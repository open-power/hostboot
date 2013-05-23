/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/common/ffs_hb.H $                                */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
    FFS_CHIPSEL_UNUSED     = 0xFF,    /**< Chip select not used */
    FFS_COMPRESS_UNUSED    = 0xFF,    /**< Compression not used  */

    FFS_INTEG_ECC_PROTECT  = 0x8000,  /**< Data Integrity: ECC protected */
    FFS_INTEG_UNUSED       = 0x1FFF,  /**< Unused Data Integrity Bits */

    FFS_VERS_SHA512        = 0x80,    /**< SHA512 used for Version */
    FFS_VERS_SHA512_PER_EC = 0x40,    /**< SHA512 version per EC */
    FFS_VERS_UNUSED        = 0x3F,    /**< Unused Version bits */

    FFS_MISC_PRESERVED      = 0x80,    /**< Preserved across code updates */
    FFS_MISC_UNUSED        = 0x1F,    /**< Unused MISC Flags */
};

/**
 * FFS entry user data
 *   This matches the PNOR binary layout of the data[] in an ffs_entry.
 */
struct ffs_hb_user_t{
    uint8_t  chip;         /**< Chip Select (0,1) */
    uint8_t  compressType; /**< Compression Indication/alg (0=not compressed) */
    uint16_t dataInteg;    /**< Indicates Data Integrity mechanism */
    uint8_t  verCheck;     /**< Indicates Version check type */
    uint8_t  miscFlags;    /**< Misc Partition related Flags */
    uint8_t  freeMisc[2];  /**< Unused Miscellaneious Info */
    uint32_t freeUser[13]; /**< Unused User Data */
} PACKED;


#endif /* _FFS_HB_H */
