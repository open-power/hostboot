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
#include <mss_eff_config_thermal.H>
#include "../genPstate.H"

using namespace TARGETING;

class pstateTest: public CxxTest::TestSuite
{
    public:

        // TODO RTC: 116310 VPD needs to be fixed in simics before a valid
        // pstate table can be built in simics.
        void DISABLE_test_verifyPstate( void )
        {
            errlHndl_t l_errl = NULL;
            bool pstateLibLoadedLocally = false;
            bool htmgtLibLoadedLocally  = false;

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

            if(!VFS::module_is_loaded("libhtmgt.so"))
            {
                l_errl = VFS::module_load("libhtmgt.so");
                if( l_errl )
                {
                    TS_FAIL("Could not load libhtmgt.so module");
                    errlCommit(l_errl,HTMGT_COMP_ID);
                }
                else
                {
                    htmgtLibLoadedLocally = true;
                }
            }

            l_errl = genPstateTables();

            if( l_errl )
            {
                errlCommit(l_errl,HTMGT_COMP_ID);
                TS_FAIL("verifyPstate failed");
            }

            // TODO RTC 116310 check eyecatcher in pstate table

            if(pstateLibLoadedLocally)
            {
                VFS::module_unload( "libpstates.so" );
            }

            if(htmgtLibLoadedLocally)
            {
                VFS::module_unload( "libhtmgt.so" );
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

                // mss_eff_config_thermal sets up the attributes needed by
                // the hw procedures that follow it.
                FAPI_INVOKE_HWP( l_errl,
                                 mss_eff_config_thermal,
                                 l_fapi_mba_target);
                if( l_errl )
                {
                    errlCommit(l_errl, HTMGT_COMP_ID);
                    TS_FAIL("Call to mss_eff_config_thermal failed");
                }

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
