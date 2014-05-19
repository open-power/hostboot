/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/plugins/initsvcudistep.H $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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

}

#endif

