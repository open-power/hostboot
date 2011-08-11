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

/** @file fsidd.H
 *  @brief Provides the interfaces to the FSI Device Driver
 */

class FsiDD;

// Predeclare these so we can make them friends
namespace FSI {
errlHndl_t ddRead(DeviceFW::OperationType i_opType,
                  TARGETING::Target* i_target,
                  void* io_buffer,
                  size_t& io_buflen,
                  int64_t i_accessType,
                  va_list i_args);
errlHndl_t ddWrite(DeviceFW::OperationType i_opType,
                   TARGETING::Target* i_target,
                   void* io_buffer,
                   size_t& io_buflen,
                   int64_t i_accessType,
                   va_list i_args);
}

/**
 * Class to handle the FSI Master operations
 *   there will be one instance per master
 */
class FsiDD
{
  public:
    /**
     * @brief Performs an FSI Read Operation
     *
     * @param[in] i_address  Address to read (relative to FSI Master chip)
     * @param[in] io_buflen  Number of bytes to access, returns
     *     number of bytes actually read
     * @param[out] o_buffer  Destination buffer for data
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t read(uint64_t i_address,
                    size_t& io_buflen,
                    uint32_t* o_buffer);

    /**
     * @brief Performs an FSI Write Operation
     *
     * @param[in] i_address  Address to read (relative to FSI Master chip)
     * @param[in] io_buflen  Number of bytes to access, returns
     *     number of bytes actually written
     * @param[out] o_buffer  Source buffer for data
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t write(uint64_t i_address,
                     size_t& io_buflen,
                     uint32_t* i_buffer);

    /**
     * @brief Initializes the FSI bus for the given slave 
     *
     * @param[in]  Chip target of FSI-slave 
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t initSlave(TARGETING::Target* i_target);

  protected:
    /**
     * @brief Constructor
     *
     * @param[in]  XSCOM target associated with this FSI Master instance
     */
    FsiDD( TARGETING::Target* i_target );


    /**
     * @brief Destructor
     */
    ~FsiDD();

    /**
     * @brief Verify Request is in appropriate address range
     *
     * @param[in] i_address  Starting address (relative to FSI Device)
     * @param[in] i_length  Number of bytes being accessed
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t verifyAddressRange(uint64_t i_address,
                                  size_t i_length);

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
     * @brief Initializes the FSI master control registers
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t initMaster();

    /**
     * FSI Address Space
     */
    enum {
        // Local FSI Space
        CFAM_CONFIG_TABLE = 0x000000, /**< Configuration Table of CFAM */
        PEEK_TABLE        = 0x000400, /**< Peek Table */
        FSI_SLAVE_REG     = 0x000800, /**< FSI Slave Register */
        FSI_SHIFT_ENGINE  = 0x000C00, /**< FSI Shift Engine (SCAN) */
        FSI2PIB_ENGINE    = 0x001000, /**< FSI2PIB Engine (SCOM) */
        FSI_SCRATCHPAD    = 0x001400, /**< FSI Scratchpad */
        FSI_I2C_MASTER    = 0x001800, /**< FSI I2C-Master */
        FSI_GEMINI_MBOX   = 0x002800, /**< FSI Gemini Mailbox with FSI GPx Registers */

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
        MFSI_PORT_0       = 0x080000, /**< MFSI port 0 */
        MFSI_PORT_1       = 0x100000, /**< MFSI port 1 */
        MFSI_PORT_2       = 0x180000, /**< MFSI port 2 */
        MFSI_PORT_3       = 0x200000, /**< MFSI port 3 */
        MFSI_PORT_4       = 0x280000, /**< MFSI port 4 */
        MFSI_PORT_5       = 0x300000, /**< MFSI port 5 */
        MFSI_PORT_6       = 0x380000, /**< MFSI port 6 */
        MFSI_PORT_7       = 0x400000, /**< MFSI port 7 */
        MFSI_PORT_MASK    = 0x780000, /**< Mask to look for a valid MFSI port */
    };


    /**
     * PIB2OPB Registers
     */
    enum {
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
        OPB_STAT_READ_VALID = 0x00020000, /**< Bit 15 is the Busy bit */
        OPB_STAT_ERR_OPB    = 0x09F00000, /**< 4,7-11 are OPB errors */
        OPB_STAT_ERR_CMFSI  = 0x0000FC00, /**< 16-21 are cMFSI errors */
        OPB_STAT_ERR_MFSI   = 0x000000FC, /**< 24-29 are MFSI errors */
        OPB_STAT_ERR_ANY    = OPB_STAT_ERR_OPB|OPB_STAT_ERR_CMFSI|OPB_STAT_ERR_MFSI,

        MAX_OPB_ATTEMPTS = 10, /**< Maximum number of attempts for OPB reg ops */        
    };


    /**
     * Global mutex   @todo - make this per target for efficiency
     */
    mutex_t iv_fsiMutex;

    /**
     * Associated target of FSI Master, i.e. XSCOM target
     */
    TARGETING::Target* iv_target;

  private:

    // let my testcase poke around
    friend class FsiDDTest;


    friend errlHndl_t FSI::ddRead(DeviceFW::OperationType i_opType,
                                  TARGETING::Target* i_target,
                                  void* io_buffer,
                                  size_t& io_buflen,
                                  int64_t i_accessType,
                                  va_list i_args);
    friend errlHndl_t FSI::ddWrite(DeviceFW::OperationType i_opType,
                                   TARGETING::Target* i_target,
                                   void* io_buffer,
                                   size_t& io_buflen,
                                   int64_t i_accessType,
                                   va_list i_args);

    /**********
     * STATIC
     **********/

    /**
     * List of available instances
     */
    static std::vector<FsiDD*> cv_instances;

    /**
     * Global mutex to handle updates to gv_instances
     */
    static mutex_t cv_mux;


  public:
    /**
     * @brief Select the instance for the given target
     *
     * @param[in] i_target  TARGETING::Target* i_target
     *
     * @return FsiDD*  Pointer to instance that matches the target
     */
    static FsiDD* getInstance( TARGETING::Target* i_target );


};


#endif
