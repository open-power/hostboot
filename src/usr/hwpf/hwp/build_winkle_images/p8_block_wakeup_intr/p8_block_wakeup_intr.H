/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_block_wakeup_intr/p8_block_wakeup_intr.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
// $Id: p8_block_wakeup_intr.H,v 1.1 2013/08/27 16:13:07 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_block_wakeup_intr.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
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
