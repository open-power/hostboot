/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/ocmbupd_helpers.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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

#define HANDLE_ODY_HWP_ERROR(ISTEP_NAME, HWP, STEP_ERR, OCMB, ERRL)     \
    ({                                                                  \
        ISTEP_ERROR::IStepError& M_steperr = STEP_ERR;                  \
        errlHndl_t& M_errl = ERRL;                                      \
        TARGETING::Target* const M_ocmb = OCMB;                         \
        if (M_errl)                                                     \
        {                                                               \
            if (ocmbupd::odysseyCodeUpdateSupported() && TARGETING::UTIL::isOdysseyChip(M_ocmb)) \
            {                                                           \
                ocmbupd::ody_upd_event_t M_update_event = ocmbupd::OCMB_HWP_FAIL_OTHER; \
                if(M_errl->getUserData1() == fapi2::RC_UNSUPPORTED_ATTR_LEVEL) \
                {                                                       \
                    TRACISTEP(INFO_MRK #ISTEP_NAME ": HWP signaled incompatible "\
                              "attribute levels for Odyssey 0x%08x.",   \
                              get_huid(M_ocmb));                                 \
                    M_update_event = ocmbupd::ATTRS_INCOMPATIBLE;       \
                }                                                       \
                                                                        \
                if (auto M_upd_errl =                                   \
                    ocmbupd::ody_upd_process_event(M_ocmb,              \
                                                   M_update_event,      \
                                                   M_errl))             \
                {                                                       \
                    TRACISTEP(ERR_MRK #ISTEP_NAME ": ody_upd_process_event(0x%08x) " \
                              "failed; halting istep "                  \
                              TRACE_ERR_FMT,                            \
                              get_huid(M_ocmb),                         \
                              TRACE_ERR_ARGS(M_upd_errl));              \
                                                                        \
                    captureError(M_upd_errl, M_steperr, HWPF_COMP_ID, M_ocmb); \
                }                                                       \
            }                                                           \
            else                                                        \
            { /* @TODO: JIRA PFHB-522 Remove  OCMBFW_HANDLE check when OCMBFW PNOR partition v1 support is removed */ \
                TRACISTEP(ERR_MRK"call " #HWP " HWP(): failed on target 0x%08X. " \
                          TRACE_ERR_FMT,                                \
                          get_huid(M_ocmb),                             \
                          TRACE_ERR_ARGS(M_errl));                      \
                                                                        \
                captureError(M_errl, M_steperr, HWPF_COMP_ID, M_ocmb);  \
            }                                                           \
        }                                                               \
    })

#endif
