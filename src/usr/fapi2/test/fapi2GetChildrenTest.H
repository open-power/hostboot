/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2GetChildrenTest.H $                   */
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

#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <fapi2.H>
#include <hwpf_fapi2_reasoncodes.H>
#include <fapi2TestUtils.H>
#include <cxxtest/TestSuite.H>
#include <functional>


#include <error_scope.H>


class Fapi2GetChildrenTest : public CxxTest::TestSuite
{
public:
//******************************************************************************
// test_fapi2GetParent
//******************************************************************************
void test_fapi2GetChildren()
{
    int numTests = 0;
    int numFails = 0;
    uint32_t l_targetHuid = 0xFFFFFFFF;
    uint32_t l_actualSize = 0;
    uint32_t l_expectedSize = 0;
    errlHndl_t l_err = NULL;
    TARGETING::Target * l_nimbusProc = NULL;
    do
    {
        // Create a vector of TARGETING::Target pointers
        TARGETING::TargetHandleList l_chipList;

        // Get a list of all of the proc chips
        TARGETING::getAllChips(l_chipList, TARGETING::TYPE_PROC, false);

        //Take the first NIMBUS proc and use it
        for(uint32_t i = 0; i < l_chipList.size(); i++)
        {
            if(TARGETING::MODEL_NIMBUS ==
            l_chipList[i]->getAttr<TARGETING::ATTR_MODEL>())
            {
              l_nimbusProc = l_chipList[i];
              break;
            }
        }
        numTests++;
        if(l_nimbusProc == NULL)
        {
            // Send an errorlog because we cannot find any NIMBUS procs.
            FAPI_ERR("FAPI2_GETPARENT:: could not find Nimbus proc, skipping tests");
            numFails++;
            /*@
            * @errortype    ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid     fapi2::MOD_FAPI2_PLAT_GET_CHILDREN_TEST
            * @reasoncode   fapi2::RC_NO_PROCS_FOUND
            * @userdata1    Model Type we looked for
            * @userdata2    Unused
            * @devdesc      Could not find NIMBUS procs in system model
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            fapi2::MOD_FAPI2_PLAT_GET_CHILDREN_TEST,
                                            fapi2::RC_NO_PROCS_FOUND,
                                            TARGETING::MODEL_NIMBUS,
                                            NULL,
                                            true/*SW Error*/);
            errlCommit(l_err,HWPF_COMP_ID);
            break;
        }

        TARGETING::Target* targeting_targets[NUM_TARGETS];
        generateTargets(l_nimbusProc, targeting_targets);

        for( uint64_t x = 0; x < NUM_TARGETS; x++ )
        {
            if(targeting_targets[x] == NULL)
            {
              FAPI_ERR("Unable to find target for item %d in targeting_targets", x);
              /*@
              * @errortype    ERRORLOG::ERRL_SEV_UNRECOVERABLE
              * @moduleid     fapi2::MOD_FAPI2_PLAT_GET_CHILDREN_TEST
              * @reasoncode   fapi2::RC_NO_PATH_TO_TARGET_FOUND
              * @userdata1    Index of target in array of objects
              * @userdata2    Unused
              * @devdesc      Could not find a path to the target of that type
              */
              l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                              fapi2::MOD_FAPI2_PLAT_GET_CHILDREN_TEST,
                                              fapi2::RC_NO_PATH_TO_TARGET_FOUND,
                                              x,
                                              NULL,
                                              true/*SW Error*/);
              errlCommit(l_err,HWPF_COMP_ID);
            }
        }

        Target<fapi2::TARGET_TYPE_PROC_CHIP> fapi2_procTarget(
                l_nimbusProc);
        Target<fapi2::TARGET_TYPE_EQ> fapi2_eqTarget(
                targeting_targets[MY_EQ]);
        Target<fapi2::TARGET_TYPE_EX> fapi2_exTarget(
                targeting_targets[MY_EX]);
        Target<fapi2::TARGET_TYPE_MCS> fapi2_mcsTarget(
                targeting_targets[MY_MCS]);;
        Target<fapi2::TARGET_TYPE_MCBIST> fapi2_mcbistTarget(
                targeting_targets[MY_MCBIST]);



        std::vector<Target<fapi2::TARGET_TYPE_CORE> > l_childCores;
        std::vector<Target<fapi2::TARGET_TYPE_MCA> > l_childMCAs;
        std::vector<Target<fapi2::TARGET_TYPE_EQ> > l_childEQs;
        std::vector<Target<fapi2::TARGET_TYPE_XBUS> > l_childXBUSs;
//      @TODO RTC:148761
//      Need to figure out how we are going to set up this relationship
//         l_childMCAs = fapi2_mcbistTarget.getChildren<fapi2::TARGET_TYPE_MCA>(TARGET_STATE_PRESENT);
//         l_targetHuid = TARGETING::get_huid(targeting_targets[MY_MCBIST]) ;
//         l_actualSize = l_childMCAs.size();
//
//         //Set expected size to be the number of MCAs per MCBIST
//         l_expectedSize = MCA_PER_MCS * MCS_PER_PROC / MCBIST_PER_PROC;
//         numTests++;
//         if(l_actualSize != l_expectedSize)
//         {
//             FAPI_INF("fapi2TargetTest:: MCAs per MCBIST mismatch");
//             numFails++;
//             break;
//         }

        l_childCores = fapi2_procTarget.getChildren<fapi2::TARGET_TYPE_CORE>(TARGET_STATE_PRESENT);
        l_targetHuid = TARGETING::get_huid(l_nimbusProc) ;
        l_actualSize = l_childCores.size();

        //Set expected size to be the number of cores per proc
        l_expectedSize = EQ_PER_PROC * EX_PER_EQ * CORE_PER_EX;
        numTests++;
        if(l_actualSize != l_expectedSize)
        {
            FAPI_INF("fapi2TargetTest:: present cores per proc mismatch");
            numFails++;
            break;
        }

        l_childCores = fapi2_procTarget.getChildren<fapi2::TARGET_TYPE_CORE>(TARGET_STATE_FUNCTIONAL);
        l_targetHuid = TARGETING::get_huid(l_nimbusProc) ;
        l_actualSize = l_childCores.size();

        //Set expected size to be the number of cores per proc
        //Nimbus model has 4 functional cores
        l_expectedSize = SIMULATED_GOOD_CORES;
        numTests++;
        if(l_actualSize != l_expectedSize)
        {
            FAPI_INF("fapi2TargetTest:: functional cores per proc mismatch");
            numFails++;
            break;
        }

        l_childMCAs = fapi2_procTarget.getChildren<fapi2::TARGET_TYPE_MCA>(TARGET_STATE_PRESENT);
        l_targetHuid = TARGETING::get_huid(l_nimbusProc) ;
        l_actualSize = l_childMCAs.size();

        //Set expected size to be the number of MCAs per proc
        l_expectedSize = MCA_PER_MCS * MCS_PER_PROC;
        numTests++;
        if(l_actualSize != l_expectedSize)
        {
            FAPI_INF("fapi2TargetTest:: MCAs per proc mismatch");
            numFails++;
            break;
        }

        l_childCores = fapi2_exTarget.getChildren<fapi2::TARGET_TYPE_CORE>(TARGET_STATE_PRESENT);
        l_targetHuid = TARGETING::get_huid(targeting_targets[MY_EX]) ;
        l_actualSize = l_childCores.size();

        //Set expected size to be the number of cores per ex
        l_expectedSize = CORE_PER_EX;
        numTests++;
        if(l_actualSize != l_expectedSize)
        {
            FAPI_INF("fapi2TargetTest:: cores per EX mismatch");
            numFails++;
            break;
        }

        l_childCores = fapi2_eqTarget.getChildren<fapi2::TARGET_TYPE_CORE>(TARGET_STATE_PRESENT);
        l_targetHuid = TARGETING::get_huid(targeting_targets[MY_EQ]) ;
        l_actualSize = l_childCores.size();

        //Set expected size to be the number of cores per eq
        l_expectedSize = CORE_PER_EX * EX_PER_EQ;
        numTests++;
        if(l_actualSize != l_expectedSize)
        {
            FAPI_INF("fapi2TargetTest:: cores per EQ mismatch");
            numFails++;
            break;
        }

        // Test pervasive children

        // Valid children for PERV:
        // PERV -> EQ   // PERV -> CORE // PERV -> XBUS   // PERV -> OBUS
        // PERV -> CAPP // PERV -> NV   // PERV -> MCBIST // PERV -> MCS
        // PERV -> MCA  // PERV -> PEC  // PERV -> PHB    // PERV -> MI
        // PERV -> DMI

        static struct pervasiveChildTestRec {

            // Expected number of children
            uint32_t expectedSize;

            // Lambda function specifying which pervasive chip units map to
            // children of the type implied by the body of the lambda function
            // below
            bool (*unitMapsToRightTargetType)(TARGETING::ATTR_CHIP_UNIT_type);

            // Lambda function taking a pervasive target and returning the
            // number of children it has for a given FAPI type
            size_t (*actualSize)(Target<fapi2::TARGET_TYPE_PERV>&);

        } pervasiveChildTests [] = {

            // EQ pervasive has 1 EQ child
            {PERV_EQ_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return ((i_unit >= EQ_LOW) && (i_unit <= EQ_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_EQ>(
                   TARGET_STATE_PRESENT).size(); } },

            // CORE pervasive has 1 CORE child
            {PERV_CORE_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                 { return ((i_unit >= CORE_LOW) && (i_unit <= CORE_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_CORE>(
                   TARGET_STATE_PRESENT).size(); } },

            // XBUS pervasive has 2 XBUS children
            {PERV_XBUS_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return (i_unit == XBUS_RANGE); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_XBUS>(
                   TARGET_STATE_PRESENT).size(); } },

            // OBUS pervasive has 1 OBUS child
            {PERV_OBUS_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return ((i_unit >= OBUS_LOW) && (i_unit <= OBUS_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_OBUS>(
                   TARGET_STATE_PRESENT).size(); } },

            // CAPP pervasive has 1 CAPP child
            {PERV_CAPP_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                { return ((i_unit == CAPP0_RANGE) || (i_unit == CAPP1_RANGE));},
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_CAPP>(
                   TARGET_STATE_PRESENT).size(); } },

            // NV pervasive has 2 NV children
            {PERV_NV_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return (i_unit == NV_RANGE); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_NV>(
                   TARGET_STATE_PRESENT).size(); } },

            // MCBIST/MCS/MCA pervasive has 1 MCBIST child
            {PERV_MCBIST_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return (   (i_unit >= MC_LOW)
                            && (i_unit <= MC_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_MCBIST>(
                   TARGET_STATE_PRESENT).size(); } },

            // MCBIST/MCS/MCA pervasive has 2 MCS children
            {PERV_MCS_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return ((i_unit >= MC_LOW) && (i_unit <= MC_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_MCS>(
                   TARGET_STATE_PRESENT).size(); } },

            // MCBIST/MCS/MCA pervasive has 4 MCA children
            {PERV_MCA_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return ((i_unit >= MC_LOW) && (i_unit <= MC_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_MCA>(
                   TARGET_STATE_PRESENT).size(); } },

            // PEC/PHB pervasive has 1 PEC child
            {PERV_PEC_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return ((i_unit >= PEC_LOW) && (i_unit <= PEC_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_PEC>(
                   TARGET_STATE_PRESENT).size(); } },

            // PEC/PHB pervasive with 1 PHB child
            {PERV_PEC0_PHB_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return (i_unit == PEC_LOW); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_PHB>(
                   TARGET_STATE_PRESENT).size(); } },

            // PEC/PHB pervasive with 2 PHB children
            {PERV_PEC1_PHB_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return (i_unit == PEC_MID); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_PHB>(
                   TARGET_STATE_PRESENT).size(); } },

            // PEC/PHB pervasive with 3 PHB children
            {PERV_PEC2_PHB_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return (i_unit == PEC_HIGH); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_PHB>(
                   TARGET_STATE_PRESENT).size(); } },

            // No MI or DMI units for Nimbus
        };

        // Build list of all pervasive targets in the blueprint
        TARGETING::TargetHandleList pervasiveTargets;
        TARGETING::getAllChiplets(
            pervasiveTargets,
            TARGETING::TYPE_PERV,
            false);

        // Test each type of target that can be a child of a pervasive
        for(const pervasiveChildTestRec& pervasiveChildTest
                : pervasiveChildTests)
        {
            l_expectedSize = pervasiveChildTest.expectedSize;
            l_actualSize = 0;
            l_targetHuid = 0;

            numTests++;
            TARGETING::TargetHandle_t candidateTarget = NULL;
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

            if(candidateTarget == NULL)
            {
                FAPI_INF("fapi2TargetTest:: candidateTarget not found");
                numFails++;
                break;
            }

            l_targetHuid = TARGETING::get_huid(candidateTarget);

            Target<fapi2::TARGET_TYPE_PERV> fapi2_pervTarget(
                candidateTarget);

            l_actualSize = pervasiveChildTest.actualSize(fapi2_pervTarget);

            if(l_actualSize != l_expectedSize)
            {
                FAPI_INF("fapi2TargetTest:: children of pervasive mismatch");
                numFails++;
                break;
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
        TS_FAIL("fapi2TargetTest Fail, for HUID: %d , expected %d children , found %d ", l_targetHuid,l_expectedSize,l_actualSize );
    }
    FAPI_INF("fapi2GetChildrenTest:: Test Complete. %d/%d fails",  numFails , numTests);
}




};
