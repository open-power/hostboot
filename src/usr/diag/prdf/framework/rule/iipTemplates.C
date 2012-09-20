/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/framework/rule/iipTemplates.C $             */
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

#include <iipDomainContainer.h>
#include <iipDomainContainer.C>
#include <prdfRuleChip.H>

template class DomainContainer<PrdfRuleChip>;

// Change Log *********************************************************
//
//  Flag Reason   Vers Date     Coder    Description
//  ---- -------- ---- -------- -------- ------------------------------
//                              DGILBERT Initial Creation
//       F429488  fips 12/16/03 mkobler  Added prdfMcChip template
//         F494911  f310 03/04/05 iawillia Added PrdfRuleChip template.
//  dg01          f300 04/05/06 dgilbert Added Domain of prdfExtensibleChip
//  dg02 F557969  f310 07/05/06 dgilbert Remove obsolite parts
// End Change Log *****************************************************
