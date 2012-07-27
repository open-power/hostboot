/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/pnor/common/ffs_hb.H $
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
#ifndef _FFS_HB_H
#define _FFS_HB_H

/*
 * FSP Destination: src/hbfw/fsp/pnor/common/ffs_hb.H
 * 
 * NOTE: Do NOT modify this file in CMVC directly!  It comes from the Hostboot
 *      repository and will be overwritten.
*/

/*
 * This file contains the struct definition for the user data portion of an FFS Entry.  Use of
 * A commont header file will help ensure consistency between Hostboot and Hardware Server.
 *
 * For a more detailed description of these bits, see the PNOR Specification.
 *
 * The general FFS Entry layout is described in ffs.h, owned by the building block team.  The FFS
 * entry is described by the struct ffs_entry.  The user data defined by this file is the
 * ffs_entry->data[] array in ffs_entry.
 */

/**
 * FFS Misc information flags
 */
enum
{
    FFS_MISC_ECC_PROTECT   = 0x80,    /**< ECC protected */
    FFS_MISC_SIDELESS      = 0x40,    /**< Preserved across code updates (sideless) =1 */
    FFS_MISC_CRC_PROTECTED = 0x20,    /**< CRC protected */
    FFS_MISC_UNUSED        = 0x1F,    /**< Unused MISC Flags */
};

/**
 * FFS entry user data
 *   This matches the PNOR binary layout of the data[] in an ffs_entry.
 */
struct ffs_hb_user_t{
    uint32_t sizeAct;      /**< Actual Size of the image */
    uint8_t chip;          /**< Chip Select (0,1) */
    uint8_t compressType;  /**< Compression Indication/alg (0=not compressed) */
    uint8_t miscFlags;     /**< Misc Partition related Flags */
    uint8_t freeMisc[5];   /**< Unused Miscellaneious Info */
    uint32_t freeUser[13]; /**< Unused User Data */
} PACKED;


#endif /* _FFS_HB_H */
