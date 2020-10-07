/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/runtime/rt_vpd.C $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2020                        */
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
#include <runtime/interface.h>            // g_hostInterfaces
#include <util/runtime/rt_fwreq_helper.H>      // firmware_request_helper
#include <targeting/common/util.H>
#include <util/runtime/util_rt.H>
#include <targeting/runtime/rt_targeting.H>
#include <runtime/interface.h>
#include <initservice/initserviceif.H>
#include <i2c/i2cif.H>

#include "vpd.H"
#include "mvpd.H"
#include "cvpd.H"
#include "spd.H"

using namespace ERRORLOG;

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
static uint64_t g_reserved_mem_addr[] = {0, 0, 0, 0};
#define MAX_RSVD_MEM_ADDRS (sizeof(g_reserved_mem_addr) / sizeof(uint64_t))


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
        // we may need to use the VPD cache in memory so we copy the RT
        // switch to the common switch.

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
                        uint8_t i_instance,
                        uint64_t &io_cachedAddr,
                        mutex_t * i_mutex )
{
    errlHndl_t err = NULL;

    if( i_instance >= MAX_RSVD_MEM_ADDRS )
    {
        TRACFCOMP(g_trac_vpd,ERR_MRK"rt_vpd: Node %d is too large for size "
                  "of reserved memory address array %d",
                  i_instance,
                  MAX_RSVD_MEM_ADDRS);
        /*@
        * @errortype
        * @moduleid     VPD::VPD_RT_GET_ADDR
        * @reasoncode   VPD::VPD_RT_NODE_TOO_LARGE
        * @userdata1    Node ID
        * @userdata2    Rsvd Mem Address array size
        * @devdesc      Node for VPD is too large
        */
        err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                      VPD::VPD_RT_GET_ADDR,
                                      VPD::VPD_RT_NODE_TOO_LARGE,
                                      i_instance,
                                      MAX_RSVD_MEM_ADDRS);

        err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                HWAS::SRCI_PRIORITY_HIGH);

        err->collectTrace( "VPD", 256);
    }
    // Get the reserved_mem_addr only once
    else if( g_reserved_mem_addr[i_instance] == 0 )
    {
        TRACDCOMP( g_trac_vpd, "Grabbing rsvd mem for instance %d", i_instance );

        uint64_t l_vpdSize;
        g_reserved_mem_addr[i_instance] =
            hb_get_rt_rsvd_mem(Util::HBRT_MEM_LABEL_VPD,
                               i_instance,
                               l_vpdSize);

        if( g_reserved_mem_addr[i_instance] == 0 )
        {
            TRACFCOMP(g_trac_vpd,ERR_MRK"rt_vpd: Failed to get VPD addr. "
                    "vpd_type: %d",
                    i_pnorInfo.pnorSection);
            /*@
            * @errortype
            * @moduleid     VPD::VPD_RT_GET_ADDR
            * @reasoncode   VPD::VPD_RT_NULL_VPD_PTR
            * @userdata1    VPD type
            * @userdata2    Node ID
            * @devdesc      Hypervisor returned NULL address for VPD
            */
            err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                        VPD::VPD_RT_GET_ADDR,
                                        VPD::VPD_RT_NULL_VPD_PTR,
                                        i_pnorInfo.pnorSection,
                                        i_instance);

            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                    HWAS::SRCI_PRIORITY_HIGH);

            err->collectTrace( "VPD", 256);
        }
    }

    uint64_t vpd_addr = g_reserved_mem_addr[i_instance];

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
    TARGETING::NODE_ID l_nodeId = 0xFF;
    int64_t vpdLocation = 0;
    uint64_t addr = 0x0;
    const char * readAddr = NULL;

    TRACSSCOMP( g_trac_vpd,
                ENTER_MRK"RT fake readPNOR()" );

    // Get the node ID associated with the input target
    l_nodeId = TARGETING::AttrRP::getNodeId(i_target);

    do
    {
        // fake getPnorAddr gets memory address of VPD
        err = getPnorAddr(i_pnorInfo,
                          l_nodeId,
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

    TARGETING::NODE_ID l_nodeId = TARGETING::NODE0;
    int64_t vpdLocation = 0;
    uint64_t addr = 0x0;
    const char * writeAddr = NULL;

    TRACSSCOMP( g_trac_vpd,
                ENTER_MRK"RT writePNOR()" );

    // Get AttrRP pointer
    TARGETING::AttrRP *l_attrRP = &TARG_GET_SINGLETON(TARGETING::theAttrRP);
    // Get the node ID associated with the input target
    l_attrRP->getNodeId(i_target, l_nodeId);

    do
    {
        //----------------------------
        // Write memory version of VPD
        //----------------------------
        // Fake getPnorAddr gets memory address of VPD
        err = getPnorAddr( i_pnorInfo,
                           l_nodeId,
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
        if(INITSERVICE::spBaseServicesEnabled())
        {
            TRACFCOMP(g_trac_vpd,
                   ERR_MRK"rt_vpd:writePNOR not supported with FSP, skipping");
            break;
        }

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
// sendMboxWriteMsg
// ------------------------------------------------------------------
errlHndl_t sendMboxWriteMsg ( size_t i_numBytes,
                              void * i_data,
                              TARGETING::Target * i_target,
                              VPD_MSG_TYPE i_type,
                              VpdWriteMsg_t& i_record )
{
    errlHndl_t l_err = nullptr;

    // Put the handle to the firmware messages out here
    // so it is easier to free later
    hostInterfaces::hbrt_fw_msg *l_req_fw_msg = nullptr;
    hostInterfaces::hbrt_fw_msg *l_resp_fw_msg = nullptr;

    // Note if we disabled the centaur i2c sensor cache
    bool l_i2cDisabled = false;

    TRACFCOMP( g_trac_vpd, INFO_MRK
               "sendMboxWriteMsg: Send msg to FSP to write VPD type %.8X, "
               "record %d, offset 0x%X",
               i_type,
               i_record.rec_num,
               i_record.offset );

    do
    {
        if(!INITSERVICE::spBaseServicesEnabled())
        {
            // No SP Base Services available at runtime then simply return
            TRACFCOMP( g_trac_vpd, ERR_MRK
                       "No SP Base Services available at runtime.")
            break;
        }

        if ((nullptr == g_hostInterfaces) ||
            (nullptr == g_hostInterfaces->firmware_request))
        {
            TRACFCOMP(g_trac_vpd, ERR_MRK"sendMboxWriteMsg: "
                      "Hypervisor firmware_request interface not linked");

            /*@
             * @errortype
             * @severity         ERRL_SEV_INFORMATIONAL
             * @moduleid         VPD_SEND_MBOX_WRITE_MESSAGE
             * @reasoncode       VPD_RT_NULL_FIRMWARE_REQUEST_PTR
             * @userdata1        HUID of target
             * @userdata2        VPD message type
             * @devdesc          MBOX send not supported in HBRT
             */
             l_err= new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                  VPD_SEND_MBOX_WRITE_MESSAGE,
                                  VPD_RT_NULL_FIRMWARE_REQUEST_PTR,
                                  TARGETING::get_huid(i_target),
                                  i_type, true);
            break;
        }


        // Note - There is a potential collision on the I2C bus with
        //  the OCC code.  On FSP systems this is handled by the HWSV
        //  code.  On OP systems this is handled by OPAL.

        TARGETING::Target* pNode = nullptr;
        if(i_target != nullptr)
        {
            if(   i_target->getAttr<TARGETING::ATTR_TYPE>()
               == TARGETING::TYPE_NODE)
            {
                pNode = i_target;
            }
            else
            {
                auto nodeType = TARGETING::TYPE_NODE;
                pNode = TARGETING::getParent(i_target,nodeType);
            }
        }

        if(pNode == nullptr)
        {
            TRACFCOMP(g_trac_vpd, ERR_MRK"sendMboxWriteMsg (runtime): "
                      "Failed to determine HUID of node target containing "
                      "(or equalling) requested target with HUID of 0x%08X",
                      TARGETING::get_huid(i_target));
            /*@
             * @errortype
             * @moduleid   VPD_SEND_MBOX_WRITE_MESSAGE
             * @reasoncode VPD_FAILED_TO_RESOLVE_NODE_TARGET
             * @userdata1  HUID of target to update VPD for
             * @userdata2  VPD message type
             * @devdesc    Could not determine which node the target is in
             * @custdesc   Runtime vital product data update failure
             */
            l_err = new ErrlEntry(
                        ERRL_SEV_UNRECOVERABLE,
                        VPD_SEND_MBOX_WRITE_MESSAGE,
                        VPD_FAILED_TO_RESOLVE_NODE_TARGET,
                        TARGETING::get_huid(i_target),
                        i_type,
                        true);
            break;
        }

        const uint32_t nodeHuid = pNode->getAttr<TARGETING::ATTR_HUID>();

        // Get an accurate size of memory needed to transport
        // the data for the firmware_request request struct
        uint32_t l_fsp_req_size = GENERIC_FSP_MBOX_MESSAGE_BASE_SIZE;
        // add on the 2 header words that are used in the IPL-time
        //  version of the VPD write message (see vpd.H)
        l_fsp_req_size +=   sizeof(nodeHuid) + sizeof(VpdWriteMsg_t)
                          + sizeof(uint64_t);
        // add on the extra_data portion of the message
        l_fsp_req_size += i_numBytes;

        // The request data size must be at a minimum the size of the
        // FSP generic message (sizeof(GenericFspMboxMessage_t))
        if (l_fsp_req_size < sizeof(GenericFspMboxMessage_t))
        {
            l_fsp_req_size = sizeof(GenericFspMboxMessage_t);
        }

        // Calculate the TOTAL size of hostInterfaces::hbrt_fw_msg which
        // means only adding hostInterfaces::HBRT_FW_MSG_BASE_SIZE to
        // the previous calculated data size
        uint64_t l_req_fw_msg_size = hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                                     l_fsp_req_size;

        // Create the firmware_request request struct to send data
        l_req_fw_msg =
                  (hostInterfaces::hbrt_fw_msg *)malloc(l_req_fw_msg_size);

        // Initialize the firmware_request request struct
        l_req_fw_msg->generic_msg.initialize();

        // Populate the firmware_request request struct with given data
        l_req_fw_msg->io_type = hostInterfaces::HBRT_FW_MSG_HBRT_FSP_REQ;
        l_req_fw_msg->generic_msg.dataSize = l_fsp_req_size;
        l_req_fw_msg->generic_msg.msgq = MBOX::FSP_VPD_MSGQ;
        l_req_fw_msg->generic_msg.msgType = i_type;
        l_req_fw_msg->generic_msg.__req = GenericFspMboxMessage_t::REQUEST;

        // the full message looks like this
        struct VpdWriteMsgHBRT_t
        {
            uint32_t nodeHuid;
            VpdWriteMsg_t vpdInfo;
            uint64_t vpdBytes;
            uint8_t vpdData; //of vpdBytes size

        } PACKED;

        VpdWriteMsgHBRT_t* l_msg = reinterpret_cast<VpdWriteMsgHBRT_t*>
          (&(l_req_fw_msg->generic_msg.data));
        l_msg->nodeHuid = nodeHuid;
        l_msg->vpdInfo = i_record;
        l_msg->vpdBytes = i_numBytes;
        memcpy( &(l_msg->vpdData), i_data, i_numBytes );

        // Create the firmware_request response struct to receive data
        // NOTE: For messages to the FSP the response size must match
        // the request size.
        // No need to check for expected response size > request
        // size because they use the same base structure
        uint64_t l_resp_fw_msg_size = l_req_fw_msg_size;
        l_resp_fw_msg =
                   (hostInterfaces::hbrt_fw_msg *)malloc(l_resp_fw_msg_size);
        memset(l_resp_fw_msg, 0, l_resp_fw_msg_size);

        // We need to temporarily disable the Centaur i2c sensor cache
        //  function to avoid some potential collisions while the SPD
        //  is getting written.        
        if( i_target->getAttr<TARGETING::ATTR_TYPE>() ==
            TARGETING::TYPE_MEMBUF )
        {
            l_err = I2C::i2cDisableSensorCache(i_target,l_i2cDisabled);
            if ( l_err )
            {
                TRACFCOMP(g_trac_vpd,
                          ERR_MRK" Disable Sensor Cache failed for HUID=0x%.8X",
                          TARGETING::get_huid(i_target));
                // commit this log and keep going, we still want to attempt the
                //  vpd write since this is only protecting against a window
                //  condition
                errlCommit( l_err, VPD_COMP_ID );
            }
        }

        // Trace out the request structure
        TRACFBIN( g_trac_vpd, INFO_MRK"Sending firmware_request",
                  l_req_fw_msg,
                  l_req_fw_msg_size);

        // Make the firmware_request call
        l_err = firmware_request_helper(l_req_fw_msg_size,
                                        l_req_fw_msg,
                                        &l_resp_fw_msg_size,
                                        l_resp_fw_msg);

        if (l_err)
        {
            break;
        }
    } while (0);

    // Re-enable the Centaur sensor cache even if we hit another error
    if( l_i2cDisabled )
    {
        errlHndl_t tmp_err = nullptr;

        tmp_err = I2C::i2cEnableSensorCache(i_target);

        if( l_err && tmp_err)
        {
            delete tmp_err;
            TRACFCOMP(g_trac_vpd,
                      ERR_MRK" Enable Sensor Cache failed for HUID=0x%.8X",
                      TARGETING::get_huid(i_target));
        }
        else if(tmp_err)
        {
            l_err = tmp_err;
        }
    }

    // release the memory created
    if( l_req_fw_msg ) { free(l_req_fw_msg); }
    if( l_resp_fw_msg ) { free(l_resp_fw_msg); }
    l_req_fw_msg = l_resp_fw_msg = nullptr;

    // Commit any errors we get in here because we'd like the main
    //  function to complete even if we can't send the data out
    if (l_err)
    {
        errlCommit( l_err, VPD_COMP_ID );
    }

    return l_err;
}

}; // end namepsace VPD
