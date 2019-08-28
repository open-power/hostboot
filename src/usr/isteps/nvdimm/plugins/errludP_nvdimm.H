/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/nvdimm/plugins/errludP_nvdimm.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2019                        */
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
#ifndef ERRL_UDP_NVDIMM_H
#define ERRL_UDP_NVDIMM_H

/**
 *  @file errludP_nvdimm.H
 *
 *  Defines the ErrlUserDetailsParser classes that parse NVDIMM FFDC
 */

#include "errluserdetails.H"
#include <string.h>

/**
 * Some macros to manipulate data types cleanly
 */
#define TO_UINT8(ptr)   (*(reinterpret_cast<uint8_t*>(ptr)))
#define TO_UINT16(ptr)  (ntohs(*(reinterpret_cast<uint16_t*>(ptr))))
#define TO_UINT32(ptr)  (ntohl(*(reinterpret_cast<uint32_t*>(ptr))))
#define TO_UINT64(ptr)  (ntohll(*(reinterpret_cast<uint64_t*>(ptr))))

namespace NVDIMM
{

/**
 * @class UdParserNvdimmParms
 *
 * Parses UdNvdimmParms
 */
class UdParserNvdimmParms : public ERRORLOG::ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    UdParserNvdimmParms() {}

    /**
     *  @brief Destructor
     */
    virtual ~UdParserNvdimmParms() {}

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
        i_parser.PrintHeading("NVDIMM I2C Parameters");

        //***** Memory Layout *****
        // 1 byte   : Op Type Description
        // 1 byte   : Op Type (DeviceFW::OperationType)
        // 4 bytes  : Target HUID
        // 8 bytes  : Length of In/Out Buffer
        // 8 bytes  : Access Type (DeviceFW::AccessType)
        // 1 byte   : Port
        // 1 byte   : Engine
        // 8 bytes  : Device Address
        // 1 byte   : Flag: skip_mode_setup;
        // 1 byte   : Flag: with_stop;
        // 1 byte   : Flag: read_not_write;
        // 8 bytes  : Bus Speed (kbits/sec)
        // 2 bytes  : Bit Rate Divisor
        // 8 bytes  : Polling Interval in ns
        // 8 bytes  : Timeout Count;
        // 1 byte   : I2C MUX Bus Selector
        // N bytes  : I2C MUX path in string form

        uint8_t op = TO_UINT8(l_databuf);
        l_databuf += sizeof(uint8_t);

        if( op == 0 )
        {
            i_parser.PrintHeading("I2C Read");
        }
        else if( op == 1 )
        {
            i_parser.PrintHeading("I2C Write");
        }
        else
        {
            i_parser.PrintHeading("Unknown I2C Operation");
        }

        i_parser.PrintNumber("Op Type Value","%.2lX",TO_UINT8(l_databuf));
        l_databuf += sizeof(uint8_t);
        i_parser.PrintNumber("Target HUID","%.8lX",TO_UINT32(l_databuf));
        l_databuf += sizeof(uint32_t);
        i_parser.PrintNumber("Length I/O Buff","%.16lX",TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);
        i_parser.PrintNumber("Access Type","%.16lX",TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);
        i_parser.PrintNumber("Port","%.2lX",TO_UINT8(l_databuf));
        l_databuf += sizeof(uint8_t);
        i_parser.PrintNumber("Engine","%.2lX",TO_UINT8(l_databuf));
        l_databuf += sizeof(uint8_t);
        i_parser.PrintNumber("Device Address","%.16lX",TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);
        i_parser.PrintNumber("Flag: skip_mode_setup","%.2lX",
                             TO_UINT8(l_databuf));
        l_databuf += sizeof(uint8_t);
        i_parser.PrintNumber("Flag: with_stop","%.2lX",TO_UINT8(l_databuf));
        l_databuf += sizeof(uint8_t);
        i_parser.PrintNumber("Flag: read_not_write","%.2lX",
                             TO_UINT8(l_databuf));
        l_databuf += sizeof(uint8_t);
        i_parser.PrintNumber("Bus Speed (kbits/sec)","%.16lX",
                              TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);
        i_parser.PrintNumber("Bit Rate Divisor","%.4lX",TO_UINT16(l_databuf));
        l_databuf += sizeof(uint16_t);
        i_parser.PrintNumber("Polling Interval (ns)","%.16lX",
                              TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);
        i_parser.PrintNumber("Timeout Count","%.16lX",TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);

        if (i_version >= 2 )
        {
            i_parser.PrintNumber("I2C Mux Selector","%.2lX",TO_UINT8(l_databuf));
            l_databuf += sizeof(uint8_t);
            i_parser.PrintString("I2C Mux Path", l_databuf);
            // Increment past the NULL terminated string + 1 (null terminator)
            l_databuf += strlen(l_databuf) + 1;

        }
    }

private:
    // Disabled
    UdParserNvdimmParms(const UdParserNvdimmParms&);
    UdParserNvdimmParms & operator=(const UdParserNvdimmParms&);
};

/**
 * @class UdParserNvdimmOPParms
 *
 * Parses UdNvdimmOPParms
 */
class UdParserNvdimmOPParms : public ERRORLOG::ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    UdParserNvdimmOPParms() {}

    /**
     *  @brief Destructor
     */
    virtual ~UdParserNvdimmOPParms() = default;

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
        i_parser.PrintHeading("NVDIMM I2C Register Traces");

        //***** Memory Layout *****
        // 1 byte   : MODULE_HEALTH
        // 1 byte   : MODULE_HEALTH_STATUS0
        // 1 byte   : MODULE_HEALTH_STATUS1
        // 1 byte   : CSAVE_STATUS
        // 1 byte   : CSAVE_INFO
        // 1 byte   : CSAVE_FAIL_INFO0
        // 1 byte   : CSAVE_FAIL_INFO1
        // 1 byte   : CSAVE_TIMEOUT_INFO0
        // 1 byte   : CSAVE_TIMEOUT_INFO1
        // 1 byte   : ERROR_THRESHOLD_STATUS
        // 1 byte   : NVDIMM_READY
        // 1 byte   : NVDIMM_CMD_STATUS0
        // 1 byte   : ERASE_STATUS
        // 1 byte   : ERASE_TIMEOUT0
        // 1 byte   : ERASE_TIMEOUT1
        // 1 byte   : ABORT_CMD_TIMEOUT
        // 1 byte   : SET_ES_POLICY_STATUS
        // 1 byte   : RESTORE_STATUS
        // 1 byte   : RESTORE_FAIL_INFO
        // 1 byte   : RESTORE_TIMEOUT0
        // 1 byte   : RESTORE_TIMEOUT1
        // 1 byte   : ARM_STATUS
        // 1 byte   : ARM_TIMEOUT0
        // 1 byte   : ARM_TIMEOUT1
        // 1 byte   : SET_EVENT_NOTIFICATION_STATUS
        // 1 byte   : ENCRYPTION_CONFIG_STATUS
        //

        i_parser.PrintNumber("Module Health Register: ","%.2lX",TO_UINT8(l_databuf));
        ++l_databuf;
        i_parser.PrintNumber("Module Health Status0 Register: ","%.2lX",TO_UINT8(l_databuf));
        ++l_databuf;
        i_parser.PrintNumber("Module Health Status1 Register: ","%.2lX",TO_UINT8(l_databuf));
        ++l_databuf;
        i_parser.PrintNumber("CSave Status Register: ","%.2lX",TO_UINT8(l_databuf));
        ++l_databuf;
        i_parser.PrintNumber("CSave Info Register: ","%.2lX",TO_UINT8(l_databuf));
        ++l_databuf;
        i_parser.PrintNumber("CSave Fail Info0 Register: ","%.2lX",TO_UINT8(l_databuf));
        ++l_databuf;
        i_parser.PrintNumber("CSave Fail Info1 Register: ","%.2lX",TO_UINT8(l_databuf));
        ++l_databuf;
        i_parser.PrintNumber("CSave Timeout Info0 Register: ","%.2lX",TO_UINT8(l_databuf));
        ++l_databuf;
        i_parser.PrintNumber("CSave Timeout Info1 Register: ","%.2lX",TO_UINT8(l_databuf));
        ++l_databuf;
        i_parser.PrintNumber("Error Threshold Status Register: ","%.2lX",TO_UINT8(l_databuf));
        ++l_databuf;
        i_parser.PrintNumber("NVDIMM Ready Register: ","%.2lX",TO_UINT8(l_databuf));
        ++l_databuf;
        i_parser.PrintNumber("NVDIMM CMD Status0 Register: ","%.2lX",TO_UINT8(l_databuf));
        ++l_databuf;
        i_parser.PrintNumber("Erase Status Register: ","%.2lX",TO_UINT8(l_databuf));
        ++l_databuf;
        i_parser.PrintNumber("Erase Timeout0 Register: ","%.2lX",TO_UINT8(l_databuf));
        ++l_databuf;
        i_parser.PrintNumber("Erase Timeout1 Register: ","%.2lX",TO_UINT8(l_databuf));
        ++l_databuf;
        i_parser.PrintNumber("Abort CMD Timeout Register: ","%.2lX",TO_UINT8(l_databuf));
        ++l_databuf;
        i_parser.PrintNumber("Set ES Policy Status Register: ","%.2lX",TO_UINT8(l_databuf));
        ++l_databuf;
        i_parser.PrintNumber("Restore Status Register: ","%.2lX",TO_UINT8(l_databuf));
        ++l_databuf;
        i_parser.PrintNumber("Restore Fail Info0 Register: ","%.2lX",TO_UINT8(l_databuf));
        ++l_databuf;
        i_parser.PrintNumber("Restore Timeout0 Register: ","%.2lX",TO_UINT8(l_databuf));
        ++l_databuf;
        i_parser.PrintNumber("Restore Timeout1 Register: ","%.2lX",TO_UINT8(l_databuf));
        ++l_databuf;
        i_parser.PrintNumber("Arm Status Register: ","%.2lX",TO_UINT8(l_databuf));
        ++l_databuf;
        i_parser.PrintNumber("Arm Timeout0 Register: ","%.2lX",TO_UINT8(l_databuf));
        ++l_databuf;
        i_parser.PrintNumber("Arm Timeout1 Register: ","%.2lX",TO_UINT8(l_databuf));
        ++l_databuf;
        i_parser.PrintNumber("Set Event Notification Status Register: ","%.2lX",TO_UINT8(l_databuf));
        ++l_databuf;
        i_parser.PrintNumber("NVDIMM Encryption Configuration and Status Register: ","%.2lX",TO_UINT8(l_databuf));
        ++l_databuf;
    }

    // Disabled
    UdParserNvdimmOPParms(const UdParserNvdimmOPParms&) = delete;
    UdParserNvdimmOPParms & operator=(UdParserNvdimmOPParms &) = delete;
};

} // end NVDIMM namespace

#endif
