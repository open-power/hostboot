/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/vpd.C $                                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2022                        */
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
#include <pldm/requests/pldm_pdr_requests.H>
#include <targeting/targplatutil.H>     // assertGetToplevelTarget
#include <arch/pvrformat.H>
#include <sys/mmio.h>

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

namespace
{
    inline bool usePvpdFacade(TARGETING::Target* i_target)
    {
        // Get the type of the target.
        TARGETING::TYPE l_type = i_target->getAttr<TARGETING::ATTR_TYPE>();
        // Only Node and TPM targets use pvpd facade.
        // TPM shares numerous keywords with the planar vpd so reuse that facade.
        return ((l_type == TARGETING::TYPE_NODE) || (l_type == TARGETING::TYPE_TPM));
    }
}

namespace VPD
{

// ------------------------------------------------------------------
// sendMboxWriteMsg
// ------------------------------------------------------------------
errlHndl_t sendMboxWriteMsg ( size_t i_numBytes,
                              void * i_data,
                              TARGETING::Target * i_target,
                              VPD_MSG_TYPE i_type,
                              VpdWriteMsg_t& io_record )
{
    errlHndl_t l_err = nullptr;
    msg_t* msg = nullptr;

    TRACSSCOMP( g_trac_vpd,
                ENTER_MRK"sendMboxWriteMsg()" );

    do
    {
        // We send VPD update message when we have SP Base Services
        // PLDM messaging (via eeache handling) covers non-SP based services
        if( !INITSERVICE::spBaseServicesEnabled() )
        {
            TRACFCOMP(g_trac_vpd, INFO_MRK "sendMboxWriteMsg: No SP Base Services skipping send");
            break;
        }

        //Create a mailbox message to send to FSP
        msg = msg_allocate();
        msg->type = i_type;
        io_record.targetHUID = get_huid(i_target);    // targetHUID
        // io_record.targetHUID lives in data[0] so copy HUID to the io_record first
        // offset from io_record.offset set by caller
        msg->data[0] = io_record.data[0];             // io_record payload has both targetHUID and offset
        msg->data[1] = i_numBytes;                    // extra payload size

        //Copy the data into the message
        msg->extra_data = malloc( i_numBytes );
        memcpy( msg->extra_data, i_data, i_numBytes );

        TRACFCOMP( g_trac_vpd,
                   INFO_MRK"sendMboxWriteMsg: VPD_WRITE_* type %.8X, HUID=0x%X i_numBytes=0x%X offset=0x%X",
                   i_type,
                   get_huid(i_target),
                   i_numBytes,
                   io_record.offset );

        l_err = MBOX::send( MBOX::FSP_VPD_MSGQ, msg );
        if( l_err )
        {
            TRACFCOMP(g_trac_vpd,
                      ERR_MRK "Failed sending VPD to FSP for %.8X",
                      TARGETING::get_huid(i_target));
            ERRORLOG::ErrlUserDetailsTarget(i_target).addToLog(l_err);

            TARGETING::TYPE l_type = i_target->getAttr<TARGETING::ATTR_TYPE>();
            if ( l_type == TARGETING::TYPE_PROC )
            {
                l_err->collectTrace("VPD",1024);
            }
            else if( l_type == TARGETING::TYPE_DIMM )
            {
                l_err->collectTrace("SPD",1024);
            }

            // just commit the log and move on, nothing else to do
            errlCommit( l_err, VPD_COMP_ID );

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
    size_t l_dataSize = 0;

    TARGETING::TYPE l_type = i_target->getAttr<TARGETING::ATTR_TYPE>();

    TRACSSCOMP(g_trac_vpd, ENTER_MRK"vpd.C::setPartAndSerialNumberAttributes(%.8X)",
              TARGETING::get_huid(i_target));
    do
    {
        IpVpdFacade * l_ipvpd = &(Singleton<MvpdFacade>::instance());
        if(usePvpdFacade(i_target))
        {
            l_ipvpd = &(Singleton<PvpdFacade>::instance());
        }

        // Get the pn/sn/fn/cc record/keyword based on the type
        std::vector<FruPropertyLocation_t> l_recordsKeywords;
        l_recordsKeywords.push_back(FruPropertyLocation_t(TARGETING::ATTR_PART_NUMBER));
        l_recordsKeywords.push_back(FruPropertyLocation_t(TARGETING::ATTR_SERIAL_NUMBER));
        l_recordsKeywords.push_back(FruPropertyLocation_t(TARGETING::ATTR_FRU_NUMBER));
        l_recordsKeywords.push_back(FruPropertyLocation_t(TARGETING::ATTR_FRU_CCIN));
        l_err = getFruRecordsAndKeywords( i_target,
                                          l_type,
                                          l_recordsKeywords );
        if( l_err )
        {
            TRACFCOMP(g_trac_vpd,
                      "Error getting records/keywords for %.8X",
                      TARGETING::get_huid(i_target));
            errlCommit(l_err, VPD_COMP_ID);
            break;
        }

        // Walk through all of the attributes we want to set
        for( const auto& rk : l_recordsKeywords )
        {
            // Get the keyword size
            IpVpdFacade::input_args_t l_args;
            l_args.record = rk.record;
            l_args.keyword = rk.keyword;
            l_err = l_ipvpd->read( i_target,
                                   nullptr,
                                   l_dataSize,
                                   l_args );
            if( l_err )
            {
                TRACFCOMP(g_trac_vpd, ERR_MRK"Error reading VPD size for 0x%X on 0x%08X",
                          rk.name,
                          TARGETING::get_huid(i_target));
                errlCommit(l_err, VPD_COMP_ID);
                // Don't break, continue to next value
                continue;
            }

            // Get the keyword data
            uint8_t l_kwData[l_dataSize] = {};
            l_err = l_ipvpd->read( i_target,
                                   l_kwData,
                                   l_dataSize,
                                   l_args );
            if( l_err )
            {
                TRACFCOMP(g_trac_vpd, ERR_MRK"Error reading VPD data for 0x%X on 0x%08X",
                          rk.name,
                          TARGETING::get_huid(i_target));
                errlCommit(l_err, VPD_COMP_ID);
                // Don't break, continue to next value
                continue;
            }

            // Have to use a switch statement because everything
            //  is templatized (don't want to use private TARGETING
            //  calls)
            switch(rk.name)
            {
                case(TARGETING::ATTR_PART_NUMBER):
                {
                    // Set the part number attribute
                    TARGETING::ATTR_PART_NUMBER_type l_partNumber = {0};
                    size_t l_attrPNSize = sizeof(l_partNumber);
                    if(l_attrPNSize < l_dataSize)
                    {
                        TRACFCOMP(g_trac_vpd,
                                  "Part number data too large for attribute. ATTR size: %d VPD size: %d, attribute will be truncated",
                                  l_attrPNSize,
                                  l_dataSize);
                        l_dataSize = l_attrPNSize; //truncate it
                    }
                    memcpy(l_partNumber, l_kwData, l_dataSize);
                    i_target->trySetAttr
                      <TARGETING::ATTR_PART_NUMBER>(l_partNumber);
                    break;
                }

                case(TARGETING::ATTR_FRU_NUMBER):
                {
                    // Set the fru part number attribute
                    TARGETING::ATTR_FRU_NUMBER_type l_fruNumber = {0};
                    size_t l_attrFNSize = sizeof(l_fruNumber);
                    if(l_attrFNSize < l_dataSize)
                    {
                        TRACFCOMP(g_trac_vpd,
                                  "FRU part number data too large for attribute. ATTR size: %d VPD size: %d, attribute will be truncated",
                                  l_attrFNSize,
                                  l_dataSize);
                        l_dataSize = l_attrFNSize; //truncate it
                    }
                    memcpy(l_fruNumber, l_kwData, l_dataSize);
                    i_target->trySetAttr
                      <TARGETING::ATTR_FRU_NUMBER>(l_fruNumber);
                    break;
                }

                case(TARGETING::ATTR_SERIAL_NUMBER):
                {
                    // Set the serial number attribute
                    TARGETING::ATTR_SERIAL_NUMBER_type l_serialNumber = {0};
                    size_t l_attrSNSize = sizeof(l_serialNumber);
                    if(l_attrSNSize < l_dataSize)
                    {
                        TRACFCOMP(g_trac_vpd,
                                  "Serial number data too large for attribute. ATTR size: %d VPD size: %d, attribute will be truncated",
                                  l_attrSNSize,
                                  l_dataSize);
                        l_dataSize = l_attrSNSize; //truncate it
                    }
                    memcpy(l_serialNumber, l_kwData, l_dataSize);
                    i_target->trySetAttr
                      <TARGETING::ATTR_SERIAL_NUMBER>(l_serialNumber);
                    break;
                }

                case(TARGETING::ATTR_FRU_CCIN):
                {
                    // Set the ccin attribute
                    TARGETING::ATTR_FRU_CCIN_type l_fruCcin = 0;
                    size_t l_attrCcinSize = sizeof(l_fruCcin);
                    if(l_attrCcinSize < l_dataSize)
                    {
                        TRACFCOMP(g_trac_vpd,
                                  "CCIN data too large for attribute. ATTR size: %d VPD size: %d, attribute will be truncated",
                                  l_attrCcinSize,
                                  l_dataSize);
                        l_dataSize = l_attrCcinSize; //truncate it
                    }
                    memcpy(&l_fruCcin, l_kwData, l_dataSize);
                    i_target->trySetAttr
                      <TARGETING::ATTR_FRU_CCIN>(l_fruCcin);
                    break;
                }

                default:
                    // Unexpected  property returned, this should never happen
                    TRACFCOMP(g_trac_vpd,ERR_MRK
                              "Attribute 0x%X not expected",
                              rk.name);
                    assert(false,"Unexpected attribute from fru vpd lookup");
            }
        }
    }while( 0 );

}

// ------------------------------------------------------------------
// getFruRecordsAndKeywords
// ------------------------------------------------------------------
errlHndl_t getFruRecordsAndKeywords( TARGETING::Target * i_target,
                                     TARGETING::TYPE i_type,
                                     std::vector<FruPropertyLocation_t>& io_locs )
{
    TRACSSCOMP(g_trac_vpd, ENTER_MRK"getFruRecordsAndKeywords(%.8X)",
               TARGETING::get_huid(i_target));
    errlHndl_t l_err = nullptr;

    do{
        // Remember any properties we can't find so we can
        // throw an error back
        std::vector<TARGETING::ATTRIBUTE_ID> l_badProperties;

        // Processor Modules
        if( i_type == TARGETING::TYPE_PROC )
        {
            for( auto& rk : io_locs )
            {
                switch(rk.name)
                {
                    case(TARGETING::ATTR_PART_NUMBER):
                        rk.record = MVPD::VRML;
                        rk.keyword = MVPD::PN;
                        break;
                    case(TARGETING::ATTR_SERIAL_NUMBER):
                        rk.record = MVPD::VRML;
                        rk.keyword = MVPD::SN;
                        break;
                    case(TARGETING::ATTR_FRU_CCIN):
                        rk.record = MVPD::VINI;
                        rk.keyword = MVPD::CC;
                        break;
                    case(TARGETING::ATTR_FRU_NUMBER):
                        rk.record = MVPD::VINI;
                        rk.keyword = MVPD::FN;
                        break;
                    default:
                        rk.record = MVPD::MVPD_INVALID_RECORD;
                        rk.keyword = MVPD::INVALID_MVPD_KEYWORD;
                        l_badProperties.push_back(rk.name);
                }
            }
        }
        // SPD-derived FRUs
        else if(  i_type == TARGETING::TYPE_DIMM )
        {
            auto l_attr_use11S = TARGETING::UTIL::assertGetToplevelTarget()
                ->getAttr<TARGETING::ATTR_USE_11S_SPD>();

             auto l_dimm_eeprom_type =
                 i_target->getAttr<TARGETING::ATTR_EEPROM_VPD_PRIMARY_INFO>().eepromContentType;

            // if not an isdimm, use the IBM11S keywords if attr is set
            // if an isdimm, only use JEDEC standard keywords
            bool l_use11S = (l_dimm_eeprom_type != TARGETING::EEPROM_CONTENT_TYPE_ISDIMM) && (l_attr_use11S == 1);

            for( auto& rk : io_locs )
            {
                // SPD does not use record
                rk.record = IPVPD::INVALID_RECORD;

                switch(rk.name)
                {
                    case(TARGETING::ATTR_PART_NUMBER):
                    case(TARGETING::ATTR_FRU_NUMBER): //same as part number
                        if( l_use11S ) {
                            rk.keyword = SPD::IBM_11S_PN;
                        } else {
                            rk.keyword = SPD::MODULE_PART_NUMBER;
                        }
                        break;
                    case(TARGETING::ATTR_SERIAL_NUMBER):
                        if( l_use11S ) {
                            rk.keyword = SPD::IBM_11S_SN;
                        } else {
                            rk.keyword = SPD::MODULE_SERIAL_NUMBER;
                        }
                        break;
                    case(TARGETING::ATTR_FRU_CCIN):
                        if( l_use11S ) {
                            rk.keyword = SPD::IBM_11S_CC;
                        } else {
                            rk.keyword = SPD::INVALID_SPD_KEYWORD;
                            l_badProperties.push_back(rk.name);
                        }
                        break;
                    default:
                        rk.keyword = SPD::INVALID_SPD_KEYWORD;
                        l_badProperties.push_back(rk.name);
                }
            }
        }
        else if (i_type == TARGETING::TYPE_OCMB_CHIP)
        {
            for( auto& rk : io_locs )
            {
                // SPD does not use record
                rk.record = IPVPD::INVALID_RECORD;

                switch(rk.name)
                {
                    case(TARGETING::ATTR_PART_NUMBER):
                    case(TARGETING::ATTR_FRU_NUMBER): //same as part number
                        rk.keyword = SPD::IBM_11S_PN;
                        break;
                    case(TARGETING::ATTR_SERIAL_NUMBER):
                        rk.keyword = SPD::IBM_11S_SN;
                        break;
                    case(TARGETING::ATTR_FRU_CCIN):
                        rk.keyword = SPD::IBM_11S_CC;
                        break;
                    default:
                        rk.keyword = SPD::INVALID_SPD_KEYWORD;
                        l_badProperties.push_back(rk.name);
                }
            }
        }
        // Backplane
        else if(usePvpdFacade(i_target))
        {
            for( auto& rk : io_locs )
            {
                // Everything comes from the VINI
                rk.record = PVPD::VINI;
                switch(rk.name)
                {
                    case(TARGETING::ATTR_PART_NUMBER):
                        rk.keyword = PVPD::PN;
                        break;
                    case(TARGETING::ATTR_SERIAL_NUMBER):
                        rk.keyword = PVPD::SN;
                        break;
                    case(TARGETING::ATTR_FRU_CCIN):
                        rk.keyword = PVPD::CC;
                        break;
                    case(TARGETING::ATTR_FRU_NUMBER):
                        rk.keyword = PVPD::FN;
                        break;
                    default:
                        rk.record = PVPD::PVPD_INVALID_RECORD;
                        rk.keyword = PVPD::PVPD_INVALID_KEYWORD;
                        l_badProperties.push_back(rk.name);
                }
            }
        }
        else
        {
            TRACFCOMP(g_trac_vpd,ERR_MRK
                      "VPD::getFruRecordsAndKeywords() Unexpected target type, huid=0x%X",
                      TARGETING::get_huid(i_target));
            /*@
             * @errortype
             * @moduleid     VPD_GET_FRU_RECS_AND_KWS
             * @reasoncode   VPD_UNEXPECTED_TARGET_TYPE
             * @userdata1    Target HUID
             * @userdata2    <UNUSED>
             * @devdesc      Unexpected target type for FRU property
             * @custdesc     Error in system firmware
             */
            l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_PREDICTIVE,
                                    VPD_GET_FRU_RECS_AND_KWS,
                                    VPD_UNEXPECTED_TARGET_TYPE,
                                    TO_UINT64(TARGETING::get_huid(i_target)),
                                    0x0,
                                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );
            l_err->collectTrace("VPD",1024);

            // Fill in output with invalid data
            for( auto& rk : io_locs )
            {
                rk.record = IPVPD::INVALID_RECORD;
                rk.keyword = IPVPD::INVALID_KEYWORD;
            }

            break;
        }

        if( !l_badProperties.empty() )
        {
            TRACFCOMP(g_trac_vpd,ERR_MRK
                      "VPD::getFruRecordsAndKeywords() Unsupported property requested, huid=0x%X",
                      TARGETING::get_huid(i_target));

            // fill a couple words of data with the bad attributes
            uint32_t l_badProps[2] = { 0 };
            size_t i = 0;
            for( auto bad : l_badProperties )
            {
                TRACFCOMP(g_trac_vpd, ERR_MRK"Bad name = 0x%X",bad);
                if( i<2 )
                {
                    l_badProps[i++] = bad;
                }
            }

            /*@
             * @errortype
             * @moduleid     VPD_GET_FRU_RECS_AND_KWS
             * @reasoncode   VPD_UNSUPPORTED_FRU_PROPERTY
             * @userdata1[00:31]  Target HUID
             * @userdata1[32:63]  Target Type
             * @userdata2    First 2 bad property attributes
             * @devdesc      Unexpected FRU property requested
             * @custdesc     Informational warning in system firmware
             */
            l_err = new ERRORLOG::ErrlEntry(
                             ERRORLOG::ERRL_SEV_INFORMATIONAL,
                             VPD_GET_FRU_RECS_AND_KWS,
                             VPD_UNSUPPORTED_FRU_PROPERTY,
                             TWO_UINT32_TO_UINT64(TARGETING::get_huid(i_target),
                                                  i_type),
                             TWO_UINT32_TO_UINT64(l_badProps[0],
                                                  l_badProps[1]),
                             ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );
            l_err->collectTrace("VPD",1024);
            errlCommit(l_err, VPD_COMP_ID);
            // just committing log here as info because caller can deal
            //  with the invalid record+keyword if the data is truly
            //  required
        }
    } while(0);

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
            || (i_eepromType == TARGETING::EEPROM_CONTENT_TYPE_DDIMM)
            || (i_eepromType == TARGETING::EEPROM_CONTENT_TYPE_PLANAR_OCMB_SPD))
    {
        l_err = SPD::cmpEecacheToEeprom(i_target,
                                        i_eepromType,
                                        i_keyword,
                                        o_match);
    }
    else
    {
        assert(false, "Error, invalid EEPROM type 0x%X for target HUID 0x%X passed to cmpEecacheToEeprom",
               i_eepromType, get_huid(i_target));
    }

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
 * @param[in]  i_property   Record/Keyword to compare
 *
 * @param[out] o_match      Result of compare
 *
 * @return errlHndl_t       nullptr if successful, otherwise a pointer to the
 *                          error log.
 */
errlHndl_t cmpEecacheToAttributes(TARGETING::Target *            i_target,
                                  TARGETING::EEPROM_CONTENT_TYPE i_eepromType,
                                  FruPropertyLocation_t&         i_property,
                                  bool&                          o_match)
{
    errlHndl_t l_err = nullptr;

    do {
        size_t l_size = 0;
        l_err = deviceRead(i_target, nullptr, l_size,
                           DEVICE_VPD_ADDRESS(i_property.record,
                                              i_property.keyword));
        if(l_err)
        {
            break;
        }
        uint8_t l_vpd[l_size];
        l_err = deviceRead(i_target, l_vpd, l_size,
                           DEVICE_VPD_ADDRESS(i_property.record,
                                              i_property.keyword));
        if(l_err)
        {
            break;
        }

        if( i_property.name == TARGETING::ATTR_SERIAL_NUMBER )
        {
            auto l_attr = i_target->getAttrAsStdArr<TARGETING::ATTR_SERIAL_NUMBER>();
            if( memcmp( l_vpd, &l_attr,
                        std::min(sizeof(l_attr),sizeof(l_vpd)) ) )
            {
                TRACFCOMP( g_trac_vpd, "VPD::cmpEecacheToAttributes found SN mismatch for HUID %.8X 0x%X:0x%X", TARGETING::get_huid(i_target), i_property.record, i_property.keyword );
                TRACFBIN( g_trac_vpd, "ATTRIBUTE", l_attr.data(), sizeof(l_attr) );
                TRACFBIN( g_trac_vpd, "CACHE", l_vpd, sizeof(l_vpd) );
            }
            else
            {
                o_match = true;
            }
        }
        else if( i_property.name == TARGETING::ATTR_PART_NUMBER )
        {
            auto l_attr = i_target->getAttrAsStdArr<TARGETING::ATTR_PART_NUMBER>();
            if( memcmp( l_vpd, &l_attr,
                        std::min(sizeof(l_attr),sizeof(l_vpd)) ) )
            {
                TRACFCOMP( g_trac_vpd, "VPD::cmpEecacheToAttributes found PN mismatch for HUID %.8X 0x%X:0x%X", TARGETING::get_huid(i_target), i_property.record, i_property.keyword );
                TRACFBIN( g_trac_vpd, "ATTRIBUTE", l_attr.data(), sizeof(l_attr) );
                TRACFBIN( g_trac_vpd, "CACHE", l_vpd, sizeof(l_vpd) );
            }
            else
            {
                o_match = true;
            }
        }
        else
        {
            TRACFCOMP( g_trac_vpd, "VPD::cmpEecacheToAttributes> Unrecognized keyword/attribute 0x%X",
                       i_property.name );
            /*@
             * @errortype
             * @moduleid     VPD_CMP_EECACHE_TO_ATTRIBUTES
             * @reasoncode   VPD_UNSUPPORTED_FRU_PROPERTY
             * @userdata1[00:31]  Target HUID
             * @userdata1[32:63]  Target Type
             * @userdata2[00:31]  Bad property
             * @userdata2[32:63]  unused
             * @devdesc      Unexpected FRU property requested
             * @custdesc     Firmware error
             */
            l_err = new ERRORLOG::ErrlEntry(
                                            ERRORLOG::ERRL_SEV_PREDICTIVE,
                                            VPD_CMP_EECACHE_TO_ATTRIBUTES,
                                            VPD_UNSUPPORTED_FRU_PROPERTY,
                                            TWO_UINT32_TO_UINT64(
                                                TARGETING::get_huid(i_target),
                                                i_target->getAttr<TARGETING::ATTR_TYPE>()),
                                            TWO_UINT32_TO_UINT64(i_property.name,
                                                0),
                                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );
            l_err->collectTrace("VPD",1024);
            break;
        }
        // Could optimize above with templates but for just 2 attributes the ROI is low

    } while(0);

    return l_err;
}

// ------------------------------------------------------------------
// ensureEepromCacheIsInSync
// ------------------------------------------------------------------
errlHndl_t ensureEepromCacheIsInSync(TARGETING::Target       * i_target,
                              TARGETING::EEPROM_CONTENT_TYPE   i_eepromType,
                              bool                             i_useAttributes,
                              bool                           & o_isInSync,
                              bool                           & o_isNewPart)
{
    errlHndl_t l_err = nullptr;

    TRACFCOMP(g_trac_vpd, ENTER_MRK"ensureEepromCacheIsInSync(%.8X) ",
              TARGETING::get_huid(i_target));

    do
    {
        // Get the pn/sn record/keyword based on the type
        std::vector<FruPropertyLocation_t> l_recordsKeywords;
        l_recordsKeywords.push_back(FruPropertyLocation_t(TARGETING::ATTR_PART_NUMBER));
        l_recordsKeywords.push_back(FruPropertyLocation_t(TARGETING::ATTR_SERIAL_NUMBER));
        l_err = getFruRecordsAndKeywords( i_target,
                                          i_target->
                                              getAttr<TARGETING::ATTR_TYPE>(),
                                          l_recordsKeywords );

        if( l_err )
        {
            TRACFCOMP(g_trac_vpd,
                      "VPD::ensureEepromCacheIsInSync: "
                      "Error getting part and serial numbers");
            break;
        }

        // Loop through all of our records/keywords to compare
        //  CACHE vs HARDWARE/ATTRIBUTES
        o_isInSync = true;
        for( auto& rk : l_recordsKeywords )
        {
            bool l_match = false;


            // Use attributes as the basis
            if( COMPARE_TO_ATTRIBUTES == i_useAttributes )
            {
                l_err = cmpEecacheToAttributes(i_target,
                                               i_eepromType,
                                               rk,
                                               l_match);
                if (l_err)
                {
                    TRACFCOMP(g_trac_vpd,ERR_MRK
                              "VPD::ensureEepromCacheIsInSync: "
                              "Error checking for CACHE/ATTRIBUTE match for rec=%d,kw=%d",
                              rk.record, rk.keyword);
                }
            }
            // Compare cache vs eeprom
            else
            {
                l_err = cmpEecacheToEeprom(i_target,
                                           i_eepromType,
                                           rk.keyword,
                                           rk.record,
                                           l_match);

                if (l_err)
                {
                    TRACFCOMP(g_trac_vpd,ERR_MRK
                              "VPD::ensureEepromCacheIsInSync: "
                              "Error checking for CACHE/HARDWARE match for rec=%d,kw=%d",
                              rk.record, rk.keyword);
                }
            }

            // update o_isInSync before breaking out on error
            o_isInSync = o_isInSync && l_match;
            if( l_err ) { break; }

        }
        if( l_err ) { break; }

        // Check the serial number and part number of the system if the previous
        // record/key pair matched. Note that this time the record/key pairs are
        // OSYS/SS and OSYS/MM for serial number and part number, respectively
        // @TODO RTC 210350 Handle this case.
//        if (l_type == TARGETING::TYPE_NODE &&
//           (l_matchSN && l_matchPN))
//        {
//
//        }

        TRACFCOMP(g_trac_vpd, "VPD::ensureEepromCacheIsInSync o_isInSync=%d HUID=0x%X",
                  o_isInSync, get_huid(i_target));

        if (i_target->getAttr<TARGETING::ATTR_EECACHE_VPD_STATE>() == TARGETING::EECACHE_VPD_STATE_VPD_NEEDS_REFRESH)
        {
            o_isInSync = false;
            o_isNewPart = false;
            TRACFCOMP(g_trac_vpd, "VPD::ensureEepromCacheIsInSync EECACHE_VPD_STATE o_isInSync=%d HUID=0x%X", o_isInSync, get_huid(i_target));
            // EECACHE_VPD_STATE reset to VPD_GOOD since we flagged for the refresh via o_isInSync
            i_target->setAttr<TARGETING::ATTR_EECACHE_VPD_STATE>(TARGETING::EECACHE_VPD_STATE_VPD_GOOD);
        }

        // If we did not match, we need to load HARDWARE VPD data into CACHE
        if (o_isInSync)
        {
            TRACFCOMP(g_trac_vpd,
                      "VPD::ensureEepromCacheIsInSync: "
                      "CACHE_PN/SN == HARDWARE_PN/SN and VPD_GOOD for target %.8X",
                      TARGETING::get_huid(i_target));
        }
        else
        {
            TRACFCOMP(g_trac_vpd,
                      "VPD::ensureEepromCacheIsInSync: CACHE_PN/SN != HARDWARE_PN/SN -OR- VPD_NEEDS_REFRESH, CACHE must be loaded from HARDWARE for target %.8X",
                      TARGETING::get_huid(i_target));
            CONSOLE::flush();
#ifndef CONFIG_SUPPORT_EEPROM_CACHING
            //  o_isNewPart comes in as true and is set to false above -ONLY- when VPD_NEEDS_REFRESH
            //  so if we have a PN/SN update needed from HARDWARE we want to markTargetChanged
            //  but -ONLY- skip markTargetChanged if this is a VPD_NEEDS_REFRESH flow
            if (o_isNewPart)
            {
                //Set the targets as changed since the p/n's don't match
                HWAS::markTargetChanged(i_target);
            }
#else
            //No need to mark target changed here, it will be handled by eecache code
#endif
        }

    } while(0);

    TRACFCOMP(g_trac_vpd, EXIT_MRK"ensureEepromCacheIsInSync(o_isInSync=%d,o_isNewPart=%d)",
              o_isInSync,o_isNewPart);

    return l_err;
}


/**
 * @brief Get a list of all overridden sections
 */
void getListOfOverrideSections( OverrideRsvMemMap_t& o_overrides )
{

}

// ------------------------------------------------------------------
// updateRecordEccData
// ------------------------------------------------------------------
errlHndl_t updateRecordEccData (
               const TARGETING::TargetHandle_t  i_target,
               const uint32_t i_record,   const uint32_t i_keyword,
               const uint32_t i_eepromSource )
{
    IpVpdFacade::input_args_t l_args;
    l_args.record = static_cast<VPD::vpdRecord>(i_record);
    l_args.keyword = static_cast<VPD::vpdKeyword>(i_keyword);
    l_args.eepromSource = static_cast<EEPROM::EEPROM_SOURCE>(i_eepromSource);

    return Singleton<MvpdFacade>::instance().updateRecordEccData( i_target, l_args );
}

// ------------------------------------------------------------------
// validateAllRecordEccData
// ------------------------------------------------------------------
errlHndl_t validateAllRecordEccData (
               const TARGETING::TargetHandle_t  i_target )
{
    return Singleton<MvpdFacade>::instance().validateAllRecordEccData( i_target );
}

}; //end VPD namespace
