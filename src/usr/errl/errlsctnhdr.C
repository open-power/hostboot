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
