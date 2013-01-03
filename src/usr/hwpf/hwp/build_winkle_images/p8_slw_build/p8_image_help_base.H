/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_slw_build/p8_image_help_base.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
// $Id: p8_image_help_base.H,v 1.9 2012/12/18 05:24:00 cmolsen Exp $
//------------------------------------------------------------------------------
//  Title:  p8_image_help_base.H
//  Description:  Contains the most basic structures and defines needed for 
//                image building and interpretation.
//------------------------------------------------------------------------------

const uint32_t  MAX_REF_IMAGE_SIZE      = 5000000; // Max reference image size.
const uint32_t  FIXED_SLW_IMAGE_SIZE    = 1000000; // Fixed SLW image size assumed by HB, PHYP and slw_build().
const uint32_t  FIXED_RING_BUF_SIZE     = 60000; // Fixed ring buffer size assumed by HB, PHYP and slw_build(). Only use when emulating FAPI calls and for command-line utilities.
const uint8_t   MAX_VPD_TYPES           = 2;     // #G and #R, so far.
const uint8_t   CHIPLET_ID_MIN          = 0x00;
const uint8_t   CHIPLET_ID_MAX          = 0x1F;
const uint8_t   MAX_CHIPLETS            = CHIPLET_ID_MAX-CHIPLET_ID_MIN+1;
const uint32_t  ASM_RS4_LAUNCH_BUF_SIZE = 24;	// Byte size of RS4 launch buffer. 
const uint32_t  LISTING_STRING_SIZE     = 256;
const uint64_t  MAX_UINT64_T            = (uint64_t)0xFFFFFFFF<<32 | (uint64_t)0xFFFFFFFF;

// Base (shared) ring layout for both RS4 and Wiggle-flip layouts.
typedef struct {
	uint64_t entryOffset;
	uint64_t backItemPtr;
	uint32_t sizeOfThis;
	uint32_t sizeOfMeta; // Exact size of meta data. Arbitrary size. Not null terminated.
} BaseRingLayout;

// RS4 specific layout.
typedef struct {
  uint64_t entryOffset;
  uint64_t backItemPtr;
  uint32_t sizeOfThis;
  uint32_t sizeOfMeta; // Exact size of meta data. Arbitrary size. Not null terminated.
  uint32_t ddLevel;
  uint8_t  sysPhase;
  uint8_t  override;
  uint8_t  reserved1;
  uint8_t  reserved2;
} Rs4RingLayout;

// PairingInfo is used for pairing, or matching, a back pointer address of a
// ring block with its corresponding TOC name.
typedef struct {
    uint64_t address;     // (in) Holds PORE backPtr addr of the ring
		uint8_t  vectorpos;   // (in) Vector position of fwdPtr [0;31]
		                      //      max=0  for most VPD rings 
												  //      max=1  for all non-VPD rings
												  //      max=1  for perv_ VPD rings
												  //      max=15 for most VPD ex_ rings
													//      max=31 for 16 ex_ chiplets with override
    char     *name;       // (out) TOC name
		uint8_t  isvpd;       // (out) 0: Non-VPD ring  1: VPD ring
		uint8_t  overridable; // (out) 0: No (most VPD rings)  1: Yes (all non-VPD rings)
    uint8_t  override;    // (out) 0: base  1: override
} PairingInfo;
