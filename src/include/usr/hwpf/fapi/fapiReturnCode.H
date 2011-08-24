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
 */

#ifndef FAPIRETURNCODE_H_
#define FAPIRETURNCODE_H_

#include <stdint.h>
#include <stddef.h>
#include <fapiTarget.H>
#include <fapiReturnCodes.H>

namespace fapi
{

// Forward declarations
class ReturnCodePlatDataRef;
class ReturnCodeHwpFfdcRef;

/**
 * @class ReturnCode
 *
 * This class provides a generic return code. It contains the rcValue (return
 * code value) which is of type uint32_t. A user can treat a ReturnCode just
 * as if it were a uint32_t.
 *
 * FAPI, PLAT and HWP code can all create a ReturnCode.
 * PLAT can associate PlatData to it (use-case is an error log).
 * HWP can add HwpFfdc to it.
 * FAPI can add an error target to it (use-case is to record which target was
 *   the subject of a HWP that generated an error)
 *
 * A ReturnCode is copyable and assignable. Therefore, it cannot be subclassed.
 *
 * When a ReturnCode is copied, any PlatData or HwpFfdc is not copied because it
 * may be heavyweight. Both ReturnCodes will refer to the same data. Data is
 * only deleted when the last ReturnCode with a reference to it is deleted. It
 * is possible for PLAT to get a pointer to the PlatData and to optionally
 * release the data (ReturnCode no longer responsible for deleting).
 *
 * A ReturnCode object is not thread safe, multiple threads must not use the
 * same ReturnCode object concurrently.
 */
class ReturnCode
{
public:

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
     * @brief Default constructor. Sets rcValue to success
     */
    ReturnCode();

    /**
     * @brief Constructor. Sets rcValue to the specified value
     *
     * @note This allows an implicit conversion between a uint32_t and a
     *       ReturnCode. A user is allowed to return a uint32_t from a function
     *       that returns a ReturnCode or is allowed to pass a uint32_t to a
     *       function that expects a ReturnCode and in both cases, the uint32_t
     *       will be automatically converted to a ReturnCode.
     *
     * @param[in] i_rcValue The rcValue to set
     */
    ReturnCode(const uint32_t i_rcValue);

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
     * @brief Assignment Operator.
     *
     * @param[in] i_rc Reference to rcValue to assign
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
     */
    operator uint32_t() const;

    /**
     * @brief Get a pointer to any PlatData. ReturnCode is still responsible for
     *        deletion of the data. The caller must not delete
     *
     * The data pointed to is only meaningful to platform code. The data pointer
     * should be used immediately in the same thread because it may be deleted
     * in the future.
     *
     * @return void *. Pointer to any PlatData. If NULL then no data
     */
    void * getPlatData() const;

    /**
     * @brief Get a pointer to any PlatData and release ownership from
     *        ReturnCode. The caller is responsible for deletion.
     *
     * The data pointed to is only meaningful to platform code.
     *
     * @return void *. Pointer to any PlatData. If NULL then no data
     */
    void * releasePlatData();

    /**
     * @brief Associates heap based PlatData with the ReturnCode. The ReturnCode
     *        object takes responsibility for deleting the data (platform code
     *        actually implements the delete function and must know the type and
     *        how to delete it).
     *
     * The data pointed to is only meaningful to platform code. This is expected
     * to be used to associate a platform error log with the ReturnCode.
     *
     * param[in] i_pData Pointer to PlatData (on the heap)
     */
    void setPlatData(void * i_pData);

    /**
     * @brief Get a pointer to any stored HwpFfdc.
     *
     * The data pointer should be used immediately in the same thread because it
     * is a pointer to internal object data.
     *
     * param[out] o_size Size of the FFDC data in bytes.
     *
     * @return void *. Pointer to any HwpFfdc. If NULL then no data
     */
    const void * getHwpFfdc(uint32_t & o_size) const;

    /**
     * @brief Stores a copy of the provided HwpFfdc
     *
     * param[in] i_pFfdc Pointer to HwpFfdc
     * param[in] i_size  Size of the FFDC data in bytes
     */
    void setHwpFfdc(const void * i_pFfdc, const uint32_t i_size);

    /**
     * @brief Gets the creator of the return code
     *
     * @return ReturnCodeCreator
     */
    returnCodeCreator getCreator() const;

    /**
     * @brief Stores a copy of the provided Target if there is an error and no
     *        Target is already stored
     *
     * This is intended to be used by FAPI_EXEC_HWP to record which target was
     * the subject of a HWP that generated an error.
     *
     * param[in] i_target Reference to Target
     */
    void setErrTarget(const Target & i_target);

    /**
     * @brief Gets the error target
     *
     * @return Target *. Pointer to Target. If NULL then no error Target
     */
    Target * getErrTarget() const;

private:

    /**
     * @brief Removes interest in pointed to ReturnCodePlatDataRef
     */
    void removePlatData();

    /**
     * @brief Removes interest in pointed to ReturnCodeHwpFfdcRef
     */
    void removeHwpFfdc();

    // The rcValue
    uint32_t iv_rcValue;

    // Pointer to ReturnCodePlatDataRef
    ReturnCodePlatDataRef * iv_pPlatDataRef;

    // Pointer to ReturnCodeHwpFfdcRef
    ReturnCodeHwpFfdcRef * iv_pHwpFfdcRef;

    // Pointer to error Target
    Target * iv_pErrTarget;
};

}

#endif // FAPIRETURNCODE_H_
