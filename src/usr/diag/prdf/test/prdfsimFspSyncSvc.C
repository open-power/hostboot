/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimFspSyncSvc.C $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2020                        */
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

#include <prdfsimFspSyncSvc.H>
#include <prdfMfgThresholdMgr.H>
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

    PRDF_ASSERT(nullptr != i_msg);

    errlHndl_t pError = nullptr;

    switch(i_msg->type)
    {
        case MFG_TRACE_SYNC_TO_FSP:
            pError = processMfgTrace(i_msg);
            if(nullptr != pError)
            {
                PRDF_ERR(FUNC " processMfgTrace returned error");
                PRDF_COMMIT_ERRL(pError, ERRL_ACTION_REPORT);
            }
            break;

        default:
            PRDF_ERR(FUNC " Invalid Message Type received from HB :"
                 "[0x%08X]", i_msg->type);
    }

    PRDF_EXIT(FUNC);
    #undef FUNC
}

errlHndl_t SimFspSyncSvc::processMfgTrace(msg_t *i_msg) const
{
    #define PRDF_FUNC "[SimFspSyncSvc::processMfgTrace]"
    PRDF_ENTER(PRDF_FUNC);

    errlHndl_t l_errLog = nullptr;
    uint8_t l_mruListCount = 0;
    uint8_t  *l_extraData = nullptr;

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

        if(nullptr != l_extraData)
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

