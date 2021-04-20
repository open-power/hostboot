/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/utillidmgr.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2021                        */
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

#include <util/utillidmgr.H>
#include <util/util_reasoncodes.H>
#include <util/utiltce.H>
#include <vfs/vfs.H>
#include <stdio.h>
#include <assert.h>

#include <errl/errlmanager.H>
#include "utillidmgrdefs.H"
#include "utilbase.H"
#include <initservice/initserviceif.H>
#include <initservice/istepdispatcherif.H>
#include <sys/mm.h>
#include <util/align.H>

#ifdef CONFIG_SECUREBOOT
#include <pnor/pnorif.H>
#include <secureboot/service.H>
#endif

#include <pldm/requests/pldm_fileio_requests.H>

using namespace ERRORLOG;
mutex_t UtilLidMgr::cv_mutex = MUTEX_INITIALIZER;

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
UtilLidMgr::UtilLidMgr(uint32_t i_lidId,
                       errlHndl_t* o_errlog)
: iv_needUnlock(false)
,iv_queueRegistered(false)
,iv_HbMsgQ(nullptr)
,iv_pLidImage(nullptr)
,iv_lidImageSize(0)
,iv_lidSize(0)
{
    errlHndl_t l_err = nullptr;

    do {
        iv_spBaseServicesEnabled = INITSERVICE::spBaseServicesEnabled();
        l_err = updateLid(i_lidId);
        if (l_err)
        {
            UTIL_FT(ERR_MRK"UtilLidMgr::UtilLidMgr() Failed to update Lid (0x%X)",
                    i_lidId);
            break;
        }
    } while(0);

    if( l_err )
    {
        l_err->collectTrace(UTIL_COMP_NAME);
        // If the user is just querying the lid then we might not want
        //  to shut the whole system down
        if( o_errlog )
        {
            *o_errlog = l_err;
        }
        else
        {
            uint32_t l_reasoncode = l_err->reasonCode();
            errlCommit(l_err,UTIL_COMP_ID);
            UTIL_FT("Shutting down due to rc=0x%08X", l_reasoncode);
            INITSERVICE::doShutdown(l_reasoncode);
        }
        iv_lidId = Util::INVALID_LIDID;
    }

}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
UtilLidMgr::~UtilLidMgr()
{
    errlHndl_t l_err = nullptr;

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
    errlHndl_t errl = nullptr;
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
        if (iv_spBaseServicesEnabled)
        {
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
            UTILLID::UTILLID_RC return_code = UTILLID_GET_RC(l_pMsg->data[0]);

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
                l_pMsg = nullptr;
                break;
            }

            // Get the LID Size
            iv_lidSize = UTILLID_GET_SIZE( l_pMsg->data[0] );

            o_lidSize = iv_lidSize;

            // for a syncronous message we need to free the message
            msg_free( l_pMsg );
            l_pMsg = nullptr;
        }
        else
        {
            UTIL_FT(INFO_MRK"getLidSize: lid's 0x%08x size will be determined by reading it from BMC until it signals the end of the file",
                   iv_lidId);
        }

    }while(0);

    return errl;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
errlHndl_t UtilLidMgr::getLidSizePnor(size_t& o_lidSize, bool& o_imgInPnor)
{
    errlHndl_t errl = nullptr;
    const char * lidAddr = nullptr;

    o_lidSize = 0;
    o_imgInPnor = false;

    do{
        if (iv_isLidInPnor)
        {
            o_lidSize = iv_lidPnorInfo.size;
        }
        else if (iv_isLidInVFS)
        {
            // Load the file
            UTIL_DT(INFO_MRK"getLidSizePnor: Try to load %s.", iv_lidFileName);
            errl = VFS::module_load( iv_lidFileName );
            if ( errl )
            {
                //Lid not in extended image
                delete errl;
                errl = nullptr;
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
        }
        else
        {
            // Lid is not in extended image or other pnor sections
            break;
        }
        o_imgInPnor = true;

    }while(0);

    return errl;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
errlHndl_t UtilLidMgr::getLidPnor(void* i_dest,
                                  size_t i_destSize,
                                  bool& o_imgInPnor)
{
    errlHndl_t errl = nullptr;
    const char * lidAddr = nullptr;
    size_t lidSize = 0;

    o_imgInPnor = false; //assume not found to start.

    do{
        if(iv_isLidInPnor)
        {
            lidSize = iv_lidPnorInfo.size;
            lidAddr = reinterpret_cast<char *>(iv_lidPnorInfo.vaddr);
        }
        else if (iv_isLidInVFS)
        {
            if(!VFS::module_is_loaded(iv_lidFileName))
            {
                // Load the file
                UTIL_DT(INFO_MRK"getLidPnor: Try to load %s.", iv_lidFileName);

                errl = VFS::module_load( iv_lidFileName );
                if ( errl )
                {
                    //Lid not in extended image
                    delete errl;
                    errl = nullptr;
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
        }
        else
        {
            // Lid is not in extended image or other pnor sections
            break;
        }

        o_imgInPnor = true;

        if(lidSize > i_destSize)
        {
            if (iv_isLidInPnor)
            {
                UTIL_FT(ERR_MRK"getLidPnor: lid=%s in PNOR::%s has size=0x%.8X, which does not fit in provided space=0x%.8X",
                        iv_lidFileName, iv_lidPnorInfo.name, lidSize,
                        i_destSize);

                /*@
                 *   @errortype
                 *   @moduleid      Util::UTIL_LIDMGR_GETLIDPNOR
                 *   @reasoncode    Util::UTIL_LIDMGR_INVAL_SIZE_PNOR
                 *   @userdata1[0:31]     LID size found in pnor
                 *   @userdata1[32:63]    Reserved space provided
                 *   @userdata2     LID ID
                 *   @devdesc       Insufficient space provided for LID by calling
                 *                  function.
                 */
                errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                     Util::UTIL_LIDMGR_GETLIDPNOR,
                                     Util::UTIL_LIDMGR_INVAL_SIZE_PNOR,
                                     TWO_UINT32_TO_UINT64(lidSize,
                                                          i_destSize),
                                     iv_lidId,
                                     true /*Add HB Software Callout*/);
                break;
            }
            else
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
        }
        //Copy file to indicated offset.
        memcpy(i_dest, lidAddr, lidSize);

    }while(0);

    return errl;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
errlHndl_t UtilLidMgr::getLid(void* i_dest, size_t i_destSize,
                              uint32_t* o_lidSize)
{
    errlHndl_t errl = nullptr;
    uint32_t curLid = 0;
    uint16_t pageNumber = 0;
    size_t dataSize = 0;
    size_t transferred_data = 0;
    uint8_t* dataPtr = nullptr;
    void* copyOffset = nullptr;
    bool img_in_pnor = false;
    bool use_tces = 0;
    bool tces_allocated = false;
    uint32_t tceToken = 0;
    uint32_t dmaAddr = 0;
    void* tceStartAddr = nullptr;
    uint64_t tceSize = 0;

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
        if(iv_spBaseServicesEnabled)
        {
            use_tces = TCE::utilUseTcesForDmas();

            // If using TCEs, setup TCE Table for FSP to use
            if (use_tces)
            {
                // Assume caller passed in Virtual Address that was already
                // backed to Physical Memory
                UTIL_FT("getLid: requesting TCEs for i_dest=0x%.16llX, i_destSize=0x%X (lidId=0x%X)", i_dest, i_destSize, iv_lidId);

                // Need to Allocate TCEs on Page-Aligned Memory
                size_t i_dest_remainder = reinterpret_cast<uint64_t>(i_dest)
                                          % PAGESIZE;

                if (i_dest_remainder != 0)
                {
                    tceStartAddr = reinterpret_cast<void*>(
                                     ALIGN_PAGE_DOWN(reinterpret_cast<uint64_t>(i_dest)));
                    tceSize = i_destSize + i_dest_remainder;
                    UTIL_DT("getLid: requesting non-page-aligned i_dest (%p): adjusted TCE tceStartAddr = %p, tceSize=0x%X", i_dest, tceStartAddr, tceSize);
                }
                else
                {
                    tceStartAddr = i_dest;
                    tceSize = i_destSize;
                }

                errl = TCE::utilAllocateTces(mm_virt_to_phys(tceStartAddr),
                                             tceSize,
                                             tceToken);
                if(errl)
                {
                    UTIL_FT(ERR_MRK"getLid: Error while allocating TCEs.");
                    break;
                }
                tces_allocated = true;

                // Update dmaAddr that FSP needs to use, if necessary
                dmaAddr = tceToken + i_dest_remainder;
                UTIL_DT("getLid: got back tceToken=0x%.16llX. DMA_Addr=0x%.16llX", tceToken, dmaAddr);
            }

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
            UTILLID_ADD_TCE_TOKEN( dmaAddr ,  l_pMsg->data[1] );

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
                l_pMsg = nullptr;
                break;
            }

            // In TCE Mode FSP DMAs the entire LID before returning synchronus
            // message above with the SEND_TO_HB message type
            if (use_tces && (l_pMsg->type == UTILLID::SEND_TO_HB))
            {
                UTIL_DT("getLid: Using TCEs and got back UTILLID::SEND_TO_HB: transfer complete");
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
                       (nullptr == dataPtr))
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
                                                nullptr != dataPtr?*(dataPtr):0,
                                                                  0)
                                             );

                        errl->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                                  HWAS::SRCI_PRIORITY_HIGH);

                        free(l_pMsg->extra_data);
                        l_pMsg->extra_data = nullptr;
                        break;
                    }


                     //confirm that the data fits in the allocated space
                    uint32_t needed_size = ((static_cast<uint32_t>(pageNumber))*
                                            (4*KILOBYTE)) + dataSize;
                    if( needed_size > i_destSize )
                    {
                        UTIL_FT(ERR_MRK"getLid: lid=%s has size=0x%.8X, which does not fit in provided space=0x%.8X",
                            iv_lidFileName, i_destSize, needed_size);

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
                        l_pMsg->extra_data = nullptr;
                        break;

                    }
                    //copy the page into memory
                    copyOffset = (reinterpret_cast<uint8_t *>(i_dest)) + (pageNumber*PAGESIZE);

                    memcpy(copyOffset, dataPtr, dataSize);

                    transferred_data+=dataSize;

                    free(l_pMsg->extra_data);
                    l_pMsg->extra_data = nullptr;


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
                     *   @devdesc       Invalid Message type received from FSP
                     *                  when transferring LID pages.
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
        } // iv_spBaseServicesEnabled
        else
        {
#ifdef CONFIG_PLDM

            // Send the progres code (reset the watchdog), since it may take a
            // while to fetch a lid from BMC
            INITSERVICE::sendProgressCode();

            uint32_t l_reportedLidSize = 0;
            // We don't know the exact size of the lid, so we will have to rely
            // on BMC to tell us how big the lid is. However, we can still limit
            // the size by the amount of space left in the memory we reserved
            // for lids (i_destSize).
            errl = getLidFromBMC(i_destSize, i_dest, l_reportedLidSize);
            if(errl)
            {
                UTIL_FT(ERR_MRK"getLid: could not get lid 0x%08x from BMC!",
                        iv_lidId);
                break;
            }
            if(o_lidSize)
            {
                *o_lidSize = l_reportedLidSize;
            }
#else
            // Weird scenario. Invalidate the output size.
            if(o_lidSize)
            {
                *o_lidSize = 0;
            }
#endif
        }
        if(errl)
        {
            break;
        }
    }while(0);

    // If TCEs were allocated previously, deallocate them here
    if (tces_allocated)
    {
        // Use Preverification Location and Size
        auto tce_errl = TCE::utilDeallocateTces(tceToken);

        if(tce_errl)
        {
            UTIL_FT(ERR_MRK"getLid: Error while deallocating TCEs.");

            if (errl)
            {
                // Commit tce_errl here and original error will be passed back
                tce_errl->collectTrace(UTIL_COMP_NAME);
                errlCommit( tce_errl, UTIL_COMP_ID );
            }
            else
            {
                // Set errl to tce_errl
                errl = tce_errl;
                tce_errl = nullptr;
            }
        }
    }

    if (iv_spBaseServicesEnabled)
    {
        unregisterMsgQueue();
    }

    return errl;
}

errlHndl_t UtilLidMgr::getLidFromBMC(size_t i_size, void* o_dest,
                                     uint32_t& o_actualSize)
{
    errlHndl_t l_errl = nullptr;
    UTIL_FT(ENTER_MRK"getLidFromBMC: getting lid 0x%08x of size 0x%08x",
            iv_lidId, i_size);
#ifdef CONFIG_PLDM
    uint32_t l_lidSize = 0;

    do {
    uint8_t* l_dest = reinterpret_cast<uint8_t*>(o_dest);
    l_errl = PLDM::getLidFile(iv_lidId, l_lidSize, l_dest);
    if(l_errl)
    {
        UTIL_FT(ERR_MRK"getLidFromBMC: Could not get lid 0x%08x from BMC!",
                iv_lidId);
        break;
    }

    if(l_lidSize > i_size)
    {
        /*@
         * @errortype
         * @moduleid         Util::UTIL_LIDMGR_GET_LID_BMC
         * @reasoncode       Util::UTIL_LIDMGR_LID_TOO_BIG
         * @userdata1        LID ID
         * @userdata2[0:31]  Requested lid size
         * @userdata2[32:63] Lid size returned by BMC
         * @devdesc BMC returned a lid of size larger than the size of lid's
         *          destination
         * @custdesc A host failure occurred
         */
        l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                               Util::UTIL_LIDMGR_GET_LID_BMC,
                               Util::UTIL_LIDMGR_LID_TOO_BIG,
                               iv_lidId,
                               TWO_UINT32_TO_UINT64(
                                    static_cast<uint32_t>(i_size),
                                    l_lidSize),
                               ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(UTIL_COMP_NAME);
        break;
    }
    o_actualSize = l_lidSize;
    }while(0);
#else
    // Weird scenario. Invalidate the actual size read
    o_actualSize = 0;
#endif
    UTIL_FT(EXIT_MRK"getLidFromBMC: lid 0x%08x; actual size: 0x%08x",
            iv_lidId, o_actualSize);
    return l_errl;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
errlHndl_t UtilLidMgr::getStoredLidImage(void*& o_pLidImage,
                                         size_t& o_lidImageSize)
{
    errlHndl_t errl = nullptr;

    if((iv_pLidImage != nullptr) && (iv_lidImageSize != 0))
    {
        o_pLidImage = iv_pLidImage;
        o_lidImageSize = iv_lidImageSize;
    }
    else
    {
        errl = updateLid(iv_lidId);
        if(0 == iv_lidImageSize && errl == nullptr)
        {
            errl = getLidSize(iv_lidImageSize);
        }

        if(errl == nullptr)
        {
            if(iv_pLidImage != nullptr)
            {
                free(iv_pLidImage);
            }

            iv_pLidImage = static_cast<void*>(malloc(iv_lidImageSize));

            errl = getLid(iv_pLidImage, iv_lidImageSize);
        }

        if(errl)
        {
            cleanup();
        }

        o_pLidImage = iv_pLidImage;
        o_lidImageSize = iv_lidImageSize;
    }

    return errl;
}


///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
errlHndl_t UtilLidMgr::releaseLidImage(void)
{
    errlHndl_t errl = cleanup();

    return errl;
}


errlHndl_t UtilLidMgr::sendMboxMessage( MBOX_MSG_TYPE type,
                                        msg_t * i_msg )
{
    errlHndl_t errl = nullptr;

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
        if( i_msg != nullptr && i_msg->extra_data != nullptr )
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
    errlHndl_t errl = nullptr;

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
    errlHndl_t l_err = nullptr;

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

    //force evict any pages that the PNOR RP might have
    // laying around
    if(iv_isLidInPnor)
    {
        bool skip_remove_pages = false;

#ifdef CONFIG_SECUREBOOT
#ifndef __HOSTBOOT_RUNTIME
        // If in SECUREBOOT the lid could be securely signed in PNOR (like OCC)
        // If so, unload it securely below rather than call mm_remove_pages
        if (iv_lidPnorInfo.secure)
        {
            skip_remove_pages = true;
        }
#endif
#endif

        if (skip_remove_pages == false)
        {
            int rc = mm_remove_pages( RELEASE,
                                      reinterpret_cast<void *>(
                                        iv_lidPnorInfo.vaddr),
                                      iv_lidPnorInfo.size );
            if( rc )
            {
                UTIL_FT( ERR_MRK"rc=%d from mm_remove_pages(%llX,%llX)", iv_lidPnorInfo.vaddr, iv_lidPnorInfo.size );
                /*@
                 *   @errortype
                 *   @moduleid      Util::UTIL_LIDMGR_CLEANUP
                 *   @reasoncode    Util::UTIL_LIDMGR_MM_FAIL
                 *   @userdata1[00:31]  LID ID
                 *   @userdata1[32:63]  rc from mm_remove_pages
                 *   @userdata2     Virtual address being removed
                 *   @devdesc       Error returned from mm_remove_pages
                 *                  when evicting lid from memory.
                 *   @custdesc      Firmware error during boot.
                 */
                l_err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                      Util::UTIL_LIDMGR_CLEANUP,
                                      Util::UTIL_LIDMGR_MM_FAIL,
                                      TWO_UINT32_TO_UINT64(iv_lidId,rc),
                                      iv_lidPnorInfo.vaddr,
                                      true /*sw fail*/);
            }
        }

#ifdef CONFIG_SECUREBOOT
        // If in SECUREBOOT the lid could be securely signed in PNOR (like OCC)
        // If so, unload it securely
        bool l_doUnload = (iv_lidPnorInfo.size != 0);

        if (iv_lidPnorInfo.secure && l_doUnload)
        {
            l_err = PNOR::unloadSecureSection(iv_lidPnorInfo.id);

            if (l_err)
            {
                UTIL_FT(ERR_MRK"UtilLidMgr::cleanup: Error from "
                               "unloadSecureSection(0x%X): "
                               "unloading module : %s (id=0x%X)",
                               iv_lidPnorInfo.id, iv_lidFileName, iv_lidId);
            }
            else
            {
                iv_lidPnorInfo.size = 0;
            }
        }
#endif

    }

    if(iv_pLidImage != nullptr)
    {
        free(iv_pLidImage);
        iv_pLidImage = nullptr;
    }

    iv_lidImageSize = 0;

    return l_err;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
errlHndl_t UtilLidMgr::setLidId(uint32_t i_lidId)
{
    errlHndl_t l_err = nullptr;

    do {
    //must call cleanup before updateLid
    l_err = cleanup();
    if (l_err)
    {
        break;
    }

    l_err = updateLid(i_lidId);
    if (l_err)
    {
        break;
    }
    } while(0);

    return l_err;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
errlHndl_t UtilLidMgr::updateLid(uint32_t i_lidId)
{
    iv_lidId = i_lidId;
    errlHndl_t l_err = nullptr;

    do {

    //if it's in PNOR, it's not technically lid, so use a slightly
    //different extension.
    sprintf(iv_lidFileName, "%x.lidbin", iv_lidId);
    l_err = getLidPnorSectionInfo(iv_lidId, iv_lidPnorInfo, iv_isLidInPnor);
    if (l_err)
    {
        UTIL_FT("UtilLidMgr::updateLid - getLidPnorSectionInfo failed");
        break;
    }
    UTIL_DT(INFO_MRK "UtilLidMgr: LID 0x%.8X in pnor: %d",
              iv_lidId ,iv_isLidInPnor);
    iv_isLidInVFS = VFS::module_exists(iv_lidFileName);
    } while(0);

    return l_err;
}

