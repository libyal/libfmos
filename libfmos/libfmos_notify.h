/*
 * Notification functions
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

#if !defined( _LIBFMOS_NOTIFY_H )
#define _LIBFMOS_NOTIFY_H

#include <common.h>
#include <file_stream.h>
#include <types.h>

#include "libfmos_extern.h"
#include "libfmos_libcerror.h"

#if defined( __cplusplus )
extern "C" {
#endif

#if !defined( HAVE_LOCAL_LIBFMOS )

LIBFMOS_EXTERN \
void libfmos_notify_set_verbose(
      int verbose );

LIBFMOS_EXTERN \
int libfmos_notify_set_stream(
     FILE *stream,
     libcerror_error_t **error );

LIBFMOS_EXTERN \
int libfmos_notify_stream_open(
     const char *filename,
     libcerror_error_t **error );

LIBFMOS_EXTERN \
int libfmos_notify_stream_close(
     libcerror_error_t **error );

#endif /* !defined( HAVE_LOCAL_LIBFMOS ) */

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBFMOS_NOTIFY_H ) */

