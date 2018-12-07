/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep06/host_set_ipl_parms.C $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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

#if (defined(CONFIG_PNORDD_IS_BMCMBOX) || defined(CONFIG_PNORDD_IS_IPMI))
#include <pnor/pnorif.H>
#endif

namespace ISTEP_06
{

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


#if (defined(CONFIG_PNORDD_IS_BMCMBOX) || defined(CONFIG_PNORDD_IS_IPMI))
    // Add a check to indicate the BMC does not support HIOMAP pnor-ipmi access
    // and the BMC firmware should be updated
    PNOR::hiomapMode l_mode = PNOR::getPnorAccessMode();
    if( l_mode != PNOR::PNOR_IPMI )
    {
#ifdef CONFIG_CONSOLE
        CONSOLE::displayf(ISTEP_COMP_NAME,
            "HIOMAP PNOR-IPMI not enabled, BMC firmware needs to be updated.");
#endif

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "HIOMAP PNOR-IPMI not enabled, BMC firmware needs to be updated.");
      
#ifdef CONFIG_PNORDD_IS_BMCMBOX
        bool l_IS_BMCMBOX = true;
#else
        bool l_IS_BMCMBOX = false;
#endif      

#ifdef CONFIG_PNORDD_IS_IPMI
        bool l_IS_IPMI = true;
#else
        bool l_IS_IPMI = false;
#endif      

        /*@
         * @errortype
         * @moduleid     ISTEP::MOD_SET_IPL_PARMS
         * @reasoncode   ISTEP::RC_PNOR_IPMI_NOT_ENABLED
         * @userdata1    HIOMAP Mode
         * @userdata2[0-31]  CONFIG_PNORDD_IS_BMCMBOX
         * @userdata2[32:63] CONFIG_PNORDD_IS_IPMI
         * @devdesc      PNOR-IPMI not enabled, BMC firmware needs to be updated
         * @custdesc     PNOR-IPMI not enabled, BMC firmware needs to be updated
         */
        l_err = new ERRORLOG::ErrlEntry(
                                        ERRORLOG::ERRL_SEV_PREDICTIVE,
                                        ISTEP::MOD_SET_IPL_PARMS,
                                        ISTEP::RC_PNOR_IPMI_NOT_ENABLED,
                                        l_mode,
                                        TWO_UINT32_TO_UINT64(
                                            l_IS_BMCMBOX,
                                            l_IS_IPMI));

        l_err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                   HWAS::SRCI_PRIORITY_HIGH);

        l_err->collectTrace(PNOR_COMP_NAME);
        l_err->collectTrace("ISTEPS_TRACE",256);

        // Create IStep error log and cross ref error that occurred
        l_stepError.addErrorDetails( l_err );
        errlCommit( l_err, ISTEP_COMP_ID );
    }
#endif

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_set_ipl_parms exit" );

    return l_stepError.getErrorHandle();
}

};
