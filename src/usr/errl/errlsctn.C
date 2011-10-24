//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/errl/errlsctn.C $
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
 *  @file errlsctn.C
 *
 *  @brief Implementation of ErrlSctn class.
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <trace/interface.H>
#include <errl/errlentry.H>


namespace ERRORLOG
{

extern trace_desc_t* g_trac_errl;


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

ErrlSctn::ErrlSctn(  const uint16_t    i_sid,
                     const uint16_t    i_slen,
                     const uint8_t     i_ver,
                     const uint8_t     i_sst,
                     const compId_t    i_compId ) :
    iv_header( i_sid, i_slen, i_ver, i_sst, i_compId )
{

}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ErrlSctn::~ErrlSctn()
{

}


} // end namespace
