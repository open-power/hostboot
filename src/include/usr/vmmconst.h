/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/vmmconst.h $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2011-2012
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

/** Hardwired pointer to output PORE image, temporary location */
/** MAX image size is 512 K */
#define OUTPUT_PORE_IMG_ADDR        0x780000
#define MAX_OUTPUT_PORE_IMG_SIZE    512*1024


/**
 * Test Constants
 */
/** Base virtual address used in remove pages test */
#define VMM_VADDR_RMVPAGE_TEST (700 * GIGABYTE);

/** Block size used in remove pages test */
#define VMM_SIZE_RMVPAGE_TEST (8 * PAGESIZE);


#endif /* _VMMCONST_H */
