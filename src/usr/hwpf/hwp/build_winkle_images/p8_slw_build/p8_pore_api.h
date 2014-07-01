/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_slw_build/p8_pore_api.h $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
/* $Id: p8_pore_api.h,v 1.2 2012/04/11 16:58:29 cmolsen Exp $ */
/* $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/utils/p8_pore_api.h,v $ */
/*------------------------------------------------------------------------------*/
/* *! (C) Copyright International Business Machines Corp. 2010                  */
/* *! All Rights Reserved -- Property of IBM                                    */
/* *! ***  ***                                                  */
/*------------------------------------------------------------------------------*/
/* *! TITLE p8_pore_api                                                        */
/* *! DESCRIPTION : PORE APIs                                                   */
/* *! OWNER NAME :  Nicole Schwartz  Email: nschwart@us.ibm.com                 */
/* *! BACKUP NAME :                                                             */
/* *! ADDITIONAL COMMENTS :                                                     */

/*------------------------------------------------------------------------------*/
/* Don't forget to create CVS comments when you check in your changes!          */
/*------------------------------------------------------------------------------*/

#ifndef _P8P_PORE_API_H
#define _P8P_PORE_API_H

/**
 * Contains all external APIs used by firmware to generate/modify the P7+
 *  PORE image.
 */


#include "p8_pore_api_custom.h"
/*#include <p7p_pore_image.h>*/
#include "p8_pore_api_const.h"

typedef struct {
  char ringName[50];
  uint32_t ringAddress;
  uint32_t clockControlData;
  uint32_t length;
} p8_pore_ringInfoStruct;


/**
 * Generate a set of PORE instructions that will initialize a scan ring.
 *
 * @param i_ringAddr    host    Address of scan ring
 * @param i_ringBitLen  host    Number of bits in the scan ring
 * @param i_ring        host    Pointer to initialized ring data, left-aligned binary
 * @param i_flush       host    Pointer to ring data for flush state, left-aligned binary
 * @param i_maxStreamLenInWords  host    Max space available for resulting PORE image in 32-bit words
 * @param o_streamLenInWords  host    Actual size of PORE image in 32-bit words
 * @param o_streamOutput  BigEndian    Pointer to allocated local memory to write PORE image into, this is
 *    the location to write the ring data into
 *
 * @return uint32_t  Error return codes
 *     P8_PORE_SUCCESS_RC       : No errors
 *     P8_PORE_IMAGE_TOO_BIG_RC : size of PORE image exceeded allowed space
 *     P8_PORE_XXX_RC           : other errors...
 */
uint32_t p8_pore_gen_scan( uint32_t i_ringAddr,
			    uint32_t i_ringBitLen,
			    uint32_t* i_ring,
			    uint32_t* i_flush,
			    uint32_t i_maxStreamLenInWords,
			    uint32_t* o_streamLenInWords,
			    uint32_t* o_streamOutput );

/**
 * Generate or update a set of PORE instructions that will initialize a scom register.
 *
 * @param i_scomAddr    host    Address of scom register
 * @param i_scomData    host    Two 32-bit words of scom register data
 * @param i_operation   host    Should data be appended or existing data updated
 *     P8_PORE_SCOM_APPEND  : add scom instructions to the end of the existing image
 *     P8_PORE_SCOM_OR      : overlay scom data onto existing instruction by bitwise OR
 *     P8_PORE_SCOM_AND     : overlay scom data onto existing instruction by bitwise AND
 *     P8_PORE_SCOM_REPLACE : replace existing instructions with new data
 *     P8_PORE_SCOM_NOOP    : replace existing instructions with NOOP, i_scomData is junk
 * @param i_maxStreamLenInWords  host    Max space available for resulting PORE image in 32-bit words
 * @param o_streamOutput  BigEndian    Pointer to allocated local memory to write PORE image into
 *
 * @return uint32_t  Error return codes
 *     P8_PORE_SUCCESS_RC       : No errors
 *     P8_PORE_IMAGE_TOO_BIG_RC : size of PORE image exceeded allowed space
 *     P8_PORE_BAD_ARG_RC       : some input argument is nonsensical
 *     P8_PORE_ADDR_NOT_FOUND   : could not find existing scom for overlay (AND/OR) operation
 *     P8_PORE_XXX_RC           : other errors...
 */
uint32_t p8_pore_gen_scom( uint32_t i_scomAddr,
			    uint32_t i_scomData[2],
			    uint32_t i_operation,
			    uint32_t i_maxStreamLenInWords,
			    uint32_t* o_streamOutput );

/**
 * Generate or update a set of PORE instructions that will initialize an
 *  architected register in the processor, ie. SPR or GPR.  It is assumed that
 *  all updates will replace any existing data for that register.  If the data
 *  does not already exist then it will be appended.
 *
 * @param i_regName     host    Constant that determines which SPR to write (see p8_pore_const.h)
 * @param i_regData     host    Two 32-bit words of register data
 * @param i_coreIndex   host    Core to operate on
 * @param i_threadIndex   host    Thread to operate on, used for HSPRG0 and LPCR
 * @param i_maxStreamLenInWords  host    Max space available for resulting PORE image in 32-bit words
 * @param o_streamOutput  BigEndian    Pointer to allocated local memory to write PORE image into
 *
 * @return uint32_t  Error return codes
 *     P8_PORE_SUCCESS_RC       : No errors
 *     P8_PORE_IMAGE_TOO_BIG_RC : size of PORE image exceeded allowed space
 *     P8_PORE_XXX_RC           : other errors...
 */
uint32_t p8_pore_gen_cpureg( uint32_t i_regName,
			      uint32_t i_regData[2],
			      uint32_t i_coreIndex,
			      uint32_t i_threadIndex,
			      uint32_t i_maxStreamLenInWords,
			      uint32_t* o_streamOutput );

/**
 * Generate a set of PORE instructions that will perform a branch operation
 *  to a relative address offset
 *
 * @param i_offset      host    Relative offset to branch to
 * @param i_maxStreamLenInWords  host    Max space available for resulting PORE instruction(s) in 32-bit words
 * @param i_branchType  host    Set to 0 for relative branch (BRA), set to 1 for branch to subroutine (BSR)
 * @param o_streamLenInWords  host    Actual size of PORE instruction(s) in 32-bit words
 * @param o_streamOutput  BigEndian    Pointer to allocated local memory to write PORE image into
 *
 * @return uint32_t  Error return codes
 *     P8_PORE_SUCCESS_RC       : No errors
 *     P8_PORE_IMAGE_TOO_BIG_RC : size of PORE image exceeded allowed space
 *     P8_PORE_XXX_RC           : other errors...
 */
uint32_t p8_pore_gen_relbranch( uint32_t i_offset,
				 uint32_t i_maxStreamLenInWords,
				 uint32_t i_branchType,
				 uint32_t* o_streamLenInWords,
				 uint32_t* o_streamOutput );

/**
 * Generate a set of PORE instructions that will perform a branch operation
 *  to an absolute address.
 *
 * @param i_address  host    Absolute address to branch to
 * @param i_maxStreamLenInWords  host    Max space available for resulting PORE instruction(s) in 32-bit words
 * @param o_streamLenInWords  host    Actual size of PORE instruction(s) in 32-bit words
 * @param o_streamOutput  host    Pointer to allocated local memory to write PORE image into
 *
 * @return uint32_t  Error return codes
 *     P8_PORE_SUCCESS_RC       : No errors
 *     P8_PORE_IMAGE_TOO_BIG_RC : size of PORE image exceeded allowed space
 *     P8_PORE_XXX_RC           : other errors...
 */
uint32_t p8_pore_gen_absbranch( uint32_t i_address,
				 uint32_t i_maxStreamLenInWords,
				 uint32_t* o_streamLenInWords,
				 uint32_t* o_streamOutput );

/**
 * Generate a set of PORE instructions that are invalid and will cause an
 *  error.  It is used to populate a region of memory that the PORE shouldn't
 *  execute.
 *
 * @param i_maxStreamLenInWords  host    Max space available for resulting PORE instruction(s) in 32-bit words
 * @param o_streamOutput  BigEndian    Pointer to allocated local memory to write PORE image into
 *
 * @return uint32_t  Error return codes
 *     P8_PORE_SUCCESS_RC       : No errors
 *     P8_PORE_IMAGE_TOO_BIG_RC : size of PORE image exceeded allowed space
 *     P8_PORE_XXX_RC           : other errors...
 */
uint32_t p8_pore_fill_invalid( uint32_t i_maxStreamLenInWords,
				uint32_t* o_streamOutput );

/**
 * Generate a set of PORE instructions that are return statements.  It is used
 *  to populate a region of memory that the PORE should return from.
 *
 * @param i_maxStreamLenInWords  host    Max space available for resulting PORE instruction(s) in 32-bit words
 * @param o_streamOutput  BigEndian    Pointer to allocated local memory to write PORE image into
 *
 * @return uint32_t  Error return codes
 *     P8_PORE_SUCCESS_RC       : No errors
 *     P8_PORE_IMAGE_TOO_BIG_RC : size of PORE image exceeded allowed space
 *     P8_PORE_XXX_RC           : other errors...
 */
uint32_t p8_pore_fill_return( uint32_t i_maxStreamLenInWords,
			       uint32_t* o_streamOutput );

/**
 * Generate a WAIT PORE instruction.
 *
 * @param i_wait  host    Number of pcb_nclk cycles to wait
 * @param i_maxStreamLenInWords  host    Max space available for resulting PORE instruction(s) in 32-bit words
 * @param o_streamLenInWords  host    Actual size of PORE instruction(s) in 32-bit words
 * @param o_streamOutput  BigEndian    Pointer to allocated local memory to write PORE image into
 *
 * @return uint32_t  Error return codes
 *     P8_PORE_SUCCESS_RC       : No errors
 *     P8_PORE_IMAGE_TOO_BIG_RC : size of PORE image exceeded allowed space
 *     P8_PORE_XXX_RC           : other errors...
 */
uint32_t p8_pore_gen_wait( uint32_t i_wait,
			    uint32_t i_maxStreamLenInWords,
			    uint32_t* o_streamLenInWords,
			    uint32_t* o_streamOutput );


#endif /* _P8_PORE_H */

/*
*************** Do not edit this area ***************
This section is automatically updated by CVS when you check in this file.
Be sure to create CVS comments when you commit so that they can be included here.

$Log: p8_pore_api.h,v $
Revision 1.2  2012/04/11 16:58:29  cmolsen
Removed #define of __PORE_INLINE_ASSEMBLER_C__

Revision 1.1  2011/08/25 12:28:04  yjkim
initial checkin

Revision 1.8  2010/08/31 14:47:15  schwartz
Changed comments about scom operations to include SCOM in the name

Revision 1.7  2010/08/30 23:27:16  schwartz
Added TRACE statements to include specified number of arguments
Defined branch type constants
Added constant for last scom op used to check if operation input to gen_scan is valid
Added mult spr error constant
Added p7p_pore_gen_wait API
Changed additional C++ style comments to C style
Initialized all variables to 0
Removed FTRACE statements
Added additional information to trace statements
Updated gen_scom to use the defined operation constants
Updated branch gen_relbranch to use defined branch type constants
Added rc check for calls to p7p_pore_gen_cpureg_status and p7p_pore_span_128byte_boundary subroutines

Revision 1.6  2010/08/26 03:57:02  schwartz
Changed comments to C-style
Changed "" to <> for #includes
Moved RINGINFO struct and RINGINDEX constant into separate object file, includes created static_data.h file
Put p7p_pore in front of #defines
Removed ring length from ringInfoStruct
Renamed scom operators to have SCOM in the name
Fixed gen_scan to use SCANRD and SCANWR pore instructions
Fixed compiler warnings

Revision 1.5  2010/07/01 21:42:11  schwartz
Included format (host or big endian) in parameter definitions

Revision 1.4  2010/06/23 23:09:05  schwartz
Updated ordering of include statements so p7p_pore_api_custom.h is first
Updated definition of gen_cpureg to include coreIndex and threadIndex

Revision 1.3  2010/05/24 02:32:07  schwartz
Fixed errors that appear when using -Werrors flag
Added in cvs logging (hopefully)


*/

