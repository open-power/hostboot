/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plugins/prdfCalloutsData.H $         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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

/** @file  prdfCalloutsData.H
 *  @brief This is specifically designed to be included in both functional and
 *         error log parsing code (i.e. must be able to compile in PPC and
 *         x86.nfp contexts).
 */

#ifndef __prdfCalloutsData_H
#define __prdfCalloutsData_H

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

namespace PRDcalloutData
{

enum MruType
{
    TYPE_NONE,
    TYPE_TARGET,
    TYPE_MEMMRU,
    TYPE_SYMFRU,
    TYPE_PROCCLK,
    TYPE_PCICLK,
};

} // end namespace PRDcalloutData

#ifdef PRDF_HOSTBOOT_ERRL_PLUGIN
} // end namespace HOSTBOOT
#endif

#ifdef PRDF_FSP_ERRL_PLUGIN
} // end namespace FSP
#endif
} // end namespace PRDF

#endif // __prdfCalloutsData_H

