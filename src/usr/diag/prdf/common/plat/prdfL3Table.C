/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/prdfL3Table.C $                 */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2012              */
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

/**
    @file prdfL3Table.C
    @brief description
*/
//-------------------------------------------------------------------------------------------------
//  Includes
//-------------------------------------------------------------------------------------------------
#define prdfL3Table_C

#include <prdfL3Table.H>

#undef prdfL3Table_C
//-------------------------------------------------------------------------------------------------
//  User Types, Constants, macros, prototypes, globals
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Member Function Specifications
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------

int32_t prdfL3TableAdd(TARGETING::TargetHandle_t i_pl3targetHandle, uint32_t address)
{
  int32_t rc = 0;
  return rc;
}

//-------------------------------------------------------------------------------------------------

void prdfL3TableGet(TARGETING::TargetHandle_t i_pl3targetHandle, uint32_t table[LineDeleteTableSize])
{
}

//-------------------------------------------------------------------------------------------------

int32_t prdfL3TableCount(TARGETING::TargetHandle_t i_pl3targetHandle)
{
  int32_t rc = 0;
  return rc;
}

//-------------------------------------------------------------------------------------------------

errlHndl_t prdfL3LineDelete(TARGETING::TargetHandle_t i_pl3targetHandle, uint32_t address)
{
  return NULL;
}

//-------------------------------------------------------------------------------------------------

// Change Log *************************************************************************************
//
//  Flag Reason  Vers    Date     Coder    Description
//  ---- ------ ------- -------- -------- -------------------------------------------------------
//       485074 fips310 12/14/04 dgilbert Initial Creation
//
// End Change Log *********************************************************************************
