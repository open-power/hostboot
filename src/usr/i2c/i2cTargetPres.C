/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/i2cTargetPres.C $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2023                        */
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
#include <eeprom/eepromif.H>
#include <initservice/initserviceif.H>
#include <errl/errlmanager.H>
#include <i2c/i2c_common.H>
#include <vpd/spdenums.H>
#include <fapiwrap/fapiWrapif.H>
#include "../eeprom/eepromCache.H"
#include <attributeenums.H>
#include <plat_hwp_invoker.H>
#include <dt_trim_read_restart_ddr5.H>

extern trace_desc_t* g_trac_i2c;

//#define TRACSSCOMP(args...)  TRACFCOMP(args)
#define TRACSSCOMP(args...)

namespace I2C
{

/**
 * @brief Performs a presence detect operation on a Target that has the
 *        ATTR_FAPI_I2C_CONTROL_INFO and can be detected via that device
 *
 *        Currently used to detect I2C_MUTEX, OCMB_CHIP, PMIC, and
 *        Generic I2C Device targets (like DDIMM ADC and GPIO Expander targets)
 *
 * @param[in]   i_target     Presence detect target
 * @param[in]   o_present    Present = 1, NOT Present (and/or error) = 0
 *
 * @return  errlHndl_t
 */
errlHndl_t genericI2CTargetPresenceDetect(TARGETING::Target* i_target,
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

        TRACSSCOMP(g_trac_i2c, "I2C::genericI2CTargetPresenceDetect> target 0x%.08X: "
                   "checking i2cm 0x%.08X, e%d/p%d/devAddr=0x%.2X",
                   TARGETING::get_huid(i_target),  TARGETING::get_huid(l_i2cMasterTarget),
                   l_i2cInfo.engine, l_i2cInfo.port, l_i2cInfo.devAddr);

        // The GPIO devices and POWER_ICs require an I2C read of 1 byte for their prsesence detection
        TARGETING::ATTR_I2C_DEV_TYPE_type l_i2c_dev_type = TARGETING::I2C_DEV_TYPE_INVALID;
        if (((i_target->tryGetAttr<TARGETING::ATTR_I2C_DEV_TYPE>(l_i2c_dev_type)) &&
            (l_i2c_dev_type == TARGETING::I2C_DEV_TYPE_PCA9554A_GPIO_EXPANDER))
            ||
            (i_target->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_POWER_IC))
        {
            uint8_t l_data;
            size_t  l_size=sizeof(l_data);
            uint8_t l_offset=0;
            size_t  l_offset_length=sizeof(l_offset);

            // Use a known good address offset for POWER_IC devices. A HWP later
            // writes to this addr.
            if(i_target->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_POWER_IC)
            {
                l_offset = 0xD4; // DT_REGS::FAULTS_CLEAR_0
            }

            TRACSSCOMP(g_trac_i2c, "I2C::genericI2CTargetPresenceDetect> trying 1-byte I2C read "
                       "for HUID 0x%.08X i2cm=0x%.08X, e%d/p%d/devAddr=0x%X, offset=%d, "
                       "offset_length=%d",
                       get_huid(i_target), get_huid(l_i2cMasterTarget), l_i2cInfo.engine,
                       l_i2cInfo.port, l_i2cInfo.devAddr, l_offset, l_offset_length);

            l_errl = deviceOp( DeviceFW::READ,
                              l_i2cMasterTarget,
                              &l_data,
                              l_size,
                              DEVICE_I2C_ADDRESS_OFFSET(
                                            l_i2cInfo.port,
                                            l_i2cInfo.engine,
                                            l_i2cInfo.devAddr,
                                            l_offset_length,
                                            &l_offset,
                                            l_i2cInfo.i2cMuxBusSelector,
                                            &(l_i2cInfo.i2cMuxPath) ) );

            if( l_errl )
            {
                TRACSSCOMP(g_trac_i2c,ERR_MRK"I2C::genericI2CTargetPresenceDetect> Failed for HUID 0x%.08X "
                          "- Deleting error: "
                          TRACE_ERR_FMT,
                          get_huid(i_target),
                          TRACE_ERR_ARGS(l_errl));
                          delete l_errl;
                          l_errl = nullptr;
            }
            else
            {
                TRACSSCOMP(g_trac_i2c,INFO_MRK"I2C::genericI2CTargetPresenceDetect> Success for HUID 0x%.08X", get_huid(i_target));
                l_target_present = true;
            }
        }

        // The PMICs and ADCs can use the i2cPresence() function
        else
        {
            l_target_present = I2C::i2cPresence(l_i2cMasterTarget,
                                                l_i2cInfo.port,
                                                l_i2cInfo.engine,
                                                l_i2cInfo.devAddr,
                                                l_i2cInfo.i2cMuxBusSelector,
                                                l_i2cInfo.i2cMuxPath );
        }
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
    errlHndl_t l_errl = nullptr;
    bool l_ocmbPresent = true;

#if( defined(CONFIG_SUPPORT_EEPROM_CACHING) && !defined(CONFIG_SUPPORT_EEPROM_HWACCESS) )
    l_errl = EEPROM::eecachePresenceDetect(i_target, l_ocmbPresent);
    if(l_errl)
    {
        TRACFCOMP(g_trac_i2c, "ocmbI2CPresencePerformOp: could not presence-"
                  "detect target HUID 0x%08X against the existing EECACHE",
                  TARGETING::get_huid(i_target));
        l_ocmbPresent = false;
        errlCommit(l_errl, I2C_COMP_ID);
    }
#else
    // Planar OCMBs don't have their own EEPROMs, since they are soldered on the
    //  board we can assume they are present
    if( i_target->getAttr<TARGETING::ATTR_MEM_MRW_IS_PLANAR>() )
    {
        l_ocmbPresent = true;
    }
    else
    {
        l_ocmbPresent = EEPROM::eepromPresence(i_target);
    }
#endif

    memcpy(io_buffer, &l_ocmbPresent, sizeof(l_ocmbPresent));
    io_buflen = sizeof(l_ocmbPresent);

    return l_errl;
}

/**
 * @brief Performs a presence detect operation on a Target in a DDIMM
 *        that has a dynamic i2c address.  This includes :
 *        PMIC, GENERIC_I2C_DEVICE, POWER_IC
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
errlHndl_t ddimmDynamicI2CPresence(DeviceFW::OperationType i_opType,
                                   TARGETING::Target* i_target,
                                   void* io_buffer,
                                   size_t& io_buflen,
                                   int64_t i_accessType,
                                   va_list i_args)
{
    assert(1 == io_buflen, "ddimmDynamicI2CPresence(): Expected buffer length (io_buflen) to be 1, received %d", io_buflen);
    assert(nullptr != io_buffer, "ddimmDynamicI2CPresence(): Expected a non-null io_buffer");

    errlHndl_t l_errl = nullptr;
    bool l_devPresent = false;
    uint8_t l_devAddr = 0;

    do{
        TARGETING::Target* l_parentOcmb = TARGETING::getImmediateParentByAffinity(i_target);
        auto l_parentHwasState = l_parentOcmb->getAttr<TARGETING::ATTR_HWAS_STATE>();
        auto l_devType = i_target->getAttr<TARGETING::ATTR_TYPE>();

        if(! l_parentHwasState.present)
        {
            // If the parent chip is not present, then neither is the pmic
            // so just break out and return not present
            break;
        }

        TARGETING::ATTR_REL_POS_type l_relPos
          = i_target->getAttr<TARGETING::ATTR_REL_POS>();

        // This device has a different device address depending on the vendor.
        // Prior to doing present detection on these parts we must first query
        // the device address from the parent OCMB's SPD
        if( TARGETING::TYPE_PMIC == l_devType )
        {
            l_errl = FAPIWRAP::get_pmic_dev_addr(l_parentOcmb,
                                                 l_relPos,
                                                 l_devAddr);
        }
        else if( TARGETING::TYPE_GENERIC_I2C_DEVICE == l_devType )
        {
            l_errl = FAPIWRAP::get_gpio_adc_dev_addr(l_parentOcmb,
                                                     l_relPos,
                                                     l_devAddr);
        }
        else if( TARGETING::TYPE_POWER_IC == l_devType )
        {
            l_errl = FAPIWRAP::get_poweric_dev_addr(l_parentOcmb,
                                                    l_relPos,
                                                    l_devAddr);
        }
        else
        {
            assert(0,"ddimmDynamicI2CPresence - Invalid type %d for device %.8X",
                   l_devType,
                   TARGETING::get_huid(i_target));
        }
        if (l_errl)
        {
            TRACFCOMP( g_trac_i2c, ERR_MRK"ddimmDynamicI2CPresence() "
                        "Error attempting to read device 0x%.8X's address on OCMB 0x%.08X",
                        TARGETING::get_huid(i_target),
                        TARGETING::get_huid(l_parentOcmb));
            break;
        }

        if (l_devAddr == FAPIWRAP::NO_DEV_ADDR)
        {
            TRACFCOMP(g_trac_i2c, ERR_MRK"ddimmDynamicI2CPresence() "
                      "Found devAddr for device 0x%.08x to be invalid. Likely that this device at REL_POS=%d does not exist for parent OCMB 0x%.8X",
                      TARGETING::get_huid(i_target),
                      l_relPos,
                      TARGETING::get_huid(l_parentOcmb));
            break;
        }

        // Remember the value we determined
        i_target->setAttr<TARGETING::ATTR_DYNAMIC_I2C_DEVICE_ADDRESS>(l_devAddr);

        // Do some i2c ops to physically detect the part
        l_errl = genericI2CTargetPresenceDetect(i_target,
                                                l_devPresent);

        if (l_errl)
        {
            TRACFCOMP( g_trac_i2c, ERR_MRK"ddimmDynamicI2CPresence() "
                        "Error detecting target 0x%.08X",
                        TARGETING::get_huid(i_target));
            break;
        }

    }while(0);

    if(l_errl)
    {
        l_devPresent = false;
    }

    // Copy variable describing if target is present or not to i/o buffer param
    memcpy(io_buffer, &l_devPresent, sizeof(l_devPresent));
    io_buflen = sizeof(l_devPresent);

    return l_errl;
}


/**
 * @brief Performs a presence detect operation on a MDS_CTLR Target
 *
 * @note Paramter io_buflen must be size of 1, will assert if not
 *
 * @param[in] DeviceFW::OperationType:
 *                           Parameter for the DD framework, not needed and not used
 * @param[in]     i_target   MDS target to detect presence of
 * @param[out]    o_buffer   Pointer to output data storage, the results of this call,
 *                           Where 1 = Success and 0 = Failure
 * @param[in/out] io_buflen  Size of io_buffer (in bytes, always 1, size of a bool)
 * @param[in]     int64_t    Parameter for the DD framework, not needed and not used
 * @param[in]     va_list    Parameter for the DD framework, not needed and not used
 *
 * @return  errlHndl_t
 */
errlHndl_t mdsI2CPresencePerformOp(DeviceFW::OperationType,    // DD framework parameter, not used
                                   TARGETING::Target* i_target,
                                   void*   o_buffer,
                                   size_t& io_buflen,
                                   int64_t, va_list) // DD framework parameters, not used
{
    assert(1 == io_buflen, "mdsI2CPresencePerformOp(): Expected buffer length (io_buflen) to be 1, received %d", io_buflen);
    assert(nullptr != o_buffer, "mdsI2CPresencePerformOp(): Expected a non-null i=o_buffer");

    errlHndl_t l_errl(nullptr);

    // Create a reference for easy access and ease of setting the outgoing buffer
    bool &l_mdsPresent = (static_cast<bool*>(o_buffer))[0];
    l_mdsPresent = false;  // Default outgoing buffer to false

    // Holds the device address of the MDS target
    uint8_t l_devAddr(0);

    // Get the state of the OCMB parent
    TARGETING::Target* l_parentOcmb(TARGETING::getImmediateParentByAffinity(i_target));
    auto l_parentHwasState(l_parentOcmb->getAttr<TARGETING::ATTR_HWAS_STATE>());

    do{
        if (!l_parentHwasState.present)
        {
            // If the parent chip is not present, then neither is the MDS target
            // so just break out and return not present
            break;
        }

        // Prior to doing present detection on an MDS we must first query the
        // device address from the parent OCMB's SPD
        l_errl = FAPIWRAP::get_mds_dev_addr( l_parentOcmb, l_devAddr );

        if (l_errl)
        {
            TRACFCOMP( g_trac_i2c, ERR_MRK"get_mds_dev_addr() "
                        "Error attempting to read MDS device address on OCMB 0x%.08X",
                        TARGETING::get_huid(l_parentOcmb));
            break;
        }

        if (l_devAddr == 0)
        {
            TRACFCOMP(g_trac_i2c, ERR_MRK"mdsI2CPresencePerformOp() "
                      "Found devAddr for MDS 0x%.08x to be 0. Likely that SPD returned "
                      "a value of 0 because this MDS does not exist for parent OCMB 0x%.8X",
                      TARGETING::get_huid(i_target),
                      TARGETING::get_huid(l_parentOcmb));
            break;
        }

        if (l_devAddr == FAPIWRAP::NO_DEV_ADDR)
        {
            TRACFCOMP(g_trac_i2c, ERR_MRK"mdsI2CPresencePerformOp() "
                      "No device address found for MDS 0x%.08x for parent OCMB 0x%.8X",
                      TARGETING::get_huid(i_target),
                      TARGETING::get_huid(l_parentOcmb));
            break;
        }

        // Set the dynamic I2C device address for the MDS with the retrieved device address
        i_target->setAttr<TARGETING::ATTR_DYNAMIC_I2C_DEVICE_ADDRESS>(l_devAddr);

        // Can't do an I2C operation on the MDS at this juncture therefore will
        // assume the MDS target is present on the premise of being able to set
        // the device address for the MDS target.
        // Set the outgoing buffer, o_buffer, to true via the l_mdsPresent reference
        l_mdsPresent = true;
    }while(0);

    return l_errl;
}  // mdsI2CPresencePerformOp


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
    assert(1 == io_buflen, "muxI2CPresencePerformOp(): Expected buffer length (io_buflen) to be 1, received %d", io_buflen);
    assert(nullptr != io_buffer, "muxI2CPresencePerformOp(): Expected a non-null io_buffer");

    bool l_muxPresent = 0;
    errlHndl_t l_errl = nullptr;

    l_errl = genericI2CTargetPresenceDetect(i_target,
                                            l_muxPresent);
    if (l_errl)
    {
        TRACFCOMP( g_trac_i2c, ERR_MRK"genericI2CTargetPresenceDetect() "
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

/**
 * @brief Performs a presence detect operation on a temperature sensor Target
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
errlHndl_t tempSensorPresencePerformOp(DeviceFW::OperationType i_opType,
                                             TARGETING::Target* i_target,
                                             void* io_buffer,
                                             size_t& io_buflen,
                                             int64_t i_accessType,
                                             va_list i_args)
{
    assert(1 == io_buflen, "tempSensorPresencePerformOp(): Expected buffer length (io_buflen) to be 1, received %d", io_buflen);
    assert(nullptr != io_buffer, "tempSensorPresencePerformOp(): Expected a non-null io_buffer");

    errlHndl_t l_errl = nullptr;
    bool l_tempSensorPresent = false;

    do {
        TARGETING::Target* l_parentOcmb = TARGETING::getImmediateParentByAffinity(i_target);
        auto l_parentHwasState = l_parentOcmb->getAttr<TARGETING::ATTR_HWAS_STATE>();

        if(! l_parentHwasState.present)
        {
            // If the parent chip is not present, then neither is the temperature sensor
            // so just break out and return not present
            TRACSSCOMP( g_trac_i2c, ERR_MRK"tempSensorPresencePerformOp() "
                       "Tgt HUID 0x%08X has non-present Parent HUID 0x%08X",
                        TARGETING::get_huid(i_target),
                        TARGETING::get_huid(l_parentOcmb));

            break;
        }

        // Check the SPD to determine the i2c address for the given sensor
        TARGETING::ATTR_REL_POS_type l_relPos
          = i_target->getAttr<TARGETING::ATTR_REL_POS>();

        uint8_t l_devAddr(0);
        l_errl = FAPIWRAP::get_tempsensor_dev_addr( l_parentOcmb, l_relPos, l_devAddr );
        if (l_errl)
        {
            TRACFCOMP( g_trac_i2c, ERR_MRK"get_tempsensor_dev_addr() "
                        "Error attempting to read temp sensor device address on OCMB 0x%.08X",
                        TARGETING::get_huid(l_parentOcmb));
            break;
        }

        if( l_devAddr == FAPIWRAP::NO_DEV_ADDR )
        {
            TRACFCOMP(g_trac_i2c, ERR_MRK"tempSensorPresencePerformOp() "
                      "Found devAddr for sensor 0x%.08x to be invalid.  This means the part isn't valid based on the SPD for parent OCMB 0x%.8X",
                      TARGETING::get_huid(i_target),
                      TARGETING::get_huid(l_parentOcmb));
            break;
        }

        // Set an attribute that we will push to the SPPE for their use
        i_target->setAttr<TARGETING::ATTR_SPPE_I2C_DEV_ADDR>(l_devAddr);

        // A valid i2c address means that the target exists.  HB can't physically
        //  talk to it since it sits behind the OCMB so we just mark it valid.
        l_tempSensorPresent = true;

    } while (0);

    // Copy variable describing if target is present or not to i/o buffer param
    memcpy(io_buffer, &l_tempSensorPresent, sizeof(l_tempSensorPresent));
    io_buflen = sizeof(l_tempSensorPresent);

    return l_errl;
}


/**
 * @brief Performs a presence detect operation on a POWER_IC (DoubleTop)
 *        target that is part of a DDR5 DDIMM.
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
errlHndl_t powerICPresence(DeviceFW::OperationType i_opType,
                           TARGETING::Target* i_target,
                           void* io_buffer,
                           size_t& io_buflen,
                           int64_t i_accessType,
                           va_list i_args)
{
    assert(1 == io_buflen, "powerICPresence(): Expected buffer length (io_buflen) to be 1, received %d", io_buflen);
    assert(nullptr != io_buffer, "powerICPresence(): Expected a non-null io_buffer");

    errlHndl_t l_errl = nullptr;
    bool l_devPresent = false;

    do{
        // First try the generic presence detection
        l_errl = ddimmDynamicI2CPresence( i_opType,
                                          i_target,
                                          &l_devPresent,
                                          io_buflen,
                                          i_accessType,
                                          i_args );
        if (l_errl)
        {
            TRACFCOMP( g_trac_i2c, ERR_MRK"powerICPresence() "
                       "Error calling ddimmDynamicI2CPresence-1 on 0x%.08X",
                       TARGETING::get_huid(i_target));
            break;
        }

        // If target is present then we're done
        if( l_devPresent )
        {
            break;
        }

        // If the parent chip is not present, then neither is the temperature sensor
        // so just break out and return not present
        TARGETING::Target* l_parentOcmb = TARGETING::getImmediateParentByAffinity(i_target);
        auto l_parentHwasState = l_parentOcmb->getAttr<TARGETING::ATTR_HWAS_STATE>();
        if( !l_parentHwasState.present )
        {
            TRACSSCOMP( g_trac_i2c, INFO_MRK"powerICPresence() "
                       "Tgt HUID 0x%08X has non-present Parent HUID 0x%08X",
                        TARGETING::get_huid(i_target),
                        TARGETING::get_huid(l_parentOcmb));

            break;
        }

        // Otherwise we may need to perform a workaround on the doubletop.
        // Sometimes the chip can power on into a bad state where it doesn't
        // recognize its own i2c address.  Instead it defaults to another
        // address that we have to use to manually reset things.

        // Only do the workaround if we think the target could be there.
        // This can be determined by checking that the dynamic i2c address
        // is set to something valid.  For example, the value will not
        // be changed if we detect this is a DDR4 DDIMM.
        auto l_devAddr = i_target->getAttr<TARGETING::ATTR_DYNAMIC_I2C_DEVICE_ADDRESS>();
        if( FAPIWRAP::NO_DEV_ADDR == l_devAddr )
        {
            break;
        }

        // Call the workaround
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_ocmb(l_parentOcmb);
        FAPI_INVOKE_HWP( l_errl, dt_trim_read_restart_ddr5, l_fapi_ocmb );
        if (l_errl)
        {
            TRACFCOMP( g_trac_i2c, ERR_MRK"powerICPresence() "
                        "Error calling dt_trim_read_restart_ddr5 for 0x%.8X's address on OCMB 0x%.08X",
                        TARGETING::get_huid(i_target),
                        TARGETING::get_huid(l_parentOcmb));
            break;
        }

        // Now do the generic detection again and use whatever result it gives.
        l_errl = ddimmDynamicI2CPresence( i_opType,
                                          i_target,
                                          &l_devPresent,
                                          io_buflen,
                                          i_accessType,
                                          i_args );
        if (l_errl)
        {
            TRACFCOMP( g_trac_i2c, ERR_MRK"powerICPresence() "
                       "Error calling ddimmDynamicI2CPresence-2 on 0x%.08X",
                       TARGETING::get_huid(i_target));
            break;
        }

    }while(0);

    if(l_errl)
    {
        l_devPresent = false;
    }

    // Copy variable describing if target is present or not to i/o buffer param
    memcpy(io_buffer, &l_devPresent, sizeof(l_devPresent));
    io_buflen = sizeof(l_devPresent);

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
                       ddimmDynamicI2CPresence );

// Register the Generic I2C Device presence detect function with the device framework
DEVICE_REGISTER_ROUTE( DeviceFW::READ,
                       DeviceFW::PRESENT,
                       TARGETING::TYPE_GENERIC_I2C_DEVICE,
                       ddimmDynamicI2CPresence );

// Register the MDS presence detect function with the device framework
DEVICE_REGISTER_ROUTE( DeviceFW::READ,
                       DeviceFW::PRESENT,
                       TARGETING::TYPE_MDS_CTLR,
                       mdsI2CPresencePerformOp );

// Register the temperature sensor detect function with the device framework
DEVICE_REGISTER_ROUTE( DeviceFW::READ,
                       DeviceFW::PRESENT,
                       TARGETING::TYPE_TEMP_SENSOR,
                       tempSensorPresencePerformOp );

// Register the power_ic detect function with the device framework
DEVICE_REGISTER_ROUTE( DeviceFW::READ,
                       DeviceFW::PRESENT,
                       TARGETING::TYPE_POWER_IC,
                       powerICPresence );
}
