/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep06/host_gard.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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

#include <hwas/common/hwas.H>
#include <hwas/common/hwasCommon.H>
#include <hwas/common/hwas_reasoncodes.H>
#include <hwas/hwasPlat.H>

#include <hwas/common/deconfigGard.H>

#include <initservice/taskargs.H>
#include <initservice/isteps_trace.H>
#include <initservice/initserviceif.H>
#include <isteps/hwpisteperror.H>

#include <targeting/attrsync.H>
#include <targeting/namedtarget.H>

#include <sbe/sbeif.H>
#include <sbe_update.H>

//  targeting support.
#include  <targeting/common/utilFilter.H>
#include  <targeting/common/commontargeting.H>
#include  <targeting/common/entitypath.H>

#include  <errl/errludtarget.H>

#include <console/consoleif.H>

// Custom compile configs
#include <config.h>

#ifdef CONFIG_ENABLE_CHECKSTOP_ANALYSIS
  #include <hwpf/hwp/occ/occ.H>
  #include <hwpf/hwp/occ/occ_common.H>

  #include <diag/attn/attn.H>
#endif

namespace ISTEP_06
{

void* host_gard( void *io_pArgs )
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_gard entry" );
    errlHndl_t l_err;
    ISTEP_ERROR::IStepError l_stepError;

    do {
        TARGETING::Target* l_pTopLevel = NULL;
        TARGETING::targetService().getTopLevelTarget( l_pTopLevel );
        assert(l_pTopLevel, "host_gard: no TopLevelTarget");

#ifdef CONFIG_ENABLE_CHECKSTOP_ANALYSIS
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   INFO_MRK"host_gard: invoke PRD to check for previous CS" );

        l_err = ATTN::checkForCSAttentions();
        if ( NULL != l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       ERR_MRK"host_gard: error from checkForCSAttentions" );
            // commit and continue
            errlCommit (l_err, ISTEP_COMP_ID);
        }
#endif

        // Check whether we're in MPIPL mode
        if (l_pTopLevel->getAttr<TARGETING::ATTR_IS_MPIPL_HB>())
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "host_gard: MPIPL mode");

            // we only want EX units to be processed
            TARGETING::PredicateCTM l_exFilter(TARGETING::CLASS_UNIT,
                                           TARGETING::TYPE_EX);
            l_err = HWAS::collectGard(&l_exFilter);
            if (l_err)
            {
               TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,"host_gard: "
                               "collectGard returned error; breaking out");
                break;
            }
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "host_gard: Normal IPL mode");

            l_err = HWAS::collectGard();
            if(l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,"host_gard: "
                   "collectGard returned error; breaking out");
                break;
            }

            if (l_err == NULL)
            {
                //  check and see if we still have enough hardware to continue
                l_err = HWAS::checkMinimumHardware();
                if(l_err)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      ERR_MRK"host_gard: "
                      "check minimum hardware returned error; breaking out");
                    break;
                }
            }
            // If targets are deconfigured as a result of host_gard, they are
            // done so using the PLID as the reason for deconfiguration.  This
            // triggers the reconfigure loop attribute to be set, which causes
            // undesirable behavior, so we need to reset it here:

            // Read current value
            TARGETING::ATTR_RECONFIGURE_LOOP_type l_reconfigAttr =
                l_pTopLevel->getAttr<TARGETING::ATTR_RECONFIGURE_LOOP>();
            // Turn off deconfigure bit
            l_reconfigAttr &= ~TARGETING::RECONFIGURE_LOOP_DECONFIGURE;
            // Write back to attribute
            l_pTopLevel->setAttr<TARGETING::ATTR_RECONFIGURE_LOOP>
                    (l_reconfigAttr);
        }

        // Send message to FSP with HUID of master core
        msg_t * core_msg = msg_allocate();
        core_msg->type = SBE::MSG_IPL_MASTER_CORE;
        const TARGETING::Target*  l_masterCore  = TARGETING::getMasterCore( );

         /*@ errorlog tag
          *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
          *  @moduleid       ISTEP::MOD_HOST_GARD
          *  @reasoncode     ISTEP::RC_MASTER_CORE_NULL
          *  @userdata1      0
          *  @userdata2      0
          *  @devdesc        host_gard: no masterCore found
          */
        if (l_masterCore == NULL)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK"host_gard: "
                "No masterCore Found" );
            const bool hbSwError = true;
            l_err = new ERRORLOG::ErrlEntry
                    (ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                     ISTEP::MOD_HOST_GARD,
                     ISTEP::RC_MASTER_CORE_NULL,
                     0, 0, hbSwError);
            break;
        }

        core_msg->data[0] = TARGETING::get_huid(l_masterCore);
        core_msg->extra_data = NULL;

        // TODO RTC 149318 Once HWSV is updated to take the master core
        // from data[0], stop sending the EX in data[1].
        // Set data[1] to 0 instead of the following.
        {
            // Get the EX chip associated with the master core as that is the
            // chip that has the MASTER_EX attribute associated with it
            TARGETING::TargetHandleList targetList;
            getParentAffinityTargets(targetList,
                             l_masterCore,
                             TARGETING::CLASS_UNIT,
                             TARGETING::TYPE_EX);
            assert(targetList.size() == 1,
             "host_gard: Incorrect EX chip(s) associated with masterCore");
            core_msg->data[1] = TARGETING::get_huid( targetList[0] );
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,"host_gard: "
                  "Sending MSG_MASTER_CORE message with EX HUID %08x",
                  core_msg->data[1]);
        }
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,"host_gard: "
              "Sending MSG_MASTER_CORE message with HUID %08x",
              core_msg->data[0]);
        l_err = MBOX::send(MBOX::IPL_SERVICE_QUEUE,core_msg);
        if (l_err)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK"host_gard: "
                       "MBOX::send failed sending Master Core message");
            msg_free(core_msg);
            break;
        }
    } while (0);

    if (l_err)
    {
        // Create IStep error log and cross reference occurred error
        l_stepError.addErrorDetails( l_err );
        // Commit Error
        errlCommit (l_err, ISTEP_COMP_ID);
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_gard exit" );
    return l_stepError.getErrorHandle();
}

};
