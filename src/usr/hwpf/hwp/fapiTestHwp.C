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

    fapi::ReturnCode l_rc;

    // Figure out the scom address and create a 64 bit data buffer
    ecmdDataBufferBase l_data(64);

    const uint64_t l_addr = 0x13010002;

    // Perform a GetScom operation on the chip
    l_rc = GetScom(i_chip, l_addr, l_data);

    if (l_rc != fapi::FAPI_RC_SUCCESS)
    {
        FAPI_ERR("hwpInitialTest: Error from GetScomChip");
    }
    else
    {
        FAPI_INF("hwpInitialTest: Data from SCOM:0x%lld", l_data.getDoubleWord(0));
    }

    return l_rc;
}

} // extern "C"
