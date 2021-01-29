/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_pau_scominit.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
/// @file p10_pau_scominit.C
/// @brief Apply SCOM overrides for the PAU unit
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_pau_scominit.H>
#include <p10_pau_scom.H>
#include <p10_fbc_utils.H>

#include <p10_scom_iohs_e.H>
#include <p10_scom_pauc_9.H>
#include <p10_scom_pau_0.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
const uint64_t ENUM_DLP_CONFIG_DL_SELECT_DLO = 0b10;

struct transport_ob_mux
{
    const uint64_t transport_01_ob_mux0;
    const uint64_t transport_01_ob_mux1;
    const uint64_t transport_01_ob_mux2;
    const uint64_t transport_23_ob_mux0;
    const uint64_t transport_23_ob_mux1;
    const uint64_t transport_23_ob_mux2;
};

transport_ob_mux direct = { 0b1, 0b0, 0b0, 0b0, 0b0, 0b1 };
transport_ob_mux sister = { 0b0, 0b0, 0b1, 0b1, 0b0, 0b0 };

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

///
/// @brief Configure TL for OpenCAPI links
///
/// @param[in] i_target         Reference to processor chip target
/// @return fapi2::ReturnCode   FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_pau_scominit_tl(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    using namespace scomt;
    using namespace scomt::pauc;
    using namespace scomt::pau;

    bool l_pau_good[P10_FBC_UTILS_MAX_LINKS] = { false };
    bool l_ocapi_en[P10_FBC_UTILS_MAX_LINKS] = { false };

    // populate array of pau partial goods
    for(auto l_pau_target : i_target.getChildren<fapi2::TARGET_TYPE_PAU>())
    {
        fapi2::ATTR_CHIP_UNIT_POS_Type l_pau_id;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_pau_target, l_pau_id),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

        l_pau_good[l_pau_id] = true;
    }

    // populate array of opt links configured for ocapi
    for(auto l_iohs_target : i_target.getChildren<fapi2::TARGET_TYPE_IOHS>())
    {
        fapi2::ATTR_IOHS_CONFIG_MODE_Type l_config_mode;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_CONFIG_MODE, l_iohs_target, l_config_mode),
                 "Error from FAPI_ATTR_GET (ATTR_IOHS_CONFIG_MODE)");

        if(l_config_mode == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_OCAPI)
        {
            fapi2::ATTR_CHIP_UNIT_POS_Type l_iohs_id;
            fapi2::ATTR_IOHS_LINK_TRAIN_Type l_link_train = fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_BOTH;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_iohs_target, l_iohs_id),
                     "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

            l_ocapi_en[l_iohs_id] = true;

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_IOHS_LINK_TRAIN, l_iohs_target, l_link_train),
                     "Error from FAPI_ATTR_SET (ATTR_IOHS_LINK_TRAIN)");
        }
    }

    for(auto l_iohs_target : i_target.getChildren<fapi2::TARGET_TYPE_IOHS>())
    {
        fapi2::ATTR_CHIP_UNIT_POS_Type l_iohs_id;
        fapi2::ATTR_IOHS_LINK_TRAIN_Type l_link_train;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_iohs_target, l_iohs_id),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_LINK_TRAIN, l_iohs_target, l_link_train),
                 "Error from FAPI_ATTR_GET (ATTR_IOHS_LINK_TRAIN)");

        // tlx represents this opt and direct pau
        // tly represents the sister opt and alternative pau
        bool l_tlx_oc = l_ocapi_en[l_iohs_id];
        bool l_tlx_pg = l_pau_good[l_iohs_id];
        bool l_tly_oc = (l_iohs_id % 2) ? l_ocapi_en[l_iohs_id - 1] : l_ocapi_en[l_iohs_id + 1];
        bool l_tly_pg = (l_iohs_id % 2) ? l_pau_good[l_iohs_id - 1] : l_pau_good[l_iohs_id + 1];

        // note that opt0/1 are swizzled
        bool l_evn_iohs = (((l_iohs_id % 2 == 0) && (l_iohs_id != 0)) || (l_iohs_id == 1)) ? true : false;
        bool l_odd_iohs = (((l_iohs_id % 2 == 1) && (l_iohs_id != 1)) || (l_iohs_id == 0)) ? true : false;

        // sublink enables for opt
        bool l_evn_sublink_en = (l_link_train == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_BOTH)
                                || (l_link_train == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_EVEN_ONLY);
        bool l_odd_sublink_en = (l_link_train == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_BOTH)
                                || (l_link_train == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_ODD_ONLY);

        if(l_tlx_oc)
        {
            auto l_pauc_target = l_iohs_target.getParent<fapi2::TARGET_TYPE_PAUC>();
            fapi2::buffer<uint64_t> l_scom_data(0x0);

            // Throw error if OPT1/2 is configured for OCAPI
            FAPI_ASSERT((l_iohs_id != 1) && (l_iohs_id != 2),
                        fapi2::P10_PAU_SCOMINIT_IOHS_OCAPI_CONFIG_ERR()
                        .set_IOHS_TARGET(l_iohs_target),
                        "IOHS1/IOHS2 cannot be configured for OCAPI operations");

            // Throw error if OPT0/3 does not have a direct PAU to use
            FAPI_ASSERT((((l_iohs_id == 0) || (l_iohs_id == 3)) && l_tlx_pg == true)
                        || ((l_iohs_id != 0) && (l_iohs_id != 3)),
                        fapi2::P10_PAU_SCOMINIT_IOHS_OCAPI_CONFIG_ERR()
                        .set_IOHS_TARGET(l_iohs_target),
                        "Unable to map IOHS0/IOHS3 to a valid PAU for OCAPI operations");

            // Throw error if OPT4/5/6/7 in west corners do not meet PAU criteria:
            // If both links in corner are configured for ocapi, both pau need to be good -or-
            // If one link in corner is configured for ocapi, atleast one pau needs to be good
            FAPI_ASSERT(((l_tlx_oc && l_tly_oc) && (l_tlx_pg && l_tly_pg))
                        || ((l_tlx_oc && !l_tly_oc) && (l_tlx_pg || l_tly_pg)),
                        fapi2::P10_PAU_SCOMINIT_IOHS_OCAPI_CONFIG_ERR()
                        .set_IOHS_TARGET(l_iohs_target),
                        "Not enough PAU chiplets for IOHS OCAPI link(s) within corner");

            // Use direct OPT->PAU mapping for OpenCAPI operations if possible
            // Else leverage sister PAU chiplet for a swizzled mapping
            transport_ob_mux* values = (l_tlx_pg == true) ? (&direct) : (&sister);

            // Transport Outbound Mux
            //   PB.AXON_OPT[0-7]_EVN_CFG
            //   PB.AXON_OPT[0-7]_ODD_CFG
            FAPI_TRY(GET_PB_MISC_CFG(l_pauc_target, l_scom_data));

            if(l_evn_iohs && l_evn_sublink_en) // opt[46] evn
            {
                SET_PB_MISC_CFG_TRANSPORT_0_ENABLE(l_scom_data);
                SET_PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0(values->transport_01_ob_mux0, l_scom_data);
                SET_PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1(values->transport_01_ob_mux1, l_scom_data);
                SET_PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2(values->transport_01_ob_mux2, l_scom_data);
            }

            if(l_evn_iohs && l_odd_sublink_en) // opt[46] odd
            {
                SET_PB_MISC_CFG_TRANSPORT_1_ENABLE(l_scom_data);
                SET_PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0(values->transport_01_ob_mux0, l_scom_data);
                SET_PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1(values->transport_01_ob_mux1, l_scom_data);
                SET_PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2(values->transport_01_ob_mux2, l_scom_data);
            }

            if(l_odd_iohs && l_evn_sublink_en) // opt[0357] evn
            {
                SET_PB_MISC_CFG_TRANSPORT_2_ENABLE(l_scom_data);
                SET_PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0(values->transport_23_ob_mux0, l_scom_data);
                SET_PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1(values->transport_23_ob_mux1, l_scom_data);
                SET_PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2(values->transport_23_ob_mux2, l_scom_data);
            }

            if(l_odd_iohs && l_odd_sublink_en) // opt[0357] odd
            {
                SET_PB_MISC_CFG_TRANSPORT_3_ENABLE(l_scom_data);
                SET_PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0(values->transport_23_ob_mux0, l_scom_data);
                SET_PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1(values->transport_23_ob_mux1, l_scom_data);
                SET_PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2(values->transport_23_ob_mux2, l_scom_data);
            }

            // Transport Inbound Mux
            // Note that pau[03] has no mux that needs to be configured
            //   PB.PTLSCOM10.TRANSPORT_PAU0_EVN_IB_MUX_EN -- pau[46]
            //   PB.PTLSCOM10.TRANSPORT_PAU0_ODD_IB_MUX_EN -- pau[46]
            //   PB.PTLSCOM10.TRANSPORT_PAU1_EVN_IB_MUX_EN -- pau[57]
            //   PB.PTLSCOM10.TRANSPORT_PAU1_ODD_IB_MUX_EN -- pau[57]
            bool l_pau03_mapped = ((l_iohs_id == 0) || (l_iohs_id == 3)) ? true : false;
            bool l_pau46_mapped = (l_iohs_id % 2) ? (l_tlx_pg ? false : true) : (l_tlx_pg ? true : false);

            if(l_evn_sublink_en && !l_pau03_mapped)
            {
                l_pau46_mapped ?
                SET_PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN(l_scom_data) : // pau[46] evn
                SET_PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN(l_scom_data);  // pau[57] evn
            }

            if(l_odd_sublink_en && !l_pau03_mapped)
            {
                l_pau46_mapped ?
                SET_PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN(l_scom_data) : // pau[46] odd
                SET_PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN(l_scom_data);  // pau[57] odd
            }

            FAPI_TRY(PUT_PB_MISC_CFG(l_pauc_target, l_scom_data));

            // Select PHY to feed inbound data back to the PAU (0=matching PHY, 1=other PHY)
            // Only needs to be configured if not doing a direct opt->pau mapping
            //   PAU[0-7].MISC.REGS.PAU_TRANSPORT_NTL0_NOT_OTH
            //   PAU[0-7].MISC.REGS.PAU_TRANSPORT_NTL1_NOT_OTH
            if(!l_tlx_pg)
            {
                // No direct opt->pau mapping means there is only one pau available in the corner
                auto l_tly_pau_target = l_pauc_target.getChildren<fapi2::TARGET_TYPE_PAU>().front();

                FAPI_TRY(GET_MISC_REGS_OPTICAL_IO_CONFIG(l_tly_pau_target, l_scom_data));
                SET_MISC_REGS_OPTICAL_IO_CONFIG_NTL0_NOT_OTH(l_scom_data); // evn
                SET_MISC_REGS_OPTICAL_IO_CONFIG_NTL1_NOT_OTH(l_scom_data); // odd
                FAPI_TRY(PUT_MISC_REGS_OPTICAL_IO_CONFIG(l_tly_pau_target, l_scom_data));
            }

            // Write attribute for opt->pau mapping
            uint8_t l_pau_id = (l_tlx_pg) ? (l_iohs_id) : ((l_iohs_id % 2) ? (l_iohs_id - 1) : (l_iohs_id + 1));
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_IOHS_PHY_TO_PAU_MAPPING, l_iohs_target, l_pau_id),
                     "Error from FAPI_ATTR_SET (ATTR_IOHS_PHY_TO_PAU_MAPPING)");
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Configure DL for OpenCAPI links
///
/// @param[in] i_target         Reference to processor chip target
/// @return fapi2::ReturnCode   FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_pau_scominit_dl(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    using namespace scomt;
    using namespace scomt::iohs;

    for(auto l_iohs_target : i_target.getChildren<fapi2::TARGET_TYPE_IOHS>())
    {
        fapi2::ATTR_IOHS_CONFIG_MODE_Type l_config_mode;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_CONFIG_MODE, l_iohs_target, l_config_mode),
                 "Error from FAPI_ATTR_GET (ATTR_IOHS_CONFIG_MODE)");

        if(l_config_mode == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_OCAPI)
        {
            fapi2::buffer<uint64_t> l_dlp_config(0x0);

            //fapi2::ATTR_IOHS_LINK_TRAIN_Type l_link_train;
            //FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_LINK_TRAIN, l_iohs_target, l_link_train),
            //         "Error from FAPI_ATTR_GET (ATTR_IOHS_LINK_TRAIN)");

            // DLP0.DLP.CONFIG_DL_SELECT = DLO
            // DLP0.DLP.CONFIG_LINK0_SELECT = ON (if even link enabled)
            // DLP0.DLP.CONFIG_LINK1_SELECT = ON (if odd link enabled)
            FAPI_TRY(GET_DLP_PHY_CONFIG(l_iohs_target, l_dlp_config));
            SET_DLP_PHY_CONFIG_DL_SELECT(ENUM_DLP_CONFIG_DL_SELECT_DLO, l_dlp_config);

            //switch(l_link_train)
            //{
            //    case fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_BOTH:
            //        SET_DLP_PHY_CONFIG_LINK0_SELECT(l_dlp_config);
            //        SET_DLP_PHY_CONFIG_LINK1_SELECT(l_dlp_config);
            //        break;

            //    case fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_EVEN_ONLY:
            //        SET_DLP_PHY_CONFIG_LINK0_SELECT(l_dlp_config);
            //        break;

            //    case fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_ODD_ONLY:
            //        SET_DLP_PHY_CONFIG_LINK1_SELECT(l_dlp_config);
            //        break;

            //    default:
            //        CLEAR_DLP_PHY_CONFIG_LINK0_SELECT(l_dlp_config);
            //        CLEAR_DLP_PHY_CONFIG_LINK1_SELECT(l_dlp_config);
            //        break;
            //}

            FAPI_TRY(PUT_DLP_PHY_CONFIG(l_iohs_target, l_dlp_config));

            //// DLP0.DLP.CONFIG_LINK_PAIR = ON (if both even/odd link enabled)
            //if(l_link_train == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_BOTH)
            //{
            //    FAPI_TRY(GET_DLP_CONFIG(l_iohs_target, l_dlp_config));
            //    SET_DLP_CONFIG_LINK_PAIR(l_dlp_config);
            //    FAPI_TRY(PUT_DLP_CONFIG(l_iohs_target, l_dlp_config));
            //}
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}


/// See doxygen comments in header file
fapi2::ReturnCode p10_pau_scominit(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Start");

    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    auto l_pau_targets = i_target.getChildren<fapi2::TARGET_TYPE_PAU>();

    // Apply PAU scom initfile
    for(auto l_pau_target : l_pau_targets)
    {
        fapi2::ReturnCode l_rc;
        char l_tgt_str[fapi2::MAX_ECMD_STRING_LEN];
        fapi2::toString(l_pau_target, l_tgt_str, sizeof(l_tgt_str));

        FAPI_DBG("Invoking p10.pau.scom.initfile on target %s...", l_tgt_str);
        FAPI_EXEC_HWP(l_rc, p10_pau_scom, l_pau_target, i_target, FAPI_SYSTEM);
        FAPI_TRY(l_rc, "Error from p10.pau.scom.initfile");
    }

    // Configure DL for OpenCAPI-configured links
    FAPI_TRY(p10_pau_scominit_dl(i_target),
             "Error from p10_pau_scominit_dl");

    // Configure TL for OpenCAPI-configured links
    FAPI_TRY(p10_pau_scominit_tl(i_target),
             "Error from p10_pau_scominit_tl");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
