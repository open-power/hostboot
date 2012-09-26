/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/build_winkle_images/proc_set_pore_bar/pba_firmware_register.H $
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
// Subversion Repositories OCC
// (root)/ssx/trunk/pgp/registers/pba_firmware_registers.h - Rev 1095
// Rev

// Rev 1077 | Blame | Compare with Previous | Last modification | View Log | RSS feed
#ifndef __PBA_FIRMWARE_REGISTERS_H__
#define __PBA_FIRMWARE_REGISTERS_H__

#ifndef SIXTYFOUR_BIT_CONSTANT
#ifdef __ASSEMBLER__
#define SIXTYFOUR_BIT_CONSTANT(x) x
#else
#define SIXTYFOUR_BIT_CONSTANT(x) x##ull
#endif
#endif

#ifndef __ASSEMBLER__

// $Id: pba_firmware_register.H,v 1.1 2012/01/09 13:46:34 kgungl Exp $

/// \file pba_firmware_registers.h
/// \brief C register structs for the PBA unit

// *** WARNING *** - This file is generated automatically, do not edit.

#include <stdint.h>


typedef union pba_barn {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t cmd_scope : 3;
        uint64_t reserved0 : 1;
        uint64_t reserved1 : 10;
        uint64_t addr : 30;
        uint64_t _reserved0 : 20;
#else
        uint64_t _reserved0 : 20;
        uint64_t addr : 30;
        uint64_t reserved1 : 10;
        uint64_t reserved0 : 1;
        uint64_t cmd_scope : 3;
#endif // _BIG_ENDIAN
    } fields;
} pba_barn_t;



typedef union pba_barmskn {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t reserved0 : 23;
        uint64_t mask : 21;
        uint64_t _reserved0 : 20;
#else
        uint64_t _reserved0 : 20;
        uint64_t mask : 21;
        uint64_t reserved0 : 23;
#endif // _BIG_ENDIAN
    } fields;
} pba_barmskn_t;



typedef union pba_fir {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t oci_apar_err : 1;
        uint64_t pb_rdadrerr_fw : 1;
        uint64_t pb_rddatato_fw : 1;
        uint64_t pb_sue_fw : 1;
        uint64_t pb_ue_fw : 1;
        uint64_t pb_ce_fw : 1;
        uint64_t oci_slave_init : 1;
        uint64_t oci_wrpar_err : 1;
        uint64_t oci_rereqto : 1;
        uint64_t pb_unexpcresp : 1;
        uint64_t pb_unexpdata : 1;
        uint64_t pb_parity_err : 1;
        uint64_t pb_wradrerr_fw : 1;
        uint64_t pb_badcresp : 1;
        uint64_t pb_ackdead_fw : 1;
        uint64_t pb_crespto : 1;
        uint64_t bcue_setup_err : 1;
        uint64_t bcue_pb_ack_dead : 1;
        uint64_t bcue_pb_adrerr : 1;
        uint64_t bcue_oci_dataerr : 1;
        uint64_t bcde_setup_err : 1;
        uint64_t bcde_pb_ack_dead : 1;
        uint64_t bcde_pb_adrerr : 1;
        uint64_t bcde_rddatato_err : 1;
        uint64_t bcde_sue_err : 1;
        uint64_t bcde_ue_err : 1;
        uint64_t bcde_ce : 1;
        uint64_t bcde_oci_dataerr : 1;
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
        uint64_t reserved : 4;
        uint64_t fir_parity_error : 1;
        uint64_t _reserved0 : 19;
#else
        uint64_t _reserved0 : 19;
        uint64_t fir_parity_error : 1;
        uint64_t reserved : 4;
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
        uint64_t bcde_oci_dataerr : 1;
        uint64_t bcde_ce : 1;
        uint64_t bcde_ue_err : 1;
        uint64_t bcde_sue_err : 1;
        uint64_t bcde_rddatato_err : 1;
        uint64_t bcde_pb_adrerr : 1;
        uint64_t bcde_pb_ack_dead : 1;
        uint64_t bcde_setup_err : 1;
        uint64_t bcue_oci_dataerr : 1;
        uint64_t bcue_pb_adrerr : 1;
        uint64_t bcue_pb_ack_dead : 1;
        uint64_t bcue_setup_err : 1;
        uint64_t pb_crespto : 1;
        uint64_t pb_ackdead_fw : 1;
        uint64_t pb_badcresp : 1;
        uint64_t pb_wradrerr_fw : 1;
        uint64_t pb_parity_err : 1;
        uint64_t pb_unexpdata : 1;
        uint64_t pb_unexpcresp : 1;
        uint64_t oci_rereqto : 1;
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



typedef union pba_fir_and {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t oci_apar_err : 1;
        uint64_t pb_rdadrerr_fw : 1;
        uint64_t pb_rddatato_fw : 1;
        uint64_t pb_sue_fw : 1;
        uint64_t pb_ue_fw : 1;
        uint64_t pb_ce_fw : 1;
        uint64_t oci_slave_init : 1;
        uint64_t oci_wrpar_err : 1;
        uint64_t oci_rereqto : 1;
        uint64_t pb_unexpcresp : 1;
        uint64_t pb_unexpdata : 1;
        uint64_t pb_parity_err : 1;
        uint64_t pb_wradrerr_fw : 1;
        uint64_t pb_badcresp : 1;
        uint64_t pb_ackdead_fw : 1;
        uint64_t pb_crespto : 1;
        uint64_t bcue_setup_err : 1;
        uint64_t bcue_pb_ack_dead : 1;
        uint64_t bcue_pb_adrerr : 1;
        uint64_t bcue_oci_dataerr : 1;
        uint64_t bcde_setup_err : 1;
        uint64_t bcde_pb_ack_dead : 1;
        uint64_t bcde_pb_adrerr : 1;
        uint64_t bcde_rddatato_err : 1;
        uint64_t bcde_sue_err : 1;
        uint64_t bcde_ue_err : 1;
        uint64_t bcde_ce : 1;
        uint64_t bcde_oci_dataerr : 1;
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
        uint64_t reserved : 4;
        uint64_t fir_parity_error : 1;
        uint64_t _reserved0 : 19;
#else
        uint64_t _reserved0 : 19;
        uint64_t fir_parity_error : 1;
        uint64_t reserved : 4;
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
        uint64_t bcde_oci_dataerr : 1;
        uint64_t bcde_ce : 1;
        uint64_t bcde_ue_err : 1;
        uint64_t bcde_sue_err : 1;
        uint64_t bcde_rddatato_err : 1;
        uint64_t bcde_pb_adrerr : 1;
        uint64_t bcde_pb_ack_dead : 1;
        uint64_t bcde_setup_err : 1;
        uint64_t bcue_oci_dataerr : 1;
        uint64_t bcue_pb_adrerr : 1;
        uint64_t bcue_pb_ack_dead : 1;
        uint64_t bcue_setup_err : 1;
        uint64_t pb_crespto : 1;
        uint64_t pb_ackdead_fw : 1;
        uint64_t pb_badcresp : 1;
        uint64_t pb_wradrerr_fw : 1;
        uint64_t pb_parity_err : 1;
        uint64_t pb_unexpdata : 1;
        uint64_t pb_unexpcresp : 1;
        uint64_t oci_rereqto : 1;
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



typedef union pba_fir_or {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t oci_apar_err : 1;
        uint64_t pb_rdadrerr_fw : 1;
        uint64_t pb_rddatato_fw : 1;
        uint64_t pb_sue_fw : 1;
        uint64_t pb_ue_fw : 1;
        uint64_t pb_ce_fw : 1;
        uint64_t oci_slave_init : 1;
        uint64_t oci_wrpar_err : 1;
        uint64_t oci_rereqto : 1;
        uint64_t pb_unexpcresp : 1;
        uint64_t pb_unexpdata : 1;
        uint64_t pb_parity_err : 1;
        uint64_t pb_wradrerr_fw : 1;
        uint64_t pb_badcresp : 1;
        uint64_t pb_ackdead_fw : 1;
        uint64_t pb_crespto : 1;
        uint64_t bcue_setup_err : 1;
        uint64_t bcue_pb_ack_dead : 1;
        uint64_t bcue_pb_adrerr : 1;
        uint64_t bcue_oci_dataerr : 1;
        uint64_t bcde_setup_err : 1;
        uint64_t bcde_pb_ack_dead : 1;
        uint64_t bcde_pb_adrerr : 1;
        uint64_t bcde_rddatato_err : 1;
        uint64_t bcde_sue_err : 1;
        uint64_t bcde_ue_err : 1;
        uint64_t bcde_ce : 1;
        uint64_t bcde_oci_dataerr : 1;
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
        uint64_t reserved : 4;
        uint64_t fir_parity_error : 1;
        uint64_t _reserved0 : 19;
#else
        uint64_t _reserved0 : 19;
        uint64_t fir_parity_error : 1;
        uint64_t reserved : 4;
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
        uint64_t bcde_oci_dataerr : 1;
        uint64_t bcde_ce : 1;
        uint64_t bcde_ue_err : 1;
        uint64_t bcde_sue_err : 1;
        uint64_t bcde_rddatato_err : 1;
        uint64_t bcde_pb_adrerr : 1;
        uint64_t bcde_pb_ack_dead : 1;
        uint64_t bcde_setup_err : 1;
        uint64_t bcue_oci_dataerr : 1;
        uint64_t bcue_pb_adrerr : 1;
        uint64_t bcue_pb_ack_dead : 1;
        uint64_t bcue_setup_err : 1;
        uint64_t pb_crespto : 1;
        uint64_t pb_ackdead_fw : 1;
        uint64_t pb_badcresp : 1;
        uint64_t pb_wradrerr_fw : 1;
        uint64_t pb_parity_err : 1;
        uint64_t pb_unexpdata : 1;
        uint64_t pb_unexpcresp : 1;
        uint64_t oci_rereqto : 1;
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



typedef union pba_fir_mask {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t mask : 44;
        uint64_t _reserved0 : 20;
#else
        uint64_t _reserved0 : 20;
        uint64_t mask : 44;
#endif // _BIG_ENDIAN
    } fields;
} pba_fir_mask_t;



typedef union pba_fir_mask_and {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t mask : 44;
        uint64_t _reserved0 : 20;
#else
        uint64_t _reserved0 : 20;
        uint64_t mask : 44;
#endif // _BIG_ENDIAN
    } fields;
} pba_fir_mask_and_t;



typedef union pba_fir_mask_or {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t mask : 44;
        uint64_t _reserved0 : 20;
#else
        uint64_t _reserved0 : 20;
        uint64_t mask : 44;
#endif // _BIG_ENDIAN
    } fields;
} pba_fir_mask_or_t;



typedef union pba_fir_action0 {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t fir_action0 : 44;
        uint64_t _reserved0 : 20;
#else
        uint64_t _reserved0 : 20;
        uint64_t fir_action0 : 44;
#endif // _BIG_ENDIAN
    } fields;
} pba_fir_action0_t;



typedef union pba_fir_action1 {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t fir_action1 : 44;
        uint64_t _reserved0 : 20;
#else
        uint64_t _reserved0 : 20;
        uint64_t fir_action1 : 44;
#endif // _BIG_ENDIAN
    } fields;
} pba_fir_action1_t;



typedef union pba_occ_action {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t occ_action_set : 44;
        uint64_t _reserved0 : 20;
#else
        uint64_t _reserved0 : 20;
        uint64_t occ_action_set : 44;
#endif // _BIG_ENDIAN
    } fields;
} pba_occ_action_t;



typedef union pba_rbufvaln {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t rd_slvnum : 2;
        uint64_t cur_rd_addr : 23;
        uint64_t spare1 : 3;
        uint64_t prefetch : 1;
        uint64_t spare2 : 2;
        uint64_t abort : 1;
        uint64_t spare3 : 1;
        uint64_t buffer_status : 7;
        uint64_t spare4 : 4;
        uint64_t _reserved0 : 20;
#else
        uint64_t _reserved0 : 20;
        uint64_t spare4 : 4;
        uint64_t buffer_status : 7;
        uint64_t spare3 : 1;
        uint64_t abort : 1;
        uint64_t spare2 : 2;
        uint64_t prefetch : 1;
        uint64_t spare1 : 3;
        uint64_t cur_rd_addr : 23;
        uint64_t rd_slvnum : 2;
#endif // _BIG_ENDIAN
    } fields;
} pba_rbufvaln_t;



typedef union pba_wbufvaln {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t wr_slvnum : 2;
        uint64_t start_wr_addr : 30;
        uint64_t spare1 : 3;
        uint64_t wr_buffer_status : 5;
        uint64_t spare2 : 1;
        uint64_t wr_byte_count : 7;
        uint64_t spare3 : 16;
#else
        uint64_t spare3 : 16;
        uint64_t wr_byte_count : 7;
        uint64_t spare2 : 1;
        uint64_t wr_buffer_status : 5;
        uint64_t spare1 : 3;
        uint64_t start_wr_addr : 30;
        uint64_t wr_slvnum : 2;
#endif // _BIG_ENDIAN
    } fields;
} pba_wbufvaln_t;



typedef union pba_mode {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t reserved0 : 4;
        uint64_t dis_rearb : 1;
        uint64_t reserved1 : 1;
        uint64_t dis_slave_rdpipe : 1;
        uint64_t dis_slave_wrpipe : 1;
        uint64_t en_marker_ack : 1;
        uint64_t dis_slvmatch_order : 1;
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
        uint64_t en_slave_fairness : 1;
        uint64_t en_ecvent_count : 1;
        uint64_t pb_noci_event_sel : 1;
        uint64_t slv_event_mux : 2;
        uint64_t enable_debug_bus : 1;
        uint64_t debug_pb_not_oci : 1;
        uint64_t debug_oci_mode : 5;
        uint64_t reserved2 : 1;
        uint64_t ocislv_fairness_mask : 5;
        uint64_t ocislv_rereq_hang_div : 5;
        uint64_t dis_chgrate_count : 1;
        uint64_t pbreq_event_mux : 2;
        uint64_t _reserved0 : 11;
#else
        uint64_t _reserved0 : 11;
        uint64_t pbreq_event_mux : 2;
        uint64_t dis_chgrate_count : 1;
        uint64_t ocislv_rereq_hang_div : 5;
        uint64_t ocislv_fairness_mask : 5;
        uint64_t reserved2 : 1;
        uint64_t debug_oci_mode : 5;
        uint64_t debug_pb_not_oci : 1;
        uint64_t enable_debug_bus : 1;
        uint64_t slv_event_mux : 2;
        uint64_t pb_noci_event_sel : 1;
        uint64_t en_ecvent_count : 1;
        uint64_t en_slave_fairness : 1;
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
        uint64_t dis_slvmatch_order : 1;
        uint64_t en_marker_ack : 1;
        uint64_t dis_slave_wrpipe : 1;
        uint64_t dis_slave_rdpipe : 1;
        uint64_t reserved1 : 1;
        uint64_t dis_rearb : 1;
        uint64_t reserved0 : 4;
#endif // _BIG_ENDIAN
    } fields;
} pba_mode_t;



typedef union pba_slvrst {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t set : 3;
        uint64_t notimp1 : 1;
        uint64_t in_prog : 4;
        uint64_t busy_status : 4;
        uint64_t _reserved0 : 52;
#else
        uint64_t _reserved0 : 52;
        uint64_t busy_status : 4;
        uint64_t in_prog : 4;
        uint64_t notimp1 : 1;
        uint64_t set : 3;
#endif // _BIG_ENDIAN
    } fields;
} pba_slvrst_t;



typedef union pba_slvctln {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t enable : 1;
        uint64_t mid_match_value : 3;
        uint64_t _reserved0 : 1;
        uint64_t mid_care_mask : 3;
        uint64_t write_ttype : 3;
        uint64_t _reserved1 : 4;
        uint64_t read_ttype : 1;
        uint64_t read_prefetch_ctl : 2;
        uint64_t buf_invalidate_ctl : 1;
        uint64_t buf_alloc_w : 1;
        uint64_t buf_alloc_a : 1;
        uint64_t buf_alloc_b : 1;
        uint64_t buf_alloc_c : 1;
        uint64_t _reserved2 : 1;
        uint64_t dis_write_gather : 1;
        uint64_t wr_gather_timeout : 3;
        uint64_t write_tsize : 7;
        uint64_t extaddr : 14;
        uint64_t _reserved3 : 15;
#else
        uint64_t _reserved3 : 15;
        uint64_t extaddr : 14;
        uint64_t write_tsize : 7;
        uint64_t wr_gather_timeout : 3;
        uint64_t dis_write_gather : 1;
        uint64_t _reserved2 : 1;
        uint64_t buf_alloc_c : 1;
        uint64_t buf_alloc_b : 1;
        uint64_t buf_alloc_a : 1;
        uint64_t buf_alloc_w : 1;
        uint64_t buf_invalidate_ctl : 1;
        uint64_t read_prefetch_ctl : 2;
        uint64_t read_ttype : 1;
        uint64_t _reserved1 : 4;
        uint64_t write_ttype : 3;
        uint64_t mid_care_mask : 3;
        uint64_t _reserved0 : 1;
        uint64_t mid_match_value : 3;
        uint64_t enable : 1;
#endif // _BIG_ENDIAN
    } fields;
} pba_slvctln_t;



typedef union pba_bcde_ctl {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t stop : 1;
        uint64_t start : 1;
        uint64_t _reserved0 : 62;
#else
        uint64_t _reserved0 : 62;
        uint64_t start : 1;
        uint64_t stop : 1;
#endif // _BIG_ENDIAN
    } fields;
} pba_bcde_ctl_t;

#endif // __ASSEMBLER__
#define PBA_BCDE_CTL_STOP SIXTYFOUR_BIT_CONSTANT(0x8000000000000000)
#define PBA_BCDE_CTL_START SIXTYFOUR_BIT_CONSTANT(0x4000000000000000)
#ifndef __ASSEMBLER__


typedef union pba_bcde_set {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t _reserved0 : 2;
        uint64_t copy_length : 6;
        uint64_t _reserved1 : 56;
#else
        uint64_t _reserved1 : 56;
        uint64_t copy_length : 6;
        uint64_t _reserved0 : 2;
#endif // _BIG_ENDIAN
    } fields;
} pba_bcde_set_t;



typedef union pba_bcde_status {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t running : 1;
        uint64_t waiting : 1;
        uint64_t wrcmp : 6;
        uint64_t _reserved0 : 6;
        uint64_t rdcmp : 6;
        uint64_t debug : 9;
        uint64_t stopped : 1;
        uint64_t error : 1;
        uint64_t done : 1;
        uint64_t _reserved1 : 32;
#else
        uint64_t _reserved1 : 32;
        uint64_t done : 1;
        uint64_t error : 1;
        uint64_t stopped : 1;
        uint64_t debug : 9;
        uint64_t rdcmp : 6;
        uint64_t _reserved0 : 6;
        uint64_t wrcmp : 6;
        uint64_t waiting : 1;
        uint64_t running : 1;
#endif // _BIG_ENDIAN
    } fields;
} pba_bcde_status_t;



typedef union pba_bcde_pbadr {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t _reserved0 : 2;
        uint64_t pb_offset : 23;
        uint64_t _reserved1 : 2;
        uint64_t extaddr : 14;
        uint64_t _reserved2 : 23;
#else
        uint64_t _reserved2 : 23;
        uint64_t extaddr : 14;
        uint64_t _reserved1 : 2;
        uint64_t pb_offset : 23;
        uint64_t _reserved0 : 2;
#endif // _BIG_ENDIAN
    } fields;
} pba_bcde_pbadr_t;



typedef union pba_bcde_ocibar {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t addr : 25;
        uint64_t _reserved0 : 39;
#else
        uint64_t _reserved0 : 39;
        uint64_t addr : 25;
#endif // _BIG_ENDIAN
    } fields;
} pba_bcde_ocibar_t;



typedef union pba_bcue_ctl {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t stop : 1;
        uint64_t start : 1;
        uint64_t _reserved0 : 62;
#else
        uint64_t _reserved0 : 62;
        uint64_t start : 1;
        uint64_t stop : 1;
#endif // _BIG_ENDIAN
    } fields;
} pba_bcue_ctl_t;

#endif // __ASSEMBLER__
#define PBA_BCUE_CTL_STOP SIXTYFOUR_BIT_CONSTANT(0x8000000000000000)
#define PBA_BCUE_CTL_START SIXTYFOUR_BIT_CONSTANT(0x4000000000000000)
#ifndef __ASSEMBLER__


typedef union pba_bcue_set {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t _reserved0 : 2;
        uint64_t copy_length : 6;
        uint64_t _reserved1 : 56;
#else
        uint64_t _reserved1 : 56;
        uint64_t copy_length : 6;
        uint64_t _reserved0 : 2;
#endif // _BIG_ENDIAN
    } fields;
} pba_bcue_set_t;



typedef union pba_bcue_status {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t running : 1;
        uint64_t waiting : 1;
        uint64_t wrcmp : 6;
        uint64_t _reserved0 : 6;
        uint64_t rdcmp : 6;
        uint64_t debug : 9;
        uint64_t stopped : 1;
        uint64_t error : 1;
        uint64_t done : 1;
        uint64_t _reserved1 : 32;
#else
        uint64_t _reserved1 : 32;
        uint64_t done : 1;
        uint64_t error : 1;
        uint64_t stopped : 1;
        uint64_t debug : 9;
        uint64_t rdcmp : 6;
        uint64_t _reserved0 : 6;
        uint64_t wrcmp : 6;
        uint64_t waiting : 1;
        uint64_t running : 1;
#endif // _BIG_ENDIAN
    } fields;
} pba_bcue_status_t;



typedef union pba_bcue_pbadr {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t _reserved0 : 2;
        uint64_t pb_offset : 23;
        uint64_t _reserved1 : 2;
        uint64_t extaddr : 14;
        uint64_t _reserved2 : 23;
#else
        uint64_t _reserved2 : 23;
        uint64_t extaddr : 14;
        uint64_t _reserved1 : 2;
        uint64_t pb_offset : 23;
        uint64_t _reserved0 : 2;
#endif // _BIG_ENDIAN
    } fields;
} pba_bcue_pbadr_t;



typedef union pba_bcue_ocibar {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t addr : 25;
        uint64_t _reserved0 : 39;
#else
        uint64_t _reserved0 : 39;
        uint64_t addr : 25;
#endif // _BIG_ENDIAN
    } fields;
} pba_bcue_ocibar_t;



typedef union pba_pbocrn {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t _reserved0 : 16;
        uint64_t event : 16;
        uint64_t _reserved1 : 12;
        uint64_t accum : 20;
#else
        uint64_t accum : 20;
        uint64_t _reserved1 : 12;
        uint64_t event : 16;
        uint64_t _reserved0 : 16;
#endif // _BIG_ENDIAN
    } fields;
} pba_pbocrn_t;



typedef union pba_xsndtx {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t snd_scope : 3;
        uint64_t snd_qid : 1;
        uint64_t snd_type : 1;
        uint64_t snd_reservation : 1;
        uint64_t spare1 : 2;
        uint64_t snd_nodeid : 3;
        uint64_t snd_chipid : 3;
        uint64_t spare2 : 2;
        uint64_t _reserved0 : 48;
#else
        uint64_t _reserved0 : 48;
        uint64_t spare2 : 2;
        uint64_t snd_chipid : 3;
        uint64_t snd_nodeid : 3;
        uint64_t spare1 : 2;
        uint64_t snd_reservation : 1;
        uint64_t snd_type : 1;
        uint64_t snd_qid : 1;
        uint64_t snd_scope : 3;
#endif // _BIG_ENDIAN
    } fields;
} pba_xsndtx_t;



typedef union pba_xcfg {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t pbax_en : 1;
        uint64_t reservation_en : 1;
        uint64_t snd_reset : 1;
        uint64_t rcv_reset : 1;
        uint64_t rcv_nodeid : 3;
        uint64_t rcv_chipid : 3;
        uint64_t spare1 : 2;
        uint64_t rcv_brdcst_group : 8;
        uint64_t rcv_datalo_thresh : 8;
        uint64_t snd_retry_thresh : 8;
        uint64_t snd_rsv_req_thresh : 2;
        uint64_t snd_retry_count_overcom : 1;
        uint64_t _reserved0 : 25;
#else
        uint64_t _reserved0 : 25;
        uint64_t snd_retry_count_overcom : 1;
        uint64_t snd_rsv_req_thresh : 2;
        uint64_t snd_retry_thresh : 8;
        uint64_t rcv_datalo_thresh : 8;
        uint64_t rcv_brdcst_group : 8;
        uint64_t spare1 : 2;
        uint64_t rcv_chipid : 3;
        uint64_t rcv_nodeid : 3;
        uint64_t rcv_reset : 1;
        uint64_t snd_reset : 1;
        uint64_t reservation_en : 1;
        uint64_t pbax_en : 1;
#endif // _BIG_ENDIAN
    } fields;
} pba_xcfg_t;



typedef union pba_xsndstat {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t snd_in_progress : 1;
        uint64_t snd_error : 1;
        uint64_t snd_status : 6;
        uint64_t snd_retry_count : 8;
        uint64_t _reserved0 : 48;
#else
        uint64_t _reserved0 : 48;
        uint64_t snd_retry_count : 8;
        uint64_t snd_status : 6;
        uint64_t snd_error : 1;
        uint64_t snd_in_progress : 1;
#endif // _BIG_ENDIAN
    } fields;
} pba_xsndstat_t;



typedef union pba_xsnddat {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t pbax_datahi : 32;
        uint64_t pbax_datalo : 32;
#else
        uint64_t pbax_datalo : 32;
        uint64_t pbax_datahi : 32;
#endif // _BIG_ENDIAN
    } fields;
} pba_xsnddat_t;



typedef union pba_xrcvstat {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t rcv_in_progress : 1;
        uint64_t rcv_error : 1;
        uint64_t rcv_write_in_progress : 1;
        uint64_t rcv_reservation_set : 1;
        uint64_t rcv_capture : 14;
        uint64_t _reserved0 : 46;
#else
        uint64_t _reserved0 : 46;
        uint64_t rcv_capture : 14;
        uint64_t rcv_reservation_set : 1;
        uint64_t rcv_write_in_progress : 1;
        uint64_t rcv_error : 1;
        uint64_t rcv_in_progress : 1;
#endif // _BIG_ENDIAN
    } fields;
} pba_xrcvstat_t;



typedef union pba_xshbrn {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t push_start : 29;
        uint64_t _reserved0 : 35;
#else
        uint64_t _reserved0 : 35;
        uint64_t push_start : 29;
#endif // _BIG_ENDIAN
    } fields;
} pba_xshbrn_t;



typedef union pba_xshcsn {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t push_full : 1;
        uint64_t push_empty : 1;
        uint64_t spare1 : 2;
        uint64_t push_intr_action : 2;
        uint64_t push_length : 5;
        uint64_t notimp1 : 2;
        uint64_t push_write_ptr : 5;
        uint64_t notimp2 : 3;
        uint64_t push_read_ptr : 5;
        uint64_t notimp3 : 5;
        uint64_t push_enable : 1;
        uint64_t _reserved0 : 32;
#else
        uint64_t _reserved0 : 32;
        uint64_t push_enable : 1;
        uint64_t notimp3 : 5;
        uint64_t push_read_ptr : 5;
        uint64_t notimp2 : 3;
        uint64_t push_write_ptr : 5;
        uint64_t notimp1 : 2;
        uint64_t push_length : 5;
        uint64_t push_intr_action : 2;
        uint64_t spare1 : 2;
        uint64_t push_empty : 1;
        uint64_t push_full : 1;
#endif // _BIG_ENDIAN
    } fields;
} pba_xshcsn_t;



typedef union pba_xshincn {

    uint64_t value;
    struct {
#ifdef _BIG_ENDIAN
        uint32_t high_order;
        uint32_t low_order;
#else
        uint32_t low_order;
        uint32_t high_order;
#endif // _BIG_ENDIAN
    } words;
    struct {
#ifdef _BIG_ENDIAN
        uint64_t reserved : 64;
#else
        uint64_t reserved : 64;
#endif // _BIG_ENDIAN
    } fields;
} pba_xshincn_t;


#endif // __ASSEMBLER__
#endif // __PBA_FIRMWARE_REGISTERS_H__


