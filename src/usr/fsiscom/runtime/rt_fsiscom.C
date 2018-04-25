/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fsiscom/runtime/rt_fsiscom.C $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <fsiscom/fsiscom_reasoncodes.H>
#include "../fsiscom.H"
#include <scom/scomif.H>
#include <scom/runtime/rt_scomif.H>
#include <targeting/common/utilFilter.H>

#include <runtime/hbrt_utilities.H>        // createGenericFspMsg
#include <util/runtime/rt_fwreq_helper.H>  // firmware_request_helper
#include <plat/cen/prdfCenChnlFailCache.H> // chnlFailScomList

#include <map>

// Trace definition
trace_desc_t* g_trac_fsiscom = NULL;
TRAC_INIT(&g_trac_fsiscom, FSISCOM_COMP_NAME, 2*KILOBYTE, TRACE::BUFFER_SLOW);

namespace FSISCOM
{

/**
 * @brief This function sends the scom op to the FSP
 *
 * @param[in]     i_opType    Scom operation type, see driverif.H
 * @param[in]     i_target    Scom target
 * @param[in]     i_scomAddr  Scom address
 * @param[in/out] io_buffer   Read: Pointer to output data storage
 *                            Write: Pointer to input data storage
 * @return  errlHndl_t
 */
errlHndl_t sendScomOpToFsp(DeviceFW::OperationType i_opType,
                           TARGETING::TargetHandle_t i_target,
                           uint64_t i_scomAddr,
                           void * io_buffer)
{
   errlHndl_t l_err = nullptr;

   // Handles to the firmware messages
   hostInterfaces::hbrt_fw_msg *l_req_fw_msg  = nullptr;
   hostInterfaces::hbrt_fw_msg *l_resp_fw_msg = nullptr;

   do
   {
      if ((nullptr == g_hostInterfaces) ||
          (nullptr == g_hostInterfaces->firmware_request))
      {
         TRACFCOMP(g_trac_fsiscom, ERR_MRK
                   "Hypervisor firmware_request interface not linked");

         /*@
          * @errortype
          * @severity         ERRL_SEV_UNRECOVERABLE
          * @moduleid         MOD_FSISCOM_RT_SEND_SCOM_TO_FSP
          * @reasoncode       RC_RT_INTERFACE_ERR
          * @userdata1        target's HUID
          * @userdata2        SCOM address
          * @devdesc          Hypervisor firmware request interface not linked
          */
         l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         MOD_FSISCOM_RT_SEND_SCOM_TO_FSP,
                                         RC_RT_INTERFACE_ERR,
                                         get_huid(i_target),
                                         i_scomAddr,
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
         break;
      }

      // Create and initialize to zero a few needed variables
      uint32_t l_fsp_data_size(0);
      uint64_t l_req_fw_msg_size(0), l_resp_fw_msg_size(0);

      // Create the dynamic firmware messages
      createGenericFspMsg(sizeof(SingleScomOpHbrtFspData_t),
                          l_fsp_data_size,
                          l_req_fw_msg_size,
                          l_req_fw_msg,
                          l_resp_fw_msg_size,
                          l_resp_fw_msg);

      // If there was an issue with creating the messages,
      // create an Error Log entry and exit
      if (!l_req_fw_msg || !l_resp_fw_msg)
      {
         TRACFCOMP(g_trac_fsiscom, ERR_MRK
                   "Unable to allocate firmware request messages");

         /*@
          * @errortype
          * @severity         ERRL_SEV_UNRECOVERABLE
          * @moduleid         MOD_FSISCOM_RT_SEND_SCOM_TO_FSP
          * @reasoncode       RC_RT_NULL_FW_MSG_PTR
          * @userdata1        target's HUID
          * @userdata2        SCOM address
          * @devdesc          Unable to allocate firmware request messages
          */
         l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         MOD_FSISCOM_RT_SEND_SCOM_TO_FSP,
                                         RC_RT_NULL_FW_MSG_PTR,
                                         get_huid(i_target),
                                         i_scomAddr,
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
         break;
      }

      // Populate the request message with given data
      l_req_fw_msg->generic_msg.msgq = MBOX::FSP_SCOM_OPS_MSGQ;
      l_req_fw_msg->generic_msg.msgType =
                                GenericFspMboxMessage_t::MSG_SINGLE_SCOM_OP;

      // Create a useful struct to populate the generic_msg::data field
      // Set the command-specific portion of the FSP message
      SingleScomOpHbrtFspData_t* l_fspData =
                  reinterpret_cast<SingleScomOpHbrtFspData_t*>
                                 (&(l_req_fw_msg->generic_msg.data));
      l_fspData->scom_op   = i_opType;
      l_fspData->huid      = get_huid(i_target);
      l_fspData->scom_addr = i_scomAddr;
      l_fspData->scom_data = *((uint64_t *)io_buffer);

      // Make the firmware_request call
      // Ask the FSP to perform this SCOM operation
      TRACFCOMP(g_trac_fsiscom, "Sending SINGLE_SCOM_OP firmware_request, "
                                "op=%c, huid=0x%X, addr=%llX",
                                (i_opType == DeviceFW::READ) ? 'r' : 'w',
                                l_fspData->huid, l_fspData->scom_addr);
      l_err = firmware_request_helper(l_req_fw_msg_size,
                                      l_req_fw_msg,
                                      &l_resp_fw_msg_size,
                                      l_resp_fw_msg);

      if (l_err)
      {
         TRACFCOMP(g_trac_fsiscom, ERR_MRK
                   "FSP scom read/write failed. "
                   "target 0x%llX addr 0x%llX r/w %d",
                   get_huid(i_target), i_scomAddr, i_opType);

         break;
      }

      // Create a useful struct to populate the generic_msg::data field
      // Get the command-specific portion of the returned FSP message
      l_fspData =
                  reinterpret_cast<SingleScomOpHbrtFspData_t*>
                                 (&(l_resp_fw_msg->generic_msg.data));
      *((uint64_t *)io_buffer) = l_fspData->scom_data;
   } while(0);

   // Release the firmware messages and set to NULL
   delete [] l_req_fw_msg;
   delete [] l_resp_fw_msg;
   l_req_fw_msg = l_resp_fw_msg = nullptr;

   return l_err;
}


/**
 * @brief Ask FSP to read list of SCOMs
 *
 * @param[in]     i_target    Scom target
 * @param[in]     i_scomAddr  Scom addresses to read
 * @param[in/out] o_scomValue Scom values read (0xDEADBEEF for errors)
 * @return  errlHndl_t
 */
errlHndl_t sendMultiScomReadToFsp(TARGETING::TargetHandle_t i_target,
                                  std::vector<uint64_t> &i_scomAddr,
                                  std::vector<uint64_t> &o_scomValue)
{
   errlHndl_t l_err = nullptr;

   // Handles to the firmware messages
   hostInterfaces::hbrt_fw_msg *l_req_fw_msg  = nullptr;
   hostInterfaces::hbrt_fw_msg *l_resp_fw_msg = nullptr;

   do
   {
      if ((nullptr == g_hostInterfaces) ||
          (nullptr == g_hostInterfaces->firmware_request))
      {
         TRACFCOMP(g_trac_fsiscom, ERR_MRK
                   "Hypervisor firmware_request interface not linked");

         /*@
          * @errortype
          * @severity         ERRL_SEV_UNRECOVERABLE
          * @moduleid         MOD_FSISCOM_RT_SEND_MULTI_SCOM_TO_FSP
          * @reasoncode       RC_RT_INTERFACE_ERR
          * @userdata1        target's HUID
          * @userdata2        # of SCOMs to read
          * @devdesc          Hypervisor firmware request interface not linked
          */
         l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         MOD_FSISCOM_RT_SEND_MULTI_SCOM_TO_FSP,
                                         RC_RT_INTERFACE_ERR,
                                         get_huid(i_target),
                                         i_scomAddr.size(),
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
         break;
      }

      // Create and initialize to zero a few needed variables
      uint32_t l_fsp_data_size(0);
      uint64_t l_req_fw_msg_size(0), l_resp_fw_msg_size(0);

      // Need to add the array of addresses/values
      size_t   l_numScoms = i_scomAddr.size();
      uint64_t l_msg_size = sizeof(MultiScomReadHbrtFspData_t);

      // Default MultiScomRead message size is for only one SCOM, need to
      // add any additional SCOMs to the message size in order to have the
      // additional space at the end of the struct.
      if (l_numScoms > 1)
      {
          l_msg_size += (l_numScoms - 1) * sizeof(uint64_t);
      }

      // Create the dynamic firmware messages
      createGenericFspMsg(l_msg_size,
                          l_fsp_data_size,
                          l_req_fw_msg_size,
                          l_req_fw_msg,
                          l_resp_fw_msg_size,
                          l_resp_fw_msg);

      // If there was an issue with creating the messages,
      // create an Error Log entry and exit
      if (!l_req_fw_msg || !l_resp_fw_msg)
      {
         TRACFCOMP(g_trac_fsiscom, ERR_MRK
                   "Unable to allocate firmware request messages");

         /*@
          * @errortype
          * @severity         ERRL_SEV_UNRECOVERABLE
          * @moduleid         MOD_FSISCOM_RT_SEND_MULTI_SCOM_TO_FSP
          * @reasoncode       RC_RT_NULL_FW_MSG_PTR
          * @userdata1        target's HUID
          * @userdata2        # of SCOMs to read
          * @devdesc          Unable to allocate firmware request messages
          */
         l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         MOD_FSISCOM_RT_SEND_MULTI_SCOM_TO_FSP,
                                         RC_RT_NULL_FW_MSG_PTR,
                                         get_huid(i_target),
                                         i_scomAddr.size(),
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
         break;
      }

      // Populate the request message with given data
      l_req_fw_msg->generic_msg.msgq = MBOX::FSP_SCOM_OPS_MSGQ;
      l_req_fw_msg->generic_msg.msgType =
                                GenericFspMboxMessage_t::MSG_MULTI_SCOM_OP;

      // Create a useful struct to populate the generic_msg::data field
      // Set the command-specific portion of the FSP message
      MultiScomReadHbrtFspData_t* l_fspData =
                  reinterpret_cast<MultiScomReadHbrtFspData_t*>
                                 (&(l_req_fw_msg->generic_msg.data));
      l_fspData->huid      = get_huid(i_target);
      l_fspData->scom_num  = l_numScoms;
      // copy SCOM addresses into scom_data
      std::copy(i_scomAddr.begin(), i_scomAddr.end(), &(l_fspData->scom_data));

      // Make the firmware_request call
      // Ask the FSP to perform this SCOM operation
      TRACFCOMP(g_trac_fsiscom, "Sending MULTI_SCOM_OP firmware_request");
      l_err = firmware_request_helper(l_req_fw_msg_size,
                                      l_req_fw_msg,
                                      &l_resp_fw_msg_size,
                                      l_resp_fw_msg);

      if (l_err)
      {
         TRACFCOMP(g_trac_fsiscom, ERR_MRK
                   "FSP multi-scom read failed. target 0x%llX",
                   get_huid(i_target));

         break;
      }

      // Create a useful struct to populate the generic_msg::data field
      // Get the command-specific portion of the returned FSP message
      l_fspData =
                  reinterpret_cast<MultiScomReadHbrtFspData_t*>
                                 (&(l_resp_fw_msg->generic_msg.data));
      if (l_fspData->scom_num != l_numScoms)
      {
         // Can't continue because we don't know how the returned SCOM values
         // match with the requested SCOM addresses.

         TRACFCOMP(g_trac_fsiscom, ERR_MRK
                   "FSP multi-scom read failed. target 0x%llX, "
                   "SCOMs requested(%d) != SCOMs read(%d)",
                   get_huid(i_target), l_numScoms, l_fspData->scom_num);

         /*@
          * @errortype
          * @severity         ERRL_SEV_PREDICTIVE
          * @moduleid         MOD_FSISCOM_RT_SEND_MULTI_SCOM_TO_FSP
          * @reasoncode       RC_INVALID_LENGTH
          * @userdata1        target's HUID
          * @userdata2[00:31] # of SCOMs requested
          * @userdata2[32:63] # of SCOMs returned
          * @devdesc          Multi-SCOM read did not return correct SCOMs
          */
         l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                         MOD_FSISCOM_RT_SEND_MULTI_SCOM_TO_FSP,
                                         RC_INVALID_LENGTH,
                                         get_huid(i_target),
                                         TWO_UINT32_TO_UINT64(
                                                         l_numScoms,
                                                         l_fspData->scom_num),
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

         break;
      }
      o_scomValue.insert(o_scomValue.end(),
                         &(l_fspData->scom_data),
                         &(l_fspData->scom_data) + l_numScoms);
   } while(0);

   // Release the firmware messages and set to NULL
   delete [] l_req_fw_msg;
   delete [] l_resp_fw_msg;
   l_req_fw_msg = l_resp_fw_msg = nullptr;

   return l_err;
}

// Mark the target and all the target's children as useFsiScom.
static void markUseFsiScom(TARGETING::TargetHandle_t i_target)
{
    // Mark target
    TARGETING::ScomSwitches l_switches = {0};
    if (i_target->tryGetAttr<TARGETING::ATTR_SCOM_SWITCHES>(l_switches))
    {
        l_switches.useFsiScom = 1;
        l_switches.useInbandScom = 0;
        i_target->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(l_switches);
    }

    // Mark children
    TARGETING::TargetHandleList pChildList;
    TARGETING::PredicateHwas    isFunctional;
    isFunctional.functional(true);

    TARGETING::targetService().getAssociated(pChildList, i_target,
                                 TARGETING::TargetService::CHILD_BY_AFFINITY,
                                 TARGETING::TargetService::ALL, &isFunctional);
    for (auto& l_child: pChildList)
    {
        markUseFsiScom(l_child);
    }
}

// This map is used to cache a bulk read of SCOM values that we expect PRD
// to ask for.  A map of translated SCOM addresses and values is mapped to
// the parent chip target.
static std::map<TARGETING::Target *, std::map<uint64_t, uint64_t>> g_scomCache;

/**
 * @brief DMI channel has checkstopped.  Mark it bad and switch to FSP access.
 *
 * @param[in]     i_target    membuf target
 * @return  None
 */
void switchToFspScomAccess(TARGETING::TargetHandle_t i_target)
{
    TRACDCOMP(g_trac_fsiscom,ENTER_MRK"switchToFspScomAccess");
    errlHndl_t l_err = NULL;

    // Need to mark the target's DMI channel and all targets below it
    // as "useFsiScom" and bulk SCOM read requests should be sent to
    // the FSP in order to populate the SCOM cache.
    TARGETING::PredicateCTM     l_dmi(TARGETING::CLASS_UNIT,
                                      TARGETING::TYPE_DMI);
    TARGETING::TargetHandleList l_dmiList;

    TARGETING::targetService().getAssociated(l_dmiList,
                                  i_target,
                                  TARGETING::TargetService::PARENT_BY_AFFINITY,
                                  TARGETING::TargetService::ALL,
                                  &l_dmi);
    if (l_dmiList.size() != 1)
    {
        TRACFCOMP(g_trac_fsiscom,ERR_MRK"Unable to find DMI for Centaur.");
    }
    else
    {
        TARGETING::TargetHandle_t l_dmiParent = nullptr;

        l_dmiParent = *(l_dmiList.begin());
        markUseFsiScom(l_dmiParent);

        // All of the cached SCOMs will map to the same membuf target (after
        // SCOM address translation).
        std::map<uint64_t, uint64_t> l_newmap;
        TARGETING::TargetHandle_t l_membuf = nullptr;

        if (i_target->getAttr<TARGETING::ATTR_TYPE>() ==
                                                        TARGETING::TYPE_MEMBUF)
        {
            l_membuf = i_target;
        }
        else
        {
            l_membuf = const_cast<TARGETING::TargetHandle_t>
                                          (TARGETING::getParentChip(i_target));
        }

        // Cache SCOMs that PRD will request.  chnlFailScomList is a map of
        // target types (MEMBUF, MBA, etc) and the associated SCOMs for them.
        // chnlFailScomList is maintained by PRD and defined in
        // prdfCenChnlFailCache.H.
        for (auto& l_typeScoms: PRDF::chnlFailScomList)
        {
            // For each target type in chnlFailScomList, find the associated
            // targets and cache their SCOMs
            TARGETING::TargetHandleList l_targetList;
            getChildAffinityTargets(l_targetList, l_dmiParent,
                                    TARGETING::CLASS_NA, l_typeScoms.first);

            for (auto& l_target: l_targetList)
            {
                std::vector<uint64_t> l_scomVals;

                l_scomVals.clear();
                l_err = sendMultiScomReadToFsp(l_target,
                                               l_typeScoms.second,
                                               l_scomVals);
                if (l_err)
                {
                    TRACFCOMP(g_trac_fsiscom,ERR_MRK
                              "There was an error caching the SCOMs "
                              "for huid(0x%llX)", get_huid(l_target));
                    errlCommit(l_err, RUNTIME_COMP_ID);
                    continue;
                }

                // Combine the requested SCOM addrs with the returned values in
                // a local map, insert into cache keyed by target.  Don't save
                // SCOMs with a returned value of 0xDEADBEEF.
                for (size_t i = 0;i < l_typeScoms.second.size();++i)
                {
                    bool     l_needsWakeup = false;
                    uint64_t l_relAddr     = 0; // relative SCOM address
                    uint64_t l_transAddr   = 0; // translated SCOM address

                    l_relAddr = l_typeScoms.second[i];
                    l_transAddr = l_relAddr;

                    if (l_target != l_membuf) // membuf addresses don't need
                                              // translation
                    {
                        l_err = SCOM::scomTranslate(l_target,
                                                    l_transAddr,
                                                    l_needsWakeup);
                    }

                    if (l_err)
                    {
                        TRACFCOMP(g_trac_fsiscom,ERR_MRK
                                  "There was an error translating the SCOM "
                                  "address (0x%llX) for huid(0x%llX)",
                                  l_relAddr, get_huid(l_target));
                        errlCommit(l_err, RUNTIME_COMP_ID);
                        continue;
                    }

                    if (l_scomVals[i] != 0xDEADBEEF)
                    {
                        l_newmap[l_transAddr] = l_scomVals[i];
                    }
                } // for SCOM address list
            } // for l_targetList
        } // for chnlFailScomList

        // Copy local map into cache for later use.
        g_scomCache[l_membuf] = l_newmap;
    }

    TRACDCOMP(g_trac_fsiscom,EXIT_MRK"switchToFspScomAccess");
}


// Direct Centaur FSI SCOM calls through this interface at runtime.
// This is an alternate route for when a DMI channel checkstop has
// occurred, and PHYP cannot service the operation.
DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::FSISCOM,
                      TARGETING::TYPE_MEMBUF,
                      fsiScomPerformOp);

/**
 * @brief Complete the SCOM operation through the FSP.
 *
 * @param[in]     i_opType    Operation type, see driverif.H
 * @param[in]     i_target    SCOM target
 * @param[in/out] io_buffer   Read: Pointer to output data storage
 *                            Write: Pointer to input data storage
 * @param[in/out] io_buflen   Input: size of io_buffer (in bytes)
 *                            Output: Read:  Size of output data
 *                                    Write: Size of data written
 * @param[in]   i_accessType  Access type
 * @param[in]   i_args        This is an argument list for DD framework.
 *                            In this function, there's only one argument,
 *                            which is the SCOM address
 * @return  errlHndl_t
 */
errlHndl_t fsiScomPerformOp(DeviceFW::OperationType i_opType,
                            TARGETING::TargetHandle_t i_target,
                            void* io_buffer,
                            size_t& io_buflen,
                            int64_t i_accessType,
                            va_list i_args)
{
    TRACDCOMP(g_trac_fsiscom,ENTER_MRK"fsiScomPerformOp");
    errlHndl_t l_err  = nullptr;
    uint64_t   l_addr = va_arg(i_args,uint64_t);

    l_err = SCOM::scomOpSanityCheck(i_opType,
                                    i_target,
                                    io_buffer,
                                    io_buflen,
                                    l_addr,
                                    sizeof(uint64_t));

    if (l_err)
    {
        // Trace here - sanity check does not know scom type
        TRACFCOMP(g_trac_fsiscom,"Runtime FSIScom sanity check failed");
    }
    else
    {
        bool found = false;
        auto targ = g_scomCache.find(i_target); // find target, returns map of
                                                // SCOM addresses and values

        if (i_opType == DeviceFW::READ && targ != g_scomCache.end())
        {
            auto scomVal = targ->second.find(l_addr); // find SCOM address

            if (scomVal != targ->second.end())
            {
                // If we found the SCOM in the cache, then erase it from the
                // cache and return the value.
                found = true;
                uint64_t *val = static_cast<uint64_t *>(io_buffer);
                *val = scomVal->second;
                io_buflen = sizeof(uint64_t);
                targ->second.erase(scomVal);
            }
        }

        if (i_opType == DeviceFW::WRITE || found == false)
        {
            l_err = sendScomOpToFsp(i_opType, i_target, l_addr, io_buffer);
        }
    }

    TRACDCOMP(g_trac_fsiscom,EXIT_MRK"fsiScomPerformOp");

    return l_err;
}

}; // end namespace FSISCOM
