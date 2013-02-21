/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: prdfRegisterCache.H $                                         */
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

#ifndef REG_CACHE_H
#define REG_CACHE_H

/** @file prdfRegisterCache.H */

#include <map>
#include <targeting/common/target.H>
#include <iipbits.h>
#include <prdfGlobal.H>
#include <prdfScanFacility.H>
#include <prdfScomRegisterAccess.H>

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
     * @param i_pChip       The target associated with the register.
     * @param i_pRegister   pointer to register to be read.
     * @param o_readStat    Returns true if the register does not exist in
     *                      cache. In this case, the function will create and
     *                      add an empty BIT_STRING_CLASS to the cache.It is
     *                      the responsibilty of the user to update the data
     *                      buffer by reading from hardware.
     * @return A reference to the data buffer associated with the register.
     */
     BIT_STRING_CLASS & read( ExtensibleChip* i_pChip,
                              const SCAN_COMM_REGISTER_CLASS * i_pRegister,
                              bool & o_readStat );

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
  private: // data

    typedef std::map<ScomRegisterAccess, BIT_STRING_CLASS *> CacheDump;
    CacheDump iv_cachedRead;

};

PRDF_DECLARE_SINGLETON(RegDataCache, ReadCache);

} // namespace PRDF

#endif // REG_CACHE_H

