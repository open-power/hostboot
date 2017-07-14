/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_phb_hv_utils.C $   */
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

///---------------------------------------------------------------------------
///
/// @file p9_phb_hv_utils.C
/// @brief Functions to access PHB HV register space  (FAPI2)
///
/// *HWP HWP Owner: Ricardo Mata Jr. ricmata@us.ibm.com
/// *HWP FW Owner: Thi Tran thi@us.ibm.com
/// *HWP Team: Nest
/// *HWP Level: 3
/// *HWP Consumed by: FSP
///
///---------------------------------------------------------------------------

///---------------------------------------------------------------------------
/// Includes
///---------------------------------------------------------------------------
#include <p9_phb_hv_utils.H>
#include <p9_misc_scom_addresses.H>
#include <p9_misc_scom_addresses_fld.H>

//---------------------------------------------------------------------------------
// NOTE: description in header
//---------------------------------------------------------------------------------
fapi2::ReturnCode p9_phb_hv_check_etu_state(
    const fapi2::Target<fapi2::TARGET_TYPE_PHB>& i_target)
{
    FAPI_DBG("  Start p9_phb_hv_check_etu_state");
    fapi2::buffer<uint64_t> l_buf;

    //Read state of ETU Reset Register
    FAPI_TRY(fapi2::getScom(i_target, PHB_PHBRESET_REG, l_buf),
             "Error from getScom (0x%.16llX)", PHB_PHBRESET_REG);
    FAPI_DBG("  ETU Reset Register %#lx", l_buf());
    FAPI_ASSERT(!l_buf.getBit<PHB_PHBRESET_REG_PE_ETU_RESET>(),
                fapi2::P9_PHB_HV_UTILS_ETU_RESET_ACTIVE()
                .set_TARGET(i_target)
                .set_ADDRESS(PHB_PHBRESET_REG)
                .set_DATA(l_buf),
                "  ETU is in reset!");

fapi_try_exit:
    FAPI_DBG("  Exiting p9_phb_hv_check_etu_state");
    return fapi2::current_err;
}

//---------------------------------------------------------------------------------
// NOTE: description in header
//---------------------------------------------------------------------------------
fapi2::ReturnCode p9_phb_hv_check_args(
    const fapi2::Target<fapi2::TARGET_TYPE_PHB>& i_target,
    const uint32_t i_address,
    bool const i_size)
{
    FAPI_DBG("  Start p9_phb_hv_check_args");
    uint32_t l_actualTransSize;

    if (i_size)
    {
        l_actualTransSize = 4;
    }
    else
    {
        l_actualTransSize = 8;
    }

    FAPI_DBG("  Addr 0x%04llX, Size 0x%d", i_address, l_actualTransSize);

    //Check the address alignment
    FAPI_ASSERT(!(i_address & (l_actualTransSize - 1)),
                fapi2::P9_PHB_HV_UTILS_INVALID_ARGS()
                .set_TARGET(i_target)
                .set_ADDRESS(i_address)
                .set_SIZE(l_actualTransSize),
                "Input address (0x%04llX) is not aligned", i_address);

    //Make sure the address is within the PHB HV bounds
    FAPI_ASSERT(i_address <= PHB_HV_MAX_ADDR,
                fapi2::P9_PHB_HV_UTILS_INVALID_ARGS()
                .set_TARGET(i_target)
                .set_ADDRESS(i_address)
                .set_SIZE(l_actualTransSize),
                "Input addr (0x%04llX) exceeds supported PHB HV address of "
                "0x%04llX", i_address, PHB_HV_MAX_ADDR);

fapi_try_exit:
    FAPI_DBG("  Exiting p9_phb_hv_check_args");
    return fapi2::current_err;
}

//---------------------------------------------------------------------------------
// NOTE: description in header
//---------------------------------------------------------------------------------
fapi2::ReturnCode p9_phb_hv_setup(const fapi2::Target<fapi2::TARGET_TYPE_PHB>& i_target, const uint32_t i_address,
                                  bool const i_size)
{
    FAPI_DBG("  Start p9_phb_hv_setup");
    fapi2::buffer<uint64_t> phb_hv_addr_reg_data(i_address);

    //Set Valid bit to allow read/write access
    phb_hv_addr_reg_data.setBit<PHB_PHB4_SCOM_HVIAR_HV_REQ_ADDR_VLD>();

    //Set Size for 8B or 4B ops
    if (i_size)
    {
        phb_hv_addr_reg_data.setBit<PHB_PHB4_SCOM_HVIAR_HV_REQ_4B>();
    }

    //This sets everything that should be set for the PHB HV Indirect Address Register
    FAPI_DBG("  PHB HV Indirect Address Register 0x%016llX", phb_hv_addr_reg_data);
    FAPI_TRY(fapi2::putScom(i_target, PHB_PHB4_SCOM_HVIAR, phb_hv_addr_reg_data),
             "Error from putScom (0x%.16llX)", PHB_PHB4_SCOM_HVIAR);

fapi_try_exit:
    FAPI_DBG("  Exiting p9_phb_hv_setup");
    return fapi2::current_err;
}

//---------------------------------------------------------------------------------
// NOTE: description in header
//---------------------------------------------------------------------------------
fapi2::ReturnCode p9_phb_hv_write(
    const fapi2::Target<fapi2::TARGET_TYPE_PHB>& i_target,
    const uint32_t i_address,
    bool const i_size, uint64_t& i_write_data)
{
    FAPI_DBG("  Start p9_phb_hv_write");
    fapi2::buffer<uint64_t> phb_hv_data_reg_data(i_write_data);

    //write the data into the PHB HV Indirect Data Register
    FAPI_DBG("  Write Data = 0x%016llX", phb_hv_data_reg_data);
    FAPI_TRY(fapi2::putScom(i_target, PHB_PHB4_SCOM_HVIDR, phb_hv_data_reg_data),
             "Error from putScom (0x%.16llX)", PHB_PHB4_SCOM_HVIDR);

fapi_try_exit:
    FAPI_DBG("  Exiting p9_phb_hv_write");
    return fapi2::current_err;
}

//---------------------------------------------------------------------------------
// NOTE: description in header
//---------------------------------------------------------------------------------
fapi2::ReturnCode p9_phb_hv_read(
    const fapi2::Target<fapi2::TARGET_TYPE_PHB>& i_target,
    const uint32_t i_address,
    bool const i_size,
    uint64_t& o_read_data)
{
    FAPI_DBG("  Start p9_phb_hv_read");
    fapi2::buffer<uint64_t> phb_hv_data_reg_data;

    //Read data from PHB HV Indirect Data Register
    FAPI_TRY(fapi2::getScom(i_target, PHB_PHB4_SCOM_HVIDR, phb_hv_data_reg_data),
             "Error from getScom (0x%.16llX)", PHB_PHB4_SCOM_HVIDR);
    o_read_data = phb_hv_data_reg_data;
    FAPI_DBG("  Read Data = 0x%016llX", o_read_data);

fapi_try_exit:
    FAPI_DBG("  Exiting p9_phb_hv_read");
    return fapi2::current_err;
}

//---------------------------------------------------------------------------------
// NOTE: description in header
//---------------------------------------------------------------------------------
fapi2::ReturnCode p9_phb_hv_clear(const fapi2::Target<fapi2::TARGET_TYPE_PHB>& i_target)
{
    FAPI_DBG("  Start p9_phb_hv_clear");
    fapi2::buffer<uint64_t> phb_hv_addr_reg_data = 0;

    //Clear the contents of the PHB HV Indirect Address Register
    FAPI_DBG("  PHB HV Indirect Address Register 0x%016llX", phb_hv_addr_reg_data);
    FAPI_TRY(fapi2::putScom(i_target, PHB_PHB4_SCOM_HVIAR, phb_hv_addr_reg_data),
             "Error from putScom (0x%.16llX)", PHB_PHB4_SCOM_HVIAR);

fapi_try_exit:
    FAPI_DBG("  Exiting p9_phb_hv_clear");
    return fapi2::current_err;
}
