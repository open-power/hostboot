/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_phb_hv_access.C $  */
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
//------------------------------------------------------------------------------
//
/// @file p9_phb_hv_access.C
/// @brief Perform read/write to PHB HV register space. (FAPI)
///
// *HWP HWP Owner: Ricardo Mata Jr. ricmata@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 3
// *HWP Consumed by: HB
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_phb_hv_access.H>
#include <p9_phb_hv_utils.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode p9_phb_hv_access(
    const fapi2::Target<fapi2::TARGET_TYPE_PHB>& i_target,
    const uint32_t i_address,
    bool const i_rnw,
    bool const i_size,
    uint64_t& io_data)
{

    uint8_t l_phb_id = 0;

    //Get the PHB id
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_phb_id));

    FAPI_DBG("PHB%i: Start PHB HV read/write access", l_phb_id);

    //Check ETU state
    FAPI_TRY(p9_phb_hv_check_etu_state(i_target),
             "Error from p9_phb_hv_check_etu_state");

    //Check arguments
    FAPI_TRY(p9_phb_hv_check_args(i_target, i_address, i_size),
             "Error from p9_phb_hv_check_args");

    //Clear contents of PHB HV Indirect Address Register
    FAPI_TRY(p9_phb_hv_clear(i_target),
             "Error from p9_phb_hv_clear");

    //setup the PHB HV registers for the read/write
    FAPI_TRY(p9_phb_hv_setup(i_target, i_address, i_size),
             "Error from p9_phb_hv_setup");

    if (i_rnw)
    {
        //Setup PHB HV Indirect for read access
        FAPI_TRY(p9_phb_hv_read(i_target, i_address, i_size, io_data),
                 "Error from p9_phb_hv_read");
    }
    else
    {
        //Setup PHB HV Indirect for write access
        FAPI_TRY(p9_phb_hv_write(i_target, i_address, i_size, io_data),
                 "Error from p9_phb_hv_write");
    }

    //Clear contents of PHB HV Indirect Address Register
    FAPI_TRY(p9_phb_hv_clear(i_target),
             "Error from p9_phb_hv_clear");


fapi_try_exit:
    FAPI_DBG("PHB%i: End PHB HV read/write Procedure", l_phb_id);
    return fapi2::current_err;

}
