/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/bootloader/inttypes_hbbl.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2025                        */
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

/*
 * @file inttypes_hbbl.H is the Hostboot Boadloader (HBBL) version of
 *       inttypes.H since the one the Secure ROM code uses is not in the
 *       src/include/securerom directory.  Since this file is only needed
 *       on a tempoary basis for HBBL, a new version was created here.
 *
 * @TODO JIRA PFHB-921 remove this file when all of the algorithms work
 *       in the SecureROM.
 */

#define uint_fast8_t  uint8_t

#ifndef BYTE_ORDER
static_assert(0,"BYTE_ORDER MUST BE DEFINED");
#endif /* #ifndef BYTE_ORDER */

#if BYTE_ORDER == LITTLE_ENDIAN
#undef __BIG_ENDIAN
#ifndef __LITTLE_ENDIAN
#define __LITTLE_ENDIAN 4321
#endif
#else
#undef __LITTLE_ENDIAN
#ifndef __BIG_ENDIAN
#define __BIG_ENDIAN    1234
#endif
#endif
