/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/fapi2/include/error_info.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
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
/// @file error_info.H
/// @brief Defines the Error Information structures and classes
///

#ifndef FAPI2_ERRORINFO_H_
#define FAPI2_ERRORINFO_H_

#include <stdint.h>
#ifndef __PPE__
    #include <memory>
#endif
#include <vector>
#include <target.H>
#include <error_info_defs.H>

namespace fapi2
{

#if defined(MINIMUM_FFDC) && !defined(FAPI2_NO_FFDC)
// convert generic type to uint64_t
template<typename T>
inline uint64_t convertType( T& i_value )
{
    // for simplicity sake, all FFDC chunks from the SBE
    // are going to be sent as a uint64_t
    return static_cast<uint64_t>(i_value);
};

// convert platform target handle to a uint64_t
template<fapi2::TargetType T, fapi2::MulticastType M>
inline uint64_t convertType( const fapi2::Target<T, M>& i_value)
{
    // send the target type and instance as ffdc they will be used
    // to instantiate a target before logging the ffdc data
    // 0:47     = Target Type
    // 48:63    = instance

    uint64_t ret_value = static_cast<uint64_t>(i_value.get().getFapiTargetType());

    //TODO: Check if sending the multicast bit is actually required. I do not
    //see any HWP attempting to callect the FFDC on the multicasted target. HWSV
    //is not even expecting the multicast bit to be present.

    //setting multicast bit at MSB of target type
    ret_value = (ret_value | static_cast<uint64_t>(i_value.get().fields.is_multicast) << 47);

    ret_value = ret_value << 16;

    //Add the target instance value.
    ret_value = ret_value | (i_value.get().getTargetInstance() & 0xFFFF);

    return ret_value;
};
#endif

#if !defined(FAPI2_NO_FFDC) && !defined(MINIMUM_FFDC)
// forward fapi2::Assert()
extern void Assert(bool);

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
        /// the FFDC size
        ///
        /// @return void *. Pointer to the FFDC
        ///
        inline const void* getData(uint32_t& o_size) const
        {
            o_size = iv_size;
            return iv_pFfdc.get();
        }

        ///
        /// @brief Get a pointer to the FfdcData
        /// @return void *. Pointer to the FFDC
        ///
        inline void* getData(void) const
        {
            return iv_pFfdc.get();
        }

        ///
        /// @brief Get the FFDC Identifier
        ///
        /// @return uint32_t The FFDC Identifier
        ///
        inline uint32_t getFfdcId(void)
        {
            return iv_ffdcId;
        }

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
        ErrorInfoFfdc(const ErrorInfoFfdc&) = delete;
        ErrorInfoFfdc& operator=(const ErrorInfoFfdc&) = delete;
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
    /// @param[in] i_clkPos          Clock position
    ///
    ErrorInfoHwCallout(
        const HwCallouts::HwCallout i_hw,
        const CalloutPriorities::CalloutPriority i_calloutPriority,
        const Target<TARGET_TYPE_ALL>& i_refTarget,
        const uint8_t i_clkPos = CLOCK_POS_UNDEF);

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

    // Clock position
    uint8_t iv_clkPos;
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
        const Target<TARGET_TYPE_ALL>& i_target1,
        const Target<TARGET_TYPE_ALL>& i_target2,
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
    /// @param[in] i_gardType    Type of GARD
    ///
    ErrorInfoCDG(const Target<TARGET_TYPE_ALL>& i_target,
                 const bool i_callout,
                 const bool i_deconfigure,
                 const bool i_gard,
                 const CalloutPriorities::CalloutPriority i_priority,
                 const GardTypes::GardType i_gardType);

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

    // GARD Type
    GardTypes::GardType iv_gardType;
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
    /// @param[in] i_parentChip  Reference to the parent target
    /// @param[in] i_childType   Child target type to c/d/g
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
    ErrorInfoChildrenCDG(const Target<TARGET_TYPE_ALL>& i_parentChip,
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
    /// @param[in] i_traceId
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

    // Vector of Hardware to callout
    std::vector<std::shared_ptr<ErrorInfoHwCallout> > iv_hwCallouts;

    // Vector of procedures to callout
    std::vector<std::shared_ptr<ErrorInfoProcedureCallout> >
    iv_procedureCallouts;

    // Vector of buses to callout
    std::vector<std::shared_ptr<ErrorInfoBusCallout> > iv_busCallouts;

    // Vector of targets to callout/deconfigure/GARD
    std::vector<std::shared_ptr<ErrorInfoCDG> > iv_CDGs;

    // Vector of children targets to callout/deconfigure/GARD
    std::vector<std::shared_ptr<ErrorInfoChildrenCDG> > iv_childrenCDGs;

    // Vector of traces to collect
    std::vector<std::shared_ptr<ErrorInfoCollectTrace> > iv_traces;
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

///
/// @brief Structure representing a hardware callout
///
struct ErrorInfoEntryHwCallout
{
    uint8_t iv_hw;
    uint8_t iv_calloutPriority;
    uint8_t iv_refObjIndex;
    uint8_t iv_clkPos;
    void addErrorInfo(std::shared_ptr<ErrorInfo> i_info,
                      const void* const* i_object) const;
};

///
/// @brief Structure representing a procedure callout
///
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

///
/// @brief Structure representing a bus callout
///
struct ErrorInfoEntryBusCallout
{
    uint8_t iv_endpoint1ObjIndex;
    uint8_t iv_endpoint2ObjIndex;
    uint8_t iv_calloutPriority;
    void addErrorInfo(std::shared_ptr<ErrorInfo> i_info,
                      const void* const* i_object) const;
};

///
/// @brief Structure representing a target callout
///
struct ErrorInfoEntryTargetCDG
{
    uint8_t iv_targetObjIndex;
    uint8_t iv_callout;
    uint8_t iv_deconfigure;
    uint8_t iv_gard;
    uint8_t iv_calloutPriority;
    uint8_t iv_gardType;
    void addErrorInfo(std::shared_ptr<ErrorInfo> i_info,
                      const void* const* i_object) const;
};

///
/// @brief Structure representing a child callout
///
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

///
/// @brief Structure representing collected trace information
///
struct ErrorInfoEntryCollectTrace
{
    uint32_t  iv_eieTraceId;
    void addErrorInfo(std::shared_ptr<ErrorInfo> i_info,
                      const void* const* i_object) const;
};

///
/// @brief Union of all the error info types
///
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

    ///
    /// @brief Add error information to the FFDC object
    /// @param[in] i_info a shared pointer to the error info
    /// @param[in] i_object the list of ffdc objects being collected
    ///
    void addErrorInfo(std::shared_ptr<ErrorInfo> i_info,
                      const void* const* i_object) const
    {
        // "unhandled error info type");
        fapi2::Assert(iv_type < EI_LAST_TYPE);

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
#endif //  !defined(FAPI2_NO_FFDC) && !defined(MINIMUM_FFDC)
}

#if !defined(FAPI2_NO_FFDC) && !defined(MINIMUM_FFDC)
    //explicitly declare for space as these templates are used everywhere
    extern template class std::shared_ptr<fapi2::ErrorInfo>;
    extern template class std::shared_ptr<fapi2::ErrorInfoFfdc>;
#endif

#endif // FAPI2_ERRORINFO_H_
