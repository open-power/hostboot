/**
 *  @file fapiTestHwpError.C
 *
 *  @brief Implements a simple test Hardware Procedure that returns an error
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     08/08/2011  Created.
 *
 */

#include <fapiTestHwpError.H>

extern "C"
{

//******************************************************************************
// hwpTestError function
//******************************************************************************
fapi::ReturnCode hwpTestError(const fapi::Target & i_target)
{
    FAPI_INF("Performing HWP: hwpTestError");

    fapi::ReturnCode l_rc = fapi::RC_TEST_ERROR_A;

    // Add some local FFDC to the ReturnCode
    uint32_t l_ffdc = 0x12345678;
    l_rc.setHwpFfdc(reinterpret_cast<void *>(&l_ffdc), sizeof(uint32_t));

    return l_rc;
}

} // extern "C"
