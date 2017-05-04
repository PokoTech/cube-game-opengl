#include "PythonB.h"

// a test for python bindings
using namespace boost::python;

PythonBindings::PythonBindings(){}

const char* hello(){
  return "Hello World";
}

BOOST_PYTHON_MODULE(libcube){
  def("hello", hello);
}

// 
// BOOST_PYTHON_MODULE(libcube)
// {
// 	class_<Main>("InitWorld")
// 	     .def("InitWorld", &Main::InitWorld)
// 	;
// 	class_<GameAssetManager>("Draw")
// 	     .def("Draw", &GameAssetManager::Draw)
//      ;
// }
