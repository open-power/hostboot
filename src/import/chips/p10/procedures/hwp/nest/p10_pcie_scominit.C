/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_pcie_scominit.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file  p10_pcie_scominit.C
/// @brief Perform PCIE SCOM initialization (FAPI2)
///
/// @author Joe McGill <jmcgill@us.ibm.com>
///

///
/// *HWP HW Maintainer: Ricardo Mata Jr. (ricmata@us.ibm.com)
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_pcie_scominit.H>
#include <p10_pcie_scom.H>
#include <p10_scom_pec_6.H>
#include <p10_scom_phb_e.H>


///-----------------------------------------------------------------------------
/// Function definitions
///-----------------------------------------------------------------------------

fapi2::ReturnCode
p10_pcie_scominit(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Start");
    using namespace scomt;
    using namespace scomt::pec;
    using namespace scomt::phb;

    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_data;
    auto l_pec_targets = i_target.getChildren<fapi2::TARGET_TYPE_PEC>();
    auto l_phb_targets = i_target.getChildren<fapi2::TARGET_TYPE_PHB>();

    //Perform the PCIe Phase 1 Inits 1-8
    //Sets the lane config based on MRW attributes
    //Sets the swap bits based on MRW attributes
    //Sets valid PHBs, remove from reset
    //Performs any needed overrides (should flush correctly) ~ this is where initfile may be used
    //Set the IOP program complete bit
    //This is where the dSMP versus PCIE is selected in the PHY Link Layer

    //Set io valids
    for (auto l_pec_target : l_pec_targets)
    {
        l_data = 0;
        FAPI_TRY(PREP_CPLT_CONF1_WO_OR(l_pec_target));
        SET_CPLT_CONF1_IOVALID_DC_8H(l_data);
        SET_CPLT_CONF1_IOVALID_DC_9H(l_data);
        SET_CPLT_CONF1_IOVALID_DC_10H(l_data);
        FAPI_TRY(PUT_CPLT_CONF1_WO_OR(l_pec_target, l_data));
    }

    //Reset PHBs
    for (auto l_phb_target : l_phb_targets)
    {
        l_data = 0;
        FAPI_TRY(PREP_REGS_PHBRESET_REG(l_phb_target));
        SET_REGS_PHBRESET_REG_PE_ETU_RESET(l_data);
        FAPI_TRY(PUT_REGS_PHBRESET_REG(l_phb_target, l_data));
    }

    //Run initfile
    FAPI_EXEC_HWP(l_rc, p10_pcie_scom, i_target);

    if (l_rc)
    {
        FAPI_ERR("Error from p10.mi.omi.scom.initfile");
        fapi2::current_err = l_rc;
        goto fapi_try_exit;
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
