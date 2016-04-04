/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/getVpdTest.C $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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

/**
 * @file getVpdTest.C
 * @brief getVpd for MCA memory test cases
 */

#include <stdint.h>
#include <cxxtest/TestSuite.H>
#include <target.H>
#include <target_types.H>
#include <vpd_access_defs.H>
#include <return_code_defs.H>
#include <return_code.H>
#include <vpd_access.H>
#include <getVpdTest.H>
#include <p9_get_mem_vpd_keyword.H>
#include <attribute_service.H>

//The following commented out section can be restored for unit testing
//#undef FAPI_DBG
//#define FAPI_DBG(args...) FAPI_INF(args)

using TARGETING::ATTR_VPD_OVERRIDE_MT;
using TARGETING::ATTR_VPD_OVERRIDE_MT_ENABLE;
using TARGETING::ATTR_VPD_OVERRIDE_MR;
using TARGETING::ATTR_VPD_OVERRIDE_MR_ENABLE;

const size_t VPD_KEYWORD_SIZE = 255;

using namespace fapi2;

// Find MCS of requested MEMVPD_POS
bool getTarget (TARGETING::ATTR_MEMVPD_POS_type       i_memVpdPos,
                TARGETING::Target *                   &o_target,
                fapi2::Target<fapi2::TARGET_TYPE_MCS> &o_fapiTarget)
{
    bool l_rc = false;


    TARGETING::TargetHandleList l_mcsTargetList;
    getAllChiplets(l_mcsTargetList, TARGETING::TYPE_MCS, false);
    FAPI_DBG("testGetVPD mcs count = %d", l_mcsTargetList.size());

    for (const auto l_mcsTarget: l_mcsTargetList)
    {
        TARGETING::ATTR_MEMVPD_POS_type l_memVpdPos =
                     l_mcsTarget->getAttr<TARGETING::ATTR_MEMVPD_POS>();
        if (i_memVpdPos == l_memVpdPos)
        {
            o_target = l_mcsTarget;
            fapi2::Target<fapi2::TARGET_TYPE_MCS>
                  l_fapiTarget(o_target);
            o_fapiTarget = l_fapiTarget;
            l_rc = true;
            break; //found MCS
        }
    }

   return l_rc;
}

//Common code for calling getVPD
ReturnCode testGetVPD(
        fapi2::Target<fapi2::TARGET_TYPE_MCS>  i_fapiTarget,
        fapi2::VPDInfo<fapi2::TARGET_TYPE_MCS> i_VPDInfo,
        const fapi2::MemVpdData                i_vpdType,
        const char                           * i_check, //NULL for no check
        int                                  & numTests,
        int                                  & numFails)
{
    numTests = 0;
    numFails = 0;
    ReturnCode l_rc;

    FAPI_DBG("testGetVPD common enter");

    do
    {
        // call with null blob pointer to get blob size
        uint8_t* blob = nullptr; //first call
        numTests++;
        l_rc = getVPD(i_fapiTarget, i_VPDInfo, blob );
        if (l_rc)
        {
            TS_FAIL  ("testGetVPD getVPD failed to get blob size");
            numFails++;
            break;
        }

        numTests++;
        if ( i_VPDInfo.iv_vpd_type != i_vpdType )
        {
            TS_FAIL  ("testGetVPD invalid initial type"
                     "value = %d expected = %d",
                     i_VPDInfo.iv_vpd_type,i_vpdType);
            numFails++;
        }
        numTests++;
        if ( blob != nullptr )
        {
            TS_FAIL  ("testGetVPD blob pointer not NULL"
                     "value = %p expected = %d",
                     blob,0);
            numFails++;
        }
        numTests++;
        if ( i_VPDInfo.iv_size != VPD_KEYWORD_SIZE )
        {
            TS_FAIL  ("testGetVPD invalid size"
                     "value = %d expected = %d",
                     i_VPDInfo.iv_size,VPD_KEYWORD_SIZE);
            numFails++;
        }
        if (numFails) break;

        // call to get blob
        blob = new uint8_t[i_VPDInfo.iv_size];
        numTests++;
        l_rc = getVPD(i_fapiTarget, i_VPDInfo, blob);
        if (l_rc)
        {
            TS_FAIL  ("testGetVPD getVPD failed to return blob");
            numFails++;
            break;
        }

        numTests++;
        if ( blob == nullptr )
        {
            TS_FAIL  ("testGetVPD blob pointer NULL value = %p",
                     blob);
            numFails++;
            break; //don't use NULL pointer
        }

        // compare to expected test data
        numTests++;
        if ( i_check &&
             (blob[0] != i_check[0]) &&
             (blob[1] != i_check[1]) )
        {
            TS_FAIL  ("testGetVPD:: invalid blob value"
                     "value = %x %x expected = %x %x",
                     blob[0],blob[1],i_check[0],i_check[1]);
            numFails++;
        }
        delete blob;
        blob = nullptr;

    }
    while(0);

    FAPI_DBG("testGetVPD common exit");

    return l_rc;
}

void testDecode_MR(void)
{
    int numTests = 0;
    int numFails = 0;
    ReturnCode l_rc;

    FAPI_DBG("testDecode MR start");

    do
    {
        // get a MCS fapi2 target for MEMVPD_POS 0
        TARGETING::ATTR_MEMVPD_POS_type l_memVpdPos = 0;

        fapi2::Target<fapi2::TARGET_TYPE_MCS> l_fapiTarget;
        TARGETING::Target * l_target;
        if(!getTarget(l_memVpdPos,l_target,l_fapiTarget))
        {
            TS_FAIL  ("testDecode_MR:: could not find MCS MEMVPD_POS=%d",
                     l_memVpdPos);
            numFails++;
            break; //Target not found
        }

        // set up VPDInfo
        fapi2::VPDInfo<fapi2::TARGET_TYPE_MCS> l_info(fapi2::MR);
        l_info.iv_freq_mhz = 1866; // index = 0
        l_info.iv_rank_count_dimm_0 = 1;
        l_info.iv_rank_count_dimm_1 = 4;
        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

        // set up the mapping data
        uint8_t l_pMapping[VPD_KEYWORD_SIZE] = {
                // Header: version=1, num entries=5, reserved
                1,5,0,
               // miss: mcs match, pair match, freq miss
               0xff,0xff,0xff,0xff,0x7f,'0',
               // miss: mcs match, pair missing, freq match
               0xff,0xff,0xfe,0xff,0xff,'1',
               // miss: mcs miss, pair match, freq match
               0x7f,0xff,0xff,0xff,0xff,'2',
               // match:
               0x80,0x00,0x01,0x00,0x80,'3', // <-- should be this one
               // match everything
               0xff,0xff,0xff,0xff,0xff,'4',
               // zero out rest
               0};

        // decode keyword
        keywordName_t l_keywordName = {0};
        numTests++;

        FAPI_EXEC_HWP(l_rc,
                  p9_get_mem_vpd_keyword,
                  l_fapiTarget,
                  l_info,
                  l_pMapping,
                  VPD_KEYWORD_SIZE,
                  l_keywordName);
        if(l_rc)
        {
            TS_FAIL  ("testDecode_MR:: p9_get_mem_vpd_keyword failed");
            numFails++;
            break; // decode failed
        }

        // compare to expected test data
        numTests++;
        if ( (l_keywordName[0] != 'J' ) &&
             (l_keywordName[1] != '3' ) )
        {
            TS_FAIL  ("testDecode_MR:: unexpected keyword name returned"
                     "value = %x %x expected = %x %x",
                     l_keywordName[0],l_keywordName[1],'J','3');
            numFails++;
        }

    }
    while(0);

    FAPI_INF("testDecode MR Test Complete, %d/%d fails",
             numFails, numTests);
}

void testDecode_MT(void)
{
    int numTests = 0;
    int numFails = 0;
    ReturnCode l_rc;

    FAPI_DBG("testDecode MT start");

    do
    {
        // get a MCS fapi2 target for MEMVPD_POS 7
        TARGETING::ATTR_MEMVPD_POS_type l_memVpdPos = 7;

        fapi2::Target<fapi2::TARGET_TYPE_MCS> l_fapiTarget;
        TARGETING::Target * l_target;
        if(!getTarget(l_memVpdPos,l_target,l_fapiTarget))
        {
            TS_FAIL  ("testDecode_MT:: could not find MCS MEMVPD_POS=%d",
                     l_memVpdPos);
            numFails++;
            break; //Target not found
        }

        // set up VPDInfo
        fapi2::VPDInfo<fapi2::TARGET_TYPE_MCS> l_info(fapi2::MT);
        l_info.iv_freq_mhz = 2667; //index 3
        l_info.iv_rank_count_dimm_0 = 4;
        l_info.iv_rank_count_dimm_1 = 1;

        // set up the mapping data
        uint8_t l_pMapping[VPD_KEYWORD_SIZE] = {
                // Header: version=1, num entries=4, reserved
                1,4,0,
               // miss: mcs match, pair match, freq miss
               0xff,0xff,0xff,0xff,0xef,'0',
               // miss: mcs match, pair missing, freq match
               0xff,0xff,0xff,0xfd,0xff,'1',
               // miss: mcs miss, pair match, freq match
               0xfe,0xff,0xff,0xff,0xff,'2',
               // match:
               0x01,0x00,0x00,0x04,0x10,'3', // <-- should be this one
               // zero out rest
               0};

        // decode keyword
        keywordName_t l_keywordName = {0};
        numTests++;
        FAPI_EXEC_HWP(l_rc,
                  p9_get_mem_vpd_keyword,
                  l_fapiTarget,
                  l_info,
                  l_pMapping,
                  VPD_KEYWORD_SIZE,
                  l_keywordName);
        if(l_rc)
        {
            TS_FAIL  ("testDecode_MT:: p9_get_mem_vpd_keyword failed");
            numFails++;
            break; // decode failed
        }

        // compare to expected test data
        numTests++;
        if ( (l_keywordName[0] != 'X' ) &&
             (l_keywordName[1] != '3' ) )
        {
            TS_FAIL  ("testDecode_MT:: unexpected keyword name returned"
                     "value = %x %x expected = %x %x",
                     l_keywordName[0],l_keywordName[1],'X','3');
            numFails++;
        }

    }
    while(0);

    FAPI_INF("testDecode MT Test Complete, %d/%d fails",
             numFails, numTests);
}

void testGetVPD_MR(void)
{
    int numTests = 0;
    int numFails = 0;
    ReturnCode l_rc;

    FAPI_DBG("testGetVPD MR start");

    do
    {
        // get a MCS fapi2 target for MEMVPD_POS 0
        TARGETING::ATTR_MEMVPD_POS_type l_memVpdPos = 0;

        fapi2::Target<fapi2::TARGET_TYPE_MCS> l_fapiTarget;
        TARGETING::Target * l_target;
        if(!getTarget(l_memVpdPos,l_target,l_fapiTarget))
        {
            TS_FAIL  ("testGetVPD_MR:: could not find MCS MEMVPD_POS=%d",
                     l_memVpdPos);
            numFails++;
            break; //Target not found
        }

        // set up VPDInfo
        // simics test data will return keyword J0
        fapi2::VPDInfo<fapi2::TARGET_TYPE_MCS> l_info(fapi2::MR);
        l_info.iv_freq_mhz = 1866;
        l_info.iv_rank_count_dimm_0 = 1;
        l_info.iv_rank_count_dimm_1 = 4;

        l_rc = testGetVPD(l_fapiTarget,
                          l_info,
                          fapi2::MR,
                          nullptr, //don't test data, just ability to access
                          numTests,
                          numFails);
        if(l_rc)
        {
            TS_FAIL  ("testGetVPD MR:: testGetVPD decode failed");
            break; // decode failed (don't double count num tests and fails)
        }

    }
    while(0);

    FAPI_INF("testGetVPD MR Test Complete, %d/%d fails",
             numFails, numTests);
}

void testGetVPD_MT(void)
{
    int numTests = 0;
    int numFails = 0;
    ReturnCode l_rc;

    FAPI_DBG("testGetVPD MT start");

    do
    {
        // get a MCS fapi2 target for MEMVPD_POS 7
        TARGETING::ATTR_MEMVPD_POS_type l_memVpdPos = 7;

        fapi2::Target<fapi2::TARGET_TYPE_MCS> l_fapiTarget;
        TARGETING::Target * l_target;
        if(!getTarget(l_memVpdPos,l_target,l_fapiTarget))
        {
            TS_FAIL  ("testGetVPD_MT:: could not find MCS MEMVPD_POS=%d",
                     l_memVpdPos);
            numFails++;
            break; //Target not found
        }

        // set up VPDInfo
        // simics test data will return keyword X0
        fapi2::VPDInfo<fapi2::TARGET_TYPE_MCS> l_info(fapi2::MT);
        l_info.iv_freq_mhz = 2667;
        l_info.iv_rank_count_dimm_0 = 4;
        l_info.iv_rank_count_dimm_1 = 1;

        l_rc = testGetVPD(l_fapiTarget,
                          l_info,
                          fapi2::MT,
                          nullptr, //don't test data, just ability to access
                          numTests,
                          numFails);
        if(l_rc)
        {
            TS_FAIL  ("testGetVPD MT:: testGetVPD decode failed");
            break; // decode failed (don't double count num tests and fails)
        }

    }
    while(0);

    FAPI_INF("testGetVPD MT Test Complete, %d/%d fails",
             numFails, numTests);
}

void testGetVPD_Override(void)
{
    int numMRTests = 0;
    int numMRFails = 0;
    int numMTTests = 0;
    int numMTFails = 0;
    ReturnCode l_rc;

    FAPI_DBG("testGetVPD Override start");

    do
    {
        // get a MCS fapi2 target for MEMVPD_POS 4
        numMTTests++;
        TARGETING::ATTR_MEMVPD_POS_type l_memVpdPos = 4;
        fapi2::Target<fapi2::TARGET_TYPE_MCS> l_fapiTarget;
        TARGETING::Target * l_target;
        if(!getTarget(l_memVpdPos,l_target,l_fapiTarget))
        {
            TS_FAIL  ("testGetVPD_Overrides:: could not find MCS MEMVPD_POS=%d",
                     l_memVpdPos);
            numMTFails++;
            break; //Target not found
        }

        //Skip test if already overriden
        TARGETING::ATTR_VPD_OVERRIDE_MT_ENABLE_type l_mtType =
            l_target->getAttr<TARGETING::ATTR_VPD_OVERRIDE_MT_ENABLE>();
        if (0 == l_mtType)
        {
            //Set the overriden data.
            //Use the plat attr svc helper function to set the override
            //attributes because the override attributes are not writable.
            //The helper avoids the error checks.
            uint8_t l_overrideMT[VPD_KEYWORD_SIZE] = {'O','T',0};
            bool l_setWorked = fapi2::platAttrSvc::setTargetingAttrHelper(
                                   l_target,
                                   TARGETING::ATTR_VPD_OVERRIDE_MT,
                                   sizeof(l_overrideMT),
                                   &l_overrideMT);
            if (!l_setWorked)
            {
                TS_FAIL  ("testGetVPD_Overrides:: "
                          "could not set ATTR_VPD_OVERRIDE_MT");
                numMTFails++;
                break; //stop on error
            }

            //Set override enable
            numMTTests++;
            l_mtType = 1;
            l_setWorked = fapi2::platAttrSvc::setTargetingAttrHelper(
                                   l_target,
                                   TARGETING::ATTR_VPD_OVERRIDE_MT_ENABLE,
                                   sizeof(l_mtType),
                                   &l_mtType);
            if (!l_setWorked)
            {
                TS_FAIL  ("testGetVPD_Overrides:: "
                          "could not set ATTR_VPD_OVERRIDE_MT_ENABLE");
                numMTFails++;
                break; //stop on error
            }

            // set up VPDInfo, only type should matter
            fapi2::VPDInfo<fapi2::TARGET_TYPE_MCS> l_info(fapi2::MT);

            l_rc = testGetVPD(l_fapiTarget,
                              l_info,
                              fapi2::MT,
                              "OT",
                              numMTTests,
                              numMTFails);
            if(l_rc)
            {
                TS_FAIL  ("testGetVPD_Overrides:: testGetVPD failed");
                break; // failed (don't double count num tests and fails)
            }

            // restore to not being overriden
            numMTTests++;
            l_mtType = 0;
            l_setWorked = fapi2::platAttrSvc::setTargetingAttrHelper(
                                   l_target,
                                   TARGETING::ATTR_VPD_OVERRIDE_MT_ENABLE,
                                   sizeof(l_mtType),
                                   &l_mtType);
            if (!l_setWorked)
            {
                TS_FAIL  ("testGetVPD_Overrides:: "
                          "could not set ATTR_VPD_OVERRIDE_MT_ENABLE");
                numMTFails++;
                break; //stop on error
            }
        }

        //Set override enable and data for MR
        //Skip test if already overriden
        TARGETING::ATTR_VPD_OVERRIDE_MR_ENABLE_type l_mrType =
            l_target->getAttr<TARGETING::ATTR_VPD_OVERRIDE_MR_ENABLE>();
        if (0 == l_mrType)
        {
            //Set the overriden data.
            uint8_t l_overrideMR[VPD_KEYWORD_SIZE] = {'O','R',0};
            bool l_setWorked = fapi2::platAttrSvc::setTargetingAttrHelper(
                                   l_target,
                                   TARGETING::ATTR_VPD_OVERRIDE_MR,
                                   sizeof(l_overrideMR),
                                   &l_overrideMR);
            if (!l_setWorked)
            {
                TS_FAIL  ("testGetVPD_Overrides:: "
                          "could not set ATTR_VPD_OVERRIDE_MR");
                numMRFails++;
                break; //stop on error
            }

            //Set override enable
            numMRTests++;
            l_mrType = 1;
            l_setWorked = fapi2::platAttrSvc::setTargetingAttrHelper(
                                   l_target,
                                   TARGETING::ATTR_VPD_OVERRIDE_MR_ENABLE,
                                   sizeof(l_mrType),
                                   &l_mrType);
            if (!l_setWorked)
            {
                TS_FAIL  ("testGetVPD_Overrides:: "
                          "could not set ATTR_VPD_OVERRIDE_MR_ENABLE");
                numMRFails++;
                break; //stop on error
            }

            // set up VPDInfo, only type should matter
            fapi2::VPDInfo<fapi2::TARGET_TYPE_MCS> l_info(fapi2::MR);

            l_rc = testGetVPD(l_fapiTarget,
                              l_info,
                              fapi2::MR,
                              "OR",
                              numMRTests,
                              numMRFails);
            if(l_rc)
            {
                TS_FAIL  ("testGetVPD_Overrides:: testGetVPD failed");
                break; // failed (don't double count num tests and fails)
            }

            // restore to not being overriden
            numMRTests++;
            l_mrType = 0;
            l_setWorked = fapi2::platAttrSvc::setTargetingAttrHelper(
                                   l_target,
                                   TARGETING::ATTR_VPD_OVERRIDE_MR_ENABLE,
                                   sizeof(l_mrType),
                                   &l_mrType);
            if (!l_setWorked)
            {
                TS_FAIL  ("testGetVPD_Overrides:: "
                          "could not set ATTR_VPD_OVERRIDE_MR_ENABLE");
                numMRFails++;
                break; //stop on error
            }
        }
    }
    while(0);

    FAPI_INF("testGetVPD Override Test Complete, %d/%d fails",
             numMRFails+numMTFails, numMRTests+numMTTests);
}

