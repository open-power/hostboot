/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/accessors/p9_get_mem_vpd_keyword.H $  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

///
/// @file p9_get_mem_vpd_keyword.H
/// @brief Return mem vpd keyword based on VPDInfo
///

// *HWP HWP Owner: Dan Crowell <dcrowell@us.ibm.com>
// *HWP HWP Backup: Matt Light <mklight@us.ibm.com>
// *HWP FW Owner: Dan Crowell <dcrowell@us.ibm.com>
// *HWP Team:
// *HWP Level: 3
// *HWP Consumed by: Cronus, FSP, HB

#ifndef _GET_MEM_VPD_KEYWORD_H_
#define _GET_MEM_VPD_KEYWORD_H_

#include <fapi2.H>
#include <fapi2_vpd_access.H>

namespace fapi2
{
/// vpd keyword to be read based on input parameters and MR/MT mapping.
/// For example, X0...XZ for MT or J0...JZ for MR vpd data.
/// Return as a string for convenient debug traces.
enum
{
    KEYWORD_BYTE_SIZE       = 2,
};
typedef char keywordName_t [KEYWORD_BYTE_SIZE + 1];

/// Structure for the layout of the MR and MT mapping keyword
enum mappingKeywordEnum
{
    MAPPING_LAYOUT_VERSION  = 1,
    MAPPING_LAYOUT_INVALID  = 0xff,
    MAPPING_LAYOUT_LAST     = 0x00,
    MAPPING_LAYOUT_MAXROWS  = 38,  //header,0..9,A..Z,end mark

    MAPPING_LAYOUT_MCA0         = 0x8000, //mca position 0
    MAPPING_LAYOUT_MCA15        = 0x0001, //mca position 15
    MAPPING_LAYOUT_DIMM0_RANK0  = 0x80,   //Dimm 0 rank count = 0
    MAPPING_LAYOUT_DIMM0_RANK4  = 0x10,   //Dimm 0 rank count = 4
    MAPPING_LAYOUT_DIMM1_RANK0  = 0x08,   //Dimm 1 rank count = 0
    MAPPING_LAYOUT_DIMM1_RANK4  = 0x01,   //Dimm 1 rank count = 4
    MAPPING_LAYOUT_FREQ0        = 0x08,   //Frequency index 0
    MAPPING_LAYOUT_FREQ3        = 0x01,   //Frequency index 3
};
union mappingKeywordRow
{
    struct //first entry is version
    {
        uint8_t  layoutVersion;
        uint16_t headerReserved;
        uint16_t dataVersion;
    } __attribute__((packed));
    struct //criteria mapping entries
    {
        uint8_t mcaMaskMSB;  // mca mask high order byte
        uint8_t mcaMaskLSB;  // mca mask low order byte
        uint8_t rankMask;    // high nibble rank 0, low nibble rank 1
        uint8_t freqMask;    // high nibble reserved
        char    keywordChar; // 0..9,A..Z
    } __attribute__((packed));
};
}

typedef fapi2::ReturnCode (*p9_get_mem_vpd_keyword_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_MCA>&,
    const fapi2::VPDInfo<fapi2::TARGET_TYPE_MCA>&,
    const uint8_t*,
    const size_t,
    fapi2::keywordName_t&);
extern "C"
{

    /// @brief Return VPD keyword based on MCA, VPDInfo, and MR/MT mapping
    /// The MR and MT keyword contains a header followed by a table. Each
    /// row in the table has criteria to select a vpd keyword.
    ///
    /// 0         1         2         3         4
    /// mmmm.mmmm.mmmm.mmmm.rrrr.ssss.xxxx.ffff.dddd.dddd
    ///
    /// m...m       mca position
    ///             0x8000 mca position 0
    ///             0x0001 mca position 15
    /// rrrr        dimm 0 rank count = 0,1,2,4
    ///             0x80 rank count 0
    ///             0x10 rank count 4
    /// ssss        dimm 1 rank count = 0,1,2,4
    ///             0x08 rank count 0
    ///             0x01 rank count 4
    /// ffff        frequency index from ATTR_MEMVPD_FREQS_MHZ
    ///             0x08 index 0
    ///             0x01 index 3
    /// dddd        second char in keyword name
    ///
    /// All the configurations for a particular keyword are 'OR'ed into the
    /// row for that keyword.
    /// Rows with all 0's do not need to be included. The last row has dddd = 0.
    /// Unsupported configurations can be mapped to dddd = 0xff.
    ///
    /// Note: this interface should not be called directly by HWPs,
    /// it is provided for platform use behind the getVPD() interface.
    ///
    /// @param[in]  i_target, the MCA
    /// @param[in]  i_vpd_info, vpd criteria
    /// @param[in]  i_pMapping, MR or MT keyword data
    /// @param[in]  i_mappingSize, size of i_pMapping buffer
    /// @param[out] o_keywordName, keyword with vpd
    /// @return FAPI2_RC_SUCCESS iff ok
    fapi2::ReturnCode p9_get_mem_vpd_keyword (
        const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const fapi2::VPDInfo<fapi2::TARGET_TYPE_MCA>& i_vpd_info,
        const uint8_t*               i_pMapping,
        const size_t                 i_mappingSize,
        fapi2::keywordName_t& o_keywordName);

}

#endif
