#!/usr/bin/python
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/trace/tracelite/weave.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2022
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

"""
@file weave.py

@brief This weave script decodes tracelite output containing hex hash values
       into a full human-readable trace output.
       trace_lite entries are found in console1.log output after enabling bios
       attribute, hb_debug_console.
       The hbotStringFile contains the translation between hash data and
       trace strings and is found in hbRepo/img/ directory or as a lid on eBMC
"""

import sys
import shlex

"""
Global debug file for debug traces
default = no debug file
"""
G_debugFile = ""
G_debugFd = None

""" Dictionary to hold parsed strings from string file
hbotTable = { hashString : { 'format': formatString = formatted trace string
                             'source': sourceString = file source },
               ...
             }
"""
hbotTable = {}

""" Global lid location of hbotStringFile """
HBOT_STRING_LID_FILE = "81e00685.lid"

""" Trace version of binary file/data in decimal
"""
TRACE_VERSION2 = 2

""" Log debug traces to G_debugFile (if defined)
@param[in] dbgStr: string to write to G_debugFile
"""
def DBG_TRACE(dbgStr):
    if (G_debugFile):
        x = dbgStr.strip()
        G_debugFd.write(x+"\n")


""" Counts the number of %arguments in format string
@param[in] formatString: format string from a stringFile line
@returns: Count of how many arguments in the format string
"""
def countargs(formatString):
    doublePer = formatString.count("%%")
    singlePer = formatString.count("%");
    # remove the double %% as they just mean single %
    singlePer = singlePer - 2*doublePer
    return singlePer


""" Parses a line of the hbotStringFile and
    adds it to the global hbotTable hash table

@param[in] line: single line from stringFile
@returns: Return 0 on success, -1 on failure
"""
def parse_sf_entry_v2 (line):
    # Line is formatted as follows with '||' separator
    # Hash value || format string || source filename
    STRINGFILE_LINE_FORMAT = 3

    splitStr = line.split('||')

    # format string may contain || so check for at least 3 sections
    if len(splitStr) >= STRINGFILE_LINE_FORMAT:
        formatStr = splitStr[1]
        # add back any middle ||, if present
        for i in range(2,len(splitStr)-1):
            formatStr = formatStr + "||" + splitStr[i]

        #If another line has the same Hash Value, it will be overwritten with the new
        #format string and source filename
        hbotTable[splitStr[0]] = {'format': formatStr,
                                  'source': splitStr[len(splitStr)-1]}

        return 0
    else:
        sys.stderr.write("Error: Line was formatted incorrectly - Skipping "+line)
        return -1


""" Parses the first line of hbotStringFile to get version number

@param[in] line: string of the line to parse
@returns: and int value of the version for FSP trace or -1 if error
"""
def parse_sf_magic_cookie(line):
    # Line is formatted as follows with '|||' separator
    # #FSP_TRACE_v# ||| timestamp ||| build id
    eyecatch = '#FSP_TRACE_v'
    version = -1

    splitStr = line.split('|||')

    index = splitStr[0].find(eyecatch)
    if index != -1:
        version = int(splitStr[0][index+len(eyecatch)])

    return version

""" Reads in the hbotStringFile to check version and parse entries

@param[in] stringFileName: string of string file name
@returns: Return 0 on success, -1 on failure
"""
def read_stringfile(stringFileName):
    retVal = 0
    with open(stringFileName) as stringFile:
        for x, line in enumerate(stringFile):
            if line.rstrip() == '': #Skip empty lines
                continue

            if x == 0:
                #Check that the stringfile is the correct version
                traceVersion = parse_sf_magic_cookie(line.rstrip())
                if traceVersion != TRACE_VERSION2:
                    sys.stderr.write('Error: Unsupported StringFile Version')
                    sys.stderr.write("Found version "+str(traceVersion))
                    retVal = -1
                    break
            else:
                parse_sf_entry_v2(line.rstrip())
    return retVal

""" Lookup format string in hbotStringFile table

@param[in] hexHashCode: hash code string in hex
@returns: Format string associated with the hash code
"""
def lookupFormatString(hexHashCode):
    x = ""
    hashCode = str(int(hexHashCode,16))
    if hashCode in hbotTable:
        x = hbotTable[hashCode].get('format')
    return x


""" Takes format string (fstring) and fills in the parameters

@param[in] fstring: format string from hbotStringFile
@param[in] paramList: list of string parameters from trace_lite trace line
@return fstring with filled-in parameters
"""
def fillInParms(fstring, paramList):
    # index into fstring
    i = 0

    # number format
    # example: %016llx = 016 number format
    numFormat = ""

    # add 0x at the beginning of hex number (for %#llx format)
    add0x = False

    # python format string to convert parameter
    # example: '{:08X}' for %08X, '{:s}' for %s
    pythonFormat = ""

    # trace_lite only supports numbers or string traces
    # this indicates the current trace parameter is a number
    isNum = True

    # default to lowercase hex number
    hexOrDec = 'x'

    # index into fstring for current parameter start (% starts)
    parmStartIndex = 0

    # index into paramList
    parmListIndex = 0

    # left '<' or right '>' aligned
    # default right aligned
    aligned = '>'

    while i < len(fstring):

        # search for '%'
        if fstring[i] != '%':
            i += 1
            continue

        # skip %
        i += 1

        #check for '%%' and skip
        if fstring[i] == '%':
            i += 1
            continue

        # mark start of replacement % parameter
        parmIndexStart = i - 1

        # now at next format
        # look for d, X, x, l, L, f, c, ., #, u, z
        while i < len(fstring):
            if fstring[i] == 'l':
                i += 1
                continue
            if fstring[i] == 'z':
                i += 1
                continue
            if fstring[i] == '-':
                aligned = '<'
                i += 1
                continue
            if fstring[i] == '#':
                if (i+1 < len(fstring)) and (fstring[i+1] != '0'):
                    add0x = True
                else:
                    i += 1 # skip 0
                    add0x = False
                i += 1
                continue
            if fstring[i] == '.':
                numFormat = "0"
                i += 1
                continue
            if fstring[i].isdigit():
                numFormat += fstring[i]
                i += 1
                continue
            if fstring[i] == 'X':
                # uppercase hex
                hexOrDec = 'X'
                i += 1
                break
            if fstring[i] == 'x':
                # lowercase hex
                hexOrDec = 'x'
                i += 1
                break
            if fstring[i] == 'd' or fstring[i] == 'u':
                # decimal
                hexOrDec = 'd'
                i += 1
                break
            if fstring[i] == 's':
                pythonFormat = "{:s}"
                isNum = False
                i += 1
                break
            if fstring[i] == 'f':  # trace_lite float is long unsigned int
                if (not numFormat):
                    numFormat = '16'
                hexOrDec = 'x'
                i += 1
                break
            if fstring[i] == 'c': # trace_lite char is unsigned int
                isNum = False
                pythonFormat = "{:c}"
                i += 1
                break

            sys.stderr.write("ERROR: Unhandled format character: " + fstring[i]+"\n")
            return fstring, -1

        parmStr = ""
        if (isNum):
            # construct pythonFormat for number parameter
            if (add0x):
                pythonFormat = '0x{:'
            else:
                pythonFormat = '{:'

            if hexOrDec == 'd' and numFormat:
                pythonFormat += ' ' + aligned + numFormat
            else:
                pythonFormat += numFormat

            pythonFormat += hexOrDec+'}'

            DBG_TRACE(str(parmListIndex)+") "+fstring[parmIndexStart:i]+"-> "+ pythonFormat)
            DBG_TRACE(fstring)
            DBG_TRACE(", ".join([str(elem) for elem in paramList]))
            parmStr = str.format(pythonFormat, int(paramList[parmListIndex],16))
        else:
            if paramList[parmListIndex][0] == '"' and paramList[parmListIndex][-1] == '"':
                if numFormat:
                    parmStr = '{message: {align}{width}}'.format(message=paramList[parmListIndex][1:-1], align=aligned, width=numFormat)
                else:
                    parmStr = paramList[parmListIndex][1:-1]
            else:
                # assuming it is a character
                parmStr = str.format(pythonFormat, int(paramList[parmListIndex],16))
        parmListIndex += 1

        # remove current parameter's formatting from fstring and replace with parsed parameter
        if parmIndexStart != 0:
            fstring = fstring[0:parmIndexStart]+parmStr+fstring[i:]
        else:
            fstring = parmStr + fstring[i:]

        # update current index just past filled in parameter
        i = parmIndexStart + len(parmStr)
        pythonFormat = ""
        numFormat = ""
        add0x = False
        isNum = True

    # change any double %% into single %
    fstring = fstring.replace('%%','%')
    return fstring, 0

""" Is the string a hex number?
@param[in] s : string
@return True if hex number, else False
"""
def ishex(s):
    try:
        hexNum = int(s,16)
        return True
    except ValueError:
        return False

""" Parse the trace_lite line into human-readable form
Note: hbotTable should be populated by read_stringfile() before this is called

@param[in] line: single line from console1 output (a trace_lite line)
@returns: Return 0 on success, num > 0 on failure
"""
def parse_tracelite_line(line):
    # line is formatted as follows with '|' separator
    # Example:
    # Initial line:        1599.92726|1329 SBEIO|trace_lite 15FEB01A 0000000000000001 0000000000000002 0000000000050002 00040000775A0000 0000000000002000 0000000000000011 "Read-Only"
    # formatStr: 369012762||memRegion: - %lld/%lld: tgt=0x%.8llX: start_addr=0x%.16llX, size=0x%.8llX, flags=0x%.2llX (%s)||sbe_memRegionMgr.C
    # After fillInParms(): 1599.92700|1329 SBEIO|memRegion: - 1/4: tgt=0x00050000: start_addr=0x0004000077560000, size=0x00002000, flags=0x11 (Read-Only)
    timestamp = None
    process = None
    trace_lite_entry = None

    fields = line.split('|')
    if (len(fields) != 3):
        # try to split just up to trace_lite
        if (len(fields) > 3):
            timestamp = fields[0]
            process = fields[1]
            try:
                trace_lite_entry_index = line.index("|trace_lite ")
                trace_lite_entry = line[trace_lite_entry_index+len("|trace_lite "):]
            except ValueError:
                print(line)
                sys.stderr.write("ERROR: no trace_lite found in tracelite line\n")
                sys.stderr.write(line+"\n")
        else:
            print(line)
            sys.stderr.write("ERROR: Invalid trace_lite line. Found "+str(len(fields))+" trace_lite sections, expected 3\n")
            sys.stderr.write(line+"\n")
    else:
        timestamp, process, trace_lite_entry = line.split('|')

    trace_lite_entry = trace_lite_entry.replace("trace_lite ","")

    # can't just split here based on space since string parameters could contain spaces
    parameterList = []
    tokenizer = shlex.shlex(trace_lite_entry)
    try:
        for token in tokenizer:
            parameterList.append(token)
    except ValueError:
        error = tokenizer.token.splitlines()[0]
        sys.stderr.write("ERROR: " + tokenizer.error_leader() + error)
        sys.stderr.write("Unable to split into parameters:\n")
        sys.stderr.write(trace_lite_entry)
        return 2

    # check this or pop on empty list will fail
    if len(parameterList) == 0:
        sys.stderr.write("ERROR: no hbotHash was found on line\n")
        sys.stderr.write(line)
        sys.stderr.write(trace_lite_entry)
        return 3

    hbotHash = parameterList.pop(0)
    if ishex(hbotHash):
        formatStr = lookupFormatString(hbotHash)
    else:
        sys.stderr.write("ERROR: Non-hash found: "+hbotHash+"\n")
        sys.stderr.write("Full line: "+line)
        sys.stderr.write(", ".join([str(elem) for elem in parameterList]))
        return 4

    if countargs(formatStr) != len(parameterList) :
        sys.stderr.write("ERROR: Found "+str(len(parameterList))+", expected "+str(countargs(formatStr)))
        sys.stderr.write(formatStr)
        sys.stderr.write(trace_lite_entry)
        sys.stderr.write(", ".join([str(elem) for elem in parameterList]))
        sys.stderr.write(line)
        return 5
    else:
        # normal path
        formatStr, retCode = fillInParms(formatStr, parameterList)
        if (retCode != 0):
            print(timestamp+"|"+process+"|"+formatStr+(", ".join([str(elem) for elem in parameterList])))
            sys.stderr.write("ERROR: Unable to fill in parameters for "+formatStr+"\n")
            sys.stderr.write(", ".join([str(elem) for elem in parameterList])+"\n")
            return 6

    print(timestamp+"|"+process+"|"+formatStr)
    return 0



""" Reads from stdin and for each line read
    it translates and outputs a line in human-readable form
    Stops when reaches EOF or interrupted by user input
@param[in] exitOnError True = exit if parsing error encountered
                       False = handle error and continue parsing
"""
def inputloop(exitOnError):
    inputLine = 0
    try:
        buff = ''
        while True:
            ch = sys.stdin.read(1)
            if len(ch) == 0: # end of file
                break
            if ch == '\r' or ch == '\n':
                # check if buffer line has 'trace_lite' in it
                if "trace_lite" in buff:
                    rc = parse_tracelite_line(buff)
                    if (rc != 0 and exitOnError):
                        sys.stderr.write("Exitting inputloop() on line "+str(inputLine)+", rc = "+str(rc))
                        break
                else:
                    # not a trace_lite line, just print it
                    if (buff):
                        print(buff)
                buff = ''
                # keep track of what line you are parsing
                if ch == '\n':
                    inputLine += 1
            else:
                buff += ch

    except KeyboardInterrupt:
       sys.stdout.flush()


def print_full_usage():
    print("\n==================================================================")
    print("usage: cat traceFile | weave.py [-s hbotStringFile] [-d debugFile]\n")
    print("If debugFile is specified, the parsing will stop on first parsing error\n")
    print("On eBMC system:\n")
    print("  tail -F /var/log/obmc-console1.log | weave.py\n")
    print("  Note: hbotStringFile is in lid, currently 81e00685.lid, on eBMC system")
    print("        Also need to enable trace_lite tracing via bios attribute hb_debug_console\n")
    print("Not on eBMC system:")
    print("  -s hbotStringFile is a required parameter\n")
    print("==================================================================\n")


"""
Main function that takes in hbotStringFile and starts translating trace-lite traces
"""
if __name__ == "__main__":
    import argparse
    exitOnError = False


    parser = argparse.ArgumentParser(description='Tool to weave trace_lite trace entries into human-readable text',
                                     epilog='On eBMC system: Enable trace_lite via hb_debug_console bios attribute, then `tail -F /var/log/obmc-console1.log | weave.py`')
    parser.add_argument('-s', dest='hbotStringFile', metavar='hbotStringFile', type=str, required=False, help='eBMC will use 81e00685.lid by default, otherwise this must be specified')
    parser.add_argument('-d', dest='debugFile', metavar='debugFile',type=str, required=False, help='Logs debug traces to this file and parsing will stop on error')
    args = parser.parse_args()

    if (args.hbotStringFile):
        read_stringfile(args.hbotStringFile)
    else:
        try:
          from udparsers.helpers.miscUtils import getLid

          # Get the LID file for the HB string file
          stringFile = getLid(HBOT_STRING_LID_FILE)
          if stringFile == "":
              sys.stderr.write("ERROR: unable to locate "+HBOT_STRING_LID_FILE+"\n");
              sys.exit(1)
          else:
              read_stringfile(stringFile)
        except ImportError:
            sys.stderr.write("ERROR: no getLid module, unable to locate hbotStringFile\n")
            print_full_usage()
            sys.exit(2)


    if (args.debugFile):
        G_debugFile = args.debugFile
        G_debugFd = open(G_debugFile, "w")
        exitOnError = True

    DBG_TRACE("Beginning inputloop...\n")
    inputloop(exitOnError)
    DBG_TRACE("inputloop done\n")
    sys.exit(0)
