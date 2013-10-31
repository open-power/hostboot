/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/fapi/fapiCollectRegFfdc.H $              */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
// $Id: fapiCollectRegFfdc.H,v 1.4 2013/10/31 19:48:22 dedahle Exp $
/**
 *  @file fapiCollectRegFfdc.H
 *
 *  @brief Defines the fapiCollectRegFfdc function that collects chip or 
 *         chiplet register FFDC data. This is called automatically by
 *         FAPI_SET_HWP_ERROR (when a HWP creates an error) and 
 *         FAPI_ADD_INFO_TO_HWP_ERROR (when an FFDC HWP adds error information
 *         to an existing error) if the error XML contains a
 *         <collectRegisterFfdc> element. This function should not be called
 *         directly by any user code. The function implementation is
 *         automatically generated from FAPI Error XML files.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     09/19/2012  Created.
 *                          dedahle     09/30/2013  Add i_child parameter for
 *                                                  chiplet register FFDC
 *                          dedahle     10/15/13    Added i_presChild and
 *                                                  i_childOffsetMult
 *                                                  parameters for register FFDC
 *                                                  collection based on present
 *                                                  child chiplets
 */

#ifndef FAPICOLLECTREGFFDC_H_
#define FAPICOLLECTREGFFDC_H_

#include <fapiHwpErrorInfo.H>
#include <fapiTarget.H>
namespace fapi
{

class Target;
class ReturnCode;

/**
 * @brief Collects Register FFDC from a chip or chiplet
 *
 * This should only be called by FAPI during FAPI_SET_HWP_ERROR or
 * FAPI_ADD_INFO_TO_HWP_ERROR
 *
 * @param[in]  i_target           Reference to Target to collect FFDC from
 * @param[in]  i_ffdcId           FFDC Identifier
 * @param[out] o_rc               Reference to ReturnCode that FFDC is added to
 * @param[in]  i_child            Specifies type of i_target's chiplet to collect
 *                                FFDC from.  If this parameter is TARGET_TYPE_NONE
 *                                (default value), then register FFDC is collected
 *                                from i_target, else, register FFDC is collected
 *                                from all functional child chiplets i_target of
 *                                the specified type
 * @param[in]  i_presChild        When specified, register FFDC will be collected
 *                                from i_target's registers based on present chiplets
 *                                of this type.
 * @param[in]  i_childOffsetMult  Specifies the chiplet position offset multiplier.
 *                                This is used in calculating the scom register
 *                                addresses when collecting register FFDC based on
 *                                present child chiplets.
 */
void fapiCollectRegFfdc(const fapi::Target & i_target,
                        const fapi::HwpFfdcId i_ffdcId,
                        fapi::ReturnCode & o_rc,
                        const fapi::TargetType i_child =
                                  fapi::TARGET_TYPE_NONE,
                        const fapi::TargetType i_presChild =
                                  fapi::TARGET_TYPE_NONE,
                        const uint32_t i_childOffsetMult = 0);
}

#endif
