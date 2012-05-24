/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/plat/fapiMvpdAccess.C $
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
 *  @file fapiMvpdAccess.C
 *
 *  @brief fetch #R records from MVPD
 *
 *  More prototypes may be added later to fetch other records from MVPD
 *
 */

#include    <stdint.h>

#include    <errl/errlentry.H>

//  targeting support
#include    <targeting/common/commontargeting.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>
#include    <hwpf/plat/fapiPlatReasonCodes.H>

//  MVPD
#include    <devicefw/userif.H>
#include    <mvpd/mvpdenums.H>

#include    <fapiMvpdAccess.H>


extern "C"
{
using   namespace   TARGETING;
using   namespace   fapi;
using   namespace   DeviceFW;


/**
 *  @def Max length for #R record
 */
const   size_t      MAX_pdR_RECORD  =   0xffff;

//  *********************************************************************
//  fapiGetMvpdPdr - get #R record from MVPD
//
//  @NOTE:  The P8 module VPD specification, March 27, 2012,
//      section 5.30.1 is wrong - #R records are in CP00.
//  *********************************************************************
fapi::ReturnCode    fapiGetMvpdPdr( const fapi::Target  &i_fapiTarget,
                                    uint8_t             *i_pPdrRecord,
                                    uint32_t            &io_rPdrSize )
{
    fapi::ReturnCode    l_fapirc( fapi::FAPI_RC_SUCCESS );
    errlHndl_t          l_errl          =   NULL;
    size_t              l_pdRLen        =   0;

    FAPI_DBG( "fapiGetMvpdPdr entry" );

    //  #R record looks like this:
    //  Field       Type    length  Value
    //  Name        ASCII   2       "#R"
    //  Length      HEX     2       -
    //  Version     HEX     1       0x10
    //  Chiplet-max HEX     12288   -

    do
    {
        // pass the parameters through to deviceRead.  If the pointer is NULL,
        //  deviceRead will pass the correct size back to the caller with no
        //  error. ( RTC 42489 )

        l_pdRLen    =   io_rPdrSize;
        //  Try to read the data
        l_errl  =   deviceRead( reinterpret_cast< TARGETING::Target*>(i_fapiTarget.get()),
                                i_pPdrRecord,
                                l_pdRLen,
                                DEVICE_MVPD_ADDRESS( MVPD::CP00,
                                                     MVPD::pdR ) );
        if ( l_errl )
        {
            FAPI_ERR( "fapiGetMvpdPdr: ERROR: deviceRead : errorlog PLID=0x%x",
                       l_errl->plid()  );

            //  set fapi error and commit errlog
            l_fapirc.setPlatError(reinterpret_cast<void *> (l_errl));

            //  set returned size to 0
            io_rPdrSize  =   0;

            // Return fapirc to caller
            break;
        }

        //  made it all the way to the bottom with no errors,
        //      return to caller with buffer and size filled in
        FAPI_DBG( "fapiGetMvpdPdr: returning #R record len=0x%x",
                  l_pdRLen );
        io_rPdrSize  =   l_pdRLen;

    }   while ( 0 );


    FAPI_DBG( "fapiGetMvpdPdr:  exit" );

    return  l_fapirc;
}

}   // extern "C"
