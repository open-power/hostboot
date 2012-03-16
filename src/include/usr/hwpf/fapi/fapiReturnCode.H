//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/hwpf/fapi/fapiReturnCode.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
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

/**
 * @brief Set HWP Error macro
 *
 * This macro should be used by a HWP to set an error code if there is
 * associated Error Information (in the Error Information XML file) that
 * needs to be processed
 */
#define FAPI_SET_HWP_ERROR(RC, ERROR) \
    RC._setHwpError(fapi::ERROR); \
    ERROR##_CALL_FUNC_TO_ANALYZE_ERROR(RC); \
    ERROR##_CALL_FUNCS_TO_COLLECT_FFDC(RC); \
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
 *      macro adds any error information associated with the HWP error to the
 *      ReturnCode (error information is documented in an error XML file).
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
    ReturnCode();

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
    bool ok() const;

    /**
     * @brief uint32_t conversion function. Returns the rcValue
     *
     * @note This allows a user to directly compare:
     *       1/ ReturnCode to uint32_t (ReturnCode converted to uint32_t)
     *       2/ ReturnCode to ReturnCode (Both ReturnCode converted to uint32_t)
     *       This allows a user to test if a ReturnCode is bad (if (l_rc){})
     */
    operator uint32_t() const;

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
     * @brief Sets a PLAT error. Sets the rcValue to FAPI_RC_PLAT_ERR_SEE_DATA,
     *        deletes any associated data and associates the supplied heap based
     *        PlatData with the ReturnCode. The ReturnCode object takes
     *        responsibility for deleting the data (platform code implements the
     *        delete function and must know the type and how to delete it).
     *
     * This is called by PLAT. The expected use-case is to associate a platform
     * error log with the ReturnCode.
     *
     * @param[in] i_pData Pointer to PlatData (on the heap)
     */
    void setPlatError(void * i_pData);

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
        EI_TYPE_FFDC    = 1,
        EI_TYPE_CALLOUT = 2,
        EI_TYPE_DECONF  = 3,
        EI_TYPE_GARD    = 4,
    };

    /**
     * @brief Structure representing a single ErrorInfo entry.
     *
     * An array of these is passed to the addErrorInfo function when a HWP
     * generates an error by calling the FAPI_SET_HWP_ERROR macro
     */
    struct ErrorInfoEntry
    {
        uint8_t iv_type  : 3; // The type of ErrorInfo (from ErrorInfoType enum)
        uint8_t iv_object: 5; // Which object in the i_pObjects array passed to
                              // addErrorInfo the ErrorInfoEntry is for
        int16_t  iv_data1;    // EI_TYPE_FFDC   : Size of FFDC
                              // EI_TYPE_CALLOUT: CalloutPriority
    };

    /**
     * @brief Add ErrorInfo
     *
     * This is called by the FAPI_SET_HWP_ERROR macro to add ErrorInfo to the
     * ReturnCode when a HWP generates an error. The function is designed to add
     * all the ErrorInfo at once rather than the FAPI_SET_HWP_ERROR macro making
     * multiple function calls to add each piece of ErrorInfo individually in
     * order to minimize code size
     *
     * @param[in] i_pObjects Pointer to array of const pointers to const objects
     *                       that are referred to by ErrorInfoEntry objects
     *                       (object type is dependent on ErrorInfoEntry type)
     * @param[in] i_pEntries Pointer to array of ErrorInfoEntry objects defining
     *                       the ErrorInfo that needs to be added
     * @param[in] i_count    Number of ErrorInfoEntry structures
     */
    void addErrorInfo(const void * const * i_pObjects,
                      const ErrorInfoEntry * i_pEntries,
                      const uint8_t i_count);

    /**
     * @brief Add a copy of FFDC to the ErrorInfo
     *
     * This is called by:
     * - addErrorInfo
     * - ReturnCodeFfdc::addEIFfdc (function template)
     *
     * @param[in] i_pFfdc Pointer to the FFDC to copy
     * @param[in] i_size  Size of the FFDC to copy
     * @param[in] i_type  Type of the FFDC to copy
     */
    void addEIFfdc(const void * i_pFfdc,
                   const uint32_t i_size,
                   const FfdcType i_type);

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
     * @brief If iv_pDataRef is NULL then a new ReturnCodeDataRef is created
     */
    void ensureDataRefExists();

    /**
     * @brief Forgets about any associated data (PlatData and ErrorInfo)
     *
     * If this is the only ReturnCode pointing to the data then the data is
     * deleted
     */
    void forgetData();

    /**
     * @brief Add a target to callout to the ErrorInfo
     *
     * This is called by addErrorInfo
     *
     * @param[in] i_target   Reference to the target to callout.
     * @param[in] i_priority The priority of the callout
     */
     void addEICallout(const Target & i_target,
                       const CalloutPriority i_priority);

    /**
     * @brief Add a target to deconfigure to the ErrorInfo
     *
     * This is called by addErrorInfo
     *
     * @param[in] i_target Reference to the target to deconfigure.
     */
    void addEIDeconfigure(const Target & i_target);

    /**
     * @brief Add a target to create a GARD record for to the ErrorInfo
     *
     * This is called by addErrorInfo
     *
     * @param[in] i_target Reference to the target to create a GARD record for
     */
    void addEIGard(const Target & i_target);

    // The rcValue
    uint32_t iv_rcValue;

    // Pointer to ReturnCodeDataRef (manages associated data)
    ReturnCodeDataRef * iv_pDataRef;
};

/**
 * @namespace ReturnCodeFfdc
 *
 * This namespace contains a template functions for adding FFDC data to a
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
        EI_FFDC_SIZE_ECMDDB = -1,   // ecmdDataBufferBase
        EI_FFDC_SIZE_TARGET = -2,   // fapi::Target
    };

    /**
     * @brief Get FFDC Size
     *
     * This is called by the FAPI_SET_HWP_ERROR macro to find out the size of
     * FFDC data. If the data is of a special type that is handled differently
     * than types that are simply memcopied then it is handled by a template
     * specialization
     *
     * @return int8_t. Size of the FFDC data
     */
    template<typename T>
    int16_t getErrorInfoFfdcSize(const T &)
    {
        return sizeof(T);
    }

    /**
     * @brief Get FFDC Size specialization for ecmdDataBufferBase
     */
    template<>
    inline int16_t getErrorInfoFfdcSize<ecmdDataBufferBase>(
        const ecmdDataBufferBase &)
    {
        return EI_FFDC_SIZE_ECMDDB;
    }

    /**
     * @brief Get FFDC Size specialization for fapi::Target
     */
    template<>
    inline int16_t getErrorInfoFfdcSize<fapi::Target>(
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
    int16_t getErrorInfoFfdcSize(const T *)
    {
        Error_PtrPassedToGetErrorInfoFfdcSize();
        return 0;
    }

    /**
     * @brief Add a copy of FFDC to the ErrorInfo in a ReturnCode
     *
     * This is called by FFDC HWPs
     *
     * @param[out] o_rc   Reference to ReturnCode to copy FFDC to
     * @param[in]  i_ffdc Reference to FFDC to copy
     */
    template<typename T>
    void addEIFfdc(ReturnCode & o_rc,
                   const T & i_ffdc)
    {
        o_rc.addEIFfdc(&i_ffdc, sizeof(T), FFDC_TYPE_DATA);
    }

    /**
     * @brief Specialization of addEIFfdc for ecmdDataBufferBase
     *
     * @param[out] o_rc   Reference to ReturnCode to copy FFDC to
     * @param[in]  i_ffdc Reference to ecmdDataBufferBase to copy
     */
    template<>
    inline void addEIFfdc<ecmdDataBufferBase>(ReturnCode & o_rc,
                                              const ecmdDataBufferBase & i_ffdc)
    {
        uint32_t * l_pData = new uint32_t[i_ffdc.getWordLength()];

        // getWordLength rounds up to the next 32bit boundary, ensure that after
        // extracting, any unset bits are zero
        l_pData[i_ffdc.getWordLength() - 1] = 0;

        // Deliberately not checking return code from extract to save code space
        i_ffdc.extract(l_pData, 0, i_ffdc.getBitLength());
        o_rc.addEIFfdc(l_pData, (i_ffdc.getWordLength() * 4),
                       FFDC_TYPE_ECMDDBB);
        delete [] l_pData;
    }

    /**
     * @brief Specialization of addEIFfdc for fapi::Target
     *
     * @param[out] o_rc   Reference to ReturnCode to copy FFDC to
     * @param[in]  i_ffdc Reference to fapi::Target to add FFDC for
     */
    template<>
    inline void addEIFfdc<fapi::Target>(ReturnCode & o_rc,
                                        const fapi::Target & i_ffdc)
    {
        const char * l_ecmdString = i_ffdc.toEcmdString();
        o_rc.addEIFfdc(l_ecmdString, (strlen(l_ecmdString) + 1),
                       FFDC_TYPE_TARGET);
    }

    /**
     * @brief Compile error if caller tries to add a pointer as FFDC
     *
     * If this function template is instantiated, the compile will fail due to
     * the construction of an undefined class.
     */
    class Error_PtrPassedToAddEIFfdc;
    template<typename T>
    void addEIFfdc(ReturnCode &,
                   const T *)
    {
        Error_PtrPassedToAddEIFfdc();
    }
}

}

#endif // FAPIRETURNCODE_H_
