/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimMfgSync.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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
