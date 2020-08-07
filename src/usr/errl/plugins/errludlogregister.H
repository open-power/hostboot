/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/plugins/errludlogregister.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2020                        */
/* [+] Google Inc.                                                        */
/* [+] International Business Machines Corp.                              */
/* [+] YADRO                                                              */
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
#ifndef ERRL_UDLOGREGISTER_H
#define ERRL_UDLOGREGISTER_H

/**
 *  @file errludlogregister.H
 *
 *  Defines the ErrlUserDetailsParserLogRegister class that parses register FFDC
 *  user detail in an error log
 */

#include "errluserdetails.H"

#include <../devicefw/userif.H>
#include <../devicefw/driverif.H>

namespace ERRORLOG
{

/**
 * @class ErrlUserDetailsLogRegister
 *
 * Parses LogRegister user detail in an error log
 */
class ErrlUserDetailsParserLogRegister : public ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    ErrlUserDetailsParserLogRegister() {}

    /**
     *  @brief Destructor
     */
    virtual ~ErrlUserDetailsParserLogRegister() {}

    /**
     *  @brief Parses register user detail data from an error log
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
        uint8_t *pBuf = reinterpret_cast<uint8_t *>(i_pBuffer);

        // while there is still at least 1 word of data left
        for (; (pBuf + sizeof(uint32_t)) <= ((uint8_t*)i_pBuffer + i_buflen); )
        {
            // first is the HUID
            uint32_t *pData = reinterpret_cast<uint32_t *>(pBuf);
            if (ntohl(UINT32_FROM_PTR(pData)) == 0xFFFFFFFF)
            {
                i_parser.PrintString("LogRegister",
                            "Target: MASTER_PROCESSOR_CHIP_TARGET_SENTINEL");
            }
            else
            {
                i_parser.PrintNumber( "LogRegister",
                            "Target: HUID = 0x%08X", ntohl(UINT32_FROM_PTR(pData)) );
            }
            pData++;
            pBuf += sizeof(*pData);

            // next is the count of registers to dump
            const uint8_t count = *pBuf;
            pBuf++;

            for (uint32_t i = 0; i < count;i++)
            {
                // format of data in the buffer is:
                // i_accessType, regParam[i], uint8_t(i_dataSize), i_dataBuf
                uint8_t l_accessType = *pBuf;
                pBuf++;
                int32_t numArgs = -1;
                std::vector <const char *> addrParams;
                switch (l_accessType)
                {
                    // one parameter
                    case DeviceFW::SCOM:        // userif.H
                        i_parser.PrintString("AccessType", "DeviceFW::SCOM");
                        numArgs = 1;
                        addrParams.push_back("  Scom address");
                        break;
                    case DeviceFW::FSI:         // userif.H
                        i_parser.PrintString("AccessType", "DeviceFW::FSI");
                        numArgs = 1;
                        addrParams.push_back("  FSI address");
                        break;
                    case DeviceFW::SPD:         // userif.H
                        i_parser.PrintString("AccessType", "DeviceFW::SPD");
                        numArgs = 1;
                        addrParams.push_back("  SPD keyword enumaration");
                        break;
                    case DeviceFW::XSCOM:       // driverif.H
                        i_parser.PrintString("AccessType", "DeviceFW::XSCOM");
                        numArgs = 1;
                        addrParams.push_back("  XScom address");
                        break;
                    case DeviceFW::FSISCOM:     // driverif.H
                        i_parser.PrintString("AccessType", "DeviceFW::FSISCOM");
                        numArgs = 1;
                        addrParams.push_back("  FSISCOM address");
                        break;
                    // two parameters
                    case DeviceFW::MVPD:        // userif.H
                        i_parser.PrintString("AccessType", "DeviceFW::MVPD");
                        numArgs = 2;
                        addrParams.push_back("  MVPD record");
                        addrParams.push_back("  MVPD keyword");
                        break;
                    case DeviceFW::EEPROM:      // driverif.H
                        i_parser.PrintString("AccessType", "DeviceFW::EEPROM");
                        numArgs = 2;
                        addrParams.push_back("  I2C slave device address");
                        addrParams.push_back("  EEPROM chip number");
                        break;
                    case DeviceFW::LPC:     // driverif.H
                        i_parser.PrintString("AccessType", "DeviceFW::LPC");
                        i_parser.PrintString("Ranges",
                                             "0=IO,1=MEM,2=FW,3=REG,4=ABS");
                        numArgs = 2;
                        addrParams.push_back("  Range");
                        addrParams.push_back("  Addr");
                        break;
                    // three parameters
                    case DeviceFW::I2C:         // driverif.H
                        i_parser.PrintString("AccessType", "DeviceFW::I2C");
                        numArgs = 3;
                        addrParams.push_back("  I2C port");
                        addrParams.push_back("  I2C master engine");
                        addrParams.push_back("  Device address");
                        break;
                    // not logged!
                    case DeviceFW::PRESENT:     // userif.H
                        i_parser.PrintString("AccessType", "DeviceFW::PRESENT "
                                                    "- not logged");
                        break;
                    case DeviceFW::PNOR:        // userif.H
                        i_parser.PrintString("AccessType", "DeviceFW::PNOR "
                                                    "- not logged");
                        break;
                    case DeviceFW::MAILBOX:     // userif.H
                        i_parser.PrintString("AccessType", "DeviceFW::MAILBOX "
                                                    "- not logged");
                        break;
                    case DeviceFW::SCAN:     // userif.H
                        i_parser.PrintString("AccessType", "DeviceFW::SCAN "
                                                    "- not logged");
                        break;
                    case DeviceFW::IBSCOM:     // userif.H
                        i_parser.PrintString("AccessType", "DeviceFW::IBSCOM "
                                                    "- not logged");
                        break;
                    case DeviceFW::SPI_EEPROM: // driverif.H
                        i_parser.PrintString("AccessType", "DeviceFW::SPI_EEPROM "
                                                    "- not logged");
                        break;
                    case DeviceFW::SPI_TPM:    // driverif.H
                        i_parser.PrintString("AccessType", "DeviceFW::SPI_TPM "
                                                    "- not logged");
                        break;
                    default:
                        i_parser.PrintNumber("AccessType", "UNKNOWN 0x%X"
                                                    "- not logged",
                                                    l_accessType);
                        break;
                } // switch l_accessType

                if (numArgs != -1)
                {
                    uint64_t *pData64 = reinterpret_cast<uint64_t *>(pBuf);
                    for (int32_t i = 0;i < numArgs;i++)
                    {
                        std::vector<char> l_traceEntry(20);
                        sprintf(&(l_traceEntry[0]),"0x%016llX", ntohll(UINT64_FROM_PTR(pData64)));
                        i_parser.PrintString(addrParams[i], &(l_traceEntry[0]));

                        pData64++;
                        pBuf += sizeof(*pData64);
                    }
                    const uint8_t dataSize = *pBuf;
                    i_parser.PrintNumber("  Register data", "size: 0x%X bytes",
                                            dataSize);
                    pBuf++;

                    pData64 = reinterpret_cast<uint64_t *>(pBuf);
                    i_parser.PrintHexDump( pData64, dataSize);
                    pBuf += dataSize;
                } // numArgs
            } // for count
        } // for
    } // parse

private:
    // Disabled
    ErrlUserDetailsParserLogRegister(const ErrlUserDetailsParserLogRegister &);
    ErrlUserDetailsParserLogRegister & operator=(
        const ErrlUserDetailsParserLogRegister &);
};

}

#endif

