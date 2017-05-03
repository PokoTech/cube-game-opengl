#include "ModelLoader.h"

bool ModelLoader::loadObject(const char* path,
                             std::vector<GLfloat> &out_vertex_buffer,
                             std::vector<GLuint> &out_element_buffer){
  std::ifstream obj(path);
  if(!obj.is_open()){
    std::cout <<"Failed to read object file " << path << std::endl;
    return false;
  }

  std::string line;
  std::string token;
  while(obj >> token){

    //v for vertexes
    if(token == "v"){
      for(int i = 0; i < 3; i++){
          obj >> token;
          out_vertex_buffer.push_back(std::strtof(token.c_str(),0));
      }
    }else if(token == "f"){
      for(int i = 0; i < 3; i++){
          obj >> token;
          //have to minus one from eat element because blender
          //doesn't start its arrays from 0
          out_element_buffer.push_back(std::strtof(token.c_str(),0) - 1);
      }
    }else{
      //std::getline(obj, line);
      obj.ignore(256,'\n');
    }
  }
  return true;

}
