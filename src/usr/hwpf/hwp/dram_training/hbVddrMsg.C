/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/hbVddrMsg.C $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
/* [+] Google Inc.                                                        */
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
#include <sys/task.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/mm.h>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <trace/interface.H>
#include <trace/trace.H>
#include <mbox/mbox_queues.H>
#include <mbox/mboxif.H>

#include <hbVddrMsg.H>
#include <initservice/initserviceif.H>
#include <pnor/pnorif.H>
#include <fapi.H>
#include "platform_vddr.H"


using namespace ERRORLOG;

using namespace TARGETING;

// Trace definition
trace_desc_t* g_trac_volt = NULL;
TRAC_INIT(&g_trac_volt, "HB_VDDR", 1024);

///////////////////////////////////////////////////////////////////////////////
// HBVddrMsg::HBVddrMsg()
///////////////////////////////////////////////////////////////////////////////
HBVddrMsg::HBVddrMsg()
{
    TRACDCOMP( g_trac_volt, ENTER_MRK "HBVddrMsg::HBVddrMsg()" );
    TRACDCOMP( g_trac_volt, EXIT_MRK "HBVddrMsg::HBVddrMsg()" );

};

///////////////////////////////////////////////////////////////////////////////
// HBVddrMsg::~HBVddrMsg()
///////////////////////////////////////////////////////////////////////////////
HBVddrMsg::~HBVddrMsg()
{
    TRACDCOMP( g_trac_volt, ENTER_MRK "HBVddrMsg::~HBVddrMsg()" );
    TRACDCOMP( g_trac_volt, EXIT_MRK "HBVddrMsg::~HBVddrMsg()" );
};


///////////////////////////////////////////////////////////////////////////////
// compareVids
///////////////////////////////////////////////////////////////////////////////

bool compareVids(
    HBVddrMsg::hwsvPowrMemVoltDomainRequest_t i_lhs,
    HBVddrMsg::hwsvPowrMemVoltDomainRequest_t i_rhs)
{
    bool lhsLogicallyBeforeRhs = (i_lhs.domain < i_rhs.domain);

    if (i_lhs.domain == i_rhs.domain)
    {
        lhsLogicallyBeforeRhs = (  static_cast<uint16_t>(i_lhs.domainId)
                                 < static_cast<uint16_t>(i_rhs.domainId) );
    }

    return lhsLogicallyBeforeRhs;
}

///////////////////////////////////////////////////////////////////////////////
// areVidsEqual
///////////////////////////////////////////////////////////////////////////////

bool areVidsEqual(
    HBVddrMsg::hwsvPowrMemVoltDomainRequest_t i_lhs,
    HBVddrMsg::hwsvPowrMemVoltDomainRequest_t i_rhs)
{
    return(   (   i_lhs.domain
               == i_rhs.domain)
           && (   static_cast<uint16_t>(i_lhs.domainId)
               == static_cast<uint16_t>(i_rhs.domainId)) );
}

///////////////////////////////////////////////////////////////////////////////
// isUnusedVoltageDomain
///////////////////////////////////////////////////////////////////////////////

bool isUnusedVoltageDomain(
    HBVddrMsg::hwsvPowrMemVoltDomainRequest_t i_vid)
{
    return (!i_vid.voltageMillivolts);
}

//******************************************************************************
// addMemoryVoltageDomains (templated)
//******************************************************************************

template<
    const ATTRIBUTE_ID OFFSET_DISABLEMENT_ATTR,
    const ATTRIBUTE_ID VOLTAGE_ATTR_WHEN_OFFSET_ENABLED,
    const ATTRIBUTE_ID VOLTAGE_ATTR_WHEN_OFFSET_DISABLED,
    const ATTRIBUTE_ID VOLTAGE_DOMAIN_ID_ATTR >
void HBVddrMsg::addMemoryVoltageDomains(
    const TARGETING::Target* const     i_pMembuf,
          HBVddrMsg::RequestContainer& io_domains) const
{
    assert(
        (i_pMembuf != NULL),
        "HBVddrMsg::addMemoryVoltageDomains: Code bug!  Caller passed NULL "
        "memory buffer target handle.");

    assert(
        (    (   i_pMembuf->getAttr<TARGETING::ATTR_CLASS>()
              == TARGETING::CLASS_CHIP)
          && (   i_pMembuf->getAttr<TARGETING::ATTR_TYPE>()
              == TARGETING::TYPE_MEMBUF)),
        "HBVddrMsg::addMemoryVoltageDomains: Code bug!  Caller passed non-"
        "memory buffer target handle of class = 0x%08X and type of 0x%08X.",
        i_pMembuf->getAttr<TARGETING::ATTR_CLASS>(),
        i_pMembuf->getAttr<TARGETING::ATTR_TYPE>());

    TARGETING::Target* pSysTarget = NULL;
    TARGETING::targetService().getTopLevelTarget(pSysTarget);

    assert(
        (pSysTarget != NULL),
        "HBVddrMsg::addMemoryVoltageDomains: Code bug!  System target was "
        "NULL.");

    typename AttributeTraits< OFFSET_DISABLEMENT_ATTR >::Type
        disableOffsetVoltage =
            pSysTarget->getAttr< OFFSET_DISABLEMENT_ATTR >();

    assert(
        (disableOffsetVoltage <= true),
        "HBVddrMsg::addMemoryVoltageDomains: Code Bug!  Unsupported "
        "value of 0x%02X for attribute ID of 0x%08X.",
        disableOffsetVoltage,
        OFFSET_DISABLEMENT_ATTR);

    // Initialized by constructor to invalid defaults
    HBVddrMsg::hwsvPowrMemVoltDomainRequest_t entry;

    switch(VOLTAGE_DOMAIN_ID_ATTR)
    {
        case TARGETING::ATTR_VMEM_ID:
            entry.domain = MEM_VOLTAGE_DOMAIN_VDDR;
            break;
        case TARGETING::ATTR_VCS_ID:
            entry.domain = MEM_VOLTAGE_DOMAIN_VCS;
            break;
        case TARGETING::ATTR_VPP_ID:
            entry.domain = MEM_VOLTAGE_DOMAIN_VPP;
            break;
        case TARGETING::ATTR_AVDD_ID:
            entry.domain = MEM_VOLTAGE_DOMAIN_AVDD;
            break;
        case TARGETING::ATTR_VDD_ID:
            entry.domain = MEM_VOLTAGE_DOMAIN_VDD;
            break;
        default:
            assert(
                0,
                "HBVddrMsg::addMemoryVoltageDomains: Code Bug!  Unsupported "
                "voltage domain of 0x%08X.",
                VOLTAGE_DOMAIN_ID_ATTR);
            break;
    }

    // There is no reasonable check to validate if a voltage ID we're reading
    // is valid so it has to be assumed good
    entry.domainId = i_pMembuf->getAttr< VOLTAGE_DOMAIN_ID_ATTR >();

    // There is no reasonable check to validate if a voltage we're
    // reading is valid so it has to be assumed good for the cases below
    if(!disableOffsetVoltage)
    {
        typename
        TARGETING::AttributeTraits< VOLTAGE_ATTR_WHEN_OFFSET_ENABLED >::Type
            voltageMillivolts
                = i_pMembuf->getAttr< VOLTAGE_ATTR_WHEN_OFFSET_ENABLED >();

        entry.voltageMillivolts = static_cast<uint32_t>(voltageMillivolts);
        io_domains.push_back(entry);
    }
    else if(   VOLTAGE_ATTR_WHEN_OFFSET_DISABLED
            != VOLTAGE_ATTR_WHEN_OFFSET_ENABLED)
    {
        typename
        TARGETING::AttributeTraits< VOLTAGE_ATTR_WHEN_OFFSET_DISABLED >::Type
            voltageMillivolts
                = i_pMembuf->getAttr< VOLTAGE_ATTR_WHEN_OFFSET_DISABLED >();

        entry.voltageMillivolts = static_cast<uint32_t>(voltageMillivolts);
        io_domains.push_back(entry);
    }
}

///////////////////////////////////////////////////////////////////////////////
// HBVddrMsg::createVddrData
///////////////////////////////////////////////////////////////////////////////

void HBVddrMsg::createVddrData(
    const VDDR_MSG_TYPE     i_requestType,
          RequestContainer& io_request) const
{
    TRACFCOMP( g_trac_volt, ENTER_MRK "HBVddrMsg::createVddrData" );

    // Go through all the memory buffers and gather their domains, domain
    // specific IDs, and domain specific voltages
    io_request.clear();

    do{

        TARGETING::TargetHandleList membufTargetList;
        getAllChips(membufTargetList, TYPE_MEMBUF);

        TARGETING::Target* pMembuf =NULL;
        for (TARGETING::TargetHandleList::const_iterator
                ppMembuf = membufTargetList.begin();
             ppMembuf != membufTargetList.end();
             ++ppMembuf)
        {
            pMembuf = *ppMembuf;

            if(i_requestType == HB_VDDR_ENABLE)
            {
                (void)addMemoryVoltageDomains<
                    TARGETING::ATTR_MSS_CENT_VDD_OFFSET_DISABLE,
                    TARGETING::ATTR_MEM_VDD_OFFSET_MILLIVOLTS,
                    TARGETING::ATTR_MEM_VDD_OFFSET_MILLIVOLTS,
                    TARGETING::ATTR_VDD_ID>(
                        pMembuf,
                        io_request);

                (void)addMemoryVoltageDomains<
                    TARGETING::ATTR_MSS_CENT_AVDD_OFFSET_DISABLE,
                    TARGETING::ATTR_MEM_AVDD_OFFSET_MILLIVOLTS,
                    TARGETING::ATTR_MEM_AVDD_OFFSET_MILLIVOLTS,
                    TARGETING::ATTR_AVDD_ID>(
                        pMembuf,
                        io_request);

                (void)addMemoryVoltageDomains<
                    TARGETING::ATTR_MSS_CENT_VCS_OFFSET_DISABLE,
                    TARGETING::ATTR_MEM_VCS_OFFSET_MILLIVOLTS,
                    TARGETING::ATTR_MEM_VCS_OFFSET_MILLIVOLTS,
                    TARGETING::ATTR_VCS_ID>(
                        pMembuf,
                        io_request);

                (void)addMemoryVoltageDomains<
                    TARGETING::ATTR_MSS_VOLT_VPP_OFFSET_DISABLE,
                    TARGETING::ATTR_MEM_VPP_OFFSET_MILLIVOLTS,
                    TARGETING::ATTR_VPP_BASE,
                    TARGETING::ATTR_VPP_ID>(
                        pMembuf,
                        io_request);
            }

            (void)addMemoryVoltageDomains<
                TARGETING::ATTR_MSS_VOLT_VDDR_OFFSET_DISABLE,
                TARGETING::ATTR_MEM_VDDR_OFFSET_MILLIVOLTS,
                TARGETING::ATTR_MSS_VOLT,
                TARGETING::ATTR_VMEM_ID>(
                    pMembuf,
                    io_request);
        }

        if (membufTargetList.size() > 1)
        {
            // Take out the duplicate records in io_request by first
            // sorting and then removing the duplicates
            std::sort(io_request.begin(), io_request.end(), compareVids);
            std::vector<hwsvPowrMemVoltDomainRequest_t>::iterator
                pInvalidEntries = std::unique(
                    io_request.begin(),
                    io_request.end(),
                    areVidsEqual);
            io_request.erase(pInvalidEntries,io_request.end());
        }

        if(   (i_requestType == HB_VDDR_ENABLE)
           && (!membufTargetList.empty())      )
        {
            // Inhibit sending any request to turn on a domain with no voltage.
            // When disabling we don't need to do this because the voltage is
            // ignored.
            io_request.erase(
                std::remove_if(io_request.begin(), io_request.end(),
                    isUnusedVoltageDomain),io_request.end());
        }

    } while(0);

    TRACFCOMP( g_trac_volt, EXIT_MRK "HBVddrMsg::createVddrData" );
    return;
}

///////////////////////////////////////////////////////////////////////////////
// HBVddrMsg::sendMsg
///////////////////////////////////////////////////////////////////////////////
errlHndl_t HBVddrMsg::sendMsg(uint32_t i_msgType) const
{
    errlHndl_t l_err = NULL;

    TRACFCOMP(g_trac_volt, ENTER_MRK
              "hbVddrMsg::sendMsg msg_type =0x%08X",i_msgType);

    do
    {
        RequestContainer l_request;

        if ( (i_msgType == HB_VDDR_ENABLE) || (i_msgType == HB_VDDR_DISABLE) )
        {
            VDDR_MSG_TYPE msgType = (i_msgType == HB_VDDR_ENABLE)
                ? HB_VDDR_ENABLE : HB_VDDR_DISABLE;
            createVddrData(msgType, l_request);
        }
        else
        {
            TRACFCOMP(g_trac_volt, ERR_MRK "hbVddrMsg::send msg with non-"
                      "valid msg type%08X",i_msgType);
            /*@
             *   @errortype
             *   @moduleid      fapi::MOD_VDDR_SEND_MSG
             *   @reasoncode    fapi::RC_INCORRECT_MSG_TYPE
             *   @userdata1     i_msgType 
             *   @userdata2     0
             *
             *   @devdesc       HB got an incorrect type message.  HB did not
             *                  provide the correct message type in the istep.
             *                  Userdata1 shows the message type passed in
             */
            createErrLog(l_err, fapi::MOD_VDDR_SEND_MSG,
                         fapi::RC_INCORRECT_MSG_TYPE, i_msgType);
            break;
        }

        size_t l_dataCount = l_request.size();

        // Only send a message if there is data to send
        if (l_dataCount)
        {
            uint32_t l_msgSize = l_dataCount *
                sizeof(hwsvPowrMemVoltDomainRequest_t);

            // Create the message to send to HWSV
            msg_t* l_msg = msg_allocate();
            l_msg->type = i_msgType;
            l_msg->data[0] = 0;
            l_msg->data[1] = l_msgSize;

            TRACFCOMP(g_trac_volt, INFO_MRK "hbVddrMsg::l_dataCount=%d, "
                      "l_msgSize=%d",
                      l_dataCount, l_msgSize);
            void* l_data = malloc(l_msgSize);

            hwsvPowrMemVoltDomainRequest_t* l_ptr =
                reinterpret_cast<hwsvPowrMemVoltDomainRequest_t*>(l_data);

            for (size_t j =0; j<l_dataCount; ++j)
            {
                l_ptr->domain=l_request.at(j).domain;
                l_ptr->domainId=l_request.at(j).domainId;
                l_ptr->voltageMillivolts=l_request.at(j).voltageMillivolts;

                TRACFCOMP(g_trac_volt, ENTER_MRK "hbVddrMsg::sendMsg "
                          "Voltage domain type = 0x%08X, "
                          "Voltage domain ID = 0x%04X, "
                          "Voltage (mV) = %d, index = %d",
                          l_ptr->domain,
                          l_ptr->domainId, l_ptr->voltageMillivolts,j);
                l_ptr++;
            }

            l_msg->extra_data = l_data;

            TRACFBIN(g_trac_volt, "l_data", l_data, l_msgSize);
            l_err = MBOX::sendrecv( MBOX::FSP_VDDR_MSGQ, l_msg );
            if (l_err)
            {
                TRACFCOMP(g_trac_volt,
                          ERR_MRK "Failed sending VDDR message to FSP");
            }
            else
            {
                l_err=processMsg(l_msg);
            }

            // If sendrecv returns error then it may not have freed the
            // extra_data, else need to free the response message extra_data
            free(l_msg->extra_data);
            l_msg->extra_data = NULL;

            msg_free(l_msg);
            l_msg = NULL;
        }
    } while(0);

    TRACFCOMP(g_trac_volt, EXIT_MRK "hbEnableVddr::sendMsg");
    return l_err;
}


///////////////////////////////////////////////////////////////////////////////
// HBVddrMsg::processVDDRmsg
///////////////////////////////////////////////////////////////////////////////
errlHndl_t  HBVddrMsg::processVDDRmsg(msg_t* i_recvMsg) const
{
    TRACFCOMP(g_trac_volt, ENTER_MRK "HBVddrMsg::processVDDRmsg");
    errlHndl_t l_errLog = NULL;
    //check to see if an error occurred from the powr Enable/Disable functions
    //and is inside the message

    uint32_t l_msgSize = i_recvMsg->data[1];
    uint16_t l_elementCount = l_msgSize/sizeof(hwsvPowrMemVoltDomainReply_t);
    const uint8_t* l_extraData = NULL;
    l_extraData=static_cast<uint8_t*>(i_recvMsg->extra_data);

    do{
        if (l_extraData==NULL)
        {
            //an error occred in obtaining the extra data from the response msg 
            TRACFCOMP( g_trac_volt, ERR_MRK
                       "HBVddrMsg::processVDDRmsg: l_extraData = NULL");
            //create an errorlog
            /*@
            *   @errortype
            *   @moduleid      fapi::MOD_VDDR_PROC_VDDR_MSG
            *   @reasoncode    fapi::RC_VDDR_EMPTY_MSG
            *   @userdata1     0
            *   @userdata2     0
            *
            *   @devdesc       The hwsv returned a message where the extra data 
            *                  was null.  This should not happen so need to 
            *                  tell HostBoot to stop the ipl
            */
            createErrLog(l_errLog, fapi::MOD_VDDR_PROC_VDDR_MSG,
                         fapi::RC_VDDR_EMPTY_MSG);
            break;
        }

        MEM_VOLTAGE_DOMAIN domain = MEM_VOLTAGE_DOMAIN_UNKNOWN;
        TARGETING::ATTR_VMEM_ID_type l_domainId =0x0;
        uint32_t l_errPlid =0x0;

        TRACFCOMP( g_trac_volt, INFO_MRK "HBVddrMsg::processVDDRmsg: "
                    "l_elementCount=%d, l_msgSize =%d", 
                    l_elementCount, l_msgSize);
        const hwsvPowrMemVoltDomainReply_t* l_ptr=
            reinterpret_cast<const hwsvPowrMemVoltDomainReply_t*>(l_extraData);

        for (size_t i=0; i<l_elementCount; ++i)
        {
            domain = l_ptr->domain;
            l_domainId = l_ptr->domainId;
            l_errPlid = l_ptr->plid;

            TRACFCOMP( g_trac_volt, INFO_MRK "HBVddrMsg::processVDDRmsg: "
                      "domain = 0x%08X, l_domainId=0x%08X, l_errPlid=0x%08X",
                      domain,l_domainId,l_errPlid);
            if (l_errPlid ==0x0)
            {
                TRACFCOMP( g_trac_volt, INFO_MRK "HBVddrMsg::processVDDRmsg: "
                          "no plid error found for domain = 0x%08X, "
                          "l_domainId=0x%08X", domain, l_domainId);
            }
            else
            {
                //error occured so break out of the loop and indicate
                //an error was present
                TRACFCOMP( g_trac_volt, ERR_MRK
                           "HBVddrMsg::processVDDRmsg: error occured "
                           "on the powr function called in hwsv");
                //create an errorlog
                /*@
                *   @errortype
                *   @moduleid      fapi::MOD_VDDR_PROC_VDDR_MSG
                *   @reasoncode    fapi::RC_VDDR_POWR_ERR
                *   @userdata1     l_errPlid 
                *   @userdata2     0
                *
                *   @devdesc       The hwsv returned a message where there was
                *                  an error when the powr function was called.
                *                  userdata1 contains the errorlog plid from
                *                  hwsv generated by the powr function
                */
                createErrLog(l_errLog, fapi::MOD_VDDR_PROC_VDDR_MSG,
                             fapi::RC_VDDR_POWR_ERR, l_errPlid);
                l_errLog->plid(l_errPlid);
                break;
            }

            l_ptr++;
        }   
    }while(0);
    TRACFCOMP(g_trac_volt, EXIT_MRK "HBVddrMsg::processVDDRmsg");
    return l_errLog;    
}

///////////////////////////////////////////////////////////////////////////////
// HBVddrMsg::processMsg
///////////////////////////////////////////////////////////////////////////////
errlHndl_t HBVddrMsg::processMsg(msg_t* i_Msg) const
{
    TRACFCOMP(g_trac_volt, ENTER_MRK "HBVddrMsg::processMsg");
    errlHndl_t l_errLog = NULL;

    do
    {
        //check to see if the data[0] =0 or contains a value.
        //A value of 0 means its a response to a request and a value not equal
        //to zero  means that its an error coming back

        uint16_t l_value1=i_Msg->data[0];
        if (l_value1 ==0)
        {
            //process a response to a request
        
            uint32_t l_msgType =i_Msg->type;
            TRACFCOMP( g_trac_volt, INFO_MRK
                       "HBVddrMsg::processMsg l_msgType=x%08X",l_msgType );
            if ( (l_msgType == HB_VDDR_ENABLE) ||
                 (l_msgType == HB_VDDR_DISABLE) )
            {
                //process a VDDR message    
                l_errLog=processVDDRmsg(i_Msg);
                if (l_errLog)
                {
                    break;
                }   

            }
            else
            {
                TRACFCOMP( g_trac_volt, ERR_MRK
                           "HBVddrMsg::processMsg recv'd a non valid type");
                //generate errorLog;    
                /*@
                 *   @errortype
                 *   @moduleid      fapi::MOD_VDDR_PROC_MSG
                 *   @reasoncode    fapi::RC_INCORRECT_MSG_TYPE
                 *   @userdata1     0
                 *   @userdata2     0
                 *
                 *   @devdesc       HB got an incorrect type message.
                 *                  HWSV did not populate the message correctly
                 *                  or mbox corrupted the message
                 */
                createErrLog(l_errLog, fapi::MOD_VDDR_PROC_MSG,
                             fapi::RC_INCORRECT_MSG_TYPE);
            }
        }
        else
        {
            //an error occurred so should stop the IPL
            TRACFCOMP( g_trac_volt, ERR_MRK
                       "HBVddrMsg::RecvMsgHndlr recv'd an error message" );
            //generate an errorlog
            /*@
             *   @errortype
             *   @moduleid      fapi::MOD_VDDR_PROC_MSG
             *   @reasoncode    fapi::RC_VDDR_ERROR_MSG
             *   @userdata1     error PLID from hwsv 
             *   @userdata2     0
             *
             *   @devdesc       The hwsv found an error while processing the 
             *                  message so it sent an error message back to
             *                  indicate to HostBoot to stop the IPL. 
             *                  Userdata1 will have the error PLID from hwsv's
             *                  errorlog
             */
            createErrLog(l_errLog, fapi::MOD_VDDR_PROC_MSG,
                         fapi::RC_VDDR_ERROR_MSG, i_Msg->data[1]);
            l_errLog->plid(i_Msg->data[1]);
        }

    }while(0);

    TRACFCOMP(g_trac_volt, EXIT_MRK "HBVddrMsg::processMsg");
    return l_errLog;    
}

///////////////////////////////////////////////////////////////////////////////
// HBVddrMsg::createErrLog
///////////////////////////////////////////////////////////////////////////////
void HBVddrMsg::createErrLog(errlHndl_t& io_err,
                             fapi::hwpfModuleId i_mod,
                             fapi::hwpfReasonCode i_rc,
                             uint32_t i_userData1) const
{
    if (io_err == NULL)
    {
        io_err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                i_mod,
                                i_rc,
                                i_userData1,
                                0);

    }   
    return;
}

// External interfaces

errlHndl_t platform_enable_vspd()
{
    // noop on FSP based system
    return NULL;
}

errlHndl_t platform_enable_vddr()
{
    errlHndl_t l_err = NULL;
    if(INITSERVICE::spBaseServicesEnabled())
    {
        HBVddrMsg l_hbVddr;

        l_err = l_hbVddr.sendMsg(HBVddrMsg::HB_VDDR_ENABLE);
        if (l_err)
        {
            TRACFCOMP(g_trac_volt,
                      "ERROR 0x%.8X: call_host_enable_vddr to sendMsg"
                      " returns error",
                      l_err->reasonCode());
        }
        else
        {
            TRACFCOMP( g_trac_volt,
                       "SUCCESS :  host_enable_vddr()" );
        }
    }
    else // simics stand-alone TULETTA
    {
        TRACFCOMP(g_trac_volt,"call_host_enable_vddr"
                "no-op because mbox not available");
    }

    return l_err;
}

errlHndl_t platform_disable_vddr()
{
    errlHndl_t l_err = NULL;
    if(INITSERVICE::spBaseServicesEnabled())
    {
        HBVddrMsg l_hbVddr;

        l_err = l_hbVddr.sendMsg(HBVddrMsg::HB_VDDR_DISABLE);
        if (l_err)
        {
            TRACFCOMP(g_trac_volt,
                      "ERROR 0x%.8X: call_host_disable_vddr to sendMsg"
                      " returns error",
                      l_err->reasonCode());
        }
        else
        {
            TRACFCOMP( g_trac_volt,
                       "SUCCESS :  host_disable_vddr()" );
        }
    }
    else  // simics stand-along TULETTA
    {
        TRACFCOMP(g_trac_volt,"call_host_disable_vddr"
                "no-op because mbox not available");
    }

    return l_err;
}

