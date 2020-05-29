/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mctp/runtime/test/testMctpSend.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2022                        */
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
#ifndef __TEST_MCTP_SEND_H
#define __TEST_MCTP_SEND_H

/**
 *  @file testMctpSend.H
 *
 *  @brief Test case for HBRT's usage of MCTP_SEND io_type
*/

#include <cxxtest/TestSuite.H>
#include <runtime/interface.h>

extern trace_desc_t* g_trac_mctp;

class mctpSendTest : public CxxTest::TestSuite
{
    public:

    // At this time there no good way to do end to end MCTP testing in
    // standalone runtime tests so this test is only making sure the mctp_send
    // struct is defined in the hbrt_fw_msg struct's union.
    void testFirmwareRequestMctpSend (void)
    {
        do {

        if (g_hostInterfaces == nullptr ||
            g_hostInterfaces->firmware_request == nullptr)
        {
           TS_FAIL("mctpSendTest::testFirmwareRequestMctpSend: "
                   "Hypervisor firmware_request interface not linked"
                   "g_hostInterfaces = %p  g_hostInterfaces->firmware_request = %p",
                   g_hostInterfaces, g_hostInterfaces->firmware_request);
            break;
        }

        // Test MCTP_SEND command
        hostInterfaces::hbrt_fw_msg l_req_fw_msg { };
        l_req_fw_msg.io_type =
              hostInterfaces::HBRT_FW_MSG_TYPE_MCTP_SEND;
        constexpr size_t l_req_fw_msg_size = hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                                              sizeof(l_req_fw_msg.mctp_send);
        // send valid  MCTP msg
        l_req_fw_msg.mctp_send.send_data[0] = 0xFF;

        // Generic Resp
        hostInterfaces::hbrt_fw_msg l_resp_fw_msg { };
        size_t l_resp_fw_msg_size = sizeof(l_resp_fw_msg);

        int rc = g_hostInterfaces->firmware_request(
                                  l_req_fw_msg_size, &l_req_fw_msg,
                                  &l_resp_fw_msg_size, &l_resp_fw_msg);

        if(rc != 0)
        {
            TS_FAIL("testFirmwareRequestMctpSend got invalid rc %d from what should have been valid fw request",
                    rc);
        }

        if(l_resp_fw_msg.resp_generic.o_status != 0)
        {
            TS_FAIL("testFirmwareRequestMctpSend got invalid o_status 0x%016x back that we expected in generic response",
                    l_resp_fw_msg.resp_generic.o_status);
        }

        }while(0);
    }
};


#endif