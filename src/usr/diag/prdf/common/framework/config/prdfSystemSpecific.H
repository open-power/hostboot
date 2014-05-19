/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/prdfSystemSpecific.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2008,2014              */
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
