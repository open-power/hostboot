/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scan/scandd.C $                                       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
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
/**
 * @file scandd.C
 *
 * @brief Implementation of the scan device driver
 *
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <string.h>
#include <sys/time.h>

#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <devicefw/driverif.H>
#include <devicefw/userif.H>
#include <scan/scan_reasoncodes.H>
#include <scan/scanif.H>
#include "scandd.H"

// ----------------------------------------------
// Globals
// ----------------------------------------------

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
trace_desc_t* g_trac_scandd = NULL;
TRAC_INIT( & g_trac_scandd, "SCANDD", KILOBYTE );

trace_desc_t* g_trac_scanddr = NULL;
TRAC_INIT( & g_trac_scanddr, "SCANDDR", KILOBYTE );


// ----------------------------------------------
// Defines
// ----------------------------------------------

// ----------------------------------------------

namespace SCANDD
{

// Register the perform Op with the routing code for Procs.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::SCAN,
                       TARGETING::TYPE_PROC,
                       scanPerformOp );

// Register the perform Op with the routing code for Memory Buffers.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::SCAN,
                       TARGETING::TYPE_MEMBUF,
                       scanPerformOp );


// ------------------------------------------------------------------
// scanPerformOp
// ------------------------------------------------------------------
errlHndl_t scanPerformOp( DeviceFW::OperationType i_opType,
                          TARGETING::Target * i_target,
                          void * io_buffer,
                          size_t & io_buflen,
                          int64_t i_accessType,
                          va_list i_args )
{

    errlHndl_t l_err = NULL;
    uint64_t i_ring = va_arg(i_args,uint64_t);
    uint64_t i_ringlength = va_arg(i_args,uint64_t);
    uint64_t i_flag = va_arg(i_args,uint64_t);

   do
   {
       // If the ringlength equals 0
       if( i_ringlength == 0x0 )
       {
           TRACFCOMP( g_trac_scandd, ERR_MRK "SCAN::scanPerformOp> Invalid Ringlength for ring =%d for target =%.8X", i_ring, TARGETING::get_huid(i_target));
           /*@
            * @errortype
            * @moduleid     SCAN::MOD_SCANDD_DDOP
            * @reasoncode   SCAN::RC_INVALID_LENGTH
            * @userdata1    SCAN Ring Address
            * @userdata2    SCAN ring length
            * @devdesc      ScanDD::scanPerformOp> Invalid ringlength
            */
           l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           SCAN::MOD_SCANDD_DDOP,
                                           SCAN::RC_INVALID_LENGTH,
                                           i_ring,
                                           i_ringlength);

           l_err->collectTrace("SCANDD",1024);
           break;
       }

       // Check to see if invalid RING.. (0xFFFFFFFF - has been used as a
       // test ring in fips code so checking for that as well.
       if ((i_ring == 0x0) || (i_ring == 0xFFFFFFFF))
       {
           TRACFCOMP( g_trac_scandd, ERR_MRK "SCAN:scanPerformOp> Invalid ring i_ring=%.8X for target =%.8X", i_ring, TARGETING::get_huid(i_target) );
           /*@
            * @errortype
            * @moduleid     SCAN::MOD_SCANDD_DDOP
            * @reasoncode   SCAN::RC_INVALID_RING_ADDRESS
            * @userdata1    SCAN Ring Address
            * @userdata2    TARGET
            * @devdesc      ScanDD::scanPerformOp> Invalid Ring Address
            */
           l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           SCAN::MOD_SCANDD_DDOP,
                                           SCAN::RC_INVALID_RING_ADDRESS,
                                           i_ring,
                                           TARGETING::get_huid(i_target));

           l_err->collectTrace("SCANDD",1024);
           break;
       }

       // Check to make sure the buflength is big enough.
       // ringlength is in bits, io_buflen is in bytes
       if ((i_ringlength) > io_buflen*8)
       {
           TRACFCOMP( g_trac_scandd, ERR_MRK "SCAN::scanPerformOp> IObuffer not big enough=ringlength = %d, iobuflen = %d for target =%.8X", i_ringlength, io_buflen,TARGETING::get_huid(i_target) );
           /*@
            * @errortype
            * @moduleid     SCAN::MOD_SCANDD_DDOP
            * @reasoncode   SCAN::RC_INVALID_BUF_SIZE
            * @userdata1    SCAN IO buffer length
            * @userdata2    SCAN ring length
            * @devdesc      ScanDD::scanPerformOp> Invalid IObuf length
            */
           l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           SCAN::MOD_SCANDD_DDOP,
                                           SCAN::RC_INVALID_BUF_SIZE,
                                           io_buflen,
                                           i_ringlength);

           l_err->collectTrace("SCANDD",1024);
           break;
       }

       // If a Scan read or Write.. do the scan op.
       if(( DeviceFW::READ == i_opType ) || ( DeviceFW::WRITE == i_opType ))
       {
          l_err = scanDoScan( i_opType,
                              i_target,
                              io_buffer,
                              io_buflen,
                              i_ring,
                              i_ringlength,
                              i_flag );

          if(l_err)
          {
              break;
          }

       }
       else
       {
           TRACFCOMP( g_trac_scandd, ERR_MRK "SCAN::scanPerformOp> Invalid Op Type = %d for target =%.8X", i_opType, TARGETING::get_huid(i_target) );
           /*@
            * @errortype
            * @moduleid     SCAN::MOD_SCANDD_DDOP
            * @reasoncode   SCAN::RC_INVALID_OPERATION
            * @userdata1    SCAN Address
            * @userdata2    Operation Type (i_opType)
            * @devdesc      ScanDD::scanPerformOp> Invalid operation type
            */
           l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           SCAN::MOD_SCANDD_DDOP,
                                           SCAN::RC_INVALID_OPERATION,
                                           i_ring,
                                           TO_UINT64(i_opType));
           l_err->collectTrace("SCANDD",1024);
           break;
       }

   }while(0);

   return l_err;
}


// ------------------------------------------------------------------
// scanDoScan - execute the scan read or write
// ------------------------------------------------------------------
errlHndl_t scanDoScan(  DeviceFW::OperationType i_opType,
                          TARGETING::Target * i_target,
                          void * io_buffer,
                          size_t & io_buflen,
                          uint64_t i_ring,
                          uint64_t i_ringlength,
                          uint64_t i_flag )
{

    errlHndl_t l_err = NULL;
    uint64_t l_wordsInChain = i_ringlength/32;
    size_t op_size = sizeof(uint64_t);
    uint32_t l_buffer[2];  // local scom buffer

    mutex_t* l_mutex = i_target->getHbMutexAttr<TARGETING::ATTR_SCAN_MUTEX>();
    mutex_lock(l_mutex);

    do
    {

        TRACFCOMP( g_trac_scandd,"SCAN::scanDoScan> Start::: i_ring=%lX, i_ringLength=%d, i_flag=%lX, i_opType=%.8X",i_ring, i_ringlength, i_flag, i_opType);

        // To get the remaining bits of data
        // If not on a 32bit boundary need to know how many bits to shift.
        uint64_t l_lastDataBits = i_ringlength % 32;

        // select the chiplet and port
        uint64_t l_scanTypeAddr = i_ring & 0x7FFF0000;

        // local flag indicating the target is a centaur
        uint64_t l_isCentaur = 0;

        if ((i_target->getAttr<TARGETING::ATTR_MODEL>()) == TARGETING::MODEL_CENTAUR)
        {
            l_isCentaur = 1;
        }

        // If working with a Centaur chip and the chipselect is
        // 0 need to set the chipselect to 1.
        // Here is the info from Cedric Lichtanau with regard to
        // this check:   "you need to use a different ring modifier/SCOM
        //   addresses with chiplet 1 instead of 0 for pervasive chiplet
        //   where the ring you want to scan is located. All other chiplet rings
        //   eg. 0203xxxx 0303xxxx stays the same. This is only special with
        //   0003xxxx"
        if ((l_isCentaur) && ((l_scanTypeAddr & 0x01000000) == 0x0))
        {
            l_scanTypeAddr |= 0x01000000;
        }

        // bits 16-31 select the scan type select register
        l_scanTypeAddr |= 0x00000007;

        // Get the "scan type select" registers "region select" field
        uint32_t l_scanTypeData = (i_ring & 0x0000FFF0) << 13;

        // convert encoded type select value to bit mapped value
        uint32_t l_typeSelectBin = 0x00000800 >> (i_ring & 0x0000000F);

        l_scanTypeData |= l_typeSelectBin;

        l_buffer[0] = l_scanTypeData;
        l_buffer[1] = 0;

        // Do a scom write to the scan type select register
        l_err = deviceOp( DeviceFW::WRITE,
                          i_target,
                          l_buffer,
                          op_size,
                          DEVICE_SCOM_ADDRESS(l_scanTypeAddr));

        TRACDCOMP( g_trac_scandd,"SCAN: ScanSelect  PUTSCOM %lX = %.8x, %.8x", l_scanTypeAddr , l_buffer[0], l_buffer[1]);


        if(l_err)
        {
            TRACFCOMP( g_trac_scandd, ERR_MRK
                       "SCAN::scanDoScan> SCOM Write to scan select register failed. i_ring=%lX, scanTypeData=%lX,scanTypeAddr=%lX, target =%.8X", i_ring, l_scanTypeData,l_scanTypeAddr, TARGETING::get_huid(i_target) );

            // TODO:  Add usrDetails
            break;

        }

        // address of the scan data register uses same bits 0-15 as the scan
        // type select register
        uint64_t l_scanDataAddr = l_scanTypeAddr & 0xFFFF0000;

        // set bit 16 to a 1 when accessing the scan data register
        l_scanDataAddr |= 0x00008000;

        // The header data is part of the data ring.. So need to always
        // do the upfront header write whether the header check is on or not

        // Need to write the header check value to the scan data register
        uint64_t l_headerDataAddr = l_scanDataAddr;

        // If this is a scan Write then need to shift the header data 32bits
        // bits 19-32 are the shift bits
        if ( DeviceFW::WRITE == i_opType )
        {
            l_headerDataAddr |= 32;

        }
        // doing a scan read op and a header check write
        //  .. need get rid of bits 19-31
        else
        {
            l_headerDataAddr = l_headerDataAddr & 0xFFFFE000;
        }

        // If this is a centaur chip need to read the header
        // data area first before the header Write.
        if (l_isCentaur)
        {
            // Do a scom write to the scan type select register
            l_err = deviceOp( DeviceFW::READ,
                              i_target,
                              l_buffer,
                              op_size,
                              DEVICE_SCOM_ADDRESS(l_headerDataAddr));

             TRACDCOMP( g_trac_scandd,"SCAN:(Cent Headr) GETSCOM %lX = %.8x %.8x",l_headerDataAddr , l_buffer[0], l_buffer[1]);

             if(l_err)
             {
                 TRACFCOMP( g_trac_scandd, ERR_MRK"SCAN::scanDoScan> ERROR i_ring=%.8X, target=%.8X , scanTypeData=%.8X, l_HeaderDataAddr=%.8X", i_ring, TARGETING::get_huid(i_target), l_buffer[0], l_headerDataAddr);

                 // TODO:  Add usrDetails
                 break;
             }
        }


        // Set the header data value
        l_buffer[0] = HEADER_CHECK_DATA;
        l_buffer[1] = 0;

        // Do a scom write to the scan type select register
        l_err = deviceOp( DeviceFW::WRITE,
                          i_target,
                          l_buffer,
                          op_size,
                          DEVICE_SCOM_ADDRESS(l_headerDataAddr));

        TRACDCOMP( g_trac_scandd,"SCAN:Headr PUTSCOM %.8x = %.8x %.8x",l_headerDataAddr , l_buffer[0], l_buffer[1]);

        if(l_err)
        {
            TRACFCOMP( g_trac_scandd, ERR_MRK"SCAN::scanDoScan> ERROR i_ring=%.8X, target=%.8X , scanTypeData=%.8X, l_HeaderDataAddr=%.8X", i_ring, TARGETING::get_huid(i_target), l_buffer[0], l_headerDataAddr);

            // TODO:  Add usrDetails
            break;
        }

        // bits 19-31 are the number of bits to shift .. <= 32 for each scom
        // operation
        // NOTE.. the ring may not be on a 32 bit boundary..
        //        So last read needs to shift
        //        only the remaining bits.. could be < 32

        //  set the shift value to 32
        l_scanDataAddr |= 32;

        uint64_t l_setPulse = 0;
        uint64_t l_wordCnt = 0;

        // If i_flag & SET_PULSE - then set the local pulse value..
        if (i_flag & SCAN::SET_PULSE)
        {
            l_setPulse = 1;
        }

        // NOTE: The additional read to get the header info and compare is
        //     outside of the loop as it needs to be done after the
        //     last bit are read which could be < 32

        // Set the temp buffer to point to the io_buffer passed in
        uint32_t *temp_buffer = (uint32_t *)io_buffer;

        // Need to increment the buffer by 1 to get past word0 which is the
        // header that we wrote to already above.
        temp_buffer++;
        // decrement the number of words to read by 1 because read header above
        l_wordsInChain--;

        //TRACFCOMP( g_trac_scandd,
        //           "SCAN::scanDoScan> Before Data Loop, i_ringlength = %.8x, i_opType =%.8X, Full words to read=%d
        //            lastbits =%d,", i_ringlength, i_opType, l_wordsInChain, l_lastDataBits);

        // Read all the words in the ring minus 1 because the header is done
        // above and is part of the ring.
        while(l_wordCnt < l_wordsInChain)
        {

            l_buffer[0] = 0;
            l_buffer[1] = 0;
            // If this is a read operation.
            if( DeviceFW::READ == i_opType )
            {
                // First iteration only.
                // If set pulse requested then set bit 17 else clear
                if (l_setPulse)
                {
                    l_scanDataAddr |= 0x00004000;
                    l_setPulse = 0;
                }
                else // clear it.
                {
                    l_scanDataAddr =  l_scanDataAddr & 0xFFFFBFFF;
                }

            }
            // If this is a scan Write
            else if ( DeviceFW::WRITE == i_opType )
            {
                // If this is the last iteration and set pulse is requested
                // and there are no additional bits left..
                // then set bit 18
                if ((l_wordCnt == l_wordsInChain-1) && (l_setPulse) &&
                    (l_lastDataBits == 0) && (!l_isCentaur))
                {
                    l_scanDataAddr |= 0x00002000;
                    l_setPulse = 0;
                }

                l_buffer[0] = *temp_buffer;

                TRACDCOMP( g_trac_scandd,"SCAN: Word PUTSCOM %lX = %.8x %.8x",l_scanDataAddr , l_buffer[0], l_buffer[1]);

            }

            // read/write 1 word and then shift the ring 32 bits
            l_err = deviceOp( i_opType,
                              i_target,
                              l_buffer,
                              op_size,
                              DEVICE_SCOM_ADDRESS(l_scanDataAddr));


            if(l_err)
            {
                TRACFCOMP( g_trac_scandd,ERR_MRK "SCAN::scanDoScan: Device OP error> i_ring=%.8X, target=%.8X , scanTypeData=%.8X, i_flag=%.8X,", i_ring, TARGETING::get_huid(i_target), l_scanDataAddr, i_flag );

                // TODO:  Add user details
                break;

            }

            // If this is a read operation.
            if( DeviceFW::READ == i_opType )
            {
                // Need to copy the buffer data read in by scom back into
                // the buffer we will return
                *temp_buffer = l_buffer[0];

                TRACDCOMP( g_trac_scandd,"SCAN: Word GETSCOM %lX = %.8x %.8x",l_scanDataAddr , l_buffer[0], l_buffer[1]);

            }

            // Increment the pointer to point to the next 32bit word.
            temp_buffer++;
            // increment the number of words read.
            l_wordCnt++;

        } // end of while..


        // make sure we break out, if error returned from while loop
        if(l_err)
        {
            break;
        }

        // if we are not on a 32bit boundary.. read the remaining bits.
        if (l_lastDataBits != 0)
        {

            l_buffer[0] = 0;
            l_buffer[1] = 0;

            // bits 19-31 are the number of bits to shift .. <= 32 for each scom
            // operation

            // need to remove the 32bit shift that we used previously
            l_scanDataAddr = l_scanDataAddr & 0xFFFFFFDF;

            // add to shift the number of bits remaining.
            l_scanDataAddr |= l_lastDataBits;

            // If this is a scan Write
            if ( DeviceFW::WRITE == i_opType )
            {
                // If this is not a Centaur chip then do the setpulse here.
                if (!l_isCentaur)
                {
                    // If this is the last iteration and set pulse is requested
                    // then set bit 18
                    if (l_setPulse)
                    {
                        l_scanDataAddr |= 0x00002000;
                        l_setPulse = 0;
                    }
                }
                // Need to copy the remaining bytes into the local 64bit buffer
                // subtracting 1 from the bits before dividing by 8 to insure
                // that we don't drop any bits if we are not on a byte boundary.
                memcpy(&l_buffer[0], temp_buffer, ((l_lastDataBits-1)/8 + 1));

                // TRACDCOMP( g_trac_scandd,"SCAN::scanDoScan: Last Bits WRITE> scanTypeDataAddr=%.8X, l_lastDataBits=%d, bytes copied %d,",l_scanDataAddr, l_lastDataBits, ((l_lastDataBits-1)/8 + 1));

                TRACDCOMP( g_trac_scandd,"SCAN: <32Bits PUTSCOM %lX = %.8x %.8x",l_scanDataAddr , l_buffer[0], l_buffer[1]);
            }

            // read/write remaining bits and shift
            l_err = deviceOp( i_opType,
                              i_target,
                              l_buffer,
                              op_size,
                              DEVICE_SCOM_ADDRESS(l_scanDataAddr));

            if(l_err)
            {
                TRACFCOMP( g_trac_scandd, ERR_MRK "SCAN::scanDoScan: OP and shift of < 32bits i_ring=%.8X, scanTypeDataAddr=%.8X, l_lastDataBits=%.8X, target=%.8X", i_ring, l_scanDataAddr, l_lastDataBits, TARGETING::get_huid(i_target) );

                // TODO:  Add user details
                break;
            }

            // If this was a read operation.
            if( DeviceFW::READ == i_opType )
            {

                // Need to shift the data bits to have the data bits be left
                // justified
                l_buffer[0] = l_buffer[0]<<(32-l_lastDataBits);

                // Need to copy the last data bits read in by scom back into
                // the buffer we will return
                // subtracting 1 from the bits before dividing by 8 to insure
                // that we don't drop any bits if we are not on a byte boundary.
                memcpy(temp_buffer, &l_buffer[0],((l_lastDataBits-1)/8 + 1));

                //TRACDCOMP( g_trac_scandd, "SCAN::scanDoScan: Last Bits READ> scanTypeDataAddr=%.8X, l_lastDataBits=%d, bytes copied = %d",l_scanDataAddr, l_lastDataBits, ((l_lastDataBits-1)/8 + 1));

                TRACDCOMP( g_trac_scandd,"SCAN: <32bits GETSCOM %lX = %.8x %.8x",l_scanDataAddr , l_buffer[0], l_buffer[1]);
            }
        }

        // make sure we break out, if error returned from while loop
        if(l_err)
        {
            break;
        }

        // Always need to do the header check read.. To get the data back where
        // it needs to be.

        l_headerDataAddr = l_scanDataAddr;

        l_buffer[0] = 0;
        l_buffer[1] = 0;

        // If we are doing a read command.. Need to shift 32 bits.
        // to get the header data back but doing a regular read
        if ( DeviceFW::READ == i_opType )
        {
            // remove any residual shift bits.
            l_headerDataAddr = l_headerDataAddr & 0xFFFFFF00;
            l_headerDataAddr |= 32;
        }
        // If doing a write. need to do a special write.
        // for the header and mask of bits 19-31
        // On a write need to do the setpulse at the time of
        // reading the header and not on the last data write
        else
        {
            l_headerDataAddr = l_headerDataAddr & 0xFFFFE000;

            // If this is a Centaur chip during a write operation need to do the
            // set pulse on the header read
            if (l_isCentaur)
            {
                // If this is the last iteration and set pulse is requested
                // then set bit 18
                if (l_setPulse)
                {
                    l_headerDataAddr |= 0x00002000;
                    l_setPulse = 0;
                }
            }
        }

        // read the Header Data
        l_err = deviceOp( DeviceFW::READ,
                          i_target,
                          l_buffer,
                          op_size,
                          DEVICE_SCOM_ADDRESS(l_headerDataAddr));

        TRACDCOMP( g_trac_scandd,"SCAN: Headr GETSCOM %lX = %.8x  %.8x",l_headerDataAddr , l_buffer[0], l_buffer[1]);

        if(l_err)
        {
            TRACFCOMP( g_trac_scandd,ERR_MRK "SCAN::scanDoScan> ERROR i_ring=%.8X, HeaderDataAddr=%.8X, i_flag=%.8X, target=%.8X", i_ring, l_headerDataAddr, i_flag, TARGETING::get_huid(i_target)  );

            // TODO:  Add user details
            break;

        }
        // If header check on.. then need to verify the data.
        if (!(i_flag & SCAN::NO_HEADER_CHECK))
        {
            // If the header data did not match..
            if ((l_buffer[0] != HEADER_CHECK_DATA))
            {
                TRACDCOMP( g_trac_scandd,"SCAN::scanDoScan> Header Check Failed expect deadbeef.. i_ring=%.8X, i_opType=%.8X , ring data=%.8X, i_flag=%.8X,", i_ring, i_opType, l_buffer[0], i_flag );

                TRACFCOMP( g_trac_scandd,"SCAN: HEADER DATA FAILED!! %.8x = %.8x  %.8x",l_headerDataAddr , l_buffer[0], l_buffer[1]);

                /*@
                 * @errortype
                 * @moduleid     SCAN::MOD_SCANDD_DOSCAN
                 * @reasoncode   SCAN::RC_HEADER_DATA_MISMATCH
                 * @userdata1    SCAN Ring Address
                 * @userdata2    Operation Type (i_opType)
                 * @devdesc      ScanDD::scanDoScan> Got a data mismatch when reading back the header
                 */
                l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                SCAN::MOD_SCANDD_DOSCAN,
                                                SCAN::RC_HEADER_DATA_MISMATCH,
                                                i_ring,
                                                TO_UINT64(i_opType));
                l_err->collectTrace("SCANDD",1024);
                break;
            }

        }
    }while(0);

    mutex_unlock(l_mutex);

    return l_err;
}




}
