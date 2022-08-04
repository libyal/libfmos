# Note that we cannot use: AUTOMAKE_OPTIONS = subdir-objects
# subdir-objects will compile the source files to a single version of Python.
# Since subdir-objects is being deprecated we copy the source files instead.
am__installdirs = "$(DESTDIR)$(pyexecdir3)"
pyexecdir = $(pyexecdir3)

if HAVE_PYTHON3
AM_CFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBFMOS_DLL_IMPORT@

am_pyfmos_la_rpath = -rpath $(pyexecdir3)

BUILT_SOURCES = \
	pyfmos.c pyfmos.h \
	pyfmos_adc.c pyfmos_adc.h \
	pyfmos_error.c pyfmos_error.h \
	pyfmos_libcerror.h \
	pyfmos_libfmos.h \
	pyfmos_lzfse.c pyfmos_lzfse.h \
	pyfmos_lzvn.c pyfmos_lzvn.h \
	pyfmos_python.h \
	pyfmos_unused.h

pyexec_LTLIBRARIES = pyfmos.la

nodist_pyfmos_la_SOURCES = $(BUILT_SOURCES)

pyfmos_la_LIBADD = \
	@LIBCERROR_LIBADD@ \
	../libfmos/libfmos.la

pyfmos_la_CPPFLAGS = $(PYTHON3_CPPFLAGS)
pyfmos_la_LDFLAGS  = -module -avoid-version $(PYTHON3_LDFLAGS)

$(BUILT_SOURCES):
	/bin/cp -f $(top_srcdir)/pyfmos/$@ $@

endif

MAINTAINERCLEANFILES = \
	Makefile.in

clean-local:
	/bin/rm -f pyfmos*.[ch]

distclean: clean
	/bin/rm -f Makefile

