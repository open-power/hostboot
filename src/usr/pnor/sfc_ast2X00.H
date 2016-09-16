/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/sfc_ast2X00.H $                                  */
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
#ifndef __PNOR_SFCAST2X00_H
#define __PNOR_SFCAST2X00_H

#include <limits.h>
#include <targeting/common/targetservice.H>
#include <errl/errlentry.H>
#include "sfcdd.H"
#include <config.h>

/** @file sfc_ast2X00.H
 *  @brief Provides the base logic to access and configure the
 *         AST2400 and AST2500 BMC in order to access the PNOR.
 *         Note: Where the controllers diverge, the child
 *         classes will implement the necessary functions.
 *
 *
 */

/**
 *  @brief  AST2X00 SFC Device Driver Class
 */
class SfcAST2X00 : public SfcDD
{

  public: //SfcDD methods
    /**
     * @brief Initialize the SFC Hardware
     *
     * @return void
     */
    virtual errlHndl_t hwInit() = 0;

    /**
     * @brief Read data from the PNOR flash
     *
     * @parm i_addr  PNOR flash Address to read
     * @parm i_size  Amount of data to read, in bytes.
     * @parm o_data  Buffer to read data into
     *
     * @return Error from operation
     */
    virtual errlHndl_t readFlash(uint32_t i_addr,
                                 size_t i_size,
                                 void* o_data);

    /**
     * @brief Write data to the PNOR flash
     *
     * @parm i_addr  PNOR flash Address to write
     * @parm i_size  Amount of data to write, in bytes.
     * @parm i_data  Buffer containing data to write
     *
     * @return Error from operation
     */
    virtual errlHndl_t writeFlash(uint32_t i_addr,
                                  size_t i_size,
                                  void* i_data);

    /**
     * @brief Erase a block of flash
     *
     * @parm i_address  Offset into flash to erase, aligned to erase block
     *
     * @return Error from operation
     */
    virtual errlHndl_t eraseFlash(uint32_t i_address);


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
                                   uint8_t* o_readData );

    /**
     * @brief Add error registers to an existing Error Log
     *
     * @param[in] io_errhdl: Error log to add data to
     */
    virtual void addFFDC( errlHndl_t& io_errhdl );

    /**
     *
     * @brief Function to call SIO dd for abh sio read
     *
     * @param[in]  i_ahb_sio_data - Register to read data into
     * @param[in]  i_lpc_addr - Address to read from
     * @param[out] errlHndl_t - Errorlog handle if an error occurred
     */
    virtual errlHndl_t ahbSioReadWrapper(uint32_t i_ahb_sio_data,
                                         uint32_t i_lpc_addr);

    /**
     *
     * @brief Function to call SIO dd for abh sio write
     *
     * @param[in]  i_ahb_sio_data - Register containing data to write
     * @param[in]  i_lpc_addr - Address to read from
     * @param[out] errlHndl_t - Errorlog handle if an error occurred
     */
    virtual errlHndl_t ahbSioWriteWrapper(uint32_t i_ahb_sio_data,
                                          uint32_t i_lpc_addr);

    /**
     * @brief Enter/exit command mode
     *
     * @param[in] i_enter: true=enter cmd mode, false=exit cmd mode
     *
     * @return Error from operation
     */
    virtual errlHndl_t commandMode( bool i_enter ) = 0;

  public:
    /**
     * @brief Constructor
     * @param[out]  Return any error in constructor
     * @param[in]  Processor target associated with the LPC master
     */
    SfcAST2X00( errlHndl_t& o_err,
                TARGETING::Target* i_proc
                = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL );

  protected:
    /**
     * @brief Enable write mode
     *
     * @return Error from operation
     */
    errlHndl_t enableWriteMode( void );

    /**
     * @brief Enter/exit command mode
     *
     * @param[in] i_enter: true=enter cmd mode, false=exit cmd mode
     *
     * @return Error from operation
     */

    /**
     * @brief Poll for completion of SPI operation
     *
     * @return Error from operation
     */
    errlHndl_t pollOpComplete( void );

    /**
     * @brief Prepare the iLPC2AHB address regs
     *
     * @param[in] i_addr: LPC address to access
     *
     * @return Error from operation
     */
    errlHndl_t setupAddrLPC2AHB( uint32_t i_addr );

    /** @brief General Constants */
    enum
    {
        /**< Offset to SPI Controller Register Space */
        LPC_SFC_CTLR_BASE   = 0x1E789000,

        /**< AHB address of SPI Flash controller */
        SPIC_BASE_ADDR_AHB = 0x1E630000,

        /**< AHB address of flash  */
        FLASH_BASE_ADDR_AHB = 0x30000000,

        /**< AHB address of LPC registers */
        LPC_CTLR_BASE_ADDR_AHB = 0x1E789000,

        /**< Maximum time to wait for a write/erase */
        MAX_WRITE_TIME_NS = NS_PER_SEC,

        /**< SuperIO Address Cycle */
        SIO_ADDR_2E = 0x2E,

        /**< SuperIO Data Cycle */
        SIO_DATA_2F = 0x2F,
    };
};

#endif
