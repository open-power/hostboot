/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/test/pstatetest.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
#ifndef __PSTATETEST_H
#define __PSTATETEST_H

#include <cxxtest/TestSuite.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>

#include <targeting/common/targetservice.H>
#include <targeting/common/attributes.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/util.H>

#include <fapi.H>
#include <fapiPlatHwpInvoker.H>

#include <vfs/vfs.H>
#include <pstates.h>
#include <proc_get_voltage.H>
#include <mss_bulk_pwr_throttles.H>
#include <mss_util_to_throttle.H>
#include <mss_throttle_to_power.H>

using namespace TARGETING;

class pstateTest: public CxxTest::TestSuite
{
    public:

        // Test function to build pstate table
        // TODO RCT 114284 fix testcase
        // Requires Hostboot functions that are not yet merged. Testcase should
        // eventually call hb function "runP8BuildPstateDataBlock" declaired in
        // freqVoltageSvc.H to build pstate table.
        // p8_build_pstate_datablock reads VPD from all existing cores, not
        // just functional cores.  The current SIMICS standalone model does
        // not support MVDP for all existing cores.
        void DISABLE_test_verifyPstate( void )
        {
            errlHndl_t l_errl = NULL;
            bool pstateLibLoadedLocally = false;

            if(!VFS::module_is_loaded( "libpstates.so" ) )
            {
                l_errl = VFS::module_load( "libpstates.so" );
                if( l_errl )
                {
                    TS_FAIL("Could not load pstate module" );
                    errlCommit(l_errl,HTMGT_COMP_ID);
                }
                else
                {
                    pstateLibLoadedLocally = true;
                }
            }

            PstateSuperStructure pstateData;
            TargetHandleList procChips;
            getAllChips(procChips, TYPE_PROC, true);

            for (TargetHandleList::iterator itr = procChips.begin();
                 itr != procChips.end();
                 ++itr)
            {
                // cast OUR type of target to a FAPI type of target.
                const fapi::Target
                    fapiTarg(fapi::TARGET_TYPE_PROC_CHIP,
                             (const_cast<Target*>(*itr)));


                FAPI_INVOKE_HWP( l_errl,
                                 p8_build_pstate_datablock,
                                 fapiTarg,
                                 &pstateData
                               );

                if( l_errl )
                {
                    errlCommit(l_errl,HTMGT_COMP_ID);
                    TS_FAIL("verifyPstate failed for huid 0x%x",
                            get_huid(*itr));
                }
            }

            if(pstateLibLoadedLocally)
            {
                VFS::module_unload( "libpstates.so" );
            }

        }

        // test to call procedures HTMGT will need
        void test_procedures( void )
        {
            errlHndl_t l_errl = NULL;

            bool mccfgLibLoadedLocally = false;

            if(!VFS::module_is_loaded( "libmc_config.so" ) )
            {
                l_errl = VFS::module_load( "libmc_config.so" );
                if( l_errl )
                {
                    TS_FAIL("Could not load mc_config module" );
                    errlCommit(l_errl,HTMGT_COMP_ID);
                }
                else
                {
                    mccfgLibLoadedLocally = true;
                }
            }

            TARGETING::TargetHandleList l_mbaTargetList;
            getAllChiplets(l_mbaTargetList, TYPE_MBA);

            for (TargetHandleList::const_iterator l_mba_iter = l_mbaTargetList.begin();
                 l_mba_iter != l_mbaTargetList.end(); ++l_mba_iter)

            {
                const TARGETING::Target* l_mba_target = *l_mba_iter;

                const fapi::Target l_fapi_mba_target
                    (fapi::TARGET_TYPE_MBA_CHIPLET,
                     (const_cast<TARGETING::Target*>(l_mba_target)));

                FAPI_INVOKE_HWP( l_errl,
                                 mss_bulk_pwr_throttles,
                                 l_fapi_mba_target);
                if( l_errl )
                {
                    errlCommit(l_errl, HTMGT_COMP_ID);
                    TS_FAIL("Call to mss_bulk_pwr_throttles failed");
                }

                FAPI_INVOKE_HWP( l_errl,
                                 mss_util_to_throttle,
                                 l_fapi_mba_target);
                if( l_errl )
                {
                    errlCommit(l_errl, HTMGT_COMP_ID);
                    TS_FAIL("Call to mss_util_to_throttle failed");
                }


                FAPI_INVOKE_HWP( l_errl,
                                 mss_throttle_to_power,
                                 l_fapi_mba_target);
                if( l_errl )
                {
                    errlCommit(l_errl, HTMGT_COMP_ID);
                    TS_FAIL("Call to mss_throttle_to_power failed");
                }
            }

            if(mccfgLibLoadedLocally)
            {
                VFS::module_unload( "libmc_config.so" );
            }
        }
};

#endif
