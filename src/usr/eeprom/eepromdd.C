/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/eeprom/eepromdd.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2022                        */
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

/**
 * @file eepromdd.C
 *
 * @brief Implementation of the EEPROM device driver,
 *      which will access various EEPROMs within the
 *      system via the I2C device driver
 *
 */

#include <errl/errlentry.H>     // errlHndl_t
#include <errl/errlmanager.H>
#include <devicefw/driverif.H>  // DeviceFW::OperationTyp
                                // TARGETING::Target
                                // va_list
#include "eepromCache.H"
#include "eepromdd_hardware.H"
#include <eeprom/eepromddreasoncodes.H>
#include <eeprom/eepromif.H>

#include <array>
#include <vector>

#ifdef __HOSTBOOT_RUNTIME
// Need to be able to convert HB target id's to runtime target ids
#include <targeting/attrrp.H>
#endif

extern trace_desc_t* g_trac_eeprom;

// Easy macro replace for unit testing
// #define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

using namespace TARGETING;

namespace EEPROM
{

/**
*
* @brief Determine if a given EEPROM has been cached into pnor's EECACHE
*        section yet or not. If it has source will be CACHE, if it has not
*        been cached yet, then source will be HARDWARE
*
*
* @param[in] i_target  - Target device associated with the eeprom.
*
* @param[in/out] io_i2cInfo - Struct containing information that tells us which
*                             EEPROM associated with the given Target we wish
*                             to lookup. NOTE it is assumed eepromRole member
*                             in this struct has been filled out prior to it
*                             being passed to this function.
*
* @pre i_i2cInfo.eepromRole is expected to have a valid value set
*
* @post o_source will either be EEPROM::CACHE or EEPROM::HARDWARE
*       io_i2cInfo will have info filled out (side effect not used)
*
* @return errlHndl_t - NULL if successful, otherwise a pointer to the
*       error log.
*
*/
errlHndl_t resolveSource(Target * i_target,
                         eeprom_addr_t & io_eepromAddr,
                         EEPROM::EEPROM_SOURCE & o_source)
{
#ifdef CONFIG_SUPPORT_EEPROM_CACHING
    eepromRecordHeader l_eepromRecordHeader;
    errlHndl_t err = nullptr;

    err = buildEepromRecordHeader(i_target,
                                  io_eepromAddr,
                                  l_eepromRecordHeader);
#ifndef __HOSTBOOT_RUNTIME
    // if lookupEepromAddr returns non-zero address
    // then we know it exists in cache somewhere
    if(lookupEepromCacheAddr(l_eepromRecordHeader))
    {
        TRACDCOMP(g_trac_eeprom,"Eeprom of 0x%08X tgt and %d role found in cache, looking at eecache",
          get_huid(i_target), io_eepromAddr.eepromRole);
        o_source = EEPROM::CACHE;
    }
    else
    {
        TRACDCOMP(g_trac_eeprom,"Eeprom not found in cache, looking at hardware");
        o_source = EEPROM::HARDWARE;
    }
#else
    uint8_t l_instance = AttrRP::getNodeId(i_target);
    // if lookupEepromAddr returns non-zero address
    // then we know it exists in cache somewhere
    if(lookupEepromCacheAddr(l_eepromRecordHeader, l_instance))
    {
        TRACDCOMP(g_trac_eeprom,"Eeprom found in cache, looking at eecache");
        o_source = EEPROM::CACHE;
    }
    else
    {
        /*@
        * @errortype
        * @moduleid     EEPROM_RESOLVE_SOURCE
        * @reasoncode   EEPROM_CACHE_NOT_FOUND_IN_MAP
        * @userdata1[0:31]  master Huid
        * @userdata1[32:39] port (or 0xFF)
        * @userdata1[40:47] engine
        * @userdata1[48:55] devAddr of eeprom slave   (or byte 0 offset_KB)
        * @userdata1[56:63] muxSelect of eeprom slave (or byte 1 offset_KB)
        * @userdata2[0:31]  size of eeprom
        * @devdesc      resolveSource failed to find cache in map during runtime
        * @custdesc     An internal firmware error occurred
        */
        err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        EEPROM_RESOLVE_SOURCE,
                        EEPROM_CACHE_NOT_FOUND_IN_MAP,
                        getEepromHeaderUserData(l_eepromRecordHeader),
                        l_eepromRecordHeader.completeRecord.cache_copy_size,
                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
    }
#endif
    return err;
#else //  CONFIG_SUPPORT_EEPROM_CACHING
    return nullptr;
#endif
}


// ------------------------------------------------------------------
// eepromPerformSingleOp
// ------------------------------------------------------------------
/**
 *
 * @brief Perform a single EEPROM access operation to EECACHE (when supported)
 *        or hardware.
 *
 * @note see performMacroOp for parameter documentation.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the
 *       error log.
 *
 */
errlHndl_t eepromPerformSingleOp(const DeviceFW::OperationType i_opType,
                                 Target* const i_target,
                                 void* const io_buffer,
                                 size_t& io_buflen,
                                 const int64_t i_accessType,
                                 const eeprom_addr_t& i_eepromAddr,
                                 const EEPROM_SOURCE i_source)
{
    errlHndl_t err = nullptr;

    TRACUCOMP (g_trac_eeprom, ENTER_MRK"eepromPerformSingleOp(): target 0x%08X "
               "i_opType=%d, role=%d, offset=%x, len=%d, i_source %d",
               get_huid(i_target), (uint64_t) i_opType,
               i_eepromAddr.eepromRole, i_eepromAddr.offset, io_buflen,
               i_source);

    do{
#ifdef CONFIG_SUPPORT_EEPROM_CACHING
        if(i_source == EEPROM::CACHE  )
        {
            // Read the copy of the EEPROM data we have cached in PNOR
            err = eepromPerformOpCache(i_opType, i_target,
                                       io_buffer, io_buflen, i_eepromAddr);
            if(err)
            {
                break;
            }
        }
        else if(i_source == EEPROM::HARDWARE)
        {
            // Read from the actual physical EEPROM device
            err = eepromPerformOpHW(i_opType, i_target, io_buffer,
                                    io_buflen, i_eepromAddr);
        }
        else
        {
            assert(false, "Unrecognized EEPROM_SOURCE %d", i_source);
        }
#else
        // Read from the actual physical EEPROM device
        err = eepromPerformOpHW(i_opType, i_target, io_buffer,
                                io_buflen, i_eepromAddr);
#endif // CONFIG_SUPPORT_EEPROM_CACHING
    }while(0);


    TRACDCOMP( g_trac_eeprom,
               EXIT_MRK"eepromPerformSingleOp() - %s",
               ((NULL == err) ? "No Error" : "With Error") );

    return err;
} // end eepromPerformSingleOp

/* @brief Wrapper around resolveSource to use as a predicate in the EEPROM
 *        operation dispatch table.
 *
 * @param[in] i_target            Target to operate on
 * @param[in] i_eepromAddr        EEPROM address to consider
 * @param[in] i_source            EEPROM source to consider
 * @param[in] o_hasEecacheEntry   Whether the given EEPROM has an EECACHE entry
 * @return errlHndl_t             Error if any, otherwise nullptr.
 */
static errlHndl_t eepromHasEecacheEntry(Target* i_target,
                                        eeprom_addr_t i_eepromAddr,
                                        EEPROM_SOURCE i_source,
                                        bool& o_hasEecacheEntry)
{
    o_hasEecacheEntry = false;
    errlHndl_t errl = resolveSource(i_target, i_eepromAddr, i_source);

    if (!errl)
    {
        o_hasEecacheEntry = i_source == EEPROM::CACHE;
    }

    return errl;
}

const int RULE_ANY = -1; // Wildcard for rule table
const int RULE_INVALID = -2; // Indicates an invalid rule

/* @brief Represents a single EEPROM operation in the routing table below.
 */
struct eeprom_subop
{
    // Used to enable or disable this rule.
    using predicate_t = errlHndl_t(*)(Target*, eeprom_addr_t, EEPROM_SOURCE, bool&);

    int new_eeprom_role = RULE_INVALID; // The EEPROM role to use instead of the original
    int new_source = RULE_INVALID; // The EEPROM source to use instead of the original

    predicate_t predicate = nullptr; // If this predicate is nullptr, it is
                                     // ignored. If not and it outputs true, the
                                     // rule is applied as usual; if it outputs
                                     // false and the alternate_* variables are
                                     // not INVALID, then they are used instead.

    int alternate_new_eeprom_role = RULE_INVALID; // Role to use when predicate returns false
    int alternate_new_source = RULE_INVALID; // Ditto source
};

/* @brief This structure is used to describe a routing rule for EEPROM
 *        accesses. Each eeprom_macroop represents one operation that should be
 *        translated into multiple other operations.
 */
struct eeprom_macroop
{
    int eeprom_role = RULE_INVALID; // VPD_PRIMARY, VPD_BACKUP, WOF_DATA, etc.
    int source = RULE_INVALID; // AUTOSELECT, CACHE, HARDWARE
    eeprom_subop subentries[2]; // Increase the max if needed
};

/* Each time an EEPROM operation is requested, this table is consulted. If the
 * combination of EEPROM role (VPD_PRIMARY, etc.) and source (EEPROM, HARDWARE,
 * AUTOSELECT) matches a rule, then the specified sub-operations are performed
 * INSTEAD of the original operation. This is used to "expand" one operation
 * into several redundant ones if applicable.
 *
 * The table is searched from beginning to end. Only the first matching rule
 * applies. If no rule matches, the operation is performed as-is with no
 * modification to the EEPROM role or source.
 *
 * Multiple sub-operations are performed according to whether the operation is a
 * READ or a WRITE.
 * - READ operations stop when one succeeds.
 * - WRITE operations keep going even when one fails. The operation counts as a
 *   success if any one of the sub-operations succeeds.
 *
 * Sub-operations are also translated via this table, so it is essentially
 * recursive.
 *
 * When the replacement role and source of a sub-operation matches the rule
 * itself, the table is not consulted (which would result in an infinite loop),
 * but rather the operation is immediately done with the original role and
 * source. This is useful for wildcard rules that want to perform the original
 * operation and other operations in addition.
 */
const eeprom_macroop eeprom_macro_ops[] {
    { VPD_AUTO, AUTOSELECT,         // This rule matches the VPD_AUTO role with AUTOSELECT source
        { { VPD_PRIMARY, CACHE,     // Translate to a VPD_PRIMARY,CACHE access...
            eepromHasEecacheEntry,  // ...if the EEPROM has an EECACHE entry.
            VPD_PRIMARY, HARDWARE },// Otherwise, translate to a VPD_PRIMARY,HARDWARE access.
          { VPD_BACKUP, HARDWARE } }// Also, do a VPD_BACKUP,HARDWARE access with no predicate.
    },
    { VPD_AUTO, CACHE,
        { { VPD_PRIMARY, CACHE },
          { VPD_BACKUP, HARDWARE } } },
    { VPD_AUTO, HARDWARE,
        { { VPD_PRIMARY, HARDWARE },
          { VPD_BACKUP, HARDWARE } } },
    { RULE_ANY, AUTOSELECT,  // This rule matches any role with the AUTOSELECT source.
        { { RULE_ANY, CACHE, // Use the original role with the CACHE source
                             // (when the predicate is true).
            eepromHasEecacheEntry,
            RULE_ANY, HARDWARE } } }, // Use the original role with the HARDWARE
                                      // source (when the predicate is false).
    { RULE_ANY, CACHE,
        { { RULE_ANY, CACHE }, // A normal CACHE access (i.e. not translated through this table)
          { RULE_ANY, HARDWARE } } }, // Hardware access afterwards
};

/* @brief Get the EEPROM_VPD_ACCESSIBILITY mask for a given role and source
 *        combination.
 *
 * @param[in] i_role    The EEPROM role.
 * @param[in] i_source  The EEPROM source.
 * @return uint32_t     The mask (to be used with ATTR_EEPROM_VPD_ACCESSIBILITY)
 */
static uint32_t roleMask(const int i_role, const int i_source)
{
    uint32_t mask = EEPROM_VPD_ACCESSIBILITY_NONE_DISABLED;

    if (i_role == VPD_PRIMARY || i_role == VPD_BACKUP)
    {
        if (i_source == CACHE)
        {
            mask = EEPROM_VPD_ACCESSIBILITY_CACHE_DISABLED;
        }
        else if (i_role == VPD_PRIMARY)
        {
            mask = EEPROM_VPD_ACCESSIBILITY_PRIMARY_DISABLED;
        }
        else
        {
            mask = EEPROM_VPD_ACCESSIBILITY_SECONDARY_DISABLED;
        }
    }

    return mask;
}

/* @brief Determine whether a role matches the given rule.
 *
 * @param[in] i_role       The operation role.
 * @param[in] i_rule_role  The rule's role.
 * @return bool            Whether the role matches the rule.
 */
static bool ruleMatchesRole(const int i_role, const int i_rule_role)
{
    return i_rule_role == RULE_ANY || i_role == i_rule_role;
}

/* @brief Determine the sub-operation's role from the operation's role and the
 *        sub-operation's "replacement" role.
 *
 * @param[in] i_role      The original operation's role.
 * @param[in] i_new_role  The sub-operation's replacement role.
 * @return int            The new role to use.
 */
static int newRole(const int i_role, const int i_new_role)
{
    int new_role = i_role;

    if (i_new_role != RULE_ANY)
    {
        new_role = i_new_role;
    }

    return new_role;
}

/* @brief Determine whether the sub-operation indicates to execute the original
 *        operation as-is.
 *
 * @param[in] i_rule_role    The role from the rule.
 * @param[in] i_rule_source  The source from the rule.
 * @param[in] i_new_role     The sub-op's replacement role.
 * @param[in] i_new_source   The sub-op's replacement source.
 * @return bool              Whether to execute the original operation.
 */
static bool forceNormalAccess(const int i_rule_role, const int i_rule_source,
                              const int i_new_role, const int i_new_source)
{
    return i_rule_role == i_new_role && i_rule_source == i_new_source;
}

/* @brief Perform a single physical EEPROM operation.
 *
 * @note See performMacroOp for parameter documentation.
 *
 * @return bool True if the operation was actually performed and succeeded,
 *              false otherwise.
 */
static bool performPhysicalOp(const DeviceFW::OperationType i_opType,
                              Target* const i_target,
                              void* const io_buffer,
                              size_t& io_buflen,
                              const int64_t i_accessType,
                              const eeprom_addr_t& i_eepromAddr,
                              uint32_t& io_target_mask,
                              int& io_attempts,
                              int& io_failures,
                              std::vector<errlHndl_t>& io_errors,
                              const EEPROM_SOURCE i_source)
{
    bool success = false;

    const uint32_t functional_mask = roleMask(i_eepromAddr.eepromRole, i_source);

    if ((functional_mask & io_target_mask) == 0)
    { // If the mask says we've tried accessing this access before and it
      // failed, then don't try again.
        ++io_attempts;

        const errlHndl_t errl
            = eepromPerformSingleOp(i_opType, i_target, io_buffer, io_buflen,
                                    i_accessType, i_eepromAddr, i_source);

        if (errl)
        {
            ++io_failures;
            io_target_mask |= functional_mask;
            io_errors.push_back(errl);
        }
        else
        {
            success = true;
        }
    }

    return success;
}

/* @brief Perform an EEPROM operation, consulting the eeprom_macro_ops table to
 *        possibly expand macro-ops into one or more sub-operations.
 *
 * @param[in] i_opType - Operation Type - See DeviceFW::OperationType in
 *       driververif.H
 *
 * @param[in] i_target - Target device.
 *
 * @param[in/out] io_buffer
 *       INPUT: Pointer to the data that will be  written to the target
 *           device.
 *       OUTPUT: Pointer to the data that was read from the target device.
 *
 * @param[in/out] io_buflen
 *       INPUT: Length of the buffer to be written to target device.
 *       OUTPUT: Length of buffer that was written, or length of buffer
 *           to be read from target device.
 *
 * @param[in] i_accessType - Access Type - See DeviceFW::AccessType in
 *       userif.H
 *
 * @param[in] i_eepromAddr - Details about the EEPROM to access
 *
 * @param[in/out] io_target_mask
 *       INPUT - The functional mask for the EEPROM sources.
 *               Comes from ATTR_EEPROM_VPD_ACCESSIBILITY.
 *       OUTPUT - The functional mask updated with the result of all
 *                the operations that were performed and failed.
 *
 * @param[in/out] io_attempts - The number of physical EEPROM operations that were
 *       actually attempted, regardless of whether they failed.
 *
 * @param[in/out] io_failures - The number of physical EEPROM operations that
 *       were attempted and failed.
 *
 * @param[in/out] io_errors - Errors encountered while performing EEPROM
 *       operations.
 *
 * @param[in] i_source - Whether to read from EECACHE or hardware (only
 *       supported when EECACHE support is enabled).
 */
static bool performMacroOp(const DeviceFW::OperationType i_opType,
                           Target* const i_target,
                           void* const io_buffer,
                           size_t& io_buflen,
                           const int64_t i_accessType,
                           const eeprom_addr_t& i_eepromAddr,
                           uint32_t& io_target_mask,
                           int& io_attempts,
                           int& io_failures,
                           std::vector<errlHndl_t>& io_errors,
                           const EEPROM_SOURCE i_source)
{
    bool function_success = false; // Whether this function succeeded.
    bool rule_match = false; // Whether we found any rules that matched.

    /// Search the table for a matching rule and apply it.

    for (const eeprom_macroop& entry : eeprom_macro_ops)
    {
        if (ruleMatchesRole(i_eepromAddr.eepromRole, entry.eeprom_role) && i_source == entry.source)
        {
            rule_match = true;

            for (const eeprom_subop& subentry : entry.subentries)
            {
                if (subentry.new_eeprom_role != RULE_INVALID)
                {
                    bool single_success = false;

                    auto new_source = static_cast<EEPROM_SOURCE>(subentry.new_source);
                    auto eepromAddr = i_eepromAddr;
                    eepromAddr.eepromRole = newRole(i_eepromAddr.eepromRole, subentry.new_eeprom_role);

                    /// Evaluate the predicate if there is one.

                    if (subentry.predicate)
                    {
                        bool predicate_success = false;
                        errlHndl_t err = subentry.predicate(i_target, eepromAddr, new_source, predicate_success);

                        if (err)
                        {
                            io_errors.push_back(err);
                            err = nullptr;
                            continue;
                        }

                        if (!predicate_success)
                        {
                            if (subentry.alternate_new_eeprom_role == RULE_INVALID)
                            {
                                continue; // skip this rule if the predicate didn't give an alternate role/source
                            }
                            else
                            {
                                eepromAddr.eepromRole = newRole(i_eepromAddr.eepromRole,
                                                                subentry.alternate_new_eeprom_role);
                                new_source = static_cast<EEPROM_SOURCE>(subentry.alternate_new_source);
                            }
                        }
                    }

                    /// Check whether the rule says to perform the access
                    /// as-is. If so, do so. If not, perform the transformed
                    /// operation.

                    if (forceNormalAccess(entry.eeprom_role, entry.source,
                                          subentry.new_eeprom_role, subentry.new_source))
                    {
                        single_success
                            = performPhysicalOp(i_opType, i_target, io_buffer, io_buflen, i_accessType, i_eepromAddr,
                                                io_target_mask, io_attempts, io_failures, io_errors, i_source);
                    }
                    else
                    { // Perform the transformed access.
                        single_success
                            = performMacroOp(i_opType, i_target, io_buffer,
                                             io_buflen, i_accessType, eepromAddr,
                                             io_target_mask, io_attempts, io_failures,
                                             io_errors, new_source);
                    }

                    function_success = function_success || single_success;

                    if (single_success && i_opType == DeviceFW::READ)
                    { // Stop when the first read succeeds. If it's a write, continue on.
                        break;
                    }
                }
            }

            break; // first matching rule wins
        }
    }

    /// If there were no matching rules, then perform the operation as-is.

    if (!rule_match)
    {
        function_success
            = performPhysicalOp(i_opType, i_target, io_buffer, io_buflen, i_accessType, i_eepromAddr,
                                io_target_mask, io_attempts, io_failures, io_errors, i_source);
    }

    return function_success;
}

// ------------------------------------------------------------------
// eepromPerformOp
// ------------------------------------------------------------------
/**
 *
 * @brief Perform an EEPROM access operation.
 *
 * @param[in] i_opType - Operation Type - See DeviceFW::OperationType in
 *       driververif.H
 *
 * @param[in] i_target - Target device.
 *
 * @param[in/out] io_buffer
 *       INPUT: Pointer to the data that will be  written to the target
 *           device.
 *       OUTPUT: Pointer to the data that was read from the target device.
 *
 * @param[in/out] io_buflen
 *       INPUT: Length of the buffer to be written to target device.
 *       OUTPUT: Length of buffer that was written, or length of buffer
 *           to be read from target device.
 *
 * @param [in] i_accessType - Access Type - See DeviceFW::AccessType in
 *       usrif.H
 *
 * @param [in] i_args - This is an argument list for the device driver
 *       framework.  This argument list consists of the chip number of
 *       the EEPROM to access from the given I2C Master target and the
 *       internal offset to use on the slave I2C device.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the
 *       error log.
 *
 */
errlHndl_t eepromPerformOp(DeviceFW::OperationType i_opType,
                           Target * i_target,
                           void* io_buffer,
                           size_t& io_buflen,
                           int64_t i_accessType,
                           va_list i_args)
{
    eeprom_addr_t eepromAddr = { };

    eepromAddr.eepromRole = va_arg(i_args, uint64_t);
    eepromAddr.offset = va_arg(i_args, uint64_t);

#ifdef CONFIG_SUPPORT_EEPROM_CACHING
    EEPROM_SOURCE l_source = (EEPROM_SOURCE)va_arg(i_args, uint64_t);
#else
    EEPROM_SOURCE l_source = EEPROM::HARDWARE;
#endif

    /// If we're accessing VPD, check whether the target has redundant VPD, and
    /// decide which VPDs we want to attempt to access.

    ATTR_EEPROM_VPD_ACCESSIBILITY_type vpd_disabled_mask_attr = EEPROM_VPD_ACCESSIBILITY_NONE_DISABLED;
    i_target->tryGetAttr<ATTR_EEPROM_VPD_ACCESSIBILITY>(vpd_disabled_mask_attr);

    ATTR_EEPROM_VPD_REDUNDANCY_type vpd_redundancy_state = EEPROM_VPD_REDUNDANCY_POSSIBLE;
    if (i_target->tryGetAttr<ATTR_EEPROM_VPD_REDUNDANCY>(vpd_redundancy_state))
    {
        // If this target doesn't have redundant VPD then don't bother using the AUTO
        // rules in the table.
        if ((vpd_redundancy_state == EEPROM_VPD_REDUNDANCY_NOT_PRESENT) &&
            (eepromAddr.eepromRole == VPD_AUTO))
        {
            eepromAddr.eepromRole = VPD_PRIMARY;
        }
    }

    int attempts = 0, failures = 0;
    std::vector<errlHndl_t> errors;

    uint32_t vpd_disabled_mask = vpd_disabled_mask_attr;

    performMacroOp(i_opType, i_target, io_buffer, io_buflen,
                   i_accessType, eepromAddr, vpd_disabled_mask,
                   attempts, failures, errors, l_source);

    // Update the EEPROM accessibility mask to disable whatever EEPROMs failed
    // in the prior access.
    if (vpd_disabled_mask != vpd_disabled_mask_attr)
    {
        TRACFCOMP(g_trac_eeprom, "perfomMacroOp() changing disabled vpd from 0x%08X to 0x%08X on HUID 0x%08X target",
            vpd_disabled_mask_attr, vpd_disabled_mask, TARGETING::get_huid(i_target));
        i_target->trySetAttr<ATTR_EEPROM_VPD_ACCESSIBILITY>(static_cast<EEPROM_VPD_ACCESSIBILITY>(vpd_disabled_mask));
    }

    errlHndl_t errl = nullptr;

    if (attempts == 0)
    { // If we didn't try any operations (because all the sources were
      // disabled), then report an error.
        /*@
         * @errortype
         * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         EEPROM_PERFORM_OP
         * @reasoncode       EEPROM_NO_FUNCTIONAL_EEPROM
         * @userdata1[0:31]  Target HUID
         * @userdata1[32:63] Operation type (0 -> read, 1 -> write)
         * @userdata2[0:31]  EEPROM role
         * @userdata2[32:63] EEPROM source
         * @devdesc          No functional EEPROM source available
         * @custdesc         There is a problem accessing the vital product data or another device
         */
        errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       EEPROM_PERFORM_OP,
                                       EEPROM_NO_FUNCTIONAL_EEPROM,
                                       TWO_UINT32_TO_UINT64(get_huid(i_target),
                                                            i_opType),
                                       TWO_UINT32_TO_UINT64(eepromAddr.eepromRole,
                                                            l_source),
                                       ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
    }
    else if (attempts == failures)
    { // If we tried some but they all failed, then return one of the errors we
      // collected.
        assert(!errors.empty(), "eepromPerformOp: list of errors is empty");

        errl = errors[0];
        errors[0] = nullptr;
    }

    for (errlHndl_t& e : errors)
    { // Clean up error handles.
        if (e)
        {
            if (!errl)
            { // If we didn't fail overall, make these informational logs and
              // commit them.
                TRACFCOMP( g_trac_eeprom,
                    ERR_MRK"eepromPerformOp: plid 0x%08X error marked as informational for non-overall failure",
                    ERRL_GETPLID_SAFE(e));
                e->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
            }

            TRACFCOMP( g_trac_eeprom,
                    ERR_MRK"eepromPerformOp: committing error plid 0x%08X error",
                    ERRL_GETPLID_SAFE(e));
            e->collectTrace(EEPROM_COMP_NAME);
            errlCommit(e, EEPROM_COMP_ID);
        }
    }

    return errl;
}

#ifndef __HOSTBOOT_RUNTIME
errlHndl_t reloadMvpdEecacheFromNextSource( TARGETING::Target* const i_target,
                                            errlHndl_t &io_triggerErrorLog )
{
    errlHndl_t errl = reloadMvpdEecacheFromNextSource(i_target);

    // if reloadMvpdEecacheFromNextSource is successful and io_triggerErrorLog
    // is not a nullptr then commit io_triggerErrorLog
    if ( (nullptr == errl)               &&
         (nullptr != io_triggerErrorLog)   )
    {
        // If reloadMvpdEecacheFromNextSource is successful then commit the error,
        // that precipitated the call to this API, as revovered.
        io_triggerErrorLog->setSev(ERRORLOG::ERRL_SEV_RECOVERED);
        TRACFCOMP( g_trac_eeprom, ERR_MRK"reloadMvpdEecacheFromNextSource: "
                   "The error log (%08X) that precipitated the reloading of the MVPD EECACHE "
                   "for target 0x%08X has module Id 0x%.2X and reason code 0x%.4X.",
                   io_triggerErrorLog->eid(),
                   TARGETING::get_huid(i_target),
                   io_triggerErrorLog->moduleId(),
                   io_triggerErrorLog->reasonCode() );
        io_triggerErrorLog->collectTrace(EEPROM_COMP_NAME);
        ERRORLOG::errlCommit( io_triggerErrorLog, EEPROM_COMP_ID );
        io_triggerErrorLog = nullptr;
    }
    // else do not commit nor modify original error

    return errl;
}


errlHndl_t reloadMvpdEecacheFromNextSource( TARGETING::Target* const i_target)
{
    using namespace TARGETING;
    using namespace ERRORLOG;

    TRACFCOMP(g_trac_eeprom,
              ENTER_MRK"reloadMvpdEecacheFromNextSource: target 0x%08x",
              get_huid(i_target));

    bool success = false;
    errlHndl_t errl = nullptr;

    ATTR_EEPROM_VPD_ACCESSIBILITY_type vpd_mask { };
    ATTR_EEPROM_VPD_REDUNDANCY_type eeprom_redundancy = EEPROM_VPD_REDUNDANCY_POSSIBLE;

    do
    {

    /// First check whether the target supports redundant VPD.

    if (!i_target->tryGetAttr<ATTR_EEPROM_VPD_ACCESSIBILITY>(vpd_mask))
    {
        break;
    }

    if (i_target->tryGetAttr<ATTR_EEPROM_VPD_REDUNDANCY>(eeprom_redundancy))
    {
        if (eeprom_redundancy == EEPROM_VPD_REDUNDANCY_NOT_PRESENT)
        {
            TRACFCOMP(g_trac_eeprom,
              "reloadMvpdEecacheFromNextSource: target 0x%08x does not have redundant eeproms",
              get_huid(i_target));
            break;
        }
    }

    /// Find the first VPD source that is active, so we can disable it.

    auto new_bit = EEPROM_VPD_ACCESSIBILITY_PRIMARY_DISABLED;

    for (; new_bit < EEPROM_VPD_ACCESSIBILITY_LAST_DISABLED >> 1;
         new_bit = static_cast<ATTR_EEPROM_VPD_ACCESSIBILITY_type>(new_bit << 1))
    {
        if ((vpd_mask & new_bit) == 0)
        {
            break;
        }
    }

    /// If there are no redundant VPD sources left, then error.

    if (new_bit == EEPROM_VPD_ACCESSIBILITY_LAST_DISABLED >> 1)
    {
        break;
    }

    /// Update the VPD accessibility mask, so that future accesses won't use the
    /// bad VPD source again.

    const auto new_mask = static_cast<ATTR_EEPROM_VPD_ACCESSIBILITY_type>(vpd_mask | new_bit);

    i_target->setAttr<ATTR_EEPROM_VPD_ACCESSIBILITY>(new_mask);

    /// Refresh the MVPD EECACHE.

    TRACFCOMP(g_trac_eeprom,
              INFO_MRK"reloadMvpdEecacheFromNextSource: Reloading VPD_PRIMARY EECACHE entry "
              "on target 0x%08x with EEPROM_VPD_ACCESSIBILITY mask 0x%x",
              get_huid(i_target),
              new_mask);

    eepromRecordHeader searchEepromRecordHeader { };
    eeprom_addr_t eepromInfo { };

    eepromInfo.eepromRole = VPD_PRIMARY;
    errl = buildEepromRecordHeader(i_target, eepromInfo, searchEepromRecordHeader);

    if (errl)
    {
        TRACFCOMP(g_trac_eeprom, ERR_MRK"reloadMvpdEecacheFromNextSource: buildEepromRecordHeader failed");
        break;
    }

    eepromRecordHeader* realEepromRecordHeader = nullptr;

    errl = findEepromHeaderInPnorEecache(i_target,
                                         true, // target is present
                                         VPD_PRIMARY,
                                         searchEepromRecordHeader,
                                         realEepromRecordHeader);

    if (errl)
    {
        TRACFCOMP(g_trac_eeprom, ERR_MRK"reloadMvpdEecacheFromNextSource: findEepromHeaderInPnorEecache failed");
        break;
    }

    errl = updateEecacheContents(i_target,
                                 VPD_AUTO,
                                 nullptr, // data buffer (using nullptr to auto-allocate)
                                 0, // data size
                                 *realEepromRecordHeader,
                                 EECACHE_EXISTING_PART);

    if (errl)
    {
        TRACFCOMP(g_trac_eeprom, ERR_MRK"reloadMvpdEecacheFromNextSource: updateEecacheContents failed");
        break;
    }

    success = true;

    } while(false);

    if (!success && !errl)
    {
        TRACFCOMP(g_trac_eeprom, ERR_MRK"reloadMvpdEecacheFromNextSource: No functional EEPROMs left "
                  "on target 0x%08x",
                  get_huid(i_target));

        /*@
         * @errortype
         * @severity         ERRL_SEV_UNRECOVERABLE
         * @moduleid         EEPROM_DISABLE_NEXT_MVPD_SOURCE
         * @reasoncode       EEPROM_NO_FUNCTIONAL_EEPROM
         * @userdata1        Mask from ATTR_EEPROM_VPD_ACCESSIBILITY
         * @userdata2        HUID of target
         * @devdesc          No functional EEPROM source available
         * @custdesc         There is a problem accessing the vital product data or another device
         */
        errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                             EEPROM_DISABLE_NEXT_MVPD_SOURCE,
                             EEPROM_NO_FUNCTIONAL_EEPROM,
                             vpd_mask,
                             get_huid(i_target),
                             ErrlEntry::NO_SW_CALLOUT);

        errl->addHwCallout(i_target,
                           HWAS::SRCI_PRIORITY_HIGH,
                           HWAS::DELAYED_DECONFIG,
                           HWAS::GARD_NULL);

        errl->collectTrace(EEPROM_COMP_NAME);
    }

    TRACFCOMP(g_trac_eeprom, EXIT_MRK"reloadMvpdEecacheFromNextSource");

    return errl;
}

#endif

// Register the perform Op with the routing code for Procs.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::EEPROM,
                       TYPE_PROC,
                       eepromPerformOp );

// Register the perform Op with the routing code for DIMMs.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::EEPROM,
                       TYPE_DIMM,
                       eepromPerformOp );

// Register the perform Op with the routing code for Memory Buffers.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::EEPROM,
                       TYPE_MEMBUF,
                       eepromPerformOp );

// Register the perform Op with the routing code for Nodes.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::EEPROM,
                       TYPE_NODE,
                       eepromPerformOp );

// Register the perform Op with the routing code for TPMs.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::EEPROM,
                       TYPE_TPM,
                       eepromPerformOp );

// Register the perform Op with the routing code for MCS chiplets.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::EEPROM,
                       TYPE_MCS,
                       eepromPerformOp );

// Register the perform Op with the routing code for Open-Capi Memory Buffer Chips.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::EEPROM,
                       TYPE_OCMB_CHIP,
                       eepromPerformOp );

} // end namespace EEPROM
