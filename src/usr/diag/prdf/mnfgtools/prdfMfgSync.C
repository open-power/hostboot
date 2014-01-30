/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/mnfgtools/prdfMfgSync.C $                   */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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

errlHndl_t MfgSync::syncMfgThresholdFromFsp()
{
    #define FUNC "[MfgSync::syncMfgThresholdFromFsp]"
    PRDF_ENTER( FUNC );

    errlHndl_t l_err = NULL;

    // Only send message to FSP when mailbox is enabled
    if( isMailboxEnabled() )
    {
        msg_t * msg = msg_allocate();

        msg->type = MFG_THRES_SYNC_FROM_FSP;
        msg->data[0] = 0;
        msg->data[1] = 0;
        msg->extra_data = NULL;

        l_err = sendMboxMsg( msg );

        if( NULL != l_err )
        {
            PRDF_ERR( FUNC" failed to send mbox msg" );
        }
        else
        {
            uint32_t l_msgSize = msg->data[1];
            uint8_t* l_extraData = NULL;
            l_extraData = static_cast<uint8_t*>(msg->extra_data);

            if(0 == l_msgSize)
            {
                PRDF_TRAC( FUNC" No FSP MFG Thresholds to sync" );
            }
            else
            {
                PRDF_TRAC( "response message:" );
                PRDF_TRAC( "type:  0x%04x", msg->type );
                PRDF_TRAC( "data0: 0x%016llx", msg->data[0] );
                PRDF_TRAC( "data1: 0x%016llx", msg->data[1] );
                PRDF_TRAC( "extra_data: %p", msg->extra_data );

                // save override thresholds
                MfgThresholdFile * l_pMfgThresholdFile =
                    MfgThresholdMgr::getInstance()->getMfgThresholdFile();
                l_pMfgThresholdFile->unpackThresholdDataFromBuffer(
                                                l_extraData, l_msgSize);
            }
        }

        // free extra data and msg
        if(NULL != msg)
        {
            if(NULL != msg->extra_data)
            {
                free( msg->extra_data );
                msg->extra_data = NULL;
            }

            msg_free( msg );
            msg = NULL;
        }
    }
    else
    {
        PRDF_TRAC( FUNC" mailbox is not enabled, "
                       "skipping MFG threshold sync." );
    }

    PRDF_EXIT( FUNC );

    return l_err;
    #undef FUNC
}

errlHndl_t MfgSync::syncMfgTraceToFsp( ErrorSignature *i_esig,
                                       const PfaData &i_pfaData )
{
    #define PRDF_FUNC "[MfgSync::syncMfgTraceToFsp]"
    PRDF_ENTER( PRDF_FUNC );

    errlHndl_t l_err = NULL;
    msg_t *msg = NULL;

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

        if( NULL != l_err )
        {
            PRDF_ERR( PRDF_FUNC" failed to send mbox msg" );
            break;
        }
    }while(0);

    // After sending an asynchronous message, the memory allocated
    // to msg and extra_data is automatically deleted.
    // We need to free it explicity if the message send failed.
    if(NULL != l_err)
    {
        free( msg->extra_data );
        msg_free( msg );
        msg = NULL;
    }

    PRDF_EXIT( PRDF_FUNC );

    return l_err;
    #undef PRDF_FUNC
}

errlHndl_t MfgSync::sendMboxMsg( msg_t * i_msg, bool i_expectResponse )
{
    #define FUNC "[MfgSync::sendMboxMsg]"
    PRDF_ENTER( FUNC );
    errlHndl_t l_errl = NULL;

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

    if( NULL != l_errl )
    {
        PRDF_TRAC(FUNC" failed to send mbox msg");
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

