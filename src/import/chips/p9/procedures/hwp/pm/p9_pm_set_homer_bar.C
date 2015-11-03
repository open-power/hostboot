/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_set_homer_bar.C $            */
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
/// @file p9_pm_set_homer_bar.C
/// @brief Setup a PBABAR to locate the HOMER region for the OCC complex

// *HWP HWP Owner       : Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Bilicon Patil <bilpatil@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 2
// *HWP Consumed by     : HS
///
///
/// High-level procedure flow:
/// \verbatim
///
///     Address and size of HOMER for the target (chip) is passed based on
///     where the caller has allocated this memory for this target.
///
///     The Base Address and a size mask for the region is passed.  This is
///     used to establish the PBA BAR and mask hardware to set the legal
///     bounds for OCC complex accesses.
///
///     The BAR defines address bits 14:43 in natural bit alignment (eg no
///     shifting)
///
///     The Size (in MB) of the region where region is located.
///         If not a power of two value, the value will be rounded up to the
///         next power of 2 for setting the hardware mask
///
///         If 0 is defined and the BAR is also defined as 0, then the BAR
///         is set (to 0) but no image accessing is done as this is considered
///         a BAR reset condition.
///
///         If 0 is defined and the BAR is NOT 0, an error is returned as this
///         is defining a zero sized, real region.
///
///     Flow (given BAR and Size are ok per the above)
///        Check that passed address is within the 56 bit real address range
///        Check that image address + image size does not extend past the 56 bit
///            boundary
///
///        Call p9_pba_bar_config to set up PBA BAR 0 with the address and
///            size of the HOMER region as passed via calling parameters
///         i_mem_bar and i_mem_size.
///
///  Procedure Prereq:
///     - HOMER memory region has been allocated.
///
///  CQ Class:  power_management
/// \endverbatim
///
//-------------------------------------------------------------------------------


// ------------------------------------------------------------------------------
// Includes
// ------------------------------------------------------------------------------
#include <fapi2.H>
#include "p9_misc_scom_addresses.H"
#include "p9_pm_set_homer_bar.H"
#include "p9_pm.H"
#include "p9_pm_pba_init.H"
#include "p9_pm_pba_bar_config.H"



// ------------------------------------------------------------------------------
// Constant definitions
// ------------------------------------------------------------------------------
static const uint64_t BAR_MASK_MB_ALIGN = 0x00000000000FFFFFull;

// The value here will yield the appropriate nibble for accessing the PowerBus

enum PBA_BARS
{
    PBA_BAR0    = 0x0,
    PBA_BAR1    = 0x1,
    PBA_BAR2    = 0x2,
    PBA_BAR3    = 0x3
};


// ------------------------------------------------------------------------------
// Function definitions
// ------------------------------------------------------------------------------


/// \param[in] i_target     Procesor Chip target
/// \param[in] i_mem_bar    Base address of the region where image is located
/// \param[in] i_mem_size   Size (in MB) of the region where image is located
///                         if not a power of two value, the value will be
///                         rounded up to the next power of 2 for setting the
///                         hardware mask.  The value of 0 is only legal if
///                         i_mem_bar is also 0;  else an error is indicated.
///
fapi2::ReturnCode
p9_pm_set_homer_bar(  const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                      const uint64_t i_mem_bar,
                      const uint64_t i_mem_size)
{

    fapi2::ReturnCode    l_rc;
    uint64_t region_masked_address;

    // Hardcoded use of PBA BAR and SCOPE
    //const uint32_t      pba_bar = PBA_BAR0;
    //p9pba::CMD_SCOPE    slw_pba_cmd_scope = p9pba::GROUP;

    FAPI_INF("Entering p9_pm_set_homer_bar ...");

    // Check to make sure mem_bar is also 0 when mem_size is 0.
    FAPI_ASSERT(!((i_mem_size == 0) && (i_mem_bar != 0)),
                fapi2::P9_PM_SET_HOMER_BAR_SIZE_INVALID().set_MEM_BAR(i_mem_bar)
                .set_MEM_SIZE(i_mem_size),
                "ERROR:HOMER Size is 0 but BAR is non-zero:0x%16llx", i_mem_bar);
    // check that bar address passed in 1MB aligned(eg bits 44:63 are zero)

    region_masked_address = i_mem_bar & BAR_MASK_MB_ALIGN;
    FAPI_ASSERT(!(region_masked_address != 0),
                fapi2::P9_PM_SET_HOMER_BAR_NOT_1MB_ALIGNED().set_MEM_BAR(i_mem_bar),
                "ERROR: i_mem_bar:0x%16llx is not 1MB aligned ", i_mem_bar);

    FAPI_DBG("Calling pba_bar_config with BAR %x Addr: 0x%16llX  Size: 0x%16llX",
             PBA_BAR0, i_mem_bar, i_mem_size);

    // Set the PBA BAR for the HOMER base
    FAPI_EXEC_HWP(l_rc, p9_pm_pba_bar_config, i_target,
                  PBA_BAR0,
                  i_mem_bar,
                  i_mem_size,
                  p9pba::GROUP, 0);

    fapi2::current_err = l_rc;


fapi_try_exit:
    return fapi2::current_err;

}
