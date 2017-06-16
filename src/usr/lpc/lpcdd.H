/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/lpc/lpcdd.H $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2017                        */
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

typedef uint64_t LPCBase_t;

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
     * @brief Check For Errors in OPB and LPCHC Status Registers
     *
     * @return Error log if error found
     */
    errlHndl_t checkForLpcErrors();

    /**
     * @brief Enums for different levels of resetting PNOR communication levels
     */
    enum ResetLevels
    {
        RESET_CLEAR          = 0x00000000, /**< Clear Reset Level */
        RESET_OPB_LPCHC_SOFT = 0x00000001, /**< OPB LPCHC Clear Errors */
        RESET_OPB_LPCHC_HARD = 0x00000002, /**< OPB LPCHC Reset Logic */
        RESET_INIT           = 0x00000004, /**< Initial HW setup */
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
    * @brief Get the base address of the LPC space
    *
    * @return Pointer to base address
    */
    uint64_t getLPCBaseAddr(void)
    {
        return iv_lpcBaseAddr;
    };

    /**
    * @brief Set the base address of the LPC space
    *
    * @return Void
    */
    void setLPCBaseAddr(uint64_t * i_baseLPCAddr)
    {
        iv_lpcBaseAddr = reinterpret_cast<uint64_t>(i_baseLPCAddr);
    };

    /**
    * @brief Get the start offset in the LPC space
    *
    * @return Offset to LPC start address
    */
    uint64_t getLPCStartAddr(void)
    {
        return LPC_ADDR_START;
    };

    /**
     * @brief Block/unblock all LPC operations
     * @param[in] i_block  true: block ops, false: allow ops
     */
    void lock( bool i_block )
    {
        if( i_block ) {
            mutex_lock(ivp_mutex);
        } else {
            mutex_unlock(ivp_mutex);
        }
    };

    /**
     * @brief Constructor
     * @param[in]  Processor target associated with the LPC Master
     */
    LpcDD( TARGETING::Target* i_proc
           = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL );

    /**
     * @brief Destructor
     */
    ~LpcDD();

  protected:


    /**
     * @brief Some general constants
     *
     */
    enum {

        /** Start of LPC Addr within the memory mapped space*/
        LPC_ADDR_START = 0xC0000000,
        /** Size that LPC takes up (0xC0000000 to 0xFFFFFFFF)*/
        LPC_SPACE_SIZE = 0x40000000,

        /**< OPB LPCM Sync FIR Reg WOX_AND - used to clear the FIR */
        OPB_LPCM_FIR_WOX_AND_REG = 0x01010C01,

        /**< OPB LPCM Sync FIR Mask Reg WO_OR - used to set the mask */
        OPB_LPCM_FIR_MASK_WO_OR_REG = 0x01010C05,

        // LPCHC reset-related registers
        OPB_MASTER_LS_CONTROL_REG = 0x008, /**<OPBM LS Control Reg */

        LPCHC_SYNC_CYCLE_COUNTER_INFINITE = 0xFF000000,

        /** OPB Master Accumulated Status Register - used to check error bits*/
        OPBM_ACCUM_STATUS_REG = 0x0,

        /** OPB Master Actual Status Register */
        OPBM_STATUS_REG = 0x004C,

        /** LPC Host Controller Status Register - used to check error bits*/
        LPCHC_REG = 0x2038,

        /** LPC Host Controller Error Addr Register - used to check error bits*/
        LPCHC_ERROR_ADDR_REG = 0x2040,

        /** LPC Host Controller Reset Register */
        LPCHC_LPC_BUS_ABORT_REG = 0x20F8,

        /** LPC Host Controller Reset Register */
        LPCHC_RESET_REG = 0x20FC,

        OPB_ERROR_MASK = 0x20000FC3, /**< OPBM Error Bits MASK */

        LPCHC_ERROR_MASK = 0x000004FC /**< LPCHC Error Bits MASK */

    };

    /**
     * @brief  OPB Master Status Register Layout
     */
    union OpbmErrReg_t
    {
        uint32_t data32;
        struct
        {
            uint32_t reserved : 2;    // 0:1 reserved
            uint32_t rxctgtel : 1;    // 2 - OPB master timeout
            uint32_t rxfwrdcv : 1;    // 3 - FW read cache valid(status only)
            uint32_t reserved1 : 16;  // 4:19 reserved
            uint32_t rxits : 1;      // 20 - Invalid Transfer Size
            uint32_t rxicmd : 1;     // 21 - Invalid Command
            uint32_t rxiaa : 1;      // 22 - Invalid address alignment
            uint32_t rxiaddr : 1;    // 23 - Invalid address
            uint32_t rxopbe : 1;     // 24 - OPB error acknowledge
            uint32_t rxopbt : 1;     // 25 - OPB timeout
            uint32_t reserved2 : 4;  // 26:29 reserved
            uint32_t rxicmdb : 1;    // 30 - Command buffer parity error
            uint32_t rxidatab : 1;   // 31 - Data buffer parity error

        };
        OpbmErrReg_t() : data32(0) {};
    };

    /**
     * @brief  LPCHC Status Register Layout
     */
    union LpchcErrReg_t
    {
        uint32_t data32;
        struct
        {
            uint32_t reserved : 17;    // 0:16 IRQSER status - not used
            uint32_t reserved1 : 4;    // 17:20 reserved
            uint32_t lreset : 1;       // 21 - Lreset Event
            uint32_t reserved2 : 2;    // 22:23 reserved
            uint32_t syncab : 1;       // 24 - Sync Abnormal
            uint32_t syncnr : 1;       // 25 - Sync no response
            uint32_t syncne : 1;       // 26 - Sync normal error
            uint32_t syncto : 1;       // 27 - Sync timeout
            uint32_t tctar : 1;        // 28 - Target cycle TAR error
            uint32_t mctar : 1;        // 29 - LPC bus master cycle TAR error
            uint32_t mzeror : 1;       // 30 - LPC bus master 0 request
            uint32_t moner : 1;        // 31 - LPC bus master 1 request
        };
        LpchcErrReg_t() : data32(0) {};
    };


    /**
     *
     * @brief Compute the Severity of the errors from the OPBM Status Register
     *
     * @parm i_opbmErrData    Masked bits of the OPBM error register
     * @parm o_resetLevel     Level of severity of the error reported
     */
    void computeOpbmErrSev(OpbmErrReg_t i_opbmErrData,
                           ResetLevels &o_resetLevel);

    /**
     * @brief Compute the Severity of the errors from the LPCHC Status Register
     *
     * @parm i_lpchcErrData    Masked bits of the LPCHC error register
     * @parm o_resetLevel     Level of severity of the error reported
     */
    void computeLpchcErrSev(LpchcErrReg_t i_lpchcErrData,
                            ResetLevels &o_resetLevel);

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
                          uint64_t* o_addr );

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
     * @brief Processor target associated with the LPC Master
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

    /**
    * @brief Virtual Address of the begining of LPC address space
    */
    uint64_t iv_lpcBaseAddr;

};


#endif
