/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/sfcdd.H $                                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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
#ifndef __PNOR_SFCDD_H
#define __PNOR_SFCDD_H

#include <limits.h>
#include <targeting/common/targetservice.H>
#include <errl/errlentry.H>

/** @file sfc.H
 *  @brief Provides the logic to access and configure the
 *         Serial Flash Controller which provides access
 *         to the PNOR
 */

/**
 *  @brief  SFC Device Driver Class
 *     Provides the logic to access and configure the
 *     Serial Flash Controller which provides access
 *     to the PNOR
 */
class SfcDD
{

  public:
    /**
     * @brief Initialize the SFC Hardware
     *
     * @return void
     */
    virtual errlHndl_t hwInit() = 0;

    /**
     * @brief Return first 3 bytes of NOR chip id
     *
     * @parm[out]  NOR chip id
     *
     * @return Error from operation
     */
    virtual errlHndl_t getNORChipId( uint32_t& o_chipId );

    /**
     * @brief Return size of erase block in bytes
     * @return Size of erase block in bytes
     */
    size_t eraseSizeBytes( void )
    {
        return iv_eraseSizeBytes;
    };

    /**
     * @brief Read data from the PNOR flash
     *
     * @parm[in] i_addr  PNOR flash Address to read
     * @parm[in] i_size  Amount of data to read, in bytes.
     * @parm[out] o_data  Buffer to read data into
     *
     * @return Error from operation
     */
    virtual errlHndl_t readFlash(uint32_t i_addr,
                                 size_t i_size,
                                 void* o_data) = 0;

    /**
     * @brief Write data to the PNOR flash
     *
     * @parm[in] i_addr  PNOR flash Address to write
     * @parm[in] i_size  Amount of data to write, in bytes.
     * @parm[in] i_data  Buffer containing data to write
     *
     * @return Error from operation
     */
    virtual errlHndl_t writeFlash(uint32_t i_addr,
                                  size_t i_size,
                                  void* i_data) = 0;

    /**
     * @brief Erase a block of flash
     *
     * @parm[in] i_address  Offset into flash to erase, aligned to erase block
     *
     * @return Error from operation
     */
    virtual errlHndl_t eraseFlash(uint32_t i_address) = 0;

    /** @brief Constant for sendSpiCmd parameter */
    static const uint32_t NO_ADDRESS = UINT32_MAX;

    /**
     * @brief Send a SPI command
     *
     * @parm[in] i_opCode: command to send into controller first
     * @parm[in] i_address: address for those commands that need it
     * @parm[in] i_writeCnt: number of bytes to write to device
     * @parm[in] i_writeData: write data buffer
     * @parm[in] i_readCnt: number of bytes to read from device
     * @parm[out] o_readData: read data buffer
     *
     * @return Error from operation
     */
    virtual errlHndl_t sendSpiCmd( uint8_t i_opCode,
                                   uint32_t i_address,
                                   size_t i_writeCnt,
                                   const uint8_t* i_writeData,
                                   size_t i_readCnt,
                                   uint8_t* o_readData ) = 0;

    /**
     * @brief Informs caller if PNORDD is using
     *        L3 Cache for fake PNOR or not.
     *
     * @return Indicate state of fake PNOR usage
     *         true = using L3 Cache for fake PNOR
     *         false = not using L3 Cache for fake PNOR
     */
    virtual bool usingL3Cache( void );

    /**
     * @brief Add error registers to an existing Error Log
     *
     * @param[in] io_errhdl: Error log to add data to
     */
    virtual void addFFDC( errlHndl_t& io_errhdl )
    {
        //do nothing by default
    };

    /**
     * @brief Retrieve bitstring of NOR workarounds
     * @return NOR workarounds (see VendorWorkarounds in norflash.H)
     */
    uint32_t getNorWorkarounds( void )
    {
        return iv_flashWorkarounds;
    };

    /**
     * @brief Destructor
     */
    virtual ~SfcDD();

  protected:
    /**
     * @brief Constructor
     * @param[out]  Return any error in constructor
     * @param[in]  Processor target associated with the LPC master
     */
    SfcDD( errlHndl_t& o_err,
           TARGETING::Target* i_proc
           = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL );


    /**
     * @brief Enums for different levels of resetting PNOR communication levels
     */
    enum ResetLevels
    {
        RESET_CLEAR          = 0x00000000, /**< Clear Reset Level */
        RESET_LPC_SLAVE      = 0x00000008, /**< LPC Slave Logic on SFC */
        RESET_LPC_SLAVE_ERRS = 0x00000010, /**< LPC Slave Errors on SFC */
        RESET_SFC_LOCAL_BUS  = 0x00000020, /**< SFC Local Bus */

        // Known possible combination:
        RESET_SFCBUS_LPCSLAVE_ERRS = RESET_LPC_SLAVE_ERRS
                                     | RESET_SFC_LOCAL_BUS,
    };

    /**
     * @brief Reset hardware to get into clean state
     *
     * @parm i_resetLevel    How much SFC logic to reset
     *
     * @return errlHndl_t  NULL on success, else error log
     */
    virtual errlHndl_t hwReset( ResetLevels i_resetLevel )
    {
        //do nothing by default
        return NULL;
    };



  protected:

    /**
     * @brief Processor target associated with the LPC logic
     */
    TARGETING::Target* iv_proc;

    /**
     * @brief Hardware workarounds
     */
    uint32_t iv_flashWorkarounds;

    /**
     * @brief PNOR Chip Id
     */
    uint32_t iv_norChipId;

    /**
     * @brief describes the erase block size, set based on NOR chip type
     */
    uint32_t iv_eraseSizeBytes;


};

namespace PNOR {
/**
 * @brief Wrapper for SfcDD constructor
 */
errlHndl_t create_SfcDD( SfcDD*& o_sfc,
            TARGETING::Target* i_proc
                         = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL );
};

#endif
