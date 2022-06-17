/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/attrrp_common.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
#include <targeting/attrrp.H>
#include <targeting/common/trace.H>
#include <util/align.H>
#include <targeting/common/util.H>
#include <attrsizesdata.H>
#include <console/consoleif.H>
#include <util/utillidmgr.H>
#include <pldm/requests/pldm_fileio_requests.H>

namespace TARGETING
{
    #define TARG_NAMESPACE "TARGETING"
    #define TARG_CLASS "AttrRP"

#ifdef __HOSTBOOT_RUNTIME
    // It is defined here to limit the scope within this file,
    // this file is also included in attrrp_rt.C
    #define INVALID_NODE_ID iv_nodeContainer.size()
#endif

    /** @struct AttrRP_Section
     *  @brief Contains parsed information about each attribute section.
     */
    struct AttrRP_Section
    {
        // Section type
        SECTION_TYPE type;

        // Desired address in Attribute virtual address space
        uint64_t     vmmAddress;

        // Location in PNOR virtual address space
        uint64_t     pnorAddress;

        uint64_t     realMemAddress;

        // Section size
        uint64_t     size;
    };

    AttrRP::~AttrRP()
    {
#ifndef __HOSTBOOT_RUNTIME
        if (iv_sections)
        {
            delete[] iv_sections;
            iv_sections = nullptr;
       }

        msg_q_destroy(iv_msgQ);
        TARG_ASSERT(false, "Assert to exit ~AttrRP");
#else
        for(uint32_t i = NODE0; i < INVALID_NODE_ID; ++i)
        {
            if (iv_nodeContainer[i].pSections)
            {
                delete[] iv_nodeContainer[i].pSections;
                iv_nodeContainer[i].pSections = nullptr;
            }
        }

        // Only assert if this in not a temporary AttrRP instance
        if (!iv_isTempInstance)
        {
            #ifndef PROFILE_CODE
            // When profiling, we want to be able to unload modules and
            // easily recover the coverage information
            TARG_ASSERT(false, "Assert to exit ~AttrRP");
            #endif
        }
#endif

    }

    void AttrRP::init(errlHndl_t &io_taskRetErrl, bool i_isMpipl)
    {
        // Call startup on singleton instance.
        Singleton<AttrRP>::instance().startup(io_taskRetErrl, i_isMpipl);
    }

#ifndef __HOSTBOOT_RUNTIME
    bool AttrRP::writeSectionData(
        const std::vector<TARGETING::sectionRefData>& i_pages) const
    {
        TARG_INF(ENTER_MRK "AttrRP::writeSectionData");

        uint8_t * l_dataPtr = NULL; // ptr to Attribute virtual address space
        bool      l_rc = true;      // true if write to section is successful

        // for each page
        for (std::vector<TARGETING::sectionRefData>::const_iterator
                pageIter = i_pages.begin();
                (pageIter != i_pages.end()) && (true == l_rc);
                ++pageIter)
        {
            // search for the section we need
            for ( size_t j = 0; j < iv_sectionCount; ++j )
            {
                if ( iv_sections[j].type == (*pageIter).sectionId )
                {
                    // found it..
                    TARG_DBG( "Writing Attribute Section: ID: %u, "
                        "address: 0x%lx size: 0x%lx page: %u",
                        iv_sections[j].type,
                        iv_sections[j].vmmAddress,
                        iv_sections[j].size,
                        (*pageIter).pageNumber);

                    // check that page number is within range
                    uint64_t l_pageOffset = (*pageIter).pageNumber * PAGESIZE;
                    if ( iv_sections[j].size < (l_pageOffset + PAGESIZE) )
                    {
                        TARG_ERR("page offset 0x%lx is greater than "
                            "size 0x%lx of section %u",
                            l_pageOffset,
                            iv_sections[j].size,
                            iv_sections[j].type);

                        l_rc = false;
                        break;
                    }

                    // adjust the pointer out by page size * page number
                    l_dataPtr =
                        reinterpret_cast<uint8_t *>
                        (iv_sections[j].vmmAddress) + l_pageOffset;

                    memcpy( l_dataPtr, (*pageIter).dataPtr, PAGESIZE );
                    break;
                }
            }

            if (false == l_rc)
            {
                break;
            }
        }

        TARG_INF( EXIT_MRK "AttrRP::writeSectionData" );
        return l_rc;
    }

    void AttrRP::readSectionData(
              std::vector<TARGETING::sectionRefData>& o_pages,
        const TARGETING::SECTION_TYPE                 i_sectionId,
        const NODE_ID                                 i_nodeId) const
    {
        sectionRefData sectionData;
        uint16_t count              =  0;
        uint16_t pages              =  0;

        // search for the section we need
        for (size_t i = 0; i < iv_sectionCount; ++i )
        {
            if ( iv_sections[i].type == i_sectionId )
            {
                // found it..
                // now figure out how many pages - rounding up to the
                // the next full page and dividing by the page size
                pages = ALIGN_PAGE( iv_sections[i].size )/PAGESIZE;

                TRACFCOMP(g_trac_targeting,
                        "Reading Attribute Section: ID: %d, \
                        address: 0x%lx size: 0x%lx pages: %d",
                        iv_sections[i].type,
                        iv_sections[i].vmmAddress,
                        iv_sections[i].size,
                        pages);

                // populate and push the structure for each page
                while( count != pages  )
                {
                    // duplicate the same section id in each structure
                    sectionData.sectionId = i_sectionId;

                    // update the current page number
                    sectionData.pageNumber = count;

                    // addjust the pointer out by page size * count each
                    // iteration
                    sectionData.dataPtr =
                             reinterpret_cast<uint8_t *>
                             (iv_sections[i].vmmAddress) + (count * PAGESIZE );

                    count++;

                    // pushing the actual structure to the vector
                    o_pages.push_back( sectionData );

                }

                break;
            }
        }
    }
#endif // ifndef __HOSTBOOT_RUNTIME

    /**
     * @brief Helper function to format the input value of the attribute according
     *        to its data size. The formatted value is appended to the vector.
     *        The vector is never cleared in this function.
     *
     * @param[in] i_dataType the data type of the attribute value (used to format
     *            the value correctly)
     * @param[in] i_attrValuePtr the pointer to the value of the attribute
     * @param[out] o_attrValue the vector where the formatted value would be
     *             appended.
     */
    void formatAttributeValue(const ATTR_DATA_TYPE i_dataType,
                              const void* i_attrValuePtr, std::vector<char>& o_attrValue)
    {
        char l_formattedValue[50]{};
        switch (i_dataType)
        {
            case UINT8_T_TYPE:
            case INT8_T_TYPE:
            {
                sprintf(l_formattedValue, " 0x%02x\n", *(reinterpret_cast<const uint8_t*>(i_attrValuePtr)));
                break;
            }
            case UINT16_T_TYPE:
            case INT16_T_TYPE:
            {
                sprintf(l_formattedValue, " 0x%04x\n", *(reinterpret_cast<const uint16_t*>(i_attrValuePtr)));
                break;
            }
            case UINT32_T_TYPE:
            case INT32_T_TYPE:
            {
                sprintf(l_formattedValue, " 0x%08x\n", *(reinterpret_cast<const uint32_t*>(i_attrValuePtr)));
                break;
            }
            case UINT64_T_TYPE:
            case INT64_T_TYPE:
            {
                sprintf(l_formattedValue, " 0x%016lx\n", *(reinterpret_cast<const uint64_t*>(i_attrValuePtr)));
                break;
            }
            default:
            {
                sprintf(l_formattedValue, " 0xBAD\n");
                break;
            }
        }
        o_attrValue.insert(o_attrValue.end(), l_formattedValue, l_formattedValue + strlen(l_formattedValue));
    }

    /**
     * @brief Helper function to convert an enum data type to string
     *
     * @param[in] i_dataType the enum data type to be converted
     * @return the string representation of the input data type. "BAD" if the
     *         data type is unknown.
     */
    const char* formatAttributeSize(const ATTR_DATA_TYPE i_dataType)
    {
        switch(i_dataType)
        {
            case UINT8_T_TYPE:
            {
                return "u8";
                break;
            }
            case INT8_T_TYPE:
            {
                return "s8";
                break;
            }
            case UINT16_T_TYPE:
            {
                return "u16";
                break;
            }
            case INT16_T_TYPE:
            {
                return "s16";
                break;
            }
            case UINT32_T_TYPE:
            {
                return "u32";
                break;
            }
            case INT32_T_TYPE:
            {
                return "s32";
                break;
            }
            case UINT64_T_TYPE:
            {
                return "u64";
                break;
            }
            case INT64_T_TYPE:
            {
                return "s64";
                break;
            }
            default:
            {
                return "BAD";
                break;
            }
        }
    }

    /**
     * @brief Helper function to dump the value of an array attribute.
     *        The format of an array attribute dump is this:
     *
     *        ATTR_NAME[0] attr_type[arraySize] attr_value[0]
     *        ATTR_NAME[1] attr_type[arraySize] attr_value[1]
     *        ATTR_NAME[2] attr_type[arraySize] attr_value[2]
     *        ...
     *        ATTR_NAME[arraySize-1] attr_type[arraySize] attr_value[arraySize-1]
     *
     *        2-D example format:
     *        ATTR_NAME[outerIndex][innerIndex] size[arraySize] value
     *
     *        The data is appended to the output vector. The vector is not
     *        cleared.
     *
     * @param[in] i_attrName the string representation of the attribute name
     *            (ATTR_NAME in example above).
     * @param[in] i_dataType the simple type of the attribute (attr_type above)
     * @param[in] i_dataSize the size of the data type of the attribute (uint8_t,
     *            uint16_t, etc.)
     * @param[in] i_arrDimensions the vector of the array dimensions. Example:
     *            a 2x3 array would have 2 entries in the dimensions vector: 2,3
     *            a 3x4x5 would be a vector consisting of 3,4,5
     * @param[in] i_attrValuePtr the pointer to the value of this array attribute
     * @param[out] o_attrValue the vector to be populated with the string
     *             representation of the attribute value.
     */
    void formatArrayAttrValue(const char* const i_attrName,
                              const ATTR_DATA_TYPE i_dataType,
                              const ATTR_DATA_SIZE i_dataSize,
                              const std::vector<uint32_t>& i_arrDimensions,
                              void* const i_attrValuePtr,
                              std::vector<char>& o_attrValue)
    {
        uint8_t* l_attrValuePtr = reinterpret_cast<uint8_t*>(i_attrValuePtr);
        // Get the string representation of the attribute data size
        const char* l_attrSizeStr = formatAttributeSize(i_dataType);

        if(i_arrDimensions.size() == 1) // One-dimensional array
        {
            // Format ATTR_NAME[arrIndex] size[arrSize] value
            for(size_t i = 0; i < i_arrDimensions[0]; ++i)
            {
                char l_attrNameFormatted[MAX_ATTR_STR_LEN]{};
                snprintf(l_attrNameFormatted, MAX_ATTR_STR_LEN, "%s[%d] %s[%d]", i_attrName, i, l_attrSizeStr, i_arrDimensions[0]);
                // Insert the formatted attribute name
                o_attrValue.insert(o_attrValue.end(), l_attrNameFormatted, l_attrNameFormatted + strlen(l_attrNameFormatted));
                // Insert the formatted attribute value
                formatAttributeValue(i_dataType, l_attrValuePtr, o_attrValue);
                l_attrValuePtr += i_dataSize;
            }
        }
        else if(i_arrDimensions.size() == 2) // Two-dimensional array
        {
            // Format ATTR_NAME[outerIndex][innerIndex] size[arrSize] value
            for(size_t i = 0; i < i_arrDimensions[0]; ++i)
            {
                for(size_t j = 0; j < i_arrDimensions[1]; ++j)
                {
                    char l_attrNameFormatted[MAX_ATTR_STR_LEN]{};
                    snprintf(l_attrNameFormatted, MAX_ATTR_STR_LEN, "%s[%d][%d] %s[%d]", i_attrName, i, j, l_attrSizeStr, i_arrDimensions[0] * i_arrDimensions[1]);
                    // Insert the formatted attribute name
                    o_attrValue.insert(o_attrValue.end(), l_attrNameFormatted, l_attrNameFormatted + strlen(l_attrNameFormatted));
                    // Insert the formatted attribute value
                    formatAttributeValue(i_dataType, l_attrValuePtr, o_attrValue);
                    l_attrValuePtr += i_dataSize;
                }
            }
        }
        else if(i_arrDimensions.size() == 3) // Three-dimensional array
        {
            // Format ATTR_NAME[index1][index2][index3] size[arrSize] value
            for(size_t i = 0; i < i_arrDimensions[0]; ++i)
            {
                for(size_t j = 0; j < i_arrDimensions[1]; ++j)
                {
                    for(size_t t = 0; t < i_arrDimensions[2]; ++t)
                    {
                        char l_attrNameFormatted[MAX_ATTR_STR_LEN]{};
                        snprintf(l_attrNameFormatted, MAX_ATTR_STR_LEN, "%s[%d][%d][%d] %s[%d]",
                                i_attrName, i, j, t,
                                l_attrSizeStr,
                                i_arrDimensions[0] * i_arrDimensions[1] * i_arrDimensions[2]);
                        // Insert the formatted attribute name
                        o_attrValue.insert(o_attrValue.end(), l_attrNameFormatted, l_attrNameFormatted + strlen(l_attrNameFormatted));
                        // Insert the formatted attribute value
                        formatAttributeValue(i_dataType, l_attrValuePtr, o_attrValue);
                        l_attrValuePtr += i_dataSize;
                    }
                }
            }
        }
        else
        {
#ifdef CONFIG_CONSOLE
            CONSOLE::displayf(CONSOLE::DEFAULT, NULL, "Could not process attribute %s of dimensions %d",
                              i_attrName,
                              i_arrDimensions.size());
#endif
            TRACFCOMP(g_trac_targeting, WARN_MRK"formatArrayAttrValue: Attribute %s of %d dimensions could not be processed",
                      i_attrName,
                      i_arrDimensions.size());
        }
    }


    /**
     * @brief Helper function to fetch the given attribute value from memory
     *        and format it into a vector of chars so it can be written out
     *        to a file. The attribute value is appended to the vector. The
     *        output vector does not get cleared by this function.
     *
     * @param[in] i_attrValuePtr the pointer to the value of the given attribute
     *            (cannot be nullptr)
     * @param[in] i_attrId the numerical ID (hash) of the attribute
     * @param[out] o_attrValue the vector that will contain the string representation
     *             of the attribute value. The string will be appended to this
     *             vector.
     */
    void getAttrValueFromMem(void* const i_attrValuePtr,
                             const ATTRIBUTE_ID i_attrId,
                             std::vector<char>& o_attrValue)
    {
        do {

        // Get the string representation of the attribute name
        const char* l_attrNamePtr = getAttrName(i_attrId);
        if(l_attrNamePtr == nullptr)
        {
            // We don't want to dump the attr value if we can't get the attr
            // name as a string
            TRACFCOMP(g_trac_targeting, WARN_MRK"Could not find a string name for attr ID 0x%x", i_attrId);
            break;
        }

        // A lambda to binary search the array of attribute size data by hashes
        auto hashCompFunc = [](const attrSizeData_t& i_attrSizeData,
                               const uint32_t i_hash)
                               {
                                   return i_attrSizeData.attrHash < i_hash;
                               };

        // Find the size and the simple data type of this attr in the array
        const auto l_attrIter = std::lower_bound(g_attrSizesArr.begin(),
                                                 g_attrSizesArr.end(),
                                                 i_attrId,
                                                 hashCompFunc);

        // Check if the hash is there and it's the exact hash that we're
        // looking for. lower_bound can return the next biggest hash if
        // it doesn't find the exact match.
        if((l_attrIter != g_attrSizesArr.end()) &&
           (l_attrIter->attrHash == i_attrId))
        {
            if(l_attrIter->isArray)
            {
                // Arrays are handled differently than single-value attrs
                formatArrayAttrValue(l_attrNamePtr,
                                     l_attrIter->dataType,
                                     l_attrIter->dataSize,
                                     l_attrIter->dimensions,
                                     i_attrValuePtr,
                                     o_attrValue);
            }
            else
            {
                // Format single-value attribute
                char l_formattedAttrStr[MAX_ATTR_STR_LEN]{};
                snprintf(l_formattedAttrStr, MAX_ATTR_STR_LEN, "%s    %s   ", l_attrNamePtr, formatAttributeSize(l_attrIter->dataType));
                o_attrValue.insert(o_attrValue.end(), l_formattedAttrStr, l_formattedAttrStr + strlen(l_formattedAttrStr));
                formatAttributeValue(l_attrIter->dataType, i_attrValuePtr, o_attrValue);
            }
        }
        else
        {
            // The attribute is not in the arr - we don't know its data type. It
            // could be a complexType or an enum. Treat is as an array of bytes
            std::vector<uint32_t>l_dimensions{attrSizeLookup(i_attrId) / UINT8_T_SIZE};
            formatArrayAttrValue(l_attrNamePtr,
                                 UINT8_T_TYPE,
                                 UINT8_T_SIZE,
                                 l_dimensions,
                                 i_attrValuePtr,
                                 o_attrValue);
        }
        }while(0);
    }

    errlHndl_t AttrRP::dumpAttrs()
    {
        errlHndl_t l_errl = nullptr;
#ifdef CONFIG_PLDM

        do {

        if(!TARGETING::targetService().isInitialized())
        {
            TRACFCOMP(g_trac_targeting, WARN_MRK"AttrRP::dumpAttrs: Targeting hasn't been initialized yet. Will not perform attr dump.");
#ifdef CONFIG_CONSOLE
            CONSOLE::displayf(CONSOLE::DEFAULT, NULL, "dumpAttrs: Targeting not initialized. Cannot dump attributes");
#endif
            break;
        }

#ifdef CONFIG_CONSOLE
        CONSOLE::displayf(CONSOLE::DEFAULT, NULL, "dumpAttrs: Dumping attributes via PLDM to LID 0x%x", Util::ATTR_DUMP_LIDID);
#endif
        TargetRangeFilter l_allTargets(targetService().begin(),
                                    targetService().end(),
                                    nullptr);
        size_t l_writeOffset = 0;
        // Walk through all targets and dump all of the attributes
        for(; l_allTargets; ++l_allTargets)
        {
#ifdef CONFIG_CONSOLE
            CONSOLE::displayf(CONSOLE::DEFAULT, NULL, "dumpAttrs: Dumping attributes for target 0x%x", l_allTargets->getAttr<ATTR_HUID>());
#endif

            // A text vector representing target and all its attributes in
            // readable format
            std::vector<char>l_targetAttributes;
            ATTRIBUTE_ID* l_attrIdArr = nullptr;
            AbstractPointer<void>* l_attrAddressesArr = nullptr;
            uint32_t l_attrCnt = targetService().getTargetAttributes(*l_allTargets,
                                                                    &TARG_GET_SINGLETON(theAttrRP),
                                                                    l_attrIdArr,
                                                                    l_attrAddressesArr);
            // First part of the output format is the "target = <FAPI target>"
            // string.
            TARGETING::ATTR_FAPI_NAME_type l_nameString = {0};
            l_allTargets->tryGetAttr<ATTR_FAPI_NAME>(l_nameString);
            char l_str[MAX_ATTR_STR_LEN] {};
            snprintf(l_str, MAX_ATTR_STR_LEN, "target = %s\n", l_nameString);
            l_targetAttributes.insert(l_targetAttributes.end(), l_str, l_str + strlen(l_str));

            // Following is a dump of each attribute and its value
            for(uint32_t l_attrNum =  0; l_attrNum < l_attrCnt; ++l_attrNum)
            {
                ATTRIBUTE_ID* l_attrId = l_attrIdArr + l_attrNum;
                void* l_attrAddr = nullptr;
                l_allTargets->_getAttrPtr(*l_attrId,
                                        &TARG_GET_SINGLETON(theAttrRP),
                                        l_attrIdArr,
                                        l_attrAddressesArr,
                                        l_attrAddr);
                if(l_attrAddr)
                {
                    // Format the attribute value if we found the attr
                    getAttrValueFromMem(l_attrAddr, *l_attrId, l_targetAttributes);
                }
                else
                {
                    TRACFCOMP(g_trac_targeting, WARN_MRK"AttrRP::dumpAttrs: Could not get value of attribute ID 0x%x",
                              *l_attrId);
                }

                // TODO CQ: SW550893 This if statement needs to be removed once
                // the defect is resolved. Currently there are PLDM timeouts
                // when we attempt to write large chunks of data via PLDM file
                // io. This workaround chops those up into page-size chunks,
                // which alleviates the problem (page-size was chosen experimentally).
                if(l_targetAttributes.size() >= PAGESIZE)
                {
                    size_t l_totalWriteSize = l_targetAttributes.size();
                    while(l_totalWriteSize > 0)
                    {
                        size_t l_offsetIntoVector = l_targetAttributes.size() - l_totalWriteSize;
                        uint32_t l_writeSize = (l_totalWriteSize >= PAGESIZE) ? PAGESIZE : l_totalWriteSize;
                        l_errl = PLDM::writeLidFileFromOffset(Util::ATTR_DUMP_LIDID,
                                                              l_writeOffset,
                                                              l_writeSize,
                                                              reinterpret_cast<uint8_t*>(l_targetAttributes.data() + l_offsetIntoVector));
                        if(l_errl)
                        {
                            errlCommit(l_errl, ISTEP_COMP_ID);
                        }
                        l_writeOffset += l_writeSize;
                        l_totalWriteSize -= l_writeSize;
                    }
                    l_targetAttributes.clear();
                }
            }
            // Newline to separate targets
            l_targetAttributes.push_back('\n');

            // Write the attrs for this target to the lid file
            uint32_t l_size = l_targetAttributes.size();
            l_errl = PLDM::writeLidFileFromOffset(Util::ATTR_DUMP_LIDID,
                                                  l_writeOffset,
                                                  l_size,
                                                  reinterpret_cast<uint8_t*>(l_targetAttributes.data()));
            if(l_errl)
            {
                TRACFCOMP(g_trac_targeting, ERR_MRK"AttrRP::dumpAttrs: Could not write to lid file");
                break;
            }
            l_writeOffset += l_size;
        }

        if(!l_errl)
        {
            // Write the end of dump indicator
            char l_doneStr[] = "=====DUMP DONE=====\n";
            uint32_t l_writeSize = strlen(l_doneStr);
            l_errl = PLDM::writeLidFileFromOffset(Util::ATTR_DUMP_LIDID,
                                                  l_writeOffset,
                                                  l_writeSize,
                                                  reinterpret_cast<uint8_t*>(l_doneStr));
            if(l_errl)
            {
                TRACFCOMP(g_trac_targeting, ERR_MRK"AttrRP::dumpAttrs: Could not write done marker to lid file");
            }
        }

#ifdef CONFIG_CONSOLE
        CONSOLE::displayf(CONSOLE::DEFAULT, NULL, "dumpAttrs: Done.");
#endif

        } while(0);
#endif
        return l_errl;
    }
}
