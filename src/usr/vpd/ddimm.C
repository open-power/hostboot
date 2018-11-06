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

#include <devicefw/driverif.H>
#include <targeting/common/attributes.H>
#include <vpd/vpd_if.H>
#include <errl/errlmanager.H>
#include <hwas/common/hwasCallout.H>
#include <targeting/common/predicates/predicatectm.H>
#include <config.h>
#include <initservice/initserviceif.H>
#include <vpd/vpdreasoncodes.H>
#include "spd.H"
#include <chipids.H>

extern trace_desc_t* g_trac_vpd;


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

    if (unlikely(io_buflen < sizeof(bool)))
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
        io_buflen = 0;
        return l_errl;
    }

//@TODO-RTC:196805-Add real implementation
bool l_ocmbvpd_present = true; //default to everything present for now
//-------------------------------------------------------------------
#if 0

    // First, make sure that the i2c master exists or we can't read
    //  our vpd
#ifdef CONFIG_MEMVPD_READ_FROM_HW
    // look up i2cMasterPath from EEPROM_VPD_PRIMARY_INFO
    // check if that target exists directly via FSI
    bool l_check_for_vpd = isSlavePresent(i2cMasterTarget);

#else
    // just default to yes for PNOR-based VPD
    bool l_check_for_vpd = true;
#endif

    // Next, probe the VPD contents to see if we have anything
    bool l_ocmbvpd_present = ...;
#endif


#if defined(CONFIG_MEMVPD_READ_FROM_HW) && defined(CONFIG_MEMVPD_READ_FROM_PNOR)
    if( l_ocmbvpd_present )
    {
        // Check if the VPD data in the PNOR matches the SEEPROM
        l_errl = VPD::ensureCacheIsInSync( i_target );
        if( l_errl )
        {
            // Save this plid to use later
            //l_saved_plid = l_errl->plid();
            l_ocmbvpd_present = false;

            TRACFCOMP(g_trac_vpd,ERR_MRK "VPD::ocmbPresenceDetect> Error during ensureCacheIsInSync (DDIMM)" );
            errlCommit( l_errl, VPD_COMP_ID );
        }
    }
    else
    {
        // Defer invalidating DDIMM VPD in the PNOR in case another target
        // might be sharing this VPD_REC_NUM. Check all targets sharing this
        // VPD_REC_NUM after target discovery in VPD::validateSharedPnorCache.
        // Ensure the VPD_SWITCHES cache valid bit is invalid at this point.
        TARGETING::ATTR_VPD_SWITCHES_type vpdSwitches =
        i_target->getAttr<TARGETING::ATTR_VPD_SWITCHES>();
        vpdSwitches.pnorCacheValid = 0;
        i_target->setAttr<TARGETING::ATTR_VPD_SWITCHES>( vpdSwitches );
    }
#endif

//-------------------------------------------------------------------

    if( l_ocmbvpd_present )
    {
        //Fsp sets PN/SN so if there is none, do it here
        if(!INITSERVICE::spBaseServicesEnabled())
        {
            // set part and serial number attributes for current target
            SPD::setPartAndSerialNumberAttributes( i_target );
        }

    }
    memcpy(io_buffer, &l_ocmbvpd_present, sizeof(l_ocmbvpd_present));
    io_buflen = sizeof(l_ocmbvpd_present);

    return nullptr;
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
