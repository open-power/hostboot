/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/test/testTextAttrOvd.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2024                             */
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
#ifndef TESTTESTATTROVD_H
#define TESTTESTATTROVD_H

/**
 *  @file testTextAttrOvd.H
 *
 *  @brief Test cases for text based attribute override
*/

#include <cstdint>
#include <cxxtest/TestSuite.H>

#include <pnor/pnorif.H>
#include <kernel/bltohbdatamgr.H>
#include <targeting/common/attributeTank.H>
#include <vector>
#include <targeting/common/target.H>
#include <attributetraits.H>
#include <secureboot/service.H>
#include <targeting/attrPlatOverride.H>
#include <targeting/common/util.H>

using namespace TARGETING;

#define POS_NA AttributeTank::ATTR_POS_NA
#define UNIT_NA AttributeTank::ATTR_UNIT_POS_NA
#define NODE_NA AttributeTank::ATTR_NODE_NA

struct FAPINAME_test {
    ATTR_FAPI_NAME_type string;
    bool expctdResult;
    uint8_t expctdNode{NODE_NA};
    uint16_t expctdPos{POS_NA};
    uint8_t expctdUnitPos{UNIT_NA};
};

class TextAttrOvdTest: public CxxTest::TestSuite
{
public:
    // ASCII to be loaded into ATTR_TMP
    const char* attrText =  "target = k0:s0\n"
                            "ATTR_SCRATCH_UINT8_1 0x12\n"
                            "ATTR_SCRATCH_UINT32_1 0x12345678\n"
                            "ATTR_SCRATCH_UINT64_1 0x8000000000000001 CONST\n"

                            "target = k0:s0:n0:ocmb:p04\n"
                            "ATTR_MRU_ID 0x2328\n"
                            "target = ocmb:k0:n0:s0:p05\n"
                            "ATTR_MRU_ID 0x232C\n"

                            "target = k0:s0:n0:dimm:p16,20\n"
                            "ATTR_ISTEP_CALLOUT_INJECT_ACTION 0xCC\n"

                            "target = k0:s0:n0:dimm:p16\n"
                            "ATTR_NV_OPS_TIMEOUT_MSEC[0] 0x1\n"
                            "ATTR_NV_OPS_TIMEOUT_MSEC[1] 0x2\n"
                            "ATTR_NV_OPS_TIMEOUT_MSEC[2] 0x3\n"
                            "ATTR_NV_OPS_TIMEOUT_MSEC[3] 0x4\n"
                            "ATTR_NV_OPS_TIMEOUT_MSEC[4] 0x5\n"
                            "ATTR_NV_OPS_TIMEOUT_MSEC[5] 0x6\n"

                            "target = k0:s0:n0:p10:pall\n"
                            "ATTR_SCRATCH_UINT32_1 0xDEADBEEF\n"

                            "target = k0:s0:n0:tpm:p0\n"
                            "ATTR_MRU_ID 0xBA\n"

                            "target = k0:s0:nall:pu.c:p01:c7\n"
                            "ATTR_ISTEP_CALLOUT_INJECT_ACTION 0xC0FFEEBABE123456 CONST\n"

                            "target = k0:s0:n0:temp_sensor:p1\n"
                            "ATTR_ISTEP_CALLOUT_INJECT_ACTION 0x44\n"

                            "target = k0:s0:n0:power_ic:p2\n"
                            "ATTR_ISTEP_CALLOUT_INJECT_ACTION 0xDE\n"

                            "target = k0:s0:n0:pmic:p3\n"
                            "ATTR_ISTEP_CALLOUT_INJECT_ACTION 0x7777777777777777\n";

    static constexpr FAPINAME_test fapinameTestArr[] = {
        {"k0",                      true, NODE_NA, POS_NA, UNIT_NA},
        {"k0:s0",                   true, NODE_NA, POS_NA, UNIT_NA},
        {"NA",                      false, NODE_NA, POS_NA, UNIT_NA},
        {"ocmb:k0:n0:s0:p05",       true, 0, 5, UNIT_NA},
        {"k0:s0:n0:ocmb:p05",       false, NODE_NA, POS_NA, UNIT_NA},
        {"ocmb:k0:s0:n0:p05",       false, NODE_NA, POS_NA, UNIT_NA},
        {"ocmb:k0:n0:s0:p05:d4",    false, NODE_NA, POS_NA, UNIT_NA},
        {"pu.c:k0:n0:s0:p05:c7",    true, 0, 5, 7},
        {"pu.c:k0:n0:s0:p05:c7:d4", false, NODE_NA, POS_NA, UNIT_NA},
        {"c0:k0:n0:s0:p05",         false, NODE_NA, POS_NA, UNIT_NA},
        {"node:k0:n1:s0",           true, 1, POS_NA, UNIT_NA},
        {"tpm:k0:s0:n0:p320",       false, NODE_NA, POS_NA, UNIT_NA},
        {"pu.c:k0:s0:n0:p320:c1",   false, NODE_NA, POS_NA, UNIT_NA},
        {"pu.omi:k0:n0:s0:p20:c12", false, NODE_NA, POS_NA, UNIT_NA},
        {"pu.omi:k0:n9:s0:p99:c8",  true, 9, 99, 8},
        {"pu.omi:k0:n0:s0:c0",      false, NODE_NA, POS_NA, UNIT_NA},
        {"pu.omi:k0:n0:s0:c01",     false, NODE_NA, POS_NA, UNIT_NA},
    };

    /**
    * @brief Tests values of attribute overrides
    *
    * Loads attribute text into memory and tests the values
    * of overrode attributes to make sure they are correct.
    * For xall targets we only test a handful of examples,
    * because simics doesnt model everything
    *
    */
    void testAttrOvd(void)
    {
        TS_INFO(ENTER_MRK"testAttrOvd");

        loadAttrText();

        TargetHandle_t l_targ;

        // target = k0:s0
        l_targ = Target::getTargetFromHuid(0x00010000);
        if (l_targ)
        {
            // ATTR_SCRATCH_UINT8_1 0x12
            ATTR_SCRATCH_UINT8_1_type val1 = 0xFF;
            l_targ->tryGetAttr<ATTR_SCRATCH_UINT8_1>(val1);
            if (val1 != 0x12)
            {
                TS_FAIL("Attribute override failed. (k0:s0 ATTR_SCRATCH_UINT8_1) "
                        "expctd: 0x12 actual: 0x%X", val1);
            }
            // ATTR_SCRATCH_UINT32_1 0x12345678
            ATTR_SCRATCH_UINT32_1_type val2 = 0xFFFFFFFF;
            l_targ->tryGetAttr<ATTR_SCRATCH_UINT32_1>(val2);
            if (val2 != 0x12345678)
            {
                TS_FAIL("Attribute override failed. (k0:s0 ATTR_SCRATCH_UINT32_1) "
                        "expctd: 0x12345678 actual: 0x%X", val2);
            }
            // ATTR_SCRATCH_UINT64_1 0x8000000000000001 CONST
            ATTR_SCRATCH_UINT64_1_type val3 = 0xFFFFFFFFFFFFFFFF;
            l_targ->tryGetAttr<ATTR_SCRATCH_UINT64_1>(val3);
            if (val3 != 0x8000000000000001)
            {
                TS_FAIL("Attribute override failed. (k0:s0 ATTR_SCRATCH_UINT64_1) "
                        "expctd: 0x8000000000000001 actual: 0x%X", val3);
            }

            // check function of CONST and not CONST
            l_targ->setAttr<ATTR_SCRATCH_UINT32_1>(0x54321);
            l_targ->setAttr<ATTR_SCRATCH_UINT64_1>(0x800000005);

            // ATTR_SCRATCH_UINT32_1 0x12345678 -> 0x54321
            val2 = l_targ->getAttr<ATTR_SCRATCH_UINT32_1>();
            if (val2 != 0x54321)
            {
                TS_FAIL("setAttr failed, override is not CONST. (k0:s0 ATTR_SCRATCH_UINT32_1) "
                        "expctd: 0x54321 actual: 0x%X", val2);
            }
            // ATTR_SCRATCH_UINT64_1 0x8000000000000001 CONST
            val3 = l_targ->getAttr<ATTR_SCRATCH_UINT64_1>();
            if (val3 != 0x8000000000000001)
            {
                TS_FAIL("Attribute override is CONST, but value was changed. (k0:s0 ATTR_SCRATCH_UINT64_1) "
                        "expctd: 0x8000000000000001 actual: 0x%X", val3);
            }
        }
        else
        {
            TS_FAIL("Could not find system target (k0:s0)");
        }

        // target = k0:s0:n0:ocmb:p04
        l_targ = Target::getTargetFromHuid(0x004B0004);
        if (l_targ)
        {
            // ATTR_MRU_ID 0x2328
            ATTR_MRU_ID_type ocmbVal = 0xFFFF;
            l_targ->tryGetAttr<ATTR_MRU_ID>(ocmbVal);
            if (ocmbVal != 0x2328)
            {
                TS_FAIL("Attribute override failed. (k0:s0:n0:ocmb:p04 ATTR_MRU_ID) "
                        "expctd: 0x2328 actual: 0x%X", ocmbVal);
            }
        }
        else
        {
            TS_FAIL("Could not find OCMB target (k0:s0:n0:ocmb:p04)")
        }

        // target = ocmb:k0:n0:s0:p05
        l_targ = Target::getTargetFromHuid(0x004B0005);
        if (l_targ)
        {
            // ATTR_MRU_ID 0x232C
            ATTR_MRU_ID_type ocmbVal = 0xFFFF;
            l_targ->tryGetAttr<ATTR_MRU_ID>(ocmbVal);
            if (ocmbVal != 0x232C)
            {
                TS_FAIL("Attribute override failed. (k0:s0:n0:ocmb:p05 ATTR_MRU_ID) "
                        "expctd: 0x2328 actual: 0x%X", ocmbVal);
            }
        }
        else
        {
            TS_FAIL("Could not find OCMB target (k0:s0:n0:ocmb:p05)")
        }

        // target = k0:s0:n0:dimm:p16,20
        for (ATTR_HUID_type huid: {0x00030010,0x00030014})
        {
            l_targ = Target::getTargetFromHuid(huid);
            if (l_targ)
            {
                // ATTR_ISTEP_CALLOUT_INJECT_ACTION 0xCC
                ATTR_ISTEP_CALLOUT_INJECT_ACTION_type val = 0xFF;
                l_targ->tryGetAttr<ATTR_ISTEP_CALLOUT_INJECT_ACTION>(val);
                if (val != 0xCC)
                {
                    TS_FAIL("Attribute override failed. (k0:s0:n0:dimm:p2,4 ATTR_ISTEP_CALLOUT_INJECT_ACTION) "
                            "expctd: 0xCC actual: 0x%X HUID: 0x%08X", val, huid);
                }
            }
            else
            {
                TS_FAIL("Unable to find dimm target (HUID 0x%08X)", huid);
            }
        }

        // target = k0:s0:n0:dimm:p16
        l_targ = Target::getTargetFromHuid(0x00030010);
        if (l_targ)
        {
            // check function of override arrays
            // ATTR_NV_OPS_TIMEOUT_MSEC[0] 0x1 ...
            ATTR_NV_OPS_TIMEOUT_MSEC_typeStdArr utilPoints;
            if (l_targ->tryGetAttr<ATTR_NV_OPS_TIMEOUT_MSEC>(utilPoints))
            {
                for (uint64_t i = 0; i < utilPoints.size(); i++)
                {
                    if (utilPoints[i] != i + 1)
                    {
                        TS_FAIL("Attribute override failed. "
                                "(k0:s0:n0:dimm:p16 ATTR_NV_OPS_TIMEOUT_MSEC[%d]) "
                                "expctd: 0x%X actual: 0x%X",
                                i, i + 1, utilPoints[i]);
                        break;
                    }
                }
            }
            else
            {
                TS_FAIL("Failed to get attribute ATTR_NV_OPS_TIMEOUT_MSEC");
            }
        }
        else
        {
            TS_FAIL("Unable to find dimm target (k0:s0:n0:dimm:p16)");
        }

        // target = k0:s0:n0:p10:pall
        for (ATTR_HUID_type huid: {0x00050000,0x00050001})
        {
            l_targ = Target::getTargetFromHuid(huid);
            if (l_targ)
            {
                // ATTR_SCRATCH_UINT32_1 0xDEADBEEF
                ATTR_SCRATCH_UINT32_1_type val = 0xFFFFFFFF;
                l_targ->tryGetAttr<ATTR_SCRATCH_UINT32_1>(val);
                if (val != 0xDEADBEEF)
                {
                    TS_FAIL("Attribute override failed. (k0:s0:n0:p10:pall ATTR_SCRATCH_UINT32_1) "
                            "expctd: 0xDEADBEEF actual: 0x%X (HUID 0x%08X)", val, huid);
                }
            }
            else
            {
                TS_FAIL("Unable to find proc (HUID 0x%08X)", huid);
            }
        }

        // target = k0:s0:n0:tpm:p0
        l_targ = Target::getTargetFromHuid(0x00310000);
        if (l_targ)
        {
            // ATTR_MRU_ID 0xBA
            ATTR_MRU_ID_type tpmVal = 0xFF;
            l_targ->tryGetAttr<ATTR_MRU_ID>(tpmVal);
            if (tpmVal != 0xBA)
            {
                TS_FAIL("Attribute override failed. (k0:s0:n0:tpm:p0 ATTR_MRU_ID) "
                        "expctd: 0xBA actual: 0x%X", tpmVal);
            }
        }
        else
        {
            TS_FAIL("Could not find tpm target (k0:s0:n0:tpm:p0)");
        }

        // target = k0:s0:nall:pu.c:p01:c7
        l_targ = Target::getTargetFromHuid(0x00070027);
        if (l_targ)
        {
            // ATTR_ISTEP_CALLOUT_INJECT_ACTION 0xC0FFEEBABE123456 CONST
            ATTR_ISTEP_CALLOUT_INJECT_ACTION_type coreVal = 0xFFFFFFFFFFFFFFFF;
            l_targ->tryGetAttr<ATTR_ISTEP_CALLOUT_INJECT_ACTION>(coreVal);
            if (coreVal != 0xC0FFEEBABE123456)
            {
                TS_FAIL("Attribute override failed. (k0:s0:nall:pu.c:p01:c7 ATTR_ISTEP_CALLOUT_INJECT_ACTION) "
                        "expctd: 0xC0FFEEBABE123456 actual: 0x%X HUID: 0x%08X", coreVal, get_huid(l_targ));
            }
        }
        else
        {
            TS_FAIL("Could not find core target (k0:s0:nall:pu.c:p01:c7)");
        }

        // target = k0:s0:n0:temp_sensor:p1
        l_targ = Target::getTargetFromHuid(0x00670001);
        if (l_targ)
        {
            // ATTR_ISTEP_CALLOUT_INJECT_ACTION 0x44
            ATTR_ISTEP_CALLOUT_INJECT_ACTION_type tempSensorVal = 0xFF;
            l_targ->tryGetAttr<ATTR_ISTEP_CALLOUT_INJECT_ACTION>(tempSensorVal);
            if (tempSensorVal != 0x44)
            {
                TS_FAIL("Attribute override failed. (k0:s0:n0:temp_sensor:p1 ATTR_ISTEP_CALLOUT_INJECT_ACTION) "
                        "expctd: 0x44 actual: 0x%X", tempSensorVal);
            }
        }
        else
        {
            TS_INFO("Couldn't find temp_sensor target, skipping");
        }

        // target = k0:s0:n0:power_ic:p2
        l_targ = Target::getTargetFromHuid(0x00660002);
        // only 4U systems have this target, skip if not
        if (l_targ)
        {
            // ATTR_ISTEP_CALLOUT_INJECT_ACTION 0xDE
            ATTR_ISTEP_CALLOUT_INJECT_ACTION_type powerICVal = 0xFF;
            l_targ->tryGetAttr<ATTR_ISTEP_CALLOUT_INJECT_ACTION>(powerICVal);
            if (powerICVal != 0xDE)
            {
                TS_FAIL("Attribute override failed. (k0:s0:n0:power_ic:p2 ATTR_ISTEP_CALLOUT_INJECT_ACTION) "
                        "expctd: 0xDE actual: 0x%X", powerICVal);
            }
        }
        else
        {
            TS_INFO("Couldn't find power_ic target, skipping");
        }

        // target = k0:s0:n0:pmic:p3
        l_targ = Target::getTargetFromHuid(0x004E0003);
        // only 4U systems have this target, skip if not
        if (l_targ)
        {
            // ATTR_ISTEP_CALLOUT_INJECT_ACTION 0x7777777777777777
            ATTR_ISTEP_CALLOUT_INJECT_ACTION_type PMICval = 0xFFFFFFFFFFFFFFFF;
            l_targ->tryGetAttr<ATTR_ISTEP_CALLOUT_INJECT_ACTION>(PMICval);
            if (PMICval != 0x7777777777777777)
            {
                TS_FAIL("Attribute override failed. (k0:s0:n0:pmic:p3 ATTR_ISTEP_CALLOUT_INJECT_ACTION) "
                        "expctd: 0x7777777777777777 actual: 0x%X", PMICval);
            }
        }
        else
        {
            TS_INFO("Couldn't find pmic target, skipping");
        }

        Target::theTargOverrideAttrTank().clearAllAttributes();

        TS_INFO(EXIT_MRK"testAttrOvd");
    }

    /**
    * @brief Tests functions used to get position info
    *
    * Tests that getPosFromFapiName returns correct info
    *
    */
    void testGetPosInfo(void)
    {
        TS_INFO(ENTER_MRK"testGetPosInfo");

        bool result;
        uint16_t o_pos;
        uint8_t o_unitPos;
        uint8_t o_node;

        for (FAPINAME_test test: fapinameTestArr)
        {
            result = getPosFromFapiName(test.string, o_pos, o_unitPos, o_node);

            if (result != test.expctdResult ||
                o_pos != test.expctdPos ||
                o_unitPos != test.expctdUnitPos ||
                o_node != test.expctdNode)
            {
                TS_FAIL("getPosFromFapiName failed, input: %s "
                        "expctd result: %s n%dp%dc%d "
                        "actual result: %s n%dp%dc%d",
                        test.string,
                        test.expctdResult ? "true" : "false", test.expctdNode, test.expctdPos, test.expctdUnitPos,
                        result ? "true" : "false", o_node, o_pos, o_unitPos);
            }
        }

        TS_INFO(EXIT_MRK"testGetPosInfo");
    }

private:
    /**
    * @brief Loads attribute override text into memory
    *
    * This function is responsible for simulating a text based attribute override.
    * First allocates and creates a simulated ATTR_TMP PNOR section, then loads
    * ascii from attrText into this section and calls getAttrOverrides, passing
    * in this memory section for consumption.
    *
    */
    void loadAttrText(void)
    {
        TS_INFO(ENTER_MRK"loadAttrText");

        if (!SECUREBOOT::allowAttrOverrides())
        {
            TS_FAIL("loadAttrText: attribute overrides are not allowed");
            return;
        }

        Target::theTargOverrideAttrTank().clearAllAttributes();

        errlHndl_t err = nullptr;
        void * l_vaddr = nullptr;

        // Allocate a contiguous block of memory
        l_vaddr = malloc(VMM_DEBUG_COMM_SIZE);

        // Create simulated ATTR_TMP PNOR section to feed to getAttrOverrides
        PNOR::SectionInfo_t l_sectionInfo;
        l_sectionInfo.id = PNOR::ATTR_TMP;
        l_sectionInfo.name = "ATTR_TMP";
        l_sectionInfo.vaddr = reinterpret_cast<uint64_t>(l_vaddr);
        l_sectionInfo.flashAddr = 0xFFFFFFFF; //Not used
        l_sectionInfo.size = VMM_DEBUG_COMM_SIZE;
        l_sectionInfo.eccProtected = false;
        l_sectionInfo.sha512Version = false;
        l_sectionInfo.sha512perEC = false;
        l_sectionInfo.readOnly = true;
        l_sectionInfo.reprovision = false;
        l_sectionInfo.secure = false;

        // homogenize memory
        memset (l_vaddr, 0xFF, VMM_DEBUG_COMM_SIZE);
        // load ascii text into ATTR_TMP
        memcpy (l_vaddr, attrText, strlen(attrText));

        // call getAttrOverrides to take PNOR section and convert to binary in attrTank
        TS_INFO("loadAttrText: Getting attribute overrides from ascii");
        err = TARGETING::getAttrOverrides(l_sectionInfo);
        if (err)
        {
            TS_FAIL("loadAttrText: Failed getAttrOverrides from dynamic set");
            errlCommit(err, TARG_COMP_ID);
            return;
        }

        // Cleanup
        free (reinterpret_cast<char *>(l_vaddr));
        l_vaddr = nullptr;

        TS_INFO(EXIT_MRK"loadAttrText");
    }
};

#endif
