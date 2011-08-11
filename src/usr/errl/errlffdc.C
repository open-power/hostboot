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
