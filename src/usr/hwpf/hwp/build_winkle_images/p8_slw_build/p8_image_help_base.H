/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_slw_build/p8_image_help_base.H $ */
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
// $Id: p8_image_help_base.H,v 1.4 2012/09/01 16:49:28 cmolsen Exp $
//------------------------------------------------------------------------------
//  Title:  p8_image_help_base.H
//  Description:  Contains the most basic structures and defines needed for 
//                image building and interpretation.
//------------------------------------------------------------------------------

#define ASM_RS4_LAUNCH_BUF_SIZE  24	// Byte size of RS4 launch buffer. 
#define LISTING_STRING_SIZE  (2*PORE_INLINE_DISASSEMBLER_STRING_SIZE)

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
    uint64_t  address;  // 64-bit PORE address
    char      *name;    // TOC name
    uint8_t   override; // 0: base  1: override
} PairingInfo;
