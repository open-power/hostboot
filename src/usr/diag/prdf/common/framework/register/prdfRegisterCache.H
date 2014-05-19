/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/prdfRegisterCache.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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

#ifndef REG_CACHE_H
#define REG_CACHE_H

/** @file prdfRegisterCache.H */

#include <map>
#include <iipbits.h>
#include <prdfGlobal.H>
#include <prdfScanFacility.H>
#include <prdfScomRegisterAccess.H>
#include <prdfTargetFwdRef.H>

class BIT_STRING_CLASS;

namespace PRDF
{
/**
 * @brief Caches the contents of registers used during analysis.
 *
 * It maintains the latest content of a register in a map. If contents of the
 * register remain unchanged, register read returns contents stored in
 * cache rather than reading from hardware. Hence it brings efficiency in read.
 * Whenever write to actual hardware takes place, it is expected that once write
 * to hardware succeeds, the user of cache shall call flush. It drops the
 * particular register from map. As a result, when read takes place from same
 * register next time, read from cache fails and actual access to hardware
 * takes place.
 */
class RegDataCache
{
  public:

    /**
     * @brief Constructor
     */
    RegDataCache()
    { }

    /**
     * @brief Destructor
     */
    ~RegDataCache();

    /**
     * @brief  Returns reference to singleton instance of the RegDataCache.
     * @return The singleton reference.
     */
     static RegDataCache & getCachedRegisters();

    /**
     * @brief Returns the data buffer for the given target and address.
     * @param i_chip The target associated with the register.
     * @param i_reg  Pointer to register to be read.
     * @return A reference to the data buffer associated with the register.
     */
    BIT_STRING_CLASS & read( ExtensibleChip * i_chip,
                             const SCAN_COMM_REGISTER_CLASS * i_reg );

    /**
     * @brief Flushes entire contents from cache.
     */
    void flush();

    /**
     * @brief Removes a single entry from the cache.
     * @param i_pChip       The rulechip  associated with the register.
     * @param i_pRegister   points to the register to be flushed from cache.
     */
    void flush( ExtensibleChip* i_pChip,
                const SCAN_COMM_REGISTER_CLASS * i_pRegister );
    /**
     * @brief Queries if a specific entry exist in cache.
     * @param i_pChip       The rulechip  associated with the register.
     * @param i_pRegister   base part of register entry to be queried in cache.
     * @return pointer to cache entry associated with a given register
     */
     BIT_STRING_CLASS * queryCache( ExtensibleChip* i_pChip,
                            const SCAN_COMM_REGISTER_CLASS * i_pRegister )const;
    /**
     * @brief Queries if a specific entry exist in cache.
     * @param i_scomAccessKey Reference to register to be queried.
     * @return pointer to cache entry associated with a given register
     */

    BIT_STRING_CLASS * queryCache(
                        const ScomRegisterAccess & i_scomAccessKey )const;
  private: // data

    typedef std::map<ScomRegisterAccess, BIT_STRING_CLASS *> CacheDump;
    CacheDump iv_cachedRead;

};

PRDF_DECLARE_SINGLETON(RegDataCache, ReadCache);

} // namespace PRDF

#endif // REG_CACHE_H

