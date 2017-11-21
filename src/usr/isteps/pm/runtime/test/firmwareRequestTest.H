/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/pm/runtime/test/firmwareRequestTest.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2017                        */
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

#include <cxxtest/TestSuite.H>
#include <runtime/interface.h>
#include <errl/hberrltypes.H>
#include <string.h>

extern trace_desc_t* g_trac_pnor;

class FirmwareRequestTest : public CxxTest::TestSuite
{
    public:
    /**
     * @brief: testFirmwareRequestHcodeUpdate
     *      test the firmware_request's HCODE update call
     */
    void testFirmwareRequestHcodeUpdate (void)
    {
        TRACFCOMP(g_trac_pnor, ENTER_MRK
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
            size_t l_resp_fw_msg_size = sizeof(l_resp_fw_msg);
            size_t rc = g_hostInterfaces->firmware_request(
                                     sizeof(l_req_fw_msg), &l_req_fw_msg,
                                     &l_resp_fw_msg_size, &l_resp_fw_msg);

            TRACFCOMP(g_trac_pnor,
                      "FirmwareRequestTest::testFirmwareRequestHcodeUpdate: "
                      "rc:%d, type:%d, resp:%d",
                      rc, l_resp_fw_msg.io_type,
                      l_resp_fw_msg.resp_generic.o_status);

            if (rc != 1)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestHcodeUpdate: "
                        "firware_request - hcode update failed - "
                        "returned wrong value");
            }

            if (l_resp_fw_msg.io_type !=
                                hostInterfaces::HBRT_FW_MSG_TYPE_RESP_GENERIC)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestHcodeUpdate: "
                        "firware_request - hcode update failed - "
                        "received incorrect msg_type");
            }

            if (l_resp_fw_msg.resp_generic.o_status != 264)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestHcodeUpdate: "
                        "firware_request - hcode update failed - "
                        "received incorrect resp");
            }
        }  // end else
        TRACFCOMP(g_trac_pnor, EXIT_MRK
                  "FirmwareRequestTest::testFirmwareRequestHcodeUpdate");

    }  // end testFirmwareRequestHcodeUpdate

    /**
     * @brief: testFirmwareRequestErrLogToFsp
     *      test the firmware_request's error log to FSP
     */
    void testFirmwareRequestErrLogToFsp (void)
    {
        TRACFCOMP(g_trac_pnor, ENTER_MRK
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
            size_t l_resp_fw_msg_size = sizeof(l_resp_fw_msg);
            size_t rc = g_hostInterfaces->firmware_request(
                                     sizeof(l_req_fw_msg), &l_req_fw_msg,
                                     &l_resp_fw_msg_size, &l_resp_fw_msg);

            TRACFCOMP(g_trac_pnor,
                      "FirmwareRequestTest::testFirmwareRequestErrLogToFsp: "
                      "rc:%d, type:%d, resp:%d",
                      rc, l_resp_fw_msg.io_type,
                      l_resp_fw_msg.resp_generic.o_status);

            if (rc != 0)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestErrLogToFsp: "
                        "firware_request - error log failed - "
                        "returned wrong value");
            }

            if (l_resp_fw_msg.io_type !=
                                hostInterfaces::HBRT_FW_MSG_TYPE_RESP_GENERIC)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestErrLogToFsp: "
                        "firware_request - error log failed - "
                        "received incorrect msg_type");
            }

            if (l_resp_fw_msg.resp_generic.o_status != 20)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestErrLogToFsp: "
                        "firware_request - error log failed - "
                        "received incorrect resp");
            }
        }  // end else
        TRACFCOMP(g_trac_pnor, EXIT_MRK
                  "FirmwareRequestTest::testFirmwareRequestErrLogToFsp");

    }  // end testFirmwareRequestErrLogToFsp

    /**
     * @brief: testFirmwareRequestHbrtToFsp
     *      test the firmware_request's HBRT to FSP call
     */
    void testFirmwareRequestHbrtToFsp (void)
    {
        TRACFCOMP(g_trac_pnor, ENTER_MRK
                  "FirmwareRequestTest::testFirmwareRequestHbrtToFsp");

        if (g_hostInterfaces == NULL ||
            g_hostInterfaces->firmware_request == NULL)
        {
           TS_FAIL("FirmwareRequestTest::testFirmwareRequestHbrtToFsp: "
                   "Hypervisor firmware_request interface not linked");
        }
        else
        {
            // Test HBRT to FSP
            // populate the firmware_request structure with arbitrary data
            hostInterfaces::hbrt_fw_msg l_req_fw_msg;
            l_req_fw_msg.generic_msg.initialize();

            if (l_req_fw_msg.generic_msg.magic != GFMM_MAGIC_NUMBER)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestHbrtToFsp: "
                        "magic was not properly initialized");
            }

            if (l_req_fw_msg.generic_msg.dataSize !=
                                         sizeof(l_req_fw_msg.generic_msg))
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestHbrtToFsp: "
                        "dataSize was not properly initialized");
            }

            if (l_req_fw_msg.generic_msg.structVer != GFMM_VERSION)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestHbrtToFsp: "
                        "structVer was not properly initialized");
            }

            if (l_req_fw_msg.generic_msg.seqnum != SeqId_t::getCurrentSeqId())
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestHbrtToFsp: "
                        "seqnum was not properly initialized");
            }

            l_req_fw_msg.io_type = hostInterfaces::HBRT_FW_MSG_HBRT_FSP_REQ;
            l_req_fw_msg.generic_msg.magic = 0x100;
            l_req_fw_msg.generic_msg.dataSize =
                                        sizeof(l_req_fw_msg.generic_msg);
            l_req_fw_msg.generic_msg.structVer = 0x20;
            l_req_fw_msg.generic_msg.seqnum = 0x300;
            l_req_fw_msg.generic_msg.msgq = 0x400;
            l_req_fw_msg.generic_msg.msgType = 0x500;
            l_req_fw_msg.generic_msg.__req = GFMM_REQUEST;
            l_req_fw_msg.generic_msg.__onlyError = GFMM_ERROR_ONLY;
            uint32_t l_plid = 0x600;
            uint32_t l_huid = 0x700;
            l_req_fw_msg.generic_msg.data =
                                          TWO_UINT32_TO_UINT64(l_plid, l_huid);

            TRACFCOMP(g_trac_pnor,
                      "FirmwareRequestTest::testFirmwareRequestHbrtToFsp req: "
                      "type:%d, magic:0x%.8X, dataSize:%d, structVer:0x%.8X, "
                      "seqnum:%.8X, msgq:0x%.8X, msgType:0x%.8X, __req:%d, "
                      "__onlyError:%d, data:0x%.8X, plid:0x%.8X, huid:0x%.8X",
                      l_req_fw_msg.io_type,
                      l_req_fw_msg.generic_msg.magic,
                      l_req_fw_msg.generic_msg.dataSize,
                      l_req_fw_msg.generic_msg.structVer,
                      l_req_fw_msg.generic_msg.seqnum,
                      l_req_fw_msg.generic_msg.msgq,
                      l_req_fw_msg.generic_msg.msgType,
                      l_req_fw_msg.generic_msg.__req,
                      l_req_fw_msg.generic_msg.__onlyError,
                      l_req_fw_msg.generic_msg.data,
                      l_req_fw_msg.generic_msg.data >> 32,
                      0x0000FFFF & l_req_fw_msg.generic_msg.data);

            hostInterfaces::hbrt_fw_msg l_resp_fw_msg;
            size_t l_resp_fw_msg_size = sizeof(l_resp_fw_msg);
            memset(&l_resp_fw_msg, 0, l_resp_fw_msg_size);
            size_t rc = g_hostInterfaces->firmware_request(
                                     sizeof(l_req_fw_msg), &l_req_fw_msg,
                                     &l_resp_fw_msg_size, &l_resp_fw_msg);

            TRACFCOMP(g_trac_pnor,
                      "FirmwareRequestTest::testFirmwareRequestHbrtToFsp resp: "
                      "type:%d, magic:0x%.8X, dataSize:%d, structVer:0x%.8X, "
                      "seqnum:%.8X, msgq:0x%.8X, msgType:0x%.8X, __req:%d, "
                      "__onlyError:%d, data:0x%.8X, plid:0x%.8X, huid:0x%.8X, "
                      "rc=%d",
                      l_resp_fw_msg.io_type,
                      l_resp_fw_msg.generic_msg.magic,
                      l_resp_fw_msg.generic_msg.dataSize,
                      l_resp_fw_msg.generic_msg.structVer,
                      l_resp_fw_msg.generic_msg.seqnum,
                      l_resp_fw_msg.generic_msg.msgq,
                      l_resp_fw_msg.generic_msg.msgType,
                      l_resp_fw_msg.generic_msg.__req,
                      l_resp_fw_msg.generic_msg.__onlyError,
                      l_resp_fw_msg.generic_msg.data,
                      l_resp_fw_msg.generic_msg.data >> 32,
                      0x0000FFFF & l_resp_fw_msg.generic_msg.data,
                      rc);

            if (rc != 5)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestHbrtToFsp: "
                        "firmware_request - HBRT to FSP failed - "
                        "returned wrong value");
            }

            if (l_resp_fw_msg.io_type !=
                                hostInterfaces::HBRT_FW_MSG_HBRT_FSP_RESP)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestHbrtToFsp: "
                        "firmware_request - HBRT to FSP failed - "
                        "received incorrect msg_type");
            }

            if (l_resp_fw_msg.generic_msg.magic != 0x10)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestHbrtToFsp: "
                        "firmware_request - HBRT to FSP failed - "
                        "received incorrect magic");
            }

            if (l_resp_fw_msg.generic_msg.dataSize != 32)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestHbrtToFsp: "
                        "firmware_request - HBRT to FSP failed - "
                        "received incorrect datSize");
            }


            if (l_resp_fw_msg.generic_msg.structVer != 0x02)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestHbrtToFsp: "
                        "firmware_request - HBRT to FSP failed - "
                        "received incorrect structVer");
            }

            if (l_resp_fw_msg.generic_msg.seqnum != 0x30)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestHbrtToFsp: "
                        "firmware_request - HBRT to FSP failed - "
                        "received incorrect seqnum");
            }

            if (l_resp_fw_msg.generic_msg.msgq != 0x40)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestHbrtToFsp: "
                        "firware_request - HBRT to FSP failed - "
                        "received incorrect msgq");
            }

            if (l_resp_fw_msg.generic_msg.msgType != 0x50)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestHbrtToFsp: "
                        "firware_request - HBRT to FSP failed - "
                        "received incorrect msgType");
            }

            if (l_resp_fw_msg.generic_msg.data >> 32 != 0x60)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestHbrtToFsp: "
                        "firware_request - HBRT to FSP failed - "
                        "received incorrect errPlid");
            }

            if ((0x0000FFFF & l_resp_fw_msg.generic_msg.data) != 0x70)
            {
                TS_FAIL("FirmwareRequestTest::testFirmwareRequestHbrtToFsp: "
                        "firware_request - HBRT to FSP failed - "
                        "received incorrect huid");
            }
       }
       TRACFCOMP(g_trac_pnor, EXIT_MRK
                  "FirmwareRequestTest::testFirmwareRequestHbrtToFsp");

    }  // end testFirmwareRequestHbrtToFsp

};  // end class FirmwareRequestTest
