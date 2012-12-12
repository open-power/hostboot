/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/proc_scomoverride_chiplets/proc_scomoverride_chiplets.C $ */
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
// $Id: proc_scomoverride_chiplets.C,v 1.2 2012/10/07 18:25:47 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_scomoverride_chiplets.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_scomoverride_chiplets.C
// *! DESCRIPTION :
// *!
// *! OWNER NAME  : Joe McGill              Email: jmcgill@us.ibm.com
// *! OWNER NAME  : Jeshua Smith            Email: jeshua@us.ibm.com
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "proc_scomoverride_chiplets.H"

extern "C"
{

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// HWP entry point
//------------------------------------------------------------------------------
fapi::ReturnCode proc_scomoverride_chiplets()
{
    // return code
    fapi::ReturnCode rc;

    // mark HWP entry
    FAPI_IMP("proc_scomoverride_chiplets : Entering ...");


    // log function exit
    FAPI_IMP("proc_scomoverride_chiplets : Exiting ...");
    return rc;
}

}
