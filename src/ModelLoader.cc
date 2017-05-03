#include "ModelLoader.h"

bool ModelLoader::loadObject(const char* path,
                             std::vector<GLfloat> &out_vertex_buffer,
                             std::vector<GLuint>  &out_element_buffer,
                             std::vector<GLfloat> &out_normal_buffer){
  std::ifstream obj(path);
  if(!obj.is_open()){
    std::cout <<"Failed to read object file " << path << std::endl;
    return false;
  }

  //std::string line;
  std::string token;

  std::vector <GLuint> temp_normal_elements;
  std::vector <GLfloat> temp_normals;
  while(obj >> token){

    //v for vertexes
    if(token == "v"){
      for(int i = 0; i < 3; i++){
          obj >> token;
          out_vertex_buffer.push_back(std::strtof(token.c_str(),0));
      }
    }else if (token == "vn"){
      for(int i = 0; i < 3; i++){
          obj >> token;
          temp_normals.push_back(std::strtof(token.c_str(),0));
      }
    }else if(token == "f"){
      std::size_t found;
      std::string normal_element;
      std::string element;
      for(int i = 0; i < 3; i++){
          obj >> token;
          //find the seperator
          found = token.find("//");
          //split into sub strings
          normal_element = token.substr(found + 2);
          element = token.substr(0, token.size() - (normal_element.size() + 2));
          //push element to its vector
          out_element_buffer.push_back(std::strtof(element.c_str(),0) - 1);
      }
      //push only one normal to normal buffer
      temp_normal_elements.push_back(std::strtof(normal_element.c_str(), 0) -1);
    }else{
      //std::getline(obj, line);
      obj.ignore(256,'\n');
    }
  }

  for(auto index : temp_normal_elements){
    out_normal_buffer.push_back(temp_normals[index*3]);
    out_normal_buffer.push_back(temp_normals[index*3+1]);
    out_normal_buffer.push_back(temp_normals[index*3+2]);
  }

  return true;

}
