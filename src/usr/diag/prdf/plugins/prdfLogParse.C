/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plugins/prdfLogParse.C $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2003,2014              */
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

