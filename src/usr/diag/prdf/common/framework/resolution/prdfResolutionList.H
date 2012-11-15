/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/prdfResolutionList.H $ */
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

#ifndef PRDFRESOLUTIONLIST_H
#define PRDFRESOLUTIONLIST_H
/**
   @file prdfResolutionList.H
   @brief List of resolutions
*/
//#include <prdfResolution.H>
#include <iipResolution.h>

#include<list>

typedef std::list<Resolution *> prdfResolutionList;

#define prdfResolution Resolution

#endif /* PRDFRESOLUTIONLIST_H */

// Change Log *****************************************************************
//
//  Flag Reason    Vers  Date     Coder    Description
//  ---- --------- ----- -------- -------- ------------------------------------
//                                dgilbert Initial Creation
//
// End Change Log *************************************************************
