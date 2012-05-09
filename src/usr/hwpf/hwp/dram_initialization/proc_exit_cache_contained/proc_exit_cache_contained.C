/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/dram_initialization/proc_exit_cache_contained/proc_exit_cache_contained.C $
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
// $Id: proc_exit_cache_contained.C,v 1.1 2012/03/14 06:03:08 venton Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_exit_cache_contained.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_exit_cache_contained.C
// *! DESCRIPTION : 
// *!
// *! OWNER NAME  : Jeshua Smith            Email: jeshua@us.ibm.com
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "proc_exit_cache_contained.H"

extern "C"
{

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// HWP entry point
//------------------------------------------------------------------------------
fapi::ReturnCode proc_exit_cache_contained()
{
    // return code
    fapi::ReturnCode rc;

    // mark HWP entry
    FAPI_IMP("proc_exit_cache_contained : Entering ...");


    // log function exit
    FAPI_IMP("proc_exit_cache_contained : Exiting ...");
    return rc;
}

}
