//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/fapiTestHwp.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
/**
 *  @file fapiTestHwp.C
 *
 *  @brief Implements a simple test Hardware Procedure
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     04/21/2011  Created.
 *                          mjjones     06/02/2011  Use ecmdDataBufferBase
 *                          mjjones     06/28/2011  Removed attribute tests
 *                          andrewg     07/07/2011  Added test for hw team to fill in
 *                          mjjones     08/10/2011  Removed clock HWP
 *                          mjjones     09/01/2011  Call toString in InitialTest
 *                          mjjones     09/14/2011  Update to scom function name
 *
 */

#include <fapiTestHwp.H>

extern "C"
{

//******************************************************************************
// hwpInitialTest function - Override with whatever you want here
//******************************************************************************
fapi::ReturnCode hwpInitialTest(const fapi::Target & i_chip)
{
    FAPI_INF("Performing HWP: hwpInitialTest");

    // Print the ecmd string of the chip
    char l_string[fapi::MAX_ECMD_STRING_LEN] = {0};
    i_chip.toString(l_string);
    FAPI_INF("hwpInitialTest: Chip: %s", l_string);

    fapi::ReturnCode l_rc;

    // Figure out the scom address and create a 64 bit data buffer
    ecmdDataBufferBase l_data(64);

    const uint64_t l_addr = 0x13010002;

    // Perform a GetScom operation on the chip
    l_rc = fapiGetScom(i_chip, l_addr, l_data);

    if (l_rc != fapi::FAPI_RC_SUCCESS)
    {
        FAPI_ERR("hwpInitialTest: Error from fapiGetScom");
    }
    else
    {
        FAPI_INF("hwpInitialTest: Data from SCOM:0x%lld", l_data.getDoubleWord(0));
    }

    return l_rc;
}

} // extern "C"
