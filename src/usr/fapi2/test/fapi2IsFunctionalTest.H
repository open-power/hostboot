/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2IsFunctionalTest.H $                  */
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

#include <fapi2.H>
#include <commontargeting.H>
#include <cxxtest/TestSuite.H>
#include "fapi2TestUtils.H"


namespace fapi2
{

class Fapi2IsFunctional : public CxxTest::TestSuite
{

    public:
    //**************************************************************************
    // test_fapi2IsFunctional
    //**************************************************************************
    void test_fapi2IsFunctional()
    {
        int numTests = 0;
        int numFails = 0;

        TARGETING::HwasState currentState;
        bool functional;
        TARGETING::Target * currTarg;

        FAPI_DBG("Enter test_fapi2IsFunctional");
        do
        {
            // get the master proc
            TARGETING::Target * proc;
            TARGETING::targetService().masterProcChipTargetHandle(proc);

            // create targeting/fapi2 target arrays to hold targets
            // *Note: NUM_TARGETS does not include the processor target
            //  so we make the array big enough to add it.
            TARGETING::Target*  targetList[NUM_TARGETS+1];
            fapi2::Target<fapi2::TARGET_TYPE_ALL> fapiTargetList[NUM_TARGETS+1];

            // generate the TARGETING::Targets to test on and add them
            // to targeting array
            generateTargets(proc, targetList);

            // add the processor target to the end of the list
            targetList[NUM_TARGETS] = proc;

            // Verify we generated valid targets
            for( uint64_t x = 0; x <= NUM_TARGETS; x++ )
            {
                if(targetList[x] == NULL)
                {
                   TS_FAIL("fapi2IsFunctionalTest: Unable to find target at index [%d]",
                           x);
                }
            }

            //populate fapiTargetList
            // EQ
            Target<fapi2::TARGET_TYPE_EQ> fapi2_eqTarget(
                    targetList[MY_EQ]);
            fapiTargetList[MY_EQ] = fapi2_eqTarget;

            // EX
            Target<fapi2::TARGET_TYPE_EX> fapi2_exTarget(
                    targetList[MY_EX]);
            fapiTargetList[MY_EX] = fapi2_exTarget;

            // CORE
            Target<fapi2::TARGET_TYPE_CORE> fapi2_coreTarget(
                    targetList[MY_CORE]);
            fapiTargetList[MY_CORE] = fapi2_coreTarget;

            // MCS
            Target<fapi2::TARGET_TYPE_MCS> fapi2_mcsTarget(
                    targetList[MY_MCS]);
            fapiTargetList[MY_MCS] = fapi2_mcsTarget;

            // MCA
            Target<fapi2::TARGET_TYPE_MCA> fapi2_mcaTarget(
                    targetList[MY_MCA]);
            fapiTargetList[MY_MCA] = fapi2_mcaTarget;

            // MCBIST
            Target<fapi2::TARGET_TYPE_MCBIST> fapi2_mcbistTarget(
                    targetList[MY_MCBIST]);
            fapiTargetList[MY_MCBIST] = fapi2_mcbistTarget;

            // PEC
            Target<fapi2::TARGET_TYPE_PEC> fapi2_pecTarget(
                    targetList[MY_PEC]);
            fapiTargetList[MY_PEC] = fapi2_pecTarget;

            // PHB
            Target<fapi2::TARGET_TYPE_PHB> fapi2_phbTarget(
                    targetList[MY_PHB]);
            fapiTargetList[MY_PHB] = fapi2_phbTarget;

            // XBUS
            Target<fapi2::TARGET_TYPE_XBUS> fapi2_xbusTarget(
                    targetList[MY_XBUS]);
            fapiTargetList[MY_XBUS] = fapi2_xbusTarget;

            // OBUS
            Target<fapi2::TARGET_TYPE_OBUS> fapi2_obusTarget(
                    targetList[MY_OBUS]);
            fapiTargetList[MY_OBUS] = fapi2_obusTarget;

            // NV
            Target<fapi2::TARGET_TYPE_NV> fapi2_nvTarget(
                    targetList[MY_NV]);
            fapiTargetList[MY_NV] = fapi2_nvTarget;

            // PPE
            Target<fapi2::TARGET_TYPE_PPE> fapi2_ppeTarget(
                    targetList[MY_PPE]);
            fapiTargetList[MY_PPE] = fapi2_ppeTarget;

            // PERV
            Target<fapi2::TARGET_TYPE_PERV> fapi2_pervTarget(
                    targetList[MY_PERV]);
            fapiTargetList[MY_PERV] = fapi2_pervTarget;

            // SBE
            Target<fapi2::TARGET_TYPE_SBE> fapi2_sbeTarget(
                    targetList[MY_SBE]);
            fapiTargetList[MY_SBE] = fapi2_sbeTarget;

            // CAPP
            Target<fapi2::TARGET_TYPE_CAPP> fapi2_cappTarget(
                    targetList[MY_CAPP]);
            fapiTargetList[MY_CAPP] = fapi2_cappTarget;

            // PROC_CHIP
            Target<fapi2::TARGET_TYPE_PROC_CHIP> fapi2_procTarget(
                    targetList[NUM_TARGETS]);
            fapiTargetList[NUM_TARGETS] = fapi2_procTarget;



            // Iterate through both arrays comparing ATTR_HWAS_STATE
            // against the return of fapi2::Target<K> isFunctional()
            for( int i = 0; i <= NUM_TARGETS; i++ )
            {
                numTests++;

                currTarg = targetList[i];

                // get the HWAS_STATE of the current target
                currentState = currTarg->getAttr<TARGETING::ATTR_HWAS_STATE>();

                functional = fapiTargetList[i].isFunctional();

                if(currentState.functional != functional)
                {
                    TS_FAIL("The functional state is incorrect. huid: 0x%x - "
                            "Functional State (Expected/Actual): (%d/%d)",
                            TARGETING::get_huid(currTarg),
                            currentState.functional,
                            functional);
                    numFails++;
                }

            }
        } while(0);
        FAPI_INF("test_fapi2IsFunctional Test Complete. %d/%d fails",
                  numFails,
                  numTests);
    } // end test_fapi2IsFunctional()

}; // end class

}// end namespace fapi2

