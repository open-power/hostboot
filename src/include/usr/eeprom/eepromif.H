/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/eeprom/eepromif.H $                           */
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
#ifndef __EEPROMIF_H
#define __EEPROMIF_H

/**
 *  @file eepromif.H
 *  @brief Header containing EEPROM interfaces for user space modules to use
 */

#include <list>
#include <eeprom/eeprom_const.H>
#include <errl/errlentry.H>
#include <targeting/common/attributes.H>

namespace EEPROM
{

#ifdef __HOSTBOOT_RUNTIME
/**
 * @brief This function returns a bool indicating if overrides to VPD data are
 *        allowed during runtime.
 *
 * @return bool - True, writes to only EEPROM CACHE are allowed
 *                False, writes to EEPROM HW, EEPROM CACHE, and FSP are NOT allowed
 */
bool allowVPDOverrides();

/**
 * @brief This function sets g_allow_vpd_overrides during runtime
 *        to disable and re-enable writing to EPROM HW and FSP
 *
 * @param[in] i_setVal - bool set g_allow_vpd_overrides
 *                       True, writes to only EEPROM CACHE are allowed
 *                       False, writes to EEPROM HW, EEPROM CACHE, and FSP are NOT allowed
 */
void setAllowVPDOverrides(bool i_setVal);
#endif

/**
* @brief Check if the target gets its VPD from a remote source
*        such as the BMC. This function will check the VPD_SWITCHES
*        attribute to see if vpdCollectedRemotely is set, if set
*        this indicates a remote source thinks this target is present
*        and has given us the VPD associated with it.
*
* @param[in] i_target Target we want to query for whether it has a remote VPD source or not
*
* @return bool True if vpdCollectedRemotely bit on ATTR_VPD_SWITCHES is true
*
* @note targets that do not have ATTR_VPD_SWITCHES will always return false
*
*/
bool hasRemoteVpdSource(TARGETING::Target * i_target);

/**
 * @brief This function tests to see if the VPD_PRIMARY eeprom is present
 *        for the specific target.
 *
 * @param[in] i_target - Target device.
 *
 * @return bool - True if the eeprom is present, false otherwise.
 */
bool eepromPresence ( TARGETING::Target * i_target );


/**
 * @brief This function will switch eeprom AUTO_VPD access from the VPD_PRIMARY
 *        to the VPD_BACKUP eeprom if one exists or may exist.
 *
 * @param[in] i_target - Target device.
 *
 * @return bool - True if switched, else false
 */
bool eepromSwitchToBackup( TARGETING::Target * i_target );


/**
 * @brief this function will read all of the associated attributes needed
 *        to access the intended EEPROM.  These attributes will be used to
 *        determine the type of I2C device as well as how to address it via
 *        the I2C device driver.
 *
 * @param[in] i_target - Target device.
 *
 * @param[out] o_i2cInfo - The structure that will contain the attribute data
 *      read from the target device.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t eepromReadAttributes ( TARGETING::Target * i_target,
                                  eeprom_addr_t & o_i2cInfo );


/**
 * @brief This function determines whether or not the i2cMasterPath provided
 *        along with i_i2cInfo points to a valid target. If it does not,
 *        o_target will result as NULL. If the target is valid then the
 *        o_target will point to the target pointer which i2cMasterPath
 *        represents.
 *
 * @param[in] i_target - The current Target.
 *
 * @param[in] i_eepromInfo - structure of eeprom information with master target
 *                           entity path filled in
 *
 * @param[out] o_target - The "new" target that will be used for all operations
 *      from this point on.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t eepromGetMasterTarget ( TARGETING::Target * i_target,
                                   const eeprom_addr_t & i_eepromInfo,
                                   TARGETING::Target * &o_target );

/**
 * @brief Return a set of information related to every unique
 *        EEPROM in the system (currently used to build HDAT structure)
 *
 * @param[out] o_info - list of EEPROM Information
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
void getEEPROMs( std::list<EepromInfo_t>& o_info );

/**
 *
 * @brief A useful utility to dump (trace out) the EepromVpdPrimaryInfo data.
 *        Use as needed.
 *
 * @param [in] i_i2cInfo - The EepromVpdPrimaryInfo data to dump for user
 *
 */
void dumpEepromData(const TARGETING::EepromVpdPrimaryInfo & i_i2cInfo);

/**
 *
 * @brief A useful utility to dump (trace out) the eeprom_addr_t data.
 *         Use as needed.
 *
 * @param [in] i_i2cInfo - The eeprom_addr_t data to dump for user
 *
 */
void dumpEepromData(const eeprom_addr_t & i_i2cInfo);

/**
 *
 * @brief A useful utility to cache the VPD for a given target
 *        from a provided byte vector
 *
 * @param [in] i_target - Target which we would like to associate with
 *                        eeprom data buffer in EECACHE
 * @param [in] i_present - Target's presence (cannot rely on HWAS)
 * @param [in] i_eeprom_data - data buffer that will be cached in EECACHE
 *
 */
errlHndl_t cacheEepromBuffer(TARGETING::Target * i_target,
                             bool i_present,
                             const std::vector<uint8_t>& i_eeprom_data);

/**
 *
 * @brief A useful utility to cache the VPD for a given target
 *        from that target's HW
 *
 * @param [in] i_target - Target whose EEPROMs we would like to cache
 * @param [in] i_present - Target's presence (cannot rely on HWAS)
 *
 */
void cacheEepromVpd(TARGETING::Target * i_target, bool i_present);

/**
 *
 * @brief A useful utility to cache all ancillary role eeprom data
 *        This is for the roles that do not know if the cache has changed
 *
 *        This should be called after cacheEeepromVpd() has been called for
 *        each target.  Needs the master eeprom setup first.
 */
void cacheEepromAncillaryRoles();

/**
 *  @brief Get a common user data piece for eepromRecordHeader record
 *         Format returned:
 *           @userdata1[0:31]  HUID of Master
 *           @userdata1[32:39] Port (or 0xFF)
 *           @userdata1[40:47] Engine
 *           @userdata1[48:55] devAddr    (or byte 0 offset_KB)
 *           @userdata1[56:63] mux_select (or byte 1 offset_KB)
 *  @param Filled in eeprom record header
 *  @return userdata for this eeprom record
 */
uint64_t getEepromHeaderUserData(const eepromRecordHeader& i_eepromRecordHeader);

#ifndef __HOSTBOOT_RUNTIME

/* @brief  A wrapper around the call to reloadMvpdEecacheFromNextSource with the
 *         additional error log parameter.  See reloadMvpdEecacheFromNextSource
 *         below for more details.
 *
 * @param[in] i_target  The target to operate on
 * @param[in/out] io_triggerErrorLog  The error that precipitated the call to this API.
 *                 * if reloadMvpdEecacheFromNextSource is successful - This error log
 *                        will be committed and set to nullptr.
 *                 * if reloadMvpdEecacheFromNextSource fails - This error log will
 *                        *not* be committed nor modified and will be returned as is.
 *
 * @return errlHndl_t   Error if any, otherwise nullptr.
 */
errlHndl_t reloadMvpdEecacheFromNextSource(TARGETING::Target* i_target,
                                           errlHndl_t &io_triggerErrorLog );

/* @brief  Disable the current redundant MVPD source for the given target, and
 *         reload the VPD EECACHE entry from the next source. If there are no
 *         more MVPD sources available, then return an error.
 *
 * @note The given target must be "present" according to HWAS.
 *
 * @param[in] i_target  The target to operate on
 * @return errlHndl_t   Error if any, otherwise nullptr.
 */
errlHndl_t reloadMvpdEecacheFromNextSource(TARGETING::Target* i_target);

#endif

};  // end namespace EEPROM

#endif  // end __EEPROMIF_H
