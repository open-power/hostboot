/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/rule/prdfRuleFiles.H $               */
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
 * @file prdfRuleFiles.H
 * @brief Contains the name of each chip's associated .prf file.
 */

namespace PRDF
{
    // P10 Chip
    extern const char * p10_proc;
    extern const char * p10_eq;
    extern const char * p10_core;
    extern const char * p10_pec;
    extern const char * p10_phb;
    extern const char * p10_mc;
    extern const char * p10_mcc;
    extern const char * p10_omic;
    extern const char * p10_iohs;
    extern const char * p10_nmmu;
    extern const char * p10_pauc;
    extern const char * p10_pau;

    // OCMB Chip
    extern const char * explorer_ocmb;
    extern const char * odyssey_ocmb;

} // end namespace PRDF

#endif

