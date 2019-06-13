/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/pm/runtime/test/firmwareRequestTest.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2019                        */
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

#include <cxxtest/TestSuite.H>       // CxxTest::TestSuite
#include <runtime/interface.h>       // g_hostInterfaces, etc
#include <runtime/hbrt_utilities.H>  // createGenericFspMsg
#include <vector>

extern trace_desc_t* g_trac_test;

class FirmwareRequestTest : public CxxTest::TestSuite
{
    public:

    /**
     * @brief: testFirmwareRequestHcodeUpdate
     *      test the firmware_request's Send Attributes
     */
    void testFirmwareRequestSendAttributes (void)
    {
        TRACFCOMP(g_trac_test, ENTER_MRK
                  "FirmwareRequestTest::testFirmwareRequestSendAttributes" );

        if (g_hostInterfaces == NULL ||
            g_hostInterfaces->firmware_request == NULL)
        {
            TS_FAIL("FirmwareRequestTest::testFirmwareRequestSendAttributes: "
                    "Hypervisor firmware_request interface not linked");
        }
        else
        {
            std::vector<TARGETING::AttributeTank::Attribute> l_attributeList;

            uint32_t l_dataSize(0);

            // Test 1: Create a default attribute and add to list
            TARGETING::AttributeTank::Attribute l_attribute;
            l_attributeList.push_back(l_attribute);
            l_dataSize += l_attribute.getSize();
            sendAttributes(l_attributeList);

            // Test 2: Modify some of the Attributes data and add to list
            l_attribute.setId(0x1001);
            l_attribute.setTargetType(0x2002);
            l_attribute.setPosition(0x3003);
            l_attribute.setUnitPosition(0x4);
            l_attribute.setNode(0x5);
            l_attribute.setFlags(0x6);
            l_attributeList.push_back(l_attribute);
            l_dataSize += l_attribute.getSize();
            sendAttributes(l_attributeList);

            // Create a buffer to be used to update Value in the Attribute
            uint32_t l_bufferSize(3);
            uint8_t l_buffer[l_bufferSize];
            l_buffer[0] = 0xAA;
            l_buffer[1] = 0xBB;
            l_buffer[2] = 0xCC;

            // Test 3: Update the Attribute Values in the Attribute
            // and add to list
            l_attribute.setValue(l_buffer, 1);
            l_attributeList.push_back(l_attribute);
            l_dataSize += l_attribute.getSize();
            sendAttributes(l_attributeList);

            // Test 4: Update the Attribute Values in the Attribute
            // and add to list
            l_buffer[0] = 0xDD;
            l_attribute.setValue(l_buffer, l_bufferSize);
            l_attributeList.push_back(l_attribute);
            l_dataSize += l_attribute.getSize();
            sendAttributes(l_attributeList);
        }

        TRACFCOMP(g_trac_test, EXIT_MRK
                  "FirmwareRequestTest::testFirmwareRequestSendAttributes");
    }

    /**
     * @brief: testFirmwareRequestHcodeUpdate
     *      test the firmware_request's HCODE update call
     */
    void testFirmwareRequestHcodeUpdate (void)
    {
        TRACFCOMP(g_trac_test, ENTER_MRK
                  "FirmwareRequestTest::testFirmwareRequestHcodeUpdate");

        if (g_hostInterfaces == NULL ||
            g_hostInterfaces->firmware_request == NULL)
        {
            TS_FAIL("FirmwareRequestTest::testFirmwareRequestHcodeUpdate: "
                    "Hypervisor firmware_request interface not linked");
        }
        else
        {
            // Test HCODE Update
            // populate the firmware_request structure with arbitrary data
            hostInterfaces::hbrt_fw_msg l_req_fw_msg;
            l_req_fw_msg.io_type =
                  hostInterfaces::HBRT_FW_MSG_TYPE_REQ_HCODE_UPDATE;
            l_req_fw_msg.req_hcode_update.i_chipId = 0x100;
            l_req_fw_msg.req_hcode_update.i_section = 20;
            l_req_fw_msg.req_hcode_update.i_operation = 30;
            l_req_fw_msg.req_hcode_update.i_scomAddr = 0x400;
            l_req_fw_msg.req_hcode_update.i_scomData = 0x500;

            hostInterfaces::hbrt_fw_msg l_resp_fw_msg;
            size_t l_resp_fw_msg_size = hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                                        sizeof(l_resp_fw_msg);
            size_t rc = g_hostInterfaces->firmware_request(
                                     sizeof(l_req_fw_msg), &l_req_fw_msg,
                                     &l_resp_fw_msg_size, &l_resp_fw_msg);

            TRACDCOMP(g_trac_test,
                      "FirmwareRequestTest::testFirmwareRequestHcodeUpdate: "
                      "rc:%d, type:%d, resp:%d",
                      rc, l_resp_fw_msg.io_type,
                      l_resp_fw_msg.resp_generic.o_status);

            if (rc != 1)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestHcodeUpdate: "
                        "firmware_request - hcode update failed - "
                        "returned wrong value");
            }

            if (l_resp_fw_msg.io_type !=
                                hostInterfaces::HBRT_FW_MSG_TYPE_RESP_GENERIC)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestHcodeUpdate: "
                        "firmware_request - hcode update failed - "
                        "received incorrect msg_type");
            }

            if (l_resp_fw_msg.resp_generic.o_status != 264)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestHcodeUpdate: "
                        "firmware_request - hcode update failed - "
                        "received incorrect resp");
            }
        }  // end else
        TRACFCOMP(g_trac_test, EXIT_MRK
                  "FirmwareRequestTest::testFirmwareRequestHcodeUpdate");
    }  // end testFirmwareRequestHcodeUpdate

    /**
     * @brief: testFirmwareRequestErrLogToFsp
     *      test the firmware_request's error log to FSP
     */
    void testFirmwareRequestErrLogToFsp (void)
    {
        TRACFCOMP(g_trac_test, ENTER_MRK
                  "FirmwareRequestTest::testFirmwareRequestErrLogToFsp");

        if (g_hostInterfaces == NULL ||
            g_hostInterfaces->firmware_request == NULL)
        {
           TS_FAIL("FirmwareRequestTest::testFirmwareRequestErrLogToFsp: "
                   "Hypervisor firmware_request interface not linked");
        }
        else
        {
            // Test error log to FSP
            // populate the firmware_request structure with arbitrary data
            hostInterfaces::hbrt_fw_msg l_req_fw_msg;
            l_req_fw_msg.io_type =hostInterfaces::HBRT_FW_MSG_TYPE_ERROR_LOG;
            l_req_fw_msg.error_log.i_plid = 0x300;
            l_req_fw_msg.error_log.i_errlSize = 1;
            l_req_fw_msg.error_log.i_data = 0xAA;

            hostInterfaces::hbrt_fw_msg l_resp_fw_msg;
            size_t l_resp_fw_msg_size = hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                                        sizeof(l_resp_fw_msg);
            size_t rc = g_hostInterfaces->firmware_request(
                                     sizeof(l_req_fw_msg), &l_req_fw_msg,
                                     &l_resp_fw_msg_size, &l_resp_fw_msg);

            TRACDCOMP(g_trac_test,
                      "FirmwareRequestTest::testFirmwareRequestErrLogToFsp: "
                      "rc:%d, type:%d, resp:%d",
                      rc, l_resp_fw_msg.io_type,
                      l_resp_fw_msg.resp_generic.o_status);

            if (rc != 0)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestErrLogToFsp: "
                        "firmware_request - error log failed - "
                        "returned wrong value");
            }

            if (l_resp_fw_msg.io_type !=
                                hostInterfaces::HBRT_FW_MSG_TYPE_RESP_GENERIC)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestErrLogToFsp: "
                        "firmware_request - error log failed - "
                        "received incorrect msg_type");
            }

            if (l_resp_fw_msg.resp_generic.o_status != 20)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestErrLogToFsp: "
                        "firmware_request - error log failed - "
                        "received incorrect resp");
            }
        }  // end else
        TRACFCOMP(g_trac_test, EXIT_MRK
                  "FirmwareRequestTest::testFirmwareRequestErrLogToFsp");

    }  // end testFirmwareRequestErrLogToFsp

    /**
     * @brief: testFirmwareRequestSbeRetry
     *      test the firmware_request's SBE retry
     */
    void testFirmwareRequestSbeRetry (void)
    {
        TRACFCOMP(g_trac_test, ENTER_MRK
                  "FirmwareRequestTest::testFirmwareRequestSbeRetry");

        if (g_hostInterfaces == NULL ||
            g_hostInterfaces->firmware_request == NULL)
        {
           TS_FAIL("FirmwareRequestTest::testFirmwareRequestSbeRetry: "
                   "Hypervisor firmware_request interface not linked");
        }
        else
        {
            // Test Request SBE Retry

            // Handles to the firmware messages
            hostInterfaces::hbrt_fw_msg *l_req_fw_msg = nullptr;
            hostInterfaces::hbrt_fw_msg *l_resp_fw_msg = nullptr;

            // Create and initialize to zero a few needed variables
            uint32_t l_fsp_data_size(0);
            uint64_t l_req_fw_msg_size(0), l_resp_fw_msg_size(0);

            // Create the dynamic firmware messages
            createGenericFspMsg(sizeof(SbeRetryReqData_t),
                                l_fsp_data_size,
                                l_req_fw_msg_size,
                                l_req_fw_msg,
                                l_resp_fw_msg_size,
                                l_resp_fw_msg);

            // Populate the firmware_request request struct with given data
            l_req_fw_msg->generic_msg.msgq = 0x300;
            l_req_fw_msg->generic_msg.msgType =
                            GenericFspMboxMessage_t::MSG_SBE_ERROR;

            // Create a useful struct to populate the generic_msg::data field
            // Setting the PLID and userData
            SbeRetryReqData_t* l_fspData =
                  reinterpret_cast<SbeRetryReqData_t*>
                                 (&(l_req_fw_msg->generic_msg.data));
            l_fspData->huid = 0x700;
            l_fspData->plid = 0x600;

            if (l_req_fw_msg->generic_msg.magic !=
                GenericFspMboxMessage_t::MAGIC_NUMBER)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestSbeRetry: "
                        "magic was not properly initialized");
            }

            if (l_req_fw_msg->generic_msg.dataSize != l_fsp_data_size)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestSbeRetry: "
                        "dataSize was not properly initialized");
            }

            if (l_req_fw_msg->generic_msg.structVer !=
                GenericFspMboxMessage_t::STRUCT_VERSION_LATEST)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestSbeRetry: "
                        "structVer was not properly initialized");
            }

            if (l_req_fw_msg->generic_msg.seqnum != SeqId_t::getCurrentSeqId())
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestSbeRetry: "
                        "seqnum was not properly initialized");
            }

            l_req_fw_msg->io_type = hostInterfaces::HBRT_FW_MSG_HBRT_FSP_REQ;
            l_req_fw_msg->generic_msg.magic = 0x100;
            l_req_fw_msg->generic_msg.dataSize = l_fsp_data_size;
            l_req_fw_msg->generic_msg.structVer = 0x20;
            l_req_fw_msg->generic_msg.seqnum = 0x300;
            l_req_fw_msg->generic_msg.__req = GenericFspMboxMessage_t::REQUEST;
            l_req_fw_msg->generic_msg.__onlyError =
                                          GenericFspMboxMessage_t::ERROR_ONLY;

            TRACDCOMP(g_trac_test,
                      "FirmwareRequestTest::testFirmwareRequestSbeRetry "
                      "Request data set 1/2: "
                      "type:%d, magic:0x%.8X, dataSize:%d, "
                      "structVer:0x%.8X,seqnum:%.8X, msgq:0x%.8X",
                      l_req_fw_msg->io_type,
                      l_req_fw_msg->generic_msg.magic,
                      l_req_fw_msg->generic_msg.dataSize,
                      l_req_fw_msg->generic_msg.structVer,
                      l_req_fw_msg->generic_msg.seqnum,
                      l_req_fw_msg->generic_msg.msgq);

            TRACDCOMP(g_trac_test,
                      "FirmwareRequestTest::testFirmwareRequestSbeRetry "
                      "Request data set 2/2: "
                      "msgType:0x%.8X, __req:%d, __onlyError:%d, "
                      "data:0x%.8X, plid:0x%.8X, huid:0x%.8X",
                      l_req_fw_msg->generic_msg.msgType,
                      l_req_fw_msg->generic_msg.__req,
                      l_req_fw_msg->generic_msg.__onlyError,
                      l_req_fw_msg->generic_msg.data,
                      l_req_fw_msg->generic_msg.data >> 32,
                      0x0000FFFF & l_req_fw_msg->generic_msg.data);


            size_t rc = g_hostInterfaces->firmware_request(l_req_fw_msg_size,
                                                           l_req_fw_msg,
                                                           &l_resp_fw_msg_size,
                                                           l_resp_fw_msg);

            TRACDCOMP(g_trac_test,
                      "FirmwareRequestTest::testFirmwareRequestSbeRetry "
                      "Response data set 1/2: "
                      "type:%d, magic:0x%.8X, dataSize:%d, "
                      "structVer:0x%.8X, seqnum:%.8X, msgq:0x%.8X",
                      l_resp_fw_msg->io_type,
                      l_resp_fw_msg->generic_msg.magic,
                      l_resp_fw_msg->generic_msg.dataSize,
                      l_resp_fw_msg->generic_msg.structVer,
                      l_resp_fw_msg->generic_msg.seqnum,
                      l_resp_fw_msg->generic_msg.msgq);

            TRACDCOMP(g_trac_test,
                      "FirmwareRequestTest::testFirmwareRequestSbeRetry "
                      "Response data set 2/2: "
                      "msgType:0x%.8X, __req:%d, __onlyError:%d, "
                      "data:0x%.8X, plid:0x%.8X, huid:0x%.8X, rc=%d",
                      l_resp_fw_msg->generic_msg.msgType,
                      l_resp_fw_msg->generic_msg.__req,
                      l_resp_fw_msg->generic_msg.__onlyError,
                      l_resp_fw_msg->generic_msg.data,
                      l_resp_fw_msg->generic_msg.data >> 32,
                      0x0000FFFF & l_resp_fw_msg->generic_msg.data,
                      rc);


            if (rc != 5)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestSbeRetry: "
                        "firmware_request - HBRT to FSP failed - "
                        "returned wrong value");
            }

            if (l_resp_fw_msg->io_type !=
                                hostInterfaces::HBRT_FW_MSG_HBRT_FSP_RESP)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestSbeRetry: "
                        "firmware_request - HBRT to FSP failed - "
                        "received incorrect msg_type");
            }

            if (l_resp_fw_msg->generic_msg.magic !=
                                GenericFspMboxMessage_t::MAGIC_NUMBER)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestSbeRetry: "
                        "firmware_request - HBRT to FSP failed - "
                        "received incorrect magic");
            }

            if (l_resp_fw_msg->generic_msg.dataSize != 32)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestSbeRetry: "
                        "firmware_request - HBRT to FSP failed - "
                        "received incorrect datSize");
            }

            if (l_resp_fw_msg->generic_msg.structVer != 0x020)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestSbeRetry: "
                        "firmware_request - HBRT to FSP failed - "
                        "received incorrect structVer");
            }

            if (l_resp_fw_msg->generic_msg.seqnum != 0x301)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestSbeRetry: "
                        "firmware_request - HBRT to FSP failed - "
                        "received incorrect seqnum");
            }

            if (l_resp_fw_msg->generic_msg.msgq != 0x300)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestSbeRetry: "
                        "firmware_request - HBRT to FSP failed - "
                        "received incorrect msgq");
            }
            if (l_resp_fw_msg->generic_msg.msgType !=
                GenericFspMboxMessage_t::MSG_SBE_ERROR)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestSbeRetry: "
                        "firmware_request - HBRT to FSP failed - "
                        "received incorrect msgType");
            }

            if (l_resp_fw_msg->generic_msg.data >> 32 != 0x60)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestSbeRetry: "
                        "firmware_request - HBRT to FSP failed - "
                        "received incorrect errPlid");
            }

            if ((0x0000FFFF & l_resp_fw_msg->generic_msg.data) != 0x70)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestSbeRetry: "
                        "firmware_request - HBRT to FSP failed - "
                        "received incorrect huid");
            }

            delete[] l_req_fw_msg;
            delete[] l_resp_fw_msg;
            l_req_fw_msg = l_resp_fw_msg = nullptr;
       }
       TRACFCOMP(g_trac_test, EXIT_MRK
                  "FirmwareRequestTest::testFirmwareRequestSbeRetry");

    }  // end testFirmwareRequestSbeRetry
};  // end class FirmwareRequestTest
