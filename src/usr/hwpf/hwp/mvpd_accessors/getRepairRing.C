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
 *  @file getRepairRing.C
 *
 *  @brief fetch repair rings from MVPD #R records
 *
 */

#include    <stdint.h>

//  fapi support
#include    <fapi.H>

#include    <getRepairRing.H>
#include    <mvpdRingFuncs.H>

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
    fapi::ReturnCode        l_fapirc;
    uint8_t                 *l_pRing        =   NULL;
    uint8_t                 *l_pdRRecord    =   NULL;
    uint32_t                l_pdRLen        =   0;
    uint32_t                l_ringLen       =   0;


    FAPI_DBG(" getRepairRing: entry ringId=0x%x, chipletId=0x%x, size=0x%x ",
             i_ringId,
             i_chipletId,
             io_rRingBufsize  );

    do  {

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

        //  allocate buffer for the record. Always works. 
        l_pdRRecord =   new uint8_t[l_pdRLen];

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

        // find ring in Field
        l_fapirc = findMvpdRingField (i_chipletId,
                                      i_ringId,
                                      l_pdRRecord,
                                      l_pdRLen,
                                      l_pRing,
                                      l_ringLen);
        if ( l_fapirc )
        {
            FAPI_ERR("getRepairRing: findMvpdRing failed");

            io_rRingBufsize =   0;
            //  break out with fapirc
            break;
        }
        //  return buffer pointer is NULL if just looking for the size
        if  (   io_pRingBuf == NULL )
        {
            io_rRingBufsize = l_ringLen;
            //  break out of do block with success rc 
            break;
        }
        //  check if we have enough space
        if ( io_rRingBufsize < l_ringLen )
        {
            FAPI_ERR( "getRepairRing: output buffer too small:  0x%x < 0x%x",
                          io_rRingBufsize,
                          l_ringLen
                          );

           //  return actual size of data, so caller can re-try with
           //  the correct value
           io_rRingBufsize =   l_ringLen;
           FAPI_SET_HWP_ERROR(l_fapirc, RC_REPAIR_RING_INVALID_SIZE );

           //  break out of do block with fapi rc set
               break;
        }
        //  we're good, copy data into the passed-in buffer
        memcpy( io_pRingBuf, l_pRing, l_ringLen );
        io_rRingBufsize =   l_ringLen;

        FAPI_DBG( "getRepairRing: return record: 0x%x.0x%x %p,  0x%x",
                          i_ringId,
                          i_chipletId,
                          io_pRingBuf,
                          io_rRingBufsize  );

    }  while ( 0 );

    //  unload the repair ring
    delete[]  l_pdRRecord;
    l_pdRRecord =   NULL;

    FAPI_DBG(" getRepairRing: exit rc=0x%x",
               static_cast<uint32_t>(l_fapirc) );

    return  l_fapirc;
}

}   // extern "C"
