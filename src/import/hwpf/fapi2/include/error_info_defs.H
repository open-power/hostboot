/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source:  $                                                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2015                        */
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
/// @file error_info_defs.H
/// @brief Defines to support the Error Information class
///

#ifndef FAPI2_ERRORINFO_DEFS_H_
#define FAPI2_ERRORINFO_DEFS_H_

#include <stdint.h>
#include <target.H>
#include <variable_buffer.H>
#include <assert.h>

#include <iostream>

namespace fapi2
{
    ///
    /// @brief Type to hold the ffdc element in the ffdc class
    /// Needed so that the size can be squirled away before the
    /// macro is called.
    ///
    class ffdc_t
    {
    public:
        ffdc_t(void)
            {}

        operator const void*() const { return iv_value.first; }
        operator uint8_t() const
            { return *(reinterpret_cast<const uint8_t*>(iv_value.first)); }

        int16_t size(void) const { return iv_value.second; }
        int16_t& size(void) { return iv_value.second; }

        const void* ptr(void) const { return iv_value.first; }
        const void*& ptr(void) { return iv_value.first; }

    private:
        std::pair<const void*, int16_t> iv_value;
    };

    ///
    /// @brief Enumeration of ErrorInfo FFDC sizes that are used to indicate a
    ///        special type that cannot simply be memcopied
    enum ErrorInfoFfdcSize
    {
        EI_FFDC_SIZE_BUF    = 0xffff,   // fapi2::buffer<T>
        EI_FFDC_SIZE_TARGET = 0xfffe,   // fapi2::Target
        EI_FFDC_SIZE_VBUF   = 0xfffd,   // fapi2::variable_buffer
        EI_FFDC_MAX_SIZE    = 0x1000,   // Limit regular FFDC capture to 4kb
    };

    ///
    /// @brief Enumeration of error log severity.
    ///
    enum errlSeverity_t
    {
        FAPI2_ERRL_SEV_UNDEFINED     = 0x00, /// Used internally by ffdc mechanism
        FAPI2_ERRL_SEV_RECOVERED     = 0x10, /// Not seen by customer
        FAPI2_ERRL_SEV_PREDICTIVE    = 0x20, /// Error recovered but customer will see
        FAPI2_ERRL_SEV_UNRECOVERABLE = 0x40  /// Unrecoverable, general
    };

    ///
    /// @brief Enumeration of ErrorInfo types
    ///
    enum ErrorInfoType
    {
        EI_TYPE_FFDC              = 0,
        EI_TYPE_HW_CALLOUT        = 1,
        EI_TYPE_PROCEDURE_CALLOUT = 2,
        EI_TYPE_BUS_CALLOUT       = 3,
        EI_TYPE_CDG               = 4, // Target Callout/Deconfig/GARD
        EI_TYPE_CHILDREN_CDG      = 5, // Children Callout/Deconfig/GARD
        EI_TYPE_COLLECT_TRACE     = 6,
        EI_LAST_TYPE              = EI_TYPE_COLLECT_TRACE + 1,
    };

    ///
    /// @enum HwCallout
    ///
    /// This enumeration defines the possible Hardware Callouts that are not
    /// represented by fapi2::Targets
    ///
    /// Note that platform code may depend on the enum values starting at 0 and
    /// incrementing in order to efficiently convert to a platform callout value
    /// so do not reorder without consulting all platforms
    ///
    namespace HwCallouts
    {
        enum HwCallout
        {
            // Where indicated, a HW Callout in FAPI Error XML must include a
            // reference target that is used to identify the HW. e.g. for
            // TOD_CLOCK, the proc chip that the clock is attached to must be
            // specified
            TOD_CLOCK           = 0, // Include proc-chip ref (or child chiplet)
            MEM_REF_CLOCK       = 1, // Include membuf-chip ref (or child chiplet)
            PROC_REF_CLOCK      = 2, // Include proc-chip ref (or child chiplet)
            PCI_REF_CLOCK       = 3, // Include proc-chip ref (or child chiplet)
            FLASH_CONTROLLER_PART      = 4,
            PNOR_PART                  = 5,
            SBE_SEEPROM_PART           = 6,
            VPD_PART                   = 7,
            LPC_SLAVE_PART             = 8,
            GPIO_EXPANDER_PART         = 9,
            SPIVID_SLAVE_PART          = 10,
        };
    }

    ///
    /// @enum ProcedureCallout
    ///
    /// This enumeration defines the possible Procedure Callouts
    /// These instruct the customer/customer-engineer what to do
    ///
    /// Note that platform code may depend on the enum values starting at 0 and
    /// incrementing in order to efficiently convert to a platform callout value
    /// so do not reorder without consulting all platforms
    ///
    namespace ProcedureCallouts
    {
        enum ProcedureCallout
        {
            CODE                  = 0, // Code problem
            LVL_SUPPORT           = 1, // Call next level of support
            MEMORY_PLUGGING_ERROR = 2, // DIMM Plugging error
            BUS_CALLOUT           = 3, // Bus Called Out
        };
    }

    ///
    /// @enum CalloutPriority
    ///
    /// This enumeration defines the possible Procedure and Target callout priorities
    ///
    /// Note that platform code may depend on the enum values starting at 0 and
    /// incrementing in order to efficiently convert to a platform priority value
    /// so do not reorder without consulting all platforms
    ///
    namespace CalloutPriorities
    {
        enum CalloutPriority
        {
            LOW = 0,
            MEDIUM = 1,
            HIGH   = 2,
        };
    }

    ///
    /// @enum Collect Trace
    ///
    /// This enumeration defines the possible firmware traces to collect
    ///
    namespace CollectTraces
    {
        const uint32_t TRACE_SIZE = 256; // limit collected trace size
        enum CollectTrace
        {
            FSI              = 1,
            SCOM             = 2,
            SCAN             = 3,
            MBOX             = 4,
        };
    }

    ///
    /// @brief Get FFDC Size
    ///
    /// This is called by the FAPI_SET_HWP_ERROR macro to find out the size of
    /// FFDC data. If the data is of a special type that is handled differently
    /// than types that are simply memcopied then it is handled by a template
    /// specialization.
    /// If this function template is instantiated with a pointer, the compile
    /// will fail.
    ///
    /// @return uint16_t. Size of the FFDC data
    ///
    template<typename T>
    inline uint16_t getErrorInfoFfdcSize(const T &)
    {
        static_assert(sizeof(T) <= EI_FFDC_MAX_SIZE,
                      "FFDC too large to capture");
        return sizeof(T);
    }

    ///
    /// @brief Compile error if caller tries to get the FFDC size of a pointer
    ///
    template<typename T>
    inline uint16_t getErrorInfoFfdcSize(const T*)
    {
        static_assert(std::is_pointer<T>::value,
                      "pointer passed to getErrorInfoFfdcSize");
        return 0;
    }

    ///
    /// @brief Get FFDC Size specialization for fapi2::Target
    ///
    template<fapi2::TargetType T>
    inline uint16_t getErrorInfoFfdcSize(const fapi2::Target<T>&)
    {
        return EI_FFDC_SIZE_TARGET;
    }

    ///
    /// @brief Get FFDC Size specialization for variable buffers
    ///
    template<>
    inline uint16_t getErrorInfoFfdcSize(const fapi2::variable_buffer& i_thing)
    {
        // Limit a variable buffer to 4kb bytes, and we can memcpy the storage.
        return std::min(static_cast<uint32_t>(EI_FFDC_MAX_SIZE),
                        i_thing.getLength<uint8_t>());
    }

}

#endif // FAPI2_ERRORINFO_DEFS_H_
