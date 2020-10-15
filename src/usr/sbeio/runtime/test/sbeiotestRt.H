/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/runtime/test/sbeiotestRt.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2020                        */
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
#ifndef __TEST_SBEIOTESTRT_H
#define __TEST_SBEIOTESTRT_H

/**
 * @file SbeiotestRt.H
 *
 * @brief Unit test for runtime process SBE messages.
 */

#include <cxxtest/TestSuite.H>
#include <runtime/interface.h>
#include <sbeio/runtime/sbe_msg_passing.H>
#include <sbeio/sbeioreasoncodes.H>
#include <targeting/translateTarget.H>
#include <targeting/common/attributes.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/hbrt_target.H>
#include <errl/errlmanager.H>
#include <devicefw/userif.H>
#include <initservice/mboxRegs.H>

//trace
extern trace_desc_t* g_trac_sbeio;

using namespace TARGETING;
using namespace SBE_MSG;
using namespace CxxTest;



/**
 * @brief SbeMessagePassingRtTest Unit test for runtime SBE message passing.
 */
class SbeMessagePassingRtTest : public CxxTest::TestSuite
{
    public:
        uint32_t iv_seqId = 0;


/* Helper Functions */

        /**
         * @brief initSbeMessagePassing.
         *
         * @param[out] o_request      Pass-through command request
         * @param[out] o_expected_response  Expected pass-through cmd response
         * @param[out] o_chipId       Processor target chip ID
         * @param[out] o_sbeCommAddr  Address of SBE Communication buffer
         * @param[out] o_rt_intf      Pointer to runtime interfaces
         *
         * @return Return Code    O if Successful, otherwise not 0.
         */
        int initSbeMessagePassing(sbeMessage_t& o_request,
                                  sbeMessage_t& o_expected_response,
                                  TARGETING::rtChipId_t& o_chipId,
                                  uint64_t& o_sbeCommAddr,
                                  runtimeInterfaces_t **o_rt_intf)
        {
            // Test init entry
            TRACDCOMP(g_trac_sbeio, ENTER_MRK "SbeMessagePassingRtTest::"
                                    "initSbeMessagePassing");

            int rc = 0;

            const uint32_t l_req_dataSize = 0x00000001;
            o_request.sbeHdr.version = SBEHDRVER_LATEST;
            o_request.sbeHdr.msgSize =
                sizeof(sbeHeader_t) + sizeof(cmdHeader_t) + l_req_dataSize;
            o_request.sbeHdr.seqId = ++iv_seqId;
            o_request.cmdHdr.version = CMDHDRVER_LATEST;
            o_request.cmdHdr.status = 0; // Gets used as test option
            o_request.cmdHdr.dataOffset =
                reinterpret_cast<uint64_t>(&(o_request.data))
                - reinterpret_cast<uint64_t>(&(o_request.cmdHdr));
            o_request.cmdHdr.dataSize = l_req_dataSize;
            o_request.cmdHdr.command = PASSTHRU_HTMGT_GENERIC;
            o_request.data[0] = 0x01; // Get OCC State


            const uint32_t l_rsp_dataSize = 0x00000001;
            o_expected_response.sbeHdr.version = o_request.sbeHdr.version;
            o_expected_response.sbeHdr.msgSize =
                sizeof(sbeHeader_t) + sizeof(cmdHeader_t) + l_rsp_dataSize;
            o_expected_response.sbeHdr.seqId = o_request.sbeHdr.seqId;
            o_expected_response.cmdHdr.version = o_request.cmdHdr.version;
            o_expected_response.cmdHdr.status = 0;
            o_expected_response.cmdHdr.dataOffset =
                reinterpret_cast<uint64_t>(&(o_expected_response.data))
                - reinterpret_cast<uint64_t>(&(o_expected_response.cmdHdr));
            o_expected_response.cmdHdr.dataSize = l_rsp_dataSize;
            o_expected_response.cmdHdr.command = o_request.cmdHdr.command;
            o_expected_response.data[0] = 0x03; // Active

            do
            {
                TargetHandleList procList;
                getAllChips( procList, TYPE_PROC, true );

                // Get the first functional proc
                if(0 == procList.size())
                {
                    rc = -1;
                    TS_FAIL("Not able to get Functional proc");
                    break;
                }
                TargetHandle_t proc = procList[0];

                // Get the chip ID for the proc
                o_chipId = 0;
                errlHndl_t err = TARGETING::getRtTarget(proc, o_chipId);
                if(nullptr != err)
                {
                    rc = -1;
                    TS_FAIL("getRtTarget() failed for 0x%08X",
                             get_huid(proc));
                    errlCommit(err, SBEIO_COMP_ID);
                    break;
                }

                // Get the address of the SBE Communication area
                o_sbeCommAddr = proc->getAttr<TARGETING::ATTR_SBE_COMM_ADDR>();
                if(NULL == o_sbeCommAddr)
                {
                    TS_INFO("SBE Communication area not available from "
                            "SBE_COMM_ADDR attribute");
                    uint64_t l_instance = proc->getAttr<ATTR_POSITION>();
                    o_sbeCommAddr = g_hostInterfaces->get_reserved_mem(
                                    HBRT_RSVD_MEM__SBE_COMM,
                                    l_instance);
                    if(NULL == o_sbeCommAddr)
                    {
                        rc = -1;
                        TS_FAIL("Not able to get SBE Communication area");
                        break;
                    }
                }

                // Get the runtime interface object
                *o_rt_intf = getRuntimeInterfaces();
                if(nullptr == *o_rt_intf)
                {
                    rc = -1;
                    TS_FAIL("Not able to get run time interface object");
                    break;
                }
            }while (0);

            // Test init exit
            TRACDCOMP(g_trac_sbeio, EXIT_MRK "SbeMessagePassingRtTest::"
                                    "initSbeMessagePassing");

            return rc;
        }

        /**
         * @brief Function to process Generic HTMGT Message pass-through command
         *
         * @param[in]  i_procTgt      HB processor target
         * @param[in]  i_reqDataSize  Pass-through command request data size
         * @param[in]  i_reqData      Pass-through command request data
         * @param[out] o_rspStatus    Pass-through command response status
         * @param[out] o_rspDataSize  Pass-through command response data size
         * @param[out] o_rspData      Pass-through command response data
         *
         * @return errlHndl_t    Error log handle on failure.
         */
        static
        errlHndl_t processGenericHtmgt(TARGETING::TargetHandle_t i_procTgt,
                                       uint32_t i_reqDataSize,
                                       uint8_t  *i_reqData,
                                       uint32_t *o_rspStatus,
                                       uint32_t *o_rspDataSize,
                                       uint8_t  *o_rspData)
        {
            errlHndl_t l_errl = nullptr;

            // Get pointers to full request and response buffers
            sbeMessage_t *l_request =
                reinterpret_cast<sbeMessage_t*>(i_reqData - sizeof(sbeHeader_t)
                                                - sizeof(cmdHeader_t));
            sbeMessage_t *l_response =
                reinterpret_cast<sbeMessage_t*>(o_rspData - sizeof(sbeHeader_t)
                                                - sizeof(cmdHeader_t));

            // Get status field from request and use as a test option
            uint32_t l_testOption = l_request->cmdHdr.status;
            if(l_testOption)
            {
                TRACDCOMP(g_trac_sbeio,
                          "processGenericHtmgt: l_testOption %d",
                          l_testOption);

                TRACDBIN( g_trac_sbeio,
                          "processGenericHtmgt: request",
                          l_request,
                          l_request->sbeHdr.msgSize);
            }

            // Set default returns
            *o_rspStatus = 0;
            *o_rspDataSize = 1;
            o_rspData[0] = 0x03;

            // Do special processing based on test option supplied
            switch(l_testOption)
            {
                // Return with excess response data size
                case 1:
                    *o_rspDataSize = SBE_MSG_SIZE;
                    break;

                 // Return with an error log
                case 2:
                    l_errl = new
                        ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            SBEIO::SBEIO_RUNTIME,
                                            SBEIO::SBEIO_INVALID_REASONCODE,
                                            0,
                                            0);
                    break;

                // Return with generic failure status
                case 3:
                    *o_rspStatus = 0xFE;
                    break;

                // Return with altered SBE Header version
                case 4:
                    l_response->sbeHdr.version = 0x11110000;
                    break;

                 // Return with altered SBE Header sequence ID
                case 5:
                    l_response->sbeHdr.seqId += 1;
                    break;

                 // Return with altered Command Header version
                case 6:
                    l_response->cmdHdr.version += 1;
                    break;

                 // Return with altered Command Header command
                case 7:
                    l_response->cmdHdr.command = PASSTHRU_HTMGT_GET_PSTATE;
                    break;

              // Normal processing
                case 0:
                default:
                    // Just use default returns
                    break;
            }

            if(l_testOption)
            {
                TRACDCOMP(g_trac_sbeio,
                          "processGenericHtmgt: response %p",
                          l_response);

                TRACDBIN( g_trac_sbeio,
                          "processGenericHtmgt: response",
                          l_response,
                          l_response->sbeHdr.msgSize);
            }

            return l_errl;
        }

        /**
         * @brief checkResetSbeMessagePassingCFAM.
         *
         * @param[in]  i_procChipId   Processor target chip ID
         * @param[in]  i_state        Mask to check CFAM register against
         *
         * @return Return Code    0 if Successful, otherwise not 0.
         */
        int checkResetSbeMessagePassingCFAM(TARGETING::rtChipId_t i_procChipId,
                                            const sbe_msg_processing_state_t i_state)
        {
            using namespace INITSERVICE::SPLESS;

            // Test check / reset CFAM entry
            TRACDCOMP(g_trac_sbeio, ENTER_MRK "SbeMessagePassingRtTest::"
                                    "checkResetSbeMessagePassingCFAM");

            int rc = 0;
            errlHndl_t errl = nullptr;

            TARGETING::Target *l_proc;

            MboxScratch4_t l_read_reg { };
            size_t l_size = sizeof(uint64_t);

            do{
                // Get TARGETING::Target for runtime chip_id (target)
                errl = RT_TARG::getHbTarget(i_procChipId,
                                            l_proc);

                if(errl)
                {
                    TS_FAIL("Not able to get TARGETING::Target for runtime "
                            "chip_id 0x%08X", i_procChipId);

                    break;
                }

                // Read mailbox scratch reg 4 for target proc
                errl = deviceRead(l_proc,
                                  &l_read_reg.data32,
                                  l_size,
                                  DEVICE_SCOM_ADDRESS(MboxScratch4_t::REG_ADDR));

                if(errl)
                {
                    TS_FAIL("Not able to read Mailbox Scratch Register 4");

                    break;
                }

                const bool l_wantComplete = i_state & SBE_MSG_COMPLETE;
                const bool l_wantInProgress = i_state & SBE_MSG_IN_PROGRESS;

                // Check CFAM register
                if (l_read_reg.sbeMsgProc.sbeMsgProcessingComplete != l_wantComplete
                    || l_read_reg.sbeMsgProc.sbeMsgProcessingInProgress != l_wantInProgress)
                {
                    TS_FAIL("Mailbox Scratch Register 4 set incorrectly, expected "
                            "%d,%d but read %d,%d",
                            l_wantComplete, l_wantInProgress,
                            l_read_reg.sbeMsgProc.sbeMsgProcessingComplete,
                            l_read_reg.sbeMsgProc.sbeMsgProcessingInProgress);
                    rc = 1;
                    break;
                }

                // Clear mask bit(s) in mbox scratch reg 4
                l_read_reg.sbeMsgProc.sbeMsgProcessingComplete = false;
                l_read_reg.sbeMsgProc.sbeMsgProcessingInProgress = false;

                // Write SCOM_ADDR_5003B for target proc
                errl = deviceWrite(l_proc,
                                   &l_read_reg,
                                   l_size,
                                   DEVICE_SCOM_ADDRESS(MboxScratch4_t::REG_ADDR));

                if(errl)
                {
                    TS_FAIL("Not able to write Mailbox Scratch Register 4");

                    break;
                }
            }while(0);

            // Test check / reset CFAM exit
            TRACDCOMP(g_trac_sbeio, EXIT_MRK "SbeMessagePassingRtTest::"
                                    "checkResetSbeMessagePassingCFAM");

            return rc;
        }

        /**
         * @brief sbeOrCmdHeaderDiffer
         * Check if the SBE-header or Command-header of two SBE Messages differ.
         *
         * @param[in]  msg_1   SBE Message 1
         * @param[in]  msg_2   SBE Message 2
         *
         * @return bool    True if difference is found, False otherwise
         */
        inline bool sbeOrCmdHeaderDiffer(const sbeMessage_t* msg_1, const sbeMessage_t* msg_2)
        {
            return msg_1->sbeHdr.version    != msg_2->sbeHdr.version    || // SBE header check
                   msg_1->sbeHdr.msgSize    != msg_2->sbeHdr.msgSize    ||
                   msg_1->sbeHdr.seqId      != msg_2->sbeHdr.seqId      ||
                   msg_1->cmdHdr.version    != msg_2->cmdHdr.version    || // Command header check
                   msg_1->cmdHdr.command    != msg_2->cmdHdr.command    ||
                   msg_1->cmdHdr.dataOffset != msg_2->cmdHdr.dataOffset ||
                   msg_1->cmdHdr.dataSize   != msg_2->cmdHdr.dataSize   ||
                   msg_1->cmdHdr.status     != msg_2->cmdHdr.status;
        }

        /**
         * @brief defaultMsgPath_SbeOrCmdHeaderDiffer
         * Check if the SBE-header or Command-header of two SBE Messages differ.
         *
         * This function should only be used in test cases that do no overwrite the SBE command
         * function to use, i.e they use the default message path (e.g. testSbeMessagePassingDefaultPath
         * test case) and the SBE message request is to get the OCC Status (as set in initSbeMessagePassing)
         *
         * Note: dataSize is use to set msgSize (see rt_sbeio.C process_sbe_msg_cmd_processor(...))
         * and dataSize is set dynamically (see htmgt_occmanager.C OccManager::_getHtmgtData(...)).
         * Because of this, msgSize and dataSize will not stay equal to the expMsg's values that are
         * hard-coded for the tests. However, given the current data structures use to fill in the
         * SBE Message, msgSize and dataSize must be divisible by 16 (bytes).
         *
         * @param[in]  actMsg   Actual SBE Message from default message path
         * @param[in]  expMsg   Expected SBE Message
         *
         * @return bool    True if difference is found, False otherwise
         */
        inline bool defaultMsgPath_SbeOrCmdHeaderDiffer(const sbeMessage_t* actMsg,
                                                        const sbeMessage_t* expMsg)
        {
            return actMsg->sbeHdr.version       != expMsg->sbeHdr.version    || // SBE header check
                   actMsg->sbeHdr.msgSize % 16  !=  0                        ||
                   actMsg->sbeHdr.seqId         != expMsg->sbeHdr.seqId      ||
                   actMsg->cmdHdr.version       != expMsg->cmdHdr.version    || // Command header check
                   actMsg->cmdHdr.command       != expMsg->cmdHdr.command    ||
                   actMsg->cmdHdr.dataOffset    != expMsg->cmdHdr.dataOffset ||
                   actMsg->cmdHdr.dataSize % 16 != 0                         ||
                   actMsg->cmdHdr.status        != expMsg->cmdHdr.status;
        }

/* End of Helper Functions */


/* Test Functions */

        /**
         * @brief testSbeMessagePassing Unit test for the
         *              SBE message passing versions.
         */
        void testSbeMessagePassingVersions(void)
        {
            // Test entry
            TRACFCOMP(g_trac_sbeio, ENTER_MRK "SbeMessagePassingRtTest::"
                                    "testSbeMessagePassingVersions");
            sbeMessage_t l_request;
            sbeMessage_t l_expected_response;
            TARGETING::rtChipId_t chipId = 0;
            uint64_t l_sbeCommAddr = 0;
            runtimeInterfaces_t *rt_intf = nullptr;

            int rc = 0;

            do
            {
                // Do initializations for SBE Message passing
                rc = initSbeMessagePassing(l_request,
                                           l_expected_response,
                                           chipId,
                                           l_sbeCommAddr,
                                           &rt_intf);

                // Change SBE Header version
                l_request.sbeHdr.version += 1;

                // Copy test request into SBE Communication area
                memcpy(reinterpret_cast<void*>(l_sbeCommAddr),
                       reinterpret_cast<void*>(&l_request),
                       l_request.sbeHdr.msgSize);

                // Call the SBE message passing code
                rc = rt_intf->sbe_message_passing(chipId);
                if(0x2833 != rc)
                {
                    TS_FAIL("Unexpected return during RT SBE message passing. "
                            "Testing SBE Header version for chipID: 0x%08X",
                            chipId);
                    break;
                }

                // Check setting of bits in CFAM register
                rc = checkResetSbeMessagePassingCFAM(chipId,
                                                     SBE_MSG_IN_PROGRESS);
                if(0 != rc)
                {
                    TS_FAIL("Unexpected error during RT SBE message passing. "
                            "chipID: 0x%08X, rc: 0x%08x, but expected 0 for "
                            "CFAM register checking",
                            chipId, rc);
                    break;
                }

                // Restore SBE Header version
                l_request.sbeHdr.version = SBEHDRVER_LATEST;

                // Increment Total Tests
                g_TotalTests++;

                // Change CMD Header version
                l_request.cmdHdr.version -= 1;

                // Copy test request into SBE Communication area
                memcpy(reinterpret_cast<void*>(l_sbeCommAddr),
                       reinterpret_cast<void*>(&l_request),
                       l_request.sbeHdr.msgSize);

                // Call the SBE message passing code
                rc = rt_intf->sbe_message_passing(chipId);
                if(0x2833 != rc)
                {
                    TS_FAIL("Unexpected return during RT SBE message passing. "
                            "Testing Command Header version for chipID: 0x%08X",
                            chipId);
                    break;
                }

                // Check setting of bits in CFAM register
                rc = checkResetSbeMessagePassingCFAM(chipId,
                                                     SBE_MSG_IN_PROGRESS);
                if(0 != rc)
                {
                    TS_FAIL("Unexpected error during RT SBE message passing. "
                            "chipID: 0x%08X, rc: 0x%08x, but expected 0 for "
                            "CFAM register checking",
                            chipId, rc);
                    break;
                }
            }while (0);

            // Test exit
            TRACFCOMP(g_trac_sbeio, EXIT_MRK "SbeMessagePassingRtTest::"
                                    "testSbeMessagePassingVersions");
        }

        /**
         * @brief testSbeMessagePassing Unit test for the
         *              SBE message passing message size.
         */
        void testSbeMessagePassingMsgSize(void)
        {
            // Test entry
            TRACFCOMP(g_trac_sbeio, ENTER_MRK "SbeMessagePassingRtTest::"
                                    "testSbeMessagePassingMsgSize");

            sbeMessage_t l_request;
            sbeMessage_t l_expected_response;
            TARGETING::rtChipId_t chipId = 0;
            uint64_t l_sbeCommAddr = 0;
            runtimeInterfaces_t *rt_intf = nullptr;

            int rc = 0;

            do
            {
                // Do initializations for SBE Message passing
                rc = initSbeMessagePassing(l_request,
                                           l_expected_response,
                                           chipId,
                                           l_sbeCommAddr,
                                           &rt_intf);

                // Save size of message to copy
                uint32_t l_sbeMsgSize = l_request.sbeHdr.msgSize;

                // Change SBE Header message size
                l_request.sbeHdr.msgSize = SBE_MSG_SIZE + 128;

                // Copy test request into SBE Communication area
                memcpy(reinterpret_cast<void*>(l_sbeCommAddr),
                       reinterpret_cast<void*>(&l_request),
                       l_sbeMsgSize);

                // Call the SBE message passing code
                rc = rt_intf->sbe_message_passing(chipId);
                if(0x2834 != rc)
                {
                    TS_FAIL("Unexpected return during RT SBE message passing. "
                            "Testing message size too large for chipID: 0x%08X",
                            chipId);
                    break;
                }

                // Check setting of bits in CFAM register
                rc = checkResetSbeMessagePassingCFAM(chipId,
                                                     SBE_MSG_IN_PROGRESS);
                if(0 != rc)
                {
                    TS_FAIL("Unexpected error during RT SBE message passing. "
                            "chipID: 0x%08X, rc: 0x%08x, but expected 0 for "
                            "CFAM register checking",
                            chipId, rc);
                    break;
                }
            }while (0);

            // Test exit
            TRACFCOMP(g_trac_sbeio, EXIT_MRK "SbeMessagePassingRtTest::"
                                    "testSbeMessagePassingMsgSize");
        }

        /**
         * @brief testSbeMessagePassing Unit test for the
         *              SBE message passing data offset.
         */
        void testSbeMessagePassingDataOffset(void)
        {
            // Test entry
            TRACFCOMP(g_trac_sbeio, ENTER_MRK "SbeMessagePassingRtTest::"
                                    "testSbeMessagePassingDataOffset");

            sbeMessage_t l_request;
            sbeMessage_t l_expected_response;
            TARGETING::rtChipId_t chipId = 0;
            uint64_t l_sbeCommAddr = 0;
            runtimeInterfaces_t *rt_intf = nullptr;

            int rc = 0;

            do
            {
                // Do initializations for SBE Message passing
                rc = initSbeMessagePassing(l_request,
                                           l_expected_response,
                                           chipId,
                                           l_sbeCommAddr,
                                           &rt_intf);

                // Change Command Header data offset to be too small
                l_request.cmdHdr.dataOffset = sizeof(cmdHeader_t) -
                    sizeof(l_request.cmdHdr.status);

                // Copy test request into SBE Communication area
                memcpy(reinterpret_cast<void*>(l_sbeCommAddr),
                       reinterpret_cast<void*>(&l_request),
                       l_request.sbeHdr.msgSize);

                // Call the SBE message passing code
                rc = rt_intf->sbe_message_passing(chipId);
                if(0x2835 != rc)
                {
                    TS_FAIL("Unexpected return during RT SBE message passing. "
                            "Testing data offset too small for chipID: 0x%08X",
                            chipId);
                    break;
                }

                // Check setting of bits in CFAM register
                rc = checkResetSbeMessagePassingCFAM(chipId,
                                                     SBE_MSG_IN_PROGRESS);
                if(0 != rc)
                {
                    TS_FAIL("Unexpected error during RT SBE message passing. "
                            "chipID: 0x%08X, rc: 0x%08x, but expected 0 for "
                            "CFAM register checking",
                            chipId, rc);
                    break;
                }

                // Increment Total Tests
                g_TotalTests++;

                // Change Command Header data offset to be too large
                l_request.cmdHdr.dataOffset = sizeof(cmdHeader_t) + 1;

                // Copy test request into SBE Communication area
                memcpy(reinterpret_cast<void*>(l_sbeCommAddr),
                       reinterpret_cast<void*>(&l_request),
                       l_request.sbeHdr.msgSize);

                // Call the SBE message passing code
                rc = rt_intf->sbe_message_passing(chipId);
                if(0x2836 != rc)
                {
                    TS_FAIL("Unexpected return during RT SBE message passing. "
                            "Testing data offset too large for chipID: 0x%08X,",
                            chipId);
                    break;
                }

                // Check setting of bits in CFAM register
                rc = checkResetSbeMessagePassingCFAM(chipId,
                                                     SBE_MSG_IN_PROGRESS);
                if(0 != rc)
                {
                    TS_FAIL("Unexpected error during RT SBE message passing. "
                            "chipID: 0x%08X, rc: 0x%08x, but expected 0 for "
                            "CFAM register checking",
                            chipId, rc);
                    break;
                }

                // Restore Command Header data offset
                l_request.cmdHdr.dataOffset = sizeof(cmdHeader_t);

                // Increment Total Tests
                g_TotalTests++;

                // Change Command Header data size
                l_request.cmdHdr.dataSize += 1;

                // Copy test request into SBE Communication area
                memcpy(reinterpret_cast<void*>(l_sbeCommAddr),
                       reinterpret_cast<void*>(&l_request),
                       l_request.sbeHdr.msgSize);

                // Call the SBE message passing code
                rc = rt_intf->sbe_message_passing(chipId);
                if(0x2836 != rc)
                {
                    TS_FAIL("Unexpected return during RT SBE message passing. "
                            "Testing data size too large for chipID: 0x%08X",
                            chipId);
                    break;
                }

                // Check setting of bits in CFAM register
                rc = checkResetSbeMessagePassingCFAM(chipId,
                                                     SBE_MSG_IN_PROGRESS);
                if(0 != rc)
                {
                    TS_FAIL("Unexpected error during RT SBE message passing. "
                            "chipID: 0x%08X, rc: 0x%08x, but expected 0 for "
                            "CFAM register checking",
                            chipId, rc);
                    break;
                }

                // Restore Command Header data size
                l_request.cmdHdr.dataSize -= 1;

                // Increment Total Tests
                g_TotalTests++;

                // Save size of message to copy
                uint32_t l_sbeMsgSize = l_request.sbeHdr.msgSize;

                // Change SBE Header message size
                l_request.sbeHdr.msgSize -= 1;

                // Copy test request into SBE Communication area
                memcpy(reinterpret_cast<void*>(l_sbeCommAddr),
                       reinterpret_cast<void*>(&l_request),
                       l_sbeMsgSize);

                // Call the SBE message passing code
                rc = rt_intf->sbe_message_passing(chipId);
                if(0x2836 != rc)
                {
                    TS_FAIL("Unexpected return during RT SBE message passing. "
                            "chipID: 0x%08X, rc: 0x%08x, but expected "
                            "-104 (0xFF98) SBEIO_RT_DATA_TOO_LARGE",
                            chipId, rc);
                    break;
                }

                // Check setting of bits in CFAM register
                rc = checkResetSbeMessagePassingCFAM(chipId,
                                                     SBE_MSG_IN_PROGRESS);
                if(0 != rc)
                {
                    TS_FAIL("Unexpected error during RT SBE message passing. "
                            "Testing message size too small / data size too "
                            "large for chipID",
                            chipId);
                    break;
                }
            }while (0);

            // Test exit
            TRACFCOMP(g_trac_sbeio, EXIT_MRK "SbeMessagePassingRtTest::"
                                    "testSbeMessagePassingDataOffset");
        }

        /**
         * @brief testSbeMessagePassing Unit test for the
         *              SBE message passing default path.
         */
        void testSbeMessagePassingDefaultPath(void)
        {
            // Test entry
            TRACFCOMP(g_trac_sbeio, ENTER_MRK "SbeMessagePassingRtTest::"
                                    "testSbeMessagePassingDefaultPath");
#ifdef CONFIG_HTMGT

            sbeMessage_t l_request;
            sbeMessage_t l_expected_response;
            TARGETING::rtChipId_t chipId = 0;
            uint64_t l_sbeCommAddr = 0;
            runtimeInterfaces_t *rt_intf = nullptr;

            int rc = 0;

            do
            {
                // Do initializations for SBE Message passing
                rc = initSbeMessagePassing(l_request,
                                           l_expected_response,
                                           chipId,
                                           l_sbeCommAddr,
                                           &rt_intf);

                // Get the response address in the SBE Communication area
                sbeMessage_t *l_sbeCommAddr_rsp =
                    reinterpret_cast<sbeMessage_t*>(l_sbeCommAddr);

                // Copy test request into SBE Communication area
                memcpy(reinterpret_cast<void*>(l_sbeCommAddr),
                       reinterpret_cast<void*>(&l_request),
                       l_request.sbeHdr.msgSize);

                // Call the SBE message passing code
                TRACFCOMP(g_trac_sbeio, "SbeMessagePassingRtTest::"
                                    "testSbeMessagePassingDefaultPath "
                                    "calling sbe_message_passing");
                rc = rt_intf->sbe_message_passing(chipId);
                if(0 != rc)
                {
                    TS_FAIL("Unexpected return during RT SBE message passing. "
                            "Testing default path for chipID: 0x%08X, rc: "
                            "0x%08x, but expected 0",
                            chipId, rc);
                    break;
                }

                // Compare test response from SBE Communication area
                if(defaultMsgPath_SbeOrCmdHeaderDiffer(l_sbeCommAddr_rsp, &l_expected_response))
                {
                    TRACFBIN( g_trac_sbeio,
                              "testSbeMessagePassingDefaultPath: expected rsp",
                              &l_expected_response,
                              l_expected_response.sbeHdr.msgSize);
                    TRACFBIN( g_trac_sbeio,
                              "testSbeMessagePassingDefaultPath: actual rsp",
                              l_sbeCommAddr_rsp,
                              l_sbeCommAddr_rsp->sbeHdr.msgSize);
                    TS_FAIL("Unexpected response from RT SBE message passing. "
                            "Testing default path for chipID: 0x%08X",
                            chipId);
                    break;
                }

                // Check setting of bits in CFAM register, SBE message passing should be marked
                // completed as default path finished with no errors
                rc = checkResetSbeMessagePassingCFAM(chipId, SBE_MSG_COMPLETE);
                if(0 != rc)
                {
                    TS_FAIL("Unexpected error during RT SBE message passing. "
                            "chipID: 0x%08X, rc: 0x%08x, but expected 0 for "
                            "CFAM register checking",
                            chipId, rc);
                    break;
                }
            }while (0);

            // Test exit
            TRACFCOMP(g_trac_sbeio, EXIT_MRK "SbeMessagePassingRtTest::"
                                    "testSbeMessagePassingDefaultPath");
#else  // #if CONFIG_HTMGT
            TRACFCOMP(g_trac_sbeio, "SbeMessagePassingRtTest::"
                                    "testSbeMessagePassingDefaultPath skipped "
                                    "because HTMGT is not supported");
#endif // #else ... #if CONFIG_HTMGT
        }

        /**
         * @brief testSbeMessagePassing Unit test for the
         *              SBE message passing function.
         */
        void testSbeMessagePassingFunction(void)
        {
            // Test entry
            TRACFCOMP(g_trac_sbeio, ENTER_MRK "SbeMessagePassingRtTest::"
                                    "testSbeMessagePassingFunction");

            sbeMessage_t l_request;
            sbeMessage_t l_expected_response;
            TARGETING::rtChipId_t chipId = 0;
            uint64_t l_sbeCommAddr = 0;
            runtimeInterfaces_t *rt_intf = nullptr;

            int rc = 0;

            do
            {
                // Clear mapping for Generic HTMGT Message command
                rc = setProcessCmdFunction(PASSTHRU_HTMGT_GENERIC,
                                           nullptr);
                if(0 != rc)
                {
                    TS_FAIL("Unexpected error during RT SBE message passing. "
                            "chipID: 0x%08X, rc: 0x%08x, but expected 0 for "
                            "setProcessCmdFunction",
                            chipId, rc);
                    break;
                }

                // Do initializations for SBE Message passing
                rc = initSbeMessagePassing(l_request,
                                           l_expected_response,
                                           chipId,
                                           l_sbeCommAddr,
                                           &rt_intf);

                // Copy test request into SBE Communication area
                memcpy(reinterpret_cast<void*>(l_sbeCommAddr),
                       reinterpret_cast<void*>(&l_request),
                       l_request.sbeHdr.msgSize);

                // Call the SBE message passing code
                rc = rt_intf->sbe_message_passing(chipId);
                if(0x2831 != rc)
                {
                    TS_FAIL("Unexpected return during RT SBE message passing. "
                            "Testing function not set for chipID: 0x%08X",
                            chipId);
                    break;
                }

                // Increment Total Tests
                g_TotalTests++;

                // Check setting of bits in CFAM register
                rc = checkResetSbeMessagePassingCFAM(chipId,
                                                     SBE_MSG_IN_PROGRESS);
                if(0 != rc)
                {
                    TS_FAIL("Unexpected error during RT SBE message passing. "
                            "chipID: 0x%08X, rc: 0x%08x, but expected 0 for "
                            "CFAM register checking",
                            chipId, rc);
                    break;
                }

                // Erase mapping for Generic HTMGT Message command
                rc = eraseProcessCmdFunction(PASSTHRU_HTMGT_GENERIC);
                if(0 != rc)
                {
                    TS_FAIL("Unexpected error during RT SBE message passing. "
                            "chipID: 0x%08X, rc: 0x%08x, but expected 0 for "
                            "eraseProcessCmdFunction",
                            chipId, rc);
                    break;
                }

                // Do initializations for SBE Message passing
                rc = initSbeMessagePassing(l_request,
                                           l_expected_response,
                                           chipId,
                                           l_sbeCommAddr,
                                           &rt_intf);

                // Copy test request into SBE Communication area
                memcpy(reinterpret_cast<void*>(l_sbeCommAddr),
                       reinterpret_cast<void*>(&l_request),
                       l_request.sbeHdr.msgSize);

                // Call the SBE message passing code
                rc = rt_intf->sbe_message_passing(chipId);
                if(0x2839 != rc)
                {
                    TS_FAIL("Unexpected error during RT SBE message passing. "
                            "Testing function not found for chipID: 0x%08X",
                            chipId);
                    break;
                }

                // Check setting of bits in CFAM register
                rc = checkResetSbeMessagePassingCFAM(chipId,
                                                     SBE_MSG_IN_PROGRESS);
                if(0 != rc)
                {
                    TS_FAIL("Unexpected error during RT SBE message passing. "
                            "chipID: 0x%08X, rc: 0x%08x, but expected 0 for "
                            "CFAM register checking",
                            chipId, rc);
                    break;
                }
            }while (0);

            // Test exit
            TRACFCOMP(g_trac_sbeio, EXIT_MRK "SbeMessagePassingRtTest::"
                                    "testSbeMessagePassingFunction");
        }

        /**
         * @brief testSbeMessagePassing Unit test for the
         *              SBE message passing set function.
         */
        void testSbeMessagePassingSetFunction(void)
        {
            // Test entry
            TRACFCOMP(g_trac_sbeio, ENTER_MRK "SbeMessagePassingRtTest::"
                                    "testSbeMessagePassingSetFunction");

            int rc = 0;

            do
            {
                // Call Set Process Command Function
                rc = setProcessCmdFunction(PASSTHRU_HTMGT_GENERIC,
                                           processGenericHtmgt);
                if(0 != rc)
                {
                    TS_FAIL("Unexpected return during RT SBE message passing. "
                            "rc: 0x%08x, but expected 0 from "
                            "setProcessCmdFunction()",
                            rc);
                    break;
                }
            }while (0);

            // Test exit
            TRACFCOMP(g_trac_sbeio, EXIT_MRK "SbeMessagePassingRtTest::"
                                    "testSbeMessagePassingSetFunction");
        }

        /**
         * @brief testSbeMessagePassing Unit test for the
         *              SBE message passing good path.
         */
        void testSbeMessagePassingGoodPath(void)
        {
            // Test entry
            TRACFCOMP(g_trac_sbeio, ENTER_MRK "SbeMessagePassingRtTest::"
                                    "testSbeMessagePassingGoodPath");

            sbeMessage_t l_request;
            sbeMessage_t l_expected_response;
            TARGETING::rtChipId_t chipId = 0;
            uint64_t l_sbeCommAddr = 0;
            runtimeInterfaces_t *rt_intf = nullptr;

            int rc = 0;

            do
            {
                // Do initializations for SBE Message passing
                rc = initSbeMessagePassing(l_request,
                                           l_expected_response,
                                           chipId,
                                           l_sbeCommAddr,
                                           &rt_intf);

                // Get the response address in the SBE Communication area
                sbeMessage_t *l_sbeCommAddr_rsp =
                    reinterpret_cast<sbeMessage_t*>(l_sbeCommAddr);

                // Copy test request into SBE Communication area
                memcpy(reinterpret_cast<void*>(l_sbeCommAddr),
                       reinterpret_cast<void*>(&l_request),
                       l_request.sbeHdr.msgSize);

                // Call Set Process Command Function
                rc = setProcessCmdFunction(PASSTHRU_HTMGT_GENERIC,
                                           processGenericHtmgt);
                if(0 != rc)
                {
                    TS_FAIL("Unexpected return during RT SBE message passing. "
                            "rc: 0x%08x, but expected 0 from "
                            "setProcessCmdFunction() for good path test",
                            rc);
                    break;
                }

                // Call the SBE message passing code
                rc = rt_intf->sbe_message_passing(chipId);
                if(0 != rc)
                {
                    TS_FAIL("Unexpected return during RT SBE message passing. "
                            "Testing good path for chipID: 0x%08X, rc: 0x%08x, "
                            "but expected 0",
                            chipId, rc);
                    break;
                }

                // Compare test response from SBE Communication area
                if(sbeOrCmdHeaderDiffer(l_sbeCommAddr_rsp, &l_expected_response))
                {
                    TRACFBIN( g_trac_sbeio,
                              "testSbeMessagePassingGoodPath: expected rsp",
                              &l_expected_response,
                              l_expected_response.sbeHdr.msgSize);
                    TRACFBIN( g_trac_sbeio,
                              "testSbeMessagePassingGoodPath: actual rsp",
                              l_sbeCommAddr_rsp,
                              l_sbeCommAddr_rsp->sbeHdr.msgSize);
                    TS_FAIL("Unexpected response from RT SBE message passing. "
                            "Testing good path for chipID: 0x%08X",
                            chipId);
                    break;
                }

                // Check setting of bits in CFAM register
                rc = checkResetSbeMessagePassingCFAM(chipId,
                                                     SBE_MSG_COMPLETE);
                if(0 != rc)
                {
                    TS_FAIL("Unexpected error during RT SBE message passing. "
                            "chipID: 0x%08X, rc: 0x%08x, but expected 0 for "
                            "CFAM register checking",
                            chipId, rc);
                    break;
                }

                // Increment Total Tests
                g_TotalTests++;

                // Increase data offset and message size and shift data
                // to verify that the data payload does not have to be
                // immediately after the Command Header
                l_request.cmdHdr.dataSize += 4;
                l_request.sbeHdr.msgSize += 4;
                uint32_t *l_req_data =
                    reinterpret_cast<uint32_t*>(&l_request.data[0]);
                l_req_data[3] = l_req_data[2];
                l_req_data[2] = l_req_data[1];
                l_req_data[1] = l_req_data[0];
                l_req_data[0] = 0;

                // Copy test request into SBE Communication area
                memcpy(reinterpret_cast<void*>(l_sbeCommAddr),
                       reinterpret_cast<void*>(&l_request),
                       l_request.sbeHdr.msgSize);

                // Call the SBE message passing code
                rc = rt_intf->sbe_message_passing(chipId);
                if(0 != rc)
                {
                    TS_FAIL("Unexpected return during RT SBE message passing. "
                            "Testing good path with data shifted for chipID: "
                            "0x%08X, rc: 0x%08x, but expected 0",
                            chipId, rc);
                    break;
                }

                // Compare test response from SBE Communication area
                if(sbeOrCmdHeaderDiffer(l_sbeCommAddr_rsp, &l_expected_response))
                {
                    TRACFBIN( g_trac_sbeio,
                              "testSbeMessagePassingGoodPath: expected rsp",
                              &l_expected_response,
                              l_expected_response.sbeHdr.msgSize);
                    TRACFBIN( g_trac_sbeio,
                              "testSbeMessagePassingGoodPath: actual rsp",
                              l_sbeCommAddr_rsp,
                              l_sbeCommAddr_rsp->sbeHdr.msgSize);
                    TS_FAIL("Unexpected response from RT SBE message passing. "
                            "Testing good path with data shifted for chipID: "
                            "0x%08X",
                            chipId);
                    break;
                }

                // Check setting of bits in CFAM register
                rc = checkResetSbeMessagePassingCFAM(chipId,
                                                     SBE_MSG_COMPLETE);
                if(0 != rc)
                {
                    TS_FAIL("Unexpected error during RT SBE message passing. "
                            "chipID: 0x%08X, rc: 0x%08x, but expected 0 for "
                            "CFAM register checking",
                            chipId, rc);
                    break;
                }
            }while (0);

            // Test exit
            TRACFCOMP(g_trac_sbeio, EXIT_MRK "SbeMessagePassingRtTest::"
                                    "testSbeMessagePassingGoodPath");
        }

        /**
         * @brief testSbeMessagePassing Unit test for the
         *              SBE message passing error paths.
         */
        void testSbeMessagePassingErrorPaths(void)
        {
            // Test entry
            TRACFCOMP(g_trac_sbeio, ENTER_MRK "SbeMessagePassingRtTest::"
                                    "testSbeMessagePassingErrorPaths");

            sbeMessage_t l_request;
            sbeMessage_t l_expected_response;
            uint32_t l_hdrsSize = sizeof(sbeHeader_t) + sizeof(cmdHeader_t);
            TARGETING::rtChipId_t chipId = 0;
            uint64_t l_sbeCommAddr = 0;
            runtimeInterfaces_t *rt_intf = nullptr;

            int rc = 0;

            do
            {
                // Do initializations for SBE Message passing
                rc = initSbeMessagePassing(l_request,
                                           l_expected_response,
                                           chipId,
                                           l_sbeCommAddr,
                                           &rt_intf);

                // Get the response address in the SBE Communication area
                sbeMessage_t *l_sbeCommAddr_rsp =
                    reinterpret_cast<sbeMessage_t*>(l_sbeCommAddr);

                // Set the test option to excess response data size
                l_request.cmdHdr.status = 0x1;

                // Change sizes in expected response
                l_expected_response.sbeHdr.msgSize = SBE_MSG_SIZE;
                l_expected_response.cmdHdr.dataSize = SBE_MSG_SIZE;

                // Copy test request into SBE Communication area
                memcpy(reinterpret_cast<void*>(l_sbeCommAddr),
                       reinterpret_cast<void*>(&l_request),
                       l_request.sbeHdr.msgSize);

                // Call Set Process Command Function
                rc = setProcessCmdFunction(PASSTHRU_HTMGT_GENERIC,
                                           processGenericHtmgt);
                if(0 != rc)
                {
                    TS_FAIL("Unexpected return during RT SBE message passing. "
                            "rc: 0x%08x, but expected 0 from "
                            "setProcessCmdFunction() for error path test",
                            rc);
                    break;
                }

                // Call the SBE message passing code
                rc = rt_intf->sbe_message_passing(chipId);
                if(0x2832 != rc)
                {
                    TS_FAIL("Unexpected return during RT SBE message passing. "
                            "Testing excess response data size error path for "
                            "chipID: 0x%08X",
                            chipId);
                    break;
                }

                // Compare test response from SBE Communication area
                if(sbeOrCmdHeaderDiffer(l_sbeCommAddr_rsp, &l_expected_response))
                {
                    TRACFBIN( g_trac_sbeio,
                              "testSbeMessagePassingErrorPaths: expected rsp",
                              &l_expected_response,
                              l_hdrsSize);
                    TRACFBIN( g_trac_sbeio,
                              "testSbeMessagePassingErrorPaths: actual rsp",
                              l_sbeCommAddr_rsp,
                              l_hdrsSize);
                    TS_FAIL("Unexpected response from RT SBE message passing. "
                            "chipID: 0x%08X, response data too large",
                            chipId);
                    break;
                }

                // Check setting of bits in CFAM register
                rc = checkResetSbeMessagePassingCFAM(chipId,
                                                     SBE_MSG_IN_PROGRESS);
                if(0 != rc)
                {
                    TS_FAIL("Unexpected error during RT SBE message passing. "
                            "chipID: 0x%08X, rc: 0x%08x, but expected 0 for "
                            "CFAM register checking",
                            chipId, rc);
                    break;
                }

                // Increment Total Tests
                g_TotalTests++;

                // Set the test option to error log
                l_request.cmdHdr.status = 0x2;

                // Change back sizes in expected response
                l_expected_response.sbeHdr.msgSize = l_hdrsSize + 1;
                l_expected_response.cmdHdr.dataSize = 1;

                // Copy test request into SBE Communication area
                memcpy(reinterpret_cast<void*>(l_sbeCommAddr),
                       reinterpret_cast<void*>(&l_request),
                       l_request.sbeHdr.msgSize);

                // Call the SBE message passing code
                rc = rt_intf->sbe_message_passing(chipId);
                if(0x2800 != rc)
                {
                    TS_FAIL("Unexpected return during RT SBE message passing. "
                            "Testing error log returned for chipID: 0x%08X",
                            chipId);
                    break;
                }

                // Check setting of bits in CFAM register
                rc = checkResetSbeMessagePassingCFAM(chipId,
                                                     SBE_MSG_IN_PROGRESS);
                if(0 != rc)
                {
                    TS_FAIL("Unexpected error during RT SBE message passing. "
                            "chipID: 0x%08X, rc: 0x%08x, but expected 0 for "
                            "CFAM register checking",
                            chipId, rc);
                    break;
                }

                // Increment Total Tests
                g_TotalTests++;

                // Set the test option to generic failure status
                l_request.cmdHdr.status = 0x3;

                // Change status in expected response
                l_expected_response.cmdHdr.status = 0xFE;

                // Copy test request into SBE Communication area
                memcpy(reinterpret_cast<void*>(l_sbeCommAddr),
                       reinterpret_cast<void*>(&l_request),
                       l_request.sbeHdr.msgSize);

                // Call the SBE message passing code
                rc = rt_intf->sbe_message_passing(chipId);
                if(0 != rc)
                {
                    TS_FAIL("Unexpected return during RT SBE message passing. "
                            "Testing failure status returned for chipID:"
                            "0x%08X, rc: 0x%08x, but expected 0",
                            chipId, rc);
                    break;
                }

                // Compare test response from SBE Communication area
                if(sbeOrCmdHeaderDiffer(l_sbeCommAddr_rsp, &l_expected_response))
                {
                    TRACFBIN( g_trac_sbeio,
                              "testSbeMessagePassingErrorPaths: expected rsp",
                              &l_expected_response,
                              l_expected_response.sbeHdr.msgSize);
                    TRACFBIN( g_trac_sbeio,
                              "testSbeMessagePassingErrorPaths: actual rsp",
                              l_sbeCommAddr_rsp,
                              l_sbeCommAddr_rsp->sbeHdr.msgSize);
                    TS_FAIL("Unexpected response from RT SBE message passing. "
                            "chipID: 0x%08X, status of generic failure",
                            chipId);
                    break;
                }

                // Check setting of bits in CFAM register
                rc = checkResetSbeMessagePassingCFAM(chipId,
                                                     SBE_MSG_COMPLETE);
                if(0 != rc)
                {
                    TS_FAIL("Unexpected error during RT SBE message passing. "
                            "chipID: 0x%08X, rc: 0x%08x, but expected 0 for "
                            "CFAM register checking",
                            chipId, rc);
                    break;
                }

                // Increment Total Tests
                g_TotalTests++;

                // Set the test option to altered SBE Header version
                l_request.cmdHdr.status = 0x4;

                // Change back status in expected response
                l_expected_response.cmdHdr.status = 0;

                // Copy test request into SBE Communication area
                memcpy(reinterpret_cast<void*>(l_sbeCommAddr),
                       reinterpret_cast<void*>(&l_request),
                       l_request.sbeHdr.msgSize);

                // Call the SBE message passing code
                rc = rt_intf->sbe_message_passing(chipId);
                if(0x2837 != rc)
                {
                    TS_FAIL("Unexpected return during RT SBE message passing. "
                            "Testing altered SBE Header version for chipID: "
                            "0x%08X",
                            chipId);
                    break;
                }

                // Check setting of bits in CFAM register
                rc = checkResetSbeMessagePassingCFAM(chipId,
                                                     SBE_MSG_IN_PROGRESS);
                if(0 != rc)
                {
                    TS_FAIL("Unexpected error during RT SBE message passing. "
                            "chipID: 0x%08X, rc: 0x%08x, but expected 0 for "
                            "CFAM register checking",
                            chipId, rc);
                    break;
                }

                // Increment Total Tests
                g_TotalTests++;

                // Set the test option to altered SBE Header sequence ID
                l_request.cmdHdr.status = 0x5;

                // Copy test request into SBE Communication area
                memcpy(reinterpret_cast<void*>(l_sbeCommAddr),
                       reinterpret_cast<void*>(&l_request),
                       l_request.sbeHdr.msgSize);

                // Call the SBE message passing code
                rc = rt_intf->sbe_message_passing(chipId);
                if(0x2837 != rc)
                {
                    TS_FAIL("Unexpected return during RT SBE message passing. "
                            "Testing altered SBE Header sequence ID for "
                            "chipID: 0x%08X",
                            chipId);
                    break;
                }

                // Check setting of bits in CFAM register
                rc = checkResetSbeMessagePassingCFAM(chipId,
                                                     SBE_MSG_IN_PROGRESS);
                if(0 != rc)
                {
                    TS_FAIL("Unexpected error during RT SBE message passing. "
                            "chipID: 0x%08X, rc: 0x%08x, but expected 0 for "
                            "CFAM register checking",
                            chipId, rc);
                    break;
                }

                // Increment Total Tests
                g_TotalTests++;

                 // Set the test option to altered Command Header version
                l_request.cmdHdr.status = 0x6;

                // Change back status in expected response
                l_expected_response.cmdHdr.status = 0;

                // Copy test request into SBE Communication area
                memcpy(reinterpret_cast<void*>(l_sbeCommAddr),
                       reinterpret_cast<void*>(&l_request),
                       l_request.sbeHdr.msgSize);

                // Call the SBE message passing code
                rc = rt_intf->sbe_message_passing(chipId);
                if(0x2837 != rc)
                {
                    TS_FAIL("Unexpected return during RT SBE message passing. "
                            "Testing altered Command Header version for "
                            "chipID: 0x%08X",
                            chipId);
                    break;
                }

                // Check setting of bits in CFAM register
                rc = checkResetSbeMessagePassingCFAM(chipId,
                                                     SBE_MSG_IN_PROGRESS);
                if(0 != rc)
                {
                    TS_FAIL("Unexpected error during RT SBE message passing. "
                            "chipID: 0x%08X, rc: 0x%08x, but expected 0 for "
                            "CFAM register checking",
                            chipId, rc);
                    break;
                }

                // Increment Total Tests
                g_TotalTests++;

                // Set the test option to altered altered Command Header command
                l_request.cmdHdr.status = 0x7;

                // Copy test request into SBE Communication area
                memcpy(reinterpret_cast<void*>(l_sbeCommAddr),
                       reinterpret_cast<void*>(&l_request),
                       l_request.sbeHdr.msgSize);

                // Call the SBE message passing code
                rc = rt_intf->sbe_message_passing(chipId);
                if(0x2837 != rc)
                {
                    TS_FAIL("Unexpected return during RT SBE message passing. "
                            "Testing altered Command Header command for "
                            "chipID: 0x%08X",
                            chipId);
                    break;
                }

                // Check setting of bits in CFAM register
                rc = checkResetSbeMessagePassingCFAM(chipId,
                                                     SBE_MSG_IN_PROGRESS);
                if(0 != rc)
                {
                    TS_FAIL("Unexpected error during RT SBE message passing. "
                            "chipID: 0x%08X, rc: 0x%08x, but expected 0 for "
                            "CFAM register checking",
                            chipId, rc);
                    break;
                }
            }while (0);

            // Test exit
            TRACFCOMP(g_trac_sbeio, EXIT_MRK "SbeMessagePassingRtTest::"
                                    "testSbeMessagePassingErrorPaths");
        }

/* End of Test Functions */

}; // class SbeMessagePassingRtTest
#endif
