/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/eeprom/eepromCache.C $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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

/**
 * @file eepromCache.C
 * @brief Source file for code relating to caching eeproms in the EECACHE
 *        section of PNOR
 */

#include <builtins.h>
#include <memory>
#include <assert.h>
#include <stdarg.h>
#include <sys/mm.h>
#include <limits.h>

#include <devicefw/driverif.H>

#include <errl/errlmanager.H>

#include <fsi/fsiif.H>

#include <hwas/hwasPlat.H>

#include <i2c/i2cif.H>
#include <i2c/i2c.H>

#include "eepromCache.H"
#include <eeprom/eepromif.H>
#include <eeprom/eepromddreasoncodes.H>

#include <pldm/pldm_errl.H>

#include <pnor/pnorif.H>

#include <vpd/vpd_if.H>

#include <initservice/initserviceif.H>
#include <initservice/initsvcreasoncodes.H>
#include <initservice/taskargs.H>

#include <errl/errludtarget.H>
#include <console/consoleif.H>

#include <targeting/targplatutil.H>     // assertGetToplevelTarget

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
std::map<eepromRecordHeader, EepromEntryMetaData_t> g_cachedEeproms;

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

eecacheSectionHeader* getEecachePnorVaddr()
{
    return reinterpret_cast<eecacheSectionHeader*>(g_eecachePnorVaddr);
}

void eepromInit(errlHndl_t & io_rtaskReturnErrl)
{
    do {
    io_rtaskReturnErrl = populateEecacheGlobals();
    if (io_rtaskReturnErrl != nullptr)
    {
        TRACFCOMP(g_trac_eeprom, ERR_MRK"eepromInit(): "
                "An error occurred during initialization of libeeprom.so! "
                "Could not populate eecache globals!");
        break;
    }

    eecacheSectionHeader* l_eecacheSectionHeaderPtr = getEecachePnorVaddr();

    if(l_eecacheSectionHeaderPtr->version == EECACHE_VERSION_UNSET)
    {
        // If version == 0xFF then nothing has been cached before,
        // if nothing has been cached before then version should
        // be set to be the latest version of the struct available
        l_eecacheSectionHeaderPtr->version = EECACHE_VERSION_LATEST;
        TRACSSCOMP( g_trac_eeprom,
                "eepromInit() Found Empty Cache, set version of cache structure to be 0x%.02x",
                EECACHE_VERSION_LATEST);
    }
    else if(l_eecacheSectionHeaderPtr->version != EECACHE_VERSION_LATEST)
    {
        const auto original_version = l_eecacheSectionHeaderPtr->version;
        // In order to update to the latest EECACHE version we must invalidate
        // entire cache
        io_rtaskReturnErrl = PNOR::clearSection(PNOR::EECACHE);

        if (io_rtaskReturnErrl != nullptr)
        {
            TRACFCOMP(g_trac_eeprom, ERR_MRK"eepromInit(): "
                    "An error occurred during initialization of libeeprom.so! "
                    "Could not clear EECACHE when version mismatch detected!");
            break;
        }

        l_eecacheSectionHeaderPtr->version = EECACHE_VERSION_LATEST;
        /*@
          * @errortype   ERRORLOG::ERRL_SEV_PREDICTIVE
          * @moduleid    EEPROM_CACHE_INIT
          * @reasoncode  EEPROM_VERSION_UPDATED
          * @userdata1   Old Version of EECACHE
          * @userdata2   New Version of EEACHE
          * @devdesc     A new EECACHE layout found and Hostboot must rebuild EECACHE
          * @custdesc    Firmware detected we need to recollect hardware information
          */
        io_rtaskReturnErrl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_PREDICTIVE,
                EEPROM_CACHE_INIT,
                EEPROM_VERSION_UPDATED,
                original_version,
                EECACHE_VERSION_LATEST,
                ERRORLOG::ErrlEntry::NO_SW_CALLOUT);
        io_rtaskReturnErrl->collectTrace(EEPROM_COMP_NAME, 256);
        io_rtaskReturnErrl->addProcedureCallout(HWAS::EPUB_PRC_LVL_SUPP,
                                                HWAS::SRCI_PRIORITY_HIGH);
        errlCommit(io_rtaskReturnErrl, EEPROM_COMP_ID);

#ifdef CONFIG_CONSOLE
        CONSOLE::displayf(CONSOLE::DEFAULT,
                EEPROM_COMP_NAME,
                "New EECACHE layout version 0x%.02x detected, we have cleared EECACHE to recollect HW data.",
                EECACHE_VERSION_LATEST);
#endif
        TRACSSCOMP(g_trac_eeprom,
                "New EECACHE layout version 0x%.02x detected, we have cleared EECACHE to recollect HW data.",
                EECACHE_VERSION_LATEST);
    }

    if(l_eecacheSectionHeaderPtr->end_of_cache == UNSET_END_OF_CACHE_VALUE)
    {
        // If end_of_cache == 0xFFFFFFFF then we will assume the cache is empty.
        // In this case, we must set end_of_cache to be the end of the header.
        // This means the start of first eeprom's cached data will be immediately
        // following the end of the EECACHE header.
        l_eecacheSectionHeaderPtr->end_of_cache = sizeof(eecacheSectionHeader);
        TRACFCOMP( g_trac_eeprom,
                "eepromInit() Found Empty Cache, set end of cache to be 0x%.04x (End of ToC)",
                sizeof(eecacheSectionHeader));
    }

    } while(0);
}

/**
 * _start() task entry procedure using the macro found in taskargs.H
 */
TASK_ENTRY_MACRO( eepromInit );

/* @brief Calls a syscall to remove page(s). In this case, only writes dirty and
 *        write-tracked pages out to PNOR.
 *
 * @param[in] i_vaddr     The virtual address to FLUSH
 *
 * @param[in] i_size      The size of the data after i_vaddr to FLUSH
 *
 * @return    errlHndl_t  error log; Otherwise, nullptr.
 */
errlHndl_t flushToPnor(void * i_vaddr, uint64_t i_size)
{
    errlHndl_t l_errl = nullptr;

    int rc = mm_remove_pages(FLUSH, i_vaddr, i_size);
    if( rc )
    {
        TRACFCOMP(g_trac_eeprom,ERR_MRK"flushToPnor(): "
                "Error from mm_remove_pages trying for flush to pnor, rc=%d",
                rc);
        /*@
         * @errortype    ERRL_SEV_UNRECOVERABLE
         * @moduleid     EEPROM_FLUSH_TO_PNOR
         * @reasoncode   EEPROM_FAILED_TO_FLUSH_PAGE
         * @userdata1    Requested Address
         * @userdata2    rc from mm_remove_pages
         * @devdesc      flushToPnor mm_remove_pages FLUSH failed
         * @custdesc     Firmware detected a problem during the boot
         */
        l_errl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                EEPROM_FLUSH_TO_PNOR,
                EEPROM_FAILED_TO_FLUSH_PAGE,
                reinterpret_cast<uint64_t>(i_vaddr),
                TO_UINT64(rc),
                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
    }

    return l_errl;
}

/* @brief     Updates the eeprom cache entry's contents in PNOR. This only
 *            modifies the data after the header section in the EECACHE
 *            partition. This function assumes a completed record header has
 *            been given. That is to say that all fields have been filled in
 *            since buildEepromRecordHeader() doesn't do that automatically
 *            because fields like internal_offset and cached_copy_valid are
 *            determined based on what may or may not already exist in PNOR.
 */
errlHndl_t updateEecacheContents(TARGETING::Target*          i_target,
                                 EEPROM::EEPROM_ROLE const   i_eepromType,
                                 void        const * const   i_eepromBuffer,
                                 size_t              const   i_eepromBuflen,
                                 eepromRecordHeader  const & i_recordHeader,
                                 const bool                  i_newPart)
{
    TRACFCOMP(g_trac_eeprom, ENTER_MRK"updateEecacheContents(): "
              "updating cache entry for 0x%.8X target of type %d",
              get_huid(i_target), i_eepromType);

    errlHndl_t l_errl = nullptr;
    eecacheSectionHeader* l_eecacheSectionHeader = getEecachePnorVaddr();

    // Size of the eeprom contents.
    size_t  l_eepromLen = i_recordHeader.completeRecord.cache_copy_size
                        * KILOBYTE;

    // Skip the last 8 bytes of MVPD for Proc targets. MVPD borders Keystore,
    // and Keystore is read-protected on SPI engine 2. There is a HW bug where
    // we can't read the last byte leading up to the border of the Keystore
    // partition, so we need to read less than the full size of MVPD. We're
    // reading 8 bytes less because SPI reading logic rounds the sizes up to
    // 8 bytes.
    if((i_eepromType == EEPROM::VPD_PRIMARY || i_eepromType == EEPROM::VPD_AUTO)
       && i_target->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_PROC)
    {
        l_eepromLen = l_eepromLen - 8;
    }

    // Where in PNOR to write the eeprom contents.
    void * l_internalSectionAddr =
        reinterpret_cast<uint8_t *>(l_eecacheSectionHeader)
        + i_recordHeader.completeRecord.internal_offset;

    char* l_pathstring = nullptr;

    do {
        l_pathstring = i_target->getAttr<TARGETING::ATTR_PHYS_PATH>().toString();
        CONSOLE::displayf(CONSOLE::DEFAULT, NULL,"Detected new part : %.8X (%s)",
                          TARGETING::get_huid(i_target),
                          l_pathstring);

        if(i_eepromBuffer == nullptr)
        {
            // Buffer to read eeprom contents into.
            std::unique_ptr<uint8_t, decltype(&free)>l_tmpBuffer(
                    static_cast<uint8_t*>(malloc(l_eepromLen)),
                    free);

            TRACFCOMP(g_trac_eeprom, "updateEecacheContents(): "
                    "passing the following into deviceOp DEVICE_EEPROM_ADDRESS:"
                    " target with huid 0x%.08X; eeprom length 0x%.08X",
                    get_huid(i_target),
                    l_eepromLen);

            // Copy vpd contents to cache
            l_errl = deviceOp(DeviceFW::READ,
                    i_target,
                    l_tmpBuffer.get(),
                    l_eepromLen,
                    DEVICE_EEPROM_ADDRESS(i_eepromType, 0, EEPROM::HARDWARE));

            // If an error occurred during the eeprom read then break out.
            if( l_errl)
            {
                TRACFCOMP(g_trac_eeprom, ERR_MRK"updateEecacheContents(): "
                        "Error occured reading from EEPROM "
                        "type %d for HUID 0x%.08X!",
                        i_eepromType,
                        get_huid(i_target));
                break;
            }

            // Copy from tmp buffer into vaddr of internal section offset
            memcpy(l_internalSectionAddr, l_tmpBuffer.get(),  l_eepromLen);
        }
        else
        {
            TRACFCOMP(g_trac_eeprom,
                    "updateEecacheContents(): "
                    "copying from buffer : huid 0x%.08X "
                    " eeprom length 0x%.08X  eecache vaddr %p" ,
                    get_huid(i_target), i_eepromBuflen, l_internalSectionAddr);

            if (i_eepromBuflen > l_eepromLen)
            {
                TRACFCOMP(g_trac_eeprom, "updateEecacheContents(): eeprom buflen %d > eeprom length %d",
                       i_eepromBuflen,
                       l_eepromLen);
                /*@
                 * @errortype   ERRL_SEV_UNRECOVERABLE
                 * @moduleid    EEPROM_UPDATE_EECACHE_CONTENTS
                 * @reasoncode  EEPROM_UPDATE_BUFFER_MISMATCH
                 * @userdata1[0:31]  HUID of Master
                 * @userdata1[32:39] Port (or 0xFF)
                 * @userdata1[40:47] Engine
                 * @userdata1[48:55] devAddr    (or byte 0 offset_KB)
                 * @userdata1[56:63] mux_select (or byte 1 offset_KB)
                 * @userdata2[0:31]  i_eepromBuflen
                 * @userdata2[32:63] l_eepromLen
                 * @devdesc   Size of data in l_eepromLen is not matching requester
                 * @custdesc  Improper handling of Vital Product Data by boot firmware
                 */

                l_errl = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    EEPROM_UPDATE_EECACHE_CONTENTS,
                    EEPROM_UPDATE_BUFFER_MISMATCH,
                    getEepromHeaderUserData(i_recordHeader),
                    TWO_UINT32_TO_UINT64(TO_UINT32(i_eepromBuflen),
                                         TO_UINT32(l_eepromLen)),
                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                l_errl->collectTrace(EEPROM_COMP_NAME, 256);
                break;
            }

            // copy in the new buffer
            memcpy(l_internalSectionAddr, i_eepromBuffer ,  i_eepromBuflen);

            // clear out the remaining space in the cache entry
            memset((static_cast<uint8_t *>(l_internalSectionAddr)
                    + i_eepromBuflen),
                    0xFF,
                    l_eepromLen - i_eepromBuflen);
        }

        // Flush the page to make sure it gets to the PNOR
        l_errl = flushToPnor(l_internalSectionAddr, l_eepromLen);

        if(l_errl)
        {
            TRACFCOMP(g_trac_eeprom, ERR_MRK"updateEecacheContents(): Failed to flush write to PNOR");
            break;
        }

        // Set mark_target_changed and cached_copy_valid
        // Since we have copied stuff in the cache is valid, and been updated.
        // Even if this is a replacement ( cached_copy_valid was already 1) we
        // must set mark_target_changed so just always update the header
        if (i_newPart == EECACHE_NEW_PART)
        {
            setEepromChanged(i_recordHeader);

            if (i_recordHeader.completeRecord.master_eeprom)
            {
                // We have updated the cache entry, this indicates we have found a
                // "new" part. Mark the target as changed in hwas.
                HWAS::markTargetChanged(i_target);
            }
        }
    } while(0);

    free(l_pathstring);
    return l_errl;
}

/* @brief Looks up the given partial record header in the global map of cached
 *        eeproms to see if it is there already. This function will then take
 *        care of adding it if it's not. Otherwise, will mark the given target
 *        as changed if the corresponding eeprom has changed this IPL.
 *
 * @param[in]      i_target       The target associated with the partial record
 *                                header.
 *
 * @param[in]      i_eepromType   Describes which EEPROM associated to the
 *                                target that is being requested to be updated,
 *                                PRIMARY, BACKUP, etc.
 *
 * @param[in]      i_partialRecordHeader    The record header to update in the
 *                                          global map of cached eeproms.
 *
 * @param[in]      i_recordFromPnorToUpdate The corresponding record header from
 *                                          PNOR. The virtual address of which
 *                                          will be stored along side the
 *                                          partial record header.
 *
 * @return    bool      TRUE = given record header already exists in cache map
 *                      FALSE = given record header didn't already exist in
 *                              cache map but now added as a result of this
 *                              function's execution.
 */
bool updateCacheMap(TARGETING::Target  *       i_target,
              EEPROM::EEPROM_ROLE              i_eepromType,
              eepromRecordHeader const &       i_partialRecordHeader,
              eepromRecordHeader const * const i_recordFromPnorToUpdate)
{
    bool alreadyUpdated = false;

    // pass the record we have been building up (i_partialRecordHeader)
    // and the virtual address of this eeprom's record entry in the
    // EECACHE table of contents as a uint64.
    if(!addEepromToCachedList(i_partialRecordHeader,
                reinterpret_cast<uint64_t>(i_recordFromPnorToUpdate)))
    {
        TRACSSCOMP(g_trac_eeprom,
                "updateCacheMap() Eeprom w/ Role %d, HUID 0x%.08X added to the global map of cached eeproms",
                i_eepromType , TARGETING::get_huid(i_target));
    }
    else
    {
        // If this target's eeprom has already been cached in PNOR and our global map
        // indicates the cache entry was updated this boot, then we must also
        // mark this target associated with the cached eeprom as changed for hwas
        if( i_partialRecordHeader.completeRecord.master_eeprom
                && hasEepromChanged( i_partialRecordHeader ))
        {
            HWAS::markTargetChanged(i_target);
        }
        TRACSSCOMP(g_trac_eeprom,
                "updateCacheMap() Eeprom w/ Role %d, HUID 0x%.08X already in global map of cached eeproms",
                i_eepromType, TARGETING::get_huid(i_target));

        // Cache entry has already been updated via another target
        alreadyUpdated = true;
    }
    return alreadyUpdated;
}

/*
 * @brief Updates the eeprom record header in PNOR EECACHE.
 *
 * @param[in]      i_completeRecordHeader   The record header to copy into
 *                                          EECACHE. Must be a complete record.
 *                                          That means all fields must be filled
 *                                          not just what is filled by
 *                                          buildEepromRecordHeader().
 *
 * @param[in/out] io_recordFromPnorToUpdate A pointer to the place in PNOR where
 *                                          this record will be copied to.
 *
 * @return  errlHndl_t
 */
errlHndl_t updateEecacheHeader(
        eepromRecordHeader const & i_completeRecordHeader,
        eepromRecordHeader * const & io_pnorRecordToUpdate)
{
    errlHndl_t l_errl = nullptr;

    TRACSSCOMP(g_trac_eeprom, ENTER_MRK"updateEecacheHeader(): "
               "Copy record header to PNOR.");
    TRACSSBIN(g_trac_eeprom, "RECORD HEADER",
              &i_completeRecordHeader,
              sizeof(eepromRecordHeader));

    // Copy the local eepromRecord header struct with the info about the
    // new eeprom we want to add to the cache to the open slot we found
    memcpy(io_pnorRecordToUpdate,
            &i_completeRecordHeader,
            sizeof(eepromRecordHeader));

    l_errl = flushToPnor(io_pnorRecordToUpdate,
                         sizeof(eepromRecordHeader));
    if (l_errl)
    {
        TRACFCOMP(g_trac_eeprom, ERR_MRK"updateEecacheHeader(): Failed to flush write to PNOR");
    }

    return l_errl;
}

/*
 * @brief Creates a new eecache entry in PNOR EECACHE that didn't already exist.
 *
 * @param[in]   i_target          The target associated with the partial record
 *                                header.
 *
 * @param[in]   i_eepromType      Describes which EEPROM associated to the
 *                                target that is being requested to be updated,
 *                                PRIMARY, BACKUP, etc.
 *
 * @param[in]   i_updateContents  Determines if the eeprom contents should be
 *                                updated. For a new record, this is dependent
 *                                only on presence of the target.
 *                                Target Present == Update contents
 *                                Target NOT Present == Don't update contents.
 *
 * @param[in]   i_eepromBuffer    A buffer containing data to load into EECACHE
 *                                or nullptr. If nullptr, HW lookup for data
 *                                will be attempted.
 *
 * @param[in]   i_eepromBuflen    Length of i_eepromBuffer. If i_eepromBuffer is
 *                                nullptr then this should be 0.
 *
 * @param[in]   i_recordHeaderToAdd The record header to add to PNOR. If the
 *                                  internal_offset isn't set then it will be
 *                                  set to to the current end of cache.
 *
 * @param[in/out] io_recordHeaderFromPnor  A pointer to the place in PNOR the
 *                                         header to add will be copied to.
 *
 * @return  errlHndl_t
 */
errlHndl_t createNewEecacheEntry(TARGETING::Target  *   i_target,
                           EEPROM::EEPROM_ROLE          i_eepromType,
                           bool                 const   i_updateContents,
                           void         const * const   i_eepromBuffer,
                           size_t               const   i_eepromBuflen,
                           eepromRecordHeader   const & i_recordHeaderToAdd,
                           eepromRecordHeader * const & io_recordHeaderFromPnor)
{
    errlHndl_t errl = nullptr;
    do {
    if (io_recordHeaderFromPnor == nullptr)
    {
        /*@
         * @errortype   ERRL_SEV_UNRECOVERABLE
         * @moduleid    EEPROM_CREATE_NEW_EECACHE_ENTRY
         * @reasoncode  EEPROM_CREATE_PNOR_ENTRY_EMPTY
         * @userdata1[0:31]  HUID of Master
         * @userdata1[32:39] Port (or 0xFF)
         * @userdata1[40:47] Engine
         * @userdata1[48:55] devAddr    (or byte 0 offset_KB)
         * @userdata1[56:63] mux_select (or byte 1 offset_KB)
         * @userdata2[0:63]  size of buffer
         * @devdesc   Attempted to create a new eecache entry without a PNOR slot
         * @custdesc  Improper handling of Vital Product Data by boot firmware
         */

        errl = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            EEPROM_CREATE_NEW_EECACHE_ENTRY,
            EEPROM_CREATE_PNOR_ENTRY_EMPTY,
            getEepromHeaderUserData(i_recordHeaderToAdd),
            i_eepromBuflen,
            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        errl->collectTrace(EEPROM_COMP_NAME, 256);
        break;
    }

    // It's possible this record isn't complete. Create a local to update it.
    eepromRecordHeader l_recordHeaderToAdd = i_recordHeaderToAdd;
    {
        bool copyValid = l_recordHeaderToAdd.completeRecord.cached_copy_valid;

        // When creating a new eecache entry, the cached_copy_valid bit is
        // dependent on if the target is present or not. If the target is
        // present then the cached_copy_valid bit should be set since the entry
        // contents will be updated and therefor valid. Otherwise, the entry
        // contents will not be filled in and thus the cache will not be valid.

        if ( (!i_updateContents && (copyValid == true) ) ||
            (i_updateContents && (copyValid == false)) )
        {
            TRACFCOMP(g_trac_eeprom, "createNewEecacheEntry: Mismatch between cached_copy_valid %d "
                "and target presence %d.", copyValid, i_updateContents);
            /*@
             * @errortype   ERRL_SEV_UNRECOVERABLE
             * @moduleid    EEPROM_CREATE_NEW_EECACHE_ENTRY
             * @reasoncode  EEPROM_MISMATCH_TARGET_PRESENCE
             * @userdata1[0:31]  HUID of Master
             * @userdata1[32:39] Port (or 0xFF)
             * @userdata1[40:47] Engine
             * @userdata1[48:55] devAddr    (or byte 0 offset_KB)
             * @userdata1[56:63] mux_select (or byte 1 offset_KB)
             * @userdata2[0:31]  i_updateContents
             * @userdata2[32:63] copyValid
             * @devdesc   Mismatch between cached_copy_valid and target presence
             * @custdesc  Improper handling of Vital Product Data by boot firmware
             */

            errl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                EEPROM_CREATE_NEW_EECACHE_ENTRY,
                EEPROM_MISMATCH_TARGET_PRESENCE,
                getEepromHeaderUserData(l_recordHeaderToAdd),
                TWO_UINT32_TO_UINT64(TO_UINT32(i_updateContents),
                                     TO_UINT32(copyValid)),
                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            errl->collectTrace(EEPROM_COMP_NAME, 256);
            break;
        }
    }

    eecacheSectionHeader * l_eecacheSectionHeader = getEecachePnorVaddr();
    size_t  l_eepromLen = l_recordHeaderToAdd.completeRecord.cache_copy_size
                        * KILOBYTE;

    if ( (l_eecacheSectionHeader->end_of_cache + l_eepromLen) >= g_eecachePnorSize )
    {
        TRACFCOMP(g_trac_eeprom, "createNewEecacheEntry: Sum of system EEPROMs (%lld + %lld) "
            "is larger than space allocated (%lld) for EECACHE pnor section",
            l_eecacheSectionHeader->end_of_cache,
            l_eepromLen,
            g_eecachePnorSize);

            /*@
             * @errortype   ERRL_SEV_UNRECOVERABLE
             * @moduleid    EEPROM_CREATE_NEW_EECACHE_ENTRY
             * @reasoncode  EEPROM_EECACHE_OUT_OF_SPACE
             * @userdata1[0:31]  HUID of Master
             * @userdata1[32:39] Port (or 0xFF)
             * @userdata1[40:47] Engine
             * @userdata1[48:55] devAddr    (or byte 0 offset_KB)
             * @userdata1[56:63] mux_select (or byte 1 offset_KB)
             * @userdata2[0:63]  Size of EECACHE in PNOR
             * @devdesc   Out of space for adding to PNOR EECACHE
             * @custdesc  Improper handling of Vital Product Data by boot firmware
             */

            errl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                EEPROM_CREATE_NEW_EECACHE_ENTRY,
                EEPROM_EECACHE_OUT_OF_SPACE,
                getEepromHeaderUserData(l_recordHeaderToAdd),
                g_eecachePnorSize,
                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            errl->collectTrace(EEPROM_COMP_NAME, 256);
            break;
    }

    // When creating a new entry from scratch the data in i_recordHeaderToAdd
    // isn't (likely) complete because when a user calls buildEepromRecordHeader
    // it doesn't fill in internal_offset because there isn't enough data from
    // the parameters to that function to fill that in. The internal_offset
    // would need to be looked-up from the record in PNOR to get that
    // information.
    //
    // In this case (a new record not already in PNOR) we need to assign the
    // internal_offset to be the current end of cache. Since this function
    // stands alone we don't want to assume that the caller hasn't already done
    // that for us. So, here we are just making sure that internal_offset is set
    // correctly and that the current end of cache is updated.
    //
    // As a bonus we're also able to check if someone called this function
    // erroneously.
    if (l_recordHeaderToAdd.completeRecord.internal_offset
            == UNSET_INTERNAL_OFFSET_VALUE)
    {
        // Set this new eepromRecord's offset within the EECACHE PNOR section
        // to be the current "end of cache" offset in the toc.
        l_recordHeaderToAdd.completeRecord.internal_offset =
            l_eecacheSectionHeader->end_of_cache;
        l_eecacheSectionHeader->end_of_cache += l_eepromLen;
    }
    else if (l_recordHeaderToAdd.completeRecord.internal_offset
                == l_eecacheSectionHeader->end_of_cache)
    {
        // The caller already set the internal_offset to be end_of_cache so
        // only update where the end of the cache is.
        l_eecacheSectionHeader->end_of_cache += l_eepromLen;
    }
    else
    {
        // It is not clear this a new entry. updateCacheMap will determine
        // if it exists already and handle it.
    }

    bool alreadyUpdated = updateCacheMap(i_target,
                                         i_eepromType,
                                         l_recordHeaderToAdd,
                                         io_recordHeaderFromPnor);

    if (alreadyUpdated)
    {
        TRACFCOMP(g_trac_eeprom, "createNewEecacheEntry: "
           "Cache map indicates this entry already exists in EECACHE. "
           "Non-new entry was given to createNewEecacheEntry().");
        /*@
         * @errortype   ERRL_SEV_UNRECOVERABLE
         * @moduleid    EEPROM_CREATE_NEW_EECACHE_ENTRY
         * @reasoncode  EEPROM_DUP_EECACHE_UPDATE
         * @userdata1[0:31]  HUID of Master
         * @userdata1[32:39] Port (or 0xFF)
         * @userdata1[40:47] Engine
         * @userdata1[48:55] devAddr    (or byte 0 offset_KB)
         * @userdata1[56:63] mux_select (or byte 1 offset_KB)
         * @devdesc   Attempt to add an already existing EECACHE entry
         * @custdesc  Improper handling of Vital Product Data by boot firmware
         */

        errl = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            EEPROM_CREATE_NEW_EECACHE_ENTRY,
            EEPROM_DUP_EECACHE_UPDATE,
            getEepromHeaderUserData(l_recordHeaderToAdd),
            0,
            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        errl->collectTrace(EEPROM_COMP_NAME, 256);
        break;
    }

    // Set cached_copy_valid to 0 until the cache contents actually gets loaded
    io_recordHeaderFromPnor->completeRecord.cached_copy_valid = 0;

    if (i_updateContents)
    {
        errl = updateEecacheContents(i_target,
                                     i_eepromType,
                                     i_eepromBuffer,
                                     i_eepromBuflen,
                                     l_recordHeaderToAdd);
    }
    if (errl == nullptr)
    {
        // The contents of the cache were successfully updated (no error
        // occurred) or i_updateContents was false (i_target not present).
        // In either of those cases, update the header for this new entry.
        errl = updateEecacheHeader(l_recordHeaderToAdd,
                                   io_recordHeaderFromPnor);

    }

    } while (0);
    return errl;

}

/*
 * @brief Checks if an update to the EECACHE partition is necessary for the
 *        given pointer to an eeprom record header in PNOR.
 *
 * @param[in]   i_target          The target associated with the pointer to the
 *                                record header from PNOR.
 *
 * @param[in]   i_present         Describes whether or not target is present
 *
 * @param[in]   i_eepromType      Describes which EEPROM associated to the
 *                                target that is being requested to be updated,
 *                                PRIMARY, BACKUP, etc.
 *
 * @param[in]   i_eepromBuffer    A buffer containing data to load into EECACHE
 *                                or nullptr. If nullptr, HW lookup for data
 *                                will be attempted.
 *
 * @param[in]   i_eepromBuflen    Length of i_eepromBuffer. If i_eepromBuffer is
 *                                nullptr then this should be 0.
 *
 * @param[in]   i_recordFromPnor  A pointer to the place in PNOR the data
 *                                to be checked resides.
 *
 * @param[out]  o_updateContents  Determines if the eeprom contents should be
 *                                updated.
 *
 * @param[out]  o_updateHeader    Determines if the eeprom header should be
 *                                updated.
 *
 * @param[out]  o_isNewPart       Determines if the target to be marked changed
 *
 * @return  errlHndl_t
 */
errlHndl_t checkForEecacheEntryUpdate(
        TARGETING::Target  *         i_target,
        bool                 const   i_present,
        EEPROM::EEPROM_ROLE  const   i_eepromType,
        void         const * const   i_eepromBuffer,
        size_t               const   i_eepromBuflen,
        eepromRecordHeader * const & i_recordFromPnor,
        bool                       & o_updateContents,
        bool                       & o_updateHeader,
        bool                       & o_isNewPart)
{
    errlHndl_t l_errl = nullptr;

    o_updateContents = true;
    o_updateHeader = true;
    o_isNewPart = true;

    do {
    // Only check if the cache is in sync with HARDWARE if there is an
    // existing EECACHE section.
    if (i_recordFromPnor->completeRecord.cached_copy_valid)
    {
        // At this point we have found a match in the PNOR but we need
        // to decide what all needs an update.
        bool l_isInSync = false;
        if (i_present)
        {
            if(i_eepromBuffer == nullptr)
            {
                l_isInSync = true;
                l_errl = isEepromInSync(i_target, *i_recordFromPnor,
                                    i_eepromType, l_isInSync, o_isNewPart);
                if (l_errl != nullptr)
                {
                    break;
                }
            }
            else
            {
                auto l_eepromCacheAddr = lookupEepromCacheAddr(*i_recordFromPnor);

                // if we found a matching record header above this should never happen
                if (l_eepromCacheAddr == 0)
                {
                    TRACFCOMP(g_trac_eeprom, "checkForEecacheEntryUpdate(): unable to find cache address for *i_recordFromPnor");
                    /*@
                     * @errortype   ERRL_SEV_UNRECOVERABLE
                     * @moduleid    EEPROM_CHECK_EECACHE_UPDATE
                     * @reasoncode  EEPROM_UNEXPECTED_CACHE_ADDR
                     * @userdata1[0:31]  HUID of Master
                     * @userdata1[32:39] Port (or 0xFF)
                     * @userdata1[40:47] Engine
                     * @userdata1[48:55] devAddr    (or byte 0 offset_KB)
                     * @userdata1[56:63] mux_select (or byte 1 offset_KB)
                     * @userdata2[0:63]  i_eepromBuflen
                     * @devdesc   Unexpected cache address
                     * @custdesc  Improper handling of Vital Product Data by boot firmware
                     */

                    l_errl = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        EEPROM_CHECK_EECACHE_UPDATE,
                        EEPROM_UNEXPECTED_CACHE_ADDR,
                        getEepromHeaderUserData(*i_recordFromPnor),
                        i_eepromBuflen,
                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                    l_errl->collectTrace(EEPROM_COMP_NAME, 256);
                    break;
               }
               // if we were given a buffer do a memcmp
               // between the cached copy and the provided buffer
               if(memcmp(reinterpret_cast<void *>(l_eepromCacheAddr),
                         i_eepromBuffer,
                         i_eepromBuflen) == 0)
                  {
                    l_isInSync = true;
                  }
            }

            if(l_isInSync)
            {
                TRACFCOMP(g_trac_eeprom,"checkForEecacheEntryUpdate():"
                        " 0x%.8X target w/ %d eepromRole - eeprom is in-sync",
                        TARGETING::get_huid(i_target), i_eepromType);
                o_updateContents = false;
            }
            else
            {
                TRACFCOMP(g_trac_eeprom, "checkForEecacheEntryUpdate() - 0x%.8X target w/ %d eepromRole - eeprom is out of sync",
                        TARGETING::get_huid(i_target), i_eepromType);
            }
        }
        else
        {
            char* l_pathstring = i_target->getAttr<TARGETING::ATTR_PHYS_PATH>().toString();
            CONSOLE::displayf(CONSOLE::DEFAULT, NULL,"Detected part removal : %.8X (%s)",
                              TARGETING::get_huid(i_target),
                              l_pathstring);
            free(l_pathstring);

            // Clear out the contents of the cache for this eeprom if we have
            // detected that it was once valid--indicating it was present at one
            // time--and is now showing up as not present. We want to clear the
            // contents of cache so we can achieve the replug behavior where a
            // tester can remove the part, boot, then plug in the same part, and
            // boot again fresh.
            if ( i_recordFromPnor->completeRecord.accessType ==
                    EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_I2C )
            {
                TRACFCOMP(g_trac_eeprom, "Detected i2cMaster 0x%.08X"
                        " Engine 0x%.02X Port 0x%.02X"
                        " MuxSelect 0x%.02X DevAddr 0x%.02X"
                        " no longer present, clearing cache and marking "
                        "cache as invalid",
                        i_recordFromPnor->completeRecord.eepromAccess.i2cAccess.i2c_master_huid,
                        i_recordFromPnor->completeRecord.eepromAccess.i2cAccess.engine,
                        i_recordFromPnor->completeRecord.eepromAccess.i2cAccess.port,
                        i_recordFromPnor->completeRecord.eepromAccess.i2cAccess.mux_select,
                        i_recordFromPnor->completeRecord.eepromAccess.i2cAccess.devAddr );
            }
            else
            {
                TRACFCOMP(g_trac_eeprom, "Detected spiMaster 0x%.08X"
                        " Engine 0x%.02X no longer present, clearing"
                        " cache and marking cache as invalid",
                        i_recordFromPnor->completeRecord.eepromAccess.spiAccess.spi_master_huid,
                        i_recordFromPnor->completeRecord.eepromAccess.spiAccess.engine );
            }
            eecacheSectionHeader* l_eecacheSectionHeaderPtr = getEecachePnorVaddr();
            l_errl = clearEecache(l_eecacheSectionHeaderPtr, *i_recordFromPnor);
            // allow l_errl to be returned

            if (i_recordFromPnor->completeRecord.master_eeprom)
            {
                // We have cleared the cache entry, this indicates we have found
                // a part has been removed. Mark that the target is changed in
                // hwas.
                HWAS::markTargetChanged(i_target);
            }

            // PNOR contents already cleared by clearEecache()
            TRACFCOMP(g_trac_eeprom, "checkForEecacheEntryUpdate(): "
                    "0x%.8X target w/ %d eepromRole - eeprom contents "
                    "cleared",
                    TARGETING::get_huid(i_target), i_eepromType);
            o_updateContents = false;
        }

        // By this point, the PNOR header is accurate and does not need updating
        o_updateHeader = false;
    }
    else if(!i_present)
    {
        TRACFCOMP(g_trac_eeprom, "checkForEecacheEntryUpdate(): "
                "0x%.8X target w/ %d eepromRole - cache already invalid and "
                "target not present",
                TARGETING::get_huid(i_target), i_eepromType);

        // If the target is not present, then do not update contents or header
        o_updateContents = false;
        o_updateHeader = false;
    }
    // If there is a matching header entry in PNOR marked 'invalid'
    // but we now see the target as present, this indicates a replacement
    // part has been added where a part was removed
    else
    {
        if ( i_recordFromPnor->completeRecord.accessType ==
                EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_I2C )
        {
            TRACFCOMP(g_trac_eeprom, "checkForEecacheEntryUpdate(): "
                    "Detected replacement of a part i2cMaster 0x%.08X "
                    "Engine 0x%.02X Port 0x%.02X MuxSelect 0x%.02X "
                    "DevAddr 0x%.02X that was previously removed, we will "
                    "update the cache with new part's eeproms contents",
                    i_recordFromPnor->completeRecord.eepromAccess.i2cAccess.i2c_master_huid,
                    i_recordFromPnor->completeRecord.eepromAccess.i2cAccess.engine,
                    i_recordFromPnor->completeRecord.eepromAccess.i2cAccess.port,
                    i_recordFromPnor->completeRecord.eepromAccess.i2cAccess.mux_select,
                    i_recordFromPnor->completeRecord.eepromAccess.i2cAccess.devAddr);
        }
        else
        {
            TRACFCOMP(g_trac_eeprom, "checkForEecacheEntryUpdate(): "
                    "Detected replacement of a part spiMaster 0x%.08X "
                    "Engine 0x%.02X that was previously removed, "
                    "we will update the cache with new part's eeproms contents",
                    i_recordFromPnor->completeRecord.eepromAccess.spiAccess.spi_master_huid,
                    i_recordFromPnor->completeRecord.eepromAccess.spiAccess.engine);
        }
    }
    } while(0);

    return l_errl;
}

/*
 * @brief Updates the header and/or the contents of an eeprom record in the
 *        EECACHE partition if necessary.
 *
 * @param[in]   i_target          The target associated with partial record
 *                                header.
 *
 * @param[in]   i_present         Describes whether or not target is present
 *
 * @param[in]   i_eepromType      Describes which EEPROM associated to the
 *                                target that is being requested to be updated,
 *                                PRIMARY, BACKUP, etc.
 *
 * @param[in]   i_eepromBuffer    A buffer containing data to load into EECACHE
 *                                or nullptr. If nullptr, HW lookup for data
 *                                will be attempted.
 *
 * @param[in]   i_eepromBuflen    Length of i_eepromBuffer. If i_eepromBuffer is
 *                                nullptr then this should be 0.
 *
 * @param[in]   i_partialRecordHeader A record that has been constructed by
 *                                    calling buildEepromRecordHeader() and
 *                                    had its cached_copy_valid bit set. The
 *                                    internal_offset doesn't have to be set
 *                                    since that can be taken from
 *                                    io_recordFromPnorToUpdate
 *
 * @param[in/out] io_recordFromPnorToUpdate  A pointer to the header in PNOR
 *                                           which may need updating.
 *
 * @param[in]   i_normal_update  Flag to indicate if a forced update should
 *                               be performed, set to false to force the update
 *
 *
 * @return  errlHndl_t
 */
errlHndl_t updateExistingEecacheEntry(
        TARGETING::Target          * i_target,
        bool                 const   i_present,
        EEPROM::EEPROM_ROLE  const   i_eepromType,
        void         const * const   i_eepromBuffer,
        size_t               const   i_eepromBuflen,
        eepromRecordHeader   const & i_partialRecordHeader,
        eepromRecordHeader * const & io_recordFromPnorToUpdate,
        bool                 const   i_normal_update)
{
    errlHndl_t errl = nullptr;

    // Initially assume we will want to update both the entry in the header
    // as well as the contents in the body of the EECACHE section
    bool l_updateHeader = true;
    bool l_updateContents = true;
    bool l_isNewPart = true;

    do {
        // Make a local copy to ensure that internal_offset has been set.
        eepromRecordHeader l_completeRecordHeader = i_partialRecordHeader;

        // updateCacheMap() requires a complete record header in order to
        // update the global map. io_recordFromPnorToUpdate has the correct
        // internal_offset so assign that to the local before passing the
        // record header along.
        //
        // updateEecacheHeader() will need internal_offset to be correct too
        // so it can do a memcpy.
        l_completeRecordHeader.completeRecord.internal_offset =
            io_recordFromPnorToUpdate->completeRecord.internal_offset;

        bool alreadyUpdated = updateCacheMap(i_target,
                                             i_eepromType,
                                             l_completeRecordHeader,
                                             io_recordFromPnorToUpdate);
        if (alreadyUpdated)
        {
            // Force the update for EECACHE_VPD_NEEDS_REFRESH
            // i_normal_update will be set to false if we need to force the update
            if (i_normal_update)
            {
                break;
            }
        }

        // Check to see if an update is necessary to the header, contents, both,
        // or neither.
        errl = checkForEecacheEntryUpdate(i_target,
                                          i_present,
                                          i_eepromType,
                                          i_eepromBuffer,
                                          i_eepromBuflen,
                                          io_recordFromPnorToUpdate,
                                          l_updateContents,
                                          l_updateHeader,
                                          l_isNewPart);
        if (errl)
        {
            break;
        }

        if (l_updateContents)
        {
            errl = updateEecacheContents(i_target,
                                         i_eepromType,
                                         i_eepromBuffer,
                                         i_eepromBuflen,
                                         l_completeRecordHeader,
                                         l_isNewPart);
            if (errl)
            {
                break;
            }
        }
        if (l_updateHeader)
        {
            errl = updateEecacheHeader(l_completeRecordHeader,
                                       io_recordFromPnorToUpdate);
            if (errl)
            {
                break;
            }

        }

    } while(0);

    return errl;
}

/*
 * @brief Searches through the records in PNOR EECACHE to check for the
 *        existence of the search record in PNOR.
 */
errlHndl_t findEepromHeaderInPnorEecache(
        TARGETING::Target*         i_target,
        bool const                 i_present,
        EEPROM::EEPROM_ROLE const  i_eepromType,
        eepromRecordHeader const & i_searchRecordHeader,
        eepromRecordHeader      *& o_recordHeaderFromPnor)
{

    errlHndl_t l_errl = nullptr;
    do {
    if (o_recordHeaderFromPnor != nullptr)
    {
        /*@
         * @errortype   ERRL_SEV_UNRECOVERABLE
         * @moduleid    EEPROM_FIND_EEPROM_HEADER_IN_CACHE
         * @reasoncode  EEPROM_NEED_O_RECORD_PTR_EMPTY
         * @userdata1[0:31]  HUID of Master
         * @userdata1[32:39] Port (or 0xFF)
         * @userdata1[40:47] Engine
         * @userdata1[48:55] devAddr    (or byte 0 offset_KB)
         * @userdata1[56:63] mux_select (or byte 1 offset_KB)
         * @userdata2        Target HUID
         * @devdesc   Expecting nullptr for o_recordHeaderFromPnor
         * @custdesc  Improper handling of Vital Product Data by boot firmware
         */

        l_errl = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            EEPROM_FIND_EEPROM_HEADER_IN_CACHE,
            EEPROM_NEED_O_RECORD_PTR_EMPTY,
            getEepromHeaderUserData(i_searchRecordHeader),
            TO_UINT64(TARGETING::get_huid(i_target)),
            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(EEPROM_COMP_NAME, 256);
        break;
    }
    eecacheSectionHeader* l_eecacheSectionHeader = getEecachePnorVaddr();

    // Parse through PNOR section header to determine which of three cases we
    // are dealing with
    //      1. eeprom doesn't exist in cache and there is no room remaining.
    //      2. eeprom doesn't exist in cache and there is room in cache to add.
    //      3. eeprom already exists in cache and may need to be updated.
    // In the first case, a nullptr will be returned for the out parameter
    // signalling the caller that there is no space left which is an error.
    for(uint8_t i = 0; i < MAX_EEPROMS_LATEST; i++)
    {
        eepromRecordHeader* headerFromPnor =
            &l_eecacheSectionHeader->recordHeaders[i];

        // If internal_offset is UNSET_INTERNAL_OFFSET_VALUE then assume this
        // address not been filled yet.
        if(headerFromPnor->completeRecord.internal_offset
                == UNSET_INTERNAL_OFFSET_VALUE)
        {
            // Case 2: There is an open slot for the new cache entry. The caller
            // can verify that the same way that was done here and handle it.
            TRACFCOMP(g_trac_eeprom,
                    "findEepromHeaderInPnorEecache() - no eecache record in PNOR found for "
                    "%s %.8X target w/ eepromRole = %d -> empty slot %d",
                    i_present ? "present" : "non-present",
                    TARGETING::get_huid(i_target), i_eepromType, i);

            // Give back a pointer to the spot for the header
            o_recordHeaderFromPnor = headerFromPnor;
            break;
        }

        // Compare the eeprom record we are checking against the eeprom records
        // we are iterating through but ignore the last 9 bytes which have chip
        // size, the offset into this pnor section where the record exists, and
        // a byte that tells us if its valid or not.
        if( memcmp(headerFromPnor,
                   &i_searchRecordHeader,
                   NUM_BYTE_UNIQUE_ID ) == 0 )
        {
            // Case 3: We have matched with existing eeprom in the PNOR's
            // EECACHE section. This is not a new entry, caller can verify that.

            // The header from pnor will be returned.
            o_recordHeaderFromPnor = headerFromPnor;

            if( o_recordHeaderFromPnor->completeRecord.cache_copy_size !=
                    i_searchRecordHeader.completeRecord.cache_copy_size )
            {
                // A cache size mismatch indicates that a part size has changed,
                // caching algorithm cannot account for size changes. Invalidate
                // entire cache and TI to trigger re-ipl.
                l_errl = PNOR::clearSection(PNOR::EECACHE);

                // If there was an error clearing the cache commit it because we
                // are TIing.
                if(l_errl)
                {
                    errlCommit(l_errl, EEPROM_COMP_ID);
                }

                /*@
                 * @errortype    ERRORLOG::ERRL_SEV_PREDICTIVE
                 * @moduleid     EEPROM_FIND_EEPROM_HEADER_IN_CACHE
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
                        EEPROM_FIND_EEPROM_HEADER_IN_CACHE,
                        EEPROM_NEW_DEVICE_DETECTED,
                        TWO_UINT32_TO_UINT64(o_recordHeaderFromPnor->completeRecord.cache_copy_size ,
                            i_searchRecordHeader.completeRecord.cache_copy_size),
                        getEepromHeaderUserData(i_searchRecordHeader),
                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                l_errl->collectTrace(EEPROM_COMP_NAME, 256);
                // Since we should be TI'ing, commit to keep progressing
                errlCommit(l_errl, EEPROM_COMP_ID);

#ifdef CONFIG_CONSOLE
                CONSOLE::displayf(CONSOLE::DEFAULT, EEPROM_COMP_NAME,
                        "New EEPROM size detected for an existing part,"
                        "clearing EEPROM cache and performing reconfig loop");
#endif

                INITSERVICE::doShutdown(INITSERVICE::SHUTDOWN_DO_RECONFIG_LOOP);
            }

            TRACSSCOMP(g_trac_eeprom,
                    "findEepromHeaderInPnorEecache() already found copy for eeprom role %d "
                    "for target w/ HUID 0x%08X in EECACHE table of contents"
                    " at 0x%X internal address",
                    i_eepromType, TARGETING::get_huid(i_target),
                    o_recordHeaderFromPnor->completeRecord.internal_offset);
            break;
        }
    }

    // Case 1: eeprom doesn't exist in existing cache and there is no room to add it
    if (o_recordHeaderFromPnor == nullptr)
    {
        TRACFCOMP(g_trac_eeprom, "findEepromHeaderInPnorEecache(): Reached the max limit of %d records in PNOR EECACHE", MAX_EEPROMS_LATEST);
        bool l_do_reconfig = true;
        TARGETING::Target* sys = TARGETING::UTIL::assertGetToplevelTarget();
        if ( sys->getAttr<TARGETING::ATTR_EECACHE_DISABLE_AUTO_RESET>() )
        {
            l_do_reconfig = false;
            // Someone had to have overrode the default
            TRACFCOMP(g_trac_eeprom, "findEepromHeaderInPnorEecache(): ATTR_EECACHE_DISABLE_AUTO_RESET "
                " so will -NOT- be clearing PNOR EECACHE, someone did this intentionally, ERRL_SEV_PREDICTIVE");
        }
        else
        {
            // clear the EECACHE to recover
            TRACFCOMP(g_trac_eeprom, "findEepromHeaderInPnorEecache(): Starting recovery, clearing EECACHE");
            l_errl = PNOR::clearSection(PNOR::EECACHE);

            // If there was an error clearing the cache commit it because we
            // are TIing.
            if(l_errl)
            {
                errlCommit(l_errl, EEPROM_COMP_ID);
            }
        }
        /*@
         * @errortype    ERRORLOG::ERRL_SEV_PREDICTIVE
         * @moduleid     EEPROM_FIND_EEPROM_HEADER_IN_CACHE
         * @reasoncode   EEPROM_REACHED_MAX_CAPACITY
         * @userdata1[0:31]  HUID of Master
         * @userdata1[32:39] Port (or 0xFF)
         * @userdata1[40:47] Engine
         * @userdata1[48:55] devAddr    (or byte 0 offset_KB)
         * @userdata1[56:63] mux_select (or byte 1 offset_KB)
         * @userdata2[0:63]  Capcity is FULL at MAX_EEPROMS_LATEST
         * @devdesc     Max records allowable has been reached in PNOR EECACHE
         * @custdesc    Improper handling of Vital Product Data by boot firmware
         */
        l_errl = new ERRORLOG::ErrlEntry(
                 ERRORLOG::ERRL_SEV_PREDICTIVE,
                 EEPROM_FIND_EEPROM_HEADER_IN_CACHE,
                 EEPROM_REACHED_MAX_CAPACITY,
                 getEepromHeaderUserData(i_searchRecordHeader),
                 MAX_EEPROMS_LATEST,
                 ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(EEPROM_COMP_NAME, 256);
#ifdef CONFIG_CONSOLE
        CONSOLE::displayf(CONSOLE::DEFAULT, EEPROM_COMP_NAME,
                "Reached the MAX CAPACITY for allowable records "
                "in the PNOR EECACHE");
#endif
        if (l_do_reconfig)
        {
            TRACFCOMP(g_trac_eeprom, "findEepromHeaderInPnorEecache(): Performing RECONFIG LOOP to complete recovery from clearing PNOR EECACHE");
            // Since we should be TI'ing, commit to keep progressing
            errlCommit(l_errl, EEPROM_COMP_ID);
            INITSERVICE::doShutdown(INITSERVICE::SHUTDOWN_DO_RECONFIG_LOOP);
        }
    }

    } while(0);

    return l_errl;
}

/**
 * @brief Lookup I2C information for given eeprom, check if eeprom exists in cache.
 *        If it exists already determine if any updates are required. If it is not
 *        in the cache yet, add it to the cache.
 *
 * @param[in]   i_target       Presence detect target
 * @param[in]   i_present      Describes whether or not target is present
 *                             ( CANNOT RELY ON HWAS_STATE!! )
 * @param[in]   i_eepromType   Describes which EEPROM associated to the target
 *                             that is being requested to cache. (PRIMARY/BACKUP etc)
 * @param[in]   i_eepromBuffer Ptr to a buffer containing data to load into EECACHE
 *                             if nullptr, HW lookup for data will be attempted if
 *                             target is present.
 * @param[in]   i_eepromBuflen Length of i_eepromBuffer, if i_eepromBuffer is nullptr
 *                             then this should be 0
 *
 * @param[in]   i_normal_update Flag to indicate if a forced update should
 *                              be performed, set to false to force the update
 * @return  errlHndl_t
 */
errlHndl_t cacheEeprom(TARGETING::Target*        i_target,
                       bool                const i_present,
                       EEPROM::EEPROM_ROLE const i_eepromType,
                       void const * const        i_eepromBuffer,
                       size_t const              i_eepromBuflen,
                       bool                const i_normal_update)
{
    TRACSSCOMP(g_trac_eeprom, ENTER_MRK"cacheEeprom(): target HUID 0x%.08X, "
            "present %d, role %d",
            TARGETING::get_huid(i_target),
            i_present,
            i_eepromType);

    errlHndl_t l_errl = nullptr;

    EEPROM::eeprom_addr_t l_eepromInfo;

    // l_partialRecordHeader will be built up during the execution of this
    // function.
    eepromRecordHeader l_partialRecordHeader;

    do{
        // eepromReadAttributes keys off the eepromRole value
        // to determine what attribute to lookup to get eeprom info
        l_eepromInfo.eepromRole = i_eepromType;

        // if the target is present, then this record is valid
        if(i_present)
        {
            l_partialRecordHeader.completeRecord.cached_copy_valid = 1;
        }

        // buildEepromRecordHeader will call eepromReadAttributes to fill in
        // l_eepromInfo and will also fill in l_partialRecordHeader.
        l_errl = buildEepromRecordHeader(i_target,
                l_eepromInfo,
                l_partialRecordHeader);

        TRACDBIN(g_trac_eeprom, "cacheEeprom: l_partialRecordHeader currently",
                &l_partialRecordHeader,
                sizeof(eepromRecordHeader));

        if(l_errl)
        {
            // buildEepromRecordHeader should have traced any relavent
            // information if it was needed, just break out and pass the error
            // along.
            break;
        }

        size_t  l_eepromLen = l_partialRecordHeader.completeRecord
                                .cache_copy_size * KILOBYTE;
        if(i_eepromBuffer &&
           i_eepromBuflen > l_eepromLen )
        {
            TRACFCOMP(g_trac_eeprom,
                      "cacheEeprom(): "
                      "attempting to cache size 0x%.016x buffer on "
                      "target 0x%.8X w/ eepromRole = %d but eeprom is only "
                      "0x%.08x bytes",
                      i_eepromBuflen, TARGETING::get_huid(i_target),
                      i_eepromType, l_eepromLen);
            /*@
            * @errortype    ERRORLOG::ERRL_SEV_PREDICTIVE
            * @moduleid     EEPROM_CACHE_EEPROM
            * @reasoncode   EEPROM_INVALID_LENGTH
            * @userdata1[0:63]  Size of buffer
            * @userdata2[0:31]  HUID of Master
            * @userdata2[32:39] Port (or 0xFF)
            * @userdata2[40:47] Engine
            * @userdata2[48:55] devAddr    (or byte 0 of offset_KB)
            * @userdata2[56:63] mux_select (or byte 1 of offset_KB)
            * @devdesc     Attempting to overwrite eeprom cache with a
            *              buffer that is larger than the eeprom device
            *              itself
            * @custdesc    Improper handling of Vital Product Data by boot firmware
            */
            l_errl = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_PREDICTIVE,
                        EEPROM_CACHE_EEPROM,
                        EEPROM_INVALID_LENGTH,
                        i_eepromBuflen,
                        getEepromHeaderUserData(l_partialRecordHeader),
                        ERRORLOG::ErrlEntry::NO_SW_CALLOUT);
            l_errl->collectTrace(EEPROM_COMP_NAME, 256);

            PLDM::addBmcErrorCallouts(l_errl);
            break;
        }

        // The start of the EECACHE pnor section follows the order of the
        // eecacheSectionHeader struct that is defined in eeprom_const.H. This
        // should be laid out as follows
        //      * version
        //      * current end of the cache
        //      * a list of EEPROM entries that combines
        //          > huid of mux target
        //          > huid of master target
        //          > port of eeprom
        //          > devAddr of eeprom
        // The combination of data in an EEPROM entry creates a unqiue
        // identifier for a given eeprom.
        eepromRecordHeader * l_recordFromPnorToUpdate = nullptr;

        l_errl = findEepromHeaderInPnorEecache(i_target,
                                         i_present,
                                         i_eepromType,
                                         l_partialRecordHeader,
                                         l_recordFromPnorToUpdate);
        if (l_errl != nullptr)
        {
            break;
        }

        // Check what eepromRecordHeader was found in the EECACHE. Three cases:
        //   1. Eeprom doesn't exist in cache and there is no room remaining.
        //      NOTE: Taken care of in findEepromHeaderInPnorEecache().
        //   2. Eeprom doesn't exist in cache and there is room in cache to add.
        //   3. Eeprom already exists in cache and may need to be updated.
        if (l_recordFromPnorToUpdate->completeRecord.internal_offset
                == UNSET_INTERNAL_OFFSET_VALUE)
        {
            // Case 2
            TRACFCOMP(g_trac_eeprom,
                    "Case 2 cacheEeprom() - no eecache record in PNOR found for "
                    "%s %.8X target w/ eepromRole = %d, adding to empty slot",
                    i_present ? "present" : "non-present",
                    TARGETING::get_huid(i_target), i_eepromType);

            l_errl = createNewEecacheEntry(i_target,
                                           i_eepromType,
                                           i_present,
                                           i_eepromBuffer,
                                           i_eepromBuflen,
                                           l_partialRecordHeader,
                                           l_recordFromPnorToUpdate);
        }
        else
        {
            // Case 3: Record will only be updated if necessary.
            TRACSSCOMP(g_trac_eeprom,
                    "Case 3 cacheEeprom() - record in PNOR found for "
                    "%s HUID=0x%X eepromRole=%d, check for updates",
                    i_present ? "present" : "non-present",
                    TARGETING::get_huid(i_target), i_eepromType);
            l_errl = updateExistingEecacheEntry(i_target,
                                                i_present,
                                                i_eepromType,
                                                i_eepromBuffer,
                                                i_eepromBuflen,
                                                l_partialRecordHeader,
                                                l_recordFromPnorToUpdate,
                                                i_normal_update);
        }

    } while(0);

    TRACSSCOMP(g_trac_eeprom, EXIT_MRK"cacheEeprom(): Target HUID 0x%.08X, "
            "l_errl rc = 0x%02X",
            TARGETING::get_huid(i_target),
            ERRL_GETRC_SAFE(l_errl));

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
 * @param[in/out] io_buffer     Ptr to a buffer containing data to load into EECACHE
 *                              if nullptr, HW lookup for data will be attempted if
 *                              target is present.
 * @param[in/out] io_buflen     Length of io_buffer, if io_buffer is nullptr
 *                              then this should be 0
 * @param[in]   i_accessType    DeviceFW::AccessType enum (userif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, there are no arguments.
 * @return  errlHndl_t
 */
errlHndl_t genericEepromCache(DeviceFW::OperationType i_opType,
                              TARGETING::Target* i_target,
                              void* io_buffer,
                              size_t& io_buflen,
                              int64_t i_accessType,
                              va_list i_args)
{
    errlHndl_t l_errl = nullptr;
    bool l_normal_update = true; // flag to force an update, like EECACHE_VPD_STATE_VPD_NEEDS_REFRESH

    TRACSSCOMP( g_trac_eeprom, ENTER_MRK"genericI2CEepromCache() "
            "Target HUID 0x%.08X Enter", TARGETING::get_huid(i_target));

    do {

    // First param is a uint64_t representing if the target is present or not
    bool l_present = static_cast<bool>(va_arg(i_args,uint64_t));
    // second param is the type of EEPROM type we wish to cache
    // (PRIMARY vs BACKUP etc)
    EEPROM::EEPROM_ROLE l_eepromType =
        static_cast<EEPROM::EEPROM_ROLE>(va_arg(i_args,uint64_t));

    if(io_buffer &&
       io_buflen == 0)
    {
          TRACFCOMP(g_trac_eeprom,
                    ERR_MRK"genericEepromCache: We were told to cache an empty buffer at %p for 0x%.08X role %d  ",
                    io_buffer, TARGETING::get_huid(i_target), l_eepromType );
          /*@
          * @errortype    ERRORLOG::ERRL_SEV_PREDICTIVE
          * @moduleid     EEPROM_GENERIC_CACHE
          * @reasoncode   EEPROM_INVALID_LENGTH
          * @userdata1        Target HUID
          * @userdata2[0:31]  1 if target is present, 0 if not
          * @userdata2[32:63] EEPROM::EEPROM_ROLE
          * @devdesc      Attempting to cache empty buffer in EEACHE
          * @custdesc     Improper handling of Vital Product Data by boot firmware
          */
          l_errl = new ERRORLOG::ErrlEntry(
                          ERRORLOG::ERRL_SEV_PREDICTIVE,
                          EEPROM_GENERIC_CACHE,
                          EEPROM_INVALID_LENGTH,
                          TO_UINT64(TARGETING::get_huid(i_target)),
                          TWO_UINT32_TO_UINT64(TO_UINT32(l_present),
                                               TO_UINT32(l_eepromType)),
                          ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
          l_errl->collectTrace(EEPROM_COMP_NAME, 256);
          break;
    }

    // Run the cache eeprom function on the target passed in
    l_errl = cacheEeprom(i_target, l_present,  l_eepromType, io_buffer, io_buflen, l_normal_update);
    if(l_errl)
    {
        TRACFCOMP(g_trac_eeprom,
                  ERR_MRK"genericEepromCache:  An error occured while attempting to cache eeprom from buffer for 0x%.08X role %d",
                  TARGETING::get_huid(i_target), l_eepromType);
        break;
    }

    } while(0);

    TRACSSCOMP( g_trac_eeprom, EXIT_MRK"genericI2CEepromCache() "
            "Target HUID 0x%.08X EXIT, rc = %d", TARGETING::get_huid(i_target),
            ERRL_GETRC_SAFE(l_errl) );

    return l_errl;
}

DEVICE_REGISTER_ROUTE( DeviceFW::READ,
                       DeviceFW::EEPROM_CACHE,
                       TARGETING::TYPE_OCMB_CHIP,
                       genericEepromCache);

DEVICE_REGISTER_ROUTE( DeviceFW::READ,
                       DeviceFW::EEPROM_CACHE,
                       TARGETING::TYPE_PROC,
                       genericEepromCache );

DEVICE_REGISTER_ROUTE( DeviceFW::READ,
                       DeviceFW::EEPROM_CACHE,
                       TARGETING::TYPE_DIMM,
                       genericEepromCache );

DEVICE_REGISTER_ROUTE( DeviceFW::READ,
                       DeviceFW::EEPROM_CACHE,
                       TARGETING::TYPE_NODE,
                       genericEepromCache );

DEVICE_REGISTER_ROUTE( DeviceFW::READ,
                       DeviceFW::EEPROM_CACHE,
                       TARGETING::TYPE_TPM,
                       genericEepromCache );

errlHndl_t setIsValidCacheEntry(const TARGETING::Target * i_target,
                                const EEPROM_ROLE &i_eepromRole,
                                bool i_isValid)
{
    errlHndl_t l_errl = nullptr;
    eepromRecordHeader l_eepromRecordHeader;
    eeprom_addr_t l_eepromInfo;

    do{

        TRACSSCOMP( g_trac_eeprom, ENTER_MRK"setIsValidCacheEntry() "
                    "Target HUID 0x%.08X  Eeprom Role = %d  Enter",
                    TARGETING::get_huid(i_target), l_eepromInfo.eepromRole);

        l_eepromInfo.eepromRole = i_eepromRole;
        l_errl = buildEepromRecordHeader(const_cast<TARGETING::Target *>(i_target), l_eepromInfo, l_eepromRecordHeader);

        if(l_errl)
        {
            break;
        }

        l_errl = setIsValidCacheEntry(l_eepromRecordHeader, i_isValid);

    } while(0);

    return l_errl;
}

errlHndl_t setIsValidCacheEntry(const eepromRecordHeader& i_eepromRecordHeader, bool i_isValid)
{
    errlHndl_t l_errl = nullptr;
    eepromRecordHeader * l_eepromRecordHeaderToUpdate;

    do{

        TRACSSCOMP( g_trac_eeprom, ENTER_MRK"setIsValidCacheEntry(%d)", i_isValid);

        // Find the address of the header entry in the table of contents of the EECACHE pnor section
        l_eepromRecordHeaderToUpdate =
            reinterpret_cast<eepromRecordHeader *>(lookupEepromHeaderAddr(i_eepromRecordHeader));

        if(l_eepromRecordHeaderToUpdate == 0)
        {
              TRACFCOMP(g_trac_eeprom,
                        ERR_MRK"setIsValidCacheEntry:  Attempting to invalidate cache for an "
                        "eeprom but we could not find in global eecache map");

              /*@
              * @errortype    ERRL_SEV_UNRECOVERABLE
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
              * @errortype    ERRL_SEV_UNRECOVERABLE
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

        l_errl = flushToPnor(l_eepromRecordHeaderToUpdate,
                             sizeof(eepromRecordHeader));

        if(l_errl)
        {
            TRACFCOMP(g_trac_eeprom,
                      ERR_MRK"setIsValidCacheEntry:  Error trying to flush header write to pnor");
            break;
        }

    } while(0);

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


errlHndl_t getMasterEepromCacheState(TARGETING::Target * i_assocTarg, bool & o_valid,
                                     bool & o_changed)
{
    errlHndl_t l_errl = nullptr;

    o_valid = false;
    o_changed = false;

    // EECACHE record header for master eeprom record of i_assocTarg
    eepromRecordHeader l_masterEepromRecHead;
    eeprom_addr_t l_masterEepromInfo;
    l_masterEepromInfo.eepromRole = EEPROM::VPD_PRIMARY;

    // Build l_masterEepromRecHead, then search for it in g_cachedEeproms.
    // If a match is found, figure out if matched-record is valid and if it's changed.
    do
    {
        l_errl = buildEepromRecordHeader(i_assocTarg, l_masterEepromInfo, l_masterEepromRecHead);

        if (l_errl)
        {
            TRACSSCOMP( g_trac_eeprom, "getMasterEepromCacheState() unable to build master eeprom "
                "record header for target HUID: 0x%.08X", get_huid(i_assocTarg));
            break;
        }

        TRACSSBIN(g_trac_eeprom, "getMasterEepromCacheState: Looking for master eeprom",
                  &l_masterEepromRecHead, sizeof(l_masterEepromRecHead));

        // find master for this eeprom
        // Map accesses are not thread safe, make sure this is always wrapped in mutex
        recursive_mutex_lock(&g_eecacheMutex);
        for (const auto& cachedEeprom : g_cachedEeproms)
        {
            const eepromRecordHeader * pHeader = &cachedEeprom.first;
            if (eepromsMatch(&l_masterEepromRecHead, const_cast<eepromRecordHeader*>(pHeader)) &&
                (pHeader->completeRecord.master_eeprom == 1) )
            {
                // At this point pHeader points to the master eeprom in g_cachedEeproms
                // Use this header to find its equivalent in PNOR to check its validity
                eepromRecordHeader * l_pnorEepromHeader =
                    reinterpret_cast<eepromRecordHeader *>(lookupEepromHeaderAddr(*pHeader));
                if (l_pnorEepromHeader)
                {
                    o_valid = l_pnorEepromHeader->completeRecord.cached_copy_valid;
                }
                o_changed = cachedEeprom.second.mark_target_changed;
                break;
            }
        }
        recursive_mutex_unlock(&g_eecacheMutex);
    } while (0);

    return l_errl;
}


bool hasEepromChanged(const eepromRecordHeader & i_eepromRecordHeader)
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

void setEepromChanged(const eepromRecordHeader & i_eepromRecordHeader)
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
        // Update record in g_cachedEeproms() as changed
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
    std::map<eepromRecordHeader, EepromEntryMetaData_t>::iterator l_it;

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
    std::map<eepromRecordHeader, EepromEntryMetaData_t>::iterator l_it;

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

errlHndl_t refreshVPD()
{
    errlHndl_t l_errl = nullptr;
    bool l_present = true;
    void* l_buffer = nullptr;
    size_t l_buflen = 0;
    EEPROM::EEPROM_ROLE l_eepromType = EEPROM::VPD_PRIMARY;
    bool l_normal_update = false;

    do {

    TRACFCOMP(g_trac_eeprom, ENTER_MRK"refreshVPD()");

    for( TARGETING::TargetIterator target = TARGETING::targetService().begin();
         target != TARGETING::targetService().end();
         ++target )
    {
        TARGETING::ATTR_EECACHE_VPD_STATE_type vpd_state = TARGETING::EECACHE_VPD_STATE_VPD_GOOD;
        if (target->tryGetAttr<TARGETING::ATTR_EECACHE_VPD_STATE>(vpd_state))
        {
            if (vpd_state == TARGETING::EECACHE_VPD_STATE_VPD_NEEDS_REFRESH)
            {
                TRACFCOMP(g_trac_eeprom, "refreshVPD() FORCE update for HUID=0x%X for EECACHE_VPD_STATE_VPD_NEEDS_REFRESH",
                    get_huid(*target));
                l_errl = cacheEeprom(*target, l_present,  l_eepromType, l_buffer, l_buflen, l_normal_update);
                if (l_errl)
                {
                    // Trace the attempt but carry on, next full IPL should sync with PNOR EECACHE partition
                    TRACFCOMP(g_trac_eeprom, "refreshVPD() UNABLE to FORCE update for HUID=0x%X to cache eeprom for role %d",
                        get_huid(*target), l_eepromType);
                    // Commit the originating l_errl and make a new l_errl for further tracing
                    errlCommit(l_errl, EEPROM_COMP_ID);

                    /*@
                     * @errortype    ERRORLOG::ERRL_SEV_INFORMATIONAL
                     * @moduleid     EEPROM_GENERIC_CACHE
                     * @reasoncode   EEPROM_PNOR_CACHE_SYNC
                     * @userdata1        Target HUID
                     * @userdata2[0:31]  1 if target is present, 0 if not
                     * @userdata2[32:63] EEPROM::EEPROM_ROLE
                     * @devdesc      Unable to sync target with PNOR EECACHE
                     * @custdesc     An error occurred during the FW boot
                     */
                     l_errl = new ERRORLOG::ErrlEntry(
                          ERRORLOG::ERRL_SEV_INFORMATIONAL,
                          EEPROM_GENERIC_CACHE,
                          EEPROM_PNOR_CACHE_SYNC,
                          TO_UINT64(TARGETING::get_huid(*target)),
                          TWO_UINT32_TO_UINT64(TO_UINT32(l_present),
                                               TO_UINT32(l_eepromType)),
                          ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                     l_errl->collectTrace(EEPROM_COMP_NAME, 256);
                    // Commit l_errl next full IPL should sync with PNOR EECACHE partition
                    errlCommit(l_errl, EEPROM_COMP_ID);
                }
                else
                {
                    TRACFCOMP(g_trac_eeprom, "refreshVPD() UPDATED EECACHE_VPD_STATE for HUID=0x%X role %d",
                    get_huid(*target), l_eepromType);
                    // Set the EECACHE_VPD_STATE back to VPD_GOOD
                    target->setAttr<TARGETING::ATTR_EECACHE_VPD_STATE>(TARGETING::EECACHE_VPD_STATE_VPD_GOOD);
                }
            }
        }
    }

    }while(0);
    TRACFCOMP(g_trac_eeprom, EXIT_MRK"refreshVPD()");
    return l_errl;
}

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
                     ERR_MRK"cacheEECACHEPartition: Problem found while populating the global eecache from PNOR "
                     "and found a duplicate record for one that already exists (verify calling this once)",
                     l_pRecordHeader,
                     sizeof(*l_pRecordHeader));

            /*@
             * @errortype   ERRL_SEV_UNRECOVERABLE
             * @moduleid    EEPROM_CACHE_EECACHE_PARTITION
             * @reasoncode  EEPROM_CACHE_PNOR_DUP_FOUND
             * @userdata1[0:31]  HUID of Master
             * @userdata1[32:39] Port (or 0xFF)
             * @userdata1[40:47] Engine
             * @userdata1[48:55] devAddr    (or byte 0 offset_KB)
             * @userdata1[56:63] mux_select (or byte 1 offset_KB)
             * @devdesc   Attempted to add a duplicate entry from the PNOR to the global eecache
             * @custdesc  Improper handling of Vital Product Data by boot firmware
             */

            l_errl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                EEPROM_CACHE_EECACHE_PARTITION,
                EEPROM_CACHE_PNOR_DUP_FOUND,
                getEepromHeaderUserData(l_recordToAdd),
                0,
                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            l_errl->collectTrace(EEPROM_COMP_NAME, 256);
            break;
        }
    }

    // check if any EECACHE_VPD_STATE_VPD_NEEDS_REFRESH persisted, in case we need to force the sync
    l_errl = refreshVPD();
    if (l_errl)
    {
        break;
    }

    }while(0);
    return l_errl;
}


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
    } while(0);

    return l_errl;
}
#endif


errlHndl_t isEepromInSync(TARGETING::Target * i_target,
                          const eepromRecordHeader& i_eepromRecordHeader,
                          EEPROM::EEPROM_ROLE i_eepromType,
                          bool & o_isInSync,
                          bool & o_isNewPart)
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

        // Primary and backup MVPDs share the same EECACHE entry
        if (i_eepromType == EEPROM::VPD_PRIMARY
            || i_eepromType == EEPROM::VPD_BACKUP
            || i_eepromType == EEPROM::VPD_AUTO)
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

        l_errl = VPD::ensureEepromCacheIsInSync(i_target,
                                                l_eepromContentType,
                                                o_isInSync,
                                                o_isNewPart);
    }
    else
    {
        // Check if this matches master
        bool valid = false;
        bool changed = false;
        // For all eeproms that are not the master eeprom, the cache state of the associated
        // master eeprom is checked.
        l_errl = getMasterEepromCacheState(i_target, valid, changed);
        if (!l_errl)
        {
            if ((changed != hasEepromChanged(i_eepromRecordHeader)) ||
            (valid != i_eepromRecordHeader.completeRecord.cached_copy_valid))
            {
                TRACSSCOMP( g_trac_eeprom,
                  "isEepromInSync() Eeprom w/ Role %d is not in sync."
                  " Master role %d/%d vs current role %d/%d (valid/changed)",
                  i_eepromType, valid, changed,
                  i_eepromRecordHeader.completeRecord.cached_copy_valid,
                  hasEepromChanged(i_eepromRecordHeader) );
                o_isInSync = false;
            }
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
            l_errl = flushToPnor(l_internalSectionAddr,
                                (l_recordHeaderToUpdate->completeRecord.cache_copy_size * KILOBYTE));
            if(l_errl)
            {
                TRACFCOMP(g_trac_eeprom,
                          ERR_MRK"clearEepromCache(): "
                          "Error from mm_remove_pages trying for flush contents write (PNOR address %p, length %lld) to pnor!",
                          l_internalSectionAddr, (l_recordHeaderToUpdate->completeRecord.cache_copy_size * KILOBYTE));
                break;
            }

            // Update the header so that it state the entry is invalid
            l_recordHeaderToUpdate->completeRecord.cached_copy_valid = 0;

            // Flush the page to make sure it gets to the PNOR
            l_errl = flushToPnor(l_recordHeaderToUpdate,
                                  sizeof(eepromRecordHeader));
            if(l_errl)
            {
                TRACFCOMP(g_trac_eeprom,
                          ERR_MRK"clearEepromCache(): "
                          "Error from mm_remove_pages trying for flush header write to pnor");
                break;
            }

            // Update record in g_cachedEeproms() as changed
            // and set cache_entry_address to zero to prevent
            // access to invalid memory
            clearCachedEeprom(*l_recordHeaderToUpdate);
        }
    }

    return l_errl;
}


} // namespace EEPROM
