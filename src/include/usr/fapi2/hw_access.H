/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/hw_access.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/// @file hw_access.H
///
/// @brief Hardware access functions that needs to be specialized for
/// platform implementation.
///

#ifndef _FAPI2_HWACCESS_H_
#define _FAPI2_HWACCESS_H_

#include <plat_hw_access.H>
#include <fapi2_hw_access.H>

namespace fapi2
{

//--------------------------------------------------------------------------
// PIB Error Functions
//
// The pib err mask can be set in order
// to ignore specific pib errors returned by a scom. The mask
// is a thread local variable and will be reset to 0 during every
// FAPI_INVOKE call before the function is executed, therefore
// it will reset on HWP calls.
//--------------------------------------------------------------------------

/// @brief Sets the PIB error mask - platform dependant
/// @param[in]  i_mask     The new error mask
// note: this can be moved  to a C file if desired
inline void setPIBErrorMask(const uint8_t i_mask)
{
    return platSetPIBErrorMask(i_mask);
}

/// @brief Gets the PIB error mask - platform dependant
/// @return uint8_t The current PIB error mask
// note: this can be moved  to a C file if desired
inline uint8_t getPIBErrorMask(void)
{
    return platGetPIBErrorMask();
}

//--------------------------------------------------------------------------
// Operational Mode Error Functions
//--------------------------------------------------------------------------

//The operational mode, or opMode is a thread local variable that allows the
//fapi2 interface to call getScom or putScom with special settings. Examples
//of their use cases are disabling the abiility for a scom to wakeup or core
//or ignore hardware errors. The opMode is reset on every FAPI_INVOKE call
//and is therefore reset each HWP.

/// @brief Sets the operational mode
/// @param[in]  i_mode     The new mode
// note: this can be moved  to a C file if desired
inline void setOpMode(const OpModes i_mode)
{
    return platSetOpMode(i_mode);
}

/// @brief Gets the operational mode
/// @return the operational mode
// note: this can be moved  to a C file if desired
inline OpModes getOpMode(void)
{
    return platGetOpMode();
}

//------------------------------------------------------------------------------
// HW Communication Functions to be implemented at the platform layer.
//------------------------------------------------------------------------------

///
/// @brief Platform-level implementation of getScom()
/// @Tparam K the type (Kind) of target
/// @Tparam M the type of multicast operation if it's a multicast target
/// @Tparam V the type of the target's value
/// @param[in]  i_target   HW target to operate on.
/// @param[in]  i_address  SCOM register address to read from.
/// @param[out] o_data     Buffer that holds data read from HW target.
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
template< TargetType K, MulticastType M, typename V >
inline ReturnCode getScom(const Target<K, M, V>& i_target,
                          const uint64_t i_address,
                          buffer<uint64_t>& o_data)
{
    return platGetScom(i_target, i_address, o_data);
}

/// @brief Platform-level implementation of putScom()
/// @Tparam K the type (Kind) of target
/// @Tparam M the type of multicast operation if it's a multicast target
/// @Tparam V the type of the target's value
/// @param[in] i_target     HW target to operate on.
/// @param[in] i_address    SCOM register address to write to.
/// @param[in] i_data       Buffer that holds data to write into address.
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
template< TargetType K, MulticastType M, typename V >
inline ReturnCode putScom(const Target<K, M, V>& i_target,
                          const uint64_t i_address,
                          const buffer<uint64_t> i_data)
{
    return platPutScom(i_target, i_address, i_data);
}

/// @brief Platform-level implementation of putScomUnderMask()
/// @Tparam K the type (Kind) of target
/// @Tparam M the type of multicast operation if it's a multicast target
/// @Tparam V the type of the target's value
/// @param[in] i_target     HW target to operate on.
/// @param[in] i_address    SCOM register address to write to.
/// @param[in] i_data       Buffer that holds data to write into address.
/// @param[in] i_mask       Buffer that holds the mask value.
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
template< TargetType K, MulticastType M, typename V >
inline ReturnCode putScomUnderMask(const Target<K, M, V>& i_target,
                                   const uint64_t i_address,
                                   const buffer<uint64_t> i_data,
                                   const buffer<uint64_t> i_mask)
{
    return platPutScomUnderMask(i_target, i_address, i_data, i_mask);
}

///
/// @brief Platform-level implementation called by getCfamRegister()
/// Hardware procedures writers will not call this function.
/// @Tparam K the type (Kind) of target
/// @Tparam M the type of multicast operation if it's a multicast target
/// @Tparam V the type of the target's value
/// @param[in]  i_target   HW target to operate on.
/// @param[in]  i_address  CFAM address to read from.
/// @param[out] o_data     32-bit buffer that holds data read from HW target.
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
template< TargetType K, MulticastType M, typename V >
inline ReturnCode getCfamRegister(const Target<K, M, V>& i_target,
                                  const uint32_t i_address,
                                  buffer<uint32_t>& o_data)
{
    return platGetCfamRegister(i_target, i_address, o_data);
}

///
/// @brief Platform-level implementation of putCfamRegister()
/// Hardware procedures writers will not call this function.
/// @Tparam K the type (Kind) of target
/// @Tparam M the type of multicast operation if it's a multicast target
/// @Tparam V the type of the target's value
/// @param[in]  i_target   HW target to operate on.
/// @param[in]  i_address  CFAM address to write to.
/// @param[out] i_data     32-bit buffer that holds data to write into address.
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
template< TargetType K, MulticastType M, typename V >
inline ReturnCode putCfamRegister(const Target<K, M, V>& i_target,
                                  const uint32_t i_address,
                                  const buffer<uint32_t> i_data)
{
    return platPutCfamRegister(i_target, i_address, i_data);
}


///
/// @brief Platform-level implementation of modifyCfamRegister()
/// Hardware procedures writers will not call this function.
/// @Tparam K the type (Kind) of target
/// @Tparam M the type of multicast operation if it's a multicast target
/// @Tparam V the type of the target's value
/// @param[in]  i_target     HW target to operate on.
/// @param[in]  i_address    CFAM register address to modify.
/// @param[out] i_data       32-bit buffer that holds data to modify.
/// @param[in]  i_modifyMode The modify mode (or/and/xor).
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
template< TargetType K, MulticastType M, typename V >
inline ReturnCode modifyCfamRegister(const Target<K, M, V>& i_target,
                                     const uint32_t i_address,
                                     const buffer<uint32_t> i_data,
                                     const fapi2::ChipOpModifyMode i_modifyMode)
{
    return platModifyCfamRegister(i_target, i_address, i_data, i_modifyMode);
}

// variable_buffer isn't supported on PPE
#if !defined(__PPE__) && !defined(FAPI_VARIABLE_BUFFER_NOT_SUPPORTED)
///
/// @brief Platform-level implementation of getRing()
/// Hardware procedures writers will not call this function.
/// @Tparam K the type (Kind) of target
/// @Tparam M the type of multicast operation if it's a multicast target
/// @Tparam V the type of the target's value
/// @param[in]  i_target   HW target to operate on.
/// @param[in]  i_address  Ring address to read from.
/// @param[out] o_data     Buffer that holds ring data read from HW target.
/// @param[in]  i_ringMode Ring operation mode.
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
template< TargetType K, MulticastType M, typename V >
inline ReturnCode getRing(const Target<K, M, V>& i_target,
                          const scanRingId_t i_address,
                          variable_buffer& o_data,
                          const RingMode i_ringMode)
{
    return platGetRing(i_target, i_address, o_data, i_ringMode);
}

/// @brief Platform-level implementation  of putRing()
/// Hardware procedures writers will not call this function.
/// @tparam K template parameter, passed in target.
/// @param[in] i_target   Target to operate on.
/// @param[in] i_address  Ring address to write to.
/// @param[in] i_data     Buffer that contains RS4 compressed ring data
///                       to write into address
/// @param[in] i_ringMode Ring operation mode.
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
template< TargetType K >
inline ReturnCode putRing(const Target<K>& i_target,
                          const scanRingId_t i_address,
                          const variable_buffer& i_data,
                          const RingMode i_ringMode)
{
    return platPutRing(i_target, i_address, i_data, i_ringMode);
}

/// @brief Platform-level implementation  of putRing()
/// @tparam K template parameter, passed in target.
/// @param[in] i_target   Target to operate on.
/// @param[in] i_ringID   Id of the Ring
/// @param[in] i_ringMode Ring operation mode.
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
template< TargetType K >
inline ReturnCode putRing(const Target<K>& i_target,
                          const RingId_t i_ringID,
                          const RingMode i_ringMode = RING_MODE_HEADER_CHECK)
{
    FAPI_DBG("Entering putRing with RingID ...");
    return platPutRing(i_target, i_ringID, i_ringMode);
}

/// @brief Platform-level implementation of modifyRing()
/// @Tparam M the type of multicast operation if it's a multicast target
/// @Tparam V the type of the target's value
/// @param[in] i_target     Target to operate on.
/// @param[in] i_address    Ring address to modify.
/// @param[in] i_data       Buffer that contains RS4 compressed ring data
///                         to be modified.
/// @param[in] i_modifyMode The modify mode (or/and/xor)
/// @param[in] i_ringMode   Ring operation mode.
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
template< TargetType K, MulticastType M, typename V >
inline ReturnCode modifyRing(const Target<K, M, V>& i_target,
                             const scanRingId_t i_address,
                             const variable_buffer& i_data,
                             const ChipOpModifyMode i_modifyMode,
                             const RingMode i_ringMode)
{
    return platModifyRing(i_target,
                          i_address,
                          i_data,
                          i_modifyMode,
                          i_ringMode);
}
#endif

#ifdef FAPI_SUPPORT_MULTI_SCOM
    /// @brief Performs a multiple SCOM operation
    ///        This interface performs multiple SCOM operations on a chip in the
    ///        order specified by the input MultiScom object.
    ///        See fapiMultiScom.H for details of how to populate the MultiScom
    ///        object with SCOM operations.
    ///
    /// @tparam K template parameter, passed in target.
    /// @param[in]     i_target Target to operate on.
    /// @param[in,out] io_multiScomObj Reference to a MultiScom object,
    ///                                pre-populated with SingleScomInfo entries
    ///                                to perform multiple SCOMs on input target
    /// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
    ///
    /// @note   This is a synchronous interface and would return after all the
    ///         SCOM operations are completed or on the first failed operation
    ///
    /// @note   SCOMs will be performed in the order they were added to the
    ///         input MultiScom object
    ///
    /// @note   In case of errors, the platform code is responsible to collect
    ///         and add all the required error info and FFDC into the error data
    ///         for debugging
    ///
    /// @note   If the SCOM operations added are specific to a processor chip,
    ///         then the FSI Shift Engine configured in scatter-gather DMA mode
    ///         extension would be used to execute the SCOM operations in a
    ///         performance optimize mode. In this mode, the special
    ///         SCOM_BULK_READ_MODE and SCOM_BULK_WRITE_MODE operations are
    ///         supported that allow a large bulk of SCOM access (in multiple of
    ///         64 bits) for targets that support auto-increment. The
    ///         SCOM_WRITE_UNDER_MASK operation is not supported in this mode
    ///
    /// @note   If the SCOM operations added are specific to a memory buffer
    ///         chip, then the regular SCOM engine is used to execute the SCOM
    ///         operations. SCOM_WRITE_UNDER_MASK operation is supported in
    ///         this mode, but the special SCOM_BULK_READ_MODE and
    ///         SCOM_BULK_WRITE_MODE operations are not supported due to
    ///         hardware limitations.
    ///
    template< TargetType K >
    fapi2::ReturnCode multiScom (const Target<K>& i_target,
                                 MultiScom&  io_multiScomObj)
    {
    }
#endif

    // -------------------------------------------------------------------------
    // NOTE:
    // No spy access in Hostboot
    // -------------------------------------------------------------------------

};

#endif // _FAPI2_HWACCESS_H_
