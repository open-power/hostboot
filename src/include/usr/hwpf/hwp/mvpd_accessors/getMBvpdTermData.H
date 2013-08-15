/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/mvpd_accessors/getMBvpdTermData.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: getMBvpdTermData.H,v 1.1 2013/05/28 11:17:29 whs Exp $

/**
 *  @file getMBvpdTermData.H
 *
 *  @brief Prototype for getMBvpdTermData() -
 *          get Termination Data from MBvpd
 */

#ifndef    _HWP_MBVPDTERMDATA_
#define    _HWP_MBVPDTERMDATA_

#include   <fapi.H>

namespace fapi
{

// The MBvpdTermData enumeration is used on the FAPI_ATTR_GET and
// getMBvpdTermData HWP accessor interface. The lower byte (6 bits)
// matches the offset of the vpd field in the MT keyword. This is a convenient
// use of the value for efficiency to index into the vpd keyword data.
//
// Most of the vpd attribute values can be returned to the requester directly.
// There are some that require special processing. For those, a
// special processing flag is added into the value. This also distinguishes
// values which have the same offset.

// special processing flags to be added on to the MBvpdTermData value
    enum MBvpdTermDataSpecial
    {
        TERM_DATA_HIGH_NIBBLE = 0x0100,     //bits 4:7 shifted right 4
        TERM_DATA_LOW_NIBBLE  = 0x0200,     //bits 0:3
    };
// mask to isolate special processing flags
const uint16_t TERM_DATA_SPECIAL_MASK = 0x0300;

// The vpd keyword changed for some of the attributes going from v5.3 of the vpd
// layout to v6.0 and after. There is a work around to use the previous
// keyword based on the vpd version.
// Flag to be added into MBvpdTermData value for attributes that need to be
// checked for work around.
const uint8_t TERM_DATA_CHK60 = 0x40;  // check version for keyword to use

// There are multiple types of output values. The type is shown in the comment.
// The base offset value is incremented based on the vpd data type.
    enum MBvpdTermData
    {
       TERM_DATA_DRAM_RON =                0x00,  //uint8_t [2][2]
       TERM_DATA_DRAM_RTT_NOM =            0x02,  //uint8_t [2][2][4]
       TERM_DATA_DRAM_RTT_WR =             0x0a,  //uint8_t [2][2][4]
       TERM_DATA_ODT_RD =                  0x12,  //uint8_t [2][2][4]
       TERM_DATA_ODT_WR =                  0x1a,  //uint8_t [2][2][4]
       TERM_DATA_CEN_RD_VREF =             0x22,  //uint32_t [2]
       TERM_DATA_DRAM_WR_VREF =            0x26,  //uint32_t [2]
       TERM_DATA_DRAM_WRDDR4_VREF =        0x2a,  //uint8_t [2]
       TERM_DATA_CEN_RCV_IMP_DQ_DQS =      0x2b,  //uint8_t [2]
       TERM_DATA_CEN_DRV_IMP_DQ_DQS =      0x2c,  //uint8_t [2]
       TERM_DATA_CEN_DRV_IMP_CNTL =        0x2d,  //uint8_t [2]
       TERM_DATA_CEN_DRV_IMP_ADDR =        0x2e,  //uint8_t [2]
       TERM_DATA_CEN_DRV_IMP_CLK =         0x2f,  //uint8_t [2]
       TERM_DATA_CEN_DRV_IMP_SPCKE =       0x30,  //uint8_t [2]
       TERM_DATA_CEN_SLEW_RATE_DQ_DQS =    0x31,  //uint8_t [2]
       TERM_DATA_CEN_SLEW_RATE_CNTL =      0x32,  //uint8_t [2]
       TERM_DATA_CEN_SLEW_RATE_ADDR =      0x33,  //uint8_t [2]
       TERM_DATA_CEN_SLEW_RATE_CLK =       0x34,  //uint8_t [2]
       TERM_DATA_CEN_SLEW_RATE_SPCKE =     0x35,  //uint8_t [2]
// TERM_DATA_CKE_PRI_MAP is a uint16 in the vpd data. It is returned as
// as a uint32. The offset is incremented by only 2 to get the next vpd value.
       TERM_DATA_CKE_PRI_MAP =             0x36,  //uint32_t [2]
       TERM_DATA_CKE_PWR_MAP =             0x38,  //uint32_t [2]
       TERM_DATA_RLO = 0x3c|TERM_DATA_CHK60|TERM_DATA_HIGH_NIBBLE, //uint8_t[2]
       TERM_DATA_WLO = 0x3c|TERM_DATA_CHK60|TERM_DATA_LOW_NIBBLE,  //uint8_t[2]
       TERM_DATA_GPO = 0x3d|TERM_DATA_CHK60,    //uint8_t[2]
    };
}
// The max base offset value is 0x3e. The MT keyword is 255 bytes.
// There is only room for 63 attributes per port. There are 4 x  64 byte
// sections, but the last one is 1 byte short. See diagram below...
const uint8_t TERM_DATA_OFFSET_MASK = 0x003f; //mask attr to isolate base offset

// Template class that is specialized for each attribute specifying it's type
template<const fapi::MBvpdTermData A>
    class MBvpdTermDataSize { };
template<>class MBvpdTermDataSize<fapi::TERM_DATA_DRAM_RON>
    { public: typedef uint8_t Type[2][2]; };
template<>class MBvpdTermDataSize<fapi::TERM_DATA_DRAM_RTT_NOM>
    { public: typedef uint8_t Type[2][2][4]; };
template<>class MBvpdTermDataSize<fapi::TERM_DATA_DRAM_RTT_WR>
    { public: typedef uint8_t Type[2][2][4]; };
template<>class MBvpdTermDataSize<fapi::TERM_DATA_ODT_RD>
    { public: typedef uint8_t Type[2][2][4]; };
template<>class MBvpdTermDataSize<fapi::TERM_DATA_ODT_WR>
    { public: typedef uint8_t Type[2][2][4]; };
template<>class MBvpdTermDataSize<fapi::TERM_DATA_CEN_RD_VREF>
    { public: typedef uint32_t Type[2]; };
template<>class MBvpdTermDataSize<fapi::TERM_DATA_DRAM_WR_VREF>
    { public: typedef uint32_t Type[2]; };
template<>class MBvpdTermDataSize<fapi::TERM_DATA_DRAM_WRDDR4_VREF>
    { public: typedef uint8_t Type[2]; };
template<>class MBvpdTermDataSize<fapi::TERM_DATA_CEN_RCV_IMP_DQ_DQS>
    { public: typedef uint8_t Type[2]; };
template<>class MBvpdTermDataSize<fapi::TERM_DATA_CEN_DRV_IMP_DQ_DQS>
    { public: typedef uint8_t Type[2]; };
template<>class MBvpdTermDataSize<fapi::TERM_DATA_CEN_DRV_IMP_CNTL>
    { public: typedef uint8_t Type[2]; };
template<>class MBvpdTermDataSize<fapi::TERM_DATA_CEN_DRV_IMP_ADDR>
    { public: typedef uint8_t Type[2]; };
template<>class MBvpdTermDataSize<fapi::TERM_DATA_CEN_DRV_IMP_CLK>
    { public: typedef uint8_t Type[2]; };
template<>class MBvpdTermDataSize<fapi::TERM_DATA_CEN_DRV_IMP_SPCKE>
    { public: typedef uint8_t Type[2]; };
template<>class MBvpdTermDataSize<fapi::TERM_DATA_CEN_SLEW_RATE_DQ_DQS>
    { public: typedef uint8_t Type[2]; };
template<>class MBvpdTermDataSize<fapi::TERM_DATA_CEN_SLEW_RATE_CNTL>
    { public: typedef uint8_t Type[2]; };
template<>class MBvpdTermDataSize<fapi::TERM_DATA_CEN_SLEW_RATE_ADDR>
    { public: typedef uint8_t Type[2]; };
template<>class MBvpdTermDataSize<fapi::TERM_DATA_CEN_SLEW_RATE_CLK>
    { public: typedef uint8_t Type[2]; };
template<>class MBvpdTermDataSize<fapi::TERM_DATA_CEN_SLEW_RATE_SPCKE>
    { public: typedef uint8_t Type[2]; };
template<>class MBvpdTermDataSize<fapi::TERM_DATA_CKE_PRI_MAP>
    { public: typedef uint32_t Type[2]; };
template<>class MBvpdTermDataSize<fapi::TERM_DATA_CKE_PWR_MAP>
    { public: typedef uint32_t Type[2]; };
template<>class MBvpdTermDataSize<fapi::TERM_DATA_RLO>
    { public: typedef uint8_t Type[2]; };
template<>class MBvpdTermDataSize<fapi::TERM_DATA_WLO>
    { public: typedef uint8_t Type[2]; };
template<>class MBvpdTermDataSize<fapi::TERM_DATA_GPO>
    { public: typedef uint8_t Type[2]; };

// Template function that checks that the type is as expected.
// This can be optionally called before calling the main HWP in order
// to check for the expected type at compile-time.
template<const fapi::MBvpdTermData ATTR>
    inline void checkTermDataType
        (typename MBvpdTermDataSize<ATTR>::Type &) {}
/* example
#define ATTR_EFF_DRAM_RON_GETMACRO(ID, PTARGET, VAL)\
   (checkTermDataType<fapi::TERM_DATA_DRAM_RON>(VAL), \
   fapi::platAttrSvc::fapiPlatGetTermData\
      (PTARGET, fapi::TERM_DATA_DRAM_RON , VAL, sizeof(VAL)))
*/
// The complilation will fail unless the output variable matches the type
// in the per attribute template specialization. The error messages will
// include text related to template MBvpdTermDataSize not be able to convert
// the incorrect output variable's type to the expected type.
//
// There will be an additonal error from the general attribute compliation
// checks related to fapiCheckIdType if the output type does not match
// any of the expected types
//
// The inline function checkTermData will be optimized out by the compiler.

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*getMBvpdTermData_FP_t)
     (const fapi::Target &, const fapi::MBvpdTermData,
      void *, const uint32_t);

extern "C"
{
/**
 * @brief get Termination Data from cvpd record VSPD keyword MT
 *
 * The Termination Data attributes are retrieved from cvpd record VSPD
 * keyword MT.
 * There are two mba per memory buffer: position 0 and position 1.
 * There are two ports for each mba. There are 4 sets of Termination
 * Data attributes.
 *
 * cpvd record VSPD keyword MT
 * -----------------------------------
 * | mba position 0                  |
 * |  -----------------------------  |
 * |  | port 0  (Port A) 64 bytes |  |
 * |  |---------------------------|  |
 * |  | port 1  (Port B) 64 bytes |  |
 * |  -----------------------------  |
 * |---------------------------------|
 * | mba postion 1                   |
 * |  -----------------------------  |
 * |  | port 0  (Port C) 64 bytes |  |
 * |  |---------------------------|  |
 * |  | port 1  (Port D) 63 bytes |  |
 * |  -----------------------------  |
 * -----------------------------------
 *
 * The Termination Data attributes have multiple types. The output value
 * is a general void * to handle the multiple attributes types. The expected
 * output variable type is shown in the attribute enumeration comment and in
 * the MBvpdTermDataSize template.
 * An error will be returned if output size does not match the size of the
 * expected output type's size.
 *
 * @param[in]  i_mbaTarget       -   mba target
 * @param[in]  i_attr            -   Termination Data attribute enumerator
 * @param[out] o_pVal            -   pointer to variable typed output variable
 * @param[in]  i_valSize         -   size of output variable
 *
 * @return fapi::ReturnCode -   FAPI_RC_SUCCESS if success,
 *                              relevant error code for failure.
 */
fapi::ReturnCode getMBvpdTermData(
                              const fapi::Target   &i_mbaTarget,
                              const fapi::MBvpdTermData i_attr,
                              void  * o_pVal,
                              const uint32_t i_valSize);

}

#endif
