/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/pmlib/include/registers/ocb_firmware_registers.h $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
#ifndef __OCB_FIRMWARE_REGISTERS_H__
#define __OCB_FIRMWARE_REGISTERS_H__

// $Id$
// $Source$
//-----------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2019
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//-----------------------------------------------------------------------------

/// \file ocb_firmware_registers.h
/// \brief C register structs for the OCB unit

// *** WARNING *** - This file is generated automatically, do not edit.

#ifndef SIXTYFOUR_BIT_CONSTANT
    #ifdef __ASSEMBLER__
        #define SIXTYFOUR_BIT_CONSTANT(x) x
    #else
        #define SIXTYFOUR_BIT_CONSTANT(x) x##ull
    #endif
#endif

#ifndef __ASSEMBLER__

#include <stdint.h>




typedef union ocb_oisr0
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t trace_trigger : 1;
        uint32_t occ_error : 1;
        uint32_t gpe2_error : 1;
        uint32_t gpe3_error : 1;
        uint32_t check_stop_gpe2 : 1;
        uint32_t check_stop_gpe3 : 1;
        uint32_t occ_malf_alert : 1;
        uint32_t pvref_error : 1;
        uint32_t ipi2 : 1;
        uint32_t ipi3 : 1;
        uint32_t debug_trigger : 1;
        uint32_t spare : 1;
        uint32_t pbax_pgpe_attn : 1;
        uint32_t pbax_pgpe_push0 : 1;
        uint32_t pbax_pgpe_push1 : 1;
        uint32_t pba_overcurrent_indicator : 1;
        uint32_t pmc_pcb_intr_type0_pending : 1;
        uint32_t pmc_pcb_intr_type1_pending : 1;
        uint32_t pmc_pcb_intr_type2_pending : 1;
        uint32_t pmc_pcb_intr_type3_pending : 1;
        uint32_t pmc_pcb_intr_type4_pending : 1;
        uint32_t pmc_pcb_intr_type5_pending : 1;
        uint32_t pmc_pcb_intr_type6_pending : 1;
        uint32_t pmc_pcb_intr_type7_pending : 1;
        uint32_t pmc_pcb_intr_type8_pending : 1;
        uint32_t pmc_pcb_intr_type9_pending : 1;
        uint32_t pmc_pcb_intr_typea_pending : 1;
        uint32_t pmc_pcb_intr_typeb_pending : 1;
        uint32_t pmc_pcb_intr_typec_pending : 1;
        uint32_t pmc_pcb_intr_typed_pending : 1;
        uint32_t pmc_pcb_intr_typee_pending : 1;
        uint32_t pmc_pcb_intr_typef_pending : 1;
#else
        uint32_t pmc_pcb_intr_typef_pending : 1;
        uint32_t pmc_pcb_intr_typee_pending : 1;
        uint32_t pmc_pcb_intr_typed_pending : 1;
        uint32_t pmc_pcb_intr_typec_pending : 1;
        uint32_t pmc_pcb_intr_typeb_pending : 1;
        uint32_t pmc_pcb_intr_typea_pending : 1;
        uint32_t pmc_pcb_intr_type9_pending : 1;
        uint32_t pmc_pcb_intr_type8_pending : 1;
        uint32_t pmc_pcb_intr_type7_pending : 1;
        uint32_t pmc_pcb_intr_type6_pending : 1;
        uint32_t pmc_pcb_intr_type5_pending : 1;
        uint32_t pmc_pcb_intr_type4_pending : 1;
        uint32_t pmc_pcb_intr_type3_pending : 1;
        uint32_t pmc_pcb_intr_type2_pending : 1;
        uint32_t pmc_pcb_intr_type1_pending : 1;
        uint32_t pmc_pcb_intr_type0_pending : 1;
        uint32_t pba_overcurrent_indicator : 1;
        uint32_t pbax_pgpe_push1 : 1;
        uint32_t pbax_pgpe_push0 : 1;
        uint32_t pbax_pgpe_attn : 1;
        uint32_t spare : 1;
        uint32_t debug_trigger : 1;
        uint32_t ipi3 : 1;
        uint32_t ipi2 : 1;
        uint32_t pvref_error : 1;
        uint32_t occ_malf_alert : 1;
        uint32_t check_stop_gpe3 : 1;
        uint32_t check_stop_gpe2 : 1;
        uint32_t gpe3_error : 1;
        uint32_t gpe2_error : 1;
        uint32_t occ_error : 1;
        uint32_t trace_trigger : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oisr0_t;



typedef union ocb_oisr0_clr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t trace_trigger : 1;
        uint32_t occ_error : 1;
        uint32_t gpe2_error : 1;
        uint32_t gpe3_error : 1;
        uint32_t check_stop_gpe2 : 1;
        uint32_t check_stop_gpe3 : 1;
        uint32_t occ_malf_alert : 1;
        uint32_t pvref_error : 1;
        uint32_t ipi2 : 1;
        uint32_t ipi3 : 1;
        uint32_t debug_trigger : 1;
        uint32_t spare : 1;
        uint32_t pbax_pgpe_attn : 1;
        uint32_t pbax_pgpe_push0 : 1;
        uint32_t pbax_pgpe_push1 : 1;
        uint32_t pba_overcurrent_indicator : 1;
        uint32_t pmc_pcb_intr_type0_pending : 1;
        uint32_t pmc_pcb_intr_type1_pending : 1;
        uint32_t pmc_pcb_intr_type2_pending : 1;
        uint32_t pmc_pcb_intr_type3_pending : 1;
        uint32_t pmc_pcb_intr_type4_pending : 1;
        uint32_t pmc_pcb_intr_type5_pending : 1;
        uint32_t pmc_pcb_intr_type6_pending : 1;
        uint32_t pmc_pcb_intr_type7_pending : 1;
        uint32_t pmc_pcb_intr_type8_pending : 1;
        uint32_t pmc_pcb_intr_type9_pending : 1;
        uint32_t pmc_pcb_intr_typea_pending : 1;
        uint32_t pmc_pcb_intr_typeb_pending : 1;
        uint32_t pmc_pcb_intr_typec_pending : 1;
        uint32_t pmc_pcb_intr_typed_pending : 1;
        uint32_t pmc_pcb_intr_typee_pending : 1;
        uint32_t pmc_pcb_intr_typef_pending : 1;
#else
        uint32_t pmc_pcb_intr_typef_pending : 1;
        uint32_t pmc_pcb_intr_typee_pending : 1;
        uint32_t pmc_pcb_intr_typed_pending : 1;
        uint32_t pmc_pcb_intr_typec_pending : 1;
        uint32_t pmc_pcb_intr_typeb_pending : 1;
        uint32_t pmc_pcb_intr_typea_pending : 1;
        uint32_t pmc_pcb_intr_type9_pending : 1;
        uint32_t pmc_pcb_intr_type8_pending : 1;
        uint32_t pmc_pcb_intr_type7_pending : 1;
        uint32_t pmc_pcb_intr_type6_pending : 1;
        uint32_t pmc_pcb_intr_type5_pending : 1;
        uint32_t pmc_pcb_intr_type4_pending : 1;
        uint32_t pmc_pcb_intr_type3_pending : 1;
        uint32_t pmc_pcb_intr_type2_pending : 1;
        uint32_t pmc_pcb_intr_type1_pending : 1;
        uint32_t pmc_pcb_intr_type0_pending : 1;
        uint32_t pba_overcurrent_indicator : 1;
        uint32_t pbax_pgpe_push1 : 1;
        uint32_t pbax_pgpe_push0 : 1;
        uint32_t pbax_pgpe_attn : 1;
        uint32_t spare : 1;
        uint32_t debug_trigger : 1;
        uint32_t ipi3 : 1;
        uint32_t ipi2 : 1;
        uint32_t pvref_error : 1;
        uint32_t occ_malf_alert : 1;
        uint32_t check_stop_gpe3 : 1;
        uint32_t check_stop_gpe2 : 1;
        uint32_t gpe3_error : 1;
        uint32_t gpe2_error : 1;
        uint32_t occ_error : 1;
        uint32_t trace_trigger : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oisr0_clr_t;



typedef union ocb_oisr0_or
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t trace_trigger : 1;
        uint32_t occ_error : 1;
        uint32_t gpe2_error : 1;
        uint32_t gpe3_error : 1;
        uint32_t check_stop_gpe2 : 1;
        uint32_t check_stop_gpe3 : 1;
        uint32_t occ_malf_alert : 1;
        uint32_t pvref_error : 1;
        uint32_t ipi2 : 1;
        uint32_t ipi3 : 1;
        uint32_t debug_trigger : 1;
        uint32_t spare : 1;
        uint32_t pbax_pgpe_attn : 1;
        uint32_t pbax_pgpe_push0 : 1;
        uint32_t pbax_pgpe_push1 : 1;
        uint32_t pba_overcurrent_indicator : 1;
        uint32_t pmc_pcb_intr_type0_pending : 1;
        uint32_t pmc_pcb_intr_type1_pending : 1;
        uint32_t pmc_pcb_intr_type2_pending : 1;
        uint32_t pmc_pcb_intr_type3_pending : 1;
        uint32_t pmc_pcb_intr_type4_pending : 1;
        uint32_t pmc_pcb_intr_type5_pending : 1;
        uint32_t pmc_pcb_intr_type6_pending : 1;
        uint32_t pmc_pcb_intr_type7_pending : 1;
        uint32_t pmc_pcb_intr_type8_pending : 1;
        uint32_t pmc_pcb_intr_type9_pending : 1;
        uint32_t pmc_pcb_intr_typea_pending : 1;
        uint32_t pmc_pcb_intr_typeb_pending : 1;
        uint32_t pmc_pcb_intr_typec_pending : 1;
        uint32_t pmc_pcb_intr_typed_pending : 1;
        uint32_t pmc_pcb_intr_typee_pending : 1;
        uint32_t pmc_pcb_intr_typef_pending : 1;
#else
        uint32_t pmc_pcb_intr_typef_pending : 1;
        uint32_t pmc_pcb_intr_typee_pending : 1;
        uint32_t pmc_pcb_intr_typed_pending : 1;
        uint32_t pmc_pcb_intr_typec_pending : 1;
        uint32_t pmc_pcb_intr_typeb_pending : 1;
        uint32_t pmc_pcb_intr_typea_pending : 1;
        uint32_t pmc_pcb_intr_type9_pending : 1;
        uint32_t pmc_pcb_intr_type8_pending : 1;
        uint32_t pmc_pcb_intr_type7_pending : 1;
        uint32_t pmc_pcb_intr_type6_pending : 1;
        uint32_t pmc_pcb_intr_type5_pending : 1;
        uint32_t pmc_pcb_intr_type4_pending : 1;
        uint32_t pmc_pcb_intr_type3_pending : 1;
        uint32_t pmc_pcb_intr_type2_pending : 1;
        uint32_t pmc_pcb_intr_type1_pending : 1;
        uint32_t pmc_pcb_intr_type0_pending : 1;
        uint32_t pba_overcurrent_indicator : 1;
        uint32_t pbax_pgpe_push1 : 1;
        uint32_t pbax_pgpe_push0 : 1;
        uint32_t pbax_pgpe_attn : 1;
        uint32_t spare : 1;
        uint32_t debug_trigger : 1;
        uint32_t ipi3 : 1;
        uint32_t ipi2 : 1;
        uint32_t pvref_error : 1;
        uint32_t occ_malf_alert : 1;
        uint32_t check_stop_gpe3 : 1;
        uint32_t check_stop_gpe2 : 1;
        uint32_t gpe3_error : 1;
        uint32_t gpe2_error : 1;
        uint32_t occ_error : 1;
        uint32_t trace_trigger : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oisr0_or_t;



typedef union ocb_oimr0
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_mask_n : 32;
#else
        uint32_t interrupt_mask_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oimr0_t;



typedef union ocb_oimr0_clr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_mask_n : 32;
#else
        uint32_t interrupt_mask_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oimr0_clr_t;



typedef union ocb_oimr0_or
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_mask_n : 32;
#else
        uint32_t interrupt_mask_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oimr0_or_t;



typedef union ocb_oitr0
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_type_n : 32;
#else
        uint32_t interrupt_type_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oitr0_t;



typedef union ocb_oitr0_clr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_type_n : 32;
#else
        uint32_t interrupt_type_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oitr0_clr_t;



typedef union ocb_oitr0_or
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_type_n : 32;
#else
        uint32_t interrupt_type_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oitr0_or_t;



typedef union ocb_oiepr0
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_edge_pol_n : 32;
#else
        uint32_t interrupt_edge_pol_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oiepr0_t;



typedef union ocb_oiepr0_clr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_edge_pol_n : 32;
#else
        uint32_t interrupt_edge_pol_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oiepr0_clr_t;



typedef union ocb_oiepr0_or
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_edge_pol_n : 32;
#else
        uint32_t interrupt_edge_pol_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oiepr0_or_t;



typedef union ocb_oinkr0
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_input_n : 32;
#else
        uint32_t interrupt_input_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oinkr0_t;



typedef union ocb_oisr1
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t debugger : 1;
        uint32_t trace_trigger : 1;
        uint32_t spare : 1;
        uint32_t pba_error : 1;
        uint32_t gpe0_error : 1;
        uint32_t gpe1_error : 1;
        uint32_t check_stop_ppc405 : 1;
        uint32_t external_trap : 1;
        uint32_t occ_timer0 : 1;
        uint32_t occ_timer1 : 1;
        uint32_t ipi0_hi_priority : 1;
        uint32_t ipi1_hi_priority : 1;
        uint32_t ipi4_hi_priority : 1;
        uint32_t i2cm_intr : 1;
        uint32_t spare_14 : 1;
        uint32_t dcm_intf_ongoing : 1;
        uint32_t pbax_occ_send_attn : 1;
        uint32_t pbax_occ_push0 : 1;
        uint32_t pbax_occ_push1 : 1;
        uint32_t pba_bcde_attn : 1;
        uint32_t pba_bcue_attn : 1;
        uint32_t occ_strm0_pull : 1;
        uint32_t occ_strm0_push : 1;
        uint32_t occ_strm1_pull : 1;
        uint32_t occ_strm1_push : 1;
        uint32_t occ_strm2_pull : 1;
        uint32_t occ_strm2_push : 1;
        uint32_t occ_strm3_pull : 1;
        uint32_t occ_strm3_push : 1;
        uint32_t ipi0_lo_priority : 1;
        uint32_t ipi1_lo_priority : 1;
        uint32_t ipi4_lo_priority : 1;
#else
        uint32_t ipi4_lo_priority : 1;
        uint32_t ipi1_lo_priority : 1;
        uint32_t ipi0_lo_priority : 1;
        uint32_t occ_strm3_push : 1;
        uint32_t occ_strm3_pull : 1;
        uint32_t occ_strm2_push : 1;
        uint32_t occ_strm2_pull : 1;
        uint32_t occ_strm1_push : 1;
        uint32_t occ_strm1_pull : 1;
        uint32_t occ_strm0_push : 1;
        uint32_t occ_strm0_pull : 1;
        uint32_t pba_bcue_attn : 1;
        uint32_t pba_bcde_attn : 1;
        uint32_t pbax_occ_push1 : 1;
        uint32_t pbax_occ_push0 : 1;
        uint32_t pbax_occ_send_attn : 1;
        uint32_t dcm_intf_ongoing : 1;
        uint32_t spare_14 : 1;
        uint32_t i2cm_intr : 1;
        uint32_t ipi4_hi_priority : 1;
        uint32_t ipi1_hi_priority : 1;
        uint32_t ipi0_hi_priority : 1;
        uint32_t occ_timer1 : 1;
        uint32_t occ_timer0 : 1;
        uint32_t external_trap : 1;
        uint32_t check_stop_ppc405 : 1;
        uint32_t gpe1_error : 1;
        uint32_t gpe0_error : 1;
        uint32_t pba_error : 1;
        uint32_t spare : 1;
        uint32_t trace_trigger : 1;
        uint32_t debugger : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oisr1_t;



typedef union ocb_oisr1_clr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t debugger : 1;
        uint32_t trace_trigger : 1;
        uint32_t spare : 1;
        uint32_t pba_error : 1;
        uint32_t gpe0_error : 1;
        uint32_t gpe1_error : 1;
        uint32_t check_stop_ppc405 : 1;
        uint32_t external_trap : 1;
        uint32_t occ_timer0 : 1;
        uint32_t occ_timer1 : 1;
        uint32_t ipi0_hi_priority : 1;
        uint32_t ipi1_hi_priority : 1;
        uint32_t ipi4_hi_priority : 1;
        uint32_t i2cm_intr : 1;
        uint32_t spare_14 : 1;
        uint32_t dcm_intf_ongoing : 1;
        uint32_t pbax_occ_send_attn : 1;
        uint32_t pbax_occ_push0 : 1;
        uint32_t pbax_occ_push1 : 1;
        uint32_t pba_bcde_attn : 1;
        uint32_t pba_bcue_attn : 1;
        uint32_t occ_strm0_pull : 1;
        uint32_t occ_strm0_push : 1;
        uint32_t occ_strm1_pull : 1;
        uint32_t occ_strm1_push : 1;
        uint32_t occ_strm2_pull : 1;
        uint32_t occ_strm2_push : 1;
        uint32_t occ_strm3_pull : 1;
        uint32_t occ_strm3_push : 1;
        uint32_t ipi0_lo_priority : 1;
        uint32_t ipi1_lo_priority : 1;
        uint32_t ipi4_lo_priority : 1;
#else
        uint32_t ipi4_lo_priority : 1;
        uint32_t ipi1_lo_priority : 1;
        uint32_t ipi0_lo_priority : 1;
        uint32_t occ_strm3_push : 1;
        uint32_t occ_strm3_pull : 1;
        uint32_t occ_strm2_push : 1;
        uint32_t occ_strm2_pull : 1;
        uint32_t occ_strm1_push : 1;
        uint32_t occ_strm1_pull : 1;
        uint32_t occ_strm0_push : 1;
        uint32_t occ_strm0_pull : 1;
        uint32_t pba_bcue_attn : 1;
        uint32_t pba_bcde_attn : 1;
        uint32_t pbax_occ_push1 : 1;
        uint32_t pbax_occ_push0 : 1;
        uint32_t pbax_occ_send_attn : 1;
        uint32_t dcm_intf_ongoing : 1;
        uint32_t spare_14 : 1;
        uint32_t i2cm_intr : 1;
        uint32_t ipi4_hi_priority : 1;
        uint32_t ipi1_hi_priority : 1;
        uint32_t ipi0_hi_priority : 1;
        uint32_t occ_timer1 : 1;
        uint32_t occ_timer0 : 1;
        uint32_t external_trap : 1;
        uint32_t check_stop_ppc405 : 1;
        uint32_t gpe1_error : 1;
        uint32_t gpe0_error : 1;
        uint32_t pba_error : 1;
        uint32_t spare : 1;
        uint32_t trace_trigger : 1;
        uint32_t debugger : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oisr1_clr_t;



typedef union ocb_oisr1_or
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t debugger : 1;
        uint32_t trace_trigger : 1;
        uint32_t spare : 1;
        uint32_t pba_error : 1;
        uint32_t gpe0_error : 1;
        uint32_t gpe1_error : 1;
        uint32_t check_stop_ppc405 : 1;
        uint32_t external_trap : 1;
        uint32_t occ_timer0 : 1;
        uint32_t occ_timer1 : 1;
        uint32_t ipi0_hi_priority : 1;
        uint32_t ipi1_hi_priority : 1;
        uint32_t ipi4_hi_priority : 1;
        uint32_t i2cm_intr : 1;
        uint32_t spare_14 : 1;
        uint32_t dcm_intf_ongoing : 1;
        uint32_t pbax_occ_send_attn : 1;
        uint32_t pbax_occ_push0 : 1;
        uint32_t pbax_occ_push1 : 1;
        uint32_t pba_bcde_attn : 1;
        uint32_t pba_bcue_attn : 1;
        uint32_t occ_strm0_pull : 1;
        uint32_t occ_strm0_push : 1;
        uint32_t occ_strm1_pull : 1;
        uint32_t occ_strm1_push : 1;
        uint32_t occ_strm2_pull : 1;
        uint32_t occ_strm2_push : 1;
        uint32_t occ_strm3_pull : 1;
        uint32_t occ_strm3_push : 1;
        uint32_t ipi0_lo_priority : 1;
        uint32_t ipi1_lo_priority : 1;
        uint32_t ipi4_lo_priority : 1;
#else
        uint32_t ipi4_lo_priority : 1;
        uint32_t ipi1_lo_priority : 1;
        uint32_t ipi0_lo_priority : 1;
        uint32_t occ_strm3_push : 1;
        uint32_t occ_strm3_pull : 1;
        uint32_t occ_strm2_push : 1;
        uint32_t occ_strm2_pull : 1;
        uint32_t occ_strm1_push : 1;
        uint32_t occ_strm1_pull : 1;
        uint32_t occ_strm0_push : 1;
        uint32_t occ_strm0_pull : 1;
        uint32_t pba_bcue_attn : 1;
        uint32_t pba_bcde_attn : 1;
        uint32_t pbax_occ_push1 : 1;
        uint32_t pbax_occ_push0 : 1;
        uint32_t pbax_occ_send_attn : 1;
        uint32_t dcm_intf_ongoing : 1;
        uint32_t spare_14 : 1;
        uint32_t i2cm_intr : 1;
        uint32_t ipi4_hi_priority : 1;
        uint32_t ipi1_hi_priority : 1;
        uint32_t ipi0_hi_priority : 1;
        uint32_t occ_timer1 : 1;
        uint32_t occ_timer0 : 1;
        uint32_t external_trap : 1;
        uint32_t check_stop_ppc405 : 1;
        uint32_t gpe1_error : 1;
        uint32_t gpe0_error : 1;
        uint32_t pba_error : 1;
        uint32_t spare : 1;
        uint32_t trace_trigger : 1;
        uint32_t debugger : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oisr1_or_t;



typedef union ocb_oimr1
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_mask_n : 32;
#else
        uint32_t interrupt_mask_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oimr1_t;



typedef union ocb_oimr1_clr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_mask_n : 32;
#else
        uint32_t interrupt_mask_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oimr1_clr_t;



typedef union ocb_oimr1_or
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_mask_n : 32;
#else
        uint32_t interrupt_mask_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oimr1_or_t;



typedef union ocb_oitr1
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_type_n : 32;
#else
        uint32_t interrupt_type_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oitr1_t;



typedef union ocb_oitr1_clr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_type_n : 32;
#else
        uint32_t interrupt_type_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oitr1_clr_t;



typedef union ocb_oitr1_or
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_type_n : 32;
#else
        uint32_t interrupt_type_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oitr1_or_t;



typedef union ocb_oiepr1
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_edge_pol_n : 32;
#else
        uint32_t interrupt_edge_pol_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oiepr1_t;



typedef union ocb_oiepr1_clr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_edge_pol_n : 32;
#else
        uint32_t interrupt_edge_pol_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oiepr1_clr_t;



typedef union ocb_oiepr1_or
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_edge_pol_n : 32;
#else
        uint32_t interrupt_edge_pol_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oiepr1_or_t;



typedef union ocb_oinkr1
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_input_n : 32;
#else
        uint32_t interrupt_input_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oinkr1_t;



typedef union ocb_oirr0a
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_route_a_n : 32;
#else
        uint32_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr0a_t;



typedef union ocb_oirr0a_clr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_route_a_n : 32;
#else
        uint32_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr0a_clr_t;



typedef union ocb_oirr0a_or
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_route_a_n : 32;
#else
        uint32_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr0a_or_t;



typedef union ocb_oirr0b
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_route_a_n : 32;
#else
        uint32_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr0b_t;



typedef union ocb_oirr0b_clr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_route_a_n : 32;
#else
        uint32_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr0b_clr_t;



typedef union ocb_oirr0b_or
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_route_a_n : 32;
#else
        uint32_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr0b_or_t;



typedef union ocb_oirr0c
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_route_a_n : 32;
#else
        uint32_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr0c_t;



typedef union ocb_oirr0c_clr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_route_a_n : 32;
#else
        uint32_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr0c_clr_t;



typedef union ocb_oirr0c_or
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_route_a_n : 32;
#else
        uint32_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr0c_or_t;



typedef union ocb_oirr1a
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_route_a_n : 32;
#else
        uint32_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr1a_t;



typedef union ocb_oirr1a_clr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_route_a_n : 32;
#else
        uint32_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr1a_clr_t;



typedef union ocb_oirr1a_or
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_route_a_n : 32;
#else
        uint32_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr1a_or_t;



typedef union ocb_oirr1b
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_route_a_n : 32;
#else
        uint32_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr1b_t;



typedef union ocb_oirr1b_clr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_route_a_n : 32;
#else
        uint32_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr1b_clr_t;



typedef union ocb_oirr1b_or
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_route_a_n : 32;
#else
        uint32_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr1b_or_t;



typedef union ocb_oirr1c
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_route_a_n : 32;
#else
        uint32_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr1c_t;



typedef union ocb_oirr1c_clr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_route_a_n : 32;
#else
        uint32_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr1c_clr_t;



typedef union ocb_oirr1c_or
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_route_a_n : 32;
#else
        uint32_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr1c_or_t;



typedef union ocb_onisr0
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_noncrit_status_n : 32;
#else
        uint32_t interrupt_noncrit_status_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_onisr0_t;



typedef union ocb_ocisr0
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_crit_status_n : 32;
#else
        uint32_t interrupt_crit_status_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocisr0_t;



typedef union ocb_ouisr0
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_uncon_status_n : 32;
#else
        uint32_t interrupt_uncon_status_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ouisr0_t;



typedef union ocb_odisr0
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_debug_status_n : 32;
#else
        uint32_t interrupt_debug_status_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_odisr0_t;



typedef union ocb_g0isr0
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_gpe0_status_n : 32;
#else
        uint32_t interrupt_gpe0_status_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_g0isr0_t;



typedef union ocb_g1isr0
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_gpe1_status_n : 32;
#else
        uint32_t interrupt_gpe1_status_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_g1isr0_t;



typedef union ocb_g2isr0
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_gpe2_status_n : 32;
#else
        uint32_t interrupt_gpe2_status_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_g2isr0_t;



typedef union ocb_g3isr0
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_gpe3_status_n : 32;
#else
        uint32_t interrupt_gpe3_status_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_g3isr0_t;



typedef union ocb_onisr1
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_noncrit_status_n : 32;
#else
        uint32_t interrupt_noncrit_status_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_onisr1_t;



typedef union ocb_ocisr1
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_crit_status_n : 32;
#else
        uint32_t interrupt_crit_status_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocisr1_t;



typedef union ocb_ouisr1
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_uncon_status_n : 32;
#else
        uint32_t interrupt_uncon_status_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ouisr1_t;



typedef union ocb_odisr1
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_debug_status_n : 32;
#else
        uint32_t interrupt_debug_status_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_odisr1_t;



typedef union ocb_g0isr1
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_gpe0_status_n : 32;
#else
        uint32_t interrupt_gpe0_status_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_g0isr1_t;



typedef union ocb_g1isr1
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_gpe1_status_n : 32;
#else
        uint32_t interrupt_gpe1_status_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_g1isr1_t;



typedef union ocb_g2isr1
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_gpe2_status_n : 32;
#else
        uint32_t interrupt_gpe2_status_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_g2isr1_t;



typedef union ocb_g3isr1
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interrupt_gpe3_status_n : 32;
#else
        uint32_t interrupt_gpe3_status_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_g3isr1_t;



typedef union ocb_occmisc
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t core_ext_intr : 1;
        uint32_t ext_intr_reason : 3;
        uint32_t pvref_error_en : 2;
        uint32_t pvref_error_gross : 1;
        uint32_t pvref_error_fine : 1;
        uint32_t firmware_fault : 1;
        uint32_t firmware_notify : 1;
        uint32_t spare : 6;
        uint32_t i2cm_intr_status : 3;
        uint32_t reserved1 : 13;
#else
        uint32_t reserved1 : 13;
        uint32_t i2cm_intr_status : 3;
        uint32_t spare : 6;
        uint32_t firmware_notify : 1;
        uint32_t firmware_fault : 1;
        uint32_t pvref_error_fine : 1;
        uint32_t pvref_error_gross : 1;
        uint32_t pvref_error_en : 2;
        uint32_t ext_intr_reason : 3;
        uint32_t core_ext_intr : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_occmisc_t;



typedef union ocb_occmisc_clr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t core_ext_intr : 1;
        uint32_t ext_intr_reason : 3;
        uint32_t pvref_error_en : 2;
        uint32_t pvref_error_gross : 1;
        uint32_t pvref_error_fine : 1;
        uint32_t firmware_fault : 1;
        uint32_t firmware_notify : 1;
        uint32_t spare : 6;
        uint32_t i2cm_intr_status : 3;
        uint32_t reserved1 : 13;
#else
        uint32_t reserved1 : 13;
        uint32_t i2cm_intr_status : 3;
        uint32_t spare : 6;
        uint32_t firmware_notify : 1;
        uint32_t firmware_fault : 1;
        uint32_t pvref_error_fine : 1;
        uint32_t pvref_error_gross : 1;
        uint32_t pvref_error_en : 2;
        uint32_t ext_intr_reason : 3;
        uint32_t core_ext_intr : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_occmisc_clr_t;



typedef union ocb_occmisc_or
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t core_ext_intr : 1;
        uint32_t ext_intr_reason : 3;
        uint32_t pvref_error_en : 2;
        uint32_t pvref_error_gross : 1;
        uint32_t pvref_error_fine : 1;
        uint32_t firmware_fault : 1;
        uint32_t firmware_notify : 1;
        uint32_t spare : 6;
        uint32_t i2cm_intr_status : 3;
        uint32_t reserved1 : 13;
#else
        uint32_t reserved1 : 13;
        uint32_t i2cm_intr_status : 3;
        uint32_t spare : 6;
        uint32_t firmware_notify : 1;
        uint32_t firmware_fault : 1;
        uint32_t pvref_error_fine : 1;
        uint32_t pvref_error_gross : 1;
        uint32_t pvref_error_en : 2;
        uint32_t ext_intr_reason : 3;
        uint32_t core_ext_intr : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_occmisc_or_t;



typedef union ocb_ohtmcr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t htm_src_sel : 2;
        uint32_t htm_stop : 1;
        uint32_t htm_marker_slave_adrs : 3;
        uint32_t event2halt_mode : 2;
        uint32_t event2halt_en : 11;
        uint32_t reserved1 : 1;
        uint32_t htm_gpe_src_sel : 2;
        uint32_t reserved2 : 1;
        uint32_t event2halt_occ : 1;
        uint32_t event2halt_gpe0 : 1;
        uint32_t event2halt_gpe1 : 1;
        uint32_t event2halt_gpe2 : 1;
        uint32_t event2halt_gpe3 : 1;
        uint32_t reserved3 : 3;
        uint32_t event2halt_halt_state : 1;
#else
        uint32_t event2halt_halt_state : 1;
        uint32_t reserved3 : 3;
        uint32_t event2halt_gpe3 : 1;
        uint32_t event2halt_gpe2 : 1;
        uint32_t event2halt_gpe1 : 1;
        uint32_t event2halt_gpe0 : 1;
        uint32_t event2halt_occ : 1;
        uint32_t reserved2 : 1;
        uint32_t htm_gpe_src_sel : 2;
        uint32_t reserved1 : 1;
        uint32_t event2halt_en : 11;
        uint32_t event2halt_mode : 2;
        uint32_t htm_marker_slave_adrs : 3;
        uint32_t htm_stop : 1;
        uint32_t htm_src_sel : 2;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ohtmcr_t;



typedef union ocb_oehdr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t event2halt_delay : 20;
        uint32_t reserved1 : 12;
#else
        uint32_t reserved1 : 12;
        uint32_t event2halt_delay : 20;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oehdr_t;



typedef union ocb_ocicfg
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t m0_priority : 2;
        uint32_t m1_priority : 2;
        uint32_t m2_priority : 2;
        uint32_t m3_priority : 2;
        uint32_t m4_priority : 2;
        uint32_t m5_priority : 2;
        uint32_t m6_priority : 2;
        uint32_t m7_priority : 2;
        uint32_t m0_priority_sel : 1;
        uint32_t m1_priority_sel : 1;
        uint32_t m2_priority_sel : 1;
        uint32_t m3_priority_sel : 1;
        uint32_t ocicfg_reserved_20 : 1;
        uint32_t m5_priority_sel : 1;
        uint32_t ocicfg_reserved_23 : 1;
        uint32_t m7_priority_sel : 1;
        uint32_t plbarb_lockerr : 1;
        uint32_t spare_24_31 : 7;
#else
        uint32_t spare_24_31 : 7;
        uint32_t plbarb_lockerr : 1;
        uint32_t m7_priority_sel : 1;
        uint32_t ocicfg_reserved_23 : 1;
        uint32_t m5_priority_sel : 1;
        uint32_t ocicfg_reserved_20 : 1;
        uint32_t m3_priority_sel : 1;
        uint32_t m2_priority_sel : 1;
        uint32_t m1_priority_sel : 1;
        uint32_t m0_priority_sel : 1;
        uint32_t m7_priority : 2;
        uint32_t m6_priority : 2;
        uint32_t m5_priority : 2;
        uint32_t m4_priority : 2;
        uint32_t m3_priority : 2;
        uint32_t m2_priority : 2;
        uint32_t m1_priority : 2;
        uint32_t m0_priority : 2;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocicfg_t;



typedef union ocb_ocbstat
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t adcfsm_ongoing : 1;
        uint32_t spare_1 : 1;
        uint32_t pmc_o2s_0a_ongoing : 1;
        uint32_t pmc_o2s_0b_ongoing : 1;
        uint32_t pmc_o2s_1a_ongoing : 1;
        uint32_t pmc_o2s_1b_ongoing : 1;
        uint32_t pmc_o2s_2a_ongoing : 1;
        uint32_t pmc_o2s_2b_ongoing : 1;
        uint32_t avs_slave0 : 1;
        uint32_t avs_slave1 : 1;
        uint32_t avs_slave2 : 1;
        uint32_t spare_11 : 1;
        uint32_t derp0_ongoing : 1;
        uint32_t derp1_ongoing : 1;
        uint32_t derp2_ongoing : 1;
        uint32_t derp3_ongoing : 1;
        uint32_t reserved1 : 16;
#else
        uint32_t reserved1 : 16;
        uint32_t derp3_ongoing : 1;
        uint32_t derp2_ongoing : 1;
        uint32_t derp1_ongoing : 1;
        uint32_t derp0_ongoing : 1;
        uint32_t spare_11 : 1;
        uint32_t avs_slave2 : 1;
        uint32_t avs_slave1 : 1;
        uint32_t avs_slave0 : 1;
        uint32_t pmc_o2s_2b_ongoing : 1;
        uint32_t pmc_o2s_2a_ongoing : 1;
        uint32_t pmc_o2s_1b_ongoing : 1;
        uint32_t pmc_o2s_1a_ongoing : 1;
        uint32_t pmc_o2s_0b_ongoing : 1;
        uint32_t pmc_o2s_0a_ongoing : 1;
        uint32_t spare_1 : 1;
        uint32_t adcfsm_ongoing : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocbstat_t;



typedef union ocb_occhbr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t occ_heartbeat_count : 16;
        uint32_t occ_heartbeat_en : 1;
        uint32_t reserved1 : 15;
#else
        uint32_t reserved1 : 15;
        uint32_t occ_heartbeat_en : 1;
        uint32_t occ_heartbeat_count : 16;
#endif // _BIG_ENDIAN
    } fields;
} ocb_occhbr_t;



typedef union ocb_ccsr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t core_config : 32;
#else
        uint32_t core_config : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ccsr_t;



typedef union ocb_ccsr_clr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t core_config : 32;
#else
        uint32_t core_config : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ccsr_clr_t;



typedef union ocb_ccsr_or
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t core_config : 32;
#else
        uint32_t core_config : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ccsr_or_t;



typedef union ocb_qssr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t l2_stopped : 12;
        uint32_t reserved1 : 2;
        uint32_t quad_stopped : 6;
        uint32_t stop_entry_ongoing : 6;
        uint32_t stop_exit_ongoing : 6;
#else
        uint32_t stop_exit_ongoing : 6;
        uint32_t stop_entry_ongoing : 6;
        uint32_t quad_stopped : 6;
        uint32_t reserved1 : 2;
        uint32_t l2_stopped : 12;
#endif // _BIG_ENDIAN
    } fields;
} ocb_qssr_t;



typedef union ocb_qssr_clr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t l2_stopped : 12;
        uint32_t reserved1 : 2;
        uint32_t quad_stopped : 6;
        uint32_t stop_entry_ongoing : 6;
        uint32_t stop_exit_ongoing : 6;
#else
        uint32_t stop_exit_ongoing : 6;
        uint32_t stop_entry_ongoing : 6;
        uint32_t quad_stopped : 6;
        uint32_t reserved1 : 2;
        uint32_t l2_stopped : 12;
#endif // _BIG_ENDIAN
    } fields;
} ocb_qssr_clr_t;



typedef union ocb_qssr_or
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t l2_stopped : 12;
        uint32_t reserved1 : 2;
        uint32_t quad_stopped : 6;
        uint32_t stop_entry_ongoing : 6;
        uint32_t stop_exit_ongoing : 6;
#else
        uint32_t stop_exit_ongoing : 6;
        uint32_t stop_entry_ongoing : 6;
        uint32_t quad_stopped : 6;
        uint32_t reserved1 : 2;
        uint32_t l2_stopped : 12;
#endif // _BIG_ENDIAN
    } fields;
} ocb_qssr_or_t;



typedef union ocb_otbr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t ocb_timebase : 32;
#else
        uint32_t ocb_timebase : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_otbr_t;



typedef union ocb_occsn
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t occ_scratch_n : 32;
#else
        uint32_t occ_scratch_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_occsn_t;



typedef union ocb_occsn_clr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t occ_scratch_n : 32;
#else
        uint32_t occ_scratch_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_occsn_clr_t;



typedef union ocb_occsn_or
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t occ_scratch_n : 32;
#else
        uint32_t occ_scratch_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_occsn_or_t;



typedef union ocb_occflgn
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t occ_flags : 32;
#else
        uint32_t occ_flags : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_occflgn_t;



typedef union ocb_occflgn_clr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t occ_flags : 32;
#else
        uint32_t occ_flags : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_occflgn_clr_t;



typedef union ocb_occflgn_or
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t occ_flags : 32;
#else
        uint32_t occ_flags : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_occflgn_or_t;



typedef union ocb_opm
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t reserved1 : 1;
        uint32_t master_match_value : 3;
        uint32_t reserved2 : 1;
        uint32_t master_mask_value : 3;
        uint32_t read_count_enable : 1;
        uint32_t write_count_enable : 1;
        uint32_t command_count : 22;
#else
        uint32_t command_count : 22;
        uint32_t write_count_enable : 1;
        uint32_t read_count_enable : 1;
        uint32_t master_mask_value : 3;
        uint32_t reserved2 : 1;
        uint32_t master_match_value : 3;
        uint32_t reserved1 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opm_t;



typedef union ocb_otrn
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t timeout_n : 1;
        uint32_t control_n : 1;
        uint32_t auto_reload_n : 1;
        uint32_t spare_n : 13;
        uint32_t timer_n : 16;
#else
        uint32_t timer_n : 16;
        uint32_t spare_n : 13;
        uint32_t auto_reload_n : 1;
        uint32_t control_n : 1;
        uint32_t timeout_n : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_otrn_t;



typedef union ocb_derpn
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t dividend : 32;
#else
        uint32_t dividend : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_derpn_t;



typedef union ocb_dorpn
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t quotient : 32;
#else
        uint32_t quotient : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_dorpn_t;



typedef union ocb_ocbslbrn
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t pull_oci_region : 3;
        uint32_t pull_start : 26;
        uint32_t reserved1 : 3;
#else
        uint32_t reserved1 : 3;
        uint32_t pull_start : 26;
        uint32_t pull_oci_region : 3;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocbslbrn_t;



typedef union ocb_ocbslcsn
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t pull_full : 1;
        uint32_t pull_empty : 1;
        uint32_t spare : 2;
        uint32_t pull_intr_action01 : 2;
        uint32_t pull_length : 5;
        uint32_t reserved1 : 2;
        uint32_t pull_write_ptr : 5;
        uint32_t reserved2 : 3;
        uint32_t pull_read_ptr : 5;
        uint32_t reserved3 : 5;
        uint32_t pull_enable : 1;
#else
        uint32_t pull_enable : 1;
        uint32_t reserved3 : 5;
        uint32_t pull_read_ptr : 5;
        uint32_t reserved2 : 3;
        uint32_t pull_write_ptr : 5;
        uint32_t reserved1 : 2;
        uint32_t pull_length : 5;
        uint32_t pull_intr_action01 : 2;
        uint32_t spare : 2;
        uint32_t pull_empty : 1;
        uint32_t pull_full : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocbslcsn_t;



typedef union ocb_ocbslin
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t reserved1 : 32;
#else
        uint32_t reserved1 : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocbslin_t;



typedef union ocb_ocbshbrn
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t push_oci_region : 3;
        uint32_t push_start : 26;
        uint32_t reserved1 : 3;
#else
        uint32_t reserved1 : 3;
        uint32_t push_start : 26;
        uint32_t push_oci_region : 3;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocbshbrn_t;



typedef union ocb_ocbshcsn
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t push_full : 1;
        uint32_t push_empty : 1;
        uint32_t spare : 2;
        uint32_t push_intr_action01 : 2;
        uint32_t push_length : 5;
        uint32_t reserved1 : 2;
        uint32_t push_write_ptr : 5;
        uint32_t reserved2 : 3;
        uint32_t push_read_ptr : 5;
        uint32_t reserved3 : 5;
        uint32_t push_enable : 1;
#else
        uint32_t push_enable : 1;
        uint32_t reserved3 : 5;
        uint32_t push_read_ptr : 5;
        uint32_t reserved2 : 3;
        uint32_t push_write_ptr : 5;
        uint32_t reserved1 : 2;
        uint32_t push_length : 5;
        uint32_t push_intr_action01 : 2;
        uint32_t spare : 2;
        uint32_t push_empty : 1;
        uint32_t push_full : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocbshcsn_t;



typedef union ocb_ocbshin
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t reserved1 : 32;
#else
        uint32_t reserved1 : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocbshin_t;



typedef union ocb_ocbsesn
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t push_read_underflow : 1;
        uint32_t pull_write_overflow : 1;
        uint32_t reserved1 : 30;
#else
        uint32_t reserved1 : 30;
        uint32_t pull_write_overflow : 1;
        uint32_t push_read_underflow : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocbsesn_t;



typedef union ocb_ocblwcrn
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t linear_window_enable : 1;
        uint32_t spare_0 : 2;
        uint32_t linear_window_bar : 17;
        uint32_t linear_window_mask : 12;
#else
        uint32_t linear_window_mask : 12;
        uint32_t linear_window_bar : 17;
        uint32_t spare_0 : 2;
        uint32_t linear_window_enable : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocblwcrn_t;



typedef union ocb_ocblwsrn
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t linear_window_scresp : 3;
        uint32_t spare0 : 5;
        uint32_t reserved1 : 24;
#else
        uint32_t reserved1 : 24;
        uint32_t spare0 : 5;
        uint32_t linear_window_scresp : 3;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocblwsrn_t;



typedef union ocb_ocblwsbrn
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t linear_window_region : 3;
        uint32_t linear_window_base : 7;
        uint32_t reserved1 : 22;
#else
        uint32_t reserved1 : 22;
        uint32_t linear_window_base : 7;
        uint32_t linear_window_region : 3;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocblwsbrn_t;



typedef union ocb_opit0qn
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t reserved1 : 13;
        uint32_t pcb_intr_payload : 19;
#else
        uint32_t pcb_intr_payload : 19;
        uint32_t reserved1 : 13;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit0qn_t;



typedef union ocb_opit1qn
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t reserved1 : 13;
        uint32_t pcb_intr_payload : 19;
#else
        uint32_t pcb_intr_payload : 19;
        uint32_t reserved1 : 13;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit1qn_t;



typedef union ocb_opit2qn
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t reserved1 : 13;
        uint32_t pcb_intr_payload : 19;
#else
        uint32_t pcb_intr_payload : 19;
        uint32_t reserved1 : 13;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit2qn_t;



typedef union ocb_opit3qn
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t reserved1 : 13;
        uint32_t pcb_intr_payload : 19;
#else
        uint32_t pcb_intr_payload : 19;
        uint32_t reserved1 : 13;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit3qn_t;



typedef union ocb_opit4qn
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t reserved1 : 13;
        uint32_t pcb_intr_payload : 19;
#else
        uint32_t pcb_intr_payload : 19;
        uint32_t reserved1 : 13;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit4qn_t;



typedef union ocb_opit5qn
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t reserved1 : 13;
        uint32_t pcb_intr_payload : 19;
#else
        uint32_t pcb_intr_payload : 19;
        uint32_t reserved1 : 13;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit5qn_t;



typedef union ocb_opit6qn
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t reserved1 : 13;
        uint32_t pcb_intr_payload : 19;
#else
        uint32_t pcb_intr_payload : 19;
        uint32_t reserved1 : 13;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit6qn_t;



typedef union ocb_opit7qn
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t reserved1 : 13;
        uint32_t pcb_intr_payload : 19;
#else
        uint32_t pcb_intr_payload : 19;
        uint32_t reserved1 : 13;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit7qn_t;



typedef union ocb_opit8cn
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t reserved1 : 13;
        uint32_t pcb_intr_source_core : 2;
        uint32_t pcb_intr_payload : 17;
#else
        uint32_t pcb_intr_payload : 17;
        uint32_t pcb_intr_source_core : 2;
        uint32_t reserved1 : 13;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit8cn_t;



typedef union ocb_opit9cn
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t reserved1 : 13;
        uint32_t pcb_intr_source_core : 2;
        uint32_t pcb_intr_payload : 17;
#else
        uint32_t pcb_intr_payload : 17;
        uint32_t pcb_intr_source_core : 2;
        uint32_t reserved1 : 13;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit9cn_t;



typedef union ocb_opitasvn
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t pcb_intr_payload_quad_0 : 4;
        uint32_t pcb_intr_payload_quad_1 : 4;
        uint32_t pcb_intr_payload_quad_2 : 4;
        uint32_t pcb_intr_payload_quad_3 : 4;
        uint32_t pcb_intr_payload_quad_4 : 4;
        uint32_t pcb_intr_payload_quad_5 : 4;
        uint32_t pcb_intr_payload_quad_6 : 4;
        uint32_t pcb_intr_payload_quad_7 : 4;
#else
        uint32_t pcb_intr_payload_quad_7 : 4;
        uint32_t pcb_intr_payload_quad_6 : 4;
        uint32_t pcb_intr_payload_quad_5 : 4;
        uint32_t pcb_intr_payload_quad_4 : 4;
        uint32_t pcb_intr_payload_quad_3 : 4;
        uint32_t pcb_intr_payload_quad_2 : 4;
        uint32_t pcb_intr_payload_quad_1 : 4;
        uint32_t pcb_intr_payload_quad_0 : 4;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opitasvn_t;



typedef union ocb_opitbsvn
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t pcb_intr_payload_quad_0 : 4;
        uint32_t pcb_intr_payload_quad_1 : 4;
        uint32_t pcb_intr_payload_quad_2 : 4;
        uint32_t pcb_intr_payload_quad_3 : 4;
        uint32_t pcb_intr_payload_quad_4 : 4;
        uint32_t pcb_intr_payload_quad_5 : 4;
        uint32_t pcb_intr_payload_quad_6 : 4;
        uint32_t pcb_intr_payload_quad_7 : 4;
#else
        uint32_t pcb_intr_payload_quad_7 : 4;
        uint32_t pcb_intr_payload_quad_6 : 4;
        uint32_t pcb_intr_payload_quad_5 : 4;
        uint32_t pcb_intr_payload_quad_4 : 4;
        uint32_t pcb_intr_payload_quad_3 : 4;
        uint32_t pcb_intr_payload_quad_2 : 4;
        uint32_t pcb_intr_payload_quad_1 : 4;
        uint32_t pcb_intr_payload_quad_0 : 4;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opitbsvn_t;



typedef union ocb_opitcsv
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t pcb_intr_payload_quad_0 : 4;
        uint32_t pcb_intr_payload_quad_1 : 4;
        uint32_t pcb_intr_payload_quad_2 : 4;
        uint32_t pcb_intr_payload_quad_3 : 4;
        uint32_t pcb_intr_payload_quad_4 : 4;
        uint32_t pcb_intr_payload_quad_5 : 4;
        uint32_t pcb_intr_payload_quad_6 : 4;
        uint32_t pcb_intr_payload_quad_7 : 4;
#else
        uint32_t pcb_intr_payload_quad_7 : 4;
        uint32_t pcb_intr_payload_quad_6 : 4;
        uint32_t pcb_intr_payload_quad_5 : 4;
        uint32_t pcb_intr_payload_quad_4 : 4;
        uint32_t pcb_intr_payload_quad_3 : 4;
        uint32_t pcb_intr_payload_quad_2 : 4;
        uint32_t pcb_intr_payload_quad_1 : 4;
        uint32_t pcb_intr_payload_quad_0 : 4;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opitcsv_t;



typedef union ocb_opitdsv
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t pcb_intr_payload_quad_0 : 4;
        uint32_t pcb_intr_payload_quad_1 : 4;
        uint32_t pcb_intr_payload_quad_2 : 4;
        uint32_t pcb_intr_payload_quad_3 : 4;
        uint32_t pcb_intr_payload_quad_4 : 4;
        uint32_t pcb_intr_payload_quad_5 : 4;
        uint32_t pcb_intr_payload_quad_6 : 4;
        uint32_t pcb_intr_payload_quad_7 : 4;
#else
        uint32_t pcb_intr_payload_quad_7 : 4;
        uint32_t pcb_intr_payload_quad_6 : 4;
        uint32_t pcb_intr_payload_quad_5 : 4;
        uint32_t pcb_intr_payload_quad_4 : 4;
        uint32_t pcb_intr_payload_quad_3 : 4;
        uint32_t pcb_intr_payload_quad_2 : 4;
        uint32_t pcb_intr_payload_quad_1 : 4;
        uint32_t pcb_intr_payload_quad_0 : 4;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opitdsv_t;



typedef union ocb_opitesv
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t pcb_intr_payload_quad_0 : 4;
        uint32_t pcb_intr_payload_quad_1 : 4;
        uint32_t pcb_intr_payload_quad_2 : 4;
        uint32_t pcb_intr_payload_quad_3 : 4;
        uint32_t pcb_intr_payload_quad_4 : 4;
        uint32_t pcb_intr_payload_quad_5 : 4;
        uint32_t pcb_intr_payload_quad_6 : 4;
        uint32_t pcb_intr_payload_quad_7 : 4;
#else
        uint32_t pcb_intr_payload_quad_7 : 4;
        uint32_t pcb_intr_payload_quad_6 : 4;
        uint32_t pcb_intr_payload_quad_5 : 4;
        uint32_t pcb_intr_payload_quad_4 : 4;
        uint32_t pcb_intr_payload_quad_3 : 4;
        uint32_t pcb_intr_payload_quad_2 : 4;
        uint32_t pcb_intr_payload_quad_1 : 4;
        uint32_t pcb_intr_payload_quad_0 : 4;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opitesv_t;



typedef union ocb_opitfsv
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t pcb_intr_payload_quad_0 : 4;
        uint32_t pcb_intr_payload_quad_1 : 4;
        uint32_t pcb_intr_payload_quad_2 : 4;
        uint32_t pcb_intr_payload_quad_3 : 4;
        uint32_t pcb_intr_payload_quad_4 : 4;
        uint32_t pcb_intr_payload_quad_5 : 4;
        uint32_t pcb_intr_payload_quad_6 : 4;
        uint32_t pcb_intr_payload_quad_7 : 4;
#else
        uint32_t pcb_intr_payload_quad_7 : 4;
        uint32_t pcb_intr_payload_quad_6 : 4;
        uint32_t pcb_intr_payload_quad_5 : 4;
        uint32_t pcb_intr_payload_quad_4 : 4;
        uint32_t pcb_intr_payload_quad_3 : 4;
        uint32_t pcb_intr_payload_quad_2 : 4;
        uint32_t pcb_intr_payload_quad_1 : 4;
        uint32_t pcb_intr_payload_quad_0 : 4;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opitfsv_t;



typedef union ocb_opit0qnrr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t reserved1 : 13;
        uint32_t pcb_intr_payload : 19;
#else
        uint32_t pcb_intr_payload : 19;
        uint32_t reserved1 : 13;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit0qnrr_t;



typedef union ocb_opit1qnrr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t reserved1 : 13;
        uint32_t pcb_intr_payload : 19;
#else
        uint32_t pcb_intr_payload : 19;
        uint32_t reserved1 : 13;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit1qnrr_t;



typedef union ocb_opit2qnrr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t reserved1 : 13;
        uint32_t pcb_intr_payload : 19;
#else
        uint32_t pcb_intr_payload : 19;
        uint32_t reserved1 : 13;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit2qnrr_t;



typedef union ocb_opit3qnrr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t reserved1 : 13;
        uint32_t pcb_intr_payload : 19;
#else
        uint32_t pcb_intr_payload : 19;
        uint32_t reserved1 : 13;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit3qnrr_t;



typedef union ocb_opit4qnrr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t reserved1 : 13;
        uint32_t pcb_intr_payload : 19;
#else
        uint32_t pcb_intr_payload : 19;
        uint32_t reserved1 : 13;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit4qnrr_t;



typedef union ocb_opit5qnrr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t reserved1 : 13;
        uint32_t pcb_intr_payload : 19;
#else
        uint32_t pcb_intr_payload : 19;
        uint32_t reserved1 : 13;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit5qnrr_t;



typedef union ocb_opit6qnrr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t reserved1 : 13;
        uint32_t pcb_intr_payload : 19;
#else
        uint32_t pcb_intr_payload : 19;
        uint32_t reserved1 : 13;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit6qnrr_t;



typedef union ocb_opit7qnrr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t reserved1 : 13;
        uint32_t pcb_intr_payload : 19;
#else
        uint32_t pcb_intr_payload : 19;
        uint32_t reserved1 : 13;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit7qnrr_t;



typedef union ocb_opit8cnrr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t reserved1 : 13;
        uint32_t pcb_intr_source_core : 2;
        uint32_t pcb_intr_payload : 17;
#else
        uint32_t pcb_intr_payload : 17;
        uint32_t pcb_intr_source_core : 2;
        uint32_t reserved1 : 13;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit8cnrr_t;



typedef union ocb_opit9cnrr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t reserved1 : 13;
        uint32_t pcb_intr_source_core : 2;
        uint32_t pcb_intr_payload : 17;
#else
        uint32_t pcb_intr_payload : 17;
        uint32_t pcb_intr_source_core : 2;
        uint32_t reserved1 : 13;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit9cnrr_t;



typedef union ocb_opitasvnrr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t pcb_intr_payload_quad_0 : 4;
        uint32_t pcb_intr_payload_quad_1 : 4;
        uint32_t pcb_intr_payload_quad_2 : 4;
        uint32_t pcb_intr_payload_quad_3 : 4;
        uint32_t pcb_intr_payload_quad_4 : 4;
        uint32_t pcb_intr_payload_quad_5 : 4;
        uint32_t pcb_intr_payload_quad_6 : 4;
        uint32_t pcb_intr_payload_quad_7 : 4;
#else
        uint32_t pcb_intr_payload_quad_7 : 4;
        uint32_t pcb_intr_payload_quad_6 : 4;
        uint32_t pcb_intr_payload_quad_5 : 4;
        uint32_t pcb_intr_payload_quad_4 : 4;
        uint32_t pcb_intr_payload_quad_3 : 4;
        uint32_t pcb_intr_payload_quad_2 : 4;
        uint32_t pcb_intr_payload_quad_1 : 4;
        uint32_t pcb_intr_payload_quad_0 : 4;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opitasvnrr_t;



typedef union ocb_opitbsvnrr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t pcb_intr_payload_quad_0 : 4;
        uint32_t pcb_intr_payload_quad_1 : 4;
        uint32_t pcb_intr_payload_quad_2 : 4;
        uint32_t pcb_intr_payload_quad_3 : 4;
        uint32_t pcb_intr_payload_quad_4 : 4;
        uint32_t pcb_intr_payload_quad_5 : 4;
        uint32_t pcb_intr_payload_quad_6 : 4;
        uint32_t pcb_intr_payload_quad_7 : 4;
#else
        uint32_t pcb_intr_payload_quad_7 : 4;
        uint32_t pcb_intr_payload_quad_6 : 4;
        uint32_t pcb_intr_payload_quad_5 : 4;
        uint32_t pcb_intr_payload_quad_4 : 4;
        uint32_t pcb_intr_payload_quad_3 : 4;
        uint32_t pcb_intr_payload_quad_2 : 4;
        uint32_t pcb_intr_payload_quad_1 : 4;
        uint32_t pcb_intr_payload_quad_0 : 4;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opitbsvnrr_t;



typedef union ocb_opitcsvrr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t pcb_intr_payload_quad_0 : 4;
        uint32_t pcb_intr_payload_quad_1 : 4;
        uint32_t pcb_intr_payload_quad_2 : 4;
        uint32_t pcb_intr_payload_quad_3 : 4;
        uint32_t pcb_intr_payload_quad_4 : 4;
        uint32_t pcb_intr_payload_quad_5 : 4;
        uint32_t pcb_intr_payload_quad_6 : 4;
        uint32_t pcb_intr_payload_quad_7 : 4;
#else
        uint32_t pcb_intr_payload_quad_7 : 4;
        uint32_t pcb_intr_payload_quad_6 : 4;
        uint32_t pcb_intr_payload_quad_5 : 4;
        uint32_t pcb_intr_payload_quad_4 : 4;
        uint32_t pcb_intr_payload_quad_3 : 4;
        uint32_t pcb_intr_payload_quad_2 : 4;
        uint32_t pcb_intr_payload_quad_1 : 4;
        uint32_t pcb_intr_payload_quad_0 : 4;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opitcsvrr_t;



typedef union ocb_opitdsvrr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t pcb_intr_payload_quad_0 : 4;
        uint32_t pcb_intr_payload_quad_1 : 4;
        uint32_t pcb_intr_payload_quad_2 : 4;
        uint32_t pcb_intr_payload_quad_3 : 4;
        uint32_t pcb_intr_payload_quad_4 : 4;
        uint32_t pcb_intr_payload_quad_5 : 4;
        uint32_t pcb_intr_payload_quad_6 : 4;
        uint32_t pcb_intr_payload_quad_7 : 4;
#else
        uint32_t pcb_intr_payload_quad_7 : 4;
        uint32_t pcb_intr_payload_quad_6 : 4;
        uint32_t pcb_intr_payload_quad_5 : 4;
        uint32_t pcb_intr_payload_quad_4 : 4;
        uint32_t pcb_intr_payload_quad_3 : 4;
        uint32_t pcb_intr_payload_quad_2 : 4;
        uint32_t pcb_intr_payload_quad_1 : 4;
        uint32_t pcb_intr_payload_quad_0 : 4;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opitdsvrr_t;



typedef union ocb_opitesvrr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t pcb_intr_payload_quad_0 : 4;
        uint32_t pcb_intr_payload_quad_1 : 4;
        uint32_t pcb_intr_payload_quad_2 : 4;
        uint32_t pcb_intr_payload_quad_3 : 4;
        uint32_t pcb_intr_payload_quad_4 : 4;
        uint32_t pcb_intr_payload_quad_5 : 4;
        uint32_t pcb_intr_payload_quad_6 : 4;
        uint32_t pcb_intr_payload_quad_7 : 4;
#else
        uint32_t pcb_intr_payload_quad_7 : 4;
        uint32_t pcb_intr_payload_quad_6 : 4;
        uint32_t pcb_intr_payload_quad_5 : 4;
        uint32_t pcb_intr_payload_quad_4 : 4;
        uint32_t pcb_intr_payload_quad_3 : 4;
        uint32_t pcb_intr_payload_quad_2 : 4;
        uint32_t pcb_intr_payload_quad_1 : 4;
        uint32_t pcb_intr_payload_quad_0 : 4;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opitesvrr_t;



typedef union ocb_opitfsvrr
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t pcb_intr_payload_quad_0 : 4;
        uint32_t pcb_intr_payload_quad_1 : 4;
        uint32_t pcb_intr_payload_quad_2 : 4;
        uint32_t pcb_intr_payload_quad_3 : 4;
        uint32_t pcb_intr_payload_quad_4 : 4;
        uint32_t pcb_intr_payload_quad_5 : 4;
        uint32_t pcb_intr_payload_quad_6 : 4;
        uint32_t pcb_intr_payload_quad_7 : 4;
#else
        uint32_t pcb_intr_payload_quad_7 : 4;
        uint32_t pcb_intr_payload_quad_6 : 4;
        uint32_t pcb_intr_payload_quad_5 : 4;
        uint32_t pcb_intr_payload_quad_4 : 4;
        uint32_t pcb_intr_payload_quad_3 : 4;
        uint32_t pcb_intr_payload_quad_2 : 4;
        uint32_t pcb_intr_payload_quad_1 : 4;
        uint32_t pcb_intr_payload_quad_0 : 4;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opitfsvrr_t;



typedef union ocb_opitir
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t reserved1 : 5;
        uint32_t pcb_intr_chiplet_id : 3;
        uint32_t reserved2 : 1;
        uint32_t pcb_intr_payload : 23;
#else
        uint32_t pcb_intr_payload : 23;
        uint32_t reserved2 : 1;
        uint32_t pcb_intr_chiplet_id : 3;
        uint32_t reserved1 : 5;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opitir_t;



typedef union ocb_opit0pra
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t pcb_intr_type_n_pending_0 : 1;
        uint32_t pcb_intr_type_n_pending_1 : 1;
        uint32_t pcb_intr_type_n_pending_2 : 1;
        uint32_t pcb_intr_type_n_pending_3 : 1;
        uint32_t pcb_intr_type_n_pending_4 : 1;
        uint32_t pcb_intr_type_n_pending_5 : 1;
        uint32_t pcb_intr_type_n_pending_6 : 1;
        uint32_t pcb_intr_type_n_pending_7 : 1;
        uint32_t reserved1 : 24;
#else
        uint32_t reserved1 : 24;
        uint32_t pcb_intr_type_n_pending_7 : 1;
        uint32_t pcb_intr_type_n_pending_6 : 1;
        uint32_t pcb_intr_type_n_pending_5 : 1;
        uint32_t pcb_intr_type_n_pending_4 : 1;
        uint32_t pcb_intr_type_n_pending_3 : 1;
        uint32_t pcb_intr_type_n_pending_2 : 1;
        uint32_t pcb_intr_type_n_pending_1 : 1;
        uint32_t pcb_intr_type_n_pending_0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit0pra_t;



typedef union ocb_opit1pra
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t pcb_intr_type_n_pending_0 : 1;
        uint32_t pcb_intr_type_n_pending_1 : 1;
        uint32_t pcb_intr_type_n_pending_2 : 1;
        uint32_t pcb_intr_type_n_pending_3 : 1;
        uint32_t pcb_intr_type_n_pending_4 : 1;
        uint32_t pcb_intr_type_n_pending_5 : 1;
        uint32_t pcb_intr_type_n_pending_6 : 1;
        uint32_t pcb_intr_type_n_pending_7 : 1;
        uint32_t reserved1 : 24;
#else
        uint32_t reserved1 : 24;
        uint32_t pcb_intr_type_n_pending_7 : 1;
        uint32_t pcb_intr_type_n_pending_6 : 1;
        uint32_t pcb_intr_type_n_pending_5 : 1;
        uint32_t pcb_intr_type_n_pending_4 : 1;
        uint32_t pcb_intr_type_n_pending_3 : 1;
        uint32_t pcb_intr_type_n_pending_2 : 1;
        uint32_t pcb_intr_type_n_pending_1 : 1;
        uint32_t pcb_intr_type_n_pending_0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit1pra_t;



typedef union ocb_opit2pra
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t pcb_intr_type_n_pending_0 : 1;
        uint32_t pcb_intr_type_n_pending_1 : 1;
        uint32_t pcb_intr_type_n_pending_2 : 1;
        uint32_t pcb_intr_type_n_pending_3 : 1;
        uint32_t pcb_intr_type_n_pending_4 : 1;
        uint32_t pcb_intr_type_n_pending_5 : 1;
        uint32_t pcb_intr_type_n_pending_6 : 1;
        uint32_t pcb_intr_type_n_pending_7 : 1;
        uint32_t reserved1 : 24;
#else
        uint32_t reserved1 : 24;
        uint32_t pcb_intr_type_n_pending_7 : 1;
        uint32_t pcb_intr_type_n_pending_6 : 1;
        uint32_t pcb_intr_type_n_pending_5 : 1;
        uint32_t pcb_intr_type_n_pending_4 : 1;
        uint32_t pcb_intr_type_n_pending_3 : 1;
        uint32_t pcb_intr_type_n_pending_2 : 1;
        uint32_t pcb_intr_type_n_pending_1 : 1;
        uint32_t pcb_intr_type_n_pending_0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit2pra_t;



typedef union ocb_opit3pra
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t pcb_intr_type_n_pending_0 : 1;
        uint32_t pcb_intr_type_n_pending_1 : 1;
        uint32_t pcb_intr_type_n_pending_2 : 1;
        uint32_t pcb_intr_type_n_pending_3 : 1;
        uint32_t pcb_intr_type_n_pending_4 : 1;
        uint32_t pcb_intr_type_n_pending_5 : 1;
        uint32_t pcb_intr_type_n_pending_6 : 1;
        uint32_t pcb_intr_type_n_pending_7 : 1;
        uint32_t reserved1 : 24;
#else
        uint32_t reserved1 : 24;
        uint32_t pcb_intr_type_n_pending_7 : 1;
        uint32_t pcb_intr_type_n_pending_6 : 1;
        uint32_t pcb_intr_type_n_pending_5 : 1;
        uint32_t pcb_intr_type_n_pending_4 : 1;
        uint32_t pcb_intr_type_n_pending_3 : 1;
        uint32_t pcb_intr_type_n_pending_2 : 1;
        uint32_t pcb_intr_type_n_pending_1 : 1;
        uint32_t pcb_intr_type_n_pending_0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit3pra_t;



typedef union ocb_opit4pra
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t pcb_intr_type_n_pending_0 : 1;
        uint32_t pcb_intr_type_n_pending_1 : 1;
        uint32_t pcb_intr_type_n_pending_2 : 1;
        uint32_t pcb_intr_type_n_pending_3 : 1;
        uint32_t pcb_intr_type_n_pending_4 : 1;
        uint32_t pcb_intr_type_n_pending_5 : 1;
        uint32_t pcb_intr_type_n_pending_6 : 1;
        uint32_t pcb_intr_type_n_pending_7 : 1;
        uint32_t reserved1 : 24;
#else
        uint32_t reserved1 : 24;
        uint32_t pcb_intr_type_n_pending_7 : 1;
        uint32_t pcb_intr_type_n_pending_6 : 1;
        uint32_t pcb_intr_type_n_pending_5 : 1;
        uint32_t pcb_intr_type_n_pending_4 : 1;
        uint32_t pcb_intr_type_n_pending_3 : 1;
        uint32_t pcb_intr_type_n_pending_2 : 1;
        uint32_t pcb_intr_type_n_pending_1 : 1;
        uint32_t pcb_intr_type_n_pending_0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit4pra_t;



typedef union ocb_opit5pra
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t pcb_intr_type_n_pending_0 : 1;
        uint32_t pcb_intr_type_n_pending_1 : 1;
        uint32_t pcb_intr_type_n_pending_2 : 1;
        uint32_t pcb_intr_type_n_pending_3 : 1;
        uint32_t pcb_intr_type_n_pending_4 : 1;
        uint32_t pcb_intr_type_n_pending_5 : 1;
        uint32_t pcb_intr_type_n_pending_6 : 1;
        uint32_t pcb_intr_type_n_pending_7 : 1;
        uint32_t reserved1 : 24;
#else
        uint32_t reserved1 : 24;
        uint32_t pcb_intr_type_n_pending_7 : 1;
        uint32_t pcb_intr_type_n_pending_6 : 1;
        uint32_t pcb_intr_type_n_pending_5 : 1;
        uint32_t pcb_intr_type_n_pending_4 : 1;
        uint32_t pcb_intr_type_n_pending_3 : 1;
        uint32_t pcb_intr_type_n_pending_2 : 1;
        uint32_t pcb_intr_type_n_pending_1 : 1;
        uint32_t pcb_intr_type_n_pending_0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit5pra_t;



typedef union ocb_opit6pra
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t pcb_intr_type_n_pending_0 : 1;
        uint32_t pcb_intr_type_n_pending_1 : 1;
        uint32_t pcb_intr_type_n_pending_2 : 1;
        uint32_t pcb_intr_type_n_pending_3 : 1;
        uint32_t pcb_intr_type_n_pending_4 : 1;
        uint32_t pcb_intr_type_n_pending_5 : 1;
        uint32_t pcb_intr_type_n_pending_6 : 1;
        uint32_t pcb_intr_type_n_pending_7 : 1;
        uint32_t reserved1 : 24;
#else
        uint32_t reserved1 : 24;
        uint32_t pcb_intr_type_n_pending_7 : 1;
        uint32_t pcb_intr_type_n_pending_6 : 1;
        uint32_t pcb_intr_type_n_pending_5 : 1;
        uint32_t pcb_intr_type_n_pending_4 : 1;
        uint32_t pcb_intr_type_n_pending_3 : 1;
        uint32_t pcb_intr_type_n_pending_2 : 1;
        uint32_t pcb_intr_type_n_pending_1 : 1;
        uint32_t pcb_intr_type_n_pending_0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit6pra_t;



typedef union ocb_opit7pra
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t pcb_intr_type_n_pending_0 : 1;
        uint32_t pcb_intr_type_n_pending_1 : 1;
        uint32_t pcb_intr_type_n_pending_2 : 1;
        uint32_t pcb_intr_type_n_pending_3 : 1;
        uint32_t pcb_intr_type_n_pending_4 : 1;
        uint32_t pcb_intr_type_n_pending_5 : 1;
        uint32_t pcb_intr_type_n_pending_6 : 1;
        uint32_t pcb_intr_type_n_pending_7 : 1;
        uint32_t reserved1 : 24;
#else
        uint32_t reserved1 : 24;
        uint32_t pcb_intr_type_n_pending_7 : 1;
        uint32_t pcb_intr_type_n_pending_6 : 1;
        uint32_t pcb_intr_type_n_pending_5 : 1;
        uint32_t pcb_intr_type_n_pending_4 : 1;
        uint32_t pcb_intr_type_n_pending_3 : 1;
        uint32_t pcb_intr_type_n_pending_2 : 1;
        uint32_t pcb_intr_type_n_pending_1 : 1;
        uint32_t pcb_intr_type_n_pending_0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit7pra_t;



typedef union ocb_opit8prb
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t pcb_intr_type_n_pending_0 : 1;
        uint32_t pcb_intr_type_n_pending_1 : 1;
        uint32_t pcb_intr_type_n_pending_2 : 1;
        uint32_t pcb_intr_type_n_pending_3 : 1;
        uint32_t pcb_intr_type_n_pending_4 : 1;
        uint32_t pcb_intr_type_n_pending_5 : 1;
        uint32_t pcb_intr_type_n_pending_6 : 1;
        uint32_t pcb_intr_type_n_pending_7 : 1;
        uint32_t pcb_intr_type_n_pending_8 : 1;
        uint32_t pcb_intr_type_n_pending_9 : 1;
        uint32_t pcb_intr_type_n_pending_10 : 1;
        uint32_t pcb_intr_type_n_pending_11 : 1;
        uint32_t pcb_intr_type_n_pending_12 : 1;
        uint32_t pcb_intr_type_n_pending_13 : 1;
        uint32_t pcb_intr_type_n_pending_14 : 1;
        uint32_t pcb_intr_type_n_pending_15 : 1;
        uint32_t pcb_intr_type_n_pending_16 : 1;
        uint32_t pcb_intr_type_n_pending_17 : 1;
        uint32_t pcb_intr_type_n_pending_18 : 1;
        uint32_t pcb_intr_type_n_pending_19 : 1;
        uint32_t pcb_intr_type_n_pending_20 : 1;
        uint32_t pcb_intr_type_n_pending_21 : 1;
        uint32_t pcb_intr_type_n_pending_22 : 1;
        uint32_t pcb_intr_type_n_pending_23 : 1;
        uint32_t pcb_intr_type_n_pending_24 : 1;
        uint32_t pcb_intr_type_n_pending_25 : 1;
        uint32_t pcb_intr_type_n_pending_26 : 1;
        uint32_t pcb_intr_type_n_pending_27 : 1;
        uint32_t pcb_intr_type_n_pending_28 : 1;
        uint32_t pcb_intr_type_n_pending_29 : 1;
        uint32_t pcb_intr_type_n_pending_30 : 1;
        uint32_t pcb_intr_type_n_pending_31 : 1;
#else
        uint32_t pcb_intr_type_n_pending_31 : 1;
        uint32_t pcb_intr_type_n_pending_30 : 1;
        uint32_t pcb_intr_type_n_pending_29 : 1;
        uint32_t pcb_intr_type_n_pending_28 : 1;
        uint32_t pcb_intr_type_n_pending_27 : 1;
        uint32_t pcb_intr_type_n_pending_26 : 1;
        uint32_t pcb_intr_type_n_pending_25 : 1;
        uint32_t pcb_intr_type_n_pending_24 : 1;
        uint32_t pcb_intr_type_n_pending_23 : 1;
        uint32_t pcb_intr_type_n_pending_22 : 1;
        uint32_t pcb_intr_type_n_pending_21 : 1;
        uint32_t pcb_intr_type_n_pending_20 : 1;
        uint32_t pcb_intr_type_n_pending_19 : 1;
        uint32_t pcb_intr_type_n_pending_18 : 1;
        uint32_t pcb_intr_type_n_pending_17 : 1;
        uint32_t pcb_intr_type_n_pending_16 : 1;
        uint32_t pcb_intr_type_n_pending_15 : 1;
        uint32_t pcb_intr_type_n_pending_14 : 1;
        uint32_t pcb_intr_type_n_pending_13 : 1;
        uint32_t pcb_intr_type_n_pending_12 : 1;
        uint32_t pcb_intr_type_n_pending_11 : 1;
        uint32_t pcb_intr_type_n_pending_10 : 1;
        uint32_t pcb_intr_type_n_pending_9 : 1;
        uint32_t pcb_intr_type_n_pending_8 : 1;
        uint32_t pcb_intr_type_n_pending_7 : 1;
        uint32_t pcb_intr_type_n_pending_6 : 1;
        uint32_t pcb_intr_type_n_pending_5 : 1;
        uint32_t pcb_intr_type_n_pending_4 : 1;
        uint32_t pcb_intr_type_n_pending_3 : 1;
        uint32_t pcb_intr_type_n_pending_2 : 1;
        uint32_t pcb_intr_type_n_pending_1 : 1;
        uint32_t pcb_intr_type_n_pending_0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit8prb_t;



typedef union ocb_opit9prb
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t pcb_intr_type_n_pending_0 : 1;
        uint32_t pcb_intr_type_n_pending_1 : 1;
        uint32_t pcb_intr_type_n_pending_2 : 1;
        uint32_t pcb_intr_type_n_pending_3 : 1;
        uint32_t pcb_intr_type_n_pending_4 : 1;
        uint32_t pcb_intr_type_n_pending_5 : 1;
        uint32_t pcb_intr_type_n_pending_6 : 1;
        uint32_t pcb_intr_type_n_pending_7 : 1;
        uint32_t pcb_intr_type_n_pending_8 : 1;
        uint32_t pcb_intr_type_n_pending_9 : 1;
        uint32_t pcb_intr_type_n_pending_10 : 1;
        uint32_t pcb_intr_type_n_pending_11 : 1;
        uint32_t pcb_intr_type_n_pending_12 : 1;
        uint32_t pcb_intr_type_n_pending_13 : 1;
        uint32_t pcb_intr_type_n_pending_14 : 1;
        uint32_t pcb_intr_type_n_pending_15 : 1;
        uint32_t pcb_intr_type_n_pending_16 : 1;
        uint32_t pcb_intr_type_n_pending_17 : 1;
        uint32_t pcb_intr_type_n_pending_18 : 1;
        uint32_t pcb_intr_type_n_pending_19 : 1;
        uint32_t pcb_intr_type_n_pending_20 : 1;
        uint32_t pcb_intr_type_n_pending_21 : 1;
        uint32_t pcb_intr_type_n_pending_22 : 1;
        uint32_t pcb_intr_type_n_pending_23 : 1;
        uint32_t pcb_intr_type_n_pending_24 : 1;
        uint32_t pcb_intr_type_n_pending_25 : 1;
        uint32_t pcb_intr_type_n_pending_26 : 1;
        uint32_t pcb_intr_type_n_pending_27 : 1;
        uint32_t pcb_intr_type_n_pending_28 : 1;
        uint32_t pcb_intr_type_n_pending_29 : 1;
        uint32_t pcb_intr_type_n_pending_30 : 1;
        uint32_t pcb_intr_type_n_pending_31 : 1;
#else
        uint32_t pcb_intr_type_n_pending_31 : 1;
        uint32_t pcb_intr_type_n_pending_30 : 1;
        uint32_t pcb_intr_type_n_pending_29 : 1;
        uint32_t pcb_intr_type_n_pending_28 : 1;
        uint32_t pcb_intr_type_n_pending_27 : 1;
        uint32_t pcb_intr_type_n_pending_26 : 1;
        uint32_t pcb_intr_type_n_pending_25 : 1;
        uint32_t pcb_intr_type_n_pending_24 : 1;
        uint32_t pcb_intr_type_n_pending_23 : 1;
        uint32_t pcb_intr_type_n_pending_22 : 1;
        uint32_t pcb_intr_type_n_pending_21 : 1;
        uint32_t pcb_intr_type_n_pending_20 : 1;
        uint32_t pcb_intr_type_n_pending_19 : 1;
        uint32_t pcb_intr_type_n_pending_18 : 1;
        uint32_t pcb_intr_type_n_pending_17 : 1;
        uint32_t pcb_intr_type_n_pending_16 : 1;
        uint32_t pcb_intr_type_n_pending_15 : 1;
        uint32_t pcb_intr_type_n_pending_14 : 1;
        uint32_t pcb_intr_type_n_pending_13 : 1;
        uint32_t pcb_intr_type_n_pending_12 : 1;
        uint32_t pcb_intr_type_n_pending_11 : 1;
        uint32_t pcb_intr_type_n_pending_10 : 1;
        uint32_t pcb_intr_type_n_pending_9 : 1;
        uint32_t pcb_intr_type_n_pending_8 : 1;
        uint32_t pcb_intr_type_n_pending_7 : 1;
        uint32_t pcb_intr_type_n_pending_6 : 1;
        uint32_t pcb_intr_type_n_pending_5 : 1;
        uint32_t pcb_intr_type_n_pending_4 : 1;
        uint32_t pcb_intr_type_n_pending_3 : 1;
        uint32_t pcb_intr_type_n_pending_2 : 1;
        uint32_t pcb_intr_type_n_pending_1 : 1;
        uint32_t pcb_intr_type_n_pending_0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit9prb_t;



typedef union ocb_opitaprc
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t pcb_intr_type_n_pending_0 : 1;
        uint32_t pcb_intr_type_n_pending_1 : 1;
        uint32_t pcb_intr_type_n_pending_2 : 1;
        uint32_t pcb_intr_type_n_pending_3 : 1;
        uint32_t pcb_intr_type_n_pending_4 : 1;
        uint32_t pcb_intr_type_n_pending_5 : 1;
        uint32_t pcb_intr_type_n_pending_6 : 1;
        uint32_t pcb_intr_type_n_pending_7 : 1;
        uint32_t reserved1 : 24;
#else
        uint32_t reserved1 : 24;
        uint32_t pcb_intr_type_n_pending_7 : 1;
        uint32_t pcb_intr_type_n_pending_6 : 1;
        uint32_t pcb_intr_type_n_pending_5 : 1;
        uint32_t pcb_intr_type_n_pending_4 : 1;
        uint32_t pcb_intr_type_n_pending_3 : 1;
        uint32_t pcb_intr_type_n_pending_2 : 1;
        uint32_t pcb_intr_type_n_pending_1 : 1;
        uint32_t pcb_intr_type_n_pending_0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opitaprc_t;



typedef union ocb_opitbprc
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t pcb_intr_type_n_pending_0 : 1;
        uint32_t pcb_intr_type_n_pending_1 : 1;
        uint32_t pcb_intr_type_n_pending_2 : 1;
        uint32_t pcb_intr_type_n_pending_3 : 1;
        uint32_t pcb_intr_type_n_pending_4 : 1;
        uint32_t pcb_intr_type_n_pending_5 : 1;
        uint32_t pcb_intr_type_n_pending_6 : 1;
        uint32_t pcb_intr_type_n_pending_7 : 1;
        uint32_t reserved1 : 24;
#else
        uint32_t reserved1 : 24;
        uint32_t pcb_intr_type_n_pending_7 : 1;
        uint32_t pcb_intr_type_n_pending_6 : 1;
        uint32_t pcb_intr_type_n_pending_5 : 1;
        uint32_t pcb_intr_type_n_pending_4 : 1;
        uint32_t pcb_intr_type_n_pending_3 : 1;
        uint32_t pcb_intr_type_n_pending_2 : 1;
        uint32_t pcb_intr_type_n_pending_1 : 1;
        uint32_t pcb_intr_type_n_pending_0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opitbprc_t;



typedef union ocb_opitcprc
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t pcb_intr_type_n_pending_0 : 1;
        uint32_t pcb_intr_type_n_pending_1 : 1;
        uint32_t pcb_intr_type_n_pending_2 : 1;
        uint32_t pcb_intr_type_n_pending_3 : 1;
        uint32_t pcb_intr_type_n_pending_4 : 1;
        uint32_t pcb_intr_type_n_pending_5 : 1;
        uint32_t pcb_intr_type_n_pending_6 : 1;
        uint32_t pcb_intr_type_n_pending_7 : 1;
        uint32_t reserved1 : 24;
#else
        uint32_t reserved1 : 24;
        uint32_t pcb_intr_type_n_pending_7 : 1;
        uint32_t pcb_intr_type_n_pending_6 : 1;
        uint32_t pcb_intr_type_n_pending_5 : 1;
        uint32_t pcb_intr_type_n_pending_4 : 1;
        uint32_t pcb_intr_type_n_pending_3 : 1;
        uint32_t pcb_intr_type_n_pending_2 : 1;
        uint32_t pcb_intr_type_n_pending_1 : 1;
        uint32_t pcb_intr_type_n_pending_0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opitcprc_t;



typedef union ocb_opitdprc
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t pcb_intr_type_n_pending_0 : 1;
        uint32_t pcb_intr_type_n_pending_1 : 1;
        uint32_t pcb_intr_type_n_pending_2 : 1;
        uint32_t pcb_intr_type_n_pending_3 : 1;
        uint32_t pcb_intr_type_n_pending_4 : 1;
        uint32_t pcb_intr_type_n_pending_5 : 1;
        uint32_t pcb_intr_type_n_pending_6 : 1;
        uint32_t pcb_intr_type_n_pending_7 : 1;
        uint32_t reserved1 : 24;
#else
        uint32_t reserved1 : 24;
        uint32_t pcb_intr_type_n_pending_7 : 1;
        uint32_t pcb_intr_type_n_pending_6 : 1;
        uint32_t pcb_intr_type_n_pending_5 : 1;
        uint32_t pcb_intr_type_n_pending_4 : 1;
        uint32_t pcb_intr_type_n_pending_3 : 1;
        uint32_t pcb_intr_type_n_pending_2 : 1;
        uint32_t pcb_intr_type_n_pending_1 : 1;
        uint32_t pcb_intr_type_n_pending_0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opitdprc_t;



typedef union ocb_opiteprd
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t pcb_intr_type_n_pending_0 : 1;
        uint32_t pcb_intr_type_n_pending_1 : 1;
        uint32_t pcb_intr_type_n_pending_2 : 1;
        uint32_t pcb_intr_type_n_pending_3 : 1;
        uint32_t pcb_intr_type_n_pending_4 : 1;
        uint32_t pcb_intr_type_n_pending_5 : 1;
        uint32_t pcb_intr_type_n_pending_6 : 1;
        uint32_t pcb_intr_type_n_pending_7 : 1;
        uint32_t reserved1 : 24;
#else
        uint32_t reserved1 : 24;
        uint32_t pcb_intr_type_n_pending_7 : 1;
        uint32_t pcb_intr_type_n_pending_6 : 1;
        uint32_t pcb_intr_type_n_pending_5 : 1;
        uint32_t pcb_intr_type_n_pending_4 : 1;
        uint32_t pcb_intr_type_n_pending_3 : 1;
        uint32_t pcb_intr_type_n_pending_2 : 1;
        uint32_t pcb_intr_type_n_pending_1 : 1;
        uint32_t pcb_intr_type_n_pending_0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opiteprd_t;



typedef union ocb_opitfprd
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t pcb_intr_type_n_pending_0 : 1;
        uint32_t pcb_intr_type_n_pending_1 : 1;
        uint32_t pcb_intr_type_n_pending_2 : 1;
        uint32_t pcb_intr_type_n_pending_3 : 1;
        uint32_t pcb_intr_type_n_pending_4 : 1;
        uint32_t pcb_intr_type_n_pending_5 : 1;
        uint32_t pcb_intr_type_n_pending_6 : 1;
        uint32_t pcb_intr_type_n_pending_7 : 1;
        uint32_t reserved1 : 24;
#else
        uint32_t reserved1 : 24;
        uint32_t pcb_intr_type_n_pending_7 : 1;
        uint32_t pcb_intr_type_n_pending_6 : 1;
        uint32_t pcb_intr_type_n_pending_5 : 1;
        uint32_t pcb_intr_type_n_pending_4 : 1;
        uint32_t pcb_intr_type_n_pending_3 : 1;
        uint32_t pcb_intr_type_n_pending_2 : 1;
        uint32_t pcb_intr_type_n_pending_1 : 1;
        uint32_t pcb_intr_type_n_pending_0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opitfprd_t;



typedef union ocb_o2sctrlfn
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t o2s_frame_size_n : 6;
        uint32_t o2s_out_count1_n : 6;
        uint32_t o2s_in_delay1_n : 6;
        uint32_t o2s_in_count1_n : 6;
        uint32_t reserved1 : 8;
#else
        uint32_t reserved1 : 8;
        uint32_t o2s_in_count1_n : 6;
        uint32_t o2s_in_delay1_n : 6;
        uint32_t o2s_out_count1_n : 6;
        uint32_t o2s_frame_size_n : 6;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2sctrlfn_t;



typedef union ocb_o2sctrlsn
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t o2s_out_count2_n : 6;
        uint32_t o2s_in_delay2_n : 6;
        uint32_t o2s_in_count2_n : 6;
        uint32_t reserved1 : 14;
#else
        uint32_t reserved1 : 14;
        uint32_t o2s_in_count2_n : 6;
        uint32_t o2s_in_delay2_n : 6;
        uint32_t o2s_out_count2_n : 6;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2sctrlsn_t;



typedef union ocb_o2sctrl1n
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t o2s_bridge_enable_n_a : 1;
        uint32_t o2s_bridge_enable_n_b : 1;
        uint32_t reserved1 : 2;
        uint32_t o2s_clock_divider_n : 10;
        uint32_t o2sctrl1n_reserved_14_16 : 3;
        uint32_t o2s_nr_of_frames_n : 1;
        uint32_t reserved2 : 2;
        uint32_t slave_data_sample_delay : 7;
        uint32_t reserved3 : 5;
#else
        uint32_t reserved3 : 5;
        uint32_t slave_data_sample_delay : 7;
        uint32_t reserved2 : 2;
        uint32_t o2s_nr_of_frames_n : 1;
        uint32_t o2sctrl1n_reserved_14_16 : 3;
        uint32_t o2s_clock_divider_n : 10;
        uint32_t reserved1 : 2;
        uint32_t o2s_bridge_enable_n_b : 1;
        uint32_t o2s_bridge_enable_n_a : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2sctrl1n_t;



typedef union ocb_o2sctrl2n
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t o2s_inter_frame_delay_n : 16;
        uint32_t reserved1 : 16;
#else
        uint32_t reserved1 : 16;
        uint32_t o2s_inter_frame_delay_n : 16;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2sctrl2n_t;



typedef union ocb_o2sstna
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t o2s_ongoing_an : 1;
        uint32_t o2sstan_reserved_1_4 : 4;
        uint32_t o2s_write_while_bridge_busy_err_an : 1;
        uint32_t o2sstan_reserved_6 : 1;
        uint32_t o2s_fsm_err_an : 1;
        uint32_t reserved1 : 24;
#else
        uint32_t reserved1 : 24;
        uint32_t o2s_fsm_err_an : 1;
        uint32_t o2sstan_reserved_6 : 1;
        uint32_t o2s_write_while_bridge_busy_err_an : 1;
        uint32_t o2sstan_reserved_1_4 : 4;
        uint32_t o2s_ongoing_an : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2sstna_t;



typedef union ocb_o2scmdna
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t o2scmdan_reserved_0 : 1;
        uint32_t o2s_clear_sticky_bits_an : 1;
        uint32_t reserved1 : 30;
#else
        uint32_t reserved1 : 30;
        uint32_t o2s_clear_sticky_bits_an : 1;
        uint32_t o2scmdan_reserved_0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2scmdna_t;



typedef union ocb_o2swdna
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t o2s_wdata_an : 32;
#else
        uint32_t o2s_wdata_an : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2swdna_t;



typedef union ocb_o2srdna
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t o2s_rdata_an : 32;
#else
        uint32_t o2s_rdata_an : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2srdna_t;



typedef union ocb_o2sstnb
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t o2s_ongoing_an : 1;
        uint32_t o2sstan_reserved_1_4 : 4;
        uint32_t o2s_write_while_bridge_busy_err_an : 1;
        uint32_t o2sstan_reserved_6 : 1;
        uint32_t o2s_fsm_err_an : 1;
        uint32_t reserved1 : 24;
#else
        uint32_t reserved1 : 24;
        uint32_t o2s_fsm_err_an : 1;
        uint32_t o2sstan_reserved_6 : 1;
        uint32_t o2s_write_while_bridge_busy_err_an : 1;
        uint32_t o2sstan_reserved_1_4 : 4;
        uint32_t o2s_ongoing_an : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2sstnb_t;



typedef union ocb_o2scmdnb
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t o2scmdan_reserved_0 : 1;
        uint32_t o2s_clear_sticky_bits_an : 1;
        uint32_t reserved1 : 30;
#else
        uint32_t reserved1 : 30;
        uint32_t o2s_clear_sticky_bits_an : 1;
        uint32_t o2scmdan_reserved_0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2scmdnb_t;



typedef union ocb_o2swdnb
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t o2s_wdata_an : 32;
#else
        uint32_t o2s_wdata_an : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2swdnb_t;



typedef union ocb_o2srdnb
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t o2s_rdata_an : 32;
#else
        uint32_t o2s_rdata_an : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2srdnb_t;



typedef union ocb_woficctrl
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interchip_link_enable : 1;
        uint32_t interchip_link_reset : 1;
        uint32_t interchip_cpol : 1;
        uint32_t interchip_cpha : 1;
        uint32_t interchip_clock_divider : 10;
        uint32_t reserved_141 : 1;
        uint32_t interchip_wrap_enable : 1;
        uint32_t interchip_interface_enable_north : 1;
        uint32_t interchip_interface_enable_south : 1;
        uint32_t interchip_sync_en : 1;
        uint32_t reserved_192 : 1;
        uint32_t interchip_ecc_gen_en : 1;
        uint32_t interchip_ecc_check_en : 1;
        uint32_t rx_fsm_freeze_on_ue : 1;
        uint32_t interchip_reset_ecc_err : 1;
        uint32_t reserved3 : 8;
#else
        uint32_t reserved3 : 8;
        uint32_t interchip_reset_ecc_err : 1;
        uint32_t rx_fsm_freeze_on_ue : 1;
        uint32_t interchip_ecc_check_en : 1;
        uint32_t interchip_ecc_gen_en : 1;
        uint32_t reserved_192 : 1;
        uint32_t interchip_sync_en : 1;
        uint32_t interchip_interface_enable_south : 1;
        uint32_t interchip_interface_enable_north : 1;
        uint32_t interchip_wrap_enable : 1;
        uint32_t reserved_141 : 1;
        uint32_t interchip_clock_divider : 10;
        uint32_t interchip_cpha : 1;
        uint32_t interchip_cpol : 1;
        uint32_t interchip_link_reset : 1;
        uint32_t interchip_link_enable : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_woficctrl_t;



typedef union ocb_woficping
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interchip_ping_send : 1;
        uint32_t interchip_ping_mode : 1;
        uint32_t interchip_ping_master : 1;
        uint32_t interchip_ping_slave : 1;
        uint32_t interchip_ping_detect_clear : 1;
        uint32_t interchip_ping_dataop : 3;
        uint32_t reserved1 : 24;
#else
        uint32_t reserved1 : 24;
        uint32_t interchip_ping_dataop : 3;
        uint32_t interchip_ping_detect_clear : 1;
        uint32_t interchip_ping_slave : 1;
        uint32_t interchip_ping_master : 1;
        uint32_t interchip_ping_mode : 1;
        uint32_t interchip_ping_send : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_woficping_t;



typedef union ocb_woficstat
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t interchip_ecc_ue : 1;
        uint32_t interchip_ecc_ce : 1;
        uint32_t reserved_2_31 : 2;
        uint32_t interchip_tx_ongoing : 1;
        uint32_t interchip_rx_ongoing : 1;
        uint32_t interchip_ping_detected : 1;
        uint32_t interchip_ping_ack_detected : 1;
        uint32_t interchip_ping_detect_count : 8;
        uint32_t interchip_tx_ecc : 8;
        uint32_t interchip_rx_ecc : 8;
#else
        uint32_t interchip_rx_ecc : 8;
        uint32_t interchip_tx_ecc : 8;
        uint32_t interchip_ping_detect_count : 8;
        uint32_t interchip_ping_ack_detected : 1;
        uint32_t interchip_ping_detected : 1;
        uint32_t interchip_rx_ongoing : 1;
        uint32_t interchip_tx_ongoing : 1;
        uint32_t reserved_2_31 : 2;
        uint32_t interchip_ecc_ce : 1;
        uint32_t interchip_ecc_ue : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_woficstat_t;



typedef union ocb_woficrd
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t wofcntl_rddata : 32;
#else
        uint32_t wofcntl_rddata : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_woficrd_t;



typedef union ocb_woficwd
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t wocntl_wrdata_high : 32;
#else
        uint32_t wocntl_wrdata_high : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_woficwd_t;



typedef union ocb_woficdcm1
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t dcm_message : 32;
#else
        uint32_t dcm_message : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_woficdcm1_t;



typedef union ocb_woficdcm2
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t dcm_message : 32;
#else
        uint32_t dcm_message : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_woficdcm2_t;



typedef union ocb_woficecc
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t inject_ecc_err : 1;
        uint32_t continuous_inject : 1;
        uint32_t inject_type : 1;
        uint32_t inject_data_or_ecc : 1;
        uint32_t reserved1 : 28;
#else
        uint32_t reserved1 : 28;
        uint32_t inject_data_or_ecc : 1;
        uint32_t inject_type : 1;
        uint32_t continuous_inject : 1;
        uint32_t inject_ecc_err : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_woficecc_t;



typedef union ocb_adccr0
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t adc_frame_size : 6;
        uint32_t adc_out_count : 6;
        uint32_t adc_in_delay : 6;
        uint32_t adc_in_count : 6;
        uint32_t reserved1 : 8;
#else
        uint32_t reserved1 : 8;
        uint32_t adc_in_count : 6;
        uint32_t adc_in_delay : 6;
        uint32_t adc_out_count : 6;
        uint32_t adc_frame_size : 6;
#endif // _BIG_ENDIAN
    } fields;
} ocb_adccr0_t;



typedef union ocb_adccr1
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t hwctrl_fsm_enable : 1;
        uint32_t hwctrl_device : 1;
        uint32_t hwctrl_cpol : 1;
        uint32_t hwctrl_cpha : 1;
        uint32_t hwctrl_clock_divider : 10;
        uint32_t hwctrl_nr_of_frames : 5;
        uint32_t hwctrl_write_while_bridge_busy_scresp_en : 1;
        uint32_t busy_response_code : 3;
        uint32_t reserved1 : 9;
#else
        uint32_t reserved1 : 9;
        uint32_t busy_response_code : 3;
        uint32_t hwctrl_write_while_bridge_busy_scresp_en : 1;
        uint32_t hwctrl_nr_of_frames : 5;
        uint32_t hwctrl_clock_divider : 10;
        uint32_t hwctrl_cpha : 1;
        uint32_t hwctrl_cpol : 1;
        uint32_t hwctrl_device : 1;
        uint32_t hwctrl_fsm_enable : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_adccr1_t;



typedef union ocb_adccr2
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t hwctrl_inter_frame_delay : 17;
        uint32_t reserved1 : 15;
#else
        uint32_t reserved1 : 15;
        uint32_t hwctrl_inter_frame_delay : 17;
#endif // _BIG_ENDIAN
    } fields;
} ocb_adccr2_t;



typedef union ocb_adc_status
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t hwctrl_ongoing : 1;
        uint32_t reserved1 : 3;
        uint32_t hwctrl_invalid_number_of_frames : 1;
        uint32_t hwctrl_write_while_bridge_busy_err : 1;
        uint32_t reserved2 : 1;
        uint32_t hwctrl_fsm_err : 1;
        uint32_t reserved3 : 24;
#else
        uint32_t reserved3 : 24;
        uint32_t hwctrl_fsm_err : 1;
        uint32_t reserved2 : 1;
        uint32_t hwctrl_write_while_bridge_busy_err : 1;
        uint32_t hwctrl_invalid_number_of_frames : 1;
        uint32_t reserved1 : 3;
        uint32_t hwctrl_ongoing : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_adc_status_t;



typedef union ocb_adc_cmd
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t hwctrl_start_sampling : 1;
        uint32_t reserved1 : 31;
#else
        uint32_t reserved1 : 31;
        uint32_t hwctrl_start_sampling : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_adc_cmd_t;



typedef union ocb_adc_reset
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t hwctrl_reset : 2;
        uint32_t reserved1 : 30;
#else
        uint32_t reserved1 : 30;
        uint32_t hwctrl_reset : 2;
#endif // _BIG_ENDIAN
    } fields;
} ocb_adc_reset_t;



typedef union ocb_adc_wdata
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t hwctrl_wdata : 16;
        uint32_t reserved1 : 16;
#else
        uint32_t reserved1 : 16;
        uint32_t hwctrl_wdata : 16;
#endif // _BIG_ENDIAN
    } fields;
} ocb_adc_wdata_t;



typedef union ocb_adc_rdata0
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t hwctrl_rdata0 : 16;
        uint32_t hwctrl_rdata1 : 16;
#else
        uint32_t hwctrl_rdata1 : 16;
        uint32_t hwctrl_rdata0 : 16;
#endif // _BIG_ENDIAN
    } fields;
} ocb_adc_rdata0_t;



typedef union ocb_adc_rdata1
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t hwctrl_rdata4 : 16;
        uint32_t hwctrl_rdata5 : 16;
#else
        uint32_t hwctrl_rdata5 : 16;
        uint32_t hwctrl_rdata4 : 16;
#endif // _BIG_ENDIAN
    } fields;
} ocb_adc_rdata1_t;



typedef union ocb_adc_rdata2
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t hwctrl_rdata8 : 16;
        uint32_t hwctrl_rdata9 : 16;
#else
        uint32_t hwctrl_rdata9 : 16;
        uint32_t hwctrl_rdata8 : 16;
#endif // _BIG_ENDIAN
    } fields;
} ocb_adc_rdata2_t;



typedef union ocb_adc_rdata3
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t hwctrl_rdata12 : 16;
        uint32_t hwctrl_rdata13 : 16;
#else
        uint32_t hwctrl_rdata13 : 16;
        uint32_t hwctrl_rdata12 : 16;
#endif // _BIG_ENDIAN
    } fields;
} ocb_adc_rdata3_t;



typedef union ocb_adc_rdata4
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t hwctrl_rdata16 : 16;
        uint32_t hwctrl_rdata17 : 16;
#else
        uint32_t hwctrl_rdata17 : 16;
        uint32_t hwctrl_rdata16 : 16;
#endif // _BIG_ENDIAN
    } fields;
} ocb_adc_rdata4_t;



typedef union ocb_adc_rdata5
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t hwctrl_rdata20 : 16;
        uint32_t hwctrl_rdata21 : 16;
#else
        uint32_t hwctrl_rdata21 : 16;
        uint32_t hwctrl_rdata20 : 16;
#endif // _BIG_ENDIAN
    } fields;
} ocb_adc_rdata5_t;



typedef union ocb_adc_rdata6
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t hwctrl_rdata24 : 16;
        uint32_t hwctrl_rdata25 : 16;
#else
        uint32_t hwctrl_rdata25 : 16;
        uint32_t hwctrl_rdata24 : 16;
#endif // _BIG_ENDIAN
    } fields;
} ocb_adc_rdata6_t;



typedef union ocb_adc_rdata7
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t hwctrl_rdata28 : 16;
        uint32_t hwctrl_rdata29 : 16;
#else
        uint32_t hwctrl_rdata29 : 16;
        uint32_t hwctrl_rdata28 : 16;
#endif // _BIG_ENDIAN
    } fields;
} ocb_adc_rdata7_t;



typedef union ocb_p2s_100ns
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t p2s_100ns : 32;
#else
        uint32_t p2s_100ns : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_p2s_100ns_t;



typedef union ocb_p2scr0
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t p2s_frame_size : 6;
        uint32_t p2s_out_count1 : 6;
        uint32_t p2s_in_delay1 : 6;
        uint32_t p2s_in_count1 : 6;
        uint32_t p2s_out_count2 : 6;
        uint32_t p2s_in_delay2 : 2;
#else
        uint32_t p2s_in_delay2 : 2;
        uint32_t p2s_out_count2 : 6;
        uint32_t p2s_in_count1 : 6;
        uint32_t p2s_in_delay1 : 6;
        uint32_t p2s_out_count1 : 6;
        uint32_t p2s_frame_size : 6;
#endif // _BIG_ENDIAN
    } fields;
} ocb_p2scr0_t;



typedef union ocb_p2scr1
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t p2s_bridge_enable : 1;
        uint32_t p2s_device : 1;
        uint32_t p2s_cpol : 1;
        uint32_t p2s_cpha : 1;
        uint32_t p2s_clock_divider : 10;
        uint32_t p2scr1_reserved_2 : 3;
        uint32_t p2s_nr_of_frames : 1;
        uint32_t reserved1 : 14;
#else
        uint32_t reserved1 : 14;
        uint32_t p2s_nr_of_frames : 1;
        uint32_t p2scr1_reserved_2 : 3;
        uint32_t p2s_clock_divider : 10;
        uint32_t p2s_cpha : 1;
        uint32_t p2s_cpol : 1;
        uint32_t p2s_device : 1;
        uint32_t p2s_bridge_enable : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_p2scr1_t;



typedef union ocb_p2scr2
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t p2s_inter_frame_delay : 17;
        uint32_t reserved1 : 15;
#else
        uint32_t reserved1 : 15;
        uint32_t p2s_inter_frame_delay : 17;
#endif // _BIG_ENDIAN
    } fields;
} ocb_p2scr2_t;



typedef union ocb_p2s_status
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t p2s_ongoing : 1;
        uint32_t reserved1 : 4;
        uint32_t p2s_write_while_bridge_busy_err : 1;
        uint32_t reserved2 : 1;
        uint32_t p2s_fsm_err : 1;
        uint32_t reserved3 : 24;
#else
        uint32_t reserved3 : 24;
        uint32_t p2s_fsm_err : 1;
        uint32_t reserved2 : 1;
        uint32_t p2s_write_while_bridge_busy_err : 1;
        uint32_t reserved1 : 4;
        uint32_t p2s_ongoing : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_p2s_status_t;



typedef union ocb_p2s_cmd
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t start_p2s_command : 1;
        uint32_t reserved1 : 31;
#else
        uint32_t reserved1 : 31;
        uint32_t start_p2s_command : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_p2s_cmd_t;



typedef union ocb_p2s_wdata
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t p2s_wdata : 32;
#else
        uint32_t p2s_wdata : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_p2s_wdata_t;



typedef union ocb_p2s_rdata
{

    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t p2s_rdata : 32;
#else
        uint32_t p2s_rdata : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_p2s_rdata_t;



typedef union ocb_ocr
{

    uint64_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct
    {
#ifdef _BIG_ENDIAN
        uint64_t core_reset : 1;
        uint64_t chip_reset : 1;
        uint64_t system_reset : 1;
        uint64_t oci_arb_reset : 1;
        uint64_t trace_disable : 1;
        uint64_t trace_event : 1;
        uint64_t dbg_unconditional_event : 1;
        uint64_t ext_interrupt : 1;
        uint64_t critical_interrupt : 1;
        uint64_t pib_slave_reset_to_405_enable : 1;
        uint64_t ocr_dbg_halt : 1;
        uint64_t spare : 5;
        uint64_t reserved1 : 48;
#else
        uint64_t reserved1 : 48;
        uint64_t spare : 5;
        uint64_t ocr_dbg_halt : 1;
        uint64_t pib_slave_reset_to_405_enable : 1;
        uint64_t critical_interrupt : 1;
        uint64_t ext_interrupt : 1;
        uint64_t dbg_unconditional_event : 1;
        uint64_t trace_event : 1;
        uint64_t trace_disable : 1;
        uint64_t oci_arb_reset : 1;
        uint64_t system_reset : 1;
        uint64_t chip_reset : 1;
        uint64_t core_reset : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocr_t;



typedef union ocb_ocr_clr
{

    uint64_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct
    {
#ifdef _BIG_ENDIAN
        uint64_t core_reset : 1;
        uint64_t chip_reset : 1;
        uint64_t system_reset : 1;
        uint64_t oci_arb_reset : 1;
        uint64_t trace_disable : 1;
        uint64_t trace_event : 1;
        uint64_t dbg_unconditional_event : 1;
        uint64_t ext_interrupt : 1;
        uint64_t critical_interrupt : 1;
        uint64_t pib_slave_reset_to_405_enable : 1;
        uint64_t ocr_dbg_halt : 1;
        uint64_t spare : 5;
        uint64_t reserved1 : 48;
#else
        uint64_t reserved1 : 48;
        uint64_t spare : 5;
        uint64_t ocr_dbg_halt : 1;
        uint64_t pib_slave_reset_to_405_enable : 1;
        uint64_t critical_interrupt : 1;
        uint64_t ext_interrupt : 1;
        uint64_t dbg_unconditional_event : 1;
        uint64_t trace_event : 1;
        uint64_t trace_disable : 1;
        uint64_t oci_arb_reset : 1;
        uint64_t system_reset : 1;
        uint64_t chip_reset : 1;
        uint64_t core_reset : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocr_clr_t;



typedef union ocb_ocr_or
{

    uint64_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct
    {
#ifdef _BIG_ENDIAN
        uint64_t core_reset : 1;
        uint64_t chip_reset : 1;
        uint64_t system_reset : 1;
        uint64_t oci_arb_reset : 1;
        uint64_t trace_disable : 1;
        uint64_t trace_event : 1;
        uint64_t dbg_unconditional_event : 1;
        uint64_t ext_interrupt : 1;
        uint64_t critical_interrupt : 1;
        uint64_t pib_slave_reset_to_405_enable : 1;
        uint64_t ocr_dbg_halt : 1;
        uint64_t spare : 5;
        uint64_t reserved1 : 48;
#else
        uint64_t reserved1 : 48;
        uint64_t spare : 5;
        uint64_t ocr_dbg_halt : 1;
        uint64_t pib_slave_reset_to_405_enable : 1;
        uint64_t critical_interrupt : 1;
        uint64_t ext_interrupt : 1;
        uint64_t dbg_unconditional_event : 1;
        uint64_t trace_event : 1;
        uint64_t trace_disable : 1;
        uint64_t oci_arb_reset : 1;
        uint64_t system_reset : 1;
        uint64_t chip_reset : 1;
        uint64_t core_reset : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocr_or_t;



typedef union ocb_ocdbg
{

    uint64_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct
    {
#ifdef _BIG_ENDIAN
        uint64_t mst_dis_abusparen : 1;
        uint64_t mst_dis_beparen : 1;
        uint64_t mst_dis_wrdbusparen : 1;
        uint64_t mst_dis_rddbuspar : 1;
        uint64_t mst_spare : 1;
        uint64_t slv_dis_sack : 1;
        uint64_t slv_dis_abuspar : 1;
        uint64_t slv_dis_bepar : 1;
        uint64_t slv_dis_be : 1;
        uint64_t slv_dis_wrdbuspar : 1;
        uint64_t slv_dis_rddbusparen : 1;
        uint64_t slv_spare : 1;
        uint64_t disable_opit_parity : 1;
        uint64_t freeze_on_first_opit_perr : 1;
        uint64_t spare : 2;
        uint64_t reserved1 : 48;
#else
        uint64_t reserved1 : 48;
        uint64_t spare : 2;
        uint64_t freeze_on_first_opit_perr : 1;
        uint64_t disable_opit_parity : 1;
        uint64_t slv_spare : 1;
        uint64_t slv_dis_rddbusparen : 1;
        uint64_t slv_dis_wrdbuspar : 1;
        uint64_t slv_dis_be : 1;
        uint64_t slv_dis_bepar : 1;
        uint64_t slv_dis_abuspar : 1;
        uint64_t slv_dis_sack : 1;
        uint64_t mst_spare : 1;
        uint64_t mst_dis_rddbuspar : 1;
        uint64_t mst_dis_wrdbusparen : 1;
        uint64_t mst_dis_beparen : 1;
        uint64_t mst_dis_abusparen : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocdbg_t;



typedef union ocb_ojcfg
{

    uint64_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct
    {
#ifdef _BIG_ENDIAN
        uint64_t jtag_src_sel : 1;
        uint64_t run_tck : 1;
        uint64_t tck_width : 3;
        uint64_t jtag_trst_b : 1;
        uint64_t dbg_halt : 1;
        uint64_t reserved1 : 57;
#else
        uint64_t reserved1 : 57;
        uint64_t dbg_halt : 1;
        uint64_t jtag_trst_b : 1;
        uint64_t tck_width : 3;
        uint64_t run_tck : 1;
        uint64_t jtag_src_sel : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ojcfg_t;



typedef union ocb_ojcfg_clr
{

    uint64_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct
    {
#ifdef _BIG_ENDIAN
        uint64_t jtag_src_sel : 1;
        uint64_t run_tck : 1;
        uint64_t tck_width : 3;
        uint64_t jtag_trst_b : 1;
        uint64_t dbg_halt : 1;
        uint64_t reserved1 : 57;
#else
        uint64_t reserved1 : 57;
        uint64_t dbg_halt : 1;
        uint64_t jtag_trst_b : 1;
        uint64_t tck_width : 3;
        uint64_t run_tck : 1;
        uint64_t jtag_src_sel : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ojcfg_clr_t;



typedef union ocb_ojcfg_or
{

    uint64_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct
    {
#ifdef _BIG_ENDIAN
        uint64_t jtag_src_sel : 1;
        uint64_t run_tck : 1;
        uint64_t tck_width : 3;
        uint64_t jtag_trst_b : 1;
        uint64_t dbg_halt : 1;
        uint64_t reserved1 : 57;
#else
        uint64_t reserved1 : 57;
        uint64_t dbg_halt : 1;
        uint64_t jtag_trst_b : 1;
        uint64_t tck_width : 3;
        uint64_t run_tck : 1;
        uint64_t jtag_src_sel : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ojcfg_or_t;



typedef union ocb_ojfrst
{

    uint64_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct
    {
#ifdef _BIG_ENDIAN
        uint64_t reserved1 : 64;
#else
        uint64_t reserved1 : 64;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ojfrst_t;



typedef union ocb_ojic
{

    uint64_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct
    {
#ifdef _BIG_ENDIAN
        uint64_t start_jtag_cmd : 1;
        uint64_t do_ir : 1;
        uint64_t do_dr : 1;
        uint64_t do_tap_reset : 1;
        uint64_t wr_valid : 1;
        uint64_t reserved1 : 7;
        uint64_t jtag_instr : 4;
        uint64_t reserved2 : 48;
#else
        uint64_t reserved2 : 48;
        uint64_t jtag_instr : 4;
        uint64_t reserved1 : 7;
        uint64_t wr_valid : 1;
        uint64_t do_tap_reset : 1;
        uint64_t do_dr : 1;
        uint64_t do_ir : 1;
        uint64_t start_jtag_cmd : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ojic_t;



typedef union ocb_ojic_clr
{

    uint64_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct
    {
#ifdef _BIG_ENDIAN
        uint64_t start_jtag_cmd : 1;
        uint64_t do_ir : 1;
        uint64_t do_dr : 1;
        uint64_t do_tap_reset : 1;
        uint64_t wr_valid : 1;
        uint64_t reserved1 : 7;
        uint64_t jtag_instr : 4;
        uint64_t reserved2 : 48;
#else
        uint64_t reserved2 : 48;
        uint64_t jtag_instr : 4;
        uint64_t reserved1 : 7;
        uint64_t wr_valid : 1;
        uint64_t do_tap_reset : 1;
        uint64_t do_dr : 1;
        uint64_t do_ir : 1;
        uint64_t start_jtag_cmd : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ojic_clr_t;



typedef union ocb_ojic_or
{

    uint64_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct
    {
#ifdef _BIG_ENDIAN
        uint64_t start_jtag_cmd : 1;
        uint64_t do_ir : 1;
        uint64_t do_dr : 1;
        uint64_t do_tap_reset : 1;
        uint64_t wr_valid : 1;
        uint64_t reserved1 : 7;
        uint64_t jtag_instr : 4;
        uint64_t reserved2 : 48;
#else
        uint64_t reserved2 : 48;
        uint64_t jtag_instr : 4;
        uint64_t reserved1 : 7;
        uint64_t wr_valid : 1;
        uint64_t do_tap_reset : 1;
        uint64_t do_dr : 1;
        uint64_t do_ir : 1;
        uint64_t start_jtag_cmd : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ojic_or_t;



typedef union ocb_ojstat
{

    uint64_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct
    {
#ifdef _BIG_ENDIAN
        uint64_t jtag_inprog : 1;
        uint64_t src_sel_eq1_err : 1;
        uint64_t run_tck_eq0_err : 1;
        uint64_t trst_b_eq0_err : 1;
        uint64_t ir_dr_eq0_err : 1;
        uint64_t inprog_wr_err : 1;
        uint64_t fsm_error : 1;
        uint64_t reserved1 : 57;
#else
        uint64_t reserved1 : 57;
        uint64_t fsm_error : 1;
        uint64_t inprog_wr_err : 1;
        uint64_t ir_dr_eq0_err : 1;
        uint64_t trst_b_eq0_err : 1;
        uint64_t run_tck_eq0_err : 1;
        uint64_t src_sel_eq1_err : 1;
        uint64_t jtag_inprog : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ojstat_t;



typedef union ocb_ojtdi
{

    uint64_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct
    {
#ifdef _BIG_ENDIAN
        uint64_t jtag_tdi : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t jtag_tdi : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ojtdi_t;



typedef union ocb_ojtdo
{

    uint64_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct
    {
#ifdef _BIG_ENDIAN
        uint64_t jtag_tdo : 32;
        uint64_t jtag_src_sel : 1;
        uint64_t run_tck : 1;
        uint64_t tck_width : 3;
        uint64_t jtag_trst_b : 1;
        uint64_t dbg_halt : 1;
        uint64_t reserved1 : 1;
        uint64_t jtag_inprog : 1;
        uint64_t src_sel_eq1_err : 1;
        uint64_t run_tck_eq0_err : 1;
        uint64_t trst_b_eq0_err : 1;
        uint64_t ir_dr_eq0_err : 1;
        uint64_t inprog_wr_err : 1;
        uint64_t fsm_error : 1;
        uint64_t reserved2 : 2;
        uint64_t do_ir : 1;
        uint64_t do_dr : 1;
        uint64_t do_tap_reset : 1;
        uint64_t wr_valid : 1;
        uint64_t reserved3 : 7;
        uint64_t jtag_instr : 4;
#else
        uint64_t jtag_instr : 4;
        uint64_t reserved3 : 7;
        uint64_t wr_valid : 1;
        uint64_t do_tap_reset : 1;
        uint64_t do_dr : 1;
        uint64_t do_ir : 1;
        uint64_t reserved2 : 2;
        uint64_t fsm_error : 1;
        uint64_t inprog_wr_err : 1;
        uint64_t ir_dr_eq0_err : 1;
        uint64_t trst_b_eq0_err : 1;
        uint64_t run_tck_eq0_err : 1;
        uint64_t src_sel_eq1_err : 1;
        uint64_t jtag_inprog : 1;
        uint64_t reserved1 : 1;
        uint64_t dbg_halt : 1;
        uint64_t jtag_trst_b : 1;
        uint64_t tck_width : 3;
        uint64_t run_tck : 1;
        uint64_t jtag_src_sel : 1;
        uint64_t jtag_tdo : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ojtdo_t;



typedef union ocb_ocbarn
{

    uint64_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct
    {
#ifdef _BIG_ENDIAN
        uint64_t oci_region : 3;
        uint64_t ocb_address : 26;
        uint64_t reserved1 : 35;
#else
        uint64_t reserved1 : 35;
        uint64_t ocb_address : 26;
        uint64_t oci_region : 3;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocbarn_t;



typedef union ocb_ocbcsrn
{

    uint64_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct
    {
#ifdef _BIG_ENDIAN
        uint64_t pull_read_underflow : 1;
        uint64_t push_write_overflow : 1;
        uint64_t pull_read_underflow_en : 1;
        uint64_t push_write_overflow_en : 1;
        uint64_t ocb_stream_mode : 1;
        uint64_t ocb_stream_type : 1;
        uint64_t spare0 : 2;
        uint64_t ocb_oci_timeout : 1;
        uint64_t ocb_oci_read_data_parity : 1;
        uint64_t ocb_oci_slave_error : 1;
        uint64_t ocb_pib_addr_parity_err : 1;
        uint64_t ocb_pib_data_parity_err : 1;
        uint64_t spare1 : 1;
        uint64_t ocb_fsm_err : 1;
        uint64_t spare2 : 1;
        uint64_t reserved1 : 48;
#else
        uint64_t reserved1 : 48;
        uint64_t spare2 : 1;
        uint64_t ocb_fsm_err : 1;
        uint64_t spare1 : 1;
        uint64_t ocb_pib_data_parity_err : 1;
        uint64_t ocb_pib_addr_parity_err : 1;
        uint64_t ocb_oci_slave_error : 1;
        uint64_t ocb_oci_read_data_parity : 1;
        uint64_t ocb_oci_timeout : 1;
        uint64_t spare0 : 2;
        uint64_t ocb_stream_type : 1;
        uint64_t ocb_stream_mode : 1;
        uint64_t push_write_overflow_en : 1;
        uint64_t pull_read_underflow_en : 1;
        uint64_t push_write_overflow : 1;
        uint64_t pull_read_underflow : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocbcsrn_t;



typedef union ocb_ocbcsrn_clr
{

    uint64_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct
    {
#ifdef _BIG_ENDIAN
        uint64_t pull_read_underflow : 1;
        uint64_t push_write_overflow : 1;
        uint64_t pull_read_underflow_en : 1;
        uint64_t push_write_overflow_en : 1;
        uint64_t ocb_stream_mode : 1;
        uint64_t ocb_stream_type : 1;
        uint64_t spare0 : 2;
        uint64_t ocb_oci_timeout : 1;
        uint64_t ocb_oci_read_data_parity : 1;
        uint64_t ocb_oci_slave_error : 1;
        uint64_t ocb_pib_addr_parity_err : 1;
        uint64_t ocb_pib_data_parity_err : 1;
        uint64_t spare1 : 1;
        uint64_t ocb_fsm_err : 1;
        uint64_t spare2 : 1;
        uint64_t reserved1 : 48;
#else
        uint64_t reserved1 : 48;
        uint64_t spare2 : 1;
        uint64_t ocb_fsm_err : 1;
        uint64_t spare1 : 1;
        uint64_t ocb_pib_data_parity_err : 1;
        uint64_t ocb_pib_addr_parity_err : 1;
        uint64_t ocb_oci_slave_error : 1;
        uint64_t ocb_oci_read_data_parity : 1;
        uint64_t ocb_oci_timeout : 1;
        uint64_t spare0 : 2;
        uint64_t ocb_stream_type : 1;
        uint64_t ocb_stream_mode : 1;
        uint64_t push_write_overflow_en : 1;
        uint64_t pull_read_underflow_en : 1;
        uint64_t push_write_overflow : 1;
        uint64_t pull_read_underflow : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocbcsrn_clr_t;



typedef union ocb_ocbcsrn_or
{

    uint64_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct
    {
#ifdef _BIG_ENDIAN
        uint64_t pull_read_underflow : 1;
        uint64_t push_write_overflow : 1;
        uint64_t pull_read_underflow_en : 1;
        uint64_t push_write_overflow_en : 1;
        uint64_t ocb_stream_mode : 1;
        uint64_t ocb_stream_type : 1;
        uint64_t spare0 : 2;
        uint64_t ocb_oci_timeout : 1;
        uint64_t ocb_oci_read_data_parity : 1;
        uint64_t ocb_oci_slave_error : 1;
        uint64_t ocb_pib_addr_parity_err : 1;
        uint64_t ocb_pib_data_parity_err : 1;
        uint64_t spare1 : 1;
        uint64_t ocb_fsm_err : 1;
        uint64_t spare2 : 1;
        uint64_t reserved1 : 48;
#else
        uint64_t reserved1 : 48;
        uint64_t spare2 : 1;
        uint64_t ocb_fsm_err : 1;
        uint64_t spare1 : 1;
        uint64_t ocb_pib_data_parity_err : 1;
        uint64_t ocb_pib_addr_parity_err : 1;
        uint64_t ocb_oci_slave_error : 1;
        uint64_t ocb_oci_read_data_parity : 1;
        uint64_t ocb_oci_timeout : 1;
        uint64_t spare0 : 2;
        uint64_t ocb_stream_type : 1;
        uint64_t ocb_stream_mode : 1;
        uint64_t push_write_overflow_en : 1;
        uint64_t pull_read_underflow_en : 1;
        uint64_t push_write_overflow : 1;
        uint64_t pull_read_underflow : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocbcsrn_or_t;



typedef union ocb_ocbesrn
{

    uint64_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct
    {
#ifdef _BIG_ENDIAN
        uint64_t ocb_error_addr : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t ocb_error_addr : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocbesrn_t;



typedef union ocb_ocbdrn
{

    uint64_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct
    {
#ifdef _BIG_ENDIAN
        uint64_t ocb_data : 64;
#else
        uint64_t ocb_data : 64;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocbdrn_t;



typedef union ocb_otdcr
{

    uint64_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct
    {
#ifdef _BIG_ENDIAN
        uint64_t trace_bus_en : 1;
        uint64_t ocb_trace_mux_sel : 1;
        uint64_t occ_trace_mux_sel : 2;
        uint64_t oci_trace_mux_sel : 4;
        uint64_t reserved1 : 56;
#else
        uint64_t reserved1 : 56;
        uint64_t oci_trace_mux_sel : 4;
        uint64_t occ_trace_mux_sel : 2;
        uint64_t ocb_trace_mux_sel : 1;
        uint64_t trace_bus_en : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_otdcr_t;



typedef union ocb_oppcinj
{

    uint64_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct
    {
#ifdef _BIG_ENDIAN
        uint64_t oci_err_inj_dcu : 1;
        uint64_t oci_err_inj_icu : 1;
        uint64_t oci_err_inj_ce_ue : 1;
        uint64_t oci_err_inj_singl_cont : 1;
        uint64_t reserved1 : 60;
#else
        uint64_t reserved1 : 60;
        uint64_t oci_err_inj_singl_cont : 1;
        uint64_t oci_err_inj_ce_ue : 1;
        uint64_t oci_err_inj_icu : 1;
        uint64_t oci_err_inj_dcu : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oppcinj_t;



typedef union ocb_ostoear
{

    uint64_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct
    {
#ifdef _BIG_ENDIAN
        uint64_t occ_spcl_timeout_addr : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t occ_spcl_timeout_addr : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ostoear_t;



typedef union ocb_ostoesr
{

    uint64_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct
    {
#ifdef _BIG_ENDIAN
        uint64_t icu_timeout_error : 1;
        uint64_t icu_rnw : 1;
        uint64_t reserved_2_31 : 2;
        uint64_t dcu_timeout_error : 1;
        uint64_t dcu_rnw : 1;
        uint64_t reserved_6_72 : 2;
        uint64_t reserved3 : 56;
#else
        uint64_t reserved3 : 56;
        uint64_t reserved_6_72 : 2;
        uint64_t dcu_rnw : 1;
        uint64_t dcu_timeout_error : 1;
        uint64_t reserved_2_31 : 2;
        uint64_t icu_rnw : 1;
        uint64_t icu_timeout_error : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ostoesr_t;



typedef union ocb_orev
{

    uint64_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct
    {
#ifdef _BIG_ENDIAN
        uint64_t oci_arb_revision : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t oci_arb_revision : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_orev_t;



typedef union ocb_oesr
{

    uint64_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct
    {
#ifdef _BIG_ENDIAN
        uint64_t oci_m0_timeout_error : 1;
        uint64_t oci_m0_rw_status : 1;
        uint64_t oci_m0_oesr_flck : 1;
        uint64_t oci_m0_oear_lock : 1;
        uint64_t oci_m1_timeout_error : 1;
        uint64_t oci_m1_rw_status : 1;
        uint64_t oci_m1_oesr_flck : 1;
        uint64_t oci_m1_oear_lock : 1;
        uint64_t oci_m2_timeout_error : 1;
        uint64_t oci_m2_rw_status : 1;
        uint64_t oci_m2_oesr_flck : 1;
        uint64_t oci_m2_oear_lock : 1;
        uint64_t oci_m3_timeout_error : 1;
        uint64_t oci_m3_rw_status : 1;
        uint64_t oci_m3_oesr_flck : 1;
        uint64_t oci_m3_oear_lock : 1;
        uint64_t oci_m4_timeout_error : 1;
        uint64_t oci_m4_rw_status : 1;
        uint64_t oci_m4_oesr_flck : 1;
        uint64_t oci_m4_oear_lock : 1;
        uint64_t oci_m5_timeout_error : 1;
        uint64_t oci_m5_rw_status : 1;
        uint64_t oci_m5_oesr_flck : 1;
        uint64_t oci_m5_oear_lock : 1;
        uint64_t oci_m6_timeout_error : 1;
        uint64_t oci_m6_rw_status : 1;
        uint64_t oci_m6_oesr_flck : 1;
        uint64_t oci_m6_oear_lock : 1;
        uint64_t oci_m7_timeout_error : 1;
        uint64_t oci_m7_rw_status : 1;
        uint64_t oci_m7_oesr_flck : 1;
        uint64_t oci_m7_oear_lock : 1;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t oci_m7_oear_lock : 1;
        uint64_t oci_m7_oesr_flck : 1;
        uint64_t oci_m7_rw_status : 1;
        uint64_t oci_m7_timeout_error : 1;
        uint64_t oci_m6_oear_lock : 1;
        uint64_t oci_m6_oesr_flck : 1;
        uint64_t oci_m6_rw_status : 1;
        uint64_t oci_m6_timeout_error : 1;
        uint64_t oci_m5_oear_lock : 1;
        uint64_t oci_m5_oesr_flck : 1;
        uint64_t oci_m5_rw_status : 1;
        uint64_t oci_m5_timeout_error : 1;
        uint64_t oci_m4_oear_lock : 1;
        uint64_t oci_m4_oesr_flck : 1;
        uint64_t oci_m4_rw_status : 1;
        uint64_t oci_m4_timeout_error : 1;
        uint64_t oci_m3_oear_lock : 1;
        uint64_t oci_m3_oesr_flck : 1;
        uint64_t oci_m3_rw_status : 1;
        uint64_t oci_m3_timeout_error : 1;
        uint64_t oci_m2_oear_lock : 1;
        uint64_t oci_m2_oesr_flck : 1;
        uint64_t oci_m2_rw_status : 1;
        uint64_t oci_m2_timeout_error : 1;
        uint64_t oci_m1_oear_lock : 1;
        uint64_t oci_m1_oesr_flck : 1;
        uint64_t oci_m1_rw_status : 1;
        uint64_t oci_m1_timeout_error : 1;
        uint64_t oci_m0_oear_lock : 1;
        uint64_t oci_m0_oesr_flck : 1;
        uint64_t oci_m0_rw_status : 1;
        uint64_t oci_m0_timeout_error : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oesr_t;



typedef union ocb_oear
{

    uint64_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct
    {
#ifdef _BIG_ENDIAN
        uint64_t oci_timeout_addr : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t oci_timeout_addr : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oear_t;



typedef union ocb_oacr
{

    uint64_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct
    {
#ifdef _BIG_ENDIAN
        uint64_t oci_priority_mode : 1;
        uint64_t oci_priority_order : 3;
        uint64_t oci_hi_bus_mode : 1;
        uint64_t oci_read_pipeline_control : 2;
        uint64_t oci_write_pipeline_control : 1;
        uint64_t reserved1 : 56;
#else
        uint64_t reserved1 : 56;
        uint64_t oci_write_pipeline_control : 1;
        uint64_t oci_read_pipeline_control : 2;
        uint64_t oci_hi_bus_mode : 1;
        uint64_t oci_priority_order : 3;
        uint64_t oci_priority_mode : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oacr_t;



typedef union ocb_ocbear
{

    uint64_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct
    {
#ifdef _BIG_ENDIAN
        uint64_t ocb_error_address : 32;
        uint64_t reserved_32_341 : 3;
        uint64_t direct_bridge_source : 1;
        uint64_t indirect_bridge_0_source : 1;
        uint64_t indirect_bridge_1_source : 1;
        uint64_t indirect_bridge_2_source : 1;
        uint64_t indirect_bridge_3_source : 1;
        uint64_t reserved2 : 24;
#else
        uint64_t reserved2 : 24;
        uint64_t indirect_bridge_3_source : 1;
        uint64_t indirect_bridge_2_source : 1;
        uint64_t indirect_bridge_1_source : 1;
        uint64_t indirect_bridge_0_source : 1;
        uint64_t direct_bridge_source : 1;
        uint64_t reserved_32_341 : 3;
        uint64_t ocb_error_address : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocbear_t;


#endif // __ASSEMBLER__
#endif // __OCB_FIRMWARE_REGISTERS_H__
