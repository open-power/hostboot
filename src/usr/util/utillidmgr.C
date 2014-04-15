/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/utillidmgr.C $                                   */
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

#include <util/utillidmgr.H>
#include <util/util_reasoncodes.H>
#include <vfs/vfs.H>
#include <stdio.h>
#include <assert.h>

#include <errl/errlmanager.H>
#include "utillidmgrdefs.H"
#include "utilbase.H"

using namespace ERRORLOG;
mutex_t UtilLidMgr::cv_mutex = MUTEX_INITIALIZER;


///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
UtilLidMgr::UtilLidMgr(uint32_t i_lidId)
: iv_needUnlock(false)
,iv_queueRegistered(false)
,iv_HbMsgQ(NULL)
,iv_lidSize(0)
{
    updateLid(i_lidId);
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
UtilLidMgr::~UtilLidMgr()
{
    errlHndl_t l_err = NULL;

    l_err = cleanup();
    if(l_err)
    {
        //cleanup errors are extermely rare
        errlCommit( l_err, UTIL_COMP_ID );
    }
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
errlHndl_t UtilLidMgr::getLidSize(size_t& o_lidSize)
{
    errlHndl_t errl = NULL;
    o_lidSize = 0;
    bool img_in_pnor = false;
    do{
        //////////////////////////////////////////////////
        //Check if file is in the PNOR Extended image first.
        //////////////////////////////////////////////////
        errl = getLidSizePnor(o_lidSize, img_in_pnor);
        if(errl)
        {
            //unexpected error encountered, /return to caller.
            break;
        }
        else if(img_in_pnor)
        {
            //Found image in PNOR.  Save size and return
            iv_lidSize = o_lidSize;
            break;
        }

        //if we get here, it means we didn't find the LID in PNOR, so
        //ask the FSP for it.

        //Send message to FSP asking for info on the current LID.

        // allocate message buffer
        // buffer will be initialized to zero by msg_allocate()
        msg_t * l_pMsg = msg_allocate();

        l_pMsg->type = UTILLID::GET_INFO;

        UTILLID_ADD_LID_ID( iv_lidId, l_pMsg->data[0] );
        UTILLID_ADD_HEADER_FLAG( 0 , l_pMsg->data[0] );

        errl = sendMboxMessage( SYNCHRONOUS, l_pMsg );
        if(errl)
        {
            UTIL_FT(ERR_MRK"getLidSize: Error when calling sendMboxMessage(SYNCHRONOUS)");
            break;
        }

        // see if there was an error on the other end
        UTILLID::UTILLID_RC return_code = UTILLID_GET_RC( l_pMsg->data[0] );

        if ( return_code )
        {
            UTIL_FT(ERR_MRK"getLidSize: rc 0x%x received from FSP for Sync to HB request",
                    return_code );

            /*@
             *   @errortype
             *   @moduleid      Util::UTIL_LIDMGR_GETLIDSIZE
             *   @reasoncode    Util::UTIL_LIDMGR_RC_FAIL
             *   @userdata1     return code from FSP
             *   @userdata2     LID ID
             *   @devdesc       The LID transfer code on the FSP side was
             *                  unable to fulfill the LID GET_INFO request.
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 Util::UTIL_LIDMGR_GETLIDSIZE,
                                 Util::UTIL_LIDMGR_RC_FAIL,
                                 return_code,
                                 iv_lidId);
            errl->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                      HWAS::SRCI_PRIORITY_HIGH);
            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                      HWAS::SRCI_PRIORITY_MED);
            // for a syncronous message we need to free the message
            msg_free( l_pMsg );
            l_pMsg = NULL;
            break;
        }

        // Get the LID Size
        iv_lidSize = UTILLID_GET_SIZE( l_pMsg->data[0] );

        o_lidSize = iv_lidSize;

        // for a syncronous message we need to free the message
        msg_free( l_pMsg );
        l_pMsg = NULL;

    }while(0);

    return errl;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
errlHndl_t UtilLidMgr::getLidSizePnor(size_t& o_lidSize, bool& o_imgInPnor)
{
    errlHndl_t errl = NULL;
    const char * lidAddr = NULL;

    o_lidSize = 0;
    o_imgInPnor = false;

    do{

        if(!VFS::module_exists(iv_lidFileName))
        {
            //Lid not in extended image
            break;
        }

        // Load the file
        UTIL_DT(INFO_MRK"getLidSizePnor: Try to load %s.", iv_lidFileName);
        errl = VFS::module_load( iv_lidFileName );
        if ( errl )
        {
            //Lid not in extended image
            delete errl;
            errl = NULL;
            break;
        }

        errl = VFS::module_address( iv_lidFileName,
                                    lidAddr,
                                    o_lidSize );
        if ( errl )
        {
            UTIL_FT(ERR_MRK"getLidSizePnor: getting address of file : %s",
                    iv_lidFileName );
            break;
        }
        o_imgInPnor = true;

    }while(0);

    return errl;
}

errlHndl_t UtilLidMgr::getLidPnor(void* i_dest,
                                  size_t i_destSize,
                                  bool& o_imgInPnor)
{
    errlHndl_t errl = NULL;
    const char * lidAddr = NULL;
    size_t lidSize = 0;

    o_imgInPnor = false; //assume not found to start.

    do{
        if(!VFS::module_exists(iv_lidFileName))
        {
            //Lid not in extended image
            break;
        }

        if(!VFS::module_is_loaded(iv_lidFileName))
        {
            // Load the file
            UTIL_DT(INFO_MRK"getLidPnor: Try to load %s.", iv_lidFileName);

            errl = VFS::module_load( iv_lidFileName );
            if ( errl )
            {
                //Lid not in extended image
                delete errl;
                errl = NULL;
                break;
            }
        }

        errl = VFS::module_address( iv_lidFileName,
                                    lidAddr,
                                    lidSize );
        if ( errl )
        {
            UTIL_FT(ERR_MRK"getLidPnor: getting address of file : %s",
                    iv_lidFileName );
            break;
        }
        o_imgInPnor = true;

        if(lidSize > i_destSize)
        {
            UTIL_FT(ERR_MRK"getLidPnor: lid=%s found in Ext image has size=0x%.8X, which does not fit in provided space=0x%.8X",
                    iv_lidFileName, lidSize, i_destSize);

            /*@
             *   @errortype
             *   @moduleid      Util::UTIL_LIDMGR_GETLIDPNOR
             *   @reasoncode    Util::UTIL_LIDMGR_INVAL_SIZE
             *   @userdata1[0:31]     LID size found in Ext Img
             *   @userdata1[32:63]    Reserved space provided
             *   @userdata2     LID ID
             *   @devdesc       Insufficient space provided for LID by calling
             *                 function.
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 Util::UTIL_LIDMGR_GETLIDPNOR,
                                 Util::UTIL_LIDMGR_INVAL_SIZE,
                                 TWO_UINT32_TO_UINT64(lidSize,
                                                      i_destSize),
                                 iv_lidId,
                                 true /*Add HB Software Callout*/);
            break;
        }

        //Copy file to indicated offset.
        memcpy(i_dest, lidAddr, lidSize);

    }while(0);

    return errl;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
errlHndl_t UtilLidMgr::getLid(void* i_dest, size_t i_destSize)
{
    errlHndl_t errl = NULL;
    uint32_t curLid = 0;
    uint16_t pageNumber = 0;
    size_t dataSize = 0;
    size_t transferred_data = 0;
    uint8_t* dataPtr = NULL;
    void* copyOffset = NULL;
    bool img_in_pnor = false;

    do{
        //////////////////////////////////////////////////
        //Check if file is in the PNOR Extended image first.
        //////////////////////////////////////////////////
        errl = getLidPnor(i_dest, i_destSize, img_in_pnor);
        if(errl || img_in_pnor)
        {
            //unexpected error encountered, or found size in PNOR
            //either way, return to caller.
            break;
        }

        //Image not in PNOR, request from FSP.

        errl = createMsgQueue();
        if(errl)
        {
            UTIL_FT(ERR_MRK"getLid: Error while creating message queue.");
            break;
        }

        //Send message to FSP requesting the DMA up the LID in chunks

        // allocate message buffer
        // buffer will be initialized to zero by msg_allocate()
        msg_t * l_pMsg = msg_allocate();

        l_pMsg->type = UTILLID::SEND_TO_HB;

        UTILLID_ADD_LID_ID( iv_lidId, l_pMsg->data[0] );
        UTILLID_ADD_HEADER_FLAG( 0 , l_pMsg->data[0] );
        //change to use TCE Window for improved performance.  RTC: 68295
        UTILLID_ADD_TCE_TOKEN( 0 ,  l_pMsg->data[1] );

        errl = sendMboxMessage( SYNCHRONOUS, l_pMsg );
        if(errl)
        {
            UTIL_FT(ERR_MRK"getLid: Error when calling sendMboxMessage(SYNCHRONOUS)");
            break;
        }

        // see if there was an error on the other end
        UTILLID::UTILLID_RC return_code = UTILLID_GET_RC( l_pMsg->data[0] );

        if ( return_code )
        {
            UTIL_FT(ERR_MRK"getLid: rc 0x%x received from FSP for Sync to HB request",
                    return_code );

            /*@
             *   @errortype
             *   @moduleid      Util::UTIL_LIDMGR_GETLID
             *   @reasoncode    Util::UTIL_LIDMGR_RC_FAIL
             *   @userdata1     return code from FSP
             *   @userdata2     LID ID
             *   @devdesc       The LID transfer code on the FSP side was
             *                  unable to fulfill the LID SEND_TO_HB request.
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 Util::UTIL_LIDMGR_GETLID,
                                 Util::UTIL_LIDMGR_RC_FAIL,
                                 return_code,
                                 iv_lidId);
            errl->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                      HWAS::SRCI_PRIORITY_HIGH);
            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                      HWAS::SRCI_PRIORITY_MED);

            // for a syncronous message we need to free the message
            msg_free( l_pMsg );
            l_pMsg = NULL;
            break;
        }


        //Now wait for FSP to send the LID page-by-page.
        do{
            //Wait for a message
            msg_t * l_pMsg = msg_wait(iv_HbMsgQ);

            //process received message
            if(  UTILLID::PAGE_TO_HB == l_pMsg->type )
            {
                UTIL_DT("getLid: received a page of data");

                curLid = UTILLID_GET_LID_ID(l_pMsg->data[0]);
                pageNumber = UTILLID_GET_PAGE_COUNT(l_pMsg->data[0]);
                dataSize = UTILLID_GET_SIZE(l_pMsg->data[1]);
                dataPtr = reinterpret_cast<uint8_t *> (l_pMsg->extra_data);

                if((curLid != iv_lidId) ||
                   (NULL == dataPtr))
                {
                    UTIL_FT(ERR_MRK"getLid: rc 0x%x received from FSP for Sync to HB request",
                            return_code );

                    /*@
                     *   @errortype
                     *   @moduleid      Util::UTIL_LIDMGR_GETLID
                     *   @reasoncode    Util::UTIL_LIDMGR_INVAL_DATA
                     *   @userdata1[0:31]     received LID ID
                     *   @userdata1[32:63]    expected LID ID
                     *   @userdata2[0:31]     pointer to extra data
                     *   @devdesc       DMA message contains data for wrong LID.
                     */
                    errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                         Util::UTIL_LIDMGR_GETLID,
                                         Util::UTIL_LIDMGR_INVAL_DATA,
                                         TWO_UINT32_TO_UINT64(curLid,
                                                              iv_lidId),
                                         TWO_UINT32_TO_UINT64(
                                            NULL != dataPtr ? *(dataPtr) : 0,
                                                              0)
                                         );

                    errl->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                              HWAS::SRCI_PRIORITY_HIGH);

                    free(l_pMsg->extra_data);
                    l_pMsg->extra_data = NULL;
                    break;
                }


                 //confirm that the data fits in the allocated space
                uint32_t needed_size = ((static_cast<uint32_t>(pageNumber))*
                                        (4*KILOBYTE)) + dataSize;
                if( needed_size > i_destSize )
                {
                    UTIL_FT(ERR_MRK"getLid: rc 0x%x received from FSP for Sync to HB request",
                            return_code );

                    /*@
                     *   @errortype
                     *   @moduleid      Util::UTIL_LIDMGR_GETLID
                     *   @reasoncode    Util::UTIL_LIDMGR_INVAL_SIZE
                     *   @userdata1[0:31]     Allocated Size
                     *   @userdata1[32:63]    Size needed for current data page
                     *   @userdata2[32:63]    Lid ID
                     *   @devdesc       Insufficient space provided for LID by
                     *                  calling function.
                     */
                    errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                         Util::UTIL_LIDMGR_GETLID,
                                         Util::UTIL_LIDMGR_INVAL_SIZE,
                                         TWO_UINT32_TO_UINT64(i_destSize,
                                                              needed_size),
                                         iv_lidId,
                                         true /*Add HB Software Callout*/
                                         );

                    free(l_pMsg->extra_data);
                    l_pMsg->extra_data = NULL;
                    break;

                }
                //copy the page into memory
                copyOffset = (reinterpret_cast<uint8_t *>(i_dest)) + (pageNumber*PAGESIZE);

                memcpy(copyOffset, dataPtr, dataSize);

                transferred_data+=dataSize;

                free(l_pMsg->extra_data);
                l_pMsg->extra_data = NULL;


            } //if UTILLID::PAGE_TO_HB
            else
            {
                UTIL_FT(ERR_MRK"getLid: Invalid Message type (0x%x) received from FSP.",
                        l_pMsg->type );

                /*@
                 *   @errortype
                 *   @moduleid      Util::UTIL_LIDMGR_GETLID
                 *   @reasoncode    Util::UTIL_LIDMGR_UNSUP_MSG
                 *   @userdata1     LID ID
                 *   @userdata2     Message Type
                 *   @devdesc       Invalid Message type received from FSP when
                 *                  transferring LID pages.
                 */
                errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                     Util::UTIL_LIDMGR_GETLID,
                                     Util::UTIL_LIDMGR_UNSUP_MSG,
                                     iv_lidId,
                                     l_pMsg->type);

                errl->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                          HWAS::SRCI_PRIORITY_HIGH);
            }

        }while(transferred_data < iv_lidSize);

        if(errl)
        {
            break;
        }


    }while(0);

    unregisterMsgQueue();

    return errl;
}

errlHndl_t UtilLidMgr::sendMboxMessage( MBOX_MSG_TYPE type,
                                        msg_t * i_msg )
{
    errlHndl_t errl = NULL;

    UTIL_DT("type:  0x%04x",   i_msg->type );
    UTIL_DT("data0: 0x%016llx",i_msg->data[0] );
    UTIL_DT("data1: 0x%016llx",i_msg->data[1] );
    UTIL_DT("extra_data: %p",i_msg->extra_data );

    // determine if its an async message or if we should wait
    // for a response
    if( type == ASYNCHRONOUS )
    {
        UTIL_DT("sendMboxMessage() - sending async mbox msg" );
        errl = MBOX::send( MBOX::FSP_LID_MSGQ, i_msg );
    }
    else
    {
        UTIL_DT("sendMboxMessage() - sending sync mbox msg" );
        errl = MBOX::sendrecv( MBOX::FSP_LID_MSGQ, i_msg );

    }

    if( errl )
    {
        UTIL_FT(ERR_MRK"sendMboxMessage() - failed sending mbox msg" );

        // if the send failed and the message is still valid, check
        // and free the extra data if it exists.
        if( i_msg != NULL && i_msg->extra_data != NULL )
        {
            free( i_msg->extra_data );
        }
    }

    return errl;
}


///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
errlHndl_t UtilLidMgr::createMsgQueue()
{
    errlHndl_t errl = NULL;

    mutex_lock(&cv_mutex);
    iv_needUnlock = true;

    // create Hostboot message queue
    iv_HbMsgQ = msg_q_create();

    // register Hostboot message queue with mailbox to receive messages
    errl = MBOX::msgq_register(MBOX::HB_LID_MSGQ, iv_HbMsgQ);
    if (errl)
    {
        UTIL_FT(ERR_MRK"createMsgQueue() - Error registering message queue" );

        //call unregister to ensure proper cleanup
        unregisterMsgQueue();
    }
    else
    {
        iv_queueRegistered = true;
    }

    return errl;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
void UtilLidMgr::unregisterMsgQueue()
{
    if(iv_queueRegistered)
    {
        // unregister the Hosboot message queue from the mailbox service.
        MBOX::msgq_unregister(MBOX::HB_LID_MSGQ);
        iv_queueRegistered = false;
    }

    if(iv_needUnlock)
    {
        mutex_unlock(&cv_mutex);
        iv_needUnlock = false;
    }
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
errlHndl_t UtilLidMgr::cleanup()
{
    errlHndl_t l_err = NULL;

    iv_lidSize = 0;

    //assert if not unregistered to catch bad code..
    assert(!iv_queueRegistered);

    //make sure we always unload the module
    if (VFS::module_is_loaded(iv_lidFileName))
    {
        l_err = VFS::module_unload( iv_lidFileName );
        if ( l_err )
        {
            UTIL_FT(ERR_MRK"getLidSizePnor: Error unloading module : %s",
                    iv_lidFileName );
        }
    }

    return l_err;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
errlHndl_t UtilLidMgr::setLidId(uint32_t i_lidId)
{
    errlHndl_t l_err = NULL;

    //must call cleanup before updateLid
    l_err = cleanup();

    updateLid(i_lidId);

    return l_err;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
void UtilLidMgr::updateLid(uint32_t i_lidId)
{
    iv_lidId = i_lidId;

    //if it's in PNOR, it's not technically lid, so use a slightly
    //different extension.
    sprintf(iv_lidFileName, "%x.lidbin", iv_lidId);

    return;
}
