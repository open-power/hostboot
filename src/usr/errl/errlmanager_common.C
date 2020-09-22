/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errlmanager_common.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
#include <hwas/common/hwasCallout.H>
#include <errl/errlreasoncodes.H>

#ifdef CONFIG_BMC_IPMI
#include <ipmi/ipmisel.H>
#include <ipmi/ipmisensor.H>
#include <ipmi/ipmiconfiglookup.H>
#endif

#ifndef __HOSTBOOT_RUNTIME
#include <pnor/pnorif.H>
#endif

#include <errl/errlentry.H>
#include <sys/mm.h>
#include <errl/errludstring.H>
#include <map>
#include <util/misc.H>

namespace ERRORLOG
{

extern trace_desc_t* g_trac_errl;

// the maximum number of targets that a callout is associated with
#define MAX_NUM_TARGETS 2

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
    uint32_t l_logId = 0;
    uint32_t l_nextLogId = 1;

    while (1)
    {
        l_logId = iv_currLogId;

        if (!iv_pnorReadyForErrorLogs)
        {
            // Range [__800000 - __FFFFFF]
            l_nextLogId = ( iv_baseNodeId |
                             (((l_logId + 1) & ERRLOG_PLID_MASK) |
                                ERRLOG_PLID_INITIAL) );
        }
        else
        {
            // Range [__000000 - __7FFFFFF]
            l_nextLogId = ( iv_baseNodeId |
                            ((l_logId + 1) & ERRLOG_PLID_POST_MAX) );
        }

        if (__sync_bool_compare_and_swap(&iv_currLogId, l_logId, l_nextLogId))
        {
            // To maintain thread-safeness (do not use iv_currLogId here)
            // Do the same operation to l_logId as this is the same value
            // that iv_currLogID had before its operation
            l_logId = l_nextLogId;
            break;
        }
    }
    return l_logId;
}

#ifndef __HOSTBOOT_RUNTIME
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

        // Set the globals appropriately
        iv_pnorAddr = reinterpret_cast<char *> (info.vaddr);
        iv_maxErrlInPnor = info.size / PNOR_ERROR_LENGTH;

        TRACFCOMP( g_trac_errl, INFO_MRK"setupPnorInfo iv_pnorAddr %p maxErrlInPnor %d",
                iv_pnorAddr, iv_maxErrlInPnor );

        // initial value, in case PNOR is empty - start at this end slot
        // so that our first save will increment and wrap correctly
        iv_pnorOpenSlot = (iv_maxErrlInPnor - 1);

        // walk thru memory, finding error logs and
        // determine the highest ID within the lower POST range of EIDs
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
                    (l_id > l_maxId ) &&
                    ((l_id & ERRLOG_PLID_MASK) <= ERRLOG_PLID_POST_MAX))
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
                        // Decide if we need to skip processing / displaying the
                        // error log
                        setErrlSkipFlag(err);
                        if(err->getSkipProcessingLog())
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
                            err = nullptr;
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
#endif  // #ifdef CONFIG_CONSOLE_OUTPUT_ERRORDISPLAY
                                                 );
                            iv_errlList.push_back(l_pair);
                        }
                    }
#else  // #ifdef CONFIG_BMC_IPMI
                    // for FSP system, this shouldn't ever happen.
                    setACKInFlattened(i);
#endif // #else ... #ifdef CONFIG_BMC_IPMI
                } // not ACKed
            } // not empty
        } // for

        // bump the current eid to 1 past the max eid found
        // Stay within the non-preboot range
        while ( !__sync_bool_compare_and_swap(&iv_currLogId, iv_currLogId,
                 (iv_baseNodeId |
                 ((l_maxId + 1) & ERRLOG_PLID_POST_MAX))) );

        // set this to change new max/min values for iv_currLogId
        // new max = ERRLOG_PLID_POST_MAX, new min = 0
        iv_pnorReadyForErrorLogs = true;
        TRACFCOMP( g_trac_errl,
            INFO_MRK"setupPnorInfo resetting LogId number 0x%X",
            iv_currLogId);


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
    } while (0);

    TRACFCOMP( g_trac_errl, EXIT_MRK"setupPnorInfo");
} // setupPnorInfo
#endif // #ifndef __HOSTBOOT_RUNTIME

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
        if( io_err->getSkipProcessingLog() )
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
#ifndef __HOSTBOOT_RUNTIME
                // FLUSH so that only the dirty pages get pushed out
                int l_rc = mm_remove_pages(FLUSH,
                                (void *) l_pnorAddr, l_errSize);
                if( l_rc )
                {
                    //If mm_remove_pages returns non zero, trace error
                    TRACFCOMP(g_trac_errl, ERR_MRK "Fail to flush the page %p size %d",
                            l_pnorAddr, l_errSize);
                }
#endif // #ifndef __HOSTBOOT_RUNTIME
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
uint8_t getSensorInfo(HWAS::callout_ud_t *i_ud,
                   uint8_t* o_sensorNumber,
                   uint8_t* o_eventOffset,
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
    else if (i_ud->type == HWAS::PROCEDURE_CALLOUT &&
             (i_ud->procedure == HWAS::EPUB_PRC_PROC_AB_BUS ||
              i_ud->procedure == HWAS::EPUB_PRC_PROC_XYZ_BUS ||
              i_ud->procedure == HWAS::EPUB_PRC_EIBUS_ERROR)
            )
    {
        iv_flag |= bus_error_mask;
    }
    else if (i_ud->type == HWAS::PROCEDURE_CALLOUT &&
             i_ud->procedure == HWAS::EPUB_PRC_MEMBUS_ERROR)
    {
       iv_flag |= membus_error_mask;
    }
};

// Modify the sensor if flag was set for that sensor.
inline bool SensorModifier::modifySensor(uint8_t i_sensorType,
        uint8_t& o_eventDirType, uint8_t& o_specificOffset)
{
    bool l_retval = false;
    if( (iv_flag & memory_plugging_error_mask) &&
       // we had a memory configuration error
       i_sensorType == TARGETING::SENSOR_TYPE_MEMORY)
    {
        o_eventDirType = IPMISEL::sensor_specific;
                            // 0x6f Sensor-specific Offset
        o_specificOffset = IPMISEL::mem_event_configuration_error;
                            // 0x07 Configuration Error
        // modified
        l_retval = true;
    }
    else if ( (iv_flag & bus_error_mask || iv_flag & membus_error_mask) &&
         i_sensorType == TARGETING::SENSOR_TYPE_PROCESSOR)
    {
        o_eventDirType = IPMISEL::sensor_specific;
        o_specificOffset = IPMISEL::proc_event_correctable_mach_check_err;
                            // 0x0Ch Correctable Machine Check Error
        // modified;
        l_retval = true;
    }
    else if ( (iv_flag & membus_error_mask) &&
          i_sensorType == TARGETING::SENSOR_TYPE_MEMORY)
    {
        o_eventDirType = IPMISEL::sensor_specific;
        o_specificOffset = IPMISEL::mem_event_device_disabled;
                            // 0x04 Memory device disabled
        // modified;
        l_retval = true;
    }
    return l_retval;
}

// Retrieve if informational/call-home eSELs are allowed to the BMC
bool ErrlManager::allowCallHomeEselsToBmc(void)
{
    bool l_allowed = false;
    uint8_t flag = 0;
    TARGETING::Target* sys = nullptr;
    TARGETING::targetService().getTopLevelTarget(sys);
    if (sys)
    {
        flag = sys->getAttr<TARGETING::ATTR_ALLOW_CALLHOME_ESELS_TO_BMC>();
    }
    if (flag)
    {
        l_allowed = true;
    }

    return l_allowed;
}

#ifndef __HOSTBOOT_RUNTIME
// @TODO: RTC 244854: Enable when can
//        Having linking issue with symbols IPMI::IpmiConfigLookup::getSensorType
//        and SENSOR::getFaultSensorNumber for Jenkins OP-BUILD

///////////////////////////////////////////////////////////////////////////////
// ErrlManager::sendErrLogToBmc()
///////////////////////////////////////////////////////////////////////////////
void ErrlManager::sendErrLogToBmc(errlHndl_t &io_err, bool i_sendSels)
{
    TRACFCOMP(g_trac_errl,
                 ENTER_MRK
                "sendErrLogToBmc errlogId 0x%.8x, i_sendSels %d",
                io_err->eid(), i_sendSels);

    bool l_send_eSel_only = !i_sendSels; // don't send callout sensor SEL
    bool l_callhome_type = false;        // Is this a callhome type eSEL?
    if (io_err->getEselCallhomeInfoEvent() && allowCallHomeEselsToBmc())
    {
        TRACFCOMP( g_trac_errl, INFO_MRK
            "sendErrLogToBmc: setting l_callhome_type" );
        l_callhome_type = true;
        l_send_eSel_only = true;  // just send eSEL without any callout SELs
    }

    do {

        // keep track of procedure callouts that modify hardware callouts
        SensorModifier l_modifier;

        // Decide whether we want to skip the error log
        if( io_err->getSkipProcessingLog() && !l_callhome_type )
        {
            TRACFCOMP( g_trac_errl, INFO_MRK
                "sendErrLogToBmc: %.8X is INFORMATIONAL/RECOVERED; skipping",
                    io_err->eid());
            break;
        }

        // two pass algorithm to find the highest priority callout
        // then send SELs for only the highest priority callouts
        std::vector< HWAS::callout_ud_t* > l_callouts;
        HWAS::callout_ud_t l_calloutToAdd; // used for EIBUS error
        HWAS::callOutPriority l_priority = HWAS::SRCI_PRIORITY_NONE;
        if (!l_send_eSel_only)
        {
            bool l_busCalloutEncountered = false; // flag bus callout

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

                    // create a "fill in" procedure callout for all bus callouts
                    if (l_ud->type == HWAS::BUS_CALLOUT)
                    {
                        l_busCalloutEncountered = true;
                        l_calloutToAdd.type = HWAS::PROCEDURE_CALLOUT;
                        l_calloutToAdd.procedure = HWAS::EPUB_PRC_EIBUS_ERROR;
                    }

                    // I2C device callouts don't map to anything useful in the
                    // IPMI world. They do come with a more IPMI-friendly
                    // callout that follows after, so we can skip to the next.
                    if (l_ud->type == HWAS::I2C_DEVICE_CALLOUT)
                    {
                        continue;
                    }

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
            if (l_busCalloutEncountered)
            {
                // add EIBUS error procedure callout
                // doing push_back after the loop and not during ensures that:
                // 1) the iterator is not invalidated by the push_back
                // 2) the push_back is done only once, even when there are
                //    multiple bus callouts (which is often). This would not
                //    be a major concern though since duplicates are removed
                //    in the next loop below.
                l_callouts.push_back(&l_calloutToAdd);
                // need to also consider this callout as a modifier of others
                l_modifier.considerCallout(&l_calloutToAdd);
                // our added callout always takes the highest priority seen
                // so that it will not be dropped
                l_calloutToAdd.priority = l_priority;
            }
        } // if i_sendSels

        //Add additional user detail section to pel data after hw and procedure
        //callouts to indicate esels from a previous boot.
        if(!i_sendSels)
        {
            const char* l_prev_boot = "Error from a previous boot";
            // Create a raw user-defined section.  It does a copy of the
            // string constant, then once added to io_err, io_err owns mem
            ErrlUD* l_ffdcSection = new ErrlUD(l_prev_boot, strlen(l_prev_boot),
                                         ERRL_COMP_ID, 1, ERRL_UDT_STRING );
            io_err->iv_SectionVector.insert(io_err->iv_SectionVector.begin(),
                                            l_ffdcSection);

            // If this is an error from the previous boot, pass it off as a
            // call home applicable log to get the eSEL propagated
            l_callhome_type = true;
        }

        // flatten into buffer, truncate to max eSEL size
        TARGETING::Target * sys = NULL;
        TARGETING::targetService().getTopLevelTarget( sys );
        uint32_t l_maxBmcErrLogSize;

        if ( sys &&
             sys->tryGetAttr<TARGETING::ATTR_BMC_MAX_ERROR_LOG_SIZE>( l_maxBmcErrLogSize ) )
        {
            // (value was extracted from attributes)
        }
        else
        {
            // use default value for max log size
            l_maxBmcErrLogSize =  IPMISEL::ESEL_MAX_SIZE_DEFAULT;

            TRACFCOMP( g_trac_errl, INFO_MRK
                       "sendErrLogToBmc: "
                       "Attribute ATTR_BMC_MAX_ERROR_LOG_SIZE not found, "
                       "ESEL_MAX_SIZE_DEFAULT used" );
        }

        uint32_t l_pelSize = io_err->flattenedSize();
        if (l_pelSize > (l_maxBmcErrLogSize - sizeof(IPMISEL::selRecord)))
        {
            TRACFCOMP( g_trac_errl, INFO_MRK
                    "sendErrLogToBmc: msg size %d > %d, truncating.",
                    l_pelSize, l_maxBmcErrLogSize);
            l_pelSize = l_maxBmcErrLogSize - sizeof(IPMISEL::selRecord);
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

        // list of sels to be sent
        std::vector<IPMISEL::sel_info_t*> l_selEventList;

        // bool default constructor initializes to false as per C++ standard
        std::map<uint8_t, bool> l_sensorNumberEncountered;

        if (!l_send_eSel_only)
        {
            l_selEventList.clear();
            std::vector<HWAS::callout_ud_t*>::const_iterator i;
            for(i = l_callouts.begin(); i != l_callouts.end(); ++i)
            {
                uint8_t l_eventDirType[MAX_NUM_TARGETS] = {
                        IPMISEL::sensor_specific,
                        // this second element is only used for bus callouts
                        IPMISEL::sensor_specific};
                uint8_t l_sensorNumber[MAX_NUM_TARGETS] = {
                        TARGETING::UTIL::INVALID_IPMI_SENSOR,
                        // this second element is only used for bus callouts
                        TARGETING::UTIL::INVALID_IPMI_SENSOR};
                uint8_t l_eventOffset[MAX_NUM_TARGETS] = {
                        IPMISEL::event_data1_invalid_offset,
                        // this second element is only used for bus callouts
                        IPMISEL::event_data1_invalid_offset};
                uint8_t l_sensorType[MAX_NUM_TARGETS] = { 0,
                        // this second element is only used for bus callouts
                        0};

                // simplify callout notation
                HWAS::callout_ud_t* l_ud = *i;

                // populate l_sensorNumber and l_eventOffset with values
                uint8_t l_num_targets = getSensorInfo(l_ud, l_sensorNumber,
                                                      l_eventOffset, io_err);

                // if the offset is unknown at this point then it will
                // be updated below by getSensorOffsetBasedOnSeverity

                // l_num_targets is 2 for bus callouts, 1 otherwise
                for (size_t j=0; j < l_num_targets; ++j)
                {
                    // last ditch effort, if no sensor number is present at
                    // this point, just use the system event sensor
                    if( l_sensorNumber[j] ==
                        TARGETING::UTIL::INVALID_IPMI_SENSOR )
                    {
                        l_sensorNumber[j] =
                            TARGETING::UTIL::getSensorNumber(NULL,
                                        TARGETING::SENSOR_NAME_SYSTEM_EVENT);

                        l_eventOffset[j] =
                                       SENSOR::UNDETERMINED_SYSTEM_HW_FAILURE;
                    }

                    // grab the sensor type so the bmc knows how to use the
                    // offset
                    errlHndl_t l_errl =
                       IPMI::IpmiConfigLookup::getSensorType(l_sensorNumber[j],
                                                             l_sensorType[j]
                                                            );
                    if(l_errl)
                    {
                        TRACFCOMP(g_trac_errl,
                            ERR_MRK"Failed to get sensor type for sensor %d",
                            l_sensorNumber[j]);
                        l_sensorType[j] = 0;

                        delete l_errl;
                        l_errl = nullptr;
                    }

                    // this call will modify the sensor if any procedure
                    // callout is known to change its effect
                    bool l_wasModified = l_modifier.modifySensor(
                        l_sensorType[j], l_eventDirType[j], l_eventOffset[j]);

                    // if no offset has been configured set it based on the
                    // severity
                    if(l_eventOffset[j] == IPMISEL::event_data1_invalid_offset)
                    {
                        getSensorOffsetBasedOnSeverity(io_err,
                           l_eventDirType[j], l_eventOffset[j]);
                    }

                    // only send highest priority SELs or
                    // SELs of lesser priority that were modified
                    if (l_ud->priority == l_priority || l_wasModified)
                    {
                       // skip this iteration if we've seen this sensor
                       // number before
                       if (l_sensorNumberEncountered[l_sensorNumber[j]])
                           continue;
                        TRACFCOMP(g_trac_errl, INFO_MRK "sendErrLogToBmc:"
                            " sensor %.2x/%.2x event %x/%x, size %d",
                            l_sensorType[j], l_sensorNumber[j],
                            l_eventDirType[j], l_eventOffset[j], l_pelSize);

                        IPMISEL::sel_info_t *l_selEvent =
                                                   new(IPMISEL::sel_info_t);
                        l_selEvent->eventDirType = l_eventDirType[j];
                        l_selEvent->sensorNumber = l_sensorNumber[j];
                        l_selEvent->eventOffset  = l_eventOffset[j];
                        l_selEvent->sensorType   = l_sensorType[j];

                        // add to the list that goes out on the wire
                        l_selEventList.push_back(l_selEvent);

                        // make a note we've seen this sensor number before
                        l_sensorNumberEncountered[l_sensorNumber[j]] = true;
                    }
                } // for l_num_targets

            } // for l_callouts

            if (l_selEventList.size())
            {
                IPMISEL::sendESEL(l_pelData, l_pelSize,
                                    io_err->eid(),
                                    l_selEventList,
                                    l_callhome_type);
                TRACFCOMP(g_trac_errl, INFO_MRK
                "sendErrLogToBmc callout size %d",
                l_selEventList.size());
            }

        }
        else
        {
            // don't send sensor SELs
            TRACFCOMP(g_trac_errl, INFO_MRK
                    "sendErrLogToBmc: no sensor SELs, size %d", l_pelSize );
            l_selEventList.clear();
            IPMISEL::sel_info_t *l_selEvent = new (IPMISEL::sel_info_t);
            uint8_t l_eventDirType = IPMISEL::sensor_specific;
            uint8_t l_eventOffset = IPMISEL::event_data1_invalid_offset;

            l_selEvent->eventDirType = l_eventDirType;
            l_selEvent->sensorNumber = TARGETING::UTIL::INVALID_IPMI_SENSOR;
            l_selEvent->eventOffset  = l_eventOffset;
            l_selEvent->sensorType   = SENSOR::INVALID_TYPE;

            l_selEventList.push_back(l_selEvent);

            IPMISEL::sendESEL(l_pelData, l_pelSize, io_err->eid(),
                             l_selEventList, l_callhome_type);
        }

        // free the buffer
        delete [] l_pelData;

    } while(0);

    TRACFCOMP(g_trac_errl, EXIT_MRK "sendErrLogToBmc");
} // sendErrLogToBmc

uint8_t getSensorInfo(HWAS::callout_ud_t *i_ud,
                uint8_t* o_sensorNumber, uint8_t* o_eventOffset,
                         errlHndl_t &io_err )
{
    uint8_t l_num_sensors = 1;

    // reset the offset, we will test and configure it later
    *o_eventOffset = IPMISEL::event_data1_invalid_offset;

    if( i_ud->type == HWAS::PROCEDURE_CALLOUT )
    {
        // for procedure callouts
        *o_sensorNumber = TARGETING::UTIL::getSensorNumber(NULL,
                    TARGETING::SENSOR_NAME_SYSTEM_EVENT);

        // For procedure callout, will have EPUB ID's.This data will be part of
        // OEM SEL.
        *o_eventOffset = i_ud->procedure;
        TRACFCOMP(g_trac_errl,
                "getSensorInfo o_eventOffset %d o_sensorNumber %d",
                o_eventOffset,*o_sensorNumber);
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
        *o_sensorNumber = SENSOR::getBackPlaneFaultSensor();
    }
    else if (i_ud->type == HWAS::SENSOR_CALLOUT )
    {
         *o_sensorNumber = static_cast<uint8_t>(i_ud->sensorId);
    }
    else
    {
        // for all other types there will be at least
        // one target in the next user data section, we will use
        // that target to find the fault sensor.
        //
        // NOTE: if the provided target does not have a fault sensor, the
        // physical path will be used to determine the parent FRU which has
        // a fault sensor associated with it.
        uint8_t * l_uData = (uint8_t *)(i_ud + 1);
        TARGETING::Target *l_target = NULL;
        bool l_err = HWAS::retrieveTarget(l_uData, l_target, io_err);
        if (!l_err)
        {
            // got a target, now get the sensor number
            *o_sensorNumber = SENSOR::getFaultSensorNumber(l_target);
        }
        else
        {
            // couldnt expand the target so we are unable to get
            // a sensor number - use the event sensor for this one
            *o_sensorNumber = TARGETING::UTIL::getSensorNumber(NULL,
                    TARGETING::SENSOR_NAME_SYSTEM_EVENT);

            *o_eventOffset = SENSOR::UNDETERMINED_SYSTEM_HW_FAILURE;
        }
        if (i_ud->type == HWAS::BUS_CALLOUT)
        {
            l_err = HWAS::retrieveTarget(l_uData, l_target, io_err);
            if (!l_err)
            {
                o_sensorNumber[l_num_sensors] =
                                        SENSOR::getFaultSensorNumber(l_target);
                l_num_sensors++;
            }
        }
    }
    return l_num_sensors;
}

#endif // #ifndef __HOSTBOOT_RUNTIME

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
#endif // #ifdef CONFIG_BMC_IPMI

void ErrlManager::setErrlSkipFlag(errlHndl_t io_err)
{
    // Note: iv_skipShowingLog and iv_skipProcessingLog are set to true by
    //     default
    // See HIDDEN_ERRLOGS_ENABLE targeting enumeration for possible bitmask
    // values.

    // Check severity
    switch (io_err->sev())
    {
        case ERRORLOG::ERRL_SEV_INFORMATIONAL:

            // Check if we are allowing info logs through.
            if(  iv_hiddenErrLogsEnable
               & TARGETING::HIDDEN_ERRLOGS_ENABLE_ALLOW_INFORMATIONAL)
            {
                io_err->setSkipProcessingLog(false);
            }
            if(  iv_hiddenErrLogsEnable
               & TARGETING::HIDDEN_ERRLOGS_ENABLE_DISPLAY_INFORMATIONAL)
            {
                io_err->setSkipShowingLog(false);
            }
            break;

        case ERRORLOG::ERRL_SEV_RECOVERED:

            // Check if we are allowing recovered logs through.
            if(  iv_hiddenErrLogsEnable
               & TARGETING::HIDDEN_ERRLOGS_ENABLE_ALLOW_RECOVERED)
            {
                // Recovered error logs that are encountered
                // before targeting and initservice are loaded
                // will still be queued for sending to PNOR/BMC
                io_err->setSkipProcessingLog(false);
            }
            if(  iv_hiddenErrLogsEnable
               & TARGETING::HIDDEN_ERRLOGS_ENABLE_DISPLAY_RECOVERED)
            {
                // Recovered error logs that are encountered
                // before targeting and initservice are loaded
                // will still be queued for display
                io_err->setSkipShowingLog(false);
            }
            break;

        default:

            // For any error log that is not INFORMATIONAL
            // or RECOVERED, we want to process and display the log
            io_err->setSkipProcessingLog(false);
            io_err->setSkipShowingLog(false);
    }
} // setErrlSkipFlag

} // end namespace
