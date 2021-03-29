#!/usr/bin/python
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/simics-debug-framework.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2021
# [+] Google Inc.
# [+] International Business Machines Corp.
#
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

# @file simics-debug-framework.py
# @brief Simics/Python implementation of the common debug framework.
#
# This is the Python side of the simics implementation of the debug framework.
# It operates by opening a Perl script as a subprocess using stdin/stdout to
# the subprocess as an IPC pipe.
#
# The Python script will handle the bridging from framework primatives, such
# as 'readData', to Simics interfaces.  The script will also search for all
# existing debug modules and automatically instantiate simics commands of the
# form 'hb-Tool' so they can be used.
#
# If the users are expecting another tool name, such as 'hb-printk' instead of
# 'hb-Printk', or are expecting nicer parameter passing, such as
# 'hb-trace COMP1,COMP2' instead of 'hb-Trace "components=COMP1,COMP2"', then a
# manual wrapper command should be implemented in 'hb-simdebug.py'.


from __future__ import print_function
import os
import subprocess
import re
import random
import struct
import time
import binascii
import sys

# @class DebugFrameworkIPCMessage
# @brief Wrapper class for constructing a properly formed IPC message for the
#        Python-Perl bridge.
#
# The class provides a Pickle-like API (dumps / loads).
#
# Messages are of the format:
#       [ "type", "data-in-ascii-encoded-hex" ]
# Example:
#    The message...
#       [ "display", "48656c6c6f20576f726c642e0a" ]
#    means 'display "Hello World.\n"'
#
class DebugFrameworkIPCMessage:
    msgtype = "unknown"
    msg = ""

    def __init__(self, msgtype = "unknown", msg = ""):
        self.msgtype = msgtype
        self.msg = msg

    def dumps(self):
        if sys.version_info.major == 3:
            msg_bytes = bytes(self.msg, 'utf-8')
            return ("[ \"" + self.msgtype + "\", \"" +
                    binascii.hexlify(msg_bytes).decode('utf-8') + "\" ]\n")
        else:
            return ("[ \"" + self.msgtype + "\", \"" +
                self.msg.encode("hex") + "\" ]\n")

    def loads(self,string):
        pattern = re.compile("\[ \"([^\"]+)\", \"([0-9a-f]*)\" ]")
        match = pattern.search(string.decode())
        if  match is None:
            print(  "error: empty message >%s< received from perl"%(string))
            print(  "       Check for print's in your perl script!!!")
        else:
            self.msgtype = match.group(1)
            self.msg = bytearray.fromhex(match.group(2)).decode('utf-8')

# @class DebugFrameworkProcess
# @brief Provides a wrapper to the 'subprocess' interface and IPC bridge.
#
# This class also provides the handling functions for various bridge message
# types into the appropriate simics interface.
#
class DebugFrameworkProcess:
    process = "";               # subprocess object.
    tool = "";                  # string - tool module name.
    toolOptions = "";           # string - tool options
    outputToString = None;      # mode - String output instead of STDOUT.
    imgPath = None;             # Image dir path override.
    result = "";                # Result string for Usage-mode.
    outputFile = None;          # Output file for results in addition to STDOUT

    def __init__(self, tool = "Printk", toolOptions = "",
                       outputToString = None, usage = None,
                       imgPath = None,
                       outputFile = None):
        # Assign instance 'imgPath' variable.
        self.imgPath = imgPath if imgPath else (os.environ['HB_TOOLPATH']+"/");

        # Determine sub-process arguments.
        process_args = [self.imgPath+"simics-debug-framework.pl"];
        if (usage): # Pass --usage if Usage mode selected.
            process_args = process_args + [ "--usage" ];
            outputToString = True;

        # Spawn sub-process
        self.process = subprocess.Popen(process_args,
                               stdin=subprocess.PIPE, stdout=subprocess.PIPE)
        # Update instance variables.
        self.tool = tool;
        self.toolOptions = toolOptions;
        self.outputToString = outputToString;
        self.outputFile = open(outputFile, 'w') if outputFile else None;

    # Read a message from the process pipe.
    def recvMsg(self):
        msg = DebugFrameworkIPCMessage()
        line = self.process.stdout.readline()
        if len(line) != 0:
            msg.loads(line)
            return (msg.msgtype, msg.msg)
        else:
            return ("", "")

    # Send a message into the process pipe.
    def sendMsg(self,msgtype,msg):
        msg = DebugFrameworkIPCMessage(msgtype, msg)
        msg_dumps_bytes = str.encode(msg.dumps())
        self.process.stdin.write(msg_dumps_bytes)
        self.process.stdin.flush()

    # End sub-process by closing its pipe.
    def endProcess(self):
        self.process.stdin.close()

    # Display string (or save to result in Usage mode).
    def display(self,data):
        if (self.outputToString):
            self.result += data
        else:
            sys.stdout.write(data)
            sys.stdout.flush()

            if self.outputFile:
                self.outputFile.write(data)

    # Read data from memory.
    #    This message has data of the format "0dADDRESS,0dSIZE".
    def read_data(self,data):
        pattern = re.compile("([0-9]+),([0-9]+)")
        match = pattern.search(data)

        addr = int(match.group(1))
        size = int(match.group(2))

        data = "".join(map(chr,
            conf.system_cmp0.phys_mem.memory[[addr , addr+size-1]]))
        self.sendMsg("data-response", data)

    # Write data to memory.
    #    This message has data of the format "0dADDR,0dSIZE,hDATA".
    def write_data(self,data):
        pattern = re.compile("([0-9]+),([0-9]+),([0-9A-Fa-f]+)")
        match = pattern.search(data)

        addr = int(match.group(1))
        size = int(match.group(2))
        data = map(ord, match.group(3).decode("hex"));

        conf.system_cmp0.phys_mem.memory[[addr, addr+size-1]] = data;

    # Read data from PNOR.
    #    This message has data of the format "0dADDRESS,0dSIZE".
    def read_pnor(self,data):
        pattern = re.compile("([0-9]+),([0-9]+)")
        match = pattern.search(data)

        addr = int(match.group(1))
        size = int(match.group(2))

        data = "".join(map(chr,
            conf.fpga0.sfc_master_mem.memory[[addr , addr+size-1]]))
        self.sendMsg("data-response", data)

    # Clock forward the model.
    #    This message had data of the format "0dCYCLES".
    def execute_instrs(self,data):
        pattern = re.compile("([0-9]+)")
        match = pattern.search(data)

        cycles = int(match.group(1))

        ## @todo mww SIM_continue is busted, try this...
        if (not SIM_simics_is_running()):
            ## SIM_continue(cycles)
            syscmd   =   "run-cycles %d"%(cycles)
            ## print ">> %s"%(syscmd)
            ( rc, out )  =   quiet_run_command( syscmd, output_modes.regular )
            if ( rc ):
                print("simics ERROR running %s: %d "%( syscmd, rc ))

    def ready_for_instr(self,data):
        self.sendMsg("data-response", "0" if SIM_simics_is_running() else "1")

    # Get tool module name.
    def get_tool(self,data):
        self.sendMsg("data-response", self.tool)

    # Get tool options.
    def get_tool_options(self,data):
        self.sendMsg("data-response", self.toolOptions)

    # Get image path.
    def get_img_path(self,data):
        self.sendMsg("data-response", self.imgPath)

    # Read data from xscom address.
    #    This message has data of the format "0dADDRESS,0dSIZE".
    def read_xscom(self,data):
        pattern = re.compile("([0-9]+),([0-9]+)")
        match = pattern.search(data)

        addr = int(match.group(1))
        size = int(match.group(2))

        ##  read the register using xscom reg addresses
        runStr  =   "(system_cmp0.phys_mem).read 0x%x  0x%x"%(addr, size)
        ( result, out )  =   quiet_run_command( runStr, output_modes.regular )
        ## DEBUG print ">> %s: "%(runStr) + "0x%16.16x"%(result) + " : " + out
        self.sendMsg("data-response", "%16.16x"%(result) )


    # Write data to xscom address..
    #    This message has data of the format "0dADDR,0dSIZE,hDATA".
    def write_xscom(self,data):
        pattern = re.compile("([0-9]+),([0-9]+),([0-9]+)")
        match = pattern.search(data)

        addr = int(match.group(1))
        size = int(match.group(2))
        data = int(match.group(3) )

        runStr  =   "(system_cmp0.phys_mem).write 0x%x 0x%x 0x%x"%(addr, data, size)
        ( result, out )  =   quiet_run_command( runStr, output_modes.regular )
        ## DEBUG print ">> %s : "%(runStr) + " 0x%16.16x"%(result) + " : " + out
        if ( result ):
            print("simics ERROR running %s: %d "%( syscmd, result ))

    # Read HRMOR from processors.
    #    This message has no input data
    def get_hrmor(self,data):
        hrmor = getHRMOR()
        self.sendMsg("data-response", "%d"%(hrmor) )

    def decode_rc(self,data):
        pattern = re.compile("([0-9]+)")
        match = pattern.search(data)
        rc = int(match.group(1))
        syscmd = "shell hb_decoderc %x"%(rc)
        (r, out) = quiet_run_command(syscmd, output_modes.regular)
        if(r):
            print("simics ERROR running %s"%(syscmd))


# @fn run_hb_debug_framework
# @brief Wrapper function to execute a tool module.
#
# @param tool - Tool module to execute.
# @param toolOpts - String containing tool options.
# @param usage - Usage mode or Execute mode.
# @param imgPath - Image path override.
def run_hb_debug_framework(tool = "Printk", toolOpts = "",
                           outputToString = None, usage = None,
                           imgPath = None, outputFile = None):
    # Create debug sub-process.
    fp = DebugFrameworkProcess(tool,toolOpts,outputToString,
                               usage,imgPath,outputFile)

    # Read / handle messages until there are no more.
    msg = fp.recvMsg()
    while msg[0] != "":
        operations = { "display" :  DebugFrameworkProcess.display,
            "read-data" :           DebugFrameworkProcess.read_data,
            "write-data" :          DebugFrameworkProcess.write_data,
            "read-pnor" :           DebugFrameworkProcess.read_pnor,
            "execute-instrs" :      DebugFrameworkProcess.execute_instrs,
            "ready-for-instr" :     DebugFrameworkProcess.ready_for_instr,
            "get-tool" :            DebugFrameworkProcess.get_tool,
            "get-tool-options" :    DebugFrameworkProcess.get_tool_options,
            "get-img-path" :        DebugFrameworkProcess.get_img_path,
            "write-scom" :          DebugFrameworkProcess.write_xscom,
            "read-scom" :           DebugFrameworkProcess.read_xscom,
            "get-hrmor" :           DebugFrameworkProcess.get_hrmor,
            "exit" :                DebugFrameworkProcess.endProcess,
            "decode-rc" :           DebugFrameworkProcess.decode_rc,
        }
        operations[msg[0]](fp,msg[1])
        msg = fp.recvMsg()

    # If in Usage mode, return result string.
    if (usage or outputToString):
        return fp.result
    return None


# @fn register_hb_debug_framework_tools
# @brief Create a simics command wrapper for each debug tool module.
def register_hb_debug_framework_tools():
    # Find all modules from within Hostboot subdirectory.
    files = os.listdir(os.environ['HB_TOOLPATH']+"/Hostboot")

    # Filter out any prefixed with '_' (utility module) or a '.' (hidden file).
    pattern = re.compile("[^\._]");
    files = [f for f in files if pattern.match(f)]

    # Filter out modules written for vbu only
    pattern = re.compile("AutoIpl|ContTrace");
    files = [f for f in files if not pattern.match(f)]

    # Remove the .pm extension from the tool modules.
    files = [re.sub("\.pm","",f) for f in files];

    # Create an entry for each module.
    for tool in files:
        # Get usage information for each module, fix text to HTML-like.
        usage = run_hb_debug_framework(tool, usage = 1)
        usage = re.sub("<","&lt;", usage);
        usage = re.sub(">","&gt;", usage);
        usage = re.sub("\t","        ",usage)
        usage = "<pre>"+usage+"</pre>"

        # Create command hook.
        new_command("hb-" + tool,
                    (lambda toolname:
                        lambda options:
                            run_hb_debug_framework(toolname, options,
                                outputFile="hb-debug-"+toolname+".output"))
                    (tool),
                    args = [arg(str_t, "options", "?", "")],
                    alias = "hb-debug-" + tool,
                    type = ["hostboot-commands"],
                    short = "Runs the debug framework for tool " + tool,
                    doc = usage)
        print("Hostboot Debug Framework: Registered tool:", "hb-" + tool)

    # Do a quick file write test to make sure we can write files and set a
    # simics variable to let us know if we need to avoid file writes.
    SIM_run_command("$fileSystemOk=1")
    try:
        f = open('hbTracTEST', 'w')
        f.write("\n")
        f.close()
        os.system("rm -rf hbTracTEST")
    except:
        SIM_run_command("$fileSystemOk=0")


# Return a number/address built from the input list elements. Each element
# in the input is a string representation of a byte-sized hex number, for
# example '0x2b' or '0x0' or '0xa'.  This does no endian conversion, thus
# the input needs to be big endian.  The length of the input list can be
# any size, usually 2, 4, or 8.
def hexDumpToNumber(hexlist):
    strNumber=""
    for i in range(len(hexlist)):
        # take away 0x for this byte
        hexlist[i] = hexlist[i][2:]
        # zero-fill leading zeroes to make a 2-char string
        hexlist[i] = hexlist[i].zfill(2)
        # concatenate onto addr
        strNumber += hexlist[i]
    return int(strNumber,16)


# Fetch the current HRMOR value.
def getHRMOR():
    # Note: will default to using the currently selected cpu
    result = SIM_get_object(simenv.hb_cpu).hrmor
    return result

# Fetch the current l3 base value off the primary processor.
def getL3Base():
    result = SIM_get_attribute(SIM_get_object(simenv.hb_masterproc), "l3_base")
    return result


# Read simics memory and return a list of strings such as ['0x0','0x2b','0x8']
# representing the data read from simics. The list returned may be handed
# to hexDumpToNumber() to turn the list into a number.
def dumpSimicsMemory(address,bytecount):
    address = address + getHRMOR()
    hexlist = map(hex,
        conf.system_cmp0.phys_mem.memory[[address,address+bytecount-1]])
    return hexlist


# Read the 64-bit big endian at the address given, return it as a number.
def readLongLong(address):
    hexlist = dumpSimicsMemory(address,8)
    return hexDumpToNumber(hexlist)

def readLong(address):
    hexlist = dumpSimicsMemory(address,4)
    return hexDumpToNumber(hexlist)

def writeLong(address,datvalue):
    address = address + getHRMOR()
    conf.system_cmp0.phys_mem.memory[[address,address+3]] = [0,0,0,datvalue]
    return



# Write simics memory. address is an integer.
# data is a list of byte-sized integers.
def writeSimicsMemory(address,data):
    address = address + getHRMOR()
    size = len(data)
    conf.system_cmp0.phys_mem.memory[[address, address+size-1]] = data;

# Convert an integer to a byte list <size> bytes long.
def intToList(n,size):
    lst = []
    for i in range(size):
        b = n & 0xFF;
        lst.insert(0,b)
        n = n >> 8
    return lst

# Convert a byte list to an integer.
def listToInt(l):
    i = 0;
    for c in l:
        i = (i << 8) | c
    return i

# Write the 64-bit big endian n at the address given.
def writeLongLong(address,n):
    writeSimicsMemory(address,intToList(n,8))

# Recursively parse out the saved link-registers in a stack.
#   Param - cpu - CPU object to read stack from.
#   Param - frame - Pointer to the frame-pointer to be parsed.
def magic_memoryleak_stackdump(cpu, frame):

    if frame == 0:
        return []

    # Pointer to the next frame is at the current frame memory address.
    next_frame = \
        cpu.iface.processor_info.logical_to_physical(frame, 1).address
    next_frame = listToInt( \
        conf.system_cmp0.phys_mem.memory[[next_frame, next_frame+7]])

    if next_frame == 0:
        return []

    # The LR save area is 2 words ahead of the current frame pointer.
    lr_save = \
        cpu.iface.processor_info.logical_to_physical(frame + 16, 1).address
    lr_save = listToInt( \
        conf.system_cmp0.phys_mem.memory[[lr_save, lr_save+7]])

    # Recursively add LR to rest of the stack-frame.
    return [lr_save] + magic_memoryleak_stackdump(cpu, next_frame)

# Respond to the magic instruction for a memory allocation function call.
#   Param - cpu - The CPU raising the magic instruction.
#
#   Registers:
#       cpu.r3 - function called (see MemoryLeak_FunctionType).
#       cpu.r4 - size of allocation (for malloc / realloc).
#       cpu.r5 - pointer (result for malloc / realloc, parameter for free).
#       cpu.r6 - pointer2 (original pointer for realloc).
#
def magic_memoryleak_function(cpu):
    # Parse registers.
    function = ["MALLOC", "REALLOC", "FREE"][cpu.r3]
    size = cpu.r4
    ptr = cpu.r5
    ptr2 = cpu.r6

    # Find stack frame.
    stack_frame = \
        cpu.iface.processor_info.logical_to_physical(cpu.r1, 1).address
    stack_frame = listToInt( \
        conf.system_cmp0.phys_mem.memory[[stack_frame, stack_frame+7]])

    file = open("hb_memoryleak.dat", "a")

    # Output parameters.
    file.write("%s %d 0x%x 0x%x" % (function,size,ptr,ptr2))
    # Output stack backtrace.
    file.write(" [ %s ]\n" % str.join(" ", \
        ("0x%x" % i for i in magic_memoryleak_stackdump(cpu, stack_frame))))

    file.close()

# Erase the hb_memoryleak.dat save data when starting up.
try:
    os.remove("hb_memoryleak.dat")
except:
    1

hb_attr_dump_file = open('hb_attr_dump.bin', 'wb')



# MAGIC_INSTRUCTION hap handler
# arg contains the integer parameter n passed to MAGIC_INSTRUCTION(n)
# See src/include/arch/ppc.H for the definitions of the magic args.
# Hostboot magic args should range 7000..7999.
def magic_instruction_callback(user_arg, cpu, arg):
    # Disable our handler if someone tells us to
    if( ('HB_DISABLE_MAGIC' in os.environ)
        and (os.environ['HB_DISABLE_MAGIC'] == '1') ):
        print('Skipping HB magic (disabled)', arg)
        return

    # HRMOR should match the l3 base that was set on the primary processor as
    # part of either hostboot or the SBE's startup.simics script
    if( (cpu.hrmor) & 0x00000000FFFFFFFF != getL3Base() ):
        print('Skipping HB magic (outside of HB): magic=', arg, ', hrmor=', cpu.hrmor, ', pir=', cpu.pir)
        return

    if arg == 7006:   # MAGIC_SHUTDOWN
        # KernelMisc::shutdown()
        print("KernelMisc::shutdown() called.")

    if arg == 7007:   # MAGIC_BREAK
        # Stop the simulation, much like a hard-coded breakpoint
        SIM_break_simulation( "Simulation stopped. (hap 7007)"  )

    if arg == 7008:
        cpu.r3 = random.randint(1, 0xffffffffffffffff)

    if arg == 7009:   # MAGIC_MEMORYLEAK_FUNCTION
        magic_memoryleak_function(cpu)

    if arg == 7011: #MAGIC_SIMICS_CHECK
        cpu.r3 = 1
        print("TimeManager::cv_isSimicsRunning = true")

    if arg == 7012:  # MAGIC_LOAD_PAYLOAD
        #For P9 the Payload load is much faster due to PNOR
        # not being behind cec-chip model, removing this but leaving
        # as comments if needed in the future
        #load_addr = cpu.r3
        #flash_file = conf.fpga0.sfc_master_mmio_image.files[0][0]
        #print 'loading payload from', flash_file, 'to 0x%x' % load_addr
        #cmd = 'shell "fcp --force -o0 -R %s:PAYLOAD simicsPayload.ecc; ecc --remove --p8 simicsPayload.ecc simicsPayload"; load-file simicsPayload 0x%x' % (flash_file, load_addr)
        #SIM_run_alone( run_command, cmd )
      print("MAGIC_LOAD_PAYLOAD not implemented\n")

    if arg == 7013: # MAGIC_IS_QME_ENABLED
        qmeEnabled = 0 if cpu.pcr_dev == None else 1
        cpu.r3 = qmeEnabled
        print("SIMICS QME model enabled = %d" % (qmeEnabled))

    if arg == 7014:   # MAGIC_HB_DUMP
        # Collect a hostboot dump
        # (no args)

        # Make sure we only do 1 dump even though every thread will TI
        if( not 'HB_DUMP_COMPLETE' in os.environ ):
            print("Generating Hostboot Dump for TI")
            os.environ['HB_DUMP_COMPLETE']="1"
            cmd1 = "hb-Dump quiet"
            SIM_run_alone(run_command, cmd1 )

    if arg == 7018:   # MAGIC_BREAK_ON_ERROR
        # Stop the simulation if an env var is set
        if( 'HB_BREAK_ON_ERROR' in os.environ ):
            SIM_break_simulation( "Stopping sim on HB error. (hap 7018)"  )

    if arg == 7019:   # MAGIC_GET_SBE_TRACES
        # Collect SBE traces out to a file
        proc_num = cpu.r4
        rc = cpu.r5
        # generate the traces
        cmd1 = "sbe-trace %d"%(proc_num)
        print("cmd1", cmd1)
        # copy the file somewhere safe
        # Ignore any issues with generating tracMERG via || true on cat, best to
        # continue running and gather other FFDC to debug why SBE tracMERG can not be
        # retrieved then cause SIMICS to fail with a "file not found" exception
        cmd2 = "shell \"echo '==HB Collecting Traces (iar=%X,rc=%X,sbe=%d)==' >> sbetrace.hb.txt; ( cat sbe_%d_tracMERG || true ) >> sbetrace.hb.txt\""%(cpu.iar,rc,proc_num,proc_num)
        print("cmd2", cmd2)

        saveCommand = "%s; %s"%(cmd1,cmd2)
        SIM_run_alone(run_command, saveCommand )

    if arg == 7020:   # MAGIC_PRINT_ISTEP
        # Print current istep out to simics console
        major_istep = cpu.r4
        minor_istep = cpu.r5
        print("%d > ISTEP %d.%d" % (int(time.time()), major_istep, minor_istep))

    if arg == 7021:  # MAGIC_PRINT_TWO_REGS
        first_num = cpu.r4
        second_num = cpu.r5
        percent_s = "%s"
        dateCommand = "shell \" date +'%s > TRACE REGS: %d %d' \""%(percent_s,first_num,second_num)
        SIM_run_alone(run_command, dateCommand )

    if arg == 7025:  # MAGIC_SETUP_THREADS
        print("Setting up urmor for all PIRs")
        # Hook to update SMF MSR bit if needed
        smfEnabled = cpu.r4

        cpu_list=hb_get_objects_by_class("ppc_power10_mambo_core")
        for othercpu in cpu_list:
            othercpu.urmor = cpu.urmor
            othercpu.hrmor = cpu.hrmor
            othercpu.tb = cpu.tb

    if arg == 7022:  # MAGIC_SET_LOG_LEVEL
        if( not 'ENABLE_HB_SIMICS_LOGS' in os.environ ):
            #print("Skipping Hostboot Simics Logging because ENABLE_HB_SIMICS_LOGS is not set")
            return

        hb_hrmor = cpu.hrmor
        # see NODE_OFFSET in memorymap.H
        per_node = 0x400000000000   #64TB
        per_chip = 0x40000000000    #4TB
        node_num = hb_hrmor//per_node
        # TODO RTC:200729 right now for 3 node systems the chip is getting calculated wrong
        proc_num = hb_hrmor//per_chip
        comp_id = cpu.r4
        log_level = cpu.r5
        # note the following list of component IDs must be kept in sync
        # with the const defintions in sync with src/include/arch/ppc.H
        component = [ ".pib_psu",      # comp_id = 0
                      ".sbe.int_bo" ]  # comp_id = 1

        comp_str = ""
        # Right now only 2 components are supported, this if check
        # needs to be updated if more components are supported
        if comp_id >= 0 or  comp_id <= 1:
            #TODO RTC:200729 Simics team is coming up with a better way to lookup object
            #check if D1Proc0 exists
            D1Proc0String = "D1Proc0"
            try:
                if(SIM_get_object(D1Proc0String)) :
                    print (D1Proc0String+" object found")
                    comp_str = "D%dProc%d"%((node_num + 1), proc_num )
            except:
                print("No "+D1Proc0String+" object found")

            #check if P9Proc0 exists
            P9Proc0String = "p9Proc0"
            try:
                if(SIM_get_object(P9Proc0String)) :
                    print (P9Proc0String+" object found")
                    comp_str = "p9Proc%d"%(proc_num )
            except:
                print("No "+P9Proc0String+" object found")

            if comp_str != "" :
                comp_str += component[comp_id]

                printCommand = "shell \" date +' MAGIC_SET_LOG_LEVEL(%d) for %s' \""%(log_level, comp_str)
                SIM_run_alone(run_command, printCommand )

                setLvlCommand = "%s"%(comp_str)+".log-level %d"%(log_level)
                SIM_run_alone(run_command, setLvlCommand )
            else :
                print("Unable to find valid object on this system type, neither %s nor %s were found"%(D1Proc0String, P9Proc0String))

    if arg == 7023:  # MAGIC_TOGGLE_OUTPUT
        if( not 'ENABLE_HB_SIMICS_LOGS' in os.environ ):
            #print("Skipping Hostboot Simics Logging because ENABLE_HB_SIMICS_LOGS is not set")
            return

        enable = cpu.r4
        zero = 0;
        if enable > zero :
            startCommand = "output-file-start hostboot_simics_log.txt -append -timestamp"
            SIM_run_alone(run_command, startCommand )
            printCommand = "shell \" date +'>> MAGIC_TOGGLE_OUTPUT(1) starting output' \""
            SIM_run_alone(run_command, printCommand )
        else :
            printCommand = "shell \" date +'<< MAGIC_TOGGLE_OUTPUT(0) stopping output' \""
            SIM_run_alone(run_command, printCommand )
            stopCommand = "output-file-stop hostboot_simics_log.txt"
            SIM_run_alone(run_command, stopCommand )

    if arg == 7055:   # MAGIC_CONTINUOUS_TRACE

        hb_tracBinaryBuffer = cpu.r4
        hb_tracBinaryBufferSz = cpu.r5
        hb_tracBinaryMaxOffset = hb_tracBinaryBuffer + hb_tracBinaryBufferSz
        # see NODE_OFFSET in memorymap.H
        per_node = 0x400000000000   #64TB
        per_chip = 0x40000000000    #4TB
        hb_hrmor = cpu.hrmor
        node_num = hb_hrmor//per_node
        chip_num = hb_hrmor//per_chip
        mem_object = None
        #print ">> hrmor=%X" % hb_hrmor
        #print ">> hb_tracBinaryBuffer=%X" % hb_tracBinaryBuffer
        #print ">> hb_tracBinaryBufferSz=%X" % hb_tracBinaryBufferSz
        #print ">> hb_tracBinaryMaxOffset=0x%X" % hb_tracBinaryMaxOffset
        #print ">> node_num=%d" % node_num
        #print ">> chip_num=%d" % chip_num

        # Find the entry in the memory map that includes our
        #  base memory region. Can't assume object is "ram"
        low_priority = 10
        mem_map_entries = (conf.system_cmp0.phys_mem).map
        for entry in mem_map_entries:
            # 0=base, 1=name, 4=size 5=mirrored target, 6=priority
            #print ">> %d:%s" % (entry[0], entry[1])
            #check if base == hrmor, or if memory space encompasses the
            #entire base memory which is:  hrmor + 0x4000000 (64 MB)
            if ((entry[0] == hb_hrmor) or
                ((entry[0] < hb_hrmor) and
                 (entry[0] + entry[4] >= hb_hrmor + 0x4000000))):
                obj = entry[1]
                size = entry[4]
                target = entry[5]
                priority = entry[6]
                # Check if there is a target that needs to be investigated that
                # points to another object or map
                if (target != None) and (priority < low_priority):
                    #print "Continuous trace target = %s" % (target)
                    smm_map_entries = target.map
                    for smm_entry in smm_map_entries:
                        if ((smm_entry[0] == (node_num*per_node)) or
                            (entry[0] == hb_hrmor)):
                            mem_object = simics.SIM_object_name(smm_entry[1])
                            #print "SMM: Found entry %s for hrmor %x" % (mem_object, hb_hrmor)
                            low_priority = priority
                            #break
                    break
                # If we find an object later in the list that covers the
                # correct area then use it.
                else:
                    if hb_tracBinaryMaxOffset < size:
                        mem_object = simics.SIM_object_name(obj)
                        #print "Found entry %s size=0x%x" % (mem_object, size)
                        low_priority = priority
                        #break

        if mem_object == None:
            print("Could not find entry for hrmor %d" % (hb_hrmor))
            SIM_break_simulation( "No memory for trace" )
            return

        # Figure out if we are running out of the cache or mainstore
        # Add the HRMOR if we're running from memory
        if 'cache' not in mem_object and 'l3' not in mem_object:
            #print "Did not find cache"
            hb_tracBinaryBuffer = (hb_tracBinaryBuffer +
                                   hb_hrmor -
                                    (per_node*node_num))

        tracbin = ["hbTracBINARY","hbTracBINARY1","hbTracBINARY2","hbTracBINARY3"]
        tracmerg = ["hbTracMERG","hbTracMERG1","hbTracMERG2","hbTracMERG3"]

        # Save the tracBinary buffer to a file named tracBINARY in current dir
        # and run fsp-trace on tracBINARY file (implied), append output to
        # tracMERG.  Once we extract the trace buffer, we need to reset
        # mailbox scratch 1 (to 0) so that the trace daemon knows it can
        # continue.
        # Newer simics versions (5.0.210) and newer only allow overwriting
        # an image by specifying that as a command line parameter
        if(conf.sim.version >= 5239):
            cmd1 = "(%s)->image.save %s 0x%x %d -overwrite"%(
                    mem_object,\
                    tracbin[node_num],\
                    hb_tracBinaryBuffer,\
                    hb_tracBinaryBufferSz)
        else:
            cmd1 = "(%s)->image.save %s 0x%x %d"%(
                    mem_object,\
                    tracbin[node_num],\
                    hb_tracBinaryBuffer,\
                    hb_tracBinaryBufferSz)

        cmd2 = "(shell \"(fsp-trace ./%s -s %s/hbotStringFile | sort -s -k 1,1 >> %s 2>/dev/null) || true\")"\
                %(tracbin[node_num],\
                os.environ['HB_TOOLPATH'],\
                tracmerg[node_num])

        cmd3 = ""
        if (simenv.hb_mode == 0): #new mode (Axone + beyond)
            cmd3 = "(get-master-procs)[0].reset-fsimbox-reg index=0x104"
        else:
            #old mode (Cumulus + prior)
            cmd3 = "(get-master-proc %d).proc_fsi2host_mbox->regs[95][1] = 0"%(node_num)
        saveCommand = "%s; %s; %s"%(cmd1,cmd2,cmd3)

        try:
            if (simenv.fileSystemOk == 1):
                SIM_run_alone(run_command, saveCommand )
            else:
                print("WARNING: Unable to write Hostboot traces, maybe check your credentials, but continuing")
        except Exception as e:
            print("WARNING: Problem running saveCommand for Hostboot traces, maybe check your credentials, but continuing... {}".format(e))

        #file = open("hb_trace_debug.dat", "a")
        #file.write("%s\n" % (saveCommand))
        #file.close()
    if arg == 7056:   # MAGIC_GCOV_DUMP_NOW
        print('Gcov dumping chain from 0x%x' % (cpu.r3,))
        SIM_run_alone(run_command, 'hb-GcovModuleUnload "address=%d"' % (cpu.r3,))

    if arg == 7057:   # MAGIC_SAVE_ATTR_VALUE
        args = (cpu.r4, cpu.r5, cpu.r6, cpu.r7, cpu.r8)
        print('Saving attribute data from %s' % (args,))

        huid, attr_id, attr_size, byte_offset, byte_data = args

        hb_attr_dump_file.write(struct.pack('>IIIIQ',
                                            huid,
                                            attr_id,
                                            attr_size,
                                            byte_offset,
                                            byte_data))

    if arg == 7058:   # MAGIC_CHECK_FEATURE
        feature = cpu.r4
        value = 0
        if feature == 1:  #MAGIC_FEATURE__MULTIPROC
            value = 1 if simenv.hb_multiproc == 1 else 0
            if value != 0:
                print("HB> MAGIC_FEATURE__MULTIPROC = %d" % (value))
        elif feature == 2:  #MAGIC_FEATURE__IGNORESMPFAIL
            value = 1 if simenv.hb_ignoresmpfail == 1 else 0
            if value != 0:
                print("HB> MAGIC_FEATURE__IGNORESMPFAIL = %d" % (value))
        elif feature == 3:  #MAGIC_FEATURE__IGNORETODFAIL
            value = 1 if simenv.hb_ignoretodfail == 1 else 0
            if value != 0:
                print("HB> MAGIC_FEATURE__IGNORETODFAIL = %d" % (value))
        elif feature == 5:  #MAGIC_FEATURE__SKIPOCC
            value = 1 if simenv.hb_skipocc  == 1 else 0
            if value != 0:
                print("HB> MAGIC_FEATURE__SKIPOCC = %d" % (value))
        else:
            print("MAGIC_CHECK_FEATURE> Unknown feature %d requested for" % (feature))
        cpu.r3 = value


# Continuous trace: Clear these files.
rc = os.system( "rm -f hbTracMERG" )
rc = os.system( "rm -f hbTracMERG1" )
rc = os.system( "rm -f hbTracMERG2" )
rc = os.system( "rm -f hbTracMERG3" )
rc = os.system( "rm -f hbTracBINARY" )
rc = os.system( "rm -f hbTracBINARY1" )
rc = os.system( "rm -f hbTracBINARY2" )
rc = os.system( "rm -f hbTracBINARY3" )

# remove legacy files so as not to confuse
rc = os.system( "rm -f tracMERG" )
rc = os.system( "rm -f tracBINARY" )

# SBE traces: Clear these files.
rc = os.system( "rm -f sbetrace.hb.txt" )

# Register the magic instruction hap handler (a callback).
SIM_hap_add_callback_range( "Core_Magic_Instruction", magic_instruction_callback, None, 7000, 7999 )

# Run the registration automatically whenever this script is loaded.
register_hb_debug_framework_tools()
