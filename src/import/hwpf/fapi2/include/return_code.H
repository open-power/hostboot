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

#ifndef FAPI2_NO_FFDC
  #include <ffdc.H>
#endif

namespace fapi2
{
    ///
    /// @brief Class representing a FAPI2 ReturnCode
    ///
    // Remove the inheritance relationship with FirstFailureData if
    // the platform doesn't support FFDC.
#ifdef FAPI2_NO_FFDC
    class ReturnCode
#else
    class ReturnCode : public FirstFailureData<ReturnCode>
#endif
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
#ifdef DOXYGEN
        inline ReturnCode& operator=(const uint64_t& rhs)
        inline ReturnCode& operator=(const ReturnCodes& rhs)
#endif

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
