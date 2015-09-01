/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmi/ipmifruinv.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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

#include <vector>
#include <map>
#include <vpd/mvpdenums.H>
#include <devicefw/userif.H>
#include <vpd/spdenums.H>
#include <vpd/cvpdenums.H>
#include <vpd/pvpdenums.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <errl/errlmanager.H>
#include <ipmi/ipmifruinv.H>
#include "ipmifru.H"
#include "ipmifruinvprvt.H"
#include <stdio.h>
#include <assert.h>
#include <pnor/pnorif.H>

extern trace_desc_t * g_trac_ipmi;


/**
 * @brief Compairs two pairs - used for std:sort
 * @param[in] lhs - left pair for comparison
 * @param[in] rhs - right pair for comparison
 */
inline static bool comparePairs(
              const std::pair<TARGETING::TargetHandle_t, uint8_t>& i_lhs,
              const std::pair<TARGETING::TargetHandle_t, uint8_t>& i_rhs)
{
    bool l_compare = i_lhs.second < i_rhs.second;

    // in case of a tie, if the left is a Node, sort it first.
    if (i_lhs.second == i_rhs.second)
    {
        if (TARGETING::TYPE_NODE==i_lhs.first->getAttr<TARGETING::ATTR_TYPE>())
        {
           l_compare = true;
        }
    }
    return l_compare;
}

IpmiFruInv::IpmiFruInv(TARGETING::TargetHandle_t i_target)
    :iv_target(i_target)
{
};

IpmiFruInv::~IpmiFruInv()
{}


IpmiFruInv *IpmiFruInv::Factory(TARGETING::TargetHandleList i_targets,
                                bool i_updateData)
{
    IpmiFruInv *l_fru = NULL;
    TARGETING::TargetHandle_t l_target;

    assert( ! i_targets.empty(),
                "IpmiFruInv::Factory: Input was empty List of Targets");
    l_target = i_targets[0];

    switch (l_target->getAttr<TARGETING::ATTR_TYPE>())
    {
        case TARGETING::TYPE_DIMM:
            l_fru = new isdimmIpmiFruInv(l_target);
            break;
        case TARGETING::TYPE_PROC:
            l_fru = new procIpmiFruInv(l_target, i_updateData);
            break;
        case TARGETING::TYPE_MEMBUF:
            // A memory riser card will have a mem buff with a distinct FRU ID
            l_fru = new membufIpmiFruInv(l_target, i_targets, i_updateData);
            break;
        case TARGETING::TYPE_NODE:
            // When the planar eeprom is shared for planar vpd and memory vpd,
            // the node and membufs will have the same FRU ID. The node has
            // been sorted ahead of the membufs. The membufs are extra targets
            // for their ECIDs.
            l_fru = new backplaneIpmiFruInv(l_target, i_targets, i_updateData);
            break;
        case TARGETING::TYPE_SYS:
            // Use sys target for setting System Firmware Info
            l_fru = new systemFwIpmiFruInv(l_target);
            break;
        default:
            assert(false,
                "IpmiFruInv::Factory: No support for target type given: [%08x]",
                       l_target->getAttr<TARGETING::ATTR_TYPE>());
            break;
    }

    return l_fru;
}

void IpmiFruInv::sendFruData(uint8_t i_deviceId)
{
    if (iv_record_data.size() > 0)
    {
        //Use IMPIFRU::writeData to send data to service processor
        // it will do any error handling and memory management
        IPMIFRU::writeData(i_deviceId, &iv_record_data[0],
                         iv_record_data.size(), IPMIFRUINV::DEFAULT_FRU_OFFSET);
    }
    else
    {
        TRACFCOMP(g_trac_ipmi,"IpmiFruInv::sendFruData: "
                   "Not sending data for deviceId[%08x], no data found for this record.");
    }

    return;
}


void IpmiFruInv::printRecordDebugData(const std::vector<uint8_t> &i_data)
{
    if (i_data.size() > 0)
    {
        TRACFBIN(g_trac_ipmi, "IpmiRecordData", &i_data[0], i_data.size());
    }
    else
    {
        TRACFCOMP(g_trac_ipmi,"IpmiRecordData empty");
    }
}


//This uses the template method design pattern
// Since all IPMI Fru Inventory records all contain the same 5 sections
// (whether they are populated or empty) this funciton will build all 5
// sections, build the header for the entire record, and then combine all 5
// records into one full record
errlHndl_t IpmiFruInv::buildFruInvRecord(void)
{
    errlHndl_t l_errl = NULL;
    std::vector<uint8_t> l_iu_data;
    std::vector<uint8_t> l_ci_data;
    std::vector<uint8_t> l_bi_data;
    std::vector<uint8_t> l_pi_data;
    std::vector<uint8_t> l_mr_data;

    do {
        //First build up all 5 records individually
        l_errl = buildInternalUseArea(l_iu_data);
        if (l_errl) { break; }

        l_errl = buildChassisInfoArea(l_ci_data);
        if (l_errl) { break; }

        l_errl = buildBoardInfoArea(l_bi_data);
        if (l_errl) { break; }

        l_errl = buildProductInfoArea(l_pi_data);
        if (l_errl) { break; }

        l_errl = buildMultiRecordInfoArea(l_mr_data);
        if (l_errl) { break; }

        //Now build common header with data for this FRU Inv Record
        buildCommonHeader(l_iu_data, l_ci_data, l_bi_data,
                          l_pi_data, l_mr_data);

        //Combine everything into one full IPMI Fru Inventory Record
        completeRecord(l_iu_data, l_ci_data, l_bi_data,
                       l_pi_data, l_mr_data);

    } while(0);

    if (l_errl)
    {
        TRACFCOMP(g_trac_ipmi,"IpmiFruInv::buildFruInvRecord Error encountered"
                  " building up Fru Inventory Record sections.");
    }

    return l_errl;
}


void IpmiFruInv::buildCommonHeader(
                                const std::vector<uint8_t> &i_internal_use_data,
                                const std::vector<uint8_t> &i_chassis_data,
                                const std::vector<uint8_t> &i_board_data,
                                const std::vector<uint8_t> &i_product_data,
                                const std::vector<uint8_t> &i_multirecord_data)
{
    //Use this variable to increment size of header as we go along to determine
    //   offset for the subsequent area offsets
    uint32_t l_cur_data_offset = 0;

    //First byte is id for version of FRU Info Storage Spec used
    addHeaderFormat(iv_record_data);

    //2nd byte is offset to internal use data
    buildCommonHeaderSection(iv_record_data, i_internal_use_data.size(),
                                                   l_cur_data_offset);

    //3rd byte is offset to chassis data
    buildCommonHeaderSection(iv_record_data, i_chassis_data.size(),
                                                 l_cur_data_offset);

    //4th byte is offset to board data
    buildCommonHeaderSection(iv_record_data, i_board_data.size(),
                                                  l_cur_data_offset);

    //5th byte is offset to product data
    buildCommonHeaderSection(iv_record_data, i_product_data.size(),
                                                  l_cur_data_offset);

    //6th byte is offset to multirecord data
    buildCommonHeaderSection(iv_record_data, i_multirecord_data.size(),
                                                           l_cur_data_offset);

    //7th byte is PAD
    padData(iv_record_data);

    //8th (Final byte of Header Format) is the checksum
    addDataChecksum(iv_record_data);
}

void IpmiFruInv::completeRecord(const std::vector<uint8_t> &i_internal_use_data,
                                const std::vector<uint8_t> &i_chassis_data,
                                const std::vector<uint8_t> &i_board_data,
                                const std::vector<uint8_t> &i_product_data,
                                const std::vector<uint8_t> &i_multirecord_data)
{
    addDataToRecord(i_internal_use_data);
    addDataToRecord(i_chassis_data);
    addDataToRecord(i_board_data);
    addDataToRecord(i_product_data);
    addDataToRecord(i_multirecord_data);
}

//Helper function to simply combine vectors together
void IpmiFruInv::addDataToRecord(const std::vector<uint8_t> &i_data)
{
    iv_record_data.insert(iv_record_data.end(), i_data.begin(), i_data.end());
}

//Helper function to create an 'empty' record
errlHndl_t IpmiFruInv::buildEmptyArea(std::vector<uint8_t> &i_data)
{
    return NULL;
}

//Helper function to pad a data record. Most of the IPMI Fru Invenotry
// Record format works with each section being a multiple of 8 bytes
// so padding is needed to make records properly formatted
void IpmiFruInv::padData(std::vector<uint8_t> &io_data)
{
    uint8_t l_pad_remainder = (io_data.size() + IPMIFRUINV::CHECKSUM_SIZE) %
                          IPMIFRUINV::RECORD_UNIT_OF_MEASUREMENT;

    if (l_pad_remainder)
    {
        io_data.insert(io_data.end(),
                       IPMIFRUINV::RECORD_UNIT_OF_MEASUREMENT - l_pad_remainder,
                       uint8_t(0));
    }
    return;
}

//Creates a 2's complement checksum at the end of the given data vector
void IpmiFruInv::addDataChecksum(std::vector<uint8_t> &io_data)
{
    uint8_t l_checksum_val = 0;
    std::vector<uint8_t>::iterator l_iter;

    for (l_iter = io_data.begin(); l_iter != io_data.end(); ++l_iter)
    {
        l_checksum_val += *l_iter;
    }

    // Push the Zero checksum as the last byte of this data
    // This appears to be a simple summation of all the bytes
    io_data.push_back(-l_checksum_val);

    return;
}

//The Common Header points to the offset for each of the 5 data record
// sections, this function is used in helping to build that up.
void IpmiFruInv::buildCommonHeaderSection(std::vector<uint8_t> &io_out_data,
                                  uint32_t i_section_data_size,
                                  uint32_t &io_cur_data_offset)
{
    //Check if data for internal use section populated
    if (i_section_data_size == 0)
    {
        //Indicate record not prsent
        io_out_data.push_back(IPMIFRUINV::RECORD_NOT_PRESENT);
    }
    else {
        //Place data to define offset to internal_use_data section
        io_out_data.push_back((io_cur_data_offset +
                                  IPMIFRUINV::COMMON_HEADER_FORMAT_SIZE)
                                  / IPMIFRUINV::RECORD_UNIT_OF_MEASUREMENT);
        io_cur_data_offset += i_section_data_size;
    }

    return;
}

//Helper function to add the IPMI Fru Inventory Format to the
// beginning of the data vector passed in
void IpmiFruInv::addHeaderFormat(std::vector<uint8_t> &io_data)
{
    //Add id for version of FRU Info Storage Spec used
    io_data.push_back(IPMIFRUINV::SPEC_VERSION);
    return;
}

//Helper function to complete the formatting for a given section
// that can be completed prior to adding section data
// It will add the spec version, create a placeholder for the data
//    size and set the language code if desired
void IpmiFruInv::preFormatProcessing(std::vector<uint8_t> &io_data,
                                   bool i_setLanguageCode)
{
    //Add id for version of FRU Info Storage Spec used
    addHeaderFormat(io_data);

    //Add Data Size - 0 as a placeholder, can edit after the data is finalized
    io_data.push_back(uint8_t(0));

    if (i_setLanguageCode)
    {
        //Add Language Code
        io_data.push_back(uint8_t(IPMIFRUINV::ENGLISH_LANGUAGE_CODE));
    }
}
//Helper function to complete the formatting for a given section
// It will calculate overall section size,
// pad the section if needed, and add the data checksum
void IpmiFruInv::postFormatProcessing(std::vector<uint8_t> &io_data)
{
    //This area needs to be padded to a multiple of 8 bytes (after checksum)
    padData(io_data);

    //Set size of data info area
    setAreaSize(io_data, 1);

    //Finally add board info checksum
    addDataChecksum(io_data);

    return;
}

//Helper function containing the logic to set the proper size of a data section
void IpmiFruInv::setAreaSize(std::vector<uint8_t> &io_data, uint8_t i_offset)
{

    io_data.at(i_offset) = (io_data.size() + IPMIFRUINV::CHECKSUM_SIZE)
                             / IPMIFRUINV::RECORD_UNIT_OF_MEASUREMENT;

    return;
}

//##############################################################################
isdimmIpmiFruInv::isdimmIpmiFruInv( TARGETING::TargetHandle_t i_target )
    :IpmiFruInv(i_target)
{

};

errlHndl_t isdimmIpmiFruInv::buildInternalUseArea(std::vector<uint8_t> &io_data)
{
    //This section not needed for isdimm type
    return IpmiFruInv::buildEmptyArea(io_data);
}

errlHndl_t isdimmIpmiFruInv::buildChassisInfoArea(std::vector<uint8_t> &io_data)
{
    //This section not needed for isdimm type
    return IpmiFruInv::buildEmptyArea(io_data);
}

errlHndl_t isdimmIpmiFruInv::buildBoardInfoArea(std::vector<uint8_t> &io_data)
{
    //This section not needed for isdimm type
    return IpmiFruInv::buildEmptyArea(io_data);
}

errlHndl_t isdimmIpmiFruInv::buildMultiRecordInfoArea(
                                                  std::vector<uint8_t> &io_data)
{
    //This section not needed for isdimm type
    return IpmiFruInv::buildEmptyArea(io_data);
}

errlHndl_t isdimmIpmiFruInv::buildProductInfoArea(std::vector<uint8_t> &io_data)
{
    errlHndl_t l_errl = NULL;

    do {
        //Set formatting data that goes at the beginning of the record
        preFormatProcessing(io_data, true);

        //Set Manufacturer's Name - Use JEDEC standard MFG ID
        l_errl = addVpdData(io_data, SPD::MODULE_MANUFACTURER_ID);
        if (l_errl) { break; }
        //Set Product Name - Use Basic SPD Memory Type
        l_errl = addVpdData(io_data, SPD::BASIC_MEMORY_TYPE);
        if (l_errl) { break; }
        //Set Product Part/Model Number
        l_errl = addVpdData(io_data, SPD::MODULE_PART_NUMBER, true);
        if (l_errl) { break; }
        //Set Product Version
        l_errl = addVpdData(io_data, SPD::MODULE_REVISION_CODE);
        if (l_errl) { break; }
        //Set Product Serial Number
        l_errl = addVpdData(io_data, SPD::MODULE_SERIAL_NUMBER);
        if (l_errl) { break; }

        //Add Asset Tag
        io_data.push_back(uint8_t(0)); //No Asset Tag needed - O bytes

        //FRU File ID - Empty
        io_data.push_back(IPMIFRUINV::TYPELENGTH_BYTE_NULL);
        io_data.push_back(uint8_t(0)); // Empty FRU File ID bytes
        io_data.push_back(IPMIFRUINV::END_OF_CUSTOM_FIELDS);

    } while (0);

    //Finalize section formatting
    postFormatProcessing(io_data);

    if (l_errl)
    {
        TRACFCOMP(g_trac_ipmi,"isdimIpmiFruInv::buildProductInfoArea - Errors "
                              "collecting product info data from VPD");
    }

    return l_errl;
}

errlHndl_t isdimmIpmiFruInv::addVpdData(std::vector<uint8_t> &io_data,
                                     uint8_t i_keyword,
                                     bool i_ascii)
{
    size_t     l_vpdSize = 0;
    errlHndl_t l_errl = NULL;

    do {
        //First get size with NULL call:
        l_errl = deviceRead(iv_target,
                                       NULL,
                                       l_vpdSize,
                                       DEVICE_SPD_ADDRESS(i_keyword));

        if (l_errl)
        {
            TRACFCOMP(g_trac_ipmi,"isdimmIpmiFruInv::addVpdData - "
                      "Error while reading SPD keyword size");
            break;
        }

        //Assert if vpd field is too large to fit in IPMI fru inventory format
        assert(l_vpdSize < IPMIFRUINV::TYPELENGTH_BYTE_ASCII);

        if (l_vpdSize > 0)
        {
            //Determine how big data is and expand it to handle the soon to
            //be read VPD data
            uint8_t l_offset = io_data.size();
            io_data.resize(l_offset + 1 + l_vpdSize);

            //Add on the data to the type/length byte indicating it is ascii
            // otherwise leave it as binary
            if (i_ascii)
            {
                io_data.at(l_offset) = l_vpdSize
                                       + IPMIFRUINV::TYPELENGTH_BYTE_ASCII;
            }
            else
            {
                io_data.at(l_offset) = l_vpdSize;
            }
            l_offset += 1;

            //Read the VPD data directly into fru inventory data buffer
            l_errl = deviceRead(iv_target,&io_data[l_offset], l_vpdSize,
                       DEVICE_SPD_ADDRESS(i_keyword));
        }
        else
        {
            TRACFCOMP(g_trac_ipmi,"isdimmIpmiFruInv::addVpdData - "
                      " No size returned for SPD keyword");
        }

    } while(0);

    if (l_errl)
    {
        TRACFCOMP(g_trac_ipmi, "addVpdData - Error acquiring data from Vpd.");
    }

    return l_errl;
}

//##############################################################################
procIpmiFruInv::procIpmiFruInv( TARGETING::TargetHandle_t i_target,
                                bool i_isUpdate )
    :IpmiFruInv(i_target),
    iv_isUpdate(i_isUpdate)
{
};

errlHndl_t procIpmiFruInv::buildInternalUseArea(std::vector<uint8_t> &io_data)
{
    //This section not needed for proc type
    return IpmiFruInv::buildEmptyArea(io_data);
}

errlHndl_t procIpmiFruInv::buildChassisInfoArea(std::vector<uint8_t> &io_data)
{
    //This section not needed for proc type
    return IpmiFruInv::buildEmptyArea(io_data);
}

errlHndl_t procIpmiFruInv::buildBoardInfoArea(std::vector<uint8_t> &io_data)
{
    errlHndl_t l_errl = NULL;

    do {
        //Set formatting data that goes at the beginning of the record
        preFormatProcessing(io_data, true);

        //MFG Date/Time - Blank
        io_data.push_back(0);
        io_data.push_back(0);
        io_data.push_back(0);

        //Board Manufacturer - IBM
        //Board MFG - Type/Length Byte
        // - Indicate 8-bit Ascii + Latin 1 (0xC0)
        // - and a size of 3 for "IBM" - 0x3
        // - add together and the value for this byte is 0xC3
        io_data.push_back(0xC3);
        // - Now put in 'IBM'
        io_data.push_back('I');
        io_data.push_back('B');
        io_data.push_back('M');

        //Set Board Info description
        l_errl = addVpdData(io_data, MVPD::VINI, MVPD::DR, true);
        if (l_errl) { break; }
        //Set Board Info serial number
        l_errl = addVpdData(io_data, MVPD::VRML, MVPD::SN, true);
        if (l_errl) { break; }
        //Set Board part number
        l_errl = addVpdData(io_data, MVPD::VRML, MVPD::PN, true);
        if (l_errl) { break; }
        //Set Board FRU File ID
        l_errl = addVpdData(io_data, MVPD::VINI, MVPD::VZ);
        if (l_errl) { break; }

        //Push Fru File ID Byte - NULL
        io_data.push_back(IPMIFRUINV::TYPELENGTH_BYTE_NULL);

        //Get ECID Data
        TARGETING::ATTR_ECID_type ecidInfo;
        bool getEcid = iv_target->tryGetAttr<TARGETING::ATTR_ECID>(ecidInfo);
        //Only add ECID Data if in an update scenario
        if (getEcid && iv_isUpdate == true)
        {
            addEcidData(iv_target, ecidInfo, io_data);
        }
        else
        {
            //Indicate no custom fields if ecid data not found
            io_data.push_back(IPMIFRUINV::TYPELENGTH_BYTE_NULL);
        }

        //Indicate end of custom fields
        io_data.push_back(IPMIFRUINV::END_OF_CUSTOM_FIELDS);

    } while (0);

    //Complete formatting for this data record
    postFormatProcessing(io_data);

    if (l_errl)
    {
        TRACFCOMP(g_trac_ipmi,"buildBoardInfoArea - Errors Collecting ISDimm "
                  "FRU Inventory Board Info Data");
    }

    return l_errl;
}

errlHndl_t procIpmiFruInv::buildProductInfoArea(std::vector<uint8_t> &io_data)
{
    //This section not needed for proc type
    return IpmiFruInv::buildEmptyArea(io_data);
}

errlHndl_t procIpmiFruInv::buildMultiRecordInfoArea(
                                                 std::vector<uint8_t> &io_data)
{
    //This section not needed for proc type
    return IpmiFruInv::buildEmptyArea(io_data);
}

errlHndl_t procIpmiFruInv::addVpdData(std::vector<uint8_t> &io_data,
                                     uint8_t i_record,
                                     uint8_t i_keyword,
                                     bool i_ascii,
                                     bool i_typeLengthByte)
{
    errlHndl_t l_errl = NULL;

    l_errl = addCommonVpdData(iv_target,
                              io_data,
                              DeviceFW::MVPD,
                              i_record,
                              i_keyword,
                              i_ascii,
                              i_typeLengthByte);
    return l_errl;
}


//##############################################################################
backplaneIpmiFruInv::backplaneIpmiFruInv( TARGETING::TargetHandle_t i_target,
                                     TARGETING::TargetHandleList i_extraTargets,
                                     bool i_isUpdate)
    :IpmiFruInv(i_target),
    iv_isUpdate(i_isUpdate),
    iv_extraTargets(i_extraTargets)
{
};

errlHndl_t backplaneIpmiFruInv::buildInternalUseArea(
                                                 std::vector<uint8_t> &io_data)
{
    //This section not needed for the backplane type
    return IpmiFruInv::buildEmptyArea(io_data);
}

errlHndl_t backplaneIpmiFruInv::buildChassisInfoArea(
                                                  std::vector<uint8_t> &io_data)
{
    errlHndl_t l_errl = NULL;

    do {
        //Set formatting data that goes at the beginning of the record
        preFormatProcessing(io_data, false);
        //Set Chassis Enclosure Type - Not Ascii
        // Also, do not include type/length byte
        l_errl = addVpdData(io_data, PVPD::OSYS, PVPD::ET, false, false);

        //Support Legacy VPD without OSYS record
        if (l_errl)
        {
            TRACFCOMP(g_trac_ipmi,"backplaneIpmiFruInv::buildChassisInfoArea - "
                      " Using Legacy Chassis VPD Data");
            //Delete errorlog and use Default data and Legacy VPD Fields
            delete l_errl;
            l_errl = NULL;

            //Set default chassis type
            io_data.push_back(IPMIFRUINV::DEFAULT_CHASSIS_TYPE);
            //Set chassis part number - ascii formatted field
            l_errl = addVpdData(io_data, PVPD::OPFR, PVPD::VP, true);
            if (l_errl) { break; }
            //Set chassis serial number - ascii formatted field
            l_errl = addVpdData(io_data, PVPD::OPFR, PVPD::VS, true);
            if (l_errl) { break; }
        }
        else
        {
            TRACFCOMP(g_trac_ipmi,"backplaneIpmiFruInv::buildChassisInfoArea - "
                      " Using NEW OSYS RECORD FOR Chassis VPD Data");

            //Set chassis part number - ascii formatted field
            l_errl = addVpdData(io_data, PVPD::OSYS, PVPD::MM, true);
            if (l_errl) { break; }

            //Set chassis serial number - ascii formatted field
            l_errl = addVpdData(io_data, PVPD::OSYS, PVPD::SS, true);
            if (l_errl) { break; }

        }

        //Indicate no custom fields
        io_data.push_back(IPMIFRUINV::TYPELENGTH_BYTE_NULL);
        io_data.push_back(IPMIFRUINV::END_OF_CUSTOM_FIELDS);

    } while (0);

    //Complete record data formatting
    postFormatProcessing(io_data);

    if (l_errl)
    {
        TRACFCOMP(g_trac_ipmi,"backplaneIpmiFruInv::buildChassisInfoArea - "
                  "Errors collecting chassis info data");
    }

    return l_errl;
}

errlHndl_t backplaneIpmiFruInv::buildBoardInfoArea(
                                              std::vector<uint8_t> &io_data)
{
    errlHndl_t l_errl = NULL;

    do {
        //Set formatting data that goes at the beginning of the record
        preFormatProcessing(io_data, true);

        //Set MFG Date/Time - Blank
        io_data.push_back(0);
        io_data.push_back(0);
        io_data.push_back(0);


        //Set Vendor Name - ascii formatted data
        l_errl = addVpdData(io_data, PVPD::OPFR, PVPD::VN, true);
        if (l_errl) { break; }

        //Set Product Name - ascii formatted data
        l_errl = addVpdData(io_data, PVPD::OPFR, PVPD::DR, true);
        if (l_errl) { break; }

        //Set Product Serial number - ascii formatted data
        TARGETING::ATTR_SERIAL_NUMBER_type l_sn = {'0'};
        if( !( iv_target->
                 tryGetAttr<TARGETING::ATTR_SERIAL_NUMBER>
                     ( l_sn) ) )
        {
            // Should not fail. Need to use tryGetAttr due to complex type.
            // Use zeros if fails.
            TRACFCOMP(g_trac_ipmi,"backplaneIpmiFruInv::buildBoardInfoArea - "
                  "Error getting serial number attribute");
        }
        // The attribute size is 18. The vpd is 16. Only use 16.
        addCommonAttrData(io_data,
                          (uint8_t *)&l_sn,
                          VPD_SN_PN_VPD_SIZE);

        //Set Product Part number - ascii formatted data
        TARGETING::ATTR_PART_NUMBER_type l_pn = {'0'};
        if( !( iv_target->
                 tryGetAttr<TARGETING::ATTR_PART_NUMBER>
                     ( l_pn) ) )
        {
            // Should not fail. Need to use tryGetAttr due to complex type.
            // Use zeros if fails.
            TRACFCOMP(g_trac_ipmi,"backplaneIpmiFruInv::buildBoardInfoArea - "
                  "Error getting part number attribute");
        }

        // The attribute size is 18. The vpd is 16. Only use 16.
        addCommonAttrData(io_data,
                          (uint8_t *)&l_pn,
                          VPD_SN_PN_VPD_SIZE);

        //Push Fru File ID Byte - NULL
        io_data.push_back(IPMIFRUINV::TYPELENGTH_BYTE_NULL);
        //Indicate End of Custom Fields
        io_data.push_back(IPMIFRUINV::END_OF_CUSTOM_FIELDS);


    } while (0);

    //Complete record data formatting
    postFormatProcessing(io_data);

    if (l_errl)
    {
        TRACFCOMP(g_trac_ipmi,"backplaneIpmiFruInv::buildBoardInfoArea - "
                  "Errors collecting board info data");
    }

    return l_errl;
}

errlHndl_t backplaneIpmiFruInv::buildProductInfoArea(
                                                  std::vector<uint8_t> &io_data)
{
    //This section not needed for the backplane type
    return IpmiFruInv::buildEmptyArea(io_data);
}

errlHndl_t backplaneIpmiFruInv::buildMultiRecordInfoArea(
                                                  std::vector<uint8_t> &io_data)
{
    //This section not needed for the backplane type
    return IpmiFruInv::buildEmptyArea(io_data);
}

errlHndl_t backplaneIpmiFruInv::addVpdData(std::vector<uint8_t> &io_data,
                                     uint8_t i_record,
                                     uint8_t i_keyword,
                                     bool i_ascii,
                                     bool i_typeLengthByte)

{
    errlHndl_t l_errl = NULL;

    l_errl = addCommonVpdData(iv_target,
                              io_data,
                              DeviceFW::PVPD,
                              i_record,
                              i_keyword,
                              i_ascii,
                              i_typeLengthByte);

    return l_errl;
}

//##############################################################################
systemFwIpmiFruInv::systemFwIpmiFruInv( TARGETING::TargetHandle_t i_target )
    :IpmiFruInv(i_target)
{

};

errlHndl_t systemFwIpmiFruInv::buildInternalUseArea(std::vector<uint8_t>
                                                                       &io_data)
{
    //This section not needed for system firmware type
    return IpmiFruInv::buildEmptyArea(io_data);
}

errlHndl_t systemFwIpmiFruInv::buildChassisInfoArea(std::vector<uint8_t>
                                                                       &io_data)
{
    //This section not needed for system firmware type
    return IpmiFruInv::buildEmptyArea(io_data);
}

errlHndl_t systemFwIpmiFruInv::buildBoardInfoArea(std::vector<uint8_t> &io_data)
{
    //This section not needed for system firmware type
    return IpmiFruInv::buildEmptyArea(io_data);
}

errlHndl_t systemFwIpmiFruInv::buildProductInfoArea(std::vector<uint8_t>
                                                                       &io_data)
{
    errlHndl_t l_errl = NULL;

    do {
        //Set formatting data that goes at the beginning of the record
        preFormatProcessing(io_data, true);

        uint8_t l_data[] = {IPMIFRUINV::TYPELENGTH_BYTE_NULL,
                            IPMIFRUINV::TYPELENGTH_BYTE_ASCII + 18, 'O','p','e',
                            'n','P','O','W','E','R',' ','F','i','r','m','w','a',
                            'r','e', IPMIFRUINV::TYPELENGTH_BYTE_NULL};

        io_data.insert( io_data.end(),
                    &l_data[0],
                    &l_data[0] + (uint8_t(sizeof(l_data) / sizeof(uint8_t))));

        //Get PNOR Version Here
        PNOR::SectionInfo_t l_pnorInfo;
        l_errl = getSectionInfo( PNOR::VERSION , l_pnorInfo);
        if (l_errl) { break; }

        uint8_t* l_versionData = reinterpret_cast<uint8_t*>( l_pnorInfo.vaddr );
        //Total Bytes in PNOR Version String
        uint8_t l_numBytes = 0;
        uint8_t l_curOffset = 0;

        //Total Number of fields needed to print PNOR Version String
        uint8_t l_numFields = 0;
        bool l_clearStandardFields = true;

        //First determine number of bytes in PNOR Version string
        //  with the caveat there is a max record size allowed, so
        //  the string will be cut off if too long
        //Also, remove newline chars
        while ((l_numBytes < IPMIFRUINV::MAX_RECORD_SIZE -
                              (uint8_t(sizeof(l_data) / sizeof(uint8_t))) -
                              IPMIFRUINV::COMMON_HEADER_FORMAT_SIZE - 8)
                               && (((char)(l_versionData[l_numBytes])) != '\0'))
        {

            if (((char)(l_versionData[l_numBytes])) == '\n')
            {

                if (l_numBytes > l_curOffset)
                {
                    //Add on size of this field to the data buffer
                    io_data.push_back(
                         IPMIFRUINV::TYPELENGTH_BYTE_ASCII
                           + (l_numBytes-l_curOffset));

                    io_data.insert(io_data.end(),
                       &l_versionData[0]+(l_curOffset),
                       &l_versionData[0]+(l_numBytes));
                }

                //Null data for standard fields needs to be indicated once after
                // the first segment of data is displayed to match the
                // ipmi fru spec
                if (l_clearStandardFields)
                {
                    //Add Empty Asset Tag
                    io_data.push_back(uint8_t(0));
                    //FRU File ID - Empty
                    io_data.push_back(IPMIFRUINV::TYPELENGTH_BYTE_NULL);
                    io_data.push_back(uint8_t(0)); // Empty FRU File ID bytes
                    l_clearStandardFields = false;
                }

                //Increment past the newline char
                l_curOffset = l_numBytes + 1;
            }
            l_numBytes++;
        }

        if (l_curOffset == 0)
        {
            //Calculate the number of fields required to display this data
            //  given only MAX_ASCII_FIELD_SIZE bytes can be in any one given
            //  IPMI fru inventory field
            l_numFields = l_numBytes / IPMIFRUINV::MAX_ASCII_FIELD_SIZE;
            if (l_numBytes % IPMIFRUINV::MAX_ASCII_FIELD_SIZE)
            {
                l_numFields += 1;
            }

            //Count by number of fields, adding the data to the buffer as
            // we go.
            for (uint8_t i=0; i < l_numFields; i++)
            {
                //Determine the data size for this particular field
                uint8_t l_dataSize=IPMIFRUINV::MAX_ASCII_FIELD_SIZE;
                if (i == l_numFields - 1)
                {
                    l_dataSize = l_numBytes -
                           (i * IPMIFRUINV::MAX_ASCII_FIELD_SIZE);
                }

                //Add on size of this field to the data buffer
                io_data.push_back(IPMIFRUINV::TYPELENGTH_BYTE_ASCII
                                         + l_dataSize);

                //Insert this segment of version string data
                io_data.insert(io_data.end(),
                       &l_versionData[0]+(i * IPMIFRUINV::MAX_ASCII_FIELD_SIZE),
                       &l_versionData[0]+(i * IPMIFRUINV::MAX_ASCII_FIELD_SIZE)
                                        +l_dataSize);

                //Null data for standard fields needs to be indicated once after
                // the first segment of data is displayed to match the
                // ipmi fru spec
                if (l_clearStandardFields)
                {
                    //Add Empty Asset Tag
                    io_data.push_back(uint8_t(0));
                    //FRU File ID - Empty
                    io_data.push_back(IPMIFRUINV::TYPELENGTH_BYTE_NULL);
                    l_clearStandardFields = false;
                }

            }
        }
        else
        {
            if (l_numBytes > l_curOffset)
            {
                io_data.push_back( IPMIFRUINV::TYPELENGTH_BYTE_ASCII
                        + (l_numBytes-l_curOffset));

                io_data.insert(io_data.end(),
                       &l_versionData[0]+(l_curOffset),
                       &l_versionData[0]+(l_numBytes));
            }

        }

        if (l_clearStandardFields)
        {
            //Add Asset Tag
            io_data.push_back(uint8_t(0)); //No Asset Tag needed - O bytes
            //FRU File ID - Empty
            io_data.push_back(IPMIFRUINV::TYPELENGTH_BYTE_NULL);
        }

        io_data.push_back(IPMIFRUINV::END_OF_CUSTOM_FIELDS);

    } while(0);

    //Finalize section formatting
    postFormatProcessing(io_data);

    return l_errl;
}

errlHndl_t systemFwIpmiFruInv::buildMultiRecordInfoArea(std::vector<uint8_t>
                                                                       &io_data)
{
    //This section not needed for system firmware type
    return IpmiFruInv::buildEmptyArea(io_data);
}

//##############################################################################
membufIpmiFruInv::membufIpmiFruInv( TARGETING::TargetHandle_t i_target,
                                     TARGETING::TargetHandleList i_extraTargets,
                                     bool i_isUpdate)
    :IpmiFruInv(i_target),
    iv_isUpdate(i_isUpdate),
    iv_extraTargets(i_extraTargets)
{
};

errlHndl_t membufIpmiFruInv::buildInternalUseArea(
                                                 std::vector<uint8_t> &io_data)
{
    //This section not needed for the mem buf type
    return IpmiFruInv::buildEmptyArea(io_data);
}

errlHndl_t membufIpmiFruInv::buildChassisInfoArea(
                                                  std::vector<uint8_t> &io_data)
{
    //This section not needed for the mem buf type
    return IpmiFruInv::buildEmptyArea(io_data);
}

errlHndl_t membufIpmiFruInv::buildBoardInfoArea(
                                              std::vector<uint8_t> &io_data)
{
    errlHndl_t l_errl = NULL;

    do {
        //Set formatting data that goes at the beginning of the record
        preFormatProcessing(io_data, true);

        //Set MFG Date/Time - Blank
        io_data.push_back(0);
        io_data.push_back(0);
        io_data.push_back(0);

        uint8_t l_fru_id = 0xFF;
        // if the centaur_ecid_fru_id is not valid then the centaur is on a
        // riser card, grab its vpd and populate the record
        l_fru_id = iv_target->getAttr<TARGETING::ATTR_CENTAUR_ECID_FRU_ID>();

        if( l_fru_id == 0xFF )
        {
            //Set Vendor Name - ascii formatted data
            l_errl = addVpdData(io_data, CVPD::OPFR, CVPD::VN, true);
            if (l_errl) { break; }

            //Set Product Name - ascii formatted data
            l_errl = addVpdData(io_data, CVPD::OPFR, CVPD::DR, true);
            if (l_errl) { break; }

            //Set Product Serial number - ascii formatted data
            TARGETING::ATTR_SERIAL_NUMBER_type l_sn = {'0'};
            if( !( iv_target->
                        tryGetAttr<TARGETING::ATTR_SERIAL_NUMBER>
                        ( l_sn) ) )
            {
                // Should not fail. Need to use tryGetAttr due to complex type.
                // Use zeros if fails.
                TRACFCOMP(g_trac_ipmi,"membufIpmiFruInv::buildBoardInfoArea - "
                        "Error getting serial number attribute");
            }
            // The attribute size is 18. The vpd is 16. Only use 16.
            addCommonAttrData(io_data,
                    (uint8_t *)&l_sn,
                    VPD_SN_PN_VPD_SIZE);

            //Set Product Part number - ascii formatted data
            TARGETING::ATTR_PART_NUMBER_type l_pn = {'0'};
            if( !( iv_target->
                        tryGetAttr<TARGETING::ATTR_PART_NUMBER>
                        ( l_pn) ) )
            {
                // Should not fail. Need to use tryGetAttr due to complex type.
                // Use zeros if fails.
                TRACFCOMP(g_trac_ipmi,"membufIpmiFruInv::buildBoardInfoArea - "
                        "Error getting part number attribute");
            }
            // The attribute size is 18. The vpd is 16. Only use 16.
            addCommonAttrData(io_data,
                    (uint8_t *)&l_pn,
                    VPD_SN_PN_VPD_SIZE);

            //Push Fru File ID Byte - NULL
            io_data.push_back(IPMIFRUINV::TYPELENGTH_BYTE_NULL);

        }
        else
        {
            //Set Vendor Name - NULL
            io_data.push_back(IPMIFRUINV::TYPELENGTH_BYTE_NULL);

            //Set Product Name - NULL
            io_data.push_back(IPMIFRUINV::TYPELENGTH_BYTE_NULL);

            //Set Product Serial number - NULL
            io_data.push_back(IPMIFRUINV::TYPELENGTH_BYTE_NULL);

            //Set Product Part number - NULL
            io_data.push_back(IPMIFRUINV::TYPELENGTH_BYTE_NULL);

            //Push Fru File ID Byte - NULL
            io_data.push_back(IPMIFRUINV::TYPELENGTH_BYTE_NULL);

        }

        //Only set the ECID Data during an update scenario
        if (iv_isUpdate == true)
        {
            customEcidData (iv_extraTargets, io_data);
        }

        //Indicate End of Custom Fields
        io_data.push_back(IPMIFRUINV::END_OF_CUSTOM_FIELDS);

    } while (0);

    //Complete record data formatting
    postFormatProcessing(io_data);

    if (l_errl)
    {
        TRACFCOMP(g_trac_ipmi,"membufIpmiFruInv::buildBoardInfoArea - "
                "Errors collecting board info data");
    }

    return l_errl;
}

errlHndl_t membufIpmiFruInv::buildProductInfoArea(
        std::vector<uint8_t> &io_data)
{
    //This section not needed for the mem buf type
    return IpmiFruInv::buildEmptyArea(io_data);
}

errlHndl_t membufIpmiFruInv::buildMultiRecordInfoArea(
        std::vector<uint8_t> &io_data)
{
    //This section not needed for the mem buf type
    return IpmiFruInv::buildEmptyArea(io_data);
}

errlHndl_t membufIpmiFruInv::addVpdData(std::vector<uint8_t> &io_data,
        uint8_t i_record,
        uint8_t i_keyword,
        bool i_ascii,
        bool i_typeLengthByte)
{
    errlHndl_t l_errl = NULL;

    l_errl = addCommonVpdData(iv_target,
            io_data,
            DeviceFW::CVPD,
            i_record,
            i_keyword,
            i_ascii,
            i_typeLengthByte);
    return l_errl;
}
//##############################################################################
void IpmiFruInv::customEcidData(TARGETING::TargetHandleList i_extraTargets,
                     std::vector<uint8_t> &io_data)
{

    bool l_setCustomData = false;
    // Check if we should add ECID
    for (TARGETING::TargetHandleList::const_iterator extraTargets_it =
                i_extraTargets.begin();
                extraTargets_it != i_extraTargets.end();
                ++extraTargets_it
            )
    {
        TARGETING::TargetHandle_t l_extraTarget = *extraTargets_it;

        //Only set the ECID Data during an update scenario
        if ( l_extraTarget->getAttr<TARGETING::ATTR_TYPE>() ==
                                                        TARGETING::TYPE_MEMBUF)
        {
            TARGETING::ATTR_ECID_type ecidInfo;
            bool getEcid =
                      l_extraTarget->tryGetAttr<TARGETING::ATTR_ECID>(ecidInfo);
            if (getEcid)
            {
                l_setCustomData = true;
                addEcidData(l_extraTarget, ecidInfo, io_data);
            }
            else
            {
               TRACFCOMP(g_trac_ipmi, "No ECID info for this huid 0x%x",
                          TARGETING::get_huid(l_extraTarget));
            }
        }
    }

    //If no Custom data was sent, an Empty Byte is needed
    if (!l_setCustomData)
    {
        io_data.push_back(IPMIFRUINV::TYPELENGTH_BYTE_NULL);
    }
}

void IpmiFruInv::addEcidData(const TARGETING::TargetHandle_t& i_target,
                             const TARGETING::ATTR_ECID_type& i_ecidInfo,
                             std::vector<uint8_t> &io_data)
{
    // Create Custom ECID Field
    // - First put in 'ECID:' to make it obvious what this is
    uint8_t l_data[] = {IPMIFRUINV::TYPELENGTH_BYTE_ASCII + 37,'E','C','I','D',
                                    ':'};

    // @todo-RTC:124687 - Refactor multiple reallocations
    io_data.insert( io_data.end(),
                    &l_data[0],
                    &l_data[0] + (uint8_t(sizeof(l_data) / sizeof(uint8_t))));

    CPPASSERT(sizeof(ATTR_ECID_type) == 16);
    CPPASSERT((sizeof(i_ecidInfo) / sizeof(ATTR_ECID_type)) == 2);

    char l_ecidAscii[33];
    sprintf(l_ecidAscii, "%.16llX%.16llX", i_ecidInfo[0], i_ecidInfo[1]);

    uint8_t* l_vDataPtr = (uint8_t*) &l_ecidAscii[0];
    io_data.insert(io_data.end(), &l_vDataPtr[0], &l_vDataPtr[0]+32);

    return;
}

errlHndl_t IpmiFruInv::addCommonVpdData(
                                     const TARGETING::TargetHandle_t& i_target,
                                     std::vector<uint8_t> &io_data,
                                     DeviceFW::AccessType i_accessType,
                                     uint8_t i_record,
                                     uint8_t i_keyword,
                                     bool i_ascii,
                                     bool i_typeLengthByte)
{
    size_t     l_vpdSize = 0;
    errlHndl_t l_errl = NULL;

    do {
        // First get size with NULL call:
        // Bypass DEVICE_?VPD_ADDRESS inorder to maximize common code
        l_errl = deviceRead(i_target,
                            NULL,
                            l_vpdSize,
                            i_accessType,
                            i_record,
                            i_keyword,
                            VPD::AUTOSELECT);

        if (l_errl)
        {
            TRACFCOMP(g_trac_ipmi,"addCommonVpdData - Error "
                      "while reading keyword size");
            break;
        }

        //Assert if vpd field is too large to fit in IPMI fru inventory format
        assert(l_vpdSize < IPMIFRUINV::TYPELENGTH_BYTE_ASCII);

        if (l_vpdSize > 0)
        {
            uint8_t l_offset = 0;
            //Add on the typelength byte if requested
            if (i_typeLengthByte)
            {
                //Determine how big data is and expand it to handle the soon to
                //be read VPD data
                l_offset = io_data.size();
                io_data.resize(l_offset + 1 + l_vpdSize);
                //Add on the data to the type/length byte indicating it is ascii
                // otherwise leave it as binary
                if (i_ascii)
                {
                    io_data.at(l_offset) = l_vpdSize
                                           + IPMIFRUINV::TYPELENGTH_BYTE_ASCII;
                }
                else
                {
                    io_data.at(l_offset) = l_vpdSize;
                }
                l_offset += 1;
            }
            else
            {
                //Determine how big data is and expand it to handle the soon to
                //be read VPD data
                l_offset = io_data.size();
                io_data.resize(l_offset + l_vpdSize);
            }
            //Read the VPD data directly into fru inventory data buffer
            l_errl = deviceRead(i_target,
                            &io_data[l_offset],
                            l_vpdSize,
                            i_accessType,
                            i_record,
                            i_keyword,
                            VPD::AUTOSELECT);
        }
        else
        {
            TRACFCOMP(g_trac_ipmi,"addCommonVpdData - "
                      " No size returned for keyword");
        }
    } while(0);

    if (l_errl)
    {
        TRACFCOMP(g_trac_ipmi, "addCommonVpdData - Error "
                  "acquiring data from Vpd.");
    }

    return l_errl;
}

void IpmiFruInv::addCommonAttrData( std::vector<uint8_t> &io_data,
                                    uint8_t * i_pAttrData,
                                    size_t    i_length)
{
    uint8_t l_offset = io_data.size();

    //Determine how big data is and expand it to handle the attr data
    //and the typelength byte
    io_data.resize(l_offset + 1 + i_length);

    //Add the type/length byte indicating ascii data.
    io_data.at(l_offset) = i_length + IPMIFRUINV::TYPELENGTH_BYTE_ASCII;

    //copy attr data
    memcpy (&io_data[l_offset+1],i_pAttrData,i_length);
}


void IPMIFRUINV::clearData(uint8_t i_fruId)
{
    uint8_t l_clearData[] =
        {IPMIFRUINV::RECORD_NOT_PRESENT, IPMIFRUINV::RECORD_NOT_PRESENT,
         IPMIFRUINV::RECORD_NOT_PRESENT, IPMIFRUINV::RECORD_NOT_PRESENT,
         IPMIFRUINV::RECORD_NOT_PRESENT, IPMIFRUINV::RECORD_NOT_PRESENT,
         IPMIFRUINV::RECORD_NOT_PRESENT, IPMIFRUINV::RECORD_NOT_PRESENT};

    //Use IMPIFRU::writeData to send data to service processor
    IPMIFRU::writeData(i_fruId, l_clearData,
                        IPMIFRUINV::COMMON_HEADER_FORMAT_SIZE,
                        IPMIFRUINV::DEFAULT_FRU_OFFSET);
}

void IPMIFRUINV::setData(bool i_updateData)
{
    errlHndl_t l_errl = NULL;

    do
    {
        // find CLASS_SYS (the top level target)
        TARGETING::Target* pSys;
        TARGETING::targetService().getTopLevelTarget(pSys);

        if (!(pSys))
        {
            TRACFCOMP(g_trac_ipmi,"IPMIFRUINV::setData - No CLASS_SYS TopLevelTarget found:"
                      " not setting IPMI Fru Inventory");
            break;
        }

        //Container with list of frus and a boolean indicating whether the data
        //needs to be cleared or not
        // @todo-RTC:124687 - Refactor map use
        std::map<uint8_t,bool> frusToClear;
        //List of all potential Frus that could need IPMI Fru Inv. Data Sent
        std::vector< std::pair<TARGETING::TargetHandle_t, uint8_t> >
                                                                l_potentialFrus;

        if (i_updateData == false)
        {
            IPMIFRUINV::gatherClearData(pSys, frusToClear);
        }

        //Get System FW FRU_ID if available
        uint32_t l_systemFwFruId;
        bool hasSystemFwFruId =
                  pSys->tryGetAttr<TARGETING::ATTR_BMC_FRU_ID>(l_systemFwFruId);
        if (hasSystemFwFruId)
        {
            l_potentialFrus.push_back(std::make_pair(pSys, l_systemFwFruId));
        }

        // Find list of all target types that may need a fru inv. record set
        IPMIFRUINV::gatherSetData(pSys, frusToClear,
                                     l_potentialFrus, i_updateData);

        //Now Loop through all TargetHandle_t, uint8_t pairs to see if there are
        //multiple targets with the same fruId. These will be formed into a list
        //as data from all Targets will be combined into one IPMI Fru Inventory
        //Record under the same fruId.
        std::vector<std::pair<TARGETING::TargetHandle_t,uint8_t> >::iterator
                                                                        l_iter;

        for (l_iter = l_potentialFrus.begin(); l_iter != l_potentialFrus.end();
                   ++l_iter)
        {
            //iterators to walk list and group frus together
            std::vector<std::pair<TARGETING::TargetHandle_t,uint8_t> >::iterator
                                                             l_curPair = l_iter;
            std::vector<std::pair<TARGETING::TargetHandle_t,uint8_t> >::iterator
                                                            l_nextPair = l_iter;

            //The 'base' TargetHandleList will have one FRU
            TARGETING::TargetHandleList l_curFru;
            l_curFru.push_back(l_curPair->first);
            //This will be the fruId to compare with what comes after this
            //Target in the vector
            uint8_t l_fruId = l_curPair->second;

            TRACFCOMP(g_trac_ipmi, "IPMIFRUINV::setData - Collecting all IPMI FRU Inventory Targets with fruId: [%08x]",
                        l_fruId);

            ++l_nextPair;
            for( ; l_nextPair != l_potentialFrus.end()
                            && l_nextPair->second == l_fruId; ++l_nextPair)
            {
                l_curFru.push_back(l_nextPair->first);
                l_iter = l_nextPair;
            }
            IpmiFruInv *l_fru = IpmiFruInv::Factory(l_curFru, i_updateData);

            if (l_fru != NULL)
            {
                //Target recognized, build & send IPMI FRU Invenotry record
                l_errl = l_fru->buildFruInvRecord();
                if (l_errl)
                {
                    TRACFCOMP(g_trac_ipmi, "IPMIFRUINV::setData - Errors encountered, will skip setting the rest of the data");
                    break;
                }
                TRACFCOMP(g_trac_ipmi, "IPMIFRUINV::setData - Sending IPMI FRU Inventory Data for target with fruId: [%08x] and size [%08x]",
                         l_fruId, l_curFru.size());
                l_fru->sendFruData(l_fruId);
                delete l_fru;
            }
        }

        //Do not clear data during a data update
        if (i_updateData == false)
        {
            //Now clear any FRU Data for fruIds that didn't have data set. This
            //will handle the case where something was removed from the system
            for (std::map<uint8_t,bool>::iterator it=frusToClear.begin();
                    it!=frusToClear.end();
                    ++it)
            {
                //If the bool is true its data needs to be cleared
                if (it->second == true)
                {
                    IPMIFRUINV::clearData(it->first);
                }
            }
        }

    } while(0);

    if (l_errl)
    {
        //Commit errorlog encountered indicating there were issues
        //setting the FRU Inventory Data
        TRACFCOMP(g_trac_ipmi, "Errors encountered setting Fru Inventory Data");
        l_errl->collectTrace(IPMI_COMP_NAME);
        errlCommit(l_errl, IPMI_COMP_ID);
    }
    return;
}


void IPMIFRUINV::gatherClearData(const TARGETING::Target* i_pSys,
                                    std::map<uint8_t,bool>& io_frusToClear)
{
    TARGETING::PredicateCTM predChip(TARGETING::CLASS_CHIP);
    TARGETING::PredicateCTM predNode(TARGETING::CLASS_ENC,
                                     TARGETING::TYPE_NODE);
    TARGETING::PredicateCTM predDimm(TARGETING::CLASS_LOGICAL_CARD,
                                         TARGETING::TYPE_DIMM);
    TARGETING::PredicatePostfixExpr checkAllExpr;
    checkAllExpr.push(&predChip).push(&predNode).Or().push(&predDimm).Or();
    TARGETING::TargetHandleList l_allPossibleFrus;
    TARGETING::targetService().getAssociated( l_allPossibleFrus, i_pSys,
    TARGETING::TargetService::CHILD, TARGETING::TargetService::ALL,
            &checkAllExpr );

    for (TARGETING::TargetHandleList::const_iterator pTarget_it =
         l_allPossibleFrus.begin();
         pTarget_it != l_allPossibleFrus.end();
         ++pTarget_it)
    {
        TARGETING::TargetHandle_t pTarget = *pTarget_it;
        uint32_t l_fruId = pTarget->getAttr<TARGETING::ATTR_FRU_ID>();

        if (l_fruId)
        {
            //Assume we clear all possible targets to start
            // @todo-RTC:124506 - New logic may be needed to clear all targets
            // after a code update
            io_frusToClear[l_fruId] = true;
        }
    }

    return;
}

void IPMIFRUINV::gatherSetData(const TARGETING::Target* i_pSys,
                                  std::map<uint8_t,bool>& io_frusToClear,
                   std::vector< std::pair<TARGETING::TargetHandle_t, uint8_t> >&
                                                               io_potentialFrus,
                                  bool i_updateData)
{
    TARGETING::PredicateCTM predChip(TARGETING::CLASS_CHIP);
    TARGETING::PredicateCTM predDimm(TARGETING::CLASS_LOGICAL_CARD,
                                     TARGETING::TYPE_DIMM);
    TARGETING::PredicatePostfixExpr checkExpr;
    TARGETING::PredicateHwas l_present;
    // @todo-RTC:124553 - Additional logic for deconfigured Frus
    //                    may be needed
    l_present.present(true);

    checkExpr.push(&predChip);
    TARGETING::PredicateCTM predNode(TARGETING::CLASS_ENC,
                                     TARGETING::TYPE_NODE);
    checkExpr.push(&predNode).Or();

    //When updating data on a later pass ignore dimms
    if (i_updateData)
    {
        checkExpr.push(&l_present).And();
    }
    else
    {
        checkExpr.push(&predDimm).Or().push(&l_present).And();
    }

    TARGETING::TargetHandleList pCheckPres;
    TARGETING::targetService().getAssociated( pCheckPres, i_pSys,
    TARGETING::TargetService::CHILD, TARGETING::TargetService::ALL,
            &checkExpr );

    for (TARGETING::TargetHandleList::const_iterator pTarget_it =
                pCheckPres.begin();
                pTarget_it != pCheckPres.end();
                ++pTarget_it
        )
    {

        TARGETING::TargetHandle_t pTarget = *pTarget_it;
        uint32_t l_fruId = pTarget->getAttr<TARGETING::ATTR_FRU_ID>();

        // check if this is a membuf target, if it is and the special
        // attribute to say we want a separate fru entry for the centaur ecids
        // is populated, then we will push that ecid to the potential frus
        // list

        if (TARGETING::TYPE_MEMBUF == pTarget->getAttr<TARGETING::ATTR_TYPE>())
        {
            uint8_t l_ecidFruId =
                pTarget->getAttr<TARGETING::ATTR_CENTAUR_ECID_FRU_ID>();

            // if the ecid fru id is valid use it, else use the regular fru id
            l_fruId = ( l_ecidFruId == 0xFF ) ? l_fruId : l_ecidFruId;

            TRACFCOMP(g_trac_ipmi,"l_fruId = 0x%x, l_ecidFruId = 0x%x", l_fruId, l_ecidFruId);
        }

        if (l_fruId)
        {
            //when updating data, ignore clearing data
            if (i_updateData == false)
            {
                //Indicate this fruId has data and later clear is not needed
                io_frusToClear[l_fruId] = false;
            }
            io_potentialFrus.push_back(std::make_pair(pTarget, l_fruId));
        }
    }

    //Sort the vector by FRU_ID for later use.
    //When the planar eeprom is shared for planar and memory buffer vpd, the
    //node and membuffs will have the same FRU ID. For this case, sort the Node
    //to be ahead of the mem buffs. The mem buffs will be extra targets for
    //their ECIDs.
    std::sort(io_potentialFrus.begin(),
              io_potentialFrus.end(),
              comparePairs);
}
