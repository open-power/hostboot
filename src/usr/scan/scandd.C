/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scan/scandd.C $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2017                        */
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
/**
 * @file scandd.C
 *
 * @brief Implementation of the scan device driver
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
#include <errl/errludtarget.H>
#include <sbeio/sbe_psudd.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>
#include <devicefw/userif.H>



// ----------------------------------------------
// Globals
// ----------------------------------------------

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
trace_desc_t* g_trac_scandd = NULL;
TRAC_INIT( & g_trac_scandd, SCANDD_TRACE_BUF, KILOBYTE );

trace_desc_t* g_trac_scanddr = NULL;
TRAC_INIT( & g_trac_scanddr, SCANDD_RTRACE_BUF, KILOBYTE );


// ----------------------------------------------
// Defines
// ----------------------------------------------
#define VIRTUAL_CHIPLET_ID_BASE_MCS_TARGET_TYPE (0x80)
// ----------------------------------------------

namespace SCANDD
{

using namespace SBEIO;

// Register the perform Op with the routing code for Procs.
//for "Put Ring From Image" command too
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::SCAN,
                       TARGETING::TYPE_PROC,
                       scanPerformOp );

// Register the perform Op with the routing code for Memory Buffers.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::SCAN,
                       TARGETING::TYPE_MEMBUF,
                       scanPerformOp );

//for "Put Ring From Image" command
// Register the perform Op with the routing code
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::SCAN,
                       TARGETING::TYPE_EX,
                       scanPerformOp );

//for "Put Ring From Image" command
// Register the perform Op with the routing code
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::SCAN,
                       TARGETING::TYPE_PERV,
                       scanPerformOp );

//for "Put Ring From Image" command
// Register the perform Op with the routing code
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::SCAN,
                       TARGETING::TYPE_XBUS,
                       scanPerformOp );

//for "Put Ring From Image" command
// Register the perform Op with the routing code
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::SCAN,
                       TARGETING::TYPE_MCBIST,
                       scanPerformOp );

//for "Put Ring From Image" command
// Register the perform Op with the routing code
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::SCAN,
                       TARGETING::TYPE_OBUS,
                       scanPerformOp );

//for "Put Ring From Image" command
// Register the perform Op with the routing code
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::SCAN,
                       TARGETING::TYPE_PCI,
                       scanPerformOp );

//for "Put Ring From Image" command
// Register the perform Op with the routing code
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::SCAN,
                       TARGETING::TYPE_CORE,
                       scanPerformOp );

//for "Put Ring From Image" command
// Register the perform Op with the routing code
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::SCAN,
                       TARGETING::TYPE_L2,
                       scanPerformOp );

//for "Put Ring From Image" command
// Register the perform Op with the routing code
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::SCAN,
                       TARGETING::TYPE_L3,
                       scanPerformOp );

//for "Put Ring From Image" command
// Register the perform Op with the routing code
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::SCAN,
                       TARGETING::TYPE_L4,
                       scanPerformOp );

//for "Put Ring From Image" command
// Register the perform Op with the routing code
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::SCAN,
                       TARGETING::TYPE_MCS,
                       scanPerformOp );

/// @brief Sends Put Ring from Image message to SBE via PSU
errlHndl_t sbeScanPerformOp( TARGETING::Target * i_target,
                             RingId_t i_ringID,
                             fapi2::RingMode i_ringMode )
{
    TRACFCOMP( g_trac_scandd, ENTER_MRK "sbeScanPerformOp(targ=%.8X,id=%d,mode=%.8X)",
               TARGETING::get_huid(i_target),
               i_ringID,
               i_ringMode );
    errlHndl_t l_errl = NULL;


    SbePsu::psuCommand   l_psuCommand(
    //control flags are hardcoded here, no need to pass them into sbe function
            SbePsu::SBE_DMCONTROL_RESPONSE_REQUIRED,
            //command class
            SbePsu::SBE_PSU_PUT_RING_FROM_IMAGE_CMD,
            //command
            SbePsu::SBE_CMD_CONTROL_PUTRING);
    SbePsu::psuResponse  l_psuResponse;

    l_psuCommand.cd3_PutRing_TargetType =  translateToSBETargetType(i_target);
    l_psuCommand.cd3_PutRing_Reserved1  =  0x00;
    l_psuCommand.cd3_PutRing_ChipletID  =  getChipletIDForSBE(i_target);
    l_psuCommand.cd3_PutRing_RingID     =  i_ringID;
    l_psuCommand.cd3_PutRing_RingMode   =  i_ringMode;

    TRACDCOMP( g_trac_scandd, INFO_MRK" sbeScanPerformOp()"
            " l_target : %.16llX i_targetType %.16llX",
                  i_target,
                  i_target->getAttr<TARGETING::ATTR_TYPE>());
    TRACDCOMP( g_trac_scandd, INFO_MRK
              ":: sbeScanPerformOp() TargetType:%.8X ",
              l_psuCommand.cd3_PutRing_TargetType);
    TRACDCOMP( g_trac_scandd, INFO_MRK
                    ":: sbeScanPerformOp() Reserved1:%.8X ",
                    l_psuCommand.cd3_PutRing_Reserved1 );
    TRACDCOMP( g_trac_scandd, INFO_MRK
                       ":: sbeScanPerformOp() ChipletID:%.8X ",
                       l_psuCommand.cd3_PutRing_ChipletID );
    TRACDCOMP( g_trac_scandd, INFO_MRK
                     ":: sbeScanPerformOp() RingID:%.8X ",
                     l_psuCommand.cd3_PutRing_RingID );
    TRACDCOMP( g_trac_scandd, INFO_MRK
            ":: sbeScanPerformOp() Control Flags :%.8X ",
            l_psuCommand.cd3_PutRing_ControlFlags );
    TRACDCOMP( g_trac_scandd, INFO_MRK
                      ":: sbeScanPerformOp() RingMode:%.8X ",
                      l_psuCommand.cd3_PutRing_RingMode );

    // PSU ops are chip-wide so find the right target
    TARGETING::Target* l_parentProc = i_target;
    if( l_parentProc->getAttr<TARGETING::ATTR_TYPE>()
        != TARGETING::TYPE_PROC )
    {
        l_parentProc =
          const_cast<TARGETING::Target *>(TARGETING::getParentChip(i_target));
        assert(l_parentProc);
        assert(l_parentProc->getAttr<TARGETING::ATTR_TYPE>()
               == TARGETING::TYPE_PROC);
    }

    // Trigger the putring
    l_errl = SBEIO::SbePsu::getTheInstance().performPsuChipOp(
                    l_parentProc,
                    &l_psuCommand,
                    &l_psuResponse,
                    SbePsu::MAX_PSU_SHORT_TIMEOUT_NS,
                    SbePsu::SBE_DMCONTROL_START_REQ_USED_REGS,
                    SbePsu::SBE_DMCONTROL_START_RSP_USED_REGS);

    TRACFCOMP( g_trac_scandd, EXIT_MRK "exiting :: sbeScanPerformOp()");

    return l_errl;
}

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

    uint64_t i_arg0 = va_arg(i_args,uint64_t);
    uint64_t i_arg1 = va_arg(i_args,uint64_t);
    uint64_t i_arg2 = va_arg(i_args,uint64_t);
    uint64_t i_whichFunction = va_arg(i_args,uint64_t);

    do
    {
        if(i_whichFunction == PUT_RING_FROM_IMAGE_COMMAND)
        {
            // from devicefw/userif.H
            // #define DEVICE_SCAN_SBE_ADDRESS( i_ringID, i_ringMode, i_flag )
            RingId_t i_ringID = static_cast<RingId_t>(i_arg0);
            fapi2::RingMode i_ringMode = static_cast<fapi2::RingMode>(i_arg1);
            l_err = sbeScanPerformOp( i_target,
                                      i_ringID,
                                      i_ringMode );
        }
        else
        {
            // from devicefw/userif.H
            // #define DEVICE_SCAN_ADDRESS( i_ring, i_ringlen, i_flag )
            uint64_t i_ring = i_arg0;
            uint64_t i_ringlength = i_arg1;
            uint64_t i_flag = i_arg2;

            l_err = scanDoPibScan( i_opType,
                                i_target,
                                io_buffer,
                                io_buflen,
                                i_ring,
                                i_ringlength,
                                i_flag );
        }//else case
    }while(0);

    return l_err;
}


// ------------------------------------------------------------------
// scanDoPibScan - execute the scan read or write
// ------------------------------------------------------------------
errlHndl_t scanDoPibScan(  DeviceFW::OperationType i_opType,
                          TARGETING::Target * i_target,
                          void * o_buffer,
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
        TRACFCOMP( g_trac_scandd,"SCAN::scanDoPibScan> Start::: i_ring=%lX, i_ringLength=%d, i_flag=%lX, i_opType=%.8X",i_ring, i_ringlength, i_flag, i_opType);


        // If the ringlength equals 0
        if( i_ringlength == 0x0 )
        {
            TRACFCOMP( g_trac_scandd,
                       ERR_MRK "SCAN::scanDoPibScan> Invalid Ringlength for"
                       " ring =%d for target =%.8X",
                       i_ring, TARGETING::get_huid(i_target));
            /*@
             * @errortype
             * @moduleid     SCAN::MOD_SCANDD_DOPIBSCAN
             * @reasoncode   SCAN::RC_INVALID_LENGTH
             * @userdata1    SCAN Ring Address
             * @userdata2    SCAN ring length
             * @devdesc      ScanDD::scanPerformOp> Invalid ringlength
             * @custdesc    A problem occurred during the IPL
             *              of the system.
             */
            l_err = new ERRORLOG::ErrlEntry(
                                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            SCAN::MOD_SCANDD_DOPIBSCAN,
                                            SCAN::RC_INVALID_LENGTH,
                                            i_ring,
                                            i_ringlength,
                                            true/*SW Error*/);
            //Add this target to the FFDC
            ERRORLOG::ErrlUserDetailsTarget(i_target,"Scan Target")
              .addToLog(l_err);

            l_err->collectTrace(SCANDD_TRACE_BUF,1024);
            break;
        }

        // Check to see if invalid RING.. (0xFFFFFFFF - has been used as a
        // test ring in fips code so checking for that as well.
        if ((i_ring == 0x0) || (i_ring == 0xFFFFFFFF))
        {
            TRACFCOMP( g_trac_scandd, ERR_MRK "SCAN:scanPerformOp> Invalid ring i_ring=%.8X for target =%.8X", i_ring, TARGETING::get_huid(i_target) );
            /*@
             * @errortype
             * @moduleid     SCAN::MOD_SCANDD_DOPIBSCAN
             * @reasoncode   SCAN::RC_INVALID_RING_ADDRESS
             * @userdata1    SCAN Ring Address
             * @userdata2    TARGET
             * @devdesc      ScanDD::scanPerformOp> Invalid Ring Address
             * @custdesc    A problem occurred during the IPL
             *              of the system.
             */
            l_err = new ERRORLOG::ErrlEntry(
                                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            SCAN::MOD_SCANDD_DOPIBSCAN,
                                            SCAN::RC_INVALID_RING_ADDRESS,
                                            i_ring,
                                            TARGETING::get_huid(i_target),
                                            true/*SW Error*/);
            //Add this target to the FFDC
            ERRORLOG::ErrlUserDetailsTarget(i_target,"Scan Target")
              .addToLog(l_err);

            l_err->collectTrace(SCANDD_TRACE_BUF,1024);
            break;
        }

        // Check to make sure the buflength is big enough.
        // ringlength is in bits, io_buflen is in bytes
        if ((i_ringlength) > io_buflen*8)
        {
            TRACFCOMP( g_trac_scandd, ERR_MRK "SCAN::scanDoPibScan> IObuffer not big enough=ringlength = %d, iobuflen = %d for target =%.8X", i_ringlength, io_buflen,TARGETING::get_huid(i_target) );
            /*@
             * @errortype
             * @moduleid     SCAN::MOD_SCANDD_DOPIBSCAN
             * @reasoncode   SCAN::RC_INVALID_BUF_SIZE
             * @userdata1    SCAN IO buffer length
             * @userdata2    SCAN ring length
             * @devdesc      ScanDD::scanPerformOp> Invalid IObuf length
             * @custdesc    A problem occurred during the IPL
             *              of the system.
             */
            l_err = new ERRORLOG::ErrlEntry(
                                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            SCAN::MOD_SCANDD_DOPIBSCAN,
                                            SCAN::RC_INVALID_BUF_SIZE,
                                            io_buflen,
                                            i_ringlength,
                                            true/*SW Error*/);
            //Add this target to the FFDC
            ERRORLOG::ErrlUserDetailsTarget(i_target,"Scan Target")
              .addToLog(l_err);

            l_err->collectTrace(SCANDD_TRACE_BUF,1024);
            break;
        }

        // If a Scan read or Write.. do the scan op.
        if( !((DeviceFW::READ == i_opType) || (DeviceFW::WRITE == i_opType)) )
        {
            TRACFCOMP( g_trac_scandd, ERR_MRK "SCAN::scanDoPibScan> Invalid Op Type = %d for target =%.8X", i_opType, TARGETING::get_huid(i_target) );
            /*@
             * @errortype
             * @moduleid     SCAN::MOD_SCANDD_DOPIBSCAN
             * @reasoncode   SCAN::RC_INVALID_OPERATION
             * @userdata1    SCAN Address
             * @userdata2    Operation Type (i_opType)
             * @devdesc      ScanDD::scanPerformOp> Invalid operation type
             * @custdesc    A problem occurred during the IPL
             *              of the system.
             */
            l_err = new ERRORLOG::ErrlEntry(
                                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            SCAN::MOD_SCANDD_DOPIBSCAN,
                                            SCAN::RC_INVALID_OPERATION,
                                            i_ring,
                                            TO_UINT64(i_opType),
                                            true/*SW Error*/);
            //Add this target to the FFDC
            ERRORLOG::ErrlUserDetailsTarget(i_target,"Scan Target")
              .addToLog(l_err);
            l_err->collectTrace(SCANDD_TRACE_BUF,1024);
            break;
        }

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
                       "SCAN::scanDoPibScan> SCOM Write to scan select register failed. i_ring=%lX, scanTypeData=%lX,scanTypeAddr=%lX, target =%.8X", i_ring, l_scanTypeData,l_scanTypeAddr, TARGETING::get_huid(i_target) );
            //Add this target to the FFDC
            ERRORLOG::ErrlUserDetailsTarget(i_target,"Scan Target")
              .addToLog(l_err);
            l_err->collectTrace(SCANDD_TRACE_BUF,1024);
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
                 TRACFCOMP( g_trac_scandd, ERR_MRK"SCAN::scanDoPibScan> ERROR i_ring=%.8X, target=%.8X , scanTypeData=%.8X, l_HeaderDataAddr=%.8X", i_ring, TARGETING::get_huid(i_target), l_buffer[0], l_headerDataAddr);
                 //Add this target to the FFDC
                 ERRORLOG::ErrlUserDetailsTarget(i_target,"Scan Target")
                   .addToLog(l_err);
                 l_err->collectTrace(SCANDD_TRACE_BUF,1024);
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
            TRACFCOMP( g_trac_scandd, ERR_MRK"SCAN::scanDoPibScan> ERROR i_ring=%.8X, target=%.8X , scanTypeData=%.8X, l_HeaderDataAddr=%.8X", i_ring, TARGETING::get_huid(i_target), l_buffer[0], l_headerDataAddr);
            //Add this target to the FFDC
            ERRORLOG::ErrlUserDetailsTarget(i_target,"Scan Target")
              .addToLog(l_err);
            l_err->collectTrace(SCANDD_TRACE_BUF,1024);
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

        // Set the temp buffer to point to the o_buffer passed in
        uint32_t *temp_buffer = (uint32_t *)o_buffer;

        // Need to increment the buffer by 1 to get past word0 which is the
        // header that we wrote to already above.
        temp_buffer++;
        // decrement the number of words to read by 1 because read header above
        l_wordsInChain--;

        //TRACFCOMP( g_trac_scandd,
        //           "SCAN::scanDoPibScan> Before Data Loop, i_ringlength = %.8x, i_opType =%.8X, Full words to read=%d
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
                TRACFCOMP( g_trac_scandd,ERR_MRK "SCAN::scanDoPibScan: Device OP error> i_ring=%.8X, target=%.8X , scanTypeData=%.8X, i_flag=%.8X,", i_ring, TARGETING::get_huid(i_target), l_scanDataAddr, i_flag );
                //Add this target to the FFDC
                ERRORLOG::ErrlUserDetailsTarget(i_target,"Scan Target")
                  .addToLog(l_err);
                l_err->collectTrace(SCANDD_TRACE_BUF,1024);
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

                // TRACDCOMP( g_trac_scandd,"SCAN::scanDoPibScan: Last Bits WRITE> scanTypeDataAddr=%.8X, l_lastDataBits=%d, bytes copied %d,",l_scanDataAddr, l_lastDataBits, ((l_lastDataBits-1)/8 + 1));

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
                TRACFCOMP( g_trac_scandd, ERR_MRK "SCAN::scanDoPibScan: OP and shift of < 32bits i_ring=%.8X, scanTypeDataAddr=%.8X, l_lastDataBits=%.8X, target=%.8X", i_ring, l_scanDataAddr, l_lastDataBits, TARGETING::get_huid(i_target) );
                //Add this target to the FFDC
                ERRORLOG::ErrlUserDetailsTarget(i_target,"Scan Target")
                  .addToLog(l_err);
                l_err->collectTrace(SCANDD_TRACE_BUF,1024);
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

                //TRACDCOMP( g_trac_scandd, "SCAN::scanDoPibScan: Last Bits READ> scanTypeDataAddr=%.8X, l_lastDataBits=%d, bytes copied = %d",l_scanDataAddr, l_lastDataBits, ((l_lastDataBits-1)/8 + 1));

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
            TRACFCOMP( g_trac_scandd,ERR_MRK "SCAN::scanDoPibScan> ERROR i_ring=%.8X, HeaderDataAddr=%.8X, i_flag=%.8X, target=%.8X", i_ring, l_headerDataAddr, i_flag, TARGETING::get_huid(i_target)  );
            l_err->collectTrace(SCANDD_TRACE_BUF,1024);
            break;

        }
        // If header check on.. then need to verify the data.
        if (!(i_flag & SCAN::NO_HEADER_CHECK))
        {
            // If the header data did not match..
            if ((l_buffer[0] != HEADER_CHECK_DATA))
            {
                TRACFCOMP( g_trac_scandd, "SCAN::scanDoPibScan> Header Check Failed on %.8X: i_ring=%.8X, i_opType=%.8X, i_flag=%.8X,", TARGETING::get_huid(i_target), i_ring, i_opType, i_flag );
                TRACFCOMP( g_trac_scandd, "%.8X = %.8X_%.8X (expected 0xDEADBEEF)", l_headerDataAddr , l_buffer[0], l_buffer[1] );

                /*@
                 * @errortype
                 * @moduleid     SCAN::MOD_SCANDD_DOPIBSCAN
                 * @reasoncode   SCAN::RC_HEADER_DATA_MISMATCH
                 * @userdata1    SCAN Ring Address
                 * @userdata2    Operation Type (i_opType)
                 * @devdesc      ScanDD::scanDoPibScan> Got a data mismatch
                 *               when reading back the header
                 * @custdesc    A problem occurred during the IPL
                 *              of the system.
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                      ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      SCAN::MOD_SCANDD_DOPIBSCAN,
                                      SCAN::RC_HEADER_DATA_MISMATCH,
                                      i_ring,
                                      TO_UINT64(i_opType) );
                //Most like cause (based on experience) is some kind
                // of a clock issue
                TARGETING::TYPE type =
                  i_target->getAttr<TARGETING::ATTR_TYPE>();
                if( type == TARGETING::TYPE_PROC)
                {
                    l_err->addClockCallout(i_target,
                                           HWAS::OSCREFCLK_TYPE,
                                           HWAS::SRCI_PRIORITY_HIGH);
                }
                else if( type == TARGETING::TYPE_MEMBUF )
                {
                    l_err->addClockCallout(i_target,
                                           HWAS::MEMCLK_TYPE,
                                           HWAS::SRCI_PRIORITY_HIGH);
                }
                else // for anything else, just blame the refclock
                {
                    l_err->addClockCallout(i_target,
                                           HWAS::OSCREFCLK_TYPE,
                                           HWAS::SRCI_PRIORITY_HIGH);
                }
                //Could also be a busted chip
                l_err->addHwCallout( i_target,
                                     HWAS::SRCI_PRIORITY_LOW,
                                     HWAS::DECONFIG, //allows us to continue
                                     HWAS::GARD_NULL );
                //Add this target to the FFDC
                ERRORLOG::ErrlUserDetailsTarget(i_target,"Scan Target")
                  .addToLog(l_err);
                l_err->collectTrace(SCANDD_TRACE_BUF,1024);
                break;
            }

        }
    }while(0);

    mutex_unlock(l_mutex);

    return l_err;
}


}
