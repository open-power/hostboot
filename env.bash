# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: env.bash $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2010,2014
#
# p1
#
# Object Code Only (OCO) source materials
# Licensed Internal Code Source Materials
# IBM HostBoot Licensed Internal Code
#
# The source code for this program is not published or otherwise
# divested of its trade secrets, irrespective of what has been
# deposited with the U.S. Copyright Office.
#
# Origin: 30
#
# IBM_PROLOG_END_TAG
ROOTDIR=.

if [ -e ./customrc ]; then
    source ./customrc
fi

export FAKEROOT=${FAKEROOT:-/opt/mcp/shared/powerpc64-gcc-20130412}
export CROSS_PREFIX=${CROSS_PREFIX:-${FAKEROOT}/wrappers/powerpc64-unknown-linux-gnu-}
export HOST_PREFIX=${HOST_PREFIX:-${FAKEROOT}/wrappers/x86_64-pc-linux-gnu-}
export PATH=${FAKEROOT}/wrappers:${PATH}

export PATH=${PATH}:`pwd`/src/build/trace
export PATH=${PATH}:`pwd`/src/build/tools

export HOSTBOOTROOT=`pwd`
TOOLSDIR=$HOSTBOOTROOT/src/build/tools

if [ -n "${SANDBOXROOT}" ]; then
    if [ -n "${SANDBOXNAME}" ]; then
        export SANDBOXBASE="${SANDBOXROOT}/${SANDBOXNAME}"
    fi
fi

export DEFAULT_MACHINE=MURANO

##  run setupgithooks.pl
if [ -e $TOOLSDIR/setupgithooks.sh ]; then
    $TOOLSDIR/setupgithooks.sh
fi
