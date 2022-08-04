/*
 * Library to support common Mac OS specific formats
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

#if !defined( _LIBFMOS_H )
#define _LIBFMOS_H

#include <libfmos/definitions.h>
#include <libfmos/error.h>
#include <libfmos/extern.h>
#include <libfmos/features.h>
#include <libfmos/types.h>

#include <stdio.h>

#if defined( __cplusplus )
extern "C" {
#endif

/* -------------------------------------------------------------------------
 * Support functions
 * ------------------------------------------------------------------------- */

/* Returns the library version
 */
LIBFMOS_EXTERN \
const char *libfmos_get_version(
             void );

/* -------------------------------------------------------------------------
 * Notify functions
 * ------------------------------------------------------------------------- */

/* Sets the verbose notification
 */
LIBFMOS_EXTERN \
void libfmos_notify_set_verbose(
      int verbose );

/* Sets the notification stream
 * Returns 1 if successful or -1 on error
 */
LIBFMOS_EXTERN \
int libfmos_notify_set_stream(
     FILE *stream,
     libfmos_error_t **error );

/* Opens the notification stream using a filename
 * The stream is opened in append mode
 * Returns 1 if successful or -1 on error
 */
LIBFMOS_EXTERN \
int libfmos_notify_stream_open(
     const char *filename,
     libfmos_error_t **error );

/* Closes the notification stream if opened using a filename
 * Returns 0 if successful or -1 on error
 */
LIBFMOS_EXTERN \
int libfmos_notify_stream_close(
     libfmos_error_t **error );

/* -------------------------------------------------------------------------
 * Error functions
 * ------------------------------------------------------------------------- */

/* Frees an error
 */
LIBFMOS_EXTERN \
void libfmos_error_free(
      libfmos_error_t **error );

/* Prints a descriptive string of the error to the stream
 * Returns the amount of printed characters if successful or -1 on error
 */
LIBFMOS_EXTERN \
int libfmos_error_fprint(
     libfmos_error_t *error,
     FILE *stream );

/* Prints a descriptive string of the error to the string
 * The end-of-string character is not included in the return value
 * Returns the amount of printed characters if successful or -1 on error
 */
LIBFMOS_EXTERN \
int libfmos_error_sprint(
     libfmos_error_t *error,
     char *string,
     size_t size );

/* Prints a backtrace of the error to the stream
 * Returns the amount of printed characters if successful or -1 on error
 */
LIBFMOS_EXTERN \
int libfmos_error_backtrace_fprint(
     libfmos_error_t *error,
     FILE *stream );

/* Prints a backtrace of the error to the string
 * The end-of-string character is not included in the return value
 * Returns the amount of printed characters if successful or -1 on error
 */
LIBFMOS_EXTERN \
int libfmos_error_backtrace_sprint(
     libfmos_error_t *error,
     char *string,
     size_t size );

/* -------------------------------------------------------------------------
 * ADC functions
 * ------------------------------------------------------------------------- */

/* Decompresses data using ADC compression
 * Returns 1 on success or -1 on error
 */
LIBFMOS_EXTERN \
int libfmos_adc_decompress(
     const uint8_t *compressed_data,
     size_t compressed_data_size,
     uint8_t *uncompressed_data,
     size_t *uncompressed_data_size,
     libfmos_error_t **error );

/* -------------------------------------------------------------------------
 * LZFSE functions
 * ------------------------------------------------------------------------- */

/* Decompresses data using LZFSE compression
 * Returns 1 on success or -1 on error
 */
LIBFMOS_EXTERN \
int libfmos_lzfse_decompress(
     const uint8_t *compressed_data,
     size_t compressed_data_size,
     uint8_t *uncompressed_data,
     size_t *uncompressed_data_size,
     libfmos_error_t **error );

/* -------------------------------------------------------------------------
 * LZVN functions
 * ------------------------------------------------------------------------- */

/* Decompresses data using LZVN compression
 * Returns 1 on success or -1 on error
 */
LIBFMOS_EXTERN \
int libfmos_lzvn_decompress(
     const uint8_t *compressed_data,
     size_t compressed_data_size,
     uint8_t *uncompressed_data,
     size_t *uncompressed_data_size,
     libfmos_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBFMOS_H ) */

