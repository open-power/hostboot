//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/errl/errlffdc.C $
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
 *  @file errlffdc.C
 *
 *  @brief Implementation of ErrlFFDC class
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <trace/interface.H>
#include "errlffdc.H"


namespace ERRORLOG
{

extern trace_desc_t* g_trac_errl;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ErrlFFDC::ErrlFFDC(const compId_t i_compId,
                           const void* i_ffdcPtr,
                           const uint32_t i_ffdcLen,
                           const uint8_t i_ffdcVer,
                           const uint8_t i_ffdcSubSect)
: ErrlSctn(i_compId, i_ffdcVer, i_ffdcSubSect)
{

    // addData is inherited from parent class ErrlSctn
    addData(i_ffdcPtr, i_ffdcLen);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ErrlFFDC::~ErrlFFDC()
{
}



} // End namespace
