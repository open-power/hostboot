/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/sbe_utils/include/sbe_attribute_utils.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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

// @file sbe_attribute_utils.H
// @brief Classes for generating and parsing attributes blob
//
// *HWP HWP Owner: P Rajees <rajerpp1@in.ibm.com>
// *HWP HWP Backup: T Rajeswaran <rajeswgo@in.ibm.com>
// *HWP Team: SBE
// *HWP Consumed by: Cronus:HB
//

#ifndef __SBE_ATTRIBUTE_UTILS__
#define __SBE_ATTRIBUTE_UTILS__

#include "sbe_targets.H"
#include <vector>
#include <netinet/in.h>

#define ATTR_FORMAT_MAJOR_VER 0
#define ATTR_FORMAT_MINOR_VER 1

namespace sbeutil
{
/**
 * @brief  RCs which will be send as part of SBE_ATTRIBUTE_FILE_UPD_RESPONSE file,
 *         as a response to Attribute Update Chipop
 */
enum SbeAttributeUpdateRC : uint32_t
{
    SBE_ATTRIBUTE_UPDATE_RC_SUCCESS,
    SBE_ATTRIBUTE_UPDATE_TGT_TYPE_NOT_FOUND,
    SBE_ATTRIBUTE_UPDATE_RC_ATTR_NOT_FOUND,
    SBE_ATTRIBUTE_UPDATE_RC_SIZE_NOT_MATCHING,
    SBE_ATTRIBUTE_UPDATE_RC_TARGET_INST_OUT_RANGE,
    SBE_ATTRIBUTE_UPDATE_RC_ARRAY_INDEX_OUT_RANGE,
    SBE_ATTRIBUTE_UPDATE_RC_ATTR_NOT_ARRAY,
    SBE_ATTRIBUTE_UPDATE_RC_OVRD_NOT_ALLOWED,
};

/**
 * @brief  different type of files used by attribute related chipops. This type
 *         has to be inserted in attribute file transferred between host and sbe,
 *         the file type should be matching with the operation intened.
 */
enum SbeAttributeFileTypes : uint8_t
{
    SBE_ATTRIBUTE_FILE_UPDATE = 1,          // Used for sending attribute update chipop
    SBE_ATTRIBUTE_FILE_UPD_RESPONSE = 2,    // Response for attribute update chipop
    SBE_ATTRIBUTE_FILE_LIST = 3,            // Response for attribute list chipop
    SBE_ATTRIBUTE_FILE_DUMP = 4,            // One of the response type for attribute dump chipop
    SBE_ATTRIBUTE_FILE_RAW_DUMP = 5,        // One of the response type for attribute dump chipop
};

// Structures for attribute file format
struct __attribute__((packed)) HeaderEntry_t
{
    uint8_t               iv_fmtMajor;     //format major version
    uint8_t               iv_fmtMinor;     //format minor version
    SbeChipType_t         iv_chipType;     //chip type
    SbeAttributeFileTypes iv_fileType;     //file type
    uint32_t              iv_numTargets;   //number of target sections
};

struct __attribute__((packed)) TargetEntry_t
{
    fapi2::LogTargetType    iv_logTgtType;   //LOG_TARGET_TYPE
    uint8_t                 iv_instance;     //instance number; 0xFF - applicable for all instance
    uint16_t                iv_numAttrs;     //number of attributes for this target type
    uint32_t                iv_padding;
};

struct __attribute__((packed)) AttrEntry_t
{
    AttrEntry_t(uint32_t i_attrId = 0,
                uint16_t i_dataSize = 0,
                uint8_t  i_row = 0xFF,
                uint8_t  i_col = 0xFF,
                uint8_t  i_hgt = 0xFF) :
    iv_attrId(i_attrId),
    iv_dataSize(i_dataSize),
    iv_row(i_row),
    iv_col(i_col),
    iv_hgt(i_hgt)
{}

uint32_t   iv_attrId;       //attribute ID
uint16_t   iv_dataSize;     //data size
uint8_t    iv_row;          //row number
uint8_t    iv_col;          //col number
uint8_t    iv_hgt;          //height
uint8_t    iv_res;          //1-byte reserved
};

/**
 * @brief  convert an array of elements from network to host or host to network order
 *
 * @param[out]  dest        output buffer containing the values after the conversion
 * @param[in]   src         input buffer containing the values before the conversion
 * @param[in]   noOfElem    Number of elements in the input buffer
 * @param[in]   convFunc    conversion function. Can be NULL if no conversion is
 *                          required.
 *
 */
template<class T>
void copyArrayWithEndianessCorrection(T* dest,
                                      const T* src,
                                      uint16_t noOfElem,
                                      T (*convFunc)(T) = nullptr)
{
    for(uint16_t i = 0; i < noOfElem; i++)
    {
        if (convFunc == nullptr)
        {
            dest[i] = src[i];
        }
        else
        {
            dest[i] = convFunc(src[i]);
        }
    }
}

/**
 * @brief  Structure for returning attribute update failure. In case of
 *         ody_analyze_sbe_attr_response(), the failure is on the SBE side
 *         and  in case of ody_apply_sbe_attribute_data(), the failure is
 *         on the platform side. These functions will return a vector containing
 *         this structure.
 */
struct AttrError_t
{
    AttrError_t(fapi2::TargetType i_targetType,
                uint8_t           i_instance,
                uint32_t          i_attrId,
                uint32_t          i_rc) :   iv_targetType(i_targetType),
        iv_instance(i_instance),
        iv_attrId(i_attrId),
        iv_rc(i_rc)
    {};

    fapi2::TargetType   iv_targetType;  // Failed attribute's fapi2::TargetType
    uint8_t             iv_instance;    // The specific instance for which the
    // update failed.
    uint32_t            iv_attrId;      // The attributeId
    uint32_t            iv_rc;          // The return code providing the reason
    // for the failure.
};

// ---------------- Base Classes Common for Generator and Parser ---------------
class SbeAttrRowHandler
{
    public:
        SbeAttrRowHandler() :
            iv_value_ptr(0),
            iv_value_size_aligned(0)
        {}

        ~SbeAttrRowHandler();

        SbeAttrRowHandler(SbeAttrRowHandler&& i_src);

        SbeAttrRowHandler(const SbeAttrRowHandler& i_src) = delete;

        SbeAttrRowHandler& operator = (const SbeAttrRowHandler& i_src) = delete;

        /**
         * @brief  To get the attribute details
         *
         * @param[out]  o_attrEntry    Structure containing the attributeId and the
         *                             co-ordinates
         */
        fapi2::ReturnCode getAttrEntry(AttrEntry_t& o_attrEntry);

    protected:
        void setAlignedSize();

        AttrEntry_t iv_attr_entry;
        uint8_t*    iv_value_ptr;
        uint16_t    iv_value_size_aligned;
};

class SbeAttrTargetSectionHandler
{
    public:
        bool checkMatching(const SbeTarget& i_sbe_targ);

        inline void getSbeTarget(SbeTarget& o_sbe_targ) const
        {
            o_sbe_targ.iv_targ_type = iv_targ_type;
            o_sbe_targ.iv_inst_num = iv_targ_inst_num;
        }

        inline uint8_t getTargetType() const
        {
            return iv_targ_type;
        }

    protected:
        SbeAttrTargetSectionHandler():
            iv_targ_type(fapi2::LOG_TARGET_TYPE_MULTICAST),
            iv_targ_inst_num(0),
            iv_next_row_index(0)
        {}

        fapi2::LogTargetType           iv_targ_type;
        uint8_t                        iv_targ_inst_num;
        // This is needed only for parser childrens. but keeping here
        //   to make all child can be contained in the vector
        //   defined for base class.
        uint16_t                       iv_next_row_index;
        std::vector<SbeAttrRowHandler> iv_attr_rows;
};

class SbeAttributeFileHandler
{
    public:
        /**
         * @brief  To set chipTarget
         *
         * @param[in] i_chip_type sbe chip type for which this override file is
         *                         generating.
         */
        fapi2::ReturnCode setChipTarget(
            const fapi2::Target<fapi2::TARGET_TYPE_ANY_POZ_CHIP>& i_chip_targ);

    protected:
        SbeAttributeFileHandler():
            iv_chip_type(CHIP_TYPE_ANY),
            iv_file_type(SBE_ATTRIBUTE_FILE_RAW_DUMP)
        {}

        SbeChipType_t                            iv_chip_type;
        SbeAttributeFileTypes                    iv_file_type;
        std::vector<SbeAttrTargetSectionHandler> iv_target_sections;
};

// --------------- Classes for Generator Update File Generator -----------------
/**
 * @brief  Class to generate sbe attribute override pak file.
 *
 */
class SbeAttributeUpdateFileGenerator : public SbeAttributeFileHandler
{
    public:
        /**
         * @brief  Constructor
         */
        SbeAttributeUpdateFileGenerator();

        /**
         * @brief  To add one sbe attribute entry
         *
         * @param[in]  i_target      target corresponding to the attribute
         * @param[in]  i_id          ID of the attribute to be overridden
         * @param[in]  i_value       The Value of the attribute
         * @param[in]  i_size        The size of the attribute in bytes
         * @param[in]  i_row         provides the first dimension of array attribute,
         *                           0xFF means value passed has all elements of the array or
         *                           the attribute is not array type
         * @param[in]  i_col         provides the second dimension of array attribute.
         *                           0xFF means value passed has all elements of the array or
         *                           the attribute has less than 2-dim (1-D array or scalar)
         * @param[in]  i_hgt         provides the third dimension of array attribute.
         *                           0xFF means value passed has all elements of the array or
         *                           the attribute has less than 3-dim.
         *
         * @return ReturnCode for the operation.
         */
        template<fapi2::TargetType T>
        fapi2::ReturnCode addAttribute(
            const fapi2::Target<T>& i_target,
            fapi2::AttributeId      i_attr_id,
            void*                   i_val,
            uint16_t                i_size,
            uint8_t                 i_elem_size,
            uint8_t                 i_row = 0xFF,
            uint8_t                 i_col = 0xFF,
            uint8_t                 i_hgt = 0xFF)
        {
            FAPI_DBG("addAttribute Entering for target type 0x%lX", i_target.getType());
            SbeTarget l_sbe_targ;
            AttrEntry_t l_attr_entry
            {
                i_attr_id,
                i_size,
                i_row,
                i_col,
                i_hgt
            };
            uint8_t l_val[i_size];

            FAPI_TRY(convertToSbeTargetWrap(i_target, l_sbe_targ));

            if(T != fapi2::TARGET_TYPE_SYSTEM)
            {
                FAPI_ASSERT(iv_chip_type == l_sbe_targ.iv_chip_type,
                            fapi2::SBE_TARGET_ERROR(),
                            "Invalid target: iv_chip_type=%d, l_sbe_targ.iv_chip_type=%d",
                            iv_chip_type, l_sbe_targ.iv_chip_type);
            }
            else
            {
                FAPI_ASSERT(CHIP_TYPE_ANY == l_sbe_targ.iv_chip_type,
                            fapi2::SBE_TARGET_ERROR(),
                            "Invalid target: l_sbe_targ.iv_chip_type=%d",
                            l_sbe_targ.iv_chip_type);
            }

            switch(i_elem_size)
            {
                case 1:
                    sbeutil::copyArrayWithEndianessCorrection<uint8_t>(
                        (uint8_t*)l_val, (uint8_t*)i_val, (i_size / i_elem_size));
                    break;

                case 2:
                    sbeutil::copyArrayWithEndianessCorrection<uint16_t>(
                        (uint16_t*)l_val, (uint16_t*)i_val, (i_size / i_elem_size), htons);
                    break;

                case 4:
                    sbeutil::copyArrayWithEndianessCorrection<uint32_t>(
                        (uint32_t*)l_val, (uint32_t*)i_val, (i_size / i_elem_size), htonl);
                    break;

                default:
                    //As of now, SBE does not support attribute having 64-bit value
                    FAPI_ASSERT(false, fapi2::SBE_TARGET_ERROR(),
                                "i_elem_size:%d not handled", i_elem_size);
            }

            FAPI_TRY(_addAttribute(l_sbe_targ, l_attr_entry, l_val), "_addAttribute failed");

        fapi_try_exit:
            return fapi2::current_err;
        }

        /**
         * @brief  To generate attr.ovrd.pak file
         *
         * @param[in]  i_file_path   file path to be prepended to the name of the
         *                           file generated. ('i_file_path + "/attr.ovrd"')
         * @param[out] o_buf         pointer to the buffer, where the pak file is generated
         *
         * @param[in]  i_buf_size    The size of the buffer
         */
        fapi2::ReturnCode genOutput(
            const char* i_file_path,
            void* o_buf,
            const uint16_t i_buf_size);

    private:

        /**
         * @brief  utility function (without any template requirement) to add one sbe attribute entry
         *
         * @param[in]  i_sbe_targ   sbe target
         * @param[in]  i_attr_entry attribute details
         * @param[in]  i_val        pointer to the attribute value. This pointer should have size same
         *                          as mentioned in i_attr_entry.iv_dataSize
         */
        fapi2::ReturnCode _addAttribute(
            const SbeTarget& i_sbe_targ,
            const AttrEntry_t& i_attr_entry,
            void* i_val);

        /**
         * @brief  to calulate the actual buffer length required for storing attribute
         *          update file (before compressing)
         *
         * @return return the size required.
         */
        uint16_t getOutputBufSize();
};

class SbeAttrTargetSectionGen : public SbeAttrTargetSectionHandler
{
    public:

        SbeAttrTargetSectionGen(
            fapi2::LogTargetType i_targ_type,
            uint8_t              i_targ_inst_num);

        /**
         * @brief  To add an attribute to this target section
         *
         * @param[in]  i_entry  structure providing attributeId, data size, and the attributes
         *                      co-ordinate
         * @param[in]  i_val    pointer to the buffer containing attribute value
         *
         */
        void addAttribute(const AttrEntry_t& i_entry, void* i_val);

        /**
         * @brief  Add the size,in number of bytes,of this target section
         *
         * @param[out]  io_size   The updated value which includes the size of this target
         *                        section
         *
         */
        void accumulateOutputSize(uint16_t& io_size);

        /**
         * @brief To generate a blob containing this target section along with its attributes
         *
         * @param[out] o_buf   pointer to the buffer where the resultant blob will be stored
         *
         */
        void genOutput(uint8_t** io_pointer);
};

class SbeAttrRowGen : public SbeAttrRowHandler
{
    public:

        /**
         * @brief   Custom constructor to create an object of SbeAttrRowGen
         *
         * @details Creates an object containing attribute details
         */
        SbeAttrRowGen(const AttrEntry_t& i_entry, void* i_val);

        /**
         * @brief  Add the size,in number of bytes,of this attribute
         *
         * @param[out]  io_size   The updated value which includes the size of this attribute
         *
         */
        void accumulateOutputSize(uint16_t& io_size);

        /**
         * @brief To generate a blob containing this attribute
         *
         * @param[out] o_buf   pointer to the buffer where the resultant blob will be stored
         *
         */
        void genOutput(uint8_t** io_pointer);

        SbeAttrRowGen(SbeAttrRowGen&& i_src) :
            SbeAttrRowHandler(std::move(i_src))
        { }

        SbeAttrRowGen(const SbeAttrRowGen& i_src) = delete;

        SbeAttrRowGen& operator = (const SbeAttrRowGen& i_src) = delete;
};

// ------------------- Base Classes for all Parser classes ---------------------
class SbeAttrRowParser : public SbeAttrRowHandler
{
    public:
        SbeAttrRowParser() = default;

        /**
         * @brief Parse an attribute from the blob
         *
         * @param[io] io_buf    The pointer to the buffer containing the blob; At the end,
         *                      the buffer pointer will be incremented by the size of this
         *                      attribute.
         *
         * @param[io] io_size   The number of bytes to be processed. At the end, the number
         *                      bytes to be processed will be decremented by the size of this
         *                      attribute.
         *
         */
        fapi2::ReturnCode parse(uint8_t** io_buf, uint16_t* io_size);

        // Only for debugging
        void printMe() const
        {
            FAPI_DBG("this : %p", this);
            FAPI_DBG("iv_value_ptr: %p", iv_value_ptr);
            FAPI_DBG("iv_value_size_aligned: %d", iv_value_size_aligned);
            FAPI_DBG("iv_attr_entry.iv_attrId : %d", iv_attr_entry.iv_attrId);
            FAPI_DBG("iv_attr_entry.iv_dataSize : %d", iv_attr_entry.iv_dataSize);
            FAPI_DBG("iv_attr_entry.iv_row : %d", iv_attr_entry.iv_row);
            FAPI_DBG("iv_attr_entry.iv_col : %d", iv_attr_entry.iv_col);
            FAPI_DBG("iv_attr_entry.iv_hgt : %d", iv_attr_entry.iv_hgt);
        }
};

class SbeAttrTargetSectionParser : public SbeAttrTargetSectionHandler
{
    public:

        SbeAttrTargetSectionParser() = default;

        /**
         * @brief Parse a target and all its attribute
         *
         * @param[io] io_buf    The pointer to the buffer containing the blob; At the end,
         *                      the buffer pointer will be incremented by the size of this
         *                      target and its attribute
         *
         * @param[io] io_size   The number of bytes to be processed. At the end, the number
         *                      bytes to be processed will be decremented by the size of this
         *                      target and its attribute.
         *
         */
        fapi2::ReturnCode parse(uint8_t** io_buf, uint16_t* io_size);

        /**
         * @brief  to retrieve remaining response/attr row in response file
         *
         * @return number of remaining response/attr row in response file
         */
        uint16_t getRemainingRowCount();

        SbeAttrRowParser& getNextRowBase();

        // Only for debugging
        void printMe() const
        {
            FAPI_DBG("this : %p", this);
            FAPI_DBG("iv_targ_type: 0x%02X", iv_targ_type);
            FAPI_DBG("iv_targ_inst_num: %d", iv_targ_inst_num);
            FAPI_DBG("iv_next_row_index: %d", iv_next_row_index);
            FAPI_DBG("iv_attr_rows.size(): %d", iv_attr_rows.size());

            for(const auto& l_row : iv_attr_rows)
            {
                static_cast<const SbeAttrRowParser&>(l_row).printMe();
            }
        }
};

/**
 * @brief  Class to parse sbe attribute override response file.
 *
 */
class SbeAttributFileParser : public SbeAttributeFileHandler
{
    protected:
        /**
         * @brief  Constructor
         */
        SbeAttributFileParser() : iv_next_targ_index(0)
        { }

        fapi2::ReturnCode validateFileType(SbeAttributeFileTypes i_file_type);

        /**
         * @brief  to retrieve next target section in base data type
         *
         * @return  next target section
         */
        SbeAttrTargetSectionParser& getNextTargetSectionBase(SbeTarget& o_sbe_targ);

        // This is needed only for parser childrens.
        // Hence, keeping it here instad of handler class.
        uint16_t                                 iv_next_targ_index;

    public:
        /**
         * @brief  parse the input file
         *
         * @param[in] i_buf input buffer containing the attr file returned from sbe
         * @param[in] i_buf_size size of the buffer
         */
        fapi2::ReturnCode parseFile(uint8_t* i_buf, uint16_t i_size);

        /**
         * @brief  to retrieve remaining target section in response file
         *
         * @return number of remaining target section in response file
         */
        uint16_t getRemainingTargSectionCount();

        // Only for debugging
        void printMe() const
        {
            FAPI_DBG("this : %p", this);
            FAPI_DBG("iv_chip_type: 0x%02X", iv_chip_type);
            FAPI_DBG("iv_file_type: 0x%02X", iv_file_type);
            FAPI_DBG("iv_next_targ_index: %d", iv_next_targ_index);
            FAPI_DBG("iv_target_sections.size(): %d", iv_target_sections.size());

            for(const auto& l_targ : iv_target_sections)
            {
                static_cast<const SbeAttrTargetSectionParser&>(l_targ).printMe();
            }
        }
};

// ------------------ Classes for Update Response Parser -------------------------

class SbeAttrRowUpdResParser : public SbeAttrRowParser
{
    public:
        SbeAttrRowUpdResParser() = default;

        fapi2::ReturnCode getResponse(SbeAttributeUpdateRC& o_resp);
};

class SbeAttrTargetSectionUpdRespParser : public SbeAttrTargetSectionParser
{
    public:

        SbeAttrTargetSectionUpdRespParser() = default;

        SbeAttrRowUpdResParser& getNextRow();
};

class SbeAttributeUpdRespFileParser : public SbeAttributFileParser
{
    public:
        /**
         * @brief  Constructor
         */
        SbeAttributeUpdRespFileParser();

        /**
         * @brief  to retrieve next target section
         *
         * @return next target section
         */
        SbeAttrTargetSectionUpdRespParser& getNextTargetSection(SbeTarget& o_sbe_targ);

};

// ------------------ Classes for List Response Parser -------------------------

class SbeAttrRowListResParser : public SbeAttrRowParser
{
    public:
        SbeAttrRowListResParser() = default;

        /**
         * @brief  Get the attribute value
         *
         * @param[out] o_val        The output buffer containing the attribute value
         *
         * @param[in]  i_size       The size of the attribute in bytes
         *
         * @param[in]  i_elem_size  The size of an element of the attribute. In case of
         *                          scalar attributes, i_elem_size will be same as i_size
         */
        fapi2::ReturnCode getAttrValue(void* o_val, uint16_t i_size, uint8_t i_elem_size);
};

class SbeAttrTargetSectionListRespParser : public SbeAttrTargetSectionParser
{
    public:

        SbeAttrTargetSectionListRespParser() = default;

        SbeAttrRowListResParser& getNextRow();
};

class SbeAttributeListRespFileParser : public SbeAttributFileParser
{
    public:
        /**
         * @brief  Constructor
         */
        SbeAttributeListRespFileParser();

        /**
         * @brief  to retrieve next target section
         *
         * @return next target section
         */
        SbeAttrTargetSectionListRespParser& getNextTargetSection(SbeTarget& o_sbe_targ);
};
}

#endif
