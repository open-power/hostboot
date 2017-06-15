/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep18/TodSvcUtil.C $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2017                        */
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
/**
 *  @file TodSvcUtil.C
 *
 *  @brief The file implements methods of common utility across TOD service
 *
 */



//targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/util.H>
#include <attributeenums.H>
#include <errl/errlmanager.H>

#include "TodSvcUtil.H"
#include "TodUtils.H"
#include "TodDrawer.H"
#include "TodTrace.H"
#include "TodAssert.H"
#include <isteps/tod_init_reasoncodes.H>

namespace TOD

{

//Namespace for containing the utility methods
namespace TodSvcUtil{

//******************************************************************************
//calloutTodEndPoint
//******************************************************************************
void calloutTodEndPoint( const TARGETING::Target* const i_pTodEndPoint,
            errlHndl_t& io_errHdl )
{

    /*@
     * @errortype
     * @moduleid     TOD_ENDPOINT_CALLOUT
     * @reasoncode   TOD_MASTER_PATH_ERROR
     * @userdata1    TOD_ENDPOINT_CALLOUT
     * @userdata2    HUID of the TOD end point that is not receiving signal
     * @devdesc      This TOD end point target on processor is not receiving
     *               signal from the OSC.
     * @custdesc     There was a problem in configuring Time Of Day on the Host
     *               processor.
     *
     */

    io_errHdl = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        TOD_ENDPOINT_CALLOUT,
                        TOD_MASTER_PATH_ERROR,
                        EMOD_CALLOUT_TOD_ENDPOINT,
                        GETHUID(i_pTodEndPoint));

    io_errHdl->addHwCallout(
            i_pTodEndPoint,
            HWAS::SRCI_PRIORITY_HIGH,
            HWAS::DECONFIG,
            HWAS::GARD_Fatal);

    //Get the PEER TOD end point on the OSC and callout as low
    io_errHdl->addProcedureCallout(
            HWAS::EPUB_PRC_TOD_CLOCK_ERR,
            HWAS::SRCI_PRIORITY_LOW);

    //Get the PEER TOD end point on the OSC and callout as low
    TARGETING::PredicateCTM  l_todEndPointPred(
            TARGETING::CLASS_UNIT,TARGETING::TYPE_TODCLK);

    TARGETING::PredicatePostfixExpr  l_funcTodEndPointPred;
    TARGETING::PredicateHwas l_hwasFunc;
    l_hwasFunc.functional(true);

    l_funcTodEndPointPred.push(&l_todEndPointPred).
            push(&l_hwasFunc).And();

    TARGETING::TargetHandleList l_todEndPointList;

    TARGETING::getPeerTargets(l_todEndPointList,//output list
            i_pTodEndPoint, //Peer for this TOD end point
            NULL,
            &l_funcTodEndPointPred);//Destination predicate


    if ( l_todEndPointList.size() > 1 )
    {
        TOD_ERR_ASSERT(0, "More than one PEER TOD end point returned"
            " for the target 0x%08X ",
            GETHUID(i_pTodEndPoint));
    }

    if ( !l_todEndPointList.empty())
    {
        io_errHdl->addHwCallout((*l_todEndPointList.begin()),
                HWAS::SRCI_PRIORITY_LOW,
                HWAS::DECONFIG,
                HWAS::GARD_Fatal);

    }

}
//******************************************************************************
//logInvalidTodConfig
//******************************************************************************
void logInvalidTodConfig(
        const uint32_t i_config,
        errlHndl_t& io_errHdl)
{
    /*@
     * @errortype
     * @moduleid     TOD_LOG_INVALID_CONFIG
     * @reasoncode   TOD_INVALID_CONFIG
     * @userdata1    The problematic configuration ( Primary/Secondary)
     * @devdesc      Error: Erroneous TOD configuration
     *               Possible Causes: Programming issue
     *               Resolution: Development team should be contacted.
     * @custdesc     Host failed to boot because there was a problem
     *               configuring Time Of Day on the Host processors
     */
     io_errHdl = new ERRORLOG::ErrlEntry(
                           ERRORLOG::ERRL_SEV_INFORMATIONAL,
                           TOD_LOG_INVALID_CONFIG,
                           TOD_INVALID_CONFIG,
                           i_config);
}

//******************************************************************************
//logUnsupportedOrdinalId
//******************************************************************************
void logUnsupportedOrdinalId(
        const uint32_t i_ordinalId,
        errlHndl_t& io_errHdl)
{
    /*@
     * @errortype
     * @moduleid     TOD_LOG_UNSUPORTED_ORDINALID
     * @reasoncode   TOD_UNSUPORTED_ORDINALID
     * @userdata1    Ordinal Id for which the error is logged
     * @devdesc      Error: The ordinal Id of one of the TOD procs did not fall
     *               in the range 0 <= Ordinal Id < getMaxProcsOnSystem
     *               Possible Causes: TOD logic has not been updated to support
     *               the latest system type where the no. of processor chips is
     *               either equal to or more than getMaxProcsOnSystem
     *               Resolution: Development team should be contacted.
     * @custdesc     Service Processor Firmware encountered an internal error
     */
     io_errHdl = new ERRORLOG::ErrlEntry(
                           ERRORLOG::ERRL_SEV_INFORMATIONAL,
                           TOD_LOG_UNSUPORTED_ORDINALID,
                           TOD_UNSUPORTED_ORDINALID,
                           i_ordinalId);

}

//******************************************************************************
//getMaxProcsOnSystem()
//******************************************************************************
uint32_t getMaxProcsOnSystem()
{
    TOD_ENTER("getMaxProcsOnSystem");
    errlHndl_t l_errHdl = NULL;
    // Get the max attribute values in this structure;
    maxConfigParamsContainer l_maxCfgParams;

    l_errHdl = getMaxConfigParams(l_maxCfgParams);

    uint32_t l_maxProcCount = 0;
    if (!l_errHdl )
    {
        //FIX_ME: need to find out how to populate this variable
        //l_maxProcCount = l_maxCfgParams.max_compute_nodes_per_sys *
        l_maxProcCount =
            l_maxCfgParams.max_procchips_per_node;
        TOD_INF("Maximum procs on system = 0x%08X", l_maxProcCount);
    }
    else
    {
        TOD_ERR("getMaxConfigParams() Failed");
        errlCommit(l_errHdl, TOD_COMP_ID);
    }

    return (l_maxProcCount);
}

//******************************************************************************
//topologyTypeToString
//******************************************************************************

char const * topologyTypeToString ( const p9_tod_setup_tod_sel i_topologyType )
{
    switch ( i_topologyType )
    {
        case TOD_PRIMARY:
            return "Primary Topology";
        case TOD_SECONDARY:
            return "Secondary Topology";
        default:
            TOD_ERR_ASSERT("Unknown Topology Type");
            return "";
    }
}

/******************************************************************************
 * getFuncNodeTargetsOnSystem
 *****************************************************************************/

errlHndl_t getFuncNodeTargetsOnSystem(
               TARGETING::ConstTargetHandle_t i_nodeOrSysTarget,
               TARGETING::TargetHandleList& o_nodeList,
               const bool i_skipFuncCheck){

    TOD_ENTER("Function Node Target On System");

    errlHndl_t l_errHdl = NULL;

    o_nodeList.clear();

    TARGETING::ATTR_CLASS_type l_class = GETCLASS(i_nodeOrSysTarget);
    TARGETING::ATTR_TYPE_type l_type = GETTYPE(i_nodeOrSysTarget);

    do{
        if(NULL == i_nodeOrSysTarget)
        {
            TOD_ERR("NULL target node passed in");
            l_errHdl = new ERRORLOG::ErrlEntry(
                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                           TOD_BUILD_TOD_DRAWERS,
                           TOD_NULL_INPUT_TARGET,
                           0);
            break;
        }

        //Check if the target is node or system
        TARGETING::PredicateCTM l_isNode(TARGETING::CLASS_ENC,
                                         TARGETING::TYPE_NODE);
        TARGETING::PredicateCTM l_isSys(TARGETING::CLASS_SYS,
                                        TARGETING::TYPE_SYS);
        if((false == l_isNode(i_nodeOrSysTarget)) &&
           (false == l_isSys(i_nodeOrSysTarget)))
        {
            TOD_ERR("Target 0x%.8X with class %s, type %s isn't node or sys",
                     GETHUID(i_nodeOrSysTarget),
                     TARGETING::attrToString<TARGETING::ATTR_CLASS>(l_class),
                     TARGETING::attrToString<TARGETING::ATTR_TYPE>(l_type));
            l_errHdl = new ERRORLOG::ErrlEntry(
                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                           TOD_BUILD_TOD_DRAWERS,
                           TOD_INVALID_TARGET,
                           GETHUID(i_nodeOrSysTarget));
            break;
        }

        if(TARGETING::TYPE_SYS == l_type) //sys target
        {
            //Use PredicateIsFunctional to filter only functional nodes
            TARGETING::PredicateIsFunctional l_isFunctional;
            TARGETING::PredicatePostfixExpr l_funcNodeFilter;
            l_funcNodeFilter.
                push(&l_isNode).push(&l_isFunctional).And();

            TARGETING::targetService().getAssociated(
                o_nodeList,
                i_nodeOrSysTarget ,
                TARGETING::TargetService::CHILD,
                TARGETING::TargetService::IMMEDIATE,
                i_skipFuncCheck ?
                    static_cast<TARGETING::PredicateBase*>(&l_isNode) :
                    static_cast<TARGETING::PredicateBase*>(&l_funcNodeFilter));
        }
        else //node target
        {
            if(i_skipFuncCheck ||
               (isFunctional(i_nodeOrSysTarget)))
            {
                o_nodeList.push_back(
                    const_cast<TARGETING::TargetHandle_t>(i_nodeOrSysTarget));
            }
        }
    }while(0);

    return l_errHdl;
}


}//End of namespace TodSvcUtil

}//End  of namespace TOD
