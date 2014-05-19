/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errlud.C $                                       */
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
 *  @file errlud.C
 *
 *  @brief <Brief Description of this file>
 *
 *  <Detailed description of what this file does, functions it includes,
 *  etc,>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <hbotcompid.H>
#include <errl/errlentry.H>



namespace ERRORLOG
{


extern trace_desc_t* g_trac_errl;


//***************************************************************************
// Constructor

ErrlUD::ErrlUD(
    const void * i_data,
    uint64_t     i_size,
    compId_t     i_compid,
    uint8_t      i_ver,
    uint8_t      i_sst )  :

    ErrlSctn( ERRL_SID_USER_DEFINED, 0, i_ver, i_sst, i_compid ),
    iv_pData( NULL ),
    iv_Size( 0 )
{
    uint64_t l_cb;

    l_cb = addData( i_data, i_size );
    if( 0 == l_cb )
    {
        // Rare.
        TRACFCOMP( g_trac_errl, "ErrlUD::ErrlUD(): addData rets error");
    }
}





/*****************************************************************************/
// Destructor

ErrlUD::~ErrlUD()
{
    free( iv_pData );
}





/*****************************************************************************/
// Add data. This works the first time when there is no data and works for
// subsequent times when you want to append data. Return [new] size of buffer.

uint64_t ErrlUD::addData(const void *i_data, const uint64_t i_size)
{
    // Expected new size of user data.
    uint64_t l_newsize = iv_Size + i_size;

    // Resize memory block
    iv_pData = static_cast<uint8_t*>(realloc(iv_pData, l_newsize));

    // Copy new data to new area, past existing data (if any)
    memcpy( iv_pData + iv_Size, i_data, i_size );

    // Save new size of the user-provided data. This will also
    // be what this method returns.
    iv_Size = l_newsize;

    return iv_Size;
}



/*****************************************************************************/
// Data Export size

uint64_t ErrlUD::flatSize()
{
    uint64_t	l_rc = 0;

    l_rc = iv_header.flatSize() + iv_Size;

    // Round up to next nearest 4-byte boundary.
    l_rc = ( l_rc + 3 ) & ~3; 

    return l_rc;
}


/*****************************************************************************/
// Data Export. Return how many bytes were written or zero on error.

uint64_t ErrlUD::flatten( void * o_pBuffer, const uint64_t i_cbBuffer )
{
    uint64_t  l_rc = 0;
    uint64_t  l_cb = 0;
    uint8_t * pBuffer = static_cast<uint8_t *>(o_pBuffer);
    uint64_t  l_cbFlat = this->flatSize();

    if ( i_cbBuffer >= l_cbFlat )
    {
        // Tell the PEL section header what is the new length.
        iv_header.iv_slen = l_cbFlat;

        // Flatten the PEL section header
        l_cb = iv_header.flatten( pBuffer, i_cbBuffer );
        pBuffer += l_cb;

        // Followed by the user data
        memcpy( pBuffer, iv_pData, iv_Size );
        pBuffer += iv_Size;

        // Buffer is rounded up to the nearst 4-byte boundary, pad with zeroes
        for (uint64_t i = l_cb + iv_Size; i < l_cbFlat; i++)
        {
            *pBuffer++ = 0;
        }

        // return how many bytes were flattened
        l_rc = l_cbFlat;
    }
    else
    {
        TRACFCOMP( g_trac_errl, "ErrlUD::flatten: buffer too small");
    }


    return l_rc;
}



uint64_t ErrlUD::unflatten( const void * i_buf )
{
    const uint8_t * p =
        static_cast<const uint8_t *>(i_buf);

    p += iv_header.unflatten(p);

    iv_Size = iv_header.iv_slen - iv_header.flatSize();
    
    iv_pData = static_cast<uint8_t*>(realloc(iv_pData, iv_Size));

    memcpy(iv_pData,p,iv_Size);

    return flatSize();
}

} //namespace
