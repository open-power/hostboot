/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/runtime/rt_errlmanager.C $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2022                        */
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
#include <errl/errlreasoncodes.H>

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
            bool l_passed = sendErrLogToBmc(io_err);
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

namespace initiate_gard
{

using namespace TARGETING;
using namespace ERRORLOG;

/* @brief Get the resource type associated with the given target, for
 * INITIATE_GARD firmware requests.
 *
 * @param[in] i_target  The target to get the resource type for.
 * @return              The resource type, or ResourceInvalid if none.
 */
hostInterfaces::InitiateGardResourceType get_resource_type(TARGETING::Target* const i_target)
{
    hostInterfaces::InitiateGardResourceType resource_type = hostInterfaces::ResourceInvalid;

    switch (i_target->getAttr<ATTR_TYPE>())
    {
    case TYPE_FC:
    case TYPE_CORE:
        resource_type = hostInterfaces::ResourceProc;
        break;
    case TYPE_NX:
        resource_type = hostInterfaces::ResourceNxUnit;
        break;
    default:
        break;
    }

    return resource_type;
}

// The failure value for get_resource_id(Target*)
static const uint16_t RESOURCE_ID_INVALID = 0xFFFF;

/* @brief Get the resource ID for a given target, for INITIATE_GARD firmware
 * requests.
 *
 * @param[in] i_target  The target to get the resource ID for.
 * @return              The target's resource ID, or RESOURCE_ID_INVALID if none.
 */
uint16_t get_resource_id(TARGETING::Target* const i_target)
{
    uint16_t resource_id = RESOURCE_ID_INVALID;

    switch (i_target->getAttr<ATTR_TYPE>())
    {
    case TYPE_FC:
        resource_id = i_target->getAttr<ATTR_ORDINAL_ID>();
        break;
    case TYPE_CORE:
    {
        const auto parent_fc = getImmediateParentByAffinity(i_target);
        resource_id = parent_fc->getAttr<ATTR_ORDINAL_ID>();
        break;
    }
    case TYPE_NX:
    {
        const auto parent_proc = getParentChip(i_target);

        // This is what HDAT's PCRD section uses for the processor ID
        resource_id = parent_proc->getAttr<ATTR_ORDINAL_ID>();
        break;
    }
    default:
        break;
    }

    return resource_id;
}

/* @brief Send a firmware request to notify the hypervisor that a resource has
 * been guarded.
 *
 * @param[in] i_error   The error log that caused the guard.
 * @param[in] i_target  The target being guarded.
 * @return              Error, if any, otherwise nullptr.
 */
errlHndl_t notify_hypervisor_of_resource_gard(const errlHndl_t i_error, TARGETING::Target* const i_target)
{
    errlHndl_t errl = nullptr;

    do
    {

    if (!g_hostInterfaces || !g_hostInterfaces->firmware_request)
    {
        TRACFCOMP(g_trac_errl,
                  ERR_MRK"notify_hypervisor_of_resource_gard: "
                  "Hypervisor firmware_request interface not linked");

        /*@
         * @errortype
         * @severity      ERRL_SEV_INFORMATIONAL
         * @moduleid      ERRL_NOTIFY_HYPERVISOR_OF_RESOURCE_GARD
         * @reasoncode    ERRL_RT_NULL_FIRMWARE_REQUEST_PTR
         * @userdata1     PLID of error log that called out the resource
         * @userdata2     HUID of the resource
         * @devdesc       Unable to make firmware request
         * @custdesc      Firmware unable to send message to hypervisor at runtime
         */
        errl = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                             ERRL_NOTIFY_HYPERVISOR_OF_RESOURCE_GARD,
                             ERRL_RT_NULL_FIRMWARE_REQUEST_PTR,
                             ERRL_GETPLID_SAFE(i_error),
                             get_huid(i_target),
                             ErrlEntry::NO_SW_CALLOUT);

        errl->addProcedureCallout(HWAS::EPUB_PRC_PHYP_CODE, HWAS::SRCI_PRIORITY_HIGH);

        break;
    }

    hostInterfaces::hbrt_fw_msg req_fw_msg = { };

    req_fw_msg.io_type = hostInterfaces::HBRT_FW_MSG_TYPE_INITIATE_GARD;
    req_fw_msg.initiate_gard.errorType = hostInterfaces::FipsInitiatedGard;
    req_fw_msg.initiate_gard.resourceType = get_resource_type(i_target);

    if (req_fw_msg.initiate_gard.resourceType == hostInterfaces::ResourceInvalid)
    {
        TRACFCOMP(g_trac_errl,
                  INFO_MRK"notify_hypervisor_of_resource_gard: Unknown resource type "
                  "(PLID=0x%08x, target HUID=0x%08x, target type=%s), "
                  "not notifying the hypervisor of gard.",
                  ERRL_GETPLID_SAFE(i_error),
                  get_huid(i_target),
                  attrToString<ATTR_TYPE>(i_target->getAttr<ATTR_TYPE>()));
        break;
    }

    req_fw_msg.initiate_gard.resourceId = get_resource_id(i_target);

    if (req_fw_msg.initiate_gard.resourceId == RESOURCE_ID_INVALID)
    {
        TRACFCOMP(g_trac_errl,
                  ERR_MRK"notify_hypervisor_of_resource_gard: Cannot obtain resource ID "
                  "for target 0x%08x (PLID=0x%08x)",
                  get_huid(i_target),
                  ERRL_GETPLID_SAFE(i_error));

        /*@
         * @errortype
         * @severity      ERRL_SEV_UNRECOVERABLE
         * @moduleid      ERRL_NOTIFY_HYPERVISOR_OF_RESOURCE_GARD
         * @reasoncode    ERRL_RT_GARD_RESOURCE_ID_NOT_FOUND
         * @userdata1     PLID of error log that called out the resource
         * @userdata2     HUID of the resource
         * @devdesc       Unable to get resource ID for runtime guard, this is a code bug
         * @custdesc      Internal firmware error at runtime
         */
        errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                             ERRL_NOTIFY_HYPERVISOR_OF_RESOURCE_GARD,
                             ERRL_RT_GARD_RESOURCE_ID_NOT_FOUND,
                             ERRL_GETPLID_SAFE(i_error),
                             get_huid(i_target),
                             ErrlEntry::ADD_SW_CALLOUT);
        break;
    }

    hostInterfaces::hbrt_fw_msg resp_fw_msg = { };
    size_t resp_fw_msg_size = sizeof(resp_fw_msg);

    TRACFCOMP(g_trac_errl,
              INFO_MRK"Sending INITIATE_GARD firmware_request, "
              "errorType = %d, resourceType = %d, resourceId = %d",
              req_fw_msg.initiate_gard.errorType,
              req_fw_msg.initiate_gard.resourceType,
              req_fw_msg.initiate_gard.resourceId);

    // Make the firmware_request call
    errl = firmware_request_helper(sizeof(req_fw_msg),
                                   &req_fw_msg,
                                   &resp_fw_msg_size,
                                   &resp_fw_msg);

    TRACFCOMP(g_trac_errl, "INITIATE_GARD firmware_request returned %p (PLID=0x%08x)",
              errl, ERRL_GETPLID_SAFE(errl));

    } while (false);

    return errl;
}

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

                errl = initiate_gard::notify_hypervisor_of_resource_gard(io_errl, pTarget);

                if (errl)
                {
                    TRACFCOMP( g_trac_errl,
                               ERR_MRK"rt_processCallout: error from notify_hypervisor_of_resource_gard (PLID=0x%08x)",
                               ERRL_GETPLID_SAFE(errl));
                    errlCommit(errl, HWAS_COMP_ID);
                }
            }
        }
    }
    return true;
}

date_time_t ErrlManager::_getCurrentDateTime()
{
    date_time_t l_result{};

    errlHndl_t l_errl = nullptr;

    do {
    if((nullptr == g_hostInterfaces) ||
       (nullptr == g_hostInterfaces->firmware_request))
    {
        TRACFCOMP(g_trac_errl, ERR_MRK"_getCurrentDateTime: firmware_request interface not found");
        break;
    }

    hostInterfaces::hbrt_fw_msg l_request{};
    size_t l_requestSize = sizeof(l_request);
    l_request.io_type = hostInterfaces::HBRT_FW_MSG_TYPE_GET_ELOG_TIME;

    hostInterfaces::hbrt_fw_msg l_response{};
    size_t l_responseSize = sizeof(l_response);

    l_errl = firmware_request_helper(l_requestSize,
                                     &l_request,
                                     &l_responseSize,
                                     &l_response);
    if(l_errl)
    {
        TRACFCOMP(g_trac_errl, ERR_MRK"_getCurrentDateTime: firmware_request_helper returned an error; deleting the error and continuing");
        delete l_errl;
        l_errl = nullptr;
        break;
    }

    hostInterfaces::dateTime* l_bcdTime = reinterpret_cast<hostInterfaces::dateTime*>(&l_response);

    l_result.format.year = l_bcdTime->year;
    l_result.format.month = l_bcdTime->month;
    l_result.format.day = l_bcdTime->day;
    l_result.format.hour = l_bcdTime->hour;
    l_result.format.minute = l_bcdTime->minute;
    l_result.format.second = l_bcdTime->second;

    } while(0);

    return l_result;
}

date_time_t ErrlManager::getCurrentDateTime()
{
    return ERRORLOG::theErrlManager::instance()._getCurrentDateTime();
}

void ErrlManager::setFwReleaseVersion_rt()
{
    errlHndl_t l_errl(nullptr);

    TARGETING::ATTR_FW_RELEASE_VERSION_type fw_release_string = { };

    // Get the FW release string
    size_t l_miKeywordSize(sizeof(fw_release_string));
    char   l_miKeyword[l_miKeywordSize] = { 0 };

    l_errl = ErrlManager::getMarkerLidMiKeyword(l_miKeywordSize, l_miKeyword);
    if (!l_errl)
    {
        memcpy(fw_release_string, l_miKeyword, l_miKeywordSize);

        TARGETING::Target * l_sys = NULL;
        if ( TARGETING::targetService().isInitialized() )
        {
            TARGETING::targetService().getTopLevelTarget( l_sys );
        }
        else
        {
            TRACFCOMP( g_trac_errl,
                       ERR_MRK"ErrlManager::setFwReleaseVersion_rt(): TARGETING is not ready, "
                               "unable to set the FW Release Version to %s", fw_release_string);

            // If hitting this, then the call to setFwReleaseVersion_rt needs to be
            // moved to a location in the code after when TARGETING is ready
            assert(false, "ErrlManager::setFwReleaseVersion_rt(): TARGETING is not ready, "
                          "unable to set the FW Release Version to %s", fw_release_string);
        }

        if (l_sys)
        {
            l_sys->setAttr<TARGETING::ATTR_FW_RELEASE_VERSION>(fw_release_string);
            TRACFCOMP( g_trac_errl,
                       INFO_MRK"ErrlManager::setFwReleaseVersion_rt(): "
                       "FW Release Version set to %s", fw_release_string);
        }
        else
        {
            TRACFCOMP( g_trac_errl,
                       ERR_MRK"ErrlManager::setFwReleaseVersion_rt(): TARGETING is not ready, "
                               "unable to set the FW Release Version to %s", fw_release_string);

            // If hitting this, then the call to setFwReleaseVersion_rt needs to be
            // moved to a location in the code after when TARGETING is ready
            assert(false, "ErrlManager::setFwReleaseVersion_rt(): TARGETING is not ready, "
                          "unable to set the FW Release Version to %s", fw_release_string);
        }
    }
    else // Received an error log from the call to ErrlManager::getMarkerLidMiKeyword
    {
        commitErrLog(l_errl, ERRL_COMP_ID);
        TRACFCOMP( g_trac_errl,
                   ERR_MRK"ErrlManager::setFwReleaseVersion_rt(): getMarkerLidMiKeyword failed");
    }
} // ErrlManager::setFwReleaseVersion_rt

} // End namespace ERRORLOG

//------------------------------------------------------------------------
void initErrlManager(void)
{
    // Note: rtPnor needs to be setup before this is called
    // call errlManager ctor so that we're ready and waiting for errors.
    ERRORLOG::theErrlManager::instance();

    // Note: TARGETING needs to be ready before this is called
    // Set the FW Release Version
    ERRORLOG::theErrlManager::instance().setFwReleaseVersion_rt();
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
