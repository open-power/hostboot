/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/hbToHwsvVoltageMsg.C $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
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
#include <initservice/initserviceif.H>
#include <pnor/pnorif.H>
#include <targeting/common/target.H>
#include "hbToHwsvVoltageMsg.H"
#include "istepHelperFuncs.H"


using namespace ERRORLOG;

using namespace TARGETING;

// Trace definition
trace_desc_t* g_trac_volt = nullptr;
TRAC_INIT(&g_trac_volt, "HB_VOLT", 1024);

///////////////////////////////////////////////////////////////////////////////
// HBToHwsvVoltageMsg::HBToHwsvVoltageMsg()
///////////////////////////////////////////////////////////////////////////////
HBToHwsvVoltageMsg::HBToHwsvVoltageMsg()
{
    TRACDCOMP( g_trac_volt, ENTER_MRK "HBToHwsvVoltageMsg::HBToHwsvVoltageMsg()" );
    TRACDCOMP( g_trac_volt, EXIT_MRK "HBToHwsvVoltageMsg::HBToHwsvVoltageMsg()" );
};

///////////////////////////////////////////////////////////////////////////////
// HBToHwsvVoltageMsg::~HBToHwsvVoltageMsg()
///////////////////////////////////////////////////////////////////////////////
HBToHwsvVoltageMsg::~HBToHwsvVoltageMsg()
{
    TRACDCOMP( g_trac_volt, ENTER_MRK "HBToHwsvVoltageMsg::~HBToHwsvVoltageMsg()" );
    TRACDCOMP( g_trac_volt, EXIT_MRK "HBToHwsvVoltageMsg::~HBToHwsvVoltageMsg()" );
};


///////////////////////////////////////////////////////////////////////////////
// compareVids
///////////////////////////////////////////////////////////////////////////////

bool compareVids(
    HBToHwsvVoltageMsg::hwsvPowrMemVoltDomainRequest_t& i_lhs,
    HBToHwsvVoltageMsg::hwsvPowrMemVoltDomainRequest_t& i_rhs)
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
// compareSequenceOrder
///////////////////////////////////////////////////////////////////////////////
bool compareSequenceOrder(
    HBToHwsvVoltageMsg::hwsvPowrMemVoltDomainRequest_t& i_lhs,
    HBToHwsvVoltageMsg::hwsvPowrMemVoltDomainRequest_t& i_rhs)
{
    // Sequencing order is VDN->VDD->VCS
    // true means lhs should be ordered before rhs
    //
    // if both values are the same, preserve order: true
    // if lhs is VDN, we know it goes first, order stays the same: true
    // if rhs is VCS, we know it goes last, order stays the same: true
    // else, lhs needs to be swapped with rhs
    return ( (i_lhs.domainId == i_rhs.domainId) ||
             (i_lhs.domainId == HBToHwsvVoltageMsg::VOLTAGE_DOMAIN_NEST_VDN) ||
             (i_rhs.domainId == HBToHwsvVoltageMsg::VOLTAGE_DOMAIN_NEST_VCS) );

}


///////////////////////////////////////////////////////////////////////////////
// areVidsEqual
///////////////////////////////////////////////////////////////////////////////

bool areVidsEqual(
    HBToHwsvVoltageMsg::hwsvPowrMemVoltDomainRequest_t& i_lhs,
    HBToHwsvVoltageMsg::hwsvPowrMemVoltDomainRequest_t& i_rhs)
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
    HBToHwsvVoltageMsg::hwsvPowrMemVoltDomainRequest_t& i_vid)
{
    return (!i_vid.voltageMillivolts);
}




///////////////////////////////////////////////////////////////////////////////
// removeExtraRequests
///////////////////////////////////////////////////////////////////////////////
void removeExtraRequests( HBToHwsvVoltageMsg::RequestContainer & io_requests,
                          HBToHwsvVoltageMsg::VOLT_MSG_TYPE i_requestType,
                          size_t i_targetListSize )
{
    if( i_targetListSize > 1 )
    {
        // Take out the duplicate records in io_requests by first
        // sorting and then removing the duplicates
        std::sort(io_requests.begin(), io_requests.end(), compareVids);
        std::vector<HBToHwsvVoltageMsg::hwsvPowrMemVoltDomainRequest_t>::iterator
            pInvalidEntries = std:: unique(
                    io_requests.begin(),
                    io_requests.end(),
                    areVidsEqual);
        io_requests.erase(pInvalidEntries, io_requests.end());
    }


    if( ( (i_requestType == HBToHwsvVoltageMsg::HB_VOLT_ENABLE) ||
              (i_requestType == HBToHwsvVoltageMsg::HB_VOLT_POST_DRAM_INIT_ENABLE) )
           && (i_targetListSize > 1 ) )
    {
            // Inhibit sending any request to turn on a domain with no voltage.
            // When disabling we don't need to do this because the voltage is
            // ignored.
            io_requests.erase(
                std::remove_if(io_requests.begin(), io_requests.end(),
                    isUnusedVoltageDomain),io_requests.end());
    }

}


//******************************************************************************
// addMemoryVoltageDomains (templated)
//******************************************************************************

template<
    const ATTRIBUTE_ID MSS_DOMAIN_PROGRAM,
    const ATTRIBUTE_ID VOLTAGE_ATTR_STATIC,
    const ATTRIBUTE_ID VOLTAGE_ATTR_DYNAMIC,
    const ATTRIBUTE_ID VOLTAGE_DOMAIN_ID_ATTR >
void HBToHwsvVoltageMsg::addMemoryVoltageDomains(
    const TARGETING::Target* const     i_pTarget,
          HBToHwsvVoltageMsg::RequestContainer& io_domains) const
{
    assert(
        (i_pTarget != nullptr),
        "HBToHwsvVoltageMsg::addMemoryVoltageDomains: Code bug!  Caller passed NULL "
        "target handle.");

    assert(
           ( ( i_pTarget->getAttr<TARGETING::ATTR_TYPE>()
              == TARGETING::TYPE_MCBIST) ||
             (   i_pTarget->getAttr<TARGETING::ATTR_TYPE>()
              == TARGETING::TYPE_MEMBUF)),
        "HBToHwsvVoltageMsg::addMemoryVoltageDomains: Code bug!  Caller passed non-"
        "MCBIST or MEMBUF target handle of class = 0x%08X and type of 0x%08X.",
        i_pTarget->getAttr<TARGETING::ATTR_CLASS>(),
        i_pTarget->getAttr<TARGETING::ATTR_TYPE>());

    TARGETING::Target* pSysTarget = nullptr;
    TARGETING::targetService().getTopLevelTarget(pSysTarget);

    assert(
        (pSysTarget != nullptr),
        "HBToHwsvVoltageMsg::addMemoryVoltageDomains: Code bug!  System target was "
        "NULL.");

    typename AttributeTraits< MSS_DOMAIN_PROGRAM >::Type
        domainProgram = pSysTarget->getAttr< MSS_DOMAIN_PROGRAM >();


    // Initialized by constructor to invalid defaults
    HBToHwsvVoltageMsg::hwsvPowrMemVoltDomainRequest_t entry;

    switch(VOLTAGE_DOMAIN_ID_ATTR)
    {
        case TARGETING::ATTR_VDDR_ID:
            entry.domain = VOLTAGE_DOMAIN_MEM_VDDR;
            break;
        case TARGETING::ATTR_VCS_ID:
            entry.domain = VOLTAGE_DOMAIN_MEM_VCS;
            break;
        case TARGETING::ATTR_VPP_ID:
            entry.domain = VOLTAGE_DOMAIN_MEM_VPP;
            break;
        case TARGETING::ATTR_AVDD_ID:
            entry.domain = VOLTAGE_DOMAIN_MEM_AVDD;
            break;
        case TARGETING::ATTR_VDD_ID:
            entry.domain = VOLTAGE_DOMAIN_MEM_VDD;
            break;
        default:
            assert(
                0,
                "HBToHwsvVoltageMsg::addMemoryVoltageDomains: Code Bug!  Unsupported "
                "voltage domain of 0x%08X.",
                VOLTAGE_DOMAIN_ID_ATTR);
            break;
    }

    // There is no reasonable check to validate if a voltage ID we're reading
    // is valid so it has to be assumed good
    entry.domainId = i_pTarget->getAttr< VOLTAGE_DOMAIN_ID_ATTR >();

    // There is no reasonable check to validate if a voltage we're
    // reading is valid so it has to be assumed good for the cases below
    if(domainProgram == MSS_PROGRAM_TYPE::STATIC_TYPE)
    {
        typename
        TARGETING::AttributeTraits< VOLTAGE_ATTR_STATIC >::Type
            voltageMillivolts
                = i_pTarget->getAttr< VOLTAGE_ATTR_STATIC >();

        entry.voltageMillivolts = static_cast<uint32_t>(voltageMillivolts);
        io_domains.push_back(entry);
    }
    else if(domainProgram == MSS_PROGRAM_TYPE::DYNAMIC_TYPE)
    {
        typename
        TARGETING::AttributeTraits< VOLTAGE_ATTR_DYNAMIC >::Type
            voltageMillivolts
                = i_pTarget->getAttr< VOLTAGE_ATTR_DYNAMIC >();

        entry.voltageMillivolts = static_cast<uint32_t>(voltageMillivolts);
        io_domains.push_back(entry);
    }
    else if(domainProgram == MSS_PROGRAM_TYPE::DEFAULT_TYPE)
    {
        entry.voltageMillivolts =
            HBToHwsvVoltageMsg::VOLTAGE_SETTING_ALERT_DEFAULT;
        io_domains.push_back(entry);
    }
}

///////////////////////////////////////////////////////////////////////////////
// HBToHwsvVoltageMsg::createVddrData
///////////////////////////////////////////////////////////////////////////////

void HBToHwsvVoltageMsg::createVddrData(
          VOLT_MSG_TYPE     i_requestType,
          RequestContainer& io_request) const
{
    TRACFCOMP( g_trac_volt, ENTER_MRK "HBToHwsvVoltageMsg::createVddrData" );

    // Go through all the mcbist targets and gather their domains, domain
    // specific IDs, and domain specific voltages
    io_request.clear();

    do{

        TARGETING::TargetHandleList l_mcbistTargetList;

        // get all functional MCBIST targets
        getAllChiplets(l_mcbistTargetList, TYPE_MCBIST);

        for (const auto & pMcbist: l_mcbistTargetList)
        {
            if(i_requestType == HB_VOLT_ENABLE)
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

        // Remove duplicate records and requests containing invalid voltages
        removeExtraRequests( io_request,
                             i_requestType,
                             l_mcbistTargetList.size());

    } while(0);

    TRACFCOMP( g_trac_volt, EXIT_MRK "HBToHwsvVoltageMsg::createVddrData" );
    return;
}


///////////////////////////////////////////////////////////////////////////////
// HBToHwsvVoltageMsg::sendRequestData
///////////////////////////////////////////////////////////////////////////////
errlHndl_t HBToHwsvVoltageMsg::sendRequestData( RequestContainer & i_requests,
                                       VOLT_MSG_TYPE i_msgType ) const
{

    errlHndl_t l_err = nullptr;

    do
    {
        size_t l_numRequests = i_requests.size();
        TRACDCOMP(g_trac_volt,
                "sendRequestData::l_numRequests = %d",
                l_numRequests);


        // Skip sending message if VPO
        if( TARGETING::is_vpo())
        {
            TRACFCOMP( g_trac_volt,
                    "hbToHwsvVoltageMsg::sendRequestData skipped because of"
                   "  VPO environment!" );
            break;
        }


        // Only send a message if there is data to send
        if( l_numRequests )
        {
            uint32_t l_msgSize = l_numRequests *
                    sizeof(hwsvPowrMemVoltDomainRequest_t);

            // Create the message to send to HWSV
            msg_t * l_msg = msg_allocate();
            l_msg->type = i_msgType;
            l_msg->data[0] = 0;
            l_msg->data[1] = l_msgSize;

            TRACDCOMP(g_trac_volt, INFO_MRK "hbToHwsvVoltageMsg::l_numRequests=%d, "
                      "l_msgSize=%d",
                      l_numRequests, l_msgSize);
            void* l_data = malloc(l_msgSize);

            hwsvPowrMemVoltDomainRequest_t* l_ptr =
                reinterpret_cast<hwsvPowrMemVoltDomainRequest_t*>(l_data);

            for (size_t j = 0; j<l_numRequests; ++j)
            {
                l_ptr->domain            = i_requests.at(j).domain;
                l_ptr->domainId          = i_requests.at(j).domainId;
                l_ptr->voltageMillivolts = i_requests.at(j).voltageMillivolts;

                TRACFCOMP(g_trac_volt, ENTER_MRK "hbToHwsvVoltageMsg::sendRequestData "
                          "Voltage domain type = 0x%08X, "
                          "Voltage domain ID = 0x%04X, "
                          "Voltage (mV) = %d, index = %d",
                          l_ptr->domain,
                          l_ptr->domainId,
                          l_ptr->voltageMillivolts,
                          j);
                l_ptr++;
            }

            l_msg->extra_data = l_data;

            TRACFBIN(g_trac_volt, "l_data", l_data, l_msgSize);
            l_err = MBOX::sendrecv( MBOX::FSP_VDDR_MSGQ, l_msg );
            if (l_err)
            {
                TRACFCOMP(g_trac_volt,
                          ERR_MRK "Failed sending voltage message to FSP");
            }
            else
            {
                l_err = processMsg(l_msg);
            }

            // If there is still data in l_msg->extra_data
            if( l_msg->extra_data )
            {
                free(l_msg->extra_data);
                l_msg->extra_data = nullptr;

                msg_free(l_msg);
                l_msg = nullptr;
            }
        }
    } while( 0 );

    return l_err;
}


///////////////////////////////////////////////////////////////////////////////
// HBToHwsvVoltageMsg::sendMsg
///////////////////////////////////////////////////////////////////////////////
errlHndl_t HBToHwsvVoltageMsg::sendMsg(VOLT_MSG_TYPE i_msgType) const
{
    errlHndl_t l_err = nullptr;

    TRACFCOMP(g_trac_volt, ENTER_MRK
              "hbToHwsvVoltageMsg::sendMsg msg_type =0x%08X",i_msgType);

    do
    {
        RequestContainer l_request;

        if ( ! ( (i_msgType == HB_VOLT_ENABLE) ||
                 (i_msgType == HB_VOLT_DISABLE) ||
                 (i_msgType == HB_VOLT_POST_DRAM_INIT_ENABLE) ) )
        {
            TRACFCOMP(g_trac_volt, ERR_MRK "hbToHwsvVoltageMsg::send msg with non-"
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
             *   @custdesc      An internal firmware error occurred
             */
            createErrLog(l_err, fapi::MOD_VDDR_SEND_MSG,
                         fapi::RC_INCORRECT_MSG_TYPE, i_msgType);
            break;
        }

        // Make a default voltage settings request
        hwsvPowrMemVoltDomainRequest_t l_defaultReq;
        l_defaultReq.voltageMillivolts = VOLTAGE_SETTING_ALERT_DEFAULT;
        // We need to specify a valid domain even though it won't be used
        // in this case.
        l_defaultReq.domain = VOLTAGE_DOMAIN_MEM_VDD;
        l_request.push_back(l_defaultReq);

        // Send the request data
        l_err = sendRequestData( l_request, i_msgType );

        if( l_err )
        {
            TRACFCOMP( g_trac_volt, "hbToHwsvVoltageMsg::sendMsg"
                    "An error occurred when sending request data" );
            break;
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
                    "HBToHwsvVoltageMsg::calloutMcbistChildDimms Target HUID = 0x%08X" ,
                    TARGETING::get_huid(l_dimm) );

            io_errl->addHwCallout( l_dimm,
                    HWAS::SRCI_PRIORITY_LOW,
                    HWAS::DELAYED_DECONFIG,
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
// HBToHwsvVoltageMsg::processVOLTmsg
///////////////////////////////////////////////////////////////////////////////
errlHndl_t  HBToHwsvVoltageMsg::processVOLTmsg(msg_t* i_recvMsg) const
{
    TRACFCOMP(g_trac_volt, ENTER_MRK "HBToHwsvVoltageMsg::processVOLTmsg");
    errlHndl_t l_errLog = nullptr;

    //check to see if an error occurred from the powr Enable/Disable functions
    //and is inside the message
    uint32_t l_msgSize = i_recvMsg->data[1];
    uint16_t l_elementCount = l_msgSize/sizeof(hwsvPowrMemVoltDomainReply_t);
    const uint8_t* l_extraData = nullptr;
    l_extraData=static_cast<uint8_t*>(i_recvMsg->extra_data);

    do{
        if (l_extraData==nullptr)
        {
            //an error occurred in obtaining the extra data from the response msg
            TRACFCOMP( g_trac_volt, ERR_MRK
                       "HBToHwsvVoltageMsg::processVOLTmsg: l_extraData = NULL");
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
            *   @custdesc      An internal firmware error occurred
            */
            createErrLog(l_errLog, fapi::MOD_VDDR_PROC_VDDR_MSG,
                         fapi::RC_VDDR_EMPTY_MSG);
            break;
        }

        VOLTAGE_DOMAIN domain = VOLTAGE_DOMAIN_UNKNOWN;
        TARGETING::ATTR_VDDR_ID_type l_domainId =0x0;
        uint32_t l_errPlid =0x0;

        TRACFCOMP( g_trac_volt, INFO_MRK "HBToHwsvVoltageMsg::processVOLTmsg: "
                    "l_elementCount=%d, l_msgSize =%d",
                    l_elementCount, l_msgSize);
        const hwsvPowrMemVoltDomainReply_t* l_ptr=
            reinterpret_cast<const hwsvPowrMemVoltDomainReply_t*>(l_extraData);

        for (size_t i=0; i<l_elementCount; ++i)
        {
            domain = l_ptr->domain;
            l_domainId = l_ptr->domainId;
            l_errPlid = l_ptr->plid;

            TRACFCOMP( g_trac_volt, INFO_MRK "HBToHwsvVoltageMsg::processVOLTmsg: "
                      "domain = 0x%08X, l_domainId=0x%08X, l_errPlid=0x%08X",
                      domain,l_domainId,l_errPlid);
            if (l_errPlid == 0x0)
            {
                TRACFCOMP( g_trac_volt, INFO_MRK "HBToHwsvVoltageMsg::processVOLTmsg: "
                          "no plid error found for domain = 0x%08X, "
                          "l_domainId=0x%08X", domain, l_domainId);
            }
            else
            {
                //error occurred so break out of the loop and indicate
                //an error was present
                TRACFCOMP( g_trac_volt, ERR_MRK
                           "HBToHwsvVoltageMsg::processVOLTmsg: error occurred "
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
                *   @custdesc      An internal firmware error occurred
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
                        case VOLTAGE_DOMAIN_MEM_VDDR:
                            l_attr_domainId =
                                pMcbist->getAttr< TARGETING::ATTR_VDDR_ID >();
                            break;
                        case VOLTAGE_DOMAIN_MEM_VCS:
                            l_attr_domainId =
                                   pMcbist->getAttr< TARGETING::ATTR_VCS_ID>();
                            break;
                        case VOLTAGE_DOMAIN_MEM_VPP:
                            l_attr_domainId =
                                    pMcbist->getAttr< TARGETING::ATTR_VPP_ID>();
                            break;
                        case VOLTAGE_DOMAIN_MEM_AVDD:
                            l_attr_domainId =
                                   pMcbist->getAttr< TARGETING::ATTR_AVDD_ID>();
                            break;
                        case VOLTAGE_DOMAIN_MEM_VDD:
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
                         "HBToHwsvVoltageMsg::processVOLTmsg MCBIST Target HUID = 0x%08X"
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
    TRACFCOMP(g_trac_volt, EXIT_MRK "HBToHwsvVoltageMsg::processVOLTmsg");
    return l_errLog;
}

///////////////////////////////////////////////////////////////////////////////
// HBToHwsvVoltageMsg::processMsg
///////////////////////////////////////////////////////////////////////////////
errlHndl_t HBToHwsvVoltageMsg::processMsg(msg_t* i_Msg) const
{
    TRACFCOMP(g_trac_volt, ENTER_MRK "HBToHwsvVoltageMsg::processMsg");
    errlHndl_t l_errLog = nullptr;

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
                       "HBToHwsvVoltageMsg::processMsg l_msgType=x%08X",l_msgType );
            if ( (l_msgType == HB_VOLT_ENABLE) ||
                 (l_msgType == HB_VOLT_DISABLE)||
                 (l_msgType == HB_VOLT_POST_DRAM_INIT_ENABLE) )
            {
                //process a voltage message
                l_errLog=processVOLTmsg(i_Msg);
                if (l_errLog)
                {
                    break;
                }
            }
            else
            {
                TRACFCOMP( g_trac_volt, ERR_MRK
                           "HBToHwsvVoltageMsg::processMsg recv'd a non valid type");
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
                 *   @custdesc      An internal firmware error occurred
                 */
                createErrLog(l_errLog, fapi::MOD_VDDR_PROC_MSG,
                             fapi::RC_INCORRECT_MSG_TYPE);
            }
        }
        else
        {
            //an error occurred so should stop the IPL
            TRACFCOMP( g_trac_volt, ERR_MRK
                       "HBToHwsvVoltageMsg::RecvMsgHndlr recv'd an error message" );

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
             *   @custdesc      An internal firmware error occurred
             */
            createErrLog(l_errLog, fapi::MOD_VDDR_PROC_MSG,
                         fapi::RC_VDDR_ERROR_MSG, i_Msg->data[1]);
            l_errLog->plid(i_Msg->data[1]);
        }

    }while(0);

    TRACFCOMP(g_trac_volt, EXIT_MRK "HBToHwsvVoltageMsg::processMsg");
    return l_errLog;
}

///////////////////////////////////////////////////////////////////////////////
// HBToHwsvVoltageMsg::createErrLog
///////////////////////////////////////////////////////////////////////////////
void HBToHwsvVoltageMsg::createErrLog(errlHndl_t& io_err,
                             fapi::hwpfModuleId i_mod,
                             fapi::hwpfReasonCode i_rc,
                             uint32_t i_userData1) const
{
    if (io_err == nullptr)
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
////////////////////////////////////////////////////////////////////////////////
// platform_enable_vddr
////////////////////////////////////////////////////////////////////////////////
errlHndl_t platform_enable_vddr()
{
    errlHndl_t l_err = nullptr;

    // only enable vddr on FSP systems
    if(INITSERVICE::spBaseServicesEnabled())
    {
        HBToHwsvVoltageMsg l_hbVddr;

        l_err = l_hbVddr.sendMsg(HBToHwsvVoltageMsg::HB_VOLT_ENABLE);
        if (l_err)
        {
            TRACFCOMP(g_trac_volt,
                      "ERROR 0x%.8X: call_host_enable_vddr to sendMsg returns error",
                      l_err->reasonCode());
        }
        else
        {
            TRACFCOMP(g_trac_volt, "SUCCESS :  host_enable_vddr()");
        }
    }
    else // no FSP/mbox services available
    {
        TRACFCOMP(g_trac_volt,
                  "call_host_enable_vddr no-op because mbox is not available");
    }

    return l_err;
}


////////////////////////////////////////////////////////////////////////////////
// platform_disable_vddr
////////////////////////////////////////////////////////////////////////////////
errlHndl_t platform_disable_vddr()
{
    errlHndl_t l_err = nullptr;
    if(INITSERVICE::spBaseServicesEnabled())
    {
        HBToHwsvVoltageMsg l_hbToHwsv;

        l_err = l_hbToHwsv.sendMsg(HBToHwsvVoltageMsg::HB_VOLT_DISABLE);
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


////////////////////////////////////////////////////////////////////////////////
// platform_adjust_vddr_post_dram_init
////////////////////////////////////////////////////////////////////////////////
errlHndl_t platform_adjust_vddr_post_dram_init()
{
    errlHndl_t l_err = nullptr;
    if(INITSERVICE::spBaseServicesEnabled())
    {
        HBToHwsvVoltageMsg l_hbVddr;

        l_err = l_hbVddr.sendMsg(HBToHwsvVoltageMsg::HB_VOLT_POST_DRAM_INIT_ENABLE);
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

////////////////////////////////////////////////////////////////////////////////
// platform_set_nest_voltages
////////////////////////////////////////////////////////////////////////////////
#if 0 // TODO: RTC 256665 Currently causes compile issues. Uncomment if this is
      // needed in the future.
errlHndl_t platform_set_nest_voltages()
{
    TRACFCOMP(g_trac_volt, "platform_set_nest_voltages>" );
    errlHndl_t l_err = nullptr;

    TARGETING::TargetHandleList l_procList;

    HBToHwsvVoltageMsg::RequestContainer l_requests;

    HBToHwsvVoltageMsg::VOLT_MSG_TYPE l_requestType =
                              HBToHwsvVoltageMsg::HB_VOLT_POST_DRAM_INIT_ENABLE;

    // Get the system's processors
    TARGETING::getAllChips( l_procList,
                            TARGETING::TYPE_PROC,
                            true ); // true: return functional procs

    for( const auto & l_procTarget : l_procList )
    {

        // Only send Voltage Rail data if not connected by AVSBus
        //    -Denoted with a value of 0xFF in the Busnum for the rail

        // VDN Rail
        if( l_procTarget->getAttr<TARGETING::ATTR_VDN_AVSBUS_BUSNUM>() == 0xff )
        {
            HBToHwsvVoltageMsg::hwsvPowrMemVoltDomainRequest_t l_vdnRequest;

            // Populate VDN request
            l_vdnRequest.domain = HBToHwsvVoltageMsg::VOLTAGE_DOMAIN_NEST_VDN;
            l_vdnRequest.domainId = l_procTarget->getAttr<TARGETING::ATTR_NEST_VDN_ID>();
            l_vdnRequest.voltageMillivolts =
                            l_procTarget->getAttr<TARGETING::ATTR_VDN_BOOT_VOLTAGE>();
            l_requests.push_back( l_vdnRequest );
        }

        // VDD Rail
        if( l_procTarget->getAttr<TARGETING::ATTR_VDD_AVSBUS_BUSNUM>() == 0xff)
        {
            // Create VRD Requests
            HBToHwsvVoltageMsg::hwsvPowrMemVoltDomainRequest_t l_vddRequest;

            // Populate VDD request
            l_vddRequest.domain = HBToHwsvVoltageMsg::VOLTAGE_DOMAIN_NEST_VDD;
            l_vddRequest.domainId = l_procTarget->getAttr<TARGETING::ATTR_NEST_VDD_ID>();
            l_vddRequest.voltageMillivolts =
                         l_procTarget->getAttr<TARGETING::ATTR_VDD_BOOT_VOLTAGE>();
            l_requests.push_back( l_vddRequest );
        }


        // VCS Rail
        if( l_procTarget->getAttr<TARGETING::ATTR_VCS_AVSBUS_BUSNUM>() == 0xff )
        {
            HBToHwsvVoltageMsg::hwsvPowrMemVoltDomainRequest_t l_vcsRequest;
            // Populate VCS request
            l_vcsRequest.domain = HBToHwsvVoltageMsg::VOLTAGE_DOMAIN_NEST_VCS;
            l_vcsRequest.domainId = l_procTarget->getAttr<TARGETING::ATTR_NEST_VCS_ID>();
            l_vcsRequest.voltageMillivolts =
                            l_procTarget->getAttr<TARGETING::ATTR_VCS_BOOT_VOLTAGE>();
            l_requests.push_back( l_vcsRequest );
        }

    } // Processor Loop

    TRACFCOMP(g_trac_volt,
              "%d requests before removing dupes", l_requests.size());

    //Remove duplicate records and requests with invalid voltages
    removeExtraRequests( l_requests,
                         l_requestType,
                         l_procList.size() );
    TRACFCOMP(g_trac_volt,
            "platform_set_nest_voltages - Sending %d requests", l_requests.size());


    // Sort the list based on sequencing order
    std::sort(l_requests.begin(), l_requests.end(), compareSequenceOrder );

    size_t l_requestsSize = l_requests.size();
    for( size_t i = 0; i < l_requestsSize ; i++ )
    {
        TRACFCOMP(g_trac_volt,
                  "Rail data: domain = 0x%x, domainId = %d, mV = %d",
                  l_requests.at(i).domain,
                  l_requests.at(i).domainId,
                  l_requests.at(i).voltageMillivolts );
    }
    //Send the actual data to HWSV
    HBToHwsvVoltageMsg l_hbToHwsv;
    l_err = l_hbToHwsv.sendRequestData(l_requests,
                                     HBToHwsvVoltageMsg::HB_VOLT_POST_DRAM_INIT_ENABLE );

    if( l_err )
    {
        TRACFCOMP(g_trac_volt,
                ERR_MRK"hbToHwsvVoltageMsg.C::platform_set_nest_voltages - "
                "Failed to send the Request Data to HWSV!" );
    }


    TRACFCOMP(g_trac_volt, "<platform_set_nest_voltages" );
    return l_err;
}
#endif
