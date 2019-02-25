/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/cvpd.C $                                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2019                        */
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
#include <targeting/common/commontargeting.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>
#include <devicefw/driverif.H>
#include <vfs/vfs.H>
#include <vpd/vpdreasoncodes.H>
#include <vpd/cvpdenums.H>
#include <vpd/vpd_if.H>
#include <i2c/eepromif.H>
#include <config.h>
#include "cvpd.H"
#include "pvpd.H"
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

#ifdef CONFIG_SECUREBOOT
        // Load the secure section just in case if we're using it
        bool l_didload = false;
        err = Singleton<CvpdFacade>::instance().
          loadUnloadSecureSection( args, i_target, true, l_didload );
#endif

        if( !err )
        {
            err = Singleton<CvpdFacade>::instance().read(i_target,
                                                         io_buffer,
                                                         io_buflen,
                                                         args);
        }

#ifdef CONFIG_SECUREBOOT
        if( l_didload )
        {
            errlHndl_t err2 = Singleton<CvpdFacade>::instance().
              loadUnloadSecureSection( args, i_target, false, l_didload );
            if( err2 && !err )
            {
                err = err2;
                err2 = nullptr;
            }
            else if( err2 )
            {
                err2->plid(err->plid());
                errlCommit( err2, VPD_COMP_ID );
            }
        }
#endif

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
    TRACSSCOMP( g_trac_vpd, ENTER_MRK"cvpdPresent()");
#if(defined( CONFIG_MEMVPD_READ_FROM_HW ) && !defined( __HOSTBOOT_RUNTIME) )

    return EEPROM::eepromPresence( i_target );

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
IpVpdFacade(CVPD::cvpdRecords,
            (sizeof(CVPD::cvpdRecords)/sizeof(CVPD::cvpdRecords[0])),
            CVPD::cvpdKeywords,
            (sizeof(CVPD::cvpdKeywords)/sizeof(CVPD::cvpdKeywords[0])),
            PNOR::CENTAUR_VPD,
            CVPD::g_mutex,
            VPD::VPD_WRITE_MEMBUF)
{
    TRACUCOMP(g_trac_vpd, "CvpdFacade::CvpdFacade> " );

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


// Get System Target
TARGETING::Target* sysTgt = NULL;
TARGETING::targetService().getTopLevelTarget(sysTgt);

assert(sysTgt != NULL,"CvpdFacade: "
       "System target was NULL.");

iv_vpdSectionSize = sysTgt->getAttr<TARGETING::ATTR_CVPD_SIZE>();

iv_vpdMaxSections = sysTgt->getAttr<TARGETING::ATTR_CVPD_MAX_SECTIONS>();

TRACDCOMP( g_trac_vpd, "CvpdFacade VpdSectionSize: %d"
           "MaxSections: %d ", iv_vpdSectionSize,iv_vpdMaxSections);
}

// Retrun lists of records that should be copied to pnor.
void CvpdFacade::getRecordLists(
                const  recordInfo* & o_primaryVpdRecords,
                uint64_t           & o_primaryRecSize,
                const  recordInfo* & o_altVpdRecords,
                uint64_t           & o_altRecSize)
{
    // Always return this object's list
    o_primaryVpdRecords = iv_vpdRecords;
    o_primaryRecSize = iv_recSize;

    // If the planar errprom  being shared with a mem buf,
    // then return the pvpd list as the alternative record list.
    // At thip point, if the membufs are be processed, then the node
    // might not have been discovered yet. If pvpd is being cached, then
    // include the pvpd list as the altnative.
#ifdef CONFIG_PVPD_READ_FROM_PNOR
    o_altVpdRecords = Singleton<PvpdFacade>::instance().iv_vpdRecords;
    o_altRecSize = Singleton<PvpdFacade>::instance().iv_recSize;
#else
    o_altVpdRecords = NULL;
    o_altRecSize = 0;
#endif
}

/**
 * @brief Callback function to check for a record override and
 *        set iv_overridePtr appropriately
 */
errlHndl_t CvpdFacade::checkForRecordOverride( const char* i_record,
                                               TARGETING::Target* i_target,
                                               uint8_t*& o_ptr )
{
    TRACFCOMP(g_trac_vpd,ENTER_MRK"CvpdFacade::checkForRecordOverride( %s, 0x%.8X )",
              i_record, get_huid(i_target));
    errlHndl_t l_errl = nullptr;
    o_ptr = nullptr;

    assert( i_record != nullptr, "CvpdFacade::checkForRecordOverride() i_record is null" );
    assert( i_target != nullptr, "CvpdFacade::checkForRecordOverride() i_target is null" );

    VPD::RecordTargetPair_t l_recTarg =
      VPD::makeRecordTargetPair(i_record,i_target);

    do
    {
        // We only support overriding SPDX
        if( strcmp( i_record, "SPDX" ) )
        {
            TRACFCOMP(g_trac_vpd,"Record %s has no override", i_record);
            mutex_lock(&iv_mutex); //iv_overridePtr is not threadsafe
            iv_overridePtr[l_recTarg] = nullptr;
            mutex_unlock(&iv_mutex);
            break;
        }

        // Compare the 5th nibble
        constexpr uint32_t l_vmMask = 0x00000F00;
        input_args_t l_args = { CVPD::SPDX, CVPD::VM, VPD::AUTOSELECT };
        l_errl = getMEMDFromPNOR( l_args,
                                  i_target,
                                  l_vmMask );
        if( l_errl )
        {
            TRACFCOMP(g_trac_vpd,ERR_MRK"ERROR from getMEMDFromPNOR.");
            break;
        }

    } while(0);

    // For any error, we should reset the override map so that we'll
    //  attempt everything again the next time we want VPD
    mutex_lock(&iv_mutex); //iv_overridePtr is not threadsafe
    if( l_errl )
    {
        iv_overridePtr.erase(l_recTarg);
    }
    else
    {
        o_ptr = iv_overridePtr[l_recTarg];
    }
    mutex_unlock(&iv_mutex);

    return l_errl;
}

#ifdef CONFIG_SECUREBOOT
/**
 * @brief Load/unload the appropriate secure section for
 *        an overriden PNOR section
 */
errlHndl_t CvpdFacade::loadUnloadSecureSection( input_args_t i_args,
                                                TARGETING::Target* i_target,
                                                bool i_load,
                                                bool& o_loaded )
{
    errlHndl_t l_err = nullptr;
    o_loaded = false;

#ifndef __HOSTBOOT_RUNTIME
    // Only relevant for SPDX
    if( i_args.record != CVPD::SPDX )
    {
        return nullptr;
    }

    const char* l_record = nullptr;
    l_err = translateRecord( i_args.record, l_record );
    if( l_err )
    {
        return l_err;
    }

    // Jump out if we don't have an override
    VPD::RecordTargetPair_t l_recTarg =
      VPD::makeRecordTargetPair(l_record,i_target);
    mutex_lock(&iv_mutex); //iv_overridePtr is not threadsafe
    VPD::OverrideMap_t::iterator l_overItr = iv_overridePtr.find(l_recTarg);
    mutex_unlock(&iv_mutex);
    if( l_overItr == iv_overridePtr.end() )
    {
        return nullptr;
    }

    if( i_load )
    {
        l_err = loadSecureSection(PNOR::MEMD);
        if( !l_err )
        {
            o_loaded = true;
        }
    }
    else
    {
        l_err = unloadSecureSection(PNOR::MEMD);
    }
#endif

    return l_err;
}
#endif
