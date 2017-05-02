#include "Python.h"
#include <boost/python.hpp>

using namespace boost::python;

PythonBindings::PythonBindings(){
	
}

BOOST_PYTHON_MODULE(lib)
{
	class_<Main>("InitWorld")
	     .def("InitWorld", &Main::InitWorld)
	;
	class_<GameAssetManager<("Draw")
	     .def("Draw", &GameAssetManager::Draw)
     ;
}