/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_attn.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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

        uint32_t l_sbePlid = getSbeRC(i_procTarg);

        TRACFCOMP( g_trac_sbeio, "handleVitalAttn> Returned SBE PLID=0x%x",
                   l_sbePlid);

        // @todo - RTC:180242 - Restart SBE

        SbeRetryHandler l_sbeObj = SbeRetryHandler(
                      SbeRetryHandler::SBE_MODE_OF_OPERATION::ATTEMPT_REBOOT);
        // @todo - RTC:180242. Once the hreset method is finalized,
        //      we can call the sbe handler with that method
        //l_sbeObj.setSbeRestartMethod(SbeRetryHandler::
        //                              SBE_RESTART_METHOD::HRESET);

        l_sbeObj.main_sbe_handler(i_procTarg);

        // @todo - RTC:180244 - Disable the OCC
        // @todo - RTC:180245 - Inform OPAL

        TRACFCOMP( g_trac_sbeio,
                   EXIT_MRK "handleVitalAttn> ");
        return l_errhdl;
    }

    uint32_t getSbeRC(TARGETING::Target* i_target)
    {
        TRACFCOMP( g_trac_sbeio, ENTER_MRK "getSbeRC()");

        errlHndl_t l_errl = nullptr;

        uint32_t l_errlPlid = NULL;
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_fapi2ProcTarget(
                        const_cast<TARGETING::Target*> (i_target));

        P9_EXTRACT_SBE_RC::RETURN_ACTION l_ret =
                        P9_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM;
        FAPI_INVOKE_HWP(l_errl, p9_extract_sbe_rc,
                        l_fapi2ProcTarget, l_ret);

        if(l_errl)
        {
            TRACFCOMP(g_trac_sbeio, "ERROR: p9_extract_sbe_rc HWP returning "
                       "errorlog PLID: 0x%x", l_errl->plid());

            ERRORLOG::ErrlUserDetailsTarget(i_target).addToLog(l_errl);
            l_errlPlid = l_errl->plid();
        }

        return l_errlPlid;
    }

};
