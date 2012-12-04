/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/prdfSystemSpecific.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2008,2013              */
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

/** @file prdfSystemSpecific.H
 *  @brief Redirection namespace for code specific for product families.
 *
 *  The purpose of this namespace is to add an indirection between prdf_main
 *  and the various family implementations.  This allows us to create a family
 *  specific library to reduce flash requirements when we have to support
 *  multiple families with the same code level.  (P6 and P7 for example).
 *
 *  There is a P6 implementation for eCLipz, P7 implementation for Apollo and
 *  P8 implementation for pegasus
 *  These are in the appropriate rule/<family> directory in P6/P7.
 *  For p8 these are defines in plat/<family> directory.
 *
 *  For shipping code, only one implementation is in the shipped library.  The
 *  eCLipz instance goes in the libprdfh_p6.so, etc.
 *
 */

#ifndef __PRDFSYSTEMSPECIFIC_H
#define __PRDFSYSTEMSPECIFIC_H

#include <iipConfigurator.h>
#include <iipstep.h>

namespace PRDF
{

namespace SystemSpecific
{
    Configurator * getConfiguratorPtr();
    void postAnalysisWorkarounds(STEP_CODE_DATA_STRUCT & i_sdc);
};

} // end namespace PRDF

#endif
