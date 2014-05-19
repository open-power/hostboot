/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/utility_procedures/proc_cpu_special_wakeup.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: proc_cpu_special_wakeup.H,v 1.8 2012/08/21 11:39:37 pchatnah Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_cpu_special_wakeup.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_cpu_special_wakeup.H
// *! DESCRIPTION : Set the EX chiplet into Special Wake-up via one of the 
// *!               entity bits provided
// *!
// *! OWNER NAME  : Greg Still    Email: stillgs@us.ibm.com
// *! BACKUP NAME : Pradeep CN    Email: padeepcn@in.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_CPUSPECWKUP_H_
#define _PROC_CPUSPECWKUP_H_


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

#ifndef _PROC_SPCWKUP_ENTITY
#define _PROC_SPCWKUP_ENTITY
enum PROC_SPCWKUP_ENTITY 
{
    HOST   = 0X1,
    FSP    = 0x2,
    OCC    = 0x3,
    PHYP   = HOST

};
        
        
enum PROC_SPCWKUP_OPS 
{
    SPCWKUP_ENABLE   = 0x1,
    SPCWKUP_DISABLE  = 0x2
};

#endif  // _PROC_SPCWKUP_TGTS




//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------


// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*proc_cpu_special_wakeup_FP_t) (const fapi::Target&, PROC_SPCWKUP_OPS , PROC_SPCWKUP_ENTITY  );

extern "C" {



//------------------------------------------------------------------------------
// Parameter structure definitions
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
/// \param[in] i_target EX target
/// \param[in] i_entity   Entity bit to use (OCC, PHYP, FSP)
/// \param[in] i_operation   operation to use (SPCWKUP_ENABLE, SPCWKUP_DISABLE)


/// \retval ECMD_SUCCESS if something good happens,
/// \retval BAD_RETURN_CODE otherwise
fapi::ReturnCode 
proc_cpu_special_wakeup(const fapi::Target& i_target, PROC_SPCWKUP_OPS i_operation , PROC_SPCWKUP_ENTITY i_entity );


} // extern "C"

#endif // _PROC_CPUSPECWKUP_H_
