/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mbox/mboxdd.C $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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
#include "mboxdd.H"
#include <mbox/mboxif.H>
#include <mbox/mbox_reasoncodes.H>
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <intr/interrupt.H>


trace_desc_t* g_trac_mbox = NULL;
TRAC_INIT(&g_trac_mbox, "MBOX", 16*KILOBYTE, TRACE::BUFFER_SLOW); //16K


namespace MBOX
{

#if defined(__DESTRUCTIVE_MBOX_TEST__)
    bool g_forceError = false;
#endif
/**
 * @brief Performs an MBOX Read Operation
 * This function performs a MBOX Read operation. It follows a pre-defined
 * prototype functions in order to be registered with the device-driver
 * framework.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        MBOX target
 * @param[in/out] io_buffer     Read: Pointer to output data storage
 *                              Write: Pointer to input data storage
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes)
 *                              Output:
 *                                  Read: Size of output data
 * @param[in]   i_accessType    DeviceFW::AccessType enum (userif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 *
 * @return  errlHndl_t
 */
errlHndl_t ddRead(DeviceFW::OperationType i_opType,
                  TARGETING::Target* i_target,
                  void* io_buffer,
                  size_t& io_buflen,
                  int64_t i_accessType,
                  va_list i_args)
{
    errlHndl_t l_err = NULL;
    uint64_t* o_status = va_arg(i_args,uint64_t*);

    do
    {
        l_err = mboxRead(i_target,io_buffer,io_buflen,o_status);
        if (l_err)
        {
            break;
        }
     } while(0);

    return l_err;
}

/**
 * @brief Performs an MBOX Write Operation
 * This function performs a MBOX Write operation. It follows a pre-defined
 * prototype functions in order to be registered with the device-driver
 * framework.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        MBOX target
 * @param[in/out] io_buffer     Read: Pointer to output data storage
 *                              Write: Pointer to input data storage
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes)
 *                              Output:
 *                                  Write: Size of data written
 * @param[in]   i_accessType    DeviceFW::AccessType enum (userif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 *
 * @return  errlHndl_t
 */
errlHndl_t ddWrite(DeviceFW::OperationType i_opType,
                  TARGETING::Target* i_target,
                  void* io_buffer,
                  size_t& io_buflen,
                  int64_t i_accessType,
                  va_list i_args)
{
    errlHndl_t l_err = NULL;

    do
    {
        l_err = mboxWrite(i_target,io_buffer,io_buflen);

        if(l_err)
        {
            break;
        }
    } while(0);

    return l_err;
}

// Register MBOXDD access functions to DD framework
DEVICE_REGISTER_ROUTE(DeviceFW::READ,
                      DeviceFW::MAILBOX,
                      TARGETING::TYPE_PROC,
                      ddRead);

DEVICE_REGISTER_ROUTE(DeviceFW::WRITE,
                      DeviceFW::MAILBOX,
                      TARGETING::TYPE_PROC,
                      ddWrite);


/**
 * @brief Performs a mailbox read operation
 */
errlHndl_t mboxRead(TARGETING::Target* i_target,void *o_buffer,
                        size_t &io_buflen,uint64_t* o_status)
{
    uint64_t l_stat = 0;
    errlHndl_t l_err = NULL;
    uint32_t l_64bitBuf[2] = {0};
    uint32_t l_StatusReg[2] = {0};
    uint32_t l_IntReg[2] = {0};
    size_t l_64bitSize = sizeof(uint64_t);
    size_t input_buflen = io_buflen;
    io_buflen = 0;

    do
    {
       // no longer check for buffer length.. MBox DD will pass back the max
       // allowed data if the buflen is > the max size.  This is done prior
       // to reading the data from the mbox registers.

        // Read the Int Reg B
        l_err = deviceOp(DeviceFW::READ,i_target,
                l_IntReg,l_64bitSize,
                DEVICE_XSCOM_ADDRESS(MBOX_DB_INT_REG_PIB));
        if (l_err)
        {
            TRACFCOMP(g_trac_mbox, ERR_MRK "mboxRead> Unable to read PIB Interrupt Register");
            break;
        }

        /*if nothing on in the interrupt reg -- nothing for this function to do*/
        if(!(l_IntReg[0]))
        {
            break;
        }

        // Check to see if there is an error bit set.
        if ((l_IntReg[0] & MBOX_DOORBELL_ERROR) ==
             MBOX_DOORBELL_ERROR)
        {
            // Go get the error info
            l_err = mboxGetErrStat(i_target,l_stat);

            if (l_err)
            {
                break;
            }
        }

#if defined(__DESTRUCTIVE_MBOX_TEST__)
        if(g_forceError)
        {
            TRACFCOMP(g_trac_mbox,"MBOXDD> forcing error!");
            g_forceError = false;
            l_stat |= MBOX_DOORBELL_ERROR | MBOX_DATA_WRITE_ERR;
        }
#endif

        // No errors so read the doorbell status and control 1a register
        l_err = deviceOp(DeviceFW::READ,i_target,
                         l_64bitBuf,l_64bitSize,
                         DEVICE_XSCOM_ADDRESS(MBOX_DB_STAT_CNTRL_1));
        if (l_err)
        {
            TRACFCOMP(g_trac_mbox, ERR_MRK "mboxRead> Unable to read Doorbell Status/Control Register");
            break;
        }
        /*
         * DB_STATUS_1A_REG: doorbell status and control 1a
         * Bit31(MSB) : Permission to Send Doorbell 1
         * Bit30 : Abort Doorbell 1
         * Bit29 : LBUS Slave B Pending Doorbell 1
         * Bit28 : PIB Slave A Pending Doorbell 1
         * Bit27 : Reserved
         * Bit26 : Xdn Doorbell 1
         * Bit25 : Xup Doorbell 1
         * Bit24 : Reserved
         * Bit23-20 : Header Count PIB Slave A Doorbell 1
         * Bit19-12 : Data Count PIB Slave A Doorbell 1
         * Bit11-8 : Header Count LBUS Slave B Doorbell 1
         * Bit7-0 : Data Count LBUS Slave B Doorbell 1
         */

        //If the Acknowledge bit is on and the Xup bit is on
        if ((l_IntReg[0] & MBOX_HW_ACK) ==
            MBOX_HW_ACK &&
            (l_64bitBuf[0] & MBOX_XUP) == MBOX_XUP)
        {
            l_stat |= MBOX_HW_ACK;
            l_StatusReg[0] |= MBOX_XUP;
        }
        //Check for PIB Pending.  If PIB pending is found then we need
        // to go read the data from the mailbox registers.
        if ((l_IntReg[0] & MBOX_DATA_PENDING) ==
             MBOX_DATA_PENDING &&
            (l_64bitBuf[0] & MBOX_PIB_SLAVE_A_PND) == MBOX_PIB_SLAVE_A_PND)
        {
            l_stat |= MBOX_DATA_PENDING;

            //Set the io_buflen to the number of bytes of data available to
            // be read.
            io_buflen = (l_64bitBuf[0] & MBOX_DATA_LBUS_SLAVE_B);

            // If the buffer length passed in is less than the data size read,
            // then set the buffer length to the passed in size and only read
            // that much data. (truncate the data to fit into the buffer)
            // Conversely, if the input_buflen is greater than the size of the
            // data read, the io_buflen returned to the user becomes the size
            // of the data read.
            if (input_buflen < io_buflen)
            {
                TRACFCOMP(g_trac_mbox, INFO_MRK

                          "mboxRead> Data truncated, input buffer length less than number of significant bytes");
                // set the io_buflen to the size of the buffer passed in.
                // which will only read enough data to fill the buffer.
                io_buflen = input_buflen;
            }

            // Current register counter indicating which of the mbox registers
            // we are currently reading from.
            uint32_t cur_reg_cntr = 0;
            uint32_t l_data[2];

            // Total number of registers to read to get all the data.
            uint8_t l_numRegsToRead = (io_buflen*sizeof(uint8_t))/sizeof(uint32_t);

            uint8_t l_numBytesLeft =
              (io_buflen*sizeof(uint8_t))%sizeof(uint32_t);

            if (l_numBytesLeft != 0)
            {
                l_numRegsToRead++;
            }

            uint32_t *local_buf = static_cast<uint32_t *>(o_buffer);
            // For the read we extract the data from the MBOX data registers.
            // MBOX_DATA_LBUS_START = 0x00050080 and the end address is
            // MBOX_DATA_LBUS_END   = 0x0005008F
            // each address between increments by 1.

            //Loop through the mbox registers until all the data to be read has
            // been extracted from the mbox registers.
            while (cur_reg_cntr < l_numRegsToRead)
            {
                l_err = deviceOp(DeviceFW::READ,i_target,
                                 l_data,l_64bitSize,
                                 DEVICE_XSCOM_ADDRESS(MBOX_DATA_LBUS_START+cur_reg_cntr));
                if (l_err)
                {
                    TRACFCOMP(g_trac_mbox, ERR_MRK "mboxRead> Unable to read Data Area Register 0x%X",MBOX_DATA_LBUS_START+cur_reg_cntr);
                    break;
                }

                // Need to check here to make sure we are not overrunning our
                // buffer.

                // If this is the last register we need to read and we are not word aligned
                if (((cur_reg_cntr + 1) == l_numRegsToRead) &&
                    (l_numBytesLeft != 0))
                {
                    // Only copy the number of bytes remaining..
                    memcpy( local_buf + cur_reg_cntr,
                            &l_data[0], l_numBytesLeft);
                }
                // normal copy path.. copy the entire word.
                else
                {
                    memcpy( local_buf + cur_reg_cntr, &l_data[0], sizeof(uint32_t));
                }

                cur_reg_cntr++;
            }
            if (l_err)
            {
                break;
            }

            //Write-to-Clear Xup,and bits 20-32 (data and header count)
            //Write to set Xup (by setting PIB_SLAVE_PND)
            //Write the Xdn to indicate read is done
            l_StatusReg[0] |= MBOX_PIB_SLAVE_A_PND | MBOX_XDN |
                              MBOX_HDR_LBUS_SLAVE_B | MBOX_DATA_LBUS_SLAVE_B;
        }


        //Write to clear PIB Pending, Abort, and XUP (all that apply)
        if(l_StatusReg[0])
        {
            l_err = deviceOp(DeviceFW::WRITE,i_target,
                             l_StatusReg,l_64bitSize,
                             DEVICE_XSCOM_ADDRESS(MBOX_DB_STAT_CNTRL_1));
            if (l_err)
            {
                TRACFCOMP(g_trac_mbox, ERR_MRK "mboxRead> Unable to clear Doorbell Status/Control Register");
                break;
            }
        }

        //Write-to-Clear 'on' bits of interrupt reg
        if(l_IntReg[0])
        {
            l_err = deviceOp(DeviceFW::WRITE,i_target,
                             l_IntReg,l_64bitSize,
                             DEVICE_XSCOM_ADDRESS(MBOX_DB_INT_REG_PIB));
            if (l_err)
            {
                TRACFCOMP(g_trac_mbox, ERR_MRK "mboxRead> Unable to clear PIB Interrupt Register");
                break;
            }
        }
    } while(0);

    (*o_status) = l_stat;


    return l_err;
}

/**
 * @brief Performs a mailbox write operation
 */
errlHndl_t mboxWrite(TARGETING::Target* i_target,void* i_buffer,
                         size_t& i_buflen)
{
    errlHndl_t l_err = NULL;
    uint32_t l_64bitBuf[2] = {0};
    size_t l_64bitSize = sizeof(uint64_t);

    do
    {
        //If the expected siZe in bytes is bigger than the max data allowed
        // send back an error.
        if (i_buflen > MBOX_MAX_DATA_BYTES)
        {
            TRACFCOMP(g_trac_mbox, ERR_MRK "MBOX::write> Invalid data length : i_buflen=%d", i_buflen);
            /*@
             * @errortype
             * @moduleid     MBOX::MOD_MBOXDD_WRITE
             * @reasoncode   MBOX::RC_INVALID_LENGTH
             * @userdata1    Target ID String...
             * @userdata2    Data Length
             * @devdesc      MboxDD::write> Invalid data length (> msg_t size)
             * @custdesc     A problem occurred during the
             *               IPL of the system.
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            MBOX::MOD_MBOXDD_WRITE,
                                            MBOX::RC_INVALID_LENGTH,
                                            TARGETING::get_huid(i_target),
                                            TO_UINT64(i_buflen),
                                            true /*Add HB Software Callout*/);

            l_err->collectTrace(MBOX_TRACE_NAME,1024);

            // Set the i_buflen to 0 to indicate no write occurred
            i_buflen = 0;

            break;
        }

        // read the DB_STATUS_1A_REG: doorbell status and control 1a
        l_err = deviceOp(DeviceFW::READ,i_target,
                         l_64bitBuf,l_64bitSize,
                         DEVICE_XSCOM_ADDRESS(MBOX_DB_STAT_CNTRL_1));
        if (l_err)
        {
            TRACFCOMP(g_trac_mbox, ERR_MRK "mboxWrite> Unable to read Doorbell Status/Control Register");
            break;
        }

        /*
         * DB_STATUS_1A_REG: doorbell status and control 1a
         * Bit31(MSB) : Permission to Send Doorbell 1
         * Bit30 : Abort Doorbell 1
         * Bit29 : LBUS Slave B Pending Doorbell 1
         * Bit28 : PIB Slave A Pending Doorbell 1
         * Bit27 : Reserved
         * Bit26 : Xdn Doorbell 1
         * Bit25 : Xup Doorbell 1
         * Bit24 : Reserved
         * Bit23-20 : Header Count PIB Slave A Doorbell 1
         * Bit19-12 : Data Count PIB Slave A Doorbell 1
         * Bit11-8 : Header Count LBUS Slave B Doorbell 1
         * Bit7-0 : Data Count LBUS Slave B Doorbell 1
         */

        //Verify There is no LBUS Pending,
        if ((l_64bitBuf[0] &
            (MBOX_LBUS_SLAVE_B_PND |  MBOX_HDR_PIB_SLAVE_A | MBOX_DATA_PIB_SLAVE_A)) == 0)
        {
            // Current register counter indicating which of the mbox registers
            // to write to
            uint32_t cur_reg_cntr = 0;
            uint32_t l_data[2] = {0};

            // Total number of registers to read to get all the data.
            uint8_t l_numRegsToWrite = (i_buflen*sizeof(uint8_t))/sizeof(uint32_t);

            uint8_t l_numBytesLeft =
              (i_buflen*sizeof(uint8_t))%sizeof(uint32_t);

            if (l_numBytesLeft != 0)
            {
                l_numRegsToWrite++;
            }

            uint32_t *l_buf = static_cast<uint32_t *>(i_buffer);

            // For the write we put the data into the MBOX data registers.
            // MBOX_DATA_PIB_START    = 0x00050040 and the end address is
            // MBOX_DATA_PIB_END      = 0x0005004F
            // each address between increments by 1.

            //Write Data registers.  Start at the first and increment through
            //the registers until all the data has been written.
            while (cur_reg_cntr < l_numRegsToWrite)
            {

                // If this is the last register we need to write and are not word aligned
                if (((cur_reg_cntr + 1) == l_numRegsToWrite) &&
                    (l_numBytesLeft != 0))
                {
                    // zero out the data reg.
                    l_data[0] = 0;

                    // Only copy the number of bytes remaining..
                    memcpy(&l_data[0], l_buf+cur_reg_cntr,l_numBytesLeft);

                }
                else
                {
                    // point to the next 32bits of data in the buffer.
                    l_data[0] = *(l_buf+cur_reg_cntr);

                }

                l_err = deviceOp(DeviceFW::WRITE,i_target,
                                 l_data,l_64bitSize,
                                 DEVICE_XSCOM_ADDRESS(MBOX_DATA_PIB_START+cur_reg_cntr));
                if (l_err)
                {
                    TRACFCOMP(g_trac_mbox, ERR_MRK "mboxWrite> Unable to write Data Area Register 0x%X",MBOX_DATA_PIB_START+cur_reg_cntr);
                    break;
                }
                //increment counter so we are at the next register
                cur_reg_cntr++;
            }
            if (l_err)
            {
                break;
            }

            //Write LBUS Pending(28) and Data Count bits(11-0) to indicate
            // data has been written.
            l_64bitBuf[0] =  MBOX_LBUS_SLAVE_B_PND | (MBOX_DATA_PIB_SLAVE_A &
                                                      (i_buflen << 12));

            l_err = deviceOp(DeviceFW::WRITE,i_target,
                             l_64bitBuf,l_64bitSize,
                             DEVICE_XSCOM_ADDRESS(MBOX_DB_STAT_CNTRL_1));

            if (l_err)
            {
                TRACFCOMP(g_trac_mbox, ERR_MRK "mboxWrite> Unable to set Doorbell Status/Control Register");
                break;
            }
        }
        else
        {
            TRACFCOMP(g_trac_mbox, ERR_MRK "mboxWrite> Message still pending : MBOX_DB_STAT_CNTRL_1=%X", l_64bitBuf[0]);
            /*@
             * @errortype
             * @moduleid     MBOX::MOD_MBOXDD_WRITE
             * @reasoncode   MBOX::RC_MSG_PENDING
             * @userdata1    Target ID String...
             * @userdata2    Status/Control Register
             * @devdesc      MboxDD::write> Message still pending
             * @custdesc     A problem occurred during the
             *               IPL of the system.
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        MBOX::MOD_MBOXDD_WRITE,
                                        MBOX::RC_MSG_PENDING,
                                        TARGETING::get_huid(i_target),
                                        reinterpret_cast<uint64_t>(l_64bitBuf),
                                        true /*Add HB Software Callout*/);

            // Set the i_buflen to 0 to indicate no write occurred
            i_buflen = 0;
            l_err->collectTrace(MBOX_TRACE_NAME,1024);
            break;
        }

    } while(0);

    return l_err;
}


/**
 * @brief Reads the mailbox PIB error status register
 */
errlHndl_t mboxGetErrStat(TARGETING::Target* i_target,uint64_t &o_status)
{
    errlHndl_t l_err = NULL;
    uint32_t l_64bitBuf[2] = {0};
    size_t l_64bitSize = sizeof(uint64_t);

    do
    {
        l_err = deviceOp(DeviceFW::READ,i_target,
                l_64bitBuf,l_64bitSize,
                DEVICE_XSCOM_ADDRESS(MBOX_DB_ERR_STAT_PIB));
        if (l_err)
        {
            TRACFCOMP(g_trac_mbox, ERR_MRK "mboxGetErrStat> Unable to read PIB Error Status");
            break;
        }
        else
        {
            TRACFCOMP(g_trac_mbox, INFO_MRK "mboxRead> Found error in pib status register (MBOX_DB_ERR_STAT_PIB): 0x%lx", l_64bitBuf[0]);

            //Check for Illegal Op
            if ((l_64bitBuf[0] & MBOX_ILLEGAL_OP) ==
                 MBOX_ILLEGAL_OP)
            {
                o_status |= MBOX_ILLEGAL_OP;
            }
            //Check for Write Full
            if ((l_64bitBuf[0] & MBOX_DATA_WRITE_ERR) ==
                 MBOX_DATA_WRITE_ERR)
            {
                o_status |= MBOX_DATA_WRITE_ERR;
            }
            //Check for Read Empty
            if ((l_64bitBuf[0] & MBOX_DATA_READ_ERR) ==
                 MBOX_DATA_READ_ERR)
            {
                o_status |= MBOX_DATA_READ_ERR;
            }
            //Check for Parity Error & add address of parity error
            if ((l_64bitBuf[0] & MBOX_PARITY_ERR) ==
                 MBOX_PARITY_ERR)
            {
                o_status |= MBOX_PARITY_ERR;
                uint64_t l_temp = (l_64bitBuf[0] & 0x00FF0000);
                o_status |= (l_temp << 40);
            }
        }
        //Write '1' to Clear Status(16)
        l_64bitBuf[0] = 0x00010000;
        l_err = deviceOp(DeviceFW::WRITE,i_target,
                l_64bitBuf,l_64bitSize,
                DEVICE_XSCOM_ADDRESS(MBOX_DB_ERR_STAT_PIB));
        if (l_err)
        {
            TRACFCOMP(g_trac_mbox, ERR_MRK "mboxGetErrStat> Unable to clear PIB Error Status");
            break;
        }

    } while(0);


    return l_err;
}


errlHndl_t mboxInit(TARGETING::Target* i_target)
{
    //For now init only enables the interrupts
    return mboxddEnableInterrupts(i_target);
}


errlHndl_t mboxddMaskInterrupts(TARGETING::Target * i_target)
{
    errlHndl_t err = NULL;

    // Mask off all interrupts
    // Reset intr enable bits by setting the bits in MBOX_DB_INT_MASK_PIB_RC
    uint64_t scom_data = (static_cast<uint64_t>(MBOX_DOORBELL_ERROR) |
                          static_cast<uint64_t>(MBOX_HW_ACK) |
                          static_cast<uint64_t>(MBOX_DATA_PENDING)) << 32;

    size_t scom_len = sizeof(uint64_t);

    err = deviceOp(DeviceFW::WRITE,
                   i_target,
                   reinterpret_cast<void*>(&scom_data),
                   scom_len,
                   DEVICE_XSCOM_ADDRESS(MBOX_DB_INT_MASK_PIB_RC));

    return err;
}

errlHndl_t mboxddEnableInterrupts(TARGETING::Target * i_target)
{
    errlHndl_t err = NULL;
    size_t scom_len = sizeof(uint64_t);

    // Setup mailbox intr mask reg
    // Set bits 2,1,0
    // assume we always use mailbox 1
    uint64_t scom_data = (static_cast<uint64_t>(MBOX_DOORBELL_ERROR) |
                          static_cast<uint64_t>(MBOX_HW_ACK) |
                          static_cast<uint64_t>(MBOX_DATA_PENDING)) << 32;

    err = deviceOp(DeviceFW::WRITE,
                   i_target,
                   reinterpret_cast<void*>(&scom_data),
                   scom_len,
                   DEVICE_XSCOM_ADDRESS(MBOX_DB_INT_MASK_PIB_RS));
    return err;
}


errlHndl_t mboxddShutDown(TARGETING::Target* i_target)
{
    size_t scom_len = sizeof(uint64_t);
    uint64_t scom_data = 0;

    errlHndl_t err = mboxddMaskInterrupts(i_target);

    if(!err)
    {
        // Clear the status reg
        //Turn off Permission to Send
        //Turn off everything possible
        err = deviceOp(DeviceFW::WRITE,
                       i_target,
                       reinterpret_cast<void*>(&scom_data),
                       scom_len,
                       DEVICE_XSCOM_ADDRESS(MBOX_DB_STAT_CNTRL_1));
    }

    // Clear any pending stuff
    if(!err)
    {
        err = deviceOp(DeviceFW::READ,
                       i_target,
                       reinterpret_cast<void*>(&scom_data),
                       scom_len,
                       DEVICE_XSCOM_ADDRESS(MBOX_DB_INT_REG_PIB));
    }

    if(!err)
    {
        err = deviceOp(DeviceFW::WRITE,
                       i_target,
                       reinterpret_cast<void*>(&scom_data),
                       scom_len,
                       DEVICE_XSCOM_ADDRESS(MBOX_DB_INT_REG_PIB));
    }

    // Others?

    return err;
}

errlHndl_t dumpMboxRegs()
{
    errlHndl_t l_err = nullptr;
    TARGETING::TargetHandleList l_procList;
    TARGETING::getAllChips( l_procList, TARGETING::TYPE_PROC);

    TRACFCOMP(g_trac_mbox, "---Dumping Mbox registers--- l_procList.size()=%d", l_procList.size());

    for( const auto l_procChip : l_procList)
    {
        uint32_t l_64bitBuf[2] = {0};
        size_t l_64bitSize = sizeof(uint64_t);
        uint32_t l_huid = TARGETING::get_huid(l_procChip);
        TRACFCOMP(g_trac_mbox, "Processor 0x%lx",l_huid);

        // Read the MBOX_DB_INT_REG_PIB
        l_err = deviceOp(DeviceFW::READ,l_procChip,
                        l_64bitBuf,l_64bitSize,
                        DEVICE_XSCOM_ADDRESS(MBOX_DB_INT_REG_PIB));
        if (l_err)
        {
            TRACFCOMP(g_trac_mbox, ERR_MRK "dumpMboxRegs> Unable to read PIB Interrupt Register");
            break;
        }
        else
        {
            TRACFCOMP(g_trac_mbox, "                 PIB Interrupt Register           (0x%08X) = 0x%08X",
                      MBOX_DB_INT_REG_PIB, l_64bitBuf[0]);
        }

        // Read the MBOX_DB_STAT_CNTRL_1
        l_err = deviceOp(DeviceFW::READ,l_procChip,
                        l_64bitBuf,l_64bitSize,
                        DEVICE_XSCOM_ADDRESS(MBOX_DB_STAT_CNTRL_1));
        if (l_err)
        {
            TRACFCOMP(g_trac_mbox, ERR_MRK "dumpMboxRegs> Unable to read Doorbell Status/Control Register");
            break;
        }
        else
        {
            TRACFCOMP(g_trac_mbox, "                 Doorbell Status/Control Register (0x%08X) = 0x%08X",
                      MBOX_DB_STAT_CNTRL_1, l_64bitBuf[0]);
        }

        // Read the MBOX_DB_ERR_STAT_PIB
        l_err = deviceOp(DeviceFW::READ,l_procChip,
                        l_64bitBuf,l_64bitSize,
                        DEVICE_XSCOM_ADDRESS( MBOX_DB_ERR_STAT_LBUS));
        if (l_err)
        {
            TRACFCOMP(g_trac_mbox, ERR_MRK "dumpMboxRegs> Unable to read Doorbell Error/Status Register");
            break;
        }
        else
        {
            TRACFCOMP(g_trac_mbox, "                 Doorbell Error/Status Register  (0x%08X)  = 0x%08lx",
                      MBOX_DB_ERR_STAT_LBUS, l_64bitBuf[0]);
        }

        for(uint8_t i = 0x0; i <= (MBOX_DATA_LBUS_END - MBOX_DATA_LBUS_START) ; i++)
        {
                // Read the MBOX_DATA_LBUS_START + i
                l_err = deviceOp(DeviceFW::READ,l_procChip,
                                l_64bitBuf,l_64bitSize,
                                DEVICE_XSCOM_ADDRESS(MBOX_DATA_LBUS_START + i));
                if (l_err)
                {
                    TRACFCOMP(g_trac_mbox, ERR_MRK "dumpMboxRegs> Unable to read MBOX_DATA_LBUS_START + %d Register", i);
                    break;
                }
                TRACFCOMP(g_trac_mbox, "                 MBOX_DATA_LBUS_START + %02d        (0x%08X) = 0x%08lx",
                          i, MBOX_DATA_LBUS_START + i , l_64bitBuf[0]);
        }
    }
    return l_err;
}

#if defined(__DESTRUCTIVE_MBOX_TEST__)
void forceErrorOnNextOperation()
{
    TRACFCOMP(g_trac_mbox,"ForceErrorOnNextOperatiron: g_forceError true");
    g_forceError = true;
}
#endif
}; //end MBOX namespace
