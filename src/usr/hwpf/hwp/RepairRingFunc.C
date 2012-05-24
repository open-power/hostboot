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

//
//  @todo :
//      pull in CompressedScanData def from proc_slw_build HWP and then remove
//      the definitions below
// #include <p8_scan_compression.H>
//
/**
 *  @struct RS4 Compressed Scan Header
 */
typedef struct  {
    uint32_t    magic;          // "RSA" + version 01 signature
    uint32_t    size;           // Total size in bytes, including the header
    uint32_t    algorithReserved;   // "reserved to the algorithm"
    uint32_t    length;         // len of original scan chain in BITS
    uint32_t    scanSelect;     // hi 32 bits of the scan select reg
    uint8_t     reserved[3];
    uint8_t     chipletId;      // 7-bit pervasive chiplet Id + Multicast bit
}   CompressedScanData;

/**
 * @def RSA_MAGIC signature - "RSA"+0x01
 */
const   uint32_t    RS4_MAGIC       =   0x52533401;


extern "C"
{
using   namespace   fapi;


fapi::ReturnCode    getRepairRing(  const fapi::Target  &i_fapiTarget,
                                    const uint32_t      i_ringModifier,
                                    uint8_t             *io_pRingBuf,
                                    uint32_t            &io_rRingBufsize )
{
    fapi::ReturnCode        l_fapirc( fapi::FAPI_RC_SUCCESS );
    uint8_t                 *l_pRing        =   NULL;
    uint32_t                l_offset        =   0;
    CompressedScanData      *l_pScanData    =   NULL;
    uint8_t                 *l_pdRRecord    =   NULL;
    uint32_t                l_pdRLen        =   0;
    bool                    l_foundflag     =   false;


    FAPI_DBG(" getRepairRing: entry ringModifier=0x%x, size=0x%x ",
             i_ringModifier,
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

        //  call fapiGetMvpdPdr once with a NULL pointer to get the buffer size
        //  no error should be returned.
        l_fapirc = fapiGetMvpdPdr(  i_fapiTarget,
                                    NULL,
                                    l_pdRLen );
        if ( l_fapirc )
        {
            FAPI_ERR("getRepairRing: fapiGetMvpdPdr failed to get buffer size");

            io_rRingBufsize =   0;
            //  break out with fapirc
            break;
        }

        FAPI_DBG( "getRepairRing: fapiGetMvpdPdr returned l_pdRLen=0x%x",
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
        l_fapirc = fapiGetMvpdPdr(  i_fapiTarget,
                                    l_pdRRecord,
                                    l_pdRLen );
        if ( l_fapirc )
        {
            FAPI_ERR("getRepairRing: fapiGetMvpdPdr failed");

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
            FAPI_DBG(   "getRepairRing: %d scanSelect=0x%x, size=0x%x, chipletId=0x%x",
                        l_offset,
                        l_pScanData->scanSelect,
                        l_pScanData->size,
                        l_pScanData->chipletId  );

            //  Check magic key to make sure this is a valid record.
            if ( l_pScanData->magic != RS4_MAGIC )
            {
                FAPI_ERR(   "getRepairRing: Header 0x%x at offset 0x%x, break",
                            l_pScanData->magic,
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

            //
            //  @TODO Need to do Leon's translation here??
            //      It's not certain that the scanSelect/ringModifier may be
            //      passed in here; if so we will have to do some translating.
            //      Leon Freimour has the translation algorithm.
            //      This will have to wait until Phase II .

            if ( l_pScanData->scanSelect == i_ringModifier )
            {
                FAPI_DBG( "getRepairRing: Found it: 0x%x, 0x%x",
                          i_ringModifier,
                          l_pScanData->size  );

                l_foundflag =   true;
                //  check if we have enough space
                if ( io_rRingBufsize < l_pScanData->size )
                {
                    FAPI_ERR( "getRepairRing: output buffer too small:  0x%x < 0x%x",
                              io_rRingBufsize,
                              l_pScanData->size
                              );

                    //  return actual size of data, so caller can re-try with
                    //  the correct value
                    io_rRingBufsize =   l_pScanData->size;
                    FAPI_SET_HWP_ERROR(l_fapirc, RC_REPAIR_RING_INVALID_SIZE );

                    //  break out of do block with fapi rc set
                    break;
                }

                //  Goodness, return ring and actual size of data.
                io_rRingBufsize =   l_pScanData->size;
                //  we're good, copy data into the passed-in buffer
                memcpy( io_pRingBuf, l_pScanData, io_rRingBufsize );

                FAPI_DBG( "getRepairRing: return record: 0x%x 0x%p,  0x%x",
                          i_ringModifier,
                          l_pScanData,
                          io_rRingBufsize  );

                // got it, break out of scan loop
                break;
            }

            // bump to next ring
            l_offset +=  l_pScanData->size ;

        }   // end while scan loop

        //  foundflag not set, set error and quit
        //  @todo
        //  revisit here too, this will overwrite RC_REPAIR_INVALID_MAGIC
        //
        if ( ! l_foundflag )
        {
            const   uint32_t    & RING_MODIFIER =   i_ringModifier;
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
