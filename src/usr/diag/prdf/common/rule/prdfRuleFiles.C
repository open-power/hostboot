/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/rule/prdfRuleFiles.C $               */
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
 * @file prdfRuleFiles.C
 * @brief Contains the name of each chip's associated .prf file.
 */

namespace PRDF
{
    // P9 Chip
    const char * p9_nimbus  = "p9_nimbus";
    const char * p9_eq      = "p9_eq";
    const char * p9_ex      = "p9_ex";
    const char * p9_ec      = "p9_ec";
    const char * p9_capp    = "p9_capp";
    const char * p9_pec     = "p9_pec";
    const char * p9_phb     = "p9_phb";
    const char * p9_xbus    = "p9_xbus";
    const char * p9_obus    = "p9_obus";
    const char * p9_mcbist  = "p9_mcbist";
    const char * p9_mcs     = "p9_mcs";
    const char * p9_mca     = "p9_mca";

    // Pegasus Centaur Chip
//    const char * Membuf     = "Membuf";
//    const char * Mba        = "Mba";

} // end namespace PRDF

#endif

