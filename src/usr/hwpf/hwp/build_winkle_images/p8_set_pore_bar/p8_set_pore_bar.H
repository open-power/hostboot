/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_set_pore_bar/p8_set_pore_bar.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
// $Id: p8_set_pore_bar.H,v 1.2 2014/11/07 18:27:55 cmolsen Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_set_pore_bar.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : p8_set_pore_bar.H
// *! DESCRIPTION : Establish the BAR setup for the SLW image in the PBA as
// *!               well as setting up the SLW engine with table base address
// *!               and memory relocation regs in the SLW
// *!
// *! OWNER NAME  : Greg Still    Email: stillgs@us.ibm.com
// *! BACKUP NAME : Jim Yacynych  Email: jimyac@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_SET_PORE_BAR_H_
#define _PROC_SET_PORE_BAR_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------


// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*p8_set_pore_bar_FP_t) (const fapi::Target&, 
                                                    void*, 
                                                    uint64_t,
                                                    uint64_t,
                                                    uint32_t                                                    
                                                    );

extern "C" {


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

enum PORE_SLW_LOC {
        SLW_MEMORY  = 0x0,
        SLW_L3      = 0x1,
        SLW_SRAM    = 0x2
        };

// The value here will yield the appropriate nibble for accessing the PowerBus
// Regions (eg 0:1 = 00) when added to 0x8 (the SLW image effective address upper 
// nibble) - 4 bit math only.
enum PORE_SLW_PBA_BAR {
        PBA_SLW_BAR0    = 0x8,  // 0x8 + 0x8 = 0x0
        PBA_SLW_BAR1    = 0x9,  // 0x8 + 0x9 = 0x1
        PBA_SLW_BAR2    = 0xA,  // 0x8 + 0xA = 0x2
        PBA_SLW_BAR3    = 0xB   // 0x8 + 0xB = 0x3
        };
       
enum PORE_PBA_BAR {
        PBA_BAR0    = 0x0,
        PBA_BAR1    = 0x1,
        PBA_BAR2    = 0x2,
        PBA_BAR3    = 0x3
        };
        
enum PORE_PBA_SLAVE {
        PBA_SLAVE0    = 0x0,
        PBA_SLAVE1    = 0x1,
        PBA_SLAVE2    = 0x2,
        PBA_SLAVE3    = 0x3
        };

//------------------------------------------------------------------------------
// Parameter structure definitions
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
/// \param[in] i_target     Procesor Chip target
/// \param[in] i_image      Platform memory pointer where image is
///                         located
/// \param[in] i_mem_bar    Base address of the region where image is located
/// \param[in] i_mem_size   Size (in MB) of the region where image is located
///                         if not a power of two value, the value will be 
///                         rounded up to the next power of 2 for setting the 
///                         hardware mask
/// \param[in] i_mem_type   Defines where the SLW image was loaded.  See
///                         p8_set_pore_bar.H enum for valid values.

fapi::ReturnCode 
p8_set_pore_bar(  const fapi::Target& i_target, 
                    void *i_image, 
                    uint64_t i_mem_bar, 
                    uint64_t i_mem_size, 
                    uint32_t i_mem_type);


} // extern "C"

#endif // _PROC_SET_PORE_BAR_H_
