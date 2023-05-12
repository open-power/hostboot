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
 *                                     <- SbeAttributeFileParser
 *                                              |
 *                                              |<- SbeAttributeUpdRespFileParser
 *                                              |<- SbeAttributeListRespFileParser
 *
 */
#include <cassert>
#include "sbe_attribute_utils.H"

using namespace fapi2;

namespace sbeutil
{
// ---------------------------- SbeAttrRowHandler ------------------------------
SbeAttrRowHandler::SbeAttrRowHandler(
    const SbeAttrTargetSectionHandler* i_parentTargetSection) :
    SbeAttrRowHandler()
{
    iv_parentTargetSection = i_parentTargetSection;
}

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

inline INVALID_ATTR_INDEX SbeAttrRowHandler::get_RC_INVALID_ATTR_INDEX()
{
    return fapi2::INVALID_ATTR_INDEX()
           .set_ATTRIBUTEID(iv_attr_entry.iv_attrId)
           .set_ROW(iv_attr_entry.iv_row)
           .set_COL(iv_attr_entry.iv_col)
           .set_HGT(iv_attr_entry.iv_hgt);
}

ReturnCode SbeAttrRowHandler::getAttrEntry(AttrEntry_t& o_attrEntry)
{
    FAPI_DBG("AttributeId: 0x%08X", iv_attr_entry.iv_attrId);

    FAPI_ASSERT(iv_attr_entry.iv_row == 0xFF, get_RC_INVALID_ATTR_INDEX(),
                "l_attr_entry.iv_row (%d) is invalid", iv_attr_entry.iv_row);
    FAPI_ASSERT(iv_attr_entry.iv_col == 0xFF, get_RC_INVALID_ATTR_INDEX(),
                "l_attr_entry.iv_col (%d) is invalid", iv_attr_entry.iv_col);
    FAPI_ASSERT(iv_attr_entry.iv_hgt == 0xFF, get_RC_INVALID_ATTR_INDEX(),
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

const SbeAttrTargetSectionHandler& SbeAttrRowHandler::getParent()
{
    assert(iv_parentTargetSection != nullptr);

    return *iv_parentTargetSection;
}

// ---------------------- SbeAttrTargetSectionHandler ------------------------
SbeAttrTargetSectionHandler::SbeAttrTargetSectionHandler(
    const SbeAttributeFileHandler* i_parentAttrFile) :
    SbeAttrTargetSectionHandler()
{
    iv_parentAttrFile = i_parentAttrFile;
}

bool SbeAttrTargetSectionHandler::checkMatching(const SbeTarget& i_sbe_targ)
{
    return ((iv_targ_type == i_sbe_targ.iv_targ_type) &&
            (iv_targ_inst_num == i_sbe_targ.iv_inst_num));
}

const SbeAttributeFileHandler& SbeAttrTargetSectionHandler::getParent() const
{
    assert(iv_parentAttrFile != nullptr);

    return *iv_parentAttrFile;
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
        l_header->iv_numTargets = htobe32(iv_target_sections.size());

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
    l_targ_entry->iv_numAttrs   = htobe16(iv_attr_rows.size());
    l_targ_entry->iv_magicWord  = htobe32(TARGET_ENTRY_MAGIC_WORD);

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
    l_attr_entry->iv_attrId   = htobe32(iv_attr_entry.iv_attrId);
    l_attr_entry->iv_dataSize = htobe16(iv_attr_entry.iv_dataSize);
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

    if (getParent().getParent().getFileType() == SBE_ATTRIBUTE_FILE_UPD_RESPONSE)
    {
        FAPI_ASSERT(*io_size >= sizeof(AttrRespEntry_t),
                    INSUFFICIENT_DATA_IN_BUFFER()
                    .set_ACTSIZE(*io_size)
                    .set_SIZE(sizeof(AttrRespEntry_t)),
                    "io_size (%d) is less than sizeof(AttrRespEntry_t)", *io_size);

        iv_attr_entry.iv_attrId   =
            be32toh(reinterpret_cast<AttrRespEntry_t*>(*io_buf)->iv_attrId);
        iv_attr_entry.iv_rc       =
            (SbeAttributeRC)be32toh(reinterpret_cast<AttrRespEntry_t*>(*io_buf)->iv_rc);
        FAPI_DBG("iv_attr_entry.iv_attrId = 0x%08x", iv_attr_entry.iv_attrId);

        *io_buf += sizeof(AttrRespEntry_t);
        *io_size -= sizeof(AttrRespEntry_t);
    }
    else
    {
        FAPI_ASSERT(*io_size >= sizeof(AttrEntry_t),
                    INSUFFICIENT_DATA_IN_BUFFER()
                    .set_ACTSIZE(*io_size)
                    .set_SIZE(sizeof(AttrEntry_t)),
                    "io_size (%d) is less than sizeof(AttrEntry_t)", *io_size);

        iv_attr_entry.iv_attrId   = be32toh(reinterpret_cast<AttrEntry_t*>(*io_buf)->iv_attrId);
        FAPI_DBG("iv_attr_entry.iv_attrId = 0x%08x", iv_attr_entry.iv_attrId);

        iv_attr_entry.iv_dataSize = be16toh(reinterpret_cast<AttrEntry_t*>(*io_buf)->iv_dataSize);
        iv_attr_entry.iv_row      = reinterpret_cast<AttrEntry_t*>(*io_buf)->iv_row;
        iv_attr_entry.iv_col      = reinterpret_cast<AttrEntry_t*>(*io_buf)->iv_col;
        iv_attr_entry.iv_hgt      = reinterpret_cast<AttrEntry_t*>(*io_buf)->iv_hgt;

        *io_buf += sizeof(AttrEntry_t);
        *io_size -= sizeof(AttrEntry_t);

        setAlignedSize();

        FAPI_ASSERT(*io_size >= iv_value_size_aligned,
                    INSUFFICIENT_DATA_IN_BUFFER()
                    .set_ACTSIZE(*io_size)
                    .set_SIZE(iv_value_size_aligned),
                    "io_size (%d) is less than iv_value_size_aligned(%d)",
                    *io_size, iv_value_size_aligned);

        iv_value_ptr = new uint8_t[iv_attr_entry.iv_dataSize];
        memcpy(iv_value_ptr, *io_buf, iv_attr_entry.iv_dataSize);

        *io_buf += iv_value_size_aligned;
        *io_size -= iv_value_size_aligned;
    }

fapi_try_exit:
    return current_err;
}

// ---------------------- SbeAttrTargetSectionParser ----------------------------
ReturnCode SbeAttrTargetSectionParser::parse(uint8_t** io_buf, uint16_t* io_size)
{
    FAPI_DBG("SbeAttrTargetSectionParser::parse Entering ...");

    FAPI_ASSERT(*io_size >= sizeof(TargetEntry_t),
                INSUFFICIENT_DATA_IN_BUFFER()
                .set_ACTSIZE(*io_size)
                .set_SIZE(sizeof(TargetEntry_t)),
                "io_size (%d) is less than sizeof(TargetEntry_t)", *io_size);

    {
        TargetEntry_t* l_targ_entry = reinterpret_cast<TargetEntry_t*>(*io_buf);
        iv_targ_type = l_targ_entry->iv_logTgtType;
        iv_targ_inst_num = l_targ_entry->iv_instance;
        uint16_t l_num_attrs = be16toh(l_targ_entry->iv_numAttrs);
        FAPI_DBG("iv_targ_type = 0x%08x, iv_targ_inst_num = %d, l_num_attrs = %d",
                 iv_targ_type, iv_targ_inst_num, l_num_attrs);

        uint32_t l_magicWord = be32toh(l_targ_entry->iv_magicWord);
        FAPI_ASSERT(l_magicWord == TARGET_ENTRY_MAGIC_WORD,
                    TARGET_ENTRY_MAGIC_WORD_MISMATCH()
                    .set_TARGET_TYPE(iv_targ_type)
                    .set_TARGET_INS_NUM(iv_targ_inst_num)
                    .set_ACTUAL_MAGICWORD(l_magicWord)
                    .set_EXPECTED_MAGICWORD(TARGET_ENTRY_MAGIC_WORD),
                    "Magicword (%08X) does not match with expected 0x%08X",
                    l_magicWord, TARGET_ENTRY_MAGIC_WORD);

        *io_buf += sizeof(TargetEntry_t);
        *io_size -= sizeof(TargetEntry_t);

        for(int i = 0; i < l_num_attrs; i++)
        {
            iv_attr_rows.emplace_back((SbeAttrTargetSectionHandler*)this);
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
                INSUFFICIENT_DATA_IN_BUFFER()
                .set_ACTSIZE(i_size)
                .set_SIZE(sizeof(HeaderEntry_t)),
                "i_size (%d) is less than sizeof(HeaderEntry_t)", i_size);

    {
        HeaderEntry_t* l_header = reinterpret_cast<HeaderEntry_t*>(i_buf);
        FAPI_ASSERT((l_header->iv_fmtMajor == ATTR_FORMAT_MAJOR_VER) &&
                    (l_header->iv_fmtMinor == ATTR_FORMAT_MINOR_VER),
                    UNEXPECTED_ATTR_FORMAT_VER()
                    .set_HEADER_MAJOR_VERSION(l_header->iv_fmtMajor)
                    .set_HEADER_MINOR_VERSION(l_header->iv_fmtMinor)
                    .set_HWP_MAJOR_VERSION(ATTR_FORMAT_MAJOR_VER)
                    .set_HWP_MINOR_VERSION(ATTR_FORMAT_MINOR_VER),
                    "major version (%d) or minor version (%d) is not matching with parser",
                    l_header->iv_fmtMajor, l_header->iv_fmtMinor);

        FAPI_ASSERT((l_header->iv_chipType == iv_chip_type),
                    UNEXPECTED_ATTR_CHIP_TYPE()
                    .set_HEADER_CHIP_TYPE(l_header->iv_chipType)
                    .set_HWP_CHIP_TYPE(iv_chip_type),
                    "chip_type (%d) is not expected (%d)",
                    l_header->iv_chipType, iv_chip_type);

        FAPI_TRY(validateFileType(l_header->iv_fileType));
        {
            uint32_t l_num_targs = be32toh(l_header->iv_numTargets);
            uint8_t* l_cur_ptr = i_buf + sizeof(HeaderEntry_t);

            FAPI_DBG("Number of target sections : %d", l_num_targs);

            for(uint16_t i = 0; i < l_num_targs; i++)
            {
                iv_target_sections.emplace_back((SbeAttributeFileHandler*)this);
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
                UNEXPECTED_ATTR_FILE_TYPE()
                .set_HEADER_FILE_TYPE(i_file_type)
                .set_PARSER_FILE_TYPE(iv_file_type),
                "i_file_type (%d) is not iv_file_type(%d)",
                i_file_type, iv_file_type);

fapi_try_exit:
    return current_err;
}

// ---------------------- SbeAttrRowUpdResParser ------------------------------
void SbeAttrRowUpdResParser::getResponse(AttrRespEntry_t& o_attrRespEntry)
{
    o_attrRespEntry.iv_attrId   = iv_attr_entry.iv_attrId;
    o_attrRespEntry.iv_rc       = iv_attr_entry.iv_rc;
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

// The data type of an attribute will never be modified in the attribute
// definition file. Hence, any data size mismatch error should be treated
// as hard stop by the caller of this function.
ReturnCode SbeAttrRowListResParser::getAttrValue(
    void* o_val, uint16_t i_size, uint8_t i_elem_size)
{
    FAPI_ASSERT(iv_attr_entry.iv_dataSize == i_size,
                UNEXPECTED_DATA_SIZE()
                .set_ATTRIBUTEID(iv_attr_entry.iv_attrId)
                .set_SIZE(iv_attr_entry.iv_dataSize)
                .set_ACTSIZE(i_size),
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
                (uint16_t*)o_val, (uint16_t*)iv_value_ptr, (i_size / i_elem_size), be16toh_xlate);
            break;

        case 4:
            sbeutil::copyArrayWithEndianessCorrection<uint32_t>(
                (uint32_t*)o_val, (uint32_t*)iv_value_ptr, (i_size / i_elem_size), be32toh_xlate);
            break;

        case 8:
            sbeutil::copyArrayWithEndianessCorrection<uint64_t>(
                (uint64_t*)o_val, (uint64_t*)iv_value_ptr, (i_size / i_elem_size), be64toh_xlate);
            break;

        default:
            FAPI_ASSERT(false,
                        INVALID_SIZE_FOR_ENDIANNESS_CORRECTION()
                        .set_ATTRIBUTEID(iv_attr_entry.iv_attrId)
                        .set_SIZE(i_elem_size),
                        "i_elem_size:%d not handled", i_elem_size);
            break;
    }

fapi_try_exit:
    return current_err;
}

// ------------------ SbeAttrTargetSectionListRespParser-----------------------
SbeAttrRowListResParser& SbeAttrTargetSectionListRespParser::getNextRow()
{
    return static_cast<SbeAttrRowListResParser&>(getNextRowBase());
}

ReturnCode SbeAttrTargetSectionListRespParser::addAttributesToError(const SbeAttributeRC i_rc,
        std::vector<AttrError_t>& io_errors)
{
    FAPI_DBG("SbeAttrTargetSectionListRespParser::addAttributesToError Entering ...");

    // This function is called after an error, and this function will help to continue
    //    by storing the error in vector (io_errors). So we have to clear the current
    //    error.
    current_err = FAPI2_RC_SUCCESS;

    AttrEntry_t l_attrEntry;

    while (this->getRemainingRowCount())
    {
        FAPI_DBG("getRemainingRowCount() = %d", this->getRemainingRowCount());

        SbeAttrRowListResParser& l_attr = this->getNextRow();
        FAPI_TRY(l_attr.getAttrEntry(l_attrEntry), "getAttrEntry returned error");

        io_errors.emplace_back(fapi2::logToTargetType(this->iv_targ_type),
                               this->iv_targ_inst_num,
                               uint32_t(l_attrEntry.iv_attrId),
                               i_rc);
    }

fapi_try_exit:
    return current_err;
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
