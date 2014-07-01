/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pm_pmc_firinit.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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

// $Id: p8_pm_pmc_firinit.H,v 1.7 2014/01/14 17:13:34 stillgs Exp $
// $Source: /archive/shadow/ekb/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pm_pmc_firinit.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : p8_pm_pmc_firinit.H
// *! DESCRIPTION : Set the EX chiplet into Special Wake-up via one of the 
// *!               entity bits provided
// *!
// *! OWNER NAME  : Greg Still    Email: stillgs@us.ibm.com
// *! BACKUP NAME : Pradeep CN    Email: padeepcn@in.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _P8_PM_PMC_FIRINIT_H_
#define _P8_PM_PMC_FIRINIT_H_


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "p8_pm_firinit.H"


const uint32_t        PMC_FIR_REGISTER_LENGTH = 49 ;
enum PMC_FIRS
{
    PSTATE_OCI_MASTER_RDERR                     =  0,
    PSTATE_OCI_MASTER_RDDATA_PARITY_ERR         =  1,
    PSTATE_GPST_CHECKBYTE_ERR                   =  2,
    PSTATE_GACK_TO_ERR                          =  3,
    PSTATE_PIB_MASTER_NONOFFLINE_ERR            =  4,
    PSTATE_PIB_MASTER_OFFLINE_ERR               =  5,
    PSTATE_OCI_MASTER_TO_ERR                    =  6,
    PSTATE_INTERCHIP_UE_ERR                     =  7,
    PSTATE_INTERCHIP_ERRORFRAME_ERR             =  8,
    PSTATE_MS_FSM_ERR                           =  9,
    MS_COMP_PARITY_ERR                          = 10,
    IDLE_PORESW_FATAL_ERR                       = 11,
    IDLE_PORESW_STATUS_RC_ERR                   = 12,
    IDLE_PORESW_STATUS_VALUE_ERR                = 13,
    IDLE_PORESW_WRITE_WHILE_INACTIVE_ERR        = 14,
    IDLE_PORESW_TIMEOUT_ERR                     = 15,
    IDLE_OCI_MASTER_WRITE_TIMEOUT_ERR           = 16,
    IDLE_INTERNAL_ERR                           = 17,
    INT_COMP_PARITY_ERR                         = 18,
    PMC_OCC_HEARTBEAT_TIMEOUT                   = 19,
    SPIVID_CRC_ERROR0                           = 20,
    SPIVID_CRC_ERROR1                           = 21,
    SPIVID_CRC_ERROR2                           = 22,
    SPIVID_RETRY_TIMEOUT                        = 23,
    SPIVID_FSM_ERR                              = 24,
    SPIVID_MAJORITY_DETECTED_A_MINORITY         = 25,
    O2S_CRC_ERROR0                              = 26,
    O2S_CRC_ERROR1                              = 27,
    O2S_CRC_ERROR2                              = 28,
    O2S_RETRY_TIMEOUT                           = 29,
    O2S_WRITE_WHILE_BRIDGE_BUSY_ERR             = 30,
    O2S_FSM_ERR                                 = 31,
    O2S_MAJORITY_DETECTED_A_MINORITY            = 32,
    O2P_WRITE_WHILE_BRIDGE_BUSY_ERR             = 33,
    O2P_FSM_ERR                                 = 34,
    OCI_SLAVE_ERR                               = 35,
    IF_COMP_PARITY_ERR                          = 36,
    IDLE_RECOVERY_NOTIFY_PRD                    = 37,
    FIR_PARITY_ERR_DUP                          = 47,
    FIR_PARITY_ERR                              = 48
};



// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*p8_pm_pmc_firinit_FP_t) (const fapi::Target& , uint32_t mode );

extern "C" {

//------------------------------------------------------------------------------
// function: FAPI p8_pm_pmc_firinit  HWP entry point
//           operates on chips passed in i_target argument to perform
//           desired settings of FIRS of PMC macro 
// parameters: i_target        => chip target

// returns: FAPI_RC_SUCCESS if all specified operations complete successfully,
//          else return code for failing operation
//------------------------------------------------------------------------------
fapi::ReturnCode 
p8_pm_pmc_firinit(const fapi::Target& i_target, uint32_t mode );
 

} // extern "C"

#endif // _P8_PM_PMC_FIRINIT_H_