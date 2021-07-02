/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/initservice/initsvcudistep.H $                */
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
 *  Defines the InitSvcUserDetailsIstep class that adds IStep FFDC to an
 *  error log as user detail data
 */

#include <errl/errluserdetails.H>
#include <initservice/initsvcstructs.H>
#include <isteps/istepmasterlist.H>

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
 * @struct UdEntryStats
 *
 * Defines the user detail data for IPL Stats
 */
struct UdEntryStats
{
    uint16_t iv_count;
    UdSubStepInfo substeps[MAX_UD_ENTRIES];
} __attribute__ ((packed));

/**
 * @class InitSvcUserDetailsIstep
 *
 * Adds IStep FFDC to an error log as user detail data
 */
class InitSvcUserDetailsIstep : public ERRORLOG::ErrlUserDetails
{
public:
    /**
     *  @brief Constructor
     *
     *  Captures the supplied IStep FFDC data internally
     *
     *  @param i_pIstepname Istep name
     *  @param i_step       Step number
     *  @param i_substep    Sub-step number
     */
    InitSvcUserDetailsIstep(const char * i_pIstepname,
                            const uint16_t i_step,
                            const uint16_t i_substep);

    /**
     *  @brief Destructor
     */
    virtual ~InitSvcUserDetailsIstep();

private:
    // Disabled
    InitSvcUserDetailsIstep(const InitSvcUserDetailsIstep &);
    InitSvcUserDetailsIstep & operator=(const InitSvcUserDetailsIstep &);
};

/**
 * @class InitSvcUserDetailsIstepStats
 *
 * Adds IStep Stats to an error log as user detail data
 */
class InitSvcUserDetailsIstepStats : public ERRORLOG::ErrlUserDetails
{
public:
    /**
     *  @brief Constructor
     *
     *  Captures the supplied IStep Stats data internally
     *
     *  @param i_ud_size_max Maximum size of UD data
     *  @param i_ipl_stats   IPL stats to compute
     */
    InitSvcUserDetailsIstepStats(const uint32_t i_ud_size_max,
        const std::array<iplInfo, MaxISteps>& i_ipl_stats);

    /**
     *  @brief Destructor
     */
    virtual ~InitSvcUserDetailsIstepStats();

private:
    // Disabled
    InitSvcUserDetailsIstepStats(const InitSvcUserDetailsIstepStats &);
    InitSvcUserDetailsIstepStats & operator=(const InitSvcUserDetailsIstepStats &);
};

}

#endif

