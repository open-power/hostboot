/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/iipCallout.h $  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1996,2013              */
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

#ifndef iipCallout_h
#define iipCallout_h

// Special maintenance notes: *****************************************
//
// This file must maintain the basic format decribed below.  All
// maintenance must preserve that format to ensure the proper function
// of all code that uses this file.
//
// PRD_NULL_MRU must be the first mru in the MruCallout enum and it
// must have a value of zero.  The value "PRD_NULL_MRU" shall be by
// definition a valid MRU value that means "No specific MRU".  Mapping
// code will verify that all MRU values are greater than this value to
// acceptable for translation.
//
// The MruCallout enum must have the name "PRD_MAXMRUNUM" as the last
// mru in the list.  This will then automatically supply the number of
// mrus in the enum to code that must check that.
//
// The MruCallout enum must default to compiler supplied values for each
// mru.  This is how "PRD_NULL_MRU" and "PRD_MAXMRUNUM" will always be
// correct and it precludes any dependencies on other code modules
// requiring a specific value.
//
// PRD_NULL_FRU must be the first fru in the FruValues enum and it
// must have a value of zero.
//
// PRD_NULL_REFCODE must be the first refcode in the RefcodeValues enum
// and it must have a value of zero.
//
// NOTE!!!!!!!
// The Version, Release, Modification and Level values set in this file
// MUST be updated each time a change is made to this file that would
// cause the renumbering of the MRU callout values in the ENUM.
//
// End of Special maintenance notes. *********************************

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Constants
//--------------------------------------------------------------------

#ifdef RS6000
#ifndef SERVGENSIMCONTROLS_H
#include <ServGenSimControls.h>
#endif
#endif

#ifdef __CPLUSPLUS
const PRD_CALLOUT_VERSION = 4;
#else
#define PRD_CALLOUT_VERSION 4
#endif

#ifdef __CPLUSPLUS
const PRD_CALLOUT_RELEASE = 3;
#else
#define PRD_CALLOUT_RELEASE 3
#endif

#ifdef __CPLUSPLUS
const PRD_CALLOUT_MODIFICATION = 0;
#else
#define PRD_CALLOUT_MODIFICATION  0
#endif

#ifdef __CPLUSPLUS
const PRD_CALLOUT_LEVEL = 4;
#else
#define PRD_CALLOUT_LEVEL 4
#endif


#ifdef __CPLUSPLUS
const PRD_REFDIM = 5;
#else
#define PRD_REFDIM 5
#endif
                                 /* This is the number of refcodes and*/
                                 /* FRUs that a MRU list can be       */
                                 /* translated into.                  */

#ifdef __CPLUSPLUS
const PRD_MRU_LIST_LIMIT = 24;
#else
#define PRD_MRU_LIST_LIMIT 24
#endif
                                 /* This is the maximum number of MRUs*/
                                 /* that will be allowed to be called */
                                 /* out for mapping.                  */

#ifdef __CPLUSPLUS
const PRD_FRU_AND_RC_LIMIT = 12;
#else
#define PRD_FRU_AND_RC_LIMIT 12
#endif
                                 /* this is the maximum number of FRUs*/
                                 /* and refcodes that will be allowed */
                                 /* in the mapping results.           */


/*--------------------------------------------------------------------*/
/*  User Types                                                        */
/*--------------------------------------------------------------------*/

//#define MruCalloutDCL UINT16     /* How big a mru is in bits.         */

namespace PRDF
{

typedef enum {

  PRD_NULL_MRU,        /* Do NOT use this.  This is an   */
                       /* MRU used to mark the low end   */
                       /* of the valid MRU number ranges.*/




/*********************************************************/
/* Last, the reserved, default value of this             */
/* "NO_MRU" reserved mru name.                           */
/* Use this only if there is no Callout and No service   */
/* action and the SRC will not get displayed.  This MRU  */
/* will be mapped to the ServiceProcessor code refcode   */
/* so that if the SRC from this MRU ever ends up in the  */
/* panel or a log SP code will be called.                */
/* This MRU is used for attentions that do not require   */
/* service actions, such as "scrub complete".            */

  NO_MRU,

/************************************************************/
/* This is the reserved and Last mru and must remain that   */
/* way for proper code function.                            */
  LAST_MRU,
  PRD_MAXMRUNUM = 0x7FFFFFFF}   MruCallout;

} // end namespace PRDF

#endif /* iipCallout_h */

