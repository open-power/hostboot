/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimMfgThresholdSync.H $            */
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

#ifndef __PRDF_SimMfgThresholdSync_H
#define __PRDF_SimMfgThresholdSync_H

#include <prdfMfgThresholdSync.H>

#include <mbox/mbox_queues.H>
#include <mbox/mboxif.H>
#include <sys/msg.h>


namespace PRDF
{

class SimMfgThresholdSync : public MfgThresholdSync
{
    public:

        /**
        *  @brief ctor
        */
        SimMfgThresholdSync();

        /**
        *  @brief dtor
        */
        virtual ~SimMfgThresholdSync();

        /**
         *  @brief sync from FSP mfg thresholds
         *
         *  @return     errlHndl_t
         */
        virtual errlHndl_t  syncMfgThresholdFromFsp();

    private:

        /**
         *  @brief  send a sync mbox message to the FSP using the
         *          FSP_MFG_THRESHOLD_SYNC_MSGQ message queue
         *
         *  @param[in/out] i_msg
         *                    This parameter is used as both input and an
         *                    output parameter. If the message is
         *                    synchronus the response will be populated
         *                    in an object pointed to by this pointer.
         *                    If the message is asynchronus the object
         *                    pointed to by this parameter will be sent
         *                    to the fsp.
         *
         *  @return     errlHndl_t
         */
        virtual errlHndl_t  sendMboxMsg( msg_t * i_msg );

};


} // end namespace PRDF

#endif
