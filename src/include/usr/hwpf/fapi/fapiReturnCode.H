/**
 *  @file fapiReturnCode.H
 *
 *  @brief Defines the ReturnCode class that is a generic return code.
 */

#ifndef FAPIRETURNCODE_H_
#define FAPIRETURNCODE_H_

#include <stdint.h>
#include <stddef.h>
#include <fapiReturnCodes.H>

namespace fapi
{

// Forward declaration
class ReturnCodeDataRef;

/**
 * @class ReturnCode
 *
 * This class provides a generic return code. It contains the rcValue (return
 * code value) which is of type uint32_t. A user can treat a ReturnCode just
 * as if it were a uint32_t.
 *
 * FAPI, PLAT and HWP code can all create a ReturnCode. PLAT can optionally add
 * platform specific ReturnCodeData to it.
 *
 * A ReturnCode is copyable and assignable. Therefore, it cannot be subclassed.
 *
 * When a ReturnCode is copied, any ReturnCodeData is not copied because it may
 * be heavyweight. Both ReturnCodes will refer to the same ReturnCodeData.
 * ReturnCodeData is only deleted when the last ReturnCode with a reference to
 * it is deleted. It is possible for PLAT to get a pointer to the ReturnCodeData
 * and to optionally release the data (ReturnCode no longer responsible for
 * deleting). This is done using the intermediate ReturnCodeDataRef class.
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
     * @brief Get a pointer to any ReturnCodeData. ReturnCode is still
     *        responsible for deletion of the data. The caller must not delete
     *
     * The data pointed to is only meaningful to platform code.
     *
     * @return void *. Pointer to any ReturnCodeData. If NULL then no data
     */
    void * getData() const;

    /**
     * @brief Get a pointer to any ReturnCodeData and release ownership from
     *        ReturnCode. The caller is responsible for deletion.
     *
     * The data pointed to is only meaningful to platform code.
     *
     * @return void *. Pointer to any ReturnCodeData. If NULL then no data
     */
    void * releaseData();

    /**
     * @brief Sets ReturnCodeData. The ReturnCode object takes responsibility
     *        for deleting the data (platform code actually implements the
     *        delete function and must know the type and how to delete it).
     *
     * The data pointed to is only meaningful to platform code.
     *
     * param[in] i_pData Pointer to ReturnCodeData (on the heap)
     */
    void setData(const void * i_pData);

    /**
     * @brief Gets the creator of the return code
     *
     * @return ReturnCodeCreator
     */
    returnCodeCreator getCreator() const;

private:

    /**
     * @brief Removes interest in pointed to ReturnCodeDataRef
     */
    void removeData();

    // The rcValue
    uint32_t iv_rcValue;

    // Pointer to ReturnCodeDataRef
    ReturnCodeDataRef * iv_pDataRef;
};

}

#endif // FAPIRETURNCODE_H_
