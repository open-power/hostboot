/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/mvpd.C $                                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2021                        */
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
#include <vpd/mvpdenums.H>
#include <vpd/vpd_if.H>
#include <eeprom/eepromif.H>

#include "../eeprom/eepromCache.H"

#include "mvpd.H"
#include "ipvpd.H"
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


namespace MVPD
{
// ----------------------------------------------
// Globals
// ----------------------------------------------
    mutex_t g_mutex = MUTEX_INITIALIZER;

    /**
     * @brief This function will perform the steps required to do a read from
     *      the Hostboot MVPD data.
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
    errlHndl_t mvpdRead ( DeviceFW::OperationType i_opType,
                          TARGETING::Target * i_target,
                          void * io_buffer,
                          size_t & io_buflen,
                          int64_t i_accessType,
                          va_list i_args )
    {
        errlHndl_t err = NULL;
        IpVpdFacade::input_args_t args;
        args.record = ((mvpdRecord)va_arg( i_args, uint64_t ));
        args.keyword = ((mvpdKeyword)va_arg( i_args, uint64_t ));
        args.location = ((VPD::vpdCmdTarget)va_arg( i_args, uint64_t ));

        TRACSSCOMP( g_trac_vpd,
                    ENTER_MRK"mvpdRead()" );

        err = Singleton<MvpdFacade>::instance().read(i_target,
                                                  io_buffer,
                                                  io_buflen,
                                                  args);

        return err;
    }



    /**
     * @brief This function will perform the steps required to do a write to
     *      the Hostboot MVPD data.
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
    errlHndl_t mvpdWrite ( DeviceFW::OperationType i_opType,
                           TARGETING::Target * i_target,
                           void * io_buffer,
                           size_t & io_buflen,
                           int64_t i_accessType,
                           va_list i_args )
    {
        errlHndl_t err = NULL;
        IpVpdFacade::input_args_t args;
        args.record = ((mvpdRecord)va_arg( i_args, uint64_t ));
        args.keyword = ((mvpdKeyword)va_arg( i_args, uint64_t ));
        args.location = ((VPD::vpdCmdTarget)va_arg( i_args, uint64_t ));

        TRACSSCOMP( g_trac_vpd,
                    ENTER_MRK"mvpdWrite()" );

        do
        {
            err = Singleton<MvpdFacade>::instance().write( i_target,  io_buffer,
                                                           io_buflen, args );
            if (err)
            {
                TRACFCOMP( g_trac_vpd, ERR_MRK"mvpdWrite(): MvpdFacade::write() failed "
                           "to write record(0x%.4X)/keyword(0x%.4X) for target 0x%.8X",
                           args.record, args.keyword, TARGETING::get_huid(i_target) );
                break;
            }

            err = Singleton<MvpdFacade>::instance().updateRecordEccData( i_target, args );
            if (err)
            {
                TRACFCOMP( g_trac_vpd, ERR_MRK"mvpdWrite(): MvpdFacade::updateRecordEccData() "
                           "failed to update ECC data for record 0x%.4X for target 0x%.8X",
                           args.record, TARGETING::get_huid(i_target) );

                break;
            }

        } while (0);

        return err;
    }

    // Register with the routing code
    DEVICE_REGISTER_ROUTE( DeviceFW::READ,
                           DeviceFW::MVPD,
                           TARGETING::TYPE_PROC,
                           mvpdRead );
    DEVICE_REGISTER_ROUTE( DeviceFW::WRITE,
                           DeviceFW::MVPD,
                           TARGETING::TYPE_PROC,
                           mvpdWrite );

}; // end MVPD namespace

// ---------------------------------------------------------
// Presence Detection
// ---------------------------------------------------------
bool VPD::mvpdPresent( TARGETING::Target * i_target )
{
    TRACSSCOMP(g_trac_vpd, ENTER_MRK"mvpdPresent()");
#if(defined( CONFIG_MVPD_READ_FROM_HW ) && !defined( __HOSTBOOT_RUNTIME) )
#   if (defined (CONFIG_SUPPORT_EEPROM_CACHING) && !defined(CONFIG_SUPPORT_EEPROM_HWACCESS))
        bool present = false;
        EEPROM::eecachePresenceDetect(i_target, present);
        return present;
#   else
        return EEPROM::eepromPresence( i_target );
#   endif
#else
    return Singleton<MvpdFacade>::instance().hasVpdPresent( i_target,
                                                            MVPD::CP00,
                                                            MVPD::VD );
#endif
}


//MVPD Class Functions
/**
 * @brief  Constructor
 */
MvpdFacade::MvpdFacade() :
IpVpdFacade(MVPD::mvpdRecords,
            (sizeof(MVPD::mvpdRecords)/sizeof(MVPD::mvpdRecords[0])),
            MVPD::mvpdKeywords,
            (sizeof(MVPD::mvpdKeywords)/sizeof(MVPD::mvpdKeywords[0])),
            PNOR::MODULE_VPD,
            MVPD::g_mutex,
            VPD::VPD_WRITE_PROC)
{
    TRACUCOMP(g_trac_vpd, "MvpdFacade::MvpdFacade> " );

#ifdef CONFIG_MVPD_READ_FROM_PNOR
    iv_configInfo.vpdReadPNOR = true;
#else
    iv_configInfo.vpdReadPNOR = false;
#endif
#ifdef CONFIG_MVPD_READ_FROM_HW
    iv_configInfo.vpdReadHW = true;
#else
    iv_configInfo.vpdReadHW = false;
#endif
#ifdef CONFIG_MVPD_WRITE_TO_PNOR
    iv_configInfo.vpdWritePNOR = true;
#else
    iv_configInfo.vpdWritePNOR = false;
#endif
#ifdef CONFIG_MVPD_WRITE_TO_HW
    iv_configInfo.vpdWriteHW = true;
#else
    iv_configInfo.vpdWriteHW = false;
#endif

   iv_vpdSectionSize = MVPD::SECTION_SIZE;

   iv_vpdMaxSections = MVPD::MAX_SECTIONS;

}

