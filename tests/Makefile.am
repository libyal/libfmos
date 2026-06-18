AM_CPPFLAGS = \
	-I../include -I$(top_srcdir)/include \
	-I../common -I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCTHREADS_CPPFLAGS@ \
	@LIBCNOTIFY_CPPFLAGS@ \
	@PTHREAD_CPPFLAGS@ \
	@LIBFMOS_DLL_IMPORT@

BUILT_SOURCES = package.m4

check_AUTOTESTS = \
	test_library \
	test_manpages

if HAVE_PYTHON_TESTS
check_AUTOTESTS += test_python_module
endif

check_SCRIPTS = \
	pyfmos_test_adc.py \
	pyfmos_test_lzfse.py \
	pyfmos_test_lzvn.py \
	pyfmos_test_support.py

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

AUTOM4TE = autom4te
AUTOTEST = $(AUTOM4TE) --language=autotest

SUFFIXES = .at

.at:
	$(AM_V_GEN)rm -f $@ $@.tmp; \
	$(AUTOTEST) -I '$(srcdir)' -o $@.tmp $< && \
	mv $@.tmp $@

atconfig: $(top_builddir)/config.status
	cd $(top_builddir) && $(SHELL) ./config.status tests/$@

check-build: $(check_PROGRAMS)

check-local: $(check_AUTOTESTS)
	@fail=0; \
	for test_suite in $(check_AUTOTESTS); do \
		$(AM_TESTS_ENVIRONMENT) $(SHELL) "./$$test_suite" $(TESTSUITEFLAGS) || fail=1; \
		echo ""; \
	done; \
	exit $$fail

clean-local:
	for test_suite in $(check_AUTOTESTS); do \
		test ! -f "$$test_suite" || $(SHELL) "./$$test_suite" --clean; \
	done

package.m4: $(top_srcdir)/configure.ac
	$(AM_V_GEN):; \
	{ \
	  echo 'm4_define([AT_PACKAGE_NAME], [$(PACKAGE_NAME)])' ; \
	  echo 'm4_define([AT_PACKAGE_TARNAME], [$(PACKAGE_TARNAME)])' ; \
	  echo 'm4_define([AT_PACKAGE_VERSION], [$(PACKAGE_VERSION)])' ; \
	  echo 'm4_define([AT_PACKAGE_STRING], [$(PACKAGE_STRING)])' ; \
	  echo 'm4_define([AT_PACKAGE_BUGREPORT], [$(PACKAGE_BUGREPORT)])' ; \
	} > $@

test_library: \
	package.m4 \
	test_library.at \
	test_macros.at

test_manpages: \
	package.m4 \
	test_manpages.at

test_python_module: \
	package.m4 \
	test_python_module.at

EXTRA_DIST = \
	$(check_AUTOTESTS:=.at) \
	$(check_SCRIPTS) \
	package.m4 \
	test_macros.at

CLEANFILES = \
	$(check_AUTOTESTS) \
	*.exe \
	*.tmp \
	notify_stream.log

DISTCLEANFILES = \
	*.log \
	atconfig \
	Makefile \
	Makefile.in

