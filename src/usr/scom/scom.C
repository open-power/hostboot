/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/scom.C $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2016                        */
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
#include <ibscom/ibscomreasoncodes.H>
#include <sys/time.h>
#include <xscom/piberror.H>
#include <errl/errludtarget.H>
#include <errl/errludlogregister.H>
#include <hw_access_def.H>


// Trace definition
trace_desc_t* g_trac_scom = NULL;
TRAC_INIT(&g_trac_scom, SCOM_COMP_NAME, KILOBYTE, TRACE::BUFFER_SLOW); //1K


namespace SCOM
{
/**
 * @brief Add any additional FFDC for this specific type of scom
 *
 * @param[in] i_err  Log to add FFDC to
 * @param[in] i_target  Target of SCOM operation
 * @param[in] i_addr  SCOM address
 */
void addScomFailFFDC( errlHndl_t i_err,
                      TARGETING::Target* i_target,
                       uint64_t i_addr );


// Register Scom access functions to DD framework
DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::SCOM,
                      TARGETING::TYPE_PROC,
                      scomPerformOp);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::SCOM,
                      TARGETING::TYPE_MEMBUF,
                      scomMemBufPerformOp);


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
    // if opMode is not specified as an argument va_arg
    // will return NULL which is 0
    uint64_t l_opMode = va_arg(i_args,uint64_t);


    l_err = checkIndirectAndDoScom(i_opType,
                                   i_target,
                                   io_buffer,
                                   io_buflen,
                                   i_accessType,
                                   l_scomAddr,
                                   l_opMode);

    return l_err;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
errlHndl_t scomMemBufPerformOp(DeviceFW::OperationType i_opType,
                               TARGETING::Target* i_target,
                               void* io_buffer,
                               size_t& io_buflen,
                               int64_t i_accessType,
                               va_list i_args)
{
    errlHndl_t l_err = NULL;


    uint64_t l_scomAddr = va_arg(i_args,uint64_t);
    // if opMode is not specified as an argument va_arg
    // will return NULL which is 0
    uint64_t l_opMode = va_arg(i_args,uint64_t);


    l_err = checkIndirectAndDoScom(i_opType,
                                   i_target,
                                   io_buffer,
                                   io_buflen,
                                   i_accessType,
                                   l_scomAddr,
                                   l_opMode);

    // Check for ATTR_CENTAUR_EC_ENABLE_RCE_WITH_OTHER_ERRORS_HW246685
    // if ATTR set and MBSECCQ being read then set bit 16
    // See RTC 97286
    //
    if(!l_err && (i_opType == DeviceFW::READ))
    {
        const uint64_t MBS_ECC0_MBSECCQ_0x0201144A = 0x000000000201144Aull;
        const uint64_t MBS_ECC1_MBSECCQ_0x0201148A = 0x000000000201148Aull;

        uint64_t addr = l_scomAddr & 0x000000007FFFFFFFull;
        if(addr == MBS_ECC0_MBSECCQ_0x0201144A ||
           addr == MBS_ECC1_MBSECCQ_0x0201148A)
        {
            uint8_t enabled = 0;
            //FAPI_ATTR_GET      @todo RTC 101877 - access FAPI attributes
            //    (ATTR_CENTAUR_EC_ENABLE_RCE_WITH_OTHER_ERRORS_HW246685,
            //     i_target,
            //     enabled);
            //   For now use:   if ec >= 0x20
            if(i_target->getAttr<TARGETING::ATTR_EC>() >= 0x20)
            {
                enabled = true;
            }

            if(enabled)
            {
                uint64_t * data = reinterpret_cast<uint64_t *>(io_buffer);
                *data |= 0x0000800000000000ull; // Force on bit 16
            }
        }
    }

    return l_err;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
errlHndl_t checkIndirectAndDoScom(DeviceFW::OperationType i_opType,
                                  TARGETING::Target* i_target,
                                  void* io_buffer,
                                  size_t& io_buflen,
                                  int64_t i_accessType,
                                  uint64_t i_addr,
                                  uint64_t i_opMode)
{

    errlHndl_t l_err = NULL;

    enum { MAX_INDSCOM_TIMEOUT_NS = 100000 }; //=.1ms

    mutex_t* l_mutex = NULL;
    bool need_unlock = false;

    do {
        // In HOSTBOOT_RUNTIME we always defer indirect scoms to Sapphire.
#ifndef __HOSTBOOT_RUNTIME
        // If the indirect scom bit is 0, then doing a regular scom
        if( (i_addr & 0x8000000000000000) == 0)
        {
#endif // __HOSTBOOT_RUNTIME
            l_err = doScomOp(i_opType,
                             i_target,
                             io_buffer,
                             io_buflen,
                             i_accessType,
                             i_addr);
            //all done
            break;
#ifndef __HOSTBOOT_RUNTIME
        }

        // We are performing an indirect scom.
        uint64_t elapsed_indScom_time_ns = 0;
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
            need_unlock = true;

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
                break;
	    }

            // Need to check loop on read until we see done, error,
            //  or we timeout
            IndirectScom_t scomout;
            scomout.data64 = 0;
            do
            {
                // Now perform the op requested using the passed in
                // IO_Buffer to pass the read data back to caller.
                l_err = doScomOp(i_opType,
                                 i_target,
                                 &(scomout.data64),
                                 io_buflen,
                                 i_accessType,
                                 i_addr);

                if (l_err != NULL)
                {
                    break;
                }

                // if bit 32 is on indicating a complete bit
                //  or we saw an error, then we're done
                if (scomout.done || scomout.piberr)
                {
                    break;
                }

                nanosleep( 0, 10000 ); //sleep for 10,000 ns
                elapsed_indScom_time_ns += 10000;

            }while ( elapsed_indScom_time_ns <= MAX_INDSCOM_TIMEOUT_NS);

            mutex_unlock(l_mutex);
            need_unlock = false;

            if (l_err) { break; }

            // Check for a PCB/PIB Error
            if( scomout.piberr != 0 )
            {
                // got an indirect read error
                // the data buffer is in tempIoData
                TRACFCOMP(g_trac_scom,
                          "INDIRECT SCOM READ: PIB Error=%d (reg=0x%.16X)",
                          scomout.piberr, scomout.data64);

                /*@
                 * @errortype
                 * @moduleid     SCOM::SCOM_CHECK_INDIRECT_AND_DO_SCOM
                 * @reasoncode   SCOM::SCOM_INDIRECT_READ_FAIL
                 * @userdata1    Address
                 * @userdata2    Indirect Scom Status Register
                 * @devdesc      Indirect SCOM Read error
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                      ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      SCOM_CHECK_INDIRECT_AND_DO_SCOM,
                                      SCOM_INDIRECT_READ_FAIL,
                                      i_addr,
                                      scomout.data64);

                //Add the callouts for the specific PCB/PIB error
                PIB::addFruCallouts( i_target,
                                     scomout.piberr,
                                     i_addr,
                                     l_err );

                //Add this target to the FFDC
                ERRORLOG::ErrlUserDetailsTarget(i_target,"IndSCOM Target")
                  .addToLog(l_err);
            }
            // if we got a timeout, create an errorlog.
            else if( scomout.done == 0 )
            {
                // got an indirect read timeout
                TRACFCOMP(g_trac_scom,
                          "INDIRECT SCOM READ: Timeout, reg=0x%.16X",
                          scomout.data64);

                /*@
                 * @errortype
                 * @moduleid     SCOM::SCOM_CHECK_INDIRECT_AND_DO_SCOM
                 * @reasoncode   SCOM::SCOM_INDIRECT_READ_TIMEOUT
                 * @userdata1    Address
                 * @userdata2    Indirect Scom Status Register
                 * @devdesc      Indirect SCOM complete bit did not come on
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                      ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      SCOM_CHECK_INDIRECT_AND_DO_SCOM,
                                      SCOM_INDIRECT_READ_TIMEOUT,
                                      i_addr,
                                      scomout.data64);

                //Best guess is the chip
                l_err->addHwCallout( i_target,
                                     HWAS::SRCI_PRIORITY_HIGH,
                                     HWAS::DELAYED_DECONFIG,
                                     HWAS::GARD_Predictive );

                //Add this target to the FFDC
                ERRORLOG::ErrlUserDetailsTarget(i_target,"IndSCOM Target")
                  .addToLog(l_err);
            }
            else // It worked
            {
                uint64_t tmp = static_cast<uint64_t>(scomout.data);
                memcpy( io_buffer, &tmp, sizeof(uint64_t) );
            }
        }
        else //write
        {
            // Turn the read bit off.
            l_io_buffer = l_io_buffer & 0x7FFFFFFFFFFFFFFF;

            // Now perform the op requested using the
            // local io_buffer with the indirect addr imbedded.
            l_err = doScomOp(i_opType,
                             i_target,
                             & l_io_buffer,
                             io_buflen,
                             i_accessType,
                             i_addr);

            if (l_err != NULL)
            {
                break;
            }

            // Need to check loop on read until we see done, error,
            //  or we timeout
            IndirectScom_t scomout;
            scomout.data64 = 0;
            do
            {
                // Now look for status
                l_err = doScomOp(DeviceFW::READ,
                                 i_target,
                                 &(scomout.data64),
                                 io_buflen,
                                 i_accessType,
                                 i_addr);

                if (l_err != NULL)
                {
                    break;
                }

                // if bit 32 is on indicating a complete bit
                //  or we saw an error, then we're done
                if (scomout.done || scomout.piberr)
                {
                    break;
                }

                nanosleep( 0, 10000 ); //sleep for 10,000 ns
                elapsed_indScom_time_ns += 10000;

            }while ( elapsed_indScom_time_ns <= MAX_INDSCOM_TIMEOUT_NS);

            if (l_err) { break; }

            // Check for a PCB/PIB Error
            if( scomout.piberr != 0 )
            {
                // got an indirect write error
                TRACFCOMP(g_trac_scom,
                        "INDIRECT SCOM PIB Error=%d (reg=0x%.16X)",
                        scomout.piberr, scomout.data64);

                /*@
                 * @errortype
                 * @moduleid    SCOM::SCOM_CHECK_INDIRECT_AND_DO_SCOM
                 * @reasoncode  SCOM::SCOM_INDIRECT_WRITE_FAIL
                 * @userdata1   Address
                 * @userdata2   Indirect Scom Status Register
                 * @devdesc     Indirect SCOM Write failed for this address
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                      ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      SCOM_CHECK_INDIRECT_AND_DO_SCOM,
                                      SCOM_INDIRECT_WRITE_FAIL,
                                      i_addr,
                                      scomout.data64);

                //Add the callouts for the specific PCB/PIB error
                PIB::addFruCallouts( i_target,
                                     scomout.piberr,
                                     i_addr,
                                     l_err );

                //Add this target to the FFDC
                ERRORLOG::ErrlUserDetailsTarget(i_target,"IndSCOM Target")
                  .addToLog(l_err);
            }
            // if we got a timeout, create an errorlog.
            else if( scomout.done == 0 )
            {
                // got an indirect read timeout
                TRACFCOMP(g_trac_scom,
                          "INDIRECT SCOM WRITE: Timeout, reg=0x%.16X",
                          scomout.data64);

                /*@
                 * @errortype
                 * @moduleid     SCOM::SCOM_CHECK_INDIRECT_AND_DO_SCOM
                 * @reasoncode   SCOM::SCOM_INDIRECT_WRITE_TIMEOUT
                 * @userdata1    Address
                 * @userdata2    Indirect Scom Status Register
                 * @devdesc      Indirect SCOM complete bit did not come on
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                      ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      SCOM_CHECK_INDIRECT_AND_DO_SCOM,
                                      SCOM_INDIRECT_WRITE_TIMEOUT,
                                      i_addr,
                                      scomout.data64);

                //Best guess is the chip
                l_err->addHwCallout( i_target,
                                     HWAS::SRCI_PRIORITY_HIGH,
                                     HWAS::DELAYED_DECONFIG,
                                     HWAS::GARD_Predictive );

                //Add this target to the FFDC
                ERRORLOG::ErrlUserDetailsTarget(i_target,"IndSCOM Target")
                  .addToLog(l_err);
            }
        } // end of write
#endif // __HOSTBOOT_RUNTIME
    } while(0);

    if(i_opMode & fapi2::IGNORE_HW_ERROR)
    {
        TRACFCOMP(g_trac_scom, "IGNORE_HW_ERROR opmode detected for scom, any errors are being deleted");
        delete l_err;
    }

    if( need_unlock )
    {
        mutex_unlock(l_mutex);
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

    //Look for special retry codes
    if( l_err
        && (0xFFFFFFFF != i_accessType)
        && (l_err->reasonCode() == IBSCOM::IBSCOM_RETRY_DUE_TO_ERROR) )
    {
        delete l_err;
        TRACFCOMP(g_trac_scom, "Forcing retry of Scom to %.16X on %.8X", i_addr,
            (TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL == i_target ?
                    0xFFFFFFFF : TARGETING::get_huid(i_target)));
        // use the unused i_accessType parameter to avoid an infinite recursion
        int64_t accessType_flag = 0xFFFFFFFF;
        l_err = doScomOp( i_opType, i_target, io_buffer,
                          io_buflen, accessType_flag, i_addr );
    }

    //Add some additional FFDC based on the specific operation
    if( l_err )
    {
        addScomFailFFDC( l_err, i_target, i_addr );
    }

    return l_err;
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void addScomFailFFDC( errlHndl_t i_err,
                      TARGETING::Target* i_target,
                      uint64_t i_addr )
{
    // Read some error regs from scom
    ERRORLOG::ErrlUserDetailsLogRegister l_scom_data(i_target);
    bool addit = false;
    TARGETING::TYPE l_type = TARGETING::TYPE_NA;
    if( i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL )
    {
        l_type = TARGETING::TYPE_PROC;
    }
    else
    {
        l_type = i_target->getAttr<TARGETING::ATTR_TYPE>();
    }

    //PBA scoms on the processor
    if( ((i_addr & 0xFFFFF000) == 0x00064000)
        && (TARGETING::TYPE_PROC == l_type) )
    {
        addit = true;
        //look for hung operations on the PBA
        uint64_t ffdc_regs[] = {
            //grab the PBA buffers in case something is hung
            0x02010850, //PBARBUFVAL0
            0x02010851, //PBARBUFVAL1
            0x02010852, //PBARBUFVAL2
            0x02010858, //PBAWBUFVAL0
            0x02010859, //PBAWBUFVAL1

            0x020F0012, //PB_GP3 (has fence information)
        };
        for( size_t x = 0; x < (sizeof(ffdc_regs)/sizeof(ffdc_regs[0])); x++ )
        {
            l_scom_data.addData(DEVICE_SCOM_ADDRESS(ffdc_regs[x]));
        }
    }
    //EX scoms on the processor (not including PCB slave regs)
    else if( ((i_addr & 0xF0000000) == 0x10000000)
             && ((i_addr & 0x00FF0000) != 0x000F0000)
             && (TARGETING::TYPE_PROC == l_type) )
    {
        addit = true;
        uint64_t ex_offset = 0xFF000000 & i_addr;
        //grab some data related to the PCB slave state
        uint64_t ffdc_regs[] = {
            0x0F010B, //Special Wakeup
            0x0F0012, //GP3
            0x0F0100, //PowerManagement GP0
            0x0F0106, //PFET Status Core
            0x0F010E, //PFET Status ECO
            0x0F0111, //PM State History
        };
        for( size_t x = 0; x < (sizeof(ffdc_regs)/sizeof(ffdc_regs[0])); x++ )
        {
            l_scom_data.addData(DEVICE_SCOM_ADDRESS(ex_offset|ffdc_regs[x]));
        }
    }

    //Any non-PCB Slave and non TP reg on the processor
    if( ((i_addr & 0x00FF0000) != 0x000F0000)
        && ((i_addr & 0xFF000000) != 0x00000000)
        && (TARGETING::TYPE_PROC == l_type) )
    {
        addit = true;
        uint64_t chiplet_offset = 0xFF000000 & i_addr;
        //grab some data related to the PCB slave state
        uint64_t ffdc_regs[] = {
            0x0F0012, //GP3
            0x0F001F, //Error capture reg
        };
        for( size_t x = 0; x < (sizeof(ffdc_regs)/sizeof(ffdc_regs[0])); x++ )
        {
            l_scom_data.addData( DEVICE_SCOM_ADDRESS(
                                 chiplet_offset|ffdc_regs[x]) );
        }

        //grab the clock/osc regs
        l_scom_data.addData(DEVICE_SCOM_ADDRESS(0x00050019));
        l_scom_data.addData(DEVICE_SCOM_ADDRESS(0x0005001A));

        //grab the clock regs via FSI too, just in case
        if (i_target != TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
        {
            TARGETING::Target* mproc = NULL;
            TARGETING::targetService().masterProcChipTargetHandle(mproc);
            if (i_target != mproc)
            {
                l_scom_data.addData(DEVICE_FSI_ADDRESS(0x2864));//==2819
                l_scom_data.addData(DEVICE_FSI_ADDRESS(0x2868));//==281A
            }
        }
    }

    if( addit )
    {
        l_scom_data.addToLog(i_err);
    }
}


} // end namespace
