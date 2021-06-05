/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_determine_eco_mode.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
/// @file p10_determine_eco_mode.C
///
/// @brief Query core partial good information to determine if it supports
///        instruction execution or should be used as an L3 cache tank only,
///        set ATTR_ECO_MODE
///
/// *HWP HW Maintainer: Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Maintainer: Dan Crowell <dcrowell@us.ibm.com>
/// *HWP Consumed by: HB,SBE,HWSV
///

// EKB-Mirror-To: hw/ppe, hostboot, hwsv

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_determine_eco_mode.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// PG bit definition reference:
//   https://ibm.box.com/s/tmt5lvsswmvp9di8zxcge8i0eljxj0jb
// constants reflect bit associated with c0 slice in EQ (start of contiguous
// 4-bit fields for L2/L3/MMA/L3 ECO data, respectively), with data packed
// into low-order 24 bits of the 32-bit ATTR_PG data
const auto l_ecl2_pg_start_bit = 13;
const auto l_l3_pg_start_bit = 17;
const auto l_mma_pg_start_bit = 23;
const auto l_l3_eco_pg_start_bit = 28;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

/// Main function, see description in header
fapi2::ReturnCode
p10_determine_eco_mode(const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target)
{
    FAPI_DBG("Entering ...");

    // grab perv target associated with parent EQ
    const auto l_eq = i_target.getParent<fapi2::TARGET_TYPE_EQ>();
    const auto l_perv = l_eq.getParent<fapi2::TARGET_TYPE_PERV>();

    fapi2::ATTR_CHIP_UNIT_POS_Type l_core_num = 0;
    fapi2::ATTR_ECO_MODE_Type l_eco_mode = fapi2::ENUM_ATTR_ECO_MODE_DISABLED;
    fapi2::ATTR_PG_Type l_eq_pg;
    fapi2::buffer<uint32_t> l_eq_pg_buf;

    // platforms should continue to treat all CORE targets are functional
    // (whether associated with a non-ECO or ECO specific slice) -- add
    // a check to confirm
    FAPI_ASSERT(i_target.isFunctional() &&
                l_eq.isFunctional() &&
                l_perv.isFunctional(),
                fapi2::P10_DETERMINE_ECO_MODE_TARGET_STATE_ERR()
                .set_CORE(i_target)
                .set_CORE_FUNCTIONAL(i_target.isFunctional())
                .set_ASSOCIATED_EQ(l_eq)
                .set_ASSOCIATED_EQ_FUNCTIONAL(l_eq.isFunctional())
                .set_ASSOCIATED_PERV(l_eq)
                .set_ASSOCIATED_PERV_FUNCTIONAL(l_perv.isFunctional()),
                "Input core target or related EQ/PERV target is not functional!");

    // retrieve chip relative core unit position (0..31)
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_core_num),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

    // retreive partial good information for EQ containing this core, via
    // the associated pervasive target
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PG, l_perv, l_eq_pg),
             "Error from FAPI_ATTR_GET (ATTR_PG)");

    // confirm expected functionality from partial good record
    // for a functional core, its associated ECL2/L3/MMA PG bits should all be 0
    l_eq_pg_buf = l_eq_pg;
    FAPI_ASSERT(!l_eq_pg_buf.getBit(l_ecl2_pg_start_bit + (l_core_num % 4)) &&
                !l_eq_pg_buf.getBit(l_l3_pg_start_bit   + (l_core_num % 4)) &&
                !l_eq_pg_buf.getBit(l_mma_pg_start_bit  + (l_core_num % 4)),
                fapi2::P10_DETERMINE_ECO_MODE_PG_ERR()
                .set_CORE(i_target)
                .set_CORE_FUNCTIONAL(i_target.isFunctional())
                .set_ECL2_PG_BIT(l_eq_pg_buf.getBit(l_ecl2_pg_start_bit + (l_core_num % 4)))
                .set_L3_PG_BIT(l_eq_pg_buf.getBit(l_l3_pg_start_bit     + (l_core_num % 4)))
                .set_MMA_PG_BIT(l_eq_pg_buf.getBit(l_mma_pg_start_bit   + (l_core_num % 4)))
                .set_EQ_PG(l_eq_pg),
                "PG keyword attribute data does not indicate core is functional!");

    // ECO mode is enabled if L3 ECO PG bit is 0
    if (!l_eq_pg_buf.getBit(l_l3_eco_pg_start_bit + (l_core_num % 4)))
    {
        l_eco_mode = fapi2::ENUM_ATTR_ECO_MODE_ENABLED;
    }

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_ECO_MODE, i_target, l_eco_mode),
             "Error from FAPI_ATTR_SET (ATTR_ECO_MODE)");

fapi_try_exit:
    FAPI_DBG("Exiting ...");
    return fapi2::current_err;
}
