/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/targeting/common/attrsyncdefs.H $
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
#ifndef __ATTRSYNC_DEFS_H__
#define __ATTRSYNC_DEFS_H__

//******************************************************************************
// Macros
//******************************************************************************
// constants for use in masking off corresponding bytes in message data words
// used for attribute synchronization mbox messages, sectoin ID and page
// number are used in the sync messages
const uint64_t SECTIONID_MASK       = 0xFFFF000000000000;
const uint64_t PAGE_NUMBER_MASK     = 0x0000FFFF00000000;

// page count mask, used in attribute sync commit message  
const uint64_t PAGE_COUNT_MASK      = 0xFFFF000000000000;

// mask to manipulate the return code field in the data returned in the
// response to an attribute sync commit message
const uint64_t RETURN_CODE_MASK     = 0xFFFF000000000000;


// used to add the section into the first data word of an attribute sync
// message - only modifies the first two bytes of the uint64_t
#define ATTR_SYNC_ADD_SECTION_ID( sectionId, data0 )  \
                            ( data0 = ( data0 & ~SECTIONID_MASK) | \
                            ( static_cast<uint64_t>(sectionId) << 48 ) )

// used to add the number of the current page to by sync'd. used in the
// attribute sync message code. Only modifies the second two bytes 
// of the uint64_t
#define ATTR_SYNC_ADD_PAGE_NUMBER( pageNumber, data0 )    \
                            ( data0 = ( data0 & ~PAGE_NUMBER_MASK) | \
                            ( static_cast<uint64_t>(pageNumber) << 32 ) )

// Used in the commit message sent after all the pages of the current section
// oare sent, the macro will add the total page count to the first two bytes
// of the data[0] uint64_t in the mailbox message.
#define ATTR_SYNC_ADD_PAGE_COUNT( pageCount, data0 ) \
                            ( data0 = ( data0 & ~PAGE_COUNT_MASK) | \
                            ( static_cast<uint64_t>(pageCount) << 48 ) )

// grabs the return code from the uint64_t returned by the mailbox message
#define ATTR_SYNC_GET_RC( data0 ) ( static_cast<ATTR_SYNC_RC>( \
                            ( data0 & RETURN_CODE_MASK )  >> 48 ))

namespace   TARGETING
{
    /**
     * @enum TARGETING::ATTR_SYNC_MSG_TYPE
     *
     * @brief  Targeting attribute sync service message types for use in the
     *         attribute sync messges between FSP and Hostboot
     */
    enum ATTR_SYNC_MSG_TYPE
    {
        ATTR_SYNC_NO_MSG    = 0,
        ATTR_SYNC_SECTION   = 0x000000A1,
        ATTR_SYNC_COMPLETE  = 0x000000A2,
    };


    /**
     * @enum TARGETING::ATTR_SYNC_RC
     *
     * @brief  Return code values for the sync complete message used by HB
     *         and the FSP when the sync has been completed.
     *
     */
    enum ATTR_SYNC_RC
    {
        ATTR_SYNC_SUCCESS = 0,
        ATTR_SYNC_FAILURE = 1
    };

}; // end namespace

#endif
