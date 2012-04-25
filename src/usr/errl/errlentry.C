//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/errl/errlentry.C $
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
 *  @file errlentry.C
 *
 *  @brief Implementation of ErrlEntry class
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <hbotcompid.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludbacktrace.H>
#include <trace/interface.H>
#include <arch/ppc.H>

namespace ERRORLOG
{

// Trace definition
trace_desc_t* g_trac_errl = NULL;
TRAC_INIT(&g_trac_errl, "ERRL", 1024);

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ErrlEntry::ErrlEntry(const errlSeverity_t i_sev,
                     const uint8_t i_modId,
                     const uint16_t i_reasonCode,
                     const uint64_t i_user1,
                     const uint64_t i_user2) :
    iv_Private( static_cast<compId_t>(i_reasonCode & 0xFF00)),
    iv_User( i_sev ),
    // The SRC_ERR_INFO becomes part of the SRC; example, B1 in SRC B180xxxx
    // iv_Src assigns the epubSubSystem_t; example, 80 in SRC B180xxxx
    iv_Src( SRC_ERR_INFO, i_modId, i_reasonCode, i_user1, i_user2 ),
    iv_termState(TERM_STATE_UNKNOWN)
{
    // Collect the Backtrace and add it to the error log
    iv_pBackTrace = new ErrlUserDetailsBackTrace();
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ErrlEntry::~ErrlEntry()
{
    // Free memory of all sections
    for (std::vector<ErrlUD*>::iterator l_itr = iv_SectionVector.begin();
         l_itr != iv_SectionVector.end(); ++l_itr)
    {
        delete (*l_itr);
    }

    delete iv_pBackTrace;
    iv_pBackTrace = NULL;
}

///////////////////////////////////////////////////////////////////////////////
// add a new UD section to the list of optional sections

ErrlUD * ErrlEntry::addFFDC(const compId_t i_compId,
             const void * i_dataPtr,
             const uint32_t i_ffdcLen,
             const uint8_t i_ffdcVer,
             const uint8_t i_ffdcSubSect,
             bool i_merge)
{
    ErrlUD * l_ffdcSection = NULL;

    if ( (i_dataPtr != NULL) && (i_ffdcLen != 0) )
    {
        TRACDCOMP( g_trac_errl, INFO_MRK"addFFDC(): %x %d %d - %s merge",
                      i_compId, i_ffdcVer,
                      i_ffdcSubSect, i_merge == true ? "DO" : "NO" );

        // if we're to try to merge, AND there's at least 1 section
        if ((i_merge) && (iv_SectionVector.size() > 0))
        {   // look at the last one to see if it's a match or not.
            // this is done to preserve the order of the errlog - we
            // only merge like sections if they are being put in at the
            // 'same time'.
            ErrlUD *pErrlUD = iv_SectionVector.back();

            if ((i_compId       == pErrlUD->iv_header.iv_compId) &&
                (i_ffdcVer      == pErrlUD->iv_header.iv_ver) &&
                (i_ffdcSubSect  == pErrlUD->iv_header.iv_sst))
            {
                TRACDCOMP( g_trac_errl, INFO_MRK"appending to matched %p",
                            pErrlUD);
                appendToFFDC(pErrlUD, i_dataPtr, i_ffdcLen);
                l_ffdcSection = pErrlUD;
            }
        } // i_merge && >0 section

        // i_merge == false, or it was true but we didn't find a match
        if (l_ffdcSection == NULL)
        {
            // Create a user-defined section.
            l_ffdcSection = new ErrlUD(  i_dataPtr,
                                         i_ffdcLen,
                                         i_compId,
                                         i_ffdcVer,
                                         i_ffdcSubSect );

            // Add to the vector of sections for this error log.
            iv_SectionVector.push_back( l_ffdcSection );
        }
    }
    else
    {
        TRACFCOMP( g_trac_errl,
        ERR_MRK"addFFDC(): Invalid FFDC data pointer or size, no add");
    }

    return l_ffdcSection;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void ErrlEntry::appendToFFDC(ErrlUD * i_pErrlUD,
                  const void *i_dataPtr,
                  const uint32_t i_dataLen)
{
    uint64_t l_rc;
    TRACDCOMP( g_trac_errl, ENTER_MRK"appendToFFDC(%p, %p, %d)",
                i_pErrlUD, i_dataPtr, i_dataLen);

    l_rc = i_pErrlUD->addData( i_dataPtr, i_dataLen );
    if( 0 == l_rc )
    {
        TRACFCOMP( g_trac_errl, ERR_MRK"ErrlEntry::appendToFFDC() rets zero" );
    }
    return;
}

///////////////////////////////////////////////////////////////////////////////
// Return a Boolean indication of success.

// Use these to tag the UD section containing the trace.
const int FIPS_ERRL_UDT_TRACE              = 0x0c;
const int FIPS_ERRL_UDV_DEFAULT_VER_1      = 1;

bool ErrlEntry::collectTrace(const char i_name[], const uint64_t i_max)
{
    bool l_rc = false;  // assume a problem.
    char * l_pBuffer = NULL;
    uint64_t l_cbOutput = 0;
    uint64_t l_cbBuffer = 0;

    do
    {
        // By passing nil arguments 2 and 3, obtain the size of the buffer.
        // Besides getting buffer size, it validates i_name.
        uint64_t l_cbFull = TRACE::Trace::getTheInstance().getBuffer( i_name,
                                                                      NULL,
                                                                      0 );
        if( 0 == l_cbFull )
        {
            // Problem, likely unknown trace buffer name.
            TRACFCOMP( g_trac_errl,
                ERR_MRK"ErrlEntry::collectTrace(): getBuffer(%s) rets zero.",i_name);
            break;
        }

        if(( 0 == i_max ) || ( i_max >= l_cbFull ))
        {
            // Full trace buffer desired
            l_cbBuffer = l_cbFull;
        }
        else
        {
            // Partial buffer desired
            l_cbBuffer = i_max;
        }

        // allocate the buffer
        l_pBuffer = new char[ l_cbBuffer ];

        // Get the data into the buffer.
        l_cbOutput =
        TRACE::Trace::getTheInstance().getBuffer( i_name,
                                                  l_pBuffer,
                                                  l_cbBuffer );

        if( 0 == l_cbOutput )
        {
            // Problem.
            TRACFCOMP( g_trac_errl,
                ERR_MRK"ErrlEntry::collectTrace(): getBuffer(%s,%ld) rets zero.",
                i_name,
                l_cbBuffer );
            break;
        }

        // Save the trace buffer as a UD section on this.
        ErrlUD * l_udSection = new ErrlUD( l_pBuffer,
                                           l_cbOutput,
                                           FIPS_ERRL_COMP_ID,
                                           FIPS_ERRL_UDV_DEFAULT_VER_1,
                                           FIPS_ERRL_UDT_TRACE );

        // Add the trace section to the vector of sections
        // for this error log.
        iv_SectionVector.push_back( l_udSection );

        l_rc = true;
    }
    while(0);

    delete[] l_pBuffer;

    return l_rc;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
void ErrlEntry::removeBackTrace()
{
    delete iv_pBackTrace;
    iv_pBackTrace = NULL;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
errlSeverity_t ErrlEntry::sev() const
{
    return iv_User.iv_severity;
}



////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
void ErrlEntry::setSev(const errlSeverity_t i_sev)
{
    iv_User.iv_severity = i_sev;
    return;
}


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
errlEventType_t ErrlEntry::eventType() const
{
    return iv_User.iv_etype;
}



////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
void ErrlEntry::setEventType(const errlEventType_t i_eventType)
{
    iv_User.iv_etype = i_eventType;
    return;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
epubSubSystem_t ErrlEntry::subSys() const
{
    return iv_User.iv_ssid;
}



////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
void ErrlEntry::setSubSys(const epubSubSystem_t i_subSys)
{
    iv_User.iv_ssid = i_subSys;
    return;
}

///////////////////////////////////////////////////////////////////////////////
// for use by ErrlManager
void ErrlEntry::commit( compId_t  i_committerComponent )
{
    // TODO need a better timepiece, or else apply a transform onto timebase
    // for an approximation of real time.
    iv_Private.iv_committed = getTB();

    // User header contains the component ID of the committer.
    iv_User.setComponentId( i_committerComponent );

    // Add the captured backtrace to the error log
    if (iv_pBackTrace)
    {
        iv_pBackTrace->addToLog(this);
        delete iv_pBackTrace;
        iv_pBackTrace = NULL;
    }
}


//////////////////////////////////////////////////////////////////////////////
// for use by ErrlManager

uint64_t ErrlEntry::flattenedSize()
{
    uint64_t l_bytecount = iv_Private.flatSize() +
                           iv_User.flatSize() +
                           iv_Src.flatSize();

    // plus the sizes of the other optional sections

    std::vector<ErrlUD*>::iterator it;
    for( it = iv_SectionVector.begin(); it != iv_SectionVector.end(); it++ )
    {
        l_bytecount += (*it)->flatSize();
    }
    return l_bytecount;
}


/////////////////////////////////////////////////////////////////////////////
// Flatten this object and all its sections into PEL
// for use by ErrlManager. Return how many bytes flattened to the output
// buffer, or else zero on error.

uint64_t ErrlEntry::flatten( void * o_pBuffer,  uint64_t i_bufsize )
{
    uint64_t  l_flatCount = 0;
    uint64_t  l_cb = 0;

    do
    {
        l_flatCount = flattenedSize();
        if ( i_bufsize < l_flatCount )
        {
            // buffer is not big enough; return zero
            TRACFCOMP( ERRORLOG::g_trac_errl, ERR_MRK"Invalid buffer size");
            l_flatCount = 0;
            break;
        }

        // The CPPASSERT() macro will cause the compile to abend
        // when the expression given evaluates to false.  If ever
        // these cause the compile to fail, then perhaps the size
        // of enum'ed types has grown unexpectedly.
        CPPASSERT( 1 == sizeof(iv_Src.iv_srcType));
        CPPASSERT( 2 == sizeof(iv_Src.iv_reasonCode));
        CPPASSERT( 2 == sizeof(compId_t));
        CPPASSERT( 1 == sizeof(iv_Src.iv_modId));

        // Inform the private header how many sections there are,
        // counting the PH, UH, PS, and the optionals.
        iv_Private.iv_sctns = 3 + iv_SectionVector.size();

        // Flatten the PH private header section
        char * pBuffer = static_cast<char *>(o_pBuffer);
        l_cb = iv_Private.flatten( pBuffer, i_bufsize );
        if( 0 == l_cb )
        {
            // Rare.
            TRACFCOMP( g_trac_errl, ERR_MRK"ph.flatten error");
            l_flatCount = 0;
            break;
        }

        pBuffer += l_cb;
        i_bufsize -= l_cb;

        // flatten the UH user header section
        l_cb = iv_User.flatten( pBuffer,  i_bufsize );
        if( 0 == l_cb )
        {
            // Rare.
            TRACFCOMP( g_trac_errl, ERR_MRK"uh.flatten error");
            l_flatCount = 0;
            break;
        }
        pBuffer += l_cb;
        i_bufsize -= l_cb;

        // flatten the PS primary SRC section
        l_cb = iv_Src.flatten( pBuffer, i_bufsize );
        if( 0 == l_cb )
        {
            // Rare.
            TRACFCOMP( g_trac_errl, ERR_MRK"ps.flatten error");
            l_flatCount = 0;
            break;
        }
        pBuffer += l_cb;
        i_bufsize -= l_cb;


        // flatten the optional user-defined sections
        std::vector<ErrlUD*>::iterator it;
        for(it = iv_SectionVector.begin(); it != iv_SectionVector.end(); it++)
        {
            l_cb = (*it)->flatten( pBuffer, i_bufsize );
            if( 0 == l_cb )
            {
                // Rare.
                TRACFCOMP( g_trac_errl, ERR_MRK"ud.flatten error");
                l_flatCount = 0;
                break;
            }
            pBuffer += l_cb;
            i_bufsize -= l_cb;
        }
    }
    while( 0 );

    return l_flatCount;
}



} // End namespace

