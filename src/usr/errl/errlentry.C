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
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <trace/interface.H>
#include <hbotcompid.H>
#include "errlsctn.H"
#include "errlffdc.H"

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
                     const uint64_t i_user2)
:iv_reasonCode(i_reasonCode),
iv_sev(i_sev),
iv_eventType(ERRL_ETYPE_NOT_APPLICABLE),
iv_subSys(EPUB_RESERVED_0),
iv_srcType(SRC_ERR_INFO),
iv_termState(TERM_STATE_UNKNOWN),
iv_modId(i_modId),
iv_user1(i_user1),
iv_user2(i_user2),
iv_sections(NULL)
{
    iv_logId = theErrlManager::instance().getUniqueErrId();
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ErrlEntry::~ErrlEntry()
{
    // Free memory of all sections
    for (std::vector<ErrlSctn*>::iterator l_itr = iv_sections.begin();
         l_itr != iv_sections.end(); ++l_itr)
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
        TRACFCOMP(ERRORLOG::g_trac_errl, "Invalid FFDC data pointer or size, no add");
    }
    else
    {
        // Create
        l_ffdcSection = new ErrlFFDC(i_compId, i_dataPtr, i_ffdcLen,
                                     i_ffdcVer, i_ffdcSubSect);
        // Add to error log
        addSection(l_ffdcSection);
    }

    return l_ffdcSection;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void ErrlEntry::appendToFFDC(ErrlFFDC* i_ffdcPtr,
                  const void *i_dataPtr,
                  const uint32_t i_dataLen)
{
    //@todo Need to support append data to an existing FFDC data block
    return;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void ErrlEntry::addSection(ErrlSctn* i_sctn)
{
    // Add pointer
    iv_sections.push_back(i_sctn);
    return;
}



} // End namespace

