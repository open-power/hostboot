/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/hostbootIstep.C $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
 *  @file hostbootIstep.C
 *
 *  @brief hostboot istep-called functions
 */

#include <hwas/common/hwas.H>
#include <hwas/common/hwasCommon.H>
#include <hwas/common/hwas_reasoncodes.H>
#include <hwas/hwasPlat.H>

#include <hwas/hostbootIstep.H>
#include <hwas/common/deconfigGard.H>

#include <fsi/fsiif.H>
#include <initservice/taskargs.H>
#include <initservice/isteps_trace.H>
#include <hwpisteperror.H>

#include <targeting/attrsync.H>
#include <targeting/namedtarget.H>
#include <diag/prdf/prdfMain.H>
#include <intr/interrupt.H>
#include <ibscom/ibscomif.H>

#include <i2c/i2cif.H>

#include <sbe/sbeif.H>
#include <sbe_update.H>

//  fapi support
#include  <fapi.H>
#include  <fapiPlatHwpInvoker.H>

//  targeting support.
#include  <targeting/common/utilFilter.H>
#include  <targeting/common/commontargeting.H>
#include  <targeting/common/entitypath.H>

#include  <errl/errludtarget.H>

#include <proc_enable_reconfig.H>


#include <ipmi/ipmisensor.H>
#include <ipmi/ipmifruinv.H>
#include <config.h>

namespace HWAS
{

using namespace TARGETING;
using namespace fapi;
using namespace ISTEP;
using namespace ISTEP_ERROR;

// functions called from the istep dispatcher -- hostboot only

//******************************************************************************
// host_init_fsi function
//******************************************************************************
void* host_init_fsi( void *io_pArgs )
{
    errlHndl_t l_errl = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_init_fsi entry" );
    do
    {
        l_errl = FSI::initializeHardware( );
        if (l_errl)
        {
            // This error should get returned
            break;
        }

        l_errl = I2C::i2cResetMasters(I2C::I2C_RESET_ALL, false);
        if (l_errl)
        {
            // Commit this error
            errlCommit( l_errl, HWPF_COMP_ID );
            l_errl = NULL;
            break;
        }

    } while (0);

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_init_fsi exit" );
    return l_errl;
}

//******************************************************************************
// host_set_ipl_parms function
//******************************************************************************
void* host_set_ipl_parms( void *io_pArgs )
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_set_ipl_parms entry" );
    errlHndl_t errl = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_set_ipl_parms exit" );

    return errl;
}

//******************************************************************************
// host_discover_targets function
//******************************************************************************
void* host_discover_targets( void *io_pArgs )
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "host_discover_targets entry" );

    errlHndl_t errl = NULL;

    // Check whether we're in MPIPL mode
    TARGETING::Target* l_pTopLevel = NULL;
    targetService().getTopLevelTarget( l_pTopLevel );
    HWAS_ASSERT(l_pTopLevel, "HWAS host_discover_targets: no TopLevelTarget");

    if (l_pTopLevel->getAttr<ATTR_IS_MPIPL_HB>())
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "MPIPL mode");

        // Sync attributes from Fsp
        errl = syncAllAttributesFromFsp();
    }
    else
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "Normal IPL mode");

        errl = discoverTargets();
    }

    // Put out some helpful messages that show which targets we actually found
    std::map<TARGETING::TYPE,uint64_t> l_presData;
    for (TargetIterator target = targetService().begin();
         target != targetService().end();
         ++target)
    {
        if (!(target->getAttr<ATTR_HWAS_STATE>().present))
        {
            continue;
        }
        TARGETING::TYPE l_type = target->getAttr<TARGETING::ATTR_TYPE>();
        TARGETING::ATTR_POSITION_type l_pos = 0;
        if( target->tryGetAttr<TARGETING::ATTR_POSITION>(l_pos) )
        {
            l_presData[l_type] |= (0x8000000000000000 >> l_pos);
        }
    }
    TARGETING::EntityPath l_epath; //use EntityPath's translation functions
    for( std::map<TARGETING::TYPE,uint64_t>::iterator itr = l_presData.begin();
         itr != l_presData.end();
         ++itr )
    {
        uint8_t l_type = itr->first;
        uint64_t l_val = itr->second;
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,"PRESENT> %s[%.2X]=%.8X%.8X", l_epath.pathElementTypeAsString(itr->first), l_type, l_val>>32, l_val&0xFFFFFFFF);
#if (!defined(CONFIG_CONSOLE_OUTPUT_TRACE) && defined(CONFIG_CONSOLE))
        CONSOLE::displayf( "PRESENT> %s[%.2X]=%.8X%.8X", l_epath.pathElementTypeAsString(itr->first), l_type, l_val>>32, l_val&0xFFFFFFFF );
#endif
    }

#ifdef CONFIG_BMC_IPMI
    // send DIMM/CORE/PROC sensor status to the BMC
    SENSOR::updateBMCSensorStatus();

    if (errl == NULL)
    {
        // Gather + Send the IPMI Fru Inventory data to the BMC
        errl = IPMIFRUINV::setData();
    }
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "host_discover_targets exit" );

    return errl;
}

//******************************************************************************
// host_gard function
//******************************************************************************
void* host_gard( void *io_pArgs )
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_gard entry" );
    errlHndl_t errl;

    do {
        // Check whether we're in MPIPL mode
        TARGETING::Target* l_pTopLevel = NULL;
        targetService().getTopLevelTarget( l_pTopLevel );
        HWAS_ASSERT(l_pTopLevel, "HWAS host_gard: no TopLevelTarget");

        if (l_pTopLevel->getAttr<ATTR_IS_MPIPL_HB>())
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "MPIPL mode");

            // we only want EX units to be processed
            TARGETING::PredicateCTM l_exFilter(TARGETING::CLASS_UNIT,
                                           TARGETING::TYPE_EX);
            errl = collectGard(&l_exFilter);
            if (errl)
            {
               TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                               "collectGard returned error; breaking out");
                break;
            }
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "Normal IPL mode");

            errl = collectGard();
            if(errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                   "collectGard returned error; breaking out");
                break;
            }

            if (errl == NULL)
            {
                //  check and see if we still have enough hardware to continue
                errl = checkMinimumHardware();
                if(errl)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
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

        // Send message to FSP sending HUID of EX chip associated with
        // master core
        msg_t * core_msg = msg_allocate();
        core_msg->type = SBE::MSG_IPL_MASTER_CORE;
        const TARGETING::Target*  l_masterCore  = TARGETING::getMasterCore( );

         /*@    errorlog tag
          *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
          *  @moduleid       MOD_HOST_GARD
          *  @reasoncode     RC_MASTER_CORE_NULL
          *  @userdata1      0
          *  @userdata2      0
          *  @devdesc        HWAS host_gard: no masterCore found
          */
        if (l_masterCore == NULL)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "No masterCore Found" );
            const bool hbSwError = true;
            errl = new ERRORLOG::ErrlEntry
                    (ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                     HWAS::MOD_HOST_GARD,
                     HWAS::RC_MASTER_CORE_NULL,
                     0, 0, hbSwError);
            break;
        }
        // Get the EX chip associated with the master core as that is the
        // chip that
        //   has the IS_MASTER_EX attribute associated with it
        TARGETING::TargetHandleList targetList;
        getParentAffinityTargets(targetList,
                             l_masterCore,
                             TARGETING::CLASS_UNIT,
                             TARGETING::TYPE_EX);
        HWAS_ASSERT(targetList.size() == 1,
             "HWAS host_gard: Incorrect EX chip(s) associated with masterCore");
        core_msg->data[0] = 0;
        core_msg->data[1] = TARGETING::get_huid( targetList[0] );
        core_msg->extra_data = NULL;
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "Sending MSG_MASTER_CORE message with HUID %08x",
              core_msg->data[1]);
        errl = MBOX::send(MBOX::IPL_SERVICE_QUEUE,core_msg);
        if (errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                      ERR_MRK"MBOX::send failed sending Master Core message");
            msg_free(core_msg);
            break;
        }
    } while (0);

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_gard exit" );
    return errl;
}

//******************************************************************************
// host_cancontinue_clear function
//******************************************************************************
void* host_cancontinue_clear( void *io_pArgs )
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "host_cancontinue_clear entry" );
    errlHndl_t errl = NULL;

    // stub -- nothing here currently

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "host_cancontinue_clear exit" );

    return errl;
}

//******************************************************************************
// host_prd_hwreconfig function
//******************************************************************************
void* host_prd_hwreconfig( void *io_pArgs )
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "host_prd_hwreconfig entry" );

    errlHndl_t errl = NULL;
    IStepError l_stepError;
    do
    {
        // Flip the scom path back to FSI in case we enabled IBSCOM previously
        IBSCOM::enableInbandScoms(IBSCOM_DISABLE);

        // Call PRDF to remove non-function chips from its system model
        errl = PRDF::refresh();

        if (errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "host_prd_hwreconfig ERROR 0x%.8X returned from"
                      "  call to PRDF::refresh", errl->reasonCode());

            // Create IStep error log and cross reference error that occurred
            l_stepError.addErrorDetails(errl);

            // Commit Error
            errlCommit(errl, HWPF_COMP_ID);

            break;
        }

        // Lists for present MCS
        TARGETING::TargetHandleList l_presMcsList;

        // find all present MCS chiplets of all procs
        getChipletResources(l_presMcsList, TYPE_MCS, UTIL_FILTER_PRESENT);

        for (TargetHandleList::const_iterator
             l_mcs_iter = l_presMcsList.begin();
             l_mcs_iter != l_presMcsList.end();
             ++l_mcs_iter)
        {
            // make a local copy of the MCS target
            const TARGETING::Target * l_pMcs = *l_mcs_iter;
            // Retrieve HUID of current MCS
            TARGETING::ATTR_HUID_type l_currMcsHuid =
                TARGETING::get_huid(l_pMcs);

            // Dump current run on target
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "Running proc_enable_reconfig HWP on "
                    "MCS target HUID %.8X", l_currMcsHuid);

            // Create FAPI Targets.
            fapi::Target l_fapiMcsTarget(TARGET_TYPE_MCS_CHIPLET,
                    (const_cast<TARGETING::Target*>(l_pMcs)));

            // Call the HWP with each fapi::Target
            FAPI_INVOKE_HWP(errl, proc_enable_reconfig, l_fapiMcsTarget);

            if (errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                         "ERROR 0x%.8X: proc_enable_reconfig HWP returns error",
                          errl->reasonCode());

                // Capture the target data in the elog
                ERRORLOG::ErrlUserDetailsTarget(l_pMcs).addToLog( errl );

                //Create IStep error log and cross reference error that occurred
                l_stepError.addErrorDetails(errl);

                // Commit Error
                errlCommit(errl, HWPF_COMP_ID);

                // Don't keep calling proc_enable_reconfig. Treat as a fatal
                // unexpected unrecoverable error and terminate the IPL.
                break ; // break with error
            }
            // Success
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "Successfully ran proc_enable_reconfig HWP on "
                    "MCS target HUID %.8X", l_currMcsHuid);
        }
    }
    while(0);
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "host_prd_hwreconfig exit" );
    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}

//******************************************************************************
// host_stub function
//******************************************************************************
void* host_stub( void *io_pArgs )
{
    errlHndl_t errl = NULL;
    // no function required
    return errl;
}

} // namespace HWAS
