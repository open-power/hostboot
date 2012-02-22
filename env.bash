#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: env.bash $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2010 - 2011
#
#  p1
#
#  Object Code Only (OCO) source materials
#  Licensed Internal Code Source Materials
#  IBM HostBoot Licensed Internal Code
#
#  The source code for this program is not published or other-
#  wise divested of its trade secrets, irrespective of what has
#  been deposited with the U.S. Copyright Office.
#
#  Origin: 30
#
#  IBM_PROLOG_END
export MCP_PATH=/opt/mcp/shared/powerhal

if [ -e /esw/fakeroot/ ]; then
    export MCP_PATH=/esw/fakeroot
fi

export PATH=${PATH}:${MCP_PATH}/opt/mcp/bin:${MCP_PATH}/usr/bin

export PATH=${PATH}:`pwd`/src/build/lids
export PATH=${PATH}:`pwd`/src/build/trace
export PATH=${PATH}:`pwd`/src/build/tools

export HOSTBOOTROOT=`pwd`

if [ -e ./customrc ]; then
    source ./customrc
fi

if [ -n "${SANDBOXROOT}" ]; then
    if [ -n "${SANDBOXNAME}" ]; then
        export SANDBOXBASE="${SANDBOXROOT}/${SANDBOXNAME}"
    fi
fi

export DEFAULT_MACHINE=VENICE
