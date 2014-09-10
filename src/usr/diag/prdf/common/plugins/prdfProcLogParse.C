/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plugins/prdfProcLogParse.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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

/** @file  prdfProcLogParse.C
 *  @brief Error log parsing code specific to the processor subsystem.
 */

#include <prdfProcLogParse.H>

#include <errlusrparser.H>
#include <cstring>
#include <iipconst.h>
#include <prdfParserEnums.H>
#include <netinet/in.h>

namespace PRDF
{

#ifdef PRDF_HOSTBOOT_ERRL_PLUGIN
namespace HOSTBOOT
#else
namespace FSP
#endif
{

using namespace PARSER;

//------------------------------------------------------------------------------

bool parseSlwFfdcData( uint8_t * i_buffer, uint32_t i_buflen,
                       ErrlUsrParser & i_parser )
{
    char hdr[HEADER_SIZE] = "";
    char data[DATA_SIZE]  = "";

    snprintf( hdr, HEADER_SIZE, " %s", SLW_FFDC_DATA::title );
    i_parser.PrintString( hdr, "" );

    const size_t sz_word = sizeof(uint32_t);

    uint32_t idx = 0;
    while ( idx + SLW_FFDC_DATA::ENTRY_SIZE < i_buflen )
    {
        uint32_t addr, val0, val1;

        memcpy( &addr, &i_buffer[idx            ], sz_word );
        memcpy( &val0, &i_buffer[idx+(1*sz_word)], sz_word );
        memcpy( &val1, &i_buffer[idx+(2*sz_word)], sz_word );

        addr = htonl(addr);
        val0 = htonl(val0);
        val1 = htonl(val1);

        snprintf(hdr,  HEADER_SIZE, "  Address: 0x%08x", addr );
        snprintf(data, DATA_SIZE,   "Value: 0x%08x 0x%08x", val0, val1 );

        i_parser.PrintString( hdr, data );

        idx += SLW_FFDC_DATA::ENTRY_SIZE;
    }

    return true;
}

//------------------------------------------------------------------------------

} // namespace FSP/HOSTBBOT
} // end namespace PRDF

