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
#include <errl/errludcallout.H>
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
        errlHndl_t l_err = nullptr;

#ifdef __HOSTBOOT_RUNTIME
        // Inform OPAL, SBE is currently disabled
        if (TARGETING::is_sapphire_load())
        {
            // Inform OPAL of the inoperable SBE
            l_err = RT_SBEIO::vital_attn_inform_opal(i_procTarg,
                                                        RT_SBEIO::SBE_DISABLED);

            if(l_err)
            {
                errlCommit(l_err, SBEIO_COMP_ID);
            }
        }

        SbeRetryHandler l_sbeObj = SbeRetryHandler(
                      SbeRetryHandler::SBE_MODE_OF_OPERATION::ATTEMPT_REBOOT);

        l_sbeObj.main_sbe_handler(i_procTarg);

        // Check if the SBE made it back to runtime, this tells us if the retry was a
        // success or not
        if (!l_sbeObj.isSbeAtRuntime())
        {
            /*@
            * @errortype  ERRL_SEV_PREDICTIVE
            * @moduleid   SBEIO_HANDLE_VITAL_ATTN
            * @reasoncode SBEIO_NO_RECOVERY_ACTION
            * @userdata1  Huid of processor
            * @userdata2  Unused
            * @devdesc    PRD detected an error with the SBE and HB failed to
            *             recover
            * @custdesc   Processor Error
            */
            l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_PREDICTIVE,
                                SBEIO_HANDLE_VITAL_ATTN,
                                SBEIO_NO_RECOVERY_ACTION,
                                TARGETING::get_huid(i_procTarg),
                                0);

            l_err->addProcedureCallout( HWAS::EPUB_PRC_SUE_PREVERROR,
                                        HWAS::SRCI_PRIORITY_HIGH);

            l_err->addHwCallout( i_procTarg,
                                  HWAS::SRCI_PRIORITY_LOW,
                                  HWAS::NO_DECONFIG,
                                  HWAS::GARD_NULL );

            l_err->collectTrace( SBEIO_COMP_NAME, 256);
            // @todo - RTC:180244 - Disable the OCC
        }
        // Inform OPAL the state of the SBE after a retry is successful
        else
        {
            if (TARGETING::is_sapphire_load())
            {
                l_err = RT_SBEIO::vital_attn_inform_opal(i_procTarg,
                                                         RT_SBEIO::SBE_ENABLED);
                if(l_err)
                {
                    errlCommit(l_err, SBEIO_COMP_ID);
                }
            }
        }
#else
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_fapi2ProcTarget(
                            const_cast<TARGETING::Target*> (i_procTarg));

        //Unused in the context, but required for p9_extract_sbe_rc
        P9_EXTRACT_SBE_RC::RETURN_ACTION l_ret =
                P9_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM;

        FAPI_INVOKE_HWP(l_err, p9_extract_sbe_rc,
                        l_fapi2ProcTarget, l_ret);

        // p9_extract_sbe_rc should always return w/ an error
        // make sure at least some sort of error gets returned
        // because we are not attempting to recover anything
        if(!l_err)
        {
           /*@
            * @errortype  ERRL_SEV_PREDICTIVE
            * @moduleid   SBEIO_HANDLE_VITAL_ATTN
            * @reasoncode SBEIO_EXTRACT_RC_ERROR
            * @userdata1  Huid of processor
            * @userdata2  Return action from extract_rc
            * @devdesc    We expected an error log to be returned from
                          p9_extract_rc but there wasn't one
            * @custdesc   Processor Error
            */
            l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_PREDICTIVE,
                                SBEIO_HANDLE_VITAL_ATTN,
                                SBEIO_EXTRACT_RC_ERROR,
                                TARGETING::get_huid(i_procTarg),
                                l_ret);
        }

        //We want to deconfigure the processor where the error was detected
        l_err->addHwCallout( i_procTarg,
                                HWAS::SRCI_PRIORITY_HIGH,
                                HWAS::DELAYED_DECONFIG,
                                HWAS::GARD_NULL );
#endif


        TRACFCOMP( g_trac_sbeio,
                   EXIT_MRK "handleVitalAttn> ");
        return l_err;
    }

};