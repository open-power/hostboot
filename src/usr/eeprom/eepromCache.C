/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/eeprom/eepromCache.C $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
#include <hwas/hwasPlat.H>
#include <i2c/i2c.H>
#include "eepromCache.H"
#include <i2c/i2cif.H>
#include <eeprom/eepromif.H>

#include <eeprom/eepromddreasoncodes.H>
#include <initservice/initserviceif.H>
#include <initservice/initsvcreasoncodes.H>
#include <pnor/pnorif.H>
#include <vpd/vpd_if.H>

#include <errl/errludtarget.H>
#ifdef CONFIG_CONSOLE
#include <console/consoleif.H>
#endif

extern trace_desc_t* g_trac_eeprom;

//#define TRACSSCOMP(args...)  TRACFCOMP(args)
#define TRACSSCOMP(args...)
//#define TRACSSBIN(args...) TRACFBIN(args)
#define TRACSSBIN(args...)

namespace EEPROM
{

// Any time we access either any of the global variables defined below we want
// to wrap the call in this mutex to avoid multi-threading issues
mutex_t g_eecacheMutex = MUTEX_RECURSIVE_INITIALIZER;

// Global variable that will keep track of the virtual address which
// points to the start of the EECACHE section, and the size of this section.
// It is handy to keep these around so we do not need to look them up in the
// pnor code everytime.
uint64_t g_eecachePnorVaddr = 0;
uint64_t g_eecachePnorSize  = 0;

// Global map which is used as a way to quickly look up the virtual address
// of a given eeprom's cached data in EECACHE section
// Key   = eepromRecordHeader with unique info filled out
// Value = A struct of 2 uint64_t virtual addresses ,one points to header address
//         and other points to the location of the cache, and a byte indicating
//         if this eeprom's hardware has changed this IPL
std::map<eepromRecordHeader, EeepromEntryMetaData_t> g_cachedEeproms;

/**
 * @brief A helper function to populate the global variables used by
 *        eecache
 *
 * @return nullptr on success; non-nullptr on error
 */
errlHndl_t populateEecacheGlobals()
{
    errlHndl_t l_errl = nullptr;

    do {
    // if g_eecachePnorVaddr == 0 this indicates we have not yet looked up
    // the virtual address for the start of the EECACHE pnor section so we must
    // look it up. We can then store it in this global var for later use
    if(g_eecachePnorVaddr == 0 || g_eecachePnorSize == 0)
    {
        PNOR::SectionInfo_t l_sectionInfo;
        l_errl = PNOR::getSectionInfo(PNOR::EECACHE, l_sectionInfo);

        if(l_errl)
        {
            TRACFCOMP(g_trac_eeprom, "populateEecacheGlobals() Failed while looking up "
                      "the EECACHE section in PNOR!!");
            break;
        }

        recursive_mutex_lock(&g_eecacheMutex);
        g_eecachePnorVaddr = l_sectionInfo.vaddr;
        g_eecachePnorSize = l_sectionInfo.size;
        TRACFCOMP( g_trac_eeprom, "populateEecacheGlobals() vaddr for EECACHE start = 0x%lx , size = 0x%lx!!",
                   g_eecachePnorVaddr, g_eecachePnorSize);
        recursive_mutex_unlock(&g_eecacheMutex);
    }
    } while(0);
    return l_errl;
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
    TRACSSCOMP( g_trac_eeprom, ENTER_MRK "cacheEeprom() target HUID 0x%.08X, present %d, role %d",
      TARGETING::get_huid(i_target), i_present, i_eepromType);
    errlHndl_t l_errl = nullptr;

    EEPROM::eeprom_addr_t l_eepromInfo;
    eecacheSectionHeader * l_eecacheSectionHeaderPtr;
    eepromRecordHeader l_eepromRecordHeader;

    // Initially assume we will want to update both the entry in the header
    // as well as the contents in the body of the EECACHE section
    bool l_updateHeader = true;
    bool l_updateContents = true;

    // Initially assume this is a new eeprom cache entry
    bool l_newEntryDetected = true;

    do{
        // eepromReadAttributes keys off the eepromRole value
        // to determine what attribute to lookup to get eeprom info
        l_eepromInfo.eepromRole = i_eepromType;

        // if the target is present, then this record is valid
        if(i_present)
        {
            l_eepromRecordHeader.completeRecord.cached_copy_valid = 1;
        }

        // buildEepromRecordHeader will call eepromReadAttributes to fill in l_eepromInfo
        // with info looked up in attributes and also fill in l_eepromRecordHeader
        l_errl = buildEepromRecordHeader(i_target, l_eepromInfo, l_eepromRecordHeader);

        TRACDBIN( g_trac_eeprom, "cacheEeprom: l_eepromRecordHeader currently ",
                    &l_eepromRecordHeader,
                    sizeof(eepromRecordHeader));

        if(l_errl)
        {
            // buildEepromRecordHeader should have traced any relavent information if
            // it was needed, just break out and pass the error along
            break;
        }

        l_errl = populateEecacheGlobals();
        if(l_errl)
        {
            break;
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
            TRACDCOMP( g_trac_eeprom,
                       "cacheEeprom() Found Empty Cache, set version of cache structure to be 0x%.02x",
                       EECACHE_VERSION_LATEST);
        }

        // @todo RTC 247228 - replace assert with a better recovery strategy
        // Do not continue using PNOR EECACHE if it is at an unsupported version
        assert(l_eecacheSectionHeaderPtr->version == EECACHE_VERSION_LATEST,
                "cacheEeprom() EECACHE PNOR version %d is not supported.  Currently supporting %d version",
                l_eecacheSectionHeaderPtr->version, EECACHE_VERSION_LATEST );

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
        // cache has MAX_EEPROMS_LATEST records and we cannot add anymore.
        // In that case l_recordHeaderToUpdateIndex would not get set in the
        // loop below.
        uint8_t l_recordHeaderToUpdateIndex = INVALID_EEPROM_INDEX;

        for(uint8_t i = 0; i < MAX_EEPROMS_LATEST; i++)
        {
            // Keep track of current record so we can use outside for loop
            l_recordHeaderToUpdate = &l_eecacheSectionHeaderPtr->recordHeaders[i];

            // If internal_offset is UNSET_INTERNAL_OFFSET_VALUE then we will assume this address not been filled
            if(l_recordHeaderToUpdate->completeRecord.internal_offset == UNSET_INTERNAL_OFFSET_VALUE)
            {
                assert((l_eecacheSectionHeaderPtr->end_of_cache + l_eepromLen) < g_eecachePnorSize,
                        "Sum of system EEPROMs (%lld + %lld) is larger than space allocated (%lld) for EECACHE pnor section",
                        l_eecacheSectionHeaderPtr->end_of_cache, l_eepromLen, g_eecachePnorSize );

                l_recordHeaderToUpdateIndex = i;
                // Set this new eepromRecord's offset within the EECACHE PNOR section
                // to be the current "end of cache" offset in the toc.
                l_eepromRecordHeader.completeRecord.internal_offset = l_eecacheSectionHeaderPtr->end_of_cache;
                l_eecacheSectionHeaderPtr->end_of_cache += l_eepromLen;

                // Set cached_copy_valid to 0 until the cache contents actually gets loaded
                l_recordHeaderToUpdate->completeRecord.cached_copy_valid = 0;

                TRACFCOMP(g_trac_eeprom, "cacheEeprom() - no eecache record in PNOR found for %s %.8X target w/ eepromRole = %d -> empty slot %d",
                    i_present?"present":"non-present", TARGETING::get_huid(i_target), i_eepromType, i);
                l_updateContents = i_present;
                break;
            }

            // Compare the eeprom record we are checking against the eeprom records we are iterating through
            // but ignore the last 9 bytes which have chip size, the offset into this pnor section where the
            // record exists, and a byte that tells us if its valid or not
            if( memcmp(l_recordHeaderToUpdate, &l_eepromRecordHeader, NUM_BYTE_UNIQUE_ID ) == 0 )
            {
                l_recordHeaderToUpdateIndex = i;
                // We have matched with existing eeprom in the PNOR's EECACHE
                // section. So we know this is not a new entry.
                l_newEntryDetected = false;

                if( l_recordHeaderToUpdate->completeRecord.cache_copy_size !=
                    l_eepromRecordHeader.completeRecord.cache_copy_size )
                {
                    // This indicates that a part size has changed, caching
                    // algorithm cannot account for size changes.
                    // Invalidate entire cache and TI to trigger re-ipl
                    l_errl = PNOR::clearSection(PNOR::EECACHE);

                    // If there was an error clearing the cache commit is because we are TIing
                    if(l_errl)
                    {
                        errlCommit(l_errl, EEPROM_COMP_ID);
                    }

                    uint64_t l_userdata2;
                    if (l_eepromRecordHeader.completeRecord.accessType ==
                        EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_I2C)
                    {
                        l_userdata2 = TWO_UINT32_TO_UINT64(
                            l_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.i2c_master_huid,
                            TWO_UINT16_TO_UINT32(
                              TWO_UINT8_TO_UINT16(l_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.port,
                                                  l_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.engine),
                              TWO_UINT8_TO_UINT16(l_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.devAddr,
                                                  l_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.mux_select)));
                    }
                    else
                    {
                        l_userdata2 = TWO_UINT32_TO_UINT64(
                            l_eepromRecordHeader.completeRecord.eepromAccess.spiAccess.spi_master_huid,
                            TWO_UINT16_TO_UINT32(
                              TWO_UINT8_TO_UINT16(0xFF,
                                l_eepromRecordHeader.completeRecord.eepromAccess.spiAccess.engine),
                                l_eepromRecordHeader.completeRecord.eepromAccess.spiAccess.offset_KB) );
                    }

                    /*@
                    * @errortype    ERRORLOG::ERRL_SEV_PREDICTIVE
                    * @moduleid     EEPROM_CACHE_EEPROM
                    * @reasoncode   EEPROM_NEW_DEVICE_DETECTED
                    * @userdata1[0:31]  Old Size of Eeprom
                    * @userdata1[32:63] New Size of Eeprom
                    * @userdata2[0:31]  HUID of Master
                    * @userdata2[32:39] Port (or 0xFF)
                    * @userdata2[40:47] Engine
                    * @userdata2[48:55] devAddr    (or byte 0 offset_KB)
                    * @userdata2[56:63] mux_select (or byte 1 offset_KB)
                    * @devdesc     New part has likely been loaded into the system.
                    * @custdesc    Firmware detected new part and is restarting
                    */
                    l_errl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_PREDICTIVE,
                                EEPROM_CACHE_EEPROM,
                                EEPROM_NEW_DEVICE_DETECTED,
                                TWO_UINT32_TO_UINT64(l_recordHeaderToUpdate->completeRecord.cache_copy_size ,
                                                     l_eepromRecordHeader.completeRecord.cache_copy_size),
                                l_userdata2 );
                    errlCommit(l_errl, EEPROM_COMP_ID);

                    #ifdef CONFIG_CONSOLE
                        CONSOLE::displayf(EEPROM_COMP_NAME,
                              "New EEPROM size detected for an existing part,"
                              "clearing EEPROM cache and performing reconfig loop");
                    #endif

                    INITSERVICE::doShutdown(INITSERVICE::SHUTDOWN_DO_RECONFIG_LOOP);
                }

                // Stash the internal_offset of the section we found in so we
                // can add this record to g_cachedEeproms for later use
                l_eepromRecordHeader.completeRecord.internal_offset  =
                        l_recordHeaderToUpdate->completeRecord.internal_offset;

                TRACFCOMP(g_trac_eeprom,
                          "cacheEeprom() already found copy for eeprom role %d "
                          "for target w/ HUID 0x%08X in EECACHE table of contents"
                          " at 0x%X internal address",
                          i_eepromType , TARGETING::get_huid(i_target),
                          l_eepromRecordHeader.completeRecord.internal_offset);
                break;
            }
        }

        // pass the record we have been building up (l_eepromRecordHeader)
        // and the virtual address of this eeprom's record entry in the
        // EECACHE table of contents as a uint64.
        if(!addEepromToCachedList(l_eepromRecordHeader,
                                  reinterpret_cast<uint64_t>(l_recordHeaderToUpdate)))
        {
            TRACSSCOMP( g_trac_eeprom,
                        "cacheEeprom() Eeprom w/ Role %d, HUID 0x%.08X added to the global map of cached eeproms",
                        i_eepromType , TARGETING::get_huid(i_target));
        }
        else
        {
            // If this target's eeprom has already been cached in PNOR and our global map
            // indicates the cache entry was updated this boot, then we must also
            // mark this target associated with the cached eeprom as changed for hwas
            if( l_eepromRecordHeader.completeRecord.master_eeprom
                 && hasEeepromChanged( l_eepromRecordHeader ) )
            {
                HWAS::markTargetChanged(i_target);
            }
            TRACSSCOMP( g_trac_eeprom,
                      "cacheEeprom() Eeprom w/ Role %d, HUID 0x%.08X already in global map of cached eeproms",
                      i_eepromType, TARGETING::get_huid(i_target));

            // Cache entry has already been updated via another target, just break out
            break;
        }

        // Only check if the cache is in sync with HARDWARE if there is an
        // existing EECACHE section. Otherwise, the code after this logic will
        // take care of adding a new eeprom cache section for the target.
        if (l_recordHeaderToUpdate->completeRecord.cached_copy_valid)
        {
            // At this point we have found a match in the PNOR but we need
            // to decide what all needs an update.
            bool l_isInSync = false;

            if (i_present)
            {
                l_isInSync = true;
                l_errl = isEepromInSync(i_target, *l_recordHeaderToUpdate,
                                        i_eepromType, l_isInSync);
                if (l_errl != nullptr)
                {
                    break;
                }

                if(l_isInSync)
                {
                    TRACFCOMP(g_trac_eeprom, "cacheEeprom() - 0x%.8X target w/ %d eepromRole - eeprom is in-sync",
                          TARGETING::get_huid(i_target), i_eepromType);
                    l_updateContents = false;
                }
            }
            else
            {
                // Clear out the contents of the cache for this eeprom if we have detected that it
                // was once valid, indicating it was present at one time, and is now showing
                // up as not present. We want to clear the contents of cache so we can achieve
                // the replug behavior where a tester can remove the part, boot, then plug in the
                // same part and boot again fresh.
                if ( l_recordHeaderToUpdate->completeRecord.accessType ==
                     EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_I2C )
                {
                        TRACFCOMP( g_trac_eeprom, "Detected i2cMaster 0x%.08X"
                                   " Engine 0x%.02X Port 0x%.02X"
                                   " MuxSelect 0x%.02X DevAddr 0x%.02X"
                                   " no longer present, clearing cache and marking cache as invalid",
                                   l_recordHeaderToUpdate->completeRecord.eepromAccess.i2cAccess.i2c_master_huid,
                                   l_recordHeaderToUpdate->completeRecord.eepromAccess.i2cAccess.engine,
                                   l_recordHeaderToUpdate->completeRecord.eepromAccess.i2cAccess.port,
                                   l_recordHeaderToUpdate->completeRecord.eepromAccess.i2cAccess.mux_select,
                                   l_recordHeaderToUpdate->completeRecord.eepromAccess.i2cAccess.devAddr );
                 }
                else
                {
                    TRACFCOMP( g_trac_eeprom, "Detected spiMaster 0x%.08X"
                               " Engine 0x%.02X no longer present, clearing"
                               " cache and marking cache as invalid",
                               l_recordHeaderToUpdate->completeRecord.eepromAccess.spiAccess.spi_master_huid,
                               l_recordHeaderToUpdate->completeRecord.eepromAccess.spiAccess.engine );
                }
                l_errl = clearEecache(l_eecacheSectionHeaderPtr, l_eepromRecordHeader);
                // allow l_errl to be returned

                if (l_eepromRecordHeader.completeRecord.master_eeprom)
                {
                    // We have cleared the cache entry, this indicates we have found a part has been removed.
                    // Mark that the target is changed in hwas.
                    HWAS::markTargetChanged(i_target);
                }

                // PNOR contents already cleared by clearEecache()
                TRACFCOMP(g_trac_eeprom, "cacheEeprom() - 0x%.8X target w/ %d eepromRole - eeprom contents cleared",
                          TARGETING::get_huid(i_target), i_eepromType);
                l_updateContents = false;
            }

            // By this point, the PNOR header is accurate and does not need updating
            l_updateHeader = false;
        }
        else if(!i_present)
        {
            // If the target is not present, then do not update contents
            // or header
            TRACFCOMP(g_trac_eeprom, "cacheEeprom() - 0x%.8X target w/ %d eepromRole - cache already invalid and target not present",
                          TARGETING::get_huid(i_target), i_eepromType);
            l_updateContents = false;
            // Only update header if this is a new entry
            l_updateHeader = l_newEntryDetected;
        }
        // The check below makes sure that is isnt a new entry
        // If there is a matching header entry in PNOR marked 'invalid'
        // but we now see the target as present, this indicates a replacement
        // part has been added where a part was removed
        else if(!l_newEntryDetected)
        {
            if ( l_recordHeaderToUpdate->completeRecord.accessType ==
                     EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_I2C )
            {
                TRACFCOMP(g_trac_eeprom, "cacheEeprom() Detected replacement of a part"
                      " i2cMaster 0x%.08X Engine 0x%.02X"
                      " Port 0x%.02X MuxSelect 0x%.02X DevAddr 0x%.02X"
                      " that was previously removed, we will update the cache with new part's eeproms contents",
                      l_recordHeaderToUpdate->completeRecord.eepromAccess.i2cAccess.i2c_master_huid,
                      l_recordHeaderToUpdate->completeRecord.eepromAccess.i2cAccess.engine,
                      l_recordHeaderToUpdate->completeRecord.eepromAccess.i2cAccess.port,
                      l_recordHeaderToUpdate->completeRecord.eepromAccess.i2cAccess.mux_select,
                      l_recordHeaderToUpdate->completeRecord.eepromAccess.i2cAccess.devAddr);
            }
            else
            {
                TRACFCOMP(g_trac_eeprom, "cacheEeprom() Detected replacement of a part"
                      " spiMaster 0x%.08X Engine 0x%.02X"
                      " that was previously removed, we will update the cache with new part's eeproms contents",
                      l_recordHeaderToUpdate->completeRecord.eepromAccess.spiAccess.spi_master_huid,
                      l_recordHeaderToUpdate->completeRecord.eepromAccess.spiAccess.engine);
            }
        }

        // Above we have determined whether the contents of the eeprom at
        // hand need to have their contents updated. Only do the following
        // steps that update the eeprom's cached data if we were told to do so.
        if( l_updateContents )
        {
            TRACFCOMP( g_trac_eeprom, "cacheEeprom() updating cache entry for 0x%.8X target of type %d",
                      get_huid(i_target), i_eepromType );

            assert(l_recordHeaderToUpdateIndex != INVALID_EEPROM_INDEX,
                    "Exceeded the max %d records in PNOR EECACHE", MAX_EEPROMS_LATEST);

            void * l_tmpBuffer;

            l_tmpBuffer = malloc(l_eepromLen);

            void * l_internalSectionAddr =
                reinterpret_cast<uint8_t *>(l_eecacheSectionHeaderPtr) +
                l_eepromRecordHeader.completeRecord.internal_offset;

            TRACFCOMP( g_trac_eeprom, "cacheEeprom() passing the following into deviceOp eeprom address : huid 0x%.08X   length 0x%.08X  vaddr %p" ,
                      get_huid(i_target), l_eepromLen, l_internalSectionAddr );

            // Copy vpd contents to cache
            l_errl = deviceOp(DeviceFW::READ,
                              i_target,
                              l_tmpBuffer,
                              l_eepromLen,
                              DEVICE_EEPROM_ADDRESS(i_eepromType, 0, EEPROM::HARDWARE));

            // If an error occurred during the eeprom read then free the tmp buffer and break out
            if( l_errl)
            {
                TRACFCOMP(g_trac_eeprom,ERR_MRK"cacheEeprom:  Error occured reading from EEPROM type %d for HUID 0x%.08X!",
                          i_eepromType, get_huid(i_target));
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

            // Set mark_target_changed and cached_copy_valid and update set updateHeader
            // Since we have copied stuff in the cache is valid, and been updated.
            // Even if this is a replacement ( cached_copy_valid was already 1) we
            // must set mark_target_changed so just always update the header
            setEeepromChanged(l_eepromRecordHeader);
            // We will update header in PNOR below so no need to call
            // setIsValidCacheEntry right here
            l_eepromRecordHeader.completeRecord.cached_copy_valid = 1;
            l_updateHeader = true;

            if (l_eepromRecordHeader.completeRecord.master_eeprom)
            {
                // We have updated the cache entry, this indicates we have found a "new" part.
                // Mark that the target is changed in hwas.
                HWAS::markTargetChanged(i_target);
            }
        }


        // Above we have determined whether the header entry for the eeprom at
        // hand needs to be updated. Only do the following steps that update
        // the eeprom's header entry if we were told to do so.
        if(l_updateHeader)
        {
            TRACSSCOMP(g_trac_eeprom,"cacheEeprom:  Copy record header to PNOR.");
            TRACSSBIN( g_trac_eeprom,"RECORD HEADER", &l_eepromRecordHeader, sizeof(eepromRecordHeader));

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

    TRACSSCOMP( g_trac_eeprom, "cacheEeprom() EXIT Target HUID 0x%.08X, l_errl rc = 0x%02X",
      TARGETING::get_huid(i_target), ERRL_GETRC_SAFE(l_errl) );

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
 * @param[in/out] io_buffer     Not used
 * @param[in/out] io_buflen     Not used
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
        // Run the cache eeprom function on the target passed in
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
            "Target HUID 0x%.08X EXIT, rc = %d", TARGETING::get_huid(i_target),
            ERRL_GETRC_SAFE(l_errl) );

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

errlHndl_t setIsValidCacheEntry(const TARGETING::Target * i_target,
                                const EEPROM_ROLE &i_eepromRole,
                                bool i_isValid)
{
    errlHndl_t l_errl = nullptr;
    eepromRecordHeader l_eepromRecordHeader;
    eeprom_addr_t l_eepromInfo;

    do{

        TRACDCOMP( g_trac_eeprom, ENTER_MRK"setIsValidCacheEntry() "
                    "Target HUID 0x%.08X  Eeprom Role = %d  Enter",
                    TARGETING::get_huid(i_target), l_eepromInfo.eepromRole);

        l_eepromInfo.eepromRole = i_eepromRole;
        l_errl = buildEepromRecordHeader(const_cast<TARGETING::Target *>(i_target), l_eepromInfo, l_eepromRecordHeader);

        if(l_errl)
        {
            break;
        }

        l_errl = setIsValidCacheEntry(l_eepromRecordHeader, i_isValid);

    }while(0);

    return l_errl;
}

errlHndl_t setIsValidCacheEntry(const eepromRecordHeader& i_eepromRecordHeader, bool i_isValid)
{
    errlHndl_t l_errl = nullptr;
    eepromRecordHeader * l_eepromRecordHeaderToUpdate;

    do{

        TRACDCOMP( g_trac_eeprom, ENTER_MRK"setIsValidCacheEntry(%d)", i_isValid);

        // Find the address of the header entry in the table of contents of the EECACHE pnor section
        l_eepromRecordHeaderToUpdate =
            reinterpret_cast<eepromRecordHeader *>(lookupEepromHeaderAddr(i_eepromRecordHeader));

        if(l_eepromRecordHeaderToUpdate == 0)
        {
              TRACFCOMP(g_trac_eeprom,
                        ERR_MRK"setIsValidCacheEntry:  Attempting to invalidate cache for an "
                        "eeprom but we could not find in global eecache map");

              /*@
              * @errortype
              * @moduleid     EEPROM_INVALIDATE_CACHE
              * @reasoncode   EEPROM_CACHE_NOT_FOUND_IN_MAP
              * @userdata1[0:31]  HUID of Master
              * @userdata1[32:39] Port (or 0xFF)
              * @userdata1[40:47] Engine
              * @userdata1[48:55] devAddr    (or byte 0 offset_KB)
              * @userdata1[56:63] mux_select (or byte 1 offset_KB)
              * @userdata2[0:31]  size of eeprom
              * @userdata2[32:63] access type
              * @devdesc      invalidateCache failed to find cache in map
              */
              l_errl = new ERRORLOG::ErrlEntry(
                              ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                              EEPROM_INVALIDATE_CACHE,
                              EEPROM_CACHE_NOT_FOUND_IN_MAP,
                              getEepromHeaderUserData(i_eepromRecordHeader),
                              TWO_UINT32_TO_UINT64(
                                  i_eepromRecordHeader.completeRecord.cache_copy_size,
                                  i_eepromRecordHeader.completeRecord.accessType),
                              ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
              break;
        }

        // Ensure that information at the address we just looked up matches the record we built up
        if( memcmp(&l_eepromRecordHeaderToUpdate->uniqueRecord.uniqueID,
                   &i_eepromRecordHeader.uniqueRecord.uniqueID,
                   NUM_BYTE_UNIQUE_ID ) != 0 )
        {
              TRACFCOMP(g_trac_eeprom,ERR_MRK"setIsValidCacheEntry:  Attempting to invalidate cache for an "
                        "eeprom but we could not find the entry in table of contents of EECACHE section of pnor");

              /*@
              * @errortype
              * @moduleid     EEPROM_INVALIDATE_CACHE
              * @reasoncode   EEPROM_CACHE_NOT_FOUND_IN_PNOR
              * @userdata1[0:31]  HUID of Master
              * @userdata1[32:39] Port (or 0xFF)
              * @userdata1[40:47] Engine
              * @userdata1[48:55] devAddr    (or byte 0 offset_KB)
              * @userdata1[56:63] mux_select (or byte 1 offset_KB)
              * @userdata2[0:31]  size of eeprom
              * @userdata2[32:63] access type
              * @devdesc      invalidateCache failed to find cache in pnor
              */
              l_errl = new ERRORLOG::ErrlEntry(
                              ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                              EEPROM_INVALIDATE_CACHE,
                              EEPROM_CACHE_NOT_FOUND_IN_PNOR,
                              getEepromHeaderUserData(i_eepromRecordHeader),
                              TWO_UINT32_TO_UINT64(
                                  i_eepromRecordHeader.completeRecord.cache_copy_size,
                                  i_eepromRecordHeader.completeRecord.accessType),
                              ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
              break;
        }

        // Update the header so that it state the entry is invalid
        TRACSSCOMP(g_trac_eeprom,"setIsValidCacheEntry() - setting 0x%08X record to %d cached_copy_valid",
          getEepromHeaderUserData(i_eepromRecordHeader), i_isValid);
        l_eepromRecordHeaderToUpdate->completeRecord.cached_copy_valid = i_isValid;

        // Flush the page to make sure it gets to the PNOR
        int rc = mm_remove_pages( FLUSH,
                                  l_eepromRecordHeaderToUpdate,
                                  sizeof(eepromRecordHeader) );
        if( rc )
        {
            TRACFCOMP(g_trac_eeprom,
                      ERR_MRK"setIsValidCacheEntry:  Error from mm_remove_pages trying for flush header write to pnor, rc=%d",rc);
            /*@
            * @errortype
            * @moduleid     EEPROM_INVALIDATE_CACHE
            * @reasoncode   EEPROM_FAILED_TO_FLUSH_HEADER
            * @userdata1    Requested Address
            * @userdata2    rc from mm_remove_pages
            * @devdesc      invalidateCache mm_remove_pages FLUSH failed
            */
            l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            EEPROM_INVALIDATE_CACHE,
                            EEPROM_FAILED_TO_FLUSH_HEADER,
                            (uint64_t)l_eepromRecordHeaderToUpdate,
                            TO_UINT64(rc),
                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
        }

    }while(0);

    return l_errl;
}

bool addEepromToCachedList(const eepromRecordHeader & i_eepromRecordHeader,
                           const uint64_t i_recordHeaderVaddr)
{
    bool l_matchFound = true;

    recursive_mutex_lock(&g_eecacheMutex);
    if(g_cachedEeproms.find(i_eepromRecordHeader) == g_cachedEeproms.end())
    {
        // Map accesses aren't thread safe, make sure this is always wrapped in
        // mutex
        g_cachedEeproms[i_eepromRecordHeader].cache_entry_address =
              g_eecachePnorVaddr + i_eepromRecordHeader.completeRecord.internal_offset;

        g_cachedEeproms[i_eepromRecordHeader].header_entry_address =
              i_recordHeaderVaddr;

        if (i_eepromRecordHeader.completeRecord.accessType ==
            EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_I2C)
        {
            TRACSSCOMP( g_trac_eeprom,
                        "addEepromToCachedList() Adding access: 0x%02X,"
                        " I2CM Huid: 0x%.08X, Port: 0x%.02X,"
                        " Engine: 0x%.02X, Dev Addr: 0x%.02X, Mux Select: 0x%.02X,"
                        " Size: 0x%.08X to g_cachedEeproms",
                        i_eepromRecordHeader.completeRecord.accessType,
                        i_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.i2c_master_huid,
                        i_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.port,
                        i_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.engine,
                        i_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.devAddr,
                        i_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.mux_select,
                        i_eepromRecordHeader.completeRecord.cache_copy_size);
        }
        else
        {
            TRACSSCOMP( g_trac_eeprom,
                        "addEepromToCachedList() Adding access: 0x%02X,"
                        " SPI master Huid: 0x%.08X, Engine: 0x%.02X, offset_KB: 0x%.04X, "
                        " Size: 0x%.08X to g_cachedEeproms",
                        i_eepromRecordHeader.completeRecord.accessType,
                        i_eepromRecordHeader.completeRecord.eepromAccess.spiAccess.spi_master_huid,
                        i_eepromRecordHeader.completeRecord.eepromAccess.spiAccess.engine,
                        i_eepromRecordHeader.completeRecord.eepromAccess.spiAccess.offset_KB,
                        i_eepromRecordHeader.completeRecord.cache_copy_size);

        }
        l_matchFound = false;
    }
    recursive_mutex_unlock(&g_eecacheMutex);

    return l_matchFound;
}

void printTableOfContentsFromPnor(bool i_only_valid_entries)
{
    eecacheSectionHeader * l_eecacheSectionHeaderPtr =
              reinterpret_cast<eecacheSectionHeader*>(g_eecachePnorVaddr);

    TRACFCOMP( g_trac_eeprom,
               "printTableOfContentsFromPnor(): Version = 0x%.02X,"
               "End of Cache = 0x%.08X",
               l_eecacheSectionHeaderPtr->version,
               l_eecacheSectionHeaderPtr->end_of_cache);
    TRACFCOMP( g_trac_eeprom, "PNOR vaddr for EECACHE start = 0x%lx , size = 0x%lx!!",
               g_eecachePnorVaddr, g_eecachePnorSize);

    for(uint8_t i = 0; i < MAX_EEPROMS_LATEST; i++)
    {
        eepromRecordHeader l_currentRecordHeader =
              l_eecacheSectionHeaderPtr->recordHeaders[i];

        if (i_only_valid_entries && !l_currentRecordHeader.completeRecord.cached_copy_valid)
        {
            continue;
        }

        if( l_currentRecordHeader.completeRecord.internal_offset !=
            UNSET_INTERNAL_OFFSET_VALUE)
        {
            if ( l_currentRecordHeader.completeRecord.accessType ==
                 EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_I2C )
            {
                TRACFCOMP( g_trac_eeprom, "printTableOfContentsFromPnor():"
                    " 0x%.02X accessType, I2CM Huid: 0x%.08X, Port: 0x%.02X,"
                    " Engine: 0x%.02X, Dev Addr: 0x%.02X,"
                    " Mux Select: 0x%.02X, Size: 0x%.08X",
                    l_currentRecordHeader.completeRecord.accessType,
                    l_currentRecordHeader.completeRecord.eepromAccess.i2cAccess.i2c_master_huid,
                    l_currentRecordHeader.completeRecord.eepromAccess.i2cAccess.port,
                    l_currentRecordHeader.completeRecord.eepromAccess.i2cAccess.engine,
                    l_currentRecordHeader.completeRecord.eepromAccess.i2cAccess.devAddr,
                    l_currentRecordHeader.completeRecord.eepromAccess.i2cAccess.mux_select,
                    l_currentRecordHeader.completeRecord.cache_copy_size );
            }
            else
            {
                TRACFCOMP( g_trac_eeprom, "printTableOfContentsFromPnor():"
                    " 0x%.02X accessType, SPI Master Huid: 0x%.08X,"
                    " Engine: 0x%.02X, recordOffset_KB: 0x%04X, Size: 0x%.08X",
                    l_currentRecordHeader.completeRecord.accessType,
                    l_currentRecordHeader.completeRecord.eepromAccess.spiAccess.spi_master_huid,
                    l_currentRecordHeader.completeRecord.eepromAccess.spiAccess.engine,
                    l_currentRecordHeader.completeRecord.eepromAccess.spiAccess.offset_KB,
                    l_currentRecordHeader.completeRecord.cache_copy_size );
            }
            TRACFCOMP( g_trac_eeprom,
                       "                            "
                       "Internal Offset: 0x%.08X, Cache Valid: %X, Master record: %X",
                       l_currentRecordHeader.completeRecord.internal_offset,
                       l_currentRecordHeader.completeRecord.cached_copy_valid,
                       l_currentRecordHeader.completeRecord.master_eeprom );
        }
    }

}

void printTableOfContentsFromGlobalMemory(bool i_only_valid_entries)
{
    recursive_mutex_lock(&g_eecacheMutex);
    for (auto& cachedEeprom : g_cachedEeproms)
    {
        const eepromRecordHeader * pHeader = &cachedEeprom.first;

        if (i_only_valid_entries && !pHeader->completeRecord.cached_copy_valid)
        {
            continue;
        }

        if ( pHeader->completeRecord.accessType ==
                 EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_I2C )
        {
            TRACFCOMP( g_trac_eeprom, "printTableOfContentsFromGlobalMemory():"
                "0x%.02X accessType, I2CM Huid: 0x%.08X, Port: 0x%.02X,"
                " Engine: 0x%.02X, Dev Addr: 0x%.02X,"
                " Mux Select: 0x%.02X, Size: 0x%.08X",
                pHeader->completeRecord.accessType,
                pHeader->completeRecord.eepromAccess.i2cAccess.i2c_master_huid,
                pHeader->completeRecord.eepromAccess.i2cAccess.port,
                pHeader->completeRecord.eepromAccess.i2cAccess.engine,
                pHeader->completeRecord.eepromAccess.i2cAccess.devAddr,
                pHeader->completeRecord.eepromAccess.i2cAccess.mux_select,
                pHeader->completeRecord.cache_copy_size );
        }
        else
        {
            TRACFCOMP( g_trac_eeprom, "printTableOfContentsFromGlobalMemory():"
                "0x%.02X accessType, SPI Master Huid: 0x%.08X,"
                " Engine: 0x%.02X, recordOffset_KB: 0x%04X, Size: 0x%.08X",
                pHeader->completeRecord.accessType,
                pHeader->completeRecord.eepromAccess.spiAccess.spi_master_huid,
                pHeader->completeRecord.eepromAccess.spiAccess.engine,
                pHeader->completeRecord.eepromAccess.spiAccess.offset_KB,
                pHeader->completeRecord.cache_copy_size );
        }
        TRACFCOMP( g_trac_eeprom,
                   "                            "
                   "Internal Offset: 0x%.08X, Cache Valid: %X, "
                   "Master record: %X",
                   pHeader->completeRecord.internal_offset,
                   pHeader->completeRecord.cached_copy_valid,
                   pHeader->completeRecord.master_eeprom);
        TRACFCOMP( g_trac_eeprom,
                   "header_addr = 0x%.8X, cache_entry_addr = 0x%.8X, "
                   "mark_target_changed = 0x%X",
                   cachedEeprom.second.header_entry_address,
                   cachedEeprom.second.cache_entry_address,
                   cachedEeprom.second.mark_target_changed );

    }
    recursive_mutex_unlock(&g_eecacheMutex);
}


void getMasterEepromCacheState(const eepromRecordHeader & i_eepromRecordHeader,
                               bool & o_valid, bool & o_changed)
{
    o_valid = false;
    o_changed = false;

    TRACSSBIN(g_trac_eeprom,
              "getMasterEepromCacheState: Looking for",
              &i_eepromRecordHeader,
              sizeof(i_eepromRecordHeader));

    // find master for this eeprom
    // Map accesses are not thread safe, make sure this is always wrapped in mutex
    recursive_mutex_lock(&g_eecacheMutex);
    for (auto& cachedEeprom : g_cachedEeproms)
    {
        const eepromRecordHeader * pHeader = &cachedEeprom.first;
        if (eepromsMatch(const_cast<eepromRecordHeader*>(&i_eepromRecordHeader),
                         const_cast<eepromRecordHeader*>(pHeader)) &&
           (pHeader->completeRecord.master_eeprom == 1) )
        {
            // At this point pHeader points to the master eeprom in g_cachedEeeproms
            // Use this header to find its equivalent in PNOR to check its validity
            eepromRecordHeader * l_pnorEepromHeader =
                reinterpret_cast<eepromRecordHeader *>(lookupEepromHeaderAddr(*pHeader));
            if ( l_pnorEepromHeader != 0 )
            {
                o_valid = l_pnorEepromHeader->completeRecord.cached_copy_valid;
            }
            o_changed = cachedEeprom.second.mark_target_changed;
            break;
        }
    }
    recursive_mutex_unlock(&g_eecacheMutex);
}


bool hasEeepromChanged(const eepromRecordHeader & i_eepromRecordHeader)
{
    bool l_eepromHasChanged = false;

    // Map accesses are not thread safe, make sure this is always wrapped in mutex
    recursive_mutex_lock(&g_eecacheMutex);

    if(g_cachedEeproms.find(i_eepromRecordHeader) != g_cachedEeproms.end())
    {
        l_eepromHasChanged = g_cachedEeproms[i_eepromRecordHeader].mark_target_changed;
    }

    recursive_mutex_unlock(&g_eecacheMutex);

    return l_eepromHasChanged;
}

void setEeepromChanged(const eepromRecordHeader & i_eepromRecordHeader)
{

    // Map accesses are not thread safe, make sure this is always wrapped in mutex
    recursive_mutex_lock(&g_eecacheMutex);

    if(g_cachedEeproms.find(i_eepromRecordHeader) != g_cachedEeproms.end())
    {
        g_cachedEeproms[i_eepromRecordHeader].mark_target_changed = true;
    }

    recursive_mutex_unlock(&g_eecacheMutex);

}

void clearCachedEeprom(const eepromRecordHeader & i_eepromRecordHeader)
{
    // Map accesses are not thread safe, make sure this is always wrapped in mutex
    recursive_mutex_lock(&g_eecacheMutex);

    if(g_cachedEeproms.find(i_eepromRecordHeader) != g_cachedEeproms.end())
    {
        // Update record in g_cachedEeeproms() as changed
        // and set cache_entry_address to zero to prevent
        // access to invalid memory
        g_cachedEeproms[i_eepromRecordHeader].mark_target_changed = true;
        g_cachedEeproms[i_eepromRecordHeader].cache_entry_address = 0;
    }

    recursive_mutex_unlock(&g_eecacheMutex);
}

uint64_t lookupEepromCacheAddr(const eepromRecordHeader& i_eepromRecordHeader)
{
    uint64_t l_vaddr = 0;
    std::map<eepromRecordHeader, EeepromEntryMetaData_t>::iterator l_it;

    // Wrap lookup in mutex because reads are not thread safe
    recursive_mutex_lock(&g_eecacheMutex);

    if (i_eepromRecordHeader.completeRecord.accessType == EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_I2C)
    {
        TRACSSCOMP( g_trac_eeprom, "lookupEepromCacheAddr() accessType: 0x%02X = I2C -> master: 0x%.8X, port: 0x%02X, engine: 0x%02X, devAddr: 0x%02X, mux_select: 0x%02X",
            i_eepromRecordHeader.completeRecord.accessType,
            i_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.i2c_master_huid,
            i_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.port,
            i_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.engine,
            i_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.devAddr,
            i_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.mux_select );
    }
    else if (i_eepromRecordHeader.completeRecord.accessType == EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_SPI)
    {
        TRACSSCOMP( g_trac_eeprom, "lookupEepromCacheAddr() accessType: 0x%02X = SPI -> master: 0x%.8X, engine: 0x%02X",
            i_eepromRecordHeader.completeRecord.accessType,
            i_eepromRecordHeader.completeRecord.eepromAccess.spiAccess.spi_master_huid,
            i_eepromRecordHeader.completeRecord.eepromAccess.spiAccess.engine );
    }

    l_it = g_cachedEeproms.find(i_eepromRecordHeader);

    if(l_it != g_cachedEeproms.end())
    {
        TRACSSCOMP( g_trac_eeprom, "lookupEepromCacheAddr() -> found %d valid at 0x%.8X cache_entry_address",
          l_it->first.completeRecord.cached_copy_valid, l_it->second.cache_entry_address);
        l_vaddr = l_it->second.cache_entry_address;
    }

    recursive_mutex_unlock(&g_eecacheMutex);

    return l_vaddr;
}


uint64_t lookupEepromHeaderAddr(const eepromRecordHeader& i_eepromRecordHeader)
{
    uint64_t l_vaddr = 0;
    std::map<eepromRecordHeader, EeepromEntryMetaData_t>::iterator l_it;

    // Wrap lookup in mutex because reads are not thread safe
    recursive_mutex_lock(&g_eecacheMutex);
    l_it = g_cachedEeproms.find(i_eepromRecordHeader);

    if(l_it != g_cachedEeproms.end())
    {
        l_vaddr = l_it->second.header_entry_address;
    }
    recursive_mutex_unlock(&g_eecacheMutex);

    if(l_vaddr == 0)
    {
        if ( i_eepromRecordHeader.completeRecord.accessType ==
             EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_I2C )
        {
            TRACFCOMP( g_trac_eeprom,
                "lookupEepromHeaderAddr() failed to find"
                " 0x%.02X access, I2CM Huid: 0x%.08X, Port: 0x%.02X,"
                " Engine: 0x%.02X, Dev Addr: 0x%.02X,"
                " Mux Select: 0x%.02X, Size: 0x%.08X"
                " in g_cachedEeproms",
                i_eepromRecordHeader.completeRecord.accessType,
                i_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.i2c_master_huid,
                i_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.port,
                i_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.engine,
                i_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.devAddr,
                i_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.mux_select,
                i_eepromRecordHeader.completeRecord.cache_copy_size );
        }
        else
        {
            TRACFCOMP( g_trac_eeprom,
                "lookupEepromHeaderAddr() failed to find"
                " 0x%.02X access, SPI master Huid: 0x%.08X, Engine: 0x%.02X,"
                " copy size: 0x%.08X in g_cachedEeproms",
                i_eepromRecordHeader.completeRecord.accessType,
                i_eepromRecordHeader.completeRecord.eepromAccess.spiAccess.spi_master_huid,
                i_eepromRecordHeader.completeRecord.eepromAccess.spiAccess.engine,
                i_eepromRecordHeader.completeRecord.cache_copy_size );
        }
    }
    return l_vaddr;
}

#ifndef CONFIG_SUPPORT_EEPROM_HWACCESS
errlHndl_t cacheEECACHEPartition()
{
    errlHndl_t l_errl = nullptr;
    do {
    l_errl = populateEecacheGlobals();
    if(l_errl)
    {
        break;
    }

    // A pointer to the top of EECACHE partition.
    eecacheSectionHeader* l_eecacheSectionHeader =
            reinterpret_cast<eecacheSectionHeader*>(g_eecachePnorVaddr);
    // The record header we want to push into the global eecache map
    eepromRecordHeader* l_pRecordHeader = nullptr;
    eepromRecordHeader l_recordToAdd {};

    for(uint8_t i = 0; i < MAX_EEPROMS_LATEST; ++i)
    {
        l_pRecordHeader = &l_eecacheSectionHeader->recordHeaders[i];
        if(l_pRecordHeader->completeRecord.internal_offset ==
           UNSET_INTERNAL_OFFSET_VALUE)
        {
            // This is a non-existing record, no need to populate the cache
            // with it
            continue;
        }

        memcpy(&l_recordToAdd, l_pRecordHeader, sizeof(l_recordToAdd));
        // Add the record to the global eecache
        if(!addEepromToCachedList(l_recordToAdd,
                                  reinterpret_cast<uint64_t>(l_pRecordHeader)))
        {
            TRACFBIN(g_trac_eeprom,
                     "cacheEECACHEPartition: added record to the cache",
                     l_pRecordHeader,
                     sizeof(*l_pRecordHeader));
        }
        else
        {
            TRACFBIN(g_trac_eeprom,
                     ERR_MRK"cacheEECACHEPartition: record already exists",
                     l_pRecordHeader,
                     sizeof(*l_pRecordHeader));
            assert(false,"cacheEECACHEPartition: Attempted to cache a duplicate"
                  " record. Ensure that cacheEECACHEPartition is called once "
                  "and no duplicate entries exist in EECACHE.");
        }
    }

    }while(0);
    return l_errl;
}
#endif


#if( defined(CONFIG_SUPPORT_EEPROM_CACHING) && !defined(CONFIG_SUPPORT_EEPROM_HWACCESS) )
errlHndl_t eecachePresenceDetect(TARGETING::Target* i_target,
                                 bool& o_present)
{
    errlHndl_t l_errl = nullptr;
    o_present = false;
    TRACSCOMP(g_trac_eeprom,"eecachePresenceDetect> Looking for %.8X", TARGETING::get_huid(i_target));

    do {
    // Build an eecache header record out of the provided target
    eeprom_addr_t l_eepromInfo;
    eepromRecordHeader l_eepromRecordHeader {};
    l_eepromInfo.eepromRole = EEPROM::VPD_PRIMARY;
    l_errl = buildEepromRecordHeader(i_target,
                                     l_eepromInfo,
                                     l_eepromRecordHeader);
    if(l_errl)
    {
        break;
    }
    TRACSSBIN(g_trac_eeprom,
              "Lookup",
              &l_eepromRecordHeader,
              sizeof(l_eepromRecordHeader));

    // Check if we have a valid record in our cache
    auto header = g_cachedEeproms.find(l_eepromRecordHeader);
    if( header != g_cachedEeproms.end() )
    {
        TRACSSBIN(g_trac_eeprom,
                  "Found",
                  &(header->first),
                  sizeof(eepromRecordHeader));
        if( header->first.completeRecord.cached_copy_valid )
        {
            o_present = true;
        }
    }

    TRACSCOMP(g_trac_eeprom,"eecachePresenceDetect> %.8X present=%d", TARGETING::get_huid(i_target), o_present);
    }while(0);

    return l_errl;
}
#endif


errlHndl_t isEepromInSync(TARGETING::Target * i_target,
                          const eepromRecordHeader& i_eepromRecordHeader,
                          EEPROM::EEPROM_ROLE i_eepromType,
                          bool & o_isInSync)
{
    errlHndl_t l_errl = nullptr;
    if (i_eepromRecordHeader.completeRecord.master_eeprom)
    {
        // Create namespace alias for targeting to reduce number of
        // new lines required to be within line character limit.
        namespace T = TARGETING;

        // If the existing eeprom record is valid, then only update
        // the contents if the SN/PN for current HW do not match the
        // eeprom record. (target must be present to cache)
        T::EEPROM_CONTENT_TYPE l_eepromContentType = T::EEPROM_CONTENT_TYPE_RAW;

        if (i_eepromType == EEPROM::VPD_PRIMARY)
        {
            if (i_eepromRecordHeader.completeRecord.accessType ==
                EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_I2C )
            {
                auto l_eepromVpd =
                    i_target->getAttr<T::ATTR_EEPROM_VPD_PRIMARY_INFO>();

                l_eepromContentType =
                    static_cast<T::EEPROM_CONTENT_TYPE>(
                            l_eepromVpd.eepromContentType);
            }
            else
            {
                auto l_spiEepromVpd =
                    i_target->getAttr<T::ATTR_SPI_MVPD_PRIMARY_INFO>();

                l_eepromContentType =
                    static_cast<T::EEPROM_CONTENT_TYPE>(
                            l_spiEepromVpd.eepromContentType);
            }
        }
        else if (i_eepromType == EEPROM::VPD_BACKUP)
        {
            if (i_eepromRecordHeader.completeRecord.accessType ==
                EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_I2C )
            {
                auto l_eepromVpd =
                   i_target->getAttr<T::ATTR_EEPROM_VPD_BACKUP_INFO>();

                l_eepromContentType =
                   static_cast<T::EEPROM_CONTENT_TYPE>(
                           l_eepromVpd.eepromContentType);
            }
            else
            {
                auto l_spiEepromVpd =
                    i_target->getAttr<T::ATTR_SPI_MVPD_BACKUP_INFO>();

                l_eepromContentType =
                    static_cast<T::EEPROM_CONTENT_TYPE>(
                            l_spiEepromVpd.eepromContentType);
            }
        }

        // Enable this once reading seeproms is supported
        l_errl = VPD::ensureEepromCacheIsInSync(i_target,
                                                l_eepromContentType,
                                                o_isInSync);
    }
    else
    {
        // Check if this matches master
        bool valid = false;
        bool changed = false;
        getMasterEepromCacheState(i_eepromRecordHeader, valid, changed);
        if ((changed != hasEeepromChanged(i_eepromRecordHeader)) ||
            (valid != i_eepromRecordHeader.completeRecord.cached_copy_valid))
        {
            TRACSSCOMP( g_trac_eeprom,
              "cacheEeprom() Eeprom w/ Role %d is not in sync."
              " Master role %d/%d vs current role %d/%d (valid/changed)",
              i_eepromType, valid, changed,
              i_eepromRecordHeader.completeRecord.cached_copy_valid,
              hasEeepromChanged(i_eepromRecordHeader) );
            o_isInSync = false;
        }
    }
    return l_errl;
}


bool eepromsMatch(eepromRecordHeader * i_eepromMasterRecord,
                  eepromRecordHeader * i_eepromCheckRecord)
{
    bool matchingEeproms = false;
    if ((i_eepromMasterRecord->completeRecord.accessType == EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_I2C) &&
        (i_eepromCheckRecord->completeRecord.accessType == EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_I2C))
    {
        if (i_eepromMasterRecord->uniqueRecord.uniqueID == i_eepromCheckRecord->uniqueRecord.uniqueID)
        {
            matchingEeproms = true;
        }
    }
    else if ((i_eepromMasterRecord->completeRecord.accessType == EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_SPI) &&
             (i_eepromCheckRecord->completeRecord.accessType == EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_SPI))
    {
        if ( (i_eepromMasterRecord->completeRecord.eepromAccess.spiAccess.spi_master_huid ==
              i_eepromCheckRecord->completeRecord.eepromAccess.spiAccess.spi_master_huid) &&
              (i_eepromMasterRecord->completeRecord.eepromAccess.spiAccess.engine ==
              i_eepromCheckRecord->completeRecord.eepromAccess.spiAccess.engine) )
        {
            // This will return both master and its associated ancillary records as matches
            matchingEeproms = true;
        }
    }
    return matchingEeproms;
}

errlHndl_t clearEecache(eecacheSectionHeader * i_eecacheSectionHeaderPtr,
                        eepromRecordHeader & i_eepromRecordHeader)
{
    errlHndl_t l_errl = nullptr;

    eepromRecordHeader * l_recordHeaderToUpdate = nullptr;
    for (uint8_t i = 0; i < MAX_EEPROMS_LATEST; i++)
    {
        // Keep track of current record
        l_recordHeaderToUpdate = &i_eecacheSectionHeaderPtr->recordHeaders[i];

        // If internal_offset is UNSET_INTERNAL_OFFSET_VALUE then we will assume this address not been filled
        if(l_recordHeaderToUpdate->completeRecord.internal_offset == UNSET_INTERNAL_OFFSET_VALUE)
        {
            // Now at end of filled-in cache entries
            break;
        }

        // Check for match to this eeprom and that it is currently valid
        if ( eepromsMatch(&i_eepromRecordHeader, l_recordHeaderToUpdate) &&
             l_recordHeaderToUpdate->completeRecord.cached_copy_valid )
        {
            if ( l_recordHeaderToUpdate->completeRecord.accessType ==
                   EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_I2C )
            {
                TRACFCOMP( g_trac_eeprom,
                          "clearEepromCache(): Eeprom i2cMaster 0x%.08X"
                          " Engine 0x%.02X Port 0x%.02X"
                          " MuxSelect 0x%.02X DevAddr 0x%.02X"
                          " is no longer present, so clearing cache"
                          " and marking cache as invalid",
                          l_recordHeaderToUpdate->completeRecord.eepromAccess.i2cAccess.i2c_master_huid,
                          l_recordHeaderToUpdate->completeRecord.eepromAccess.i2cAccess.engine,
                          l_recordHeaderToUpdate->completeRecord.eepromAccess.i2cAccess.port,
                          l_recordHeaderToUpdate->completeRecord.eepromAccess.i2cAccess.mux_select,
                          l_recordHeaderToUpdate->completeRecord.eepromAccess.i2cAccess.devAddr );
            }
            else
            {
                TRACFCOMP( g_trac_eeprom,
                           "clearEepromCache(): Eeprom spiMaster 0x%.08X"
                           " Engine 0x%.02X (offset: 0x%08X) no longer present,"
                           " so clearing cache and marking cache as invalid",
                           l_recordHeaderToUpdate->completeRecord.eepromAccess.spiAccess.spi_master_huid,
                           l_recordHeaderToUpdate->completeRecord.eepromAccess.spiAccess.engine,
                           l_recordHeaderToUpdate->completeRecord.eepromAccess.spiAccess.offset_KB );
            }

            // clear this eeprom's record content first
            void * l_internalSectionAddr =
                    reinterpret_cast<uint8_t *>(i_eecacheSectionHeaderPtr) +
                    l_recordHeaderToUpdate->completeRecord.internal_offset;

            memset( l_internalSectionAddr, 0xFF, (l_recordHeaderToUpdate->completeRecord.cache_copy_size * KILOBYTE));

            // Flush the cleared page to make sure it gets to the PNOR
            int rc = mm_remove_pages( FLUSH, l_internalSectionAddr, (l_recordHeaderToUpdate->completeRecord.cache_copy_size * KILOBYTE) );
            if( rc )
            {
                TRACFCOMP( g_trac_eeprom,ERR_MRK"clearEepromCache:  Error from mm_remove_pages trying for flush contents write (PNOR address %p, length %lld) to pnor! rc=%d",
                    l_internalSectionAddr, (l_recordHeaderToUpdate->completeRecord.cache_copy_size * KILOBYTE), rc );
                /*@
                * @errortype    ERRL_SEV_UNRECOVERABLE
                * @moduleid     EEPROM_CLEAR_EECACHE
                * @reasoncode   EEPROM_FAILED_TO_FLUSH_CONTENTS
                * @userdata1    Requested Address in PNOR
                * @userdata2    rc from mm_remove_pages
                * @devdesc      cacheEeprom mm_remove_pages FLUSH failed
                */
                l_errl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                EEPROM_CLEAR_EECACHE,
                                EEPROM_FAILED_TO_FLUSH_CONTENTS,
                                (uint64_t)l_internalSectionAddr,
                                TO_UINT64(rc),
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                break;
            }

            // Update the header so that it state the entry is invalid
            l_recordHeaderToUpdate->completeRecord.cached_copy_valid = 0;

            // Flush the page to make sure it gets to the PNOR
            rc = mm_remove_pages( FLUSH,
                                  l_recordHeaderToUpdate,
                                  sizeof(eepromRecordHeader) );
            if( rc )
            {
                TRACFCOMP(g_trac_eeprom,
                          ERR_MRK"clearEepromCache:  Error from mm_remove_pages trying for flush header write to pnor, rc=%d",rc);
                /*@
                * @errortype    ERRL_SEV_UNRECOVERABLE
                * @moduleid     EEPROM_CLEAR_EECACHE
                * @reasoncode   EEPROM_FAILED_TO_FLUSH_HEADER
                * @userdata1    Requested Address
                * @userdata2    rc from mm_remove_pages
                * @devdesc      clearEepromCache() header mm_remove_pages FLUSH failed
                */
                l_errl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                EEPROM_CLEAR_EECACHE,
                                EEPROM_FAILED_TO_FLUSH_HEADER,
                                (uint64_t)l_recordHeaderToUpdate,
                                TO_UINT64(rc),
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                break;
            }

            // Update record in g_cachedEeeproms() as changed
            // and set cache_entry_address to zero to prevent
            // access to invalid memory
            clearCachedEeprom(*l_recordHeaderToUpdate);
        }
    }

    return l_errl;
}


} // namespace EEPROM
