/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2GetParentTest.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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
        TARGETING::Target * l_parent = l_src.getParent<PARENT_TYPE>().get(); \
        numTests++;                                                                                            \
        if(TARGETING::get_huid(targeting_targets[PARENT_TEST_TARGET_ID]) !=                                    \
            TARGETING::get_huid(l_parent))                                                                     \
        {                                                                                                      \
            TS_FAIL("test_fapi2GetParent::Unable to find " #SRC_TYPE "'s " #PARENT_TYPE " parent!");           \
            FAPI_INF("Found=%.8X, Expected=%.8X",                                                              \
                     TARGETING::get_huid(l_parent),                                                            \
                     TARGETING::get_huid(targeting_targets[PARENT_TEST_TARGET_ID]));                           \
            numFails++;                                                                                        \
        }                                                                                                      \
    }

    //// Start Common Targets
    // EQ Parent Tests
    GET_PARENT_TEST_MACRO(MY_EQ, TARGET_TYPE_EQ, MY_PROC, TARGET_TYPE_PROC_CHIP)
    // FC Parent Tests
    GET_PARENT_TEST_MACRO(MY_FC, TARGET_TYPE_FC, MY_EQ,   TARGET_TYPE_EQ)
    GET_PARENT_TEST_MACRO(MY_FC, TARGET_TYPE_FC, MY_PROC, TARGET_TYPE_PROC_CHIP)
    // Core Parent Tests
    GET_PARENT_TEST_MACRO(MY_CORE, TARGET_TYPE_CORE, MY_FC,   TARGET_TYPE_FC)
    GET_PARENT_TEST_MACRO(MY_CORE, TARGET_TYPE_CORE, MY_EQ,   TARGET_TYPE_EQ)
    GET_PARENT_TEST_MACRO(MY_CORE, TARGET_TYPE_CORE, MY_PROC, TARGET_TYPE_PROC_CHIP)
    GET_PARENT_TEST_MACRO(MY_CORE, TARGET_TYPE_CORE | TARGET_TYPE_MULTICAST, MY_PROC, TARGET_TYPE_PROC_CHIP)
    // PHB Parent Test
    GET_PARENT_TEST_MACRO(MY_PHB, TARGET_TYPE_PHB, MY_PROC, TARGET_TYPE_PROC_CHIP)
    // PEC Parent Test
    GET_PARENT_TEST_MACRO(MY_PEC, TARGET_TYPE_PEC, MY_PROC, TARGET_TYPE_PROC_CHIP)
    // PAUC Parent Test
    GET_PARENT_TEST_MACRO(MY_PAUC, TARGET_TYPE_PAUC, MY_PROC, TARGET_TYPE_PROC_CHIP)
    // IOHS Parent Test
    GET_PARENT_TEST_MACRO(MY_IOHS, TARGET_TYPE_IOHS, MY_PAUC, TARGET_TYPE_PAUC)
    // IOLINK Parent Test
    GET_PARENT_TEST_MACRO(MY_IOLINK, TARGET_TYPE_IOLINK, MY_PAUC, TARGET_TYPE_PAUC)
    GET_PARENT_TEST_MACRO(MY_IOLINK, TARGET_TYPE_IOLINK, MY_IOHS, TARGET_TYPE_IOHS)
    // PAU Parent Test
    GET_PARENT_TEST_MACRO(MY_PAU, TARGET_TYPE_PAU, MY_PAUC, TARGET_TYPE_PAUC)
    // PERV Parent Test
    GET_PARENT_TEST_MACRO(MY_PERV, TARGET_TYPE_PERV, MY_PROC, TARGET_TYPE_PROC_CHIP)
    ////End Common Targets

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
        isHwValid(l_proc, MY_OMIC0))
    {
        // Check parent MC
        GET_PARENT_TEST_MACRO(MY_OMIC0, TARGET_TYPE_OMIC, MY_MC, TARGET_TYPE_MC)
        // Check parent proc
        GET_PARENT_TEST_MACRO(MY_OMIC0, TARGET_TYPE_OMIC, MY_PROC, TARGET_TYPE_PROC_CHIP)
    }
    if (isHwValid(l_proc, MY_PAUC)  &&
        isHwValid(l_proc, MY_OMIC1))
    {
        // Check parent PAUC
        GET_PARENT_TEST_MACRO(MY_OMIC1, TARGET_TYPE_OMIC, MY_PAUC, TARGET_TYPE_PAUC)
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
        if (isHwValid(l_proc, MY_OMIC0))
        {
            // Check parent OMIC
            GET_PARENT_TEST_MACRO(MY_OMI, TARGET_TYPE_OMI, MY_OMIC0, TARGET_TYPE_OMIC)
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

        static pervasiveParentTestRec p10PervasiveParentTests [] = {
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
            {targeting_targets[MY_OMIC0],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_OMIC>(i_pTarget); }},
          };

        pervasiveParentTestRec* ptr = p10PervasiveParentTests;
        int numPervTests = sizeof(p10PervasiveParentTests) / sizeof(pervasiveParentTestRec);

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
                pPervasiveParent = fapi2_pervTarg.getParent<TARGET_TYPE_PROC_CHIP>().get();
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
                * @custdesc          An internal firmware error occurred
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
                TS_FAIL("test_fapi2GetParent::Unable to find unit's pervasive!");
                numFails++;
            }
        }
    } while(0);

    FAPI_INF("fapi2GetParentTest:: Test Complete. %d/%d fails", numFails, numTests);
}


};
