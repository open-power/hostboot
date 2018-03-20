/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/scom/centaurScomCache.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2018                        */
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

#ifndef __CENTAURSCOMCACHE_H
#define __CENTAURSCOMCACHE_H

/**
 *  @file src/include/usr/scom/centaurScomCache.H
 *
 *  @brief Interface for the Secure Boot Centaur SCOM cache
 */

//******************************************************************************
// Includes
//******************************************************************************

#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>

extern trace_desc_t* g_trac_scom;

// These defines allow standard logging of error information in traces
#define TRACE_ERR_FMT "Error info: PLID=0x%08X, EID=0x%08X, Reason=0x%04X. "
#define TRACE_ERR_ARGS(pError) \
    ERRL_GETPLID_SAFE(pError), ERRL_GETEID_SAFE(pError), ERRL_GETRC_SAFE(pError)

namespace SECUREBOOT
{

namespace CENTAUR_SECURITY
{

/**
 *  @brief Structure which provides Centaur SCOM cache register definitions
 */
struct ScomRegDef
{
    // Address of the SCOM register
    // Must not be 0
    uint64_t addr;

    // NOTE: only one of isWandReg or isWorReg can be set in a given record at a
    // time

    // Indicates whether a write to this register bitwise ANDs the requested
    // write value into a different base register. 0b1=yes, 0b0=no
    uint8_t isWandReg : 1;

    // Indicates whether a write to this register bitwise ORs the requested
    // write value into a different base register. 0b1=yes, 0b0=no
    uint8_t isWorReg  : 1;

    // If isWandReg or isWorReg is 0b1, indicates the base register to perform
    // the WAND or WOR operation on (which must not be 0).
    // N/A (set to 0) otherwise
    uint64_t baseAddr;

    // If isWandReg or isWorReg is 0b1, indicates a different index into the
    // register definition vector where the base address register is located.
    // Otherwise, indicates this record's position in the register definition
    // vector.  This index allows base register record and per-Centaur register
    // lookup with O(1) algorithmic complexity.
    // Must be -1 prior to init, 0..size-1 afterwards
    ssize_t baseIndex;

    // The expected hardware initialization value
    // Default = 0
    // N/A (set to 0) if isWandReg or isWorReg bit set to 0b1
    uint64_t expectedHwInitValue;

    // A mask indicating which bits of the register to consider when
    // comparing values read from hardware vs. the cache.  If a bit
    // is set, the bits at the same position should be compared.
    // Default = all bits 0b1 = compare whole register.
    // Must not be 0 when neither isWandReg nor isWorReg bit is set.
    // N/A (set to 0) if isWandReg or isWorReg bit set to 0b1
    uint64_t mask;

    /**
     *  @brief Returns whether this register has an associated base register
     *
     *  @retval bool Boolean indicating whether register has an associated base
     *      register that gets changed on write operations
     *  @return true Register has a base register
     *  @return false Register does not have a base register
     */
    bool hasBaseAddr() const
    {
        return (isWandReg || isWorReg);
    }

    /**
     *  @brief Enum giving defaults for various record fields
     */
    enum DEFAULTS
    {
        DEFAULT_IS_WAND_REG=0b0, ///< Not a WAND register
        DEFAULT_IS_WOR_REG=0b0, ///< Not a WOR register
        DEFAULT_BASE_ADDR=0x0ULL, ///< No associated base register
        DEFAULT_BASE_INDEX=-1, ///< Lookup index not populated
        DEFAULT_EXPECTED_HW_INIT_VALUE=0x0ULL, ///< Expected HW init value of 0
        DEFAULT_MASK=0xFFFFFFFFFFFFFFFFULL, ///< Compare whole registers
    };

    /**
     *  @brief Constructor to build a SCOM register definition record
     *
     *  @param[in] i_addr Register address
     *  @param[in] i_isWandReg Whether register has a base register it bitwise
     *      ANDs into
     *  @param[in] i_isWorReg Whether register has a base register it bitwise
     *      ANDs into
     *  @param[in] i_baseAddr If isWandReg or isWorReg set, the associated base
     *      register
     *  @param[in] i_baseIndex If isWandReg or isWorReg set, the index of the
     *      associated base register in the SCOM register definition vector.
     *      Otherwise, the index of this record in the SCOM register definition
     *      vector.  If DEFAULT_BASE_INDEX, the value must be changed before
     *      caching is enabled.
     *  @param[in] i_expectedHwInitValue The expected hardware initialization
     *      value for the register
     *  @param[in] i_mask A mask indicating which bits to analyze when a
     *      register's cache value is compared to the value read from hardware.
     *
     *  @note: See ScomRegDef field documentation above for additional
     *      restrictions.
     */
    ScomRegDef(
        uint64_t i_addr,
        int      i_isWandReg=DEFAULT_IS_WAND_REG,
        int      i_isWorReg=DEFAULT_IS_WOR_REG,
        uint64_t i_baseAddr=DEFAULT_BASE_ADDR,
        ssize_t  i_baseIndex=DEFAULT_BASE_INDEX,
        uint64_t i_expectedHwInitValue=DEFAULT_EXPECTED_HW_INIT_VALUE,
        uint64_t i_mask=DEFAULT_MASK)
    : addr(i_addr),
      isWandReg(i_isWandReg),
      isWorReg(i_isWorReg),
      baseAddr(i_baseAddr),
      baseIndex(i_baseIndex),
      expectedHwInitValue(i_expectedHwInitValue),
      mask(i_mask)
    {
    }
};

// Alias for the SCOM register definition vector type
typedef std::vector<ScomRegDef> ScomRegDefs;

/**
 *  @brief Class which coordinates tracking read and write access to any Centaur
 *      SCOM register deemed to be security sensitive
 */
class ScomCache
{
  public:

    /**
     *  @brief Initializes all Centaurs' SCOM register cache
     *
     *  @par Detailed Description:
     *      Builds a SCOM register cache seeded with expected hardware
     *      initialization values for each security sensitive register, and
     *      clones it to every Centaur
     */
    void init() const;

    /**
     *  @brief Globally enables caching of read/write SCOM requests for every
     *      functional Centaur
     */
    void enableCache();

    /**
     *  @brief Globally disables caching of read/write SCOM requests for every
     *      functional Centaur
     */
    void disableCache();

    /**
     *  @brief Returns whether Centaur SCOM register caching is enabled for
     *      all functional Centaurs
     *
     *  @retval boolean Indicating whether Centaur SCOM register cache is
     *      enabled for all functional Centuars or not
     */
    bool cacheEnabled() const;

    /**
     *  @brief Delete all Centaurs' SCOM register cache
     */
    void destroy() const;

    /**
     *  @brief If caching enabled and register is sensitive, writes the
     *      requested value to the given Membuf's cache
     *
     *  @param[in] i_Membuf Membuf target to write.  If the request happens
     *      -not- to be a Centaur or caching is disabled, it's a no-op.  Returns
     *      error if target is nullptr.
     *  @param[in] i_addr Register address
     *  @param[in] i_value Register value
     *
     *  @return errlHndl_t Error log handle
     *  @retval nullptr Operation was successful
     *  @retval !nullptr Operation failed with valid error log
     */
    errlHndl_t write(
        TARGETING::Target* i_pMembuf,
        uint64_t           i_addr,
        uint64_t           i_value) const;

    /**
     *  @brief If caching enabled and register is sensitive, reads the
     *      requested register from the given Membuf's cache.  If the
     *      register was returned, the call indicates a cache hit, else a miss
     *
     *  @param[in] i_pMembuf Membuf target to read.  If the request happens
     *      -not- to be a Centaur, or caching is disabled, it's a no-op.
     *      Returns error if target is nullptr.
     *  @param[in] i_addr SCOM register address to read
     *  @param[out] o_cacheHit Whether the cache held the requested register
     *      value
     *  @param[out] o_value Register value that was read; only valid if
     *      o_cacheHit is true
     *
     *  @return errlHndl_t Error log handle
     *  @retval nullptr Operation was successful
     *  @retval !nullptr Operation failed with valid error log; all outputs
     *      invalid
     */
    errlHndl_t read(
        TARGETING::Target* i_pMembuf,
        uint64_t           i_addr,
        bool&              o_cacheHit,
        uint64_t&          o_value) const;

    /**
     *  @brief Verifies, node-wide, that every security sensitive Centaur SCOM
     *      register's cached value matches (as directed by the compare mask)
     *      the value actually read from the hardware.
     *
     *  @return errlHndl_t Error log handle
     *  @retval nullptr Operation was successful
     *  @retval !nullptr Operation failed with valid error log
     */
    errlHndl_t verify() const;

    /**
     *  @brief Dumps, node-wide, the cached values of every security sensitive
     *      Centaur SCOM register to the trace
     */
    void dump() const;

    /**
     *  @brief Returns the Centaur SCOM cache singleton
     *
     *  @retval ScomCache& Reference to the Centaur SCOM cache singleton
     */
    static ScomCache& getInstance();

    /**
     * Delete Copy Constructor
     */
    ScomCache(const ScomCache&) = delete;

    /**
     * Delete Copy Assignment
     */
    ScomCache& operator= (const ScomCache&) = delete;

    /**
     * Delete Move Constructor
     */
    ScomCache (ScomCache&&) = delete;

    /**
     * Delete Move Assignment
     */
    ScomCache& operator = (ScomCache&&) = delete;

  protected:

    /**
     *  @brief Centaur SCOM cache constructor
     */
    ScomCache();

    /**
     *  @brief Centaur SCOM cache destructor
     */
    ~ScomCache();

  private: // APIs

    /**
     *  @brief Helper function to retrieve a Centaur's SCOM cache
     *
     *  @param[in] i_pCentaur Centaur target.  Must not be nullptr and must be a
     *      Centaur, but this is not strictly enforced.
     *  @retval std::vector<uint64_t>* Pointer to the SCOM cache
     */
    std::vector<uint64_t>* _getCachePtr(
        TARGETING::Target* i_pCentaur) const
    {
        return reinterpret_cast<std::vector<uint64_t>*>(
            i_pCentaur->getAttr<TARGETING::ATTR_CENTAUR_REGISTER_CACHE_PTR>());
    }

    /**
     *  @brief Helper function to store a Centaur's SCOM cache
     *
     *  @param[in] i_pCentaur Centaur target.  Must not be nullptr and must be a
     *      Centaur, but this is not strictly enforced.
     *  @param[in] i_pCache Pointer to the SCOM cache
     */
    void _setCachePtr(
              TARGETING::Target*     i_pCentaur,
        const std::vector<uint64_t>* i_pCache) const
    {
        i_pCentaur->setAttr<TARGETING::ATTR_CENTAUR_REGISTER_CACHE_PTR>(
            reinterpret_cast<uint64_t>(
                const_cast<std::vector<uint64_t>*>(i_pCache)));
    }

    /**
     *  @brief Generated function to initialize the SCOM register definitions
     *
     *  @return ScomRegDefs* Pointer to the SCOM register definitions.  Memory
     *    transfer occurs and caller responsible for deleting the vector later.
     *
     *  @note: Generated source @ obj/genfiles/centaurScomCacheRegDefs.C
     */
    ScomRegDefs* _initScomRegDefs() const;

    /**
     *  @brief Checks for duplicate SCOM register definition records (any with
     *      duplicate addresses) and asserts if that condition is found
     */
    void _enforceScomRegDefUniqueness() const;

    /**
     *  @brief Ensures the SCOM register definition records are formatted
     *      properly.  Asserts on any violation.
     */
    void _validateScomRegDefs() const;

    /**
     *  @brief Performs a performance fixup that allows register lookup for an
     *      individual Centaur that runs in O(log n) algoritmic complexity
     */
    void _optimizeScomRegDefs();

  private: // Instance vars

    ///< Pointer to vector of SCOM register definitions
    ScomRegDefs* iv_pScomRegDefs;

    ///< Whether the node-wide Centaur SCOM cache is active
    bool iv_cacheEnabled;
};

} // end CENTAUR_SECURITY namespace

} // end SECUREBOOT namespace

#endif

