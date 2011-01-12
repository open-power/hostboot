export MCP_PATH=/opt/mcp/shared/powerhal

if [ -e /esw/fakeroot/ ]; then
    export MCP_PATH=/esw/fakeroot
fi

export PATH=${PATH}:${MCP_PATH}/opt/mcp/bin:${MCP_PATH}/usr/bin:`pwd`/src/build/trace
