/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/sbeio/runtime/sbeio_vital_attn.H $            */
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
#ifndef __SBE_MSG_SBEIO_VITAL_ATTN_H
#define __SBE_MSG_SBEIO_VITAL_ATTN_H

#include <errl/errlentry.H>            // errlHndl_t
#include <targeting/common/target.H>   // TARGETING::TargetHandle_t

namespace RT_SBEIO
{
    /**
      * State of the SBE
      */
    enum SBE_STATE
    {
        SBE_DISABLED = 0x0000000000000000, // SBE restart failed, SBE disabled
        SBE_ENABLED  = 0x0000000000000001, // SBE restart successful, SBE enabled
    };

    /**
     * @brief Inform OPAL the state of the SBE
     *
     * @details Inform OPAL the state of the SBE after trying a restart
     *
     * @param[in] i_procTarg  HB processor target of the disabled/enabled SBE
     * @param[in] i_sbeState  state of the SBE, 0 = disabled, 1 = enabled
     *
     * @return nullptr upon success, pointer to ErrlEntry if an error occurred.
     */
    errlHndl_t vital_attn_inform_opal(TARGETING::TargetHandle_t i_procTarg,
                                      SBE_STATE i_sbeState);

}  // end namespace RT_SBEIO

#endif
