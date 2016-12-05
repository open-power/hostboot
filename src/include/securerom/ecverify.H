/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/securerom/ecverify.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/*----------------------------------------------------------------------
 *   (C) COPYRIGHT INTERNATIONAL BUSINESS MACHINES CORPORATION  2010
 *                        ALL RIGHTS RESERVED
 *  IBM Research, Zurich  and  IBM Crypto Competency Center, Copenhagen
 *----------------------------------------------------------------------
 *  Author: Tamas Visegrady (tvi@zurich.ibm.com)
 *----------------------------------------------------------------------*/

#if !defined(__ECVERIFY_H__)
#define   __ECVERIFY_H__

/** ECDSA verification on fixed curve
 */

#define EC_HASHBYTES   64     /* SHA-256 */
#define EC_COORDBYTES  66     /* P-521   */

typedef uint8_t ecc_key_t[2*EC_COORDBYTES];
typedef uint8_t ecc_signature_t[2*EC_COORDBYTES];

/** Returns positive if signature verified
 *          zero     if parameters are valid but signature verification fails
 *          negative if parameters (such as point) are invalid
 */
int ec_verify (const uint8_t *publicpt,     /* 2*EC_COORDBYTES */
               const uint8_t *hash,         /*   EC_HASHBYTES  */
               const uint8_t *signature) ;  /* 2*EC_COORDBYTES */

#define NDEBUG

#endif    /* defined(__ECVERIFY_H__) */
