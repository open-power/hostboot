/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/vpd.C $                                           */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include "vpd.H"

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
trace_desc_t* g_trac_vpd = NULL;
TRAC_INIT( & g_trac_vpd, "VPD", KILOBYTE );

namespace VPD
{

// ------------------------------------------------------------------
// getVpdLocation
// ------------------------------------------------------------------
errlHndl_t getVpdLocation ( int64_t & o_vpdLocation,
                            TARGETING::Target * i_target )
{
    errlHndl_t err = NULL;

    TRACSSCOMP( g_trac_spd,
                ENTER_MRK"getVpdLocation()" );

    o_vpdLocation = i_target->getAttr<TARGETING::ATTR_VPD_REC_NUM>();
    TRACUCOMP( g_trac_spd,
               INFO_MRK"Using VPD location: %d",
               o_vpdLocation );

    TRACSSCOMP( g_trac_spd,
                EXIT_MRK"getVpdLocation()" );

    return err;
}


// ------------------------------------------------------------------
// getPnorAddr
// ------------------------------------------------------------------
errlHndl_t getPnorAddr ( pnorInformation & i_pnorInfo,
                         uint64_t &io_cachedAddr,
                         mutex_t * i_mutex )
{
    errlHndl_t err = NULL;
    PNOR::SectionInfo_t info;

    TRACSSCOMP( g_trac_vpd,
                ENTER_MRK"getPnorAddr()" );

    do
    {
        // Get SPD PNOR section info from PNOR RP
        err = PNOR::getSectionInfo( i_pnorInfo.pnorSection,
                                    i_pnorInfo.pnorSide,
                                    info );

        if( err )
        {
            break;
        }

        // Set the globals appropriately
        mutex_lock( i_mutex );
        io_cachedAddr = info.vaddr;
        mutex_unlock( i_mutex );
    } while( 0 );

    TRACSSCOMP( g_trac_vpd,
                EXIT_MRK"getPnorAddr() - addr: 0x%08x",
                io_cachedAddr );

    return err;
}


// ------------------------------------------------------------------
// readPNOR
// ------------------------------------------------------------------
errlHndl_t readPNOR ( uint64_t i_byteAddr,
                      size_t i_numBytes,
                      void * o_data,
                      TARGETING::Target * i_target,
                      pnorInformation & i_pnorInfo,
                      uint64_t &io_cachedAddr,
                      mutex_t * i_mutex )
{
    errlHndl_t err = NULL;
    int64_t vpdLocation = 0;
    uint64_t addr = 0x0;
    const char * readAddr = NULL;

    TRACSSCOMP( g_trac_vpd,
                ENTER_MRK"readPNOR()" );

    do
    {
        // Check if we have the PNOR addr cached.
        if( 0x0 == io_cachedAddr )
        {
            err = getPnorAddr( i_pnorInfo,
                               io_cachedAddr,
                               i_mutex );

            if( err )
            {
                break;
            }
        }
        addr = io_cachedAddr;

        // Find vpd location of the target
        err = getVpdLocation( vpdLocation,
                              i_target );

        if( err )
        {
            break;
        }

        // Offset cached address by vpd location multiplier
        addr += (vpdLocation * i_pnorInfo.segmentSize);

        // Now offset into that chunk of data by i_byteAddr
        addr += i_byteAddr;

        TRACUCOMP( g_trac_vpd,
                   INFO_MRK"Address to read: 0x%08x",
                   addr );

        //TODO: Validate write is within bounds of appropriate PNOR
        //   partition/section.   RTC: 51807

        // Pull the data
        readAddr = reinterpret_cast<const char*>( addr );
        memcpy( o_data,
                readAddr,
                i_numBytes );
    } while( 0 );

    TRACSSCOMP( g_trac_vpd,
                EXIT_MRK"readPNOR()" );

    return err;
}


// ------------------------------------------------------------------
// writePNOR
// ------------------------------------------------------------------
errlHndl_t writePNOR ( uint64_t i_byteAddr,
                       size_t i_numBytes,
                       void * i_data,
                       TARGETING::Target * i_target,
                       pnorInformation & i_pnorInfo,
                       uint64_t &io_cachedAddr,
                       mutex_t * i_mutex )
{
    errlHndl_t err = NULL;
    int64_t vpdLocation = 0;
    uint64_t addr = 0x0;
    const char * writeAddr = NULL;

    TRACSSCOMP( g_trac_vpd,
                ENTER_MRK"writePNOR()" );

    do
    {
        // Check if we have the PNOR addr cached.
        if( 0x0 == io_cachedAddr )
        {
            err = getPnorAddr( i_pnorInfo,
                               io_cachedAddr,
                               i_mutex );

            if( err )
            {
                break;
            }
        }
        addr = io_cachedAddr;

        // Find vpd location of the target
        err = getVpdLocation( vpdLocation,
                              i_target );

        if( err )
        {
            break;
        }

        // Offset cached address by vpd location multiplier
        addr += (vpdLocation * i_pnorInfo.segmentSize);

        // Now offset into that chunk of data by i_byteAddr
        addr += i_byteAddr;

        //TODO: Validate write is within bounds of appropriate PNOR
        //   partition/section.   RTC: 51807

        TRACUCOMP( g_trac_vpd,
                   INFO_MRK"Address to write: 0x%08x",
                   addr );

        // Write the data
        writeAddr = reinterpret_cast<const char*>( addr );
        memcpy( (void*)(writeAddr),
                i_data,
                i_numBytes );
    } while( 0 );

    TRACSSCOMP( g_trac_vpd,
                EXIT_MRK"writePNOR()" );

    return err;
}

// ------------------------------------------------------------------
// sendMboxWriteMsg
// ------------------------------------------------------------------
errlHndl_t sendMboxWriteMsg ( size_t i_numBytes,
                              void * i_data,
                              TARGETING::Target * i_target,
                              VPD_MSG_TYPE i_type,
                              VpdWriteMsg_t& i_record )
{
    errlHndl_t l_err = NULL;
    msg_t* msg = NULL;

    TRACSSCOMP( g_trac_vpd,
                ENTER_MRK"sendMboxWriteMsg()" );

    do
    {
        //Create a mailbox message to send to FSP
        msg = msg_allocate();
        msg->type = i_type;
        msg->data[0] = i_record.data0;
        msg->data[1] = i_numBytes;

        //should never need more than 4KB  @fixme
        assert( i_numBytes < PAGESIZE);

        msg->extra_data = malloc( i_numBytes );
        memcpy( msg->extra_data, i_data, i_numBytes );
        TRACFCOMP( g_trac_vpd, "extra_data=%p", msg->extra_data );

        TRACFCOMP( g_trac_vpd,
                   INFO_MRK"Send msg to FSP to write VPD type %.8X, record %d, offset 0x%X",
                   i_type,
                   i_record.rec_num,
                   i_record.offset );

        //Create a mbox message with the error log and send it to FSP
        //We only send error log to FSP when mailbox is enabled
        if( !MBOX::mailbox_enabled() )
        {
            TRACFCOMP(g_trac_vpd, INFO_MRK "Mailbox is disabled, skipping VPD write");
            TRACFBIN( g_trac_vpd, "msg=", msg, sizeof(msg_t) );
            TRACFBIN( g_trac_vpd, "extra=", msg->extra_data, i_numBytes );
        }

        l_err = MBOX::send( MBOX::FSP_VPD_MSGQ, msg );
        if( l_err )
        {
            TRACFCOMP(g_trac_vpd,
                      ERR_MRK "Failed sending VPD to FSP for %.8X",
                      TARGETING::get_huid(i_target));
            ERRORLOG::ErrlUserDetailsTarget(i_target).addToLog(l_err);

            l_err->collectTrace("VPD",1024);
            if( VPD_WRITE_DIMM == i_type )
            {
                l_err->collectTrace("SPD",1024);
            }
            else if( VPD_WRITE_PROC == i_type )
            {
                l_err->collectTrace("MVPD",1024);
            }
            else if( VPD_WRITE_MEMBUF == i_type )
            {
                //l_err->collectTrace("CVPD",1024);  @TODO-Fill in with RTC:44009
            }

            // just commit the log and move on, nothing else to do           
            errlCommit( l_err, VPD_COMP_ID );
            l_err = NULL;

            free( msg->extra_data );
            msg->extra_data = NULL;
            msg_free( msg );
        }
    } while( 0 );

    TRACSSCOMP( g_trac_vpd,
                EXIT_MRK"sendMboxWriteMsg()" );

    return l_err;
}


}; //end VPD namespace
