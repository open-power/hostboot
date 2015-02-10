/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: $                                                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
 *  @file ffdc.H
 *  @brief Defines the FirstFailureData class
 */

#ifndef FAPI2_FFDC_H_
#define FAPI2_FFDC_H_

#include <memory>
#include <hwp_return_codes.H>
#include <plat_trace.H>
#include <error_info.H>
#include <target.H>
#include <assert.h>

using fapi2::TARGET_TYPE_ALL;

namespace fapi2
{
    ///
    /// @brief Check the type of a variable
    ///
    /// This function can be called to check that a variable type is as expected
    /// @note This mechanism will allow for cast ctor's which other static type
    /// checking might not.
    ///
    template<typename T>
    inline
    void checkType(const T &) {}

    class ReturnCode;

    ///
    /// @class FirstFailureData
    ///
    /// This class provides storage and methods for creating and manipulating
    /// FFDC.
    /// It is not needed on all platforms - platforms which need this class have
    /// specified this by forcing their fapi2::ReturnCode to be a subclass of
    /// this class.
    ///
    template< class R = fapi2::ReturnCode >
    class FirstFailureData
    {
    public:

        ///
        /// @brief Default constructor.
        /// @note We don't create our error info be default. It will be created
        /// when its needed in the setHwpError() method. Note that dereferencing
        /// the error info without will create a problem.
        ///
        FirstFailureData(void):
            iv_info( nullptr )
            {}

        ///
        /// @brief Copy Constructor
        ///
        /// @param[in] i_right Reference to FirstFailureData to copy
        /// @note Generates default copy constructor - no deep pointer
        /// copies necessary.
        ///
        FirstFailureData(const FirstFailureData & i_right) = default;

        ///
        /// @brief Destructor
        ///
        ~FirstFailureData(void) = default;

        ///
        /// @brief Assignment Operator.
        ///
        /// @param[in] i_right Reference to FirstFailureData to assign from.
        /// @return Reference to 'this' FirstFailureData
        ///
        FirstFailureData & operator=(const FirstFailureData & i_right) = default;

        ///
        /// @brief Sets a HWP error. Sets the rcValue to the supplied value (from
        ///      the HwpFirstFailureData enumeration) and deletes any
        /// associated data.
        ///
        /// HWP code must call the FAPI_SET_HWP_ERROR macro rather than this
        /// function
        /// directly to generate an error so that any error information is
        /// automatically added to the FirstFailureData
        ///
        /// @param[in] i_rcValue Error value to set
        ///
        inline void _setHwpError(const fapi2::HwpReturnCode i_rcValue)
            {
                FAPI_ERR("_setHwpError: Creating HWP error 0x%x", i_rcValue);
                static_cast<R*>(this)->operator=(i_rcValue);

                // Forget about any associated data (this is a new error)
                iv_info.reset(new ErrorInfo());
            }

        ///
        /// @brief Get a pointer to any PlatData. FirstFailureData is still
        ///        responsible for deletion of the data. The caller must not
        ///        delete
        ///
        /// This is called by PLAT. The expected use-case is to get a pointer to
        /// a platform error log. The data pointer should be used immediately in
        /// the same thread.
        ///
        /// @return void *. Pointer to any PlatData. If NULL then no data
        ///
        void* getData(void) const;

        ///
        /// @brief Get a pointer to any PlatData and release ownership from
        ///      FirstFailureData. The caller is responsible for deletion.
        ///
        /// This is called by PLAT. The expected use-case is to retrieve a
        /// platform error log.
        ///
        /// @return void*. Pointer to any PlatData. If NULL then no data
        ///
        void* releaseData(void);

        ///
        /// @brief Add ErrorInfo
        ///
        /// This is called by the FAPI_SET_HWP_ERROR and macro to add ErrorInfo
        /// to the FirstFailureData when a HWP generates an error. The function
        /// is designed to add all the ErrorInfo at once rather than the
        /// FAPI_SET_HWP_ERROR macro making multiple function calls to add each
        /// piece of ErrorInfo individually in order to minimize code size
        ///
        /// @param[in] i_pObjects Pointer to array of const pointers to const
        ///     objects that are referred to by ErrorInfoEntry objects
        /// @param[in] i_pEntries Pointer to array of ErrorInfoEntry objects
        ///     defining the ErrorInfo that needs to be added
        /// @param[in] i_count    Number of ErrorInfoEntry entries
        ///
        void addErrorInfo(const void* const * i_pObjects,
                          const ErrorInfoEntry* i_pEntries,
                          const uint8_t i_count);

        ///
        /// @brief Get a pointer to any ErrorInfo
        ///
        /// This is called by PLAT to find information about an error
        ///
        /// @return ErrorInfo *. Pointer to any ErrorInfo. If NULL then no info
        ///
        inline const fapi2::ErrorInfo* getErrorInfo(void) const
            { return iv_info.get(); }

        ///
        /// @brief Forgets about any associated data (PlatData and ErrorInfo)
        ///
        /// If this is the only FirstFailureData pointing to the data then the
        /// data is deleted
        ///
        inline void forgetData(void)
            { iv_info = nullptr; }

    private:

        // Pointer to the data
        std::shared_ptr<ErrorInfo> iv_info;
    };

};
#endif // FAPI2_FFDC_H_
