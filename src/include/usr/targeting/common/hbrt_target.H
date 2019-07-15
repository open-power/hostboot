/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/hbrt_target.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
#ifndef __HBRT_TARGET_H
#define __HBRT_TARGET_H

#include <errl/errlentry.H>

namespace TARGETING
{
    typedef uint64_t rtChipId_t;
     /**
     * @brief Convert a TARGETING::Target to an unit ID that can be used
     * in calls to the runtime host
     * @param[in] The HB TARGETING::Target
     * @param[out] Sapphire target id
     * @return an error handle on error
     */
    errlHndl_t getRtTarget(const TARGETING::Target* i_target,
                           rtChipId_t &o_targetId);

}

#endif