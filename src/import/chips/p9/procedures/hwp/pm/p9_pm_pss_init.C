/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_pss_init.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file p9_pm_pss_init.C
/// @brief Initializes P2S and HWC logic
///
// *HWP HWP Owner: Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 2
// *HWP Consumed by: FSP:HS

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include <p9_pm_pss_init.H>

// -----------------------------------------------------------------------------
// Function prototypes
// -----------------------------------------------------------------------------

//------------------------------------------------------------------------------
///
/// @brief Using configured attributed, performs the initialization of the PSS
///        function
///
/// @param[in] i_target Chip target
///
/// @return FAPI2_RC_SUCCESS on success, else error.
///
fapi2::ReturnCode pm_pss_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

//------------------------------------------------------------------------------
///
/// @brief Performs the reset of the PSS function
///
/// @param[in] i_target Chip target
///
/// @return FAPI2_RC_SUCCESS on success, else error.
///
fapi2::ReturnCode pm_pss_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);


// -----------------------------------------------------------------------------
// Function definitions
// -----------------------------------------------------------------------------

fapi2::ReturnCode p9_pm_pss_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9pm::PM_FLOW_MODE i_mode)
{
    FAPI_IMP("p9_pm_pss_init Enter");

    // Initialization:  perform order or dynamic operations to initialize
    // the PMC using necessary Platform or Feature attributes.
    if (i_mode == p9pm::PM_INIT)
    {
        FAPI_TRY(pm_pss_init(i_target), "Failed to initialize the PSS logic");
    }
    // Reset:  perform reset of PSS
    else if (i_mode == p9pm::PM_RESET)
    {
        FAPI_TRY(pm_pss_reset(i_target), "Failed to reset PSS logic.");
    }

fapi_try_exit:
    FAPI_IMP("p9_pm_pss_init Exit");
    return fapi2::current_err;
}

fapi2::ReturnCode pm_pss_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP("pm_pss_init Enter");

    fapi2::buffer<uint64_t> l_data64;

    const uint32_t l_default_attr_proc_pss_init_nest_frequency = 2400;
    const uint8_t  l_default_apss_chip_select = 1;
    const uint8_t  l_default_spipss_frame_size = 0x20;
    const uint8_t  l_default_spipss_in_delay = 0;
    const uint8_t  l_default_spipss_clock_polarity = 0;
    const uint8_t  l_default_spipss_clock_phase = 0;
    const uint16_t l_default_attr_pm_spipss_clock_divider = 0xA;

    uint32_t l_attr_proc_pss_init_nest_frequency;
    uint8_t  l_attr_pm_apss_chip_select;
    uint8_t  l_attr_pm_spipss_frame_size;
    uint8_t  l_attr_pm_spipss_in_delay;
    uint8_t  l_attr_pm_spipss_clock_polarity;
    uint8_t  l_attr_pm_spipss_clock_phase;
    uint16_t l_attr_pm_spipss_clock_divider;
    uint32_t l_attr_pm_spipss_inter_frame_delay;

    uint32_t l_spipss_100ns_value;
    uint8_t  l_p2s_fsm_enable;
    uint8_t  l_p2s_nr_of_frames;
    uint8_t  l_hwctrl_fsm_enable;
    uint8_t  l_hwctrl_nr_of_frames;

    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> l_sysTarget =
        i_target.getParent<fapi2::TARGET_TYPE_SYSTEM>();

    GETATTR_DEFAULT(fapi2::ATTR_FREQ_PB_MHZ, "ATTR_FREQ_PB_MHZ", l_sysTarget,
                    l_attr_proc_pss_init_nest_frequency,
                    l_default_attr_proc_pss_init_nest_frequency);

    GETATTR_DEFAULT(fapi2::ATTR_PM_APSS_CHIP_SELECT,
                    "ATTR_PM_APSS_CHIP_SELECT",
                    i_target, l_attr_pm_apss_chip_select,
                    l_default_apss_chip_select);

    GETATTR_DEFAULT(fapi2::ATTR_PM_SPIPSS_FRAME_SIZE,
                    "ATTR_PM_SPIPSS_FRAME_SIZE",
                    i_target, l_attr_pm_spipss_frame_size,
                    l_default_spipss_frame_size);

    GETATTR_DEFAULT(fapi2::ATTR_PM_SPIPSS_IN_DELAY, "ATTR_PM_SPIPSS_IN_DELAY",
                    i_target, l_attr_pm_spipss_in_delay,
                    l_default_spipss_in_delay );

    GETATTR_DEFAULT(fapi2::ATTR_PM_SPIPSS_CLOCK_POLARITY,
                    "ATTR_PM_SPIPSS_CLOCK_POLARITY", i_target,
                    l_attr_pm_spipss_clock_polarity,
                    l_default_spipss_clock_polarity );

    GETATTR_DEFAULT(fapi2::ATTR_PM_SPIPSS_CLOCK_PHASE,
                    "ATTR_PM_SPIPSS_CLOCK_PHASE",
                    i_target, l_attr_pm_spipss_clock_phase,
                    l_default_spipss_clock_phase );

    GETATTR_DEFAULT(fapi2::ATTR_PM_SPIPSS_CLOCK_DIVIDER,
                    "ATTR_PM_SPIPSS_CLOCK_DIVIDER", i_target,
                    l_attr_pm_spipss_clock_divider,
                    l_default_attr_pm_spipss_clock_divider);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PM_SPIPSS_INTER_FRAME_DELAY_SETTING,
                           i_target, l_attr_pm_spipss_inter_frame_delay),
             "Error: Could not fetch inter frame delay");

    // ------------------------------------------
    //  -- Init procedure
    // ------------------------------------------

    //  ******************************************************************
    //     - set SPIPSS_ADC_CTRL_REG0 with the values read from attributes
    //  ******************************************************************
    FAPI_TRY(fapi2::getScom(i_target, PU_SPIMPSS_ADC_CTRL_REG0, l_data64));

    l_data64.insertFromRight<0, 6>(l_attr_pm_spipss_frame_size);
    l_data64.insertFromRight<12, 6>(l_attr_pm_spipss_in_delay);

    FAPI_TRY(fapi2::putScom(i_target, PU_SPIMPSS_ADC_CTRL_REG0, l_data64),
             "Error: failed to set the SPIPSS ADC CTRL REG 0 configuration");

    //  ******************************************************************
    //     - set SPIPSS_ADC_CTRL_REG1
    //         adc_fsm_enable = disable
    //         adc_device     = APSS
    //         adc_cpol       = 0
    //         adc_cpha       = 0
    //         adc_clock_divider = set to 10Mhz
    //         adc_nr_of_frames  = 0x16 (for auto 2 mode)
    //  ******************************************************************

    FAPI_TRY(fapi2::getScom(i_target, PU_SPIPSS_ADC_CTRL_REG1, l_data64));

    l_hwctrl_fsm_enable = 0x1;
    l_hwctrl_nr_of_frames = 0x10;

    l_data64.insertFromRight<0, 1>(l_hwctrl_fsm_enable);
    l_data64.insertFromRight<1, 1>(l_attr_pm_apss_chip_select);
    l_data64.insertFromRight<2, 1>(l_attr_pm_spipss_clock_polarity);
    l_data64.insertFromRight<3, 1>(l_attr_pm_spipss_clock_phase);
    l_data64.insertFromRight<4, 10>(l_attr_pm_spipss_clock_divider);
    l_data64.insertFromRight<14, 4>(l_hwctrl_nr_of_frames);

    FAPI_TRY(fapi2::putScom(i_target, PU_SPIPSS_ADC_CTRL_REG1, l_data64),
             "Error: failed to set the SPIPSS ADC CTRL REG 1 configuration");

    //  ******************************************************************
    //     - set SPIPSS_ADC_CTRL_REG2
    //  ******************************************************************

    FAPI_TRY(fapi2::getScom(i_target, PU_SPIPSS_ADC_CTRL_REG2, l_data64));
    l_data64.insertFromRight<0, 17>(l_attr_pm_spipss_inter_frame_delay);
    FAPI_TRY(fapi2::putScom(i_target, PU_SPIPSS_ADC_CTRL_REG2, l_data64),
             "Error: failed to set the SPIPSS ADC CTRL REG 2 configuration");

    //  ******************************************************************
    //     - clear SPIPSS_ADC_Wdata_REG
    //  ******************************************************************
    l_data64.flush<0>();
    FAPI_TRY(fapi2::putScom(i_target, PU_SPIPSS_ADC_WDATA_REG, l_data64),
             "Error: Failed to clear SPIPSS ADC WDATA");

    //  ******************************************************************
    //     - set SPIPSS_P2S_CTRL_REG0
    //  ******************************************************************

    FAPI_TRY(fapi2::getScom(i_target, PU_SPIPSS_P2S_CTRL_REG0, l_data64));

    l_data64.insertFromRight<0, 6>(l_attr_pm_spipss_frame_size);
    l_data64.insertFromRight<12, 6>(l_attr_pm_spipss_in_delay);

    FAPI_TRY(fapi2::putScom(i_target, PU_SPIPSS_P2S_CTRL_REG0, l_data64),
             "Error: Failed to set SPIPSS P2S CTRL REG 0");

    //  ******************************************************************
    //     - set SPIPSS_P2S_CTRL_REG1
    //         p2s_fsm_enable = disable
    //         p2s_device     = APSS
    //         p2s_cpol       = 0
    //         p2s_cpha       = 0
    //         p2s_clock_divider = set to 10Mhz
    //         p2s_nr_of_frames = 1 (for auto 2 mode)
    //  ******************************************************************

    FAPI_TRY(fapi2::getScom(i_target, PU_SPIPSS_P2S_CTRL_REG1, l_data64));

    l_p2s_fsm_enable = 0x1;
    l_p2s_nr_of_frames = 0x1;

    l_data64.insertFromRight<0, 1>(l_p2s_fsm_enable);
    l_data64.insertFromRight<1, 1>(l_attr_pm_apss_chip_select);
    l_data64.insertFromRight<2, 1>(l_attr_pm_spipss_clock_polarity);
    l_data64.insertFromRight<3, 1>(l_attr_pm_spipss_clock_phase);
    l_data64.insertFromRight<4, 10>(l_attr_pm_spipss_clock_divider);
    l_data64.insertFromRight<17, 1>(l_p2s_nr_of_frames);

    FAPI_TRY(fapi2::putScom(i_target, PU_SPIPSS_P2S_CTRL_REG1, l_data64),
             "Error: Failed to set SPIPSS P2S CTRL REG 1");

    //  ******************************************************************
    //     - set SPIPSS_P2S_CTRL_REG2
    //  ******************************************************************

    FAPI_TRY(fapi2::getScom(i_target, PU_SPIPSS_P2S_CTRL_REG2, l_data64));
    l_data64.insertFromRight<0, 17>(l_attr_pm_spipss_inter_frame_delay);
    FAPI_TRY(fapi2::putScom(i_target, PU_SPIPSS_P2S_CTRL_REG2, l_data64),
             "Error: Failed to set SPIPSS P2S CTRL REG 2");

    //  ******************************************************************
    //     - clear SPIPSS_P2S_Wdata_REG
    //  ******************************************************************
    l_data64.flush<0>();
    FAPI_TRY(fapi2::putScom(i_target, PU_SPIPSS_P2S_WDATA_REG, l_data64),
             "Error: Failed to clear SPI PSS P2S WDATA");

    //  ******************************************************************
    //     - Set 100ns Register for Interframe delay
    //  ******************************************************************
    l_spipss_100ns_value = l_attr_proc_pss_init_nest_frequency / 40;
    FAPI_TRY(fapi2::getScom(i_target, PU_SPIPSS_100NS_REG, l_data64));
    l_data64.insertFromRight<0, 32>(l_spipss_100ns_value);
    FAPI_TRY(fapi2::putScom(i_target, PU_SPIPSS_100NS_REG, l_data64),
             "Error: Failed to set 100ns clear SPI PSS P2S WDATA");

fapi_try_exit:
    return fapi2::current_err;
}


fapi2::ReturnCode pm_pss_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP("pm_pss_reset Enter");

    fapi2::buffer<uint64_t> l_data64;
    uint32_t l_pollcount = 0;
    uint32_t l_max_polls;
    // timeout period is 10 millisecond. (Far longer than needed)
    const uint32_t l_pss_timeout_us = 10000;
    const uint32_t l_pss_poll_interval_us = 10;

    //  ******************************************************************
    //     - Poll status register for ongoing or no errors to give the
    //       chance for on-going operations to complete
    //  ******************************************************************

    FAPI_INF("Polling for ADC on-going to go low ... ");
    l_max_polls = l_pss_timeout_us / l_pss_poll_interval_us;

    for (l_pollcount = 0; l_pollcount < l_max_polls; l_pollcount++)
    {
        FAPI_TRY(fapi2::getScom(i_target, PU_SPIPSS_ADC_STATUS_REG, l_data64));

        // ADC on-going complete
        if (l_data64.getBit<0>() == 0)
        {
            FAPI_INF("All frames sent from ADC to the APSS device.");
            break;
        }

        // ADC error
        FAPI_ASSERT(l_data64.getBit<7>() != 1,
                    fapi2::PM_PSS_ADC_ERROR()
                    .set_CHIP(i_target),
                    "Error while sending the frames from ADC to APSS device");

        FAPI_DBG("Delay before next poll");
        fapi2::delay(l_pss_poll_interval_us * 1000, 1000);
    }

    // Write attempted while Bridge busy
    if(l_data64.getBit<5>() == 1)
    {
        FAPI_INF("SPIP2S Write While Bridge Busy bit asserted. May cause "
                 "undefined bridge behavior. Will be cleared during reset");
    }

    // Polling timeout
    if (l_pollcount >= l_max_polls)
    {
        FAPI_INF("WARNING: SPI ADC did not go to idle in at least %d us. "
                 "Reset of PSS macro is commencing anyway", l_pss_timeout_us);
    }

    //  ******************************************************************
    //     - Poll status register for ongoing or errors to give the
    //       chance for on-going operations to complete
    //  ******************************************************************

    FAPI_INF("Polling for P2S on-going to go low ... ");

    for (l_pollcount = 0; l_pollcount < l_max_polls; l_pollcount++)
    {
        FAPI_TRY(fapi2::getScom(i_target, PU_SPIPSS_P2S_STATUS_REG, l_data64));

        //P2S On-going complete
        if (l_data64.getBit<0>() == 0)
        {
            FAPI_INF("All frames sent from P2S to the APSS device.");
            break;
        }

        // P2S error
        FAPI_ASSERT(l_data64.getBit<7>() != 1,
                    fapi2::PM_PSS_P2S_ERROR()
                    .set_CHIP(i_target),
                    "Error while sending the frames from P2S to APSS device");

        FAPI_DBG("Delay before next poll");
        fapi2::delay(l_pss_poll_interval_us * 1000, 1000);
    }

    // write attempted while bridge busy
    if (l_data64.getBit<5>() == 1)
    {
        FAPI_INF("SPIP2S Write While Bridge Busy bit asserted. "
                 "Will be cleared with coming reset");
    }

    // Poll timeout
    if (l_pollcount >= l_max_polls)
    {
        FAPI_INF("WARNING: SPI P2S did not go to idle in at least %d us. "
                 "Reset of PSS macro is commencing anyway", l_pss_timeout_us);
    }

    //  ******************************************************************
    //     - Resetting both ADC and P2S bridge
    //  ******************************************************************

    FAPI_INF("Resetting P2S and ADC bridges.");

    l_data64.flush<0>();
    l_data64.setBit<1>();

    FAPI_TRY(fapi2::putScom(i_target, PU_SPIPSS_ADC_RESET_REGISTER, l_data64),
             "Error: Could not reset ADC bridge");
    FAPI_TRY(fapi2::putScom(i_target, PU_SPIPSS_P2S_RESET_REGISTER, l_data64),
             "Error: Could not reset P2S bridge");

    // Clearing reset for cleanliness
    l_data64.flush<0>();
    FAPI_TRY(fapi2::putScom(i_target, PU_SPIPSS_ADC_RESET_REGISTER, l_data64),
             "Error: Could not clear the ADC reset register");
    FAPI_TRY(fapi2::putScom(i_target, PU_SPIPSS_P2S_RESET_REGISTER, l_data64),
             "Error: Could not clear the P2S reset register");

fapi_try_exit:
    return fapi2::current_err;
}
