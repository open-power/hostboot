# Setting up auto-boot and auto-patching on Denali

HB_NFS_DIR is an environment variable that is required to trigger auto-booting and auto-patching in an ODE sandbox.
It points to the absolute path location where to find the hostboot code patches for FSP. It is recommended that the
final dir in the path be nfs. For example, /esw/user/nfs/mraybuck/sandbox/p10/nfs would be a valid path since it ends
with nfs. However, /esw/user/nfs/mraybuck/sandbox/p10/nfs/test/pnor is not. If the final dir isn't nfs then a warning
will be generated and the user is expected to know what they are doing.

For auto-booting and auto-patching to trigger it is required to set HB_NFS_DIR in your ODE sandbox workon environment
where you will be executing runsim_ode.py from.
