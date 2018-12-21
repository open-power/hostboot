/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/plugins/errludParser_pgData.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#ifndef ERRLUDPARSER_PGDATA_H
#define ERRLUDPARSER_PGDATA_H

#include "errluserdetails.H"
#include <targeting/common/utilFilter.H>
#include "../hwas/common/vpdConstants.H"
#include "../hwas/common/hwas_reasoncodes.H"

namespace HWAS
{
    class UdParserPartialGoodIssue : public ERRORLOG::ErrlUserDetailsParser
    {
    public:

        UdParserPartialGoodIssue()
        {
        }

        ~UdParserPartialGoodIssue()
        {
        }

        /**
        *  @brief Parses user detail data from an error log
        *
        *  Parses the supplied user detail data and outputs info to i_parser.
        *
        *  @param  i_version      Version of the data
        *
        *  @param  i_parse        ErrlUsrParser object for outputting
        *                         information
        *
        *  @param  i_pBuffer      Pointer to buffer containing detail data
        *
        *  @param  i_buflen       Length of the buffer
        *
        */
        virtual void parse(errlver_t       i_version,
                           ErrlUsrParser&  i_parser,
                           void *          i_pBuffer,
                           const uint32_t  i_buflen) const
        {
            if (i_version < HWAS_UDT_VERSION_1)
            {
                i_parser.PrintHeading("HWAS PG FFDC: Unknown Version");
            }
            else
            {
                i_parser.PrintHeading("HWAS PG FFDC");

                // Get the correct all good values for the chip from the buffer.
                const uint16_t* pData =
                    reinterpret_cast<const uint16_t*>(i_pBuffer);

                uint16_t l_xbus = ERRORLOG::NTH_UINT16(pData);

                ++pData;

                uint16_t l_obus = ERRORLOG::NTH_UINT16(pData);

                ++pData;

                // Buffer with all good data. All of the following constants are
                // defined within vpdConstants.H
                const uint16_t pgDataAllGood[VPD_CP00_PG_DATA_ENTRIES] =
                    {static_cast<uint16_t>(VPD_CP00_PG_FSI_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_PERVASIVE_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_N0_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_N1_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_N2_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_N3_GOOD),
                    l_xbus,
                    static_cast<uint16_t>(VPD_CP00_PG_MCxx_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_MCxx_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_OBUS_GOOD),
                    l_obus,
                    l_obus,
                    static_cast<uint16_t>(VPD_CP00_PG_OBUS_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_PCIx_GOOD[0]),
                    static_cast<uint16_t>(VPD_CP00_PG_PCIx_GOOD[1]),
                    static_cast<uint16_t>(VPD_CP00_PG_PCIx_GOOD[2]),
                    static_cast<uint16_t>(VPD_CP00_PG_EPx_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_EPx_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_EPx_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_EPx_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_EPx_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_EPx_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_RESERVED_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_RESERVED_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_RESERVED_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_RESERVED_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_RESERVED_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_RESERVED_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_RESERVED_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_RESERVED_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_RESERVED_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_RESERVED_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_ECxx_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_ECxx_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_ECxx_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_ECxx_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_ECxx_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_ECxx_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_ECxx_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_ECxx_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_ECxx_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_ECxx_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_ECxx_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_ECxx_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_ECxx_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_ECxx_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_ECxx_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_ECxx_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_ECxx_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_ECxx_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_ECxx_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_ECxx_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_ECxx_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_ECxx_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_ECxx_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_ECxx_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_RESERVED_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_RESERVED_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_RESERVED_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_RESERVED_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_RESERVED_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_RESERVED_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_RESERVED_GOOD),
                    static_cast<uint16_t>(VPD_CP00_PG_RESERVED_GOOD)};

                const int OUTPUT_STRING_LENGTH = 38;
                const int LABEL_STRING_LENGTH = 4;
                char l_outputString[OUTPUT_STRING_LENGTH]={0},
                     l_labelString[LABEL_STRING_LENGTH]={0};

                for (size_t i = 0; i < VPD_CP00_PG_DATA_ENTRIES; ++i)
                {
                    uint16_t pgValue = ERRORLOG::NTH_UINT16(pData + i);

                    sprintf(l_outputString,
                            "pgData[%d] = 0x%04x; expected 0x%04x",
                            i, pgValue, pgDataAllGood[i]);

                    sprintf(l_labelString,
                            "%s",
                            (pgDataAllGood[i] & pgValue == pgDataAllGood[i])
                            ? "" : "Bad");

                    i_parser.PrintString(l_labelString, l_outputString);

                }
            }
        }

    private:
        // Parser isn't compiled with c++11 in all environments, and
        // therefore "delete" of unused interfaces (like below) is not
        // supported, nor are functions with move semantics
        // Disable compiler provided default functions
        UdParserPartialGoodIssue(const UdParserPartialGoodIssue&);
        UdParserPartialGoodIssue& operator=(const UdParserPartialGoodIssue&);
    };
}

#endif
