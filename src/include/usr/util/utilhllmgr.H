/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/util/utilhllmgr.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2025                        */
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
#ifndef __HLLMGR_H
#define __HLLMGR_H

#include <vector>
#include <map>
#include <secureboot/containerheader.H>
#include <errl/errlentry.H>
#include <usr/vmmconst.h>
#include <securerom/ROM.H>
#include <limits.h>
#include <securerom/sha512.H>

// Forward declarations
class HLLTest;

namespace HLL
{

// Group ID(name) within HLL
typedef std::array<uint8_t,16> GroupID;

// Group ID in string form
// NOTE: GroupID in the HLL does not include NULL terminator so include room
typedef char GroupIdString[17];

// Constants used to group and manage the lids
// When reading in the HLL TOC the entries and sections of
// the HLL are placed in the appropriate group to be handled by specific
// code logic later in the processing.
extern const GroupID g_HLLGroup;
extern const GroupID g_HLLPowerVM;
extern const GroupID g_HLLPreVerified;

constexpr uint64_t HLL_EYE_CATCHER         = 0x46575342484C4C00; // FWSBHLL + 0x00
constexpr uint64_t HLL_POWERVM_EYE_CATCHER = 0x504f574552564d00; // POWERVM + 0x00
constexpr uint64_t HLL_ENTR_EYE_CATCHER    = 0x454E545200;       // ENTR    + 0x00

constexpr uint16_t HLL_SUPPORTED_VERSION   = 0x1;

// @enum Flags for HLL Entries
enum class HllEntryFlags : uint16_t
{
    UNSIGNED = 0x0000,
    SIGNED = 0x8000,
    PRE_VERIFY = 0x4000,
    SIGNED_PRE_VERIFY = SIGNED|PRE_VERIFY,
};

/**
 * @brief  HLL Entry Flags logical AND overload
 *
 * @param[in]  lhs - HllEntryFlags to compare to
 * @param[in]  rhs - HllEntryFlags to compare to
 *
 * @return HllEntryFlags - The result of logically AND'ing two HllEntryFlags
 */
inline HllEntryFlags operator&(const HllEntryFlags &lhs, const HllEntryFlags &rhs)
{
    return  static_cast<HllEntryFlags>(
                static_cast<uint16_t>(lhs) & static_cast<uint16_t>(rhs)
            );
}

/**
 * @brief  Group Flags logical OR overload
 *
 * @param[in]  lhs - HllEntryFlags to compare to
 * @param[in]  rhs - HllEntryFlags to compare to
 *
 * @return HllEntryFlags - The result of logically OR'ing two HllEntryFlags
 */
inline HllEntryFlags operator|(const HllEntryFlags &lhs, const HllEntryFlags &rhs)
{
    return  static_cast<HllEntryFlags>(
                static_cast<uint16_t>(lhs) | static_cast<uint16_t>(rhs)
            );
}

// HLL header section
// See Hash List Secure Boot HLDD, Version 0.1
struct HLLHeader
{
    uint64_t EyeCatcher;
    uint16_t version;
    uint16_t CompatibleVersion; // oldest compatible version
    uint16_t NumberOfEntries; // Count of the TOCLidEntry
    uint16_t hashSignMode; // SHA3_512
    uint16_t HashEntrySize;
    uint16_t OffsetToHashListEntries;
    uint16_t OffsetToPowerVM;
    uint16_t Flags;
    uint8_t  reserved[104];
} __attribute__ ((packed));

// PowerVM header
struct PowerVmHeader
{
    uint64_t EyeCatcher;
    uint16_t SectionSize;
    uint16_t NumberOfPowerVmLids;
    uint16_t Flags;
    uint8_t  reserved[18];
    uint32_t PowerVmLids[]; // variable number of lids
} __attribute__ ((packed));

// LidEntry
struct LidEntry
{
    uint32_t EyeCatcher;
    uint32_t LidID;
    uint32_t LidSize;
    uint16_t OffsetToHash;
    uint16_t PreVerified : 1;
    uint16_t Unsigned    : 1;
    uint16_t FlagsRsvd   : 14;
    uint8_t  LidHash[]; // variable lid hash length
} __attribute__ ((packed));

struct HashEntry
{
    SHA512_t HashCalc;
}  __attribute__ ((packed));

// @brief Structure that holds lid ids and sizes
struct LidInfo
{
    LidInfo(): id(0), size(0), vAddr(nullptr), hllHash(), PreVerified(0), Unsigned(0), FlagsRsvd(0) {}
    LidInfo(uint32_t i_id): id(i_id), size(0), vAddr(nullptr), hllHash(), PreVerified(0), Unsigned(0), FlagsRsvd(0) {}
    LidInfo(uint32_t i_id, size_t i_size): id(i_id), size(i_size),
        vAddr(nullptr), hllHash(), PreVerified(0), Unsigned(0), FlagsRsvd(0) {}

    uint32_t id; // LID ID
    size_t size; // Size of LID
    void* vAddr; // Virtual address where LID was loaded
    HashEntry hllHash; // HLL Hash Value
    uint16_t PreVerified : 1;
    uint16_t Unsigned    : 1;
    uint16_t FlagsRsvd   : 14;

    /**
     * @brief  Lid Info equality comparison
     *
     * @param[in]  rhs - LidInfo to compare to
     * @return bool - true if Lid Infos are equal, false otherwise
     */
    bool operator==(const LidInfo& rhs) const
    {
        return (   (id == rhs.id)
                && (size == rhs.size)
                && (vAddr == rhs.vAddr));
    }

    /**
     * @brief  Lid Info inequality comparison
     *
     * @param[in]  rhs - LidInfo to compare to
     * @return bool - true if Lid Infos are not equal, false otherwise
     */
    bool operator!=(const LidInfo& rhs) const
    {
        return !(*this == rhs);
    }

};

// @brief Structure that holds information on each group in the HLL
// When reading in the HLL TOC the entries and sections of
// the HLL are placed in the appropriate group to be handled by specific
// code logic later in the processing.
// The GroupInfo is an object which tracks various data for the entire group.

struct GroupInfo
{
    HllEntryFlags flags;
    uint64_t mainstoreAddr;
    size_t totalSize;
    size_t protectedSize;
    size_t unprotectedSize;
    std::vector<LidInfo> lidIds;

    // Constructors
    GroupInfo()
        : flags(HllEntryFlags::UNSIGNED), mainstoreAddr(0), totalSize(0),
          protectedSize(0), unprotectedSize(0), lidIds{} {}
    GroupInfo(HllEntryFlags i_flags)
        : flags(i_flags), mainstoreAddr(0), totalSize(0), protectedSize(0),
          unprotectedSize(0), lidIds{} {}

    /**
     * @brief  Group Info equality comparison
     *
     * @param[in]  rhs - GroupInfo to compare to
     * @return bool - true if Group Infos are equal, false otherwise
     */
    bool operator==(const GroupInfo& rhs) const
    {
        return (flags == rhs.flags &&
                mainstoreAddr == rhs.mainstoreAddr &&
                totalSize == rhs.totalSize &&
                protectedSize == rhs.protectedSize &&
                unprotectedSize == rhs.unprotectedSize &&
                lidIds == rhs.lidIds);
    }

    /**
     * @brief  Group Info inequality comparison
     *
     * @param[in]  rhs - GroupInfo to compare to
     * @return bool - true if Group Infos are not equal, false otherwise
     */
    bool operator!=(const GroupInfo& rhs) const
    {
        return !(*this == rhs);
    }

    /**
     * @brief  Print Group Info in human friendly format
     * @return N/A
     */
    void print() const;
};

// Structure for Group Info cache
typedef std::map<GroupID, GroupInfo> GroupInfoMap;

/**
 * @brief Convert Group ID to a char*
 *        Helpful for trace
 *
 * @param[in] i_groupId - Group ID to convert
 * @param[out] o_groupIdStr - Group ID String
 *
 * @return N/A
 */
void groupIdToString(const GroupID i_groupId, GroupIdString o_groupIdStr);

/**
 * @brief Perform XZ decompression and copy to caller space
 *
 * @param[in]      i_buffer - Buffer containing compressed lid
 * @param[in/out]  io_buffer - Buffer that will contain decompressed lid
 * @param[in]      i_size - Size of the compressed lid
 * @param[in/out]  io_size -
 *                 On input reflects the size of io_buffer
 *                 On output reflects the size of the decompressed lid
 *
 * @return errlHndl_t Error log handle
 * @retval nullptr    Success
 * @retval !nullptr   Error log handle points to valid error log
 */

errlHndl_t decompressLid(const uint8_t * i_buffer, uint8_t * io_buffer,
                     uint64_t i_size, uint64_t& io_size);

/**
 * @brief Convert/truncate Group ID to a uint64_t
 *        Helpful for FFDC
 *
 * @param[in] i_compId - Group ID to convert
 *
 * @return uint64_t - truncated Group ID
 */
uint64_t groupIdToInt(const GroupID i_groupId);

/**
 * @brief Extract list of lid ids from lid info vector
 *
 * @param[in] i_lidIds - Vector to pull lid ids out of
 *
 * @return RomVerifyIds - IDs associated with secure groups
 */
RomVerifyIds extractLidIds(const std::vector<LidInfo>& i_lidIds);

// @brief Class to Manage the HLL
class HLLMgr
{
    public:

    /**
     * @brief Default Constructor
     *     Initializes memory spaces, loads, and parses an HLL.
     *
     * @param[in] i_toc_only Only initialize the TOC, leave the temp space as-is.
     *            For some isteps it is necessary to NOT touch the temp space
     *            when the class is constructed, so the i_toc_only means to
     *            skip touching the initialization of the temp space where the lids
     *            have already been populated.  This allows the TOC to be instantiated
     *            with the class constructor and then leverage the already populated
     *            temp space with the lids later in the IPL.
     *
     * @param[in] i_force_hll_load Because the PHYP HLL can sit in the MTOC space
     *            across HLLMgr() calls and isteps, this variable will be used to
     *            enforce that the PHYP HLL in the MTOC space gets cleared out
     *            such that the more recent PHYP HLL can be loaded.  This is
     *            especially necessary for MPIPLs. This should be set to true
     *            the absolute first time the HLLMgr constructor is called.
     */
    HLLMgr(bool i_toc_only = false,
           bool i_force_hll_load = false);

    /**
     * @brief Destructor. Cleans up memory allocated for class
     */
    ~HLLMgr();

     /** @brief  Performs the steps necessary for verifying the
     *          PowerVM payload
     *
     *          This is called at populate_hbruntime to verify
     *          each of the PowerVM lids
     *  @param([in] i_payload The PowerVM payload to verify
     *
     *  @retval nullptr on Success, otherwise error log handle
     */
    errlHndl_t verifyPowerVM(void * i_payload);

    /** @brief  Performs the steps necessary for managing the
     *          PowerVM group of lids
     *
     *          This is called at call_host_load_payload in the
     *          IPL to properly load PHYP to main store memory.
     *
     *  @retval nullptr on Success, otherwise error log handle
     */
    errlHndl_t managePowerVMGroup();

    /** @brief  Performs the steps necessary for managing the
     *          PreVerified group of lids.
     *
     *          This is called during populate_hbruntime which
     *          will handle the population of the reserved
     *          memory which will hold the pre-verified lids.
     *
     *  @retval nullptr on Success, otherwise error log handle
     */
    errlHndl_t managePreVerifiedGroup();

    /**
     * @brief TPM extend container information for secure components
     *
     * @param[in] i_groupId - Group Id
     * @param[in] i_conHdr  - Container header with information to extend
     *
     * @return Error handle if error
     */
    static errlHndl_t tpmExtendContainer(const GroupID& i_groupId,
                                const SECUREBOOT::ContainerHeader& i_conHdr);

    protected:

    /**
     * @brief Custom Constructor.
     *        Same as default cstor, but passes in a custom HLL
     *        NOTE: protected cstor to be used by test cases only
     *              nullptr indicates to load from UtilLidMgr
     * @param[in] i_pHLL - pointer to custom HLL
     * @param[in] i_size - size of custom HLL
     */
    HLLMgr(const void* i_pHLL,
                          const size_t i_size);

    private:

    /**
     * @brief Common function for all constructors to call to initialize the HLLMgr
     *
     * @param[in] i_pHLL - Pointer to custom HLL if provided
     *                     NOTE: nullptr indicates to load from UtilLidMgr
     * @param[in] i_HLLSize - Size of Custom HLL
     *
     * @return N/A
     */
    void initHLL(const void* i_pHLL = nullptr, const size_t i_HLLSize = 0);

    /**
     * @brief Responsible for allocating space for HLL mgr lid handling
     *        NOTE: Will shutdown if error occurs
     *
     * @param[in] i_physAddr  - Starting physical address to initialize memory
     * @param[in] i_size - Size to allocate
     * @param[in/out] io_pVaddr - Pointer to store virtual address pointer from
     *                            block map
     *                            NOTE: no-op unless the pointer is a nullptr
     *
     * @return N/A
     */
    void initMem(const uint64_t i_physAddr, const size_t i_size,
                 void *&io_pVaddr);

    /**
     * @brief Responsible for deallocating space used by HLL lid handling
     *        NOTE: Will shutdown if error occurs
     *
     * @param[in] i_physAddr - Starting physical address to deallocate from
     * @param[in/out] io_pVaddr - Pointer to virtual memory to release
     *                            NOTE: no-op if the pointer is nullptr
     *
     * @return N/A
     */
    void releaseMem(const uint64_t i_physAddr, void *&io_pVaddr);

    /**
     * @brief Checks the HLL to confirm that the versions are valid
     * @return bool True is valid versions, false if not
     */
    bool isValid();

    /**
     * @brief Parse the HLL and store important information in Group Info Cache
     * @return Error handle if error
     */
    errlHndl_t parseHLL();

    /**
     * @brief Print HLL Group Info Cache in human friendly format
     * @return N/A
     */
    void printGroupInfoCache();

    /**
     * @brief Reads the HLL and creates the appropriate data structures to be
     *        used later in the various methods during the IPL.
     *
     * @param[in]     i_groupId - Group Id
     * @param[in/out] io_groupInfo - Group info to process
     *
     * @return Error handle if error
     */
    errlHndl_t initMetaData(const GroupID& i_groupId,
                                GroupInfo& io_groupInfo);

    /**
     * @brief Load all lids associated with a Group into contiguous memory
     *        NOTE: updates the lid sizes in GroupInfo
     *
     * @param[in/out] io_groupInfo - Group info to verify
     * @param[out] o_totalSize - Size of all lids
     *
     * @return Error handle if error
     */
    errlHndl_t loadLids(GroupInfo& io_groupInfo, size_t& o_totalSize);

    /**
     * @brief Decompress lids associated with a Group into mainstore memory
     *        NOTE: NO updates are made to lid sizes in GroupInfo
     *
     * @param[in/out] io_groupInfo - Info of Group to process
     * @param[out] o_totalSize - Reported size of all lids post decompression
     *
     * @return Error handle if error
     */

    errlHndl_t managePhypLids(GroupInfo& io_groupInfo, size_t& o_totalSize);

    // Physical addresses reserved for the HLL itself
    uint64_t iv_HLLAddr;

    // Maximum size of memory for the HLL itself
    size_t iv_HLLSize;

    // Physical addresses reserved for temp HLL mgr space
    uint64_t iv_tmpAddr;

    // Maximum size of memory for temp HLL mgr workspace
    size_t iv_tmpSize;

    // Maximum size based on HLL or temp components
    size_t iv_maxSize;

    // Pointer to HLL virtual address space
    void* iv_pHLLVaddr;

    // Pointer to HLL temp virtual address space
    void* iv_pTempVaddr;

    // Pointer to either HLL or TMP virtual address spaces
    void* iv_pVaddr;

    // Cache Groups and their corresponding lids
    GroupInfoMap iv_groupInfoCache;

    // Indicates the HLL has a secure header
    bool iv_hasHeader;

    // Cache current group id string for easy tracing
    GroupIdString iv_curGroupIdStr;

    uint16_t iv_version = 0;

    // When creating an instance the following instance
    // variables are used to manage the temporary memory space.
    //
    // The HLLMgr instances are used at different IPL steps
    // and some isteps are not even executed on FSP systems,
    // so dynamic memory detection is used to properly setup
    // each new instance created.
    //
    // The memory management allows the HLL LID to be read
    // only once and then subsequent callers can create a
    // new instance and detect the memory has been initialized.
    //
    // For some isteps it is necessary to NOT touch the temp space
    // when the class is constructed, so the iv_toc_only means to
    // skip touching the initialization of the temp space where the lids
    // have already been populated.  This allows the TOC to be instantiated
    // with the class constructor and then leverage the already populated
    // temp space with the lids later in the IPL.
    //
    // However, in the case of MPIPLs, the original HLL might still be
    // in memory.  Therefore, use iv_force_hll_load on the first
    // instance the HLL Mgr constructor gets called to load the PHYP
    // payload to ensure a new HLL is loaded.
    bool iv_toc_only = false;
    bool iv_initMetaData_required = false;
    bool iv_initTempSpace_required = false;
    bool iv_force_hll_load = false;

    // HLL hash entry size, i.e. SHA512_t or future changes
    uint16_t iv_HashEntrySize = 0;

    // Allow test cases to call custom constructors and have direct access
    friend class ::HLLTest;
};

} // end namespace HLL

#endif
