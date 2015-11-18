/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/dvpd.C $                                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2016                        */
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
#include <vpd/dvpdenums.H>
#include <vpd/vpd_if.H>
#include <i2c/eepromif.H>
#include <config.h>
#include "dvpd.H"
#include "cvpd.H"
#include "vpd.H"
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

namespace DVPD
{
    // local functions
    bool dvpdPresent ( TARGETING::Target * i_target );

    // ----------------------------------------------
    // Globals
    // ----------------------------------------------
    mutex_t g_mutex = MUTEX_INITIALIZER;


    /**
     * @brief This function will perform the steps required to do a read from
     *      the Hostboot DVPD data.
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
    errlHndl_t dvpdRead ( DeviceFW::OperationType i_opType,
                          TARGETING::Target * i_target,
                          void * io_buffer,
                          size_t & io_buflen,
                          int64_t i_accessType,
                          va_list i_args )
    {
        errlHndl_t err = NULL;
        IpVpdFacade::input_args_t args;
        args.record = ((dvpdRecord)va_arg( i_args, uint64_t ));
        args.keyword = ((dvpdKeyword)va_arg( i_args, uint64_t ));
        args.location = ((VPD::vpdCmdTarget)va_arg( i_args, uint64_t ));

        TRACSSCOMP( g_trac_vpd,
                    ENTER_MRK"dvpdRead()" );

        err = Singleton<DvpdFacade>::instance().read(i_target,
                                                     io_buffer,
                                                     io_buflen,
                                                     args);

        return err;
    }


    /**
     * @brief This function will perform the steps required to do a write to
     *      the Hostboot DVPD data.
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
    errlHndl_t dvpdWrite ( DeviceFW::OperationType i_opType,
                           TARGETING::Target * i_target,
                           void * io_buffer,
                           size_t & io_buflen,
                           int64_t i_accessType,
                           va_list i_args )
    {
        errlHndl_t err = NULL;
        IpVpdFacade::input_args_t args;
        args.record = ((dvpdRecord)va_arg( i_args, uint64_t ));
        args.keyword = ((dvpdKeyword)va_arg( i_args, uint64_t ));
        args.location = ((VPD::vpdCmdTarget)va_arg( i_args, uint64_t ));

        TRACSSCOMP( g_trac_vpd,
                    ENTER_MRK"dvpdWrite()" );


        err = Singleton<DvpdFacade>::instance().write(i_target,
                                                      io_buffer,
                                                      io_buflen,
                                                      args);

        return err;
    }

    // Register with the routing code
    DEVICE_REGISTER_ROUTE( DeviceFW::READ,
                           DeviceFW::DVPD,
                           TARGETING::TYPE_MCS,
                           dvpdRead );
    DEVICE_REGISTER_ROUTE( DeviceFW::WRITE,
                           DeviceFW::DVPD,
                           TARGETING::TYPE_MCS,
                           dvpdWrite );

}; // end namespace DVPD

#if !defined(__HOSTBOOT_RUNTIME)
// --------------------------------------------------------
// Presence Detection
//---------------------------------------------------------

/**
 * @brief Performs a presence detect operation on MCSs
 *
 * Although not a physical part, presence detect confirms access
 * to direct access memory vpd.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        Presence detect target
 * @param[in/out] io_buffer     Read: Pointer to output data storage
 *                              Write: Pointer to input data storage
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes, always 1)
 *                              Output: Success = 1, Failure = 0
 * @param[in]   i_accessType    DeviceFW::AccessType enum (userif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, there are no arguments.
 * @return  errlHndl_t
 */
errlHndl_t directMemoryPresenceDetect(DeviceFW::OperationType i_opType,
                              TARGETING::Target* i_target,
                              void* io_buffer,
                              size_t& io_buflen,
                              int64_t i_accessType,
                              va_list i_args)
{
    errlHndl_t l_errl = NULL;
    bool dvpd_present = false;

    TRACSSCOMP(g_trac_vpd,
                  ENTER_MRK "directMemoryPresenceDetect");

    if (unlikely(io_buflen < sizeof(bool)))
    {
        TRACFCOMP(g_trac_vpd,
                  ERR_MRK "directMemoryPresenceDetect> Invalid data length: %d",
                  io_buflen);
        /*@
         * @errortype
         * @moduleid     VPD::VPD_DVPD_PRESENCEDETECT
         * @reasoncode   VPD::VPD_INVALID_LENGTH
         * @userdata1    Data Length
         * @devdesc      presenceDetect> Invalid data length (!= 1 bytes)
         */
        l_errl =
                new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        VPD::VPD_DVPD_PRESENCEDETECT,
                                        VPD::VPD_INVALID_LENGTH,
                                        TO_UINT64(io_buflen),
                                        true /*SW error*/);
        io_buflen = 0;
        return l_errl;
    }

    dvpd_present = DVPD::dvpdPresent( i_target );
#if defined(CONFIG_MEMVPD_READ_FROM_HW) && defined(CONFIG_MEMVPD_READ_FROM_PNOR)
    if( dvpd_present )
    {
        // Check if the VPD data in the PNOR matches the SEEPROM
        l_errl = VPD::ensureCacheIsInSync( i_target );
        if( l_errl )
        {
            TRACFCOMP(g_trac_vpd,ERR_MRK "nodePresenceDetect>"
                    " Error during ensureCacheIsInSync (DVPD)" );
            errlCommit( l_errl, FSI_COMP_ID );
        }
    }
    else
    {
        TRACFCOMP(g_trac_vpd,
                  ERR_MRK "directMemoryPresenceDetect> failed presence detect");

        // Invalidate DVPD in the PNOR
        l_errl = VPD::invalidatePnorCache(i_target);
        if (l_errl)
        {
            TRACFCOMP( g_trac_vpd, "Error invalidating DVPD in PNOR" );
            errlCommit( l_errl, VPD_COMP_ID );
        }
    }
#endif

    memcpy(io_buffer, &dvpd_present, sizeof(dvpd_present));
    io_buflen = sizeof(dvpd_present);

    TRACSSCOMP(g_trac_vpd,
                  EXIT_MRK "directMemoryPresenceDetect = %d",dvpd_present);
    return NULL;
}

// Register as the presence detect for MCSs.
DEVICE_REGISTER_ROUTE(DeviceFW::READ,
                      DeviceFW::PRESENT,
                      TARGETING::TYPE_MCS,
                      directMemoryPresenceDetect);
#endif

bool DVPD::dvpdPresent( TARGETING::Target * i_target )
{
    TRACSSCOMP( g_trac_vpd, ENTER_MRK"dvpdPresent()");
#if(defined( CONFIG_MEMVPD_READ_FROM_HW ) && !defined( __HOSTBOOT_RUNTIME) )

    return EEPROM::eepromPresence( i_target );

#else
    return Singleton<DvpdFacade>::instance().hasVpdPresent( i_target,
//TODO RTC 144519 Update recod/keyword once records/keywords defined
//                to be used as "sniff test" that vpd is readable.
                                                            CVPD::VEIR,
                                                            CVPD::PF );
#endif
}


//DVPD Class Functions
/**
 * @brief  Constructor
 * Planar VPD is included in the Centaur PNOR section.
 * Including with Centaur vpd minimizes the number of PNOR sections.
 */
DvpdFacade::DvpdFacade() :
IpVpdFacade(DVPD::SECTION_SIZE,
            DVPD::MAX_SECTIONS,
            DVPD::dvpdRecords,
            (sizeof(DVPD::dvpdRecords)/sizeof(DVPD::dvpdRecords[0])),
            DVPD::dvpdKeywords,
            (sizeof(DVPD::dvpdKeywords)/sizeof(DVPD::dvpdKeywords[0])),
            PNOR::CENTAUR_VPD,  // note use of CVPD
            DVPD::g_mutex,
            VPD::VPD_WRITE_MCS) // Direct access memory
{
    TRACUCOMP(g_trac_vpd, "DvpdFacade::DvpdFacade> " );

#ifdef CONFIG_MEMVPD_READ_FROM_PNOR
    iv_configInfo.vpdReadPNOR = true;
#else
    iv_configInfo.vpdReadPNOR = false;
#endif
#ifdef CONFIG_MEMVPD_READ_FROM_HW
    iv_configInfo.vpdReadHW = true;
#else
    iv_configInfo.vpdReadHW = false;
#endif
#ifdef CONFIG_MEMVPD_WRITE_TO_PNOR
    iv_configInfo.vpdWritePNOR = true;
#else
    iv_configInfo.vpdWritePNOR = false;
#endif
#ifdef CONFIG_MEMVPD_WRITE_TO_HW
    iv_configInfo.vpdWriteHW = true;
#else
    iv_configInfo.vpdWriteHW = false;
#endif
}
// Retrun lists of records that should be copied to pnor.
void DvpdFacade::getRecordLists(
                const  recordInfo* & o_list1VpdRecords,
                uint64_t           & o_list1RecSize,
                const  recordInfo* & o_list2VpdRecords,
                uint64_t           & o_list2RecSize)
{
    // Always return this object's list
    o_list1VpdRecords = iv_vpdRecords;
    o_list1RecSize = iv_recSize;

    // If the planar eeprom is being shared with direct memory vpd,
    // then return the pvpd list as the secondlist.
    // TODO RTC 144519 If there is a separate eeprom for planar
    // and direct memory VPD, then list2 = NULL size=0;
    // The pvpd and cvpd may need an update on what configs to check for
    // sharing.
#ifdef CONFIG_PVPD_READ_FROM_PNOR
    o_list2VpdRecords = Singleton<PvpdFacade>::instance().iv_vpdRecords;
    o_list2RecSize = Singleton<PvpdFacade>::instance().iv_recSize;
#else
    o_list2VpdRecords = NULL;
    o_list2RecSize = 0;
#endif
}

