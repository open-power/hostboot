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

void getSensorOffsetBasedOnSeverity(errlHndl_t & io_err,
                                    uint8_t &o_eventDirType,
                                    uint8_t & o_offset );

// helper function to gather sensor information
void getSensorInfo(HWAS::callout_ud_t *i_ud,
                   uint8_t &o_sensorNumber,
                   uint8_t &o_eventOffset,
                   HWAS::callOutPriority &io_priority,
                   errlHndl_t& io_error );

void ErrlManager::sendErrLogToBmc(errlHndl_t &io_err)
{
    TRACFCOMP(g_trac_errl, ENTER_MRK
                "sendErrLogToBmc errlogId 0x%.8x", io_err->eid());

    do {

        // Decide whether we want to skip the error log
        if( io_err->getSkipShowingLog() )
        {
            TRACFCOMP( g_trac_errl, INFO_MRK
                    "sendErrLogToBmc: %.8X is INFORMATIONAL/RECOVERED; skipping",
                    io_err->eid());
            break;
        }

        // look thru the errlog for any Callout UserDetail sections
        // to determine the sensor information for the SEL
        // create a vector of sensor numbers and offsets
        std::vector<std::pair<uint8_t, uint8_t> > l_sensorNumbers;
        HWAS::callOutPriority l_priority = HWAS::SRCI_PRIORITY_NONE;

        for(std::vector<ErrlUD*>::const_iterator
                it = io_err->iv_SectionVector.begin();
                it != io_err->iv_SectionVector.end();
                it++ )
        {
            uint8_t l_sensorNumber  = TARGETING::UTIL::INVALID_IPMI_SENSOR;
            uint8_t l_eventOffset   = IPMISEL::event_data1_invalid_offset;

            HWAS::callout_ud_t *l_ud =
                    reinterpret_cast<HWAS::callout_ud_t*>((*it)->iv_pData);

            // if this is a CALLOUT that will have a target
            if ((ERRL_COMP_ID     == (*it)->iv_header.iv_compId) &&
                (1                == (*it)->iv_header.iv_ver) &&
                (ERRL_UDT_CALLOUT == (*it)->iv_header.iv_sst) )
            {
                // if this callout is higher than any previous callout
                if (l_ud->priority > l_priority)
                {
                    TRACFCOMP(g_trac_errl,
                    "sendErrLogToBmc new priority picked 0x%x > 0x%x",
                     l_ud->priority, l_priority );

                    // get sensor number for the target.
                    // we found a higher priority callout, get the sensor
                    // information for it
                    getSensorInfo( l_ud, l_sensorNumber, l_eventOffset,
                                  l_priority, io_err);

                    TRACFCOMP(g_trac_errl,
                    "l_sensorNumber = 0x%x, l_eventOffset = 0x%x",
                     l_sensorNumber, l_eventOffset );


                    //remove previous sensor data
                    l_sensorNumbers.clear();

                    l_sensorNumbers.push_back(std::make_pair(l_sensorNumber,
                                                             l_eventOffset));

                        // and update the priority
                    l_priority = l_ud->priority;

                }
                // or if it has the same priority
                else if(l_ud->priority == l_priority)
                {
                    //get the sensor number for the target

                    getSensorInfo( l_ud, l_sensorNumber,
                                  l_eventOffset, l_priority, io_err);

                    l_sensorNumbers.push_back(std::make_pair(l_sensorNumber,
                                              l_eventOffset));
                }
            }
        } // for each SectionVector


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

        if (l_errSize ==0 )
        {
            // flatten didn't work
            TRACFCOMP( g_trac_errl, ERR_MRK
                    "sendErrLogToBmc: could not flatten data - not sending");
            delete [] l_pelData;
            break;
        }

        for(size_t i = 0; i < l_sensorNumbers.size(); i++)
        {

            uint8_t l_eventDirType  = IPMISEL::sensor_specific;

            // if the offset is unknown after this then it will
            // be updated based on elog severity below
            uint8_t l_eventOffset = l_sensorNumbers.at(i).second ;

            // last ditch effort, if no sensor number is present at this
            // point, just use the system event sensor
            if( l_sensorNumbers.at(i).first ==
                    TARGETING::UTIL::INVALID_IPMI_SENSOR )
            {
                l_sensorNumbers.at(i).first =
                    TARGETING::UTIL::getSensorNumber(NULL,
                            TARGETING::SENSOR_NAME_SYSTEM_EVENT);

                l_sensorNumbers.at(i).second =
                    SENSOR::UNDETERMINED_SYSTEM_HW_FAILURE;

            }

            // grab the sensor type so the bmc knows how to use the offset
            uint8_t unused = 0;
            uint8_t l_SensorType = 0;

            errlHndl_t e =
                SENSOR::SensorBase::getSensorType(
                        l_sensorNumbers.at(i).first,
                        l_SensorType,unused);

            if( e )
            {
                TRACFCOMP(g_trac_errl,
                        ERR_MRK"Failed to get sensor type for sensor %d",
                        l_sensorNumbers.at(i).first);

                l_SensorType = 0;
                // since we are in the commit path, lets just delete this
                // error and move on.
                delete e;
            }

            // if no offset has been configured set it based on the severity
            if( l_eventOffset == IPMISEL::event_data1_invalid_offset )
            {
                getSensorOffsetBasedOnSeverity(io_err, l_eventDirType,
                                           l_eventOffset );
            }

            // if we are sending the first sel then we will include the
            // pel data, otherwise we send no data
            uint32_t selSize = ( i == 0 ) ? l_pelSize:0;

            TRACFCOMP(g_trac_errl, INFO_MRK
                    "sendErrLogToBmc: sensor %.2x/%.2x event %x/%x, size %d",
                    l_SensorType, l_sensorNumbers.at(i).first,
                    l_eventDirType, l_eventOffset, selSize );

            IPMISEL::sendESEL(l_pelData, selSize,
                            io_err->eid(),
                            l_eventDirType, l_eventOffset,
                            l_SensorType,
                            l_sensorNumbers.at(i).first);
        }

        // free the buffer
        delete [] l_pelData;

    } while(0);

    TRACFCOMP(g_trac_errl, EXIT_MRK "sendErrLogToBmc");
} // sendErrLogToBmc


void getSensorInfo(HWAS::callout_ud_t *i_ud, uint8_t
                         &o_sensorNumber, uint8_t &o_eventOffset,
                         HWAS::callOutPriority &io_priority,
                         errlHndl_t &io_err )
{

    // reset the offset, we will test and configure it later
    o_eventOffset = IPMISEL::event_data1_invalid_offset;

    if( i_ud->type == HWAS::PROCEDURE_CALLOUT )
    {
        // for procedure callouts generate sel using the system event
        // sensor
        o_sensorNumber = TARGETING::UTIL::getSensorNumber(NULL,
                TARGETING::SENSOR_NAME_SYSTEM_EVENT);

        // use the generic offset to indicate there is more work
        // required to figure out what went wrong, ie. follow
        // the procedure in the elog
        o_eventOffset = SENSOR::UNDETERMINED_SYSTEM_HW_FAILURE;

    }
    // if its a clock callout or a its a part callout and its not
    // the VPD part or the SBE EEPROM, then use the backplane fault
    // sensor as these parts reside there.
    else if((i_ud->type == HWAS::CLOCK_CALLOUT ) ||
            ((i_ud->type == HWAS::PART_CALLOUT ) &&
             !((i_ud->partType == HWAS::VPD_PART_TYPE ) ||
               (i_ud->partType == HWAS::SBE_SEEPROM_PART_TYPE))
            ))
    {
        o_sensorNumber = SENSOR::getBackPlaneFaultSensor();
    }
    else
    {
        // for all other types there will be at least
        // one target in the next user data section, we will use
        // that target to find the fault sensor. For a
        // bus callout, we will just use the first of the
        // bus target endpoints provided.
        //
        // NOTE: if the provided target does not have a fault sensor, the
        // physical path will be used to determine the parent FRU which has
        // a fault sensor associated with it.
        uint8_t * l_uData = (uint8_t *)(i_ud + 1);
        TARGETING::Target *l_target = NULL;
        bool l_err = HWAS::retrieveTarget(l_uData,
                l_target, io_err);

        if (!l_err)
        {
            // got a target, now get the sensor number
            o_sensorNumber = SENSOR::getFaultSensorNumber(l_target);
        }
        else
        {
            // couldnt expand the target so we are unable to get
            // a sensor number - use the event sensor for this one
            o_sensorNumber = TARGETING::UTIL::getSensorNumber(NULL,
                    TARGETING::SENSOR_NAME_SYSTEM_EVENT);

            o_eventOffset = SENSOR::UNDETERMINED_SYSTEM_HW_FAILURE;

        }
    }
}

void getSensorOffsetBasedOnSeverity(errlHndl_t & io_err,
        uint8_t &o_eventDirType,
        uint8_t & o_eventOffset )
{
    switch (io_err->sev())
    {
        case ERRORLOG::ERRL_SEV_INFORMATIONAL:
            o_eventDirType  = IPMISEL::event_transition;
            o_eventOffset   = IPMISEL::event_data1_trans_informational;
            break;
        case ERRL_SEV_RECOVERED:
            o_eventDirType  = IPMISEL::event_transition;
            o_eventOffset   = IPMISEL::event_data1_trans_to_ok;
            break;
        case ERRL_SEV_PREDICTIVE:
            o_eventDirType  = IPMISEL::event_predictive;
            o_eventOffset   = IPMISEL::event_data1_trans_to_noncrit_from_ok;
            break;
        case ERRL_SEV_UNRECOVERABLE:
            o_eventDirType  = IPMISEL::event_transition;
            o_eventOffset   = IPMISEL::event_data1_trans_to_non_recoverable;
            break;
        case ERRL_SEV_CRITICAL_SYS_TERM:
            o_eventDirType  = IPMISEL::event_transition;
            o_eventOffset   = IPMISEL::event_data1_trans_to_crit_from_non_r;
            break;
        case ERRL_SEV_UNKNOWN:
            o_eventDirType  = IPMISEL::event_state;
            o_eventOffset   = IPMISEL::event_data1_asserted;
            break;
        default:
            o_eventDirType  = IPMISEL::sensor_specific;
            o_eventOffset   = IPMISEL::event_data1_trans_to_non_recoverable;
            break;
    }
}

#endif

} // end namespace
