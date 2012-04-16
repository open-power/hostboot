//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/hwpf/fapi/fapiChipEcFeature.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
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
 *  @file fapiChipEcFeature.H
 *
 *  @brief Defines the fapiQueryChipEcFeature function that allows HWPs to
 *         query if a particular chip has a feature determined by its EC level.
 *         Chip EC features are specified in attribute XML files and the
 *         fapiQueryChipEcFeature function implementation is auto-generated.
 *         HWPs should not call this function directly, but should access the
 *         corresponding HWPF attribute using FAPI_ATTR_GET
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     03/26/2012  Created.
 */

#ifndef FAPICHIPECFEATURE_H_
#define FAPICHIPECFEATURE_H_

#include <stdint.h>
#include <fapiAttributeIds.H>
#include <fapiReturnCode.H>

namespace fapi
{

class Target;

/**
 * @brief Queries if a Chip has a particular feature
 *
 * This should only be called by FAPI during the processing of a FAPI_ATTR_GET
 * for a Chip EC Feature attribute
 *
 * @param[in]  i_id         Attribute ID of the Chip EC Feature
 * @param[in]  i_pTarget    Pointer to chip target
 * @param[out] o_hasFeature Set to 1 if chip has feature else 0
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiQueryChipEcFeature(fapi::AttributeId i_id,
                                        fapi::Target * i_pTarget,
                                        uint8_t & o_hasFeature);
}

#endif
