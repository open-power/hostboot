/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_oha_init.H $           */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
// $Id: p8_oha_init.H,v 1.2 2012/11/27 18:11:53 stillgs Exp $
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
  /// \param[in]      &i_target           Chip target
  /// \param[in]      i_mode                Mode 1:    CONFIG-Mode
  ///                                     Mode 2:    RESET-Mode
  ///                                     Mode 3:    INIT-Mode
  
fapi::ReturnCode p8_oha_init          (const fapi::Target& i_target, uint32_t i_mode);


}


