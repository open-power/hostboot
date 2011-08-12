/**
 *  @file fapiTestHwpFfdc.C
 *
 *  @brief Implements a simple test Hardware Procedure that collects FFDC data
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     08/08/2011  Created.
 *
 */

#include <fapiTestHwpFfdc.H>

extern "C"
{

//******************************************************************************
// hwpTestFfdc1 function
//******************************************************************************
fapi::ReturnCode hwpTestFfdc1(const fapi::Target & i_target,
                              fapi::TestFfdc1 & o_ffdc)
{
    FAPI_INF("Performing FFDC HWP: hwpTestFfdc1");

    // Just set data to output structure. A real FFDC HWP would do a hardware
    // access to get FFDC
    fapi::ReturnCode l_rc;

    o_ffdc.iv_data = 0x11223344;

    return l_rc;
}

} // extern "C"
