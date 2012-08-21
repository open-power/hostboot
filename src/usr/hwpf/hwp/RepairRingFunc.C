 /*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/RepairRingFunc.C $
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
// $Id: RepairRingFunc.C,v 1.1 2012/07/19 22:00:40 mjjones Exp $
/**
 *  @file RepairRingFunc.C
 *
 *  @brief fetch repair rings from MVPD #R records
 *
 */

#include    <stdint.h>

//  fapi support
#include    <fapi.H>

#include    <RepairRingFunc.H>

//      pull in CompressedScanData def from proc_slw_build HWP
#include <p8_scan_compression.H>

extern "C"
{
using   namespace   fapi;


fapi::ReturnCode getRepairRing( const fapi::Target &i_fapiTarget,
                                const uint8_t       i_chipletId,
                                const uint8_t       i_ringId,
                                uint8_t             *io_pRingBuf,
                                uint32_t            &io_rRingBufsize)
{
    fapi::ReturnCode        l_fapirc( fapi::FAPI_RC_SUCCESS );
    uint8_t                 *l_pRing        =   NULL;
    uint32_t                l_offset        =   0;
    CompressedScanData      *l_pScanData    =   NULL;
    uint8_t                 *l_pdRRecord    =   NULL;
    uint32_t                l_pdRLen        =   0;
    bool                    l_foundflag     =   false;


    FAPI_DBG(" getRepairRing: entry ringId=0x%x, chipletId=0x%x, size=0x%x ",
             i_ringId,
             i_chipletId,
             io_rRingBufsize  );

    do  {

        //  input check
        if  (   io_pRingBuf == NULL )
        {
            FAPI_ERR("getRepairRing: NULL pointer passed in");

            io_rRingBufsize =   0;
            FAPI_SET_HWP_ERROR(l_fapirc, RC_REPAIR_RING_INVALID_RINGBUF_PTR );

            break;
        }

        FAPI_DBG( "getRepairRing: get MVPD #R buffer" );

        //  call fapiGetMvpdField once with a NULL pointer to get the buffer
        //  size no error should be returned.
        l_fapirc = fapiGetMvpdField(  fapi::MVPD_RECORD_CP00,
                                      fapi::MVPD_KEYWORD_PDR,
                                      i_fapiTarget,
                                      NULL,
                                      l_pdRLen );
        if ( l_fapirc )
        {
            FAPI_ERR("getRepairRing: fapiGetMvpdField failed to get buffer size");

            io_rRingBufsize =   0;
            //  break out with fapirc
            break;
        }

        FAPI_DBG( "getRepairRing: fapiGetMvpdField returned l_pdRLen=0x%x",
                  l_pdRLen );

        //  allocate buffer for the record
        l_pdRRecord =   new uint8_t[l_pdRLen];
        // check to make sure it got allocated
        if ( l_pdRRecord == NULL )
        {
            FAPI_ERR( "getRepairRing: failed to alloc buffer");
            FAPI_SET_HWP_ERROR(l_fapirc, RC_REPAIR_RING_ALLOC_FAIL );

            io_rRingBufsize =   0;
            // break out with fapirc
            break;
        }

        //  load repair ring from MVPD for this target
        l_fapirc = fapiGetMvpdField(  fapi::MVPD_RECORD_CP00,
                                      fapi::MVPD_KEYWORD_PDR,
                                      i_fapiTarget,
                                      l_pdRRecord,
                                      l_pdRLen );
        if ( l_fapirc )
        {
            FAPI_ERR("getRepairRing: fapiGetMvpdField failed");

            io_rRingBufsize =   0;
            //  break out with fapirc
            break;
        }

        //  point to #R record
        l_pRing =   l_pdRRecord;
        //
        //  1) Find first RSA data block in #R (fixed offset defined by
        //      MVPD spec)
        //
        //  First byte in #R record should be the version number, skip
        //      over this.
        //
        FAPI_DBG( "getRepairRing: #R record version = 0x%x", *l_pRing );
        l_pRing++;
        l_offset    =   0;

        l_foundflag =   false;
        while ( l_offset < l_pdRLen )
        {
            //  point to header
            l_pScanData =
                reinterpret_cast<CompressedScanData *>( l_pRing+l_offset );

            //  dump record info for debug
            FAPI_DBG(   "getRepairRing: %d ringId=0x%x, size=0x%x, chipletId=0x%x",
                        l_offset,
                        l_pScanData->iv_ringId,
                        l_pScanData->iv_chipletId,
                        l_pScanData->iv_size    );

            //  Check magic key to make sure this is a valid record.
            if ( l_pScanData->iv_magic != RS4_MAGIC )
            {
                FAPI_ERR(   "getRepairRing: Header 0x%x at offset 0x%x, break",
                            l_pScanData->iv_magic,
                            l_offset  );

                //  @todo
                //  test image does not have correct headers, this
                //     returns early.  Revisit this later.
                //
                // $$const   uint32_t    &MAGIC = l_pScanData->magic;
                // $$FAPI_SET_HWP_ERROR(l_fapirc, RC_REPAIR_RING_INVALID_MAGIC );

                // return 0 size to indicate bad record
                io_rRingBufsize =   0;
                // break out of scan loop
                break;
            }


            if (    (l_pScanData->iv_ringId == i_ringId)
                 && (l_pScanData->iv_chipletId == i_chipletId) )
            {
                FAPI_DBG( "getRepairRing: Found it: 0x%x.0x%x, 0x%x",
                          i_ringId,
                          i_chipletId,
                          l_pScanData->iv_size  );

                l_foundflag =   true;
                //  check if we have enough space
                if ( io_rRingBufsize < l_pScanData->iv_size )
                {
                    FAPI_ERR( "getRepairRing: output buffer too small:  0x%x < 0x%x",
                              io_rRingBufsize,
                              l_pScanData->iv_size
                              );

                    //  return actual size of data, so caller can re-try with
                    //  the correct value
                    io_rRingBufsize =   l_pScanData->iv_size;
                    FAPI_SET_HWP_ERROR(l_fapirc, RC_REPAIR_RING_INVALID_SIZE );

                    //  break out of do block with fapi rc set
                    break;
                }

                //  Goodness, return ring and actual size of data.
                io_rRingBufsize =   l_pScanData->iv_size;
                //  we're good, copy data into the passed-in buffer
                memcpy( io_pRingBuf, l_pScanData, io_rRingBufsize );

                FAPI_DBG( "getRepairRing: return record: 0x%x.0x%x %p,  0x%x",
                          i_ringId,
                          i_chipletId,
                          l_pScanData,
                          io_rRingBufsize  );

                // got it, break out of scan loop
                break;
            }

            // bump to next ring
            l_offset +=  l_pScanData->iv_size ;

        }   // end while scan loop

        //  foundflag not set, set error and quit
        //  @todo
        //  revisit here too, this will overwrite RC_REPAIR_INVALID_MAGIC
        //
        if ( ! l_foundflag )
        {
            const   uint32_t    & RING_MODIFIER =   i_ringId;
            FAPI_SET_HWP_ERROR(l_fapirc, RC_REPAIR_RING_NOT_FOUND );

            io_rRingBufsize =   0;
        }

    }  while ( 0 );

    //  unload the repair ring
    if ( l_pdRRecord    != NULL )
    {
        FAPI_DBG( "Unload repair #R record" );

        delete[]  l_pdRRecord;
        l_pdRRecord =   NULL;
        l_pdRLen    =   0;
    }

    FAPI_DBG(" getRepairRing: exit" );

    return  l_fapirc;
}

}   // extern "C"
