/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/fapi/fapiErrorInfo.H $                   */
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
 */

#ifndef FAPIERRORINFO_H_
#define FAPIERRORINFO_H_

#include <stdint.h>
#include <vector>
#include <fapiTarget.H>

namespace fapi
{

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

    ProcedureCallouts::ProcedureCallout iv_procedure;
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
     * @param[in] i_target Reference to the target to callout/deconfigure/GARD
     */
    ErrorInfoCDG(const Target & i_target);

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

    /**
     * @brief Get a reference to the ErrorInfoCDG structure for the specified
     *        Target. If there is no existing structure then one is created
     *
     * @param[in] i_target Reference to Target to get the information for
     *
     * @return Reference to ErrorInfoCDG
     */
    ErrorInfoCDG & getCreateErrorInfoCDG(const Target & i_target);

    // Vector of FFDC Data
    std::vector<ErrorInfoFfdc *> iv_ffdcs;
    typedef std::vector<ErrorInfoFfdc *>::iterator ErrorInfoFfdcItr_t;
    typedef std::vector<ErrorInfoFfdc *>::const_iterator ErrorInfoFfdcCItr_t;

    // Vector of procedures to callout
    std::vector<ErrorInfoProcedureCallout *> iv_procedureCallouts;
    typedef std::vector<ErrorInfoProcedureCallout *>::iterator
        ErrorInfoProcedureCalloutItr_t;
    typedef std::vector<ErrorInfoProcedureCallout *>::const_iterator
        ErrorInfoProcedureCalloutCItr_t;

    // Vector of targets to callout/deconfigure/GARD
    std::vector<ErrorInfoCDG *> iv_CDGs;
    typedef std::vector<ErrorInfoCDG *>::iterator ErrorInfoCDGItr_t;
    typedef std::vector<ErrorInfoCDG *>::const_iterator ErrorInfoCDGCItr_t;
};

}

#endif // FAPIERRORINFO_H_
