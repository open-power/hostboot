/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/test/htmgtcfgtest.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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


class htmgtMemTest : public CxxTest::TestSuite
{

private:
    bool iv_mcConfigLoaded;
    bool iv_htmgtLoaded;

public:

    htmgtMemTest()
    {
        if (!VFS::module_is_loaded("libmc_config.so"))
        {
            errlHndl_t err = VFS::module_load("libmc_config.so");
            if (err)
            {
                TS_FAIL("Could not load mc_config module");
                errlCommit(err, HTMGT_COMP_ID);
            }

            iv_mcConfigLoaded = true;
        }
        else
        {
            iv_mcConfigLoaded = false;
        }

        if (!VFS::module_is_loaded("libhtmgt.so"))
        {
            errlHndl_t err = VFS::module_load("libhtmgt.so");
            if (err)
            {
                TS_FAIL("Could not load libhtmgt module");
                errlCommit(err, HTMGT_COMP_ID);
            }

            iv_htmgtLoaded = true;
        }
        else
        {
            iv_htmgtLoaded = false;
        }
    }


    ~htmgtMemTest()
    {
        if (iv_mcConfigLoaded)
        {
            errlHndl_t err = VFS::module_unload("libmc_config.so");
            if (err)
            {
                TS_FAIL("Could not unload mc_config module");
                errlCommit(err, HTMGT_COMP_ID);
            }
        }

        if (iv_htmgtLoaded)
        {
            errlHndl_t err = VFS::module_unload("libhtmgt.so");
            if (err)
            {
                TS_FAIL("Could not unload libhtmgt module");
                errlCommit(err, HTMGT_COMP_ID);
            }
        }

    }


    void testThrottles()
    {
        TS_TRACE(ENTER_MRK"HTMGT: testThrottles");

        calcMemThrottles();


        TargetHandleList mbas;
        TargetHandleList::iterator mba;

        getAllChiplets(mbas, TYPE_MBA, true);

        //Make sure all of the numerators are set
        for (mba=mbas.begin();mba!=mbas.end();++mba)
        {
            if (0 == (*mba)->getAttr<ATTR_OT_MIN_N_PER_MBA>())
            {
                TS_FAIL("MBA 0x%X has value of zero for OT_MIN_N_PER_MBA",
                        (*mba)->getAttr<ATTR_HUID>());
            }

            if (0 == (*mba)->getAttr<ATTR_N_PLUS_ONE_N_PER_MBA>())
            {
                TS_FAIL("MBA 0x%X has value of zero for N_PLUS_ONE_N_PER_MBA",
                        (*mba)->getAttr<ATTR_HUID>());
            }

            if (0 == (*mba)->getAttr<ATTR_N_PLUS_ONE_N_PER_CHIP>())
            {
                TS_FAIL("MBA 0x%X has value of zero for N_PLUS_ONE_N_PER_CHIP",
                        (*mba)->getAttr<ATTR_HUID>());
            }

            if (0 == (*mba)->getAttr<ATTR_OVERSUB_N_PER_MBA>())
            {
                TS_FAIL("MBA 0x%X has value of zero for OVERSUB_N_PER_MBA",
                        (*mba)->getAttr<ATTR_HUID>());
            }

            if (0 == (*mba)->getAttr<ATTR_OVERSUB_N_PER_CHIP>())
            {
                TS_FAIL("MBA 0x%X has value of zero for OVERSUB_N_PER_CHIP",
                        (*mba)->getAttr<ATTR_HUID>());
            }
        }

    }


    void testThrottleConfigData()
    {
        TargetHandleList occs;
        TargetHandleList::iterator occ;
        uint8_t numSets = 0;
        uint8_t data[4*KILOBYTE];
        uint64_t size = 0;
        uint64_t expectedSize = 0;
        const size_t THROTTLE_DATA_SET_SIZE = 12;

        TS_TRACE(ENTER_MRK"HTMGT: testThrottleConfigData");

        getAllChiplets(occs, TYPE_OCC, true);

        for (occ=occs.begin();occ!=occs.end();++occ)
        {
            memset(data, 0, 4*KILOBYTE);

            getMemThrottleMessageData(*occ, data, size);

            if (data[0] != OCC_CFGDATA_MEM_THROTTLE)
            {
                TS_FAIL("Wrong format 0x%X for throttle config data command",
                        data[0]);
            }

            //Note: Yes, the version number is hardcoded, but if the version
            //changes then these testcases would have to change anyway.
            if (data[1] != 0x10)
            {
                TS_FAIL("Wrong version 0x%X for throttle config data command",
                        data[1]);
            }

            numSets = data[2];

            TS_TRACE("HTMGT: testThrottleConfigData: OCC 0x%X returned message"
                     " size %d num sets %d",
                      (*occ)->getAttr<ATTR_HUID>(), size, numSets);

            //3B header + 12B / set
            expectedSize = 3 + (THROTTLE_DATA_SET_SIZE * numSets);
            if (size != expectedSize)
            {
                TS_FAIL("Throttle data size %d did not match expected size %d"
                        " for OCC 0x%X",
                        size, expectedSize, (*occ)->getAttr<ATTR_HUID>());
            }
        }

    }


    void testMemConfigData()
    {
        TargetHandleList occs;
        TargetHandleList::iterator occ;
        uint8_t numSets = 0;
        uint8_t data[4*KILOBYTE];
        uint64_t size = 0;
        uint64_t expectedSize = 0;
        const size_t MEMCONFIG_DATA_SET_SIZE = 12;

        TS_TRACE(ENTER_MRK"HTMGT: testMemConfigData");

        getAllChiplets(occs, TYPE_OCC, true);

        for (occ=occs.begin();occ!=occs.end();++occ)
        {
            memset(data, 0, 4*KILOBYTE);

            getMemConfigMessageData(*occ, true, data, size);

            if (data[0] != OCC_CFGDATA_MEM_CONFIG)
            {
                TS_FAIL("Wrong format 0x%X for mem config data command",
                        data[0]);
            }

            if (data[1] != 0x10)
            {
                TS_FAIL("Wrong version 0x%X for mem config data command",
                        data[1]);
            }

            numSets = data[2];

            TS_TRACE("HTMGT: testMemConfigData: OCC 0x%X returned message "
                     "size %d num sets %d",
                     (*occ)->getAttr<ATTR_HUID>(), size, numSets);

            expectedSize = 3 + (MEMCONFIG_DATA_SET_SIZE * numSets);
            if (size != expectedSize)
            {
                TS_FAIL("MemConfig data size %d did notmatch expected "
                        "size %d for OCC 0x%X",
                        size, expectedSize, (*occ)->getAttr<ATTR_HUID>());
            }
        }

    }

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

        if (data[1] != 0x10)
        {
            TS_FAIL("Wrong version 0x%X for power cap config data command",
                    data[1]);
        }

        if (size != 8)
        {
            TS_FAIL("Wrong size %d for power cap config data command",
                    size);
        }

    }


    void testSystemConfigData()
    {
        TargetHandleList occs;
        TargetHandleList::iterator occ;
        uint8_t data[4*KILOBYTE];
        uint64_t size = 0;

        TS_TRACE(ENTER_MRK"HTMGT: testSystemConfigData");

        getAllChiplets(occs, TYPE_OCC, true);

        for (occ=occs.begin();occ!=occs.end();++occ)
        {
            memset(data, 0, 4*KILOBYTE);

            getSystemConfigMessageData(*occ, data, size);

            if (data[0] != OCC_CFGDATA_SYS_CONFIG)
            {
                TS_FAIL("Wrong format 0x%X for system config data command",
                        data[0]);
            }

            if (data[1] != 0x10)
            {
                TS_FAIL("Wrong version 0x%X for system config data command",
                        data[1]);
            }


            if (data[2] != OCC_CFGDATA_OPENPOWER_SYSTEMTYPE)
            {
                TS_FAIL("wrong system type 0x%X for system config data command",
                        data[2]);
            }

            if (size != 57)
            {
                TS_FAIL("wrong size %d for system config data command",
                        size);
            }
        }

    }


    void testThermalControlConfigData()
    {
        uint8_t data[4*KILOBYTE];
        uint64_t size = 0;

        TS_TRACE(ENTER_MRK"HTMGT: testThermalControlConfigData");

        getThermalControlMessageData(data, size);


        if (data[0] != OCC_CFGDATA_TCT_CONFIG)
        {
            TS_FAIL("Wrong format 0x%X for thermal config data command",
                    data[0]);
        }

        if (data[1] != 0x10)
        {
            TS_FAIL("Wrong version 0x%X for thermal config data command",
                    data[1]);
        }

        if (size != 15)
        {
            TS_FAIL("wrong size %d for thermal control config data command",
                    size);
        }

    }


    void testFreqPointConfigData()
    {
        uint8_t data[4*KILOBYTE];
        uint64_t size = 0;

        TS_TRACE(ENTER_MRK"HTMGT: testThermalControlConfigData");
        memset(data, 0, 4*KILOBYTE);

        getFrequencyPointMessageData(data, size);

        if (data[0] != OCC_CFGDATA_FREQ_POINT)
        {
            TS_FAIL("Wrong format 0x%X for frequency point data command",
                    data[0]);
        }

        if (data[1] != 0x10)
        {
            TS_FAIL("Wrong version 0x%X for frequency point data command",
                    data[1]);
        }

        if (size != 8)
        {
            TS_FAIL("wrong size %d for frequency point config data command",
                    size);
        }

    }

    void testReadPstateTable( void )
    {
        TS_TRACE(ENTER_MRK"HTMGT::testReadPstateTable");

        TargetHandleList occs;
        TargetHandleList::iterator occ;
        size_t size = sizeof(ATTR_PSTATE_TABLE_type) + 4;
        uint8_t data[size];

        getAllChiplets(occs, TYPE_OCC, true);

        for(occ=occs.begin(); occ !=occs.end(); ++occ)
        {
            size = sizeof(ATTR_PSTATE_TABLE_type) + 4;
            memset(data, 0, size);
            getPstateTableMessageData(*occ, data, size);

            if(size != sizeof(ATTR_PSTATE_TABLE_type) + 4)
            {
                TS_FAIL("Wrong pstate table size. %d",
                        size);
            }
        }
    }

    void testApssConfigData()
    {
        uint64_t size = 256;
        uint8_t data[size];

        TMGT_INF(ENTER_MRK"HTMGT::testApccConfigData");
        memset(data,0,size);
        size = 0;

        getApssMessageData(data, size);

        TMGT_INF("APSS message size = %d bytes", size);

        if(size != 216 || data[0] != HTMGT::OCC_CFGDATA_APSS_CONFIG)
        {
            TS_FAIL("Invalid APSS config size (%d) or format.",size);
        }
    }
};


#endif
