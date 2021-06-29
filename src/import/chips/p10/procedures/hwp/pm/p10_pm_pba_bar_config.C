/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_pba_bar_config.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
/// @file p10_pm_pba_bar_config.C
///
/// @brief Initialize PAB and PAB_MSK of PBA
///
// *HWP HWP Owner: Greg Still <stillgs @us.ibm.com>
// *HWP FW Owner:  Prem Shanker Jha <premjha2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 3
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
#include <p10_pm_pba_bar_config.H>
#include <p10_scom_proc.H>
#include <p10_scom_eq.H>
#include <multicast_group_defs.H>
#include <math.h>

// -----------------------------------------------------------------------------
// Constant & Structure definitions
// -----------------------------------------------------------------------------

using namespace scomt::proc;

enum BAR_ADDR_RANGE
{
    BAR_ADDR_RANGECHECK_HIGH = 0xFF00000000000000ull,
    BAR_ADDR_RANGECHECK_LOW  = 0x00000000000FFFFFull
};

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

// -----------------------------------------------------------------------------
// Prototypes
// -----------------------------------------------------------------------------

// See doxygen
inline bool isPowerOfTwo(uint64_t i_value)
{
    // if i_value ANDed with the i_value-1 is 0, then i_value is a power of 2.
    // if i_value is 0, this is considered not a power of 2 and will return false.
    return !(i_value & (i_value - 1));
}

// See doxygen
uint64_t PowerOf2Roundedup (uint64_t i_value)
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


// -----------------------------------------------------------------------------
// Function definitions
// -----------------------------------------------------------------------------
// See doxygen in header file
fapi2::ReturnCode p10_pm_pba_bar_config (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint32_t i_index,
    const uint64_t i_pba_bar_addr,
    const uint64_t i_pba_bar_size,
    const p10pba::CMD_SCOPE i_pba_cmd_scope,
    const uint16_t i_vectorTarget)
{
    FAPI_DBG(">> p10_pm_pba_bar_config...");

    fapi2::buffer<uint64_t> l_bar64;
    uint64_t                l_work_size;
    uint64_t                l_finalMask;

    FAPI_DBG("Called with channel 0x%llX, scope 0x%llX, address 0x%016llX, "
             "size 0x%016llX", i_index, i_pba_cmd_scope, i_pba_bar_addr,
             i_pba_bar_size);

    // Check if PBA BAR address is within range,
    // High order bits checked to ensure a valid real address
    FAPI_ASSERT((BAR_ADDR_RANGECHECK_HIGH & i_pba_bar_addr) == 0x0ull,
                fapi2::PM_PBA_ADDR_OUT_OF_RANGE()
                .set_INDEX(i_index)
                .set_BAR_ADDR(i_pba_bar_addr)
                .set_BAR_SIZE(i_pba_bar_size)
                .set_CMD_SCOPE(i_pba_cmd_scope)
                .set_EXP_BAR_ADDR_RANGECHECK_HIGH(BAR_ADDR_RANGECHECK_HIGH)
                .set_CURPROC(i_target),
                "ERROR: Address out of Range : i_pba_bar_addr = 0x%016llX & "
                "Upper permissible limit = 0x%016llX", i_pba_bar_addr,
                BAR_ADDR_RANGECHECK_HIGH);

    // Low order bits checked for alignment
    FAPI_ASSERT((BAR_ADDR_RANGECHECK_LOW & i_pba_bar_addr) == 0x0ull,
                fapi2::PM_PBA_ADDR_ALIGNMENT_ERROR()
                .set_INDEX(i_index)
                .set_BAR_ADDR(i_pba_bar_addr)
                .set_BAR_SIZE(i_pba_bar_size)
                .set_CMD_SCOPE(i_pba_cmd_scope)
                .set_EXP_BAR_ADDR_RANGECHECK_LOW(BAR_ADDR_RANGECHECK_LOW)
                .set_CURPROC(i_target),
                "ERROR: Address must be on a 1MB boundary : i_pba_bar_addr="
                "0x%016llX & Alignment limit=0x%016llX", i_pba_bar_addr,
                BAR_ADDR_RANGECHECK_LOW);

    // The combination of both the BAR size and addr being zero is legal.
    // But, if the BAR size is 0 and the BAR addr is not zero return error.
    FAPI_ASSERT(!((i_pba_bar_size == 0) && (i_pba_bar_addr != 0)),
                fapi2::PM_PBA_BAR_SIZE_INVALID()
                .set_INDEX(i_index)
                .set_BAR_ADDR(i_pba_bar_addr)
                .set_BAR_SIZE(i_pba_bar_size)
                .set_CURPROC(i_target),
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
                            TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE_LEN>(i_pba_cmd_scope);

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
    FAPI_DBG("<< p10_pm_pba_bar_config...");
    return fapi2::current_err;
}
