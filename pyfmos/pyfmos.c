/*
 * Python bindings module for libfmos (pyfmos)
 *
 * Copyright (C) 2019-2022, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <narrow_string.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( HAVE_WINAPI )
#include <stdlib.h>
#endif

#include "pyfmos.h"
#include "pyfmos_adc.h"
#include "pyfmos_error.h"
#include "pyfmos_libcerror.h"
#include "pyfmos_libfmos.h"
#include "pyfmos_lzfse.h"
#include "pyfmos_lzvn.h"
#include "pyfmos_python.h"
#include "pyfmos_unused.h"

/* The pyfmos module methods
 */
PyMethodDef pyfmos_module_methods[] = {
	{ "get_version",
	  (PyCFunction) pyfmos_get_version,
	  METH_NOARGS,
	  "get_version() -> String\n"
	  "\n"
	  "Retrieves the version." },

	{ "adc_decompress",
	  (PyCFunction) pyfmos_adc_decompress,
	  METH_VARARGS | METH_KEYWORDS,
	  "adc_decompress(compressed_data, uncompressed_data_size) -> Bytes\n"
	  "\n"
	  "Decompresses data using ADC compression." },

	{ "lzfse_decompress",
	  (PyCFunction) pyfmos_lzfse_decompress,
	  METH_VARARGS | METH_KEYWORDS,
	  "lzfse_decompress(compressed_data, uncompressed_data_size) -> Bytes\n"
	  "\n"
	  "Decompresses data using LZFSE compression." },

	{ "lzvn_decompress",
	  (PyCFunction) pyfmos_lzvn_decompress,
	  METH_VARARGS | METH_KEYWORDS,
	  "lzvn_decompress(compressed_data, uncompressed_data_size) -> Bytes\n"
	  "\n"
	  "Decompresses data using LZVN compression." },

	/* Sentinel */
	{ NULL, NULL, 0, NULL }
};

/* Retrieves the pyfmos/libfmos version
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfmos_get_version(
           PyObject *self PYFMOS_ATTRIBUTE_UNUSED,
           PyObject *arguments PYFMOS_ATTRIBUTE_UNUSED )
{
	const char *errors           = NULL;
	const char *version_string   = NULL;
	size_t version_string_length = 0;

	PYFMOS_UNREFERENCED_PARAMETER( self )
	PYFMOS_UNREFERENCED_PARAMETER( arguments )

	Py_BEGIN_ALLOW_THREADS

	version_string = libfmos_get_version();

	Py_END_ALLOW_THREADS

	version_string_length = narrow_string_length(
	                         version_string );

	/* Pass the string length to PyUnicode_DecodeUTF8
	 * otherwise it makes the end of string character is part
	 * of the string
	 */
	return( PyUnicode_DecodeUTF8(
	         version_string,
	         (Py_ssize_t) version_string_length,
	         errors ) );
}

#if PY_MAJOR_VERSION >= 3

/* The pyfmos module definition
 */
PyModuleDef pyfmos_module_definition = {
	PyModuleDef_HEAD_INIT,

	/* m_name */
	"pyfmos",
	/* m_doc */
	"Python libfmos module (pyfmos).",
	/* m_size */
	-1,
	/* m_methods */
	pyfmos_module_methods,
	/* m_reload */
	NULL,
	/* m_traverse */
	NULL,
	/* m_clear */
	NULL,
	/* m_free */
	NULL,
};

#endif /* PY_MAJOR_VERSION >= 3 */

/* Initializes the pyfmos module
 */
#if PY_MAJOR_VERSION >= 3
PyMODINIT_FUNC PyInit_pyfmos(
                void )
#else
PyMODINIT_FUNC initpyfmos(
                void )
#endif
{
	PyObject *module = NULL;

#if defined( HAVE_DEBUG_OUTPUT )
	libfmos_notify_set_stream(
	 stderr,
	 NULL );
	libfmos_notify_set_verbose(
	 1 );
#endif

	/* Create the module
	 * This function must be called before grabbing the GIL
	 * otherwise the module will segfault on a version mismatch
	 */
#if PY_MAJOR_VERSION >= 3
	module = PyModule_Create(
	          &pyfmos_module_definition );
#else
	module = Py_InitModule3(
	          "pyfmos",
	          pyfmos_module_methods,
	          "Python libfmos module (pyfmos)." );
#endif
	if( module == NULL )
	{
#if PY_MAJOR_VERSION >= 3
		return( NULL );
#else
		return;
#endif
	}
#if PY_VERSION_HEX < 0x03070000
	PyEval_InitThreads();
#endif
	/* This binding does not define any types at the moment
	 */
#if PY_MAJOR_VERSION >= 3
	return( module );
#else
	return;
#endif
}

