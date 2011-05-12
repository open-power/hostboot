/**
 *  @file errlmanager.C
 *
 *  @brief Implementation of ErrlManager class
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errl/errlmanager.H>
#include <trace/interface.H>
#include <errl/errlentry.H>

namespace ERRORLOG
{

extern trace_desc_t* g_trac_errl;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ErrlManager::ErrlManager()
:iv_currLogId(0)
{
    //@todo
    // This is done in order to avoid reading logID from PNOR for every
    // error log created.
    // When ErrlManager singleton instantiated:
    // 1. Parse the last committed error from PNOR
    // 2. Get the logID from that error
    // 3. Load iv_currLogId with that value.
    // 4. When next error is committed, assign the next ID value to it
    //    before writing to PNOR.


}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ErrlManager::~ErrlManager()
{
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void ErrlManager::commitErrLog(errlHndl_t& io_err)
{
    // If NULL, put out warning trace
    if (io_err == NULL)
    {
        //@thi TRACFCOMP(g_trac_errl, "commitErrLog() - NULL pointer");
    }
    else
    {
        // Assign a unique error ID to the committed log
        uint32_t l_errId = getUniqueErrId();
        io_err->setLogId(l_errId);

        // @todo:
        //  - Flatten error into PNOR

        delete io_err;
        io_err = NULL;
    }
    return;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
uint32_t ErrlManager::getUniqueErrId()
{
    return (__sync_add_and_fetch(&iv_currLogId, 1));
}

} // End namespace
