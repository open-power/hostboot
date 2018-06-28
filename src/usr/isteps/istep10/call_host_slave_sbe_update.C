/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep10/call_host_slave_sbe_update.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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
#include    <errl/errlentry.H>
#include    <errl/errludtarget.H>
#include    <errl/errlmanager.H>
#include    <isteps/hwpisteperror.H>
#include    <isteps/istep_reasoncodes.H>
#include    <initservice/isteps_trace.H>
#include    <initservice/istepdispatcherif.H>
#include    <initservice/initserviceif.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/target.H>

#include    <sbe/sbeif.H>
#include    <pnor/pnorif.H>
#include    <i2c/i2cif.H>
#include    <console/consoleif.H>
#include    <config.h>
#ifdef CONFIG_BMC_IPMI
#include    <ipmi/ipmisensor.H>
#endif
#include    <sys/time.h>
#include    <hwas/common/hwasCommon.H>

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

using   namespace   ISTEP_ERROR;
using   namespace   ISTEP;
using   namespace   TARGETING;
using   namespace   ERRORLOG;

namespace ISTEP_10
{

errlHndl_t rediscoverI2CTargets(void)
{
    errlHndl_t err = nullptr;
    size_t dimm_count_before = 0;
    size_t dimm_count_after = 0;

    TRACUCOMP( ISTEPS_TRACE::g_trac_isteps_trace,ENTER_MRK
               "rediscoverI2CTargets" );
    do
    {
        if ((SECUREBOOT::enabled() == false ) ||
            (INITSERVICE::spBaseServicesEnabled() == true ))
        {
            TRACUCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "rediscoverI2CTargets: skipping because either security "
                       "(%d) is not enabled or FSP-based system (%d)",
                       SECUREBOOT::enabled(),
                       INITSERVICE::spBaseServicesEnabled());

            break;
        }

        // find CLASS_SYS (the top level target)
        Target* pSys = nullptr;
        targetService().getTopLevelTarget(pSys);
        assert(pSys, "rediscoverI2CTargets: pSys is nullptr");

        // find list of all we need to call platPresenceDetect against
        PredicateCTM predDimm(CLASS_LOGICAL_CARD, TYPE_DIMM);
        PredicatePostfixExpr checkExpr;

        // Look for the ones that are 'not present'
        PredicateHwas notPresent;
        notPresent.present(false);

        checkExpr.push(&predDimm).push(&notPresent).And();

        TargetHandleList pDimmList;
        targetService().getAssociated( pDimmList, pSys,
            TargetService::CHILD, TargetService::ALL, &checkExpr );

        dimm_count_before = pDimmList.size();
        if ( dimm_count_before == 0 )
        {
            TRACUCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "rediscoverI2CTargets: pDimmList has size of %d meaning "
                       "no DIMMs to discover",
                       dimm_count_before);
            break;
        }

        // Pass this list to the hwas platform-specific api to reevaluate if
        // these targets are now present
        TRACUCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "rediscoverI2CTargets: pDimmList size before: %d",
                   dimm_count_before);
        err = HWAS::platPresenceDetect(pDimmList);
        if (err)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "rediscoverI2CTargets: HWAS::platPresenceDetect "
                       "returned err plid=0x%X, rc=0x%X",
                       err->plid(), err->reasonCode());
            break;
        }

        // HWAS::platPresenceDetect only keeps present targets, so save that
        // count here
        dimm_count_after = pDimmList.size();
        TRACUCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "rediscoverI2CTargets: pDimmList size after: %d (was %d)",
                   dimm_count_after, dimm_count_before);

        if ( dimm_count_after > 0 )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,ERR_MRK
                       "rediscoverI2CTargets: New DIMM(s) detected: pDimmList "
                       "size before=%d, after=%d. Requesting reboot",
                       dimm_count_before, dimm_count_after);

            uint32_t huid0 = get_huid(pDimmList.at(0));
            uint32_t huid1 = 0;
            if ( dimm_count_after >= 2)
            {
                huid1 = get_huid(pDimmList.at(1));
            }

            // Create info log

            /*@
             * @errortype
             * @moduleid         ISTEP::MOD_REDISCOVER_I2C_TARGETS
             * @reasoncode       ISTEP::RC_REDISCOVERED_TARGETS
             * @userdata1[0:31]  HUID of 1st rediscovered target
             * @userdata1[31:63] HUID of 2nd rediscovered target, if applicable
             * @userdata2[0:31]  Target Count Before Rediscover Attempt
             * @userdata2[31:63] Target Count After Rediscover Attempt
             * @devdesc          Targets detected via I2C were rediscovered
             *                   after an I2C reset.  Reboot to add to config
             * @custdesc         A problem occurred during the IPL of the
             *                   system and the system will reboot.
             */
            err = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                ISTEP::MOD_REDISCOVER_I2C_TARGETS,
                                ISTEP::RC_REDISCOVERED_TARGETS,
                                TWO_UINT32_TO_UINT64(huid0,
                                                     huid1),
                                TWO_UINT32_TO_UINT64(dimm_count_before,
                                                     dimm_count_after));
            err->collectTrace(ISTEP_COMP_NAME);
            err->collectTrace(HWAS_COMP_NAME);

            // Add Rediscovered Targets To The Error Log
            for ( auto l_tgt : pDimmList )
            {
                ErrlUserDetailsTarget(l_tgt).addToLog(err);
            }

            // Commit Error Log here since requesting reboot and not returning
            // error log to the caller
            errlCommit(err, ISTEP_COMP_ID);

#ifdef CONFIG_CONSOLE
            CONSOLE::displayf(ISTEP_COMP_NAME,"Requesting Reboot after DIMM(s) "
                              "were rediscovered after I2C Reset");
            CONSOLE::flush();
#endif

#ifdef CONFIG_BMC_IPMI
            uint16_t count = SENSOR::DEFAULT_REBOOT_COUNT;
            SENSOR::RebootCountSensor l_sensor;

            // Set reboot count to default value
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,INFO_MRK
                       "rediscoverI2CTargets: Writing Reboot Sensor Count=%d",
                       count);

            auto new_err = l_sensor.setRebootCount( count );
            if ( new_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"rediscoverI2CTargets: "
                           "FAIL Writing Reboot Sensor Count to %d. "
                           "Committing Error Log rc=0x%.4X eid=0x%.8X "
                           "plid=0x%.8X, but continuing shutdown",
                           count,
                           new_err->reasonCode(),
                           new_err->eid(),
                           new_err->plid());
                new_err->collectTrace(ISTEP_COMP_NAME);
                errlCommit( new_err, ISTEP_COMP_ID );

                // No Break - Still send chassis power cycle
            }

            // Initiate a graceful power cycle
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,INFO_MRK
                   "rediscoverI2CTargets: requesting power cycle");
            INITSERVICE::requestReboot();

            // sleep here to give IPMI code so that the istep doesn't
            // continue with SBE Update
            while (true)
            {
                nanosleep(60,0); // 60 seconds
            }
#endif


       }

    } while(0);

    TRACUCOMP( ISTEPS_TRACE::g_trac_isteps_trace,EXIT_MRK
               "rediscoverI2CTargets: err plid=0x%X rc=0x%X",
               ERRL_GETPLID_SAFE(err), ERRL_GETRC_SAFE(err) );

    return err;
}

void* call_host_slave_sbe_update (void *io_pArgs)
{
    errlHndl_t  l_errl  =   NULL;
    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_slave_sbe_update entry" );
    do
    {

        // Slave processors should now use Host I2C Access Method
        I2C::i2cSetAccessMode( I2C::I2C_SET_ACCESS_MODE_PROC_HOST );

        // Reset I2C devices before trying to access the SBE SEEPROMs
        // Any error returned should not fail istep
        l_errl = I2C::i2cResetActiveMasters( I2C::I2C_PROC_ALL );
        if (l_errl)
        {
            // Commit error and keep going
            errlCommit( l_errl, HWPF_COMP_ID );
        }

        // Attempt to rediscover any I2C devices after the above reset
        l_errl = rediscoverI2CTargets();
        if (l_errl)
        {
            // Commit error and keep going
            errlCommit( l_errl, HWPF_COMP_ID );
        }

        // Call to check state of Processor SBE SEEPROMs and
        // make any necessary updates
        l_errl = SBE::updateProcessorSbeSeeproms();

        if (l_errl)
        {
            // Create IStep error log and cross reference error that occurred
            l_StepError.addErrorDetails( l_errl);
            // Commit error
            errlCommit( l_errl, HWPF_COMP_ID );
            break;
        }

        // Call to Validate any Alternative Master's connection to PNOR
        // Only call this in MNFG mode
        // Any error returned should not fail istep

        // Get target service and the system target
        TargetService& tS = targetService();
        TARGETING::Target* sys = NULL;
        (void) tS.getTopLevelTarget( sys );
        assert(sys, "call_host_slave_sbe_update() system target is NULL");

        TARGETING::ATTR_MNFG_FLAGS_type mnfg_flags;
        mnfg_flags = sys->getAttr<TARGETING::ATTR_MNFG_FLAGS>();
        if ( mnfg_flags & MNFG_FLAG_THRESHOLDS )
        {
            l_errl = PNOR::validateAltMaster();
            if (l_errl)
            {
                // Commit error
                errlCommit( l_errl, HWPF_COMP_ID );
                break;
            }
        }


        // Set SEEPROM_VERSIONS_MATCH attributes for each processor
        // this will be used later on by the sbe_retry code to determine
        // if it is safe to switch seeprom sides during recovery attempts
        l_errl = SBE::querySbeSeepromVersions();
        if(l_errl)
        {
            l_StepError.addErrorDetails( l_errl);
            errlCommit( l_errl, HWPF_COMP_ID);
        }

   } while (0);

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_slave_sbe_update exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();

}

};
