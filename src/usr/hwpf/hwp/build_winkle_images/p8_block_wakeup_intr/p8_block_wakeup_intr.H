/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_block_wakeup_intr/p8_block_wakeup_intr.H $ */
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
// $Id: p8_block_wakeup_intr.H,v 1.1 2013/08/27 16:13:07 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_block_wakeup_intr.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
/**
  * OWNER NAME:   Greg Still         Email: stillgs@us.ibm.com
  * BACKUP NAME : Michael Olsen      Email: cmolsen@us.ibm.com
  *
  * @file p8_block_wakeup_intr.C
  * @brief Set/reset the BLOCK_REG_WKUP_SOURCES bit in the PCBS-PM associated 
  *         with an EX chiplet
 */  
//------------------------------------------------------------------------------

#ifndef _PROC_BLKWKUP_H_
#define _PROC_BLKWKUP_H_


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

#define NUM_BLKWKUP_OPS 2
enum PROC_BLKWKUP_OPS 
{
    BLKWKUP_SET,
    BLKWKUP_RESET
};

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include "p8_pm.H"

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*p8_block_wakeup_intr_FP_t) (
                            const fapi::Target&, 
                            PROC_BLKWKUP_OPS);

extern "C" {

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------

/**
 * p8_block_wakeup_intr
 *
 * @param[in] i_target EX target
 * @param[in] i_operation  SET, RESET
 *
 * @retval ECMD_SUCCESS
 * @retval ERROR only those from called functions or MACROs
 */
fapi::ReturnCode 
p8_block_wakeup_intr(  const fapi::Target& i_target, 
                        PROC_BLKWKUP_OPS i_operation);

} // extern "C"

#endif // _PROC_BLKWKUP_H_
