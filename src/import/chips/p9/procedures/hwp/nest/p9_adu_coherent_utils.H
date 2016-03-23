/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_adu_coherent_utils.H $        */
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

// Definitions of how to handle Busy state of the ADU when
// checking its status.
enum adu_status_busy_handler
{
    EXPECTED_BUSY_BIT_CLEAR = 0,  // Expect to be clear, error if not
    EXPECTED_BUSY_BIT_SET   = 1,  // Expect to be set, error if not
    EXIT_ON_BUSY            = 2   // Return Busy status without checking
                              // any other errors.
};

extern"C"
{

//-----------------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------
// Classes
//-----------------------------------------------------------------------------------
///
/// @brief  Manage ADU operation flag that is used to program the
//          ADU CMD register, PU_ALTD_CMD_REG (Addr: 0x00090001)
///
    class p9_ADU_oper_flag
    {
        public:

            // Type of ADU operations
            enum OperationType_t
            {
                CACHE_INHIBIT = 0,
                DMA_PARTIAL   = 1,
                PB_OPER       = 2,
                PMISC_OPER    = 3,
            };

            // Transaction size
            enum Transaction_size_t
            {
                TSIZE_1 = 1,
                TSIZE_2 = 2,
                TSIZE_4 = 4,
                TSIZE_8 = 8,
            };

            // Constructor
            inline p9_ADU_oper_flag()
                : iv_operType(CACHE_INHIBIT), iv_autoInc(false), iv_lockPick(false),
                  iv_numLockAttempts(1), iv_cleanUp(true), iv_fastMode(false),
                  iv_itag(false), iv_ecc(false), iv_eccItagOverwrite(false),
                  iv_transSize(TSIZE_1)
            {
            }

            ///
            /// @brief Set the ADU operation type
            ///
            /// @param[in] i_type     ADU operation type
            ///
            /// @return void.
            ///
            inline void setOperationType(const OperationType_t i_type)
            {
                iv_operType = i_type;
                return;
            }

            ///
            /// @brief Get the ADU operation type setting.
            ///
            /// @return iv_operType.
            ///
            inline const OperationType_t getOperationType(void)
            {
                return iv_operType;
            }

            /// @brief Set the Auto Increment option, for CI/DMA operations only.
            ///
            /// @param[in] i_value     True: Enable auto inc; False: Disable
            ///
            /// @return void.
            ///
            inline void setAutoIncrement(bool i_value)
            {
                if ( (iv_operType != CACHE_INHIBIT) &&
                     (iv_operType != DMA_PARTIAL) )
                {
                    FAPI_ERR("WARNING: Set AUTOINC for non CI/DMA operation, Operation type 0x%.8X",
                             iv_operType);
                }

                iv_autoInc = i_value;
                return;
            }

            /// @brief Get the Auto Increment setting, for CI/DMA operations only.
            ///
            /// @return iv_autoInc.
            ///
            inline const bool getAutoIncrement(void)
            {
                if ( (iv_operType != CACHE_INHIBIT) &&
                     (iv_operType != DMA_PARTIAL) )
                {
                    FAPI_ERR("WARNING: AUTOINC value is invalid for non CI/DMA operation, Operation type 0x%.8X",
                             iv_operType);
                }

                return iv_autoInc;
            }

            ///
            /// @brief Set ADU lock control
            ///
            /// @param[in] i_value     True: Attempt lock ADU before operation
            ///                        False: No lock attempt
            ///
            /// @return void
            ///
            inline void setLockControl(bool i_value)
            {
                iv_lockPick = i_value;
                return;
            }

            ///
            /// @brief Get the ADU lock control setting.
            ///
            /// @return iv_lockPick.
            ///
            inline const bool getLockControl(void)
            {
                return iv_lockPick;
            }

            ///
            /// @brief Set number of lock attempts
            ///
            /// @param[in] i_value     Num of lock attempts to try. If still can't lock
            ///                        ADU, return an error.
            ///
            /// @return void
            ///
            inline void setNumLockAttempts(uint8_t i_value)
            {
                iv_numLockAttempts = i_value;
                return;
            }

            ///
            /// @brief Get number of lock attempts setting.
            ///
            /// @return iv_numLockAttempts.
            ///
            inline const uint8_t getNumLockAttempts(void)
            {
                return iv_numLockAttempts;
            }

            ///
            /// @brief Clean up if operation fails
            ///
            /// @param[in] i_value     True: Clean up and release lock if oper fails.
            ///                        False: Leave ADU in fail state.
            ///
            /// @return void.
            ///
            inline void setOperFailCleanup(bool i_value)
            {
                iv_cleanUp = i_value;
                return;
            }

            ///
            /// @brief Get the clean up for failed operation setting.
            ///
            /// @return iv_cleanUp.
            ///
            inline const bool getOperFailCleanup(void)
            {
                return iv_cleanUp;
            }

            ///
            /// @brief Set fast read/write mode.
            ///        For fast read/write mode, no status check.  Otherwise,
            ///        do status check after every read/write.
            ///
            /// @param[in] i_value     True: Enable fast read/write mode.
            ///                        False: Disable fast read/write mode.
            ///
            /// @return void.
            ///
            inline void setFastMode(bool i_value)
            {
                iv_fastMode = i_value;
                return;
            }

            ///
            /// @brief Get the Fast mode setting.
            ///
            /// @return iv_fastMode.
            ///
            inline const bool getFastMode(void)
            {
                return iv_fastMode;
            }

            ///
            /// @brief Set itag collection mode.
            ///        Collect/set itag with each 8B read/write
            ///        For a write only set if itag data should be 1
            ///
            /// @param[in] i_value     True: Collect itag
            ///                        False: Don't collect itag.
            ///
            /// @return void.
            ///
            inline void setItagMode(bool i_value)
            {
                iv_itag = i_value;
                return;
            }

            ///
            /// @brief the ITAG collection mode.
            ///
            /// @return iv_itag.
            ///
            inline const bool getItagMode(void)
            {
                return iv_itag;
            }

            ///
            /// @brief Set Ecc mode.
            ///        Collect/set ecc with each 8B read/write
            ///
            /// @param[in] i_value     True: Collect ECC
            ///                        False: Don't collect ECC.
            ///
            /// @return void.
            ///
            inline void setEccMode(bool i_value)
            {
                iv_ecc = i_value;
                return;
            }

            ///
            /// @brief Get the Ecc mode setting.
            ///
            /// @return iv_ecc.
            ///
            inline const bool getEccMode(void)
            {
                return iv_ecc;
            }

            ///
            /// @brief Overwrite ECC/ITAG data mode.
            ///
            /// @param[in] i_value     Overwrite ECC
            ///                        False: Don't overwrite ECC
            ///
            /// @return void.
            ///
            inline void setEccItagOverrideMode(bool i_value)
            {
                iv_eccItagOverwrite = i_value;
                return;
            }

            ///
            /// @brief Get the Overwrite ECC/ITAG data mode.
            ///
            /// @return iv_eccItagOverwrite.
            ///
            inline const bool getEccItagOverrideMode(void)
            {
                return iv_eccItagOverwrite;
            }

            ///
            /// @brief Set transaction size
            ///
            /// @param[in] i_value     Transaction size
            ///
            /// @return void.
            ///
            inline void setTransactionSize(Transaction_size_t i_value)
            {
                iv_transSize = i_value;
                return;
            }

            ///
            /// @brief Get the transaction size
            ///
            /// @return iv_transSize.
            ///
            inline const Transaction_size_t getTransactionSize(void)
            {
                return iv_transSize;
            }

            ///
            /// @brief Assemble the 32-bit ADU flag based on current
            ///        info contained in this class.
            ///        This flag is to be used in ADU interface call
            ///        See flag bit definitions in p9_adu_constants.H
            ///
            /// @return uint32_t
            ///
            inline uint32_t setFlag();

            ///
            /// @brief Update the class instant variables with info
            ///        embedded in the passed in flag value.
            ///
            /// @return void.
            ///
            inline void getFlag(uint32_t i_flag);

        private:

            // Class variables
            OperationType_t iv_operType;         // Operation type
            bool iv_autoInc;                     // Auto increment
            bool iv_lockPick;                    // Lock ADU before operation
            uint8_t iv_numLockAttempts;          // Number of lock attempts
            bool iv_cleanUp;
            bool iv_fastMode;                    // Fast ADU read/write mode
            bool iv_itag;                        // Itag mode
            bool iv_ecc;                         // ECC mode
            bool iv_eccItagOverwrite;            // ECC/ITAG overwrite mode
            Transaction_size_t iv_transSize;     // Transaction size
    };

///
/// See doxygen in class definition
///
    uint32_t p9_ADU_oper_flag::setFlag()
    {
        uint32_t l_aduFlag = 0;

        // Operation type
        l_aduFlag |= (iv_operType << FLAG_ADU_TTYPE_SHIFT);

        // Auto Inc
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

        // Leave dirty
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
        if (iv_transSize == TSIZE_1)
        {
            l_aduFlag |= FLAG_SIZE_TSIZE_1;
        }
        else if (iv_transSize == TSIZE_2)
        {
            l_aduFlag |= FLAG_SIZE_TSIZE_2;
        }
        else if (iv_transSize == TSIZE_4)
        {
            l_aduFlag |= FLAG_SIZE_TSIZE_4;
        }
        else if (iv_transSize == TSIZE_8)
        {
            l_aduFlag |= FLAG_SIZE_TSIZE_8;
        }
        else
        {
            FAPI_ERR("Invalid transaction size: iv_transSize %d",  iv_transSize);
        }

        // Debug trace
        FAPI_DBG("p9_ADU_oper_flag::setFlag()");
        FAPI_DBG("    iv_operType 0x%.8X, iv_autoInc 0x%.8X, iv_lockPick 0x%.8X, iv_numLockAttempts 0x%.8X",
                 iv_operType, iv_autoInc, iv_lockPick, iv_numLockAttempts);
        FAPI_DBG("    iv_cleanUp 0x%.8X, iv_fastMode 0x%.8X, iv_itag 0x%.8X, iv_ecc 0x%.8X",
                 iv_cleanUp, iv_fastMode, iv_itag, iv_ecc);
        FAPI_DBG("    iv_eccItagOverwrite 0x%.8X, iv_transSize 0x%.8X",
                 iv_eccItagOverwrite, iv_transSize);
        FAPI_DBG("   ADU Flag value: 0x%.8X", l_aduFlag);

        return l_aduFlag;
    }

///
/// See doxygen in class definition
///
    void p9_ADU_oper_flag::getFlag(const uint32_t i_flag)
    {
        // Decode Operation type
        iv_operType = static_cast<OperationType_t>
                      ( (i_flag & FLAG_ADU_TTYPE) >> FLAG_ADU_TTYPE_SHIFT);

        // Auto Inc
        iv_autoInc = (i_flag & FLAG_AUTOINC);

        // Lock pick
        iv_lockPick = (i_flag & FLAG_LOCK_PICK);

        // Lock attempts
        iv_numLockAttempts = ( (i_flag & FLAG_LOCK_TRIES) >> FLAG_LOCK_TRIES_SHIFT);

        // Leave dirty
        iv_cleanUp = ~(i_flag & FLAG_LEAVE_DIRTY);

        // Fast mode
        iv_fastMode = (i_flag & FLAG_ADU_FASTMODE);

        // Itag
        iv_itag = (i_flag & FLAG_ITAG);

        // ECC
        iv_ecc = (i_flag & FLAG_ECC);

        // Overwrite ECC
        iv_eccItagOverwrite = (i_flag & FLAG_OVERWRITE_ECC);

        // Transaction size
        iv_transSize = static_cast<Transaction_size_t>
                       ( (i_flag & FLAG_SIZE) >> FLAG_ADU_SIZE_SHIFT );

        // Debug trace
        FAPI_DBG("p9_ADU_oper_flag::getFlag() - Flag value 0x%.8X", i_flag);
        FAPI_DBG("    iv_operType 0x%.8X, iv_autoInc 0x%.8X, iv_lockPick 0x%.8X, iv_numLockAttempts 0x%.8X",
                 iv_operType, iv_autoInc, iv_lockPick, iv_numLockAttempts);
        FAPI_DBG("    iv_cleanUp 0x%.8X, iv_fastMode 0x%.8X, iv_itag 0x%.8X, iv_ecc 0x%.8X",
                 iv_cleanUp, iv_fastMode, iv_itag, iv_ecc);
        FAPI_DBG("    iv_eccItagOverwrite 0x%.8X, iv_transSize 0x%.8X",
                 iv_eccItagOverwrite, iv_transSize);
        return;
    }

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
/// @param[in] i_aduOper      => Contains information that the ADU needs to know to set up registers
/// @param[in] i_write_data   => the data that is to be written to the ADU
/// @return FAPI_RC_SUCCESS if writing the ADU is a success
    fapi2::ReturnCode p9_adu_coherent_adu_write(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const bool i_firstGranule,
        const uint64_t i_address,
        p9_ADU_oper_flag& i_aduOper,
        const uint8_t i_write_data[]);

/// @brief does the read for the ADU
/// @param[in] i_target       => P9 chip target
/// @param[in] i_firstGranule => the first 8B granule that we are reading
/// @param[in] i_address      => address for this read
/// @param[in] i_aduOper      => Contains information that the ADU needs to know to set up registers
/// @param[out] o_read_data   => the data that is read from the ADU
/// @return FAPI_RC_SUCCESS if reading the ADU is a success
    fapi2::ReturnCode p9_adu_coherent_adu_read(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const bool i_firstGranule,
        const uint64_t i_address,
        p9_ADU_oper_flag& i_aduOper,
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

/// @brief This function checks the status of the adu.
///        If ADU is busy, it will handle
///
/// @param[in] i_target            P9 chip target
/// @param[in] i_busyBitHandler    Instruction on how to handle the ADU busy
/// @param[in] i_addressOnlyOper   Indicate the check is called after an Address
///                                only operation
/// @param[out] o_busyStatus       ADU status busy bit.
///
/// @return FAPI_RC_SUCCESS if the status check is a success
    fapi2::ReturnCode p9_adu_coherent_status_check(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const adu_status_busy_handler i_busyBitHandler,
        const bool i_addressOnlyOper,
        bool& o_busyBitStatus);

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
