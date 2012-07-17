/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/build_winkle_images/proc_set_pore_bar/proc_pm.H $
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
// $Id: proc_pm.H,v 1.4 2012/05/22 14:05:53 jimyac Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_pm.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_pm.H
// *! DESCRIPTION : Common header for Power Manangement procedures
// *!
// *! OWNER NAME  : Greg Still    Email: stillgs@us.ibm.com
// *! BACKUP NAME : Jim Yacynych  Email: jimyac@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_PM_H_
#define _PROC_PM_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi.H>

#include "p8_scom_addresses.H"


extern "C" {

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------


#ifndef _PROC_PM_FLOW_MODE
#define _PROC_PM_FLOW_MODE
enum PROC_PM_FLOW_MODE {
        PM_CONFIG     = 0x1,
        PM_RESET      = 0x2,
        PM_INIT       = 0x3,
        PM_SETUP      = 0x4,
        PM_SETUP_PIB  = 0x5,
        PM_SETUP_ALL  = 0x6
        };
#endif  // _PROC_PM_FLOW_MODE


} // extern "C"

#endif // _PROC_PM_H_
