/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_pfet_init.C $     */
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
    const uint32_t i_delay_ns,
    const uint32_t i_proc_nest_frequency_MHz);

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

    uint32_t                    l_proc_nest_frequency;
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
    l_proc_nest_frequency = 0;
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_FREQ_PB_MHZ,
                            FAPI_SYSTEM,
                            l_proc_nest_frequency),
              "Error getting ATTR_FREQ_PB_MHZ");


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
                                l_proc_nest_frequency);

    l_pfet_powerdown_delay_value =
        convert_delay_to_value( l_pfet_powerdown_delay_ns,
                                l_proc_nest_frequency);


    FAPI_DBG("PFET Power Up Delay");
    FAPI_DBG("  ATTR_PM_PFET_POWERUP_DELAY_NS      : %d (0x%X)",
             l_pfet_powerup_delay_ns,
             l_pfet_powerup_delay_ns);
    FAPI_DBG("  pfet_powerup_delay_value           : %X", l_pfet_powerup_delay_value);

    FAPI_DBG("PFET Power Down Delay");
    FAPI_DBG("  ATTR_PM_PFET_POWERDOWN_DELAY_NS    : %d (0x%X)",
             l_pfet_powerdown_delay_ns,
             l_pfet_powerdown_delay_ns);
    FAPI_DBG("  pfet_powerdown_delay_value         : %X", l_pfet_powerdown_delay_value);


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
//
//  The hardware uses a 1 in the power of 2 bit position of a 16 bit counter
//  to indicate a delay match.  As the LSb of the counter will become a 1 every
//  other cycle, there is an inherent multiply by 2 built in.  Thus, the smallest
//  delay possible is 2 x the counter frequency (eg for a 2GHz nest with PFET
//  controller logic running at /4 of that indicates a 2ns cycle time.  With a
//  power of 2 of 0 (eg bit 15 of the counter) indicates a match on that LSb
//  every 4ns).
//------------------------------------------------------------------------------
// @todo can this be done in a better way?
uint8_t
convert_delay_to_value (const uint32_t i_delay_ns,
                        const uint32_t i_proc_nest_frequency_MHz)
{
    uint8_t   pfet_delay_value = 0xFF;  // An illegal value
    uint64_t  dly;

    //  i_attr_proc_nest_frequency_MHz (Mcycles/s * M/M = cycles/us)

    //  PPM cycle time (ns/cycle) = 1/PPM frequency_MHz [1/(cycles/us)]
    //                            = 1/PPM frequency_MHz [us/cycle]
    //                            = (1/PPM frequency_MHz)* 1000 ns/cycle
    //
    //  PPM frequency_MHz (cycles/us) =  i_attr_proc_nest_frequency_MHz / 4 (cycles/us)
    //
    //  delay_ns = 2 * PPM cycle time (ns) * 2**(15-N)
    //          where N (pfet_delay value) is the bit position of a 16 bit counter
    //          that has the least significant bit toggling every other cycle.
    //          The every other cycle is the reason for the 2 * cycle time.
    //
    //  delay_ns / (2 * PPM cycle time (ns)) = 2**(15-N)
    //  (delay_ns / 2) * PPM frequency (cycles/ns) = 2**(15-N)
    //  (delay_ns / 2) * PPM frequency_MHz/1000 (cycles/us * us/1000ns -> cycles/ns) = 2**(15-N)
    //  log2(delay_ns/2 * PPM Frequency_MHz/1000) = 15-N
    //  N (pfet_delay_value) = 15 - log2(delay_ns/2 * PPM Frequency_MHz/1000);
    //  N (pfet_delay_value) = 15 - log2(i_delay_ns/2 * (i_attr_proc_nest_frequency_MHz/4)/1000);
    //
    //  dly = i_delay_ns/2 * (i_attr_proc_nest_frequency_MHz/4)/1000
    //  pfet_delay_value = 15 - log2( dly );

    dly = i_delay_ns / 2 * (i_proc_nest_frequency_MHz / 4 ) / 1000;
    FAPI_DBG("i_delay_ns = %d (0x%X), i_proc_nest_frequency_MHz = %d (0x%X), "
             "ppm_frequency_MHz = %d (0x%X),  dly = %d (0x%08llX)",
             i_delay_ns, i_delay_ns,
             i_proc_nest_frequency_MHz, i_proc_nest_frequency_MHz,
             i_proc_nest_frequency_MHz / 4, i_proc_nest_frequency_MHz / 4,
             dly, dly );

    uint16_t pow2bit_value = 0x8000;
    uint16_t value   = (uint16_t)dly;

    // For log2, walk a 1 across the data to find the 2**i that is less than
    // or equal.
    for (uint32_t i = 0; i < 16; ++i)
    {
        if (pow2bit_value == value)         // Matched exactly.  We found the bit
        {
            FAPI_DBG("EQ i = %d pow2bit_value = 0x%04X,  value = 0x%04X", i, pow2bit_value, value);
            pfet_delay_value = i;
            break;
        }
        else if (pow2bit_value < value)     // Found bit that was less than
        {
            if (i == 0)
            {
                FAPI_DBG("LT but saturated: i = %d pow2bit_value = 0x%04X,  value = 0x%04X", i, pow2bit_value, value);
                pfet_delay_value = i;
            }
            else
            {
                FAPI_DBG("LT but rounding up: i = %d pow2bit_value = 0x%04X,  value = 0x%04X", i, pow2bit_value, value);
                pfet_delay_value = i - 1;   // Power of 2 eg round up
            }

            break;
        }
        else                                // shift it right to check the next bit
        {
            pow2bit_value >>= 1;
        }
    }

    FAPI_DBG("pfet_delay_value = %d (0x%X))",
             pfet_delay_value, pfet_delay_value );

    return (pfet_delay_value);
}

