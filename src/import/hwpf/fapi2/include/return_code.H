/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: $                                                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
 * @file return_code.H
 * @brief definitions for fapi2 return codes
 */

#ifndef __FAPI2_RETURN_CODE__
#define __FAPI2_RETURN_CODE__

#include <stdint.h>

// Remove this for platforms which don't support FFDC
#include <ffdc.H>

///
/// @brief Set HWP Error macro
///
/// This macro should be used by a HWP to create an error. The ReturnCode's
/// internal return code is set and any error information in the Error XML file
/// is added to the ReturnCode
///
#define FAPI_SET_HWP_ERROR(RC, ERROR) \
    RC._setHwpError(fapi2::ERROR); \
    ERROR##_CALL_FUNCS_TO_COLLECT_FFDC(RC); \
    ERROR##_CALL_FUNCS_TO_COLLECT_REG_FFDC(RC); \
    ERROR##_ADD_ERROR_INFO(RC)

///
/// @brief Add info to HWP Error macro
///
/// This macro should be used by an FFDC HWP to add error information from an
/// Error XML file to an existing error.
///
#define FAPI_ADD_INFO_TO_HWP_ERROR(RC, ERROR) \
    ERROR##_CALL_FUNCS_TO_COLLECT_FFDC(RC); \
    ERROR##_CALL_FUNCS_TO_COLLECT_REG_FFDC(RC); \
    ERROR##_ADD_ERROR_INFO(RC)

namespace fapi2
{
    ///
    /// @brief Enumeration of return codes
    ///
    enum ReturnCodes
    {
        ///< Success
        FAPI2_RC_SUCCESS = 0,

        // Flag bits indicating which code generated the error.
        FAPI2_RC_FAPI2_MASK = 0x04000000, ///< FAPI2 mask
        FAPI2_RC_PLAT_MASK =  0x02000000, ///< Platform mask
        FAPI2_RC_HWP_MASK =   0x00000000, ///< HWP mask

        //
        // FAPI generated return codes
        //

        FAPI2_RC_INVALID_ATTR_GET            = FAPI2_RC_FAPI2_MASK | 0x01,
        ///< Initfile requested an attribute with an invalid attribute ID

        FAPI2_RC_INVALID_CHIP_EC_FEATURE_GET = FAPI2_RC_FAPI2_MASK | 0x02,
        ///< HWP requested a chip EC feature with an invalid attribute ID

        FAPI2_RC_INVALID_MULTISCOM_LENGTH    = FAPI2_RC_FAPI2_MASK | 0x03,
        ///< Invalid multiscom parameters

        FAPI2_RC_INVALID_PARAMETER           = FAPI2_RC_FAPI2_MASK | 0x04,
        ///< Invalid parameters to a FAPI2 function

        FAPI2_RC_OVERFLOW                    = FAPI2_RC_FAPI2_MASK | 0x05,
        ///< Overflow condition, typically a buffer operation

        FAPI2_RC_FALSE                       = FAPI2_RC_FAPI2_MASK | 0x06,
        ///< The logical opposite of SUCCESS. Needed where procedures want
        ///< a multi-bool type of operation (e.g., true, false, scom error)

        //
        // PLAT generated return codes. Additional details may be contained in
        // ReturnCode platData (this can only be looked at by PLAT code)
        //

        FAPI2_RC_PLAT_ERR_SEE_DATA   = FAPI2_RC_PLAT_MASK | 0x01,
        ///< Generic platform error

        FAPI2_RC_PLAT_ERR_ADU_LOCKED = FAPI2_RC_PLAT_MASK | 0x02,
        ///< Operation to AlterDisplay unit failed because it is locked

        FAPI2_RC_PLAT_NOT_SUPPORTED_AT_RUNTIME = FAPI2_RC_PLAT_MASK | 0x03,
        ///< Operation not supported by HB runtime
    };

    ///
    /// @brief Class representing a FAPI2 ReturnCode
    ///
    /// @note Remove the inheritance relationship with FirstFailureData if
    /// the platform doesn't support FFDC.
    class ReturnCode : public FirstFailureData<ReturnCode>
    {
    public:

        ///
        /// @brief Constructor.
        /// @param[in] i_rc the rc to set
        ///
        ReturnCode(const uint64_t i_rc = FAPI2_RC_SUCCESS):
            iv_rc(i_rc)
            {};

        ///
        /// @brief integral type conversion function. Returns the error code
        /// @return The error code
        ///
        inline operator uint64_t() const { return iv_rc; }

        ///
        /// @brief Returns true iff iv_rc == SUCCESS
        /// @return true or false
        ///
        inline operator bool() const { return iv_rc == FAPI2_RC_SUCCESS; }

        ///
        /// @brief Assignement operator
        ///
        inline ReturnCode& operator=(const uint64_t& rhs)
            {
                iv_rc = rhs;
                return *this;
            }

        inline ReturnCode& operator=(const ReturnCodes& rhs)
            {
                iv_rc = rhs;
                return *this;
            }

        inline bool operator==(const uint64_t& rhs) const
            { return rhs == iv_rc; }

        inline bool operator==(const ReturnCodes& rhs) const
            { return rhs == iv_rc; }

        inline bool operator!=(const uint64_t& rhs) const
            { return rhs != iv_rc; }

        inline bool operator!=(const ReturnCodes& rhs) const
            { return rhs != iv_rc; }

    private:
        uint64_t iv_rc;
    };

    /// This implementation assumes no exception handling and leverages thread-local
    /// storage. For platforms without thread support, a global variable will
    /// suffice for the error state.
    extern thread_local ReturnCode current_err;      /// the current error state
    extern thread_local uint64_t pib_error_mask;     /// the pib mask
    extern thread_local uint64_t operational_state;  /// the operational mode

}

#endif
