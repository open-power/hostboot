/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_perst_phb.C $      */
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
///
/// @file p9_perst_phb.C
/// @brief Procedure to assert/deassert PERST on PHB (FAPI2)
///
// *HWP HWP Owner: Ricardo Mata Jr. ricmata@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: HB

//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <p9_perst_phb.H>
#include <p9_phb_hv_access.H>
#include "p9_misc_scom_addresses.H"
#include "p9_misc_scom_addresses_fld.H"

extern "C"
{
    //---------------------------//
    // Function definitions      //
    //---------------------------//
    //------------------------------------------------------------------------------
    // name: p9_perst_phb
    //------------------------------------------------------------------------------
    // purpose:
    // Procedure to asser/deassert PERST signal from PHB.
    //
    // parameters:
    // 'i_target' is reference to phb target
    // 'i_perst_action' is reference to the ACTIVATE or DEACTIVATE PERST.
    //
    // returns:
    // FAPI_RC_SUCCESS (success, forced PERST assert/deassert from PHBs)
    // (Note: refer to file eclipz/chips/p9/working/procedures/xml/error_info/p9_perst_phb_errors.xml)
    // getscom/putscom fapi errors
    // fapi error assigned from eCMD function failure
    //
    //------------------------------------------------------------------------------
    fapi2::ReturnCode p9_perst_phb(const fapi2::Target<fapi2::TARGET_TYPE_PHB>& i_target, const PERST_ACTION i_perst_action)
    {
        fapi2::buffer<uint64_t> l_buf = 0;
        uint8_t l_phb_id = 0;


        //Get the PHB id
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_phb_id));

        FAPI_DBG("PHB%i: Start PERST PHB Procedure", l_phb_id);

        //Make sure that the perst action input is valid
        FAPI_ASSERT(!((i_perst_action != ACTIVATE_PERST) && (i_perst_action != DEACTIVATE_PERST)),
                    fapi2::P9_PHB_PERST_ACTION_INVALID_ARGS_ERR()
                    .set_TARGET(i_target)
                    .set_PERSTACTION(i_perst_action),
                    "PHB%i: i_perst_action is not valid", l_phb_id);


        //Read state of ETU Reset Register
        FAPI_TRY(fapi2::getScom(i_target, PHB_PHBRESET_REG, l_buf));
        FAPI_DBG("  ETU Reset Register %016lX", l_buf());

        if(l_buf.getBit(PHB_PHBRESET_REG_PE_ETU_RESET))
        {
            //Take ETU out of reset to acess PHB PCI - Core Reset Register
            FAPI_DBG("  ETU is in reset. Taking it out of reset");
            l_buf.clearBit<PHB_PHBRESET_REG_PE_ETU_RESET>();
            FAPI_DBG("  ETU Reset Register %016lX", l_buf());
            FAPI_TRY(fapi2::putScom(i_target, PHB_PHBRESET_REG, l_buf));
        }


        //Perform PERST action requested
        if(i_perst_action == DEACTIVATE_PERST) //Deactive PERST
        {

            //Deassert the PERST signal from the PHB
            FAPI_DBG("  Deassert PERST signal.");

            //RMW PHB Core Reset Register
            FAPI_TRY(p9_phb_hv_access(i_target, PHB_CORE_RESET_REGISTER, true, false, l_buf));
            l_buf.setBit<PHB_HP_PERST_BIT>();
            FAPI_DBG("  Value to be written to %016lX -  %016lX", PHB_CORE_RESET_REGISTER, l_buf());
            FAPI_TRY(p9_phb_hv_access(i_target, PHB_CORE_RESET_REGISTER, false, false, l_buf));
        }
        else //Activate PERST
        {

            //Assert the PERST signal from the PHB
            FAPI_DBG("  Assert PERST signal.");

            //RMW PHB Core Reset Register
            FAPI_TRY(p9_phb_hv_access(i_target, PHB_CORE_RESET_REGISTER, true, false, l_buf));
            l_buf.clearBit<PHB_HP_PERST_BIT>();
            FAPI_DBG("  Value to be written to %016lX - %016lX", PHB_CORE_RESET_REGISTER, l_buf());
            FAPI_TRY(p9_phb_hv_access(i_target, PHB_CORE_RESET_REGISTER, false, false, l_buf));

            //Put ETU into reset
            FAPI_DBG("  Put ETU into reset.");
            l_buf = 0;
            l_buf.setBit<PHB_PHBRESET_REG_PE_ETU_RESET>();
            FAPI_DBG("  ETU Reset Register %016lX", l_buf());
            FAPI_TRY(fapi2::putScom(i_target, PHB_PHBRESET_REG, l_buf));
        }

    fapi_try_exit:
        FAPI_DBG("PHB%i: End PERST PHB Procedure", l_phb_id);
        return fapi2::current_err;
    }

} // extern "C
