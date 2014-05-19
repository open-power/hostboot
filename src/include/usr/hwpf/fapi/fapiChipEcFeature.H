/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/fapi/fapiChipEcFeature.H $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: fapiChipEcFeature.H,v 1.4 2013/10/15 13:13:23 dcrowell Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/hwpf/working/fapi/fapiChipEcFeature.H,v $

/**
 *  @file fapiChipEcFeature.H
 *
 *  @brief Defines the fapiQueryChipEcFeature function that allows HWPs to
 *         query if a particular chip has a feature determined by its EC level.
 *         Chip EC features are specified in attribute XML files and the
 *         fapiQueryChipEcFeature function implementation is auto-generated.
 *         HWPs should not call this function directly, but should access the
 *         corresponding HWPF attribute using FAPI_ATTR_GET
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     03/26/2012  Created.
 */

#ifndef FAPICHIPECFEATURE_H_
#define FAPICHIPECFEATURE_H_

#include <stdint.h>
#include <fapiAttributeIds.H>
#include <fapiReturnCode.H>

namespace fapi
{

class Target;

/**
 * @brief Queries if a Chip has a particular feature
 *
 * This should only be called by FAPI during the processing of a FAPI_ATTR_GET
 * for a Chip EC Feature attribute
 *
 * @param[in]  i_id         Attribute ID of the Chip EC Feature
 * @param[in]  i_pTarget    Pointer to chip target
 * @param[out] o_hasFeature Set to 1 if chip has feature else 0
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiQueryChipEcFeature(fapi::AttributeId i_id,
                                        const fapi::Target * i_pTarget,
                                        uint8_t & o_hasFeature);
}

#endif
