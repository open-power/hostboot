/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_scomoverride_chiplets.C $     */
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
/// @file p9_scomoverride_chiplets.C
///
/// @brief Apply sequenced scom overrides
///

//
// *HWP HW Owner : Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner : Thi N. Tran <thi@us.ibm.com>
// *HWP Team : Nest
// *HWP Level : 2
// *HWP Consumed by : HB
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "p9_scomoverride_chiplets.H"
#include "p9_perv_scom_addresses.H"
#include "p9_perv_scom_addresses_fld.H"

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode
p9_scomoverride_chiplets(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Entering ...");

    // HW354978 -- drop syncclock_muxsel for OBUS/XBUS/PCI chiplets
    fapi2::buffer<uint64_t> l_cplt_ctrl0_clear = 0;
    l_cplt_ctrl0_clear.setBit<PERV_1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC>();

    auto l_perv_functional_vector =
        i_target.getChildren<fapi2::TARGET_TYPE_PERV>(fapi2::TARGET_STATE_FUNCTIONAL);

    for (auto l_trgt_chplt : l_perv_functional_vector)
    {
        uint8_t l_attr_chip_unit_pos = 0; //actual value is read in FAPI_ATTR_GET below
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_trgt_chplt,
                               l_attr_chip_unit_pos));

        if (!((l_attr_chip_unit_pos == 0x09 || l_attr_chip_unit_pos == 0x0A
               || l_attr_chip_unit_pos == 0x0B
               || l_attr_chip_unit_pos == 0x0C/* ObusChiplet */) ||
              (l_attr_chip_unit_pos == 0x0D || l_attr_chip_unit_pos == 0x0E
               || l_attr_chip_unit_pos == 0x0F/* PcieChiplet */) ||
              (l_attr_chip_unit_pos == 0x06/* XbusChiplet */)))
        {
            continue;
        }

        FAPI_TRY(fapi2::putScom(l_trgt_chplt, PERV_CPLT_CTRL0_CLEAR, l_cplt_ctrl0_clear));
    }

    FAPI_DBG("Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}

