/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/lpc/lpcdd.H $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2021                        */
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
#include <lpc/lpc_const.H>

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
    virtual errlHndl_t readLPC(LPC::TransType i_type,
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
    virtual errlHndl_t writeLPC(LPC::TransType i_type,
                        uint32_t i_address,
                        const void* i_buffer,
                        size_t& io_buflen);

    /**
     * @brief Check For Errors in OPB and LPCHC Status Registers
     *
     * @return Error log if error found
     */
    virtual errlHndl_t checkForLpcErrors();

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
    virtual errlHndl_t hwReset( ResetLevels i_resetLevel );

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
    virtual ~LpcDD();

    /**
     * @brief LPC complex register addresses.  These addresses are expressed as
     *     relative to the start of the OPB space (i.e. do not include base
     *     address of that space or any chip-relative addressing)
     */
    enum LPC_REGS
    {
        // OPB Master (4 bytes accesses)
        OPBM_ACCUM_STATUS_REG            = 0x0000,
        OPBM_ACCUM_STATUS_INT_ENABLE_REG = 0x0004,
        OPBM_CONTROL_REG                 = 0x0008,
        OPBM_IOMUX_CONTROL_REG           = 0x000C,
        OPBM_TRACE_00_REG                = 0x0010,
        OPBM_TRACE_01_REG                = 0x0014,
        OPBM_TRACE_02_REG                = 0x0018,
        OPBM_TRACE_03_REG                = 0x001C,
        OPBM_TRACE_04_REG                = 0x0020,
        OPBM_TRACE_05_REG                = 0x0024,
        OPBM_TRACE_06_REG                = 0x0028,
        OPBM_TRACE_07_REG                = 0x002C,
        OPBM_TRACE_08_REG                = 0x0030,
        OPBM_TRACE_09_REG                = 0x0034,
        OPBM_BUF_ERR_INJECT_REG          = 0x0038,
        OPBM_TIMEOUT_VALUE_REG           = 0x0040,
        OPBM_ACCUM_STATUS_ERR_INJECT_REG = 0x0048,
        OPBM_ACTUAL_STATUS_REG           = 0x004C,
        OPBM_INT_REG                     = 0x0050,
        OPBM_INT_ENABLE_REG              = 0x0054,
        OPBM_INT_POLARITY_REG            = 0x0058,
        OPBM_INT_INPUTS_REG              = 0x005C,

        // OPB Arbiter (1 byte accesses)
        OPB_ARB_PRIORITY_REG             = 0x1000,
        OPB_ARB_CONTROL_REG              = 0x1001,
        OPB_ARB_REVISION_ID_0_REG        = 0x1004,
        OPB_ARB_REVISION_ID_1_REG        = 0x1005,
        OPB_ARB_REVISION_ID_2_REG        = 0x1006,
        OPB_ARB_REVISION_ID_3_REG        = 0x1007,

        // LPCHC (4 byte accesses)
        LPCHC_BASE_ADDR_0_INT_REG        = 0x2000,
        LPCHC_BASE_ADDR_1_IO_REG         = 0x2004,
        LPCHC_BASE_ADDR_2_MEM_REG        = 0x2008,
        LPCHC_BASE_ADDR_3_FW_REG         = 0x200C,
        LPCHC_MEM_SEGMENT_REG            = 0x2020,
        LPCHC_FW_SEGMENT_REG             = 0x2024,
        LPCHC_FW_READ_ACCESS_SIZE_REG    = 0x2028,
        LPCHC_SYNC_CYCLE_CNT_REG         = 0x202C,
        LPCHC_LPCIRQSER_CONTROL_REG      = 0x2030,
        LPCHC_LPCIRQ_MASK_REG            = 0x2034,
        LPCHC_LPCIRQ_STATUS_REG          = 0x2038,
        LPCHC_ERROR_ADDR_REG             = 0x2040,
        LPCHC_LPC_BUS_MASTER_GRANT_REG   = 0x2050,
        LPCHC_LPC_BUS_MASTER_DATA_REG    = 0x2054,
        LPCHC_LPC_BUS_MASTER_ADDR_REG    = 0x2058,
        LPCHC_LPC_BUS_MASTER_SYNC_REG    = 0x205C,
        LPCHC_WATERMARK_REG              = 0x20F0,
        LPCHC_LPC_BUS_ABORT_CYCLE_REG    = 0x20F8,
        LPCHC_RESET_REG                  = 0x20FC,
    };

  protected:

    /**
     *  @brief Returns whether address in LPC error space is part of the OPB
     *      Arbiter
     *
     *  @param[in] i_addr Address, relative to LPC error space, to check
     *
     *  @return bool Indicating whether address is in OPB Arbiter space or not
     */
    bool opbArbiterRange(uint64_t i_addr) const;

    /**
     *  @brief Returns whether address in LPC error space is part of the OPB
     *      Master
     *
     *  @param[in] i_addr Address, relative to LPC error space, to check
     *
     *  @return bool Indicating whether address is in OPB Master space or not
     */
    bool opbMasterRange(uint64_t i_addr) const;

    /**
     *  @brief Returns whether address in LPC error space is part of the LPCHC
     *
     *  @param[in] i_addr Address, relative to LPC error space, to check
     *
     *  @return bool Indicating whether address is in LPCHC space or not
     */
    bool lpchcRange(uint64_t i_addr) const;

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

  protected:

    /**
     * @brief Processor target associated with the LPC Master
     */
    TARGETING::Target* iv_proc;

    /**
     * @brief Marker to avoid infinite recursion in error handlers
     */
    bool iv_ffdcActive;

    /**
     * @brief Indicates if class is currently doing a RESET procedure
     */
    bool iv_resetActive;
    /**
     * @brief Indicates recovery from an error has failed
     */
    bool iv_errorRecoveryFailed;

    /**
     * @brief Number of times recovered from an error
     */
    uint32_t iv_errorHandledCount;

    /**
     * @brief Pointer to mutex in use
     */
    mutex_t* ivp_mutex;

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
     * @brief Virtual Address of the begining of LPC address space
     */
    uint64_t iv_lpcBaseAddr;

};

#endif
