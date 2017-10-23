/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_reset.C $         */
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
/// @file p9_pm_reset.C
/// @brief Wrapper that calls underlying HWPs to perform a Power Management
///        Reset function when needing to restart the OCC complex.
///
// *HWP HWP Owner        : Greg Still <stillgs@us.ibm.com>
// *HWP HWP Backup Owner : Prasad BG Ranganath <prasadbgr@in.ibm.com>
// *HWP FW Owner         : Prem S Jha <premjha2@in.ibm.com>
// *HWP Team             : PM
// *HWP Level            : 3
// *HWP Consumed by      : HS

///
/// High-level procedure flow:
///
/// @verbatim
///
///     - Mask the OCC FIRs
///     - Halt and then Reset the PPC405
///     - Put all EX chiplets in special wakeup
///     - Mask PBA, PPM and CME FIRs
///     - Reset OCC, PSTATE and STOP GPEs
///     - Reset the Cores and Quads
///     - Reset OCB
///     - Reset PSS
///
/// @endverbatim
///
// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include <p9_pm_reset.H>
#include <p9_pm_utils.H>
#include <p9_setup_evid.H>
#include <p9_quad_scom_addresses.H>
#include <p9_quad_scom_addresses_fld.H>

// -----------------------------------------------------------------------------
// Constant definitions
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Global variables
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Constant Defintions
// -----------------------------------------------------------------------------
enum PPM_MASK
{
    CME_FIRMASK = 0xFFFFFFFF,
    CORE_ERRMASK = 0xFFFFFFFF,
    QUAD_ERRMASK = 0xFFFFFFFF
};

// -----------------------------------------------------------------------------
// Function definitions
// -----------------------------------------------------------------------------

fapi2::ReturnCode p9_pm_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    void* i_pHomerImage = NULL)
{
    FAPI_IMP(">> p9_pm_reset");

    fapi2::buffer<uint64_t> l_data64;
    fapi2::ReturnCode l_rc;

    //  ************************************************************************
    //  Mask the OCC FIRs as errors can occur in what follows
    //  ************************************************************************
    FAPI_DBG("Executing p9_pm_occ_firinit for masking errors in reset operation.");
    FAPI_EXEC_HWP(l_rc, p9_pm_occ_firinit, i_target, p9pm::PM_RESET);
    FAPI_TRY(l_rc, "ERROR: Failed to mask OCC FIRs.");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After masking FIRs"));

    //  ************************************************************************
    //  Halt the OCC PPC405 and reset it safely
    //  ************************************************************************
    FAPI_DBG("Executing p9_pm_occ_control to put OCC PPC405 into reset safely.");
    FAPI_EXEC_HWP(l_rc, p9_pm_occ_control,
                  i_target,
                  p9occ_ctrl::PPC405_RESET_SEQUENCE, //Operation on PPC405
                  p9occ_ctrl::PPC405_BOOT_NULL, // Boot instruction location
                  0); //Jump to 405 main instruction - not used here
    FAPI_TRY(l_rc, "ERROR: Failed to reset OCC PPC405");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After safe reset of OCC PPC405"));

    //  ************************************************************************
    //  Put all EX chiplets in special wakeup
    //  ************************************************************************
    FAPI_DBG("Enable special wakeup for all functional  EX targets.");
    FAPI_TRY(special_wakeup_all(i_target,
                                true),//Enable splwkup
             "ERROR: Failed to remove EX chiplets from special wakeup");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After EX in special wakeup"));

    //  ************************************************************************
    //  Mask the PBA & CME FIRs as errors can occur in what follows
    //  ************************************************************************
    FAPI_DBG("Executing p9_pm_firinit for masking errors in reset operation.");
    FAPI_EXEC_HWP(l_rc, p9_pm_firinit, i_target, p9pm::PM_RESET);
    FAPI_TRY(l_rc, "ERROR: Failed to mask PBA & CME FIRs.");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After masking FIRs"));

    //  ************************************************************************
    //  Issue reset to OCC GPEs ( GPE0 and GPE1) (Bring them to HALT)
    //  ************************************************************************
    FAPI_DBG("Executing p9_pm_occ_gpe_init to reset OCC GPE");
    FAPI_EXEC_HWP(l_rc, p9_pm_occ_gpe_init,
                  i_target,
                  p9pm::PM_RESET,
                  p9occgpe::GPEALL // Apply to both OCC GPEs
                 );
    FAPI_TRY(l_rc, "ERROR: Failed to reset the OCC GPEs");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After reset of OCC GPEs"));

    //  ************************************************************************
    //  Reset the PSTATE GPE (Bring it to HALT)
    //  ************************************************************************
    FAPI_DBG("Executing p9_pm_pstate_gpe_init to reset PGPE");
    FAPI_EXEC_HWP(l_rc, p9_pm_pstate_gpe_init, i_target, p9pm::PM_RESET);
    FAPI_TRY(l_rc, "ERROR: Failed to reset the PGPE");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After reset of PGPE"));

    //  ************************************************************************
    //  Reset the STOP GPE (Bring it to HALT)
    //  ************************************************************************
    FAPI_DBG("Executing p9_pm_stop_gpe_init to reset SGPE");
    FAPI_EXEC_HWP(l_rc, p9_pm_stop_gpe_init, i_target, p9pm::PM_RESET);
    FAPI_TRY(l_rc, "ERROR: Failed to reset SGPE");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After reset of SGPE"));


    //  ************************************************************************
    //  Move PSAFE values to DPLL and Ext Voltage
    //  ************************************************************************
    FAPI_TRY(p9_pm_reset_psafe_update(i_target),
             "Error from p9_pm_reset_psafe_update");
    //  ************************************************************************
    // Clear the OCC Flag and Scratch2 registers
    // which contain runtime settings and modes for PM GPEs (Pstate and Stop functions)
    //  ************************************************************************
    l_data64.flush<0>();
    FAPI_TRY(fapi2::putScom(i_target, PU_OCB_OCI_OCCFLG_SCOM, l_data64),
             "ERROR: Failed to write to OCC Flag Register");
    FAPI_TRY(fapi2::putScom(i_target, PU_OCB_OCI_OCCS2_SCOM, l_data64),
             "ERROR: Failed to write to OCC Scratch2 Register");


    //  ************************************************************************
    //  Reset Cores and Quads
    //  ************************************************************************
    FAPI_DBG("Executing p9_pm_corequad_init to reset cores & quads");
    FAPI_EXEC_HWP(l_rc, p9_pm_corequad_init,
                  i_target,
                  p9pm::PM_RESET,
                  CME_FIRMASK, // CME FIR MASK
                  CORE_ERRMASK,// Core Error Mask
                  QUAD_ERRMASK // Quad Error Mask
                 );
    FAPI_TRY(l_rc, "ERROR: Failed to reset cores & quads");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After reset of core quad"));

    //  ************************************************************************
    //  Issue reset to OCC-SRAM
    //  ************************************************************************
    FAPI_DBG("Executing p8_occ_sram_init to reset OCC-SRAM");
    FAPI_EXEC_HWP(l_rc, p9_pm_occ_sram_init, i_target, p9pm::PM_RESET);
    FAPI_TRY(l_rc, "ERROR: Failed to reset OCC SRAM");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After reset of OCC SRAM"));

    //  ************************************************************************
    //  Issue reset to OCB
    //  ************************************************************************
    FAPI_DBG("Executing p9_pm_ocb_init to reset OCB");
    FAPI_EXEC_HWP(l_rc, p9_pm_ocb_init,
                  i_target,
                  p9pm::PM_RESET,
                  p9ocb::OCB_CHAN0, // Channel
                  p9ocb::OCB_TYPE_NULL, // Channel type
                  0, // Base address
                  0, // Length of circular push/pull queue
                  p9ocb::OCB_Q_OUFLOW_NULL, // Channel flow control
                  p9ocb::OCB_Q_ITPTYPE_NULL // Channel interrupt control
                 );
    FAPI_TRY(l_rc, "ERROR: Failed to reset OCB");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After reset of OCB channels"));

    //  ************************************************************************
    //  Resets P2S and HWC logic
    //  ************************************************************************
    FAPI_DBG("Executing p9_pm_pss_init to reset P2S and HWC logic");
    FAPI_EXEC_HWP(l_rc, p9_pm_pss_init, i_target, p9pm::PM_RESET);
    FAPI_TRY(l_rc, "ERROR: Failed to reset PSS & HWC");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After reset of PSS"));

fapi_try_exit:
    FAPI_IMP("<< p9_pm_reset");
    return fapi2::current_err;
}

fapi2::ReturnCode
p9_pm_reset_psafe_update(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    uint32_t l_safe_mode_freq_dpll = 0;
    bool l_external_voltage_update = false;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_EQ>> l_eqChiplets;
    fapi2::Target<fapi2::TARGET_TYPE_EQ> l_firstEqChiplet;
    fapi2::buffer<uint64_t> l_dpll_data64;
    fapi2::buffer<uint64_t> l_vdm_data64;
    fapi2::buffer<uint64_t> l_dpll_fmult;
    uint32_t l_dpll_mhz;
    fapi2::buffer<uint64_t> l_occflg_data(0);
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    uint8_t l_chipNum = 0xFF;
    fapi2::ATTR_SAFE_MODE_FREQUENCY_MHZ_Type l_attr_safe_mode_freq_mhz;
    fapi2::ATTR_SAFE_MODE_VOLTAGE_MV_Type l_attr_safe_mode_mv;
    fapi2::ATTR_VDD_AVSBUS_BUSNUM_Type l_vdd_bus_num;
    fapi2::ATTR_VDD_AVSBUS_RAIL_Type   l_vdd_bus_rail;
    fapi2::ATTR_VDD_BOOT_VOLTAGE_Type       l_vdd_voltage_mv;
    fapi2::ATTR_FREQ_PROC_REFCLOCK_KHZ_Type l_freq_proc_refclock_khz;
    fapi2::ATTR_PROC_DPLL_DIVIDER_Type      l_proc_dpll_divider;
    fapi2::ATTR_SAFE_MODE_NOVDM_UPLIFT_MV_Type l_uplift_mv;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SAFE_MODE_FREQUENCY_MHZ, i_target, l_attr_safe_mode_freq_mhz));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SAFE_MODE_VOLTAGE_MV, i_target, l_attr_safe_mode_mv));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDD_AVSBUS_BUSNUM, i_target, l_vdd_bus_num));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDD_AVSBUS_RAIL, i_target, l_vdd_bus_rail));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDD_BOOT_VOLTAGE, i_target, l_vdd_voltage_mv));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_DPLL_DIVIDER, i_target, l_proc_dpll_divider));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_PROC_REFCLOCK_KHZ, FAPI_SYSTEM, l_freq_proc_refclock_khz));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SAFE_MODE_NOVDM_UPLIFT_MV, i_target, l_uplift_mv));
    l_attr_safe_mode_mv += l_uplift_mv;

    do
    {
        FAPI_INF(">> p9_pm_reset_psafe_update");
        FAPI_TRY(fapi2::getScom(i_target, PU_OCB_OCI_OCCFLG_SCOM2, l_occflg_data),
                 "Error setting OCC Flag register bit REQUEST_OCC_SAFE_STATE");

        if (l_occflg_data.getBit<p9hcd::PGPE_SAFE_MODE_ACTIVE>())
        {
            FAPI_IMP("PGPE indicates valid safe mode has been achieved");
            break;
        }


        if (!l_attr_safe_mode_freq_mhz || !l_attr_safe_mode_mv)
        {
            break;
        }

        l_eqChiplets = i_target.getChildren<fapi2::TARGET_TYPE_EQ>(fapi2::TARGET_STATE_FUNCTIONAL);

        for ( auto l_itr = l_eqChiplets.begin(); l_itr != l_eqChiplets.end(); ++l_itr)
        {
            l_dpll_fmult.flush<0>();
            FAPI_TRY(fapi2::getScom(*l_itr, EQ_QPPM_DPLL_FREQ , l_dpll_data64),
                     "ERROR: Failed to read EQ_QPPM_DPLL_FREQ");

            l_dpll_data64.extractToRight<EQ_QPPM_DPLL_FREQ_FMULT,
                                         EQ_QPPM_DPLL_FREQ_FMULT_LEN>(l_dpll_fmult);

            // Convert frequency value to a format that needs to be written to the
            // register
            l_safe_mode_freq_dpll = ((l_attr_safe_mode_freq_mhz * 1000) * l_proc_dpll_divider) /
                                    l_freq_proc_refclock_khz;

            FAPI_INF("l_dpll_fmult %08x  l_safe_mode_freq_dpll %08x",
                     l_dpll_fmult, l_safe_mode_freq_dpll);

            // Convert back to the complete frequency value
            l_dpll_mhz =  ((l_dpll_fmult * l_freq_proc_refclock_khz ) / l_proc_dpll_divider ) / 1000;


            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, *l_itr, l_chipNum));
            FAPI_INF("For EQ number %u, l_dpll_mhz %08X l_attr_safe_mode_freq_mhz %08X",
                     l_chipNum, l_dpll_mhz, l_attr_safe_mode_freq_mhz);
            FAPI_INF ("l_vdd_voltage_mv %08x, l_attr_safe_mode_mv %08x", l_vdd_voltage_mv, l_attr_safe_mode_mv);

            //Case 1: The voltage is below the safe value with the frequency
            //above safe value. This is fatal and something is very wrong.
            FAPI_ASSERT(!((l_vdd_voltage_mv < l_attr_safe_mode_mv) && (l_dpll_mhz > l_attr_safe_mode_freq_mhz)),
                        fapi2::PM_RESET_PSAFE_EXT_VDD_VOLT_FAIL()
                        .set_CHIP_TARGET(i_target)
                        .set_DPLL_FREQ(l_dpll_mhz)
                        .set_SAFE_MODE_FREQ(l_attr_safe_mode_freq_mhz)
                        .set_SAFE_MODE_VOLTAGE(l_attr_safe_mode_mv)
                        .set_EXT_VDD_VOLTAGE(l_vdd_voltage_mv),
                        "present external VDD value %08x is less than safe mode voltage %08x",
                        l_vdd_voltage_mv, l_attr_safe_mode_mv);

            FAPI_ASSERT(!((l_vdd_voltage_mv > l_attr_safe_mode_mv) && (l_dpll_mhz < l_attr_safe_mode_freq_mhz)),
                        fapi2::PM_RESET_PSAFE_DPLL_FREQ_FAIL()
                        .set_CHIP_TARGET(i_target)
                        .set_DPLL_FREQ(l_dpll_mhz)
                        .set_SAFE_MODE_FREQ(l_attr_safe_mode_freq_mhz)
                        .set_SAFE_MODE_VOLTAGE(l_attr_safe_mode_mv)
                        .set_EXT_VDD_VOLTAGE(l_vdd_voltage_mv),
                        "present dpll frequency value %08x is less than safe mode frequency %08x",
                        l_dpll_mhz, l_attr_safe_mode_freq_mhz);

            FAPI_ASSERT(!((l_vdd_voltage_mv < l_attr_safe_mode_mv) && (l_dpll_mhz < l_attr_safe_mode_freq_mhz)),
                        fapi2::PM_RESET_PSAFE_BOTH_VOLT_FREQ_FAIL()
                        .set_CHIP_TARGET(i_target)
                        .set_DPLL_FREQ(l_dpll_mhz)
                        .set_SAFE_MODE_FREQ(l_attr_safe_mode_freq_mhz)
                        .set_SAFE_MODE_VOLTAGE(l_attr_safe_mode_mv)
                        .set_EXT_VDD_VOLTAGE(l_vdd_voltage_mv),
                        "present external VDD value %08x is less than safe mode voltage %08x and \
                         DPLL frequency %08x is less than safe mode frequency %08x.",
                        l_vdd_voltage_mv, l_attr_safe_mode_mv, l_dpll_mhz, l_attr_safe_mode_freq_mhz);


            //Case 2 If both VDD voltage and DPLL freq are greater than safe
            //mode values..then apply safe mode values to hw
            if ((l_dpll_mhz > l_attr_safe_mode_freq_mhz) && (l_vdd_voltage_mv >= l_attr_safe_mode_mv))
            {
                l_external_voltage_update = true;
                //FMax
                l_dpll_data64.insertFromRight<EQ_QPPM_DPLL_FREQ_FMAX,
                                              EQ_QPPM_DPLL_FREQ_FMAX_LEN>(l_safe_mode_freq_dpll);
                //FMin
                l_dpll_data64.insertFromRight<EQ_QPPM_DPLL_FREQ_FMIN,
                                              EQ_QPPM_DPLL_FREQ_FMIN_LEN>(l_safe_mode_freq_dpll);
                //FMult
                l_dpll_data64.insertFromRight<EQ_QPPM_DPLL_FREQ_FMULT,
                                              EQ_QPPM_DPLL_FREQ_FMULT_LEN>(l_safe_mode_freq_dpll);

                FAPI_TRY(fapi2::putScom(*l_itr, EQ_QPPM_DPLL_FREQ, l_dpll_data64),
                         "ERROR: Failed to write for EQ_QPPM_DPLL_FREQ");
            }
        } //end of eq list

        //Update Avs Bus voltage
        if (l_external_voltage_update)
        {
            FAPI_TRY(p9_setup_evid_voltageWrite(i_target,
                                                l_vdd_bus_num,
                                                l_vdd_bus_rail,
                                                l_vdd_voltage_mv,
                                                VDD_SETUP),
                     "Error from VDD setup function");
        }

    }
    while (0);

fapi_try_exit:
    return fapi2::current_err;
}
