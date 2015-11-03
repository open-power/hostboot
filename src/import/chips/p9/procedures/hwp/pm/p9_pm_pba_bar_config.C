/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_pba_bar_config.C $           */
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
/// @file p9_pm_pba_bar_config.C
///
/// @brief Initialize PAB and PAB_MSK of PBA
///
// *HWP HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 2
// *HWP Consumed by: HS
///
/// @verbatim
///     The purpose of this procedure is to set the PBA BAR and PBA BAR Mask
///
///     INPUTS: Values for one set of pbabar
///
///     High-level procedure flow:
///         Parameter checking
///         Set PBA_BAR
///         Set PBA_BARMSK
///
///     Procedure Prereq:
///         System clocks are running
///
/// @endverbatim

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include <p9_pm_pba_bar_config.H>

// -----------------------------------------------------------------------------
// Constant & Structure definitions
// -----------------------------------------------------------------------------

enum BAR_ADDR_RANGE
{
    BAR_ADDR_RANGECHECK_HIGH = 0xFF00000000000000ull,
    BAR_ADDR_RANGECHECK_LOW  = 0x00000000000FFFFFull
};

const uint64_t PBA_BARs[4] =
{
    PU_PBABAR0,
    PU_PBABAR1,
    PU_PBABAR2,
    PU_PBABAR3
};

const uint64_t PBA_BARMSKs[4] =
{
    PU_PBABARMSK0,
    PU_PBABARMSK1,
    PU_PBABARMSK2,
    PU_PBABARMSK3
};

// -----------------------------------------------------------------------------
// Prototypes
// -----------------------------------------------------------------------------

///-----------------------------------------------------------------------------
/// Determine if a number is a power of two or not
///-----------------------------------------------------------------------------
inline bool isPowerOfTwo (uint64_t value);

///-----------------------------------------------------------------------------
/// Round up to next higher power of 2 (return value if it's already a power of
/// 2).
///-----------------------------------------------------------------------------
inline uint64_t PowerOf2Roundedup (uint64_t value);


// -----------------------------------------------------------------------------
// Function definitions
// -----------------------------------------------------------------------------
fapi2::ReturnCode p9_pm_pba_bar_config (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint32_t i_index,
    const uint64_t i_pba_bar_addr,
    const uint64_t i_pba_bar_size,
    const p9pba::CMD_SCOPE i_pba_cmd_scope,
    const uint16_t i_vectorTarget)
{
    FAPI_IMP("Entering P9_PM_PBA_BAR_CONFIG...");

    fapi2::buffer<uint64_t> l_bar64;
    uint64_t                l_work_size;
    uint64_t                l_finalMask;

    FAPI_DBG("Called with channel 0x%llX, scope 0x%llX, address 0x%016llX, "
             "size 0x%016llX", i_index, i_pba_cmd_scope, i_pba_bar_addr,
             i_pba_bar_size);

    // Check if PBA BAR address is within range,
    // High order bits checked to ensure a valid real address
    FAPI_ASSERT((BAR_ADDR_RANGECHECK_HIGH & i_pba_bar_addr) == 0x0ull,
                fapi2::P9_PBA_ADDR_OUT_OF_RANGE().set_INDEX(i_index)
                .set_BAR_ADDR(i_pba_bar_addr).set_BAR_SIZE(i_pba_bar_size)
                .set_CMD_SCOPE(i_pba_cmd_scope)
                .set_EXP_BAR_ADDR_RANGECHECK_HIGH(BAR_ADDR_RANGECHECK_HIGH),
                "ERROR: Address out of Range : i_pba_bar_addr = 0x%016llX & "
                "Upper permissible limit = 0x%016llX", i_pba_bar_addr,
                BAR_ADDR_RANGECHECK_HIGH);

    // Low order bits checked for alignment
    FAPI_ASSERT((BAR_ADDR_RANGECHECK_LOW & i_pba_bar_addr) == 0x0ull,
                fapi2::P9_PBA_ADDR_ALIGNMENT_ERROR().set_INDEX(i_index)
                .set_BAR_ADDR(i_pba_bar_addr).set_BAR_SIZE(i_pba_bar_size)
                .set_CMD_SCOPE(i_pba_cmd_scope)
                .set_EXP_BAR_ADDR_RANGECHECK_LOW(BAR_ADDR_RANGECHECK_LOW),
                "ERROR: Address must be on a 1MB boundary : i_pba_bar_addr="
                "0x%016llX & Alignment limit=0x%016llX", i_pba_bar_addr,
                BAR_ADDR_RANGECHECK_LOW);

    // The combination of both the BAR size and addr being zero is legal.
    // But, if the BAR size is 0 and the BAR addr is not zero return error.

    FAPI_ASSERT(!((i_pba_bar_size == 0) && (i_pba_bar_addr != 0)),
                fapi2::P9_PBA_BAR_SIZE_INVALID().set_INDEX(i_index)
                .set_BAR_ADDR(i_pba_bar_addr).set_BAR_SIZE(i_pba_bar_size)
                .set_CMD_SCOPE(i_pba_cmd_scope),
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
    l_bar64.insertFromRight<0, 3>(i_pba_cmd_scope);

    if (i_pba_cmd_scope == p9pba::VECTORED_GROUP)
    {
        FAPI_DBG("Setting the initial vectored group target for scope 0x%X",
                 i_pba_cmd_scope);
        l_bar64.insertFromRight<48, 16>(i_vectorTarget);
    }

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

    l_finalMask = l_work_size - 1;

    FAPI_DBG("bar mask: 0x%016llX", l_finalMask);

    // Write the MASK
    l_bar64.flush<0>();
    l_bar64.set(l_finalMask);

    FAPI_TRY(fapi2::putScom(i_target, PBA_BARMSKs[i_index], l_bar64),
             "PBA_MASK Putscom failed for channel 0x%llX", i_index);

    FAPI_IMP("Exiting P9_PM_PBA_BAR_CONFIG...");

fapi_try_exit:
    return fapi2::current_err;
}

inline bool isPowerOfTwo(uint64_t value)
{
    // if value ANDed with the value-1 is 0, then value is a power of 2.
    // if value is 0, this is considered not a power of 2 and will return false.

    return !(value & (value - 1));
}

inline uint64_t PowerOf2Roundedup (uint64_t value)
{
    if (value < 0)
    {
        return 0;
    }

    --value;
    value |= value >> 1;
    value |= value >> 2;
    value |= value >> 4;
    value |= value >> 8;
    value |= value >> 16;
    return value + 1;
}
