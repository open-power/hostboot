/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/rule/prdrLoadChipCache.H $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
             * @note Caller must check o_chip for nullptr pointers, indicating that
             * the chip file could not be found / loaded.
             *
             * @retuns errlHndl_t - In the event of a registry or file failure.
             */
            static errlHndl_t loadChip(const char * i_file, Chip ** o_chip);

        private:
            /** The file cache. */
            typedef std::map<const char *, Chip *, PRDF::StrCompare> Cache_t;
            static Cache_t cv_cache;
    };

} // end namespace Prdr
