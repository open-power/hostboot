/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/fapi2/include/collect_reg_ffdc.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
#ifndef FAPI2_COLLECT_REG_FFDC_H_
#define FAPI2_COLLECT_REG_FFDC_H_
#include <stdint.h>
#include <vector>
#include <hw_access.H>
#include <ffdc.H>
#include <hwp_error_info.H>
#include <error_info_defs.H>
#include <buffer.H>
#include <target.H>
#include <return_code.H>
#include <fapi2_attribute_service.H>
#include <plat_trace.H>


namespace fapi2
{

// in generated file collect_reg_ffdc_regs.C
void getAddressData(const fapi2::HwpFfdcId i_ffdcId,
                    std::vector<uint64_t>& o_scomAddresses ,
                    std::vector<uint32_t>& o_cfamAddresses ,
                    uint32_t& o_ffdcSize );


///
/// @brief converts value to a type to enable overloading based on values
///
/// @tparam[in]  v - value to create to a unique type
///
/// @return  v - value.
///
template <int v>
struct toType
{
    enum { value = v };
};

///
/// @class TargetPosition
///
///  helper class to get the position for the passed in chip
///  or chiplet.
///
///
template < TargetType T, bool isChiplet = T& TARGET_TYPE_CHIPLETS >
class TargetPosition
{

    public:
        ///
        /// @brief constructor
        ///
        TargetPosition(const Target<T>& t)
            : iv_targ(t)
        {};

        ///
        /// @brief Return position of either a chip or chiplet target
        ///
        /// @param[out]  o_pos - position of chip/chiplet target
        /// @param[in]   is_chiplet - converted to type for overloading
        ///                           to correct function call.
        ///
        /// @return fapi2::ReturnCode. FAPI_RC_SUCCESS, or failure value.
        ///
        fapi2::ReturnCode getPosition( uint32_t& o_pos)
        {
            return getPosition(o_pos, toType<isChiplet>());
        }

    private:
        ///
        /// @brief  return target position for chiplet
        ///
        /// @param[out] o_pos - chiplet position
        /// @param[in]  is_chiplet = true
        ///
        /// @return fapi2::ReturnCode. FAPI_RC_SUCCESS, or failure value.
        ///
        fapi2::ReturnCode getPosition(uint32_t& o_pos, toType<true>)
        {
            fapi2::ReturnCode l_rc;

            uint8_t l_chipletPos = 0;

            l_rc = FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, iv_targ, l_chipletPos);

            if (l_rc)
            {
                FAPI_ERR("collect_reg_ffdc.C: Error getting chiplet position");
                l_chipletPos = 0xFF;
            }

            o_pos = static_cast<uint32_t>(l_chipletPos);

            return l_rc;
        }

        ///
        /// @brief  return target position for chip
        ///
        /// @param[out] o_pos - chiplet position
        /// @param[in]  is_chiplet = false
        ///
        /// @return fapi2::ReturnCode. FAPI_RC_SUCCESS, or failure value.
        ///
        fapi2::ReturnCode getPosition(uint32_t& o_pos, toType<false>)
        {
            fapi2::ReturnCode l_rc;

            uint32_t l_Pos = 0;

            l_rc = FAPI_ATTR_GET(fapi2::ATTR_POS, iv_targ, l_Pos);

            if (l_rc)
            {
                FAPI_ERR("collect_reg_ffdc.C: Error getting position");
                l_Pos = 0xFF;
            }

            o_pos = l_Pos;

            return l_rc;
        }

        const fapi2::Target<T>& iv_targ;
};




const fapi2::TargetType TARGET_TYPE_PROC_CHIPLETS = fapi2::TARGET_TYPE_EX |
        fapi2::TARGET_TYPE_MCS |
        fapi2::TARGET_TYPE_XBUS |
        fapi2::TARGET_TYPE_CORE |
        fapi2::TARGET_TYPE_EQ |
        fapi2::TARGET_TYPE_MCA |
        fapi2::TARGET_TYPE_MCBIST |
        fapi2::TARGET_TYPE_MI |
        fapi2::TARGET_TYPE_CAPP |
        fapi2::TARGET_TYPE_DMI |
        fapi2::TARGET_TYPE_OBUS |
        fapi2::TARGET_TYPE_NV |
        fapi2::TARGET_TYPE_SBE |
        fapi2::TARGET_TYPE_PPE |
        fapi2::TARGET_TYPE_PERV |
        fapi2::TARGET_TYPE_PEC |
        fapi2::TARGET_TYPE_PHB;

const fapi2::TargetType TARGET_TYPE_SCOM_TARGET = fapi2::TARGET_TYPE_PROC_CHIP |
        fapi2::TARGET_TYPE_MEMBUF_CHIP |
        fapi2::TARGET_TYPE_EX |
        fapi2::TARGET_TYPE_MBA |
        fapi2::TARGET_TYPE_MCS |
        fapi2::TARGET_TYPE_XBUS |
        fapi2::TARGET_TYPE_ABUS |
        fapi2::TARGET_TYPE_L4 |
        fapi2::TARGET_TYPE_CORE |
        fapi2::TARGET_TYPE_EQ |
        fapi2::TARGET_TYPE_MCA |
        fapi2::TARGET_TYPE_MCBIST |
        fapi2::TARGET_TYPE_MI |
        fapi2::TARGET_TYPE_DMI |
        fapi2::TARGET_TYPE_OBUS |
        fapi2::TARGET_TYPE_NV |
        fapi2::TARGET_TYPE_SBE |
        fapi2::TARGET_TYPE_PPE |
        fapi2::TARGET_TYPE_PERV |
        fapi2::TARGET_TYPE_PEC |
        fapi2::TARGET_TYPE_PHB;



template< TargetType T>
inline fapi2::Target<fapi2::TARGET_TYPE_CHIPS>
getChipTarget(const fapi2::Target<T>& i_target)
{
    return getChipTarget(i_target);
}

// handle membuf/proc targets
inline fapi2::Target<fapi2::TARGET_TYPE_CHIPS>
getChipTarget(const fapi2::Target<fapi2::TARGET_TYPE_CHIPS>& i_target)
{
    return i_target;
}

// handle dimms
inline fapi2::Target<fapi2::TARGET_TYPE_CHIPS>
getChipTarget(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    return i_target.getParent<fapi2::TARGET_TYPE_MBA>().getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();
}

// everything else is w/proc chip?
inline fapi2::Target<fapi2::TARGET_TYPE_CHIPS>
getChipTarget(const
              fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIPLETS>& i_target)
{
    return i_target.getParent<fapi2::TARGET_TYPE_CHIPS>();
}

template < TargetType T>
fapi2::Target<fapi2::TARGET_TYPE_SCOM_TARGET>
getScomTarget(const fapi2::Target<T>& i_target)
{
    return i_target;
}

inline fapi2::Target<fapi2::TARGET_TYPE_SCOM_TARGET>
getScomTarget(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    return i_target.getParent<fapi2::TARGET_TYPE_MBA>();
}


template<TargetType T>
class CfamReader
{
    public:
        CfamReader(const fapi2::Target<T>& i_target)
            : iv_target(i_target) {};

        ReturnCode
        read_register(const uint32_t address, fapi2::buffer<uint32_t>& i_buf)
        {
            FAPI_DBG("CfamReader.read_register - no-op");

            return FAPI2_RC_SUCCESS;
        }

    private:
        const fapi2::Target<T>& iv_target;
};

template<>
class CfamReader<TARGET_TYPE_MEMBUF_CHIP>
{
    public:
        CfamReader(const fapi2::Target<TARGET_TYPE_MEMBUF_CHIP>& i_target)
            : iv_target(i_target) {};

        ReturnCode read_register
        (const uint32_t address, fapi2::buffer<uint32_t>& i_buf)
        {
            FAPI_DBG("CfamReader.read_register - MEMBUF VERSION");
            return fapi2::getCfamRegister(iv_target, address, i_buf);
        }

    private:
        const fapi2::Target<TARGET_TYPE_MEMBUF_CHIP>& iv_target;
};

template<>
class CfamReader<TARGET_TYPE_PROC_CHIP>
{
    public:
        CfamReader(const fapi2::Target<TARGET_TYPE_PROC_CHIP>& i_target)
            : iv_target(i_target) {};

        ReturnCode
        read_register(const uint32_t address, fapi2::buffer<uint32_t>& i_buf)
        {
            FAPI_DBG("CfamReader.read_register - PROC VERSION");
            return fapi2::getCfamRegister(iv_target, address, i_buf);
        }

    private:
        const fapi2::Target<TARGET_TYPE_PROC_CHIP>& iv_target;
};

///
/// @class ScomReader
///
///  Class to abstract away details of reading of a scom register
///
template< TargetType T >
class ScomReader
{
    public:
        ScomReader(const fapi2::Target<T>& i_target)
            : iv_target(i_target)
        {};

        ReturnCode read_register(const uint64_t i_address,
                                 fapi2::buffer<uint64_t>& o_buf)
        {
            FAPI_DBG("ScomReader.read_register - BASE version");
            return getScom(iv_target, i_address, o_buf);
        }
    private:
        const fapi2::Target<T>& iv_target;
};

///
/// @brief class to handle reading from scom registers from generic function
///
template<>
class ScomReader<TARGET_TYPE_DIMM>
{
    public:
        ScomReader(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
            : iv_target(getScomTarget(i_target))
        {};

        ReturnCode
        read_register(const uint64_t i_address, fapi2::buffer<uint64_t>& o_buf)
        {
            FAPI_DBG("ScomReader.read_register - DIMM version");
            ReturnCode l_rc = getScom(iv_target, i_address, o_buf);
            return l_rc;
        }

    private:
        const fapi2::Target<TARGET_TYPE_SCOM_TARGET>& iv_target;

};

///
/// @brief collectRegisterData
///
///  collect all the data from a list of registers and return it to the caller
///
/// @tparam[in]  T register data size - uint32_t or uint64_t
/// @tparam[in]  U - reader object for specific data type
/// @param[in]   i_addresses - vector containing either cfam or scom addresses
/// @param[in]   i_offset    - optional offset to add to the address values
///                            passed in the vector of addresses
/// @param[out]  o_pData - pointer to the data destination
///
/// @return fapi2::ReturnCode. FAPI_RC_SUCCESS, or failure value.
///
template< typename T, class U>
ReturnCode collectRegisterData(std::vector<T>& i_addresses, U& i_reader,
                               uint32_t i_offset, uint8_t* o_pData)
{
    FAPI_DBG("collectRegisterData -> address count: 0x%lx", i_addresses.size());

    T l_data = 0;

    ReturnCode l_rc = FAPI2_RC_SUCCESS;

    for( auto address : i_addresses )
    {
        fapi2::buffer<T> l_buf;

        const T l_address = address + i_offset;

        l_rc = i_reader.read_register(l_address, l_buf);

        if(l_rc)
        {
            l_data = 0xbaddbadd;
        }
        else
        {
            l_data = l_buf();
        }

        memcpy(o_pData, &l_data, sizeof(T));

        o_pData += sizeof(T);

    }

    return l_rc;
}


///
/// @brief read registers
///
///  Template function to allow reading either scom and cfam data from registers
///  for a given target
///
/// @tparam[in]  T - fapi2::TargetType
/// @param[out]  o_pData - pointer to a location to store register data
/// @param[in]   i_cfamAddresses - vector of cfam addresses to read
/// @param[in]   i_scomAddresses - vector of scom addresses to read
/// @param[i/o]  input/output parm description
///
/// @return fapi2::ReturnCode. FAPI_RC_SUCCESS, or failure value.
///
template<fapi2::TargetType T>
void readRegisters(const fapi2::Target<T>& i_target,
                   uint8_t* o_pData,
                   std::vector<uint32_t> i_cfamAddresses,
                   std::vector<uint64_t> i_scomAddresses,
                   uint32_t i_childOffset = 0)
{
    FAPI_DBG("readRegisters()");

    // create an object to read Cfam registers
    CfamReader<T> l_cfamReader(i_target);

    // Create an object to read scom registers
    ScomReader<T> l_scomReader(i_target);

    // read data from the cfam registers if required
    ReturnCode rc = collectRegisterData<uint32_t,
               CfamReader<T> >(i_cfamAddresses, l_cfamReader,
                               i_childOffset, o_pData);

    if(rc)
    {
        FAPI_ERR("An error occured when reading from the cfam registers skipping..");
    }

    // read data from Scom registers if present
    rc = collectRegisterData<uint64_t,
    ScomReader<T> >(i_scomAddresses, l_scomReader,
                    i_childOffset, o_pData);

    if(rc)
    {
        FAPI_ERR("An error occured when reading the scom registers..");
    }

    FAPI_DBG("readRegisters() exit");
}

///
/// @brief Collect register data for child targets
///
/// @tparam[in]  C - child target type
/// @tparam[in]  T - parent target type
/// @param[in]   i_parent - fapi2::Target
/// @param[in]   i_childState - fapi2::TargetState for child targets
/// @param[in]   i_ffdcId - type of ffdc to be collected
/// @param[out]  o_errorInfo - vector of shared pointers to fapi2::ErrorInfoFfdc type
///                            for returned register data
/// @param[in]   i_childOffsetMult - child offset for register calculations
/// @param[i/o]  input/output parm description
///
///
template<fapi2::TargetType C, fapi2::TargetType T>
void collectRegFfdc(const fapi2::ffdc_t i_parent,
                    const fapi2::TargetState i_childState,
                    const HwpFfdcId i_ffdcId,
                    std::vector<std::shared_ptr<fapi2::ErrorInfoFfdc>>& o_errorInfoFfdc,
                    uint32_t i_childOffsetMult = 0)
{

    FAPI_INF("collectRegFfdc child targets version");

    std::vector<fapi2::Target<C> > l_targets;

    Target<T> l_parent =
        *(static_cast<const Target<T>*>(i_parent.ptr()));

    // Collect FFDC for functional or present chiplets of
    // type C associated with i_target - yeah, odd syntax.
    l_targets = l_parent.template getChildren<C>(i_childState);

    if (l_targets.empty())
    {
        FAPI_INF("collect_reg_ffdc.C: Error: No chiplets found. ");
        return;
    }

    std::vector<uint32_t> l_cfamAddresses;
    std::vector<uint64_t> l_scomAddresses;

    uint32_t l_ffdcSize = 0;

    // call generated code to fetch the address vectors
    getAddressData(i_ffdcId, l_scomAddresses, l_cfamAddresses, l_ffdcSize);

    uint32_t l_position = 0;

    // add the position size to the total
    l_ffdcSize += sizeof(l_position);

    // update size for each target
    l_ffdcSize += (l_ffdcSize * l_targets.size());

    uint8_t  l_pBuf[l_ffdcSize];

    uint8_t* l_pData = &l_pBuf[0];

    // grab the data for each child target
    for( auto target : l_targets)
    {
        ReturnCode l_rc =
            TargetPosition<C>(target).getPosition(l_position);

        // add chip/chiplets position to the data
        memcpy(l_pData, &l_position, sizeof(l_position));

        // advance the pointer into our buffer
        l_pData += sizeof(l_position);

        if(i_childState == TARGET_STATE_FUNCTIONAL)
        {
            FAPI_INF(" calling version for TARGET_STATE_FUNCTIONAL ");

            // since its functional just read from the child target
            readRegisters(target, l_pData, l_cfamAddresses,
                          l_scomAddresses, i_childOffsetMult);
        }
        else
        {
            // use the parent and read address + offset since the
            // child targets may not be functional
            uint32_t l_offset = i_childOffsetMult * l_position;

            FAPI_INF(" calling version for TARGET_STATE_PRESENT ");

            readRegisters(l_parent, l_pData, l_cfamAddresses,
                          l_scomAddresses, l_offset);
        }
    }

    FAPI_INF("collectRegFfdc. SCOM address count: %#lx", l_scomAddresses.size());
    FAPI_INF("collectRegFfdc. CFAM address count: %#lx", l_cfamAddresses.size());

    FAPI_DBG("size info i_ffdcId = %d, l_pBuf = %p, l_ffdcSize=%d", i_ffdcId, l_pBuf, l_ffdcSize);

    // Create a ErrorInfoFfdc object and pass it back
    o_errorInfoFfdc.push_back(std::shared_ptr<fapi2::ErrorInfoFfdc>(new ErrorInfoFfdc(i_ffdcId, l_pBuf, l_ffdcSize)));

}
///
/// @brief Collect register data for a single target
///
/// @tparam[in]  T - target type
/// @param[in]   i_target - fapi2::Target
/// @param[in]   i_ffdcId - type of ffdc to be collected
/// @param[out]  o_errorInfo - shared pointer to fapi2::ErrorInfoFfdc type
///                            for returned register data
/// @param[in]   i_childOffsetMult - child offset for register calculations
///
template<fapi2::TargetType T>
void collectRegFfdc(const fapi2::ffdc_t i_target,
                    const HwpFfdcId i_ffdcId,
                    std::vector<std::shared_ptr<fapi2::ErrorInfoFfdc> >& o_errorInfoFfdc,
                    uint32_t i_childOffset = 0)
{

    FAPI_INF("single target no children - ");

    Target<T> l_target =
        *(static_cast<const Target<T>*>(i_target.ptr()));

    std::vector<uint32_t> l_cfamAddresses;
    std::vector<uint64_t> l_scomAddresses;

    uint32_t l_ffdcSize = 0;

    // call generated code to fetch the address vectors
    getAddressData(i_ffdcId, l_scomAddresses, l_cfamAddresses, l_ffdcSize);

    uint32_t l_position = 0;

    ReturnCode l_rc = TargetPosition<T>(l_target).getPosition(l_position);

    l_ffdcSize += sizeof(l_position);

    uint8_t l_pBuf[l_ffdcSize];

    uint8_t* l_pData = &l_pBuf[0];

    // add chip/chiplets position to the data
    memcpy(l_pData, &l_position, sizeof(l_position));

    l_pData += sizeof(l_position);

    // do the work
    readRegisters(l_target, l_pData, l_cfamAddresses, l_scomAddresses,
                  i_childOffset);

    FAPI_DBG("size info i_ffdcId = %d, l_pBuf = %p, l_ffdcSize=%d", i_ffdcId, l_pBuf, l_ffdcSize);
    // Create a ErrorInfoFfdc object and add it to the Error Information
    // object of the FFDC class
    o_errorInfoFfdc.push_back(std::shared_ptr<fapi2::ErrorInfoFfdc>(new ErrorInfoFfdc(i_ffdcId, l_pBuf, l_ffdcSize)));

    FAPI_INF("collectRegFfdc. SCOM address count: 0x%lx", l_scomAddresses.size());
    FAPI_INF("collectRegFfdc. CFAM address count: 0x%lx", l_cfamAddresses.size());

    FAPI_INF("collectRegFfdc() - exit");
}

}// end namespace
#endif
