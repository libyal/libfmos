AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCTHREADS_CPPFLAGS@ \
	@LIBCNOTIFY_CPPFLAGS@ \
	@PTHREAD_CPPFLAGS@ \
	@LIBFMOS_DLL_IMPORT@

TESTS = \
	test_library.sh \
	$(TESTS_PYFMOS)

if HAVE_PYTHON_TESTS
TESTS_PYFMOS = \
	test_python_module.sh
endif

check_SCRIPTS = \
	pyfmos_test_adc.py \
	pyfmos_test_lzfse.py \
	pyfmos_test_lzvn.py \
	pyfmos_test_support.py \
	test_library.sh \
	test_manpage.sh \
	test_python_module.sh \
	test_runner.sh

EXTRA_DIST = \
	$(check_SCRIPTS)

check_PROGRAMS = \
	fmos_test_adc \
	fmos_test_error \
	fmos_test_lzfse \
	fmos_test_lzfse_bit_stream \
	fmos_test_lzfse_decoder \
	fmos_test_lzvn \
	fmos_test_notify \
	fmos_test_support

fmos_test_adc_SOURCES = \
	fmos_test_adc.c \
	fmos_test_libcerror.h \
	fmos_test_libcnotify.h \
	fmos_test_libfmos.h \
	fmos_test_macros.h \
	fmos_test_unused.h

fmos_test_adc_LDADD = \
	@LIBCNOTIFY_LIBADD@ \
	../libfmos/libfmos.la \
	@LIBCERROR_LIBADD@

fmos_test_error_SOURCES = \
	fmos_test_error.c \
	fmos_test_libfmos.h \
	fmos_test_macros.h \
	fmos_test_unused.h

fmos_test_error_LDADD = \
	../libfmos/libfmos.la

fmos_test_lzfse_SOURCES = \
	fmos_test_lzfse.c \
	fmos_test_libcerror.h \
	fmos_test_libcnotify.h \
	fmos_test_libfmos.h \
	fmos_test_macros.h \
	fmos_test_unused.h

fmos_test_lzfse_LDADD = \
	@LIBCNOTIFY_LIBADD@ \
	../libfmos/libfmos.la \
	@LIBCERROR_LIBADD@

fmos_test_lzfse_bit_stream_SOURCES = \
	fmos_test_lzfse_bit_stream.c \
	fmos_test_libcerror.h \
	fmos_test_libcnotify.h \
	fmos_test_libfmos.h \
	fmos_test_macros.h \
	fmos_test_unused.h

fmos_test_lzfse_bit_stream_LDADD = \
	@LIBCNOTIFY_LIBADD@ \
	../libfmos/libfmos.la \
	@LIBCERROR_LIBADD@

fmos_test_lzfse_decoder_SOURCES = \
	fmos_test_lzfse_decoder.c \
	fmos_test_libcerror.h \
	fmos_test_libcnotify.h \
	fmos_test_libfmos.h \
	fmos_test_macros.h \
	fmos_test_unused.h

fmos_test_lzfse_decoder_LDADD = \
	@LIBCNOTIFY_LIBADD@ \
	../libfmos/libfmos.la \
	@LIBCERROR_LIBADD@

fmos_test_lzvn_SOURCES = \
	fmos_test_lzvn.c \
	fmos_test_libcerror.h \
	fmos_test_libcnotify.h \
	fmos_test_libfmos.h \
	fmos_test_macros.h \
	fmos_test_unused.h

fmos_test_lzvn_LDADD = \
	@LIBCNOTIFY_LIBADD@ \
	../libfmos/libfmos.la \
	@LIBCERROR_LIBADD@

fmos_test_notify_SOURCES = \
	fmos_test_libcerror.h \
	fmos_test_libfmos.h \
	fmos_test_macros.h \
	fmos_test_notify.c \
	fmos_test_unused.h

fmos_test_notify_LDADD = \
	../libfmos/libfmos.la \
	@LIBCERROR_LIBADD@

fmos_test_support_SOURCES = \
	fmos_test_libfmos.h \
	fmos_test_macros.h \
	fmos_test_support.c \
	fmos_test_unused.h

fmos_test_support_LDADD = \
	../libfmos/libfmos.la

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

