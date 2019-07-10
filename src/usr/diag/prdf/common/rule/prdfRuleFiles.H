/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/rule/prdfRuleFiles.H $               */
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
 * @file prdfRuleFiles.H
 * @brief Contains the name of each chip's associated .prf file.
 */

namespace PRDF
{

    // P9 Nimbus Chip
    extern const char * nimbus_proc;
    extern const char * nimbus_eq;
    extern const char * nimbus_ex;
    extern const char * nimbus_ec;
    extern const char * nimbus_capp;
    extern const char * nimbus_pec;
    extern const char * nimbus_phb;
    extern const char * nimbus_xbus;
    extern const char * nimbus_obus;
    extern const char * nimbus_mcbist;
    extern const char * nimbus_mcs;
    extern const char * nimbus_mca;

    // P9 Cumulus Chip
    extern const char * cumulus_proc;
    extern const char * cumulus_eq;
    extern const char * cumulus_ex;
    extern const char * cumulus_ec;
    extern const char * cumulus_capp;
    extern const char * cumulus_pec;
    extern const char * cumulus_phb;
    extern const char * cumulus_xbus;
    extern const char * cumulus_obus;
    extern const char * cumulus_mc;
    extern const char * cumulus_mi;
    extern const char * cumulus_dmi;

    // P9 Axone Chip
    extern const char * axone_proc;
    extern const char * axone_eq;
    extern const char * axone_ex;
    extern const char * axone_ec;
    extern const char * axone_capp;
    extern const char * axone_npu;
    extern const char * axone_pec;
    extern const char * axone_phb;
    extern const char * axone_xbus;
    extern const char * axone_obus;
    extern const char * axone_mc;
    extern const char * axone_mi;
    extern const char * axone_mcc;
    extern const char * axone_omic;

    // P9 Explorer Chip
    extern const char * explorer_ocmb;

} // end namespace PRDF

#endif

