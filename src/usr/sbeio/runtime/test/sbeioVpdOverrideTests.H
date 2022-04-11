/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/runtime/test/sbeioVpdOverrideTests.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2022                        */
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
*  @file sbeioVpdOverrideTests.H
*
*  @brief testcases for sbeApplyVpdOverrides()
*         test data formatted as a vpdOverwriteCmd_t.
*         These tests utilize sbeApplyVpdOverrides() to
*         perform reads to various data sections, however
*         this is only for testing purposes, and
*         sbeApplyVpdOverrides() should not be used for
*         reads outside of these tests
*/

#ifndef __SBEIO_SBEIO_VPD_OVERRIDES_TEST_H
#define __SBEIO_SBEIO_VPD_OVERRIDES_TEST_H

#include <cxxtest/TestSuite.H>
#include <runtime/interface.h>
#include <sbeio/runtime/sbe_msg_passing.H>
#include <sbeio/sbeioreasoncodes.H>
#include <vpd/vpdreasoncodes.H>
#include <secureboot/service.H>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <targeting/runtime/rt_targeting.H>
#include <errl/errlmanager.H>
#include <devicefw/userif.H>

#include <eeprom/eepromif.H>
#include <sbeio/runtime/sbeio_vpd_override.H>

#include <vpd/mvpdenums.H>

#include <initservice/mboxRegs.H>

#include <vector>

#include <string.h>
#include <stdio.h>

//See rt_sbeio.C
namespace RT_SBEIO
{
    int process_sbe_msg(uint32_t i_procChipId);
}

extern trace_desc_t* g_trac_sbeio;

#define SBE_VPDOVER_TRACF(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"SbePassThroughApplyVpdOverrides: " printf_string,##args)


const uint8_t testGoodMVPDRecKeyPath[] = {
// BYTE 0: flag for data section to write, and the method. 0x00 = MVPD using keyword, record
    0x00,
// BYTE 1-32: target identifier string. Set to all 0x00 since procChip found in step #1
// is used for writting to MVPD
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
// BYTE 33-40: Keyword. 'ED'   = 0x45, 0x44
// These are passed as ascii string literals of they keywords defined in mvpd.H
    0x45, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
// BYTE 41-48: Record.  'CRP0' = 0x43, 0x52, 0x50, 0x30
// same as Keyword. Ascii string literals
    0x43, 0x52, 0x50, 0x30, 0x00, 0x00, 0x00, 0x00,
// the ED keyword in the CRPO record is 33 bytes long acording to mvpd_p10_spec_V01_04a.pdf
// so fill in 33 bytes of test data
    0xDE, 0xAD, 0xBE, 0xEF,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE,
    0xDD,
    0xDE, 0xAD, 0xBE, 0xEF,

};

// the value for the offset used in this test was found by tracing out the
// following value in IpVpdFacade::writeKeyword()
//               // Write directly to target's EEPROM.
//               err = DeviceFW::deviceOp( DeviceFW::WRITE,
//                                         i_target,
//                                         i_buffer,
//                                         keywordSize,
//                                         DEVICE_EEPROM_ADDRESS(
//                                             EEPROM::VPD_AUTO,
//                                             i_recordOffset+keywordOffset,    <---------
//                                             EEPROM::AUTOSELECT) );
const uint8_t testGoodMVPDOffsetPath[] = {
// BYTE 0: flag for data section to write, and the method. 0x01 = MVPD using offset write
    0x01,
// BYTE 1-32: target identifier string. Set to all 0x00 since procChip found in step #1
// is used for writting to MVPD
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
// BYTE 33-40: Offset into the data section, MVPD in this case.
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8D, 0x45,
// BYTE 41-48: number of bytes to write starting at the offset above
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x21,
    0xDE, 0xAD, 0xBE, 0xEF,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE,
    0xDD,
    0xDE, 0xAD, 0xBE, 0xEF,
};


const uint8_t testBadMethodData[] = {
// BYTE 0: flag for data section to write, and the method. 0xFF = INVALID
    0xFF,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x45, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x43, 0x52, 0x50, 0x30, 0x00, 0x00, 0x00, 0x00,
    0xDE, 0xAD, 0xBE, 0xEF,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE,
    0xDD,
    0xDE, 0xAD, 0xBE, 0xEF,

};

const uint8_t testBadRecordStringData[] = {
    0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
// BYTE 33-40: Keyword. 'ED'   = 0x45, 0x44
    0x45, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
// BYTE 41-48: Record.  'DEAD' = 0x44, 0x45, 0x41, 0x44
    0x44, 0x45, 0x41, 0x44, 0x00, 0x00, 0x00, 0x00,
    0xDE, 0xAD, 0xBE, 0xEF,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE,
    0xDD,
    0xDE, 0xAD, 0xBE, 0xEF,

};

const uint8_t testBadKeywordStringData[] = {
    0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
// BYTE 33-40. Keyword. 'DEAD' = 0x44, 0x45, 0x41, 0x44
    0x44, 0x45, 0x41, 0x44, 0x00, 0x00, 0x00, 0x00,
// BYTE 41-48: Record.  'CRP0' = 0x43, 0x52, 0x50, 0x30
    0x43, 0x52, 0x50, 0x30, 0x00, 0x00, 0x00, 0x00,
    0xDE, 0xAD, 0xBE, 0xEF,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE,
    0xDD,
    0xDE, 0xAD, 0xBE, 0xEF,

};

// This test attempts to send a valid header, but with no data to write
// this test exercises that sbeApplyVpdOverrides() checks that there is
// at least 1 byte of data is send to be written
const uint8_t testShortMessageData[] = {
    0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x45, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x43, 0x52, 0x50, 0x30, 0x00, 0x00, 0x00, 0x00,
    // the sbeApplyVpdOverrides() func expects a message strictly greater than 49 bytes
    // (sizeof(vpdCmdHeader)) since from the 50th byte onward should be the data to write to the vpd
};

const uint8_t testOffsetShortData[] = {
    0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
// BYTE 33-40: Offset into the data section, CRP0, ED in this case.
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11,
// BYTE 41-48: number of bytes to write starting at the offset above
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x21,
// above we said we're writting 33 bytes (0x21) of data
// so only fill in 32 below to hit the error path
    0xDE, 0xAD, 0xBE, 0xEF,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE,
    //0xDD,
    0xDE, 0xAD, 0xBE, 0xEF,

};

const uint8_t testOffsetLongData[] = {
    0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
// BYTE 33-40: Offset into the data section, CRP0, ED in this case.
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11,
// BYTE 41-48: number of bytes to write starting at the offset above
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x21,
// above we said we're writting 33 (0x21) bytes of data
// so fill in 34 below to hit the error path
    0xDE, 0xAD, 0xBE, 0xEF,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE,
    0xDD, 0xDD,
    0xDE, 0xAD, 0xBE, 0xEF,

};

#define CHECK_PRTF_RESULT(rc, remaining, ptr) \
if(rc > 0 && rc < remaining) \
{ \
    remaining -= rc; \
    ptr += rc; \
    if(remaining <= 0) \
    { \
        break; \
    } \
} \
else \
{ \
    break; \
}

using namespace SBE_MSG;
using namespace VPD;

// forward declare ClearToSend enum from sbeioAttrOverrideTests.H
enum class ClearToSend : int;

using namespace CxxTest;

//------------------------------------------------------------------
class SbePassThroughApplyVpdOverrides: public CxxTest::TestSuite
{
public:
//SbePassThroughApplyVpdOverrides
    //------------------------------------------------------
    void testApplyVpdRecKeyGoodPath()
    {
        SBE_VPDOVER_TRACF("Starting testApplyVpdGoodPath");

        if(sendTestData(testGoodMVPDRecKeyPath) == 0)
        {
            SBE_VPDOVER_TRACF("testApplyVpdGoodPath passed!");
        }
        else
        {
            TS_FAIL("testApplyVpdGoodPath failed!");
        }
    }

    //------------------------------------------------------
    void testApplyVpdOffsetGoodPath()
    {
        SBE_VPDOVER_TRACF("Starting testApplyVpdOffsetGoodPath");

        if(sendTestData(testGoodMVPDOffsetPath) == 0)
        {
            SBE_VPDOVER_TRACF("testApplyVpdOffsetGoodPath passed!");
        }
        else
        {
            TS_FAIL("testApplyVpdOffsetGoodPath failed!");
        }
    }

    //------------------------------------------------------
    void testBadMethod()
    {
        SBE_VPDOVER_TRACF("Starting testBadMethod");

        if(sendTestData(testBadMethodData) == VPD_INVALID_METHOD_OR_DATA_SECTION)
        {
            SBE_VPDOVER_TRACF("testBadMethod passed!");
        }
        else
        {
            TS_FAIL("testBadMethod failed!");
        }
    }

    //------------------------------------------------------
    void testBadRecordString()
    {
        SBE_VPDOVER_TRACF("Starting testBadRecordString");

        if(sendTestData(testBadRecordStringData) == VPD_RECORD_NOT_FOUND)
        {
            SBE_VPDOVER_TRACF("testBadRecordString passed!");
        }
        else
        {
            TS_FAIL("testBadRecordString failed!");
        }
    }

    //------------------------------------------------------
    void testBadKeywordString()
    {
        SBE_VPDOVER_TRACF("Starting testBadKeywordString");

        if(sendTestData(testBadKeywordStringData) == VPD_KEYWORD_NOT_FOUND)
        {
            SBE_VPDOVER_TRACF("testBadKeywordString passed!");
        }
        else
        {
            TS_FAIL("testBadKeywordString failed!");
        }
    }

    //------------------------------------------------------
    void testShortMessage()
    {
        SBE_VPDOVER_TRACF("Starting testShortMessage");

        if(sendTestData(testShortMessageData) == VPD_SHORT_REQUEST)
        {
            SBE_VPDOVER_TRACF("testShortMessage passed!");
        }
        else
        {
            TS_FAIL("testShortMessage failed!");
        }
    }

    //------------------------------------------------------
    void testOffsetWriteShortData()
    {
        SBE_VPDOVER_TRACF("Starting testOffsetWriteShortData");

        if(sendTestData(testOffsetShortData) == VPD_BYTES_TO_WRITE_MISMATCH)
        {
            SBE_VPDOVER_TRACF("testOffsetWriteShortData passed!");
        }
        else
        {
            TS_FAIL("testOffsetWriteShortData failed!");
        }
    }

    //------------------------------------------------------
    void testOffsetWriteLongData()
    {
        SBE_VPDOVER_TRACF("Starting testOffsetWriteLongData");

        if(sendTestData(testOffsetLongData) == VPD_BYTES_TO_WRITE_MISMATCH)
        {
            SBE_VPDOVER_TRACF("testOffsetWriteLongData passed!");
        }
        else
        {
            TS_FAIL("testOffsetWriteLongData failed!");
        }
    }

private:

    uint32_t iv_seqNumber{0};

    template <uint32_t N>
    int sendTestData(const uint8_t (& testData)[N]){

        //#############################################################
        //STEPS:
        // 1) Get Chip ID
        // 2) Read the original vpd data
        // 3) Write the testData
        //     A) Get runtime interfaces for sbe_msg_passing
        //     B) Ensure that another SBE pass-through is not in progress
        //     C) Get pointer to SBE COMMS AREA
        //     D) Setup Request Data
        //     E) Setup Expected Response
        //     F) Copy Request Data to SBE COMMS AREA
        //     G) Invoke sbe_message_passing
        //     H) Check Response Message
        // 4) Read back the vpd data after writing
        // 5) Compare the data written to test data
        // 6) Write back the original data
        // 7) Clear Register CFAM Reg 0x283B

        TARGETING::TargetHandle_t l_proc{};
        int result = 0;

        SBE_VPDOVER_TRACF("SBE_MSG_DATA_OFFSET: 0x%08X",
                              SBE_MSG_DATA_OFFSET);

        uint8_t * readCmd = new uint8_t[N];
        do
        {
            //##############################################
            // Step 1 - Get Chip ID
            //##############################################

            TARGETING::TargetHandleList procList;
            getAllChips(procList, TARGETING::TYPE_PROC, true);

            if(0 == procList.size())
            {
                TS_FAIL("SbePassThroughApplyVpdOverrides: "
                        "Unable to get proc targets.");

                result = -1;
                break;
            }

            l_proc = procList[0];
            TARGETING::rtChipId_t l_chipId = 0;
            errlHndl_t l_err = TARGETING::getRtTarget(l_proc, l_chipId);

            if(nullptr != l_err)
            {
                TS_FAIL("SbePassThroughApplyVpdOverrides: "
                        "RT_TARG::getRtTarget returned an error.");

                errlCommit(l_err, SBEIO_COMP_ID);

                result = -1;
                break;
            }

            //#############################################
            // Step 2 - read the original vpd data
            //#############################################

            // assume testcase writer doesn't know the size of the data section being
            // read, so use SBE_MSG_MAX_DATA as the max upperbound for data read in
            uint32_t l_size = SBE_MSG_MAX_DATA;
            std::vector<uint8_t> l_origData(l_size, 0);

            // mask on the 'Read' bit onto the dataSectionAndMethod byte in the testData
            memcpy(readCmd, testData, N);
            readCmd[0] |= READ_CMD_MASK;

            // after this call, l_size is the # of bytes read into l_origData
            l_err = sbeApplyVpdOverrides(l_proc,
                                         N,
                                         readCmd, reinterpret_cast<uint32_t * >(&result),
                                         &l_size, l_origData.data());

            if (l_err || result != 0)
            {
                result = l_err->reasonCode();
                TS_INFO("SbePassThroughApplyVpdOverrides: failed to read the vpd data");
                break;
            }

            //#############################################
            // Step 3 - write the testData
            //#############################################
            result = invokeSBEMessagePassing(testData, sizeof(testData), l_proc, l_chipId);
            // if result != 0 then some form of error occured when writting the data
            if (result != 0)
            {
                TS_INFO("SbePassThroughApplyVpdOverrides: failed to write test data");
                break;
            }

            //#############################################
            // Step 4 - Read back the vpd data after writing
            //#############################################

            // read size, l_size, is known now,so use instead of SBE_MSG_MAX_DATA
            std::vector<uint8_t> l_dataAfterWrite(l_size, 0);

            l_err = sbeApplyVpdOverrides(l_proc,
                                         N,
                                         readCmd,
                                         reinterpret_cast<uint32_t * >(&result),
                                         &l_size, l_dataAfterWrite.data());

            // if there was an error in reading the data,
            // break since we were able to do a successful read before
            if (l_err || result != 0)
            {
                result = l_err->reasonCode();
                TS_INFO("SbePassThroughApplyVpdOverrides: failed to read the vpd data "
                        "after successfully writting");
                break;
            }

            //#############################################
            // Step 5 - Compare the data written to test data
            //#############################################

            if(memcmp(static_cast<void *>(& l_dataAfterWrite[0]),
                                         (testData + sizeof(vpdCmdHeader_t)),
                                         l_size) != 0)
            {
                TS_FAIL("SbePassThroughApplyVpdOverrides: "
                        "MVPD data after write is not the same as the test data");
                TRACFBIN( g_trac_sbeio, "testdata",
                                         (testData + sizeof(vpdCmdHeader_t)),
                                         N - sizeof(vpdCmdHeader_t));
                TRACFBIN( g_trac_sbeio, "l_dataAfterWrite",
                                         static_cast<void *>(& l_dataAfterWrite[0]), l_size);

                result = -1;
                break;
            }

            //#############################################
            // Step 6 - write back the original data
            //#############################################

            // use the testData's cmdHeader section to write to the original
            // location and use the l_origData as the data to write
            uint8_t * array = new uint8_t[N];
            memcpy(array, testData, sizeof(vpdCmdHeader_t));
            memcpy(array + sizeof(vpdCmdHeader_t),
                   l_origData.begin(),
                   l_size);
            result = invokeSBEMessagePassing(array, N, l_proc, l_chipId);

            delete [] array;
            array = nullptr;
            // if result != 0 then some form of error occured when writting back the data
            if (result != 0)
            {
                TS_INFO("SbePassThroughApplyVpdOverrides: failed to write back original data");
                break;
            }

        }
        while(0);

        delete [] readCmd;
        readCmd = nullptr;

        //#############################################
        // Step 7 - Clear Register CFAM Reg 0x283B
        //#############################################

        // regardless of a previous error, attempt to clear the control register
        bool controlRegisterCleared = clearControlRegister(l_proc);

        if(not controlRegisterCleared)
        {
            TS_FAIL("SbePassThroughApplyVpdOverrides: "
                    "clearControlRegister returned false");
            // if an error code was not returned above
            // make sure to return a non-zero result
            if (result == 0)
            {
                result = -1;
            }
        }

        return result;
    }

    //-----------------------------------------------------------
    ClearToSend ensureClearToSend(TARGETING::TargetHandle_t i_proc)
    {
        using namespace INITSERVICE::SPLESS;

        ClearToSend retval{ClearToSend::OK};

        do
        {
            if(not i_proc)
            {
                SBE_VPDOVER_TRACF("ensureClearToSend, i_proc is NULL!");

                TS_FAIL("ensureClearToSend, i_proc is NULL!");

                retval = ClearToSend::FAIL;
                break;
            }

            MboxScratch4_t l_register { };
            size_t l_size = sizeof(uint64_t);

            errlHndl_t errl =
            deviceRead(i_proc,
                       &l_register.data32,
                       l_size,
                       DEVICE_SCOM_ADDRESS(MboxScratch4_t::REG_ADDR));

            if(nullptr != errl)
            {
                errlCommit (errl, SBE_COMP_ID);
                errl = nullptr;

                SBE_VPDOVER_TRACF("ensureClearToSend, "
                                      "Failed to read scom register.");
                TS_FAIL("Failed to read scom register.");

                retval = ClearToSend::FAIL;
                break;
            }

            if(l_register.sbeMsgProc.sbeMsgProcessingInProgress)
            {
               TS_WARN("SCOM_ADDR_5003B SBE_MSG_IN_PROGRESS set!");

               retval = ClearToSend::WARN;
               break;
            }
        }
        while(0);

        return retval;
    }

    //-----------------------------------------------------------
    bool clearControlRegister(TARGETING::TargetHandle_t i_proc)
    {
        using namespace INITSERVICE::SPLESS;

        bool retval{true};

        do
        {
            if(not i_proc)
            {
                SBE_VPDOVER_TRACF("ensureClearToSend, "
                                      "i_proc is NULL!");

                TS_FAIL("ensureClearToSend, i_proc is NULL!");

                retval = false;
                break;
            }

            MboxScratch4_t l_register{};
            size_t l_size = sizeof(uint64_t);

            errlHndl_t errl =
            deviceRead(i_proc,
                       &l_register.data32,
                       l_size,
                       DEVICE_SCOM_ADDRESS(MboxScratch4_t::REG_ADDR));

            if(nullptr != errl)
            {
                errlCommit (errl, SBE_COMP_ID);
                errl = nullptr;

                SBE_VPDOVER_TRACF("ensureClearToSend, "
                                      "Failed to read scom register.");
                TS_FAIL("Failed to read scom register.");

                retval = false;
                break;
            }

            l_register.sbeMsgProc.sbeMsgProcessingComplete = false;
            l_register.sbeMsgProc.sbeMsgProcessingInProgress = false;

            errl = deviceWrite(i_proc,
                               &l_register.data32,
                               l_size,
                               DEVICE_SCOM_ADDRESS(MboxScratch4_t::REG_ADDR));

            if(nullptr != errl)
            {
                errlCommit (errl, SBE_COMP_ID);
                errl = nullptr;

                SBE_VPDOVER_TRACF("ensureClearToSend, "
                                      "Failed to write to scom register.");
                TS_FAIL("Failed to read scom register.");

                retval = false;
                break;
            }
        }
        while(0);

        return retval;
    }

    //-----------------------------------------------------------
    template<size_t N>
    void printSbeMessage(char (&strbuffer)[N],
                         const char* prefix,
                         const SBE_MSG::sbeMessage_t& msg)
    {
        memset(strbuffer, 0, N);
        char* ptr = strbuffer;

        do
        {
            int remaining = static_cast<int>(N - 1);
            int rc = 0;

            rc = snprintf(ptr,
                          static_cast<size_t>(remaining),
                          "%s\n",
                          prefix);
            CHECK_PRTF_RESULT(rc, remaining, ptr);

            rc = snprintf(ptr,
                          static_cast<size_t>(remaining),
                          "\tsbeHdr.version: 0x%08X\n",
                           msg.sbeHdr.version);
            CHECK_PRTF_RESULT(rc, remaining, ptr);

            rc = snprintf(ptr,
                          static_cast<size_t>(remaining),
                          "\tsbeHdr.msgSize: 0x%08X\n",
                           msg.sbeHdr.msgSize);
            CHECK_PRTF_RESULT(rc, remaining, ptr);

            rc = snprintf(ptr,
                          static_cast<size_t>(remaining),
                          "\tsbeHdr.seqId 0x%08X\n",
                          msg.sbeHdr.seqId);
            CHECK_PRTF_RESULT(rc, remaining, ptr);

            rc = snprintf(ptr,
                          static_cast<size_t>(remaining),
                          "\tcmdHdr.version 0x%08X\n",
                          msg.cmdHdr.version);
            CHECK_PRTF_RESULT(rc, remaining, ptr);

            rc = snprintf(ptr,
                          static_cast<size_t>(remaining),
                          "\tcmdHdr.status  0x%08X\n",
                          msg.cmdHdr.status);
            CHECK_PRTF_RESULT(rc, remaining, ptr);

            rc = snprintf(ptr,
                          static_cast<size_t>(remaining),
                          "\tcmdHdr.dataOffset 0x%08X\n",
                          msg.cmdHdr.dataOffset);
            CHECK_PRTF_RESULT(rc, remaining, ptr);

            rc = snprintf(ptr,
                          static_cast<size_t>(remaining),
                          "\tcmdHdr.dataSize 0x%08X\n",
                          msg.cmdHdr.dataSize);
            CHECK_PRTF_RESULT(rc, remaining, ptr);

            rc = snprintf(ptr,
                          static_cast<size_t>(remaining),
                          "\tcmdHdr.command  0x%08X\n",
                          msg.cmdHdr.command);
            CHECK_PRTF_RESULT(rc, remaining, ptr);
        }
        while(0);
    }

    /*-----------------------------------------------------------
     * @brief copies testData to the SBE Comms area and invokes
     *        sbe_message_passing to call sbeApplyVpdOverrides
     *
     * @param [in] testData - pointer to the data to send sbeApplyVpdOverrides
     *                        through SBE Comms area
     *
     * @param [in] i_size   - size in bytes of testData
     *
     * @param [in] i_proc   - used to get the SBE Comms area and check
     *                        that another SBE pass-through is not in
     *                        progress
     *
     * @param [in] i_chipId - chip target to invoke the message passing on
     *
     * @return result       - 0 if sbe_message_passing call was successful,
     *                        -1 if there was a setup or response issue, or
     *                        a vpdReasonCode if sbeApplyVpdOverrides()
     *                        encoutered an error
     */
    int invokeSBEMessagePassing(const void * testData,
                                size_t i_size,
                                TARGETING::TargetHandle_t i_proc,
                                TARGETING::rtChipId_t i_chipId)
    {

        using sbeCommAddr_t = void*;
        int result = 0;

        do {
            //#################################################################
            // Step A - get runtime interfaces for sbe_msg_passing
            //#################################################################

            runtimeInterfaces_t* l_rt = getRuntimeInterfaces();
            if(nullptr == l_rt)
            {
                TS_FAIL("SbePassThroughApplyVpdOverrides: "
                        "Unable to get runtime interfaces.");

                result = -1;
                break;
            }

            if (&RT_SBEIO::process_sbe_msg != l_rt->sbe_message_passing)
            {
                TS_FAIL("invokeSBEMessagePassing: sbe_message_passing function pointer is not set to RT_SBEIO::process_sbe_msg()");
                break;
            }

            //#################################################################
            // Step B - Ensure that another SBE pass-through is not in progress
            //#################################################################

            ClearToSend clearToSend = ensureClearToSend(i_proc);
            if(ClearToSend::WARN == clearToSend)
            {
                clearControlRegister(i_proc);
            }
            else if(ClearToSend::FAIL == clearToSend)
            {
                result = -1;
                break;
            }

            //########################################
            // Step C - Get pointer to SBE COMMS AREA
            //########################################

            SBE_VPDOVER_TRACF("ChipId: 0x%016llX", i_chipId);

            sbeCommAddr_t l_sbeCommAddr{};
            uint64_t address = 0;

            bool bGotAttr =
               i_proc->tryGetAttr<TARGETING::ATTR_SBE_COMM_ADDR>(address);

            if(not bGotAttr || 0 == address)
            {
                uint64_t l_instance =
                    i_proc->getAttr<TARGETING::ATTR_POSITION>();

                address = g_hostInterfaces->get_reserved_mem(
                                                    HBRT_RSVD_MEM__SBE_COMM,
                                                    l_instance);

                if(0 == address)
                {
                    TS_FAIL("SbePassThroughApplyVpdOverrides: "
                            "Unable to get SBE communications area.");
                    result = -1;
                    break;
                }
            }

            l_sbeCommAddr = reinterpret_cast<void*>(address);
            SBE_VPDOVER_TRACF("SBE Area Address: "
                                  "0x%016llX. ",
                                   address);

            //########################################
            // Step D - Setup Request Data
            //########################################

            SBE_MSG::sbeMessage_t l_request{};

            //Setup request message.
            l_request.sbeHdr.version = SBE_MSG::SBEHDRVER_LATEST;
            l_request.sbeHdr.msgSize = sizeof(sbeHeader_t) +
                                       sizeof(cmdHeader_t) +
                                       i_size;
            l_request.sbeHdr.seqId = ++iv_seqNumber;

            l_request.cmdHdr.version = SBE_MSG::CMDHDRVER_LATEST;
            l_request.cmdHdr.status = 0;
            l_request.cmdHdr.dataOffset = SBE_MSG_DATA_OFFSET;
            l_request.cmdHdr.dataSize = i_size;
            l_request.cmdHdr.command = SBE_MSG::PASSTHRU_HBRT_OVERRIDE_VPD;

            memset(l_request.data,
                   0xFF,
                   sizeof(l_request.data));

            memcpy(l_request.data,
                   testData,
                   l_request.cmdHdr.dataSize);

            //########################################
            // Step E - Setup Expected Response
            //########################################

            SBE_MSG::sbeMessage_t l_expectedResponse{};

            memset(&l_expectedResponse, 0, sizeof(SBE_MSG::sbeMessage_t));

            l_expectedResponse.sbeHdr.version = SBE_MSG::SBEHDRVER_LATEST;
            l_expectedResponse.sbeHdr.msgSize = sizeof(sbeHeader_t) +
                                                sizeof(cmdHeader_t);
            l_expectedResponse.sbeHdr.seqId = l_request.sbeHdr.seqId;

            l_expectedResponse.cmdHdr.version = SBE_MSG::CMDHDRVER_LATEST;
            l_expectedResponse.cmdHdr.status = 0;
            l_expectedResponse.cmdHdr.dataOffset = SBE_MSG_DATA_OFFSET;
            l_expectedResponse.cmdHdr.dataSize = 0;
            l_expectedResponse.cmdHdr.command = l_request.cmdHdr.command;
            memset(l_expectedResponse.data,
                   0,
                   sizeof(l_expectedResponse.data));

            //#############################################
            // Step F - Copy Request Data to SBE COMMS AREA
            //#############################################

            memcpy(l_sbeCommAddr, &l_request, l_request.sbeHdr.msgSize);

            {
                char msgBuffer[256] = {0};
                printSbeMessage(msgBuffer,
                                "Pre Call SBE Area Dump",
                                *(reinterpret_cast<SBE_MSG::sbeMessage_t*>
                                                              (l_sbeCommAddr)));
                SBE_VPDOVER_TRACF("SbePassThroughApplyVpdOverrides: %s", msgBuffer);
            }

            //#############################################
            // Step G - Invoke process_sbe_msg
            //#############################################

            // the rc from the sbe_msg_passing is the reasoncode of the errorlog
            // that was created in sbeApplyVpdOverrides, 0 if no error was created
            result = RT_SBEIO::process_sbe_msg(i_chipId);
            if(0 != result)
            {
                TS_INFO("SbePassThroughApplyVpdOverrides: "
                        "process_sbe_msg failed. rc: 0x%X",
                         result);
                break;
            }

            {
                char msgBuffer[256] = {0};
                printSbeMessage(msgBuffer,
                                "Post Call SBE Area Dump",
                                *(reinterpret_cast<SBE_MSG::sbeMessage_t*>
                                                              (l_sbeCommAddr)));
                SBE_VPDOVER_TRACF("SbePassThroughApplyVpdOverrides: %s", msgBuffer);
            }

            //#############################################
            // Step H - Check Response Message
            //#############################################

            SBE_MSG::sbeMessage_t l_response{};
            memset(&l_response, 0, sizeof(SBE_MSG::sbeMessage_t));
            memcpy(&l_response,
                   l_sbeCommAddr,
                   l_expectedResponse.sbeHdr.msgSize);

            memset(l_sbeCommAddr, 0, l_request.sbeHdr.msgSize);

            //see if the response matches the expectations.
            if(
               (memcmp(&l_response.cmdHdr,
                       &l_expectedResponse.cmdHdr,
                      sizeof(cmdHeader_t))) != 0 ||
               (memcmp(&l_response.sbeHdr,
                       &l_expectedResponse.sbeHdr,
                       sizeof(sbeHeader_t)) != 0)
              )
            {
                char msgBuffer[256] = {0};
                printSbeMessage(msgBuffer, "Actual Response", l_response);
                SBE_VPDOVER_TRACF("actual response "
                                      "differs from expected response.");
                SBE_VPDOVER_TRACF("SbePassThroughApplyVpdOverrides: %s", msgBuffer);
                printSbeMessage(msgBuffer,
                                "Expected Response", l_expectedResponse);

                SBE_VPDOVER_TRACF("SbePassThroughApplyVpdOverrides: %s", msgBuffer);

                TS_FAIL("SbePassThroughApplyVpdOverrides: The actual response differs "
                        "from the expected response.");
                result = -1;
                break;
            }
        } while(0);
        return result;
    }
};

#endif
