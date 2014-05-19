/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/rule/prdrLoadChipCache.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2006,2014              */
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

#ifdef __HOSTBOOT_MODULE

                char* l_filePathName;
                size_t l_filePathSize = strlen(i_file) + 4 + 1; // 4 is for ".prf"
                l_filePathName = new char[l_filePathSize];
                strcpy(l_filePathName, i_file);
                strncat(l_filePathName, ".prf", l_filePathSize-1);

                UtilFile l_ruleFile(l_filePathName);
                if (!l_ruleFile.exists())
                {
                    // FIXME: do we need to log and commit an error here?
                    PRDF_ERR("LoadChipCache::loadChip() failed to find %s", l_filePathName);
                }
                else
                {
                    l_ruleFile.Open("r");
                }

                delete[] l_filePathName;

#else

                 // Read the correct directory path for flash.
                size_t l_rootPathSize = 256;
                char l_rootPath[256] = { '\0' };
                l_errl = UtilReg::read("fstp/RO_Root",
                                       (void *) l_rootPath,
                                       l_rootPathSize);
                strncat(l_rootPath, "prdf/", 255);
                strncat(l_rootPath, i_file, 255);
                strncat(l_rootPath, ".prf", 255);

                if (NULL != l_errl) break;

                // Read /maint/data/... directory path
                // for any prf file patch
                char l_patchPath[256] = { '\0' };
                strcpy(l_patchPath, "/maint/data/prdf/");
                strncat(l_patchPath, i_file, 255);
                strncat(l_patchPath, ".prf", 255);

                if (NULL != l_errl) break;

                // Open File to read chip.
                UtilFile l_ruleFile(l_patchPath);
                if (!l_ruleFile.exists())        // check for patch file.
                {
                    l_ruleFile.Open(l_rootPath, "r");
                }
                else
                {
                    l_ruleFile.Open("r");
                }

#endif
                // Load chip object.
                l_errl = LoadChip(l_ruleFile, *(*o_chip));

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
