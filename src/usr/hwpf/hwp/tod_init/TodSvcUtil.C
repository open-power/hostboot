/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/tod_init/TodSvcUtil.C $                      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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

/**
 *  @file TodSvcUtil.C
 *
 *  @brief This file implements the various utility methods
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

#include <targeting/common/attributes.H>
#include <targeting/common/targetservice.H>
#include <tod_init/tod_init_reasoncodes.H>
#include <devicefw/userif.H>

#include "TodTrace.H"
#include "TodSvcUtil.H"

using namespace TARGETING;

namespace TOD {

//******************************************************************************
//logInvalidTodConfig
//******************************************************************************
void logInvalidTodConfig(
        const uint32_t i_config,
        errlHndl_t& io_errHdl)
{
    /*@
     * @errortype
     * @reasoncode   TOD_INVALID_CONFIG
     * @moduleid     TOD_LOG_INVALID_CONFIG
     * @userdata1    The problematic configuration (Primary/Secondary)
     * @devdesc      Error: Erroneous TOD configuration
     *               Possible Causes: Programming issue
     *               Resolution: Development team should be contacted.
     */
     io_errHdl = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        TOD_LOG_INVALID_CONFIG,
                        TOD_INVALID_CONFIG,
                        i_config, 0);
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
     * @reasoncode   TOD_UNSUPORTED_ORDINALID
     * @moduleid     TOD_LOG_UNSUPORTED_ORDINALID
     * @userdata1    Ordinal Id for which the error is logged
     * @devdesc      Error: The ordinal Id of one of the TOD procs did not fall
     *               in the range 0 <= Ordinal Id < getMaxProcsOnSystem
     *               Possible Causes: TOD logic has not been updated to support
     *               the latest system type where the no. of processor chips is
     *               either equal to or more than getMaxProcsOnSystem
     *               Resolution: Development team should be contacted.
     */
     io_errHdl = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        TOD_LOG_UNSUPORTED_ORDINALID,
                        TOD_UNSUPORTED_ORDINALID,
                        i_ordinalId, 0 );
}

//******************************************************************************
//getMaxProcsOnSystem()
//******************************************************************************
uint32_t getMaxProcsOnSystem()
{
    Target* sys = NULL;
    targetService().getTopLevelTarget(sys);

    uint8_t l_maxProcs = 0;
    sys->tryGetAttr<ATTR_MAX_PROC_CHIPS_PER_NODE>(l_maxProcs);

    return ( (uint32_t)l_maxProcs );
}

//******************************************************************************
//getMaxPossibleCoresPerProc()
//******************************************************************************
uint32_t  getMaxPossibleCoresPerProc()
{
    Target* sys = NULL;
    targetService().getTopLevelTarget(sys);

    uint8_t l_maxCores = 0;
    sys->tryGetAttr<ATTR_MAX_EXS_PER_PROC_CHIP>(l_maxCores);

    return ( (uint32_t)l_maxCores );
}

//******************************************************************************
//todGetScom()
//******************************************************************************
errlHndl_t todGetScom(const TARGETING::Target * i_target,
                      const uint64_t i_address,
                      ecmdDataBufferBase & o_data)
{
    uint32_t l_ecmdRc;
    errlHndl_t l_err = NULL;

    // Perform SCOM read
    uint64_t l_data = 0;
    size_t l_size = sizeof(uint64_t);

    l_err = deviceRead((TARGETING::Target *)i_target,
                       &l_data,
                       l_size,
                       DEVICE_SCOM_ADDRESS(i_address));

    if (!l_err)
    {
        l_ecmdRc  = o_data.setBitLength(64);
        l_ecmdRc |= o_data.setDoubleWord(0, l_data);
        if (l_ecmdRc)
        {
            /*@
             * @errortype
             * @reasoncode   TOD_ECMD_ERROR
             * @moduleid     TOD_GETSCOM
             * @userdata1    return code from ecmdDataBufferBase operation(s)
             * @devdesc      Scom access error
             */
           l_err = new ERRORLOG::ErrlEntry(
                           ERRORLOG::ERRL_SEV_INFORMATIONAL,
                           TOD_LOG_UNSUPORTED_ORDINALID,
                           TOD_UNSUPORTED_ORDINALID,
                           l_ecmdRc, 0 );
       }
    }

    return l_err;
}

//******************************************************************************
//getFuncNodeTargetsOnSystem
//******************************************************************************
errlHndl_t getFuncNodeTargetsOnSystem(const TARGETING::Target*
        i_pInputTarget, TARGETING::TargetHandleList&
        o_functionalNodeTargetList)
{
    TOD_ENTER("getFuncNodeTargetsOnSystem");
    errlHndl_t l_errHdl = NULL;
    o_functionalNodeTargetList.clear();

    do{
        if (i_pInputTarget == NULL )
        {
            TOD_ERR("NULL target passed in the call to method "
                    "getFuncNodeTargetsOnSystem ");
            /*@
             * @errortype
             * @reasoncode   TOD_NULL_INPUT_TARGET
             * @moduleid     TOD_GETFUNCNODETARGETSONSYSTEM
             * @userdata1    HUID of the target that was validated
             * @devdesc      Scom access error
             */
           l_errHdl = new ERRORLOG::ErrlEntry(
                              ERRORLOG::ERRL_SEV_INFORMATIONAL,
                              TOD_GETFUNCNODETARGETSONSYSTEM,
                              TOD_NULL_INPUT_TARGET );
            break;
        }

        CLASS l_class = i_pInputTarget->getAttr<ATTR_CLASS>();
        TYPE  l_type = i_pInputTarget->getAttr<ATTR_TYPE>();

        if((TARGETING::CLASS_SYS == l_class) &&
                (TARGETING::TYPE_SYS ==  l_type))//System target
        {
            //create the predicate with CLASS_ENC and TYPE_NODE
            TARGETING::PredicateCTM
                l_nodeFilter(TARGETING::CLASS_ENC,TARGETING::TYPE_NODE);

            //Use PredicateIsFunctional to filter only functional nodes
            TARGETING::PredicateIsFunctional    l_isFunctional;
            TARGETING::PredicatePostfixExpr     l_functionalAndNodeFilter;

            l_functionalAndNodeFilter.push(&l_nodeFilter).
                push(&l_isFunctional).And();

            //Create an iterator to loop over the selected targets
            TARGETING::TargetRangeFilter    l_pFuncNode(
                    TARGETING::targetService().begin(),
                    TARGETING::targetService().end(),
                    &l_functionalAndNodeFilter );

            for (  ; l_pFuncNode ; ++l_pFuncNode)
            {
                o_functionalNodeTargetList.push_back(*l_pFuncNode);
            }
        }
        else if ((TARGETING::CLASS_ENC == l_class ) &&
                (TARGETING::TYPE_NODE == l_type )) //Node target
        {
            if (i_pInputTarget->getAttr<ATTR_HWAS_STATE>().functional)
            {
                o_functionalNodeTargetList.push_back(
                        const_cast<TARGETING::Target*>(i_pInputTarget));
            }
            else
            {
                TOD_ERR("Failed to get the functional state for target 0x%08X",
                        i_pInputTarget->getAttr<TARGETING::ATTR_HUID>());
                break;
            }
        }
        else
        {
            TOD_ERR("Invalid target 0x%08X  passed in the call to method "
                    "getFuncNodeTargetsOnSystem ",
                    i_pInputTarget->getAttr<TARGETING::ATTR_HUID>());
            /*@
             * @errortype
             * @reasoncode   TOD_INVALID_TARGET
             * @moduleid     TOD_GETFUNCNODETARGETSONSYSTEM
             * @userdata1    HUID of the target that was validated
             * @devdesc      Scom access error
             */
           l_errHdl = new ERRORLOG::ErrlEntry(
                              ERRORLOG::ERRL_SEV_INFORMATIONAL,
                              TOD_GETFUNCNODETARGETSONSYSTEM,
                              TOD_INVALID_TARGET,
                              i_pInputTarget->getAttr<TARGETING::ATTR_HUID>());
            break;
        }
    }while(0);

    if ( l_errHdl )
    {
        o_functionalNodeTargetList.clear();
    }

    TOD_EXIT("getFuncNodeTargetsOnSystem. errHdl = %p", l_errHdl);
    return l_errHdl;
}

} //End  of namespace TOD
