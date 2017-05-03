#include "CubeAsset.h"

CubeAsset::CubeAsset(){
  // model coordinates, origin at centre.
	std::vector<GLfloat> vertex_buffer;
	vertex_buffer.insert(vertex_buffer.end(),
	{
	    -0.5f, -0.5f, 0.5f
	  , -0.5f,  0.5f, 0.5f
	  ,  0.5f, -0.5f, 0.5f
	  ,  0.5f,  0.5f, 0.5f,

		  -0.5f, -0.5f, -0.5f
		, -0.5f, 0.5f,  -0.5f
		,  0.5f, -0.5f, -0.5f
		,  0.5f, 0.5f,  -0.5f
	});

  std::vector<GLuint> element_buffer;
	element_buffer.insert(element_buffer.end(),
	{
		//front face
		  2, 0, 1
	  , 1, 3, 2
		// //left face
		, 0, 4, 5
		, 5, 1, 0
		// // //back face
		, 4, 6, 7
		, 7, 5, 4
		// // //right face
		, 6, 2, 3
	  , 3, 7, 6
		// // // bottom face
		, 6, 4, 0
		, 0, 2, 6
		// // //top face
		, 3, 1, 5
		, 5, 7, 3
	});

	//normal buffer
	std::vector<GLfloat> normal_buffer;
	normal_buffer.insert(normal_buffer.end(),
	{
		// front face
		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f,
	  // left face
	  1.0f,  0.0f,  0.0f,
		1.0f,  0.0f,  0.0f,
		// // back face
		0.0f,  0.0f, -1.0f,
		0.0f,  0.0f, -1.0f,
		// // // right face
		1.0f,  0.0f,  0.0f,
		1.0f,  0.0f,  0.0f,
	  // // bottom face
		0.0f,  -1.0f,  0.0f,
		0.0f,  -1.0f,  0.0f,
		// // top face
		0.0f,  1.0f,  0.0f,
	  0.0f,  1.0f,  0.0f
	});


	// get sizes of arrays
	vertex_buffer_length = vertex_buffer.size();
	element_buffer_length = element_buffer.size();
	normal_buffer_length = normal_buffer.size();

  // Transfer buffers to the GPU
  //

  // create buffer
  glGenBuffers(1, &vertex_buffer_token);

  // immediately bind the buffer and transfer the data
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_token);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vertex_buffer_length, vertex_buffer.data(), GL_STATIC_DRAW);

  glGenBuffers(1, &element_buffer_token);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_token);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * element_buffer_length, element_buffer.data(), GL_STATIC_DRAW);

	glGenBuffers(1, &normal_buffer_token);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, normal_buffer_token);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLfloat) * normal_buffer_length, normal_buffer.data(), GL_STATIC_DRAW);
}

CubeAsset::CubeAsset(const char* path){
  // model coordinates, origin at centre.
	std::vector<GLfloat> vertex_buffer;
  std::vector<GLuint> element_buffer;
	std::vector<GLfloat> normal_buffer;

	//Load object in from model
	ModelLoader::loadObject(path, vertex_buffer, element_buffer, normal_buffer);
	// get sizes of arrays
	vertex_buffer_length  = vertex_buffer.size();
	element_buffer_length = element_buffer.size();
	normal_buffer_length  = normal_buffer.size();
  // Transfer buffers to the GPU
  //


	// vertex buffer
  // create buffer
  glGenBuffers(1, &vertex_buffer_token);
  // immediately bind the buffer and transfer the data
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_token);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vertex_buffer_length, vertex_buffer.data(), GL_STATIC_DRAW);

	// element buffer
  glGenBuffers(1, &element_buffer_token);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_token);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * element_buffer_length, element_buffer.data(), GL_STATIC_DRAW);

	//normal buffer
	glGenBuffers(1, &normal_buffer_token);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, normal_buffer_token);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLfloat) * normal_buffer_length, normal_buffer.data(), GL_STATIC_DRAW);
}

CubeAsset::~CubeAsset() {
}

#ifdef DEBUG
#define checkGLError() checkError(__FILE__, __LINE__)
#else
// define symbol to be nothing
#define checkGLError()
#endif

void checkError(std::string file, int line) {
  GLenum gl_error = glGetError();
  if(GL_NO_ERROR != gl_error) {
    std::cerr << "GL error in " << file << " at line " << line << " error: " << gl_error << std::endl;
    exit(-1);
  }
}

void CubeAsset::Draw(GLuint program_token) {
  if(!glIsProgram(program_token)) {
    std::cerr << "Drawing Cube with invalid program" << std::endl;
    return;
  }
  GLint validation_ok;
  glValidateProgram(program_token);
  glGetProgramiv(program_token, GL_VALIDATE_STATUS, &validation_ok);
  if(!validation_ok) {
    GLint maxLength = 0;
    glGetProgramiv(program_token, GL_INFO_LOG_LENGTH, &maxLength);

    //The maxLength includes the NULL character
    std::vector<char> errorLog(maxLength);
    glGetProgramInfoLog(program_token, maxLength, &maxLength, &errorLog[0]);

    std::cerr << "Invalid program " << program_token << " with error code " << validation_ok << std::endl;
    for(auto c: errorLog) {
      std::cerr << c;
    }
    exit(-1);
  }


  //sending color to the shader color_vector
  GLuint color_attrib = glGetUniformLocation(program_token, "color_vector");
  checkGLError();
  glUniform3fv(color_attrib, 1, glm::value_ptr(color));

  // sending matrix to the shader model_matrix
  GLuint model_attrib = glGetUniformLocation(program_token, "model_matrix");
  checkGLError();
  glUniformMatrix4fv(model_attrib, 1, GL_FALSE, glm::value_ptr(matrix));

  GLuint position_attrib = glGetAttribLocation(program_token, "position");
  checkGLError();

	GLuint normal_attrib = glGetAttribLocation(program_token, "normal");
  checkGLError();


  glUseProgram(program_token);
  checkGLError();

  // use the previously transferred buffer as the vertex array.  This way
  // we transfer the buffer once -- at construction -- not on every frame.
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_token);
  glVertexAttribPointer(
                        position_attrib,               /* attribute */
                        3,                             /* size */
                        GL_FLOAT,                      /* type */
                        GL_FALSE,                      /* normalized? */
                        0,                             /* stride */
                        (void*)0                       /* array buffer offset */
                        );
  glEnableVertexAttribArray(position_attrib);

  checkGLError();

	//transfer normals
	glBindBuffer(GL_ARRAY_BUFFER, normal_buffer_token);
	glVertexAttribPointer(
												normal_attrib,                 /* attribute */
												3,                             /* size */
												GL_FLOAT,                      /* type */
												GL_FALSE,                      /* normalized? */
												0,                             /* stride */
												(void*)0                       /* array buffer offset */
												);
	glEnableVertexAttribArray(normal_attrib);

	checkGLError();


	//
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_token);
  glDrawElements(
                 GL_TRIANGLES,
                 element_buffer_length,
                 GL_UNSIGNED_INT,
                 (GLvoid*) 0
                 );

  checkGLError();
  glDisableVertexAttribArray(position_attrib);
	glDisableVertexAttribArray(normal_attrib);

}
