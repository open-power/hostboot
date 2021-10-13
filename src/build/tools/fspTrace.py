#!/usr/bin/python
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/fspTrace.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2021
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
import struct
import sys, os
import argparse

""" Dictionary to hold parsed strings from string file
hTable = { hashString : { 'format': formatString ,
                          'source': sourceString },
           ...
         }
"""
hTable = {}

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
@param[in] vparms_start: starting index of current trace args
@param[in] vparms_end: ending index of current trace args
@returns: a string with the values put into to the format string
          or an empty string if error
"""
def trexMyVsnprintf(bData, fstring, vparms_start, vparms_end):
    argnum = 0
    longflag = False
    parsedArgs = []

    vparms_size = vparms_end - vparms_start
    i = 0 #used to iterate through format string
    j = vparms_start #used to iterate through binary arg data
    unsuportedFormatChars = 'hjzt'
    charstring = "-+0123456789#lLw. 'Ihjzt"

    while i < len(fstring):
        if argnum > TRACE_MAX_ARGS:
            break

        #check for '%'
        if fstring[i] != '%':
            i += 1
            continue

        #skip %
        i += 1

        #check for '%%' and skip
        if fstring[i] == '%':
            i += 1
            continue

        #check for format characters following '%'
        while(1):
            if fstring[i] == 'l':
                longflag = True
                fstring = fstring[0 : i : ] + fstring[i + 1 : :]
            elif fstring[i] == 'L':
                longflag = True
                i += 1
            elif unsuportedFormatChars.find(fstring[i]) != -1: #Unsupported char found
                #Remove char from format string
                fstring = fstring[0 : i : ] + fstring[i + 1 : :]
            elif charstring.find(fstring[i]) == -1: #not found
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

                unpackStr = str(nullCharIndx - j) + 's'
                #Unpack a string (nullCharIndx - j) bytes long from bData starting at offset j
                #and add string to parsed arguments list
                parsedArgs.append(struct.unpack_from(unpackStr, bData, j)[0].decode('UTF-8'))

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
            print("Error: unsupported format specifier in trace found: ", fstring[i])
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
        return ''

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
        print("Error: Trace component name corrupted")
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

""" Reads traces from the binary data and prints formatted traces

@param[in] bData: bytes object holding binary trace data
@param[in] oFile: string of output file name
@param[in] printNumTraces: int value of number of traces from the end to print
@returns: Return 0 on success, -1 on failure
"""
def trace_adal_print_pipe(bData, oFile, printNumTraces):
    traces = []
    start = 1
    end = 0
    while start < len(bData) - 1:
        gpt = get_pipe_trace(bData, start)
        if gpt != -1:
            end = gpt[1]
            #make sure index isn't passed end of data
            if end <= len(bData):
                #get format string
                fstring = get_format_by_hash(str(gpt[2]))
                #Format full trace
                trace = gpt[3] + trexMyVsnprintf(bData, fstring, gpt[0], end)
                if flags & TRACE_FILENAME:
                    trace += (' | ' + get_source_by_hash(str(gpt[2])))
                #Add it to list of traces
                traces.append(trace)
                start = end
            else:
                print("Error: index passed end of data")
                return -1
        else:
            print("Error: header data for trace not parsed correctly "
                  "- skipping the rest of the data")
            break

    if printNumTraces == -1:
        printNumTraces = len(traces)

    if oFile != '':
        #Write traces to given file
        of = open(oFile, 'w')
        of.write(trace_output_get_format())
        for x in traces[-printNumTraces:]:
            of.write(x + '\n')
        of.close()
    else:
        #Print Traces
        print(trace_output_get_format(), end='')
        for x in traces[-printNumTraces:]:
            print(x)

    return 0

""" Process tracBINARY file

@param[in] bFile: string of binary file name
@param[in] oFile: string of output file name
@param[in] printNumTraces: int value of number of traces from the end to print
@returns: Return 0 on success, -1 on failure
"""
def do_file_binary(bFile, oFile, printNumTraces):
    bf = open(bFile, "rb")

    ret = trace_adal_print_pipe(bf.read(), oFile, printNumTraces)

    bf.close()

    return ret

""" Check if the first byte of the binary file is "0x2" (fsp-trace version)

@param[in] bFile: string of the binary file name
@returns: Return 0 on success, -1 on failure
"""
def is_tracBINARY(bFile):
    f = open(bFile, "rb")

    if f.read(1) != bytes.fromhex('02'):
        f.close()
        return -1
    else:
        f.close()
        return 0

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
        print("Error: Line was formatted incorrectly - Skipping")
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

@param[in] stringFileName: string of string file name
@returns: Return 0 on success, -1 on failure
"""
def trace_adal_read_stringfile(stringFileName):
    with open(stringFileName) as stringFile:
        for x, line in enumerate(stringFile):
            if line.rstrip() == '': #Skip empty lines
                continue

            if x != 0: #Parse line entry
                parse_sf_entry_v2(line.rstrip())
            else: #Check that the stringfile is the correct version
                if parse_sf_magic_cookie(line.rstrip()) != 2:
                    print('Error: Unknown StringFile Version')
                    return -1
    stringFile.close()

    return 0

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
    if trace_adal_read_stringfile(args.stringfile) == -1:
        print("Error processing string file - terminating")
        sys.exit()

    #Check version of tracBINARY
    if is_tracBINARY(args.tracBINARY) == -1:
        print("Error incorrect version for tracBINARY - terminating")
        sys.exit()

    #Process Binary file and Print Traces
    if do_file_binary(args.tracBINARY, args.output_dir, args.tail) == -1:
        print("Error processing binary file - terminating")
        sys.exit()
