//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/fsi/fsidd.H $
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
#ifndef __FSI_FSIDD_H
#define __FSI_FSIDD_H

#include <sys/sync.h>
#include <util/locked/list.H>
#include <list>
#include <errl/errlentry.H>
#include <usr/devicefw/driverif.H>
#include <fsi/fsiif.H>

/** @file fsidd.H
 *  @brief Provides the definition of the FSI Device Driver class
 */

//@todo - pre-declare fake attribute call
FSI::FsiChipInfo_t temp_attr_call(TARGETING::Target* i_target);

/**
 * Class to handle the FSI Master operations
 *   there will be a single instance within hostboot
 */
class FsiDD
{
  public:
    /**
     * @brief Static Initializer
     * @param[in]  Task Args pointer passed by init service
     */
    static void init( void* i_taskArgs );

    /**
     * @brief Initialize the FSI hardware
     *
     * @param[out] o_numPorts  Number of FSI ports that were
     *    successfully initialized
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t initializeHardware( uint64_t& o_numPorts );

    /**
     * @brief Performs an FSI Read Operation to an absolute address
     *
     * @param[in] i_target  Chip target of FSI operation
     * @param[in] i_address  Address to read (relative to target)
     * @param[out] o_buffer  Destination buffer for data
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t read(TARGETING::Target* i_target,
                    uint64_t i_address,
                    uint32_t* o_buffer);

    /**
     * @brief Performs an FSI Write Operation
     *
     * @param[in] i_target  Chip target of FSI operation
     * @param[in] i_address  Address to write (relative to target)
     * @param[out] i_buffer  Source buffer for data
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t write(TARGETING::Target* i_target,
                     uint64_t i_address,
                     uint32_t* i_buffer);


  protected:
    /**
     * @brief Constructor
     */
    FsiDD();


    /**
     * @brief Destructor
     */
    ~FsiDD();

    /**
     * @brief Performs an FSI Read Operation
     *
     * @param[in] i_address  Address to read (relative to FSI Master chip)
     * @param[out] o_buffer  Destination buffer for data
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t read(uint64_t i_address,
                    uint32_t* o_buffer);

    /**
     * @brief Performs an FSI Write Operation to an absolute address
     *
     * @param[in] i_address  Absolute address to write
     * @param[out] i_buffer  Source buffer for data
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t write(uint64_t i_address,
                     uint32_t* i_buffer);

    /**
     * @brief Initializes the FSI master control registers
     *
     * @param[in] i_master  Target of FSI master chip to initialize
     * @param[in] i_type  Type of FSI interface
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t initMasterControl(TARGETING::Target* i_master,
                                 FSI::MasterType i_type);


    /**
     * @brief Initializes the FSI link to allow slave access
     *
     * @param[in]  Chip target of FSI-Master 
     * @param[in]  Type of FSI-Master
     * @param[in]  FSI port (0-7) being initialized (relative to master)
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t initPort(TARGETING::Target* i_master,
                        FSI::MasterType i_type,
                        uint64_t i_port);

    /**
     * @brief Verify Request is in appropriate address range
     *
     * @param[in] i_address  Starting address (relative to FSI Device)
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t verifyAddressRange(uint64_t i_address);


    /**
     * @brief Analyze error bits and recover hardware as needed
     *
     * @param[in] i_target  Target of SCOM operation
     * @param[in] i_address  Address of FSI register being accessed
     * @param[in] i_opbStatReg  OPB Status bits (OPB_REG_STAT[0:31])
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t handleOpbErrors(TARGETING::Target* i_target,
                               uint64_t i_address,
                               uint32_t i_opbStatReg);

    /**
     * @brief  Poll for completion of a FSI operation, return data on read
     *
     * @param[in] i_address  Address of FSI register being accessed
     * @param[out] o_readData  buffer to copy read data into, set to NULL
     *       for write operations
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t pollForComplete(uint64_t i_address,
                               uint32_t* o_readData);

    /**
     * @brief Generate a complete FSI address based on the target and the
     *    FSI offset within that target
     *
     * @param[in] i_target  Target of FSI-slave, or master for control regs
     * @param[in] i_address  Address of FSI register relative to slave space
     *
     * @return uint64_t  Fully qualified FSI address
     */
    uint64_t genFullFsiAddr(TARGETING::Target* i_target,
                            uint64_t i_address);

    /**
     * @brief Generate a valid SCOM address to access the OPB, this will
     *    choosing the correct master
     *
     * @param[in] i_address  Address of OPB register relative to OPB space,
     *      e.g. OPB_REG_CMD
     *
     * @return uint64_t  Fully qualified OPB SCOM address
     */
    uint64_t genOpbScomAddr(uint64_t i_opbOffset);

    /**
     * @brief Compute a few useful FSI values based on the target of the
     *   FSI operation, this will look up some attributes under the covers.
     *
     * @param[in] i_master  Target of FSI Master
     * @param[in] i_type  Type of FSI interface
     * @param[in] i_port  FSI link number (relative to master)
     * @param[out] o_masterOffset  Address offset for master control regs
     * @param[out] o_slaveOffset  Address offset for slave regs
     * @param[out] o_portBit  1-hot bitstring with this chip's port set
     */
    void getFsiInfo( TARGETING::Target* i_master,
                     FSI::MasterType i_type,
                     uint8_t i_port,
                     uint64_t& o_masterOffset,
                     uint64_t& o_slaveOffset,
                     uint32_t& o_portBit );


    /**
     * @brief Convert a type/port pair into a FSI address offset
     *
     * @param[in] i_type  Type of FSI interface
     * @param[in] i_port  FSI link number
     * @return uint64_t  FSI address offset 
     */
    uint64_t getPortOffset(FSI::MasterType i_type,
                           uint8_t i_port);

    
    /**
     * FSI Address Space
     */
    enum FsiAddressSpace {
        // Master control registers
        CMFSI_CONTROL_REG = 0x003000, /**< cMFSI Control Register */
        MFSI_CONTROL_REG  = 0x003400, /**< MFSI Control Register */
        CONTROL_REG_MASK  = 0x003400, /**< Mask to look for a valid control register */

        // cMFSI Ports  (32KB each)
        CMFSI_PORT_0      = 0x040000, /**< cMFSI port 0 */
        CMFSI_PORT_1      = 0x048000, /**< cMFSI port 1 */
        CMFSI_PORT_2      = 0x050000, /**< cMFSI port 2 */
        CMFSI_PORT_3      = 0x058000, /**< cMFSI port 3 */
        CMFSI_PORT_4      = 0x060000, /**< cMFSI port 4 */
        CMFSI_PORT_5      = 0x068000, /**< cMFSI port 5 */
        CMFSI_PORT_6      = 0x070000, /**< cMFSI port 6 */
        CMFSI_PORT_7      = 0x078000, /**< cMFSI port 7 */
        CMFSI_PORT_MASK   = 0x078000, /**< Mask to look for a valid cMFSI port */

        // Offsets to cascaded slaves within a cMFSI port
        CMFSI_SLAVE_0     = 0x000000, /**< cMFSI - Slave 0 */
        CMFSI_SLAVE_1     = 0x002000, /**< cMFSI - Slave 1 */
        CMFSI_SLAVE_2     = 0x004000, /**< cMFSI - Slave 2 */
        CMFSI_SLAVE_3     = 0x006000, /**< cMFSI - Slave 3 */

        // MFSI Ports  (512KB each)
        MFSI_PORT_LOCAL   = 0x000000, /**< Local master (used for local cMFSI) */
        MFSI_PORT_0       = 0x080000, /**< MFSI port 0 */
        MFSI_PORT_1       = 0x100000, /**< MFSI port 1 */
        MFSI_PORT_2       = 0x180000, /**< MFSI port 2 */
        MFSI_PORT_3       = 0x200000, /**< MFSI port 3 */
        MFSI_PORT_4       = 0x280000, /**< MFSI port 4 */
        MFSI_PORT_5       = 0x300000, /**< MFSI port 5 */
        MFSI_PORT_6       = 0x380000, /**< MFSI port 6 */
        MFSI_PORT_7       = 0x400000, /**< MFSI port 7 */
        MFSI_PORT_MASK    = 0x780000, /**< Mask to look for a valid MFSI port */

        // Offsets to cascaded slaves within a MFSI port
        MFSI_SLAVE_0      = 0x000000, /**< MFSI - Slave 0 */
        MFSI_SLAVE_1      = 0x020000, /**< MFSI - Slave 1 */
        MFSI_SLAVE_2      = 0x040000, /**< MFSI - Slave 2 */
        MFSI_SLAVE_3      = 0x060000, /**< MFSI - Slave 3 */
    };


    /**
     * PIB2OPB Registers
     */
    enum Pib2OpbRegisters {
        OPB_REG_CMD   = 0x0000, /**< Command Register */
        OPB_REG_STAT  = 0x0001, /**< Status Register */
        OPB_REG_LSTAT = 0x0002, /**< Locked Status */
        // no reg for 0x0003
        OPB_REG_RES   = 0x0004, /**< Reset */
        OPB_REG_CRSIC = 0x0005, /**< cMFSI Remote Slave Interrupt Condition */
        OPB_REG_CRSIM = 0x0006, /**< cMFSI Remote Slave Interrupt Mask */
        OPB_REG_CRSIS = 0x0007, /**< cMFSI Remote Slave Interrupt Status */
        OPB_REG_RSIC  = 0x0008, /**< MFSI Remote Slave Interrupt Condition */
        OPB_REG_RSIM  = 0x0009, /**< MFSI Remote Slave Interrupt Mask */
        OPB_REG_RSIS  = 0x000A, /**< MFSI Remote Slave Interrupt Status */

        // Offsets for cMFSI
        FSI2OPB_OFFSET_0 = 0x00020010, /**< cMFSI 0 and MFSI */
        FSI2OPB_OFFSET_1 = 0x00030000, /**< cMFSI 1 */

        // Bit masks
        OPB_STAT_BUSY       = 0x00010000, /**< Bit 15 is the Busy bit */
        OPB_STAT_READ_VALID = 0x00020000, /**< Bit 14 is the Valid Read bit */
        OPB_STAT_ERR_OPB    = 0x09F00000, /**< 4,7-11 are OPB errors */
        OPB_STAT_ERR_CMFSI  = 0x0000FC00, /**< 16-21 are cMFSI errors */
        OPB_STAT_ERR_MFSI   = 0x000000FC, /**< 24-29 are MFSI errors */
        OPB_STAT_ERR_ANY    = OPB_STAT_ERR_OPB|OPB_STAT_ERR_CMFSI|OPB_STAT_ERR_MFSI,

        MAX_OPB_ATTEMPTS = 10, /**< Maximum number of attempts for OPB reg ops */        
    };

    //@todo - move to external header?
    /**
     * FSI Control Registers
     */
    enum FsiControlRegisters {
        FSI_MMODE_000   = 0x000,
        FSI_MDLYR_004   = 0x004,
        FSI_MCRSP0_008  = 0x008,
        FSI_MLEVP0_018  = 0x018,
        FSI_MSIEP0_030  = 0x030,
        FSI_MAEB_070    = 0x070,
        FSI_MRESP0_0D0  = 0x0D0,
        FSI_MRESP0_0D1  = 0x0D1,
        FSI_MRESP0_0D2  = 0x0D2,
        FSI_MRESP0_0D3  = 0x0D3,
        FSI_MRESP0_0D4  = 0x0D4,
        FSI_MRESP0_0D5  = 0x0D5,
        FSI_MRESP0_0D6  = 0x0D6,
        FSI_MRESP0_0D7  = 0x0D7,
        FSI_MECTRL_2E0  = 0x2E0
    };

    //@todo - move to external header?
    /**
     * FSI Slave Registers
     *   These registers are repeated for every master+port+cascade combo 
     */
    enum FsiSlaveRegisters {
        // Local FSI Space
        FSIS_CFG_TABLE    = 0x000000, /**< Configuration Table of CFAM */
        FSIS_PEEK_TABLE   = 0x000400, /**< Peek Table */


        FSI_SLAVE_REGS    = 0x000800, /**< FSI Slave Register */
        FSIS_MODE_00      = FSI_SLAVE_REGS| 0x00,

        FSI_SHIFT_ENGINE  = 0x000C00, /**< FSI Shift Engine (SCAN) */
        FSI2PIB_ENGINE    = 0x001000, /**< FSI2PIB Engine (SCOM) */
        FSI_SCRATCHPAD    = 0x001400, /**< FSI Scratchpad */
        FSI_I2C_MASTER    = 0x001800, /**< FSI I2C-Master */
        FSI_GEMINI_MBOX   = 0x002800, /**< FSI Gemini Mailbox with FSI GPx Registers */
    };

    /**
     * General Constants
     */
    enum Constants {
        MAX_SLAVE_PORTS = 8, /**< Maximum of 8 slave ports */
        LOCAL_MFSI_PORT_SELECT = MAX_SLAVE_PORTS + FSI::MFSI_TYPE,
        LOCAL_CMFSI_PORT_SELECT = MAX_SLAVE_PORTS + FSI::CMFSI_TYPE,
    };

    /**
     * @brief Retrieve the control register address based on type
     * @param[in] i_type  Type of FSI interface
     * @return uint64_t  FSI address offset 
     */
    uint64_t getControlReg(FSI::MasterType i_type)
    {
        uint64_t ctl_reg = MFSI_CONTROL_REG;
        if( FSI::CMFSI_TYPE == i_type )
        {
            ctl_reg = CMFSI_CONTROL_REG;
        }
        return ctl_reg;
    };

    /**
     * @brief Retrieve the slave enable index
     * @param[in] i_master  Target of FSI Master
     * @param[in] i_type  Type of FSI interface
     * @return uint64_t  Index into iv_slaves array
     */
    uint64_t getSlaveEnableIndex( TARGETING::Target* i_master,
                                  FSI::MasterType i_type )
    {
        //default to local slave ports
        uint64_t slave_index = MAX_SLAVE_PORTS+i_type;
        if( i_master != iv_master )
        {
            FSI::FsiChipInfo_t m_info = temp_attr_call(i_master);
            slave_index = m_info.port;
        }
        return slave_index;
    };

    /**
     * Global mutex   
     */
    mutex_t iv_fsiMutex;

    /**
     * Active slaves, 1 bit per port, 1=active,
     *   one entry per MFSI port, plus local MFSI and local cMFSI
     */
    uint8_t iv_slaves[MAX_SLAVE_PORTS+2];    

    /**
     * Master processor target
     */
    TARGETING::Target* iv_master;

  private:

    // let my testcase poke around
    friend class FsiDDTest;


};


#endif
