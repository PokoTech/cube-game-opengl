AC_INIT([SimpleGame], [0.1])
AM_INIT_AUTOMAKE([foreign subdir-objects])
AC_CONFIG_SRCDIR([configure.ac])
AC_CONFIG_HEADERS([config.h])
AC_PROG_CXX

# Find the following libraries on the system
PKG_CHECK_MODULES([gl], [gl])
PKG_CHECK_MODULES([glew], [glew])
PKG_CHECK_MODULES([sdl2], [sdl2])

AC_CONFIG_FILES([Makefile
    src/Makefile
    shaders/Makefile])
AC_OUTPUT
