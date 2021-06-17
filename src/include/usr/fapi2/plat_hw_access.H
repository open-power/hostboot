/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/plat_hw_access.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
#include <common_ringId.H>

#include <devicefw/userif.H>
#include "plat_utils.H"

namespace fapi2
{

// Forward-declare multicast enums
enum MulticastGroup : uint32_t;
enum MulticastType : uint32_t;

//------------------------------------------------------------------------------
// HW Communication Functions to be implemented at the platform layer.
//------------------------------------------------------------------------------
//


///
/// @brief Helper function to calculate the scanMode based on the
///        ring scan mode.
///        The bits which may be set in the returned scanMode are:
///          SCAN:SET_PULSE
///          SCAN::NO_HEADER_CHECK
/// @param[in]  scan mode from put ring call
/// @return scanMode
///
uint64_t platGetDDScanMode(const uint32_t i_ringMode);


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
inline ReturnCode platGetRing(const Target<TARGET_TYPE_ALL>& i_target,
                              const scanRingId_t i_address,
                              variable_buffer& o_data,
                              const RingMode i_ringMode)
{
    FAPI_ERR("platGetRing: not supported");
    assert(0,"platGetRing not supported.");
    return RC_UNSUPPORTED_OPERATION;
};


/// @brief Read-modify-write a ring on a chip.
/// @param[in] i_target     Target to operate on.
/// @param[in] i_address    Ring address to modify.
/// @param[in] i_data       Buffer that contains RS4 compressed ring data
///                         to be modified.
/// @param[in] i_modifyMode The modify mode (or/and/xor)
/// @param[in] i_ringMode   Ring operation mode.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
inline ReturnCode platModifyRing(const Target<TARGET_TYPE_ALL>& i_target,
                             const scanRingId_t i_address,
                             const variable_buffer& i_data,
                             const ChipOpModifyMode i_modifyMode,
                             const RingMode i_ringMode)
{
    FAPI_ERR("platModifyRing: not supported");
    assert(0,"platModifyRing not supported.");
    return RC_UNSUPPORTED_OPERATION;
};



// This will be used in future Cumulus code
/// @brief Write a ring on a chip.
/// @param[in] i_target     Target to operate on.
/// @param[in] i_address    Ring address to modify.
/// @param[in] i_data       Buffer that contains RS4 compressed ring data
///                         to be written
/// @param[in] i_ringMode   Ring operation mode.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
inline ReturnCode platPutRing(const Target<TARGET_TYPE_ALL>& i_target,
                       const scanRingId_t i_address,
                       variable_buffer& i_data,
                       const RingMode i_ringMode)
{
    FAPI_ERR("platPutRing: not supported");
    assert(0,"platPutRing not supported.");
    return RC_UNSUPPORTED_OPERATION;
};



/// @brief Writes a ring to a chip, the ring id will be passed to the SBE
///        the op will be executed
///
/// @param[in] i_target   Target to operate on.
/// @param[in] i_ringID   Ring ID that will identify the Ring to be scanned
/// @param[in] i_ringMode Ring operation mode.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
template<TargetType T>
inline ReturnCode platPutRing(const Target<T>& i_target,
                       const RingId_t i_ringID,
                       const RingMode i_ringMode)
{
    FAPI_ERR("platPutRing: not supported");
    assert(0,"platPutRing not supported.");
    return RC_UNSUPPORTED_OPERATION;
};



//--------------------------------------------------------------------------
// Operational Mode Error Functions
//--------------------------------------------------------------------------

/// @brief Sets the operational mode
/// @param[in]  i_mode     The new mode
void platSetOpMode(const OpModes i_mode);

/// @brief Gets the operational mode
/// @return the operational mode
OpModes platGetOpMode(void);

/// @brief Verify target of a cfam access
/// @param[in]  i_target    TARGETING::Target being verified
/// @param[in]  i_address   cfam address
errlHndl_t verifyCfamAccessTarget(const TARGETING::Target* i_target,
                                  const uint32_t i_address);

#ifndef PLAT_NO_THREAD_LOCAL_STORAGE
extern thread_local OpModes opMode;
#else
extern OpModes opMode;
#endif

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
* @brief Determine if a given target is on the boot proc chip
* @param[in]  i_Target   TARGETING::Target which op is being called on
* @param[out] i_isBootProc True if on boot proc chip, false if not
* @return errlHndl_t
*/
errlHndl_t isOnBootProc(TARGETING::Target * i_target, bool & o_isBootProc);

/**
 * @brief Assemble a multicast address from the given SCOM address
 *
 * @param[in] i_addr the SCOM address to populate with multicast info
 * @param[in] i_group the multicast group to add to the address
 * @param[in] i_op the multicast op (type) to add to the address
 * @param[in] i_coreSelect the core select bits
 * @return The assembled multicast address
 */
uint64_t getMulticastAddr(uint64_t i_addr,
                          MulticastGroup i_group,
                          MulticastType i_op,
                          MulticastCoreSelect i_coreSelect = MCCORE_NONE);

/**
 * @brief Returns the multicast bit of the given address
 *
 * @param[in] i_scomAddr the input address
 * @return bool whether the multicast bit is set in the given address
 */
bool isMulticastBitSet(uint32_t i_scomAddr);

/**
 * @brief Returns the multicast group of the passed address
 * @note The return value only makes sense if the multicast bit in the address
 *       is set
 *
 * @param[in] i_mulitcastScomAddr the input address
 * @return MulticastGroup the multicast group of the given address
 */
MulticastGroup getMulticastGroup(uint32_t i_multicastScomAddr);

/**
 * @brief Returns the muticast operation requested for the given multicast addr
 * @note The return value only makes sense if the multicast bit in the address
 *       is set
 *
 * @param[in] i_multicastScomAddr the input address
 * @return MulticastType the multicast operation requested
 */
MulticastType getMulticastOp(uint32_t i_mulitcastScomAddr);

/**
 * @brief Returns the core select bits of the specified address
 *
 * @param[in] i_multicastScomAddr the input address
 * @return MulticastCoreSelect the core select bits of the address
 */
MulticastCoreSelect getCoreSelect(uint32_t i_multicastScomAddr);

/**
 * @brief Encodes the given multicast group into hex value to insert into
 *        the mulitcast address.
 *
 * @param[in] i_group the multicast group to encode
 * @return uint32_t the encoded value in the range 0-7
 */
uint32_t getPlatMCGroup(MulticastGroup i_group);

} // End namespace

#endif // PLATHWACCESS_H_
