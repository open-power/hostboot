/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep21/call_nvdimm_update.C $                 */
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
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <initservice/isteps_trace.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>

// NVDIMM support
#include <isteps/nvdimm/nvdimm.H>

#include "call_nvdimm_update.H"

namespace NVDIMM_UPDATE
{

/**
 * @brief This function updates the NVDIMM firmware code
 */
void call_nvdimm_update()
{
    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,ENTER_MRK"call_nvdimm_update()");

    TARGETING::TargetHandleList l_nvdimmTargetList;
    TARGETING::TargetHandleList l_procList;
    TARGETING::getAllChips(l_procList, TARGETING::TYPE_PROC, false);

    // grab the NVDIMMs under each processor and add to overall list
    for (auto l_proc : l_procList)
    {
        TARGETING::TargetHandleList tmpList =
            TARGETING::getProcNVDIMMs(l_proc);
        l_nvdimmTargetList.insert(l_nvdimmTargetList.end(),
                                  tmpList.begin(), tmpList.end());
    }

    // Run the nvdimm update function if the list is not empty
    if ( !l_nvdimmTargetList.empty() )
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "call_nvdimm_update(): found %d nvdimms to check for update",
            l_nvdimmTargetList.size());
        bool updateWorked = NVDIMM::nvdimm_update(l_nvdimmTargetList);
        if (!updateWorked)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "call_nvdimm_update(): nvdimm update failed");
        }
    }

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,EXIT_MRK"call_nvdimm_update()");
}

};
