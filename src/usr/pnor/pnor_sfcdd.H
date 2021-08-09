/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/pnor_sfcdd.H $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
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
#ifndef __PNOR_PNORDD_H
#define __PNOR_PNORDD_H

#include <limits.h>
#include <pnor/pnor_const.H>

namespace PNOR { class UdPnorDDParms; }
class SfcDD;

/** @file pnor_sfcdd.H
 *  @brief Provides the interfaces to the PNOR Device Driver
 */

/**
 *  @brief  PNOR Device Driver Class
 *     Provides access to the PNOR flash via the ECCB/LPC hardware
 */
class PnorSfcDD
{

  public:
    /**
     * @brief Performs a PNOR Read Operation
     *
     * @parm o_buffer  Buffer to read data into
     * @parm io_buflen  Input: Number of bytes to read,
     *       Output: Number of bytes actually read
     * @parm i_address  Offset into flash to read
     *
     * @return Error from operation
     */
    errlHndl_t readFlash(void* o_buffer,
                         size_t& io_buflen,
                         uint64_t i_address);

    /**
     * @brief Performs a PNOR Write Operation
     *
     * @parm i_buffer  Buffer to write data from
     * @parm io_buflen  Input: Number of bytes to write,
     *       Output: Number of bytes actually written
     * @parm i_address  Offset into flash to write
     *
     * @return Error from operation
     */
    errlHndl_t writeFlash(void* i_buffer,
                          size_t& io_buflen,
                          uint64_t i_address);

    /**
     * @brief Informs caller if PNORDD is using
     *        L3 Cache for fake PNOR or not.
     *
     * @return Indicate state of fake PNOR
     *         true = PNOR DD is using L3 Cache for fake PNOR
     *         false = PNOR DD not using L3 Cache for fake PNOR
     */
    bool usingL3Cache( );


    /**
     * @brief Retrieve bitstring of NOR workarounds
     * @return NOR workarounds (see VendorWorkarounds in norflash.H)
     */
    uint32_t getNorWorkarounds( void );

    /**
     * @brief Retrieve size of NOR flash
     * @return Size of PNOR in bytes
     */
    uint32_t getNorSize( void );

    /**
     * @brief Retrieve error log from constructor and forget
     *        about it
     * @return nullptr if no error occurred in constructor,
     *         else contains error log that occurred in constructor
     */
    errlHndl_t getConstructorLog( void )
    {
        // give the stored log to the caller
        errlHndl_t errhdl = iv_constructorLog;
        iv_constructorLog = nullptr;
        return errhdl;
    };

    /**
     * @brief Constructor
     *
     * @parm i_target     Processor Target connected to PNOR
     *       NOTE: i_target can only be used after targeting is loaded
     */
    PnorSfcDD( TARGETING::Target* i_target = NULL );

    /**
     * @brief Destructor
     */
    ~PnorSfcDD();

  protected:

    struct EraseInfo_t
    {
        uint32_t addr;  /**< Address of the erase block */
        uint32_t count;  /**< Num Erases of block */
    };

    /**
     * Enums for different operations that might be re-tried
     */
    enum RetryOp
    {
        RETRY_NOOP              = 0,
        RETRY_writeFlash        = 1,
        RETRY_readFlash         = 2,
        RETRY_eraseFlash        = 3,
    };

    /**
     * @brief Some general constants
     */
    enum {

        LPC_SFC_CMDREG_OFFSET = 0xF0000C00, /** LPC Offest to SFC Cmd Regs */
        LPC_SFC_CMDBUF_OFFSET = 0xF0000D00, /** LPC Off to SFC Cmd Buf space */

        ECCB_STAT_REG = 0x000B0022, /**< ECCB Status Reg (FW) */

        /**< OPB LPCM Sync FIR Reg - used to read the FIR*/
        OPB_LPCM_FIR_REG = 0x01010C00,

        /**< OPB LPCM Sync FIR Reg WOX_AND - used to clear the FIR */
        OPB_LPCM_FIR_WOX_AND_REG = 0x01010C01,

        /**< OPB LPCM Sync FIR Mask Reg WO_OR - used to set the mask */
        OPB_LPCM_FIR_MASK_WO_OR_REG = 0x01010C05,

        OPB_LPCM_FIR_ERROR_MASK = 0xFF00000000000000, /**< Error Bits MASK */

        // LPCHC reset-related registers
        OPB_MASTER_LS_CONTROL_REG = 0xC0010008, /**<OPBM LS Control Reg */
        LPCHC_RESET_REG = 0xC00120FC, /**<LPC HC Reset Register */

        ERASE_COUNT_MAX = 64,  /**<Max number of tracked erase blocks */
        ERASESIZE_BYTES_DEFAULT = 4 * KILOBYTE, /**< Min Erase Block (bytes) */
    };

    /**
     * @brief Read an address from LPC space
     *
     * @parm i_addr  Absolute LPC Address
     * @parm o_data  Buffer to read data into
     *
     * @return Error from operation
     */
    errlHndl_t readLPC(uint32_t i_addr,
                       uint32_t& o_data);

    /**
     * @brief Write an address from LPC space
     *

     * @parm o_data  Data to write
     *
     * @return Error from operation
     */
    errlHndl_t writeLPC(uint32_t i_addr,
                        uint32_t i_data);


    /**
     * @brief Erase a block of flash
     * @pre Mutex should already be locked before calling
     *
     * @parm i_address  Offset into flash to erase, aligned to erase block
     *
     * @return Error from operation
     */
    errlHndl_t eraseFlash(uint32_t i_address);

    /**
     * @brief Compare the existing data in 1 erase block of the flash with
     *   the incoming data and write or erase as needed
     * @pre Mutex should already be locked before calling
     *
     * @parm i_blockStart  Start of Erase Block we're writing to
     * @parm i_writeStart  Starting address where we want to write data.
     * @parm i_bytesToWrite  Number of 32-bit words to write
     * @parm i_data  Buffer of data to write
     *
     * @return Error from operation
     */
    errlHndl_t compareAndWriteBlock(uint32_t i_blockStart,
                                    uint32_t i_writeStart,
                                    size_t i_bytesToWrite,
                                    void* i_data);

    /**
     * @brief Determine the nearest flash address aligned to an erase block
     *
     * @parm i_address  Offset into flash
     *
     * @return Block-aligned flash address
     */
    uint32_t findEraseBlock(uint32_t i_address)
    {
        return (i_address - i_address%iv_eraseSizeBytes);
    };

    /**
     * @brief Determine the number of erase blocks that are included in
     *    the given range
     *
     * @parm i_address  Offset into flash
     * @parm i_byteSize  Number of bytes in range
     *
     * @return Number of full or partial erase blocks
     */
    uint32_t getNumAffectedBlocks(uint32_t i_address,
                                  size_t i_byteSize)
    {
        uint32_t blocks = 0;
        uint32_t addr = i_address;
        while( findEraseBlock(addr) < (i_address+i_byteSize) )
        {
            blocks++;
            addr += iv_eraseSizeBytes;
        }
        return blocks;
    };

    /**
     * @brief Returns if an operation should be retried and handles
     *        the error logs
     *
     * @pre   iv_error_recovery_failed should be 'false' before starting
     *        the retry loop as it gets checked in the function
     *
     * @parm i_op             Operation being retried
     * @parm io_err           Error log from current attempt of the operation
     * @parm io_original_err  Error log representing original error
     * @parm io_retry_count   Count of retries attempted
     *                        NOTE: count incremented when function returns true
     * @return bool           true if retry is necessary; false if not
     *
     * @post  Logic Table:
     *
     * |retries| io_err | io_original_err-     | io_retry_count | function |
     * | left  |        |  related actions     |                |  returns |
     * |-------|--------|----------------------|----------------|----------|
     * | N/A   | NULL   | if NULL then nothing | <nothing>      |  false   |
     * |       |        | if !NULL then        |                |          |
     * |       |        |  a) io_original_err  |                |          |
     * |       |        |     deleted          |                |          |
     * |       |        |  b) io_original_err  |                |          |
     * |       |        |     set to NULL      |                |          |
     * |-------|--------|----------------------|----------------|----------|
     * | No    | !NULL  | if NULL then nothing | <nothing>      |  false   |
     * |       |        | if !NULL then:       |                |          |
     * |       |        |  a) io_err committed |                |          |
     * |       |        |  b) io_err set to    |                |          |
     * |       |        |     io_original_err  |                |          |
     * |       |        |  c) io_original_err  |                |          |
     * |       |        |     set to NULL      |                |          |
     * |-------|--------|----------------------|----------------|----------|
     * | Yes   | !NULL  | if NULL then         | incremented    | true     |
     * |       |        |  a) io_err saved as  |                |          |
     * |       |        |     io_original_err  |                |          |
     * |       |        |  b) io_err set to    |                |          |
     * |       |        |     NULL             |                |          |
     * |       |        | if !NULL then        |                |          |
     * |       |        |  a) io_err info      |                |          |
     * |       |        |     added to         |                |          |
     * |       |        |     io_original_err  |                |          |
     * |       |        |  b) then io_err      |                |          |
     * |       |        |     deleted and set  |                |          |
     * |       |        |     to NULL          |                |          |
     * |-------|--------|----------------------|----------------|----------|
     *
     * NOTES: -- if iv_error_recovery_failed is set then no retries
     *        -- otherwise retries left determined by io_retry_count and
     *           PNORDD_MAX_RETRIES
     */
    bool shouldRetry( RetryOp     i_op,
                      errlHndl_t& io_err,
                      errlHndl_t& io_original_err,
                      uint8_t&    io_retry_count );


    /**
     * @brief Call SFC to write data to the PNOR flash, doing retries
     *        as needed
     * @pre Mutex should already be locked before calling
     *
     * @parm[in] i_addr  PNOR flash Address to write
     * @parm[in] i_size  Amount of data to write, in bytes.
     * @parm[in] i_data  Buffer containing data to write
     *
     * @return Error from operation
     */
    errlHndl_t _writeFlash( uint32_t i_addr,
                            size_t i_size,
                            void* i_data );

    /**
     * @brief Call SFC to read data from the PNOR flash, doing retries
     *        as needed
     * @pre Mutex should already be locked before calling
     *
     * @parm[in] i_addr  PNOR flash Address to read
     * @parm[in] i_size  Amount of data to read, in bytes.
     * @parm[out] o_data  Buffer to read data into
     *
     * @return Error from operation
     */
    errlHndl_t _readFlash( uint32_t i_addr,
                           size_t i_size,
                           void* o_data );

    /**
     * @brief Call SFC to erase the PNOR flash, doing retries
     *        as needed
     * @pre Mutex should already be locked before calling
     *
     * @parm i_address  Offset into flash to erase, aligned to erase block
     *
     * @return Error from operation
     */
    errlHndl_t _eraseFlash( uint32_t i_address );


  private: // Variables

   /**
    * @brief Global Mutex to prevent concurrent PNOR accesses to Master Proc
    *        This needs to be static so we can mutex across multiple
    *        instances of PnorDD
    */
   static mutex_t cv_mutex;

    /**
     * @brief Class Mutex used to prevent concurrent PNOR accesses
     */
    mutex_t iv_mutex;

    /**
     * @brief Mutex pointer to either class-specific or global mutex to prevent
     *        concurrent PNOR accesses.
     *        Each class uses a mutex; some share the static cv_mutex
     */
    mutex_t* iv_mutex_ptr;

    /**
     * @brief Track PNOR erases for wear monitoring
     */
    EraseInfo_t iv_erases[ERASE_COUNT_MAX];

    /**
     * @brief describes the erase block size, set based on NOR chip type
     *
     */
    uint32_t iv_eraseSizeBytes;

    /**
     * @brief CHIP ID or the NOR chip attached to SFC.
     *
     */
    uint32_t iv_norChipId;

    /**
     * @brief Associated Serial Flash Controller
     *
     */
    SfcDD* iv_sfc;

    /**
     * @brief Processor Target used to access PNOR device
     *
     */
    TARGETING::Target* iv_target;

    /**
     * @brief Remember any log that we hit during the constructor
     *
     */
    errlHndl_t iv_constructorLog;

    // Needed for testcases
    friend class PnorDdTest;
    friend class SfcIBMTest;
    friend class SfcAST2400Test;

    // let the UserDetails classes see internal structures
    friend class PNOR::UdPnorDDParms;
};


#endif
