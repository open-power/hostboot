/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/bootconfig/bootconfig_ast2400.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
#ifndef __INITSERVICE_BOOTCONFIG_AST2400_H
#define __INITSERIVCE_BOOTCONFIG_AST2400_H

#include "bootconfig.H"
namespace INITSERVICE
{
namespace BOOTCONFIG
{


/**
 *  @brief  AST2400BootConfig Class
 *  This class contains all of the logic and necessary information to
 *  read the SIO registers which are shared by the AMI BMC and Hostboot.
 *  The registers are used to write configuration information which is used by
 *  Hostboot during the IPL, the registers can be updated using IPMI commands.
 */
class AST2400BootConfig : public BootConfig
{

    /**********************************************************************/
    // Globals/Constants
    /**********************************************************************/


    /************************************************************************/
    // Typedef/Enumerations
    /************************************************************************/
    enum {

        // Hostboot/BMC shared register addresses.
        ISTEP_STATUS_REG          = 0x26,
        ISTEP_HOST_CTL_REG        = 0x27,
        BOOT_FLAGS_VERSION_REG    = 0x28,
        BOOT_FLAGS_REG            = 0x29,
        ISTEP_CONTROL_REG         = 0x2a,
        ISTEP_MAJOR_REG           = 0x2b,
        ISTEP_MINOR_REG           = 0x2c,
        PLAT_FLAGS_REG            = 0x2d,

        // SIO address/data register
        SIO_ADDR_REG              = 0x2e,
        SIO_DATA_REG              = 0x2f,

        // lock/unlock keys for SIO register access
        SIO_REG_UNLOCK_KEY        = 0xA5,
        SIO_REG_LOCK_KEY          = 0xAA,
    };

    // masks to select flags from SIO register
    enum bootFlagMask_t
    {
        LOG_LEVEL_FLAGS     = 0x07,
        RESERVED_FLAGS      = 0x08,
        BOOT_OPTIONS_FLAGS  = 0x30,
        BOOT_MODE_FLAGS     = 0xC0,
    };

    // Masks to test boot mode flags from config register
    enum bootModeFlags
    {
        NORMAL             = 0x00,
        TERMINATE_ON_ERROR = 0x40,
        ISTEP_MODE         = 0x80,
    };

    // Masks to test boot options flags from config register
    enum bootOptionsFlags
    {
        CLEAR_GARD_RECORDS  = 0x20,
    };

    // Masks to test log level flags from config register
    enum LogLevel
    {
        LOG_LEVEL_NORMAL        = 0x00,
        LOG_ENABLE_SCAN_TRACE   = 0x01,
    };

public:

    /**
     * @brief  Default constructor
     *
     */
    AST2400BootConfig();

    /**
     * @brief  Destructor
     *
     */
    ~AST2400BootConfig();

    /**
     * @brief Read BMC Scratch registers which contain ISTEP control
     *        information
     *
     * @param[out] o_istepInfo - ISTEP control structure containing the
     *                           next control action as well as next istep
     *                           information.
     * @return - errlHndl_t
     *
     *        SIO Register :  Contents
     *              0x2a      Istep control
     *              0x2b      Major step number
     *              0x2C      Minor step number
     */
    errlHndl_t readIstepControl(istepControl_t & o_istepInfo );

   /**
    * @brief Write BMC Scratch register which contains ISTEP control
    *
    * @param[out] i_istepInfo - ISTEP control structure containing the
    *                           next control action
    * @return - errlHndl_t
    *
    *        SIO Register :  Contents
    *              0x2a      Istep control
    */

    errlHndl_t writeIstepControl(istepControl_t i_istepCtl);


    /**
     * @brief Read BMC Scratch registers containing the boot flags
     *        and process them as needed.
     *
     *  SIO Register 0x29: Boot Flags
     *
     *       [0:1] Boot mode:
     *              00 : Normal
     *              01 : Terminate on first error
     *              10 : istep mode
     *              11 : reserved
     *       [2:3] Boot options
     *              00 : reserved
     *              01 : reserved
     *              10 : Clear gard
     *              11 : reserved
     *       [ 4 ] Reserved
     *       [5:7] Hostboot Log level:
     *                 000 : Normal
     *                 001 : Enable Scan trace
     *                 xxx : reserved
     *
     * @return - errlHndl_t
     */
    errlHndl_t readAndProcessBootConfig();

    /**
     * @brief Process the boot mode from the boot flags register.
     *
     * @param[i] i_mode - boot mode as set in the boot flags reg.
     *
     */
    void configureBootMode( uint8_t i_mode );

    /**
     * @brief Process boot options from boot flags register
     *
     * @param[i] i_options - requested boot options as set in the boot flags
     *                       reg.
     *
     */
    void configureBootOptions( uint8_t i_options );

    /**
     * @brief Process the Hostboot logging options from boot flags register
     *
     * @param[i] i_logOptions - requested hb logging options
     *
     */
    void configureHbLogLevel( uint8_t i_logOptions );

    /**
     * @brief process version one of the boot flags
     *        layout
     *
     * @param[i] i_flags - contents of SIO register 0x29
     *
     *
     *
     */
    void processBootFlagsV1( uint8_t i_flags );

};

};
};
#endif
