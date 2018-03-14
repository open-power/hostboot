/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/common/sbe_attn.C $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2018                        */
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
/*
  Contains the logic that is needed to handle and recover from SBE vital
  attentions that occur when the SBE crashes.
*/

#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <sbeio/sbe_attn.H>
#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>
#include <p9_extract_sbe_rc.H>
#include <sbeio/sbeioreasoncodes.H>
#include <sbeio/sbe_retry_handler.H>
#include <sbeio/runtime/sbeio_attr_override.H>
#include <sbeio/runtime/sbeio_vital_attn.H>
#include <initservice/initserviceif.H>

extern trace_desc_t* g_trac_sbeio;

namespace SBEIO
{

    /**
     * @brief Gathers FFDC and recovers from SBE errors
     */
    errlHndl_t handleVitalAttn( TARGETING::Target* i_procTarg )
    {
        TRACFCOMP( g_trac_sbeio,
                   ENTER_MRK "handleVitalAttn> i_procTarg=",
                   TARGETING::get_huid(i_procTarg) );
        errlHndl_t l_errhdl = nullptr;

        // TODO 167191 Full SBE Belly-Up Handling for OP
#ifdef __HOSTBOOT_RUNTIME
        // Inform OPAL, SBE is currently disabled
        if (TARGETING::is_sapphire_load())
        {
            // Inform OPAL of the inoperable SBE
            l_errhdl = RT_SBEIO::vital_attn_inform_opal(i_procTarg,
                                                        RT_SBEIO::SBE_DISABLED);
        }
#endif

        // @todo - RTC:180242 - Restart SBE

        SbeRetryHandler l_sbeObj = SbeRetryHandler(
                      SbeRetryHandler::SBE_MODE_OF_OPERATION::ATTEMPT_REBOOT);

        //l_sbeObj.main_sbe_handler(i_procTarg);


#ifdef __HOSTBOOT_RUNTIME
        // Inform OPAL the state of the SBE after a retry
        if (l_sbeObj.isSbeAtRuntime())
        {
            if (TARGETING::is_sapphire_load())
            {
                l_errhdl = RT_SBEIO::vital_attn_inform_opal(i_procTarg,
                                                         RT_SBEIO::SBE_ENABLED);
            }

            // @todo - RTC:180244 - Disable the OCC
        }
#endif

        TRACFCOMP( g_trac_sbeio,
                   EXIT_MRK "handleVitalAttn> ");
        return l_errhdl;
    }

};
