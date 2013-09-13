/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/fapi/fapiReturnCode.H $                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
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
/**
 *  @file fapiReturnCode.H
 *
 *  @brief Defines the ReturnCode class that is a generic return code.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     04/13/2011  Created.
 *                          mjjones     07/05/2011  Removed const from data
 *                          mjjones     07/25/2011  Added support for FFDC and
 *                                                  Error Target
 *                          camvanng    09/06/2011  Added function template for
 *                                                  setHwpFfdc
 *                          mjjones     09/22/2011  Added ErrorInfo Support
 *                          mjjones     11/10/2011  Use ecmdDataBufferBase
 *                          mjjones     01/12/2012  Enforce correct usage
 *                          mjjones     02/22/2012  Allow user to add Target FFDC
 *                          mjjones     03/16/2012  Add type to FFDC data
 *                          mjjones     03/16/2012  Allow different PLAT errors
 *                          brianh      07/31/2012  performance/size optimizations
 *                          mjjones     08/14/2012  Created getCreateReturnCodeDataRef
 *                          mjjones     09/19/2012  Add FFDC ID to error info
 *                          mjjones     03/22/2013  Support Procedure Callouts
 *                          mjjones     05/20/2013  Support Bus Callouts
 *                          mjjones     06/06/2013  Check FFDC size at compile time
 *                          mjjones     06/24/2013  Support Children CDGs
 *                          mjjones     08/26/2013  Support Hw Callout
 *                          rjknight    09/10/2013  Support DIMM callout from
 *                                                  MBA port and dimm number
 */

#ifndef FAPIRETURNCODE_H_
#define FAPIRETURNCODE_H_

#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <ecmdDataBufferBase.H>
#include <fapiTarget.H>
#include <fapiReturnCodes.H>
#include <fapiErrorInfo.H>
#include <fapiHwpErrorInfo.H>
#include <fapiPlatTrace.H>
#include <fapiHwpReturnCodes.H>
#include <fapiCollectRegFfdc.H>

/**
 * @brief Set HWP Error macro
 *
 * This macro should be used by a HWP to create an error. The ReturnCode's
 * internal return code is set and any error information in the Error XML file
 * is added to the ReturnCode
 */
#define FAPI_SET_HWP_ERROR(RC, ERROR) \
    RC._setHwpError(fapi::ERROR); \
    ERROR##_CALL_FUNCS_TO_COLLECT_FFDC(RC); \
    ERROR##_CALL_FUNCS_TO_COLLECT_REG_FFDC(RC); \
    ERROR##_ADD_ERROR_INFO(RC)

/**
 * @brief Add info to HWP Error macro
 *
 * This macro should be used by an FFDC HWP to add error information from an
 * Error XML file to an existing error.
 */
#define FAPI_ADD_INFO_TO_HWP_ERROR(RC, ERROR) \
    ERROR##_CALL_FUNCS_TO_COLLECT_FFDC(RC); \
    ERROR##_CALL_FUNCS_TO_COLLECT_REG_FFDC(RC); \
    ERROR##_ADD_ERROR_INFO(RC)

namespace fapi
{

// Forward declarations
class ReturnCodeDataRef;

/**
 * @class ReturnCode
 *
 * This class provides a generic return code. It contains the rcValue (return
 * code value) which is of type uint32_t.
 *
 * FAPI can set an error in the ReturnCode by calling setFapiError.
 * PLAT can set an error in the ReturnCode by calling setPlatError, this
 *      function associates heap based PlatData to the ReturnCode (use-case is
 *      an error log).
 * HWP  can set an error in the ReturnCode by calling FAPI_SET_HWP_ERROR, this
 *      macro adds any error information specified in the error XML file to the
 *      ReturnCode
 * HWP  can add error information to a ReturnCode that already contains an
 *      error by calling FAPI_ADD_INFO_TO_HWP_ERROR, this is called by HWPs
 *      that are specifically written to collect FFDC. This macro adds any error
 *      information specified in the error XML file to the ReturnCode
 * FAPI/PLAT/HWP can set an ecmdDataBufferBase error in the ReturnCode by
 *               calling setEcmdError
 *
 * A ReturnCode is copyable and assignable. Therefore, it cannot be subclassed.
 *
 * When a ReturnCode is copied, any PlatData or ErrorInfo is not copied
 * because it may be heavyweight. Both ReturnCodes will refer to the same data.
 * this is achieved with the ReturnCodeDataRef class.
 *
 * A ReturnCode object is not thread safe, multiple threads must not use the
 * same ReturnCode object concurrently.
 */
class ReturnCode
{
public:

    /**
     * @brief Default constructor. Sets rcValue to success
     */
    ReturnCode() : iv_rcValue(FAPI_RC_SUCCESS), iv_pDataRef(NULL) { }

    /**
     * @brief Constructor. Sets rcValue to the specified value
     *
     * @note This allows an implicit conversion from a value from the
     *       ReturnCodes enumeration and a ReturnCode. This is provided so that
     *       a function can do "return FAPI_RC_SUCCESS;"
     *
     * @param[in] i_rcValue The rcValue to set
     */
    ReturnCode(const ReturnCodes i_rcValue);

    /**
     * @brief Copy Constructor
     *
     * @param[in] i_right Reference to ReturnCode to copy
     */
    ReturnCode(const ReturnCode & i_right);

    /**
     * @brief Destructor
     */
    ~ReturnCode();

    /**
     * @brief Assignment Operator.
     *
     * @param[in] i_right Reference to ReturnCode to assign from.
     *
     * @return Reference to 'this' ReturnCode
     */
    ReturnCode & operator=(const ReturnCode & i_right);

    /**
     * @brief ***DEPRECATED*** Assignment Operator.
     *
     * TODO
     * This function will be deleted to prevent invalid usage of ReturnCode
     * Use setFapiError, setPlatError, setEcmdError or FAPI_SET_HWP_ERROR
     *
     * @param[in] i_rc rcValue to assign
     *
     * If FAPI_RC_SUCCESS (zero) is assigned then any associated data is deleted
     *
     * @return Reference to 'this' ReturnCode
     */
    ReturnCode & operator=(const uint32_t i_rcValue);

    /**
     * @brief Returns if the return code indicates success
     *
     * @return bool. True if ok, else false
     */
    bool ok() const { return (iv_rcValue == FAPI_RC_SUCCESS); }

    /**
     * @brief uint32_t conversion function. Returns the rcValue
     *
     * @note This allows a user to directly compare:
     *       1/ ReturnCode to uint32_t (ReturnCode converted to uint32_t)
     *       2/ ReturnCode to ReturnCode (Both ReturnCode converted to uint32_t)
     *       This allows a user to test if a ReturnCode is bad (if (l_rc){})
     */
    operator uint32_t() const { return iv_rcValue; }

    /**
     * @brief Sets a FAPI error. Sets the rcValue to the supplied value (from
     *        the ReturnCodes enumeration) and deletes any associated data.
     *
     * This is called by FAPI code to generate an error.
     *
     * @param[in] i_rcValue Error value to set
     */
    void setFapiError(const ReturnCodes i_rcValue);

    /**
     * @brief Sets an ecmd error. Sets the rcValue to the supplied value and
     *        deletes any associated data.
     *
     * This is called by FAPI/PLAT/HWP code to generate an error when an
     * ecmdDataBufferBase call returns non zero. This can also be used by PLAT
     * code that reports errors with ecmd return codes.
     *
     * @param[in] i_rcValue ecmdDataBufferBase error value to set
     */
    void setEcmdError(const uint32_t i_rcValue);

    /**
     * @brief Sets a PLAT error. Sets the rcValue to the supplied value, deletes
     *        any associated data and associates the supplied heap based
     *        PlatData with the ReturnCode. The ReturnCode object takes
     *        responsibility for deleting the data (platform code implements the
     *        delete function and must know the type and how to delete it).
     *
     * This is called by PLAT code to generate an error. The expected use-case
     * is to associate a platform error log with the ReturnCode. If the error is
     * one that a HWP can look for (e.g. the HWP may want to retry in a specific
     * error) then one of the specific FAPI_RC_PLAT errors in fapiReturnCodes.H
     * can be used else it defaults to FAPI_RC_PLAT_ERR_SEE_DATA which means
     * that there is a platform error that the HWP cannot decode.
     *
     * @param[in] i_pData   Pointer to PlatData (on the heap). Can be NULL if
     *                      the platform does not attach data
     * @param[in] i_rcValue Error value to set
     */
    void setPlatError(void * i_pData,
                      const ReturnCodes i_rcValue = FAPI_RC_PLAT_ERR_SEE_DATA);

    /**
     * @brief Sets a HWP error. Sets the rcValue to the supplied value (from
     *        the HwpReturnCode enumeration) and deletes any associated data.
     *
     * HWP code must call the FAPI_SET_HWP_ERROR macro rather than this function
     * directly to generate an error so that any error information is
     * automatically added to the ReturnCode
     *
     * @param[in] i_rcValue Error value to set
     */
    void _setHwpError(const HwpReturnCode i_rcValue);

    /**
     * @brief Get a pointer to any PlatData. ReturnCode is still responsible for
     *        deletion of the data. The caller must not delete
     *
     * This is called by PLAT. The expected use-case is to get a pointer to a
     * platform error log. The data pointer should be used immediately in the
     * same thread.
     *
     * @return void *. Pointer to any PlatData. If NULL then no data
     */
    void * getPlatData() const;

    /**
     * @brief Get a pointer to any PlatData and release ownership from
     *        ReturnCode. The caller is responsible for deletion.
     *
     * This is called by PLAT. The expected use-case is to retrieve a platform
     * error log.
     *
     * @return void *. Pointer to any PlatData. If NULL then no data
     */
    void * releasePlatData();

    /**
     * @brief Enumeration of ErrorInfo types
     */
    enum ErrorInfoType
    {
        EI_TYPE_FFDC              = 1,
        EI_TYPE_HW_CALLOUT        = 2,
        EI_TYPE_PROCEDURE_CALLOUT = 3,
        EI_TYPE_BUS_CALLOUT       = 4,
        EI_TYPE_CDG               = 5, // Target Callout/Deconfig/GARD
        EI_TYPE_CHILDREN_CDG      = 6, // Children Callout/Deconfig/GARD
    };

    /**
     * @brief Structure representing a single ErrorInfo entry.
     *
     * An array of these is passed to the addErrorInfo function when a HWP
     * generates an error by calling the FAPI_SET_HWP_ERROR macro
     */
    struct ErrorInfoEntry
    {
        uint8_t iv_type; // Value from ErrorInfoType
        union
        {
            struct
            {
                uint8_t  iv_ffdcObjIndex;
                uint16_t iv_ffdcSize;
                uint32_t iv_ffdcId;
            } ffdc;

            struct
            {
                uint8_t iv_hw;
                uint8_t iv_calloutPriority;
                uint8_t iv_refObjIndex;
            } hw_callout;

            struct
            {
                uint8_t iv_procedure;
                uint8_t iv_calloutPriority;
            } proc_callout;

            struct
            {
                uint8_t iv_endpoint1ObjIndex;
                uint8_t iv_endpoint2ObjIndex;
                uint8_t iv_calloutPriority;
            } bus_callout;

            struct
            {
                uint8_t iv_targetObjIndex;
                uint8_t iv_callout;
                uint8_t iv_deconfigure;
                uint8_t iv_gard;
                uint8_t iv_calloutPriority;
            } target_cdg;

            struct
            {
                uint8_t  iv_parentObjIndex;
                uint8_t  iv_callout;
                uint8_t  iv_deconfigure;
                uint32_t iv_childType;
                uint8_t  iv_childPort;
                uint8_t  iv_childNumber;
                uint8_t  iv_gard;
                uint8_t  iv_calloutPriority;
            } children_cdg;
        };
    };

    /**
     * @brief Add ErrorInfo
     *
     * This is called by the FAPI_SET_HWP_ERROR and macro to add ErrorInfo to the
     * ReturnCode when a HWP generates an error. The function is designed to add
     * all the ErrorInfo at once rather than the FAPI_SET_HWP_ERROR macro making
     * multiple function calls to add each piece of ErrorInfo individually in
     * order to minimize code size
     *
     * @param[in] i_pObjects Pointer to array of const pointers to const objects
     *                       that are referred to by ErrorInfoEntry objects
     * @param[in] i_pEntries Pointer to array of ErrorInfoEntry objects defining
     *                       the ErrorInfo that needs to be added
     * @param[in] i_count    Number of ErrorInfoEntry entries
     */
    void addErrorInfo(const void * const * i_pObjects,
                      const ErrorInfoEntry * i_pEntries,
                      const uint8_t i_count);

    /**
     * @brief Add a copy of FFDC to the ErrorInfo
     *
     * This is called by addErrorInfo
     *
     * @param[in] i_ffdcId FFDC Identifier - used for decoding
     * @param[in] i_pFfdc Pointer to the FFDC to copy
     * @param[in] i_size  Size of the FFDC to copy
     */
    void addEIFfdc(const uint32_t i_ffdcId,
                   const void * i_pFfdc,
                   const uint32_t i_size);

    /**
     * @brief Get a pointer to any ErrorInfo 
     *
     * This is called by PLAT to find information about an error
     *
     * @return ErrorInfo *. Pointer to any ErrorInfo. If NULL then no info
     */
    const ErrorInfo * getErrorInfo() const;

    /**
     * @brief Enumeration of return code creators
     */
    enum returnCodeCreator
    {
        CREATOR_FAPI = 1,
        CREATOR_PLAT = 2,
        CREATOR_HWP = 3,
    };

    /**
     * @brief Gets the creator of the return code
     *
     * @return ReturnCodeCreator
     */
    returnCodeCreator getCreator() const;

private:

    /**
     * @brief Get a reference to the ReturnCodeDataRef, if it doesn't exist
     *        then one is created and returned
     *
     * @return ReturnCodeDataRef &. Reference to ReturnCodeDataRef
     */
    ReturnCodeDataRef & getCreateReturnCodeDataRef();

    /**
     * @brief Forgets about any associated data (PlatData and ErrorInfo)
     *
     * If this is the only ReturnCode pointing to the data then the data is
     * deleted
     */
    void forgetData();

    /**
     * @brief Add a HW callout to the ErrorInfo
     *
     * This is called by addErrorInfo
     *
     * @param[in] i_hw        The hardware to callout
     * @param[in] i_priority  The priority of the callout
     * @param[in] i_refTarget Reference to reference Target
     */
     void addEIHwCallout(
         const HwCallouts::HwCallout i_hw,
         const CalloutPriorities::CalloutPriority i_priority,
         const Target & i_refTarget);

    /**
     * @brief Add a procedure callout to the ErrorInfo
     *
     * This is called by addErrorInfo
     *
     * @param[in] i_procedure The procedure to callout
     * @param[in] i_priority  The priority of the callout
     */
     void addEIProcedureCallout(
         const ProcedureCallouts::ProcedureCallout i_procedure,
         const CalloutPriorities::CalloutPriority i_priority);

    /**
     * @brief Add a bus callout to the ErrorInfo
     *
     * This is called by addErrorInfo
     *
     * @param[in] i_target1  Reference to endpoint1 Target
     * @param[in] i_target2  Reference to endpoint2 Target
     * @param[in] i_priority The priority of the callout
     */
     void addEIBusCallout(
         const Target & i_target1,
         const Target & i_target2,
         const CalloutPriorities::CalloutPriority i_priority);

    /**
     * @brief Add a target callout/deconfigure/GARD to the ErrorInfo
     *
     * This is called by addErrorInfo
     *
     * @param[in] i_target      Reference to the target to cdg
     * @param[in] i_callout     True if Target should be called out
     * @param[in] i_deconfigure True if Target should be deconfigured
     * @param[in] i_gard        True if Target should be GARDed
     * @param[in] i_priority    The priority of any callout
     */
     void addEICdg(
         const Target & i_target,
         const bool i_callout,
         const bool i_deconfigure,
         const bool i_gard,
         const CalloutPriorities::CalloutPriority i_priority);

     /**
      * @brief Add children target callout/deconfigure/GARDs to the ErrorInfo
      *
      * This is called by addErrorInfo to c/d/g all child Targets of a specified
      * type. The function can take a chip/unit pair or an MBA/DIMM pair.  For
      * the MBA/DIMM pair two additional parameters are used to identify which
      * dimms should be called out.
      *
      * @param[in] i_parent      Reference to the parent chip
      * @param[in] i_childType   Child target types to c/d/g
      * @param[in] i_callout     True if Target should be called out
      * @param[in] i_deconfigure True if Target should be deconfigured
      * @param[in] i_gard        True if Target should be GARDed
      * @param[in] i_priority    The priority of any callout
      * @param[in] i_childPort   MBA port where error was detected
      * @param[in] i_childNum    MBA dimm number of failing chip
      */
      void addEIChildrenCdg(
          const Target & i_parent,
          const TargetType i_childType,
          const bool i_callout,
          const bool i_deconfigure,
          const bool i_gard,
          const CalloutPriorities::CalloutPriority i_priority,
          const uint8_t i_childPort, const uint8_t i_childNum);

    // The rcValue
    uint32_t iv_rcValue;

    // Pointer to ReturnCodeDataRef (manages associated data)
    ReturnCodeDataRef * iv_pDataRef;
};

/**
 * @namespace ReturnCodeFfdc
 *
 * This namespace contains template functions used for adding FFDC data to a
 * ReturnCode. They cannot be a ReturnCode member functions because a function
 * template cannot be specialized within a class
 */
namespace ReturnCodeFfdc
{
    /**
     * @brief Enumeration of ErrorInfo FFDC sizes that are used to indicate a
     *        special type that cannot simply be memcopied
     */
    enum ErrorInfoFfdcSize
    {
        EI_FFDC_SIZE_ECMDDB = 0xffff,   // ecmdDataBufferBase
        EI_FFDC_SIZE_TARGET = 0xfffe,   // fapi::Target
        EI_FFDC_MAX_SIZE    = 0x1000,   // Limit regular FFDC capture to 4kb
    };

    /**
     * @brief Compile error if caller tries to add too much FFDC to a ReturnCode
     *
     * If the unspecialized function template is instantiated, the compile will
     * fail due to the construction of an undefined class. If the specialized
     * function template is instantiated (done if the FFDC size is not too big),
     * the function does nothing and is optimized out
     */
    class Error_FfdcTooLargeToCapture;
    template<const bool TOO_BIG> void checkFfdcSize()
    {
        Error_FfdcTooLargeToCapture();
    }
    template <> inline void checkFfdcSize<false>() {}

    /**
     * @brief Get FFDC Size
     *
     * This is called by the FAPI_SET_HWP_ERROR macro to find out the size of
     * FFDC data. If the data is of a special type that is handled differently
     * than types that are simply memcopied then it is handled by a template
     * specialization
     *
     * @return uint16_t. Size of the FFDC data
     */
    template<typename T>
    inline uint16_t getErrorInfoFfdcSize(const T &)
    {
        checkFfdcSize<(sizeof(T) > EI_FFDC_MAX_SIZE)>();
        return sizeof(T);
    }

    /**
     * @brief Get FFDC Size specialization for ecmdDataBufferBase
     */
    template<>
    inline uint16_t getErrorInfoFfdcSize<ecmdDataBufferBase>(
        const ecmdDataBufferBase &)
    {
        return EI_FFDC_SIZE_ECMDDB;
    }

    /**
     * @brief Get FFDC Size specialization for fapi::Target
     */
    template<>
    inline uint16_t getErrorInfoFfdcSize<fapi::Target>(
        const fapi::Target &)
    {
        return EI_FFDC_SIZE_TARGET;
    }

    /**
     * @brief Compile error if caller tries to get the FFDC size of a pointer
     *
     * If this function template is instantiated, the compile will fail due to
     * the construction of an undefined class.
     */
    class Error_PtrPassedToGetErrorInfoFfdcSize;
    template<typename T>
    inline int16_t getErrorInfoFfdcSize(const T *)
    {
        Error_PtrPassedToGetErrorInfoFfdcSize();
        return 0;
    }
}

}

#endif // FAPIRETURNCODE_H_
