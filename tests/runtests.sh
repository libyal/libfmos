#!/bin/sh
# Script to run tests
#
# Version: 20201121

if test -f ${PWD}/libfmos/.libs/libfmos.1.dylib && test -f ./pyfmos/.libs/pyfmos.so;
then
	install_name_tool -change /usr/local/lib/libfmos.1.dylib ${PWD}/libfmos/.libs/libfmos.1.dylib ./pyfmos/.libs/pyfmos.so;
fi

make check CHECK_WITH_STDERR=1;
RESULT=$?;

if test ${RESULT} -ne 0 && test -f tests/test-suite.log;
then
	cat tests/test-suite.log;
fi
exit ${RESULT};

