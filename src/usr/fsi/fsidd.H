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
#include <attributestructs.H>


/** @file fsidd.H
 *  @brief Provides the definition of the FSI Device Driver class
 */

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
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t initializeHardware();

    /**
     * @brief Performs an FSI Read Operation to an absolute address
     *
     * @param[in] i_target  Chip target of FSI operation
     * @param[in] i_address  Address to read (relative to target)
     * @param[out] o_buffer  Destination buffer for data
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t read(const TARGETING::Target* i_target,
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
    errlHndl_t write(const TARGETING::Target* i_target,
                     uint64_t i_address,
                     uint32_t* i_buffer);


    /**
     * @brief Retrieves the status of a given port
     *
     * @param[in] i_fsiMaster  FSI Master chip
     * @param[in] i_type  FSI Master Type (MFSI or cMFSI)
     * @param[in] i_port  Slave port number
     * 
     * @return bool  true if port sensed as active during FSI initialization
     */
    bool isSlavePresent( const TARGETING::Target* i_fsiMaster,
                         TARGETING::FSI_MASTER_TYPE i_type,
                         uint8_t i_port );

    /**
     * @brief Retrieves the FSI status of a given chip
     *
     * @param[in] i_target
     * 
     * @return bool  true if port sensed as active during FSI initialization
     */
    bool isSlavePresent( const TARGETING::Target* i_target );

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
     * @brief Performs an FSI Read Operation to an absolute address
     *   using the master processor chip to drive it
     *
     * @param[in] i_address  Absolute FSI address to read relative to
     *     the master processor chip
     * @param[out] o_buffer  Destination buffer for data
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t read(uint64_t i_address,
                    uint32_t* o_buffer);

    /**
     * @brief Performs an FSI Write Operation to an absolute address
     *   using the master processor chip to drive it
     *
     * @param[in] i_address  Absolute FSI address to write relative to
     *     the master processor chip
     * @param[out] i_buffer  Source buffer for data
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t write(uint64_t i_address,
                     uint32_t* i_buffer);

    /**
     * @brief Holds a set of addressomg information to describe the 
     *   current FSI operation 
     */
    struct FsiAddrInfo_t {
        const TARGETING::Target* fsiTarg; ///< Target of FSI operation
        TARGETING::Target* opbTarg; ///< OPB control reg target
        uint32_t relAddr; ///< Input FSI address (relative to fsiTarg)
        uint32_t absAddr; ///< Absolute FSI address (relative to opbTarg)

        /** Input Arg Constructor */
        FsiAddrInfo_t( const TARGETING::Target* i_target,
                       uint64_t i_address ) :
          fsiTarg(i_target), opbTarg(NULL),
        relAddr(i_address), absAddr(0xFFFFFFFF)
        {};

      private:
        /** Default Constructor is not allowed */
        FsiAddrInfo_t() :
          fsiTarg(NULL), opbTarg(NULL), 
        relAddr(0xFFFFFFFF),absAddr(0xFFFFFFFF)
        {};        
    };

    /**
     * @brief Performs an FSI Read Operation
     *
     * @param[in] i_addrInfo  Addressing information
     * @param[out] o_buffer  Destination buffer for data
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t read(const FsiAddrInfo_t& i_addrInfo,
                    uint32_t* o_buffer);

    /**
     * @brief Performs an FSI Write Operation to an absolute address
     *
     * @param[in] i_addrInfo  Addressing information
     * @param[out] i_buffer  Source buffer for data
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t write(const FsiAddrInfo_t& i_addrInfo,
                     uint32_t* i_buffer);

    /**
     * @brief Initializes the FSI master control registers
     *
     * @param[in] i_master  Target of FSI master chip to initialize
     * @param[in] i_type  Type of FSI interface
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t initMasterControl(const TARGETING::Target* i_master,
                                 TARGETING::FSI_MASTER_TYPE i_type);

    /**
     * Common id to identify a FSI position to use in error logs and traces
     */
    union FsiLinkId_t
    {
        uint32_t id;
        struct
        {
            uint8_t node; ///< Physical Node of FSI Master processor
            uint8_t proc; ///< Physical Position of FSI Master processor
            uint8_t type; ///< FSI Master type (FSI_MASTER_TYPE)
            uint8_t port; ///< Slave link/port number
        };
    };

    /**
     * @brief Structure which defines info necessary to access a chip via FSI
     */
    struct FsiChipInfo_t
    {
        TARGETING::Target* master; ///< FSI Master  
        TARGETING::FSI_MASTER_TYPE type; ///< Master or Cascaded Master
        uint8_t port; ///< Which port is this chip hanging off of 
        uint8_t cascade; ///< Slave cascade position
        uint16_t flags; ///< Reserved for any special flags we might need
        FsiLinkId_t linkid; ///< Id for traces and error logs
    };


    /**
     * @brief Initializes the FSI link to allow slave access
     *
     * @param[in] i_fsiInfo  FSI Chip Information for the slave port
     *    that is being initialized
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t initPort(FsiChipInfo_t i_fsiInfo,
                        bool& o_enabled);

    /**
     * @brief Analyze error bits and recover hardware as needed
     *
     * @param[in] i_addrInfo  FSI addressing information
     * @param[in] i_opbStatReg  OPB Status bits (OPB_REG_STAT[0:31])
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t handleOpbErrors(const FsiAddrInfo_t& i_addrInfo,
                               uint32_t i_opbStatReg);

    /**
     * @brief  Poll for completion of a FSI operation, return data on read
     *
     * @param[in] i_addrInfo  FSI addressing information
     * @param[out] o_readData  buffer to copy read data into, set to NULL
     *       for write operations
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t pollForComplete(const FsiAddrInfo_t& i_addrInfo,
                               uint32_t* o_readData);

    /**
     * @brief Figure out the optimal OPB Master to use and generate a
     *    complete FSI address relative to that master based on the target
     *    and the FSI offset within that target
     *
     * @param[inout] io_addrInfo  FSI addressing information,
     *     expects fsiTarg and relAddr to be populated as input
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t genFullFsiAddr(FsiAddrInfo_t& io_addrInfo);

    /**
     * @brief Generate a valid SCOM address to access the OPB, this will
     *    choose the correct master
     *
     * @param[in] i_addrInfo  FSI  data
     * @param[in] i_address  Address of OPB register relative to OPB space,
     *      e.g. OPB_REG_CMD
     *
     * @return uint64_t  Fully qualified OPB SCOM address
     */
    uint64_t genOpbScomAddr(const FsiAddrInfo_t& i_addrInfo,
                            uint64_t i_opbOffset);


    /**
     * @brief Convert a type/port pair into a FSI address offset
     *
     * @param[in] i_type  Type of FSI interface
     * @param[in] i_port  FSI link number
     * @return uint64_t  FSI address offset 
     */
    uint64_t getPortOffset(TARGETING::FSI_MASTER_TYPE i_type,
                           uint8_t i_port);

    
    /**
     * FSI Address Space
     */
    enum FsiAddressSpace {
        // Master control registers
        CMFSI_CONTROL_REG = 0x003000, /**< cMFSI Control Register */
        MFSI_CONTROL_REG  = 0x003400, /**< MFSI Control Register */

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
    };

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


    /**
     * General Constants
     */
    enum Constants {
        MAX_SLAVE_PORTS = 8, /**< Maximum of 8 slave ports */
        LOCAL_MFSI_PORT_SELECT = MAX_SLAVE_PORTS + TARGETING::FSI_MASTER_TYPE_MFSI,
        LOCAL_CMFSI_PORT_SELECT = MAX_SLAVE_PORTS + TARGETING::FSI_MASTER_TYPE_CMFSI,
        INVALID_SLAVE_INDEX = 0x12345678
    };

    /**
     * @brief Retrieve the control register address based on type
     * @param[in] i_type  Type of FSI interface
     * @return uint64_t  FSI address offset 
     */
    uint64_t getControlReg(TARGETING::FSI_MASTER_TYPE i_type)
    {
        uint64_t ctl_reg = MFSI_CONTROL_REG;
        if( TARGETING::FSI_MASTER_TYPE_CMFSI == i_type )
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
    uint64_t getSlaveEnableIndex( const TARGETING::Target* i_master,
                                  TARGETING::FSI_MASTER_TYPE i_type );

    /**
     * @brief Retrieve the connection information needed to access FSI
     *        registers within the given chip target
     *
     * @param[in] i_target  Target of FSI Slave to access
     *
     * @return FsiChipInfo_t  FSI Chip Information
     */
    FsiChipInfo_t getFsiInfo( const TARGETING::Target* i_target );



    /********************************************
     * VARIABLES
     ********************************************/

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
