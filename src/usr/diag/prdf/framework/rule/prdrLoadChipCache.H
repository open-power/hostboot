/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/framework/rule/prdrLoadChipCache.H $        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2006,2012              */
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

/**
 * @file prdrLoadChipCache.H
 * @brief Contains class information for a rule-chip loader cache.
 */

#include <errlentry.H>
#include <prdrLoadChip.H>
#include <map>
#include <prdfPluginMap.H>

namespace Prdr
{
    /**
     * @class LoadChipCache
     * @brief Creates a cache of the .prf rule-chips so the files only need to
     * be parsed a single time.
     */
    class LoadChipCache
    {
        public:
            /**
             * @fn flushCache
             * @brief Clears any objects within the cache and frees all memory
             * associated with them.
             *
             * @note After this call any pointers obtained from 'loadChip' are
             * invalid.
             */
            static void flushCache();

            /**
             * @fn loadChip
             * @brief Loads a .prf file specified and returns a pointer to an
             * associated chip object.
             *
             * This function will first look in NFS and then in flash for an
             * associated chip file, assuming the object was not already in
             * the cache.
             *
             * Any pointer returned should not be deleted.  Its memory will be
             * freed after the call to 'flushCache'.
             *
             * @param i_file - File name to open, eg. "SomeIoChip.prf".
             * @param o_chip - Pointer to the object loaded from the file or
             *                        retrieved from the cache.
             *
             * @note Caller must check o_chip for NULL pointers, indicating that
             * the chip file could not be found / loaded.
             *
             * @retuns errlHndl_t - In the event of a registry or file failure.
             */
            static errlHndl_t loadChip(const char * i_file, PrdrChip ** o_chip);

        private:
            /** The file cache. */
            typedef std::map<const char *, PrdrChip *, PrdfStrCompare> Cache_t;
            static Cache_t cv_cache;
    };
};
