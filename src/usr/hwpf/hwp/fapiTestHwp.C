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
 *
 */

#include <fapiTestHwp.H>

extern "C"
{

//******************************************************************************
// hwpIsP7ChipletClockOn function
//******************************************************************************
fapi::ReturnCode hwpIsP7EM0ChipletClockOn(const fapi::Target & i_chip,
                                          bool & o_clocksOn)
{
    // Ported from a combination of
    // hwsvClockAlgP7.C : hwsvClockQueryOnP7 (main HWP)
    // hwsvClockAlgP7.C : isChipletClockOn (sub function)

    // Attempt to call the attribute get/set functions for the test attributes
    fapi::ReturnCode l_rc;

    // Constants
    const uint64_t EM_CLOCK_STATUS_MASK = 0xEEC0000000000000ULL;
    const uint32_t EM0_CHIPLET_BASE_ADDR = 0x06000000;
    const uint32_t CHIPLET_CLOCK_ON_SCOM_ADDR = 0x00030008;

    // Set caller's result to default
    o_clocksOn = false;

    // Figure out the scom address and create a 64 bit data buffer
    uint32_t l_addr = (EM0_CHIPLET_BASE_ADDR | CHIPLET_CLOCK_ON_SCOM_ADDR);
    ecmdDataBufferBase l_data(64);

    // Perform a GetScom operation on the chip
    l_rc = GetScom(i_chip, l_addr, l_data);

    if (l_rc != fapi::FAPI_RC_SUCCESS)
    {
        FAPI_ERR("hwpIsP7EM0ChipletClockOn: Error from GetScomChip");
    }
    else
    {
        if (!(l_data.getDoubleWord(0) & EM_CLOCK_STATUS_MASK))
        {
            FAPI_INF("hwpIsP7EM0ChipletClockOn: Clocks are on");
            o_clocksOn = true;
        }
        else
        {
            FAPI_INF("hwpIsP7EM0ChipletClockOn: Clocks are off");
        }
    }

    return l_rc;
}

//******************************************************************************
// hwpInitialTest function - Override with whatever you want here
//******************************************************************************
fapi::ReturnCode hwpInitialTest(const fapi::Target & i_chip)
{
    fapi::ReturnCode l_rc;

    // Figure out the scom address and create a 64 bit data buffer
    ecmdDataBufferBase l_data(64);

    const uint64_t l_addr = 0x0201240B;

    // Perform a GetScom operation on the chip
    l_rc = GetScom(i_chip, l_addr, l_data);

    if (l_rc != fapi::FAPI_RC_SUCCESS)
    {
        FAPI_ERR("hwpInitialTest: Error from GetScomChip");
    }
    else
    {
        FAPI_INF("hwpInitialTest: Data from SCOM:0x%X  0x%16X",l_data.getDoubleWord(0));
        
    }

    return l_rc;
}

} // extern "C"
