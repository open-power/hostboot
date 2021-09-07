/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_adu_utils.H $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file p10_adu_utils.H
/// @brief Alter/Display library functions to support adu procedures
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: SBE
///

#ifndef _P10_ADU_UTILS_H_
#define _P10_ADU_UTILS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <p10_adu_constants.H>

/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_adu_utils_reset_adu_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& );

typedef fapi2::ReturnCode (*p10_adu_utils_cleanup_adu_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& );

extern"C"
{

//------------------------------------------------------------------------------
// Classes
//------------------------------------------------------------------------------

///
/// @brief Manage adu operation flags that are used to program the
///        Alter/Display Command register, PU_ALTD_CMD_REG (scom 0x90001)
///
    class adu_operationFlag
    {
        public:

            // Type of ADU operations
            enum OperationType_t
            {
                CACHE_INHIBIT     = 0,               // cache-inhibited 1, 2, 4, or 8 byte read/write
                DMA_PARTIAL       = 1,               // partial cache line direct memory access; always 8 byte read/write
                PB_DIS_OPER       = 2,               // pbop.disable_all
                PMISC_OPER        = 3,               // pmisc switch
                PB_INIT_OPER      = 4,               // pbop.enable_all
                PRE_SWITCH_CD     = 5,               // do not issue PB command, pre-set for switch CD operation
                PRE_SWITCH_AB     = 6,               // do not issue PB command, pre-set for switch AB operation
                POST_SWITCH       = 7,               // do not issue PB command, clear switch CD/AB flags
                ILLEGAL_OPER_TYPE = POST_SWITCH + 1, // Illegal operation type, must always be the last entry.
            };

            // Transaction size; only checked if not DMA
            enum Transaction_size_t
            {
                TSIZE_1 = 1,
                TSIZE_2 = 2,
                TSIZE_4 = 4,
                TSIZE_8 = 8
            };

            // Constructor
            inline adu_operationFlag():
                iv_operType(CACHE_INHIBIT),
                iv_autoInc(false),
                iv_lockPick(false),
                iv_numLockAttempts(1),
                iv_cleanUp(true),
                iv_fastMode(false),
                iv_itag(false),
                iv_ecc(false),
                iv_eccItagOverwrite(false),
                iv_transSize(TSIZE_1),
                iv_flagInvalid(false)
            {
            }

            /// @brief Assemble the 32-bit ADU flag based on current info contained in this class
            ///        See flag bit definitions in p10_adu_constants.H
            inline uint32_t setFlag();

            /// @brief Update the class instance variables with info embedded in the passed in flag value
            ///        See flag bit definitions in p10_adu_constants.H
            inline void getFlag(uint32_t i_flag);

            /// @brief Determine if adu operation type is address only or will require data transfer
            inline bool isAddressOnly(void)
            {
                return ((iv_operType == PB_DIS_OPER) ||
                        (iv_operType == PMISC_OPER)  ||
                        (iv_operType == PB_INIT_OPER));
            }

            /// @brief Get the adu operation type setting
            /// @return iv_operType
            inline OperationType_t getOperationType(void) const
            {
                return iv_operType;
            }
            /// @brief Get the auto increment setting, for dma ops only
            /// @return iv_autoInc
            inline bool getAutoIncrement(void) const
            {
                return iv_autoInc;
            }
            /// @brief Get the adu lock control setting
            /// @return iv_lockPick
            inline bool getLockControl(void) const
            {
                return iv_lockPick;
            }
            /// @brief Get number of lock attempts setting
            /// @return iv_numLockAttempts
            inline uint8_t getNumLockAttempts(void) const
            {
                return iv_numLockAttempts;
            }
            /// @brief Get the cleanup for failed operation setting
            /// @return iv_cleanUp
            inline bool getOperFailCleanup(void) const
            {
                return iv_cleanUp;
            }
            /// @brief Get the fast mode setting
            /// @return iv_fastMode
            inline bool getFastMode(void) const
            {
                return iv_fastMode;
            }
            /// @brief Get the itag collection mode
            /// @return iv_itag
            inline bool getItagMode(void) const
            {
                return iv_itag;
            }
            /// @brief Get the ecc mode setting
            /// @return iv_ecc
            inline bool getEccMode(void) const
            {
                return iv_ecc;
            }
            /// @brief Get the overwrite ecc/itag data mode
            /// @return iv_eccItagOverwrite
            inline bool getEccItagOverrideMode(void) const
            {
                return iv_eccItagOverwrite;
            }
            /// @brief Get the transaction size
            /// @return iv_transSize
            inline Transaction_size_t getTransactionSize(void) const
            {
                return iv_transSize;
            }

            /// @brief Set the adu operation type
            /// @param[in] i_type   Adu operation type
            /// @return void
            inline void setOperationType(const OperationType_t i_type)
            {
                iv_operType = i_type;

                if (iv_operType >= ILLEGAL_OPER_TYPE)
                {
                    FAPI_ERR("Invalid Operation type (%d)", iv_operType);
                    setFlagInvalid();
                }

                return;
            }
            /// @brief Set the auto increment option, for dma ops only
            /// @param[in] i_value  True: Enable auto increment
            ///                     False: Disable auto increment
            /// @return void
            inline void setAutoIncrement(bool i_value)
            {
                iv_autoInc = i_value;
                return;
            }
            /// @brief Set the auto lock control option
            /// @param[in] i_value  True: Attempt to lock adu before operation
            ///                     False: No lock attempt
            /// @return void
            inline void setLockControl(bool i_value)
            {
                iv_lockPick = i_value;
                return;
            }
            /// @brief Set number of lock attempts
            /// @param[in] i_value  Number of lock attempts to try
            /// @return void
            inline void setNumLockAttempts(uint8_t i_value)
            {
                iv_numLockAttempts = i_value;
                return;
            }
            /// @brief Set cleanup if operation fails option
            /// @param[in] i_value  True: Clean up and release lock if op fails
            ///                     False: Leave adu in fail state
            /// @return void
            inline void setOperFailCleanup(bool i_value)
            {
                iv_cleanUp = i_value;
                return;
            }
            /// @brief Set the fast read/write mode
            ///        For fast read/write mode, skip status checking
            ///        Otherwise, do status check after every read/write
            /// @param[in] i_value  True: Enable fast read/write mode
            ///                     False: Disable fast read/write mode
            /// @return void
            inline void setFastMode(bool i_value)
            {
                iv_fastMode = i_value;
                return;
            }
            /// @brief Set the itag collection mode
            ///        Collect/set itag with each 8B read/write
            ///        For a write only set if itag data should be 1
            /// @param[in] i_value  True: Collect itag
            ///                     False: Do not collect itag
            /// @return void
            inline void setItagMode(bool i_value)
            {
                iv_itag = i_value;
                return;
            }
            /// @brief Set the ecc mode option
            /// @param[in] i_value  True: Collect ecc
            ///                     False: Do not collect ecc
            /// @return void
            inline void setEccMode(bool i_value)
            {
                iv_ecc = i_value;
                return;
            }
            /// @brief Set the overwrite ecc/itag data mode
            /// @param[in] i_value  True: Overwrite ecc
            ///                     False: Do not overwrite ecc
            /// @return void
            inline void setEccItagOverrideMode(bool i_value)
            {
                iv_eccItagOverwrite = i_value;
                return;
            }
            /// @brief Set the transaction size
            /// @param[in] i_value  Transaction size
            /// @return void
            inline void setTransactionSize(Transaction_size_t i_value)
            {
                iv_transSize = i_value;

                if ( (iv_transSize != TSIZE_1) &&
                     (iv_transSize != TSIZE_2) &&
                     (iv_transSize != TSIZE_4) &&
                     (iv_transSize != TSIZE_8) )
                {
                    FAPI_ERR("Invalid TSIZE (%d)",  iv_transSize);
                    setFlagInvalid();
                }

                return;
            }

            /// @brief Return flag valid status
            /// @return true if flag is valid
            inline bool isFlagValid() const
            {
                return (!iv_flagInvalid);
            }

        private:

            /// @brief Set the flag invalid bit
            /// @return void
            inline void setFlagInvalid()
            {
                iv_flagInvalid = true;
                return;
            }

            // Class variables
            OperationType_t iv_operType;     // Operation type
            bool iv_autoInc;                 // Auto increment
            bool iv_lockPick;                // Lock ADU before operation
            uint8_t iv_numLockAttempts;      // Number of lock attempts
            bool iv_cleanUp;                 // Cleanup ADU errors after operation
            bool iv_fastMode;                // Fast ADU read/write mode
            bool iv_itag;                    // Itag mode
            bool iv_ecc;                     // ECC mode
            bool iv_eccItagOverwrite;        // ECC/ITAG overwrite mode
            Transaction_size_t iv_transSize; // Transaction size
            bool iv_flagInvalid;             // Invalid flag
    };

    ///
    /// See doxygen in class definition
    ///
    uint32_t adu_operationFlag::setFlag()
    {
        uint32_t l_aduFlag = 0;

        // Operation type
        l_aduFlag |= (iv_operType << FLAG_ADU_TTYPE_SHIFT);

        // Auto increment
        if (iv_autoInc == true)
        {
            l_aduFlag |= FLAG_AUTOINC;
        }

        // Lock pick
        if (iv_lockPick == true)
        {
            l_aduFlag |= FLAG_LOCK_PICK;
        }

        // Lock attempts
        l_aduFlag |= (iv_numLockAttempts << FLAG_LOCK_TRIES_SHIFT);

        // Operation fail cleanup
        if (iv_cleanUp == false)
        {
            l_aduFlag |= FLAG_LEAVE_DIRTY;
        }

        // Fast mode
        if (iv_fastMode == true)
        {
            l_aduFlag |= FLAG_ADU_FASTMODE;
        }

        // Itag
        if (iv_itag == true)
        {
            l_aduFlag |= FLAG_ITAG;
        }

        // ECC
        if (iv_ecc == true)
        {
            l_aduFlag |= FLAG_ECC;
        }

        // Overwrite ECC
        if (iv_eccItagOverwrite == true)
        {
            l_aduFlag |= FLAG_OVERWRITE_ECC;
        }

        // Transaction size
        switch(iv_transSize)
        {
            case TSIZE_1:
                l_aduFlag |= FLAG_SIZE_TSIZE_1;
                break;

            case TSIZE_2:
                l_aduFlag |= FLAG_SIZE_TSIZE_2;
                break;

            case TSIZE_4:
                l_aduFlag |= FLAG_SIZE_TSIZE_4;
                break;

            case TSIZE_8:
                l_aduFlag |= FLAG_SIZE_TSIZE_8;
                break;

            default:
                FAPI_ERR("Invalid transaction size: iv_transSize %d",  iv_transSize);
                l_aduFlag |= FLAG_ADU_INVALID_BIT;
                break;
        }

        // Set flag validity
        if (iv_flagInvalid == true)
        {
            l_aduFlag |= FLAG_ADU_INVALID_BIT;
        }

        // Debug trace
        FAPI_DBG("adu_operationFlag::setFlag() // Flag value: 0x%.8X iv_operType 0x%.8X iv_TransSize 0x%.8X", l_aduFlag,
                 iv_operType, iv_transSize);

        if (iv_autoInc)
        {
            FAPI_DBG("    iv_autoInc 0x%.8X", iv_autoInc);
        }

        if (iv_lockPick)
        {
            FAPI_DBG("    iv_lockPick 0x%.8X", iv_lockPick);
        }

        if (iv_numLockAttempts)
        {
            FAPI_DBG("    iv_numLockAttempts 0x%.8X", iv_numLockAttempts);
        }

        if (iv_cleanUp)
        {
            FAPI_DBG("    iv_cleanUp 0x%.8X", iv_cleanUp);
        }

        if (iv_fastMode)
        {
            FAPI_DBG("    iv_fastMode 0x%.8X", iv_fastMode);
        }

        if (iv_eccItagOverwrite)
        {
            FAPI_DBG("    iv_itag 0x%.8X", iv_itag);
            FAPI_DBG("    iv_ecc 0x%.8X", iv_ecc);
            FAPI_DBG("    iv_eccItagOverwrite 0x%.8X", iv_eccItagOverwrite);
        }

        if (iv_flagInvalid)
        {
            FAPI_DBG("    iv_flagInvalid 0x%.8X", iv_flagInvalid);
        }

        return l_aduFlag;
    }

    ///
    /// See doxygen in class definition
    ///
    void adu_operationFlag::getFlag(const uint32_t i_flag)
    {
        // Operation type
        iv_operType = static_cast<OperationType_t>((i_flag & FLAG_ADU_TTYPE) >> FLAG_ADU_TTYPE_SHIFT);

        iv_autoInc = (i_flag & FLAG_AUTOINC);    // Auto increment
        iv_lockPick = (i_flag & FLAG_LOCK_PICK); // Lock pick

        // Lock attempts
        iv_numLockAttempts = ((i_flag & FLAG_LOCK_TRIES) >> FLAG_LOCK_TRIES_SHIFT);

        iv_cleanUp = (~i_flag & FLAG_LEAVE_DIRTY);           // Operation fail cleanup
        iv_fastMode = (i_flag & FLAG_ADU_FASTMODE);          // Fast mode
        iv_itag = (i_flag & FLAG_ITAG);                      // Itag
        iv_ecc = (i_flag & FLAG_ECC);                        // ECC
        iv_eccItagOverwrite = (i_flag & FLAG_OVERWRITE_ECC); // Overwrite ECC

        // Transaction size
        switch(i_flag & FLAG_SIZE)
        {
            case FLAG_SIZE_TSIZE_1:
                iv_transSize = TSIZE_1;
                break;

            case FLAG_SIZE_TSIZE_2:
                iv_transSize = TSIZE_2;
                break;

            case FLAG_SIZE_TSIZE_4:
                iv_transSize = TSIZE_4;
                break;

            case FLAG_SIZE_TSIZE_8:
                iv_transSize = TSIZE_8;
                break;

            default:
                FAPI_ERR("Invalid transaction size: iv_transSize %d",  iv_transSize);
                break;
        }

        // Flag validity
        iv_flagInvalid = (i_flag & FLAG_ADU_INVALID_BIT);

        // Debug trace
        FAPI_DBG("adu_operationFlag::getFlag() // Flag value: 0x%.8X iv_operType 0x%.8X iv_TransSize 0x%.8X", i_flag,
                 iv_operType, iv_transSize);

        if (iv_autoInc)
        {
            FAPI_DBG("    iv_autoInc 0x%.8X", iv_autoInc);
        }

        if (iv_lockPick)
        {
            FAPI_DBG("    iv_lockPick 0x%.8X", iv_lockPick);
        }

        if (iv_numLockAttempts)
        {
            FAPI_DBG("    iv_numLockAttempts 0x%.8X", iv_numLockAttempts);
        }

        if (iv_cleanUp)
        {
            FAPI_DBG("    iv_cleanUp 0x%.8X", iv_cleanUp);
        }

        if (iv_fastMode)
        {
            FAPI_DBG("    iv_fastMode 0x%.8X", iv_fastMode);
        }

        if (iv_eccItagOverwrite)
        {
            FAPI_DBG("    iv_itag 0x%.8X", iv_itag);
            FAPI_DBG("    iv_ecc 0x%.8X", iv_ecc);
            FAPI_DBG("    iv_eccItagOverwrite 0x%.8X", iv_eccItagOverwrite);
        }

        if (iv_flagInvalid)
        {
            FAPI_DBG("    iv_flagInvalid 0x%.8X", iv_flagInvalid);
        }

        return;
    }

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

/// @brief Validate input arguments/flags
/// @param[in] i_target         Reference to processor chip target
/// @param[in] i_address        Starting address for ADU operation
/// @param[in] i_flags          Input flag request
/// @param[in] o_flags          Structure representing ADU operation parameters
/// @return FAPI_RC_SUCCESS if arguments are valid
    fapi2::ReturnCode p10_adu_utils_check_args(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const uint64_t i_address,
        const uint32_t i_flags,
        adu_operationFlag& o_flags);

/// @brief Ensures that fabric is initialized and stop control is not set (by checkstop/mode switch),
///        which if set would prohibit fabric commands from being broadcasted
/// @param[in] i_target         Reference to processor target chip
/// @return FAPI_RC_SUCCESS if fabric is not stopped
    fapi2::ReturnCode p10_adu_utils_check_fbc_state(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

/// @brief Calculates the number of 8 byte granules that can be read/written before setup needs to be run again
/// @param[in] i_target         Reference to processor chip target
/// @param[in] i_address        Starting address for ADU operation
/// @return Number of 8 byte granules that can be read/written before setup needs to be run again
    fapi2::ReturnCode p10_adu_utils_get_num_granules(
        const uint64_t i_address,
        uint32_t& o_numGranules);

/// @brief Does the setup to enable pre-quiesce and post-init delays around an ADU command
/// @param[in] i_target         Reference to processor chip target
/// @return FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode p10_adu_utils_set_quiesce_init(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

/// @brief Sets action which will occur on fabric pmisc switch command
/// @param[in] i_target         Reference to processor chip target
/// @param[in] i_switch_ab      Perform switch AB operation if true
/// @param[in] i_switch_cd      Perform switch CD operation if true
/// @return FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode p10_adu_utils_set_switch_action(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const bool i_switch_ab,
        const bool i_switch_cd);

/// @brief Sets up the initial registers for an ADU operation
/// @param[in] i_target         Reference to processor chip target
/// @param[in] i_address        Starting address for ADU operation
/// @param[in] i_rnw            Whether the operation is a read or write
/// @param[in] i_flags          Structure representing ADU operation parameters
/// @return FAPI_RC_SUCCESS if setting up the adu registers is a success
    fapi2::ReturnCode p10_adu_utils_setup_adu(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const uint64_t i_address,
        const bool i_rnw,
        const adu_operationFlag& i_flags);

/// @brief Starts the operation that is set up in the adu command register
/// @param[in] i_target         Reference to processor chip target
/// @return FAPI_RC_SUCCESS if setting up the adu registers is a success
    fapi2::ReturnCode p10_adu_utils_start_op(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

/// @brief Uses the ADU to do a coherent write operation
/// @param[in] i_target         Reference to processor chip target
/// @param[in] i_firstGranule   The first 8B granule that we are writing?
/// @param[in] i_lastGranule    The last 8B granule that we are writing?
/// @param[in] i_address        Address for this write
/// @param[in] i_flags          Structure representing ADU operation parameters
/// @param[in] i_write_data     The data that is to be written to the ADU
/// @return FAPI_RC_SUCCESS if writing the ADU is a success
    fapi2::ReturnCode p10_adu_utils_adu_write(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const bool i_firstGranule,
        const bool i_lastGranule,
        const uint64_t i_address,
        const adu_operationFlag& i_flags,
        const uint8_t i_write_data[]);

/// @brief Uses the ADU to do a coherent read operation
/// @param[in] i_target         Reference to processor chip target
/// @param[in] i_firstGranule   The first 8B granule that we are reading?
/// @param[in] i_lastGranule    The last 8B granule that we are reading?
/// @param[in] i_address        address for this read
/// @param[in] i_flags          Structure representing ADU operation parameters
/// @param[out] o_read_data     the data that is read from the ADU
/// @return FAPI_RC_SUCCESS if reading the ADU is a success
    fapi2::ReturnCode p10_adu_utils_adu_read(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const bool i_firstGranule,
        const bool i_lastGranule,
        const uint64_t i_address,
        const adu_operationFlag& i_flags,
        uint8_t o_read_data[]);

/// @brief Resets ADU state machines and status registers
/// @param[in] i_target         Reference to processor chip target
/// @return FAPI_RC_SUCCESS if the reset is a success
    fapi2::ReturnCode p10_adu_utils_reset_adu(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

/// @brief Does any cleanup for the ADU after all operations have been done
/// @param[in] i_target         Reference to processor chip target
/// @return FAPI_RC_SUCCESS if cleaning up the ADU is a success
    fapi2::ReturnCode p10_adu_utils_cleanup_adu(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

/// @brief Removes the auto increment bit before the last iteration
/// @param[in] i_target         Reference to processor chip target
/// @return FAPI_RC_SUCCESS if removing the auto inc bit is a success
    fapi2::ReturnCode p10_adu_utils_clear_autoinc(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

/// @brief Checks the entire status of the adu
/// @param[in] i_target         Reference to processor chip target
/// @param[in] i_expBusyState   Expected state of ADU status busy bit.
/// @param[in] i_addrOnlyOper   Indicate the check is called after an Address-only operation
/// @return FAPI_RC_SUCCESS if the status check is a success
    fapi2::ReturnCode p10_adu_utils_status_check(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const bool i_expBusyState,
        const bool i_addrOnlyOper);

/// @brief Acquires and releases a lock as well as deals with any lock picking
/// @param[in] i_target         Reference to processor chip target
/// @param[in] i_lock_pick      If the lock does not go through should we set a lock pick
/// @param[in] i_lock           True if this is to lock the ADU false if this is to unlock the ADU
/// @param[in] i_num_attempts   Number of times to try locking the ADU
/// @return FAPI_RC_SUCCESS if the lock action is a success
    fapi2::ReturnCode p10_adu_utils_manage_lock(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const bool i_lock_pick,
        const bool i_lock,
        const uint32_t i_num_attempts);

/// @brief Appends input data to the fapi2 return code if we got an error back
/// @param[in] i_address        Address for the read or write
/// @param[in] i_rnw            Whether the operation is a read or write
/// @param[in] i_flags          Flags that contain information that the ADU needs to know to set up registers
/// @param[inout] o_rc          FAPI error code to be appended with input data
    void p10_adu_utils_append_input_data(
        const uint64_t i_address,
        const bool i_rnw,
        const uint32_t i_flags,
        fapi2::ReturnCode& o_rc);

} // extern "C"

#endif //_P10_ADU_UTILS_H_
