/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/utillidmgrdefs.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
/* File utillidmgrdefs.H created by ADAM R. MUHLE on Fri Mar 22 2013. */

/* Change Activity: */
/* End Change Activity */

#ifndef _UTILLIDMGRDEFS_H
#define _UTILLIDMGRDEFS_H

// gets the return code from the uint64_t returned by the mailbox message
#define UTILLID_GET_RC( data0 ) ( static_cast<UTILLID::UTILLID_RC>( \
                        ( data0 & UTILLID::RETURN_CODE_MASK )  >> 48 ))

// used to add the LID ID into the first data word of a
// message - only modifies the first word of the uint64_t
#define UTILLID_ADD_LID_ID( lidId, data0 )  \
                            ( data0 = ( data0 & ~UTILLID::LID_ID_MASK) | \
                            ( static_cast<uint64_t>(lidId) << 32 ) )

// used to add the LID ID into the first data word of a
// message - only modifies the second word of the uint64_t
#define UTILLID_ADD_HEADER_FLAG( headerFlag, data0 )  \
                            ( data0 = ( data0 & ~UTILLID::LID_HEADER_MASK) | \
                            ( static_cast<uint64_t>(headerFlag)  ) )

// used to set TCE TOKEN into data1 of a
// message - only modifies the second word of the uint64_t
#define UTILLID_ADD_TCE_TOKEN( tecToken, data1 )  \
                            ( data1 = ( data1 & ~UTILLID::TCE_TOKEN_MASK) | \
                            ( static_cast<uint64_t>(tecToken)  ) )


// Used to get the LID ID from the first data word of a
// message - only retrieves the first word of the uint64_t
#define UTILLID_GET_LID_ID( data0 ) ( static_cast<uint32_t>( \
                            ( data0 & UTILLID::LID_ID_MASK ) >> 32 ) )

// Used to get the page number of the current LID from the mailbox message.
// The macro will extract the total page count from the last two bytes
// of the data[0] uint64_t in the mailbox message.
#define UTILLID_GET_PAGE_COUNT( data0 ) ( static_cast<uint16_t> ( \
                            ( data0 & UTILLID::PAGE_COUNT_MASK ) ) )

// Used to get the size  passed as part of the  mailbox
// message.  The macro will extract the size from the last word
// of the data uint64_t in the mailbox message.
#define UTILLID_GET_SIZE( data ) ( static_cast<size_t> ( \
                           ( data & UTILLID::SIZE_MASK ) ) )

namespace UTILLID
{

    //*******************************************************************
    // Macros
    //*******************************************************************
    // constants for use in masking off corresponding bytes in message data 
    // words used for LID transfer mbox messages.

    // mask to manipulate the return code field in the data returned in the
    // response to LID related messages
    const uint64_t RETURN_CODE_MASK     = 0xFFFF000000000000;

    // page count mask
    const uint64_t PAGE_COUNT_MASK      = 0x000000000000FFFF;

    // LID ID Mask
    const uint64_t LID_ID_MASK          = 0xFFFFFFFF00000000;

    // LID HEADER Mask
    //     0 -> want LID without header
    //     1 -> request LID with header - NOT currently supported
    const uint64_t LID_HEADER_MASK      = 0x000000000000FFFF;

    // Size mask
    const uint64_t SIZE_MASK            = 0x00000000FFFFFFFF;

    // TCE Token Mask
    //     0 -> Use DMA
    //     != 0 -> Indicates TCE Token to use.
    const uint64_t TCE_TOKEN_MASK       = 0x00000000FFFFFFFF;

    /**
     * @enum UTILLID::MSG_TYPE
     *
     * @brief  Targeting attribute sync service message types for use in the
     *         attribute sync messages between FSP and Hostboot
     */
    enum MSG_TYPE
    {
        //NOTE: Types cannot overlap with typs in attrsyncdefs.H
        //  due to common FSP message queue
        NO_MSG         = 0x00000000,
        GET_INFO       = 0x000000D1,  //HB Request for information about a LID
        SEND_TO_HB     = 0x000000D2,  //HB Request for a LID
        PAGE_TO_HB     = 0x000000D3,  //FSP sending LID Page to HB
     };

    /**
     * @enum UTILLID::UTILLID Return Codes
     *
     * @brief  Return code values LID transfer messages used by Hostboot
     *         and the FSP during communication.
     *
     */
    enum UTILLID_RC
    {
        UTILLID_SUCCESS = 0,
        UTILLID_FAILURE = 1
    };

}; //end UTILLID namespace

#endif /* _UTILLIDMGRDEFS_H */
