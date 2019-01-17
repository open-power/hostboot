/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/rule/prdfRuleFiles.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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
    // P9 Nimbus Chip
    const char * nimbus_proc    = "nimbus_proc";
    const char * nimbus_eq      = "nimbus_eq";
    const char * nimbus_ex      = "nimbus_ex";
    const char * nimbus_ec      = "nimbus_ec";
    const char * nimbus_capp    = "nimbus_capp";
    const char * nimbus_pec     = "nimbus_pec";
    const char * nimbus_phb     = "nimbus_phb";
    const char * nimbus_xbus    = "nimbus_xbus";
    const char * nimbus_obus    = "nimbus_obus";
    const char * nimbus_mcbist  = "nimbus_mcbist";
    const char * nimbus_mcs     = "nimbus_mcs";
    const char * nimbus_mca     = "nimbus_mca";
    const char * nimbus_nvdimm  = "nimbus_nvdimm";

    // P9 Cumulus Chip
    const char * cumulus_proc = "cumulus_proc";
    const char * cumulus_eq   = "cumulus_eq";
    const char * cumulus_ex   = "cumulus_ex";
    const char * cumulus_ec   = "cumulus_ec";
    const char * cumulus_capp = "cumulus_capp";
    const char * cumulus_pec  = "cumulus_pec";
    const char * cumulus_phb  = "cumulus_phb";
    const char * cumulus_xbus = "cumulus_xbus";
    const char * cumulus_obus = "cumulus_obus";
    const char * cumulus_mc   = "cumulus_mc";
    const char * cumulus_mi   = "cumulus_mi";
    const char * cumulus_dmi  = "cumulus_dmi";

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

    // Centaur Chip
    const char * centaur_membuf = "centaur_membuf";
    const char * centaur_mba    = "centaur_mba";

} // end namespace PRDF

#endif

