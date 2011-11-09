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
    usage = None;               # mode - Usage output instead of Execution.
    imgPath = "./";             # Image dir path override.
    result = "";                # Result string for Usage-mode.

    def __init__(self, tool = "Printk", toolOptions = "",
                       usage = None, imgPath = "./"):
        # Determine sub-process arguments.
        process_args = ["./simics-debug-framework.pl"];
        if (usage): # Pass --usage if Usage mode selected.
            process_args = process_args + [ "--usage" ];

        # Spawn sub-process
        self.process = subprocess.Popen(process_args,
                               stdin=subprocess.PIPE, stdout=subprocess.PIPE)
        # Update instance variables.
        self.tool = tool;
        self.toolOptions = toolOptions;
        self.usage = usage;
        self.imgPath = imgPath;

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
        if (self.usage):
            self.result += data
        else:
            print data,

    # Read data from memory.
    #    This message has data of the format "0xADDRESS,0xSIZE".
    def read_data(self,data):
        pattern = re.compile("([0-9]+),([0-9]+)")
        match = pattern.search(data);

        addr = int(match.group(1))
        size = int(match.group(2))

        data = "".join(map(chr, conf.phys_mem.memory[[addr , addr+size-1]]))
        self.sendMsg("data-response", data)

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
                           usage = None, imgPath = "./"):
    # Create debug sub-process.
    fp = DebugFrameworkProcess(tool,toolOpts,usage,imgPath)

    # Read / handle messages until there are no more.
    msg = fp.recvMsg()
    while msg[0] != "":
        operations = { "display" :  DebugFrameworkProcess.display,
            "read-data" :           DebugFrameworkProcess.read_data,
            "get-tool" :            DebugFrameworkProcess.get_tool,
            "get-tool-options" :    DebugFrameworkProcess.get_tool_options,
            "get-img-path" :        DebugFrameworkProcess.get_img_path,
            "exit" :                DebugFrameworkProcess.endProcess,
        }
        operations[msg[0]](fp,msg[1])
        msg = fp.recvMsg()

    # If in Usage mode, return result string.
    if (usage):
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
                            run_hb_debug_framework(toolname, options))(tool),
                    args = [arg(str_t, "options", "?", "")],
                    alias = "hb-debug-" + tool,
                    type = ["hostboot-commands"],
                    short = "Runs the debug framework for tool " + tool,
                    doc = usage)
        print "Hostboot Debug Framework: Registered tool:", "hb-" + tool

# Run the registration automatically whenever this script is loaded.
register_hb_debug_framework_tools()

