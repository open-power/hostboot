/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/runtime/rt_vpd.C $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2015                        */
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
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <vpd/vpdreasoncodes.H>
#include <initservice/initserviceif.H>
#include <devicefw/driverif.H>
#include <i2c/eepromif.H>
#include <runtime/interface.h>
#include <targeting/common/util.H>
#include "vpd.H"
#include "mvpd.H"
#include "cvpd.H"
#include "spd.H"

extern trace_desc_t* g_trac_vpd;

// ------------------------
// Macros for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)
//#define TRACSSCOMP(args...)  TRACFCOMP(args)
#define TRACSSCOMP(args...)

// Global variable to store the location of hbrt-vpd-image returned by the
// host interface get_reserved_mem function.  We only want to call the
// function once as memory is allocated with every call.
static uint64_t g_reserved_mem_addr = 0;

namespace VPD
{

// ------------------------------------------------------------------
// rtVpdInit
// ------------------------------------------------------------------
struct rtVpdInit
{
    rtVpdInit()
    {
        // The VPD code that is common to IPL and runtime uses the
        // pnorCacheValid switch.  During a golden-side boot this switch
        // gets cleared when the VPD cache is invalidated.  At runtime
        // we may need to use the VPD cache (really the devtree data in
        // memory) so we copy the RT switch to the common switch.

        // Find all the targets with VPD switches
        for (TARGETING::TargetIterator target =
            TARGETING::targetService().begin();
            target != TARGETING::targetService().end();
            ++target)
        {
            TARGETING::ATTR_VPD_SWITCHES_type l_switch;
            if(target->tryGetAttr<TARGETING::ATTR_VPD_SWITCHES>(l_switch))
            {
                l_switch.pnorCacheValid = l_switch.pnorCacheValidRT;
                target->setAttr<TARGETING::ATTR_VPD_SWITCHES>( l_switch );
            }
        }
    }
};
rtVpdInit g_rtVpdInit;

// ------------------------------------------------------------------
// Fake getPnorAddr - VPD image is in memory
// ------------------------------------------------------------------
errlHndl_t getPnorAddr( pnorInformation & i_pnorInfo,
                        uint64_t &io_cachedAddr,
                        mutex_t * i_mutex )
{
    errlHndl_t err = NULL;

    // Get the reserved_mem_addr only once
    if( g_reserved_mem_addr == 0 )
    {
        if( g_hostInterfaces != NULL &&
            g_hostInterfaces->get_reserved_mem)
        {
            g_reserved_mem_addr =
                g_hostInterfaces->get_reserved_mem("ibm,hbrt-vpd-image",0);

            if( g_reserved_mem_addr == 0 )
            {
                TRACFCOMP(g_trac_vpd,ERR_MRK"rt_vpd: Failed to get VPD addr. "
                        "vpd_type: %d",
                        i_pnorInfo.pnorSection);
                /*@
                * @errortype
                * @moduleid     VPD::VPD_RT_GET_ADDR
                * @reasoncode   VPD::VPD_RT_NULL_VPD_PTR
                * @userdata1    VPD type
                * @userdata2    0
                * @devdesc      Hypervisor returned NULL address for VPD
                */
                err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                            VPD::VPD_RT_GET_ADDR,
                                            VPD::VPD_RT_NULL_VPD_PTR,
                                            i_pnorInfo.pnorSection,
                                            0);

                err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                        HWAS::SRCI_PRIORITY_HIGH);

                err->collectTrace( "VPD", 256);
            }
        }
        else // interface not set
        {
            TRACFCOMP(g_trac_vpd,ERR_MRK"Hypervisor vpd interface not linked");
            /*@
            * @errortype
            * @moduleid     VPD::VPD_RT_GET_ADDR
            * @reasoncode   VPD::VPD_RT_NOT_INITIALIZED
            * @userdata1    VPD type
            * @userdata2    0
            * @devdesc      Runtime VPD interface not linked.
            */
            err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                        VPD::VPD_RT_GET_ADDR,
                                        VPD::VPD_RT_NOT_INITIALIZED,
                                        i_pnorInfo.pnorSection,
                                        0);

            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                    HWAS::SRCI_PRIORITY_HIGH);

            err->collectTrace( "VPD", 256);
        }
    }

    uint64_t vpd_addr = g_reserved_mem_addr;

    if(!err)
    {

        switch(i_pnorInfo.pnorSection)
        {
            case PNOR::DIMM_JEDEC_VPD:
                break;

            case PNOR::MODULE_VPD:
                vpd_addr += VMM_DIMM_JEDEC_VPD_SIZE;
                break;

            case PNOR::CENTAUR_VPD:
                vpd_addr += (VMM_DIMM_JEDEC_VPD_SIZE + VMM_MODULE_VPD_SIZE);
                break;

            default: // Huh?
                TRACFCOMP(g_trac_vpd, ERR_MRK
                          "RT getPnorAddr: Invalid VPD type: 0x%x",
                          i_pnorInfo.pnorSection);

                /*@
                 * @errortype
                 * @reasoncode       VPD::VPD_RT_INVALID_TYPE
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         VPD::VPD_RT_GET_ADDR
                 * @userdata1        Requested VPD TYPE
                 * @userdata2        0
                 * @devdesc          Requested VPD type is invalid or not
                 *                   supported at runtime
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               VPD::VPD_RT_GET_ADDR,
                                               VPD::VPD_RT_INVALID_TYPE,
                                               i_pnorInfo.pnorSection,
                                               0 );

                err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                         HWAS::SRCI_PRIORITY_HIGH);

                err->collectTrace( "VPD", 256);

                break;
        }
    }

    if(!err)
    {
        io_cachedAddr = vpd_addr;
    }

    return err;
}

// ------------------------------------------------------------------
// Fake readPNOR - image is in memory
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
                ENTER_MRK"RT fake readPNOR()" );

    do
    {
        // fake getPnorAddr gets memory address of VPD
        err = getPnorAddr(i_pnorInfo,
                          io_cachedAddr,
                          i_mutex );
        if(err)
        {
            break;
        }

        addr = io_cachedAddr;

        err = getVpdLocation( vpdLocation,
                              i_target);

        if(err)
        {
            break;
        }

        // Add Offset for target vpd location
        addr += (vpdLocation * i_pnorInfo.segmentSize);

        // Add keyword offset
        addr += i_byteAddr;

        TRACUCOMP( g_trac_vpd,
                   INFO_MRK"Address to read: 0x%08x",
                   addr );

        readAddr = reinterpret_cast<const char *>( addr );
        memcpy( o_data,
                readAddr,
                i_numBytes );
    } while(0);

    TRACSSCOMP( g_trac_vpd,
                EXIT_MRK"RT fake readPNOR()" );

    return err;
}

// ------------------------------------------------------------------
// Fake writePNOR - image is in memory
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
                ENTER_MRK"RT writePNOR()" );

    do
    {
        if(INITSERVICE::spBaseServicesEnabled())
        {
            TRACFCOMP(g_trac_vpd,ERR_MRK"rt_vpd:writePNOR not supported with FSP");

            /*@
             * @errortype
             * @reasoncode       VPD::VPD_RT_WRITE_NOT_SUPPORTED
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         VPD::VPD_RT_WRITE_PNOR
             * @userdata1        Target
             * @userdata2        0
             * @devdesc          MBOX send not supported in HBRT
             */
            err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          VPD::VPD_RT_WRITE_PNOR,
                                          VPD::VPD_RT_WRITE_NOT_SUPPORTED,
                                          TARGETING::get_huid(i_target),
                                          0);

            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_HIGH);

            err->collectTrace( "VPD", 256);

            break;
        }

        //----------------------------
        // Write memory version of VPD
        //----------------------------
        // Fake getPnorAddr gets memory address of VPD
        err = getPnorAddr( i_pnorInfo,
                           io_cachedAddr,
                           i_mutex );
        if(err)
        {
            break;
        }

        addr = io_cachedAddr;

        err = getVpdLocation( vpdLocation,
                              i_target);
        if(err)
        {
            break;
        }

        // Add Offset for target vpd location
        addr += (vpdLocation * i_pnorInfo.segmentSize);

        // Add keyword offset
        addr += i_byteAddr;

        TRACUCOMP( g_trac_vpd,
                   INFO_MRK"Address to write: 0x%08x",
                   addr );

        // Write fake VPD in main-store
        writeAddr = reinterpret_cast<const char *>( addr );
        memcpy( (void*)(writeAddr),
                i_data,
                i_numBytes );

        //--------------------------------
        // Write PNOR cache version of VPD
        //--------------------------------

        // Check if the VPD PNOR cache is loaded for this target
        TARGETING::ATTR_VPD_SWITCHES_type vpdSwitches =
                i_target->getAttr<TARGETING::ATTR_VPD_SWITCHES>();
        if( vpdSwitches.pnorCacheValid && !(vpdSwitches.disableWriteToPnorRT) )
        {
            PNOR::SectionInfo_t info;
            writeAddr = NULL;

            // Get SPD PNOR section info from PNOR RP
            err = PNOR::getSectionInfo( i_pnorInfo.pnorSection,
                                        info );
            if( err )
            {
                break;
            }

            addr = info.vaddr;

            // Offset cached address by vpd location multiplier
            addr += (vpdLocation * i_pnorInfo.segmentSize);

            // Now offset into that chunk of data by i_byteAddr
            addr += i_byteAddr;

            TRACUCOMP( g_trac_vpd,
                       INFO_MRK"Address to write: 0x%08x",
                       addr );

            // Write the data
            writeAddr = reinterpret_cast<const char*>( addr );
            memcpy( (void*)(writeAddr),
                    i_data,
                    i_numBytes );

            // Flush the page to make sure it gets to the PNOR
            err = PNOR::flush( info.id );
            if( err )
            {
                break;
            }
        }

    } while(0);

    TRACSSCOMP( g_trac_vpd,
                EXIT_MRK"RT writePNOR()" );

    return err;
}

// ------------------------------------------------------------------
// sendMboxWriteMsg - not supported at runtime
// Treat the same way HB does if mbox is not available
// ------------------------------------------------------------------
errlHndl_t sendMboxWriteMsg ( size_t i_numBytes,
                              void * i_data,
                              TARGETING::Target * i_target,
                              VPD_MSG_TYPE i_type,
                              VpdWriteMsg_t& i_record )
{
    errlHndl_t err = NULL;
    TRACFCOMP( g_trac_vpd, INFO_MRK
               "sendMboxWriteMsg: Send msg to FSP to write VPD type %.8X, "
               "record %d, offset 0x%X",
               i_type,
               i_record.rec_num,
               i_record.offset );

    // mimic the behavior of hostboot when mbox is not available.
    TRACFCOMP( g_trac_vpd, ERR_MRK
               "No SP Base Services available at runtime.");

    /*@
     * @errortype
     * @reasoncode       VPD::VPD_MBOX_NOT_SUPPORTED_RT
     * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
     * @moduleid         VPD::VPD_SEND_MBOX_WRITE_MESSAGE
     * @userdata1        VPD message type
     * @userdata2        0
     * @devdesc          MBOX send not supported in HBRT
     */
    err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                  VPD::VPD_SEND_MBOX_WRITE_MESSAGE,
                                  VPD::VPD_MBOX_NOT_SUPPORTED_RT,
                                  i_type,
                                  0);

    err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                             HWAS::SRCI_PRIORITY_HIGH);

    err->collectTrace( "VPD", 256);

    return err;
}


}; // end namepsace VPD
