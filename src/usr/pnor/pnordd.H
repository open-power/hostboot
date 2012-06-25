/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/pnor/pnordd.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2011-2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#ifndef __PNOR_PNORDD_H
#define __PNOR_PNORDD_H

#include <limits.h>

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

    enum PnorMode_t {
        MODEL_UNKNOWN,   /**< Invalid */
        MODEL_MEMCPY,    /**< No LPC logic, just do memcpy into cache area */
        MODEL_LPC_MEM,   /**< Break into 32-bit LPC ops but use memcpy into cache area */
        MODEL_REAL_CMD,  /**< Code for real hardware or complete sim model using Commands based reads */
        MODEL_REAL_MMIO, /**< Code for real hardware or complete sim model using MMIO reads-Not currently implemented */
    };

    /**
     * @brief Constructor
     */
    PnorDD( PnorMode_t i_mode = MODEL_UNKNOWN );


    /**
     * @brief Destructor
     */
    ~PnorDD();

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
    };
    
    /**
     * @brief SPI Config Info
     *    OP Codes and other MISC info for configuring SFC
     */
    enum SpiConfigInfo {
        SPI_GET_CHIPID_OP   = 0x9F, /**< Default Op code for getting NOR ChipID */

        SPI_SIM_SM_ERASE_OP = 0x00000020, /**< Simics Op Code for Small Erase */
        SPI_SIM_SM_ERASE_SZ = 0x1000, /**< Simics Small Erase Size */
    };

    /**
     * @brief Supported NOR Chip IDs
     *
     */
    enum NorChipIDs
    {
        SIMICS_NOR_ID     = 0x20ba2000,  /**< CHIP ID returned by Simics NOR chip */
    };


    enum SfcRange {
        SFC_CMD_SPACE,    /**< Indicate accessing command reg */
        SFC_CMDBUF_SPACE, /**< Indicate accessing command buffer space */
    };

    /**
     * @brief SFC Registers
     *    These are offsets within the SFC Register Space
     */
    enum SfcRegAddr {
        SFC_REG_CONF    = 0x10, /**< CONF: Direct Access Configuration */
        SFC_REG_STATUS  = 0x0C, /**< STATUS : Status Reg */
        SFC_REG_CMD     = 0x40, /**< CMD : Command */
        SFC_REG_ADR     = 0x44, /**< ADR : Address */
        SFC_REG_ERASMS  = 0x48, /**< ERASMS : Small Erase Block Size */
        SFC_REG_ERASLGS = 0x4C, /**< ERALGS : Large Erase Block Size */
        SFC_REG_CONF4   = 0x54, /**< CONF4  : SPI Op Code for Small Erase */
        SFC_REG_CONF5   = 0x58, /**< CONF5  : Small Erase Size config reg */
        SFC_REG_ADRCBF  = 0x80, /**< ADRCBF : First Intf NOR Addr Offset */
        SFC_REG_ADRCMF  = 0x84, /**< ADRCMF : First Intf NOR Allocation */
        SFC_REG_ADRCBS  = 0x88, /**< ADRCBS : Second Intf NOR Addr Offset */
        SFC_REG_ADRCMS  = 0x8C, /**< ADRCMS : Second Intf NOR Allocation */
        SFC_REG_OADRNB  = 0x90, /**< OADRNB : Direct Access OBP Window Base Address */
        SFC_REG_OADRNS  = 0x94, /**< OADRNS : DIrect Access OPB Window Size */


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
    };


    enum {
        SFC_CMDBUF_SIZE = 256,   /**< SFC Command buffer is 0x100/256 bytes/0x40 words */

        SFC_POLL_TIME_NS = 400000, /**< todo: Find out Max time to wait */
        SFC_POLL_INCR_NS = 10,     /**< minimum increment during poll */

    };

    /**
     * @brief  SFC Command Register Layout
     */
    union SfcCmdReg_t
    {
        uint32_t data32;
        struct
        {
            uint32_t reserved    : 16; /**< 0:15 = Reserved  */
            uint32_t opcode      : 7;  /**< 16:22 = OpCode */
            uint32_t length      : 9;  /**< 22:31 = Num bytes for ReadRaw/WriteRaw */
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
            uint32_t unused    : 30; /**< 0:29 = Not Currently Used  */
            uint32_t timeout   : 1;  /**< 30   = Timeout */
            uint32_t done      : 1;  /**< 31   = Done */
        };
        SfcStatReg_t() : data32(0) {};
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
     * @brief Poll for SFC Op Complete
     *
     * @parm i_pollTime  Amount of time to Poll, default SFC_POLL_TIME_NS
     *
     * @return Error from operation
     */
    errlHndl_t pollSfcOpComplete(uint64_t i_pollTime = SFC_POLL_TIME_NS);


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

        LPC_DIRECT_READ_OFFSET = 0xFC000000,
        LPC_SFC_CMDREG_OFFSET = 0xF0000C00,  /** LPC Offest to SFC Command Registers */
        LPC_SFC_CMDBUF_OFFSET = 0xF0000D00,  /** LPC Offest to SFC Command Buffer space */
        LPC_TOP_OF_FLASH_OFFSET = 0xFFFFFFFF,

        ECCB_CTL_REG  = 0x000B0020, /**< ECCB Control Reg (FW) */
        ECCB_STAT_REG = 0x000B0022, /**< ECCB Status Reg (FW) */
        ECCB_DATA_REG = 0x000B0023, /**< ECCB Data Reg (FW) */

        // Default Values to set for all operations
        // 1101.0100.0000.000x.0000.0001.0000.0000.<address>
        LPC_CTL_REG_DEFAULT = 0xD400010000000000,

        LPC_STAT_REG_ERROR_MASK = 0xFC0000000007F700, /**< Error Bits */

        PNORSIZE = 16 * MEGABYTE, //@fixme - read from TOC instead  (RTC: 42252)
        ERASESIZE_BYTES_DEFAULT = 4 * KILOBYTE, /**< Minimum Erase Block (bytes) */
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
     * @parm i_addr  Absolute LPC Address
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


    /**
     * @brief  ECCB Control Register Layout
     */
    union ControlReg_t
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

        ControlReg_t() : data64(LPC_CTL_REG_DEFAULT) {};            
    };

    /**
     * @brief  ECCB Status Register Layout
     */
    union StatusReg_t
    {
        uint64_t data64;
        struct
        {
            uint64_t pib_errors  : 6;  /**< 0:5  */
            uint64_t read_data   : 32; /**< 6:37 */
            uint64_t unused1     : 6;  /**< 38:43 */
            uint64_t busy        : 1;  /**< 44 = Operation Busy */
            uint64_t errors1     : 7;  /**< 45:51 */
            uint64_t op_done     : 1;  /**< 52 */
            uint64_t errors2     : 3;  /**< 53:55 */
            uint64_t unused2     : 8;  /**< 56:63 */
        };
        StatusReg_t() : data64(0) {};
    };

  private: // Variables
    /**
     * @brief Mutex to prevent concurrent PNOR accesses
     *     This needs to be static so we can mutex across multiple instances of PnorDD
     */
    static mutex_t cv_mutex;

    //TODO: Make this dynamically sized.
    /**
     * @brief Track PNOR erases for wear monitoring
     *    (making this static so tools can find it easier)
     *    track writes by page (=erase block)
     */
    uint8_t* iv_erases;

    /** 
     * @brief Determine how much of the PNOR logic to use,
     *   this is required due to different model functionality
     *   in the current VPO and Simics models
     */
    PnorMode_t iv_mode;

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
     * @brief indicates if SFC initialization has been performed.
     *
     */
    static bool cv_sfcInitDone;


    // Needed for testcases
    friend class PnorDdTest;
};


#endif
