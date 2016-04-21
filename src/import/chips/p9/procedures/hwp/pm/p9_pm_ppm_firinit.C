/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_ppm_firinit.C $              */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file p9_pm_ppm_firinit.C
/// @brief Configures the CME FIRs, Mask & Actions
///
// *HWP HW Owner: Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 2
// *HWP Consumed by: FSP:HS

/// High-level procedure flow:
/// \verbatim
///   if reset:
///      loop over all functional chiplets (core and quad){
///         Mask all bits of error mask
///      }
///   else if init:
///      loop over all functional chiplets (core and quad) {
///         Mask the required bits
///      }
///
/// Procedure Prereq:
///   o System clocks are running
/// \endverbatim

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <p9_pm_ppm_firinit.H>

// ----------------------------------------------------------------------
// Constant Definitions
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Function prototype
// ----------------------------------------------------------------------

/// @brief Initialize the core and quad's error mask registers
///
/// @param[in] i_target   Chip target
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode pm_ppm_fir_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

/// @brief Reset the core and quad's error mask registers
///
/// @param[in] i_target   Chip target
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode pm_ppm_fir_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------

fapi2::ReturnCode p9_pm_ppm_firinit(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9pm::PM_FLOW_MODE i_mode)
{
    FAPI_IMP("p9_pm_ppm_firinit start");

    if(i_mode == p9pm::PM_RESET)
    {
        FAPI_TRY(pm_ppm_fir_reset(i_target),
                 "ERROR: Failed to reset the Core and Quad error masks");
    }
    else if(i_mode == p9pm::PM_INIT)
    {
        FAPI_TRY(pm_ppm_fir_init(i_target),
                 "ERROR: Failed to initialize Core and Quad error masks");
    }
    else
    {
        FAPI_ASSERT(false, fapi2::PM_PPM_FIRINIT_BAD_MODE().set_BADMODE(i_mode),
                    "ERROR; Unknown mode passed to p9_pm_ppm_firinit. Mode %x",
                    i_mode);
    }

fapi_try_exit:
    FAPI_INF("p9_pm_ppm_firinit end");
    return fapi2::current_err;
}

fapi2::ReturnCode pm_ppm_fir_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP("pm_ppm_fir_init start");

    uint8_t l_firinit_done_flag;
    auto l_eqChiplets = i_target.getChildren<fapi2::TARGET_TYPE_EQ>
                        (fapi2::TARGET_STATE_FUNCTIONAL);

    auto l_coreChiplets = i_target.getChildren<fapi2::TARGET_TYPE_CORE>
                          (fapi2::TARGET_STATE_FUNCTIONAL);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PM_FIRINIT_DONE_ONCE_FLAG,
                           i_target, l_firinit_done_flag),
             "ERROR: Failed to fetch the entry status of FIRINIT");

    for (auto l_eq_chplt : l_eqChiplets)
    {
        p9pmFIR::PMFir <p9pmFIR::FIRTYPE_PPM_LFIR> l_qppmFir(l_eq_chplt);

        // As of now I am just masking all the bits.
        // The exact details about which bits to be masked/unmasked
        // is yet to be known
        FAPI_TRY(l_qppmFir.setAllRegBits(p9pmFIR::REG_ERRMASK),
                 "ERROR: Faled to set the Quad Error MASK");

        if (l_firinit_done_flag)
        {
            /* Restore Quad PPM Error Mask */
            FAPI_TRY(l_qppmFir.restoreSavedMask(),
                     "ERROR: Failed to restore the Quad Error mask saved");
        }

        FAPI_TRY(l_qppmFir.put(),
                 "ERROR:Failed to write to the Quad Error mask FIR MASK");
    }

    for (auto l_core_chplt : l_coreChiplets)
    {
        p9pmFIR::PMFir <p9pmFIR::FIRTYPE_PPM_LFIR> l_cppmFir(l_core_chplt);

        // As of now I am just masking all the bits.
        // The exact details about which bits to be masked/unmasked
        // is yet to be known
        FAPI_TRY(l_cppmFir.setAllRegBits(p9pmFIR::REG_ERRMASK),
                 "ERROR: Failed to set the Core Error MASK");

        if (l_firinit_done_flag)
        {
            /* Restore Core PPM Error Mask */
            FAPI_TRY(l_cppmFir.restoreSavedMask(),
                     "ERROR: Failed to restore the Core Error mask saved");
        }

        FAPI_TRY(l_cppmFir.put(),
                 "ERROR:Failed to write to the Core Error mask");
    }

fapi_try_exit:
    return fapi2::current_err;
}

fapi2::ReturnCode pm_ppm_fir_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP("pm_ppm_fir_reset start");

    uint8_t l_firinit_done_flag;
    auto l_eqChiplets = i_target.getChildren<fapi2::TARGET_TYPE_EQ>
                        (fapi2::TARGET_STATE_FUNCTIONAL);
    auto l_coreChiplets = i_target.getChildren<fapi2::TARGET_TYPE_CORE>
                          (fapi2::TARGET_STATE_FUNCTIONAL);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PM_FIRINIT_DONE_ONCE_FLAG,
                           i_target, l_firinit_done_flag),
             "ERROR: Failed to fetch the entry status of FIRINIT");

    for (auto l_eq_chplt : l_eqChiplets)
    {
        p9pmFIR::PMFir <p9pmFIR::FIRTYPE_PPM_LFIR> l_ppmFir(l_eq_chplt);

        if (l_firinit_done_flag == 1)
        {
            FAPI_TRY(l_ppmFir.get(p9pmFIR::REG_ERRMASK),
                     "ERROR: Failed to get the QUAD ERROR MASK value");

            /* Fetch the QUAD ERROR MASK; Save it to HWP attribute; clear it */
            FAPI_TRY(l_ppmFir.saveMask(),
                     "ERROR: Failed to save Quad ERROR Mask to the attribute");
        }

        FAPI_TRY(l_ppmFir.setAllRegBits(p9pmFIR::REG_ERRMASK),
                 "ERROR: Faled to set the Quad Error MASK");

        FAPI_TRY(l_ppmFir.put(),
                 "ERROR:Failed to write to the Quad Error MASK");
    }

    for (auto l_c_chplt : l_coreChiplets)
    {
        p9pmFIR::PMFir <p9pmFIR::FIRTYPE_PPM_LFIR> l_cppmFir(l_c_chplt);

        if (l_firinit_done_flag == 1)
        {
            FAPI_TRY(l_cppmFir.get(p9pmFIR::REG_ERRMASK),
                     "ERROR: Failed to get the Core ERROR MASK value");

            /* Fetch the core ERROR MASK; Save it to HWP attribute; clear it */
            FAPI_TRY(l_cppmFir.saveMask(),
                     "ERROR: Failed to save Core ERROR Mask to the attribute");
        }

        FAPI_TRY(l_cppmFir.setAllRegBits(p9pmFIR::REG_ERRMASK),
                 "ERROR: Faled to set the Core Error MASK");

        FAPI_TRY(l_cppmFir.put(),
                 "ERROR:Failed to write to the Core Error MASK");
    }

fapi_try_exit:
    return fapi2::current_err;
}
