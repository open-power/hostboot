/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/util/utillidmgr.H $                           */
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
#ifndef _UTILLIDMGR_H
#define _UTILLIDMGR_H

/**
 *  @file util/utillidmgr.H
 *
 *  @brief  Interface to support loading lids into memory.  The utilities are
 *          smart enough to determine if a lid is available in PNOR.  If not,
 *          it will attempt to get the LID from the FSP via mailbox messages.
 */

#include <mbox/mbox_queues.H>
#include <mbox/mboxif.H>
#include <errl/errlentry.H>
#include <sys/msg.h>
#include <pnor/pnorif.H>

namespace Util
{

// Lid Ids
//  A Container Lid can be referred to as a Secure Header. The Container Lid ID
//  is associated with the header data that sits in front of an image.
enum LidId
{
    TEST_LIDID = 0x00000111,
    OCC_LIDID = 0x81e00430,
    OCC_CONTAINER_LIDID = 0x80d0000b,
    MCL_LIDID = 0x80d00020,
    // TODO RTC 172767 Make utillidmgr LIDID structure attribute driven
    WOF_LIDID = 0x81e00440,
    WOF_CONTAINER_LIDID = 0x80d00015,
    // Hcode Reference Image LIDs
    P10_HCODE_LIDID = 0x81e00602,
    HCODE_CONTAINER_LIDID = 0x80d0000c,
    HWREFIMG_RINGOVD_LIDID = 0x81e00620,
    TARGETING_BINARY_LIDID = 0x81e00630,
    NVDIMM_16GB_LIDID = 0x81e00640,
    NVDIMM_32GB_LIDID = 0x81e00641,
    UCD_LIDID = 0x81e00650,

    INVALID_LIDID = 0xFFFFFFFF
};

}

class UtilLidMgr
{
  private:
    /**
     *  @brief Default constructor.
     *
     *  @par Detailed Description
     *      Forcing user to use constructor with input parm/
     */
    UtilLidMgr();


  public:
    /**
     *  @brief Initialize Lid Manager object.
     *
     *  @par Detailed Description
     *      Ensures member variables are initialized to sane values.
     *      Sets the initial LID ID.
     *      Note will shutdown if error occurs during updateLid and not Runtime
     *
     *  @param[in] i_lidId
     *                LID ID.
     *  @param[out] o_errlog (optional)
     *                Pointer to set with error log from constructor.
     *
     */
    explicit UtilLidMgr(uint32_t i_lidId,
                        errlHndl_t* o_errlog = nullptr);

    /**
     *  @brief Destroy the Lid Manager object resources
     *
     *  @par Detailed Description:
     *      Frees any allocated memory
     *
     */
    ~UtilLidMgr();

    /**
     *  @brief  Sets the desired LID ID in an instance variable.
     *
     *  @par Detailed Description:
     *          This is how the user declares which LID they want
     *          to work with.  It can also be used to reset the
     *          object to a different LID Id..
     *
     *  @param[in] i_lidId
     *                   LID ID.
     *
     *  @return     errlHndl_t
     *                  return errl ==  nullptr  -> success
     *                  return errl !=  nullptr  -> failure
     */
    errlHndl_t setLidId(uint32_t i_lidId);

    /**
     *  @brief Get LID Size
     *
     *  @par Detailed Description:
     *          Returns useful LID metrics to the user.  Currently
     *          this is only the size of the LID in bytes.
     *
     *  @param[out] o_lidSize
     *                   Size of the LID in bytes. On BMC systems, this
     *                   will always be zero. In order to find the size
     *                   of the lid on BMC, we need to read it
     *                   (see getLidFromBMC).
     *
     *  @return     errlHndl_t
     *                  return errl ==  nullptr  -> success
     *                  return errl !=  nullptr  -> failure
     */
    errlHndl_t getLidSize(size_t& o_lidSize);

    /**
     *  @brief Get LID
     *
     *  @par Detailed Description:
     *          Gets lid and puts it into space allocated
     *          by the caller.  The caller is required to
     *          allocate the indicated memory space before
     *          calling this function.
     *
     *  @param[in] i_dest
     *          Pointer to where LID should be stored in
     *          hostboot memory
     *
     *  @param[in] i_destSeze
     *          Reserved space in bytes at destintion address
     *          for LID.
     *
     *  @param[out] o_lidSize
     *          The actual size of the lid read (used in the eBMC case)
     *
     *  @return     errlHndl_t
     *                  return errl ==  nullptr  -> success
     *                  return errl !=  nullptr  -> failure
     */
    errlHndl_t getLid(void* i_dest, size_t i_destSize,
                      uint32_t* o_lidSize = nullptr);

    /**
     *  @brief Get Stored LID Image
     *
     *  @par Detailed Description:
     *          Determines if a lid image is stored in hostboot
     *          memory space for this UtilLidMgr object.  If an
     *          image is not stored, then the lid image is stored.
     *          Returns pointer and size for the lid image.
     *
     *  @param[out] o_pLidImage
     *          Pointer to where lid image is stored in hostboot
     *          memory
     *
     *  @param[out] o_lidImageSize
     *          Size of lid image is stored in hostboot memory
     *
     *
     *  @return     errlHndl_t
     *                  return errl ==  nullptr  -> success
     *                  return errl !=  nullptr  -> failure
     */
    errlHndl_t getStoredLidImage(void*& o_pLidImage,
                                 size_t& o_lidImageSize);

    /**
     *  @brief Release LID Image
     *
     *  @par Detailed Description:
     *          Frees memory space allocated for the lid image.
     *          Clears variables associated with storing the image.
     *
     *  @return     errlHndl_t
     *                  return errl ==  nullptr  -> success
     *                  return errl !=  nullptr  -> failure
     */
    errlHndl_t releaseLidImage(void);

#ifdef __HOSTBOOT_RUNTIME
    /**
     * @brief Get a list of LID numbers
     * @param[out] number of entrees in the list
     * @return pointer to the list
     */
    static
        const uint32_t * getLidList(size_t * o_num);
#endif

  protected:

    /**
     *  @brief  Updates the lidId in the object
     *
     *  @par Detailed Description:
     *          Updates the lidId in the object
     *          Also composes the LID filename
     *          This function assumes the lid name is of the format
     *          <uppercase hex>.lidbin
     *          The file is not technically a lid, thus the slightly
     *          different name
     *
     *  @param[in] i_lidId
     *                   LID ID.
     *  @return     errlHndl_t
     *                  return errl ==  nullptr  -> success
     *                  return errl !=  nullptr  -> failure
     */
    errlHndl_t updateLid(uint32_t i_lidId);

    /**
     *  @brief performs object cleanup when a new lidId is set
     *         Function is also called by the destructor.
     */
    errlHndl_t cleanup();

    /**
     * @brief Fetches the lid file from BMC
     *
     * @param[in] i_size the size of lid to request. Passing a size of 0 will
     *            read the file until BMC indicates an end-of-file condition.
     * @param[out] o_dest where to put the returned lid file
     * @param[out] o_actualSize the actual size of the read lid (may not equal
     *             the requested size)
     * @return nullptr on success; non-nullptr on error
     */
    errlHndl_t getLidFromBMC(size_t i_size, void* o_dest,
                             uint32_t& o_actualSize);

#ifndef __HOSTBOOT_RUNTIME
    /**
     * @brief value indicating if lid is in its own pnor partition
     *
     */
    bool iv_isLidInPnor;

    /**
     *  @brief Get LID Size PNOR
     *
     *  @par Detailed Description:
     *          Checks if LID is in Hostboot Ext image and
     *          gets the size from there if available.
     *          This function assumes the lid name is of the format
     *          <uppercase hex>.lidbin
     *          The file is not technically a lid, thus the slightly
     *          different name
     *
     *  @param[out] o_lidSize
     *                   Size of the LID in bytes.
     *
     *  @param[out] o_imgInPnor
     *                   Indicates image was found in PNOR
     *
     *  @return     errlHndl_t
     *                  return errl ==  nullptr  -> success
     *                  return errl !=  nullptr  -> failure
     */
    errlHndl_t getLidSizePnor(size_t& o_lidSize, bool& o_imgInPnor);

    /**
     *  @brief Get LID PNOR
     *
     *  @par Detailed Description:
     *          Gets the LID from the PNOR extended image
     *          if it exists.  The caller is required to
     *          allocate the indicated memory space before
     *          calling this function.
     *          This function assumes the lid name is of the format
     *          <uppercase hex>.lidbin
     *          The file is not technically a lid, thus the slightly
     *          different name
     *
     *  @param[in] i_dest
     *          pointer where LID should be stored in
     *          hostboot memory
     *
     *  @param[in] i_destSeze
     *          Reserved space in bytes at destintion address
     *          for LID.
     *
     *  @param[out] o_imgInPnor
     *                   Indicates image was found in PNOR
     *
     *  @return     errlHndl_t
     *                  return errl ==  nullptr  -> success
     *                  return errl !=  nullptr  -> failure
     */
    errlHndl_t getLidPnor(void* i_dest,
                          size_t i_destSize,
                          bool& o_imgInPnor);

    /**
     * @enum UtilLidMgr::MBOX_MSG_TYPE
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
     *  @brief Create message queue
     *
     *  @par Detailed Description:
     *          Creates LID message queue and registers with mbox.
     *          It also locks the cv_mutex.  This ensures only the
     *            current instance will listen for response messages
     *            from FSP.
     *          Any function that calls this function must also call
     *            unregisterMsgQueue() to free the queue and unlock
     *            the mutex.
     *
     *  @return     errlHndl_t
     *                  return errl ==  nullptr  -> success
     *                  return errl !=  nullptr  -> failure
     */
    errlHndl_t createMsgQueue();

    /**
     *  @brief Unregister Msg Queue
     *
     *  @par Detailed Description:
     *          Unregisters LID msg queue with mbox
     */
    void unregisterMsgQueue();

    /**
     *  @brief  Uses the internal mailbox to send a message to the FSP
     *
     *
     *  @par Detailed Description:
     *          This funciton will call into mailboxsp code using the
     *          UtilLidMgr as a target message queue..
     *
     *  @param[in] i_type
     *           ::MBOX_MSG_TYPE passed in to define the
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
     *                  return errl ==  nullptr  -> success
     *                  return errl !=  nullptr  -> failure
     */
    errlHndl_t  sendMboxMessage( MBOX_MSG_TYPE i_type, msg_t * i_msg  );

    /**
     * @brief Mutex to prevent concurrent LID operations.
     *     This needs to be static so we can mutex across multiple instances
     */
    static mutex_t cv_mutex;

    /**
     * @brief Keep track of mutex state
     */
    bool iv_needUnlock;

    /**
     * @brief Keep track of Msg queue registered state
     */
    bool iv_queueRegistered;

    /**
     * @brief Pointer to message queue
     */
    msg_q_t iv_HbMsgQ;

    /**
     * @brief pointer to buffer with image of current LID
     */
    void* iv_pLidImage;

    /**
     * @brief size of buffer with image of current LID
     */
    size_t iv_lidImageSize;


#else // __HOSTBOOT_RUNTIME

    /**
     * @brief Loads the LID using the Host interfaces.
     */
    errlHndl_t loadLid();

    /**
     * @brief Pointer to the buffer containing the LID.
     */
    void* iv_lidBuffer;

    /**
     *  @brief Indicates that a lid is pre-verified in HbResvMem
     *
     *  @param[in] i_section - Lid Id
     *
     *  @return bool - True if lid is in HB reserved memory, false otherwise
    */
    bool lidInHbResvMem(uint32_t i_lidId) const;

#endif // __HOSTBOOT_RUNTIME

    /**
     *  @brief Determines if a Lid Id has a corresponding PNOR section ID
     *         and sets PNOR info if it exists
     *
     *  @param[in] i_lidId          - lid id to search for
     *  @param[out] o_lidPnorInfo   - pnor section info associated with the lid
     *                                if it exists in pnor
     *  @param[out] o_isLidInPnor   - True if lid is in a section, false otherwise
     *
     *  @return     errlHndl_t
     *                  return errl ==  nullptr  -> success
     *                  return errl !=  nullptr  -> failure
    */
    errlHndl_t getLidPnorSectionInfo(uint32_t i_lidId,
                                     PNOR::SectionInfo_t &o_lidPnorInfo,
                                     bool &o_isLidInPnor);
    /**
     * @brief LID fileName
     */
    char iv_lidFileName[16];

    /**
     * @brief current LID ID
     */
    uint32_t iv_lidId;

    /**
     * @brief reported size of current LID
     */
    size_t iv_lidSize;

    /**
     * @brief pnor section (other than ext img) current lid is in
     *        PNOR::INVALID_SECTION if not in other sections
     */
    PNOR::SectionInfo_t iv_lidPnorInfo;

    /**
     * @brief value indicating if a fsp exists
     */
    bool iv_spBaseServicesEnabled;

    /**
     * @brief value indicating if lid is in extended image
     */
    bool iv_isLidInVFS;

    /**
     * @brief value indicating if lid is in hostboot reserved memory
     */
    bool iv_isLidInHbResvMem;

};

#endif /* _UTILLIDMGR_H */

