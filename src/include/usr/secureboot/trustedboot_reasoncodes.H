/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/trustedboot_reasoncodes.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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

/////////////////////////////////////////////////////////////////
// NOTE: This file is exportable as TSS-Lite for skiboot/PHYP  //
/////////////////////////////////////////////////////////////////

#ifndef __TRUSTEDBOOT_REASONCODES_H
#define __TRUSTEDBOOT_REASONCODES_H

#ifdef __HOSTBOOT_MODULE
#include <hbotcompid.H>
#else
#define TRBOOT_COMP_ID 0x2B00
#endif

#ifdef __cplusplus
namespace TRUSTEDBOOT
{
#endif

    enum TRUSTEDModuleId
    {
        MOD_HOST_UPDATE_MASTER_TPM          = 0x00,
        MOD_TPM_INITIALIZE                  = 0x01,
        MOD_TPM_CMD_STARTUP                 = 0x02,
        MOD_TPM_CMD_GETCAPFWVERSION         = 0x03,
        MOD_TPM_MARSHALCMDDATA              = 0x04,
        MOD_TPM_UNMARSHALRESPDATA           = 0x05,
        MOD_TPM_VERIFYFUNCTIONAL            = 0x06,
        MOD_TPM_CMD_PCREXTEND               = 0x07,
        MOD_TPM_CMD_PCRREAD                 = 0x08,
        MOD_TPM_REPLAY_LOG                  = 0x09,
        MOD_TPM_PCREXTEND                   = 0x0A,
        MOD_TPM_TPMDAEMON                   = 0x0B,
        MOD_TPM_SYNCRESPONSE                = 0x0C,
        MOD_TPM_SEPARATOR                   = 0x0D,
        MOD_TPM_CMD_GETCAPNVINDEX           = 0x0E,
        MOD_FLUSH_TPM_QUEUE                 = 0x0F,
        MOD_TPMLOGMGR_INITIALIZE            = 0x10,
        MOD_TPMLOGMGR_ADDEVENT              = 0x11,
        MOD_TPMLOGMGR_INITIALIZEEXISTLOG    = 0x12,
        MOD_TPMLOGMGR_GETDEVTREEINFO        = 0x13,
        MOD_TPM_MARK_FAILED                 = 0x14,
        MOD_INIT_BACKUP_TPM                 = 0x15,
        MOD_DO_INIT_BACKUP_TPM              = 0x16,
        MOD_TEST_CMP_PRIMARY_AND_BACKUP_TPM = 0x17,
        MOD_TPM_GETRANDOM                   = 0x18,
        MOD_VALIDATE_TPM_HANDLE             = 0x19,
        MOD_TPM_CMD_CREATE_ATTEST           = 0x1A,
        MOD_CREATE_ATT_KEYS                 = 0x1B,
        MOD_READ_AK_CERT                    = 0x1C,
        MOD_TPM_CMD_READ_AK_CERT            = 0x1D,
        MOD_TPM_CMD_GEN_QUOTE               = 0x1E,
        MOD_GEN_QUOTE                       = 0x1F,
        MOD_TPM_CMD_FLUSH_CONTEXT           = 0x20,
        MOD_FLUSH_CONTEXT                   = 0x21,
        MOD_PCR_READ                        = 0x22,
        MOD_EXPAND_TPM_LOG                  = 0x23,
        MOD_TPM_CMD_EXPAND_TPM_LOG          = 0x24,
        MOD_MARK_TPM_UNUSABLE               = 0x25,
        MOD_TPM_CHECK_TDP_BIT               = 0x26,
        MOD_SYNCHRONIZE_TPM_LOG             = 0x27,
        MOD_LOG_SBE_MEASUREMENT_REGS        = 0x28,
        MOD_EXTEND_MEAS_OTHER_NODES         = 0x29,
    };

    enum TRUSTEDReasonCode
    {
        // Reason codes 0x00 - 0x9F reserved for secure_reasoncodes.H

        RC_TPM_START_FAIL                = TRBOOT_COMP_ID | 0xA0,
        RC_TPM_EXISTENCE_FAIL            = TRBOOT_COMP_ID | 0xA1,
        RC_TPM_GETCAP_FAIL               = TRBOOT_COMP_ID | 0xA2,
        RC_TPM_GETCAP_FW_INVALID_RESP    = TRBOOT_COMP_ID | 0xA3,
        RC_TPM_GETCAP2_FAIL              = TRBOOT_COMP_ID | 0xA4,
        RC_TPM_GETCAP2_FW_INVALID_RESP   = TRBOOT_COMP_ID | 0xA5,
        RC_TPM_MARSHAL_INVALID_CMD       = TRBOOT_COMP_ID | 0xA6,
        RC_TPM_MARSHALING_FAIL           = TRBOOT_COMP_ID | 0xA7,
        RC_TPM_UNMARSHAL_INVALID_CMD     = TRBOOT_COMP_ID | 0xA8,
        RC_TPM_UNMARSHALING_FAIL         = TRBOOT_COMP_ID | 0xA9,
        RC_TPMLOGMGR_ADDEVENT_FAIL       = TRBOOT_COMP_ID | 0xAA,
        RC_TPMLOGMGR_ADDEVENTMARSH_FAIL  = TRBOOT_COMP_ID | 0xAB,
        RC_TPMLOGMGR_INIT_FAIL           = TRBOOT_COMP_ID | 0xAC,
        //termination_rc
        RC_TPM_NOFUNCTIONALTPM_FAIL      = TRBOOT_COMP_ID | 0xAD,
        RC_TPM_COMMAND_FAIL              = TRBOOT_COMP_ID | 0xAE,
        RC_TPM_INVALID_ARGS              = TRBOOT_COMP_ID | 0xAF,
        RC_TPMLOGMGR_LOGWALKFAIL         = TRBOOT_COMP_ID | 0xB0,
        RC_SENDRECV_FAIL                 = TRBOOT_COMP_ID | 0xB1,
        RC_SEND_FAIL                     = TRBOOT_COMP_ID | 0xB2,
        RC_MSGRESPOND_FAIL               = TRBOOT_COMP_ID | 0xB3,
        RC_UPDATE_SECURITY_CTRL_HWP_FAIL = TRBOOT_COMP_ID | 0xB4,
        RC_TPM_NVINDEX_VALIDATE_FAIL     = TRBOOT_COMP_ID | 0xB5,
        RC_TPMLOGMGR_INITIALIZE_FAIL     = TRBOOT_COMP_ID | 0xB6,
        RC_BACKUP_TPM_TEST_FAIL          = TRBOOT_COMP_ID | 0xB7,
        RC_INVALID_TPM_HANDLE            = TRBOOT_COMP_ID | 0xB8,
        RC_NON_FUNCTIONAL_TPM_HANDLE     = TRBOOT_COMP_ID | 0xB9,
        RC_UNREACHABLE_TPM               = TRBOOT_COMP_ID | 0xBA,
        RC_RAND_NUM_TOO_BIG              = TRBOOT_COMP_ID | 0xBB,
        RC_TPM_BAD_RESP                  = TRBOOT_COMP_ID | 0xBC,
        RC_NO_TPM_LOG_MGR                = TRBOOT_COMP_ID | 0xBD,
        RC_TPM_IS_UNUSABLE               = TRBOOT_COMP_ID | 0xBE,
        RC_TPM_START_SBE_SETUP_FAILED    = TRBOOT_COMP_ID | 0xBF,
        RC_TPM_TDP_BIT_IS_SET            = TRBOOT_COMP_ID | 0xC0,
        RC_VIRT_TO_PHYS_FAIL             = TRBOOT_COMP_ID | 0xC1,
        RC_MBOX_QUEUE_MISMATCH           = TRBOOT_COMP_ID | 0xC2,
        RC_AK_CERT_NOT_AVAIL             = TRBOOT_COMP_ID | 0xC3,
    };
#ifdef __cplusplus
}
#endif

#endif
