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
#include    <errl/errluserdetails.H>

namespace ERRORLOG
{

/*****************************************************************************/
// ErrlUserDetails default constructor
/*****************************************************************************/
ErrlUserDetails::ErrlUserDetails()
: iv_CompId(HBERRL_COMP_ID),
  iv_Version(0),
  iv_SubSection(0),
  iv_pBuffer(NULL),
  iv_BufLen(0)
{
}

/*****************************************************************************/
// ErrlUserDetails Destructor
/*****************************************************************************/
ErrlUserDetails::~ErrlUserDetails()
{
    delete [] iv_pBuffer;
    iv_pBuffer = NULL;
}


/*****************************************************************************/
//  ErrlUserDetails  add/appendToLog
/*****************************************************************************/
void ErrlUserDetails::addToLog(errlHndl_t i_errl)
{
    if((i_errl) && (iv_BufLen))
    {
        i_errl->addFFDC(iv_CompId, iv_pBuffer, iv_BufLen, iv_Version,
                        iv_SubSection );
    }
}

/*****************************************************************************/
// ErrlUserDetails reallocUsrBuf
/*****************************************************************************/
uint8_t * ErrlUserDetails::reallocUsrBuf(const uint32_t i_size)
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
