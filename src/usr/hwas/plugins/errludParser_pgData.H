/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/plugins/errludParser_pgData.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
            if (i_version > HWAS_UDT_VERSION_1)
            {
                i_parser.PrintHeading("HWAS PG FFDC: Unknown Version (too new)");
            }
            else
            {
                const int OUTPUT_STRING_LENGTH = 64;
                char l_outputString[OUTPUT_STRING_LENGTH]={0};

                i_parser.PrintHeading("HWAS PG FFDC");

                // Our local copy of the AG vector, which we will update with
                // the model-specific AG values as we extract them below. We
                // then take this AGV and compare it against the PG values we
                // extract, to see which ones differ.
                partialGoodVector l_pgDataAG;

                memcpy(&l_pgDataAG, &pgDataAllGood, sizeof(pgDataAllGood));

                const uint32_t* l_iterator = static_cast<uint32_t*>(i_pBuffer);

                // Extract the model-specific AG values and put them into
                // l_pgDataAG at their proper locations
                {
                    const uint32_t l_num_ag_entries
                        = ERRORLOG::NTH_UINT32(l_iterator);

                    ++l_iterator;

                    for (uint32_t i = 0; i < l_num_ag_entries; ++i)
                    {
                        const uint32_t l_model_ag_index
                            = ERRORLOG::NTH_UINT32(l_iterator);
                        ++l_iterator;
                        const uint32_t l_model_ag_value
                            = ERRORLOG::NTH_UINT32(l_iterator);
                        ++l_iterator;

                        if (l_model_ag_index < VPD_CP00_PG_DATA_ENTRIES)
                        {
                            l_pgDataAG[l_model_ag_index] = l_model_ag_value;
                        }
                        else
                        {
                            sprintf(l_outputString,
                                    "Model-specific AG value "
                                    "out of bounds: [%u] = 0x%08x",
                                    l_model_ag_index, l_model_ag_value);

                            i_parser.PrintString("Error", l_outputString);
                        }
                    }
                }

                // Extract the PG values and compare them against our AG vector
                {
                    const uint32_t l_num_pg_entries
                        = ERRORLOG::NTH_UINT32(l_iterator);

                    ++l_iterator;

                    if (l_num_pg_entries != VPD_CP00_PG_DATA_ENTRIES)
                    {
                        sprintf(l_outputString,
                                "Expected %u PG entries, got %u",
                                static_cast<uint32_t>(VPD_CP00_PG_DATA_ENTRIES),
                                l_num_pg_entries);
                        i_parser.PrintString("Error", l_outputString);
                    }
                    else
                    {
                        for (size_t i = 0; i < VPD_CP00_PG_DATA_ENTRIES; ++i)
                        {
                            const pg_entry_t l_pgValue
                                = ERRORLOG::NTH_UINT32(l_iterator);

                            ++l_iterator;

                            sprintf(l_outputString,
                                    "pgData[%d] = 0x%08x; expected 0x%08x",
                                    i, l_pgValue, l_pgDataAG[i]);

                            i_parser.PrintString((l_pgValue == l_pgDataAG[i]
                                                  ? "" : "Bad"),
                                                 l_outputString);
                        }
                    }
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
