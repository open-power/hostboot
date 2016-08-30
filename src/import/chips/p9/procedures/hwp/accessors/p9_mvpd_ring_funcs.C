/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/accessors/p9_mvpd_ring_funcs.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
    fapi2::ReturnCode mvpdRingFunc(const mvpdRingFuncOp i_mvpdRingFuncOp,
                                   fapi2::MvpdRecord    i_record,
                                   fapi2::MvpdKeyword   i_keyword,
                                   const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                                   & i_fapiTarget,
                                   const uint8_t        i_chipletId,
                                   const uint8_t        i_ringId,
                                   uint8_t*             i_pRingBuf,
                                   uint32_t&            io_rRingBufsize)
    {
        fapi2::ReturnCode       l_fapirc = fapi2::FAPI2_RC_SUCCESS;
        uint32_t                l_recordLen  = 0;
        uint8_t*                l_recordBuf  = NULL;
        uint8_t*                l_pRing      = NULL;
        uint32_t                l_ringLen    = 0;

        FAPI_DBG("mvpdRingFunc:entry op=0x%x ringId=0x%x chipletId=0x%x "
                 "size=0x%x",
                 i_mvpdRingFuncOp,
                 i_ringId,
                 i_chipletId,
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
                 "chipletId=0x%x, ringId=0x%x",
                 i_chipletId,
                 i_ringId);

        // find ring in the record. It is an error if not there for a "get".
        // Its ok if not there for a "set". The ring will be added.
        // l_ringLen set to 0 if not there with l_pRing at the start of padding.
        FAPI_TRY(mvpdRingFuncFind(i_fapiTarget,
                                  i_record,
                                  i_keyword,
                                  i_chipletId,
                                  i_ringId,
                                  l_recordBuf,
                                  l_recordLen,
                                  l_pRing,
                                  l_ringLen),
                 "mvpdRingFunc: mvpdRingFuncFind failed "
                 "chipletId=0x%x, ringId=0x%x",
                 i_chipletId,
                 i_ringId);

        // do the get or set specific operations
        if (i_mvpdRingFuncOp == MVPD_RING_GET ) // do the get operation
        {
            // Ensure ring was found. Must be there for "get"
            //@TODO: Uncomment the following after PowerOn. Also, need to come
            //       to agreement whether this should be fatal error or not.
            //       For now, for PO, it's considered benign and noise and is
            //       being commented out... most of it at least.
            FAPI_ASSERT( l_ringLen != 0,
                         fapi2::MVPD_RING_NOT_FOUND().
                         set_CHIP_TARGET(i_fapiTarget) );
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
                     "chipletId=0x%x, ringId=0x%x",
                     i_chipletId,
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


    /**
     *  @brief MVPD Ring Function Find
     *
     *  @par Detailed Description:
     *           Step through the record looking at rings for a match.
     *
     *  @param[in]  i_chipletId
     *                   Chiplet ID for the op
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
    fapi2::ReturnCode mvpdRingFuncFind(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                                       & i_fapiTarget,
                                       fapi2::MvpdRecord    i_record,
                                       fapi2::MvpdKeyword   i_keyword,
                                       const uint8_t    i_chipletId,
                                       const uint8_t    i_ringId,
                                       uint8_t*         i_pRecordBuf,
                                       uint32_t         i_recordBufLen,
                                       uint8_t*&        o_rpRing,
                                       uint32_t&        o_rRingLen)
    {
        fapi2::ReturnCode       l_fapirc;
        uint8_t*                l_pRing         =   NULL;
        uint32_t                l_offset        =   0;
        CompressedScanData*     l_pScanData     =   NULL;
        bool                    l_foundflag     =   false;

        // initialize return fields in case of an error.
        o_rpRing = NULL;
        o_rRingLen = 0;

        FAPI_DBG("mvpdRingFuncFind: entry chipletId=0x%x, ringId=0x%x ",
                 i_chipletId,
                 i_ringId  );

        do
        {
            //  Point to record
            l_pRing =   i_pRecordBuf;

            //  Find first RSA data block in ring (fixed offset defined by
            //      MVPD spec)
            //
            //  First byte in record should be the version number, skip
            //      over this.
            //
            FAPI_DBG( "mvpdRingFuncFind: record version = 0x%x", *l_pRing );
            l_pRing++;
            l_offset    =   0;

            // point to header of first ring in record
            l_pScanData =
                reinterpret_cast<CompressedScanData*>( l_pRing + l_offset );

            l_foundflag =   false;

            // be sure that data we will look at is within the passed buffer
            while ( (l_offset + be32toh(l_pScanData->iv_size)) < i_recordBufLen )
            {

                // There's only two valid header words that may appear in the Mvpd record:
                // - MVPD_END_OF_DATA_MAGIC which indicates end of the data with a record.
                // - RS4_MAGIC which indicates the beginning of another VPD ring.
                // - Anything else is a catastrophic failure.

                // Check for end of data magic word
                if ((be32toh(l_pScanData->iv_magic) & 0xffffff00) == (MVPD_END_OF_DATA_MAGIC & 0xffffff00))
                {
                    FAPI_DBG("mvpdRingFuncFind: Found end of data magic word (=0x%08X): "
                             "offset=0x%x, chipletId=0x%x, ringId=0x%x",
                             be32toh(l_pScanData->iv_magic),
                             l_offset,
                             i_chipletId,
                             i_ringId);
                    break;
                }

                // Check magic word to make sure this is valid data.
                FAPI_ASSERT( (be32toh(l_pScanData->iv_magic) & 0xffffff00) == (RS4_MAGIC & 0xffffff00),
                             fapi2::MVPD_INVALID_RS4_HEADER().
                             set_CHIP_TARGET(i_fapiTarget).
                             set_MVPD_RECORD(i_record).
                             set_MVPD_KEYWORD(i_keyword),
                             "mvpdRingFuncFind: Couldn't find RS4 or End-of-data magic word in header: "
                             "Header=0x%x, offset=0x%x, ringId=0x%x, chipletId=0x%x",
                             be32toh(l_pScanData->iv_magic),
                             l_offset,
                             i_ringId,
                             i_chipletId );

                // We can now assume good data...

                // Dump record info for debug
                FAPI_DBG("mvpdRingFuncFind:%d ringId=0x%x chipletId=0x%x"
                         " ringlen=0x%x size=0x%x",
                         l_offset,
                         l_pScanData->iv_ringId,
                         l_pScanData->iv_chipletId,
                         be32toh(l_pScanData->iv_length),
                         be32toh(l_pScanData->iv_size) );


                if ( (l_pScanData->iv_ringId == i_ringId)
                     && (l_pScanData->iv_chipletId == i_chipletId) )
                {
                    FAPI_DBG( "mvpdRingFuncFind: Found it: ringId=0x%x, "
                              "chiplet=0x%x, ringlen=0x%x",
                              i_ringId,
                              i_chipletId,
                              be32toh(l_pScanData->iv_length) );

                    // shouldn't happen, but does not all fit
                    FAPI_ASSERT(l_offset + be32toh(l_pScanData->iv_size) <=
                                i_recordBufLen,
                                fapi2::MVPD_INSUFFICIENT_RECORD_SPACE(),
                                "mvpdRingFuncFind: data does not fit "
                                "into record buffer: ringId=0x%x, chipletId=0x%x",
                                i_ringId,
                                i_chipletId );

                    l_foundflag =   true;
                    o_rpRing = l_pRing + l_offset;
                    o_rRingLen = be32toh(l_pScanData->iv_size);
                    // got it, break out of scan loop
                    break;
                }

                // being defensive.
                if ( be32toh(l_pScanData->iv_size) == 0)
                {
                    // size of 0 is invalid, would loop forever.
                    break;
                }

                // bump to next ring
                l_offset += be32toh(l_pScanData->iv_size) ;

                //  point to header
                l_pScanData =
                    reinterpret_cast<CompressedScanData*>( l_pRing + l_offset );


            }   // end while scan loop

            //  if no other error and not found, indicate with 0 size.
            if ( !l_fapirc && ! l_foundflag )
            {
                o_rpRing = l_pRing + l_offset; //return pointer to end of list
                //incase needed for appending
                o_rRingLen = 0;            //indicate not found
            }

        }
        while ( 0 );

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
    fapi2::ReturnCode mvpdValidateRingHeader( CompressedScanData* i_pRingBuf,
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
        FAPI_ASSERT((be32toh(i_pRingBuf->iv_magic) & 0xffffff00) == (RS4_MAGIC & 0xffffff00),
                    fapi2::MVPD_RING_FUNC_INVALID_PARAMETER(),
                    "mvpdValidateRingHeader: i_pRingBuf->iv_magic failed "
                    "chipletId=0x%x, ringId=0x%x",
                    i_chipletId,
                    i_ringId);
        FAPI_ASSERT(i_pRingBuf->iv_ringId == i_ringId,
                    fapi2::MVPD_RING_FUNC_INVALID_PARAMETER(),
                    "mvpdValidateRingHeader: i_pRingBuf->iv_ringId failed "
                    "chipletId=0x%x, ringId=0x%x",
                    i_chipletId,
                    i_ringId);
        FAPI_ASSERT(i_pRingBuf->iv_chipletId == i_chipletId,
                    fapi2::MVPD_RING_FUNC_INVALID_PARAMETER(),
                    "mvpdValidateRingHeader: i_pRingBuf->iv_chipletId failed "
                    "chipletId=0x%x, ringId=0x%x",
                    i_chipletId,
                    i_ringId);
        FAPI_ASSERT(be32toh(i_pRingBuf->iv_size) == i_ringBufsize,
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
