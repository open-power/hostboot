/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/rule/prdfPluginMap.C $     */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2005,2012              */
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

