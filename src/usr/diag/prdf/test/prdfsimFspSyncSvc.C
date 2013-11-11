/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimFspSyncSvc.C $                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2009,2013              */
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

#include <prdfsimFspSyncSvc.H>
#include <prdfMfgThresholdMgr.H>
#include <prdfsimFspMfgThresholdFile.H>
#include <prdfAssert.h>
#include <prdfEnums.H>
#include <prdfErrlUtil.H>

namespace PRDF
{

/****************************/
// SimFspSyncSvc begin
/****************************/

SimFspSyncSvc& getSyncSvc()
{
    return PRDF_GET_SINGLETON(theSyncSvc);
}

void SimFspSyncSvc::processRequestMsg(msg_t * i_msg)
{
    #define FUNC "[SimFspSyncSvc::processRequestMsg]"
    PRDF_ENTER(FUNC);

    PRDF_ASSERT(NULL != i_msg);

    errlHndl_t pError = NULL;

    switch(i_msg->type)
    {
        case MFG_THRES_SYNC_FROM_FSP:
            pError = sendMfgThresRespMsg(i_msg);
            if(NULL != pError)
            {
                PRDF_ERR(FUNC" sendMfgThresRespMsg returned error");
                PRDF_COMMIT_ERRL(pError, ERRL_ACTION_REPORT);
            }
            break;
        default:
            PRDF_ERR(FUNC" Invalid Message Type received from HB :"
                 "[0x%08X]", i_msg->type);
    }

    PRDF_EXIT(FUNC);
    #undef FUNC
}

errlHndl_t SimFspSyncSvc::sendMfgThresRespMsg(msg_t * i_msg) const
{
    #define FUNC "[SimFspSyncSvc::sendMfgThresRespMsg]"
    PRDF_ENTER(FUNC);
    errlHndl_t l_errLog = NULL;
    uint8_t* l_extraData = NULL;

    do
    {
        SimFspMfgThresholdFile l_pMfgThresholdFile;

        // Override Mfg thresholds
        l_pMfgThresholdFile.overrideThreshold();

        uint32_t l_msgSize = l_pMfgThresholdFile.getThresholdSize();

        PRDF_TRAC("l_msgSize=%d", l_msgSize);

        i_msg->data[0] = 0;
        i_msg->data[1] = l_msgSize;
        i_msg->extra_data = NULL;

        if(0 == l_msgSize)
        {
            PRDF_TRAC(FUNC" no override MFG thresholds to send back");
        }
        else
        {
            i_msg->extra_data = malloc( l_msgSize );
            memset(i_msg->extra_data, 0, l_msgSize);

            l_extraData = static_cast<uint8_t*>(i_msg->extra_data);

            l_pMfgThresholdFile.packThresholdDataIntoBuffer(l_extraData,
                                                             l_msgSize);
        }


    } while(0);

    PRDF_EXIT(FUNC);

    return l_errLog;

    #undef FUNC
}

/****************************/
// SimFspSyncSvc end
/****************************/

} // end namespace PRDF

