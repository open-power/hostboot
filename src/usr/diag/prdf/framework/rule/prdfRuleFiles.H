/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/framework/rule/prdfRuleFiles.H $            */
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

#ifndef __PRDFRULEFILES_H
#define __PRDFRULEFILES_H

/**
 * @file prdfRuleFiles.H
 * @brief Contains the name of each chip's associated .prf file.
 */

namespace PRDF
{

    // Pegasus P8 Chip
    extern const char * Proc;
    extern const char * Ex;
    extern const char * Mcs;

    // Pegasus Centaur Chip
    extern const char * Membuf;
    extern const char * Mba;

};

#endif

