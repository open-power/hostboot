//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/errl/errlud.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
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
    if( iv_pData ) free( iv_pData );
}





/*****************************************************************************/
// Add data. This works the first time when there is no data and works for
// subsequent times when you want to append data. Return [new] size of buffer.

uint64_t ErrlUD::addData(const void *i_data, const uint64_t i_size)
{
    uint64_t l_rc = 0;

    // Expected new size of user data.
    uint64_t l_newsize = iv_Size + i_size;

    // Resize memory block
    iv_pData = static_cast<uint8_t*>(realloc(iv_pData, l_newsize));

    // Make sure reallocate call succeeds
    if (iv_pData != NULL)
    {
        // Copy new data to new area, past existing data (if any)
        memcpy( iv_pData + iv_Size, i_data, i_size );

        // Save new size of the user-provided data. This will also
        // be what this method returns.
        iv_Size = l_newsize;
        l_rc = iv_Size;

        // Tell the PEL header what is the new length.
        iv_header.iv_slen = iv_header.flatSize() + iv_Size;
    }
    else
    {
        TRACFCOMP( g_trac_errl,
                   "ErrlUD::addData() - Reallocate memory failed!");
    }
    return l_rc;
}



/*****************************************************************************/
// Data Export size

uint64_t ErrlUD::flatSize()
{
    uint64_t	l_rc = 0;

    l_rc = iv_header.flatSize() + iv_Size;

    return l_rc;
}


/*****************************************************************************/
// Data Export. Return how many bytes were written or zero on error.

uint64_t ErrlUD::flatten( void * o_pBuffer, const uint64_t i_cbBuffer )
{
    uint64_t  l_rc = 0;
    uint64_t  cb = 0;
    uint8_t * pBuffer = static_cast<uint8_t *>(o_pBuffer);

    if ( i_cbBuffer >= this->flatSize() )
    {
        // flatten the section header
        cb = iv_header.flatten( pBuffer, i_cbBuffer );
        pBuffer += cb;

        // followed by the user data
        memcpy( pBuffer, iv_pData, iv_Size );

        // return how many bytes were flattened
        l_rc = iv_Size + cb;
    }
    else
    {
        TRACFCOMP( g_trac_errl, "ErrlUD::flatten: buffer too small");
    }


    return l_rc;
}

} //namespace
