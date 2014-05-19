/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pss_init.H $           */
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
// $Id: p8_pss_init.H,v 1.5 2013/08/02 19:21:26 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pss_init.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Greg Still         Email: stillgs@us.ibm.com
// *!
// *! General Description: Calls the function p8_pss_init.C
// *!        Initializes the PSS macro , resets it and configures the required
// *!        Attributes
//------------------------------------------------------------------------------


/**
 * p8_pss_init calls the underlying routine based on mode parameter
 *
 * @param[in] i_target Chip target
 * @param[in] mode     Control mode for the procedure
 *                     PM_INIT, PM_CONFIG, PM_RESET
 *
 * @retval ECMD_SUCCESS
 * @retval ERROR defined in xml
 */
typedef fapi::ReturnCode (*p8_pss_init_FP_t) (const fapi::Target&, uint32_t);

extern "C" {

fapi::ReturnCode p8_pss_init(const fapi::Target& i_target, uint32_t mode);

}
