/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/rule/prdfPluginMap.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2005,2014              */
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

#ifndef __PRDFPLUGINMAP_H
#define __PRDFPLUGINMAP_H

#include <map>
#include <prdfPluginDef.H>
#include <string.h>
#include <functional>

namespace PRDF
{

class ExtensibleChip;

/**
  * @brief custom comparison functor to pass to a map container
  *        that uses char* as the key
  */
struct StrCompare : public std::binary_function<const char*, const char*, bool>
{
    public:
      bool operator() (const char* str1, const char* str2) const
      {
          return strcmp(str1, str2) < 0;
      }
};

typedef std::map<const char *, ExtensibleFunctionType *, StrCompare> PluginMap;

class PluginGlobalMap;
PluginGlobalMap & getPluginGlobalMap();

class PluginGlobalMap
{
    private:
        std::map<const char *, PluginMap, StrCompare> cv_globalMap;

    public:
        PluginGlobalMap() : cv_globalMap() {};

        void registerPlugin(const char *   i_chipName,
                            const char *   i_pluginName,
                            ExtensibleFunctionType * i_plugin);

        PluginMap & getPlugins(const char * i_chipName);
};

class PluginRegisterClass
{
    public:
        PluginRegisterClass(const char * i_chipName,
                                const char * i_pluginName,
                                ExtensibleFunctionType * i_plugin);
};

} // end namespace PRDF

#endif
