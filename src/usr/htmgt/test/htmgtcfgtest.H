/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/test/htmgtcfgtest.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2021                        */
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
#ifndef __HTMGTMEMTEST_H
#define __HTMGTMEMTEST_H

#include <vfs/vfs.H>
#include <cxxtest/TestSuite.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/attributes.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/util.H>
#include "../htmgt_memthrottles.H"
#include "../htmgt_cfgdata.H"
#include "../htmgt_utility.H"

using namespace TARGETING;
using namespace HTMGT;


class htmgtCfgTest : public CxxTest::TestSuite
{

private:
    bool iv_mcConfigLoaded;
    bool iv_htmgtLoaded;

public:

    // TODO: RTC 269380 - Add Mem Config Support

    void testOCCRoleConfigData()
    {
        uint8_t data[4*KILOBYTE];
        uint64_t size = 0;

        TS_TRACE(ENTER_MRK"HTMGT: testOCCRoleConfigData");

        getOCCRoleMessageData(true, true, data, size);

        if (data[0] != OCC_CFGDATA_OCC_ROLE)
        {
            TS_FAIL("Wrong format 0x%X for occ role config data command",
                    data[0]);
        }

        if (data[1] != (OCC_ROLE_MASTER | OCC_ROLE_FIR_MASTER))
        {
            TS_FAIL("Wrong OCC role data 0x%X for occ"
                    " role config data command",
                    data[1]);
        }

        if (size != 2)
        {
            TS_FAIL("Wrong message length %d for occ role config data command",
                    size);
        }


        //Now do fir master = false
        getOCCRoleMessageData(true, false, data, size);

        if (data[1] != OCC_ROLE_MASTER)
        {
            TS_FAIL("Wrong OCC role data 0x%X for occ"
                    " role config data command",
                    data[1]);
        }

        //now master role = false
        getOCCRoleMessageData(false, true, data, size);

        if (data[1] != OCC_ROLE_FIR_MASTER)
        {
            TS_FAIL("Wrong OCC role data 0x%X for occ role config data command",
                    data[1]);
        }

        TS_TRACE(EXIT_MRK"HTMGT: testOCCRoleConfigData");
    }



    void testPowerCapConfigData()
    {
        uint8_t data[4*KILOBYTE];
        uint64_t size = 0;

        TS_TRACE(ENTER_MRK"HTMGT: testPowerCapConfigData");

        getPowerCapMessageData(data, size);

        if (data[0] != OCC_CFGDATA_PCAP_CONFIG)
        {
            TS_FAIL("Wrong format 0x%X for power cap config data command",
                    data[0]);
        }

        if (data[1] != 0x20)
        {
            TS_FAIL("Wrong version 0x%X for power cap config data command",
                    data[1]);
        }

        if (size != 10)
        {
            TS_FAIL("Wrong size %d for power cap config data command",
                    size);
        }

        TS_TRACE(EXIT_MRK"HTMGT: testPowerCapConfigData");
    }


    void testThermalControlConfigData()
    {
        uint8_t data[4*KILOBYTE];
        uint64_t size = 0;

        TS_TRACE(ENTER_MRK"HTMGT: testThermalControlConfigData");

        // Get all functional processors
        TARGETING::TargetHandleList pProcs;
        TARGETING::getChipResources(pProcs,
                                    TARGETING::TYPE_PROC,
                                    TARGETING::UTIL_FILTER_FUNCTIONAL);
        // just use the first functional proc target
        TARGETING::Target * procTarget = *pProcs.begin();

        getThermalControlMessageData(procTarget,data, size);


        if (data[0] != OCC_CFGDATA_TCT_CONFIG)
        {
            TS_FAIL("Wrong format 0x%X for thermal config data command",
                    data[0]);
        }

        if (data[1] != 0x30)
        {
            TS_FAIL("Wrong version 0x%X for thermal config data command",
                    data[1]);
        }

        if (size != 54)
        {
            TS_FAIL("wrong size %d for thermal control config data command",
                    size);
        }

        TS_TRACE(EXIT_MRK"HTMGT: testThermalControlConfigData");
    }


    void testApssConfigData()
    {
        uint64_t size = 256;
        uint8_t data[size];

        TMGT_INF(ENTER_MRK"HTMGT: testApssConfigData");
        memset(data,0,size);
        size = 0;

        getApssMessageData(data, size);

        TMGT_INF("APSS message size = %d bytes", size);

        if((size != 248) || (data[0] != HTMGT::OCC_CFGDATA_APSS_CONFIG))
        {
            TS_FAIL("Invalid APSS config size (%d) or format.",size);
        }

        TMGT_INF(EXIT_MRK"HTMGT: testApssConfigData");
    }
};


#endif
