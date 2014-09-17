AC_INIT([ShaderExamples], [0.1])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([foreign subdir-objects])
AC_CONFIG_SRCDIR([configure.ac])
AC_CONFIG_HEADERS([config.h])

AC_PROG_LIBTOOL
AC_PROG_CXX

BOOST_REQUIRE
BOOST_PROGRAM_OPTIONS

# Find the following libraries on the system
PKG_CHECK_MODULES([gl], [gl])
PKG_CHECK_MODULES([glew], [glew])
PKG_CHECK_MODULES([sdl2], [sdl2])

AC_CONFIG_FILES([Makefile
    src/Makefile
    shaders/Makefile])
AC_OUTPUT
