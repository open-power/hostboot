/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/rule/prdrLoadChipCache.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
            if (NULL != i->second)
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
        errlHndl_t l_errl = NULL;
        *o_chip = NULL;

        Cache_t::iterator i = cv_cache.find(i_file);

        if (cv_cache.end() != i) // Found object in cache.
        {
            (*o_chip) = (Chip*)(*i).second;
            l_errl = NULL;
        }
        else
        {
            (*o_chip) = new Chip();

            do
            {
                // NOTE: to patch PRF files require rebuilding
                // entire Hostboot image and put in a special
                // location on FSP /maint/ mount.
                // FIXME: if we need to patch prf files directly
                // on Hostboot, need to discuss with Patrick
                // about a possibility of creating a new PNOR
                // partition outside of the cryptographically
                // signed area just for PRD.

                const char * ext = ".prf";

                const size_t sz_file     = strlen( i_file );
                const size_t sz_ext      = strlen( ext );
                const size_t sz_filePath = sz_file + sz_ext;

                char filePath[sz_filePath + 1];
                memset( filePath, '\0', sizeof(filePath) );

                strncpy( filePath, i_file, sz_file );
                strncat( filePath, ext,    sz_ext  );

                #ifdef __HOSTBOOT_MODULE
                // TODO: RTC 119022 remove after UtilFile is supported in HBRT
                #ifndef __HOSTBOOT_RUNTIME

                UtilFile l_ruleFile( filePath );
                if ( !l_ruleFile.exists() )
                {
                    PRDF_ERR( "LoadChipCache::loadChip() failed to find %s",
                              filePath );
                }
                else
                {
                    l_ruleFile.Open("r");
                }

                #endif
                #else // not __HOSTBOOT_MODULE

                // Read the correct directory path for flash.
                const char * prdPath = "prdf/";
                const size_t sz_prdPath = strlen( prdPath );

                size_t sz_rootPath = 256;
                char rootPath[ sz_rootPath + sz_prdPath + sz_filePath + 1 ];
                memset( rootPath, '\0', sizeof(rootPath) );

                l_errl = UtilReg::read( "fstp/RO_Root", (void *)rootPath,
                                        sz_rootPath );
                if ( NULL != l_errl ) break;

                strncat( rootPath, prdPath,  sz_prdPath  );
                strncat( rootPath, filePath, sz_filePath );

                // Read /maint/data/... directory path for any prf file patch.
                const char * maintPath = "/maint/data/prdf/";
                const size_t sz_maintPath = strlen( maintPath );

                char patchPath[ sz_maintPath + sz_filePath + 1 ];
                memset( patchPath, '\0', sizeof(patchPath) );

                strncpy( patchPath, maintPath, sz_maintPath );
                strncat( patchPath, filePath,  sz_filePath );

                // Open File to read chip.
                UtilFile l_ruleFile( patchPath );
                if ( !l_ruleFile.exists() ) // check for patch file.
                {
                    l_ruleFile.Open(rootPath, "r");
                }
                else
                {
                    l_ruleFile.Open("r");
                }

                #endif // end __HOSTBOOT_MODULE

                // TODO: RTC 119022 remove after UtilFile is supported in HBRT
                #ifndef __HOSTBOOT_RUNTIME
                // Load chip object.
                l_errl = LoadChip(l_ruleFile, *(*o_chip));
                #endif

            } while (0);

            if (NULL == l_errl)
            {
                // Add chip object to the cache.
                cv_cache[i_file] = *o_chip;
            }
            else
            {
                PRDF_ERR("LoadChipCache::loadChip() l_errl is not null!");
                delete *o_chip;
                (*o_chip) = NULL;
            }

        }

        return l_errl;

    };
    //---------------------------------------------------------------------

} // end namespace Prdr
