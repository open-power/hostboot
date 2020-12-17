/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/eeprom/eepromCache_common.C $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
#include "eepromCache.H"
#include <errl/errlmanager.H>
#include <eeprom/eepromif.H>
#include <eeprom/eepromddreasoncodes.H>
#include <errl/errludtarget.H>

#ifdef __HOSTBOOT_RUNTIME
#include <targeting/attrrp.H>
#else
#include <sys/mm.h>
#endif

extern trace_desc_t* g_trac_eeprom;

//#define TRACSSCOMP(args...)  TRACFCOMP(args)
#define TRACSSCOMP(args...)

namespace EEPROM
{

errlHndl_t buildEepromRecordHeader(TARGETING::Target * i_target,
                                   eeprom_addr_t & io_eepromInfo,
                                   eepromRecordHeader & o_eepromRecordHeader)
{

    TARGETING::Target * l_muxTarget = nullptr;
    TARGETING::Target * l_masterTarget = nullptr;
    TARGETING::TargetService& l_targetService = TARGETING::targetService();
    errlHndl_t l_errl = nullptr;

    do{
        l_errl = eepromReadAttributes(i_target, io_eepromInfo);
        if(l_errl)
        {
            TRACFCOMP( g_trac_eeprom,
                      "buildEepromRecordHeader() error occurred reading eeprom attributes for eepromType %d, target 0x%.08X, returning!!",
                      io_eepromInfo.eepromRole,
                      TARGETING::get_huid(i_target));
            l_errl->collectTrace(EEPROM_COMP_NAME);
            break;
        }


        // Grab the master target so we can read the HUID, if the target is NULL we will not be able
        // to lookup attribute to uniquely ID this eeprom so we will not cache it
        if (io_eepromInfo.accessMethod == EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_I2C)
        {
            l_masterTarget = l_targetService.toTarget( io_eepromInfo.accessAddr.i2c_addr.i2cMasterPath );
        }
        else
        {
            l_masterTarget = l_targetService.toTarget( io_eepromInfo.accessAddr.spi_addr.spiMasterPath );
        }
        if(l_masterTarget == nullptr)
        {
            TRACFCOMP( g_trac_eeprom,
                      "buildEepromRecordHeader() master target associated with target 0x%.08X resolved to a nullptr, check attribute for eepromType %d. Skipping Cache ",
                      TARGETING::get_huid(i_target),
                      io_eepromInfo.eepromRole);
            /*@
            * @errortype
            * @moduleid     EEPROM_CACHE_EEPROM
            * @reasoncode   EEPROM_MASTER_PATH_ERROR
            * @userdata1    HUID of target we want to cache
            * @userdata2    Type of EEPROM we are caching
            * @devdesc      buildEepromRecordHeader invalid master target
            */
            l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            EEPROM_CACHE_EEPROM,
                            EEPROM_MASTER_PATH_ERROR,
                            TARGETING::get_huid(i_target),
                            io_eepromInfo.eepromRole,
                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            l_errl->collectTrace(EEPROM_COMP_NAME);
            break;
        }

        if (io_eepromInfo.accessMethod == EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_I2C)
        {
            // Grab the I2C mux target so we can read the HUID, if the target is NULL we will not be able
            // to lookup attribute to uniquely ID this eeprom so we will not cache it
            l_muxTarget = l_targetService.toTarget( io_eepromInfo.accessAddr.i2c_addr.i2cMuxPath);
            if(l_muxTarget == nullptr)
            {
                TRACFCOMP( g_trac_eeprom,
                          "buildEepromRecordHeader() Mux target associated with target 0x%.08X resolved to a nullptr , check attribute for eepromType %d. Skipping Cache",
                          TARGETING::get_huid(i_target),
                          io_eepromInfo.eepromRole);
                /*@
                * @errortype
                * @moduleid     EEPROM_CACHE_EEPROM
                * @reasoncode   EEPROM_I2C_MUX_PATH_ERROR
                * @userdata1    HUID of target we want to cache
                * @userdata2    Type of EEPROM we are caching
                * @devdesc      buildEepromRecordHeader invalid mux target
                */
                l_errl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                EEPROM_CACHE_EEPROM,
                                EEPROM_I2C_MUX_PATH_ERROR,
                                TARGETING::get_huid(i_target),
                                io_eepromInfo.eepromRole,
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                l_errl->collectTrace(EEPROM_COMP_NAME);
                break;
            }
        }

        // This is what we will compare w/ when we are going through the existing
        // caches in the eeprom to see if we have already cached something
        // Or if no matches are found we will copy this into the header
        o_eepromRecordHeader.completeRecord.accessType = io_eepromInfo.accessMethod;
        o_eepromRecordHeader.completeRecord.cache_copy_size = static_cast<uint32_t>(io_eepromInfo.devSize_KB);

        // mask out top byte which contains node ID
        // eecache scope is node agnostic, so use only the non-node HUID ID
        uint32_t huid_node_mask = 0x00ffffff;

        if(io_eepromInfo.accessMethod == EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_I2C)
        {
            o_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.i2c_master_huid = l_masterTarget->getAttr<TARGETING::ATTR_HUID>() & huid_node_mask;
            o_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.port       = static_cast<uint8_t>(io_eepromInfo.accessAddr.i2c_addr.port);
            o_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.engine     = static_cast<uint8_t>(io_eepromInfo.accessAddr.i2c_addr.engine);
            o_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.devAddr    = static_cast<uint8_t>(io_eepromInfo.accessAddr.i2c_addr.devAddr);
            o_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.mux_select = static_cast<uint8_t>(io_eepromInfo.accessAddr.i2c_addr.i2cMuxBusSelector);
        }
        else
        {
            o_eepromRecordHeader.completeRecord.eepromAccess.spiAccess.spi_master_huid = l_masterTarget->getAttr<TARGETING::ATTR_HUID>() & huid_node_mask;
            o_eepromRecordHeader.completeRecord.eepromAccess.spiAccess.engine     = static_cast<uint8_t>(io_eepromInfo.accessAddr.spi_addr.engine);
            o_eepromRecordHeader.completeRecord.eepromAccess.spiAccess.offset_KB = static_cast<uint16_t>(io_eepromInfo.accessAddr.spi_addr.roleOffset_KB);
        }

        // Do not set valid bit nor internal offset here as we do not have
        // enough information available to determine
        o_eepromRecordHeader.completeRecord.internal_offset =
            UNSET_INTERNAL_OFFSET_VALUE;
        // cached_copy_valid defaults to the "unset" value when an
        // eepromRecordHeader is constructed.

        if ((io_eepromInfo.eepromRole == VPD_PRIMARY) ||
            (io_eepromInfo.eepromRole == VPD_BACKUP) ||
            (io_eepromInfo.eepromRole == VPD_AUTO))
        {
            // This record is the master record for this eeprom
            o_eepromRecordHeader.completeRecord.master_eeprom = 1;
        }
    }while(0);

    return l_errl;
}

errlHndl_t eepromPerformOpCache(DeviceFW::OperationType i_opType,
                                TARGETING::Target * i_target,
                                void *  io_buffer,
                                size_t& io_buflen,
                                eeprom_addr_t i_eepromInfo)
{
    errlHndl_t l_errl = nullptr;
    eepromRecordHeader l_eepromRecordHeader;

    do{

        TRACSSCOMP( g_trac_eeprom, ENTER_MRK"eepromPerformOpCache() "
                    "Target HUID 0x%.08X Enter", TARGETING::get_huid(i_target));

        if (i_eepromInfo.eepromRole == VPD_BACKUP)
        { // Route backup VPD operations to the primary EECACHE entry, because
          // the primary and backup VPD share the same EECACHE entry.
            i_eepromInfo.eepromRole = VPD_PRIMARY;
        }

        l_errl = buildEepromRecordHeader(i_target,
                                         i_eepromInfo,
                                         l_eepromRecordHeader);

        if(l_errl)
        {
            // buildEepromRecordHeader should have traced any relavent information if
            // it was needed, just break out and pass the error along
            break;
        }

#ifndef __HOSTBOOT_RUNTIME
        uint64_t l_eepromCacheVaddr = lookupEepromCacheAddr(l_eepromRecordHeader);
#else
        uint8_t l_instance = TARGETING::AttrRP::getNodeId(i_target);
        uint64_t l_eepromCacheVaddr = lookupEepromCacheAddr(l_eepromRecordHeader, l_instance);
#endif

        // Ensure that a copy of the eeprom exists in our map of cached eeproms
        if(l_eepromCacheVaddr)
        {
            // First check if io_buffer is a nullptr, if so then assume user is
            // requesting size back in io_bufferlen
            if(io_buffer == nullptr)
            {
                io_buflen = l_eepromRecordHeader.completeRecord.cache_copy_size * KILOBYTE;
                TRACSSCOMP( g_trac_eeprom, "eepromPerformOpCache() "
                            "io_buffer == nullptr , returning io_buflen as 0x%lx",
                            io_buflen);
                break;
            }

            TRACSSCOMP( g_trac_eeprom, "eepromPerformOpCache() "
                    "Performing %s on target 0x%.08X offset 0x%lx   length 0x%x     vaddr 0x%lx",
                    (i_opType == DeviceFW::READ) ? "READ" : "WRITE",
                    TARGETING::get_huid(i_target),
                    i_eepromInfo.offset, io_buflen, l_eepromCacheVaddr);

            // Make sure that offset + buflen are less than the total size of the eeprom
            if(i_eepromInfo.offset + io_buflen >
              (l_eepromRecordHeader.completeRecord.cache_copy_size * KILOBYTE))
            {
                TRACFCOMP(g_trac_eeprom,
                          ERR_MRK"eepromPerformOpCache: %s at offset (0x%X) + "
                          "io_buflen (0x%X) is greater than size of eeprom "
                          "(0x%x KB = 0x%X)",
                          (i_opType == DeviceFW::READ) ? "READ" : "WRITE",
                          i_eepromInfo.offset, io_buflen,
                          l_eepromRecordHeader.completeRecord.cache_copy_size,
                          l_eepromRecordHeader.completeRecord.cache_copy_size *
                          KILOBYTE );
                /*@
                * @errortype
                * @moduleid     EEPROM_CACHE_PERFORM_OP
                * @reasoncode   EEPROM_OVERFLOW_ERROR
                * @userdata1    Length of Operation
                * @userdata2    Offset we are attempting to read/write
                * @custdesc     Soft error in Firmware
                * @devdesc      cacheEeprom invalid op type
                */
                l_errl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                EEPROM_CACHE_PERFORM_OP,
                                EEPROM_OVERFLOW_ERROR,
                                TO_UINT64(io_buflen),
                                TO_UINT64(i_eepromInfo.offset),
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                ERRORLOG::ErrlUserDetailsTarget(i_target).addToLog(l_errl);
                l_errl->collectTrace( EEPROM_COMP_NAME );

                break;
            }

            if(i_opType == DeviceFW::READ)
            {
                memcpy(io_buffer,
                       reinterpret_cast<void *>(l_eepromCacheVaddr + i_eepromInfo.offset),
                       io_buflen);
            }
            else if(i_opType == DeviceFW::WRITE)
            {
                memcpy(reinterpret_cast<void *>(l_eepromCacheVaddr + i_eepromInfo.offset),
                       io_buffer,
                       io_buflen);

#ifndef __HOSTBOOT_RUNTIME
                // Perform flush to ensure pnor is updated
                int rc = mm_remove_pages( FLUSH,
                                          reinterpret_cast<void *>(l_eepromCacheVaddr + i_eepromInfo.offset),
                                          io_buflen );
                if( rc )
                {
                    TRACFCOMP(g_trac_eeprom,
                              ERR_MRK"eepromPerformOpCache:  Error from mm_remove_pages trying for flush contents write to pnor! rc=%d",
                              rc);
                    /*@
                    * @errortype
                    * @moduleid     EEPROM_CACHE_PERFORM_OP
                    * @reasoncode   EEPROM_FAILED_TO_FLUSH_CONTENTS
                    * @userdata1    Requested Address
                    * @userdata2    rc from mm_remove_pages
                    * @devdesc      cacheEeprom mm_remove_pages FLUSH failed
                    */
                    l_errl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    EEPROM_CACHE_PERFORM_OP,
                                    EEPROM_FAILED_TO_FLUSH_CONTENTS,
                                    (l_eepromCacheVaddr + i_eepromInfo.offset),
                                    TO_UINT64(rc),
                                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                    l_errl->collectTrace( EEPROM_COMP_NAME );
                }
#endif
            }
            else
            {
                TRACFCOMP(g_trac_eeprom,
                          ERR_MRK"eepromPerformOpCache: Invalid OP_TYPE passed to function, i_opType=%d",
                          i_opType);
                /*@
                * @errortype
                * @moduleid     EEPROM_CACHE_PERFORM_OP
                * @reasoncode   EEPROM_INVALID_OPERATION
                * @userdata1[0:31]  Op Type that was invalid
                * @userdata1[32:63] Eeprom Role
                * @userdata2    Offset we are attempting to perfrom op on
                * @custdesc     Soft error in Firmware
                * @devdesc      cacheEeprom invalid op type
                */
                l_errl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                EEPROM_CACHE_PERFORM_OP,
                                EEPROM_INVALID_OPERATION,
                                TWO_UINT32_TO_UINT64(i_opType,
                                                     i_eepromInfo.eepromRole),
                                TO_UINT64(i_eepromInfo.offset),
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                ERRORLOG::ErrlUserDetailsTarget(i_target).addToLog(l_errl);
                l_errl->collectTrace( EEPROM_COMP_NAME );
            }
        }
        else
        {
            TRACFCOMP( g_trac_eeprom,"eepromPerformOpCache: Failed to find entry in cache for 0x%.08X, %s failed",
                       TARGETING::get_huid(i_target),
                       (i_opType == DeviceFW::READ) ? "READ" : "WRITE");
            /*@
            * @errortype
            * @moduleid     EEPROM_CACHE_PERFORM_OP
            * @reasoncode   EEPROM_NOT_IN_CACHE
            * @userdata1[0:31]  Op Type
            * @userdata1[32:63] Eeprom Role
            * @userdata2    Offset we are attempting to read/write
            * @custdesc     Soft error in Firmware
            * @devdesc      Tried to lookup eeprom not in cache
            */
            l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            EEPROM_CACHE_PERFORM_OP,
                            EEPROM_NOT_IN_CACHE,
                            TWO_UINT32_TO_UINT64(i_opType,
                                                 i_eepromInfo.eepromRole),
                            TO_UINT64(i_eepromInfo.offset),
                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            ERRORLOG::ErrlUserDetailsTarget(i_target).addToLog(l_errl);
            l_errl->collectTrace( EEPROM_COMP_NAME );
        }

        TRACSSCOMP( g_trac_eeprom, EXIT_MRK"eepromPerformOpCache() "
                    "Target HUID 0x%.08X Exit", TARGETING::get_huid(i_target));

    }while(0);

    return l_errl;
}
}
