/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/plugins/errludP_htmgt.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2022                        */
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
#ifndef ERRL_UDP_HTMGT_H
#define ERRL_UDP_HTMGT_H

/**
*  @file errludP_htmgt.H
*
*  Defines the ErrlUserDetailsParser classes that parse HTMGT FFDC
*/

#include "errluserdetails.H"
#include <string.h>

/**
* Macros required when parser runs on x86
*/
#define TO_UINT8(ptr)   (*(reinterpret_cast<uint8_t*>(ptr)))
#define TO_UINT16(ptr)  (ntohs(*(reinterpret_cast<uint16_t*>(ptr))))
#define TO_UINT32(ptr)  (ntohl(*(reinterpret_cast<uint32_t*>(ptr))))
#define TO_UINT64(ptr)  (ntohll(*(reinterpret_cast<uint64_t*>(ptr))))



namespace HTMGT
{
    // Already in HTMGT
    enum tmgtElogSubsecTypes
    {
        // Values selected to be common with FSP from tmgt_elog_parser.H
        //SUBSEC_MSG_DATA_TYPE          = 0x01,
        //SUBSEC_ERROR_DATA_TYPE        = 0x06,
        //SUBSEC_ENERGYSCALE_DATA_TYPE  = 0x08,
        //SUBSEC_OCC_ELOG_DATA_TYPE     = 0x0A,
        //SUBSEC_OCC_FFDC_DATA_TYPE     = 0x0B,
        SUBSEC_ADDITIONAL_SRC         = 0x0C,
        SUBSEC_OCC_CMD_DATA           = 0x0D,
        SUBSEC_OCC_RSP_DATA           = 0x0E,
        SUBSEC_ELOG_TYPE_HTMGT_DATA   = 0x10,
        //SUBSEC_ELOG_TYPE_OCC_RESET    = 0x11,
        //SUBSEC_ELOG_TYPE_PCAP_DATA    = 0x12,
        //SUBSEC_ELOG_TYPE_THERMAL_DATA = 0x13,
        //SUBSEC_PROC_SCOM_REGISTERS    = 0x14,
        //SUBSEC_ELOG_TYPE_OCC_TRACE    = 0x15,
        // 0xE0-0xEF are reserved for OCC Exceptions
    };
    // END Already in HTMGT

    struct occStateData
    {
        uint8_t  instance;
        uint8_t  state;
        uint8_t  role;
        uint8_t  masterCapable;
        uint8_t  commEstablished;
        uint8_t  mode;
        uint8_t  reserved[2];
        uint8_t  failed;
        uint8_t  needsReset;
        uint8_t  resetReason;
        uint8_t  resetCountWof:4;
        uint8_t  resetCount:4;
        uint32_t lastPollHeader;
    } __attribute__ ((__packed__));
    typedef struct occStateData occData_t;

    struct htmgtStateData
    {
        // HTMGT specific data
        uint8_t numOccs;
        uint8_t masterInstance;
        uint8_t state;
        uint8_t targetState;
        uint8_t sysResetCount;
        uint8_t cumulativeResets;
        uint8_t mode;
        uint8_t safeMode;
        uint32_t safeReturnCode;
        uint32_t safeOccInstance;

        // Now add OCC specific data (for each OCC)
        occData_t occData[8];
    } __attribute__ ((__packed__));
    typedef struct htmgtStateData htmgtStateData_t;



    /**
    * @class UdParserHtmgtData
    *
    * Parses UdPibInfo
    */
    class UdParserHtmgtData : public ERRORLOG::ErrlUserDetailsParser
    {
        public:
            /**
            *  @brief Constructor
            */
            UdParserHtmgtData() {}

            /**
            *  @brief Destructor
            */
            virtual ~UdParserHtmgtData() {}

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
                htmgtStateData_t* hdata = static_cast<htmgtStateData_t*>
                    (i_pBuffer);
                i_parser.PrintString( "HTMGT", "" );
                i_parser.PrintNumber("  Number of OCCs", "%d", hdata->numOccs);
                i_parser.PrintNumber("  Master OCC", "%d",
                                     hdata->masterInstance);
                i_parser.PrintNumber("  State", "0x%02X", hdata->state);
                i_parser.PrintNumber("  Target State", "0x%02X",
                                     hdata->targetState);
                i_parser.PrintNumber("  HTMGT triggered resets", "%d",
                                     hdata->sysResetCount);
                i_parser.PrintNumber("  Resets since power on", "%d",
                                     hdata->cumulativeResets);
                i_parser.PrintNumber("  Mode", "0x%02X", hdata->mode);
                // Don't display if not in safe mode because the flag may not be
                //   set at the time this data is added to an error log
                if (hdata->safeMode)
                {
                    i_parser.PrintBool(  "  In Safe Mode", hdata->safeMode);
                    i_parser.PrintNumber("    Safe Reason Code", "0x%04X",
                                         TO_UINT32(&hdata->safeReturnCode));
                    i_parser.PrintNumber("    Safe OCC Instance", "%d",
                                         TO_UINT32(&hdata->safeOccInstance));
                }
                for (unsigned int instance = 0;
                     instance < hdata->numOccs;
                     ++instance)
                {
                    occData_t *odata = &hdata->occData[instance];
                    char occ_name[16];
                    sprintf(occ_name, "OCC%d", odata->instance);
                    i_parser.PrintBlank();
                    i_parser.PrintString(occ_name, "" );
                    i_parser.PrintNumber("  Instance", "%d", odata->instance);
                    i_parser.PrintNumber("  State", "0x%02X", odata->state);
                    i_parser.PrintNumber("  Role", "0x%02X", odata->role);
                    i_parser.PrintBool(  "  Master Capable",
                                         odata->masterCapable);
                    i_parser.PrintBool(  "  Comm Established",
                                         odata->commEstablished);
                    i_parser.PrintBool(  "  Mode", odata->mode);
                    i_parser.PrintBool(  "  Failed", odata->failed);
                    i_parser.PrintBool(  "  Needs Reset", odata->needsReset);
                    i_parser.PrintNumber("  Reset Reason", "0x%02X",
                                         odata->resetReason);
                    i_parser.PrintNumber("  Reset Count", "%d",
                                         odata->resetCount);
                    i_parser.PrintNumber("  WOF Reset Count", "%d",
                                         odata->resetCountWof);
                    uint16_t status = TO_UINT16(&odata->lastPollHeader);
                    if ((status & 0x00FF) != 0)
                    {
                        char status_string[256] = "";
                        sprintf(status_string, "0x%08X -",
                                TO_UINT32(&odata->lastPollHeader));
                        if (status & 0x0080) strcat(status_string,
                                                    " Throttle-ProcOverTemp");
                        if (status & 0x0040) strcat(status_string,
                                                    " Throttle-Power");
                        if (status & 0x0020) strcat(status_string,
                                                    " MemThrot-OverTemp");
                        if (status & 0x0010) strcat(status_string,
                                                    " QuickPowerDrop");
                        if (status & 0x0008) strcat(status_string,
                                                    " Throttle-VddOverTemp");
                        i_parser.PrintString("  Last Poll Header",
                                             status_string);
                    }
                    else
                    {
                        i_parser.PrintNumber("  Last Poll Header", "0x%08X",
                                             TO_UINT32(&odata->lastPollHeader));
                    }
                }
            }

          private:

            // Parser isn't compiled with c++11 in all environments, and
            // therefore "delete" of unused interfaces (like below) is not
            // supported, nor are functions with move semantics

            // Disable compiler provided default functions
            UdParserHtmgtData(
                const UdParserHtmgtData&);
            UdParserHtmgtData & operator=(
                const UdParserHtmgtData&);
    };

}

#endif
