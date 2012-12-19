/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_set_pore_bar/p8_pfet_types.H $ */
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
// $Id: p8_pfet_types.H,v 1.1 2012/12/12 04:29:27 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pfet_types.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : p8_pfet_types.H
// *! DESCRIPTION : General routines for controlling EX chiplet PFET headers
// *!
// *! OWNER NAME  : Ralf Maier    Email: ralf.maier@de.ibm.com
// *! BACKUP NAME : Greg Still    Email: stillgs@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _P8_PFETTYPE_H_
#define _P8_PFETTYPE_H_


extern "C" {

// valid domain options
typedef enum  pfet_dom_type
{
  BOTH,         // write to both domains
  ECO,          // eco only
  CORE,         // core only
} pfet_dom_t;


// valid force options
typedef enum  pfet_force_type
{
  NONE,         // no operation (00)
  VOFF,         // voff (01)
  VRET,         // Vret (10)... not supported
  VON,          // von (11)
  NO_FORCE_PARM // use this when not writing to reg.
} pfet_force_t;


} // extern "C"

#endif // _P8_PFETTYPE_H_
