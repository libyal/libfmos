#!/bin/sh
# Script to run tests
#
# Version: 20260714

if [ -f "${PWD}/libfmos/.libs/libfmos.1.dylib" ] && [ -f ./pyfmos/.libs/pyfmos.so ]
then
    install_name_tool -change /usr/local/lib/libfmos.1.dylib "${PWD}/libfmos/.libs/libfmos.1.dylib" ./pyfmos/.libs/pyfmos.so
fi

make check-build > /dev/null

# shellcheck disable=SC2068
make check $@
RESULT=$?

if [ ${RESULT} -ne 0 ]
then
    find . -name \*.log -path \*.dir/\*/\*.log -print -exec cat {} \;
fi
exit ${RESULT}

