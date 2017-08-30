/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/runtime/rt_errlmanager.C $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2017                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
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
#include <pnor/pnorif.H>
#include <hwas/common/deconfigGard.H>

namespace ERRORLOG
{

// Allow Hidden error logs to be shown by default
uint8_t ErrlManager::iv_hiddenErrLogsEnable =
            TARGETING::HIDDEN_ERRLOGS_ENABLE_ALLOW_ALL_LOGS;

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
ErrlManager::ErrlManager() :
        iv_currLogId(0),
        iv_pStorage(NULL),
        iv_hwasProcessCalloutFn(NULL),
        iv_pnorAddr(NULL),
        iv_maxErrlInPnor(0),
        iv_pnorOpenSlot(0),
        iv_isSpBaseServices(false),
#ifdef CONFIG_BMC_IPMI
        iv_isIpmiEnabled(true)
#else
        iv_isIpmiEnabled(false)
#endif
{
    TRACFCOMP( g_trac_errl, ENTER_MRK "ErrlManager::ErrlManager constructor." );

    iv_hwasProcessCalloutFn = rt_processCallout;

    // determine starting PLID value
    TARGETING::Target * sys = NULL;
    if( TARGETING::targetService().isInitialized() )
    {
        TARGETING::targetService().getTopLevelTarget( sys );
    }
    else
    {
        TRACFCOMP( g_trac_errl, "Error log being created before TARGETING is ready..." );
    }
    if(sys)
    {
        iv_currLogId = sys->getAttr<TARGETING::ATTR_HOSTSVC_PLID>();

        // set whether we want to skip certain error logs or not.
        iv_hiddenErrLogsEnable =
            sys->getAttr<TARGETING::ATTR_HIDDEN_ERRLOGS_ENABLE>();

        TRACFCOMP( g_trac_errl,"iv_hiddenErrorLogsEnable = 0x%x",
                iv_hiddenErrLogsEnable );

    }
    else
    {
        iv_currLogId = 0x89bad000;
        TRACFCOMP( g_trac_errl, ERR_MRK"HOSTSVC_PLID not available" );
    }

    // check if there's an FSP. if not, then we write to PNOR
    TARGETING::SpFunctions spfn;
    if (!(sys &&
          sys->tryGetAttr<TARGETING::ATTR_SP_FUNCTIONS>(spfn) &&
          spfn.baseServices))
    {
        iv_isSpBaseServices = false;
        TRACFCOMP( g_trac_errl, INFO_MRK"no baseServices, setting up to save to pnor" );
        setupPnorInfo();
    }
    else
    {
        iv_isSpBaseServices = true;
    }


    TRACFCOMP( g_trac_errl, EXIT_MRK "ErrlManager::ErrlManager constructor." );
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ErrlManager::~ErrlManager()
{
    TRACFCOMP( g_trac_errl, INFO_MRK"ErrlManager::ErrlManager destructor" );
    if (!iv_isSpBaseServices)
    {
        // if we saved to PNOR, we need to flush
        TRACFCOMP( g_trac_errl, INFO_MRK"no baseServices, flushing pnor" );
        PNOR::flush(PNOR::HB_ERRLOGS);
    }
}

///////////////////////////////////////////////////////////////////////////////
// ErrlManager::sendMboxMsg()
///////////////////////////////////////////////////////////////////////////////
void ErrlManager::sendMboxMsg ( errlHndl_t& io_err )
{
    do
    {
        if (!iv_isSpBaseServices)
        {
            // save to PNOR
            TRACFCOMP( g_trac_errl, INFO_MRK"no baseServices, saving to pnor" );
            bool l_savedToPnor = saveErrLogToPnor(io_err);
            if (!l_savedToPnor)
            {
                TRACFCOMP( g_trac_errl, ENTER_MRK"saveErrLogToPnor didn't save 0x%X",
                    io_err->eid());
            }
        }


#ifdef CONFIG_BMC_IPMI
        TRACFCOMP(g_trac_errl,INFO_MRK"Send msg to BMC for errlogId [0x%08x]",
                  io_err->plid() );

        // convert to SEL/eSEL and send to BMC over IPMI
        sendErrLogToBmc(io_err);
#else
        TRACDCOMP(g_trac_errl,
                  INFO_MRK"Send msg to FSP for errlogId [0x%08x]",
                  io_err->plid() );

        if(g_hostInterfaces)
        {
            uint32_t l_msgSize = io_err->flattenedSize();
            if (g_hostInterfaces->sendErrorLog)
            {
                uint8_t * temp_buff = new uint8_t [l_msgSize ];
                io_err->flatten ( temp_buff, l_msgSize );

                size_t rc = g_hostInterfaces->sendErrorLog(io_err->plid(),
                                                           l_msgSize,
                                                           temp_buff);

                if(rc)
                {
                    TRACFCOMP(g_trac_errl, ERR_MRK
                              "Failed sending error log to FSP via "
                              "sendErrorLog. rc: %d. plid: 0x%08x",
                              rc,
                              io_err->plid() );
                }

               delete [] temp_buff;
            }
            else if (g_hostInterfaces->firmware_request)
            {
                // Get an accurate size of memory actually
                // needed to transport the data
                size_t l_req_fw_msg_size =
                              hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                              sizeof(hostInterfaces::hbrt_fw_msg::error_log) +
                              l_msgSize;

                // Create the firmware_request structure
                // to carry the error log data
                hostInterfaces::hbrt_fw_msg *l_req_fw_msg =
                      (hostInterfaces::hbrt_fw_msg *)malloc(l_req_fw_msg_size);

                memset(l_req_fw_msg, 0, l_req_fw_msg_size);

                // Populate the firmware_request structure with given data
                l_req_fw_msg->io_type =
                                hostInterfaces::HBRT_FW_MSG_TYPE_ERROR_LOG;
                l_req_fw_msg->error_log.i_plid = io_err->plid();
                l_req_fw_msg->error_log.i_errlSize = l_msgSize;
                io_err->flatten (&(l_req_fw_msg->error_log.i_data), l_msgSize);

                hostInterfaces::hbrt_fw_msg l_resp_fw_msg;
                uint64_t l_resp_fw_msg_size = sizeof(l_resp_fw_msg);
                size_t rc = g_hostInterfaces->
                          firmware_request(l_req_fw_msg_size, l_req_fw_msg,
                                          &l_resp_fw_msg_size, &l_resp_fw_msg);

                if(rc)
                {
                    TRACFCOMP(g_trac_errl, ERR_MRK
                              "Failed sending error log to FSP "
                              "via firmware_request. rc: %d. plid: 0x%08x",
                              rc,
                              io_err->plid() );
                }

                free(l_req_fw_msg);
            }
            else
            {
                TRACFCOMP(g_trac_errl, ERR_MRK
                          "Host interfaces sendErrorLog and firmware_request "
                          "not initialized, error log not sent. plid: 0x%08x",
                          io_err->plid()
                          );
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
#endif
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
///////////////////////////////////////////////////////////////////////////////
void ErrlManager::setHwasProcessCalloutFn(HWAS::processCalloutFn i_fn)
{
    ERRORLOG::theErrlManager::instance().iv_hwasProcessCalloutFn = i_fn;
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
            ((pCalloutUD->deconfigState == HWAS::DELAYED_DECONFIG) ||
             (pCalloutUD->deconfigState == HWAS::DECONFIG)))
        {
            pCalloutUD->deconfigState = HWAS::NO_DECONFIG;

            TRACFCOMP( g_trac_errl, ERR_MRK
                       "Runtime errorlog callout with DELAYED_DECONFIG or "
                       "DECONFIG not allowed! Changed to NO_DECONFIG. "
                       " plid: 0x%X. Deconfig State: 0x%x", io_errl->plid(),
                       pCalloutUD->deconfigState);
        }

    }

    if ((pCalloutUD->type == HWAS::HW_CALLOUT) &&
        (pCalloutUD->gardErrorType != HWAS::GARD_NULL))
    {
            TARGETING::Target *pTarget = NULL;
            uint8_t * l_uData = (uint8_t *)(pCalloutUD + 1);
            bool l_err = HWAS::retrieveTarget(l_uData, pTarget, io_errl);

            if (!l_err)
            {
                errlHndl_t errl = HWAS::theDeconfigGard().platCreateGardRecord(pTarget,
                        io_errl->eid(),
                        pCalloutUD->gardErrorType);
                if (errl)
                {
                    TRACFCOMP( g_trac_errl, ERR_MRK
                        "rt_processCallout: error from platCreateGardRecord");
                    errlCommit(errl, HWAS_COMP_ID);
                }
            }

    }
    return true;
}

} // End namespace
