/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_pfet_init.C $                */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file p9_pfet_init.C
/// @brief  Initialization and reset the EC/EQ chiplet PFET controller
///
// *HWP HWP Owner: Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 1
// *HWP Consumed by: FSP:HS
///
/// High-level procedure flow:
/// \verbatim
///
///     Check for valid parameters
///     if PM_INIT {
///         Get the delay setting held in platform attributes
///         Convert these to hardware values
///         for each EX chiplet {
///             Store the VDD delay and VOFF value
///             Store the VCS delay and VOFF values
///         }
///     } else if PM_RESET {
///         for each EX chiplet {
///             Reset the VDD delay and VOFF values to hardware defaults
///             Reore the VCS delay and VOFF values to hardware defaults
///     }
///
///  Procedure Prereq:
///     - System clocks are running
/// \endverbatim
///
//------------------------------------------------------------------------------


// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include "p9_pm_pfet_init.H"


// ----------------------------------------------------------------------
// Constants
// ----------------------------------------------------------------------

static const uint32_t C_PFETDLY_REG_ADDR_OFFSET   = 0x200F011B;
static const uint32_t C_PFETSENSE_REG_ADDR_OFFSET = 0x2000011C;
static const uint32_t C_PFETOFF_REG_ADDR_OFFSET   = 0x200F011D;

static const uint32_t EQ_PFETDLY_REG_ADDR_OFFSET   = 0x100F011B;
static const uint32_t EQ_PFETSENSE_REG_ADDR_OFFSET = 0x1000011C;
static const uint32_t EQ_PFETOFF_REG_ADDR_OFFSET   = 0x100F011D;

// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------

///
/// @brief Initializes PFET controller.
///
/// @param [in]   i_target          Chip Target
///
/// @param [in]   i_mode            Init or Reset.
///

fapi2::ReturnCode pfet_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint32_t i_mode);

///
/// @brief Set Power Up and Power Down delay to the target specified
///
/// @param [in]   i_target          Chip Target
///
/// @param [in]   i_powerup_delay   PowerUp Delay.
///                                 This gets converted to POWUP_DLY for PFETDLY_REG
///
/// @param [in]   i_powerdown_delay Power Down Delay.
///                                 This gets converted to POWDN_DLY for PFETDLY_REG

template <fapi2::TargetType K >
fapi2::ReturnCode pfet_set_delay(
    const fapi2::Target< K >& i_target,
    const uint8_t       i_powerup_delay,
    const uint8_t       i_powerdown_delay);

///
/// @brief Set Power Up and Power Down delay to the target specified
///
/// @param [in]   i_target          Chip Target
///
/// @param [in]   i_vdd_voff_sel    Voff value for VDD PFETs.
///                                 This gets converted to VDD_VOFF_SET in PFETOFF_REG
///
/// @param [in]   i_vcs_voff_sel    Voff value for VCS PFETs.
///                                 This gets converted to VCS_VOFF_SET in PFETOFF_REG
///
/// @return FAPI2_RC_SUCCESS on success, else error.
///

template <fapi2::TargetType K >
fapi2::ReturnCode pfet_set_voff(
    const fapi2::Target< K >& i_target,
    const uint8_t       i_vdd_voff_sel,
    const uint8_t       i_vcs_voff_sel);

///
/// @brief Helper function to convert time values (binary in ns)to hardware delays
///
/// @param [in]   i_delay
///
/// @param [in]   i_attr_proc_nest_frequency
///
/// @return delays in this register are in terms of PPM clock period

uint8_t convert_delay_to_value (
    const uint32_t   i_delay,
    const uint32_t   i_attr_proc_nest_frequency);

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------

/// \param[in] i_target  Chip target
/// \param[in] i_mode    Control mode (PM_INIT, PM_RESET)
///
/// \retval FAPI_RC_SUCCESS if something good happens,
/// \retval RC per p9_pfet_init_errors.xml otherwise
///
/// \attr  ATTR_PM_PFET_POWERUP_DELAY_NS -
///     Time (in nanoseconds) between PFET controller steps (7 of them)
///     when turning the PFET ON. Applies to both VDD and VCS rails
///
/// \attr  ATTR_PM_PFET_POWERDOWN_DELAY_NS -
///     Time (in nanoseconds) between PFET controller steps (7 of them)
///     when turning the PFES OFF.  Applies to both VDD and VCS rails
///
/// \attr  ATTR_PM_PFET_VDD_VOFF_SEL -
///     Value of the stage withing the PFET controller representing OFF
///     for the VDD rail.  Enum: 0 through 8 inclusive
///
/// \attr  ATTR_PM_PFET_VCS_VOFF_SEL -
///     Value of the stage withing the PFET controller representing OFF
///     for the VCS rail.  Enum: 0 through 8 inclusive

fapi2::ReturnCode p9_pm_pfet_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9pm::PM_FLOW_MODE i_mode)
{
    FAPI_IMP("Entering p9_pm_pfet_init");

    FAPI_DBG("Executing p9_pm_pfet_init in mode %x ....", i_mode);

    FAPI_ASSERT(((i_mode == p9pm::PM_INIT) || (i_mode == p9pm::PM_RESET)),
                fapi2::PFET_INIT_BAD_MODE()
                .set_MODE(i_mode),
                "pm_pfet_init: invalid mode"
                "0x%08X", i_mode);

    switch (i_mode)
    {

        /// -------------------------------
        /// Initialization:  Initialize the PFET hardware
        case p9pm::PM_INIT:

            FAPI_INF("PFET init...");
            FAPI_TRY(pfet_init(i_target, i_mode));
            break;

        /// -------------------------------
        /// Reset:  perform reset of PFETs so that it can reconfigured and
        /// reinitialized
        case p9pm:: PM_RESET:

            FAPI_INF("PFET reset...");
            FAPI_INF("---> None is defined...");
            break;

        default:
            break;
    }

fapi_try_exit:

    FAPI_IMP("Exiting p9_pm_pfet_init");
    return fapi2::current_err;
}

//------------------------------------------------------------------------------
// PFET Initialization Function
//------------------------------------------------------------------------------
fapi2::ReturnCode pfet_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint32_t i_mode)
{

    uint8_t                     l_pfet_powerup_delay_value = 0;
    uint8_t                     l_pfet_powerdown_delay_value = 0;

    uint32_t                    l_proc_refclk_frequency;
    uint32_t                    l_pfet_powerup_delay_ns;
    uint32_t                    l_pfet_powerdown_delay_ns;
    uint8_t                     l_pfet_vdd_voff_sel;
    uint8_t                     l_pfet_vcs_voff_sel;

    // Get all core chiplets
    auto l_core_functional_vector =
        i_target.getChildren<fapi2::TARGET_TYPE_CORE>
        (fapi2::TARGET_STATE_FUNCTIONAL);

    // Get all cache chiplets
    auto l_cache_functional_vector =
        i_target.getChildren<fapi2::TARGET_TYPE_EQ>
        (fapi2::TARGET_STATE_FUNCTIONAL);

    FAPI_DBG("Number chiplets present => Core: %d  Cache: %d",
             l_core_functional_vector.size(),
             l_cache_functional_vector.size());

    /// PFET Sequencing Delays
    ///      convert_pfet_delays() - Convert the following delays from platform
    ///         attributes (binary in nano/ seconds) to PFET delay value feature
    //          attributes.  The conversion uses ATTR_PROC_NEST_FREQUENCY.


    FAPI_INF("Executing pfet_init...");

    //  ******************************************************************
    //  Get Attributes for PFET Delays
    //  ******************************************************************
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    /// ----------------------------------------------------------
    l_proc_refclk_frequency = 0;
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_FREQ_PROC_REFCLOCK_KHZ,
                            FAPI_SYSTEM,
                            l_proc_refclk_frequency),
              "Error getting ATTR_FREQ_PROC_REFCLOCK");


    /// ----------------------------------------------------------
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_PFET_POWERUP_DELAY_NS,
                            FAPI_SYSTEM,
                            l_pfet_powerup_delay_ns),
              "Error getting ATTR_PFET_POWERUP_DELAY_NS");

    /// ----------------------------------------------------------
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_PFET_POWERDOWN_DELAY_NS,
                            FAPI_SYSTEM,
                            l_pfet_powerdown_delay_ns),
              "Error getting ATTR_PFET_POWERDOWN_DELAY_NS");

    /// ----------------------------------------------------------
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_PFET_VDD_VOFF_SEL,
                            FAPI_SYSTEM,
                            l_pfet_vdd_voff_sel),
              "Error getting ATTR_PFET_VDD_VOFF_SEL");

    /// ----------------------------------------------------------
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_PFET_VCS_VOFF_SEL,
                            FAPI_SYSTEM,
                            l_pfet_vcs_voff_sel),
              "Error getting ATTR_PFET_VCS_VOFF_SEL");


    //  ******************************************************************
    //  Calculate Delay values out of PFET Delays
    //  ******************************************************************

    l_pfet_powerup_delay_value =
        convert_delay_to_value( l_pfet_powerup_delay_ns,
                                l_proc_refclk_frequency);

    l_pfet_powerdown_delay_value =
        convert_delay_to_value( l_pfet_powerdown_delay_ns,
                                l_proc_refclk_frequency);


    FAPI_DBG("PFET Power Up Delay");
    FAPI_DBG("  ATTR_PM_PFET_POWERUP_DELAY_NS      : %d (0x%X)",
             l_pfet_powerup_delay_value,
             l_pfet_powerup_delay_value);
    FAPI_DBG("  pfet_powerup_delay_value           :  %X", l_pfet_powerup_delay_value);

    FAPI_DBG("PFET Power Down Delay");
    FAPI_DBG("  ATTR_PM_PFET_POWERDOWN_DELAY_NS    : %d (0x%X)",
             l_pfet_powerdown_delay_value,
             l_pfet_powerdown_delay_value);
    FAPI_DBG("  pfet_powerdown_delay_value         :  %X", l_pfet_powerdown_delay_value);


    //  ******************************************************************
    //  Install in the hardware
    //      Loop through all the present core and cache (EQ) chiplets
    //  ******************************************************************

    for (auto l_chplt_trgt : l_core_functional_vector)
    {
        uint8_t l_attr_chip_unit_pos = 0; //actual value is read in FAPI_ATTR_GET below
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_chplt_trgt,
                               l_attr_chip_unit_pos));

        FAPI_INF("Set PFET values into Core chiplet % d", l_attr_chip_unit_pos);

        // -------------------------------------------------------------
        FAPI_DBG("\tSetting Core Power up Delays");
        FAPI_TRY(pfet_set_delay<fapi2::TargetType::TARGET_TYPE_CORE>(l_chplt_trgt,
                 l_pfet_powerup_delay_value,
                 l_pfet_powerdown_delay_value),
                 "Error: pfet_set_delay for core!!");


        // -------------------------------------------------------------
        FAPI_DBG("Setting Core Voff Settings");
        FAPI_TRY(pfet_set_voff<fapi2::TargetType::TARGET_TYPE_CORE>(l_chplt_trgt,
                 l_pfet_vdd_voff_sel,
                 l_pfet_vcs_voff_sel),
                 "Error: pfet_set_off for core!!");

    } // core chiplet loop

    // Process all cache chiplets
    for (auto l_chplt_trgt : l_cache_functional_vector)
    {
        uint8_t l_attr_chip_unit_pos = 0; //actual value is read in FAPI_ATTR_GET below
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_chplt_trgt,
                               l_attr_chip_unit_pos));

        FAPI_INF("Set PFET values into Cache chiplet % d", l_attr_chip_unit_pos);

        // -------------------------------------------------------------
        FAPI_DBG("Setting Cache Power up Delays");
        FAPI_TRY(pfet_set_delay<fapi2::TargetType::TARGET_TYPE_EQ>(l_chplt_trgt,
                 l_pfet_powerup_delay_value,
                 l_pfet_powerdown_delay_value),
                 "Error: pfet_set_delay for cache!!");


        // -------------------------------------------------------------
        FAPI_DBG("Setting Cache Voff Settings");
        FAPI_TRY(pfet_set_voff<fapi2::TargetType::TARGET_TYPE_EQ>(l_chplt_trgt,
                 l_pfet_vdd_voff_sel,
                 l_pfet_vcs_voff_sel),
                 "Error: pfet_set_off for cache!!");

    } // core chiplet loop


fapi_try_exit:
    return fapi2::current_err;
}


//------------------------------------------------------------------------------
// pfet_set_delay
//  Helper function to set delay registers
//------------------------------------------------------------------------------
template <fapi2::TargetType K >
fapi2::ReturnCode pfet_set_delay(
    const fapi2::Target< K >& i_target,
    const uint8_t       i_powerup_delay,
    const uint8_t       i_powerdown_delay)
{
    fapi2::buffer<uint64_t> l_data64 = 0;

    uint32_t PFETDLY_REG = 0;

    if(i_target.getType() & fapi2::TARGET_TYPE_CORE)
    {
        PFETDLY_REG = C_PFETDLY_REG_ADDR_OFFSET;
    }
    else
    {
        PFETDLY_REG = EQ_PFETDLY_REG_ADDR_OFFSET;
    }

    const uint32_t POWDN_DLY_FLD_START = 0;
    const uint32_t POWDN_DLY_FLD_LEN = 4;
    const uint32_t POWUP_DLY_FLD_START = 4;
    const uint32_t POWUP_DLY_FLD_LEN = 4;

    l_data64.insertFromRight<POWDN_DLY_FLD_START, POWDN_DLY_FLD_LEN>(i_powerdown_delay);
    l_data64.insertFromRight<POWUP_DLY_FLD_START, POWUP_DLY_FLD_LEN>(i_powerup_delay);

    FAPI_TRY(fapi2::putScom(i_target, PFETDLY_REG , l_data64));

fapi_try_exit:
    return fapi2::current_err;
}



//------------------------------------------------------------------------------
// pfet_set_voff
//  Helper function to set OFF registers
//------------------------------------------------------------------------------
template <fapi2::TargetType K >
fapi2::ReturnCode pfet_set_voff(
    const fapi2::Target< K >& i_target,
    const uint8_t       i_vdd_voff_sel,
    const uint8_t       i_vcs_voff_sel)
{
    fapi2::buffer<uint64_t> l_data64 = 0;

    uint32_t PFETOFF_REG = 0;

    if(i_target.getType() & fapi2::TARGET_TYPE_CORE)
    {
        PFETOFF_REG = C_PFETOFF_REG_ADDR_OFFSET;
    }
    else
    {
        PFETOFF_REG = EQ_PFETOFF_REG_ADDR_OFFSET;
    }

    const uint32_t VDD_VOFF_SEL_FLD_START = 0;
    const uint32_t VDD_VOFF_SEL_FLD_LEN = 4;
    const uint32_t VCS_VOFF_SEL_FLD_START = 4;
    const uint32_t VCS_VOFF_SEL_FLD_LEN = 4;


    l_data64.insertFromRight<VDD_VOFF_SEL_FLD_START, VDD_VOFF_SEL_FLD_LEN>(i_vdd_voff_sel);
    l_data64.insertFromRight<VCS_VOFF_SEL_FLD_START, VCS_VOFF_SEL_FLD_LEN>(i_vcs_voff_sel);

    FAPI_TRY(fapi2::putScom(i_target, PFETOFF_REG , l_data64));

fapi_try_exit:
    return fapi2::current_err;
}

//------------------------------------------------------------------------------
// convert_delay_to_value
//  Helper function to convert time values (binary in ns)to hardware delays
//------------------------------------------------------------------------------
// @todo can this be done in a better way?
uint8_t
convert_delay_to_value (uint32_t i_delay,
                        uint32_t i_proc_nest_frequency)
{
    uint8_t   pfet_delay_value;
    float     dly;
    //  attr_proc_nest_frequency [MHz]
    //  delay [ns]
    //  pfet_delay_value = 15 - log2( i_delay * i_attr_proc_nest_frequency/1000);
    //  since log2 function is not available, this is done manually
    //  pfet_delay_value = 15 - log2( dly );
    dly = ( i_delay * i_proc_nest_frequency / 1000);

    if ( dly <= 1.4 )
    {
        pfet_delay_value = 15 - 0 ;
    }
    else if (( 1.4   < dly ) && ( dly <= 2.8 )  )
    {
        pfet_delay_value = 15 - 1 ;
    }
    else if (( 2.8   < dly ) && ( dly <= 5.6 )  )
    {
        pfet_delay_value = 15 - 2 ;
    }
    else if (( 5.6   < dly ) && ( dly <= 11.5 ) )
    {
        pfet_delay_value = 15 - 3 ;
    }
    else if (( 11.5  < dly ) && ( dly <= 23 )   )
    {
        pfet_delay_value = 15 - 4 ;
    }
    else if (( 23    < dly ) && ( dly <= 46 )   )
    {
        pfet_delay_value = 15 - 5 ;
    }
    else if (( 46    < dly ) && ( dly <= 92 )   )
    {
        pfet_delay_value = 15 - 6 ;
    }
    else if (( 92    < dly ) && ( dly <= 182 )  )
    {
        pfet_delay_value = 15 - 7 ;
    }
    else if (( 182   < dly ) && ( dly <= 364 )  )
    {
        pfet_delay_value = 15 - 8 ;
    }
    else if (( 364   < dly ) && ( dly <= 728 )  )
    {
        pfet_delay_value = 15 - 9 ;
    }
    else if (( 728   < dly ) && ( dly <= 1456 ) )
    {
        pfet_delay_value = 15 - 10;
    }
    else if (( 1456  < dly ) && ( dly <= 2912 ) )
    {
        pfet_delay_value = 15 - 11;
    }
    else if (( 2912  < dly ) && ( dly <= 5824 ) )
    {
        pfet_delay_value = 15 - 12;
    }
    else if (( 5824  < dly ) && ( dly <= 11648 ))
    {
        pfet_delay_value = 15 - 13;
    }
    else if (( 11648 < dly ) && ( dly <= 23296 ))
    {
        pfet_delay_value = 15 - 14;
    }
    else if  ( 23296 < dly )
    {
        pfet_delay_value = 15 - 15;
    }
    else
    {
        pfet_delay_value = 15 - 15;
    }

    return (pfet_delay_value);
}

