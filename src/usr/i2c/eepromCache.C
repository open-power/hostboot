/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/eepromCache.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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

#include <builtins.h>
#include <stdarg.h>
#include <sys/mm.h>
#include <limits.h>
#include <devicefw/driverif.H>
#include <errl/errlmanager.H>
#include <fsi/fsiif.H>
#include "i2c.H"
#include "eepromCache.H"
#include <i2c/i2cif.H>
#include <i2c/eepromif.H>
#include <i2c/eepromddreasoncodes.H>
#include <initservice/initserviceif.H>
#include <initservice/initsvcreasoncodes.H>
#include <pnor/pnorif.H>
#include <vpd/vpd_if.H>
#include <errl/errludtarget.H>
#include <config.h>
#ifdef CONFIG_CONSOLE
#include <console/consoleif.H>
#endif

extern trace_desc_t* g_trac_eeprom;

//#define TRACSSCOMP(args...)  TRACFCOMP(args)
#define TRACSSCOMP(args...)

namespace EEPROM
{

// Global variable that will keep track of the virtual address which
// points to the start of the EECACHE section, and the size of this section.
// It is handy to keep these around so we do not need to look them up in the
// pnor code everytime.
uint64_t g_eecachePnorVaddr = 0;
uint64_t g_eecachePnorSize  = 0;

// Global map which is used as a way to quickly look up the virtual address
// of a given eeprom's cached data in EECACHE section
// Key   = eepromRecordHeader with unique info filled out
// Value = virtual address pointing to the cached eeprom data in pnor
std::map<eepromRecordHeader, uint64_t> g_cachedEeproms;

// Any time we access either any of the global variables defined above we want
// to wrap the call in this mutex to avoid multi-threading issues
mutex_t g_eecacheMutex = MUTEX_INITIALIZER;

uint64_t lookupEepromAddr(const eepromRecordHeader& i_eepromRecordHeader)
{
    uint64_t l_vaddr = 0;
    std::map<eepromRecordHeader, uint64_t>::iterator l_it;

    // Wrap lookup in mutex because reads are not thread safe
    mutex_lock(&g_eecacheMutex);
    l_it = g_cachedEeproms.find(i_eepromRecordHeader);
    mutex_unlock(&g_eecacheMutex);

    if(l_it != g_cachedEeproms.end())
    {
        l_vaddr = l_it->second;
    }

    if(l_vaddr == 0)
    {
        TRACSSCOMP( g_trac_eeprom, "lookupEepromAddr() failed to find I2CM Huid: 0x%.08X, Port: 0x%.02X, Engine: 0x%.02X, Dev Addr: 0x%.02X, Mux Select: 0x%.02X, Size: 0x%.08X in g_cachedEeproms",
                    i_eepromRecordHeader.completeRecord.i2c_master_huid,
                    i_eepromRecordHeader.completeRecord.port,
                    i_eepromRecordHeader.completeRecord.engine,
                    i_eepromRecordHeader.completeRecord.devAddr,
                    i_eepromRecordHeader.completeRecord.mux_select,
                    i_eepromRecordHeader.completeRecord.cache_copy_size);
    }
    return l_vaddr;
}

errlHndl_t buildEepromRecordHeader(TARGETING::Target * i_target,
                                   eeprom_addr_t & io_eepromInfo,
                                   eepromRecordHeader & o_eepromRecordHeader)
{

    TARGETING::Target * l_muxTarget = nullptr;
    TARGETING::Target * l_i2cMasterTarget = nullptr;
    TARGETING::TargetService& l_targetService = TARGETING::targetService();
    errlHndl_t l_errl = nullptr;

    do{

        l_errl = eepromReadAttributes(i_target, io_eepromInfo);
        if(l_errl)
        {
            TRACFCOMP( g_trac_eeprom,
                      "buildEepromRecordHeader() error occured reading eeprom attributes for eepromType %d, target 0x%.08X, returning!!",
                      io_eepromInfo.eepromRole,
                      TARGETING::get_huid(i_target));
            l_errl->collectTrace(EEPROM_COMP_NAME);
            break;
        }

        // Grab the I2C mux target so we can read the HUID, if the target is NULL we will not be able
        // to lookup attribute to uniquely ID this eeprom so we will not cache it
        l_muxTarget = l_targetService.toTarget( io_eepromInfo.i2cMuxPath);
        if(l_muxTarget == nullptr)
        {
            TRACFCOMP( g_trac_eeprom,
                      "buildEepromRecordHeader() Mux target associated with target 0x%.08X resolved to a nullptr , check attribute for eepromType %d. Skipping Cache",
                      TARGETING::get_huid(i_target),
                      io_eepromInfo.eepromRole);
            /*@
            * @errortype
            * @moduleid     EEPROM_CACHE_EEPROM
            * @reasoncode   EEPROM_I2C_MUX_PATH_ERROR
            * @userdata1    HUID of target we want to cache
            * @userdata2    Type of EEPROM we are caching
            * @devdesc      buildEepromRecordHeader invalid mux target
            */
            l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            EEPROM_CACHE_EEPROM,
                            EEPROM_I2C_MUX_PATH_ERROR,
                            TARGETING::get_huid(i_target),
                            io_eepromInfo.eepromRole,
                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            l_errl->collectTrace(EEPROM_COMP_NAME);
            break;
        }

        // Grab the I2C master target so we can read the HUID, if the target is NULL we will not be able
        // to lookup attribute to uniquely ID this eeprom so we will not cache it
        l_i2cMasterTarget = l_targetService.toTarget( io_eepromInfo.i2cMasterPath );
        if(l_i2cMasterTarget == nullptr)
        {
            TRACFCOMP( g_trac_eeprom,
                      "buildEepromRecordHeader() I2C Master target associated with target 0x%.08X resolved to a nullptr , check attribute for eepromType %d. Skipping Cache ",
                      TARGETING::get_huid(i_target),
                      io_eepromInfo.eepromRole);
            /*@
            * @errortype
            * @moduleid     EEPROM_CACHE_EEPROM
            * @reasoncode   EEPROM_I2C_MASTER_PATH_ERROR
            * @userdata1    HUID of target we want to cache
            * @userdata2    Type of EEPROM we are caching
            * @devdesc      buildEepromRecordHeader invalid master target
            */
            l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            EEPROM_CACHE_EEPROM,
                            EEPROM_I2C_MASTER_PATH_ERROR,
                            TARGETING::get_huid(i_target),
                            io_eepromInfo.eepromRole,
                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            l_errl->collectTrace(EEPROM_COMP_NAME);
            break;
        }

        // This is what we will compare w/ when we are going through the existing
        // caches in the eeprom to see if we have already cached something
        // Or if no matches are found we will copy this into the header
        o_eepromRecordHeader.completeRecord.i2c_master_huid = l_i2cMasterTarget->getAttr<TARGETING::ATTR_HUID>();
        o_eepromRecordHeader.completeRecord.port            = static_cast<uint8_t>(io_eepromInfo.port);
        o_eepromRecordHeader.completeRecord.engine          = static_cast<uint8_t>(io_eepromInfo.engine);
        o_eepromRecordHeader.completeRecord.devAddr         = static_cast<uint8_t>(io_eepromInfo.devAddr);
        o_eepromRecordHeader.completeRecord.mux_select      = static_cast<uint8_t>(io_eepromInfo.i2cMuxBusSelector);
        o_eepromRecordHeader.completeRecord.cache_copy_size     = static_cast<uint32_t>(io_eepromInfo.devSize_KB);

        // Do not set valid bit nor internal offset here as we do not have
        // enough information availible to determine

    }while(0);

    return l_errl;
}

// Do NOT allow adding/removing eeproms to cache during RT
#ifndef __HOSTBOOT_RUNTIME

bool addEepromToCachedList(const eepromRecordHeader & i_eepromRecordHeader)
{
    bool l_matchFound = true;
    std::map<eepromRecordHeader, uint64_t>::iterator it;

    // Map accesses are not thread safe, make sure this is always wrapped in mutex
    mutex_lock(&g_eecacheMutex);

    if(g_cachedEeproms.find(i_eepromRecordHeader) == g_cachedEeproms.end())
    {
        g_cachedEeproms[i_eepromRecordHeader] = g_eecachePnorVaddr + i_eepromRecordHeader.completeRecord.internal_offset;
        TRACSSCOMP( g_trac_eeprom, "addEepromToCachedList() Adding I2CM Huid: 0x%.08X, Port: 0x%.02X, Engine: 0x%.02X, Dev Addr: 0x%.02X, Mux Select: 0x%.02X, Size: 0x%.08X to g_cachedEeproms",
                    i_eepromRecordHeader.completeRecord.i2c_master_huid,
                    i_eepromRecordHeader.completeRecord.port,
                    i_eepromRecordHeader.completeRecord.engine,
                    i_eepromRecordHeader.completeRecord.devAddr,
                    i_eepromRecordHeader.completeRecord.mux_select,
                    i_eepromRecordHeader.completeRecord.cache_copy_size);
        l_matchFound = false;
    }

    mutex_unlock(&g_eecacheMutex);

    return l_matchFound;
}

/**
 * @brief Lookup I2C information for given eeprom, check if eeprom exists in cache.
 *        If it exists already determine if any updates are required. If it is not
 *        in the cache yet, add it to the cache.
 *
 * @param[in]   i_target     Presence detect target
 * @param[in]   i_present    Describes whether or not target is present
 *                           ( CANNOT RELY ON HWAS_STATE!! )
 * @param[in]   i_eepromType Describes which EEPROM associated to the target
 *                           that is being requested to cache. (PRIMARY/BACKUP etc)
 * @return  errlHndl_t
 */
errlHndl_t cacheEeprom(TARGETING::Target* i_target,
                       bool i_present,
                       EEPROM::EEPROM_ROLE i_eepromType)
{
    TRACSSCOMP( g_trac_eeprom, "cacheEeprom() ENTER Target HUID 0x%.08X ", TARGETING::get_huid(i_target));
    errlHndl_t l_errl = nullptr;

    EEPROM::eeprom_addr_t l_eepromInfo;
    eecacheSectionHeader * l_eecacheSectionHeaderPtr;
    eepromRecordHeader l_eepromRecordHeader;

    // Initially assume we will want to update both the entry in the header
    // as well as the contents in the body of the EECACHE section
    bool l_updateHeader = true;
    bool l_updateContents = true;

    do{
        // eepromReadAttributes keys off the eepromRole value
        // to determine what attribute to lookup to get eeprom info
        l_eepromInfo.eepromRole = i_eepromType;

        // if the target is present, then this record is valid
        l_eepromRecordHeader.completeRecord.cached_copy_valid = i_present;

        // buildEepromRecordHeader will call eepromReadAttributes to fill in l_eepromInfo
        // with info looked up in attributes and also fill in l_eepromRecordHeader
        l_errl = buildEepromRecordHeader(i_target, l_eepromInfo, l_eepromRecordHeader);

        TRACDBIN( g_trac_eeprom, "cacheEeprom: l_eepromRecordHeader currently ",
                    &l_eepromRecordHeader,
                    sizeof(eepromRecordHeader));

        if(l_errl)
        {
            // buildEepromRecordHeader should have traced any relavent information if
            // is was needed, just break out and pass the error along
            break;
        }

        // if g_eecachePnorVaddr == 0 this indicates we have not yet looked up
        // the virtual address for the start of the EECACHE pnor section so we must look
        // it up. We can then store it in this global var for later use
        if(g_eecachePnorVaddr == 0 || g_eecachePnorSize == 0)
        {
            PNOR::SectionInfo_t l_sectionInfo;
            l_errl = PNOR::getSectionInfo(PNOR::EECACHE, l_sectionInfo);

            if(l_errl)
            {
                TRACFCOMP( g_trac_eeprom, "cacheEeprom() Failed while looking up the EECACHE section in PNOR!!");
                break;
            }

            mutex_lock(&g_eecacheMutex);
            g_eecachePnorVaddr = l_sectionInfo.vaddr;
            g_eecachePnorSize = l_sectionInfo.size;
            TRACFCOMP( g_trac_eeprom, "cacheEeprom() vaddr for EECACHE start = 0x%lx , size = 0x%lx!!",
                       g_eecachePnorVaddr, g_eecachePnorSize);
            mutex_unlock(&g_eecacheMutex);
        }

        // The start of the EECACHE pnor section follows the order of the eecacheSectionHeader struct
        // that is defined in eepromCache_const.H. This should be the version, followed by the current
        // end of the cache, followed by a list of EEPROM entries that combines huid of mux target, huid
        // of master target, port of eeprom, and devAddr of eeprom to come up with a unqiue identifier
        // for a given eeprom.
        l_eecacheSectionHeaderPtr = reinterpret_cast<eecacheSectionHeader*>(g_eecachePnorVaddr);

        if(l_eecacheSectionHeaderPtr->version == EECACHE_VERSION_UNSET)
        {
            // If version == 0xFF then nothing has been cached before,
            // if nothing has been cached before then version should
            // be set to be the latest version of the struct available
            l_eecacheSectionHeaderPtr->version = EECACHE_VERSION_LATEST;
            TRACFCOMP( g_trac_eeprom,
                       "cacheEeprom() Found Empty Cache, set version of cache structure to be 0x%.02x",
                       EECACHE_VERSION_1);
        }

        if(l_eecacheSectionHeaderPtr->end_of_cache == UNSET_END_OF_CACHE_VALUE)
        {
            // If end_of_cache == 0xFFFFFFFF then we will assume the cache is empty.
            // In this case, we must set end_of_cache to be the end of the header.
            // This means the start of first eeprom's cached data will be immediately
            // following the end of the EECACHE header.
            l_eecacheSectionHeaderPtr->end_of_cache = sizeof(eecacheSectionHeader);
            TRACFCOMP( g_trac_eeprom,
                       "cacheEeprom() Found Empty Cache, set end of cache to be 0x%.04x (End of ToC)",
                       sizeof(eecacheSectionHeader));
        }

        size_t l_eepromLen = l_eepromInfo.devSize_KB  * KILOBYTE;

        // Parse through PNOR section header to determine if a copy of this
        // eeprom already exists, or if we need to add it, and where we should add it
        // if we need to.
        eepromRecordHeader * l_recordHeaderToUpdate = nullptr;

        // Initialize this to an INVALID value. This way we catch the case where
        // cache has 50 records and we cannot add anymore. In that case l_recordHeaderToUpdateIndex
        // would not get set in the loop below.
        uint8_t l_recordHeaderToUpdateIndex = INVALID_EEPROM_INDEX;

        for(uint8_t i = 0; i < MAX_EEPROMS_VERSION_1; i++)
        {
            // Keep track of current record so we can use outside for loop
            l_recordHeaderToUpdate = &l_eecacheSectionHeaderPtr->recordHeaders[i];


            // If internal_offset is UNSET_INTERNAL_OFFSET_VALUE then we will assume this address not been filled
            if(l_recordHeaderToUpdate->completeRecord.internal_offset == UNSET_INTERNAL_OFFSET_VALUE)
            {
                assert((l_eecacheSectionHeaderPtr->end_of_cache + l_eepromLen) < g_eecachePnorSize,
                        "Sum of system EEPROMs is larger than space allocated for EECACHE pnor section");

                l_recordHeaderToUpdateIndex = i;
                // Set this new eepromRecord's offset within the EECACHE PNOR section
                // to be the current "end of cache" offset in the toc.
                l_eepromRecordHeader.completeRecord.internal_offset = l_eecacheSectionHeaderPtr->end_of_cache;
                l_eecacheSectionHeaderPtr->end_of_cache += l_eepromLen;
                l_updateContents = i_present;
                break;
            }

            // Compare the eeprom record we are checking against the eeprom records we are iterating through
            // but ignore the last 9 bytes which have chip size, the offset into this pnor section where the
            // record exists, and a byte that tells us if its valid or not
            if( memcmp(l_recordHeaderToUpdate, &l_eepromRecordHeader, NUM_BYTE_UNIQUE_ID ) == 0 )
            {
                l_recordHeaderToUpdateIndex = i;

                if( l_recordHeaderToUpdate->completeRecord.cache_copy_size != l_eepromRecordHeader.completeRecord.cache_copy_size)
                {
                    // This indicates that a part size has changed , caching
                    // algorithm cannot account for size changes.
                    // Invalidate entire cache and TI to trigger re-ipl
                    l_errl = PNOR::clearSection(PNOR::EECACHE);

                    // If there was an error clearing the cache commit is because we are TIing
                    if(l_errl)
                    {
                        errlCommit(l_errl, EEPROM_COMP_ID);
                    }

                    /*@
                    * @errortype    ERRORLOG::ERRL_SEV_PREDICTIVE
                    * @moduleid     EEPROM_CACHE_EEPROM
                    * @reasoncode   EEPROM_NEW_DEVICE_DETECTED
                    * @userdata1[0:31]  Old Size of Eeprom
                    * @userdata1[32:63] New Size of Eeprom
                    * @userdata2[0:31]  HUID of I2C Master
                    * @userdata2[32:39] Port
                    * @userdata2[40:47] Engine
                    * @userdata2[48:55] HUID of I2C Master
                    * @userdata2[56:63] HUID of I2C Master
                    * @devdesc     New part has likely been loaded into the system.
                    * @custdesc    Firmware detected new part and is restarting
                    */
                    l_errl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_PREDICTIVE,
                                EEPROM_CACHE_EEPROM,
                                EEPROM_NEW_DEVICE_DETECTED,
                                TWO_UINT32_TO_UINT64(l_recordHeaderToUpdate->completeRecord.cache_copy_size ,
                                                     l_eepromRecordHeader.completeRecord.cache_copy_size),
                                TWO_UINT32_TO_UINT64(l_eepromRecordHeader.completeRecord.i2c_master_huid,
                                                     TWO_UINT16_TO_UINT32(
                                                        TWO_UINT8_TO_UINT16(l_eepromRecordHeader.completeRecord.port,
                                                                            l_eepromRecordHeader.completeRecord.engine),
                                                        TWO_UINT8_TO_UINT16(l_eepromRecordHeader.completeRecord.devAddr,
                                                                            l_eepromRecordHeader.completeRecord.mux_select))));
                    errlCommit(l_errl, EEPROM_COMP_ID);

                    #ifdef CONFIG_CONSOLE
                        CONSOLE::displayf(EEPROM_COMP_NAME,
                              "New EEPROM size detected for an existing part, clearing EEPROM cache and performing reconfig loop");
                    #endif

                    INITSERVICE::doShutdown(INITSERVICE::SHUTDOWN_DO_RECONFIG_LOOP);
                }

                //
                // At this point we have found a match in the PNOR but we need
                // to decide what all needs an update
                //

                // Stash the internal_offset of the section we found in so we can add
                // this record to g_cachedEeproms for later use
                l_eepromRecordHeader.completeRecord.internal_offset  =
                            l_recordHeaderToUpdate->completeRecord.internal_offset;


                if(l_recordHeaderToUpdate->completeRecord.cached_copy_valid)
                {
                    // If the existing eeprom record is valid, then only update the
                    // contents if the SN/PN for current HW do not match the eeprom
                    // record. (target must be present to cache)

                    // TODO RTC:203788 add lookup for PN and SN matches
                    //if( !i_present || PNandSNMatch )
                    {
                        l_updateContents = false;
                    }

                    // If target is present there is nothing in the
                    // header to update
                    if( i_present )
                    {
                        l_updateHeader = false;
                    }
                }
                else if(!i_present)
                {
                    // If the target is not present, then do not update contents or header
                    l_updateContents = false;
                    l_updateHeader = false;
                }

                TRACSSCOMP( g_trac_eeprom, "cacheEeprom() already found copy for eeprom role %d for target w/ HUID 0x.%08X",
                          i_eepromType , TARGETING::get_huid(i_target));
                break;
            }
        }

        if(!addEepromToCachedList(l_eepromRecordHeader))
        {
            TRACSSCOMP( g_trac_eeprom, "cacheEeprom() Eeprom w/ Role %d, HUID 0x.%08X added to cached list",
                  i_eepromType , TARGETING::get_huid(i_target));
        }
        else
        {
            TRACSSCOMP( g_trac_eeprom, "cacheEeprom() Eeprom w/ Role %d, HUID 0x.%08X already in cached list",
                  i_eepromType , TARGETING::get_huid(i_target));
        }


        // Above we have determined whether the contents of the eeprom at
        // hand need to have their contents updated. Only do the following
        // steps that update the eeprom's cached data if we were told to do so.
        if(l_updateContents )
        {
            assert(l_recordHeaderToUpdateIndex != INVALID_EEPROM_INDEX,
                    "More than MAX_EEPROMS_VERSION_1 in system XML");

            void * l_tmpBuffer;

            l_tmpBuffer = malloc(l_eepromLen);

            void * l_internalSectionAddr =
                reinterpret_cast<uint8_t *>(l_eecacheSectionHeaderPtr) + l_eepromRecordHeader.completeRecord.internal_offset;

            TRACSSCOMP( g_trac_eeprom, "cacheEeprom() passing the following into deviceOp eeprom address : huid 0x%.08X   length 0x%.08X  vaddr %p" ,
                        get_huid(i_target), l_eepromLen, l_internalSectionAddr);

            // Copy vpd contents to cache
            l_errl = deviceOp(DeviceFW::READ,
                              i_target,
                              l_tmpBuffer,
                              l_eepromLen,
                              DEVICE_EEPROM_ADDRESS(i_eepromType, 0, VPD::SEEPROM));

            // If an error occurred during the eeprom read then free the tmp buffer and break out
            if( l_errl)
            {
                TRACFCOMP(g_trac_eeprom,ERR_MRK"cacheEeprom:  Error occured reading from EEPROM type %d for HUID 0x%.08X!",
                          i_eepromType,get_huid(i_target));
                free(l_tmpBuffer);
                break;
            }

            // Copy from tmp buffer into vaddr of internal section offset
            memcpy(l_internalSectionAddr, l_tmpBuffer,  l_eepromLen);

            // Flush the page to make sure it gets to the PNOR
            int rc = mm_remove_pages( FLUSH, l_internalSectionAddr, l_eepromLen );
            if( rc )
            {
                TRACFCOMP(g_trac_eeprom,ERR_MRK"cacheEeprom:  Error from mm_remove_pages trying for flush contents write to pnor! rc=%d",rc);
                /*@
                * @errortype
                * @moduleid     EEPROM_CACHE_EEPROM
                * @reasoncode   EEPROM_FAILED_TO_FLUSH_CONTENTS
                * @userdata1    Requested Address
                * @userdata2    rc from mm_remove_pages
                * @devdesc      cacheEeprom mm_remove_pages FLUSH failed
                */
                l_errl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                EEPROM_CACHE_EEPROM,
                                EEPROM_FAILED_TO_FLUSH_CONTENTS,
                                (uint64_t)l_internalSectionAddr,
                                TO_UINT64(rc),
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            }
            else
            {
                TRACSSCOMP( g_trac_eeprom, "cacheEeprom() %.08X bytes of eeprom data related to %.08X have been written to %p" ,
                        l_eepromLen, get_huid(i_target), l_internalSectionAddr);
            }

            // regardless of success always free tmp buffer we allocated
            free(l_tmpBuffer);

            if(l_errl)
            {
                break;
            }

        }

        // Above we have determined whether the header entry for the eeprom at
        // hand needs to be updated. Only do the following steps that update
        // the eeprom's header entry if we were told to do so.
        if(l_updateHeader)
        {
            TRACDBIN( g_trac_eeprom, "cacheEeprom: l_eecacheSectionHeaderPtr currently ",
                      l_eecacheSectionHeaderPtr,
                      sizeof(eecacheSectionHeader));
            // Copy the local eepromRecord header struct with the info about the
            // new eeprom we want to add to the cache to the open slot we found
            memcpy(l_recordHeaderToUpdate , &l_eepromRecordHeader, sizeof(eepromRecordHeader));

            // Flush the page to make sure it gets to the PNOR
            int rc = mm_remove_pages( FLUSH, l_recordHeaderToUpdate, sizeof(eepromRecordHeader) );
            if( rc )
            {
                TRACFCOMP(g_trac_eeprom,ERR_MRK"cacheEeprom:  Error from mm_remove_pages trying for flush header write to pnor, rc=%d",rc);
                /*@
                * @errortype
                * @moduleid     EEPROM_CACHE_EEPROM
                * @reasoncode   EEPROM_FAILED_TO_FLUSH_HEADER
                * @userdata1    Requested Address
                * @userdata2    rc from mm_remove_pages
                * @devdesc      cacheEeprom mm_remove_pages FLUSH failed
                */
                l_errl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                EEPROM_CACHE_EEPROM,
                                EEPROM_FAILED_TO_FLUSH_HEADER,
                                (uint64_t)l_recordHeaderToUpdate,
                                TO_UINT64(rc),
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                break;
            }
        }


    }while(0);

    TRACSSCOMP( g_trac_eeprom, "cacheEeprom() EXIT Target HUID 0x%.08X ", TARGETING::get_huid(i_target));

    return l_errl;
}

/**
 * @brief Generic deviceOp that will lookup the PRIMARY_VPD eeprom associated
 *        with a given target and cache the data from the eeprom into the
 *        EECACHE section in PNOR for later use
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        Target whose Eeprom we will try to cache
 * @param[in/out] io_buffer     Read: Pointer to output data storage
 *                              Write: Pointer to input data storage
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes, always 1)
 *                              Output: Success = 1, Failure = 0
 * @param[in]   i_accessType    DeviceFW::AccessType enum (userif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, there are no arguments.
 * @return  errlHndl_t
 */
errlHndl_t genericI2CEepromCache(DeviceFW::OperationType i_opType,
                                          TARGETING::Target* i_target,
                                          void* io_buffer,
                                          size_t& io_buflen,
                                          int64_t i_accessType,
                                          va_list i_args)
{
    errlHndl_t l_errl = nullptr;

    // First param is a uint64_t representing if the target is present or not
    bool l_present = (bool)va_arg(i_args,uint64_t);

    // second param is the type of EEPROM type we wish to cache (PRIMARY vs BACKUP etc)
    EEPROM::EEPROM_ROLE l_eepromType = (EEPROM::EEPROM_ROLE)va_arg(i_args,uint64_t);

    TRACSSCOMP( g_trac_eeprom, ENTER_MRK"genericI2CEepromCache() "
            "Target HUID 0x%.08X Enter", TARGETING::get_huid(i_target));

    do{
        // Run the cache eerpom function on the target passed in
        l_errl = cacheEeprom(i_target, l_present,  l_eepromType);
        if(l_errl)
        {
            TRACFCOMP(g_trac_eeprom,
                      ERR_MRK"cacheEeprom:  An error occured while attempting to cache eeprom for 0x%.08X",
                      TARGETING::get_huid(i_target));
            break;
        }

    }while(0);

    TRACSSCOMP( g_trac_eeprom, EXIT_MRK"genericI2CEepromCache() "
            "Target HUID 0x%.08X EXIT", TARGETING::get_huid(i_target));

    return l_errl;
}

DEVICE_REGISTER_ROUTE( DeviceFW::READ,
                       DeviceFW::EEPROM_CACHE,
                       TARGETING::TYPE_OCMB_CHIP,
                       genericI2CEepromCache);

DEVICE_REGISTER_ROUTE( DeviceFW::READ,
                       DeviceFW::EEPROM_CACHE,
                       TARGETING::TYPE_PROC,
                       genericI2CEepromCache );

DEVICE_REGISTER_ROUTE( DeviceFW::READ,
                       DeviceFW::EEPROM_CACHE,
                       TARGETING::TYPE_DIMM,
                       genericI2CEepromCache );

#endif

errlHndl_t eepromPerformOpCache(DeviceFW::OperationType i_opType,
                                TARGETING::Target * i_target,
                                void *  io_buffer,
                                size_t& io_buflen,
                                eeprom_addr_t &i_eepromInfo)
{
    errlHndl_t l_errl = nullptr;
    eepromRecordHeader l_eepromRecordHeader;

    do{

        TRACSSCOMP( g_trac_eeprom, ENTER_MRK"eepromPerformOpCache() "
                    "Target HUID 0x%.08X Enter", TARGETING::get_huid(i_target));

        l_errl = buildEepromRecordHeader(i_target, i_eepromInfo, l_eepromRecordHeader);

        if(l_errl)
        {
            // buildEepromRecordHeader should have traced any relavent information if
            // it was needed, just break out and pass the error along
            break;
        }

        uint64_t l_eepromCacheVaddr = lookupEepromAddr(l_eepromRecordHeader);

        // Ensure that a copy of the eeprom exists in our map of cached eeproms
        if(l_eepromCacheVaddr)
        {
            // First check if io_buffer is a nullptr, if so then assume user is
            // requesting size back in io_bufferlen
            if(io_buffer == nullptr)
            {
                io_buflen = l_eepromRecordHeader.completeRecord.cache_copy_size * KILOBYTE;
                TRACSSCOMP( g_trac_eeprom, "eepromPerformOpCache() "
                            "io_buffer == nullptr , returning io_buflen as 0x%lx",
                            io_buflen);
                break;
            }

            TRACSSCOMP( g_trac_eeprom, "eepromPerformOpCache() "
                    "Performing %s on target 0x%.08X offset 0x%lx   length 0x%x     vaddr 0x%lx",
                    (i_opType == DeviceFW::READ) ? "READ" : "WRITE",
                    TARGETING::get_huid(i_target),
                    i_eepromInfo.offset, io_buflen, l_eepromCacheVaddr);

            // Make sure that offset + buflen are less than the total size of the eeprom
            if(i_eepromInfo.offset + io_buflen > (l_eepromRecordHeader.completeRecord.cache_copy_size * KILOBYTE))
            {
                TRACFCOMP(g_trac_eeprom,
                          ERR_MRK"eepromPerformOpCache: i_eepromInfo.offset + i_offset is greater than size of eeprom (0x%x KB)",
                          l_eepromRecordHeader.completeRecord.cache_copy_size);
                /*@
                * @errortype
                * @moduleid     EEPROM_CACHE_PERFORM_OP
                * @reasoncode   EEPROM_OVERFLOW_ERROR
                * @userdata1    Length of Operation
                * @userdata2    Offset we are attempting to read/write
                * @custdesc     Soft error in Firmware
                * @devdesc      cacheEeprom invalid op type
                */
                l_errl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                EEPROM_CACHE_PERFORM_OP,
                                EEPROM_OVERFLOW_ERROR,
                                TO_UINT64(io_buflen),
                                TO_UINT64(i_eepromInfo.offset),
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                ERRORLOG::ErrlUserDetailsTarget(i_target).addToLog(l_errl);
                l_errl->collectTrace( EEPROM_COMP_NAME );

                break;
            }

            if(i_opType == DeviceFW::READ)
            {
                memcpy(io_buffer, reinterpret_cast<void *>(l_eepromCacheVaddr + i_eepromInfo.offset), io_buflen);
            }
            else if(i_opType == DeviceFW::WRITE)
            {
                memcpy(reinterpret_cast<void *>(l_eepromCacheVaddr + i_eepromInfo.offset), io_buffer,  io_buflen);

                #ifndef __HOSTBOOT_RUNTIME

                // Perform flush to ensure pnor is updated
                int rc = mm_remove_pages( FLUSH,
                                          reinterpret_cast<void *>(l_eepromCacheVaddr + i_eepromInfo.offset),
                                          io_buflen );
                if( rc )
                {
                    TRACFCOMP(g_trac_eeprom,ERR_MRK"eepromPerformOpCache:  Error from mm_remove_pages trying for flush contents write to pnor! rc=%d",rc);
                    /*@
                    * @errortype
                    * @moduleid     EEPROM_CACHE_PERFORM_OP
                    * @reasoncode   EEPROM_FAILED_TO_FLUSH_CONTENTS
                    * @userdata1    Requested Address
                    * @userdata2    rc from mm_remove_pages
                    * @devdesc      cacheEeprom mm_remove_pages FLUSH failed
                    */
                    l_errl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    EEPROM_CACHE_PERFORM_OP,
                                    EEPROM_FAILED_TO_FLUSH_CONTENTS,
                                    (l_eepromCacheVaddr + i_eepromInfo.offset),
                                    TO_UINT64(rc),
                                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                    l_errl->collectTrace( EEPROM_COMP_NAME );
                }
                #endif //__HOSTBOOT_RUNTIME
            }
            else
            {
                TRACFCOMP(g_trac_eeprom,ERR_MRK"eepromPerformOpCache: Invalid OP_TYPE passed to function, i_opType=%d", i_opType);
                /*@
                * @errortype
                * @moduleid     EEPROM_CACHE_PERFORM_OP
                * @reasoncode   EEPROM_INVALID_OPERATION
                * @userdata1[0:31]  Op Type that was invalid
                * @userdata1[32:63] Eeprom Role
                * @userdata2    Offset we are attempting to perfrom op on
                * @custdesc     Soft error in Firmware
                * @devdesc      cacheEeprom invalid op type
                */
                l_errl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                EEPROM_CACHE_PERFORM_OP,
                                EEPROM_INVALID_OPERATION,
                                TWO_UINT32_TO_UINT64(i_opType,
                                                     i_eepromInfo.eepromRole),
                                TO_UINT64(i_eepromInfo.offset),
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                ERRORLOG::ErrlUserDetailsTarget(i_target).addToLog(l_errl);
                l_errl->collectTrace( EEPROM_COMP_NAME );
            }
        }
        else
        {
            TRACFCOMP( g_trac_eeprom,"eepromPerformOpCache: Failed to find entry in cache for 0x%.08X, %s failed",
                       TARGETING::get_huid(i_target),
                       (i_opType == DeviceFW::READ) ? "READ" : "WRITE");
            /*@
            * @errortype
            * @moduleid     EEPROM_CACHE_PERFORM_OP
            * @reasoncode   EEPROM_NOT_IN_CACHE
            * @userdata1[0:31]  Op Type
            * @userdata1[32:63] Eeprom Role
            * @userdata2    Offset we are attempting to read/write
            * @custdesc     Soft error in Firmware
            * @devdesc      Tried to lookup eeprom not in cache
            */
            l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            EEPROM_CACHE_PERFORM_OP,
                            EEPROM_NOT_IN_CACHE,
                            TWO_UINT32_TO_UINT64(i_opType,
                                                  i_eepromInfo.eepromRole),
                            TO_UINT64(i_eepromInfo.offset),
                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            ERRORLOG::ErrlUserDetailsTarget(i_target).addToLog(l_errl);
            l_errl->collectTrace( EEPROM_COMP_NAME );
        }

        TRACSSCOMP( g_trac_eeprom, EXIT_MRK"eepromPerformOpCache() "
                    "Target HUID 0x%.08X Exit", TARGETING::get_huid(i_target));

    }while(0);

    return l_errl;
}

}
