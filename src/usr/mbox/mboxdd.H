/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/mbox/mboxdd.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
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
#ifndef __MBOX_MBOXDD_H
#define __MBOX_MBOXDD_H

#include <errl/errlentry.H>
#include <usr/devicefw/driverif.H>

/** @file mboxdd.H
 *  @brief Provides the interfaces to the MBOX Device Driver
 */

namespace MBOX
{
    /*
     * Mbox device driver public constants
     */
    enum 
    {
        MBOX_MAX_DATA_BYTES = 64, //16 32-bit Data Registers
    };

    /*
     * Mbox device driver status values
     */
    enum MboxReadStatus 
    {
        MBOX_DOORBELL_ERROR  = 0x00000004, /* Error Set In Error Register */
        MBOX_HW_ACK          = 0x00000002, /* LBUS Data Acknowledgment */
        MBOX_DATA_PENDING    = 0x00000001, /* PIB Data Pending */
        MBOX_ILLEGAL_OP      = 0x08000000, /* Illegal Operation Attempted */
        MBOX_DATA_WRITE_ERR  = 0x04000000, /* Write Full LBUS Mailbox Error */
        MBOX_DATA_READ_ERR   = 0x02000000, /* Read Empty LBUS Mailbox Error */
        MBOX_PARITY_ERR      = 0x01000000, /* LBUS RAM Parity Error Detected */
    };

    /**
     * @brief Initialize device driver hardware
     * 
     * @param[in] i_target, Chip target of the MBOX operation
     * @return errlHndl_t If scom error | NULL (success)
     */
     errlHndl_t mboxInit(TARGETING::Target* i_target);

     /**
      * @brief Disable the reporting of interrupts
      * @param[in] i_target, Chip target of the MBOX operations
      */
     errlHndl_t mboxddMaskInterrupts(TARGETING::Target * i_target);

     /**
      * @brief Shutdown device driver
      *
      * @param[in] i_target, Chip target of the MBOX operation
      * @return errlHndl_t if scom error | NULL (success)
      */
     errlHndl_t mboxddShutDown(TARGETING::Target* i_target);

    /**
     * @brief Performs a mailbox read operation
     *
     * @param[in] i_target - Chip target of MBOX operation
     * @param[out] o_buffer - Destination buffer for data
     * @param[in/out] io_buflen - Size of buffer
     * @param[out] o_status - Contains any error status bits
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t mboxRead(TARGETING::Target* i_target,
                        void* o_buffer,
                        size_t& io_buflen,
                        uint64_t* o_status);

    /**
     * @brief Performs a mailbox write operation
     *
     * @param[in] i_target - Chip target of MBOX operation
     * @param[in] i_buffer - Location of data to be written
     * @param[in] i_buflen - Size of data
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t mboxWrite(TARGETING::Target* i_target,
                         void* i_buffer,
                         size_t& i_buflen);

    /**
     * @brief Reads the mailbox PIB error status register
     *
     * @param[in] i_target - Chip target of MBOX operation
     * @param[out] o_status - Bits set to errors found
     */
    errlHndl_t mboxGetErrStat(TARGETING::Target* i_target,
                              uint64_t &o_status);

#if defined(__DESTRUCTIVE_MBOX_TEST__)
    void forceErrorOnNextOperation();
#endif

    //Mailbox 1 Status & Interrupt register addresses
    enum MboxRegs {
        MBOX_DB_STAT_CNTRL_1     = 0x00050020, //LBUS(rw),PIB(rw) Stat/Cntrl 1
        MBOX_DB_ERR_STAT_PIB     = 0x00050031, //LBUS(ro),PIB(rw) Err Stat B
        MBOX_DB_ERR_STAT_LBUS    = 0x00050030, //LBUS(rw),PIB(ro) Err Stat A
        MBOX_DB_INT_REG_LBUS     = 0x00050035, //LBUS(rw),PIB(ro) Int Reg A
        MBOX_DB_INT_MASK_LBUS_RS = 0x00050036, //LBUS(r/set),PIB(ro) Int Mask A
        MBOX_DB_INT_MASK_LBUS_RC = 0x00050037, //LBUS(r/clear),PIB(ro/zero)
        MBOX_DB_INT_REG_PIB      = 0x00050032, //LBUS(ro),PIB(rw) Int Reg B
        MBOX_DB_INT_MASK_PIB_RS  = 0x00050033, //LBUS(ro),PIB(r/set) Int Mask B
        MBOX_DB_INT_MASK_PIB_RC  = 0x00050034, //LBUS(ro/zero,PIB(r/clear)
    };

    //Mailbox 1 Header/Command register addresses
    enum MboxHeadCmdRegs {
        MBOX_HEAD_CMD_LBUS0   = 0x00050025, //LBUS(rw),PIB(ro) H/C 0A
        MBOX_HEAD_CMD_LBUS1   = 0x00050026, //LBUS(rw),PIB(ro) H/C 1A
        MBOX_HEAD_CMD_LBUS2   = 0x00050027, //LBUS(rw),PIB(ro) H/C 2A
        MBOX_HEAD_CMD_PIB0    = 0x00050021, //LBUS(ro),PIB(rw) H/C 0B
        MBOX_HEAD_CMD_PIB1    = 0x00050022, //LBUS(ro),PIB(rw) H/C 1B
        MBOX_HEAD_CMD_PIB2    = 0x00050023, //LBUS(ro),PIB(rw) H/C 2B
    };

    //Mailbox 1 Data register address boundaries
    enum MboxDataRegs {
        MBOX_DATA_LBUS_START   = 0x00050080, //LBUS(rw),PIB(ro) First address
        MBOX_DATA_LBUS_END     = 0x0005008F, //LBUS(rw),PIB(ro) Last address
        MBOX_DATA_PIB_START    = 0x00050040, //LBUS(ro),PIB(rw) First address
        MBOX_DATA_PIB_END      = 0x0005004F, //LBUS(ro),PIB(rw) Last address
    };

    // DB_STATUS_1A_REG: doorbell status and control 1a bit masks
    enum MboxDBStausReg1a {
        MBOX_PERM_TO_SND       = 0x80000000, //Permission to Send Doorbell
        MBOX_ABORT             = 0x40000000, //Abort Doorbell 1
        MBOX_LBUS_SLAVE_B_PND  = 0x20000000, //Lbus save B pending
        // Doorbell 1
        MBOX_PIB_SLAVE_A_PND   = 0x10000000, //PIB Slave A Pending
        // DoorBell 1
        // bit 27 - reserved
        MBOX_XDN               = 0x04000000, //Xdn Doorbell 1
        MBOX_XUP               = 0x02000000, //Xup Doorbell 1
        // bit 24 - reserved
        MBOX_HDR_PIB_SLAVE_A   = 0x00F00000, // Header Count PIB Slave A
        // Doorbell 1
        MBOX_DATA_PIB_SLAVE_A  = 0x000FF000, // Data Count PIB Slave A
        // Doorbell 1
        MBOX_HDR_LBUS_SLAVE_B  = 0x00000F00, // Header Count LBUS Slave B
        // Doorbell 1
        MBOX_DATA_LBUS_SLAVE_B =0x000000FF,  // Data Count LBUS Slave B
    };                                                    // Doorbell 1

}; // namespace MBOX

#endif
