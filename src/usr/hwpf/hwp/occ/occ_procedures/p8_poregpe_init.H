/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_poregpe_init.H $       */
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
/* begin_generated_IBM_copyright_prolog                            */
/*                                                                 */
/* This is an automatically generated copyright prolog.            */
/* After initializing,  DO NOT MODIFY OR MOVE                      */ 
/* --------------------------------------------------------------- */
/* IBM Confidential                                                */
/*                                                                 */
/* Licensed Internal Code Source Materials                         */
/*                                                                 */
/* (C)Copyright IBM Corp.  2014, 2014                              */
/*                                                                 */
/* The Source code for this program is not published  or otherwise */
/* divested of its trade secrets,  irrespective of what has been   */
/* deposited with the U.S. Copyright Office.                       */
/*  -------------------------------------------------------------- */
/*                                                                 */
/* end_generated_IBM_copyright_prolog                              */
// $Id: p8_poregpe_init.H,v 1.1 2012/08/23 04:58:56 stillgs Exp $
// $Source: /afs/awd.austin.ibm.com/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_poregpe_init.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : p8_poregpe_init.H
// *! DESCRIPTION : Initialize the PORE GPE Engines in the OCC
// *!
// *! OWNER NAME  : Greg Still    Email: stillgs@us.ibm.com
// *! BACKUP NAME : Jim Yacynych  Email: jimyac@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _P8_POREGPE_H_
#define _P8_POREGPE_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------


// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*p8_poregpe_init_FP_t) (const fapi::Target&, uint32_t, uint32_t);

extern "C" {


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

#ifndef _P8_POREGPE_ENGINES
#define _P8_POREGPE_ENGINES
enum P8_POREGPE_ENGINES {
        GPE0        = 0x0,
        GPE1        = 0x1,
        GPEALL      = 0XF
        };
#endif  // _P8_POREGPE_ENGINES


//------------------------------------------------------------------------------
// Parameter structure definitions
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
/// \param[in] i_target Chip target
/// \param[in] mode     Control mode for the procedure (PM_CONFIG, PM_RESET)
/// \param[in] engine   Targeted engine:  GPE0, GPE1, GPEALL

/// \retval ECMD_SUCCESS if something good happens,
/// \retval BAD_RETURN_CODE otherwise
fapi::ReturnCode 
p8_poregpe_init(const fapi::Target& i_target, uint32_t mode, uint32_t engine);


} // extern "C"

#endif // _P8_POREGPE_H_
