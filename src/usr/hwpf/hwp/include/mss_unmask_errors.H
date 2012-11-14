/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_initialization/mss_thermal_init/mss_unmask_errors.H $ */
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
// $Id: mss_unmask_errors.H,v 1.1 2012/09/05 21:04:20 gollub Exp $
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|   Date:  | Author: | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.1   | 09/05/12 | gollub  | Created

#ifndef _MSS_UNMASK_ERRORS_H
#define _MSS_UNMASK_ERRORS_H

/** @file  mss_unmask_errors.H
 *  @brief Utility functions to set action regs and unmask FIR bits 
 *         at the end of various mss IPL procedures.
 */


//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------

#include <fapi.H>
#include <ecmdDataBufferBase.H>



//------------------------------------------------------------------------------
// Constants and enums
//------------------------------------------------------------------------------






//------------------------------------------------------------------------------
// mss_unmask_inband_errors
//------------------------------------------------------------------------------


/**
 * @brief  To be called at the end of proc_cen_set_inband_addr.C
 *         Sets action regs and mask settings for inband errors to their 
 *         runtime settings.
 *
 * @param  i_target         Centaur target
 * @param  i_bad_rc         If proc_cen_set_inband_addr.C already has a bad rc
 *                          before it calls this function, we pass it in as 
 *                          i_bad_rc. If this function gets it's own bad local 
 *                          l_rc, i_bad_rc will be commited, and l_rc will be 
 *                          passed back as return value. Else if no l_rc, 
 *                          i_bad_rc will be be passed back as return value.
 * @return Non-SUCCESS if i_bad_rc Non_SUCCESS, or if internal function fails, 
 *         SUCCESS otherwise.
 */
fapi::ReturnCode mss_unmask_inband_errors( const fapi::Target & i_target,
                                           fapi::ReturnCode i_bad_rc );


//------------------------------------------------------------------------------
// mss_unmask_ddrphy_errors
//------------------------------------------------------------------------------


/**
 * @brief  To be called at the end of mss_ddr_phy_reset.C.
 *         Sets action regs and mask settings for ddr phy errors to their 
 *         runtime settings.
 *
 * @param  i_target         MBA target
 * @param  i_bad_rc         If mss_ddr_phy_reset.C already has a bad rc
 *                          before it calls this function, we pass it in as 
 *                          i_bad_rc. If this function gets it's own bad local 
 *                          l_rc, i_bad_rc will be commited, and l_rc will be 
 *                          passed back as return value. Else if no l_rc, 
 *                          i_bad_rc will be be passed back as return value.
 * @return Non-SUCCESS if i_bad_rc Non_SUCCESS, or if internal function fails, 
 *         SUCCESS otherwise.
 */
fapi::ReturnCode mss_unmask_ddrphy_errors( const fapi::Target & i_target,
                                           fapi::ReturnCode i_bad_rc );


//------------------------------------------------------------------------------
// mss_unmask_draminit_errors
//------------------------------------------------------------------------------


/**
 * @brief  To be called at the end of mss_draminit.C.
 *         Sets MBACALFIR action regs to their runtime settings, and unmasks
 *         errors that are valid for PRD to handle after mss_draminit procedure.
 *
 * @param  i_target         MBA target
 * @param  i_bad_rc         If mss_draminit.C already has a bad rc
 *                          before it calls this function, we pass it in as 
 *                          i_bad_rc. If this function gets it's own bad local 
 *                          l_rc, i_bad_rc will be commited, and l_rc will be 
 *                          passed back as return value. Else if no l_rc, 
 *                          i_bad_rc will be be passed back as return value.
 * @return Non-SUCCESS if i_bad_rc Non_SUCCESS, or if internal function fails, 
 *         SUCCESS otherwise.
 */
fapi::ReturnCode mss_unmask_draminit_errors( const fapi::Target & i_target,
                                             fapi::ReturnCode i_bad_rc );


//------------------------------------------------------------------------------
// mss_unmask_draminit_training_errors
//------------------------------------------------------------------------------


/**
 * @brief  To be called at the end of mss_draminit_training.C.
 *         Unmasks MBACALFIR errors that are valid for PRD to handle after
 *         mss_draminit_training procedure.
 *
 * @param  i_target         MBA target
 * @param  i_bad_rc         If mss_draminit_training.C already has a bad rc
 *                          before it calls this function, we pass it in as 
 *                          i_bad_rc. If this function gets it's own bad local 
 *                          l_rc, i_bad_rc will be commited, and l_rc will be 
 *                          passed back as return value. Else if no l_rc, 
 *                          i_bad_rc will be be passed back as return value.
 * @return Non-SUCCESS if i_bad_rc Non_SUCCESS, or if internal function fails, 
 *         SUCCESS otherwise.
 */
fapi::ReturnCode mss_unmask_draminit_training_errors( 
                                            const fapi::Target & i_target,
                                            fapi::ReturnCode i_bad_rc );


//------------------------------------------------------------------------------
// mss_unmask_draminit_training_advanced_errors
//------------------------------------------------------------------------------


/**
 * @brief  To be called at the end of mss_draminit_training_advanced.C.
 *         Unmasks MBACALFIR errors that are valid for PRD to handle after
 *         mss_draminit_training_advanced procedure.
 *
 * @param  i_target         MBA target
 * @param  i_bad_rc         If mss_draminit_training_advanced.C already has a 
 *                          bad rc before it calls this function, we pass it in 
 *                          as i_bad_rc. If this function gets it's own bad  
 *                          local l_rc, i_bad_rc will be commited, and l_rc will 
 *                          be passed back as return value. Else if no l_rc, 
 *                          i_bad_rc will be be passed back as return value.
 * @return Non-SUCCESS if i_bad_rc Non_SUCCESS, or if internal function fails, 
 *         SUCCESS otherwise.
 */
fapi::ReturnCode mss_unmask_draminit_training_advanced_errors( 
                                            const fapi::Target & i_target,
                                            fapi::ReturnCode i_bad_rc );


//------------------------------------------------------------------------------
// mss_unmask_maint_errors
//------------------------------------------------------------------------------


/**
 * @brief  To be called at the end of mss_draminit_mc.C.
 *         Sets action regs and unmasks maint errors prior to the maint logic
 *         being used in memdiags so that PRD will be able to handle them 
 *         if they happen during memdiags.
 *
 * @param  i_target         MBA target
 * @param  i_bad_rc         If mss_draminit_mc already has a 
 *                          bad rc before it calls this function, we pass it in 
 *                          as i_bad_rc. If this function gets it's own bad  
 *                          local l_rc, i_bad_rc will be commited, and l_rc will 
 *                          be passed back as return value. Else if no l_rc, 
 *                          i_bad_rc will be be passed back as return value.
 * @return Non-SUCCESS if i_bad_rc Non_SUCCESS, or if internal function fails, 
 *         SUCCESS otherwise.
 */
fapi::ReturnCode mss_unmask_maint_errors(const fapi::Target & i_target,
                                         fapi::ReturnCode i_bad_rc );


//------------------------------------------------------------------------------
// mss_unmask_fetch_errors
//------------------------------------------------------------------------------


/**
 * @brief  To be called at the end of mss_thermal_init.C.
 *         Sets action regs and unmasks fetch errors prior to the start of
 *         mainline traffic.
 *
 * @param  i_target         Centaur target
 * @param  i_bad_rc         If mss_thermal_init already has a 
 *                          bad rc before it calls this function, we pass it in 
 *                          as i_bad_rc. If this function gets it's own bad  
 *                          local l_rc, i_bad_rc will be commited, and l_rc will 
 *                          be passed back as return value. Else if no l_rc, 
 *                          i_bad_rc will be be passed back as return value.
 * @return Non-SUCCESS if i_bad_rc Non_SUCCESS, or if internal function fails, 
 *         SUCCESS otherwise.
 */
fapi::ReturnCode mss_unmask_fetch_errors(const fapi::Target & i_target,
                                         fapi::ReturnCode i_bad_rc );



//------------------------------------------------------------------------------
// fapiGetScom_w_retry
//------------------------------------------------------------------------------

/**
 * @brief     Reads a SCOM register from a Chip and retries once if SCOM fails.
 *            Retry is done with assumption that hostboot will switch from
 *            inband SCOM to FSI, so if inband failed due to channel fail,
 *            FSI may still work.
 * @param[in] i_target      Target to operate on
 * @param[in] i_address     Scom address to read from
 * @param[out] o_data       ecmdDataBufferBase object that holds data read from
 *                             address
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiGetScom_w_retry(const fapi::Target& i_target,
                                     const uint64_t i_address,
                                     ecmdDataBufferBase & o_data);

//------------------------------------------------------------------------------
// fapiPutScom_w_retry
//------------------------------------------------------------------------------

/**
 * @brief     Writes a SCOM register on a Chip and retries once if SCOM fails.
 *            Retry is done with assumption that hostboot will switch from
 *            inband SCOM to FSI, so if inband failed due to channel fail,
 *            FSI may still work.
 * @param[in] i_target Target to operate on
 * @param[in] i_address Scom address to write to
 * @param[in] i_data ecmdDataBufferBase object that holds data to write into
 *                   address
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPutScom_w_retry(const fapi::Target& i_target,
                                     const uint64_t i_address,
                                     ecmdDataBufferBase & i_data);






#endif /* _MSS_UNMASK_ERRORS_H */
