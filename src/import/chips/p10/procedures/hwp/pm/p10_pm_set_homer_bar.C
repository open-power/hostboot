/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_set_homer_bar.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
#include "p10_pm_pba_bar_config.H"
#include "p10_pm.H"
#include <p10_scom_proc.H>
#include <p10_scom_eq.H>
#include <multicast_group_defs.H>
#include <math.h>

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

//extern uint64_t PowerOf2Roundedup (uint64_t value);

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

    auto eqList =
        i_target.getChildren<fapi2::TARGET_TYPE_EQ>(fapi2::TARGET_STATE_FUNCTIONAL);

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

    l_bar64.flush<0>();
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

    for( auto eq : eqList )
    {
        FAPI_TRY(fapi2::putScom(eq, QME_BCEBAR0, l_bar64));
    }

fapi_try_exit:
    FAPI_DBG("<< p10_pm_qme_bar_config...");
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
    FAPI_EXEC_HWP(l_rc, p10_pm_pba_bar_config, i_target,
                  PBA_BAR0,
                  i_mem_bar,
                  i_mem_size,
                  p10pba::LOCAL_NODAL, 0);

    // Set the QME BARS for the HOMER base
    FAPI_TRY(pm_qme_bar_config(i_target, i_mem_bar, i_mem_size));


fapi_try_exit:
    return fapi2::current_err;

}
