/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimFspSyncSvc.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2009,2014              */
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

#ifndef __PRDF_SimFspSyncSvc_H
#define __PRDF_SimFspSyncSvc_H


#include <prdfMfgThresholdFile.H>
#include <prdfGlobal.H>

#include <mbox/mbox_queues.H>
#include <mbox/mboxif.H>
#include <sys/msg.h>


namespace PRDF
{

/**
 *  @brief Singleton to access the SimFspSyncSvc
 */
class SimFspSyncSvc;
PRDF_DECLARE_SINGLETON(SimFspSyncSvc, theSyncSvc);

/**
 *  @brief Returns a reference to the SimFspSyncSvc singleton
 *
 *  @return Reference to the SyncSvc
 */
SimFspSyncSvc& getSyncSvc();

class SimFspSyncSvc
{
    public:

        /**
         * @brief Constructor
         */
        SimFspSyncSvc() {};

        /**
         * @brief Destructor
         */
        virtual ~SimFspSyncSvc() {};

        /**
         * @brief used to process hostboot msg
         *
         * @param[in] i_pHMsg host message ptr from fmbx
         *
         */
        void processRequestMsg(msg_t * i_pHMsg);


    private:

        /*
         * @brief - send back the response to HB with MFG thresholds
         *
         * @param[in] i_msg, the request msg that was sent by HB
         *
         * @return Error log handle that will indicate if the response msg was
         *      successfully sent
         *
         */
        errlHndl_t sendMfgThresRespMsg(msg_t * i_msg) const;

        /*
         * @brief Process the Mnfg Trace data sent by Hostboot
         *
         * @param[in] i_msg, the request msg that was sent by HB
         *
         * @return Error log handle that will indicate if the Mnfg trace file
         *         was updated, error otherwise.
         *
         */
        errlHndl_t processMfgTrace(msg_t * i_msg) const;

        // Disabled copy constructor and assignment operator
        SimFspSyncSvc(const SimFspSyncSvc & right);
        SimFspSyncSvc & operator=(const SimFspSyncSvc & right);


};

} // end namespace PRDF

#endif
