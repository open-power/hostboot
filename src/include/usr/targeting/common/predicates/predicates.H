/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/predicates/predicates.H $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2023                        */
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
#ifndef __TARGETING_COMMON_PREDICATES_H
#define __TARGETING_COMMON_PREDICATES_H

/**
 *  @file targeting/common/predicates/predicates.H
 *
 *  @brief Shortcut file to pull in all the predicate include files.
 *
 */
#include <targeting/common/predicates/predicatebase.H>
#include <targeting/common/predicates/predicatectm.H>
#include <targeting/common/predicates/predicateisfunctional.H>
#include <targeting/common/predicates/predicatehwas.H>
#include <targeting/common/predicates/predicatehwaschanged.H>
#include <targeting/common/predicates/predicatepostfixexpr.H>
#include <targeting/common/predicates/predicateattrval.H>
#include <targeting/common/predicates/predicateisnonfunctional.H>

#ifdef __HOSTBOOT_MODULE
// NOTE: need to explicity add to FSP/CMVC file src/hbfw/fsp/targeting/makefile if
//       this is needed for that environment
#include <targeting/common/predicates/predicateattr.H>
#endif

// please keep up to date...

#endif // __TARGETING_COMMON_PREDICATES_H

