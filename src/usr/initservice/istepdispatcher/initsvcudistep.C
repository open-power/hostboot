/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/istepdispatcher/initsvcudistep.C $        */
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
/**
 *  @file initsvcudistep.C
 *
 *  @brief Implementation of InitSvcUserDetailsIstep
 */
#include <initservice/initsvcudistep.H>
#include <initservice/initsvcreasoncodes.H>
#include <initservice/initsvcstructs.H>
#include <isteps/istepmasterlist.H>
#include <sys/time.h>

namespace   INITSERVICE
{
extern trace_desc_t *g_trac_initsvc;

//------------------------------------------------------------------------------
InitSvcUserDetailsIstep::InitSvcUserDetailsIstep(
    const char * i_pIstepname,
    const uint16_t i_step,
    const uint16_t i_substep)
{
    InitSvcUserDetailsIstepData * l_pBuf =
        reinterpret_cast<InitSvcUserDetailsIstepData *>(
            reallocUsrBuf(sizeof(InitSvcUserDetailsIstepData) +
                          (strlen(i_pIstepname) + 1)));

    l_pBuf->iv_step = i_step;
    l_pBuf->iv_substep = i_substep;
    strcpy(l_pBuf->iv_pIstepname, i_pIstepname);

    // Set up ErrlUserDetails instance variables
    iv_CompId = INITSVC_COMP_ID;
    iv_Version = 1;
    iv_SubSection = INIT_SVC_UDT_ISTEP;
}

//------------------------------------------------------------------------------
InitSvcUserDetailsIstep::~InitSvcUserDetailsIstep()
{

}

//------------------------------------------------------------------------------
InitSvcUserDetailsIstepStats::InitSvcUserDetailsIstepStats(
    const uint32_t i_ud_size_max,
    const std::array<iplInfo, MaxISteps>& i_ipl_stats)
{

    char * l_pBuf = reinterpret_cast<char *>(reallocUsrBuf(sizeof(UdEntryStats)));
    UdEntryStats * l_EntryInfo = reinterpret_cast<UdEntryStats *>(l_pBuf);
    uint16_t l_counter = 0;
    uint32_t l_UD_dynamic_current_size = 0;
    // See ErrlEntry::getErrlSize defaults
    // PNOR limits to the i_ud_size_max
    assert( (sizeof(UdEntryStats) <= i_ud_size_max),
        "Bug! Current User Details size=%u needs to be within the PNOR limit=%u",
         sizeof(UdEntryStats), i_ud_size_max);

    memset( l_pBuf, 0x00, sizeof(UdEntryStats));

    l_EntryInfo->iv_count = 0;

    for (uint16_t step = 0; step < MaxISteps; step++)
    {
        if (i_ipl_stats[step].numitems != 0)
        {
            for (uint16_t substep = 0; substep < MAX_SUBSTEPS; substep++)
            {
                if (i_ipl_stats[step].substeps[substep].valid)
                {
                    l_EntryInfo->substeps[l_counter].step = step;
                    l_EntryInfo->substeps[l_counter].substep = substep;
                    l_EntryInfo->substeps[l_counter].msecs =
                        i_ipl_stats[step].substeps[substep].nsecs/NS_PER_MSEC;
                    // For future usage or debug to capture the istep name strings
                    // Need to add stepname to the substep structure in initsvcstructs.H
                    //  snprintf(l_EntryInfo->substeps[l_counter].stepname,
                    //    sizeof(i_ipl_stats[step].substeps[substep].stepname),
                    //    i_ipl_stats[step].substeps[substep].stepname);
                    l_counter++;
                    l_UD_dynamic_current_size =
                        (sizeof(UdSubStepInfo) * l_counter) + sizeof(uint16_t);
                    assert( (l_UD_dynamic_current_size <= i_ud_size_max),
                        "Bug! We have too many entries based on UdSubStepInfo, "
                        "check the structures, "
                        "l_counter=%d l_UD_dynamic_current_size=%u i_ud_size_max=%u",
                        l_counter, l_UD_dynamic_current_size, i_ud_size_max);
                }
            }
        }
    }

    l_EntryInfo->iv_count = l_counter;

    // Set up ErrlUserDetails instance variables
    iv_CompId = INITSVC_COMP_ID;
    iv_Version = 1;
    iv_SubSection = INIT_SVC_UDT_ISTEP_STATS;
}

//------------------------------------------------------------------------------
InitSvcUserDetailsIstepStats::~InitSvcUserDetailsIstepStats()
{

}

}

