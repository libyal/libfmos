include_HEADERS = \
	libfmos.h

pkginclude_HEADERS = \
	libfmos/definitions.h \
	libfmos/error.h \
	libfmos/extern.h \
	libfmos/features.h \
	libfmos/types.h

EXTRA_DIST = \
	libfmos.h.in \
	libfmos/definitions.h.in \
	libfmos/features.h.in \
	libfmos/types.h.in

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f libfmos.h
	/bin/rm -f libfmos/definitions.h
	/bin/rm -f libfmos/features.h
	/bin/rm -f libfmos/types.h
	/bin/rm -f Makefile

