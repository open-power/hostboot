/**
 *  @file errlsctn.C
 *
 *  @brief Implementation of ErrlSctn class
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <trace/interface.H>
#include "errlsctn.H"
#include <assert.h>

namespace ERRORLOG
{

extern trace_desc_t* g_trac_errl;


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ErrlSctn::ErrlSctn(const compId_t i_compId,
                   const uint8_t i_sctnVer,
                   const uint8_t i_subSect)
:iv_ErrlSctnHdr(i_compId, i_sctnVer, i_subSect),iv_pData(NULL),iv_cbData(0)
{
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ErrlSctn::~ErrlSctn()
{
    delete iv_pData;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
uint64_t ErrlSctn::addData(const void *i_data, const uint64_t i_size)
{
    uint64_t l_rc = 0;

    // Expected new size of user data.
    uint64_t l_newsize = iv_cbData + i_size;

    // Resize memory block
    iv_pData = static_cast<uint8_t*>(realloc(iv_pData, l_newsize));

    // Make sure reallocate call succeeds
    if (iv_pData != NULL)
    {
        // Copy new data to new area, past existing data (if any)
        memcpy( iv_pData+iv_cbData, i_data, i_size );

        // Save new size of the user-provided data.
        l_rc = iv_cbData = l_newsize;
    }
    else
    {
        TRACFCOMP( g_trac_errl,
                   "ErrlFFDC::addData() - Reallocate memory failed!");
    }
    return l_rc;
}


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
uint64_t ErrlSctn::flattenedSize()
{
    return sizeof(section_header_t) + iv_cbData;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
uint64_t ErrlSctn::flatten( void* io_pBuffer, uint64_t i_bufsize )
{
    uint64_t l_flatCount = 0;

    do
    {
        l_flatCount = flattenedSize();
        if( i_bufsize < l_flatCount )
        {
            // error path, return 0
            TRACFCOMP( g_trac_errl, "Invalid buffer size" );
            l_flatCount = 0;
            break;
        }

        // CPPASSERT() makes an assertion to the compiler, and if the
        // expression is false, the compile will end in error.  If these
        // compiler asserts should fail, then the packed structures
        // defined in errl/errltypes.H will need to be adjusted.
        CPPASSERT( 2 == sizeof(iv_ErrlSctnHdr.iv_compId));
        CPPASSERT( 1 == sizeof(iv_ErrlSctnHdr.iv_sctnVer));
        CPPASSERT( 1 == sizeof(iv_ErrlSctnHdr.iv_subSect));
        CPPASSERT( 0 == sizeof( section_header_t ) %  sizeof( uint32_t ));


        // Marshall the data into a section_header_t
        section_header_t l_Header;
        memset( &l_Header, 0, sizeof( l_Header ));
        l_Header.cbHeader   = sizeof( l_Header );
        l_Header.cbSection  = iv_cbData;
        l_Header.compId     = iv_ErrlSctnHdr.iv_compId;
        l_Header.sctnVer    = iv_ErrlSctnHdr.iv_sctnVer;
        l_Header.subSect    = iv_ErrlSctnHdr.iv_subSect;


        // Write data to caller's memory.
        char * l_pchar = static_cast<char *>(io_pBuffer);
        memcpy( l_pchar, &l_Header, sizeof( l_Header ));
        l_pchar += sizeof( l_Header );

        // Write any user-defined data.
        if( iv_cbData )
        {
            memcpy( l_pchar, iv_pData, iv_cbData );
        }
    }
    while( 0 );

    return l_flatCount;
}



} // end namespace
