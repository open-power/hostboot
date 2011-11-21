#!/usr/bin/python
#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/debug/simics-debug-framework.py $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2011
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
    imgPath = "./";             # Image dir path override.
    result = "";                # Result string for Usage-mode.
    outputFile = None;          # Output file for results in addition to STDOUT

    def __init__(self, tool = "Printk", toolOptions = "",
                       outputToString = None, usage = None,
                       imgPath = "./",outputFile = None):
        # Determine sub-process arguments.
        process_args = ["./simics-debug-framework.pl"];
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
        self.imgPath = imgPath;
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

        data = "".join(map(chr, conf.phys_mem.memory[[addr , addr+size-1]]))
        self.sendMsg("data-response", data)

    # Write data to memory.
    #    This message has data of the format "0dADDR,0dSIZE,hDATA".
    def write_data(self,data):
        pattern = re.compile("([0-9]+),([0-9]+),([0-9A-Fa-f]+)")
        match = pattern.search(data)

        addr = int(match.group(1))
        size = int(match.group(2))
        data = map(ord, match.group(3).decode("hex"));

        conf.phys_mem.memory[[addr, addr+size-1]] = data;

    # Clock forward the model.
    #    This message had data of the format "0dCYCLES".
    def execute_instrs(self,data):
        pattern = re.compile("([0-9]+)")
        match = pattern.search(data)

        cycles = int(match.group(1))

        if (not SIM_simics_is_running()):
            SIM_continue(cycles)

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

# @fn run_hb_debug_framework
# @brief Wrapper function to execute a tool module.
#
# @param tool - Tool module to execute.
# @param toolOpts - String containing tool options.
# @param usage - Usage mode or Execute mode.
# @param imgPath - Image path override.
def run_hb_debug_framework(tool = "Printk", toolOpts = "",
                           outputToString = None, usage = None,
                           imgPath = "./", outputFile = None):
    # Create debug sub-process.
    fp = DebugFrameworkProcess(tool,toolOpts,outputToString,
                               usage,imgPath,outputFile)

    # Read / handle messages until there are no more.
    msg = fp.recvMsg()
    while msg[0] != "":
        operations = { "display" :  DebugFrameworkProcess.display,
            "read-data" :           DebugFrameworkProcess.read_data,
            "write-data" :          DebugFrameworkProcess.write_data,
            "execute-instrs" :      DebugFrameworkProcess.execute_instrs,
            "ready-for-instr" :     DebugFrameworkProcess.ready_for_instr,
            "get-tool" :            DebugFrameworkProcess.get_tool,
            "get-tool-options" :    DebugFrameworkProcess.get_tool_options,
            "get-img-path" :        DebugFrameworkProcess.get_img_path,
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
    files = os.listdir("./Hostboot")

    # Filter out any prefixed with '_' (utility module) or a '.' (hidden file).
    pattern = re.compile("[^\._]");
    files = [f for f in files if pattern.match(f)]

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

# Run the registration automatically whenever this script is loaded.
register_hb_debug_framework_tools()

