#include "GameAssetManager.h"

GameAssetManager& GameAssetManager::getInstance() {
  static GameAssetManager the_manager;
  return the_manager;
}

void GameAssetManager::addAsset(std::shared_ptr<GameAsset> the_asset) {
}

GameAssetManager::GameAssetManager() {
}

GameAssetManager::GameAssetManager(GameAssetManager const& the_manager) {
}

GameAssetManager::GameAssetManager(GameAssetManager const&& the_manager) {
}

void GameAssetManager::operator=(GameAssetManager const& the_manager) {
}

GLuint GameAssetManager::CreateGLProgram(std::string & vertex_shader
                       , std::string & fragment_shader) {
  auto v_shader_token = CreateGLESShader(GL_VERTEX_SHADER, vertex_shader);
  auto f_shader_token = CreateGLESShader(GL_FRAGMENT_SHADER, fragment_shader);

  GLint program_ok;

  GLuint program = glCreateProgram();

  glAttachShader(program, v_shader_token);
  glAttachShader(program, f_shader_token);
  glLinkProgram(program);

  glGetProgramiv(program, GL_LINK_STATUS, &program_ok);
  if (!program_ok) {
    std::cerr << "Failed to link shader program:" << std::endl;
    glDeleteProgram(program);
    return -1;
  }
  return program;
}

GLuint GameAssetManager::CreateGLESShader(GLenum type, std::string & shader) {
  GLuint shader_token;
  GLint shader_ok;
  auto source = ReadShader(shader);

  if (!source.first)
    return 0;

  shader_token = glCreateShader(type);
  glShaderSource(shader_token, 1, (const GLchar**)&source.first, &source.second);
  delete(source.first);
  glCompileShader(shader_token);

  glGetShaderiv(shader_token, GL_COMPILE_STATUS, &shader_ok);
  if (!shader_ok) {
    std::cerr << "Failed to compile " << shader << " with error code " << shader_ok << std::endl;
    glDeleteShader(shader_token);
    return 0;
  }
  return shader_token;
}


std::pair<GLchar *, GLint> GameAssetManager::ReadShader(std::string & shader) {
  std::ifstream input_file;
  GLint length;
  input_file.open(shader, std::ios::in);

  input_file.seekg(0, std::ios::end);  // go to the end of the file
  length = input_file.tellg();    // get length of the file
  input_file.seekg(0, std::ios::beg);  // go to beginning of the file

  GLchar * buffer = new GLchar[length+1];
  input_file.read(buffer, length);
  buffer[length+1]='\0';  // Ensure null terminated

  input_file.close();
  return std::make_pair(buffer, length);
}
