/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_ocb_indir_setup_linear.C $ */
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
// $Id: p8_ocb_indir_setup_linear.C,v 1.2 2012/10/10 14:47:19 pchatnah Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_ocb_indir_setup_linear.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Jim Yacynych         Email: jimyac@us.ibm.com
// *!
/// \file p8_ocb_indir_setup_linear.C
/// \brief  Configure OCB Channel for Linear Streaming or Non-streaming mode
///
/// High-level procedure flow:
/// \verbatim
///  Setup specified channel to linear streaming or non-streaming mode by calling proc proc_ocb_init
///
///  Procedure Prereq:
///     - System clocks are running
/// \endverbatim
///
//------------------------------------------------------------------------------

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------

#include "p8_pm.H"
#include "p8_ocb_indir_setup_linear.H"

extern "C" {

using namespace fapi;

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------
/// \param[in]  i_target              => Chip Target
/// \param[in]  i_ocb_chan            => select channel 0-3 to set up      (see p8_ocb_init.H)
/// \param[in]  i_ocb_type            => linear streaming or non-streaming (see p8_ocb_init.H)
/// \param[in]  i_ocb_bar             => 32-bit channel base address (29 bits + "000")
/// \retval FAPI_RC_SUCCESS
/// \retval ERROR defined in xml for p8_ocb_init

ReturnCode
p8_ocb_indir_setup_linear(const Target& i_target, uint8_t i_ocb_chan, uint8_t i_ocb_type, uint32_t i_ocb_bar)
{
    ReturnCode rc;

    FAPI_INF("Executing p8_ocb_indir_setup_linear for channel %x as type %x to address 0x%x\n", i_ocb_chan, i_ocb_type, i_ocb_bar);

    FAPI_EXEC_HWP(rc, p8_ocb_init, i_target, PM_SETUP_PIB, i_ocb_chan, i_ocb_type, i_ocb_bar, 0, OCB_Q_ITPTYPE_NULL, OCB_Q_ITPTYPE_NULL);
    if (!rc.ok()) {
        FAPI_ERR("Error calling proc_ocb_init from p8_ocb_indir_setup_linear. \n");
        return rc;
    }

    return rc;
}

} //end extern C
