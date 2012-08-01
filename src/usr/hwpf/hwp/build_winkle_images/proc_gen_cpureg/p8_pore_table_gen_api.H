/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/build_winkle_images/pore_gen_cpureg/p8_pore_table_gen_api.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
/*------------------------------------------------------------------------------*/
/* *! (C) Copyright International Business Machines Corp. 2012                  */
/* *! All Rights Reserved -- Property of IBM                                    */
/* *! *** IBM Confidential ***                                                  */
/*------------------------------------------------------------------------------*/
/* *! TITLE :       p8_pore_table_gen_api                                       */
/* *! DESCRIPTION : Contains all external APIs used by firmware (PHYP) to       */
//                  generate/modify the P8 PORE SLW image with /Ramming and
//                  Scomming specific instructions to be executed on exit from
//                  Sleep/Winkle. Also contains definitions for the ramming
//                  PORE code.
/* *! OWNER NAME :  Michael Olsen            Email: cmolsen@us.ibm.com          */
//
/* *! COMMENTS :    *** VERY IMPORTANT ***                                      */
//                  The "Shared RAM section", the "Pore RAM section" and the
//                  "C-code RAM section" must closely match eachother.
//
/*------------------------------------------------------------------------------*/

#ifndef _P8_PORE_TABLE_GEN_API_H
#define _P8_PORE_TABLE_GEN_API_H

/********************************************************************/
/* Shared RAM section  -  begin                                     */
/* This section MUST perfectly match the "Pore/C-code RAM section". */
/********************************************************************/
// Header defs (P8&PORE 64-bit notation where bits are numbered from left-to-right).
// (Some of these defs are used in the c-specific section further down.)
// -----------------------------------------------------------------------------
// Note:  SPR register numbers have a swizzle about them per PPC architecture
// spr(instruction) <- spr5:9 || spr0:4
//
// For the PGAS routine, it is assumed that the API does the swizzling upon
// building the instruction held in this structure
//
//    Header configuration: CPU Register Operation Header
//    0       - End:  1=End; 0=More
//    1       - Reserved
//    2:3     - Type
//                00: MTSPR
//                01: MTGPR
//                10: Reserved
//                11: Reserved
//    4:13    - SPR number in non-swizzled form (0:9)
//    14:15   - Reserved for SPR nunmber expansion
//    16:18   - Thread ID
//    19:31   - Reserved

#define RAM_HEADER_END_START      0
#define RAM_HEADER_END_MASK      BITS(RAM_HEADER_END_START,1)
#define RAM_HEADER_TYPE_START     2
#define RAM_HEADER_TYPE_MASK     BITS(RAM_HEADER_TYPE_START,2)
#define RAM_HEADER_SPRN_START     4
#define RAM_HEADER_SPRN_MASK     BITS(RAM_HEADER_SPRN_START,10)
#define RAM_HEADER_THREAD_START  16
#define RAM_HEADER_THREAD_MASK   BITS(RAM_HEADER_THREAD_START,3)
#define RAM_INSTR_START          32
#define RAM_INSTR_MASK           BITS(RAM_INSTR_START,32)
// MTSPR instr defs
#define RAM_MTSPR_INSTR_TEMPL    ( ( (uint64_t)31<<(63-5) | (uint64_t)467<<(63-30) ) )
#define RAM_MTSPR_SPR_START      11
#define RAM_MTSPR_SPR_MASK       BITS(RAM_MTSPR_SPR_START,10)
// Thread align defs
#define RAM_HEADER_THREAD_RALIGN ( 61-16 )  // 3 Bit shift right amount
#define RAM_HEADER_THREAD_LALIGN ( 61-16 )  // 3 Bit shift left amount
/********************************************************************/
/* Shared RAM section  -  end                                       */
/********************************************************************/


#ifdef FOR_PORE_RAMMING

// Thread status
CONST_UINT64_T( PROC_RAS_STAT_10013002                , ULL(0x10013002) );

// TCTL RAS Status (for each thread)
// Note:  the address is not included in the name to ease PGAS indexing
// of these registers
CONST_UINT64_T( EX_PERV_TCTL0_R_STAT                  , ULL(0x10013002) );
CONST_UINT64_T( EX_PERV_TCTL1_R_STAT                  , ULL(0x10013012) );
CONST_UINT64_T( EX_PERV_TCTL2_R_STAT                  , ULL(0x10013022) );
CONST_UINT64_T( EX_PERV_TCTL3_R_STAT                  , ULL(0x10013032) );
CONST_UINT64_T( EX_PERV_TCTL4_R_STAT                  , ULL(0x10013042) );
CONST_UINT64_T( EX_PERV_TCTL5_R_STAT                  , ULL(0x10013052) );
CONST_UINT64_T( EX_PERV_TCTL6_R_STAT                  , ULL(0x10013062) );
CONST_UINT64_T( EX_PERV_TCTL7_R_STAT                  , ULL(0x10013072) );

// Thread scratch registers
// Note:  the address is not included in the name to ease PGAS indexing
// of these registers
CONST_UINT64_T( EX_PERV_SCRATCH0                      , ULL(0x10013283) );
CONST_UINT64_T( EX_PERV_SCRATCH1                      , ULL(0x10013284) );
CONST_UINT64_T( EX_PERV_SCRATCH2                      , ULL(0x10013285) );
CONST_UINT64_T( EX_PERV_SCRATCH3                      , ULL(0x10013286) );
CONST_UINT64_T( EX_PERV_SCRATCH4                      , ULL(0x10013287) );
CONST_UINT64_T( EX_PERV_SCRATCH5                      , ULL(0x10013288) );
CONST_UINT64_T( EX_PERV_SCRATCH6                      , ULL(0x10013289) );
CONST_UINT64_T( EX_PERV_SCRATCH7                      , ULL(0x1001328A) );

// Max # of polling attempts. SLW ops have no quiescent needs, so low #.
CONST_UINT32_T( SLW_MAX_RAM_POLLS               , ULL(0x04) );

// mfspr gpr0, scratch0  opcode left-shifted 29 bits, ready for ramming.
CONST_UINT64_T( MFSPR_GPR0_SCRATCH0_RAM_READY, (0x000000007C1542A6<<29));

#ifdef __ASSEMBLER__

/***********************************************************************/
/* Pore RAM section  -  begin                                          */
/* This section MUST perfectly match the "Shared/C-code RAM  section". */
/***********************************************************************/
.set    RAM_HEADER, 0
.set    RAM_INSTR,  4
.set    RAM_DATA,   8
.set    RAM_ENTRY_LENGTH, 16
/***********************************************************************/
/* Pore RAM section  -  end                                            */
/***********************************************************************/

#endif  // __ASSEMBLER__


#else   // Not FOR_PORE_RAMMING


#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "pore_bitmanip.H"

// Header defs (C notation where bits are numbered from right-to-left, and reducing to 32-bit)
#define RAM_HEADER_END_START_C    ( 31-RAM_HEADER_END_START+1-1 )
#define RAM_HEADER_END_MASK_C      (uint32_t)(RAM_HEADER_END_MASK>>32)
#define RAM_HEADER_TYPE_START_C    ( 31-RAM_HEADER_TYPE_START+1-2 )
#define RAM_HEADER_TYPE_MASK_C    (uint32_t)(RAM_HEADER_TYPE_MASK>>32)
#define RAM_HEADER_SPRN_START_C    ( 31-RAM_HEADER_SPRN_START+1-10 )
#define RAM_HEADER_SPRN_MASK_C    (uint32_t)(RAM_HEADER_SPRN_MASK>>32)
#define RAM_HEADER_THREAD_START_C  ( 31-RAM_HEADER_THREAD_START+1-3 )
#define RAM_HEADER_THREAD_MASK_C  (uint32_t)(RAM_HEADER_THREAD_MASK>>32)
// MTSPR instr defs
#define RAM_MTSPR_INSTR_TEMPL_C    ( ( (uint32_t)31<<(31-5) | (uint32_t)467<<(31-30) ) )
#define RAM_MTSPR_SPR_START_C      ( 31-RAM_MTSPR_SPR_START+1-10 )
//#define RAM_MTSPR_SPR_MASK_C      (uint32_t)(BITS(RAM_MTSPR_SPR_START,10)>>32)
#define RAM_MTSPR_SPR_MASK_C      (uint32_t)(RAM_MTSPR_SPR_MASK>>32)

/* Other defs needed for ramming */
// TOC names
#define SLW_HOST_REG_VECTOR_TOC_NAME     "slw_host_reg_vector"
#define SLW_HOST_SCOM_VECTOR_TOC_NAME    "slw_host_scom_vector"
#define SLW_HOST_REG_TABLE_TOC_NAME      "slw_core_reg_table"

// Defines for slw_build() to update "host_runtime_scom" w/pointer to "sub_slw_runtime_scom" at SLW image build time.
#define HOST_RUNTIME_SCOM_TOC_NAME  "host_runtime_scom"    // Null 1st, then fill w/addr of SLW_RUNTIME_SCOM_TOC_NAME
#define SLW_RUNTIME_SCOM_TOC_NAME   "sub_slw_runtime_scom"

// RAM table defines
#define XIPSIZE_RAM_ENTRY       ( (sizeof(RamTableEntry)+7)/8*8 )
#define SLW_MAX_CORES           16
#define SLW_MAX_CPUREGS_CORE     8
#define SLW_MAX_CPUREGS_THREADS  2 // Was 3 at some point, when MSR reg was included?
#define SLW_CORE_THREADS         8
#define SLW_MAX_CPUREGS_OPS     (  SLW_MAX_CPUREGS_CORE + \
                                   SLW_CORE_THREADS*SLW_MAX_CPUREGS_THREADS )
//  $$ mww 2012-07-19 SLW_SLW_SECTION_SIZE removed? needed by proc_slw_build
#define SLW_SLW_SECTION_SIZE    (  SLW_MAX_CORES * SLW_MAX_CPUREGS_OPS * XIPSIZE_RAM_ENTRY )
#define SLW_RAM_TABLE_SIZE      (  SLW_MAX_CORES * SLW_MAX_CPUREGS_OPS * XIPSIZE_RAM_ENTRY )

// SCOM table defines
#define XIPSIZE_SCOM_ENTRY      16
#define SLW_MAX_SCOMS           32
#define SLW_SCOM_TABLE_SPACE_PER_CORE ( (SLW_MAX_SCOMS+1)*XIPSIZE_SCOM_ENTRY ) // Add 1 for RNNN IIS
#define SLW_SCOM_TABLE_SIZE     (  SLW_MAX_CORES * SLW_SCOM_TABLE_SPACE_PER_CORE )

// SCOM/CID masks and ranges
#define P8_CID_EX_LOW         0x10        // Lowest EX chiplet addr
#define P8_CID_EX_HIGH        0x1f        // Highest EX chiplet addr

// SCOM Operators
#define P8_PORE_SCOM_FIRST_OP 1  // First supported INPUT Scom operation.
#define P8_PORE_SCOM_APPEND   0  // Add Scom to the end of table (only used internally)
#define P8_PORE_SCOM_REPLACE  1  // Replace existing Scom, or append to end of table
#define P8_PORE_SCOM_OR       2  // Overlay data onto existing Scom by bitwise OR
#define P8_PORE_SCOM_AND      3  // Overlay data onto existing Scom by bitwise AND
#define P8_PORE_SCOM_NOOP     4  // Replace existing Scom PORE NOP instruction
#define P8_PORE_SCOM_RESET    5  // Delete all entries for given coreID. Repl w/RNNN IIS
#define P8_PORE_SCOM_LAST_OP  5  // Keep track of the last op for checking correctness of op input


// Return codes
#define SLW_RAM_SUCCESS                      0
#define SLW_RAM_HEADERS_NOT_SYNCED           1
#define SLW_RAM_IMAGE_SIZE_MISMATCH          2
#define SLW_RAM_TABLE_ENTRY_OVERFLOW         3
#define SLW_RAM_CODE_ERROR                   4
#define SLW_RAM_INVALID_PARAMETER            5
#define SLW_RAM_WARNING_TABLE_CONTAMINATION  6


#ifdef __cpluscplus
extern "C" {
#endif

/********************************************************************/
/* C-code RAM section  -  begin                                     */
/* This section MUST perfectly match the "Shared/Pore RAM section". */
/********************************************************************/
typedef struct ram_instr_t  {
  uint32_t  header;
  uint32_t  instr;
  uint64_t  data;
} RamTableEntry;
/********************************************************************/
/* C-code RAM section  -  end                                       */
/********************************************************************/

// SLW supported SPR registers
typedef struct {
  const char *name;
  uint32_t   value;
  uint32_t   swizzled;
} SlwSprRegs;


/*  Name:             p8_pore_gen_cpureg()
 *  Description:      Populates ramming entries in the .slw section
 *  Parameter list:   i_image     - pointer to SLW mainstore image
 *                    i_sizeImage - size of SLW mainstore image
 *                    i_regName   - unswizzled SPR register value
 *                    i_regData   - data to write to SPR register
 *                    i_coreId    - the core ID to operate on
 *                    i_threadId  - the thread ID to operate on
 */
uint32_t p8_pore_gen_cpureg(void      *io_image,
                            uint32_t  i_sizeImage,
                            uint32_t  i_regName,
                            uint64_t  i_regData,
                            uint32_t  i_coreId,
                            uint32_t  i_threadId);

/*  Name:             p8_pore_gen_scom()
 *  Description:      Populates scom entries in the .slw section
 *  Parameter list:   i_image     - pointer to SLW mainstore image
 *                    i_sizeImage - size of SLW mainstore image
 *                    i_scomAddr  - scom register address
 *                    i_scomData  - 64-bit data to put in scom register
 *                    i_operation - what to do with the scom data
 *                    i_coreId    - the core ID [0:15]
 */
uint32_t p8_pore_gen_scom(void      *io_image,
                          uint32_t  i_sizeImage,
                          uint32_t  i_scomAddr,
                          uint32_t  i_coreId,
                          uint64_t  i_scomData,
                          uint32_t  i_operation);

#ifdef __cpluscplus
}
#endif

#endif  // FOR_PORE_RAMMING

#endif  // _P8_PORE_TABLE_GEN_API_H
