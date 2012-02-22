//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/hwpf/fapi/fapiSystemConfig.H $
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
 *  @file fapiSystemConfig.H
 *
 *  @brief Defines the System Config query functions that platform code must
 *         implement. It is an eCMD requirement that these be "C" functions.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     09/12/2011  Updated with new functions.
 *                          mjjones     02/17/2012  Updated fapiGetAssociatedDimms
 *                                                  description to only allow MBA
 *
 */

#ifndef FAPISYSTEMCONFIG_H_
#define FAPISYSTEMCONFIG_H_

#include <stdint.h>
#include <vector>
#include <fapiReturnCode.H>
#include <fapiTarget.H>

extern "C"
{

/** 
 * @brief Gets the chiplets that are children of the input chip
 * 
 * @param[in]  i_chip        Input chip
 * @param[in]  i_chipletType Type of chiplet required
 * @param[out] o_chiplets    Reference to vector that is cleared then filled in
 *                           with the children chiplet Targets
 * @param[in]  i_state       Only return targets of the specified state. Either
 *                           present or functional (default)
 * 
 * @return ReturnCode. Zero on success, else error 
 */ 
fapi::ReturnCode fapiGetChildChiplets(
    const fapi::Target & i_chip,
    const fapi::TargetType i_chipletType, 
    std::vector<fapi::Target> & o_chiplets,
    const fapi::TargetState i_state = fapi::TARGET_STATE_FUNCTIONAL);

/** 
 * @brief Gets the DIMMs that are logically associated with the input MBA target
 *
 * @param[in]  i_target Input MBA chiplet target
 * @param[out] o_dimms  Reference to vector that is cleared then filled in with
 *                      the associated DIMM Targets
 * @param[in]  i_state  Only return targets of the specified state. Either
 *                      present or functional (default)
 * 
 * @return ReturnCode. Zero on success, else error 
 */ 
fapi::ReturnCode fapiGetAssociatedDimms(
    const fapi::Target& i_target, 
    std::vector<fapi::Target> & o_dimms,
    const fapi::TargetState i_state = fapi::TARGET_STATE_FUNCTIONAL); 

/** 
 * @brief Gets the parent chip of the input chiplet
 *
 * @param[in]  i_chiplet Input chiplet
 * @param[out] o_chip    Reference to Target that is set to the parent chip
 * 
 * @return ReturnCode. Zero on success, else error 
 */ 
fapi::ReturnCode fapiGetParentChip(
    const fapi::Target& i_chiplet,
    fapi::Target & o_chip);

} // extern "C"

#endif // FAPISYSTEMCONFIG_H_
