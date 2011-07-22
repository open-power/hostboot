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
