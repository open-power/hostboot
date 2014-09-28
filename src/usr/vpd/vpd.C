/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/vpd.C $                                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <vpd/vpdreasoncodes.H>
#include <initservice/initserviceif.H>
#include <devicefw/driverif.H>
#include <hwas/hwasPlat.H>
#include <sys/mm.h>
#include "vpd.H"
#include "mvpd.H"
#include "cvpd.H"
#include "spd.H"

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
trace_desc_t* g_trac_vpd = NULL;
TRAC_INIT( & g_trac_vpd, "VPD", KILOBYTE );

// ------------------------
// Macros for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)
//#define TRACSSCOMP(args...)  TRACFCOMP(args)
#define TRACSSCOMP(args...)

namespace VPD
{

// ------------------------------------------------------------------
// getVpdLocation
// ------------------------------------------------------------------
errlHndl_t getVpdLocation ( int64_t & o_vpdLocation,
                            TARGETING::Target * i_target )
{
    errlHndl_t err = NULL;

    TRACSSCOMP( g_trac_vpd,
                ENTER_MRK"getVpdLocation()" );

    o_vpdLocation = i_target->getAttr<TARGETING::ATTR_VPD_REC_NUM>();
    TRACUCOMP( g_trac_vpd,
               INFO_MRK"Using VPD location: %d",
               o_vpdLocation );

    TRACSSCOMP( g_trac_vpd,
                EXIT_MRK"getVpdLocation()" );

    return err;
}


// ------------------------------------------------------------------
// getPnorAddr
// ------------------------------------------------------------------
errlHndl_t getPnorAddr ( pnorInformation & i_pnorInfo,
                         uint64_t &io_cachedAddr,
                         mutex_t * i_mutex )
{
    errlHndl_t err = NULL;
    PNOR::SectionInfo_t info;

    TRACSSCOMP( g_trac_vpd,
                ENTER_MRK"getPnorAddr()" );

    do
    {
        // Get SPD PNOR section info from PNOR RP
        err = PNOR::getSectionInfo( i_pnorInfo.pnorSection,
                                    info );

        if( err )
        {
            break;
        }

        // Set the globals appropriately
        mutex_lock( i_mutex );
        io_cachedAddr = info.vaddr;
        mutex_unlock( i_mutex );
    } while( 0 );

    TRACSSCOMP( g_trac_vpd,
                EXIT_MRK"getPnorAddr() - addr: 0x%08x",
                io_cachedAddr );

    return err;
}


// ------------------------------------------------------------------
// readPNOR
// ------------------------------------------------------------------
errlHndl_t readPNOR ( uint64_t i_byteAddr,
                      size_t i_numBytes,
                      void * o_data,
                      TARGETING::Target * i_target,
                      pnorInformation & i_pnorInfo,
                      uint64_t &io_cachedAddr,
                      mutex_t * i_mutex )
{
    errlHndl_t err = NULL;
    int64_t vpdLocation = 0;
    uint64_t addr = 0x0;
    const char * readAddr = NULL;

    TRACSSCOMP( g_trac_vpd,
                ENTER_MRK"readPNOR()" );

    do
    {
        // Check if we have the PNOR addr cached.
        if( 0x0 == io_cachedAddr )
        {
            err = getPnorAddr( i_pnorInfo,
                               io_cachedAddr,
                               i_mutex );

            if( err )
            {
                break;
            }
        }
        addr = io_cachedAddr;

        // Find vpd location of the target
        err = getVpdLocation( vpdLocation,
                              i_target );

        if( err )
        {
            break;
        }

        // Offset cached address by vpd location multiplier
        addr += (vpdLocation * i_pnorInfo.segmentSize);

        // Now offset into that chunk of data by i_byteAddr
        addr += i_byteAddr;

        TRACUCOMP( g_trac_vpd,
                   INFO_MRK"Address to read: 0x%08x",
                   addr );

        //TODO: Validate write is within bounds of appropriate PNOR
        //   partition/section.   RTC: 51807

        // Pull the data
        readAddr = reinterpret_cast<const char*>( addr );
        memcpy( o_data,
                readAddr,
                i_numBytes );
    } while( 0 );

    TRACSSCOMP( g_trac_vpd,
                EXIT_MRK"readPNOR()" );

    return err;
}


// ------------------------------------------------------------------
// writePNOR
// ------------------------------------------------------------------
errlHndl_t writePNOR ( uint64_t i_byteAddr,
                       size_t i_numBytes,
                       void * i_data,
                       TARGETING::Target * i_target,
                       pnorInformation & i_pnorInfo,
                       uint64_t &io_cachedAddr,
                       mutex_t * i_mutex )
{
    errlHndl_t err = NULL;
    int64_t vpdLocation = 0;
    uint64_t addr = 0x0;
    const char * writeAddr = NULL;

    TRACSSCOMP( g_trac_vpd,
                ENTER_MRK"writePNOR()" );

    do
    {
        // Check if we have the PNOR addr cached.
        if( 0x0 == io_cachedAddr )
        {
            err = getPnorAddr( i_pnorInfo,
                               io_cachedAddr,
                               i_mutex );

            if( err )
            {
                break;
            }
        }
        addr = io_cachedAddr;

        // Find vpd location of the target
        err = getVpdLocation( vpdLocation,
                              i_target );

        if( err )
        {
            break;
        }

        // Offset cached address by vpd location multiplier
        addr += (vpdLocation * i_pnorInfo.segmentSize);

        // Now offset into that chunk of data by i_byteAddr
        addr += i_byteAddr;

        //TODO: Validate write is within bounds of appropriate PNOR
        //   partition/section.   RTC: 51807

        TRACUCOMP( g_trac_vpd,
                   INFO_MRK"Address to write: 0x%08x",
                   addr );

        // Write the data
        writeAddr = reinterpret_cast<const char*>( addr );
        memcpy( (void*)(writeAddr),
                i_data,
                i_numBytes );

        // @todo RTC:117042 - enable flush once PNOR writes supported
        // Flush the page to make sure it gets to the PNOR
#if 0
        int rc = mm_remove_pages( FLUSH, (void*)addr, i_numBytes );
        if( rc )
        {
            TRACFCOMP(g_trac_vpd,ERR_MRK"writePNOR() Error from mm_remove_pages, rc=%d",rc);
            /*@
             * @errortype
             * @moduleid     VPD_WRITE_PNOR
             * @reasoncode   VPD_REMOVE_PAGES_FAIL
             * @userdata1    Requested Address
             * @userdata2    rc from mm_remove_pages
             * @devdesc      writePNOR mm_remove_pages FLUSH failed
             */
            err = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            VPD_WRITE_PNOR,
                            VPD_REMOVE_PAGES_FAIL,
                            addr,
                            TO_UINT64(rc),
                            true /*Add HB Software Callout*/ );
        }
#endif
    } while( 0 );

    TRACSSCOMP( g_trac_vpd,
                EXIT_MRK"writePNOR()" );

    return err;
}

// ------------------------------------------------------------------
// sendMboxWriteMsg
// ------------------------------------------------------------------
errlHndl_t sendMboxWriteMsg ( size_t i_numBytes,
                              void * i_data,
                              TARGETING::Target * i_target,
                              VPD_MSG_TYPE i_type,
                              VpdWriteMsg_t& i_record )
{
    errlHndl_t l_err = NULL;
    msg_t* msg = NULL;

    TRACSSCOMP( g_trac_vpd,
                ENTER_MRK"sendMboxWriteMsg()" );

    do
    {
        //Create a mailbox message to send to FSP
        msg = msg_allocate();
        msg->type = i_type;
        msg->data[0] = i_record.data0;
        msg->data[1] = i_numBytes;

        //Copy the data into the message
        msg->extra_data = malloc( i_numBytes );
        memcpy( msg->extra_data, i_data, i_numBytes );

        TRACFCOMP( g_trac_vpd,
                   INFO_MRK"sendMboxWriteMsg: Send msg to FSP to write VPD type %.8X, record %d, offset 0x%X",
                   i_type,
                   i_record.rec_num,
                   i_record.offset );

        //We only send VPD update when we have SP Base Services
        if( !INITSERVICE::spBaseServicesEnabled() )
        {
            TRACFCOMP(g_trac_vpd, INFO_MRK "No SP Base Services, skipping VPD write");
            TRACFBIN( g_trac_vpd, "msg=", msg, sizeof(msg_t) );
            TRACFBIN( g_trac_vpd, "extra=", msg->extra_data, i_numBytes );
            free (msg->extra_data);
            msg_free( msg );

            break;
        }

        l_err = MBOX::send( MBOX::FSP_VPD_MSGQ, msg );
        if( l_err )
        {
            TRACFCOMP(g_trac_vpd,
                      ERR_MRK "Failed sending VPD to FSP for %.8X",
                      TARGETING::get_huid(i_target));
            ERRORLOG::ErrlUserDetailsTarget(i_target).addToLog(l_err);

            l_err->collectTrace("VPD",1024);
            if( VPD_WRITE_DIMM == i_type )
            {
                l_err->collectTrace("SPD",1024);
            }

            // just commit the log and move on, nothing else to do
            errlCommit( l_err, VPD_COMP_ID );
            l_err = NULL;

            free( msg->extra_data );
            msg->extra_data = NULL;
            msg_free( msg );
        }
    } while( 0 );

    TRACSSCOMP( g_trac_vpd,
                EXIT_MRK"sendMboxWriteMsg()" );

    return l_err;
}


// ------------------------------------------------------------------
// resolveVpdSource
// ------------------------------------------------------------------
bool resolveVpdSource( TARGETING::Target * i_target,
                       bool i_rwPnorEnabled,
                       bool i_rwHwEnabled,
                       vpdCmdTarget i_vpdCmdTarget,
                       vpdCmdTarget& o_vpdSource )
{
    bool badConfig = false;
    o_vpdSource = VPD::INVALID_LOCATION;

    if( i_vpdCmdTarget == VPD::PNOR )
    {
        if( i_rwPnorEnabled )
        {
            o_vpdSource = VPD::PNOR;
        }
        else
        {
            badConfig = true;
            TRACFCOMP(g_trac_vpd,"resolveVpdSource: VpdCmdTarget=PNOR but READ/WRITE PNOR CONFIG is disabled");
        }
    }
    else if( i_vpdCmdTarget == VPD::SEEPROM )
    {
        if( i_rwHwEnabled )
        {
            o_vpdSource = VPD::SEEPROM;
        }
        else
        {
            badConfig = true;
            TRACFCOMP(g_trac_vpd,"resolveVpdSource: VpdCmdTarget=SEEPROM but READ/WRITE HW CONFIG is disabled");
        }
    }
    else  // i_vpdCmdTarget == VPD::AUTOSELECT
    {
        if( i_rwPnorEnabled &&
            i_rwHwEnabled )
        {
            // PNOR needs to be loaded before we can use it
            TARGETING::ATTR_VPD_SWITCHES_type vpdSwitches =
                    i_target->getAttr<TARGETING::ATTR_VPD_SWITCHES>();
            if( vpdSwitches.pnorLoaded )
            {
                o_vpdSource = VPD::PNOR;
            }
            else
            {
                o_vpdSource = VPD::SEEPROM;
            }
        }
        else if( i_rwPnorEnabled )
        {
            o_vpdSource = VPD::PNOR;
        }
        else if( i_rwHwEnabled )
        {
            o_vpdSource = VPD::SEEPROM;
        }
        else
        {
            badConfig = true;
            TRACFCOMP(g_trac_vpd,"resolveVpdSource: READ/WRITE PNOR CONFIG and READ/WRITE HW CONFIG disabled");
        }
    }

    return badConfig;
}


// ------------------------------------------------------------------
// ensureCacheIsInSync
// ------------------------------------------------------------------
errlHndl_t ensureCacheIsInSync ( TARGETING::Target * i_target )
{
    errlHndl_t l_err = NULL;

    TRACSSCOMP( g_trac_vpd, ENTER_MRK"ensureCacheIsInSync() " );

    IpVpdFacade& l_ipvpd = Singleton<MvpdFacade>::instance();

    vpdRecord  l_record    = 0;
    vpdKeyword l_keywordPN = 0;
    vpdKeyword l_keywordSN = 0;

    TARGETING::TYPE l_type = i_target->getAttr<TARGETING::ATTR_TYPE>();

    if( l_type == TARGETING::TYPE_PROC )
    {
        l_record    = MVPD::VINI;
        l_keywordPN = MVPD::PN;
        l_keywordSN = MVPD::SN;
    }
    else if( l_type == TARGETING::TYPE_MEMBUF )
    {
        l_ipvpd     = Singleton<CvpdFacade>::instance();
        l_record    = CVPD::VINI;
        l_keywordPN = CVPD::PN;
        l_keywordSN = CVPD::SN;
    }
    else if( l_type == TARGETING::TYPE_DIMM )
    {
        // SPD does not have a singleton instance
        // SPD does not use records
        l_keywordPN = SPD::MODULE_PART_NUMBER;
        l_keywordSN = SPD::MODULE_SERIAL_NUMBER;
    }
    else
    {
        TRACFCOMP(g_trac_vpd,ERR_MRK"ensureCacheIsInSync() Unexpected target type, huid=0x%X",TARGETING::get_huid(i_target));
        /*@
         * @errortype
         * @moduleid     VPD_ENSURE_CACHE_IS_IN_SYNC
         * @reasoncode   VPD_UNEXPECTED_TARGET_TYPE
         * @userdata1    Target HUID
         * @userdata2    <UNUSED>
         * @devdesc      Unexpected target type
         */
        l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                VPD_ENSURE_CACHE_IS_IN_SYNC,
                                VPD_UNEXPECTED_TARGET_TYPE,
                                TO_UINT64(TARGETING::get_huid(i_target)),
                                0x0,
                                true /*Add HB Software Callout*/ );
        return l_err;
    }

    do
    {
        // Compare the Part Numbers in PNOR/SEEPROM
        bool l_matchPN = false;
        if( ( l_type == TARGETING::TYPE_PROC   ) ||
            ( l_type == TARGETING::TYPE_MEMBUF ) )
        {
            l_err = l_ipvpd.cmpPnorToSeeprom( i_target,
                                              l_record,
                                              l_keywordPN,
                                              l_matchPN );
        }
        else if( l_type == TARGETING::TYPE_DIMM )
        {
            l_err = SPD::cmpPnorToSeeprom( i_target,
                                           l_keywordPN,
                                           l_matchPN );
        }
        if (l_err)
        {
            TRACFCOMP(g_trac_vpd,ERR_MRK"VPD::ensureCacheIsInSync: Error checking for PNOR/SEEPROM PN match");
            break;
        }

        // Compare the Serial Numbers in PNOR/SEEPROM
        bool l_matchSN = false;
        if( ( l_type == TARGETING::TYPE_PROC   ) ||
            ( l_type == TARGETING::TYPE_MEMBUF ) )
        {
            l_err = l_ipvpd.cmpPnorToSeeprom( i_target,
                                              l_record,
                                              l_keywordSN,
                                              l_matchSN );
        }
        else if( l_type == TARGETING::TYPE_DIMM )
        {
            l_err = SPD::cmpPnorToSeeprom( i_target,
                                           l_keywordSN,
                                           l_matchSN );
        }
        if( l_err )
        {
            TRACFCOMP(g_trac_vpd,ERR_MRK"VPD::ensureCacheIsInSync: Error checking for PNOR/SEEPROM SN match");
            break;
        }

        // If we did not match, we need to load SEEPROM VPD data into PNOR
        if( l_matchPN && l_matchSN )
        {
            TRACFCOMP(g_trac_vpd,"VPD::ensureCacheIsInSync: PNOR_PN/SN = SEEPROM_PN/SN");
        }
        else
        {
            TRACFCOMP(g_trac_vpd,"VPD::ensureCacheIsInSync: PNOR_PN/SN != SEEPROM_PN/SN, Loading PNOR from SEEPROM");

            //Set the targets as changed since the p/n's don't match
            HWAS::markTargetChanged(i_target);

            // Load the PNOR data from the SEEPROM
            if( ( l_type == TARGETING::TYPE_PROC   ) ||
                ( l_type == TARGETING::TYPE_MEMBUF ) )
            {
                l_err = l_ipvpd.loadPnor( i_target );
            }
            else if( l_type == TARGETING::TYPE_DIMM )
            {
                l_err = SPD::loadPnor( i_target );
            }
            if( l_err )
            {
                TRACFCOMP(g_trac_vpd,"Error loading SEEPROM VPD into PNOR");
                break;
            }
        }

        // Set target attribute switch that says VPD is loaded into PNOR
        TARGETING::ATTR_VPD_SWITCHES_type vpdSwitches =
                    i_target->getAttr<TARGETING::ATTR_VPD_SWITCHES>();
        vpdSwitches.pnorLoaded = 1;
        i_target->setAttr<TARGETING::ATTR_VPD_SWITCHES>( vpdSwitches );

    } while(0);

    TRACSSCOMP( g_trac_vpd, EXIT_MRK"ensureCacheIsInSync()" );

    return l_err;
}


// ------------------------------------------------------------------
// invalidatePnorCache
// ------------------------------------------------------------------
errlHndl_t invalidatePnorCache ( TARGETING::Target * i_target )
{
    errlHndl_t l_err = NULL;

    TRACSSCOMP( g_trac_vpd, ENTER_MRK"invalidatePnorCache() " );

    TARGETING::TYPE l_type = i_target->getAttr<TARGETING::ATTR_TYPE>();

    if( l_type == TARGETING::TYPE_PROC )
    {
        l_err = Singleton<MvpdFacade>::instance().invalidatePnor( i_target );
    }
    else if( l_type == TARGETING::TYPE_MEMBUF )
    {
        l_err = Singleton<CvpdFacade>::instance().invalidatePnor( i_target );
    }
    else if( l_type == TARGETING::TYPE_DIMM )
    {
        l_err = SPD::invalidatePnor( i_target );
    }

    // Clear target attribute switch that says VPD is loaded into PNOR
    TARGETING::ATTR_VPD_SWITCHES_type vpdSwitches =
                i_target->getAttr<TARGETING::ATTR_VPD_SWITCHES>();
    vpdSwitches.pnorLoaded = 0;
    i_target->setAttr<TARGETING::ATTR_VPD_SWITCHES>( vpdSwitches );

    TRACSSCOMP( g_trac_vpd, EXIT_MRK"invalidatePnorCache()" );

    return l_err;
}


}; //end VPD namespace
