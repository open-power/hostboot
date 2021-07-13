/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/accessors/p10_mvpd_ring_funcs.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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
// $Id: p9_mvpd_ring_funcs.C,v 1.12 2014/07/16 19:06:49 cswenson Exp $
//
//  @file p9_mvpd_ring_funcs.C
//
//  @brief Common Mvpd access routines
//
//  @brief fetch repair rings from MVPD  records
//
//  *HWP HWP Owner: Mike Olsen <cmolsen@us.ibm.com>
//  *HWP HWP Backup Owner: Sumit Kumar <sumit_kumar@in.ibm.com>
//  *HWP Team: Infrastructure
//  *HWP Level: 3
//  *HWP Consumed by: HOSTBOOT, CRONUS
//

#include  <stdint.h>

#include  <fapi2.H>
#include  <utils.H>
#include  <mvpd_access.H>
#include  <p10_mvpd_ring_funcs.H>
#include  <p10_scan_compression.H>
#include  <p10_ringId.H>
#include  <p10_ipl_customize.H>

extern "C"
{

    using   namespace   fapi2;

// functions internal to this file
// these functions are common for both mvpdRingFunc and mbvpdRingFunc
    fapi2::ReturnCode mvpdValidateRingHeader( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            & i_fapiTarget,
            CompressedScanData* i_pRing,
            uint32_t            i_chipletSel,
            RingId_t            i_ringId,
            uint32_t            i_ringBufsize);

    fapi2::ReturnCode mvpdRingFuncFind( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                                        & i_fapiTarget,
                                        fapi2::MvpdRecord    i_record,
                                        fapi2::MvpdKeyword   i_keyword,
                                        const uint32_t  i_chipletSel,
                                        const RingId_t  i_ringId,
                                        uint8_t*        i_pRecordBuf,
                                        uint32_t        i_recordBufLenfapi,
                                        uint8_t*&       o_rRingBuf,
                                        uint32_t&       o_rRingBufsize);

    fapi2::ReturnCode mvpdRingFuncGet( uint8_t*     i_pRing,
                                       uint32_t     i_ringLen,
                                       uint8_t*     i_pCallerRingBuf,
                                       uint32_t&    io_rCallerRingBufLen);

    fapi2::ReturnCode mvpdRingFuncSet( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                                       & i_fapiTarget,
                                       fapi2::MvpdRecord    i_record,
                                       fapi2::MvpdKeyword   i_keyword,
                                       uint8_t*     i_pRecordBuf,
                                       uint32_t     i_recordLen,
                                       uint8_t*     i_pRing,
                                       uint32_t     i_ringLen,
                                       uint8_t*     i_pCallerRingBuf,
                                       uint32_t     i_callerRingBufLen);

// add record/keywords with rings with RS4 header here.
    struct _supportedRecordKeywords
    {
        fapi2::MvpdRecord record;
        fapi2::MvpdKeyword keyword;
    } supportedRecordKeywords [] =
    {
        { MVPD_RECORD_CP00, MVPD_KEYWORD_PDR },
        { MVPD_RECORD_CP00, MVPD_KEYWORD_PDG },
        { MVPD_RECORD_CP00, MVPD_KEYWORD_PDS },
    };

    /**
     *  @brief Validate Record and Keyword Combination
     *
     *  @par Detailed Description:
     *           Check for supported combinations of Record and Keyword.
     *           The record needs to contain rings of RS4 header
     *           (CompressedScanData) format.
     *
     *  @param[in]  i_fapiTarget
     *                   FAPI proc chip target
     *
     *  @param[in]  i_record
     *                   Record to validate
     *
     *  @param[in]  i_keyword
     *                   Keyword to validate
     *
     *  @note:  "Getting" data not in RS4 header format would likely just
     *          fail to find the ring harmlessly.  "Setting" data could
     *          make a mess looking for the end to append a new ring. The
     *          result could be invalid vpd.
     *
     *  @return     fapi2::ReturnCode
     */
    fapi2::ReturnCode mvpdValidateRecordKeyword(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
        & i_fapiTarget,
        fapi2::MvpdRecord   i_record,
        fapi2::MvpdKeyword  i_keyword )
    {
        bool l_validPair = false;
        const uint32_t numPairs =
            sizeof(supportedRecordKeywords) / sizeof(supportedRecordKeywords[0]);

        for (uint32_t curPair = 0; curPair < numPairs; curPair++ )
        {
            if (supportedRecordKeywords[curPair].record == i_record &&
                supportedRecordKeywords[curPair].keyword == i_keyword)
            {
                l_validPair = true;
                break;
            }
        }

        FAPI_ASSERT( l_validPair,
                     fapi2::MVPD_RING_FUNC_INVALID_RECORD_KEYWORD_PAIR().
                     set_CHIP_TARGET(i_fapiTarget).
                     set_MVPD_RECORD(i_record).
                     set_MVPD_KEYWORD(i_keyword),
                     "The Mvpd record and keyword don't match up: "
                     "record==0x%x, keyword=0x%x",
                     i_record,
                     i_keyword );

    fapi_try_exit:
        return fapi2::current_err;
    };


    /**
     *  @brief MVPD Ring Function
     *
     *  @par Detailed Description:
     *           The getMvpdRing and setMvpdRing wrappers call this function
     *           to do all the processing.
     *
     *  @param[in]  i_fapiTarget
     *                   FAPI proc chip target for the op
     *
     *  @param[in]  i_mvpdRingFuncOp
     *                   MVPD ring function op to process
     *
     *  @param[in]  i_record
     *                   Record in the MVPD
     *
     *  @param[in]  i_keyword
     *                   Keyword for the MVPD record
     *
     *  @param[in]  i_chipletSel
     *                   Chiplet Select for the op
     *
     *  @param[in]  i_ringId
     *                   Ring ID for the op
     *
     *  @param[out] o_pRingBuf
     *                   Pointer to ring buffer with set data
     *
     *  @param[in/out]  io_rRingBufsize
     *                   Size of ring buffer
     *
     *  @note:      io_rRingBufsize is only an 'output' for get function.
     *
     *  @return     fapi2::ReturnCode
     */
    fapi2::ReturnCode mvpdRingFunc( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                                    & i_fapiTarget,
                                    const mvpdRingFuncOp i_mvpdRingFuncOp,
                                    fapi2::MvpdRecord    i_record,
                                    fapi2::MvpdKeyword   i_keyword,
                                    const uint32_t       i_chipletSel,
                                    const RingId_t       i_ringId,
                                    uint8_t*             o_pRingBuf,
                                    uint32_t&            io_rRingBufsize )
    {
        fapi2::ReturnCode       l_fapirc = fapi2::FAPI2_RC_SUCCESS;
        uint32_t                l_recordLen  = 0;
        uint8_t*                l_recordBuf  = NULL;
        uint8_t*                l_pRing      = NULL;
        uint32_t                l_ringLen    = 0;

        FAPI_DBG("mvpdRingFunc: Called w/op=0x%x, ringId=0x%x, chipletSel=0x%08x, "
                 "size=0x%x",
                 i_mvpdRingFuncOp,
                 i_ringId,
                 i_chipletSel,
                 io_rRingBufsize  );

        // do common get and set input parameter error checks
        // check for supported combination of Record and Keyword
        FAPI_TRY(mvpdValidateRecordKeyword( i_fapiTarget,
                                            i_record,
                                            i_keyword ),
                 "mvpdRingFunc: unsupported record keyword pair "
                 "record=0x%x, keyword=0x%x",
                 i_record,
                 i_keyword);

        // do set specific input parameter checks
        if (i_mvpdRingFuncOp == MVPD_RING_SET )
        {
            // passing NULL pointer to receive needed size is only for get.
            FAPI_ASSERT(o_pRingBuf != NULL,
                        fapi2::MVPD_RING_FUNC_NULL_POINTER().
                        set_CHIP_TARGET(i_fapiTarget).
                        set_RING_ID(i_ringId).
                        set_CHIPLET_SEL(i_chipletSel),
                        "mvpdRingFunc(SET): NULL ring buffer pointer passed "
                        "to SET function for chipletSel=0x%08x, ringId=0x%x",
                        i_chipletSel,
                        i_ringId);

            // Validate ring header to protect Mvpd
            FAPI_TRY(mvpdValidateRingHeader(
                         i_fapiTarget,
                         reinterpret_cast<CompressedScanData*>(o_pRingBuf),
                         i_chipletSel,
                         i_ringId,
                         io_rRingBufsize),
                     "mvpdRingFunc: invalid ring header "
                     "chipletSel=0x%08x, ringId=0x%x",
                     i_chipletSel,
                     i_ringId);
        }

        //  call getMvpdField once with a NULL pointer to get the buffer
        //  size no error should be returned.
        FAPI_TRY(getMvpdField(i_record,
                              i_keyword,
                              i_fapiTarget,
                              NULL,
                              l_recordLen ),
                 "mvpdRingFunc: getMvpdField failed to get buffer size for "
                 "record=0x%x, keyword=0x%x and ringId=0x%x",
                 i_record,
                 i_keyword,
                 i_ringId);

        FAPI_DBG( "mvpdRingFunc: getMvpdField returned record len=0x%x",
                  l_recordLen );

        //  allocate buffer for the record. Always works
        l_recordBuf =  static_cast<uint8_t*>(malloc((size_t)l_recordLen));

        //  load ring from MVPD for this target
        FAPI_TRY(getMvpdField(i_record,
                              i_keyword,
                              i_fapiTarget,
                              l_recordBuf,
                              l_recordLen ),
                 "mvpdRingFunc: getMvpdField failed to get the buffer for "
                 "record=0x%x, keyword=0x%x and ringId=0x%x",
                 i_record,
                 i_keyword,
                 i_ringId);

        // find ring in the record. It is an error if not there for a "get".
        // Its ok if not there for a "set". The ring will be added.
        // l_ringLen set to 0 if not there with l_pRing at the start of padding.
        FAPI_TRY(mvpdRingFuncFind(i_fapiTarget,
                                  i_record,
                                  i_keyword,
                                  i_chipletSel,
                                  i_ringId,
                                  l_recordBuf,
                                  l_recordLen,
                                  l_pRing,
                                  l_ringLen),
                 "mvpdRingFunc: mvpdRingFuncFind failed "
                 "chipletSel=0x%08x, ringId=0x%x",
                 i_chipletSel,
                 i_ringId);

        // do the get or set specific operations
        if (i_mvpdRingFuncOp == MVPD_RING_GET ) // do the get operation
        {
            // Ensure ring was found. Must be there for "get"
            if (l_ringLen == 0)
            {
                fapi2::current_err = RC_MVPD_RING_NOT_FOUND;
                goto fapi_try_exit;
            }

            // copy ring back to caller's buffer
            FAPI_TRY(mvpdRingFuncGet(l_pRing,
                                     l_ringLen,
                                     o_pRingBuf,
                                     io_rRingBufsize),
                     "mvpdRingFunc: mvpdRingFuncGet failed "
                     "chipletSel=0x%08x, ringId=0x%x",
                     i_chipletSel,
                     i_ringId);
        }
        else         // set operation
        {
            // update record with caller's ring
            FAPI_TRY(mvpdRingFuncSet(i_fapiTarget,
                                     i_record,
                                     i_keyword,
                                     l_recordBuf,
                                     l_recordLen,
                                     l_pRing,
                                     l_ringLen,
                                     o_pRingBuf,
                                     io_rRingBufsize),
                     "mvpdRingFunc: mvpdRingFuncSet failed "
                     "chipletSel=0x%08x, ringId=0x%x",
                     i_chipletSel,
                     i_ringId);

            // update record back to the mvpd
            FAPI_TRY(setMvpdField(i_record,
                                  i_keyword,
                                  i_fapiTarget,
                                  l_recordBuf,
                                  l_recordLen),
                     "mvpdRingFunc: setMvpdField failed "
                     "chipletSel=0x%08x, ringId=0x%x",
                     i_chipletSel,
                     i_ringId);
        }

    fapi_try_exit:
        // get current error
        l_fapirc = fapi2::current_err;

        //  unload the repair ring if allocated
        if(l_recordBuf)
        {
            free(static_cast<void*>(l_recordBuf));
            l_recordBuf = NULL;
        }

        if((i_mvpdRingFuncOp != MVPD_RING_GET) && l_fapirc)
        {
            io_rRingBufsize = 0;
        }

        if ( l_fapirc &&
             ((uint32_t)l_fapirc != RC_MVPD_RING_NOT_FOUND) )
        {
            FAPI_ERR( "mvpdRingFunc: Failed with bufsize=0x%x and rc=0x%x",
                      io_rRingBufsize,
                      static_cast<uint32_t>(l_fapirc) );
        }
        else
        {
            FAPI_DBG( "mvpdRingFunc: Exiting with bufsize=0x%x and rc=0x%x",
                      io_rRingBufsize,
                      static_cast<uint32_t>(l_fapirc) );
        }

        return  l_fapirc;
    }

// Attempts to find the MVPD END marker at given buffer address.
// Returns o_mvpdEnd: true if END marker read, false otherwise.
// Adjusts buffer pointer and length for the consumed portion of buffer, if any.
    fapi2::ReturnCode mvpdRingFuncFindEnd( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                                           & i_fapiTarget,
                                           uint8_t** io_pBufLeft,
                                           uint32_t* io_pBufLenLeft,
                                           bool*      o_mvpdEnd)
    {
        uint32_t l_mvpdMagic;
        const uint8_t l_mvpdMagicLength = 3; // we match against 3 out of 4 bytes

        *o_mvpdEnd = false;

        if (*io_pBufLenLeft < l_mvpdMagicLength)
        {
            return fapi2::current_err;
        }

        l_mvpdMagic = *(reinterpret_cast<uint32_t*>(*io_pBufLeft));
        l_mvpdMagic = be32toh(l_mvpdMagic) & 0xffffff00;

        // Check for end of data magic word
        if (l_mvpdMagic == (MVPD_END_OF_DATA_MAGIC & 0xffffff00))
        {
            *o_mvpdEnd = true;

            FAPI_DBG("mvpdRingFuncFind: Found end of VPD data "
                     "at address 0x%x",
                     *io_pBufLeft);

            *io_pBufLeft    += l_mvpdMagicLength;
            *io_pBufLenLeft -= l_mvpdMagicLength;
        }

        return fapi2::current_err;
    }

// Returns a matching MVPD ring in RS4 format at given buffer address,
// NULL otherwise.
// Adjusts buffer pointer and remaining length for the consumed portion
// of buffer, that is, for the size of a matching MVPD ring, if any.
    fapi2::ReturnCode mvpdRingFuncFindHdr( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                                           & i_fapiTarget,
                                           const uint32_t      i_chipletSel,
                                           const RingId_t      i_ringId,
                                           uint8_t**           io_pBufLeft,
                                           uint32_t*           io_pBufLenLeft,
                                           CompressedScanData** o_pScanData)
    {
        CompressedScanData* l_pScanData =
            reinterpret_cast<CompressedScanData*>(*io_pBufLeft);

        *o_pScanData = NULL;

        // check if buffer is big enough for new ring header
        if (*io_pBufLenLeft < sizeof(CompressedScanData))
        {
            return fapi2::current_err;
        }

        // check magic word
        FAPI_ASSERT(be16toh(l_pScanData->iv_magic) == RS4_MAGIC,
                    fapi2::MVPD_RING_FUNC_INVALID_RS4_MAGIC().
                    set_CHIP_TARGET(i_fapiTarget).
                    set_HEADER_MAGIC(be16toh(l_pScanData->iv_magic)).
                    set_REF_MAGIC(RS4_MAGIC),
                    "mvpdRingFuncFindHdr: Invalid RS4 magic (=0x%4x)",
                    be16toh(l_pScanData->iv_magic));

        // make sure that buffer is big enough for entire ring
        FAPI_ASSERT(*io_pBufLenLeft >= be16toh(l_pScanData->iv_size),
                    fapi2::MVPD_INSUFFICIENT_RING_BUFFER_SPACE().
                    set_CHIP_TARGET(i_fapiTarget).
                    set_RING_ID(i_ringId).
                    set_CHIPLET_SEL(i_chipletSel).
                    set_BUFFER_SIZE(*io_pBufLenLeft).
                    set_RING_SIZE(be16toh(l_pScanData->iv_size)).
                    set_OCCURRENCE(1),
                    "mvpdRingFuncFindHdr: Not enough ring buffer space to contain ring: "
                    "ringId=0x%x, chipletSel=0x%08x, ",
                    "pBufLenLeft=%d, ring->iv_size=%d",
                    i_ringId, i_chipletSel,
                    *io_pBufLenLeft, be16toh(l_pScanData->iv_size));

        // ok, this part of the input buffer can be considered consumed,
        // regardless of it being the ring to be found or not
        *io_pBufLeft    += be16toh(l_pScanData->iv_size);
        *io_pBufLenLeft -= be16toh(l_pScanData->iv_size);

        if ( be16toh(l_pScanData->iv_ringId) == i_ringId )
        {
            if ( ( (i_chipletSel & EQ_QUADRANT_MASK) == 0 &&
                   ( be32toh(l_pScanData->iv_scanAddr) & CHIPLET_ID_MASK ) == i_chipletSel )  ||
                 ( (i_chipletSel & EQ_QUADRANT_MASK) != 0 &&
                   ( be32toh(l_pScanData->iv_scanAddr) & (CHIPLET_ID_MASK | EQ_QUADRANT_MASK) ) == i_chipletSel ) )
            {
                // found it, return pointer to ring
                *o_pScanData = l_pScanData;

                FAPI_DBG("mvpdRingFuncFindHdr: Found RS4 ring for chipletSel=0x%08x and"
                         " ringId=0x%x and ring size=%u",
                         i_chipletSel,
                         i_ringId,
                         be16toh((*o_pScanData)->iv_size));
            }
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    /**
     *  @brief MVPD Ring Function Find
     *
     *  @par Detailed Description:
     *           Step through the record looking at rings for a match.
     *
     *  @param[in]  i_fapiTarget
     *                   FAPI proc chip target
     *
     *  @param[in]  i_record
     *                   Record to validate
     *
     *  @param[in]  i_keyword
     *                   Keyword to validate
     *
     *  @param[in]  i_chipletSel
     *                   Chiplet Select for the op
     *
     *  @param[in]  i_ringId
     *                   Ring ID for the op
     *
     *  @param[in]  i_pRecordBuf
     *                   Pointer to record buffer
     *
     *  @param[in]  i_recordBufLen
     *                   Length of record buffer
     *
     *  @param[out] o_rpRing
     *                   Pointer to the ring in the record, if it is there
     *                   Pointer to the start of the padding after the last
     *                   ring, if it is not there
     *
     *  @param[out] o_rRingLen
     *                   Number of bytes in the ring (header and data)
     *                   Will be 0 if ring not found
     *
     *  @return     fapi2::ReturnCode
     */
    fapi2::ReturnCode mvpdRingFuncFind( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                                        & i_fapiTarget,
                                        fapi2::MvpdRecord   i_record,
                                        fapi2::MvpdKeyword  i_keyword,
                                        const uint32_t      i_chipletSel,
                                        const RingId_t      i_ringId,
                                        uint8_t*            i_pRecordBuf,
                                        uint32_t            i_recordBufLen,
                                        uint8_t*&           o_rpRing,
                                        uint32_t&           o_rRingLen )
    {
        fapi2::ReturnCode   l_fapirc;
        bool                l_mvpdEnd;
        CompressedScanData* l_pScanData = NULL;
        uint32_t            l_prevLen;
        uint32_t            l_recordBufLenLeft = i_recordBufLen;

        FAPI_IMP("mvpdRingFuncFind: Enter w/chipletSel=0x%08x and ringId=0x%x ",
                 i_chipletSel,
                 i_ringId);

        //  Find first RSA data block in ring (fixed offset defined by MVPD spec)
        //
        //  First byte in record's keyword is the version number which we skip
        //
        i_pRecordBuf++;
        l_recordBufLenLeft--;

        o_rRingLen = 0; // Just making sure this is zero in case of a fail or not found

        do
        {
            // let's track the previous size of the remaining buffer,
            // so that we can determine whether we have found anything,
            // and bail out if not (= buffer content corrupted)
            l_prevLen = l_recordBufLenLeft;

            // first look for vpd end marker
            FAPI_TRY(mvpdRingFuncFindEnd(i_fapiTarget,
                                         &i_pRecordBuf,
                                         &l_recordBufLenLeft,
                                         &l_mvpdEnd),
                     "mvpdRingFuncFind: mvpdRingFuncFindEnd failed");

            // second look for ring header
            if (!l_mvpdEnd && !l_pScanData)
            {
                FAPI_TRY(mvpdRingFuncFindHdr(i_fapiTarget,
                                             i_chipletSel,
                                             i_ringId,
                                             &i_pRecordBuf,
                                             &l_recordBufLenLeft,
                                             &l_pScanData),
                         "mvpdRingFuncFind: mvpdRingFuncFindHdr failed");
            }

            FAPI_ASSERT(l_prevLen != l_recordBufLenLeft,
                        fapi2::MVPD_RING_FUNC_ENDLESS_BUFFER().
                        set_CHIP_TARGET(i_fapiTarget).
                        set_RING_ID(i_ringId).
                        set_CHIPLET_SEL(i_chipletSel).
                        set_RECORD_VAL(i_record).
                        set_KEYWORD_VAL(i_keyword),
                        "mvpdRingFuncFind: Found neither END marker nor valid"
                        " ring in record buffer for "
                        "(ringId,chipletSel)=(0x%x,0x%08x) and (record,keyword)=(%d,%d)",
                        i_ringId, i_chipletSel, i_record, i_keyword);
        }
        while (!l_mvpdEnd && !l_pScanData && l_recordBufLenLeft);

        if (l_pScanData)
        {
            o_rpRing   = (uint8_t*)l_pScanData;
            o_rRingLen = be16toh(l_pScanData->iv_size);
        }
        else
        {
            // if no error and not found, return pointer to end of list
            // in case it's needed for appending, and indicate with 0 size
            o_rpRing   = i_pRecordBuf;
            o_rRingLen = 0;
        }

    fapi_try_exit:
        // get current error
        l_fapirc = fapi2::current_err;

        FAPI_IMP("mvpdRingFuncFind: Exit w/rc=0x%08x for chipletSel=0x%08x, ringId=0x%x and"
                 " ring size=%u (if size==0, then something failed)",
                 static_cast<uint32_t>(l_fapirc),
                 i_chipletSel,
                 i_ringId,
                 o_rRingLen);

        return  l_fapirc;
    }


    /**
     *  @brief MVPD Validate Ring Header
     *
     *  @param[in]  i_fapiTarget
     *                   FAPI proc chip target
     *
     *  @param[in]  i_pRingBuf
     *                   Pointer to the ring in the record
     *
     *  @param[in]  i_chipletSel
     *                   Chiplet Select for the op
     *
     *  @param[in]  i_ringId
     *                   Ring ID for the op
     *
     *  @param[in]  i_ringBufsize
     *                   Number of bytes in the ring (header and data)
     *
     *  @return     fapi2::ReturnCode
     */
    fapi2::ReturnCode mvpdValidateRingHeader(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
        & i_fapiTarget,
        CompressedScanData*  i_pRingBuf,
        uint32_t             i_chipletSel,
        RingId_t             i_ringId,
        uint32_t             i_ringBufsize)
    {
        uint8_t l_failedTestVec = 0x00;

        if ( be16toh(i_pRingBuf->iv_magic) != RS4_MAGIC )
        {
            l_failedTestVec = l_failedTestVec | 0x80;
        }

        if ( be16toh(i_pRingBuf->iv_ringId) != i_ringId )
        {
            l_failedTestVec = l_failedTestVec | 0x40;
        }

        if ( ( (i_chipletSel & EQ_QUADRANT_MASK) == 0 &&
               ( be32toh(i_pRingBuf->iv_scanAddr) & CHIPLET_ID_MASK ) != i_chipletSel )  &&
             ( (i_chipletSel & EQ_QUADRANT_MASK) != 0 &&
               ( be32toh(i_pRingBuf->iv_scanAddr) & (CHIPLET_ID_MASK | EQ_QUADRANT_MASK) ) != i_chipletSel ) )
        {
            l_failedTestVec = l_failedTestVec | 0x20;
        }

        if ( be16toh(i_pRingBuf->iv_size) != i_ringBufsize )
        {
            l_failedTestVec = l_failedTestVec | 0x10;
        }

        if ( i_ringBufsize <= sizeof(CompressedScanData) )
        {
            l_failedTestVec = l_failedTestVec | 0x08;
        }

        FAPI_ASSERT( l_failedTestVec == 0x00,
                     fapi2::MVPD_RING_FUNC_INVALID_RS4_HEADER().
                     set_CHIP_TARGET(i_fapiTarget).
                     set_HEADER_MAGIC(be16toh(i_pRingBuf->iv_magic)).
                     set_REF_MAGIC(RS4_MAGIC).
                     set_HEADER_RING_ID(be16toh(i_pRingBuf->iv_ringId)).
                     set_REF_RING_ID(i_ringId).
                     set_HEADER_SCAN_ADDR(be32toh(i_pRingBuf->iv_scanAddr)).
                     set_REF_CHIPLET_SEL(i_chipletSel).
                     set_HEADER_RING_SIZE(be16toh(i_pRingBuf->iv_size)).
                     set_REF_RING_SIZE(i_ringBufsize).
                     set_SIZEOF_COMPRESSED_SCAN_DATA(sizeof(CompressedScanData)).
                     set_FAILED_TEST_VEC(l_failedTestVec),
                     "mvpdValidateRingHeader() failed: \n"
                     "Test0x80: iv_magic=0x%x     vs  RS4_MAGIC=0x%x \n"
                     "Test0x80: iv_ringId=0x%x    vs  i_ringId=0x%x \n"
                     "Test0x80: iv_scanAddr=0x%x  vs  i_chipletSel=0x%08x \n"
                     "Test0x80: iv_size=0x%x      vs  i_ringBufsize=0x%x  vs  sizeof(CompressedScanData)=0x%x \n"
                     "Fail test vector: 0x%02x",
                     be16toh(i_pRingBuf->iv_magic), RS4_MAGIC,
                     be16toh(i_pRingBuf->iv_ringId), i_ringId,
                     be32toh(i_pRingBuf->iv_scanAddr), i_chipletSel,
                     be16toh(i_pRingBuf->iv_size), i_ringBufsize, sizeof(CompressedScanData),
                     l_failedTestVec );

    fapi_try_exit:
        return fapi2::current_err;
    }


    /**
     *  @brief MVPD Get Ring Function
     *
     *  @par Detailed Description:
     *           Copy the ring back to the caller.
     *
     *  @param[in]  i_pRing
     *                   Pointer to the ring in the record
     *
     *  @param[in]  i_ringLen
     *                   Number of bytes in the ring (header and data)
     *
     *
     *  @param[in]  i_pCallerRingBuf
     *                   Pointer to the caller's ring in the record
     *
     *  @param[in/out]  io_rCallerRingBufLen
     *                   Number of bytes in the caller's ring
     *
     *  @return     fapi2::ReturnCode
     */
    fapi2::ReturnCode mvpdRingFuncGet( uint8_t*     i_pRing,
                                       uint32_t     i_ringLen,
                                       uint8_t*     i_pCallerRingBuf,
                                       uint32_t&    io_rCallerRingBufLen)
    {
        fapi2::ReturnCode        l_fapirc;

        do
        {
            //  return buffer pointer is NULL if just looking for the size
            if  ( i_pCallerRingBuf == NULL )
            {
                io_rCallerRingBufLen = i_ringLen;
                //  break out of do block with success rc
                break;
            }

            //  check if we have enough space
            if ( io_rCallerRingBufLen < i_ringLen )
            {
                FAPI_ERR("mvpdRingFuncGet(): Output buffer too small:  "
                         "rCallerRingBufLen(=0x%x) < ringLen(=0x%x)",
                         io_rCallerRingBufLen,
                         i_ringLen);
                fapi2::current_err = RC_MVPD_RING_BUFFER_TOO_SMALL;
                goto fapi_try_exit;
            }

            //  we're good, copy data into the passed-in buffer
            FAPI_DBG( "mvpdRingFuncGet: memcpy(0x%p,0x%p,%u)",
                      i_pCallerRingBuf,
                      i_pRing,
                      i_ringLen );

            memcpy( i_pCallerRingBuf, i_pRing, i_ringLen );

//CMO-20200611: We should check here several RS4 header fields:that iv_type
//            if ( ((CompressedScanData*)i_pCallerRingBuf)->iv_version R== RS4_VERSION  &&
//                 (((CompressedScanData*)i_pCallerRingBuf)->iv_type & RS4_IV_TYPE_ORIG_MVPD) ==
//                   RS4_IV_TYPE_ORIG_MVPD  &&
//                 ((((CompressedScanData*)i_pCallerRingBuf)->iv_type & RS4_IV_TYPE_SCAN_FLUSH) ==
//                   RS4_IV_TYPE_SCAN_FLUSH  &&  ringType != PDS )  &&
//                 ((((CompressedScanData*)i_pCallerRingBuf)->iv_type & RS4_IV_TYPE_SCAN_OVRD) ==
//                   RS4_IV_TYPE_SCAN_OVRD  &&  ringType == PDS ) )
//            {
//                break;
//            }
//            else
//            {
//                FAPI_ERR();
//            }

            io_rCallerRingBufLen =   i_ringLen;
        }
        while (0);

    fapi_try_exit:
        // get current error
        l_fapirc = fapi2::current_err;

        if (l_fapirc.isRC(RC_MVPD_RING_BUFFER_TOO_SMALL))
        {
            //  return actual size of data, so caller can re-try with
            //  the correct value
            io_rCallerRingBufLen = i_ringLen;
        }

        FAPI_DBG( "mvpdRingFuncGet: Exit w/rc=0x%08x and w/bufsize=0x%x",
                  static_cast<uint32_t>(l_fapirc),
                  io_rCallerRingBufLen );

        return l_fapirc;
    }


    /**
     *  @brief MVPD Set Ring Function
     *
     *  @par Detailed Description:
     *           Update the record with the caller's ring.
     *
     *  @param[in]  i_fapiTarget
     *                   FAPI proc chip target
     *
     *  @param[in]  i_pRecordBuf
     *                   Pointer to record buffer
     *
     *  @param[in]  i_recordLen
     *                   Length of record buffer
     *
     *  @param[in]  i_pRing
     *                   Pointer to the ring in the record
     *
     *  @param[in]  i_ringLen
     *                   Number of bytes in the ring (header and data)
     *
     *  @param[in]  i_pCallerRingBuf
     *                   Pointer to the caller's ring in the record
     *
     *  @param[in]  i_callerRingBufLen
     *                   Number of bytes in the caller's ring
     *
     *  @return     fapi2::ReturnCode
     */
    fapi2::ReturnCode mvpdRingFuncSet( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                                       & i_fapiTarget,
                                       fapi2::MvpdRecord    i_record,
                                       fapi2::MvpdKeyword   i_keyword,
                                       uint8_t*     i_pRecordBuf,
                                       uint32_t     i_recordLen,
                                       uint8_t*     i_pRing,
                                       uint32_t     i_ringLen,
                                       uint8_t*     i_pCallerRingBuf,
                                       uint32_t     i_callerRingBufLen)
    {
        fapi2::ReturnCode l_fapirc;
        uint8_t*          l_to = NULL;
        uint8_t*          l_fr = NULL;
        uint32_t          l_len = 0;
        uint8_t*          l_pRingEnd; // pointer into record to start of pad at end

        FAPI_DBG( "mvpdRingFuncSet: pRing=0x%p rLen=0x%x pCaller=0x%p cLen=0x%x",
                  i_pRing,
                  i_ringLen,
                  i_pCallerRingBuf,
                  i_callerRingBufLen);

        do
        {
            // if exact fit, update in place
            if (i_callerRingBufLen == i_ringLen)
            {
                l_to = i_pRing;
                l_fr = i_pCallerRingBuf;
                l_len = i_callerRingBufLen;
                FAPI_DBG( "mvpdRingFuncSet: update in place-memcpy 0x%p 0x%p 0x%x",
                          l_to,
                          l_fr,
                          l_len);
                memcpy (l_to, l_fr, l_len);

                // break out successful
                break;
            }

            // will need the end for shifting... look for something invalid
            FAPI_TRY(mvpdRingFuncFind(i_fapiTarget,
                                      i_record,
                                      i_keyword,
                                      0x00,
                                      0x00,
                                      i_pRecordBuf,
                                      i_recordLen,
                                      l_pRingEnd, // find start of padding
                                      l_len),
                     "mvpdRingFuncSet: mvpdRingFuncFind failed");

            FAPI_DBG( "mvpdRingFuncSet: end= 0x%p",
                      l_pRingEnd);

            // if not there, then append if it fits
            if (i_ringLen == 0 ) //is not currently in record (0 len from find)
            {
                FAPI_ASSERT(l_pRingEnd + i_callerRingBufLen <=
                            i_pRecordBuf + i_recordLen,
                            fapi2::MVPD_INSUFFICIENT_RECORD_SPACE().
                            set_CHIP_TARGET(i_fapiTarget).
                            set_REM_RING_SIZE(i_callerRingBufLen).
                            set_REM_RECORD_SPACE(i_pRecordBuf + i_recordLen - l_pRingEnd).
                            set_OCCURRENCE(1),
                            "mvpdRingFuncSet: Not enough record space to append new ring: "
                            "Remaining_ring_size=%d, Remaining_record_space=%d",
                            i_callerRingBufLen, i_pRecordBuf + i_recordLen - l_pRingEnd);

                l_to = i_pRing;
                l_fr = i_pCallerRingBuf;
                l_len = i_callerRingBufLen;
                FAPI_DBG( "mvpdRingFuncSet: append-memcpy 0x%p 0x%p 0x%x",
                          l_to,
                          l_fr,
                          l_len);
                memcpy (l_to, l_fr, l_len);

                // break out successful
                break;
            }

            // if smaller, then shift left and zero fill
            if (i_callerRingBufLen < i_ringLen)
            {
                l_to = i_pRing;
                l_fr = i_pCallerRingBuf;
                l_len = i_callerRingBufLen;
                FAPI_DBG( "mvpdRingFuncSet: shrink-memcpy 0x%p 0x%p 0x%x",
                          l_to,
                          l_fr,
                          l_len);
                memcpy (l_to, l_fr, l_len);

                l_to = i_pRing + i_callerRingBufLen;
                l_fr = i_pRing + i_ringLen;
                l_len = (l_pRingEnd) - (i_pRing + i_ringLen);
                FAPI_DBG( "mvpdRingFuncSet: shrink-memmove 0x%p 0x%p 0x%x",
                          l_to,
                          l_fr,
                          l_len);
                memmove (l_to, l_fr, l_len); //use memmove, always overlaps.

                l_to = (l_pRingEnd) - (i_ringLen - i_callerRingBufLen);
                l_len = i_ringLen - i_callerRingBufLen;
                FAPI_DBG( "mvpdRingFuncSet: shrink-memset 0x%p 0x%x 0x%x",
                          l_to,
                          0x00,
                          l_len);
                memset (l_to, 0x00, l_len);

                // break out successful
                break;

            }

            // if larger, then shift right, if it fits
            if (i_callerRingBufLen > i_ringLen)
            {
                // ensure the padding can contain the growth
                FAPI_ASSERT((l_pRingEnd + (i_callerRingBufLen - i_ringLen)) <=
                            (i_pRecordBuf + i_recordLen),
                            fapi2::MVPD_INSUFFICIENT_RECORD_SPACE().
                            set_CHIP_TARGET(i_fapiTarget).
                            set_REM_RING_SIZE(i_callerRingBufLen - i_ringLen).
                            set_REM_RECORD_SPACE(i_pRecordBuf + i_recordLen - l_pRingEnd).
                            set_OCCURRENCE(2),
                            "mvpdRingFuncSet: Not enough record space to replace "
                            "existing ring: "
                            "Remaining_ring_size=%d, Remaining_record_space=%d",
                            i_callerRingBufLen - i_ringLen,
                            i_pRecordBuf + i_recordLen - l_pRingEnd);

                l_to = i_pRing + i_callerRingBufLen;
                l_fr = i_pRing + i_ringLen;
                l_len = l_pRingEnd - (i_pRing + i_ringLen);
                FAPI_DBG( "mvpdRingFuncSet: insert-memmove 0x%p 0x%p 0x%x",
                          l_to,
                          l_fr,
                          l_len);
                memmove (l_to, l_fr, l_len);

                l_to = i_pRing;
                l_fr = i_pCallerRingBuf;
                l_len = i_callerRingBufLen;
                FAPI_DBG( "mvpdRingFuncSet: insert-memcpy 0x%p 0x%p 0x%x",
                          l_to,
                          l_fr,
                          l_len);
                memcpy (l_to, l_fr, l_len);

                // break out successful
                break;
            }

            FAPI_ASSERT( false,
                         fapi2::MVPD_CODE_BUG().
                         set_CHIP_TARGET(i_fapiTarget).
                         set_OCCURRENCE(1),
                         "Code bug(1): Should never get here. Fix code!" );

        }
        while (0);

    fapi_try_exit:
        // get current error
        l_fapirc = fapi2::current_err;

        FAPI_DBG( "mvpdRingFuncSet: exit  rc= 0x%x",
                  static_cast<uint32_t>(l_fapirc) );

        return l_fapirc;
    }

} // extern C
