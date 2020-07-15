/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2GetChildrenTest.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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

#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <fapi2.H>
#include <hwpf_fapi2_reasoncodes.H>
#include <fapi2TestUtils.H>
#include <cxxtest/TestSuite.H>
#include <functional>
#include <plat_utils.H>
#include <error_scope.H>

namespace fapi2
{

class Fapi2GetChildrenTest : public CxxTest::TestSuite
{
public:


        struct pervasiveChildTestRec {

            // Expected number of children
            uint32_t expectedSize;

            // Lambda function specifying which pervasive chip units map to
            // children of the type implied by the body of the lambda function
            // below
            bool (*unitMapsToRightTargetType)(TARGETING::ATTR_CHIP_UNIT_type);

            // Lambda function taking a pervasive target and returning the
            // number of children it has for a given FAPI type
            size_t (*actualSize)(Target<fapi2::TARGET_TYPE_PERV>&);
        };

//******************************************************************************
// test_fapi2GetChildren
//******************************************************************************
void test_fapi2GetChildren()
{
    uint32_t l_targetHuid = 0xFFFFFFFF;
    uint32_t l_actualSize = 0;
    uint32_t l_expectedSize = 0;
    errlHndl_t l_err = nullptr;
    int numTests = 0;
    int numFails = 0;

    do
    {
        GENERATE_TEST_TARGETS(test_fapi2GetChildren)

        // Creates some vectors for later use
        std::vector<Target<fapi2::TARGET_TYPE_CORE> > l_childCores;
        std::vector<Target<fapi2::TARGET_TYPE_EQ> > l_childEQs;
        std::vector<Target<fapi2::TARGET_TYPE_FC> > l_childFCs;
        std::vector<Target<fapi2::TARGET_TYPE_OMI> > l_childOMIs;
        std::vector<Target<fapi2::TARGET_TYPE_OCMB_CHIP> > l_childOCMBs;
        std::vector<Target<fapi2::TARGET_TYPE_MEM_PORT> > l_childMEMPORTs;
        std::vector<Target<fapi2::TARGET_TYPE_OMIC> > l_childOmics;
        std::vector<Target<fapi2::TARGET_TYPE_IOHS> > l_childIohss;

        if (isHwValid(l_proc, MY_MC)
            && isHwValid(l_proc, MY_MI)
            && isHwValid(l_proc, MY_MCC)
            && isHwValid(l_proc, MY_OMI))
        {
            l_childOMIs = fapi2_mcTarget.getChildren<fapi2::TARGET_TYPE_OMI>(TARGET_STATE_PRESENT);
            l_targetHuid = TARGETING::get_huid(targeting_targets[MY_MC]);
            l_actualSize = l_childOMIs.size();

            //Set expected size to be the number of OMIs per MC
            l_expectedSize = OMI_PER_MCC * MCC_PER_MI * MI_PER_MC;
            numTests++;
            if(l_actualSize != l_expectedSize)
            {
                TS_FAIL("test_fapi2GetChildren:: OMIs per MC mismatch");
                numFails++;
                break;
            }
        }

        l_childCores = fapi2_procTarget.getChildren<fapi2::TARGET_TYPE_CORE>(TARGET_STATE_PRESENT);
        l_targetHuid = TARGETING::get_huid(l_proc) ;
        l_actualSize = l_childCores.size();

        //Set expected size to be the number of cores per proc
        l_expectedSize = EQ_PER_PROC * FC_PER_EQ * CORE_PER_FC;
        numTests++;
        if(l_actualSize != l_expectedSize)
        {
            TS_FAIL("test_fapi2GetChildren:: present cores per proc mismatch");
            numFails++;
            break;
        }

        l_childCores = fapi2_procTarget.getChildren<fapi2::TARGET_TYPE_CORE>(TARGET_STATE_FUNCTIONAL);
        l_targetHuid = TARGETING::get_huid(l_proc) ;
        l_actualSize = l_childCores.size();

        //Set expected size to be the number of cores per proc
        //Nimbus model has 4 functional cores
        l_expectedSize = SIMULATED_GOOD_CORES;
        numTests++;
        if(l_actualSize != l_expectedSize)
        {
            TS_FAIL("test_fapi2GetChildren:: functional cores per proc mismatch");
            numFails++;
            break;
        }

        if (isHwValid(l_proc, MY_MC)
            && isHwValid(l_proc, MY_MI)
            && isHwValid(l_proc, MY_MCC)
            && isHwValid(l_proc, MY_OMI))
        {
            l_childOMIs = fapi2_procTarget.getChildren<fapi2::TARGET_TYPE_OMI>(TARGET_STATE_PRESENT);
            l_targetHuid = TARGETING::get_huid(l_proc);
            l_actualSize = l_childOMIs.size();

            //Set expected size to be the number of OMIs per proc
            l_expectedSize = OMI_PER_MCC * MCC_PER_MI * MI_PER_MC * MC_PER_PROC;
            numTests++;
            if(l_actualSize != l_expectedSize)
            {
                TS_FAIL("test_fapi2GetChildren:: OMIs per proc mismatch");
                numFails++;
                break;
            }
        }

        if (isHwValid(l_proc, MY_MCC)
            && isHwValid(l_proc, MY_OMI))
        {
            l_childOMIs = fapi2_mccTarget.getChildren<fapi2::TARGET_TYPE_OMI>(TARGET_STATE_PRESENT);
            l_targetHuid = TARGETING::get_huid(targeting_targets[MY_MCC]);
            l_actualSize = l_childOMIs.size();

            l_expectedSize = 2;
            numTests++;
            if(l_actualSize != l_expectedSize)
            {
                TS_FAIL("test_fapi2GetChildren:: # OMIs foound for MCC is %d and not %d",
                         l_actualSize, l_expectedSize);
                numFails++;
                break;
            }

            bool l_foundme = false;
            for( auto omi : l_childOMIs )
            {
                if( static_cast<TARGETING::Target*>(omi.get())
                    == targeting_targets[MY_OMI] )
                {
                    l_foundme = true;
                    break;
                }
            }
            if( !l_foundme )
            {
                TS_FAIL("OMI %.8X not found in child list for MCC %.8X",
                        TARGETING::get_huid(targeting_targets[MY_OMI]),
                        TARGETING::get_huid(targeting_targets[MY_MCC]));
            }
        }

        if (isHwValid(l_proc, MY_OMI)
            && isHwValid(l_proc, MY_OCMB))
        {
            l_childOCMBs = fapi2_omiTarget.getChildren<fapi2::TARGET_TYPE_OCMB_CHIP>(TARGET_STATE_PRESENT);
            l_targetHuid = TARGETING::get_huid(targeting_targets[MY_OMI]);
            l_actualSize = l_childOCMBs.size();

            //Set expected size to be the number of OMIs per proc
            l_expectedSize = OCMB_PER_OMI;
            numTests++;
            if(l_actualSize != l_expectedSize)
            {
                TS_FAIL("test_fapi2GetChildren:: OCMBs per proc mismatch");
                numFails++;
                break;
            }
        }

        if (isHwValid(l_proc, MY_OCMB)
            && isHwValid(l_proc, MY_MEM_PORT))
        {
            l_childMEMPORTs = fapi2_ocmbTarget.getChildren<fapi2::TARGET_TYPE_MEM_PORT>(TARGET_STATE_PRESENT);
            l_targetHuid = TARGETING::get_huid(targeting_targets[MY_OCMB]);
            l_actualSize = l_childOCMBs.size();

            //Set expected size to be the number of OMIs per proc
            l_expectedSize = MEM_PORT_PER_OCMB;
            numTests++;
            if(l_actualSize != l_expectedSize)
            {
                TS_FAIL("test_fapi2GetChildren:: MEM_PORTs per proc mismatch");
                numFails++;
                break;
            }
        }

        if (isHwValid(l_proc, MY_PAUC)
            && isHwValid(l_proc, MY_OMIC0)
            && isHwValid(l_proc, MY_IOHS))
        {
            l_childOmics = fapi2_paucTarget.getChildren<fapi2::TARGET_TYPE_OMIC>
                (TARGET_STATE_PRESENT);
            l_targetHuid = TARGETING::get_huid(targeting_targets[MY_PAUC]);
            l_actualSize = l_childOmics.size();

            //Set expected size to be the number of OMICs per PAUC
            l_expectedSize = OMIC_PER_PAUC;
            numTests++;
            if(l_actualSize != l_expectedSize)
            {
                TS_FAIL("test_fapi2GetChildren:: OMICs per PAUC mismatch. "
                        "Expected %d, returned %d",
                        l_expectedSize, l_actualSize);
                numFails++;
                break;
            }

            // Verify the existing PAUC/IOHS relationship is intact
            l_childIohss = fapi2_paucTarget.getChildren<fapi2::TARGET_TYPE_IOHS>
                (TARGET_STATE_PRESENT);
            l_actualSize = l_childIohss.size();
            //Set expected size to be the number of IOHSs per PAUC
            l_expectedSize = IOHS_PER_PAUC;
            numTests++;
            if(l_actualSize != l_expectedSize)
            {
                TS_FAIL("test_fapi2GetChildren:: IOHSs per PAUC mismatch. "
                        "Expected %d, returned %d",
                        l_expectedSize, l_actualSize);
                numFails++;
                break;
            }
        }


        l_childCores = fapi2_fcTarget.getChildren<fapi2::TARGET_TYPE_CORE>(TARGET_STATE_PRESENT);
        l_targetHuid = TARGETING::get_huid(targeting_targets[MY_FC]) ;
        l_actualSize = l_childCores.size();

        //Set expected size to be the number of cores per ex
        l_expectedSize = CORE_PER_FC;
        numTests++;
        if(l_actualSize != l_expectedSize)
        {
            TS_FAIL("test_fapi2GetChildren:: cores per FC mismatch");
            numFails++;
            break;
        }


        l_childCores = fapi2_eqTarget.getChildren<fapi2::TARGET_TYPE_CORE>(TARGET_STATE_PRESENT);
        l_targetHuid = TARGETING::get_huid(targeting_targets[MY_EQ]) ;
        l_actualSize = l_childCores.size();

        //Set expected size to be the number of cores per eq
        l_expectedSize = CORE_PER_FC * FC_PER_EQ;
        numTests++;
        if(l_actualSize != l_expectedSize)
        {
            TS_FAIL("test_fapi2GetChildren:: cores per EQ mismatch");
            numFails++;
            break;
        }


        //Explicitly make sure getChildren for FC targets works
        l_childFCs = fapi2_procTarget.getChildren<fapi2::TARGET_TYPE_FC>(TARGET_STATE_PRESENT);
        l_targetHuid = TARGETING::get_huid(l_proc) ;
        l_actualSize = l_childFCs.size();

        //Set expected size to be the number of Fcs per proc
        l_expectedSize = EQ_PER_PROC * FC_PER_EQ;
        numTests++;
        if(l_actualSize != l_expectedSize)
        {
            TS_FAIL("test_fapi2GetChildren:: FCs per proc mismatch");
            numFails++;
            break;
        }


        // Test pervasive children

        static pervasiveChildTestRec p10PervasiveChildTests [] = {

            // EQ pervasive has 1 EQ child
            {PERV_EQ_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return ((i_unit >= EQ_LOW) && (i_unit <= EQ_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_EQ>(
                         TARGET_STATE_PRESENT).size(); } },

            // CORE pervasive has 4 CORE children
            {PERV_CORE_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                 { return ((i_unit >= CORE_LOW) && (i_unit <= CORE_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_CORE>(
                         TARGET_STATE_PRESENT).size(); } },

            // PEC/PHB pervasive has 1 PEC child
            {PERV_PEC_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
              { return ((i_unit >= PEC_LOW) && (i_unit <= PEC_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_PEC>(
                         TARGET_STATE_PRESENT).size(); } },

            // PEC/PHB pervasive with 3 PHB children
            {PERV_PEC_PHB_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
              { return ((i_unit >= PEC_LOW) && (i_unit <= PEC_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_PHB>(
                         TARGET_STATE_PRESENT).size(); } },

            // MC / MI pervasive has 1 MC child
            {PERV_MC_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return (   (i_unit >= MC_LOW)
                            && (i_unit <= MC_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                  { return i_perv.getChildren<fapi2::TARGET_TYPE_MC>(
                          TARGET_STATE_PRESENT).size(); }  },

            // MC / MI pervasive has 1 MI child
            {PERV_MI_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return ((i_unit >= MC_LOW) && (i_unit <= MC_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                  { return i_perv.getChildren<fapi2::TARGET_TYPE_MI>(
                          TARGET_STATE_PRESENT).size(); } },

            // MC pervasive has 2 MI children
            {PERV_MCC_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return ((i_unit >= MC_LOW) && (i_unit <= MC_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                   { return i_perv.getChildren<fapi2::TARGET_TYPE_MCC>(
                           TARGET_STATE_PRESENT).size(); }  },

            // MC / MI / MCC / OMI pervasive has 4 OMI children
            {PERV_OMI_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return ((i_unit >= MC_LOW) && (i_unit <= MC_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                   { return i_perv.getChildren<fapi2::TARGET_TYPE_OMI>(
                           TARGET_STATE_PRESENT).size(); }  },

            // MC / MI pervasive has 2 OMIC children
            {PERV_OMIC_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return ((i_unit >= MC_LOW) && (i_unit <= MC_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                   { return i_perv.getChildren<fapi2::TARGET_TYPE_OMIC>(
                           TARGET_STATE_PRESENT).size(); }  },

            // first two PAUC pervasives have 1 PAU child
            {PERV_PAU_LOW_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return ((i_unit >= PAUC_LOW) && (i_unit <= PAUC_MID)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                   { return i_perv.getChildren<fapi2::TARGET_TYPE_PAU>(
                           TARGET_STATE_PRESENT).size(); }  },

            // second two PAUC pervasive have 2 PAU children
            {PERV_PAU_HIGH_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return ((i_unit > PAUC_MID) && (i_unit <= PAUC_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                   { return i_perv.getChildren<fapi2::TARGET_TYPE_PAU>(
                           TARGET_STATE_PRESENT).size(); }  },

            // IOHS pervasive has 1 IOHS children
            {PERV_IOHS_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return ((i_unit >= IOHS_LOW) && (i_unit <= IOHS_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                   { return i_perv.getChildren<fapi2::TARGET_TYPE_IOHS>(
                           TARGET_STATE_PRESENT).size(); }  },
        };

        pervasiveChildTestRec* ptr = nullptr;
        int numPervTests = 0;

        numPervTests = sizeof(p10PervasiveChildTests) / sizeof(pervasiveChildTestRec);
        ptr = p10PervasiveChildTests;

        // Build list of all pervasive targets in the blueprint
        TARGETING::TargetHandleList pervasiveTargets;
        TARGETING::getAllChiplets(
            pervasiveTargets,
            TARGETING::TYPE_PERV,
            false);

        // Test each type of target that can be a child of a pervasive
        for (int i = 0; i < numPervTests; ++i)
        {
            const pervasiveChildTestRec& pervasiveChildTest = ptr[i];
            l_expectedSize = pervasiveChildTest.expectedSize;
            l_actualSize = 0;
            l_targetHuid = 0;

            numTests++;
            TARGETING::TargetHandle_t candidateTarget = nullptr;
            for(TARGETING::TargetHandleList::const_iterator pIt
                    = pervasiveTargets.begin();
                pIt != pervasiveTargets.end();
                ++pIt)
            {
                auto unit = (*pIt)->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                if ( pervasiveChildTest.unitMapsToRightTargetType(unit) )
                {
                    candidateTarget = (*pIt);
                    break;
                }
            }

            if(candidateTarget == nullptr)
            {
                TS_FAIL("test_fapi2GetChildren:: candidateTarget not found");
                numFails++;
                continue;
            }

            l_targetHuid = TARGETING::get_huid(candidateTarget);

            Target<fapi2::TARGET_TYPE_PERV> fapi2_pervTarget(
                candidateTarget);

            l_actualSize = pervasiveChildTest.actualSize(fapi2_pervTarget);

            if(l_actualSize != l_expectedSize)
            {
                TS_FAIL("test_fapi2GetChildren:: children of pervasive mismatch: "
                        "HUID 0x%x, expected %d, got %d",
                        l_targetHuid, l_expectedSize,
                        l_actualSize);
                numFails++;
                continue;
            }

        }

        // Uncomment to test compile fails
        // std::vector<Target<fapi2::TARGET_TYPE_PROC_CHIP> > l_childProcs;
        // l_childProcs = fapi2_procTarget.getChildren<
        //     fapi2::TARGET_TYPE_PROC_CHIP>(TARGET_STATE_PRESENT);
        // l_childCores = fapi2_mcsTarget.getChildren<
        //     fapi2::TARGET_TYPE_CORE>(TARGET_STATE_PRESENT);

    }while(0);

    if(l_actualSize != l_expectedSize)
    {
        /*@
        * @errortype          ERRORLOG::ERRL_SEV_UNRECOVERABLE
        * @moduleid           fapi2::MOD_FAPI2_PLAT_GET_CHILDREN_TEST
        * @reasoncode         fapi2::RC_INVALID_CHILD_COUNT
        * @userdata1[0:31]    Expected Child Count
        * @userdata1[32:63]   Actual Child Count
        * @userdata2          Parent HUID
        * @devdesc            Invalid amount of child cores found
        *                     on a proc
        */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        fapi2::MOD_FAPI2_PLAT_GET_CHILDREN_TEST,
                                        fapi2::RC_INVALID_CHILD_COUNT,
                                        TWO_UINT32_TO_UINT64(
                                        TO_UINT32(
                                        l_expectedSize),
                                        TO_UINT32(
                                        l_actualSize)),
                                        l_targetHuid,
                                        true/*SW Error*/);
        errlCommit(l_err,HWPF_COMP_ID);
        TS_FAIL("test_fapi2GetChildren Fail, for HUID: 0x%x , expected %d children , found %d ", l_targetHuid,l_expectedSize,l_actualSize );
    }
    FAPI_INF("fapi2GetChildrenTest:: Test Complete. %d/%d fails",  numFails , numTests);
}

//******************************************************************************
// test_fapi2GetChildrenFilter
//******************************************************************************
void test_fapi2GetChildrenFilter()
{
    int numTests = 0;
    int numFails = 0;
/* # FIXME RTC:257497
    uint32_t l_targetHuid = 0xFFFFFFFF;
    uint32_t l_actualSize = 0;
    uint32_t l_expectedSize = 0;
    errlHndl_t l_err = nullptr;
*/
    TARGETING::Target * l_proc = nullptr;
    TARGETING::TargetHandleList l_chipList;
    do
    {
        FAPI_DBG("start of test_fapi2GetChildrenFilter()");

        numTests++;
        // Get a list of all of the proc chips
        TARGETING::getAllChips(l_chipList, TARGETING::TYPE_PROC, false);

        if(l_chipList.size())
        {
            l_proc = l_chipList[0];
        }
        else
        {
            TS_FAIL("test_fapi2GetChildren Fail: could not find any proc, skipping tests");
            numFails++;
            break;
        }
        TARGETING::Target* targeting_targets[NUM_TARGETS];
        generateTargets(l_proc, targeting_targets);

        numTests++;
        for( uint64_t x = 0; x < NUM_TARGETS; x++ )
        {
            //Skip tests where the HW unit to test isn't valid for the proc type
            if (!isHwValid(l_proc, x))
            {
                continue;
            }
            else if(targeting_targets[x] == nullptr)
            {
              numFails++;
              TS_FAIL("test_fapi2GetChildrenFilter Fail: Unable to find target for item %d in targeting_targets", x);
              break;
            }
        }

        // Start of the Tests
/*
# FIXME RTC:257497
# src/import/chips/p10/common/include/target_filters.H has not yet defined
# TARGET_FILTER_ALL_CORES, TARGET_FILTER_CORE1, and
# TARGET_FILTER_SYNC_MODE_ALL_IO_EXCEPT_NEST which are used below.

        Target<fapi2::TARGET_TYPE_PROC_CHIP> fapi2_procTarget(
                l_proc);

        std::vector<Target<fapi2::TARGET_TYPE_PERV> > l_childPERVs;

        // PERV - TARGET_FILTER_ALL_CORES
        l_expectedSize = 24;
        l_childPERVs = fapi2_procTarget.getChildren<fapi2::TARGET_TYPE_PERV>(
                                                             TARGET_FILTER_ALL_CORES,
                                                             TARGET_STATE_PRESENT);
        l_targetHuid = TARGETING::get_huid(l_proc) ;
        l_actualSize = l_childPERVs.size();
        numTests++;
        if(l_actualSize != l_expectedSize)
        {
            numFails++;
            break;
        }

        // PERV - TARGET_FILTER_CORE1
        l_expectedSize = 1;
        l_childPERVs = fapi2_procTarget.getChildren<fapi2::TARGET_TYPE_PERV>(
                                                             TARGET_FILTER_CORE1,
                                                             TARGET_STATE_PRESENT);
        l_targetHuid = TARGETING::get_huid(l_proc) ;
        l_actualSize = l_childPERVs.size();
        numTests++;
        if(l_actualSize != l_expectedSize)
        {
            numFails++;
            break;
        }

        if (isHwValid(l_proc, MY_MC))
        {
            // PERV - TARGET_FILTER_ALL_MC
            l_expectedSize = 2;
            l_childPERVs = fapi2_procTarget.getChildren<fapi2::TARGET_TYPE_PERV>(
                                                             TARGET_FILTER_ALL_MC,
                                                             TARGET_STATE_PRESENT);
            l_targetHuid = TARGETING::get_huid(l_proc) ;
            l_actualSize = l_childPERVs.size();
            numTests++;
            if(l_actualSize != l_expectedSize)
            {
                numFails++;
                break;
            }
        }

        // PERV - SYNC_MODE_ALL_IO_EXCEPT_NEST
        l_expectedSize = 8;
        l_childPERVs = fapi2_procTarget.getChildren<fapi2::TARGET_TYPE_PERV>(
                                                             TARGET_FILTER_SYNC_MODE_ALL_IO_EXCEPT_NEST,
                                                             TARGET_STATE_PRESENT);
        l_targetHuid = TARGETING::get_huid(l_proc) ;
        l_actualSize = l_childPERVs.size();
        numTests++;
        if(l_actualSize != l_expectedSize)
        {
            numFails++;
            break;
        }
*/

    }while(0);

    // # FIXME RTC:257497
    // if(l_actualSize != l_expectedSize)
    // {
    //     /*@
    //     * @errortype          ERRORLOG::ERRL_SEV_UNRECOVERABLE
    //     * @moduleid           fapi2::MOD_FAPI2_PLAT_GET_CHILDREN_FILTER_TEST
    //     * @reasoncode         fapi2::RC_INVALID_CHILD_COUNT
    //     * @userdata1[0:31]    Expected Child Count
    //     * @userdata1[32:63]   Actual Child Count
    //     * @userdata2          Parent HUID
    //     * @devdesc            Invalid amount of child cores found
    //     *                     on a proc
    //     */
    //     l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
    //                                     fapi2::MOD_FAPI2_PLAT_GET_CHILDREN_FILTER_TEST,
    //                                     fapi2::RC_INVALID_CHILD_COUNT,
    //                                     TWO_UINT32_TO_UINT64(
    //                                     TO_UINT32(
    //                                     l_expectedSize),
    //                                     TO_UINT32(
    //                                     l_actualSize)),
    //                                     l_targetHuid,
    //                                     true/*SW Error*/);
    //     errlCommit(l_err,HWPF_COMP_ID);
    //     TS_FAIL("test_fapi2GetChildrenFilter Fail, for HUID: 0x%X , expected %d children , found %d ", l_targetHuid,l_expectedSize,l_actualSize );
    // }

    FAPI_INF("test_fapi2GetChildrenFilter: Test Complete. %d/%d fails",  numFails , numTests);
}

//******************************************************************************
// test_fapi2GetChildrenFilter
// Currently only test DIMM aspects of interface
//******************************************************************************
void test_fapi2getChildTargetsForCDG()
{
    int numTests = 0;
    int numFails = 0;
    TARGETING::Target * l_proc = nullptr;
    size_t l_expectedDimms = 0;
    TARGETING::TargetHandleList l_chipList;

    do
    {
        FAPI_DBG("start of test_fapi2getChildTargetsForCDG()");

        numTests++;
        // Get a list of all of the proc chips
        TARGETING::getAllChips(l_chipList, TARGETING::TYPE_PROC, false);

        if(l_chipList.size())
        {
            l_proc = l_chipList[0];
        }
        else
        {
            TS_FAIL("test_fapi2getChildTargetsForCDG Fail: could not find any proc, skipping tests");
            numFails++;
            break;
        }

        l_expectedDimms = 8;

        Target<fapi2::TARGET_TYPE_PROC_CHIP> fapi2_procTarget(l_proc);
        // Now get all dimms under this processor
        TARGETING::TargetHandleList l_dimmList;
        fapi2::getChildTargetsForCDG(fapi2_procTarget,
                fapi2::TARGET_TYPE_DIMM,
                0xff,  // All ports
                0xff,  // All sockets
                l_dimmList);

        FAPI_INF("test_fapi2getChildTargetsForCDG: Dimms under proc 0x%.08X is %d",
                TARGETING::get_huid(l_proc),l_dimmList.size());
        numTests++;
        if(l_dimmList.size() != l_expectedDimms)
        {
            TS_FAIL("test_fapi2getChildTargetsForCDG: Dimm count %d not equal expected %d",
                    l_dimmList.size(),l_expectedDimms);
            numFails++;
        }

    }while(0);

    FAPI_INF("test_fapi2getChildTargetsForCDG: Test Complete. %d/%d fails",  numFails , numTests);
}

};

} // namespace fapi2
