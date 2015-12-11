/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_build_smp_adu.C $             */
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
/// @file p9_build_smp_adu.C
/// @brief Interface for ADU operations required to support fabric
///        configuration actions (FAPI2)
///
/// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
/// *HWP Team: Nest
/// *HWP Level: 2
/// *HWP Consumed by: HB,FSP
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_build_smp_adu.H>
#include <p9_adu_coherent_utils.H>
#include <p9_misc_scom_addresses.H>

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------

// Poll threshold
const uint32_t P9_BUILD_SMP_MAX_STATUS_POLLS = 100;

// ADU lock
const uint32_t P9_BUILD_SMP_PHASE1_ADU_LOCK_ATTEMPTS = 1;
const bool P9_BUILD_SMP_PHASE1_ADU_PICK_LOCK = false;

const uint32_t P9_BUILD_SMP_PHASE2_ADU_LOCK_ATTEMPTS = 5;
const bool P9_BUILD_SMP_PHASE2_ADU_PICK_LOCK = true;

// ADU pMISC Mode register field/bit definitions
const uint32_t ADU_PMISC_MODE_ENABLE_PB_SWITCH_AB_BIT = 30;
const uint32_t ADU_PMISC_MODE_ENABLE_PB_SWITCH_CD_BIT = 31;

enum p9_build_smp_ffdc_reg_index
{
    PB_MODE_CENT_DATA_INDEX = 0,
    PB_HP_MODE_NEXT_CENT_DATA_INDEX = 1,
    PB_HP_MODE_CURR_CENT_DATA_INDEX = 2,
    PB_HPX_MODE_NEXT_CENT_DATA_INDEX = 3,
    PB_HPX_MODE_CURR_CENT_DATA_INDEX = 4,
    X_GP0_DATA_INDEX = 5,
    PB_X_MODE_DATA_INDEX = 6,
    A_GP0_DATA_INDEX = 7,
    ADU_IOS_LINK_EN_DATA_INDEX = 8,
    PB_A_MODE_DATA_INDEX = 9,
    ADU_PMISC_MODE_DATA_INDEX = 10
};

extern "C"
{

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------
///
/// @brief Check ADU status matches expected state/value
///        NOTE: intended to be run while holding ADU lock
///
/// @param[in] i_target                P9 target
/// @param[in] i_smp                   Structure encapsulating SMP topology
/// @param[in] i_dump_all_targets      Dump FFDC for all targets in SMP?
///                                    true=yes; false=no (only for i_target)
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_build_smp_adu_check_status(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        p9_build_smp_system& i_smp,
        const bool i_dump_all_targets)
    {
        FAPI_DBG("Start");
        fapi2::ReturnCode l_rc;
        uint32_t l_numPolls = 0;
        bool l_busyBitStatus = false;

        // SMP SWITCH expect BUSY BIT to be clear
        adu_status_busy_handler l_busyHandling = EXIT_ON_BUSY;

        // Wait for operation to be completed (busy bit cleared)
        while (l_numPolls < P9_BUILD_SMP_MAX_STATUS_POLLS)
        {
            l_rc = p9_adu_coherent_status_check(i_target, l_busyHandling, true,
                                                l_busyBitStatus);

            if (l_rc)
            {
                FAPI_ERR("p9_adu_coherent_status_check() returns error");
                break;
            }

            if (l_busyBitStatus == true)
            {
                l_numPolls++;

                // Last try, set handler to expect busy bit clear, if not then
                // p9_adu_coherent_status_check() will log an error so that
                // we don't have to deal with the error separately here.
                if (l_numPolls == (P9_BUILD_SMP_MAX_STATUS_POLLS - 1))
                {
                    l_busyHandling = EXPECTED_BUSY_BIT_CLEAR;
                }
            }
            else
            {
                // Operation done, break out
                break;
            }
        }

        FAPI_DBG("Num of polls %u", l_numPolls);

        // TODO: RTC 147511 - Need to add code to dump FFDC
        // Note: variable_buffer doesn't currently support resize because it's
        // an expensive operation.
        // Per Joe's suggestion, may be we can size statically by the maximum
        // number of chips possible in the system.  It's not efficient, but
        // this is an error path.
#if 0

        // Additional error handling for SMP build
        if (l_rc)
        {
            fapi2::current_err = l_rc;


            // Dump FFDC
            // There is no clean way to represent the collection in XML (given an
            // arbitrary number of chips), so collect manually and store into data
            // buffers which can be post-processed from the error log
            std::map<p9_fab_smp_node_id, p9_build_smp_node>::iterator n_iter;
            std::map<p9_fab_smp_chip_id, p9_build_smp_chip>::iterator p_iter;
            std::vector<fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>*> targets_to_collect;
            fapi2::buffer<uint64_t> l_scomData;
            fapi2::variable_buffer l_chipIds;
            fapi2::variable_buffer l_ffdcRegData[P9_BUILD_SMP_FFDC_NUM_REGS];
            bool l_ffdcScomError = false;

            // Determine set of chips to collect
            for (n_iter = i_smp.nodes.begin();
                 n_iter != i_smp.nodes.end();
                 ++n_iter)
            {
                for (p_iter = n_iter->second.chips.begin();
                     p_iter != n_iter->second.chips.end();
                     ++p_iter)
                {
                    if (i_dump_all_targets ||
                        (p_iter->second.chip->this_chip == i_target))
                    {
                        targets_to_collect.push_back(
                            &(p_iter->second.chip->this_chip));
                    }
                }
            }

            // Size the FFDC buffers
            rc_ecmd |= chip_ids.setByteLength(targets_to_collect.size());

            for (uint8_t i = 0; i < P9_BUILD_SMP_FFDC_NUM_REGS; i++)
            {
                rc_ecmd |= ffdc_reg_data[i].setDoubleWordLength(targets_to_collect.size());
            }

            // extract FFDC data
            std::vector<bool>::iterator n = nv_present.begin();

            for (std::vector<fapi::Target*>::iterator t = targets_to_collect.begin();
                 t != targets_to_collect.end();
                 t++, n++)
            {
                // log node/chip ID
                for (n_iter = i_smp.nodes.begin();
                     n_iter != i_smp.nodes.end();
                     n_iter++)
                {
                    for (p_iter = n_iter->second.chips.begin();
                         p_iter != n_iter->second.chips.end();
                         p_iter++)
                    {
                        if ((&(p_iter->second.chip->this_chip)) == *t)
                        {
                            uint8_t id = ((n_iter->first & 0x3) << 4) |
                                         (p_iter->first & 0x3);

                            rc_ecmd |= chip_ids.setByte(t - targets_to_collect.begin(), id);
                        }
                    }
                }

                // collect SCOM data
                for (uint8_t i = 0; i < P9_BUILD_SMP_FFDC_NUM_REGS; i++)
                {
                    // skip A / F link registers if NV link logic is present
                    if ((*n) &&
                        ((i == static_cast<uint8_t>(A_GP0_DATA_INDEX)) ||
                         (i == static_cast<uint8_t>(ADU_IOS_LINK_EN_DATA_INDEX)) ||
                         (i == static_cast<uint8_t>(PB_A_MODE_DATA_INDEX))))
                    {
                        rc_ecmd |= scom_data.flushTo1();
                    }
                    else
                    {
                        rc = fapiGetScom(*(*t), P9_BUILD_SMP_FFDC_REGS[i], scom_data);

                        if (!rc.ok())
                        {
                            ffdc_scom_error = true;
                        }
                    }

                    rc_ecmd |= scom_data.extractPreserve(
                                   ffdc_reg_data[i],
                                   0, 64,
                                   64 * (t - targets_to_collect.begin()));
                }
            }

            const fapi::Target& TARGET = i_target;
            const p9_adu_utils_adu_status& ADU_STATUS_DATA = status;
            const uint8_t& ADU_NUM_POLLS = num_polls;
            const uint8_t& NUM_CHIPS = targets_to_collect.size();
            const uint8_t& FFDC_VALID = !rc_ecmd && !ffdc_scom_error;
            const ecmdDataBufferBase& CHIP_IDS = chip_ids;
            const ecmdDataBufferBase& PB_MODE_CENT_DATA = ffdc_reg_data[0];
            const ecmdDataBufferBase& PB_HP_MODE_NEXT_CENT_DATA = ffdc_reg_data[1];
            const ecmdDataBufferBase& PB_HP_MODE_CURR_CENT_DATA = ffdc_reg_data[2];
            const ecmdDataBufferBase& PB_HPX_MODE_NEXT_CENT_DATA = ffdc_reg_data[3];
            const ecmdDataBufferBase& PB_HPX_MODE_CURR_CENT_DATA = ffdc_reg_data[4];
            const ecmdDataBufferBase& X_GP0_DATA = ffdc_reg_data[5];
            const ecmdDataBufferBase& PB_X_MODE_DATA = ffdc_reg_data[6];
            const ecmdDataBufferBase& A_GP0_DATA = ffdc_reg_data[7];
            const ecmdDataBufferBase& ADU_IOS_LINK_EN_DATA = ffdc_reg_data[8];
            const ecmdDataBufferBase& PB_A_MODE_DATA = ffdc_reg_data[9];
            const ecmdDataBufferBase& ADU_PMISC_MODE_DATA = ffdc_reg_data[10];
            FAPI_SET_HWP_ERROR(rc, RC_PROC_BUILD_SMP_ADU_STATUS_MISMATCH);
            break;

        }

    fapi_try_exit:
#endif

        FAPI_DBG("End");
        return fapi2::current_err;
    }

// NOTE: see comments above function prototype in header
    fapi2::ReturnCode p9_build_smp_quiesce_pb(p9_build_smp_system& i_smp,
            const p9_build_smp_operation i_op)
    {
        FAPI_DBG("Start");
        fapi2::ReturnCode l_rc;
        bool l_lockPick = false;
        uint8_t l_numAttempts = 1;
        uint64_t l_address = 0; // Address phase
        p9_ADU_oper_flag l_myAduFlag;

        // Node/Chip iterators
        std::map<p9_fab_smp_node_id, p9_build_smp_node>::iterator n_iter;
        std::map<p9_fab_smp_chip_id, p9_build_smp_chip>::iterator p_iter;
        std::vector<p9_build_smp_chip*>::iterator quiesce_iter;

        // Lock flag
        bool adu_is_dirty = false;

        FAPI_DBG("Acquiring lock for all ADU units in fabric");

        // Set pick lock & num of tries
        l_lockPick = (i_op == SMP_ACTIVATE_PHASE1) ?
                     P9_BUILD_SMP_PHASE1_ADU_PICK_LOCK :
                     P9_BUILD_SMP_PHASE2_ADU_PICK_LOCK;
        l_numAttempts = (i_op == SMP_ACTIVATE_PHASE1) ?
                        P9_BUILD_SMP_PHASE1_ADU_LOCK_ATTEMPTS :
                        P9_BUILD_SMP_PHASE2_ADU_LOCK_ATTEMPTS;

        // Loop through all chips, lock & reset ADU
        for (n_iter = i_smp.nodes.begin();
             n_iter != i_smp.nodes.end();
             ++n_iter)
        {
            for (p_iter = n_iter->second.chips.begin();
                 p_iter != n_iter->second.chips.end();
                 ++p_iter)
            {
                // Acquire ADU lock
                FAPI_TRY(p9_adu_coherent_manage_lock(
                             p_iter->second.chip->this_chip,
                             l_lockPick,
                             true,           // Acquire lock
                             l_numAttempts),
                         "p9_adu_coherent_manage_lock() - Lock returns an error, l_rc 0x%.8X",
                         (uint64_t)fapi2::current_err);

                // NOTE: lock is now held, if an operation fails from this point
                //       to the end of the procedure:
                //         o attempt to cleanup/release lock (so that procedure does
                //         not leave the ADU in a locked state)
                //         o return rc of original fail
                adu_is_dirty = true;

                // Reset ADU
                l_rc = p9_adu_coherent_utils_reset_adu(
                           p_iter->second.chip->this_chip);

                if (l_rc)
                {
                    FAPI_ERR("Error from p9_adu_coherent_utils_reset_adu()");
                    goto adu_reset_unlock;
                }
            }
        }

        FAPI_DBG("All ADU locks held");

        // Setup ADU flag to peform quiesce
        l_myAduFlag.setOperationType(p9_ADU_oper_flag::PB_OPER);

        // Issue quiesce on all specified chips
        for (n_iter = i_smp.nodes.begin();
             n_iter != i_smp.nodes.end();
             ++n_iter)
        {
            for (p_iter = n_iter->second.chips.begin();
                 p_iter != n_iter->second.chips.end();
                 ++p_iter)
            {
                if (p_iter->second.issue_quiesce_next)
                {
                    char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];
                    fapi2::toString(p_iter->second.chip->this_chip, l_targetStr,
                                    sizeof(l_targetStr));
                    FAPI_INF("Issuing quiesce from %s", l_targetStr);

                    // Setup and launch command
                    l_rc = p9_adu_coherent_setup_adu(p_iter->second.chip->this_chip,
                                                     l_address,
                                                     false,      // write
                                                     l_myAduFlag.setFlag());

                    if (l_rc)
                    {
                        FAPI_ERR("Error from p9_adu_coherent_setup_adu()");
                        goto adu_reset_unlock;
                    }

                    // Check status
                    l_rc = p9_build_smp_adu_check_status(
                               p_iter->second.chip->this_chip,
                               i_smp,
                               (i_op == SMP_ACTIVATE_PHASE2));

                    if (l_rc)
                    {
                        FAPI_ERR("Error from p9_build_smp_adu_check_status");
                        goto adu_reset_unlock;
                    }
                }
            }
        }

        // Loop through all chips, unlock ADUs
        FAPI_DBG("Releasing lock for all ADU units in drawer");

        for (n_iter = i_smp.nodes.begin();
             n_iter != i_smp.nodes.end();
             ++n_iter)
        {
            for (p_iter = n_iter->second.chips.begin();
                 p_iter != n_iter->second.chips.end();
                 ++p_iter)
            {
                // Release ADU lock
                l_lockPick = false;
                l_numAttempts = (i_op == SMP_ACTIVATE_PHASE1) ?
                                P9_BUILD_SMP_PHASE1_ADU_LOCK_ATTEMPTS :
                                P9_BUILD_SMP_PHASE2_ADU_LOCK_ATTEMPTS;
                FAPI_TRY(p9_adu_coherent_manage_lock(p_iter->second.chip->this_chip,
                                                     l_lockPick,
                                                     false, // Release lock
                                                     l_numAttempts),
                         "p9_adu_coherent_manage_lock() - Release returns an error, l_rc 0x%.8X",
                         (uint64_t)fapi2::current_err);
            }
        }

        FAPI_DBG("All ADU locks released");
        // No error for entire operation, ADU locks released.
        adu_is_dirty = false;

    adu_reset_unlock:

        // If error has occurred and any ADU is dirty,
        // attempt to reset all ADUs and free locks (propogate rc of original fail)
        if (l_rc && adu_is_dirty)
        {
            // Save original error
            fapi2::ReturnCode l_savedRc = l_rc;

            FAPI_INF("Attempting to reset/free lock on all ADUs");

            // loop through all chips, unlock ADUs
            for (n_iter = i_smp.nodes.begin();
                 n_iter != i_smp.nodes.end();
                 ++n_iter)
            {
                for (p_iter = n_iter->second.chips.begin();
                     p_iter != n_iter->second.chips.end();
                     ++p_iter)
                {
                    // Ignore l_rc1 when attempting to reset/unlock
                    l_rc = p9_adu_coherent_utils_reset_adu(
                               p_iter->second.chip->this_chip);
                    l_rc = p9_adu_coherent_manage_lock(
                               p_iter->second.chip->this_chip,
                               false, // No lock pick
                               false, // Lock release
                               1);    // Attempt 1 time
                }
            }

            // Return original error
            fapi2::current_err = l_savedRc;
        }

    fapi_try_exit:
        FAPI_DBG("End");
        return fapi2::current_err;
    }

///
/// @brief Set action which will occur on fabric pmisc switch command
///        NOTE: intended to be run while holding ADU lock
///
/// @param[in] i_target        P9 target
/// @param[in] i_switch_ab     Perform switch AB operation?
/// @param[in] i_switch_cd     Perform switch CD operation?
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_build_smp_adu_set_switch_action(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const bool i_switch_ab,
        const bool i_switch_cd)
    {
        FAPI_DBG("Start");
        fapi2::ReturnCode l_rc;

        fapi2::buffer<uint64_t> pmisc_data;
        fapi2::buffer<uint64_t> pmisc_mask;

        // Build ADU pMisc Mode register content
        FAPI_DBG("Writing ADU pMisc Mode register. Switch_ab %s, Switch_cd %s",
                 i_switch_ab ? "true" : "false", i_switch_cd ? "true" : "false");

        // Switch AB bit
        pmisc_data.writeBit<ADU_PMISC_MODE_ENABLE_PB_SWITCH_AB_BIT>(i_switch_ab);
        pmisc_mask.setBit<ADU_PMISC_MODE_ENABLE_PB_SWITCH_AB_BIT>();

        // Switch CD bit
        pmisc_data.writeBit<ADU_PMISC_MODE_ENABLE_PB_SWITCH_CD_BIT>(i_switch_cd);
        pmisc_mask.setBit<ADU_PMISC_MODE_ENABLE_PB_SWITCH_CD_BIT>();

        FAPI_TRY(fapi2::putScomUnderMask(i_target, PU_SND_MODE_REG,
                                         pmisc_data, pmisc_mask),
                 "putScomUnderMask() returns an error.  Address 0x%.16llX", PU_SND_MODE_REG);

    fapi_try_exit:
        FAPI_DBG("End");
        return fapi2::current_err;
    }

// NOTE: see comments above function prototype in header
    fapi2::ReturnCode p9_build_smp_switch_ab(p9_build_smp_system& i_smp,
            const p9_build_smp_operation i_op)
    {
        FAPI_DBG("Start");
        fapi2::ReturnCode l_rc;
        p9_ADU_oper_flag l_myAduFlag;

        // Chip/Node map iterators
        std::map<p9_fab_smp_node_id, p9_build_smp_node>::iterator n_iter;
        std::map<p9_fab_smp_chip_id, p9_build_smp_chip>::iterator p_iter;

        // Lock flag
        bool adu_is_dirty = false;
        bool l_lockPick = false;
        uint8_t l_numAttempts = 1;
        uint64_t l_address = 0; // Address phase

        // Loop through all chips, lock & reset ADU & set switch action
        for (n_iter = i_smp.nodes.begin();
             n_iter != i_smp.nodes.end();
             ++n_iter)
        {
            for (p_iter = n_iter->second.chips.begin();
                 p_iter != n_iter->second.chips.end();
                 ++p_iter)
            {
                // Set pick lock & num of tries
                l_lockPick = (i_op == SMP_ACTIVATE_PHASE1) ?
                             P9_BUILD_SMP_PHASE1_ADU_PICK_LOCK :
                             P9_BUILD_SMP_PHASE2_ADU_PICK_LOCK;
                l_numAttempts = (i_op == SMP_ACTIVATE_PHASE1) ?
                                P9_BUILD_SMP_PHASE1_ADU_LOCK_ATTEMPTS :
                                P9_BUILD_SMP_PHASE2_ADU_LOCK_ATTEMPTS;

                // Acquire ADU lock
                FAPI_TRY(p9_adu_coherent_manage_lock(
                             p_iter->second.chip->this_chip,
                             l_lockPick,
                             true,           // Acquire lock
                             l_numAttempts),
                         "p9_adu_coherent_manage_lock() - Lock returns an error, l_rc 0x%.8X",
                         (uint64_t)fapi2::current_err);

                // NOTE: lock is now held, if an operation fails from this point
                //       to the end of the procedure:
                //         o attempt to cleanup/release lock (so that procedure does
                //         not leave the ADU in a locked state)
                //         o return rc of original fail
                adu_is_dirty = true;

                // Reset ADU
                l_rc = p9_adu_coherent_utils_reset_adu(
                           p_iter->second.chip->this_chip);

                if (l_rc)
                {
                    FAPI_ERR("Error from p9_adu_coherent_utils_reset_adu()");
                    goto adu_reset_unlock;
                }

                // Condition for switch AB operation
                // all chips which were not quiesced prior to switch AB will
                // need to observe the switch
                l_rc = p9_build_smp_adu_set_switch_action(
                           p_iter->second.chip->this_chip,
                           !p_iter->second.quiesced_next,
                           false);

                if (l_rc)
                {
                    FAPI_ERR("(Set): Error from p9_build_smp_adu_set_switch_action()");
                    goto adu_reset_unlock;
                }
            }
        }

        FAPI_DBG("All ADU locks held");

        // Setup ADU flag to peform switch
        l_myAduFlag.setOperationType(p9_ADU_oper_flag::PMISC_OPER);

        char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];
        fapi2::toString(i_smp.nodes[i_smp.master_chip_curr_node_id].chips[i_smp.master_chip_curr_chip_id].chip->this_chip,
                        l_targetStr,
                        sizeof(l_targetStr));
        FAPI_INF("Issuing switch AB from %s", l_targetStr);

        // Setup and launch command
        l_rc = p9_adu_coherent_setup_adu(
                   i_smp.nodes[i_smp.master_chip_curr_node_id].chips[i_smp.master_chip_curr_chip_id].chip->this_chip,
                   l_address,
                   false,      // write
                   l_myAduFlag.setFlag());

        if (l_rc)
        {
            FAPI_ERR("Error from p9_adu_coherent_setup_adu()");
            goto adu_reset_unlock;
        }

        // Check status
        l_rc = p9_build_smp_adu_check_status(
                   i_smp.nodes[i_smp.master_chip_curr_node_id].chips[i_smp.master_chip_curr_chip_id].chip->this_chip,
                   i_smp,
                   (i_op == SMP_ACTIVATE_PHASE2));

        if (l_rc)
        {
            FAPI_ERR("Error from p9_build_smp_adu_check_status");
            goto adu_reset_unlock;
        }

        // Loop through all chips, unlock ADUs
        FAPI_DBG("Releasing lock for all ADU units in drawer");

        for (n_iter = i_smp.nodes.begin();
             n_iter != i_smp.nodes.end();
             ++n_iter)
        {
            for (p_iter = n_iter->second.chips.begin();
                 p_iter != n_iter->second.chips.end();
                 ++p_iter)
            {
                // Release ADU lock
                l_lockPick = false;
                l_numAttempts = (i_op == SMP_ACTIVATE_PHASE1) ?
                                P9_BUILD_SMP_PHASE1_ADU_LOCK_ATTEMPTS :
                                P9_BUILD_SMP_PHASE2_ADU_LOCK_ATTEMPTS;
                FAPI_TRY(p9_adu_coherent_manage_lock(p_iter->second.chip->this_chip,
                                                     l_lockPick,
                                                     false, l_numAttempts),
                         "p9_adu_coherent_manage_lock() - Release returns an error, l_rc 0x%.8X",
                         (uint64_t)fapi2::current_err);
            }
        }

        FAPI_DBG("All ADU locks released");
        // No error for entire operation, ADU locks released.
        adu_is_dirty = false;

    adu_reset_unlock:

        // If error has occurred and any ADU is dirty,
        // attempt to reset all ADUs and free locks (propogate rc of original fail)
        if (l_rc && adu_is_dirty)
        {
            // Save original error
            fapi2::ReturnCode l_savedRc = l_rc;

            FAPI_INF("Attempting to reset/free lock on all ADUs");

            // loop through all chips, unlock ADUs
            for (n_iter = i_smp.nodes.begin();
                 n_iter != i_smp.nodes.end();
                 ++n_iter)
            {
                for (p_iter = n_iter->second.chips.begin();
                     p_iter != n_iter->second.chips.end();
                     ++p_iter)
                {
                    // Ignore l_rc when attempting to reset/unlock
                    l_rc = p9_build_smp_adu_set_switch_action(
                               p_iter->second.chip->this_chip,
                               false, false);
                    l_rc = p9_adu_coherent_utils_reset_adu(
                               p_iter->second.chip->this_chip);
                    l_rc = p9_adu_coherent_manage_lock(
                               p_iter->second.chip->this_chip,
                               false, // No lock pick
                               false, // Lock release
                               1);    // Attempt 1 time
                }
            }

            // Return original error
            fapi2::current_err = l_savedRc;
        }

    fapi_try_exit:

        FAPI_DBG("End");
        return fapi2::current_err;
    }

// NOTE: see comments above function prototype in header
    fapi2::ReturnCode p9_build_smp_switch_cd(
        p9_build_smp_chip& i_smp_chip,
        p9_build_smp_system& i_smp)
    {
        FAPI_DBG("Start");
        fapi2::ReturnCode l_rc;
        p9_ADU_oper_flag l_myAduFlag;

        // Lock flag
        bool adu_is_dirty = false;
        bool l_lockPick = false;
        uint8_t l_numAttempts = 1;
        uint64_t l_address = 0; // Address phase

        FAPI_DBG("Acquiring lock for ADU");

        // Acquire ADU lock
        // only required to obtain lock for this chip, as this function will
        // only be executed when fabric is configured as single chip island

        // Set pick lock & num of tries
        l_lockPick = P9_BUILD_SMP_PHASE1_ADU_PICK_LOCK;
        l_numAttempts = P9_BUILD_SMP_PHASE1_ADU_LOCK_ATTEMPTS;

        // Acquire ADU lock
        FAPI_TRY(p9_adu_coherent_manage_lock(
                     i_smp_chip.chip->this_chip,
                     l_lockPick,
                     true,           // Acquire lock
                     l_numAttempts),
                 "p9_adu_coherent_manage_lock() - Lock returns an error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // NOTE: lock is now held, if an operation fails from this point
        //       to the end of the procedure:
        //         o attempt to cleanup/release lock (so that procedure does
        //         not leave the ADU in a locked state)
        //         o return rc of original fail
        adu_is_dirty = true;

        // Reset ADU
        l_rc = p9_adu_coherent_utils_reset_adu(i_smp_chip.chip->this_chip);

        if (l_rc)
        {
            FAPI_ERR("Error from p9_adu_coherent_utils_reset_adu()");
            goto adu_reset_unlock;
        }

        // Condition for switch CD operation
        l_rc = p9_build_smp_adu_set_switch_action(i_smp_chip.chip->this_chip,
                false, // Switch A/B
                true); // Switch C/D

        if (l_rc)
        {
            FAPI_ERR("(Set): Error from p9_build_smp_adu_set_switch_action()");
            goto adu_reset_unlock;
        }


        FAPI_DBG("All ADU locks held");

        // Setup ADU flag to peform switch
        l_myAduFlag.setOperationType(p9_ADU_oper_flag::PMISC_OPER);

        char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];
        fapi2::toString(i_smp_chip.chip->this_chip, l_targetStr,
                        sizeof(l_targetStr));
        FAPI_INF("Issuing switch CD from %s", l_targetStr);

        // Setup and launch command
        l_rc = p9_adu_coherent_setup_adu(i_smp_chip.chip->this_chip,
                                         l_address,
                                         false,      // write
                                         l_myAduFlag.setFlag());

        if (l_rc)
        {
            FAPI_ERR("Error from p9_adu_coherent_setup_adu()");
            goto adu_reset_unlock;
        }

        // Check status
        l_rc = p9_build_smp_adu_check_status(i_smp_chip.chip->this_chip,
                                             i_smp, false);

        if (l_rc)
        {
            FAPI_ERR("Error from p9_build_smp_adu_check_status");
            goto adu_reset_unlock;
        }

        // Reset switch controls
        l_rc = p9_build_smp_adu_set_switch_action(i_smp_chip.chip->this_chip,
                false, false);

        if (l_rc)
        {
            FAPI_ERR("(Reset): Error from p9_build_smp_adu_set_switch_action()");
            goto adu_reset_unlock;
        }

        // Release ADU lock
        FAPI_DBG("Releasing lock for ADU");
        l_lockPick = false;
        l_numAttempts = P9_BUILD_SMP_PHASE1_ADU_LOCK_ATTEMPTS;
        FAPI_TRY(p9_adu_coherent_manage_lock(i_smp_chip.chip->this_chip,
                                             l_lockPick,
                                             false,        // Release
                                             l_numAttempts),
                 "p9_adu_coherent_manage_lock() - Release returns an error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        FAPI_DBG("All ADU locks released");
        // No error for entire operation, ADU locks released.
        adu_is_dirty = false;

    adu_reset_unlock:

        // If error has occurred and any ADU is dirty,
        // attempt to reset all ADUs and free locks (propogate rc of original fail)
        if (l_rc && adu_is_dirty)
        {
            FAPI_INF("Attempting to reset/free lock on ADU");

            // Save original error
            fapi2::ReturnCode l_savedRc = l_rc;

            // Ignore l_rc when attempting to reset/unlock
            l_rc = p9_build_smp_adu_set_switch_action(i_smp_chip.chip->this_chip,
                    false, false);
            l_rc = p9_adu_coherent_utils_reset_adu(i_smp_chip.chip->this_chip);
            l_rc = p9_adu_coherent_manage_lock(i_smp_chip.chip->this_chip,
                                               false, // No lock pick
                                               false, // Lock release
                                               1);    // Attempt 1 time
            // Return original error
            fapi2::current_err = l_savedRc;
        }

    fapi_try_exit:

        FAPI_DBG("End");
        return fapi2::current_err;
    }

} // extern "C"


