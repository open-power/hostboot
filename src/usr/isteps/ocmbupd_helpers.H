/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/ocmbupd_helpers.H $                            */
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

#ifndef OCMBUPD_HELPERS_H
#define OCMBUPD_HELPERS_H

#include <ody_upd_fsm.H>
#include <hwp_return_codes.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbeioreasoncodes.H>

#define HANDLE_ODY_HWP_ERROR(ISTEP_NAME, HWP, STEP_ERR, OCMB, ERRL)     \
    ({                                                                  \
        ISTEP_ERROR::IStepError& M_steperr = STEP_ERR;                  \
        errlHndl_t& M_errl_ptr = ERRL;                                  \
        errlOwner M_errl(M_errl_ptr);                                   \
        M_errl_ptr = nullptr;                                           \
        TARGETING::Target* const M_ocmb = OCMB;                         \
        if (M_errl)                                                     \
        {                                                               \
            if (TARGETING::UTIL::isOdysseyChip(M_ocmb))                 \
            {                                                           \
                if(M_ocmb->getAttr<TARGETING::ATTR_COLLECT_SBE_SCRATCH_DATA>() == 1 && \
                   !M_errl->hasErrorType(SBEIO::SBEIO_ERROR_TYPE_HRESET_PERFORMED)) \
                {                                                       \
                    errlHndl_t l_scratchErrls;                          \
                    auto l_errl = SBEIO::getAndProcessScratchData(M_ocmb,\
                                                       l_scratchErrls); \
                    if(l_errl)                                          \
                    {                                                   \
                        errlCommit(l_errl, SBEIO_COMP_ID);              \
                    }                                                   \
                    else if (l_scratchErrls)                            \
                    {                                                   \
                        errlCommit(l_scratchErrls, SBEIO_COMP_ID);      \
                    }                                                   \
                }                                                       \
                ocmbupd::ody_upd_event_t M_update_event = ocmbupd::OCMB_HWP_FAIL_OTHER; \
                if (M_errl->hasUserData1(fapi2::RC_UNSUPPORTED_ATTR_LEVEL)) \
                {                                                       \
                    TRACISTEP(INFO_MRK #ISTEP_NAME ": HWP signaled incompatible "\
                              "attribute levels for Odyssey 0x%08x, log 0x%08X.", \
                              get_huid(M_ocmb),                         \
                              ERRL_GETEID_SAFE(M_errl));                \
                    M_update_event = ocmbupd::ATTRS_INCOMPATIBLE;       \
                }                                                       \
                else if (M_errl->hasUserData1(fapi2::RC_POZ_FILE_HASH_MISMATCH)) \
                {                                                       \
                    TRACISTEP(INFO_MRK #ISTEP_NAME ": HWP signaled SecureBoot " \
                              "fail for Odyssey 0x%08x, log 0x%08x.",   \
                              get_huid(M_ocmb),                         \
                              ERRL_GETEID_SAFE(M_errl));                \
                    M_update_event = ocmbupd::OCMB_HWP_FAIL_HASH_FAIL;  \
                }                                                       \
                                                                        \
                if (auto M_upd_errl =                                   \
                    ocmbupd::ody_upd_process_event(M_ocmb,              \
                                                   M_update_event,      \
                                                   move(M_errl)))       \
                {                                                       \
                    TRACISTEP(ERR_MRK #ISTEP_NAME ": ody_upd_process_event(0x%08x) " \
                              "failed; halting istep "                  \
                              TRACE_ERR_FMT,                            \
                              get_huid(M_ocmb),                         \
                              TRACE_ERR_ARGS(M_upd_errl));              \
                                                                        \
                    captureError(move(M_upd_errl), M_steperr, HWPF_COMP_ID, M_ocmb); \
                }                                                       \
            }                                                           \
        }                                                               \
    })

#endif
