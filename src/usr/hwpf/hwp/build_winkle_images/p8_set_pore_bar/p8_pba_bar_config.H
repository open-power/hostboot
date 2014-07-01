/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_set_pore_bar/p8_pba_bar_config.H $ */
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
// $Id: p8_pba_bar_config.H,v 1.1 2012/09/25 20:18:52 stillgs Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Klaus P. Gungl         Email: kgungl@de.ibm.com
// *!
// *! General Description:
// *!        
// *! include file for p8_pba_bar_config 
// *!
//------------------------------------------------------------------------------
// 


// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*p8_pba_bar_config_FP_t) (const fapi::Target&, 
                                                            uint32_t, 
                                                            uint64_t, 
                                                            uint64_t, 
                                                            uint64_t);

extern "C" 
{				

fapi::ReturnCode 
p8_pba_bar_config   (const fapi::Target&    i_target, 
		             uint32_t               index, 
		             uint64_t               pba_bar_addr,
		             uint64_t               pba_bar_size,
		             uint64_t               pba_cmd_scope);
}
