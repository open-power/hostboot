/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/fapi/fapi.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
// $Id: fapi.H,v 1.9 2013/10/15 13:13:28 dcrowell Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/hwpf/working/fapi/fapi.H,v $

/**
 *  @file fapi.H
 *
 *  @brief Includes all the header files necessary for the FAPI interface.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     04/13/2011  Created.
 *                          mjjones     06/07/2011  Added new includes.
 *                          mjjones     08/08/2011  Updated Executor include
 *                          mjjones     09/23/2011  Added fapiHwpErrorInfo.H
 *                          mjjones     11/10/2011  Use ecmdDataBufferBase
 *                          mjjones     04/16/2012  Added fapiChipEcFeature.H
 *                          mjjones     11/14/2012  Added fapiSetSbeError.H
 */

#ifndef FAPI_H_
#define FAPI_H_

#include <fapiTarget.H>
#include <fapiReturnCode.H>
#include <fapiUtil.H>
#include <fapiHwAccess.H>
#include <fapiSystemConfig.H>
#include <fapiPlatTrace.H>
#include <fapiHwpExecutor.H>
#include <fapiAttributeService.H>
#include <fapiChipEcFeature.H>
#include <fapiHwpReturnCodes.H> // Generated file
#include <fapiHwpErrorInfo.H>   // Generated file
#include <fapiAttributeIds.H>   // Generated file
#include <fapiSetSbeError.H>    // Generated file
#include <ecmdDataBufferBase.H>
#include <fapiMvpdAccess.H>
#include <fapiMBvpdAccess.H>

#endif // FAPI_H_
