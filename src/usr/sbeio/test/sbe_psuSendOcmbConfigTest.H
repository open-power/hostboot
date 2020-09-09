/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/test/sbe_psuSendOcmbConfigTest.H $              */
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
#ifndef __SBE_PSU_SEND_OCMB_CONFIG_TEST_H
#define __SBE_PSU_SEND_OCMB_CONFIG_TEST_H

/**
 *  @file sbe_psuSendOcmbConfigTest.H
 *
 *  @brief Test cases for setting up the PSU Command with OCMB config info
*/

#include <cxxtest/TestSuite.H>


#include <sbeio/sbe_psudd.H>                   // SbePsu::psuCommand
#include <targeting/common/commontargeting.H>  // get_huid
#include <targeting/common/utilFilter.H>       // getAllChips

namespace SBEIO
{
    // Forward declarion of getOcmbConfigInfo
    uint32_t getOcmbConfigInfo(const TargetHandle_t i_pProc,
                               SbePsu::psuCommand &io_psuCommand);
}

using namespace SBEIO;

extern trace_desc_t* g_trac_sbeio;

class PsuSendOcmbConfigTest : public CxxTest::TestSuite
{
    public:

    /**
     *  @brief Test setting the PSU command with the OCMB config info
     */
    void testOcmbConfigInfo(void)
    {
        TRACFCOMP(g_trac_sbeio, ENTER_MRK"PsuSendOcmbConfigTest: testOcmbConfigInfo");

        // Create a vector of Target pointers to hold the OCMB targets.
        TargetHandleList l_procTargetList;
        getAllChips(l_procTargetList, TYPE_PROC, true);

        // Create an array to hold the OCMBs HUIDs
        uint32_t l_ocmbHuidArray[SbePsu::SBE_OCMB_CONFIG_MAX_NUMBER_OF_PORTS];

        // Create an array to hold the port infos of the OCMBs
        uint8_t l_portInfoArray[SbePsu::SBE_OCMB_CONFIG_MAX_NUMBER_OF_PORTS];

        // Create an array to hold the functional states of the OCMBs
        uint8_t l_funtionalState[SbePsu::SBE_OCMB_CONFIG_MAX_NUMBER_OF_PORTS];

        // Variables to hold the OCMB engine and device address info
        uint8_t l_engine(0), l_devAddr(0);

        for ( const auto & l_procTarget: l_procTargetList )
        {
            // Clear these variables, before populating them with data
            memset(l_ocmbHuidArray, 0, SbePsu::SBE_OCMB_CONFIG_MAX_NUMBER_OF_PORTS);
            memset(l_portInfoArray, 0, SbePsu::SBE_OCMB_CONFIG_MAX_NUMBER_OF_PORTS);
            memset(l_funtionalState, 0, SbePsu::SBE_OCMB_CONFIG_MAX_NUMBER_OF_PORTS);
            l_engine = l_devAddr = 0;

            // Get the OCMBs associated with the PROC target
            TargetHandleList l_ocmbTargetList;
            getChildAffinityTargetsByState( l_ocmbTargetList,
                                            l_procTarget,
                                            CLASS_CHIP,
                                            TYPE_OCMB_CHIP,
                                            UTIL_FILTER_ALL);

            // Gather the OCMB config info to do a comparison with
            for ( const auto & l_ocmbTarget: l_ocmbTargetList )
            {
                // Get the FAPI position of the OCMB target.  The FAPI position will
                // be used as an index into PSU command message.
                const ATTR_FAPI_POS_type l_fapiPos
                    = l_ocmbTarget->getAttr<ATTR_FAPI_POS>();
                uint32_t l_arrayIndex = l_fapiPos % SbePsu::SBE_OCMB_CONFIG_MAX_NUMBER_OF_PORTS;

                // Cache the OCMB HUID for tracing/debugging means
                l_ocmbHuidArray[l_arrayIndex] = get_huid(l_ocmbTarget);

                // Get the FAPI I2C control info from the OCMB target. The port info,
                // engine and device address resides within the FAPI I2C control info.
                const ATTR_FAPI_I2C_CONTROL_INFO_type l_fapiI2cControlInfo
                    = l_ocmbTarget->getAttr<ATTR_FAPI_I2C_CONTROL_INFO>();

                // Gather the port info, engine and device address of the OCMB target
                l_portInfoArray[l_arrayIndex]= l_fapiI2cControlInfo.port;
                l_engine = l_fapiI2cControlInfo.engine;
                l_devAddr = l_fapiI2cControlInfo.devAddr;

                // Gather the functional state of the OCMB target
                l_funtionalState[l_arrayIndex]
                    = l_ocmbTarget->getAttr<TARGETING::ATTR_HWAS_STATE>().functional;
            } // for ( const auto l_ocmbTarget: l_ocmbTargetList )

            // Create a PSU command message and initialize it with OCMB Config specific flags
            SbePsu::psuCommand l_psuCommand(
                        SbePsu::SBE_REQUIRE_RESPONSE |
                        SbePsu::SBE_REQUIRE_ACK,          // control flags
                        SbePsu::SBE_PSU_GENERIC_MESSAGE,  // command class (0xD7)
                        SbePsu::SBE_PSU_OCMB_CONFIG);     // command (0x09)

            // Populate the PSU command with the OCMB config info
            getOcmbConfigInfo(l_procTarget, l_psuCommand);

            // Cache the PROC's HUID for tracing
            auto l_procHuid = get_huid(l_procTarget);

            // Validate the PSU command's reserved0 data has not been modified
            if ( l_psuCommand.cd7_sendOcmbConfig_Reserved0 != 0)
            {
                TS_FAIL("testOcmbConfigInfo: PSU command, Reserved0 "
                        "mismatch, expected(0) but found(0x%.8X)",
                        l_psuCommand.cd7_sendOcmbConfig_Reserved0 );
            }

            // Validate the PSU command's reserved 1 (control flags) has not been modified
            if ( l_psuCommand.cd7_sendOcmbConfig_Reserved1 !=
                 (SbePsu::SBE_REQUIRE_RESPONSE | SbePsu::SBE_REQUIRE_ACK) )
            {
                TS_FAIL("testOcmbConfigInfo: PSU command, Reserved1 (control "
                        "flags) mismatch, expected(0x%.8X) but found(0x%.8X)",
                        (SbePsu::SBE_REQUIRE_RESPONSE | SbePsu::SBE_REQUIRE_ACK),
                        l_psuCommand.cd7_sendOcmbConfig_Reserved1 );
            }

            // Validate the PSU command's sequence id has not been modified
            if ( l_psuCommand.cd7_sendOcmbConfig_SeqID != 0)
            {
                TS_FAIL("testOcmbConfigInfo: PSU command, sequence ID "
                        "mismatch, expected(0) but found(0x%.8X)",
                        l_psuCommand.cd7_sendOcmbConfig_SeqID );
            }


            // Validate the PSU command class has not been modified
            if ( l_psuCommand.cd7_sendOcmbConfig_CommandClass !=
                 SbePsu::SBE_PSU_GENERIC_MESSAGE )
            {
                TS_FAIL("testOcmbConfigInfo: PSU command class "
                        "mismatch, expected(0x%.8X) but found(0x%.8X)",
                        SbePsu::SBE_PSU_GENERIC_MESSAGE,
                        l_psuCommand.cd7_sendOcmbConfig_CommandClass );
            }

            // Validate the PSU command has not been modified
            if ( l_psuCommand.cd7_sendOcmbConfig_Command !=
                 SbePsu::SBE_PSU_OCMB_CONFIG )
            {
                TS_FAIL("testOcmbConfigInfo: PSU command "
                        "mismatch, expected(0x%.8X) but found(0x%.8X)",
                        SbePsu::SBE_PSU_OCMB_CONFIG,
                        l_psuCommand.cd7_sendOcmbConfig_Command );
            }

            // Check the validity of the data
            uint8_t * l_ocmbPortArray = static_cast<uint8_t *>
                                   ( &(l_psuCommand.cd7_sendOcmbConfig_I0_port) );

            // Validate the OCMB's port
            for (int i = 0; i < SbePsu::SBE_OCMB_CONFIG_MAX_NUMBER_OF_PORTS; ++i)
            {
                if ( l_portInfoArray[i] != l_ocmbPortArray[i] )
                {
                    TS_FAIL("testOcmbConfigInfo: PROC(0x%.8X): OCMB(0x%.8X) port "
                            "mismatch, expected(0x%.2X) but found(0x%.2X)",
                            l_procHuid,
                            l_ocmbHuidArray[i],
                            l_portInfoArray[i],
                            l_ocmbPortArray[i]);
                }
            }

            // Validate the OCMB's engine
            if (l_psuCommand.cd7_sendOcmbConfig_engine != l_engine)
            {
                TS_FAIL("testOcmbConfigInfo: PROC(0x%.8X): OCMB engine "
                        "mismatch, expected(0x%.2X) but found(0x%.2X)",
                        l_procHuid,
                        l_engine,
                        l_psuCommand.cd7_sendOcmbConfig_engine);
            }

            // Validate the OCMB's device address
            if (l_psuCommand.cd7_sendOcmbConfig_devAddr != l_devAddr)
            {
                TS_FAIL( "testOcmbConfigInfo: PROC(0x%.8X): OCMB device address "
                         "mismatch, expected(0x%.2X) but found(0x%.2X)",
                         l_procHuid,
                         l_devAddr,
                         l_psuCommand.cd7_sendOcmbConfig_devAddr );
            }

            // Create a mask to single out the last bit of a 16 bit integer
            const uint16_t l_functionalStateMask = 0x00001;
            // Cache the OCMB's functional state for manipulation
            uint16_t l_psuCommandFunctionalState = l_psuCommand.cd7_sendOcmbConfig_function_state;

            // Check the individual functional state which is represented by a bit
            for (int i = (SbePsu::SBE_OCMB_CONFIG_MAX_NUMBER_OF_PORTS - 1); i >= 0; --i)
            {
                // Validate the functional state
                if ( ( l_psuCommandFunctionalState & l_functionalStateMask) !=
                       l_funtionalState[i] )
                {
                    TS_FAIL( "testOcmbConfigInfo: PROC(0x%.8X): OCMB(0x%.8X) functional "
                             "state mismatch, expected(%d) but found(%d), where "
                             "1 represents functional and 0 non-functional",
                             l_procHuid,
                             l_ocmbHuidArray[i],
                             l_funtionalState[i],
                             l_psuCommandFunctionalState & l_functionalStateMask );
                }

                // Slide the functional state to the right to get next functional state
                l_psuCommandFunctionalState >>= 1;
            }

        } // for ( const auto l_procTarget: l_procTargetList )

        TRACFCOMP(g_trac_sbeio, EXIT_MRK"PsuSendOcmbConfigTest: testOcmbConfigInfo");
    } // void testOcmbConfigInfo(void)
};  //  using namespace SBEIO;

#endif  //  __SBE_PSU_SEND_OCMB_CONFIG_TEST_H
