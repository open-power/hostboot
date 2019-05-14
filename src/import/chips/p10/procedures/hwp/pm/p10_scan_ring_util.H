/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_scan_ring_util.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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
#ifndef __P10_SCAN_RING_UTIL_H
#define __P10_SCAN_RING_UTIL_H

#include <fapi2.H>
#include <map>

//#define __CRONUS_VER
///
/// @file   p9_scan_ring_util.H
/// @brief  utility classes and functions for scan ring debug.
///
/// *HWP HWP Owner:      Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner:       Prem S Jha <premjha2@in.ibm.com>
/// *HWP Team:           PM
/// *HWP Level:          2
/// *HWP Consumed by:    Hostboot:Phyp:Cro
//

namespace hcodeImageBuild
{

/**
 * @brief   enumerates all the platforms associated with hcode image build.
 */
enum PlatId
{
    PLAT_SELF   =   0,
    PLAT_XGPE   =   1,
    PLAT_QME    =   2,
    PLAT_PGPE   =   3,
};

class P10FuncModel
{
    public:
        /**
         * @brief   constructor
         */
        P10FuncModel( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP >& i_procTgt );
        /**
         * brief    destructor
         */
        ~P10FuncModel( );

        /**
         * @brief   returns functional state of a given core.
         */
        bool isCoreFunctional( uint32_t i_corePos ) const;

        /**
         * @brief   returns functional state of a given ex.
         */
        bool isExFunctional( uint32_t i_exPos )     const;

        /**
         * @brief   returns functional state of a given quad.
         */
        bool isQuadFunctional( uint32_t i_quadPos ) const;

        /**
         * @brief   returns dd level associated with a processor.
         */
        uint8_t getChipLevel()  const;

        /**
         * uint8_t returns an ID pertaining to chip name.
         */

        uint8_t getChipName() const;

        /**
         * @brief   constructor
         */
        P10FuncModel(  );

    private:
        P10FuncModel( const P10FuncModel& );              //Disallow copy constructor
        P10FuncModel& operator = ( const P10FuncModel&); // Disallow assignment operator
        uint32_t iv_funcCores;
        uint16_t iv_funcExes;
        uint8_t  iv_funcQuads;
        uint8_t  iv_ddLevel;
        uint8_t  iv_chipName;
        uint8_t  iv_reserved[2];
};

}// namesapce hcodeImageBuild ends

#endif //__P10_SCAN_RING_UTIL_H
