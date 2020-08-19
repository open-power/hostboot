/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimMfgSync.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2020                        */
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

#include <prdfsimMfgSync.H>
#include <prdfsimFspSyncSvc.H>
#include <prdfMfgThresholdMgr.H>
#include <prdfEnums.H>

namespace PRDF
{

SimMfgSync& getSimMfgSync()
{
    return PRDF_GET_SINGLETON(theSimMfgSync);
}

SimMfgSync::SimMfgSync(): MfgSync()
{
    #define FUNC "[SimMfgSync::SimMfgSync]"
    PRDF_TRAC( FUNC );
    iv_mailBoxStatus = false;
    #undef FUNC
}

SimMfgSync::~SimMfgSync()
{
    #define FUNC "[SimMfgSync::~SimMfgSync]"
    PRDF_TRAC( FUNC );
    #undef FUNC
}

errlHndl_t SimMfgSync::syncMfgTraceToFsp(ErrorSignature *i_esig,
                                         const PfaData  &i_pfaData)
{
    #define PRDF_FUNC "[SimMfgSync::syncMfgTraceToFsp]"
    PRDF_ENTER( PRDF_FUNC );

    errlHndl_t l_err = nullptr;

    do
    {
        l_err = MfgSync::syncMfgTraceToFsp(i_esig, i_pfaData);

        if(nullptr != l_err)
        {
            PRDF_TRAC( PRDF_FUNC " syncMfgTraceToFsp failed" );
        }

    } while(0);


    PRDF_EXIT( PRDF_FUNC );

    return l_err;
    #undef PRDF_FUNC
}

errlHndl_t SimMfgSync::sendMboxMsg( msg_t * i_msg, bool i_expectResponse )
{
    #define FUNC "[SimMfgSync::sendMboxMsg]"
    PRDF_ENTER( FUNC );
    errlHndl_t l_errl = nullptr;

    // send a sync message
    PRDF_TRAC(FUNC " sending sync mbox msg" );
    PRDF_TRAC( "type:  0x%04x", i_msg->type );
    PRDF_TRAC( "data0: 0x%016llx", i_msg->data[0] );
    PRDF_TRAC( "data1: 0x%016llx", i_msg->data[1] );
    PRDF_TRAC( "extra_data: %p", i_msg->extra_data );

    // call sim SyncService to handle the request
    getSyncSvc().processRequestMsg(i_msg);

    PRDF_EXIT( FUNC );

    return l_errl;

    #undef FUNC
}

void SimMfgSync::setMailBoxStatus(bool i_status)
{
     iv_mailBoxStatus = i_status;
}

bool SimMfgSync::isMailboxEnabled()
{
    return iv_mailBoxStatus;
}

} // end namespace PRDF

