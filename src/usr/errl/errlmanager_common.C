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

#include <sys/mm.h>
#include <pnor/pnorif.H>

namespace ERRORLOG
{

extern trace_desc_t* g_trac_errl;

const uint32_t PNOR_ERROR_LENGTH = 4096;
const uint32_t EMPTY_ERRLOG_IN_PNOR = 0xFFFFFFFF;
const uint32_t FIRST_BYTE_ERRLOG = 0xF0000000;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// Global function (not a method on an object) to commit the error log.
void errlCommit(errlHndl_t& io_err, compId_t i_committerComp )
{
    ERRORLOG::theErrlManager::instance().commitErrLog(io_err, i_committerComp );
    return;
}

///////////////////////////////////////////////////////////////////////////////
// Global function (not a method on an object) to ack that the error log
// was sent to the BMC.
void ErrlManager::errlAckErrorlog(uint32_t i_eid)
{
    ERRORLOG::theErrlManager::instance().ackErrLogInPnor(i_eid);
    return;
}


///////////////////////////////////////////////////////////////////////////////
// Global function (not a method on an object) to get the hidden logs flag.
uint8_t getHiddenLogsEnable( )
{
    return ERRORLOG::theErrlManager::instance().iv_hiddenErrLogsEnable;
}

///////////////////////////////////////////////////////////////////////////////
// Atomically increment log id and return it.
uint32_t ErrlManager::getUniqueErrId()
{
    return (__sync_add_and_fetch(&iv_currLogId, 1));
}

// ------------------------------------------------------------------
// setupPnorInfo
// ------------------------------------------------------------------
void ErrlManager::setupPnorInfo()
{
    TRACFCOMP( g_trac_errl, ENTER_MRK"setupPnorInfo" );

    do
    {
        // Get HB_ERRLOG PNOR section info from PNOR RP
        PNOR::SectionInfo_t info;
        errlHndl_t err = PNOR::getSectionInfo( PNOR::HB_ERRLOGS, info );

        if (err)
        {
            TRACFCOMP( g_trac_errl, INFO_MRK"setupPnorInfo getSectionInfo failed");
            assert(err == NULL);
            break;
        }

        TRACFCOMP( g_trac_errl, INFO_MRK"setupPnorInfo sectionInfo id %d name \"%s\" size %d",
                info.id, info.name, info.size );

#ifndef __HOSTBOOT_RUNTIME
        // Set the globals appropriately
        iv_pnorAddr = reinterpret_cast<char *> (info.vaddr);
        iv_maxErrlInPnor = info.size / PNOR_ERROR_LENGTH;

        TRACFCOMP( g_trac_errl, INFO_MRK"setupPnorInfo iv_pnorAddr %p maxErrlInPnor %d",
                iv_pnorAddr, iv_maxErrlInPnor );

        // initial value, in case PNOR is empty - start at this end slot
        // so that our first save will increment and wrap correctly
        iv_pnorOpenSlot = (iv_maxErrlInPnor - 1);

        // walk thru memory, finding error logs and determine the highest ID
        uint32_t l_maxId = 0;
        for (uint32_t i = 0; i < iv_maxErrlInPnor; i++)
        {
            if (!isSlotEmpty(i))
            {
                uint32_t l_id = readEidFromFlattened(i);
                // If eid is not from HB or HBRT (meaning the FSP put this log
                // in here for us to 'start' from; FSP eid's aren't in the same
                // range as HB/HBRT eid's)
                if ( (l_id & FIRST_BYTE_ERRLOG) != ERRLOG_PLID_BASE )
                {
                    // then grab plid instead (FSP will have put a HB plid in
                    l_id = readPlidFromFlattened(i);
                }
                // if this is 'my' type of plid (HB or HBRT) see if it's max
                if (((l_id & FIRST_BYTE_ERRLOG) == ERRLOG_PLID_BASE ) &&
                    (l_id > l_maxId ))
                {
                    l_maxId = l_id;

                    // set this - start at this 'max' slot so that our first
                    // save will increment correctly
                    iv_pnorOpenSlot = i;
                }
                // also check if it's ACKed or not
                if (!isSlotACKed(i))
                {
                    TRACFCOMP( g_trac_errl,
                        INFO_MRK"setupPnorInfo slot %d eid %.8X was not ACKed.",
                        i, l_id);

#ifdef CONFIG_BMC_IPMI
                    // for IPMI systems, unflatten to send down to the BMC
                    err = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE, 0,0);
                    char *l_errlAddr = iv_pnorAddr + (PNOR_ERROR_LENGTH * i);
                    uint64_t rc = err->unflatten(l_errlAddr, PNOR_ERROR_LENGTH);
                    if (rc != 0)
                    {
                        // unflatten didn't work, nothing we can do
                        TRACFCOMP( g_trac_errl,
                            ERR_MRK"setupPnorInfo unflatten failed on slot %d eid %.8X.",
                            i, l_id);
                    }
                    else
                    {
                        // Decide if we need to skip the error log
                        setErrlSkipFlag(err);
                        if(err->getSkipShowingLog())
                        {
                            // skip it, go to the next one
                            continue;
                        }
                        if (iv_isIpmiEnabled)
                        {
                            // convert to SEL/eSEL and send to BMC over IPMI
                            sendErrLogToBmc(err,
                                            false /* do not resend SELs */);
                            delete err;
                        }
                        else
                        {
                            TRACFCOMP( g_trac_errl,
                                INFO_MRK"setupPnorInfo pushing slot %d eid %.8X to iv_errList.",
                                i, l_id);
                            // Pair with IPMI_NOSEL flag to add to the errlList
                            // so that it'll get sent down when IPMI is up
                            ErrlFlagPair_t l_pair(err, IPMI_NOSEL_FLAG
#ifdef CONFIG_CONSOLE_OUTPUT_ERRORDISPLAY
                                                         | ERRLDISP_FLAG
#endif
                                                 );
                            iv_errlList.push_back(l_pair);
                        }
                    }
#else
                    // for FSP system, this shouldn't ever happen.
                    setACKInFlattened(i);
#endif
                } // not ACKed
            } // not empty
        } // for

        // bump the current eid to 1 past the max eid found
        while (!__sync_bool_compare_and_swap(&iv_currLogId, iv_currLogId,
                    (iv_currLogId & ERRLOG_PLID_BASE_MASK) +
                    (l_maxId & ERRLOG_PLID_MASK) + 1));
        TRACFCOMP( g_trac_errl, INFO_MRK"setupPnorInfo reseting LogId 0x%X", iv_currLogId);

        // if error(s) came in before PNOR was ready,
        // the error log(s) would be on this list. save now.
        ErrlListItr_t it = iv_errlList.begin();
        while(it != iv_errlList.end())
        {
            // Check if PNOR processing is needed
            if (_isFlagSet(*it, PNOR_FLAG))
            {
                //ACK it if no one is there to receive
                bool l_savedToPnor = saveErrLogToPnor(it->first);

                // check if we actually saved the msg to PNOR
                if (l_savedToPnor)
                {
                    // Mark PNOR processing complete
                    _clearFlag(*it, PNOR_FLAG);
                    _updateErrlListIter(it);
                }
                else
                {
                    // still couldn't save it (PNOR maybe full) so
                    // it's still on the list.
                    break; // get out of this while loop.
                }
            }
            else
            {
                ++it;
            }
        }
#endif // __HOSTBOOT_RUNTIME
    } while (0);

    TRACFCOMP( g_trac_errl, EXIT_MRK"setupPnorInfo");
} // setupPnorInfo

///////////////////////////////////////////////////////////////////////////////
// ErrlManager::incrementPnorOpenSlot()
///////////////////////////////////////////////////////////////////////////////
bool ErrlManager::incrementPnorOpenSlot()
{
    uint32_t initialSlot = iv_pnorOpenSlot; // starting slot
    do
    {
        iv_pnorOpenSlot++;
        if (iv_pnorOpenSlot == iv_maxErrlInPnor)
        {   // wrap
            iv_pnorOpenSlot = 0;
        }
    } while (   !isSlotEmpty(iv_pnorOpenSlot) &&
                !isSlotACKed(iv_pnorOpenSlot) &&
                (iv_pnorOpenSlot != initialSlot));

    // if we got a different slot, return true; else false - no open slots
    return (iv_pnorOpenSlot != initialSlot);
} // incrementPnorOpenSlot

///////////////////////////////////////////////////////////////////////////////
// ErrlManager::saveErrLogToPnor()
///////////////////////////////////////////////////////////////////////////////
bool ErrlManager::saveErrLogToPnor( errlHndl_t& io_err)
{
    bool rc = false;
    TRACFCOMP( g_trac_errl, ENTER_MRK"saveErrLogToPnor eid=%.8x", io_err->eid());

    do
    {
        // Decide whether or not to skip error log
        // if so, we'll just 'say' that we saved it and go on.
        if( io_err->getSkipShowingLog() )
        {
            TRACFCOMP( g_trac_errl, INFO_MRK"saveErrLogToPnor: INFORMATIONAL/RECOVERED log, skipping");
            rc = true;
            break;
        }

        // save our current slot, and see if there's an open slot
        uint32_t l_previousSlot = iv_pnorOpenSlot;  // in case flatten fails

        if ((iv_pnorAddr != NULL) && incrementPnorOpenSlot())
        {
            // flatten into PNOR, truncate to the slot size
            char *l_pnorAddr =
                iv_pnorAddr + (PNOR_ERROR_LENGTH * iv_pnorOpenSlot);
            TRACDBIN( g_trac_errl, INFO_MRK"saveErrLogToPnor: l_pnorAddr before",
                l_pnorAddr, 128);
            uint64_t l_errSize = io_err->flatten(l_pnorAddr,
                                    PNOR_ERROR_LENGTH, true);
            if (l_errSize !=0)
            {
                TRACFCOMP( g_trac_errl, INFO_MRK"saveErrLogToPnor: %d bytes flattened into %p, slot %d",
                    l_errSize, l_pnorAddr, iv_pnorOpenSlot );

                TRACDBIN( g_trac_errl, INFO_MRK"saveErrLogToPnor: l_pnorAddr after",
                    l_pnorAddr, 128);

                // Ensure that this error log is pushed out to PNOR
#ifdef __HOSTBOOT_RUNTIME
                PNOR::flush(PNOR::HB_ERRLOGS);
#else
                // FLUSH so that only the dirty pages get pushed out
                int l_rc = mm_remove_pages(FLUSH,
                                (void *) l_pnorAddr, l_errSize);
                if( l_rc )
                {
                    //If mm_remove_pages returns non zero, trace error
                    TRACFCOMP(g_trac_errl, ERR_MRK "Fail to flush the page %p size %d",
                            l_pnorAddr, l_errSize);
                }
#endif
            }
            else
            {
                // flatten didn't work, so still return true - we don't want
                // to try to save this errlog.

                TRACFCOMP( g_trac_errl, ERR_MRK"saveErrLogToPnor: could not flatten data");
                // restore slot so that our next save will find this slot
                iv_pnorOpenSlot = l_previousSlot;
            }
            rc = true;
        }
        // else no open slot - return false
    } while (0);

    TRACFCOMP( g_trac_errl, EXIT_MRK"saveErrLogToPnor returning %s",
        rc ? "true" : "false");
    return rc;
} // saveErrLogToPnor

///////////////////////////////////////////////////////////////////////////////
// ErrlManager::ackErrLogInPnor()
///////////////////////////////////////////////////////////////////////////////
bool ErrlManager::ackErrLogInPnor( uint32_t i_errEid )
{
    TRACFCOMP( g_trac_errl, ENTER_MRK"ackErrLogInPnor(%.8x)", i_errEid);
    bool rc = true;

    // look for an un-ACKed log that matches this eid
    uint32_t i;
    for (i = 0; i < iv_maxErrlInPnor; i++)
    {
        if (!isSlotEmpty(i) && !isSlotACKed(i))
        {
            uint32_t l_eid = readEidFromFlattened(i);
            if (l_eid == i_errEid)
            {
                TRACDCOMP( g_trac_errl, INFO_MRK"ackErrLogInPnor: match in slot %d", i);
                setACKInFlattened(i);
                break;
            }
        }
    } // for

    // if we made it through the loop w/out breaking early
    if (i == iv_maxErrlInPnor)
    {
        //could not find the errorlog to mark for acknowledgment
        TRACDCOMP( g_trac_errl, ERR_MRK"ackErrLogInPnor failed to find the error log" );
        rc = false;
    }

    TRACFCOMP( g_trac_errl, EXIT_MRK"ackErrLogInPnor returning %s",
            rc ? "true" : "false");
    return rc;
} // ackErrLogInPnor


bool ErrlManager::isSlotEmpty(uint32_t i_position)
{
    // checks the first word of the flattened errlog, which should be a
    //  pelsectionheader - which will NEVER be 0xFFFFFFFF if it's valid.
    char * l_pnorAddr = iv_pnorAddr + (PNOR_ERROR_LENGTH * i_position);
    bool rc = (memcmp(l_pnorAddr, &EMPTY_ERRLOG_IN_PNOR, sizeof(uint32_t))
                    == 0);
    TRACDCOMP( g_trac_errl, "isSlotEmpty: slot %d @ %p is %s",
        i_position, l_pnorAddr, rc ? "empty" : "not empty");
    return rc;
}

// readEidFromFlattened()
// i_position MUST be valid errlog (not EMPTY_ERRLOG_IN_PNOR)
uint32_t ErrlManager::readEidFromFlattened(uint32_t i_position)
{
    const char * l_pnorAddr = iv_pnorAddr + (PNOR_ERROR_LENGTH * i_position);
    const pelPrivateHeaderSection_t *pPH =
            reinterpret_cast<const pelPrivateHeaderSection_t *>(l_pnorAddr);
    TRACDCOMP(g_trac_errl, "readEid(%d): eid %.8x", i_position, pPH->eid);

    return pPH->eid;
}

// readPlidFromFlattened()
// i_position MUST be valid errlog (not EMPTY_ERRLOG_IN_PNOR)
uint32_t ErrlManager::readPlidFromFlattened(uint32_t i_position)
{
    const char * l_pnorAddr = iv_pnorAddr + (PNOR_ERROR_LENGTH * i_position);
    const pelPrivateHeaderSection_t *pPH =
            reinterpret_cast<const pelPrivateHeaderSection_t *>(l_pnorAddr);
    TRACDCOMP(g_trac_errl, "readEid(%d): plid %.8x", i_position, pPH->plid);

    return pPH->plid;
}

// isSlotACKed()
// i_position MUST be valid errlog (not EMPTY_ERRLOG_IN_PNOR)
bool ErrlManager::isSlotACKed(uint32_t i_position)
{
    const char * l_pnorAddr = iv_pnorAddr + (PNOR_ERROR_LENGTH * i_position);
    l_pnorAddr += sizeof(pelPrivateHeaderSection_t);
    l_pnorAddr += sizeof(pelUserHeaderSection_t);
    const pelSRCSection_t *pSRC =
            reinterpret_cast<const pelSRCSection_t *>(l_pnorAddr);

    TRACDCOMP(g_trac_errl, "isSlotACKed(%d): word5 %08x - %s",
        i_position, pSRC->word5,
        (pSRC->word5 & ErrlSrc::ACK_BIT) ? "not ACKed" : "ACKed");

    return (pSRC->word5 & ErrlSrc::ACK_BIT) ? false : true;
}

// setACKInFlattened()
void ErrlManager::setACKInFlattened(uint32_t i_position)
{
    char * l_pnorErrlAddr = iv_pnorAddr + (PNOR_ERROR_LENGTH * i_position);
    char * l_pnorAddr = l_pnorErrlAddr + sizeof(pelPrivateHeaderSection_t);
    l_pnorAddr += sizeof(pelUserHeaderSection_t);
    pelSRCSection_t *pSRC = reinterpret_cast<pelSRCSection_t *>(l_pnorAddr);

    pSRC->word5 &= ~(ErrlSrc::ACK_BIT);

    TRACDCOMP(g_trac_errl, "setACKInFlattened(%d): word5 %08x - %s",
        i_position, pSRC->word5,
        (pSRC->word5 & ErrlSrc::ACK_BIT) ? "not ACKed" : "ACKed");

    return;
}


#ifdef CONFIG_BMC_IPMI
void getSensorOffsetBasedOnSeverity(errlHndl_t & io_err,
                                    uint8_t &o_eventDirType,
                                    uint8_t & o_offset );

// helper function to gather sensor information
void getSensorInfo(HWAS::callout_ud_t *i_ud,
                   uint8_t &o_sensorNumber,
                   uint8_t &o_eventOffset,
                   errlHndl_t& io_error );

//  SensorModifier is a class that detects certain procedure callouts that
//  can override the sensors generated by hardware callouts.
//  For example, a memory plugging error can override a hardware callout
//  of type memory in order to indicate a "configuration error" occured
//  See errlmanager.H for more info

// The constructor initializes flags for procedure callouts.
inline SensorModifier::SensorModifier()
{
    iv_flag = 0;
};

// Consider this callout as a potential sensor modifier
inline void SensorModifier::considerCallout(HWAS::callout_ud_t *i_ud)
{
    if (i_ud->type == HWAS::PROCEDURE_CALLOUT &&
        i_ud->procedure == HWAS::EPUB_PRC_MEMORY_PLUGGING_ERROR)
    {
        iv_flag |= memory_plugging_error_mask;
    }
};

// Modify the sensor if flag was set for that sensor.
inline bool SensorModifier::modifySensor(uint8_t i_sensorType,
        uint8_t& o_eventDirType, uint8_t& o_specificOffset)
{
    bool l_retval = false;
    if( (iv_flag & memory_plugging_error_mask) &&
       // we had a memory configuration error
       i_sensorType == TARGETING::SENSOR_TYPE_MEMORY
    )
    {
        o_eventDirType = IPMISEL::sensor_specific;
                            // 0x6f Sensor-specific Offset
        o_specificOffset = IPMISEL::event_data1_trans_monitor;
                            // 0x07 Configuration Error
        // modified
        l_retval = true;
    }
    return l_retval;
}


///////////////////////////////////////////////////////////////////////////////
// ErrlManager::sendErrLogToBmc()
///////////////////////////////////////////////////////////////////////////////
void ErrlManager::sendErrLogToBmc(errlHndl_t &io_err, bool i_sendSels)
{
    TRACFCOMP(g_trac_errl, ENTER_MRK
                "sendErrLogToBmc errlogId 0x%.8x, i_sendSels %d",
                io_err->eid(), i_sendSels);

    do {
        // keep track of procedure callouts that modify hardware callouts
        SensorModifier l_modifier;

        // Decide whether we want to skip the error log
        if( io_err->getSkipShowingLog() )
        {
            TRACFCOMP( g_trac_errl, INFO_MRK
                    "sendErrLogToBmc: %.8X is INFORMATIONAL/RECOVERED; skipping",
                    io_err->eid());
            break;
        }

        // two pass algorithm to find the highest priority callout
        // then send SELs for only the highest priority callouts
        std::vector< HWAS::callout_ud_t* > l_callouts;
        HWAS::callOutPriority l_priority = HWAS::SRCI_PRIORITY_NONE;
        if (i_sendSels)
        {
            // look thru the errlog for any Callout UserDetail sections
            // to later determine the sensor information for each SEL
            // create a vector of callouts during the first pass
            for(std::vector<ErrlUD*>::const_iterator
                    it = io_err->iv_SectionVector.begin();
                    it != io_err->iv_SectionVector.end();
                    it++ )
            {
                // if this is a CALLOUT
                if ((ERRL_COMP_ID     == (*it)->iv_header.iv_compId) &&
                    (1                == (*it)->iv_header.iv_ver) &&
                    (ERRL_UDT_CALLOUT == (*it)->iv_header.iv_sst) )
                {
                    HWAS::callout_ud_t *l_ud =
                        reinterpret_cast<HWAS::callout_ud_t*>((*it)->iv_pData);

                    // if this callout is higher than any previous callout
                    if (l_ud->priority > l_priority)
                    {
                        TRACFCOMP(g_trac_errl,
                            "sendErrLogToBmc new priority picked 0x%x > 0x%x",
                            l_ud->priority, l_priority );

                        // and update the priority
                        l_priority = l_ud->priority;
                    }
                    // consider as a potential modifier of other callouts
                    l_modifier.considerCallout(l_ud);

                    // add to list to be traversed in second pass
                    l_callouts.push_back(l_ud);
                } // if callout
            } // for each SectionVector
        } // if i_sendSels

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

        if (l_errSize == 0 )
        {
            // flatten didn't work
            TRACFCOMP( g_trac_errl, ERR_MRK
                    "sendErrLogToBmc: could not flatten data - not sending");
            delete [] l_pelData;
            break;
        }

        if (i_sendSels)
        {
            for(size_t i = 0; i < l_callouts.size(); i++)
            {
                uint8_t l_eventDirType = IPMISEL::sensor_specific;
                uint8_t l_sensorNumber = TARGETING::UTIL::INVALID_IPMI_SENSOR;
                uint8_t l_eventOffset = IPMISEL::event_data1_invalid_offset;

                // simplify callout notation
                HWAS::callout_ud_t* l_ud = l_callouts.at(i);

                // populate l_sensorNumber and l_eventOffset with values
                getSensorInfo( l_ud, l_sensorNumber, l_eventOffset, io_err);

                // if the offset is unknown at this point then it will
                // be updated below by getSensorOffsetBasedOnSeverity

                // last ditch effort, if no sensor number is present at this
                // point, just use the system event sensor
                if( l_sensorNumber ==
                        TARGETING::UTIL::INVALID_IPMI_SENSOR )
                {
                    l_sensorNumber =
                        TARGETING::UTIL::getSensorNumber(NULL,
                                TARGETING::SENSOR_NAME_SYSTEM_EVENT);

                    l_eventOffset =
                        SENSOR::UNDETERMINED_SYSTEM_HW_FAILURE;

                }

                // grab the sensor type so the bmc knows how to use the offset
                uint8_t unused = 0;
                uint8_t l_sensorType = 0;

                errlHndl_t e =
                    SENSOR::SensorBase::getSensorType(
                            l_sensorNumber,
                            l_sensorType,unused);

                if( e )
                {
                    TRACFCOMP(g_trac_errl,
                            ERR_MRK"Failed to get sensor type for sensor %d",
                            l_sensorNumber);

                    l_sensorType = 0;
                    // since we are in the commit path, lets just delete this
                    // error and move on.
                    delete e;
                }

                // this call will modify the sensor if any procedure callout is
                // known to change its effect
                bool l_wasModified = l_modifier.modifySensor(l_sensorType,
                                                l_eventDirType, l_eventOffset);

                // if no offset has been configured set it based on the severity
                if( l_eventOffset == IPMISEL::event_data1_invalid_offset )
                {
                    getSensorOffsetBasedOnSeverity(io_err, l_eventDirType,
                                               l_eventOffset );
                }

                // if we are sending the first sel then we will include the
                // pel data, otherwise we send no data
                uint32_t selSize = ( i == 0 ) ? l_pelSize:0;

                // only send highest priority SELs or
                // SELs of lesser priority that were modified
                if (l_ud->priority == l_priority || l_wasModified)
                {
                    TRACFCOMP(g_trac_errl, INFO_MRK "sendErrLogToBmc:"
                            " sensor %.2x/%.2x event %x/%x, size %d",
                            l_sensorType, l_sensorNumber,
                            l_eventDirType, l_eventOffset, selSize );

                    IPMISEL::sendESEL(l_pelData, selSize,
                                    io_err->eid(),
                                    l_eventDirType, l_eventOffset,
                                    l_sensorType,
                                    l_sensorNumber);
                }
            } // for l_callouts
        }
        else
        {
            // don't send sensor SELs
            TRACFCOMP(g_trac_errl, INFO_MRK
                    "sendErrLogToBmc: no sensor SELs, size %d",
                    l_pelSize );

            uint8_t l_eventDirType = IPMISEL::sensor_specific;
            uint8_t l_eventOffset = IPMISEL::event_data1_invalid_offset;
            IPMISEL::sendESEL(l_pelData, l_pelSize,
                            io_err->eid(),
                            l_eventDirType, l_eventOffset,
                            SENSOR::INVALID_TYPE, TARGETING::UTIL::INVALID_IPMI_SENSOR);
        }

        // free the buffer
        delete [] l_pelData;

    } while(0);

    TRACFCOMP(g_trac_errl, EXIT_MRK "sendErrLogToBmc");
} // sendErrLogToBmc

void getSensorInfo(HWAS::callout_ud_t *i_ud, uint8_t
                         &o_sensorNumber, uint8_t &o_eventOffset,
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
#endif // CONFIG_BMC_IPMI

void ErrlManager::setErrlSkipFlag(errlHndl_t io_err)
{
    // Note: iv_skipShowingLog is set to True by default
    //0 = Prevent INFORMATIONAL/RECOVERED error logs from being processed.
    //1 = Send only INFORMATIONAL error logs.
    //2 = Send only RECOVERED error logs.
    //3 = Allow all hidden error logs to be processed.

    //Check severity
    switch (io_err->sev())
    {
        case ERRORLOG::ERRL_SEV_INFORMATIONAL:

            // check if we are allowing info logs through.
            if((iv_hiddenErrLogsEnable ==
                TARGETING::
                    HIDDEN_ERRLOGS_ENABLE_ALLOW_INFORMATIONAL)||
               (iv_hiddenErrLogsEnable ==
                TARGETING::
                    HIDDEN_ERRLOGS_ENABLE_ALLOW_ALL_LOGS))
            {
                io_err->setSkipShowingLog(false);
            }
            break;

        case ERRORLOG::ERRL_SEV_RECOVERED:

            // check if we are allowing recovered logs through.
            if(((iv_hiddenErrLogsEnable ==
               TARGETING::
                    HIDDEN_ERRLOGS_ENABLE_ALLOW_RECOVERED) ||
               (iv_hiddenErrLogsEnable ==
                TARGETING::
                    HIDDEN_ERRLOGS_ENABLE_ALLOW_ALL_LOGS)) &&
                !iv_isSpBaseServices)
            {
                //Recovered error logs that are encountered
                //before targeting and initservice are loaded,
                //will still be queued for sending to PNOR/IPMI
                io_err->setSkipShowingLog(false);
            }
            break;

        default:

            // For any error log that is not INFORMATIONAL
            // or RECOVERED, we want to show the log
            io_err->setSkipShowingLog(false);
    }
} // setErrlSkipFlag

} // end namespace
