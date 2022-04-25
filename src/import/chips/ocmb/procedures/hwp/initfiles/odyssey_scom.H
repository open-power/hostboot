/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/procedures/hwp/initfiles/odyssey_scom.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
#ifndef _INIT_ODYSSEY_SCOM_PROCEDURE_H_
#define _INIT_ODYSSEY_SCOM_PROCEDURE_H_


#include <stddef.h>
#include <stdint.h>
#include <fapi2.H>


typedef fapi2::ReturnCode (*odyssey_scom_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&);

extern "C"
{

    fapi2::ReturnCode odyssey_scom(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& TGT0);

}

#endif
