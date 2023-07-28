#!/usr/bin/python
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/ebmc/hostfw_trace.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2021,2023
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
@file hostfw_trace.py

@brief This file decodes version 1 and 2 of trace entries.
       This file can be used as a stand alone file or using API
       get_binary_trace_data_as_string as plugin.
"""

import struct
import sys, os
import argparse
from collections import namedtuple


""" Named Tuple Definitions
"""
""" Version 1 Header Data Structure:
        version      - version of the buffer data
        headerLength - size of the header data
        timeFlag     - meaning of timestamp entry field
        endianFlag   - flag for big ('B') or little ('L') endian
        compName     - the component name
        binaryDataLength - size of buffer data, including header
        wrapCount    - how often the buffer wrapped
        offsetAfterLastTraceEntrySize - offset of the byte past the last entry's size
        # The following are not part of the data structure but are helpful to cache
        offsetToFirstTraceEntry - offset to the first entry
        endianPythonChar - Python character that represents big ('>') or little ('<') endian
"""
HeaderDataV1 = namedtuple('HeaderDataV1', ['version', 'headerLength', 'timeFlag',
                          'endianFlag', 'compName', 'binaryDataLength', 'wrapCount',
                          'offsetAfterLastTraceEntrySize', 'offsetToFirstTraceEntry',
                          'endianPythonChar' ])

""" Version 1 Trace Entry Structure:
        seconds    - timestamp upper part
        useconds   - timestamp lower part
        pid        - process/thread id
        entrySize  - size of trace entry
        entryType  - type of entry: xTRACE xDUMP, (un)packed
        hash       - a value for the (format) string
        lineNumber - source file line number of trace call
        argsOffset - offset to trace arguments
"""
TraceEntryV1 = namedtuple('TraceEntryV1', ['seconds', 'useconds', 'pid', 'entrySize', 'entryType',
                           'hash', 'lineNumber', 'argsOffset'])

""" Version 2 Trace Entry Structure:
        compStr      - the component name
        TraceEntryV1 - Version 1 Trace Entry data
"""
TraceEntryV2 = namedtuple('TraceEntryV2', ['compStr', 'TraceEntryV1'])

""" Dictionary to hold parsed strings from string file
hTable = { hashString : { 'format': formatString ,
                          'source': sourceString },
           ...
         }
"""
hTable = {}


""" The name of the string file that hTable is currently populated with.
    Used to determine if the hTable is populated with the current string file
    and if not, then need to process the string file, gather its hash string
    data, save it to the hTable and update this variable to the string file's name.
"""
hTableStringFileName = ""


""" Dictionary to hold a list of the hashed parsed strings from a string file.
    Used to hold the hash strings of the string file HB and/or the string
    file SBE.  Could hold others in the future.
hTableList = { fileName:  hashString : { 'format': formatString ,
                                         'source': sourceString },
                          ...
               ...
             }
"""
hTableList = { }


"""@brief Trace version of binary file/data in decimal
"""
TRACE_VERSION1 = 1
TRACE_VERSION2 = 2

"""@brief Maximum size of component name
"""
TRACE_MAX_COMP_NAME_SIZE = 16

"""@brief Maximum number of args in a trace
"""
TRACE_MAX_ARGS = 8

"""@brief Flags for options passed in
"""
TRACE_FILENAME = 32
flags = 0

DEBUG_TRACE_HEADER = 0
DEBUG_TRACE_DATA = 0
DEBUG_TRACE_ENTRY = 0

"""@brief Trace identification flag
"""
TRACE_COMP_TRACE = 0x434F # Identifies trace as a component trace (printf): 0x434F = "CO"
TRACE_FIELDBIN = 0x4644 # a binary trace of type field (non-debug): x4644 = "FD"
TRACE_FIELDTRACE = 0x4654 # Field Trace - "FT"

"""@brief A global list to consolidate errors encountered while parsing trace entries
"""
parse_errors = []

""" Takes the given error and adds it to the gathered list of errors
@param[in] error: A printable string of error messages
"""
def capture_error(error):
    parse_errors.append(error)

""" Takes the errors, that were encountered, that are contained within the
    parse_errors list and produces a printable string
@returns: a string: Encountered errors coalesced into a single string
"""
def get_captured_errors_as_string():
    return '\n'.join(parse_errors)

"""@brief A global list to consolidate warnings encountered while parsing trace entries
"""
parse_warnings = []

""" Takes the given warning and adds it to the gathered list of warnings
@param[in] error: A printable string of warnings messages
"""
def capture_warning(warning):
    parse_warnings.append(warning)

"""@brief String to be displayed when buffer is empty
"""
BUFFER_EMPTY_STRING = "Buffer is empty."


""" Takes the warnings, that were encountered, that are contained within the
    parse_warnings list and produces a printable string
@returns: a string: Encountered warnings coalesced into a single string
"""
def get_captured_warnings_as_string():
    return '\n'.join(parse_warnings)


""" Reset the global variables.  These global variables are not being cleared
    when being called which can lead to errors and warnings being propagated to a
    buffer, being decoded, that did not have issues.  This can lead to confusion.
    Not resetting the hash table, hTable, that holds the strings file.  In this case
    it is advantageous to not reload the data as it is very time consuming and
    the data is constant.
"""
def reset_global_vars():
    global flags
    flags = 0
    parse_errors.clear()
    parse_warnings.clear()


""" Creates string of the header for trace output

@returns: a string of the formatted header
"""
def trace_output_get_format():
    delim = '-------------------------------------------------------------------------------\n'
    dataFormat = f"{'Sec':^9}{'Usec':^10}{'PID':^5}{' Comp':<15}" + 'Line Entry   Data'

    if flags & TRACE_FILENAME:
        dataFormat += '   Filename'

    header = delim + 'TRACEBUFFER: tracBINARY\n' + delim + dataFormat + '\n' + delim

    return header


""" Parses trace arguments and binary data for arguments

@param[in] bData: bytes object of the binary data
@param[in] fstring: string of format string for current trace
@param[in] fsource: file from which the format string originates from
@param[in] vparms_start: starting index of current trace args
@param[in] vparms_end: ending index of current trace args
@returns: a string with the values put into to the format string
          or an empty string if error
"""
def trexMyVsnprintf(bData, fstring, fsource, vparms_start, vparms_end):
    argnum = 0
    parsedArgs = []

    vparms_size = vparms_end - vparms_start
    i = 0 #used to iterate through format string
    j = vparms_start #used to iterate through binary arg data
    unsupportedSubSpecifiers = 'hjzt'
    formatSubSpecifiers = "-+0123456789#lLw. 'Ihjzt"

    while i < len(fstring):
        if argnum > TRACE_MAX_ARGS:
            break

        # check for '%' to find the first argument specifier
        if fstring[i] != '%':
            i += 1
            continue

        #skip %
        i += 1

        #check for '%%' and skip
        if fstring[i] == '%':
            i += 1
            continue


        # Check for supported format characters following the '%' which are sub-specifiers
        # such as flags (-+#0), precision (.num) and length (l, ll, L).
        # Also check for unsupported format characters such as the length specifiers hjzt.
        #
        # Trace Format String Assertions:
        # 1. %p will be supported as a 4-byte data entry for legacy support.
        #    %lp will be supported as a 8-byte data entry
        # 2. Any number of “l” characters in the format string signifies 8 bytes of data.  This
        #    is despite the fact that on some platforms %l=4 and %ll=8.
        # 3. Every subsystem must modify their hasher to match the number of bytes that are saved
        #    into the trace binary
        longflag = False
        while(1):
            if fstring[i] == 'l':
                longflag = True
                fstring = fstring[0 : i : ] + fstring[i + 1 : :]
            elif fstring[i] == 'L':
                longflag = True
                i += 1
            elif fstring[i] == 'p':
                # Replace %p with %x
                fstring = fstring[0 : i : ] + "x" + fstring[i + 1 : :]
            elif unsupportedSubSpecifiers.find(fstring[i]) != -1: #Unsupported char found
                #Remove char from format string
                fstring = fstring[0 : i : ] + fstring[i + 1 : :]
            elif formatSubSpecifiers.find(fstring[i]) == -1: #not found
                break
            else:
                i += 1 #skip optional char

        if fstring[i] == 's':
            #use marker if no data left in trace entry
            if j >= vparms_end:
                parsedArgs.append("[[NODATA]]")
            else:
                #find index of null char, if no null char use vparms_end + 1
                nullCharIndx = j
                strStartIndx = j
                while nullCharIndx < vparms_end + 1:
                    if bData[nullCharIndx]:
                        nullCharIndx += 1
                    else:
                        break

                numberOfChars = nullCharIndx - j
                unpackStr = str(numberOfChars) + 's'
                #Unpack a string (nullCharIndx - j) bytes long from bData starting at offset j
                #and add string to parsed arguments list
                try:
                    parsedArgs.append(struct.unpack_from(unpackStr, bData, j)[0].decode('UTF-8'))
                except Exception as err:
                    parsedArgs.append("[[PARSE ERROR]]")
                    capture_warning("Issue with parsing argument "
                                     + str(argnum + 1)
                                     + " with data \'0x"
                                     + data_to_hexstring2(bData, j, j+ numberOfChars)
                                     + "\' for:" )
                    capture_warning("  string: " + fstring)
                    capture_warning("  source: " + fsource)

                #make sure index is increased by a multiple of 4
                strLen = nullCharIndx - strStartIndx

                tmpint = strLen + 1;
                tmpint = (tmpint + 3) & ~3;

                j += tmpint

        elif "pcdiou".find(fstring[i]) != -1:
            if j >= vparms_end:
                parsedArgs.append("[[NODATA]]")
            else:
                if longflag:
                    #Unpack long long (8 bytes) from bData
                    #and add integer to parsed arguments list
                    parsedArgs.append(struct.unpack_from('>q', bData, j)[0])
                    j += 8
                else:
                    #Unpack long (4 bytes) from bData
                    #and add integer string to parsed arguments list
                    parsedArgs.append(struct.unpack_from('>l', bData, j)[0])
                    j += 4
            i += 1
        elif "xX".find(fstring[i]) != -1:
            if j >= vparms_end:
                parsedArgs.append("[[NODATA]]")
            else:
                if longflag:
                    #Unpack unsigned long long (8 bytes) from bData
                    #and add integer to parsed arguments list
                    parsedArgs.append(struct.unpack_from('>Q', bData, j)[0])
                    j += 8
                else:
                    #Unpack unsigned long (4 bytes) from bData
                    #and add integer string to parsed arguments list
                    parsedArgs.append(struct.unpack_from('>L', bData, j)[0])
                    j += 4
            i += 1
        elif "efEFgGaA".find(fstring[i]) != -1:
            #Unpack a float (4 bytes) from bData
            #and add float to parsed arguments list
            parsedArgs.append(struct.unpack_from('>f', bData, j)[0])
            j += 4
            i += 1
        else:
            capture_warning("Warning: unsupported format specifier in trace found '" + fstring[i] + "' :")
            capture_warning(fstring)
            i += 1
            return ''

        argnum += 1

    return fstring % tuple(parsedArgs)

""" Gets the format string for the given hash string

@param[in] hashValue: string of the Hash Value to lookup
@returns: a string of the format string for the given hash
          or an empty string if hash was not found
"""
def get_format_by_hash(hashValue):
    h = hTable.get(hashValue)
    if h is not None:
        return h['format']
    else:
        return '!!! NO STRING NO TRACE !!! for hash='+str(hashValue)

""" Gets the source file for the given hash string

@param[in] hashValue: string of the Hash Value to lookup
@returns: a string of the source file for the given hash
          or an empty string if hash was not found
"""
def get_source_by_hash(hashValue):
    h = hTable.get(hashValue)
    if h is not None:
        return h['source']
    else:
        return ''

""" Parses header data for a trace entry

@param[in] bf: bytes object of binary data
@param[in] start: int value of the starting index of data for a trace
@returns: if all the parsing was done successfully returns a tuple which includes:
          an int value of the starting index of the arg data for the current trace,
          an int value of the end index of the arg data,
          a int of the hash value,
          and a string of the formatted header data.
          or returns -1 if there was an error
"""
def get_pipe_trace(bf, start):
    # Data is in this format for each trace
    # N bytes : component name
    # 4 bytes : timestamp (seconds)
    # 4 bytes : timestamp (useconds)
    # 4 bytes : PID
    # 2 bytes : length of trace entry
    # 2 bytes : type of entry: xTRACE, xDUMP, (un)packed
    # 4 bytes : hash value for format string
    # 4 bytes : line number
    # N bytes : args

    dataHeaderSize = 4 + 4 + 4 + 2 + 2 + 4 + 4

    i = start
    compStr = ''

    if start >= (len(bf) - 1):
        return -1

    #Component name is followed by null char
    for i, b in enumerate(bf[start:], start):
        if b == 0x0:
            break
        else:
            compStr += chr(b)

    if TRACE_MAX_COMP_NAME_SIZE < (i-start-1):
        capture_error("Error: Trace component name corrupted")
        return -1

    i += 1
    #Unpack header data
    parsedData = struct.unpack_from('>3IHHII', bf, i)

    #Format header data for trace
    headerStr = f'{parsedData[0]:08}' + "." + f'{parsedData[1]:09}' + "|" + f'{parsedData[2]:>5}' + "|"
    headerStr += (f'{compStr:<16}' + "|" + f'{parsedData[6]:>4}' + "|")

    #Get starting index of args
    dataStart = i + dataHeaderSize
    return dataStart, (dataStart + parsedData[3]), parsedData[5], headerStr

""" Decodes the binary traces to a list that contains the individual traces in ASCII form

@param[in] bData: byte array - holds the binary trace data
@param[in] startingPosition: int value - the starting position in the byte array to start
                             decoding.  Useful if the binary trace data is prepended with
                             version info or some other beginning marker.
@returns: retVal: int value - the return code: 0 on success, non 0 on failure
          traces: list - the ASCII traces in list form
"""
def decode_binary_traces_to_ascii_list(bData, startingPosition):
    retVal = 0
    traces = []
    start = startingPosition
    end = 0
    while start < len(bData) - 1:
        gpt = get_pipe_trace(bData, start)
        if gpt != -1:
            end = gpt[1]
            #make sure index isn't passed end of data
            if end <= len(bData):
                #get format string and source
                formatString = get_format_by_hash(str(gpt[2]))
                formatSource = get_source_by_hash(str(gpt[2]))
                #Format full trace
                trace = gpt[3] + trexMyVsnprintf(bData, formatString, formatSource, gpt[0], end)
                if flags & TRACE_FILENAME:
                    trace += (' | ' + formatSource)
                #Add it to list of traces
                traces.append(trace)
                start = end
            else:
                capture_error("Error: index passed end of data")
                retVal = -1
                break
        else:
            capture_error("Error: header data for trace not parsed correctly " +
                          "- skipping the rest of the data")
            retVal = -1
            break

    return retVal, traces

""" Takes a list of the ASCII traces and returns the traces in a single string

@param[in] asciiTraceList: list - holds the ASCII Traces
@param[in] printNumTraces: int value - the number of traces to print starting at the end.
                                       if -1 then all traces are printed
@return a single string containing the ASCII traces
"""
def convert_ascii_trace_list_to_string(asciiTraceList, printNumTraces):
    # Initialize the return string with the header info
    traceDataString = trace_output_get_format()

    # If the number of traces is 0 then just return the header info
    if printNumTraces == 0 or len(asciiTraceList) == 0:
        traceDataString += (BUFFER_EMPTY_STRING + "\n")
        return traceDataString
    # If the number of traces is -1 then retrieve all the trace data
    elif printNumTraces == -1:
        printNumTraces = len(asciiTraceList)

    # Collect the traces limited by the number of traces given by caller
    traceDataString += '\n'.join(asciiTraceList[-printNumTraces:]) # Get the individual traces
    traceDataString += '\n' # Append a newline at the end of traces

    return traceDataString

""" Reads traces from the binary data and prints formatted traces

@param[in] bData: byte array - holds the binary trace data
@param[in] oFile: If an empty string - The ASCII traces are printed to the console
                  If not an empty string - The ASCII traces are printed to file 'oFile'
@param[in] startingPosition: int value - the starting position in the byte array to start
                             decoding.  Useful if the binary trace data is prepended with
                             version info or some other beginning marker.
@param[in] printNumTraces: int value - the number of traces to print starting at the end.
                                       if -1 then all traces are printed
@returns: Return 0 on success, non 0 on failure
"""
def trace_adal_print_pipe(bData, oFile, startingPosition, printNumTraces):
    # Decode the binary traces within the 'binaryData' into its ASCII equivalent
    retVal, asciiTracesList = decode_binary_traces_to_ascii_list(bData, startingPosition)
    if retVal != 0:
        return retVal

    # Get a string representation of the ASCII traces which is in list form
    traceDataString = convert_ascii_trace_list_to_string(asciiTracesList, printNumTraces);

    # Print the ASCII string based on the existence of the output file 'oFile'
    return processTraceDataString(oFile, traceDataString)

""" Translates the the trace in binary form to it's equivalent ASCII string

@param[in] binaryData: byte array - holds the binary trace data
@param[in] startingPosition: int value - the starting position in the byte array to start
                             decoding.  Useful if the binary trace data is prepended with
                             version info or some other beginning marker.
@param[in] printNumTraces: int value of number of traces from the end to print
@param[in] stringFileName: the hbotStringFile and location to it

@returns: retVal: int value - the return code: 0 for success, non 0 on failure
          traceDataString: string - if retVal is 0: a string containing the ASCII traces
                                    if retVal is not 0: a string containing error messages
          warningMessages: string - a string with warning messages if any encountered
"""
def get_binary_trace_data_as_string(binaryData, startingPosition, printNumTraces, stringFileName):
    # Reset the global variables.  Because they don't always get cleared with
    # subsequent calls to this API and can lead to undesired results.
    reset_global_vars()

    # Default the outgoing string to ""
    traceDataString = ""

    # Read in the string file and store its contents in the global hTable.
    # The hTable will be used in function call get_format_by_hash which is in
    # a nested call in method call process_binary_data_v1 below
    retVal = trace_adal_read_stringfile(stringFileName)
    if retVal != 0:
        capture_error("Error processing string file: " + stringFileName)
        return retVal, get_captured_errors_as_string(), get_captured_warnings_as_string()

    version = binaryData[startingPosition]
    retVal = validate_binary_data_trace_version(version)
    if retVal != 0:
        capture_error("Error processing binary data, version " + str(version) + " is unsupported")
        return retVal, get_captured_errors_as_string(), get_captured_warnings_as_string()

    if (version == TRACE_VERSION1):
        # Process version 1 binary data
        retVal, traceDataString = process_binary_data_v1(binaryData, startingPosition, printNumTraces)
        if retVal != 0:
            capture_error("Error processing binary data version 1 ")
            return retVal, get_captured_errors_as_string(), get_captured_warnings_as_string()
    elif (version == TRACE_VERSION2):
        startingPosition += 1
        (retVal, asciiTracesList) = decode_binary_traces_to_ascii_list(binaryData, startingPosition)
        if retVal != 0:
            capture_error("Error processing binary file version 2")
            return retVal, get_captured_errors_as_string(), get_captured_warnings_as_string()
        traceDataString = convert_ascii_trace_list_to_string(asciiTracesList, printNumTraces);

    return 0, traceDataString, get_captured_warnings_as_string()

""" Process tracBINARY file

@param[in] bFile: string of binary file name
@param[in] oFile: string of output file name
@param[in] printNumTraces: int value of number of traces from the end to print
@returns: Return 0 on success, non 0 on failure
"""
def process_binary_file_v2(bFile, oFile, printNumTraces):
    retVal = 0;
    try:
        with open(bFile, "rb") as bf:
            startingPosition = 1; # Skip over the version info of the file which is the 1st byte
            retVal = trace_adal_print_pipe(bf.read(), oFile, startingPosition, printNumTraces)
    except IOError as err:
        retVal = err.errno
        capture_error (str(err))
    except Exception as err:
        retVal = -1
        capture_error (str(err))

    return retVal

""" Validate the given trace version

@param[in] version: int value
@returns: Return 0 on success, non 0 on failure
"""
def validate_binary_data_trace_version(version):
    if ( (version != TRACE_VERSION1) and
         (version != TRACE_VERSION2) ):
        return -1
    return 0

""" Validate that the trace version of binary file is a supported version

@param[in] bFile: string of the path plus name to binary file.
@returns: return value: int value - the return code: 0 on success, non 0 on failure
          trace version: int value - the trace version, of the binary file, as an integer
"""
def validate_binary_file_trace_version(bFile):
    retVal = 0
    version = [0]
    try:
        with open(bFile, "rb") as f:
            version = f.read(1)
    except IOError as err:
        retVal = err.errno
        capture_error (str(err))
    except Exception as err:
        retVal = -1
        capture_error (str(err))
    else:
        # If the length of the version is 0 then dealing with an empty file
        if len(version) == 0:
            version = [0]  # reset this for the return statement below
            capture_error("Error: binary file " + bFile + " is empty")
            retVal = -1
        else:
            version = struct.unpack('b', version)
            retVal = validate_binary_data_trace_version(version[0])

    return retVal, version[0]

""" Parses a line of the stringFile and adds it to the hash table

@param[in] line: string of the line to parse
@returns: Return 0 on success, -1 on failure
"""
def parse_sf_entry_v2 (line):
    # Line is formatted as follows with '||' separator
    # Hash value || format string || source filename
    STRINGFILE_LINE_FORMAT = 3

    splitStr = line.split('||')

    if len(splitStr) == STRINGFILE_LINE_FORMAT:
        #If another line has the same Hash Value, it will be overwritten with the new
        #format string and source filename
        hTable[splitStr[0]] = {'format': splitStr[1],
                               'source': splitStr[2]}
        return 0
    else:
        capture_warning("Warning: Line was formatted incorrectly - Skipping:")
        capture_warning(line)
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

""" Reads in the string file to check version and parse entries

@param[in] fullyQualifiedStringFileName: string - absolute path to file and name of file
@returns: Return 0 on success, non 0 on failure
"""
def _trace_adal_read_stringfile(fullyQualifiedStringFileName):
    retVal = 0;
    try:
        with open(fullyQualifiedStringFileName) as stringFile:
            for x, line in enumerate(stringFile):
                if line.rstrip() == '': #Skip empty lines
                    continue

                if x != 0: #Parse line entry
                    parse_sf_entry_v2(line.rstrip())
                else: #Check that the stringfile is the correct version
                    version = parse_sf_magic_cookie(line.rstrip())
                    if version == -1:
                        capture_error("Error: File bad format. Cannot determine version of string file.")
                        retVal = -1
                        break
                    elif version != TRACE_VERSION2:
                        capture_error("Error: Unknown string file version " + str(version))
                        retVal = -1
                        break

    except IOError as err:
        retVal = err.errno
        capture_error (str(err))
    except Exception as err:
        retVal = -1
        capture_error (str(err))

    if retVal == 0 and not hTable:
        capture_error("Error: String file has no parsable data.")
        retVal = -1

    return retVal


""" Save the contents of the file into the global hash table list
    for future retrieval so it does NOT need to be parsed every time this file
    is encountered.

@param[in] fullyQualifiedStringFileName: string - absolute path to file and name of file
"""
def saveToHashTableList(fullyQualifiedStringFileName):
    # Remove the directories leading to file and extract the file name
    fileName = os.path.basename(fullyQualifiedStringFileName)

    # Declare global hTableStringFileName and hTableList to use global and not make a local
    global hTableList
    global hTableStringFileName

    # Deep copy the contents of the global hash and store it in the global hash list
    hTableList[fileName] = hTable.copy()
    hTableStringFileName = fileName


""" Reads in the string file to check version and parse entries

@param[in] fullyQualifiedStringFileName: string - absolute path to file and name of file
@returns: Return 0 if global hash table, hTable, contains the data from the file
          Return non 0 if hTable does not contain the data from the file
"""
def getFromHashTableList(fullyQualifiedStringFileName):
    # Remove the directories leading to file and extract the file name
    fileName = os.path.basename(fullyQualifiedStringFileName)

    # Declare global hTableStringFileName to use global and not make a local
    global hTableStringFileName

    # If current hash string file is the same as the file name then the global
    # hash table, hTable, is already populated with string file's data.
    # Nothing needs to be done
    if hTableStringFileName == fileName:
        return 0

    # If current hash string file is not the same as the file name
    # then check the global hash list to see if this file has already
    # been encountered and the data for it is stored. If so, then populate
    # the global hash table, hTable, with said file name's data.
    l_hTable = hTableList.get(fileName)
    if l_hTable is not None:
        # The hash info for file has been found,
        # Copy the contents to the global hash table
        global hTable
        hTable = l_hTable.copy()
        hTableStringFileName = fileName
        return 0

    # The file name's data is not stored, return -1 indicating this
    return -1

""" Reads in the string file and parse it's content's into the global
    hash table, hTable, and global hash table list, hTableList, if first time
    encountering file.  If file has already been encountered, then copy
    contents of file from the hash table list into the global hash table if it
    not currently there.

@param[in] fullyQualifiedStringFileName: string - absolute path to file and name of file
@returns: Return 0 on success, non 0 on failure
"""
def trace_adal_read_stringfile(fullyQualifiedStringFileName):
    retVal = getFromHashTableList(fullyQualifiedStringFileName)
    # If unable to get the hash info for file then need to create
    if retVal != 0:
        retVal = _trace_adal_read_stringfile(fullyQualifiedStringFileName)
        # If reading in the string file was successful
        # then save the info for future use
        if retVal == 0:
            saveToHashTableList(fullyQualifiedStringFileName)

    return retVal


""" Process binary file, with version 1 in the first byte of the data, and return
    the binary trace entries, found in the file, into ASCII traces that can be either
    written to an output file, if parameter 'outputFile' is defined, or printed
    to the console, if parameter 'outputFile' is not defined.

@param[in] binaryFile: binary file to read/process
@param[in] outputFile: file to write ASCII traces, if defined
@param[in] printNumTraces: an int value that specifies the number of traces
                           from the chronological end to print. A value of -1
                           is interpreted as to gather all traces
@returns: Return 0 on success, non 0 on failure
"""
def process_binary_file_v1(binaryFile, outputFile, printNumTraces):
    try:
        with open(binaryFile, "rb") as binaryFileHandle:
            startingPosition = 0; # position of the first byte where the version info is located
            # Process the binary data, contained within the binary file, and return the
            # trace entries, within the data, as a single string.
            (retVal, traceDataString) = process_binary_data_v1(binaryFileHandle.read(),
                                                               startingPosition, printNumTraces)
    except IOError as err:
        retVal = err.errno
        capture_error (str(err))
    except Exception as err:
        retVal = -1
        capture_error (str(err))

    if retVal != 0:
        return retVal

    return processTraceDataString(outputFile, traceDataString)

""" Process binary data, with version 1 in the first byte, and return the binary
    trace entries, found in the data, into a single string that contains the
    combined ASCII traces.  The number of traces, found in the string, will be
    limited to the number of traces specified by input parameter 'printNumTraces'
    if not -1.  A -1 value for 'printNumTraces' signifies to gather all traces.

@param[in] binaryData: a byte array that contains the header and traces for version 1 data
@param[in] dataHeaderOffset: an int value that species the offset to the version
                             1 header info
@param[in] printNumTraces: an int value that specifies the number of traces
                           from the chronological end to print.  A value of -1
                           is interpreted as to gather all traces
@returns: return value: int value - the return code: 0 on success, non 0 on failure
          trace data string: a string - a string composed of the traces
"""
def process_binary_data_v1(binaryData, dataHeaderOffset, printNumTraces):
    # Process the header data, for version 1, and return the data found in the
    # header as a named tuple 'HeaderDataV1'
    retVal, headerDataV1 = parse_binary_data_header_v1(binaryData, dataHeaderOffset)
    if retVal != 0:
        return retVal, 0

    # Process the trace entries in the binary data and return the trace entry data
    # as a list of a named tuple 'TraceEntriesV2'.  Trace entry version 2 has the
    # same data as version 1 with the addition of the component name.
    retVal, traceEntriesV2 = parse_data_trace_entries_v1(binaryData, headerDataV1)
    if retVal != 0:
        return retVal, 0

    # Reverse the order of trace entires to get the data in chronological order
    traceEntriesV2.reverse()

    # Translate the trace entries to ASCII representation
    retVal, asciiTracesList = get_ascii_traces_from_trace_entry_list(binaryData, traceEntriesV2)
    if retVal != 0:
        return retVal, 0

    # Get a string representation of the ASCII traces which is in list form
    traceDataString = convert_ascii_trace_list_to_string(asciiTracesList, printNumTraces);

    return 0, traceDataString


""" Parse the header from the binary data, with version 1 in the first byte, and
    return the parsed data into a named tuple 'HeaderDataV1'.

@param[in] binaryData: a byte array that contains the header for version 1
@param[in] headerOffset: an int value that specifies the offset to the header
@returns: return value: int value - the return code: 0 on success, non 0 on failure
          named tuple HeaderDataV1: tuple - named tuple HeaderDataV1 composed of
                                    the header data from the binaryData
"""
def parse_binary_data_header_v1(binaryData, headerOffset):
    # Binary Trace Data Header Version 1
    # 1 bytes : version of binary data
    # 1 bytes : header length in bytes
    # 1 bytes : time flag - meaning of timestamp entry field
    # 1 bytes : endian flag for big 'B' and little 'L'
    # 16 bytes : null terminated component name (TRACE_MAX_COMP_NAME_SIZE)
    # 4 bytes : size of binary data including this header data
    # 4 bytes : how often the buffer wrapped
    # 4 bytes : offset to byte right after last trace entry which is the size of the last trace entry
    # 8 bytes : unused in version 1 header, needed for forward compatibility with version 2.
    headerDataSize = 1 + 1 + 1 + 1 + TRACE_MAX_COMP_NAME_SIZE + 4 + 4 + 4 + 8

    offset = headerOffset

    # Read the version, header length, time flag and endianess as a single byte (B) each
    # Reading bytes therefore endianness is not a factor
    (version, retrievedHeaderDataSize, timeFlag, endianess) = struct.unpack_from('4B', binaryData, offset)

    if DEBUG_TRACE_HEADER > 0:
        print("Trace Header:")
        hexStrings = data_to_hexstring(binaryData, 0, headerDataSize)
        for line in hexStrings:
            print(line)

    # Confirm the binary data is version 1
    if (version != TRACE_VERSION1):
        capture_error("Error: Expected version " + str(TRACE_VERSION1) +
                      " but the binary data is version " + str(version) )
        return -1, 0

    # Confirm that header size given in the binary data is what is expectd
    if (retrievedHeaderDataSize != headerDataSize):
        capture_error("Error: Retrieved header size " + str(retrievedHeaderDataSize) +
                      " does not match the expected header size " + str(headerDataSize) +
                      ".  The binary data is corrupt/incorrect" )
        return -1, 0

    # Interpret the endianess from the header to its python equivalent character
    endian = '>' # Assume endianess is big (>)
    if ( endianess == ord('L') ):
        endian = '<'

    offset += 4 # advance offset to component name

    compStr = ''
    # Retrieve component name up until the max component name size, TRACE_MAX_COMP_NAME_SIZE
    # number of bytes, has been found or when the first NULL character is encountered
    for i, b in enumerate(binaryData[offset:]):
        if (i == TRACE_MAX_COMP_NAME_SIZE) or (b == 0x0):
            break
        else:
            compStr += chr(b)

    offset += TRACE_MAX_COMP_NAME_SIZE # advance offset to 'size of binary data'

    # Read the size of binary data, buffer wrap count and offset to end of data
    # each as integers (I = 4 bytes)
    (sizeOfBinaryData, wrapCount, offsetToLastEntrySize) = struct.unpack_from(endian + '3I', binaryData, offset)

    # Confirm that the size of binary is equal to the offset to the last trace
    # entry size.  The last entry size will be at the end of the buffer
    if (sizeOfBinaryData != offsetToLastEntrySize):
        # Some apps do not truncate the trace buffer correctly so the offset to the last
        #   entry is actually before the start of the trace block. Add a warning and adjust
        #   the offset to allow the trace to be parsed. The oldest trace entry will be
        #   detected as truncated and be dropped. Allowing this for backwards compatibility.
        capture_warning("block size:"+str(sizeOfBinaryData)+" != offset to last entry:"+
                str(offsetToLastEntrySize)+" (wrapCount="+str(wrapCount)+") for component: "+
                compStr)
        offsetToLastEntrySize = sizeOfBinaryData

    # Get the offset to the start of the trace entries which is right after
    # the header info
    offsetToStartOfTraces = headerOffset + retrievedHeaderDataSize

    # Cache all of the gathered data into a header tuple and hand back to caller
    headerData = HeaderDataV1(version, retrievedHeaderDataSize, timeFlag, endianess,
                              compStr, sizeOfBinaryData, wrapCount,
                              offsetToLastEntrySize, offsetToStartOfTraces, endian)

    return 0, headerData

""" Parse the header from the binary data, with version 1 in the first byte, and
    return the parsed data into named tuple 'HeaderDataV1'.

@param[in] binaryData: a byte array that contains the trace entries for version 1
@param[in] headerData: named tumple HeaderDataV1
@returns: return value: int value - the return code: 0 on success, non 0 on failure
          named tuple TraceEntriesV2 list: A list of named tuples TraceEntriesV2
"""
def parse_data_trace_entries_v1(binaryData, headerData):
    """  The trace entries are in reverse chronological order with the size of the
         trace entry at the end of the trace entry itself:
            First Trace Entry - Last in chronological order
            First Trace Entry Size
            ....
            Last Trace Entry - First in chronological order
            Last Trace Entry Size

         With the size of the trace entry after the trace entry itself, therefore
         must read trace entries starting with the last entry's size:
            Read last entry size
            Read last entry
            Read 'last - 1' entry size, using the last's entry size to get to offset
            Read 'last - 1' entry
            ...
            Read first trace entry size, using the previous entry size to get this offset
            Read first trace entry

        Note:  The entry size incudes both the size of the entry and size of the entry size
    """
    startOffset = headerData.offsetToFirstTraceEntry
    endOffset = headerData.offsetAfterLastTraceEntrySize
    compStr = headerData.compName
    endian = headerData.endianPythonChar

    if DEBUG_TRACE_DATA > 0:
        print("Trace Data for component \""+compStr+"\":")
        hexStrings = data_to_hexstring(binaryData, startOffset, endOffset)
        for line in hexStrings:
            print(line)

    # Cache the size, the number of bytes that make up the trace entry size
    traceEntryByteSize = 4

    traceEntriesV2 = []

    # Start with the last entry and iterate to the first entry in buffer
    # The endOffset points to the byte right after the size of an entry
    """
    | 1st trace entry                |
    |   4 bytes: seconds             |  <--- startOffset (stays constant)
    |   ....                         |
    |   N bytes: argument(s)         |
    |   4 bytes: trace entry size    | <--- traceEntrySizeOffset AKA the trace entry end
    | 1 byte : byte after entry size | <--- endOffset (gets updated on each iteration)
    |  ......                        |

    | Last - 1 trace entry           |
    |   4 bytes: seconds             | <--- traceEntryStart (gets updated on each iteration)
    |   ....                         |
    |   N bytes: argument(s)         |
    |   4 bytes: trace entry size    | <--- traceEntrySizeOffset AKA the trace entry end
    | 1 byte : byte after entry size | <--- endOffset (gets updated on each iteration)
    |                                |
    | Last trace entry               |
    |   4 bytes: seconds             | <--- traceEntryStart (gets updated on each iteration)
    |   ....                         |
    |   N bytes: argument(s)         |
    |   4 bytes: trace entry size    | <--- traceEntrySizeOffset AKA the trace entry end
    | 1 byte : byte after entry size | <--- endOffset (initial value)
    """
    while endOffset >  startOffset:
        # Get the offset to the trace entry size which is 4 bytes above the endOffset
        traceEntrySizeOffset = endOffset - traceEntryByteSize
        # Get the size of the trace entry
        traceEntrySize = struct.unpack_from(endian + 'I', binaryData, traceEntrySizeOffset)
        # Get the offset to the start of the trace entry via the trace entry size
        traceEntryStart = endOffset - traceEntrySize[0]

        # Verify that the start of the entry is *not* before the start offset
        if startOffset > traceEntryStart:
            # Print warning, but still return the successfully parsed trace
            capture_warning("Ignoring truncated last trace entry (offset:" +
                    str(traceEntryStart) + " < starting offset:" + str(startOffset) +
                    ") for component \""+compStr+"\"")
            return 0, traceEntriesV2

        # The end of the trace is where the trace entry size begins therefore
        # passing traceEntrySizeOffset as the trace entry end
        retVal, traceEntryV1 = parse_trace_entry_header_v1(binaryData,
                                 headerData.endianPythonChar, traceEntryStart,
                                 traceEntrySizeOffset)

        if retVal != 0:
            return retVal, traceEntriesV2

        traceEntryV2 = TraceEntryV2(compStr, traceEntryV1)
        traceEntriesV2.append(traceEntryV2)
        # Get the next preceding trace entry
        endOffset = traceEntryStart

    return 0, traceEntriesV2


""" Given a list of trace entries, version 2, return a list of ASCII strings
    translated from the trace entries.

@param[in] binaryData: a byte array that contains the trace entries
@param[in] traceEntriesV2: a list of version 2 trace entries
@returns: return value: int value - the return code: 0 on success, non 0 on failure
          traces: list of strings: a list of ASCII strings translated from the trace entries.
"""
def get_ascii_traces_from_trace_entry_list(binaryData, traceEntriesV2):
    traces = []
    for traceEntryV2 in traceEntriesV2:
        traceEntryV1 = traceEntryV2.TraceEntryV1

        traceStr = format_trace_entry(traceEntryV2.compStr,  traceEntryV1.seconds,
                                      traceEntryV1.useconds, traceEntryV1.pid,
                                      traceEntryV1.lineNumber )

        formatString = get_format_by_hash(str(traceEntryV1.hash))
        sourceString = get_source_by_hash(str(traceEntryV1.hash))
        if (traceEntryV1.entryType == TRACE_COMP_TRACE) or (traceEntryV1.entryType == TRACE_FIELDTRACE):
            traceStr +=  trexMyVsnprintf(binaryData, formatString, sourceString, traceEntryV1.argsOffset,
                         (traceEntryV1.argsOffset + traceEntryV1.entrySize))
            if flags & TRACE_FILENAME:
                traceStr += (' | ' + get_source_by_hash(str(traceEntryV1.hash)))
            traces.append(traceStr)
        elif traceEntryV1.entryType == TRACE_FIELDBIN:
            traceStr2 =  traceStr + trexMyVsnprintf(binaryData, formatString, sourceString, traceEntryV1.argsOffset,
                                   (traceEntryV1.argsOffset + traceEntryV1.entrySize))

            traces.append(traceStr2)
            hexStrings = data_to_hexstring(binaryData, traceEntryV1.argsOffset,
                                          (traceEntryV1.argsOffset + traceEntryV1.entrySize) );
            for hexString in hexStrings:
                hexTrace = traceStr + hexString
                traces.append(hexTrace)
        else:
            capture_error("Error: entry type " + str(traceEntryV1.entryType) +
                          " not recognized")
            return -1, traces

    return 0, traces


""" Converts binary data into lines of printable strings.  Each line is representing
    16 bytes of the binary data or less.  A line is composed of 3 columns.
    A left column displaying the offset into the data, a middle column displaying
    the binary data, as readable ASCII, and a right column displaying any printable
    ASCII chars within the binary data and any non-printable ASCII chars are
    represented as '.'.
    See example below.
    Example:
        ~[0x0000] 82993DCB 46F51938 68567C7E 0C32BCCA     *..=.F..8hV|~.2..*
        ~[0x0010] ED6F0EE6 9AE01210 5D21666A 6DE9A091     *.o......]!fjm...*

@param[in] binaryData: a byte array that contains the trace entries and data associated with
@param[in] startOfData: an integer offset to the beginning of the binary data of a trace entry
@param[in] endOfData:   an integer offset to one past the end of the binary data of a trace entry
@returns: hex string traces: a list of printable strings representing the binary data
"""
def data_to_hexstring(binaryData, startOfData, endOfData):
    lastAsciiChar = 127 # The value of the last ASCII character
    hexStrings = [] # Will contain the printable strings that will be returned back
    lineCount = 0   # Keeps track of the offset into the data
    dataPart = ""   # Will hold the printable hex values of the data
    asciiPart = ""  # Will hold the printable ASCII values of the data or "." if not printable
    # Iterate thru the data, decoding each byte
    start = startOfData
    while start < endOfData:
        byte = binaryData[start]
        # Convert the data to its equivalent printable hex value
        dataPart += '%.2X' % byte
        # Convert the data to it's equivalent printable ASCII value or "."
        if byte <= lastAsciiChar:
            dataChar = chr(byte)
            if dataChar.isprintable():
                asciiPart += dataChar
            else:
                asciiPart += "."
        else:
            asciiPart += "."

        lineCount += 1

        # If 4 bytes have been seen, then add an extra blank, " ", as separation
        if lineCount % 4 == 0:
            dataPart += " "

        # If 16 bytes have been seen, then append the ASCII part and add to list
        if lineCount % 16 == 0:
            # Get the line number the 16 bytes are aligned with, starting at 0
            lineNumber = "~[" + '0x{0:0{1}X}'.format(lineCount - 16, 4) + "] "
            dataPart += "    *" + asciiPart + "*"
            hexStrings.append(lineNumber + dataPart)
            dataPart = ""
            asciiPart = ""
        start += 1

    # If the data did not land on a 16 byte boundary, then pad the data part
    while (lineCount % 16) != 0:
        lineCount += 1
        dataPart+= "  "
        if lineCount % 4 == 0:
            dataPart+= " "

        if lineCount % 16 == 0:
            # Get the line number the 16 bytes are aligned with, starting at 0
            lineNumber = "~[" + '0x{0:0{1}X}'.format(lineCount - 16,4) + "] "
            dataPart += "    *" + asciiPart + "*"
            hexStrings.append(lineNumber + dataPart)

    return hexStrings

""" Convert a array of binary data into a string of printable hex values

@param[in] binaryData: a byte array that contains the binary data to be converted to ASCII
@param[in] startOfData: an integer offset to the beginning of the binary data
@param[in] endOfData:   an integer offset to one past the end of the binary data
@returns: hex string: a printable string representing the binary data
"""
def data_to_hexstring2(binaryData, startOfData, endOfData):
    hexString = ""   # Will hold the printable hex values of the data
    # Iterate thru the data, decoding each byte
    start = startOfData
    while start < endOfData:
        # Convert the data to its equivalent printable hex value
        hexString += '%.2X' % binaryData[start]
        start += 1

    return hexString


""" Parse a version 1 trace entry

@param[in] binaryData: the binary data that contains the trace entry
@param[in] endian: the endiannes that the trace entry is formatted in
@param[in] traceEntryStart: the offset to the beginning of the trace entry
@param[in] traceEntryEnd: the offset to the ending of the trace entry
@returns: return value: int value - the return code: 0 on success, non 0 on failure
          named tuple TraceEntryV1: tuple - named tuple TraceEntryV1 composed of
                                    version 1 trace entry
"""
def parse_trace_entry_header_v1(binaryData, endian, traceEntryStart, traceEntryEnd):
    # Data is in this format for each trace
    # 4 bytes : timestamp (seconds)
    # 4 bytes : timestamp (useconds)
    # 4 bytes : PID
    # 2 bytes : size of trace entry
    # 2 bytes : entry type (xTRACE, xDUMP)
    # 4 bytes : hash
    # 4 bytes : line number
    # N bytes : args
    dataHeaderSize = 4 + 4 + 4 + 2 + 2 + 4 + 4

    startOffset = traceEntryStart
    endOffset = traceEntryEnd

    if DEBUG_TRACE_ENTRY > 0:
        print("Trace Entry:")
        hexStrings = data_to_hexstring(binaryData, startOffset, endOffset)
        for line in hexStrings:
            print(line)

    if (startOffset + dataHeaderSize) > endOffset:
        capture_error("Error: Trace entry buffer size " +  str(traceEntryEnd - traceEntryStart + 1) +
                      " is not large enough to contain a version 1 trace of size " + str(dataHeaderSize))
        return -1, 0

    # Unpack header data: seconds ... line number (see above data format)
    parsedData = struct.unpack_from(endian + '3I2H2I', binaryData, startOffset)

    # populate a TraceEntryV1 with the gathered data plus the offset to the arguments
    argsOffset = startOffset + dataHeaderSize
    traceEntry = TraceEntryV1(*parsedData, argsOffset)

    return 0, traceEntry


""" Format the given data into a string

@param[in] compStr: component name
@param[in] timeSeconds: whole seconds part
@param[in] timeUseconds: fractional seconds part
@param[in] pid: process ID
@param[in] lineNumber: line number of trace
@return a formatted string of the data given
"""
def format_trace_entry(compStr, timeSeconds, timeUseconds, pid, lineNumber):
    #Format header data for trace
    headerStr = f'{timeSeconds:08}' + "." + f'{timeUseconds:09}' + "|" + f'{pid:>5}' + "|"
    headerStr += (f'{compStr:<16}' + "|" + f'{lineNumber:>4}' + "|")
    return headerStr


""" Given a string, representing the trace entries, write string to a file or
    write to a console based on the input parameter 'outputFile'.  If the
    'outputFile' is defined then the string is written to file.  If 'outputFile'
    is not define then string is written to console.

@param[in] outputFile: file to write ASCII traces, if defined
@param[in] traceDataString: string representing trace entries
@return: int value: 0 on success, non 0 on failure
"""
def processTraceDataString(outputFile, traceDataString):
    retVal = 0
    # Print the ASCII string based on the existence of the output file 'outputFile'
    if outputFile != '':
        try:
            # Write the ASCII trace data to given file
            with open(outputFile, 'w') as outputFileHandle:
                if len(get_captured_warnings_as_string()):
                    outputFileHandle.write(get_captured_warnings_as_string())
                    outputFileHandle.write("\n")
                outputFileHandle.write(traceDataString)
        except IOError as err:
            retVal = err.errno
            capture_error (str(err))
        except Exception as err:
            retVal = -1
            capture_error (str(err))
    else:
        # Print the ASCII trace data out to the console
        if len(get_captured_warnings_as_string()):
            print(get_captured_warnings_as_string())
        print(traceDataString, end='')

    return retVal

""" main """
if __name__ == "__main__":
    defaultStringFileName = 'img/hbotStringFile'

    cmdlineParser = argparse.ArgumentParser(description='fsp-trace -- Used to parse trace binary files')
    cmdlineParser.add_argument('-f', '--file_name', action='store_true',
                                                    help='Display File Name with each trace')
    cmdlineParser.add_argument('-t', '--tail', metavar='NUM',
                                               type=int,
                                               default=-1,
                                               help='Only show last NUM traces')
    cmdlineParser.add_argument('-o', '--output_dir', type=str,
                                                     default='',
                                                     help='Write output to given file')
    cmdlineParser.add_argument('-s', '--stringfile', type=str,
                                                     default=defaultStringFileName,
                                                     help='Location of StringFile')
    cmdlineParser.add_argument('tracBINARY', type=str, help='Location of binary file')

    args = cmdlineParser.parse_args()

    if args.file_name:
        flags |= TRACE_FILENAME

    #Process String File
    retVal = trace_adal_read_stringfile(args.stringfile)
    if retVal != 0:
        capture_error("Error processing string file " + args.stringfile +
                      " - terminating")
        print(get_captured_errors_as_string())
        sys.exit(retVal)

    #Validate that the trace version of the supplied binary file is supported
    retVal, version = validate_binary_file_trace_version(args.tracBINARY)
    if retVal != 0:
        capture_error("Error processing binary file, version " + str(version) +
                      " is unsupported - terminating")
        print(get_captured_errors_as_string())
        sys.exit(retVal)

    if (version == TRACE_VERSION1):
        #Process version 1 binary file
        retVal = process_binary_file_v1(args.tracBINARY, args.output_dir, args.tail)
        if retVal != 0:
            capture_error("Error processing binary file version 1 - terminating")
            print(get_captured_errors_as_string())
            sys.exit(retVal)
    elif (version == TRACE_VERSION2):
        #Process version 2 binary file
        retVal = process_binary_file_v2(args.tracBINARY, args.output_dir, args.tail)
        if retVal != 0:
            capture_error("Error processing binary file version 2 - terminating")
            print(get_captured_errors_as_string())
            sys.exit(retVal)


