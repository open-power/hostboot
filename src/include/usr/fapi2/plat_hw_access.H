/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/plat_hw_access.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file plat_hw_access.H
///
/// @brief Defines hardware-access functions for the platform layer.
/// Hardware procedure writers will not call these functions.
/// These platform entry points are called by fapi2 functions from
/// hw_access.H, output scand traces common to all platforms.
/// These functions have the same argument signatures as the
/// fapi-level functions, but the function names her start with
/// "plat."
///

#ifndef PLATHWACCESS_H_
#define PLATHWACCESS_H_

#include <return_code.H>
#include <buffer.H>
#include <target.H>
#include <target_types.H>
#include <hw_access_def.H>
#include <p9_ringId.H>

namespace fapi2
{

//------------------------------------------------------------------------------
// HW Communication Functions to be implemented at the platform layer.
//------------------------------------------------------------------------------

///
/// @brief Platform-level implementation called by getScom()
/// @Tparam K template parameter, passed in target.
/// @param[in]  i_target   HW target to operate on.
/// @param[in]  i_address  SCOM register address to read from.
/// @param[out] o_data     Buffer that holds data read from HW target.
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
ReturnCode platGetScom(const Target<TARGET_TYPE_ALL>& i_target,
                       const uint64_t i_address,
                       buffer<uint64_t>& o_data);


/// @brief Platform-level implementation called by putScom()
/// @Tparam K template parameter, passed in target.
/// @param[in] i_target     HW target to operate on.
/// @param[in] i_address    SCOM register address to write to.
/// @param[in] i_data       Buffer that holds data to write into address.
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
ReturnCode platPutScom(const Target<TARGET_TYPE_ALL>& i_target,
                       const uint64_t i_address,
                       const buffer<uint64_t> i_data);


/// @brief Platform-level implementation called by putScomUnderMask()
/// @tparam K template parameter, passed in target.
/// @param[in] i_target     HW target to operate on.
/// @param[in] i_address    SCOM register address to write to.
/// @param[in] i_data       Buffer that holds data to write into address.
/// @param[in] i_mask       Buffer that holds the mask value.
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
ReturnCode platPutScomUnderMask(const Target<TARGET_TYPE_ALL>& i_target,
                                const uint64_t i_address,
                                const buffer<uint64_t> i_data,
                                const buffer<uint64_t> i_mask);


///
/// @brief Platform-level implementation called by getCfamRegister()
/// Hardware procedures writers will not call this function.
/// @Tparam K template parameter, passed in target.
/// @param[in]  i_target   HW target to operate on.
/// @param[in]  i_address  CFAM address to read from.
/// @param[out] o_data     32-bit buffer that holds data read from HW target.
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
ReturnCode platGetCfamRegister(const Target<TARGET_TYPE_ALL>& i_target,
                               const uint32_t i_address,
                               buffer<uint32_t>& o_data);


///
/// @brief Platform-level implementation called by putCfamRegister()
/// Hardware procedures writers will not call this function.
/// @param[in]  i_target   HW target to operate on.
/// @param[in]  i_address  CFAM address to write to.
/// @param[out] i_data     32-bit buffer that holds data to write into address.
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
ReturnCode platPutCfamRegister(const Target<TARGET_TYPE_ALL>& i_target,
                               const uint32_t i_address,
                               const buffer<uint32_t> i_data);


///
/// @brief Platform-level implementation of modifyCfamRegister()
/// Hardware procedures writers will not call this function.
/// @param[in]  i_target     HW target to operate on.
/// @param[in]  i_address    CFAM register address to modify.
/// @param[out] i_data       32-bit buffer that holds data to modify.
/// @param[in]  i_modifyMode The modify mode (or/and/xor).
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
ReturnCode platModifyCfamRegister(const Target<TARGET_TYPE_ALL>& i_target,
                                  const uint32_t i_address,
                                  const buffer<uint32_t> i_data,
                                  const fapi2::ChipOpModifyMode i_modifyMode);



/// @brief Reads a ring from a chip.
/// @param[in]  i_target   Target to operate on.
/// @param[in]  i_address  Ring address to read from.
/// @param[out] o_data     Buffer that holds data read from HW target.
/// @param[in]  i_ringMode Ring operation mode.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
ReturnCode platGetRing(const Target<TARGET_TYPE_ALL>& i_target,
                              const scanRingId_t i_address,
                              variable_buffer& o_data,
                              const RingMode i_ringMode);

/// @brief Read-modify-write a ring on a chip.
/// @param[in] i_target     Target to operate on.
/// @param[in] i_address    Ring address to modify.
/// @param[in] i_data       Buffer that contains RS4 compressed ring data
///                         to be modified.
/// @param[in] i_modifyMode The modify mode (or/and/xor)
/// @param[in] i_ringMode   Ring operation mode.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
ReturnCode platModifyRing(const Target<TARGET_TYPE_ALL>& i_target,
                             const scanRingId_t i_address,
                             const variable_buffer& i_data,
                             const ChipOpModifyMode i_modifyMode,
                             const RingMode i_ringMode);


// This will be used in future Cumulus code
/// @brief Write a ring on a chip.
/// @param[in] i_target     Target to operate on.
/// @param[in] i_address    Ring address to modify.
/// @param[in] i_data       Buffer that contains RS4 compressed ring data
///                         to be written
/// @param[in] i_ringMode   Ring operation mode.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
ReturnCode platPutRing(const Target<TARGET_TYPE_ALL>& i_target,
                       const scanRingId_t i_address,
                       variable_buffer& i_data,
                       const RingMode i_ringMode);

/// @brief Writes a ring to a chip.
/// @param[in] i_target   Target to operate on.
/// @param[in] i_ringID   Ring ID that will identify the Ring in the image.
/// @param[in] i_ringMode Ring operation mode.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
ReturnCode platPutRing(const Target<TARGET_TYPE_ALL>& i_target,
                       const RingId_t i_ringID,
                       const RingMode i_ringMode);

//--------------------------------------------------------------------------
// Operational Mode Error Functions
//--------------------------------------------------------------------------

/// @brief Sets the operational mode
/// @param[in]  i_mode     The new mode
void platSetOpMode(const OpModes i_mode);

/// @brief Gets the operational mode
/// @return the operational mode
OpModes platGetOpMode(void);

extern OpModes opMode;

//--------------------------------------------------------------------------
// PIB Error Mask Functions
//--------------------------------------------------------------------------
//
// See hw_access.H for more detail on pib error mask

/// @brief Sets the pib error mask
/// @param[in]  i_mask     The new mask
void platSetPIBErrorMask(const uint8_t i_mask);

/// @brief Gets the pib error mask
/// @return the pib error mask
uint8_t platGetPIBErrorMask(void);

/// @brief takes in an error log and looks for user details sections
///        with a compId of COMP_SCOM_ID. If one of those is found and
///        the pib err attatched to it matches the pib_err_mask, then
///        we delete the err.
/// @param[in/out] io_errLog Error log that we would like the check the piberr
///                mask against
/// @return void
void checkPibMask(errlHndl_t& io_errLog );

// --------------------------------------------------------------------------
// NOTE:
// No spy access interface as HB doesn't allow spy access.
// --------------------------------------------------------------------------

/**
* @brief Determine if a given target is on the master proc chip
* @param[in]  i_Target   TARGETING::Target which op is being called on
* @param[out] i_isMaster True if on master proc chip, false if not
* @return errlHndl_t
*/
errlHndl_t isOnMasterProc(TARGETING::Target * i_target, bool & o_isMaster);


} // End namespace

#endif // PLATHWACCESS_H_
