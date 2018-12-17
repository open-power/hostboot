/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/ddimm.C $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
 * Provides functionality related to the DDIMM package
 */


#include <targeting/common/attributes.H>
#include <targeting/common/predicates/predicatectm.H>
#include <devicefw/driverif.H>
#include <fsi/fsiif.H>
#include <i2c/i2cif.H>
#include <initservice/initserviceif.H>
#include <vpd/vpd_if.H>
#include <vpd/vpdreasoncodes.H>
#include <errl/errlmanager.H>
#include <hwas/common/hwasCallout.H>
#include <config.h>
#include "spd.H"
#include <chipids.H>

extern trace_desc_t* g_trac_vpd;

//#define TRACSSCOMP(args...)  TRACFCOMP(args)
#define TRACSSCOMP(args...)

namespace VPD
{

#ifndef __HOSTBOOT_RUNTIME  // No presence detection in HBRT

/**
 * @brief Performs a presence detect operation on a OCMB Chip.
 *
 * There is no way to access the OCMB until later in the IPL so we will
 *  use the existence of VPD as the only indication..
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        Presence detect target
 * @param[in/out] io_buffer     Read: Pointer to output data storage
 *                              Write: Pointer to input data storage
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes, always 1)
 *                              Output: Success = 1, Failure = 0
 * @param[in]   i_accessType    DeviceFW::AccessType enum (userif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, there are no arguments.
 * @return  errlHndl_t
 */
errlHndl_t ocmbPresenceDetect(DeviceFW::OperationType i_opType,
                              TARGETING::Target* i_target,
                              void* io_buffer,
                              size_t& io_buflen,
                              int64_t i_accessType,
                              va_list i_args)
{
    errlHndl_t l_errl = nullptr;
    bool l_ocmb_present = false;
    bool l_i2cMaster_exists = false;
    TARGETING::Target * l_i2cMasterTarget = nullptr;
    TARGETING::Target* l_masterProcTarget = nullptr;
    TARGETING::ATTR_FAPI_I2C_CONTROL_INFO_type l_i2cInfo;
    uint32_t l_commonPlid = 0;

    TRACSSCOMP( g_trac_vpd, ENTER_MRK"ocmbPresenceDetect() "
                "OCMB HUID 0x%.08X ENTER", TARGETING::get_huid(i_target));

    do{

        if (unlikely(io_buflen != sizeof(bool)))
        {
            TRACFCOMP(g_trac_vpd,
                      ERR_MRK "VPD::ocmbPresenceDetect> Invalid data length: %d",
                      io_buflen);
            /*@
            * @errortype
            * @moduleid     VPD::MOD_OCMBPRESENCEDETECT
            * @reasoncode   VPD::VPD_INVALID_LENGTH
            * @userdata1    Data Length
            * @userdata2    HUID of target being detected
            * @devdesc      ocmbPresenceDetect> Invalid data length (!= 1 bytes)
            * @custdesc     Firmware error during boot
            */
            l_errl =
                    new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            VPD::MOD_OCMBPRESENCEDETECT,
                                            VPD::VPD_INVALID_LENGTH,
                                            TO_UINT64(io_buflen),
                                            TARGETING::get_huid(i_target),
                                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
        }

        // Get a ptr to the target service which we will use later on
        TARGETING::TargetService& l_targetService = TARGETING::targetService();

        // Read Attributes needed to complete the operation
        l_i2cInfo = i_target->getAttr<TARGETING::ATTR_FAPI_I2C_CONTROL_INFO>();

        // Check if the target set as the i2cMasterPath actually exists
        l_targetService.exists(l_i2cInfo.i2cMasterPath, l_i2cMaster_exists);

        // if the i2c master listed doesn't exist then bail out -- this OCMB is not present
        if(!l_i2cMaster_exists)
        {
            TRACFCOMP(g_trac_vpd,
                      ERR_MRK"VPD::ocmbPresenceDetect> I2C Master in FAPI_I2C_CONTROL_INFO for OCMB 0x.08%X does not exist, target not present",
                      TARGETING::get_huid(i_target));

            /*@
            * @errortype
            * @moduleid     VPD::MOD_OCMBPRESENCEDETECT
            * @reasoncode   VPD::VPD_INVALID_MASTER_I2C_PATH
            * @userdata1    HUID of target being detected
            * @userdata2    Unused
            * @devdesc      ocmbPresenceDetect> Invalid master i2c path
            * @custdesc     Firmware error during boot
            */
            l_errl =
                    new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            VPD::MOD_OCMBPRESENCEDETECT,
                                            VPD::VPD_INVALID_MASTER_I2C_PATH,
                                            TARGETING::get_huid(i_target),
                                            0,
                                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            break;
        }

        // if we think it exists then lookup the master path with the target service
        l_i2cMasterTarget = l_targetService.toTarget(l_i2cInfo.i2cMasterPath);

        // if target service returns a null ptr for the path something is wrong and we should
        // mark the OCMB not present
        if(l_i2cMasterTarget == nullptr)
        {
            TRACFCOMP(g_trac_vpd,
                      ERR_MRK"VPD::ocmbPresenceDetect> I2C Master in FAPI_I2C_CONTROL_INFO for OCMB 0x.08%X returned a nullptr, target not present",
                      TARGETING::get_huid(i_target));

            /*@
            * @errortype
            * @moduleid     VPD::MOD_OCMBPRESENCEDETECT
            * @reasoncode   VPD::VPD_NULL_I2C_MASTER
            * @userdata1    HUID of target being detected
            * @userdata2    Unused
            * @devdesc      ocmbPresenceDetect> Master i2c path returned nullptr
            * @custdesc     Firmware error during boot
            */
            l_errl =
                    new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            VPD::MOD_OCMBPRESENCEDETECT,
                                            VPD::VPD_NULL_I2C_MASTER,
                                            TARGETING::get_huid(i_target),
                                            0,
                                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            break;
        }

        TRACSSCOMP( g_trac_vpd, "VPD::ocmbPresenceDetect> i2c master for OCMB 0x%.08X is HUID 0x%.08X",
                    TARGETING::get_huid(i_target),  TARGETING::get_huid(l_i2cMasterTarget));

        // Master proc is taken as always present. Validate other targets.
        TARGETING::targetService().masterProcChipTargetHandle(l_masterProcTarget );

        if (l_i2cMasterTarget != l_masterProcTarget)
        {
            // Use the FSI slave presence detection to see if master i2c can be found
            if( ! FSI::isSlavePresent(l_i2cMasterTarget) )
            {
                TRACFCOMP( g_trac_vpd,
                           ERR_MRK"ocmbPresenceDetect> isSlavePresent returned false for I2C Master Target 0x%.08X. "
                           "This implies 0x%.08X is also NOT present",
                           TARGETING::get_huid(l_i2cMasterTarget), TARGETING::get_huid(i_target));
                break;
            }
        }

        //***********************************************************************************
        //* If we make it through all of the checks then we have verified master is present *
        //***********************************************************************************

        //Check for the target at the I2C level
        l_ocmb_present = I2C::i2cPresence(l_i2cMasterTarget,
                                            l_i2cInfo.port,
                                            l_i2cInfo.engine,
                                            l_i2cInfo.devAddr );

        if(l_ocmb_present )
        {
#if defined(CONFIG_MEMVPD_READ_FROM_HW) && defined(CONFIG_MEMVPD_READ_FROM_PNOR)
            // Check if the VPD data in the PNOR matches the SEEPROM
            l_errl = VPD::ensureCacheIsInSync( i_target );
            if( l_errl )
            {
                // Save this plid to use later
                l_commonPlid = l_errl->plid();
                l_ocmb_present = false;

                TRACFCOMP(g_trac_vpd,ERR_MRK "VPD::ocmbPresenceDetect> Error during ensureCacheIsInSync (DDIMM)" );
                errlCommit( l_errl, VPD_COMP_ID );
                l_errl = nullptr;
            }
#endif
            //Fsp sets PN/SN so if there is none, do it here
            if(!INITSERVICE::spBaseServicesEnabled())
            {
                // set part and serial number attributes for current target
                SPD::setPartAndSerialNumberAttributes( i_target );
            }
        }
        else
        {
            TRACFCOMP(g_trac_vpd,
                      ERR_MRK"VPD::ocmbPresenceDetect> i2cPresence returned false! OCMB chip 0x%.08X is NOT Present!",
                      TARGETING::get_huid(i_target));
        }
    }while(0);

    if(!l_ocmb_present)
    {
        // Invalidate the SPD in PNOR
        l_errl = VPD::invalidatePnorCache(i_target);
        if (l_errl)
        {
            // Link the logs if there was an existing log
            if(l_commonPlid)
            {
                l_errl->plid(l_commonPlid);
            }

            TRACFCOMP( g_trac_vpd, ERR_MRK"dimmPresenceDetect() "
                       "Error invalidating SPD in PNOR for target 0x%.08X",
                       TARGETING::get_huid(i_target));
        }
    }

    // Copy variable describing if ocmb is present or not to i/o buffer param
    memcpy(io_buffer, &l_ocmb_present, sizeof(l_ocmb_present));
    io_buflen = sizeof(l_ocmb_present);

    TRACSSCOMP( g_trac_vpd, EXIT_MRK"ocmbPresenceDetect() "
            "OCMB HUID 0x%.08X EXIT", TARGETING::get_huid(i_target));

    return l_errl;
}

// Register the presence detect function with the device framework
DEVICE_REGISTER_ROUTE(DeviceFW::READ,
                      DeviceFW::PRESENT,
                      TARGETING::TYPE_OCMB_CHIP,
                      ocmbPresenceDetect);


//@fixme - RTC:201996 - Collect IDEC later in the boot
errlHndl_t ocmbIDEC(DeviceFW::OperationType i_opType,
                    TARGETING::Target* i_target,
                    void* io_buffer,
                    size_t& io_buflen,
                    int64_t i_accessType,
                    va_list i_args)
{
    // for now just hardcode the answer to something explicitly invalid
    uint8_t l_ec = INVALID__ATTR_EC;
    i_target->setAttr<TARGETING::ATTR_EC>(l_ec);
    i_target->setAttr<TARGETING::ATTR_HDAT_EC>(l_ec);

    // we can assume this is an Explorer chip though
    uint32_t l_id = POWER_CHIPID::EXPLORER_16;
    i_target->setAttr<TARGETING::ATTR_CHIP_ID>(l_id);

    return nullptr;
}

// Register the presence detect function with the device framework
DEVICE_REGISTER_ROUTE(DeviceFW::WRITE,
                      DeviceFW::IDEC,
                      TARGETING::TYPE_OCMB_CHIP,
                      ocmbIDEC);


#endif // !__HOSTBOOT_RUNTIME


//Other DDIMM functions go here


}; //namespace VPD
