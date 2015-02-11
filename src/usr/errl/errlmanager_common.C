/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errlmanager_common.C $                           */
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
#include <errl/errlmanager.H>
#include <config.h>
#include <hwas/common/hwasCallout.H>
#include <errl/errlreasoncodes.H>
#include <ipmi/ipmisel.H>
#include <ipmi/ipmisensor.H>

namespace ERRORLOG
{

extern trace_desc_t* g_trac_errl;

#ifdef CONFIG_BMC_IPMI
void ErrlManager::sendErrLogToBmc(errlHndl_t &io_err)
{
    TRACFCOMP(g_trac_errl, ENTER_MRK
                "sendErrLogToBmc errlogId 0x%.8x", io_err->eid());

    do {

        // if it's an INFORMATIONAL log, we don't want to waste the cycles
        if (io_err->sev() == ERRORLOG::ERRL_SEV_INFORMATIONAL)
        {
            TRACFCOMP( g_trac_errl, INFO_MRK
                    "sendErrLogToBmc: %.8X is INFORMATIONAL; skipping",
                    io_err->eid());
            break;
        }

        // look thru the errlog for any Callout UserDetail sections
        //  to determine the sensor information for the SEL
        uint8_t l_sensorNumber = SENSOR::INVALID_SENSOR;
        uint8_t l_sensorType = SENSOR::INVALID_SENSOR;
        HWAS::callOutPriority l_priority = HWAS::SRCI_PRIORITY_NONE;
        for(std::vector<ErrlUD*>::const_iterator
                it = io_err->iv_SectionVector.begin();
                it != io_err->iv_SectionVector.end();
                it++ )
        {
            HWAS::callout_ud_t *l_ud =
                    reinterpret_cast<HWAS::callout_ud_t*>((*it)->iv_pData);

            // if this is a CALLOUT that will have a target
            if ((ERRL_COMP_ID     == (*it)->iv_header.iv_compId) &&
                (1                == (*it)->iv_header.iv_ver) &&
                (ERRL_UDT_CALLOUT == (*it)->iv_header.iv_sst) &&
                (HWAS::HW_CALLOUT == l_ud->type)
               )
            {
                // if this callout is higher than any previous
                if (l_ud->priority > l_priority)
                {
                    // get the sensor number for the target
                    uint8_t * l_uData = (uint8_t *)(l_ud + 1);
                    TARGETING::Target *l_target = NULL;
                    bool l_err = HWAS::retrieveTarget(l_uData,
                            l_target, io_err);
                    if (!l_err)
                    {
                        // got a target, now get the sensor number
                        l_sensorNumber =
                                SENSOR::getFaultSensorNumber(l_target);

                        // and update the priority
                        l_priority = l_ud->priority;
                    }
                }
            }
        } // for each SectionVector

#if 0
// TODO: RTC 119440
        if (l_sensorNumber != SENSOR::INVALID_SENSOR)
        {
            l_sensorType = SENSOR::getSensorType(l_sensorNumber);
        }
#endif

        // flatten into buffer, truncate to max eSEL size
        uint32_t l_pelSize = io_err->flattenedSize();
        if (l_pelSize > (IPMISEL::ESEL_MAX_SIZE - sizeof(IPMISEL::selRecord)))
        {
            TRACFCOMP( g_trac_errl, INFO_MRK
                    "sendErrLogToBmc: msg size %d > %d, truncating.",
                    l_pelSize, IPMISEL::ESEL_MAX_SIZE);
            l_pelSize = IPMISEL::ESEL_MAX_SIZE - sizeof(IPMISEL::selRecord);
        }

        uint8_t *l_pelData = new uint8_t[l_pelSize];
        uint32_t l_errSize = io_err->flatten (l_pelData,
                                    l_pelSize, true /* truncate */);

        if (l_errSize ==0)
        {
            // flatten didn't work
            TRACFCOMP( g_trac_errl, ERR_MRK
                    "sendErrLogToBmc: could not flatten data - not sending");
            delete [] l_pelData;
            break;
        }

        // send it to the BMC over IPMI
        TRACFCOMP(g_trac_errl, INFO_MRK
                "sendErrLogToBmc: sensor %.2x/%.2x, size %d",
                l_sensorType, l_sensorNumber, l_pelSize);
        IPMISEL::sendESEL(l_pelData, l_pelSize,
                            io_err->eid(), IPMISEL::event_unspecified,
                            l_sensorType, l_sensorNumber);

        // free the buffer
        delete [] l_pelData;

    } while(0);

    TRACFCOMP(g_trac_errl, EXIT_MRK "sendErrLogToBmc");
} // sendErrLogToBmc

#endif

} // end namespace