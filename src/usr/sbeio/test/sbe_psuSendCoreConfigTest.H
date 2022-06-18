/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/test/sbe_psuSendCoreConfigTest.H $              */
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
#ifndef __SBE_PSU_SEND_CORE_CONFIG_TEST_H
#define __SBE_PSU_SEND_CORE_CONFIG_TEST_H

/**
 *  @file sbe_psuSendCoreConfigTest.H
 *
 *  @brief Test cases for setting up the PSU Command with Core config info
*/

#include <cxxtest/TestSuite.H>


#include <sbeio/sbe_psudd.H>                   // SbePsu::psuCommand
#include <targeting/common/commontargeting.H>  // get_huid
#include <targeting/common/utilFilter.H>       // getAllChips


namespace SBEIO
{

}

using namespace SBEIO;

extern trace_desc_t* g_trac_sbeio;

class PsuSendCoreConfigTest : public CxxTest::TestSuite
{
    public:

    /**
     *  @brief Test setting the PSU command with the Core config info
     *
     *  The decision to implement the cross check is intentional.
     *
     */
    void testCoreConfigInfo(void)
    {
        TRACFCOMP(g_trac_sbeio, ENTER_MRK"PsuSendCoreConfigTest: testCoreConfigInfo");
        errlHndl_t l_err = nullptr;

        // Create a vector of Target pointers to hold the targets.
        TargetHandleList l_procTargetList;
        getAllChips(l_procTargetList, TYPE_PROC, true);

        for ( const auto & l_procTarget: l_procTargetList )
        {
            // Create a PSU command message and initialize it with Core Config specific flags
            SbePsu::psuCommand l_psuCommand(
                        SbePsu::SBE_REQUIRE_RESPONSE |
                        SbePsu::SBE_REQUIRE_ACK,           // control flags
                        SbePsu::SBE_PSU_CLASS_CORE_STATE,  // command class (0xD1)
                        SbePsu::SBE_CMD_CORE_CONFIG);      // command (0x03)


            // Validate the PSU command's reserved 1 (control flags) has not been modified
            if ( l_psuCommand.cd7_sendCoreConfig_ControlFlags !=
                 (SbePsu::SBE_REQUIRE_RESPONSE | SbePsu::SBE_REQUIRE_ACK) )
            {
                TS_FAIL("testCoreConfigInfo: PSU command, Reserved1 (control "
                        "flags) mismatch, expected(0x%.8X) but found(0x%.8X)",
                        (SbePsu::SBE_REQUIRE_RESPONSE | SbePsu::SBE_REQUIRE_ACK),
                        l_psuCommand.cd7_sendCoreConfig_ControlFlags );
            }

            // Validate the PSU command's sequence id has not been modified
            if ( l_psuCommand.cd7_sendCoreConfig_SeqID != 0)
            {
                TS_FAIL("testCoreConfigInfo: PSU command, sequence ID "
                        "mismatch, expected(0) but found(0x%.8X)",
                        l_psuCommand.cd7_sendCoreConfig_SeqID );
            }


            // Validate the PSU command class has not been modified
            if ( l_psuCommand.cd7_sendCoreConfig_CommandClass !=
                 SbePsu::SBE_PSU_CLASS_CORE_STATE )
            {
                TS_FAIL("testCoreConfigInfo: PSU command class "
                        "mismatch, expected(0x%.8X) but found(0x%.8X)",
                        SbePsu::SBE_PSU_CLASS_CORE_STATE,
                        l_psuCommand.cd7_sendCoreConfig_CommandClass );
            }

            // Validate the PSU command has not been modified
            if ( l_psuCommand.cd7_sendCoreConfig_Command !=
                 SbePsu::SBE_CMD_CORE_CONFIG )
            {
                TS_FAIL("testCoreConfigInfo: PSU command "
                        "mismatch, expected(0x%.8X) but found(0x%.8X)",
                        SbePsu::SBE_CMD_CORE_CONFIG,
                        l_psuCommand.cd7_sendCoreConfig_Command );
            }

            // Create a PSU response message
            SbePsu::psuResponse l_psuResponse;
            bool command_unsupported =false;

            // Make the call to perform the PSU Chip Operation
            // NOTE: Once the new SBE image is available in simics we can
            // change to ERRL_SERV_PREDICTIVE
            l_err = SbePsu::getTheInstance().performPsuChipOp(
                            l_procTarget,
                            &l_psuCommand,
                            &l_psuResponse,
                            SbePsu::MAX_PSU_SHORT_TIMEOUT_NS,
                            SbePsu::SBE_CORE_CONFIG_REQ_USED_REGS,
                            SbePsu::SBE_CORE_CONFIG_RSP_USED_REGS,
                            SbePsu::unsupported_command_error_severity { ERRORLOG::ERRL_SEV_INFORMATIONAL },
                            &command_unsupported);
            if ( command_unsupported )
            {
                TS_INFO("testCoreConfigInfo: SBE firmware "
                        "does not support PSU sending Core configuration information" );
                errlCommit(l_err, CXXTEST_COMP_ID);
                break;
            }
            else if (l_err)
            {
                TRACFCOMP( g_trac_sbeio, ERR_MRK"testCoreConfigInfo: ERROR: "
                           "Call to performPsuChipOp failed, error returned" );
                TS_FAIL("testCoreConfigInfo: ERROR: "
                        "Call to performPsuChipOp failed. RC 0x%.8X", l_err->reasonCode());
                errlCommit(l_err, CXXTEST_COMP_ID);
                break;
            }
            else if (SBE_PRI_OPERATION_SUCCESSFUL != l_psuResponse.primaryStatus)
            {
                TS_FAIL("testCoreConfigInfo: ERROR: "
                          "Call to performPsuChipOp failed. Returned primary status "
                          "(0x%.4X) and secondary status (0x%.4X)",
                          l_psuResponse.primaryStatus,
                          l_psuResponse.secondaryStatus);
                // Collect the entire command and response buffers
                SBE_TRACFBIN("Send Core Config full command:",
                             &l_psuCommand, sizeof(l_psuCommand));
                SBE_TRACFBIN("Send Core Config full response:",
                             &l_psuResponse, sizeof(l_psuResponse));
                break;
            }

        } // for ( const auto l_procTarget: l_procTargetList )

        TRACFCOMP(g_trac_sbeio, EXIT_MRK"PsuSendCoreConfigTest: testCoreConfigInfo");
    } // void testCoreConfigInfo(void)
};  //  using namespace SBEIO;

#endif  //  __SBE_PSU_SEND_PMIC_CONFIG_TEST_H
