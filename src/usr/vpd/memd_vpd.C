/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/memd_vpd.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2017                        */
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
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>
#include <devicefw/driverif.H>
#include <vfs/vfs.H>
#include <vpd/vpdreasoncodes.H>
#include <vpd/memd_vpdenums.H>
#include <vpd/vpd_if.H>
#include <i2c/eepromif.H>
#include <config.h>
#include "memd_vpd.H"
#include "cvpd.H"
#include "vpd.H"
#include "pvpd.H"
#include <initservice/initserviceif.H>

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

namespace MEMD_VPD
{
    // ----------------------------------------------
    // Globals
    // ----------------------------------------------
    mutex_t g_mutex = MUTEX_INITIALIZER;


    /**
     * @brief This function will perform the steps required to do a read from
     *      the Hostboot MEMD_VPD data.
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
    errlHndl_t MEMD_VPDRead ( DeviceFW::OperationType i_opType,
                          TARGETING::Target * i_target,
                          void * io_buffer,
                          size_t & io_buflen,
                          int64_t i_accessType,
                          va_list i_args )
    {
        errlHndl_t err = NULL;
        IpVpdFacade::input_args_t args;
        args.record = ((MEMD_VPDRecord)va_arg( i_args, uint64_t ));
        args.keyword = ((MEMD_VPDKeyword)va_arg( i_args, uint64_t ));
        args.location = ((VPD::vpdCmdTarget)va_arg( i_args, uint64_t ));

        TRACSSCOMP( g_trac_vpd,
                    ENTER_MRK"MEMD_VPDRead()" );

        err = Singleton<MEMD_VpdFacade>::instance().read(i_target,
                                                     io_buffer,
                                                     io_buflen,
                                                     args);

        return err;
    }


    /**
     * @brief This function will perform the steps required to do a write to
     *      the Hostboot MEMD_VPD data.
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
    errlHndl_t MEMD_VPDWrite ( DeviceFW::OperationType i_opType,
                           TARGETING::Target * i_target,
                           void * io_buffer,
                           size_t & io_buflen,
                           int64_t i_accessType,
                           va_list i_args )
    {
        errlHndl_t err = NULL;
        IpVpdFacade::input_args_t args;
        args.record = ((MEMD_VPDRecord)va_arg( i_args, uint64_t ));
        args.keyword = ((MEMD_VPDKeyword)va_arg( i_args, uint64_t ));
        args.location = ((VPD::vpdCmdTarget)va_arg( i_args, uint64_t ));

        TRACSSCOMP( g_trac_vpd,
                    ENTER_MRK"MEMD_VPDWrite()" );


        err = Singleton<MEMD_VpdFacade>::instance().write(i_target,
                                                      io_buffer,
                                                      io_buflen,
                                                      args);

        return err;
    }

    // Register with the routing code
    DEVICE_REGISTER_ROUTE( DeviceFW::READ,
                           DeviceFW::MEMD_VPD,
                           TARGETING::TYPE_MCS,
                           MEMD_VPDRead );
    DEVICE_REGISTER_ROUTE( DeviceFW::WRITE,
                           DeviceFW::MEMD_VPD,
                           TARGETING::TYPE_MCS,
                           MEMD_VPDWrite );

}; // end namespace MEMD_VPD


//MEMD_VpdFacade Class Functions
/**
 * @brief  Constructor
 * Planar VPD is included in the Centaur PNOR section.
 * Including with Centaur vpd minimizes the number of PNOR sections.
 */
MEMD_VpdFacade::MEMD_VpdFacade() :
IpVpdFacade(MEMD_VPD::MEMD_VPDRecords,
            (sizeof(MEMD_VPD::MEMD_VPDRecords)/sizeof(
                            MEMD_VPD::MEMD_VPDRecords[0])),
            MEMD_VPD::MEMD_VPDKeywords,
            (sizeof(MEMD_VPD::MEMD_VPDKeywords)/sizeof(
                            MEMD_VPD::MEMD_VPDKeywords[0])),
            PNOR::MEMD,  // note use of MEMD
            MEMD_VPD::g_mutex,
            VPD::VPD_INVALID) // Direct access memory
{
    TRACUCOMP(g_trac_vpd, "MEMD_VpdFacade::MEMD_VpdFacade> " );

    iv_configInfo.vpdReadPNOR = true;
    iv_configInfo.vpdReadHW = false;
    iv_configInfo.vpdWritePNOR = false;
    iv_configInfo.vpdWriteHW = false;
    iv_vpdSectionSize = MEMD_VPD::SECTION_SIZE;
    iv_vpdMaxSections = MEMD_VPD::MAX_SECTIONS;
}

/**
 * @brief returns true if the record is present in this facade.
 *        this will always return true in this function
 */
bool MEMD_VpdFacade::recordPresent( const char * i_record,
                                    uint16_t & offset,
                                    TARGETING::Target * i_target,
                                    VPD::vpdCmdTarget i_location )
{
    offset = 0;
    return true;
}
