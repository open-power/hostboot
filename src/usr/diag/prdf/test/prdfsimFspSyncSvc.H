/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimFspSyncSvc.H $                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2009,2013              */
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

#ifndef __PRDF_SimFspSyncSvc_H
#define __PRDF_SimFspSyncSvc_H


#include <prdfMfgThresholdFile.H>
#include <prdfGlobal.H>

#include <mbox/mbox_queues.H>
#include <mbox/mboxif.H>
#include <sys/msg.h>


namespace PRDF
{

class SimFspSyncSvc
{
    public:

        /*
         * @brief Returns a pointer to the only instance of this
         *        singleton object, constructing it if neeeded.
         *
         * @return pointer to the instance of this object
         */
        inline static SimFspSyncSvc* getSyncSvc();

        /*
         * @brief Returns true if SyncSvc is already running
         *
         * @return true if already running
         */
        inline bool static isSyncSvcRunning();

        /*
         * @brief Returns true if hb sync was already done
         *
         * @return true if already sync with hostboot
         */
        inline bool isHbSynced();

        /**
         * @brief Destructor
         */
        virtual ~SimFspSyncSvc();

        /**
         * @brief used to process hostboot msg
         *
         * @param[in] i_pHMsg host message ptr from fmbx
         *
         */
        void processRequestMsg(msg_t * i_pHMsg);


    private:

        /**
         * @brief Constructor
         */
        SimFspSyncSvc() {};

        /**
         * @brief Sync Service Singleton
         */
        static SimFspSyncSvc* cvInstance;

        /**
         * @brief Flag to indicate hostboot sync already occurred
         */
        bool iv_hbSynced;

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


        // Disabled copy constructor and assignment operator
        SimFspSyncSvc(const SimFspSyncSvc & right);
        SimFspSyncSvc & operator=(const SimFspSyncSvc & right);


};

inline SimFspSyncSvc* SimFspSyncSvc::getSyncSvc()
{
    if( NULL == cvInstance )
    {
         cvInstance = new SimFspSyncSvc();
    }

    return cvInstance;
}


/**
 *  @brief check if SyncSvc is running
 *
 *  @return true if SyncSvc is already running
 */
inline bool SimFspSyncSvc::isSyncSvcRunning()
{
    return ( NULL == cvInstance ) ? false : true;
}

inline bool SimFspSyncSvc::isHbSynced()
{
    return iv_hbSynced;
}

} // end namespace PRDF

#endif
