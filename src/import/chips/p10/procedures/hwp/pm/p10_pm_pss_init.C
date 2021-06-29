/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_pss_init.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

/// @file p10_pm_pss_init.C
/// @brief Initializes P2S and HWC logic
///
// *HWP HW Owner        :   Greg Still <stillgs@us.ibm.com>
// *HWP Backup Owner    :   Prasad BG Ranganath <prasadbgr@in.ibm.com>
// *HWP FW Owner        :   Prem S Jha <premjha2@in.ibm.com>
// *HWP Team            :   PM
// *HWP Level           :   3
// *HWP Consumed by     :   HS

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include <p10_pm_pss_init.H>
#include <p10_scom_proc.H>
#include <p10_scom_proc_3.H>

// ----------------------------------------------------------------------
// Constant Definitions
// ----------------------------------------------------------------------
enum
{
    //WOF_CNTRL_SETUP break up
    //Bit0 OCB_OCI_WOFICCTRL_INTERCHIP_LINK_ENABLE:
    //Transmit and receive of FSM enabled

    //Bit4:13 OCB_OCI_WOFICCTRL_INTERCHIP_CLOCK_DIVIDER:
    //Interchip clock speed divider to divide the tpconst_gckn/4 mesh clock

    //Bit16: OCB_OCI_WOFICCTRL_INTERCHIP_INTERFACE_ENABLE_NORTH: Enable the
    //tx pins on the north interface. This also selects the north rx
    //interface for receiving data.

    //Bit17: OCB_OCI_WOFICCTRL_INTERCHIP_INTERFACE_ENABLE_SOUTH:
    //Enable the tx pins on the south interface. This also selects the south rx
    //interface for receiving data

    //Bit20: OCB_OCI_WOFICCTRL_INTERCHIP_ECC_GEN_EN:
    //Enable ECC generation. This will produce an 8b ECC of an assumed 64b
    //payload using 64/72 SEC/DED encoding.

    WOF_CNTRL_SETUP   =    0x8024E8,
};

// -----------------------------------------------------------------------------
// Function prototypes
// -----------------------------------------------------------------------------

//------------------------------------------------------------------------------
///
/// @brief Using configuration attributes, performs the initialization of the PSS
///        function
///
/// @param[in] i_target Chip target
///
/// @return FAPI2_RC_SUCCESS on success, else error.
///
fapi2::ReturnCode pm_pss_start(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

//------------------------------------------------------------------------------
///
/// @brief Performs the halt of the PSS function
///
/// @param[in] i_target Chip target
///
/// @return FAPI2_RC_SUCCESS on success, else error.
///
fapi2::ReturnCode pm_pss_halt(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);


// -----------------------------------------------------------------------------
// Function definitions
// -----------------------------------------------------------------------------

fapi2::ReturnCode p10_pm_pss_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const pm::PM_FLOW_MODE i_mode)
{
    FAPI_IMP(">> p10_pm_pss_init");

    // Start:  perform order or dynamic operations to initialize
    // the PMC using necessary Platform or Feature attributes.
    if (i_mode == pm::PM_START)
    {
        FAPI_TRY(pm_pss_start(i_target), "Failed to start the PSS logic");
    }
    // Reset:  perform halt of PSS
    else if (i_mode == pm::PM_HALT)
    {
        FAPI_TRY(pm_pss_halt(i_target), "Failed to halt PSS logic.");
    }

fapi_try_exit:
    FAPI_IMP("<< p10_pm_pss_init");
    return fapi2::current_err;
}

fapi2::ReturnCode pm_pss_start(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP(">> pm_pss_start Enter");

    fapi2::buffer<uint64_t> l_data64;

    const uint8_t  l_default_apss_chip_select = 0;
    const uint8_t  l_default_spipss_frame_size = 0x20;
    const uint8_t  l_default_spipss_in_delay = 0;
    const uint8_t  l_default_spipss_clock_polarity = 0;
    const uint8_t  l_default_spipss_clock_phase = 0;
    const uint16_t l_default_attr_pm_spipss_clock_divider = 0xA;

    uint32_t l_attr_pss_macro_frequency_mhz;
    uint8_t  l_attr_pm_spipss_select;
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

    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    auto l_pau_vector = i_target.getChildren<fapi2::TARGET_TYPE_PAUC>(fapi2::TARGET_STATE_FUNCTIONAL);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_PAU_MHZ, FAPI_SYSTEM,
                           l_attr_pss_macro_frequency_mhz),
             "Error: Could not fetch the system Frequency")
    FAPI_INF("OCC Frequency: %d Mz", l_attr_pss_macro_frequency_mhz);

    GETATTR_DEFAULT(fapi2::ATTR_SPIPSS_SELECT,
                    "ATTR_SPIPSS_SELECT",
                    i_target, l_attr_pm_spipss_select,
                    l_default_apss_chip_select);

    GETATTR_DEFAULT(fapi2::ATTR_PM_SPIPSS_FRAME_SIZE,
                    "ATTR_PM_SPIPSS_FRAME_SIZE",
                    i_target, l_attr_pm_spipss_frame_size,
                    l_default_spipss_frame_size);

    GETATTR_DEFAULT(fapi2::ATTR_PM_SPIPSS_IN_DELAY,
                    "ATTR_PM_SPIPSS_IN_DELAY",
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
    {
        using namespace scomt::proc;

        //  ******************************************************************
        //     - set SPIPSS_ADC_CTRL_REG0 with the values read from attributes
        //  ******************************************************************
        FAPI_TRY(fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_CR0, l_data64));

        l_data64.insertFromRight<0, 6>(l_attr_pm_spipss_frame_size);
        l_data64.insertFromRight<12, 6>(l_attr_pm_spipss_in_delay);

        FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_CR0, l_data64),
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

        FAPI_TRY(fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_CR1, l_data64));

        l_hwctrl_fsm_enable = 0x1;
        l_hwctrl_nr_of_frames = 0x10;

        l_data64.insertFromRight<0, 1>(l_hwctrl_fsm_enable);
        l_data64.insertFromRight<1, 1>(l_attr_pm_spipss_select);
        l_data64.insertFromRight<2, 1>(l_attr_pm_spipss_clock_polarity);
        l_data64.insertFromRight<3, 1>(l_attr_pm_spipss_clock_phase);
        l_data64.insertFromRight<4, 10>(l_attr_pm_spipss_clock_divider);
        l_data64.insertFromRight<14, 5>(l_hwctrl_nr_of_frames);

        FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_CR1, l_data64),
                 "Error: failed to set the SPIPSS ADC CTRL REG 1 configuration");

        //  ******************************************************************
        //     - set SPIPSS_ADC_CTRL_REG2
        //  ******************************************************************

        FAPI_TRY(fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_CR2, l_data64));
        l_data64.insertFromRight<0, 17>(l_attr_pm_spipss_inter_frame_delay);
        FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_CR2, l_data64),
                 "Error: failed to set the SPIPSS ADC CTRL REG 2 configuration");

        //  ******************************************************************
        //     - clear SPIPSS_ADC_Wdata_REG
        //  ******************************************************************
        l_data64.flush<0>();
        FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_WDATA, l_data64),
                 "Error: Failed to clear SPIPSS ADC WDATA");

        //  ******************************************************************
        //     - set SPIPSS_P2S_CTRL_REG0
        //  ******************************************************************

        FAPI_TRY(fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_P2S_CR0, l_data64));

        l_data64.insertFromRight<0, 6>(l_attr_pm_spipss_frame_size);
        l_data64.insertFromRight<12, 6>(l_attr_pm_spipss_in_delay);

        FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_P2S_CR0, l_data64),
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

        FAPI_TRY(fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_P2S_CR1, l_data64));

        l_p2s_fsm_enable = 0x1;
        l_p2s_nr_of_frames = 0x1;

        l_data64.insertFromRight<0, 1>(l_p2s_fsm_enable);
        l_data64.insertFromRight<1, 1>(l_attr_pm_spipss_select);
        l_data64.insertFromRight<2, 1>(l_attr_pm_spipss_clock_polarity);
        l_data64.insertFromRight<3, 1>(l_attr_pm_spipss_clock_phase);
        l_data64.insertFromRight<4, 10>(l_attr_pm_spipss_clock_divider);
        l_data64.insertFromRight<17, 1>(l_p2s_nr_of_frames);

        FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_P2S_CR1, l_data64),
                 "Error: Failed to set SPIPSS P2S CTRL REG 1");

        //  ******************************************************************
        //     - set SPIPSS_P2S_CTRL_REG2
        //  ******************************************************************

        FAPI_TRY(fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_P2S_CR2, l_data64));
        l_data64.insertFromRight<0, 17>(l_attr_pm_spipss_inter_frame_delay);
        FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_P2S_CR2, l_data64),
                 "Error: Failed to set SPIPSS P2S CTRL REG 2");

        //  ******************************************************************
        //     - clear SPIPSS_P2S_Wdata_REG
        //  ******************************************************************
        l_data64.flush<0>();
        FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_P2S_WDATA, l_data64),
                 "Error: Failed to clear SPI PSS P2S WDATA");

        //  ******************************************************************
        //     - Set 100ns Register for Interframe delay
        //  ******************************************************************
        l_spipss_100ns_value = l_attr_pss_macro_frequency_mhz / 40;
        FAPI_TRY(fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_P2S_100NS, l_data64));
        l_data64.insertFromRight<0, 32>(l_spipss_100ns_value);
        FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_P2S_100NS, l_data64),
                 "Error: Failed to set 100ns clear SPI PSS P2S WDATA");

        //  ******************************************************************
        //  - Enable WOFCNTL Setup
        //  ******************************************************************
        FAPI_TRY( fapi2::getScom( i_target, TP_TPCHIP_OCC_OCI_OCB_WOFICCTRL, l_data64 ),
                  "Error: Failed To Read WOF Cntrl Setup" );
        l_data64.insertFromRight <0, 23>( WOF_CNTRL_SETUP );
        FAPI_TRY( fapi2::putScom( i_target, TP_TPCHIP_OCC_OCI_OCB_WOFICCTRL, l_data64 ),
                  "Error: Failed To Init WOF Cntrl Setup" );

    } // END: using namespace scomt::eq

fapi_try_exit:
    FAPI_IMP("<< pm_pss_start");
    return fapi2::current_err;
}


fapi2::ReturnCode pm_pss_halt(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP(">> pm_pss_halt");

    fapi2::buffer<uint64_t> l_data64;
    uint32_t l_pollcount = 0;
    uint32_t l_max_polls;
    // timeout period is 10 millisecond. (Far longer than needed)
    const uint32_t l_pss_timeout_us = 10000;
    const uint32_t l_pss_poll_interval_us = 10;

    {
        using namespace scomt::proc;

        //  ******************************************************************
        //     - Poll status register for ongoing or no errors to give the
        //       chance for on-going operations to complete
        //  ******************************************************************

        FAPI_INF("Polling for ADC on-going to go low ... ");
        l_max_polls = l_pss_timeout_us / l_pss_poll_interval_us;

        for (l_pollcount = 0; l_pollcount < l_max_polls; l_pollcount++)
        {
            FAPI_TRY(fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_STAT, l_data64));

            // ADC on-going complete
            if (l_data64.getBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_ONGOING>() == 0)
            {
                FAPI_INF("All frames sent from ADC to the APSS device.");
                break;
            }

            // ADC error
            FAPI_ASSERT(!l_data64.getBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_FSM_ERR>(),
                        fapi2::PM_PSS_ADC_ERROR()
                        .set_CHIP(i_target)
                        .set_TP_TPCHIP_OCC_OCI_OCB_ADC_STAT(l_data64)
                        .set_POLLCOUNT(l_pollcount),
                        "Error while sending the frames from ADC to APSS device");

            FAPI_DBG("Delay before next poll");
            fapi2::delay(l_pss_poll_interval_us * 1000, 1000);
        }

        // Write attempted while Bridge busy
        if(l_data64.getBit<TP_TPCHIP_OCC_OCI_OCB_ADC_STAT_HWCTRL_WRITE_WHILE_BRIDGE_BUSY_ERR>() == 1)
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
            FAPI_TRY(fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_P2S_STAT, l_data64));

            //P2S On-going complete
            if (l_data64.getBit<TP_TPCHIP_OCC_OCI_OCB_P2S_STAT_P2S_ONGOING>() == 0)
            {
                FAPI_INF("All frames sent from P2S to the APSS device.");
                break;
            }

            // P2S error
            FAPI_ASSERT(!l_data64.getBit<TP_TPCHIP_OCC_OCI_OCB_P2S_STAT_P2S_FSM_ERR>(),
                        fapi2::PM_PSS_P2S_ERROR()
                        .set_CHIP(i_target)
                        .set_TP_TPCHIP_OCC_OCI_OCB_P2S_STAT(l_data64)
                        .set_POLLCOUNT(l_pollcount),
                        "Error while sending the frames from P2S to APSS device");

            FAPI_DBG("Delay before next poll");
            fapi2::delay(l_pss_poll_interval_us * 1000, 1000);
        }

        FAPI_ASSERT_NOEXIT(!l_data64.getBit<TP_TPCHIP_OCC_OCI_OCB_P2S_STAT_P2S_WRITE_WHILE_BRIDGE_BUSY_ERR>(),
                           fapi2::PM_PSS_ADC_WRITE_WHILE_BUSY()
                           .set_CHIP(i_target)
                           .set_TP_TPCHIP_OCC_OCI_OCB_P2S_STAT(l_data64)
                           .set_POLLCOUNT(l_pollcount),
                           "SPIP2S Write While Bridge Busy bit asserted. Will be cleared with coming reset");

        FAPI_ASSERT_NOEXIT(l_pollcount < l_max_polls,
                           fapi2::PM_PSS_ADC_TIMEOUT()
                           .set_CHIP(i_target)
                           .set_TP_TPCHIP_OCC_OCI_OCB_P2S_STAT(l_data64)
                           .set_POLLCOUNT(l_pollcount)
                           .set_MAXPOLLS(l_max_polls)
                           .set_TIMEOUTUS(l_pss_timeout_us),
                           "SPI P2S did not go to idle in at least % d us. "
                           "Reset of PSS macro is commencing anyway", l_pss_timeout_us );

        //  ******************************************************************
        //     - Resetting both ADC and P2S bridge
        //  ******************************************************************

        FAPI_INF("Resetting P2S and ADC bridges.");

        l_data64.flush<0>();
        // Need to write 01
        l_data64.setBit < TP_TPCHIP_OCC_OCI_OCB_ADC_RESET_OCB_OCI_ADC_RESET_HWCTRL + 1 > ();

        FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_RESET, l_data64),
                 "Error: Could not reset ADC bridge");
        FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_P2S_RESET, l_data64),
                 "Error: Could not reset P2S bridge");

        // Clearing reset for cleanliness
        l_data64.flush<0>();
        FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_RESET, l_data64),
                 "Error: Could not clear the ADC reset register");
        FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_P2S_RESET, l_data64),
                 "Error: Could not clear the P2S reset register");

    } // END: using namespace scomt::eq

fapi_try_exit:
    FAPI_IMP(" << pm_pss_halt");
    return fapi2::current_err;
}
