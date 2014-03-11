/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/fapi/fapiErrorInfo.H $                   */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: fapiErrorInfo.H,v 1.13 2014/03/12 00:47:58 whs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/hwpf/working/fapi/fapiErrorInfo.H,v $

/**
 *  @file fapiErrorInfo.H
 *
 *  @brief Defines the Error Information structures and classes
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     08/09/2011  Created.
 *                          mjjones     08/24/2011  Added ErrorInfoGard.
 *                          mjjones     09/22/2011  Major updates
 *                          mjjones     03/16/2012  Add FfdcType. Remove copy
 *                                                  ctor and assignment operator
 *                          mjjones     08/14/2012  Merge Callout/Deconfig/Gard
 *                                                  structures into one
 *                          mjjones     09/19/2012  Replace FFDC type with ID
 *                          mjjones     03/22/2013  Support Procedure Callouts
 *                          mjjones     05/20/2013  Support Bus Callouts
 *                          mjjones     06/24/2013  Support Children CDGs
 *                          mjjones     08/26/2013  Support HW Callouts
 *                          rjknight    09/19/2013  Allow callout/deconfigure
 *                                                  /gard of DIMM(s) related
 *                                                  to MBA
 *                          whs         03/11/2014  Add FW traces to error logs
 */

#ifndef FAPIERRORINFO_H_
#define FAPIERRORINFO_H_

#include <stdint.h>
#include <vector>
#include <fapiTarget.H>

namespace fapi
{

/**
 * @enum HwCallout
 *
 * This enumeration defines the possible Hardware Callouts that are not
 * represented by fapi::Targets
 *
 * Note that platform code may depend on the enum values starting at 0 and
 * incrementing in order to efficiently convert to a platform callout value
 * so do not reorder without consulting all platforms
 */
namespace HwCallouts
{
enum HwCallout
{
    // Where indicated, a HW Callout in FAPI Error XML must include a reference
    // target that is used to identify the HW. e.g. for TOD_CLOCK, the proc chip
    // that the clock is attached to must be specified
    TOD_CLOCK             = 0, // Include proc-chip ref (or child chiplet)
    MEM_REF_CLOCK         = 1, // Include membuf-chip ref (or child chiplet)
    PROC_REF_CLOCK        = 2, // Include proc-chip ref (or child chiplet)
    PCI_REF_CLOCK         = 3, // Include proc-chip ref (or child chiplet)
};
}

/**
 * @enum ProcedureCallout
 *
 * This enumeration defines the possible Procedure Callouts
 * These instruct the customer/customer-engineer what to do
 *
 * Note that platform code may depend on the enum values starting at 0 and
 * incrementing in order to efficiently convert to a platform callout value
 * so do not reorder without consulting all platforms
 */
namespace ProcedureCallouts
{
enum ProcedureCallout
{
    CODE                  = 0, // Code problem
    LVL_SUPPORT           = 1, // Call next level of support
    MEMORY_PLUGGING_ERROR = 2, // DIMM Plugging error
};
}

/**
 * @enum CalloutPriority
 *
 * This enumeration defines the possible Procedure and Target callout priorities
 *
 * Note that platform code may depend on the enum values starting at 0 and
 * incrementing in order to efficiently convert to a platform priority value
 * so do not reorder without consulting all platforms
 */
namespace CalloutPriorities
{
enum CalloutPriority
{
    LOW    = 0,
    MEDIUM = 1,
    HIGH   = 2,
};
}

/**
 * @enum Enumeration of firmware traces
 *
 * This enumeration defines the possible firmware traces to collect
 */
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

/**
 * @class ErrorInfoFfdc
 *
 * This class contains a copy of some FFDC data
 */
class ErrorInfoFfdc
{
public:
    /**
     * @brief Constructor
     *
     * @param[in] i_ffdcId FFDC Identifier (used to decode FFDC)
     * @param[in] i_pFfdc  Pointer to the FFDC to copy
     * @param[in] i_size   Size of the FFDC to copy
     */
    ErrorInfoFfdc(const uint32_t i_ffdcId,
                  const void * i_pFfdc,
                  const uint32_t i_size);

    /**
     * @brief Destructor
     */
    ~ErrorInfoFfdc();

    /**
     * @brief Get a pointer to the FfdcData
     *
     * @param[out] o_size Reference to uint32_t that is filled in with the FFDC
     *                    size
     *
     * @return void *. Pointer to the FFDC
     */
    const void * getData(uint32_t & o_size) const;

    /**
     * @brief Get the FFDC Identifier
     *
     * @return uint32_t The FFDC Identifier
     */
    uint32_t getFfdcId() {return iv_ffdcId;}

#ifdef FAPI_CUSTOM_MALLOC
    /**
     * @brief Overload new operator to use platform-specific allocator
     *
     * @param[in] i_sz  Size of memory to allocate in bytes
     *
     * @return  Pointer to allocated memory
    */
    static void * operator new(size_t i_sz);

    /**
     * @brief Overload delete operator to use platform-specific deallocator
     *
     * @param[in] i_ptr Pointer to memory previously allocated with new
     */
    static void operator delete(void * i_ptr);
#endif

private:

    // FFDC Identifier
    uint32_t iv_ffdcId;

    // Pointer to the FFDC
    uint8_t * iv_pFfdc;

    // Size of the FFDC
    uint32_t iv_size;

    // Disabled
    ErrorInfoFfdc(const ErrorInfoFfdc &);
    ErrorInfoFfdc & operator=(const ErrorInfoFfdc &);
};

/**
 * @struct ErrorInfoHwCallout
 *
 * This struct contains hardware to callout
 */
struct ErrorInfoHwCallout
{
    /**
     * @brief Constructor.
     *
     * @param[in] i_hw              Hardware to callout
     * @param[in] i_calloutPriority Priority of callout
     * @param[in] i_refTarget       Reference to reference target
     */
    ErrorInfoHwCallout(
        const HwCallouts::HwCallout i_hw,
        const CalloutPriorities::CalloutPriority i_calloutPriority,
        const Target & i_refTarget);

#ifdef FAPI_CUSTOM_MALLOC
    /**
     * @brief Overload new operator to use platform-specific allocator
     *
     * @param[in] i_sz  Size of memory to allocate in bytes
     *
     * @return  Pointer to allocated memory
     */
    static void * operator new(size_t i_sz);

    /**
     * @brief Overload delete operator to use platform-specific deallocator
     *
     * @param[in] i_ptr Pointer to memory previously allocated with new
     */
    static void operator delete(void * i_ptr);
#endif

    // The hw to callout
    HwCallouts::HwCallout iv_hw;

    // The callout priority
    CalloutPriorities::CalloutPriority iv_calloutPriority;

    // The reference target (needed for some HW callouts to identify what to
    // callout). The target handle is NULL if there is no reference target.
    Target iv_refTarget;
};

/**
 * @struct ErrorInfoProcedureCallout
 *
 * This struct contains a procedure to callout
 */
struct ErrorInfoProcedureCallout
{
    /**
     * @brief Constructor.
     *
     * @param[in] i_procedure        Procedure to callout
     * @param[in] i_calloutPriority  Priority of callout
     */
    ErrorInfoProcedureCallout(
        const ProcedureCallouts::ProcedureCallout i_procedure,
        const CalloutPriorities::CalloutPriority i_calloutPriority);

#ifdef FAPI_CUSTOM_MALLOC
    /**
     * @brief Overload new operator to use platform-specific allocator
     *
     * @param[in] i_sz  Size of memory to allocate in bytes
     *
     * @return  Pointer to allocated memory
     */
    static void * operator new(size_t i_sz);

    /**
     * @brief Overload delete operator to use platform-specific deallocator
     *
     * @param[in] i_ptr Pointer to memory previously allocated with new
     */
    static void operator delete(void * i_ptr);
#endif

    // The procedure to callout
    ProcedureCallouts::ProcedureCallout iv_procedure;

    // The callout priority
    CalloutPriorities::CalloutPriority iv_calloutPriority;
};

/**
 * @struct ErrorInfoBusCallout
 *
 * This struct contains a bus to callout
 */
struct ErrorInfoBusCallout
{
    /**
     * @brief Constructor.
     *
     * @param[in] i_target1          Reference to target on one end of the bus
     * @param[in] i_target2          Reference to target on other end of the bus
     * @param[in] i_calloutPriority  Priority of callout
     */
    ErrorInfoBusCallout(
        const Target & i_target1,
        const Target & i_target2,
        const CalloutPriorities::CalloutPriority i_calloutPriority);

#ifdef FAPI_CUSTOM_MALLOC
    /**
     * @brief Overload new operator to use platform-specific allocator
     *
     * @param[in] i_sz  Size of memory to allocate in bytes
     *
     * @return  Pointer to allocated memory
     */
    static void * operator new(size_t i_sz);

    /**
     * @brief Overload delete operator to use platform-specific deallocator
     *
     * @param[in] i_ptr Pointer to memory previously allocated with new
     */
    static void operator delete(void * i_ptr);
#endif

    // The targets on each end of the bus to callout
    Target iv_target1;
    Target iv_target2;

    // The callout priority
    CalloutPriorities::CalloutPriority iv_calloutPriority;
};

/**
 * @struct ErrorInfoCDG
 *
 * This struct contains a target to callout/deconfigure/GARD
 */
struct ErrorInfoCDG
{
    /**
     * @brief Constructor.
     *
     * @param[in] i_target      Reference to the target to c/d/g
     * @param[in] i_callout     True if Target should be called out
     * @param[in] i_deconfigure True if Target should be deconfigured
     * @param[in] i_gard        True if Target should be GARDed
     * @param[in] i_priority    The priority of any callout
     */
    ErrorInfoCDG(const Target & i_target,
                 const bool i_callout,
                 const bool i_deconfigure,
                 const bool i_gard,
                 const CalloutPriorities::CalloutPriority i_priority);

#ifdef FAPI_CUSTOM_MALLOC
    /**
     * @brief Overload new operator to use platform-specific allocator
     *
     * @param[in] i_sz  Size of memory to allocate in bytes
     *
     * @return  Pointer to allocated memory
     */
    static void * operator new(size_t i_sz);

    /**
     * @brief Overload delete operator to use platform-specific deallocator
     *
     * @param[in] i_ptr Pointer to memory previously allocated with new
     */
    static void operator delete(void * i_ptr);
#endif

    // The target to callout/deconfigure/GARD
    Target iv_target;

    // Callout Information
    bool iv_callout;
    CalloutPriorities::CalloutPriority iv_calloutPriority;

    // Deconfigure Information
    bool iv_deconfigure;

    // GARD Information
    bool iv_gard;
};

/**
 * @struct ErrorInfoChildrenCDG
 *
 * This struct contains children targets to callout/deconfigure/GARD
 *
 * Children by containment can be CDG (chiplets belonging to a parent chip) e.g.
 * - PROC_CHIP -> EX_CHIPLET
 * - MEMBUF_CHIP -> MBA_CHIPLET
 * Children by affinity can be CDG.
 *   Any from PROC_CHIP->MCS_CHIPLET->MEMBUF_CHIP->MBA_CHIPLET->DIMM e.g.
 *   - PROC_CHIP->MEMBUF_CHIP
 *   - MEMBUF_CHIP->DIMM
 *   - MBA_CHIPLET->DIMM
 * Port and Number criteria can be applied to the child target as
 * detailed in the constructor
 */
struct ErrorInfoChildrenCDG
{
    /**
     * @brief Constructor.
     *
     * @param[in] i_parent      Reference to the parent target
     * @oaram[in] i_childType   Child target type to c/d/g
     * @param[in] i_callout     True if Target should be called out
     * @param[in] i_deconfigure True if Target should be deconfigured
     * @param[in] i_gard        True if Target should be GARDed
     * @param[in] i_priority    The priority of any callout
     * @param[in] i_childPort   Child Port
     *                            For DIMM children, the MBA port number
     * @param[in] i_childNum    Child Number
     *                            For DIMM children, the dimm socket number
     *                            For Chip children, the chip position
     *                            For Chiplet children, the chiplet unit pos
     */
    ErrorInfoChildrenCDG(const Target & i_parentChip,
                         const TargetType i_childType,
                         const bool i_callout,
                         const bool i_deconfigure,
                         const bool i_gard,
                         const CalloutPriorities::CalloutPriority i_priority,
                         const uint8_t i_childPort, const uint8_t i_childNum);

#ifdef FAPI_CUSTOM_MALLOC
    /**
     * @brief Overload new operator to use platform-specific allocator
     *
     * @param[in] i_sz  Size of memory to allocate in bytes
     *
     * @return  Pointer to allocated memory
    */
    static void * operator new(size_t i_sz);

    /**
     * @brief Overload delete operator to use platform-specific deallocator
     *
     * @param[in] i_ptr Pointer to memory previously allocated with new
     */
    static void operator delete(void * i_ptr);
#endif

    // The parent chip
    Target iv_parent;

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

/**
 * @struct ErrorInfoCollectTrace
 *
 * This struct contains trace ID to add to the error log
 */
struct ErrorInfoCollectTrace
{
    /**
     * @brief Constructor.
     *
     * @param[in] i_trace
     */
    ErrorInfoCollectTrace(CollectTraces::CollectTrace i_traceId);

#ifdef FAPI_CUSTOM_MALLOC
    /**
     * @brief Overload new operator to use platform-specific allocator
     *
     * @param[in] i_sz  Size of memory to allocate in bytes
     *
     * @return  Pointer to allocated memory
     */
    static void * operator new(size_t i_sz);

    /**
     * @brief Overload delete operator to use platform-specific deallocator
     *
     * @param[in] i_ptr Pointer to memory previously allocated with new
     */
    static void operator delete(void * i_ptr);
#endif

    // trace
    CollectTraces::CollectTrace iv_eiTraceId;
};

/**
 * @struct ErrorInfo
 *
 * This struct defines the error information associated with a fapi::ReturnCode
 * Users are allowed to access the data directly
 */
struct ErrorInfo
{
    /**
     * @brief Destructor.
     */
    ~ErrorInfo();

#ifdef FAPI_CUSTOM_MALLOC
    /**
     * @brief Overload new operator to use platform-specific allocator
     *
     * @param[in] i_sz  Size of memory to allocate in bytes
     *
     * @return  Pointer to allocated memory
     */
    static void * operator new(size_t i_sz);

    /**
     * @brief Overload delete operator to use platform-specific deallocator
     *
     * @param[in] i_ptr Pointer to memory previously allocated with new
     */
    static void operator delete(void * i_ptr);
#endif

    // Vector of FFDC Data
    std::vector<ErrorInfoFfdc *> iv_ffdcs;
    typedef std::vector<ErrorInfoFfdc *>::iterator ErrorInfoFfdcItr_t;
    typedef std::vector<ErrorInfoFfdc *>::const_iterator ErrorInfoFfdcCItr_t;

    // Vector of Hardware to callout
    std::vector<ErrorInfoHwCallout *> iv_hwCallouts;
    typedef std::vector<ErrorInfoHwCallout *>::iterator
        ErrorInfoHwCalloutItr_t;
    typedef std::vector<ErrorInfoHwCallout *>::const_iterator
        ErrorInfoHwCalloutCItr_t;

    // Vector of procedures to callout
    std::vector<ErrorInfoProcedureCallout *> iv_procedureCallouts;
    typedef std::vector<ErrorInfoProcedureCallout *>::iterator
        ErrorInfoProcedureCalloutItr_t;
    typedef std::vector<ErrorInfoProcedureCallout *>::const_iterator
        ErrorInfoProcedureCalloutCItr_t;

    // Vector of buses to callout
    std::vector<ErrorInfoBusCallout *> iv_busCallouts;
    typedef std::vector<ErrorInfoBusCallout *>::iterator
        ErrorInfoBusCalloutItr_t;
    typedef std::vector<ErrorInfoBusCallout *>::const_iterator
        ErrorInfoBusCalloutCItr_t;

    // Vector of targets to callout/deconfigure/GARD
    std::vector<ErrorInfoCDG *> iv_CDGs;
    typedef std::vector<ErrorInfoCDG *>::iterator ErrorInfoCDGItr_t;
    typedef std::vector<ErrorInfoCDG *>::const_iterator ErrorInfoCDGCItr_t;

    // Vector of children targets to callout/deconfigure/GARD
    std::vector<ErrorInfoChildrenCDG *> iv_childrenCDGs;
    typedef std::vector<ErrorInfoChildrenCDG *>::iterator
        ErrorInfoChildrenCDGItr_t;
    typedef std::vector<ErrorInfoChildrenCDG *>::const_iterator
        ErrorInfoChildrenCDGCItr_t;

    // Vector of traces to collect
    std::vector<ErrorInfoCollectTrace *> iv_traces;
    typedef std::vector<ErrorInfoCollectTrace *>::iterator
         ErrorInfoCollectTraceItr_t;
    typedef std::vector<ErrorInfoCollectTrace *>::const_iterator
         ErrorInfoCollectTraceCItr_t;
};

}

#endif // FAPIERRORINFO_H_
