if HAVE_PYTHON
AM_CFLAGS = \
	-I../include -I$(top_srcdir)/include \
	-I../common -I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBFMOS_DLL_IMPORT@

pyexec_LTLIBRARIES = pyfmos.la

pyfmos_la_SOURCES = \
	pyfmos.c pyfmos.h \
	pyfmos_adc.c pyfmos_adc.h \
	pyfmos_error.c pyfmos_error.h \
	pyfmos_libcerror.h \
	pyfmos_libfmos.h \
	pyfmos_lzfse.c pyfmos_lzfse.h \
	pyfmos_lzvn.c pyfmos_lzvn.h \
	pyfmos_python.h \
	pyfmos_unused.h

pyfmos_la_LIBADD = \
	@LIBCERROR_LIBADD@ \
	../libfmos/libfmos.la

pyfmos_la_CPPFLAGS = $(PYTHON_CPPFLAGS)
pyfmos_la_LDFLAGS  = -module -avoid-version $(PYTHON_LDFLAGS)

endif

DISTCLEANFILES = \
	Makefile \
	Makefile.in

