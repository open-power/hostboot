/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/runtime/rt_errlmanager.C $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2021                        */
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
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>
#include <runtime/interface.h>   // g_hostInterfaces
#include <util/runtime/rt_fwreq_helper.H>  // firmware_request_helper
#include <targeting/common/targetservice.H>
#include <hwas/common/deconfigGard.H>
#include <initservice/initserviceif.H> // spBaseServiceEnabled()

namespace ERRORLOG
{

// Declared in errlentry.C
extern std::map<uint8_t, const char *> errl_sev_str_map;

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
        iv_baseNodeId(ERRLOG_PLID_BASE_MASK),
        iv_pnorReadyForErrorLogs(true),
        iv_pStorage(NULL),
        iv_hwasProcessCalloutFn(NULL),
        iv_pnorAddr(NULL),
        iv_maxErrlInPnor(0),
        iv_pnorOpenSlot(0),
#ifdef CONFIG_FSP_BUILD
        iv_isFSP(true),
#else
        iv_isFSP(false),
#endif
#ifdef CONFIG_PLDM
        iv_isBmcInterfaceEnabled(true)
#else
        iv_isBmcInterfaceEnabled(false)
#endif
{
    TRACFCOMP( g_trac_errl, ENTER_MRK "ErrlManager::ErrlManager constructor." );
    //Note - There is no PNOR access inside HBRT

    iv_hwasProcessCalloutFn = rt_processCallout;

    // determine starting PLID value
    TARGETING::Target * sys = NULL;
    if( TARGETING::targetService().isInitialized() )
    {
        TARGETING::targetService().getTopLevelTarget( sys );
    }
    else
    {
        TRACFCOMP( g_trac_errl, "Error log being created before "
                                "TARGETING is ready..." );

    }
    if(sys)
    {
        iv_currLogId = sys->getAttr<TARGETING::ATTR_HOSTSVC_PLID>();
        TRACFCOMP( g_trac_errl,"Initial Error Log ID = %.8X", iv_currLogId );

        // set whether we want to skip certain error logs or not.
        iv_hiddenErrLogsEnable =
            sys->getAttr<TARGETING::ATTR_HIDDEN_ERRLOGS_ENABLE>();

        TRACFCOMP( g_trac_errl,"iv_hiddenErrorLogsEnable = 0x%x",
                iv_hiddenErrLogsEnable );

        // If this isn't an FSP system, and we do not have PLD wait
        // specifically disabled via the attribute ATTR_DISABLE_PLD_WAIT,
        // then PLD waits are enabled.
        iv_pldWaitEnable = !iv_isFSP && !sys->getAttr<TARGETING::ATTR_DISABLE_PLD_WAIT>();

    }
    else
    {
        iv_currLogId = 0x89bad000;
        TRACFCOMP( g_trac_errl, ERR_MRK"HOSTSVC_PLID not available" );

        // If this isn't an FSP system, and targeting isn't ready when
        // the first error log comes in, ignore the DISABLE_PLD_WAIT
        // override and just enable the wait.
        iv_pldWaitEnable = !iv_isFSP;
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
// ErrlManager::sendMboxMsg()
///////////////////////////////////////////////////////////////////////////////
void ErrlManager::sendMboxMsg ( errlHndl_t& io_err )
{
    // Put the handle to the firmware_request request struct
    // out here so it is easier to free later
    hostInterfaces::hbrt_fw_msg *l_req_fw_msg = nullptr;

    do
    {
#ifdef CONFIG_PLDM
        if (iv_isBmcInterfaceEnabled)
        {
            TRACFCOMP(g_trac_errl,INFO_MRK"Send msg to BMC for errlogId [0x%08x]",
                      io_err->eid());

            // send to BMC
            bool l_passed = sendErrLogToBmcPLDM(io_err);
            if (!l_passed)
            {
                TRACFCOMP( g_trac_errl,
                    ERR_MRK"BMC interface failed sending EID[0x%08x] SEV[0%02x]",
                    io_err->eid(), io_err->sev() );
                io_err->traceLogEntry();
            }
        }
        else
        {
            TRACFCOMP( g_trac_errl,
                ERR_MRK"BMC interface down, cannot send EID[0x%08x] SEV[0x%02x]",
                io_err->eid(), io_err->sev() );
            io_err->traceLogEntry();
        }

#else

        TRACFCOMP(g_trac_errl,
                  INFO_MRK"Send msg to FSP for errlogId [0x%08x]",
                  io_err->plid() );

        if(g_hostInterfaces)
        {
            uint32_t l_msgSize = io_err->flattenedSize();

            // The F2/01/0 MBOX message only supports 4KB
            // PHYP and OPAL use the same command down to the FSP,
            //  regardless of which interface we call
            const uint32_t MAX_FSP_ERROR_LOG_LENGTH = 4096;
            if (l_msgSize > MAX_FSP_ERROR_LOG_LENGTH)
            {
                l_msgSize = MAX_FSP_ERROR_LOG_LENGTH;
            }

            if (g_hostInterfaces->sendErrorLog)
            {
                uint8_t * temp_buff = new uint8_t [l_msgSize ];
                uint64_t l_flatsize = io_err->flatten ( temp_buff,
                                                        l_msgSize,
                                                        true  /* truncate */ );
                if( l_flatsize == 0 )
                {
                    TRACFCOMP(g_trac_errl,
                              INFO_MRK"Problem flattening error %.8X",
                              io_err->eid());
                    // nothing else to do here since I can't create a new log,
                    //  better to keep running than to assert in case we get
                    //  stuck in a loop on the restart
                    break;
                }

                size_t rc = g_hostInterfaces->sendErrorLog(io_err->plid(),
                                                           l_msgSize,
                                                           temp_buff);

                if(rc)
                {
                    TRACFCOMP(g_trac_errl,
                              ERR_MRK"Failed sending error log to FSP via "
                              "sendErrorLog. rc: %d. plid: 0x%08x",
                              rc,
                              io_err->plid() );
                }

               delete [] temp_buff;
            }
            else if (g_hostInterfaces->firmware_request)
            {
                // Get an accurate size of memory needed to transport
                // the data for the firmware_request request struct
                uint64_t l_req_fw_msg_size =
                         hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                         sizeof(hostInterfaces::hbrt_fw_msg::error_log) +
                         l_msgSize -
                         sizeof(hostInterfaces::hbrt_fw_msg::error_log.i_data);

                // Create the firmware_request request struct to send data
                hostInterfaces::hbrt_fw_msg *l_req_fw_msg =
                      (hostInterfaces::hbrt_fw_msg *)malloc(l_req_fw_msg_size);
                memset(l_req_fw_msg, 0, l_req_fw_msg_size);

                // Populate the firmware_request request struct with given data
                l_req_fw_msg->io_type =
                                hostInterfaces::HBRT_FW_MSG_TYPE_ERROR_LOG;
                l_req_fw_msg->error_log.i_plid = io_err->plid();
                l_req_fw_msg->error_log.i_errlSize = l_msgSize;
                uint64_t l_flatsize = io_err->flatten (&(l_req_fw_msg->error_log.i_data),
                                                       l_msgSize,
                                                       true /*truncate*/);
                if( l_flatsize == 0 )
                {
                    TRACFCOMP(g_trac_errl,
                              INFO_MRK"Problem flattening error %.8X",
                              io_err->eid());
                    // nothing else to do here since I can't create a new log,
                    //  better to keep running than to assert in case we get
                    //  stuck in a loop on the restart
                    break;
                }

                // Trace out firmware request info
                TRACFCOMP(g_trac_errl,
                          INFO_MRK"Error log firmware request info: "
                          "io_type:%d, plid: 0x%08x, errlSize:%d",
                          l_req_fw_msg->io_type,
                          l_req_fw_msg->error_log.i_plid,
                          l_req_fw_msg->error_log.i_errlSize);

                TRACFBIN(g_trac_errl, "Error log firmware request data: ",
                         &(l_req_fw_msg->error_log.i_data),
                         l_req_fw_msg->error_log.i_errlSize);

                // Create the firmware_request response struct to receive data
                hostInterfaces::hbrt_fw_msg l_resp_fw_msg;
                uint64_t l_resp_fw_msg_size = sizeof(l_resp_fw_msg);
                memset(&l_resp_fw_msg, 0, l_resp_fw_msg_size);


                // Make the firmware_request call
                errlHndl_t l_err = firmware_request_helper(l_req_fw_msg_size,
                                                           l_req_fw_msg,
                                                           &l_resp_fw_msg_size,
                                                           &l_resp_fw_msg);

                // Should not get an error log, but if it happens,
                // just delete it.
                delete l_err, l_err = nullptr;
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

    // Release the firmware_request request struct
    free(l_req_fw_msg);
    l_req_fw_msg = nullptr;

    TRACFCOMP( g_trac_errl, EXIT_MRK"sendMboxMsg()" );
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

        // Increment our persistent counter so we don't reuse EIDs
        //  after reboots or mpipl
        TARGETING::Target * sys = NULL;
        if( TARGETING::targetService().isInitialized() )
        {
            TARGETING::targetService().getTopLevelTarget( sys );
            sys->setAttr<TARGETING::ATTR_HOSTSVC_PLID>(io_err->eid()+1);
            // update instance variable in case target service was not
            // avaible when errlmanager's constructor was called.
            iv_pldWaitEnable &= !sys->getAttr<TARGETING::ATTR_DISABLE_PLD_WAIT>();
        }

        // If this is not an FSP and this log has a callout that
        // could trigger a maintenance request,we have to allow
        // time for the BMC to detect possible Power Line
        // Disturbances before we process the log
        auto do_pld_wait = iv_pldWaitEnable && io_err->hasMaintenanceCallout();
        TRACFCOMP(g_trac_errl,
                  "commitErrLog() called by %.4X for eid=%.8x, Reasoncode=%.4X, Sev=%s %s waiting for BMC to determine if Power Line Disturbance (PLD) occurred",
                  i_committerComp, io_err->eid(), io_err->reasonCode(), errl_sev_str_map.at(io_err->sev()), do_pld_wait ? "" : "not"  );

        if(do_pld_wait)
        {
            nanosleep(MIN_PLD_WAIT_TIME_SEC, 0);
        }

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

    // Gard callouts are handled by the HWSV if there is an FSP
    // if we attempt to create a gard record it requires us to read
    // PNOR which we cannot do on FSP based machines
    if(!INITSERVICE::spBaseServicesEnabled())
    {
        if ((pCalloutUD->type == HWAS::HW_CALLOUT) &&
            (pCalloutUD->gardErrorType != HWAS::GARD_NULL))
        {
                TARGETING::Target *pTarget = NULL;
                uint8_t * l_uData = (uint8_t *)(pCalloutUD + 1);
                bool l_err = HWAS::retrieveTarget(l_uData, pTarget, io_errl);

                if (!l_err)
                {
                    errlHndl_t errl = HWAS::theDeconfigGard().platCreateGardRecord
                        (pTarget,
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
    }
    return true;
}

} // End namespace


//------------------------------------------------------------------------
void initErrlManager(void)
{
    // Note: rtPnor needs to be setup before this is called
    // call errlManager ctor so that we're ready and waiting for errors.
    ERRORLOG::theErrlManager::instance();
}


struct registerInitErrlManager
{
    registerInitErrlManager()
    {
        // Register interface for Host to call
        postInitCalls_t * rt_post = getPostInitCalls();
        rt_post->callInitErrlManager = &initErrlManager;
    }
};

registerInitErrlManager g_registerInitErrlManager;

