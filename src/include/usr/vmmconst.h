/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/vmmconst.h $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2020                        */
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
#ifndef _VMMCONST_H
#define _VMMCONST_H

/**
 * This file contains any hardcoded memory addresses used by the
 * Virtual Memory Subsystem
 */

#include <limits.h>

/**
 * Segments
 */

/** Stacks are all 1TB in size. */
#define VMM_SEGMENT_SIZE (1 * TERABYTE)

/** Base Segment is at 0 TB */
#define VMM_VADDR_BASE_SEGMENT  (0 * TERABYTE)

/** Stack Segment is at 1 TB */
#define VMM_VADDR_STACK_SEGMENT  (VMM_VADDR_BASE_SEGMENT + VMM_SEGMENT_SIZE)

/** Device Segments are at 2 TB - 10 TB */
#define VMM_VADDR_DEVICE_SEGMENT_FIRST  \
            (VMM_VADDR_STACK_SEGMENT + VMM_SEGMENT_SIZE)

#define VMM_VADDR_DEVICE_SEGMENT_LAST  \
            (VMM_VADDR_DEVICE_SEGMENT_FIRST + (8 * VMM_SEGMENT_SIZE))

/**
 * Blocks
 */

/** Base Segment Base Block Base Address */
#define VMM_ADDR_BASE_BLOCK 0

/** Maximize size of Base Segment Memory after expansion */
#define VMM_MEMORY_SIZE (64*MEGABYTE)

/**
 * Resource Providers
 */

/** Extended Image is at 1GB */
#define VMM_VADDR_VFS_EXT_MODULE  (1 * GIGABYTE)
// Note : vfs.h hardcodes this value due to external compile issues

/** PNOR Resource Provider is at 2GB */
#define VMM_VADDR_PNOR_RP  (2 * GIGABYTE)

/** Temp PNOR Resource Provider space is at 5GB */
#define VMM_VADDR_SPNOR_TEMP (5 * GIGABYTE)

/** The delta between PNOR RP and temp space and
 *  the delta between temp space and Secure PNOR RP space is 3GB
 */
#define VMM_VADDR_SPNOR_DELTA (VMM_VADDR_SPNOR_TEMP - VMM_VADDR_PNOR_RP)

/** Secure PNOR Resource Provider is at 8GB */
#define VMM_VADDR_SPNOR_RP (VMM_VADDR_SPNOR_TEMP + VMM_VADDR_SPNOR_DELTA)

/** SBE Update process is at 3GB, see the map layout in sbe_update.H */
#define VMM_VADDR_SBE_UPDATE (3 * GIGABYTE)
/* See sbe_update.H SBE VADDR Layout map for usage and sizes needed */
#define VMM_SBE_UPDATE_SIZE (4096 * KILOBYTE)
#define VMM_VADDR_SBE_UPDATE_END (VMM_VADDR_SBE_UPDATE + VMM_SBE_UPDATE_SIZE)

/** Debug Comm Channel is at 3.5GB, uses 32KB */
#define VMM_VADDR_DEBUG_COMM ((3 * GIGABYTE) + (500 * MEGABYTE))
#define VMM_DEBUG_COMM_SIZE (32 * KILOBYTE)
#define VMM_VADDR_DEBUG_COMM_END (VMM_VADDR_DEBUG_COMM + VMM_DEBUG_COMM_SIZE)

/** Virtual address space for WOF Tables - 32GB for 50MB */
#define VMM_VADDR_WOFDATA_LID  (32 * GIGABYTE)
#define VMM_SIZE_WOFDATA_LID   (50 * MEGABYTE)

/** Attribute Resource Provider */
// Note: Not simplified to make it easier to extract with the PNOR targeting
// image generator script
// WARNING: 4 GB range deliberately chosen so that 64-bit Hostboot pointers
// are similar to 32 bit FSP pointers, except that the upper 32 bits are
// set to 0x00000001.  This allows both FSP and Hostboot to opearate on the same
// targeting image
#define VMM_VADDR_ATTR_RP  (4ul * 1024ul * 1024ul * 1024ul)

/** Virtual memory block priorities */
enum BlockPriority
{
    PNOR_PRIORITY  = 0, //No dependencies
    SPNOR_PRIORITY = (PNOR_PRIORITY + 1), //Dependent on PNOR
    VFS_PRIORITY   = (SPNOR_PRIORITY + 1), //Dependent on PNOR and SPNOR
    ATTR_PRIORITY  = (SPNOR_PRIORITY + 1), //Dependent on PNOR and SPNOR
};

/**
 * Other Constants
 */

/** Segment Size in bits per SLBE  */
#define SLBE_s 40

/** Page Size in bits per SLBE  */
#define SLBE_b 12

/** Hostboot reserved memory */
#define VMM_HRMOR_OFFSET ((4 * GIGABYTE) - (256*MEGABYTE))
#define VMM_HB_RSV_MEM_SIZE (256*MEGABYTE)

/** Hardwired offsets from HRMOR to HOMER images in real mem */
/** HOMER starts immediately after our HB memory */
/**    <n0p0 HRMOR = 4GB-256MB> + <memory size = 64MB> = 3904 MB */
/** HOMER is 4 MB per proc, 4 procs = 16MB */
/** Each HOMER must start on a 4MB offset to meet OCC requirements */
#define VMM_HOMER_REGION_START_OFFSET (VMM_MEMORY_SIZE)
#define VMM_HOMER_INSTANCE_SIZE_IN_MB (4)
#define VMM_HOMER_INSTANCE_SIZE \
 (VMM_HOMER_INSTANCE_SIZE_IN_MB*MEGABYTE)
#define VMM_HOMER_REGION_SIZE (VMM_HOMER_INSTANCE_SIZE*8)
#define VMM_HOMER_REGION_END_OFFSET \
 (VMM_HOMER_REGION_START_OFFSET + VMM_HOMER_REGION_SIZE)
/** HOMER_REGION_END = 208MB */

/** Physical Memory for OCC common space - 8MB total */
/** OCC Common must be on an 8MB offset */
#define VMM_OCC_BOOTLOADER_SIZE (1 * PAGESIZE)
#define VMM_OCC_COMMON_START_OFFSET VMM_HOMER_REGION_END_OFFSET
#define VMM_OCC_COMMON_SIZE_IN_MB 8
#define VMM_OCC_COMMON_SIZE \
 (VMM_OCC_COMMON_SIZE_IN_MB*MEGABYTE)
#define VMM_OCC_COMMON_END_OFFSET \
 (VMM_OCC_COMMON_START_OFFSET + VMM_OCC_COMMON_SIZE)
/** End of Common Area = 216MB */

/** Total Memory required for HOMERs and OCC Common */
#define VMM_ALL_HOMER_OCC_MEMORY_SIZE \
 (VMM_OCC_COMMON_SIZE + VMM_HOMER_REGION_SIZE)

/**
 * Memory for Architected state (max 4 procs - 256KB Each)
 * XXX MPIPL depends on memory reservation layout. Any change in the
 *     reservation order impact MPIPL (see copyArchitectedRegs()).
 */
#define VMM_ARCH_REG_DATA_START_OFFSET VMM_OCC_COMMON_END_OFFSET
#define VMM_ARCH_REG_DATA_PER_PROC_SIZE_IN_KB 256
#define VMM_ARCH_REG_DATA_PER_PROC_SIZE \
 ( VMM_ARCH_REG_DATA_PER_PROC_SIZE_IN_KB*KILOBYTE )
//TODO: via RTC:254920 update for Everest
//(4 Procs * 184 registers) + FAPI FFDC space
#define VMM_ARCH_REG_DATA_SIZE_ALL_PROC_IN_MB 3
#define VMM_ARCH_REG_DATA_SIZE_ALL_PROC \
 ( VMM_ARCH_REG_DATA_SIZE_ALL_PROC_IN_MB*MEGABYTE )
#define VMM_ARCH_REG_DATA_END_OFFSET \
 ( VMM_ARCH_REG_DATA_START_OFFSET + VMM_ARCH_REG_DATA_SIZE_ALL_PROC )
/** End offset for the Architected region is 217MB **/

/** Memory for attribute data */
#define VMM_ATTR_DATA_START_OFFSET  VMM_ARCH_REG_DATA_END_OFFSET
#define VMM_ATTR_DATA_SIZE (1*MEGABYTE)
/** End of Attr Area = 218MB */

/** Memory for hostboot data Table of Contents */
#define VMM_HB_DATA_TOC_START_OFFSET \
    (VMM_ATTR_DATA_START_OFFSET + VMM_ATTR_DATA_SIZE) /* currently 218MB */

/** Variable Attribute overrides and Attributes memory here **/

/** Memory for VPD (1 MB total) */
#define VMM_MODULE_VPD_SIZE (512*KILOBYTE)          /* must be 64KB aligned */
#define VMM_CENTAUR_VPD_SIZE (256*KILOBYTE)         /* must be 64KB aligned */
#define VMM_DIMM_JEDEC_VPD_SIZE (256*KILOBYTE)      /* must be 64KB aligned */
#ifndef CONFIG_SUPPORT_EEPROM_CACHING
#define VMM_RT_VPD_SIZE ( VMM_MODULE_VPD_SIZE + \
                          VMM_DIMM_JEDEC_VPD_SIZE )
#else
// @TODO RTC 246430
// Re-compensate for when EECACHE ECC is removed (reduce to non-ECC size)
#define VMM_RT_VPD_SIZE (2816*KILOBYTE) /* 2816KB aligned (size EECACHE section size) */
#endif


/** Internode communication area outside of the HB image.
 * Preserved between mpipl.
 *
 * @node There is one area per hostboot instance.
 *  Need to add (ATTR_HB_HRMOR_NODAL_BASE * hbinstance_num) to this
 *  address to get the physical address
 */
#define VMM_INTERNODE_PRESERVED_MEMORY_SIZE (4*MEGABYTE)
#define VMM_INTERNODE_PRESERVED_MEMORY_ADDR (VMM_HB_RSV_MEM_SIZE - \
                                            VMM_INTERNODE_PRESERVED_MEMORY_SIZE)

/** PHYP ATTN AREA OFFSET */
/** This offset is relative to the HRMOR of a given node */
#define PHYP_ATT_AREA_SIZE (64*MEGABYTE)
#define PHYP_ATTN_AREA_OFFSET (VMM_INTERNODE_PRESERVED_MEMORY_ADDR - \
                               PHYP_ATT_AREA_SIZE)
#define PHYP_ATTN_AREA_1_SIZE (1*KILOBYTE)


/**
 * Test Constants
 */

/** Base virtual address used in remove pages test */
#define VMM_VADDR_RMVPAGE_TEST (700 * GIGABYTE)

/** Block size used in remove pages test */
#define VMM_SIZE_RMVPAGE_TEST (8 * PAGESIZE)

/** Chunk of physical memory used for Dump Source Table */
#define DUMP_TEST_MEMORY_ADDR (256*MEGABYTE)
#define DUMP_TEST_MEMORY_SIZE (4*MEGABYTE)
/** End of Dump Test Area = 260MB */



/**
 * Physical Memory Constants
 */


/** Layout
 * (HRMOR+64MB)..(HRMOR+96MB): HOMER for each proc (32MB)
 * (HRMOR+96MB)..(HRMOR+104MB): OCC Common (8MB)
 * (HRMOR+104MB)..(HRMOR+105MB): Arch reg data (1MB)
 * (HRMOR+105MB)..(HRMOR+106MB): HBRT Data TOC (hbrtTableOfContents_t)
 * (HRMOR+106MB): Reserved mem start
 * (HRMOR+(168MB-20KB)): Reserved mem end
 * (HRMOR+(168MB-20KB))..(HRMOR+168MB): MCL_ADDR (20KB)
 * (HRMOR+168MB)..(HRMOR+232MB): MCL_TMP_ADDR (64MB + PAGESIZE)
 * (HRMOR+232MB)..(HRMOR+248MB): HDAT_TMP_ADDR (16MB)
 * (HRMOR+248MB)..(HRMOR+252MB): TCE Table (needs to be 4-byte aligned) (4MB)
 * (HRMOR+252MB)..(HRMOR+256MB): VMM_INTERNODE_PRESERVED_MEMORY_ADDR (4MB)
 * (HRMOR+256MB): The end of usable memory
 */

/* Reserved memory starts with HB TOC and ends on MCL_ADDR */
#define RESERVED_MEM_MAX_SIZE (MCL_ADDR - VMM_HB_DATA_TOC_START_OFFSET)
#define RESERVED_MEM_START_OFFSET (VMM_HB_DATA_TOC_START_OFFSET)
#define RESERVED_MEM_END_OFFSET (MCL_ADDR)

/** Two memory locations for MCL processing **/
// Note: 2 spaces needed so the MCL can be initialized without wiping out PHYP
// Location for the MCL itself to sit in.
#define MCL_SIZE (20*KILOBYTE)
#define MCL_ADDR (MCL_TMP_ADDR - MCL_SIZE)
// Location for PHYP to be loaded into and reused for all Master Container Lids
// Verification is done in a temporary, non-secure area of mainstore memory,
// then relocated to its final, secure location in mainstore.
#define MCL_TMP_SIZE ((64 * MEGABYTE) + PAGESIZE)
#define MCL_TMP_ADDR (HDAT_TMP_ADDR - MCL_TMP_SIZE)

// Location for HDAT to be loaded into via TCEs by FSP
// Verification is done in a temporary, non-secure area of mainstore memory,
// then relocated to its final, secure location in mainstore.
#define HDAT_TMP_SIZE (16 * MEGABYTE)
#define HDAT_TMP_ADDR (TCE_TABLE_ADDR - HDAT_TMP_SIZE)

/** The TCE Table size is 512K entries each uint64_t (8 bytes) in size */
#define TCE_TABLE_SIZE  ((512*KILOBYTE)*sizeof(uint64_t))

/** Physical memory location of the TCE Table */
/** - needs to be aligned on 4MB boundary     */
#define TCE_TABLE_ADDR  (VMM_INTERNODE_PRESERVED_MEMORY_ADDR - TCE_TABLE_SIZE)

/** Physical memory location used for Unsecure Memory Region Testing */
/** - place it after TCE Table */
#define UNSECURE_MEM_REGION_ADDR_TEST (TCE_TABLE_ADDR + TCE_TABLE_SIZE)

#define UNSECURE_MEM_REGION_SIZE_TEST (1*KILOBYTE)


/** PreVerifiedLidMgr test space */
#define PREVERLIDMGR_TEST_ADDR  (512*MEGABYTE)
#define PREVERLIDMGR_TEST_SIZE  (64*MEGABYTE)

#endif /* _VMMCONST_H */
