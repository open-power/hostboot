/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimMfgSync.H $                     */
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

#ifndef __PRDF_SimMfgSync_H
#define __PRDF_SimMfgSync_H

#include <prdfMfgSync.H>

#include <mbox/mbox_queues.H>
#include <mbox/mboxif.H>
#include <sys/msg.h>


namespace PRDF
{

/**
 * @brief Singleton to access the SimMfgSync
 */
class SimMfgSync;
PRDF_DECLARE_SINGLETON(SimMfgSync, theSimMfgSync);

/**
 * @brief Returns a reference to the SimMfgSync singleton
 *
 * @return Reference to the SimMfgSync
 */
SimMfgSync& getSimMfgSync();

class SimMfgSync : public MfgSync
{
    public:

        /**
        *  @brief ctor
        */
        SimMfgSync();

        /**
        *  @brief dtor
        */
        virtual ~SimMfgSync();

        /**
         *  @brief sync from FSP mfg thresholds
         *
         *  @return     errlHndl_t
         */
        virtual errlHndl_t  syncMfgThresholdFromFsp();

        /**
         *  @brief sync to FSP mfg trace data
         *
         *  @param Error Signature
         *  @param The PFA data struct
         *
         *  @return errlHndl_t
         */
        virtual errlHndl_t syncMfgTraceToFsp(ErrorSignature *i_esig,
                                             const PfaData  &i_pfaData);
        /**
         * @brief getter for mailbox status
         * @return TRUE if mailbox is enabled. FALSE, otherwise.
         */
        virtual bool isMailboxEnabled();

        /**
         * @brief setter for mailbox status
         * @return None 
         */
        void setMailBoxStatus (bool i_status);

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
         * @param[in] i_expectResponse
         *                 This is a default parameter.
         *                 If true, this function sends a synchronous message
         *                 If false, this function sends an asynchronous message
         *
         *  @return     errlHndl_t
         */
         virtual errlHndl_t  sendMboxMsg( msg_t * i_msg,
                                          bool i_expectResponse = true );

        // Disabled copy constructor and assignment operator
        SimMfgSync(const SimMfgSync & right);
        SimMfgSync & operator=(const SimMfgSync & right);

        bool iv_mailBoxStatus;
};


} // end namespace PRDF

#endif
