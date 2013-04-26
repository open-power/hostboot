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
// $Id: p8_pmc_init.H,v 1.7 2013/04/12 01:25:04 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pmc_init.H,v $
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

/// \param[in] i_target1 Primary chip target of the module
/// \param[in] i_target2 Secondary chip target (applicable to DCMs)
/// \param[in] mode     


// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*p8_pmc_init_FP_t) (  const fapi::Target& ,
                                                const fapi::Target&, 
                                                uint32_t mode);

extern "C" {


fapi::ReturnCode 
p8_pmc_init(const fapi::Target& i_target1, 
            const fapi::Target& i_target2, 
            uint32_t mode);

}


