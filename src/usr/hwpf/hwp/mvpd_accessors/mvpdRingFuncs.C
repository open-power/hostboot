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
 *  @file mvpdRingFuncs.C
 *
 *  @brief common routines
 *
 */

#include    <stdint.h>

//  fapi support
#include    <fapi.H>

#include    <mvpdRingFuncs.H>

//      pull in CompressedScanData def from proc_slw_build HWP
#include <p8_scan_compression.H>

extern "C"
{
using   namespace   fapi;

fapi::ReturnCode findMvpdRingField( const uint8_t   i_chipletId,
                                const uint8_t       i_ringId,
                                uint8_t     * const i_pFieldBuf,
                                uint32_t            i_fieldBufsize,
                                uint8_t           * &o_rRingBuf,
                                uint32_t            &o_rRingBufsize)
{
    fapi::ReturnCode        l_fapirc;
    uint8_t                 *l_pRing        =   NULL;
    uint32_t                l_offset        =   0;
    CompressedScanData      *l_pScanData    =   NULL;
    bool                    l_foundflag     =   false;

    // initialize return fields in case of an error.
    o_rRingBuf=NULL;
    o_rRingBufsize=0;

    FAPI_DBG(" findMvpdRingField: entry chipletId=0x%x, ringId=0x%x ",
             i_chipletId,
             i_ringId  );

    do  {
        //  point to #R record
        l_pRing =   i_pFieldBuf;

        //
        //  Find first RSA data block in #R (fixed offset defined by
        //      MVPD spec)
        //
        //  First byte in #R record should be the version number, skip
        //      over this.
        //
        FAPI_DBG( "findMvpdRingField: #R record version = 0x%x", *l_pRing );
        l_pRing++;
        l_offset    =   0;

        l_foundflag =   false;
        // be sure that data we will look at is within the passed buffer
        while ( l_offset+sizeof(CompressedScanData) < i_fieldBufsize )
        {
            //  point to header
            l_pScanData =
                reinterpret_cast<CompressedScanData *>( l_pRing+l_offset );

            //  Check magic key to make sure this is a valid record.
            if ( l_pScanData->iv_magic != RS4_MAGIC )
            {
                FAPI_ERR(   "findMvpdRingField: Header 0x%x at offset 0x%x,hit end of list",
                            l_pScanData->iv_magic,
                            l_offset  );

                //  TODO: RTC 51917 how to tell the end of the list? Assume that
                // finding a header without RS4_MAGIC is the end.
                //  TODO: RTC 51716 test image does not have correct header
                //
                // keep the following incase there is a different way to find 
                // the end. 
                // $$const   uint32_t    &MAGIC = l_pScanData->magic;
                // $$FAPI_SET_HWP_ERROR(l_fapirc, RC_REPAIR_RING_INVALID_MAGIC );
                // break out of scan loop, ring not found
                break;
            }
            //  dump record info for debug
            FAPI_DBG(   "findMvpdRingField: %d ringId=0x%x, chipletId=0x%x, size=0x%x",
                        l_offset,
                        l_pScanData->iv_ringId,
                        l_pScanData->iv_chipletId,
                        l_pScanData->iv_size    );


            if (    (l_pScanData->iv_ringId == i_ringId)
                 && (l_pScanData->iv_chipletId == i_chipletId) )
            {
                FAPI_DBG( "findMvpdRingField: Found it: 0x%x.0x%x, 0x%x",
                          i_ringId,
                          i_chipletId,
                          l_pScanData->iv_size  );

                if (l_offset+l_pScanData->iv_size > i_fieldBufsize) 
                {
                    // shouldn't happen, but does not all fit
                    FAPI_SET_HWP_ERROR(l_fapirc, RC_REPAIR_RING_INVALID_SIZE );
                    break;
                }
                l_foundflag =   true;
                o_rRingBuf = l_pRing+l_offset;
                o_rRingBufsize=l_pScanData->iv_size;
                // got it, break out of scan loop
                break;
            }

            // being defensive.
            if (l_pScanData->iv_size == 0)
            {
                // size of 0 is invalid, would loop forever.
                break;
            }
            // bump to next ring
            l_offset +=  l_pScanData->iv_size ;

        }   // end while scan loop

        //  foundflag not set, set error if no other error
        if ( !l_fapirc && ! l_foundflag )
        {
            const   uint8_t    & RING_MODIFIER =   i_ringId;
            const   uint8_t    & CHIPLET_ID =   i_chipletId;
            FAPI_SET_HWP_ERROR(l_fapirc, RC_REPAIR_RING_NOT_FOUND );
        }

    }  while ( 0 );


    FAPI_DBG(" findMvpdRingField: exit RC=0x%x",
                          static_cast<uint32_t>(l_fapirc) );

    return  l_fapirc;
}

}   // extern "C"
