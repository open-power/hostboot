/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/hwpf/fapi/fapiErrorInfo.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2011-2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
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
 */

#ifndef FAPIERRORINFO_H_
#define FAPIERRORINFO_H_

#include <stdint.h>
#include <vector>
#include <fapiTarget.H>

namespace fapi
{

/**
 * @enum FfdcType
 *
 * This enumeration defines the possible types of FFDC data
 */
enum FfdcType
{
    FFDC_TYPE_NONE = 0,
    FFDC_TYPE_TARGET = 1,  // FFDC data is a Target ecmd-string
    FFDC_TYPE_ECMDDBB = 2, // FFDC data is the contents of an ecmdDataBaseBuffer
    FFDC_TYPE_DATA = 3,    // FFDC data is just raw data
};

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
     * @param[in] i_pFfdc Pointer to the FFDC to copy
     * @param[in] i_size  Size of the FFDC to copy
     * @param[in] i_type  Type of the FFDC to copy
     */
    ErrorInfoFfdc(const void * i_pFfdc,
                  const uint32_t i_size,
                  const FfdcType i_type);

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
     * @brief Get the FfdcData type
     *
     * @return FfdcType. FFDC type
     */
    FfdcType getType() const;

private:

    // Pointer to the FFDC
    uint8_t * iv_pFfdc;

    // Size of the FFDC
    uint32_t iv_size;

    // Type of the FFDC
    FfdcType iv_type;

    // Disabled
    ErrorInfoFfdc(const ErrorInfoFfdc &);
    ErrorInfoFfdc & operator=(const ErrorInfoFfdc &);
};

/**
 * @enum CalloutPriority
 *
 * This enumeration defines the possible callout priorities
 */
enum CalloutPriority
{
    PRI_LOW = 1,
    PRI_MEDIUM = 2,
    PRI_HIGH = 3,
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
    CalloutPriority iv_calloutPriority;

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

    // Vector of targets to callout/deconfigure/GARD
    std::vector<ErrorInfoCDG *> iv_CDGs;
    typedef std::vector<ErrorInfoCDG *>::iterator ErrorInfoCDGItr_t;
    typedef std::vector<ErrorInfoCDG *>::const_iterator ErrorInfoCDGCItr_t;
};

}

#endif // FAPIERRORINFO_H_
