/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/diag/prdf/prdfMain_ipl.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2021                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

#ifndef __prdfMain_ipl_H
#define __prdfMain_ipl_H

// Custom compile configs

/**
 * @file  prdfMain_ipl.H
 * @brief PRD code used by external components (IPL only).
 *
 * This file contains code that is strictly specific to Hostboot. All code that
 * is common between FSP and Hostboot should be in the respective common file.
 */

namespace PRDF
{

/**
 * @brief Initialize PRD system model and data (No System Lock)
 * @return Error log if error occurs
 */
extern errlHndl_t noLock_initialize();

/**
 * @brief  Restores hardware DRAM repairs to reflect what is stored in VPD.
 * @param  i_trgt An MBA, MCA, or OCMB target.
 * @return Non-SUCCESS if conditions are such that a callout had to be made,
 *         SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
extern uint32_t restoreDramRepairs( const TARGETING::TargetHandle_t i_trgt );

/**
 * @brief  Analyzes IPL CE statistics during MNFG IPL
 * @param  i_trgt An MBA, MCBIST, or OCMB_CHIP target.
 * @param  o_calloutMade True if callout has been made, false otherwise .
 * @return Non-SUCCESS if internal function fails, SUCCESS otherwise.
 */
extern int32_t analyzeIplCEStats( const TARGETING::TargetHandle_t i_trgt,
                                  bool &o_calloutMade );

/**
 * @brief  Starts memory background scrubbing on the given target.
 * @param  i_trgt A target that contains the maintenance command logic (i.e.
 *                MCBIST or MBA or OCMB_CHIP).
 * @return If an error log is returned, then some internal function failed. See
 *         the FFDC in the error log for failure details.
 */
extern errlHndl_t startScrub( const TARGETING::TargetHandle_t i_trgt );

namespace PlatServices
{

/**
 * @brief  Queries the ATTR_MEM_EFF_HYBRID and ATTR_MEM_EFF_HYBRID_MEMORY_TYPE
 *         attributes to determine if a DIMM is an MDS DDIMM.
 * @param  i_target Target MEM_PORT/OCMB.
 * @return True if the target is an MDS DDIMM, false otherwise.
 */
template<TARGETING::TYPE T>
extern bool isMdsDimm( TARGETING::TargetHandle_t i_target );

}

} // end namespace PRDF

#endif // __prdfMain_ipl_H

