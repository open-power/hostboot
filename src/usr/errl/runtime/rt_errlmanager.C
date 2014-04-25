/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/runtime/rt_errlmanager.C $                       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errl/errlmanager.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <sys/task.h>
#include <stdlib.h>
#include <string.h>
#include <runtime/interface.h>
#include <targeting/common/targetservice.H>

namespace ERRORLOG
{

extern trace_desc_t* g_trac_errl;

//////////////////////////////////////////////////////////////////////////////
// Local functions
//////////////////////////////////////////////////////////////////////////////

/**
 * Override the HWAS processCallout function at runtime
 *  @param[in]  io_errl Error log handle reference
 *  @param[in]  i_pData  Pointer to the callout bundle
 *  @param[in]  i_Size  size of the data in the callout bundle
 *  @param[in]  i_DeferredOnly  bool - true if ONLY check for defered deconfig
 */
bool rt_processCallout(errlHndl_t &io_errl,
                       uint8_t * i_pData,
                       uint64_t i_Size,
                       bool i_DeferredOnly);

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ErrlManager::ErrlManager()
    :
        iv_currLogId(0),
        iv_pStorage(NULL),
        iv_hwasProcessCalloutFn(NULL),
        iv_msgQ(NULL)
{
    TRACFCOMP( g_trac_errl, ENTER_MRK "ErrlManager::ErrlManager constructor" );


    iv_hwasProcessCalloutFn = rt_processCallout;

    TARGETING::Target * sys = NULL;
    TARGETING::targetService().getTopLevelTarget( sys );

    if(sys)
    {
        iv_currLogId = sys->getAttr<TARGETING::ATTR_HOSTSVC_PLID>();
    }
    else
    {
        iv_currLogId = 0x9fbad000;
        TRACFCOMP( g_trac_errl, ERR_MRK"HOSTSVC_PLID not available" );
    }

    TRACFCOMP( g_trac_errl, EXIT_MRK "ErrlManager::ErrlManager constructor." );
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ErrlManager::~ErrlManager()
{
    TRACFCOMP( g_trac_errl, INFO_MRK"ErrlManager::ErrlManager destructor" );
}

///////////////////////////////////////////////////////////////////////////////
// ErrlManager::msgQueueInit()
///////////////////////////////////////////////////////////////////////////////
void ErrlManager::msgQueueInit ( void )
{
}

///////////////////////////////////////////////////////////////////////////////
// ErrlManager::startup()
///////////////////////////////////////////////////////////////////////////////
void * ErrlManager::startup ( void* i_self )
{
    return NULL;
}


///////////////////////////////////////////////////////////////////////////////
// ErrlManager::errlogMsgHndlr()
///////////////////////////////////////////////////////////////////////////////
void ErrlManager::errlogMsgHndlr ( void )
{
    // Not used in HB_RUNTIME
}


///////////////////////////////////////////////////////////////////////////////
// ErrlManager::sendMboxMsg()
///////////////////////////////////////////////////////////////////////////////
void ErrlManager::sendMboxMsg ( errlHndl_t& io_err )
{
    TRACFCOMP( g_trac_errl, ENTER_MRK"ErrlManager::sendToHypervisor" );
    do
    {
        uint32_t l_msgSize = io_err->flattenedSize();

        uint8_t * temp_buff = new uint8_t [l_msgSize ];
        io_err->flatten ( temp_buff, l_msgSize );

        TRACDCOMP(g_trac_errl,
                  INFO_MRK"Send msg to FSP for errlogId [0x%08x]",
                  io_err->plid() );

        if(g_hostInterfaces && g_hostInterfaces->sendErrorLog)
        {
            int rc = g_hostInterfaces->sendErrorLog(io_err->plid(),
                                                    l_msgSize,
                                                    temp_buff);

            if(rc)
            {
                TRACFCOMP(g_trac_errl, ERR_MRK
                          "Failed sending error log to FSP. rc: %d. "
                          "plid: 0x%08x",
                          rc,
                          io_err->plid() );
            }
        }
        else
        {
            TRACFCOMP(g_trac_errl, ERR_MRK
                      "Host interfaces not initialized, error log not sent. "
                      "plid: 0x%08x",
                      io_err->plid()
                      );
        }

        delete [] temp_buff;
        delete io_err;
        io_err = NULL;

    } while (0);

    TRACFCOMP( g_trac_errl, EXIT_MRK"sendToHypervisor()" );
    return;
}

///////////////////////////////////////////////////////////////////////////////
//  Handling commit error log.
///////////////////////////////////////////////////////////////////////////////
void ErrlManager::commitErrLog(errlHndl_t& io_err, compId_t i_committerComp )
{

    TRACDCOMP( g_trac_errl, ENTER_MRK"ErrlManager::commitErrLog" );
    do
    {
        if (io_err == NULL)
        {
            // put out warning trace
            TRACFCOMP(g_trac_errl, ERR_MRK "commitErrLog() - NULL pointer");
            break;
        }

        TRACFCOMP(g_trac_errl, "commitErrLog() called by %.4X for plid=0x%X,"
                               "Reasoncode=%.4X", i_committerComp,
                               io_err->plid(), io_err->reasonCode() );

        // Deferred callouts not allowed at runtime - this call will check,
        // flag and change any that are found.
        io_err->deferredDeconfigure();

        TRACFCOMP( g_trac_errl, INFO_MRK
                   "Send an error log to hypervisor to commit. plid=0x%X",
                   io_err->plid() );

        io_err->commit(i_committerComp);
        sendMboxMsg(io_err);
        io_err = NULL;

    } while( 0 );

   TRACDCOMP( g_trac_errl, EXIT_MRK"ErrlManager::commitErrLog" );

   return;
}

///////////////////////////////////////////////////////////////////////////////
// ErrlManager::saveErrLogEntry()
///////////////////////////////////////////////////////////////////////////////
void ErrlManager::saveErrLogEntry( errlHndl_t& io_err )
{
    return;
}



///////////////////////////////////////////////////////////////////////////////
// Atomically increment log id and return it.
uint32_t ErrlManager::getUniqueErrId()
{
    return (__sync_add_and_fetch(&iv_currLogId, 1));
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void ErrlManager::setHwasProcessCalloutFn(HWAS::processCalloutFn i_fn)
{
    ERRORLOG::theErrlManager::instance().iv_hwasProcessCalloutFn = i_fn;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// Global function (not a method on an object) to commit the error log.
void errlCommit(errlHndl_t& io_err, compId_t i_committerComp )
{
    ERRORLOG::theErrlManager::instance().commitErrLog(io_err, i_committerComp );
    return;
}


///////////////////////////////////////////////////////////////////////////////
// ErrlManager::sendErrlogToMessageQueue()
///////////////////////////////////////////////////////////////////////////////
void ErrlManager::sendErrlogToMessageQueue ( errlHndl_t& io_err,
                                             compId_t i_committerComp )
{
    return;
}

///////////////////////////////////////////////////////////////////////////////
// ErrlManager::errlogShutdown()
///////////////////////////////////////////////////////////////////////////////
void ErrlManager::errlogShutdown(void)
{
    return;
}

//  Runtime processCallout
bool rt_processCallout(errlHndl_t &io_errl,
                       uint8_t * i_pData,
                       uint64_t i_Size,
                       bool i_DeferredOnly)
{
    HWAS::callout_ud_t *pCalloutUD = (HWAS::callout_ud_t *)i_pData;
    if(i_DeferredOnly)
    {
        if ((pCalloutUD->type == HWAS::HW_CALLOUT) &&
            (pCalloutUD->deconfigState == HWAS::DELAYED_DECONFIG))
        {
            pCalloutUD->deconfigState = HWAS::NO_DECONFIG;

            TRACFCOMP( g_trac_errl, ERR_MRK
                       "Runtime errorlog callout with DELAYED_DECONFIG not "
                       "allowed! Changed to NO_DECONFIG. plid: 0x%X",
                       io_errl->plid() );
        }

    }
    return true;
}

} // End namespace
