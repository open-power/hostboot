/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fsiscom/fsiscom.C $                                   */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#include <errl/errludtarget.H>
#include <xscom/piberror.H>
#include <fsiscom/fsiscom_reasoncodes.H>
#include <fsi/fsiif.H>
#include <sys/time.h>
#include "fsiscom.H"

//Globals/Constants

// Trace definition
trace_desc_t* g_trac_fsiscom = NULL;
TRAC_INIT(&g_trac_fsiscom, FSISCOM_COMP_NAME, 2*KILOBYTE); //2K

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

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void pib_error_handler( TARGETING::Target* i_target,
                        errlHndl_t i_errlog,
                        uint32_t i_status )
{
    //Add this target to the FFDC
    ERRORLOG::ErrlUserDetailsTarget(i_target,"SCOM Target").addToLog(i_errlog);

    //Add the callouts for the specific PCB/PIB error
    uint32_t pib_error = i_status >> 12;
    PIB::addFruCallouts( i_target,
                         pib_error,
                         i_errlog );

    //Grab the PIB2OPB Status reg for a Resource Occupied error
    if( pib_error == PIB::PIB_RESOURCE_OCCUPIED ) //piberr=001
    {
        FSI::getFsiFFDC( FSI::FFDC_PIB_FAIL,
                         i_errlog,
                         i_target );
    }

    //Recovery sequence from Markus
    //  if SCOM fails and FSI Master displays "MasterTimeOut"
    //     then 7,6  <covered by FSI driver>
    //  else if SCOM fails and FSI2PIB Status shows PIB abort
    //     then just perform unit reset (6) and wait 1 ms
    //  else (PIB_abort='0' but PIB error is unequal 0)
    //     then just perform unit reset (6) (wait not needed).
    uint32_t l_command = 0;
    size_t op_size = sizeof(uint32_t);
    errlHndl_t l_err = DeviceFW::deviceOp( DeviceFW::WRITE,
                                       i_target,
                                       &l_command,
                                       op_size,
                                       DEVICE_FSI_ADDRESS(ENGINE_RESET_REG));
    if(l_err)
    {
        TRACFCOMP( g_trac_fsiscom,
                   ERR_MRK"Error resetting FSI : %.4X",
                   ERRL_GETRC_SAFE(l_err) );
        l_err->plid(i_errlog->plid());
        errlCommit(l_err,FSISCOM_COMP_ID);
    }

    nanosleep( 0,NS_PER_MSEC ); //sleep for ms

}

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
             * @devdesc      fsiScomPerformOp> Invalid data length (!= 8 bytes)
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            FSISCOM::MOD_FSISCOM_PERFORMOP,
                                            FSISCOM::RC_INVALID_LENGTH,
                                            l_scomAddr,
                                            TO_UINT64(io_buflen));
            l_err->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                        HWAS::SRCI_PRIORITY_LOW );
            ERRORLOG::ErrlUserDetailsTarget(i_target,"SCOM Target").
              addToLog(l_err);
            break;
        }

        if( (l_scomAddr & 0xFFFFFFFF80000000) != 0)
        {
            TRACFCOMP( g_trac_fsiscom, ERR_MRK "fsiScomPerformOp> Address contains more than 31 bits : l_scomAddr=0x%.16X", l_scomAddr );
            /*@
             * @errortype
             * @moduleid     FSISCOM::MOD_FSISCOM_PERFORMOP
             * @reasoncode   FSISCOM::RC_INVALID_ADDRESS
             * @userdata1    SCOM Address
             * @userdata2    Target HUID
             * @devdesc      fsiScomPerformOp> Address contains
             *               more than 31 bits.
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            FSISCOM::MOD_FSISCOM_PERFORMOP,
                                            FSISCOM::RC_INVALID_ADDRESS,
                                            l_scomAddr,
                                            TARGETING::get_huid(i_target));
            l_err->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                        HWAS::SRCI_PRIORITY_LOW );
            ERRORLOG::ErrlUserDetailsTarget(i_target,"SCOM Target").
              addToLog(l_err);
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

            // Check the status reg for errors
            if( (l_status & PIB_ERROR_BITS)      // PCB/PIB Errors
                || (l_status & PIB_ABORT_BIT)  ) // PIB Abort
            {
                TRACFCOMP( g_trac_fsiscom, ERR_MRK"fsiScomPerformOp:Write: PCB/PIB error received: l_status=0x%X)", l_status);
                /*@
                 * @errortype
                 * @moduleid     FSISCOM::MOD_FSISCOM_PERFORMOP
                 * @reasoncode   FSISCOM::RC_WRITE_ERROR
                 * @userdata1    SCOM Addr
                 * @userdata2[00:31]  Target HUID
                 * @userdata2[32:63]  SCOM Status Reg
                 * @devdesc      fsiScomPerformOp> Error returned
                 *               from SCOM Engine after write
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                FSISCOM::MOD_FSISCOM_PERFORMOP,
                                FSISCOM::RC_WRITE_ERROR,
                                l_scomAddr,
                                TWO_UINT32_TO_UINT64(
                                           TARGETING::get_huid(i_target),
                                           l_status));

                // call common error handler to do callouts and recovery
                pib_error_handler( i_target, l_err, l_status );

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

            // atomic section <<
            need_unlock = false;
            mutex_unlock(l_mutex);
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

            // Check the status reg for errors
            if( (l_status & PIB_ERROR_BITS)      // PCB/PIB Errors
                || (l_status & PIB_ABORT_BIT)  ) // PIB Abort
            {
                TRACFCOMP( g_trac_fsiscom, ERR_MRK"fsiScomPerformOp:Read: PCB/PIB error received: l_status=0x%0.8X)", l_status);

                /*@
                 * @errortype
                 * @moduleid     FSISCOM::MOD_FSISCOM_PERFORMOP
                 * @reasoncode   FSISCOM::RC_READ_ERROR
                 * @userdata1    SCOM Addr
                 * @userdata2[00:31]  Target HUID
                 * @userdata2[32:63]  SCOM Status Reg
                 * @devdesc      fsiScomPerformOp> Error returned from SCOM Engine after read.
                 */
                l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                FSISCOM::MOD_FSISCOM_PERFORMOP,
                                                FSISCOM::RC_READ_ERROR,
                                                l_scomAddr,
                                                TWO_UINT32_TO_UINT64(
                                                 TARGETING::get_huid(i_target),
                                                 l_status));

                // call common error handler to do callouts and recovery
                pib_error_handler( i_target, l_err, l_status );

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
             * @userdata1[0:31]    Operation Type (i_opType) : 0=READ, 1=WRITE
             * @userdata1[32:64]   Input scom address
             * @userdata2    Target HUID
             * @devdesc      fsiScomPerformOp> Unsupported Operation Type specified
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            FSISCOM::MOD_FSISCOM_PERFORMOP,
                                            FSISCOM::RC_INVALID_OPTYPE,
                                            TWO_UINT32_TO_UINT64(i_opType,
                                                                 l_scomAddr),
                                            TARGETING::get_huid(i_target));
            //Add this target to the FFDC
            ERRORLOG::ErrlUserDetailsTarget(i_target,"SCOM Target").
              addToLog(l_err);

            l_err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                       HWAS::SRCI_PRIORITY_HIGH);

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
