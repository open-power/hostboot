/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/test/htmgt_test.H $                             */
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

#ifndef __HTMGTTEST_H
#define __HTMGTTEST_H

#include <cxxtest/TestSuite.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <vfs/vfs.H>

#include <htmgt/htmgt.H>
#include <htmgt_activate.H>

#include <targeting/common/targetservice.H>
#include <targeting/common/attributes.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/util.H>


using namespace TARGETING;


class htmgtTest: public CxxTest::TestSuite
{
    public:

        // Check for HTMGT library
        bool verifyModuleLoaded(const char *i_modname)
        {
            bool loadedLocally = false;

            if(!VFS::module_is_loaded(i_modname))
            {
                errlHndl_t l_err = VFS::module_load(i_modname);
                if( l_err )
                {
                    TS_FAIL("Could not load %s module", i_modname);
                    errlCommit(l_err,HTMGT_COMP_ID);
                }
                else
                {
                    loadedLocally = true;
                }
            }

            return loadedLocally;
        }


        // Get a target for the first OCC
        TARGETING::TargetHandle_t getFirstOccTarget()
        {
            TARGETING::TargetHandle_t o_occTarget = NULL;

            // Get all functional processors
            TARGETING::TargetHandleList pProcs;
            TARGETING::getChipResources(pProcs,
                                        TARGETING::TYPE_PROC,
                                        TARGETING::UTIL_FILTER_FUNCTIONAL);
            if (pProcs.size() > 0)
            {
                const uint8_t instance =
                    pProcs[0]->getAttr<TARGETING::ATTR_POSITION>();
                TS_TRACE("buildOccs: PROC%d is functional", instance);

                // Get functional OCC (one per proc)
                TARGETING::TargetHandleList pOccs;
                getChildChiplets(pOccs, pProcs[0], TARGETING::TYPE_OCC);
                if (pOccs.size() > 0)
                {
                    // Use first OCC target
                    TS_TRACE("getFirstOccTarget: Found OCC%d", instance);
                    o_occTarget = pOccs[0];
                }
            }
            if (NULL == o_occTarget)
            {
                TS_FAIL("getFirstOccTarget: did not find functional OCC");
            }

            return o_occTarget;
        }


        void test_occdataattr(void)
        {
            TS_TRACE("entered test_occdataattr");

            uint8_t occControlData[256];
            TargetHandleList procChips;
            getAllChips(procChips, TYPE_PROC, true);
            uint32_t index = 0;
            for (TargetHandleList::iterator itr = procChips.begin();
                 itr != procChips.end();
                 ++itr)
            {
                const uint32_t *wordPtr = (uint32_t*)occControlData;
                itr[index]->tryGetAttr<ATTR_OCC_CONTROL_DATA>(occControlData);
                TS_TRACE("test_occdataattr[%d]: 0x%08X ...",
                         index++, *wordPtr);
                // TODO RTC 109066
            }

            TS_TRACE("exiting test_occdataattr");
        }


        void test_occloadstartfail(void)
        {
            TS_TRACE("entered test_occloadstartfail");
            const bool locallyLoaded = verifyModuleLoaded("libhtmgt.so");

            TARGETING::TargetHandle_t failedOcc = getFirstOccTarget();
            HTMGT::processOccStartStatus(false, failedOcc);
            if (HTMGT::occMgr::instance().getNumOccs() != 0)
            {
                TS_FAIL("occloadstartfail: No OCCs should be available");
            }

            if (locallyLoaded)
            {
                VFS::module_unload("libhtmgt.so");
            }

            TS_TRACE("exiting test_occloadstartfail");
        }


        void test_occloadstartsuccess(void)
        {
            TS_TRACE("entered test_occloadstartsuccess");
            const bool locallyLoaded = verifyModuleLoaded("libhtmgt.so");

            HTMGT::processOccStartStatus(true);
            if (HTMGT::occMgr::instance().getNumOccs() == 0)
            {
                TS_FAIL("occloadstartsuccess: No OCCs are available");
            }

            if (locallyLoaded)
            {
                VFS::module_unload("libhtmgt.so");
            }

            TS_TRACE("exiting test_occloadstartsuccess");
        }


        void test_processoccerror(void)
        {
            TS_TRACE("entered test_processoccerror");
            const bool locallyLoaded = verifyModuleLoaded("libhtmgt.so");

                TARGETING::TargetHandle_t occTarget = getFirstOccTarget();
                HTMGT::occMgr::instance().buildOccs();
                if (HTMGT::occMgr::instance().getNumOccs() > 0)
                {
                    HTMGT::processOccError(occTarget);
                    // TODO RTC 109224
                }
                else
                {
                    TS_FAIL("processoccerror: Couldnt find a functional OCC");
                }

            if (locallyLoaded)
            {
                VFS::module_unload("libhtmgt.so");
            }

            TS_TRACE("exiting test_processoccerror");
        }

        void test_processoccreset(void)
        {
            TS_TRACE("entered test_processoccreset");
            const bool locallyLoaded = verifyModuleLoaded("libhtmgt.so");

            TARGETING::TargetHandle_t occTarget = getFirstOccTarget();
            HTMGT::occMgr::instance().buildOccs();
            if (HTMGT::occMgr::instance().getNumOccs() > 0)
            {
                HTMGT::processOccReset(occTarget);
                // TODO RTC 115296
            }
            else
            {
                TS_FAIL("processoccreset: Couldnt find a functional OCC");
            }

            if (locallyLoaded)
            {
                VFS::module_unload("libhtmgt.so");
            }

            TS_TRACE("exiting test_processoccreset");
        }

};

#endif
