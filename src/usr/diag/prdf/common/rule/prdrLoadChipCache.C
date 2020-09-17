/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/rule/prdrLoadChipCache.C $           */
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

#ifndef __HOSTBOOT_MODULE

#include <utilreg.H> // for UtilReg

#endif


#include <string.h>                // for strncat
#include <prdrLoadChipCache.H>
#include <utilfile.H>
#include <prdfTrace.H>

namespace Prdr
{
    // Declare private member instance.
    LoadChipCache::Cache_t LoadChipCache::cv_cache;

    //---------------------------------------------------------------------
    void LoadChipCache::flushCache()
    {
        // Delete all objects within the cache.
        for (Cache_t::iterator i = cv_cache.begin();
             i != cv_cache.end();
             ++i)
        {
            if (nullptr != i->second)
                delete (Chip*)i->second;
        }

        // Clear map.
        cv_cache.clear();
    };
    //---------------------------------------------------------------------

    //---------------------------------------------------------------------
    errlHndl_t LoadChipCache::loadChip(const char * i_file,
                                       Chip ** o_chip)
    {
        errlHndl_t l_errl = nullptr;
        *o_chip = nullptr;

        Cache_t::iterator i = cv_cache.find(i_file);

        if (cv_cache.end() != i) // Found object in cache.
        {
            (*o_chip) = (Chip*)(*i).second;
            l_errl = nullptr;
        }
        else
        {
            (*o_chip) = new Chip();

            do
            {
                // NOTE: to patch PRF files require rebuilding
                // entire Hostboot image and put in a special
                // location on FSP /nfs/test/pnor/ mount.

                // Add the extention to the file name.
                const char * ext = ".prf";

                char fileName[ strlen(i_file) + strlen(ext) + 1 ];

                strcpy( fileName, i_file );
                strcat( fileName, ext    );

                #ifdef __HOSTBOOT_MODULE

                // Open file to read chip.
                UtilFile l_ruleFile( fileName );
                if ( !l_ruleFile.exists() )
                {
                    PRDF_ERR( "LoadChipCache::loadChip() failed to find %s",
                              fileName );
                }
                else
                {
                    l_ruleFile.Open("r");
                }

                #else // not __HOSTBOOT_MODULE

                // Get the length of the root path from the registry. Note that
                // passing nullptr will simply return the size of the entry.
                size_t sz_rootPath = 0;
                l_errl = UtilReg::read( "fstp/RO_Root", nullptr, sz_rootPath );
                if ( nullptr != l_errl ) break;

                // Allocate space for the root path.
                char rootPath[ sz_rootPath + 1 ]; // add null char just in case
                memset( rootPath, '\0', sizeof(rootPath) );

                // Get the root path from the registry (no truncation).
                l_errl = UtilReg::read( "fstp/RO_Root", (void *)rootPath,
                                        sz_rootPath, false );
                if ( nullptr != l_errl ) break;

                // Now, build the full file path.
                const char * prdPath = "prdf/";

                char filePath[ strlen(rootPath) + strlen(prdPath) +
                               strlen(fileName) + 1 ];

                strcpy( filePath, rootPath );
                strcat( filePath, prdPath  );
                strcat( filePath, fileName );

                // A patched version of the file may exist, so check that first.
                const char * maintPath = "/maint/data/prdf/";

                char patchPath[ strlen(maintPath) + strlen(fileName) + 1 ];

                strcpy( patchPath, maintPath );
                strcat( patchPath, fileName  );

                // Open file to read chip.
                UtilFile l_ruleFile( patchPath );
                if ( !l_ruleFile.exists() ) // check for patch file.
                {
                    l_ruleFile.Open(filePath, "r");
                }
                else
                {
                    l_ruleFile.Open("r");
                }

                #endif // end __HOSTBOOT_MODULE

                // Load chip object.
                l_errl = LoadChip(l_ruleFile, *(*o_chip));

            } while (0);

            if (nullptr == l_errl)
            {
                // Add chip object to the cache.
                cv_cache[i_file] = *o_chip;
            }
            else
            {
                PRDF_ERR("LoadChipCache::loadChip() l_errl is not null!");
                delete *o_chip;
                (*o_chip) = nullptr;
            }

        }

        return l_errl;

    };
    //---------------------------------------------------------------------

} // end namespace Prdr
