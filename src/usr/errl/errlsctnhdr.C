//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/errl/errlsctnhdr.C $
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
 *  @file errlsctnhdr.C
 *
 *  @brief  Abstract header of all error log's sections
 *
 *  This header file contains the definition of common section header in
 *  each error log's section
 *
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include "errlsctnhdr.H"

namespace ERRORLOG
{

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ErrlSctnHdr::ErrlSctnHdr(const compId_t i_compId,
                                 const uint8_t i_sctnVer,
                                 const uint8_t i_subSect)
:iv_compId(i_compId),
iv_sctnVer(i_sctnVer),
iv_subSect(i_subSect)
{

}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ErrlSctnHdr::~ErrlSctnHdr()
{

}

} // End namespace
