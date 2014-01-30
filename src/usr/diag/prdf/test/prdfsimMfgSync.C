/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimMfgSync.C $                     */
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

errlHndl_t SimMfgSync::syncMfgThresholdFromFsp()
{
    #define FUNC "[SimMfgSync::syncMfgThresholdFromFsp]"
    PRDF_ENTER( FUNC );

    errlHndl_t l_err = NULL;

    do
    {
        l_err = MfgSync::syncMfgThresholdFromFsp();

        if(NULL != l_err)
        {
            PRDF_TRAC( FUNC" syncMfgThresholdFromFsp failed" );
        }

    } while(0);


    PRDF_EXIT( FUNC );

    return l_err;
    #undef FUNC
}

errlHndl_t SimMfgSync::syncMfgTraceToFsp(ErrorSignature *i_esig,
                                         const PfaData  &i_pfaData)
{
    #define PRDF_FUNC "[SimMfgSync::syncMfgTraceToFsp]"
    PRDF_ENTER( PRDF_FUNC );

    errlHndl_t l_err = NULL;

    do
    {
        l_err = MfgSync::syncMfgTraceToFsp(i_esig, i_pfaData);

        if(NULL != l_err)
        {
            PRDF_TRAC( PRDF_FUNC" syncMfgTraceToFsp failed" );
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
    errlHndl_t l_errl = NULL;

    // send a sync message
    PRDF_TRAC(FUNC" sending sync mbox msg" );
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

