/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mctp/libmctp-lpc.h $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
#ifndef _LIBMCTP_LPCL_H
#define _LIBMCTP_LPCL_H

/**
 * @file libmctp-lpc.h
 * @brief header with common code for lpc binding
 */
// Headers from local directory
#include "extern/libmctp.h"

struct mctp_lpcmap_hdr {
  uint32_t  magic;

  uint16_t  bmc_ver_min;
  uint16_t  bmc_ver_cur;
  uint16_t  host_ver_min;
  uint16_t  host_ver_cur;
  uint16_t  negotiated_ver;
  uint16_t  pad0;

  uint32_t  rx_offset;
  uint32_t  rx_size;
  uint32_t  tx_offset;
  uint32_t  tx_size;
} __attribute__((packed));

// first 4 bytes of config area of MCTP space
const uint32_t MCTP_MAGIC = 0x4d435450;
// Bits we care about in STATUS register
const uint8_t KCS_STATUS_BMC_READY      = 0x80;
const uint8_t KCS_STATUS_CHANNEL_ACTIVE = 0x40;
const uint8_t KCS_STATUS_COMMAND_DATA   = 0x08;
const uint8_t KCS_STATUS_IBF            = 0x02;
const uint8_t KCS_STATUS_OBF            = 0x01;
// KCS data register possible values
const uint8_t KCS_INIT        = 0x00;
const uint8_t KCS_TX_BEGIN    = 0x01;
const uint8_t KCS_RX_COMPLETE = 0x02;
const uint8_t KCS_DUMMY       = 0xFF;


enum mctp_binding_lpc_kcs_reg {
  MCTP_LPC_KCS_REG_DATA = 0,
  MCTP_LPC_KCS_REG_STATUS = 1,
};

struct mctp_binding_lpc_ops {
  int (*kcs_read)(void *data, enum mctp_binding_lpc_kcs_reg reg,
      uint8_t *val);
  int (*kcs_write)(void *data, enum mctp_binding_lpc_kcs_reg reg,
      uint8_t val);
  int (*lpc_read)(void *data, void *buf, uint64_t offset, size_t len);
  int (*lpc_write)(void *data, void *buf, uint64_t offset, size_t len);
  void (*nanosleep)(uint64_t i_sec, uint64_t nsec);
  void (*do_shutdown)(uint64_t i_status);
  void (*console_print)(const char* i_message);
};

#endif
