/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pm_firinit.H $         */
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
// $Id: p8_pm_firinit.H,v 1.11 2013/08/26 12:42:40 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pm_firinit.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
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
#define CLEAR_FIR_MASK(b){SET_FIR_MASK(b,0);}

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*p8_pm_firinit_FP_t) (const fapi::Target& , uint32_t);


extern "C" {

/// \brief Calls each PM unit firinit procedures to configure the FIRs of the chip to  predefined types :
/// \calls p8_pm_pmc_firinit
/// \calls p8_pm_pba_firinit
/// \calls p8_pm_pcbs_firinit
/// \calls p8_pm_oha_firinit
/// \calls p8_pm_occ_firinit


//const uint32_t        PCB_FIR_REGISTER_LENGTH = 43 ;
//const uint32_t        PMC_FIR_REGISTER_LENGTH = 49 ;
//const uint32_t        PBA_FIR_REGISTER_LENGTH = 46 ;
//const uint32_t        OHA_FIR_REGISTER_LENGTH = 6 ;
//const uint32_t        OCC_FIR_REGISTER_LENGTH = 64 ;

//------------------------------------------------------------------------------
/**
 * p8_pm_firinit Call underlying FIR procedures to deal with the FIRs based on 
 *       the mode
 *
 * @param[in] i_target   Chip target which will be passed to all the procedures
 *
 * @param[in] i_mode   Control mode for the procedure
 *                     PM_INIT, PM_CONFIG, PM_RESET, PM_RESET_SOFT
 *
 * @retval ECMD_SUCCESS
 * @retval ERROR defined in xml
 */
fapi::ReturnCode p8_pm_firinit(const fapi::Target& i_target , uint32_t i_mode);
 

} // extern "C"

#endif
