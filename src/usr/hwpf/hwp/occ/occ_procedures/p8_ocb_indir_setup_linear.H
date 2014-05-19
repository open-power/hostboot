/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_ocb_indir_setup_linear.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: p8_ocb_indir_setup_linear.H,v 1.3 2012/11/30 00:06:44 jimyac Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_ocb_indir_setup_linear.H,v $
#ifndef _P8_OCB_INDIR_SETUP_LINEAR_H_
#define _P8_OCB_INDIR_SETUP_LINEAR_H_

#include <fapi.H>
#include "p8_pm.H"
#include "p8_ocb_init.H"

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*p8_ocb_indir_setup_linear_FP_t) (const fapi::Target&,
                                                            const uint8_t,
                                                            const uint8_t,
                                                            const uint32_t);

extern "C" {

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
/// \brief  Configure OCB Channel for Linear Streaming or Non-streaming mode
/// \param[in]  i_target              => Chip Target
/// \param[in]  i_ocb_chan            => select channel 0-3 to set up      (see p8_ocb_init.H)
/// \param[in]  i_ocb_type            => linear streaming or non-streaming (see p8_ocb_init.H)
/// \param[in]  i_ocb_bar             => 32-bit channel base address (29 bits + "000")

fapi::ReturnCode p8_ocb_indir_setup_linear(const fapi::Target& i_target,
                                           const uint8_t       i_ocb_chan,
                                           const uint8_t       i_ocb_type,
                                           const uint32_t      i_ocb_bar);

} // extern "C"

#endif
