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
 * This class contains a pointer to platform specific ReturnCodeData and a
 * reference count recording how many ReturnCodes have a pointer to itself.
 *
 * It is used exclusively by the ReturnCode class. Multiple copies of a
 * ReturnCode will all point to the same ReturnCodeDataRef. The ReturnCodes
 * maintain the reference count, the last ReturnCode to remove its reference
 * will delete the ReturnCodeDataRef which in turn deletes the ReturnCodeData.
 * The ReturnCodeData pointer is maintained in this class so that releasing the
 * data releases it from all ReturnCode copies.
 *
 * A ReturnCodeDataRef object is not thread safe, multiple threads must not use
 * the same ReturnCodeDataRef object concurrently.
 */
class ReturnCodeDataRef
{
public:

    /**
     * @brief Constructor
     *
     * @param[in] i_pData Pointer to platform specific ReturnCodeData
     */
    explicit ReturnCodeDataRef(void * i_pData);

    /**
     * @brief Destructor
     */
    ~ReturnCodeDataRef();

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

    /**
     * @brief Get a pointer to ReturnCodeData. ReturnCodeDataRef is still
     *        responsible for deletion of the data. The caller must not delete
     *
     * The pointer is only meaningful to platform code.
     *
     * @return void *. Pointer to ReturnCodeData. If NULL then no data (must
     *                 have been released)
     */
    void * getData() const;

    /**
     * @brief Get a pointer to any ReturnCodeData and release ownership from
     *        ReturnCodeDataRef. The caller is responsible for deletion.
     *
     * The pointer is only meaningful to platform code.
     *
     * @return void *. Pointer to ReturnCodeData. If NULL then no data (must
     *                 have been released)
     */
    void * releaseData();

private:

    // Copy constructor and assignment operator disabled
    ReturnCodeDataRef(const ReturnCodeDataRef & i_right);
    ReturnCodeDataRef & operator=(const ReturnCodeDataRef & i_right);

    /**
     * @brief Deletes the ReturnCodeData
     *
     * @note Implemented by platform code because only platform code knows the
     *       type of the data and how to delete it.
     */
    void deleteData();

    // The reference count (how many ReturnCodes are pointing to this object)
    uint32_t iv_refCount;

    // Pointer to platform specific ReturnCodeData
    void * iv_pData;
};

}

#endif // FAPIRETURNCODEDATAREF_H_
