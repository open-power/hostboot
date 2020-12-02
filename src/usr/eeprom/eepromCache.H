/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/eeprom/eepromCache.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
#ifndef __EEPROM_CACHE_H
#define __EEPROM_CACHE_H

#include <eeprom/eeprom_const.H>
#include <errl/errlentry.H>

namespace EEPROM
{

/**
*
* @brief Perform a read or write operation on an eeprom record inside EEACHE
*
*
* @param[in] i_opType - Operation Type - See DeviceFW::OperationType in
*       driververif.H
*
* @param[in] i_target - Target device associated w/ the EEPROM.
*
* @param[in/out] io_buffer
*       INPUT: Pointer to the data that will be  written to the target
*           device.
*       OUTPUT: Pointer to the data that was read from the target device.
*
* @param[in] io_buflen
*       INPUT: Length of the buffer to be written to target device or
*       length of buffer to be read from target device.
*       Output: If io_buffer is passed in as nullptr size will be set in
*               io_buflen as an out param
*
* @param [in] i_eepromInfo struct containing information needed to perform
*        operation on the given i2c eeprom. NOTE It is expected that
*        eepromRole and offset have been filled out in this struct
*        prior to passing it into this function
*
* @return errlHndl_t - nullptr if successful, otherwise a pointer to the
*       error log.
*
*/
errlHndl_t eepromPerformOpCache(DeviceFW::OperationType i_opType,
                                TARGETING::Target * i_target,
                                void * io_buffer,
                                size_t & io_buflen,
                                eeprom_addr_t i_eepromInfo);

/**
*
* @brief Build up a struct that is used to compare cached eeprom entries
*        in the EECACHE section. Each eeprom will get an entry in the
*        eepromRecordHeader order in the EECACHE section header
*
* @param[in] i_target - Target device associated w/ the EEPROM.
*
* @param [in/out] io_eepromInfo struct containing information needed to perform
*        operation on the given i2c eeprom. NOTE It is expected that
*        eepromRole has been filled out in this struct prior to passing
*        it into this function
* @param [out] o_eepromRecordHeader struct that will be populated with infromation
*        that can be used to determine if the eeprom has been cached yet or not,
*        or for looking up an eeprom we want to write to/ read from.
*
* @pre  It is expected that io_i2cInfo.eepromRole will have a valid role set
*
* @post After function o_eepromRecordHeader will be filled in with information
*       found while looking up the eeprom info from the target's attributes.
*       o_eepromRecordHeader can be used to see if a cached copy exists
*
* @return errlHndl_t - nullptr if successful, otherwise a pointer to the
*       error log.
*
*/
errlHndl_t buildEepromRecordHeader(TARGETING::Target * i_target,
                                    eeprom_addr_t & io_eepromInfo,
                                    eepromRecordHeader & o_eepromRecordHeader);

/**
 *
 * @brief Check whether the given record header is present in the global
 *        EEPROM cache map.
 * @param[in] i_eepromRecordHeader - the record to be found in the map
 *
 * @return bool whether the record exists in the global EEPROM cache map
 */
bool isEepromRecordPresent(const eepromRecordHeader& i_eepromRecordHeader);

/**
 * @brief Pre-populates the global eecache map with the contents of the
 *        EECACHE PNOR partition
 *
 * @return nullptr on success; non-nullptr on error
 */
errlHndl_t cacheEECACHEPartition();

#ifndef __HOSTBOOT_RUNTIME

/**
*
* @brief Check if entry already exists in g_cachedEeproms, if a match is
*        found then return true. If there is no match, add it to the list
*        and return false;
*
* @param[in] i_eepromRecordHeader Header for record we want to add to map
*
* @param[in] i_recordHeaderVaddr Virtual address to PNOR copy of header information
*
* @return TRUE if entry is already in map FALSE if this is a new entry
*
*/
bool addEepromToCachedList(const eepromRecordHeader & i_eepromRecordHeader,
                           const uint64_t i_recordHeaderVaddr);

/**
*
* @brief Perform a lookup on the global map g_cachedEeproms to get a
*        virtual address for a given EEPROM entry in the EECACHE table of contents
*
* @param[in] i_eepromRecordHeader
*
* @pre  It is expected that i_eepromRecordHeader has valid information for
*       the uniqueID (i2cm_huid, port, engine, devAddr, mux_select)
*
* @return uint64_t virtual address pointing to the cached eeprom data in pnor
*
*/
uint64_t lookupEepromHeaderAddr(const eepromRecordHeader& i_eepromRecordHeader);

/**
*
* @brief Perform a lookup on the global map g_cachedEeproms to get a
*        virtual address for a given EEPROM cache entry
*
* @param[in] i_eepromRecordHeader
*
* @pre  It is expected that i_eepromRecordHeader has valid information for
*       the uniqueID (i2cm_huid, port, engine, devAddr, mux_select)
*
* @return uint64_t virtual address pointing to the cached eeprom data in pnor
*
*/
uint64_t lookupEepromCacheAddr(const eepromRecordHeader& i_eepromRecordHeader);


/**
*
* @brief Print the info found in the Table of Contents of the EECACHE
*        section of pnor to trace buffer
*
* @param[in] i_only_valid_entries - just print the valid entries
*
* @return void
*
*/
void printTableOfContentsFromPnor(bool i_only_valid_entries = false);


/**
*
* @brief Print the global map table of contents section to trace buffer
*
* @param[in] i_only_valid_entries - just print the valid entries
*
* @return void
*
*/
void printTableOfContentsFromGlobalMemory(bool i_only_valid_entries = false);

/**
*
* @brief Update the record entry in the Table of Contents of the EECACHE
*        section of pnor to either mark the contents of the cache to be
*        valid or invalid
*
* @param[in] i_target     Target associated with EEPROM
*
* @param[in] i_eepromRole Role of EEPROM associated with target (VPD_PRIMARY etc)
*
* @param[in] i_isValid    Mark eeprom cache valid or invalid ?
*
* @return errlHndl_t - nullptr if successful, otherwise a pointer to the
*       error log.
*
*/
errlHndl_t setIsValidCacheEntry(const TARGETING::Target * i_target,
                                const EEPROM_ROLE &i_eepromRole,
                                bool i_isValid);

/**
*
* @brief Update the record entry in the Table of Contents of the EECACHE
*        section of pnor to either mark the contents of the cache to be
*        valid or invalid
*
* @param[in] i_eepromRecordHeader eepromRecord oject already filled in (including eepromRole)
*
* @param[in] i_isValid    Mark eeprom cache valid or invalid ?
*
* @return errlHndl_t - nullptr if successful, otherwise a pointer to the
*       error log.
*
*/
errlHndl_t setIsValidCacheEntry(const eepromRecordHeader& i_eepromRecordHeader, bool i_isValid);

/**
*
* @brief Lookup a given i_eepromRecordHeader in the global map of eeprom
*        caches and check if the eeprom has changed this IPL or not
*
* @param[in] i_eepromRecordHeader we want to look up
*
* @return bool Return TRUE if eeprom is found in map AND mark_target_changed
               was set to true for the eeprom entry. Return FALSE otherwise.
*
*/
bool hasEepromChanged(const eepromRecordHeader & i_eepromRecordHeader);

/**
*
* @brief Lookup a given i_eepromRecordHeader in the global map of eeprom
*        caches and mark that it has changed this IPL
*
* @param[in] i_eepromRecordHeader we want to mark as changed
*
* @return void
*/
void setEepromChanged(const eepromRecordHeader & i_eepromRecordHeader);


/**
 * @brief Checks if eeprom is in sync with hw based on vpd
 *        or matching master role eeprom
 * @param[in] - target checking
 * @param[in] - eeprom record to check
 * @param[in] - eeprom role
 * @param[out] - true if record is in-sync, else false
 * @return  error log if failure found
 */
errlHndl_t isEepromInSync(TARGETING::Target * i_target,
                          const eepromRecordHeader& i_eepromRecordHeader,
                          EEPROM::EEPROM_ROLE i_eepromType,
                          bool & o_isInSync);

/**
 * @brief Compares the two headers to see if they are on the same eeprom
 *        This will match master and ancillary eeproms
 *        since they are for same physical eeprom
 * @param[in] - i_eepromMasterRecord - this record's eeprom must be matched
 * @param[in] - i_eepromCheckRecord - check this eeprom against master one
 * @return true if records are for same eeprom, else false
 */
bool eepromsMatch(eepromRecordHeader * i_eepromMasterRecord,
                  eepromRecordHeader * i_eepromCheckRecord);

/**
 * @brief Clears all cache records pertaining to the physical eeprom.
 *        It will walk the PNOR records and clear out all
 *        sections (master & ancillary) with matching eeprom.
 *        Writes 0xFF to content data and sets each matching
 *        record's header to invalid cache.
 * @param[in] - i_eecacheSectionHeaderPtr - pointer to PNOR EECACHE
 * @param[in] - i_eepromRecordHeader - record pointing to eeprom to clear
 * @return error if failure during clear, else nullptr
 */
errlHndl_t clearEecache(eecacheSectionHeader * i_eecacheSectionHeaderPtr,
                        eepromRecordHeader & i_eepromRecordHeader);

/**
 * @brief Figure out the current cache state of the master eeprom for a given proc Target (i_assocTarg).
 *        It is expected that this proc target will have a VPD_PRIMARY record attached to itself.
 * @param[in] - i_assocTarg - proc target associated with some eeprom record
 * @param[out] - o_valid - true if master eeprom is valid, else false
 * @param[out] - o_changed - true if master eeprom has changed, else false
 * @return errlHndl_t - nullptr if successful, otherwise a pointer to an error log
 */
errlHndl_t getMasterEepromCacheState(TARGETING::Target * i_assocTarg, bool & o_valid,
                                     bool & o_changed);

/*
 * @brief Searches through the records in PNOR EECACHE to check for the
 *        existence of the search record in PNOR.
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
 * @param[in]   i_searchRecordHeader  A record that has been constructed by
 *                                    calling buildEepromRecordHeader().
 *
 * @param[out]  o_recordHeaderFromPnor  A pointer that must be nullptr because
 *                                      it will be reassigned to the record
 *                                      found or a place for a new record.
 *
 *
 * @return  errlHndl_t
 */
errlHndl_t findEepromHeaderInPnorEecache(
        TARGETING::Target*         i_target,
        bool const                 i_present,
        EEPROM::EEPROM_ROLE const  i_eepromType,
        eepromRecordHeader const & i_searchRecordHeader,
        eepromRecordHeader      *& o_recordHeaderFromPnor);

// Constants for use in updateEecacheContents' i_newPart parameter
const bool EECACHE_EXISTING_PART = false;
const bool EECACHE_NEW_PART = true;

/* @brief     Updates the eeprom cache entry's contents in PNOR. This only
 *            modifies the data after the header section in the EECACHE
 *            partition. This function assumes a completed record header has
 *            been given. That is to say that all fields have been filled in
 *            since buildEepromRecordHeader() doesn't do that automatically
 *            because fields like internal_offset and cached_copy_valid are
 *            determined based on what may or may not already exist in PNOR.
 *
 * @param[in]   i_target       Target associated with the eeprom record. Used
 *                             only for tracing purposes.
 *
 * @param[in]   i_eepromType   Describes which EEPROM associated to the target
 *                             that is being requested to be updated,
 *                             PRIMARY, BACKUP, etc.
 *
 * @param[in]   i_eepromBuffer A buffer containing data to load into EECACHE or
 *                             nullptr. If nullptr, HW lookup for data will be
 *                             attempted.
 *
 * @param[in]   i_eepromBuflen Length of i_eepromBuffer. If i_eepromBuffer is
 *                             nullptr then this should be 0.
 *
 * @param[in]  i_recordHeader The complete eeprom record header to be used to
 *                            update the contents in EECACHE.
 *
 * @param[in]  i_newPart      Whether the target represents a new part that
 *                            has been introduced into the system. This will
 *                            be the case when e.g. we detect a SN/PN mismatch
 *                            in a processor's MVPD and we need to update
 *                            the cached copy.
 *
 * @return  errlHndl_t
 */
errlHndl_t updateEecacheContents(TARGETING::Target*          i_target,
                                 EEPROM::EEPROM_ROLE const   i_eepromType,
                                 void        const * const   i_eepromBuffer,
                                 size_t              const   i_eepromBuflen,
                                 eepromRecordHeader  const & i_recordHeader,
                                 bool                        i_newPart = EECACHE_NEW_PART);

#else
/**
*
* @brief Check if entry already exists in g_cachedEeproms, if a match is
*        found then return true. If there is no match, add it to the list
*        and return false;
*
* @param[in] i_eepromRecordHeader Header for record we want to add to map
*
* @param[in] i_recordHeaderVaddr Virtual address to PNOR copy of header information
*
* @param[in] i_instance          Node ID that this eeprom is on
*
* @return TRUE if entry is already in map FALSE if this is a new entry
*
*/
bool addEepromToCachedList(const eepromRecordHeader & i_eepromRecordHeader,
                           const uint64_t i_recordHeaderVaddr,
                           const uint8_t i_instance);

/**
*
* @brief Perform a lookup on the global map g_cachedEeproms to get a
*        virtual address for a given EEPROM cache entry
*
* @param[in] i_eepromRecordHeader Header for record we want to add to lookup address for
*
* @param[in] i_instance  Node ID that this eeprom is on
*
* @pre  It is expected that i_eepromRecordHeader has valid information for
*       the uniqueID (i2cm_huid, port, engine, devAddr, mux_select)
*
* @return uint64_t virtual address pointing to the cached eeprom data in pnor
*
*/
uint64_t lookupEepromCacheAddr(const eepromRecordHeader& i_eepromRecordHeader,
                               const uint8_t i_instance);

/**
*
* @brief Walk through g_cachedEeproms map and print information about
*        the cached eeproms found
*
* @return void
*
*/
void printCurrentCachedEepromMap(void);

#endif  // __HOSTBOOT_RUNTIME

#if( defined(CONFIG_SUPPORT_EEPROM_CACHING) && !defined(CONFIG_SUPPORT_EEPROM_HWACCESS) )
/**
 * @brief Performs presence detection against the EECACHE PNOR partition.
 *        In this case, the target is considered present if it has a
 *        corresponding record in the EECACHE header.
 *
 * @param[in] i_target the target to check for presence
 * @param[out] o_present the presence state of the target
 * @return errlHndl_t: nullptr on success; non-nullptr on error
 */
errlHndl_t eecachePresenceDetect(TARGETING::Target* i_target,
                                 bool& o_present);
#endif

}

#endif // namespace  EEPROM
