/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pm_occ_firinit.H $     */
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
// $Id: p8_pm_occ_firinit.H,v 1.7 2013/08/26 12:44:32 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pm_occ_firinit.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE       : proc_pm_oha_firinit.H
// *! DESCRIPTION : Configures the OCC LFIR Mask and Action 
// *!
// *! OWNER NAME: Jim Yacynych         Email: jimyac@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _P8_PM_OCC_FIRINIT_H_
#define _P8_PM_OCC_FIRINIT_H_

#include "p8_pm_firinit.H"
#include <fapi.H>

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*p8_pm_occ_firinit_FP_t) (const fapi::Target& , uint32_t mode);

const uint32_t        OCC_FIR_REGISTER_LENGTH = 64 ;


extern "C" {
//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
/// \brief  Configures the OCC LFIR Mask and Action
/// \param[in]  i_target              => Chip Target

fapi::ReturnCode 
p8_pm_occ_firinit(const fapi::Target& i_target , uint32_t mode);
 
} // extern "C"

#endif 
