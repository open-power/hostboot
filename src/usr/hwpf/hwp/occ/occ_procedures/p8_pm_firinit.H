/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pm_firinit.H $         */
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
// $Id: p8_pm_firinit.H,v 1.9 2013/04/01 04:27:47 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pm_firinit.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : p8_pm_firinit.H
// *! DESCRIPTION : common .H file for all FIRINITS
// *!
// *! OWNER NAME  : Greg Still    Email: stillgs@us.ibm.com
// *! BACKUP NAME : Pradeep CN    Email: padeepcn@in.ibm.com
// *!
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// MACRO structure definitions
//------------------------------------------------------------------------------

#ifndef _P8_PM_FIRINIT_H_
#define _P8_PM_FIRINIT_H_

#include "p8_pm.H"

#define SET_FIR_ACTION(b, x, y){		\
      if (x) { \
        e_rc |= action_0.setBit(b); 	\
      } \
      else \
      { \
          e_rc |= action_0.clearBit(b);  \
      } \
      if (y) { \
        e_rc |= action_1.setBit(b);  \
      } \
      else \
      { \
        e_rc |= action_1.clearBit(b);  \
      }\
     }

#define SET_FIR_MASK(b,y){			\
     if (y) { \
       e_rc |= mask.setBit(b); \
     } \
     else \
     { \
         e_rc |= mask.clearBit(b); \
     } \
     }

#define SET_CHECK_STOP(b){SET_FIR_ACTION(b, 0, 0);}
#define SET_RECOV_ATTN(b){SET_FIR_ACTION(b, 0, 1);}
#define SET_RECOV_INTR(b){SET_FIR_ACTION(b, 1, 0);}
#define SET_MALF_ALERT(b){SET_FIR_ACTION(b, 1, 1);}
#define SET_FIR_MASKED(b){SET_FIR_MASK(b,1);}

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*p8_pm_firinit_FP_t) (const fapi::Target& , uint32_t mode );


extern "C" {

/// \brief Calls each PM unit firinit procedures to configure the FIRs of the chip to  predefined types :
/// \calls p8_pm_pmc_firinit
/// \calls p8_pm_pba_firinit
/// \calls p8_pm_pcbs_firinit
/// \calls p8_pm_oha_firinit
/// \calls p8_pm_occ_firinit


const uint32_t        PCB_FIR_REGISTER_LENGTH = 43 ;
const uint32_t        PMC_FIR_REGISTER_LENGTH = 49 ;
const uint32_t        PBA_FIR_REGISTER_LENGTH = 46 ;
const uint32_t        OHA_FIR_REGISTER_LENGTH = 6 ;
const uint32_t        OCC_FIR_REGISTER_LENGTH = 64 ;

/// \  input chip_target
fapi::ReturnCode p8_pm_firinit(const fapi::Target& i_target , uint32_t mode);
 

} // extern "C"

#endif
