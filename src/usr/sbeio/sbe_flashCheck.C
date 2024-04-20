/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_flashCheck.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023,2024                        */
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
 * @file sbe_flashCheck.C
 * @brief This file contains the implementations of the
 *        SPPE SPI flash check messaging
 */

#include "sbe_fifodd.H"
#include <sbeio/sbeioif.H>
#include <sbeio/sbeioreasoncodes.H>
#include <ocmbupd/ody_upd_fsm.H>
#include <errl/errludstring.H>
#include <errl/hberrltypes.H>
#include <targeting/common/mfgFlagAccessors.H>

using namespace TARGETING;
using namespace ERRORLOG;
using namespace ocmbupd;
using namespace errl_util;

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACF(printf_string,args...) \
            TRACFCOMP(g_trac_sbeio, printf_string,##args)
#define SBE_TRACD(printf_string,args...) \
            TRACDCOMP(g_trac_sbeio, printf_string,##args)
#define SBE_TRACFBIN(printf_string,args...) \
            TRACFBIN(g_trac_sbeio, printf_string,##args)


namespace SBEIO
{

struct flashErrorInfo
{
    uint8_t side;
    uint8_t deviceId;
    uint16_t numCe; // The number of Correctable Errors (CE)
    uint16_t numUe; // The number of Unrecoverable Errors (UE)
} PACKED;

errlHndl_t makeFlashErrl(Target* i_ocmb,
                         bool i_side0Fail,
                         bool i_side1Fail,
                         bool i_goldenFail,
                         const std::vector<flashErrorInfo>& i_side0Errors,
                         const std::vector<flashErrorInfo>& i_side1Errors,
                         const std::vector<flashErrorInfo>& i_goldenErrors)
{
    /*@
     * @errortype
     * @moduleid SBEIO_ODY_CHECK_FLASH
     * @reasoncode SBEIO_ODY_FLASH_CHECK_ERR
     * @userdata1[0:31] Odyssey HUID
     * @userdata1[32:63] Currently running side
     * @userdata2[0:15] Whether the failure was detected on side 0
     * @userdata2[16:31] Whether the failure was detected on side 1
     * @userdata2[32:47] Whether the failure was detected on golden side
     * @devdesc Odyssey flash check error(s) detected
     * @custdesc Boot failure occurred
     */
    errlHndl_t l_errl = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                                      SBEIO_ODY_CHECK_FLASH,
                                      SBEIO_ODY_FLASH_CHECK_ERR,
                                      SrcUserData(bits{0,31}, get_huid(i_ocmb),
                                                  bits{32,63}, i_ocmb->getAttr<ATTR_OCMB_BOOT_SIDE>()),
                                      SrcUserData(bits{0,15}, i_side0Fail,
                                                  bits{16,31}, i_side1Fail,
                                                  bits{32,47}, i_goldenFail));

    l_errl->addHwCallout(i_ocmb,
                         HWAS::SRCI_PRIORITY_HIGH,
                         HWAS::NO_DECONFIG,
                         HWAS::GARD_NULL);

    for(const auto l_errorVector : {&i_side0Errors, &i_side1Errors, &i_goldenErrors})
    {
        for(const auto l_error : *l_errorVector)
        {
            // Flash side values as defined with enum flashCheckSide are not the normal boot
            // side0, side1, side2 (golden) values.  The messages below include both values to
            // avoid any confusion.
            uint8_t aka_side = 0;
            if (l_error.side == SIDE_0) {aka_side = 0;}
            else if (l_error.side == SIDE_1) {aka_side = 1;}
            else if (l_error.side == SIDE_GOLDEN) {aka_side = 2;}

            char errorString[256] = {};
            snprintf(errorString, sizeof(errorString),
                     "Flash Check Side %d (aka boot side %d) DeviceID: 0x%x; number of Correctable Errors: 0x%x; Unrecoverable Errors: 0x%x",
                     l_error.side, aka_side, l_error.deviceId, l_error.numCe, l_error.numUe);
            SBE_TRACF(INFO_MRK"processSpiFlashCheckResponse: Flash Check Side %d (aka boot side %d) DeviceID 0x%x; number of CEs: 0x%x; UEs: 0x%x",
                      l_error.side, aka_side, l_error.deviceId, l_error.numCe, l_error.numUe);
            ErrlUserDetailsString(errorString).addToLog(l_errl);
        }
    }

    l_errl->collectTrace(SBEIO_COMP_NAME);

    return l_errl;
}

errlHndl_t processSpiFlashCheckResponse(Target* i_ocmb, uint8_t i_numStatusEntries, uint8_t* i_response)
{
    errlHndl_t l_errl = nullptr;
    bool l_side0Fail = false;
    bool l_side1Fail = false;
    bool l_goldenFail = false;
    bool l_ceFound = false;

    std::vector<flashErrorInfo> l_side0Errors;
    std::vector<flashErrorInfo> l_side1Errors;
    std::vector<flashErrorInfo> l_goldenErrors;

    SbeFifo::spiScrubStatusEntry* l_scrubStatusEntry = reinterpret_cast<SbeFifo::spiScrubStatusEntry*>(i_response);

    for(uint8_t i = 0; i < i_numStatusEntries; ++i, ++l_scrubStatusEntry)
    {
        // The number of UEs is valid only if the scrub status is good, so check
        // the status first.
        if(l_scrubStatusEntry->scrubStatus == 0)
        {
            if(l_scrubStatusEntry->ce != 0)
            {
                l_ceFound = true;
            }

            if(l_scrubStatusEntry->side == SIDE_0)
            {
                l_side0Errors.push_back({l_scrubStatusEntry->side,
                                         l_scrubStatusEntry->deviceId,
                                         l_scrubStatusEntry->ce,
                                         l_scrubStatusEntry->ue});
                if(l_scrubStatusEntry->ue != 0)
                {
                    SBE_TRACF(ERR_MRK"processSpiFlashCheckResponse: detected %d UEs on Side 0 of device %d",
                              l_scrubStatusEntry->ue, l_scrubStatusEntry->deviceId);
                    l_side0Fail = true;
                }
            }
            else if(l_scrubStatusEntry->side == SIDE_1)
            {
                l_side1Errors.push_back({l_scrubStatusEntry->side,
                                         l_scrubStatusEntry->deviceId,
                                         l_scrubStatusEntry->ce,
                                         l_scrubStatusEntry->ue});
                if(l_scrubStatusEntry->ue != 0)
                {
                    SBE_TRACF(ERR_MRK"processSpiFlashCheckResponse: detected %d UEs on Side 1 of device %d",
                              l_scrubStatusEntry->ue, l_scrubStatusEntry->deviceId);
                    l_side1Fail = true;
                }
            }
            else if(l_scrubStatusEntry->side == SIDE_GOLDEN)
            {
                l_goldenErrors.push_back({l_scrubStatusEntry->side,
                                          l_scrubStatusEntry->deviceId,
                                          l_scrubStatusEntry->ce,
                                          l_scrubStatusEntry->ue});
                if(l_scrubStatusEntry->ue != 0)
                {
                    SBE_TRACF(ERR_MRK"processSpiFlashCheckResponse: detected %d UEs on Golden Side of device %d",
                              l_scrubStatusEntry->ue, l_scrubStatusEntry->deviceId);
                    l_goldenFail = true;
                }
            }
        }
    }

    // Deconfigure the OCMB and fail the IPL in MFG mode for any detected flash failure.
    if((l_side0Fail || l_side1Fail || l_goldenFail || l_ceFound) &&
       areAllSrcsTerminating())
    {
        l_errl = makeFlashErrl(i_ocmb, l_side0Fail, l_side1Fail, l_goldenFail,
                               l_side0Errors, l_side1Errors, l_goldenErrors);
        l_errl->addHwCallout(i_ocmb,
                             HWAS::SRCI_PRIORITY_HIGH,
                             HWAS::DECONFIG,
                             HWAS::GARD_NULL);
        goto ERROR_EXIT;
    }

    // If there is a flash check failure on the side we're currently running on,
    // then pass that failure to the code update FSM, and it will handle side-switching
    // and/or reboot correctly. If the failure is on the "opposite" side, then set
    // the force image sync flag. Always handle errors on golden side. If only CE
    // (correctable errors) are found, commit a recovered log.
    if((i_ocmb->getAttr<ATTR_OCMB_BOOT_SIDE>() == 0 && l_side0Fail) ||
       (i_ocmb->getAttr<ATTR_OCMB_BOOT_SIDE>() == 1 && l_side1Fail) ||
       l_goldenFail)
    {
        SBE_TRACF(ERR_MRK"processSpiFlashCheckResponse: Failure on currently running side or golden side detected");

        l_errl = makeFlashErrl(i_ocmb, l_side0Fail, l_side1Fail, l_goldenFail,
                               l_side0Errors, l_side1Errors, l_goldenErrors);

        auto l_fsmErrl = ody_upd_process_event(i_ocmb,
                                               OCMB_FLASH_ERROR,
                                               errlOwner(l_errl));
        l_errl = nullptr;
        if(l_fsmErrl)
        {
            SBE_TRACF("processSpiFlashCheckResponse: could not process Ody event");
            l_errl = l_fsmErrl.release();
        }
    }
    else if((i_ocmb->getAttr<ATTR_OCMB_BOOT_SIDE>() == 0 && l_side1Fail) ||
            (i_ocmb->getAttr<ATTR_OCMB_BOOT_SIDE>() == 1 && l_side0Fail))
    {
        SBE_TRACF(ERR_MRK"processSpiFlsahCheckResponse: Failure found on alternate side; setting flag to force the image sync");
        i_ocmb->setAttr<ATTR_OCMB_FORCE_IMAGE_SYNC>(1);
        l_errl = makeFlashErrl(i_ocmb, l_side0Fail, l_side1Fail, l_goldenFail,
                               l_side0Errors, l_side1Errors, l_goldenErrors);
        l_errl->setSev(ERRL_SEV_RECOVERED);
        errlCommit(l_errl, SBEIO_COMP_ID);
    }
    else if(l_ceFound)
    {
        l_errl = makeFlashErrl(i_ocmb, l_side0Fail, l_side1Fail, l_goldenFail,
                               l_side0Errors, l_side1Errors, l_goldenErrors);
        l_errl->setSev(ERRL_SEV_RECOVERED);
        errlCommit(l_errl, SBEIO_COMP_ID);
    }

ERROR_EXIT:

    return l_errl;
}

errlHndl_t sendSpiFlashCheckRequest(Target* i_ocmb, uint8_t i_scope, uint8_t i_side, uint8_t i_deviceId)
{
    SBE_TRACF(ENTER_MRK"sendSpiFlashCheckRequest: i_ocmb = 0x%08X, scope=%d, side=0x%X, devId=%d",
              get_huid(i_ocmb), i_scope, i_side, i_deviceId);
    errlHndl_t l_errl = nullptr;

    // SPPE will send back a scrub status entry per side requested per device, so
    // if we request to scrub the primary and backup sides on two devices, SPPE
    // will send back 4 scrub status entries. The side and deivce ID bits are OR'ed
    // together, so we can multiply the bit counts to find the total number of
    // scrub status entries we need to expect from SPPE.
    size_t l_numScrubStatusEntries = __builtin_popcount(i_side) * __builtin_popcount(i_deviceId);

    // The SSPE reponse contains the scrub status entries followed by the standard
    // FIFO response.
    std::vector<uint8_t>l_response;
    l_response.resize(l_numScrubStatusEntries * sizeof(SbeFifo::spiScrubStatusEntry) +
                      sizeof(SbeFifo::fifoStandardResponse));

    SbeFifo::fifoScrubMemDeviceRequest l_request;
    l_request.scope = i_scope;
    l_request.side = i_side;
    l_request.deviceId = i_deviceId;

    l_errl = SbeFifo::getTheInstance().performFifoChipOp(i_ocmb,
                                                         reinterpret_cast<uint32_t*>(&l_request),
                                                         reinterpret_cast<uint32_t*>(l_response.data()),
                                                         l_response.size());
    if(l_errl)
    {
        SBE_TRACF("sendSpiFlashCheckRequest: chip op failed for OCMB 0x08%x" TRACE_ERR_FMT,
                  get_huid(i_ocmb),
                  TRACE_ERR_ARGS(l_errl));
        goto ERROR_EXIT;
    }

    l_errl = processSpiFlashCheckResponse(i_ocmb, l_numScrubStatusEntries, l_response.data());
    if(l_errl)
    {
        SBE_TRACF("sendSpiFlashCheckRequest: response processing failed for OCMB 0x%08X" TRACE_ERR_FMT,
                  get_huid(i_ocmb),
                  TRACE_ERR_ARGS(l_errl));
        goto ERROR_EXIT;
    }

ERROR_EXIT:
    SBE_TRACF(EXIT_MRK"sendSpiFlashCheckRequest: i_ocmb = 0x%08X", get_huid(i_ocmb));
    return l_errl;
}

} // namespace SBEIO
