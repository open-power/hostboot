/**
 *  @file fapiTestHwp.C
 *
 *  @brief Implements test Hardware Procedures.
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

    // Test getting and setting attributes
    {
        char * l_pString = NULL;
        uint8_t l_uint8 = 0;
        uint32_t l_uint32 = 0;
        uint64_t l_uint64 = 0;
        uint8_t l_pUint8Array[3] = {0};
        uint32_t l_pUint32Array[4] = {0};
        uint64_t l_pUint64Array[5] = {0};

        // All of the following should currently compile (not checking RC which
        // should be FAPI_RC_NOT_IMPLEMENTED). The get/set functions do not
        // currently do anything so passing NULL will work.
        l_rc = FAPI_ATTR_GET(ATTR_TEST_STRING, &i_chip, l_pString);
        l_rc = FAPI_ATTR_GET(ATTR_TEST_UINT8, &i_chip, l_uint8);
        l_rc = FAPI_ATTR_GET(ATTR_TEST_UINT32, &i_chip, l_uint32);
        l_rc = FAPI_ATTR_GET(ATTR_TEST_UINT64, &i_chip, l_uint64);
        l_rc = FAPI_ATTR_GET(ATTR_TEST_UINT8_ARRAY, &i_chip, l_pUint8Array);
        l_rc = FAPI_ATTR_GET(ATTR_TEST_UINT32_ARRAY, &i_chip, l_pUint32Array);
        l_rc = FAPI_ATTR_GET(ATTR_TEST_UINT64_ARRAY, &i_chip, l_pUint64Array);

        l_rc = FAPI_ATTR_SET(ATTR_TEST_STRING, &i_chip, l_pString);
        l_rc = FAPI_ATTR_SET(ATTR_TEST_STRING, &i_chip, "test-string");
        l_rc = FAPI_ATTR_SET(ATTR_TEST_UINT8, &i_chip, l_uint8);
        l_rc = FAPI_ATTR_SET(ATTR_TEST_UINT32, &i_chip, l_uint32);
        l_rc = FAPI_ATTR_SET(ATTR_TEST_UINT64, &i_chip, l_uint64);
        l_rc = FAPI_ATTR_SET(ATTR_TEST_UINT8_ARRAY, &i_chip, l_pUint8Array);
        l_rc = FAPI_ATTR_SET(ATTR_TEST_UINT32_ARRAY, &i_chip, l_pUint32Array);
        l_rc = FAPI_ATTR_SET(ATTR_TEST_UINT64_ARRAY, &i_chip, l_pUint64Array);

        // All of the following should not compile due to wrong types used
        //l_rc = FAPI_ATTR_GET(ATTR_TEST_STRING, &i_chip, l_uint8);
        //l_rc = FAPI_ATTR_GET(ATTR_TEST_STRING, &i_chip, l_uint32);
        //l_rc = FAPI_ATTR_GET(ATTR_TEST_STRING, &i_chip, l_uint64);
        //l_rc = FAPI_ATTR_GET(ATTR_TEST_STRING, &i_chip, l_pUint8Array);
        //l_rc = FAPI_ATTR_GET(ATTR_TEST_UINT8, &i_chip, l_pString);
        //l_rc = FAPI_ATTR_GET(ATTR_TEST_UINT32, &i_chip, l_uint8);
        //l_rc = FAPI_ATTR_GET(ATTR_TEST_UINT64, &i_chip, l_pUint8Array);
        //l_rc = FAPI_ATTR_GET(ATTR_TEST_UINT64, &i_chip, l_pUint64Array);
        //l_rc = FAPI_ATTR_GET(ATTR_TEST_UINT8_ARRAY, &i_chip, l_pString);
        //l_rc = FAPI_ATTR_GET(ATTR_TEST_UINT32_ARRAY, &i_chip, l_uint8);
        //l_rc = FAPI_ATTR_GET(ATTR_TEST_UINT64_ARRAY, &i_chip, l_uint64);
        //l_rc = FAPI_ATTR_GET(ATTR_TEST_UINT64_ARRAY, &i_chip, l_pUint32Array);

        //l_rc = FAPI_ATTR_SET(ATTR_TEST_STRING, &i_chip, l_uint8);
        //l_rc = FAPI_ATTR_SET(ATTR_TEST_STRING, &i_chip, l_uint32);
        //l_rc = FAPI_ATTR_SET(ATTR_TEST_STRING, &i_chip, l_uint64);
        //l_rc = FAPI_ATTR_SET(ATTR_TEST_STRING, &i_chip, l_pUint64Array);
        //l_rc = FAPI_ATTR_SET(ATTR_TEST_UINT8, &i_chip, l_pString);
        //l_rc = FAPI_ATTR_SET(ATTR_TEST_UINT32, &i_chip, l_uint64);
        //l_rc = FAPI_ATTR_SET(ATTR_TEST_UINT64, &i_chip, l_pUint32Array);
        //l_rc = FAPI_ATTR_SET(ATTR_TEST_UINT64, &i_chip, l_pUint64Array);
        //l_rc = FAPI_ATTR_SET(ATTR_TEST_UINT8_ARRAY, &i_chip, l_pString);
        //l_rc = FAPI_ATTR_SET(ATTR_TEST_UINT32_ARRAY, &i_chip, l_uint8);
        //l_rc = FAPI_ATTR_SET(ATTR_TEST_UINT64_ARRAY, &i_chip, l_uint64);
        //l_rc = FAPI_ATTR_SET(ATTR_TEST_UINT64_ARRAY, &i_chip, l_pUint8Array);

        l_rc = fapi::FAPI_RC_SUCCESS;
    }

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


} // extern "C"
