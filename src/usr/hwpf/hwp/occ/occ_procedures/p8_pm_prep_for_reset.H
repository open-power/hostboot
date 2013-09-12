/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pm_prep_for_reset.H $  */
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
// $Id: p8_pm_prep_for_reset.H,v 1.10 2013/08/02 19:13:48 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pm_prep_for_reset.H,v $

//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Ralf Maier         Email: ralf.maier@de.ibm.com
// *!
// *! General Description:
// *!        
// *! Prepare powermanagement components for reset
// *!
//------------------------------------------------------------------------------
//  
// constant definitions for .
#define UNIT_CONFIG     0x1
#define UNIT_RESET      0x2

#include "p8_pm.H"
#include "p8_poregpe_init.H"
#include "p8_pcbs_init.H"
#include "p8_pmc_init.H"
#include "p8_poreslw_init.H"
#include "p8_poregpe_init.H"
#include "p8_oha_init.H"
#include "p8_pba_init.H"
#include "p8_occ_sram_init.H"
#include "p8_ocb_init.H"
#include "p8_pss_init.H"
#include "p8_pmc_force_vsafe.H"
#include "p8_occ_control.H"
#include "p8_pm_firinit.H"

typedef fapi::ReturnCode (*p8_pm_prep_for_reset_FP_t) (const fapi::Target &, 
                                                       const fapi::Target &,
                                                       uint32_t);


extern "C"
{

//------------------------------------------------------------------------------
/**
 * p8_pm_prep_for_reset Call underlying unit procedures to perform readiness for
 *          reinitialization of PM complex.
 *
 * @param[in] i_primary_chip_target   Primary Chip target which will be passed
 *        to all the procedures
 * @param[in] i_secondary_chip_target Secondary Chip target will be passed for
 *        pmc_init -reset only if it is DCM otherwise this should be NULL.
 * @param[in] i_mode (PM_RESET (hard - will kill the PMC);
 *                    PM_RESET_SOFT (will not fully reset the PMC))
 *
 * @retval ECMD_SUCCESS
 * @retval ERROR defined in xml
 */
  
fapi::ReturnCode p8_pm_prep_for_reset(  const fapi::Target &i_primary_chip_target , 
                                        const fapi::Target &i_secondary_chip_target,
                                        uint32_t            i_mode);
  
}


