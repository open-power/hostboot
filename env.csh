setenv MCP_PATH /opt/mcp/shared/powerhal
if (-e /esw/fakeroot/) then
    setenv MCP_PATH /esw/fakeroot
endif


setenv PATH ${PATH}:${MCP_PATH}/opt/mcp/bin:${MCP_PATH}/usr/bin:`pwd`/src/build/lids:`pwd`/src/build/trace:`pwd`/src/build/tools
