/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pss_init.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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
// $Id: p8_pss_init.C,v 1.8 2013/11/08 22:36:48 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pss_init.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE : p8_pss_init.C
// *! DESCRIPTION : Initializes P2S and HWC logic
// *! OWNER NAME  : Pradeep CN   Email: padeepcn@in.ibm.com
// *! BACKUP NAME :              Email:
// #! ADDITIONAL COMMENTS :
//
//
/// Procedure Summary:
/// --------------------
///    One procedure to initialize both P2S and HWC SPIPSS registers to
///    second Procedure is to access APSS or DPSS through P2S Bridge
///    Third procedure is to access APSS or DPSS through HWC (hardware control)
///
///    High-level procedure flow:
///     ----------------------------------
///      o INIT PROCEDURE(frame_size,cpol,cpha)
///         - set SPIPSS_ADC_CTRL_REG0(24b)
///             hwctrl_frame_size = 16
///         - set SPIPSS_ADC_CTRL_REG1
///             hwctrl_fsm_enable = disable
///             hwctrl_device     = APSS
///             hwctrl_cpol       = 0 (set idle state = deasserted)
///             hwctrl_cpha       = 0 (set 1st edge = capture 2nd edge = change)
///             hwctrl_clock_divider = set to 10Mhz(0x1D)
///             hwctrl_nr_of_frames (4b) = 16 (for auto 2 mode)
///         - set SPIPSS_ADC_CTRL_REG2
///                      hwctrl_interframe_delay = 0x0
///              - clear SPIPSS_ADC_WDATA_REG
///         - set SPIPSS_P2S_CTRL_REG0 (24b)
///             p2s_frame_size  = 16
///         - set SPIPSS_P2S_CTRL_REG1
///             p2s_bridge_enable = disable
///             p2s_device        = DPSS
///             p2s_cpol          = 0
///             p2s_cpha          = 0
///             p2s_clock_divider = set to 10Mhz
///             p2s_nr_of_frames (1b) = 0 (means 1 frame operation)
///         - set SPIPSS_P2S_CTRL_REG2
///                      p2s_interframe_delay = 0x0
///              - clear SPIPSS_P2S_WDATA_REG
/// Procedure Prereq:
///   o System clocks are running
///
///------------------------------------------------------------------------------


// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------

#include "p8_pm.H"
#include "p8_pss_init.H"

extern "C" {

using namespace fapi;

// ----------------------------------------------------------------------
// Global variables
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------
fapi::ReturnCode pss_config_spi_settings(const Target& i_target);
fapi::ReturnCode pss_init(const Target& i_target);
fapi::ReturnCode pss_reset(const Target& i_target);

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------

//------------------------------------------------------------------------------
/**
 * p8_pss_init calls the underlying routine based on mode parameter
 *
 * @param[in] i_target Chip target
 * @param[in] mode     Control mode for the procedure
 *                     PM_INIT, PM_CONFIG, PM_RESET
 *
 * @retval ECMD_SUCCESS
 * @retval ERROR defined in xml
 */
fapi::ReturnCode
p8_pss_init(const Target &i_target, uint32_t mode)
{
    fapi::ReturnCode    rc;

    /// -------------------------------
    /// Configuration:  perform translation of any Platform Attributes into Feature Attributes
    /// that are applied during Initalization
    if (mode == PM_CONFIG)
    {
        rc = pss_config_spi_settings(i_target);
    }
    /// -------------------------------
    /// Initialization:  perform order or dynamic operations to initialize
    /// the PMC using necessary Platform or Feature attributes.
    else if (mode == PM_INIT)
    {
        rc = pss_init(i_target);
    }
    /// -------------------------------
    /// Reset:  perform reset of PSS
    else if (mode == PM_RESET)
    {
        rc = pss_reset(i_target);
    }
    /// -------------------------------
    /// Unsupported Mode
    else
    {
        FAPI_ERR("Unknown mode passed to p8_pss_init. Mode %x ....", mode);
        const fapi::Target & CHIP = i_target;
        uint32_t & IMODE = mode;
        FAPI_SET_HWP_ERROR(rc, RC_PROCPM_PSS_CODE_BAD_MODE);
    } 

    return rc;

} // p8_pss_init

//------------------------------------------------------------------------------
/**
 * pss_config_spi_settings Determines the configuration setting for the SPI
 *              bus based on attributes
 *
 * @param[in] i_target Chip target
 *
 *
 * @retval ECMD_SUCCESS
 * @retval ERROR defined in xml
 */
fapi::ReturnCode
pss_config_spi_settings(const Target& i_target)
{
    fapi::ReturnCode rc;

    uint32_t        attr_proc_pss_init_nest_frequency=2400;
    uint32_t        attr_pm_pss_init_spipss_frequency=10;
    uint8_t         attr_pm_spipss_clock_divider ;
    uint32_t        attr_pm_spipss_interframe_delay_setting=0 ;
    uint32_t        attr_pm_spipss_interframe_delay = 0 ;

    const uint32_t  default_spipss_frequency = 1;  // MHz
    const uint32_t  default_spipss_interframe_delay = 10000;  // MHz

    FAPI_INF("PSS config start...");
    do
    {

        //----------------------------------------------------------
        GETATTR(        rc,
                        ATTR_FREQ_PB,
                        "ATTR_FREQ_PB",
                        NULL,
                        attr_proc_pss_init_nest_frequency);

        //----------------------------------------------------------
        GETATTR_DEFAULT(rc,
                        ATTR_PM_SPIPSS_FREQUENCY,
                        "ATTR_PM_SPIPSS_FREQUENCY",
                        NULL,
                        attr_pm_pss_init_spipss_frequency,
                        default_spipss_frequency);

        // calculation of clock divider
        attr_pm_spipss_clock_divider = ((attr_proc_pss_init_nest_frequency /
                                         attr_pm_pss_init_spipss_frequency)/ 8 )-1 ;


        SETATTR(        rc,
                        ATTR_PM_SPIPSS_CLOCK_DIVIDER,
                        "ATTR_PM_SPIPSS_CLOCK_DIVIDER",
                        &i_target,
                        attr_pm_spipss_clock_divider);

        // ########################### SET INTER_FRAM_DELAY ################################ //

        //----------------------------------------------------------
        // Delay between command and status frames of a SPIVID WRITE operation
        // (binary in nanoseconds)ATTR_PM_SPIPSS_INTER_FRAME_DELAY


        GETATTR_DEFAULT(    rc,
                            ATTR_PM_SPIPSS_INTER_FRAME_DELAY,
                            "ATTR_PM_SPIPSS_INTERFRAME_DELAY",
                            &i_target,
                            attr_pm_spipss_interframe_delay,
                            default_spipss_interframe_delay);

        // Delay is computed as: (value * ~100ns_hang_pulse)
        // +0/-~100ns_hang_pulse time
        // Thus, value = delay / 100
        attr_pm_spipss_interframe_delay_setting =
        attr_pm_spipss_interframe_delay/ 100;

        SETATTR(            rc,
                            ATTR_PM_SPIPSS_INTER_FRAME_DELAY_SETTING ,
                            "ATTR_PM_SPIPSS_INTER_FRAME_DELAY_SETTING",
                            &i_target,
                            attr_pm_spipss_interframe_delay_setting);

    } while(0);

    FAPI_INF("PSS config end...\n");
    return rc;

} // pss_config_spi_settings

//------------------------------------------------------------------------------
/**
 * pss_init Using configured attributed, performs the initialization of the PSS
 *          function
 *
 * @param[in] i_target Chip target
 *
 *
 * @retval ECMD_SUCCESS
 * @retval ERROR defined in xml
 */
fapi::ReturnCode
pss_init(const Target& i_target)
{
    fapi::ReturnCode rc;
    uint32_t            e_rc = 0;
    ecmdDataBufferBase  data(64);

    const uint8_t       default_spipss_frame_size = 16 ;
    const uint8_t       default_spipss_in_delay = 0 ;
    const uint8_t       default_spipss_clock_polarity = 0 ;
    const uint8_t       default_spipss_clock_phase = 0 ;
    const uint8_t       default_apss_chip_select = 1 ;

    uint32_t            attr_proc_pss_init_nest_frequency=2400;
    uint8_t             attr_pm_spipss_clock_divider ;

    uint8_t             attr_pm_apss_chip_select=1 ;

    uint8_t             attr_pm_spipss_frame_size ;
    uint8_t             attr_pm_spipss_in_delay ;
    uint8_t             attr_pm_spipss_clock_polarity ;
    uint8_t             attr_pm_spipss_clock_phase ;
    uint32_t            attr_pm_spipss_inter_frame_delay ;

    FAPI_INF("PSS initialization start...");
    do
    {

        //----------------------------------------------------------
        GETATTR_DEFAULT(rc,
                        ATTR_PM_SPIPSS_FRAME_SIZE,
                        "ATTR_PM_SPIPSS_FRAME_SIZE",
                        &i_target,
                        attr_pm_spipss_frame_size,
                        default_spipss_frame_size );

        //----------------------------------------------------------
        GETATTR_DEFAULT(rc,
                        ATTR_PM_SPIPSS_IN_DELAY,
                        "ATTR_PM_SPIPSS_IN_DELAY",
                        &i_target,
                        attr_pm_spipss_in_delay,
                        default_spipss_in_delay );

        //----------------------------------------------------------
        GETATTR_DEFAULT(rc,
                        ATTR_PM_SPIPSS_CLOCK_POLARITY,
                        "ATTR_PM_SPIPSS_CLOCK_POLARITY",
                        &i_target,
                        attr_pm_spipss_clock_polarity,
                        default_spipss_clock_polarity );

        //----------------------------------------------------------
        GETATTR_DEFAULT(rc,
                        ATTR_PM_SPIPSS_CLOCK_PHASE,
                        "ATTR_PM_SPIPSS_CLOCK_PHASE",
                        &i_target,
                        attr_pm_spipss_clock_phase,
                        default_spipss_clock_phase );

        //----------------------------------------------------------
        GETATTR(        rc,
                        ATTR_PM_SPIPSS_INTER_FRAME_DELAY_SETTING,
                        "ATTR_PM_SPIPSS_INTER_FRAME_DELAY_SETTING",
                        &i_target,
                        attr_pm_spipss_inter_frame_delay);

        //----------------------------------------------------------
        GETATTR_DEFAULT(rc,
                        ATTR_PM_APSS_CHIP_SELECT,
                        "ATTR_PM_APSS_CHIP_SELECT",
                        &i_target,
                        attr_pm_apss_chip_select,
                        default_apss_chip_select );

        //----------------------------------------------------------
        GETATTR(        rc,
                        ATTR_PM_SPIPSS_CLOCK_DIVIDER,
                        "ATTR_PM_SPIPSS_CLOCK_DIVIDER",
                        &i_target,
                        attr_pm_spipss_clock_divider);


        //----------------------------------------------------------
        GETATTR(        rc,
                        ATTR_FREQ_PB,
                        "ATTR_FREQ_PB",
                        NULL,
                        attr_proc_pss_init_nest_frequency);

        // ------------------------------------------
        //  -- Init procedure
        // ------------------------------------------

        uint8_t       hwctrl_target = 0xA;
        uint8_t       hwctrl_frame_size           = attr_pm_spipss_frame_size ;
        uint8_t       hwctrl_in_delay             = attr_pm_spipss_in_delay ;
        uint8_t       hwctrl_clk_pol              = attr_pm_spipss_clock_polarity ;
        uint8_t       hwctrl_clk_pha              = attr_pm_spipss_clock_phase ;
        uint32_t      hwctrl_clk_divider          = attr_pm_spipss_clock_divider ;
        uint32_t      hwctrl_inter_frame_delay    = attr_pm_spipss_inter_frame_delay ;
        uint8_t       hwctrl_device               = attr_pm_apss_chip_select;
        uint32_t      nest_freq                   = attr_proc_pss_init_nest_frequency ;
        uint32_t      spipss_100ns_div_value ;


        spipss_100ns_div_value = (( attr_proc_pss_init_nest_frequency ) /40);

        //  ******************************************************************
        //     - set SPIPSS_ADC_CTRL_REG0 (24b)
        //         adc_frame_size = 16
        //  ******************************************************************

        rc = fapiGetScom(i_target, SPIPSS_ADC_CTRL_REG0_0x00070000, data );
        if (rc)
        {
            FAPI_ERR("fapiGetScom(SPIPSS_ADC_CTRL_REG0) failed.");
            break;
        }

        e_rc |= data.insertFromRight(hwctrl_frame_size,0,6);
        e_rc |= data.insertFromRight(hwctrl_in_delay,12,6);
        if (e_rc)
        {
            rc.setEcmdError(e_rc);
            break;
        }

        FAPI_INF("    SPIPSS ADC CTRL_REG_0 Configuration                  ");
        FAPI_INF("      frame size                 => %d ", hwctrl_frame_size);

        rc = fapiPutScom(i_target, SPIPSS_ADC_CTRL_REG0_0x00070000, data );
        if (rc)
        {
            FAPI_ERR("fapiPutScom(SPIPSS_ADC_CTRL_REG0_0x00070000) failed.");
            break;
        }

        //  ******************************************************************
        //     - set SPIPSS_ADC_CTRL_REG1
        //         adc_fsm_enable = disable
        //         adc_device     = APSS
        //         adc_cpol       = 0
        //         adc_cpha       = 0
        //         adc_clock_divider = set to 10Mhz
        //         adc_nr_of_frames (4b) = 16 (for auto 2 mode)
        //  ******************************************************************

        rc = fapiGetScom(i_target, SPIPSS_ADC_CTRL_REG1_0x00070001, data );
        if (rc)
        {
            FAPI_ERR("fapiGetScom(SPIPSS_ADC_CTRL_REG1) failed.");
            break;
        }

        uint8_t   hwctrl_fsm_enable = 0x1 ;
        uint8_t   hwctrl_nr_of_frames = 0x10 ;

        e_rc |= data.insertFromRight(hwctrl_fsm_enable   ,0,1);
        e_rc |= data.insertFromRight(hwctrl_device       ,1,1);
        e_rc |= data.insertFromRight(hwctrl_clk_pol      ,2,1);
        e_rc |= data.insertFromRight(hwctrl_clk_pha      ,3,1);
        e_rc |= data.insertFromRight(hwctrl_clk_divider  ,4,10);
        e_rc |= data.insertFromRight(hwctrl_nr_of_frames ,14,4);
        if (e_rc)
        {
            rc.setEcmdError(e_rc);
            break;
        }

        FAPI_INF("    SPIPSS ADC CTRL_REG_1 Configuration                  ");
        FAPI_INF("      hwctrl_fsm_enable          => %d ", hwctrl_fsm_enable  );
        FAPI_INF("      nest_freq                  => %d ", nest_freq  );
        FAPI_INF("      hwctrl_target              => %d ", hwctrl_target      );
        FAPI_INF("      hwctrl_device              => %d ", hwctrl_device      );
        FAPI_INF("      hwctrl_clk_pol             => %d ", hwctrl_clk_pol     );
        FAPI_INF("      hwctrl_clk_pha             => %d ", hwctrl_clk_pha     );
        FAPI_INF("      hwctrl_clk_divider         => %d ", hwctrl_clk_divider );
        FAPI_INF("      hwctrl_nr_of_frames        => %d ", hwctrl_nr_of_frames);

        rc = fapiPutScom(i_target, SPIPSS_ADC_CTRL_REG1_0x00070001, data );
        if (rc)
        {
            FAPI_ERR("fapiPutScom(SPIPSS_ADC_CTRL_REG1_0x00070001) failed.");
            break;
        }

        //  ******************************************************************
        //     - set SPIPSS_ADC_CTRL_REG2
        //         adc_inter_frame_delay = 0x0
        //  ******************************************************************

        rc = fapiGetScom(i_target, SPIPSS_ADC_CTRL_REG2_0x00070002, data );
        if (rc)
        {
            FAPI_ERR("fapiGetScom(SPIPSS_ADC_CTRL_REG2) failed.");
            break;
        }

        e_rc = data.insertFromRight(hwctrl_inter_frame_delay,0,17);
        if (e_rc)
        {
            rc.setEcmdError(e_rc);
            break;
        }


        FAPI_INF("    SPIPSS ADC CTRL_REG_2 Configuration                  ");
        FAPI_INF("      hwctrl_inter_frm_delay     => %d ", hwctrl_inter_frame_delay );

        rc = fapiPutScom(i_target, SPIPSS_ADC_CTRL_REG2_0x00070002, data );
        if (rc)
        {
            FAPI_ERR("fapiPutScom(SPIPSS_ADC_CTRL_REG2_0x00070002) failed.");
            break;
        }

        //  ******************************************************************
        //     - clear SPIPSS_ADC_Wdata_REG
        //  ******************************************************************

        uint32_t   hwctrl_wdata    = 0x0;

        e_rc |= data.flushTo0();
        e_rc |= data.insertFromRight(hwctrl_wdata    ,0,16);
        if (e_rc)
        {
            rc.setEcmdError(e_rc);
            break;
        }

        FAPI_INF("    SPIPSS_WDATA_REG is cleared                             ");
        FAPI_INF("      hwctrl_wdata               => %d ", hwctrl_wdata       );

        rc = fapiPutScom(i_target, SPIPSS_ADC_WDATA_REG_0x00070010, data );
        if (rc)
        {
            FAPI_ERR("fapiPutScom(SPIPSS_ADC_WDATA_REG_0x00070010) failed.");
            break;
        }

        //  ******************************************************************
        //     - set SPIPSS_P2S_CTRL_REG0 (24b)
        //         p2s_frame_size = 16
        //  ******************************************************************

        rc = fapiGetScom(i_target, SPIPSS_P2S_CTRL_REG0_0x00070040, data );
        if (rc)
        {
            FAPI_ERR("fapiGetScom(SPIPSS_P2S_CTRL_REG0) failed.");
            break;
        }

        // modify_data here
        uint8_t   p2s_frame_size = 0x02 ;
        uint8_t   p2s_device     = 0;
        uint8_t   p2s_clk_pol    = 0;
        uint8_t   p2s_clk_pha    = 0;
        uint16_t  p2s_clk_divider= 0x1D;
        uint8_t   p2s_target = 0xA;// DPSS
        uint32_t  p2s_inter_frame_delay = 0x0;
        uint8_t   p2s_in_delay;

        p2s_frame_size      =    attr_pm_spipss_frame_size ;
        p2s_in_delay        =    attr_pm_spipss_in_delay ;
        p2s_clk_pol         =    attr_pm_spipss_clock_polarity ;
        p2s_clk_pha         =    attr_pm_spipss_clock_phase ;
        p2s_clk_divider     =    attr_pm_spipss_clock_divider ;
        p2s_inter_frame_delay =  attr_pm_spipss_inter_frame_delay ;
        p2s_device          = attr_pm_apss_chip_select;


        //  ******************************************************************
        //     - set SPIPSS_P2S_CTRL_REG0
        //  ******************************************************************

        rc = fapiGetScom(i_target, SPIPSS_P2S_CTRL_REG0_0x00070040, data );
        if (rc)
        {
            FAPI_ERR("fapiGetScom(SPIPSS_P2S_CTRL_REG0) failed.");
            break;
        }

        e_rc |= data.insertFromRight(p2s_frame_size,0,6);
        e_rc |= data.insertFromRight(p2s_in_delay,12,6);
        if (e_rc)
        {
            rc.setEcmdError(e_rc);
            break;
        }

        FAPI_INF("    SPIPSS P2S CTRL_REG_0 Configuration                  ");
        FAPI_INF("      frame size                 => %d ", p2s_frame_size);
        FAPI_INF("      p2s_in_delay               => %d ", p2s_in_delay  );

        rc = fapiPutScom(i_target, SPIPSS_P2S_CTRL_REG0_0x00070040, data );
        if (rc)
        {
            FAPI_ERR("fapiPutScom(SPIPSS_P2S_CTRL_REG0_0x00070040) failed.");
            break;
        }

        //  ******************************************************************
        //     - set SPIPSS_P2S_CTRL_REG1
        //         p2s_fsm_enable = disable
        //         p2s_device     = APSS
        //         p2s_cpol       = 0
        //         p2s_cpha       = 0
        //         p2s_clock_divider = set to 10Mhz
        //         p2s_nr_of_frames (4b) = 16 (for auto 2 mode)
        //  ******************************************************************

        rc = fapiGetScom(i_target, SPIPSS_P2S_CTRL_REG1_0x00070041, data );
        if (rc)
        {
            FAPI_ERR("fapiGetScom(SPIPSS_P2S_CTRL_REG1) failed.");
            break;
        }

        // modify_data here

        uint8_t   p2s_fsm_enable = 0x1 ;
        uint8_t   p2s_nr_of_frames = 0x10 ;

        e_rc |= data.insertFromRight(p2s_fsm_enable   ,0,1);
        e_rc |= data.insertFromRight(p2s_device       ,1,1);
        e_rc |= data.insertFromRight(p2s_clk_pol      ,2,1);
        e_rc |= data.insertFromRight(p2s_clk_pha      ,3,1);
        e_rc |= data.insertFromRight(p2s_clk_divider  ,4,10);
        e_rc |= data.insertFromRight(p2s_nr_of_frames ,14,4);
        if (e_rc)
        {
            rc.setEcmdError(e_rc);
            break;
        }

        FAPI_INF("    SPIPSS P2S CTRL_REG_1 Configuration                  ");
        FAPI_INF("      p2s_fsm_enable          => %d ", p2s_fsm_enable  );
        FAPI_INF("      p2s_target              => %d ", p2s_target      );
        FAPI_INF("      p2s_device              => %d ", p2s_device      );
        FAPI_INF("      p2s_clk_pol             => %d ", p2s_clk_pol     );
        FAPI_INF("      p2s_clk_pha             => %d ", p2s_clk_pha     );
        FAPI_INF("      p2s_clk_divider         => %d ", p2s_clk_divider );
        FAPI_INF("      p2s_nr_of_frames        => %d ", p2s_nr_of_frames);

        rc = fapiPutScom(i_target, SPIPSS_P2S_CTRL_REG1_0x00070041, data );
        if (rc)
        {
            FAPI_ERR("fapiPutScom(SPIPSS_P2S_CTRL_REG1_0x00070041) failed.");
            break;
        }

        //  ******************************************************************
        //     - set SPIPSS_P2S_CTRL_REG2
        //         p2s_inter_frame_delay = 0x0
        //  ******************************************************************

        rc = fapiGetScom(i_target, SPIPSS_P2S_CTRL_REG2_0x00070042, data );
        if (rc)
        {
            FAPI_ERR("fapiGetScom(SPIPSS_P2S_CTRL_REG2) failed.");
            break;
        }

        e_rc |= data.insertFromRight(p2s_inter_frame_delay,0,17);
        if (e_rc)
        {
            rc.setEcmdError(e_rc);
            break;
        }

        FAPI_INF("    SPIPSS P2S CTRL_REG_2 Configuration                  ");
        FAPI_INF("      p2s_inter_frm_delay     => %d ", p2s_inter_frame_delay );

        rc = fapiPutScom(i_target, SPIPSS_P2S_CTRL_REG2_0x00070042, data );
        if (rc)
        {
            FAPI_ERR("fapiPutScom(SPIPSS_P2S_CTRL_REG2_0x00070042) failed.");
            break;
        }


        //  ******************************************************************
        //     - clear SPIPSS_P2S_Wdata_REG
        //  ******************************************************************
        rc = fapiGetScom(i_target, SPIPSS_P2S_WDATA_REG_0x00070050, data );
        if (rc)
        {
            FAPI_ERR("fapiGetScom(SPIPSS_P2S_WDATA_REG_0x00070050) failed.");
            break;
        }

        uint32_t   p2s_wdata    = 0x0;
        e_rc |= data.flushTo0();
        e_rc |= data.insertFromRight(p2s_wdata    ,0,16);
        if (e_rc)
        {
            rc.setEcmdError(e_rc);
            break;
        }

        FAPI_INF("    SPIPSS_P2S_WDATA_REG is cleared                           ");
        FAPI_INF("      p2s_wdata               => %d ", p2s_wdata       );
        FAPI_INF("                                       "                     );

        rc = fapiPutScom(i_target, SPIPSS_P2S_WDATA_REG_0x00070050, data );
        if (rc)
        {
            FAPI_ERR("fapiPutScom(SPIPSS_P2Sb_WDATA_REG_0x00070050) failed.");
            break;
        }

        //  ******************************************************************
        //     - Set 100ns Register for Interframe delay
        //  ******************************************************************
        rc = fapiGetScom(i_target, SPIPSS_100NS_REG_0x00070028, data );
        if (rc)
        {
            FAPI_ERR("fapiGetScom(SPIPSS_100NS_REG_0x00070028) failed.");
            break;
        }

        e_rc=data.insertFromRight(spipss_100ns_div_value ,0,32);
        if (e_rc)
        {
            rc.setEcmdError(e_rc);
            break;
        }

        FAPI_INF("    SPIPSS_100NS_REG is set the value                     ");
        FAPI_INF("      spipss_100ns_div_value_hi     => %d ", spipss_100ns_div_value       );
        FAPI_INF("        nest_freq                   => %d ", nest_freq                     );
        FAPI_INF("                                       "                     );

        rc = fapiPutScom(i_target, SPIPSS_100NS_REG_0x00070028, data );
        if (rc)
        {
            FAPI_ERR("fapiPutScom(SPIPSS_100NS_REG_0x00070028) failed.");
            break;
        }

    } while(0);

    FAPI_INF("PSS initialization end...\n");
    return rc;
} // pss_init


//------------------------------------------------------------------------------
/**
 * pss_reset Performs the reset of the PSS function
 *
 * @param[in] i_target Chip target
 *
 *
 * @retval ECMD_SUCCESS
 * @retval ERROR defined in xml
 */
fapi::ReturnCode
pss_reset(const Target& i_target)
{
    fapi::ReturnCode    rc;
    uint32_t            e_rc = 0;
    ecmdDataBufferBase  data(64);

    uint32_t            pollcount = 0;
    uint32_t            max_polls;
    const uint32_t      pss_timeout_us = 10000;  // 10 millisecond.  Far longer than needed
    const uint32_t      pss_poll_interval_us = 10;

    FAPI_INF("PSS reset start...");
    do
    {

        //  ******************************************************************
        //     - Poll status register for ongoing or no errors to give the
        //       chance for on-going operations to complete
        //  ******************************************************************

        FAPI_DBG("Polling for ADC on-going to go low ... ");
        max_polls = pss_timeout_us / pss_poll_interval_us;
        for (pollcount = 0; pollcount < max_polls; pollcount++)
        {
            rc = fapiGetScom(i_target, SPIPSS_ADC_STATUS_REG_0x00070003, data );
            if (rc)
            {
                FAPI_ERR("fapiGetScom(SPIPSS_ADC_STATUS_REG_0x00070003) failed.");
                break;
            }
            // Ongoing is not set OR an error
            if (data.isBitClear(0) || data.isBitSet(7))
            {
                break;
            }
            FAPI_DBG("Delay before next poll");
            e_rc = fapiDelay(pss_poll_interval_us*1000, 1000);  // ns, sim clocks
            if (e_rc)
            {
                FAPI_ERR("fapiDelay error");
                rc.setEcmdError(e_rc);
                break;
            }
        }
        if (!rc.ok())
        {
            break;
        }
        if (data.isBitSet(7))
        {
            FAPI_ERR("SPIADC error bit asserted waiting for operation to complete.");
            const fapi::Target & CHIP = i_target;
            FAPI_SET_HWP_ERROR(rc, RC_PROCPM_PSS_ADC_ERROR);
            break;
        }
        if (pollcount >= max_polls)
        {
            FAPI_INF("WARNING: SPI ADC did not go to idle in at least %d us.  Reset of PSS macro is commencing anyway", pss_timeout_us);
            break;
        }
        else
        {
            FAPI_INF("All frames sent from ADC to the APSS device.");
        }

        //  ******************************************************************
        //     - Poll status register for ongoing or errors to give the
        //       chance for on-going operations to complete
        //  ******************************************************************

        FAPI_INF("Polling for P2S on-going to go low ... ");
        for (pollcount = 0; pollcount < max_polls; pollcount++)
        {
            rc = fapiGetScom(i_target, SPIPSS_P2S_STATUS_REG_0x00070043, data );
            if (rc)
            {
                FAPI_ERR("fapiGetScom(SPIPSS_P2S_STATUS_REG_0x00070043) failed.");
                break;
            }
           
            // Ongoing is not set OR an error
            if (data.isBitClear(0) || data.isBitSet(7))
            {
                break;
            }
            FAPI_DBG("Delay before next poll");
            e_rc = fapiDelay(pss_poll_interval_us*1000, 1000);  // ns, sim clocks
            if (e_rc)
            {
                rc.setEcmdError(e_rc);
                break;
            }            
        }
        if (!rc.ok())
        {
            break;
        }
        if (data.isBitSet(7))
        {
            FAPI_ERR("SPIP2S FSM error bit asserted waiting for operation to complete.");
            const fapi::Target & CHIP = i_target;
            FAPI_SET_HWP_ERROR(rc, RC_PROCPM_PSS_P2S_ERROR);
            break;
        }
        if (data.isBitSet(5))
        {
            FAPI_INF("SPIP2S Write While Bridge Busy bit asserted.  Will be cleared with coming reset");
        }
        if (pollcount >= max_polls)
        {
            FAPI_INF("WARNING: SPI P2S did not go to idle in at least %d us.  Reset of PSS macro is commencing anyway", pss_timeout_us);
        }
        else
        {
            FAPI_INF("SAll frames sent from P2S to the APSS device.");
        }

        //  ******************************************************************
        //     - Resetting both ADC and P2S bridge
        //  ******************************************************************

        FAPI_INF("Resetting P2S and ADC bridges.");

        e_rc=data.flushTo0();
        e_rc=data.setBit(1);
        if (e_rc)
        {
            rc.setEcmdError(e_rc);
            break;
        }

        rc = fapiPutScom(i_target,  SPIPSS_ADC_RESET_REGISTER_0x00070005 , data);
        if (rc)
        {
            FAPI_ERR("fapiPutScom(SPIPSS_ADC_RESET_REGISTER_0x00070005) failed.");
            break;
        }

        rc = fapiPutScom(i_target,  SPIPSS_P2S_RESET_REGISTER_0x00070045 , data);
        if (rc)
        {
            FAPI_ERR("fapiPutScom(SPIPSS_P2S_RESET_REGISTER_0x00070045) failed.");
            break;
        }
        
        // Clearing reset for cleanliness (SW229669)
        e_rc=data.flushTo0();
        if (e_rc)
        {
            rc.setEcmdError(e_rc);
            break;
        }
               
        rc = fapiPutScom(i_target,  SPIPSS_ADC_RESET_REGISTER_0x00070005 , data);
        if (rc)
        {
            FAPI_ERR("fapiPutScom(SPIPSS_ADC_RESET_REGISTER_0x00070005) failed.");
            break;
        }

        rc = fapiPutScom(i_target,  SPIPSS_P2S_RESET_REGISTER_0x00070045 , data);
        if (rc)
        {
            FAPI_ERR("fapiPutScom(SPIPSS_P2S_RESET_REGISTER_0x00070045) failed.");
            break;
        }
    } while (0);

    FAPI_INF("PSS reset end...\n");
    return rc;
} // pss_reset


} //end extern C
