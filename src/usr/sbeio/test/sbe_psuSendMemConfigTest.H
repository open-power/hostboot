/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/test/sbe_psuSendMemConfigTest.H $               */
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
#ifndef __SBE_PSU_SEND_PMIC_CONFIG_TEST_H
#define __SBE_PSU_SEND_PMIC_CONFIG_TEST_H

/**
 *  @file sbe_psuSendMemConfigTest.H
 *
 *  @brief Test cases for setting up the PSU Command with Memory config info
*/

#include <cxxtest/TestSuite.H>


#include <sbeio/sbe_psudd.H>                   // SbePsu::psuCommand
#include <targeting/common/commontargeting.H>  // get_huid
#include <targeting/common/utilFilter.H>       // getAllChips


#define SBE_TRACFBIN(printf_string,args...) \
    TRACFBIN(g_trac_sbeio, "PsuSendMemConfigTest: testMemConfigInfo " printf_string,##args)

namespace SBEIO
{
    // Forward declarion of getMemConfigInfo
    uint32_t getMemConfigInfo(const TargetHandle_t i_pProc,
                               CLASS i_class,
                               TYPE i_type,
                               uint32_t i_max_number,
                               SbePsu::MemConfigData_t * i_buffer);

}

using namespace SBEIO;

extern trace_desc_t* g_trac_sbeio;

// The following structures need to align with MemConfigData_t
// from src/include/usr/sbeio/sbe_psudd.H
// These are manually created here to validate independently

uint32_t l_pmic_HuidArray[SbePsu::SBE_PMIC_CONFIG_MAX_NUMBER];
uint32_t l_generic_HuidArray[SbePsu::SBE_GENERIC_I2C_CONFIG_MAX_NUMBER];
uint32_t l_ocmb_HuidArray[SbePsu::SBE_OCMB_CONFIG_MAX_NUMBER];


class PsuSendMemConfigTest : public CxxTest::TestSuite
{
    public:

    /**
     *  @brief Test setting the PSU command with the Memory config info
     *
     *  The decision to implement the cross check is intentional.
     *
     *  Any enhancements to optimize the cross check ended up duplicating
     *  the original logic in getMemConfigInfo, so this methodology is explicitly
     *  left using simple arrays to cross check the structure population.
     */
    void testMemConfigInfo(void)
    {
        TRACFCOMP(g_trac_sbeio, ENTER_MRK"PsuSendMemConfigTest: testMemConfigInfo");
        errlHndl_t l_err = nullptr;

        // Create a vector of Target pointers to hold the targets.
        TargetHandleList l_procTargetList;
        getAllChips(l_procTargetList, TYPE_PROC, true);

        void* l_sbeMemAlloc = nullptr;
        SBEIO::sbeAllocationHandle_t l_MemConfigAlloc { };
        SbePsu::MemConfigData_t l_i2c_telemetry_data { };

        // For completeness, set the version and supported types and max values
        // We don't really validate this data since its set by us
        // and consumed by SBE, i.e. we could check its equal to this
        // value, but why ?
        // Set here for awareness and to match the TRACFBIN
        // output sections in hbTracMERG if desired during visual review
        l_i2c_telemetry_data.i2c_config_version = SbePsu::SBE_PSU_I2C_CONFIG_VERSION_LATEST;
        l_i2c_telemetry_data.i2c_config_types_supported = SbePsu::SBE_PSU_I2C_CONFIG_TYPES_SUPPORTED;
        l_i2c_telemetry_data.pmic_chips_max_number = SbePsu::SBE_PMIC_CONFIG_MAX_NUMBER;
        l_i2c_telemetry_data.gi2c_chips_max_number = SbePsu::SBE_GENERIC_I2C_CONFIG_MAX_NUMBER;
        l_i2c_telemetry_data.ocmb_chips_max_number = SbePsu::SBE_OCMB_CONFIG_MAX_NUMBER;

        for ( const auto & l_procTarget: l_procTargetList )
        {
            // Clear these variables, before populating them with data
            memset(l_pmic_HuidArray, 0, SbePsu::SBE_PMIC_CONFIG_MAX_NUMBER);
            memset(l_generic_HuidArray, 0, SbePsu::SBE_GENERIC_I2C_CONFIG_MAX_NUMBER);
            memset(l_ocmb_HuidArray, 0, SbePsu::SBE_OCMB_CONFIG_MAX_NUMBER);

            // Get the PMIC targets associated with the PROC target
            // UTIL_FILTER_ALL will retrieve ALL BLUEPRINT
            TargetHandleList l_pmicTargetList;
            getChildAffinityTargetsByState( l_pmicTargetList,
                                            l_procTarget,
                                            CLASS_NA,
                                            TYPE_PMIC,
                                            UTIL_FILTER_ALL);


            // Gather the Memory config info to do a comparison with
            for ( const auto & l_pmicTarget: l_pmicTargetList )
            {
                // Get the FAPI position of the target.  The FAPI position will
                // be used as an index into PSU command message.
                const ATTR_FAPI_POS_type l_fapiPos
                    = l_pmicTarget->getAttr<ATTR_FAPI_POS>();
                uint32_t l_arrayIndex = l_fapiPos % SbePsu::SBE_PMIC_CONFIG_MAX_NUMBER;

                // Cache the HUID for tracing/debugging means
                l_pmic_HuidArray[l_arrayIndex] = get_huid(l_pmicTarget);

                // Get the FAPI I2C control info from the target. The port info,
                // engine and device address resides within the FAPI I2C control info.
                ATTR_FAPI_I2C_CONTROL_INFO_type l_fapiI2cControlInfo
                    = l_pmicTarget->getAttr<ATTR_FAPI_I2C_CONTROL_INFO>();

                ATTR_FAPI_I2C_CONTROL_INFO_type l_dynamic_I2cControlInfo = { };

                // If the target has dynamic device address attribute, then use that instead of the
                // read-only address found in ATTR_FAPI_I2C_CONTROL_INFO. We use the dynamic address
                // attribute because ATTR_FAPI_I2C_CONTROL_INFO is not writable and its difficult
                // to override complex attributes.
                if (l_pmicTarget->tryGetAttr<TARGETING::ATTR_DYNAMIC_I2C_DEVICE_ADDRESS>(l_dynamic_I2cControlInfo.devAddr))
                {
                    l_fapiI2cControlInfo.devAddr = l_dynamic_I2cControlInfo.devAddr;
                }

                // Gather the port info, engine and device address of the target
                l_i2c_telemetry_data.pmic_chips[l_arrayIndex].i2c_port= l_fapiI2cControlInfo.port;
                l_i2c_telemetry_data.pmic_chips[l_arrayIndex].i2c_engine = l_fapiI2cControlInfo.engine;
                l_i2c_telemetry_data.pmic_chips[l_arrayIndex].i2c_devAddr = l_fapiI2cControlInfo.devAddr;

                // Gather the functional state of the target
                l_i2c_telemetry_data.pmic_chips[l_arrayIndex].i2c_functional
                    = l_pmicTarget->getAttr<TARGETING::ATTR_HWAS_STATE>().functional;
                // Gather the present state of the target
                l_i2c_telemetry_data.pmic_chips[l_arrayIndex].i2c_present
                    = l_pmicTarget->getAttr<TARGETING::ATTR_HWAS_STATE>().present;
            } // for ( const auto l_pmicTarget: l_pmicTargetList )

            // Get the GENERIC targets associated with the PROC target
            // UTIL_FILTER_ALL will retrieve ALL BLUEPRINT
            TargetHandleList l_genericTargetList;
            getChildAffinityTargetsByState( l_genericTargetList,
                                            l_procTarget,
                                            CLASS_NA,
                                            TYPE_GENERIC_I2C_DEVICE,
                                            UTIL_FILTER_ALL);


            // Gather the Memory config info to do a comparison with
            for ( const auto & l_genericTarget: l_genericTargetList )
            {
                // Get the FAPI position of the target.  The FAPI position will
                // be used as an index into PSU command message.
                const ATTR_FAPI_POS_type l_fapiPos
                    = l_genericTarget->getAttr<ATTR_FAPI_POS>();
                uint32_t l_arrayIndex = l_fapiPos % SbePsu::SBE_GENERIC_I2C_CONFIG_MAX_NUMBER;

                // Cache the HUID for tracing/debugging means
                l_generic_HuidArray[l_arrayIndex] = get_huid(l_genericTarget);

                // Get the FAPI I2C control info from the target. The port info,
                // engine and device address resides within the FAPI I2C control info.
                ATTR_FAPI_I2C_CONTROL_INFO_type l_fapiI2cControlInfo
                    = l_genericTarget->getAttr<ATTR_FAPI_I2C_CONTROL_INFO>();

                ATTR_FAPI_I2C_CONTROL_INFO_type l_dynamic_I2cControlInfo = { };

                // If the target has dynamic device address attribute, then use that instead of the
                // read-only address found in ATTR_FAPI_I2C_CONTROL_INFO. We use the dynamic address
                // attribute because ATTR_FAPI_I2C_CONTROL_INFO is not writable and its difficult
                // to override complex attributes.
                if (l_genericTarget->tryGetAttr<TARGETING::ATTR_DYNAMIC_I2C_DEVICE_ADDRESS>(l_dynamic_I2cControlInfo.devAddr))
                {
                    l_fapiI2cControlInfo.devAddr = l_dynamic_I2cControlInfo.devAddr;
                }

                // Gather the port info, engine and device address of the target
                l_i2c_telemetry_data.gi2c_chips[l_arrayIndex].i2c_port = l_fapiI2cControlInfo.port;
                l_i2c_telemetry_data.gi2c_chips[l_arrayIndex].i2c_engine = l_fapiI2cControlInfo.engine;
                l_i2c_telemetry_data.gi2c_chips[l_arrayIndex].i2c_devAddr = l_fapiI2cControlInfo.devAddr;

                // Gather the functional state of the target
                l_i2c_telemetry_data.gi2c_chips[l_arrayIndex].i2c_functional
                    = l_genericTarget->getAttr<TARGETING::ATTR_HWAS_STATE>().functional;
                // Gather the present state of the target
                l_i2c_telemetry_data.gi2c_chips[l_arrayIndex].i2c_present
                    = l_genericTarget->getAttr<TARGETING::ATTR_HWAS_STATE>().present;
            } // for ( const auto l_genericTarget: l_genericTargetList )

            // Get the OCMB targets associated with the PROC target
            // UTIL_FILTER_ALL will retrieve ALL BLUEPRINT
            TargetHandleList l_ocmbTargetList;
            getChildAffinityTargetsByState( l_ocmbTargetList,
                                            l_procTarget,
                                            CLASS_CHIP,
                                            TYPE_OCMB_CHIP,
                                            UTIL_FILTER_ALL);


            // Gather the Memory config info to do a comparison with
            for ( const auto & l_ocmbTarget: l_ocmbTargetList )
            {
                // Get the FAPI position of the target.  The FAPI position will
                // be used as an index into PSU command message.
                const ATTR_FAPI_POS_type l_fapiPos
                    = l_ocmbTarget->getAttr<ATTR_FAPI_POS>();
                uint32_t l_arrayIndex = l_fapiPos % SbePsu::SBE_OCMB_CONFIG_MAX_NUMBER;

                // Cache the HUID for tracing/debugging means
                l_ocmb_HuidArray[l_arrayIndex] = get_huid(l_ocmbTarget);

                // Get the FAPI I2C control info from the target. The port info,
                // engine and device address resides within the FAPI I2C control info.
                const ATTR_FAPI_I2C_CONTROL_INFO_type l_fapiI2cControlInfo
                    = l_ocmbTarget->getAttr<ATTR_FAPI_I2C_CONTROL_INFO>();

                // Gather the port info, engine and device address of the target
                l_i2c_telemetry_data.ocmb_chips[l_arrayIndex].i2c_port = l_fapiI2cControlInfo.port;
                l_i2c_telemetry_data.ocmb_chips[l_arrayIndex].i2c_engine = l_fapiI2cControlInfo.engine;
                l_i2c_telemetry_data.ocmb_chips[l_arrayIndex].i2c_devAddr = l_fapiI2cControlInfo.devAddr;

                // Gather the functional state of the target
                l_i2c_telemetry_data.ocmb_chips[l_arrayIndex].i2c_functional
                    = l_ocmbTarget->getAttr<TARGETING::ATTR_HWAS_STATE>().functional;
                // Gather the present state of the target
                l_i2c_telemetry_data.ocmb_chips[l_arrayIndex].i2c_present
                    = l_ocmbTarget->getAttr<TARGETING::ATTR_HWAS_STATE>().present;
            } // for ( const auto l_ocmbTarget: l_ocmbTargetList )

            // POPULATED l_i2c_telemetry_data LOCAL BUFFER
            SBE_TRACFBIN("POPULATED l_i2c_telemetry_data MATCH ME to POPULATED l_sbeMalloc:",
                         &l_i2c_telemetry_data, sizeof(SbePsu::MemConfigData_t));

            // Create a PSU command message and initialize it with Memory Config specific flags
            SbePsu::psuCommand l_psuCommand(
                        SbePsu::SBE_REQUIRE_RESPONSE |
                        SbePsu::SBE_REQUIRE_ACK,          // control flags
                        SbePsu::SBE_PSU_GENERIC_MESSAGE,  // command class (0xD7)
                        SbePsu::SBE_CMD_MEM_CONFIG);      // command (0x0B)


            // Populate the PSU command with the Memory config info
            l_MemConfigAlloc = sbeMalloc(sizeof(SbePsu::MemConfigData_t), l_sbeMemAlloc);
            // memset the virtual address to zeros to assure data buffer properly initialized
            memset(l_sbeMemAlloc, 0, sizeof(SbePsu::MemConfigData_t));

            // SBE consumes a physical address
            // Assumed the virtual pages returned by malloc are backed by contiguous physical pages

            TRACFCOMP(g_trac_sbeio, "psuSendSbeMemConfig: SBE indirect data at address 0x%lx "
                "l_sbeMemAlloc=0x%X sizeof(MemConfigData_t)=0x%X",
                l_MemConfigAlloc.physAddr, l_sbeMemAlloc, sizeof(SbePsu::MemConfigData_t));

            l_psuCommand.cd7_sendMemConfig_DataAddr = l_MemConfigAlloc.physAddr;

            uint32_t l_total_mem_targets_processed = 0;
            uint32_t l_current_targets_processed = 0;
            l_current_targets_processed = getMemConfigInfo(l_procTarget, CLASS_NA,
                                          TYPE_PMIC,
                                          SbePsu::SBE_PMIC_CONFIG_MAX_NUMBER,
                                          reinterpret_cast<SbePsu::MemConfigData_t *>(l_sbeMemAlloc));
            l_total_mem_targets_processed += l_current_targets_processed;
            if (l_current_targets_processed > SbePsu::SBE_PMIC_CONFIG_MAX_NUMBER)
            {
                TS_FAIL("testMemConfigInfo: Processed %d "
                    "PMICs but MAX is SBE_PMIC_CONFIG_MAX_NUMBER of %d",
                    l_current_targets_processed, SbePsu::SBE_PMIC_CONFIG_MAX_NUMBER);
            }
            else
            {
                TS_INFO("testMemConfigInfo: Completed processing %d "
                    "PMICs and MAX is SBE_PMIC_CONFIG_MAX_NUMBER of %d",
                    l_current_targets_processed, SbePsu::SBE_PMIC_CONFIG_MAX_NUMBER);
            }

            l_current_targets_processed = getMemConfigInfo(l_procTarget, CLASS_NA,
                                          TYPE_GENERIC_I2C_DEVICE,
                                          SbePsu::SBE_GENERIC_I2C_CONFIG_MAX_NUMBER,
                                          reinterpret_cast<SbePsu::MemConfigData_t *>(l_sbeMemAlloc));
            l_total_mem_targets_processed += l_current_targets_processed;
            if (l_current_targets_processed > SbePsu::SBE_GENERIC_I2C_CONFIG_MAX_NUMBER)
            {
                TS_FAIL("testMemConfigInfo: Processed %d GENERIC I2Cs "
                    "but MAX is SBE_GENERIC_I2C_CONFIG_MAX_NUMBER of %d",
                    l_current_targets_processed, SbePsu::SBE_GENERIC_I2C_CONFIG_MAX_NUMBER);
            }
            else
            {
                TS_INFO("testMemConfigInfo: Completed processing %d "
                    "GENERIC I2Cs and MAX is SBE_GENERIC_I2C_CONFIG_MAX_NUMBER of %d",
                    l_current_targets_processed, SbePsu::SBE_GENERIC_I2C_CONFIG_MAX_NUMBER);
            }

            l_current_targets_processed = getMemConfigInfo(l_procTarget, CLASS_CHIP,
                                          TYPE_OCMB_CHIP,
                                          SbePsu::SBE_OCMB_CONFIG_MAX_NUMBER,
                                          reinterpret_cast<SbePsu::MemConfigData_t *>(l_sbeMemAlloc));
            l_total_mem_targets_processed += l_current_targets_processed;
            if (l_current_targets_processed > SbePsu::SBE_OCMB_CONFIG_MAX_NUMBER)
            {
                TS_FAIL("testMemConfigInfo: Processed %d OCMBs "
                    "but MAX is SBE_OCMB_CONFIG_MAX_NUMBER of %d",
                    l_current_targets_processed, SbePsu::SBE_OCMB_CONFIG_MAX_NUMBER);
            }
            else
            {
                TS_INFO("testMemConfigInfo: Completed processing %d "
                    "OCMBs and MAX is SBE_OCMB_CONFIG_MAX_NUMBER of %d",
                    l_current_targets_processed, SbePsu::SBE_OCMB_CONFIG_MAX_NUMBER);
            }

            // Cache the PROC's HUID for tracing
            auto l_procHuid = get_huid(l_procTarget);

            // Validate the PSU command's reserved0 data has not been modified
            if ( l_psuCommand.cd7_sendMemConfig_Reserved0 != 0)
            {
                TS_FAIL("testMemConfigInfo: PSU command, Reserved0 "
                        "mismatch, expected(0) but found(0x%.8X)",
                        l_psuCommand.cd7_sendMemConfig_Reserved0 );
            }

            // Validate the PSU command's reserved 1 (control flags) has not been modified
            if ( l_psuCommand.cd7_sendMemConfig_ControlFlags !=
                 (SbePsu::SBE_REQUIRE_RESPONSE | SbePsu::SBE_REQUIRE_ACK) )
            {
                TS_FAIL("testMemConfigInfo: PSU command, Reserved1 (control "
                        "flags) mismatch, expected(0x%.8X) but found(0x%.8X)",
                        (SbePsu::SBE_REQUIRE_RESPONSE | SbePsu::SBE_REQUIRE_ACK),
                        l_psuCommand.cd7_sendMemConfig_ControlFlags );
            }

            // Validate the PSU command's sequence id has not been modified
            if ( l_psuCommand.cd7_sendMemConfig_SeqID != 0)
            {
                TS_FAIL("testMemConfigInfo: PSU command, sequence ID "
                        "mismatch, expected(0) but found(0x%.8X)",
                        l_psuCommand.cd7_sendMemConfig_SeqID );
            }


            // Validate the PSU command class has not been modified
            if ( l_psuCommand.cd7_sendMemConfig_CommandClass !=
                 SbePsu::SBE_PSU_GENERIC_MESSAGE )
            {
                TS_FAIL("testMemConfigInfo: PSU command class "
                        "mismatch, expected(0x%.8X) but found(0x%.8X)",
                        SbePsu::SBE_PSU_GENERIC_MESSAGE,
                        l_psuCommand.cd7_sendMemConfig_CommandClass );
            }

            // Validate the PSU command has not been modified
            if ( l_psuCommand.cd7_sendMemConfig_Command !=
                 SbePsu::SBE_CMD_MEM_CONFIG )
            {
                TS_FAIL("testMemConfigInfo: PSU command "
                        "mismatch, expected(0x%.8X) but found(0x%.8X)",
                        SbePsu::SBE_CMD_MEM_CONFIG,
                        l_psuCommand.cd7_sendMemConfig_Command );
            }

            // Validate the PMICs
            for ( const auto & l_pmicTarget: l_pmicTargetList )
            {
                // Get the FAPI position of the target.  The FAPI position will
                // be used as an index into PSU command message.
                const ATTR_FAPI_POS_type l_fapiPos
                    = l_pmicTarget->getAttr<ATTR_FAPI_POS>();
                uint32_t i = l_fapiPos % SbePsu::SBE_PMIC_CONFIG_MAX_NUMBER;
                SbePsu::MemConfigData_t * l_testMemAlloc = reinterpret_cast<SbePsu::MemConfigData_t *>(l_sbeMemAlloc);

                if ( l_i2c_telemetry_data.pmic_chips[i].i2c_port != l_testMemAlloc->pmic_chips[i].i2c_port )
                {
                    TS_FAIL("testMemConfigInfo: i=%d PROC(0x%X): PMIC(0x%X) port "
                            "mismatch, expected i2c_port (0x%X) but found l_testMemAlloc->pmic_chips[i].i2c_port (0x%X)",
                            i,
                            l_procHuid,
                            l_pmic_HuidArray[i],
                            l_i2c_telemetry_data.pmic_chips[i].i2c_port,
                            l_testMemAlloc->pmic_chips[i].i2c_port);
                }
                if ( l_i2c_telemetry_data.pmic_chips[i].i2c_engine != l_testMemAlloc->pmic_chips[i].i2c_engine )
                {
                    TS_FAIL("testMemConfigInfo: i=%d PROC(0x%X): PMIC(0x%X) engine "
                            "mismatch, expected i2c_engine (0x%X) but found l_testMemAlloc->pmic_chips[i].i2c_engine (0x%X)",
                            i,
                            l_procHuid,
                            l_pmic_HuidArray[i],
                            l_i2c_telemetry_data.pmic_chips[i].i2c_engine,
                            l_testMemAlloc->pmic_chips[i].i2c_engine);
                }
                if ( l_i2c_telemetry_data.pmic_chips[i].i2c_devAddr != l_testMemAlloc->pmic_chips[i].i2c_devAddr )
                {
                    TS_FAIL("testMemConfigInfo: i=%d PROC(0x%X): PMIC(0x%X) devAddr "
                            "mismatch, expected i2c_devAddr (0x%X) but found l_testMemAlloc->pmic_chips[i].i2c_devAddr (0x%X)",
                            i,
                            l_procHuid,
                            l_pmic_HuidArray[i],
                            l_i2c_telemetry_data.pmic_chips[i].i2c_devAddr,
                            l_testMemAlloc->pmic_chips[i].i2c_devAddr);
                }
                if ( l_i2c_telemetry_data.pmic_chips[i].i2c_functional != l_testMemAlloc->pmic_chips[i].i2c_functional)
                {
                    {
                        TS_FAIL("testMemConfigInfo: i=%d PROC(0x%X): PMIC(0x%X) functional state "
                                "mismatch, expected i2c_functional (0x%X) but found l_testMemAlloc->pmic_chips[i].i2c_functional (0x%X)",
                                i,
                                l_procHuid,
                                l_pmic_HuidArray[i],
                                l_i2c_telemetry_data.pmic_chips[i].i2c_functional,
                                l_testMemAlloc->pmic_chips[i].i2c_functional);
                    }
                }
                if ( l_i2c_telemetry_data.pmic_chips[i].i2c_present != l_testMemAlloc->pmic_chips[i].i2c_present)
                {
                    {
                        TS_FAIL("testMemConfigInfo: i=%d PROC(0x%X): PMIC(0x%X) present state "
                                "mismatch, expected i2c_present (0x%X) but found l_testMemAlloc->pmic_chips[i].i2c_present (0x%X)",
                                i,
                                l_procHuid,
                                l_pmic_HuidArray[i],
                                l_i2c_telemetry_data.pmic_chips[i].i2c_present,
                                l_testMemAlloc->pmic_chips[i].i2c_present);
                    }
                }
            } // for ( const auto l_pmicTarget: l_pmicTargetList )

            // Validate the GENERICs
            for ( const auto & l_genericTarget: l_genericTargetList )
            {
                // Get the FAPI position of the target.  The FAPI position will
                // be used as an index into PSU command message.
                const ATTR_FAPI_POS_type l_fapiPos
                    = l_genericTarget->getAttr<ATTR_FAPI_POS>();
                uint32_t i = l_fapiPos % SbePsu::SBE_GENERIC_I2C_CONFIG_MAX_NUMBER;
                SbePsu::MemConfigData_t * l_testMemAlloc = reinterpret_cast<SbePsu::MemConfigData_t *>(l_sbeMemAlloc);

                if ( l_i2c_telemetry_data.gi2c_chips[i].i2c_port != l_testMemAlloc->gi2c_chips[i].i2c_port )
                {
                    TS_FAIL("testMemConfigInfo: i=%d PROC(0x%X): GENERIC(0x%X) port "
                            "mismatch, expected i2c_port (0x%X) but found l_testMemAlloc->gi2c_chips[i].i2c_port (0x%X)",
                            i,
                            l_procHuid,
                            l_generic_HuidArray[i],
                            l_i2c_telemetry_data.gi2c_chips[i].i2c_port,
                            l_testMemAlloc->gi2c_chips[i].i2c_port);
                }
                if ( l_i2c_telemetry_data.gi2c_chips[i].i2c_engine != l_testMemAlloc->gi2c_chips[i].i2c_engine )
                {
                    TS_FAIL("testMemConfigInfo: i=%d PROC(0x%X): GENERIC(0x%X) engine "
                            "mismatch, expected i2c_engine (0x%X) but found l_testMemAlloc->gi2c_chips[i].i2c_engine (0x%X)",
                            i,
                            l_procHuid,
                            l_generic_HuidArray[i],
                            l_i2c_telemetry_data.gi2c_chips[i].i2c_engine,
                            l_testMemAlloc->gi2c_chips[i].i2c_engine);
                }
                if ( l_i2c_telemetry_data.gi2c_chips[i].i2c_devAddr != l_testMemAlloc->gi2c_chips[i].i2c_devAddr )
                {
                    TS_FAIL("testMemConfigInfo: i=%d PROC(0x%X): GENERIC(0x%X) devAddr "
                            "mismatch, expected l_generic_devAddrArray (0x%X) but found l_testMemAlloc->gi2c_chips[i].i2c_devAddr (0x%X)",
                            i,
                            l_procHuid,
                            l_generic_HuidArray[i],
                            l_i2c_telemetry_data.gi2c_chips[i].i2c_devAddr,
                            l_testMemAlloc->gi2c_chips[i].i2c_devAddr);
                }
                if ( l_i2c_telemetry_data.gi2c_chips[i].i2c_functional != l_testMemAlloc->gi2c_chips[i].i2c_functional)
                {
                    {
                        TS_FAIL("testMemConfigInfo: i=%d PROC(0x%X): GENERIC(0x%X) functional state "
                                "mismatch, expected i2c_functional (0x%X) but found l_testMemAlloc->gi2c_chips[i].i2c_functional (0x%X)",
                                i,
                                l_procHuid,
                                l_generic_HuidArray[i],
                                l_i2c_telemetry_data.gi2c_chips[i].i2c_functional,
                                l_testMemAlloc->gi2c_chips[i].i2c_functional);
                    }
                }
                if ( l_i2c_telemetry_data.gi2c_chips[i].i2c_present != l_testMemAlloc->gi2c_chips[i].i2c_present)
                {
                    {
                        TS_FAIL("testMemConfigInfo: i=%d PROC(0x%X): GENERIC(0x%X) present state "
                                "mismatch, expected i2c_present (0x%X) but found l_testMemAlloc->gi2c_chips[i].i2c_present (0x%X)",
                                i,
                                l_procHuid,
                                l_generic_HuidArray[i],
                                l_i2c_telemetry_data.gi2c_chips[i].i2c_present,
                                l_testMemAlloc->gi2c_chips[i].i2c_present);
                    }
                }
            } // for ( const auto l_genericTarget: l_genericTargetList )

            // Validate the OCMBs
            for ( const auto & l_ocmbTarget: l_ocmbTargetList )
            {
                // Get the FAPI position of the target.  The FAPI position will
                // be used as an index into PSU command message.
                const ATTR_FAPI_POS_type l_fapiPos
                    = l_ocmbTarget->getAttr<ATTR_FAPI_POS>();
                uint32_t i = l_fapiPos % SbePsu::SBE_OCMB_CONFIG_MAX_NUMBER;
                SbePsu::MemConfigData_t * l_testMemAlloc = reinterpret_cast<SbePsu::MemConfigData_t *>(l_sbeMemAlloc);

                if ( l_i2c_telemetry_data.ocmb_chips[i].i2c_port != l_testMemAlloc->ocmb_chips[i].i2c_port )
                {
                    TS_FAIL("testMemConfigInfo: i=%d PROC(0x%X): OCMB(0x%X) port "
                            "mismatch, expected i2c_port (0x%X) but found l_testMemAlloc->ocmb_chips[i].i2c_port (0x%X)",
                            i,
                            l_procHuid,
                            l_ocmb_HuidArray[i],
                            l_i2c_telemetry_data.ocmb_chips[i].i2c_port,
                            l_testMemAlloc->ocmb_chips[i].i2c_port);
                }
                if ( l_i2c_telemetry_data.ocmb_chips[i].i2c_engine != l_testMemAlloc->ocmb_chips[i].i2c_engine )
                {
                    TS_FAIL("testMemConfigInfo: i=%d PROC(0x%X): OCMB(0x%X) engine "
                            "mismatch, expected i2c_engine (0x%X) but found l_testMemAlloc->ocmb_chips[i].i2c_engine (0x%X)",
                            i,
                            l_procHuid,
                            l_ocmb_HuidArray[i],
                            l_i2c_telemetry_data.ocmb_chips[i].i2c_engine,
                            l_testMemAlloc->ocmb_chips[i].i2c_engine);
                }
                if ( l_i2c_telemetry_data.ocmb_chips[i].i2c_devAddr != l_testMemAlloc->ocmb_chips[i].i2c_devAddr )
                {
                    TS_FAIL("testMemConfigInfo: i=%d PROC(0x%X): OCMB(0x%X) devAddr "
                            "mismatch, expected i2c_devAddr (0x%X) but found l_testMemAlloc->ocmb_chips[i].i2c_devAddr (0x%X)",
                            i,
                            l_procHuid,
                            l_ocmb_HuidArray[i],
                            l_i2c_telemetry_data.ocmb_chips[i].i2c_devAddr,
                            l_testMemAlloc->ocmb_chips[i].i2c_devAddr);
                }
                if ( l_i2c_telemetry_data.ocmb_chips[i].i2c_functional != l_testMemAlloc->ocmb_chips[i].i2c_functional)
                {
                    {
                        TS_FAIL("testMemConfigInfo: i=%d PROC(0x%X): OCMB(0x%X) functional state "
                                "mismatch, expected i2c_functional (0x%X) but found l_testMemAlloc->ocmb_chips[i].i2c_functional (0x%X)",
                                i,
                                l_procHuid,
                                l_ocmb_HuidArray[i],
                                l_i2c_telemetry_data.ocmb_chips[i].i2c_functional,
                                l_testMemAlloc->ocmb_chips[i].i2c_functional);
                    }
                }
                if ( l_i2c_telemetry_data.ocmb_chips[i].i2c_present != l_testMemAlloc->ocmb_chips[i].i2c_present)
                {
                    {
                        TS_FAIL("testMemConfigInfo: i=%d PROC(0x%X): OCMB(0x%X) present state "
                                "mismatch, expected i2c_present (0x%X) but found l_testMemAlloc->ocmb_chips[i].i2c_present (0x%X)",
                                i,
                                l_procHuid,
                                l_ocmb_HuidArray[i],
                                l_i2c_telemetry_data.ocmb_chips[i].i2c_present,
                                l_testMemAlloc->ocmb_chips[i].i2c_present);
                    }
                }
            } // for ( const auto l_ocmbTarget: l_ocmbTargetList )

        // Create a PSU response message
        SbePsu::psuResponse l_psuResponse;
        bool command_unsupported =false;

        // Make the call to perform the PSU Chip Operation
        l_err = SbePsu::getTheInstance().performPsuChipOp(
                        l_procTarget,
                        &l_psuCommand,
                        &l_psuResponse,
                        SbePsu::MAX_PSU_SHORT_TIMEOUT_NS,
                        SbePsu::SBE_MEM_CONFIG_REQ_USED_REGS,
                        SbePsu::SBE_MEM_CONFIG_RSP_USED_REGS,
                        SbePsu::unsupported_command_error_severity { ERRORLOG::ERRL_SEV_PREDICTIVE },
                        &command_unsupported);
        if ( command_unsupported )
        {
            TS_FAIL("testMemConfigInfo: ERROR: SBE firmware "
                    "does not support PSU sending Memory configuration information" );
            errlCommit(l_err, CXXTEST_COMP_ID);
            break;
        }
        else if (l_err)
        {
            TRACFCOMP( g_trac_sbeio, ERR_MRK"testMemConfigInfo: ERROR: "
                       "Call to performPsuChipOp failed, error returned" );
            TS_FAIL("testMemConfigInfo: ERROR: "
                    "Call to performPsuChipOp failed. RC 0x%.8X", l_err->reasonCode());
            errlCommit(l_err, CXXTEST_COMP_ID);
            break;
        }
        else if (SBE_PRI_OPERATION_SUCCESSFUL != l_psuResponse.primaryStatus)
        {
            TS_FAIL("testMemConfigInfo: ERROR: "
                      "Call to performPsuChipOp failed. Returned primary status "
                      "(0x%.4X) and secondary status (0x%.4X)",
                      l_psuResponse.primaryStatus,
                      l_psuResponse.secondaryStatus);
            // Collect the entire command and response buffers
            SBE_TRACFBIN("Send Memory Config full command:",
                         &l_psuCommand, sizeof(l_psuCommand));
            SBE_TRACFBIN("Send Memory Config full response:",
                         &l_psuResponse, sizeof(l_psuResponse));
            break;
        }

        } // for ( const auto l_procTarget: l_procTargetList )

        sbeFree(l_MemConfigAlloc);
        TRACFCOMP(g_trac_sbeio, EXIT_MRK"PsuSendMemConfigTest: testMemConfigInfo");
    } // void testMemConfigInfo(void)
};  //  using namespace SBEIO;

#endif  //  __SBE_PSU_SEND_PMIC_CONFIG_TEST_H
