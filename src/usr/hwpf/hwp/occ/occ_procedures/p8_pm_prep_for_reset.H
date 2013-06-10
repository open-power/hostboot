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
// $Id: p8_pm_prep_for_reset.H,v 1.8 2013/03/27 08:34:05 pchatnah Exp $
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

#include "proc_cpu_special_wakeup.H"
#include "p8_pm.H"
#include "p8_poregpe_init.H"
#include "p8_pcbs_init.H"
#include "p8_pmc_init.H"
#include "p8_poreslw_init.H"
#include "p8_poregpe_init.H"
#include "p8_oha_init.H"
#include "p8_pba_init.H"    //FIXME was not compiling check with Klaus
#include "p8_occ_sram_init.H"
#include "p8_ocb_init.H"
#include "p8_pss_init.H"
#include "p8_pmc_force_vsafe.H"
#include "p8_occ_control.H"
#include "p8_pm_firinit.H"


/**
* @brief Function pointer typedef.
*/
// typedef fapi::ReturnCode (*p8_occ_control_FP_t)       (Target i_target, uint32_t ppc405_reset_ctrl, uint32_t sram_bv_ctrl);
// //typedef fapi::ReturnCode (*p8_cpu_special_wakeup_FP_t)(Target i_target, uint32_t mode);
// //typedef fapi::ReturnCode (*p8_cpu_special_wakeup_FP_t)(Target i_target, uint8_t, uint8_t);

// typedef fapi::ReturnCode (*p8_pmc_force_vsafe_FP_t)   (Target i_target);
// typedef fapi::ReturnCode (*p8_pcbs_init_FP_t)         (const fapi::Target&, uint32_t );
// typedef fapi::ReturnCode (*p8_pmc_init_FP_t)          (const fapi::Target&, uint32_t );
// typedef fapi::ReturnCode (*p8_poreslw_init_FP_t)      (const fapi::Target&, uint32_t);
// typedef fapi::ReturnCode (*p8_poregpe_init_FP_t)      (const fapi::Target&, uint32_t, uint32_t);
// typedef fapi::ReturnCode (*p8_oha_init_FP_t)          (const fapi::Target&, uint32_t);
// typedef fapi::ReturnCode (*p8_pba_init_FP_t)          (const fapi::Target&, uint32_t);
// typedef fapi::ReturnCode (*p8_occ_sram_init_FP_t)     (const fapi::Target&, uint32_t);
// typedef fapi::ReturnCode (*p8_ocb_init_FP_t)          (const fapi::Target&, uint32_t);
 typedef fapi::ReturnCode (*p8_pm_prep_for_reset_FP_t) (const fapi::Target &i_primary_chip_target , const fapi::Target &i_secondary_chip_target  );


extern "C"
{

  /// \brief Prepare powermanagement components for reset
  /// i_primary_chip_target                       Primary Chip target which will be passed to all the procedures
  /// i_secondary_chip_target                     Secondary Chip target will be passed for pmc_init -reset only if it is DCM otherwise 

  fapi::ReturnCode p8_pm_prep_for_reset(const fapi::Target &i_primary_chip_target , const fapi::Target &i_secondary_chip_target  );
  
  
// p8_occ_control   
// fapi::ReturnCode p8_occ_control(Target &i_target, uint32_t ppc405_reset_ctrl, uint32_t sram_bv_ctrl);

// // p8_cpu_special_wakeup
// //fapi::ReturnCode p8_cpu_special_wakeup(const Target &i_target, uint32_t mode);
// //fapi::ReturnCode p8_cpu_special_wakeup(const Target &i_target, uint8_t entity, uint8_t operation);

// // p8_pmc_force_vsafe
// fapi::ReturnCode p8_pmc_force_vsafe(const Target &i_target);

// // p8_pcbs_init
// fapi::ReturnCode p8_pcbs_init(const Target &i_target, uint32_t mode);

// // p8_pmc_init
// fapi::ReturnCode p8_pmc_init(const Target &i_target, uint32_t mode);

// //p8_poreslw_init
// fapi::ReturnCode p8_poreslw_init(const fapi::Target& i_target, uint32_t mode);

// //p8_poregpe_init
// fapi::ReturnCode p8_poregpe_init(const fapi::Target& i_target, uint32_t mode, uint32_t engine);

// //p8_oha_init
// fapi::ReturnCode p8_oha_init(const fapi::Target& i_target, uint32_t mode);

// //p8_pba_init
// fapi::ReturnCode p8_pba_init(const fapi::Target& i_target, uint32_t mode);

// //p8_occ_sram_init
// fapi::ReturnCode p8_occ_sram_init(const fapi::Target& i_target, uint32_t mode);

// //p8_ocb_init
// fapi::ReturnCode p8_ocb_init(const fapi::Target& i_target, uint32_t mode);


}


