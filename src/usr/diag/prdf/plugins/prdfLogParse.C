/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plugins/prdfLogParse.C $                    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2003,2013              */
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

/** @file prdfLogParse.C
 *  @brief Hostboot error log plugin parser
 */

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <prdfLogParse_common.H>

//------------------------------------------------------------------------------

// Parser plugins

static errl::SrcPlugin  g_SrcPlugin( PRDF_COMP_ID,
                                     PRDF::HOSTBOOT::srcDataParse,
                                     ERRL_CID_HOSTBOOT);
static errl::DataPlugin g_DataPlugin( PRDF_COMP_ID,
                                      PRDF::HOSTBOOT::logDataParse,
                                      ERRL_CID_HOSTBOOT);

