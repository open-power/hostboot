/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/ibscom/ibscomif.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
#ifndef __IBSCOM_IBSCOMIF_H
#define __IBSCOM_IBSCOMIF_H

#include <stdint.h>
#include <builtins.h>
#include <errl/errlentry.H>

namespace IBSCOM
{

#define IBSCOM_DISABLE true
#define IBSCOM_ENABLE false

/**
 * @brief Enable or disable Inband SCOMs on all capable chips
 *
 * @param i_disable  true: disable inband scoms
 */
void enableInbandScoms( bool i_disable = IBSCOM_ENABLE );

}

#endif
