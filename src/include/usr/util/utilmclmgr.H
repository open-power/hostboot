/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/util/utilmclmgr.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2022                        */
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
#ifndef __MASTERCONTAINERLIDMGR_H
#define __MASTERCONTAINERLIDMGR_H

#include <vector>
#include <map>
#include <secureboot/containerheader.H>
#include <errl/errlentry.H>
#include <usr/vmmconst.h>
#include <securerom/ROM.H>
#include <limits.h>

// Forward declarations
class MasterContainerLidMgrTest;

namespace MCL
{

/**
 *  @brief Structure used to hold information about a container loaded into
 *      memory using the MCL manager
 */
struct LoadedContainerInfo_t
{
    void*  pSecureHeader; ///< Virtual address of secure header; nullptr if N/A
    void*  pContent;      ///< Virtual address of container logical content
    size_t size;          ///< Size of container logical content in bytes

    /**
     *  @brief Builds a default LoadedContainerInfo_t
     */
    LoadedContainerInfo_t()
        : pSecureHeader(nullptr),
          pContent(nullptr),
          size(0)
    {
    }
};

// Component ID(name) within MCL
typedef std::array<uint8_t,16> ComponentID;

// Component ID in string form
// NOTE: ComponentID in the MCL does not include NULL terminator so include room
typedef char CompIdString[17];

// Constants to simplify checking for the MCL and POWERVM/UCD9090 comp ids
extern const ComponentID g_MclCompId;
extern const ComponentID g_PowervmCompId;
extern const ComponentID g_OpalCompId;
extern const ComponentID g_UcdCompId;
extern const ComponentID g_NvdimmCompId;

// @enum Permission Types for MCL Component
enum class CompFlags : uint16_t
{
    UNSIGNED = 0x0000,
    SIGNED = 0x8000,
    PRE_VERIFY = 0x4000,
    SIGNED_PRE_VERIFY = SIGNED|PRE_VERIFY,
};

/**
 * @brief  Comp Flags logical AND overload
 *
 * @param[in]  lhs - CompFlags to compare to
 * @param[in]  rhs - CompFlags to compare to
 *
 * @return CompFlags - The result of logically AND'ing two CompFlags
 */
inline CompFlags operator&(const CompFlags &lhs, const CompFlags &rhs)
{
    return  static_cast<CompFlags>(
                static_cast<uint16_t>(lhs) & static_cast<uint16_t>(rhs)
            );
}

/**
 * @brief  Comp Flags logical OR overload
 *
 * @param[in]  lhs - CompFlags to compare to
 * @param[in]  rhs - CompFlags to compare to
 *
 * @return CompFlags - The result of logically OR'ing two CompFlags
 */
inline CompFlags operator|(const CompFlags &lhs, const CompFlags &rhs)
{
    return  static_cast<CompFlags>(
                static_cast<uint16_t>(lhs) | static_cast<uint16_t>(rhs)
            );
}

// MCL header section
struct MclHeader
{
    uint32_t version;
    uint32_t offsetToCompSection;
    uint8_t numComponents;
    uint8_t reserved[7];
} __attribute__ ((packed));

// Structure for each component within the MCL
struct MclCompSection
{
    ComponentID compId;
    uint32_t sizeCompList;
    uint32_t numLids;
    CompFlags flags;
    uint8_t reserved[6];
    // Array size determined by numLids
    uint32_t lidArray[];
    //padding to 16 byte boundary
} __attribute__ ((packed));

// Padded size for MCL components
extern const size_t MclCompSectionPadSize;

// @brief Structure that holds lid ids and sizes
struct LidInfo
{
    LidInfo(): id(0), size(0), vAddr(nullptr) {}
    LidInfo(uint32_t i_id): id(i_id), size(0), vAddr(nullptr) {}
    LidInfo(uint32_t i_id, size_t i_size): id(i_id), size(i_size),
        vAddr(nullptr) {}

    uint32_t id; // LID ID
    size_t size; // Size of LID
    void* vAddr; // Virtual address where LID was loaded

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

// @brief Structure that holds information on each component in the MCL
struct CompInfo
{
    CompFlags flags;
    uint64_t mainstoreAddr;
    size_t totalSize;
    size_t protectedSize;
    size_t unprotectedSize;
    std::vector<LidInfo> lidIds;

    // Constructors
    CompInfo()
        : flags(CompFlags::UNSIGNED), mainstoreAddr(0), totalSize(0),
          protectedSize(0), unprotectedSize(0), lidIds{} {}
    CompInfo(CompFlags i_flags)
        : flags(i_flags), mainstoreAddr(0), totalSize(0), protectedSize(0),
          unprotectedSize(0), lidIds{} {}

    /**
     * @brief  Comp Info equality comparison
     *
     * @param[in]  rhs - CompInfo to compare to
     * @return bool - true if Comp Infos are equal, false otherwise
     */
    bool operator==(const CompInfo& rhs) const
    {
        return (flags == rhs.flags &&
                mainstoreAddr == rhs.mainstoreAddr &&
                totalSize == rhs.totalSize &&
                protectedSize == rhs.protectedSize &&
                unprotectedSize == rhs.unprotectedSize &&
                lidIds == rhs.lidIds);
    }

    /**
     * @brief  Comp Info inequality comparison
     *
     * @param[in]  rhs - CompInfo to compare to
     * @return bool - true if Comp Infos are not equal, false otherwise
     */
    bool operator!=(const CompInfo& rhs) const
    {
        return !(*this == rhs);
    }

    /**
     * @brief  Print Comp Info in human friendly format
     * @return N/A
     */
    void print() const;
};

// A global POWERVM component info struct. This struct is populated in istep20
// by eBMC with the lid numbers of the POWERVM component and their sizes. It is
// later used to populate the reserved memory areas correctly with the right
// lids of the right sizes.
extern CompInfo g_PowervmCompInfo;

// Structure for Comp Info cache
typedef std::map<ComponentID, CompInfo> CompInfoMap;

/**
 * @brief Convert Component ID to a char*
 *        Helpful for trace
 *
 * @param[in] i_compId - Component ID to convert
 * @param[out] o_compIdStr - Component ID String
 *
 * @return N/A
 */
void compIdToString(const ComponentID i_compId, CompIdString o_compIdStr);

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
 * @retval !nullptr   Error; Error log handle points to valid error log
 */

errlHndl_t decompressLid(const uint8_t * i_buffer, uint8_t * io_buffer,
                     uint64_t i_size, uint64_t& io_size);

/**
 * @brief Convert/truncate Component ID to a uint64_t
 *        Helpful for FFDC
 *
 * @param[in] i_compId - Component ID to convert
 *
 * @return uint64_t - truncated Component ID
 */
uint64_t compIdToInt(const ComponentID i_compId);

/**
 * @brief Extract list of lid ids from lid info vector
 *
 * @param[in] i_lidIds - Vector to pull lid ids out of
 *
 * @return RomVerifyIds - IDs associated with secure component
 */
RomVerifyIds extractLidIds(const std::vector<LidInfo>& i_lidIds);

// @brief Class to manager the Master Container Lid provided by the FSP
class MasterContainerLidMgr
{

    public:

    /**
     * @brief Default Constructor
     *     Initializes memory spaces, loads, and parses the MCL.
     *
     * @param[in] i_loadOnly Only load content into memory on subsequent
     *     requests to process components.  Do not not move the content to
     *     Hostboot reserved memory.
     */
    MasterContainerLidMgr(bool i_loadOnly = false);

    /**
     * @brief Destructor. Cleans up memory allocated for class
     */
    ~MasterContainerLidMgr();

    /**
     * @brief Process each component in the MCL.
     *        See: processComponent for more info
     */
    errlHndl_t processComponents();

    /**
     *  @brief Process a single, named component from the MCL.
     *      Loads the specified component into the managed mainstore memory
     *      region.  If component is marked pre-verified, cryptographically
     *      verifies the component and extends its measurement to the TPM.
     *      If MCL manager is in non-load-only mode, copies the content into
     *      Hostboot reserved memory region as well.
     *
     *  @param[in] i_compId Component ID to load
     *  @param[out] o_info  Information (LID ID, size, virtual address, etc.)
     *      for the LIDs that were loaded.
     *
     *  @param[in] i_forceProcessPhyp the flag to force processing of the PHYP
     *             component. False by default.
     *
     *  @note: The container will go out of scope if another container is loaded
     *      or the MCL manager goes out of scope.
     *
     *  @note: Component info will be reset on each call
     *
     *  @return errlHndl_t Error log handle
     *  @retval nullptr    Success
     *  @retval !nullptr   Error; Error log handle points to valid error log
     */
    errlHndl_t processSingleComponent(
        const ComponentID&           i_compId,
              CompInfo&              o_info,
              bool                   i_forceProcessPhyp = false);

    /**
     *  @brief Manages a single, named component from the MCL.
     *         Directs the call to manageComponent and subsequently
     *         will get routed to the proper component management
     *         routine(s).
     *
     *         manageSingleComponent allows custom logic to be applied
     *         for a particular component(s) handling/use cases.
     *
     *  @param[in] i_compId Component ID to manage
     *  @param[out] o_info  Original information (LID ID, size, virtual address, etc.)
     *      for component that was operated on
     *
     *  @param[in] i_forceProcessPhyp the flag to force processing of the PHYP
     *             component. False by default.
     *
     *  @note: The container will go out of scope if another container is loaded
     *      or the MCL manager goes out of scope.
     *
     *  @return errlHndl_t Error log handle
     *  @retval nullptr    Success
     *  @retval !nullptr   Error; Error log handle points to valid error log
     */

    errlHndl_t manageSingleComponent(
        const ComponentID&           i_compId,
              CompInfo&              o_info,
              bool                   i_forceProcessPhyp = false);

    /**
     * @brief TPM extend information for secure components
     *
     * @param[in] i_compId - Component Id
     * @param[in] i_conHdr - Container header with information to extend
     *
     * @return Error handle if error
     */
    static errlHndl_t tpmExtend(const ComponentID& i_compId,
                                const SECUREBOOT::ContainerHeader& i_conHdr);

    /**
     *  @brief Caches a copy of the PHyp secure header
     *
     *  @param[in] i_pHeader Pointer to PHyp secure header;
     *      Must not be nullptr or API will assert.  Input header must be
     *      exactly PAGESIZE bytes
     */
    static void cachePhypHeader(const uint8_t* i_pHeader)
    {
        assert(i_pHeader != nullptr,
            "Bug! PHyp header pointer was nullptr");
        memcpy(cv_pPhypHeader,i_pHeader,PAGESIZE);
    }

    /**
     *  @brief Returns pointer to the cached PHyp secure header
     *
     *  @return const uint8_t* Pointer to cached Phyp secure header
     */
    static const uint8_t* getPhypHeader()
    {
        return cv_pPhypHeader;
    };

    protected:

    /**
     * @brief Custom Constructor.
     *        Same as default cstor, but passes in a custom MCL
     *        NOTE: protected cstor to be used by test cases only
     *              nullptr indicates to load from UtilLidMgr
     * @param[in] i_pMcl - pointer to custom MCL
     * @param[in] i_size - size of custom MCL
     */
    MasterContainerLidMgr(const void* i_pMcl,
                          const size_t i_size);

    private:

    /**
     * @brief Common function for all constructors to call to initialize the MCL
     *
     * @param[in] i_pMcl - Pointer to custom MCL if provided
     *                     NOTE: nullptr indicates to load from UtilLidMgr
     * @param[in] i_pMcl - Size of Custom MCL
     *
     * @return N/A
     */
    void initMcl(const void* i_pMcl = nullptr, const size_t i_mclSize = 0);

    /**
     * @brief Responsible for allocating space for MCL mgr component parsing
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
     * @brief Responsible for deallocating space used by MCL component parsing
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
     * @brief Parse MCL and store important information in Comp Info Cache
     *        Will also print out Comp Info Cache
     * @return N/A
     */
    void parseMcl();

    /**
     * @brief Print MCL Comp Info Cache in human friendly format
     * @return N/A
     */
    void printCompInfoCache();

    /**
     * @brief Process single component in the MCL.
     *        Loads, verifies, tpm extends lids and loads into hb resv memory
     *
     * @param[in]     i_compId - Component Id
     * @param[in/out] io_compInfo - Component info of component to process
     * @param[in]     i_forceProcessPhyp - the flag to force processing of the
     *                PHYP component. False by default.
     *
     * @return Error handle if error
     */
    errlHndl_t processComponent(const ComponentID& i_compId,
                                CompInfo& io_compInfo,
                                bool i_forceProcessPhyp = false);

    /**
     * @brief Manages a single, named component from the MCL
     *      (this case is for PHYP lid management).
     *
     *      Walks the CompInfo previously cached to determine if
     *      the lid header represents an XZ compressed lid.
     *
     *      If XZ compression is indicated in the lid header
     *      (the lid resides in hostboot temporary memory, MCL_TMP_ADDR)
     *      then performs direct decompression to mainstore memory for PHYP.
     *
     * @param[in]     i_compId - Component Id
     * @param[in/out] io_compInfo - Info of component to process
     *
     * @return Error handle if error
     */

    errlHndl_t managePhypComponent(const ComponentID& i_compId,
                                CompInfo& io_compInfo);

    /**
     * @brief Load all lids associated with a Component into contiguous memory
     *        NOTE: updates the lid sizes in CompInfo
     *
     * @param[in] io_compInfo - Component info of component to verify
     * @param[out] o_totalSize - Size of all lids reported by the FSP
     * @param[in] i_isPhypComp - Indicates if PHYP lids
     *
     * @return Error handle if error
     */
    errlHndl_t loadLids(CompInfo& io_compInfo, size_t& o_totalSize,
                        bool i_isPhypComp);

    /**
     * @brief Decompress lids associated with a Component into mainstore memory
     *        NOTE: NO updates are made to lid sizes in CompInfo
     *
     * @param[in] io_compInfo - Info of component to process
     * @param[out] o_totalSize - Reported size of all lids post decompression
     *
     * @return Error handle if error
     */

    errlHndl_t managePhypLids(CompInfo& io_compInfo, size_t& o_totalSize);

    /**
     * @brief Verify and Extend Component
     *
     * @param[in] i_compId - Component Id
     * @param[in] io_compInfo - Component info of component to verify
     *
     * @return Error handle if error
     *         Note: Will not return on Secure Verification Error
     */
    errlHndl_t verifyExtend(const ComponentID& i_compId,
                            CompInfo& io_compInfo);

    // Physical addresses reserved for the MCL itself
    uint64_t iv_mclAddr;

    // Maximum size of memory for the MCL itself
    size_t iv_mclSize;

    // Physical addresses reserved for temp MCL mgr space
    uint64_t iv_tmpAddr;

    // Maximum size of memory for temp MCL mgr workspace
    size_t iv_tmpSize;

    // Maximum size based on MCL or temp components
    size_t iv_maxSize;

    // Pointer to MCL virtual address space
    void* iv_pMclVaddr;

    // Pointer to MCL temp virtual address space
    void* iv_pTempVaddr;

    // Pointer to either MCL or TMP virtual address spaces
    void* iv_pVaddr;

    // Cache Components and their corresponding lids
    CompInfoMap iv_compInfoCache;

    // Indicates that Master Container Lid has a header
    bool iv_hasHeader;

    // Cache current comp id string for easy tracing
    CompIdString iv_curCompIdStr;

    // When processing a component, only load the component and verify / measure
    // it (do not copy it to reserved memory).
    bool iv_loadOnly;

    // Cached PHyp header
    static uint8_t cv_pPhypHeader[PAGE_SIZE];

    // Allow test cases to call custom constructors and have direct access
    friend class ::MasterContainerLidMgrTest;
};

} // end namespace MCL

#endif
