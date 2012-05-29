/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/build_winkle_images/proc_slw_build/p8_pore_static_data.c $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
/* $Id: p8_pore_static_data.c,v 1.1 2011/08/25 12:32:01 yjkim Exp $ */
/* $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/utils/p8_pore_static_data.c,v $ */
/*------------------------------------------------------------------------------*/
/* *! (C) Copyright International Business Machines Corp. 2010                  */
/* *! All Rights Reserved -- Property of IBM                                    */
/* *! *** IBM Confidential ***                                                  */
/*------------------------------------------------------------------------------*/
/* *! TITLE p7p_pore_static_data                                                */
/* *! DESCRIPTION : Static data for PORE APIs                                   */
/* *! OWNER NAME :  Nicole Schwartz  Email: nschwart@us.ibm.com                 */
/* *! BACKUP NAME :                                                             */
/* *! ADDITIONAL COMMENTS :                                                     */

/*------------------------------------------------------------------------------*/
/* Don't forget to create CVS comments when you check in your changes!          */
/*------------------------------------------------------------------------------*/
/* HvPlic include needed for PHYP, must be first include */
/*#include "HvPlicModule.H"*/
#include "p8_pore_api_custom.h"
#include "p8_pore_api.h"
#include "p8_pore_static_data.h"

/* Note: this info is a place holder until we get all other rings */
const p8_pore_ringInfoStruct P8_PORE_RINGINFO[] = {
  /*ring name            ring local address    scan region/type*/
  { "REPR_RING_C0",      0x00034A08,           0x48000080 },
  { "REPR_RING_C1",      0x00034A02,           0x48002000 },
  { "REPR_RING_C2",      0x00034A01,           0x48004000 },
  { "REPR_RING_C3",      0x00034A04,           0x48000800 },
  { "REPR_RING_C4",      0x00034A07,           0x48000100 },
  { "REPR_RING_C5",      0x00034A05,           0x48000400 },
  { "REPR_RING_C6",      0x00034A07,           0x48000100 },
  { "REPR_RING_C7",      0x00034A05,           0x48000400 },
  /* P7P data
  { "EX_ECO_BNDY",       0x00034A08,           0x48000080 },
  { "EX_ECO_GPTR",       0x00034A02,           0x48002000 },
  { "EX_ECO_MODE",       0x00034A01,           0x48004000 },
  { "EX_ECO_LBST",       0x00034A04,           0x48000800 },
  { "EX_ECO_TIME",       0x00034A07,           0x4800010000000000 },
  { "EX_ECO_ABST",       0x00034A05,           0x4800040000000000 },
  { "EX_ECO_REGF",       0x00034A03,           0x4800100000000000 },
  { "EX_ECO_REPR",       0x00034A06,           0x4800020000000000 },
  { "EX_ECO_FUNC",       0x00034800,           0x4800800000000000 },
  { "EX_ECO_L3REFR",     0x00030200,           0x0200800000000000 },
  { "EX_ECO_DPLL_FUNC",  0x00030400,           0x0400800000000000 },
  { "EX_ECO_DPLL_GPTR",  0x00030402,           0x0400200000000000 },
  { "EX_ECO_DPLL_MODE",  0x00030401,           0x0400400000000000 },
  { "EX_CORE_BNDY",      0x00033008,           0x3000008000000000 },
  { "EX_CORE_GPTR",      0x00033002,           0x3000200000000000 },
  { "EX_CORE_MODE",      0x00033001,           0x3000400000000000 },
  { "EX_CORE_LBST",      0x00033004,           0x3000080000000000 },
  { "EX_CORE_TIME",      0x00033007,           0x3000010000000000 },
  { "EX_CORE_ABST",      0x00033005,           0x3000040000000000 },
  { "EX_CORE_REGF",      0x00032003,           0x2000100000000000 },
  { "EX_CORE_REPR",      0x00033006,           0x3000020000000000 },
  { "EX_CORE_FUNC",      0x00032000,           0x2000800000000000 },
  { "EX_CORE_L2FARY",    0x00031009,           0x1000900000000000 },
  */
};

const int P8_PORE_RINGINDEX=sizeof P8_PORE_RINGINFO/sizeof P8_PORE_RINGINFO[0];

/*
*************** Do not edit this area ***************
This section is automatically updated by CVS when you check in this file.
Be sure to create CVS comments when you commit so that they can be included here.

$Log: p8_pore_static_data.c,v $
Revision 1.1  2011/08/25 12:32:01  yjkim
initial checkin

Revision 1.5  2010/10/19 22:34:41  schwartz
added #include <p7p_pore_static_data.h>

Revision 1.4  2010/08/26 15:13:33  schwartz
Fixed more C++ style comments to C style comments

Revision 1.3  2010/08/26 03:57:02  schwartz
Changed comments to C-style
Changed "" to <> for #includes
Moved RINGINFO struct and RINGINDEX constant into separate object file, includes created static_data.h file
Put p7p_pore in front of #defines
Removed ring length from ringInfoStruct
Renamed scom operators to have SCOM in the name
Fixed gen_scan to use SCANRD and SCANWR pore instructions
Fixed compiler warnings

Revision 1.2  2010/07/09 15:38:35  schwartz
Changed ring names to uppercase and updated length of rings.  Neither of these pieces of data are used in the gen_scan API, but is used when generating rings for verification

Revision 1.1  2010/06/23 23:10:06  schwartz
Moved constants ringInfoStruct and RINGINDEX into this file


*/
