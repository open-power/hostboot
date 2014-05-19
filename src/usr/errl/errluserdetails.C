/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errluserdetails.C $                              */
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
: iv_CompId(ERRL_COMP_ID),
  iv_Version(0),
  iv_SubSection(0),
  iv_merge(false),
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
        i_errl->addFFDC(iv_CompId, iv_pBuffer, iv_BufLen, 
                iv_Version, iv_SubSection,
                iv_merge );
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
