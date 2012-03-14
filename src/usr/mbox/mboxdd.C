//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/mbox/mboxdd.C $
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
#include "mboxdd.H"
#include <mbox/mboxif.H>
#include <mbox/mbox_reasoncodes.H>
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <targeting/targetservice.H>

using namespace MBOX;

trace_desc_t* g_trac_mbox = NULL;
TRAC_INIT(&g_trac_mbox, "MBOX", 4096); //4K

//TODO - May or may not be necessary for MBOX error logs
uint64_t target_to_uint64(const TARGETING::Target* i_target)
{
    uint64_t id = 0;
    if( i_target == NULL )
    {
        id = 0x0;
    }
    else if( i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL )
    {
        id = 0xFFFFFFFFFFFFFFFF;
    }
    else
    {
        // physical path, 3 nibbles per type/instance pair
        //   TIITIITII... etc.
        TARGETING::EntityPath epath;
        i_target->tryGetAttr<TARGETING::ATTR_PHYS_PATH>(epath);
        for( uint32_t x = 0; x < epath.size(); x++ )
        {
            id = id << 12;
            id |= (uint64_t)((epath[x].type << 8) & 0xF00);
            id |= (uint64_t)(epath[x].instance & 0x0FF);
        }
    }
    return id;
}

namespace MBOX
{

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
 *                                  Write: Size of data written
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
        l_err = Singleton<MboxDD>::instance().read(i_target,io_buffer,
                                                   io_buflen,o_status);
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
 *                                  Read: Size of output data
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
        l_err = Singleton<MboxDD>::instance().write(i_target,io_buffer,
                                                    io_buflen);
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

}; //end MBOX namespace

/**
 * @brief Performs a mailbox read operation
 */
errlHndl_t MboxDD::read(TARGETING::Target* i_target,void *o_buffer,
                        size_t &io_buflen,uint64_t* o_status)
{
    uint64_t l_stat = 0;
    errlHndl_t l_err = NULL;
    uint32_t l_64bitBuf[2] = {0};
    uint32_t l_StatusReg[2] = {0};
    uint32_t l_IntReg[2] = {0};
    size_t l_64bitSize = sizeof(uint64_t);
    size_t buflen = io_buflen;
    io_buflen = 0;

    do
    {
        if (MBOX_MAX_DATA_BYTES < buflen)
        {
            TRACFCOMP(g_trac_mbox, ERR_MRK "MBOX::read> Invalid data length : io_buflen=%d", buflen);
            /*@
             * @errortype
             * @moduleid     MBOX::MOD_MBOXDD_READ
             * @reasoncode   MBOX::RC_INVALID_LENGTH
             * @userdata1    Target ID String...
             * @userdata2    Data Length
             * @devdesc      MboxDD::read> Invalid data length (< msg_t size)
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    MBOX::MOD_MBOXDD_READ,
                    MBOX::RC_INVALID_LENGTH,
                    target_to_uint64(i_target),
                    TO_UINT64(buflen));
            l_err->collectTrace("MBOX",1024);
            break;
        }

        l_err = deviceOp(DeviceFW::READ,i_target,
                l_IntReg,l_64bitSize,
                DEVICE_XSCOM_ADDRESS(MBOX_DB_INT_REG_PIB));
        if (l_err)
        {
            TRACFCOMP(g_trac_mbox, ERR_MRK "MBOX::read> Unable to read PIB Interrupt Register");
            break;
        }

        /*if nothing on in the interrupt reg -- nothing for this function to do*/
        if(!(l_IntReg[0]))
        {
            break;
        }

        if ((l_IntReg[0] & MBOX_DOORBELL_ERROR) ==
             MBOX_DOORBELL_ERROR)
        {
            TRACFCOMP(g_trac_mbox, INFO_MRK "MBOX::read> Found interrupt on error status register");
            l_err = getErrStat(i_target,l_stat);
            if (l_err)
            {
                break;
            }
        }

        l_err = deviceOp(DeviceFW::READ,i_target,
                         l_64bitBuf,l_64bitSize,
                         DEVICE_XSCOM_ADDRESS(MBOX_DB_STAT_CNTRL_1));
        if (l_err)
        {
            TRACFCOMP(g_trac_mbox, ERR_MRK "MBOX::read> Unable to read Doorbell Status/Control Register");
            break;
        }
        /*
         * DB_STATUS_1A_REG: doorbell status and control 1a
         * Bit31(MSB) : Permission to Send Doorbell 1
         * Bit30 : Abort Doorbell 1
         * Bit29 : PIB Slave B Pending Doorbell 1
         * Bit28 : LBUS Slave A Pending Doorbell 1
         * Bit27 : Reserved
         * Bit26 : Xdn Doorbell 1
         * Bit25 : Xup Doorbell 1
         * Bit24 : Reserved
         * Bit23-20 : Header Count LBUS Slave A Doorbell 1
         * Bit19-12 : Data Count LBUS Slave A Doorbell 1
         * Bit11-8 : Header Count PIB Slave B Doorbell 1
         * Bit7-0 : Data Count PIB Slave B Doorbell 1
         */
        //Check for Abort
        if ((l_IntReg[0] & MBOX_ABORT_LAST_MSG) ==
            MBOX_ABORT_LAST_MSG &&
            (l_64bitBuf[0] & 0x40000000) == 0x40000000)
        {
            l_stat |= MBOX_ABORT_LAST_MSG;
            l_StatusReg[0] |= 0x40000000;
        }
        //Check for Xdn
        if ((l_IntReg[0] & MBOX_XDN_ACK) ==
            MBOX_XDN_ACK &&
            (l_64bitBuf[0] & 0x04000000) == 0x04000000)
        {
            l_stat |= MBOX_XDN_ACK;
            l_StatusReg[0] |= 0x04000000;
        }
        //Check for PIB Pending
        if ((l_IntReg[0] & MBOX_DATA_PENDING) ==
             MBOX_DATA_PENDING &&
            (l_64bitBuf[0] & 0x20000000) == 0x20000000)
        {
            l_stat |= MBOX_DATA_PENDING;
            //Read how many bytes are significant
            io_buflen = ((l_64bitBuf[0] & 0x000FF000) >> 12);
            if (buflen < io_buflen)
            {
                TRACFCOMP(g_trac_mbox, INFO_MRK "MBOX::read> Data truncated, input buffer length less than number of significant bytes");
                io_buflen = buflen;
            }
            uint32_t i = 0;
            uint32_t l_data[2];
            uint8_t l_numRegs = (io_buflen*sizeof(uint8_t))/sizeof(uint32_t);
            if ((io_buflen*sizeof(uint8_t))%sizeof(uint32_t) != 0) l_numRegs++;
            uint8_t *l_buf = static_cast<uint8_t *>(o_buffer);
            //Extract Data
            while (i < l_numRegs)
            {
                l_err = deviceOp(DeviceFW::READ,i_target,
                        l_data,l_64bitSize,
                        DEVICE_XSCOM_ADDRESS(MBOX_DATA_LBUS_START+i));
                if (l_err)
                {
                    TRACFCOMP(g_trac_mbox, ERR_MRK "MBOX::read> Unable to read Data Area Register 0x%X",MBOX_DATA_LBUS_START+i);
                    break;
                }
                //TODO Use memcpy() since byte aligned?
                for (uint8_t byteNum = 0;byteNum<sizeof(uint32_t);++byteNum)
                {
                    *(l_buf+(byteNum+i*sizeof(uint32_t))) =
                     (l_data[0]>>(sizeof(uint32_t)*8-(byteNum+1)*8) & 0x000000FF);
                }
                i++;
            }
            if (l_err)
            {
                break;
            }

            //Write-to-Clear PIB Pending,and bits 23-12 (data and header count)
            //Write to set Xup
            l_StatusReg[0] |= 0x22FFF000;
        }


        //Write to clear PIB Pending, Abort, and Xdn (all that apply)
        if(l_StatusReg[0])
        {
            l_err = deviceOp(DeviceFW::WRITE,i_target,
                             l_StatusReg,l_64bitSize,
                             DEVICE_XSCOM_ADDRESS(MBOX_DB_STAT_CNTRL_1));
            if (l_err)
            {
                TRACFCOMP(g_trac_mbox, ERR_MRK "MBOX::read> Unable to clear Doorbell Status/Control Register");
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
                TRACFCOMP(g_trac_mbox, ERR_MRK "MBOX::read> Unable to clear PIB Interrupt Register");
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
errlHndl_t MboxDD::write(TARGETING::Target* i_target,void* i_buffer,
                         size_t& i_buflen)
{
    errlHndl_t l_err = NULL;
    uint32_t l_64bitBuf[2] = {0};
    size_t l_64bitSize = sizeof(uint64_t);

    do
    {
        //Expect size in bytes
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
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            MBOX::MOD_MBOXDD_WRITE,
                                            MBOX::RC_INVALID_LENGTH,
                                            target_to_uint64(i_target),
                                            TO_UINT64(i_buflen));
            l_err->collectTrace("MBOX",1024);
            break;
        }

        l_err = deviceOp(DeviceFW::READ,i_target,
                         l_64bitBuf,l_64bitSize,
                         DEVICE_XSCOM_ADDRESS(MBOX_DB_STAT_CNTRL_1));
        if (l_err)
        {
            TRACFCOMP(g_trac_mbox, ERR_MRK "MBOX::write> Unable to read Doorbell Status/Control Register");
            break;
        }

        /*
         * DB_STATUS_1A_REG: doorbell status and control 1a
         * Bit31(MSB) : Permission to Send Doorbell 1
         * Bit30 : Abort Doorbell 1
         * Bit29 : PIB Slave B Pending Doorbell 1
         * Bit28 : LBUS Slave A Pending Doorbell 1
         * Bit27 : Reserved
         * Bit26 : Xdn Doorbell 1
         * Bit25 : Xup Doorbell 1
         * Bit24 : Reserved
         * Bit23-20 : Header Count LBUS Slave A Doorbell 1
         * Bit19-12 : Data Count LBUS Slave A Doorbell 1
         * Bit11-8 : Header Count PIB Slave B Doorbell 1
         * Bit7-0 : Data Count PIB Slave B Doorbell 1
         */
        //Verify LBUS Pending,
        if ((l_64bitBuf[0] & 0x10000FFF) == 0)
        {
            uint32_t i = 0;
            uint32_t l_data[2] = {0};
            uint8_t l_numRegs = (i_buflen*sizeof(uint8_t))/sizeof(uint32_t);
            if ((i_buflen*sizeof(uint8_t))%sizeof(uint32_t) != 0) l_numRegs++;
            uint32_t *l_buf = static_cast<uint32_t *>(i_buffer);
            //Write Data registers
            while (i < l_numRegs)
            {
                l_data[0] = *(l_buf+i);
                l_err = deviceOp(DeviceFW::WRITE,i_target,
                                 l_data,l_64bitSize,
                                 DEVICE_XSCOM_ADDRESS(MBOX_DATA_PIB_START+i));
                if (l_err)
                {
                    TRACFCOMP(g_trac_mbox, ERR_MRK "MBOX::write> Unable to write Data Area Register 0x%X",MBOX_DATA_PIB_START+i);
                    break;
                }
                i++;
            }
            if (l_err)
            {
                break;
            }

            //Write LBUS Pending(28) and Data Count bits(11-0)
            l_64bitBuf[0] = 0x10000000 | i_buflen;
            l_err = deviceOp(DeviceFW::WRITE,i_target,
                             l_64bitBuf,l_64bitSize,
                             DEVICE_XSCOM_ADDRESS(MBOX_DB_STAT_CNTRL_1));
            if (l_err)
            {
                TRACFCOMP(g_trac_mbox, ERR_MRK "MBOX::write> Unable to set Doorbell Status/Control Register");
                break;
            }
        }
        else
        {
            TRACFCOMP(g_trac_mbox, ERR_MRK "MBOX::write> Message still pending : MBOX_DB_STAT_CNTRL_1=%X", l_64bitBuf[0]);
            /*@
             * @errortype
             * @moduleid     MBOX::MOD_MBOXDD_WRITE
             * @reasoncode   MBOX::RC_MSG_PENDING
             * @userdata1    Target ID String...
             * @userdata2    Status/Control Register
             * @devdesc      MboxDD::write> Message still pending
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            MBOX::MOD_MBOXDD_WRITE,
                                            MBOX::RC_MSG_PENDING,
                                            target_to_uint64(i_target),
                                            reinterpret_cast<uint64_t>(l_64bitBuf));
            l_err->collectTrace("MBOX",1024);
            break;
        }

    } while(0);

    return l_err;
}

/**
 * @brief Reads the mailbox PIB error status register
 */
errlHndl_t MboxDD::getErrStat(TARGETING::Target* i_target,uint64_t &o_status)
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
            TRACFCOMP(g_trac_mbox, ERR_MRK "MBOX::getErrStat> Unable to read PIB Error Status");
            break;
        }
        else
        {
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
            TRACFCOMP(g_trac_mbox, ERR_MRK "MBOX::getErrStat> Unable to clear PIB Error Status");
            break;
        }

    } while(0);

    return l_err;
}

/**
 * @brief Constructor
 */
MboxDD::MboxDD()
{
    TRACFCOMP(g_trac_mbox, "MboxDD::MboxDD()> ");
}

errlHndl_t MboxDD::init(TARGETING::Target* i_target)
{
    errlHndl_t err = NULL;
    // Setup mailbox intr mask reg
    // Set bits 6,4,2,0
    // assume we always use mailbox 1
    uint64_t scom_data = (static_cast<uint64_t>(MBOX_ABORT_LAST_MSG) |
                          static_cast<uint64_t>(MBOX_DOORBELL_ERROR) |
                          static_cast<uint64_t>(MBOX_XDN_ACK) |
                          static_cast<uint64_t>(MBOX_DATA_PENDING)) << 32;

    size_t scom_len = sizeof(uint64_t);

     
    err = deviceOp(DeviceFW::WRITE,
                   i_target,
                   reinterpret_cast<void*>(&scom_data),
                   scom_len,
                   DEVICE_XSCOM_ADDRESS(MBOX_DB_INT_MASK_PIB_RS));

    return err;

}

/**
 * @brief Destructor
 */
MboxDD::~MboxDD()
{
}
