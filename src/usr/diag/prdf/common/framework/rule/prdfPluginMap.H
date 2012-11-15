/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/rule/prdfPluginMap.H $     */
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

#ifndef __PRDFPLUGINMAP_H
#define __PRDFPLUGINMAP_H

#include <map>
#include <prdfPluginDef.H>
#include <string.h>
#include <functional>

class PrdfExtensibleChip;

/**
  * @brief custom comparison functor to pass to a map container
  *        that uses char* as the key
  */
struct PrdfStrCompare : public std::binary_function<const char*, const char*, bool>
{
    public:
      bool operator() (const char* str1, const char* str2) const
      {
          return strcmp(str1, str2) < 0;
      }
};

typedef std::map<const char *, PrdfExtensibleFunctionType *, PrdfStrCompare> PrdfPluginMap;

class PrdfPluginGlobalMap;
PrdfPluginGlobalMap & prdfGetPluginGlobalMap();

class PrdfPluginGlobalMap
{
    private:
        std::map<const char *, PrdfPluginMap, PrdfStrCompare> cv_globalMap;

    public:
        PrdfPluginGlobalMap() : cv_globalMap() {};

        void registerPlugin(const char *   i_chipName,
                            const char *   i_pluginName,
                            PrdfExtensibleFunctionType * i_plugin);

        PrdfPluginMap & getPlugins(const char * i_chipName);
};

class PrdfPluginRegisterClass
{
    public:
        PrdfPluginRegisterClass(const char * i_chipName,
                                const char * i_pluginName,
                                PrdfExtensibleFunctionType * i_plugin);
};

#endif
