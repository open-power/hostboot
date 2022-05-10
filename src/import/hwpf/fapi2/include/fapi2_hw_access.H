/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/fapi2/include/fapi2_hw_access.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
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
///
/// @file fapi2_hw_access.H
/// @brief Common file that defines the hardware access functions that
/// platform code must implement.
///

#ifndef _FAPI2_COMMON_HWACCESS_H_
#define _FAPI2_COMMON_HWACCESS_H_

#ifdef FAPI_SUPPORT_SPY_AS_ENUM
    #include <spy_ids.H>
    typedef uint64_t spyId_t;
#endif

#include <stdint.h>
#include <buffer.H>

// variable_buffer isn't supported on PPE or Hostboot Bootloader
#if !defined(__PPE__) && !defined(FAPI_VARIABLE_BUFFER_NOT_SUPPORTED)
    #include <variable_buffer.H>
#endif

#include <return_code.H>
#include <target.H>
#include <hw_access_def.H>
#include <plat_hw_access.H>

namespace fapi2
{
// No PIB error masks supported by Hostboot Bootloader
#ifndef PIB_ERROR_MASK_NOT_SUPPORTED
    //--------------------------------------------------------------------------
    // PIB Error Functions
    //--------------------------------------------------------------------------

    /// @brief Sets the PIB error mask - platform dependant
    /// @param[in]  i_mask     The new error mask
    inline void setPIBErrorMask(uint8_t i_mask);

    /// @brief Gets the PIB error mask - platform dependant
    /// @return uint8_t The current PIB error mask
    inline uint8_t getPIBErrorMask(void);

#endif

//--------------------------------------------------------------------------
// Operational Mode Error Functions
//--------------------------------------------------------------------------

/// @brief Sets the operational mode
/// @param[in]  i_mode     The new mode
inline void setOpMode(const OpModes i_mode);

/// @brief Gets the operational mode
/// @return the operational mode
inline OpModes getOpMode(void);

//--------------------------------------------------------------------------
// Multicast mapping functions
//--------------------------------------------------------------------------

/// @brief Set up or replace the multicast group mapping for a given chip
/// @param[in] i_chip     The chip whose multicast map is to be replaced
/// @param[in] i_mappings A list of multicast group mappings
/// @return FAPI2_RC_SUCCESS if the map was updated, otherwise error code.
///
/// This replaces the given chip's map of abstract multicast groups to chip
/// specific hardware values with a new map. Any abstract group not explicitly
/// mapped via i_mappings will be unmapped after this call returns success,
/// and attempting to create multicast targets targeting unmapped groups will
/// result in error.
/// i_mappings may contain an arbitrary amount of abstract/HW pairs, but the
/// function may return an error if too many mappings are specified.
/// If the hardware supports a "broadcast" group, that must also be mapped
/// explicitly via this function - platforms are not expected to map the
/// broadcast group implicitly.
template< TargetType K, MulticastType M, typename V >
inline ReturnCode setMulticastGroupMap(const Target<K, M, V>& i_chip,
                                       const std::vector< MulticastGroupMapping >& i_mappings);

//--------------------------------------------------------------------------
// HW Communication Functions
//--------------------------------------------------------------------------

/// @brief Reads a SCOM register from a chip.
/// @tparam K template parameter, passed in target.
/// @param[in]  i_target     HW target to operate on.
/// @param[in]  i_address    SCOM register address to read from.
/// @param[out] o_data       Buffer that holds data read from HW target.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
template< TargetType K, MulticastType M, typename V >
inline ReturnCode getScom(const Target<K, M, V>& i_target, const uint64_t i_address,
                          buffer<uint64_t>& o_data);

/// @brief Writes a SCOM register on a chip.
/// @tparam K template parameter, passed in target.
/// @param[in] i_target     HW target to operate on.
/// @param[in] i_address    SCOM register address to write to.
/// @param[in] i_data       Buffer that holds data to write into address.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
template< TargetType K, MulticastType M, typename V >
inline ReturnCode putScom(const Target<K, M, V>& i_target, const uint64_t i_address,
                          const buffer<uint64_t> i_data);

/// @brief Writes a SCOM register under mask on a chip
/// @tparam K template parameter, passed in target.
/// @param[in] i_target     HW target to operate on.
/// @param[in] i_address    SCOM register address to write to.
/// @param[in] i_data       Buffer that holds data to write into address.
/// @param[in] i_mask       Buffer that holds the mask value.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
template< TargetType K, MulticastType M, typename V >
inline ReturnCode putScomUnderMask(const Target<K, M, V>& i_target,
                                   const uint64_t i_address,
                                   const buffer<uint64_t> i_data,
                                   const buffer<uint64_t> i_mask);

/// @brief Reads a CFAM register from a chip.
///        CFAM register is 32-bit wide.
/// @tparam K template parameter, passed in target.
/// @param[in]  i_target  HW target to operate on.
/// @param[in]  i_address CFAM register address to read from.
/// @param[out] o_data    Buffer that holds data read from HW target.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
template< TargetType K, MulticastType M, typename V >
inline ReturnCode getCfamRegister(const Target<K, M, V>& i_target,
                                  const uint32_t i_address,
                                  buffer<uint32_t>& o_data);

/// @brief Writes a CFAM register on a chip.
///        CFAM register is 32-bit wide.
/// @tparam K template parameter, passed in target.
/// @param[in] i_target  HW target to operate on.
/// @param[in] i_address CFAM register address to write to.
/// @param[in] i_data    Buffer that holds data to write into address.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
template< TargetType K, MulticastType M, typename V >
inline ReturnCode putCfamRegister(const Target<K, M, V>& i_target,
                                  const uint32_t i_address,
                                  const buffer<uint32_t> i_data);

/// @brief Read-modify-write a CFAM register on a chip.
///        CFAM register is 32-bit wide.
/// @tparam K template parameter, passed in target.
/// @param[in] i_target     HW target to operate on.
/// @param[in] i_address    CFAM register address to modify.
/// @param[in] i_data       Buffer that holds data to be modified.
/// @param[in] i_modifyMode The modify mode (or/and/xor).
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
template< TargetType K, MulticastType M, typename V >
inline ReturnCode modifyCfamRegister(const Target<K, M, V>& i_target,
                                     const uint32_t i_address,
                                     const buffer<uint32_t> i_data,
                                     const ChipOpModifyMode i_modifyMode);

/// @brief Writes a ring to a chip.
/// @tparam K template parameter, passed in target.
/// @param[in] i_target   Target to operate on.
/// @param[in] i_ringID   Ring ID that will identify the Ring in the image.
/// @param[in] i_ringMode Ring operation mode.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
template< TargetType K, MulticastType M, typename V >
ReturnCode putRing(const Target<K, M, V>& i_target,
                   const RingId_t i_ringID,
                   const RingMode i_ringMode = RING_MODE_HEADER_CHECK);

/// @brief Writes a ring to a chip.
/// @tparam K template parameter, passed in target.
/// @param[in] i_target   Target to operate on.
/// @param[in] i_ringID   Ring ID name that will identify the Ring in the image.
/// @param[in] i_ringMode Ring operation mode.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
template< TargetType K, MulticastType M, typename V >
ReturnCode putRing(const Target<K, M, V>& i_target,
                   const char* i_ringID,
                   const RingMode i_ringMode = RING_MODE_HEADER_CHECK);

// variable_buffer isn't supported on PPE
#if !defined(__PPE__) && !defined(FAPI_VARIABLE_BUFFER_NOT_SUPPORTED)
/// @brief Reads a ring from a chip.
/// @tparam K template parameter, passed in target.
/// @param[in]  i_target   Target to operate on.
/// @param[in]  i_address  Ring address to read from.
/// @param[out] o_data     Buffer that holds data read from HW target.
/// @param[in]  i_ringMode Ring operation mode.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
template< TargetType K, MulticastType M, typename V >
inline ReturnCode getRing(const Target<K, M, V>& i_target,
                          const scanRingId_t i_address,
                          variable_buffer& o_data,
                          const RingMode i_ringMode = RING_MODE_HEADER_CHECK);

/// @brief Read-modify-write a ring on a chip.
/// @tparam K template parameter, passed in target.
/// @param[in] i_target     Target to operate on.
/// @param[in] i_address    Ring address to modify.
/// @param[in] i_data       Buffer that contains RS4 compressed ring data
///                         to be modified.
/// @param[in] i_modifyMode The modify mode (or/and/xor)
/// @param[in] i_ringMode   Ring operation mode.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
template< TargetType K, MulticastType M, typename V >
inline ReturnCode modifyRing(const Target<K, M, V>& i_target,
                             const scanRingId_t i_address,
                             const variable_buffer& i_data,
                             const ChipOpModifyMode i_modifyMode,
                             const RingMode i_ringMode = RING_MODE_HEADER_CHECK);
#endif

// --------------------------------------------------------------------------
// NOTE:
// Implement platform Spy access functions if platform supports them.
// --------------------------------------------------------------------------

// variable_buffer isn't supported on PPE
#if !defined(__PPE__) && !defined(FAPI_VARIABLE_BUFFER_NOT_SUPPORTED)
/// @brief Reads a spy from a chip.
/// @tparam K template parameter, passed in target.
/// @param[in]  TARGET   Target to operate on.
/// @param[in]  ID       Id of the spy whose data to be read.
/// @param[out] DATA     Buffer that holds data read from HW target.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
/// @note:  The string version is only supported for cronus.
///
///         The fapi design to support both FSP and cronus use of get and
///         put spy functions is dependant on the SPY names being expanded
///         to resemble a valid C identifier. This design places some
///         restrictions on the SPY names which can be used.
///
///         1. if the spy name contains a # procedure writers should replace
///         it with an __P__ for example -
///
///         ABUS.RX0.RXPACKS#0.RXPACK.RD.LC.LC.ACT_DIS
///         becomes
///         ABUS.RX0.RXPACKS__P__0.RXPACK.RD.LC.LC.ACT_DIS
///
///         2. if the spy name has a number following a "." it must have an
///         underscore prepended to the number.
///
///         EH.TPCHIP.2KX100_ARY_CLK_EDGES_DLY
///         becomes
///         EH.TPCHIP._2KX100_ARY_CLK_EDGES_DLY
///
///         Example SPY name:
///         The hardware procedure should call the function like:
///
///          ABUS.RX0.RXPACKS#0.RXPACK.RD.LC.LC.ACT_DIS
///
///          fapi2::ReturnCode rc = fapiGetSpy( targ,
///                  ABUS.RX0.RXPACKS__P__0.RXPACK.RD.LC.LC.ACT_DIS, data );
///
/// @note The ID is not in quotes the fapi code will handle adding
///       the quotes for the cronus environment
#if defined(FAPI_SUPPORT_SPY_AS_ENUM) || defined(DOXYGEN)

#define FAPI_GET_SPY(TARGET, ID, DATA) fapi2::getSpy(TARGET, FAPI_SPY_NAMES::ID.value, DATA)

template< TargetType K, MulticastType M, typename V >
inline ReturnCode getSpy(const Target<K, M, V>& i_target,
                         const spyId_t i_spyId,
                         variable_buffer& o_data);

template< TargetType K >
inline ReturnCode getSpy(const Target<K>& i_target,
                         const spyId_t i_spyId,
                         variable_buffer& o_data,
                         const RingMode i_ringMode);
#endif

#if defined(FAPI_SUPPORT_SPY_AS_STRING) || defined(DOXYGEN)

#define FAPI_GET_SPY(TARGET, ID, DATA) fapi2::getSpy(TARGET, #ID, DATA)

template< TargetType K, MulticastType M, typename V >
inline ReturnCode getSpy(const Target<K, M, V>& i_target,
                         const char* const i_spyId,
                         variable_buffer& o_data);

template< TargetType K >
inline ReturnCode getSpy(const Target<K>& i_target,
                         const char* const i_spyId,
                         variable_buffer& o_data,
                         const RingMode i_ringMode);
#endif

/// @brief Writes a spy on a chip.
/// @tparam K template parameter, passed in target.
/// @param[in]  TARGET   Target to operate on.
/// @param[in]  ID       Id of the spy to write data to.
/// @param[out] DATA     Buffer that holds data to write into spy.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
/// @note:  The string version is only supported for cronus.
///
///         The fapi design to support both FSP and cronus use of get and
///         put spy functions is dependent on the SPY names being expanded
///         to resemble a valid C identifier. This design places some
///         restrictions on the SPY names which can be used.
///
///         1. if the spy name contains a # procedure writers should replace
///         is with an __P__ for example -
///
///         ABUS.RX0.RXPACKS#0.RXPACK.RD.LC.LC.ACT_DIS
///         becomes
///         ABUS.RX0.RXPACKS__P__0.RXPACK.RD.LC.LC.ACT_DIS
///
///         2. if the spy name has a number following a "." it must have an
///         underscore prepended to the number.
///
///         EH.TPCHIP.2KX100_ARY_CLK_EDGES_DLY
///         becomes
///         EH.TPCHIP._2KX100_ARY_CLK_EDGES_DLY
///
///         Example SPY name:
///         The hardware procedure should call the function like:
///
///          ABUS.RX0.RXPACKS#0.RXPACK.RD.LC.LC.ACT_DIS
///
///          fapi2::ReturnCode rc = fapiPutSpy( targ,
///                  ABUS.RX0.RXPACKS__P__0.RXPACK.RD.LC.LC.ACT_DIS, data );
///
/// @note The ID is not in quotes the fapi code will handle adding
///         the quotes for the cronus environment
///
#if defined(FAPI_SUPPORT_SPY_AS_ENUM) || defined(DOXYGEN)

#define FAPI_PUT_SPY(TARGET, ID, DATA) fapi2::putSpy(TARGET, FAPI_SPY_NAMES::ID.value, DATA)

template< TargetType K, MulticastType M, typename V >
inline ReturnCode putSpy(const Target<K, M, V>& i_target,
                         const spyId_t i_spyId,
                         const variable_buffer& i_data);
#endif

#if defined(FAPI_SUPPORT_SPY_AS_STRING) || defined(DOXYGEN)

#define FAPI_PUT_SPY(TARGET, ID, DATA) fapi2::putSpy(TARGET, #ID, DATA)

template< TargetType K, MulticastType M, typename V >
inline ReturnCode putSpy(const Target<K, M, V>& i_target,
                         const char* const i_spyId,
                         const variable_buffer& i_data);

template< TargetType K, MulticastType M, typename V >
inline ReturnCode putSpyWithCare(const Target<K, M, V>& i_target,
                                 const char* const i_spyId,
                                 const variable_buffer& i_data,
                                 const variable_buffer& i_care);

template< TargetType K, MulticastType M, typename V >
inline ReturnCode putSpy(const Target<K, M, V>& i_target,
                         const char* const i_spyId,
                         const char* i_enum);
#endif

/// @brief Writes spy data into a buffer holding ring data image
///        This API is used by L2/L3 repair to put column repair data
///        into a ring buffer image.
/// @tparam K template parameter, passed in target.
/// @param[in]  TARGET Target to operate on.
/// @param[in]  ID     Id of the spy.
/// @param[in]  DATA1  Buffer that holds spy data to write into ring
///                      image.
/// @param[out] DATA2  Buffer that holds updated ring image.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
/// @note:  The string version is only supported for cronus.
///
///         The fapi design to support both FSP and cronus use of get and
///         put spy functions is dependent on the SPY names being expanded
///         to resemble a valid C identifier. This design places some
///         restrictions on the SPY names which can be used.
///
///         See fapiPutSpy for details on spy id specifics.
///
#if defined(FAPI_SUPPORT_SPY_AS_ENUM) || defined(DOXYGEN)

#define FAPI_PUT_SPY_IMAGE(TARGET, ID, DATA1, DATA2)                    \
    fapi2::putSpyImage(TARGET, FAPI_SPY_NAMES::ID.value,                \
                       DATA1, DATA2)

template< TargetType K, MulticastType M, typename V >
inline ReturnCode putSpyImage(const Target<K, M, V>& i_target,
                              const spyId_t i_spyId,
                              const variable_buffer& i_data,
                              variable_buffer& o_imageData);
#endif

#if defined(FAPI_SUPPORT_SPY_AS_STRING) || defined(DOXYGEN)

#define FAPI_PUT_SPY_IMAGE(TARGET, ID, DATA1, DATA2) \
    fapi2::putSpyImage(TARGET, #ID, DATA1,DATA2)

template< TargetType K, MulticastType M, typename V >
inline ReturnCode putSpyImage(const Target<K, M, V>& i_target,
                              const char* const i_spyId,
                              const variable_buffer& i_data,
                              variable_buffer& o_imageData);
#endif

/// @brief Reads spy data from a ring image buffer
/// @param[in]   TARGET    Target to operate on
/// @param[in]   ID        The spy's id
/// @param[out]  DATA1     Buffer that holds data read from ring image.
/// @param[in]   DATA2     Buffer that holds ring image to read data
///                        from.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
/// @note:  The string version is only supported for cronus.
///
///         The fapi design to support both FSP and cronus use of get and
///         put spy functions is dependent on the SPY names being expanded
///         to resemble a valid C identifier. This design places some
///         restrictions on the SPY names which can be used.
///
///         See fapiPutSpy for details on spy id specifics.
///
#if defined(FAPI_SUPPORT_SPY_AS_ENUM) || defined(DOXYGEN)

#define FAPI_GET_SPY_IMAGE(TARGET, ID, DATA1, DATA2)    \
    fapi2:getSpyImage(TARGET, FAPI_SPY_NAMES::ID.value, \
                      DATA1, DATA2)

template< TargetType K, MulticastType M, typename V >
inline ReturnCode getSpyImage(const Target<K, M, V>& i_target,
                              const spyId_t i_spyId,
                              variable_buffer& o_data,
                              const variable_buffer& i_imageData);
#endif

#if defined(FAPI_SUPPORT_SPY_AS_STRING) || defined(DOXYGEN)

#define FAPI_GET_SPY_IMAGE(TARGET, ID, DATA1, DATA2) \
    fapi2::getSpyImage(TARGET, #ID, DATA1,DATA2)

template< TargetType K, MulticastType M, typename V >
inline ReturnCode getSpyImage(const Target<K, M, V>& i_target,
                              const char* const i_spyId,
                              variable_buffer& o_data,
                              const variable_buffer& i_imageData);
#endif

#endif // PPE and FAPI_VARIABLE_BUFFER_NOT_SUPPORTED
};

#endif // _FAPI2_HWACCESS_H_
