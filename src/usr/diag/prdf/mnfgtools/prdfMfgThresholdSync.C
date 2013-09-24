/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/mnfgtools/prdfMfgThresholdSync.C $          */
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

#include <prdfMfgThresholdSync.H>
#include <prdfMfgThresholdMgr.H>
#include <prdfEnums.H>
#include <initservice/initserviceif.H>

namespace PRDF
{

MfgThresholdSync::MfgThresholdSync()
{
    iv_MailboxEnabled = INITSERVICE::spBaseServicesEnabled();
}

MfgThresholdSync::~MfgThresholdSync()
{
    #define FUNC "[MfgThresholdSync::~MfgThresholdSync]"
    PRDF_TRAC( FUNC );
    #undef FUNC
}

errlHndl_t MfgThresholdSync::syncMfgThresholdFromFsp()
{
    #define FUNC "[MfgThresholdSync::syncMfgThresholdFromFsp]"
    PRDF_ENTER( FUNC );

    errlHndl_t l_err = NULL;

    // Only send message to FSP when mailbox is enabled
    if( isMailboxEnabled() )
    {
        msg_t * msg = msg_allocate();

        // initialize msg buffer
        memset( msg, 0, sizeof(msg_t) );

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

errlHndl_t MfgThresholdSync::sendMboxMsg( msg_t * i_msg )
{
    #define FUNC "[MfgThresholdSync::sendMboxMsg]"
    PRDF_ENTER( FUNC );
    errlHndl_t l_errl = NULL;

    PRDF_TRAC( "type:  0x%04x", i_msg->type );
    PRDF_TRAC( "data0: 0x%016llx", i_msg->data[0] );
    PRDF_TRAC( "data1: 0x%016llx", i_msg->data[1] );
    PRDF_TRAC( "extra_data: %p", i_msg->extra_data );

    // send a sync message
    l_errl = MBOX::sendrecv( MBOX::FSP_PRD_SYNC_MSGQ_ID, i_msg );

    if( NULL != l_errl )
    {
        PRDF_TRAC(FUNC" failed to send mbox msg");
    }

    PRDF_EXIT( FUNC );

    return l_errl;

    #undef FUNC
}


} // end namespace PRDF

