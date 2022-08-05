ACLOCAL_AMFLAGS = -I m4

SUBDIRS = \
	include \
	common \
	libcerror \
	libcthreads \
	libcnotify \
	libfmos \
	pyfmos \
	pyfmos-python2 \
	pyfmos-python3 \
	po \
	manuals \
	tests \
	ossfuzz \
	msvscpp

DPKG_FILES = \
	dpkg/changelog \
	dpkg/changelog.in \
	dpkg/compat \
	dpkg/control \
	dpkg/copyright \
	dpkg/rules \
	dpkg/libfmos.install \
	dpkg/libfmos-dev.install \
	dpkg/source/format

GETTEXT_FILES = \
	config.rpath \
	po/Makevars.in

PKGCONFIG_FILES = \
	libfmos.pc.in

SETUP_PY_FILES = \
	setup.py

SPEC_FILES = \
	libfmos.spec \
	libfmos.spec.in

EXTRA_DIST = \
	$(DPKG_FILES) \
	$(GETTEXT_FILES) \
	$(PKGCONFIG_FILES) \
	$(SETUP_PY_FILES) \
	$(SPEC_FILES)

MAINTAINERCLEANFILES = \
	Makefile.in

pkgconfigdir = $(libdir)/pkgconfig

pkgconfig_DATA = \
	libfmos.pc

libtool: @LIBTOOL_DEPS@
	cd $(srcdir) && $(SHELL) ./config.status --recheck

lib: library

library:
	(cd $(srcdir)/common && $(MAKE) $(AM_MAKEFLAGS))
	(cd $(srcdir)/libcerror && $(MAKE) $(AM_MAKEFLAGS))
	(cd $(srcdir)/libcthreads && $(MAKE) $(AM_MAKEFLAGS))
	(cd $(srcdir)/libcnotify && $(MAKE) $(AM_MAKEFLAGS))
	(cd $(srcdir)/libfmos && $(MAKE) $(AM_MAKEFLAGS))
	(cd $(srcdir)/po && $(MAKE) $(AM_MAKEFLAGS))

distclean: clean
	/bin/rm -f Makefile
	/bin/rm -f config.status
	/bin/rm -f config.cache
	/bin/rm -f config.log
	/bin/rm -f libfmos.pc
	/bin/rm -f libfmos.spec
	@for dir in ${subdirs}; do \
		(cd $$dir && $(MAKE) distclean) \
		|| case "$(MFLAGS)" in *k*) fail=yes;; *) exit 1;; esac; \
	done && test -z "$$fail"

splint:
	(cd $(srcdir)/libcerror && $(MAKE) splint $(AM_MAKEFLAGS))
	(cd $(srcdir)/libcthreads && $(MAKE) splint $(AM_MAKEFLAGS))
	(cd $(srcdir)/libcnotify && $(MAKE) splint $(AM_MAKEFLAGS))
	(cd $(srcdir)/libfmos && $(MAKE) splint $(AM_MAKEFLAGS))
	(cd $(srcdir)/po && $(MAKE) splint $(AM_MAKEFLAGS))
	(cd $(srcdir)/libclocale && $(MAKE) splint $(AM_MAKEFLAGS))
	(cd $(srcdir)/libuna && $(MAKE) splint $(AM_MAKEFLAGS))
	(cd $(srcdir)/libcfile && $(MAKE) splint $(AM_MAKEFLAGS))
	(cd $(srcdir)/tests && $(MAKE) splint $(AM_MAKEFLAGS))
	(cd $(srcdir)/ossfuzz && $(MAKE) splint $(AM_MAKEFLAGS))

