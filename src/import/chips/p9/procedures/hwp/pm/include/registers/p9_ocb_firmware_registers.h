/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/include/registers/p9_ocb_firmware_registers.h $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef P9_OCB_FIRMWARE_REGISTERS_H__
#define P9_OCB_FIRMWARE_REGISTERS_H__

// $Id$
// $Source$
//-----------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2015
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
        uint64_t debugger : 1;
        uint64_t trace_trigger : 1;
        uint64_t occ_error : 1;
        uint64_t pba_error : 1;
        uint64_t srt_error : 1;
        uint64_t gpe0_error : 1;
        uint64_t gpe1_error : 1;
        uint64_t gpe2_error : 1;
        uint64_t gpe3_error : 1;
        uint64_t ppc405_halt : 1;
        uint64_t ocb_error : 1;
        uint64_t spipss_error : 1;
        uint64_t check_stop_ppc405 : 1;
        uint64_t check_stop_gpe0 : 1;
        uint64_t check_stop_gpe1 : 1;
        uint64_t check_stop_gpe2 : 1;
        uint64_t check_stop_gpe3 : 1;
        uint64_t occ_malf_alert : 1;
        uint64_t adu_malf_alert : 1;
        uint64_t external_trap : 1;
        uint64_t ivrm_pvref_error : 1;
        uint64_t occ_timer0 : 1;
        uint64_t occ_timer1 : 1;
        uint64_t avs_slave0 : 1;
        uint64_t avs_slave1 : 1;
        uint64_t ipi0_hi_priority : 1;
        uint64_t ipi1_hi_priority : 1;
        uint64_t ipi2_hi_priority : 1;
        uint64_t ipi3_hi_priority : 1;
        uint64_t ipi4_hi_priority : 1;
        uint64_t adcfsm_ongoing : 1;
        uint64_t spare_31 : 1;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t spare_31 : 1;
        uint64_t adcfsm_ongoing : 1;
        uint64_t ipi4_hi_priority : 1;
        uint64_t ipi3_hi_priority : 1;
        uint64_t ipi2_hi_priority : 1;
        uint64_t ipi1_hi_priority : 1;
        uint64_t ipi0_hi_priority : 1;
        uint64_t avs_slave1 : 1;
        uint64_t avs_slave0 : 1;
        uint64_t occ_timer1 : 1;
        uint64_t occ_timer0 : 1;
        uint64_t ivrm_pvref_error : 1;
        uint64_t external_trap : 1;
        uint64_t adu_malf_alert : 1;
        uint64_t occ_malf_alert : 1;
        uint64_t check_stop_gpe3 : 1;
        uint64_t check_stop_gpe2 : 1;
        uint64_t check_stop_gpe1 : 1;
        uint64_t check_stop_gpe0 : 1;
        uint64_t check_stop_ppc405 : 1;
        uint64_t spipss_error : 1;
        uint64_t ocb_error : 1;
        uint64_t ppc405_halt : 1;
        uint64_t gpe3_error : 1;
        uint64_t gpe2_error : 1;
        uint64_t gpe1_error : 1;
        uint64_t gpe0_error : 1;
        uint64_t srt_error : 1;
        uint64_t pba_error : 1;
        uint64_t occ_error : 1;
        uint64_t trace_trigger : 1;
        uint64_t debugger : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oisr0_t;



typedef union ocb_oisr0_clr
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
        uint64_t debugger : 1;
        uint64_t trace_trigger : 1;
        uint64_t occ_error : 1;
        uint64_t pba_error : 1;
        uint64_t srt_error : 1;
        uint64_t gpe0_error : 1;
        uint64_t gpe1_error : 1;
        uint64_t gpe2_error : 1;
        uint64_t gpe3_error : 1;
        uint64_t ppc405_halt : 1;
        uint64_t ocb_error : 1;
        uint64_t spipss_error : 1;
        uint64_t check_stop_ppc405 : 1;
        uint64_t check_stop_gpe0 : 1;
        uint64_t check_stop_gpe1 : 1;
        uint64_t check_stop_gpe2 : 1;
        uint64_t check_stop_gpe3 : 1;
        uint64_t occ_malf_alert : 1;
        uint64_t adu_malf_alert : 1;
        uint64_t external_trap : 1;
        uint64_t ivrm_pvref_error : 1;
        uint64_t occ_timer0 : 1;
        uint64_t occ_timer1 : 1;
        uint64_t avs_slave0 : 1;
        uint64_t avs_slave1 : 1;
        uint64_t ipi0_hi_priority : 1;
        uint64_t ipi1_hi_priority : 1;
        uint64_t ipi2_hi_priority : 1;
        uint64_t ipi3_hi_priority : 1;
        uint64_t ipi4_hi_priority : 1;
        uint64_t adcfsm_ongoing : 1;
        uint64_t spare_31 : 1;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t spare_31 : 1;
        uint64_t adcfsm_ongoing : 1;
        uint64_t ipi4_hi_priority : 1;
        uint64_t ipi3_hi_priority : 1;
        uint64_t ipi2_hi_priority : 1;
        uint64_t ipi1_hi_priority : 1;
        uint64_t ipi0_hi_priority : 1;
        uint64_t avs_slave1 : 1;
        uint64_t avs_slave0 : 1;
        uint64_t occ_timer1 : 1;
        uint64_t occ_timer0 : 1;
        uint64_t ivrm_pvref_error : 1;
        uint64_t external_trap : 1;
        uint64_t adu_malf_alert : 1;
        uint64_t occ_malf_alert : 1;
        uint64_t check_stop_gpe3 : 1;
        uint64_t check_stop_gpe2 : 1;
        uint64_t check_stop_gpe1 : 1;
        uint64_t check_stop_gpe0 : 1;
        uint64_t check_stop_ppc405 : 1;
        uint64_t spipss_error : 1;
        uint64_t ocb_error : 1;
        uint64_t ppc405_halt : 1;
        uint64_t gpe3_error : 1;
        uint64_t gpe2_error : 1;
        uint64_t gpe1_error : 1;
        uint64_t gpe0_error : 1;
        uint64_t srt_error : 1;
        uint64_t pba_error : 1;
        uint64_t occ_error : 1;
        uint64_t trace_trigger : 1;
        uint64_t debugger : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oisr0_clr_t;



typedef union ocb_oisr0_or
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
        uint64_t debugger : 1;
        uint64_t trace_trigger : 1;
        uint64_t occ_error : 1;
        uint64_t pba_error : 1;
        uint64_t srt_error : 1;
        uint64_t gpe0_error : 1;
        uint64_t gpe1_error : 1;
        uint64_t gpe2_error : 1;
        uint64_t gpe3_error : 1;
        uint64_t ppc405_halt : 1;
        uint64_t ocb_error : 1;
        uint64_t spipss_error : 1;
        uint64_t check_stop_ppc405 : 1;
        uint64_t check_stop_gpe0 : 1;
        uint64_t check_stop_gpe1 : 1;
        uint64_t check_stop_gpe2 : 1;
        uint64_t check_stop_gpe3 : 1;
        uint64_t occ_malf_alert : 1;
        uint64_t adu_malf_alert : 1;
        uint64_t external_trap : 1;
        uint64_t ivrm_pvref_error : 1;
        uint64_t occ_timer0 : 1;
        uint64_t occ_timer1 : 1;
        uint64_t avs_slave0 : 1;
        uint64_t avs_slave1 : 1;
        uint64_t ipi0_hi_priority : 1;
        uint64_t ipi1_hi_priority : 1;
        uint64_t ipi2_hi_priority : 1;
        uint64_t ipi3_hi_priority : 1;
        uint64_t ipi4_hi_priority : 1;
        uint64_t adcfsm_ongoing : 1;
        uint64_t spare_31 : 1;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t spare_31 : 1;
        uint64_t adcfsm_ongoing : 1;
        uint64_t ipi4_hi_priority : 1;
        uint64_t ipi3_hi_priority : 1;
        uint64_t ipi2_hi_priority : 1;
        uint64_t ipi1_hi_priority : 1;
        uint64_t ipi0_hi_priority : 1;
        uint64_t avs_slave1 : 1;
        uint64_t avs_slave0 : 1;
        uint64_t occ_timer1 : 1;
        uint64_t occ_timer0 : 1;
        uint64_t ivrm_pvref_error : 1;
        uint64_t external_trap : 1;
        uint64_t adu_malf_alert : 1;
        uint64_t occ_malf_alert : 1;
        uint64_t check_stop_gpe3 : 1;
        uint64_t check_stop_gpe2 : 1;
        uint64_t check_stop_gpe1 : 1;
        uint64_t check_stop_gpe0 : 1;
        uint64_t check_stop_ppc405 : 1;
        uint64_t spipss_error : 1;
        uint64_t ocb_error : 1;
        uint64_t ppc405_halt : 1;
        uint64_t gpe3_error : 1;
        uint64_t gpe2_error : 1;
        uint64_t gpe1_error : 1;
        uint64_t gpe0_error : 1;
        uint64_t srt_error : 1;
        uint64_t pba_error : 1;
        uint64_t occ_error : 1;
        uint64_t trace_trigger : 1;
        uint64_t debugger : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oisr0_or_t;



typedef union ocb_oimr0
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
        uint64_t interrupt_mask_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_mask_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oimr0_t;



typedef union ocb_oimr0_clr
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
        uint64_t interrupt_mask_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_mask_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oimr0_clr_t;



typedef union ocb_oimr0_or
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
        uint64_t interrupt_mask_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_mask_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oimr0_or_t;



typedef union ocb_oitr0
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
        uint64_t interrupt_type_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_type_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oitr0_t;



typedef union ocb_oitr0_clr
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
        uint64_t interrupt_type_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_type_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oitr0_clr_t;



typedef union ocb_oitr0_or
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
        uint64_t interrupt_type_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_type_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oitr0_or_t;



typedef union ocb_oiepr0
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
        uint64_t interrupt_edge_pol_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_edge_pol_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oiepr0_t;



typedef union ocb_oiepr0_clr
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
        uint64_t interrupt_edge_pol_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_edge_pol_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oiepr0_clr_t;



typedef union ocb_oiepr0_or
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
        uint64_t interrupt_edge_pol_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_edge_pol_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oiepr0_or_t;



typedef union ocb_oisr1
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
        uint64_t pbax_occ_send : 1;
        uint64_t pbax_occ_push0 : 1;
        uint64_t pbax_occ_push1 : 1;
        uint64_t pba_bcde_attn : 1;
        uint64_t pba_bcue_attn : 1;
        uint64_t occ_strm0_pull : 1;
        uint64_t occ_strm0_push : 1;
        uint64_t occ_strm1_pull : 1;
        uint64_t occ_strm1_push : 1;
        uint64_t occ_strm2_pull : 1;
        uint64_t occ_strm2_push : 1;
        uint64_t occ_strm3_pull : 1;
        uint64_t occ_strm3_push : 1;
        uint64_t pmc_pcb_intr_type0_pending : 1;
        uint64_t pmc_pcb_intr_type1_pending : 1;
        uint64_t pmc_pcb_intr_type2_pending : 1;
        uint64_t pmc_pcb_intr_type3_pending : 1;
        uint64_t pmc_pcb_intr_type4_pending : 1;
        uint64_t pmc_pcb_intr_type5_pending : 1;
        uint64_t pmc_pcb_intr_type6_pending : 1;
        uint64_t pmc_pcb_intr_type7_pending : 1;
        uint64_t pmc_o2s_0a_ongoing : 1;
        uint64_t pmc_o2s_0b_ongoing : 1;
        uint64_t pmc_o2s_1a_ongoing : 1;
        uint64_t pmc_o2s_1b_ongoing : 1;
        uint64_t pssbridge_ongoing : 1;
        uint64_t ipi0_lo_priority : 1;
        uint64_t ipi1_lo_priority : 1;
        uint64_t ipi2_lo_priority : 1;
        uint64_t ipi3_lo_priority : 1;
        uint64_t ipi4_lo_priority : 1;
        uint64_t spare_31 : 1;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t spare_31 : 1;
        uint64_t ipi4_lo_priority : 1;
        uint64_t ipi3_lo_priority : 1;
        uint64_t ipi2_lo_priority : 1;
        uint64_t ipi1_lo_priority : 1;
        uint64_t ipi0_lo_priority : 1;
        uint64_t pssbridge_ongoing : 1;
        uint64_t pmc_o2s_1b_ongoing : 1;
        uint64_t pmc_o2s_1a_ongoing : 1;
        uint64_t pmc_o2s_0b_ongoing : 1;
        uint64_t pmc_o2s_0a_ongoing : 1;
        uint64_t pmc_pcb_intr_type7_pending : 1;
        uint64_t pmc_pcb_intr_type6_pending : 1;
        uint64_t pmc_pcb_intr_type5_pending : 1;
        uint64_t pmc_pcb_intr_type4_pending : 1;
        uint64_t pmc_pcb_intr_type3_pending : 1;
        uint64_t pmc_pcb_intr_type2_pending : 1;
        uint64_t pmc_pcb_intr_type1_pending : 1;
        uint64_t pmc_pcb_intr_type0_pending : 1;
        uint64_t occ_strm3_push : 1;
        uint64_t occ_strm3_pull : 1;
        uint64_t occ_strm2_push : 1;
        uint64_t occ_strm2_pull : 1;
        uint64_t occ_strm1_push : 1;
        uint64_t occ_strm1_pull : 1;
        uint64_t occ_strm0_push : 1;
        uint64_t occ_strm0_pull : 1;
        uint64_t pba_bcue_attn : 1;
        uint64_t pba_bcde_attn : 1;
        uint64_t pbax_occ_push1 : 1;
        uint64_t pbax_occ_push0 : 1;
        uint64_t pbax_occ_send : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oisr1_t;



typedef union ocb_oisr1_clr
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
        uint64_t pbax_occ_send : 1;
        uint64_t pbax_occ_push0 : 1;
        uint64_t pbax_occ_push1 : 1;
        uint64_t pba_bcde_attn : 1;
        uint64_t pba_bcue_attn : 1;
        uint64_t occ_strm0_pull : 1;
        uint64_t occ_strm0_push : 1;
        uint64_t occ_strm1_pull : 1;
        uint64_t occ_strm1_push : 1;
        uint64_t occ_strm2_pull : 1;
        uint64_t occ_strm2_push : 1;
        uint64_t occ_strm3_pull : 1;
        uint64_t occ_strm3_push : 1;
        uint64_t pmc_pcb_intr_type0_pending : 1;
        uint64_t pmc_pcb_intr_type1_pending : 1;
        uint64_t pmc_pcb_intr_type2_pending : 1;
        uint64_t pmc_pcb_intr_type3_pending : 1;
        uint64_t pmc_pcb_intr_type4_pending : 1;
        uint64_t pmc_pcb_intr_type5_pending : 1;
        uint64_t pmc_pcb_intr_type6_pending : 1;
        uint64_t pmc_pcb_intr_type7_pending : 1;
        uint64_t pmc_o2s_0a_ongoing : 1;
        uint64_t pmc_o2s_0b_ongoing : 1;
        uint64_t pmc_o2s_1a_ongoing : 1;
        uint64_t pmc_o2s_1b_ongoing : 1;
        uint64_t pssbridge_ongoing : 1;
        uint64_t ipi0_lo_priority : 1;
        uint64_t ipi1_lo_priority : 1;
        uint64_t ipi2_lo_priority : 1;
        uint64_t ipi3_lo_priority : 1;
        uint64_t ipi4_lo_priority : 1;
        uint64_t spare_31 : 1;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t spare_31 : 1;
        uint64_t ipi4_lo_priority : 1;
        uint64_t ipi3_lo_priority : 1;
        uint64_t ipi2_lo_priority : 1;
        uint64_t ipi1_lo_priority : 1;
        uint64_t ipi0_lo_priority : 1;
        uint64_t pssbridge_ongoing : 1;
        uint64_t pmc_o2s_1b_ongoing : 1;
        uint64_t pmc_o2s_1a_ongoing : 1;
        uint64_t pmc_o2s_0b_ongoing : 1;
        uint64_t pmc_o2s_0a_ongoing : 1;
        uint64_t pmc_pcb_intr_type7_pending : 1;
        uint64_t pmc_pcb_intr_type6_pending : 1;
        uint64_t pmc_pcb_intr_type5_pending : 1;
        uint64_t pmc_pcb_intr_type4_pending : 1;
        uint64_t pmc_pcb_intr_type3_pending : 1;
        uint64_t pmc_pcb_intr_type2_pending : 1;
        uint64_t pmc_pcb_intr_type1_pending : 1;
        uint64_t pmc_pcb_intr_type0_pending : 1;
        uint64_t occ_strm3_push : 1;
        uint64_t occ_strm3_pull : 1;
        uint64_t occ_strm2_push : 1;
        uint64_t occ_strm2_pull : 1;
        uint64_t occ_strm1_push : 1;
        uint64_t occ_strm1_pull : 1;
        uint64_t occ_strm0_push : 1;
        uint64_t occ_strm0_pull : 1;
        uint64_t pba_bcue_attn : 1;
        uint64_t pba_bcde_attn : 1;
        uint64_t pbax_occ_push1 : 1;
        uint64_t pbax_occ_push0 : 1;
        uint64_t pbax_occ_send : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oisr1_clr_t;



typedef union ocb_oisr1_or
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
        uint64_t pbax_occ_send : 1;
        uint64_t pbax_occ_push0 : 1;
        uint64_t pbax_occ_push1 : 1;
        uint64_t pba_bcde_attn : 1;
        uint64_t pba_bcue_attn : 1;
        uint64_t occ_strm0_pull : 1;
        uint64_t occ_strm0_push : 1;
        uint64_t occ_strm1_pull : 1;
        uint64_t occ_strm1_push : 1;
        uint64_t occ_strm2_pull : 1;
        uint64_t occ_strm2_push : 1;
        uint64_t occ_strm3_pull : 1;
        uint64_t occ_strm3_push : 1;
        uint64_t pmc_pcb_intr_type0_pending : 1;
        uint64_t pmc_pcb_intr_type1_pending : 1;
        uint64_t pmc_pcb_intr_type2_pending : 1;
        uint64_t pmc_pcb_intr_type3_pending : 1;
        uint64_t pmc_pcb_intr_type4_pending : 1;
        uint64_t pmc_pcb_intr_type5_pending : 1;
        uint64_t pmc_pcb_intr_type6_pending : 1;
        uint64_t pmc_pcb_intr_type7_pending : 1;
        uint64_t pmc_o2s_0a_ongoing : 1;
        uint64_t pmc_o2s_0b_ongoing : 1;
        uint64_t pmc_o2s_1a_ongoing : 1;
        uint64_t pmc_o2s_1b_ongoing : 1;
        uint64_t pssbridge_ongoing : 1;
        uint64_t ipi0_lo_priority : 1;
        uint64_t ipi1_lo_priority : 1;
        uint64_t ipi2_lo_priority : 1;
        uint64_t ipi3_lo_priority : 1;
        uint64_t ipi4_lo_priority : 1;
        uint64_t spare_31 : 1;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t spare_31 : 1;
        uint64_t ipi4_lo_priority : 1;
        uint64_t ipi3_lo_priority : 1;
        uint64_t ipi2_lo_priority : 1;
        uint64_t ipi1_lo_priority : 1;
        uint64_t ipi0_lo_priority : 1;
        uint64_t pssbridge_ongoing : 1;
        uint64_t pmc_o2s_1b_ongoing : 1;
        uint64_t pmc_o2s_1a_ongoing : 1;
        uint64_t pmc_o2s_0b_ongoing : 1;
        uint64_t pmc_o2s_0a_ongoing : 1;
        uint64_t pmc_pcb_intr_type7_pending : 1;
        uint64_t pmc_pcb_intr_type6_pending : 1;
        uint64_t pmc_pcb_intr_type5_pending : 1;
        uint64_t pmc_pcb_intr_type4_pending : 1;
        uint64_t pmc_pcb_intr_type3_pending : 1;
        uint64_t pmc_pcb_intr_type2_pending : 1;
        uint64_t pmc_pcb_intr_type1_pending : 1;
        uint64_t pmc_pcb_intr_type0_pending : 1;
        uint64_t occ_strm3_push : 1;
        uint64_t occ_strm3_pull : 1;
        uint64_t occ_strm2_push : 1;
        uint64_t occ_strm2_pull : 1;
        uint64_t occ_strm1_push : 1;
        uint64_t occ_strm1_pull : 1;
        uint64_t occ_strm0_push : 1;
        uint64_t occ_strm0_pull : 1;
        uint64_t pba_bcue_attn : 1;
        uint64_t pba_bcde_attn : 1;
        uint64_t pbax_occ_push1 : 1;
        uint64_t pbax_occ_push0 : 1;
        uint64_t pbax_occ_send : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oisr1_or_t;



typedef union ocb_oimr1
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
        uint64_t interrupt_mask_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_mask_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oimr1_t;



typedef union ocb_oimr1_clr
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
        uint64_t interrupt_mask_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_mask_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oimr1_clr_t;



typedef union ocb_oimr1_or
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
        uint64_t interrupt_mask_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_mask_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oimr1_or_t;



typedef union ocb_oitr1
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
        uint64_t interrupt_type_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_type_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oitr1_t;



typedef union ocb_oitr1_clr
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
        uint64_t interrupt_type_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_type_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oitr1_clr_t;



typedef union ocb_oitr1_or
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
        uint64_t interrupt_type_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_type_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oitr1_or_t;



typedef union ocb_oiepr1
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
        uint64_t interrupt_edge_pol_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_edge_pol_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oiepr1_t;



typedef union ocb_oiepr1_clr
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
        uint64_t interrupt_edge_pol_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_edge_pol_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oiepr1_clr_t;



typedef union ocb_oiepr1_or
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
        uint64_t interrupt_edge_pol_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_edge_pol_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oiepr1_or_t;



typedef union ocb_oirr0a
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
        uint64_t interrupt_route_a_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr0a_t;



typedef union ocb_oirr0a_clr
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
        uint64_t interrupt_route_a_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr0a_clr_t;



typedef union ocb_oirr0a_or
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
        uint64_t interrupt_route_a_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr0a_or_t;



typedef union ocb_oirr0b
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
        uint64_t interrupt_route_a_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr0b_t;



typedef union ocb_oirr0b_clr
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
        uint64_t interrupt_route_a_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr0b_clr_t;



typedef union ocb_oirr0b_or
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
        uint64_t interrupt_route_a_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr0b_or_t;



typedef union ocb_oirr0c
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
        uint64_t interrupt_route_a_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr0c_t;



typedef union ocb_oirr0c_clr
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
        uint64_t interrupt_route_a_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr0c_clr_t;



typedef union ocb_oirr0c_or
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
        uint64_t interrupt_route_a_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr0c_or_t;



typedef union ocb_oirr1a
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
        uint64_t interrupt_route_a_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr1a_t;



typedef union ocb_oirr1a_clr
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
        uint64_t interrupt_route_a_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr1a_clr_t;



typedef union ocb_oirr1a_or
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
        uint64_t interrupt_route_a_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr1a_or_t;



typedef union ocb_oirr1b
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
        uint64_t interrupt_route_a_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr1b_t;



typedef union ocb_oirr1b_clr
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
        uint64_t interrupt_route_a_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr1b_clr_t;



typedef union ocb_oirr1b_or
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
        uint64_t interrupt_route_a_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr1b_or_t;



typedef union ocb_oirr1c
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
        uint64_t interrupt_route_a_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr1c_t;



typedef union ocb_oirr1c_clr
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
        uint64_t interrupt_route_a_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr1c_clr_t;



typedef union ocb_oirr1c_or
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
        uint64_t interrupt_route_a_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_route_a_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oirr1c_or_t;



typedef union ocb_onisr0
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
        uint64_t interrupt_noncrit_status_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_noncrit_status_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_onisr0_t;



typedef union ocb_ocisr0
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
        uint64_t interrupt_crit_status_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_crit_status_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocisr0_t;



typedef union ocb_ouisr0
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
        uint64_t interrupt_uncon_status_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_uncon_status_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ouisr0_t;



typedef union ocb_odisr0
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
        uint64_t interrupt_debug_status_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_debug_status_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_odisr0_t;



typedef union ocb_g0isr0
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
        uint64_t interrupt_gpe0_status_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_gpe0_status_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_g0isr0_t;



typedef union ocb_g1isr0
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
        uint64_t interrupt_gpe1_status_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_gpe1_status_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_g1isr0_t;



typedef union ocb_g2isr0
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
        uint64_t interrupt_gpe2_status_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_gpe2_status_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_g2isr0_t;



typedef union ocb_g3isr0
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
        uint64_t interrupt_gpe3_status_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_gpe3_status_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_g3isr0_t;



typedef union ocb_onisr1
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
        uint64_t interrupt_noncrit_status_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_noncrit_status_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_onisr1_t;



typedef union ocb_ocisr1
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
        uint64_t interrupt_crit_status_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_crit_status_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocisr1_t;



typedef union ocb_ouisr1
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
        uint64_t interrupt_uncon_status_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_uncon_status_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ouisr1_t;



typedef union ocb_odisr1
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
        uint64_t interrupt_debug_status_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_debug_status_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_odisr1_t;



typedef union ocb_g0isr1
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
        uint64_t interrupt_gpe0_status_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_gpe0_status_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_g0isr1_t;



typedef union ocb_g1isr1
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
        uint64_t interrupt_gpe1_status_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_gpe1_status_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_g1isr1_t;



typedef union ocb_g2isr1
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
        uint64_t interrupt_gpe2_status_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_gpe2_status_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_g2isr1_t;



typedef union ocb_g3isr1
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
        uint64_t interrupt_gpe3_status_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t interrupt_gpe3_status_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_g3isr1_t;



typedef union ocb_occmisc
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
        uint64_t core_ext_intr : 1;
        uint64_t spare : 15;
        uint64_t reserved1 : 48;
#else
        uint64_t reserved1 : 48;
        uint64_t spare : 15;
        uint64_t core_ext_intr : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_occmisc_t;



typedef union ocb_occmisc_clr
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
        uint64_t core_ext_intr : 1;
        uint64_t spare : 15;
        uint64_t reserved1 : 48;
#else
        uint64_t reserved1 : 48;
        uint64_t spare : 15;
        uint64_t core_ext_intr : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_occmisc_clr_t;



typedef union ocb_occmisc_or
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
        uint64_t core_ext_intr : 1;
        uint64_t spare : 15;
        uint64_t reserved1 : 48;
#else
        uint64_t reserved1 : 48;
        uint64_t spare : 15;
        uint64_t core_ext_intr : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_occmisc_or_t;



typedef union ocb_ohtmcr
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
        uint64_t htm_src_sel : 2;
        uint64_t htm_stop : 1;
        uint64_t htm_marker_slave_adrs : 3;
        uint64_t event2halt_mode : 2;
        uint64_t event2halt_en : 11;
        uint64_t reserved1 : 4;
        uint64_t event2halt_occ : 1;
        uint64_t event2halt_gpe0 : 1;
        uint64_t event2halt_gpe1 : 1;
        uint64_t event2halt_gpe2 : 1;
        uint64_t event2halt_gpe3 : 1;
        uint64_t reserved2 : 3;
        uint64_t event2halt_halt_state : 1;
        uint64_t reserved3 : 32;
#else
        uint64_t reserved3 : 32;
        uint64_t event2halt_halt_state : 1;
        uint64_t reserved2 : 3;
        uint64_t event2halt_gpe3 : 1;
        uint64_t event2halt_gpe2 : 1;
        uint64_t event2halt_gpe1 : 1;
        uint64_t event2halt_gpe0 : 1;
        uint64_t event2halt_occ : 1;
        uint64_t reserved1 : 4;
        uint64_t event2halt_en : 11;
        uint64_t event2halt_mode : 2;
        uint64_t htm_marker_slave_adrs : 3;
        uint64_t htm_stop : 1;
        uint64_t htm_src_sel : 2;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ohtmcr_t;



typedef union ocb_oehdr
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
        uint64_t event2halt_delay : 20;
        uint64_t reserved1 : 44;
#else
        uint64_t reserved1 : 44;
        uint64_t event2halt_delay : 20;
#endif // _BIG_ENDIAN
    } fields;
} ocb_oehdr_t;



typedef union ocb_ocicfg
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
        uint64_t m0_priority : 2;
        uint64_t m1_priority : 2;
        uint64_t m2_priority : 2;
        uint64_t m3_priority : 2;
        uint64_t m4_priority : 2;
        uint64_t m5_priority : 2;
        uint64_t m6_priority : 2;
        uint64_t m7_priority : 2;
        uint64_t m0_priority_sel : 1;
        uint64_t m1_priority_sel : 1;
        uint64_t m2_priority_sel : 1;
        uint64_t m3_priority_sel : 1;
        uint64_t ocicfg_reserved_20 : 1;
        uint64_t m5_priority_sel : 1;
        uint64_t ocicfg_reserved_23 : 1;
        uint64_t m7_priority_sel : 1;
        uint64_t plbarb_lockerr : 1;
        uint64_t spare_24_31 : 7;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t spare_24_31 : 7;
        uint64_t plbarb_lockerr : 1;
        uint64_t m7_priority_sel : 1;
        uint64_t ocicfg_reserved_23 : 1;
        uint64_t m5_priority_sel : 1;
        uint64_t ocicfg_reserved_20 : 1;
        uint64_t m3_priority_sel : 1;
        uint64_t m2_priority_sel : 1;
        uint64_t m1_priority_sel : 1;
        uint64_t m0_priority_sel : 1;
        uint64_t m7_priority : 2;
        uint64_t m6_priority : 2;
        uint64_t m5_priority : 2;
        uint64_t m4_priority : 2;
        uint64_t m3_priority : 2;
        uint64_t m2_priority : 2;
        uint64_t m1_priority : 2;
        uint64_t m0_priority : 2;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocicfg_t;



typedef union ocb_occs0
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
        uint64_t occ_scratch_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t occ_scratch_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_occs0_t;



typedef union ocb_occs1
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
        uint64_t occ_scratch_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t occ_scratch_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_occs1_t;



typedef union ocb_occs2
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
        uint64_t occ_scratch_n : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t occ_scratch_n : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_occs2_t;



typedef union ocb_occflg
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
        uint64_t occ_flags : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t occ_flags : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_occflg_t;



typedef union ocb_occflg_clr
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
        uint64_t occ_flags : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t occ_flags : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_occflg_clr_t;



typedef union ocb_occflg_or
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
        uint64_t occ_flags : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t occ_flags : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_occflg_or_t;



typedef union ocb_occhbr
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
        uint64_t occ_heartbeat_count : 16;
        uint64_t occ_heartbeat_en : 1;
        uint64_t reserved1 : 47;
#else
        uint64_t reserved1 : 47;
        uint64_t occ_heartbeat_en : 1;
        uint64_t occ_heartbeat_count : 16;
#endif // _BIG_ENDIAN
    } fields;
} ocb_occhbr_t;



typedef union ocb_ccsr
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
        uint64_t core_config : 24;
        uint64_t reserved1 : 40;
#else
        uint64_t reserved1 : 40;
        uint64_t core_config : 24;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ccsr_t;



typedef union ocb_ccsr_clr
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
        uint64_t core_config : 24;
        uint64_t reserved1 : 40;
#else
        uint64_t reserved1 : 40;
        uint64_t core_config : 24;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ccsr_clr_t;



typedef union ocb_ccsr_or
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
        uint64_t core_config : 24;
        uint64_t reserved1 : 40;
#else
        uint64_t reserved1 : 40;
        uint64_t core_config : 24;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ccsr_or_t;



typedef union ocb_qcsr
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
        uint64_t reserved1 : 12;
        uint64_t l3_config : 12;
        uint64_t reserved2 : 39;
        uint64_t change_in_progress : 1;
#else
        uint64_t change_in_progress : 1;
        uint64_t reserved2 : 39;
        uint64_t l3_config : 12;
        uint64_t reserved1 : 12;
#endif // _BIG_ENDIAN
    } fields;
} ocb_qcsr_t;



typedef union ocb_qcsr_clr
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
        uint64_t reserved1 : 12;
        uint64_t l3_config : 12;
        uint64_t reserved2 : 39;
        uint64_t change_in_progress : 1;
#else
        uint64_t change_in_progress : 1;
        uint64_t reserved2 : 39;
        uint64_t l3_config : 12;
        uint64_t reserved1 : 12;
#endif // _BIG_ENDIAN
    } fields;
} ocb_qcsr_clr_t;



typedef union ocb_qcsr_or
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
        uint64_t reserved1 : 12;
        uint64_t l3_config : 12;
        uint64_t reserved2 : 39;
        uint64_t change_in_progress : 1;
#else
        uint64_t change_in_progress : 1;
        uint64_t reserved2 : 39;
        uint64_t l3_config : 12;
        uint64_t reserved1 : 12;
#endif // _BIG_ENDIAN
    } fields;
} ocb_qcsr_or_t;



typedef union ocb_qssr
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
        uint64_t l2_stopped : 12;
        uint64_t l3_stopped : 12;
        uint64_t quad_stopped : 6;
        uint64_t reserved1 : 1;
        uint64_t stop_in_progress : 1;
        uint64_t reserved2 : 32;
#else
        uint64_t reserved2 : 32;
        uint64_t stop_in_progress : 1;
        uint64_t reserved1 : 1;
        uint64_t quad_stopped : 6;
        uint64_t l3_stopped : 12;
        uint64_t l2_stopped : 12;
#endif // _BIG_ENDIAN
    } fields;
} ocb_qssr_t;



typedef union ocb_qssr_clr
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
        uint64_t l2_stopped : 12;
        uint64_t l3_stopped : 12;
        uint64_t quad_stopped : 6;
        uint64_t reserved1 : 1;
        uint64_t stop_in_progress : 1;
        uint64_t reserved2 : 32;
#else
        uint64_t reserved2 : 32;
        uint64_t stop_in_progress : 1;
        uint64_t reserved1 : 1;
        uint64_t quad_stopped : 6;
        uint64_t l3_stopped : 12;
        uint64_t l2_stopped : 12;
#endif // _BIG_ENDIAN
    } fields;
} ocb_qssr_clr_t;



typedef union ocb_qssr_or
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
        uint64_t l2_stopped : 12;
        uint64_t l3_stopped : 12;
        uint64_t quad_stopped : 6;
        uint64_t reserved1 : 1;
        uint64_t stop_in_progress : 1;
        uint64_t reserved2 : 32;
#else
        uint64_t reserved2 : 32;
        uint64_t stop_in_progress : 1;
        uint64_t reserved1 : 1;
        uint64_t quad_stopped : 6;
        uint64_t l3_stopped : 12;
        uint64_t l2_stopped : 12;
#endif // _BIG_ENDIAN
    } fields;
} ocb_qssr_or_t;



typedef union ocb_otbr
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
        uint64_t ocb_timebase : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t ocb_timebase : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_otbr_t;



typedef union ocb_otrn
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
        uint64_t timeout : 1;
        uint64_t control : 1;
        uint64_t auto_reload : 1;
        uint64_t spare : 13;
        uint64_t timer : 16;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t timer : 16;
        uint64_t spare : 13;
        uint64_t auto_reload : 1;
        uint64_t control : 1;
        uint64_t timeout : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_otrn_t;



typedef union ocb_ocbslbrn
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
        uint64_t pull_oci_region : 3;
        uint64_t pull_start : 26;
        uint64_t reserved1 : 35;
#else
        uint64_t reserved1 : 35;
        uint64_t pull_start : 26;
        uint64_t pull_oci_region : 3;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocbslbrn_t;



typedef union ocb_ocbslcsn
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
        uint64_t pull_full : 1;
        uint64_t pull_empty : 1;
        uint64_t spare : 2;
        uint64_t pull_intr_action : 2;
        uint64_t pull_length : 5;
        uint64_t reserved1 : 2;
        uint64_t pull_write_ptr : 5;
        uint64_t reserved2 : 3;
        uint64_t pull_read_ptr : 5;
        uint64_t reserved3 : 5;
        uint64_t pull_enable : 1;
        uint64_t reserved4 : 32;
#else
        uint64_t reserved4 : 32;
        uint64_t pull_enable : 1;
        uint64_t reserved3 : 5;
        uint64_t pull_read_ptr : 5;
        uint64_t reserved2 : 3;
        uint64_t pull_write_ptr : 5;
        uint64_t reserved1 : 2;
        uint64_t pull_length : 5;
        uint64_t pull_intr_action : 2;
        uint64_t spare : 2;
        uint64_t pull_empty : 1;
        uint64_t pull_full : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocbslcsn_t;



typedef union ocb_ocbslin
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
} ocb_ocbslin_t;



typedef union ocb_ocbshbrn
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
        uint64_t push_oci_region : 3;
        uint64_t push_start : 26;
        uint64_t reserved1 : 35;
#else
        uint64_t reserved1 : 35;
        uint64_t push_start : 26;
        uint64_t push_oci_region : 3;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocbshbrn_t;



typedef union ocb_ocbshcsn
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
        uint64_t push_full : 1;
        uint64_t push_empty : 1;
        uint64_t spare : 2;
        uint64_t push_intr_action : 2;
        uint64_t push_length : 5;
        uint64_t reserved1 : 2;
        uint64_t push_write_ptr : 5;
        uint64_t reserved2 : 3;
        uint64_t push_read_ptr : 5;
        uint64_t reserved3 : 5;
        uint64_t push_enable : 1;
        uint64_t reserved4 : 32;
#else
        uint64_t reserved4 : 32;
        uint64_t push_enable : 1;
        uint64_t reserved3 : 5;
        uint64_t push_read_ptr : 5;
        uint64_t reserved2 : 3;
        uint64_t push_write_ptr : 5;
        uint64_t reserved1 : 2;
        uint64_t push_length : 5;
        uint64_t push_intr_action : 2;
        uint64_t spare : 2;
        uint64_t push_empty : 1;
        uint64_t push_full : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocbshcsn_t;



typedef union ocb_ocbshin
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
} ocb_ocbshin_t;



typedef union ocb_ocbsesn
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
        uint64_t push_read_underflow : 1;
        uint64_t pull_write_overflow : 1;
        uint64_t reserved1 : 62;
#else
        uint64_t reserved1 : 62;
        uint64_t pull_write_overflow : 1;
        uint64_t push_read_underflow : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocbsesn_t;



typedef union ocb_ocblwcrn
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
        uint64_t linear_window_enable : 1;
        uint64_t spare_0 : 2;
        uint64_t linear_window_bar : 17;
        uint64_t linear_window_mask : 12;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t linear_window_mask : 12;
        uint64_t linear_window_bar : 17;
        uint64_t spare_0 : 2;
        uint64_t linear_window_enable : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocblwcrn_t;



typedef union ocb_ocblwsrn
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
        uint64_t linear_window_scresp : 3;
        uint64_t spare0 : 5;
        uint64_t reserved1 : 56;
#else
        uint64_t reserved1 : 56;
        uint64_t spare0 : 5;
        uint64_t linear_window_scresp : 3;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocblwsrn_t;



typedef union ocb_ocblwsbrn
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
        uint64_t linear_window_region : 3;
        uint64_t linear_window_base : 7;
        uint64_t reserved1 : 54;
#else
        uint64_t reserved1 : 54;
        uint64_t linear_window_base : 7;
        uint64_t linear_window_region : 3;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocblwsbrn_t;



typedef union ocb_opit0cn
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
        uint64_t reserved1 : 22;
        uint64_t pcb_intr_type_a_core_n : 10;
        uint64_t reserved2 : 32;
#else
        uint64_t reserved2 : 32;
        uint64_t pcb_intr_type_a_core_n : 10;
        uint64_t reserved1 : 22;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit0cn_t;



typedef union ocb_opit1cn
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
        uint64_t reserved1 : 22;
        uint64_t pcb_intr_type_a_core_n : 10;
        uint64_t reserved2 : 32;
#else
        uint64_t reserved2 : 32;
        uint64_t pcb_intr_type_a_core_n : 10;
        uint64_t reserved1 : 22;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit1cn_t;



typedef union ocb_opit2cn
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
        uint64_t reserved1 : 22;
        uint64_t pcb_intr_type_a_core_n : 10;
        uint64_t reserved2 : 32;
#else
        uint64_t reserved2 : 32;
        uint64_t pcb_intr_type_a_core_n : 10;
        uint64_t reserved1 : 22;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit2cn_t;



typedef union ocb_opit3cn
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
        uint64_t reserved1 : 22;
        uint64_t pcb_intr_type_a_core_n : 10;
        uint64_t reserved2 : 32;
#else
        uint64_t reserved2 : 32;
        uint64_t pcb_intr_type_a_core_n : 10;
        uint64_t reserved1 : 22;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit3cn_t;



typedef union ocb_opit4cn
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
        uint64_t reserved1 : 22;
        uint64_t pcb_intr_type_a_core_n : 10;
        uint64_t reserved2 : 32;
#else
        uint64_t reserved2 : 32;
        uint64_t pcb_intr_type_a_core_n : 10;
        uint64_t reserved1 : 22;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit4cn_t;



typedef union ocb_opit5cn
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
        uint64_t reserved1 : 22;
        uint64_t pcb_intr_type_a_core_n : 10;
        uint64_t reserved2 : 32;
#else
        uint64_t reserved2 : 32;
        uint64_t pcb_intr_type_a_core_n : 10;
        uint64_t reserved1 : 22;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit5cn_t;



typedef union ocb_opit6xn
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
        uint64_t reserved1 : 22;
        uint64_t pcb_intr_type_a_quad_n : 4;
        uint64_t reserved2 : 6;
        uint64_t reserved3 : 32;
#else
        uint64_t reserved3 : 32;
        uint64_t reserved2 : 6;
        uint64_t pcb_intr_type_a_quad_n : 4;
        uint64_t reserved1 : 22;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit6xn_t;



typedef union ocb_opit7xn
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
        uint64_t reserved1 : 22;
        uint64_t pcb_intr_type_a_quad_n : 1;
        uint64_t reserved2 : 9;
        uint64_t reserved3 : 32;
#else
        uint64_t reserved3 : 32;
        uint64_t reserved2 : 9;
        uint64_t pcb_intr_type_a_quad_n : 1;
        uint64_t reserved1 : 22;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit7xn_t;



typedef union ocb_opit0cnrp
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
        uint64_t reserved1 : 22;
        uint64_t pcb_intr_type_a_reset_core_n : 10;
        uint64_t reserved2 : 32;
#else
        uint64_t reserved2 : 32;
        uint64_t pcb_intr_type_a_reset_core_n : 10;
        uint64_t reserved1 : 22;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit0cnrp_t;



typedef union ocb_opit1cnrp
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
        uint64_t reserved1 : 22;
        uint64_t pcb_intr_type_a_reset_core_n : 10;
        uint64_t reserved2 : 32;
#else
        uint64_t reserved2 : 32;
        uint64_t pcb_intr_type_a_reset_core_n : 10;
        uint64_t reserved1 : 22;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit1cnrp_t;



typedef union ocb_opit2cnrp
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
        uint64_t reserved1 : 22;
        uint64_t pcb_intr_type_a_reset_core_n : 10;
        uint64_t reserved2 : 32;
#else
        uint64_t reserved2 : 32;
        uint64_t pcb_intr_type_a_reset_core_n : 10;
        uint64_t reserved1 : 22;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit2cnrp_t;



typedef union ocb_opit3cnrp
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
        uint64_t reserved1 : 22;
        uint64_t pcb_intr_type_a_reset_core_n : 10;
        uint64_t reserved2 : 32;
#else
        uint64_t reserved2 : 32;
        uint64_t pcb_intr_type_a_reset_core_n : 10;
        uint64_t reserved1 : 22;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit3cnrp_t;



typedef union ocb_opit4cnrp
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
        uint64_t reserved1 : 22;
        uint64_t pcb_intr_type_a_reset_core_n : 10;
        uint64_t reserved2 : 32;
#else
        uint64_t reserved2 : 32;
        uint64_t pcb_intr_type_a_reset_core_n : 10;
        uint64_t reserved1 : 22;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit4cnrp_t;



typedef union ocb_opit5cnrp
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
        uint64_t reserved1 : 22;
        uint64_t pcb_intr_type_a_reset_core_n : 10;
        uint64_t reserved2 : 32;
#else
        uint64_t reserved2 : 32;
        uint64_t pcb_intr_type_a_reset_core_n : 10;
        uint64_t reserved1 : 22;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit5cnrp_t;



typedef union ocb_opit6xnrp
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
        uint64_t reserved1 : 22;
        uint64_t pcb_intr_type_a_reset_quad_n : 4;
        uint64_t reserved2 : 6;
        uint64_t reserved3 : 32;
#else
        uint64_t reserved3 : 32;
        uint64_t reserved2 : 6;
        uint64_t pcb_intr_type_a_reset_quad_n : 4;
        uint64_t reserved1 : 22;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit6xnrp_t;



typedef union ocb_opit7xnrp
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
        uint64_t reserved1 : 22;
        uint64_t pcb_intr_type_a_reset_quad_n : 1;
        uint64_t reserved2 : 9;
        uint64_t reserved3 : 32;
#else
        uint64_t reserved3 : 32;
        uint64_t reserved2 : 9;
        uint64_t pcb_intr_type_a_reset_quad_n : 1;
        uint64_t reserved1 : 22;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit7xnrp_t;



typedef union ocb_opitnpra
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
        uint64_t pcb_intr_type_n_pending_0 : 1;
        uint64_t pcb_intr_type_n_pending_1 : 1;
        uint64_t pcb_intr_type_n_pending_2 : 1;
        uint64_t pcb_intr_type_n_pending_3 : 1;
        uint64_t pcb_intr_type_n_pending_4 : 1;
        uint64_t pcb_intr_type_n_pending_5 : 1;
        uint64_t pcb_intr_type_n_pending_6 : 1;
        uint64_t pcb_intr_type_n_pending_7 : 1;
        uint64_t pcb_intr_type_n_pending_8 : 1;
        uint64_t pcb_intr_type_n_pending_9 : 1;
        uint64_t pcb_intr_type_n_pending_10 : 1;
        uint64_t pcb_intr_type_n_pending_11 : 1;
        uint64_t pcb_intr_type_n_pending_12 : 1;
        uint64_t pcb_intr_type_n_pending_13 : 1;
        uint64_t pcb_intr_type_n_pending_14 : 1;
        uint64_t pcb_intr_type_n_pending_15 : 1;
        uint64_t pcb_intr_type_n_pending_16 : 1;
        uint64_t pcb_intr_type_n_pending_17 : 1;
        uint64_t pcb_intr_type_n_pending_18 : 1;
        uint64_t pcb_intr_type_n_pending_19 : 1;
        uint64_t pcb_intr_type_n_pending_20 : 1;
        uint64_t pcb_intr_type_n_pending_21 : 1;
        uint64_t pcb_intr_type_n_pending_22 : 1;
        uint64_t pcb_intr_type_n_pending_23 : 1;
        uint64_t reserved1 : 8;
        uint64_t reserved2 : 32;
#else
        uint64_t reserved2 : 32;
        uint64_t reserved1 : 8;
        uint64_t pcb_intr_type_n_pending_23 : 1;
        uint64_t pcb_intr_type_n_pending_22 : 1;
        uint64_t pcb_intr_type_n_pending_21 : 1;
        uint64_t pcb_intr_type_n_pending_20 : 1;
        uint64_t pcb_intr_type_n_pending_19 : 1;
        uint64_t pcb_intr_type_n_pending_18 : 1;
        uint64_t pcb_intr_type_n_pending_17 : 1;
        uint64_t pcb_intr_type_n_pending_16 : 1;
        uint64_t pcb_intr_type_n_pending_15 : 1;
        uint64_t pcb_intr_type_n_pending_14 : 1;
        uint64_t pcb_intr_type_n_pending_13 : 1;
        uint64_t pcb_intr_type_n_pending_12 : 1;
        uint64_t pcb_intr_type_n_pending_11 : 1;
        uint64_t pcb_intr_type_n_pending_10 : 1;
        uint64_t pcb_intr_type_n_pending_9 : 1;
        uint64_t pcb_intr_type_n_pending_8 : 1;
        uint64_t pcb_intr_type_n_pending_7 : 1;
        uint64_t pcb_intr_type_n_pending_6 : 1;
        uint64_t pcb_intr_type_n_pending_5 : 1;
        uint64_t pcb_intr_type_n_pending_4 : 1;
        uint64_t pcb_intr_type_n_pending_3 : 1;
        uint64_t pcb_intr_type_n_pending_2 : 1;
        uint64_t pcb_intr_type_n_pending_1 : 1;
        uint64_t pcb_intr_type_n_pending_0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opitnpra_t;



typedef union ocb_opitnpra_clr
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
        uint64_t pcb_intr_type_n_pending_0 : 1;
        uint64_t pcb_intr_type_n_pending_1 : 1;
        uint64_t pcb_intr_type_n_pending_2 : 1;
        uint64_t pcb_intr_type_n_pending_3 : 1;
        uint64_t pcb_intr_type_n_pending_4 : 1;
        uint64_t pcb_intr_type_n_pending_5 : 1;
        uint64_t pcb_intr_type_n_pending_6 : 1;
        uint64_t pcb_intr_type_n_pending_7 : 1;
        uint64_t pcb_intr_type_n_pending_8 : 1;
        uint64_t pcb_intr_type_n_pending_9 : 1;
        uint64_t pcb_intr_type_n_pending_10 : 1;
        uint64_t pcb_intr_type_n_pending_11 : 1;
        uint64_t pcb_intr_type_n_pending_12 : 1;
        uint64_t pcb_intr_type_n_pending_13 : 1;
        uint64_t pcb_intr_type_n_pending_14 : 1;
        uint64_t pcb_intr_type_n_pending_15 : 1;
        uint64_t pcb_intr_type_n_pending_16 : 1;
        uint64_t pcb_intr_type_n_pending_17 : 1;
        uint64_t pcb_intr_type_n_pending_18 : 1;
        uint64_t pcb_intr_type_n_pending_19 : 1;
        uint64_t pcb_intr_type_n_pending_20 : 1;
        uint64_t pcb_intr_type_n_pending_21 : 1;
        uint64_t pcb_intr_type_n_pending_22 : 1;
        uint64_t pcb_intr_type_n_pending_23 : 1;
        uint64_t reserved1 : 8;
        uint64_t reserved2 : 32;
#else
        uint64_t reserved2 : 32;
        uint64_t reserved1 : 8;
        uint64_t pcb_intr_type_n_pending_23 : 1;
        uint64_t pcb_intr_type_n_pending_22 : 1;
        uint64_t pcb_intr_type_n_pending_21 : 1;
        uint64_t pcb_intr_type_n_pending_20 : 1;
        uint64_t pcb_intr_type_n_pending_19 : 1;
        uint64_t pcb_intr_type_n_pending_18 : 1;
        uint64_t pcb_intr_type_n_pending_17 : 1;
        uint64_t pcb_intr_type_n_pending_16 : 1;
        uint64_t pcb_intr_type_n_pending_15 : 1;
        uint64_t pcb_intr_type_n_pending_14 : 1;
        uint64_t pcb_intr_type_n_pending_13 : 1;
        uint64_t pcb_intr_type_n_pending_12 : 1;
        uint64_t pcb_intr_type_n_pending_11 : 1;
        uint64_t pcb_intr_type_n_pending_10 : 1;
        uint64_t pcb_intr_type_n_pending_9 : 1;
        uint64_t pcb_intr_type_n_pending_8 : 1;
        uint64_t pcb_intr_type_n_pending_7 : 1;
        uint64_t pcb_intr_type_n_pending_6 : 1;
        uint64_t pcb_intr_type_n_pending_5 : 1;
        uint64_t pcb_intr_type_n_pending_4 : 1;
        uint64_t pcb_intr_type_n_pending_3 : 1;
        uint64_t pcb_intr_type_n_pending_2 : 1;
        uint64_t pcb_intr_type_n_pending_1 : 1;
        uint64_t pcb_intr_type_n_pending_0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opitnpra_clr_t;



typedef union ocb_opitnpra_or
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
        uint64_t pcb_intr_type_n_pending_0 : 1;
        uint64_t pcb_intr_type_n_pending_1 : 1;
        uint64_t pcb_intr_type_n_pending_2 : 1;
        uint64_t pcb_intr_type_n_pending_3 : 1;
        uint64_t pcb_intr_type_n_pending_4 : 1;
        uint64_t pcb_intr_type_n_pending_5 : 1;
        uint64_t pcb_intr_type_n_pending_6 : 1;
        uint64_t pcb_intr_type_n_pending_7 : 1;
        uint64_t pcb_intr_type_n_pending_8 : 1;
        uint64_t pcb_intr_type_n_pending_9 : 1;
        uint64_t pcb_intr_type_n_pending_10 : 1;
        uint64_t pcb_intr_type_n_pending_11 : 1;
        uint64_t pcb_intr_type_n_pending_12 : 1;
        uint64_t pcb_intr_type_n_pending_13 : 1;
        uint64_t pcb_intr_type_n_pending_14 : 1;
        uint64_t pcb_intr_type_n_pending_15 : 1;
        uint64_t pcb_intr_type_n_pending_16 : 1;
        uint64_t pcb_intr_type_n_pending_17 : 1;
        uint64_t pcb_intr_type_n_pending_18 : 1;
        uint64_t pcb_intr_type_n_pending_19 : 1;
        uint64_t pcb_intr_type_n_pending_20 : 1;
        uint64_t pcb_intr_type_n_pending_21 : 1;
        uint64_t pcb_intr_type_n_pending_22 : 1;
        uint64_t pcb_intr_type_n_pending_23 : 1;
        uint64_t reserved1 : 8;
        uint64_t reserved2 : 32;
#else
        uint64_t reserved2 : 32;
        uint64_t reserved1 : 8;
        uint64_t pcb_intr_type_n_pending_23 : 1;
        uint64_t pcb_intr_type_n_pending_22 : 1;
        uint64_t pcb_intr_type_n_pending_21 : 1;
        uint64_t pcb_intr_type_n_pending_20 : 1;
        uint64_t pcb_intr_type_n_pending_19 : 1;
        uint64_t pcb_intr_type_n_pending_18 : 1;
        uint64_t pcb_intr_type_n_pending_17 : 1;
        uint64_t pcb_intr_type_n_pending_16 : 1;
        uint64_t pcb_intr_type_n_pending_15 : 1;
        uint64_t pcb_intr_type_n_pending_14 : 1;
        uint64_t pcb_intr_type_n_pending_13 : 1;
        uint64_t pcb_intr_type_n_pending_12 : 1;
        uint64_t pcb_intr_type_n_pending_11 : 1;
        uint64_t pcb_intr_type_n_pending_10 : 1;
        uint64_t pcb_intr_type_n_pending_9 : 1;
        uint64_t pcb_intr_type_n_pending_8 : 1;
        uint64_t pcb_intr_type_n_pending_7 : 1;
        uint64_t pcb_intr_type_n_pending_6 : 1;
        uint64_t pcb_intr_type_n_pending_5 : 1;
        uint64_t pcb_intr_type_n_pending_4 : 1;
        uint64_t pcb_intr_type_n_pending_3 : 1;
        uint64_t pcb_intr_type_n_pending_2 : 1;
        uint64_t pcb_intr_type_n_pending_1 : 1;
        uint64_t pcb_intr_type_n_pending_0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opitnpra_or_t;



typedef union ocb_opit6prb
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
        uint64_t pcb_intr_type_n_pending_0 : 1;
        uint64_t pcb_intr_type_n_pending_1 : 1;
        uint64_t pcb_intr_type_n_pending_2 : 1;
        uint64_t pcb_intr_type_n_pending_3 : 1;
        uint64_t pcb_intr_type_n_pending_4 : 1;
        uint64_t pcb_intr_type_n_pending_5 : 1;
        uint64_t reserved1 : 26;
        uint64_t reserved2 : 32;
#else
        uint64_t reserved2 : 32;
        uint64_t reserved1 : 26;
        uint64_t pcb_intr_type_n_pending_5 : 1;
        uint64_t pcb_intr_type_n_pending_4 : 1;
        uint64_t pcb_intr_type_n_pending_3 : 1;
        uint64_t pcb_intr_type_n_pending_2 : 1;
        uint64_t pcb_intr_type_n_pending_1 : 1;
        uint64_t pcb_intr_type_n_pending_0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit6prb_t;



typedef union ocb_opit6prb_clr
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
        uint64_t pcb_intr_type_n_pending_0 : 1;
        uint64_t pcb_intr_type_n_pending_1 : 1;
        uint64_t pcb_intr_type_n_pending_2 : 1;
        uint64_t pcb_intr_type_n_pending_3 : 1;
        uint64_t pcb_intr_type_n_pending_4 : 1;
        uint64_t pcb_intr_type_n_pending_5 : 1;
        uint64_t reserved1 : 26;
        uint64_t reserved2 : 32;
#else
        uint64_t reserved2 : 32;
        uint64_t reserved1 : 26;
        uint64_t pcb_intr_type_n_pending_5 : 1;
        uint64_t pcb_intr_type_n_pending_4 : 1;
        uint64_t pcb_intr_type_n_pending_3 : 1;
        uint64_t pcb_intr_type_n_pending_2 : 1;
        uint64_t pcb_intr_type_n_pending_1 : 1;
        uint64_t pcb_intr_type_n_pending_0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit6prb_clr_t;



typedef union ocb_opit6prb_or
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
        uint64_t pcb_intr_type_n_pending_0 : 1;
        uint64_t pcb_intr_type_n_pending_1 : 1;
        uint64_t pcb_intr_type_n_pending_2 : 1;
        uint64_t pcb_intr_type_n_pending_3 : 1;
        uint64_t pcb_intr_type_n_pending_4 : 1;
        uint64_t pcb_intr_type_n_pending_5 : 1;
        uint64_t reserved1 : 26;
        uint64_t reserved2 : 32;
#else
        uint64_t reserved2 : 32;
        uint64_t reserved1 : 26;
        uint64_t pcb_intr_type_n_pending_5 : 1;
        uint64_t pcb_intr_type_n_pending_4 : 1;
        uint64_t pcb_intr_type_n_pending_3 : 1;
        uint64_t pcb_intr_type_n_pending_2 : 1;
        uint64_t pcb_intr_type_n_pending_1 : 1;
        uint64_t pcb_intr_type_n_pending_0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit6prb_or_t;



typedef union ocb_opit7prb
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
        uint64_t pcb_intr_type_n_pending_0 : 1;
        uint64_t pcb_intr_type_n_pending_1 : 1;
        uint64_t pcb_intr_type_n_pending_2 : 1;
        uint64_t pcb_intr_type_n_pending_3 : 1;
        uint64_t pcb_intr_type_n_pending_4 : 1;
        uint64_t pcb_intr_type_n_pending_5 : 1;
        uint64_t reserved1 : 26;
        uint64_t reserved2 : 32;
#else
        uint64_t reserved2 : 32;
        uint64_t reserved1 : 26;
        uint64_t pcb_intr_type_n_pending_5 : 1;
        uint64_t pcb_intr_type_n_pending_4 : 1;
        uint64_t pcb_intr_type_n_pending_3 : 1;
        uint64_t pcb_intr_type_n_pending_2 : 1;
        uint64_t pcb_intr_type_n_pending_1 : 1;
        uint64_t pcb_intr_type_n_pending_0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit7prb_t;



typedef union ocb_opit7prb_clr
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
        uint64_t pcb_intr_type_n_pending_0 : 1;
        uint64_t pcb_intr_type_n_pending_1 : 1;
        uint64_t pcb_intr_type_n_pending_2 : 1;
        uint64_t pcb_intr_type_n_pending_3 : 1;
        uint64_t pcb_intr_type_n_pending_4 : 1;
        uint64_t pcb_intr_type_n_pending_5 : 1;
        uint64_t reserved1 : 26;
        uint64_t reserved2 : 32;
#else
        uint64_t reserved2 : 32;
        uint64_t reserved1 : 26;
        uint64_t pcb_intr_type_n_pending_5 : 1;
        uint64_t pcb_intr_type_n_pending_4 : 1;
        uint64_t pcb_intr_type_n_pending_3 : 1;
        uint64_t pcb_intr_type_n_pending_2 : 1;
        uint64_t pcb_intr_type_n_pending_1 : 1;
        uint64_t pcb_intr_type_n_pending_0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit7prb_clr_t;



typedef union ocb_opit7prb_or
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
        uint64_t pcb_intr_type_n_pending_0 : 1;
        uint64_t pcb_intr_type_n_pending_1 : 1;
        uint64_t pcb_intr_type_n_pending_2 : 1;
        uint64_t pcb_intr_type_n_pending_3 : 1;
        uint64_t pcb_intr_type_n_pending_4 : 1;
        uint64_t pcb_intr_type_n_pending_5 : 1;
        uint64_t reserved1 : 26;
        uint64_t reserved2 : 32;
#else
        uint64_t reserved2 : 32;
        uint64_t reserved1 : 26;
        uint64_t pcb_intr_type_n_pending_5 : 1;
        uint64_t pcb_intr_type_n_pending_4 : 1;
        uint64_t pcb_intr_type_n_pending_3 : 1;
        uint64_t pcb_intr_type_n_pending_2 : 1;
        uint64_t pcb_intr_type_n_pending_1 : 1;
        uint64_t pcb_intr_type_n_pending_0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_opit7prb_or_t;



typedef union ocb_o2sctrlf0a
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
        uint64_t o2s_frame_size_an : 6;
        uint64_t o2s_out_count1_an : 6;
        uint64_t o2s_in_delay1_an : 6;
        uint64_t o2s_in_count1_an : 6;
        uint64_t reserved1 : 40;
#else
        uint64_t reserved1 : 40;
        uint64_t o2s_in_count1_an : 6;
        uint64_t o2s_in_delay1_an : 6;
        uint64_t o2s_out_count1_an : 6;
        uint64_t o2s_frame_size_an : 6;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2sctrlf0a_t;



typedef union ocb_o2sctrls0a
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
        uint64_t o2s_out_count2_an : 6;
        uint64_t o2s_in_delay2_an : 6;
        uint64_t o2s_in_count2_an : 6;
        uint64_t reserved1 : 46;
#else
        uint64_t reserved1 : 46;
        uint64_t o2s_in_count2_an : 6;
        uint64_t o2s_in_delay2_an : 6;
        uint64_t o2s_out_count2_an : 6;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2sctrls0a_t;



typedef union ocb_o2sctrl10a
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
        uint64_t o2s_bridge_enable_an : 1;
        uint64_t o2sctrl1an_reserved_1 : 1;
        uint64_t o2s_cpol_an : 1;
        uint64_t o2s_cpha_an : 1;
        uint64_t o2s_clock_divider_an : 10;
        uint64_t o2sctrl1an_reserved_14_16 : 3;
        uint64_t o2s_nr_of_frames_an : 1;
        uint64_t reserved1 : 46;
#else
        uint64_t reserved1 : 46;
        uint64_t o2s_nr_of_frames_an : 1;
        uint64_t o2sctrl1an_reserved_14_16 : 3;
        uint64_t o2s_clock_divider_an : 10;
        uint64_t o2s_cpha_an : 1;
        uint64_t o2s_cpol_an : 1;
        uint64_t o2sctrl1an_reserved_1 : 1;
        uint64_t o2s_bridge_enable_an : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2sctrl10a_t;



typedef union ocb_o2sctrl20a
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
        uint64_t o2s_inter_frame_delay_an : 17;
        uint64_t reserved1 : 47;
#else
        uint64_t reserved1 : 47;
        uint64_t o2s_inter_frame_delay_an : 17;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2sctrl20a_t;



typedef union ocb_o2sst0a
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
        uint64_t o2s_ongoing_an : 1;
        uint64_t o2sstan_reserved_1_4 : 4;
        uint64_t o2s_write_while_bridge_busy_err_an : 1;
        uint64_t o2sstan_reserved_6 : 1;
        uint64_t o2s_fsm_err_an : 1;
        uint64_t reserved1 : 56;
#else
        uint64_t reserved1 : 56;
        uint64_t o2s_fsm_err_an : 1;
        uint64_t o2sstan_reserved_6 : 1;
        uint64_t o2s_write_while_bridge_busy_err_an : 1;
        uint64_t o2sstan_reserved_1_4 : 4;
        uint64_t o2s_ongoing_an : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2sst0a_t;



typedef union ocb_o2scmd0a
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
        uint64_t o2scmdan_reserved_0 : 1;
        uint64_t o2s_clear_sticky_bits_an : 1;
        uint64_t reserved1 : 62;
#else
        uint64_t reserved1 : 62;
        uint64_t o2s_clear_sticky_bits_an : 1;
        uint64_t o2scmdan_reserved_0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2scmd0a_t;



typedef union ocb_o2swd0a
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
        uint64_t o2s_wdata_an : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t o2s_wdata_an : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2swd0a_t;



typedef union ocb_o2srd0a
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
        uint64_t o2s_rdata_an : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t o2s_rdata_an : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2srd0a_t;



typedef union ocb_o2sctrlf0b
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
        uint64_t o2s_frame_size_an : 6;
        uint64_t o2s_out_count1_an : 6;
        uint64_t o2s_in_delay1_an : 6;
        uint64_t o2s_in_count1_an : 6;
        uint64_t reserved1 : 40;
#else
        uint64_t reserved1 : 40;
        uint64_t o2s_in_count1_an : 6;
        uint64_t o2s_in_delay1_an : 6;
        uint64_t o2s_out_count1_an : 6;
        uint64_t o2s_frame_size_an : 6;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2sctrlf0b_t;



typedef union ocb_o2sctrls0b
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
        uint64_t o2s_out_count2_an : 6;
        uint64_t o2s_in_delay2_an : 6;
        uint64_t o2s_in_count2_an : 6;
        uint64_t reserved1 : 46;
#else
        uint64_t reserved1 : 46;
        uint64_t o2s_in_count2_an : 6;
        uint64_t o2s_in_delay2_an : 6;
        uint64_t o2s_out_count2_an : 6;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2sctrls0b_t;



typedef union ocb_o2sctrl10b
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
        uint64_t o2s_bridge_enable_an : 1;
        uint64_t o2sctrl1an_reserved_1 : 1;
        uint64_t o2s_cpol_an : 1;
        uint64_t o2s_cpha_an : 1;
        uint64_t o2s_clock_divider_an : 10;
        uint64_t o2sctrl1an_reserved_14_16 : 3;
        uint64_t o2s_nr_of_frames_an : 1;
        uint64_t reserved1 : 46;
#else
        uint64_t reserved1 : 46;
        uint64_t o2s_nr_of_frames_an : 1;
        uint64_t o2sctrl1an_reserved_14_16 : 3;
        uint64_t o2s_clock_divider_an : 10;
        uint64_t o2s_cpha_an : 1;
        uint64_t o2s_cpol_an : 1;
        uint64_t o2sctrl1an_reserved_1 : 1;
        uint64_t o2s_bridge_enable_an : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2sctrl10b_t;



typedef union ocb_o2sctrl20b
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
        uint64_t o2s_inter_frame_delay_an : 17;
        uint64_t reserved1 : 47;
#else
        uint64_t reserved1 : 47;
        uint64_t o2s_inter_frame_delay_an : 17;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2sctrl20b_t;



typedef union ocb_o2sst0b
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
        uint64_t o2s_ongoing_an : 1;
        uint64_t o2sstan_reserved_1_4 : 4;
        uint64_t o2s_write_while_bridge_busy_err_an : 1;
        uint64_t o2sstan_reserved_6 : 1;
        uint64_t o2s_fsm_err_an : 1;
        uint64_t reserved1 : 56;
#else
        uint64_t reserved1 : 56;
        uint64_t o2s_fsm_err_an : 1;
        uint64_t o2sstan_reserved_6 : 1;
        uint64_t o2s_write_while_bridge_busy_err_an : 1;
        uint64_t o2sstan_reserved_1_4 : 4;
        uint64_t o2s_ongoing_an : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2sst0b_t;



typedef union ocb_o2scmd0b
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
        uint64_t o2scmdan_reserved_0 : 1;
        uint64_t o2s_clear_sticky_bits_an : 1;
        uint64_t reserved1 : 62;
#else
        uint64_t reserved1 : 62;
        uint64_t o2s_clear_sticky_bits_an : 1;
        uint64_t o2scmdan_reserved_0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2scmd0b_t;



typedef union ocb_o2swd0b
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
        uint64_t o2s_wdata_an : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t o2s_wdata_an : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2swd0b_t;



typedef union ocb_o2srd0b
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
        uint64_t o2s_rdata_an : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t o2s_rdata_an : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2srd0b_t;



typedef union ocb_o2sctrlf1a
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
        uint64_t o2s_frame_size_an : 6;
        uint64_t o2s_out_count1_an : 6;
        uint64_t o2s_in_delay1_an : 6;
        uint64_t o2s_in_count1_an : 6;
        uint64_t reserved1 : 40;
#else
        uint64_t reserved1 : 40;
        uint64_t o2s_in_count1_an : 6;
        uint64_t o2s_in_delay1_an : 6;
        uint64_t o2s_out_count1_an : 6;
        uint64_t o2s_frame_size_an : 6;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2sctrlf1a_t;



typedef union ocb_o2sctrls1a
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
        uint64_t o2s_out_count2_an : 6;
        uint64_t o2s_in_delay2_an : 6;
        uint64_t o2s_in_count2_an : 6;
        uint64_t reserved1 : 46;
#else
        uint64_t reserved1 : 46;
        uint64_t o2s_in_count2_an : 6;
        uint64_t o2s_in_delay2_an : 6;
        uint64_t o2s_out_count2_an : 6;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2sctrls1a_t;



typedef union ocb_o2sctrl11a
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
        uint64_t o2s_bridge_enable_an : 1;
        uint64_t o2sctrl1an_reserved_1 : 1;
        uint64_t o2s_cpol_an : 1;
        uint64_t o2s_cpha_an : 1;
        uint64_t o2s_clock_divider_an : 10;
        uint64_t o2sctrl1an_reserved_14_16 : 3;
        uint64_t o2s_nr_of_frames_an : 1;
        uint64_t reserved1 : 46;
#else
        uint64_t reserved1 : 46;
        uint64_t o2s_nr_of_frames_an : 1;
        uint64_t o2sctrl1an_reserved_14_16 : 3;
        uint64_t o2s_clock_divider_an : 10;
        uint64_t o2s_cpha_an : 1;
        uint64_t o2s_cpol_an : 1;
        uint64_t o2sctrl1an_reserved_1 : 1;
        uint64_t o2s_bridge_enable_an : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2sctrl11a_t;



typedef union ocb_o2sctrl21a
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
        uint64_t o2s_inter_frame_delay_an : 17;
        uint64_t reserved1 : 47;
#else
        uint64_t reserved1 : 47;
        uint64_t o2s_inter_frame_delay_an : 17;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2sctrl21a_t;



typedef union ocb_o2sst1a
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
        uint64_t o2s_ongoing_an : 1;
        uint64_t o2sstan_reserved_1_4 : 4;
        uint64_t o2s_write_while_bridge_busy_err_an : 1;
        uint64_t o2sstan_reserved_6 : 1;
        uint64_t o2s_fsm_err_an : 1;
        uint64_t reserved1 : 56;
#else
        uint64_t reserved1 : 56;
        uint64_t o2s_fsm_err_an : 1;
        uint64_t o2sstan_reserved_6 : 1;
        uint64_t o2s_write_while_bridge_busy_err_an : 1;
        uint64_t o2sstan_reserved_1_4 : 4;
        uint64_t o2s_ongoing_an : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2sst1a_t;



typedef union ocb_o2scmd1a
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
        uint64_t o2scmdan_reserved_0 : 1;
        uint64_t o2s_clear_sticky_bits_an : 1;
        uint64_t reserved1 : 62;
#else
        uint64_t reserved1 : 62;
        uint64_t o2s_clear_sticky_bits_an : 1;
        uint64_t o2scmdan_reserved_0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2scmd1a_t;



typedef union ocb_o2swd1a
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
        uint64_t o2s_wdata_an : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t o2s_wdata_an : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2swd1a_t;



typedef union ocb_o2srd1a
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
        uint64_t o2s_rdata_an : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t o2s_rdata_an : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2srd1a_t;



typedef union ocb_o2sctrlf1b
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
        uint64_t o2s_frame_size_an : 6;
        uint64_t o2s_out_count1_an : 6;
        uint64_t o2s_in_delay1_an : 6;
        uint64_t o2s_in_count1_an : 6;
        uint64_t reserved1 : 40;
#else
        uint64_t reserved1 : 40;
        uint64_t o2s_in_count1_an : 6;
        uint64_t o2s_in_delay1_an : 6;
        uint64_t o2s_out_count1_an : 6;
        uint64_t o2s_frame_size_an : 6;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2sctrlf1b_t;



typedef union ocb_o2sctrls1b
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
        uint64_t o2s_out_count2_an : 6;
        uint64_t o2s_in_delay2_an : 6;
        uint64_t o2s_in_count2_an : 6;
        uint64_t reserved1 : 46;
#else
        uint64_t reserved1 : 46;
        uint64_t o2s_in_count2_an : 6;
        uint64_t o2s_in_delay2_an : 6;
        uint64_t o2s_out_count2_an : 6;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2sctrls1b_t;



typedef union ocb_o2sctrl11b
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
        uint64_t o2s_bridge_enable_an : 1;
        uint64_t o2sctrl1an_reserved_1 : 1;
        uint64_t o2s_cpol_an : 1;
        uint64_t o2s_cpha_an : 1;
        uint64_t o2s_clock_divider_an : 10;
        uint64_t o2sctrl1an_reserved_14_16 : 3;
        uint64_t o2s_nr_of_frames_an : 1;
        uint64_t reserved1 : 46;
#else
        uint64_t reserved1 : 46;
        uint64_t o2s_nr_of_frames_an : 1;
        uint64_t o2sctrl1an_reserved_14_16 : 3;
        uint64_t o2s_clock_divider_an : 10;
        uint64_t o2s_cpha_an : 1;
        uint64_t o2s_cpol_an : 1;
        uint64_t o2sctrl1an_reserved_1 : 1;
        uint64_t o2s_bridge_enable_an : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2sctrl11b_t;



typedef union ocb_o2sctrl21b
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
        uint64_t o2s_inter_frame_delay_an : 17;
        uint64_t reserved1 : 47;
#else
        uint64_t reserved1 : 47;
        uint64_t o2s_inter_frame_delay_an : 17;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2sctrl21b_t;



typedef union ocb_o2sst1b
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
        uint64_t o2s_ongoing_an : 1;
        uint64_t o2sstan_reserved_1_4 : 4;
        uint64_t o2s_write_while_bridge_busy_err_an : 1;
        uint64_t o2sstan_reserved_6 : 1;
        uint64_t o2s_fsm_err_an : 1;
        uint64_t reserved1 : 56;
#else
        uint64_t reserved1 : 56;
        uint64_t o2s_fsm_err_an : 1;
        uint64_t o2sstan_reserved_6 : 1;
        uint64_t o2s_write_while_bridge_busy_err_an : 1;
        uint64_t o2sstan_reserved_1_4 : 4;
        uint64_t o2s_ongoing_an : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2sst1b_t;



typedef union ocb_o2scmd1b
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
        uint64_t o2scmdan_reserved_0 : 1;
        uint64_t o2s_clear_sticky_bits_an : 1;
        uint64_t reserved1 : 62;
#else
        uint64_t reserved1 : 62;
        uint64_t o2s_clear_sticky_bits_an : 1;
        uint64_t o2scmdan_reserved_0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2scmd1b_t;



typedef union ocb_o2swd1b
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
        uint64_t o2s_wdata_an : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t o2s_wdata_an : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2swd1b_t;



typedef union ocb_o2srd1b
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
        uint64_t o2s_rdata_an : 32;
        uint64_t reserved1 : 32;
#else
        uint64_t reserved1 : 32;
        uint64_t o2s_rdata_an : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_o2srd1b_t;



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
        uint64_t spare : 4;
        uint64_t reserved1 : 48;
#else
        uint64_t reserved1 : 48;
        uint64_t spare : 4;
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
        uint64_t reserved1 : 2;
        uint64_t dcu_timeout_error : 1;
        uint64_t dcu_rnw : 1;
        uint64_t reserved2 : 58;
#else
        uint64_t reserved2 : 58;
        uint64_t dcu_rnw : 1;
        uint64_t dcu_timeout_error : 1;
        uint64_t reserved1 : 2;
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
        uint64_t reserved1 : 3;
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
        uint64_t reserved1 : 3;
        uint64_t ocb_error_address : 32;
#endif // _BIG_ENDIAN
    } fields;
} ocb_ocbear_t;



typedef union ocb_occlfir
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
        uint64_t occ_fw0 : 1;
        uint64_t occ_fw1 : 1;
        uint64_t cme_error_notify : 1;
        uint64_t stop_recovery_notify_prd : 1;
        uint64_t occ_hb_error : 1;
        uint64_t gpe0_watchdog_timeout : 1;
        uint64_t gpe1_watchdog_timeout : 1;
        uint64_t gpe2_watchdog_timeout : 1;
        uint64_t gpe3_watchdog_timeout : 1;
        uint64_t gpe0_error : 1;
        uint64_t gpe1_error : 1;
        uint64_t gpe2_error : 1;
        uint64_t gpe3_error : 1;
        uint64_t ocb_error : 1;
        uint64_t srt_ue : 1;
        uint64_t srt_ce : 1;
        uint64_t srt_read_error : 1;
        uint64_t srt_write_error : 1;
        uint64_t srt_dataout_perr : 1;
        uint64_t srt_oci_write_data_parity : 1;
        uint64_t srt_oci_be_parity_err : 1;
        uint64_t srt_oci_addr_parity_err : 1;
        uint64_t gpe0_halted : 1;
        uint64_t gpe1_halted : 1;
        uint64_t gpe2_halted : 1;
        uint64_t gpe3_halted : 1;
        uint64_t external_trap : 1;
        uint64_t ppc405_core_reset : 1;
        uint64_t ppc405_chip_reset : 1;
        uint64_t ppc405_system_reset : 1;
        uint64_t ppc405_dbgmsrwe : 1;
        uint64_t ppc405_dbgstopack : 1;
        uint64_t ocb_db_oci_timeout : 1;
        uint64_t ocb_db_oci_read_data_parity : 1;
        uint64_t ocb_db_oci_slave_error : 1;
        uint64_t ocb_pib_addr_parity_err : 1;
        uint64_t ocb_db_pib_data_parity_err : 1;
        uint64_t ocb_idc0_error : 1;
        uint64_t ocb_idc1_error : 1;
        uint64_t ocb_idc2_error : 1;
        uint64_t ocb_idc3_error : 1;
        uint64_t srt_fsm_err : 1;
        uint64_t jtagacc_err : 1;
        uint64_t spare_err_38 : 1;
        uint64_t c405_ecc_ue : 1;
        uint64_t c405_ecc_ce : 1;
        uint64_t c405_oci_machinecheck : 1;
        uint64_t sram_spare_direct_error0 : 1;
        uint64_t sram_spare_direct_error1 : 1;
        uint64_t sram_spare_direct_error2 : 1;
        uint64_t sram_spare_direct_error3 : 1;
        uint64_t gpe0_ocislv_err : 1;
        uint64_t gpe1_ocislv_err : 1;
        uint64_t gpe2_ocislv_err : 1;
        uint64_t gpe3_ocislv_err : 1;
        uint64_t c405icu_m_timeout : 1;
        uint64_t c405dcu_m_timeout : 1;
        uint64_t occ_complex_fault_safe : 1;
        uint64_t spare_58_61 : 4;
        uint64_t fir_parity_err_dup : 1;
        uint64_t fir_parity_err : 1;
#else
        uint64_t fir_parity_err : 1;
        uint64_t fir_parity_err_dup : 1;
        uint64_t spare_58_61 : 4;
        uint64_t occ_complex_fault_safe : 1;
        uint64_t c405dcu_m_timeout : 1;
        uint64_t c405icu_m_timeout : 1;
        uint64_t gpe3_ocislv_err : 1;
        uint64_t gpe2_ocislv_err : 1;
        uint64_t gpe1_ocislv_err : 1;
        uint64_t gpe0_ocislv_err : 1;
        uint64_t sram_spare_direct_error3 : 1;
        uint64_t sram_spare_direct_error2 : 1;
        uint64_t sram_spare_direct_error1 : 1;
        uint64_t sram_spare_direct_error0 : 1;
        uint64_t c405_oci_machinecheck : 1;
        uint64_t c405_ecc_ce : 1;
        uint64_t c405_ecc_ue : 1;
        uint64_t spare_err_38 : 1;
        uint64_t jtagacc_err : 1;
        uint64_t srt_fsm_err : 1;
        uint64_t ocb_idc3_error : 1;
        uint64_t ocb_idc2_error : 1;
        uint64_t ocb_idc1_error : 1;
        uint64_t ocb_idc0_error : 1;
        uint64_t ocb_db_pib_data_parity_err : 1;
        uint64_t ocb_pib_addr_parity_err : 1;
        uint64_t ocb_db_oci_slave_error : 1;
        uint64_t ocb_db_oci_read_data_parity : 1;
        uint64_t ocb_db_oci_timeout : 1;
        uint64_t ppc405_dbgstopack : 1;
        uint64_t ppc405_dbgmsrwe : 1;
        uint64_t ppc405_system_reset : 1;
        uint64_t ppc405_chip_reset : 1;
        uint64_t ppc405_core_reset : 1;
        uint64_t external_trap : 1;
        uint64_t gpe3_halted : 1;
        uint64_t gpe2_halted : 1;
        uint64_t gpe1_halted : 1;
        uint64_t gpe0_halted : 1;
        uint64_t srt_oci_addr_parity_err : 1;
        uint64_t srt_oci_be_parity_err : 1;
        uint64_t srt_oci_write_data_parity : 1;
        uint64_t srt_dataout_perr : 1;
        uint64_t srt_write_error : 1;
        uint64_t srt_read_error : 1;
        uint64_t srt_ce : 1;
        uint64_t srt_ue : 1;
        uint64_t ocb_error : 1;
        uint64_t gpe3_error : 1;
        uint64_t gpe2_error : 1;
        uint64_t gpe1_error : 1;
        uint64_t gpe0_error : 1;
        uint64_t gpe3_watchdog_timeout : 1;
        uint64_t gpe2_watchdog_timeout : 1;
        uint64_t gpe1_watchdog_timeout : 1;
        uint64_t gpe0_watchdog_timeout : 1;
        uint64_t occ_hb_error : 1;
        uint64_t stop_recovery_notify_prd : 1;
        uint64_t cme_error_notify : 1;
        uint64_t occ_fw1 : 1;
        uint64_t occ_fw0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_occlfir_t;



typedef union ocb_occlfir_and
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
        uint64_t occ_fw0 : 1;
        uint64_t occ_fw1 : 1;
        uint64_t cme_error_notify : 1;
        uint64_t stop_recovery_notify_prd : 1;
        uint64_t occ_hb_error : 1;
        uint64_t gpe0_watchdog_timeout : 1;
        uint64_t gpe1_watchdog_timeout : 1;
        uint64_t gpe2_watchdog_timeout : 1;
        uint64_t gpe3_watchdog_timeout : 1;
        uint64_t gpe0_error : 1;
        uint64_t gpe1_error : 1;
        uint64_t gpe2_error : 1;
        uint64_t gpe3_error : 1;
        uint64_t ocb_error : 1;
        uint64_t srt_ue : 1;
        uint64_t srt_ce : 1;
        uint64_t srt_read_error : 1;
        uint64_t srt_write_error : 1;
        uint64_t srt_dataout_perr : 1;
        uint64_t srt_oci_write_data_parity : 1;
        uint64_t srt_oci_be_parity_err : 1;
        uint64_t srt_oci_addr_parity_err : 1;
        uint64_t gpe0_halted : 1;
        uint64_t gpe1_halted : 1;
        uint64_t gpe2_halted : 1;
        uint64_t gpe3_halted : 1;
        uint64_t external_trap : 1;
        uint64_t ppc405_core_reset : 1;
        uint64_t ppc405_chip_reset : 1;
        uint64_t ppc405_system_reset : 1;
        uint64_t ppc405_dbgmsrwe : 1;
        uint64_t ppc405_dbgstopack : 1;
        uint64_t ocb_db_oci_timeout : 1;
        uint64_t ocb_db_oci_read_data_parity : 1;
        uint64_t ocb_db_oci_slave_error : 1;
        uint64_t ocb_pib_addr_parity_err : 1;
        uint64_t ocb_db_pib_data_parity_err : 1;
        uint64_t ocb_idc0_error : 1;
        uint64_t ocb_idc1_error : 1;
        uint64_t ocb_idc2_error : 1;
        uint64_t ocb_idc3_error : 1;
        uint64_t srt_fsm_err : 1;
        uint64_t jtagacc_err : 1;
        uint64_t spare_err_38 : 1;
        uint64_t c405_ecc_ue : 1;
        uint64_t c405_ecc_ce : 1;
        uint64_t c405_oci_machinecheck : 1;
        uint64_t sram_spare_direct_error0 : 1;
        uint64_t sram_spare_direct_error1 : 1;
        uint64_t sram_spare_direct_error2 : 1;
        uint64_t sram_spare_direct_error3 : 1;
        uint64_t gpe0_ocislv_err : 1;
        uint64_t gpe1_ocislv_err : 1;
        uint64_t gpe2_ocislv_err : 1;
        uint64_t gpe3_ocislv_err : 1;
        uint64_t c405icu_m_timeout : 1;
        uint64_t c405dcu_m_timeout : 1;
        uint64_t occ_complex_fault_safe : 1;
        uint64_t spare_58_61 : 4;
        uint64_t fir_parity_err_dup : 1;
        uint64_t fir_parity_err : 1;
#else
        uint64_t fir_parity_err : 1;
        uint64_t fir_parity_err_dup : 1;
        uint64_t spare_58_61 : 4;
        uint64_t occ_complex_fault_safe : 1;
        uint64_t c405dcu_m_timeout : 1;
        uint64_t c405icu_m_timeout : 1;
        uint64_t gpe3_ocislv_err : 1;
        uint64_t gpe2_ocislv_err : 1;
        uint64_t gpe1_ocislv_err : 1;
        uint64_t gpe0_ocislv_err : 1;
        uint64_t sram_spare_direct_error3 : 1;
        uint64_t sram_spare_direct_error2 : 1;
        uint64_t sram_spare_direct_error1 : 1;
        uint64_t sram_spare_direct_error0 : 1;
        uint64_t c405_oci_machinecheck : 1;
        uint64_t c405_ecc_ce : 1;
        uint64_t c405_ecc_ue : 1;
        uint64_t spare_err_38 : 1;
        uint64_t jtagacc_err : 1;
        uint64_t srt_fsm_err : 1;
        uint64_t ocb_idc3_error : 1;
        uint64_t ocb_idc2_error : 1;
        uint64_t ocb_idc1_error : 1;
        uint64_t ocb_idc0_error : 1;
        uint64_t ocb_db_pib_data_parity_err : 1;
        uint64_t ocb_pib_addr_parity_err : 1;
        uint64_t ocb_db_oci_slave_error : 1;
        uint64_t ocb_db_oci_read_data_parity : 1;
        uint64_t ocb_db_oci_timeout : 1;
        uint64_t ppc405_dbgstopack : 1;
        uint64_t ppc405_dbgmsrwe : 1;
        uint64_t ppc405_system_reset : 1;
        uint64_t ppc405_chip_reset : 1;
        uint64_t ppc405_core_reset : 1;
        uint64_t external_trap : 1;
        uint64_t gpe3_halted : 1;
        uint64_t gpe2_halted : 1;
        uint64_t gpe1_halted : 1;
        uint64_t gpe0_halted : 1;
        uint64_t srt_oci_addr_parity_err : 1;
        uint64_t srt_oci_be_parity_err : 1;
        uint64_t srt_oci_write_data_parity : 1;
        uint64_t srt_dataout_perr : 1;
        uint64_t srt_write_error : 1;
        uint64_t srt_read_error : 1;
        uint64_t srt_ce : 1;
        uint64_t srt_ue : 1;
        uint64_t ocb_error : 1;
        uint64_t gpe3_error : 1;
        uint64_t gpe2_error : 1;
        uint64_t gpe1_error : 1;
        uint64_t gpe0_error : 1;
        uint64_t gpe3_watchdog_timeout : 1;
        uint64_t gpe2_watchdog_timeout : 1;
        uint64_t gpe1_watchdog_timeout : 1;
        uint64_t gpe0_watchdog_timeout : 1;
        uint64_t occ_hb_error : 1;
        uint64_t stop_recovery_notify_prd : 1;
        uint64_t cme_error_notify : 1;
        uint64_t occ_fw1 : 1;
        uint64_t occ_fw0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_occlfir_and_t;



typedef union ocb_occlfir_or
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
        uint64_t occ_fw0 : 1;
        uint64_t occ_fw1 : 1;
        uint64_t cme_error_notify : 1;
        uint64_t stop_recovery_notify_prd : 1;
        uint64_t occ_hb_error : 1;
        uint64_t gpe0_watchdog_timeout : 1;
        uint64_t gpe1_watchdog_timeout : 1;
        uint64_t gpe2_watchdog_timeout : 1;
        uint64_t gpe3_watchdog_timeout : 1;
        uint64_t gpe0_error : 1;
        uint64_t gpe1_error : 1;
        uint64_t gpe2_error : 1;
        uint64_t gpe3_error : 1;
        uint64_t ocb_error : 1;
        uint64_t srt_ue : 1;
        uint64_t srt_ce : 1;
        uint64_t srt_read_error : 1;
        uint64_t srt_write_error : 1;
        uint64_t srt_dataout_perr : 1;
        uint64_t srt_oci_write_data_parity : 1;
        uint64_t srt_oci_be_parity_err : 1;
        uint64_t srt_oci_addr_parity_err : 1;
        uint64_t gpe0_halted : 1;
        uint64_t gpe1_halted : 1;
        uint64_t gpe2_halted : 1;
        uint64_t gpe3_halted : 1;
        uint64_t external_trap : 1;
        uint64_t ppc405_core_reset : 1;
        uint64_t ppc405_chip_reset : 1;
        uint64_t ppc405_system_reset : 1;
        uint64_t ppc405_dbgmsrwe : 1;
        uint64_t ppc405_dbgstopack : 1;
        uint64_t ocb_db_oci_timeout : 1;
        uint64_t ocb_db_oci_read_data_parity : 1;
        uint64_t ocb_db_oci_slave_error : 1;
        uint64_t ocb_pib_addr_parity_err : 1;
        uint64_t ocb_db_pib_data_parity_err : 1;
        uint64_t ocb_idc0_error : 1;
        uint64_t ocb_idc1_error : 1;
        uint64_t ocb_idc2_error : 1;
        uint64_t ocb_idc3_error : 1;
        uint64_t srt_fsm_err : 1;
        uint64_t jtagacc_err : 1;
        uint64_t spare_err_38 : 1;
        uint64_t c405_ecc_ue : 1;
        uint64_t c405_ecc_ce : 1;
        uint64_t c405_oci_machinecheck : 1;
        uint64_t sram_spare_direct_error0 : 1;
        uint64_t sram_spare_direct_error1 : 1;
        uint64_t sram_spare_direct_error2 : 1;
        uint64_t sram_spare_direct_error3 : 1;
        uint64_t gpe0_ocislv_err : 1;
        uint64_t gpe1_ocislv_err : 1;
        uint64_t gpe2_ocislv_err : 1;
        uint64_t gpe3_ocislv_err : 1;
        uint64_t c405icu_m_timeout : 1;
        uint64_t c405dcu_m_timeout : 1;
        uint64_t occ_complex_fault_safe : 1;
        uint64_t spare_58_61 : 4;
        uint64_t fir_parity_err_dup : 1;
        uint64_t fir_parity_err : 1;
#else
        uint64_t fir_parity_err : 1;
        uint64_t fir_parity_err_dup : 1;
        uint64_t spare_58_61 : 4;
        uint64_t occ_complex_fault_safe : 1;
        uint64_t c405dcu_m_timeout : 1;
        uint64_t c405icu_m_timeout : 1;
        uint64_t gpe3_ocislv_err : 1;
        uint64_t gpe2_ocislv_err : 1;
        uint64_t gpe1_ocislv_err : 1;
        uint64_t gpe0_ocislv_err : 1;
        uint64_t sram_spare_direct_error3 : 1;
        uint64_t sram_spare_direct_error2 : 1;
        uint64_t sram_spare_direct_error1 : 1;
        uint64_t sram_spare_direct_error0 : 1;
        uint64_t c405_oci_machinecheck : 1;
        uint64_t c405_ecc_ce : 1;
        uint64_t c405_ecc_ue : 1;
        uint64_t spare_err_38 : 1;
        uint64_t jtagacc_err : 1;
        uint64_t srt_fsm_err : 1;
        uint64_t ocb_idc3_error : 1;
        uint64_t ocb_idc2_error : 1;
        uint64_t ocb_idc1_error : 1;
        uint64_t ocb_idc0_error : 1;
        uint64_t ocb_db_pib_data_parity_err : 1;
        uint64_t ocb_pib_addr_parity_err : 1;
        uint64_t ocb_db_oci_slave_error : 1;
        uint64_t ocb_db_oci_read_data_parity : 1;
        uint64_t ocb_db_oci_timeout : 1;
        uint64_t ppc405_dbgstopack : 1;
        uint64_t ppc405_dbgmsrwe : 1;
        uint64_t ppc405_system_reset : 1;
        uint64_t ppc405_chip_reset : 1;
        uint64_t ppc405_core_reset : 1;
        uint64_t external_trap : 1;
        uint64_t gpe3_halted : 1;
        uint64_t gpe2_halted : 1;
        uint64_t gpe1_halted : 1;
        uint64_t gpe0_halted : 1;
        uint64_t srt_oci_addr_parity_err : 1;
        uint64_t srt_oci_be_parity_err : 1;
        uint64_t srt_oci_write_data_parity : 1;
        uint64_t srt_dataout_perr : 1;
        uint64_t srt_write_error : 1;
        uint64_t srt_read_error : 1;
        uint64_t srt_ce : 1;
        uint64_t srt_ue : 1;
        uint64_t ocb_error : 1;
        uint64_t gpe3_error : 1;
        uint64_t gpe2_error : 1;
        uint64_t gpe1_error : 1;
        uint64_t gpe0_error : 1;
        uint64_t gpe3_watchdog_timeout : 1;
        uint64_t gpe2_watchdog_timeout : 1;
        uint64_t gpe1_watchdog_timeout : 1;
        uint64_t gpe0_watchdog_timeout : 1;
        uint64_t occ_hb_error : 1;
        uint64_t stop_recovery_notify_prd : 1;
        uint64_t cme_error_notify : 1;
        uint64_t occ_fw1 : 1;
        uint64_t occ_fw0 : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_occlfir_or_t;



typedef union ocb_occlfirmask
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
        uint64_t occ_fw0_mask : 1;
        uint64_t occ_fw1_mask : 1;
        uint64_t spare_2_mask : 1;
        uint64_t spare_3_mask : 1;
        uint64_t occ_hb_malf_mask : 1;
        uint64_t gpe0_watchdog_timeout_mask : 1;
        uint64_t gpe1_watchdog_timeout_mask : 1;
        uint64_t gpe2_watchdog_timeout_mask : 1;
        uint64_t gpe3_watchdog_timeout_mask : 1;
        uint64_t gpe0_error_mask : 1;
        uint64_t gpe1_error_mask : 1;
        uint64_t gpe2_error_mask : 1;
        uint64_t gpe3_error_mask : 1;
        uint64_t ocb_error_mask : 1;
        uint64_t srt_ue_mask : 1;
        uint64_t srt_ce_mask : 1;
        uint64_t srt_read_error_mask : 1;
        uint64_t srt_write_error_mask : 1;
        uint64_t srt_dataout_perr_mask : 1;
        uint64_t srt_oci_write_data_parity_mask : 1;
        uint64_t srt_oci_be_parity_err_mask : 1;
        uint64_t srt_oci_addr_parity_err_mask : 1;
        uint64_t gpe0_halted_mask : 1;
        uint64_t gpe1_halted_mask : 1;
        uint64_t gpe2_halted_mask : 1;
        uint64_t gpe3_halted_mask : 1;
        uint64_t external_trap_mask : 1;
        uint64_t ppc405_core_reset_mask : 1;
        uint64_t ppc405_chip_reset_mask : 1;
        uint64_t ppc405_system_reset_mask : 1;
        uint64_t ppc405_dbgmsrwe_mask : 1;
        uint64_t ppc405_dbgstopack_mask : 1;
        uint64_t ocb_db_oci_timeout_mask : 1;
        uint64_t ocb_db_oci_read_data_parity_mask : 1;
        uint64_t ocb_db_oci_slave_error_mask : 1;
        uint64_t ocb_pib_addr_parity_err_mask : 1;
        uint64_t ocb_db_pib_data_parity_err_mask : 1;
        uint64_t ocb_idc0_error_mask : 1;
        uint64_t ocb_idc1_error_mask : 1;
        uint64_t ocb_idc2_error_mask : 1;
        uint64_t ocb_idc3_error_mask : 1;
        uint64_t srt_fsm_err_mask : 1;
        uint64_t jtagacc_err_mask : 1;
        uint64_t spare_err_38_mask : 1;
        uint64_t c405_ecc_ue_mask : 1;
        uint64_t c405_ecc_ce_mask : 1;
        uint64_t c405_oci_machinecheck_mask : 1;
        uint64_t sram_spare_direct_error0_mask : 1;
        uint64_t sram_spare_direct_error1_mask : 1;
        uint64_t sram_spare_direct_error2_mask : 1;
        uint64_t sram_spare_direct_error3_mask : 1;
        uint64_t gpe0_ocislv_err_mask : 1;
        uint64_t gpe1_ocislv_err_mask : 1;
        uint64_t gpe2_ocislv_err_mask : 1;
        uint64_t gpe3_ocislv_err_mask : 1;
        uint64_t c405icu_m_timeout_mask : 1;
        uint64_t c405dcu_m_timeout_mask : 1;
        uint64_t occ_complex_fault_safe_mask : 1;
        uint64_t spare_58_61_mask : 4;
        uint64_t fir_parity_err_dup_mask : 1;
        uint64_t fir_parity_err_mask : 1;
#else
        uint64_t fir_parity_err_mask : 1;
        uint64_t fir_parity_err_dup_mask : 1;
        uint64_t spare_58_61_mask : 4;
        uint64_t occ_complex_fault_safe_mask : 1;
        uint64_t c405dcu_m_timeout_mask : 1;
        uint64_t c405icu_m_timeout_mask : 1;
        uint64_t gpe3_ocislv_err_mask : 1;
        uint64_t gpe2_ocislv_err_mask : 1;
        uint64_t gpe1_ocislv_err_mask : 1;
        uint64_t gpe0_ocislv_err_mask : 1;
        uint64_t sram_spare_direct_error3_mask : 1;
        uint64_t sram_spare_direct_error2_mask : 1;
        uint64_t sram_spare_direct_error1_mask : 1;
        uint64_t sram_spare_direct_error0_mask : 1;
        uint64_t c405_oci_machinecheck_mask : 1;
        uint64_t c405_ecc_ce_mask : 1;
        uint64_t c405_ecc_ue_mask : 1;
        uint64_t spare_err_38_mask : 1;
        uint64_t jtagacc_err_mask : 1;
        uint64_t srt_fsm_err_mask : 1;
        uint64_t ocb_idc3_error_mask : 1;
        uint64_t ocb_idc2_error_mask : 1;
        uint64_t ocb_idc1_error_mask : 1;
        uint64_t ocb_idc0_error_mask : 1;
        uint64_t ocb_db_pib_data_parity_err_mask : 1;
        uint64_t ocb_pib_addr_parity_err_mask : 1;
        uint64_t ocb_db_oci_slave_error_mask : 1;
        uint64_t ocb_db_oci_read_data_parity_mask : 1;
        uint64_t ocb_db_oci_timeout_mask : 1;
        uint64_t ppc405_dbgstopack_mask : 1;
        uint64_t ppc405_dbgmsrwe_mask : 1;
        uint64_t ppc405_system_reset_mask : 1;
        uint64_t ppc405_chip_reset_mask : 1;
        uint64_t ppc405_core_reset_mask : 1;
        uint64_t external_trap_mask : 1;
        uint64_t gpe3_halted_mask : 1;
        uint64_t gpe2_halted_mask : 1;
        uint64_t gpe1_halted_mask : 1;
        uint64_t gpe0_halted_mask : 1;
        uint64_t srt_oci_addr_parity_err_mask : 1;
        uint64_t srt_oci_be_parity_err_mask : 1;
        uint64_t srt_oci_write_data_parity_mask : 1;
        uint64_t srt_dataout_perr_mask : 1;
        uint64_t srt_write_error_mask : 1;
        uint64_t srt_read_error_mask : 1;
        uint64_t srt_ce_mask : 1;
        uint64_t srt_ue_mask : 1;
        uint64_t ocb_error_mask : 1;
        uint64_t gpe3_error_mask : 1;
        uint64_t gpe2_error_mask : 1;
        uint64_t gpe1_error_mask : 1;
        uint64_t gpe0_error_mask : 1;
        uint64_t gpe3_watchdog_timeout_mask : 1;
        uint64_t gpe2_watchdog_timeout_mask : 1;
        uint64_t gpe1_watchdog_timeout_mask : 1;
        uint64_t gpe0_watchdog_timeout_mask : 1;
        uint64_t occ_hb_malf_mask : 1;
        uint64_t spare_3_mask : 1;
        uint64_t spare_2_mask : 1;
        uint64_t occ_fw1_mask : 1;
        uint64_t occ_fw0_mask : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_occlfirmask_t;



typedef union ocb_occlfirmask_and
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
        uint64_t occ_fw0_mask : 1;
        uint64_t occ_fw1_mask : 1;
        uint64_t spare_2_mask : 1;
        uint64_t spare_3_mask : 1;
        uint64_t occ_hb_malf_mask : 1;
        uint64_t gpe0_watchdog_timeout_mask : 1;
        uint64_t gpe1_watchdog_timeout_mask : 1;
        uint64_t gpe2_watchdog_timeout_mask : 1;
        uint64_t gpe3_watchdog_timeout_mask : 1;
        uint64_t gpe0_error_mask : 1;
        uint64_t gpe1_error_mask : 1;
        uint64_t gpe2_error_mask : 1;
        uint64_t gpe3_error_mask : 1;
        uint64_t ocb_error_mask : 1;
        uint64_t srt_ue_mask : 1;
        uint64_t srt_ce_mask : 1;
        uint64_t srt_read_error_mask : 1;
        uint64_t srt_write_error_mask : 1;
        uint64_t srt_dataout_perr_mask : 1;
        uint64_t srt_oci_write_data_parity_mask : 1;
        uint64_t srt_oci_be_parity_err_mask : 1;
        uint64_t srt_oci_addr_parity_err_mask : 1;
        uint64_t gpe0_halted_mask : 1;
        uint64_t gpe1_halted_mask : 1;
        uint64_t gpe2_halted_mask : 1;
        uint64_t gpe3_halted_mask : 1;
        uint64_t external_trap_mask : 1;
        uint64_t ppc405_core_reset_mask : 1;
        uint64_t ppc405_chip_reset_mask : 1;
        uint64_t ppc405_system_reset_mask : 1;
        uint64_t ppc405_dbgmsrwe_mask : 1;
        uint64_t ppc405_dbgstopack_mask : 1;
        uint64_t ocb_db_oci_timeout_mask : 1;
        uint64_t ocb_db_oci_read_data_parity_mask : 1;
        uint64_t ocb_db_oci_slave_error_mask : 1;
        uint64_t ocb_pib_addr_parity_err_mask : 1;
        uint64_t ocb_db_pib_data_parity_err_mask : 1;
        uint64_t ocb_idc0_error_mask : 1;
        uint64_t ocb_idc1_error_mask : 1;
        uint64_t ocb_idc2_error_mask : 1;
        uint64_t ocb_idc3_error_mask : 1;
        uint64_t srt_fsm_err_mask : 1;
        uint64_t jtagacc_err_mask : 1;
        uint64_t spare_err_38_mask : 1;
        uint64_t c405_ecc_ue_mask : 1;
        uint64_t c405_ecc_ce_mask : 1;
        uint64_t c405_oci_machinecheck_mask : 1;
        uint64_t sram_spare_direct_error0_mask : 1;
        uint64_t sram_spare_direct_error1_mask : 1;
        uint64_t sram_spare_direct_error2_mask : 1;
        uint64_t sram_spare_direct_error3_mask : 1;
        uint64_t gpe0_ocislv_err_mask : 1;
        uint64_t gpe1_ocislv_err_mask : 1;
        uint64_t gpe2_ocislv_err_mask : 1;
        uint64_t gpe3_ocislv_err_mask : 1;
        uint64_t c405icu_m_timeout_mask : 1;
        uint64_t c405dcu_m_timeout_mask : 1;
        uint64_t occ_complex_fault_safe_mask : 1;
        uint64_t spare_58_61_mask : 4;
        uint64_t fir_parity_err_dup_mask : 1;
        uint64_t fir_parity_err_mask : 1;
#else
        uint64_t fir_parity_err_mask : 1;
        uint64_t fir_parity_err_dup_mask : 1;
        uint64_t spare_58_61_mask : 4;
        uint64_t occ_complex_fault_safe_mask : 1;
        uint64_t c405dcu_m_timeout_mask : 1;
        uint64_t c405icu_m_timeout_mask : 1;
        uint64_t gpe3_ocislv_err_mask : 1;
        uint64_t gpe2_ocislv_err_mask : 1;
        uint64_t gpe1_ocislv_err_mask : 1;
        uint64_t gpe0_ocislv_err_mask : 1;
        uint64_t sram_spare_direct_error3_mask : 1;
        uint64_t sram_spare_direct_error2_mask : 1;
        uint64_t sram_spare_direct_error1_mask : 1;
        uint64_t sram_spare_direct_error0_mask : 1;
        uint64_t c405_oci_machinecheck_mask : 1;
        uint64_t c405_ecc_ce_mask : 1;
        uint64_t c405_ecc_ue_mask : 1;
        uint64_t spare_err_38_mask : 1;
        uint64_t jtagacc_err_mask : 1;
        uint64_t srt_fsm_err_mask : 1;
        uint64_t ocb_idc3_error_mask : 1;
        uint64_t ocb_idc2_error_mask : 1;
        uint64_t ocb_idc1_error_mask : 1;
        uint64_t ocb_idc0_error_mask : 1;
        uint64_t ocb_db_pib_data_parity_err_mask : 1;
        uint64_t ocb_pib_addr_parity_err_mask : 1;
        uint64_t ocb_db_oci_slave_error_mask : 1;
        uint64_t ocb_db_oci_read_data_parity_mask : 1;
        uint64_t ocb_db_oci_timeout_mask : 1;
        uint64_t ppc405_dbgstopack_mask : 1;
        uint64_t ppc405_dbgmsrwe_mask : 1;
        uint64_t ppc405_system_reset_mask : 1;
        uint64_t ppc405_chip_reset_mask : 1;
        uint64_t ppc405_core_reset_mask : 1;
        uint64_t external_trap_mask : 1;
        uint64_t gpe3_halted_mask : 1;
        uint64_t gpe2_halted_mask : 1;
        uint64_t gpe1_halted_mask : 1;
        uint64_t gpe0_halted_mask : 1;
        uint64_t srt_oci_addr_parity_err_mask : 1;
        uint64_t srt_oci_be_parity_err_mask : 1;
        uint64_t srt_oci_write_data_parity_mask : 1;
        uint64_t srt_dataout_perr_mask : 1;
        uint64_t srt_write_error_mask : 1;
        uint64_t srt_read_error_mask : 1;
        uint64_t srt_ce_mask : 1;
        uint64_t srt_ue_mask : 1;
        uint64_t ocb_error_mask : 1;
        uint64_t gpe3_error_mask : 1;
        uint64_t gpe2_error_mask : 1;
        uint64_t gpe1_error_mask : 1;
        uint64_t gpe0_error_mask : 1;
        uint64_t gpe3_watchdog_timeout_mask : 1;
        uint64_t gpe2_watchdog_timeout_mask : 1;
        uint64_t gpe1_watchdog_timeout_mask : 1;
        uint64_t gpe0_watchdog_timeout_mask : 1;
        uint64_t occ_hb_malf_mask : 1;
        uint64_t spare_3_mask : 1;
        uint64_t spare_2_mask : 1;
        uint64_t occ_fw1_mask : 1;
        uint64_t occ_fw0_mask : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_occlfirmask_and_t;



typedef union ocb_occlfirmask_or
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
        uint64_t occ_fw0_mask : 1;
        uint64_t occ_fw1_mask : 1;
        uint64_t spare_2_mask : 1;
        uint64_t spare_3_mask : 1;
        uint64_t occ_hb_malf_mask : 1;
        uint64_t gpe0_watchdog_timeout_mask : 1;
        uint64_t gpe1_watchdog_timeout_mask : 1;
        uint64_t gpe2_watchdog_timeout_mask : 1;
        uint64_t gpe3_watchdog_timeout_mask : 1;
        uint64_t gpe0_error_mask : 1;
        uint64_t gpe1_error_mask : 1;
        uint64_t gpe2_error_mask : 1;
        uint64_t gpe3_error_mask : 1;
        uint64_t ocb_error_mask : 1;
        uint64_t srt_ue_mask : 1;
        uint64_t srt_ce_mask : 1;
        uint64_t srt_read_error_mask : 1;
        uint64_t srt_write_error_mask : 1;
        uint64_t srt_dataout_perr_mask : 1;
        uint64_t srt_oci_write_data_parity_mask : 1;
        uint64_t srt_oci_be_parity_err_mask : 1;
        uint64_t srt_oci_addr_parity_err_mask : 1;
        uint64_t gpe0_halted_mask : 1;
        uint64_t gpe1_halted_mask : 1;
        uint64_t gpe2_halted_mask : 1;
        uint64_t gpe3_halted_mask : 1;
        uint64_t external_trap_mask : 1;
        uint64_t ppc405_core_reset_mask : 1;
        uint64_t ppc405_chip_reset_mask : 1;
        uint64_t ppc405_system_reset_mask : 1;
        uint64_t ppc405_dbgmsrwe_mask : 1;
        uint64_t ppc405_dbgstopack_mask : 1;
        uint64_t ocb_db_oci_timeout_mask : 1;
        uint64_t ocb_db_oci_read_data_parity_mask : 1;
        uint64_t ocb_db_oci_slave_error_mask : 1;
        uint64_t ocb_pib_addr_parity_err_mask : 1;
        uint64_t ocb_db_pib_data_parity_err_mask : 1;
        uint64_t ocb_idc0_error_mask : 1;
        uint64_t ocb_idc1_error_mask : 1;
        uint64_t ocb_idc2_error_mask : 1;
        uint64_t ocb_idc3_error_mask : 1;
        uint64_t srt_fsm_err_mask : 1;
        uint64_t jtagacc_err_mask : 1;
        uint64_t spare_err_38_mask : 1;
        uint64_t c405_ecc_ue_mask : 1;
        uint64_t c405_ecc_ce_mask : 1;
        uint64_t c405_oci_machinecheck_mask : 1;
        uint64_t sram_spare_direct_error0_mask : 1;
        uint64_t sram_spare_direct_error1_mask : 1;
        uint64_t sram_spare_direct_error2_mask : 1;
        uint64_t sram_spare_direct_error3_mask : 1;
        uint64_t gpe0_ocislv_err_mask : 1;
        uint64_t gpe1_ocislv_err_mask : 1;
        uint64_t gpe2_ocislv_err_mask : 1;
        uint64_t gpe3_ocislv_err_mask : 1;
        uint64_t c405icu_m_timeout_mask : 1;
        uint64_t c405dcu_m_timeout_mask : 1;
        uint64_t occ_complex_fault_safe_mask : 1;
        uint64_t spare_58_61_mask : 4;
        uint64_t fir_parity_err_dup_mask : 1;
        uint64_t fir_parity_err_mask : 1;
#else
        uint64_t fir_parity_err_mask : 1;
        uint64_t fir_parity_err_dup_mask : 1;
        uint64_t spare_58_61_mask : 4;
        uint64_t occ_complex_fault_safe_mask : 1;
        uint64_t c405dcu_m_timeout_mask : 1;
        uint64_t c405icu_m_timeout_mask : 1;
        uint64_t gpe3_ocislv_err_mask : 1;
        uint64_t gpe2_ocislv_err_mask : 1;
        uint64_t gpe1_ocislv_err_mask : 1;
        uint64_t gpe0_ocislv_err_mask : 1;
        uint64_t sram_spare_direct_error3_mask : 1;
        uint64_t sram_spare_direct_error2_mask : 1;
        uint64_t sram_spare_direct_error1_mask : 1;
        uint64_t sram_spare_direct_error0_mask : 1;
        uint64_t c405_oci_machinecheck_mask : 1;
        uint64_t c405_ecc_ce_mask : 1;
        uint64_t c405_ecc_ue_mask : 1;
        uint64_t spare_err_38_mask : 1;
        uint64_t jtagacc_err_mask : 1;
        uint64_t srt_fsm_err_mask : 1;
        uint64_t ocb_idc3_error_mask : 1;
        uint64_t ocb_idc2_error_mask : 1;
        uint64_t ocb_idc1_error_mask : 1;
        uint64_t ocb_idc0_error_mask : 1;
        uint64_t ocb_db_pib_data_parity_err_mask : 1;
        uint64_t ocb_pib_addr_parity_err_mask : 1;
        uint64_t ocb_db_oci_slave_error_mask : 1;
        uint64_t ocb_db_oci_read_data_parity_mask : 1;
        uint64_t ocb_db_oci_timeout_mask : 1;
        uint64_t ppc405_dbgstopack_mask : 1;
        uint64_t ppc405_dbgmsrwe_mask : 1;
        uint64_t ppc405_system_reset_mask : 1;
        uint64_t ppc405_chip_reset_mask : 1;
        uint64_t ppc405_core_reset_mask : 1;
        uint64_t external_trap_mask : 1;
        uint64_t gpe3_halted_mask : 1;
        uint64_t gpe2_halted_mask : 1;
        uint64_t gpe1_halted_mask : 1;
        uint64_t gpe0_halted_mask : 1;
        uint64_t srt_oci_addr_parity_err_mask : 1;
        uint64_t srt_oci_be_parity_err_mask : 1;
        uint64_t srt_oci_write_data_parity_mask : 1;
        uint64_t srt_dataout_perr_mask : 1;
        uint64_t srt_write_error_mask : 1;
        uint64_t srt_read_error_mask : 1;
        uint64_t srt_ce_mask : 1;
        uint64_t srt_ue_mask : 1;
        uint64_t ocb_error_mask : 1;
        uint64_t gpe3_error_mask : 1;
        uint64_t gpe2_error_mask : 1;
        uint64_t gpe1_error_mask : 1;
        uint64_t gpe0_error_mask : 1;
        uint64_t gpe3_watchdog_timeout_mask : 1;
        uint64_t gpe2_watchdog_timeout_mask : 1;
        uint64_t gpe1_watchdog_timeout_mask : 1;
        uint64_t gpe0_watchdog_timeout_mask : 1;
        uint64_t occ_hb_malf_mask : 1;
        uint64_t spare_3_mask : 1;
        uint64_t spare_2_mask : 1;
        uint64_t occ_fw1_mask : 1;
        uint64_t occ_fw0_mask : 1;
#endif // _BIG_ENDIAN
    } fields;
} ocb_occlfirmask_or_t;



typedef union ocb_occlfiract0
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
        uint64_t fir_action0 : 64;
#else
        uint64_t fir_action0 : 64;
#endif // _BIG_ENDIAN
    } fields;
} ocb_occlfiract0_t;



typedef union ocb_occlfiract1
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
        uint64_t fir_action1 : 64;
#else
        uint64_t fir_action1 : 64;
#endif // _BIG_ENDIAN
    } fields;
} ocb_occlfiract1_t;



typedef union ocb_occlfirwof
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
        uint64_t wof : 64;
#else
        uint64_t wof : 64;
#endif // _BIG_ENDIAN
    } fields;
} ocb_occlfirwof_t;



typedef union ocb_occerrrpt
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
        uint64_t sram_cerrrpt : 10;
        uint64_t jtagacc_cerrpt : 6;
        uint64_t c405_dcu_ecc_ue : 1;
        uint64_t c405_dcu_ecc_ce : 1;
        uint64_t c405_icu_ecc_ue : 1;
        uint64_t c405_icu_ecc_ce : 1;
        uint64_t gpe0_ocislv_err : 7;
        uint64_t reserved1 : 1;
        uint64_t gpe1_ocislv_err : 7;
        uint64_t reserved2 : 1;
        uint64_t gpe2_ocislv_err : 7;
        uint64_t reserved3 : 1;
        uint64_t gpe3_ocislv_err : 7;
        uint64_t reserved4 : 1;
        uint64_t ocb_ocislv_err : 7;
        uint64_t reserved5 : 5;
#else
        uint64_t reserved5 : 5;
        uint64_t ocb_ocislv_err : 7;
        uint64_t reserved4 : 1;
        uint64_t gpe3_ocislv_err : 7;
        uint64_t reserved3 : 1;
        uint64_t gpe2_ocislv_err : 7;
        uint64_t reserved2 : 1;
        uint64_t gpe1_ocislv_err : 7;
        uint64_t reserved1 : 1;
        uint64_t gpe0_ocislv_err : 7;
        uint64_t c405_icu_ecc_ce : 1;
        uint64_t c405_icu_ecc_ue : 1;
        uint64_t c405_dcu_ecc_ce : 1;
        uint64_t c405_dcu_ecc_ue : 1;
        uint64_t jtagacc_cerrpt : 6;
        uint64_t sram_cerrrpt : 10;
#endif // _BIG_ENDIAN
    } fields;
} ocb_occerrrpt_t;


#endif // __ASSEMBLER__
#endif // P9_OCB_FIRMWARE_REGISTERS_H__

