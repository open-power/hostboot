/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/vpd.C $                                           */
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
#include "pvpd.H"
#include "spd.H"
#include "ipvpd.H"

// ----------------------------------------------
// Trace - defined in vpd_common
// ----------------------------------------------
extern trace_desc_t* g_trac_vpd;

// ------------------------
// Macros for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)
//#define TRACSSCOMP(args...)  TRACFCOMP(args)
#define TRACSSCOMP(args...)

namespace VPD
{

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

        // Flush the page to make sure it gets to the PNOR
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
// setPartAndSerialNumberAttributes
// ------------------------------------------------------------------
void setPartAndSerialNumberAttributes( TARGETING::Target * i_target )
{
    errlHndl_t l_err = NULL;
    vpdKeyword l_serialNumberKeyword = 0;
    size_t l_dataSize = 0;

    TARGETING::TYPE l_type = i_target->getAttr<TARGETING::ATTR_TYPE>();

    TRACSSCOMP(g_trac_vpd, ENTER_MRK"vpd.C::setPartAndSerialNumberAttributes");
    do
    {
            IpVpdFacade * l_ipvpd = &(Singleton<MvpdFacade>::instance());
            if(l_type == TARGETING::TYPE_MEMBUF)
            {
                l_ipvpd = &(Singleton<CvpdFacade>::instance());
            }
            else if(l_type == TARGETING::TYPE_NODE)
            {
                l_ipvpd = &(Singleton<PvpdFacade>::instance());
            }

            IpVpdFacade::input_args_t l_args;

            l_err = getPnAndSnRecordAndKeywords( i_target,
                                                 l_type,
                                                 l_args.record,
                                                 l_args.keyword,
                                                 l_serialNumberKeyword );

            if( l_err )
            {
                TRACFCOMP(g_trac_vpd, "setPartAndSerialNumberAttributes::Error getting record/keywords for PN/SN");
                errlCommit(l_err, VPD_COMP_ID);
                l_err = NULL;
                break;
            }

            // Get the size of the part number
            l_err = l_ipvpd->read( i_target,
                                   NULL,
                                   l_dataSize,
                                   l_args );

            if( l_err )
            {
                TRACFCOMP(g_trac_vpd, " vpd.C::setPartAndSerialNumbers::read part number size");
                errlCommit(l_err, VPD_COMP_ID);
                l_err = NULL;
                break;
            }

            //get the actual part number data
            uint8_t l_partNumberData[l_dataSize];
            l_err = l_ipvpd->read( i_target,
                                   l_partNumberData,
                                   l_dataSize,
                                   l_args );
            if( l_err )
            {
                TRACFCOMP(g_trac_vpd, "vpd.C::setPartAndSerialNumbers::read part number");
                errlCommit(l_err, VPD_COMP_ID);
                l_err = NULL;
                break;
            }

            // Set the part number attribute
            TARGETING::ATTR_PART_NUMBER_type l_partNumber = {0};
            size_t expectedPNSize = sizeof(l_partNumber);
            if(expectedPNSize < l_dataSize)
            {
                TRACFCOMP(g_trac_vpd, "Part number data to large for attribute. Expected: %d Actual: %d",
                        expectedPNSize, l_dataSize);
            }
            else
            {
                memcpy( l_partNumber, l_partNumberData, l_dataSize );
                i_target->trySetAttr<TARGETING::ATTR_PART_NUMBER>(l_partNumber);
            }
            // Get the serial number attribute data
            l_args.keyword = l_serialNumberKeyword;
            l_dataSize = 0;
            l_err = l_ipvpd->read( i_target,
                          NULL,
                          l_dataSize,
                          l_args );

            if( l_err )
            {
                TRACFCOMP(g_trac_vpd, "vpd.C::setPartAndSerialNumbers::read serial number size");
                errlCommit( l_err, VPD_COMP_ID );
                l_err = NULL;
                break;
            }

            // Get the actual serial number data
            uint8_t l_serialNumberData[l_dataSize];
            l_err = l_ipvpd->read( i_target,
                                   l_serialNumberData,
                                   l_dataSize,
                                   l_args );

            if( l_err )
            {
                TRACFCOMP(g_trac_vpd, "vpd.C::setPartAndSerialNumbers::serial number");
                errlCommit( l_err, VPD_COMP_ID );
                l_err = NULL;
                break;
            }

            // set the serial number attribute
            TARGETING::ATTR_SERIAL_NUMBER_type l_serialNumber = {0};
            size_t expectedSNSize = sizeof(l_serialNumber);
            if(expectedSNSize < l_dataSize)
            {
                TRACFCOMP(g_trac_vpd, "Serial number data to large for attribute. Expected: %d Actual: %d",
                        expectedSNSize, l_dataSize);
            }
            else
            {
                memcpy( l_serialNumber, l_serialNumberData, l_dataSize );
                i_target->trySetAttr
                            <TARGETING::ATTR_SERIAL_NUMBER>(l_serialNumber);
            }


    }while( 0 );

}



// ------------------------------------------------------------------
// getPnAndSnRecordAndKeywords
// ------------------------------------------------------------------
errlHndl_t getPnAndSnRecordAndKeywords( TARGETING::Target * i_target,
                                  TARGETING::TYPE i_type,
                                  vpdRecord & io_record,
                                  vpdKeyword & io_keywordPN,
                                  vpdKeyword & io_keywordSN )
{
    TRACFCOMP(g_trac_vpd, ENTER_MRK"getPnAndSnRecordAndKeywords()");
    errlHndl_t l_err = NULL;
    do{

        if( i_type == TARGETING::TYPE_PROC )
        {
            io_record    = MVPD::VRML;
            io_keywordPN = MVPD::PN;
            io_keywordSN = MVPD::SN;
        }
        else if( i_type == TARGETING::TYPE_MEMBUF )
        {
#if defined(CONFIG_MEMVPD_READ_FROM_HW) && defined(CONFIG_MEMVPD_READ_FROM_PNOR)
            IpVpdFacade* l_ipvpd     = &(Singleton<CvpdFacade>::instance());
            io_record    = CVPD::OPFR;
            io_keywordPN = CVPD::VP;
            io_keywordSN = CVPD::VS;

            bool l_zeroPN;
            l_err = l_ipvpd->cmpSeepromToZero( i_target,
                                               io_record,
                                               io_keywordPN,
                                               l_zeroPN );
            if (l_err)
            {
                TRACFCOMP(g_trac_vpd,ERR_MRK"VPD::getPnAndSnRecordAndKeywords: Error checking if OPFR:VP == 0");
                break;
            }

            bool l_zeroSN;
            l_err = l_ipvpd->cmpSeepromToZero( i_target,
                                               io_record,
                                               io_keywordSN,
                                               l_zeroSN );
            if (l_err)
            {
                TRACFCOMP(g_trac_vpd,ERR_MRK"VPD::getPnAndSnRecordAndKeywords: Error checking if OPFR:VS == 0");
                break;
            }

            // If VP and VS are zero, use VINI instead
            if( l_zeroPN && l_zeroSN )
            {
                TRACFCOMP(g_trac_vpd, "setting cvpd to VINI PN SN");
                io_record    = CVPD::VINI;
                io_keywordPN = CVPD::PN;
                io_keywordSN = CVPD::SN;
            }
#else
            io_record    = CVPD::VINI;
            io_keywordPN = CVPD::PN;
            io_keywordSN = CVPD::SN;
#endif
        }
        else if( i_type == TARGETING::TYPE_DIMM )
        {
            // SPD does not have singleton instance
            // SPD does not use records
            io_keywordPN = SPD::MODULE_PART_NUMBER;
            io_keywordSN = SPD::MODULE_SERIAL_NUMBER;
        }
        else if( i_type == TARGETING::TYPE_NODE )
        {
#if defined(CONFIG_PVPD_READ_FROM_HW) && defined(CONFIG_PVPD_READ_FROM_PNOR)
            IpVpdFacade* l_ipvpd     = &(Singleton<PvpdFacade>::instance());
            io_record    = PVPD::OPFR;
            io_keywordPN = PVPD::VP;
            io_keywordSN = PVPD::VS;

            bool l_zeroPN;
            l_err = l_ipvpd->cmpSeepromToZero( i_target,
                                               io_record,
                                               io_keywordPN,
                                               l_zeroPN );
            if (l_err)
            {
                TRACFCOMP(g_trac_vpd,ERR_MRK"VPD::getPnAndSnRecordAndKeywords: Error checking if OPFR:VP == 0");
                break;
            }

            bool l_zeroSN;
            l_err = l_ipvpd->cmpSeepromToZero( i_target,
                                               io_record,
                                               io_keywordSN,
                                               l_zeroSN );
            if (l_err)
            {
                TRACFCOMP(g_trac_vpd,ERR_MRK"VPD::getPnAndSnRecordAndKeywords: Error checking if OPFR:VS == 0");
                break;
            }

            // If VP and VS are zero, use VINI instead
            if( l_zeroPN && l_zeroSN )
            {
                TRACFCOMP(g_trac_vpd, "setting cvpd to VINI PN SN");
                io_record    = PVPD::VINI;
                io_keywordPN = PVPD::PN;
                io_keywordSN = PVPD::SN;
            }
#else
            io_record    = PVPD::VINI;
            io_keywordPN = PVPD::PN;
            io_keywordSN = PVPD::SN;
#endif
        }
        else
        {
            TRACFCOMP(g_trac_vpd,ERR_MRK"VPD::getPnAndSnRecordAndKeywords() Unexpected target type, huid=0x%X",TARGETING::get_huid(i_target));
            /*@
             * @errortype
             * @moduleid     VPD_GET_PN_AND_SN
             * @reasoncode   VPD_UNEXPECTED_TARGET_TYPE
             * @userdata1    Target HUID
             * @userdata2    <UNUSED>
             * @devdesc      Unexpected target type
             */
            l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    VPD_GET_PN_AND_SN,
                                    VPD_UNEXPECTED_TARGET_TYPE,
                                    TO_UINT64(TARGETING::get_huid(i_target)),
                                    0x0,
                                    true /*Add HB Software Callout*/ );

        }
    }while( 0 );
    TRACSSCOMP(g_trac_vpd, EXIT_MRK"getPnAndSnRecordAndKeywords()");
    return l_err;
}

// ------------------------------------------------------------------
// ensureCacheIsInSync
// ------------------------------------------------------------------
errlHndl_t ensureCacheIsInSync ( TARGETING::Target * i_target )
{
    errlHndl_t l_err = NULL;

    TRACSSCOMP( g_trac_vpd, ENTER_MRK"ensureCacheIsInSync() " );

    vpdRecord  l_record    = 0;
    vpdKeyword l_keywordPN = 0;
    vpdKeyword l_keywordSN = 0;

    TARGETING::TYPE l_type = i_target->getAttr<TARGETING::ATTR_TYPE>();

    IpVpdFacade* l_ipvpd = &(Singleton<MvpdFacade>::instance());
    // If we have a membuf, use CVPD api
    if(l_type == TARGETING::TYPE_MEMBUF)
    {
        l_ipvpd = &(Singleton<CvpdFacade>::instance());
    }
    else if(l_type == TARGETING::TYPE_NODE)
    {
        l_ipvpd = &(Singleton<PvpdFacade>::instance());
    }
    do
    {
        // Get the correct Part and serial numbers
        l_err = getPnAndSnRecordAndKeywords( i_target,
                                             l_type,
                                             l_record,
                                             l_keywordPN,
                                             l_keywordSN );
        if( l_err )
        {
            TRACFCOMP(g_trac_vpd, "VPD::ensureCacheIsInSync: Error getting part and serial numbers");
            break;
        }


        // Compare the Part Numbers in PNOR/SEEPROM
        bool l_matchPN = false;
        if( ( l_type == TARGETING::TYPE_PROC   ) ||
            ( l_type == TARGETING::TYPE_NODE   ) ||
            ( l_type == TARGETING::TYPE_MEMBUF ) )
        {
            l_err = l_ipvpd->cmpPnorToSeeprom( i_target,
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
            TRACDCOMP(g_trac_vpd,ERR_MRK"VPD::ensureCacheIsInSync: Error checking for PNOR/SEEPROM PN match");
            break;
        }

        // Compare the Serial Numbers in PNOR/SEEPROM
        bool l_matchSN = false;
        if( ( l_type == TARGETING::TYPE_PROC   ) ||
            ( l_type == TARGETING::TYPE_NODE   ) ||
            ( l_type == TARGETING::TYPE_MEMBUF ) )
        {
            l_err = l_ipvpd->cmpPnorToSeeprom( i_target,
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
            TRACDCOMP(g_trac_vpd,ERR_MRK"VPD::ensureCacheIsInSync: Error checking for PNOR/SEEPROM SN match");
            break;
        }

        // If we did not match, we need to load SEEPROM VPD data into PNOR
        if( l_matchPN && l_matchSN )
        {
            TRACFCOMP(g_trac_vpd,"VPD::ensureCacheIsInSync: PNOR_PN/SN == SEEPROM_PN/SN for target %.8X",TARGETING::get_huid(i_target));
        }
        else
        {
            TRACFCOMP(g_trac_vpd,"VPD::ensureCacheIsInSync: PNOR_PN/SN != SEEPROM_PN/SN, Loading PNOR from SEEPROM for target %.8X",TARGETING::get_huid(i_target));

            //Set the targets as changed since the p/n's don't match
            HWAS::markTargetChanged(i_target);

            // Load the PNOR data from the SEEPROM
            if( ( l_type == TARGETING::TYPE_PROC ) ||
                ( l_type == TARGETING::TYPE_NODE ) ||
                ( l_type == TARGETING::TYPE_MEMBUF ) )
            {
                l_err = l_ipvpd->loadPnor( i_target );
            }
            else if( l_type == TARGETING::TYPE_DIMM )
            {
                l_err = SPD::loadPnor( i_target );
            }
            if( l_err )
            {
                TRACDCOMP(g_trac_vpd,"Error loading SEEPROM VPD into PNOR");
                break;
            }
        }

        // Set target attribute switches that say VPD is loaded into PNOR
        TARGETING::ATTR_VPD_SWITCHES_type vpdSwitches =
                    i_target->getAttr<TARGETING::ATTR_VPD_SWITCHES>();
        vpdSwitches.pnorCacheValid = 1;
        vpdSwitches.pnorCacheValidRT = 1;
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
    else if( l_type == TARGETING::TYPE_NODE )
    {
        l_err = Singleton<PvpdFacade>::instance().invalidatePnor( i_target );
    }
    else if( l_type == TARGETING::TYPE_DIMM )
    {
        l_err = SPD::invalidatePnor( i_target );
    }

    // Clear target attribute switch that says VPD is loaded into PNOR
    TARGETING::ATTR_VPD_SWITCHES_type vpdSwitches =
                i_target->getAttr<TARGETING::ATTR_VPD_SWITCHES>();
    vpdSwitches.pnorCacheValid = 0;
    i_target->setAttr<TARGETING::ATTR_VPD_SWITCHES>( vpdSwitches );

    TRACSSCOMP( g_trac_vpd, EXIT_MRK"invalidatePnorCache()" );

    return l_err;
}


// ------------------------------------------------------------------
// setVpdConfigFlagsHW
// ------------------------------------------------------------------
void setVpdConfigFlagsHW ( )
{
    Singleton<MvpdFacade>::instance().setConfigFlagsHW();
    Singleton<CvpdFacade>::instance().setConfigFlagsHW();
    Singleton<PvpdFacade>::instance().setConfigFlagsHW();
    SPD::setConfigFlagsHW();
}


// ------------------------------------------------------------------
// invalidateAllPnorCaches
// ------------------------------------------------------------------
errlHndl_t invalidateAllPnorCaches ( bool i_setHwOnly )
{
    TRACFCOMP(g_trac_vpd,"invalidateAllPnorCaches");
    errlHndl_t l_err = NULL;

    do {
        // Find all the targets with VPD switches
        for (TARGETING::TargetIterator target =
             TARGETING::targetService().begin();
             target != TARGETING::targetService().end();
             ++target)
        {
            TARGETING::ATTR_VPD_SWITCHES_type l_switch;
            if(target->tryGetAttr<TARGETING::ATTR_VPD_SWITCHES>(l_switch))
            {
                if (l_switch.pnorCacheValid)
                {
                    // Invalidate the VPD PNOR for this target
                    // This also clears the VPD ATTR switch
                    l_err = invalidatePnorCache(*target);
                    if (l_err)
                    {
                        break;
                    }
                }
            }
        }
        if (l_err)
        {
            break;
        }

        // Reset the PNOR config flags to HW - MVPD/CVPD/SPD
        // Checks for PNOR caching mode before reset
        if( i_setHwOnly )
        {
            VPD::setVpdConfigFlagsHW();
        }

    } while(0);

    return l_err;
}


}; //end VPD namespace
