/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/i2cTargetPres.C $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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

#include <devicefw/driverif.H>
#include <fsi/fsiif.H>
#include <vpd/vpd_if.H>
#include <i2c/i2cif.H>
#include <i2c/i2creasoncodes.H>
#include <i2c/eepromif.H>
#include <initservice/initserviceif.H>
#include <errl/errlmanager.H>
#include "i2c_common.H"
#include <vpd/spdenums.H>
#include <fapiwrap/fapiWrapif.H>

extern trace_desc_t* g_trac_i2c;

//#define TRACSSCOMP(args...)  TRACFCOMP(args)
#define TRACSSCOMP(args...)

namespace I2C
{

/**
 * @brief Performs a presence detect operation on a Target that has the
 *        ATTR_FAPI_I2C_CONTROL_INFO and can be detected via that device
 *
 *        Currently used to detect I2C_MUTEX and OCMB_CHIP targets
 *
 * @param[in]   i_target     Presence detect target
 * @param[in]   i_buflen     lengh of operation requested
 * @param[in]   o_present    Present = 1, NOT Present = 0
 * @
 * @return  errlHndl_t
 */
errlHndl_t genericI2CTargetPresenceDetect(TARGETING::Target* i_target,
                                          size_t i_buflen,
                                          bool & o_present)
{
    errlHndl_t l_errl = nullptr;
    bool l_target_present = false;
    bool l_i2cMaster_exists = false;
    TARGETING::Target * l_i2cMasterTarget = nullptr;
    TARGETING::Target* l_masterProcTarget = nullptr;
    TARGETING::ATTR_FAPI_I2C_CONTROL_INFO_type l_i2cInfo;

    TRACSSCOMP( g_trac_i2c, ENTER_MRK"genericI2CTargetPresenceDetect() "
                "Target HUID 0x%.08X ENTER", TARGETING::get_huid(i_target));

    do{
        if (unlikely(i_buflen != sizeof(bool)))
        {
            TRACFCOMP(g_trac_i2c,
                      ERR_MRK "I2C::ddimmPresenceDetect> Invalid data length: %d",
                      i_buflen);
            /*@
            * @errortype
            * @moduleid     I2C::I2C_GENERIC_PRES_DETECT
            * @reasoncode   I2C::I2C_INVALID_LENGTH
            * @userdata1    Data Length
            * @userdata2    HUID of target being detected
            * @devdesc      ddimmPresenceDetect> Invalid data length (!= 1 bytes)
            * @custdesc     Firmware error during boot
            */
            l_errl =
                    new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            I2C::I2C_GENERIC_PRES_DETECT,
                                            I2C::I2C_INVALID_LENGTH,
                                            TO_UINT64(i_buflen),
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

        // if the i2c master listed doesn't exist then bail out -- this target is not present
        if(!l_i2cMaster_exists)
        {
            TRACFCOMP(g_trac_i2c,
                      ERR_MRK"I2C::genericI2CTargetPresenceDetect> I2C Master in FAPI_I2C_CONTROL_INFO for Target 0x.08%X does not exist, target not present",
                      TARGETING::get_huid(i_target));

            /*@
            * @errortype
            * @moduleid     I2C::I2C_GENERIC_PRES_DETECT
            * @reasoncode   VPD::VPD_INVALID_MASTER_I2C_PATH
            * @userdata1    HUID of target being detected
            * @userdata2    Unused
            * @devdesc      ocmbPresenceDetect> Invalid master i2c path
            * @custdesc     Firmware error during boot
            */
            l_errl =
                    new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            I2C::I2C_GENERIC_PRES_DETECT,
                                            I2C::INVALID_MASTER_TARGET,
                                            TARGETING::get_huid(i_target),
                                            0,
                                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            break;
        }

        // if we think it exists then lookup the master path with the target service
        l_i2cMasterTarget = l_targetService.toTarget(l_i2cInfo.i2cMasterPath);

        // if target service returns a null ptr for the path something is wrong and we should
        // mark the target not present
        if(l_i2cMasterTarget == nullptr)
        {
            TRACFCOMP(g_trac_i2c,
                      ERR_MRK"I2C::genericI2CTargetPresenceDetect> I2C Master in FAPI_I2C_CONTROL_INFO for Target 0x.08%X returned a nullptr, target not present",
                      TARGETING::get_huid(i_target));

            /*@
            * @errortype
            * @moduleid     I2C::I2C_GENERIC_PRES_DETECT
            * @reasoncode   I2C::I2C_NULL_MASTER_TARGET
            * @userdata1    HUID of target being detected
            * @userdata2    Unused
            * @devdesc      ocmbPresenceDetect> Master i2c path returned nullptr
            * @custdesc     Firmware error during boot
            */
            l_errl =
                    new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            I2C::I2C_GENERIC_PRES_DETECT,
                                            I2C::I2C_NULL_MASTER_TARGET,
                                            TARGETING::get_huid(i_target),
                                            0,
                                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            break;
        }

        TRACSSCOMP( g_trac_i2c, "I2C::genericI2CTargetPresenceDetect> i2c master for target 0x%.08X is HUID 0x%.08X",
                    TARGETING::get_huid(i_target),  TARGETING::get_huid(l_i2cMasterTarget));

        // Master proc is taken as always present. Validate other targets.
        TARGETING::targetService().masterProcChipTargetHandle(l_masterProcTarget );

        if (l_i2cMasterTarget != l_masterProcTarget)
        {
            // Use the FSI slave presence detection to see if master i2c can be found
            if( ! FSI::isSlavePresent(l_i2cMasterTarget) )
            {
                TRACFCOMP( g_trac_i2c,
                           ERR_MRK"genericI2CTargetPresenceDetect> isSlavePresent returned false for I2C Master Target %.08X",
                           TARGETING::get_huid(l_i2cMasterTarget));
                break;
            }
        }

        //***********************************************************************************
        //* If we make it through all of the checks then we have verified master is present *
        //***********************************************************************************

        // If the target has dynamic device address attribute, then use that instead of the
        // read-only address found in ATTR_FAPI_I2C_CONTROL_INFO. We use the dynamic address
        // attribute because ATTR_FAPI_I2C_CONTROL_INFO is not writable and its difficult
        // to override complex attributes.
        if(i_target->tryGetAttr<TARGETING::ATTR_DYNAMIC_I2C_DEVICE_ADDRESS>(l_i2cInfo.devAddr))
        {
            TRACDCOMP(g_trac_i2c,
                     "Using DYNAMIC_I2C_DEVICE_ADDRESS %.2x for HUID %.8x",
                      l_i2cInfo.devAddr,
                      TARGETING::get_huid(i_target));
        }

        //Check for the target at the I2C level
        l_target_present = I2C::i2cPresence(l_i2cMasterTarget,
                                            l_i2cInfo.port,
                                            l_i2cInfo.engine,
                                            l_i2cInfo.devAddr,
                                            l_i2cInfo.i2cMuxBusSelector,
                                            l_i2cInfo.i2cMuxPath );
    }while(0);

    o_present = l_target_present;

    TRACSSCOMP( g_trac_i2c, EXIT_MRK"genericI2CTargetPresenceDetect() "
            "Target HUID 0x%.08X found to be %s present EXIT", TARGETING::get_huid(i_target), o_present ? "" : "NOT" );

    return l_errl;
}

/**
 * @brief Performs a presence detect operation on a OCMB Target
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
errlHndl_t ocmbI2CPresencePerformOp(DeviceFW::OperationType i_opType,
                                    TARGETING::Target* i_target,
                                    void* io_buffer,
                                    size_t& io_buflen,
                                    int64_t i_accessType,
                                    va_list i_args)
{
    errlHndl_t l_invalidateErrl = nullptr;

    // TODO RTC 213602
    // Enable once presence detection is supported
    //bool l_ocmbPresent = EEPROM::eepromPresence(i_target);
    bool l_ocmbPresent = true;

    memcpy(io_buffer, &l_ocmbPresent, sizeof(l_ocmbPresent));
    io_buflen = sizeof(l_ocmbPresent);

    return l_invalidateErrl;
}

/**
 * @brief Performs a presence detect operation on a PMIC Target
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
errlHndl_t pmicI2CPresencePerformOp(DeviceFW::OperationType i_opType,
                                    TARGETING::Target* i_target,
                                    void* io_buffer,
                                    size_t& io_buflen,
                                    int64_t i_accessType,
                                    va_list i_args)
{

    errlHndl_t l_errl = nullptr;
    bool l_pmicPresent = 0;
    TARGETING::Target* l_parentOcmb = TARGETING::getImmediateParentByAffinity(i_target);

    uint8_t l_spdBlob[SPD::DDIMM_DDR4_SPD_SIZE];
    size_t l_spdSize = SPD::DDIMM_DDR4_SPD_SIZE;

    do{

        l_errl = deviceRead(l_parentOcmb,
                            l_spdBlob,
                            l_spdSize,
                            DEVICE_SPD_ADDRESS(SPD::ENTIRE_SPD_WITHOUT_EFD));

        if(l_errl)
        {
            TRACFCOMP( g_trac_i2c, ERR_MRK"pmicI2CPresencePerformOp() "
                        "Error reading SPD associated with PMIC 0x%.08X, failed to determine presence",
                        TARGETING::get_huid(i_target));
            break;
        }

        TARGETING::ATTR_REL_POS_type l_relPos = i_target->getAttr<TARGETING::ATTR_REL_POS>();

        // PMICs will have a different device address depending on the vendor.
        // Prior to doing present detection on a pmic we must first query the
        // device address from the parent OCMB's SPD
        uint8_t l_devAddr = FAPIWRAP::get_pmic_dev_addr(reinterpret_cast<char *>(l_spdBlob),
                                                      l_relPos);

        assert(l_devAddr != 0,
              "Found devAddr for PMIC 0x%.08x to be 0, this cannot be. Check SPD and REL_POS on target",
              TARGETING::get_huid(i_target));

        i_target->setAttr<TARGETING::ATTR_DYNAMIC_I2C_DEVICE_ADDRESS>(l_devAddr);

        l_errl = genericI2CTargetPresenceDetect(i_target,
                                                io_buflen,
                                                l_pmicPresent);

        if (l_errl)
        {
            TRACFCOMP( g_trac_i2c, ERR_MRK"pmicI2CPresencePerformOp() "
                        "Error detecting target 0x%.08X, io_buffer will not be set",
                        TARGETING::get_huid(i_target));
            break;
        }

        // Copy variable describing if target is present or not to i/o buffer param
        memcpy(io_buffer, &l_pmicPresent, sizeof(l_pmicPresent));
        io_buflen = sizeof(l_pmicPresent);

    }while(0);

    return l_errl;
}

/**
 * @brief Performs a presence detect operation on a Mux Target that has the
 *        ATTR_FAPI_I2C_CONTROL_INFO and can be detected via that device
 *
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
errlHndl_t muxI2CPresencePerformOp(DeviceFW::OperationType i_opType,
                                     TARGETING::Target* i_target,
                                     void* io_buffer,
                                     size_t& io_buflen,
                                     int64_t i_accessType,
                                     va_list i_args)
{
    bool l_muxPresent = 0;
    errlHndl_t l_errl = nullptr;

    // TODO RTC 213602
    // Enable once presence detection is supported
    //l_errl = genericI2CTargetPresenceDetect(i_target,
    //                                                 io_buflen,
    //                                                 l_muxPresent);
    l_muxPresent = true;


    if (l_errl)
    {
        TRACFCOMP( g_trac_i2c, ERR_MRK"basicI2CTargetPresenceDetect() "
                    "Error detecting target 0x%.08X, io_buffer will not be set",
                    TARGETING::get_huid(i_target));
    }
    else
    {
        // Copy variable describing if target is present or not to i/o buffer param
        memcpy(io_buffer, &l_muxPresent, sizeof(l_muxPresent));
        io_buflen = sizeof(l_muxPresent);
    }

    return l_errl;
}

// Register the ocmb presence detect function with the device framework
DEVICE_REGISTER_ROUTE(DeviceFW::READ,
                      DeviceFW::PRESENT,
                      TARGETING::TYPE_OCMB_CHIP,
                      ocmbI2CPresencePerformOp);

// Register the i2c mux presence detect function with the device framework
DEVICE_REGISTER_ROUTE( DeviceFW::READ,
                       DeviceFW::PRESENT,
                       TARGETING::TYPE_I2C_MUX,
                       muxI2CPresencePerformOp );

// Register the pmic vrm presence detect function with the device framework
DEVICE_REGISTER_ROUTE( DeviceFW::READ,
                       DeviceFW::PRESENT,
                       TARGETING::TYPE_PMIC,
                       pmicI2CPresencePerformOp );

}
