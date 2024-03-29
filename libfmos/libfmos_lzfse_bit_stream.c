/*
 * LZFSE bit-stream functions
 *
 * Copyright (C) 2019-2024, Joachim Metz <joachim.metz@gmail.com>
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
#include <byte_stream.h>
#include <memory.h>
#include <types.h>

#include "libfmos_libcerror.h"
#include "libfmos_libcnotify.h"
#include "libfmos_lzfse_bit_stream.h"

/* Creates a bit stream
 * Make sure the value bit_stream is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfmos_lzfse_bit_stream_initialize(
     libfmos_lzfse_bit_stream_t **bit_stream,
     const uint8_t *byte_stream,
     size_t byte_stream_size,
     libcerror_error_t **error )
{
	static char *function = "libfmos_lzfse_bit_stream_initialize";

	if( bit_stream == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid bit stream.",
		 function );

		return( -1 );
	}
	if( *bit_stream != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid bit stream value already set.",
		 function );

		return( -1 );
	}
	if( byte_stream == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid byte stream.",
		 function );

		return( -1 );
	}
	if( byte_stream_size > (size_t) SSIZE_MAX )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_EXCEEDS_MAXIMUM,
		 "%s: invalid byte stream size value exceeds maximum.",
		 function );

		return( -1 );
	}
	*bit_stream = memory_allocate_structure(
	               libfmos_lzfse_bit_stream_t );

	if( *bit_stream == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create bit stream.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     *bit_stream,
	     0,
	     sizeof( libfmos_lzfse_bit_stream_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear bit stream.",
		 function );

		goto on_error;
	}
	( *bit_stream )->byte_stream        = byte_stream;
	( *bit_stream )->byte_stream_size   = byte_stream_size;
	( *bit_stream )->byte_stream_offset = byte_stream_size;

	return( 1 );

on_error:
	if( *bit_stream != NULL )
	{
		memory_free(
		 *bit_stream );

		*bit_stream = NULL;
	}
	return( -1 );
}

/* Frees a bit stream
 * Returns 1 if successful or -1 on error
 */
int libfmos_lzfse_bit_stream_free(
     libfmos_lzfse_bit_stream_t **bit_stream,
     libcerror_error_t **error )
{
	static char *function = "libfmos_lzfse_bit_stream_free";

	if( bit_stream == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid bit stream.",
		 function );

		return( -1 );
	}
	if( *bit_stream != NULL )
	{
		memory_free(
		 *bit_stream );

		*bit_stream = NULL;
	}
	return( 1 );
}

/* Retrieves a value from the bit stream
 * Returns 1 on success or -1 on error
 */
int libfmos_lzfse_bit_stream_get_value(
     libfmos_lzfse_bit_stream_t *bit_stream,
     uint8_t number_of_bits,
     uint32_t *value_32bit,
     libcerror_error_t **error )
{
	static char *function            = "libfmos_lzfse_bit_stream_get_value";
	uint32_t read_value_32bit        = 0;
	uint32_t safe_value_32bit        = 0;
	uint8_t read_number_of_bits      = 0;
	uint8_t remaining_number_of_bits = 0;

	if( bit_stream == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid bit stream.",
		 function );

		return( -1 );
	}
	if( number_of_bits > (uint8_t) 32 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_EXCEEDS_MAXIMUM,
		 "%s: invalid number of bits value exceeds maximum.",
		 function );

		return( -1 );
	}
	if( value_32bit == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid 32-bit value.",
		 function );

		return( -1 );
	}
	remaining_number_of_bits = number_of_bits;

	while( remaining_number_of_bits > 0 )
	{
		while( ( remaining_number_of_bits > bit_stream->bit_buffer_size )
		    && ( bit_stream->bit_buffer_size <= 24 ) )
		{
			if( bit_stream->byte_stream_offset == 0 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
				 "%s: invalid byte stream offset value out of bounds.",
				 function );

				return( -1 );
			}
			bit_stream->byte_stream_offset -= 1;

			bit_stream->bit_buffer     <<= 8;
			bit_stream->bit_buffer      |= bit_stream->byte_stream[ bit_stream->byte_stream_offset ];
			bit_stream->bit_buffer_size += 8;
		}
		if( remaining_number_of_bits < bit_stream->bit_buffer_size )
		{
			read_number_of_bits = remaining_number_of_bits;
		}
		else
		{
			read_number_of_bits = bit_stream->bit_buffer_size;
		}
		read_value_32bit = bit_stream->bit_buffer;

		if( remaining_number_of_bits < number_of_bits )
		{
			safe_value_32bit <<= remaining_number_of_bits;
		}
		bit_stream->bit_buffer_size -= read_number_of_bits;
		read_value_32bit           >>= bit_stream->bit_buffer_size;

		if( bit_stream->bit_buffer_size > 0 )
		{
			bit_stream->bit_buffer &= 0xffffffffUL >> ( 32 - bit_stream->bit_buffer_size );
		}
		else
		{
			bit_stream->bit_buffer = 0;
		}
		safe_value_32bit         |= read_value_32bit;
		remaining_number_of_bits -= read_number_of_bits;
	}
	*value_32bit = safe_value_32bit;

	return( 1 );
}

