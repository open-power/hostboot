/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimMfgThresholdSync.C $            */
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

#include <prdfsimMfgThresholdSync.H>
#include <prdfsimFspSyncSvc.H>
#include <prdfMfgThresholdMgr.H>
#include <prdfEnums.H>

namespace PRDF
{

SimMfgThresholdSync::SimMfgThresholdSync()
: MfgThresholdSync()
{
    #define FUNC "[SimMfgThresholdSync::SimMfgThresholdSync]"
    PRDF_TRAC( FUNC );

    // override the mailbox enabled flag for testing
    setMailboxEnabled( true );

    #undef FUNC
}

SimMfgThresholdSync::~SimMfgThresholdSync()
{
    #define FUNC "[SimMfgThresholdSync::~SimMfgThresholdSync]"
    PRDF_TRAC( FUNC );
    #undef FUNC
}

errlHndl_t SimMfgThresholdSync::syncMfgThresholdFromFsp()
{
    #define FUNC "[SimMfgThresholdSync::SimsyncMfgThresholdFromFsp]"
    PRDF_ENTER( FUNC );

    errlHndl_t l_err = NULL;

    do
    {
        l_err = MfgThresholdSync::syncMfgThresholdFromFsp();

        if(NULL != l_err)
        {
            PRDF_TRAC( FUNC" syncMfgThresholdFromFsp failed" );
        }

    } while(0);


    PRDF_EXIT( FUNC );

    return l_err;
    #undef FUNC
}

errlHndl_t SimMfgThresholdSync::sendMboxMsg( msg_t * i_msg )
{
    #define FUNC "[SimMfgThresholdSync::sendMboxMsg]"
    PRDF_ENTER( FUNC );
    errlHndl_t l_errl = NULL;

    // send a sync message
    PRDF_TRAC(FUNC" sending sync mbox msg" );
    PRDF_TRAC( "type:  0x%04x", i_msg->type );
    PRDF_TRAC( "data0: 0x%016llx", i_msg->data[0] );
    PRDF_TRAC( "data1: 0x%016llx", i_msg->data[1] );
    PRDF_TRAC( "extra_data: %p", i_msg->extra_data );

    // call sim SyncService to handle the request
    SimFspSyncSvc::getSyncSvc()->processRequestMsg(i_msg);

    PRDF_EXIT( FUNC );

    return l_errl;

    #undef FUNC
}


} // end namespace PRDF

