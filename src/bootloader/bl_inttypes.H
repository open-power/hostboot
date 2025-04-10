/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/bootloader/bl_inttypes.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2025                        */
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
 * @file bl_inttypes.H is the Hostboot Boadloader (HBBL) version of
 *       inttypes.H that points to the Secure ROM version of intypes.H.
 *       This is needed to support bl_ecverify.C which is a version of
 *       the Secure ROM ecverify.C that needs to be build differently for
 *       HBBL
 *
 * @TODO JIRA PFHB-921 remove this file when all of the algorithms work
 *       in the Secure ROM and can be pulled from the HBBL.
 */

#include <bootloader/bootloader.H>

#define bl_inttypes_H

#include <../securerom/inttypes.H>

#undef bl_inttypes_H
