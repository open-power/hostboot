/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/service/iipstep.h $        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1996,2012              */
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

#ifndef IIPSTEP_H
#define IIPSTEP_H

/*!
 Processor Runtime Diagnostics Step Code class declaration
 @file iipstep.h
*/

/* Change Log *********************************************************/
/*                                                                    */
/*  Flag Reason   Vers Date     Coder Description                     */
/*  ---- -------- ---- -------- ----- ------------------------------- */
/*                V300 07/16/93 JST   Initial Creation                */
/*                V300 12/20/93 JST   Modifying Step Code Data        */
/*                V300 02/15/94 JST   Removed Step Code Class         */
/*                V300 03/11/94 JST   Modified Step Code Data         */
/*       d24737.? V4R1 10/25/95 DRG   Added ServiceDataCollector      */
/*       357551  fips1 02/01/02 dgilbert FSP - removed ERROR_OBJECT   */
/*                                                                    */
/* End Change Log *****************************************************/

/*--------------------------------------------------------------------*/
/* Reference the virtual function tables and inline function
   defintions in another translation unit.                            */
/*--------------------------------------------------------------------*/
#ifdef __GNUC__
#endif
/*--------------------------------------------------------------------*/
/*  Includes                                                          */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*  Forward References                                                */
/*--------------------------------------------------------------------*/

//class ERROR_OBJECT_CLASS;

namespace PRDF
{

class ServiceDataCollector;

/*--------------------------------------------------------------------*/
/*  User Types                                                        */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*  Constants                                                         */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*  Macros                                                            */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*  Global Variables                                                  */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*  Function Prototypes                                               */
/*--------------------------------------------------------------------*/

/* Structure Specification ********************************************/
/*                                                                    */
/*  Title:  Step Code Data                                            */
/*                                                                    */
/*  Purpose:  STEP_CODE_DATA_STRUCT represents the static information
              required for a unique errror condition.                 */
/*                                                                    */
/*  Usage:  Concrete structure                                        */
/*                                                                    */
/*  Side-effects:  None.                                              */
/*                                                                    */
/*  Dependencies:  None.                                              */
/*                                                                    */
/*  Cardinality:  N                                                   */
/*                                                                    */
/*  Space Complexity:  Constant                                       */
/*                                                                    */
/* End Structure Specification ****************************************/

struct STEP_CODE_DATA_STRUCT
{
  // Used to identify a unique error condition. (Muskie/Cobra)
  //  ERROR_OBJECT_CLASS *        error_ptr; // obsolete

  //! Used to identify a unique error condition and collect related information
  ServiceDataCollector *      service_data;

};

} // end namespace PRDF

#endif
