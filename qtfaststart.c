/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2012 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id: header 321634 2012-01-01 13:15:04Z felipe $ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_qtfaststart.h"

#include "qt-faststart-lib.h"

/* If you declare any globals in php_qtfaststart.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(qtfaststart)
*/

/* True global resources - no need for thread safety here */
static int le_qtfaststart;

// stupid header changes during minor revisions
#ifndef ZEND_FE_END
	#define ZEND_FE_END            { NULL, NULL, NULL, 0, 0 }
	#define PHP_FE_END ZEND_FE_END
#endif

/* {{{ qtfaststart_functions[]
 *
 * Every user visible function must have an entry in qtfaststart_functions[].
 */
const zend_function_entry qtfaststart_functions[] = {
	PHP_FE(qtfaststart,	NULL)		/* For testing, remove later. */
	PHP_FE_END	/* Must be the last line in qtfaststart_functions[] */
};
/* }}} */

/* {{{ qtfaststart_module_entry
 */
zend_module_entry qtfaststart_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"qtfaststart",
	qtfaststart_functions,
	PHP_MINIT(qtfaststart),
	PHP_MSHUTDOWN(qtfaststart),
	PHP_RINIT(qtfaststart),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(qtfaststart),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(qtfaststart),
#if ZEND_MODULE_API_NO >= 20010901
	"0.1", /* Replace with version number for your extension */
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_QTFASTSTART
ZEND_GET_MODULE(qtfaststart)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("qtfaststart.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_qtfaststart_globals, qtfaststart_globals)
    STD_PHP_INI_ENTRY("qtfaststart.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_qtfaststart_globals, qtfaststart_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_qtfaststart_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_qtfaststart_init_globals(zend_qtfaststart_globals *qtfaststart_globals)
{
	qtfaststart_globals->global_value = 0;
	qtfaststart_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(qtfaststart)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(qtfaststart)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(qtfaststart)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(qtfaststart)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(qtfaststart)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "qtfaststart support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */


/* Remove the following function when you have succesfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string qtfaststart(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(qtfaststart)
{
	char *infile = NULL;
	int infile_len;

	char *outfile = NULL;
	int outfile_len;

	char *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss", &infile, &infile_len, &outfile, &outfile_len) == FAILURE) {
		return;
	}


	if(do_faststart(infile,outfile)==0)
		RETURN_TRUE;
	
	RETURN_FALSE;

	//len = spprintf(&strg, 0, "%.78s %.78s",infile,outfile);
	//RETURN_STRINGL(strg, len, 0);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and 
   unfold functions in source code. See the corresponding marks just before 
   function definition, where the functions purpose is also documented. Please 
   follow this convention for the convenience of others editing your code.
*/


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
