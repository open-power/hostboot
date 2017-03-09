/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_scan_ring_util.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
#include "p9_scan_ring_util.H"
#include "p9_hcode_image_defines.H"
#include <fapi2.H>
#include <stdio.h>
///
/// @file   p9_scan_ring_util.C
/// @brief  utility classes and functions for scan ring debug.
///
/// *HWP HWP Owner:      Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner:       Prem S Jha <premjha2@in.ibm.com>
/// *HWP Team:           PM
/// *HWP Level:          2
/// *HWP Consumed by:    Hostboot:Phyp:Cro
//

namespace p9_hcodeImageBuild
{
/**
 * @brief some local constants.
 */
enum
{
    TEMP_MAX_QUAD_CMN_RINGS    =   0x50,
    TEMP_MAX_QUAD_SPEC_RINGS   =   0x10,
    TEMP_MAX_CORE_CMN_RINGS    =   0x08,
    TEMP_MAX_CORE_SPEC_RINGS   =   0x04,
};

bool operator < ( const RingProfile& i_lhsRing, const RingProfile& i_rhsRing )
{
    bool l_state = false;

    if( i_lhsRing.iv_ringId < i_rhsRing.iv_ringId )
    {
        l_state = true;
    }
    else if( i_lhsRing.iv_ringId == i_rhsRing.iv_ringId )
    {
        if( i_lhsRing.iv_chipletPos < i_rhsRing.iv_chipletPos )
        {
            l_state = true;
        }
    }

    return l_state;
}

bool operator == ( const RingProfile& i_lhsRing, const RingProfile& i_rhsRing )
{
    bool l_state = false;

    if( i_lhsRing.iv_ringId == i_rhsRing.iv_ringId )
    {
        if( i_lhsRing.iv_chipletPos == i_rhsRing.iv_chipletPos )
        {
            l_state = true;
        }
    }

    return l_state;
}

RingName::RingName( char* i_char )
{
    uint32_t strlength = strlen(i_char);
    strlength = strlength > 40 ? 40 : strlength;
    memset( iv_ringStr, 0, 40);
    memcpy( iv_ringStr, i_char, strlength );
}

char* RingName::c_str()
{
    char* pStrName =   &iv_ringStr[0];
    return pStrName ;
}

void getScanRing( void* o_pRingBuffer, uint32_t& o_size,
                  uint32_t i_ringId, PlatId i_plat )
{
    FAPI_DBG("> getScanRing Plat %s", (i_plat == PLAT_SGPE) ? "SGPE" : "CME");
#ifdef __CRONUS_VER

    do
    {
        FILE* fpFakeRing = fopen( "../../output/gen/fake_ring.bin", "r" );

        if( !fpFakeRing )
        {
            FAPI_ERR("Failed to open fake ring file");
            break;
        }

        fseek( fpFakeRing, ( sizeof( FakeRing ) * i_ringId ), SEEK_SET );
        fread( (uint8_t*)o_pRingBuffer, sizeof(char), sizeof(FakeRing), fpFakeRing );
        o_size = sizeof( FakeRing );

    }
    while(0);

#endif
    FAPI_DBG("< getScanRing");
}
//-------------------------------------------------------------------------

RingBucket::RingBucket( PlatId i_plat, uint8_t* i_pRingStart, RingDebugMode_t i_debugMode  )
{
    iv_pRingStart   =   i_pRingStart;
    iv_plat         =   i_plat;
    iv_debugMode    =   i_debugMode;

    uint32_t ringIndex = 0;

    if( PLAT_SGPE == i_plat )
    {
        RingProfile l_quadCmnRings[TEMP_MAX_QUAD_CMN_RINGS] =
        {
            { eq_fure,                  0,  0 },
            { eq_gptr,                  0,  0 },
            { eq_time,                  0,  0 },
            { eq_mode,                  0,  0 },
            { ex_l3_fure,               0,  0 },
            { ex_l3_gptr,               0,  0 },
            { ex_l3_time,               0,  0 },
            { ex_l2_mode,               0,  0 },
            { ex_l2_fure,               0,  0 },
            { ex_l2_gptr,               0,  0 },
            { ex_l2_time,               0,  0 },
            { ex_l3_refr_fure,          0,  0 },
            { ex_l3_refr_gptr,          0,  0 },
            { eq_ana_func,              0,  0 },
            { eq_ana_gptr,              0,  0 },
            { eq_dpll_func,             0,  0 },
            { eq_dpll_gptr,             0,  0 },
            { eq_dpll_mode,             0,  0 },
            { eq_ana_bndy_bucket_0,     0,  0 },
            { eq_ana_bndy_bucket_1,     0,  0 },
            { eq_ana_bndy_bucket_2,     0,  0 },
            { eq_ana_bndy_bucket_3,     0,  0 },
            { eq_ana_bndy_bucket_4,     0,  0 },
            { eq_ana_bndy_bucket_5,     0,  0 },
            { eq_ana_bndy_bucket_6,     0,  0 },
            { eq_ana_bndy_bucket_7,     0,  0 },
            { eq_ana_bndy_bucket_8,     0,  0 },
            { eq_ana_bndy_bucket_9,     0,  0 },
            { eq_ana_bndy_bucket_10,    0,  0 },
            { eq_ana_bndy_bucket_11,    0,  0 },
            { eq_ana_bndy_bucket_12,    0,  0 },
            { eq_ana_bndy_bucket_13,    0,  0 },
            { eq_ana_bndy_bucket_14,    0,  0 },
            { eq_ana_bndy_bucket_15,    0,  0 },
            { eq_ana_bndy_bucket_16,    0,  0 },
            { eq_ana_bndy_bucket_17,    0,  0 },
            { eq_ana_bndy_bucket_18,    0,  0 },
            { eq_ana_bndy_bucket_19,    0,  0 },
            { eq_ana_bndy_bucket_20,    0,  0 },
            { eq_ana_bndy_bucket_21,    0,  0 },
            { eq_ana_bndy_bucket_22,    0,  0 },
            { eq_ana_bndy_bucket_23,    0,  0 },
            { eq_ana_bndy_bucket_24,    0,  0 },
            { eq_ana_bndy_bucket_25,    0,  0 },
            { eq_ana_bndy_bucket_l3dcc, 0,  0 },
            { eq_ana_mode,              0,  0 },
            { eq_ana_bndy_bucket_26,    0,  0 },
            { eq_ana_bndy_bucket_27,    0,  0 },
            { eq_ana_bndy_bucket_28,    0,  0 },
            { eq_ana_bndy_bucket_29,    0,  0 },
            { eq_ana_bndy_bucket_30,    0,  0 },
            { eq_ana_bndy_bucket_31,    0,  0 },
            { eq_ana_bndy_bucket_32,    0,  0 },
            { eq_ana_bndy_bucket_33,    0,  0 },
            { eq_ana_bndy_bucket_34,    0,  0 },
            { eq_ana_bndy_bucket_35,    0,  0 },
            { eq_ana_bndy_bucket_36,    0,  0 },
            { eq_ana_bndy_bucket_37,    0,  0 },
            { eq_ana_bndy_bucket_38,    0,  0 },
            { eq_ana_bndy_bucket_39,    0,  0 },
            { eq_ana_bndy_bucket_40,    0,  0 },
            { eq_ana_bndy_bucket_41,    0,  0 },
        };

        RingProfile l_quadSpecRings[TEMP_MAX_QUAD_SPEC_RINGS * MAX_QUADS_PER_CHIP] =
        {
            { eq_repr,              0x10  },
            { ex_l3_repr,           0x10  },
            { ex_l3_repr,           0x11  },
            { ex_l2_repr,           0x10  },
            { ex_l2_repr,           0x11  },
            { ex_l3_refr_repr,      0x10  },
            { ex_l3_refr_repr,      0x11  },
            { ex_l3_refr_time,      0x10  },
            { ex_l3_refr_time,      0x11  },

            { eq_repr,              0x11  },
            { ex_l3_repr,           0x12  },
            { ex_l3_repr,           0x13  },
            { ex_l2_repr,           0x12  },
            { ex_l2_repr,           0x13  },
            { ex_l3_refr_repr,      0x12  },
            { ex_l3_refr_repr,      0x13  },
            { ex_l3_refr_time,      0x12  },
            { ex_l3_refr_time,      0x13  },

            { eq_repr,              0x12  },
            { ex_l3_repr,           0x14  },
            { ex_l3_repr,           0x15  },
            { ex_l2_repr,           0x14  },
            { ex_l2_repr,           0x15  },
            { ex_l3_refr_repr,      0x14  },
            { ex_l3_refr_repr,      0x15  },
            { ex_l3_refr_time,      0x14  },
            { ex_l3_refr_time,      0x15  },

            { eq_repr,              0x13  },
            { ex_l3_repr,           0x16  },
            { ex_l3_repr,           0x17  },
            { ex_l2_repr,           0x16  },
            { ex_l2_repr,           0x17  },
            { ex_l3_refr_repr,      0x16  },
            { ex_l3_refr_repr,      0x17  },
            { ex_l3_refr_time,      0x16  },
            { ex_l3_refr_time,      0x17  },

            { eq_repr,              0x14  },
            { ex_l3_repr,           0x18  },
            { ex_l3_repr,           0x19  },
            { ex_l2_repr,           0x18  },
            { ex_l2_repr,           0x19  },
            { ex_l3_refr_repr,      0x18  },
            { ex_l3_refr_repr,      0x19  },
            { ex_l3_refr_time,      0x18  },
            { ex_l3_refr_time,      0x19  },

            { eq_repr,              0x15  },
            { ex_l3_repr,           0x1A  },
            { ex_l3_repr,           0x1B  },
            { ex_l2_repr,           0x1A  },
            { ex_l2_repr,           0x1B  },
            { ex_l3_refr_repr,      0x1A  },
            { ex_l3_refr_repr,      0x1B  },
            { ex_l3_refr_time,      0x1A  },
            { ex_l3_refr_time,      0x1B  },

        };

        for( ringIndex = 0; ringIndex < EQ::g_eqData.iv_num_common_rings; ringIndex++ )
        {
            iv_cmnRingMap[ringIndex] = l_quadCmnRings[ringIndex];
        }

        for( ringIndex = 0; ringIndex < ( EQ::g_eqData.iv_num_instance_rings_scan_addrs * MAX_QUADS_PER_CHIP );
             ringIndex++ )
        {
            iv_instRingMap[ringIndex] = l_quadSpecRings[ringIndex];
        }

        iv_ringName[ eq_fure ]                  =   (char*)"eq_fure             ";
        iv_ringName[ eq_gptr ]                  =   (char*)"eq_gptr             ";
        iv_ringName[ eq_time ]                  =   (char*)"eq_time             ";
        iv_ringName[ eq_mode ]                  =   (char*)"eq_mode             ";
        iv_ringName[ ex_l3_fure ]               =   (char*)"ex_l3_fure          ";
        iv_ringName[ ex_l3_gptr ]               =   (char*)"ex_l3_gptr          ";
        iv_ringName[ ex_l3_time ]               =   (char*)"ex_l3_time          ";
        iv_ringName[ ex_l2_mode ]               =   (char*)"ex_l2_mode          ";
        iv_ringName[ ex_l2_fure ]               =   (char*)"ex_l2_fure          ";
        iv_ringName[ ex_l2_gptr ]               =   (char*)"ex_l2_gptr          ";
        iv_ringName[ ex_l2_time ]               =   (char*)"ex_l2_time          ";
        iv_ringName[ ex_l3_refr_fure ]          =   (char*)"ex_l3_refr_fure     ";
        iv_ringName[ ex_l3_refr_gptr ]          =   (char*)"ex_l3_refr_gptr     ";
        iv_ringName[ eq_ana_func ]              =   (char*)"eq_ana_func         ";
        iv_ringName[ eq_ana_gptr ]              =   (char*)"eq_ana_gptr         ";
        iv_ringName[ eq_dpll_func ]             =   (char*)"eq_dpll_func        ";
        iv_ringName[ eq_dpll_gptr ]             =   (char*)"eq_dpll_gptr        ";
        iv_ringName[ eq_dpll_mode ]             =   (char*)"eq_dpll_mode        ";
        iv_ringName[ eq_ana_bndy_bucket_0 ]     =   (char*)"eq_ana_bndy_bucket_0";
        iv_ringName[ eq_ana_bndy_bucket_1 ]     =   (char*)"eq_ana_bndy_bucket_1";
        iv_ringName[ eq_ana_bndy_bucket_2 ]     =   (char*)"eq_ana_bndy_bucket_2";
        iv_ringName[ eq_ana_bndy_bucket_3 ]     =   (char*)"eq_ana_bndy_bucket_3";
        iv_ringName[ eq_ana_bndy_bucket_4 ]     =   (char*)"eq_ana_bndy_bucket_4";
        iv_ringName[ eq_ana_bndy_bucket_5 ]     =   (char*)"eq_ana_bndy_bucket_5";
        iv_ringName[ eq_ana_bndy_bucket_6 ]     =   (char*)"eq_ana_bndy_bucket_6";
        iv_ringName[ eq_ana_bndy_bucket_7 ]     =   (char*)"eq_ana_bndy_bucket_7";
        iv_ringName[ eq_ana_bndy_bucket_8 ]     =   (char*)"eq_ana_bndy_bucket_8";
        iv_ringName[ eq_ana_bndy_bucket_9 ]     =   (char*)"eq_ana_bndy_bucket_9";
        iv_ringName[ eq_ana_bndy_bucket_10 ]    =   (char*)"eq_ana_bndy_bucket_10";
        iv_ringName[ eq_ana_bndy_bucket_11 ]    =   (char*)"eq_ana_bndy_bucket_11";
        iv_ringName[ eq_ana_bndy_bucket_12 ]    =   (char*)"eq_ana_bndy_bucket_12";
        iv_ringName[ eq_ana_bndy_bucket_13 ]    =   (char*)"eq_ana_bndy_bucket_13";
        iv_ringName[ eq_ana_bndy_bucket_14 ]    =   (char*)"eq_ana_bndy_bucket_14";
        iv_ringName[ eq_ana_bndy_bucket_15 ]    =   (char*)"eq_ana_bndy_bucket_15";
        iv_ringName[ eq_ana_bndy_bucket_16 ]    =   (char*)"eq_ana_bndy_bucket_16";
        iv_ringName[ eq_ana_bndy_bucket_17 ]    =   (char*)"eq_ana_bndy_bucket_17";
        iv_ringName[ eq_ana_bndy_bucket_18 ]    =   (char*)"eq_ana_bndy_bucket_18";
        iv_ringName[ eq_ana_bndy_bucket_19 ]    =   (char*)"eq_ana_bndy_bucket_19";
        iv_ringName[ eq_ana_bndy_bucket_20 ]    =   (char*)"eq_ana_bndy_bucket_20";
        iv_ringName[ eq_ana_bndy_bucket_21 ]    =   (char*)"eq_ana_bndy_bucket_21";
        iv_ringName[ eq_ana_bndy_bucket_22 ]    =   (char*)"eq_ana_bndy_bucket_22";
        iv_ringName[ eq_ana_bndy_bucket_23 ]    =   (char*)"eq_ana_bndy_bucket_23";
        iv_ringName[ eq_ana_bndy_bucket_24 ]    =   (char*)"eq_ana_bndy_bucket_24";
        iv_ringName[ eq_ana_bndy_bucket_25 ]    =   (char*)"eq_ana_bndy_bucket_25";
        iv_ringName[ eq_ana_bndy_bucket_l3dcc ] =   (char*)"eq_ana_bndy_bucket_l3dcc";
        iv_ringName[ eq_ana_mode ]              =   (char*)"eq_ana_mode          ";
        iv_ringName[ eq_ana_bndy_bucket_26 ]    =   (char*)"eq_ana_bndy_bucket_26";
        iv_ringName[ eq_ana_bndy_bucket_27 ]    =   (char*)"eq_ana_bndy_bucket_27";
        iv_ringName[ eq_ana_bndy_bucket_28 ]    =   (char*)"eq_ana_bndy_bucket_28";
        iv_ringName[ eq_ana_bndy_bucket_29 ]    =   (char*)"eq_ana_bndy_bucket_29";
        iv_ringName[ eq_ana_bndy_bucket_30 ]    =   (char*)"eq_ana_bndy_bucket_30";
        iv_ringName[ eq_ana_bndy_bucket_31 ]    =   (char*)"eq_ana_bndy_bucket_31";
        iv_ringName[ eq_ana_bndy_bucket_32 ]    =   (char*)"eq_ana_bndy_bucket_32";
        iv_ringName[ eq_ana_bndy_bucket_33 ]    =   (char*)"eq_ana_bndy_bucket_33";
        iv_ringName[ eq_ana_bndy_bucket_34 ]    =   (char*)"eq_ana_bndy_bucket_34";
        iv_ringName[ eq_ana_bndy_bucket_35 ]    =   (char*)"eq_ana_bndy_bucket_35";
        iv_ringName[ eq_ana_bndy_bucket_36 ]    =   (char*)"eq_ana_bndy_bucket_36";
        iv_ringName[ eq_ana_bndy_bucket_37 ]    =   (char*)"eq_ana_bndy_bucket_37";
        iv_ringName[ eq_ana_bndy_bucket_38 ]    =   (char*)"eq_ana_bndy_bucket_38";
        iv_ringName[ eq_ana_bndy_bucket_39 ]    =   (char*)"eq_ana_bndy_bucket_39";
        iv_ringName[ eq_ana_bndy_bucket_40 ]    =   (char*)"eq_ana_bndy_bucket_40";
        iv_ringName[ eq_ana_bndy_bucket_41 ]    =   (char*)"eq_ana_bndy_bucket_41";
        iv_ringName[ eq_repr ]                  =   (char*)"eq_repr              ";
        iv_ringName[ ex_l3_repr ]               =   (char*)"ex_l3_repr           ";
        iv_ringName[ ex_l2_repr ]               =   (char*)"ex_l2_repr           ";
        iv_ringName[ ex_l3_refr_repr ]          =   (char*)"ex_l3_refr_repr      ";
        iv_ringName[ ex_l3_refr_time ]          =   (char*)"ex_l3_refr_time      ";
    }
    else if( PLAT_CME == i_plat )
    {
        RingProfile l_coreCmnRings[TEMP_MAX_CORE_CMN_RINGS] =
        {
            { ec_func, 0, 0 },
            { ec_gptr, 0, 0 },
            { ec_time, 0, 0 },
            { ec_mode, 0, 0 },
            { ec_abst, 0, 0 },
        };

        RingProfile l_coreSpecRings[TEMP_MAX_CORE_SPEC_RINGS * MAX_CORES_PER_CHIP] =
        {
            { ec_repr, 0 },
            { ec_repr, 1 },
            { ec_repr, 2 },
            { ec_repr, 3 },
            { ec_repr, 4 },
            { ec_repr, 5 },
            { ec_repr, 6 },
            { ec_repr, 7 },
            { ec_repr, 8 },
            { ec_repr, 9 },
            { ec_repr, 10 },
            { ec_repr, 11},
            { ec_repr, 12 },
            { ec_repr, 13 },
            { ec_repr, 14 },
            { ec_repr, 15 },
            { ec_repr, 16 },
            { ec_repr, 17 },
            { ec_repr, 18 },
            { ec_repr, 19 },
            { ec_repr, 20 },
            { ec_repr, 21 },
            { ec_repr, 22 },
            { ec_repr, 23 },
        };

        for( ringIndex = 0; ringIndex < EC::g_ecData.iv_num_common_rings; ringIndex++ )
        {
            iv_cmnRingMap[ringIndex] = l_coreCmnRings[ringIndex];
        }

        for( ringIndex = 0; ringIndex < MAX_CORES_PER_CHIP;
             ringIndex++ )
        {
            iv_instRingMap[ringIndex] = l_coreSpecRings[ringIndex];
        }

        iv_ringName[ ec_func ]      =   (char*)"ec_func        ";
        iv_ringName[ ec_gptr ]      =   (char*)"ec_gptr        ";
        iv_ringName[ ec_time ]      =   (char*)"ec_time        ";
        iv_ringName[ ec_mode ]      =   (char*)"ec_mode        ";
        iv_ringName[ ec_repr ]      =   (char*)"ec_repr        ";
        iv_ringName[ ec_abst ]      =   (char*)"ec_abst        ";
    }
}

//-------------------------------------------------------------------------
RingBucket:: ~RingBucket()
{
#ifdef    __CRONUS_VER
    iv_ringName.clear();
#endif
    iv_instRingMap.clear();
    iv_cmnRingMap.clear();

}
//-------------------------------------------------------------------------

RingID RingBucket::getCommonRingId( uint16_t i_ringPos )
{
    return iv_cmnRingMap[i_ringPos].iv_ringId; // for now not checking validity of pos
}

//-------------------------------------------------------------------------

RingID RingBucket::getInstRingId( uint16_t i_ringPos )
{
    return iv_instRingMap[i_ringPos].iv_ringId; // for now not checking validity of pos
}

//-------------------------------------------------------------------------

uint16_t RingBucket::getRingOffset( RingID i_ringId, uint8_t i_chipletPos  )
{
    uint16_t l_ringOffset = 0;
    std::map<uint16_t, RingProfile>::iterator it;

    do
    {
        for( it = iv_cmnRingMap.begin(); it != iv_cmnRingMap.end();
             it++ )
        {
            RingProfile l_searchRing( i_ringId, i_chipletPos );

            if( it->second  == l_searchRing )
            {
                l_ringOffset = it->second.iv_ringOffset;
                break;
            }
        }

        for( it = iv_instRingMap.begin(); it != iv_instRingMap.end();
             it++ )
        {
            RingProfile l_searchRing( i_ringId, i_chipletPos );

            if( it->second  == l_searchRing )
            {
                l_ringOffset = it->second.iv_ringOffset;
                break;
            }
        }

    }
    while(0);

    return l_ringOffset;
}

//-------------------------------------------------------------------------


void RingBucket::setRingOffset( uint8_t* i_pRingPtr, RingID i_ringId, uint8_t i_chipletPos )
{
    do
    {
        std::map<uint16_t, RingProfile>::iterator it;
        RingProfile l_searchRing( i_ringId, i_chipletPos );

        for( it = iv_cmnRingMap.begin(); it != iv_cmnRingMap.end();
             it++ )
        {
            if( it->second == l_searchRing )
            {
                it->second.iv_ringOffset =  i_pRingPtr - iv_pRingStart;
                break;
            }
        }

        for( it = iv_instRingMap.begin(); it != iv_instRingMap.end();
             it++ )
        {
            if( it->second == l_searchRing )
            {
                it->second.iv_ringOffset =  i_pRingPtr - iv_pRingStart;
                break;
            }
        }
    }
    while(0);
}

//-------------------------------------------------------------------------

void RingBucket::initRingBase( uint8_t* i_pRingStart )
{
    iv_pRingStart = i_pRingStart;
}

//-------------------------------------------------------------------------
uint16_t RingBucket::getRingSize( RingID i_ringId, uint8_t i_chipletPos )
{
    std::map<uint16_t, RingProfile>::iterator it = iv_cmnRingMap.begin();
    uint16_t l_ringSize = 0;
    RingProfile l_searchRing( i_ringId, i_chipletPos );

    do
    {
        for( it = iv_cmnRingMap.begin(); it != iv_cmnRingMap.end();
             it++ )
        {
            if( it->second == l_searchRing )
            {
                l_ringSize = it->second.iv_ringSize;
                break;
            }
        }

        for( it = iv_instRingMap.begin(); it != iv_instRingMap.end();
             it++ )
        {
            if ( it->second == l_searchRing )
            {
                l_ringSize = it->second.iv_ringSize;
                break;
            }
        }

    }
    while(0);

    return l_ringSize;
}

//-------------------------------------------------------------------------

void RingBucket::setRingSize( RingID i_ringId, uint16_t i_ringSize, uint8_t i_chipletPos )
{
    std::map<uint16_t, RingProfile>::iterator it = iv_cmnRingMap.begin();

    do
    {
        RingProfile l_searchRing( i_ringId, i_chipletPos );

        for( it = iv_cmnRingMap.begin(); it != iv_cmnRingMap.end();
             it++ )
        {
            if( it->second == l_searchRing )
            {
                it->second.iv_ringSize = i_ringSize;
                break;
            }
        }

        for( it = iv_instRingMap.begin(); it != iv_instRingMap.end();
             it++ )
        {
            if( it->second == l_searchRing )
            {
                it->second.iv_ringSize = i_ringSize;
                break;
            }
        }

    }
    while(0);

}

//-------------------------------------------------------------------------

const char* RingBucket::getRingName( RingID i_ringId )
{
    const char* pRingName = NULL;

    if( iv_ringName.find(i_ringId) != iv_ringName.end() )
    {
        pRingName = ((iv_ringName.find(i_ringId)->second).c_str());
    }

    return pRingName;
}

//-------------------------------------------------------------------------
void RingBucket::extractRing( void* i_ptr, uint32_t i_ringSize, uint32_t i_ringId )
{
    do
    {
        if( SCAN_RING_NO_DEBUG == iv_debugMode )
        {
            break;
        }

        if( !i_ptr )
        {
            break;
        }

        uint8_t* pRing = (uint8_t*)(i_ptr);
        uint16_t maxLines = i_ringSize / sizeof(uint64_t);
        FAPI_DBG("Ring Id 0x%08x", i_ringId );

        for( uint32_t ringId = 0; ringId < maxLines; ringId++ )
        {
            FAPI_DBG("%02x %02x %02x %02x %02x %02x %02x %02x",
                     (*pRing ), *(pRing + 1), *(pRing + 2 ), *(pRing + 3 ),
                     *(pRing + 4 ), *(pRing + 5 ), *(pRing + 6 ), *(pRing + 7 ) );
            pRing = pRing + sizeof(uint64_t);
        }

    }
    while(0);
}
//-------------------------------------------------------------------------

void RingBucket::dumpRings( )
{
    std::map<RingID, RingName>::iterator it = iv_ringName.begin();
    uint32_t chipletNo = 0;

    do
    {
        if( SCAN_RING_NO_DEBUG == iv_debugMode )
        {
            break;
        }

        FAPI_INF("===================================================================================");
        FAPI_INF("===================================================================================");

        if( iv_plat == PLAT_CME )
        {
            FAPI_INF("---------------------------------CME Rings---------------------------------------");
            chipletNo = EC::g_ecData.iv_num_instance_rings_scan_addrs;
        }
        else if( iv_plat == PLAT_SGPE )
        {
            FAPI_INF("---------------------------------SGPE Rings--------------------------------------");
            chipletNo = EQ::g_eqData.iv_num_instance_rings_scan_addrs;
        }
        else
        {
            FAPI_INF("---------------------------------Unknown Platform--------------------------------");
        }

        FAPI_INF("-------------------------------------------------------------------------------------");
        FAPI_INF("-------------------------------------------------------------------------------------");
        FAPI_INF("-------------------------------Common Rings------------------------------------------");
        FAPI_INF("Ring Name----------------------Offset----------------------------Size----------------");
        FAPI_INF("=====================================================================================");
        FAPI_INF("=====================================================================================");

        for( uint16_t ringIndex = 0; ringIndex < iv_cmnRingMap.size();
             ringIndex++ )
        {
            it = iv_ringName.find( iv_cmnRingMap[ringIndex].iv_ringId );

            if( iv_ringName.end() != it )
            {
                FAPI_INF("%s\t\t  %08d ( 0x%08x )\t\t%08d ( 0x%08x )", (it->second).c_str(),
                         iv_cmnRingMap[ringIndex].iv_ringOffset,
                         iv_cmnRingMap[ringIndex].iv_ringOffset,
                         iv_cmnRingMap[ringIndex].iv_ringSize,
                         iv_cmnRingMap[ringIndex].iv_ringSize );
            }
        }

        FAPI_INF("=====================================================================================");
        FAPI_INF("=====================================================================================");
        FAPI_INF("-------------------------------Instance Ring-----------------------------------------");
        FAPI_INF("Ring Name----------------------Offset-------------------------Size-------------------");

        for( uint16_t ringIndex = 0; ringIndex < iv_instRingMap.size();
             ringIndex++ )
        {
            uint32_t chipletIndex = ringIndex % chipletNo;

            if(( 0 == ringIndex ) || ( 0 == chipletIndex ))
            {
                FAPI_INF("==============================================================================");
                FAPI_INF("==============================================================================");
                FAPI_INF("\t\t%s ( %d )", ( iv_plat == PLAT_CME ) ? "Core" : "Cache", (ringIndex / chipletNo) );
                FAPI_INF("==============================================================================");
                FAPI_INF("==============================================================================");
            }

            it = iv_ringName.find( iv_instRingMap[ringIndex].iv_ringId );

            if( iv_ringName.end() != it )
            {
                FAPI_INF("%s\t  %08d ( 0x%08x )\t\t%08d ( 0x%08x )", (it->second).c_str(),
                         iv_instRingMap[ringIndex].iv_ringOffset,
                         iv_instRingMap[ringIndex].iv_ringOffset,
                         iv_instRingMap[ringIndex].iv_ringSize,
                         iv_instRingMap[ringIndex].iv_ringSize );
            }
        }

        FAPI_INF("=================================================================================");
        FAPI_INF("=================================================================================");
    }
    while(0);
}

//-------------------------------------------------------------------------
void RingBucket::dumpOverrideRings( )
{
    std::map<RingID, RingName>::iterator it = iv_ringName.begin();

    do
    {
        if( SCAN_RING_NO_DEBUG == iv_debugMode )
        {
            break;
        }

        FAPI_INF("===================================================================================");
        FAPI_INF("===================================================================================");

        if( iv_plat == PLAT_CME )
        {
            FAPI_INF("----------------------------------CME Ring Overrides---------------------------");
        }
        else if( iv_plat == PLAT_SGPE )
        {
            FAPI_INF("----------------------------------SGPE Rings Overrides-------------------------");
        }
        else
        {
            FAPI_INF("----------------------------------Unknown Platform-----------------------------");
        }

        FAPI_INF("-----------------------------------------------------------------------------------");
        FAPI_INF("-----------------------------------------------------------------------------------");
        FAPI_INF("Ring Name----------------------Offset----------------------------Size--------------");
        FAPI_INF("===================================================================================");
        FAPI_INF("===================================================================================");

        for( uint16_t ringIndex = 0; ringIndex < iv_cmnRingMap.size();
             ringIndex++ )
        {
            it = iv_ringName.find( iv_cmnRingMap[ringIndex].iv_ringId );

            if( iv_ringName.end() != it )
            {
                FAPI_INF("%s\t  %08d ( 0x%08x )\t\t%08d ( 0x%08x )", (it->second).c_str(),
                         iv_cmnRingMap[ringIndex].iv_ringOffset,
                         iv_cmnRingMap[ringIndex].iv_ringOffset,
                         iv_cmnRingMap[ringIndex].iv_ringSize,
                         iv_cmnRingMap[ringIndex].iv_ringSize );
            }
        }

        FAPI_INF("===============================================================================");
        FAPI_INF("===============================================================================");

    }
    while(0);
}
//-------------------------------------------------------------------------

P9FuncModel::P9FuncModel(  ):
    iv_funcCores(0),
    iv_funcExes(0),
    iv_funcQuads(0),
    iv_ddLevel(0)
{ }
//-------------------------------------------------------------------------

P9FuncModel::P9FuncModel( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP >& i_procTgt , uint8_t i_ddLevel )
{
    iv_funcCores = 0;
    iv_funcExes  = 0;
    iv_funcQuads = 0;
    iv_ddLevel   = i_ddLevel;

    auto l_core_functional_vector =
        i_procTgt.getChildren<fapi2::TARGET_TYPE_CORE>(fapi2::TARGET_STATE_FUNCTIONAL);
    uint8_t l_corePos = 0;

    for( auto it : l_core_functional_vector )
    {
        FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS, it, l_corePos );
        FAPI_DBG("functional cores id %d", l_corePos );
        iv_funcCores    =   iv_funcCores  | (1 << l_corePos );
        iv_funcExes     =   iv_funcExes   | (1 << (l_corePos >> 1) );
        iv_funcQuads    =   iv_funcQuads  | (1 << (l_corePos >> 2) );
    }

    FAPI_DBG("functional core 0x%08x, Ex 0x%08x quad 0x%08x",
             iv_funcCores, iv_funcExes, iv_funcQuads );
}

//---------------------------------------------------------------------------

P9FuncModel::~P9FuncModel()
{
    FAPI_DBG("Destroyed P9FuncModel");
}

//---------------------------------------------------------------------------

bool P9FuncModel::isCoreFunctional( uint32_t i_corePos ) const
{
    return ( (iv_funcCores & ( 1 << i_corePos )) != 0 );
}

//-------------------------------------------------------------------------

bool P9FuncModel::isExFunctional( uint32_t i_exPos )    const
{
    return ( (iv_funcExes & ( 1 << i_exPos )) != 0 );
}

//-------------------------------------------------------------------------

bool P9FuncModel::isQuadFunctional( uint32_t i_quadPos ) const
{
    return ( (iv_funcQuads & ( 1 << i_quadPos )) != 0 );
}

//-------------------------------------------------------------------------
uint8_t P9FuncModel::getChipLevel() const
{
    return iv_ddLevel;
}

}
