/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pm_init.H $            */
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
// $Id: p8_pm_init.H,v 1.7 2013/04/06 02:14:19 pchatnah Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pm_init.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Greg Still       Email: stillgs@us.ibm.com
// *!
// *! General Description:
// *!        
// *!  include file for p8_pm_effective with constants, definitions, prototypes
// *!
//------------------------------------------------------------------------------
//  

#include "p8_pcbs_init.H"
#include "p8_pmc_init.H"
#include "p8_poreslw_init.H"
#include "p8_poregpe_init.H"
#include "p8_oha_init.H"
#include "p8_pba_init.H"    //FIXME was not compiling check with Klaus
#include "p8_occ_sram_init.H"
#include "p8_ocb_init.H"
#include "p8_pss_init.H"
#include "p8_cpu_special_wakeup.H"
#include "p8_pm_firinit.H"

/**
* @brief Function pointer typedef.
*
*/



typedef fapi::ReturnCode (*p8_pm_init_FP_t)      (const fapi::Target&, const fapi::Target&, uint32_t);

extern "C"
{


// enum p8_PM_FLOW_MODE {
//         PM_CONFIG     = 0x1,
//         PM_RESET      = 0x2,
//         PM_INIT       = 0x3,
//         PM_SETUP      = 0x4,
//         PM_SETUP_PIB  = 0x5,
//         PM_SETUP_ALL  = 0x6
//         };


// Base function   
/// \param[in] i_target chip Target
/// \param[in] mode   PM_CONFIG, PM_INIT             


fapi::ReturnCode p8_pm_init(const fapi::Target  &i_target1 , const fapi::Target  &i_target2,  uint32_t mode);


}


