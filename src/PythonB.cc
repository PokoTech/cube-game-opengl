#include "PythonB.h"

// a test file for python bindings
using namespace boost::python;

PythonBindings::PythonBindings(){}

const char* hello(){
  return "Hello World";
}

BOOST_PYTHON_MODULE(libcube){
  def("hello", hello);
}
