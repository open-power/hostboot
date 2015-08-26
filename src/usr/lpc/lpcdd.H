/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/lpc/lpcdd.H $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2016                        */
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
     * @brief Enums for different levels of resetting PNOR communication levels
     */
    enum ResetLevels
    {
        RESET_CLEAR          = 0x00000000, /**< Clear Reset Level */
        RESET_ECCB           = 0x00000001, /**< ECCB FW Logic */
        RESET_OPB_LPCHC_SOFT = 0x00000002, /**< OPB LPCHC Clear Errors */
        RESET_OPB_LPCHC_HARD = 0x00000004, /**< OPB LPCHC Reset Logic */
        RESET_INIT           = 0x00000008, /**< Initial HW setup */
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
     * @brief Some general constants
     *
     */
    enum {

        /** Start of LPC Addr within the memory mapped space*/
        LPC_ADDR_START = 0xC0000000,
        /** Size that LPC takes up (0xC0000000 to 0xFFFFFFFF)*/
        LPC_SPACE_SIZE = 0x40000000,

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


        LPCHC_SYNC_CYCLE_COUNTER_INFINITE = 0xFF000000
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

    /**
    * @brief Virtual Address of the begining of LPC address space
    */
    uint64_t iv_lpcBaseAddr;

};


#endif
