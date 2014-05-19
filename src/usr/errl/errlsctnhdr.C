/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errlsctnhdr.C $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
/**
 *  @file errlsctnhdr.C
 *
 *  @brief Header data for any/all sections in an error log.
 *
 */




#include <assert.h>
#include <errl/errlsctnhdr.H>

namespace ERRORLOG
{

extern trace_desc_t* g_trac_errl;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ErrlSctnHdr::ErrlSctnHdr( const uint16_t     i_sid,
                          const uint16_t     i_slen,
                          const uint8_t      i_ver,
                          const uint8_t      i_sst,
                          const compId_t     i_compId ) :
iv_sid( i_sid ),
iv_ver( i_ver ),
iv_sst( i_sst ),
iv_compId(i_compId)
{
    // Caller/owner of this instance has provided the slen (section length)
    // for its data, but does not include the size of its ErrlSctnHdr.
    iv_slen =  i_slen + flatSize();
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ErrlSctnHdr::~ErrlSctnHdr()
{

}


///////////////////////////////////////////////////////////////////////////////
// Flatten the data to the output pointer given as PEL as defined in
// eCLipz and P7 Platform Event Log and SRC PLDD  mcdoc 1675

uint64_t ErrlSctnHdr::flatten( void * o_pBuffer, const uint64_t i_cbBuffer )
{
    uint64_t   l_rc = 0;

    // Compile-time assertions
    CPPASSERT( 8 == sizeof( pelSectionHeader_t ));
    CPPASSERT( 2 == sizeof( iv_sid ));
    CPPASSERT( 2 == sizeof( iv_slen ));
    CPPASSERT( 1 == sizeof( iv_ver ));
    CPPASSERT( 1 == sizeof( iv_sst ));
    CPPASSERT( 2 == sizeof( iv_compId ));

    if( i_cbBuffer >= sizeof( pelSectionHeader_t ))
    {
        // See errltypes.H for pelSectionHeader_t
        pelSectionHeader_t * p  = static_cast<pelSectionHeader_t *>(o_pBuffer);
        p->sid      = iv_sid;
        p->len      = iv_slen;
        p->ver      = iv_ver;
        p->sst      = iv_sst;
        p->compId   = iv_compId;

        l_rc = sizeof( pelSectionHeader_t );
    }
    else
    {
        TRACFCOMP( g_trac_errl, "ErrlSctnHdr::flatten: buffer too small");
    }

    return l_rc;
};

uint64_t ErrlSctnHdr::unflatten( const void * i_buf )
{
    const pelSectionHeader_t * p =
        static_cast<const pelSectionHeader_t *>(i_buf);

    iv_sid      = p->sid;
    iv_slen     = p->len;
    iv_ver      = p->ver;
    iv_sst      = p->sst;
    iv_compId   = p->compId;

    return sizeof( pelSectionHeader_t );
}

} // End namespace
