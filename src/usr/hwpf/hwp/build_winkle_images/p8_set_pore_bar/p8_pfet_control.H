/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_set_pore_bar/p8_pfet_control.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
// $Id: p8_pfet_control.H,v 1.5 2014/02/25 04:30:36 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pfet_control.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : p8_pfet_control.H
// *! DESCRIPTION : General routines for controlling EX chiplet PFET headers
// *!
// *! OWNER NAME  : Ralf Maier    Email: ralf.maier@de.ibm.com
// *! BACKUP NAME : Greg Still    Email: stillgs@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _P8_PFETCTL_H_
#define _P8_PFETCTL_H_


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "p8_pfet_types.H"

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*p8_pfet_control_FP_t) (const fapi::Target&,
                                                  uint8_t,
                                                  pfet_dom_t,
                                                  pfet_force_t);

extern "C" {

/// Controls the pfets for the specified EX chiplet
///
/// \param[in] i_target    Processor Chip target
/// \param[in] i_ex_number EX number
/// \param[in] i_domain    Domain: BOTH, ECO, CORE
/// \param[in] i_op        Operation:
///                          VON: Turns a chiplet domain on, VCS then VDD
///                          VOFF: Turns a chiplet domain off, VDD then VCS
//                           VOFF_OVERRIDE: Turns a chiplet domain off with
///                                         controller override
///
/// \retval SUCCESS if something good happens,
/// \retval BAD_RETURN_CODE otherwise
fapi::ReturnCode p8_pfet_control(const fapi::Target& i_target,
                                 uint8_t             i_ex_number,
                                 pfet_dom_t          i_domain,
                                 pfet_force_t        i_op);

} // extern "C"

#endif // _P8_PFETCTL_H_
