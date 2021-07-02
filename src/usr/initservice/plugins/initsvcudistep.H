/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/plugins/initsvcudistep.H $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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
#ifndef INITSVC_UDSTEP_H
#define INITSVC_UDSTEP_H

/**
 *  @file initsvcudistep.H
 *
 *  Defines the InitSvcUserDetailsParserIstep class that parses
 *  IStep FFDC user detail in an error log
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

// See initsvcstructs.H for similar MAX_UD_ENTRIES
// Value based on max number of valid major/minor steps expected
// Currently 83 major/minor steps, so padded up for some flexibility
#define MAX_UD_ENTRIES 100

namespace   INITSERVICE
{

/**
 * @struct InitSvcUserDetailsIstepData
 *
 * Defines the user detail data
 */
struct InitSvcUserDetailsIstepData
{
    uint16_t iv_step;
    uint16_t iv_substep;
    char iv_pIstepname[0];
};

struct UdSubStepInfo
{
    uint16_t  step;
    uint16_t  substep;
    uint64_t  msecs;
    // See initsvcudistep.C for future usage of stepname
    // Similar change needed in initsvcstructs.H
    // The limitation today is size of the UD object produced needs to fit in PNOR
    // char      stepname[64];
} __attribute__ ((packed));

// Max number of expected istep major/minor, i.e. 6.4 thru 21.4
// This data structure is the compacted output from all expected
// MaxISteps and MAX_SUBSTEPs, i.e. each entry we want to output
struct UdEntryStats
{
    uint16_t       iv_count;
    UdSubStepInfo  substeps[MAX_UD_ENTRIES];
} __attribute__ ((packed));

/**
 * @class InitSvcUserDetailsParserIstep
 *
 * Parses Istep user detail in an error log
*/
class InitSvcUserDetailsParserIstep : public ERRORLOG::ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    InitSvcUserDetailsParserIstep() {}

    /**
     *  @brief Destructor
     */
    virtual ~InitSvcUserDetailsParserIstep() {}

    /**
     *  @brief Parses Istep user detail data from an error log
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
        InitSvcUserDetailsIstepData * l_pData =
            static_cast<InitSvcUserDetailsIstepData *>(i_pBuffer);

        i_parser.PrintString("IStep name", l_pData->iv_pIstepname);
        i_parser.PrintNumber("Step", "%d", ntohs(l_pData->iv_step));
        i_parser.PrintNumber("Sub-step", "%d", ntohs(l_pData->iv_substep));
    }

private:
    // Disabled
    InitSvcUserDetailsParserIstep(const InitSvcUserDetailsParserIstep &);
    InitSvcUserDetailsParserIstep & operator=(
        const InitSvcUserDetailsParserIstep &);
};

/**
 * @class InitSvcUserDetailsParserIstepStats
 *
 * Parses Istep user detail in an error log
*/
class InitSvcUserDetailsParserIstepStats : public ERRORLOG::ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    InitSvcUserDetailsParserIstepStats() {}

    /**
     *  @brief Destructor
     */
    virtual ~InitSvcUserDetailsParserIstepStats() {}

    /**
     *  @brief Parses Istep user detail data from an error log
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
        UdEntryStats * l_EntryInfo =
            static_cast<UdEntryStats *>(i_pBuffer);

        //i_parser.PrintBlank();
        //i_parser.PrintHeading("Hostboot DUMP IPL Stats");
        //i_parser.PrintHexDump(i_pBuffer, i_buflen);

        i_parser.PrintBlank();
        i_parser.PrintHeading("Hostboot IPL Stats");
        i_parser.PrintBlank();
        uint16_t count = TO_UINT16(&l_EntryInfo->iv_count);

        // output a header
        //
        i_parser.PrintString("IStep", "Time in IStep (msecs)");
        i_parser.PrintBlank();
        for (uint16_t index = 0; index < count; index++)
        {
            // SAMPLE  | IStep 6.4 : msecs=346 |
            const char * l_string = "msecs=%llu";
            const auto l_length = snprintf(NULL, 0, l_string, TO_UINT64(&l_EntryInfo->substeps[index].msecs));
            char output_buffer[l_length + 1];
            snprintf(output_buffer, (l_length + 1), l_string, TO_UINT64(&l_EntryInfo->substeps[index].msecs));

            const char * l_tag_string = "IStep %d.%d";
            const auto l_tag_length = snprintf(NULL, 0, l_tag_string,
                TO_UINT16(&l_EntryInfo->substeps[index].step),
                TO_UINT16(&l_EntryInfo->substeps[index].substep));
            char output_tag_buffer[l_tag_length + 1];
            snprintf(output_tag_buffer, (l_tag_length + 1), l_tag_string,
                TO_UINT16(&l_EntryInfo->substeps[index].step),
                TO_UINT16(&l_EntryInfo->substeps[index].substep));

            i_parser.PrintString(output_tag_buffer, output_buffer);
        }
    }

private:
    // Disabled
    InitSvcUserDetailsParserIstepStats(const InitSvcUserDetailsParserIstepStats &);
    InitSvcUserDetailsParserIstepStats & operator=(
        const InitSvcUserDetailsParserIstepStats &);
};

}

#endif

