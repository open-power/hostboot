/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/plugins/sbeIoErrlUd.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2024                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef SBEIO_ERRL_UDP_H
#define SBEIO_ERRL_UDP_H

/*
 *  @file sbeIoErrlUd.H
 *
 *  @NOTE: This file integrates the contents of the file in the FSP repo,
 *         $SANDBOXBASE/obj/ppc/sbei/sbfw/parserplugins/odySbeUserDataParser.C
 *         These files must be kept in sync. Any modification to this file
 *         must be reflected in the file odySbeUserDataParser.C and vice versa.
 *
 *  Defines the ErrlUserDetailsParser classes that parse SBEIO FFDC
 */

#include <sys/stat.h>
#include <errno.h>

#include <cstdlib>
#include <cstring>
#include <sstream>

#include <utilfile.H>
#include <utilmem.H>

#include "sbeIoFfdcType.H"
#include "sbeffdctypecommon.H"

#define ODY_SBE_TEMP_DUMP_FILE              "/tmp/ody_trace_dump.bin"
#define ODY_SBE_TRACE_BIN                   "/tmp/ody_sbe_trace.bin"
#define ODY_PPE2FSP_TOOL                    "ppe2fsp"
#define ODY_SBE_STRING_FILE                 "odysseySppeStringFile_DD1"

#define ODY_SBE_TRACE_CMD                   "fsp-trace -s"
#define ODY_SBE_TRACE_HEADLINE              "SBE Traces"

#define SBE_TEMP_DUMP_FILE              "/tmp/trace_dump.bin"
#define SBE_TRACE_BIN                   "/tmp/sbe_trace.bin"
#define PPE2FSP_TOOL                    "ppe2fsp"
#define P9_XIP_TOOL                     "p9_xip_tool"
#define SBE_TRACE_CMD                   "fsp-trace -s"
#define SBE_TRACE_HEADLINE              "SBE Traces"
#define SBE_ATTR_DUMP_HEADLINE          "SBE Attributes Dump"
#define P9_XIP_ATTR_CMD                 "-ifs attrdump"
#define SBE_STRING_FILE                 "sbeStringFile_DD1"

// Keeping the ODY parms to allow independency between PROC and ODYSSEY
#define ODY_SBE_PARSER_TRACE_HEADER_SIZE    56
#define ODY_SBE_PARSER_MAX_CIRC_BUFFER_SIZE 8192
#define SBE_PARSER_MAX_LOCAL_BUFFER         8192
#define ODY_SBE_PARSER_MAX_LOCAL_BUFFER     ODY_SBE_PARSER_TRACE_HEADER_SIZE + \
                                            ODY_SBE_PARSER_MAX_CIRC_BUFFER_SIZE

#define SBE_PARSER_PRINT_DELIMITER {std::cout << \
"*****************************************************************************"\
<< std::endl;}
#define SBE_PARSER_PRINT_HEADING(x) { SBE_PARSER_PRINT_DELIMITER \
std::cout << \
"                             " x << std::endl;\
SBE_PARSER_PRINT_DELIMITER }

#define ODY_SBE_PARSER_PRINT_DELIMITER {std::cout << \
"*****************************************************************************"\
<< std::endl;}
#define ODY_SBE_PARSER_PRINT_HEADING(x) { ODY_SBE_PARSER_PRINT_DELIMITER \
std::cout << \
"                             " x<< std::endl;\
ODY_SBE_PARSER_PRINT_DELIMITER }

#define SPPE_LEVEL_ATTR_MAX_STRING_SIZE 20
#define SPPE_CODE_LEVEL_ATTR_ARRAY_SIZE 64
#define TO_UINT32(ptr)  (ntohl(*(reinterpret_cast<uint32_t*>(ptr))))
#define TO_UINT64(ptr)  (ntohll(*(reinterpret_cast<uint64_t*>(ptr))))

namespace SBEIO
{

std::string SBE_SEEPROM_BIN = "sbe_seeprom_DD1.bin";


/**
 * @class SbeIoOdyFfdcErrlParser
 *
 */
class SbeIoOdyFfdcErrlParser : public ERRORLOG::ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    SbeIoOdyFfdcErrlParser() {}

    /**
     *  @brief Destructor
     */
    virtual ~SbeIoOdyFfdcErrlParser() {}

    /**
     *  @brief Parses string user detail data from an error log
     *
     *  @param  i_version Version of the data
     *  @param  i_parse   ErrlUsrParser object for outputting information
     *  @param  i_pBuffer Pointer to buffer containing detail data
     *  @param  i_buflen  Length of the buffer
     */

    virtual void parse(errlver_t i_version,
                       ErrlUsrParser & i_parser,
                       void * i_pBuffer,
                       const uint32_t i_buflen) const
    {
    int l_rc = 0;
    uint32_t fapiRc = 0;
    sbePlatHeader_t l_pData = {0};
    char l_buffer[ODY_SBE_PARSER_MAX_LOCAL_BUFFER] = {0};
    char *l_pBuffer = (char*)i_pBuffer;
    uint32_t l_buflen = i_buflen;
    do
    {
        if(i_pBuffer == NULL)
        {
            l_rc = -1;
            break;
        }
        //seek l_mem to the binary blob of FFDC package
        UtilMem l_mem(const_cast<void*>(i_pBuffer),i_buflen);

        // The data is a buffer of SBE FFDC data
        i_parser.PrintHeading("SBE FFDC Parser");

        if(l_buflen < sizeof(fapiRc))
        {
            i_parser.PrintHexDump(l_pBuffer, l_buflen);
            break;
        }
        l_buflen -= sizeof(fapiRc);
        l_pBuffer += sizeof(fapiRc);
        l_mem >> fapiRc;
        i_parser.PrintNumber("FAPI RC ", "0x%08X", ntohl(fapiRc));

        if(l_buflen < sizeof(l_pData))
        {
            i_parser.PrintHexDump(l_pBuffer, l_buflen);
            break;
        }
        l_buflen -= sizeof(l_pData);
        l_pBuffer += sizeof(l_pData);
        l_mem >> l_pData;

        i_parser.PrintNumber("Primary Status ", "0x%04X",
                (uint16_t)ntohs(l_pData.priRc));
        i_parser.PrintNumber("Secondary Status ", "0x%04X",
                (uint16_t)ntohs(l_pData.secRc));
        i_parser.PrintNumber("FW Commit ID ", "0x%08X",
                (uint32_t)ntohl(l_pData.fwCommitId));
        i_parser.PrintNumber("DD Major ", "0x%02X",
                l_pData.ddMajor);
        i_parser.PrintNumber("DD Minor", "0x%02X",
                l_pData.ddMinor);
        i_parser.PrintNumber("Thread Id", "0x%02X",
                l_pData.threadId);

        //loop through the number of fields configured
        uint32_t l_data = 0;

        if(l_buflen < sizeof(l_data))
        {
            i_parser.PrintHexDump(l_pBuffer, l_buflen);
            break;
        }
        l_buflen -= sizeof(l_data);
        l_pBuffer += sizeof(l_data);

        l_mem >> l_data;
        uint32_t l_dumpFields = ntohl(l_data);
        while(l_dumpFields && !l_rc)
        {
            if(l_dumpFields & SBE_FFDC_ALL_PLAT_DATA)
            {
                if(l_buflen < sizeof(uint32_t))
                {
                    //Complete this loop and let the tools print as much data
                    //as possible but break from next loop
                    l_rc = -1;
                }
                packageBlobField_t l_ffdcUserDataId = {0};
                l_buflen -= sizeof(uint32_t); //l_ffdcUserDataId
                l_pBuffer += sizeof(uint32_t); //l_ffdcUserDataLength

                l_mem >> l_ffdcUserDataId;

                uint16_t fieldId = ntohs(l_ffdcUserDataId.fieldId);
                uint16_t fieldLen = ntohs(l_ffdcUserDataId.fieldLen);

                if((l_buflen < fieldLen) &&
                    (fieldId != SBE_FFDC_TRACE_DATA))
                {
                    i_parser.PrintHexDump(l_pBuffer, l_buflen);
                    break;
                }

                l_buflen -= fieldLen;
                l_pBuffer += fieldLen;
                l_mem.read(l_buffer, fieldLen);
                std::ostringstream  l_strFile;
                //Generate temp dump file name
                l_strFile << ODY_SBE_TEMP_DUMP_FILE;

                //Write dump into the temporary file
                UtilFile l_fileObj(l_strFile.str().c_str());
                errlHndl_t l_errlHndl = l_fileObj.open("w");
                if ( l_errlHndl )
                {
                    std::cerr << "Error opening "
                              << l_strFile.str() << std::endl;
                    l_errlHndl->commit(HWSV_COMP_ID, ERRL_ACTION_REPORT);
                    delete l_errlHndl;
                    l_errlHndl = NULL;
                    i_parser.PrintHexDump(l_buffer, fieldLen);
                    break;
                }
                else
                {
                    l_fileObj.write( l_buffer, fieldLen);
                    l_fileObj.Close();
                }

                if(fieldId == SBE_FFDC_TRACE_DATA)
                {
                    ODY_SBE_PARSER_PRINT_HEADING(ODY_SBE_TRACE_HEADLINE)
                    //command
                    std::ostringstream  l_strCmd1, l_strCmd2;
                    // ppe2fsp <trace dump file> <trace bin file> 2>&1
                    l_strCmd1 << SbeIoOdyFfdcErrlParser::findSbeFile(PPE2FSP_TOOL)
                              << " "
                              << l_strFile.str().c_str()
                              << " "
                              << ODY_SBE_TRACE_BIN
                              << " "
                              << "2>&1";

                    // fsp-trace -s <sbe string file> <trace bin file> 2>&1
                    l_strCmd2 << ODY_SBE_TRACE_CMD
                              << " "
                              << SbeIoOdyFfdcErrlParser::findSbeFile(ODY_SBE_STRING_FILE)
                              << " "
                              << SBE_TRACE_BIN
                              << " "
                              << "2>&1";

                    //Call out the commands
                    SbeIoOdyFfdcErrlParser::sbeParserSysCall( l_strCmd1.str().c_str() );
                    SbeIoOdyFfdcErrlParser::sbeParserSysCall( l_strCmd2.str().c_str() );
                }

                //Delete the temp file
                l_fileObj.Remove();
            }
            l_dumpFields >>= 1;
            if(l_rc != 0)
            {
                break;
            }
        } // end while
    } while(false);

    } // end parse

private:
    // Disabled
    SbeIoOdyFfdcErrlParser(const SbeIoOdyFfdcErrlParser&);
    SbeIoOdyFfdcErrlParser & operator=(const SbeIoOdyFfdcErrlParser&);

    std::string findSbeFile(const char *name) const
    {
        std::string tmp = getenv("PATH");
#ifdef CONTEXT_x86_nfp
        char *bb = getenv("bb");
        if(bb != NULL)
        {
            std::string bbstr(bb);
            tmp += ":" + bbstr + "/src/sbei/sbfw/img" +
                  ":" + bbstr + "/obj/x86.nfp/sbei/sbfw/simics" +
                  ":" + bbstr + "/obj/ppc/hwsv/server/buildhwpfimport/hwpf2/tools/x86_binaries";
        }
#endif
#ifdef CONTEXT_ppc
        tmp += ":/nfs:/maint";
#endif
        char *path = strdup(tmp.c_str());
        char *dir = NULL;

        std::string file;

        struct  stat    l_stat;

        for(dir = strtok( path, ":" ); dir; dir = strtok(NULL, ":"))
        {
            file = file + dir + "/" +  name;

            if(stat(file.c_str(), &l_stat) < 0)
            {
                // String file not found, go to next one
                file.clear();
            }
            else
            {
                // update where trexStringFile is
                break;
            }
        }

        free(path);
        path = NULL;        //sm05c

        return file;
    } // end findSbeFile

    void sbeParserSysCall(const char *cmd) const
    {
        FILE *stream;
        char buffer[256];

        stream = popen(cmd, "r" );
        if(stream)
        {
            while(!feof(stream))
            {
                if(fgets(buffer, 256, stream) != NULL)
                {
                   std::cout << buffer;
                }
            }
        }
        else
        {
            std::cout << "command failed :[" << cmd << "]" << std::endl;
            std::cout << "errno [" << errno << "]" << std::endl;
        }
    } // end sbeParserSysCall

}; // end class SbeIoOdyFfdcErrlParser

/**
 * @class SbeIoFfdcErrlParser
 *
 */
class SbeIoFfdcErrlParser : public ERRORLOG::ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    SbeIoFfdcErrlParser() {}

    /**
     *  @brief Destructor
     */
    virtual ~SbeIoFfdcErrlParser() {}

    /**
     *  @brief Parses string user detail data from an error log
     *
     *  @param  i_version Version of the data
     *  @param  i_parse   ErrlUsrParser object for outputting information
     *  @param  i_pBuffer Pointer to buffer containing detail data
     *  @param  i_buflen  Length of the buffer
     */

    virtual void parse(errlver_t i_version,
                       ErrlUsrParser & i_parser,
                       void * i_pBuffer,
                       const uint32_t i_buflen) const
    {
        int l_rc = 0;
        uint32_t fapiRc = 0;
        sbeFFDCDataHeader_t l_pData = {0};
        char l_buffer[SBE_PARSER_MAX_LOCAL_BUFFER] = {0};
        char *l_pBuffer = (char*)i_pBuffer;
        uint32_t l_buflen = i_buflen;

        do
        {
            if(i_pBuffer == NULL)
            {
                l_rc = -1;
                break;
            }
            //seek l_mem to the binary blob of FFDC package
            UtilMem l_mem(const_cast<void*>(i_pBuffer),i_buflen);

            // The data is a buffer of SBE FFDC data
            i_parser.PrintHeading("SBE FFDC Parser");

            if(l_buflen < sizeof(fapiRc))
            {
                i_parser.PrintHexDump(l_pBuffer, l_buflen);
                break;
            }
            l_buflen -= sizeof(fapiRc);
            l_pBuffer += sizeof(fapiRc);
            l_mem >> fapiRc;
            i_parser.PrintNumber("FAPI RC ", "0x%08X", ntohl(fapiRc));

            if(l_buflen < sizeof(l_pData))
            {
                i_parser.PrintHexDump(l_pBuffer, l_buflen);
                break;
            }
            l_buflen -= sizeof(l_pData);
            l_pBuffer += sizeof(l_pData);
            l_mem >> l_pData;

            i_parser.PrintNumber("Primary Status ", "0x%04X",
                   (uint16_t)ntohs(l_pData.primaryStatus));
            i_parser.PrintNumber("Secondary Status ", "0x%04X",
                   (uint16_t)ntohs(l_pData.secondaryStatus));
            i_parser.PrintNumber("FW Commit ID ", "0x%08X",
                   (uint32_t)ntohl(l_pData.fwCommitID));
            if(ntohl(l_pData.ddLevel) == SBE_FFDC_DD2)
            {
                SBE_SEEPROM_BIN = "sbe_seeprom_DD2.bin";
            }
            //loop through the number of fields configured
            uint32_t *data = (uint32_t *)&l_pData.dumpFields;
            *data = ntohl(*data);
            uint32_t l_dumpFields = l_pData.dumpFields.get();
            while(l_dumpFields && !l_rc)
            {
                if(l_dumpFields & 0x0001)
                {
                    if(l_buflen < sizeof(uint32_t))
                    {
                        //Complete this loop and let the tools print as much data
                        //as possible but break from next loop
                        l_rc = -1;
                    }
                    sbeFFDCUserDataIdentifier_t l_ffdcUserDataId = {0};
                    l_buflen -= sizeof(uint32_t); //l_ffdcUserDataId
                    l_pBuffer += sizeof(uint32_t); //l_ffdcUserDataId

                    l_mem >> l_ffdcUserDataId;

                    // TODO via RTC:158462 continue even for attribute dump
                    // Need to extend p9_xip_tool for partial attr dump handling
                    uint16_t fieldLen = ntohs(l_ffdcUserDataId.fieldLen);
                    uint16_t fieldId = ntohs(l_ffdcUserDataId.fieldId);

                    if((l_buflen < fieldLen) &&
                       (fieldId != SBE_FFDC_TRACE_DUMP))
                    {
                        i_parser.PrintHexDump(l_pBuffer, l_buflen);
                        break;
                    }

                    l_buflen -= fieldLen;
                    l_pBuffer += fieldLen;

                    l_mem.read(l_buffer, fieldLen);
                    std::ostringstream  l_strFile;
                    //Generate temp dump file name
                    l_strFile << SBE_TEMP_DUMP_FILE;

                    //Write dump into the temporary file
                    UtilFile l_fileObj(l_strFile.str().c_str());
                    errlHndl_t l_errlHndl = l_fileObj.open("w");
                    if ( l_errlHndl )
                    {
                        std::cerr << "Error opening "
                                 << l_strFile.str() << std::endl;
                        l_errlHndl->commit(HWSV_COMP_ID, ERRL_ACTION_REPORT);
                        delete l_errlHndl;
                        l_errlHndl = NULL;
                        i_parser.PrintHexDump(l_buffer, fieldLen);
                        break;
                    }
                    else
                    {
                        l_fileObj.write( l_buffer, fieldLen);
                        l_fileObj.Close();
                    }
                    //Specific handling
                    if(fieldId == SBE_FFDC_ATTR_DUMP)
                    {
                        SBE_PARSER_PRINT_HEADING(SBE_ATTR_DUMP_HEADLINE)
                        //command
                        std::ostringstream  l_strCmd1;
                        // p9_xip_tool <sbe seeprom bin file>
                        // -ifs attrdump <attr dump file> 2>&1
                        l_strCmd1 << findSbeFile(P9_XIP_TOOL)
                                 << " "
                                 << findSbeFile(SBE_SEEPROM_BIN.c_str())
                                 << " "
                                 << P9_XIP_ATTR_CMD
                                 << " "
                                 << l_strFile.str().c_str()
                                 << " "
                                 << "2>&1";

                        //Call out the command
                        sbeParserSysCall( l_strCmd1.str().c_str() );
                    }
                    else if(fieldId == SBE_FFDC_TRACE_DUMP)
                    {
                        SBE_PARSER_PRINT_HEADING(SBE_TRACE_HEADLINE)
                        //command
                        std::ostringstream  l_strCmd1, l_strCmd2;
                        // ppe2fsp <trace dump file> <trace bin file> 2>&1
                        l_strCmd1 << findSbeFile(PPE2FSP_TOOL)
                                 << " "
                                 << l_strFile.str().c_str()
                                 << " "
                                 << SBE_TRACE_BIN
                                 << " "
                                 << "2>&1";

                        // fsp-trace -s <sbe string file> <trace bin file> 2>&1
                        l_strCmd2 << SBE_TRACE_CMD
                                 << " "
                                 << findSbeFile(SBE_STRING_FILE)
                                 << " "
                                 << SBE_TRACE_BIN
                                 << " "
                                 << "2>&1";

                        //Call out the commands
                        sbeParserSysCall( l_strCmd1.str().c_str() );
                        sbeParserSysCall( l_strCmd2.str().c_str() );
                    }

                    //Delete the temp file
                    l_fileObj.Remove();
                }
                l_dumpFields >>= 1;
                if(l_rc != 0)
                {
                    break;
                }
            }
        } while(false);
    }

private:
    // Disabled
    SbeIoFfdcErrlParser(const SbeIoFfdcErrlParser&);
    SbeIoFfdcErrlParser & operator=(const SbeIoFfdcErrlParser&);

    std::string findSbeFile(const char *name) const
    {
        std::string tmp = getenv("PATH");
#ifdef CONTEXT_x86_nfp
        char *bb = getenv("bb");
        if(bb != NULL)
        {
            std::string bbstr(bb);
            tmp += ":" + bbstr + "/src/sbei/sbfw/img" +
                  ":" + bbstr + "/obj/x86.nfp/sbei/sbfw/simics" +
                  ":" + bbstr + "/obj/ppc/hwsv/server/buildhwpfimport/hwpf2/tools/x86_binaries";
        }
#endif
#ifdef CONTEXT_ppc
        tmp += ":/nfs:/maint";
#endif
        char *path = strdup(tmp.c_str());
        char *dir = NULL;

        std::string file;

        struct  stat    l_stat;

        for(dir = strtok( path, ":" ); dir; dir = strtok(NULL, ":"))
        {
            file = file + dir + "/" +  name;

            if(stat(file.c_str(), &l_stat) < 0)
            {
                // String file not found, go to next one
                file.clear();
            }
            else
            {
                // update where trexStringFile is
                break;
            }
        }

        free(path);
        path = NULL;        //sm05c

        return file;
    }

    void sbeParserSysCall(const char *cmd) const
    {
        FILE *stream;
        char buffer[256];

        stream = popen(cmd, "r" );
        if(stream)
        {
            while(!feof(stream))
            {
                if(fgets(buffer, 256, stream) != NULL)
                {
                   std::cout << buffer;
                }
            }
        }
        else
        {
            std::cout << "command failed :[" << cmd << "]" << std::endl;
            std::cout << "errno [" << errno << "]" << std::endl;
        }
    }
};

/**
 * @class UdParserSPPECodeLevels
 *
 * Parses UdSPPECodeLevels
 */
class UdParserSPPECodeLevels : public ERRORLOG::ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    UdParserSPPECodeLevels() {}

    /**
     *  @brief Destructor
     */
    virtual ~UdParserSPPECodeLevels() {}

    /**
     *  @brief Parses string user detail data from an error log
     *
     *  @param  i_version Version of the data
     *  @param  i_parse   ErrlUsrParser object for outputting information
     *  @param  i_pBuffer Pointer to buffer containing detail data
     *  @param  i_buflen  Length of the buffer
     */
    virtual void parse(errlver_t i_version,
                       ErrlUsrParser & i_parser,
                       void * i_pBuffer,
                       const uint32_t i_buflen) const
    {
        char* l_databuf = static_cast<char*>(i_pBuffer);
        i_parser.PrintHeading("SPPE Code Levels");

        //***** Memory Layout *****
        // 4 bytes  : OCMB HUID
        // 4 bytes  : ATTR_SBE_VERSION_INFO
        // 4 bytes  : ATTR_SBE_COMMIT_ID
        // 64 bytes : ATTR_SBE_BOOTLOADER_CODELEVEL
        // 64 bytes : ATTR_SBE_RUNTIME_CODELEVEL
        // 21 bytes : ATTR_SBE_RELEASE_TAG
        // 21 bytes : ATTR_SBE_BUILD_TAG
        // 21 bytes : ATTR_SBE_EKB_BUILD_TAG

        i_parser.PrintNumber("OCMB HUID",
                             "%.8lX", TO_UINT32(l_databuf));
        l_databuf += sizeof(uint32_t);

        i_parser.PrintNumber("ATTR_SBE_VERSION_INFO",
                             "%.8lX", TO_UINT32(l_databuf));
        l_databuf += sizeof(uint32_t);

        i_parser.PrintNumber("ATTR_SBE_COMMIT_ID",
                             "%.8lX", TO_UINT32(l_databuf));
        l_databuf += sizeof(uint32_t);

        for (uint32_t l_byte = 0; l_byte < 16; l_byte++)
        {
            i_parser.PrintNumber("ATTR_SBE_BOOTLOADER_CODELEVEL",
                                 "%.8X", TO_UINT32(l_databuf));
            l_databuf += sizeof(uint32_t);
        }

        for (uint32_t l_byte = 0; l_byte < 16; l_byte++)
        {
            i_parser.PrintNumber("ATTR_SBE_RUNTIME_CODELEVEL",
                                 "%.8X", TO_UINT32(l_databuf));
            l_databuf += sizeof(uint32_t);
        }

        i_parser.PrintString("ATTR_SBE_RELEASE_TAG", l_databuf);
        l_databuf += SPPE_LEVEL_ATTR_MAX_STRING_SIZE + 1; // null terminator

        i_parser.PrintString("ATTR_SBE_BUILD_TAG", l_databuf);
        l_databuf += SPPE_LEVEL_ATTR_MAX_STRING_SIZE + 1; // null terminator

        i_parser.PrintString("ATTR_SBE_EKB_BUILD_TAG", l_databuf);
        l_databuf += SPPE_LEVEL_ATTR_MAX_STRING_SIZE + 1; // null terminator
    }

private:
    // Disabled
    UdParserSPPECodeLevels(const UdParserSPPECodeLevels&);
    UdParserSPPECodeLevels & operator=(const UdParserSPPECodeLevels&);
};


} // end namespace

#endif
