/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/ipl/sbe/p9_adu_coherent_utils.H $         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
//-----------------------------------------------------------------------------------
// *!
/// @file p9_adu_coherent_utils.H
/// @brief Common Code to support ADU get/putmem procedures (FAPI)
///
// *HWP HWP Owner: Christina Graves clgraves@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by:
// ---------------------------------------------------------------------------------
// *! ADDITIONAL COMMENTS :
// *!
// *!
//-----------------------------------------------------------------------------------

#ifndef _P9_ADU_COHERENT_UTILS_H_
#define _P9_ADU_COHERENT_UTILS_H_

//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------

#include <fapi2.H>
#include <p9_adu_constants.H>

extern"C"
{

//-----------------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------
// Function prototypes
//-----------------------------------------------------------------------------------

/// @brief check that the address is cacheline aligned and within the fabric real address range
/// @param[in] i_target  => P9 chip target
/// @param[in] i_address => starting address for ADU operation
/// @return FAPI_RC_SUCCESS if arguments are valid
    fapi2::ReturnCode p9_adu_coherent_utils_check_args(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const uint64_t i_address);

/// @brief ensure that fabric is initialized and stop control is not set
///           (by checkstop/mode switch), which if set would prohibit fabric
///           commands from being broadcasted
/// @param[in] i_target => P9 chip target
/// @return FAPI_RC_SUCCESS if fabric is not stopped
    fapi2::ReturnCode p9_adu_coherent_utils_check_fbc_state(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target
    );

/// @brief calculates the number of 8 byte granules that can be read/written before setup needs to be run again
/// @param[in] i_target  => P9 chip target
/// @param[in] i_address => starting address for ADU operation
/// @return number of 8 byte granules that can be read/written before setup needs to be run again
    fapi2::ReturnCode p9_adu_coherent_utils_get_num_granules(
        const uint64_t i_address,
        uint32_t& o_numGranules);

/// @brief does the setup for the ADU to set up the initial registers for a read/write
/// @param[in] i_target  => P9 chip target
/// @param[in] i_address => starting address for ADU operation
/// @param[in] i_rnw     => whether the operation is a read or write
/// @param[in] i_flags   => flags that contain information that the ADU needs to know to set up registers
/// @return FAPI_RC_SUCCESS if setting up the adu registers is a success
    fapi2::ReturnCode p9_adu_coherent_setup_adu(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const uint64_t i_address,
        const bool i_rnw,
        const uint32_t i_flags);

/// @brief does the write for the ADU
/// @param[in] i_target       => P9 chip target
/// @param[in] i_firstGranule => the first 8B granule that we are writing
/// @param[in] i_address      => address for this write
/// @param[in] i_flags        => flags that contain information that the ADU needs to know to set up registers
/// @param[in] i_write_data   => the data that is to be written to the ADU
/// @return FAPI_RC_SUCCESS if writing the ADU is a success
    fapi2::ReturnCode p9_adu_coherent_adu_write(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const bool i_firstGranule,
        const uint64_t i_address,
        const uint32_t i_flags,
        const uint8_t i_write_data[]);

/// @brief does the read for the ADU
/// @param[in] i_target       => P9 chip target
/// @param[in] i_firstGranule => the first 8B granule that we are reading
/// @param[in] i_address      => address for this read
/// @param[in] i_flags        => flags that contain information that the ADU needs to know to set up registers
/// @param[out] o_read_data   => the data that is read from the ADU
/// @return FAPI_RC_SUCCESS if reading the ADU is a success
    fapi2::ReturnCode p9_adu_coherent_adu_read(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const bool i_firstGranule,
        const uint64_t i_address,
        const uint32_t i_flags,
        uint8_t o_read_data[]);

/// @brief this does a reset for the ADU
/// @param[in] i_target => P9 chip target
/// @return FAPI_RC_SUCCESS if the reset is a success
    fapi2::ReturnCode p9_adu_coherent_utils_reset_adu(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

/// @brief this does any cleanup for the ADU after all reads/writes have been done
/// @param[in] i_target => P9 chip target
/// @return FAPI_RC_SUCCESS if cleaning up the ADU is a success
    fapi2::ReturnCode p9_adu_coherent_cleanup_adu(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

/// @brief this will remove the auto increment bit before the last iteration
/// @param[in] i_target => P9 chip target
/// @return FAPI_RC_SUCCESS if removing the auto inc bit is a success
    fapi2::ReturnCode p9_adu_coherent_clear_autoinc(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

/// @brief this will check the status of the pba
/// @param[in] i_target => P9 chip target
/// @return FAPI_RC_SUCCESS if the status check is a success
    fapi2::ReturnCode p9_adu_coherent_status_check(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const bool i_busy_bit_set_expected);

/// @brief this will acquire and release a lock as well as deal with any lock picking
/// @param[in] i_target       => P9 chip target
/// @param[in] i_lock_pick    => If the lock does not go through should we set a lock pick
/// @param[in] i_lock         => true if this is to lock the ADU false if this is to unlock the ADU
/// @param[in] i_num_attempts => number of times to try locking the ADU
    fapi2::ReturnCode p9_adu_coherent_manage_lock(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const bool i_lock_pick,
        const bool i_lock,
        const uint32_t i_num_attempts);

} // extern "C"

#endif //_P9_ADU_COHERENT_UTILS_H_
