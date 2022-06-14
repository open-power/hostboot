/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/extended/hb_fru.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2022                        */
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
 *  @file hb_fru.H
 *  @brief Header for utility functions that manipulate PLDM
 *         fru record table info
 */

#ifndef HB_FRU_H
#define HB_FRU_H

#include <errl/errlentry.H>
#include <pldm/pldm_const.H>

namespace PLDM
{

// Struct used to map ATTR_BUS_RAIL_LOCATION_MAP
// Must match the sizes found in attribute_types_openpower.xml
struct bus_rail_loc_map {
    uint8_t bus;
    uint8_t rail;
    char location[VRM_LOCATION_SIZE];
} __attribute__((packed));

// Struct used to map ATTR_LOCATION_PN_SN_CCIN_MAP
// Must match the sizes found in attribute_types_openpower.xml
struct loc_pn_sn_ccin_map {
    char location[VRM_LOCATION_SIZE];
    uint8_t pn[VRM_PN_SIZE];
    uint8_t sn[VRM_SN_SIZE];
    uint8_t ccin[VRM_CCIN_SIZE];
} __attribute__((packed));

/**
 * @brief Utility function that will perform PLDM operations necessary to lookup
 *        the fru record table from the BMC and read out the VPD Hostboot cares about
 *        and store it in the EECACHE section of PNOR
 *
 * @return returns error log if error occurs, otherwise returns nullptr
 */
errlHndl_t cacheRemoteFruVpd(void);

/**
 * @brief Utility function to print out all records contained in
 *        the fru table we got from the getFruRecordTable request.
 *        See https://www.dmtf.org/standards/pmci for references
 *
 * @param[in] i_pldm_fru_table_buf Ptr to a buffer which contains data defined
 *                                 in Table 7 of DSP0257 v1.0.0
 * @param[in] i_record_count       Number of records in the fru record table
 *
 * @note Output is written to g_trac_pldm trace buffer
 *
 * @return void
 */
void printFruRecordTable(const uint8_t* i_pldm_fru_table_buf,
                         uint16_t i_record_count);
}

#endif
