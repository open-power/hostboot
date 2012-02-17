//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/mbox/mboxdd.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
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
#ifndef __MBOX_MBOXDD_H
#define __MBOX_MBOXDD_H

#include <errl/errlentry.H>
#include <usr/devicefw/driverif.H>

/** @file mboxdd.H
 *  @brief Provides the interfaces to the MBOX Device Driver
 */
class MboxDD
{

  public:

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
    errlHndl_t read(TARGETING::Target* i_target,
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
    errlHndl_t write(TARGETING::Target* i_target,
                     void* i_buffer,
                     size_t& i_buflen);

    /**
     * @brief Reads the mailbox PIB error status register
     *
     * @param[in] i_target - Chip target of MBOX operation
     * @param[out] o_status - Bits set to errors found
     */
    errlHndl_t getErrStat(TARGETING::Target* i_target,
                          uint64_t &o_status);

  protected:

    /**
     * @brief Constructor
     */
    MboxDD();

    /**
     * @brief Destructor
     */
    ~MboxDD();

  private:

    //Mailbox 1 Status & Interrupt register addresses
    enum MboxRegs {
        MBOX_DB_STAT_CNTRL_1     = 0x00050024, //LBUS(rw),PIB(rw) Stat/Cntrl 1
        MBOX_DB_ERR_STAT_PIB     = 0x00050030, //LBUS(ro),PIB(rw) Err Stat B
        MBOX_DB_ERR_STAT_LBUS    = 0x00050031, //LBUS(rw),PIB(ro) Err Stat A
        MBOX_DB_INT_REG_LBUS     = 0x00050032, //LBUS(rw),PIB(ro) Int Reg A
        MBOX_DB_INT_MASK_LBUS_RS = 0x00050033, //LBUS(r/set),PIB(ro) Int Mask A
        MBOX_DB_INT_MASK_LBUS_RC = 0x00050034, //LBUS(r/clear),PIB(ro/zero)
        MBOX_DB_INT_REG_PIB      = 0x00050035, //LBUS(ro),PIB(rw) Int Reg B
        MBOX_DB_INT_MASK_PIB_RS  = 0x00050036, //LBUS(ro),PIB(r/set) Int Mask B
        MBOX_DB_INT_MASK_PIB_RC  = 0x00050037, //LBUS(ro/zero,PIB(r/clear)
    };

    //Mailbox 1 Header/Command register addresses
    enum MboxHeadCmdRegs {
        MBOX_HEAD_CMD_LBUS0   = 0x00050021, //LBUS(rw),PIB(ro) H/C 0A
        MBOX_HEAD_CMD_LBUS1   = 0x00050022, //LBUS(rw),PIB(ro) H/C 1A
        MBOX_HEAD_CMD_LBUS2   = 0x00050023, //LBUS(rw),PIB(ro) H/C 2A
        MBOX_HEAD_CMD_PIB0    = 0x00050025, //LBUS(ro),PIB(rw) H/C 0B
        MBOX_HEAD_CMD_PIB1    = 0x00050026, //LBUS(ro),PIB(rw) H/C 1B
        MBOX_HEAD_CMD_PIB2    = 0x00050027, //LBUS(ro),PIB(rw) H/C 2B
    };

    //Mailbox 1 Data register address boundaries
    enum MboxDataRegs {
        MBOX_DATA_LBUS_START   = 0x00050040, //LBUS(rw),PIB(ro) First address
        MBOX_DATA_LBUS_END     = 0x0005004F, //LBUS(rw),PIB(ro) Last address
        MBOX_DATA_PIB_START    = 0x00050080, //LBUS(ro),PIB(rw) First address
        MBOX_DATA_PIB_END      = 0x0005008F, //LBUS(ro),PIB(rw) Last address
    };

};

#endif
