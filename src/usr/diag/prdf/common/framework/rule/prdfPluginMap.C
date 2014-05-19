/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/rule/prdfPluginMap.C $     */
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

#include <prdfPluginMap.H>

namespace PRDF
{

PluginGlobalMap & getPluginGlobalMap()
{
    static PluginGlobalMap g_globalPluginMap;
    return g_globalPluginMap;
};

void PluginGlobalMap::registerPlugin(const char *   i_chipName,
                                         const char *   i_pluginName,
                                         ExtensibleFunctionType * i_plugin)
{
    this->cv_globalMap[i_chipName][i_pluginName] = i_plugin;
};

PluginMap & PluginGlobalMap::getPlugins(const char * i_chipName)
{
    return this->cv_globalMap[i_chipName];
};

PluginRegisterClass::PluginRegisterClass(
                                const char * i_chipName,
                                const char * i_pluginName,
                                ExtensibleFunctionType * i_plugin)
{
    getPluginGlobalMap().registerPlugin(i_chipName,
                                            i_pluginName,
                                            i_plugin);
};

} // end namespace PRDF

