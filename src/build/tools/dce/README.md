
# Hostboot Dynamic Code Execution Framework

The Hostboot DCE Framework is a set of scripts and Hostboot code intended to make developing Hostboot code
faster. Rather than building the entire Hostboot repository, patching a machine and re-IPLing for each new change,
developers can IPL once, compile a standalone C or C++ file in a few seconds, and run their changes
immediately. Using DCE, developers can even run code on a machine without building Hostboot at all.

Code compiled with DCE can define new functions, print to the console, and call any Hostboot function that would be
callable from normal Hostboot code.

When DCE code crashes, the most recent backtrace from the kernel's printk buffer is dumped to the SOL console,
which aids debugging and speeds testing.

DCE supports eBMC-based machines (simulated or hardware). FSP-based machines are not supported.

(Note: DCE cannot be used when secure mode is enabled.)

## Usage

There are three steps to running custom C++ code on a BMC machine:

1. Write your code and compile/link/package it into a LID file.
2. Istep your machine past the PDR exchange (i.e. the end of istep 6).
3. Copy the LID file to the BMC and run the executor script.

### Step 1: Compiling and packaging

In this example we will be working out of a Hostboot repository that has already been built (but not necessarily
primed) and which has been used to patch a machine you want to run code on (i.e. the machine is using the same
binaries as are in the Hostboot repository). For instructions on how to use DCE without building Hostboot yourself,
see the section below titled "Running DCE without building Hostboot".

The default Hostboot Make scripts are capable of compiling and packaging code to be run with DCE.

For this example, put this code into a file called `foo.c++` (the filename doesn't matter as long as it has the `.c++`
extension, but we will need to remember the filename for later):

```cpp

#include <console/consoleif.H>
#include <pldm/extended/sbe_dump.H>
#include <targeting/common/utilFilter.H>

using namespace TARGETING;

int main()
{
    TargetHandleList procs;
    getAllChips(procs, TYPE_PROC);

    assert(!procs.empty());

    CONSOLE::displayf(CONSOLE::DEFAULT, NULL,
                      "Requesting SBE dump for HUID 0x%08x",
                      get_huid(procs.back()));

    auto errl = PLDM::dumpSbe(procs.back(), 0x12345678);

    CONSOLE::displayf(CONSOLE::DEFAULT, NULL,
                      "SBE dump for HUID 0x%08x finished with error %p",
                      ERRL_GETPLID_SAFE(errl));

    errlCommit(errl, 0);

    return 0;
}
```

This example program uses some Hostboot functions to do an arbitrary task, which is in this case requesting an SBE
dump via PLDM.

The entrypoint of every DCE program is a function with the signature `int main()`.

Then run `make foo.dce.lid` (i.e. replace the `.c++` suffix with `.dce.lid`) and you will see this output:

```bash
$ make foo.dce.lid
./src/build/tools/dce/dce-compile "foo.c++" -o foo.dce.lid.intermediate -I./src/include/ -I./src/subtree/ -I./obj/genfiles
+ /opt/mcp/shared/powerpc64-gcc-20190822/bin/powerpc64le-buildroot-linux-gnu-g++ -D__HOSTBOOT_MODULE=DCE -DNO_INITIALIZER_LIST -DNO_PLAT_STD_STRING_SUPPORT -D__FAPI -include config.h -Os -nostdlib -nostdinc -g -mno-vsx -mno-altivec -Werror -Wall -mtraceback=no -pipe -ffunction-sections -fdata-sections -ffreestanding -mbig-endian -DFAPI2_ENABLE_PLATFORM_GET_TARGET -DCOMPILETIME_TRACEHASH -nostdinc++ -fno-rtti -fno-exceptions -Werror -Wall -fuse-cxa-atexit -std=gnu++14 -s -Os -nostdinc -nostdlib -nostartfiles -fPIC -Wl,-z,norelro -Wl,-z,max-page-size=1 -fno-zero-initialized-in-bss -mabi=elfv1 -I /esw/san5/zach/hostboot-dce-test/src/include -I /esw/san5/zach/hostboot-dce-test/src/include/usr -I /esw/san5/zach/hostboot-dce-test/src/subtree -I /esw/san5/zach/hostboot-dce-test/obj/genfiles -shared foo.c++ -o foo.dce.lid.intermediate -I./src/include/ -I./src/subtree/ -I./obj/genfiles -T /esw/san5/zach/hostboot-dce-test/src/build/tools/dce/dce.ld
./src/build/tools/dce/preplib.py foo.dce.lid.intermediate
mv foo.dce.lid.intermediate.lid foo.dce.lid
Copy foo.dce.lid to the BMC
```

As the output says, this will produce a file named `foo.dce.lid` that can be copied to the BMC.

Note: any time you rebuild hbicore.bin, you have to rebuild the DCE code. If you use `make`, the makefile will
automatically skip rebuilding the DCE code if it isn't necessary.

### Step 2: IPL the machine

DCE code can be run at nearly any time that Hostboot IPL code can process PLDM requests, but it's convenient to
pause the IPL at some point somehow (either by using the `istep` command or else by patching the machine to hang
the IPL manually). The machine must be booted past the PDR exchange (i.e. near the end of istep 6) for the machine
to respond to DCE requests. Make sure that secure mode is disabled before IPLing.

### Step 3: Copy the LID to the BMC and run it

Copy the LID to the patch folder on the BMC and name it `dcec0de.lid`:

```bash
$ scp foo.dce.lid root@hostname:/usr/local/share/hostfw/running/dcec0de.lid
```

You can also copy the executor script to the BMC (skip this step if you already have the script on the BMC):

```bash
$ scp dce-bmc-invoke.sh root@hostname:/tmp
```

Then, from the BMC, run the invocation script:

```bash
# /tmp/dce-bmc-invoke.sh
{
    "Response": "SUCCESS"
}
```

This will cause Hostboot to fetch your code from the `dcec0de.lid` file on the BMC and execute it. The output of your
code should appear in the SOL console.

You can edit, recompile/reupload and re-execute the LID file as many times as you like.

## Running DCE without building Hostboot

In the above example we built and executed a DCE binary from a Hostboot repository that had been compiled and
linked. It's also possible to do the same thing for an unpatched machine, because the files that were used to build
Hostboot are saved in the backing build. To build and run DCE code from a backing build, change directory into the
Hostboot build directory of the op-build setup from the driver. For example, if the driver on the machine you want
to run DCE code on is opp10.2299.20220118n, run:

```bash
$ cd /afs/rchland.ibm.com/projects/esw/oppp10ebmc/Builds/opp10.2299.20220118n/op-build/output/build/hostboot-p10-*/
```

Download the Hostboot config file for the machine type you want to run on (p10ebmc.config, for example) and put it
anywhere in the filesystem.

Additionally, put your source file (`foo.c++` as in the example above) anywhere in the filesystem.

Source the following script in your shell and replace the items in brackets as appropriate (this is essentially
doing the work of customrc):

```bash
export SANDBOXROOT=/path/to/sandbox/directory
export SANDBOXNAME=hostboot-dce
export MACHINE=P10_STANDALONE
export PNOR=p10.pnor
export CHIP=P10
export SIMICSOPTIONS=""
export CONFIG_FILE=/path/to/p10ebmc.config
```

Run `./hb workon` and then build the DCE LID with `make` as usual:

```bash
$ ./hb workon
$ make /path/to/source/file/foo.dce.lid
```

Then follow the instructions in the example above to copy your files to the BMC.

## Extras

### Module include directories

If you are developing code that will live in a certain module (i.e. libsbeio.so or something) and you need the include
paths to be set up as if your code were being compiled as part of that module, you can `cd` into the directory you
will be working from and run `make` from there:

```bash
$ cd src/usr/sbeio
$ make $PROJECT_ROOT/foo.dce.lid
```

This will compile your code with the same include paths that are used for the library in that folder.

If you need to add include directories to the compiler's search path, you can provide the INCDIR environment variable
to the makefile:

```bash
$ INCDIR=$PROJECT_ROOT/src/subtree/openbmc/pldm/libpldm  make foo.dce.lid
```

Note: any time you rebuild hbicore.bin you have to rebuild the DCE code lid too, because the linker needs to know the
exact addresses of the symbols in hbicore.bin and if they change then the DCE code must be relinked.

### Accessing private class data

The distinction between private and public member variables is purely a compile-time concept. By telling the compiler
that you actually do have access to the data, you can read it like any other data:

    #define private public

### Using multiple code files

If you are developing code where you don't want all of it to be in the same file you can make multiple .c++ files to
compile along with the main .c++ file which has the dce entrypoint function in it. To do this, simply create the
separate code normally in any number of additional files with the extension .c++ then you can include the prototypes in
.h++ files in main .c++ file.

When you are ready to compile, either create a new env var named DCE_EXTRA_FILES with the list of the .c++ and h++ files
you created or declare it on the command line along with the make invocation.

For example, here are the multiple files contents:

test.c++
```cpp
#include <console/consoleif.H>

void hey()
{
    CONSOLE::displayf(CONSOLE::DEFAULT, NULL,
            "Hello World");
}
```

test.h++
```cpp
void hey(void);
```

foo.c++
```cpp
#include "test.h++"

extern "C" int _start()
{
    hey();
    return 0;
}
```

and on the command line, you would type:

```bash
DCE_EXTRA_FILES="test.c++ test.h++" make foo.dce.lid
```

You can now copy the resulting lid onto the system and invoke it with the script as normal.

## Restrictions

There are certain features of C++ and Hostboot that DCE code does not support:

1. Traces

   The `TRACFCOMP` macro itself works as normal in DCE code. However, the trace hash won't be known to the trace
   decoder, so weave or similar tools will be unable to display the trace.

   You can turn all traces in the file into SOL console messages by putting this code below all the header include
   directives in your DCE source file:

```cpp
#undef TRACFCOMP
#define TRACFCOMP(X, ...) CONSOLE::displayf(CONSOLE::DEFAULT, NULL, __VA_ARGS__);
```

2. thread_local

DCE does not yet support thread_local. This is due to be fixed in the future.

## Gotchas

1. If DCE code crashes, global destructors will not be called.

2. Accessing data in unloaded modules

   Be careful about accessing Hostboot functions and data that are resident in modules that may be unloaded
   when you invoke your DCE script. For example, to call a function defined in libsbeio.so, that module
   must be loaded. You can do this either by istepping to a step that loads your module and invoking your module
   at that time, or else using the VFS module loader directly:

       VFS::module_load("libsbeio.so");

## Implementation details

### Overview

At the beginning of the IPL (during the PDR exchange), the DCE framework registers a PLDM state effecter with the PDR
manager, attached to the PLDM system entity. This state effecter has a unique state set ID to make it distinguishable
from the other state set effecters attached to the system entity. When the BMC makes a PLDM request to Hostboot to set
the state of this effecter (at the user's request, done by the dce-bmc-invoke.sh script), Hostboot will (1) reply to
the request immediately with a "success" status, and then (2) request a LID file from the BMC and execute the code
therein.

### Setting the PLDM effecter to start the code execution process

When the BMC and Hostboot have completed the PDR exchange, the BMC will be in possession of the state effecter PDR
that Hostboot created. When the user is ready, they can run the script `dce-bmc-invoke.sh`. This script will use the
DBUS FindStateEffecterPDR method to determine the effecter's ID, and then it will use the pldmtool utility to make a
PLDM SetStateEffecterStates request to Hostboot.

When Hostboot receives this request, it will respond with a "success" status, and start the process of retrieving the
code to execute from the BMC.

### Retrieving the code from the BMC

Hostboot retrieves the DCE code from the BMC by using the PLDM getLIDFile API. The DCE code must be stored in a LID
file named `dcec0de.lid`. This LID is completey refetched on every DCE invocation, so new versions can be uploaded
between each invocation to test new code.
