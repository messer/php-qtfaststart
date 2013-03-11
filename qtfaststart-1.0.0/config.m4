dnl $Id$
dnl config.m4 for extension qtfaststart

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(qtfaststart, for qtfaststart support,
dnl Make sure that the comment is aligned:
dnl [  --with-qtfaststart             Include qtfaststart support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(qtfaststart, whether to enable qtfaststart support,
dnl Make sure that the comment is aligned:
[  --enable-qtfaststart           Enable qtfaststart support])

if test "$PHP_QTFASTSTART" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-qtfaststart -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/qtfaststart.h"  # you most likely want to change this
  dnl if test -r $PHP_QTFASTSTART/$SEARCH_FOR; then # path given as parameter
  dnl   QTFASTSTART_DIR=$PHP_QTFASTSTART
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for qtfaststart files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       QTFASTSTART_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$QTFASTSTART_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the qtfaststart distribution])
  dnl fi

  dnl # --with-qtfaststart -> add include path
  dnl PHP_ADD_INCLUDE($QTFASTSTART_DIR/include)

  dnl # --with-qtfaststart -> check for lib and symbol presence
  dnl LIBNAME=qtfaststart # you may want to change this
  dnl LIBSYMBOL=qtfaststart # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $QTFASTSTART_DIR/lib, QTFASTSTART_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_QTFASTSTARTLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong qtfaststart lib version or lib not found])
  dnl ],[
  dnl   -L$QTFASTSTART_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(QTFASTSTART_SHARED_LIBADD)

  PHP_NEW_EXTENSION(qtfaststart, qtfaststart.c qt-faststart-lib.c, $ext_shared)
fi
