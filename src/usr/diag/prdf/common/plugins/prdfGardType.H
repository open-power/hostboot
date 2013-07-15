/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plugins/prdfGardType.H $             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2001,2013              */
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

#ifndef prdfGardType_H
#define prdfGardType_H

namespace PRDF
{
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

} // end namespace PRDF

#endif /* prdfGardType_H */

