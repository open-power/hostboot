/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/mnfgtools/prdfMfgSync.H $                   */
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

#ifndef __PRDF_MFGSYNC_H
#define __PRDF_MFGSYNC_H

#include <prdfGlobal.H>
#include <prdfMfgThresholdFile.H>
#include <prdfErrorSignature.H>
#include <prdfPfa5Data.h>

#include <mbox/mbox_queues.H>
#include <mbox/mboxif.H>
#include <sys/msg.h>


namespace PRDF
{

/**
 * @brief Singleton to access the MfgSync
 */
class MfgSync;
PRDF_DECLARE_SINGLETON(MfgSync, theMfgSync);

/**
 * @brief Returns a reference to the MfgSync singleton
 *
 * @return Reference to the MfgSync
 */
MfgSync& getMfgSync();

class MfgSync
{
    public:

        /**
        *  @brief ctor
        */
        MfgSync(){};

        /**
        *  @brief dtor
        */
        virtual ~MfgSync(){};

        /**
         *  @brief sync from FSP mfg thresholds
         *
         *  @return     errlHndl_t
         */
        virtual errlHndl_t  syncMfgThresholdFromFsp();

        /**
         * @brief sync to FSP mfg trace data
         *
         * @param i_esig Error Signature
         * @param i_pfaData The PFA data struct
         *
         * @return     errlHndl_t
         */
        virtual errlHndl_t  syncMfgTraceToFsp( ErrorSignature *i_esig,
                                               const PfaData &i_pfaData );

        /**
         *  @brief getter for mailbox enabled flag
         *
         */
        virtual bool isMailboxEnabled();

    private:

        /**
         * @brief  send a sync mbox message to the FSP using the
         *         FSP_MFG_THRESHOLD_SYNC_MSGQ message queue
         *
         * @param[in/out] i_msg
         *                 This parameter is used as both input and an
         *                 output parameter. If the message is
         *                 synchronus, the response will be populated
         *                 in an object pointed to by this pointer.
         *                 If the message is asynchronus, the object
         *                 pointed to by this parameter will be sent
         *                 to the fsp.
         * @param i_expectResponse
         *                 This is a default parameter.
         *                 If true, this functions sends a synchronous message
         *                 If false, this function sends an asynchronous message
         *
         * @return     errlHndl_t
         */
        virtual errlHndl_t  sendMboxMsg( msg_t * i_msg,
                                         bool i_expectResponse = true );

    private:

        // Disabled copy constructor and assignment operator
        MfgSync(const MfgSync & right);
        MfgSync & operator=(const MfgSync & right);
};


} // end namespace PRDF

#endif
