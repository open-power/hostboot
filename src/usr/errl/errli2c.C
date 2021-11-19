/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errli2c.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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
/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <stdio.h>
#include <algorithm>
#include <errl/errli2c.H>
#include <errl/errlmanager.H>
#include <trace/interface.H>
#include <hwas/common/hwasCallout.H>
#include <hwas/common/deconfigGard.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <attributeenums.H>
#include <eeprom/eepromif.H>

using namespace ERRORLOG;
using namespace HWAS;

namespace ERRORLOG
{

// Trace definition
extern trace_desc_t* g_trac_errl;

uint8_t I2cDevInfos::getDepth(const TARGETING::Target* i_target) const
{
    return i_target->getAttr<TARGETING::ATTR_PHYS_PATH>().size();
}

I2cDevInfos::I2cDevInfos()
{
    auto& tS = TARGETING::targetService();

    TARGETING::TargetRangeFilter l_targetFilter(tS.begin(), tS.end(), nullptr);

    // gather up all the matching info and store in the vector
    for(;l_targetFilter; ++l_targetFilter)
    {
        const TARGETING::Target* l_tgt = (*l_targetFilter);
        // Looking to see if we have any info about VPD
        {
            TARGETING::ATTR_EEPROM_VPD_PRIMARY_INFO_type d; // local scope
            if (l_tgt->tryGetAttr<TARGETING::ATTR_EEPROM_VPD_PRIMARY_INFO>(d))
            {
                iv_i2cdvs.push_back({d.i2cMasterPath, d.engine, d.port,
                                    d.devAddr, d.chipCount, EEPROM::VPD_PRIMARY,
                                    l_tgt, getDepth(l_tgt)});
            }
        }
        {
            TARGETING::ATTR_EEPROM_VPD_BACKUP_INFO_type d; // local scope
            if (l_tgt->tryGetAttr<TARGETING::ATTR_EEPROM_VPD_BACKUP_INFO>(d))
            {
                // String literal is used for comparison below, must stay sync'd
                iv_i2cdvs.push_back({d.i2cMasterPath, d.engine, d.port,
                                     d.devAddr, d.chipCount, EEPROM::VPD_BACKUP,
                                     l_tgt, getDepth(l_tgt)});
            }
        }
        // UCD
        {
            TARGETING::ATTR_I2C_CONTROL_INFO_type u;
            if (l_tgt->tryGetAttr<TARGETING::ATTR_I2C_CONTROL_INFO>(u))
            {
                // String literal is used for comparison below, must stay sync'd
                iv_i2cdvs.push_back({u.i2cMasterPath, u.engine, u.port,
                                     u.devAddr, 0,
                                     EEPROM::INVALID_CHIP_TYPE, l_tgt,
                                     getDepth(l_tgt)});
            }
        }
    }
}


/* @brief Given an I2C device FRU, call out targets in the electrical path
 *        leading to it.
 *
 * @param[in] i_target     The target called out in the error log
 * @param[in] i_errl       The error log
 * @param[in] i_priority   The callout priority
 */
void addI2cFruPathCallouts(const TARGETING::Target* const i_target,
                           ErrlEntry* const i_errl,
                           const HWAS::callOutPriority i_priority)
{
#ifdef CONFIG_BUILD_FULL_PEL
    using namespace TARGETING;

    ATTR_I2C_CALLOUTS_type fru_path = { };

    if (i_target->tryGetAttr<ATTR_I2C_CALLOUTS>(fru_path))
    {
        const auto callouts = hbstd::deduplicate(ErrlEntry::getTargetCallouts(fru_path));

        for (const auto callout : callouts)
        {
            // The target itself has already been added to the error log.
            if (callout.target != i_target)
            {
                TRACFCOMP(g_trac_errl, "addI2cFruPathCallouts(plid=0x%08x): Calling out 0x%08x with priority %d",
                          ERRL_GETRC_SAFE(i_errl), get_huid(callout.target), i_priority);

                i_errl->addHwCallout(callout.target, i_priority, HWAS::NO_DECONFIG, HWAS::GARD_NULL);
            }
        }
    }
#endif
}

void handleI2cDeviceCalloutWithinHostboot(
        errlHndl_t i_errl,
        const TARGETING::Target *i_i2cMaster,
        const uint8_t i_engine,
        const uint8_t i_port,
        const uint8_t i_address,
        const HWAS::callOutPriority i_priority)
{
    do {

    assert(i_errl != nullptr, "Bug! Error log handle pointer passed is null");
    assert(i_i2cMaster != nullptr, "Bug! I2C master target passed is null");
    assert(i_priority >= HWAS::SRCI_PRIORITY_LOW &&
           i_priority <= HWAS::SRCI_PRIORITY_HIGH, "Bug! Bad priority given");

    auto& tS = TARGETING::targetService();

    auto l_devFound = false;

    const auto l_i2cmPhysPath = i_i2cMaster->
        getAttr<TARGETING::ATTR_PHYS_PATH>();

    // determine default priority to be one below what was passed in, or if
    // LOW was passed in, then LOW. Its use is described below.
    auto l_defaultPriority = HWAS::SRCI_PRIORITY_LOW;
    if (i_priority == HWAS::SRCI_PRIORITY_HIGH)
    {
        l_defaultPriority = HWAS::SRCI_PRIORITY_MED;
    }

    // list of devices to search from
    auto i2cdvs = I2cDevInfos::getInstance().getDevList();

    // we delay adding hardware callouts until the end so that we
    // can eliminate duplicate targets representing the same device
    std::vector<I2cMatchingInfo_t> i2chwcos;

    // try to find a device match in the list of matching infos
    for (auto& i2cd : i2cdvs)
    {
        TRACDCOMP(g_trac_errl, "handleI2cDeviceCalloutWithinHostboot: chipType "
                 "%d Engine=%d, Port=%d, addr=0x%X, "
                 "i2cMasterHuid=0x%X huid=0x%X w/ %d chips",
                 i2cd.chipType,
                 i2cd.engine,
                 i2cd.port,
                 i2cd.devAddr,
                 TARGETING::get_huid(tS.toTarget(i2cd.i2cMasterPath)),
                 TARGETING::get_huid(i2cd.tgt), i2cd.chipCount);

        // match the master path, engine and port
        if (l_i2cmPhysPath == i2cd.i2cMasterPath &&
            i_engine == i2cd.engine &&
            i_port == i2cd.port)
        {
            // all devices on the bus default to one notch below the passed
            // in priority unless LOW was passed in (see calculation above)
            auto l_priority = l_defaultPriority;

            // if the device is its own i2c master
            if (i_i2cMaster == i2cd.tgt)
            {
                // go the part callout route

                // set to the passed in priority if the address is in range
                // otherwise leave as default priority
                const auto maxAddr = i2cd.devAddr +
                                  (i2cd.chipCount * EEPROM::EEPROM_DEVADDR_INC);
                if (i_address >= i2cd.devAddr && i_address < maxAddr)
                {
                    l_priority = i_priority; // priority passed in
                    l_devFound = true;
                }
                TRACDCOMP(g_trac_errl, "handleI2cDeviceCalloutWithinHostboot: "
                          "Match found! Adding part callout for chipType %d "
                          "Engine=%d, Port=%d, addr=0x%X, i2cMasterHuid=0x%X "
                          "w/ %d chips",
                          i2cd.chipType,
                          i2cd.engine,
                          i2cd.port,
                          i2cd.devAddr,
                          TARGETING::get_huid(i2cd.tgt),
                          i2cd.chipCount);

                // add VPD or SBE part callout depending on chip type
                i_errl->addPartCallout(i2cd.tgt,
                                       (i2cd.chipType==EEPROM::VPD_PRIMARY ||
                                        i2cd.chipType==EEPROM::VPD_BACKUP)?
                                           HWAS::VPD_PART_TYPE:
                                           HWAS::NO_PART_TYPE,
                                       l_priority,
                                       HWAS::NO_DECONFIG,
                                       HWAS::GARD_NULL);
            }
            else
            {
                // go the HW callout route

                // first check to see if the device is a duplicate
                auto dupItr = std::find_if(i2chwcos.begin(),i2chwcos.end(),
                [&i2cd](const I2cMatchingInfo_t & matchedBefore)
                {
                    // return true if the current device matches something we
                    // have matched previously
                    return i2cd.i2cMasterPath == matchedBefore.i2cMasterPath &&
                           i2cd.engine == matchedBefore.engine &&
                           i2cd.port == matchedBefore.port &&
                           i2cd.devAddr == matchedBefore.devAddr;
                });

                TRACDCOMP(g_trac_errl, "handleI2cDeviceCalloutWithinHostboot: "
                          "i2cdev chipType=%d  Engine=%d, Port=%d, addr=0x%X, "
                          "i2cHuid=0x%X, i2cd.targetAncestryDepth=%d",
                          i2cd.chipType,
                          i2cd.engine,
                          i2cd.port,
                          i2cd.devAddr,
                          TARGETING::get_huid(i2cd.tgt),
                          i2cd.targetAncestryDepth);

                if(dupItr == i2chwcos.end())
                {
                    // not there so add the match
                    i2chwcos.push_back(i2cd);
                }
                else
                {
                    // dereference the duplicate device from its iterator
                    auto dupDev = *dupItr;

                    TRACDCOMP(g_trac_errl,
                              "handleI2cDeviceCalloutWithinHostboot: "
                              "dupdev chipType=%d  Engine=%d, Port=%d, "
                              "addr=0x%X, i2cHuid=0x%X, "
                              "dupDev.targetAncestryDepth=%d",
                              dupDev.chipType,
                              dupDev.engine,
                              dupDev.port,
                              dupDev.devAddr,
                              TARGETING::get_huid(dupDev.tgt),
                              dupDev.targetAncestryDepth);

                    // we need to replace it if we found a device with more
                    // seniority (in other words less depth) than the duplicate
                    if (dupDev.targetAncestryDepth > i2cd.targetAncestryDepth)
                    {
                        i2chwcos.erase(dupItr); // remove the old
                        i2chwcos.push_back(i2cd); // add the new
                    }
                }
            }
        }
    }

    // now that we know there are no duplicates add the HW callouts in 2nd pass
    for (auto& i2cd : i2chwcos)
    {
        // all devices on the bus default to one notch below the passed
        // in priority unless LOW was passed in (see calculation above)
        auto l_priority = l_defaultPriority;

        // set to the passed in priority for exact device address matches
        // otherwise leave as default priority

        if (i_address == i2cd.devAddr)
        {
            l_priority = i_priority;
            l_devFound = true;

            addI2cFruPathCallouts(i2cd.tgt, i_errl, i_priority);
        }
        TRACDCOMP(g_trac_errl, "handleI2cDeviceCalloutWithinHostboot: "
                  "Match found! Adding Hw callout for huid 0x%X",
                  TARGETING::get_huid(i2cd.tgt));
        i_errl->addHwCallout(i2cd.tgt,
                             l_priority,
                             HWAS::NO_DECONFIG,
                             HWAS::GARD_NULL);
    }

    // callout i2c master as the priorty passed in if nothing else was found
    // otherwise callout as low to let the device found to take precedence
    i_errl->addHwCallout( i_i2cMaster,
                          l_devFound? HWAS::SRCI_PRIORITY_LOW:
                                      i_priority,
                          HWAS::NO_DECONFIG,
                          HWAS::GARD_NULL );

    } while ( 0 );
}


I2cDevInfos& I2cDevInfos::getInstance()
{
    return Singleton<I2cDevInfos>::instance();
}

} // End namespace
