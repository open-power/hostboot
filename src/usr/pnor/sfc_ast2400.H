/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/sfc_ast2400.H $                                  */
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
#ifndef __PNOR_SFCAST2400_H
#define __PNOR_SFCAST2400_H

#include <limits.h>
#include <targeting/common/targetservice.H>
#include <errl/errlentry.H>
#include "sfcdd.H"

/** @file sfc_ast2400.H
 *  @brief Provides the logic to access and configure the
 *         AST2400 BMC in order to access the PNOR
 */

/**
 *  @brief  AST2400 SFC Device Driver Class
 *    Provides the logic to access and configure the
 *    AST2400 BMC in order to access the PNOR
 */
class SfcAST2400 : public SfcDD
{

  public: //SfcDD methods
    /**
     * @brief Initialize the SFC Hardware
     *
     * @return void
     */
    virtual errlHndl_t hwInit();

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

  public:
    /**
     * @brief Constructor
     * @param[out]  Return any error in constructor
     * @param[in]  Processor target associated with the LPC master
     */
    SfcAST2400( errlHndl_t& o_err,
                TARGETING::Target* i_proc
                = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL );

  protected:
    /**
     * @brief List of registers in the SPI Controller logic
     */
    enum SpicReg_t
    {
        CONFREG_00     = 0x00,
        CTLREG_04      = 0x04,
        MISCCTLREG_10  = 0x10,
        READTIMEREG_14 = 0x14
    };

    /**
     * @brief Write a SPI Controller register
     *
     * @param[in] i_reg: Register to write
     * @param[in] i_data: Data to write
     *
     * @return Error from operation
     */
    errlHndl_t writeRegSPIC( SpicReg_t i_reg,
                             uint32_t i_data );

    /**
     * @brief Write a SPI Controller register
     *
     * @param[in] i_reg: Register to write
     * @param[in] o_data: Data that was read
     *
     * @return Error from operation
     */
    errlHndl_t readRegSPIC( SpicReg_t i_reg,
                            uint32_t& o_data );

    /**
     * @brief Write a single byte into a SIO register
     *
     * @param[in] i_reg: Register to write
     * @param[in] i_data: Data to write
     *
     * @return Error from operation
     */
    errlHndl_t writeRegSIO( uint8_t i_regAddr,
                            uint8_t i_data );

    /**
     * @brief Read a single byte from a SIO register
     *
     * @param[in] i_reg: Register to read
     * @param[in] o_data: Data that was read
     *
     * @return Error from operation
     */
    errlHndl_t readRegSIO( uint8_t i_regAddr,
                           uint8_t& o_data );

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
    errlHndl_t commandMode( bool i_enter );

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


    /**
     * @brief SPI0 Configuration Register
     */
    union SpiConfigReg00_t
    {
        uint32_t data32;
        struct
        {                             //Little-endian bit positions
            uint32_t rsvd            : 30; //31:2
            uint32_t inactiveX2mode  : 1; //1
            uint32_t enableWrite     : 1; //0
        };
        SpiConfigReg00_t() : data32(0) {};
    };

    /**
     * @brief SPI04 Control Register
     */
    union SpiControlReg04_t
    {
        uint32_t data32;
        struct
        {                             //Little-endian bit positions
            uint32_t rsvd            : 2; //31:30
            uint32_t ioMode          : 2; //29:28
            uint32_t pulseWidth      : 4; //27:24
            uint32_t cmdData         : 8; //23:16
            uint32_t dummyCycleCmd   : 1; //15
            uint32_t dummyCycleRead1 : 1; //14
            uint32_t fourByteMode    : 1; //13
            uint32_t disableCmdMerge : 1; //12
            uint32_t spiClkFreq      : 4; //11:8
            uint32_t dummyCycleRead2 : 2; //7:6
            uint32_t lsbFirst        : 1; //5
            uint32_t useClkMode3     : 1; //4
            uint32_t dualInputMode   : 1; //3
            uint32_t stopActiveCtl   : 1; //2
            uint32_t cmdMode         : 2; //1:0
        };
        SpiControlReg04_t() : data32(0) {};
    };

    /**
     * @brief Default value of SPI04 (saves a read)
     */
    SpiControlReg04_t iv_ctlRegDefault;


    /** @brief General Constants */
    enum
    {
        LPC_TOP_OF_FLASH_OFFSET = 0x0FFFFFFF,
#ifdef CONFIG_PNOR_IS_32MB
        PNOR_SIZE = 32*MEGABYTE,
#else //default to 64MB
        PNOR_SIZE = 64*MEGABYTE,
#endif
        //The direct offset value must be equal to <top of flash>-<pnor size>+1
        // for the SBE to work so we can rely on that same assertion
        /**< Offset to direct read space, from FW base */
        LPC_SFC_MMIO_OFFSET = LPC_TOP_OF_FLASH_OFFSET-PNOR_SIZE+1,

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

    friend class SfcAST2400Test;
};

#endif
