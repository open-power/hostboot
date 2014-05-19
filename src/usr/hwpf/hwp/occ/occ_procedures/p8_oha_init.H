/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_oha_init.H $           */
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
// $Id: p8_oha_init.H,v 1.3 2013/08/02 19:00:26 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_oha_init.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : p8_oha_init.H
// *! DESCRIPTION : Initialize OHA
// *!
// *! OWNER NAME: Ralf Maier         Email: ralf.maier@de.ibm.com
// *!
// *!
//------------------------------------------------------------------------------
//  

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*p8_oha_init_FP_t) (const fapi::Target&, uint32_t);

extern "C"
{


  /// \brief Initialize OHA
  /// 
  /// \param[in]      &i_target Chip target
  /// \param[in]      i_mode    CONFIG-Mode
  ///                           RESET-Mode
  ///                           INIT-Mode
  ///                           defined in p8_pm.H, enum P8_PM_FLOW_MODE
  
fapi::ReturnCode p8_oha_init    (const fapi::Target& i_target, uint32_t i_mode);


}


