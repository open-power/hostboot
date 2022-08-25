/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/test/testTargPlatUtil.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
#ifndef __TEST_TARG_PLAT_UTIL_H
#define __TEST_TARG_PLAT_UTIL_H

/**
 *  @file targeting/test/testTargPlatUtil.H
 *
 *  @brief Unit test for common target utilities on platform
 */

//******************************************************************************
// Includes
//******************************************************************************

// CXX TEST
#include <cxxtest/TestSuite.H>

#include <targeting/targplatutil.H>

using namespace TARGETING;

//******************************************************************************
// class TargPlatUtilTest
//******************************************************************************
class TargPlatUtilTest: public CxxTest::TestSuite
{
public:

    /**
     * Test getSensorNumber() and getSensorTarget() functions for OCMB targets
     */
    void testGetSensorNumberOCMB();

    /**
     * Test getSensorNumber() and getSensorTarget() functions for DIMM targets
     */
    void testGetSensorNumberDIMM();

}; //  end class TargPlatUtilTest

void TargPlatUtilTest::testGetSensorNumberOCMB()
{
    TS_INFO(">>testGetSensorNumberOCMB");

    // OMCB test

    // Find a valid target of type OCMB_CHIP
    TargetHandleList l_ocmbTargetList;
    getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP, true);
    TS_INFO("testGetSensorNumberOCMB: l_ocmbTargetList.size=%d", l_ocmbTargetList.size());
    if (l_ocmbTargetList.empty())
    {
        TS_FAIL("<<testGetSensorNumberOCMB: No valid TYPE_OCMB_CHIP target found. "
                "Can not execute test cases.");
        return;
    }

    for (auto l_ocmb : l_ocmbTargetList)
    {
        bool tcFailure{false};
        uint32_t sensorNum = UTIL::getSensorNumber(l_ocmb, SENSOR_NAME_MEMBUF_STATE);
#ifdef CONFIG_PLDM
        const UTIL::occ_sensor_id_t sensor { .encoded = sensorNum };
        if (sensor.sensor_type != UTIL::occ_sensor_id_t::SENSOR_TYPE_DIMM)
        {
            TS_FAIL("Invalid sensor type 0x%02X found for OCMB 0x%08X (expected 0x%02X)",
                sensor.sensor_type, get_huid(l_ocmb), UTIL::occ_sensor_id_t::SENSOR_TYPE_DIMM);
            tcFailure = true;
        }
        if (sensor.target_type != UTIL::occ_sensor_id_t::target_type_t::TARGET_TYPE_OCMB)
        {
            TS_FAIL("Invalid reserved type 0x%02X found for OCMB 0x%08X (expected 0x%02X)",
                sensor.target_type, get_huid(l_ocmb), UTIL::occ_sensor_id_t::target_type_t::TARGET_TYPE_OCMB);
            tcFailure = true;
        }
#endif
        if (!tcFailure)
        {
            // try to convert back to target from sensor number

            // find processor associated with ocmb
            TargetHandleList affinityParentTargets;
            getParentAffinityTargets (
               affinityParentTargets,
               l_ocmb,
               TARGETING::CLASS_CHIP,
               TARGETING::TYPE_PROC,
               false);
            if (affinityParentTargets.empty())
            {
                TS_FAIL("Unable to find processor parent of OCMB 0x%08X", get_huid(l_ocmb));
                continue;
            }
            // now find OCC associated with processor
            TargetHandleList pOccs;
            getChildChiplets(pOccs, affinityParentTargets[0], TARGETING::TYPE_OCC);
            if (pOccs.empty())
            {
                TS_FAIL("Unable to find OCC under processor 0x%08X", get_huid(affinityParentTargets[0]));
                continue;
            }

            TargetHandle_t targetSensor = UTIL::getSensorTarget(sensorNum, pOccs[0]);

            if (targetSensor != l_ocmb)
            {
                TS_FAIL("OCMB target 0x%08X does NOT match sensor number 0x%08X target 0x%08X",
                    get_huid(l_ocmb), sensorNum, get_huid(targetSensor));
            }
            else
            {
                TS_INFO("Found OCMB target 0x%08X matching sensor number 0x%08X", get_huid(l_ocmb), sensorNum);
            }
        }
    }
    TS_INFO("<<testGetSensorNumberOCMB");
}


void TargPlatUtilTest::testGetSensorNumberDIMM()
{
    TS_INFO(">>testGetSensorNumberDIMM");

    TargetHandleList l_dimms;
    getAllLogicalCards(l_dimms, TYPE_DIMM, true );
    TS_TRACE( "testGetSensorNumberDIMM: %d functional dimms",
              l_dimms.size() );
    if (l_dimms.empty())
    {
        TS_FAIL("<<testGetSensorNumberDIMM: No valid TYPE_DIMM target found. "
                "Can not execute test cases.");
        return;
    }
    for (auto l_dimm : l_dimms)
    {
        bool tcFailure{false};
        uint32_t sensorNum = UTIL::getSensorNumber(l_dimm, SENSOR_NAME_MEMBUF_STATE);
#ifdef CONFIG_PLDM
        const UTIL::occ_sensor_id_t sensor { .encoded = sensorNum };
        if (sensor.sensor_type != UTIL::occ_sensor_id_t::SENSOR_TYPE_DIMM)
        {
            TS_FAIL("Invalid sensor type 0x%02X found for DIMM 0x%08X (expected 0x%02X)",
                sensor.sensor_type, get_huid(l_dimm), UTIL::occ_sensor_id_t::SENSOR_TYPE_DIMM);
            tcFailure = true;
        }
        if (sensor.target_type != UTIL::occ_sensor_id_t::target_type_t::TARGET_TYPE_DIMM)
        {
            TS_FAIL("Invalid reserved type 0x%02X found for DIMM 0x%08X (expected 0x%02X)",
                sensor.target_type, get_huid(l_dimm), UTIL::occ_sensor_id_t::target_type_t::TARGET_TYPE_DIMM);
            tcFailure = true;
        }
#endif
        if (!tcFailure)
        {
            // try to convert back to target from sensor number

            // find processor associated with dimm
            TargetHandleList affinityParentTargets;
            getParentAffinityTargets (
               affinityParentTargets,
               l_dimm,
               TARGETING::CLASS_CHIP,
               TARGETING::TYPE_PROC,
               false);
            if (affinityParentTargets.empty())
            {
                TS_FAIL("Unable to find processor parent of DIMM 0x%08X", get_huid(l_dimm));
                continue;
            }
            // now find OCC associated with processor that has dimm
            TargetHandleList pOccs;
            getChildChiplets(pOccs, affinityParentTargets[0], TARGETING::TYPE_OCC);
            if (pOccs.empty())
            {
                TS_FAIL("Unable to find OCC under processor 0x%08X", get_huid(affinityParentTargets[0]));
                continue;
            }

            TargetHandle_t targetSensor = UTIL::getSensorTarget(sensorNum, pOccs[0]);

            if (targetSensor != l_dimm)
            {
                TS_FAIL("DIMM target 0x%08X does NOT match sensor number 0x%08X target 0x%08X",
                    get_huid(l_dimm), sensorNum, get_huid(targetSensor));
            }
            else
            {
                TS_INFO("Found DIMM target 0x%08X matching sensor number 0x%08X", get_huid(l_dimm), sensorNum);
            }
        }
    }

    TS_INFO("<<testGetSensorNumberDIMM");
}

#endif  // end __TEST_TARG_PLAT_UTIL_H
