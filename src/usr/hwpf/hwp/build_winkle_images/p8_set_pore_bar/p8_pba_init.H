/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_set_pore_bar/p8_pba_init.H $ */
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


//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Klaus P. Gungl         Email: kgungl@de.ibm.com
// *!
// *! General Description:
// *!        
// *!  include file for pba_init with constants, definitions, prototypes
// *!
//------------------------------------------------------------------------------
//  

#ifndef _PROC_PBAINIT_H_
#define _PROC_PBAINIT_H_

#include "p8_scom_addresses.H"

typedef fapi::ReturnCode (*p8_pba_init_FP_t) (const fapi::Target& , uint64_t );

// constant definitions for valid command scope. LIMIT is used by setup routine for plausibility checking.

#define PBA_CMD_SCOPE_NODAL    0x00
#define PBA_CMD_SCOPE_GROUP    0x01
#define PBA_CMD_SCOPE_SYSTEM   0x02
#define PBA_CMD_SCOPE_RGP      0x03
#define PBA_CMD_SCOPE_FOREIGN0 0x04
#define PBA_CMD_SCOPE_FOREIGN1 0x05
#define PBA_CMD_SCOPE_LIMIT    0x06

enum cmd_scope_t 
{
    CMD_SCOPE_NODAL, 
    CMD_SCOPE_GROUP, 
    CMD_SCOPE_SYSTEM, 
    CMD_SCOPE_RGP, 
    CMD_SCOPE_FOREIGN0,  
    CMD_SCOPE_FOREIGN1 
};
// enum cmd_scope_type {NODAL, GROUP, SYSTEM, RGP, FOREIGN0, FOREIGN1 };


// addresses of PBA and PBABAR, actually a duplicate of definitions in "p8_scom_addresses.H" but here an array to be indexed.
const uint64_t PBA_BARs[4] = 
{
    PBA_BAR0_0x02013F00, 
    PBA_BAR1_0x02013F01, 
    PBA_BAR2_0x02013F02, 
    PBA_BAR3_0x02013F03
};

const uint64_t PBA_BARMSKs[4] = 
{
    PBA_BARMSK0_0x02013F04, 
    PBA_BARMSK1_0x02013F05, 
    PBA_BARMSK2_0x02013F06, 
    PBA_BARMSK3_0x02013F07
};

const uint64_t PBA_SLVCTLs[4] = 
{
    PBA_SLVCTL0_0x00064004, 
    PBA_SLVCTL1_0x00064005, 
    PBA_SLVCTL2_0x00064006, 
    PBA_SLVCTL3_0x00064007};

// bar mask is valid for bits 23 to 43, in a 64bit value this is
//           1         2         3         4         5         6 
// 0123456789012345678901234567890123456789012345678901234567890123
// 0000000000000000000000011111111111111111111100000000000000000000
//    0   0   0   0   0   1   F   F   F   F   F   0   0   0   0   0
// 0000000000000011111111111111111111111111111100000000000000000000
//    0   0   0   3   F   F   F   F   F   F   F   0   0   0   0   0
//                       0123456701234567 
#define BAR_MASK_LIMIT 0x000001FFFFF00000ull
#define BAR_ADDR_LIMIT 0x0003FFFFFFF00000ull

// structure of values for cmd_scope, pba and pbabar initialization
typedef struct {
  cmd_scope_t cmd_scope;
  uint64_t addr;
  uint64_t size;
} struct_pba_bar_msk_scope_init_type;

typedef struct {
  struct_pba_bar_msk_scope_init_type regs0;
  struct_pba_bar_msk_scope_init_type regs1;
  struct_pba_bar_msk_scope_init_type regs2;
  struct_pba_bar_msk_scope_init_type regs3;
} pba_init_type;

typedef struct {
  unsigned long reserved_3:20;
  unsigned long addr:30;
  unsigned short reserved_2:10;
  char reserved_1:1;
  uint8_t cmd_scope:3;
} struct_pba_bar_fields_type;

typedef struct {
  unsigned long reserved_1:23;
  unsigned long mask:21;
  unsigned long reserved_2:20;
} struct_pba_barmsk_fields_type;

typedef union {
  struct_pba_bar_fields_type fields;
  uint64_t value;
} bar_reg_type;

typedef union {
  struct_pba_barmsk_fields_type fields ;
  uint64_t value;
} barmsk_reg_type;

typedef struct {
  bar_reg_type     bar_reg;
  barmsk_reg_type  barmsk_reg; 
} struct_pba_bar_init_type;


typedef struct {
  struct struct_pba_bar{
    char cmd_scope:3;
    char reserved_1:1;
    unsigned short reserved_2:10;
    unsigned long addr:30;
    unsigned long reserved_3:20;
  }; 
  struct struct_pba_barmsk{
    unsigned long reserved_1:23;
    unsigned long mask:21;
    unsigned long reserved_2:20;
  };
} struct_pba_bar_init_type_1;

typedef struct {
  struct_pba_bar_init_type pba_bar0_init;
  struct_pba_bar_init_type pba_bar1_init;
  struct_pba_bar_init_type pba_bar2_init;
  struct_pba_bar_init_type pba_bar3_init;
} struct_all_pba_bar_init_type;


typedef uint64_t pba_slvctl_type;


typedef union pbaxcfg_typ{
   uint64_t value;
   struct {
     unsigned long  reserved_0 :20;
     unsigned char  ATTR_PM_PBAX_RCV_RESERV_TIMEOUT :5 ;
     unsigned long  reserved_1 :2;
     unsigned char  ATTR_PM_PBAX_SND_RETRY_COUNT_OVERCOMMIT_ENABLE :1 ;
     unsigned short ATTR_PM_PBAX_SND_RETRY_THRESHOLD :8 ;
     unsigned short ATTR_PM_PBAX_SND_RESERV_TIMEOUT  :5 ;
     unsigned long  reserved_2 :23 ;
   } fields;
} pbaxcfg_t;
   



// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------

extern "C" 
{

fapi::ReturnCode 
p8_pba_init (const fapi::Target& i_target, 
                     uint64_t mode
              );


} // extern "C"



#endif // _PROC_PBAINITQ_H_


