/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/targeting/attrsync.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#include <targeting/attrsync.H>
#include <targeting/common/targreasoncodes.H>
#include <targeting/common/trace.H>

using namespace ERRORLOG;

namespace TARGETING
{

    AttributeSync::AttributeSync()
        :iv_section_to_sync(SECTION_TYPE_PNOR_RW),iv_total_pages(0),iv_current_page(0)
    {};

    AttributeSync::~AttributeSync()
    {};

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

        TRACDCOMP(g_trac_targeting, "total pages %d", iv_total_pages );
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

                msg->type = ATTR_SYNC_SECTION;

                msg->data[0] = 0;

                ATTR_SYNC_ADD_SECTION_ID( iv_section_to_sync, msg->data[0] );

                ATTR_SYNC_ADD_PAGE_NUMBER( iv_current_page, msg->data[0] );

                // set the 2nd data word to the buffer size
                msg->data[1] = PAGESIZE;

                // allocated storage will always be 4k
                msg->extra_data = malloc( PAGESIZE );

                // copy the attributes from mem to our buffer.
                memcpy( msg->extra_data, 
                        iv_pages[iv_current_page].dataPtr, PAGESIZE );

                TRACFCOMP(g_trac_targeting, 
                        "syncSectionToFsp()  - copy %d bytes from %p to %p",
                        PAGESIZE, iv_pages[iv_current_page].dataPtr, 
                        msg->extra_data);

                // mailbox code will free both the msg and the extra data
                // we allocated above for an async message.
                l_errl = sendMboxMessage( ASYNCHRONOUS, msg );

                if( l_errl )
                {
                    TRACFCOMP(g_trac_targeting, "failed sending sync message");
                    break;
                }

            }

            if( l_errl == NULL )
            {
                // tell fsp to commit the last section of data we sent
                l_errl =  sendSyncCompleteMessage();

                if( l_errl )
                {
                    TRACFCOMP(g_trac_targeting,
                            "failed sending sync complete message");
                }
            }

        }while(0);

        return l_errl;

    }

    // send the sync complete message
    errlHndl_t AttributeSync::sendSyncCompleteMessage( )
    {
        TRACFCOMP(g_trac_targeting, "sending sync complete message");

        errlHndl_t l_err = NULL;

        msg_t * msg = msg_allocate();

        // initilaize msg buffer
        memset( msg, 0, sizeof(msg_t) );

        msg->type = ATTR_SYNC_COMPLETE;

        ATTR_SYNC_ADD_PAGE_COUNT( iv_total_pages, msg->data[0] );

        l_err = sendMboxMessage( SYNCHRONOUS, msg );

        if( l_err == NULL )
        {
            // see if there was an error on the other end
            ATTR_SYNC_RC return_code = ATTR_SYNC_GET_RC( msg->data[0] );

            if ( return_code )
            {
                TRACFCOMP(g_trac_targeting, "return code: 0x%x", return_code );

                /*@
                 *   @errortype
                 *   @moduleid      TARG_MOD_ATTR_SYNC
                 *   @reasoncode    TARG_RC_ATTR_SYNC_FAIL
                 *   @userdata1     return code from FSP attribute sync
                 *   @userdata2     section ID of for section being sync'd
                 *
                 *   @devdesc       The Attribute synchronization code on the
                 *                  FSP side was unable to complete the sync
                 *                  operation successfully.
                 */
                 l_err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                        TARG_MOD_ATTR_SYNC,
                                        TARG_RC_ATTR_SYNC_FAIL,
                                        return_code,
                                        (uint64_t)iv_section_to_sync);
            }
        }

        // for a syncronous message we need to free the message
        msg_free( msg );

        return l_err;
    }

    errlHndl_t AttributeSync::sendMboxMessage( MBOX_MSG_TYPE type,
                                                msg_t * i_msg )
    {
        errlHndl_t l_errl = NULL;

        TRACDCOMP(g_trac_targeting, "type:  0x%04x",   i_msg->type );
        TRACDCOMP(g_trac_targeting, "data0: 0x%016llx",i_msg->data[0] );
        TRACDCOMP(g_trac_targeting, "data1: 0x%016llx",i_msg->data[1] );
        TRACDCOMP(g_trac_targeting, "extra_data: %p",i_msg->extra_data );

        // determine if its an async message or if we should wait
        // for a response
        if( type == ASYNCHRONOUS )
        {
            TRACDCOMP(g_trac_targeting,
                    "sendMboxMessage() - sending async mbox msg" );
            l_errl = MBOX::send( MBOX::FSP_ATTR_SYNC_MSGQ, i_msg );
        }
        else
        {
            TRACDCOMP(g_trac_targeting,
                    "sendMboxMessage() - sending sync mbox msg" );
            l_errl = MBOX::sendrecv( MBOX::FSP_ATTR_SYNC_MSGQ, i_msg );

        }

        if( l_errl )
        {
            TRACFCOMP(g_trac_targeting,
                    "sendMboxMessage() - failed sending mbox msg" );

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
            // if the mailbox is not enabled then skip attribute sync
            // let the test case force message creation/sending
            if( !(MBOX::mailbox_enabled()) )
            {
                break;
            }

            SECTION_TYPE section_type[] ={SECTION_TYPE_PNOR_RW,
                                      SECTION_TYPE_HEAP_PNOR_INIT,
                                      SECTION_TYPE_HEAP_ZERO_INIT};

            size_t section_count = sizeof(section_type)/sizeof(section_type[0]);

            TRACFCOMP(g_trac_targeting,"section count = %d", section_count );

            // push down all attributes to FSP
            AttributeSync l_Sync;

            uint8_t i = 0;

            for(; i < section_count; i++)
            {
                l_errl = l_Sync.syncSectionToFsp( section_type[i] );

                if( l_errl )
                {
                    TRACFCOMP(g_trac_targeting,
                            "Error returned when syncing section type %d", 
                            section_type[i]);
                    break;
                }
            }

        } while (0);

        return  l_errl;
    }

};   // end namespace


