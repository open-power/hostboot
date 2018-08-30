/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2GetParentTest.H $                     */
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

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <fapi2.H>
#include <hwpf_fapi2_reasoncodes.H>
#include <fapi2TestUtils.H>

using namespace fapi2;

class Fapi2GetParentTest : public CxxTest::TestSuite
{
public:

// Check units which have a pervasive parent
struct pervasiveParentTestRec {
    // Source unit from which to find parent pervasive
    TARGETING::Target* pTarget;
    // Lambda function taking a unit target and returning its
    // parent pervasive target (if any)
    TARGETING::Target* (*getParent)(TARGETING::Target* i_pTarget);
};

void test_fapi2GetParentPervasive(int& numTests, int& numFails,
                                  const pervasiveParentTestRec[],
                                  TARGETING::Target *);

//******************************************************************************
// fapi2GetParentTest
//******************************************************************************
void test_fapi2GetParent()
{
    errlHndl_t l_err = nullptr;
    int numTests = 0;
    int numFails = 0;
    do
    {
        GENERATE_TEST_TARGETS(test_fapi2GetChildren)

#define GET_PARENT_TEST_MACRO(TEST_TARGET_ID, SRC_TYPE, PARENT_TEST_TARGET_ID, PARENT_TYPE)                    \
    {                                                                                                          \
        fapi2::Target<SRC_TYPE> l_src(targeting_targets[TEST_TARGET_ID]);                                      \
        TARGETING::Target * l_parent = static_cast<TARGETING::Target*>(l_src.getParent<PARENT_TYPE>());        \
        numTests++;                                                                                            \
        if(TARGETING::get_huid(targeting_targets[PARENT_TEST_TARGET_ID]) !=                                    \
            TARGETING::get_huid(l_parent))                                                                     \
        {                                                                                                      \
            TS_FAIL("fapi2TargetTest::Unable to find SRC_TYPE's" #PARENT_TYPE "parent!");                      \
            numFails++;                                                                                        \
        }                                                                                                      \
    }

    //// Start Common Targets
    // EQ Parent Tests
    GET_PARENT_TEST_MACRO(MY_EQ, TARGET_TYPE_EQ, MY_PROC, TARGET_TYPE_PROC_CHIP)
    // EX Parent Tests
    GET_PARENT_TEST_MACRO(MY_EX, TARGET_TYPE_EX, MY_EQ,   TARGET_TYPE_EQ)
    GET_PARENT_TEST_MACRO(MY_EX, TARGET_TYPE_EX, MY_PROC, TARGET_TYPE_PROC_CHIP)
    // Core Parent Tests
    GET_PARENT_TEST_MACRO(MY_CORE, TARGET_TYPE_CORE, MY_EX,   TARGET_TYPE_EX)
    GET_PARENT_TEST_MACRO(MY_CORE, TARGET_TYPE_CORE, MY_EQ,   TARGET_TYPE_EQ)
    GET_PARENT_TEST_MACRO(MY_CORE, TARGET_TYPE_CORE, MY_PROC, TARGET_TYPE_PROC_CHIP)
    // PHB Parent Test
    GET_PARENT_TEST_MACRO(MY_PHB, TARGET_TYPE_PHB, MY_PROC, TARGET_TYPE_PROC_CHIP)
    // PEC Parent Test
    GET_PARENT_TEST_MACRO(MY_PEC, TARGET_TYPE_PEC, MY_PROC, TARGET_TYPE_PROC_CHIP)
    // XBUS Parent Test
    GET_PARENT_TEST_MACRO(MY_XBUS, TARGET_TYPE_XBUS, MY_PROC, TARGET_TYPE_PROC_CHIP)
    // OBUS Parent Test
    GET_PARENT_TEST_MACRO(MY_OBUS, TARGET_TYPE_OBUS, MY_PROC, TARGET_TYPE_PROC_CHIP)
    // OBUS Brick Parent Test
    GET_PARENT_TEST_MACRO(MY_OBUS_BRICK, TARGET_TYPE_OBUS_BRICK, MY_PROC, TARGET_TYPE_PROC_CHIP)
    GET_PARENT_TEST_MACRO(MY_OBUS_BRICK, TARGET_TYPE_OBUS_BRICK, MY_OBUS, TARGET_TYPE_OBUS)
    // PPE Parent Test
    GET_PARENT_TEST_MACRO(MY_PPE, TARGET_TYPE_PPE, MY_PROC, TARGET_TYPE_PROC_CHIP)
    // PERV Parent Test
    GET_PARENT_TEST_MACRO(MY_PERV, TARGET_TYPE_PERV, MY_PROC, TARGET_TYPE_PROC_CHIP)
    // CAPP Parent Test
    GET_PARENT_TEST_MACRO(MY_CAPP, TARGET_TYPE_CAPP, MY_PROC, TARGET_TYPE_PROC_CHIP)
    // SBE Parent Test
    GET_PARENT_TEST_MACRO(MY_SBE, TARGET_TYPE_SBE, MY_PROC, TARGET_TYPE_PROC_CHIP)
    ////End Common Targets

    //// Start Nimbus only Targets
    // MCA Parent Tests
    if (isHwValid(l_proc, MY_MCA))
    {
        // Check proc parent
        GET_PARENT_TEST_MACRO(MY_MCA, TARGET_TYPE_MCA, MY_PROC, TARGET_TYPE_PROC_CHIP)
        if(isHwValid(l_proc, MY_MCS))
        {
            // Check MCS parent
            GET_PARENT_TEST_MACRO(MY_MCA, TARGET_TYPE_MCA, MY_MCS, TARGET_TYPE_MCS)
        }
        if(isHwValid(l_proc, MY_MCBIST))
        {
            // Check MCBIST parent
            GET_PARENT_TEST_MACRO(MY_MCA, TARGET_TYPE_MCA, MY_MCBIST, TARGET_TYPE_MCBIST)
        }
    }
    // MCS Parent Tests
    if (isHwValid(l_proc, MY_MCBIST) &&
        isHwValid(l_proc, MY_MCS))
    {
        GET_PARENT_TEST_MACRO(MY_MCS, TARGET_TYPE_MCS, MY_MCBIST, TARGET_TYPE_MCBIST)
        GET_PARENT_TEST_MACRO(MY_MCS, TARGET_TYPE_MCS, MY_PROC, TARGET_TYPE_PROC_CHIP)
    }
    // MCBIST Parent Test
    if (isHwValid(l_proc, MY_MCBIST))
    {
        GET_PARENT_TEST_MACRO(MY_MCBIST, TARGET_TYPE_MCBIST, MY_PROC, TARGET_TYPE_PROC_CHIP)
    }
    //// End NIMBUS targets

    //// Start Cumulus/Axone common targets
    // MC Parent Test
    if (isHwValid(l_proc, MY_MC))
    {
        // Check parent proc
        GET_PARENT_TEST_MACRO(MY_MC, TARGET_TYPE_MC, MY_PROC, TARGET_TYPE_PROC_CHIP)
    }
    // MI Parent Tests
    if (isHwValid(l_proc, MY_MC) &&
        isHwValid(l_proc, MY_MI))
    {
        // Check parent MC
        GET_PARENT_TEST_MACRO(MY_MI, TARGET_TYPE_MI, MY_MC, TARGET_TYPE_MC)
        // Check parent proc
        GET_PARENT_TEST_MACRO(MY_MI, TARGET_TYPE_MI, MY_PROC, TARGET_TYPE_PROC_CHIP)
    }
    //// End Cumulus/Axone common targets

    //// Start Cumulus only targets
    // DMI Parent Tests
    if (isHwValid(l_proc, MY_DMI))
    {
        // Check parent proc
        GET_PARENT_TEST_MACRO(MY_DMI, TARGET_TYPE_DMI, MY_PROC, TARGET_TYPE_PROC_CHIP)
        if(isHwValid(l_proc, MY_MI))
        {
            // Check parent MI
            GET_PARENT_TEST_MACRO(MY_DMI, TARGET_TYPE_DMI, MY_MI, TARGET_TYPE_MI)
        }
        if(isHwValid(l_proc, MY_MC))
        {
            // Check parent MC
            GET_PARENT_TEST_MACRO(MY_DMI, TARGET_TYPE_DMI, MY_MC, TARGET_TYPE_MC)
        }
    }
    //// End Cumulus only targets

    //// Start Axone only targets
    // MCC Parent Tests
    if (isHwValid(l_proc, MY_MCC))
    {
        // Check parent proc
        GET_PARENT_TEST_MACRO(MY_MCC, TARGET_TYPE_MCC, MY_PROC, TARGET_TYPE_PROC_CHIP)
        if(isHwValid(l_proc, MY_MI))
        {
            // Check parent MI
            GET_PARENT_TEST_MACRO(MY_MCC, TARGET_TYPE_MCC, MY_MI, TARGET_TYPE_MI)
        }
        if(isHwValid(l_proc, MY_MC))
        {
            // Check parent MC
            GET_PARENT_TEST_MACRO(MY_MCC, TARGET_TYPE_MCC, MY_MC, TARGET_TYPE_MC)
        }
    }
    // OMIC Parent Tests
    if (isHwValid(l_proc, MY_MC)  &&
        isHwValid(l_proc, MY_OMIC))
    {
        // Check parent MC
        GET_PARENT_TEST_MACRO(MY_OMI, TARGET_TYPE_OMIC, MY_MC, TARGET_TYPE_MC)
        // Check parent proc
        GET_PARENT_TEST_MACRO(MY_OMI, TARGET_TYPE_OMIC, MY_PROC, TARGET_TYPE_PROC_CHIP)
    }
    // OMI Parent Tests
    if (isHwValid(l_proc, MY_OMI))
    {
        // Check parent proc
        GET_PARENT_TEST_MACRO(MY_OMI, TARGET_TYPE_OMI, MY_PROC, TARGET_TYPE_PROC_CHIP)
        if (isHwValid(l_proc, MY_MCC))
        {
            // Check parent MCC
            GET_PARENT_TEST_MACRO(MY_OMI, TARGET_TYPE_OMI, MY_MCC, TARGET_TYPE_MCC)
        }
        if (isHwValid(l_proc, MY_OMIC))
        {
            // Check parent OMIC
            GET_PARENT_TEST_MACRO(MY_OMI, TARGET_TYPE_OMI, MY_OMIC, TARGET_TYPE_OMIC)
        }
        if (isHwValid(l_proc, MY_MI))
        {
            // Check parent MI
            GET_PARENT_TEST_MACRO(MY_OMI, TARGET_TYPE_OMI, MY_MI, TARGET_TYPE_MI)
        }
        if (isHwValid(l_proc, MY_MC))
        {
            // Check parent MC
            GET_PARENT_TEST_MACRO(MY_OMI, TARGET_TYPE_OMI, MY_MC, TARGET_TYPE_MC)
        }
    }
    // OCMB Parent Tests
    if (isHwValid(l_proc, MY_OCMB))
    {
        if (isHwValid(l_proc, MY_OMI))
        {
            // Check parent OMI
            GET_PARENT_TEST_MACRO(MY_OCMB, TARGET_TYPE_OCMB_CHIP, MY_OMI, TARGET_TYPE_OMI)
        }
    }
    // MEM_PORT Parent Tests
    if (isHwValid(l_proc, MY_MEM_PORT))
    {
        if (isHwValid(l_proc, MY_OCMB))
        {
            // Check parent OCMB
            GET_PARENT_TEST_MACRO(MY_MEM_PORT, TARGET_TYPE_MEM_PORT, MY_OCMB, TARGET_TYPE_OCMB_CHIP)
        }
    }
    // End Axone only targets

        static pervasiveParentTestRec nimbusPervasiveParentTests [] = {
             {targeting_targets[MY_EQ],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_EQ>(i_pTarget); }},
            {targeting_targets[MY_CORE],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_CORE>(i_pTarget); }},
            {targeting_targets[MY_MCS],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_MCS>(i_pTarget); }},
            {targeting_targets[MY_MCA],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_MCA>(i_pTarget); }},
            {targeting_targets[MY_MCBIST],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_MCBIST>(i_pTarget);}},
            {targeting_targets[MY_PEC],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_PEC>(i_pTarget); }},
            {targeting_targets[MY_PHB],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_PHB>(i_pTarget); }},
            {targeting_targets[MY_XBUS],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_XBUS>(i_pTarget); }},
            {targeting_targets[MY_OBUS],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_OBUS>(i_pTarget); }},
            {targeting_targets[MY_OBUS_BRICK],
             [](TARGETING::Target* i_pTarget)
               {return getPervasiveParent<TARGET_TYPE_OBUS_BRICK>(i_pTarget);}},
            {targeting_targets[MY_CAPP],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_CAPP>(i_pTarget); }},
          };

        static pervasiveParentTestRec cumulusPervasiveParentTests [] = {
            {targeting_targets[MY_EQ],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_EQ>(i_pTarget); }},
            {targeting_targets[MY_CORE],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_CORE>(i_pTarget); }},
            {targeting_targets[MY_PEC],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_PEC>(i_pTarget); }},
            {targeting_targets[MY_PHB],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_PHB>(i_pTarget); }},
            {targeting_targets[MY_XBUS],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_XBUS>(i_pTarget); }},
            {targeting_targets[MY_OBUS],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_OBUS>(i_pTarget); }},
            {targeting_targets[MY_OBUS_BRICK],
             [](TARGETING::Target* i_pTarget)
               {return getPervasiveParent<TARGET_TYPE_OBUS_BRICK>(i_pTarget);}},
            {targeting_targets[MY_CAPP],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_CAPP>(i_pTarget); }},
            {targeting_targets[MY_MC],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_MC>(i_pTarget); }},
            {targeting_targets[MY_MI],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_MI>(i_pTarget); }},
            {targeting_targets[MY_DMI],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_DMI>(i_pTarget); }},
          };

        static pervasiveParentTestRec axonePervasiveParentTests [] = {
            {targeting_targets[MY_EQ],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_EQ>(i_pTarget); }},
            {targeting_targets[MY_CORE],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_CORE>(i_pTarget); }},
            {targeting_targets[MY_PEC],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_PEC>(i_pTarget); }},
            {targeting_targets[MY_PHB],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_PHB>(i_pTarget); }},
            {targeting_targets[MY_XBUS],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_XBUS>(i_pTarget); }},
            {targeting_targets[MY_OBUS],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_OBUS>(i_pTarget); }},
            {targeting_targets[MY_OBUS_BRICK],
             [](TARGETING::Target* i_pTarget)
               {return getPervasiveParent<TARGET_TYPE_OBUS_BRICK>(i_pTarget);}},
            {targeting_targets[MY_CAPP],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_CAPP>(i_pTarget); }},
            {targeting_targets[MY_MC],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_MC>(i_pTarget); }},
            {targeting_targets[MY_MI],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_MI>(i_pTarget); }},
            {targeting_targets[MY_MCC],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_MCC>(i_pTarget); }},
            {targeting_targets[MY_OMI],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_OMI>(i_pTarget); }},
            {targeting_targets[MY_OMIC],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_OMIC>(i_pTarget); }},
          };

        pervasiveParentTestRec* ptr;
        int numPervTests = 0;
        auto l_model = l_proc->getAttr<TARGETING::ATTR_MODEL>();
        if (l_model == TARGETING::MODEL_NIMBUS)
        {
            numPervTests = sizeof(nimbusPervasiveParentTests) / sizeof(pervasiveParentTestRec);
            ptr = nimbusPervasiveParentTests;
        }
        else if (l_model == TARGETING::MODEL_CUMULUS)
        {
            numPervTests = sizeof(cumulusPervasiveParentTests) / sizeof(pervasiveParentTestRec);
            ptr = cumulusPervasiveParentTests;
        }
        else
        {
            numPervTests = sizeof(axonePervasiveParentTests) / sizeof(pervasiveParentTestRec);
            ptr = axonePervasiveParentTests;
        }

        // Test each type of target that can have exactly one pervasive parent
        for (int i = 0; i < numPervTests; ++i)
        {
            const pervasiveParentTestRec& pervasiveParentTest = ptr[i];
            numTests++;
            if (pervasiveParentTest.pTarget == nullptr)
            {
                FAPI_ERR("Found pervasive parent to be null pervasiveParentTestRec for test: %d",
                          i);
            }
            TARGETING::Target * l_tempTargetingParent = pervasiveParentTest.getParent(
                pervasiveParentTest.pTarget);

            // Result must be a non-nullptr target of pervasive type, and its
            // parent must be the same proc as the other tests above
            TARGETING::Target* pPervasiveParent = nullptr;
            if(    l_tempTargetingParent
               && (   l_tempTargetingParent->getAttr<TARGETING::ATTR_TYPE>()
                   == TARGETING::TYPE_PERV))
            {
                Target<TARGET_TYPE_PERV> fapi2_pervTarg(l_tempTargetingParent);
                pPervasiveParent = static_cast<TARGETING::Target*>(
                    fapi2_pervTarg.getParent<TARGET_TYPE_PROC_CHIP>());
            }

            // If the parent of the target under test was nullptr, or it was
            // not a pervasive, or if the parent of the pervasive was nullptr
            // or was not the processor, fail the test
            if(TARGETING::get_huid(l_proc) !=
               TARGETING::get_huid(pPervasiveParent))
            {
                TARGETING::ATTR_CHIP_UNIT_type instance = 0;
                TARGETING::ATTR_TYPE_type type = TARGETING::TYPE_NA;
                pervasiveParentTest.pTarget->
                    tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(instance);
                pervasiveParentTest.pTarget->
                    tryGetAttr<TARGETING::ATTR_TYPE>(type);

                /*@
                * @errortype         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                * @moduleid          fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST
                * @reasoncode        fapi2::RC_UNIT_NO_PERV_FOUND
                * @userdata1[0:31]   Actual PROC HUID
                * @userdata1[32:63]  Actual PERV HUID
                * @userdata2[0:31]   Source unit's "chip unit"
                * @userdata2[32:63]  Source unit's "targeting type"
                * @devdesc           Could not find the parent PERV of this
                *                    unit target or the pervasive did not
                *                    map to expected PROC
                */
                l_err = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST,
                    fapi2::RC_UNIT_NO_PERV_FOUND,
                    TWO_UINT32_TO_UINT64(
                        TO_UINT32(
                            TARGETING::get_huid(pPervasiveParent)),
                        TO_UINT32(
                            TARGETING::get_huid(l_tempTargetingParent))),
                    TWO_UINT32_TO_UINT64(
                        TO_UINT32(instance),
                        TO_UINT32(type)),
                    true/*SW Error*/);

                errlCommit(l_err,HWPF_COMP_ID);
                TS_FAIL("fapi2TargetTest::Unable to find unit's pervasive!");
                numFails++;
            }
        }
    } while(0);

    FAPI_INF("fapi2GetParentTest:: Test Complete. %d/%d fails", numFails, numTests);
}


};
