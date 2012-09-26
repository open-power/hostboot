/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_pba_bar_config/p8_pba_bar_config.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: p8_pba_bar_config.H,v 1.1 2012/09/25 20:18:52 stillgs Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
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
