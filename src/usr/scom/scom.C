/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/scom.C $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2017                        */
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
#include <scom/errlud_pib.H>
#include <ibscom/ibscomreasoncodes.H>
#include <sys/time.h>
#include <xscom/piberror.H>
#include <errl/errludtarget.H>
#include <errl/errludlogregister.H>
#include <hw_access_def.H>
#include <p9_scom_addr.H>



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
errlHndl_t scomMemBufPerformOp(DeviceFW::OperationType i_opType,
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
                                  uint64_t i_addr)
{

    errlHndl_t l_err = NULL;

    do {
        // Do we need to do the indirect logic or not?
        bool l_runIndirectLogic = true;

        // If the indirect scom bit is 0, then doing a regular scom
        if( (i_addr & 0x8000000000000000) == 0)
        {
            l_runIndirectLogic = false;
        }

        // In HOSTBOOT_RUNTIME we always defer indirect scoms to
        //   Sapphire, but PHYP wants us to do it ourselves
#ifdef __HOSTBOOT_RUNTIME
        if( TARGETING::is_sapphire_load() )
        {
            l_runIndirectLogic = false;
        }
#endif // __HOSTBOOT_RUNTIME

        // Not indirect (or skipping that) so just do regular scom
        if( l_runIndirectLogic == false )
        {
            l_err = doScomOp(i_opType,
                             i_target,
                             io_buffer,
                             io_buflen,
                             i_accessType,
                             i_addr);
            //all done
            break;
        }

        //----------------------------------------------
        //---  Below here is the indirect scom logic ---

        uint64_t l_io_buffer = 0;
        uint64_t temp_scomAddr = 0;
        uint8_t form = 0;

        memcpy(&l_io_buffer, io_buffer, 8);
        memcpy(&temp_scomAddr, &i_addr, 8);

        // Bits 0:3 of the address hold the indirect and form bits
        // We shift out 60 bits to read the form bit here
        form = (i_addr >> 60) & 1;

        // If the form is 0, we are using the "old" indirect scom method
        if (form == 0)
        {
            // setupForm0ScomRegs sets up the registers for form0 scom op
            l_err = doForm0IndirectScom(i_opType,
                                        i_target,
                                        io_buffer,
                                        io_buflen,
                                        i_accessType,
                                        i_addr);

            if (l_err)
            {
                TRACFCOMP(g_trac_scom,
                    "checkIndirectAndDoScom: Error from doForm0IndirectScom");
                break;
            }
        }

        // If form is equal to 1, we are using new FBC method
        else if (form == 1)
        {
            l_err = doForm1IndirectScom(i_opType,
                                        i_target,
                                        io_buffer,
                                        io_buflen,
                                        i_accessType,
                                        i_addr);

            if (l_err)
            {
                TRACFCOMP(g_trac_scom,
                    "checkIndirectAndDoScom: Error from doForm1IndirectScom");
                break;

            }
        }

        // Unsupported form, break out
        else
        {
            TRACFCOMP(g_trac_scom, "Unsupported indirect scom form %d", form);

            /*@
             * @errortype
             * @moduleid     SCOM::SCOM_CHECK_INDIRECT_AND_DO_SCOM
             * @reasoncode   SCOM::SCOM_INVALID_FORM
             * @userdata1    Address
             * @userdata2    HUID of Target
             * @devdesc      Unsupported indirect scom form
             * @custdesc     A problem occurred during the IPL of the system.
             */
            l_err = new ERRORLOG::ErrlEntry(
                                  ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                  SCOM_CHECK_INDIRECT_AND_DO_SCOM,
                                  SCOM_INVALID_FORM,
                                  i_addr,
                                  get_huid(i_target),
                                  true /*Add HB Software Callout*/);

            break;
        }

    } while(0);

    return l_err;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
errlHndl_t doForm0IndirectScom(DeviceFW::OperationType i_opType,
                               TARGETING::Target* i_target,
                               void* io_buffer,
                               size_t& io_buflen,
                               int64_t i_accessType,
                               uint64_t i_addr)
{
    errlHndl_t l_err = NULL;

    enum { MAX_INDSCOM_TIMEOUT_NS = 10000000 }; //=10ms

    mutex_t* l_mutex = NULL;
    bool need_unlock = false;
    uint64_t elapsed_indScom_time_ns = 0;
    uint64_t l_io_buffer = 0;
    uint64_t temp_scomAddr = 0;

    memcpy(&l_io_buffer, io_buffer, 8);
    memcpy(&temp_scomAddr, &i_addr, 8);

    do {
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
                    // there is a small chance for a race if we check the
                    //  status very quickly, the hardware sets the status
                    //  to 001=Resource Occupied when the command first
                    //  starts so keep polling
                    if( scomout.piberr != PIB::PIB_RESOURCE_OCCUPIED )
                    {
                        break;
                    }
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

                // we should never hit this so if we do we are going
                //  to blame hardware
                if( scomout.piberr == PIB::PIB_RESOURCE_OCCUPIED )
                {
                    SCOM::UdPibInfo(scomout.piberr).addToLog(l_err);
                    l_err->addHwCallout( i_target,
                                         HWAS::SRCI_PRIORITY_HIGH,
                                         HWAS::NO_DECONFIG,
                                         HWAS::GARD_NULL );
                }
                else
                {
                    //Add the callouts for the specific PCB/PIB error
                    PIB::addFruCallouts( i_target,
                                         scomout.piberr,
                                         i_addr,
                                         l_err );
                }

                //Add this target to the FFDC
                ERRORLOG::ErrlUserDetailsTarget(i_target,"IndSCOM Target")
                  .addToLog(l_err);

                l_err->collectTrace( SCOM_COMP_NAME, 256);
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

                l_err->collectTrace( SCOM_COMP_NAME, 256);
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
                    // there is a small chance for a race if we check the
                    //  status very quickly, the hardware sets the status
                    //  to 001=Resource Occupied when the command first
                    //  starts so keep polling
                    if( scomout.piberr != PIB::PIB_RESOURCE_OCCUPIED )
                    {
                        break;
                    }
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

                // we should never hit this so if we do we are going
                //  to blame hardware
                if( scomout.piberr == PIB::PIB_RESOURCE_OCCUPIED )
                {
                    SCOM::UdPibInfo(scomout.piberr).addToLog(l_err);
                    l_err->addHwCallout( i_target,
                                         HWAS::SRCI_PRIORITY_HIGH,
                                         HWAS::NO_DECONFIG,
                                         HWAS::GARD_NULL );
                }
                else
                {
                    //Add the callouts for the specific PCB/PIB error
                    PIB::addFruCallouts( i_target,
                                         scomout.piberr,
                                         i_addr,
                                         l_err );
                }

                //Add this target to the FFDC
                ERRORLOG::ErrlUserDetailsTarget(i_target,"IndSCOM Target")
                  .addToLog(l_err);

                l_err->collectTrace( SCOM_COMP_NAME, 256);
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

                l_err->collectTrace( SCOM_COMP_NAME, 256);
            }
        } // end of write
    } while(0);

    if( need_unlock )
    {
        mutex_unlock(l_mutex);
    }

    return l_err;
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
errlHndl_t doForm1IndirectScom(DeviceFW::OperationType i_opType,
                               TARGETING::Target* i_target,
                               void* io_buffer,
                               size_t& io_buflen,
                               int64_t i_accessType,
                               uint64_t i_addr)
{
    errlHndl_t l_err = NULL;

    uint64_t l_io_buffer = 0;
    uint64_t temp_scomAddr = 0;
    uint64_t l_data_from_addr = 0;

    memcpy(&l_io_buffer, io_buffer, 8);
    memcpy(&temp_scomAddr, &i_addr, 8);

    do {
        if(i_opType == DeviceFW::READ)
        {
            TRACFCOMP(g_trac_scom, "doForm1IndirectScom: Indirect Scom Form 1"
                " does not support read op");

            /*@
             * @errortype
             * @moduleid     SCOM::SCOM_DO_FORM_1_INDIRECT_SCOM
             * @reasoncode   SCOM::SCOM_FORM_1_READ_REQUEST
             * @userdata1    Address
             * @userdata2    Operation Type
             * @devdesc      No read op on form 1 indirect scom.
             */
            l_err = new ERRORLOG::ErrlEntry(
                                  ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                  SCOM_DO_FORM_1_INDIRECT_SCOM,
                                  SCOM_FORM_1_READ_REQUEST,
                                  i_addr,
                                  i_opType,
                                  true /*Add HB SW Callout*/);

            break;
        }
        // We want to make sure the user inputted data bits 0:11 are zero
        // so we can push addr(20:31) in it.
        if ((l_io_buffer & 0xFFF0000000000000) != 0)
        {
            TRACFCOMP(g_trac_scom, "doForm1IndirectScom> User supplied "
                "data(0:11) is not Zero: data out of range");

            /*@
             * @errortype
             * @moduleid     SCOM::SCOM_DO_FORM_1_INDIRECT_SCOM
             * @reasoncode   SCOM::SCOM_FORM_1_INVALID_DATA
             * @userdata1    Address
             * @userdata2    User supplied data
             * @devdesc      Bits 0:11 in user supplied data is not zero
             */
            l_err = new ERRORLOG::ErrlEntry(
                                  ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                  SCOM_DO_FORM_1_INDIRECT_SCOM,
                                  SCOM_FORM_1_INVALID_DATA,
                                  i_addr,
                                  l_io_buffer,
                                  true /*Add HB SW Callout*/);

            break;
        }

        // Set up Address reg
        // cmdreg = addr(32:63)
        temp_scomAddr = i_addr & 0x00000000FFFFFFFF;

        // Set up data regs
        // data(0:11) = addr(20:31)
        l_data_from_addr = i_addr & 0x00000FFF00000000;
        // Do some bit shifting so things line up nicely
        l_data_from_addr = (l_data_from_addr << 20 );

        // data(12:63) = data(12:63)
        // Set Data reg
        l_io_buffer = l_io_buffer | l_data_from_addr;

        // Now perform the op requested using the
        // local io_buffer with the indirect addr imbedded.
        l_err = doScomOp(i_opType,
                         i_target,
                         & l_io_buffer,
                         io_buflen,
                         i_accessType,
                         temp_scomAddr);

        if (l_err != NULL)
        {
            TRACFCOMP(g_trac_scom, "doForm1IndirectScom: Write op fail");
            break;
        }

    }while(0);

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
        else if(scomSetting.useSbeScom)
        {   //do SBESCOM
            l_err = deviceOp(i_opType,
                             i_target,
                             io_buffer,
                             io_buflen,
                             DEVICE_SBEFIFOSCOM_ADDRESS(i_addr));
            if( l_err ) { break; }
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
            assert(0,"SCOM::scomPerformOp> ATTR_SCOM_SWITCHES does not indicate Xscom, SBESCOM, Ibscom, or FSISCOM is supported. i_target=0x%.8x", get_huid(i_target));
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


    if( l_err && p9_scom_addr(i_addr).is_multicast() )
    {
        //Delete the error if the mask matches the pib err
        for(auto data : l_err->getUDSections(SCOM_COMP_ID, SCOM::SCOM_UDT_PIB))
        {
            //We get the raw data from the userdetails section, which in this
            //case is the pib_err itself so just check it.
            if(*reinterpret_cast<uint8_t *>(data) == PIB::PIB_CHIPLET_OFFLINE)
            {
                TRACFCOMP(g_trac_scom, "Ignoring error %.8X because it is a"
                          " multicast scom with a PIB_CHIPLET_OFFLINE error,"
                          " and this is expected",
                          l_err->plid() );
                delete l_err;
                l_err = NULL;
                break;
            }
        }
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
                      TARGETING::Target* i_chipTarg,
                      uint64_t i_addr )
{
    // Read some error regs from scom
    ERRORLOG::ErrlUserDetailsLogRegister l_scom_data(i_chipTarg);
    bool addit = false;
    TARGETING::TYPE l_type = TARGETING::TYPE_NA;
    uint32_t l_badChiplet = 0x00;

    static bool l_insideFFDC = false;
    if( l_insideFFDC )
    {
        TRACDCOMP( g_trac_scom, "Already gathering FFDC..." );
        return;
    }
    l_insideFFDC = true;

    if( i_chipTarg == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL )
    {
        l_type = TARGETING::TYPE_PROC;
    }
    else
    {
        l_type = i_chipTarg->getAttr<TARGETING::ATTR_TYPE>();
    }

    //Multicast scoms on the processor
    if( p9_scom_addr(i_addr).is_multicast()
        && (TARGETING::TYPE_PROC == l_type) )
    {
        addit = true;
        uint64_t ffdc_regs1[] = {
            0x000F001E, // PCBMS.FIRST_ERR_REG
            0x000F001F, // PCBMS.ERROR_REG
        };
        for( size_t x = 0;
             x < (sizeof(ffdc_regs1)/sizeof(ffdc_regs1[0]));
             x++ )
        {
            l_scom_data.addData(DEVICE_SCOM_ADDRESS(ffdc_regs1[x]));
        }

        uint64_t ffdc_regs2[] = {
            0x000F0011, // PCBMS.REC_ERR_REG0
            0x000F0012, // PCBMS.REC_ERR_REG1
            0x000F0013, // PCBMS.REC_ERR_REG2
            0x000F0014, // PCBMS.REC_ERR_REG3
        };

        // save off the responses to figure out which chiplet failed
        uint8_t l_responses[(sizeof(ffdc_regs2)/sizeof(ffdc_regs2[0]))
                            *sizeof(uint64_t)];
        uint8_t* l_respPtr = l_responses;

        for( size_t x = 0;
             x < (sizeof(ffdc_regs2)/sizeof(ffdc_regs2[0]));
             x++ )
        {
            // going to read these manually because we want to look at the data
            uint64_t l_scomdata = 0;
            size_t l_scomsize = sizeof(l_scomdata);
            errlHndl_t l_ignored = doScomOp( DeviceFW::READ,
                                             i_chipTarg,
                                             &l_scomdata,
                                             l_scomsize,
                                             DeviceFW::SCOM,
                                             ffdc_regs2[x] );
            if( l_ignored )
            {
                delete l_ignored;
                l_scomdata = 0;
            }
            else
            {
                l_scom_data.addDataBuffer( &l_scomdata,
                                        l_scomsize,
                                        DEVICE_SCOM_ADDRESS(ffdc_regs2[x]) );
            }

            // copy the error data into our big buffer
            memcpy( l_respPtr, &l_scomdata, l_scomsize );
            l_respPtr += l_scomsize; // move to the next chunk
        }

        // find the bad chiplet
        //   4-bits per chiplet : 1-bit response, 3-bit error code
        for( size_t x = 0; x < sizeof(l_responses); x++ )
        {
            // look for the first non-zero pib error code
            if( l_responses[x] & 0x70 ) //front nibble
            {
                l_badChiplet = x*2;
            }
            else if( l_responses[x] & 0x07 ) //back nibble
            {
                l_badChiplet = x*2 + 1;
            }
        }

        uint64_t ffdc_regs3[] = {
            0x0F0001, // multicast group1
            0x0F0002, // multicast group2
            0x0F0003, // multicast group3
            0x0F0004, // multicast group4
        };
        for( size_t x = 0;
             x < (sizeof(ffdc_regs3)/sizeof(ffdc_regs3[0]));
             x++ )
        {
            p9_scom_addr l_scom(ffdc_regs3[x]);
            l_scom.set_chiplet_id(l_badChiplet);
            l_scom_data.addData(DEVICE_SCOM_ADDRESS(l_scom.get_addr()));
        }
    }

    //Any non-PCB Slave and non TP reg on the processor
    if( ((i_addr & 0x00FF0000) != 0x000F0000) //PCB slave
        && (p9_scom_addr(i_addr).get_chiplet_id() != 0x00) //TP
        && (TARGETING::TYPE_PROC == l_type) )
    {
        addit = true;
        if( l_badChiplet == 0x00 )
        {
            l_badChiplet = p9_scom_addr(i_addr).get_chiplet_id();
        }
        //grab some data related to the PCB slave state
        uint64_t ffdc_regs[] = {
            0x0F001F, // PCBSL<cplt>.ERROR_REG
            0x03000F, // CC.<chiplet>.ERROR_STATUS
            0x010001, // <chiplet>.PSC.PSCOM_STATUS_ERROR_REG
            0x010002, // <chiplet>.PSC.PSCOM_ERROR_MASK
        };
        for( size_t x = 0; x < (sizeof(ffdc_regs)/sizeof(ffdc_regs[0])); x++ )
        {
            p9_scom_addr l_scom(ffdc_regs[x]);
            l_scom.set_chiplet_id(l_badChiplet);
            l_scom_data.addData(DEVICE_SCOM_ADDRESS(l_scom.get_addr()));
        }

        //Osc Switch Sense 1 register
        l_scom_data.addData(DEVICE_SCOM_ADDRESS(0x0005001D));
        //Osc Switch Sense 2 register
        l_scom_data.addData(DEVICE_SCOM_ADDRESS(0x0005001E));

        //grab the clock regs via FSI too, just in case
        if (i_chipTarg != TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
        {
            TARGETING::Target* mproc = NULL;
            TARGETING::targetService().masterProcChipTargetHandle(mproc);
            if (i_chipTarg != mproc)
            {
                l_scom_data.addData(DEVICE_FSI_ADDRESS(0x2874));//==281D
                l_scom_data.addData(DEVICE_FSI_ADDRESS(0x2878));//==281E
            }
        }
    }

    //PBA scoms on the processor
    if( ((i_addr & 0xFFFFF000) == 0x00068000)
        && (TARGETING::TYPE_PROC == l_type) )
    {
        addit = true;
        //look for hung operations on the PBA
        uint64_t ffdc_regs[] = {
            //grab the PBA buffers in case something is hung
            0x05012850, //PBARBUFVAL0
            0x05012851, //PBARBUFVAL1
            0x05012852, //PBARBUFVAL2
            0x05012853, //PBARBUFVAL3
            0x05012854, //PBARBUFVAL4
            0x05012855, //PBARBUFVAL5
            0x05012858, //PBAWBUFVAL0
            0x05012859, //PBAWBUFVAL1
        };
        for( size_t x = 0; x < (sizeof(ffdc_regs)/sizeof(ffdc_regs[0])); x++ )
        {
            l_scom_data.addData(DEVICE_SCOM_ADDRESS(ffdc_regs[x]));
        }
    }
    //Core/EX/EQ scoms on the processor (not including PCB slave regs)
    else if( (((i_addr & 0xF0000000) == 0x10000000) //CACHE
              || ((i_addr & 0xF0000000) == 0x20000000)) //CORE
             && ((i_addr & 0x00FF0000) != 0x000F0000) //PCB slave
             && (TARGETING::TYPE_PROC == l_type) )
    {
        addit = true;
        uint8_t l_badChiplet = p9_scom_addr(i_addr).get_chiplet_id();
        //grab some data related to the PCB slave state
        uint64_t ffdc_regs[] = {
            0x0F010A, //Special Wakeup Other
            0x0F010B, //Special Wakeup FSP
            0x0F010C, //Special Wakeup OCC
            0x0F010D, //Special Wakeup HYP
            0x0F0111, //PM State History FSP
        };
        for( size_t x = 0; x < (sizeof(ffdc_regs)/sizeof(ffdc_regs[0])); x++ )
        {
            p9_scom_addr l_scom(ffdc_regs[x]);
            l_scom.set_chiplet_id(l_badChiplet);
            l_scom_data.addData(DEVICE_SCOM_ADDRESS(l_scom.get_addr()));
        }
    }


    if( addit )
    {
        l_scom_data.addToLog(i_err);
    }

    l_insideFFDC = false;
}


} // end namespace
