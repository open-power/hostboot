/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/rule/prdfRuleFiles.H $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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

    // P9 Chip
    extern const char * p9_nimbus;
    extern const char * p9_eq;
    extern const char * p9_ex;
    extern const char * p9_ec;
    extern const char * p9_capp;
    extern const char * p9_pec;
    extern const char * p9_phb;
    extern const char * p9_xbus;
    extern const char * p9_obus;
    extern const char * p9_mcbist;
    extern const char * p9_mcs;
    extern const char * p9_mca;

    // Centaur Chip
//    extern const char * Membuf;
//    extern const char * Mba;

} // end namespace PRDF

#endif

