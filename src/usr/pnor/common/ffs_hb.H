/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/common/ffs_hb.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
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
 * FFS User Data flags
 */
enum
{
    /* Chip Select : 1 byte */
    FFS_CHIPSEL_UNUSED     = 0xFF,    /**< Chip select not used */

    /* Compression : 1 byte */
    FFS_COMPRESS_XZ        = 0x80,    /**< Section is XZ compressed */
    FFS_COMPRESS_UNUSED    = 0x7F,    /**< Compression not used  */

    /* Data Integrity : 2 bytes */
    FFS_INTEG_ECC_PROTECT  = 0x8000,  /**< Data Integrity: ECC protected */
    FFS_INTEG_UNUSED       = 0x1FFF,  /**< Unused Data Integrity Bits */

    /* Version Checking : 1 byte */
    FFS_VERS_SHA512        = 0x80,    /**< SHA512 used for Version */
    FFS_VERS_SHA512_PER_EC = 0x40,    /**< SHA512 version per EC */
    FFS_VERS_UNUSED        = 0x3F,    /**< Unused Version bits */

    /* Miscellaneous Bits : 1 byte */
    FFS_MISC_PRESERVED     = 0x80,    /**< Preserved across code updates */
    FFS_MISC_READ_ONLY     = 0x40,    /**< Read only section */
    FFS_MISC_PSEUDO        = 0x20,    /**< Pseudo partition */
    FFS_MISC_GOLDEN        = 0x01,    /**< Golden side of PNOR */
    FFS_MISC_UNUSED        = 0x1E,    /**< Unused MISC Flags */
};

/**
 * FFS entry user data
 *   This matches the PNOR binary layout of the data[] in an ffs_entry.
 */
struct ffs_hb_user_t{
    uint8_t  chip;            /**< Chip Select (0,1) */
    uint8_t  compressType;    /**< Compression Indication/alg (0=not compressed) */
    uint16_t dataInteg;       /**< Indicates Data Integrity mechanism */
    uint8_t  verCheck;        /**< Indicates Version check type */
    uint8_t  miscFlags;       /**< Misc Partition related Flags */
    uint8_t  freeMisc[2];     /**< Unused Miscellaneious Info */
    uint32_t decompressSize;  /**< Size after data is uncompressed in bytes */
    uint32_t freeUser[12];    /**< Unused User Data */
} PACKED;


#endif /* _FFS_HB_H */
