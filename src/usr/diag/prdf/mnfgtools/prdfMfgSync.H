/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/mnfgtools/prdfMfgSync.H $                   */
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
