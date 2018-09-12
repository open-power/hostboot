/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/p9_mmiotests.C $                           */
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
/// @file  p9_mmiotests.C
///
/// @brief These procedures test the fapi2 mmio_access interfaces.
//-----------------------------------------------------------------------------
#include <sys/time.h>

#include <cxxtest/TestSuite.H>
#include <fapi2.H>
#include <mmio_access.H>
#include <errl/errlentry.H>
#include <plat_hwp_invoker.H>
#include <sbe/sbe_common.H>


fapi2::ReturnCode p9_mmiotest_getmmio_invalid_target(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    // This will fail because PROC_CHIP not supported type
    FAPI_INF("Entering p9_mmiotest_getmmio_invalid_target...");

    std::vector<uint8_t> l_mmiodata;
    l_mmiodata.resize(8);

    FAPI_INF("Do getMMIO on a proc target for 8 bytes");
    FAPI_TRY(fapi2::getMMIO(i_target,
                            0x1000,  // mmio address relative to target
                            8,       // mmio transaction size
                            l_mmiodata));
 fapi_try_exit:

    FAPI_INF("Exiting p9_mmiotest_getmmio_invalid_target...");

    return fapi2::current_err;

}


fapi2::ReturnCode p9_mmiotest_putmmio_invalid_target(
               fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    // This will fail because PROC_CHIP not supported type
    FAPI_INF("Entering p9_mmiotest_putmmio_invalid_target...");

    std::vector<uint8_t> l_mmiodata;
    l_mmiodata.push_back(1);
    l_mmiodata.push_back(2);
    l_mmiodata.push_back(3);
    l_mmiodata.push_back(4);


    FAPI_INF( "Do putMMIO on proc target" );
    FAPI_TRY(fapi2::putMMIO(i_target,
                            0x1000,
                            4,
                            l_mmiodata));

 fapi_try_exit:

    FAPI_INF( "Exiting p9_mmiotest_putmmio_invalid_target... rc = 0x%.8X",
              (uint64_t)fapi2::current_err );

    return fapi2::current_err;

}


fapi2::ReturnCode p9_mmiotest_indivisible_by_section_size(
               fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    // This will fail because data can not be divided evenly among multiple section size transfers
    FAPI_INF("Entering p9_mmiotest_indivisible_by_section_size...");

    std::vector<uint8_t> l_mmiodata;
    l_mmiodata.resize(10);

    FAPI_INF("Do getMMIO on a target for 10 bytes");
    FAPI_TRY(fapi2::getMMIO(i_target,
                            0x1000,  // mmio address relative to target
                            8,       // mmio transaction size
                            l_mmiodata));
 fapi_try_exit:

    FAPI_INF("Exiting p9_mmiotest_indivisible_by_section_size...");

    return fapi2::current_err;

}


fapi2::ReturnCode p9_mmiotest_invalid_section_size(
               fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    // This will fail because an invalid section transfer size is being requested
    FAPI_INF("Entering p9_mmiotest_invalid_section_size...");

    std::vector<uint8_t> l_mmiodata;
    l_mmiodata.resize(12);

    FAPI_INF("Do getMMIO on a target for 12 bytes");
    FAPI_TRY(fapi2::getMMIO(i_target,
                            0x1000,  // mmio address relative to target
                            12,      // mmio transaction size
                            l_mmiodata));
 fapi_try_exit:

    FAPI_INF("Exiting p9_mmiotest_invalid_section_size...");

    return fapi2::current_err;

}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
fapi2::ReturnCode p9_mmiotest_getmmio_pass(
               fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    std::vector<uint8_t> l_mmiodata;

    FAPI_INF("Entering p9_mmiotest_getmmio_pass...");

    const size_t l_mmiodataSize = 4;
    l_mmiodata.resize(l_mmiodataSize); // do a single mmio transaction

    FAPI_INF("Do single-read transaction getMMIO on an OCMB target");
    FAPI_TRY(fapi2::getMMIO(i_target,
                            0x1000,
                            l_mmiodataSize,
                            l_mmiodata) );


    l_mmiodata.resize(l_mmiodataSize*2); // do a double mmio transaction
    FAPI_INF("Do double-read transaction getMMIO on an OCMB target");
    FAPI_TRY(fapi2::getMMIO(i_target,
                            0x1000,
                            l_mmiodataSize,
                            l_mmiodata) );

 fapi_try_exit:

    FAPI_INF("Exiting p9_mmiotest_getmmio_pass...");

    return fapi2::current_err;

}


fapi2::ReturnCode p9_mmiotest_double_read_pass(
               fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    std::vector<uint8_t> l_1st_read;
    std::vector<uint8_t> l_2nd_read;

    FAPI_INF("Entering p9_mmiotest_double_read_pass...");

    const size_t l_mmioTransactionSize = 4;
    l_1st_read.resize(4);

    FAPI_INF("Do first getMMIO on an ocmb target");
    FAPI_TRY(fapi2::getMMIO(i_target,
                            0x1000,
                            l_mmioTransactionSize,
                            l_1st_read) );

    // Initialize to some bad data
    l_2nd_read.push_back('T');
    l_2nd_read.push_back('e');
    l_2nd_read.push_back('s');
    l_2nd_read.push_back('t');

    FAPI_INF("Do second getMMIO on an ocmb target");
    FAPI_TRY(fapi2::getMMIO(i_target,
                            0x1000,
                            l_mmioTransactionSize,
                            l_2nd_read) );

    // read data should match
    if (l_2nd_read != l_1st_read)
    {
        TS_FAIL("1st read data (%d) does NOT match 2nd read data (%d)",
            l_1st_read.size(), l_2nd_read.size());
        TRACFBIN(g_fapiTd, "1st data", l_1st_read.data(), l_1st_read.size());
        TRACFBIN(g_fapiTd, "2nd data", l_2nd_read.data(), l_2nd_read.size());
    }

 fapi_try_exit:

    FAPI_INF("Exiting p9_mmiotest_double_read_pass...");

    return fapi2::current_err;
}


fapi2::ReturnCode p9_mmiotest_putmmio_pass(
               fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    FAPI_INF("Entering p9_mmiotest_putmmio_pass...");

    std::vector<uint8_t> l_mmiodata;
    l_mmiodata.push_back('P');
    l_mmiodata.push_back('U');
    l_mmiodata.push_back('T');
    l_mmiodata.push_back('M');
    l_mmiodata.push_back('M');
    l_mmiodata.push_back('I');
    l_mmiodata.push_back('O');
    l_mmiodata.push_back('-');
    l_mmiodata.push_back('P');
    l_mmiodata.push_back('A');
    l_mmiodata.push_back('S');
    l_mmiodata.push_back('S');

    FAPI_INF("Do putMMIO on OCMB target");
    FAPI_TRY(fapi2::putMMIO(i_target,
                            0x1000,
                            4,
                            l_mmiodata));
 fapi_try_exit:

    FAPI_INF("Exiting p9_mmiotest_putmmio_pass...");

    return fapi2::current_err;
}


fapi2::ReturnCode p9_mmiotest_write_read_pass(
               fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    FAPI_INF("Entering p9_mmiotest_write_read_pass...");

    const size_t l_mmioTransactionSize = 4;
    std::vector<uint8_t> l_mmio_data;
    std::vector<uint8_t> l_read_mmio_data;

    const uint8_t l_data[] = {'p','9','_','m', 'm','i','o','t',
                              'e','s','t','_', 'w','r','i','t',
                              'e','_','r','e', 'a','d','_','p',
                              'a','s','s','!'};
    const size_t l_data_size = sizeof(l_data);
    l_mmio_data.insert( l_mmio_data.end(), &l_data[0], &l_data[l_data_size] );

    // Write out a known value (name of this test)
    FAPI_INF("Calling putMMIO on the target (size: %d)", l_data_size);
    FAPI_TRY(fapi2::putMMIO(i_target, 0x1000,
                            l_mmioTransactionSize, l_mmio_data));

    // now read it out and verify it was written correctly
    FAPI_INF("Now read the just written data");
    l_read_mmio_data.resize(l_data_size);
    FAPI_TRY(fapi2::getMMIO(i_target,
                            0x1000,
                            l_mmioTransactionSize,
                            l_read_mmio_data));

    if (l_mmio_data == l_read_mmio_data)
    {
        FAPI_INF("Data found matches what was written");
    }
    else
    {
        TS_FAIL( "Data found (%d) does NOT match written values (%d)",
            l_read_mmio_data.size(), l_mmio_data.size() );
        TRACFBIN(g_fapiTd, "getMMIO returned",
            l_read_mmio_data.data(), l_read_mmio_data.size());
        TRACFBIN(g_fapiTd, "putMMIO wrote", l_mmio_data.data(),
            l_mmio_data.size());
    }

 fapi_try_exit:

    FAPI_INF("Exiting p9_mmiotest_write_read_pass...");

    return fapi2::current_err;
}
