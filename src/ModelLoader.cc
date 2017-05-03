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

  std::string line;
  std::string token;
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
          out_normal_buffer.push_back(std::strtof(token.c_str(),0));
      }
    }else if(token == "f"){
      for(int i = 0; i < 3; i++){
          obj >> token;
          //find the seperator
          std::size_t found = token.find("//");
          //split into sub strings
          std::string normal_element = token.substr(found + 2);
          std::string element = token.substr(0, token.size() - (normal_element.size() + 2));
          //push element to its vector
          out_element_buffer.push_back(std::strtof(token.c_str(),0) - 1);
          //std::cout<< normal_element << std::endl;
      }
    }else{
      //std::getline(obj, line);
      obj.ignore(256,'\n');
    }
  }
  return true;

}
