# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: env.bash $
#
# OpenPOWER HostBoot Project
#
# COPYRIGHT International Business Machines Corp. 2010,2014
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
# implied. See the License for the specific language governing
# permissions and limitations under the License.
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
