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
#include <devicefw/driverif.H>
#include "eepromdd.H"
#include <errl/errlmanager.H>
#include <fsi/fsiif.H>
#include "i2c.H"
#include <i2c/i2cif.H>
#include <i2c/eepromif.H>
#include <i2c/i2creasoncodes.H>
#include <i2c/eepromCache_const.H>
#include <initservice/initserviceif.H>
#include <initservice/initsvcreasoncodes.H>
#include <sys/mm.h>
#include <limits.h>
#include <pnor/pnorif.H>
#include <stdarg.h>
#include <vpd/vpd_if.H>

extern trace_desc_t* g_trac_i2c;

// #define TRACSSCOMP(args...)  TRACFCOMP(args)
#define TRACSSCOMP(args...)

namespace I2C
{

uint64_t g_eecachePnorVaddr;
uint64_t g_eecachePnorSize;

mutex_t g_eecacheMutex = MUTEX_INITIALIZER;

/**
 * @brief Write all 0xFFs to the EECACHE section in pnor to clear out the
 *        eeprom cache information.
 * @return  errlHndl_t
 */
errlHndl_t clearEEcache()
{
    errlHndl_t l_errl = nullptr;

    memset(reinterpret_cast<void *>(g_eecachePnorVaddr), 0xFF, g_eecachePnorSize);

    // Flush the page to make sure it gets to the PNOR
    int rc = mm_remove_pages( FLUSH, reinterpret_cast<void *>(g_eecachePnorVaddr), g_eecachePnorSize );


    if( rc )
    {
        TRACFCOMP(g_trac_i2c,ERR_MRK"cacheEeprom:  Error from mm_remove_pages trying for flush contents write to pnor! rc=%d",rc);
        /*@
        * @errortype
        * @moduleid     I2C_CLEAR_EECACHE
        * @reasoncode   I2C_FAILED_TO_FLUSH_CONTENTS
        * @userdata1    Requested Address
        * @userdata2    rc from mm_remove_pages
        * @devdesc      clearEEcache mm_remove_pages FLUSH failed
        */
        l_errl = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        I2C_CLEAR_EECACHE,
                        I2C_FAILED_TO_FLUSH_CONTENTS,
                        (uint64_t)g_eecachePnorVaddr,
                        TO_UINT64(rc),
                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

        l_errl->collectTrace(I2C_COMP_NAME);
    }
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
                       EEPROM::eeprom_chip_types_t i_eepromType)
{
    TRACSSCOMP( g_trac_i2c, "cacheEeprom() ENTER Target HUID 0x%.08X ", TARGETING::get_huid(i_target));
    errlHndl_t l_errl = nullptr;
    TARGETING::Target * l_muxTarget = nullptr;
    TARGETING::Target * l_i2cMasterTarget = nullptr;
    TARGETING::TargetService& l_targetService = TARGETING::targetService();

    EEPROM::eeprom_addr_t l_eepromInfo;
    eecacheSectionHeader * l_eecacheSectionHeaderPtr;

    // Initially assume we will want to update both the entry in the header
    // as well as the contents in the body of the EECACHE section
    bool l_updateHeader = true;
    bool l_updateContents = true;

    do{
        // eepromReadAttributes keys off the eepromRole value
        // to determine what attribute to lookup to get eeprom info
        l_eepromInfo.eepromRole = i_eepromType;

        l_errl = eepromReadAttributes(i_target, l_eepromInfo);
        if(l_errl)
        {
            TRACFCOMP( g_trac_i2c,
                      "cacheEeprom() error occured reading eeprom attributes for eepromType %d, target 0x%.08X, returning!!",
                      i_eepromType,
                      TARGETING::get_huid(i_target));
            l_errl->collectTrace(I2C_COMP_NAME);
            break;
        }

        // Grab the I2C mux target so we can read the HUID, if the target is NULL we will not be able
        // to lookup attribute to uniquely ID this eeprom so we will not cache it
        l_muxTarget = l_targetService.toTarget( l_eepromInfo.i2cMuxPath);
        if(l_muxTarget == nullptr)
        {
            TRACFCOMP( g_trac_i2c,
                      "cacheEeprom() Mux target associated with target 0x%.08X resolved to a nullptr , check attribute for eepromType %d. Skipping Cache",
                      TARGETING::get_huid(i_target),
                      i_eepromType);
            /*@
            * @errortype
            * @moduleid     I2C_CACHE_EEPROM
            * @reasoncode   I2C_MUX_TARGET_NOT_FOUND
            * @userdata1    HUID of target we want to cache
            * @userdata2[0:31]  Type of EEPROM we are caching
            * @userdata2[32:63] Boolean is target present or not
            * @devdesc      cacheEeprom invalid mux target
            */
            l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            I2C_CACHE_EEPROM,
                            I2C_MUX_TARGET_NOT_FOUND,
                            TARGETING::get_huid(i_target),
                            TWO_UINT32_TO_UINT64(i_eepromType, i_present),
                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            l_errl->collectTrace(I2C_COMP_NAME);
            break;
        }

        // Grab the I2C master target so we can read the HUID, if the target is NULL we will not be able
        // to lookup attribute to uniquely ID this eeprom so we will not cache it
        l_i2cMasterTarget = l_targetService.toTarget( l_eepromInfo.i2cMasterPath );
        if(l_i2cMasterTarget == nullptr)
        {
            TRACFCOMP( g_trac_i2c,
                      "cacheEeprom() I2C Master target associated with target 0x%.08X resolved to a nullptr , check attribute for eepromType %d. Skipping Cache ",
                      TARGETING::get_huid(i_target),
                      i_eepromType);
            /*@
            * @errortype
            * @moduleid     I2C_CACHE_EEPROM
            * @reasoncode   INVALID_MASTER_TARGET
            * @userdata1    HUID of target we want to cache
            * @userdata2[0:31]  Type of EEPROM we are caching
            * @userdata2[32:63] Boolean is target present or not
            * @devdesc      cacheEeprom invalid master target
            */
            l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            I2C_CACHE_EEPROM,
                            INVALID_MASTER_TARGET,
                            TARGETING::get_huid(i_target),
                            TWO_UINT32_TO_UINT64(i_eepromType, i_present),
                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            l_errl->collectTrace(I2C_COMP_NAME);
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
                TRACFCOMP( g_trac_i2c, "cacheEeprom() Failed while looking up the EECACHE section in PNOR!!");
                break;
            }

            mutex_lock(&g_eecacheMutex);
            g_eecachePnorVaddr = l_sectionInfo.vaddr;
            g_eecachePnorSize = l_sectionInfo.size;
            TRACFCOMP( g_trac_i2c, "cacheEeprom() vaddr for EECACHE start = 0x%lx , size = 0x%lx!!",
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
            TRACFCOMP( g_trac_i2c,
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
            TRACFCOMP( g_trac_i2c,
                       "cacheEeprom() Found Empty Cache, set end of cache to be 0x%.04x (End of ToC)",
                       sizeof(eecacheSectionHeader));
        }

        // This is what we will compare w/ when we are going through the existing
        // caches in the eeprom to see if we have already cached something
        // Or if no matches are found we will copy this into the header
        eepromRecordHeader l_eepromRecord = {l_i2cMasterTarget->getAttr<TARGETING::ATTR_HUID>(),
                                            (uint8_t)l_eepromInfo.port,
                                            (uint8_t)l_eepromInfo.engine,
                                            (uint8_t)l_eepromInfo.devAddr,
                                            l_muxTarget->getAttr<TARGETING::ATTR_HUID>(),
                                            l_eepromInfo.i2cMuxBusSelector,
                                            (uint8_t)l_eepromInfo.devSize_KB,
                                            0, // Default internal offset to be 0
                                            i_present};

        size_t l_eepromLen = l_eepromInfo.devSize_KB  * KILOBYTE;

        // Parse through PNOR section header to determine if a copy of this
        // eeprom already exists, or if we need to add it, and where we should add it
        // if we need to.
        eepromRecordHeader * l_recordHeaderToUpdate;

        // Initialize this to an INVALID value. This way we catch the case where
        // cache has 50 records and we cannot add anymore. In that case l_recordHeaderToUpdateIndex
        // would not get set in the loop below.
        uint8_t l_recordHeaderToUpdateIndex = INVALID_EEPROM_INDEX;

        for(uint8_t i = 0; i < MAX_EEPROMS_VERSION_1; i++)
        {
            // Keep track of current record so we can use outside for loop
            l_recordHeaderToUpdate = &l_eecacheSectionHeaderPtr->recordHeaders[i];

            // If internal_offset is non-zero then we will assume this address has been filled
            if(l_recordHeaderToUpdate->internal_offset != UNSET_INTERNAL_OFFSET_VALUE)
            {
                // Compare the eeprom record we are checking against the eeprom records we are iterating through
                // but ignore the last 9 bytes which have chip size, the offset into this pnor section where the
                // record exists, and a byte that tells us if its valid or not
                if( memcmp(l_recordHeaderToUpdate, &l_eepromRecord, RECORD_COMPARE_SIZE ) == 0 )
                {
                    l_recordHeaderToUpdateIndex = i;
                    if( l_recordHeaderToUpdate->record_size != l_eepromRecord.record_size)
                    {
                        // This indicates that a part size has changed , caching
                        // algorithm cannot account for size changes.
                        // Invalidate entire cache and TI to trigger re-ipl
                        l_errl = clearEEcache();

                        // If there was an error clearing the cache commit is because we are TIing
                        if(l_errl)
                        {
                            errlCommit(l_errl, I2C_COMP_ID);
                        }

                        INITSERVICE::doShutdown(INITSERVICE::SHUTDOWN_DO_RECONFIG_LOOP);
                    }

                    if(l_recordHeaderToUpdate->record_valid)
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

                    TRACSSCOMP( g_trac_i2c, "cacheEeprom() already found copy for eeprom role %d for target w/ HUID 0x.%08X",
                              i_eepromType , TARGETING::get_huid(i_target));
                    break;
                }
            }
            else
            {
                assert((l_eecacheSectionHeaderPtr->end_of_cache + l_eepromLen) < g_eecachePnorSize,
                        "Sum of system EEPROMs is larger than space allocated for EECACHE pnor section");

                l_recordHeaderToUpdateIndex = i;
                // Set this new eepromRecord's offset within the EECACHE PNOR section
                // to be the current "end of cache" offset in the toc.
                l_eepromRecord.internal_offset = l_eecacheSectionHeaderPtr->end_of_cache;
                l_eecacheSectionHeaderPtr->end_of_cache += l_eepromLen;
                l_updateContents = i_present;
                break;
            }
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
                reinterpret_cast<uint8_t *>(l_eecacheSectionHeaderPtr) + l_eepromRecord.internal_offset;

            TRACSSCOMP( g_trac_i2c, "cacheEeprom() passing the following into deviceOp eeprom address : huid 0x%.08X   length 0x%.08X" ,
                        get_huid(i_target), l_eepromLen);

            // Copy vpd contents to cache
            l_errl = deviceOp(DeviceFW::READ,
                              i_target,
                              l_tmpBuffer,
                              l_eepromLen,
                              DEVICE_EEPROM_ADDRESS(i_eepromType, 0));

            // If an error occurred during the eeprom read then free the tmp buffer and break out
            if( l_errl)
            {
                TRACFCOMP(g_trac_i2c,ERR_MRK"cacheEeprom:  Error occured reading from EEPROM type %d for HUID 0x%.08X!",
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
                TRACFCOMP(g_trac_i2c,ERR_MRK"cacheEeprom:  Error from mm_remove_pages trying for flush contents write to pnor! rc=%d",rc);
                /*@
                * @errortype
                * @moduleid     I2C_CACHE_EEPROM
                * @reasoncode   I2C_FAILED_TO_FLUSH_CONTENTS
                * @userdata1    Requested Address
                * @userdata2    rc from mm_remove_pages
                * @devdesc      cacheEeprom mm_remove_pages FLUSH failed
                */
                l_errl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                I2C_CACHE_EEPROM,
                                I2C_FAILED_TO_FLUSH_CONTENTS,
                                (uint64_t)l_internalSectionAddr,
                                TO_UINT64(rc),
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            }
            else
            {
                TRACSSCOMP( g_trac_i2c, "cacheEeprom() %.08X bytes of eeprom data related to %.08X have been written to %p" ,
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
            // Copy the local eepromRecord header struct with the info about the
            // new eeprom we want to add to the cache to the open slot we found
            memcpy(l_recordHeaderToUpdate , &l_eepromRecord, sizeof(eepromRecordHeader));

            // Flush the page to make sure it gets to the PNOR
            int rc = mm_remove_pages( FLUSH, l_recordHeaderToUpdate, sizeof(eepromRecordHeader) );
            if( rc )
            {
                TRACFCOMP(g_trac_i2c,ERR_MRK"cacheEeprom:  Error from mm_remove_pages trying for flush header write to pnor, rc=%d",rc);
                /*@
                * @errortype
                * @moduleid     I2C_CACHE_EEPROM
                * @reasoncode   I2C_FAILED_TO_FLUSH_HEADER
                * @userdata1    Requested Address
                * @userdata2    rc from mm_remove_pages
                * @devdesc      cacheEeprom mm_remove_pages FLUSH failed
                */
                l_errl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                I2C_CACHE_EEPROM,
                                I2C_FAILED_TO_FLUSH_HEADER,
                                (uint64_t)l_recordHeaderToUpdate,
                                TO_UINT64(rc),
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                break;
            }
        }

        TRACDBIN( g_trac_i2c, "cacheEeprom: l_eecacheSectionHeaderPtr currently ",
            l_eecacheSectionHeaderPtr,
            sizeof(eecacheSectionHeader));
    }while(0);

    TRACSSCOMP( g_trac_i2c, "cacheEeprom() EXIT Target HUID 0x%.08X ", TARGETING::get_huid(i_target));

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
    EEPROM::eeprom_chip_types_t l_eepromType = (EEPROM::eeprom_chip_types_t)va_arg(i_args,uint64_t);

    TRACSSCOMP( g_trac_i2c, ENTER_MRK"genericI2CEepromCache() "
            "Target HUID 0x%.08X Enter", TARGETING::get_huid(i_target));

    do{
        // Run the cache eerpom function on the target passed in
        l_errl = cacheEeprom(i_target, l_present,  l_eepromType);
        if(l_errl)
        {
            TRACFCOMP(g_trac_i2c,
                      ERR_MRK"cacheEeprom:  An error occured while attempting to cache eeprom for 0x%.08X",
                      TARGETING::get_huid(i_target));
            break;
        }

    }while(0);

    TRACSSCOMP( g_trac_i2c, EXIT_MRK"genericI2CEepromCache() "
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

}