/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep06/host_set_ipl_parms.C $                 */
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

#include <stdint.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>
#include <util/utilsemipersist.H>
#include <hwas/common/deconfigGard.H>
#include <arch/pvrformat.H>
#include <sys/mmio.h>
#include <console/consoleif.H>
#include <initservice/initserviceif.H>

using namespace TARGETING;

namespace ISTEP_06
{

constexpr uint8_t PROC_EC_DD2 = 0x22;

void* host_set_ipl_parms( void *io_pArgs )
{
    ISTEP_ERROR::IStepError l_stepError;
    errlHndl_t l_err;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_set_ipl_parms entry" );

    // only run on non-FSP systems
    if( !INITSERVICE::spBaseServicesEnabled() )
    {
        //Read out the semi persistent area.
        Util::semiPersistData_t l_semiData;
        Util::readSemiPersistData(l_semiData);

        // If magic number set, then this is warm reboot:
        //          1) increment boot count
        if(l_semiData.magic == Util::PERSIST_MAGIC)
        {
            l_semiData.reboot_cnt++;
        }
        // else magic number is not set, then this is first, cold boot:
        //          1) set magic num, boot count
        //          2) clear all gard records of type GARD_Reconfig
        else
        {
            l_semiData.magic = Util::PERSIST_MAGIC;
            l_semiData.reboot_cnt = 0;
            //Intentionally don't change mfg_term_reboot

            l_err = HWAS::clearGardByType(HWAS::GARD_Reconfig);
            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR 0x%.8X: clearGardByType( )",
                          l_err->reasonCode() );
                // Create IStep error log and cross ref error that occurred
                l_stepError.addErrorDetails( l_err );
                errlCommit( l_err, ISTEP_COMP_ID );
            }
        }

        //Write update data back out
        Util::writeSemiPersistData(l_semiData);
    }


    // Add a check to indicate that Nimbus DD1.0 is NOT supported
    // and prevent a boot
    PVR_t l_pvr( mmio_pvr_read() & 0xFFFFFFFF );
    if( l_pvr.isNimbusDD1() )
    {
#ifdef CONFIG_CONSOLE
        CONSOLE::displayf(ISTEP_COMP_NAME,
                          "P9N (Nimbus) DD1.0 is not supported in this driver");
        CONSOLE::displayf(ISTEP_COMP_NAME,
                          "Please update the system's processor modules");
#endif


        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "DD1.0 is NOT SUPPORTED anymore. "
                   "Please upgrade proc modules");
        /*@
         * @errortype
         * @moduleid     ISTEP::MOD_SET_IPL_PARMS
         * @reasoncode   ISTEP::RC_P9N_DD1_NOT_SUPPORTED
         * @userdata1    PVR of master proc
         * @devdesc      P9N (Nimbus) DD1.x is not supported
         *               in this firmware driver.  Please update
         *               your module or use a different driver
         * @custdesc     A problem occurred during the IPL
         *               of the system.
         */
        uint64_t l_dummy = 0x0;
        l_err = new ERRORLOG::ErrlEntry(
                                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        ISTEP::MOD_SET_IPL_PARMS,
                                        ISTEP::RC_P9N_DD1_NOT_SUPPORTED,
                                        l_pvr.word,
                                        l_dummy);
        // Create IStep error log and cross ref error that occurred
        l_stepError.addErrorDetails( l_err );
        errlCommit( l_err, ISTEP_COMP_ID );
    }


    // OP920: Any proc EC less than Nimbus DD2.2 is NOT supported
    // Generate an error but still continue to boot

    // Get the system target
    Target * l_sys = nullptr;
    targetService().getTopLevelTarget(l_sys);

    // Get the child proc chips
    TargetHandleList l_procList;
    getChildAffinityTargets( l_procList,
                             l_sys,
                             CLASS_CHIP,
                             TYPE_PROC );

    // For each proc target
    for( const auto & l_proc : l_procList )
    {
        if( (l_proc->getAttr<ATTR_MODEL>() == MODEL_NIMBUS) &&
            (l_proc->getAttr<TARGETING::ATTR_EC>() < PROC_EC_DD2) )
        {
#ifdef CONFIG_CONSOLE
            CONSOLE::displayf(ISTEP_COMP_NAME,
                "P9N (Nimbus) less than DD2.2 is not supported in this driver");
            CONSOLE::displayf(ISTEP_COMP_NAME,
                "Please update the system's processor modules");
#endif

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "P9N less than DD2.2 is NOT SUPPORTED anymore. "
                    "Please upgrade proc modules");
            /*@
            * @errortype
            * @moduleid     ISTEP::MOD_SET_IPL_PARMS
            * @reasoncode   ISTEP::RC_P9N_LESS_THAN_DD22_NOT_SUPPORTED
            * @userdata1    PVR of master proc
            * @devdesc      P9N (Nimbus) less than DD2.2 is not supported
            *               in this firmware driver.  Please update
            *               your module or use a different driver
            * @custdesc     Down-level processor detected causing IPL to fail
            */
            uint64_t l_dummy = 0x0;
            l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_PREDICTIVE,
                                    ISTEP::MOD_SET_IPL_PARMS,
                                    ISTEP::RC_P9N_LESS_THAN_DD22_NOT_SUPPORTED,
                                    l_pvr.word,
                                    l_dummy);
            l_err->addHwCallout(l_proc,
                                HWAS::SRCI_PRIORITY_HIGH,
                                HWAS::NO_DECONFIG,
                                HWAS::GARD_NULL );
            l_err->addProcedureCallout(
                                HWAS::EPUB_PRC_INVALID_PART,
                                HWAS::SRCI_PRIORITY_HIGH);
            // Create IStep error log and cross ref error that occurred
            l_stepError.addErrorDetails( l_err );
            errlCommit( l_err, ISTEP_COMP_ID );
        }
    }


    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_set_ipl_parms exit" );

    return l_stepError.getErrorHandle();
}

};
