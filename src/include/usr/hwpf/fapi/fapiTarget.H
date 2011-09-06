//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/hwpf/fapi/fapiTarget.H $
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
 *  @file fapiTarget.H
 *
 *  @brief Defines the Target class that is a generic target of a Hardware
 *         Procedure operation.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     04/13/2011  Created. Based on Hlava prototype
 *                          mjjones     06/29/2011  Removed incorrect MSB from 2 enums
 *                          mjjones     07/05/2011  Removed const from handle
 *                          mjjones     08/29/2011  Updated toString function
 */

#ifndef FAPITARGET_H_
#define FAPITARGET_H_

#include <stdint.h>
#include <stddef.h>

namespace fapi
{

/**
 * @brief Enumeration of target types values (bitmask values)
 */
enum TargetType
{
    TARGET_TYPE_NONE        = 0x00000000,
    TARGET_TYPE_SYSTEM      = 0x00000001,
    TARGET_TYPE_DIMM        = 0x00000002,
    TARGET_TYPE_PROC_CHIP   = 0x00000004,
    TARGET_TYPE_MEMBUF_CHIP = 0x00000008,
    TARGET_TYPE_EX_CHIPLET  = 0x00000010,
    TARGET_TYPE_MBA_CHIPLET = 0x00000020,
    TARGET_TYPE_MBS_CHIPLET = 0x00000040,
    TARGET_TYPE_MCS_CHIPLET = 0x00000080,
};

/**
 * @brief Typedef used when passing multiple TargetType values
 */
typedef uint32_t TargetTypes_t;

/**
 * @brief ECMD constants
 */
const uint32_t MAX_ECMD_STRING_LEN = 64;

/**
 * @class Target
 *
 * This class provides a generic Target of a Hardware Procedure Operation.
 *
 * A Target contains a void * pointer to a handle which is only meaningful to
 * platform code.
 *
 * A Target object is copyable and assignable. Therefore, it cannot be
 * subclassed.
 *
 * A Target object is not thread safe, multiple threads must not use the same
 * Target object concurrently.
 */
class Target
{
public:

    /**
     * @brief Default constructor
     */
    Target();

    /**
     * @brief Constructor
     *
     * @param[in] i_type    Target type
     * @param[in] i_pHandle Pointer to platform specific Target handle
     */
    Target(const TargetType i_type,
           void * i_pHandle);

    /**
     * @brief Copy Constructor
     *
     * @param[in] i_right Reference to Target to copy
     */
    Target(const Target & i_right);

    /**
     * @brief Destructor
     */
    ~Target();

    /**
     * @brief Assignment Operator.
     *
     * @param[in] i_right Reference to Target to assign from.
     *
     * @return Reference to 'this' Target
     */
    Target & operator=(const Target & i_right);

    /**
     * @brief Equality Comparison Operator
     *
     * @param[in] i_right Reference to Target to compare.
     *
     * @return bool. True if equal.
     */
    bool operator==(const Target & i_right) const;

    /**
     * @brief Inequality Comparison Operator
     *
     * @param[in] i_right Reference to Target to compare.
     *
     * @return bool. True if not equal.
     */
    bool operator!=(const Target & i_right) const;

    /**
     * @brief Get the handle pointer.
     *
     * The handle is only meaningful to platform code.
     *
     * @return Handle_t. The handle.
     */
    void * get() const;

    /**
     * @brief Set the handle. Platform using Handle_t as handle
     *
     * The handle is only meaningful to platform code.
     *
     * @param[in] i_pHandle Pointer to platform specific handle
     */
    void set(void * i_pHandle);

    /**
     * @brief Get the target type
     *
     * @return The type of target represented by this target
     */
    TargetType getType() const;

    /**
     * @brief Set the target type
     *
     * @param[in] i_type The type of target represented by this target
     */
    void setType(const TargetType i_type);

    /**
     * @brief Convert a target to an ecmd-format target string
     *
     * This is used in order to trace the target in the common SCAN trace
     *
     * @note Implemented by platform code
     *
     * @param[out] o_ecmdString. Reference to a character array of length
     *                           MAX_ECMD_STRING_LEN. This is filled in with the
     *                           null terminated ECMD string.
     */
    void toString(char (&o_ecmdString)[MAX_ECMD_STRING_LEN]) const;

private:

    /**
     * @brief Compare the handle
     *
     * @note Implemented by platform code because only platform code knows the
     *       type pointed to by iv_pHandle to compare
     *
     * @param[in] i_right Reference to Target to compare handle to
     *
     * @return bool. True if the same
     */
    bool compareHandle(const Target & i_right) const;

    /**
     * @brief Copy the handle
     *
     * @note Implemented by platform code because only platform code knows the
     *       type pointed to by iv_pHandle to copy
     *
     * @param[in] i_right Reference to Target to copy handle from
     */
    void copyHandle(const Target & i_right);

    /**
     * @brief Delete the handle
     *
     * @note Implemented by platform code because only platform code knows the
     *       type to delete and if it should actually be deleted
     */
    void deleteHandle();

    // Type of target
    TargetType iv_type;

    // Pointer to platform specific Target Handle
    void * iv_pHandle;
};

}

#endif // FAPITARGET_H_
