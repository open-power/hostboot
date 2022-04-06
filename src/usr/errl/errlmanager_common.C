/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errlmanager_common.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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

#include <pnor/pnorif.H>

#include <errl/errlentry.H>
#include <sys/mm.h>
#include <errl/errludstring.H>
#include <map>
#include <util/misc.H>
#include <util/utillidmgr.H>
#include <console/consoleif.H>
#include <errl/errlreasoncodes.H>
#include <targeting/common/targetservice.H>
#include <initservice/initserviceif.H>

#ifdef CONFIG_PLDM
#include <pldm/requests/pldm_fileio_requests.H>
#include <pldm/pldm_errl.H>
#endif

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

void errlCommitAllowExtraLogs(errlHndl_t& io_err, compId_t i_committerComp, bool i_keepTraces )
{
    ERRORLOG::theErrlManager::instance().commitErrAllowExtraLogs(io_err, i_committerComp, i_keepTraces );
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

// ------------------------------------------------------------------
// setupPnorInfo
// ------------------------------------------------------------------
void ErrlManager::setupPnorInfo()
{
    TRACFCOMP( g_trac_errl, ENTER_MRK"setupPnorInfo" );

    do
    {
        PNOR::SectionInfo_t info;

#if !defined(CONFIG_FSP_BUILD) || (defined(CONFIG_FSP_BUILD) && !defined(__HOSTBOOT_RUNTIME))
        // Get HB_ERRLOG PNOR section info from PNOR RP;
        // Only do that during IPL-time or at runtime for non-FSP systems. On
        // FSP systems, HB doesn't have access to PNOR at runtime.
        errlHndl_t err = PNOR::getSectionInfo( PNOR::HB_ERRLOGS, info );

        if (err)
        {
            TRACFCOMP( g_trac_errl, INFO_MRK"setupPnorInfo getSectionInfo failed");
            assert(err == NULL);
            break;
        }
#endif

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

#ifndef __HOSTBOOT_RUNTIME

        // walk thru memory, finding error logs and
        // determine the highest ID within the lower POST range of EIDs
        uint32_t l_maxId = 0;
        // If we find any HBRT EIDs, note the max EID number to pass to HBRT.
        iv_firstHbrtEid = ERRLOG_HBRT_EID_BASE;
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
                // if this is 'my' type of plid (HB) see if it's max
                if (((l_id & FIRST_BYTE_ERRLOG) == ERRLOG_PLID_BASE ) &&
                    (l_id > l_maxId ) &&
                    ((l_id & ERRLOG_PLID_MASK) <= ERRLOG_PLID_POST_MAX))
                {
                    l_maxId = l_id;

                    // set this - start at this 'max' slot so that our first
                    // save will increment correctly
                    iv_pnorOpenSlot = i;
                }

                // Check for the largest HBRT PLID
                if(((l_id & FIRST_BYTE_ERRLOG) == ERRLOG_HBRT_EID_BASE) &&
                   (l_id > iv_firstHbrtEid) &&
                   ((l_id & ERRLOG_PLID_MASK) <= ERRLOG_PLID_POST_MAX))
                {
                    iv_firstHbrtEid = l_id;
                }

                // also check if it's ACKed or not
                if (!isSlotACKed(i))
                {
                    TRACFCOMP( g_trac_errl,
                        INFO_MRK"setupPnorInfo slot %d eid %.8X was not ACKed.",
                        i, l_id);

#ifdef CONFIG_PLDM
                    // for BMC systems, unflatten to send down to the BMC
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

                        // trace the invalid log entry
                        uint32_t errlOffset = 0;
                        // divide invalid log into smaller chunks
                        const uint32_t LOG_CHUNCK_SIZE = PNOR_ERROR_LENGTH / 4;
                        while ((errlOffset+LOG_CHUNCK_SIZE) <= PNOR_ERROR_LENGTH)
                        {
                            TRACFCOMP(g_trac_errl, "Log bytes 0x%04X-0x%04X",
                                errlOffset, errlOffset+(LOG_CHUNCK_SIZE-1));
                            TRACFBIN( g_trac_errl, "Unflatten Log",
                                l_errlAddr+errlOffset, LOG_CHUNCK_SIZE );
                            errlOffset+=LOG_CHUNCK_SIZE;
                        }
                        // at least try to trace the bad entries SRC data
                        err->traceLogEntry();

                        // cleanup error log memory
                        delete err;
                        err = nullptr;

                        // set the ACK or this log will prevent future logs in PNOR
                        setACKInFlattened(i);
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
                        if (iv_isBmcInterfaceEnabled)
                        {
                            // send log to BMC and mark as previous boot error
                            bool sentSuccessful = sendErrLogToBmc(err, true);
                            if (!sentSuccessful)
                            {
                                TRACFCOMP(g_trac_errl,
                                    INFO_MRK"setupPnorInfo: Attempt to send previous boot error "
                                    "eid %.8X to BMC failed. Ignoring/Deleting error",
                                    l_id);
                            }
                            delete err;
                            err = nullptr;
                        }
                        else
                        {
                            TRACFCOMP( g_trac_errl,
                                INFO_MRK"setupPnorInfo pushing slot %d eid %.8X to iv_errList.",
                                i, l_id);
                            // Pair with BMC_PREV_ERR_FLAG to add to the errlList
                            // so that it'll get sent down when BMC interface is up
                            ErrlFlagPair_t l_pair(err, BMC_PREV_ERR_FLAG
#ifdef CONFIG_CONSOLE_OUTPUT_ERRORDISPLAY
                                                         | ERRLDISP_FLAG
#endif  // #ifdef CONFIG_CONSOLE_OUTPUT_ERRORDISPLAY
                                                 );
                            iv_errlList.push_back(l_pair);
                        }
                    }
#else  // #ifdef CONFIG_PLDM
                    // for FSP system, this shouldn't ever happen.
                    setACKInFlattened(i);
#endif // #else ... #ifdef CONFIG_PLDM
                } // not ACKed
            } // not empty
        } // for

        TRACFCOMP(g_trac_errl,
                  INFO_MRK"setupPnorInfo: the first HBRT EID is calculated to be 0x%x",
                  iv_firstHbrtEid);

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
    } while (!isSlotEmpty(iv_pnorOpenSlot) &&
             (!isSlotACKed(iv_pnorOpenSlot) ||
                 (isLastIplEid(iv_pnorOpenSlot) || isFirstHbrtEid(iv_pnorOpenSlot))) &&
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
                // Keep track of the last IPL-time EID
                if(io_err->eid() > getLastIplEid())
                {
                    setLastIplEid(io_err->eid());
                }
#endif // #ifndef __HOSTBOOT_RUNTIME
#ifndef CONFIG_FSP_BUILD
                // Flush RT logs
                PNOR::flush(PNOR::HB_ERRLOGS);
#endif // CONFIG_FSP_BUILD

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
        i_position, pSRC->src.word5,
        (pSRC->src.word5 & ErrlSrc::ACK_BIT) ? "not ACKed" : "ACKed");

    return (pSRC->src.word5 & ErrlSrc::ACK_BIT) ? false : true;
}

bool ErrlManager::doesEidMatch(const uint32_t i_position, const uint32_t i_eid)
{
    const char* l_pnorAddr = iv_pnorAddr + (PNOR_ERROR_LENGTH * i_position);
    const pelPrivateHeaderSection_t* l_privateHeaderSection =
            reinterpret_cast<const pelPrivateHeaderSection_t*>(l_pnorAddr);

    return (l_privateHeaderSection->eid == i_eid);
}

bool ErrlManager::isLastIplEid(const uint32_t i_position)
{
    return doesEidMatch(i_position, getLastIplEid());
}

bool ErrlManager::isFirstHbrtEid(const uint32_t i_position)
{
    return doesEidMatch(i_position, getFirstHbrtEid());
}

// setACKInFlattened()
void ErrlManager::setACKInFlattened(uint32_t i_position)
{
    char * l_pnorErrlAddr = iv_pnorAddr + (PNOR_ERROR_LENGTH * i_position);
    char * l_pnorAddr = l_pnorErrlAddr + sizeof(pelPrivateHeaderSection_t);
    l_pnorAddr += sizeof(pelUserHeaderSection_t);
    pelSRCSection_t *pSRC = reinterpret_cast<pelSRCSection_t *>(l_pnorAddr);

    pSRC->src.word5 &= ~(ErrlSrc::ACK_BIT);

    TRACDCOMP(g_trac_errl, "setACKInFlattened(%d): word5 %08x - %s",
        i_position, pSRC->src.word5,
        (pSRC->src.word5 & ErrlSrc::ACK_BIT) ? "not ACKed" : "ACKed");

#ifndef CONFIG_FSP_BUILD
    // Flush logs
    PNOR::flush(PNOR::HB_ERRLOGS);
#endif // CONFIG_FSP_BUILD

    return;
}


#ifdef CONFIG_PLDM

bool ErrlManager::sendErrLogToBmc(errlHndl_t &io_err, bool i_isPrevBootErr)
{
    assert(io_err != nullptr, "sendErrLogToBmc has nullptr error handle");

    TRACFCOMP(g_trac_errl, ENTER_MRK "sendErrLogToBmc errlogId 0x%.8X, i_isPrevBootErr %d",
                io_err->eid(), i_isPrevBootErr);

    bool l_errlSentAndAckd = false;

    uint32_t l_maxBmcErrLogSize = 0; // maximum allowable error log size
    uint32_t l_totalErrlSize = 0;    // actual flattened error log size

    do {
        // Add additional user detail section to pel data to indicate errl is
        // from a previous boot.
        if(i_isPrevBootErr)
        {
            const char* l_prev_boot = "Error from a previous boot";
            // Create a raw user-defined section.  It does a copy of the
            // string constant, then once added to io_err, io_err owns mem
            ErrlUD* l_ffdcSection = new ErrlUD(l_prev_boot, strlen(l_prev_boot),
                                         ERRL_COMP_ID, 1, ERRL_UDT_STRING );
            io_err->iv_SectionVector.insert(io_err->iv_SectionVector.begin(),
                                            l_ffdcSection);

            // we don't want any visible logs from this set of data because it is untrustworthy
            io_err->setSev(ERRL_SEV_INFORMATIONAL);

            // always try to send these previous errors to BMC (no skip check)
        }
        else
        {
            // Decide whether we want to skip the error log
            if( io_err->getSkipProcessingLog() )
            {
                TRACFCOMP( g_trac_errl, INFO_MRK
                    "sendErrLogToBmc: EID 0x%.8X is being skipped",
                    io_err->eid() );
                break;
            }
        }

        // Get this current log size and max allowable
        io_err->getErrlSize(l_totalErrlSize, l_maxBmcErrLogSize);

        if (l_totalErrlSize > l_maxBmcErrLogSize)
        {
            // need to truncate to max size
            l_totalErrlSize = l_maxBmcErrLogSize;
        }

        // flatten into buffer, truncate to max BMC errl transfer size
        std::vector<uint8_t> vPelData(l_totalErrlSize);

        uint32_t l_errSize = io_err->flatten(vPelData.data(),
                                             l_totalErrlSize, true /* truncate */);
        if (l_errSize == 0 )
        {
            // flatten didn't work
            TRACFCOMP( g_trac_errl, ERR_MRK
                "sendErrLogToBmc: could not flatten data - not sending");
            break;
        }
        if (l_errSize > l_maxBmcErrLogSize)
        {
            TRACFCOMP( g_trac_errl, ERR_MRK
                "sendErrLogToBmc: flatten truncated error size %d over max size %d",
                l_errSize, l_maxBmcErrLogSize );
            break;
        }

        errlHndl_t l_errl = PLDM::sendErrLog(io_err->eid(), vPelData.data(), l_errSize);
        if (l_errl)
        {
            TRACFCOMP( g_trac_errl, ERR_MRK
                "PLDM::sendErrLog() failed with eid=0x%.8X rc=0x%04X so stopping BMC PLDM error logging",
                l_errl->eid(), l_errl->reasonCode() );

            // stop sending error logs down to PLDM
            iv_isBmcInterfaceEnabled = false;

#ifndef __HOSTBOOT_RUNTIME
            // save off these trace variables
            const uint16_t rc = l_errl->reasonCode();
            const uint32_t eid = l_errl->eid();
#endif
            // commit this error to local memory and PNOR if possible
            commitErrLog(l_errl, ERRL_COMP_ID);

#ifndef __HOSTBOOT_RUNTIME
            CONSOLE::displayf(CONSOLE::DEFAULT, PLDM_COMP_NAME,
                "Unable to send error log 0x%.8X rc=0x%04X to BMC.  "
                "Shutting down with RC_PLDM_SEND_LOG_FAILED",
                eid, rc);
            INITSERVICE::doShutdown(RC_PLDM_SEND_LOG_FAILED, true /* background shutdown */);
#endif
        }
        else
        {
            // Set ACK bit in PNOR to identify this log as having been sent to BMC
            l_errlSentAndAckd = ackErrLogInPnor(io_err->eid());
        }

    } while (0);

    if (l_errlSentAndAckd)
    {
        TRACFCOMP(g_trac_errl,
              EXIT_MRK "sendErrLogToBmc errlogId 0x%.8X successfully sent",
              io_err->eid() );
    }
    else
    {
        TRACFCOMP(g_trac_errl,
              EXIT_MRK "sendErrLogToBmc errlogId 0x%.8X not sent completely",
              io_err->eid() );
    }

    return l_errlSentAndAckd;
}

#endif


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

void ErrlManager::commitErrAllowExtraLogs(errlHndl_t& io_err, compId_t i_committerComp, bool i_keepTraces )
{
    // To exploit this function the ErrlUD MUST be within the l_maxErrLogSize
    // e.g. if the l_maxErrLogSize is 4K, then the ErrlUD should already be no
    // greater than the 4K per addToLog, etc.
    //
    // Additional sections are added to error log during commit time
    // like backtrace, code level, etc...
    // (varies between 740 and 800 bytes)
    constexpr uint32_t COMMIT_ADDITIONAL_SECTIONS_SIZE = 800;

    // flatten into buffer, truncate to max eSEL size
    TARGETING::Target * sys = nullptr;
    TARGETING::targetService().getTopLevelTarget( sys );
    uint32_t l_maxErrLogSize;
    uint32_t l_totalErrlSize;

    do {
    if (!io_err)
    {
        TRACFCOMP( g_trac_errl, ERR_MRK"commitErrAllowExtraLogs: NULL Errl Object, "
            "unable to proceed, this is probably a code bug, see if someone committed logs "
            "and using a nullptr for the ERRL object");
        break;
    }
    // Get the current log size and max log size
    io_err->getErrlSize(l_totalErrlSize, l_maxErrLogSize);

    if (l_totalErrlSize > l_maxErrLogSize)
    {
        TRACFCOMP( g_trac_errl, INFO_MRK"commitErrAllowExtraLogs: PROCESSING LARGE ERRL "
            "l_totalErrlSize=%d l_maxErrLogSize=%d",
            l_totalErrlSize, l_maxErrLogSize);
        // Account for the sections added at commit time for each log
        if (l_maxErrLogSize > COMMIT_ADDITIONAL_SECTIONS_SIZE)
        {
            l_maxErrLogSize -= COMMIT_ADDITIONAL_SECTIONS_SIZE;
        }
        TRACDCOMP( g_trac_errl, INFO_MRK
                "commitErrAllowExtraLogs: size %d bytes > max size %d bytes",
                l_totalErrlSize, l_maxErrLogSize );

        std::vector<ErrlUD*> l_errlUDEntries =
            io_err->removeExcessiveUDsections(l_maxErrLogSize, i_keepTraces);

        uint16_t l_reasonCode = io_err->reasonCode();
        uint32_t l_plid = io_err->plid();

        // Keep track of additional logs so they can be committed later
        //  and EIDs added to the first original log
        std::vector<errlHndl_t>l_additional_logs;

        auto sectionVectorIt = l_errlUDEntries.begin();
        for (unsigned int i = 0; (i < MAX_EXTRA_LOGS_PER_ORIGINAL) && (sectionVectorIt != l_errlUDEntries.end()); i++)
        {
            // Create an informational error log and tie it to original error log
            /*@
             * @errortype
             * @moduleid     ERRORLOG::ERRL_COMMIT_EXTRA_LOGS_ID
             * @reasoncode   ERRORLOG::ERRL_EXTRA_LOG_RC
             * @userdata1    Original log reason code
             * @userdata2    Extra log number
             * @devdesc      Commit of extra data tied to original log
             * @custdesc     Additional data log for original log
             */
            errlHndl_t l_newErrl = new ERRORLOG::ErrlEntry(
                                      ERRL_SEV_INFORMATIONAL,
                                      ERRORLOG::ERRL_COMMIT_EXTRA_LOGS_ID,
                                      ERRORLOG::ERRL_EXTRA_LOG_RC,
                                      l_reasonCode,
                                      i);

            // Associate this new error log with the original one
            l_newErrl->plid(l_plid);

            // Note: l_maxErrLogSize will always accommodate initial flat size
            uint64_t l_sizeLeft = l_maxErrLogSize - l_newErrl->flattenedSize();

            // Add entries until no more UD sections or
            // error log can't hold another entry
            int l_entriesAdded = 0;
            while (l_sizeLeft && (sectionVectorIt != l_errlUDEntries.end()))
            {
                uint64_t l_udSize = (*sectionVectorIt)->flatSize();

                TRACDCOMP( g_trac_errl, INFO_MRK
                    "commitErrAllowExtraLogs: Current section size 0x%llX, "
                    "size left in error 0x%llX",
                    l_udSize, l_sizeLeft);

                if ( l_sizeLeft >= l_udSize )
                {
                    l_newErrl->addUDSection(*sectionVectorIt);
                    l_entriesAdded++;
                    sectionVectorIt++;

                    // Update how much size is left in error log
                    // after this section was added
                    l_sizeLeft -= l_udSize;
                }
                else
                {
                    TRACFCOMP( g_trac_errl, INFO_MRK"commitErrAllowExtraLogs: "
                        "Current section l_udSize=%llu "
                        "does NOT fit in the remaining space l_sizeLeft=%llu",
                        l_udSize, l_sizeLeft);
                    // Section doesn't fit in error log
                    break;
                }
            }
            if (l_entriesAdded)
            {
                // store this additional error log to commit later
                l_additional_logs.push_back(l_newErrl);
            }
            else
            {
                // just remove this error log as no entries added
                delete l_newErrl;
                l_newErrl = nullptr;
                break;
            }
        } // end FOR loop creating extra logs

        // Delete the non-committed UD sections left after extra logs
        while(sectionVectorIt != l_errlUDEntries.end())
        {
            TRACFCOMP( g_trac_errl, INFO_MRK"commitErrAllowExtraLogs: "
                "DELETING non-committed UD sections, "
                "this MAY or MAY NOT be a PROBLEM, CHECK logs "
                "for indication of NO EXTRA LOGS produced");
            // Remove the ErrlUD* at this position
            delete (*sectionVectorIt);

            // Erase this entry from the vector and go to next one
            sectionVectorIt = l_errlUDEntries.erase(sectionVectorIt);
        }

        // Add a user data section to keep track of additional logs associated
        // with original error.  Note: using EID since eBMC may change plid
        char l_log_count_str[150];
        sprintf(l_log_count_str, "%d additional module 0x%02X rc 0x%04X logs associated with this error:",
            l_additional_logs.size(), ERRORLOG::ERRL_COMMIT_EXTRA_LOGS_ID, ERRORLOG::ERRL_EXTRA_LOG_RC);
        for (auto extraLog : l_additional_logs)
        {
            sprintf(l_log_count_str+strlen(l_log_count_str), " 0x%08X", extraLog->eid());
        }
        ErrlUD* l_ffdcSection = new ErrlUD(l_log_count_str, strlen(l_log_count_str), ERRL_COMP_ID, 1, ERRL_UDT_STRING);
        io_err->addUDSection(l_ffdcSection);
        commitErrLog(io_err, i_committerComp);

        // now commit the additional logs
        for (auto extraLog : l_additional_logs)
        {
            commitErrLog(extraLog, i_committerComp);
        }
    }
    else
    {
        // just commit this error log (no need for extra logs)
        TRACFCOMP( g_trac_errl, INFO_MRK"commitErrAllowExtraLogs: No Extra Logs committed, "
                "the l_maxErrLogSize allowed is %d but the log requested is l_totalErrlSize=%d",
                l_totalErrlSize, l_maxErrLogSize );
        commitErrLog(io_err, i_committerComp);
    }
    } while (0);
}

///////////////////////////////////////////////////////////////////////////////
// Global function (not a method on an object) to get the MI Keyword from the
// Marker LID via the PLDM file input/output framework,
errlHndl_t ErrlManager::getMarkerLidMiKeyword(size_t &io_bufferSize, char* const o_buffer)
{
    errlHndl_t l_err(nullptr);

#ifdef CONFIG_PLDM

    do
    {
        ////////////////////////////////////////////////////////////////////////
        /// Get the Marker Lid Header from via the PLDM::getLidFileFromOffset call
        ////////////////////////////////////////////////////////////////////////
        // Set up the Marker Lid file handler
        uint32_t l_fileHandle(Util::MARKER_LIDID);

        // Set up variables to read the Marker Lid Header
        uint32_t l_offset(0);
        uint32_t l_markerLidHeaderSize = sizeof(markerHeader_t);

        // Create a unique pointer for the Marker Lid Header for auto cleanup
        // and clear the memory via calloc
        std::unique_ptr<markerHeader_t, decltype(free)*> l_markerLidHeader{
            static_cast<markerHeader_t*>(calloc(l_markerLidHeaderSize, sizeof(uint8_t))),
            free};

        // Get the Marker Lid Header Info
        l_err = PLDM::getLidFileFromOffset(l_fileHandle, l_offset, l_markerLidHeaderSize,
                                           reinterpret_cast<uint8_t*>(l_markerLidHeader.get()));

        if (l_err)
        {
            TRACFCOMP( g_trac_errl, ERR_MRK"ErrlManager::getMarkerLidMiKeyword(): "
                       "PLDM::getLidFileFromOffset() Failed to retrieve the Marker lid header");
            break;
        }

        ////////////////////////////////////////////////////////////////////////
        /// Get the MI Keyword Section from the Marker LID via the PLDM::getLidFileFromOffset call
        ////////////////////////////////////////////////////////////////////////
        // Set up variables to read the MI Keyword Section
        l_offset = l_markerLidHeader->MIKeyWordOffset;
        uint32_t l_markerMiSize = sizeof(markerMI_t);

        // Create a unique pointer for the MI Keyword Section for auto cleanup
        // and clear the memory via calloc
        std::unique_ptr<markerMI_t, decltype(free)*> l_markerMi{
            static_cast<markerMI_t*>(calloc(l_markerMiSize, sizeof(uint8_t))),
            free};

        // Get the MI keyword section from the Marker Lid
        l_err = PLDM::getLidFileFromOffset(l_fileHandle, l_offset, l_markerMiSize,
                                           reinterpret_cast<uint8_t*>(l_markerMi.get()) );
        if (l_err)
        {
            TRACFCOMP( g_trac_errl, ERR_MRK"ErrlManager::getMarkerLidMiKeyword(): "
                       "PLDM::getLidFileFromOffset() Failed to retrieve the MI keyword section");
            break;
        }

        // If no buffer size given, then the caller is asking for the buffer size
        // of the MI keyword
        if (!io_bufferSize)
        {
            io_bufferSize = l_markerMi->MIKeyWordSize;
            TRACFCOMP( g_trac_errl, INFO_MRK"ErrlManager::getMarkerLidMiKeyword(): "
                       "Returning the MI keyword size (%d) to caller", io_bufferSize);
            break;
        }

        ////////////////////////////////////////////////////////////////////////
        /// Do some sanity checks on the size of buffer (io_bufferSize) and
        /// the buffer (o_buffer) itself
        ////////////////////////////////////////////////////////////////////////
        // If buffer size is less than the size of the MI keyword then return back an error
        if (io_bufferSize < l_markerMi->MIKeyWordSize)
        {
            TRACFCOMP( g_trac_errl, ERR_MRK"ErrlManager::getMarkerLidMiKeyword(): "
                       "Buffer size(%d) is insufficient to contain the MI keyword with size(%d)",
                       io_bufferSize, l_markerMi->MIKeyWordSize );

            /*@
             * @errortype
             * @moduleid   ERRL_GET_MARKER_LID_MI_KEYWORD
             * @reasoncode ERRL_MARKER_LID_INVALID_BUFFER_SIZE
             * @userdata1  Size of the buffer the caller provided
             * @userdata2  Size of MI keyword, the minimum size needed for the buffer
             * @devdesc    The size of the buffer is insufficient to contain the MI keyword
             * @custdesc   A host failure occurred
             */
            l_err = new ErrlEntry( ERRL_SEV_UNRECOVERABLE,
                                   ERRL_GET_MARKER_LID_MI_KEYWORD,
                                   ERRL_MARKER_LID_INVALID_BUFFER_SIZE,
                                   io_bufferSize,
                                   l_markerMi->MIKeyWordSize,
                                   ErrlEntry::NO_SW_CALLOUT);

            PLDM::addBmcErrorCallouts(l_err);
            break;
        }

        // If the buffer is a nullptr, then return an error
        if (!o_buffer)
        {
            TRACFCOMP( g_trac_errl, ERR_MRK"ErrlManager::getMarkerLidMiKeyword(): "
                       "Buffer size(%d) is not 0 but provided buffer is a nullptr",
                       io_bufferSize);

            /*@
             * @errortype
             * @moduleid   ERRL_GET_MARKER_LID_MI_KEYWORD
             * @reasoncode ERRL_MARKER_LID_INVALID_BUFFER
             * @userdata1  Size of the buffer the caller provided
             * @userdata2  unused
             * @devdesc    The size of the buffer is not 0 but buffer is a nullptr
             * @custdesc   A host failure occurred
             */
            l_err = new ErrlEntry( ERRL_SEV_UNRECOVERABLE,
                                   ERRL_GET_MARKER_LID_MI_KEYWORD,
                                   ERRL_MARKER_LID_INVALID_BUFFER,
                                   io_bufferSize,
                                   0,
                                   ErrlEntry::ADD_SW_CALLOUT);
            break;
        }

        ////////////////////////////////////////////////////////////////////////
        /// Copy the MI keyword into the out going buffer (o_buffer) and send back to caller
        ////////////////////////////////////////////////////////////////////////
        // Clear the outgoing buffer for good measure, before setting the buffer size
        memset(o_buffer, 0, io_bufferSize);
        // Set the outgoing size to the actual size of the MI keyword
        io_bufferSize = l_markerMi->MIKeyWordSize;
        // Copy contents from MI keyword to callers buffer
        memcpy(o_buffer, l_markerMi->MIKeyword, io_bufferSize);
    }
    while (0);

#else // #ifdef CONFIG_PLDM
    // Considering that the PLDM framework is being used to get the MI Keyword,
    // if the framework is not available then zero out the outgoing data
    if (o_buffer)
    {
        memset(o_buffer, 0, io_bufferSize);
    }
    io_bufferSize = 0;
#endif // #ifdef CONFIG_PLDM ... #else

    return l_err;
} // ErrlManager::getMarkerLidMiKeyword

uint32_t ErrlManager::_getFirstHbrtEid()
{
    return iv_firstHbrtEid;
}

uint32_t ErrlManager::getFirstHbrtEid()
{
    return ERRORLOG::theErrlManager::instance()._getFirstHbrtEid();
}

#ifndef __HOSTBOOT_RUNTIME
uint32_t ErrlManager::_getLastIplEid()
{
    return iv_lastIplEid;
}
#endif

uint32_t ErrlManager::getLastIplEid()
{
#ifndef __HOSTBOOT_RUNTIME
    return ERRORLOG::theErrlManager::instance()._getLastIplEid();
#else
    return TARGETING::UTIL::assertGetToplevelTarget()->getAttr<TARGETING::ATTR_LAST_IPLTIME_EID>();
#endif
}

#ifndef __HOSTBOOT_RUNTIME
void ErrlManager::_setLastIplEid(const uint32_t i_eid)
{
    iv_lastIplEid = i_eid;
}
#endif

#ifndef __HOSTBOOT_RUNTIME
void ErrlManager::setLastIplEid(const uint32_t i_eid)
{
    ERRORLOG::theErrlManager::instance()._setLastIplEid(i_eid);
    if(Util::isTargetingLoaded())
    {
        TARGETING::UTIL::assertGetToplevelTarget()->setAttr<TARGETING::ATTR_LAST_IPLTIME_EID>(i_eid);
    }
}
#endif

} // end namespace
