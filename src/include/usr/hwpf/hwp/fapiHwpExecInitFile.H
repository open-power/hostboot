//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/hwpf/hwp/fapiTestHwp.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
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
