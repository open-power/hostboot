/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/mnfgtools/prdfMfgSync.C $                   */
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

#include <prdfMfgSync.H>
#include <prdfMfgThresholdMgr.H>
#include <prdfEnums.H>
#include <initservice/initserviceif.H>

namespace PRDF
{

MfgSync& getMfgSync()
{
    return PRDF_GET_SINGLETON(theMfgSync);
}

errlHndl_t MfgSync::syncMfgTraceToFsp( ErrorSignature *i_esig,
                                       const PfaData &i_pfaData )
{
    #define PRDF_FUNC "[MfgSync::syncMfgTraceToFsp]"
    PRDF_ENTER( PRDF_FUNC );

    errlHndl_t l_err = nullptr;
    msg_t *msg = nullptr;

    do
    {
        // Only send message to FSP when mailbox is enabled
        if( false == isMailboxEnabled() )
        {
            // mailbox is not enabled, skipping MFG trace sync.
            break;
        }

        uint32_t l_chipID = i_esig->getChipId();
        uint32_t l_sigID = i_esig->getSigId();
        uint64_t l_data0 = l_chipID;
        l_data0 = ((l_data0 << 32) | l_sigID);

        msg = msg_allocate();

        msg->type = MFG_TRACE_SYNC_TO_FSP;
        msg->data[0] = l_data0;
        msg->data[1] = (i_pfaData.mruListCount * sizeof(PfaMruListStruct));
        if(0 < i_pfaData.mruListCount)
        {
            msg->extra_data =
                      malloc(i_pfaData.mruListCount * sizeof(PfaMruListStruct));
            memcpy(msg->extra_data,
                   i_pfaData.mruList,
                   (i_pfaData.mruListCount * sizeof(PfaMruListStruct)));
        }

        l_err = sendMboxMsg( msg, false );

        if( nullptr != l_err )
        {
            PRDF_ERR( PRDF_FUNC " failed to send mbox msg" );
            break;
        }
    }while(0);

    // After sending an asynchronous message, the memory allocated
    // to msg and extra_data is automatically deleted.
    // We need to free it explicity if the message send failed.
    if(nullptr != l_err)
    {
        free( msg->extra_data );
        msg_free( msg );
        msg = nullptr;
    }

    PRDF_EXIT( PRDF_FUNC );

    return l_err;
    #undef PRDF_FUNC
}

errlHndl_t MfgSync::sendMboxMsg( msg_t * i_msg, bool i_expectResponse )
{
    #define FUNC "[MfgSync::sendMboxMsg]"
    PRDF_ENTER( FUNC );
    errlHndl_t l_errl = nullptr;

    PRDF_TRAC( "type:  0x%04x", i_msg->type );
    PRDF_TRAC( "data0: 0x%016llx", i_msg->data[0] );
    PRDF_TRAC( "data1: 0x%016llx", i_msg->data[1] );
    PRDF_TRAC( "extra_data: %p", i_msg->extra_data );

    if(true == i_expectResponse)
    {
        // send a sync message
        l_errl = MBOX::sendrecv( MBOX::FSP_PRD_SYNC_MSGQ_ID, i_msg );
    }
    else
    {
        // send an async message
        l_errl = MBOX::send( MBOX::FSP_PRD_SYNC_MSGQ_ID, i_msg );
    }

    if( nullptr != l_errl )
    {
        PRDF_TRAC(FUNC " failed to send mbox msg");
    }

    PRDF_EXIT( FUNC );

    return l_errl;

    #undef FUNC
}

bool MfgSync::isMailboxEnabled()
{
    return INITSERVICE::spBaseServicesEnabled();
}

} // end namespace PRDF

