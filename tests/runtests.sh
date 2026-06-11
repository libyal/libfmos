#!/bin/sh
# Script to run tests
#
# Version: 20260609

if test -f ${PWD}/libfmos/.libs/libfmos.1.dylib && test -f ./pyfmos/.libs/pyfmos.so
then
	install_name_tool -change /usr/local/lib/libfmos.1.dylib ${PWD}/libfmos/.libs/libfmos.1.dylib ./pyfmos/.libs/pyfmos.so
fi

make check-build > /dev/null

make check $@
RESULT=$?

if test ${RESULT} -ne 0
then
	find . -name \*.log -path \*.dir/\*/\*.log -print -exec cat {} \;
fi
exit ${RESULT}

