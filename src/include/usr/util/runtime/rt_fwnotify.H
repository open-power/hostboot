/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/util/runtime/rt_fwnotify.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2019                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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
#ifndef __RUNTIME_FWNOTIFY_H
#define __RUNTIME_FWNOTIFY_H

#include <runtime/interface.h>

/**
 *  @brief Perform an NVDIMM operation
 *  @param[in] nvDimmOp - A struct that contains the operation(s) to perform
 *                        and a flag indicating whether to perform operation
 *                        on all processors or a given single processor.
 *  @Note The operations below are in the order of which they should be
 *        performed.  If a new operation is added, make sure it inserted in the
 *        correct order.
 *        The current order is: disarm -> disable encryption -> remove keys ->
 *                              enable encryption -> arm
 **/
int doNvDimmOperation(const hostInterfaces::nvdimm_operation_t& nvDimmOp);



#endif   // __RUNTIME_FWNOTIFY_H
