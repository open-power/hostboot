/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/common/pmlib/include/registers/pba_firmware_registers.h $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef __PBA_FIRMWARE_REGISTERS_H__
#define __PBA_FIRMWARE_REGISTERS_H__

// $Id$
// $Source$
//-----------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2015
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//-----------------------------------------------------------------------------

/// \file pba_firmware_registers.h
/// \brief C register structs for the PBA unit

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
#include "pba_firmware_constants.h"



typedef union pba_mode
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
        uint64_t reserved1 : 4;
        uint64_t dis_rearb : 1;
        uint64_t dis_mstid_match_pref_inv : 1;
        uint64_t dis_slave_rdpipe : 1;
        uint64_t dis_slave_wrpipe : 1;
        uint64_t en_marker_ack : 1;
        uint64_t reserved2 : 1;
        uint64_t en_second_wrbuf : 1;
        uint64_t dis_rerequest_to : 1;
        uint64_t inject_type : 2;
        uint64_t inject_mode : 2;
        uint64_t pba_region : 2;
        uint64_t oci_marker_space : 3;
        uint64_t bcde_ocitrans : 2;
        uint64_t bcue_ocitrans : 2;
        uint64_t dis_master_rd_pipe : 1;
        uint64_t dis_master_wr_pipe : 1;
        uint64_t en_slv_fairness : 1;
        uint64_t en_event_count : 1;
        uint64_t pb_noci_event_sel : 1;
        uint64_t slv_event_mux : 2;
        uint64_t enable_debug_bus : 1;
        uint64_t debug_pb_not_oci : 1;
        uint64_t debug_oci_mode : 5;
        uint64_t reserved3 : 1;
        uint64_t ocislv_fairness_mask : 5;
        uint64_t ocislv_rereq_hang_div : 5;
        uint64_t dis_chgrate_count : 1;
        uint64_t pbreq_event_mux : 2;
        uint64_t reserved4 : 11;
#else
        uint64_t reserved4 : 11;
        uint64_t pbreq_event_mux : 2;
        uint64_t dis_chgrate_count : 1;
        uint64_t ocislv_rereq_hang_div : 5;
        uint64_t ocislv_fairness_mask : 5;
        uint64_t reserved3 : 1;
        uint64_t debug_oci_mode : 5;
        uint64_t debug_pb_not_oci : 1;
        uint64_t enable_debug_bus : 1;
        uint64_t slv_event_mux : 2;
        uint64_t pb_noci_event_sel : 1;
        uint64_t en_event_count : 1;
        uint64_t en_slv_fairness : 1;
        uint64_t dis_master_wr_pipe : 1;
        uint64_t dis_master_rd_pipe : 1;
        uint64_t bcue_ocitrans : 2;
        uint64_t bcde_ocitrans : 2;
        uint64_t oci_marker_space : 3;
        uint64_t pba_region : 2;
        uint64_t inject_mode : 2;
        uint64_t inject_type : 2;
        uint64_t dis_rerequest_to : 1;
        uint64_t en_second_wrbuf : 1;
        uint64_t reserved2 : 1;
        uint64_t en_marker_ack : 1;
        uint64_t dis_slave_wrpipe : 1;
        uint64_t dis_slave_rdpipe : 1;
        uint64_t dis_mstid_match_pref_inv : 1;
        uint64_t dis_rearb : 1;
        uint64_t reserved1 : 4;
#endif // _BIG_ENDIAN
    } fields;
} pba_mode_t;



typedef union pba_slvrst
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
        uint64_t set : 3;
        uint64_t reserved1 : 1;
        uint64_t in_prog : 4;
        uint64_t busy_status : 4;
        uint64_t scope_attn_bar : 2;
        uint64_t reserved2 : 50;
#else
        uint64_t reserved2 : 50;
        uint64_t scope_attn_bar : 2;
        uint64_t busy_status : 4;
        uint64_t in_prog : 4;
        uint64_t reserved1 : 1;
        uint64_t set : 3;
#endif // _BIG_ENDIAN
    } fields;
} pba_slvrst_t;



typedef union pba_slvctln
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
        uint64_t enable : 1;
        uint64_t mid_match_value : 3;
        uint64_t reserved1 : 1;
        uint64_t mid_care_mask : 3;
        uint64_t write_ttype : 3;
        uint64_t reserved2 : 4;
        uint64_t read_ttype : 1;
        uint64_t read_prefetch_ctl : 2;
        uint64_t buf_invalidate_ctl : 1;
        uint64_t buf_alloc_w : 1;
        uint64_t buf_alloc_a : 1;
        uint64_t buf_alloc_b : 1;
        uint64_t buf_alloc_c : 1;
        uint64_t reserved3 : 1;
        uint64_t dis_write_gather : 1;
        uint64_t wr_gather_timeout : 3;
        uint64_t write_tsize : 8;
        uint64_t extaddr : 14;
        uint64_t reserved4 : 1;
        uint64_t reserved5 : 13;
#else
        uint64_t reserved5 : 13;
        uint64_t reserved4 : 1;
        uint64_t extaddr : 14;
        uint64_t write_tsize : 8;
        uint64_t wr_gather_timeout : 3;
        uint64_t dis_write_gather : 1;
        uint64_t reserved3 : 1;
        uint64_t buf_alloc_c : 1;
        uint64_t buf_alloc_b : 1;
        uint64_t buf_alloc_a : 1;
        uint64_t buf_alloc_w : 1;
        uint64_t buf_invalidate_ctl : 1;
        uint64_t read_prefetch_ctl : 2;
        uint64_t read_ttype : 1;
        uint64_t reserved2 : 4;
        uint64_t write_ttype : 3;
        uint64_t mid_care_mask : 3;
        uint64_t reserved1 : 1;
        uint64_t mid_match_value : 3;
        uint64_t enable : 1;
#endif // _BIG_ENDIAN
    } fields;
} pba_slvctln_t;



typedef union pba_bcde_ctl
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
        uint64_t stop : 1;
        uint64_t start : 1;
        uint64_t reserved1 : 62;
#else
        uint64_t reserved1 : 62;
        uint64_t start : 1;
        uint64_t stop : 1;
#endif // _BIG_ENDIAN
    } fields;
} pba_bcde_ctl_t;



typedef union pba_bcde_set
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
        uint64_t reserved1 : 2;
        uint64_t copy_length : 6;
        uint64_t reserved2 : 56;
#else
        uint64_t reserved2 : 56;
        uint64_t copy_length : 6;
        uint64_t reserved1 : 2;
#endif // _BIG_ENDIAN
    } fields;
} pba_bcde_set_t;



typedef union pba_bcde_stat
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
        uint64_t running : 1;
        uint64_t waiting : 1;
        uint64_t wrcmp : 6;
        uint64_t reserved1 : 6;
        uint64_t rdcmp : 6;
        uint64_t debug : 9;
        uint64_t stopped : 1;
        uint64_t error : 1;
        uint64_t done : 1;
        uint64_t reserved2 : 32;
#else
        uint64_t reserved2 : 32;
        uint64_t done : 1;
        uint64_t error : 1;
        uint64_t stopped : 1;
        uint64_t debug : 9;
        uint64_t rdcmp : 6;
        uint64_t reserved1 : 6;
        uint64_t wrcmp : 6;
        uint64_t waiting : 1;
        uint64_t running : 1;
#endif // _BIG_ENDIAN
    } fields;
} pba_bcde_stat_t;



typedef union pba_bcde_pbadr
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
        uint64_t reserved1 : 2;
        uint64_t pb_offset : 23;
        uint64_t reserved2 : 2;
        uint64_t extaddr : 14;
        uint64_t reserved3 : 2;
        uint64_t reserved4 : 21;
#else
        uint64_t reserved4 : 21;
        uint64_t reserved3 : 2;
        uint64_t extaddr : 14;
        uint64_t reserved2 : 2;
        uint64_t pb_offset : 23;
        uint64_t reserved1 : 2;
#endif // _BIG_ENDIAN
    } fields;
} pba_bcde_pbadr_t;



typedef union pba_bcde_ocibar
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
        uint64_t addr : 25;
        uint64_t reserved1 : 39;
#else
        uint64_t reserved1 : 39;
        uint64_t addr : 25;
#endif // _BIG_ENDIAN
    } fields;
} pba_bcde_ocibar_t;



typedef union pba_bcue_ctl
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
        uint64_t stop : 1;
        uint64_t start : 1;
        uint64_t reserved1 : 62;
#else
        uint64_t reserved1 : 62;
        uint64_t start : 1;
        uint64_t stop : 1;
#endif // _BIG_ENDIAN
    } fields;
} pba_bcue_ctl_t;



typedef union pba_bcue_set
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
        uint64_t reserved1 : 2;
        uint64_t copy_length : 6;
        uint64_t reserved2 : 56;
#else
        uint64_t reserved2 : 56;
        uint64_t copy_length : 6;
        uint64_t reserved1 : 2;
#endif // _BIG_ENDIAN
    } fields;
} pba_bcue_set_t;



typedef union pba_bcue_stat
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
        uint64_t running : 1;
        uint64_t waiting : 1;
        uint64_t wrcmp : 6;
        uint64_t reserved1 : 6;
        uint64_t rdcmp : 6;
        uint64_t debug : 9;
        uint64_t stopped : 1;
        uint64_t error : 1;
        uint64_t done : 1;
        uint64_t reserved2 : 32;
#else
        uint64_t reserved2 : 32;
        uint64_t done : 1;
        uint64_t error : 1;
        uint64_t stopped : 1;
        uint64_t debug : 9;
        uint64_t rdcmp : 6;
        uint64_t reserved1 : 6;
        uint64_t wrcmp : 6;
        uint64_t waiting : 1;
        uint64_t running : 1;
#endif // _BIG_ENDIAN
    } fields;
} pba_bcue_stat_t;



typedef union pba_bcue_pbadr
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
        uint64_t reserved1 : 2;
        uint64_t pb_offset : 23;
        uint64_t reserved2 : 2;
        uint64_t extaddr : 14;
        uint64_t reserved3 : 2;
        uint64_t reserved4 : 21;
#else
        uint64_t reserved4 : 21;
        uint64_t reserved3 : 2;
        uint64_t extaddr : 14;
        uint64_t reserved2 : 2;
        uint64_t pb_offset : 23;
        uint64_t reserved1 : 2;
#endif // _BIG_ENDIAN
    } fields;
} pba_bcue_pbadr_t;



typedef union pba_bcue_ocibar
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
        uint64_t addr : 25;
        uint64_t reserved1 : 39;
#else
        uint64_t reserved1 : 39;
        uint64_t addr : 25;
#endif // _BIG_ENDIAN
    } fields;
} pba_bcue_ocibar_t;



typedef union pba_pbocrn
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
        uint64_t reserved1 : 16;
        uint64_t event : 16;
        uint64_t reserved2 : 12;
        uint64_t accum : 20;
#else
        uint64_t accum : 20;
        uint64_t reserved2 : 12;
        uint64_t event : 16;
        uint64_t reserved1 : 16;
#endif // _BIG_ENDIAN
    } fields;
} pba_pbocrn_t;



typedef union pba_xsndtx
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
        uint64_t snd_scope : 3;
        uint64_t snd_qid : 1;
        uint64_t snd_type : 1;
        uint64_t snd_reservation : 1;
        uint64_t reserved1 : 2;
        uint64_t snd_groupid : 4;
        uint64_t snd_chipid : 3;
        uint64_t reserved2 : 1;
        uint64_t vg_targe : 16;
        uint64_t reserved3 : 27;
        uint64_t snd_stop : 1;
        uint64_t snd_cnt : 4;
#else
        uint64_t snd_cnt : 4;
        uint64_t snd_stop : 1;
        uint64_t reserved3 : 27;
        uint64_t vg_targe : 16;
        uint64_t reserved2 : 1;
        uint64_t snd_chipid : 3;
        uint64_t snd_groupid : 4;
        uint64_t reserved1 : 2;
        uint64_t snd_reservation : 1;
        uint64_t snd_type : 1;
        uint64_t snd_qid : 1;
        uint64_t snd_scope : 3;
#endif // _BIG_ENDIAN
    } fields;
} pba_xsndtx_t;



typedef union pba_xcfg
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
        uint64_t pbax_en : 1;
        uint64_t reservation_en : 1;
        uint64_t snd_reset : 1;
        uint64_t rcv_reset : 1;
        uint64_t rcv_groupid : 4;
        uint64_t rcv_chipid : 3;
        uint64_t reserved1 : 1;
        uint64_t rcv_brdcst_group : 8;
        uint64_t rcv_datato_div : 5;
        uint64_t reserved2 : 2;
        uint64_t snd_retry_count_overcom : 1;
        uint64_t snd_retry_thresh : 8;
        uint64_t snd_rsvto_div : 5;
        uint64_t reserved3 : 23;
#else
        uint64_t reserved3 : 23;
        uint64_t snd_rsvto_div : 5;
        uint64_t snd_retry_thresh : 8;
        uint64_t snd_retry_count_overcom : 1;
        uint64_t reserved2 : 2;
        uint64_t rcv_datato_div : 5;
        uint64_t rcv_brdcst_group : 8;
        uint64_t reserved1 : 1;
        uint64_t rcv_chipid : 3;
        uint64_t rcv_groupid : 4;
        uint64_t rcv_reset : 1;
        uint64_t snd_reset : 1;
        uint64_t reservation_en : 1;
        uint64_t pbax_en : 1;
#endif // _BIG_ENDIAN
    } fields;
} pba_xcfg_t;



typedef union pba_xsndstat
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
        uint64_t snd_in_progress : 1;
        uint64_t snd_error : 1;
        uint64_t snd_phase_status : 2;
        uint64_t snd_cnt_status : 4;
        uint64_t snd_retry_count : 8;
        uint64_t reserved1 : 48;
#else
        uint64_t reserved1 : 48;
        uint64_t snd_retry_count : 8;
        uint64_t snd_cnt_status : 4;
        uint64_t snd_phase_status : 2;
        uint64_t snd_error : 1;
        uint64_t snd_in_progress : 1;
#endif // _BIG_ENDIAN
    } fields;
} pba_xsndstat_t;



typedef union pba_xsnddat
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
        uint64_t pbax_datahi : 32;
        uint64_t pbax_datalo : 32;
#else
        uint64_t pbax_datalo : 32;
        uint64_t pbax_datahi : 32;
#endif // _BIG_ENDIAN
    } fields;
} pba_xsnddat_t;



typedef union pba_xrcvstat
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
        uint64_t rcv_in_progress : 1;
        uint64_t rcv_error : 1;
        uint64_t rcv_write_in_progress : 1;
        uint64_t rcv_reservation_set : 1;
        uint64_t rcv_capture : 16;
        uint64_t reserved1 : 44;
#else
        uint64_t reserved1 : 44;
        uint64_t rcv_capture : 16;
        uint64_t rcv_reservation_set : 1;
        uint64_t rcv_write_in_progress : 1;
        uint64_t rcv_error : 1;
        uint64_t rcv_in_progress : 1;
#endif // _BIG_ENDIAN
    } fields;
} pba_xrcvstat_t;



typedef union pba_xshbrn
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
        uint64_t push_start : 29;
        uint64_t reserved1 : 35;
#else
        uint64_t reserved1 : 35;
        uint64_t push_start : 29;
#endif // _BIG_ENDIAN
    } fields;
} pba_xshbrn_t;



typedef union pba_xshcsn
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
        uint64_t reserved1 : 2;
        uint64_t push_intr_action : 2;
        uint64_t push_length : 5;
        uint64_t reserved2 : 2;
        uint64_t push_write_ptr : 5;
        uint64_t reserved3 : 3;
        uint64_t push_read_ptr : 5;
        uint64_t reserved4 : 5;
        uint64_t push_enable : 1;
        uint64_t reserved5 : 32;
#else
        uint64_t reserved5 : 32;
        uint64_t push_enable : 1;
        uint64_t reserved4 : 5;
        uint64_t push_read_ptr : 5;
        uint64_t reserved3 : 3;
        uint64_t push_write_ptr : 5;
        uint64_t reserved2 : 2;
        uint64_t push_length : 5;
        uint64_t push_intr_action : 2;
        uint64_t reserved1 : 2;
        uint64_t push_empty : 1;
        uint64_t push_full : 1;
#endif // _BIG_ENDIAN
    } fields;
} pba_xshcsn_t;



typedef union pba_xshincn
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
} pba_xshincn_t;



typedef union pba_fir
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
        uint64_t oci_apar_err : 1;
        uint64_t pb_rdadrerr_fw : 1;
        uint64_t pb_rddatato_fw : 1;
        uint64_t pb_sue_fw : 1;
        uint64_t pb_ue_fw : 1;
        uint64_t pb_ce_fw : 1;
        uint64_t oci_slave_init : 1;
        uint64_t oci_wrpar_err : 1;
        uint64_t reserved1 : 1;
        uint64_t pb_unexpcresp : 1;
        uint64_t pb_unexpdata : 1;
        uint64_t pb_parity_err : 1;
        uint64_t pb_wradrerr_fw : 1;
        uint64_t pb_badcresp : 1;
        uint64_t pb_ackdead_fw_rd : 1;
        uint64_t pb_operto : 1;
        uint64_t bcue_setup_err : 1;
        uint64_t bcue_pb_ack_dead : 1;
        uint64_t bcue_pb_adrerr : 1;
        uint64_t bcue_oci_daterr : 1;
        uint64_t bcde_setup_err : 1;
        uint64_t bcde_pb_ack_dead : 1;
        uint64_t bcde_pb_adrerr : 1;
        uint64_t bcde_rddatato_err : 1;
        uint64_t bcde_sue_err : 1;
        uint64_t bcde_ue_err : 1;
        uint64_t bcde_ce : 1;
        uint64_t bcde_oci_daterr : 1;
        uint64_t internal_err : 1;
        uint64_t illegal_cache_op : 1;
        uint64_t oci_bad_reg_addr : 1;
        uint64_t axpush_wrerr : 1;
        uint64_t axrcv_dlo_err : 1;
        uint64_t axrcv_dlo_to : 1;
        uint64_t axrcv_rsvdata_to : 1;
        uint64_t axflow_err : 1;
        uint64_t axsnd_dhi_rtyto : 1;
        uint64_t axsnd_dlo_rtyto : 1;
        uint64_t axsnd_rsvto : 1;
        uint64_t axsnd_rsverr : 1;
        uint64_t pb_ackdead_fw_wr : 1;
        uint64_t reserved2 : 1;
        uint64_t reserved3 : 1;
        uint64_t reserved4 : 1;
        uint64_t fir_parity_err2 : 1;
        uint64_t fir_parity_err : 1;
        uint64_t reserved5 : 18;
#else
        uint64_t reserved5 : 18;
        uint64_t fir_parity_err : 1;
        uint64_t fir_parity_err2 : 1;
        uint64_t reserved4 : 1;
        uint64_t reserved3 : 1;
        uint64_t reserved2 : 1;
        uint64_t pb_ackdead_fw_wr : 1;
        uint64_t axsnd_rsverr : 1;
        uint64_t axsnd_rsvto : 1;
        uint64_t axsnd_dlo_rtyto : 1;
        uint64_t axsnd_dhi_rtyto : 1;
        uint64_t axflow_err : 1;
        uint64_t axrcv_rsvdata_to : 1;
        uint64_t axrcv_dlo_to : 1;
        uint64_t axrcv_dlo_err : 1;
        uint64_t axpush_wrerr : 1;
        uint64_t oci_bad_reg_addr : 1;
        uint64_t illegal_cache_op : 1;
        uint64_t internal_err : 1;
        uint64_t bcde_oci_daterr : 1;
        uint64_t bcde_ce : 1;
        uint64_t bcde_ue_err : 1;
        uint64_t bcde_sue_err : 1;
        uint64_t bcde_rddatato_err : 1;
        uint64_t bcde_pb_adrerr : 1;
        uint64_t bcde_pb_ack_dead : 1;
        uint64_t bcde_setup_err : 1;
        uint64_t bcue_oci_daterr : 1;
        uint64_t bcue_pb_adrerr : 1;
        uint64_t bcue_pb_ack_dead : 1;
        uint64_t bcue_setup_err : 1;
        uint64_t pb_operto : 1;
        uint64_t pb_ackdead_fw_rd : 1;
        uint64_t pb_badcresp : 1;
        uint64_t pb_wradrerr_fw : 1;
        uint64_t pb_parity_err : 1;
        uint64_t pb_unexpdata : 1;
        uint64_t pb_unexpcresp : 1;
        uint64_t reserved1 : 1;
        uint64_t oci_wrpar_err : 1;
        uint64_t oci_slave_init : 1;
        uint64_t pb_ce_fw : 1;
        uint64_t pb_ue_fw : 1;
        uint64_t pb_sue_fw : 1;
        uint64_t pb_rddatato_fw : 1;
        uint64_t pb_rdadrerr_fw : 1;
        uint64_t oci_apar_err : 1;
#endif // _BIG_ENDIAN
    } fields;
} pba_fir_t;



typedef union pba_fir_and
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
        uint64_t oci_apar_err : 1;
        uint64_t pb_rdadrerr_fw : 1;
        uint64_t pb_rddatato_fw : 1;
        uint64_t pb_sue_fw : 1;
        uint64_t pb_ue_fw : 1;
        uint64_t pb_ce_fw : 1;
        uint64_t oci_slave_init : 1;
        uint64_t oci_wrpar_err : 1;
        uint64_t reserved1 : 1;
        uint64_t pb_unexpcresp : 1;
        uint64_t pb_unexpdata : 1;
        uint64_t pb_parity_err : 1;
        uint64_t pb_wradrerr_fw : 1;
        uint64_t pb_badcresp : 1;
        uint64_t pb_ackdead_fw_rd : 1;
        uint64_t pb_operto : 1;
        uint64_t bcue_setup_err : 1;
        uint64_t bcue_pb_ack_dead : 1;
        uint64_t bcue_pb_adrerr : 1;
        uint64_t bcue_oci_daterr : 1;
        uint64_t bcde_setup_err : 1;
        uint64_t bcde_pb_ack_dead : 1;
        uint64_t bcde_pb_adrerr : 1;
        uint64_t bcde_rddatato_err : 1;
        uint64_t bcde_sue_err : 1;
        uint64_t bcde_ue_err : 1;
        uint64_t bcde_ce : 1;
        uint64_t bcde_oci_daterr : 1;
        uint64_t internal_err : 1;
        uint64_t illegal_cache_op : 1;
        uint64_t oci_bad_reg_addr : 1;
        uint64_t axpush_wrerr : 1;
        uint64_t axrcv_dlo_err : 1;
        uint64_t axrcv_dlo_to : 1;
        uint64_t axrcv_rsvdata_to : 1;
        uint64_t axflow_err : 1;
        uint64_t axsnd_dhi_rtyto : 1;
        uint64_t axsnd_dlo_rtyto : 1;
        uint64_t axsnd_rsvto : 1;
        uint64_t axsnd_rsverr : 1;
        uint64_t pb_ackdead_fw_wr : 1;
        uint64_t reserved2 : 1;
        uint64_t reserved3 : 1;
        uint64_t reserved4 : 1;
        uint64_t fir_parity_err2 : 1;
        uint64_t fir_parity_err : 1;
        uint64_t reserved5 : 18;
#else
        uint64_t reserved5 : 18;
        uint64_t fir_parity_err : 1;
        uint64_t fir_parity_err2 : 1;
        uint64_t reserved4 : 1;
        uint64_t reserved3 : 1;
        uint64_t reserved2 : 1;
        uint64_t pb_ackdead_fw_wr : 1;
        uint64_t axsnd_rsverr : 1;
        uint64_t axsnd_rsvto : 1;
        uint64_t axsnd_dlo_rtyto : 1;
        uint64_t axsnd_dhi_rtyto : 1;
        uint64_t axflow_err : 1;
        uint64_t axrcv_rsvdata_to : 1;
        uint64_t axrcv_dlo_to : 1;
        uint64_t axrcv_dlo_err : 1;
        uint64_t axpush_wrerr : 1;
        uint64_t oci_bad_reg_addr : 1;
        uint64_t illegal_cache_op : 1;
        uint64_t internal_err : 1;
        uint64_t bcde_oci_daterr : 1;
        uint64_t bcde_ce : 1;
        uint64_t bcde_ue_err : 1;
        uint64_t bcde_sue_err : 1;
        uint64_t bcde_rddatato_err : 1;
        uint64_t bcde_pb_adrerr : 1;
        uint64_t bcde_pb_ack_dead : 1;
        uint64_t bcde_setup_err : 1;
        uint64_t bcue_oci_daterr : 1;
        uint64_t bcue_pb_adrerr : 1;
        uint64_t bcue_pb_ack_dead : 1;
        uint64_t bcue_setup_err : 1;
        uint64_t pb_operto : 1;
        uint64_t pb_ackdead_fw_rd : 1;
        uint64_t pb_badcresp : 1;
        uint64_t pb_wradrerr_fw : 1;
        uint64_t pb_parity_err : 1;
        uint64_t pb_unexpdata : 1;
        uint64_t pb_unexpcresp : 1;
        uint64_t reserved1 : 1;
        uint64_t oci_wrpar_err : 1;
        uint64_t oci_slave_init : 1;
        uint64_t pb_ce_fw : 1;
        uint64_t pb_ue_fw : 1;
        uint64_t pb_sue_fw : 1;
        uint64_t pb_rddatato_fw : 1;
        uint64_t pb_rdadrerr_fw : 1;
        uint64_t oci_apar_err : 1;
#endif // _BIG_ENDIAN
    } fields;
} pba_fir_and_t;



typedef union pba_fir_or
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
        uint64_t oci_apar_err : 1;
        uint64_t pb_rdadrerr_fw : 1;
        uint64_t pb_rddatato_fw : 1;
        uint64_t pb_sue_fw : 1;
        uint64_t pb_ue_fw : 1;
        uint64_t pb_ce_fw : 1;
        uint64_t oci_slave_init : 1;
        uint64_t oci_wrpar_err : 1;
        uint64_t reserved1 : 1;
        uint64_t pb_unexpcresp : 1;
        uint64_t pb_unexpdata : 1;
        uint64_t pb_parity_err : 1;
        uint64_t pb_wradrerr_fw : 1;
        uint64_t pb_badcresp : 1;
        uint64_t pb_ackdead_fw_rd : 1;
        uint64_t pb_operto : 1;
        uint64_t bcue_setup_err : 1;
        uint64_t bcue_pb_ack_dead : 1;
        uint64_t bcue_pb_adrerr : 1;
        uint64_t bcue_oci_daterr : 1;
        uint64_t bcde_setup_err : 1;
        uint64_t bcde_pb_ack_dead : 1;
        uint64_t bcde_pb_adrerr : 1;
        uint64_t bcde_rddatato_err : 1;
        uint64_t bcde_sue_err : 1;
        uint64_t bcde_ue_err : 1;
        uint64_t bcde_ce : 1;
        uint64_t bcde_oci_daterr : 1;
        uint64_t internal_err : 1;
        uint64_t illegal_cache_op : 1;
        uint64_t oci_bad_reg_addr : 1;
        uint64_t axpush_wrerr : 1;
        uint64_t axrcv_dlo_err : 1;
        uint64_t axrcv_dlo_to : 1;
        uint64_t axrcv_rsvdata_to : 1;
        uint64_t axflow_err : 1;
        uint64_t axsnd_dhi_rtyto : 1;
        uint64_t axsnd_dlo_rtyto : 1;
        uint64_t axsnd_rsvto : 1;
        uint64_t axsnd_rsverr : 1;
        uint64_t pb_ackdead_fw_wr : 1;
        uint64_t reserved2 : 1;
        uint64_t reserved3 : 1;
        uint64_t reserved4 : 1;
        uint64_t fir_parity_err2 : 1;
        uint64_t fir_parity_err : 1;
        uint64_t reserved5 : 18;
#else
        uint64_t reserved5 : 18;
        uint64_t fir_parity_err : 1;
        uint64_t fir_parity_err2 : 1;
        uint64_t reserved4 : 1;
        uint64_t reserved3 : 1;
        uint64_t reserved2 : 1;
        uint64_t pb_ackdead_fw_wr : 1;
        uint64_t axsnd_rsverr : 1;
        uint64_t axsnd_rsvto : 1;
        uint64_t axsnd_dlo_rtyto : 1;
        uint64_t axsnd_dhi_rtyto : 1;
        uint64_t axflow_err : 1;
        uint64_t axrcv_rsvdata_to : 1;
        uint64_t axrcv_dlo_to : 1;
        uint64_t axrcv_dlo_err : 1;
        uint64_t axpush_wrerr : 1;
        uint64_t oci_bad_reg_addr : 1;
        uint64_t illegal_cache_op : 1;
        uint64_t internal_err : 1;
        uint64_t bcde_oci_daterr : 1;
        uint64_t bcde_ce : 1;
        uint64_t bcde_ue_err : 1;
        uint64_t bcde_sue_err : 1;
        uint64_t bcde_rddatato_err : 1;
        uint64_t bcde_pb_adrerr : 1;
        uint64_t bcde_pb_ack_dead : 1;
        uint64_t bcde_setup_err : 1;
        uint64_t bcue_oci_daterr : 1;
        uint64_t bcue_pb_adrerr : 1;
        uint64_t bcue_pb_ack_dead : 1;
        uint64_t bcue_setup_err : 1;
        uint64_t pb_operto : 1;
        uint64_t pb_ackdead_fw_rd : 1;
        uint64_t pb_badcresp : 1;
        uint64_t pb_wradrerr_fw : 1;
        uint64_t pb_parity_err : 1;
        uint64_t pb_unexpdata : 1;
        uint64_t pb_unexpcresp : 1;
        uint64_t reserved1 : 1;
        uint64_t oci_wrpar_err : 1;
        uint64_t oci_slave_init : 1;
        uint64_t pb_ce_fw : 1;
        uint64_t pb_ue_fw : 1;
        uint64_t pb_sue_fw : 1;
        uint64_t pb_rddatato_fw : 1;
        uint64_t pb_rdadrerr_fw : 1;
        uint64_t oci_apar_err : 1;
#endif // _BIG_ENDIAN
    } fields;
} pba_fir_or_t;



typedef union pba_firmask
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
        uint64_t oci_apar_err_mask : 1;
        uint64_t pb_rdadrerr_fw_mask : 1;
        uint64_t pb_rddatato_fw_mask : 1;
        uint64_t pb_sue_fw_mask : 1;
        uint64_t pb_ue_fw_mask : 1;
        uint64_t pb_ce_fw_mask : 1;
        uint64_t oci_slave_init_mask : 1;
        uint64_t oci_wrpar_err_mask : 1;
        uint64_t reserved1 : 1;
        uint64_t pb_unexpcresp_mask : 1;
        uint64_t pb_unexpdata_mask : 1;
        uint64_t pb_parity_err_mask : 1;
        uint64_t pb_wradrerr_fw_mask : 1;
        uint64_t pb_badcresp_mask : 1;
        uint64_t pb_ackdead_fw_rd_mask : 1;
        uint64_t pb_operto_mask : 1;
        uint64_t bcue_setup_err_mask : 1;
        uint64_t bcue_pb_ack_dead_mask : 1;
        uint64_t bcue_pb_adrerr_mask : 1;
        uint64_t bcue_oci_daterr_mask : 1;
        uint64_t bcde_setup_err_mask : 1;
        uint64_t bcde_pb_ack_dead_mask : 1;
        uint64_t bcde_pb_adrerr_mask : 1;
        uint64_t bcde_rddatato_err_mask : 1;
        uint64_t bcde_sue_err_mask : 1;
        uint64_t bcde_ue_err_mask : 1;
        uint64_t bcde_ce_mask : 1;
        uint64_t bcde_oci_daterr_mask : 1;
        uint64_t internal_err_mask : 1;
        uint64_t illegal_cache_op_mask : 1;
        uint64_t oci_bad_reg_addr_mask : 1;
        uint64_t axpush_wrerr_mask : 1;
        uint64_t axrcv_dlo_err_mask : 1;
        uint64_t axrcv_dlo_to_mask : 1;
        uint64_t axrcv_rsvdata_to_mask : 1;
        uint64_t axflow_err_mask : 1;
        uint64_t axsnd_dhi_rtyto_mask : 1;
        uint64_t axsnd_dlo_rtyto_mask : 1;
        uint64_t axsnd_rsvto_mask : 1;
        uint64_t axsnd_rsverr_mask : 1;
        uint64_t pb_ackdead_fw_wr_mask : 1;
        uint64_t reserved2 : 3;
        uint64_t fir_parity_err2_mask : 1;
        uint64_t fir_parity_err_mask : 1;
        uint64_t reserved3 : 18;
#else
        uint64_t reserved3 : 18;
        uint64_t fir_parity_err_mask : 1;
        uint64_t fir_parity_err2_mask : 1;
        uint64_t reserved2 : 3;
        uint64_t pb_ackdead_fw_wr_mask : 1;
        uint64_t axsnd_rsverr_mask : 1;
        uint64_t axsnd_rsvto_mask : 1;
        uint64_t axsnd_dlo_rtyto_mask : 1;
        uint64_t axsnd_dhi_rtyto_mask : 1;
        uint64_t axflow_err_mask : 1;
        uint64_t axrcv_rsvdata_to_mask : 1;
        uint64_t axrcv_dlo_to_mask : 1;
        uint64_t axrcv_dlo_err_mask : 1;
        uint64_t axpush_wrerr_mask : 1;
        uint64_t oci_bad_reg_addr_mask : 1;
        uint64_t illegal_cache_op_mask : 1;
        uint64_t internal_err_mask : 1;
        uint64_t bcde_oci_daterr_mask : 1;
        uint64_t bcde_ce_mask : 1;
        uint64_t bcde_ue_err_mask : 1;
        uint64_t bcde_sue_err_mask : 1;
        uint64_t bcde_rddatato_err_mask : 1;
        uint64_t bcde_pb_adrerr_mask : 1;
        uint64_t bcde_pb_ack_dead_mask : 1;
        uint64_t bcde_setup_err_mask : 1;
        uint64_t bcue_oci_daterr_mask : 1;
        uint64_t bcue_pb_adrerr_mask : 1;
        uint64_t bcue_pb_ack_dead_mask : 1;
        uint64_t bcue_setup_err_mask : 1;
        uint64_t pb_operto_mask : 1;
        uint64_t pb_ackdead_fw_rd_mask : 1;
        uint64_t pb_badcresp_mask : 1;
        uint64_t pb_wradrerr_fw_mask : 1;
        uint64_t pb_parity_err_mask : 1;
        uint64_t pb_unexpdata_mask : 1;
        uint64_t pb_unexpcresp_mask : 1;
        uint64_t reserved1 : 1;
        uint64_t oci_wrpar_err_mask : 1;
        uint64_t oci_slave_init_mask : 1;
        uint64_t pb_ce_fw_mask : 1;
        uint64_t pb_ue_fw_mask : 1;
        uint64_t pb_sue_fw_mask : 1;
        uint64_t pb_rddatato_fw_mask : 1;
        uint64_t pb_rdadrerr_fw_mask : 1;
        uint64_t oci_apar_err_mask : 1;
#endif // _BIG_ENDIAN
    } fields;
} pba_firmask_t;



typedef union pba_firmask_and
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
        uint64_t oci_apar_err_mask : 1;
        uint64_t pb_rdadrerr_fw_mask : 1;
        uint64_t pb_rddatato_fw_mask : 1;
        uint64_t pb_sue_fw_mask : 1;
        uint64_t pb_ue_fw_mask : 1;
        uint64_t pb_ce_fw_mask : 1;
        uint64_t oci_slave_init_mask : 1;
        uint64_t oci_wrpar_err_mask : 1;
        uint64_t reserved1 : 1;
        uint64_t pb_unexpcresp_mask : 1;
        uint64_t pb_unexpdata_mask : 1;
        uint64_t pb_parity_err_mask : 1;
        uint64_t pb_wradrerr_fw_mask : 1;
        uint64_t pb_badcresp_mask : 1;
        uint64_t pb_ackdead_fw_rd_mask : 1;
        uint64_t pb_operto_mask : 1;
        uint64_t bcue_setup_err_mask : 1;
        uint64_t bcue_pb_ack_dead_mask : 1;
        uint64_t bcue_pb_adrerr_mask : 1;
        uint64_t bcue_oci_daterr_mask : 1;
        uint64_t bcde_setup_err_mask : 1;
        uint64_t bcde_pb_ack_dead_mask : 1;
        uint64_t bcde_pb_adrerr_mask : 1;
        uint64_t bcde_rddatato_err_mask : 1;
        uint64_t bcde_sue_err_mask : 1;
        uint64_t bcde_ue_err_mask : 1;
        uint64_t bcde_ce_mask : 1;
        uint64_t bcde_oci_daterr_mask : 1;
        uint64_t internal_err_mask : 1;
        uint64_t illegal_cache_op_mask : 1;
        uint64_t oci_bad_reg_addr_mask : 1;
        uint64_t axpush_wrerr_mask : 1;
        uint64_t axrcv_dlo_err_mask : 1;
        uint64_t axrcv_dlo_to_mask : 1;
        uint64_t axrcv_rsvdata_to_mask : 1;
        uint64_t axflow_err_mask : 1;
        uint64_t axsnd_dhi_rtyto_mask : 1;
        uint64_t axsnd_dlo_rtyto_mask : 1;
        uint64_t axsnd_rsvto_mask : 1;
        uint64_t axsnd_rsverr_mask : 1;
        uint64_t pb_ackdead_fw_wr_mask : 1;
        uint64_t reserved2 : 3;
        uint64_t fir_parity_err2_mask : 1;
        uint64_t fir_parity_err_mask : 1;
        uint64_t reserved3 : 18;
#else
        uint64_t reserved3 : 18;
        uint64_t fir_parity_err_mask : 1;
        uint64_t fir_parity_err2_mask : 1;
        uint64_t reserved2 : 3;
        uint64_t pb_ackdead_fw_wr_mask : 1;
        uint64_t axsnd_rsverr_mask : 1;
        uint64_t axsnd_rsvto_mask : 1;
        uint64_t axsnd_dlo_rtyto_mask : 1;
        uint64_t axsnd_dhi_rtyto_mask : 1;
        uint64_t axflow_err_mask : 1;
        uint64_t axrcv_rsvdata_to_mask : 1;
        uint64_t axrcv_dlo_to_mask : 1;
        uint64_t axrcv_dlo_err_mask : 1;
        uint64_t axpush_wrerr_mask : 1;
        uint64_t oci_bad_reg_addr_mask : 1;
        uint64_t illegal_cache_op_mask : 1;
        uint64_t internal_err_mask : 1;
        uint64_t bcde_oci_daterr_mask : 1;
        uint64_t bcde_ce_mask : 1;
        uint64_t bcde_ue_err_mask : 1;
        uint64_t bcde_sue_err_mask : 1;
        uint64_t bcde_rddatato_err_mask : 1;
        uint64_t bcde_pb_adrerr_mask : 1;
        uint64_t bcde_pb_ack_dead_mask : 1;
        uint64_t bcde_setup_err_mask : 1;
        uint64_t bcue_oci_daterr_mask : 1;
        uint64_t bcue_pb_adrerr_mask : 1;
        uint64_t bcue_pb_ack_dead_mask : 1;
        uint64_t bcue_setup_err_mask : 1;
        uint64_t pb_operto_mask : 1;
        uint64_t pb_ackdead_fw_rd_mask : 1;
        uint64_t pb_badcresp_mask : 1;
        uint64_t pb_wradrerr_fw_mask : 1;
        uint64_t pb_parity_err_mask : 1;
        uint64_t pb_unexpdata_mask : 1;
        uint64_t pb_unexpcresp_mask : 1;
        uint64_t reserved1 : 1;
        uint64_t oci_wrpar_err_mask : 1;
        uint64_t oci_slave_init_mask : 1;
        uint64_t pb_ce_fw_mask : 1;
        uint64_t pb_ue_fw_mask : 1;
        uint64_t pb_sue_fw_mask : 1;
        uint64_t pb_rddatato_fw_mask : 1;
        uint64_t pb_rdadrerr_fw_mask : 1;
        uint64_t oci_apar_err_mask : 1;
#endif // _BIG_ENDIAN
    } fields;
} pba_firmask_and_t;



typedef union pba_firmask_or
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
        uint64_t oci_apar_err_mask : 1;
        uint64_t pb_rdadrerr_fw_mask : 1;
        uint64_t pb_rddatato_fw_mask : 1;
        uint64_t pb_sue_fw_mask : 1;
        uint64_t pb_ue_fw_mask : 1;
        uint64_t pb_ce_fw_mask : 1;
        uint64_t oci_slave_init_mask : 1;
        uint64_t oci_wrpar_err_mask : 1;
        uint64_t reserved1 : 1;
        uint64_t pb_unexpcresp_mask : 1;
        uint64_t pb_unexpdata_mask : 1;
        uint64_t pb_parity_err_mask : 1;
        uint64_t pb_wradrerr_fw_mask : 1;
        uint64_t pb_badcresp_mask : 1;
        uint64_t pb_ackdead_fw_rd_mask : 1;
        uint64_t pb_operto_mask : 1;
        uint64_t bcue_setup_err_mask : 1;
        uint64_t bcue_pb_ack_dead_mask : 1;
        uint64_t bcue_pb_adrerr_mask : 1;
        uint64_t bcue_oci_daterr_mask : 1;
        uint64_t bcde_setup_err_mask : 1;
        uint64_t bcde_pb_ack_dead_mask : 1;
        uint64_t bcde_pb_adrerr_mask : 1;
        uint64_t bcde_rddatato_err_mask : 1;
        uint64_t bcde_sue_err_mask : 1;
        uint64_t bcde_ue_err_mask : 1;
        uint64_t bcde_ce_mask : 1;
        uint64_t bcde_oci_daterr_mask : 1;
        uint64_t internal_err_mask : 1;
        uint64_t illegal_cache_op_mask : 1;
        uint64_t oci_bad_reg_addr_mask : 1;
        uint64_t axpush_wrerr_mask : 1;
        uint64_t axrcv_dlo_err_mask : 1;
        uint64_t axrcv_dlo_to_mask : 1;
        uint64_t axrcv_rsvdata_to_mask : 1;
        uint64_t axflow_err_mask : 1;
        uint64_t axsnd_dhi_rtyto_mask : 1;
        uint64_t axsnd_dlo_rtyto_mask : 1;
        uint64_t axsnd_rsvto_mask : 1;
        uint64_t axsnd_rsverr_mask : 1;
        uint64_t pb_ackdead_fw_wr_mask : 1;
        uint64_t reserved2 : 3;
        uint64_t fir_parity_err2_mask : 1;
        uint64_t fir_parity_err_mask : 1;
        uint64_t reserved3 : 18;
#else
        uint64_t reserved3 : 18;
        uint64_t fir_parity_err_mask : 1;
        uint64_t fir_parity_err2_mask : 1;
        uint64_t reserved2 : 3;
        uint64_t pb_ackdead_fw_wr_mask : 1;
        uint64_t axsnd_rsverr_mask : 1;
        uint64_t axsnd_rsvto_mask : 1;
        uint64_t axsnd_dlo_rtyto_mask : 1;
        uint64_t axsnd_dhi_rtyto_mask : 1;
        uint64_t axflow_err_mask : 1;
        uint64_t axrcv_rsvdata_to_mask : 1;
        uint64_t axrcv_dlo_to_mask : 1;
        uint64_t axrcv_dlo_err_mask : 1;
        uint64_t axpush_wrerr_mask : 1;
        uint64_t oci_bad_reg_addr_mask : 1;
        uint64_t illegal_cache_op_mask : 1;
        uint64_t internal_err_mask : 1;
        uint64_t bcde_oci_daterr_mask : 1;
        uint64_t bcde_ce_mask : 1;
        uint64_t bcde_ue_err_mask : 1;
        uint64_t bcde_sue_err_mask : 1;
        uint64_t bcde_rddatato_err_mask : 1;
        uint64_t bcde_pb_adrerr_mask : 1;
        uint64_t bcde_pb_ack_dead_mask : 1;
        uint64_t bcde_setup_err_mask : 1;
        uint64_t bcue_oci_daterr_mask : 1;
        uint64_t bcue_pb_adrerr_mask : 1;
        uint64_t bcue_pb_ack_dead_mask : 1;
        uint64_t bcue_setup_err_mask : 1;
        uint64_t pb_operto_mask : 1;
        uint64_t pb_ackdead_fw_rd_mask : 1;
        uint64_t pb_badcresp_mask : 1;
        uint64_t pb_wradrerr_fw_mask : 1;
        uint64_t pb_parity_err_mask : 1;
        uint64_t pb_unexpdata_mask : 1;
        uint64_t pb_unexpcresp_mask : 1;
        uint64_t reserved1 : 1;
        uint64_t oci_wrpar_err_mask : 1;
        uint64_t oci_slave_init_mask : 1;
        uint64_t pb_ce_fw_mask : 1;
        uint64_t pb_ue_fw_mask : 1;
        uint64_t pb_sue_fw_mask : 1;
        uint64_t pb_rddatato_fw_mask : 1;
        uint64_t pb_rdadrerr_fw_mask : 1;
        uint64_t oci_apar_err_mask : 1;
#endif // _BIG_ENDIAN
    } fields;
} pba_firmask_or_t;



typedef union pba_firact0
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
        uint64_t fir_action0 : 46;
        uint64_t reserved1 : 18;
#else
        uint64_t reserved1 : 18;
        uint64_t fir_action0 : 46;
#endif // _BIG_ENDIAN
    } fields;
} pba_firact0_t;



typedef union pba_firact1
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
        uint64_t fir_action1 : 46;
        uint64_t reserved1 : 18;
#else
        uint64_t reserved1 : 18;
        uint64_t fir_action1 : 46;
#endif // _BIG_ENDIAN
    } fields;
} pba_firact1_t;



typedef union pba_occact
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
        uint64_t occ_action_set : 44;
        uint64_t reserved1 : 20;
#else
        uint64_t reserved1 : 20;
        uint64_t occ_action_set : 44;
#endif // _BIG_ENDIAN
    } fields;
} pba_occact_t;



typedef union pba_cfg
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
        uint64_t pbreq_slvfw_max_priority : 1;
        uint64_t pbreq_exit_on_hang : 1;
        uint64_t pbreq_bce_max_priority : 1;
        uint64_t pbreq_exit_on_hang_pbax : 1;
        uint64_t pbreq_data_hang_div : 5;
        uint64_t pbreq_oper_hang_div : 5;
        uint64_t pbreq_drop_priority_mask : 6;
        uint64_t pbreq_exit_hang_div : 4;
        uint64_t chsw_hang_on_adrerror : 1;
        uint64_t chsw_dis_ociabuspar_check : 1;
        uint64_t chsw_dis_ocibepar_check : 1;
        uint64_t chsw_hang_on_derror : 1;
        uint64_t reserved1 : 1;
        uint64_t chsw_dis_write_match_rearb : 1;
        uint64_t chsw_dis_ocidatapar_gen : 1;
        uint64_t chsw_dis_ocidatapar_check : 1;
        uint64_t chsw_dis_oper_hang : 1;
        uint64_t chsw_dis_data_hang : 1;
        uint64_t chsw_dis_ecc_check : 1;
        uint64_t chsw_dis_retry_backoff : 1;
        uint64_t chsw_exit_on_invalid_cresp : 1;
        uint64_t reserved2 : 1;
        uint64_t chsw_dis_group_scope : 1;
        uint64_t chsw_dis_rtag_parity_chk : 1;
        uint64_t chsw_dis_pb_parity_chk : 1;
        uint64_t chsw_skip_group_scope : 1;
        uint64_t chsw_use_pr_dma_inj : 1;
        uint64_t chsw_use_cl_dma_inj : 1;
        uint64_t reserved3 : 4;
        uint64_t reserved4 : 16;
#else
        uint64_t reserved4 : 16;
        uint64_t reserved3 : 4;
        uint64_t chsw_use_cl_dma_inj : 1;
        uint64_t chsw_use_pr_dma_inj : 1;
        uint64_t chsw_skip_group_scope : 1;
        uint64_t chsw_dis_pb_parity_chk : 1;
        uint64_t chsw_dis_rtag_parity_chk : 1;
        uint64_t chsw_dis_group_scope : 1;
        uint64_t reserved2 : 1;
        uint64_t chsw_exit_on_invalid_cresp : 1;
        uint64_t chsw_dis_retry_backoff : 1;
        uint64_t chsw_dis_ecc_check : 1;
        uint64_t chsw_dis_data_hang : 1;
        uint64_t chsw_dis_oper_hang : 1;
        uint64_t chsw_dis_ocidatapar_check : 1;
        uint64_t chsw_dis_ocidatapar_gen : 1;
        uint64_t chsw_dis_write_match_rearb : 1;
        uint64_t reserved1 : 1;
        uint64_t chsw_hang_on_derror : 1;
        uint64_t chsw_dis_ocibepar_check : 1;
        uint64_t chsw_dis_ociabuspar_check : 1;
        uint64_t chsw_hang_on_adrerror : 1;
        uint64_t pbreq_exit_hang_div : 4;
        uint64_t pbreq_drop_priority_mask : 6;
        uint64_t pbreq_oper_hang_div : 5;
        uint64_t pbreq_data_hang_div : 5;
        uint64_t pbreq_exit_on_hang_pbax : 1;
        uint64_t pbreq_bce_max_priority : 1;
        uint64_t pbreq_exit_on_hang : 1;
        uint64_t pbreq_slvfw_max_priority : 1;
#endif // _BIG_ENDIAN
    } fields;
} pba_cfg_t;



typedef union pba_errrpt0
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
        uint64_t cerr_pb_rddatato_fw : 6;
        uint64_t cerr_pb_rdadrerr_fw : 6;
        uint64_t cerr_pb_wradrerr_fw : 4;
        uint64_t cerr_pb_ackdead_fw_rd : 6;
        uint64_t cerr_pb_ackdead_fw_wr : 2;
        uint64_t cerr_pb_unexpcresp : 11;
        uint64_t cerr_pb_unexpdata : 6;
        uint64_t reserved1 : 23;
#else
        uint64_t reserved1 : 23;
        uint64_t cerr_pb_unexpdata : 6;
        uint64_t cerr_pb_unexpcresp : 11;
        uint64_t cerr_pb_ackdead_fw_wr : 2;
        uint64_t cerr_pb_ackdead_fw_rd : 6;
        uint64_t cerr_pb_wradrerr_fw : 4;
        uint64_t cerr_pb_rdadrerr_fw : 6;
        uint64_t cerr_pb_rddatato_fw : 6;
#endif // _BIG_ENDIAN
    } fields;
} pba_errrpt0_t;



typedef union pba_errrpt1
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
        uint64_t cerr_pb_badcresp : 12;
        uint64_t cerr_pb_operto : 12;
        uint64_t reserved1 : 6;
        uint64_t cerr_bcde_setup_err : 2;
        uint64_t cerr_bcue_setup_err : 2;
        uint64_t cerr_bcue_oci_dataerr : 2;
        uint64_t reserved2 : 28;
#else
        uint64_t reserved2 : 28;
        uint64_t cerr_bcue_oci_dataerr : 2;
        uint64_t cerr_bcue_setup_err : 2;
        uint64_t cerr_bcde_setup_err : 2;
        uint64_t reserved1 : 6;
        uint64_t cerr_pb_operto : 12;
        uint64_t cerr_pb_badcresp : 12;
#endif // _BIG_ENDIAN
    } fields;
} pba_errrpt1_t;



typedef union pba_errrpt2
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
        uint64_t cerr_slv_internal_err : 8;
        uint64_t cerr_bcde_internal_err : 4;
        uint64_t cerr_bcue_internal_err : 4;
        uint64_t cerr_bar_parity_err : 1;
        uint64_t cerr_scomtb_err : 1;
        uint64_t cerr_spare : 2;
        uint64_t cerr_pbdout_parity_err : 1;
        uint64_t cerr_pb_parity_err : 3;
        uint64_t cerr_axflow_err : 5;
        uint64_t cerr_axpush_wrerr : 2;
        uint64_t reserved1 : 33;
#else
        uint64_t reserved1 : 33;
        uint64_t cerr_axpush_wrerr : 2;
        uint64_t cerr_axflow_err : 5;
        uint64_t cerr_pb_parity_err : 3;
        uint64_t cerr_pbdout_parity_err : 1;
        uint64_t cerr_spare : 2;
        uint64_t cerr_scomtb_err : 1;
        uint64_t cerr_bar_parity_err : 1;
        uint64_t cerr_bcue_internal_err : 4;
        uint64_t cerr_bcde_internal_err : 4;
        uint64_t cerr_slv_internal_err : 8;
#endif // _BIG_ENDIAN
    } fields;
} pba_errrpt2_t;



typedef union pba_rbufvaln
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
        uint64_t rd_slvnum : 2;
        uint64_t cur_rd_addr : 23;
        uint64_t reserved1 : 3;
        uint64_t prefetch : 1;
        uint64_t reserved2 : 2;
        uint64_t abort : 1;
        uint64_t reserved3 : 1;
        uint64_t buffer_status : 7;
        uint64_t reserved4 : 1;
        uint64_t masterid : 3;
        uint64_t reserved5 : 20;
#else
        uint64_t reserved5 : 20;
        uint64_t masterid : 3;
        uint64_t reserved4 : 1;
        uint64_t buffer_status : 7;
        uint64_t reserved3 : 1;
        uint64_t abort : 1;
        uint64_t reserved2 : 2;
        uint64_t prefetch : 1;
        uint64_t reserved1 : 3;
        uint64_t cur_rd_addr : 23;
        uint64_t rd_slvnum : 2;
#endif // _BIG_ENDIAN
    } fields;
} pba_rbufvaln_t;



typedef union pba_wbufvaln
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
        uint64_t wr_slvnum : 2;
        uint64_t start_wr_addr : 30;
        uint64_t reserved1 : 3;
        uint64_t wr_buffer_status : 5;
        uint64_t reserved2 : 1;
        uint64_t wr_byte_count : 7;
        uint64_t reserved3 : 16;
#else
        uint64_t reserved3 : 16;
        uint64_t wr_byte_count : 7;
        uint64_t reserved2 : 1;
        uint64_t wr_buffer_status : 5;
        uint64_t reserved1 : 3;
        uint64_t start_wr_addr : 30;
        uint64_t wr_slvnum : 2;
#endif // _BIG_ENDIAN
    } fields;
} pba_wbufvaln_t;



typedef union pba_barn
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
        uint64_t cmd_scope : 3;
        uint64_t reserved1 : 1;
        uint64_t reserved2 : 4;
        uint64_t addr : 36;
        uint64_t reserved3 : 4;
        uint64_t vtarget : 16;
#else
        uint64_t vtarget : 16;
        uint64_t reserved3 : 4;
        uint64_t addr : 36;
        uint64_t reserved2 : 4;
        uint64_t reserved1 : 1;
        uint64_t cmd_scope : 3;
#endif // _BIG_ENDIAN
    } fields;
} pba_barn_t;



typedef union pba_barmskn
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
        uint64_t reserved1 : 23;
        uint64_t mask : 21;
        uint64_t reserved2 : 20;
#else
        uint64_t reserved2 : 20;
        uint64_t mask : 21;
        uint64_t reserved1 : 23;
#endif // _BIG_ENDIAN
    } fields;
} pba_barmskn_t;


#endif // __ASSEMBLER__
#endif // __PBA_FIRMWARE_REGISTERS_H__

