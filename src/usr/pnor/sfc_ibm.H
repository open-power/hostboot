/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/sfc_ibm.H $                                      */
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
#ifndef __PNOR_SFC_IBM_H
#define __PNOR_SFC_IBM_H

#include <limits.h>
#include <targeting/common/targetservice.H>
#include <errl/errlentry.H>
#include <lpc/lpcif.H>
#include "sfcdd.H"

/** @file sfc_ibm.H
 *  @brief Provides the logic to access and configure the
 *         IBM Serial Flash Controller which provides access
 *         to the PNOR
 */

/**
 *  @brief  IBM SFC Device Driver Class
 *     Provides the logic to access and configure the
 *     IBM Serial Flash Controller which provides access
 *     to the PNOR
 */
class SfcIBM : public SfcDD
{

  public: //SfcDD methods
    /**
     * @brief Initialize the SFC Hardware
     *
     * @return void
     */
    virtual errlHndl_t hwInit();

    /**
     * @brief Return first 3 bytes of NOR chip id
     *
     * @parm[out]  NOR chip id
     *
     * @return Error from operation
     */
    virtual errlHndl_t getNORChipId( uint32_t& o_chipId );

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
     * @brief Send a user-defined SPI command
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

  public: //SfcIBM methods
    /**
     * @brief Constructor
     * @param[out]  Return any error in constructor
     * @param[in]  Processor target associated with the LPC master
     */
    SfcIBM( errlHndl_t& o_err,
            TARGETING::Target* i_proc
            = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL );


  protected: //SfcDD methods

    /**
     * @brief Reset hardware to get into clean state
     *
     * @parm i_resetLevel    How much SFC logic to reset
     *
     * @return errlHndl_t  NULL on success, else error log
     */
    virtual errlHndl_t hwReset( ResetLevels i_resetLevel );


  protected: //SfcIBM stuff

    /** @brief General constants */
    enum
    {
        /** @brief SFC Command buffer is 0x100/256 bytes/0x40 words */
        SFC_CMDBUF_SIZE = 256,

        //@todo-RTC:95125 Find out Max time to wait
        /** @brief Max time to wait for SFC op to complete */
        SFC_POLL_TIME_NS = 1000000000,

        /** @brief Minimum increment during poll for complete */
        SFC_POLL_INCR_NS = 10,

        /** @brief Offset to SFC command regs, from FW base */
        SFC_CMDREG_OFFSET = 0x00000C00,

        /** @brief Offset to SFC buffer space, from FW base */
        SFC_CMDBUF_OFFSET = 0x00000D00,

        /** @brief Offset to SFC direct read space, from FW base */
        SFC_MMIO_OFFSET = 0x0C000000,
    };

    /**
     * @brief SFC Op Codes
     *    OP Codes for the SFC Command Register
     */
    enum SfcOpCodes {
        SFC_OP_READRAW    = 0x03, /**< Read Raw */
        SFC_OP_WRITERAW   = 0x02, /**< Write Raw */
        SFC_OP_ERASM      = 0x32, /**< Erase Small */
        SFC_OP_ERALG      = 0x34, /**< Erase Large */
        SFC_OP_ENWRITPROT = 0x53, /**< Enable WRite Protect */
        SFC_OP_CHIPID     = 0x1F, /**< Get Chip ID */
        SFC_OP_STATUS     = 0x05, /**< Get Status */
        SFC_OP_TURNOFF    = 0x5E, /**< Turn Off */
        SFC_OP_TURNON     = 0x50, /**< Turn On */
        SFC_OP_ABORT      = 0x6F, /**< Super-Abort */
        SFC_OP_START4BA   = 0x37, /**< Start 4BA */
        SFC_OP_END4BA     = 0x69, /**< End 4BA */
        SFC_OP_INVALID    = 0x00, /**< Invalid - used for testing */
    };

    //@fixme-RTC:109860 : Create structures for this data
#define SFC_REG_SPICLK_OUTDLY_SHFT 24
#define SFC_REG_SPICLK_INSAMPDLY_SHFT 16
#define SFC_REG_SPICLK_CLKHI_SHFT 8
#define SFC_REG_SPICLK_CLKLO_SHFT 0
#define SFC_REG_CONF8_CSINACTIVEREAD_SHFT 18
#define SFC_REG_CONF8_ENDUALAD_SHFT 16
#define SFC_REG_CONF8_ENDUALDAT_SHFT 13
#define SFC_REG_CONF8_DUMMY_SHFT 8
#define SFC_REG_CONF8_READOP_SHFT 0

    /**
     * @brief Ranges of SFC addresses
     */
    enum SfcRange {
        SFC_CMD_SPACE,    /**< Indicate accessing command reg */
        SFC_CMDBUF_SPACE, /**< Indicate accessing command buffer space */
        SFC_MMIO_SPACE,   /**< Indicate accessing MMIO based Direct Reads */
        SFC_LPC_SPACE,    /**< Indicate LPC Slave Space  */
    };


    /**
     * @brief SFC Registers
     *    These are offsets within the SFC Register Space
     */
    enum SfcRegAddr {
        SFC_REG_CONF    = 0x10, /**< CONF: Direct Access Configuration */
        SFC_REG_STATUS  = 0x0C, /**< STATUS : Status Reg */
        SFC_REG_SPICLK  = 0x3C, /**< SPICLK : SPI clock rate config */
        SFC_REG_CMD     = 0x40, /**< CMD : Command */
        SFC_REG_ADR     = 0x44, /**< ADR : Address */
        SFC_REG_ERASMS  = 0x48, /**< ERASMS : Small Erase Block Size */
        SFC_REG_ERASLGS = 0x4C, /**< ERALGS : Large Erase Block Size */
        SFC_REG_CONF4   = 0x54, /**< CONF4  : SPI Op Code for Small Erase */
        SFC_REG_CONF5   = 0x58, /**< CONF5  : Small Erase Size config reg */
        SFC_REG_CONF8   = 0x64, /**< CONF8  : Read Command */
        SFC_REG_ADRCBF  = 0x80, /**< ADRCBF : First Intf NOR Addr Offset */
        SFC_REG_ADRCMF  = 0x84, /**< ADRCMF : First Intf NOR Allocation */
        SFC_REG_ADRCBS  = 0x88, /**< ADRCBS : Second Intf NOR Addr Offset */
        SFC_REG_ADRCMS  = 0x8C, /**< ADRCMS : Second Intf NOR Allocation */
        SFC_REG_OADRNB  = 0x90, /**< OADRNB : Direct Access OBP Window Base Address */
        SFC_REG_OADRNS  = 0x94, /**< OADRNS : DIrect Access OPB Window Size */
        SFC_REG_CHIPIDCONF  = 0x9C, /**< CHIPIDCONF : config ChipId CMD */
        SFC_REG_ERRCONF = 0x6C, /**< ERRCONF : Configures error counts that
                                 cause interupts */
        SFC_REG_ERRTAG  = 0x1C, /**< ERRTAG : Holds Control Info of Error */
        SFC_REG_ERROFF  = 0x20, /**< ERROFF : Holds Address Info of Error */
        SFC_REG_ERRSYN  = 0x24, /**< ERRSYN : Holds Syndrome That Caused Error*/
        SFC_REG_ERRDATH = 0x28, /**< ERRDATH : Holds Most Signifcant Word of
                                 Double Word That Caused Error */
        SFC_REG_ERRDATL = 0x2C, /**< ERRDATL : Holds Least Signifcant Word of
                                 Double Word That Caused Error */
        SFC_REG_ERRCNT  = 0x30, /**< ERRCNT : Counts The Number Of Errors */
        SFC_REG_CLRCNT  = 0x34, /**< CLRCNT : Which Bits To Clear In ERRCNT */
        SFC_REG_ERRINJ  = 0x38, /**< ERRINJ : Force Errors Into Read Paths */
        SFC_REG_PROTA   = 0x70, /**< PROTA : Write Protect Range Address Base */
        SFC_REG_PROTM   = 0x74, /**< PROTM : Write Protect Range Size */
        SFC_REG_ECCADDR = 0x78, /**< ECCADDR : ECC Disable Range Base Address */
        SFC_REG_ECCRNG  = 0x7C, /**< ECCRNG : ECC Disable Range Size */
        SFC_REG_ERRORS  = 0x00, /**< ERRORS : Collection of Error Status Bits */
        SFC_REG_INTMSK  = 0x04, /**< INTMSK : Record of Events That Could Lead
                                 To Interrupt */
        SFC_REG_INTENM  = 0x14, /**< INTENM : Controls Which Events Lead
                                 To Interupts */
        SFC_REG_CONF2   = 0x18, /**< CONF2 : SPI Configuration */
        SFC_REG_CONF3   = 0x50, /**< CONF3 : SPI Recovery */

    };

    /**
     * @brief LPC Slave Registers
     *    These are offsets within the LPC Slave Register Space
     */
    enum LpcSlaveRegAddr
    {
        LPC_SLAVE_REG_STATUS  = 0x14, /**< STATUS: read-only  */
        LPC_SLAVE_REG_RESET   = 0x14, /**< RESET : write-only */
    };

    /**
     * @brief  LPC Slave Status Register Layout
     */
    union LpcSlaveStatReg_t
    {
        uint32_t data32;
        struct
        {
            uint32_t lbusowner       : 2;   /**< 0:1 = Local Bus Owner */
            uint32_t lbusparityerror : 1;   /**< 2   = Local Bus Parity Error */
            uint32_t lbus2opberr     : 3;   /**< 3:5 = Errors From LBUS2OPB */
            uint32_t unused          : 26;  /**< 6:21 = Not Currently Used */
        };
        LpcSlaveStatReg_t() : data32(0) {};
    };

    /**
     * @brief  LPC Slave Reset Register Layout
     */
    union LpcSlaveResetReg_t
    {
        uint32_t data32;
        struct
        {
            uint32_t lpcslave     : 1;  /**< 0 Reset LPC Slave */
            uint32_t lpcslaveerrs : 1;  /**< 1 Reset LPC Slave Errors */
            uint32_t localbus     : 1;  /**< 2 Reset Local Bus */
            uint32_t unused       : 29; /**< 4:31 = Not Currently Used */
        };
        LpcSlaveResetReg_t() : data32(0) {};
    };


    /**
     * @brief LPC Slave LBUS2OPB Errors
     *        Translation of LPC Slave Status Register Bits 3:5
     */
    enum LpcSlaveLbus2OpbErrors {
        LBUS2OPB_ADDR_PARITY_ERR    = 0b010, /**< Address Parity Error */
        LBUS2OPB_INVALID_SELECT_ERR = 0b001, /**< Invalid Select Error */
        LBUS2OPB_DATA_PARITY_ERR    = 0b011, /**< Data Parity Error */
        LBUS2OPB_MONITOR_ERR        = 0b100, /**< Monitor Error */
        LBUS2OPB_TIMEOUT_ERR        = 0b101, /**< Timeout Error */
    };




    /**
     * @brief  SFC Command Register Layout
     */
    union SfcCmdReg_t
    {
        uint32_t data32;
        struct
        {
            uint32_t reserved : 16; /**< 0:15 = Reserved  */
            uint32_t opcode   : 7;  /**< 16:22 = OpCode */
            uint32_t length   : 9;  /**< 22:31 = Num bytes for Read/Write Raw */
        };
        SfcCmdReg_t() : data32(0) {};
    };


    /**
     * @brief  SFC Status Register Layout
     */
    union SfcStatReg_t
    {
        uint32_t data32;
        struct
        {
            uint32_t unused     : 20; /**< 0:19 = Not Currently Used  */
            uint32_t eccerrcntr : 1;  /**< 20 Threshold for SRAM ECC errors */
            uint32_t eccues     : 1;  /**< 21 SRAM cmd uncorrectable ECC error*/
            uint32_t unused_22  : 3;  /**< 22:24 = Not Currently Used */
            uint32_t cmdexe     : 1;  /**< 25 Previous cmd is in progress */
            uint32_t cmdwait    : 1;  /**< 26 Previous cmd waiting to execute */
            uint32_t illegal    : 1;  /**< 27 Previous op illegal */
            uint32_t eccerrcntn : 1;  /**< 28 Threshold for Flash ECC errors */
            uint32_t eccuen     : 1;  /**< 29 Flash cmd uncorrectable ECC err */
            uint32_t timeout    : 1;  /**< 30 Timeout */
            uint32_t done       : 1;  /**< 31 Done */
        };
        SfcStatReg_t() : data32(0) {};
    };


    /**
     * @brief  SFC ConfId Register Layout
     */
    union SfcCustomReg_t
    {
        uint32_t data32;
        struct
        {
            uint32_t opcode    : 8;
            uint32_t read      : 1;
            uint32_t write     : 1;
            uint32_t needaddr  : 1;
            uint32_t clocks    : 5;
            uint32_t reserved  : 8;
            uint32_t length    : 8;
        };
        SfcCustomReg_t() : data32(0) {};
    };

    /**
     * @brief Write a SFC Register
     *
     * @parm i_range  SFC Address Range
     * @parm i_addr   SFC Register to write
     * @parm i_data   Data to write
     *
     * @return Error from operation
     */
    errlHndl_t writeReg(SfcRange i_range,
                        uint32_t i_addr,
                        uint32_t i_data);

    /**
     * @brief Read a SFC Register
     *
     * @parm i_range  SFC Address Range
     * @parm i_addr   SFC Register to read
     * @parm o_data   Data to write
     *
     * @return Error from operation
     */
    errlHndl_t readReg(SfcRange i_range,
                       uint32_t i_addr,
                       uint32_t& o_data);

    /**
     * @brief Poll for SFC operation to complete and look for
     *   errors
     *
     * @return Error from operation
     */
    errlHndl_t pollOpComplete( void );

    /**
     * @brief Load SFC command buffer with data from PNOR
     *
     * @parm i_addr  PNOR flash Address to read
     * @parm i_size  Number of bytes to read.to command buffer
     *
     * @return Error from operation
     */
    errlHndl_t loadSfcBuf(uint32_t i_addr,
                          size_t i_size);

    /**
     * @brief Flush SFC command buffer contents out to PNOR Flash
     *
     * @parm[in] i_addr  PNOR flash Address to write
     * @parm[in] i_size  Number of bytes to write.to command buffer
     *
     * @return Error from operation
     */
    errlHndl_t flushSfcBuf(uint32_t i_addr,
                           size_t i_size);

    /**
     * @brief Read data in SFC Command buffer and put into buffer
     *
     * @parm[in] i_size  Amount of data in Cmd Buffer to read, in bytes.
     * @parm[out] o_data  Buffer to read data into
     *
     * @return Error from operation
     */
    errlHndl_t readFromBuffer(size_t i_size,
                              void* o_data);

    /**
     * @brief Write data into SFC Command buffer
     *
     * @parm[in] i_size  Amount of data in Cmd Buffer to write, in bytes.
     * @parm[out] o_data  Buffer to read data from
     *
     * @return Error from operation
     */
    errlHndl_t writeIntoBuffer(size_t i_size,
                               void* i_data);

    /**
     * @brief Convert a SFC address to a LPC address
     *
     * @parm[in] i_sfcRange  SFC Address range
     * @parm[in] i_sfcAddr  SFC Address relative to i_sfcRange
     * @parm[out] o_lpcRange  LPC Address type
     * @parm[out] o_lpcAddr  LPC Address relative to o_lpcRange
     */
    void sfc2lpc( SfcRange i_sfcRange,
                  uint32_t i_sfcAddr,
                  LPC::TransType& o_lpcRange,
                  uint32_t& o_lpcAddr );

    /**
     * @brief Check For Errors in SFC Status Registers
     *
     * @parm o_resetLevel    if error, reset level to clear error
     * @return Error log if error found
     */
    errlHndl_t checkForErrors( ResetLevels &o_resetLevel );


    /**
     * @brief Indicates if class is currently collecting FFDC data
     */
    bool iv_ffdcActive;

    /**
     * @brief Number of times recovered from an error
     */
    uint32_t iv_errorHandledCount;

    /**
     * @brief Indicates if class is currently doing a RESET procedure
     */
    bool iv_resetActive;


    // Needed for testcases
    friend class PnorDdTest;
};


#endif
