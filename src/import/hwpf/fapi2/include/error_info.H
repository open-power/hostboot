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
/**
 * @file erro_infor.H
 * @brief Defines the Error Information structures and classes
 */

#ifndef FAPI2_ERRORINFO_H_
#define FAPI2_ERRORINFO_H_

#include <stdint.h>
#include <memory>
#include <vector>
#include <target.H>
#include <assert.h>

namespace fapi2
{
    class ReturnCode;

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
        operator const uint8_t() const
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
    /// @enum Enumeration of firmware traces
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
    }

    ///
    /// @brief Get FFDC Size specialization for fapi2::Target
    ///
    template<>
    inline uint16_t getErrorInfoFfdcSize(const fapi2::Target<TARGET_TYPE_ALL>*)
    {
        return EI_FFDC_SIZE_TARGET;
    }

    ///
    /// @brief Get FFDC Size specialization for ffdc method arguments
    /// @note The ffdc class sets the std::pair when the method is
    /// called so the size has been calculated. All that needs to be
    /// done here is to grab it. We do it this way so the macro definitions
    /// can be the same whether the ffdc class is used or the old-school
    /// locals.
    ///
    template<>
    inline uint16_t getErrorInfoFfdcSize(const fapi2::ffdc_t& i_thing)
    {
        return i_thing.size();
    }

    ///
    /// @class ErrorInfoFfdc
    ///
    /// This class contains a copy of some FFDC data
    ///
    class ErrorInfoFfdc
    {
    public:
        ///
        /// @brief Constructor
        ///
        /// @param[in] i_ffdcId FFDC Identifier (used to decode FFDC)
        /// @param[in] i_pFfdc  Pointer to the FFDC to copy
        /// @param[in] i_size   Size of the FFDC to copy
        ///
        ErrorInfoFfdc(const uint32_t i_ffdcId,
                      const void*    i_pFfdc,
                      const uint32_t i_size);

        ///
        /// @brief Get a pointer to the FfdcData
        ///
        /// @param[out] o_size Reference to uint32_t that is filled in with
        /// the FFDC
        ///                    size
        ///
        /// @return void *. Pointer to the FFDC
        ///
        const void* getData(uint32_t & o_size) const
            {
                o_size = iv_size;
                return iv_pFfdc.get();
            }

        ///
        /// @brief Get a pointer to the FfdcData
        /// @return void *. Pointer to the FFDC
        ///
        void* getData(void) const
            { return iv_pFfdc.get(); }

        ///
        /// @brief Get the FFDC Identifier
        ///
        /// @return uint32_t The FFDC Identifier
        ///
        uint32_t getFfdcId(void) {return iv_ffdcId;}

#ifdef FAPI_CUSTOM_MALLOC
        ///
        /// @brief Overload new operator to use platform-specific allocator
        ///
        /// @param[in] i_sz  Size of memory to allocate in bytes
        ///
        /// @return  Pointer to allocated memory
        ///
        static void* operator new(size_t i_sz);

        ///
        /// @brief Overload delete operator to use platform-specific deallocator
        ///
        /// @param[in] i_ptr Pointer to memory previously allocated with new
        ///
        static void operator delete(void* i_ptr);
#endif

    private:

        // FFDC Identifier
        uint32_t iv_ffdcId;

        // Pointer to the FFDC
        std::shared_ptr<uint8_t> iv_pFfdc;

        // Size of the FFDC
        uint32_t iv_size;

        // Disabled
        ErrorInfoFfdc(const ErrorInfoFfdc &) = delete;
        ErrorInfoFfdc & operator=(const ErrorInfoFfdc &) = delete;
    };

    ///
    /// @struct ErrorInfoHwCallout
    ///
    /// This struct contains hardware to callout
    ///
    struct ErrorInfoHwCallout
    {
        ///
        /// @brief Constructor.
        ///
        /// @param[in] i_hw              Hardware to callout
        /// @param[in] i_calloutPriority Priority of callout
        /// @param[in] i_refTarget       Reference to reference target
        ///
        ErrorInfoHwCallout(
            const HwCallouts::HwCallout i_hw,
            const CalloutPriorities::CalloutPriority i_calloutPriority,
            const Target<TARGET_TYPE_ALL> & i_refTarget);

#ifdef FAPI_CUSTOM_MALLOC
        ///
        /// @brief Overload new operator to use platform-specific allocator
        ///
        /// @param[in] i_sz  Size of memory to allocate in bytes
        ///
        /// @return  Pointer to allocated memory
        ///
        static void* operator new(size_t i_sz);

        ///
        /// @brief Overload delete operator to use platform-specific deallocator
        ///
        /// @param[in] i_ptr Pointer to memory previously allocated with new
        ///
        static void operator delete(void* i_ptr);
#endif

        // The hw to callout
        HwCallouts::HwCallout iv_hw;

        // The callout priority
        CalloutPriorities::CalloutPriority iv_calloutPriority;

        // The reference target (needed for some HW callouts to identify what to
        // callout). The target handle is NULL if there is no reference target.
        Target<TARGET_TYPE_ALL> iv_refTarget;
    };

    ///
    /// @struct ErrorInfoProcedureCallout
    ///
    /// This struct contains a procedure to callout
    ///
    struct ErrorInfoProcedureCallout
    {
        ///
        /// @brief Constructor.
        ///
        /// @param[in] i_procedure        Procedure to callout
        /// @param[in] i_calloutPriority  Priority of callout
        ///
        ErrorInfoProcedureCallout(
            const ProcedureCallouts::ProcedureCallout i_procedure,
            const CalloutPriorities::CalloutPriority i_calloutPriority);

#ifdef FAPI_CUSTOM_MALLOC
        ///
        /// @brief Overload new operator to use platform-specific allocator
        ///
        /// @param[in] i_sz  Size of memory to allocate in bytes
        ///
        /// @return  Pointer to allocated memory
        ///
        static void* operator new(size_t i_sz);

        ///
        /// @brief Overload delete operator to use platform-specific deallocator
        ///
        /// @param[in] i_ptr Pointer to memory previously allocated with new
        ///
        static void operator delete(void* i_ptr);
#endif

        // The procedure to callout
        ProcedureCallouts::ProcedureCallout iv_procedure;

        // The callout priority
        CalloutPriorities::CalloutPriority iv_calloutPriority;
    };

    ///
    /// @struct ErrorInfoBusCallout
    ///
    /// This struct contains a bus to callout
    ///
    struct ErrorInfoBusCallout
    {
        ///
        /// @brief Constructor.
        ///
        /// @param[in] i_target1          Reference to target on one end of the bus
        /// @param[in] i_target2          Reference to target on other end of the bus
        /// @param[in] i_calloutPriority  Priority of callout
        ///
        ErrorInfoBusCallout(
            const Target<TARGET_TYPE_ALL> & i_target1,
            const Target<TARGET_TYPE_ALL> & i_target2,
            const CalloutPriorities::CalloutPriority i_calloutPriority);

#ifdef FAPI_CUSTOM_MALLOC
        ///
        /// @brief Overload new operator to use platform-specific allocator
        ///
        /// @param[in] i_sz  Size of memory to allocate in bytes
        ///
        /// @return  Pointer to allocated memory
        ///
        static void* operator new(size_t i_sz);

        ///
        /// @brief Overload delete operator to use platform-specific deallocator
        ///
        /// @param[in] i_ptr Pointer to memory previously allocated with new
        ///
        static void operator delete(void* i_ptr);
#endif

        // The targets on each end of the bus to callout
        Target<TARGET_TYPE_ALL> iv_target1;
        Target<TARGET_TYPE_ALL> iv_target2;

        // The callout priority
        CalloutPriorities::CalloutPriority iv_calloutPriority;
    };

    ///
    /// @struct ErrorInfoCDG
    ///
    /// This struct contains a target to callout/deconfigure/GARD
    ///
    struct ErrorInfoCDG
    {
        ///
        /// @brief Constructor.
        ///
        /// @param[in] i_target      Reference to the target to c/d/g
        /// @param[in] i_callout     True if Target should be called out
        /// @param[in] i_deconfigure True if Target should be deconfigured
        /// @param[in] i_gard        True if Target should be GARDed
        /// @param[in] i_priority    The priority of any callout
        ///
        ErrorInfoCDG(const Target<TARGET_TYPE_ALL> & i_target,
                     const bool i_callout,
                     const bool i_deconfigure,
                     const bool i_gard,
                     const CalloutPriorities::CalloutPriority i_priority);

#ifdef FAPI_CUSTOM_MALLOC
        ///
        /// @brief Overload new operator to use platform-specific allocator
        ///
        /// @param[in] i_sz  Size of memory to allocate in bytes
        ///
        /// @return  Pointer to allocated memory
        ///
        static void* operator new(size_t i_sz);

        ///
        /// @brief Overload delete operator to use platform-specific deallocator
        ///
        /// @param[in] i_ptr Pointer to memory previously allocated with new
        ///
        static void operator delete(void* i_ptr);
#endif

        // The target to callout/deconfigure/GARD
        Target<TARGET_TYPE_ALL> iv_target;

        // Callout Information
        bool iv_callout;
        CalloutPriorities::CalloutPriority iv_calloutPriority;

        // Deconfigure Information
        bool iv_deconfigure;

        // GARD Information
        bool iv_gard;
    };

    ///
    /// @struct ErrorInfoChildrenCDG
    ///
    /// This struct contains children targets to callout/deconfigure/GARD
    ///
    /// Children by containment can be CDG (chiplets belonging to a parent chip)
    /// e.g.
    /// - PROC_CHIP -> EX_CHIPLET
    /// - MEMBUF_CHIP -> MBA_CHIPLET
    /// Children by affinity can be CDG.
    ///   Any from PROC_CHIP->MCS_CHIPLET->MEMBUF_CHIP->MBA_CHIPLET->DIMM e.g.
    ///   - PROC_CHIP->MEMBUF_CHIP
    ///   - MEMBUF_CHIP->DIMM
    ///   - MBA_CHIPLET->DIMM
    /// Port and Number criteria can be applied to the child target as
    /// detailed in the constructor
    ///
    struct ErrorInfoChildrenCDG
    {
        ///
        /// @brief Constructor.
        ///
        /// @param[in] i_parent      Reference to the parent target
        /// @oaram[in] i_childType   Child target type to c/d/g
        /// @param[in] i_callout     True if Target should be called out
        /// @param[in] i_deconfigure True if Target should be deconfigured
        /// @param[in] i_gard        True if Target should be GARDed
        /// @param[in] i_priority    The priority of any callout
        /// @param[in] i_childPort   Child Port
        ///                            For DIMM children, the MBA port number
        /// @param[in] i_childNum    Child Number
        ///                            For DIMM children, the dimm socket number
        ///                            For Chip children, the chip position
        ///                            For Chiplet children, the chiplet unit pos
        ///
        ErrorInfoChildrenCDG(const Target<TARGET_TYPE_ALL> & i_parentChip,
                             const TargetType i_childType,
                             const bool i_callout,
                             const bool i_deconfigure,
                             const bool i_gard,
                             const CalloutPriorities::CalloutPriority i_priority,
                             const uint8_t i_childPort, const uint8_t i_childNum);

#ifdef FAPI_CUSTOM_MALLOC
        ///
        /// @brief Overload new operator to use platform-specific allocator
        ///
        /// @param[in] i_sz  Size of memory to allocate in bytes
        ///
        /// @return  Pointer to allocated memory
        ///
        static void* operator new(size_t i_sz);

        ///
        /// @brief Overload delete operator to use platform-specific deallocator
        ///
        /// @param[in] i_ptr Pointer to memory previously allocated with new
        ///
        static void operator delete(void* i_ptr);
#endif

        // The parent chip
        Target<TARGET_TYPE_ALL> iv_parent;

        // The child target types to c/d/g
        TargetType iv_childType;

        // Callout Information
        bool iv_callout;
        CalloutPriorities::CalloutPriority iv_calloutPriority;

        // Deconfigure Information
        bool iv_deconfigure;

        // GARD Information
        bool iv_gard;

        // Child Port
        static const uint8_t ALL_CHILD_PORTS = 0xff;
        uint8_t iv_childPort;

        // Child Number
        static const uint8_t ALL_CHILD_NUMBERS = 0xff;
        uint8_t iv_childNumber;
    };

    ///
    /// @struct ErrorInfoCollectTrace
    ///
    /// This struct contains trace ID to add to the error log
    ///
    struct ErrorInfoCollectTrace
    {
        ///
        /// @brief Constructor.
        ///
        /// @param[in] i_trace
        ///
        ErrorInfoCollectTrace(CollectTraces::CollectTrace i_traceId);


#ifdef FAPI_CUSTOM_MALLOC
        ///
        /// @brief Overload new operator to use platform-specific allocator
        ///
        /// @param[in] i_sz  Size of memory to allocate in bytes
        ///
        /// @return  Pointer to allocated memory
        ///
        static void* operator new(size_t i_sz);

        ///
        /// @brief Overload delete operator to use platform-specific deallocator
        ///
        /// @param[in] i_ptr Pointer to memory previously allocated with new
        ///
        static void operator delete(void* i_ptr);
#endif

        // trace
        CollectTraces::CollectTrace iv_eiTraceId;
    };

   ///
   /// @struct ErrorInfo
   ///
   /// This struct defines the error information associated with a fapi2::ffdc
   /// Users are allowed to access the data directly
   ///
    struct ErrorInfo
    {

#ifdef FAPI_CUSTOM_MALLOC
        ///
        /// @brief Overload new operator to use platform-specific allocator
        ///
        /// @param[in] i_sz  Size of memory to allocate in bytes
        ///
        /// @return  Pointer to allocated memory
        ///
        static void* operator new(size_t i_sz);

        ///
        /// @brief Overload delete operator to use platform-specific deallocator
        ///
        /// @param[in] i_ptr Pointer to memory previously allocated with new
        ///
        static void operator delete(void* i_ptr);
#endif

        // Vector of FFDC Data
        std::vector<std::shared_ptr<ErrorInfoFfdc> > iv_ffdcs;
        typedef std::vector<std::shared_ptr<ErrorInfoFfdc> >::iterator
          ErrorInfoFfdcItr_t;
        typedef std::vector<std::shared_ptr<ErrorInfoFfdc> >::const_iterator
          ErrorInfoFfdcCItr_t;

        // Vector of Hardware to callout
        std::vector<std::shared_ptr<ErrorInfoHwCallout> > iv_hwCallouts;
        typedef std::vector<std::shared_ptr<ErrorInfoHwCallout> >::iterator
          ErrorInfoHwCalloutItr_t;
        typedef std::vector<std::shared_ptr<ErrorInfoHwCallout> >::const_iterator
          ErrorInfoHwCalloutCItr_t;

        // Vector of procedures to callout
        std::vector<std::shared_ptr<ErrorInfoProcedureCallout> >
          iv_procedureCallouts;
        typedef std::vector<std::shared_ptr<ErrorInfoProcedureCallout> >
          ::iterator ErrorInfoProcedureCalloutItr_t;
        typedef std::vector<std::shared_ptr<ErrorInfoProcedureCallout> >
          ::const_iterator ErrorInfoProcedureCalloutCItr_t;

        // Vector of buses to callout
        std::vector<std::shared_ptr<ErrorInfoBusCallout> > iv_busCallouts;
        typedef std::vector<std::shared_ptr<ErrorInfoBusCallout> >::iterator
          ErrorInfoBusCalloutItr_t;
        typedef std::vector<std::shared_ptr<ErrorInfoBusCallout> >
          ::const_iterator ErrorInfoBusCalloutCItr_t;

        // Vector of targets to callout/deconfigure/GARD
        std::vector<std::shared_ptr<ErrorInfoCDG> > iv_CDGs;
        typedef std::vector<std::shared_ptr<ErrorInfoCDG> >
          ::iterator ErrorInfoCDGItr_t;
        typedef std::vector<std::shared_ptr<ErrorInfoCDG> >
          ::const_iterator ErrorInfoCDGCItr_t;

        // Vector of children targets to callout/deconfigure/GARD
        std::vector<std::shared_ptr<ErrorInfoChildrenCDG> > iv_childrenCDGs;
        typedef std::vector<std::shared_ptr<ErrorInfoChildrenCDG> >::iterator
          ErrorInfoChildrenCDGItr_t;
        typedef std::vector<std::shared_ptr<ErrorInfoChildrenCDG> >
          ::const_iterator ErrorInfoChildrenCDGCItr_t;

        // Vector of traces to collect
        std::vector<std::shared_ptr<ErrorInfoCollectTrace> > iv_traces;
        typedef std::vector<std::shared_ptr<ErrorInfoCollectTrace> >::iterator
          ErrorInfoCollectTraceItr_t;
        typedef std::vector<std::shared_ptr<ErrorInfoCollectTrace> >
          ::const_iterator ErrorInfoCollectTraceCItr_t;
    };

    ///
    /// @brief Structure representing a single ErrorInfo entry.
    ///
    /// An array of these is passed to the addErrorInfo function when a HWP
    /// generates an error by calling the FAPI_SET_HWP_ERROR macro
    // Why aren't these inherited classes? Saves on allocation overhead.
    // We create an array of ErrorInfoEntries as automatics when we start
    // FFDC collection. If we did this as inherited classes it would either
    // be allocating and deallocating or we'd need to allocate an array of
    // the largest and map each struct in to it. That's messy to do without
    // unions (that's what they're for) so we do it like this. The inherited
    // model would result in a jump table anyway, so we're basically doing
    // all of that by hand to avoid the mess.
    //
    struct ErrorInfoEntryFfdc
    {
        uint8_t  iv_ffdcObjIndex;
        uint16_t iv_ffdcSize;
        uint32_t iv_ffdcId;
        void addErrorInfo(std::shared_ptr<ErrorInfo> i_info,
                          const void* const* i_object) const;
    };

    struct ErrorInfoEntryHwCallout
    {
        uint8_t iv_hw;
        uint8_t iv_calloutPriority;
        uint8_t iv_refObjIndex;
        void addErrorInfo(std::shared_ptr<ErrorInfo> i_info,
                          const void* const* i_object) const;
    };

    struct ErrorInfoEntryProcCallout
    {
        uint8_t iv_procedure;
        uint8_t iv_calloutPriority;
        void addErrorInfo(std::shared_ptr<ErrorInfo> i_info,
                          const void* const* i_object) const;

        ErrorInfoEntryProcCallout(uint8_t i_procedure, uint8_t i_calloutPriority):
            iv_procedure(i_procedure),
            iv_calloutPriority(i_calloutPriority)
            {}

        ErrorInfoEntryProcCallout(void) = default;
    };

    struct ErrorInfoEntryBusCallout
    {
        uint8_t iv_endpoint1ObjIndex;
        uint8_t iv_endpoint2ObjIndex;
        uint8_t iv_calloutPriority;
        void addErrorInfo(std::shared_ptr<ErrorInfo> i_info,
                          const void* const* i_object) const;
    };

    struct ErrorInfoEntryTargetCDG
    {
        uint8_t iv_targetObjIndex;
        uint8_t iv_callout;
        uint8_t iv_deconfigure;
        uint8_t iv_gard;
        uint8_t iv_calloutPriority;
        void addErrorInfo(std::shared_ptr<ErrorInfo> i_info,
                          const void* const* i_object) const;
    };

    struct ErrorInfoEntryChildrenCDG
    {
        uint8_t  iv_parentObjIndex;
        uint8_t  iv_callout;
        uint8_t  iv_deconfigure;
        uint32_t iv_childType;
        uint8_t  iv_childPort;
        uint8_t  iv_childNumber;
        uint8_t  iv_gard;
        uint8_t  iv_calloutPriority;
        void addErrorInfo(std::shared_ptr<ErrorInfo> i_info,
                          const void* const* i_object) const;
    };

    struct ErrorInfoEntryCollectTrace
    {
        uint32_t  iv_eieTraceId;
        void addErrorInfo(std::shared_ptr<ErrorInfo> i_info,
                          const void* const* i_object) const;
    };

    struct ErrorInfoEntry
    {
        uint8_t iv_type; // Value from ErrorInfoType
        union
        {
            ErrorInfoEntryFfdc ffdc;
            ErrorInfoEntryHwCallout hw_callout;
            ErrorInfoEntryProcCallout proc_callout;
            ErrorInfoEntryBusCallout bus_callout;
            ErrorInfoEntryTargetCDG target_cdg;
            ErrorInfoEntryChildrenCDG children_cdg;
            ErrorInfoEntryCollectTrace collect_trace;
        };
        void addErrorInfo(std::shared_ptr<ErrorInfo> i_info,
                          const void* const* i_object) const
            {
                // "unhandled error info type");
                assert(iv_type < EI_LAST_TYPE);

                switch(iv_type)
                {
                case EI_TYPE_FFDC:
                    ffdc.addErrorInfo(i_info, i_object);
                    break;
                case EI_TYPE_HW_CALLOUT:
                    hw_callout.addErrorInfo(i_info, i_object);
                    break;
                case EI_TYPE_PROCEDURE_CALLOUT:
                    proc_callout.addErrorInfo(i_info, i_object);
                    break;
                case EI_TYPE_BUS_CALLOUT:
                    bus_callout.addErrorInfo(i_info, i_object);
                    break;
                case EI_TYPE_CDG:
                    target_cdg.addErrorInfo(i_info, i_object);
                    break;
                case EI_TYPE_CHILDREN_CDG:
                    children_cdg.addErrorInfo(i_info, i_object);
                    break;
                case EI_TYPE_COLLECT_TRACE:
                    collect_trace.addErrorInfo(i_info, i_object);
                    break;
                };
                return;
            }
    };
}

#endif // FAPI2_ERRORINFO_H_
