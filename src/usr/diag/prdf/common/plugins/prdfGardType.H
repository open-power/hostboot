/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plugins/prdfGardType.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2001,2014              */
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

#ifndef prdfGardType_H
#define prdfGardType_H

namespace PRDF
{
#ifdef PRDF_HOSTBOOT_ERRL_PLUGIN
namespace HOSTBOOT
{
#endif

#ifdef PRDF_FSP_ERRL_PLUGIN
namespace FSP
{
#endif

namespace GardAction
{
  enum ErrorType
  {
    // No Gard is possible
    NoGard        = 0,
    // Recovered error at threshold
    Predictive    = 1,
    // Checkstop, failing resources can be removed to prevent future occurances
    Fatal         = 2,
    // This is NoGard unless attn type is CheckStop, then it is Fatal (Func)
    CheckStopOnlyGard = 3,
    //This is to allow Deferred Deconfig, with No Garding
    DeconfigNoGard = 4
  };

  inline const char* ToString( uint32_t i_type )
  {
      switch (i_type)
      {
          case NoGard:              return "NoGard";
          case Predictive:          return "Predictive";
          case Fatal:               return "Fatal";
          case CheckStopOnlyGard:   return "CheckStopOnlyGard";
          case DeconfigNoGard:      return "DeconfigNoGard";
          default:                  return "Undefined";
      }
  }

} // end namespace GardAction

#ifdef PRDF_HOSTBOOT_ERRL_PLUGIN
} // end namespace HOSTBOOT
#endif

#ifdef PRDF_FSP_ERRL_PLUGIN
} // end namespace FSP
#endif
} // end namespace PRDF

#endif /* prdfGardType_H */

