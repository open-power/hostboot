/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_slw_build/p8_ring_identification.H $ */
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
// $Id: p8_ring_identification.H,v 1.7 2013/02/12 17:33:12 cmolsen Exp $
/*------------------------------------------------------------------------------*/
/* *! (C) Copyright International Business Machines Corp. 2012                  */
/* *! All Rights Reserved -- Property of IBM                                    */
/* *! *** IBM Confidential ***                                                  */
/*------------------------------------------------------------------------------*/
/* *! TITLE :       p8_ring_identification                                      */
/* *! DESCRIPTION : Include file for global static #G & #R ringID vs ringName.  */
/* *! OWNER NAME :  Michael Olsen            Email: cmolsen@us.ibm.com          */
//
/*------------------------------------------------------------------------------*/
#include <p8_pore_api_custom.h>
#include <string.h> // Why isn't this included in p8_pore_api_custom.h? PHYP
                    //   said back in Aug that strcmp() is allowed. But it is
                    //   not in p8_pore_api_custom.h.

// Ring ID list structure.
typedef struct {
  const char  *ringName;
  uint8_t     ringId;
  uint8_t     chipIdMin;    // the min chipletId
  uint8_t     chipIdMax;    // the max chipletId
  const char  *ringNameImg; // Ring name in image: ringName + "_ring"
  uint8_t     vpdKeyword;
  uint8_t      bWcSpace;     // 0: fitted  1: worst-case space (3 x ring length)
} RingIdList;

extern const RingIdList  RING_ID_LIST_PG[], RING_ID_LIST_PR[];
extern const uint32_t    RING_ID_LIST_PG_SIZE, RING_ID_LIST_PR_SIZE;
extern const RingIdList  RING_ID_LIST[];
extern const uint32_t    RING_ID_LIST_SIZE;

// Enumerated VPD keyword values.
// Note! This is DIFFERENT from the MvpdKeyword list in fapiMvpdAccess.H which
//       can't be used in this file since it's not, per se, a fapi file. So
//       these values need to be translated in xip_customize when passing the
//       mvpdKeyword to getMvpdRing();
enum VpdKeyword  {
  VPD_KEYWORD_PDG,
  VPD_KEYWORD_PDR,
  NUM_OF_VPD_TYPES
};

int get_vpd_ring_list_entry(const char *i_ringName,
                            const uint8_t i_ringId,
                            RingIdList **i_ringIdList);

