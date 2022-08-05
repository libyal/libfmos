if HAVE_LIB_FUZZING_ENGINE
AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common

bin_PROGRAMS = \
	adc_fuzzer \
	lzfse_fuzzer \
	lzvn_fuzzer

adc_fuzzer_SOURCES = \
	adc_fuzzer.cc \
	ossfuzz_libfmos.h

adc_fuzzer_LDADD = \
	@LIB_FUZZING_ENGINE@ \
	../libfmos/libfmos.la

lzfse_fuzzer_SOURCES = \
	lzfse_fuzzer.cc \
	ossfuzz_libfmos.h

lzfse_fuzzer_LDADD = \
	@LIB_FUZZING_ENGINE@ \
	../libfmos/libfmos.la

lzvn_fuzzer_SOURCES = \
	lzvn_fuzzer.cc \
	ossfuzz_libfmos.h

lzvn_fuzzer_LDADD = \
	@LIB_FUZZING_ENGINE@ \
	../libfmos/libfmos.la
endif

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

splint:
	@echo "Running splint on adc_fuzzer ..."
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(adc_fuzzer_SOURCES)
	@echo "Running splint on lzfse_fuzzer ..."
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(lzfse_fuzzer_SOURCES)
	@echo "Running splint on lzvn_fuzzer ..."
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(lzvn_fuzzer_SOURCES)

