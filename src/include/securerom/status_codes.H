/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/securerom/status_codes.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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

#ifndef STATUS_CODES_H
#define STATUS_CODES_H

// Error extension code
#ifndef EMULATE_HW
#define ERROR_EVENT            0xFFFFFFFFFFFF8000
#else
#define ERROR_EVENT            0xFFFFFFFFFFFF8000ull
#endif

// context codes
#define ROM_VERIFY             0x0100
#define ROM_SRESET             0x0E00

// progress/test codes
#define BEGIN                  0x0001

#define TRUSTED_MEM_BAR        0x0012

#define CONTAINER_LOW_TEST     0x0013

#define XSCOM_LOW_TEST         0x0010
#define XSCOM_VALID_TEST       0x0011

#define MAGIC_NUMBER_TEST      0x0020
#define CONTAINER_VERSION_TEST 0x0021
#define PREFIX_VER_ALG_TEST    0x0022
#define HEADER_VER_ALG_TEST    0x0023

#define STACK_LOW_TEST         0x0030
#define STACK_VALID_TEST       0x0031
#define STACK_TRUST_TEST       0x0032
#define STACK_ZERO_DONE        0x0033

#define SHA_GOOD_TEST          0x0040
#define SHA_BAD_TEST           0x0041
#define ECDSA_GOOD_TEST        0x0042
#define ECDSA_BAD_TEST         0x0043

#define TARGET_LOW_TEST        0x0050
#define TARGET_VALID_TEST      0x0051
#define TARGET_TRUST_TEST      0x0052
#define STACK_VS_TARGET_TEST   0x0053
#define TARGET_ZERO_DONE       0x0054
#define CONTAINER_COPY_DONE    0x0055

#define HBI_KEY_TEST           0x0056

#define CONTAINER_VERIFY_DONE  0x0057
#define STACK_CLEANUP_DONE     0x0058

#define OTP_ECID_INVPOPSUM_CHECK 0x0059
#define OTP_KEY_INVPOPSUM_CHECK  0x005A

#define HW_KEY_HASH_TEST       0x0060
#define HW_SIGNATURE_TEST      0x0061
#define PREFIX_ECID_TEST       0x0062
#define PREFIX_HASH_TEST       0x0063
#define SW_KEY_PROTECTION_TEST 0x0064
#define SW_KEY_INVALID_COUNT   0x0065

#define SW_SIGNATURE_TEST      0x0070
#define HEADER_ECID_TEST       0x0071
#define HEADER_HASH_TEST       0x0072
#define CODE_PROTECTION_TEST   0x0073

#define ENTRY_VALID_TEST       0x0080

#define SECURE_VERSION_TEST    0x0090

#define PARTIAL                0x0002
#define COMPLETED              0x0003

#define EXECUTION_ERROR        0x00EE
#define XSCOM_ERROR            0xAFEE

#define RETURNED_ERROR         0xD00F

#endif
