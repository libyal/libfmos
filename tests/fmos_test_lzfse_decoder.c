/*
 * LZFSE decoder testing program
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
#include <memory.h>
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "fmos_test_libcerror.h"
#include "fmos_test_libcnotify.h"
#include "fmos_test_macros.h"
#include "fmos_test_unused.h"

#include "../libfmos/libfmos_lzfse_decoder.h"

#if defined( __GNUC__ ) && !defined( LIBFMOS_DLL_IMPORT )

/* Tests the libfmos_lzfse_decoder_initialize function
 * Returns 1 if successful or 0 if not
 */
int fmos_test_lzfse_decoder_initialize(
     void )
{
	libcerror_error_t *error         = NULL;
	libfmos_lzfse_decoder_t *decoder = NULL;
	int result                       = 0;

#if defined( HAVE_FMOS_TEST_MEMORY )
	int number_of_malloc_fail_tests  = 1;
	int number_of_memset_fail_tests  = 1;
	int test_number                  = 0;
#endif

	/* Test regular cases
	 */
	result = libfmos_lzfse_decoder_initialize(
	          &decoder,
	          &error );

	FMOS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMOS_TEST_ASSERT_IS_NOT_NULL(
	 "decoder",
	 decoder );

	FMOS_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfmos_lzfse_decoder_free(
	          &decoder,
	          &error );

	FMOS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMOS_TEST_ASSERT_IS_NULL(
	 "decoder",
	 decoder );

	FMOS_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfmos_lzfse_decoder_initialize(
	          NULL,
	          &error );

	FMOS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMOS_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	decoder = (libfmos_lzfse_decoder_t *) 0x12345678UL;

	result = libfmos_lzfse_decoder_initialize(
	          &decoder,
	          &error );

	decoder = NULL;

	FMOS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMOS_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if defined( HAVE_FMOS_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test decoder_initialize with malloc failing
		 */
		fmos_test_malloc_attempts_before_fail = test_number;

		result = libfmos_lzfse_decoder_initialize(
		          &decoder,
		          &error );

		if( fmos_test_malloc_attempts_before_fail != -1 )
		{
			fmos_test_malloc_attempts_before_fail = -1;

			if( decoder != NULL )
			{
				libfmos_lzfse_decoder_free(
				 &decoder,
				 NULL );
			}
		}
		else
		{
			FMOS_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			FMOS_TEST_ASSERT_IS_NULL(
			 "decoder",
			 decoder );

			FMOS_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
	for( test_number = 0;
	     test_number < number_of_memset_fail_tests;
	     test_number++ )
	{
		/* Test libfmos_lzfse_decoder_initialize with memset failing
		 */
		fmos_test_memset_attempts_before_fail = test_number;

		result = libfmos_lzfse_decoder_initialize(
		          &decoder,
		          &error );

		if( fmos_test_memset_attempts_before_fail != -1 )
		{
			fmos_test_memset_attempts_before_fail = -1;

			if( decoder != NULL )
			{
				libfmos_lzfse_decoder_free(
				 &decoder,
				 NULL );
			}
		}
		else
		{
			FMOS_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			FMOS_TEST_ASSERT_IS_NULL(
			 "decoder",
			 decoder );

			FMOS_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
#endif /* defined( HAVE_MODI_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( decoder != NULL )
	{
		libfmos_lzfse_decoder_free(
		 &decoder,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfmos_lzfse_decoder_free function
 * Returns 1 if successful or 0 if not
 */
int fmos_test_lzfse_decoder_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfmos_lzfse_decoder_free(
	          NULL,
	          &error );

	FMOS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMOS_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

#endif /* defined( __GNUC__ ) && !defined( LIBFMOS_DLL_IMPORT ) */

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc FMOS_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] FMOS_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc FMOS_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] FMOS_TEST_ATTRIBUTE_UNUSED )
#endif
{
	FMOS_TEST_UNREFERENCED_PARAMETER( argc )
	FMOS_TEST_UNREFERENCED_PARAMETER( argv )

#if defined( HAVE_DEBUG_OUTPUT ) && defined( FMOS_TEST_LZFSE_VERBOSE )
	libcnotify_verbose_set(
	 1 );
	libcnotify_stream_set(
	 stderr,
	 NULL );
#endif

#if defined( __GNUC__ ) && !defined( LIBFMOS_DLL_IMPORT )

	FMOS_TEST_RUN(
	 "libfmos_lzfse_decoder_initialize",
	 fmos_test_lzfse_decoder_initialize );

	FMOS_TEST_RUN(
	 "libfmos_lzfse_decoder_free",
	 fmos_test_lzfse_decoder_free );

#endif /* defined( __GNUC__ ) && !defined( LIBFMOS_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

#if defined( __GNUC__ ) && !defined( LIBFMOS_DLL_IMPORT )

on_error:
	return( EXIT_FAILURE );

#endif /* defined( __GNUC__ ) && !defined( LIBFMOS_DLL_IMPORT ) */
}

