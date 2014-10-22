/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/cvpd.C $                                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
/* [+] Google Inc.                                                        */
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
// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <string.h>
#include <endian.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <targeting/common/targetservice.H>
#include <devicefw/driverif.H>
#include <vfs/vfs.H>
#include <vpd/vpdreasoncodes.H>
#include <vpd/cvpdenums.H>
#include <vpd/vpd_if.H>
#include <config.h>
#include "cvpd.H"
#include "vpd.H"

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
extern trace_desc_t* g_trac_vpd;


// ------------------------
// Macros for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)
//#define TRACSSCOMP(args...)  TRACFCOMP(args)
#define TRACSSCOMP(args...)

namespace CVPD
{
    // ----------------------------------------------
    // Globals
    // ----------------------------------------------
    mutex_t g_mutex = MUTEX_INITIALIZER;





    /**
     * @brief This function will perform the steps required to do a read from
     *      the Hostboot CVPD data.
     *
     * @param[in] i_opType - Operation Type - See DeviceFW::OperationType in
     *       driververif.H
     *
     * @param[in] i_target - Processor Target device
     *
     * @param [in/out] io_buffer - Pointer to the data that was read from
     *       the target device.  This parameter, when set to NULL, will return
     *       the keyword size value in io_buflen.
     *
     * @param [in/out] io_buflen - Length of the buffer to be read or written
     *       to/from the target.  This value should indicate the size of the
     *       io_buffer parameter that has been allocated.  Being returned it
     *       will indicate the number of valid bytes in the buffer being
     *       returned. This parameter will contain the size of a keyword when
     *       the io_buffer parameter is passed in NULL.
     *
     * @param [in] i_accessType - Access Type - See DeviceFW::AccessType in
     *       usrif.H
     *
     * @param [in] i_args - This is an argument list for the device driver
     *       framework.
     *
     * @return errlHndl_t - NULL if successful, otherwise a pointer to the
     *       error log.
     */
    errlHndl_t cvpdRead ( DeviceFW::OperationType i_opType,
                          TARGETING::Target * i_target,
                          void * io_buffer,
                          size_t & io_buflen,
                          int64_t i_accessType,
                          va_list i_args )
    {
        errlHndl_t err = NULL;
        IpVpdFacade::input_args_t args;
        args.record = ((cvpdRecord)va_arg( i_args, uint64_t ));
        args.keyword = ((cvpdKeyword)va_arg( i_args, uint64_t ));
        args.location = ((VPD::vpdCmdTarget)va_arg( i_args, uint64_t ));

        TRACSSCOMP( g_trac_vpd,
                    ENTER_MRK"cvpdRead()" );

        err = Singleton<CvpdFacade>::instance().read(i_target,
                                                     io_buffer,
                                                     io_buflen,
                                                     args);

        return err;
    }


    /**
     * @brief This function will perform the steps required to do a write to
     *      the Hostboot CVPD data.
     *
     * @param[in] i_opType - Operation Type - See DeviceFW::OperationType in
     *       driververif.H
     *
     * @param[in] i_target - Processor Target device
     *
     * @param [in/out] io_buffer - Pointer to the data that was read from
     *       the target device.  It will also be used to contain data to
     *       be written to the device.
     *
     * @param [in/out] io_buflen - Length of the buffer to be read or written
     *       to/from the target.  This value should indicate the size of the
     *       io_buffer parameter that has been allocated.  Being returned it
     *       will indicate the number of valid bytes in the buffer being
     *       returned.
     *
     * @param [in] i_accessType - Access Type - See DeviceFW::AccessType in
     *       usrif.H
     *
     * @param [in] i_args - This is an argument list for the device driver
     *       framework.
     *
     * @return errlHndl_t - NULL if successful, otherwise a pointer to the
     *       error log.
     */
    errlHndl_t cvpdWrite ( DeviceFW::OperationType i_opType,
                           TARGETING::Target * i_target,
                           void * io_buffer,
                           size_t & io_buflen,
                           int64_t i_accessType,
                           va_list i_args )
    {
        errlHndl_t err = NULL;
        IpVpdFacade::input_args_t args;
        args.record = ((cvpdRecord)va_arg( i_args, uint64_t ));
        args.keyword = ((cvpdKeyword)va_arg( i_args, uint64_t ));
        args.location = ((VPD::vpdCmdTarget)va_arg( i_args, uint64_t ));

        TRACSSCOMP( g_trac_vpd,
                    ENTER_MRK"cvpdWrite()" );


        err = Singleton<CvpdFacade>::instance().write(i_target,
                                                      io_buffer,
                                                      io_buflen,
                                                      args);

        return err;
    }

    // Register with the routing code
    DEVICE_REGISTER_ROUTE( DeviceFW::READ,
                           DeviceFW::CVPD,
                           TARGETING::TYPE_MEMBUF,
                           cvpdRead );
    DEVICE_REGISTER_ROUTE( DeviceFW::WRITE,
                           DeviceFW::CVPD,
                           TARGETING::TYPE_MEMBUF,
                           cvpdWrite );



}; // end namespace CVPD

// --------------------------------------------------------
// Presence Detection
//---------------------------------------------------------
bool VPD::cvpdPresent( TARGETING::Target * i_target )
{
#ifdef CONFIG_CVPD_READ_FROM_HW
    //@todo - Fix this the right way with RTC:117048
    IpVpdFacade::input_args_t args;
    args.record = CVPD::VEIR;
    args.keyword = CVPD::PF ;
    args.location = VPD::AUTOSELECT;
    size_t kwlen = 0;
    errlHndl_t l_errl = Singleton<CvpdFacade>::instance().read(
                                   i_target,
                                   NULL,
                                   kwlen,
                                   args );
    if( l_errl )
    {
        delete l_errl;
        return false;
    }
    if( kwlen == 0 )
    {
        return false;
    }
    return true;

#else
    return Singleton<CvpdFacade>::instance().hasVpdPresent( i_target,
                                                            CVPD::VEIR,
                                                            CVPD::PF );
#endif
}




//CVPD Class Functions
/**
 * @brief  Constructor
 */
CvpdFacade::CvpdFacade() :
IpVpdFacade(CVPD::SECTION_SIZE,
            CVPD::MAX_SECTIONS,
            CVPD::cvpdRecords,
            (sizeof(CVPD::cvpdRecords)/sizeof(CVPD::cvpdRecords[0])),
            CVPD::cvpdKeywords,
            (sizeof(CVPD::cvpdKeywords)/sizeof(CVPD::cvpdKeywords[0])),
            PNOR::CENTAUR_VPD,
            CVPD::g_mutex,
            VPD::VPD_WRITE_MEMBUF)
{
    TRACUCOMP(g_trac_vpd, "CvpdFacade::CvpdFacade> " );

#ifdef CONFIG_CVPD_READ_FROM_PNOR
    iv_configInfo.vpdReadPNOR = true;
#else
    iv_configInfo.vpdReadPNOR = false;
#endif
#ifdef CONFIG_CVPD_READ_FROM_HW
    iv_configInfo.vpdReadHW = true;
#else
    iv_configInfo.vpdReadHW = false;
#endif    
#ifdef CONFIG_CVPD_WRITE_TO_PNOR
    iv_configInfo.vpdWritePNOR = true;
#else
    iv_configInfo.vpdWritePNOR = false;
#endif    
#ifdef CONFIG_CVPD_WRITE_TO_HW
    iv_configInfo.vpdWriteHW = true;
#else
    iv_configInfo.vpdWriteHW = false;
#endif
}
