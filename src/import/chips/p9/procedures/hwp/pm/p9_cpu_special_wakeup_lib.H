/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_cpu_special_wakeup_lib.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
///  @file          :     p9_cpu_special_wakeup_lib.H
///  @brief         :     Templated functions to perform special wakeups of
///                       core, EQ or EX.

// *HWP HW Owner    :    Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner    :    Prem S Jha <premjha2@in.ibm.com>
// *HWP Team        :    PM
// *HWP Level       :    2
// *HWP Consumed by :    OCC:FSP:HOST:CRO

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include <p9_cpu_special_wakeup.H>
#include <p9_quad_scom_addresses.H>
#include <p9_perv_scom_addresses.H>
#include <p9_perv_scom_addresses_fld.H>
#include <p9_misc_scom_addresses.H>

static const uint32_t NUM_CHIPLET_TYPES = 2;
static const uint32_t NUM_ENTITIES = 4;


/**
 *  @brief Addresses for each entity
 */

static const uint64_t SPCWKUP_ADDR[NUM_ENTITIES][NUM_CHIPLET_TYPES] =
{
    {C_PPM_SPWKUP_OTR, EQ_PPM_SPWKUP_OTR},
    {C_PPM_SPWKUP_FSP, EQ_PPM_SPWKUP_FSP},
    {C_PPM_SPWKUP_OCC, EQ_PPM_SPWKUP_OCC},
    {C_PPM_SPWKUP_HYP, EQ_PPM_SPWKUP_HYP}
};

static const uint64_t SPCWKUP_HIST_ADDR[NUM_ENTITIES][NUM_CHIPLET_TYPES] =
{
    {C_PPM_SSHOTR, EQ_PPM_SSHOTR},
    {C_PPM_SSHFSP, EQ_PPM_SSHFSP},
    {C_PPM_SSHOCC, EQ_PPM_SSHOCC},
    {C_PPM_SSHHYP, EQ_PPM_SSHHYP}
};

static const uint64_t SPCWKUP_NETCTRL0_ADDR[NUM_CHIPLET_TYPES] =
{
    C_NET_CTRL0, EQ_NET_CTRL0
};

static const uint64_t SPCWKUP_GPMMR_ADDR[NUM_CHIPLET_TYPES] =
{
    C_PPM_GPMMR_SCOM, EQ_PPM_GPMMR_SCOM
};

static const uint32_t SPECIAL_WAKE_UP_POLL_INTERVAL_NS  =  1000000;   //1ms
static const uint32_t SPECIAL_WAKEUP_TIMEOUT_NS         =  (100 * SPECIAL_WAKE_UP_POLL_INTERVAL_NS);     //100 ms
static const uint32_t SPWKUP_BIT            = 0;
static const uint32_t GPMMR_SPWKUP_DONE_BIT = 0;
static const uint32_t HIST_SPWKUP_DONE_BIT  = 1;
static const uint32_t SGPE_ACTIVE_BIT       = 8;
static const uint32_t CORES_PER_EX          = 2;

namespace p9specialWakeup
{
extern const char* SPWK_MSG_LIST[];
extern const char* PROC_SPCWKUP_ENTITY_NAMES[];

}


// Information to be used for an operation.  Populated based on the entity
struct ProcessingValues_t
{
    p9specialWakeup::PROC_SPCWKUP_ENTITY    entity;
    bool                   b_xstop_flag;
    bool                   b_ignore_xstop_flag;
    bool                   b_wakeup_on_entry_flag;
    bool                   b_ex_flag;
    uint32_t               num_addresses;
    uint64_t               spwkup_address[CORES_PER_EX];
    uint64_t               gpmmr_address[CORES_PER_EX];
    uint64_t               history_address[CORES_PER_EX];
    uint64_t               netctrl_address[CORES_PER_EX];
};

// -----------------------------------------------------------------------------
// Templated Functions
// -----------------------------------------------------------------------------

/// ----------------------------------------------------------------------------
///
/// Get the Chip Target from the input Target
///
/// @brief find the CHIP target given a K target
/// @param[in] the fapi2 target,
/// @return a CHIP target.
///
template< fapi2::TargetType K >
inline fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> get_chip_target( const fapi2::Target<K>& );

///
/// @brief find the CHIP target given a CORE target
/// @param[in] the fapi2 target,
/// @return a CHIP target.
///
template<>
inline fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> get_chip_target( const fapi2::Target<fapi2::TARGET_TYPE_CORE>&
        i_target )
{
    return i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
}

///
/// @brief find the CHIP target given a EQ target
/// @param[in] the fapi2 target,
/// @return a CHIP target.
///
template<>
inline fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> get_chip_target( const fapi2::Target<fapi2::TARGET_TYPE_EQ>&
        i_target )
{
    return i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
}

///
/// @brief find the CHIP target given a EX target
/// @param[in] the fapi2 target,
/// @return a CHIP target.
///
template<>
inline fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> get_chip_target( const fapi2::Target<fapi2::TARGET_TYPE_EX>&
        i_target )
{
    return i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
}

///
/// @brief find the CHIP target given a CHIP target
/// @param[in] the fapi2 target,
/// @return a CHIP target.
///
template<>
inline fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> get_chip_target( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&
        i_target )
{
    return i_target;
}

/// ----------------------------------------------------------------------------
///
/// @brief Set addresses based on the target type (Template)
///
template< fapi2::TargetType K >
fapi2::ReturnCode set_addresses(const fapi2::Target<K>& i_target,
                                ProcessingValues_t& i_structure,
                                const uint32_t i_entity );

///
/// @brief Set addresses for a core target type
///
template<>
fapi2::ReturnCode set_addresses(const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
                                ProcessingValues_t& i_structure,
                                const uint32_t i_entity );
///
/// @brief Set addresses for an EQ target type
///
template<>
fapi2::ReturnCode set_addresses(const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_target,
                                ProcessingValues_t& i_structure,
                                const uint32_t i_entity );
///
/// @brief Set addresses for an EX
///
template<>
fapi2::ReturnCode set_addresses(const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_target,
                                ProcessingValues_t& i_structure,
                                const uint32_t i_entity );

// -----------------------------------------------------------------------------
// Function Implementations
// -----------------------------------------------------------------------------

/// ----------------------------------------------------------------------------
///
/// @brief Setup based on entity
/// @param[in]   i_chipletTarget    fapi2 target
/// @param[in]   i_entity           Entity to perform special wakeup upon.
/// @param[in]   i_processing_info  Structure containing processing information
///
template <fapi2::TargetType K>
fapi2::ReturnCode spwkup_setup_entity(  const fapi2::Target<K>& i_chipletTarget,
                                        const p9specialWakeup::PROC_SPCWKUP_ENTITY i_entity,
                                        ProcessingValues_t& i_processing_info )
{
    FAPI_DBG(">> spwkup_setup_entity");

    uint8_t             l_attr_chip_unit_pos;
    fapi2::TargetType   l_chiplet_type = i_chipletTarget.getType();

    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_parentTarget;
    // Get the parent chip to deal with chip level accesses
    l_parentTarget = get_chip_target<K> (i_chipletTarget);

    i_processing_info.entity = i_entity;
    i_processing_info.b_ex_flag = ( l_chiplet_type == fapi2::TARGET_TYPE_EX ? true : false );
    // Initialize other control structure settings.
    i_processing_info.b_xstop_flag = false;
    i_processing_info.b_ignore_xstop_flag = false;
    i_processing_info.b_wakeup_on_entry_flag = false;

    FAPI_DBG("i_processing: flags "
             "entity = %d  "
             "b_xstop_flag = %d "
             "b_ignore_xstop_flag = %d "
             "b_wakeup_on_entry_flag = %d "
             "b_ex_flag = %d \n",
             i_processing_info.entity,
             i_processing_info.b_xstop_flag,
             i_processing_info.b_ignore_xstop_flag,
             i_processing_info.b_wakeup_on_entry_flag,
             i_processing_info.b_ex_flag);

    // Get the chiplet number
    FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS, i_chipletTarget, l_attr_chip_unit_pos),
             "fapiGetAttribute of ATTR_CHIP_UNIT_POS");

    FAPI_DBG("Chiplet number = %d of type %X", l_attr_chip_unit_pos, l_chiplet_type);

    // Steering the addresses to the target
    FAPI_TRY(set_addresses(i_chipletTarget, i_processing_info, i_entity));


fapi_try_exit:
    FAPI_INF("< spwkup_setup_entity" );
    return fapi2::current_err;
}

/// ----------------------------------------------------------------------------
///
/// @brief Check for checkstop and set flags
/// @param[in]   i_chipletTarget    fapi2 target
/// @param[in]   i_processing_info  Structure containing processing information
///
template <fapi2::TargetType K>
fapi2::ReturnCode spwkup_check_xstop(   const fapi2::Target<K>& i_chipletTarget,
                                        ProcessingValues_t& i_processing_info )
{
    FAPI_DBG(">> spwkup_check_xstop");

    fapi2::buffer<uint64_t> l_intr_type;

    // Get the parent chip to deal with chip level accesses
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_parentTarget;
    l_parentTarget = get_chip_target<K> (i_chipletTarget);

    uint8_t l_attr_ignore_xstop = 0;
    FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_PM_SPWUP_IGNORE_XSTOP_FLAG,
                            l_parentTarget,
                            l_attr_ignore_xstop),
             "fapiGetAttribute of ATTR_PM_SPWUP_IGNORE_XSTOP_FLAG failed");

    FAPI_INF("Ignore XSTOP:  %s", (l_attr_ignore_xstop ? "YES" : "NO"));
    i_processing_info.b_ignore_xstop_flag = l_attr_ignore_xstop ? true : false;

    // Read system checkstop indicator
    FAPI_TRY(fapi2::getScom(l_parentTarget,
                            PERV_PIB_INTERRUPT_TYPE_REG,
                            l_intr_type),
             "GetScom of Interrupt Type failed");

    if(l_intr_type.getBit<PERV_INTERRUPT_TYPE_REG_CHECKSTOP>())
    {
        FAPI_INF( "Checkstop present" );
        i_processing_info.b_xstop_flag = true;
    }

    // Error out if system is checkstopped and not told to ignore it
//     FAPI_ASSERT((!l_attr_ignore_xstop && i_processing_info.b_xstop_flag),
//                   fapi2::SPWKUP_CHKSTOP()
//                  .geIGNOREXSTOP(l_attr_ignore_xstop)
//                  .set_TARGET(l_parentTarget),
//         "This chip is xstopped and the attribute ATTR_PM_SPWUP_IGNORE_XSTOP_FLAG is NOT set" );

fapi_try_exit:
    FAPI_INF("<< spwkup_check_xstop" );
    return fapi2::current_err;
}

/// ----------------------------------------------------------------------------
///
/// @brief Assert special wake-up and poll for done
/// @param[in]   i_chipletTarget    fapi2 target
/// @param[in]   i_processing_info  Structure containing processing information
/// @param[in]   i_msgId              String to prepend to trace outputs
///
template <fapi2::TargetType K>
fapi2::ReturnCode spwkup_assert(const fapi2::Target<K>& i_chipletTarget,
                                ProcessingValues_t& i_processing_info,
                                p9specialWakeup::SpecialWakeUpMsg i_msgId )
{

    fapi2::buffer<uint64_t> l_stop_hist_state[2];
    fapi2::buffer<uint64_t> l_gpmmr[2];
    fapi2::buffer<uint64_t> l_netctrl[2];
    fapi2::buffer<uint64_t> l_spwkup[2];

    uint32_t                l_pollcount = 0;
    bool                    b_poll_during_xstop_flag;

    // Get the parent chip to deal with chip level accesses
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_parentTarget;
    l_parentTarget = get_chip_target<K> (i_chipletTarget);

    uint32_t l_special_wakeup_poll_interval_ns = SPECIAL_WAKE_UP_POLL_INTERVAL_NS;
    /// Calculate the maximum number of polls until a timeout is thrown
    uint32_t l_special_wakeup_max_polls =  (SPECIAL_WAKEUP_TIMEOUT_NS / l_special_wakeup_poll_interval_ns);

    // This is done in two phases:  1) assert the special wake-ups to all elements;
    //                              2) poll for done from all elements
    // This allows for parallism (polling for one while the other is in the process of waking up
    for (uint32_t i = 0; i < i_processing_info.num_addresses; ++i)
    {
        FAPI_TRY(fapi2::getScom(l_parentTarget, i_processing_info.history_address[i], l_stop_hist_state[i]),
                 "GetScom of STOP History 0x%08llX failed", i_processing_info.history_address[i]);

        FAPI_TRY(fapi2::getScom(l_parentTarget, i_processing_info.spwkup_address[i], l_spwkup[i]),
                 "GetScom of Special Wake-up failed");

        FAPI_TRY(fapi2::getScom(l_parentTarget, i_processing_info.gpmmr_address[i], l_gpmmr[i]),
                 "GetScom of GPMMR 0x%08llX failed", i_processing_info.gpmmr_address[i]);

        // Make a note of spwu is already asserted.  This flag is useful
        // for debug
        i_processing_info.b_wakeup_on_entry_flag = l_spwkup[i].getBit<SPWKUP_BIT>();

        l_spwkup[i].flush<0>().setBit<SPWKUP_BIT>();
        FAPI_TRY(fapi2::putScom(l_parentTarget, i_processing_info.spwkup_address[i], l_spwkup[i]),
                 "PutScom of Special Wake-up failed");

    } // num_addresses

    for (uint32_t i = 0; i < i_processing_info.num_addresses; ++i)
    {
        // Determine whether to poll for completion of Special wake-up.
        // Running and STOP <= 2 - can always be polled as these are not
        //      dependent on an xstop condition.
        // STOP > 2 - poll only if not in an xstop condition


        // @todo  RTC 136801 Check the STOP History Register (and other hardware
        //           and Hcode state) to determine if polling during xstop
        //          is valid.  Refer to ex_determine_inst_pm_state in P8.
        // Don't poll if Xstop for now.
        b_poll_during_xstop_flag = false;

        // Poll for completion if conditions are right
        if ( (!i_processing_info.b_xstop_flag) || ( i_processing_info.b_xstop_flag && b_poll_during_xstop_flag))
        {
            // poll for the set completion
            l_pollcount = 0;
            l_gpmmr[i].flush<0>();

            while ( !l_gpmmr[i].getBit<GPMMR_SPWKUP_DONE_BIT>() && l_pollcount < l_special_wakeup_max_polls)
            {
                FAPI_TRY(fapi2::getScom(l_parentTarget, i_processing_info.gpmmr_address[i],  l_gpmmr[i]),
                         "GetScom of GPMMR failed");

                FAPI_DBG("  Loop get for Special Wake-up Done => 0x%016llx", l_gpmmr[i]);

                fapi2::delay(l_special_wakeup_poll_interval_ns, 1000000);
                ++l_pollcount;
            }

            if (l_gpmmr[i].getBit<GPMMR_SPWKUP_DONE_BIT>())
            {
                FAPI_INF("Special wakeup done is set.  SUCCESS!  ... ");
            }
            else
            {
                FAPI_TRY(fapi2::getScom(l_parentTarget, i_processing_info.netctrl_address[i], l_netctrl[i]),
                         "GetScom of Network Control register failed");

                // The following are put in the procedure (vs the XML) to
                // capture for Cronus debug

                FAPI_TRY(fapi2::getScom(l_parentTarget, i_processing_info.spwkup_address[i], l_spwkup[i]),
                         "GetScom of Special Wake-up register failed");

                FAPI_DBG("  After set of SPWKUP_REG (0x%08llx) => 0x%016llx",
                         i_processing_info.spwkup_address[i], l_spwkup[i]);

                //  We really can't leave a latent spwu bit enabled. Even
                /// though we gave it a very long time to complete, we can't
                //  take the chance that it fires later. So, lets clear it now.
                //  This will do no harm since the presumption at this point,
                //  anyway, is that it failed and so therefore it should be cleared
                //  too.
                //
                //  Note, we only want to do this for count=0 and if
                //  procesing_info.b_wakeup_on_entry_flag==false as this would be an indication that we,
                //  right now, just asserted the spwu from a deasserted state.
                //  Therefore, we can safely also deassert it.

                if (!i_processing_info.b_wakeup_on_entry_flag)
                {
                    FAPI_TRY(spwkup_deassert(i_chipletTarget, i_processing_info, p9specialWakeup::SPWK_MSG_CLEAN_UP_DEASSERT));
                }

                FAPI_ASSERT(false,
                            fapi2::SPCWKUP_TIMEOUT()
                            .set_POLLCOUNT(l_pollcount)
                            .set_NETCTRL(l_netctrl[i])
                            .set_SP_WKUP_REG_ADDRESS(i_processing_info.spwkup_address[i])
                            .set_SP_WKUP_REG_VALUE(l_spwkup[i])
                            .set_SP_WKUP_REG_ADDRESS(i_processing_info.history_address[i])
                            .set_SP_WKUP_REG_VALUE(l_stop_hist_state[i])
                            .set_ENTITY(i_processing_info.entity),
                            "Timed out in setting the CPU in Special wakeup");
            }
        }  // Done checking
        else
        {
            FAPI_ASSERT(false,
                        fapi2::SPCWKUP_STOP_IN_CHKSTOP()
                        .set_CHIPLET_TARGET(i_chipletTarget),
                        "Special_wakeup requested to an chiplet in a STOP state "
                        "with the system checkstopped that cannot succeed");
        }
    } // num_addresses

fapi_try_exit:
    FAPI_INF("< spwkup_check_xstop" );
    return fapi2::current_err;
}

/// ----------------------------------------------------------------------------
///
/// @brief Templated helper to deassert special wake-up
/// @param[in]   i_chipletTarget    fapi2 target
/// @param[in]   i_processing_info  Structure containing processing information
/// @param[in]   i_msgId              String to prepend to trace outputs
///
template <fapi2::TargetType K>
fapi2::ReturnCode _spwkup_deassert( const fapi2::Target<K>& i_chipletTarget,
                                    uint64_t i_address,
                                    p9specialWakeup::SpecialWakeUpMsg i_msgId)
{
    FAPI_INF("> spwkup_deassert" );

    fapi2::buffer<uint64_t> l_data64 = 0;
    // Get the parent chip to deal with chip level accesses
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_parentTarget;
    l_parentTarget = get_chip_target<K> (i_chipletTarget);

    FAPI_TRY(fapi2::putScom(l_parentTarget, i_address, l_data64),
             "PutScom of Special Wake-up register failed");
    FAPI_DBG("  %s: After clear putscom of SPWKUP_REG (0x%08llx) => 0x%016llx",
             *(p9specialWakeup::SPWK_MSG_LIST[i_msgId]),
             i_address,
             l_data64);

    // This puts an inherent delay in the propagation of the reset transition.
    FAPI_TRY(fapi2::getScom(l_parentTarget, i_address, l_data64),
             "GetScom of Special Wake-up failed");
    FAPI_DBG("  %s: After read (delay) of SPWKUP_REG (0x%08llx) 0x%016llx",
             *(p9specialWakeup::SPWK_MSG_LIST[i_msgId]),
             i_address,
             l_data64);

fapi_try_exit:
    FAPI_INF("< spwkup_deassert" );
    return fapi2::current_err;
}


/// @brief Deassert special wake-up template
/// @param[in]   i_chipletTarget    fapi2 target
/// @param[in]   i_processing_info  Structure containing processing information
/// @param[in]   i_msgId             Id of the string to prepend to trace outputs
///
template <fapi2::TargetType K>
fapi2::ReturnCode spwkup_deassert(  const fapi2::Target<K>& i_chipletTarget,
                                    const ProcessingValues_t i_processing_info,
                                    p9specialWakeup::SpecialWakeUpMsg i_msgId);



///
/// @brief Deassert special wake-up - EQ
///
fapi2::ReturnCode spwkup_deassert(  const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_chipletTarget,
                                    const ProcessingValues_t i_processing_info,
                                    p9specialWakeup::SpecialWakeUpMsg i_msgId);

///
/// @brief Deassert special wake-up - EX
///
fapi2::ReturnCode spwkup_deassert(  const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_chipletTarget,
                                    const ProcessingValues_t i_processing_info,
                                    p9specialWakeup::SpecialWakeUpMsg i_msgId);

///
/// @brief Deassert special wake-up - Core
///
fapi2::ReturnCode spwkup_deassert(  const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_chipletTarget,
                                    const ProcessingValues_t i_processing_info,
                                    p9specialWakeup::SpecialWakeUpMsg i_msgId);
/// ----------------------------------------------------------------------------
///
/// @brief       Templated helper to assert/deassert the entity bit as targeted.
/// @param[in]   i_chipletTarget    fapi2 target
/// @param[in]   i_operation        special wakeup operations to be used.
/// @param[in]   i_entity           entity to perform special wake-up upon
///
template <fapi2::TargetType K>
fapi2::ReturnCode _special_wakeup(const fapi2::Target<K>& i_chipletTarget,
                                  const p9specialWakeup::PROC_SPCWKUP_OPS i_operation,
                                  const p9specialWakeup::PROC_SPCWKUP_ENTITY i_entity )
{
    FAPI_DBG(">> _special_wakeup");

    fapi2::ReturnCode       l_rc;
    fapi2::buffer<uint64_t> occFlagReg;
    ProcessingValues_t     processing_info;

    char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::toString(i_chipletTarget, l_targetStr, fapi2::MAX_ECMD_STRING_LEN);

    // Get the parent chip to deal with chip level accesses
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_parentTarget;
    l_parentTarget = get_chip_target<K> (i_chipletTarget);

    do
    {
        // Read system checkstop indicator
        FAPI_TRY(fapi2::getScom(l_parentTarget,
                                PU_OCB_OCI_OCCFLG_SCOM,
                                occFlagReg),
                 "GetScom of OCC Flag Register Failed");

        if( !occFlagReg.getBit<SGPE_ACTIVE_BIT>() )
        {
            FAPI_INF("SGPE not active. STOP Sub-System not ready for special wakeup" );
            break;
        }

        switch (i_operation)
        {

            case p9specialWakeup::SPCWKUP_ENABLE:
                // Select the addresses to use based on the entity
                FAPI_TRY(spwkup_setup_entity(i_chipletTarget, i_entity, processing_info),
                         "Error:  spwkup_setup_entity failed");

                // Determine if xstop checking should be ignored based on a caller
                // set attribute.
                //
                // This is used during MPIPL clean-up to a core to clear FIRs that
                // will eventually clear the xstop condition.  However, to do so
                // needs the xstop check to not keep the special wake-up operation
                // from happening.
                FAPI_TRY(spwkup_check_xstop(i_chipletTarget, processing_info));

                // Proceed
                FAPI_INF("Setting Special Wake-up  ...") ;

                FAPI_TRY(spwkup_assert(i_chipletTarget, processing_info, p9specialWakeup::SPWK_MSG_ASSERT ));

                break;

            case p9specialWakeup::SPCWKUP_DISABLE:
                FAPI_INF("Clearing Special Wake-up...");

                // Select the addresses to use based on the entity
                FAPI_TRY(spwkup_setup_entity(i_chipletTarget, i_entity, processing_info),
                         "Error:  spwkup_setup_entity failed");

                FAPI_TRY(spwkup_deassert(i_chipletTarget, processing_info, p9specialWakeup::SPWK_MSG_DEASSERT ));

                break;

            default:
                ;
        }

    }
    while(0);

fapi_try_exit:
    FAPI_INF("< p9_cpu_special_wakeup" );
    return fapi2::current_err;
}
