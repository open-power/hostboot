/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fsiscom/fsiscom.C $                                   */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <string.h>
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <fsiscom/fsiscom_reasoncodes.H>
#include "fsiscom.H"

//Globals/Constants

// Trace definition
trace_desc_t* g_trac_fsiscom = NULL;
TRAC_INIT(&g_trac_fsiscom, "FSISCOM", 2*KILOBYTE); //2K

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)


namespace FSISCOM
{

union ioData6432
{
    uint64_t data64;
    struct {
        uint32_t data32_0;
        uint32_t data32_1;
    };
};

//@fixme - not full tested due to simics instability.  Will full test when
// enabling the scom test cases.

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
errlHndl_t fsiScomPerformOp(DeviceFW::OperationType i_opType,
                         TARGETING::Target* i_target,
                         void* io_buffer,
                         size_t& io_buflen,
                         int64_t i_accessType,
                         va_list i_args)
{
    errlHndl_t l_err = NULL;

    uint64_t l_scomAddr = va_arg(i_args,uint64_t);
    ioData6432 scratchData;
    uint32_t l_command = 0;
    uint32_t l_status = 0;
    bool need_unlock = false;
    size_t op_size = sizeof(uint32_t);
    mutex_t* l_mutex = NULL;

    do{

        if( io_buflen != sizeof(uint64_t) )
        {
            TRACFCOMP( g_trac_fsiscom, ERR_MRK "fsiScomPerformOp> Invalid data length : io_buflen=%d", io_buflen );
            /*@
             * @errortype
             * @moduleid     FSISCOM::MOD_FSISCOM_PERFORMOP
             * @reasoncode   FSISCOM::RC_INVALID_LENGTH
             * @userdata1    SCOM Address
             * @userdata2    Data Length
             * @devdesc      FSISCOM: fsiScomPerformOp> Invalid data length (!= 8 bytes)
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            FSISCOM::MOD_FSISCOM_PERFORMOP,
                                            FSISCOM::RC_INVALID_LENGTH,
                                            l_scomAddr,
                                            TO_UINT64(io_buflen));
            //@fixme: Need to callout target somehow.  Need to decide how to callout target and where
            //  it should be done (this layer or somewhere higher in the call stack?)
            break;
        }

        if( (l_scomAddr & 0xFFFFFFFF80000000) != 0)
        {
            TRACFCOMP( g_trac_fsiscom, ERR_MRK "fsiScomPerformOp> Address contains more than 31 bits : l_scomAddr=0x%.8x", l_scomAddr );
            /*@
             * @errortype
             * @moduleid     FSISCOM::MOD_FSISCOM_PERFORMOP
             * @reasoncode   FSISCOM::RC_INVALID_ADDRESS
             * @userdata1    SCOM Address
             * @userdata2    0
             * @devdesc      FSISCOM: fsiScomPerformOp> Address contains more than 31 bits.
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            FSISCOM::MOD_FSISCOM_PERFORMOP,
                                            FSISCOM::RC_INVALID_ADDRESS,
                                            l_scomAddr,
                                            0);
            //@fixme: Need to callout target somehow.  Need to decide how to callout target and where
            //  it should be done (this layer or somewhere higher in the call stack?)
            break;
        }

        l_command = static_cast<uint32_t>(l_scomAddr & 0x000000007FFFFFFF);

        // use the chip-specific mutex attribute
        l_mutex = i_target->getHbMutexAttr<TARGETING::ATTR_FSI_SCOM_MUTEX>();

        if(i_opType == DeviceFW::WRITE)
        {
            memcpy(&(scratchData.data64), io_buffer, 8);

            TRACUCOMP( g_trac_fsiscom, "fsiScomPerformOp> Write(l_scomAddr=0x%X, l_data0=0x%X, l_data1=0x%X)", l_scomAddr, scratchData.data32_0, scratchData.data32_1);


            // atomic section >>
            mutex_lock(l_mutex);
            need_unlock = true;


            //write bits 0-31 to data0
            l_err = DeviceFW::deviceOp( DeviceFW::WRITE,
                                        i_target,
                                        &scratchData.data32_0,
                                        op_size,
                                        DEVICE_FSI_ADDRESS(DATA0_REG));
            if(l_err)
            {
                break;
            }

            //write bits 32-63 to data1
            l_err = DeviceFW::deviceOp( DeviceFW::WRITE,
                                        i_target,
                                        &scratchData.data32_1,
                                        op_size,
                                        DEVICE_FSI_ADDRESS(DATA1_REG));
            if(l_err)
            {
                break;
            }

            //write to FSI2PIB command reg starts write operation
             //bit 0 high => write command
            l_command = 0x80000000 | l_command;
            l_err = DeviceFW::deviceOp( DeviceFW::WRITE,
                                        i_target,
                                        &l_command,
                                        op_size,
                                        DEVICE_FSI_ADDRESS(COMMAND_REG));
            if(l_err)
            {
                break;
            }

            //check status reg to see result
            l_err = DeviceFW::deviceOp( DeviceFW::READ,
                                        i_target,
                                        &l_status,
                                        op_size,
                                        DEVICE_FSI_ADDRESS(STATUS_REG));
            if(l_err)
            {
                break;
            }

            // atomic section <<
            need_unlock = false;
            mutex_unlock(l_mutex);

            //bits 17-19 indicates PCB/PIB error
            if(l_status & 0x00007000)
            {
                TRACFCOMP( g_trac_fsiscom, ERR_MRK"fsiScomPerformOp:Write: PCB/PIB error received: l_status=0x%X)", l_status);
                /*@
                 * @errortype
                 * @moduleid     FSISCOM::MOD_FSISCOM_PERFORMOP
                 * @reasoncode   FSISCOM::RC_WRITE_ERROR
                 * @userdata1    SCOM Addr
                 * @userdata2    SCOM Status Reg
                 * @devdesc      fsiScomPerformOp> Error returned from SCOM Engine after write
                 */
                l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                FSISCOM::MOD_FSISCOM_PERFORMOP,
                                                FSISCOM::RC_WRITE_ERROR,
                                                l_scomAddr,
                                                TO_UINT64(l_status));

                //@fixme: Need to callout target somehow.  Need to decide how to callout target and where
                //  it should be done (this layer or somewhere higher in the call stack?)
                //@todo: May add recover actions later.  Currently undefined

                //Grab the PIB2OPB Status reg for a XSCOM Block error
                if( (l_status & 0x00007000) == 0x00001000 ) //piberr=001
                {
                    //@todo: Switch to external FSI FFDC interfaces RTC:35064
                    TARGETING::Target* l_master = NULL;
                    TARGETING::targetService().
                      masterProcChipTargetHandle(l_master);

                    uint64_t scomdata = 0;
                    size_t scomsize = sizeof(uint64_t);
                    errlHndl_t l_err2 = DeviceFW::deviceOp( DeviceFW::READ,
                                           l_master,
                                           &scomdata,
                                           scomsize,
                                           DEVICE_XSCOM_ADDRESS(0x00020001));
                    if( l_err2 ) {
                        delete l_err2;
                    } else {
                        TRACFCOMP( g_trac_fsiscom, "PIB2OPB Status = %.16X", scomdata );
                    }
                }

                break;
            }



        }
        else if(i_opType == DeviceFW::READ)
        {
            TRACUCOMP( g_trac_fsiscom, "fsiScomPerformOp: Read(l_scomAddr=0x%.8X)", l_scomAddr);

            // atomic section >>
            mutex_lock(l_mutex);
            need_unlock = true;


            //write to FSI2PIB command reg starts read operation
            // bit 0 low -> read command
            l_err = DeviceFW::deviceOp( DeviceFW::WRITE,
                                        i_target,
                                        &l_command,
                                        op_size,
                                        DEVICE_FSI_ADDRESS(COMMAND_REG));
            if(l_err)
            {
                break;
            }

            //check ststus reg to see result
            l_err = DeviceFW::deviceOp( DeviceFW::READ,
                                        i_target,
                                        &l_status,
                                        op_size,
                                        DEVICE_FSI_ADDRESS(STATUS_REG));
            if(l_err)
            {
                break;
            }

           //bits 17-19 indicates PCB/PIB error
            if((l_status & 0x00007000) != 0)
            {
                TRACFCOMP( g_trac_fsiscom, ERR_MRK"fsiScomPerformOp:Read: PCB/PIB error received: l_status=0x%0.8X)", l_status);

                /*@
                 * @errortype
                 * @moduleid     FSISCOM::MOD_FSISCOM_PERFORMOP
                 * @reasoncode   FSISCOM::RC_READ_ERROR
                 * @userdata1    SCOM Addr
                 * @userdata2    SCOM Status Reg
                 * @devdesc      fsiScomPerformOp> Error returned from SCOM Engine after read.
                 */
                l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                FSISCOM::MOD_FSISCOM_PERFORMOP,
                                                FSISCOM::RC_READ_ERROR,
                                                l_scomAddr,
                                                TO_UINT64(l_status));

                //@fixme: Need to callout target somehow.  Need to decide how to callout target and where
                //  it should be done (this layer or somewhere higher in the call stack?)
                //@todo: May add recover actions later.  Currently undefined
                break;
            }

            //read bits 0-31 to data0
            l_err = DeviceFW::deviceOp( DeviceFW::READ,
                                        i_target,
                                        &scratchData.data32_0,
                                        op_size,
                                        DEVICE_FSI_ADDRESS(DATA0_REG));
            if(l_err)
            {
                break;
            }

            //read bits 32-63 to data1
            l_err = DeviceFW::deviceOp( DeviceFW::READ,
                                        i_target,
                                        &scratchData.data32_1,
                                        op_size,
                                        DEVICE_FSI_ADDRESS(DATA1_REG));
            if(l_err)
            {
                break;
            }

            // atomic section <<
            need_unlock = false;
            mutex_unlock(l_mutex);

            TRACUCOMP( g_trac_fsiscom, "fsiScomPerformOp: Read: l_scomAddr=0x%X, l_data0=0x%X, l_data1=0x%X", l_scomAddr, scratchData.data32_0, scratchData.data32_1);

             memcpy(io_buffer, &(scratchData.data64), 8);
        }
        else
        {
            TRACFCOMP( g_trac_fsiscom, ERR_MRK"fsiScomPerformOp:Read: PCB/PIB error received: l_status=0x%.8X)", l_status);

            /*@
             * @errortype
             * @moduleid     FSISCOM::MOD_FSISCOM_PERFORMOP
             * @reasoncode   FSISCOM::RC_INVALID_OPTYPE
             * @userdata1    Operation Type (i_opType) : 0=READ, 1=WRITE
             * @userdata2    0
             * @devdesc      fsiScomPerformOp> Unsupported Operation Type specified
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            FSISCOM::MOD_FSISCOM_PERFORMOP,
                                            FSISCOM::RC_INVALID_OPTYPE,
                                            TO_UINT64(i_opType),
                                            0);

            //@fixme: Need to callout target somehow.  Need to decide how to callout target and where
            //  it should be done (this layer or somewhere higher in the call stack?)
            break;

        }

    }while(0);

    if( need_unlock && l_mutex )
    {
        mutex_unlock(l_mutex);
    }


    return l_err;

}

// Register SCom access functions to DD framework
DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::FSISCOM,
                      TARGETING::TYPE_PROC,
                      fsiScomPerformOp);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::FSISCOM,
                      TARGETING::TYPE_MEMBUF,
                      fsiScomPerformOp);

} // end namespace
