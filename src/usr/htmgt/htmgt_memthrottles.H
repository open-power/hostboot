/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/htmgt_memthrottles.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2017                        */
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
#ifndef HTMGT_MEMTHROTTLES_H
#define HTMGT_MEMTHROTTLES_H

#include <errl/errlmanager.H>

namespace HTMGT
{
    // NIMBUS:
    const uint8_t TMGT_MAX_MCS_PER_MCBIST = 2;
    const uint8_t TMGT_MAX_MCA_PER_MCS = 2;
    const uint8_t TMGT_MAX_DIMM_PER_MCA = 2;
    const uint8_t TMGT_MAX_DIMM_PER_MCS =
        TMGT_MAX_DIMM_PER_MCA * TMGT_MAX_MCA_PER_MCS;

    /**
     * Calculates the memory throttling numerator values for the OT,
     * oversubscription, and redundant power cases.  The results are
     * stored in attributes under the corresponding MBAs.
     */
    errlHndl_t calcMemThrottles();

};
#endif
