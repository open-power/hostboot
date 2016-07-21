/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_scan_ring_util.H $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
#ifndef __P9_SCAN_RING_UTIL_H
#define __P9_SCAN_RING_UTIL_H

#include <fapi2.H>
#include "p9_ringId.H"
#include "p9_stop_util.H"
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

namespace p9_hcodeImageBuild
{

/**
 * @brief   enumerates all the platforms associated with hcode image build.
 */
enum PlatId
{
    PLAT_SELF   =   0,
    PLAT_SGPE   =   1,
    PLAT_CME    =   2,
    PLAT_PGPE   =   3,
};

/**
 * @brief   constants associated with fake scan rings.
 */
enum FakeScanRing_t
{
    SCAN_RNG_START      =   0x5363616e20526e67,
    SCAN_RNG_END        =   0x52696e6720456e64,
    MAX_SCAN_RING_SIZE  =   120,
    MAX_FAKE_CMN_RING   =   0x14,
    MAX_FAKE_RING       =   0x1E,
};

/**
 * @brief   debug modes supported for scan rings.
 */
enum RingDebugMode_t
{
    SCAN_RING_NO_DEBUG      =   0x00,
    SCAN_RING_TRACE_DEBUG   =   0x01,
};
/**
 * @brief   models a fake ring for debug.
 */
struct FakeRing
{
    uint64_t iv_ringHeader;
    uint64_t iv_ringNumber;
    uint8_t  iv_ringPayload[MAX_SCAN_RING_SIZE];
    uint64_t iv_ringEnd;

#ifdef __CRONUS_VER
    FakeRing( uint8_t i_ringNumber ):
        iv_ringHeader( SWIZZLE_8_BYTE(SCAN_RNG_START) ),
        iv_ringEnd(SWIZZLE_8_BYTE(SCAN_RNG_END))
    {
        memset( &iv_ringPayload, 0xAA, MAX_SCAN_RING_SIZE );
        uint8_t temp1 = i_ringNumber / 100;
        temp1 = temp1 + 0x30;
        iv_ringNumber = temp1 << 16;
        temp1 = i_ringNumber % 100;
        iv_ringNumber |= (( temp1 / 10) + 0x30 ) << 8;
        iv_ringNumber |= ((temp1 % 10) + 0x30 );
        iv_ringNumber = SWIZZLE_8_BYTE(iv_ringNumber);
    }
#else
    FakeRing( uint8_t i_ringNumber ):
        iv_ringHeader( 0 ),
        iv_ringEnd( 0)
    {
        //dummy constructor to avoid compilation issue
        memset( &iv_ringPayload, 0xAA, MAX_SCAN_RING_SIZE );
    }
#endif
};

class RingName
{
    public:
        /**
         * @brief   constructor
         * @param   i_ringName      name associated with the a scan ring.
         * @param   i_debugMode     debug mode.
         */
        RingName( char* i_ringName );

        /**
         * @brief   constructor
         */
        RingName() {};

        /**
         * @brief   destructor
         */
        ~RingName() {};

        /**
         * @brief   returns string Name.
         */
        char* c_str();
    private:
        char iv_ringStr[40];
};

/**
 * @brief   models the profile of a scan ring for debug.
 */
struct RingProfile
{
    RingID iv_ringId;
    uint32_t iv_ringOffset;
    uint32_t iv_ringSize;
    uint32_t iv_chipletPos;

    RingProfile ( RingID i_ringId, uint16_t i_ringOffset, uint16_t i_ringSize ) :
        iv_ringId( i_ringId ),
        iv_ringOffset( i_ringOffset ),
        iv_ringSize( i_ringSize ),
        iv_chipletPos( 0 )
    { }

    RingProfile ( RingID i_ringId, uint8_t i_chipletPos ) :
        iv_ringId( i_ringId ),
        iv_ringOffset( 0 ),
        iv_ringSize( 0 ),
        iv_chipletPos( i_chipletPos )
    { }

    RingProfile():
        iv_ringId(eq_fure),
        iv_ringOffset(0),
        iv_ringSize(0)
    {}
};

/**
 * @brief   populates an input buffer with a fake scan ring.
 * @param   o_pRingBuffer   rings in which scan rings are copied.
 * @param   o_size          size of scan ring.
 * @param   i_ringId        scan ring id.
 * @param   i_plat          platform associated with scan ring.
 */
void getScanRing( void* o_pRingBuffer, uint32_t& o_size,
                  uint32_t i_ringId, PlatId i_plat );

/**
 * @brief   class to suppport debug of scan ring layout in P9 HOMER
 * @note    Intended platform is cronus.
 */
class RingBucket
{
    public:
        /**
         * @brief   constructor
         */
        RingBucket( PlatId i_plat, uint8_t* i_pRingStart, RingDebugMode_t i_debugMode );

        /**
         * @brief   destructor
         */
        ~RingBucket();
        /**
         * @brief   returns the id of common ring from storage index.
         * @param   i_ringPos   storage position of ring.
         * @return  scan ring id.
         */
        RingID getCommonRingId( uint16_t i_ringPos );

        /**
         * @brief   returns the id of chiplet instance specific ring from storage index.
         * @param   i_ringPos   storage position of ring.
         * @return  scan ring id.
         */
        RingID getInstRingId  ( uint16_t  i_ringPos );

        /**
         * @brief   returns the offset associated with scan ring of given id.
         * @param   i_ringId    Id associated with a scan ring.
         * @param   SUCCESS for successful operation erro code otherwise.
         * @return  offset associated with a given ring.
         */
        uint16_t getRingOffset( RingID i_ringId, uint8_t i_chipletPos = 0 );

        /**
         * @brief   sets the offset associated with scan ring of given id.
         * @param   i_pRingPtr  points to start of scan ring.
         * @param   i_ringId    Id associated with a scan ring.
         * @param   SUCCESS for successful operation, error code otherwise.
         */
        void setRingOffset( uint8_t* i_pRingPtr, RingID i_ringId, uint8_t i_chipletPos = 0 );

        /**
         * @brief   sets base of a ring associated with a given platform.
         * @param   i_ringPos   points to start of ring index of CME/SGPE
         */
        void initRingBase( uint8_t* i_pRingStart );

        /**
         * @brief   sets size of a given scan ring.
         * @param   i_ringId    Id associated with a given scan ring.
         * @param   i_ringSize  size of scan ring.
         */
        void setRingSize( RingID i_ringId, uint16_t i_ringSize, uint8_t i_chipletPos = 0 );

        /**
         * @brief   returns size of a given scan ring.
         * @param   i_ringId    Id associated with a given scan ring.
         * @return  size of a given scan ring.
         */
        uint16_t getRingSize( RingID i_ringId, uint8_t i_chipletPos = 0 );

        /**
         * @brief   returns name of scan ring associated with given id.
         * @param   i_ringId    Id associated with a given scan ring.
         * @return  size of a given scan ring.
         */
        const char* getRingName( RingID i_ringId );

        /**
         * @brief   generates a report on layout of CME/SGPE scan rings in HOMER.
         */
        void dumpRings( );

        /**
         * @brief   generates a report on layout of CME/SGPE scan ring overrides in HOMER.
         */
        void dumpOverrideRings();

    private:
        std::map<uint16_t, RingProfile> iv_cmnRingMap;
        std::map<uint16_t, RingProfile> iv_instRingMap;
        uint8_t* iv_pRingStart;
        uint16_t iv_ringSize;
        PlatId iv_plat;
        RingDebugMode_t iv_debugMode;

        std::map<RingID, RingName> iv_ringName;
};

class P9FuncModel
{
    public:
        /**
         * @brief   constructor
         */
        P9FuncModel( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP >& i_procTgt,
                     uint8_t i_ddLevel );
        /**
         * brief    destructor
         */
        ~P9FuncModel( );

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
         * @brief   constructor
         */
        P9FuncModel(  );

    private:
        P9FuncModel( const P9FuncModel& );              //Disallow copy constructor
        P9FuncModel& operator = ( const P9FuncModel&); // Disallow assignment operator
        uint32_t iv_funcCores;
        uint16_t iv_funcExes;
        uint8_t  iv_funcQuads;
        uint8_t  iv_ddLevel;
};

}// namesapce p9_hcodeImageBuild ends

#endif //__P9_SCAN_RING_UTIL_H
