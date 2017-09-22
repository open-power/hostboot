/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/util/utilmclmgr.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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

// Forward declarations
class MasterContainerLidMgrTest;

namespace MCL
{

// Component ID(name) within MCL
typedef std::array<uint8_t,16> ComponentID;

// Defines to simplify syntax when checking for the MCL and POWERVM comp ids
extern const ComponentID g_MclCompId;
extern const ComponentID g_PowervmCompId;

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
    LidInfo(): id(0), size(0) {}
    LidInfo(uint32_t i_id): id(i_id), size(0) {}
    LidInfo(uint32_t i_id, size_t i_size): id(i_id), size(i_size) {}

    uint32_t id;
    size_t size;

    /**
     * @brief  Lid Info equality comparison
     *
     * @param[in]  rhs - LidInfo to compare to
     * @return bool - true if Lid Infos are equal, false otherwise
     */
    bool operator==(const LidInfo& rhs) const
    {
        return (id == rhs.id && size == rhs.size);
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

// Structure for Comp Info cache
typedef std::map<ComponentID, CompInfo> CompInfoMap;

// @brief Class to manager the Master Container Lid provided by the FSP
class MasterContainerLidMgr
{

    public:

    /**
     * @brief Default Constructor
     *        Initializes memory spaces, loads, and parses the MCL.
     */
    MasterContainerLidMgr();

    /**
     * @brief Destructor. Cleans up memory allocated for class
     */
    ~MasterContainerLidMgr();

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

    // Physical addresses reserved for the MCL itself
    uint64_t iv_mclAddr;

    // Maximum size of memory for the MCL itself
    size_t iv_mclSize;

    // Physical addresses reserved for temp MCL mgr space
    uint64_t iv_tmpAddr;

    // Maximum size of memory for temp MCL mgr workspace
    size_t iv_tmpSize;

    // Pointer to MCL virtual address space
    void* iv_pMclVaddr;

    // Pointer to MCL temp virtual address space
    void* iv_pTempVaddr;

    // Cache Components and their corresponding lids
    CompInfoMap iv_compInfoCache;

    // Allow test cases to call custom constructors and have direct access
    friend class ::MasterContainerLidMgrTest;
};

} // end namespace MCL

#endif