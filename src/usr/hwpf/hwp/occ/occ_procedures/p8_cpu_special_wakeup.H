/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_cpu_special_wakeup.H $ */
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
// $Id: p8_cpu_special_wakeup.H,v 1.5 2013/04/16 12:14:35 pchatnah Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_cpu_special_wakeup.H,v $
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

#define NUM_SPCWKUP_ENTITIES 4
enum PROC_SPCWKUP_ENTITY 
{
    HOST,
    FSP,
    OCC,
    PHYP = HOST,
    SPW_ALL
};



#define NUM_SPCWKUP_OPS 3
enum PROC_SPCWKUP_OPS 
{
    SPCWKUP_DISABLE,
    SPCWKUP_ENABLE,
    SPCWKUP_INIT
};


#endif  // _PROC_SPCWKUP_TGTS




//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------


// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*p8_cpu_special_wakeup_FP_t) (
                            const fapi::Target&, 
                            PROC_SPCWKUP_OPS, 
                            PROC_SPCWKUP_ENTITY         );

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
p8_cpu_special_wakeup(  const fapi::Target& i_target, 
                        PROC_SPCWKUP_OPS i_operation , 
                        PROC_SPCWKUP_ENTITY i_entity );

} // extern "C"

#endif // _PROC_CPUSPECWKUP_H_
