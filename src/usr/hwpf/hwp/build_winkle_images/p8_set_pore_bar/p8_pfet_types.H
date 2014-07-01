/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_set_pore_bar/p8_pfet_types.H $ */
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
// $Id: p8_pfet_types.H,v 1.3 2013/05/17 20:15:44 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pfet_types.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
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
  NONE,          // no operation (00)
  VOFF,          // voff (01)
  VRET,          // Vret (10)... not supported
  VON,           // von (11)
  NO_FORCE_PARM, // use this when not writing to reg.
  VOFF_OVERRIDE
} pfet_force_t;

// valid read options
typedef enum  pfet_read_type
{
  PFET_READ_VOFF,
  PFET_READ_VREG,
  PFET_READ_VON,
  PFET_READ_VBETWEEN,
  PFET_READ_VOFFOVRD
} pfet_read_t;


} // extern "C"

#endif // _P8_PFETTYPE_H_
