/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_block_wakeup_intr.C $           */
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
/// @file p9_block_wakeup_intr.C
/// @brief Set/reset the BLOCK_REG_WKUP_SOURCES bit in the PCBS-PM associated
///          with an EX chiplet
///
//  *HWP HWP Owner: Amit Kumar <akumar3@us.ibm.com>
//  *HWP FW Owner: Prem Jha <premjha1@in.ibm.com>
//  *HWP Team: PM
//  *HWP Level: 2
//  *HWP Consumed by: FSP:HS
///
/// @verbatim
/// High-level procedure flow:
///
///   With set/reset enum parameter, either set or clear PMGP0(53)
///
/// Procedure Prereq:
///    - System clocks are running
/// @endverbatim
///
//------------------------------------------------------------------------------


// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------

#include <p9_block_wakeup_intr.H>
#include <p9_hcd_common.H>



// This must stay in sync with enum OP_TYPE enum in header file
const char* OP_TYPE_STRING[] =
{
    "SET",
    "CLEAR"
};


// ----------------------------------------------------------------------
// Procedure Function
// ----------------------------------------------------------------------

/// @brief @brief Set/reset the BLOCK_INTR_INPUTS bit in the Core PPM
///         associated with an EX chiplet

fapi2::ReturnCode
p9_block_wakeup_intr(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_core_target,
    const p9pmblockwkup::OP_TYPE i_operation)
{
    FAPI_INF("> p9_block_wakeup_intr...");

    fapi2::buffer<uint64_t> l_data64 = 0;

    // Get the core number
    uint8_t l_attr_chip_unit_pos = 0;

    fapi2::Target<fapi2::TARGET_TYPE_PERV> l_perv =
        i_core_target.getParent<fapi2::TARGET_TYPE_PERV>();

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                           l_perv,
                           l_attr_chip_unit_pos),
             "fapiGetAttribute of ATTR_CHIP_UNIT_POS failed");
    l_attr_chip_unit_pos = l_attr_chip_unit_pos - p9hcd::PERV_TO_CORE_POS_OFFSET;

    // Read for trace
    {
        fapi2::buffer<uint64_t> l_cpmmr = 0;
        fapi2::buffer<uint64_t> l_gpmmr = 0;

        // Read the CPMMR and GPMMR as a trace
        FAPI_TRY(fapi2::getScom(i_core_target,
                                C_CPPM_CPMMR,
                                l_cpmmr),
                 "getScom of CPMMR failed");

        FAPI_TRY(fapi2::getScom(i_core_target,
                                C_PPM_GPMMR,
                                l_gpmmr),
                 "getScom of GPMMR failed");

        FAPI_DBG("Debug: before setting PPM_WRITE_OVERRIDE on Core %d - CPPMR: 0x%016llX GPMMR: 0x%016llX",
                 l_attr_chip_unit_pos, l_cpmmr, l_gpmmr);
    }

    // Ensure access to the GPMMR is in place using CPMMR Write Access
    // Override.  This will not affect the CME functionality as only the
    // Block Wake-up bit is being manipulated -- a bit that the CME does
    // not control but does react upon.

    FAPI_INF("Set the CPPM PPM Write Override");
    l_data64.flush<0>().setBit<C_CPPM_CPMMR_PPM_WRITE_OVERRIDE>();
    FAPI_TRY(fapi2::putScom(i_core_target,
                            C_CPPM_CPMMR_OR,
                            l_data64),
             "putScom of CPMMR to set PMM Write Override failed");

    l_data64.flush<0>().setBit<BLOCK_REG_WKUP_EVENTS>();

    switch (i_operation)
    {
        case p9pmblockwkup::SET:

            // @todo RTC 144905 Add Special Wakeup setting here when available

            FAPI_INF("Setting GPMMR[Block Interrupt Sources] on Core %d",
                     l_attr_chip_unit_pos);

            FAPI_TRY(fapi2::putScom(i_core_target,
                                    C_PPM_GPMMR_OR,
                                    l_data64),
                     "Setting GPMMR failed");

            // @todo RTC 144905 Add Special Wakeup clearing here when available

            break;

        case p9pmblockwkup::SET_NOSPWUP:
            FAPI_INF("Setting GPMMR[Block Interrupt Sources] without Special Wake-up on Core %d",
                     l_attr_chip_unit_pos);

            FAPI_TRY(fapi2::putScom(i_core_target,
                                    C_PPM_GPMMR_OR,
                                    l_data64),
                     "Setting GPMMR failed");
            break;

        case p9pmblockwkup::CLEAR:
            FAPI_INF("Clearing GPMMR[Block Interrupt Sources] on Core %d",
                     l_attr_chip_unit_pos);

            FAPI_TRY(fapi2::putScom(i_core_target,
                                    C_PPM_GPMMR_CLEAR,
                                    l_data64),
                     "Clearing GPMMR failed");
            break;

        default:
            ;
    }

    FAPI_INF("Clear the CPPM PPM Write Override");
    l_data64.flush<0>().setBit<C_CPPM_CPMMR_PPM_WRITE_OVERRIDE>();
    FAPI_TRY(fapi2::putScom(i_core_target,
                            C_CPPM_CPMMR_CLEAR,
                            l_data64),
             "putScom of CPMMR to clear PMM Write Override failed");

fapi_try_exit:
    FAPI_INF("< p9_block_wakeup_intr...");
    return fapi2::current_err;
}
