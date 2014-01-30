/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimFspSyncSvc.C $                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2009,2014              */
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
#include <prdfPfa5Data.h>

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

        case MFG_TRACE_SYNC_TO_FSP:
            pError = processMfgTrace(i_msg);
            if(NULL != pError)
            {
                PRDF_ERR(FUNC" processMfgTrace returned error");
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

errlHndl_t SimFspSyncSvc::processMfgTrace(msg_t *i_msg) const
{
    #define PRDF_FUNC "[SimFspSyncSvc::processMfgTrace]"
    PRDF_ENTER(PRDF_FUNC);

    errlHndl_t l_errLog = NULL;
    uint8_t l_mruListCount = 0;
    uint8_t  *l_extraData = NULL;

    do
    {
        l_extraData = reinterpret_cast <uint8_t *> (i_msg->extra_data);

        l_mruListCount = (i_msg->data[1] / sizeof(PfaMruListStruct));

        if(l_mruListCount > MruListLIMIT)
        {
            PRDF_ERR(PRDF_FUNC "Invalid MRU count: %d received from Hostboot"
                               " max expected count is: %d",
                               l_mruListCount, MruListLIMIT);

            /*@
             * @errortype
             * @refcode    LIC_REFCODE
             * @subsys     EPUB_FIRMWARE_SP
             * @reasoncode PRDF_INVALID_CONFIG
             *
             * @moduleid   PRDF_SYNC_SVC
             * @userdata1  MRU List Count
             * @userdata2  Max MRU Count
             * @userdata3  Line number in file
             * @devdesc    Received invalid MRU count in
             *             MnfgTrace message from Hostboot
             */
            PRDF_CREATE_ERRL(l_errLog,
                             ERRL_SEV_INFORMATIONAL,
                             ERRL_ETYPE_NOT_APPLICABLE,
                             SRCI_ERR_INFO,
                             SRCI_NO_ATTR,
                             PRDF_SYNC_SVC,
                             LIC_REFCODE,
                             PRDF_INVALID_CONFIG,
                             l_mruListCount,
                             MruListLIMIT,
                             __LINE__, 0);
            break;
        }

        if(NULL != l_extraData)
        {
            free(l_extraData);
        }

    }while(0);

    return l_errLog;
    #undef PRDF_FUNC
}

/****************************/
// SimFspSyncSvc end
/****************************/

} // end namespace PRDF

