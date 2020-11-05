/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/plugins/errludwofdata.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2021                        */
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
#ifndef ERRL_UDWOFDATA_H
#define ERRL_UDWOFDATA_H

/**
 *  @file errludwofdata.H
 *
 *  Defines the ErrlUserDetailsWofData class that parses the
 *  WOF data user detail section of an error log
 */

#include "errluserdetails.H"
#include <targeting/common/target.H>

namespace ERRORLOG
{

/**
 * @class ErrlUserDetailsParserWofData
 *
 * Parses WOF data user detail in an error log
 */
class ErrlUserDetailsParserWofData : public ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    ErrlUserDetailsParserWofData() {}

    /**
     *  @brief Destructor
     */
    virtual ~ErrlUserDetailsParserWofData() {}

    /**
     *  @brief Parses WOF detail data from an error log
     *
     *  @param  i_version Version of the data
     *  @param  i_parser  ErrlUsrParser object for outputting information
     *  @param  i_pBuffer Pointer to buffer containing WOF detail data
     *  @param  i_buflen  Length of the buffer
     */
    virtual void parse(errlver_t i_version,
                       ErrlUsrParser & i_parser,
                       void * i_pBuffer,
                       const uint32_t i_buflen) const
    {

        if (i_version != WOF_OVERRIDE_ERROR_UD_VERSION)
        {
            i_parser.PrintHeading("Unsupported UD version found - hexdump:");
            i_parser.PrintNumber("Version found", "0x%X", i_version);
            i_parser.PrintNumber("Version supported", "0x%X", WOF_OVERRIDE_ERROR_UD_VERSION);
            i_parser.PrintHexDump(i_pBuffer, i_buflen);
        }
        else
        {
            uint16_t tableEntries = 0;

            // Format of WofData error buffer:
            //     uint16_t - Number of entries: i.e. entry with search info + all entries searched
            //     wofOverrideCompareData_t - Info used to perform search
            //     wofOverrideCompareData_t - last entry rejected for possible match
            //     ...
            //     wofOverrideCompareData_t - 1st entry rejected for possible match
            // NOTE: format must match addWofOverrideSearchEntriesToErrl() in plat_wof_access.C
            if ((NULL != i_pBuffer) && (i_buflen >= sizeof(tableEntries)))
            {
              tableEntries = ntohs(UINT16_FROM_PTR(i_pBuffer));
            }

            // How many entries are really present in this buffer?
            uint16_t actualTableCount = (i_buflen - sizeof(tableEntries)) /
                                         sizeof(wofOverrideCompareData_t);

            // sanity check to verify we are getting all the table data
            if (tableEntries != actualTableCount)
            {
              i_parser.PrintString("**************************************","");
              i_parser.PrintNumber("Total entries calculated", "%d",
                                   actualTableCount);
              i_parser.PrintNumber("Total entries expected", "%d",
                                   tableEntries);
              i_parser.PrintString("**************************************","");

              tableEntries = actualTableCount;  // don't go over buffer length
            }

            // Verify the buffer contains at least the specified number of entries
            if ( (i_buflen - sizeof(tableEntries) -
                  tableEntries * sizeof(wofOverrideCompareData_t)) >= 0 )
            {
                i_parser.PrintString("---------------------------------------",
                                     "---------------------------------------");
                i_parser.PrintNumber("Total WOF override set entries compared", "%d",
                                     tableEntries-1);

                // point to start of searched override entries
                void * i_pTableData = (uint8_t*)i_pBuffer + sizeof(tableEntries);
                wofOverrideCompareData_t* outputDataPtr =
                                  static_cast<wofOverrideCompareData_t*>(i_pTableData);
                for ( uint32_t tableEntry = 0; tableEntry < tableEntries;
                      ++tableEntry )
                {
                  if (tableEntry == 0)
                  {
                    i_parser.PrintString("---------------------------------------",
                                         "---------------------------------------");
                    i_parser.PrintString("Searched for this entry",
                                         "Tried to match this:");
                  }
                  else
                  {
                    i_parser.PrintString("---------------------------------------",
                                         "---------------------------");
                    i_parser.PrintNumber("WOF Override Table", "#%d", tableEntry);
                  }

                  i_parser.PrintNumber( "Core Count", "%d",
                                        outputDataPtr->core_count );
                  i_parser.PrintNumber("Socket Power (Watts)", "%d",
                                        ntohs(outputDataPtr->socket_power_w));
                  i_parser.PrintNumber("Sort Power Freq (MHz)", "%d",
                                        ntohs(outputDataPtr->sort_power_freq_mhz));
                  outputDataPtr++; // go to next table entry
                }
            }
            else
            {
                i_parser.PrintString("Unable to parse too small buffer","");
                i_parser.PrintNumber("WOF Buffer length", "0x%X", i_buflen);
                i_parser.PrintNumber("Total entry count", "0x%X", tableEntries);
                i_parser.PrintString("Expected buffer format:",
                            "uint16_t count, match this entry, unmatched entries");
                i_parser.PrintNumber("Each entry size", "%d",
                                    sizeof(wofOverrideCompareData_t));
                i_parser.PrintHexDump(i_pBuffer, i_buflen);
            }
        }
    }

private:
    // Disabled
    ErrlUserDetailsParserWofData(const ErrlUserDetailsParserWofData &);
    ErrlUserDetailsParserWofData & operator=(
        const ErrlUserDetailsParserWofData &);

    // uint and struct from src/usr/fapi2/plat_wof_access.C and also used in src/usr/errl/plugins/ebmc/b0100.py
    const uint8_t WOF_OVERRIDE_ERROR_UD_VERSION = 1;
    typedef struct __attribute__((__packed__)) wofOverrideCompareData
    {
        uint8_t  core_count;
        uint16_t socket_power_w;
        uint16_t sort_power_freq_mhz;
    } wofOverrideCompareData_t;
};

}

#endif
