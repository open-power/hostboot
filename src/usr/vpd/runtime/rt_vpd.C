/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/runtime/rt_vpd.C $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2017                        */
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
#include <runtime/interface.h>            // g_hostInterfaces
#include <util/runtime/rt_fwreq_helper.H>      // firmware_request_helper
#include <targeting/common/util.H>
#include <util/runtime/util_rt.H>
#include <runtime/rt_targeting.H>
#include <runtime/interface.h>
#include <initservice/initserviceif.H>

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
static uint64_t g_reserved_mem_addr = 0;

// See i_operation of req_i2c_lock structure
static const uint8_t LOCKOP_LOCK    = 1;
static const uint8_t LOCKOP_UNLOCK  = 2;

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
                        uint64_t &io_cachedAddr,
                        mutex_t * i_mutex )
{
    errlHndl_t err = NULL;

    // Get the reserved_mem_addr only once
    if( g_reserved_mem_addr == 0 )
    {
        uint64_t l_vpdSize;
        g_reserved_mem_addr = hb_get_rt_rsvd_mem(Util::HBRT_MEM_LABEL_VPD,
                                                 0,
                                                 l_vpdSize);

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


/**
 *  @brief Fill in the iic lock message to send to FSP
 *  @param[in] i_target target device
 *  @param[in] i_operation 1=lock, 2=unlock
 *  @param[in/out] io_i2cLockMsg - i2c lock msg (fills this in)
 *  @platform FSP
 *  @return errlHndl_t - NULL if successful,
 *                       otherwise a pointer to the error log.
 */
errlHndl_t fillI2CLockMsg( TARGETING::Target * i_target, uint8_t i_operation,
               hostInterfaces::hbrt_fw_msg * io_i2cLockMsg)
{
    errlHndl_t l_err = nullptr;
    TRACFCOMP( g_trac_vpd, ENTER_MRK
             "fillI2CLockMsg: %s i2cMaster of target huid 0x%llX",
             (i_operation == LOCKOP_LOCK)?"lock":"unlock", get_huid(i_target) );

    do {
        io_i2cLockMsg->req_i2c_lock.i_operation = i_operation;

        // find i2cMaster
        TARGETING::EepromVpdPrimaryInfo l_eepromData;
        // Using tryGetAttr as we want the code to continue
        if(! (i_target->tryGetAttr<TARGETING::ATTR_EEPROM_VPD_PRIMARY_INFO>
                    ( l_eepromData )) )
        {
            TRACFCOMP( g_trac_vpd, ERR_MRK"fillI2CLockMsg() - "
                "unable to get ATTR_EEPROM_VPD_PRIMARY_INFO from 0x%llX",
                TARGETING::get_huid(i_target) );

            /*@
             * @errortype
             * @severity         ERRORLOG::ERRL_SEV_PREDICTIVE
             * @moduleid         VPD::VPD_FILL_I2C_LOCK_MSG
             * @reasoncode       VPD::VPD_EEPROM_VPD_PRIMARY_INFO_MISSING
             * @userdata1        HUID of target
             * @userdata2        nothing
             * @devdesc          Unable to find VPD info necessary
             *                   for lock/unlock() request
             * @custdesc         A problem was detected during runtime of
             *                   the system while updating VPD
             */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                    VPD::VPD_FILL_I2C_LOCK_MSG,
                                    VPD::VPD_EEPROM_VPD_PRIMARY_INFO_MISSING,
                                    TARGETING::get_huid(i_target),
                                    0, true );
            break;
        }


        io_i2cLockMsg->req_i2c_lock.i_i2cMaster = l_eepromData.engine;

        // Since it exists, convert to a target
        TARGETING::Target * l_pChipTarget =
            TARGETING::targetService().toTarget(l_eepromData.i2cMasterPath);

        if( nullptr == l_pChipTarget )
        {
            TRACFCOMP( g_trac_vpd,
                       ERR_MRK"fillI2CLockMsg() - I2C Master "
                              "Path target was NULL!" );

            /*@
             * @errortype
             * @severity         ERRORLOG::ERRL_SEV_PREDICTIVE
             * @moduleid         VPD::VPD_FILL_I2C_LOCK_MSG
             * @reasoncode       VPD::VPD_TARGET_CHIP_NOT_FOUND
             * @userdata1        HUID of target
             * @userdata2        Nothing
             * @devdesc          Unable to find chipId for lock/unlock() request
             * @custdesc         A problem was detected during runtime of
             *                   the system where locking is currently
             *                   unavailable for sending vpd to the host
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                            VPD::VPD_FILL_I2C_LOCK_MSG,
                                            VPD::VPD_TARGET_CHIP_NOT_FOUND,
                                            TARGETING::get_huid(i_target),
                                            0,true);
            break;
        }

        // Get the Proc Chip Id
        RT_TARG::rtChipId_t l_chipId = 0;
        l_err = RT_TARG::getRtTarget(l_pChipTarget, l_chipId);
        if(l_err)
        {
            TRACFCOMP( g_trac_vpd, ERR_MRK"fillI2CLockMsg: getRtTarget ERROR" );
            break;
        }
        io_i2cLockMsg->req_i2c_lock.i_chipId =
                                        reinterpret_cast<uint64_t>(l_chipId);
    }
    while (0);

    TRACFCOMP( g_trac_vpd, EXIT_MRK
               "fillI2CLockMsg: target 0x%llX %s message "
               "i_chipId: 0x%llX, i_i2cMaster: %d, i_operation: %d",
               get_huid(i_target), (i_operation == LOCKOP_LOCK)?"lock":"unlock",
               io_i2cLockMsg->req_i2c_lock.i_chipId,
               io_i2cLockMsg->req_i2c_lock.i_i2cMaster,
               io_i2cLockMsg->req_i2c_lock.i_operation );

    return l_err;
}

/**
 *  @brief Send iic lock message to FSP
 *  @param[in] i_target target device
 *  @param[in] i_operation 1=lock, 2=unlock
 *  @platform FSP
 *  @return errlHndl_t - nullptr if successful,
 *                       otherwise a pointer to the error log.
 */
errlHndl_t sendI2CLockMsg( TARGETING::Target * i_target,
                           uint8_t i_operation )
{
    errlHndl_t l_err = nullptr;

    TRACFCOMP( g_trac_vpd, INFO_MRK
        "sendI2CLockMsg: %s i2cMaster of target huid 0x%llX",
        (i_operation == LOCKOP_LOCK)?"lock":"unlock", get_huid(i_target) );

    hostInterfaces::hbrt_fw_msg *l_req_fw_msg = nullptr;
    hostInterfaces::hbrt_fw_msg *l_resp_fw_msg = nullptr;

    do
    {
        if ((nullptr == g_hostInterfaces) ||
            (nullptr == g_hostInterfaces->firmware_request))
        {
            /*@
             * @errortype
             * @severity         ERRORLOG::ERRL_SEV_INFORMATIONAL
             * @moduleid         VPD::VPD_SEND_I2C_LOCK_MSG
             * @reasoncode       VPD::VPD_RT_NULL_FIRMWARE_REQUEST_PTR
             * @userdata1        HUID of target
             * @userdata2        I2C Lock message type
             * @devdesc          MBOX send not supported in HBRT
             * @custdesc         A problem was detected during runtime of
             *                   the system where locking is currently
             *                   unavailable for sending vpd to the host
             */
             l_err= new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                      VPD::VPD_SEND_I2C_LOCK_MSG,
                                      VPD::VPD_RT_NULL_FIRMWARE_REQUEST_PTR,
                                      TARGETING::get_huid(i_target),
                                      hostInterfaces::HBRT_FW_MSG_TYPE_I2C_LOCK,
                                      true);
            break;
        }

        // Get an accurate size of memory actually needed to transport the data
        size_t l_req_fw_msg_size = hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                            sizeof(hostInterfaces::hbrt_fw_msg::req_i2c_lock);

        //create the firmware_request structure to carry the i2c lock msg data
        l_req_fw_msg =
                  (hostInterfaces::hbrt_fw_msg *)malloc(l_req_fw_msg_size);
        memset(l_req_fw_msg, 0, l_req_fw_msg_size);

        // populate the firmware_request structure with given data
        l_req_fw_msg->io_type = hostInterfaces::HBRT_FW_MSG_TYPE_I2C_LOCK;

        // build up msg
        l_err = fillI2CLockMsg(i_target, i_operation, l_req_fw_msg);
        if (l_err)
        {
            TRACFCOMP(g_trac_vpd, ERR_MRK"sendI2CLockMsg: "
                "unable to fill in i2c %s msg",
                (i_operation==LOCKOP_LOCK)?"lock":"unlock");
            break;
        }

        // Create the firmware_request response struct to receive data
        uint64_t l_resp_fw_msg_size = l_req_fw_msg_size;
        l_resp_fw_msg =
                  (hostInterfaces::hbrt_fw_msg *)malloc(l_resp_fw_msg_size);
        memset(l_resp_fw_msg, 0, l_resp_fw_msg_size);

        // Trace out the request structure
        TRACFBIN( g_trac_vpd, INFO_MRK"sendI2CLockMsg: "
                  "Sending firmware_request",
                  l_req_fw_msg,
                  l_req_fw_msg_size);

        // Make the firmware_request call
        l_err = firmware_request_helper(l_req_fw_msg_size,
                                        l_req_fw_msg,
                                        &l_resp_fw_msg_size,
                                        l_resp_fw_msg);
    }
    while (0);

    // release the memory created
    free(l_req_fw_msg);
    free(l_resp_fw_msg);
    l_req_fw_msg = l_resp_fw_msg = nullptr;

    // add VPD traces to all error logs
    if (l_err)
    {
        l_err->collectTrace( "VPD", 256);
    }

    return l_err;
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
    errlHndl_t l_lock_errl = nullptr;

    // Put the handle to the firmware messages out here
    // so it is easier to free later
    hostInterfaces::hbrt_fw_msg *l_req_fw_msg = nullptr;
    hostInterfaces::hbrt_fw_msg *l_resp_fw_msg = nullptr;

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

        // Lock the I2C master for this target before sending VPD to
        // prevent collisions
        l_lock_errl = sendI2CLockMsg(i_target, LOCKOP_LOCK );


        // Get an accurate size of memory needed to transport
        // the data for the firmware_request request struct
        uint32_t l_fsp_req_size = GENERIC_FSP_MBOX_MESSAGE_BASE_SIZE;
        // add on the 2 header words that are used in the IPL-time
        //  version of the VPD write message (see vpd.H)
        l_fsp_req_size += sizeof(VpdWriteMsg_t) + sizeof(uint64_t);
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
            VpdWriteMsg_t vpdInfo;
            uint64_t vpdBytes;
            uint8_t vpdData; //of vpdBytes size
        };
        VpdWriteMsgHBRT_t* l_msg = reinterpret_cast<VpdWriteMsgHBRT_t*>
          (&(l_req_fw_msg->generic_msg.data));
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

    // release the memory created
    if( l_req_fw_msg ) { free(l_req_fw_msg); }
    if( l_resp_fw_msg ) { free(l_resp_fw_msg); }
    l_req_fw_msg = l_resp_fw_msg = nullptr;

    // Commit previous lock error (if any)
    if (l_lock_errl)
    {
        // Associate lock error with this error
        if (l_err)
        {
            l_lock_errl->plid(l_err->plid());
        }
        l_lock_errl->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
        errlCommit( l_lock_errl, VPD_COMP_ID );
    }

    // Unlock i2cMaster for this target
    l_lock_errl = sendI2CLockMsg( i_target, LOCKOP_UNLOCK );
    if (l_lock_errl)
    {
        // Associate unlock error with this error
        if (l_err)
        {
            l_lock_errl->plid(l_err->plid());
        }
        l_lock_errl->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
        errlCommit( l_lock_errl, VPD_COMP_ID );
    }

    if (l_err)
    {
        // @fixme-RTC:180490 - Temporarily commit until FSP code is implemented
        // Just commit the log for now until FSP code is implemented
        l_err->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
        errlCommit( l_err, VPD_COMP_ID );
    }

    return l_err;
}

}; // end namepsace VPD
