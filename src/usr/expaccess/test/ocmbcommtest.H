/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/expaccess/test/ocmbcommtest.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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
#ifndef __OCMBCOMMTEST_H
#define __OCMBCOMMTEST_H
/**
 *  @file ocmbcommtest.H
 *
 *  @brief Test cases for OCMB communication protocol
 */
#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <fapi2.H>

#include <plat_hwp_invoker.H>
#include <exp_inband.H>
#include <exp_data_structs.H>
#include <generic/memory/lib/utils/endian_utils.H>
#include "exptest_utils.H"


// EXP_FW_ADAPTER_PROPERTIES_GET data response format
#define FW_ADAPTER_MAX_FW_IMAGE  4
#define FW_ADAPTER_CHIP_VERSION_SIZE  128
#define FW_ADAPTER_SPI_FLASH_ID_SIZE  32
typedef struct
{
    uint32_t fw_number_of_images;     // number of FW images
    uint32_t boot_partion_id;         // ID of current boot partion
    struct fw_version_string
    {
        uint32_t major;               // FW version - Major release
        uint32_t minor;               // FW version - Minor release
        uint32_t build_num;           // FW build number
        uint32_t build_patch;         // FW build path number
        uint32_t sector_size;         // FW sector size
    } fw_ver_str[FW_ADAPTER_MAX_FW_IMAGE];

    uint32_t ram_size_in_bytes;       // RAM size in bytes
    unsigned char chip_version[FW_ADAPTER_CHIP_VERSION_SIZE];  // Explorer chip revision
    unsigned char spi_flash_id[FW_ADAPTER_SPI_FLASH_ID_SIZE];  // SPI flash ID
    uint32_t spi_flash_size;          // SPI flash size in bytes
    uint32_t error_buffer_offset;     // FW error buffer offset in SPI flash
    uint32_t error_buffer_size;       // FW error buffer size in bytes
} FW_ADAPTER_PROPERTIES_type;


class OCMBCommTest: public CxxTest::TestSuite
{
  public:

    /**
     * @brief Fills in command structure for the EXP_FW_ADAPTER_PROPERTIES_GET cmd
     * @param io_cmd -- command that gets filled in
     */
    void buildPropertiesGetCmd(host_fw_command_struct & io_cmd)
    {
        io_cmd.cmd_id = 0x07;   // EXP_FW_ADAPTER_PROPERTIES_GET
        io_cmd.cmd_flags = 0x00; // no additional data
        io_cmd.request_identifier = 0x0203; // host generated id number
        io_cmd.cmd_length = 0x00000000; // length of addditional data
        io_cmd.cmd_crc = 0xFFFFFFFF; // CRC-32 of no additional data
        io_cmd.host_work_area = 0x00000000;
        io_cmd.cmd_work_area = 0x00000000;
        memset(io_cmd.padding, 0, sizeof(io_cmd.padding));
        memset(io_cmd.command_argument, 0, sizeof(io_cmd.command_argument));
    }

    /**
     *  @brief Convert structure from little endian format into big endian
     *  @param o_data -- big endian output
     *  @param i_data -- vector of little endian data
     *  @return true if successful, else false
     */
    bool fw_adapter_properties_struct_from_little_endian(
                                          FW_ADAPTER_PROPERTIES_type & o_data,
                                          std::vector<uint8_t>& i_data)
    {
        bool l_rc = false;

        // make sure we don't go outside i_data range
        if (i_data.size() >= sizeof(o_data))
        {
          uint32_t l_idx = 0;
          l_rc = mss::readLE(i_data, l_idx, o_data.fw_number_of_images);
          l_rc &= mss::readLE(i_data, l_idx, o_data.boot_partion_id);
          for (int i = 0; i < FW_ADAPTER_MAX_FW_IMAGE; ++i)
          {
            l_rc &= mss::readLE(i_data, l_idx, o_data.fw_ver_str[i].major);
            l_rc &= mss::readLE(i_data, l_idx, o_data.fw_ver_str[i].minor);
            l_rc &= mss::readLE(i_data, l_idx, o_data.fw_ver_str[i].build_num);
            l_rc &= mss::readLE(i_data, l_idx, o_data.fw_ver_str[i].build_patch);
            l_rc &= mss::readLE(i_data, l_idx, o_data.fw_ver_str[i].sector_size);
          }
          l_rc &= mss::readLE(i_data, l_idx, o_data.ram_size_in_bytes);
          l_rc &= mss::readLEArray(i_data, FW_ADAPTER_CHIP_VERSION_SIZE, l_idx, o_data.chip_version);
          l_rc &= mss::readLEArray(i_data, FW_ADAPTER_SPI_FLASH_ID_SIZE, l_idx, o_data.spi_flash_id);
          l_rc &= mss::readLE(i_data, l_idx, o_data.spi_flash_size);
          l_rc &= mss::readLE(i_data, l_idx, o_data.error_buffer_offset);
          l_rc &= mss::readLE(i_data, l_idx, o_data.error_buffer_size);
        }
        else
        {
            TS_FAIL("fw_adapter_properties_struct_from_little_endian(): "
              "not enough data present (%d, expected %d)",
              i_data.size(), sizeof(o_data) );
        }
        return l_rc;
    }

    /**
     *  @brief Send and check get_properties Explorer inband command
     *  @return Number of failures
     */
    int sendOcmbInbandCmdRsp(bool setScomI2c)
    {
        errlHndl_t l_errl = nullptr;
        uint8_t failures = 0;

        // Create a vector of TARGETING::Target pointers
        TARGETING::TargetHandleList l_chipList;

        // Get a list of all of the functioning ocmb chips
        TARGETING::getAllChips(l_chipList, TARGETING::TYPE_OCMB_CHIP, true);

        host_fw_command_struct l_cmd;
        host_fw_response_struct l_rsp;
        std::vector<uint8_t> l_rsp_data;

        // Create a non-destructive get_properties command
        buildPropertiesGetCmd(l_cmd);

        for (auto & l_ocmb: l_chipList)
        {
            do
            {
                if (setScomI2c)
                {
                    FAPI_INF("sendOcmbInbandCmdRsp: testing 0x%.8X OCMB using I2C", TARGETING::get_huid(l_ocmb));
                    // disable inband and use i2c when possible
                    exptest::disableInbandScomsOcmb(l_ocmb);
                }
                else
                {
                    FAPI_INF("sendOcmbInbandCmdRsp: testing 0x%.8X OCMB using MMIO", TARGETING::get_huid(l_ocmb));
                    // just incase some other test disabled inband scoms
                    exptest::enableInbandScomsOcmb(l_ocmb);
                }

                fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>l_fapi2_target( l_ocmb );

                TRACFBIN(g_trac_expscom, "l_cmd: ", &l_cmd, sizeof(host_fw_command_struct));

                // send the command
                FAPI_INVOKE_HWP(l_errl, mss::exp::ib::putCMD, l_fapi2_target,
                                l_cmd);
                if (l_errl)
                {
                    TS_FAIL("Error from putCMD for 0x%.8X target",
                        TARGETING::get_huid(l_ocmb));
                    failures++;
                    break;
                }

                FAPI_INF("sendOcmbInbandCmdRsp: reading response");

                // grab the response
                FAPI_INVOKE_HWP(l_errl, mss::exp::ib::getRSP, l_fapi2_target,
                                l_cmd.cmd_id, l_rsp, l_rsp_data);
                if (l_errl)
                {
                    TS_FAIL("Error from getRSP for 0x%.8X target, plid=0x%X rc=0x%X",
                        TARGETING::get_huid(l_ocmb),
                        ERRL_GETPLID_SAFE(l_errl), ERRL_GETRC_SAFE(l_errl));
                    failures++;
                    break;
                }

                TRACFBIN(g_trac_expscom, "l_rsp: ", &l_rsp, sizeof(host_fw_response_struct));
                TRACFBIN(g_trac_expscom, "l_rsp_data: ", l_rsp_data.data(), l_rsp_data.size());

                // Check for a valid data response length
                if (l_rsp.response_length != sizeof(FW_ADAPTER_PROPERTIES_type))
                {
                    TS_FAIL("Unexpected response length 0x%.8X (expected 0x%.8X)",
                      l_rsp.response_length, sizeof(FW_ADAPTER_PROPERTIES_type));
                    failures++;
                    break;
                }

                // Now convert the little endian response data into big endian
                FW_ADAPTER_PROPERTIES_type l_fw_adapter_data;
                fw_adapter_properties_struct_from_little_endian(l_fw_adapter_data,
                                                                l_rsp_data);

                // Check for some expected response values
                // Simics should return 0x88 as the first byte of chip_version
                if (l_fw_adapter_data.chip_version[0] != 0x88 )
                {
                    TS_FAIL("Expected chip_version to start with 0x88, found 0x%02X",
                        l_fw_adapter_data.chip_version[0]);
                    failures++;
                }
            } while (0);

            if (l_errl)
            {
                // Commit the error as this is NOT expected and
                // needs to be investigated
                errlCommit( l_errl, TARG_COMP_ID );
            }

            if (setScomI2c)
            {
                // Default the ocmb back to inband communication
                exptest::enableInbandScomsOcmb(l_ocmb);
            }
        }

        FAPI_INF("sendOcmbInbandCmdRsp: exiting");
        return failures;
    };

    /**
     *  @brief Test the Explorer inband command/response path over MMIO
     */
    void  testOcmbInbandCmdRspOverMMIO( void )
    {
#if 0 //@fixme-RTC:255444-Reenable (and fix expectations) when we get a new Simics level
        if (!iv_serializeTestMutex)
        {
            TS_FAIL("iv_serializedTestMutex is not setup, unable to continue");
        }
        else
        {
            // Inband operations can't be run at the same time
            // atomic section >>
            mutex_lock(iv_serializeTestMutex);

            int failures = sendOcmbInbandCmdRsp(false);
            if (failures)
            {
                TS_FAIL("testOcmbInbandCmdRspOverMMIO() failed: %d", failures);
            }
            mutex_unlock(iv_serializeTestMutex);
        }
#else
        TS_INFO("Skipping testOcmbInbandCmdRspOverMMIO - RTC:255444");
#endif
    }

    /**
     *  @brief Test the Explorer inband command/response path over I2C
     *         using ATTR_FORCE_SRAM_MMIO_OVER_I2C
     */
    void  testOcmbInbandCmdRspOverI2c_via_force( void )
    {
#if 0 //@fixme-RTC:255444-Reenable (and fix expectations) when we get a new Simics level
        FAPI_INF("testOcmbInbandCmdRspOverI2c_via_force: entering");
        if (!iv_serializeTestMutex)
        {
            TS_FAIL("iv_serializedTestMutex is not setup, unable to continue");
        }
        else
        {
            // Inband operations can't be run at the same time
            // atomic section >>
            mutex_lock(iv_serializeTestMutex);

            // Set FORCE_SRAM_MMIO_OVER_I2C to change to use I2C instead of MMIO
            TARGETING::Target * l_sys = nullptr;
            TARGETING::targetService().getTopLevelTarget(l_sys);
            crit_assert(l_sys != nullptr);

            l_sys->setAttr<TARGETING::ATTR_FORCE_SRAM_MMIO_OVER_I2C>(0x01);

            int failures = sendOcmbInbandCmdRsp(false);
            if (failures)
            {
                TS_FAIL("testOcmbInbandCmdRspOverI2c_via_force() failed: %d", failures);
            }

            // Restore using MMIO instead of I2C
            l_sys->setAttr<TARGETING::ATTR_FORCE_SRAM_MMIO_OVER_I2C>(0x00);

            mutex_unlock(iv_serializeTestMutex);
        }
        FAPI_INF("testOcmbInbandCmdRspOverI2c_via_force: exiting");
#else
        TS_INFO("Skipping testOcmbInbandCmdRspOverMMIO - RTC:255444");
#endif
    }

    /**
     *  @brief Test the Explorer inband command/response path over I2C
     *         using scom setting to i2c
     */
    void  testOcmbInbandCmdRspOverI2c_via_scom_switch( void )
    {
#if 0 //@fixme-RTC:255444-Reenable (and fix expectations) when we get a new Simics level
        FAPI_INF("testOcmbInbandCmdRspOverI2c_via_scom_switch: entering");
        if (!iv_serializeTestMutex)
        {
            TS_FAIL("iv_serializedTestMutex is not setup, unable to continue");
        }
        else
        {
            // Inband operations can't be run at the same time
            // atomic section >>
            mutex_lock(iv_serializeTestMutex);

            // Set SCOM_SWITCHES to use i2c instead of MMMIO when
            // running the inband cmd/rsp operations
            int failures = sendOcmbInbandCmdRsp(true);
            if (failures)
            {
                TS_FAIL("testOcmbInbandCmdRspOverI2c_via_scom_switch() failed: %d", failures);
            }

            mutex_unlock(iv_serializeTestMutex);
        }
        FAPI_INF("testOcmbInbandCmdRspOverI2c_via_scom_switch: exiting");
#else
        TS_INFO("Skipping testOcmbInbandCmdRspOverMMIO - RTC:255444");
#endif
    }

    /**
     * @brief Constructor
     */
    OCMBCommTest() : CxxTest::TestSuite()
    {
        // All modules are loaded by runtime,
        // so testcase loading of modules is not required
#ifndef __HOSTBOOT_RUNTIME
        errlHndl_t err = nullptr;

        err = exptest::loadModule(exptest::MSS_LIBRARY_NAME);
        if(err)
        {
            TS_FAIL("OCMBCommTest() - Constuctor: failed to load MSS module");
            errlCommit( err, TARG_COMP_ID );
        }
#endif
        iv_serializeTestMutex = exptest::getTestMutex();
    };

    /**
     * @brief Destructor
     */
    ~OCMBCommTest()
    {
    };

    private:
      // This is used for tests that need to not run operations at the same time
      TARGETING::HB_MUTEX_SERIALIZE_TEST_LOCK_ATTR iv_serializeTestMutex;

};

#endif
