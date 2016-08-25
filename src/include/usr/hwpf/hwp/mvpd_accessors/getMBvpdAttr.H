/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/mvpd_accessors/getMBvpdAttr.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2016                        */
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
// $Id: getMBvpdAttr.H,v 1.8 2015/11/02 21:42:22 sglancy Exp $

/**
 *  @file getMBvpdAttr.H
 *
 *  @brief Prototype for getMBvpdAttr() -
 *          get Attribute Data from MBvpd
 */

#ifndef    _HWP_MBVPDATTR_
#define    _HWP_MBVPDATTR_

#include   <fapi.H>
#include    <fapiUtil.H>
#include   <fapiMBvpdAccess.H>

namespace fapi
{
namespace getAttrData
{
    const uint32_t VM_00_MR_LAYOUT_KW_SIZE = 255;
    const uint32_t VM_00_MR_LAYOUT_NON_PORT_HEAD_SIZE = 0;
    const uint32_t VM_00_MR_LAYOUT_PORT_SEC_SIZE = 64;
    const uint32_t VM_00_MT_LAYOUT_KW_SIZE = 255;
    const uint32_t VM_00_MT_LAYOUT_NON_PORT_HEAD_SIZE = 0;
    const uint32_t VM_00_MT_LAYOUT_PORT_SEC_SIZE = 64;
    const uint32_t VM_01_MR_LAYOUT_KW_SIZE = 255;
    const uint32_t VM_01_MR_LAYOUT_NON_PORT_HEAD_SIZE =2;
    const uint32_t VM_01_MR_LAYOUT_PORT_SEC_SIZE = 64;
    const uint32_t VM_01_MT_LAYOUT_KW_SIZE = 384;
    const uint32_t VM_01_MT_LAYOUT_NON_PORT_HEAD_SIZE = 2;
    const uint32_t VM_01_MT_LAYOUT_PORT_SEC_SIZE = 96;

    class keywordLayout
    {
        public:
        virtual uint32_t getKeywordSize()=0;
        virtual uint32_t getNonPortHeadSize()=0;
        virtual uint32_t getPortSectionSize()=0;
        virtual ~keywordLayout() {}
    };
    class VM_00_MR_layout : public keywordLayout
    {
        public:
        uint32_t getKeywordSize(){ return VM_00_MR_LAYOUT_KW_SIZE; }
        uint32_t getNonPortHeadSize(){ return VM_00_MR_LAYOUT_NON_PORT_HEAD_SIZE; }
        uint32_t getPortSectionSize(){ return VM_00_MR_LAYOUT_PORT_SEC_SIZE; }
        ~VM_00_MR_layout() {}
    };
    class VM_00_MT_layout : public keywordLayout
    {
        public:
        uint32_t getKeywordSize(){ return VM_00_MT_LAYOUT_KW_SIZE; }
        uint32_t getNonPortHeadSize(){ return VM_00_MT_LAYOUT_NON_PORT_HEAD_SIZE; }
        uint32_t getPortSectionSize(){ return VM_00_MT_LAYOUT_PORT_SEC_SIZE; }
        ~VM_00_MT_layout() {}
    };
    class VM_01_MR_layout : public keywordLayout
    {
        public:
        uint32_t getKeywordSize(){ return VM_01_MR_LAYOUT_KW_SIZE; }
        uint32_t getNonPortHeadSize(){ return VM_01_MR_LAYOUT_NON_PORT_HEAD_SIZE; }
        uint32_t getPortSectionSize(){ return VM_01_MR_LAYOUT_PORT_SEC_SIZE; }
        ~VM_01_MR_layout() {}
    };
    class VM_01_MT_layout : public keywordLayout
    {
        public:
        uint32_t getKeywordSize(){ return VM_01_MT_LAYOUT_KW_SIZE; }
        uint32_t getNonPortHeadSize(){ return VM_01_MT_LAYOUT_NON_PORT_HEAD_SIZE; }
        uint32_t getPortSectionSize(){ return VM_01_MT_LAYOUT_PORT_SEC_SIZE; }
        ~VM_01_MT_layout() {}
    };
    class layoutFactory
    {
        public:     
        static keywordLayout* getLayout(const uint32_t &i_keyword ,const uint32_t &i_ver);
    };
    

    //MT and MR keyword layout for VM ver 0.
    const uint8_t NUM_MBA =  2;    //There are 2 MBAs per Centaur memory buffer
    const uint8_t NUM_PORTS = 2;   //Each MBA has 2 ports
    const uint8_t NUM_DIMMS = 2;   //Each port has 2 DIMMs
    const uint8_t NUM_RANKS = 4;   //Number of ranks

    //  DIMM types
    enum DimmType
    {
        ALL_DIMM = 0,        // Same for all Dimm types
        CDIMM    = 1,
        ISDIMM   = 2,
    };

    //Exceptions for MT keyword layout for VM ver 1.
    

    //  Versions to check for
    enum VpdVersion
    {
        VD_VER  = 0x010000,        // Version came from VD keyword
        VZ_VER  = 0x020000,        // Version came from VZ keyword
        VM_VER  = 0x040000,        // Version came from VM keyword
        ALL_VD  = VD_VER,          // Base value for VD keyword (version=0)
        ALL_VZ  = VZ_VER,          // Base value for VZ keyword (version=0)
        ALL_VM  = VM_VER,          // Base value for VM keyword (version=0)
        ALL_VER = VD_VER|VZ_VER|VM_VER,   // Base value for all versions

        // VZ values
        VZ_10   = VZ_VER | 0x3130, // Version 6.0 is ascii "10"
        VZ_13   = VZ_VER | 0x3133, // Version 6.3 is ascii "13"

        // VD values
        VD_01   = VD_VER | 0x3031, // VD version "01"
 
        // VM values
        VM_01   = VM_VER | 0x0001, // VM version "01" in hex

        // Supported VM version range
        // As of now only VM_01 is supported
        VM_SUPPORTED_HIGH_VER = 0x01,
        VM_NOT_SUPPORTED = 0x00,

        VER_MASK= 0xffff,          // Just version
        INVALID_VER = 0,           // Invalid initialization value
    };

//  Output data types
    enum OutputType
    {
        UINT8_BY2         =0x0001,   // uint8_t  [2]
        UINT8_BY2_BY2     =0x0002,   // uint8_t  [2][2]
        UINT8_BY2_BY2_BY4 =0x0003,   // uint8_t  [2][2][4]
        UINT32_BY2        =0x0004,   // uint32_t [2]
        UINT32_BY2_BY2    =0x0005,   // uint32_t [2][2]
        UINT64            =0x0006,   // uint64_t
        UINT8             =0x0007,   // uint8_t  
    };
    const uint16_t OUTPUT_TYPE_MASK = 0x00FF;

    typedef uint8_t  UINT8_BY2_t [2];
    typedef uint8_t  UINT8_BY2_BY2_t [2][2];
    typedef uint8_t  UINT8_BY2_BY2_BY4_t [2][2][4];
    typedef uint32_t UINT32_BY2_t [2];
    typedef uint32_t UINT32_BY2_BY2_t [2][2];
    typedef uint64_t UINT64_t;
    typedef uint8_t UINT8_t;

    //  Special processing
    //  Rules:
    //  Values for "All types" needs to be unquie for all output types
    //  Values for a particular type only need to be unique within that type
    enum SpecialProcessing
    {
    // for All Types
        DEFAULT_VALUE  = 0x1000,
        UINT8_DATA     = 0x2000,  // The vpd data size
        UINT16_DATA    = 0x3000,  // The vpd data size
        UINT32_DATA    = 0x4000,  // The vpd data size
        // All the "all types" need to be within this mask
        SPECIAL_DATA_MASK  = 0xF000,

    // for UINT8_BY2 (all mutually exclusive)
        XLATE_SLEW     = 0x0100,
        HIGH_NIBBLE    = 0x0200,
        LOW_NIBBLE     = 0x0300,
        PORT00         = 0x0400,
        PORT11         = 0x0500,

    // for UINT8_BY2_BY2 (all mutually exclusive)
        XLATE_DRAM_RON = 0x0100,
        BOTH_DIMMS     = 0x0200,

    // for UNIT8_BY2_BY2_BY4 (all mutually exclusive)
        XLATE_RTT_NOM  = 0x0100,
        XLATE_RTT_WR   = 0x0200,
        XLATE_RTT_PARK   = 0x0400,

    // for UINT32_BY2 (all mutually exclusive)
        XLATE_RD_VREF  = 0x0100,
        XLATE_WR_VREF  = 0x0200,
    //  UINT8_DATA supported
    //  UINT16_DATA supported

    // for UINT32_BY2_BY2
    //  UINT8_DATA supported
    //  UINT16_DATA supported

    // for UINT64
        MERGE          = 0x0100,

    //  all of the "for output type" enums need to be within this mask
        SPECIAL_XLATE_MASK = 0x0F00,

    //  All enums need to be within this mask. The lower byte is the offset.
        SPECIAL_PROCESSING_MASK = 0xFF00,
    };

//  VM keyword defination
    struct MBvpdVMKeyword
    {
        uint8_t              iv_version;
        uint8_t              iv_systemType;
        uint8_t              iv_systemType_ext;
        uint8_t              iv_dataVersion;
    public:
	MBvpdVMKeyword() : iv_version(0),iv_systemType(0),
			   iv_systemType_ext(0),iv_dataVersion(0) {};
	operator uint32_t() const {
		return iv_version << 24 | iv_systemType << 16 |
			iv_systemType_ext << 8 | iv_dataVersion;
	}
    };
//  Attribute definition
    struct MBvpdAttrDef
    {
        AttributeId          iv_attrId;
        DimmType             iv_dimmType;
        VpdVersion           iv_version;
        fapi::MBvpdKeyword   iv_keyword;
        uint8_t              iv_offset;
        uint16_t             iv_outputType;
        uint32_t             iv_defaultValue;
    };

// Declare global table and size
extern const MBvpdAttrDef g_MBVPD_ATTR_DEF_array [];
extern const uint32_t g_MBVPD_ATTR_DEF_array_size;

} // getAttrData namespace
} // fapi namespace

// Template class that is specialized for each attribute specifying it's type
template<const fapi::AttributeId A>
    class MBvpdAttrDataType { };

// Term Data attribute specializations
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_DRAM_RON>
    { public: typedef fapi::ATTR_VPD_DRAM_RON_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_DRAM_RTT_NOM>
    { public: typedef fapi::ATTR_VPD_DRAM_RTT_NOM_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_DRAM_RTT_WR>
    { public: typedef fapi::ATTR_VPD_DRAM_RTT_WR_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_ODT_RD>
    { public: typedef fapi::ATTR_VPD_ODT_RD_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_ODT_WR>
    { public: typedef fapi::ATTR_VPD_ODT_WR_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_DIMM_RCD_IBT>
    { public: typedef fapi::ATTR_VPD_DIMM_RCD_IBT_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_DIMM_RCD_OUTPUT_TIMING>
    { public: typedef fapi::ATTR_VPD_DIMM_RCD_OUTPUT_TIMING_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_RD_VREF>
    { public: typedef fapi::ATTR_VPD_CEN_RD_VREF_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_DRAM_WR_VREF>
    { public: typedef fapi::ATTR_VPD_DRAM_WR_VREF_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_DRAM_WRDDR4_VREF>
    { public: typedef fapi::ATTR_VPD_DRAM_WRDDR4_VREF_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_RCV_IMP_DQ_DQS>
    { public: typedef fapi::ATTR_VPD_CEN_RCV_IMP_DQ_DQS_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_DRV_IMP_DQ_DQS>
    { public: typedef fapi::ATTR_VPD_CEN_DRV_IMP_DQ_DQS_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_DRV_IMP_CNTL>
    { public: typedef fapi::ATTR_VPD_CEN_DRV_IMP_CNTL_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_DRV_IMP_ADDR>
    { public: typedef fapi::ATTR_VPD_CEN_DRV_IMP_ADDR_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_DRV_IMP_CLK>
    { public: typedef fapi::ATTR_VPD_CEN_DRV_IMP_CLK_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_DRV_IMP_SPCKE>
    { public: typedef fapi::ATTR_VPD_CEN_DRV_IMP_SPCKE_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_SLEW_RATE_DQ_DQS>
    { public: typedef fapi::ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_SLEW_RATE_CNTL>
    { public: typedef fapi::ATTR_VPD_CEN_SLEW_RATE_CNTL_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_SLEW_RATE_ADDR>
    { public: typedef fapi::ATTR_VPD_CEN_SLEW_RATE_ADDR_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_SLEW_RATE_CLK>
    { public: typedef fapi::ATTR_VPD_CEN_SLEW_RATE_CLK_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_SLEW_RATE_SPCKE>
    { public: typedef fapi::ATTR_VPD_CEN_SLEW_RATE_SPCKE_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CKE_PRI_MAP>
    { public: typedef fapi::ATTR_VPD_CKE_PRI_MAP_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CKE_PWR_MAP>
    { public: typedef fapi::ATTR_VPD_CKE_PWR_MAP_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_RLO>
    { public: typedef fapi::ATTR_VPD_RLO_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_WLO>
    { public: typedef fapi::ATTR_VPD_WLO_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_GPO>
    { public: typedef fapi::ATTR_VPD_GPO_Type Type; };

// Phase Rotator attribute specializations
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M0_CLK_P0>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M0_CLK_P0_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M0_CLK_P1>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M0_CLK_P1_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M1_CLK_P0>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M1_CLK_P0_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M1_CLK_P1>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M1_CLK_P1_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_A0>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_A0_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_A1>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_A1_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_A2>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_A2_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_A3>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_A3_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_A4>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_A4_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_A5>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_A5_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_A6>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_A6_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_A7>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_A7_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_A8>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_A8_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_A9>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_A9_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_A10>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_A10_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_A11>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_A11_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_A12>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_A12_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_A13>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_A13_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_A14>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_A14_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_A15>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_A15_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_BA0>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_BA0_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_BA1>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_BA1_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_BA2>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_BA2_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_CASN>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_CASN_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_RASN>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_RASN_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_WEN>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M_CMD_WEN_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M_PAR>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M_PAR_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M_ACTN>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M_ACTN_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE0>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE0_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE1>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE1_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE2>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE2_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE3>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE3_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN0>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN0_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN1>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN1_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN2>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN2_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN3>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN3_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_ODT0>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_ODT0_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_ODT1>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_ODT1_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE0>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE0_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE1>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE1_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE2>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE2_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE3>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE3_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN0>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN0_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN1>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN1_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN2>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN2_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN3>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN3_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_ODT0>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_ODT0_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_ODT1>
    { public: typedef fapi::ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_ODT1_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_MR_VERSION_BYTE>
    { public: typedef fapi::ATTR_VPD_MR_VERSION_BYTE_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_MR_DATA_CONTROL_BYTE>
    { public: typedef fapi::ATTR_VPD_MR_DATA_CONTROL_BYTE_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_PERIODIC_MEMCAL_MODE_OPTIONS>
    { public: typedef fapi::ATTR_VPD_PERIODIC_MEMCAL_MODE_OPTIONS_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_MT_VERSION_BYTE>
    { public: typedef fapi::ATTR_VPD_MT_VERSION_BYTE_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_MT_DATA_CONTROL_BYTE>
    { public: typedef fapi::ATTR_VPD_MT_DATA_CONTROL_BYTE_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_DRAM_RTT_PARK>
    { public: typedef fapi::ATTR_VPD_DRAM_RTT_PARK_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_RD_CTR_WINDAGE_OFFSET>
    { public: typedef fapi::ATTR_VPD_RD_CTR_WINDAGE_OFFSET_Type Type; };


// There is no ATTR_VPD_DRAM_2N_MODE attribute. getMBvpdAttr is called
// directly using ATTR_VPD_DRAM_2N_MODE_ENABLED as an ID.
//template<>class MBvpdAttrDataType<fapi::ATTR_VPD_DRAM_2N_MODE>
//    { public: typedef fapi::ATTR_VPD_DRAM_2N_MODE Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_TSYS_ADR>
    { public: typedef fapi::ATTR_VPD_TSYS_ADR_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_TSYS_DP18>
    { public: typedef fapi::ATTR_VPD_TSYS_DP18_Type Type; };
template<>class MBvpdAttrDataType<fapi::ATTR_VPD_POWER_CONTROL_CAPABLE>
    { public: typedef fapi::ATTR_VPD_POWER_CONTROL_CAPABLE_Type Type; };


// Template function that checks that the type is as expected.
// This can be optionally called before calling the main HWP in order
// to check for the expected type at compile-time.
template<const fapi::AttributeId ATTR>
    inline void checkAttrDataType
        (typename MBvpdAttrDataType<ATTR>::Type &) {}

/* example
#define ATTR_VPD_DRAM_RON_GETMACRO(ID, PTARGET, VAL)\
   (checkAddrDataType<fapi::ATTR_VPD_DRAM_RON>(VAL), \
   fapi::platAttrSvc::fapiPlatGetAddrData\
      (PTARGET, fapi::ATTR_VPD_DRAM_RON , VAL, sizeof(VAL)))
*/
// The complilation will fail unless the output variable matches the type
// in the per attribute template specialization. The error messages will
// include text related to template MBvpdAttrDataSize not be able to convert
// the incorrect output variable's type to the expected type.
//
// There will be an additonal error from the general attribute compliation
// checks related to fapiCheckIdType if the output type does not match
// any of the expected types
//
// The inline function checkTermData will be optimized out by the compiler.

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*getMBvpdAttr_FP_t)
     (const fapi::Target &, const fapi::AttributeId,
      void *, const size_t);



extern "C"
{
/**
 * @brief get Attribute Data from MBvpd
 *
 * @param[in]  i_mbaTarget       -   mba target
 * @param[in]  i_attr            -   Attribute ID
 * @param[out] o_pVal            -   pointer to variable typed output variable
 * @param[in]  i_valSize         -   size of output variable
 *
 * @return fapi::ReturnCode -   FAPI_RC_SUCCESS if success,
 *                              relevant error code for failure.
 */
fapi::ReturnCode getMBvpdAttr(
                              const fapi::Target   &i_mbaTarget,
                              const fapi::AttributeId i_attr,
                              void  * o_pVal,
                              const size_t i_valSize);

/**
 *  @brief Find dimm info; parent, type, position
 */
fapi::ReturnCode findDimmInfo (const fapi::Target   & i_mbaTarget,
                                     fapi::Target   & o_mbTarget,
                                     uint8_t        & o_pos,
                                     fapi::getAttrData::DimmType       & o_dimmType);


}

#endif
