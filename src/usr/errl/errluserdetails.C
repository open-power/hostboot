//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/errl/errluserdetails.C $
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
 *  @file errluserdetails.C
 *
 *  @brief Implementation for ErrlUsrDetails
 *
 *  2011-09-28  mww Forked from /esw/fips740/Builds/b0824a_1135.740/src/util/fsp
 *
*/


/******************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>                          // memcpy

#include    <hbotcompid.H>
#include    <errl/errlentry.H>
#include    <errl/errlmanager.H>
#include    <errl/errlreasoncodes.H>

#include    <errl/errluserdetails.H>

#include    "errlsctn.H"
#include    <errl/errlud.H>                        // ErrlFFDC


namespace ERRORLOG
{

/*****************************************************************************/
// ErrlUserDetails default constructor
/*****************************************************************************/
ErrlUserDetails::ErrlUserDetails()
: iv_CompId(HBERRL_COMP_ID),
  iv_Version(0),
  iv_SubSection(0),
  iv_pErrlFFDC(NULL),
  iv_pBuffer(NULL),
  iv_BufLen(0)
{
}

/*****************************************************************************/
// ErrlUserDetails Destructor
/*****************************************************************************/
ErrlUserDetails::~ErrlUserDetails()
{
    if (iv_pBuffer)
    {
        delete [] iv_pBuffer;
        iv_pBuffer = NULL;
    }

}


/*****************************************************************************/
//  ErrlUserDetails  add/appendToLog
/*****************************************************************************/
void ErrlUserDetails::addToLog(
        errlHndl_t      i_errl,
        const void      *i_paddBuf,
        const uint32_t  i_addBufLen )
{

    assert( i_errl != NULL );

    if ( iv_pErrlFFDC == NULL )
    {
        // first time through, do an addFFDC() and save the returned handle
        iv_pErrlFFDC =   i_errl->addFFDC(
                                    iv_CompId,
                                    iv_pBuffer,
                                    iv_BufLen,
                                    iv_Version,
                                    iv_SubSection );

        // assert if fails to addFFDC
        assert( iv_pErrlFFDC != NULL );
    }

    // if there is a buffer/len , append it to the existing FFDC.
    if ( ( i_paddBuf != NULL ) && ( i_addBufLen > 0 ) )
    {
        i_errl->appendToFFDC(
                        iv_pErrlFFDC,
                        i_paddBuf,
                        i_addBufLen );
    }
}


/*****************************************************************************/
// ErrlUserDetails allocUsrBuf
/*****************************************************************************/
uint8_t * ErrlUserDetails::allocUsrBuf(const uint32_t i_size)
{
    uint8_t * pNewBuffer = new uint8_t[i_size];
    if (iv_pBuffer)
    {
        if (iv_BufLen <= i_size)
        {
            memcpy(pNewBuffer, iv_pBuffer, iv_BufLen);
        }
        else
        {
            memcpy(pNewBuffer, iv_pBuffer, i_size);
        }
        delete [] iv_pBuffer;
    }

    iv_pBuffer = pNewBuffer;
    iv_BufLen = i_size;

    return (iv_pBuffer);
}

/*****************************************************************************/
// ErrlUserDetails getUsrBufSize
/*****************************************************************************/
uint32_t ErrlUserDetails::getUsrBufSize() const
{
    return iv_BufLen;
}

} // end namespace
