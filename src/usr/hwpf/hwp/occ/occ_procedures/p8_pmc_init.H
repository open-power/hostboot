/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pmc_init.H $           */
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
// $Id: p8_pmc_init.H,v 1.7 2013/04/12 01:25:04 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pmc_init.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Greg Stilll         Email: stillgs@us.ibm.com
// *!

// *! General Description:
// *!        This procedure is intializes / resets / configures the O2S access bridge
// *!        Target : Processor chip
//------------------------------------------------------------------------------
//  

/// \param[in] i_target1 Primary chip target of the module
/// \param[in] i_target2 Secondary chip target (applicable to DCMs)
/// \param[in] mode     


// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*p8_pmc_init_FP_t) (  const fapi::Target& ,
                                                const fapi::Target&, 
                                                uint32_t mode);

extern "C" {


fapi::ReturnCode 
p8_pmc_init(const fapi::Target& i_target1, 
            const fapi::Target& i_target2, 
            uint32_t mode);

}


