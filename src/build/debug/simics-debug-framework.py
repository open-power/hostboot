#!/usr/bin/python
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/simics-debug-framework.py $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2011,2013
#
# p1
#
# Object Code Only (OCO) source materials
# Licensed Internal Code Source Materials
# IBM HostBoot Licensed Internal Code
#
# The source code for this program is not published or otherwise
# divested of its trade secrets, irrespective of what has been
# deposited with the U.S. Copyright Office.
#
# Origin: 30
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


import os
import subprocess
import re
import random

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
        return ("[ \"" + self.msgtype + "\", \"" +
                self.msg.encode("hex") + "\" ]\n")

    def loads(self,string):
        pattern = re.compile("\[ \"([^\"]+)\", \"([0-9a-f]*)\" ]")
        match = pattern.search(string)
        if  match is None:
            print   "error: empty message >%s< received from perl"%(string)
            print   "       Check for print's in your perl script!!!"
        else:
            self.msgtype = match.group(1)
            self.msg = match.group(2).decode("hex")

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
        self.process.stdin.write(msg.dumps())

    # End sub-process by closing its pipe.
    def endProcess(self):
        self.process.stdin.close()

    # Display string (or save to result in Usage mode).
    def display(self,data):
        if (self.outputToString):
            self.result += data
        else:
            print data,
            if self.outputFile:
                print >>self.outputFile,data,

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
                print "simics ERROR running %s: %d "%( syscmd, rc )

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
            print "simics ERROR running %s: %d "%( syscmd, result )

    # Read HRMOR from processors.
    #    This message has no input data
    def get_hrmor(self,data):
        hrmor = getHRMOR()
        self.sendMsg("data-response", "%d"%(hrmor) )


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
        print "Hostboot Debug Framework: Registered tool:", "hb-" + tool


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
    runStr  =  "($hb_cpu).read-reg HRMOR"
    ( result, out )  =   quiet_run_command( runStr, output_modes.regular )
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

# MAGIC_INSTRUCTION hap handler
# arg contains the integer parameter n passed to MAGIC_INSTRUCTION(n)
# See src/include/arch/ppc.H for the definitions of the magic args.
# Hostboot magic args should range 7000..7999.
def magic_instruction_callback(user_arg, cpu, arg):
    if arg == 7008:
        cpu.r3 = random.randint(1, 0xffffffffffffffffL)

    if arg == 7006:   # MAGIC_SHUTDOWN
        # KernelMisc::shutdown()
        print "KernelMisc::shutdown() called."
        # Could break/stop/pause the simics run, but presently
        # shutdown() is called four times. --Monte Jan 2012
        # SIM_break_simulation( "Shutdown. Simulation stopped." )

    if arg == 7007:   # MAGIC_BREAK
        # Stop the simulation, much like a hard-coded breakpoint
        SIM_break_simulation( "Simulation stopped. (hap 7007)"  )

    if arg == 7009:   # MAGIC_MEMORYLEAK_FUNCTION
        magic_memoryleak_function(cpu)

    if arg == 7011: #MAGIC_SIMICS_CHECK
        cpu.r3 = 1
        print "TimeManager::cv_isSimicsRunning = true"

    if arg == 7055:   # MAGIC_CONTINUOUS_TRACE
        hb_tracBinaryBuffer = cpu.r4
        hb_tracBinaryBufferSz = cpu.r5
        # Figure out if we are running out of the cache or mainstore
        runStr = "(system_cmp0.phys_mem)->map[0][1]"
        ( result, out )  =   quiet_run_command( runStr, output_modes.regular )
        # Add the HRMOR if we're running from memory
        if 'cache' not in result:
            hb_tracBinaryBuffer = hb_tracBinaryBuffer + getHRMOR()
        # Save the tracBinary buffer to a file named tracBINARY in current dir
        # and run fsp-trace on tracBINARY file (implied), append output to
        # tracMERG.  Once we extract the trace buffer, we need to reset
        # mailbox scratch 1 (to 0) so that the trace daemon knows it can
        # continue.
        saveCommand = "(system_cmp0.phys_mem)->map[0][1]->image.save tracBINARY 0x%x %d ; (shell \"(fsp-trace ./ -s %s/hbotStringFile >> tracMERG 2>/dev/null) || true\"); ($hb_masterproc).proc_fsi2host_mbox->regs[95][1] = 0"%(hb_tracBinaryBuffer,hb_tracBinaryBufferSz,os.environ['HB_TOOLPATH'])
        SIM_run_alone(run_command, saveCommand )

# Continuous trace: Clear these files.
rc = os.system( "rm -f tracMERG" )
rc = os.system( "rm -f tracBINARY" )

# Register the magic instruction hap handler (a callback).
SIM_hap_add_callback_range( "Core_Magic_Instruction", magic_instruction_callback, None, 7000, 7999 )


# Run the registration automatically whenever this script is loaded.
register_hb_debug_framework_tools()

