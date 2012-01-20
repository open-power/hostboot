//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/pnor/pnordd.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#ifndef __PNOR_PNORDD_H
#define __PNOR_PNORDD_H

/** @file pnordd.H
 *  @brief Provides the interfaces to the PNOR Device Driver
 */

namespace PNOR
{

/**
 *  @brief  Type definition for PNOR address
 */
typedef uint64_t PNORAddress_t;


class PnorDD
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


  protected:
    /**
     * @brief Constructor
     */
    PnorDD();


    /**
     * @brief Destructor
     */
    ~PnorDD();

    /**
     * @brief Verify flash request is in appropriate address range
     *
     * @i_address  Flash address being operated on
     * @i_length  Length of chunk being operated on
     *
     * @return Error if requested address range is invalid
     */
    errlHndl_t verifyFlashAddressRange(uint64_t i_address,
                                       size_t& i_length);

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
     * @brief Read a LPC Host Controller Register
     *
     * @parm i_addr  Register address, relative to the
     *           LPC Host Controller Register Space
     * @parm o_data  Buffer to read data into
     *
     * @return Error from operation
     */
    errlHndl_t readRegLPC(LpcRegAddr i_addr,
                          uint32_t& o_data);

    /**
     * @brief Write a LPC Host Controller Register
     *
     * @parm i_addr  Register address, relative to the
     *           LPC Host Controller Register Space
     * @parm o_data  Data to write
     *
     * @return Error from operation
     */
    errlHndl_t writeRegLPC(LpcRegAddr i_addr,
                           uint32_t i_data);

    /**
     * @brief Read a SPI Register
     *
     * @parm i_addr  Register address, relative to the SPI engine
     * @parm o_data  Buffer to read data into
     *
     * @return Error from operation
     */
    errlHndl_t readRegSPI(uint32_t i_addr,
                          uint32_t& o_data);

    /**
     * @brief Write a SPI Register
     *
     * @parm i_addr  Register address, relative to the SPI engine
     * @parm o_data  Data to write
     *
     * @return Error from operation
     */
    errlHndl_t writeRegSPI(uint32_t i_addr,
                           uint32_t i_data);


    /**
     * @brief Some general constants
     *
     */
    enum {
        LPCHC_FW_SPACE  = 0xF0000000, /**< LPC Host Controller FW Space */
        LPCHC_MEM_SPACE = 0xE0000000, /**< LPC Host Controller Mem Space */
        LPCHC_IO_SPACE  = 0xD0010000, /**< LPC Host Controller I/O Space */
        LPCHC_REG_SPACE = 0xC0012000, /**< LPC Host Ctlr Register Space */

        ECCB_CTL_REG  = 0x000B0020, /**< ECCB Control Reg (FW) */
        ECCB_STAT_REG = 0x000B0022, /**< ECCB Status Reg (FW) */
        ECCB_DATA_REG = 0x000B0023, /**< ECCB Data Reg (FW) */

        // Default Values to set for all operations
        // 1101.0100.0000.000x.0000.0001.0000.0000.<address>
        LPC_CTL_REG_DEFAULT = 0xD400010000000000,

        LPC_STAT_REG_ERROR_MASK = 0xFC0000000007F700, /**< Error Bits */

        PNORSIZE = 3 * MEGABYTE, //@fixme - read from TOC instead
        ERASESIZE_BYTES = 4 * KILOBYTE, /**< Minimum Erase Block (bytes) */
        ERASESIZE_WORD32 = ERASESIZE_BYTES/(sizeof(uint32_t)), /**< Erase Block (32-bit words) */
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
     * @parm i_targetAddr  Starting address to write
     * @parm i_wordsToWrite  Number of 32-bit words to write
     * @parm i_data  Buffer of data to write
     *
     * @return Error from operation
     */
    errlHndl_t compareAndWriteBlock(uint32_t i_targetAddr,
                                    uint32_t i_wordsToWrite,
                                    uint32_t* i_data);

    /**
     * @brief Determine the nearest flash address aligned to an erase block
     *
     * @parm i_address  Offset into flash
     *
     * @return Block-aligned flash address
     */
    uint32_t findEraseBlock(uint32_t i_address)
    {
        return (i_address - i_address%ERASESIZE_BYTES);
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
            addr += ERASESIZE_BYTES;
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
     */
    mutex_t iv_mutex;

    /**
     * @brief Track PNOR erases for wear monitoring
     *    (making this static so tools can find it easier)
     *    track writes by page (=erase block)
     */
    uint8_t iv_erases[PNORSIZE/ERASESIZE_BYTES];
};

}; //end PNOR namespace

#endif
