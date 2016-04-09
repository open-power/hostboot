/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/occ/test/occAccessTest.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2016                        */
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

#ifndef __OCCACCESSTEST_H
#define __OCCACCESSTEST_H

#include    <stdint.h>

#include    <occ/occAccess.H>
#include    <errl/errlentry.H>
#include    <vfs/vfs.H>
#include    <isteps/hwpf_reasoncodes.H>

//  fapi support
#include    <fapi.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/targetservice.H>
#include    <targeting/common/util.H>

using namespace TARGETING;

class occAccessTest : public CxxTest::TestSuite
{
public:

void testAccessOCBIndirectChannel()
{
    TS_TRACE ("testAccessOCBIndirectChannel: enter");

    errlHndl_t l_errl = NULL;
    bool occ_loaded = false;
    bool l_error = false;

    do
    {
        //*********************************************************************
        // load occ if needed
        //*********************************************************************

        if (  !VFS::module_is_loaded( "libocc.so" ) )
        {
            TS_TRACE("testAccessOCBIndirectChannel: load occ module");
            l_errl = VFS::module_load( "libocc.so" );

            if ( l_errl )
            {
                //  load module returned with errl set
                TS_FAIL("testAccessOCBIndirectChannel:"
                        " could not load occ module");
                l_error = true;
                break;
            }
            occ_loaded = true;
        }

        //*********************************************************************
        // Find a PROC target and its OCC target
        //*********************************************************************

        //Get a Proc target
        TARGETING::TargetHandleList l_procTargetList;
        getAllChips(l_procTargetList,
                       TYPE_PROC,
                       true);

        if (0==l_procTargetList.size()) //unexpected error
        {
            TS_FAIL("testAccessOCBIndirectChannel: No Proc targets");
            l_error = true;
            break;
        }
        const TARGETING::Target* l_procTarget = l_procTargetList[0];

        //Find an OCC target
        TARGETING::TargetHandleList l_occTargetList;
        getChildChiplets( l_occTargetList,
                       l_procTarget,
                       TYPE_OCC,
                       true);
        // if there are no OCCs in this configuration, use the PROC target
        if (0==l_occTargetList.size())
        {
            TS_TRACE("testAccessOCBIndirectChannel: No OCC targets");
            l_occTargetList.push_back(l_procTargetList[0]);
        }
        const TARGETING::Target* l_occTarget = l_occTargetList[0];

        //*********************************************************************
        // Read and Write the OCC linear buffer
        // 1. Read current value
        // 2. Write test data
        // 3. Read back and verify
        // 4. Restore current value
        //*********************************************************************
        ecmdDataBufferBase l_currentData(64);
        ecmdDataBufferBase l_testData(64);
        ecmdDataBufferBase l_readBackData(64);
        uint32_t l_addr = 0xFFFF6000;//sample value from TMGT.
        const uint64_t l_testValue = 0x0123456789ABCDEF;


        // read current data (use proc target)
        TS_TRACE("testAccessOCBIndirectChannel:"
                  "  target=%.8x type=%d read current",
                  get_huid(l_procTarget),
                  (l_procTarget)->getAttr<TARGETING::ATTR_TYPE>());

        l_errl = HBOCC::readSRAM(l_procTarget,l_addr,l_currentData);
        if (l_errl)
        {
            TS_FAIL("testAccessOCBIndirectChannel: Read OCC SRAM failed");
            l_error = true;
            break;
        }
        TS_TRACE("testAccessOCBIndirectChannel: current data=%lx",
              l_currentData.getDoubleWord(0));

        // write test data (use occ target)
        TS_TRACE("testAccessOCBIndirectChannel:"
                   " target=%.8x type=%d write test",
                   get_huid(l_occTarget),
                   (l_occTarget)->getAttr<TARGETING::ATTR_TYPE>());

        l_testData.setDoubleWord(0,l_testValue);
        l_errl = HBOCC::writeSRAM(l_occTarget,l_addr,l_testData);
        if (l_errl)
        {
            TS_FAIL("testAccessOCBIndirectChannel: write test data failed");
            l_error = true;
            break;
        }
        TS_TRACE("testAccessOCBIndirectChannel: test data=%lx",
              l_testData.getDoubleWord(0));

        // read test data back (use proc target)
        TS_TRACE("testAccessOCBIndirectChannel:"
                  " target=%.8x type=%d read test data",
                    get_huid(l_procTarget),
                    (l_procTarget)->getAttr<TARGETING::ATTR_TYPE>());

        l_errl = HBOCC::readSRAM(l_procTarget,l_addr,l_readBackData);
        if (l_errl)
        {
            TS_FAIL("testAccessOCBIndirectChannel: read test data failed");
            l_error = true;
            break;
        }
        TS_TRACE("testAccessOCBIndirectChannel: read back data=%lx",
              l_readBackData.getDoubleWord(0));

        if(l_testValue != l_readBackData.getDoubleWord(0))
        {
            TS_FAIL("testAccessOCBIndirectChannel: read back compare failed");
            l_error = true;
            break;
        }

        // write original data back (use proc target)
        TS_TRACE("testAccessOCBIndirectChannel:"
                  " target=%.8x type=%d write orginial back",
                   get_huid(l_procTarget),
                   (l_procTarget)->getAttr<TARGETING::ATTR_TYPE>());

        l_errl = HBOCC::writeSRAM(l_procTarget,l_addr,l_currentData);
        if (l_errl)
        {
            TS_FAIL("testAccessOCBIndirectChannel: restore data failed");
            l_error = true;
            break;
        }

        //*********************************************************************
        // Test write circular
        //*********************************************************************
        ecmdDataBufferBase l_data(64); // value 0

        // write circular (use proc target)
        TS_TRACE("testAccessOCBIndirectChannel:"
                  "  target=%.8x type=%d write circular",
                    get_huid(l_procTarget),
                    (l_procTarget)->getAttr<TARGETING::ATTR_TYPE>());

        l_errl = HBOCC::writeCircularBuffer(l_procTarget,l_data);
        if (l_errl)
        {
            TS_FAIL("testAccessOCBIndirectChannel: write circular failed");
            l_error = true;
            break;
        }
        TS_TRACE("testAccessOCBIndirectChannel: write circular data=%lx",
              l_data.getDoubleWord(0));

        //*********************************************************************
        // Error tests
        //*********************************************************************

        // null target
        const TARGETING::Target* l_nullTarget = NULL;
        l_errl = HBOCC::writeCircularBuffer(l_nullTarget,l_data);
        if (l_errl) {
            TS_TRACE("testAccessOCBIndirectChannel: null test rc=%x",
               static_cast<uint32_t>(l_errl->reasonCode()));
        }
        if (!l_errl || (RC_TARGET_UNSUPPORTED != l_errl->reasonCode()))
        {
            TS_FAIL("testAccessOCBIndirectChannel: null target test failed");
            l_error = true;
            break;
        }
        delete l_errl;
        l_errl = NULL;

        // wrong target type
        TARGETING::TargetHandleList l_wrongTargetList;
        getAllChips(l_wrongTargetList,
                       TYPE_MEMBUF,
                       true);

        if (0==l_wrongTargetList.size()) //unexpected error
        {
            TS_FAIL("testAccessOCBIndirectChannel: No wrong targets");
            l_error = true;
            break;
        }
        const TARGETING::Target* l_wrongTarget = l_wrongTargetList[0];

        l_errl = HBOCC::writeCircularBuffer(l_wrongTarget,l_data);
        if (l_errl) {
            TS_TRACE("testAccessOCBIndirectChannel: wrong target rc=%x",
               static_cast<uint32_t>(l_errl->reasonCode()));
        }
        if (!l_errl || (RC_TARGET_UNSUPPORTED != l_errl->reasonCode()))
        {
            TS_FAIL("testAccessOCBIndirectChannel: wrong target test failed");
            l_error = true;
            break;
        }
        delete l_errl;
        l_errl = NULL;

        // wrong data length
        ecmdDataBufferBase l_wrongData(65);

        l_errl = HBOCC::readSRAM(l_procTarget,l_addr,l_wrongData);
        if (l_errl) {
            TS_TRACE("testAccessOCBIndirectChannel: wrong data rc=%x",
               static_cast<uint32_t>(l_errl->reasonCode()));
        }
        if (!l_errl || (RC_INVALID_DATA_BUFFER_LENGTH != l_errl->reasonCode()))
        {
            TS_FAIL("testAccessOCBIndirectChannel: wrong data length failed");
            l_error = true;
            break;
        }
        delete l_errl;
        l_errl = NULL;

    }
    while (0);

    //*********************************************************************
    // unload occ if needed
    //*********************************************************************
    if (occ_loaded)
    {
        errlHndl_t  l_tmpErrl  =   NULL;
        l_tmpErrl = VFS::module_unload( "libocc.so" );
        if ( l_tmpErrl )
        {
            TS_WARN("testAccessOCBIndirectChannel:"
                    " Error unloading libocc module" );
            delete l_tmpErrl;
            l_tmpErrl = NULL;
        }
        else
        {
            TS_TRACE("testAccessOCBIndirectChannel: unload occ module");
        }
    }


    if (l_errl)  //Test case failed, commit error
    {
        errlCommit(l_errl,HWPF_COMP_ID);
        TS_TRACE ("testAccessOCBIndirectChannel: exit FAILED log committed");
    }
    else if (l_error) //Failed without an error log created
    {
        TS_TRACE ("testAccessOCBIndirectChannel: exit FAILED");
    }
    else
    {
        TS_TRACE ("testAccessOCBIndirectChannel: exit PASSED");
    }

}

}; // end class

#endif
