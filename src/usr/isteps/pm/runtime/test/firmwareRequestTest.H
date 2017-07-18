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

extern trace_desc_t* g_trac_pnor;

class FirmwareRequestTest : public CxxTest::TestSuite
{
    public:
    /**
     * @brief: testFirmwareRequest
     *      tests that the firmware_request is being accessed properly
     */
    void testFirmwareRequest (void)
    {
       TRACFCOMP(g_trac_pnor, ENTER_MRK
                 "FirmwareRequestTest::testFirmwareRequest" );

       if (g_hostInterfaces == NULL ||
           g_hostInterfaces->firmware_request == NULL)
       {
          TS_FAIL("FirmwareRequestTest::testFirmwareRequest: "
                  "Hypervisor firmware_request interface not linked");
       }
       else
       {
          hostInterfaces::hbrt_fw_msg l_req_fw_msg;
          l_req_fw_msg.io_type =
               hostInterfaces::HBRT_FW_MSG_TYPE_REQ_HCODE_UPDATE;
          l_req_fw_msg.req_hcode_update.i_chipId = 0;
          l_req_fw_msg.req_hcode_update.i_section = 0;
          l_req_fw_msg.req_hcode_update.i_operation = 0;
          l_req_fw_msg.req_hcode_update.i_scomAddr = 0;
          l_req_fw_msg.req_hcode_update.i_scomData = 0;


          hostInterfaces::hbrt_fw_msg l_resp_fw_msg;
          uint64_t l_resp_fw_msg_size = sizeof(l_resp_fw_msg);
          int rc = g_hostInterfaces->firmware_request(sizeof(l_resp_fw_msg),
                       &l_req_fw_msg, &l_resp_fw_msg_size, &l_resp_fw_msg);

          TRACFCOMP(g_trac_pnor, "FirmwareRequestTest::testFirmwareRequest: "
                                  "rc:%d, type:%d, resp:%d",
                    rc, l_resp_fw_msg.io_type,
                    l_resp_fw_msg.resp_generic.o_status);

          if (rc != 1)
          {
             TS_FAIL("FirmwareRequestTest::testFirmwareRequest: "
                     "firware_request failed - returned wrong value");
          }

          if (l_resp_fw_msg.io_type !=
                                hostInterfaces::HBRT_FW_MSG_TYPE_RESP_GENERIC)
          {
             TS_FAIL("FirmwareRequestTest::testFirmwareRequest: "
                     "firware_request failed - received incorrect msg_type");
          }

          if (l_resp_fw_msg.resp_generic.o_status != 264)
          {
             TS_FAIL("FirmwareRequestTest::testFirmwareRequest: "
                     "firware_request failed - received incorrect resp");
          }

          TRACFCOMP(g_trac_pnor, EXIT_MRK
                    "FirmwareRequestTest::testFirmwareRequest");
       }
    }
};
