EXTRA_DIST = GameWorld.h GameAssetManager.h GameAsset.h CubeAsset.h ModelLoader.h Camera.h PythonB.h common.h

bin_PROGRAMS = shaderexample
shaderexample_SOURCES = main.cc
shaderexample_LDADD = libcube.la

lib_LTLIBRARIES = libcubepy.la
libcubepy_la_SOURCES =  PythonB.cc
libcubepy_la_LIBADD =  libcube.la -lboost_python -lpython2.7
libcubepy_la_CPPFLAGS = -I/usr/include/python2.7/

lib_LTLIBRARIES += libcube.la
libcube_la_SOURCES = GameWorld.cc GameAssetManager.cc CubeAsset.cc Camera.cc ModelLoader.cc

AM_CPPFLAGS = -DGL_GLEXT_PROTOTYPES -DGL3_PROTOTYPES
AM_CPPFLAGS += -std=c++11
AM_CPPFLAGS += $(gl_CFLAGS) $(glew_CFLAGS) $(sdl2_CFLAGS) $(BOOST_CPPFLAGS)
LIBS += $(gl_LIBS) $(glew_LIBS) $(sdl2_LIBS) $(BOOST_THREAD_LIBS) $(BOOST_PROGRAM_OPTIONS_LIBS)
