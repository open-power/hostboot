//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/hwpf/fapi/fapiErrorInfo.H $
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
 *  @file fapiErrorInfo.H
 *
 *  @brief Defines the ErrorInfoRepository, ErrorInfoRecord and associated
 *         classes.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     08/09/2011  Created.
 */

#ifndef FAPIERRORINFO_H_
#define FAPIERRORINFO_H_

#include <stdint.h>
#include <fapiTarget.H>
#include <fapiReturnCode.H>
#include <fapiHwpReturnCodes.H>
#include <vector>

namespace fapi
{

/**
 * @enum CalloutPriority
 *
 * This enumeration defines the possible callout priorities
 */
enum CalloutPriority
{
    HIGH = 1,
    MEDIUM = 2,
    LOW = 3,
};

/**
 * @struct ErrorInfoCallout
 *
 * This struct defines a target callout. An ErrorInfoRecord can contain a number
 * of these.
 */
struct ErrorInfoCallout
{
    /**
     * @brief Constructor.
     *
     * @param[in] i_targetType The type of the target being called out. If the
     *                         same as the target of the HWP that generated the
     *                         error then that is the target
     * @param[in] i_targetPos  The position of the target being called out.
     *                         Relative to the target of the HWP that generated
     *                         the error
     * @param[in] i_priority   The priority of the callout
     */
    ErrorInfoCallout(const TargetType i_targetType,
                     const uint32_t i_targetPos,
                     const CalloutPriority i_priority);

    // The type of the target being called out. See ctor for details
    TargetType iv_targetType;

    // The position of the target being called out. See ctor for details
    uint32_t iv_targetPos;

    // The priority of the callout
    CalloutPriority iv_priority;
};

/**
 * @struct ErrorInfoFfdc
 *
 * This struct defines FFDC collection information.  An ErrorInfoRecord can
 * contain a number of these.
 */
struct ErrorInfoFfdc
{
    /**
     * @brief Constructor.
     *
     * @param[in] i_targetType   The type of the target to collect FFDC from. If
     *                           the same as the target of the HWP that
     *                           generated the error then that is the target
     * @param[in] i_targetPos    The position of the target to collect FFDC
     *                           from. Relative to the target of the HWP that
     *                           generated the error
     * @param[in] i_ffdcHwpToken The token used to identify the HWP to call to
     *                           collect FFDC
     */
    ErrorInfoFfdc(const TargetType i_targetType,
                  const uint32_t i_targetPos,
                  const FfdcHwpToken i_ffdcHwpToken);

    // The type of the target to collect FFDC from. See ctor for details
    TargetType iv_targetType;

    // The position of the target to collect FFDC from. See ctor for details
    uint32_t iv_targetPos;

    // The token used to identify the HWP to call to collect FFDC
    FfdcHwpToken iv_ffdcHwpToken;
};

/**
 * @struct ErrorInfoRecord
 *
 * This struct defines the error information record. This gives information
 * about a specific HWP generated ReturnCode value.
 */
struct ErrorInfoRecord
{
    /**
     * @brief Default constructor.
     */
    ErrorInfoRecord();

    /**
     * @brief Copy constructor.
     *
     * @param[in] i_right Reference to ErrorInfoRecord to copy
     */
    ErrorInfoRecord(const ErrorInfoRecord & i_right);

    /**
     * @brief Destructor
     */
    ~ErrorInfoRecord();

    /**
     * @brief Assignment operator
     *
     * @param[in] i_right Reference to ErrorInfoRecord to copy
     *
     * @return Reference to 'this' ErrorInfoRecord
     */
    ErrorInfoRecord & operator=(const ErrorInfoRecord & i_right);

    /**
     * @brief Set Description function
     *
     * @param[in] i_pDesc Pointer to C string that is copied
     */
    void setDescription(const char * i_pDescription);

    /**
     * @brief Get Description function
     *
     * @return pointer to description (NULL if no description set)
     */
    const char * getDescription();

    // The Return Code value
    uint32_t iv_rc;

    // Vector of target callouts
    std::vector<ErrorInfoCallout> iv_callouts;
    typedef std::vector<ErrorInfoCallout>::iterator ErrorInfoCalloutItr_t;

    // Vector of FFDC collection information
    std::vector<ErrorInfoFfdc> iv_ffdcs;
    typedef std::vector<ErrorInfoFfdc>::iterator ErrorInfoFfdcItr_t;

private:
    // C-String containing the description of the error
    char * iv_pDescription;
};

/**
 * @class ErrorInfoRepository
 *
 * This class defines the error information repository. It provides an
 * ErrorInfoRecord given a ReturnCode value. This is an abstract class that a
 * concrete class must derive from.
 */
class ErrorInfoRepository
{
public:

    /**
     * @brief Get the singleton instance.
     *
     * This function must be implemented by a concrete derived class
     */
    static ErrorInfoRepository& Instance();

    /**
     * @brief Default constructor.
     */
    ErrorInfoRepository();

    /**
     * @brief Destructor
     */
    virtual ~ErrorInfoRepository();

    /**
     * @brief Find Error Information Record for given ReturnCode value
     *
     * This is a pure virtual function that must be implemented by a concrete
     * derived class
     *
     * @param[in]  i_rc     The ReturnCode value. User can pass in a ReturnCode
     *                      object and it will be implicitly converted to a
     *                      uint32_t using the ReturnCode conversion operator
     * @param[out] o_record Reference to a ErrorInfoRecord. If the record is
     *                      found then it is assigned to o_record, else it is
     *                      not. User should pass an ErrorInfoRecord with a good
     *                      ReturnCode value and then look to see if the value
     *                      was changed to the ReturnCode value to figure out if
     *                      the record was found.
     *
     * @return ReturnCode. Zero on success else error accessing the repository
     */
    virtual ReturnCode find(const uint32_t i_rc,
                            ErrorInfoRecord & o_record) = 0;

};

}

#endif // FAPIERRORINFO_H_
