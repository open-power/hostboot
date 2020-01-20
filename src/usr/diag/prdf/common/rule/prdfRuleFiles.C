/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/rule/prdfRuleFiles.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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

#ifndef __PRDFRULEFILES_H
#define __PRDFRULEFILES_H

/**
 * @file prdfRuleFiles.C
 * @brief Contains the name of each chip's associated .prf file.
 */

namespace PRDF
{
    // P9 Axone Chip
    const char * axone_proc = "axone_proc";
    const char * axone_eq   = "axone_eq";
    const char * axone_ex   = "axone_ex";
    const char * axone_ec   = "axone_ec";
    const char * axone_capp = "axone_capp";
    const char * axone_npu  = "axone_npu";
    const char * axone_pec  = "axone_pec";
    const char * axone_phb  = "axone_phb";
    const char * axone_xbus = "axone_xbus";
    const char * axone_obus = "axone_obus";
    const char * axone_mc   = "axone_mc";
    const char * axone_mi   = "axone_mi";
    const char * axone_mcc  = "axone_mcc";
    const char * axone_omic = "axone_omic";

    // P9 Explorer Chip
    const char * explorer_ocmb = "explorer_ocmb";

} // end namespace PRDF

#endif

