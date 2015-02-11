/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmi/runtime/test/rt_ipmitest.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
#ifndef __RT_IPMITEST_H
#define __RT_IPMITEST_H

/**
 *  @file ipmitest.H
 *
 *  @brief Test case for IPMI messages
*/

#include <cxxtest/TestSuite.H>

#include "../../../trace/entry.H"

#include <ipmi/ipmiif.H>
#include <ipmi/ipmisensor.H>


class RT_IpmiTest: public CxxTest::TestSuite
{
public:


    /**
     * @brief call sendrecv directly
     */
    void testIpmi1(void)
    {
        do
        {
            IPMI::completion_code cc = IPMI::CC_UNKBAD;
            size_t len = 0;
            uint8_t* data = NULL;
            errlHndl_t err = IPMI::sendrecv(IPMI::get_capabilities(), cc, len, data);

            TS_WARN("testIpmi1: cc x%x, len %d", cc, len);

            if ( err != NULL )
            {
                TS_FAIL("testIpmi1: get_capabilities() failed");
                break;
            }
            if (cc != IPMI::CC_OK)
            {
                TS_FAIL("testIpmi1: get_capabilities() failed with cc 0x%x", cc);
                break;
            }
            if (len != 5)
            {
                TS_FAIL("testIpmi1: get_capabilities() returned len %d instead of 5",
                        len);
                break;
            }

            TS_WARN("testIpmi1: get_capabilities x%x, x%x x%x x%x x%x",
                    data[0], data[1], data[2], data[3], data[4]);

        }
        while(0);
    }

    /**
     * @brief  call IPMI::sensor function
     */
    void testIpmi2(void)
    {
        do
        {
            uint8_t l_sensorNumber = SENSOR::getFaultSensorNumber(
                    TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL);

            TS_WARN("testIpmi2: getFaultSensorNumber x%x",
                    l_sensorNumber);
        }
        while(0);
    }
};

#endif
