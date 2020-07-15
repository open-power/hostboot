/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/getVpdTest.C $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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

//RTC:257497-Update with new vpd targets and types

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
#include <errl/errlmanager.H>

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

