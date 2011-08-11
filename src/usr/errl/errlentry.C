/**
 *  @file errlentry.C
 *
 *  @brief Implementation of ErrlEntry class
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <hbotcompid.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include "errlsctn.H"
#include "errlffdc.H"
#include <trace/interface.H>
#include <arch/ppc.H>

namespace ERRORLOG
{

// Trace definition
trace_desc_t* g_trac_errl = NULL;
TRAC_INIT(&g_trac_errl, "ERRL", 4096);

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ErrlEntry::ErrlEntry(const errlSeverity_t i_sev,
                     const uint8_t i_modId,
                     const uint16_t i_reasonCode,
                     const uint64_t i_user1,
                     const uint64_t i_user2) :
    iv_reasonCode(i_reasonCode),
    iv_sev(i_sev),
    iv_eventType(ERRL_ETYPE_NOT_APPLICABLE),
    iv_subSys(EPUB_RESERVED_0),
    iv_srcType(SRC_ERR_INFO),
    iv_termState(TERM_STATE_UNKNOWN),
    iv_modId(i_modId),
    iv_user1(i_user1),
    iv_user2(i_user2),
    iv_logId(0)
{

    // record time of creation
    iv_CreationTime = getTB();
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ErrlEntry::~ErrlEntry()
{
    // Free memory of all sections
    for (std::vector<ErrlSctn*>::iterator l_itr = iv_SectionVector.begin();
         l_itr != iv_SectionVector.end(); ++l_itr)
    {
        delete (*l_itr);
    }
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ErrlFFDC* ErrlEntry::addFFDC(const compId_t i_compId,
             const void * i_dataPtr,
             const uint32_t i_ffdcLen,
             const uint8_t i_ffdcVer,
             const uint8_t i_ffdcSubSect)
{
    ErrlFFDC* l_ffdcSection = NULL;

    if ( (i_dataPtr == NULL) || (i_ffdcLen == 0) )
    {
        TRACFCOMP( ERRORLOG::g_trac_errl,
                   "Invalid FFDC data pointer or size, no add");
    }
    else
    {
        // Create
        l_ffdcSection = new ErrlFFDC(i_compId, i_dataPtr, i_ffdcLen,
                                     i_ffdcVer, i_ffdcSubSect);

        // Add to the end of the vector of sections for this error log.
        iv_SectionVector.push_back( l_ffdcSection );
    }

    return l_ffdcSection;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void ErrlEntry::appendToFFDC(ErrlFFDC* i_ffdcPtr,
                  const void *i_dataPtr,
                  const uint32_t i_dataLen)
{
    // class ErrlFFDC inherits addData() from its parent class ErrlSctn
    i_ffdcPtr->addData( i_dataPtr, i_dataLen );
    return;
}




///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

uint64_t ErrlEntry::flattenedSize()
{
    uint64_t l_bytecount = sizeof( errl_header_t );

    // add the bytes in the sections, if any
    std::vector<ErrlSctn*>::iterator it;
    for( it = iv_SectionVector.begin(); it != iv_SectionVector.end(); it++ )
    {
        l_bytecount += (*it)->flattenedSize();
    }

    return l_bytecount;
}




///////////////////////////////////////////////////////////////////////////////
// Flatten object instance data into a packed structure.
// See errl/erltypes.H and the errl_header_t  struct.

uint64_t ErrlEntry::flatten( void * io_pBuffer,  uint64_t i_bufsize )
{
    uint64_t  l_flatCount = 0;

    do
    {
        l_flatCount = flattenedSize();
        if ( i_bufsize < l_flatCount )
        {
            // error path; return zero
            TRACFCOMP( ERRORLOG::g_trac_errl, "Invalid buffer size");
            l_flatCount = 0;
            break;
        }

        // The CPPASSERT() macro will cause the compile to abend
        // when the expression given evaluates to false.  If ever
        // these cause the compile to fail, then perhaps the size
        // of enum'ed types has grown unexpectedly.  At any rate,
        // errl_header_t defined in errl/errltypes.H will need to
        // be adjusted for the changes in size of these instance
        // variables.    Monte
        CPPASSERT( 1 == sizeof(iv_sev));
        CPPASSERT( 1 == sizeof(iv_eventType));
        CPPASSERT( 1 == sizeof(iv_subSys));
        CPPASSERT( 1 == sizeof(iv_srcType));
        CPPASSERT( 2 == sizeof(iv_reasonCode));
        CPPASSERT( 2 == sizeof(compId_t));
        CPPASSERT( 1 == sizeof(iv_modId));
        CPPASSERT( 0 == (sizeof(errl_header_t) % sizeof(uint32_t)));


        // Marshall the instance var data into a struct.
        errl_header_t l_hdr;
        memset( &l_hdr, 0, sizeof( l_hdr ));
        l_hdr.cbytes       = sizeof( l_hdr );
        l_hdr.csections    = iv_SectionVector.size();
        l_hdr.reasonCode   = iv_reasonCode;
        l_hdr.modId        = iv_modId;
        l_hdr.sev          = iv_sev;
        l_hdr.eventType    = iv_eventType;
        l_hdr.subSys       = iv_subSys;
        l_hdr.srcType      = iv_srcType;
        l_hdr.termState    = iv_termState;
        l_hdr.logId        = iv_logId;
        l_hdr.user1        = iv_user1;
        l_hdr.user2        = iv_user2;
        l_hdr.CreationTime = iv_CreationTime;


        // Write the flat data.
        char * l_pchar = reinterpret_cast<char*>(io_pBuffer);
        memcpy( l_pchar, &l_hdr, sizeof( l_hdr ));
        l_pchar += sizeof( l_hdr );

        // Append all the sections.
        std::vector<ErrlSctn*>::iterator it;
        for(it=iv_SectionVector.begin(); it != iv_SectionVector.end(); it++ )
        {
            uint64_t l_countofbytes = (*it)->flattenedSize();
            (*it)->flatten( l_pchar, l_countofbytes );
            l_pchar += l_countofbytes;
        }
    }
    while( 0 );

    return l_flatCount;
}




} // End namespace

