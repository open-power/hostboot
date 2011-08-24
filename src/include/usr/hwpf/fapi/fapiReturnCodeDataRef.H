//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/hwpf/fapi/fapiReturnCodeDataRef.H $
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
 *  @file fapiReturnCodeDataRef.H
 *
 *  @brief Defines the ReturnCodeDataRef class that provides a pointer and a
 *         reference count to a platform specific ReturnCodeData object.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     04/13/2011  Created.
 *                          mjjones     07/05/2011. Removed const from data
 *                          mjjones     07/25/2011  Added support for FFDC
 */

#ifndef FAPIRETURNCODEDATAREF_H_
#define FAPIRETURNCODEDATAREF_H_

#include <stdint.h>
#include <stddef.h>

namespace fapi
{

/**
 * @class ReturnCodeDataRef
 *
 * This class is a simple reference counter. Derived classes are used by a
 * ReturnCode object in order to maintain a count of how many ReturnCode objects
 * have a reference to the object.
 *
 * A ReturnCodeDataRef object is not thread safe, multiple threads must not use
 * the same ReturnCodeDataRef object concurrently.
 */
class ReturnCodeDataRef
{
public:

    /**
     * @brief Constructor
     */
    ReturnCodeDataRef();

    /**
     * @brief Destructor
     */
    virtual ~ReturnCodeDataRef();

    /**
     * @brief Increments the ref count
     */
    void incRefCount();

    /**
     * @brief Decrements the ref count
     *
     * @return bool True if zero reached
     */
    bool decRefCountCheckZero();

private:

    // Copy constructor and assignment operator disabled
    ReturnCodeDataRef(const ReturnCodeDataRef & i_right);
    ReturnCodeDataRef & operator=(const ReturnCodeDataRef & i_right);

    // The reference count (how many ReturnCodes are pointing to this object)
    uint32_t iv_refCount;
};

/**
 * @class ReturnCodePlatDataRef
 *
 * This class contains a pointer to PlatData and inherits from ReturnCodeDataRef
 * for a reference count recording how many ReturnCodes have a pointer to it.
 *
 * It is used exclusively by the ReturnCode class. Multiple copies of a
 * ReturnCode will all point to the same ReturnCodePlatDataRef. The ReturnCodes
 * maintain the reference count, the last ReturnCode to remove its reference
 * will delete the ReturnCodePlatDataRef which in turn deletes the PlatData.
 * The PlatData pointer is maintained in this class so that releasing the data
 * releases it from all ReturnCode copies.
 *
 * A ReturnCodePlatDataRef object is not thread safe, multiple threads must not
 * use the same ReturnCodePlatDataRef object concurrently.
 */
class ReturnCodePlatDataRef : public ReturnCodeDataRef
{
public:

    /**
     * @brief Constructor
     *
     * @param[in] i_pData Pointer to PlatData to associate
     */
    explicit ReturnCodePlatDataRef(void * i_pData);

    /**
     * @brief Destructor
     */
    virtual ~ReturnCodePlatDataRef();

    /**
     * @brief Get a pointer to any PlatData. ReturnCodePlatDataRef is still
     *        responsible for deletion of the data. The caller must not delete
     *
     * The pointer is only meaningful to platform code.
     *
     * @return void *. Pointer to PlatData. If NULL then no data (must have been
     *                 released)
     */
    void * getData() const;

    /**
     * @brief Get a pointer to any PlatData and release ownership from
     *        ReturnCodeDataRef. The caller is responsible for deletion.
     *
     * The pointer is only meaningful to platform code.
     *
     * @return void *. Pointer to PlatData. If NULL then no data (must have been
     *                 released)
     */
    void * releaseData();

private:

    // Copy constructor and assignment operator disabled
    ReturnCodePlatDataRef(const ReturnCodePlatDataRef & i_right);
    ReturnCodePlatDataRef & operator=(const ReturnCodePlatDataRef & i_right);

    /**
     * @brief Deletes the PlatData
     *
     * @note Implemented by platform code because only platform code knows the
     *       type of the data and how to delete it.
     */
    void deleteData();

    // Pointer to PlatData
    void * iv_pData;
};

/**
 * @class ReturnCodeHwpFfdcRef
 *
 * This class contains HwpFfdc and inherits from ReturnCodeDataRef for a
 * reference count recording how many ReturnCodes have a pointer to it.
 *
 * It is used exclusively by the ReturnCode class. Multiple copies of a
 * ReturnCode will all point to the same ReturnCodeHwpFfdcRef. The ReturnCodes
 * maintain the reference count, the last ReturnCode to remove its reference
 * will delete the ReturnCodeHwpFfdcRef which in turn deletes the contained
 * HwpFfdc.
 *
 * A ReturnCodeHwpFfdcRef object is not thread safe, multiple threads must not
 * use the same ReturnCodeHwpFfdcRef object concurrently.
 */
class ReturnCodeHwpFfdcRef : public ReturnCodeDataRef
{
public:

    /**
     * @brief Constructor
     *
     * @param[in] i_pFfdc Pointer to the FFDC to copy
     * @param[in] i_size  Size of the FFDC to copy
     */
    ReturnCodeHwpFfdcRef(const void * i_pFfdc,
                         const uint32_t i_size);

    /**
     * @brief Destructor
     */
    virtual ~ReturnCodeHwpFfdcRef();

    /**
     * @brief Get a pointer to the HwpFfdc.
     *
     * @param[out] o_size Size of the FFDC data in bytes.
     *
     * @return void *. Pointer to HwpFfdc.
     */
    const void * getData(uint32_t & o_size) const;

private:

    // Copy constructor and assignment operator disabled
    ReturnCodeHwpFfdcRef(const ReturnCodeHwpFfdcRef & i_right);
    ReturnCodeHwpFfdcRef & operator=(const ReturnCodeHwpFfdcRef & i_right);

    // Pointer to HwpFfdc
    uint8_t * iv_pFfdc;

    // Size of HwpFfdc
    uint32_t iv_size;
};

}

#endif // FAPIRETURNCODEDATAREF_H_
