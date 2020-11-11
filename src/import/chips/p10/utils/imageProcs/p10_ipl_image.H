/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/utils/imageProcs/p10_ipl_image.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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

/// \file p10_ipl_image.H
/// \brief definition of structs in sections
///
/// Contains struct ProcSbeFixed which contains functions, rings and
/// attributes whose pointers are stored in the fixed and fixed_toc section
/// Everything related to creating and manipulating IPL (formerly XIP)
/// binary images

// *INDENT-OFF*

#ifndef __P10_IPL_IMAGE_H__
#define __P10_IPL_IMAGE_H__

/// Current version (fields, layout, sections) of the IPL image (formerly
/// XIP image) header
///
/// If any changes are made to this file,  please update the header version
/// below and follow-up on all of the error messages.
///
/// V1:  Introduces .sbe nested image and moves .rings into the PPE's
///      nested images (as compared to P9's last XIP V9 header)
/// V2:  Expands the max number of IPL image sections from 15 to 24 and which
///      cause a .header size increase of 9 x 12 B = 108 B
#define IPL_IMAGE_HEADER_VERSION 2

/// \defgroup p9_xip_magic_numbers P9-XIP magic numbers
///
/// An P9-XIP magic number is a 64-bit constant.  The 4 high-order bytes
/// contain the ASCII characters "XIP " and identify the image as a P9-XIP
/// image, while the 4 low-order bytes identify the type of the image.
///
/// @{

#ifdef __ASSEMBLER__
    #define ULL(x) x
#else
    #define ULL(x) x##ull
#endif

#define P9_XIP_MAGIC              0x58495020           // "XIP "
#define P9_XIP_MAGIC_SEEPROM  ULL(0x584950205345504d)  // "XIP SEPM" also called SBE image
#define P9_XIP_MAGIC_HW       ULL(0x5849502020204857)  // "XIP   HW"
#define P9_XIP_MAGIC_SBE      ULL(0x5849502020534245)  // "XIP  SBE"
#define P9_XIP_MAGIC_QME      ULL(0x5849502020514d45)  // "XIP  QME"
#define P9_XIP_MAGIC_XGPE     ULL(0x5849502057475045)  // "XIP XGPE"
#define P9_XIP_MAGIC_PGPE     ULL(0x5849502050475045)  // "XIP PGPE"
#define P9_XIP_MAGIC_RESTORE  ULL(0x5849502052455354)  // "XIP REST"
#define P9_XIP_MAGIC_IOPPE    ULL(0x5849502049505045)  // "XIP IPPE"
#define P9_XIP_MAGIC_IOPXRAM  ULL(0x584950205852414d)  // "XIP XRAM"
/// @}


/// \defgroup p9_xip_sections P9-XIP Image Section Indexes
///
/// These constants define the order that the P9XipSection structures appear
/// in the header, which is not necessarily the order the sections appear in
/// the binary image.  Given that P9-XIP image contents are tightly
/// controlled, we use this simple indexing scheme for the allowed sections
/// rather than a more general approach, e.g., allowing arbitrary sections
/// identified by their names.
///
/// @{

// Fixed number of entries in section table including common and
// image-specific sections
#define IPL_IMAGE_SECTIONS 24
#define UNDEFINED_IPL_IMAGE_SID (int)0xff  // SID: Section ID

// This ensures that common sections go first followed by image-specific
// sections, to be used to define image-specific sections
#define P9_XIP_SECTIONS_PLUS(num) (P9_XIP_SECTIONS_COMMON + num)

#ifndef __ASSEMBLER__

// List of image section types supported in the XIP image

typedef enum {
    IST_XIP,  // A legacy XIP image
    IST_TOR,  // A standalone TOR ring section image
    IST_DDCO, // A standalone DD level container
    IST_MVPD, // An Mvpd file
    IST_DYN,  // A dynamic feature/service binary image
    NOOF_IST,
    IST_UNDEFINED = 0xff
} image_section_type_t;

// These are the common P9-XIP sections defined for every image
typedef enum {
    P9_XIP_SECTION_HEADER    = 0,
    P9_XIP_SECTION_FIXED     = 1,
    P9_XIP_SECTION_FIXED_TOC = 2,
    P9_XIP_SECTION_TOC       = 3,
    P9_XIP_SECTION_STRINGS   = 4,
    P9_XIP_SECTIONS_COMMON   = 5   // total number of common sections
} p9_xip_section_common_t;

/// Applications can expand this macro to create an array of section names.
#define P9_XIP_SECTION_NAMES_COMMON \
    ".header",                      \
    ".fixed",                       \
    ".fixedtoc",                    \
    ".toc",                         \
    ".strings"

#define P9_XIP_SECTION_NAMES(var, ...) \
    const char* var[] =  {             \
        P9_XIP_SECTION_NAMES_COMMON,   \
        __VA_ARGS__                    \
                         }

/// Applications can use this macro to safely index the array of section
/// names.
#define P9_XIP_SECTION_NAME(var, n)                               \
    ((((n) < 0) || ((n) >= (int)(sizeof(var) / sizeof(char*)))) ? \
     "" : var[n])

#endif  /* __ASSEMBLER__ */

/// @}


/// \defgroup p9_xip_validate() ignore masks.
///
/// These defines, when matched in p9_xip_validate(), cause the validation
/// to skip the check of the corresponding property. The purpose is to more
/// effectively debug images that may be damaged and which have excess info
/// before or after the image. The latter will be the case when dumping the
/// image as a memory block without knowing where the image starts and ends.
///
/// @{

#define P9_XIP_IGNORE_FILE_SIZE (uint32_t)0x00000001
#define P9_XIP_IGNORE_ALL       (uint32_t)0x80000000

/// @}

/// Maximum section alignment for P9-XIP sections
#define P9_XIP_MAX_SECTION_ALIGNMENT 128

/// \defgroup p9_xip_toc_types P9-XIP Table of Contents data types
///
/// These are the data types stored in the \a iv_type field of the P9XipToc
/// objects.  These must be defined as manifest constants because they are
/// required to be recognized as manifest constants in C (as opposed to C++)
/// code.
///
/// NB: The 0x0 code is purposefully left undefined to catch bugs.
///
/// @{

/// Data is a single unsigned byte
#define P9_XIP_UINT8 0x01

/// Data is a 16-bit unsigned integer
#define P9_XIP_UINT16 0x02

/// Data is a 32-bit unsigned integer
#define P9_XIP_UINT32 0x03

/// Data is a 64-bit unsigned integer
#define P9_XIP_UINT64 0x04

/// Data is a single signed byte
#define P9_XIP_INT8 0x05

/// Data is a 16-bit signed integer
#define P9_XIP_INT16 0x06

/// Data is a 32-bit signed integer
#define P9_XIP_INT32 0x07

/// Data is a 64-bit signed integer
#define P9_XIP_INT64 0x08

/// Data is a 0-byte terminated ASCII string
#define P9_XIP_STRING 0x09

/// Data is an address
#define P9_XIP_ADDRESS 0x0A

/// The maximum type number
#define P9_XIP_MAX_TYPE_INDEX 0x0A

/// Applications can expand this macro to get access to string forms of the
/// P9-XIP data types if desired.
#define P9_XIP_TYPE_STRINGS(var) \
    const char* var[] = {        \
        "Illegal 0 Code",        \
        "P9_XIP_UINT8",          \
        "P9_XIP_UINT16",         \
        "P9_XIP_UINT32",         \
        "P9_XIP_UINT64",         \
        "P9_XIP_INT8",           \
        "P9_XIP_INT16",          \
        "P9_XIP_INT32",          \
        "P9_XIP_INT64",          \
        "P9_XIP_STRING",         \
        "P9_XIP_ADDRESS",        \
    }

/// Applications can expand this macro to get access to abbreviated string
/// forms of the P9-XIP data types if desired.
#define P9_XIP_TYPE_ABBREVS(var) \
    const char* var[] = {        \
        "Illegal 0 Code",        \
        "u8 ",                   \
        "u16",                   \
        "u32",                   \
        "u64",                   \
        "i8 ",                   \
        "i16",                   \
        "i32",                   \
        "i64",                   \
        "str",                   \
        "adr",                   \
    }

/// Applications can use this macro to safely index either array of P9-XIP
/// type strings.
#define P9_XIP_TYPE_STRING(var, n)                 \
    (((n) > (sizeof(var) / sizeof(char*))) ?       \
     "Invalid P9-XIP type specification" : var[n])

/// @}


/// Final alignment constraint for P9-XIP images.
///
/// images are required to be multiples of 8 bytes in length, to
/// gaurantee that the something will be able to complete any 8-byte load/store.
#define P9_XIP_FINAL_ALIGNMENT 8


////////////////////////////////////////////////////////////////////////////
// C Definitions
////////////////////////////////////////////////////////////////////////////

#ifndef __ASSEMBLER__
#ifdef _WIN32
#include "win32_stdint.h"
#else
#include <stdint.h>
#endif
#include <stddef.h>
#include <common_ringId.H>

#ifdef __cplusplus
extern "C" {
#endif
#if 0
} /* So __cplusplus doesn't mess w/auto-indent */
#endif

/// P9-XIP Section information
///
/// This structure defines the data layout of section table entries in the
/// P9-XIP image header.

// -*- DO NOT REORDER OR EDIT THIS STRUCTURE DEFINITION WITHOUT ALSO    -*-
// -*- EDITING THE ASSEMBLER LAYOUT IN p9_xip_header.H                 -*-

typedef struct
{

    /// The offset (in bytes) of the section from the beginning of the image
    ///
    /// In normalized images the section offset will always be 0 if the
    /// section size is also 0.
    uint32_t iv_offset;

    /// The size of the section in bytes, exclusive of alignment padding
    ///
    /// This is the size of the program-significant data in the section,
    /// exclusive of any alignment padding or reserved or extra space.  The
    /// alignment padding (reserved space) is not represented explicitly, but
    /// is only implied by the offset of any subsequent non-empty section, or
    /// in the case of the final section in the image, the image size.
    ///
    /// Regardless of the \a iv_offset, if the \a iv_size of a section is 0 it
    /// should be considered "not present" in the image.  In normalized images
    /// the section offset will always be 0 if the section size is also 0.
    uint32_t iv_size;

    /// The required initial alignment for the section offset
    ///
    /// The image and the applications using P9-XIP images have strict
    /// alignment/padding requirements.  The image does not handle any type of
    /// unaligned instruction or data fetches.  Some sections and subsections
    /// must also be POWER cache-line aligned. The \a iv_alignment applies to
    /// the first byte of the section. image images are also required to be
    /// multiples of 8 bytes in length, to gaurantee that the something will be
    /// able to complete any 8-byte load/store.  These constraints are checked
    /// by p9_xip_validate() and enforced by p9_xip_append(). The alignment
    /// constraints may force a section to be padded, which may create "holes"
    /// in the image as explained in the comments for the \a iv_size field.
    ///
    /// Note that alignment constraints are always checked relative to the
    /// first byte of the image for in-memory images, not relative to the host
    /// address. Alignment specifications are required to be a power-of-2.
    uint8_t iv_alignment;

    /// Indicate if section has DD-level support. This value must be set
    /// to either 1 for true or 0 for false (default).
    uint8_t iv_ddSupport;

    /// Reserved structure alignment padding; Pad to 12 bytes
    uint8_t iv_reserved8[2];

} P9XipSection;

/// The P9XipSection structure is created by assembler code and is expected
/// to have the same size in C code.  This constraint is checked in
/// p9_xip_validate().
#define SIZE_OF_P9_XIP_SECTION 12


/// P9-XIP binary image header
///
/// This header occupies the initial bytes of a P9-XIP binary image.
/// The header contents are documented here, however the structure is actually
/// defined in the file p9_xip_header.S, and these two definitions must be
/// kept consistent.
///
/// The header is a fixed-format representation of the most critical
/// information about the image.  The large majority of information about the
/// image and its contents are available through the searchable table of
/// contents. image code itself normally accesses the data directly through
/// global symbols.
///
/// The header only contains information 1) required by OTPROM code (e.g., the
/// entry point); 2) required by search and updating APIs (e.g., the
/// locations and sizes of all of the sections.); a few pieces of critical
/// meta-data (e.g., information about the image build process).
///
/// Any entries that are accessed by image code are required to be 64 bits, and
/// will appear at the beginning of the header.
///
/// The header also contains bytewise offsets and sizes of all of the sections
/// that are assembled to complete the image.  The offsets are relative to the
/// start of the image (where the header is loaded).  The sizes include any
/// padding inserted by the link editor to guarantee section alignment.
///
/// Every field of the header is also accesssible through the searchable table
/// of contents as documented in p9_xip_header.S.

// -*- DO NOT REORDER OR EDIT THIS STRUCTURE DEFINITION WITHOUT ALSO     -*-
// -*- EDITING THE ASSEMBLER LAYOUT IN p9_xip_header.S, AND WITHOUT     -*-
// -*- UPDATING THE p9_xip_translate_header() API IN p9_xip_image.c.   -*-

typedef struct
{

    //////////////////////////////////////////////////////////////////////
    // Identification - 8-byte aligned; 8 entries
    //////////////////////////////////////////////////////////////////////

    /// Contains P9_XIP_MAGIC to identify a P9-XIP image
    uint64_t iv_magic;

    /// The entry address of the L1 loader entry point in SEEPROM
    uint64_t iv_L1LoaderAddr;

    /// The entry address of the L2 loader entry point in SRAM
    uint64_t iv_L2LoaderAddr;

    /// The entry address of Kernel in SRAM
    uint64_t iv_kernelAddr;

    /// The pibmem memory address for the data section. For HRESET requirement
    /// were on the text section needs to be reloaded, we had to split the text
    /// and the data section in the image. This address will be used to load
    /// the data into the pibmem.
    uint64_t iv_dataAddr;

    /// The base address used to link the image, as a full relocatable image
    /// address
    uint64_t iv_linkAddress;

    /// Reserved for future expansion
    uint64_t iv_reserved64[2];

    //////////////////////////////////////////////////////////////////////
    // Section Table - 4-byte aligned; 24 entries
    //////////////////////////////////////////////////////////////////////

    P9XipSection iv_section[IPL_IMAGE_SECTIONS];

    //////////////////////////////////////////////////////////////////////
    // Other information - 4-byte aligned; 8 entries
    //////////////////////////////////////////////////////////////////////

    /// The size of the image (including padding) in bytes
    uint32_t iv_imageSize;

    /// Build date generated in yyyymmdd format, e.g., 20110630
    uint32_t iv_buildDate;

    /// Build time generated in hhmm format, e.g., 0756
    uint32_t iv_buildTime;

    /// Build tag, generated when releasing this image to fw
    char iv_buildTag[20];

    //////////////////////////////////////////////////////////////////////
    // Other Information - 1-byte aligned; 8 entries
    //////////////////////////////////////////////////////////////////////

    /// Header format version number
    uint8_t iv_headerVersion;

    /// Indicates whether the image has been normalized (0/1)
    uint8_t iv_normalized;

    /// Indicates whether the TOC has been sorted to speed searching (0/1)
    uint8_t iv_tocSorted;

    /// Reserved for future expansion
    uint8_t iv_reserved8[5];

    //////////////////////////////////////////////////////////////////////
    // Strings; 64 characters allocated
    //////////////////////////////////////////////////////////////////////

    /// Build user, generated by `id -un`
    char iv_buildUser[16];

    /// Build host, generated by `hostname`
    char iv_buildHost[32];

    /// Build head commit, generated by `git log`
    char iv_buildHeadCommit[8];

    /// Reserved for future expansion
    char iv_reservedChar[8];
} P9XipHeader;



/// A C-structure form of the P9-XIP Table of Contents (TOC) entries
///
/// The .toc section consists entirely of an array of these structures.
/// TOC entries are never accessed by image code.
///
/// These structures store indexing information for global data required to be
/// manipulated by external tools.  The actual data is usually allocated in a
/// data section and manipulated by the SBE code using global or local symbol
/// names.  Each TOC entry contains a pointer to a keyword string naming the
/// data, the address of the data (or the data itself), the data type,
/// meta-information about the data, and for vectors the vector size.

// -*- DO NOT REORDER OR EDIT THIS STRUCTURE DEFINITION WITHOUT ALSO     -*-
// -*- EDITING THE ASSEMBLER MACROS (BELOW) THAT CREATE THE TABLE OF     -*-
// -*- CONTENTS ENTRIES.                                                 -*-

typedef struct
{

    /// A pointer to a 0-byte terminated ASCII string identifying the data.
    ///
    /// When allocated by the .xip_toc macro this is a pointer to the string
    /// form of the symbol name for the global or local symbol associated with
    /// the data which is allocated in the .strings section. This pointer is
    /// not aligned.
    ///
    /// When the image is normalized this pointer is replaced by the offset of
    /// the string in the .strings section.
    uint32_t iv_id;

    /// A 32-bit pointer locating the data
    ///
    /// This field is initially populated by the link editor.  For scalar,
    /// vector and string types this is the final relocated address of the
    /// first byte of the data.  For address types, this is the relocated
    /// address.  When the image is normalized, these addresses are converted
    /// into the equivalent offsets from the beginning of the section holding
    /// the data.
    uint32_t iv_data;

    /// The type of the data; See \ref p9_xip_toc_types.
    uint8_t iv_type;

    /// The section containing the data; See \ref p9_xip_sections.
    uint8_t iv_section;

    /// The number of elements for vector types, otherwise 1 for scalar types
    /// and addresses.
    ///
    /// Vectors are naturally limited in size, e.g. to the number of cores,
    /// chips in a node, DD-levels etc.  If \a iv_elements is 0 then no bounds
    /// checking is done on get/set accesses of the data.
    uint8_t iv_elements;

    /// Structure alignment padding; Pad to 12 bytes
    uint8_t iv_pad;

} P9XipToc;

/// The P9XipToc structure is created by assembler code and is expected
/// to have the same size in C code.  This constraint is checked in
/// p9_xip_validate().
#define SIZE_OF_P9_XIP_TOC 12


/// A C-structure form of hashed P9-XIP Table of Contents (TOC) entries
///
/// This structure was introduced in order to allow a small TOC for the .fixed
/// section to support minimum-sized SEEPROM images in which the global TOC
/// and all strings have been stripped out.  In this structure the index
/// string has been replaced by a 32-bit hash, and there is no longer a record
/// of the original data name other then the hash.  The section of the data is
/// assumed to be .fixed, with a maximum 16-bit offset.
///
/// These structures are created when entries are made in the .fixed section.
/// They are created empty, then filled in during image normalization.
///
/// This structure allows the p9_xip_get*() and p9_xip_set*() APIs to work
/// even on highly-stripped SEEPROM images.

typedef struct
{

    /// A 32-bit hash (FNV-1a) of the Id string.
    uint32_t iv_hash;

    /// The offset in bytes from the start of the (implied) section of the data
    uint16_t iv_offset;

    /// The type of the data; See \ref p9_xip_toc_types.
    uint8_t iv_type;

    /// The number of elements for vector types, otherwise 1 for scalar types
    /// and addresses.
    ///
    /// Vectors are naturally limited in size, e.g. to the number of cores,
    /// chips in a node, DD-levels etc.  If \a iv_elements is 0 then no bounds
    /// checking is done on get/set accesses of the data.
    uint8_t iv_elements;

} P9XipHashedToc;

/// The P9XipHashedToc structure is created by assembler code and is expected
/// to have the same size in C code.  This constraint is checked in
/// p9_xip_validate().
#define SIZE_OF_P9_XIP_HASHED_TOC 8


/// A decoded TOC entry for use by applications
///
/// This structure is a decoded form of a normalized TOC entry, filled in by
/// the p9_xip_decode_toc() and p9_xip_find() APIs.  This structure is
/// always returned with data elements in host-endian format.
///
/// In the event that the TOC has been removed from the image, this structure
/// will also be returned by p9_xip_find() with information populated from
/// the .fixed_toc section if possible.  In this case the field \a iv_partial
/// will be set and only the fields \a iv_address, \a iv_imageData, \a iv_type
/// and \a iv_elements will be populated (all other fields will be set to 0).
///
/// \note Only special-purpose applications will ever need to use this
/// structure given that the higher-level APIs p9_xip_get_*() and
/// p9_xip_set_*() are provided and should be used if possible, especially
/// given that the information may be truncated as described above.

typedef struct
{

    /// A pointer to the associated TOC entry as it exists in the image
    ///
    ///  If \a iv_partial is set this field is returned as 0.
    P9XipToc* iv_toc;

    /// The full relocatable image address
    ///
    /// All relocatable addresses are computed from the \a iv_linkAddress
    /// stored in the header. For scalar and string data, this is the
    /// relocatable address of the data.  For address-only entries, this is
    /// the indexed address itself.
    uint64_t iv_address;

    /// A host pointer to the first byte of text or data within the image
    ///
    /// For scalar or string types this is a host pointer to the first byte of
    /// the data.  For code pointers (addresses) this is host pointer to the
    /// first byte of code.  Note that any use of this field requires the
    /// caller to handle conversion of the data to host endian-ness if
    /// required.  Only 8-bit and string data can be used directly on all
    /// hosts.
    void* iv_imageData;

    /// The item name
    ///
    /// This is a pointer in host memory to a string that names the TOC entry
    /// requested.  This field is set to a pointer to the ID string of the TOC
    /// entry inside the image. If \a iv_partial is set this field is returned
    /// as 0.
    char* iv_id;

    /// The data type, one of the P9_XIP_* constants
    uint8_t iv_type;

    /// The number of elements in a vector
    ///
    /// This field is set from the TOC entry when the TOC entry is
    /// decoded. This value is stored as 1 for scalar declarations, and may be
    /// set to 0 for vectors with large or undeclared sizes.  Otherwise it is
    /// used to bounds check indexed accesses.
    uint8_t iv_elements;

    /// Is this record only partially populated?
    ///
    /// This field is set to 0 normally, and only set to 1 if a lookup is made
    /// in an image that only has the fixed TOC and the requested Id hashes to
    /// the fixed TOC.
    uint8_t iv_partial;

} P9XipItem;


/// Validate a P9-XIP image
///
/// \param[in] i_image A pointer to a P9-XIP image in host memory.
///
/// \param[in] i_size The putative size of the image
///
/// \param[in] i_maskIgnores Array of ignore bits representing which properties
/// should not be checked for in p9_xip_validate2().
///
/// This API should be called first by all applications that manipulate
/// P9-XIP images in host memory.  The magic number is validated, and
/// the image is checked for consistency of the section table and table of
/// contents.  The \a iv_imageSize field of the header must also match the
/// provided \a i_size parameter.  Validation does not modify the image.
///
/// \retval 0 Success
///
/// \retval non-0 See \ref p9_xip_image_errors
int
p9_xip_validate(void* i_image, const uint32_t i_size);

int
p9_xip_validate2(void* i_image, const uint32_t i_size,
                 const uint32_t i_maskIgnores);


/// Normalize the P9-XIP image
///
/// \param[in] io_image A pointer to a P9-XIP image in host memory.  The
/// image is assumed to be consistent with the information contained in the
/// header regarding the presence of and sizes of all sections.
///
/// P9-XIP images must be normalized before any other APIs are allowed to
/// operate on the image.  Since normalization modifies the image, an explicit
/// call to normalize the image is required.  Briefly, normalization modifies
/// the TOC entries created by the final link to simplify search, updates,
/// modification and relocation of the image.  Normalization is explained in
/// the written documentation of the P9-XIP binary format. Normalization does
/// not modify the size of the image.
///
/// \retval 0 Success
///
/// \retval non-0 See \ref p9_xip_image_errors
int
p9_xip_normalize(void* io_image);


/// Return the size of a P9-XIP image from the image header
///
/// \param[in] i_image A pointer to a P9-XIP image in host memory.  The
/// image is assumed to be consistent with the information contained in the
/// header regarding the presence of and sizes of all sections.
///
/// \param[out] o_size A pointer to a variable returned as the size of the
/// image in bytes, as recorded in the image header.
///
/// \retval 0 Success
///
/// \retval non-0 See \ref p9_xip_image_errors
int
p9_xip_image_size(void* i_image, uint32_t* o_size);


/// Locate a section table entry and translate into host format and return
/// only that portion of the section specified by the ddLevel. Note that
/// the entries in the hostSection are updated on return and no longer have
/// any connection to the hostSection of the sectionId specified. The only
/// exception to this is if ddLevel=UNDEFINED_DD_LEVEL is specified in which
/// case sectionId's hostSection content remains the same.
///
/// \param[in] i_image A pointer to a P9-XIP image in host memory.
///
/// \param[in] i_sectionId Identifies the section to be queried.  See \ref
/// p9_xip_sections.
///
/// \param[out] o_hostSection Updated to contain the section table entry
/// translated to host byte order.
///
/// \param[in] i_ddLevel Specified the DD level of the sub-section within
/// the XIP section to be extracted.
///
/// \retval 0 Success
///
/// \retval non-0 See \ref p9_xip_image_errors
int
p9_xip_get_section(const void* i_image,
                   const int i_sectionId,
                   P9XipSection* o_hostSection,
#ifdef __PPE__
                   uint8_t i_ddLevel);
#else
                   uint8_t i_ddLevel=UNDEFINED_DD_LEVEL);
#endif



/// Retrieve an embedded DD block of a sub IPL image section within a nested
/// IPL image and return the DD block's P9XipSection table entry (i.e., as if it
/// was a true IPL image section).  This API may also be [misused] as a
/// replacement for xip_get_section to retrieve any main IPL image section.
/// Note that it is an assumption of this API that a nested image is DD
/// unspecific and that it is only the sub-section that has DD support.  Also
/// see the comments to the p9_xip_get_section API.
///
/// \param[in] i_image  A pointer to an IPL image (formerly XIP).
///
/// \param[in] i_mainSectionID  This is the enumerated IPL image section ID (SID)
/// of the main image section to access.  It typically identifies another IPL
/// image within i_image. This other image is sometimes referred to as a "nested"
/// image.  However, if the next parameter in this API, i.e. i_subSectionID, is
/// subSectionID==UNDEFINED, then mainSectionID is allowed to be any IPL image
/// section of i_image.  In such as case, this call is no different than calling
/// xip_get_section w/sectionId=mainSectionID.
///
/// \param[in] i_subSectionID  Identifies the section ID of a section within
/// the nested image.  Note that if nestLevelSID==UNDEFINED, then this call
/// is no different than calling xip_get_section w/sectionId=topLevelSID.
///
/// \param[out] o_hostSection  Contains the embedded DD level block's
/// P9XipSection table entry as if it was a true IPL image section (but which it
/// is NOT). We are merely using the P9XipSection's iv_offset, and iv_size, to
/// represent the offset, and size, of the embedded block from the beginning of
/// i_image.  Note that hostSection is translated to host byte order endianness.
///
/// \param[in] i_ddLevel  Specifies the DD level of the embedded block within
/// the sub IPL image section.  This is embedded block is NOT an IPL image
/// section, i.e. it does not have a TOC entry.
///
/// \retval 0 Success
///
/// \retval non-0 See \ref p9_xip_image_errors
int
p9_xip_get_sub_section( const void* i_image,
                        const int i_mainSectionID, // Nested image's section ID
                        const int i_subSectionID,  // Sub section ID within the nested image
                        P9XipSection* o_hostSection, // Embedded DD block's "table entry"
#ifdef __PPE__
                        const uint8_t i_ddLevel); // DD level of embedded block within the sub-section
#else
                        const uint8_t i_ddLevel=UNDEFINED_DD_LEVEL );
#endif



/// Endian translation of a P9XipHeader object
///
/// \param[out] o_hostHeader The destination object.
///
/// \param[in] i_imageHeader The source object.
///
/// Translation of a P9XipHeader includes translation of all data members
/// including traslation of the embedded section table.  This translation
/// works even if \a o_src == \a o_dest, i.e., in the destructive case.
void
p9_xip_translate_header(P9XipHeader* o_hostHeader,
                        const P9XipHeader* i_imageHeader);


/// Get scalar data from a P9-XIP image
///
/// \param[in] i_image A pointer to a P9-XIP image in host memory.  The
/// image is assumed to be consistent with the information contained in the
/// header regarding the presence of and sizes of all sections.  The image is
/// also required to have been normalized.
///
/// \param[in] i_id A pointer to a 0-terminated ASCII string naming the item
/// requested.
///
/// \param[out] o_data A pointer to an 8-byte integer to receive the scalar
/// data. Assuming the item is located this variable is assigned by the call.
/// In the event of an error the final state of \a o_data is not specified.
///
/// This API searches the P9-XIP Table of Contents (TOC) for the item named
/// \a i_id, assigning \a o_data from the image if the item is found and is a
/// scalar value.  Scalar values include 8- 32- and 64-bit integers and image
/// addresses.  Image data smaller than 64 bits are extracted as unsigned
/// types, and it is the caller's responsibility to cast or convert the
/// returned data as appropriate.
///
/// \retval 0 Success
///
/// \retval non-0 See \ref p9_xip_image_errors
int
p9_xip_get_scalar(void* i_image, const char* i_id, uint64_t* o_data);


/// Get endianness converted value from the P9-XIP image toc data
///
/// \param[in] i_item - decoded toc entry

/// \param[out] o_data A pointer to an 8-byte integer to receive the scalar
/// data. Assuming the item is located this variable is assigned by the call.
/// In the event of an error the final state of \a o_data is not specified.
///
/// \param[in] i_index The index of the vector element to return.
///
/// \retval 0 Success
///
/// \retval non-0 See \ref p9_xip_image_errors
int
p9_xip_get_item(const P9XipItem *i_item, uint64_t* o_data, uint32_t i_index);


/// Get an integral element from a vector held in a P9-XIP image
///
/// \param[in] i_image A pointer to a P9-XIP image in host memory.  The
/// image is assumed to be consistent with the information contained in the
/// header regarding the presence of and sizes of all sections.  The image is
/// also required to have been normalized.
///
/// \param[in] i_id A pointer to a 0-terminated ASCII string naming the item
/// requested.
///
/// \param[in] i_index  The index of the vector element to return.
///
/// \param[out] o_data A pointer to an 8-byte integer to receive the
/// data. Assuming the item is located this variable is assigned by the call.
/// In the event of an error the final state of \a o_data is not specified.
///
/// This API searches the P9-XIP Table of Contents (TOC) for the \a i_index
/// element of the item named \a i_id, assigning \a o_data from the image if
/// the item is found, is a vector of an integral type, and the \a i_index is
/// in bounds.  Vector elements smaller than 64 bits are extracted as unsigned
/// types, and it is the caller's responsibility to cast or convert the
/// returned data as appropriate.
///
/// \retval 0 Success
///
/// \retval non-0 See \ref p9_xip_image_errors
int
p9_xip_get_element(void* i_image,
                   const char* i_id,
                   const uint32_t i_index,
                   uint64_t* o_data);


/// Get string data from a P9-XIP image
///
/// \param[in] i_image A pointer to a P9-XIP image in host memory.  The
/// image is assumed to be consistent with the information contained in the
/// header regarding the presence of and sizes of all sections.  The image is
/// also required to have been normalized.
///
/// \param[in] i_id A pointer to a 0-terminated ASCII string naming the item
/// requested.
///
/// \param[out] o_data A pointer to a character pointer.  Assuming the
/// item is located this variable is assigned by the call to point to the
/// string as it exists in the \a i_image.  In the event of an error the final
/// state of \a o_data is not specified.
///
/// This API searches the P9-XIP Table of Contents (TOC) for the item named
/// \a i_id, assigning \a o_data if the item is found and is a string.  It is
/// the caller's responsibility to copy the string from the \a i_image memory
/// space if necessary.
///
/// \retval 0 Success
///
/// \retval non-0 See \ref p9_xip_image_errors
int
p9_xip_get_string(void* i_image, const char* i_id, char** o_data);


/// Directly read 64-bit data from the image based on a image address
///
/// \param[in] i_image A pointer to a P9-XIP image in host memory.  The
/// image is assumed to be consistent with the information contained in the
/// header regarding the presence of and sizes of all sections.
///
/// \param[in] i_imageAddress A relocatable IMAGE address contained in the
/// image, presumably of an 8-byte data area.  The \a i_imageAddress is
/// required to be 8-byte aligned, otherwise the P9_XIP_ALIGNMENT_ERROR code
/// is returned.
///
/// \param[out] o_data The 64 bit data in host format that was found at \a
/// i_imageAddress.
///
/// This API is provided for applications that need to manipulate P9-XIP
/// images in terms of their relocatable IMAGE addresses.  The API checks that
/// the \a i_imageAddress is properly aligned and contained in the image, then
/// reads the contents of \a i_imageAddress into \a o_data, performing
/// image-to-host endianess conversion if required.
///
/// \retval 0 Success
///
/// \retval non-0 See \ref p9_xip_image_errors
int
p9_xip_read_uint64(const void* i_image,
                   const uint64_t i_imageAddress,
                   uint64_t* o_data);


/// Set scalar data in a P9-XIP image
///
/// \param[in,out] io_image A pointer to a P9-XIP image in host memory.
/// The image is assumed to be consistent with the information contained in
/// the header regarding the presence of and sizes of all sections.  The image
/// is also required to have been normalized.
///
/// \param[in] i_id A pointer to a 0-terminated ASCII string naming the item
/// to be modified.
///
/// \param[in] i_data The new scalar data.
///
/// This API searches the P9-XIP Table of Contents (TOC) for the item named
/// by \a i_id, updating the image from \a i_data if the item is found, has
/// a scalar type and can be modified.  For this API the scalar types include
/// 8- 32- and 64-bit integers.  Although IMAGE addresses are considered a
/// scalar type for p9_xip_get_scalar(), IMAGE addresses can not be modified
/// by this API.  The caller is responsible for ensuring that the \a i_data is
/// of the correct size for the underlying data element in the image.
///
/// \retval 0 Success
///
/// \retval non-0 See \ref p9_xip_image_errors
int
p9_xip_set_scalar(void* io_image, const char* i_id, const uint64_t i_data);


/// Set an integral element in a vector held in a P9-XIP image
///
/// \param[in] i_image A pointer to a P9-XIP image in host memory.  The
/// image is assumed to be consistent with the information contained in the
/// header regarding the presence of and sizes of all sections.  The image is
/// also required to have been normalized.
///
/// \param[in] i_id A pointer to a 0-terminated ASCII string naming the item
/// to be updated.
///
/// \param[in] i_index  The index of the vector element to update.
///
/// \param[out] i_data The new vector element.
///
/// This API searches the P9-XIP Table of Contents (TOC) for the \a i_index
/// element of the item named \a i_id, update the image from \a i_data if the
/// item is found, is a vector of an integral type, and the \a i_index is in
/// bounds.  The caller is responsible for ensuring that the \a i_data is of
/// the correct size for the underlying data element in the image.
///
/// \retval 0 Success
///
/// \retval non-0 See \ref p9_xip_image_errors
int
p9_xip_set_element(void* i_image,
                   const char* i_id,
                   const uint32_t i_index,
                   const uint64_t i_data);


/// Set string data in a P9-XIP image
///
/// \param[in,out] io_image A pointer to a P9-XIP image in host memory.  The
/// image is assumed to be consistent with the information contained in the
/// header regarding the presence of and sizes of all sections.  The image is
/// also required to have been normalized.
///
/// \param[in] i_id A pointer to a 0-terminated ASCII string naming the item
/// to be modified.
///
/// \param[in] i_data A pointer to the new string data.
///
/// This API searches the P9-XIP Table of Contents (TOC) for the item named
/// \a i_id, which must be a string variable.  If found, then the string data
/// in the image is overwritten with \a i_data.  Strings are held 0-terminated
/// in the image, and the P9-XIP format does not maintain a record of the
/// amount of memory allocated for an individual string.  If a string is
/// overwritten by a shorter string then the 'excess' storage is effectively
/// lost.  If the length of \a i_data is longer that the current strlen() of
/// the string data then \a i_data is silently truncated to the first
/// strlen(old_string) characters.
///
/// \retval 0 Success
///
/// \retval non-0 See \ref p9_xip_image_errors
int
p9_xip_set_string(void* io_image, const char* i_id, const char* i_data);


/// Directly write 64-bit data into the image based on a IMAGE address
///
/// \param[in, out] io_image A pointer to a P9-XIP image in host memory.  The
/// image is assumed to be consistent with the information contained in the
/// header regarding the presence of and sizes of all sections.
///
/// \param[in] i_imageAddress A relocatable IMAGE address contained in the
/// image, presumably of an 8-byte data area.  The \a i_imageAddress is
/// required to be 8-byte aligned, otherwise the P9_XIP_ALIGNMENT_ERROR code
/// is returned.
///
/// \param[in] i_data The 64 bit data in host format to be written to \a
/// i_imageAddress.
///
/// This API is provided for applications that need to manipulate P9-XIP
/// images in terms of their relocatable IMAGE addresses.  The API checks that
/// the \a i_imageAddress is properly aligned and contained in the image, then
/// updates the contents of \a i_imageAddress with \a i_data, performing
/// host-to-image endianess conversion if required.
///
/// \retval 0 Success
///
/// \retval non-0 See \ref p9_xip_image_errors
int
p9_xip_write_uint64(void* io_image,
                    const uint64_t i_imageAddress,
                    const uint64_t i_data);


/// Map over a P9-XIP image Table of Contents
///
/// \param[in,out] io_image A pointer to a P9-XIP image in host memory.  The
/// image is assumed to be consistent with the information contained in the
/// header regarding the presence of and sizes of all sections.  The image is
/// also required to have been normalized.
///
/// \param[in] i_fn A pointer to a function to call on each TOC entry.  The
/// function has the prototype:
///
/// \code
/// int (*i_fn)(void* io_image,
///             const P9XipItem* i_item,
///             void* io_arg)
/// \endcode
///
/// \param[in,out] io_arg The private argument of \a i_fn.
///
/// This API iterates over each entry of the TOC, calling \a i_fn with
/// pointers to the image, a P9XipItem* pointer, and a private argument. The
/// iteration terminates either when all TOC entries have been mapped, or \a
/// i_fn returns a non-zero code.
///
/// \retval 0 Success; All TOC entries were mapped, including the case that
/// the .toc section is empty.
///
/// \retval non-0 May be either one of the P9-XIP image error codes (see \ref
/// p9_xip_image_errors), or a non-zero code from \a i_fn. Since the standard
/// P9_XIP return codes are > 0, application-defined codes should be < 0.
int
p9_xip_map_toc(void* io_image,
               int (*i_fn)(void* io_image,
                           const P9XipItem* i_item,
                           void* io_arg),
               void* io_arg);


/// Find a P9-XIP TOC entry
///
/// \param[in] i_image A pointer to a P9-XIP image in host memory.  The
/// image is assumed to be consistent with the information contained in the
/// header regarding the presence of and sizes of all sections.  The image is
/// also required to have been normalized.
///
/// \param[in] i_id A 0-byte terminated ASCII string naming the item to be
/// searched for.
///
/// \param[out] o_item If the search is successful, then the object
/// pointed to by \a o_item is filled in with the decoded form of the
/// TOC entry for \a i_id.  If the API returns a non-0 error code then the
/// final state of the storage at \a o_item is undefined.  This parameter may
/// be suppied as 0, in which case p9_xip_find() serves as a simple predicate
/// on whether an item is indexded in the TOC.
///
/// This API searches the TOC of a normalized P9-XIP image for the item named
/// \a i_id, and if found, fills in the structure pointed to by \a
/// o_item with a decoded form of the TOC entry.  If the item is not found,
/// the following two return codes may be considered non-error codes:
///
/// - P9_XIP_ITEM_NOT_FOUND : No TOC record for \a i_id was found.
///
/// - P9_XIP_DATA_NOT_PRESENT : The item appears in the TOC, however the
/// section containing the data is no longer present in the image.
///
/// If the TOC section has been deleted from the image, then the search is
/// restricted to the abbreviated TOC that indexes data in the .fixed section.
/// In this case the \a o_item structure is marked with a 1 in the \a
/// iv_partial field since the abbreviated TOC can not populate the entire
/// P9XipItem structure.
///
/// \note This API should typically only be used as a predicate, not as a way
/// to access the image via the returned P9XipItem structure. To obtain data
/// from the image or update data in the image use the p9_xip_get_*() and
/// p9_xip_set_*() APIs respectively.
///
/// \retval 0 Success
///
/// \retval non-0 See \ref p9_xip_image_errors
int
p9_xip_find(void* i_image,
            const char* i_id,
            P9XipItem* o_item);



/// Delete any section, except .header, from a P9-XIP image in host memory,
/// even in-between sections, i.e. non-final sections.
///
/// \param[in,out] io_image A pointer to a P9-XIP image in host memory.  The
/// image is assumed to be consistent with the information contained in the
/// header regarding the presence of and sizes of all sections. The image is
/// also required to have been normalized. In case of failure in this
/// funtion, the io_image will get restored to its input value.
///
/// \param[out] o_imageBuf  A pointer to a pre-allocated buffer that MUST
/// BE greater than or equal to the size of the \a io_image. The size of
/// this buffer must be supplied in \a i_imageBufSize. If \a o_imageBuf
/// is NULL, the supplied \a i_sectionId must be the final section in the
/// image or this function will fail at deleting the section. On return
/// from this function, o_imageBuf contains a copy of the initial input
/// image \a io_image, but only if it's a valid buffer.
///
/// \param[in] i_imageBufSize The size of \a o_imageBuf buffer. It MUST
/// BE greater than or equal to the size of \a io_image. However, if \a
/// o_imageBuf is NULL, then this arg is ignored.
///
/// \param[in] i_sectionId Identifies the section to be deleted.  See \ref
/// p9_xip_sections.
///
/// This API effectively deletes a section from a P9-XIP image held in host
/// memory.  Deleting a section of the image means that the section size is
/// set to 0, and the size of the image recorded in the header is reduced by
/// the section size.  Any alignment padding of the in-between section is
/// also handled, i.e. removed if final section and re-applied upon
/// re-appending sections.  In the special case where \a o_imageBuf is
/// NULL, unless the requested \a i_sectionId is already empty, only the final
/// section (highest address offset) of the image may be deleted.
///
/// \note This API does not check for or warn if other sections in the image
/// reference the deleted section.
///
/// \retval 0 Success
///
/// \retval non-0 See \ref p9_xip_image_errors
int
p9_xip_delete_section(void* io_image,
                      void* o_imageBuf,
                      const uint32_t i_imageBufSize,
                      const int i_sectionId);



#ifndef PPC_HYP

/// Duplicate a section from a P9-XIP image in host memory
///
/// \param[in,out] i_image A pointer to a P9-XIP image in host memory.  The
/// image is assumed to be consistent with the information contained in the
/// header regarding the presence of and sizes of all sections.
///
/// \param[in] i_sectionId Identifies the section to be duplicated.  See \ref
/// p9_xip_sections.
///
/// \param[out] o_duplicate At exit, points to the newly allocated and
/// initialized duplicate of the given section. The caller is responsible for
/// free()-ing this memory when no longer required.
///
/// \param[out] o_size At exit, contains the size (in bytes) of the duplicated
/// section.
///
/// This API creates a bytewise duplicate of a non-empty section into newly
/// malloc()-ed memory. At exit \a o_duplicate points to the duplicate, and \a
/// o_size is set the the size of the duplicated section. The caller is
/// responsible for free()-ing the memory when no longer required.  The
/// pointer at \a o_duplicate is set to NULL (0) and the \a o_size is set to 0
/// in the event of any failure.
///
/// \retval 0 Success
///
/// \retval non-0 See \ref p9_xip_image_errors
int
p9_xip_duplicate_section(const void* i_image,
                         const int i_sectionId,
                         void** o_duplicate,
                         uint32_t* o_size);

#endif // PPC_HYP


/// Append binary data to a P9-XIP image held in host memory
///
/// \param[in,out] io_image A pointer to a P9-XIP image in host memory.  The
/// image is assumed to be consistent with the information contained in the
/// header regarding the presence of and sizes of all sections. The image is
/// also required to have been normalized.
///
/// \param[in] i_sectionId Identifies the section to contain the new data.
///
/// \param[in] i_data A pointer to the data to be appended to the image.  If
/// this pointer is NULL (0), then the effect is as if \a i_data were a
/// pointer to an \a i_size array of 0 bytes.
///
/// \param[in] i_size The size of the data to be appended in bytes.  If \a
/// i_data is 0, then this is the number of bytes to clear.
///
/// \param[in] i_allocation The size of the memory region containing the
/// image, measured from the first byte of the image.  The call will fail if
/// appending the new data plus any alignment padding would overflow the
/// allocated memory.
///
/// \param[out] o_sectionOffset If non-0 at entry, then the API updates the
/// location pointed to by \a o_sectionOffset with the offset of the first
/// byte of the appended data within the indicated section. This return value
/// is invalid in the event of a non-0 return code.
///
/// \param[in] i_ddSupport Specifies if the section contains ddLevel sub-
/// sections (=1) or if it does not have ddLevel support (=0).
///
/// This API copies data from \a i_data to the end of the indicated \a
/// i_section.  The section \a i_section must either be empty, or must be the
/// final (highest address) section in the image.  If the section is initially
/// empty and \a i_size is non-0 then the section is created at the end of the
/// image.  The size of \a i_section and the size of the image are always
/// adjusted to reflect the newly added data.  This is a simple binary copy
/// without any interpretation (e.g., endian-translation) of the copied data.
/// The caller is responsible for insuring that the host memory area
/// containing the P9-XIP image is large enough to hold the newly appended
/// data without causing addressing errors or buffer overrun errors.
///
/// The final parameter \a o_sectionOffset is optional, and may be passed as
/// NULL (0) if the application does not require the information.  This return
/// value is provided to simplify typical use cases of this API:
///
/// - A scan program is appended to the image, or a run-time data area is
/// allocated and cleared at the end of the image.
///
/// - Pointer variables in the image are updated with IMAGE addresses obtained
/// via p9_xip_section2image(), or
/// other procedure code initializes a newly allocated and cleared data area
/// via host addresses obtained from p9_xip_section2host().
///
/// Regarding alignment, note that the P9-XIP format requires that sections
/// maintain an initial alignment that varies by section, and the API will
/// enforce these alignment constraints for all sections created by the API.
/// All alignment is relative to the first byte of the image (\a io_image) -
/// \e not to the current in-memory address of the image. By specification
/// P9-XIP images must be loaded at a 4K alignment in order for IMAGE hardware
/// relocation to work, however the APIs don't require this 4K alignment for
/// in-memory manipulation of images.  Images to be executed on ImageVe will
/// normally require at least 8-byte final aligment in order to guarantee that
/// the ImageVe can execute an 8-byte fetch or load/store of the final
/// doubleword.
///
/// \note If the TOC section is modified then the image is marked as having an
/// unsorted TOC.
///
/// \note If the call fails for any reason (other than a bug in the API
/// itself) then the \a io_image data is returned unmodified.
///
/// \retval 0 Success
///
/// \retval non-0 See \ref p9_xip_image_errors
int
p9_xip_append(void* io_image,
              const int i_sectionId,
              const void* i_data,
              const uint32_t i_size,
              const uint32_t i_allocation,
              uint32_t* o_sectionOffset,
              uint8_t i_ddSupport);


/// Convert a P9-XIP section offset to a relocatable IMAGE address
///
/// \param[in] i_image A pointer to a P9-XIP image in host memory
///
/// \param[in] i_sectionId A valid P9-XIP section identifier; The section
/// must be non-empty.
///
/// \param[in] i_offset An offset (in bytes) within the section.  At least one
/// byte at \a i_offset must be currently allocated in the section.
///
/// \param[in] o_imageAddress The equivalent relocatable IMAGE address is
/// returned via this pointer. Since valid IMAGE addresses are always either
/// 4-byte (code) or 8-byte (data) aligned, this API checks the aligment of
/// the translated address and returns P9_XIP_ALIGNMENT_ERROR if the IMAGE
/// address is not at least 4-byte aligned.  Note that the translated address
/// is still returned even if incorrectly aligned.
///
/// This API is typically used to translate section offsets returned from
/// p9_xip_append() into relocatable IMAGE addresses.
///
/// \retval 0 Success
///
/// \retval non-0 See \ref p9_xip_image_errors
int
p9_xip_section2image(const void* i_image,
                     const int i_sectionId,
                     const uint32_t i_offset,
                     uint64_t* o_imageAddress);


/// Convert a P9-XIP relocatable image address to a host memory address
///
/// \param[in] i_image A pointer to a P9-XIP image in host memory.
///
/// \param[in] i_imageAddress A relocatable image address putatively addressing
/// relocatable memory contained in the image.
///
/// \param[out] o_hostAddress The API updates the location pointed to by \a
/// o_hostAddress with the host address of the memory addressed by \a
/// i_imageAddress.  In the event of an error (non-0 return code) the final
/// content of \a o_hostAddress is undefined.
///
/// This API is typically used to translate relocatable image addresses stored
/// in the P9-XIP image into the equivalent host address of the in-memory
/// image, allowing host-code to manipulate arbitrary data structures in the
/// image. If the \a i_imageAddress does not refer to memory within the image
/// (as determined by the link address and image size) then the
/// P9_XIP_INVALID_ARGUMENT error code is returned.
///
/// \retval 0 Success
///
/// \retval non-0 See \ref p9_xip_image_errors
int
p9_xip_image2host(const void* i_image,
                  const uint64_t i_imageAddress,
                  void** o_hostAddress);


/// Convert a P9-XIP relocatable image address to section Id and offset
///
/// \param[in] i_image A pointer to a P9-XIP image in host memory.
///
/// \param[in] i_imageAddress A relocatable image address putatively addressing
/// relocatable memory contained in the image.
///
/// \param[out] o_section The API updates the location pointed to by \a
/// o_section with the section Id of the memory addressed by \a
/// i_imageAddress.  In the event of an error (non-0 return code) the final
/// content of \a o_section is undefined.
///
/// \param[out] o_offset The API updates the location pointed to by \a
/// o_offset with the byte offset of the memory addressed by \a i_imageAddress
/// within \a o_section.  In the event of an error (non-0 return code) the
/// final content of \a o_offset is undefined.
///
/// This API is typically used to translate relocatable image addresses stored
/// in the P9-XIP image into the equivalent section + offset form, allowing
/// host-code to manipulate arbitrary data structures in the image. If the \a
/// i_imageAddress does not refer to memory within the image (as determined by
/// the link address and image size) then the P9_XIP_INVALID_ARGUMENT error
/// code is returned.
///
/// \retval 0 Success
///
/// \retval non-0 See \ref p9_xip_image_errors
int
p9_xip_image2section(const void* i_image,
                     const uint64_t i_imageAddress,
                     int* o_section,
                     uint32_t* o_offset);


/// Convert an in-memory P9-XIP host address to a relocatable image address
///
/// \param[in] i_image A pointer to a P9-XIP image in host memory
///
/// \param[in] i_hostAddress A host address addressing data within the image.
///
/// \param[out] o_imageAddress The API updates the location pointed to by \a
/// o_imageAddress with the equivelent relocatable image address of the memory
/// addressed by i_hostAddress.  Since valid image addresses are always either
/// 4-byte (code) or 8-byte (data) aligned, this API checks the aligment of
/// the translated address and returns P9_XIP_ALIGNMENT_ERROR if the image
/// address is not at least 4-byte aligned.  Note that the translated address
/// is still returned evn if incorrectly aligned.
///
/// This API is provided as a convenient way to convert host memory addresses
/// for an in-memory P9-XIP image into image addresses correctly relocated for
/// the image, for example to update pointer variables in the image.  If the
/// \a i_hostAddress does not refer to memory within the image (as determined
/// by the image address and image size) then the P9_XIP_INVALID_ARGUMENT
/// error code is returned.
///
/// \retval 0 Success
///
/// \retval non-0 See \ref p9_xip_image_errors
int
p9_xip_host2image(const void* i_image,
                  void* i_hostAddress,
                  uint64_t* o_imageAddress);

/// Get all the information required to search and find the TOC
///
/// \param[in] i_image A pointer to a P9-XIP image in host memory
///
/// \param[out][optional] o_toc A pointer to TOC listing
///
/// \param[out][optional] o_entries Number of TOC entries located
///
/// \param[out][optional] o_sorted Indication if the TOC is sorted
///
/// \param[out][optional] o_strings A pointer to String section containing TOC
///                                 names
///
/// \retval 0 Success
///
/// \retval non-0 See \ref p9_xip_image_errors
int
p9_xip_get_toc(void* i_image,
               P9XipToc** o_toc,
               size_t* o_entries,
               int* o_sorted,
               char** o_strings);


/// Inform caller if specified subSectionId has DD support. Note however that if
/// subSectionId==UNDEFINED, this API informs if mainSectionId has DD support.
///
/// \param[in] i_image A pointer to a P9-XIP image in host memory.
///
/// \param[in] i_mainSectionId Identifies the section (typically a nested image) within which
/// the subSection is to be queried.  See \ref p9_xip_sections.
///
/// \param[in] i_subSectionId Identifies the section to be queried. See \ref p9_xip_sections.
///
/// \param[out] o_bDdSupport Returns true or false whether subSectionId has DD support or not.
///
/// \retval 0 Success
///
/// \retval non-0 See \ref p9_xip_image_errors
int
p9_xip_dd_section_support(const void* i_image,
                          const int i_mainSectionId,
                          const int i_subSectionId,
                          MyBool_t* o_bDdSupport);


/// \brief Decode a TOC entry from dump file
///
///\param[in] - i_image - seeprom image
///\param[in] - i_dump - dump file
///\param[in] - i_imageToc - TOC entry
///\param[out] - o_item - decoded toc entry
///
///\return - 0 Success; non-0 See \ref p9_xip_image_errors
int
p9_xip_decode_toc_dump(void* i_image, void* i_dump,
        P9XipToc* i_imageToc,
        P9XipItem* o_item);

// PHYP has their own way of implementing the <string.h> functions. PHYP also
// does not allow static functions or data, so all of the XIP_STATIC functions
// defined here are global to PHYP.

#ifdef PPC_HYP

    #ifdef PLIC_MODULE
        #define strcpy(dest, src) hvstrcpy(dest, src)
        #define strlen(s) hvstrlen(s)
        #define strcmp(s1, s2) hvstrcmp(s1, s2)
    #endif //PLIC_MODULE

    #define XIP_STATIC

#else // PPC_HYP

    // #define XIP_STATIC static
    #define XIP_STATIC

#endif // PPC_HYP

/// \defgroup p9_xip_image_errors Error codes from P9-XIP image APIs
///
/// @{

/// A putative P9-XIP image does not have the correct magic number, or
/// contains some other major inconsistency.
#define P9_XIP_IMAGE_ERROR 1

/// The TOC may be missing, partially present or may have an alignment problem.
#define P9_XIP_TOC_ERROR 2

/// A named item was not found in the P9-XIP TOC, or a putative HALT address
/// is not associated with a halt code in .halt.
#define P9_XIP_ITEM_NOT_FOUND 3

/// A named item appears in the P9-XIP TOC, but the data is not present in
/// the image.  This error can occur if sections have been deleted from the
/// image.
#define P9_XIP_DATA_NOT_PRESENT 4

/// A named item appears in the P9-XIP TOC, but the data can not be
/// modified. This error will occur if an attempt is made to modify an
/// address-only entry.
#define P9_XIP_CANT_MODIFY 5

/// A direct or implied argument is invalid, e.g. an illegal data type or
/// section identifier, or an address not contained within the image.
#define P9_XIP_INVALID_ARGUMENT 6

/// A data type mismatch or an illegal type was specified or implied for an
/// operation.
#define P9_XIP_TYPE_ERROR 7

/// A bug in a P9-XIP image API
#define P9_XIP_BUG 8

/// The image must first be normalized with p9_xip_normalize().
#define P9_XIP_NOT_NORMALIZED 9

/// Attempt to delete a non-empty section that is not the final section of the
/// image, or an attempt to append data to a non-empty section that is not the
/// final section of the image, or an attempt to operate on an empty section
/// for those APIs that prohibit this.
#define P9_XIP_SECTION_ERROR 10

/// An address translation API returned a image address that was not at least
/// 4-byte aligned, or alignment violations were observed by
/// p9_xip_validate() or p9_xip_append().
#define P9_XIP_ALIGNMENT_ERROR 11

/// An API that performs dynamic memory allocation was unable to allocate
/// memory.
#define P9_XIP_NO_MEMORY 12

/// Attempt to get or set a vector element with an index that is outside of
/// the declared bounds of the vector.
#define P9_XIP_BOUNDS_ERROR 13

/// Attempt to grow the image past its defined memory allocation
#define P9_XIP_WOULD_OVERFLOW 14

/// Error returned from an TOR API function.
#define P9_XIP_TOR_API_ERROR 15

/// Hash collision creating the .fixed_toc section
#define P9_XIP_HASH_COLLISION 16

/// Invalid buffer. It had a NULL ptr.
#define P9_XIP_NULL_BUFFER 17

/// Image has been broken and unable to restore original image.
#define P9_XIP_CANT_RESTORE_IMAGE 18

/// .rings seciton for specific dd level is larger than the allowable size
#define P9_XIP_SECTION_SIZE_IS_ZERO 19

/// Specified section has no ddLevel support
#define P9_XIP_NO_DDLEVEL_SUPPORT 20

/// Specified ddLevel was not found in section
#define P9_XIP_DDLEVEL_NOT_FOUND 21

/// Code bug in the ddLevel handling codes
#define P9_XIP_DDLEVEL_CODE_BUG 22

/// Applications can expand this macro to declare an array of string forms of
/// the error codes if desired.
#define P9_XIP_ERROR_STRINGS(var)    \
    const char* var[] = {            \
        "Success",                   \
        "P9_XIP_IMAGE_ERROR",        \
        "P9_XIP_TOC_ERROR",          \
        "P9_XIP_ITEM_NOT_FOUND",     \
        "P9_XIP_DATA_NOT_PRESENT",   \
        "P9_XIP_CANT_MODIFY",        \
        "P9_XIP_INVALID_ARGUMENT",   \
        "P9_XIP_TYPE_ERROR",         \
        "P9_XIP_BUG",                \
        "P9_XIP_NOT_NORMALIZED",     \
        "P9_XIP_SECTION_ERROR",      \
        "P9_XIP_ALIGNMENT_ERROR",    \
        "P9_XIP_NO_MEMORY",          \
        "P9_XIP_BOUNDS_ERROR",       \
        "P9_XIP_WOULD_OVERFLOW",     \
        "P9_XIP_TOR_API_ERROR",      \
        "P9_XIP_HASH_COLLISION",     \
        "P9_XIP_NULL_BUFFER",        \
        "P9_XIP_CANT_RESTORE_IMAGE", \
        "P9_XIP_SECTION_SIZE_IS_ZERO",\
        "P9_XIP_NO_DDLEVEL_SUPPORT", \
        "P9_XIP_DDLEVEL_NOT_FOUND",  \
        "P9_XIP_DDLEVEL_CODE_BUG",   \
    }

/// Applications can use this macro to safely index the array of error
/// strings.
#define P9_XIP_ERROR_STRING(var, n)                              \
    ((((n) < 0) || ((n) > (int)(sizeof(var) / sizeof(char*)))) ? \
     "Bug : Invalid P9-XIP error code" : var[n])

/// @}

#if 0
{
    /* So __cplusplus doesn't mess w/auto-indent */
#endif
#ifdef __cplusplus
}
#endif

#endif  // __ASSEMBLER__


////////////////////////////////////////////////////////////////////////////
// Assembler Definitions
////////////////////////////////////////////////////////////////////////////

#ifdef __ASSEMBLER__

/// Create an XIP TOC entry
///
/// \param[in] index The string form of the \a index symbol is created and
/// linked from the TOC entry to allow external search procedures to locate
/// the \a address.
///
/// \param[in] type One of the P9_XIP_* type constants; See \ref
/// p9_xip_toc_types.
///
/// \param[in] address The address of the idexed code or data; This will
/// typically be a symbol.
///
/// \param[in] elements <Optional> For vector types, number of elements in the
/// vector, which is limited to an 8-bit unsigned integer.  This parameter
/// defaults to 1 which indicates a scalar type. Declaring a vector with 0
/// elements disables bounds checking on vector accesses, and can be used if
/// very large or indeterminate sized vectors are required. The TOC format
/// does not support vectors of strings or addresses.
///
/// The \c .xip_toc macro creates a XIP Table of Contents (TOC) structure in
/// the \c .toc section, as specified by the parameters.  This macro is
/// typically not used directly in assembly code.  Instead programmers should
/// use .xip_quad, .xip_quada, .xip_quadia, .xip_address or .xip_string

    .macro .xip_toc, index:req, type:req, address:req, elements=1

        .if (((\type) < 1) || ((\type) > P9_XIP_MAX_TYPE_INDEX))
            .error ".xip_toc : Illegal type index"
        .endif

        // First push into the .strings section to lay down the
        // string form of the index name under a local label.

        .pushsection .strings
7667862:
        .asciz "\index"
        .popsection

        // Now the 12-byte TOC entry is created.  Push into the .toc section
        // and lay down the first 4 bytes which are always a pointer to the
        // string just declared.  The next 4 bytes are the address of the data
        // (or the address itself in the case of address types). The final 4
        // bytes are the type, section (always 0 prior to normalization),
        // number of elements, and a padding byte.

        .pushsection .toc

        .long 7667862b, (\address)
        .byte (\type), 0, (\elements), 0

        .popsection

    .endm


/// Allocate and initialize 64-bit global scalar or vector data and create the
/// TOC entry.
///
/// \param[in] symbol The name of the scalar or vector; this name is also used
/// as the TOC index of the data.
///
/// \param[in] init The initial value of (each element of) the data.
/// This is a 64-bit integer; To allocate address pointers use .xip_quada.
///
/// \param[in] elements The number of 64-bit elements in the data structure,
/// defaulting to 1, with a maximum value of 255.
///
/// \param[in] section The section where the data will be allocated,
/// default depends on the memory space

    .macro .xip_quad, symbol:req, init:req, elements=1, section

        ..xip_quad_helper .quad, \symbol, (\init), (\elements), \section

    .endm


/// Allocate and initialize 64-bit global scalar or vector data containing a
/// relocatable address in and create the TOC entry.
///
/// \param[in] symbol The name of the scalar or vector; this name is also used
/// as the TOC index of the data.
///
/// \param[in] init The initial value of (each element of) the data.  This
/// will typically be a symbolic address. If the intention is to define an
/// address that will always be filled in later by image manipulation tools,
/// then use the .xip_quad macro with a 0 initial value.
///
/// \param[in] elements The number of 64-bit elements in the data structure,
/// defaulting to 1, with a maximum value of 255.
///
/// \param[in] section The section where the data will be allocated,
/// default depends on the memory space

    .macro .xip_quada, symbol:req, offset:req, elements=1, section

        ..xip_quad_helper .quada, \symbol, (\offset), (\elements), \section

    .endm


/// Helper for .xip_quad and .xip_quada

    .macro ..xip_quad_helper, directive, symbol, init, elements, section

        .if (((\elements) < 1) || ((\elements) > 255))
            .error "The number of vector elements must be in the range 1..255"
        .endif

        ..xip_pushsection \section
        .balign 8

        .global \symbol
\symbol\():
        .rept (\elements)
            \directive (\init)
        .endr

        .popsection

        .xip_toc \symbol, P9_XIP_UINT64, \symbol, (\elements)

    .endm


/// Allocate and initialize 64-bit global scalar or vector data containing
/// full 64-bit addresses and create a TOC entry
///
/// \param[in] symbol The name of the scalar or vector; this name is also used
/// as the TOC index of the data.
///
/// \param[in] space A valid image memory space descriptor
///
/// \param[in] offset A 32-bit relocatable offset
///
/// \param[in] elements The number of 64-bit elements in the data structure,
/// defaulting to 1, with a maximum value of 255.
///
/// \param[in] section The section where the data will be allocated,
/// default depends on the memory space

    .macro .xip_quadia, symbol:req, space:req, offset:req, elements=1, section

        .if (((\elements) < 1) || ((\elements) > 255))
            .error "The number of vector elements must be in the range 1..255"
        .endif

        ..xip_pushsection \section
        .balign 8

        .global \symbol
\symbol\():
        .rept (\elements)
            .quadia (\space), (\offset)
        .endr

        .popsection

        .xip_toc \symbol, P9_XIP_UINT64, \symbol, (\elements)

    .endm

/// Default push into .ipl_data unless in an OCI space, then .data

    .macro ..xip_pushsection, section

        .ifnb \section
            .pushsection \section
        .else
            .if (_PGAS_DEFAULT_SPACE == PORE_SPACE_OCI)
                .pushsection .data
            .else
                .pushsection .ipl_data
            .endif
        .endif

        .balign 8

    .endm

/// Allocate and initialize a string in .strings
///
/// \param[in] index The string will be stored in the TOC using this index
/// symbol.
///
/// \param[in] string The string to be allocated in .strings. String space is
/// fixed once allocated.  Strings designed to be overwritten by external tools
/// should be allocated to be as long as eventually needed (e.g., by a string
/// of blanks.)

    .macro .xip_string, index:req, string:req

        .pushsection .strings
7874647:
        .asciz "\string"
        .popsection

        .xip_toc \index, P9_XIP_STRING, 7874647b

    .endm


/// Shorthand to create a TOC entry for an address
///
/// \param[in] index The symbol will be indexed as this name
///
/// \param[in] symbol <Optional> The symbol to index; by default the same as
/// the index.

    .macro .xip_address, index:req, symbol

        .ifb \symbol
            .xip_toc \index, P9_XIP_ADDRESS, \index
        .else
            .xip_toc \index, P9_XIP_ADDRESS, \symbol
        .endif

    .endm


    .macro  .xip_section, s, alignment=1, empty=0
        .ifnb \s
_\s\()_section:
            .if \empty
                .long   0
                .long   0
            .else
                .long   _\s\()_offset
                .long   _\s\()_size
            .endif
        .else
            .long   0
            .long   0
        .endif
        .byte   (\alignment)
        .byte   0, 0, 0
    .endm

#endif  // __ASSEMBLER__

#ifndef __ASSEMBLER__

/**************************************************************************/
/* Hardware Image                                                         */
/**************************************************************************/
typedef enum
{
    P9_XIP_SECTION_HW_SBE       = P9_XIP_SECTIONS_PLUS(0),
    P9_XIP_SECTION_HW_QME       = P9_XIP_SECTIONS_PLUS(1),
    P9_XIP_SECTION_HW_XGPE      = P9_XIP_SECTIONS_PLUS(2),
    P9_XIP_SECTION_HW_PGPE      = P9_XIP_SECTIONS_PLUS(3),
    P9_XIP_SECTION_HW_RESTORE   = P9_XIP_SECTIONS_PLUS(4),
    P9_XIP_SECTION_HW_IOPPE     = P9_XIP_SECTIONS_PLUS(5),
    P9_XIP_SECTION_HW_IOPXRAM   = P9_XIP_SECTIONS_PLUS(6),
    P9_XIP_SECTION_HW_OVERLAYS  = P9_XIP_SECTIONS_PLUS(7),
    P9_XIP_SECTION_HW_DYNAMIC   = P9_XIP_SECTIONS_PLUS(8),
    P9_XIP_SECTION_HW_DYN_FEAT  = P9_XIP_SECTIONS_PLUS(9),
    P9_XIP_SECTION_HW_DYN_SERV  = P9_XIP_SECTIONS_PLUS(10),
    P9_XIP_SECTIONS_HW          = P9_XIP_SECTIONS_PLUS(11) // # sections
} p9_xip_section_hw_t;

#define P9_XIP_SECTION_NAMES_HW(var)      \
    P9_XIP_SECTION_NAMES(var,             \
                         ".sbe",          \
                         ".qme",          \
                         ".xgpe",         \
                         ".pgpe",         \
                         ".core_restore", \
                         ".ioppe",        \
                         ".iopxram",      \
                         ".overlays",     \
                         ".dynamic",      \
                         ".dyn_features", \
                         ".dyn_services")

/**************************************************************************/
/* SBE Image                                                              */
/**************************************************************************/
typedef enum
{
    P9_XIP_SECTION_SBE_LOADERTEXT      = P9_XIP_SECTIONS_PLUS(0),
    P9_XIP_SECTION_SBE_PIBREPRDATA     = P9_XIP_SECTIONS_PLUS(1),
    P9_XIP_SECTION_SBE_TEXT            = P9_XIP_SECTIONS_PLUS(2),
    P9_XIP_SECTION_SBE_DATA            = P9_XIP_SECTIONS_PLUS(3),
    P9_XIP_SECTION_SBE_BASE            = P9_XIP_SECTIONS_PLUS(4),
    P9_XIP_SECTION_SBE_BASELOADER      = P9_XIP_SECTIONS_PLUS(5),
    P9_XIP_SECTION_SBE_RINGS           = P9_XIP_SECTIONS_PLUS(6),
    P9_XIP_SECTION_SBE_OVERRIDES       = P9_XIP_SECTIONS_PLUS(7),
    P9_XIP_SECTION_SBE_HBBL            = P9_XIP_SECTIONS_PLUS(8),
    P9_XIP_SECTION_SBE_FA_EC_CL2_FAR   = P9_XIP_SECTIONS_PLUS(9),
    P9_XIP_SECTION_SBE_FA_EC_MMA_FAR   = P9_XIP_SECTIONS_PLUS(10),
    P9_XIP_SECTION_SBE_FA_RING_OVRD    = P9_XIP_SECTIONS_PLUS(11),
    P9_XIP_SECTION_SBE_RINGIDFEATLIST  = P9_XIP_SECTIONS_PLUS(12),
    P9_XIP_SECTION_SBE_HDCT            = P9_XIP_SECTIONS_PLUS(13),
    P9_XIP_SECTION_SBE_SBH_FIRMWARE    = P9_XIP_SECTIONS_PLUS(14),
    P9_XIP_SECTION_SBE_SBH_HBBL        = P9_XIP_SECTIONS_PLUS(15),
    P9_XIP_SECTION_SBE_SB_SETTINGS     = P9_XIP_SECTIONS_PLUS(16),
    P9_XIP_SECTION_SBE_SB_VERIFICATION = P9_XIP_SECTIONS_PLUS(17),
    P9_XIP_SECTIONS_SBE                = P9_XIP_SECTIONS_PLUS(18) // # sections
} p9_xip_section_sbe_t;

#define P9_XIP_SECTION_NAMES_SBE(var)     \
    P9_XIP_SECTION_NAMES(var,             \
                         ".loader_text",  \
                         ".pibrepr_data", \
                         ".text",         \
                         ".data",         \
                         ".base",         \
                         ".baseloader",   \
                         ".rings",        \
                         ".overrides",    \
                         ".hbbl",         \
                         ".fa_ec_cl2_far", \
                         ".fa_ec_mma_far", \
                         ".fa_ring_ovrd",  \
                         ".ringidfeatlist",\
                         ".hdct",\
                         ".sbh_firmware",\
                         ".sbh_hbbl",\
                         ".sb_settings",\
                         ".sb_verification")

/**************************************************************************/
/* QME Image                                                             */
/**************************************************************************/
typedef enum
{
    P9_XIP_SECTION_QME_LVL1_BL   = P9_XIP_SECTIONS_PLUS(0),
    P9_XIP_SECTION_QME_LVL2_BL   = P9_XIP_SECTIONS_PLUS(1),
    P9_XIP_SECTION_QME_HCODE     = P9_XIP_SECTIONS_PLUS(2),
    P9_XIP_SECTION_QME_RINGS     = P9_XIP_SECTIONS_PLUS(3),
    P9_XIP_SECTION_QME_META_DATA = P9_XIP_SECTIONS_PLUS(4),
    P9_XIP_SECTIONS_QME          = P9_XIP_SECTIONS_PLUS(5) // # sections
} p9_xip_section_qme_t;

#define P9_XIP_SECTION_NAMES_QME(var)          \
    P9_XIP_SECTION_NAMES(var,                  \
                         ".lvl1_bl",           \
                         ".lvl2_bl",           \
                         ".hcode",             \
                         ".rings",             \
                         ".meta_data")

/**************************************************************************/
/* XGPE Image                                                             */
/**************************************************************************/
typedef enum
{
    P9_XIP_SECTION_XGPE_XPMR_HDR    =   P9_XIP_SECTIONS_PLUS(0),
    P9_XIP_SECTION_XGPE_LVL1_BL     =   P9_XIP_SECTIONS_PLUS(1),
    P9_XIP_SECTION_XGPE_LVL2_BL     =   P9_XIP_SECTIONS_PLUS(2),
    P9_XIP_SECTION_XGPE_HCODE       =   P9_XIP_SECTIONS_PLUS(3),
    P9_XIP_SECTION_XGPE_AUX_TASK    =   P9_XIP_SECTIONS_PLUS(4),
    P9_XIP_SECTION_XGPE_META_DATA   =   P9_XIP_SECTIONS_PLUS(5),
    P9_XIP_SECTIONS_XGPE            =   P9_XIP_SECTIONS_PLUS(6) // # sections
} p9_xip_section_xgpe_t;

#define P9_XIP_SECTION_NAMES_XGPE(var)         \
    P9_XIP_SECTION_NAMES(var,                  \
                         ".xpmr_hdr",          \
                         ".lvl1_bl",           \
                         ".lvl2_bl",           \
                         ".hcode",             \
                         ".aux_task",          \
                         ".meta_data")

/**************************************************************************/
/* PGPE Image                                                             */
/**************************************************************************/
typedef enum
{
    P9_XIP_SECTION_PGPE_PPMR_HDR    =   P9_XIP_SECTIONS_PLUS(0),
    P9_XIP_SECTION_PGPE_LVL1_BL     =   P9_XIP_SECTIONS_PLUS(1),
    P9_XIP_SECTION_PGPE_LVL2_BL     =   P9_XIP_SECTIONS_PLUS(2),
    P9_XIP_SECTION_PGPE_HCODE       =   P9_XIP_SECTIONS_PLUS(3),
    P9_XIP_SECTION_PGPE_META_DATA   =   P9_XIP_SECTIONS_PLUS(4),
    P9_XIP_SECTIONS_PGPE            =   P9_XIP_SECTIONS_PLUS(5) // # sections
} p9_xip_section_pgpe_t;

#define P9_XIP_SECTION_NAMES_PGPE(var)         \
    P9_XIP_SECTION_NAMES(var,                  \
                         ".ppmr_hdr",          \
                         ".lvl1_bl",           \
                         ".lvl2_bl",           \
                         ".hcode",             \
                         ".meta_data")

/**************************************************************************/
/* Core Restore Image                                                     */
/**************************************************************************/
typedef enum
{
    P9_XIP_SECTION_RESTORE_CPMR_HDR          = P9_XIP_SECTIONS_PLUS(0),
    P9_XIP_SECTION_RESTORE_SELF_SAVE_RESTORE = P9_XIP_SECTIONS_PLUS(1),
    P9_XIP_SECTIONS_RESTORE                  = P9_XIP_SECTIONS_PLUS(2) // # sections
} p9_xip_section_restore_t;
#define P9_XIP_SECTION_NAMES_RESTORE(var)    \
    P9_XIP_SECTION_NAMES(var,                \
                         ".cpmr_hdr",        \
                         ".self_save_restore")

/**************************************************************************/
/* IOPPE Image                                                            */
/**************************************************************************/
typedef enum
{
    P9_XIP_SECTION_IOPPE_IOO     = P9_XIP_SECTIONS_PLUS(0),
    P9_XIP_SECTION_IOPPE_MEMREGS = P9_XIP_SECTIONS_PLUS(1),
    P9_XIP_SECTION_IOPPE_NV      = P9_XIP_SECTIONS_PLUS(2),
    P9_XIP_SECTIONS_IOPPE        = P9_XIP_SECTIONS_PLUS(3) // # sections
} p9_xip_section_ioppe_t;

#define P9_XIP_SECTION_NAMES_IOPPE(var)        \
    P9_XIP_SECTION_NAMES(var,                  \
                         ".ioo",               \
                         ".memregs",           \
                         ".nv")

/**************************************************************************/
/* IOPXRAM Image                                                          */
/**************************************************************************/
typedef enum
{
    P9_XIP_SECTION_IOPXRAM_IOP_FW  = P9_XIP_SECTIONS_PLUS(0),
    P9_XIP_SECTION_IOPXRAM_VER     = P9_XIP_SECTIONS_PLUS(1),
    P9_XIP_SECTIONS_IOPXRAM        = P9_XIP_SECTIONS_PLUS(2) // # sections
} p9_xip_section_iopxram_t;

#define P9_XIP_SECTION_NAMES_IOPXRAM(var)        \
    P9_XIP_SECTION_NAMES(var,                    \
                         ".iop_fw",              \
                         ".iop_fw_ver")

#endif  // ifndef __ASSEMBLER__

#endif  // __P10_IPL_IMAGE_H__

// *INDENT-ON*
