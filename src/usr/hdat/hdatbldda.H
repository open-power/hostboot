/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatbldda.H $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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

#ifndef HDATBLDDA_H
#define HDATBLDDA_H


/**
 *  @file hdatbldda.H
 *
 *  @brief This file contains the interfaces for building hypervisor data
 *         areas.
 */

/*----------------------------------------------------------------------------*/
/* Includes                                                                   */
/*----------------------------------------------------------------------------*/
#include <stdint.h>          // standard types
#include <hdat/hdat.H>            // HDAT header type definitions
#include "hdatvpd.H"
#include <errl/errlentry.H>       // ErrlEntry class definition
#include <hdat/hdat_reasoncodes.H>
#include "../vpd/mvpd.H"
#include "../vpd/ipvpd.H"
#include "../vpd/pvpd.H"
using namespace MVPD;
using namespace PVPD;
using namespace IPVPD;

namespace HDAT
{

/** @brief Constant for the eye catcher for VPD structures
 */
const char HDAT_FRU_VPD_STRUCT_NAME[] = "FRUVPD";
const char HDAT_SYS_VPD_STRUCT_NAME[] = "SYSVPD";


/** @enum hdatSpiraDataAreas
 *        This enumeration defines the various data areas that must be built
 T_MISC_VPD_FILE_NAME
 *        processor.
 *        This list must be kept in the same order as the 5-tuple entries in
 *        the SPIRA.
 *
 *        If the order is changed, entries are added, or entries are deleted,
 *        update the HDAT_STR_NAME array in hdatPrtSpira().
 */
enum hdatSpiraDataAreas
{
  HDAT_SPIRA_DA_FIRST   = 0,
  HDAT_SP_SUBSYS        = 0,    // service processor subsystem
  HDAT_IPL_PARAMS        = 1,    // IPL parameters
  HDAT_ENCLOSURE_VPD    = 2,    // enclosure vital product data
  HDAT_SLCA             = 3,    // slot location code array
  HDAT_BACKPLANE_VPD    = 4,    // backplane vital product data
  HDAT_SYS_VPD          = 5,    // system vital product data
  HDAT_CHIP_TOD         = 6,    // chip time-of-day
  HDAT_PROC_INIT        = 7,    // phyp-supplied processor init data
  HDAT_CLOCK_VPD        = 8,    // clock vital product data
  HDAT_ANCHOR_VPD       = 9,    // anchor card vital product data
  HDAT_OP_PNL_VPD       = 10,   // operator panel vital product data
  HDAT_L3_VPD           = 11,   // level 3 cache vital product data
  HDAT_MISC_CEC_VPD     = 12,   // miscellaneous FRU vital product data
  HDAT_PACA             = 13,   // processor address communication area
  HDAT_MDT              = 14,   // memory description tree
  HDAT_IO_HUB           = 15,   // I/O hub FRU array
  HDAT_CPU_CTRL         = 16,   // CPU controls
  HDAT_MS_DUMP_SRC_TBL  = 17,   // mainstore dump source table (can change at run time)
  HDAT_MS_DUMP_DST_TBL  = 18,   // mainstore dump destination table (can change at run time)
  HDAT_MS_DUMP_RSLT_TBL = 19,   // mainstore dump results table
  HDAT_SPIRA_DA_GA1LAST = 20,   // End of list for 1st eclipz release
  HDAT_HEAP             = 20,   // Phyp allocated storage location for most of the data
  HDAT_SPIRA_OLDPACA_LAST = 21, // This was last entry for old PACA format.                                  //bs01a

  HDAT_PCIA             = 21,   // PCIA (Core information area) starting out on  P7+                         //bs01a
  HDAT_PCRD             = 22,   // PCRD (Chip related data area) starting out on P7+                         //bs01a
  HDAT_HOSTSR           = 23,   // HOSTSR (Host service data) starting out on P8                             //rij01A
  HDAT_SPIRA_DA_LAST    = 24                                                                                 //bs01c
};

/**
 * @brief The routines in this file drive the building of the various hypervisor
 *        data areas
 *
 * @pre
 *
 * @post
 *
 * @param[in] i_dataArea - An identifier for the specific data area
 * @param[in] i_msAddr   - The main store address where this data area
 *                     will be written to.
 * @param[out] o_count - number of instance of each area
 * @param[out] o_size  - actual size wrote to memory
 *
 * @return A null error log handle if successful, else the return code pointed 
 *         to by errlHndl_t contains one of:
 *
 */

/* Build the specific VPD data areas */
errlHndl_t hdatBldSpecificVpd(hdatSpiraDataAreas i_dataArea,
                              const hdatMsAddr_t &i_msAddr,
                              uint32_t &o_count,
                              uint32_t &o_size);

/**
 * @brief This function build vpd structure and write the data to MS memory.
 *
 * @pre
 *
 * @post
 *
 * @param[in] i_msAddr   - The main store address where this data area
 * @param[in] i_dataArea - An identifier for the specific data area
 *                     will be written to.
 * @param[in] i_fetchVpd - VPD record and keyword details                    
 * @param[in] i_size     - number of entries in VPD table
 * @param[in] i_vpdtype  - type of fru
 * @param[out] o_count - number of instance of each area
 * @param[out] o_size  - actual size wrote to memory
 *
 * @return A null error log handle if successful, else the return code pointed 
 *         to by errlHndl_t contains one of:
 *
 */
errlHndl_t hdatProcessFru(const hdatMsAddr_t &i_msAddr,
                                const hdatSpiraDataAreas i_dataArea,
                                const IpVpdFacade::recordInfo i_fetchVpd[],
                                const uint8_t i_size,
                                vpdType i_vpdtype,
                                uint32_t &o_count,
                                uint32_t &o_size);
};
#endif //HDATBLDDA_H
