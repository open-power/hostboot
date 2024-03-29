/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/attrsync.C $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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
#include <targeting/attrsync.H>
#include <targeting/common/targreasoncodes.H>
#include <targeting/common/trace.H>
#include <initservice/initserviceif.H>
#include <errl/hberrltypes.H>
#include <secureboot/service.H>
#include <arch/magic.H>

using namespace ERRORLOG;

namespace TARGETING
{

    AttributeSync::AttributeSync()
        :iv_section_to_sync(SECTION_TYPE_PNOR_RW),iv_total_pages(0),iv_current_page(0)
    {};

    AttributeSync::~AttributeSync()
    {};

#ifndef __HOSTBOOT_RUNTIME
    void AttributeSync::getSectionData()
    {
        // make sure we have a clean slate
        iv_total_pages  = 0;
        iv_current_page = 0;
        iv_pages.clear();

        // call the targeting function here to get context.
        TargetService& l_targetService = targetService();

        // read the section data info into the iv_pages structure
        l_targetService.readSectionData( iv_pages, iv_section_to_sync );

        iv_total_pages = iv_pages.size();

        TARG_INF("AttributeSync::getDataSection() - total pages %d, section type 0x%x",
                    iv_total_pages, iv_section_to_sync );

    }

    ATTR_SYNC_RC AttributeSync::updateSectionData() const
    {
        TARG_INF( ENTER_MRK "AttributeSync::updateSectionData - "
                  "section type %u total pages %d",
                  iv_section_to_sync, iv_total_pages );

        if (!SECUREBOOT::allowAttrOverrides())
        {
            TARG_INF("AttributeSync::updateSectionData(): skipping since "
                     "attribute overrides are not allowed and we don't "
                     "trust the FSP, but still returning ATTR_SYNC_SUCCESS");
            return ATTR_SYNC_SUCCESS;
        }

        ATTR_SYNC_RC l_rc = ATTR_SYNC_SUCCESS;

        // call the targeting function here to get context.
        TargetService& l_targetService = targetService();

        // write the section data info into the iv_pages structure
        if ( false == l_targetService.writeSectionData( iv_pages ) )
        {
            l_rc = ATTR_SYNC_FAILURE;
        }

        TARG_INF( EXIT_MRK "AttributeSync::updateSectionData");
        return l_rc;
    }

    errlHndl_t AttributeSync::syncSectionToFsp(
                                    TARGETING::SECTION_TYPE i_section_to_sync )
    {
        errlHndl_t l_errl   = NULL;
        msg_t   *  msg      = NULL;

        iv_section_to_sync = i_section_to_sync;

        do{

            // set up the pointers to the data area
            getSectionData();

            for( iv_current_page = 0;
                    iv_current_page < iv_total_pages; iv_current_page++ )
            {
                msg = msg_allocate();

                msg->type = ATTR_SYNC_SECTION_TO_FSP;

                msg->data[0] = 0;

                ATTR_SYNC_ADD_SECTION_ID( iv_section_to_sync, msg->data[0] );

                ATTR_SYNC_ADD_PAGE_NUMBER( iv_current_page, msg->data[0] );

                // set the 2nd data word to the buffer size
                msg->data[1] = PAGESIZE;

                // allocated storage will always be 4k
                msg->extra_data = MBOX::allocate( PAGESIZE );

                // copy the attributes from mem to our buffer.
                memcpy( msg->extra_data,
                        iv_pages[iv_current_page].dataPtr, PAGESIZE );

                TARG_INF("syncSectionToFsp()  - copy %d bytes from %p to %p",
                        PAGESIZE, iv_pages[iv_current_page].dataPtr,
                        msg->extra_data);

                // mailbox code will free both the msg and the extra data
                // we allocated above for an async message.
                l_errl = sendMboxMessage( ASYNCHRONOUS, msg );

                if( l_errl )
                {
                    TARG_ERR("failed sending sync message");
                    break;
                }

            }

            // Tell Simics we are waiting for the FSP to do something
            //  simce the vast majority of the processing time is
            //  on the FSP side of things
            MAGIC_WAITING_FOR_FSP();

            if(( l_errl == NULL ) && ( iv_total_pages != 0 ))
            {
                // tell fsp to commit the last section of data we sent
                l_errl =  sendSyncCompleteMessage();

                if( l_errl )
                {
                    TARG_ERR("failed sending sync complete message");
                }
            }

            // Tell Simics we are done waiting
            MAGIC_DONE_WAITING_FOR_FSP();

        }while(0);

        return l_errl;

    }

    errlHndl_t AttributeSync::syncSectionFromFsp(
                                    TARGETING::SECTION_TYPE i_section_to_sync,
                                    msg_q_t i_pMsgQ )
    {
        TARG_INF( ENTER_MRK "AttributeSync::syncSectionFromFsp" );

        errlHndl_t l_errl    = NULL;
        bool l_sync_complete = false;
        ATTR_SYNC_RC l_rc    = ATTR_SYNC_FAILURE;
        TARGETING::sectionRefData l_page;

        iv_section_to_sync = i_section_to_sync;
        memset( &l_page, 0, sizeof(TARGETING::sectionRefData) );

        do{
            if (!SECUREBOOT::allowAttrOverrides())
            {
                TARG_INF("AttributeSync::syncSectionFromFsp(): skipping since "
                         "attribute overrides are not allowed and we don't "
                         "trust the FSP");
                break;
            }

            // send a request to FSP to sync to Hostboot
            l_errl = sendSyncToHBRequestMessage();
            if (l_errl)
            {
                break;
            }

            do{

                // wait for FSP to send the section's attribute data
                TARG_DBG( "Wait for message from FSP");
                msg_t * l_pMsg = msg_wait(i_pMsgQ);

                // process message just received
                if ( ATTR_SYNC_SECTION_TO_HB == l_pMsg->type )
                {
                    TARG_DBG( "HB Attribute Sync Section message type received "
                        "from the FSP");

                    // get the section id
                    l_page.sectionId = ATTR_SYNC_GET_SECTION_ID(l_pMsg->data[0]);

                    // get the page number
                    l_page.pageNumber = ATTR_SYNC_GET_PAGE_NUMBER(l_pMsg->data[0]);

                    // save a pointer to the page
                    l_page.dataPtr =
                        reinterpret_cast<uint8_t *> (l_pMsg->extra_data);

                    // Validate the data received.  Ignore page if
                    // section id or page size is incorrect or if
                    // there are no page received since we cannot send
                    // an error back to the FSP at this point.  We will
                    // check later whether the correct number of valid
                    // pages for the section was received when FSP send
                    // us the sync complete message.

                    // if no page received
                    if ( NULL == l_page.dataPtr)
                    {
                        TARG_ERR("WARNING: "
                            "no attribute page received from FSP");
                    }
                    // if it's not the requested section
                    else if ( iv_section_to_sync != l_page.sectionId )
                    {
                        TARG_ERR("WARNING: "
                            "section type received from FSP = %u, expecting %u",
                            l_page.sectionId, iv_section_to_sync);

                        //Free the memory
                        free(l_pMsg->extra_data);
                        l_pMsg->extra_data = NULL;
                    }
                    // page size should always be 4K
                    else if ( PAGESIZE != l_pMsg->data[1] )
                    {
                        TARG_ERR("WARNING: "
                            "page size received from FSP = %u, expecting 4K",
                            l_pMsg->data[1]);

                        free(l_pMsg->extra_data);
                        l_pMsg->extra_data = NULL;
                    }
                    else
                    {
                        iv_pages.push_back(l_page);
                    }

                    // Free memory allocated for message
                    msg_free( l_pMsg );
                    l_pMsg = NULL;
                }
                else if ( ATTR_SYNC_COMPLETE_TO_HB == l_pMsg->type )
                {
                    TARG_DBG( "HB Attribute Sync Complete message type "
                        "received from the FSP");

                    l_sync_complete = true;

                    iv_total_pages = ATTR_SYNC_GET_PAGE_COUNT( l_pMsg->data[0] );

                    // check that the total # of valid pages received is correct
                    if ( iv_pages.size() == iv_total_pages )
                    {
                        // write the section to the Attribute virtual address
                        // space
                        l_rc = updateSectionData();

                        if (l_rc)
                        {
                            TARG_ERR(
                                "HB failed in writing the attribute section" );
                        }
                    }
                    else
                    {
                        TARG_ERR( "total # of valid pages received = %u, "
                            "expecting %u", iv_pages.size(), iv_total_pages);

                        l_rc = ATTR_SYNC_FAILURE;
                    }

                    if (l_rc)
                    {
                        /*@
                         *   @errortype
                         *   @moduleid      TARG_MOD_ATTR_SYNC
                         *   @reasoncode    TARG_RC_ATTR_SYNC_TO_HB_FAIL
                         *   @userdata1     return code
                         *   @userdata2     section to sync
                         *   @devdesc       The attribute synchronization from
                         *                  the FSP failed.
                         */
                         l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                                TARG_MOD_ATTR_SYNC,
                                                TARG_RC_ATTR_SYNC_TO_HB_FAIL,
                                                l_rc,
                                                iv_section_to_sync);
                    }

                    // send a msg back to FSP indicating success/failure
                    l_pMsg->data[0] = 0;
                    ATTR_SYNC_ADD_RC( l_rc, l_pMsg->data[0] );
                    int l_respond_rc = msg_respond(i_pMsgQ, l_pMsg);
                    if (l_respond_rc)
                    {
                        // Just output a trace here since FSP should
                        // handle error case where it doesn't receive
                        // a response from HB.
                        TARG_ERR( "WARNING: Bad rc from msg_respond: %d",
                            l_respond_rc);
                        msg_free( l_pMsg );
                        l_pMsg = NULL;
                    }
                }
                else
                {
                    TARG_ERR( "WARNING: Invalid message type [0x%x] received "
                        "from the FSP, ignoring...", l_pMsg->type);
                    msg_free( l_pMsg );
                    l_pMsg = NULL;
                }

            }while (false == l_sync_complete);

            // free memory
            if ( iv_pages.size() )
            {
                for ( size_t i = 0; i < iv_pages.size(); i++ )
                {
                    free( iv_pages[i].dataPtr );
                }

                iv_pages.clear();
            }

        }while (0);

        TARG_INF( EXIT_MRK "AttributeSync::syncSectionFromFsp" );
        return l_errl;
    }

    // send the sync complete message
    errlHndl_t AttributeSync::sendSyncCompleteMessage( )
    {
        TARG_INF("sending sync complete message");

        errlHndl_t l_err = NULL;

        msg_t * msg = msg_allocate();

        // initialize msg buffer
        memset( msg, 0, sizeof(msg_t) );

        msg->type = ATTR_SYNC_COMPLETE_TO_FSP;

        ATTR_SYNC_ADD_PAGE_COUNT( iv_total_pages, msg->data[0] );

        l_err = sendMboxMessage( SYNCHRONOUS, msg );

        if( l_err == NULL )
        {
            // see if there was an error on the other end
            ATTR_SYNC_RC return_code = ATTR_SYNC_GET_RC( msg->data[0] );

            if ( return_code )
            {
                TARG_ERR("Attribute sync failed with return code: 0x%x", return_code );
                TARG_ERR("Failed syncing iv_total_pages: 0x%x from iv_section_to_sync: 0x%x",
                          iv_total_pages,iv_section_to_sync );

                /*@
                 *   @errortype
                 *   @moduleid          TARG_MOD_ATTR_SYNC
                 *   @reasoncode        TARG_RC_ATTR_SYNC_TO_FSP_FAIL
                 *   @userdata1         return code from FSP attribute sync
                 *   @userdata2[0:31]   page count for this section
                 *   @userdata2[31:63]  section ID of for section being sync'd
                 *
                 *   @devdesc       The attribute synchronization code on the
                 *                  FSP side was unable to complete the sync
                 *                  operation successfully.
                 *
                 *   @custdesc      A problem occurred during the IPL of the
                 *                  system: Attributes were not fully
                 *                  syncronized between the host firmware and
                 *                  service processor.
                 *
                 */
                 l_err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                        TARG_MOD_ATTR_SYNC,
                                        TARG_RC_ATTR_SYNC_TO_FSP_FAIL,
                                        return_code,
                                        TWO_UINT32_TO_UINT64(
                                            iv_total_pages,iv_section_to_sync));
            }
        }

        // for a syncronous message we need to free the message
        msg_free( msg );

        return l_err;
    }

    // send a request to FSP to sync to Hostboot
    errlHndl_t AttributeSync::sendSyncToHBRequestMessage()
    {
        TARG_INF( ENTER_MRK "AttributeSync::sendSyncToHBRequestMessage" );

        errlHndl_t l_err = NULL;

        // allocate message buffer
        // buffer will be initialized to zero by msg_allocate()
        msg_t * l_pMsg = msg_allocate();

        l_pMsg->type = ATTR_SYNC_REQUEST_TO_HB;

        ATTR_SYNC_ADD_SECTION_ID( iv_section_to_sync, l_pMsg->data[0] );

        l_err = sendMboxMessage( SYNCHRONOUS, l_pMsg );

        if( l_err == NULL )
        {
            // see if there was an error on the other end
            ATTR_SYNC_RC return_code = ATTR_SYNC_GET_RC( l_pMsg->data[0] );

            if ( return_code )
            {
                TARG_ERR(
                    "rc 0x%x received from FSP for Sync to HB request",
                    return_code );

                /*@
                 *   @errortype
                 *   @moduleid      TARG_MOD_ATTR_SYNC
                 *   @reasoncode    TARG_RC_ATTR_SYNC_REQUEST_TO_HB_FAIL
                 *   @userdata1     return code from FSP
                 *   @userdata2     section to sync
                 *   @devdesc       The attribute synchronization code on the
                 *                  FSP side was unable to fulfill the sync to
                 *                  HostBoot request.
                 */
                 l_err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                       TARG_MOD_ATTR_SYNC,
                                       TARG_RC_ATTR_SYNC_REQUEST_TO_HB_FAIL,
                                       return_code,
                                       iv_section_to_sync);
            }
        }
        else
        {
            TARG_ERR(
                "Failed to send request to FSP to sync section type %u "
                "to Hostboot.", iv_section_to_sync );
        }

        // for a syncronous message we need to free the message
        msg_free( l_pMsg );
        l_pMsg = NULL;

        TARG_INF( EXIT_MRK "AttributeSync::sendSyncToHBRequestMessage" );
        return l_err;
    }

    errlHndl_t AttributeSync::sendMboxMessage( MBOX_MSG_TYPE type,
                                                msg_t * i_msg )
    {
        errlHndl_t l_errl = NULL;

        TARG_DBG("type:  0x%04x",   i_msg->type );
        TARG_DBG("data0: 0x%016llx",i_msg->data[0] );
        TARG_DBG("data1: 0x%016llx",i_msg->data[1] );
        TARG_DBG("extra_data: %p",i_msg->extra_data );

        // determine if its an async message or if we should wait
        // for a response
        if( type == ASYNCHRONOUS )
        {
            TARG_DBG("sendMboxMessage() - sending async mbox msg" );
            l_errl = MBOX::send( MBOX::FSP_ATTR_SYNC_MSGQ, i_msg );
        }
        else
        {
            TARG_INF("sendMboxMessage() - sending sync mbox msg" );
            l_errl = MBOX::sendrecv( MBOX::FSP_ATTR_SYNC_MSGQ, i_msg );

        }

        if( l_errl )
        {
            TARG_ERR("sendMboxMessage() - failed sending mbox msg" );

            // if the send failed and the message is still valid, check
            // and free the extra data if it exists.
            if( i_msg != NULL && i_msg->extra_data != NULL )
            {
                free( i_msg->extra_data );
            }
        }

        return l_errl;
    }


    errlHndl_t syncAllAttributesToFsp()
    {
        errlHndl_t l_errl = NULL;

        do{
            // If no SP Base Services then skip attribute sync
            // let the test case force message creation/sending
            if( !INITSERVICE::spBaseServicesEnabled() )
            {
                break;
            }

            SECTION_TYPE section_type[] ={SECTION_TYPE_PNOR_RW,
                                      SECTION_TYPE_HEAP_PNOR_INIT,
                                      SECTION_TYPE_HEAP_ZERO_INIT};

            size_t section_count = sizeof(section_type)/sizeof(section_type[0]);

            TARG_INF("section count = %d", section_count );

            // push down all attributes to FSP
            AttributeSync l_Sync;

            uint8_t i = 0;

            for(; i < section_count; i++)
            {
                l_errl = l_Sync.syncSectionToFsp( section_type[i] );

                if( l_errl )
                {
                    TARG_ERR("Error returned when syncing section type %d to FSP",
                            section_type[i]);

                    // collect some trace
                    l_errl->collectTrace("TARG", 512);
                    l_errl->collectTrace("MBOX", 512);

                    break;
                }
            }

        } while (0);

        return  l_errl;
    }

    errlHndl_t syncAllAttributesFromFsp()
    {
        TARG_INF( ENTER_MRK "syncAllAttributesFromFsp" );

        errlHndl_t l_errl = NULL;

        do{
            // If no SP Base Services then skip attribute sync
            if( !INITSERVICE::spBaseServicesEnabled() )
            {
                TARG_INF( "SP Base Services not enabled, skipping attribute sync" );
                break;
            }

            if (!SECUREBOOT::allowAttrOverrides())
            {
                TARG_INF("syncAllAttributesFromFsp(): skipping since "
                         "attribute overrides are not allowed and we don't "
                         "trust the FSP");
                break;
            }

            // create Hostboot message queue
            msg_q_t l_pHbMsgQ = msg_q_create();

            // register Hostboot message queue with mailbox to receive messages
            l_errl = MBOX::msgq_register(MBOX::HB_ATTR_SYNC_MSGQ, l_pHbMsgQ);
            if (l_errl)
            {
                TARG_ERR( "Error registering the Hostboot message queue with "
                    "mailbox service." );
                break;
            }

            // these are the sections we want to sync
            SECTION_TYPE section_type[] ={SECTION_TYPE_PNOR_RW,
                                          SECTION_TYPE_HEAP_PNOR_INIT,
                                          SECTION_TYPE_HEAP_ZERO_INIT};

            size_t section_count = sizeof(section_type)/sizeof(section_type[0]);

            TARG_DBG( "section count = %d", section_count );

            // pull all attributes from FSP
            AttributeSync l_Sync;

            for(uint8_t i = 0; i < section_count; i++)
            {
                TARG_INF( "syncing section type = %d", section_type[i] );
                l_errl = l_Sync.syncSectionFromFsp( section_type[i], l_pHbMsgQ );

                if (l_errl)
                {
                    break;
                }
            }

            // unregister the Hosboot message queue from the mailbox service.
            MBOX::msgq_unregister(MBOX::HB_ATTR_SYNC_MSGQ);

        } while (0);

        // Zero ATTR_RECONFIGURE_LOOP to avoid TI
        TARGETING::Target* l_pTopLevel = NULL;
        TARGETING::targetService().getTopLevelTarget(l_pTopLevel);
        l_pTopLevel->setAttr<TARGETING::ATTR_RECONFIGURE_LOOP>(0);

        TARG_INF( EXIT_MRK "syncAllAttributesFromFsp" );
        return  l_errl;
    }
#endif

};   // end namespace


