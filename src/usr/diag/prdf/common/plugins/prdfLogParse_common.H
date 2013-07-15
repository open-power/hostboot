/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plugins/prdfLogParse_common.H $      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2003,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
