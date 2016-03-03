/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_fab_iovalid.C $               */
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
/// @file p9_fab_iovalid.C
/// @brief Manage fabric link iovalid controls (FAPI2)
///
/// @author Joe McGill <jmcgill@us.ibm.com>
///

//
// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: HB,FSP
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_fab_iovalid.H>
#include <p9_fbc_smp_utils.H>


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
// EXTFIR/RAS FIR field constants
const uint8_t IOVALID_FIELD_NUM_BITS = 2;

// DL FIR register field constants
const uint8_t DL_FIR_LINK0_TRAINED_BIT = 0;
const uint8_t DL_FIR_LINK1_TRAINED_BIT = 1;

// TL FIR register field constants
const uint8_t TL_FIR_TRAINED_FIELD_LENGTH = 2;
const uint8_t TL_FIR_TRAINED_LINK_TRAINED = 0x3;

// TL Link Delay register field constants
const uint8_t TL_LINK_DELAY_FIELD_NUM_BITS = 12;


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


/// @brief Validate DL/TL link layers are trained
///
/// @param[in]  i_target          Processor chip target
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p9_fab_iovalid_link_validate(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9_fbc_link_ctl_t& i_link_ctl)
{
    FAPI_DBG("Start");
    fapi2::buffer<uint64_t> l_dl_fir_reg;
    fapi2::buffer<uint64_t> l_tl_fir_reg;
    uint8_t l_tl_fir_trained_state = 0;

    // validate DL training state
    FAPI_TRY(fapi2::getScom(i_target, i_link_ctl.dl_fir_addr, l_dl_fir_reg),
             "Error from getScom (0x%.16llX)", i_link_ctl.dl_fir_addr);
    FAPI_ASSERT(l_dl_fir_reg.getBit<DL_FIR_LINK0_TRAINED_BIT>() &&
                l_dl_fir_reg.getBit<DL_FIR_LINK1_TRAINED_BIT>(),
                fapi2::P9_FAB_IOVALID_DL_NOT_TRAINED_ERR()
                .set_TARGET(i_target)
                .set_LOC_ENDP_TYPE(i_link_ctl.endp_type)
                .set_LOC_ENDP_UNIT_ID(i_link_ctl.endp_unit_id)
                .set_DL_FIR_REG(l_dl_fir_reg),
                "Link DL training did not complete successfully!");

    // validate TL training state
    FAPI_TRY(fapi2::getScom(i_target, i_link_ctl.tl_fir_addr, l_tl_fir_reg),
             "Error from getScom (0x%.16llX)", i_link_ctl.tl_fir_addr);
    FAPI_TRY(l_tl_fir_reg.extractToRight(l_tl_fir_trained_state,
                                         i_link_ctl.tl_fir_trained_field_start_bit,
                                         TL_FIR_TRAINED_FIELD_LENGTH),
             "Error extracting TL layer training state");

    FAPI_ASSERT(l_tl_fir_trained_state == TL_FIR_TRAINED_LINK_TRAINED,
                fapi2::P9_FAB_IOVALID_TL_NOT_TRAINED_ERR()
                .set_TARGET(i_target)
                .set_LOC_ENDP_TYPE(i_link_ctl.endp_type)
                .set_LOC_ENDP_UNIT_ID(i_link_ctl.endp_unit_id)
                .set_TL_FIR_REG(l_tl_fir_reg),
                "Link TL training did not complete successfully!");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


/// @brief Compute single end link delay of individual link
///
/// @param[in]  i_target          Processor chip target
/// @param[in]  i_link_ctl        X/A link control structure for link
/// @param[out] o_link_delay      Link delay
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p9_fab_iovalid_get_link_delay(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9_fbc_link_ctl_t& i_link_ctl,
    uint32_t o_link_delay)
{
    FAPI_DBG("Start");
    fapi2::buffer<uint64_t> l_link_delay_reg;
    uint32_t l_sublink_delay[2];

    // read link delay register, extract hi/lo delay values & return their average
    FAPI_TRY(fapi2::getScom(i_target, i_link_ctl.tl_link_delay_addr, l_link_delay_reg),
             "Error from getScom (0x%.16llX)", i_link_ctl.tl_link_delay_addr);
    FAPI_TRY(l_link_delay_reg.extractToRight(l_sublink_delay[0],
             i_link_ctl.tl_link_delay_hi_start_bit,
             TL_LINK_DELAY_FIELD_NUM_BITS),
             "Error extracting link delay (hi>");
    FAPI_TRY(l_link_delay_reg.extractToRight(l_sublink_delay[1],
             i_link_ctl.tl_link_delay_lo_start_bit,
             TL_LINK_DELAY_FIELD_NUM_BITS),
             "Error extracting link delay (lo)");
    o_link_delay = (l_sublink_delay[0] + l_sublink_delay[1]) / 2;

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


/// @brief Get round trip training delays reported by both endpoints
///        of a given link
///
/// @tparam T template parameter, defines endpoint type
/// @param[in]  i_loc_target        Source side chip target
/// @param[in]  i_loc_link_ctl      X/A link control structure for link local end
/// @param[in]  i_rem_link_ctl      X/A link control structure for link remote end
/// @param[out] o_agg_link_delay    Sum of local and remote end link delays
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
template<fapi2::TargetType T>
fapi2::ReturnCode p9_fab_iovalid_get_link_delays(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_loc_chip_target,
    const p9_fbc_link_ctl_t& i_loc_link_ctl,
    const p9_fbc_link_ctl_t& i_rem_link_ctl,
    uint32_t& o_agg_link_delay)
{
    FAPI_DBG("Start");

    bool l_found = false;
    uint32_t l_loc_link_delay = 0xFFF;
    uint32_t l_rem_link_delay = 0xFFF;
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_rem_chip_target;

    // use local end link control structure to find associated endpoint target
    auto l_endp_targets = i_loc_chip_target.getChildren<T>();

    for (auto l_iter = l_endp_targets.begin();
         (l_iter != l_endp_targets.end()) && !l_found;
         l_iter++)
    {
        uint8_t l_loc_endp_unit_id;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, *l_iter, l_loc_endp_unit_id),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS, local)");

        if ((static_cast<fapi2::TargetType>(i_loc_link_ctl.endp_type) == T) &&
            (i_loc_link_ctl.endp_unit_id == l_loc_endp_unit_id))
        {
            // associated endpoint target found, use getOtherEnd/getParent to reach chip
            // target of connected chip
            fapi2::Target<T> l_rem_endp_target;
            fapi2::ReturnCode l_rc = l_iter->getOtherEnd(l_rem_endp_target);
            FAPI_ASSERT(!l_rc,
                        fapi2::P9_FAB_IOVALID_REM_ENDP_TARGET_ERR()
                        .set_LOC_TARGET(i_loc_chip_target)
                        .set_LOC_ENDP_TYPE(i_loc_link_ctl.endp_type)
                        .set_LOC_ENDP_UNIT_ID(i_loc_link_ctl.endp_unit_id)
                        .set_REM_ENDP_UNIT_ID(i_rem_link_ctl.endp_unit_id),
                        "Endpoint target at other end of link is invalid!");

            l_rem_chip_target = l_rem_endp_target.template getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
            l_found = true;
        }
    }

    FAPI_ASSERT(l_found,
                fapi2::P9_FAB_IOVALID_LOC_ENDP_TARGET_ERR()
                .set_LOC_TARGET(i_loc_chip_target)
                .set_LOC_ENDP_TYPE(i_loc_link_ctl.endp_type)
                .set_LOC_ENDP_UNIT_ID(i_loc_link_ctl.endp_unit_id),
                "No matching local endpoint target found!");

    // read link delay from local/remote chip targets
    // link control structures provide register/bit offsets to collect
    FAPI_TRY(p9_fab_iovalid_get_link_delay(
                 i_loc_chip_target,
                 i_loc_link_ctl,
                 l_loc_link_delay),
             "Error from p9_fab_iovalid_get_link_delay (local)");

    FAPI_TRY(p9_fab_iovalid_get_link_delay(
                 l_rem_chip_target,
                 i_rem_link_ctl,
                 l_rem_link_delay),
             "Error from p9_fab_iovalid_get_link_delay (remote)");

    o_agg_link_delay = l_loc_link_delay + l_rem_link_delay;

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}



///
/// @brief Manipulate iovalid/FIR settings for a single fabric link (X/A)
///
/// @param[in] i_target        Reference to processor chip target
/// @param[in] i_ctl           Reference to link control structure
/// @param[in] i_set_not_clear Define iovalid operation (true=set, false=clear)
///
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode
p9_fab_iovalid_update_link(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                           const p9_fbc_link_ctl_t& i_ctl,
                           const bool i_set_not_clear)
{
    FAPI_DBG("Start");

    // form data buffers for iovalid/RAS FIR mask updates
    fapi2::buffer<uint64_t> l_iovalid_mask;
    fapi2::buffer<uint64_t> l_ras_fir_mask;

    if (i_set_not_clear)
    {
        // set iovalid
        l_iovalid_mask.flush<0>();
        FAPI_TRY(l_iovalid_mask.setBit(i_ctl.iovalid_field_start_bit,
                                       IOVALID_FIELD_NUM_BITS));
        // clear RAS FIR mask
        l_ras_fir_mask.flush<1>();
        FAPI_TRY(l_ras_fir_mask.clearBit(i_ctl.ras_fir_field_bit));
    }
    else
    {
        // clear iovalid
        l_iovalid_mask.flush<1>();
        FAPI_TRY(l_iovalid_mask.clearBit(i_ctl.iovalid_field_start_bit,
                                         IOVALID_FIELD_NUM_BITS));
        // set RAS FIR mask
        l_ras_fir_mask.flush<0>();
        FAPI_TRY(l_ras_fir_mask.setBit(i_ctl.ras_fir_field_bit));
    }

    // use AND/OR mask registers to atomically update link specific fields
    // in iovalid/RAS FIR mask registers
    FAPI_TRY(fapi2::putScom(i_target,
                            (i_set_not_clear) ? (i_ctl.iovalid_or_addr) : (i_ctl.iovalid_clear_addr),
                            l_iovalid_mask),
             "Error writing iovalid control register!");

    FAPI_TRY(fapi2::putScom(i_target,
                            (i_set_not_clear) ? (PU_PB_CENT_SM1_EXTFIR_MASK_REG_AND) : (PU_PB_CENT_SM1_EXTFIR_MASK_REG_OR),
                            l_ras_fir_mask),
             "Error writing RAS FIR mask register!");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


// NOTE: see doxygen comments in header
fapi2::ReturnCode
p9_fab_iovalid(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
               const bool i_set_not_clear,
               const bool i_manage_electrical,
               const bool i_manage_optical)
{
    FAPI_INF("Start");

    // logical link (X/A) configuration parameters
    // arrays indexed by link ID on local end
    // enable on local end
    uint8_t l_x_en[P9_FBC_UTILS_MAX_X_LINKS];
    uint8_t l_a_en[P9_FBC_UTILS_MAX_A_LINKS];
    // link ID on remote end
    uint8_t l_x_rem_link_id[P9_FBC_UTILS_MAX_X_LINKS];
    uint8_t l_a_rem_link_id[P9_FBC_UTILS_MAX_A_LINKS];
    // aggregate (local+remote) delays
    uint32_t l_x_agg_link_delay[P9_FBC_UTILS_MAX_X_LINKS];
    uint32_t l_a_agg_link_delay[P9_FBC_UTILS_MAX_A_LINKS];

    // seed arrays with attribute values
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG, i_target, l_x_en),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_LINK_ID, i_target, l_x_rem_link_id),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ATTACHED_LINK_ID");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_LINK_DELAY, i_target, l_x_agg_link_delay),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_LINK_DELAY");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG, i_target, l_a_en),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_LINK_ID, i_target, l_a_rem_link_id),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_ATTACHED_LINK_ID");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_LINK_DELAY, i_target, l_a_agg_link_delay),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_LINK_DELAY");

    for (uint8_t l_link_id = 0; l_link_id < P9_FBC_UTILS_MAX_X_LINKS; l_link_id++)
    {
        if (l_x_en[l_link_id])
        {
            if ((i_manage_electrical &&
                 (P9_FBC_XBUS_LINK_CTL_ARR[l_link_id].endp_type == ELECTRICAL)) ||
                (i_manage_optical &&
                 (P9_FBC_XBUS_LINK_CTL_ARR[l_link_id].endp_type == OPTICAL)))
            {
                FAPI_DBG("Updating link X%d", l_link_id);
                FAPI_TRY(p9_fab_iovalid_update_link(i_target,
                                                    P9_FBC_XBUS_LINK_CTL_ARR[l_link_id],
                                                    i_set_not_clear),
                         "Error from p9_fab_iovalid_update_link (X)");

                if (i_set_not_clear)
                {
                    FAPI_DBG("Collecting link delay counter values");

                    if (P9_FBC_XBUS_LINK_CTL_ARR[l_link_id].endp_type == ELECTRICAL)
                    {
                        FAPI_TRY(p9_fab_iovalid_get_link_delays<fapi2::TARGET_TYPE_XBUS>(
                                     i_target,
                                     P9_FBC_XBUS_LINK_CTL_ARR[l_link_id],
                                     P9_FBC_XBUS_LINK_CTL_ARR[l_x_rem_link_id[l_link_id]],
                                     l_x_agg_link_delay[l_link_id]),
                                 "Error from p9_fab_iovalid_get_link_delays (X, electrical)");
                    }
                    else
                    {
                        FAPI_TRY(p9_fab_iovalid_get_link_delays<fapi2::TARGET_TYPE_OBUS>(
                                     i_target,
                                     P9_FBC_XBUS_LINK_CTL_ARR[l_link_id],
                                     P9_FBC_XBUS_LINK_CTL_ARR[l_x_rem_link_id[l_link_id]],
                                     l_x_agg_link_delay[l_link_id]),
                                 "Error from p9_fab_iovalid_get_link_delays (X, optical)");
                    }
                }
            }
        }
        else
        {
            FAPI_DBG("Skipping link X%d", l_link_id);
        }
    }

    for (uint8_t l_link_id = 0; l_link_id < P9_FBC_UTILS_MAX_A_LINKS; l_link_id++)
    {
        if (l_a_en[l_link_id])
        {
            if (i_manage_optical &&
                (P9_FBC_ABUS_LINK_CTL_ARR[l_link_id].endp_type == OPTICAL))
            {
                FAPI_DBG("Updating link A%d", l_link_id);
                FAPI_TRY(p9_fab_iovalid_update_link(i_target,
                                                    P9_FBC_ABUS_LINK_CTL_ARR[l_link_id],
                                                    i_set_not_clear),
                         "Error from p9_fab_iovalid_update_link (A)");

                if (i_set_not_clear)
                {
                    FAPI_DBG("Collecting link delay counter values");
                    FAPI_TRY(p9_fab_iovalid_get_link_delays<fapi2::TARGET_TYPE_OBUS>(
                                 i_target,
                                 P9_FBC_ABUS_LINK_CTL_ARR[l_link_id],
                                 P9_FBC_ABUS_LINK_CTL_ARR[l_a_rem_link_id[l_link_id]],
                                 l_a_agg_link_delay[l_link_id]),
                             "Error from p9_fab_iovalid_get_link_delays (A)");
                }
            }
        }
        else
        {
            FAPI_DBG("Skipping link A%d", l_link_id);
        }
    }

    // update link delay attributes
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_X_LINK_DELAY, i_target, l_x_agg_link_delay),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_LINK_DELAY");

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_A_LINK_DELAY, i_target, l_a_agg_link_delay),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_LINK_DELAY");

fapi_try_exit:
    FAPI_INF("End");
    return fapi2::current_err;
}
