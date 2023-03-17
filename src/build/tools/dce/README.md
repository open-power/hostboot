
# Hostboot Dynamic Code Execution Framework

The Hostboot DCE Framework is a set of scripts and Hostboot code intended to make developing Hostboot code
faster. Rather than building the entire Hostboot repository, patching a machine and re-IPLing for each new change,
developers can IPL once, compile a standalone C or C++ file in a few seconds, and run their changes
immediately. Using DCE, developers can even run new code on a machine without building Hostboot at all.

Code compiled with DCE can define new functions, print to the console, and call any Hostboot function that would be
callable from normal Hostboot code.

When DCE code crashes, the most recent backtrace from the kernel's printk buffer is dumped to the SOL console and
the user can rebuild or run again immediately with no downtime, which aids debugging and speeds testing.

DCE supports eBMC-based machines (simulated or hardware), and standalone SIMICS. FSP-based machines are
not supported.

(Note: DCE cannot be used when secure mode is enabled.)

## Usage

There are three steps to running custom C++ code on a BMC machine:

1. Write your code and compile/link/package it into a LID file.
2. Istep your machine or simulation to the point you want to run your code. (BMC-based hardware must pass the PDR
   exchange at the end of istep 6).
3. Execute the LID file (via SIMICS command for standalone simulation, or using the included executor script for
   BMC systems after copying the file to the BMC).

### Step 1: Compiling and packaging

In this example we will be running our code on a BMC machine and working out of a Hostboot repository that has already
been built (but not necessarily primed) and which has been used to patch a machine you want to run code on (i.e. the
machine is using the same binaries as are in the Hostboot repository). For instructions on how to use DCE without
building Hostboot yourself, see the section below titled "Running DCE without building Hostboot".

The default Hostboot Make scripts are capable of compiling and packaging code to be run with DCE.

For this example, put this code into a file called `foo.C` (the filename doesn't matter as long as it has the `.C`
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

Then run `make foo.dce.lid` (i.e. replace the '.C' suffix with '.dce.lid') from the project root.
You will see output similar to this:

```bash
$ make foo.dce.lid
./src/build/tools/dce/dce-compile "foo.C" -o foo.dce.lid.intermediate -I./src/include/ -I./src/subtree/ -I./obj/genfiles
+ /opt/mcp/shared/powerpc64-gcc-20190822/bin/powerpc64le-buildroot-linux-gnu-g++ -D__HOSTBOOT_MODULE=DCE -DNO_INITIALIZER_LIST -DNO_PLAT_STD_STRING_SUPPORT -D__FAPI -include config.h -Os -nostdlib -nostdinc -g -mno-vsx -mno-altivec -Werror -Wall -mtraceback=no -pipe -ffunction-sections -fdata-sections -ffreestanding -mbig-endian -DFAPI2_ENABLE_PLATFORM_GET_TARGET -DCOMPILETIME_TRACEHASH -nostdinc++ -fno-rtti -fno-exceptions -Werror -Wall -fuse-cxa-atexit -std=gnu++14 -s -Os -nostdinc -nostdlib -nostartfiles -fPIC -Wl,-z,norelro -Wl,-z,max-page-size=1 -fno-zero-initialized-in-bss -mabi=elfv1 -I /esw/san5/zach/hostboot-dce-test/src/include -I /esw/san5/zach/hostboot-dce-test/src/include/usr -I /esw/san5/zach/hostboot-dce-test/src/subtree -I /esw/san5/zach/hostboot-dce-test/obj/genfiles -shared foo.C -o foo.dce.lid.intermediate -I./src/include/ -I./src/subtree/ -I./obj/genfiles -T /esw/san5/zach/hostboot-dce-test/src/build/tools/dce/dce.ld
./src/build/tools/dce/preplib.py foo.dce.lid.intermediate
mv foo.dce.lid.intermediate.lid foo.dce.lid
Copy foo.dce.lid to the BMC
```

As the output says, this will produce a file named `foo.dce.lid` that can be copied to the BMC.

Note: any time you rebuild hbicore.bin, you have to rebuild the DCE code. If you use `make`, the makefile will
automatically skip rebuilding the DCE code if it isn't necessary.

### Step 2: IPL the machine

DCE code on BMC machines can be run at nearly any time that Hostboot IPL code can process PLDM requests, but it's
convenient to pause the IPL at some point somehow (either by using the `istep` command or else by patching the machine
to hang the IPL manually). The machine must be booted past the PDR exchange (i.e. near the end of istep 6) for the
machine to respond to DCE requests. Make sure that secure mode is disabled before IPLing.

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

Additionally, put your source file (`foo.C` as in the example above) anywhere in the filesystem.

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

## Standalone SIMICS example

Using DCE with standalone SIMICS is similar to the above, but is a bit simpler:

1. Build for standalone Hostboot as normal and prime your sandbox with the `--test` flag.
2. Build your code with `make myfile.dce.test.lid`. (Note the suffix `dce.test.lid` instead of the usual `dce.lid`.)
3. Launch SIMICS, and execute the `hb-pauseIstepsAt <major> <minor>` command to ask Hostboot to wait at the beginning
   of the Istep where you want to run your code. (For example `hb-pauseIstepsAt 6 7` for Istep 6.7.)
4. Optionally run `hb-simicsLPCConsole` to redirect the LPC console to the SIMICS console (to make it easier to see
   the output of your DCE programs).
5. Run SIMICS until it reaches your desired Istep and pauses.
6. Run `hb-executeDCELid path/to/myfile.dce.test.lid` to execute your code. You can rebuild (step 2) and rerun as
   desired without having to restart Hostboot.

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
$ INCDIR=$PROJECT_ROOT/src/subtree/openbmc/pldm/libpldm/include/libpldm  make foo.dce.lid
```

Note: any time you rebuild hbicore.bin you have to rebuild the DCE code lid too, because the linker needs to know the
exact addresses of the symbols in hbicore.bin and if they change then the DCE code must be relinked.

### Accessing private class data

By default, your DCE scripts won't be able to access the private or protected instance variables inside existing
Hostboot classes, just like normal C++ code. However, the distinction between private and public member variables is
purely a compile-time concept. By telling the compiler that you actually do have access to the data, you can read it
like any other data:

    #define private public
    #include <whatever.h>

Now you can access all the private data inside classes declared in `whatever.h`.

### Calling functions that aren't declared in a header

Some functions in Hostboot are defined in C files and are not declared anywhere in any header file for you to
include. You can still call these functions without copying and pasting them into your DCE source files by simply
putting a forward declaration of the function in your DCE files (make sure to get it in the correct namespace).

For example, if this function is defined in `src/usr/isteps/initservice/istepdispatcher.C`:

```cpp
namespace INITSERVICE
{

void foo() {
    // do stuff here
}

}
```

You can add this to your DCE file:

```cpp
namespace INITSERVICE
{

void foo();

}
```

And call `INITSERVICE::foo` as any other function.

Note that if a function in a Hostboot implementation file is defined with internal linkage (i.e. it is declared as a
`static` global function or in an anonymous namespace), that function cannot be called in any way from outside that
file, even with a forward declaration. You will need to copy and paste the entire implementation into your DCE source
file(s) to use such code. This is because the compiler does not emit symbol information for such functions, and indeed
may not even emit a body for such functions at all if it decides to inline all its uses. (A hacky workaround is to
`#include` the .C file as if it were a header file, which will do the equivalent of copying and pasting the
implementation into your .C file.)

### Using multiple code files

If you are developing code where you don't want all of it to be in the same file you can make multiple .C files to
compile along with the main .C file which has the dce entrypoint function in it. To do this, simply create the
separate code normally in any number of additional files with the extension .C then you can include the prototypes in
.H files in the  main .C file.

When you are ready to compile, either create a new env var named DCE_EXTRA_FILES with the list of the .C and H files
you created or declare it on the command line along with the make invocation.

For example, here are the multiple files contents:

test.C
```cpp
#include <console/consoleif.H>

void hey()
{
    CONSOLE::displayf(CONSOLE::DEFAULT, NULL,
            "Hello World");
}
```

test.H
```cpp
void hey(void);
```

foo.C
```cpp
#include "test.H"

int main()
{
    hey();
    return 0;
}
```

and on the command line, you would type:

```bash
DCE_EXTRA_FILES="test.C test.H" make foo.dce.lid
```

You can now copy the resulting LID onto the system and invoke it with the script as normal. Alternatively, if you place
your extra files in src/build/tools/dce/dce-extra-files/ the dce_rc file in there can be sourced before compile and it
will update your environment variables for you.

### dce_rc file

In src/build/tools/dce/dce-extra-files there is an rc file that can be updated and sourced before each compile of DCE as
needed. This file is not automatically sourced, it must be manually sourced by the user. It is also .gitignored to avoid
users accidentally committing their personalized version of the file. If an update to dce_rc is required for all users
then be sure to include the file in the commit with `git add -f`.

If you are going to source this file, you must not place your main DCE file in the same location as
DCE_EXTRA_FILES_LOCATION as this will cause compile issues. (multiple definition errors from being included in the
compile twice).

There a few helpful env vars but DCE_EXTRA_FILES should be left alone. It's defaulted to populate itself with
all additional files required for the main .C file. All you need to do is update DCE_EXTRA_FILES_LOCATION if you want
to locate your files elsewhere from the default.

#### Symlinking hostboot code into DCE_EXTRA_FILES_LOCATION

If desired, you can create symlinks to hostboot code you would like to test with instead of copying implementations into
new files. This allows you to test your code in-place, gathering tracing exactly where you desire, and reduces overhead
of getting your code ready to commit.

To do this, simply make a symlink of the file in the DCE_EXTRA_FILES_LOCATION like so:
    `ln -s $PROJECT_ROOT/file.C $DCE_EXTRA_FILES_LOCATION`

As long as your include paths are correct and you've symlinked in the necessary headers as well, you will be able to
compile your dce code as usual. Now you can add on to the existing file and when you're done just commit the .C/.H files
as usual.

Many pieces of hostboot already have testcases created for you to use. To use those in conjunction with your symlinked
files all you need to do is symlink in the relevant testcases and in your main_dce.C file do the following

```cpp
#define MANUAL_CXXTEST
#include "existing_cxxtest.H"

int main()
{
    // Create testcase object found in existing_cxxtest.H
    myTest t;
    // Invoke a test
    t.testMyCode();

    return 0;
}
```

This essentially allows you to isolation test existing hostboot code without having to recompile hostboot or make a
duplicate DCE only implementation.

## Checkpoints

DCE is fully compatible with SIMICS checkpoints, and in particular with standalone SIMICS. Save a checkpoint with your
machine waiting at the appropriate Istep, develop and execute DCE code, then reload your checkpoint later to pick up
where you left off. For example

```
$ hb startsimics
simics> hb-pauseIstepsAt 6 7 # Pause hostboot at the beginning of istep 6.7
simics> hb-simicsLPCConsole # Redirect the LPC console to the simics console (so we can see it more easily)
simics> c
... simics boots to istep 6.7, hb pauses ...
running> stop
simics> write-configuration whatever.save # when we load this checkpoint, simics will resume at this point
... do your work, quit simics ...
$ HB_SIMICS_CHECKPOINT=whatever.sav hb startsimics
... simics loads to standby at the point where you saved the checkpoint ...
simics> hb-simicsLPCConsole # This doesn't get saved as part of the checkpoint
simics> c
... pick up where you left off ...
```

## Traces

In DCE scripts, all TRACFCOMP is redirected to the LPC/SOL console. This was done by redefining TRACFCOMP in trace_defs.H
under src/build/tools/dce/dce-extra-files.

## Restrictions

There are certain features of C++ and Hostboot that DCE code does not support:

1. thread_local

DCE does not yet support thread_local. This is due to be fixed in the future.

## Gotchas

1. If DCE code crashes, global destructors will not be called.

2. Accessing data in unloaded modules

   Be careful about accessing Hostboot functions and data that are resident in modules that may be unloaded
   when you invoke your DCE script. For example, to call a function defined in libsbeio.so, that module
   must be loaded. You can do this either by istepping to a step that loads your module and invoking your module
   at that time, or else using the VFS module loader directly:

       VFS::module_load("libsbeio.so");

3. The DCE main function must have a return statement.

   In normal C++ programs, it is legal to omit the return statement in the main function, and the compiler inserts
   a return of 0 for you. With DCE, omitting the return statement from main may cause your code to crash. (You
   will see a compiler warning if you accidentally forget.)

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
