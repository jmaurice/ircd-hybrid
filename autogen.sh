#!/bin/sh
set -e
aclocal-1.9
autoheader
libtoolize --automake --ltdl
# Don't ask, but this is a workaround for libltdl in Debian unstable
sed -i -e 's/install-sh ltmain.sh missing mkinstalldirs/install-sh ltmain.sh missing/' libltdl/Makefile.in
automake-1.9 --add-missing
autoconf
./configure "$@"
