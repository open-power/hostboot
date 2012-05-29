/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/build_winkle_images/proc_slw_build/p8_pore_table_gen_api.H $
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
//                  generate/modify the P8 PORE SLW image.
/* *! OWNER NAME :  Michael Olsen            Email: cmolsen@us.ibm.com          */
/* *! ADDITIONAL COMMENTS :                                                     */
//                  - Start file: p7p_pore_api.h
//                  - _table_entry structs must agree with Greg's proc_slw_ram.H
//
/*------------------------------------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "pore_bitmanip.H"
#include "sbe_xip_image.h"

//#ifndef _P8_PORE_API_H
//#define _P8_PORE_API_H

//#include <p8_pore_api_custom.h>
//#include <p8_pore_image.h>
//#include <p8_pore_api_const.h>

/* Common header for *.c and .S ramming code: Call it ../sbe/proc_slw_ram.H ? */
// Header defs (P8&PORE 64-bit notation where bits are numbered from left-to-right)
#define RAM_HEADER_END_START    0
#define RAM_HEADER_END_MASK      BITS(RAM_HEADER_END_START,1)
#define RAM_HEADER_TYPE_START    2
#define RAM_HEADER_TYPE_MASK    BITS(RAM_HEADER_TYPE_START,2)
#define RAM_HEADER_SPRN_START    4
#define RAM_HEADER_SPRN_MASK    BITS(RAM_HEADER_SPRN_START,10)
#define RAM_HEADER_THREAD_START  16
#define RAM_HEADER_THREAD_MASK  BITS(RAM_HEADER_THREAD_START,3)
// MTSPR instr defs
#define RAM_MTSPR_INSTR_TEMPL    ( ( (uint64_t)31<<(63-5) | (uint64_t)467<<(63-30) ) )
#define RAM_MTSPR_SPR_START      11
#define RAM_MTSPR_SPR_MASK      BITS(RAM_MTSPR_SPR_START,10)
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

// Defines for slw_build() to update "host_runtime_scome" w/pointer to "slw_host_runtime" at SLW image build time.
#define HOST_RUNTIME_SCOM_TOC_NAME  "host_runtime_scom"    // Null 1st, then fill w/addr of SLW_HOST_RUNTIME_TOC_NAME
#define SLW_HOST_RUNTIME_TOC_NAME   "slw_host_runtime"


// RAM table defines
#define XIPSIZE_RAM_ENTRY       (  (sizeof(RamTableEntry)+7)/8*8 )
#define SLW_MAX_CORES           16
#define SLW_MAX_CPUREGS_CORE     8
#define SLW_MAX_CPUREGS_THREADS  3
#define SLW_CORE_THREADS         8
#define SLW_MAX_CPUREGS_OPS     (  SLW_MAX_CPUREGS_CORE + \
                                   SLW_CORE_THREADS*SLW_MAX_CPUREGS_THREADS )
#define SLW_SLW_SECTION_SIZE    (  SLW_MAX_CORES * SLW_MAX_CPUREGS_OPS * XIPSIZE_RAM_ENTRY )

// Return codes
#define SLW_RAM_SUCCESS                 0
#define SLW_RAM_HEADERS_NOT_SYNCED      1
#define SLW_RAM_IMAGE_SIZE_MISMATCH     2
#define SLW_RAM_TABLE_ENTRY_OVERFLOW    3
#define SLW_RAM_CODE_ERROR              4
#define SLW_RAM_INVALID_PARAMETER       5
#define SLW_RAM_WARNING_TABLE_CONTAMINATION 10

#ifdef __cpluscplus
extern "C" {
#endif

typedef struct ram_instr_t  {
  uint32_t  header;
  uint32_t  instr;
  uint64_t  data;
} RamTableEntry;

// SLW supported SPR registers
typedef struct {
  const char *name;
  uint32_t   value;
  uint32_t   swizzled;
}  SlwSprRegs;

const SlwSprRegs SLW_SPR_REGS[] = {  
  /*    name          value         swizzled              */
  // ...core regs
  { "P8_SPR_HRMOR",    313,  (  313>>5 | ( 313&0x1f)<<5 ) },
  { "P8_SPR_HMEER",    337,  (  337>>5 | ( 337&0x1f)<<5 ) },
  { "P8_SPR_PMICR",    852,  (  852>>5 | ( 852&0x1f)<<5 ) },
  { "P8_SPR_PMCR",     884,  (  884>>5 | ( 884&0x1f)<<5 ) },
  { "P8_SPR_HID0",    1008,  ( 1008>>5 | (1008&0x1f)<<5 ) },
  { "P8_SPR_HID1",    1009,  ( 1009>>5 | (1009&0x1f)<<5 ) },
  { "P8_SPR_HID4",    1012,  ( 1012>>5 | (1012&0x1f)<<5 ) },
  { "P8_SPR_HID5",    1014,  ( 1014>>5 | (1014&0x1f)<<5 ) },
  // ...thread regs
  { "P8_SPR_HSPRG0",   304,  (  304>>5 | ( 304&0x1f)<<5 ) },
  { "P8_SPR_LPCR",     318,  (  318>>5 | ( 318&0x1f)<<5 ) },
  // Greg, this is NOT in jbishop's SS. Got it from ur ST. But 1023 is max!
  { "P8_SPR_MSR",     2000,  ( 2000>>5 | (2000&0x1f)<<5 ) }
};

const int SLW_SPR_REGS_SIZE = sizeof(SLW_SPR_REGS)/sizeof(SLW_SPR_REGS[0]);


/*  Name:              p8_pore_gen_cpureg()
 *  Description:      Populates ramming entries in the .slw section
 *  Parameter list:    i_image     -  pointer to SLW mainstore image
 *                    i_sizeImage  -  size of SLW mainstore image
 *                    i_regName   - unswizzled SPR register value
 *                    i_regData   - data to write to SPR register
 *                    i_coreId     - the core ID to operate on
 *                    i_threadId   - the thread ID to operate on
 */
uint32_t p8_pore_gen_cpureg(void      *i_image,
                            uint32_t  i_sizeImage, 
                            uint32_t  i_regName,
                            uint64_t  i_regData,
                            uint32_t  i_coreId,
                            uint32_t  i_threadId);

#ifdef __cpluscplus
}
#endif
