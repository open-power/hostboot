/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/vpd/ipz_vpd_consts.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
/**
  * @file ipz_vpd_consts.H
  * @brief Miscellaneous IPZ VPD definitions
  */

// Following values are from the common_vpd_architecture doc
constexpr uint8_t  RECORD_BYTE_SIZE           = 4;
constexpr uint8_t  RECORD_ADDR_BYTE_SIZE      = 2;
constexpr uint8_t  RECORD_SIZE_BYTE_OFFSET    = 1;
constexpr uint8_t  RECORD_SIZE_BYTE_SIZE      = 2;
constexpr uint8_t  KEYWORD_BYTE_SIZE          = 2;
constexpr uint8_t  KEYWORD_SIZE_BYTE_SIZE     = 1;
constexpr uint8_t  RECORD_TOC_UNUSED          = 2;
constexpr uint8_t  RT_SKIP_BYTES              = 3;
constexpr uint8_t  VHDR_ECC_DATA_SIZE         = 11;
constexpr uint8_t  RESOURCE_ID_SIZE           = 1;
constexpr uint8_t  VPD_RECORD_START_MAGIC_NUM = 0x84;
constexpr uint8_t  VPD_RECORD_END_MAGIC_NUM   = 0x78;
constexpr uint16_t MAX_RECORD_SIZE            = 0xFFFF;
constexpr uint8_t  MAX_KEYWORD_SIZE           = 0xFF;
constexpr uint16_t ASCII_RT                   = 0x5254;
// Total size of VPD Header (VHDR) record, includes ECC, magic numbers, etc
constexpr uint16_t VPD_HEADER_TOTAL_RECORD_SIZE = 55;
const char* const VPD_HEADER_RECORD_NAME("VHDR");
const char* const VPD_TABLE_OF_CONTENTS_RECORD_NAME("VTOC");
const char* const VPD_KEYWORD_POINTER_TO_RECORD("PT");

/**
  * @brief Structure representing the first 10 bytes of all
  *        IPZ records except the VHDR record
  */
struct standard_ipz_record_hdr
{
    uint8_t  large_resource;
    uint16_t record_length;
    uint16_t rt_kw_name;
    uint8_t  rt_kw_len;
    uint32_t rt_kw_val;
} PACKED;

/**
  * @brief Structure representing the format of each record
  *        in the PT keyword of the VTOC or VHDR.
  */
struct pt_entry {
    char record_name[RECORD_BYTE_SIZE] = {0x00,0x00,0x00,0x00};
    // All uint16 fields are stored in little endian.
    uint16_t record_type   = 0x0000;
    uint16_t record_offset = 0x0000;
    uint16_t record_length = 0x0000;
    uint16_t ecc_offset    = 0x0000;
    uint16_t ecc_length    = 0x0000;
} PACKED;

// VHDR is one of the records we must generate and prepend to the IPZ VPD
// buffer we are generating. A lot of the fields of the vhdr_record are known
// at compile time so creating a struct with a specialized constructor easily
// packages the information for us.
// See Common VPD Architecture document for details
// NOTE : kw_name vars are ascii
//        record_len var is little-endian
//        ecc offset/len is irrelevant to us
//        pt entry types are irrelevant to us
struct vhdr_record
{
   uint8_t     ecc[11] = {0x00};        // (unused)
   uint8_t     large_resource = VPD_RECORD_START_MAGIC_NUM; // 0x84
   uint16_t    record_len = 0x2800;     // 0x2800
   uint16_t    rt_kw_name = 0x5254;     // "RT"
   uint8_t     rt_kw_len  = 0x04;       // 0x04
   uint32_t    rt_kw_data = 0x56484452; // "VHDR"
   uint16_t    vd_kw_name = 0x5644;     // "VD"
   uint8_t     vd_kw_len  = 0x02;       // 0x02
   uint16_t    vd_kw_data = 0x3031;     // "01"
   uint16_t    pt_kw_name = 0x5054;     // "PT"
   uint8_t     pt_kw_len  = 0x0E;       // 0x0E
   uint32_t    pt_kw_vtoc_name = 0x56544F43; // "VTOC"
   uint16_t    pt_kw_vtoc_type = 0x0000;     // (unused, doesn't really matter)
   uint16_t    pt_kw_vtoc_off  = 0x3700;     // 0x3700   (little-endian)
   uint16_t    pt_kw_vtoc_len  = 0x0000;     // set by ctor (little-endian)
   uint16_t    pt_kw_vtoc_ecc_off = 0x0000; // (unused, doesn't really matter)
   uint16_t    pt_kw_vtoc_ecc_len = 0x0000; // (unused, doesn't really matter)
   uint16_t    pf_kw_name = 0x5046;  // "PF"
   uint8_t     pf_kw_len  = 0x08;    // 0x08
   uint64_t    pf_kw_data = 0x0000000000000000;
   uint8_t     small_resource = VPD_RECORD_END_MAGIC_NUM;   // 0x78

   vhdr_record(uint16_t vtoc_len) :
                   pt_kw_vtoc_len(htole16(vtoc_len)) {};
} PACKED;
