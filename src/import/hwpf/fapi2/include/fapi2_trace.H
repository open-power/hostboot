/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/fapi2/include/fapi2_trace.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2024                             */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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
/* $Source: hwpf/fapi2/include/fapi2_trace.H $                            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2024                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file fapi2_trace.H
/// @brief Macros for specialized trace
/// EKB-Mirror-To: hw/ppe, hwsv, hostboot

#ifndef _FAPI2_TRACE_H_
#define _FAPI2_TRACE_H_

#ifdef __PPE__
    // Macro for simplfing FAPI_INF calls in code used in SBE/SPPE - Does nothing if PPE defined
    #define FAPI_INF_NO_SBE(_fmt_, _args_...)
#else // !defined(__PPE__)
    // Macro for simplfing FAPI_INF calls in code used in SBE/SPPE - FAPI_INF if PPE not defined
    #define FAPI_INF_NO_SBE(_fmt_, _args_...) FAPI_INF(_fmt_, ##_args_)
#endif // !defined(__PPE__)
#endif // _FAPI2_TRACE_H_
