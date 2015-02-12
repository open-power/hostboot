/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/vmmconst.h $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2015                        */
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

/** Base Segment Base Block size */
#define VMM_BASE_BLOCK_SIZE (8*MEGABYTE)

/** Base Segment Extended Memory Block Base Address */
#define VMM_ADDR_EXTEND_BLOCK (VMM_ADDR_BASE_BLOCK + VMM_BASE_BLOCK_SIZE)

/** Maximize size of Base Segment Memory after expansion */
#define VMM_MEMORY_SIZE (32*MEGABYTE)

/** Base Segment Extended Memory Block Size */
#define VMM_EXTEND_BLOCK_SIZE (VMM_MEMORY_SIZE-VMM_BASE_BLOCK_SIZE)

/**
 * Resource Providers
 */

/** Extended Image is at 1GB */
#define VMM_VADDR_VFS_EXT_MODULE  (1 * GIGABYTE)
// Note : vfs.h hardcodes this value due to external compile issues

/** PNOR Resource Provider is at 2GB */
#define VMM_VADDR_PNOR_RP  (2 * GIGABYTE)

/** SBE Update process is at 3GB, uses 256KB */
#define VMM_VADDR_SBE_UPDATE (3 * GIGABYTE)
#define VMM_SBE_UPDATE_SIZE (256*KILOBYTE)
#define VMM_VADDR_SBE_UPDATE_END (VMM_VADDR_SBE_UPDATE + VMM_SBE_UPDATE_SIZE)

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
    PNOR_PRIORITY = 0, //No dependencies
    VFS_PRIORITY  = (PNOR_PRIORITY + 1), //Dependent on PNOR
    ATTR_PRIORITY = (PNOR_PRIORITY + 1), //Dependent on PNOR
};

/**
 * Other Constants
 */

/** Segment Size in bits per SLBE  */
#define SLBE_s 40

/** Page Size in bits per SLBE  */
#define SLBE_b 12

/** Hardwired pointer to HOMER images in real mem */
/** HOMER starts at 128MB + 32MB = 160MB */
/** HOMER is 4 MB per proc, 8 procs = 32MB */
/** Each HOMER must start on a 4MB offset to meet OCC requirements */
#define VMM_HOMER_REGION_START_ADDR (128*MEGABYTE + 32*MEGABYTE)
#define VMM_HOMER_INSTANCE_SIZE_IN_MB (4)
#define VMM_HOMER_INSTANCE_SIZE \
 (VMM_HOMER_INSTANCE_SIZE_IN_MB*MEGABYTE)
#define VMM_HOMER_REGION_SIZE (VMM_HOMER_INSTANCE_SIZE*8)
/** HOMER_REGION_END = 192MB */
#define VMM_HOMER_REGION_END_ADDR \
 (VMM_HOMER_REGION_START_ADDR + VMM_HOMER_REGION_SIZE)

/** Physical Memory for OCC common space - 8MB total */
/** OCC Common must be on an 8MB offset */
/** Start = End of Homer, currently 192MB */
#define VMM_OCC_COMMON_START_ADDR VMM_HOMER_REGION_END_ADDR
#define VMM_OCC_COMMON_SIZE_IN_MB 8
#define VMM_OCC_COMMON_SIZE \
 (VMM_OCC_COMMON_SIZE_IN_MB*MEGABYTE)
#define VMM_OCC_COMMON_END \
 (VMM_OCC_COMMON_START_ADDR + VMM_OCC_COMMON_SIZE)

/** Total Memory required for HOMERs and OCC Common */
#define VMM_ALL_HOMER_OCC_MEMORY_SIZE \
 (VMM_OCC_COMMON_SIZE+VMM_HOMER_REGION_SIZE)


/** Reserved runtime VPD sizes in bytes */
//  must be 64KB aligned
#define VMM_MODULE_VPD_SIZE 0x80000
#define VMM_CENTAUR_VPD_SIZE 0x40000
#define VMM_DIMM_JEDEC_VPD_SIZE 0x40000

/** Total VPD image size */
#define VMM_RT_VPD_SIZE (VMM_MODULE_VPD_SIZE + \
                         VMM_CENTAUR_VPD_SIZE + \
                         VMM_DIMM_JEDEC_VPD_SIZE)

/** Memory offset for runtime VPD image */
// Given value is number of bytes BELOW the top of memory to store
// the runtime image(s)  Currently below the OCC HOMER IMAGE
#define VMM_RT_VPD_OFFSET (VMM_RT_VPD_SIZE + \
                           VMM_ALL_HOMER_OCC_MEMORY_SIZE)


/** Internode communication area outside of the HB image.
 * Preserved between mpipl.
 *
 * @node There is one area per hostboot instance.
 *  Need to add (ATTR_HB_HRMOR_NODAL_BASE * hbinstance_num) to this
 *  address to get the physical address
 */
#define VMM_INTERNODE_PRESERVED_MEMORY_ADDR (96 * MEGABYTE)

/** Region of memory reserved for unsecure memory accesses
 *
 *  The Secure BAR is placed at 64MB so that initially, everything above
 *  is marked secure and everything below is marked unsecure.  External
 *  entities, such as FSP, can only access memory in the unsecure region.
 *  Items such as the Mailbox DMA buffer need to be placed into this region.
 *
 *  We do not want to place this region directly at zero because in some cases
 *  we load a payload at address 0 (ex. Sapphire) and need to make sure there
 *  is enough room for the payload before any reserved unsecure space.
 *
 *  Choosing (Secure BAR - Cache Size) as the value for this region, which
 *  allows us to have a payload image up to that size and up to 'Cache Size'
 *  worth of unsecure content.
 */
#define VMM_UNSECURE_RESERVED_MEMORY_BASEADDR (56 * MEGABYTE)

/**
 * Test Constants
 */

/** Base virtual address used in remove pages test */
#define VMM_VADDR_RMVPAGE_TEST (700 * GIGABYTE)

/** Block size used in remove pages test */
#define VMM_SIZE_RMVPAGE_TEST (8 * PAGESIZE)

/** Chunk of physical memory to use for HostServices Attributes */
#define HSVC_TEST_MEMORY_ADDR   (VMM_MEMORY_SIZE + 32*MEGABYTE)
#define HSVC_TEST_SYSDATA_SIZE  (4*KILOBYTE)  /* match FSP HDAT code */
#define HSVC_TEST_NODEDATA_SIZE (256000)      /* match FSP HDAT code */
#define HSVC_TEST_MEMORY_SIZE   \
   ALIGN_PAGE((HSVC_TEST_SYSDATA_SIZE+HSVC_TEST_NODEDATA_SIZE))

/* Chunk of physical memory used for Dump Source Table */
#define DUMP_TEST_MEMORY_ADDR (HSVC_TEST_MEMORY_ADDR + HSVC_TEST_MEMORY_SIZE)
#define DUMP_TEST_MEMORY_SIZE  (4*MEGABYTE)

/** Location of the TCE Table */
#define TCE_TABLE_ADDR  (90*MEGABYTE)

// The size if 512K bytes of entries each uint64_t or 8 bytes in size.
#define TCE_TABLE_SIZE  ((512*KILOBYTE)*sizeof(uint64_t))

#endif /* _VMMCONST_H */
