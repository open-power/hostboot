/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_dump_pstate_table.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
///
/// @file  p10_dump_pstate_table.H
/// @brief Prints out the PGPE Generated PState Info structure
///


#ifndef _P10_DUMP_PSTATE_TABLE_H_
#define _P10_DUMP_PSTATE_TABLE_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <pstates_common.H>
#include <pstates_pgpe.H>
#include <pstates_occ.H>
#include <pstates_table.H>
#include <p10_hcode_image_defines.H>

enum PSTATE_DUMP_FLAGS
{
    PSTATE_DUMP_ALL           =  0xFFFFFFFF,
    PSTATE_DUMP_BASIC         =  0x00000001,
    PSTATE_DUMP_FULL          =  0x00000002,
    PSTATE_DUMP_RESCLK        =  0x00000004,
    PSTATE_DUMP_DDS           =  0x00000008,
    PSTATE_DUMP_PGPE_FLAGS    =  0x00000010,
    PSTATE_DUMP_WOF_WOV       =  0x00000020,
    PSTATE_DUMP_VRM           =  0x00000040,
    PSTATE_DUMP_OCC           =  0x00000080,
};

extern "C"
{

    void p10_dump_pstate_table(void* gpi, uint32_t pstate_dump_flag);
    void p10_dump_occ_ppb(OCCPstateParmBlock_t* i_oppb);

} // end extern C

#endif //_P10_DUMP_PSTATE_TABLE_H_
