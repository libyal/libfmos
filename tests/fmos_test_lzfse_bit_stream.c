/*
 * LZFSE bit-stream testing program
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

#include "../libfmos/libfmos_lzfse.h"

uint8_t fmos_test_lzfse_bit_stream_compressed_data[ 226 ] = {
	0x62, 0x76, 0x78, 0x32, 0x00, 0x40, 0x00, 0x00, 0x44, 0x00, 0x30, 0x02, 0x00, 0x0a, 0x00, 0x40,
	0xe4, 0x8b, 0xd9, 0xa2, 0xc9, 0x18, 0x00, 0x00, 0xa3, 0x00, 0x00, 0x00, 0x3a, 0x24, 0xc0, 0x0e,
	0x0f, 0x01, 0x4c, 0x80, 0x09, 0x00, 0x30, 0x27, 0x13, 0x80, 0x09, 0x00, 0x13, 0x80, 0xb7, 0xe0,
	0x9d, 0x79, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xe0, 0xe5, 0x02, 0xb8, 0x03, 0x00, 0x80, 0xbb, 0x37, 0x00, 0x00, 0xb8, 0x03, 0xe0,
	0xee, 0x0e, 0x00, 0xb8, 0x03, 0x00, 0xee, 0xe0, 0xee, 0x0e, 0x00, 0x00, 0x00, 0xee, 0x00, 0xb8,
	0xbb, 0x03, 0x00, 0x00, 0xb8, 0x03, 0x00, 0xe0, 0x0e, 0xee, 0xbe, 0x02, 0xee, 0x78, 0x03, 0xee,
	0xee, 0xb8, 0x03, 0xe0, 0x0e, 0x00, 0xe0, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x80, 0x37, 0x80, 0x3b, 0x00, 0x00, 0xee, 0x00, 0xb8, 0x03, 0x00, 0xee, 0x00, 0x00,
	0x00, 0x00, 0xb8, 0xbb, 0xbb, 0x03, 0xb8, 0x03, 0x00, 0xe0, 0x0e, 0xe0, 0x0e, 0xee, 0xee, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xef, 0x1c, 0x68, 0xbd, 0xc5, 0xd0, 0xc4, 0x3c, 0x8c, 0xb7, 0xbe, 0x86,
	0x9b, 0xeb, 0x76, 0x65, 0xd2, 0x38, 0x3e, 0x26, 0x5c, 0x31, 0x96, 0xe7, 0x57, 0xc5, 0x31, 0xd3,
	0x83, 0xb0, 0x45, 0x9f, 0xa7, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xca,
	0xfd, 0x9f, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xbf, 0xff, 0x83, 0x81, 0x89, 0x26, 0x01, 0x62, 0x76,
	0x78, 0x24 };

#if defined( __GNUC__ ) && !defined( LIBFMOS_DLL_IMPORT )

/* Tests the libfmos_lzfse_bit_stream_initialize function
 * Returns 1 if successful or 0 if not
 */
int fmos_test_lzfse_bit_stream_initialize(
     void )
{
	libcerror_error_t *error               = NULL;
	libfmos_lzfse_bit_stream_t *bit_stream = NULL;
	int result                             = 0;

#if defined( HAVE_FMOS_TEST_MEMORY )
	int number_of_malloc_fail_tests        = 1;
	int number_of_memset_fail_tests        = 1;
	int test_number                        = 0;
#endif

	/* Test regular cases
	 */
	result = libfmos_lzfse_bit_stream_initialize(
	          &bit_stream,
	          fmos_test_lzfse_bit_stream_compressed_data,
	          226,
	          &error );

	FMOS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMOS_TEST_ASSERT_IS_NOT_NULL(
	 "bit_stream",
	 bit_stream );

	FMOS_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfmos_lzfse_bit_stream_free(
	          &bit_stream,
	          &error );

	FMOS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMOS_TEST_ASSERT_IS_NULL(
	 "bit_stream",
	 bit_stream );

	FMOS_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfmos_lzfse_bit_stream_initialize(
	          NULL,
	          fmos_test_lzfse_bit_stream_compressed_data,
	          226,
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

	bit_stream = (libfmos_lzfse_bit_stream_t *) 0x12345678UL;

	result = libfmos_lzfse_bit_stream_initialize(
	          &bit_stream,
	          fmos_test_lzfse_bit_stream_compressed_data,
	          226,
	          &error );

	bit_stream = NULL;

	FMOS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMOS_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfmos_lzfse_bit_stream_initialize(
	          &bit_stream,
	          NULL,
	          226,
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

	result = libfmos_lzfse_bit_stream_initialize(
	          &bit_stream,
	          fmos_test_lzfse_bit_stream_compressed_data,
	          (size_t) SSIZE_MAX + 1,
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

#if defined( HAVE_FMOS_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libfmos_lzfse_bit_stream_initialize with malloc failing
		 */
		fmos_test_malloc_attempts_before_fail = test_number;

		result = libfmos_lzfse_bit_stream_initialize(
		          &bit_stream,
		          fmos_test_lzfse_bit_stream_compressed_data,
		          226,
		          &error );

		if( fmos_test_malloc_attempts_before_fail != -1 )
		{
			fmos_test_malloc_attempts_before_fail = -1;

			if( bit_stream != NULL )
			{
				libfmos_lzfse_bit_stream_free(
				 &bit_stream,
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
			 "bit_stream",
			 bit_stream );

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
		/* Test libfmos_lzfse_bit_stream_initialize with memset failing
		 */
		fmos_test_memset_attempts_before_fail = test_number;

		result = libfmos_lzfse_bit_stream_initialize(
		          &bit_stream,
		          fmos_test_lzfse_bit_stream_compressed_data,
		          226,
		          &error );

		if( fmos_test_memset_attempts_before_fail != -1 )
		{
			fmos_test_memset_attempts_before_fail = -1;

			if( bit_stream != NULL )
			{
				libfmos_lzfse_bit_stream_free(
				 &bit_stream,
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
			 "bit_stream",
			 bit_stream );

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
	if( bit_stream != NULL )
	{
		libfmos_lzfse_bit_stream_free(
		 &bit_stream,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfmos_lzfse_bit_stream_free function
 * Returns 1 if successful or 0 if not
 */
int fmos_test_lzfse_bit_stream_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfmos_lzfse_bit_stream_free(
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

/* Tests the libfmos_lzfse_bit_stream_get_value function
 * Returns 1 if successful or 0 if not
 */
int fmos_test_lzfse_bit_stream_get_value(
     void )
{
	libfmos_lzfse_bit_stream_t *bit_stream = NULL;
	libcerror_error_t *error               = NULL;
	uint32_t value_32bit                   = 0;
	int result                             = 0;

	/* Initialize test
	 */
	result = libfmos_lzfse_bit_stream_initialize(
	          &bit_stream,
	          &( fmos_test_lzfse_bit_stream_compressed_data[ 163 ] ),
	          35,
	          &error );

	FMOS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMOS_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfmos_lzfse_bit_stream_get_value(
	          bit_stream,
	          0,
	          &value_32bit,
	          &error );

	FMOS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMOS_TEST_ASSERT_EQUAL_UINT32(
	 "value_32bit",
	 value_32bit,
	 (uint32_t) 0x00000000UL );

	FMOS_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	FMOS_TEST_ASSERT_EQUAL_SIZE(
	 "bit_stream->byte_stream_offset",
	 bit_stream->byte_stream_offset,
	 (size_t) 35 );

	FMOS_TEST_ASSERT_EQUAL_UINT32(
	 "bit_stream->bit_buffer",
	 bit_stream->bit_buffer,
	 (uint32_t) 0x00000000UL );

	FMOS_TEST_ASSERT_EQUAL_UINT8(
	 "bit_stream->bit_buffer_size",
	 bit_stream->bit_buffer_size,
	 (uint8_t) 0 );

	result = libfmos_lzfse_bit_stream_get_value(
	          bit_stream,
	          4,
	          &value_32bit,
	          &error );

	FMOS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMOS_TEST_ASSERT_EQUAL_UINT32(
	 "value_32bit",
	 value_32bit,
	 (uint32_t) 0x00000000UL );

	FMOS_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	FMOS_TEST_ASSERT_EQUAL_SIZE(
	 "bit_stream->byte_stream_offset",
	 bit_stream->byte_stream_offset,
	 (size_t) 34 );

	FMOS_TEST_ASSERT_EQUAL_UINT32(
	 "bit_stream->bit_buffer",
	 bit_stream->bit_buffer,
	 (uint32_t) 0x00000003UL );

	FMOS_TEST_ASSERT_EQUAL_UINT8(
	 "bit_stream->bit_buffer_size",
	 bit_stream->bit_buffer_size,
	 (uint8_t) 4 );

	result = libfmos_lzfse_bit_stream_get_value(
	          bit_stream,
	          12,
	          &value_32bit,
	          &error );

	FMOS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMOS_TEST_ASSERT_EQUAL_UINT32(
	 "value_32bit",
	 value_32bit,
	 (uint32_t) 0x000003a7UL );

	FMOS_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	FMOS_TEST_ASSERT_EQUAL_SIZE(
	 "bit_stream->byte_stream_offset",
	 bit_stream->byte_stream_offset,
	 (size_t) 33 );

	FMOS_TEST_ASSERT_EQUAL_UINT32(
	 "bit_stream->bit_buffer",
	 bit_stream->bit_buffer,
	 (uint32_t) 0x00000000UL );

	FMOS_TEST_ASSERT_EQUAL_UINT8(
	 "bit_stream->bit_buffer_size",
	 bit_stream->bit_buffer_size,
	 (uint8_t) 0 );

	result = libfmos_lzfse_bit_stream_get_value(
	          bit_stream,
	          24,
	          &value_32bit,
	          &error );

	FMOS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMOS_TEST_ASSERT_EQUAL_UINT32(
	 "value_32bit",
	 value_32bit,
	 (uint32_t) 0x009f45b0UL );

	FMOS_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	FMOS_TEST_ASSERT_EQUAL_SIZE(
	 "bit_stream->byte_stream_offset",
	 bit_stream->byte_stream_offset,
	 (size_t) 30 );

	FMOS_TEST_ASSERT_EQUAL_UINT32(
	 "bit_stream->bit_buffer",
	 bit_stream->bit_buffer,
	 (uint32_t) 0x00000000UL );

	FMOS_TEST_ASSERT_EQUAL_UINT8(
	 "bit_stream->bit_buffer_size",
	 bit_stream->bit_buffer_size,
	 (uint8_t) 0 );

	/* Test error cases
	 */
	result = libfmos_lzfse_bit_stream_get_value(
	          NULL,
	          24,
	          &value_32bit,
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

	result = libfmos_lzfse_bit_stream_get_value(
	          bit_stream,
	          64,
	          &value_32bit,
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

	result = libfmos_lzfse_bit_stream_get_value(
	          bit_stream,
	          24,
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

	bit_stream->byte_stream_offset = 0;
        bit_stream->bit_buffer_size    = 0;

	result = libfmos_lzfse_bit_stream_get_value(
	          bit_stream,
	          24,
	          &value_32bit,
	          &error );

	bit_stream->byte_stream_offset = 0;

	FMOS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMOS_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfmos_lzfse_bit_stream_free(
	          &bit_stream,
	          &error );

	FMOS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMOS_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( bit_stream != NULL )
	{
		libfmos_lzfse_bit_stream_free(
		 &bit_stream,
		 NULL );
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

#if defined( __GNUC__ ) && !defined( LIBFMOS_DLL_IMPORT )

	FMOS_TEST_RUN(
	 "libfmos_lzfse_bit_stream_initialize",
	 fmos_test_lzfse_bit_stream_initialize );

	FMOS_TEST_RUN(
	 "libfmos_lzfse_bit_stream_free",
	 fmos_test_lzfse_bit_stream_free );

	FMOS_TEST_RUN(
	 "libfmos_lzfse_bit_stream_get_value",
	 fmos_test_lzfse_bit_stream_get_value );

#endif /* defined( __GNUC__ ) && !defined( LIBFMOS_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

#if defined( __GNUC__ ) && !defined( LIBFMOS_DLL_IMPORT )

on_error:
	return( EXIT_FAILURE );

#endif /* defined( __GNUC__ ) && !defined( LIBFMOS_DLL_IMPORT ) */
}

