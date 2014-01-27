/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mvpd_accessors/mvpdRingFuncs.C $             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: mvpdRingFuncs.C,v 1.9 2014/02/12 22:14:51 mjjones Exp $
/**
 *  @file mvpdRingFuncs.C
 *
 *  @brief common routines
 *
 */

#include    <stdint.h>

//  fapi support
#include    <fapi.H>
#include    <fapiUtil.H>
#include    <mvpdRingFuncs.H>

//      pull in CompressedScanData def from proc_slw_build HWP
#include <p8_scan_compression.H>

extern "C"
{
using   namespace   fapi;

// functions internal to this file
// these functions are common for both mvpdRingFunc and mbvpdRingFunc
fapi::ReturnCode mvpdValidateRingHeader( CompressedScanData * i_pRing,
                                     uint8_t              i_chipletId,
                                     uint8_t              i_ringId,
                                     uint32_t             i_ringBufsize);

fapi::ReturnCode mvpdRingFuncFind( const uint8_t   i_chipletId,
                               const uint8_t       i_ringId,
                               uint8_t           * i_pRecordBuf,
                               uint32_t            i_recordBufLen,
                               uint8_t           * &o_rRingBuf,
                               uint32_t            &o_rRingBufsize);

fapi::ReturnCode mvpdRingFuncGet ( uint8_t *i_pRing,
                               uint32_t     i_ringLen,
                               uint8_t     *i_pCallerRingBuf,
                               uint32_t    &io_rCallerRingBufLen);

fapi::ReturnCode mvpdRingFuncSet ( uint8_t *i_pRecordBuf,
                               uint32_t     i_recordLen,
                               uint8_t     *i_pRing,
                               uint32_t     i_ringLen,
                               uint8_t     *i_pCallerRingBuf,
                               uint32_t     i_callerRingBufLen);

//******************************************************************************
// mvpdValidateRecordKeyword & mbvpdValidateRecordKeyword
// Check for supported combinations of Record and Keyword.
// The record needs to contain rings of RS4 header (CompressedScanData) format
//  note: "getting" data not in RS4 header format would likely just fail to find
//  the ring harmlessly.  "Setting" data could make a mess looking for the end
//  to append a new ring. The result could be invalid vpd.
//  note: place first in the file to make finding the supported list easier.
//******************************************************************************
fapi::ReturnCode mvpdValidateRecordKeyword( fapi::MvpdRecord i_record,
                                            fapi::MvpdKeyword i_keyword)
{
    // add record/keywords with rings with RS4 header here.
    struct _supportedRecordKeywords {
                                fapi::MvpdRecord record;
                                fapi::MvpdKeyword keyword;
    } supportedRecordKeywords [] = {
        { MVPD_RECORD_CP00, MVPD_KEYWORD_PDR },
        { MVPD_RECORD_CP00, MVPD_KEYWORD_PDG },
    };
    fapi::ReturnCode        l_fapirc;
    bool l_validPair = false;
    const uint32_t numPairs =
             sizeof(supportedRecordKeywords)/sizeof(supportedRecordKeywords[0]);

    for (uint32_t curPair = 0; curPair < numPairs; curPair++ )
    {
        if (supportedRecordKeywords[curPair].record == i_record &&
            supportedRecordKeywords[curPair].keyword == i_keyword)
        {
            l_validPair = true;
            break;
        }
    }
    if ( !l_validPair ) {
        FAPI_SET_HWP_ERROR(l_fapirc, RC_MVPD_RING_FUNC_INVALID_PARAMETER );
     }
    return l_fapirc;

};

fapi::ReturnCode mbvpdValidateRecordKeyword(fapi::MBvpdRecord i_record,
                                            fapi::MBvpdKeyword i_keyword)
{
    // add record/keywords with rings with RS4 header here.
    struct _supportedRecordKeywords {
                                fapi::MBvpdRecord record;
                                fapi::MBvpdKeyword keyword;
    } supportedRecordKeywords [] = {
        { MBVPD_RECORD_VSPD, MBVPD_KEYWORD_PDD },
    };

    fapi::ReturnCode l_fapirc;
    bool l_validPair = false;

    const uint32_t numPairs =
             sizeof(supportedRecordKeywords)/sizeof(supportedRecordKeywords[0]);

    for (uint32_t curPair = 0; curPair < numPairs; curPair++ )
    {
        if (supportedRecordKeywords[curPair].record == i_record &&
            supportedRecordKeywords[curPair].keyword == i_keyword)
        {
            l_validPair = true;
            break;
        }
    }
    if (!l_validPair)
    {
        FAPI_SET_HWP_ERROR(l_fapirc, RC_MBVPD_RING_FUNC_INVALID_PARAMETER );
    }
    return l_fapirc;

};

//******************************************************************************
// mvpdRingFunc: the getMvpdRing and setMvpdRing wrappers call this function
//               to do all the processing.
// note: io_rRingBufsize is only 'output' for get.
//******************************************************************************
fapi::ReturnCode mvpdRingFunc(  const mvpdRingFuncOp i_mvpdRingFuncOp,
                                fapi::MvpdRecord i_record,
                                fapi::MvpdKeyword i_keyword,
                                const fapi::Target   &i_fapiTarget,
                                const uint8_t        i_chipletId,
                                const uint8_t        i_ringId,
                                uint8_t              *i_pRingBuf,
                                uint32_t             &io_rRingBufsize)
{
    fapi::ReturnCode        l_fapirc;
    uint32_t                l_recordLen  = 0;
    uint8_t                 *l_recordBuf = NULL;
    uint8_t                 *l_pRing     = NULL;
    uint32_t                l_ringLen    = 0;

   FAPI_DBG("mvpdRingFunc:entry op=0x%x ringId=0x%x chipletId=0x%x size=0x%x ",
             i_mvpdRingFuncOp,
             i_ringId,
             i_chipletId,
             io_rRingBufsize  );

    do {
        // do common get and set input parameter error checks
        // check for supported combination of Record and Keyword
        l_fapirc = mvpdValidateRecordKeyword( i_record,
                                              i_keyword);
        if ( l_fapirc )
        {
             FAPI_ERR(" mvpdRingFunc: unsupported record keyword pair ");

            //  break out with fapirc
            break;
        }

        // do set specific input parameter checks
        if (i_mvpdRingFuncOp == MVPD_RING_SET )
        {
            // passing NULL pointer to receive needed size is only for get.
            if (i_pRingBuf == NULL )
            {
                FAPI_SET_HWP_ERROR(l_fapirc,
                                    RC_MVPD_RING_FUNC_INVALID_PARAMETER );
                //  break out with fapirc
                break;
            }

            // Validate ring header to protect vpd
            l_fapirc =  mvpdValidateRingHeader(
                         reinterpret_cast<CompressedScanData *>(i_pRingBuf),
                         i_chipletId,
                         i_ringId,
                         io_rRingBufsize);
            if ( l_fapirc )
            {
                FAPI_ERR(" mvpdRingFunc: invalid ring header ");
                //  break out with fapirc
                break;
            }

        }

        //  call fapiGetMvpdField once with a NULL pointer to get the buffer
        //  size no error should be returned.
        l_fapirc = fapiGetMvpdField(  i_record,
                                      i_keyword,
                                      i_fapiTarget,
                                      NULL,
                                      l_recordLen );
        if ( l_fapirc )
        {
            FAPI_ERR("mvpdRingFunc:fapiGetMvpdField failed to get buffer size");

            //  break out with fapirc
            break;
        }

        FAPI_DBG( "mvpdRingFunc: fapiGetMvpdField returned record len=0x%x",
                  l_recordLen );

        //  allocate buffer for the record. Always works
        l_recordBuf =   new uint8_t[l_recordLen];

        //  load ring from MVPD for this target
        l_fapirc = fapiGetMvpdField(  i_record,
                                      i_keyword,
                                      i_fapiTarget,
                                      l_recordBuf,
                                      l_recordLen );
        if ( l_fapirc )
        {
            FAPI_ERR("mvpdRingFunc: fapiGetMvpdField failed rc=0x%x",
                     static_cast<uint32_t>(l_fapirc));
            //  break out with fapirc
            break;
        }

        // find ring in the record. It is an error if not there for a "get".
        // Its ok if not there for a "set". The ring will be added.
        // l_ringLen set to 0 if not there with l_pRing at the start of padding.
        l_fapirc = mvpdRingFuncFind (i_chipletId,
                                     i_ringId,
                                     l_recordBuf,
                                     l_recordLen,
                                     l_pRing,
                                     l_ringLen);
        if ( l_fapirc )
        {
            FAPI_ERR("mvpdRingFunc: mvpdRingFuncFind failed rc=0x%x",
                     static_cast<uint32_t>(l_fapirc));
            //  break out with fapirc
            break;
        }
        // do the get or set specific operations
        if (i_mvpdRingFuncOp == MVPD_RING_GET ) // do the get operation
        {
            // ensure ring was found. Must be there for "get"
            if (l_ringLen == 0)  //not found
            {
                const   uint8_t    & RING_MODIFIER =   i_ringId;
                const   uint8_t    & CHIPLET_ID =   i_chipletId;
                const fapi::Target & CHIP_TARGET = i_fapiTarget;
                FAPI_SET_HWP_ERROR(l_fapirc, RC_REPAIR_RING_NOT_FOUND );
                //  break out with fapirc
                break;
            }

            // copy ring back to caller's buffer
            l_fapirc = mvpdRingFuncGet ( l_pRing,
                                         l_ringLen,
                                         i_pRingBuf,
                                         io_rRingBufsize);
            if ( l_fapirc )
            {
                FAPI_ERR("mvpdRingFunc: mvpdRingFuncGet failed rc=0x%x",
                     static_cast<uint32_t>(l_fapirc));
                //  break out with fapirc
                break;
            }

        } else {     // set operation

            // update record with caller's ring
            l_fapirc = mvpdRingFuncSet ( l_recordBuf,
                                         l_recordLen,
                                         l_pRing,
                                         l_ringLen,
                                         i_pRingBuf,
                                         io_rRingBufsize);
            if ( l_fapirc )
            {
                FAPI_ERR("mvpdRingFunc: mvpdRingFuncSet failed rc=0x%x",
                     static_cast<uint32_t>(l_fapirc));
                //  break out with fapirc
                break;
            }
            // update record back to the mvpd
            l_fapirc = fapiSetMvpdField(i_record,
                                      i_keyword,
                                      i_fapiTarget,
                                      l_recordBuf,
                                      l_recordLen );
            if ( l_fapirc )
            {
                FAPI_ERR("mvpdRingFunc: fapiSetMvpdField failed");

                io_rRingBufsize =   0;
                //  break out with fapirc
               break;
            }
        }


    } while ( 0 );

    //  unload the repair ring
    delete[]  l_recordBuf;
    l_recordBuf =   NULL;

    FAPI_DBG( "mvpdRingFunc: exit bufsize= 0x%x rc= 0x%x",
                          io_rRingBufsize,
                          static_cast<uint32_t>(l_fapirc) );
    return  l_fapirc;
}

//******************************************************************************
// mbvpdRingFunc: getMBvpdRing calls this function to get repair ring
// note: io_rRingBufsize is only 'output' for get.
//******************************************************************************
fapi::ReturnCode mbvpdRingFunc( const mbvpdRingFuncOp i_mbvpdRingFuncOp,
                                fapi::MBvpdRecord i_record,
                                fapi::MBvpdKeyword i_keyword,
                                const fapi::Target &i_fapiTarget,
                                const uint8_t i_chipletId,
                                const uint8_t i_ringId,
                                uint8_t *i_pRingBuf,
                                uint32_t &io_rRingBufsize)
{
    fapi::ReturnCode l_fapirc;
    uint32_t l_recordLen = 0;
    uint8_t *l_recordBuf = NULL;
    uint8_t *l_pRing = NULL;
    uint32_t l_ringLen = 0;

   FAPI_DBG("mbvpdRingFunc:entry op=0x%x ringId=0x%x chipletId=0x%x size=0x%x ",
             i_mbvpdRingFuncOp, i_ringId, i_chipletId, io_rRingBufsize  );

    do {
        // do input parameter error checks
        // check for supported combination of Record and Keyword
        l_fapirc = mbvpdValidateRecordKeyword( i_record, i_keyword);

        if (l_fapirc)
        {
             FAPI_ERR(" mbvpdRingFunc: unsupported record keyword pair ");
            //  break out with fapirc
            break;
        }

        //  call fapiGetMBvpdField once with a NULL pointer to get the buffer
        //  size no error should be returned.
        l_fapirc = fapiGetMBvpdField( i_record,
                                      i_keyword,
                                      i_fapiTarget,
                                      NULL,
                                      l_recordLen );
        if (l_fapirc)
        {
            FAPI_ERR("mbvpdRingFunc:fapiGetMBvpdField failed"
                         " to get buffer size");
            //  break out with fapirc
            break;
        }

        FAPI_DBG("mbvpdRingFunc: fapiGetMBvpdField returned record len=0x%x",
                  l_recordLen );

        //  allocate buffer for the record. Always works
        l_recordBuf = new uint8_t[l_recordLen];

        //  load ring from MBVPD for this target
        l_fapirc = fapiGetMBvpdField( i_record,
                                      i_keyword,
                                      i_fapiTarget,
                                      l_recordBuf,
                                      l_recordLen );
        if (l_fapirc)
        {
            FAPI_ERR("mbvpdRingFunc: fapiGetMBvpdField failed rc=0x%x",
                     static_cast<uint32_t>(l_fapirc));
            //  break out with fapirc
            break;
        }

        // find ring in the record. It is an error if not there for a "get".
        l_fapirc = mvpdRingFuncFind ( i_chipletId,
                                  i_ringId,
                                  l_recordBuf,
                                  l_recordLen,
                                  l_pRing,
                                  l_ringLen);
        if (l_fapirc)
        {
            FAPI_ERR("mbvpdRingFunc: mvpdRingFuncFind failed rc=0x%x",
                     static_cast<uint32_t>(l_fapirc));
            //  break out with fapirc
            break;
        }
        // do the get operations
        if (i_mbvpdRingFuncOp == MBVPD_RING_GET) // do the get operation
        {
            // ensure ring was found. Must be there for "get"
            if (l_ringLen == 0)  //not found
            {
                const uint8_t & RING_MODIFIER = i_ringId;
                const uint8_t & CHIPLET_ID = i_chipletId;
                const fapi::Target & CHIP_TARGET = i_fapiTarget;
                FAPI_SET_HWP_ERROR(l_fapirc, RC_REPAIR_RING_NOT_FOUND );
                //  break out with fapirc
                break;
            }

            // copy ring back to caller's buffer
            l_fapirc = mvpdRingFuncGet ( l_pRing,
                                     l_ringLen,
                                     i_pRingBuf,
                                     io_rRingBufsize);
            if (l_fapirc)
            {
                FAPI_ERR("mbvpdRingFunc: mvpdRingFuncGet failed rc=0x%x",
                     static_cast<uint32_t>(l_fapirc));
                //  break out with fapirc
                break;
            }
        }
        else
        {
            // Set operation has been removed, if need to be implemented
            //copy over from mvpdRingFuncs
            FAPI_ERR("mbvpdRingFunc: Invalid parameter function");
            FAPI_SET_HWP_ERROR(l_fapirc, RC_MBVPD_RING_FUNC_INVALID_PARAMETER);
        }

    } while ( 0 );

    //  unload the repair ring
    delete[]  l_recordBuf;
    l_recordBuf =   NULL;

    FAPI_DBG( "mbvpdRingFunc: exit bufsize= 0x%x rc= 0x%x",
                          io_rRingBufsize,
                          static_cast<uint32_t>(l_fapirc) );
    return  l_fapirc;
}



//******************************************************************************
// mvpdRingFuncFind: step through the record looking at rings for a match.
// o_rpRing returns a pointer to the ring if it is there in the record
//          if not there, returns a pointer to the start of the padding after
//          the last ring.
// o_rRingLen returns the number of bytes in the ring (header and data)
//          Will be 0 if ring not found.
//******************************************************************************
fapi::ReturnCode mvpdRingFuncFind( const uint8_t    i_chipletId,
                                const uint8_t       i_ringId,
                                uint8_t           * i_pRecordBuf,
                                uint32_t            i_recordBufLen,
                                uint8_t           * &o_rpRing,
                                uint32_t            &o_rRingLen)
{
    fapi::ReturnCode        l_fapirc;
    uint8_t                 *l_pRing        =   NULL;
    uint32_t                l_offset        =   0;
    CompressedScanData      *l_pScanData    =   NULL;
    bool                    l_foundflag     =   false;

    // initialize return fields in case of an error.
    o_rpRing=NULL;
    o_rRingLen=0;

    FAPI_DBG("mvpdRingFuncFind: entry chipletId=0x%x, ringId=0x%x ",
             i_chipletId,
             i_ringId  );

    do  {
        //  point to #R record
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

        l_foundflag =   false;
        // be sure that data we will look at is within the passed buffer
        while ( l_offset+sizeof(CompressedScanData) < i_recordBufLen )
        {
            //  point to header
            l_pScanData =
                reinterpret_cast<CompressedScanData *>( l_pRing+l_offset );

            //  Check magic key to make sure this is a valid record.
            if ( FAPI_BE32TOH(l_pScanData->iv_magic) != RS4_MAGIC )
            {
                FAPI_DBG("mvpdRingFuncFind:Header 0x%x offset 0x%x,end of list",
                            FAPI_BE32TOH(l_pScanData->iv_magic),
                            l_offset  );
                break;
            }
            //  dump record info for debug
            FAPI_DBG("mvpdRingFuncFind:%d ringId=0x%x chipletId=0x%x"
                        " ringlen=0x%x size=0x%x",
                        l_offset,
                        l_pScanData->iv_ringId,
                        l_pScanData->iv_chipletId,
                        FAPI_BE32TOH(l_pScanData->iv_length),
                        FAPI_BE32TOH(l_pScanData->iv_size)  );


            if (    (l_pScanData->iv_ringId == i_ringId)
                 && (l_pScanData->iv_chipletId == i_chipletId) )
            {
                FAPI_DBG( "mvpdRingFuncFind: Found it: ring=0x%x, chiplet=0x%x,"
                          " ringlen=0x%x",
                          i_ringId,
                          i_chipletId,
                          FAPI_BE32TOH(l_pScanData->iv_length) );

                if (l_offset+FAPI_BE32TOH(l_pScanData->iv_size)>i_recordBufLen)
                {
                    // shouldn't happen, but does not all fit
                    FAPI_SET_HWP_ERROR(l_fapirc, RC_REPAIR_RING_INVALID_SIZE );
                    break;
                }
                l_foundflag =   true;
                o_rpRing = l_pRing+l_offset;
                o_rRingLen=FAPI_BE32TOH(l_pScanData->iv_size);
                // got it, break out of scan loop
                break;
            }

            // being defensive.
            if (FAPI_BE32TOH(l_pScanData->iv_size) == 0)
            {
                // size of 0 is invalid, would loop forever.
                break;
            }
            // bump to next ring
            l_offset +=  FAPI_BE32TOH(l_pScanData->iv_size) ;

        }   // end while scan loop

        //  if no other error and not found, indicate with 0 size.
        if ( !l_fapirc && ! l_foundflag )
        {
            o_rpRing = l_pRing+l_offset; //return pointer to end of list
                                           //incase needed for appending
            o_rRingLen=0;              //indicate not found
        }

    }  while ( 0 );


    FAPI_DBG("mvpdRingFuncFind: exit *ring= 0x%p", o_rpRing);
    FAPI_IMP("mvpdRingFuncFind: exit chipletId=0x%x, ringId=0x%x size=0x%x"
                          " rc=0x%x",
                          i_chipletId,
                          i_ringId,
                          o_rRingLen,
                          static_cast<uint32_t>(l_fapirc) );

    return  l_fapirc;
}

//******************************************************************************
// mvpdValidateRingHeader
//******************************************************************************
fapi::ReturnCode mvpdValidateRingHeader( CompressedScanData * i_pRingBuf,
                                     uint8_t              i_chipletId,
                                     uint8_t              i_ringId,
                                     uint32_t             i_ringBufsize)
{
    fapi::ReturnCode        l_fapirc;

    if ( i_ringBufsize <= sizeof(CompressedScanData) ||
                FAPI_BE32TOH(i_pRingBuf->iv_magic) != RS4_MAGIC ||
                i_pRingBuf->iv_ringId != i_ringId ||
                i_pRingBuf->iv_chipletId != i_chipletId ||
                FAPI_BE32TOH(i_pRingBuf->iv_size) != i_ringBufsize)
   {
       FAPI_SET_HWP_ERROR(l_fapirc, RC_MVPD_RING_FUNC_INVALID_PARAMETER );
   }
   return l_fapirc;
}

//******************************************************************************
// mvpdRingFuncGet: copy the ring back to the caller
//******************************************************************************
fapi::ReturnCode mvpdRingFuncGet ( uint8_t     *i_pRing,
                               uint32_t     i_ringLen,
                               uint8_t     *i_pCallerRingBuf,
                               uint32_t    &io_rCallerRingBufLen)
{
    fapi::ReturnCode        l_fapirc;

    do {
        //  return buffer pointer is NULL if just looking for the size
        if  (   i_pCallerRingBuf == NULL )
        {
            io_rCallerRingBufLen = i_ringLen;
            //  break out of do block with success rc
            break;
        }
        //  check if we have enough space
        if ( io_rCallerRingBufLen < i_ringLen )
        {
            FAPI_ERR( "mvpdRingFuncGet: output buffer too small:  0x%x < 0x%x",
                          io_rCallerRingBufLen,
                          i_ringLen
                          );

            //  return actual size of data, so caller can re-try with
            //  the correct value
            io_rCallerRingBufLen =   i_ringLen;
            FAPI_SET_HWP_ERROR(l_fapirc, RC_REPAIR_RING_INVALID_SIZE );

            //  break out of do block with fapi rc set
            break;
        }
       //  we're good, copy data into the passed-in buffer
       FAPI_DBG( "mvpdRingFuncGet: memcpy 0x%p 0x%p 0x%x",
                    i_pCallerRingBuf,
                    i_pRing,
                    i_ringLen );
       memcpy( i_pCallerRingBuf, i_pRing, i_ringLen );
       io_rCallerRingBufLen =   i_ringLen;

   }  while (0);

   FAPI_DBG( "mvpdRingFuncGet: exit bufsize= 0x%x rc= 0x%x",
                          io_rCallerRingBufLen,
                          static_cast<uint32_t>(l_fapirc) );

   return l_fapirc;
}

//******************************************************************************
// mvpdRingFuncSet: update the record with the caller's ring.
//******************************************************************************
fapi::ReturnCode mvpdRingFuncSet ( uint8_t     *i_pRecordBuf,
                               uint32_t     i_recordLen,
                               uint8_t     *i_pRing,
                               uint32_t     i_ringLen,
                               uint8_t     *i_pCallerRingBuf,
                               uint32_t     i_callerRingBufLen)
{
    fapi::ReturnCode l_fapirc;
    uint8_t          *l_to = NULL;
    uint8_t          *l_fr = NULL;
    uint32_t         l_len = 0;
    uint8_t          *l_pRingEnd; // pointer into record to start of pad at end

    FAPI_DBG( "mvpdRingFuncSet: pRing=0x%p rLen=0x%x pCaller=0x%p cLen=0x%x",
                       i_pRing,
                       i_ringLen,
                       i_pCallerRingBuf,
                       i_callerRingBufLen);

    do {
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
        l_fapirc = mvpdRingFuncFind (0x00,
                                     0x00,
                                     i_pRecordBuf,
                                     i_recordLen,
                                     l_pRingEnd, // find start of padding
                                     l_len);
        if ( l_fapirc )
        {
            FAPI_ERR("mvpdRingFuncSet: mvpdRingFuncFind failed rc=0x%x",
                     static_cast<uint32_t>(l_fapirc));
            //  break out with fapirc
            break;
        }
        FAPI_DBG( "mvpdRingFuncSet: end= 0x%p",
                                 l_pRingEnd);

        // if not there, then append if it fits
        if (i_ringLen == 0 ) //is not currently in record (0 len from find)
        {
            if (l_pRingEnd+i_callerRingBufLen > i_pRecordBuf+i_recordLen)
            {
          FAPI_ERR( "mvpdRingFuncSet: not enough room to append ");
                FAPI_SET_HWP_ERROR(l_fapirc,
                                 RC_MVPD_RING_FUNC_INSUFFICIENT_RECORD_SPACE );
                //  break out of do block with fapi rc set
                break;
            }
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

            l_to = i_pRing+i_callerRingBufLen;
            l_fr = i_pRing+i_ringLen;
            l_len = (l_pRingEnd)-(i_pRing+i_ringLen);
            FAPI_DBG( "mvpdRingFuncSet: shrink-memmove 0x%p 0x%p 0x%x",
                       l_to,
                       l_fr,
                       l_len);
            memmove (l_to, l_fr, l_len); //use memmove, always overlaps.

            l_to = (l_pRingEnd)-(i_ringLen-i_callerRingBufLen);
            l_len = i_ringLen-i_callerRingBufLen;
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
            if ((l_pRingEnd + (i_callerRingBufLen - i_ringLen))  >
                (i_pRecordBuf + i_recordLen))
            {
                FAPI_ERR( "mvpdRingFuncSet: not enough room to insert ");
                FAPI_SET_HWP_ERROR(l_fapirc,
                                 RC_MVPD_RING_FUNC_INSUFFICIENT_RECORD_SPACE );
                //  break out of do block with fapi rc set
                break;
            }

            l_to = i_pRing+i_callerRingBufLen;
            l_fr = i_pRing+i_ringLen;
            l_len = l_pRingEnd-(i_pRing+i_ringLen);
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

    } while (0);

    FAPI_DBG( "mvpdRingFuncSet: exit  rc= 0x%x",
                          static_cast<uint32_t>(l_fapirc) );

   return l_fapirc;
}


}   // extern "C"
