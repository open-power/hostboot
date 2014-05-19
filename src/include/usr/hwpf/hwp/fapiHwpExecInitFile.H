/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/fapiHwpExecInitFile.H $              */
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
/**
 *  @file fapiHwpExecInitFile.H
 *
 *  @brief Defines for Hardware Procedure initfile execution
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          camvanng    09/29/2011  Created.
 *                          andrewg     11/16/2011  Refactor includes with initfile compiler
 *                          camvanng    11/16/2011  Define function pointer to HWP
 *                          camvanng    05/07/2012  Support for associated target attributes
 *
 */

#ifndef FAPIHWPEXECINITFILE_H_
#define FAPIHWPEXECINITFILE_H_

#include <fapi.H>
#include <fapiHwpInitFileInclude.H>

// HWPs are defined as C functions because platforms may wish to package them
// in linux shared libraries which are DL-Opened
extern "C"
{

//Provided for platforms that need to cast a generic function pointer into a
//function pointer of the correct type to call the HWP.
typedef fapi::ReturnCode (*fapiHwpExecInitFile_FP_t)(const std::vector<fapi::Target> & i_target,
                                                     const char * i_file);
/**
* @brief HWP to execute an initfile.
*
* @param[in] i_target Reference to std::vector of targets
* @param[in] i_file filename of binary initfile 
*
* @return ReturnCode
*/
fapi::ReturnCode fapiHwpExecInitFile(const std::vector<fapi::Target> & i_target,
                                     const char * i_file);

} // extern "C"

#endif // FAPIHWPEXECINITFILE_H_
