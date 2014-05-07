/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/pnordd.H $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2014                        */
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
#include <config.h>
namespace PNOR { class UdPnorDDParms; }

/** @file pnordd.H
 *  @brief Provides the interfaces to the PNOR Device Driver
 */

/**
 *  @brief  PNOR Device Driver Class
 *     Provides access to the PNOR flash via the ECCB/LPC/SPI hardware
 */
class PnorDD
{

  public:
    /**
     * @brief Initializer called by PnorRP::init() to init the SFC
     *
     * @return void
     */
    void sfcInit( );

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


    // Enumeration values must match those in debug framework.
    enum PnorMode_t {
        MODEL_UNKNOWN,   /**< Invalid */
        MODEL_MEMCPY,    /**< No LPC logic, just do memcpy into cache area */
        MODEL_LPC_MEM,   /**< Break into 32-bit LPC ops but use fake-PNOR */
        MODEL_REAL_CMD,  /**< Code for real HW using Command based reads */
        MODEL_REAL_MMIO, /**< Code for real hardware using MMIO reads */
    };

    /**
     * @brief Constructor
     */
    PnorDD( PnorMode_t i_mode = MODEL_UNKNOWN,
            uint64_t i_fakeStart = 0,
            uint64_t i_fakeSize =  0);


    /**
     * @brief Destructor
     */
    ~PnorDD();

  protected:

    struct EraseInfo_t
    {
        uint32_t addr;  /**< Address of the erase block */
        uint32_t count;  /**< Num Erases of block */
    };

    /**
     * @brief LPC HC Registers
     *    These are offsets within the LPC Host Controller Register Space
     */
    enum LpcRegAddr {
        LPC_REG_BAR0 = 0x00, /**< BAR0 : OPB register */
        LPC_REG_BAR1 = 0x04, /**< BAR1 : LPC I/O space */
        LPC_REG_BAR2 = 0x08, /**< BAR2 : LPC Memory space */
        LPC_REG_BAR3 = 0x0C, /**< BAR3 : LPC Firmware space */
    };

    /**
     * @brief SPI Config Info
     *    OP Codes and other MISC info for configuring SFC
     */
    enum SpiConfigInfo {
        SPI_GET_CHIPID_OP   = 0x9F, /**< Default Op code for getting NOR ChipID */
        SPI_START4BA        = 0x37, /**< Enable Macronix 4-Byte addressing */

        /*
         * Micron Flash Commands
         */
        SPI_MICRON_FLAG_STAT    = 0x70, /**< Check write/erase complete */
        SPI_MICRON_CLRFLAG_STAT = 0x50, /**< Clear write/erase Status reg */
        SPI_MICRON_READ_SFDP    = 0x5A, /**< Read Serial Flash Disc Parms */
        SPI_MICRON_CHIPID       = 0x9F, /**< Read ChipID */

        /* SPI protocol command bytes */
        SPI_JEDEC_FAST_READ = 0x0B,
        SPI_JEDEC_SECTOR_ERASE = 0x20,
        SPI_JEDEC_BLOCK_ERASE = 0xD8,

        SPI_SIM_SM_ERASE_OP = 0x00000020, /**< Simics Op Code for Small Erase */
        SPI_SIM_SM_ERASE_SZ = 0x1000, /**< Simics Small Erase Size */
    };

    /**
     * @brief Supported NOR Chip IDs
     *
     */
    enum NorChipIDs
    {
        /* Note: Simics currently models Micron NOR  */
        UNKNOWN_NOR_ID    = 0,  /**< Unknown NOR chip ID */
        MICRON_NOR_ID     = 0x20ba2000,  /**< Micron NOR chip ID */
        VPO_NOR_ID        = 0x20201800,  /**< VPO NOR chip ID */
        MACRONIX_NOR_ID   = 0xC2201A00,  /**< Macronix NOR chip ID */

        ID_MASK           = 0xFFFFFF00,  /**< Only look at 3 bytes */
    };


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
        SFC_REG_SPICLK  = 0x3C, /**< SPICLK: SPI clock rate config */
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
                                              To Interupt */
        SFC_REG_INTENM  = 0x14, /**< INTENM : Controls Which Events Lead
                                              To Interupts */
        SFC_REG_CONF2   = 0x18, /**< CONF2 : SPI Configuration */
        SFC_REG_CONF3   = 0x50, /**< CONF3 : SPI Recovery */

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


    enum {
        SFC_CMDBUF_SIZE = 256,   /**< SFC Command buffer is
                                  0x100/256 bytes/0x40 words */

        //@todo-RTC:95125 Find out Max time to wait*/
        SFC_POLL_TIME_NS = 1000000000, /**< Max time to wait for SFC Op */
        SFC_POLL_INCR_NS = 10,     /**< minimum increment during poll */

    };


    /**
     * Flags used to trigger Hardware workarounds
     */
    enum {
        // Must perform 'read flag status' commands after
        //  any write or erase
        HWWK_MICRON_WRT_ERASE = 0x00000001,

        // Must do a read of a low flash address before issuing read
        //  commands that return more than 1 word of data
        HWWK_MICRON_EXT_READ  = 0x00000002,
    };

    /**
     * Enums for different levels of resetting PNOR communication levels
     */
    enum ResetLevels {
        RESET_CLEAR          = 0x00000000, /**< Clear Reset Level */
        RESET_ECCB           = 0x00000001, /**< ECCB FW Logic */
        RESET_OPB_LPCHC_SOFT = 0x00000002, /**< OPB LPCHC Clear Errors */
        RESET_OPB_LPCHC_HARD = 0x00000004, /**< OPB LPCHC Reset Logic */
        RESET_LPC_SLAVE      = 0x00000008, /**< LPC Slave Logic on SFC */
        RESET_LPC_SLAVE_ERRS = 0x00000010, /**< LPC Slave Errors on SFC */
        RESET_SFC_LOCAL_BUS  = 0x00000020, /**< SFC Local Bus */
        // Known possible combination:
        RESET_SFCBUS_LPCSLAVE_ERRS  = 0x00000030, /**< Bus and LPC Slave Errs */
    };

    /**
     * Enums for different operations that might be re-tried
     */
    enum RetryOp {
        RETRY_NOOP              = 0,
        RETRY_getNORChipId      = 1,
        RETRY_bufferedSfcRead   = 2,
        RETRY_bufferedSfcWrite  = 3,
        RETRY_eraseFlash        = 4,
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
     * @brief LPC Slave Registers
     *    These are offsets within the LPC Slave Register Space
     */
    enum LpcSlaveRegAddr {
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
     * @brief LPCHC Registers
     *    These are offsets within the LPCHC Register Space
     */
    enum LpcHcRegAddr {
        LPCHC_REG_RESET   = 0xFC, /**< RESET : write-only */
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
    errlHndl_t writeRegSfc(SfcRange i_range,
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
    errlHndl_t readRegSfc(SfcRange i_range,
                          uint32_t i_addr,
                          uint32_t& o_data);

    /**
     * @brief Read a user-defined Flash Register
     *
     * @parm i_cmd   Custom command
     * @parm o_data  Data being read
     * @parm i_addr  Address to use with command
     *
     * @return Error from operation
     */
    errlHndl_t readRegFlash(SfcCustomReg_t i_cmd,
                            uint32_t* o_data,
                            uint32_t i_addr = 0);


    /**
     * @brief Poll for SFC Op Complete
     *
     * @parm i_pollTime  Amount of time to Poll, default SFC_POLL_TIME_NS
     *
     * @return Error from operation
     */
    errlHndl_t pollSfcOpComplete(uint64_t i_pollTime = SFC_POLL_TIME_NS);

    /**
     * @brief Check flag status bit on Micron NOR chips
     *        The current version of Micron parts require the Flag
     *        Status register be read after a read or erase operation,
     *        otherwise all future operations won't work..
     *
     * @parm i_pollTime  Amount of time to Poll, default SFC_POLL_TIME_NS
     *
     * @return Error from operation
     */
    errlHndl_t micronFlagStatus(uint64_t i_pollTime = SFC_POLL_TIME_NS);

    /**
     * @brief Read the NOR FLash ChipID
     *
     * @parm o_chipId  NOR Flash ChipID
     * @parm i_spiOpcode   SPI OpCode to use to get Chip ID
     *
     * @return Error from operation
     */
    errlHndl_t getNORChipId(uint32_t& o_chipId,
                            uint32_t i_spiOpcode = SPI_GET_CHIPID_OP);

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
     * @brief Flush SFC command buffer contents to PNOR Flash
     *
     * @parm i_addr  PNOR flash Address to write
     * @parm i_size  Number of bytes to write.to command buffer
     *
     * @return Error from operation
     */
    errlHndl_t flushSfcBuf(uint32_t i_addr,
                           size_t i_size);

    /**
     * @brief Read data in SFC Command buffer and put into buffer
     *
     * @parm i_size  Amount of data in Cmd Buffer to read, in bytes.
     * @parm o_data  Buffer to read data into
     *
     * @return Error from operation
     */
    errlHndl_t readSfcBuffer(size_t i_size,
                             void* o_data);

    /**
     * @brief Write data to SFC Command buffer
     *
     * @parm i_size  Amount of data in Cmd Buffer to write, in bytes.
     * @parm o_data  Buffer to read data from
     *
     * @return Error from operation
     */
    errlHndl_t writeSfcBuffer(size_t i_size,
                              void* i_data);


    /**
     * @brief Perform command based read of PNOR, maximizing use of
     *        SFC Command buffer..
     *
     * @parm i_addr  PNOR flash Address to read
     * @parm i_size  Amount of data to read, in bytes.
     * @parm o_data  Buffer to read data into
     *
     * @return Error from operation
     */
    errlHndl_t bufferedSfcRead(uint32_t i_addr,
                               size_t i_size,
                               void* o_data);

    /**
     * @brief Perform command based write of PNOR, maximizing use of
     *        SFC Command buffer..
     *
     * @parm i_addr  PNOR flash Address to write
     * @parm i_size  Amount of data to write, in bytes.
     * @parm i_data  Buffer containing data to write
     *
     * @return Error from operation
     */
    errlHndl_t bufferedSfcWrite(uint32_t i_addr,
                                size_t i_size,
                                void* i_data);


    /**
     * @brief Some general constants
     *
     */
    enum {
        LPCHC_FW_SPACE  = 0xF0000000, /**< LPC Host Controller FW Space */
        LPCHC_MEM_SPACE = 0xE0000000, /**< LPC Host Controller Mem Space */
        LPCHC_IO_SPACE  = 0xD0010000, /**< LPC Host Controller I/O Space */
        LPCHC_REG_SPACE = 0xC0012000, /**< LPC Host Ctlr Register Space */

        LPC_SFC_CMDREG_OFFSET = 0xF0000C00, /** LPC Offest to SFC Cmd Regs */
        LPC_SFC_CMDBUF_OFFSET = 0xF0000D00, /** LPC Off to SFC Cmd Buf space */
#ifdef CONFIG_SFC_IS_AST2400
        LPC_SFC_MMIO_OFFSET = 0xFE000000, /** LPC Off to SFC Direct Read space*/
#else //default to IBM DPSS controller
        LPC_SFC_MMIO_OFFSET = 0xFC000000, /** LPC Off to SFC Direct Read space*/
#endif
        LPC_TOP_OF_FLASH_OFFSET = 0xFFFFFFFF,

        ECCB_CTL_REG    = 0x000B0020, /**< ECCB Control Reg (FW) */
        ECCB_RESET_REG  = 0x000B0021, /**< ECCB Reset Reg (FW) */
        ECCB_STAT_REG   = 0x000B0022, /**< ECCB Status Reg (FW) */
        ECCB_DATA_REG   = 0x000B0023, /**< ECCB Data Reg (FW) */

        // Default Values to set for all operations
        // 1101.0100.0000.000x.0000.0001.0000.0000.<address>
        ECCB_LPC_CTL_REG_DEFAULT = 0xD400010000000000,

        // Error bits: 41-43, 56  (52=cmd complete) (not 57: only non-fw use)
        ECCB_LPC_STAT_REG_ERROR_MASK = 0x0000000000700080, /**< Error Bits */

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
        ECCB_POLL_TIME_NS = 400000, /**< max time from Manfred Walz is 400ms */
        ECCB_POLL_INCR_NS = 10, /**< minimum increment during poll */
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
     *
     * @parm i_address  Offset into flash to erase, aligned to erase block
     *
     * @return Error from operation
     */
    errlHndl_t eraseFlash(uint32_t i_address);

    /**
     * @brief Compare the existing data in 1 erase block of the flash with
     *   the incoming data and write or erase as needed
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
        return (i_address - i_address%iv_erasesize_bytes);
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
            addr += iv_erasesize_bytes;
        }
        return blocks;
    };

    // These are used to cheat and use a chunk of our cache as a PNOR
    //   iv_mode == MODEL_MEMCPY,MODEL_LPC_MEM
    /**
     * @brief write to fake PNOR
     *
     * @parm i_pnorAddr  Offset into fake PNOR
     * @parm i_buffer  Buffer of data to write
     * @param i_size Amount to write.
     */
    void write_fake_pnor( uint64_t i_pnorAddr,
                          void* i_buffer, size_t i_size );

    /**
     * @brief Read from fake PNOR
     *
     * @parm i_pnorAddr  Offset into fake PNOR
     * @parm i_buffer  Buffer to return read data
     * @param i_size Amount to read.
     */
    void read_fake_pnor( uint64_t i_pnorAddr,
                         void* o_buffer,
                         size_t i_size );

    /**
     * @brief Erase fake PNOR
     *
     * @parm i_pnorAddr  Offset to start erase
     * @param i_size Amount to erase.
     */
    void erase_fake_pnor( uint64_t i_pnorAddr,
                          size_t i_size );

    /**
     * @brief Check For Errors in SFC Status Registers
     *
     * @parm o_pnorResetLevel    if error, reset level to clear error
     * @return Error log if error found
     */
    errlHndl_t checkForSfcErrors( ResetLevels &o_pnorResetLevel );


    /**
     * @brief Check For Errors in OPB and LPCHC Status Registers
     *
     * @parm o_pnorResetLevel    if error, reset level to clear error
     * @return Error log if error found
     */
    errlHndl_t checkForOpbErrors( ResetLevels &o_pnorResetLevel );


    /**
     * @brief Add FFDC Error Registers to an existing Error Log
     *
     * @parm io_errl    Error Log To Add FFDC To
     *
     */
    void addFFDCRegisters(errlHndl_t & io_errl);

    /**
     * @brief  ECCB Control Register Layout
     */
    union EccbControlReg_t
    {
        uint64_t data64;
        struct
        {
            // unused sections should be set to zero
            uint64_t magic1      : 8;  /**< 0:7 = b11010100 per spec */
            uint64_t unused1     : 7;  /**< 8:14 */
            uint64_t read_op     : 1;  /**< 15 = set for read operation */
            uint64_t unused2     : 7;  /**< 16:22 */
            uint64_t addr_len    : 3;  /**< 23:25 = 100 means 4 byte */
            uint64_t unused3     : 6;  /**< 26:31 */
            uint64_t address     : 32; /**< 32:63 = LPC Address */
        };

        EccbControlReg_t() : data64(ECCB_LPC_CTL_REG_DEFAULT) {};
    };

    /**
     * @brief  ECCB Status Register Layout
     */
    union EccbStatusReg_t
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
        EccbStatusReg_t() : data64(0) {};
    };


    /**
     * @brief Reset PNOR Logic At The Specified Level
     *
     * @parm i_pnorResetLevel    Level of PNOR to Reset
     *
     * @return Error log if error found
     */
    errlHndl_t resetPnor( ResetLevels i_pnorResetLevel );


    /**
     * @brief Reinitialize the SFC
     *
     * @return Error log if error found
     */
    errlHndl_t reinitializeSfc( void );


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



  private: // Variables

    // NOTE: The layout of the variables in this class must be maintained
    //       along with the offsets in the debug framework.

    /**
     * @brief Mutex to prevent concurrent PNOR accesses
     *     This needs to be static so we can mutex across multiple instances of PnorDD
     */
    static mutex_t cv_mutex;

    /**
     * @brief Track PNOR erases for wear monitoring
     */
    EraseInfo_t iv_erases[ERASE_COUNT_MAX];

    /**
     * @brief Determine how much of the PNOR logic to use,
     *   this is required due to different model functionality
     *   in the current VPO and Simics models
     */
    PnorMode_t iv_mode;

    /**
     * @brief Flag to drive special behavior in VPO.
     */
     static uint64_t iv_vpoMode;

    /**
     * @brief describes the erase block size, set based on NOR chip type
     *
     */
    uint32_t iv_erasesize_bytes;

    /**
     * @brief CHIP ID or the NOR chip attached to SFC.
     *
     */
    static uint32_t cv_nor_chipid;

    /**
     * @brief Hardware workarounds
     *
     */
    static uint32_t cv_hw_workaround;

    /**
     * @brief indicates if SFC initialization has been performed.
     *
     */
    static bool cv_sfcInitDone;

    /**
     * @brief Start of Fake PNOR address range..
     *
     */
    uint64_t iv_fakeStart;

    /**
     * @brief Size of Fake PNOR address range..
     *
     */
    uint64_t iv_fakeSize;

    /**
     * @brief Indicates if class is currently collecting FFDC data
     *
     */
    bool iv_ffdc_active;

    /**
     * @brief Number of times recovered from an error
     *
     */
    uint32_t iv_error_handled_count;

    /**
     * @brief Indicates recovery from an error has failed
     *
     */
    bool iv_error_recovery_failed;

    /**
     * @brief Indicates if class is currently doing a RESET procedure
     *
     */
    bool iv_reset_active;

    // Needed for testcases
    friend class PnorDdTest;

    // let the UserDetails classes see internal structures
    friend class PNOR::UdPnorDDParms;
};


#endif
