/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/scom.C $                                         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2012              */
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
/**
 *  @file scom.C
 *
 *  @brief Implementation of SCOM operations
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <assert.h>
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include "scom.H"
#include <scom/scomreasoncodes.H>
#include <sys/time.h>


// Trace definition
trace_desc_t* g_trac_scom = NULL;
TRAC_INIT(&g_trac_scom, "SCOM", 1024, TRACE::BUFFER_SLOW); //1K


namespace SCOM
{

// Register Scom access functions to DD framework
DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::SCOM,
                      TARGETING::TYPE_PROC,
                      scomPerformOp);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::SCOM,
                      TARGETING::TYPE_MEMBUF,
                      scomPerformOp);


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
errlHndl_t scomPerformOp(DeviceFW::OperationType i_opType,
                         TARGETING::Target* i_target,
                         void* io_buffer,
                         size_t& io_buflen,
                         int64_t i_accessType,
                         va_list i_args)
{
    errlHndl_t l_err = NULL;


    uint64_t l_scomAddr = va_arg(i_args,uint64_t);



    l_err = checkIndirectAndDoScom(i_opType,
                                   i_target,
                                   io_buffer,
                                   io_buflen,
                                   i_accessType,
                                   l_scomAddr);

    return l_err;
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
errlHndl_t checkIndirectAndDoScom(DeviceFW::OperationType i_opType,
                                  TARGETING::Target* i_target,
                                  void* io_buffer,
                                  size_t& io_buflen,
                                  int64_t i_accessType,
                                  uint64_t i_addr)
{

    errlHndl_t l_err = NULL;
    mutex_t* l_mutex = NULL;
    uint64_t elapsed_indScom_time_ns = 0;
    bool l_indScomError = false;
    uint64_t temp_io_buffer = 0;

    //@todo - determine hwhat an appropriate timeout value
    enum { MAX_INDSCOM_TIMEOUT_NS = 100000 }; //=.1ms

    // If the indirect scom bit is 0, then doing a regular scom
    if( (i_addr & 0x8000000000000000) == 0)
    {
        l_err = doScomOp(i_opType,
                         i_target,
                         io_buffer,
                         io_buflen,
                         i_accessType,
                         i_addr);
     }
    // We are performing an indirect scom.
    else
    {
        uint64_t l_io_buffer = 0;
        uint64_t temp_scomAddr = 0;

        memcpy(&l_io_buffer, io_buffer, 8);
        memcpy(&temp_scomAddr, &i_addr, 8);

        // Get the 20bit indirect scom address
        temp_scomAddr = temp_scomAddr & 0x001FFFFF00000000;

        // Zero out the indirect address location.. leave the 16bits of data
        l_io_buffer = l_io_buffer & 0x000000000000FFFF;

        // OR in the 20bit indirect address
        l_io_buffer = l_io_buffer | temp_scomAddr;

        // zero out the indirect address from the buffer..
        // bit 0-31 - indirect area..
        // bit 32 - always 0
        // bit 33-47 - bcast/chipletID/port
        // bit 48-63 - local addr
        i_addr = i_addr & 0x000000007FFFFFFF;


        // If we are doing a read. We need to do a write first..
        if(i_opType == DeviceFW::READ)
        {

            // use the chip-specific mutex attribute
            l_mutex =
              i_target->getHbMutexAttr<TARGETING::ATTR_SCOM_IND_MUTEX>();

            mutex_lock(l_mutex);

            // turn the read bit on.
            l_io_buffer = l_io_buffer | 0x8000000000000000;

            // perform write before the read with the new
            // IO_buffer with the imbedded indirect scom addr.
            l_err = doScomOp(DeviceFW::WRITE,
                             i_target,
                             & l_io_buffer,
                             io_buflen,
                             i_accessType,
                             i_addr);

            if (l_err != NULL)
	    {
                mutex_unlock(l_mutex);
                return l_err;
	    }

            // Need to check loop on read until either
            // bit (32) = 1 or we have exceeded our max
            // retries.
            do
            {
                // Now perform the op requested using the passed in
                // IO_Buffer to pass the read data back to caller.
                l_err = doScomOp(i_opType,
                                 i_target,
                                 io_buffer,
                                 io_buflen,
                                 i_accessType,
                                 i_addr);

                if (l_err != NULL)
                {
                    break;
                }

                // if bit 32 is on indicating a complete bit
                if ((*((uint64_t *)io_buffer) & SCOM_IND_COMPLETE_MASK)
                    == SCOM_IND_COMPLETE_MASK)
                {
                    // check for bits 33-35 to be 0
                    //   indicating the read is valid
                    if ((*((uint64_t *)io_buffer) & SCOM_IND_ERROR_MASK)
                        == 0)

                    {
                        // Clear out the other bits in the io_buffer
                        // register to only return the read data to caller
                        *((uint64_t *)io_buffer) &= 0x00000000000FFFF;

                    }
                    else
                    {
                      // indicate that we do have a indirect scom failure
                      l_indScomError = true;
                    }

                    // break out because we got the complete bit..
                    break;
                }

                //TODO tmp remove for VPO, need better polling strategy -- RTC43738
                //nanosleep( 0, 10000 ); //sleep for 10,000 ns
                elapsed_indScom_time_ns += 10000;

            }while ( elapsed_indScom_time_ns <= MAX_INDSCOM_TIMEOUT_NS);

            mutex_unlock(l_mutex);

            if (l_err == NULL)
            {
                if (l_indScomError == true)
                {
                    // got an indirect read error
                    // the data buffer is in tempIoData
                    TRACFCOMP(g_trac_scom,
                              "INDIRECT SCOM READ= ERROR valid bits are not on..  scomreg=0x%.16X",
                              *((uint64_t *)io_buffer));

                    /*@
                     * @errortype
                     * @moduleid     SCOM::SCOM_CHECK_INDIRECT_AND_DO_SCOM
                     * @reasoncode   SCOM::SCOM_INDIRECT_READ_FAIL
                     * @userdata1    Address
                     * @userdata2    Scom data read from Address
                     * @devdesc      Indirect SCOM Read error
                     */
                    l_err = new ERRORLOG::ErrlEntry(
                                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           SCOM_CHECK_INDIRECT_AND_DO_SCOM,
                                           SCOM_INDIRECT_READ_FAIL,
                                           i_addr,
                                           *((uint64_t *)io_buffer));

                    //@TODO - add usr details to the errorlog when we have one to
                    //        give better info regarding the fail..

                }
                // if we got a timeout, create an errorlog.
                else  if(  elapsed_indScom_time_ns > MAX_INDSCOM_TIMEOUT_NS )
                {
                    // got an indirect read timeout
                    TRACFCOMP(g_trac_scom,
                              "INDIRECT SCOM READ=indirect read timout ..  scomreg=0x%.16X",
                              *((uint64_t *)io_buffer));


                    /*@
                     * @errortype
                     * @moduleid     SCOM::SCOM_CHECK_INDIRECT_AND_DO_SCOM
                     * @reasoncode   SCOM::SCOM_INDIRECT_READ_TIMEOUT
                     * @userdata1    Address
                     * @userdata2    Scom data read from Address
                     * @devdesc      Indirect SCOM complete bit did not come on
                     */
                    l_err = new ERRORLOG::ErrlEntry(
                                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            SCOM_CHECK_INDIRECT_AND_DO_SCOM,
                                            SCOM_INDIRECT_READ_TIMEOUT,
                                            i_addr,
                                            *((uint64_t *)io_buffer));

                    //@TODO - add usr details to the errorlog when we have
                    //        one to give better info regarding the fail..

                }
            }
        }
        else //write
        {
            // Turn the read bit off.
            l_io_buffer = l_io_buffer & 0x7FFFFFFFFFFFFFFF;

            // Now perform the op requested using the
            // locai io_buffer with the indirect addr imbedded.
            l_err = doScomOp(i_opType,
                             i_target,
                             & l_io_buffer,
                             io_buflen,
                             i_accessType,
                             i_addr);

            // Need to check loop on read until either
            // bit (32) = 1 or we have exceeded our max
            // retries.
            do
            {

                memcpy(&temp_io_buffer, io_buffer, 8);

                // Now perform the op requested using the passed in
                // IO_Buffer to pass the read data back to caller.
                l_err = doScomOp(DeviceFW::READ,
                                 i_target,
                                 & temp_io_buffer,
                                 io_buflen,
                                 i_accessType,
                                 i_addr);


                if (l_err != NULL)
                {
                    break;
                }

                // if bit 32 is on indicating a complete bit
                if ((temp_io_buffer & SCOM_IND_COMPLETE_MASK)
                    == SCOM_IND_COMPLETE_MASK)
                {
                    // The write is valid when bits 33-35 are 0..
                    //      if not on return error
                    if ((temp_io_buffer & SCOM_IND_ERROR_MASK)
                        != 0)

                    {
                        // bits did not get turned on.. set error to true.
                        l_indScomError = true;
                    }

                    // break out because we got the complete bit on
                    break;

                }

                //TODO tmp remove for VPO, need better polling strategy -- RTC43738
                //nanosleep( 0, 10000 ); //sleep for 10,000 ns
                elapsed_indScom_time_ns += 10000;

            }while ( elapsed_indScom_time_ns <= MAX_INDSCOM_TIMEOUT_NS);

            if (l_err == NULL)
            {
                // If the indirect scom has an error.
                if (l_indScomError == true)
                {
                    // got an indirect write error
                    TRACFCOMP(g_trac_scom, "INDIRECT SCOM WRITE= ERROR valid bits are not on..  scomreg=0x%.16X", temp_io_buffer);

                    /*@
                     * @errortype
                     * @moduleid     SCOM::SCOM_CHECK_INDIRECT_AND_DO_SCOM
                     * @reasoncode   SCOM::SCOM_INDIRECT_WRITE_FAIL
                     * @userdata1   Address
                     * @userdata2   Scom data read from Address
                     * @devdesc     Indirect SCOM Write failed for this address
                     */
                    l_err = new ERRORLOG::ErrlEntry(
                                             ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                             SCOM_CHECK_INDIRECT_AND_DO_SCOM,
                                             SCOM_INDIRECT_WRITE_FAIL,
                                             i_addr,
                                             temp_io_buffer);

                    //@TODO - add usr details to the errorlog when we have
                    //        one to give better info regarding the fail..

                }
                // if we got a timeout, create an errorlog.
                else  if(  elapsed_indScom_time_ns > MAX_INDSCOM_TIMEOUT_NS )
                {
                    // got an indirect write timeout
                    TRACFCOMP(g_trac_scom,
                              "INDIRECT SCOM WRITE=indirect write timeout ..  scomreg=0x%.16X",
                              temp_io_buffer);


                    /*@
                     * @errortype
                     * @moduleid     SCOM::SCOM_CHECK_INDIRECT_AND_DO_SCOM
                     * @reasoncode   SCOM::SCOM_INDIRECT_WRITE_TIMEOUT
                     * @userdata1    Address
                     * @userdata2    Scom data read from Address
                     * @devdesc      Indirect SCOM write timeout, complete
                     *               bit did not come one
                     */
                    l_err = new ERRORLOG::ErrlEntry(
                                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            SCOM_CHECK_INDIRECT_AND_DO_SCOM,
                                            SCOM_INDIRECT_WRITE_TIMEOUT,
                                            i_addr,
                                            temp_io_buffer);

                    //@TODO - add usr details to the errorlog when we have
                    //        one to give better info regarding the fail..

                }
            }
        } // end of write
    }
    return l_err;
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
errlHndl_t doScomOp(DeviceFW::OperationType i_opType,
                    TARGETING::Target* i_target,
                    void* io_buffer,
                    size_t& io_buflen,
                    int64_t i_accessType,
                    uint64_t i_addr)
{

    errlHndl_t l_err = NULL;

    do{
        TARGETING::ScomSwitches scomSetting;
        scomSetting.useXscom = true;  //Default to Xscom supported.
        if(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL != i_target)
        {
            scomSetting =
              i_target->getAttr<TARGETING::ATTR_SCOM_SWITCHES>();
        }

        //Always XSCOM the Master Sentinel
        if((TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL == i_target) ||
            (scomSetting.useXscom))
        {  //do XSCOM

            l_err = deviceOp(i_opType,
                             i_target,
                             io_buffer,
                             io_buflen,
                             DEVICE_XSCOM_ADDRESS(i_addr));
            break;
        }
        else if(scomSetting.useInbandScom)
        {   //do IBSCOM
            l_err = deviceOp(i_opType,
                             i_target,
                             io_buffer,
                             io_buflen,
                             DEVICE_IBSCOM_ADDRESS(i_addr));
            if( l_err ) { break; }
        }
        else if(scomSetting.useFsiScom)
        {   //do FSISCOM
            l_err = deviceOp(i_opType,
                             i_target,
                             io_buffer,
                             io_buflen,
                             DEVICE_FSISCOM_ADDRESS(i_addr));
            if( l_err ) { break; }
        }
        else
        {
            assert(0,"SCOM::scomPerformOp> ATTR_SCOM_SWITCHES does not indicate Xscom, Ibscom, or FSISCOM is supported. i_target=0x%.8x", get_huid(i_target));
            break;
        }

    }while(0);

    return l_err;
}


} // end namespace
