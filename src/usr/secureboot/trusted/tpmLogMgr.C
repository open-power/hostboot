/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/tpmLogMgr.C $                      */
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
/**
 * @file TpmLogMgr.C
 *
 * @brief TPM Event log manager
 */

/////////////////////////////////////////////////////////////////
// NOTE: This file is exportable as TSS-Lite for skiboot/PHYP  //
/////////////////////////////////////////////////////////////////

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <string.h>
#include <endian.h>
#include "tpmLogMgr.H"
#ifdef __HOSTBOOT_MODULE
#include <sys/mm.h>
#include <util/align.H>
#include <secureboot/trustedboot_reasoncodes.H>
#else
#include "trustedboot_reasoncodes.H"
#endif
#include "trustedbootUtils.H"
#include "trustedboot.H"
#include "trustedTypes.H"

#ifdef __cplusplus
namespace TRUSTEDBOOT
{
#endif

    uint32_t TCG_EfiSpecIdEventStruct_size(TCG_EfiSpecIdEventStruct* val)
    {
        return (sizeof(TCG_EfiSpecIdEventStruct) + val->vendorInfoSize);
    }

#ifdef __HOSTBOOT_MODULE
    errlHndl_t TpmLogMgr_initialize(TpmLogMgr* i_val)
    {
        errlHndl_t err = TB_SUCCESS;
        const char vendorInfo[] = "IBM";
        const char eventSignature[] = "Spec ID Event03";
        TCG_EfiSpecIdEventStruct* eventData = NULL;

        TCG_PCR_EVENT eventLogEntry;

        TRACUCOMP( g_trac_trustedboot, ">>initialize()");

        if (NULL == i_val)
        {
            TRACFCOMP( g_trac_trustedboot,
                       "TPM LOG INIT FAIL");

                /*@
                 * @errortype
                 * @reasoncode     RC_TPMLOGMGR_INIT_FAIL
                 * @severity       ERRL_SEV_UNRECOVERABLE
                 * @moduleid       MOD_TPMLOGMGR_INITIALIZE
                 * @userdata1      0
                 * @userdata2      0
                 * @devdesc        TPM log buffer init failure.
                 * @custdesc       TPM log buffer init failure.
                 */
                err = tpmCreateErrorLog( MOD_TPMLOGMGR_INITIALIZE,
                                         RC_TPMLOGMGR_INIT_FAIL, 0, 0);

        }
        else
        {

            memset(i_val, 0, sizeof(TpmLogMgr));
            i_val->logMaxSize = TPMLOG_BUFFER_SIZE;

            mutex_init( &i_val->logMutex );
            mutex_lock( &i_val->logMutex );

            // Assign our new event pointer to the start
            i_val->newEventPtr = i_val->eventLog;
            memset(i_val->eventLog, 0, TPMLOG_BUFFER_SIZE);

            memset(&eventLogEntry, 0, sizeof(eventLogEntry));
            eventData = (TCG_EfiSpecIdEventStruct*) eventLogEntry.event;

            // Add the header event log
            // Values here come from the PC ClientSpecificPlatformProfile spec
            eventLogEntry.eventType = EV_NO_ACTION;
            eventLogEntry.pcrIndex = 0;
            eventLogEntry.eventSize = sizeof(TCG_EfiSpecIdEventStruct) +
                sizeof(vendorInfo);

            memcpy(eventData->signature, eventSignature,
                   sizeof(eventSignature));
            eventData->platformClass = htole32(TPM_PLATFORM_SERVER);
            eventData->specVersionMinor = TPM_SPEC_MINOR;
            eventData->specVersionMajor = TPM_SPEC_MAJOR;
            eventData->specErrata = TPM_SPEC_ERRATA;
            eventData->uintnSize = 1;
            eventData->numberOfAlgorithms = htole32(HASH_COUNT);
            eventData->digestSizes[0].algorithmId = htole16(TPM_ALG_SHA256);
            eventData->digestSizes[0].digestSize = htole16(TPM_ALG_SHA256_SIZE);
            eventData->digestSizes[1].algorithmId = htole16(TPM_ALG_SHA1);
            eventData->digestSizes[1].digestSize = htole16(TPM_ALG_SHA1_SIZE);
            eventData->vendorInfoSize = sizeof(vendorInfo);
            memcpy(eventData->vendorInfo, vendorInfo, sizeof(vendorInfo));
            i_val->newEventPtr = TCG_PCR_EVENT_logMarshal(&eventLogEntry,
                                                          i_val->newEventPtr);

            // Done, move our pointers
            i_val->logSize += TCG_PCR_EVENT_marshalSize(&eventLogEntry);

            mutex_unlock( &i_val->logMutex );

            // Debug display of raw data
            TRACUBIN(g_trac_trustedboot, "tpmInitialize: Header Entry",
                     i_val->eventLog, i_val->logSize);

            TRACUCOMP( g_trac_trustedboot,
                       "<<initialize() LS:%d - %s",
                       i_val->logSize,
                       ((TB_SUCCESS == err) ? "No Error" : "With Error") );
        }
        return err;
    }
#endif

    errlHndl_t TpmLogMgr_initializeUsingExistingLog(TpmLogMgr* i_val,
                                                    uint8_t* i_eventLogPtr,
                                                    uint32_t i_eventLogSize)
    {
        errlHndl_t err = TB_SUCCESS;
        TRACUCOMP( g_trac_trustedboot,
                   ">>initializeUsingExistingLog()");

        do
        {

            mutex_init( &i_val->logMutex );
            mutex_lock( &i_val->logMutex );

            i_val->logMaxSize = i_eventLogSize;
            i_val->eventLogInMem = i_eventLogPtr;

            // Ok, walk the log to figure out how big this is
            i_val->logSize = TpmLogMgr_calcLogSize(i_val);

            if (0 == i_val->logSize)
            {
                TRACFCOMP( g_trac_trustedboot,
                       "TPM LOG INIT WALK FAIL");
                /*@
                 * @errortype
                 * @reasoncode     RC_TPMLOGMGR_LOGWALKFAIL
                 * @severity       ERRL_SEV_UNRECOVERABLE
                 * @moduleid       MOD_TPMLOGMGR_INITIALIZEEXISTLOG
                 * @userdata1      0
                 * @userdata2      0
                 * @devdesc        TPM log header entry is missing.
                 * @custdesc       TPM log invalid format
                 */
                err = tpmCreateErrorLog(MOD_TPMLOGMGR_INITIALIZEEXISTLOG,
                                        RC_TPMLOGMGR_LOGWALKFAIL,
                                        0,
                                        0);
                break;
            }
            // We are good, let's move the newEventLogPtr
            i_val->newEventPtr = i_val->eventLogInMem + i_val->logSize;

        }
        while(0);

        if (TB_SUCCESS != err)
        {
            i_val->eventLogInMem = NULL;
            i_val->newEventPtr = NULL;
            i_val->logMaxSize = 0;
            i_val->logSize = 0;
        }

        mutex_unlock( &i_val->logMutex );

        return err;
    }

    errlHndl_t TpmLogMgr_addEvent(TpmLogMgr* i_val,
                                  TCG_PCR_EVENT2* i_logEvent)
    {
        errlHndl_t err = TB_SUCCESS;
        size_t newLogSize = TCG_PCR_EVENT2_marshalSize(i_logEvent);

        TRACUCOMP( g_trac_trustedboot,
                   ">>tpmAddEvent() PCR:%d Type:%d Size:%d. "
                   "(Current LS(%d) Max LS(%d))",
                   i_logEvent->pcrIndex,
                   i_logEvent->eventType,
                   static_cast<int>(newLogSize),
                   static_cast<int>(i_val->logSize),
                   static_cast<int>(i_val->logMaxSize));

        mutex_lock( &i_val->logMutex );

        do
        {
            // Need to ensure we have room for the new event
            // We have to leave room for the log full event as well
            if ((NULL == i_val->newEventPtr) ||
                (i_val->logSize + newLogSize > i_val->logMaxSize) ||
                (newLogSize > MAX_TPM_LOG_MSG))
            {
                TRACFCOMP( g_trac_trustedboot,
                           "TPM LOG ADD FAIL PNULL(%d) LS(%d) New LS(%d)"
                           " Max LS(%d) Max LMS(%d)",
                           (NULL == i_val->newEventPtr ? 0 : 1),
                           (int)i_val->logSize, (int)newLogSize,
                           (int)i_val->logMaxSize, MAX_TPM_LOG_MSG);

                /*@
                 * @errortype
                 * @reasoncode     RC_TPMLOGMGR_ADDEVENT_FAIL
                 * @severity       ERRL_SEV_UNRECOVERABLE
                 * @moduleid       MOD_TPMLOGMGR_ADDEVENT
                 * @userdata1[0:31]  Max log size
                 * @userdata1[32:63] Log buffer NULL
                 * @userdata2[0:15]  Current Log Size
                 * @userdata2[16:31] Max TPM Log Message Size
                 * @userdata2[32:63] New entry size
                 * @devdesc        TPM log buffer add failure.
                 * @custdesc       TPM log overflow
                 */
                err = tpmCreateErrorLog( MOD_TPMLOGMGR_ADDEVENT,
                                         RC_TPMLOGMGR_ADDEVENT_FAIL,
                                         static_cast<uint64_t>(
                                           i_val->logMaxSize) << 32 |
                                         (NULL == i_val->newEventPtr ? 0 : 1),
                                         TWO_UINT16_ONE_UINT32_TO_UINT64(
                                           static_cast<uint16_t>(
                                             i_val->logSize),
                                           MAX_TPM_LOG_MSG,
                                           newLogSize));

                break;
            }

            i_val->newEventPtr = TCG_PCR_EVENT2_logMarshal(i_logEvent,
                                                           i_val->newEventPtr);

            if (NULL == i_val->newEventPtr)
            {
                TRACFCOMP( g_trac_trustedboot,
                           "TPM LOG MARSHAL Fail");

                /*@
                 * @errortype
                 * @reasoncode     RC_TPMLOGMGR_ADDEVENTMARSH_FAIL
                 * @severity       ERRL_SEV_UNRECOVERABLE
                 * @moduleid       MOD_TPMLOGMGR_ADDEVENT
                 * @userdata1      0
                 * @userdata2      0
                 * @devdesc        log buffer marshal failure.
                 * @custdesc       TPM log operation failure
                 */
                err = tpmCreateErrorLog( MOD_TPMLOGMGR_ADDEVENT,
                                         RC_TPMLOGMGR_ADDEVENTMARSH_FAIL,
                                         0,
                                         0);
                break;
            }

            i_val->logSize += newLogSize;


        } while ( 0 );

        TRACUCOMP( g_trac_trustedboot,
                   "<<tpmAddEvent() LS:%d - %s",
                   (int)i_val->logSize,
                   ((TB_SUCCESS == err) ? "No Error" : "With Error") );

        mutex_unlock( &i_val->logMutex );
        return err;
    }

    uint32_t TpmLogMgr_getLogSize(TpmLogMgr* i_val)
    {
        return i_val->logSize;
    }

    void TpmLogMgr_dumpLog(TpmLogMgr* i_val)
    {

        // Debug display of raw data
        TRACUCOMP(g_trac_trustedboot, "tpmDumpLog Size : %d",
                  (int)i_val->logSize);

#ifdef __HOSTBOOT_MODULE
        // Debug display of raw data
        if (NULL == i_val->eventLogInMem)
        {
            TRACUBIN(g_trac_trustedboot, "tpmDumpLog",
                     i_val->eventLog, i_val->logSize);
        }
        else
        {
#endif
            TRACUBIN(g_trac_trustedboot, "tpmDumpLog From Memory",
                     i_val->eventLogInMem, i_val->logSize);
#ifdef __HOSTBOOT_MODULE
        }
#endif
    }

    uint32_t TpmLogMgr_calcLogSize(TpmLogMgr* i_val)
    {
        uint32_t logSize = 0;
        TCG_PCR_EVENT event;
        TCG_PCR_EVENT2 event2;
        bool errorFound = false;
        const uint8_t* prevLogHandle = NULL;
        const uint8_t* nextLogHandle = NULL;

        TRACUCOMP( g_trac_trustedboot, ">>calcLogSize");

        // Start walking events
        prevLogHandle = TpmLogMgr_getLogStartPtr(i_val);
        do
        {

            // First need to deal with the header entry
            nextLogHandle = TCG_PCR_EVENT_logUnmarshal(&event,
                                                       prevLogHandle,
                                                       sizeof(TCG_PCR_EVENT),
                                                       &errorFound);

            if (NULL == nextLogHandle || errorFound ||
                EV_NO_ACTION != event.eventType ||
                0 == event.eventSize)
            {
                TRACFCOMP( g_trac_trustedboot, "Header Marshal Failure");
                prevLogHandle = NULL;
                break;
            }

            if (( nextLogHandle - TpmLogMgr_getLogStartPtr(i_val)) >
                i_val->logMaxSize)
            {
                TRACFCOMP( g_trac_trustedboot, "calcLogSize overflow");
                prevLogHandle = NULL;
                break;
            }
            prevLogHandle = nextLogHandle;

            // Now iterate through all the other events
            while (NULL != prevLogHandle)
            {
                nextLogHandle = TCG_PCR_EVENT2_logUnmarshal(
                                               &event2,
                                               prevLogHandle,
                                               sizeof(TCG_PCR_EVENT2),
                                               &errorFound);
                if (NULL == nextLogHandle || errorFound)
                {
                    // Failed parsing so we must have hit the end of log
                    break;
                }
                if (( nextLogHandle - TpmLogMgr_getLogStartPtr(i_val)) >
                    i_val->logMaxSize)
                {
                    TRACFCOMP( g_trac_trustedboot, "calcLogSize overflow");
                    prevLogHandle = NULL;
                    break;
                }
                prevLogHandle = nextLogHandle;
            }
        }
        while (0);

        if (NULL == prevLogHandle)
        {
            logSize = 0;
        }
        else
        {
            logSize = (prevLogHandle - TpmLogMgr_getLogStartPtr(i_val));
        }
        TRACUCOMP( g_trac_trustedboot, "<<calcLogSize : %d", logSize);

        return logSize;
    }

    const uint8_t* TpmLogMgr_getFirstEvent(TpmLogMgr* i_val)
    {
        TCG_PCR_EVENT event;
        bool err = false;
        const uint8_t* result = NULL;

        // Header event in the log is always first, we skip over that
        const uint8_t* firstEvent = TpmLogMgr_getLogStartPtr(i_val);
        memset(&event, 0, sizeof(TCG_PCR_EVENT));

        firstEvent = TCG_PCR_EVENT_logUnmarshal(&event, firstEvent,
                                                sizeof(TCG_PCR_EVENT),
                                                &err);
        if (NULL != firstEvent && !err &&
            firstEvent < i_val->newEventPtr)
        {
            result = firstEvent;
        }

        return result;
    }

    const uint8_t* TpmLogMgr_getNextEvent(TpmLogMgr* i_val,
                                          const uint8_t* i_handle,
                                          TCG_PCR_EVENT2* i_eventLog,
                                          bool* o_err)
    {
        const uint8_t* l_resultPtr = NULL;
        if (NULL == i_handle)
        {
            *o_err = true;
        }
        else
        {
            memset(i_eventLog, 0, sizeof(TCG_PCR_EVENT2));
            TRACUCOMP( g_trac_trustedboot, "TPM getNextEvent 0x%p", i_handle);
            l_resultPtr = TCG_PCR_EVENT2_logUnmarshal(i_eventLog, i_handle,
                                                      sizeof(TCG_PCR_EVENT2),
                                                      o_err);
            if (NULL == l_resultPtr)
            {
                // An error was detected, ensure o_err is set
                *o_err = true;
            }
            else if (l_resultPtr >= i_val->newEventPtr)
            {
                l_resultPtr = NULL;
            }
        }

        return l_resultPtr;
    }

    TCG_PCR_EVENT2 TpmLogMgr_genLogEventPcrExtend(TPM_Pcr i_pcr,
                                                  EventTypes i_eventType,
                                                  TPM_Alg_Id i_algId_1,
                                                  const uint8_t* i_digest_1,
                                                  size_t i_digestSize_1,
                                                  TPM_Alg_Id i_algId_2,
                                                  const uint8_t* i_digest_2,
                                                  size_t i_digestSize_2,
                                                  const uint8_t* i_logMsg,
                                                  const size_t i_logMsgSize)
    {
        TCG_PCR_EVENT2 eventLog;
        size_t fullDigestSize_1 = 0;
        size_t fullDigestSize_2 = 0;

        fullDigestSize_1 = getDigestSize(i_algId_1);
        if (NULL != i_digest_2)
        {
            fullDigestSize_2 = getDigestSize(i_algId_2);
        }

        memset(&eventLog, 0, sizeof(eventLog));
        eventLog.pcrIndex = i_pcr;
        eventLog.eventType = i_eventType;

        // Update digest information
        eventLog.digests.count = 1;
        eventLog.digests.digests[0].algorithmId = i_algId_1;
        memcpy(&(eventLog.digests.digests[0].digest),
               i_digest_1,
               (i_digestSize_1 < fullDigestSize_1 ?
                i_digestSize_1 : fullDigestSize_1));

        if (NULL != i_digest_2)
        {
            eventLog.digests.count = 2;
            eventLog.digests.digests[1].algorithmId = i_algId_2;
            memcpy(&(eventLog.digests.digests[1].digest),
                   i_digest_2,
                   (i_digestSize_2 < fullDigestSize_2 ?
                    i_digestSize_2 : fullDigestSize_2));
        }
        // Event field data
        eventLog.event.eventSize = i_logMsgSize;
        memset(eventLog.event.event, 0, sizeof(eventLog.event.event));
        memcpy(eventLog.event.event, i_logMsg,
               (i_logMsgSize > MAX_TPM_LOG_MSG ?
                MAX_TPM_LOG_MSG : i_logMsgSize));

        return eventLog;
    }


    uint8_t* TpmLogMgr_getLogStartPtr(TpmLogMgr* i_val)
    {
#ifdef __HOSTBOOT_MODULE
        return (i_val->eventLogInMem == NULL ?
           reinterpret_cast<uint8_t*>(&(i_val->eventLog)) :
                i_val->eventLogInMem);
#else
        return i_val->eventLogInMem;
#endif
    }

#ifdef __HOSTBOOT_MODULE
    errlHndl_t TpmLogMgr_getDevtreeInfo(TpmLogMgr* i_val,
                                        uint64_t & io_logAddr,
                                        size_t & o_allocationSize,
                                        uint64_t & o_xscomAddr,
                                        uint32_t & o_spiControllerOffset)
    {
        errlHndl_t err = NULL;

        mutex_lock( &i_val->logMutex );

        assert(io_logAddr != 0, "Invalid starting log address");
        assert(i_val->eventLogInMem == NULL,
               "getDevtreeInfo can only be called once");

        io_logAddr -= ALIGN_PAGE(TPMLOG_DEVTREE_SIZE);
        // Align to 64KB for Opal
        io_logAddr = ALIGN_DOWN_X(io_logAddr,64*KILOBYTE);

        i_val->inMemlogBaseAddr = io_logAddr;
        o_allocationSize = TPMLOG_DEVTREE_SIZE;
        o_xscomAddr = i_val->devtreeXscomAddr;
        o_spiControllerOffset = i_val->devtreeSpiControllerOffset;

        // Copy image.
        i_val->eventLogInMem = (uint8_t*)(mm_block_map(
                                 (void*)(io_logAddr),
                                 ALIGN_PAGE(TPMLOG_DEVTREE_SIZE)));
        // Copy log into new location
        memset(i_val->eventLogInMem, 0, TPMLOG_DEVTREE_SIZE);
        memcpy(i_val->eventLogInMem, i_val->eventLog, i_val->logSize);
        i_val->newEventPtr = i_val->eventLogInMem + i_val->logSize;

        mutex_unlock( &i_val->logMutex );

        TRACUCOMP( g_trac_trustedboot,
                   "<<getDevtreeInfo() Addr:%lX - %s",
                   io_logAddr,
                   ((TB_SUCCESS == err) ? "No Error" : "With Error") );
        return err;
    }


    void TpmLogMgr_setTpmDevtreeInfo(TpmLogMgr* i_val,
                                     uint64_t i_xscomAddr,
                                     uint32_t i_spiControllerOffset)
    {
        i_val->devtreeXscomAddr = i_xscomAddr;
        i_val->devtreeSpiControllerOffset = i_spiControllerOffset;
    }

    void TpmLogMgr_relocateTpmLog(TpmLogMgr* i_val,
                                  uint8_t* i_newLog,
                                  size_t i_maxSize)
    {
        mutex_lock( &i_val->logMutex );

        TRACUCOMP( g_trac_trustedboot,
                   ">>relocateTpmLog() LogSize:%d MaxSize:%d",
                   i_val->logSize, i_maxSize);

        assert(i_newLog != NULL, "Bug! Log start address is nullptr");
        assert(i_val->logSize < i_maxSize,
               "Logsize is greater than maxsize");

        if(i_val->eventLogInMem)
        {
            // The log had been expanded previously. Need to copy over the log
            // memory to the new location and delete the pointer before
            // reassigning
            memcpy(i_newLog, i_val->eventLogInMem, i_val->logSize);
            delete[](i_val->eventLogInMem);
            i_val->eventLogInMem = i_newLog;
        }
        else
        {
            // Point logMgr to new location
            i_val->eventLogInMem = i_newLog;

            // Copy log into new location
            memset(i_val->eventLogInMem, 0, i_maxSize);
            memcpy(i_val->eventLogInMem, i_val->eventLog, i_val->logSize);
        }

        i_val->newEventPtr = i_val->eventLogInMem + i_val->logSize;
        i_val->logMaxSize = i_maxSize;

        mutex_unlock( &i_val->logMutex );

        TRACUCOMP( g_trac_trustedboot,
                   "<<relocateTpmLog() Addr:%p",
                   i_newLog);
        return;
    }


#endif

#ifdef __cplusplus
} // end TRUSTEDBOOT
#endif
