/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mctp/runtime/test/testMctpReceive.H $                 */
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
#ifndef __TEST_MCTP_RECEIVE_H
#define __TEST_MCTP_RECEIVE_H

/**
 *  @file testMctpReceive.H
 *
 *  @brief Test case for HBRT's usage of MCTP_RECEIVE io_type
*/

#include <cxxtest/TestSuite.H>
#include <runtime/interface.h>
#include <libmctp.h>
#include <memory>

extern trace_desc_t* g_trac_mctp;

using hbrt_fw_msg = hostInterfaces::hbrt_fw_msg;

class mctpReceiveTest : public CxxTest::TestSuite
{
    public:

    // At this time there no good way to do end to end MCTP testing in
    // standalone runtime tests so this test is only making sure the
    // mctp_receive struct is defined in the hbrt_fw_msg struct's union.
    void testFirmwareRequestMctpReceive (void)
    {
        do {

        if (g_hostInterfaces == nullptr ||
            g_hostInterfaces->firmware_request == nullptr)
        {
           TS_FAIL("mctpReceiveTest::testFirmwareRequestMctpReceive: "
                   "Hypervisor firmware_request interface not linked."
                   "g_hostInterfaces = %p  g_hostInterfaces->firmware_request = %p",
                   g_hostInterfaces, g_hostInterfaces->firmware_request);
            break;
        }

        // Test MCTP_RECEIVE command
        constexpr size_t l_req_fw_msg_size = hostInterfaces::HBRT_FW_MSG_BASE_SIZE;
        hostInterfaces::hbrt_fw_msg l_req_fw_msg { };
        l_req_fw_msg.io_type = hostInterfaces::HBRT_FW_MSG_TYPE_MCTP_RECEIVE;


        size_t l_resp_fw_msg_size =
          hostInterfaces::HBRT_FW_MSG_BASE_SIZE + MCTP_BTU;
        std::unique_ptr<hostInterfaces::hbrt_fw_msg, decltype(&free)> l_resp_fw_msg(
            static_cast<hostInterfaces::hbrt_fw_msg *>(malloc( l_resp_fw_msg_size)), free);

        int rc = g_hostInterfaces->firmware_request(
                                  l_req_fw_msg_size, &l_req_fw_msg,
                                  &l_resp_fw_msg_size, l_resp_fw_msg.get());

        if(rc != 0)
        {
            TS_FAIL("testFirmwareRequestMctpReceive got rc %d from what should have been valid fw request", rc);
        }

        }while(0);
    }
};


#endif