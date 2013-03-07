/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pmc_init.H $           */
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
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Greg Stilll         Email: stillgs@us.ibm.com
// *!
// *! General Description:
// *!        This procedure is intializes / resets / configures the O2S access bridge
// *!        Target : Processor chip
//------------------------------------------------------------------------------
//  

/// \param[in] i_target Chip target
/// \param[in] mode     


// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*p8_pmc_init_FP_t) (const fapi::Target&, uint32_t mode);

extern "C" {

// enum p8_PM_FLOW_MODE {
//         PM_CONFIG     = 0x1,
//         PM_RESET      = 0x2,
//         PM_INIT       = 0x3,
//         PM_SETUP      = 0x4,
//         PM_SETUP_PIB  = 0x5,
//         PM_SETUP_ALL  = 0x6
//         };


fapi::ReturnCode p8_pmc_init(const fapi::Target& i_target, uint32_t mode);

}


