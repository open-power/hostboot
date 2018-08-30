/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/p9_i2ctests.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
//------------------------------------------------------------------------------
/// @file  p9_i2ctests.C
///
/// @brief These procedures test the fapi2 i2c_access interfaces.
//-----------------------------------------------------------------------------
#include <sys/time.h>

#include <fapi2.H>
#include <i2c_access.H>
#include <errl/errlentry.H>
#include <plat_hwp_invoker.H>
#include <sbe/sbe_common.H>


fapi2::ReturnCode p9_i2ctest_geti2c_fail(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    // This will fail because PROC_CHIP not supported type
    std::vector<uint8_t> l_i2cdata;
    std::vector<uint8_t> l_cfgData;
    l_cfgData.push_back(0);
    l_cfgData.push_back(1);

    FAPI_INF("Entering p9_i2ctest_geti2c_fail...");

    FAPI_INF("Do getI2c on a proc target for 10 bytes");
    FAPI_TRY(fapi2::getI2c(i_target,
                           10,
                           l_cfgData,
                           l_i2cdata));
 fapi_try_exit:

    FAPI_INF("Exiting p9_i2ctest_geti2c_fail...");

    return fapi2::current_err;

}

fapi2::ReturnCode p9_i2ctest_puti2c_fail(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    // This will fail because PROC_CHIP not supported type
    FAPI_INF("Entering p9_i2ctest_puti2c_fail...");

    std::vector<uint8_t> l_i2cdata;
    l_i2cdata.push_back(1);
    l_i2cdata.push_back(2);
    l_i2cdata.push_back(3);
    l_i2cdata.push_back(4);
    l_i2cdata.push_back(5);


    FAPI_INF( "Do putI2c on proc target" );
    FAPI_TRY(fapi2::putI2c(i_target,
                           l_i2cdata));

 fapi_try_exit:

    FAPI_INF( "Exiting p9_i2ctest_puti2c_fail... rc = 0x%.8X",
              (uint64_t)fapi2::current_err );

    return fapi2::current_err;

}

////////////////////////////////////////////////////////////////////////////////
// @todo RTC:198116 -- Need to update testcases to use OCMB target instead of PROC
// Also update FAPI_I2C_CONTROL_INFO attribute on OCMB target
////////////////////////////////////////////////////////////////////////////////
fapi2::ReturnCode p9_i2ctest_geti2c_pass(
               fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    std::vector<uint8_t> l_i2cdata;
    std::vector<uint8_t> l_cfgData;

    FAPI_INF("Entering p9_i2ctest_geti2c_pass...");
/*
    const size_t l_i2cdataSize = 4;
    FAPI_INF("Do getI2c on a proc target");
    FAPI_TRY(fapi2::getI2c(i_target,
                           l_i2cdataSize,
                           l_cfgData,
                           l_i2cdata));

 fapi_try_exit:
*/
    FAPI_INF("Exiting p9_i2ctest_geti2c_pass...");

    return fapi2::current_err;

}


fapi2::ReturnCode p9_i2ctest_double_read_pass(
               fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
/*
    std::vector<uint8_t> l_cfgData;
    std::vector<uint8_t> l_1st_read;
    std::vector<uint8_t> l_2nd_read;

    FAPI_INF("Entering p9_i2ctest_double_read_pass...");

    const size_t l_expectedReadSize = sizeof(SBE::sbeSeepromVersionInfo_t);
    l_cfgData.push_back(0xFE);
    l_cfgData.push_back(0xD9);

    FAPI_INF("Do first getI2c on a proc target");
    FAPI_TRY(fapi2::getI2c(i_target,
                           l_expectedReadSize,
                           l_cfgData,
                           l_1st_read));

    // Initialize to some bad data
    l_2nd_read.push_back('T');
    l_2nd_read.push_back('e');
    l_2nd_read.push_back('s');
    l_2nd_read.push_back('t');

    FAPI_INF("Do second getI2c on a proc target");
    FAPI_TRY(fapi2::getI2c(i_target,
                           l_expectedReadSize,
                           l_cfgData,
                           l_2nd_read));

    // read data should match
    if (l_2nd_read != l_1st_read)
    {
        FAPI_ERR("1st read data does NOT match 2nd read data");
        TRACFBIN(g_fapiTd, "1st data", l_1st_read.data(), l_1st_read.size());
        TRACFBIN(g_fapiTd, "2nd data", l_2nd_read.data(), l_2nd_read.size());
    }

 fapi_try_exit:
*/
    FAPI_INF("Exiting p9_i2ctest_double_read_pass...");

    return fapi2::current_err;
}


fapi2::ReturnCode p9_i2ctest_puti2c_pass(
               fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    FAPI_INF("Entering p9_i2ctest_puti2c_pass...");
/*
    std::vector<uint8_t> l_i2cdata;

    // purposely truncate address to the last 2 bytes
    uint16_t offsetAddr = (uint16_t)SBE::SBE_VERSION_SEEPROM_ADDRESS;
    uint8_t * pOffset = (uint8_t*)&offsetAddr;

    l_i2cdata.push_back(pOffset[0]);
    l_i2cdata.push_back(pOffset[1]);
    l_i2cdata.push_back('P');
    l_i2cdata.push_back('U');
    l_i2cdata.push_back('T');
    l_i2cdata.push_back('I');
    l_i2cdata.push_back('2');
    l_i2cdata.push_back('C');
    l_i2cdata.push_back('-');
    l_i2cdata.push_back('P');
    l_i2cdata.push_back('A');
    l_i2cdata.push_back('S');
    l_i2cdata.push_back('S');

    FAPI_INF("Do putI2c on proc target");
    FAPI_TRY(fapi2::putI2c(i_target,
                           l_i2cdata));
 fapi_try_exit:
*/
    FAPI_INF("Exiting p9_i2ctest_puti2c_pass...");

    return fapi2::current_err;
}


fapi2::ReturnCode p9_i2ctest_write_read_pass(
               fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    FAPI_INF("Entering p9_i2ctest_write_read_pass...");
/*
    std::vector<uint8_t> l_i2cdata;
    std::vector<uint8_t> l_read_i2cdata;
    std::vector<uint8_t> l_read_offset;

    const uint8_t l_data[] = {0xFE,0xD9,
                              0x49,0x4E,0x56,0x41,0x4C,0x49,0x44,0x00,0x8C,
                              0x49,0x4E,0x56,0x41,0x4C,0x49,0x44,0x00,0x8C,
                              0x49,0x4E,0x56,0x41,0x4C,0x49,0x44,0x00,0x8C,
                              0x49,0x4E,0x56,0x41,0x4C,0x49,0x44,0x00,0x8C};
    const size_t l_read_size = sizeof(l_data) - 2;
    l_i2cdata.insert( l_i2cdata.end(), &l_data[0], &l_data[sizeof(l_data)] );
    l_read_offset.insert( l_read_offset.end(), &l_data[0], &l_data[2]);

    FAPI_INF("Calling putI2c on the target");
    FAPI_TRY(fapi2::putI2c(i_target,
                           l_i2cdata));

    // now read it out and verify it was written correctly
    FAPI_INF("Now read the just written data");
    FAPI_TRY(fapi2::getI2c(i_target,
                           l_read_size,
                           l_read_offset,
                           l_read_i2cdata));

    // remove 2-byte address part at beginning
    l_i2cdata.clear();
    l_i2cdata.insert( l_i2cdata.end(), &l_data[2], &l_data[sizeof(l_data)] );
    if (l_i2cdata == l_read_i2cdata)
    {
        FAPI_INF("Data found matches what was written");
    }
    else
    {
        FAPI_ERR( "Data found (%d) does NOT match written values (%d)",
            l_read_i2cdata.size(), l_i2cdata.size() );
        TRACFBIN(g_fapiTd, "getI2c returned", l_read_i2cdata.data(), l_read_i2cdata.size());
        TRACFBIN(g_fapiTd, "putI2c wrote", l_i2cdata.data(), l_i2cdata.size());
    }

 fapi_try_exit:
*/
    FAPI_INF("Exiting p9_i2ctest_write_read_pass...");

    return fapi2::current_err;
}
