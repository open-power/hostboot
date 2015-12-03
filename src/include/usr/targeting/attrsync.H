/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/attrsync.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
#ifndef __ATTRSYNC_H_
#define __ATTRSYNC_H_
/**
 *  @file targeting/attsync.H
 *
 *  @brief  Interface to support syncing the targeting attributes between the
 *          FSP and Hostboot. Sync operations can be either direction, HB->FSP
 *          or FSP->HB however for sprint 7.12 only HB->FSP support will be
 *          added.
 */
//******************************************************************************
// Includes
//******************************************************************************
#include <mbox/mbox_queues.H>
#include <mbox/mboxif.H>
#include <errl/errlentry.H>
#include <sys/msg.h>
#include <pnortargeting.H>
#include <stddef.h>
#include <targeting/common/targetservice.H>
#include <targeting/common/attrsyncdefs.H>


namespace   TARGETING
{

    /**
     *  @class AttributeSync
     *
     *  @brief Targeting attribute sync class
     *
     *  @par Detailed Description:
     *      Provides all the functionality to synchronize the targeting
     *      attributes from the Hostboot area down to the FSP
     */
    class AttributeSync
    {

        public:

            /**
             *  @brief Initialize the attribute synchronization object
             *
             *  @par Detailed Description
             *      Ensures member variables are initialized to sane values.
             */
            AttributeSync();

            /**
             *  @brief Destroy the attribute sync object resources
             *
             *  @par Detailed Description:
             *      Frees any memory allocated by the attribute sync object
             *
             */
            ~AttributeSync();

            /**
             *  @brief  Setup the internal variables to point to the correct
             *          attribute section.
             *
             *  @par Detailed Description:
             *          This function will call into the AttRP:: to have the
             *          correct attribute section paged into accessible memory.
             *          this function may be called multiple times with different
             *          section names.
             *
             *  @pre None:
             *
             *  @post   The entire section from the HB attribute section
             *          passed in has been synchronized to the FSP memory area.
             *
             *  @param[in]  i_section_to_sync
             *                  TARGETING::SECTION_TYPE is passed in to
             *                  identify the section to be synced to the
             *                  FSP.
             *
             *  @return     errlHndl_t
             *                  return errl ==  NULL  -> success
             *                  return errl !=  NULL  -> failure
             *
             */
            errlHndl_t  syncSectionToFsp( 
                                    TARGETING::SECTION_TYPE i_section_to_sync );

            /**
             *  @brief  Sends a request to the FSP to sync its data to Hostboot
             *          for a specific attribute section.  Write the data
             *          received from the FSP to the attribute section.
             *
             *  @par Detailed Description:
             *          This function will call into the AttRP:: to have the
             *          correct attribute section updated.  This function may be
             *          called multiple times with different section names.
             *
             *  @pre None:
             *
             *  @post   The entire section from the FSP attribute section
             *          passed in has been synchronized to the HB memory area.
             *
             *  @param[in]  i_section_to_sync
             *                  TARGETING::SECTION_TYPE is passed in to
             *                  identify the section to be synced from the
             *                  FSP.
             *              i_msgQ
             *                  the message queue which FSP will use to send
             *                  the attribute data
             *
             *  @return     errlHndl_t
             *                  return errl ==  NULL  -> success
             *                  return errl !=  NULL  -> failure
             *
             */
            errlHndl_t  syncSectionFromFsp(
                                    TARGETING::SECTION_TYPE i_section_to_sync,
                                    msg_q_t i_pMsgQ );

        private:

            /**
             * @enum TARGETING::MBOX_MSG_TYPE
             *
             * @brief  Message enum to determine if msg should be sent
             *         asynchronously or if the call should be synchronous
             *
             */
            enum MBOX_MSG_TYPE
            {
                ASYNCHRONOUS,
                SYNCHRONOUS
            };

            /**
             *  @brief  Setup the internal variables to point to the correct
             *          attribute section.
             *
             *  @par Detailed Description:
             *      This function will call into the AttRP:: to have the
             *      correct attribute section paged into accessible memory
             *
             */
            void        getSectionData();

            /**
             *  @brief  Write the attribute data received from the FSP to
             *          the attribute section.
             *
             *  @par Detailed Description:
             *      This function will call into the AttRP:: to have the
             *      correct attribute section written
             *
             *  @return     ATTR_SYNC_SUCCESS -> success
             *              ATTR_SYNC_FAILURE -> failure
             *
             */
            ATTR_SYNC_RC updateSectionData() const;

            /**
             *  @brief  Uses the internal mailbox to send a message to the FSP
             *
             *
             *  @par Detailed Description:
             *          This funciton will call into mailboxsp code using the
             *          FSP_ATTR_SYNC_MSGQ as a target message queue..
             *
             *  @param[in] i_type
             *           TARGETING::MBOX_MSG_TYPE passed in to define the
             *           message sending policy.
             *
             *  @param[in/out] i_msg 
             *                    This parameter is used as both input and an
             *                    output parameter. If the message is sent
             *                    synchronusly the response will be populated
             *                    in an object pointed to by this pointer. If
             *                    the message is asynchronus the object
             *                    pointed to by this parameter will be sent to
             *                    the fsp.
             *
             *  @return     errlHndl_t
             *                  return errl ==  NULL  -> success
             *                  return errl !=  NULL  -> failure
             */
            errlHndl_t  sendMboxMessage( MBOX_MSG_TYPE i_type, msg_t * i_msg  );

            /**
             *  @brief  Sends the sync complete message to the FSP indicating
             *          the operation has completed.
             *
             *  @return     errlHndl_t
             *                  return errl ==  NULL  -> success
             *                  return errl !=  NULL  -> failure
             */
            errlHndl_t  sendSyncCompleteMessage();

            /**
             *  @brief  Sends the sync to HB request message to the FSP
             *          requesting the FSP to sync it's attribute data
             *          to Hostboot.
             *
             *  @return     errlHndl_t
             *                  return errl ==  NULL  -> success
             *                  return errl !=  NULL  -> failure
             */
            errlHndl_t  sendSyncToHBRequestMessage();

        private:

            // id of the section being updated
            TARGETING::SECTION_TYPE iv_section_to_sync;


            // count of total pages, calculated from data supplied by the
            // attribute resource provider code;
            uint16_t    iv_total_pages;

            // maintiains the current page number being sync'ed.
            uint16_t    iv_current_page;

            // vector of structures to hold the location info for each section
            // we would like to sync.  Data is filled in by the attrrp code
            // when we call AttRP::readSectionData(...
            std::vector <TARGETING::sectionRefData>iv_pages;

    };

    /**
     *  @brief  Handles synchronization of all RW targeting attributes from
     *          hostboot to the fsp; the following sections are
     *          synchronized.
     * 
     *           1). SECTION_TYPE_PNOR_RW
     *           2). SECTION_TYPE_HEAP_PNOR_INIT
     *           3). SECTION_TYPE_HEAP_PNOR_ZERO_INIT
     *
     *
     *  @return     errlHndl_t
     *                  return errl ==  NULL  -> success
     *                  return errl !=  NULL  -> failure
     */
    errlHndl_t syncAllAttributesToFsp();

    /**
     *  @brief  Handles synchronization of all RW targeting attributes from
     *          the fsp to hostboot; the following sections are
     *          synchronized.
     * 
     *           1). SECTION_TYPE_PNOR_RW
     *           2). SECTION_TYPE_HEAP_PNOR_INIT
     *           3). SECTION_TYPE_HEAP_PNOR_ZERO_INIT
     *
     *
     *  @return     errlHndl_t
     *                  return errl ==  NULL  -> success
     *                  return errl !=  NULL  -> failure
     */
    errlHndl_t syncAllAttributesFromFsp();

    /**
     *  @brief  A temporary hack to set attributes that HDAT needs.
     *          To be removed by RTC: 143191
     *  @return     errlHndl_t
     *                  return errl ==  NULL  -> success
     *                  return errl !=  NULL  -> failure
     */
    errlHndl_t hdatAttrHack();

} // namespace
#endif
