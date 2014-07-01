/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/cen_stopclocks/cen_stopclocks.H $ */
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
// $Id: cen_stopclocks.H,v 1.5 2013/10/10 14:23:35 mfred Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/cen_stopclocks.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE       : cen_stopclocks.H
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Mark Fredrickson  Email: mfred@us.ibm.com
// *! BACKUP NAME : Mark Bellows      Email: bellows@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// This is the header file for cen_stopclocks.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------

#ifndef CEN_STOPCLOCKSHWPB_H_
#define CEN_STOPCLOCKSHWPB_H_

#include <fapi.H>


// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*cen_stopclocks_FP_t)(const fapi::Target &,
                                                const bool,
                                                const bool,
                                                const bool,
                                                const bool,
                                                const bool);


//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{
    // Target is centaur chip

/**
 * @brief cen_stopclocks procedure:  The purpose of this procedure is to assert the tholds (stop the clocks) in the Centaur chip.
 *
 * @param[in] i_target                 Reference to centaur target
 * @param[in] i_stop_mem_clks          True if MEM chiplet clocks should be stopped, else false
 * @param[in] i_stop_nest_clks         True if NEST chiplet clocks (except for refresh clks) should be stopped, else false
 * @param[in] i_stop_dram_rfrsh_clks   If (i_stop_nest_clks==true) then true if NEST chiplet refresh clocks should be stopped, else false
 * @param[in] i_stop_tp_clks           True if PERV (TP) chiplet clocks should be stopped, else false
 * @param[in] i_stop_vitl_clks         True if PERV VITL clocks should be stopped, else false
 *
 * @return ReturnCode
 */

    fapi::ReturnCode cen_stopclocks(const fapi::Target& i_target,
                                    const bool i_stop_mem_clks,
                                    const bool i_stop_nest_clks,
                                    const bool i_stop_dram_rfrsh_clks,
                                    const bool i_stop_tp_clks,
                                    const bool i_stop_vitl_clks);

    // Target is centaur chip

} // extern "C"

#endif // CEN_STOPCLOCKSHWPB_H_
