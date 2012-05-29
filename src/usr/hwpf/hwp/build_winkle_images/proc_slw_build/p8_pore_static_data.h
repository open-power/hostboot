/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/build_winkle_images/proc_slw_build/p8_pore_static_data.h $
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
/* $Id: p8_pore_static_data.h,v 1.1 2011/08/25 12:31:51 yjkim Exp $ */
/* $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/utils/p8_pore_static_data.h,v $ */
/*------------------------------------------------------------------------------*/
/* *! (C) Copyright International Business Machines Corp. 2010                  */
/* *! All Rights Reserved -- Property of IBM                                    */
/* *! *** IBM Confidential ***                                                  */
/*------------------------------------------------------------------------------*/
/* *! TITLE p8_pore_static_data                                                */
/* *! DESCRIPTION : Static data for PORE APIs                                   */
/* *! OWNER NAME :  Nicole Schwartz  Email: nschwart@us.ibm.com                 */
/* *! BACKUP NAME :                                                             */
/* *! ADDITIONAL COMMENTS :                                                     */
/*                                                                              */
/*------------------------------------------------------------------------------*/
/* Don't forget to create CVS comments when you check in your changes!          */
/*------------------------------------------------------------------------------*/

#ifndef _P8_PORE_STATIC_DATA_H
#define _P8_PORE_STATIC_DATA_H

extern const p8_pore_ringInfoStruct P8_PORE_RINGINFO[];
extern const int P8_PORE_RINGINDEX;

#endif /* _P8_PORE_STATIC_DATA_H */

/*
*************** Do not edit this area ***************
This section is automatically updated by CVS when you check in this file.
Be sure to create CVS comments when you commit so that they can be included here.

$Log: p8_pore_static_data.h,v $
Revision 1.1  2011/08/25 12:31:51  yjkim
initial check-in

Revision 1.2  2010/08/26 15:13:34  schwartz
Fixed more C++ style comments to C style comments

Revision 1.1  2010/08/26 03:57:02  schwartz
Changed comments to C-style
Changed "" to <> for #includes
Moved RINGINFO struct and RINGINDEX constant into separate object file, includes created static_data.h file
Put p7p_pore in front of #defines
Removed ring length from ringInfoStruct
Renamed scom operators to have SCOM in the name
Fixed gen_scan to use SCANRD and SCANWR pore instructions
Fixed compiler warnings


*/
