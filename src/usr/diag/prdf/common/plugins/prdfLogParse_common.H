/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plugins/prdfLogParse_common.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2003,2014              */
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

#ifndef prdfLogParse_common_H
#define prdfLogParse_common_H

/** @file  prdfLogParse_common.H
 *  @brief
 */

#include <srcisrc.H>
#include <errlplugins.H>
#include <errlusrparser.H>
#include <stdint.h>

namespace PRDF
{
#ifdef PRDF_HOSTBOOT_ERRL_PLUGIN
namespace HOSTBOOT
#else
namespace FSP
#endif
{
    struct ErrorCodeDescription
    {
        uint32_t signature;
        const char * description;
    };

    struct RegisterName
    {
        uint16_t id;
        const char * registername;
        uint32_t address;
    };

/* SRC data parser */
bool srcDataParse( ErrlUsrParser & i_parser, const SrciSrc & i_src );

/* Usr data section parser */
bool logDataParse( ErrlUsrParser & i_parser, void * i_buffer,
                          uint32_t i_buflen, errlver_t i_ver,
                          errlsubsec_t i_sst );
} // namespace FSP/HOSTBBOT
} // end namespace PRDF

#endif // prdfLogParse_common_H
