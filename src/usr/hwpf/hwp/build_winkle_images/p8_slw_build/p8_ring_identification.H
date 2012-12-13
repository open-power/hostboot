/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_slw_build/p8_ring_identification.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: p8_ring_identification.H,v 1.6 2012/11/13 16:39:12 cmolsen Exp $
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
	uint8_t     chipIdMin;
	uint8_t     chipIdMax;
	const char  *ringNameImg; // Ring name in image: ringName + "_ring"
	uint8_t     vpdKeyword;
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

