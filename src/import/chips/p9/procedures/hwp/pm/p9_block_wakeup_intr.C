/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/ipl/hwp/p9_block_wakeup_intr.C $          */
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
/// @file p8_block_wakeup_intr.C
/// @brief Set/reset the BLOCK_REG_WKUP_SOURCES bit in the PCBS-PM associated
///          with an EX chiplet
///
//  *HWP HWP Owner: Amit Kumar <akumar3@us.ibm.com>
//  *HWP FW Owner: Bilicon Patil <bilpatil@in.ibm.com>
//  *HWP Team: PM
//  *HWP Level: 1
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

#include "p9_block_wakeup_intr.H"

// ----------------------------------------------------------------------
// Procedure Function
// ----------------------------------------------------------------------

/// @brief @brief Set/reset the BLOCK_INTR_INPUTS bit in the Core PPM
///         associated with an EX chiplet
fapi2::ReturnCode p9_block_wakeup_intr(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_core_target,
    const p9pmblockwkup::OP_TYPE i_operation )

{
    FAPI_IMP("p9_block_wakeup_intr start");

#if 0
    ecmdDataBufferBase  data(64);

    uint8_t             attr_chip_unit_pos = 0;

    // CPMMR Bit definitions
    const uint32_t      BLOCK_INTR_INPUTS = 11;

    FAPI_DBG("Executing with operation %s to Core %s...",
             p9pmblockwkup::P9_BLKWKUP_OP_STRING[i_operation],
             i_core_target.toEcmdString());


    // Get the core number
    FAPI_TRY(FAPI_ATTR_GET( ATTR_CHIP_UNIT_POS,
                            &i_core_target,
                            attr_chip_unit_pos),
             "fapiGetAttribute of ATTR_CHIP_UNIT_POS failed");

    FAPI_DBG("Core number = %d", attr_chip_unit_pos);

    if (i_operation == p9pmblockwkup::SET)
    {
        FAPI_INF("Setting Block Interrupt Sources...");


    }
    else if (i_operation == p9pmblockwkup::CLEAR)
    {

        FAPI_INF("Clearing Block Interrupt Sources...");


    }
    else
    {
        FAPI_ASSERT(false,
                    BLOCK_WAKEUP_INTR_OP()
                    .set_OPERATION(i_operation),
                    "Invalid operation specified.");
    }


#endif
    FAPI_INF("p9_block_wakeup_intr end");
    return fapi2::current_err;
}
