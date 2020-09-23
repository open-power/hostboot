/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/vpd.C $                                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2020                        */
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
#include <vpd/pvpdenums.H>
#include <initservice/initserviceif.H>
#include <devicefw/driverif.H>
#include <hwas/hwasPlat.H>
#include <sys/mm.h>
#include "vpd.H"
#include "mvpd.H"
#include "pvpd.H"
#include "spd.H"
#include "ipvpd.H"
#include <map>
#include <console/consoleif.H>
#include <initservice/istepdispatcherif.H>
#include <ipmi/ipmifruinv.H>
#include <pldm/requests/pldm_pdr_requests.H>


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
    errlHndl_t err = nullptr;
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
    errlHndl_t err = nullptr;
    int64_t vpdLocation = 0;
    uint64_t addr = 0x0;
    const char * readAddr = nullptr;

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
    errlHndl_t err = nullptr;
    int64_t vpdLocation = 0;
    uint64_t addr = 0x0;
    const char * writeAddr = nullptr;

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
    errlHndl_t l_err = nullptr;
    msg_t* msg = nullptr;

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
            l_err = nullptr;

            free( msg->extra_data );
            msg->extra_data = nullptr;
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
    errlHndl_t l_err = nullptr;
    vpdKeyword l_serialNumberKeyword = 0;
    size_t l_dataSize = 0;

    TARGETING::TYPE l_type = i_target->getAttr<TARGETING::ATTR_TYPE>();

    TRACSSCOMP(g_trac_vpd, ENTER_MRK"vpd.C::setPartAndSerialNumberAttributes");
    do
    {
            IpVpdFacade * l_ipvpd = &(Singleton<MvpdFacade>::instance());
            if(l_type == TARGETING::TYPE_NODE)
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
                l_err = nullptr;
                break;
            }

            // Get the size of the part number
            l_err = l_ipvpd->read( i_target,
                                   nullptr,
                                   l_dataSize,
                                   l_args );

            if( l_err )
            {
                TRACFCOMP(g_trac_vpd, " vpd.C::setPartAndSerialNumbers::read part number size");
                errlCommit(l_err, VPD_COMP_ID);
                l_err = nullptr;
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
                l_err = nullptr;
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
                          nullptr,
                          l_dataSize,
                          l_args );

            if( l_err )
            {
                TRACFCOMP(g_trac_vpd, "vpd.C::setPartAndSerialNumbers::read serial number size");
                errlCommit( l_err, VPD_COMP_ID );
                l_err = nullptr;
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
                l_err = nullptr;
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
// setPartAndSerialNumberAttributes
// ------------------------------------------------------------------
errlHndl_t updateSerialNumberFromBMC( TARGETING::Target * i_nodetarget )
{
    errlHndl_t l_errl = nullptr;
#ifdef CONFIG_UPDATE_SN_FROM_BMC
    size_t     l_vpdSize = 0;

    //Get Product Serial Number from Backplane
    char* l_sn_prod = nullptr;
    l_sn_prod = IPMIFRUINV::getProductSN(0);
    if (l_sn_prod != nullptr)
    {
        TRACFCOMP(g_trac_vpd, "Got system serial number from BMC.");
        TRACFCOMP(g_trac_vpd, "SN from BMC is: %s", l_sn_prod);

        l_errl = deviceRead(i_nodetarget, nullptr, l_vpdSize,
                DEVICE_PVPD_ADDRESS( PVPD::OSYS, PVPD::SS ));

        if(l_errl == nullptr)
        {
            uint8_t l_vpddata[l_vpdSize];

            l_errl = deviceRead(i_nodetarget, l_vpddata, l_vpdSize,
                DEVICE_PVPD_ADDRESS( PVPD::OSYS, PVPD::SS ));

            if(l_errl == nullptr)
            {
                TRACFCOMP(g_trac_vpd, "SN in PVPD::OSYS:SS: %s, size: %d", l_vpddata, l_vpdSize);

                if (strncmp(l_sn_prod, l_vpddata, l_vpdSize) != 0)
                {
                    l_errl = deviceWrite(i_nodetarget, l_sn_prod, l_vpdSize,
                                DEVICE_PVPD_ADDRESS( PVPD::OSYS, PVPD::SS ));
                    CONSOLE::displayf(nullptr, "updated SN from BMC into PVPD.");
                    CONSOLE::flush();
                    CONSOLE::displayf(nullptr, "Need a reboot.");
                    CONSOLE::flush();
#ifdef CONFIG_PLDM
                    INITSERVICE::stopIpl();
                    l_errl = PLDM::sendGracefulRebootRequest();
                    if(l_errl)
                    {
                        TRACFCOMP(g_trac_vpd, "updateSerialNumberFromBMC: Could not send reboot PLDM request");
                    }
#elif defined (CONFIG_BMC_IPMI)
                    INITSERVICE::requestReboot();
#endif
                }
            }
        }

         //getProductSN requires the caller to delete the char array
         delete[] l_sn_prod;
         l_sn_prod = nullptr;

        TRACFCOMP(g_trac_vpd, "End updateSerialNumberFromBMC.");
    }
#endif
    return l_errl;
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
    errlHndl_t l_err = nullptr;
    do{

        if( i_type == TARGETING::TYPE_PROC )
        {
            io_record    = MVPD::VRML;
            io_keywordPN = MVPD::PN;
            io_keywordSN = MVPD::SN;
        }
        else if((  i_type == TARGETING::TYPE_DIMM )
               || (i_type == TARGETING::TYPE_OCMB_CHIP))
        {
            // SPD does not have singleton instance
            // SPD does not use record
            io_keywordPN = SPD::MODULE_PART_NUMBER;
            io_keywordSN = SPD::MODULE_SERIAL_NUMBER;
        }
        else if( i_type == TARGETING::TYPE_NODE )
        {
            io_record    = PVPD::VINI;
            io_keywordPN = PVPD::PN;
            io_keywordSN = PVPD::SN;
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

/**
 * @brief This function compares the specified record/keyword in
 *        CACHE/HARDWARE by calling the correct function based on the
 *        target's eeprom content type and returns the result.  A mismatch
 *        will not return an error.
 *
 * @param[in]  i_target     Target device
 *
 * @param[in]  i_eepromType Eeprom content type for the target.
 *
 * @param[in]  i_keyword    Keyword to compare
 *
 * @param[in]  i_record     Record to compare
 *
 * @param[out] o_match      Result of compare
 *
 * @return errlHndl_t       nullptr if successful, otherwise a pointer to the
 *                          error log.
 */
errlHndl_t cmpEecacheToEeprom(TARGETING::Target *            i_target,
                              TARGETING::EEPROM_CONTENT_TYPE i_eepromType,
                              vpdKeyword                     i_keyword,
                              vpdRecord                      i_record,
                              bool&                          o_match)
{
    errlHndl_t l_err = nullptr;

    if (  (i_eepromType == TARGETING::EEPROM_CONTENT_TYPE_IBM_MVPD)
       || (i_eepromType == TARGETING::EEPROM_CONTENT_TYPE_IBM_FRUVPD))
    {
        auto l_type = i_target->getAttr<TARGETING::ATTR_TYPE>();
        IpVpdFacade* l_ipvpd = &(Singleton<MvpdFacade>::instance());

        // If we have a NODE, use pvpd api
        if(l_type == TARGETING::TYPE_NODE)
        {
            l_ipvpd = &(Singleton<PvpdFacade>::instance());
        }

        l_err = l_ipvpd->cmpEecacheToEeprom(i_target,
                                            i_record,
                                            i_keyword,
                                            o_match);
    }
    else if (  (i_eepromType == TARGETING::EEPROM_CONTENT_TYPE_ISDIMM)
            || (i_eepromType == TARGETING::EEPROM_CONTENT_TYPE_DDIMM))
    {
        l_err = SPD::cmpEecacheToEeprom(i_target,
                                        i_eepromType,
                                        i_keyword,
                                        o_match);
    }
    else
    {
        assert(false, "Error, invalid EEPROM type 0x%x for target HUID 0x%X passed to cmpEecacheToEeprom",
               i_eepromType, get_huid(i_target));
    }

    return l_err;
}


// ------------------------------------------------------------------
// ensureEepromCacheIsInSync
// ------------------------------------------------------------------
errlHndl_t ensureEepromCacheIsInSync(TARGETING::Target           * i_target,
                                  TARGETING::EEPROM_CONTENT_TYPE   i_eepromType,
                                  bool                           & o_isInSync)
{
    errlHndl_t l_err = nullptr;

    TRACDCOMP(g_trac_vpd, ENTER_MRK"ensureEepromCacheIsInSync() ");

    vpdRecord  l_record    = 0;
    vpdKeyword l_keywordPN = 0;
    vpdKeyword l_keywordSN = 0;

    do
    {
        // Get the correct Part and serial numbers
        l_err = getPnAndSnRecordAndKeywords(i_target,
                                            i_target->
                                                getAttr<TARGETING::ATTR_TYPE>(),
                                            l_record,
                                            l_keywordPN,
                                            l_keywordSN);
        if( l_err )
        {
            TRACFCOMP(g_trac_vpd,
                      "VPD::ensureEepromCacheIsInSync: "
                      "Error getting part and serial numbers");
            break;
        }

        // Compare the Part Numbers in CACHE/HARDWARE
        bool l_matchPN = false;
        l_err = cmpEecacheToEeprom(i_target,
                                   i_eepromType,
                                   l_keywordPN,
                                   l_record,
                                   l_matchPN);

        if (l_err)
        {
            TRACFCOMP(g_trac_vpd,ERR_MRK
                      "VPD::ensureEepromCacheIsInSync: "
                      "Error checking for CACHE/HARDWARE PN match");
            break;
        }

        // Compare the Serial Numbers in CACHE/HARDWARE
        bool l_matchSN = false;
        l_err = cmpEecacheToEeprom(i_target,
                                   i_eepromType,
                                   l_keywordSN,
                                   l_record,
                                   l_matchSN);

        if (l_err)
        {
            TRACFCOMP(g_trac_vpd, ERR_MRK
                     "VPD::ensureEepromCacheIsInSync: Error checking for "
                     "CACHE/HARDWARE SN match");
            break;
        }

        // Check the serial number and part number of the system if the previous
        // record/key pair matched. Note that this time the record/key pairs are
        // OSYS/SS and OSYS/MM for serial number and part number, respectively
        // @TODO RTC 210350 Handle this case.
//        if (l_type == TARGETING::TYPE_NODE &&
//           (l_matchSN && l_matchPN))
//        {
//
//        }

        o_isInSync = (l_matchPN && l_matchSN);

        // If we did not match, we need to load HARDWARE VPD data into CACHE
        if (o_isInSync)
        {
            TRACFCOMP(g_trac_vpd,
                      "VPD::ensureEepromCacheIsInSync: "
                      "CACHE_PN/SN == HARDWARE_PN/SN for target %.8X",
                      TARGETING::get_huid(i_target));
        }
        else
        {
            TRACFCOMP(g_trac_vpd,
                      "VPD::ensureEepromCacheIsInSync: CACHE_PN/SN != HARDWARE_PN/SN,CACHE must be loaded from HARDWARE for target %.8X",
                      TARGETING::get_huid(i_target));
            CONSOLE::flush();
#ifndef CONFIG_SUPPORT_EEPROM_CACHING
            //Set the targets as changed since the p/n's don't match
            HWAS::markTargetChanged(i_target);
#else
            //No need to mark target changed here, it will be handled by eecache code
#endif
        }

    } while(0);

    TRACDCOMP(g_trac_vpd, EXIT_MRK"ensureEepromCacheIsInSync()");

    return l_err;
}

// ------------------------------------------------------------------
// ensureCacheIsInSync
// ------------------------------------------------------------------
errlHndl_t ensureCacheIsInSync ( TARGETING::Target * i_target )
{
    errlHndl_t l_err = nullptr;

    TRACSSCOMP( g_trac_vpd, ENTER_MRK"ensureCacheIsInSync() " );

    vpdRecord  l_record    = 0;
    vpdKeyword l_keywordPN = 0;
    vpdKeyword l_keywordSN = 0;

    TARGETING::TYPE l_type = i_target->getAttr<TARGETING::ATTR_TYPE>();

    IpVpdFacade* l_ipvpd = &(Singleton<MvpdFacade>::instance());
    if(l_type == TARGETING::TYPE_NODE)
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
            ( l_type == TARGETING::TYPE_MEMBUF ))
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

        //Check the serial number and part number of the system if the previous
        //record/key pair matched. Note that this time the record/key pairs
        //are VSYS/SE and VSYS/TM for serial number and part number,respectively
        if(l_type == TARGETING::TYPE_NODE &&
           (l_matchSN && l_matchPN))
        {

            bool l_zeroPN = false;
            bool l_zeroSN = false;
            // current pair is a guess
            l_err = l_ipvpd->cmpSeepromToZero(i_target,
                                              PVPD::VSYS,
                                              PVPD::TM,
                                              l_zeroPN);
            if(l_err)
            {
                TRACDCOMP(g_trac_vpd,ERR_MRK"VPD::ensureCacheIsInSync: "
                "cmpSeepromToZero returned an error. Assuming this error is "
                "related to OSYS/MM not being present in SEEPROM. Skipping "
                "this error. HUID: 0x%.8X",
                TARGETING::get_huid(i_target));
                delete l_err;
                l_err = nullptr;
                l_zeroPN = true;

            }

            // current pair is a guess
            l_err = l_ipvpd->cmpSeepromToZero(i_target,
                                              PVPD::VSYS,
                                              PVPD::SE,
                                              l_zeroSN);
            if(l_err)
            {
                TRACDCOMP(g_trac_vpd,ERR_MRK"VPD::ensureCacheIsInSync: "
                "cmpSeepromToZero returned an error. Assuming this error is "
                "related to OSYS/SS not being present in SEEPROM. Skipping "
                "this error. HUID: 0x%.8X",
                TARGETING::get_huid(i_target));
                delete l_err;
                l_err = nullptr;
                l_zeroSN = true;
            }

            //Only compare the SN/PN between SEEPROM and PNOR if they are
            //nonzero.
            if(!l_zeroPN)
            {
                // current pair is a guess
                l_err = l_ipvpd->cmpPnorToSeeprom(i_target,
                                                  PVPD::VSYS,
                                                  PVPD::TM,
                                                  l_matchPN);
                if(l_err)
                {
                    TRACFCOMP(g_trac_vpd,ERR_MRK"VPD::ensureCacheIsInSync: Error"
                    " checking for PNOR/SEEPROM PN match for NODE target 0x%.8X",
                    TARGETING::get_huid(i_target));
                    break;
                }
            }

            if(!l_zeroSN)
            {
                // current pair is a guess
                l_err = l_ipvpd->cmpPnorToSeeprom(i_target,
                                                  PVPD::VSYS,
                                                  PVPD::SE,
                                                  l_matchSN);
                if(l_err)
                {
                    TRACFCOMP(g_trac_vpd,ERR_MRK"VPD::ensureCacheIsInSync: Error"
                    " checking for PNOR/SEEPROM SN match for NODE target 0x%.8X",
                    TARGETING::get_huid(i_target));
                    break;
                }
            }
        }

        // If we did not match, we need to load SEEPROM VPD data into PNOR
        if( l_matchPN && l_matchSN )
        {
            TRACFCOMP(g_trac_vpd,"VPD::ensureCacheIsInSync: PNOR_PN/SN == SEEPROM_PN/SN for target %.8X",TARGETING::get_huid(i_target));
        }
        else
        {
            TRACFCOMP(g_trac_vpd,"VPD::ensureCacheIsInSync: PNOR_PN/SN != SEEPROM_PN/SN, Loading PNOR from SEEPROM for target %.8X",TARGETING::get_huid(i_target));
            const char* l_pathstring =
              i_target->getAttr<TARGETING::ATTR_PHYS_PATH>().toString();
            CONSOLE::displayf(nullptr,"Detected new part : %.8X (%s)",
                              TARGETING::get_huid(i_target),
                              l_pathstring);
            free((void*)(l_pathstring));
            l_pathstring = nullptr;
            CONSOLE::flush();

            //Set the targets as changed since the p/n's don't match
            HWAS::markTargetChanged(i_target);

            // Load the PNOR data from the SEEPROM
            if( ( l_type == TARGETING::TYPE_PROC ) ||
                ( l_type == TARGETING::TYPE_NODE ) ||
                ( l_type == TARGETING::TYPE_MEMBUF ))
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
    errlHndl_t l_err = nullptr;

    TRACSSCOMP( g_trac_vpd, ENTER_MRK"invalidatePnorCache() " );

    TARGETING::TYPE l_type = i_target->getAttr<TARGETING::ATTR_TYPE>();

    if( l_type == TARGETING::TYPE_PROC )
    {
        l_err = Singleton<MvpdFacade>::instance().invalidatePnor( i_target );
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
    Singleton<PvpdFacade>::instance().setConfigFlagsHW();
    SPD::setConfigFlagsHW();
}


// ------------------------------------------------------------------
// invalidateAllPnorCaches
// ------------------------------------------------------------------
errlHndl_t invalidateAllPnorCaches ( bool i_setHwOnly )
{
    TRACFCOMP(g_trac_vpd,"invalidateAllPnorCaches");
    errlHndl_t l_err = nullptr;

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

        // Reset the PNOR config flags to HW - MVPD/SPD
        // Checks for PNOR caching mode before reset
        if( i_setHwOnly )
        {
            VPD::setVpdConfigFlagsHW();
        }

    } while(0);

    return l_err;
}

typedef std::pair<TARGETING::Target *, bool> targetValidPair_t;
typedef std::map<TARGETING::ATTR_VPD_REC_NUM_type,
            targetValidPair_t> numRecValidMap_t;

// For each target in list, either add a map entry for this VPD_REC_NUM
// or OR in the cache valid bit if VPD_REC_NUM is already in the map.
void addListToMap(numRecValidMap_t                  & i_recNumMap,
                  const TARGETING::TargetHandleList & i_targetList)
{
    for (TARGETING::TargetHandleList::const_iterator
                 targItr = i_targetList.begin();
                 targItr != i_targetList.end();
                 ++targItr)
    {
        TARGETING::Target * l_pTarg = *targItr;
        TARGETING::ATTR_VPD_REC_NUM_type l_recNum =
            l_pTarg->getAttr<TARGETING::ATTR_VPD_REC_NUM>();
        TARGETING::ATTR_VPD_SWITCHES_type l_switches =
            l_pTarg->getAttr<TARGETING::ATTR_VPD_SWITCHES>();

        numRecValidMap_t::iterator itr = i_recNumMap.find(l_recNum);
        if( itr != i_recNumMap.end() )
        {
            TRACDCOMP( g_trac_vpd, "addListToMap() "
                       "OR in %d for VPD_REC_NUM %d HUID %.8X",
                       l_switches.pnorCacheValid,
                       l_recNum,
                       TARGETING::get_huid(l_pTarg));

            itr->second.second |= l_switches.pnorCacheValid;
        }
        else
        {
            TRACDCOMP( g_trac_vpd, "addListToMap() "
                       "Set %d for VPD_REC_NUM %d HUID %.8X",
                       l_switches.pnorCacheValid,
                       l_recNum,
                       TARGETING::get_huid(l_pTarg));

            i_recNumMap[l_recNum] =
                targetValidPair_t(l_pTarg,l_switches.pnorCacheValid);
        }
    }
}

// --------------------------------------------------------
// This function validates targets sharing the PNOR::CENTAUR_VPD cache.
// Invalidate sections where all of the targets sharing a VPD_REC_NUM
// are invalid. Keep the section if any target is valid.
//---------------------------------------------------------
errlHndl_t validateSharedPnorCache()
{
    errlHndl_t errl = nullptr;
    std::map<TARGETING::ATTR_VPD_REC_NUM_type,targetValidPair_t> l_recNumMap;

    TRACDCOMP( g_trac_vpd, ENTER_MRK"validateSharedPnorCache()");

    do
    {
#if defined(CONFIG_PVPD_READ_FROM_HW) && defined(CONFIG_PVPD_READ_FROM_PNOR)
        // Add cache status for the node
        TARGETING::TargetHandleList l_nodeList;
        getEncResources(l_nodeList,
                        TARGETING::TYPE_NODE,
                        TARGETING::UTIL_FILTER_ALL);
        addListToMap( l_recNumMap, l_nodeList);
#endif

        // If this system has mem bufs, then gather all mem bufs.
        // If there are no mem bufs, then gather the MCSs for direct memory.
        TARGETING::TargetHandleList l_memBufList;
        getChipResources(l_memBufList,
                         TARGETING::TYPE_MEMBUF,
                         TARGETING::UTIL_FILTER_ALL);
        if (l_memBufList.size()) // system has mem bufs
        {
            addListToMap( l_recNumMap, l_memBufList);
        }
        else // Add cache status for all MCSs for direct memory
        {
            TARGETING::TargetHandleList l_mcsList;
            getChipletResources(l_mcsList,
                                TARGETING::TYPE_MCS,
                                TARGETING::UTIL_FILTER_ALL);
            addListToMap( l_recNumMap, l_mcsList);
        }

        // check for any section that is invalid for all that share it
        for (numRecValidMap_t::iterator itr = l_recNumMap.begin();
                 itr != l_recNumMap.end(); ++itr)
        {
            // The second.second is the accumulation of all pnorCacheValid
            // bits. If true, then at least one target is using this
            // VPD_REC_NUM section. Keep it.
            if (itr->second.second)
            {
                TRACDCOMP( g_trac_vpd, "validateSharedPnorCache() "
                           "valid is %d for VPD_REC_NUM %d HUID %.8X "
                           "keep this section",
                           itr->second.second,
                           itr->first,
                           TARGETING::get_huid(itr->second.first));
            }
            // if false, then all that share this section, none are valid.
            // Invalidate this section.
            else
            {
                TRACFCOMP( g_trac_vpd, "validateSharedPnorCache() "
                           "valid is %d for VPD_REC_NUM %d HUID %.8X "
                           "invalidate this section",
                           itr->second.second,
                           itr->first,
                           TARGETING::get_huid(itr->second.first));

                // invalidate cache section for this VPD_REC_NUM
                errl = VPD::invalidatePnorCache(itr->second.first);
                if (errl)
                {
                    // Just commit the log and move on. No need to terminate IPL
                    errlCommit( errl, VPD_COMP_ID );
                }
            }
        }
    } while (0);

    return errl;
}

/**
 * @brief Get a list of all overridden sections
 */
void getListOfOverrideSections( OverrideRsvMemMap_t& o_overrides )
{

}

}; //end VPD namespace
