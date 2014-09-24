/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/lpc/lpcdd.H $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
/* [+] Google Inc.                                                        */
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
#ifndef __LPC_LPCDD_H
#define __LPC_LPCDD_H

#include <limits.h>
#include <sys/sync.h>
#include <stdint.h>
#include <errl/errlentry.H>
#include <lpc/lpcif.H>

/** @file lpcdd.H
 *  @brief Provides the interfaces to the LPC Device Driver
 */

/**
 *  @brief  LPC Device Driver Class
 *     Provides access to the LPC bus for a specific Processor
 */
class LpcDD
{
  public:
    /**
     * @brief Performs a LPC Read Operation
     *
     * @param i_trans    LPC transaction type
     * @param i_address  LPC address
     * @param o_buffer   Buffer to read data into
     * @param io_buflen  Input: Number of bytes to read,
     *       Output: Number of bytes actually read
     *
     * @return Error from operation
     */
    errlHndl_t readLPC(LPC::TransType i_type,
                       uint32_t i_address,
                       void* o_buffer,
                       size_t& io_buflen);

    /**
     * @brief Performs a LPC Write Operation
     *
     * @param i_trans    LPC transaction type
     * @param i_address  LPC address
     * @param i_buffer  Buffer to write data from
     * @param io_buflen  Input: Number of bytes to write,
     *       Output: Number of bytes actually written
     *
     * @return Error from operation
     */
    errlHndl_t writeLPC(LPC::TransType i_type,
                        uint32_t i_address,
                        const void* i_buffer,
                        size_t& io_buflen);


    /**
     * @brief Enums for different levels of resetting PNOR communication levels
     */
    enum ResetLevels
    {
        RESET_CLEAR          = 0x00000000, /**< Clear Reset Level */
        RESET_ECCB           = 0x00000001, /**< ECCB FW Logic */
        RESET_OPB_LPCHC_SOFT = 0x00000002, /**< OPB LPCHC Clear Errors */
        RESET_OPB_LPCHC_HARD = 0x00000004, /**< OPB LPCHC Reset Logic */

        RESET_INIT    = RESET_CLEAR, // Nothing to do for initial boot yet
    };


    /**
     * @brief Reset hardware to get into clean state
     *
     * @parm i_resetLevel    How much LPC logic to reset
     *
     * @return errlHndl_t  NULL on success, else error log
     */
    errlHndl_t hwReset( ResetLevels i_resetLevel );

    /**
     * @brief Get the target associated with this dd instance
     *
     * @return Pointer to target
     */
    TARGETING::Target* getProc( void )
    {
        return iv_proc;
    };

    /**
     * @brief Constructor
     * @param[in]  Processor target associated with the ECCB logic
     */
    LpcDD( TARGETING::Target* i_proc
           = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL );


    /**
     * @brief Destructor
     */
    ~LpcDD();

  protected:
    /**
     * @brief LPC HC Registers
     *    These are offsets within the LPC Host Controller Register Space
     */
    enum LpcRegAddr {
        LPC_REG_BAR0 = 0x00, /**< BAR0 : OPB register */
        LPC_REG_BAR1 = 0x04, /**< BAR1 : LPC I/O space */
        LPC_REG_BAR2 = 0x08, /**< BAR2 : LPC Memory space */
        LPC_REG_BAR3 = 0x0C, /**< BAR3 : LPC Firmware space */
        LPC_REG_ABRTCNT = 0x2C, /**< ABORT COUNT */
    };


    /**
     * @brief Some general constants
     *
     */
    enum {
        LPCHC_FW_SPACE  = 0xF0000000, /**< LPC Host Controller FW Space */
        LPCHC_MEM_SPACE = 0xE0000000, /**< LPC Host Controller Mem Space */
        LPCHC_IO_SPACE  = 0xD0010000, /**< LPC Host Controller I/O Space */
        LPCHC_REG_SPACE = 0xC0012000, /**< LPC Host Ctlr Register Space */

        ECCB_NON_FW_RESET_REG = 0x000B0001, /**< ECCB Reset Reg (non-FW) */

        ECCB_CTL_REG  = 0x000B0020, /**< ECCB Control Reg (FW) */
        ECCB_RESET_REG  = 0x000B0021, /**< ECCB Reset Reg (FW) */
        ECCB_STAT_REG = 0x000B0022, /**< ECCB Status Reg (FW) */
        ECCB_DATA_REG = 0x000B0023, /**< ECCB Data Reg (FW) */

        // Default Values to set for all operations
        // 1101.0100.0000.000x.0000.0001.0000.0000.<address>
        ECCB_CTL_REG_DEFAULT = 0xD400010000000000,

        // Error bits: 41-43, 56  (52=cmd complete) (not 57: only non-fw use)
        ECCB_STAT_REG_ERROR_MASK = 0x0000000000700080, /**< Error Bits */

        /**< OPB LPCM Sync FIR Reg - used to read the FIR*/
        OPB_LPCM_FIR_REG = 0x01010C00,

        /**< OPB LPCM Sync FIR Reg WOX_AND - used to clear the FIR */
        OPB_LPCM_FIR_WOX_AND_REG = 0x01010C01,

        /**< OPB LPCM Sync FIR Mask Reg WO_OR - used to set the mask */
        OPB_LPCM_FIR_MASK_WO_OR_REG = 0x01010C05,

        OPB_LPCM_FIR_ERROR_MASK = 0xFF00000000000000, /**< Error Bits MASK */

        // LPCHC reset-related registers
        OPB_MASTER_LS_CONTROL_REG = 0x008, /**<OPBM LS Control Reg */
        LPCHC_RESET_REG           = 0x0FC, /**<LPC HC Reset Register */

        ECCB_RESET_LPC_FAST_RESET = 1ULL << 62, /**< bit 1 = Fast reset */

        ECCB_POLL_TIME_NS = 400000, /**< max time should be 400ms */
        ECCB_POLL_INCR_NS = 10, /**< minimum increment during poll */

        LPCHC_SYNC_CYCLE_COUNTER_INFINITE = 0xFF000000
    };

    /**
     * @brief  ECCB Control Register Layout
     */
    union ControlReg_t
    {
        uint64_t data64;
        struct
        {
            // unused sections should be set to zero
            uint64_t magic1      : 4;  /**< 0:3 = b1101 per spec */
            uint64_t data_len    : 4;  /**< 4:7 = b0100 means 4 byte */
            uint64_t unused1     : 7;  /**< 8:14 */
            uint64_t read_op     : 1;  /**< 15 = set for read operation */
            uint64_t unused2     : 7;  /**< 16:22 */
            uint64_t addr_len    : 3;  /**< 23:25 = b100 means 4 byte */
            uint64_t unused3     : 6;  /**< 26:31 */
            uint64_t address     : 32; /**< 32:63 = LPC Address */
        };

        ControlReg_t() : data64(ECCB_CTL_REG_DEFAULT) {};
    };

    /**
     * @brief  ECCB Status Register Layout
     */
    union StatusReg_t
    {
        uint64_t data64;
        struct
        {
            uint64_t unused      : 6;  /**< 0:5  */
            uint64_t read_data   : 32; /**< 6:37 */
            uint64_t unused1     : 3;  /**< 38:40 */
            uint64_t eccb_err    : 3;  /**< 41:43 = ECCB_Error_Info */
            uint64_t busy        : 1;  /**< 44 = Operation Busy */
            uint64_t unused2     : 7;  /**< 45:51 */
            uint64_t op_done     : 1;  /**< 52 = Command Complete */
            uint64_t unused3     : 3;  /**< 53:55 */
            uint64_t addr_parity_err : 1; /**< 56 = ECC Address Register
                                                    Parity Error */
            uint64_t unused4     : 7;  /**< 57:63 */
        };
        StatusReg_t() : data64(0) {};
    };

    /**
     * @brief  OPB-LPCM FIR Register Layout
     */
    union OpbLpcmFirReg_t
    {
        uint64_t data64;
        struct
        {
            uint64_t rxits : 1;    // Invalid Transfer Size
            uint64_t rxicmd : 1;   // Invalid Command
            uint64_t rxiaa : 1;    // Invalid Address Alignment
            uint64_t rxhopbe : 1;  // OPB Bus Error
            uint64_t rxhopbt : 1;  // OPB Bus Timeout
            uint64_t rxctgtel : 1; // CI Load/CI Store/OPB Master Hang Timeout
            uint64_t rxcbpe : 1;   // Command Buffer Parity Error
            uint64_t rxdbpe : 1;   // Data Buffer Parity Error
            uint64_t reserved  : 56;
        };
        OpbLpcmFirReg_t() : data64(0) {};
    };


    /**
     * @brief Check For Errors in OPB and LPCHC Status Registers
     *
     * @parm o_resetLevel    if error, reset level to clear error
     * @return Error log if error found
     */
    errlHndl_t checkForOpbErrors( ResetLevels &o_resetLevel );

    /**
     * @brief Sanity check the input address for a LPC op and return
     *   full absolute address
     *
     * @param[in] i_type  LPC range
     * @param[in] i_addr  Relative LPC address
     * @param[out] o_addr  Absolute LPC address
     *
     * @return Error from operation
     */
    errlHndl_t checkAddr( LPC::TransType i_type,
                          uint32_t i_addr,
                          uint32_t* o_addr );

    /**
     * @brief Poll for completion of LPC operation
     *
     * @param[in] i_ctrl  Control register describing operation
     * @param[out] o_stat  Status register for failures
     *
     * @return errlHndl_t  NULL on success, else error log
     */
    errlHndl_t pollComplete( const ControlReg_t& i_ctrl,
                             StatusReg_t& o_stat );

    /**
     * @brief Add Error Registers to an existing Error Log
     * @param[inout] io_errl  Error log to add data to
     */
    void addFFDC(errlHndl_t& io_errl);

    /**
     * @brief Performs a LPC Read Operation, assumes lock is already held
     *
     * @param i_trans    LPC transaction type
     * @param i_address  LPC address
     * @param o_buffer   Buffer to read data into
     * @param io_buflen  Input: Number of bytes to read,
     *       Output: Number of bytes actually read
     *
     * @return Error from operation
     */
    errlHndl_t _readLPC(LPC::TransType i_type,
                        uint32_t i_address,
                        void* o_buffer,
                        size_t& io_buflen);

    /**
     * @brief Performs a LPC Write Operation, assumes lock is already held
     *
     * @param i_trans    LPC transaction type
     * @param i_address  LPC address
     * @param i_buffer  Buffer to write data from
     * @param io_buflen  Input: Number of bytes to write,
     *       Output: Number of bytes actually written
     *
     * @return Error from operation
     */
    errlHndl_t _writeLPC(LPC::TransType i_type,
                         uint32_t i_address,
                         const void* i_buffer,
                         size_t& io_buflen);

  private:
    /**
     * @brief Mutex to prevent concurrent LPC accesses to the master
     */
    static mutex_t cv_mutex;

    /**
     * @brief Mutex to prevent concurrent LPC accesses to a given
     *        instance of the LPC logic
     *        Note: this is unused for Master
     */
    mutex_t iv_mutex;

    /**
     * @brief Pointer to mutex in use
     */
    mutex_t* ivp_mutex;

    /**
     * @brief Processor target associated with the ECCB logic
     */
    TARGETING::Target* iv_proc;

    /**
     * @brief Marker to avoid infinite recursion in error handlers
     */
    bool iv_ffdcActive;

    /**
     * @brief Number of times recovered from an error
     */
    uint32_t iv_errorHandledCount;

    /**
     * @brief Indicates recovery from an error has failed
     */
    bool iv_errorRecoveryFailed;

    /**
     * @brief Indicates if class is currently doing a RESET procedure
     */
    bool iv_resetActive;

};


#endif
