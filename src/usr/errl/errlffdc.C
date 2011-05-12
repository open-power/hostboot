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
#include "errlsctn.H"

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
: ErrlSctn(i_compId, i_ffdcVer, i_ffdcSubSect),
  iv_data( NULL ),
  iv_size( 0 )
{
    addData(i_ffdcPtr, i_ffdcLen);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ErrlFFDC::~ErrlFFDC()
{
    // Free FFDC data memory
    delete iv_data;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void ErrlFFDC::addData(const void *i_data,
                       const uint32_t i_size)
{
    // Resize memory block
    iv_data = (uint8_t*)realloc(iv_data, iv_size + i_size);

    // Make sure reallocate call successes
    if (iv_data != NULL)
    {
        // Copy data to new area
        memcpy(iv_data + iv_size, i_data, i_size);

        // Total extra data
        iv_size += i_size;
    }
    else
    {
        TRACFCOMP(g_trac_errl, "ErrlFFDC::addData() - Reallocate memory failed!");
    }
}


} // End namespace
