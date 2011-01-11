setenv MCP_PATH /esw/user/nfs/iawillia/fakeroot
if (-e /esw/fakeroot/) then
    setenv MCP_PATH /esw/fakeroot
endif


setenv PATH ${PATH}:${MCP_PATH}/opt/mcp/bin:${MCP_PATH}/usr/bin:`pwd`/src/build/trace
