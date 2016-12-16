/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/accessors/p9_mvpd_ring_funcs.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/**
 *  @file p9_mvpd_ring_funcs.C
 *
 *  @brief common routines
 *
 */

#include    <stdint.h>

//  fapi2 support
#include    <fapi2.H>
#include    <utils.H>
#include    <mvpd_access.H>
#include    <p9_mvpd_ring_funcs.H>

//      pull in CompressedScanData def from proc_slw_build HWP
#include <p9_scan_compression.H>
#include <p9_ring_identification.H>
#include <p9_ringId.H>


extern "C"
{
    using   namespace   fapi2;

// functions internal to this file
// these functions are common for both mvpdRingFunc and mbvpdRingFunc
    fapi2::ReturnCode mvpdValidateRingHeader( CompressedScanData* i_pRing,
            uint8_t             i_chipletId,
            uint8_t             i_ringId,
            uint32_t            i_ringBufsize);

    fapi2::ReturnCode mvpdRingFuncFind( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                                        & i_fapiTarget,
                                        fapi2::MvpdRecord    i_record,
                                        fapi2::MvpdKeyword   i_keyword,
                                        const uint8_t   i_chipletId,
                                        const uint8_t   i_evenOdd,
                                        const uint8_t   i_ringId,
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
    };

    /**
     *  @brief Validate Record and Keyword Combination
     *
     *  @par Detailed Description:
     *           Check for supported combinations of Record and Keyword.
     *           The record needs to contain rings of RS4 header
     *           (CompressedScanData) format.
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
    fapi2::ReturnCode mvpdValidateRecordKeyword( fapi2::MvpdRecord i_record,
            fapi2::MvpdKeyword i_keyword)
    {
        fapi2::ReturnCode        l_fapirc;
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

        if ( !l_validPair )
        {
            FAPI_SET_HWP_ERROR(l_fapirc, RC_MVPD_RING_FUNC_INVALID_PARAMETER );
        }

        return l_fapirc;

    };


    /**
     *  @brief MVPD Ring Function
     *
     *  @par Detailed Description:
     *           The getMvpdRing and setMvpdRing wrappers call this function
     *           to do all the processing.
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
     *  @param[in]  i_fapiTarget
     *                   FAPI target for the op
     *
     *  @param[in]  i_chipletId
     *                   Chiplet ID for the op
     *
     *  @param[in]  i_evenOdd
     *                   Indicates whether to choose even (0) or odd (1) EX.
     *                   Undefined and to be disregarded for non-EX.
     *
     *  @param[in]  i_ringId
     *                   Ring ID for the op
     *
     *  @param[in]  i_pRingBuf
     *                   Pointer to ring buffer with set data
     *
     *  @param[in/out]  io_rRingBufsize
     *                   Size of ring buffer
     *
     *  @note:      io_rRingBufsize is only an 'output' for get function.
     *
     *  @return     fapi2::ReturnCode
     */
    fapi2::ReturnCode mvpdRingFunc( const mvpdRingFuncOp i_mvpdRingFuncOp,
                                    fapi2::MvpdRecord    i_record,
                                    fapi2::MvpdKeyword   i_keyword,
                                    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                                    & i_fapiTarget,
                                    const uint8_t        i_chipletId,
                                    const uint8_t        i_evenOdd,
                                    const uint8_t        i_ringId,
                                    uint8_t*             i_pRingBuf,
                                    uint32_t&            io_rRingBufsize )
    {
        fapi2::ReturnCode       l_fapirc = fapi2::FAPI2_RC_SUCCESS;
        uint32_t                l_recordLen  = 0;
        uint8_t*                l_recordBuf  = NULL;
        uint8_t*                l_pRing      = NULL;
        uint32_t                l_ringLen    = 0;

        FAPI_DBG("mvpdRingFunc: Called w/op=0x%x, ringId=0x%x, chipletId=0x%x, "
                 "evenOdd=0x%x, size=0x%x",
                 i_mvpdRingFuncOp,
                 i_ringId,
                 i_chipletId,
                 i_evenOdd,
                 io_rRingBufsize  );

        // do common get and set input parameter error checks
        // check for supported combination of Record and Keyword
        FAPI_TRY(mvpdValidateRecordKeyword(i_record,
                                           i_keyword),
                 "mvpdRingFunc: unsupported record keyword pair "
                 "record=0x%x, keyword=0x%x",
                 i_record,
                 i_keyword);

        // do set specific input parameter checks
        if (i_mvpdRingFuncOp == MVPD_RING_SET )
        {
            // passing NULL pointer to receive needed size is only for get.
            FAPI_ASSERT(i_pRingBuf != NULL,
                        fapi2::MVPD_RING_FUNC_INVALID_PARAMETER(),
                        "mvpdRingFunc: NULL ring buffer pointer passed "
                        "to set function chipletId=0x%x, ringId=0x%x",
                        i_chipletId,
                        i_ringId);

            // Validate ring header to protect vpd
            FAPI_TRY(mvpdValidateRingHeader(
                         reinterpret_cast<CompressedScanData*>(i_pRingBuf),
                         i_chipletId,
                         i_ringId,
                         io_rRingBufsize),
                     "mvpdRingFunc: invalid ring header "
                     "chipletId=0x%x, ringId=0x%x",
                     i_chipletId,
                     i_ringId);
        }

        //  call getMvpdField once with a NULL pointer to get the buffer
        //  size no error should be returned.
        FAPI_TRY(getMvpdField(i_record,
                              i_keyword,
                              i_fapiTarget,
                              NULL,
                              l_recordLen ),
                 "mvpdRingFunc: getMvpdField failed to get buffer size "
                 "chipletId=0x%x, ringId=0x%x",
                 i_chipletId,
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
                 "mvpdRingFunc: getMvpdField failed "
                 "chipletId=0x%x, evenOdd=0x%x, ringId=0x%x",
                 i_chipletId,
                 i_evenOdd,
                 i_ringId);

        // find ring in the record. It is an error if not there for a "get".
        // Its ok if not there for a "set". The ring will be added.
        // l_ringLen set to 0 if not there with l_pRing at the start of padding.
        FAPI_TRY(mvpdRingFuncFind(i_fapiTarget,
                                  i_record,
                                  i_keyword,
                                  i_chipletId,
                                  i_evenOdd,
                                  i_ringId,
                                  l_recordBuf,
                                  l_recordLen,
                                  l_pRing,
                                  l_ringLen),
                 "mvpdRingFunc: mvpdRingFuncFind failed "
                 "chipletId=0x%x, evenOdd=0x%x, ringId=0x%x",
                 i_chipletId,
                 i_evenOdd,
                 i_ringId);

        // do the get or set specific operations
        if (i_mvpdRingFuncOp == MVPD_RING_GET ) // do the get operation
        {
            // Ensure ring was found. Must be there for "get"
            //@TODO: Uncomment the following after PowerOn. Also, need to come
            //       to agreement whether this should be fatal error or not.
            //       For now, for PO, it's considered benign and noise and is
            //       being commented out and we just exit with manually setting
            //       the RC ring not found but which doesn't activates the FFDC
            //       capturing.
            if (l_ringLen == 0)
            {
                fapi2::current_err = RC_MVPD_RING_NOT_FOUND;
                goto fapi_try_exit;
            }

            //FAPI_ASSERT(l_ringLen != 0,
            //            fapi2::MVPD_RING_NOT_FOUND().
            //            set_CHIP_TARGET(i_fapiTarget).
            //            set_RING_ID(i_ringId).
            //            set_CHIPLET_ID(i_chipletId),
            //            "mvpdRingFunc: mvpdRingFuncFind did not find ring");

            // copy ring back to caller's buffer
            FAPI_TRY(mvpdRingFuncGet(l_pRing,
                                     l_ringLen,
                                     i_pRingBuf,
                                     io_rRingBufsize),
                     "mvpdRingFunc: mvpdRingFuncGet failed "
                     "chipletId=0x%x, evenOdd=0x%x, ringId=0x%x",
                     i_chipletId,
                     i_evenOdd,
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
                                     i_pRingBuf,
                                     io_rRingBufsize),
                     "mvpdRingFunc: mvpdRingFuncSet failed "
                     "chipletId=0x%x, ringId=0x%x",
                     i_chipletId,
                     i_ringId);

            // update record back to the mvpd
            FAPI_TRY(setMvpdField(i_record,
                                  i_keyword,
                                  i_fapiTarget,
                                  l_recordBuf,
                                  l_recordLen),
                     "mvpdRingFunc: setMvpdField failed "
                     "chipletId=0x%x, ringId=0x%x",
                     i_chipletId,
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

        FAPI_DBG( "mvpdRingFunc: exit bufsize= 0x%x rc= 0x%x",
                  io_rRingBufsize,
                  static_cast<uint32_t>(l_fapirc) );
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


    // Returns a matching MVPD ring in RS4 v2 format at given buffer address,
    // NULL otherwise.
    // Adjusts buffer pointer and remaining length for the consumed portion
    // of buffer, that is, for the size of a matching MVPD ring, if any.
    // This function is needed only for backward compatibility, and may be
    // removed as soon as no RS4 v2 MVPD rings will be available.
    fapi2::ReturnCode mvpdRingFuncFindOld( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                                           & i_fapiTarget,
                                           const uint8_t       i_chipletId,
                                           const uint8_t       i_evenOdd,
                                           const uint8_t       i_ringId,
                                           uint8_t**           io_pBufLeft,
                                           uint32_t*           io_pBufLenLeft,
                                           CompressedScanData** o_pScanData)
    {
        uint64_t l_evenOddMask;
        CompressedScanData l_scanData;

        // old CompressedScanData structure
        typedef struct
        {
            uint32_t iv_magic;
            uint32_t iv_size;
            uint32_t iv_algorithmReserved;
            uint32_t iv_length;
            uint64_t iv_scanSelect;
            uint8_t  iv_headerVersion;
            uint8_t  iv_flushOptimization;
            uint8_t  iv_ringId;
            uint8_t  iv_chipletId;
        } OldCompressedScanData;

        OldCompressedScanData* l_pScanDataOld =
            reinterpret_cast<OldCompressedScanData*>(*io_pBufLeft);

        *o_pScanData = NULL;

        // check if buffer is big enough for old ring header
        if (*io_pBufLenLeft < sizeof(OldCompressedScanData))
        {
            return fapi2::current_err;
        }

        // check magic word assuming an old ring header
        if ((be32toh(l_pScanDataOld->iv_magic) & 0xffffff00) != 0x52533400)
        {
            return fapi2::current_err;
        }

        // make sure that buffer is big enough for entire ring
        FAPI_ASSERT(*io_pBufLenLeft >= be32toh(l_pScanDataOld->iv_size),
                    fapi2::MVPD_INSUFFICIENT_RECORD_SPACE(),
                    "mvpdRingFuncFind: data does not fit "
                    "into record buffer: ringId=0x%x, chipletId=0x%x",
                    i_ringId,
                    i_chipletId );

        // ok, this is a ring with an old header,
        // hence this part of the input buffer can be considered consumed,
        // regardless of it being the ring to be found or not
        *io_pBufLeft    += be32toh(l_pScanDataOld->iv_size);
        *io_pBufLenLeft -= be32toh(l_pScanDataOld->iv_size);

        // for a few rings there are two different copies,
        // called even and odd, which we need to consider
        // as an extra search criterion for those rings (EX only)
        switch (i_ringId)
        {
            case ex_l3_refr_time:
            case ex_l3_refr_repr:
                l_evenOddMask = 0x0008000000000000 >> i_evenOdd;
                break;

            case ex_l2_repr:
                l_evenOddMask = 0x0080000000000000 >> i_evenOdd;
                break;

            case ex_l3_repr:
                l_evenOddMask = 0x0200000000000000 >> i_evenOdd;
                break;

            default:
                l_evenOddMask = 0;
        }

        // check if this ring matches the given criteria
        // (ring ID, chiplet Id, and even/odd for EX)
        if ( l_pScanDataOld->iv_ringId == i_ringId       &&
             l_pScanDataOld->iv_chipletId == i_chipletId &&
             (l_evenOddMask == 0 ||
              be64toh(l_pScanDataOld->iv_scanSelect) & l_evenOddMask) )
        {
            // look up ring in p9_ringId and retrieve scanAddr
            GenRingIdList* l_ringProp = p9_ringid_get_ring_properties(
                                            (RingID)i_ringId);
            FAPI_ASSERT(l_ringProp,
                        fapi2::MVPD_RINGID_DATA_NOT_FOUND(),
                        "mvpdRingFuncFind: lookup of scanAddr failed "
                        "for ringId=0x%x, chipletId=0x%x",
                        i_ringId,
                        i_chipletId);

            // update chipletId in iv_scanScomAddress (for instance rings)
            uint32_t l_scanScomAddr = l_ringProp->scanScomAddress;

            if (i_chipletId != (l_scanScomAddr & 0xff000000) >> 24)
            {
                l_scanScomAddr = (l_scanScomAddr & 0x00ffffff) |
                                 (((uint32_t)i_chipletId) << 24);
            }

            // update even/odd region mask in iv_scanScomAddress (for EX):
            // p9_ringId.C stores scan addresses for even EX rings. Hence we
            // only need to clear the even bit and set the odd bit
            // to create the correct scan address for odd EX rings.
            if (l_evenOddMask && i_evenOdd)
            {
                uint32_t l_evenOddMask32 = (uint32_t)(l_evenOddMask >> 45);
                l_scanScomAddr &= ~(l_evenOddMask32 << i_evenOdd);
                l_scanScomAddr |= l_evenOddMask32;
            }

            // translate old ring header to new ring header
            l_scanData.iv_magic    = htobe16(RS4_MAGIC);
            l_scanData.iv_version  = RS4_VERSION;
            l_scanData.iv_type     = RS4_SCAN_DATA_TYPE_NON_CMSK;
            l_scanData.iv_size     = htobe16(
                                         (be32toh(l_pScanDataOld->iv_size)
                                          - sizeof(OldCompressedScanData)
                                          + sizeof(CompressedScanData)));
            l_scanData.iv_ringId   = htobe16(i_ringId);
            l_scanData.iv_scanAddr = htobe32(l_scanScomAddr);

            // overwrite old ring header with new ring header
            memcpy(l_pScanDataOld, &l_scanData, sizeof(l_scanData));

            // move compressed ring data to position adjacent to new header
            memmove((uint8_t*)l_pScanDataOld + sizeof(CompressedScanData),
                    (uint8_t*)l_pScanDataOld + sizeof(OldCompressedScanData),
                    be16toh(l_scanData.iv_size) - sizeof(CompressedScanData));

            // return found ring in new format
            *o_pScanData = reinterpret_cast<CompressedScanData*>
                           (l_pScanDataOld);

            FAPI_DBG("mvpdRingFuncFindOld: found RS4 v2 ring for "
                     "chipletId 0x%x, evenOdd %d and ringId %d "
                     "at address 0x%x and with old/translated size %d/%d",
                     i_chipletId,
                     i_evenOdd,
                     i_ringId,
                     *o_pScanData,
                     be32toh(l_pScanDataOld->iv_size),
                     be16toh((*o_pScanData)->iv_size));
        }

    fapi_try_exit:
        return fapi2::current_err;
    }


    // Returns a matching MVPD ring in RS4 v3 format at given buffer address,
    // NULL otherwise.
    // Adjusts buffer pointer and remaining length for the consumed portion
    // of buffer, that is, for the size of a matching MVPD ring, if any.
    fapi2::ReturnCode mvpdRingFuncFindNew( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                                           & i_fapiTarget,
                                           const uint8_t       i_chipletId,
                                           const uint8_t       i_evenOdd,
                                           const uint8_t       i_ringId,
                                           uint8_t**           io_pBufLeft,
                                           uint32_t*           io_pBufLenLeft,
                                           CompressedScanData** o_pScanData)
    {
        uint32_t l_evenOddMask;

        CompressedScanData* l_pScanData =
            reinterpret_cast<CompressedScanData*>(*io_pBufLeft);

        *o_pScanData = NULL;

        // check if buffer is big enough for new ring header
        if (*io_pBufLenLeft < sizeof(CompressedScanData))
        {
            return fapi2::current_err;
        }

        // check magic word assuming a new ring header
        if (be16toh(l_pScanData->iv_magic) != RS4_MAGIC)
        {
            return fapi2::current_err;
        }

        // make sure that buffer is big enough for entire ring
        FAPI_ASSERT(*io_pBufLenLeft >= be16toh(l_pScanData->iv_size),
                    fapi2::MVPD_INSUFFICIENT_RECORD_SPACE(),
                    "mvpdRingFuncFind: data does not fit "
                    "into record buffer: ringId=0x%x, chipletId=0x%x",
                    i_ringId,
                    i_chipletId);

        // ok, this is a ring with a new header,
        // hence this part of the input buffer can be considered consumed,
        // regardless of it being the ring to be found or not
        *io_pBufLeft    += be16toh(l_pScanData->iv_size);
        *io_pBufLenLeft -= be16toh(l_pScanData->iv_size);

        // for a few rings there are two different copies,
        // called even and odd, which we need to consider
        // as an extra search criterion for those rings (EX only)
        switch (i_ringId)
        {
            case ex_l3_refr_time:
            case ex_l3_refr_repr:
                l_evenOddMask = 0x00000040 >> i_evenOdd;
                break;

            case ex_l2_repr:
                l_evenOddMask = 0x00000400 >> i_evenOdd;
                break;

            case ex_l3_repr:
                l_evenOddMask = 0x00001000 >> i_evenOdd;
                break;

            default:
                l_evenOddMask = 0;
        }

        if ( be16toh(l_pScanData->iv_ringId) == i_ringId       &&
             (be32toh(l_pScanData->iv_scanAddr) & 0xFF000000UL) >> 24
             == i_chipletId &&
             ( l_evenOddMask == 0 ||
               (be32toh(l_pScanData->iv_scanAddr) & l_evenOddMask) ) )
        {
            // found it, return pointer to ring
            *o_pScanData = l_pScanData;

            FAPI_DBG("mvpdRingFuncFindNew: found RS4 v3 ring for "
                     "chipletId 0x%x, evenOdd %d and ringId %d "
                     "at address 0x%x and with size %d",
                     i_chipletId,
                     i_evenOdd,
                     i_ringId,
                     *o_pScanData,
                     be16toh((*o_pScanData)->iv_size));
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
     *  @param[in]  i_chipletId
     *                   Chiplet ID for the op
     *
     *  @param[in]  i_evenOdd
     *                   Indicates whether choose even (0) or odd (1) EX.
     *                   Undefined and to be disregarded for non-EX.
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
                                        const uint8_t       i_chipletId,
                                        const uint8_t       i_evenOdd,
                                        const uint8_t       i_ringId,
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

        FAPI_DBG("mvpdRingFuncFind: Called w/chipletId=0x%x, evenOdd=0x%x, ringId=0x%x ",
                 i_chipletId,
                 i_evenOdd,
                 i_ringId);

        //  Find first RSA data block in ring (fixed offset defined by
        //      MVPD spec)
        //
        //  First byte in record should be the version number, skip
        //      over this.
        //
        FAPI_DBG( "mvpdRingFuncFind: record version = 0x%x", *i_pRecordBuf );
        i_pRecordBuf++;
        l_recordBufLenLeft--;

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

            // next look for old ring header, because
            // its magic "RS4" is not as ambigiuous as the new "RS" magic
            if (!l_mvpdEnd)
            {
                FAPI_TRY(mvpdRingFuncFindOld(i_fapiTarget,
                                             i_chipletId,
                                             i_evenOdd,
                                             i_ringId,
                                             &i_pRecordBuf,
                                             &l_recordBufLenLeft,
                                             &l_pScanData),
                         "mvpdRingFuncFind: mvpdRingFuncFindOld failed");
            }

            // last look for new ring header
            if (!l_mvpdEnd && !l_pScanData)
            {
                FAPI_TRY(mvpdRingFuncFindNew(i_fapiTarget,
                                             i_chipletId,
                                             i_evenOdd,
                                             i_ringId,
                                             &i_pRecordBuf,
                                             &l_recordBufLenLeft,
                                             &l_pScanData),
                         "mvpdRingFuncFind: mvpdRingFuncFindNew failed");
            }

            FAPI_ASSERT(l_prevLen != l_recordBufLenLeft,
                        fapi2::MVPD_RING_FUNC_ENDLESS(),
                        "mvpdRingFuncFind: found neither END marker, nor valid"
                        " ring at address 0x%x for remaining buffer size 0x%d.",
                        i_pRecordBuf,
                        l_recordBufLenLeft);
        }
        while (!l_mvpdEnd && !l_pScanData && l_recordBufLenLeft);

        if (l_pScanData)
        {
            o_rpRing   = (uint8_t*)l_pScanData;
            o_rRingLen = be16toh(l_pScanData->iv_size);

            // Dump record info for debug
            FAPI_DBG("mvpdRingFuncFind:ringId=0x%x chipletId=0x%x size=0x%x",
                     i_ringId,
                     i_chipletId,
                     be16toh(l_pScanData->iv_size));
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

        FAPI_DBG("mvpdRingFuncFind: exit *ring= 0x%p", o_rpRing);
        FAPI_IMP("mvpdRingFuncFind: exit chipletId=0x%x, ringId=0x%x size=0x%x"
                 " rc=0x%x",
                 i_chipletId,
                 i_ringId,
                 o_rRingLen,
                 static_cast<uint32_t>(l_fapirc) );

        return  l_fapirc;
    }


    /**
     *  @brief MVPD Validate Ring Header
     *
     *  @param[in]  i_pRingBuf
     *                   Pointer to the ring in the record
     *
     *  @param[in]  i_chipletId
     *                   Chiplet ID for the op
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
        CompressedScanData*  i_pRingBuf,
        uint8_t              i_chipletId,
        uint8_t              i_ringId,
        uint32_t             i_ringBufsize)
    {
        FAPI_ASSERT(i_ringBufsize > sizeof(CompressedScanData),
                    fapi2::MVPD_RING_FUNC_INVALID_PARAMETER(),
                    "mvpdValidateRingHeader: i_ringBufsize failed "
                    "chipletId=0x%x, ringId=0x%x",
                    i_chipletId,
                    i_ringId);
        FAPI_ASSERT(be16toh(i_pRingBuf->iv_magic) == RS4_MAGIC,
                    fapi2::MVPD_RING_FUNC_INVALID_PARAMETER(),
                    "mvpdValidateRingHeader: i_pRingBuf->iv_magic failed "
                    "chipletId=0x%x, ringId=0x%x",
                    i_chipletId,
                    i_ringId);
        FAPI_ASSERT(be16toh(i_pRingBuf->iv_ringId) == i_ringId,
                    fapi2::MVPD_RING_FUNC_INVALID_PARAMETER(),
                    "mvpdValidateRingHeader: i_pRingBuf->iv_ringId failed "
                    "chipletId=0x%x, ringId=0x%x",
                    i_chipletId,
                    i_ringId);
        FAPI_ASSERT((be32toh(i_pRingBuf->iv_scanAddr) & 0xFF000000UL) >> 24
                    == i_chipletId,
                    fapi2::MVPD_RING_FUNC_INVALID_PARAMETER(),
                    "mvpdValidateRingHeader: i_pRingBuf->iv_chipletId failed "
                    "chipletId=0x%x, ringId=0x%x",
                    i_chipletId,
                    i_ringId);
        FAPI_ASSERT(be16toh(i_pRingBuf->iv_size) == i_ringBufsize,
                    fapi2::MVPD_RING_FUNC_INVALID_PARAMETER(),
                    "mvpdValidateRingHeader: i_pRingBuf->iv_size failed "
                    "chipletId=0x%x, ringId=0x%x",
                    i_chipletId,
                    i_ringId);

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
            if  (   i_pCallerRingBuf == NULL )
            {
                io_rCallerRingBufLen = i_ringLen;
                //  break out of do block with success rc
                break;
            }

            //  check if we have enough space
            FAPI_ASSERT(io_rCallerRingBufLen >= i_ringLen,
                        fapi2::MVPD_RING_BUFFER_TOO_SMALL(),
                        "mvpdRingFuncGet: output buffer too small:  "
                        "0x%x < 0x%x",
                        io_rCallerRingBufLen,
                        i_ringLen);

            //  we're good, copy data into the passed-in buffer
            FAPI_DBG( "mvpdRingFuncGet: memcpy 0x%p 0x%p 0x%x",
                      i_pCallerRingBuf,
                      i_pRing,
                      i_ringLen );
            memcpy( i_pCallerRingBuf, i_pRing, i_ringLen );
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

        FAPI_DBG( "mvpdRingFuncGet: exit bufsize= 0x%x rc= 0x%x",
                  io_rCallerRingBufLen,
                  static_cast<uint32_t>(l_fapirc) );

        return l_fapirc;
    }


    /**
     *  @brief MVPD Set Ring Function
     *
     *  @par Detailed Description:
     *           Update the record with the caller's ring.
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
                            fapi2::MVPD_INSUFFICIENT_RECORD_SPACE(),
                            "mvpdRingFuncSet: not enough record space to append");

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
                            fapi2::MVPD_INSUFFICIENT_RECORD_SPACE(),
                            "mvpdRingFuncSet: not enough record space to insert ");

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

            FAPI_ERR( "mvpdRingFuncSet: shouldn't get to here" );

        }
        while (0);

    fapi_try_exit:
        // get current error
        l_fapirc = fapi2::current_err;

        FAPI_DBG( "mvpdRingFuncSet: exit  rc= 0x%x",
                  static_cast<uint32_t>(l_fapirc) );

        return l_fapirc;
    }


}   // extern "C"
