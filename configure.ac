dnl Copyright (c) 2004-2005  Justin Spadea
dnl
dnl This program is free software; you can redistribute it and/or modify it
dnl under the terms of the GNU General Public License as published by the
dnl Free Software Foundation; either version 2 of the License, or (at your
dnl option) any later version.
dnl
dnl This program is distributed in the hope that it will be useful, but
dnl WITHOUT ANY WARRANTY; without even the implied warranty of
dnl MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
dnl General Public License for more details.
dnl
dnl You should have received a copy of the GNU General Public License along
dnl with this program; if not, write to the Free Software Foundation, Inc.,
dnl 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA


AC_PREREQ([2.50])
AC_INIT([gcolor2], [0.4])
AM_CONFIG_HEADER([config.h])
AM_INIT_AUTOMAKE([gcolor2], [0.4])

AM_MAINTAINER_MODE

AC_PROG_CC
AC_DISABLE_STATIC
AC_PROG_LIBTOOL
AC_PROG_INTLTOOL([0.27])


GETTEXT_PACKAGE=gcolor2
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE,"$GETTEXT_PACKAGE", [Gettext package.])


ALL_LINGUAS=""
AM_GLIB_GNU_GETTEXT


pkg_modules="gtk+-2.0 >= 2.4"
PKG_CHECK_MODULES(PACKAGE, [$pkg_modules])
AC_SUBST(PACKAGE_CFLAGS)
AC_SUBST(PACKAGE_LIBS)


AC_CONFIG_FILES([
Makefile
src/Makefile
po/Makefile.in
pixmaps/Makefile
gcolor2.spec
])

AC_OUTPUT

echo
echo now type \'make\' to compile
