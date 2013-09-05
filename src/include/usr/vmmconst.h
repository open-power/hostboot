/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/vmmconst.h $                                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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


/**
 * Test Constants
 */

/** Base virtual address used in remove pages test */
#define VMM_VADDR_RMVPAGE_TEST (700 * GIGABYTE)

/** Block size used in remove pages test */
#define VMM_SIZE_RMVPAGE_TEST (8 * PAGESIZE)

/** Chunk of physical memory to use for HostServices Attributes */
#define HSVC_TEST_MEMORY_ADDR  (VMM_MEMORY_SIZE + 32*MEGABYTE)
#define HSVC_TEST_MEMORY_SIZE  (2*MEGABYTE)

/* Chunk of physical memory used for Dump Source Table */
#define DUMP_TEST_MEMORY_ADDR (HSVC_TEST_MEMORY_ADDR + HSVC_TEST_MEMORY_SIZE)
#define DUMP_TEST_MEMORY_SIZE  (4*MEGABYTE)

/** Location of the TCE Table */
#define TCE_TABLE_ADDR  (90*MEGABYTE)

// The size if 512K bytes of entries each uint64_t or 8 bytes in size.
#define TCE_TABLE_SIZE  ((512*KILOBYTE)*sizeof(uint64_t))

#endif /* _VMMCONST_H */
