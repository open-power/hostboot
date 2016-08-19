/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep13/hbVddrMsg.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
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

#include "hbVddrMsg.H"
#include <initservice/initserviceif.H>
#include <pnor/pnorif.H>
#include "platform_vddr.H"
#include <istepHelperFuncs.H>
#include <targeting/common/target.H>


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
    const ATTRIBUTE_ID MSS_DOMAIN_PROGRAM,
    const ATTRIBUTE_ID VOLTAGE_ATTR_STATIC,
    const ATTRIBUTE_ID VOLTAGE_ATTR_DYNAMIC,
    const ATTRIBUTE_ID VOLTAGE_DOMAIN_ID_ATTR >
void HBVddrMsg::addMemoryVoltageDomains(
    const TARGETING::Target* const     i_pMcbist,
          HBVddrMsg::RequestContainer& io_domains) const
{
    assert(
        (i_pMcbist != NULL),
        "HBVddrMsg::addMemoryVoltageDomains: Code bug!  Caller passed NULL "
        "MCBIST target handle.");

    assert(
        (    (   i_pMcbist->getAttr<TARGETING::ATTR_CLASS>()
              == TARGETING::CLASS_UNIT)
          && (   i_pMcbist->getAttr<TARGETING::ATTR_TYPE>()
              == TARGETING::TYPE_MCBIST)),
        "HBVddrMsg::addMemoryVoltageDomains: Code bug!  Caller passed non-"
        "MCBIST target handle of class = 0x%08X and type of 0x%08X.",
        i_pMcbist->getAttr<TARGETING::ATTR_CLASS>(),
        i_pMcbist->getAttr<TARGETING::ATTR_TYPE>());

    TARGETING::Target* pSysTarget = nullptr;
    TARGETING::targetService().getTopLevelTarget(pSysTarget);

    assert(
        (pSysTarget != nullptr),
        "HBVddrMsg::addMemoryVoltageDomains: Code bug!  System target was "
        "NULL.");

    typename AttributeTraits< MSS_DOMAIN_PROGRAM >::Type
        domainProgram = pSysTarget->getAttr< MSS_DOMAIN_PROGRAM >();


    // Initialized by constructor to invalid defaults
    HBVddrMsg::hwsvPowrMemVoltDomainRequest_t entry;

    switch(VOLTAGE_DOMAIN_ID_ATTR)
    {
        case TARGETING::ATTR_VDDR_ID:
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
    entry.domainId = i_pMcbist->getAttr< VOLTAGE_DOMAIN_ID_ATTR >();

    // There is no reasonable check to validate if a voltage we're
    // reading is valid so it has to be assumed good for the cases below
    if(domainProgram == MSS_PROGRAM_TYPE::STATIC)
    {
        typename
        TARGETING::AttributeTraits< VOLTAGE_ATTR_STATIC >::Type
            voltageMillivolts
                = i_pMcbist->getAttr< VOLTAGE_ATTR_STATIC >();

        entry.voltageMillivolts = static_cast<uint32_t>(voltageMillivolts);
        io_domains.push_back(entry);
    }
    else if(domainProgram == MSS_PROGRAM_TYPE::DYNAMIC)
    {
        typename
        TARGETING::AttributeTraits< VOLTAGE_ATTR_DYNAMIC >::Type
            voltageMillivolts
                = i_pMcbist->getAttr< VOLTAGE_ATTR_DYNAMIC >();

        entry.voltageMillivolts = static_cast<uint32_t>(voltageMillivolts);
        io_domains.push_back(entry);
    }
}

///////////////////////////////////////////////////////////////////////////////
// HBVddrMsg::createVddrData
///////////////////////////////////////////////////////////////////////////////

void HBVddrMsg::createVddrData(
          VDDR_MSG_TYPE     i_requestType,
          RequestContainer& io_request) const
{
    TRACFCOMP( g_trac_volt, ENTER_MRK "HBVddrMsg::createVddrData" );

    // Go through all the mcbist targets and gather their domains, domain
    // specific IDs, and domain specific voltages
    io_request.clear();

    do{

        TARGETING::TargetHandleList l_mcbistTargetList;

        // get all functional MCBIST targets
        getAllChiplets(l_mcbistTargetList, TYPE_MCBIST);

        for (const auto & pMcbist: l_mcbistTargetList)
        {
            if(i_requestType == HB_VDDR_ENABLE)
            {
                (void)addMemoryVoltageDomains<
                    TARGETING::ATTR_MSS_VDD_PROGRAM,
                    TARGETING::ATTR_MSS_VOLT_VDD_MILLIVOLTS,
                    TARGETING::ATTR_MSS_VOLT_VDD_OFFSET_MILLIVOLTS,
                    TARGETING::ATTR_VDD_ID>(
                        pMcbist,
                        io_request);

                (void)addMemoryVoltageDomains<
                    TARGETING::ATTR_MSS_AVDD_PROGRAM,
                    TARGETING::ATTR_MSS_VOLT_AVDD_MILLIVOLTS,
                    TARGETING::ATTR_MSS_VOLT_AVDD_OFFSET_MILLIVOLTS,
                    TARGETING::ATTR_AVDD_ID>(
                        pMcbist,
                        io_request);

                (void)addMemoryVoltageDomains<
                    TARGETING::ATTR_MSS_VCS_PROGRAM,
                    TARGETING::ATTR_MSS_VOLT_VCS_MILLIVOLTS,
                    TARGETING::ATTR_MSS_VOLT_VCS_OFFSET_MILLIVOLTS,
                    TARGETING::ATTR_VCS_ID>(
                        pMcbist,
                        io_request);

                (void)addMemoryVoltageDomains<
                    TARGETING::ATTR_MSS_VPP_PROGRAM,
                    TARGETING::ATTR_MSS_VOLT_VPP_MILLIVOLTS,
                    TARGETING::ATTR_MSS_VOLT_VPP_OFFSET_MILLIVOLTS,
                    TARGETING::ATTR_VPP_ID>(
                        pMcbist,
                        io_request);
            }

            (void)addMemoryVoltageDomains<
                TARGETING::ATTR_MSS_VDDR_PROGRAM,
                TARGETING::ATTR_MSS_VOLT_VDDR_MILLIVOLTS,
                TARGETING::ATTR_MSS_VOLT_VDDR_OFFSET_MILLIVOLTS,
                TARGETING::ATTR_VDDR_ID>(
                    pMcbist,
                    io_request);
        }

        if (l_mcbistTargetList.size() > 1)
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

        if( ( (i_requestType == HB_VDDR_ENABLE) ||
              (i_requestType == HB_VDDR_POST_DRAM_INIT_ENABLE) )
           && (!l_mcbistTargetList.empty())      )
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
errlHndl_t HBVddrMsg::sendMsg(VDDR_MSG_TYPE i_msgType) const
{
    errlHndl_t l_err = NULL;

    TRACFCOMP(g_trac_volt, ENTER_MRK
              "hbVddrMsg::sendMsg msg_type =0x%08X",i_msgType);

    do
    {
        RequestContainer l_request;
        if (TARGETING::is_vpo())
        {
            TRACFCOMP(g_trac_volt,
                "hbVddrMsg::sendMsg skipped because of VPO environment");
            break;
        }

        if ( ! ( (i_msgType == HB_VDDR_ENABLE) ||
                 (i_msgType == HB_VDDR_DISABLE) ||
                 (i_msgType == HB_VDDR_POST_DRAM_INIT_ENABLE) ) )
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
        createVddrData(i_msgType, l_request);

        size_t l_dataCount = l_request.size();

        // Only send a message if there is data to send
        // Skip sending message if VPO
        if ( l_dataCount )
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

            for (size_t j = 0; j<l_dataCount; ++j)
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

//
// calloutMcbistChildDimms : HW callout for the failing DIMMs
//
void calloutMcbistChildDimms( errlHndl_t & io_errl,
                              const TARGETING::Target * i_mcbist)
{
    TRACFCOMP(g_trac_volt, ENTER_MRK "calloutMcbistChildDimms");

    TARGETING::TargetHandleList l_dimmList;

    // Get child dimms
    getChildAffinityTargets( l_dimmList,
                             i_mcbist,
                             CLASS_NA,
                             TYPE_DIMM );

    if( !l_dimmList.empty())
    {
        // iterate over the DIMMs and call them out
        for (const auto & l_dimm : l_dimmList)
        {
            TRACFCOMP( g_trac_volt, INFO_MRK
                    "HBVddrMsg::calloutMcbistChildDimms Target HUID = 0x%08X" ,
                    TARGETING::get_huid(l_dimm) );

            io_errl->addHwCallout( l_dimm,
                    HWAS::SRCI_PRIORITY_LOW,
                    HWAS::NO_DECONFIG,
                    HWAS::GARD_NULL );
        }
    }
    else
    {
        TRACFCOMP(g_trac_volt, "Mcbist [ 0x%08X ] No child DIMMs found!",
                               TARGETING::get_huid(i_mcbist));
    }

    TRACFCOMP(g_trac_volt, EXIT_MRK "calloutMcbistChildDimms");
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
            //an error occurred in obtaining the extra data from the response msg
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
        TARGETING::ATTR_VDDR_ID_type l_domainId =0x0;
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
            if (l_errPlid == 0x0)
            {
                TRACFCOMP( g_trac_volt, INFO_MRK "HBVddrMsg::processVDDRmsg: "
                          "no plid error found for domain = 0x%08X, "
                          "l_domainId=0x%08X", domain, l_domainId);
            }
            else
            {
                //error occurred so break out of the loop and indicate
                //an error was present
                TRACFCOMP( g_trac_volt, ERR_MRK
                           "HBVddrMsg::processVDDRmsg: error occurred "
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

                l_errLog->addProcedureCallout(
                             HWAS::EPUB_PRC_MEMORY_PLUGGING_ERROR,
                             HWAS::SRCI_PRIORITY_MED );

                // Find the MCBIST associated with this Domain ID
                TARGETING::TargetHandleList mcbistTargetList;
                TARGETING::ATTR_VDDR_ID_type  l_attr_domainId = 0x0;

                getAllChiplets(mcbistTargetList, TYPE_MCBIST);

                bool l_domain_found;
                for (const auto & pMcbist: mcbistTargetList)
                {
                    l_domain_found = true;
                    switch(domain)
                    {
                        // Add hw callouts for child DIMMs
                        case MEM_VOLTAGE_DOMAIN_VDDR:
                            l_attr_domainId =
                                pMcbist->getAttr< TARGETING::ATTR_VDDR_ID >();
                            break;
                        case MEM_VOLTAGE_DOMAIN_VCS:
                            l_attr_domainId =
                                   pMcbist->getAttr< TARGETING::ATTR_VCS_ID>();
                            break;
                        case MEM_VOLTAGE_DOMAIN_VPP:
                            l_attr_domainId =
                                    pMcbist->getAttr< TARGETING::ATTR_VPP_ID>();
                            break;
                        case MEM_VOLTAGE_DOMAIN_AVDD:
                            l_attr_domainId =
                                   pMcbist->getAttr< TARGETING::ATTR_AVDD_ID>();
                            break;
                        case MEM_VOLTAGE_DOMAIN_VDD:
                            l_attr_domainId =
                                    pMcbist->getAttr< TARGETING::ATTR_VDD_ID>();
                            break;
                        default:
                            // Mark this Dimm as Not found
                            l_domain_found = false;
                            TRACFCOMP( g_trac_volt, ERR_MRK
                                    "[ ERROR ] unsupported Domain %d", domain );
                            break;
                    }

                    // Add Callout MCBIST dimms
                    if((l_domain_found) && ( l_attr_domainId == l_domainId ))
                    {
                        TRACFCOMP( g_trac_volt, INFO_MRK
                         "HBVddrMsg::processVDDRmsg MCBIST Target HUID = 0x%08X"
                         " matches failing domain 0x%08X and ID = 0x%08X",
                         TARGETING::get_huid(pMcbist), domain, l_domainId );

                        calloutMcbistChildDimms(l_errLog, pMcbist);
                    }
                }

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
                 (l_msgType == HB_VDDR_DISABLE)||
                 (l_msgType == HB_VDDR_POST_DRAM_INIT_ENABLE) )
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
errlHndl_t platform_enable_vddr()
{
    errlHndl_t l_err = NULL;

    TARGETING::Target* pSysTarget = nullptr;
    TARGETING::targetService().getTopLevelTarget(pSysTarget);
    assert(
        (pSysTarget != nullptr),
        "platform_enable_vddr: Code bug!  System target was NULL.");

    // only enable vddr if system supports dynamic voltage and MBOX available
    if((pSysTarget->getAttr< TARGETING::ATTR_SUPPORTS_DYNAMIC_MEM_VOLT >() == 1)
        && (INITSERVICE::spBaseServicesEnabled()))
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
    else // no FSP/mbox services available
    {
        TRACFCOMP(g_trac_volt,"call_host_enable_vddr"
            " no-op because mbox not available or system"
            " does not support dynamic voltages");
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
    else  // no FSP/mbox services available
    {
        TRACFCOMP(g_trac_volt,"call_host_disable_vddr"
                "no-op because mbox not available");
    }

    return l_err;
}

errlHndl_t platform_adjust_vddr_post_dram_init()
{
    errlHndl_t l_err = NULL;
    if(INITSERVICE::spBaseServicesEnabled())
    {
        HBVddrMsg l_hbVddr;

        l_err = l_hbVddr.sendMsg(HBVddrMsg::HB_VDDR_POST_DRAM_INIT_ENABLE);
        if (l_err)
        {
            TRACFCOMP(g_trac_volt,
                      "ERROR 0x%.8X: call_host_adjust_vddr_post_dram_init to "
                      "sendMsg returns error",
                      l_err->reasonCode());
        }
        else
        {
            TRACFCOMP( g_trac_volt,
                       "SUCCESS :  host_adjust_vddr_post_dram_init()" );
        }
    }
    else  // no FSP/mbox services available
    {
        TRACFCOMP(g_trac_volt,"call_host_adjust_vddr_post_dram_init()"
                "no-op because mbox not available");
    }

    return l_err;
}

