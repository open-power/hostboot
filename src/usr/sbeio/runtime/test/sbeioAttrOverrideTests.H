/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/runtime/test/sbeioAttrOverrideTests.H $         */
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
#ifndef __SBEIO_SBEIO_ATTR_OVERRIDES_TEST_H
#define __SBEIO_SBEIO_ATTR_OVERRIDES_TEST_H

#include <cxxtest/TestSuite.H>
#include <runtime/interface.h>
#include <sbeio/runtime/sbe_msg_passing.H>
#include <sbeio/sbeioreasoncodes.H>
#include <secureboot/service.H>
#include <targeting/common/attributeTank.H>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <targeting/runtime/rt_targeting.H>
#include <errl/errlmanager.H>
#include <devicefw/userif.H>
#include <initservice/mboxRegs.H>

#include <string.h>
#include <stdio.h>

//See rt_sbeio.C
namespace RT_SBEIO
{
    int process_sbe_msg(uint32_t i_procChipId);
}

extern trace_desc_t* g_trac_sbeio;

#define SBE_PASSTHROUGH_TRACF(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"SbePassThroughTests: " printf_string,##args)


//=======================================
// Test Data - overrides
//=======================================
/*
target
ATTR_SCRATCH_UINT8_1 0xCE
ATTR_SCRATCH_UINT8_2 0xFE
ATTR_SCRATCH_UINT32_1 0x12345678
ATTR_SCRATCH_UINT32_2 0xAABBCCDD
ATTR_SCRATCH_UINT64_1 0x1234567890ABCDEF
ATTR_SCRATCH_UINT64_2 0x1A2B3C4D5E6F7890
*/

const uint16_t attrOverrideData[] = {
    0x0000, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0011,
    0x0c7b, 0xc372, 0x0000, 0x0001, 0xffff, 0xfff0, 0x0000, 0x0001,
    0xce00, 0x0000, 0x0200, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x110e, 0x9341, 0x9a00, 0x0000, 0x01ff, 0xffff, 0xf000, 0x0000,
    0x01fe, 0x0000, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0014, 0x0782, 0xc053, 0x0000, 0x0001, 0xffff, 0xfff0, 0x0000,
    0x0004, 0x1234, 0x5678, 0x0000, 0x0002, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0014, 0x0002, 0x156b, 0x0000, 0x0001, 0xffff,
    0xfff0, 0x0000, 0x0004, 0xaabb, 0xccdd, 0x0000, 0x0002, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0018, 0x0eee, 0x9926, 0x0000,
    0x0001, 0xffff, 0xfff0, 0x0000, 0x0008, 0x1234, 0x5678, 0x90ab,
    0xcdef, 0x0000, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0018, 0x018a, 0x17a2, 0x0000, 0x0001, 0xffff, 0xfff0, 0x0000,
    0x0008, 0x1a2b, 0x3c4d, 0x5e6f, 0x7890
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

enum class ClearToSend{OK, WARN, FAIL};

//------------------------------------------------------------------
class SbePassThroughApplyAttrOverrides: public CxxTest::TestSuite
{
public:

    //------------------------------------------------------
    void testApplyAtrr()
    {
        //#############################################################
        //STEPS:
        // 1) Get Chip ID
        // 2) Ensure that Another SBE pass-through is not in progress
        // 3) Get pointer to SBE COMMS AREA
        // 4) Setup Request Data
        // 5) Setup Expected Response
        // 6) Copy Request Data to SBE COMMS AREA
        // 7) Invoke sbe_message_passing
        // 8) Check Response Message
        // 9) Clear register CFAM Reg 0x283B
        // 10) Validate Attribute Tank was Updated
        // 11) Validate Target Override Values

        using sbeCommAddr_t = void*;
        TARGETING::TargetHandle_t l_proc{};
        bool result{true};
        bool l_allowOverrides{true};

#ifdef CONFIG_SECUREBOOT
       l_allowOverrides = SECUREBOOT::allowAttrOverrides();
#endif
        SBE_PASSTHROUGH_TRACF("SBE_MSG_DATA_OFFSET: 0x%08X",
                              SBE_MSG_DATA_OFFSET
                             );

        do
        {
            //##############################################
            // Step 1 - Get Chip ID
            //#############################################

            //get runtime interfaces
            runtimeInterfaces_t* l_rt = getRuntimeInterfaces();
            if(nullptr == l_rt)
            {
                TS_FAIL("SbePassThroughApplyAttrOverrides: "
                        "Unable to get runtime interfaces.");

                result = false;
                break;
            }
            else if(not l_rt->sbe_message_passing)
            {
                TS_FAIL("SbePassThroughApplyAttrOverrides: "
                        "sbe_message_passing runtime interface "
                        "has not been set.");

                result = false;
                break;
            }

            if (&RT_SBEIO::process_sbe_msg != l_rt->sbe_message_passing)
            {
                TS_FAIL("SbePassThroughApplyAttrOverrides: sbe_message_passing function pointer is not set to RT_SBEIO::process_sbe_msg()");
                break;
            }

            TARGETING::TargetHandleList procList;
            getAllChips(procList, TARGETING::TYPE_PROC, true);

            if(0 == procList.size())
            {
                TS_FAIL("SbePassThroughApplyAttrOverrides: "
                        "Unable to get proc targets."
                       );

                result = false;
                break;
            }

            l_proc = procList[0];
            TARGETING::rtChipId_t l_chipId = 0;
            errlHndl_t l_err = TARGETING::getRtTarget(l_proc, l_chipId);

            if(nullptr != l_err)
            {
                TS_FAIL("SbePassThroughApplyAttrOverrides: "
                        "RT_TARG::getRtTarget returned an error."
                       );

                errlCommit(l_err, SBEIO_COMP_ID);

                result = false;
                break;
            }

            printAttributes("Attributes Before SBE Passthrough:");

            //#################################################################
            // Step 2 - Ensure that Another SBE pass-through is not in progress
            //#################################################################

            ClearToSend clearToSend = ensureClearToSend(l_proc);
            if(ClearToSend::WARN == clearToSend)
            {
                clearControlRegister(l_proc);
            }
            else if(ClearToSend::FAIL == clearToSend)
            {
                result = false;
                break;
            }

            //########################################
            // Step 3 - Get pointer to SBE COMMS AREA
            //########################################

            SBE_PASSTHROUGH_TRACF("applyAtrrTest. ChipId: 0x%016llX", l_chipId);

            sbeCommAddr_t l_sbeCommAddr{};
            uint64_t address;

            bool bGotAttr =
               l_proc->tryGetAttr<TARGETING::ATTR_SBE_COMM_ADDR>(address);

            if(not bGotAttr || 0 == address)
            {
                uint64_t l_instance =
                    l_proc->getAttr<TARGETING::ATTR_POSITION>();

                address = g_hostInterfaces->get_reserved_mem(
                                                    HBRT_RSVD_MEM__SBE_COMM,
                                                    l_instance);

                if(0 == address)
                {
                    TS_FAIL("SbePassThroughApplyAttrOverrides: "
                            "Unable to get SBE communications area."
                           );
                    result = false;
                    break;
                }
            }

            l_sbeCommAddr = reinterpret_cast<void*>(address);
            SBE_PASSTHROUGH_TRACF("applyAtrrTest, SBE Area Address: "
                                  "0x%016llX. ",
                                   address
                                 );

            //########################################
            // Step 4 - Setup Request Data
            //########################################

            SBE_MSG::sbeMessage_t l_request;

            //Setup request message.
            l_request.sbeHdr.version = SBE_MSG::SBEHDRVER_LATEST;
            l_request.sbeHdr.msgSize = sizeof(sbeHeader_t) +
                                       sizeof(cmdHeader_t) +
                                       sizeof(attrOverrideData);
            l_request.sbeHdr.seqId = ++iv_seqNumber;

            l_request.cmdHdr.version = SBE_MSG::CMDHDRVER_LATEST;
            l_request.cmdHdr.status = 0;
            l_request.cmdHdr.dataOffset = SBE_MSG_DATA_OFFSET;
            l_request.cmdHdr.dataSize = sizeof(attrOverrideData);
            l_request.cmdHdr.command = SBE_MSG::PASSTHRU_HBRT_OVERRIDE_ATTR;

            memset(l_request.data,
                   0xFF,
                   sizeof(l_request.data));

            memcpy(l_request.data,
                   attrOverrideData,
                   l_request.cmdHdr.dataSize);

            //########################################
            // Step 5 - Setup Expected Response
            //########################################

            SBE_MSG::sbeMessage_t l_expectedResponse;

            memset(&l_expectedResponse, 0, sizeof(SBE_MSG::sbeMessage_t));

            l_expectedResponse.sbeHdr.version = SBE_MSG::SBEHDRVER_LATEST;
            l_expectedResponse.sbeHdr.msgSize = sizeof(sbeHeader_t) +
                                                sizeof(cmdHeader_t);
            l_expectedResponse.sbeHdr.seqId = l_request.sbeHdr.seqId;

            l_expectedResponse.cmdHdr.version = SBE_MSG::CMDHDRVER_LATEST;

            if(l_allowOverrides)
            {
                l_expectedResponse.cmdHdr.status = 0;
            }
            else
            {
                l_expectedResponse.cmdHdr.status = 0xFFFFFFFF;
            }

            l_expectedResponse.cmdHdr.dataOffset = SBE_MSG_DATA_OFFSET;
            l_expectedResponse.cmdHdr.dataSize = 0;
            l_expectedResponse.cmdHdr.command = l_request.cmdHdr.command;
            memset(l_expectedResponse.data,
                   0,
                   sizeof(l_expectedResponse.data));

            //#############################################
            // Step 6 - Copy Request Data to SBE COMMS AREA
            //#############################################

            memcpy(l_sbeCommAddr, &l_request, l_request.sbeHdr.msgSize);

            {
                char msgBuffer[256] = {0};
                printSbeMessage(msgBuffer,
                                "Pre Call SBE Area Dump",
                                *(reinterpret_cast<SBE_MSG::sbeMessage_t*>
                                                              (l_sbeCommAddr))
                                 );
                SBE_PASSTHROUGH_TRACF("applyAtrrTest, %s", msgBuffer);
            }

            //#############################################
            // Step 7 - Invoke sbe_message_passing
            //#############################################

            int rc = RT_SBEIO::process_sbe_msg(l_chipId);

            if(0 != rc)
            {
                TS_FAIL("SbePassThroughApplyAttrOverrides: "
                        "RT_SBEIO::process_sbe_msg failed. rc: %d",
                         rc
                       );
                result = false;
                break;
            }

            {
                char msgBuffer[256] = {0};
                printSbeMessage(msgBuffer,
                                "Post Call SBE Area Dump",
                                *(reinterpret_cast<SBE_MSG::sbeMessage_t*>
                                                              (l_sbeCommAddr))
                                 );
                SBE_PASSTHROUGH_TRACF("applyAtrrTest, %s", msgBuffer);
            }

            //#############################################
            // Step 8 - Check Response Message
            //#############################################

            SBE_MSG::sbeMessage_t l_response;
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
                SBE_PASSTHROUGH_TRACF("applyAtrrTest, actual response "
                                      "differs from expected response.");
                SBE_PASSTHROUGH_TRACF("applyAtrrTest, %s", msgBuffer);
                printSbeMessage(msgBuffer,
                                "Expected Response", l_expectedResponse);

                SBE_PASSTHROUGH_TRACF("applyAtrrTest, %s", msgBuffer);

                TS_FAIL("applyAtrrTest: The actual response differs "
                        "from the expected response.");
                result = false;
                break;
            }

            //#############################################
            // Step 9 - Clear Register CFAM Reg 0x283B
            //#############################################
            bool controlRegisterCleared = clearControlRegister(l_proc);

            if(not l_allowOverrides)
            {
                break;
            }

            //#############################################
            // Step 10 - Validate Attribute Tank Updated
            //#############################################
            uint8_t scratch_8_1{};
            constexpr uint8_t scratch_8_1_expected = 0xCE;

            uint8_t scratch_8_2{};
            constexpr uint8_t scratch_8_2_expected = 0xFE;

            uint32_t scratch_32_1{};
            constexpr uint32_t scratch_32_1_expected = 0x12345678;

            uint32_t scratch_32_2{};
            constexpr uint32_t scratch_32_2_expected = 0xAABBCCDD;

            uint64_t scratch_64_1{};
            constexpr uint64_t scratch_64_1_expected = 0x1234567890ABCDEF;

            uint64_t scratch_64_2{};
            constexpr uint64_t scratch_64_2_expected = 0x1A2B3C4D5E6F7890;

            constexpr uint16_t TARG_POS = 0xFFFF;
            constexpr uint8_t  TARG_CHIP_POS = 0xFF;
            constexpr uint8_t  TARG_NODE = 0x0F;

            const TARGETING::AttributeTank& l_tank =
                                TARGETING::Target::theTargOverrideAttrTank();

            //ATTR_SCRATCH_UINT8_1
            //===================================================
            if(not l_tank.getAttribute(
                                TARGETING::ATTR_SCRATCH_UINT8_1,
                                TARGETING::TYPE_SYS,
                                TARG_POS,
                                TARG_CHIP_POS,
                                TARG_NODE,
                                &scratch_8_1
                                    ))
            {
                SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                      "getAttribute failed for "
                                      "ATTR_SCRATCH_UINT8_1"
                                     );
                TS_FAIL("getAttribute failed for "
                         "ATTR_SCRATCH_UINT8_1");

                result = false;
                break;
            }

            SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                  "ATTR_SCRATCH_UINT8_1: 0x%02X",
                                   scratch_8_1
                                 );

            if(scratch_8_1_expected != scratch_8_1)
            {
                SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                      "ATTR_SCRATCH_UINT8_1 value "
                                      "differs from expected! "
                                      "Expected 0x%02X, Actual 0x%02X",
                                      scratch_8_1_expected,
                                      scratch_8_1
                                     );

                TS_FAIL("applyAtrrTest, "
                        "ATTR_SCRATCH_UINT8_1 value "
                        "differs from expected! "
                        "Expected 0x%02X, Actual 0x%02X",
                        scratch_8_1_expected,
                        scratch_8_1
                     );

                result = false;
                break;
            }


            //ATTR_SCRATCH_UINT8_2
            //===================================================
            if(not l_tank.getAttribute(
                                TARGETING::ATTR_SCRATCH_UINT8_2,
                                TARGETING::TYPE_SYS,
                                TARG_POS,
                                TARG_CHIP_POS,
                                TARG_NODE,
                                &scratch_8_2
                                    ))
            {
                SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                      "getAttribute failed for "
                                      "ATTR_SCRATCH_UINT8_2"
                                     );
                TS_FAIL("getAttribute failed for "
                         "ATTR_SCRATCH_UINT8_2");

                result = false;
                break;
            }

            SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                  "ATTR_SCRATCH_UINT8_2: 0x%02X",
                                   scratch_8_2
                                 );

            if(scratch_8_2_expected != scratch_8_2)
            {
                SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                      "ATTR_SCRATCH_UINT8_2 value "
                                      "differs from expected! "
                                      "Expected 0x%02X, Actual 0x%02X",
                                      scratch_8_2_expected,
                                      scratch_8_2
                                     );

                TS_FAIL("applyAtrrTest, "
                        "ATTR_SCRATCH_UINT8_2 value "
                        "differs from expected! "
                        "Expected 0x%02X, Actual 0x%02X",
                        scratch_8_2_expected,
                        scratch_8_2
                     );

                result = false;
                break;
            }


            //ATTR_SCRATCH_UINT32_1
            //===================================================
            if(not l_tank.getAttribute(
                                TARGETING::ATTR_SCRATCH_UINT32_1,
                                TARGETING::TYPE_SYS,
                                TARG_POS,
                                TARG_CHIP_POS,
                                TARG_NODE,
                                &scratch_32_1
                                    ))
            {
                SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                      "getAttribute failed for "
                                      "ATTR_SCRATCH_UINT32_1"
                                     );
                TS_FAIL("getAttribute failed for "
                         "ATTR_SCRATCH_UINT32_1");

                result = false;
                break;
            }

            SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                  "ATTR_SCRATCH_UINT32_1: 0x%08X",
                                   scratch_32_1
                                 );

            if(scratch_32_1_expected != scratch_32_1)
            {
                SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                      "ATTR_SCRATCH_UINT32_1 value "
                                      "differs from expected! "
                                      "Expected 0x%08X, Actual 0x%08X",
                                      scratch_32_1_expected,
                                      scratch_32_1
                                     );

                TS_FAIL("applyAtrrTest, "
                        "ATTR_SCRATCH_UINT32_1 value "
                        "differs from expected! "
                        "Expected 0x%08X, Actual 0x%08X",
                        scratch_32_1_expected,
                        scratch_32_1
                     );

                result = false;
                break;
            }


            //ATTR_SCRATCH_UINT32_2
            //===================================================
            if(not l_tank.getAttribute(
                                TARGETING::ATTR_SCRATCH_UINT32_2,
                                TARGETING::TYPE_SYS,
                                TARG_POS,
                                TARG_CHIP_POS,
                                TARG_NODE,
                                &scratch_32_2
                                    ))
            {
                SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                      "getAttribute failed for "
                                      "ATTR_SCRATCH_UINT32_2"
                                     );
                TS_FAIL("getAttribute failed for "
                         "ATTR_SCRATCH_UINT32_2");

                result = false;
                break;
            }

            SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                  "ATTR_SCRATCH_UINT32_2: 0x%08X",
                                   scratch_32_2
                                 );

            if(scratch_32_2_expected != scratch_32_2)
            {
                SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                      "ATTR_SCRATCH_UINT32_2 value "
                                      "differs from expected! "
                                      "Expected 0x%08X, Actual 0x%08X",
                                      scratch_32_2_expected,
                                      scratch_32_2
                                     );

                TS_FAIL("applyAtrrTest, "
                        "ATTR_SCRATCH_UINT32_2 value "
                        "differs from expected! "
                        "Expected 0x%08X, Actual 0x%08X",
                        scratch_32_2_expected,
                        scratch_32_2
                     );

                result = false;
                break;
            }

            //ATTR_SCRATCH_UINT64_1
            //===================================================
            if(not l_tank.getAttribute(
                                TARGETING::ATTR_SCRATCH_UINT64_1,
                                TARGETING::TYPE_SYS,
                                TARG_POS,
                                TARG_CHIP_POS,
                                TARG_NODE,
                                &scratch_64_1
                                    ))
            {
                SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                      "getAttribute failed for "
                                      "ATTR_SCRATCH_UINT64_1"
                                     );
                TS_FAIL("getAttribute failed for "
                         "ATTR_SCRATCH_UINT64_1");

                result = false;
                break;
            }

            SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                  "ATTR_SCRATCH_UINT64_1: 0x%016llX",
                                   scratch_64_1
                                 );

            if(scratch_64_1_expected != scratch_64_1)
            {
                SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                      "ATTR_SCRATCH_UINT64_1 value "
                                      "differs from expected! "
                                      "Expected 0x%016llX, Actual 0x%016llX",
                                      scratch_64_1_expected,
                                      scratch_64_1
                                     );

                TS_FAIL("applyAtrrTest, "
                        "ATTR_SCRATCH_UINT64_1 value "
                        "differs from expected! "
                        "Expected 0x%016llX, Actual 0x%016llX",
                        scratch_64_1_expected,
                        scratch_64_1
                     );

                result = false;
                break;
            }

            //ATTR_SCRATCH_UINT64_2
            //===================================================
            if(not l_tank.getAttribute(
                                TARGETING::ATTR_SCRATCH_UINT64_2,
                                TARGETING::TYPE_SYS,
                                TARG_POS,
                                TARG_CHIP_POS,
                                TARG_NODE,
                                &scratch_64_2
                                    ))
            {
                SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                      "getAttribute failed for "
                                      "ATTR_SCRATCH_UINT64_2"
                                     );
                TS_FAIL("getAttribute failed for "
                         "ATTR_SCRATCH_UINT64_2");

                result = false;
                break;
            }

            SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                  "ATTR_SCRATCH_UINT64_2: 0x%016llX",
                                   scratch_64_2
                                 );

            if(scratch_64_2_expected != scratch_64_2)
            {
                SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                      "ATTR_SCRATCH_UINT64_2 value "
                                      "differs from expected! "
                                      "Expected 0x%016llX, Actual 0x%016llX",
                                      scratch_64_2_expected,
                                      scratch_64_2
                                     );

                TS_FAIL("applyAtrrTest, "
                        "ATTR_SCRATCH_UINT64_2 value "
                        "differs from expected! "
                        "Expected 0x%016llX, Actual 0x%016llX",
                        scratch_64_2_expected,
                        scratch_64_2
                     );

                result = false;
                break;
            }

            //#############################################
            // Step 11 - Validate Target Override Values
            //#############################################

            TARGETING::Target* l_sys{};
            TARGETING::targetService().getTopLevelTarget(l_sys);

            if(nullptr == l_sys)
            {
                SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                  "Failed to obtain Sys Target."
                                 );

                TS_FAIL("Failed to obtain Sys Target");
                result = false;
                break;
            }

            //ATTR_SCRATCH_UINT8_1
            //===================================================
            if(not l_sys->
                    tryGetAttr<TARGETING::ATTR_SCRATCH_UINT8_1>(scratch_8_1))
            {
                SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                      "tryGetAttr failed for "
                                      "ATTR_SCRATCH_UINT8_1"
                                     );
                TS_FAIL("tryGetAttr failed for "
                         "ATTR_SCRATCH_UINT8_1");

                result = false;
                break;
            }

            SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                  "ATTR_SCRATCH_UINT8_1: 0x%02X",
                                   scratch_8_1
                                 );

            if(scratch_8_1_expected != scratch_8_1)
            {
                SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                      "ATTR_SCRATCH_UINT8_1 value "
                                      "differs from expected! "
                                      "Expected 0x%02X, Actual 0x%02X",
                                      scratch_8_1_expected,
                                      scratch_8_1
                                     );

                TS_FAIL("applyAtrrTest, "
                        "ATTR_SCRATCH_UINT8_1 value "
                        "differs from expected! "
                        "Expected 0x%02X, Actual 0x%02X",
                        scratch_8_1_expected,
                        scratch_8_1
                     );

                result = false;
                break;
            }

            //ATTR_SCRATCH_UINT8_2
            //===================================================
            if(not l_sys->
                    tryGetAttr<TARGETING::ATTR_SCRATCH_UINT8_2>(scratch_8_2))
            {
                SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                      "tryGetAttr failed for "
                                      "ATTR_SCRATCH_UINT8_2"
                                     );
                TS_FAIL("tryGetAttr failed for "
                         "ATTR_SCRATCH_UINT8_2");

                result = false;
                break;
            }

            SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                  "ATTR_SCRATCH_UINT8_2: 0x%02X",
                                   scratch_8_2
                                 );

            if(scratch_8_2_expected != scratch_8_2)
            {
                SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                      "ATTR_SCRATCH_UINT8_2 value "
                                      "differs from expected! "
                                      "Expected 0x%02X, Actual 0x%02X",
                                      scratch_8_2_expected,
                                      scratch_8_2
                                     );

                TS_FAIL("applyAtrrTest, "
                        "ATTR_SCRATCH_UINT8_2 value "
                        "differs from expected! "
                        "Expected 0x%02X, Actual 0x%02X",
                        scratch_8_2_expected,
                        scratch_8_2
                     );

                result = false;
                break;
            }

            //ATTR_SCRATCH_UINT32_1
            //===================================================
            if(not l_sys->
                   tryGetAttr<TARGETING::ATTR_SCRATCH_UINT32_1>(scratch_32_1))
            {
                SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                      "tryGetAttr failed for "
                                      "ATTR_SCRATCH_UINT32_1"
                                     );
                TS_FAIL("tryGetAttr failed for "
                         "ATTR_SCRATCH_UINT32_1");

                result = false;
                break;
            }

            SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                  "ATTR_SCRATCH_UINT32_1: 0x%08X",
                                   scratch_32_1
                                 );

            if(scratch_32_1_expected != scratch_32_1)
            {
                SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                      "ATTR_SCRATCH_UINT32_1 value "
                                      "differs from expected! "
                                      "Expected 0x%08X, Actual 0x%08X",
                                      scratch_32_1_expected,
                                      scratch_32_1
                                     );

                TS_FAIL("applyAtrrTest, "
                        "ATTR_SCRATCH_UINT32_1 value "
                        "differs from expected! "
                        "Expected 0x%08X, Actual 0x%08X",
                        scratch_32_1_expected,
                        scratch_32_1
                     );

                result = false;
                break;
            }

            //ATTR_SCRATCH_UINT32_2
            //===================================================
            if(not l_sys->
                   tryGetAttr<TARGETING::ATTR_SCRATCH_UINT32_2>(scratch_32_2))
            {
                SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                      "tryGetAttr failed for "
                                      "ATTR_SCRATCH_UINT32_2"
                                     );
                TS_FAIL("tryGetAttr failed for "
                         "ATTR_SCRATCH_UINT32_2");

                result = false;
                break;
            }

            SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                  "ATTR_SCRATCH_UINT32_2: 0x%08X",
                                   scratch_32_2
                                 );

            if(scratch_32_2_expected != scratch_32_2)
            {
                SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                      "ATTR_SCRATCH_UINT32_2 value "
                                      "differs from expected! "
                                      "Expected 0x%08X, Actual 0x%08X",
                                      scratch_32_2_expected,
                                      scratch_32_2
                                     );

                TS_FAIL("applyAtrrTest, "
                        "ATTR_SCRATCH_UINT32_2 value "
                        "differs from expected! "
                        "Expected 0x%08X, Actual 0x%08X",
                        scratch_32_2_expected,
                        scratch_32_2
                     );

                result = false;
                break;
            }

            //ATTR_SCRATCH_UINT64_1
            //===================================================
            if(not l_sys->
                   tryGetAttr<TARGETING::ATTR_SCRATCH_UINT64_1>(scratch_64_1))
            {
                SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                      "tryGetAttr failed for "
                                      "ATTR_SCRATCH_UINT64_1"
                                     );
                TS_FAIL("tryGetAttr failed for "
                         "ATTR_SCRATCH_UINT64_1");

                result = false;
                break;
            }

            SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                  "ATTR_SCRATCH_UINT64_1: 0x%016llX",
                                   scratch_64_1
                                 );

            if(scratch_64_1_expected != scratch_64_1)
            {
                SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                      "ATTR_SCRATCH_UINT64_1 value "
                                      "differs from expected! "
                                      "Expected 0x%016llX, Actual 0x%016llX",
                                      scratch_64_1_expected,
                                      scratch_64_1
                                     );

                TS_FAIL("applyAtrrTest, "
                        "ATTR_SCRATCH_UINT64_1 value "
                        "differs from expected! "
                        "Expected 0x%016llX, Actual 0x%016llX",
                        scratch_64_1_expected,
                        scratch_64_1
                     );

                result = false;
                break;
            }

            //ATTR_SCRATCH_UINT64_2
            //===================================================
            if(not l_sys->
                   tryGetAttr<TARGETING::ATTR_SCRATCH_UINT64_2>(scratch_64_2))
            {
                SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                      "tryGetAttr failed for "
                                      "ATTR_SCRATCH_UINT64_2"
                                     );
                TS_FAIL("tryGetAttr failed for "
                         "ATTR_SCRATCH_UINT64_2");

                result = false;
                break;
            }

            SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                  "ATTR_SCRATCH_UINT64_2: 0x%016llX",
                                   scratch_64_2
                                 );

            if(scratch_64_2_expected != scratch_64_2)
            {
                SBE_PASSTHROUGH_TRACF("applyAtrrTest, "
                                      "ATTR_SCRATCH_UINT64_2 value "
                                      "differs from expected! "
                                      "Expected 0x%016llX, Actual 0x%016llX",
                                      scratch_64_2_expected,
                                      scratch_64_2
                                     );

                TS_FAIL("applyAtrrTest, "
                        "ATTR_SCRATCH_UINT64_2 value "
                        "differs from expected! "
                        "Expected 0x%016llX, Actual 0x%016llX",
                        scratch_64_2_expected,
                        scratch_64_2
                     );

                result = false;
                break;
            }

            printAttributes("Attributes After SBE Passthrough:");

            if(not controlRegisterCleared)
            {
                result = false;
                break;
            }
        }
        while(0);

        clearControlRegister(l_proc);

        if(result)
        {
            SBE_PASSTHROUGH_TRACF("applyAtrrTest passed!");
        }
        else
        {
            SBE_PASSTHROUGH_TRACF("applyAtrrTest failed!");
        }
    }

private:

    uint32_t iv_seqNumber{0};

    //-----------------------------------------------------------
    ClearToSend ensureClearToSend(TARGETING::TargetHandle_t i_proc)
    {
        using namespace INITSERVICE::SPLESS;

        ClearToSend retval{ClearToSend::OK};

        do
        {
            if(not i_proc)
            {
                SBE_PASSTHROUGH_TRACF("ensureClearToSend, "
                                      "i_proc is NULL!"
                                     );

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
                       DEVICE_SCOM_ADDRESS(MboxScratch4_t::REG_ADDR)
                      );

            if(nullptr != errl)
            {
                delete errl;
                errl = nullptr;

                SBE_PASSTHROUGH_TRACF("ensureClearToSend, "
                                      "Failed to read scom register."
                                     );
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
                SBE_PASSTHROUGH_TRACF("ensureClearToSend, "
                                      "i_proc is NULL!"
                                     );

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
                       DEVICE_SCOM_ADDRESS(MboxScratch4_t::REG_ADDR)
                      );

            if(nullptr != errl)
            {
                delete errl;
                errl = nullptr;

                SBE_PASSTHROUGH_TRACF("ensureClearToSend, "
                                      "Failed to read scom register."
                                     );
                TS_FAIL("Failed to read scom register.");

                retval = false;
                break;
            }

            l_register.sbeMsgProc.sbeMsgProcessingComplete = false;
            l_register.sbeMsgProc.sbeMsgProcessingInProgress = false;

            errl = deviceWrite(i_proc,
                               &l_register.data32,
                               l_size,
                               DEVICE_SCOM_ADDRESS(MboxScratch4_t::REG_ADDR)
                              );

           if(nullptr != errl)
            {
                delete errl;
                errl = nullptr;

                SBE_PASSTHROUGH_TRACF("ensureClearToSend, "
                                      "Failed to write to scom register."
                                     );
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
                          prefix
                          );
            CHECK_PRTF_RESULT(rc, remaining, ptr);

            rc = snprintf(ptr,
                          static_cast<size_t>(remaining),
                          "\tsbeHdr.version: 0x%08X\n",
                           msg.sbeHdr.version
                          );
            CHECK_PRTF_RESULT(rc, remaining, ptr);

            rc = snprintf(ptr,
                          static_cast<size_t>(remaining),
                          "\tsbeHdr.msgSize: 0x%08X\n",
                           msg.sbeHdr.msgSize
                          );
            CHECK_PRTF_RESULT(rc, remaining, ptr);

            rc = snprintf(ptr,
                          static_cast<size_t>(remaining),
                          "\tsbeHdr.seqId 0x%08X\n",
                          msg.sbeHdr.seqId
                          );
            CHECK_PRTF_RESULT(rc, remaining, ptr);

            rc = snprintf(ptr,
                          static_cast<size_t>(remaining),
                          "\tcmdHdr.version 0x%08X\n",
                          msg.cmdHdr.version
                          );
            CHECK_PRTF_RESULT(rc, remaining, ptr);

            rc = snprintf(ptr,
                          static_cast<size_t>(remaining),
                          "\tcmdHdr.status  0x%08X\n",
                          msg.cmdHdr.status
                          );
            CHECK_PRTF_RESULT(rc, remaining, ptr);

            rc = snprintf(ptr,
                          static_cast<size_t>(remaining),
                          "\tcmdHdr.dataOffset 0x%08X\n",
                          msg.cmdHdr.dataOffset
                          );
            CHECK_PRTF_RESULT(rc, remaining, ptr);

            rc = snprintf(ptr,
                          static_cast<size_t>(remaining),
                          "\tcmdHdr.dataSize 0x%08X\n",
                          msg.cmdHdr.dataSize
                          );
            CHECK_PRTF_RESULT(rc, remaining, ptr);

            rc = snprintf(ptr,
                          static_cast<size_t>(remaining),
                          "\tcmdHdr.command  0x%08X\n",
                          msg.cmdHdr.command
                          );
            CHECK_PRTF_RESULT(rc, remaining, ptr);
        }
        while(0);
    }


    //---------------------------------------------------------------
    void printAttributes(const char* prefix)
    {
        uint8_t scratch_8_1{};
        uint8_t scratch_8_2{};
        uint32_t scratch_32_1{};
        uint32_t scratch_32_2{};
        uint64_t scratch_64_1{};
        uint64_t scratch_64_2{};

        TARGETING::Target* l_sys{};
        TARGETING::targetService().getTopLevelTarget(l_sys);

        if(nullptr == l_sys)
        {
            return;
        }

        SBE_PASSTHROUGH_TRACF("%s", prefix);

        //ATTR_SCRATCH_UINT8_1
        //===================================================
        if(l_sys->tryGetAttr<TARGETING::ATTR_SCRATCH_UINT8_1>(scratch_8_1))
        {
            SBE_PASSTHROUGH_TRACF(
                               "\t\tATTR_SCRATCH_UINT8_1: 0x%02X",
                               scratch_8_1
                             );
        }

        //ATTR_SCRATCH_UINT8_2
        //===================================================
        if(l_sys->tryGetAttr<TARGETING::ATTR_SCRATCH_UINT8_2>(scratch_8_2))
        {
             SBE_PASSTHROUGH_TRACF(
                              "\t\tATTR_SCRATCH_UINT8_2: 0x%02X",
                               scratch_8_2
                             );
        }

        //ATTR_SCRATCH_UINT32_1
        //===================================================
        if(l_sys->tryGetAttr<TARGETING::ATTR_SCRATCH_UINT32_1>(scratch_32_1))
        {
            SBE_PASSTHROUGH_TRACF(
                              "\t\tATTR_SCRATCH_UINT32_1: 0x%08X",
                               scratch_32_1
                             );
        }

        //ATTR_SCRATCH_UINT32_2
        //===================================================
        if(l_sys->tryGetAttr<TARGETING::ATTR_SCRATCH_UINT32_2>(scratch_32_2))
        {
            SBE_PASSTHROUGH_TRACF(
                              "\t\tATTR_SCRATCH_UINT32_2: 0x%08X",
                               scratch_32_2
                             );
        }

        //ATTR_SCRATCH_UINT64_1
        //===================================================
        if(l_sys->tryGetAttr<TARGETING::ATTR_SCRATCH_UINT64_1>(scratch_64_1))
        {
            SBE_PASSTHROUGH_TRACF(
                              "\t\tATTR_SCRATCH_UINT64_1: 0x%016llX",
                               scratch_64_1
                             );
        }

        //ATTR_SCRATCH_UINT64_2
        //===================================================
        if(l_sys->tryGetAttr<TARGETING::ATTR_SCRATCH_UINT64_2>(scratch_64_2))
        {
            SBE_PASSTHROUGH_TRACF(
                              "\t\tATTR_SCRATCH_UINT64_2: 0x%016llX",
                               scratch_64_2
                             );
        }

    }
};



#endif
