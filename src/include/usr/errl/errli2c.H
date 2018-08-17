/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/errl/errli2c.H $                              */
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
#ifndef ERRLI2C_H
#define ERRLI2C_H
/**
 *  @file errli2c.H
 *
 *  @brief  Error log target matching interface for i2c device callouts
 *
 *  This header file contains the definitions for an i2c device matching info
 *  data structure and a supporting singleton class to manage the creation of
 *  a lists of these structures. Once created, the list can be searched for
 *  targets to call out when an i2c device fails or is unresponsive.
 *
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <stdint.h>
#include <limits.h>
#include <vector>

#include <errl/errlentry.H>
#include <hwas/common/hwasCallout.H>
#include <i2c/eepromif.H>

namespace ERRORLOG
{

/**
 * @brief This structure stores information about I2C devices that we need
 *        in order to match identifying I2C device info with the info
 *        required for callouts.
 */
struct I2cMatchingInfo_t
{
    TARGETING::EntityPath i2cMasterPath;
    uint8_t engine;
    uint8_t port;
    uint8_t devAddr;
    uint8_t chipCount;
    EEPROM::eeprom_chip_types_t chipType;
    const TARGETING::Target* tgt;
    uint8_t targetAncestryDepth;
};

/**
 *  @brief I2c Device Info Matching Info Holding Class
 *
 *  This class provides a container for all of the I2C device info that is used
 *  to find matching devices for I2C Device Callouts. It is intended to be
 *  instantiated as a singleton so that the device info gathering process
 *  happens only once per IPL.
 */
class I2cDevInfos
{

public:

    /**
     * @brief getInstance returns an instance to a singleton object of type
     *        I2cDevInfos. This method ensures that the object has truly only
     *        one instance in the hostboot environment no matter where it is
     *        called.
     *
     * @return I2cDevInfos reference to the singleton object
     */
    static I2cDevInfos& getInstance();

    /**
     * @brief getDevList returns a reference to the matching info vector.
     *
     * The calling code can use this list of devices to find a matching device
     * and decide what needs to be called out.
     */
    const std::vector<I2cMatchingInfo_t>& getDevList() const
    {
        return iv_i2cdvs;
    }

    /**
     * @brief I2cDevInfos constructor.
     *
     * This does the actual work to build the list of I2C Devices with targets
     * that can be used for matching.
     */
    I2cDevInfos();

    // Disable compiler-provided default functions
    I2cDevInfos(const I2cDevInfos &) = delete;
    I2cDevInfos & operator=(const I2cDevInfos &) = delete;
    I2cDevInfos (I2cDevInfos&&) = delete;
    I2cDevInfos& operator = (I2cDevInfos&&) = delete;

private:

    // the vector that stores all the matching info
    std::vector<I2cMatchingInfo_t> iv_i2cdvs;

    /**
     * @brief getDepth returns the number of path elements in the indicated
     *        target's physical entity path
     *
     * Used internally by I2cDevInfos class to precalcuate target depths once
     * per IPL. Target depths are needed to remove duplicate HW callouts from
     * I2C Device Callout error logs.
     */
    uint8_t getDepth(const TARGETING::Target* tgt) const;

};


/**
 *  @brief Do the handling of an I2c device callout within hostboot for
 *         non-FSP based systems
 *
 *  @param[in]  i_errl          errlHndl_t to process. Cannot be nullptr.
 *  @param[in]  i_i2cMaster     The i2c master target. Cannot be nullptr.
 *                              Cannot be the master sentinel.
 *  @param[in]  i_engine        The i2c device engine
 *  @param[in]  i_port          The i2c device port
 *  @param[in]  i_address       The i2c device address
 *  @param[in]  i_priority      The i2c device callout priority
 *
 *  @return void
 */
void handleI2cDeviceCalloutWithinHostboot(
    errlHndl_t i_errl,
    const TARGETING::Target *i_i2cMaster,
    uint8_t i_engine,
    uint8_t i_port,
    uint8_t i_address,
    HWAS::callOutPriority i_priority);


} // End namespace


#endif //ERRLI2C_H
