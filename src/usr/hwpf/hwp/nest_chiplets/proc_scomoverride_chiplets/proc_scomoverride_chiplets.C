/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/proc_scomoverride_chiplets/proc_scomoverride_chiplets.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: proc_scomoverride_chiplets.C,v 1.3 2013/10/28 03:57:15 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_scomoverride_chiplets.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_scomoverride_chiplets.C
// *! DESCRIPTION : Placeholder for chiplet SCOM overrides
// *!
// *! OWNER NAME  : Joe McGill              Email: jmcgill@us.ibm.com
// *! OWNER NAME  : Jeshua Smith            Email: jeshua@us.ibm.com
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <proc_scomoverride_chiplets.H>

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
