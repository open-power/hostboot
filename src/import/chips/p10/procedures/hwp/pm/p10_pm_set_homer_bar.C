/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_set_homer_bar.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
/// @file p10_pm_set_homer_bar.C
/// @brief Setup a PBABAR to locate the HOMER region for the OCC complex

// *HWP Owner           :   Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        :   Prem S Jha <premjha2@in.ibm.com>
// *HWP Team            :   PM
// *HWP Level           :   3
// *HWP Consumed by     :   HS
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
///             boundary
///
///        Set up PBA BAR 0 with the address and
///             size of the HOMER region as passed via calling parameters
///             i_mem_bar and i_mem_size.
///
///        Set up QME BARs for BCE and PPE accesses with the address and
///             size HOMER region as passed via calling parameters
///             i_mem_bar and i_mem_size.
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
#include "p10_pm_set_homer_bar.H"
#include "p10_pm.H"
#include <p10_scom_proc.H>
#include <p10_scom_eq.H>
#include <multicast_group_defs.H>

// ------------------------------------------------------------------------------
// Constant definitions
// ------------------------------------------------------------------------------
static const uint64_t BAR_MASK_4MB_ALIGN = 0x00000000003FFFFFull;

// The value here will yield the appropriate nibble for accessing the PowerBus

enum PBA_BARS
{
    PBA_BAR0    = 0x0,
    PBA_BAR1    = 0x1,
    PBA_BAR2    = 0x2,
    PBA_BAR3    = 0x3
};

enum BAR_ADDR_RANGE
{
    BAR_ADDR_RANGECHECK_HIGH = 0xFF00000000000000ull,
    BAR_ADDR_RANGECHECK_LOW  = 0x00000000000FFFFFull
};

using namespace scomt::proc;
const uint64_t PBA_BARs[4] =
{
    TP_TPBR_PBA_PBAO_PBABAR0,
    TP_TPBR_PBA_PBAO_PBABAR1,
    TP_TPBR_PBA_PBAO_PBABAR2,
    TP_TPBR_PBA_PBAO_PBABAR3
};

const uint64_t PBA_BARMSKs[4] =
{
    TP_TPBR_PBA_PBAO_PBABARMSK0,
    TP_TPBR_PBA_PBAO_PBABARMSK1,
    TP_TPBR_PBA_PBAO_PBABARMSK2,
    TP_TPBR_PBA_PBAO_PBABARMSK3
};

// Valid command scope.
enum CMD_SCOPE
{
    LOCAL_NODAL    = 0x00,
    NEAR_NODE      = 0x02,
    GROUP          = 0x03,
    REMOTE_NODE    = 0x04,
    VECTORED_GROUP = 0x5
};


// -----------------------------------------------------------------------------
// Function definitions
// -----------------------------------------------------------------------------
///
/// @brief Round up to next higher power of 2
///
/// @param [in] i_value     p10_pm_qme_bar_config.C   Input value
/// @return Next higher power of 2 of i_value.
///         If i_value is already a power of 2, return i_value.
///
inline uint64_t PowerOf2Roundedup (uint64_t i_value)
{
    if (i_value < 0)
    {
        return 0;
    }

    --i_value;
    i_value |= i_value >> 1;
    i_value |= i_value >> 2;
    i_value |= i_value >> 4;
    i_value |= i_value >> 8;
    i_value |= i_value >> 16;
    return i_value + 1;
}



///
/// @brief Initialize the QME BARs
///
/// @param [in] i_target        Reference to Proc chip target
/// @param [in] i_index         Identifies the set of BAR/BARMSK registers [0-3]
/// @param [in] i_qme_bar_addr  QME base address - 1MB granularity
/// @param [in] i_qme_bar_size  QME region size in MB; If not a power of two,
///                             the value will be rounded up to the next power
///                             of 2.
///
/// @return FAPI_RC_SUCCESS on success or error return code
///
fapi2::ReturnCode pm_qme_bar_config (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_qme_bar_addr,
    const uint64_t i_qme_bar_size)
{

    using namespace scomt::eq;

    FAPI_DBG(">> p10_pm_qme_bar_config...");

    fapi2::buffer<uint64_t> l_bar64;
    uint64_t                l_work_size;
    uint32_t                l_bce_size_encode;

    FAPI_DBG("p10_pm_qme_bar_config: address 0x%016llX, size 0x%016llX",
             i_qme_bar_addr, i_qme_bar_size);

    auto l_eq_mc  =
        i_target.getMulticast<fapi2::TARGET_TYPE_EQ >(fapi2::MCGROUP_GOOD_EQ);

    // Check if QME BAR address is within range,
    // High order bits checked to ensure a valid real address
    FAPI_ASSERT((BAR_ADDR_RANGECHECK_HIGH & i_qme_bar_addr) == 0x0ull,
                fapi2::PM_QME_ADDR_OUT_OF_RANGE()
                .set_BAR_ADDR(i_qme_bar_addr)
                .set_BAR_SIZE(i_qme_bar_size)
                .set_EXP_BAR_ADDR_RANGECHECK_HIGH(BAR_ADDR_RANGECHECK_HIGH),
                "ERROR: Address out of Range : i_qme_bar_addr = 0x%016llX & "
                "Upper permissible limit = 0x%016llX", i_qme_bar_addr,
                BAR_ADDR_RANGECHECK_HIGH);

    // Low order bits checked for alignment
    FAPI_ASSERT((BAR_ADDR_RANGECHECK_LOW & i_qme_bar_addr) == 0x0ull,
                fapi2::PM_QME_ADDR_ALIGNMENT_ERROR()
                .set_BAR_ADDR(i_qme_bar_addr)
                .set_BAR_SIZE(i_qme_bar_size)
                .set_EXP_BAR_ADDR_RANGECHECK_LOW(BAR_ADDR_RANGECHECK_LOW),
                "ERROR: Address must be on a 1MB boundary : i_qme_bar_addr="
                "0x%016llX & Alignment limit=0x%016llX", i_qme_bar_addr,
                BAR_ADDR_RANGECHECK_LOW);

    // The combination of both the BAR size and addr being zero is legal.
    // But, if the BAR size is 0 and the BAR addr is not zero return error.
    FAPI_ASSERT(!((i_qme_bar_size == 0) && (i_qme_bar_addr != 0)),
                fapi2::PM_QME_BAR_SIZE_INVALID()
                .set_BAR_ADDR(i_qme_bar_addr)
                .set_BAR_SIZE(i_qme_bar_size),
                "ERROR: Bar size of 0 but non-zero i_qme_bar_size=0x%016llx",
                i_qme_bar_size);

    // Create the BCE BAR value
    l_bar64.set(i_qme_bar_addr);
    FAPI_DBG("i_qme_bar_addr: 0x%016llX vs l_bar64: 0x%016llX", i_qme_bar_addr, l_bar64);

    if (i_qme_bar_size != 0)
    {
        l_work_size = PowerOf2Roundedup(i_qme_bar_size);
        FAPI_INF("i_qme_bar_size: 0x%016llX.  Final work_size: 0x%016llX",
                 i_qme_bar_size, l_work_size);
    }
    else
    {
        // If bar_size==0, treat as if == 2. Otherwize, range will max out to 2TB
        l_work_size = PowerOf2Roundedup(2ull);
        FAPI_INF("i_qme_bar_size: 0x%016llX but treated as if bar_size=1. "
                 "Final work_size: 0x%016llX", i_qme_bar_size, l_work_size);
    }

    l_bce_size_encode = (uint32_t)log2(l_work_size >> 20); // MB units
    FAPI_DBG("size encode = 0x%02X", l_bce_size_encode);

    l_bar64.insertFromRight<QME_BCEBAR0_SIZE,
                            QME_BCEBAR0_SIZE_LEN>(l_bce_size_encode);

    FAPI_DBG("after: 0x%016llX", l_bar64);

    FAPI_TRY(fapi2::putScom(l_eq_mc, QME_BCEBAR0, l_bar64));

fapi_try_exit:
    FAPI_DBG("<< p10_pm_qme_bar_config...");
    return fapi2::current_err;
}


// -----------------------------------------------------------------------------
// Function definitions
// -----------------------------------------------------------------------------
///
/// @brief Initialize PAB_BAR (address) and PAB_BARMSK (mask/size)
///
/// @param [in] i_target        Reference to Proc chip target
/// @param [in] i_index         Identifies the set of BAR/BARMSK registers [0-3]
/// @param [in] i_pba_bar_addr  PBA base address - 1MB granularity
/// @param [in] i_pba_bar_size  PBA region size in MB; If not a power of two,
///                             the value will be rounded up to the next power
///                             of 2 for setting hardware mask
fapi2::ReturnCode pm_pba_bar_config (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint32_t i_index,
    const uint64_t i_pba_bar_addr,
    const uint64_t i_pba_bar_size)
{
    using namespace scomt::proc;

    FAPI_DBG(">> p10_pm_pba_bar_config...");

    fapi2::buffer<uint64_t> l_bar64;
    uint64_t                l_work_size;
    uint64_t                l_finalMask;

    FAPI_DBG("Called with channel 0x%llX, address 0x%016llX, "
             "size 0x%016llX", i_index, i_pba_bar_addr,
             i_pba_bar_size);

    // Check if PBA BAR address is within range,
    // High order bits checked to ensure a valid real address
    FAPI_ASSERT((BAR_ADDR_RANGECHECK_HIGH & i_pba_bar_addr) == 0x0ull,
                fapi2::PM_PBA_ADDR_OUT_OF_RANGE()
                .set_INDEX(i_index)
                .set_BAR_ADDR(i_pba_bar_addr)
                .set_BAR_SIZE(i_pba_bar_size)
                .set_EXP_BAR_ADDR_RANGECHECK_HIGH(BAR_ADDR_RANGECHECK_HIGH),
                "ERROR: Address out of Range : i_pba_bar_addr = 0x%016llX & "
                "Upper permissible limit = 0x%016llX", i_pba_bar_addr,
                BAR_ADDR_RANGECHECK_HIGH);

    // Low order bits checked for alignment
    FAPI_ASSERT((BAR_ADDR_RANGECHECK_LOW & i_pba_bar_addr) == 0x0ull,
                fapi2::PM_PBA_ADDR_ALIGNMENT_ERROR()
                .set_INDEX(i_index)
                .set_BAR_ADDR(i_pba_bar_addr)
                .set_BAR_SIZE(i_pba_bar_size)
                .set_EXP_BAR_ADDR_RANGECHECK_LOW(BAR_ADDR_RANGECHECK_LOW),
                "ERROR: Address must be on a 1MB boundary : i_pba_bar_addr="
                "0x%016llX & Alignment limit=0x%016llX", i_pba_bar_addr,
                BAR_ADDR_RANGECHECK_LOW);

    // The combination of both the BAR size and addr being zero is legal.
    // But, if the BAR size is 0 and the BAR addr is not zero return error.
    FAPI_ASSERT(!((i_pba_bar_size == 0) && (i_pba_bar_addr != 0)),
                fapi2::PM_PBA_BAR_SIZE_INVALID()
                .set_INDEX(i_index)
                .set_BAR_ADDR(i_pba_bar_addr)
                .set_BAR_SIZE(i_pba_bar_size),
                "ERROR: Bar size must be >=1MB for PBABAR 0x%llX, but "
                "i_pba_bar_size=0x%016llx", i_index, i_pba_bar_size);

    // Check that the image address passed is within the memory region that
    // is also passed.
    //
    // The PBA Mask indicates which bits from 23:43 (1MB granularity) are
    // enabled to be passed from the OCI addresses. Inverting this mask
    // indicates which address bits are going to come from the PBA BAR value.
    // The image address (the starting address) must match these post mask bits
    // to be resident in the range.
    //
    // Starting bit number: 64 bit Big Endian
    //                                          12223344
    //                                          60482604
    // region_inverted_mask = i_mem_mask ^ BAR_MASK_LIMIT;  // XOR
    // Set bits 8:22 as these are unconditional address bits
    // region_inverted_mask = region_inverted_mask | BAR_ADDR_UNMASKED;
    // computed_image_address = region_inverted_mask && image_address;
    //                          (Need to AND the address)

    // Write the BAR
    l_bar64.set(i_pba_bar_addr);

    // Note: P10 uses topology id translation registers instead of the CMD_SCOPE
    // field of the PBABAR.  This older setup is left in place in the event that
    // PBAOCFG[7](chsw_use_topology_id_scope) is set.

    l_bar64.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE,
                            TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE_LEN>(LOCAL_NODAL);

    FAPI_TRY(fapi2::putScom(i_target, PBA_BARs[i_index], l_bar64),
             "PBA_BAR Putscom failed for channel 0x%llX", i_index);

    // Compute and write the mask based on passed region size.

    // If the size is a power of 2,
    //     then set the mask to (size - 1).
    // else if the size is not a power of 2,
    //     then set the mask to the rounded up power of 2(value - 1).
    // else if the size is zero,
    //     then treat the size as equal to 1 and then do the round up check.

    if (i_pba_bar_size != 0)
    {
        l_work_size = PowerOf2Roundedup(i_pba_bar_size);
        FAPI_INF("i_pba_bar_size: 0x%016llX.  Final work_size: 0x%016llX",
                 i_pba_bar_size, l_work_size);
    }
    else
    {
        // If bar_size==0, treat as if ==1. Otherwize, range will max out to 2TB
        l_work_size = PowerOf2Roundedup(1ull);
        FAPI_INF("i_pba_bar_size: 0x%016llX but treated as if bar_size=1. "
                 "Final work_size: 0x%016llX", i_pba_bar_size, l_work_size);
    }

    l_finalMask = (l_work_size - 1) << 20; //shift to align mask 1MB

    FAPI_DBG("bar mask: 0x%016llX", l_finalMask);

    // Write the MASK
    l_bar64.flush<0>();
    l_bar64.set(l_finalMask);

    FAPI_TRY(fapi2::putScom(i_target, PBA_BARMSKs[i_index], l_bar64),
             "PBA_MASK Putscom failed for channel 0x%llX", i_index);

fapi_try_exit:
    FAPI_DBG("<< pm_pba_bar_config...");
    return fapi2::current_err;
}



// ------------------------------------------------------------------------------
// Function definitions
// ------------------------------------------------------------------------------


/// \param[in] i_target     Procesor Chip target
/// \param[in] i_mem_bar    Base address of the region where image is located
/// \param[in] i_mem_size   Size (in MB) of the region where image is located
///                         if not a power of two value, the value will be
///                         rounded up to the next power of 2 for setting the
///                         size.  The value of 0 is only legal if
///                         i_mem_bar is also 0;  else an error is indicated.
///
fapi2::ReturnCode
p10_pm_set_homer_bar(  const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                       const uint64_t i_mem_bar,
                       const uint64_t i_mem_size)
{

    fapi2::ReturnCode    l_rc;
    uint64_t region_masked_address;

    FAPI_INF("Entering p10_pm_set_homer_bar ...");

    // Check to make sure mem_bar is also 0 when mem_size is 0.
    FAPI_ASSERT(!((i_mem_size == 0) && (i_mem_bar != 0)),
                fapi2::PM_SET_HOMER_BAR_SIZE_INVALID().set_MEM_BAR(i_mem_bar)
                .set_MEM_SIZE(i_mem_size),
                "ERROR:HOMER Size is 0 but BAR is non-zero:0x%16llx", i_mem_bar);
    // check that bar address passed in 4MB aligned(eg bits 44:63 are zero)

    region_masked_address = i_mem_bar & BAR_MASK_4MB_ALIGN;
    FAPI_ASSERT((region_masked_address == 0),
                fapi2::PM_SET_HOMER_BAR_NOT_4MB_ALIGNED().set_MEM_BAR(i_mem_bar),
                "ERROR: i_mem_bar:0x%16llx is not 4MB aligned ", i_mem_bar);

    FAPI_DBG("Calling pba_bar_config with BAR %x Addr: 0x%16llX  Size: 0x%16llX",
             PBA_BAR0, i_mem_bar, i_mem_size);

    // Set the PBA BAR for the HOMER base
    FAPI_TRY(pm_pba_bar_config(i_target, PBA_BAR0, i_mem_bar, i_mem_size));

    // Set the QME BARS for the HOMER base
    FAPI_TRY(pm_qme_bar_config(i_target, i_mem_bar, i_mem_size));

fapi_try_exit:
    return fapi2::current_err;

}
