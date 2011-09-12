//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/limits.h $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#ifndef __LIMITS_H
#define __LIMITS_H

#define KILOBYTE  (1024ul)            /**< 1 KB */
#define MEGABYTE  (1024 * 1024ul)     /**< 1 MB */
#define GIGABYTE  (MEGABYTE * 1024ul) /**< 1 GB */
#define TERABYTE  (GIGABYTE * 1024ul) /**< 1 TB */

#define PAGESIZE  (4*KILOBYTE)  /**< 4 KB */
#define PAGE_SIZE PAGESIZE

#endif
