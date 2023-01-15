/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/sbe_utils/src/sbe_attribute_utils.C $         */
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
/**
 *  @file sbe_attribute_utils.C
 *  @brief Implements generator classes for attribute update chip-op request and
 *         parser classes for attribute list chip-op response.
 *
 *         The class hierarchy is as follows:
 *
 *         SbeAttrRowHandler  <- SbeAttrRowGen
 *                            <- SbeAttrRowParser  <- SbeAttrRowListResParser
 *
 *         SbeAttrTargetSectionHandler <- SbeAttrTargetSectionGen
 *                                     <- SbeAttrTargetSectionParser
 *                                              |
 *                                              |<- SbeAttrTargetSectionUpdRespParser
 *                                              |<- SbeAttrTargetSectionListRespParser
 *
 *         SbeAttributeFileHandler     <- SbeAttributeUpdateFileGenerator
 *                                     <- SbeAttributFileParser
 *                                              |
 *                                              |<- SbeAttributeUpdRespFileParser
 *                                              |<- SbeAttributeListRespFileParser
 *
 */

#include "sbe_attribute_utils.H"

using namespace fapi2;

namespace sbeutil
{
// ---------------------------- SbeAttrRowHandler ------------------------------
SbeAttrRowHandler::~SbeAttrRowHandler()
{

    if(iv_value_ptr)
    {
        delete [] iv_value_ptr;
    }

}

SbeAttrRowHandler::SbeAttrRowHandler(SbeAttrRowHandler&& i_src)
{
    iv_attr_entry = i_src.iv_attr_entry;
    iv_value_ptr = i_src.iv_value_ptr;
    iv_value_size_aligned = i_src.iv_value_size_aligned;

    i_src.iv_value_ptr = nullptr;
}

ReturnCode SbeAttrRowHandler::getAttrEntry(AttrEntry_t& o_attrEntry)
{
    FAPI_DBG("AttributeId: 0x%08X", iv_attr_entry.iv_attrId);

    FAPI_ASSERT(iv_attr_entry.iv_row == 0xFF, fapi2::INVALID_ATTR_FILE(),
                "l_attr_entry.iv_row (%d) is invalid", iv_attr_entry.iv_row);
    FAPI_ASSERT(iv_attr_entry.iv_col == 0xFF, fapi2::INVALID_ATTR_FILE(),
                "l_attr_entry.iv_col (%d) is invalid", iv_attr_entry.iv_col);
    FAPI_ASSERT(iv_attr_entry.iv_hgt == 0xFF, fapi2::INVALID_ATTR_FILE(),
                "l_attr_entry.iv_hgt (%d) is invalid", iv_attr_entry.iv_hgt);
    o_attrEntry = iv_attr_entry;

fapi_try_exit:
    return fapi2::current_err;
}

void SbeAttrRowHandler::setAlignedSize()
{
    // total size of attribute row should be aligned to 8 bytes
    uint16_t l_tot_aligned_size = iv_attr_entry.iv_dataSize + sizeof(AttrEntry_t);
    l_tot_aligned_size = (l_tot_aligned_size + 7) & 0xFFF8;
    iv_value_size_aligned = l_tot_aligned_size - sizeof(AttrEntry_t);
}

// ---------------------- SbeAttrTargetSectionHandler ------------------------
bool SbeAttrTargetSectionHandler::checkMatching(const SbeTarget& i_sbe_targ)
{
    return ((iv_targ_type == i_sbe_targ.iv_targ_type) &&
            (iv_targ_inst_num == i_sbe_targ.iv_inst_num));
}

// -------------------------- SbeAttributeFileHandler --------------------------
ReturnCode SbeAttributeFileHandler::setChipTarget(
    const Target<TARGET_TYPE_ANY_POZ_CHIP>& i_chip_targ)
{
    FAPI_TRY(find_chip_type(i_chip_targ, iv_chip_type));

fapi_try_exit:
    return current_err;
}

// ---------------------- SbeAttributeUpdateFileGenerator ------------------------
SbeAttributeUpdateFileGenerator::SbeAttributeUpdateFileGenerator()
{
    iv_file_type = SBE_ATTRIBUTE_FILE_UPDATE;
}

ReturnCode SbeAttributeUpdateFileGenerator::_addAttribute(
    const SbeTarget& i_sbe_targ,
    const AttrEntry_t& i_attr_entry,
    void* i_val)
{
    FAPI_DBG("_addAttribute Entering ...");
    bool l_target_found_flag = false;

    for(auto& l_targ : iv_target_sections)
    {
        if(l_targ.checkMatching(i_sbe_targ))
        {
            l_target_found_flag = true;
            static_cast<SbeAttrTargetSectionGen&>(l_targ).addAttribute(i_attr_entry, i_val);
        }
    }

    if(!l_target_found_flag)
    {
        iv_target_sections.push_back(
            SbeAttrTargetSectionGen(i_sbe_targ.iv_targ_type, i_sbe_targ.iv_inst_num));
        static_cast<SbeAttrTargetSectionGen&>(
            iv_target_sections.back()).addAttribute(i_attr_entry, i_val);
    }

fapi_try_exit:
    return current_err;
}

uint16_t SbeAttributeUpdateFileGenerator::getOutputBufSize()
{
    uint16_t l_ret_size = sizeof(HeaderEntry_t);;

    for(auto& l_targ : iv_target_sections)
    {
        static_cast<SbeAttrTargetSectionGen&>(l_targ).accumulateOutputSize(l_ret_size);
    }

    return l_ret_size;
}

ReturnCode SbeAttributeUpdateFileGenerator::genOutput(
    const char* i_file_path,
    void* o_buf,
    const uint16_t i_buf_size)
{
    FAPI_DBG("genOutput Entering ...");
    uint16_t l_output_size = getOutputBufSize();
    FAPI_DBG("l_output_size=%d", l_output_size);

    FAPI_ASSERT(l_output_size <= i_buf_size,
                INVALID_ATTR_FILE(),
                "The output buffer size [%d] is not sufficient to hold the generated blob of size [%d]",
                i_buf_size, l_output_size);
    {
        uint8_t l_buf[l_output_size] = {0};

        HeaderEntry_t* l_header = reinterpret_cast<HeaderEntry_t*>(l_buf);
        l_header->iv_fmtMajor   = ATTR_FORMAT_MAJOR_VER;
        l_header->iv_fmtMinor   = ATTR_FORMAT_MINOR_VER;
        l_header->iv_chipType   = iv_chip_type;
        l_header->iv_fileType   = iv_file_type;
        l_header->iv_numTargets = htonl(iv_target_sections.size());

        uint8_t* l_cur_pointer = l_buf + sizeof(HeaderEntry_t);

        for(auto& l_targ : iv_target_sections)
        {
            FAPI_DBG("l_target.iv_targ_type = 0x%02X", l_targ.getTargetType());
            static_cast<SbeAttrTargetSectionGen&>(l_targ).genOutput(&l_cur_pointer);
        }

        // TODO: generate the pak with name 'i_file_path + "/attr.ovrd"', and content l_buf
        memcpy(o_buf, l_buf, sizeof(l_buf));
    }
fapi_try_exit:
    return current_err;
}

// ---------------------- SbeAttrTargetSectionGen ------------------------------
SbeAttrTargetSectionGen::SbeAttrTargetSectionGen(
    LogTargetType i_targ_type,
    uint8_t              i_targ_inst_num)
{
    iv_targ_type = i_targ_type;
    iv_targ_inst_num = i_targ_inst_num;
}

void SbeAttrTargetSectionGen::addAttribute(const AttrEntry_t& i_entry, void* i_val)
{
    iv_attr_rows.push_back(SbeAttrRowGen(i_entry, i_val));
}

void SbeAttrTargetSectionGen::accumulateOutputSize(uint16_t& io_size)
{
    io_size += sizeof(TargetEntry_t);

    for(auto& l_attr : iv_attr_rows)
    {
        static_cast<SbeAttrRowGen&>(l_attr).accumulateOutputSize(io_size);
    }
}

void SbeAttrTargetSectionGen::genOutput(uint8_t** io_pointer)
{
    TargetEntry_t* l_targ_entry = reinterpret_cast<TargetEntry_t*>(*io_pointer);
    l_targ_entry->iv_logTgtType = iv_targ_type;
    l_targ_entry->iv_instance   = iv_targ_inst_num;
    l_targ_entry->iv_numAttrs   = htons(iv_attr_rows.size());

    *io_pointer += sizeof(TargetEntry_t);

    for(auto& l_attr : iv_attr_rows)
    {
        static_cast<SbeAttrRowGen&>(l_attr).genOutput(io_pointer);
    }
}

// -------------------------- SbeAttrRowGen ------------------------------------
SbeAttrRowGen::SbeAttrRowGen(const AttrEntry_t& i_entry, void* i_val)
{
    iv_attr_entry = i_entry;
    iv_value_ptr = new uint8_t[iv_attr_entry.iv_dataSize];
    memcpy(iv_value_ptr, i_val, iv_attr_entry.iv_dataSize);

    setAlignedSize();
}

void SbeAttrRowGen::accumulateOutputSize(uint16_t& io_size)
{
    io_size += sizeof(AttrEntry_t) + iv_value_size_aligned;
}

void SbeAttrRowGen::genOutput(uint8_t** io_pointer)
{
    AttrEntry_t* l_attr_entry = reinterpret_cast<AttrEntry_t*>(*io_pointer);
    l_attr_entry->iv_attrId   = htonl(iv_attr_entry.iv_attrId);
    l_attr_entry->iv_dataSize = htons(iv_attr_entry.iv_dataSize);
    l_attr_entry->iv_row      = iv_attr_entry.iv_row;
    l_attr_entry->iv_col      = iv_attr_entry.iv_col;
    l_attr_entry->iv_hgt      = iv_attr_entry.iv_hgt;
    *io_pointer += sizeof(iv_attr_entry);

    memcpy(*io_pointer, iv_value_ptr, iv_attr_entry.iv_dataSize);
    *io_pointer += iv_value_size_aligned;
}

// ---------------------- SbeAttrRowParser ------------------------------------
ReturnCode SbeAttrRowParser::parse(uint8_t** io_buf, uint16_t* io_size)
{
    FAPI_DBG("SbeAttrRowParser::parse Entering ...");

    FAPI_ASSERT(*io_size >= sizeof(AttrEntry_t),
                INVALID_ATTR_FILE(),
                "io_size (%d) is less than sizeof(AttrEntry_t)", *io_size);

    iv_attr_entry.iv_attrId   = ntohl(reinterpret_cast<AttrEntry_t*>(*io_buf)->iv_attrId);
    FAPI_DBG("iv_attr_entry.iv_attrId = 0x%08x", iv_attr_entry.iv_attrId);

    iv_attr_entry.iv_dataSize = ntohs(reinterpret_cast<AttrEntry_t*>(*io_buf)->iv_dataSize);
    iv_attr_entry.iv_row      = reinterpret_cast<AttrEntry_t*>(*io_buf)->iv_row;
    iv_attr_entry.iv_col      = reinterpret_cast<AttrEntry_t*>(*io_buf)->iv_col;
    iv_attr_entry.iv_hgt      = reinterpret_cast<AttrEntry_t*>(*io_buf)->iv_hgt;

    *io_buf += sizeof(AttrEntry_t);
    *io_size -= sizeof(AttrEntry_t);

    setAlignedSize();

    FAPI_ASSERT(*io_size >= iv_value_size_aligned,
                INVALID_ATTR_FILE(),
                "io_size (%d) is less than iv_value_size_aligned(%d)",
                *io_size, iv_value_size_aligned);

    iv_value_ptr = new uint8_t[iv_attr_entry.iv_dataSize];
    memcpy(iv_value_ptr, *io_buf, iv_attr_entry.iv_dataSize);

    *io_buf += iv_value_size_aligned;
    *io_size += iv_value_size_aligned;

fapi_try_exit:
    return current_err;
}

// ---------------------- SbeAttrTargetSectionParser ----------------------------
ReturnCode SbeAttrTargetSectionParser::parse(uint8_t** io_buf, uint16_t* io_size)
{
    FAPI_DBG("SbeAttrTargetSectionParser::parse Entering ...");

    FAPI_ASSERT(*io_size >= sizeof(TargetEntry_t),
                INVALID_ATTR_FILE(),
                "io_size (%d) is less than sizeof(TargetEntry_t)", *io_size);

    {
        TargetEntry_t* l_targ_entry = reinterpret_cast<TargetEntry_t*>(*io_buf);
        iv_targ_type = l_targ_entry->iv_logTgtType;
        iv_targ_inst_num = l_targ_entry->iv_instance;
        uint16_t l_num_attrs = ntohs(l_targ_entry->iv_numAttrs);
        FAPI_DBG("iv_targ_type = 0x%08x, iv_targ_inst_num = %d, l_num_attrs = %d",
                 iv_targ_type, iv_targ_inst_num, l_num_attrs);

        *io_buf += sizeof(TargetEntry_t);
        *io_size -= sizeof(TargetEntry_t);

        for(int i = 0; i < l_num_attrs; i++)
        {
            iv_attr_rows.push_back(SbeAttrRowParser());
            FAPI_TRY(static_cast<SbeAttrRowParser&>(
                         iv_attr_rows.back()).parse(io_buf, io_size),
                     "SbeAttrRowParser.parse failed");
        }
    }

fapi_try_exit:
    return current_err;
}

uint16_t SbeAttrTargetSectionParser::getRemainingRowCount()
{
    return iv_attr_rows.size() - iv_next_row_index;
}

SbeAttrRowParser& SbeAttrTargetSectionParser::getNextRowBase()
{
    FAPI_DBG("Entering  .... iv_next_row_index = %d", iv_next_row_index);
    return static_cast<SbeAttrRowParser&>(
               iv_attr_rows[iv_next_row_index++]);
}

// ---------------------- SbeAttributFileParser ----------------------
ReturnCode SbeAttributFileParser::parseFile(uint8_t* i_buf, uint16_t i_size)
{
    FAPI_DBG("parseFile Entering ...");

    FAPI_ASSERT(i_size >= sizeof(HeaderEntry_t),
                INVALID_ATTR_FILE(),
                "i_size (%d) is less than sizeof(HeaderEntry_t)", i_size);

    {
        HeaderEntry_t* l_header = reinterpret_cast<HeaderEntry_t*>(i_buf);
        FAPI_ASSERT((l_header->iv_fmtMajor == ATTR_FORMAT_MAJOR_VER) &&
                    (l_header->iv_fmtMinor == ATTR_FORMAT_MINOR_VER),
                    INVALID_ATTR_FILE(),
                    "major version (%d) or minor version (%d) is not matching with parser",
                    l_header->iv_fmtMajor, l_header->iv_fmtMinor);

        FAPI_ASSERT((l_header->iv_chipType == iv_chip_type),
                    INVALID_ATTR_FILE(),
                    "chip_type (%d) is not expected (%d)",
                    l_header->iv_chipType, iv_chip_type);

        FAPI_TRY(validateFileType(l_header->iv_fileType));
        {
            uint32_t l_num_targs = ntohl(l_header->iv_numTargets);
            uint8_t* l_cur_ptr = i_buf + sizeof(HeaderEntry_t);

            for(uint16_t i = 0; i < l_num_targs; i++)
            {
                iv_target_sections.push_back(SbeAttrTargetSectionParser());
                FAPI_TRY(static_cast<SbeAttrTargetSectionParser&>(
                             iv_target_sections.back()).parse(&l_cur_ptr, &i_size));
            }
        }
    }

fapi_try_exit:
    return current_err;
}

uint16_t SbeAttributFileParser::getRemainingTargSectionCount()
{
    return iv_target_sections.size() - iv_next_targ_index;
}

SbeAttrTargetSectionParser&
SbeAttributFileParser::getNextTargetSectionBase(SbeTarget& o_sbe_targ)
{
    FAPI_DBG("Entering ... iv_next_targ_index = %d", iv_next_targ_index);
    iv_target_sections[iv_next_targ_index].getSbeTarget(o_sbe_targ);
    o_sbe_targ.iv_chip_type = iv_chip_type;
    return static_cast<SbeAttrTargetSectionParser&>(
               iv_target_sections[iv_next_targ_index++]);
}

ReturnCode SbeAttributFileParser::validateFileType(SbeAttributeFileTypes i_file_type)
{
    FAPI_ASSERT(i_file_type == iv_file_type,
                INVALID_ATTR_FILE(),
                "i_file_type (%d) is not iv_file_type(%d)",
                i_file_type, iv_file_type);

fapi_try_exit:
    return current_err;
}

// ---------------------- SbeAttrRowUpdResParser ------------------------------
ReturnCode SbeAttrRowUpdResParser::getResponse(SbeAttributeUpdateRC& o_resp)
{
    FAPI_ASSERT(iv_attr_entry.iv_dataSize == sizeof(SbeAttributeUpdateRC),
                INVALID_ATTR_FILE(),
                "iv_dataSize(%d) != sizeof(SbeAttributeUpdateRC)(%d)",
                iv_attr_entry.iv_dataSize, sizeof(SbeAttributeUpdateRC));

    o_resp = *(reinterpret_cast<SbeAttributeUpdateRC*>(iv_value_ptr));

fapi_try_exit:
    return current_err;
}

// ------------------ SbeAttrTargetSectionUpdRespParser-----------------------
SbeAttrRowUpdResParser& SbeAttrTargetSectionUpdRespParser::getNextRow()
{
    return static_cast<SbeAttrRowUpdResParser&>(getNextRowBase());
}

// ---------------------- SbeAttributeUpdRespFileParser ----------------------
SbeAttributeUpdRespFileParser::SbeAttributeUpdRespFileParser()
{
    iv_file_type = SBE_ATTRIBUTE_FILE_UPD_RESPONSE;
}

SbeAttrTargetSectionUpdRespParser&
SbeAttributeUpdRespFileParser::getNextTargetSection(SbeTarget& o_sbe_targ)
{
    return static_cast<SbeAttrTargetSectionUpdRespParser&>(
               getNextTargetSectionBase(o_sbe_targ));
}

// ---------------------- SbeAttrRowListResParser ------------------------------
ReturnCode SbeAttrRowListResParser::getAttrValue(
    void* o_val, uint16_t i_size, uint8_t i_elem_size)
{
    FAPI_ASSERT(iv_attr_entry.iv_dataSize == i_size,
                INVALID_ATTR_FILE(),
                "iv_dataSize(%d) != i_size(%d)",
                iv_attr_entry.iv_dataSize, i_size);

    switch(i_elem_size)
    {
        case 1:
            sbeutil::copyArrayWithEndianessCorrection<uint8_t>(
                (uint8_t*)o_val, (uint8_t*)iv_value_ptr, (i_size / i_elem_size));
            break;

        case 2:
            sbeutil::copyArrayWithEndianessCorrection<uint16_t>(
                (uint16_t*)o_val, (uint16_t*)iv_value_ptr, (i_size / i_elem_size), ntohs);
            break;

        case 4:
            sbeutil::copyArrayWithEndianessCorrection<uint32_t>(
                (uint32_t*)o_val, (uint32_t*)iv_value_ptr, (i_size / i_elem_size), ntohl);
            break;

        default:
            FAPI_ASSERT(false, INVALID_ATTR_FILE(),
                        "i_elem_size:%d not handled", i_elem_size);
    }

fapi_try_exit:
    return current_err;
}

// ------------------ SbeAttrTargetSectionListRespParser-----------------------
SbeAttrRowListResParser& SbeAttrTargetSectionListRespParser::getNextRow()
{
    return static_cast<SbeAttrRowListResParser&>(getNextRowBase());
}

// ---------------------- SbeAttributeListRespFileParser ----------------------
SbeAttributeListRespFileParser::SbeAttributeListRespFileParser()
{
    iv_file_type = SBE_ATTRIBUTE_FILE_LIST;
}

SbeAttrTargetSectionListRespParser&
SbeAttributeListRespFileParser::getNextTargetSection(SbeTarget& o_sbe_targ)
{
    FAPI_DBG("Entering");
    return static_cast<SbeAttrTargetSectionListRespParser&>(
               getNextTargetSectionBase(o_sbe_targ));
}

} // namespace sbeutil
