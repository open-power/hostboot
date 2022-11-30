/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/rule/prdfRuleFiles.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2022                        */
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
    // P10 Chip
    const char * p10_proc = "p10_proc";
    const char * p10_eq   = "p10_eq";
    const char * p10_core = "p10_core";
    const char * p10_pec  = "p10_pec";
    const char * p10_phb  = "p10_phb";
    const char * p10_mc   = "p10_mc";
    const char * p10_mi   = "p10_mi";
    const char * p10_mcc  = "p10_mcc";
    const char * p10_omic = "p10_omic";
    const char * p10_iohs = "p10_iohs";
    const char * p10_nmmu = "p10_nmmu";
    const char * p10_pauc = "p10_pauc";
    const char * p10_pau  = "p10_pau";


    // OCMB Chip
    const char * explorer_ocmb = "explorer_ocmb";
    const char * odyssey_ocmb  = "odyssey_ocmb";

} // end namespace PRDF

#endif

