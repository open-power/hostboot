/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmi/ipmifru.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
#include <vpd/mvpdenums.H>
#include <devicefw/userif.H>
#include <vpd/spdenums.H>
#include <vpd/cvpdenums.H>
#include <ipmi/ipmifruinv.H>
#include "ipmifru.H"
#include "ipmifruinvprvt.H"
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>


extern trace_desc_t * g_trac_ipmi;

IpmiFruInv::IpmiFruInv(TARGETING::TargetHandle_t i_target)
    :iv_target(i_target)
{
};

IpmiFruInv::~IpmiFruInv()
{}


IpmiFruInv *IpmiFruInv::Factory(TARGETING::TargetHandle_t i_target)
{
    IpmiFruInv *l_fru = NULL;

    switch (i_target->getAttr<TARGETING::ATTR_TYPE>())
    {
        case TARGETING::TYPE_DIMM:
            l_fru = new isdimmIpmiFruInv(i_target);
            break;
        case TARGETING::TYPE_PROC:
            l_fru = new procIpmiFruInv(i_target);
            break;
        case TARGETING::TYPE_MEMBUF:
            // @todo-RTC:117702
            l_fru = new backplaneIpmiFruInv(i_target);
            break;
        default:
            TRACFCOMP(g_trac_ipmi,"IpmiFruInv::Factory: No support for target type given: [%08x]",
                       i_target->getAttr<TARGETING::ATTR_TYPE>());
            assert(false);
            break;
    }

    return l_fru;
}

void IpmiFruInv::sendFruData(uint8_t i_deviceId)
{
    if (iv_record_data.size() > 0)
    {
        //Use IMPIFRU::writeData to sand data to service processor
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

    io_data.insert(io_data.end(),
                   ((io_data.size() + IPMIFRUINV::CHECKSUM_SIZE) %
                          IPMIFRUINV::RECORD_UNIT_OF_MEASUREMENT),
                   uint8_t(0));

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

    //Set size of board info area
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
        l_errl = addVpdData(io_data, SPD::MODULE_PART_NUMBER);
        if (l_errl) { break; }
        //Set Product Version
        l_errl = addVpdData(io_data, SPD::MODULE_REVISION_CODE);
        if (l_errl) { break; }
        //Set Product Serial Number
        l_errl = addVpdData(io_data, SPD::MODULE_SERIAL_NUMBER);
        if (l_errl) { break; }

        //Add Asset Tag
        io_data.push_back(uint8_t(1)); //Asset Tag is One Byte for now
        io_data.push_back(uint8_t(0));

        //FRU File ID - Empty
        io_data.push_back(IPMIFRUINV::TYPELENGTH_BYTE_NULL);
        io_data.push_back(uint8_t(0)); // Empty FRU File ID bytes
        io_data.push_back(IPMIFRUINV::END_OF_CUSTOM_FIELDS);

        //Finalize section formatting
        postFormatProcessing(io_data);

    } while (0);

    if (l_errl)
    {
        TRACFCOMP(g_trac_ipmi,"isdimIpmiFruInv::buildProductInfoArea - Errors "
                              "collecting product info data from VPD");
    }

    return l_errl;
}

errlHndl_t isdimmIpmiFruInv::addVpdData(std::vector<uint8_t> &io_data,
                                     uint8_t i_keyword)
{
    size_t     l_vpdSize = 0;
    errlHndl_t l_errl = NULL;

    do {
        //First get size with NULL call:
        errlHndl_t l_errl = deviceRead(iv_target,
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
            uint8_t l_vDataPtr[l_vpdSize];
            l_errl = deviceRead(iv_target, l_vDataPtr, l_vpdSize,
                                DEVICE_SPD_ADDRESS(i_keyword));

            //First append data size to vector data
            io_data.push_back(l_vpdSize);

            //Second append all data found onto vector data
            io_data.insert(io_data.end(),
                                   &l_vDataPtr[0], &l_vDataPtr[l_vpdSize]);

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
procIpmiFruInv::procIpmiFruInv( TARGETING::TargetHandle_t i_target )
    :IpmiFruInv(i_target)
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
        io_data.push_back(0x49); //I
        io_data.push_back(0x42); //B
        io_data.push_back(0x4D); //M

        //Set Board Info description
        l_errl = addVpdData(io_data, MVPD::VINI, MVPD::DR, true);
        if (l_errl) { break; }
        //Set Board Info serial number
        l_errl = addVpdData(io_data, MVPD::VINI, MVPD::SN);
        if (l_errl) { break; }
        //Set Board part number
        l_errl = addVpdData(io_data, MVPD::VINI, MVPD::FN);
        if (l_errl) { break; }
        //Set Board FRU File ID
        l_errl = addVpdData(io_data, MVPD::VINI, MVPD::VZ);
        if (l_errl) { break; }
        io_data.push_back(IPMIFRUINV::END_OF_CUSTOM_FIELDS);

        //Complete formatting for this data record
        postFormatProcessing(io_data);

    } while (0);

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
                                     bool i_ascii)
{
    size_t     l_vpdSize = 0;
    errlHndl_t l_errl = NULL;

    do {

        //First get size of data by passing NULL
        errlHndl_t l_errl = deviceRead(iv_target,
                                      NULL,
                                      l_vpdSize,
                                      DEVICE_MVPD_ADDRESS(i_record, i_keyword));

        if (l_errl)
        {
            TRACFCOMP(g_trac_ipmi,"procIpmiFruInv::addVpdData - Error while "
                      "reading MVPD keyword size");
            break;
        }

        //Assert if vpd field is too large to fit in IPMI fru inventory format
        assert(l_vpdSize < IPMIFRUINV::TYPELENGTH_BYTE_ASCII);

        if (l_vpdSize > 0)
        {
            uint8_t l_vDataPtr[l_vpdSize];

            l_errl = deviceRead(iv_target, l_vDataPtr, l_vpdSize,
                                DEVICE_MVPD_ADDRESS(i_record, i_keyword));

            //Add on the data to the type/length byte indicating it is ascii
            // otherwise leave it as binary
            if (i_ascii)
            {
                io_data.push_back(l_vpdSize
                                          + IPMIFRUINV::TYPELENGTH_BYTE_ASCII);
            }
            else
            {
                //First push back the size of this data
                io_data.push_back(l_vpdSize);
            }

            //Second append all data found onto vector data
            io_data.insert(io_data.end(),
                                   &l_vDataPtr[0], &l_vDataPtr[l_vpdSize]);

        }
        else
        {
            TRACFCOMP(g_trac_ipmi,"procIpmiFruInv::addVpdData - "
                      " No size returned for MVPD keyword");
        }
    } while(0);

    if (l_errl)
    {
        TRACFCOMP(g_trac_ipmi, "addVpdData - Error acquiring data from Vpd.");
    }

    return l_errl;
}


//##############################################################################
backplaneIpmiFruInv::backplaneIpmiFruInv( TARGETING::TargetHandle_t i_target )
    :IpmiFruInv(i_target)
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
        preFormatProcessing(io_data, true);

        //Set default chassis type
        io_data.push_back(IPMIFRUINV::DEFAULT_CHASSIS_TYPE);
        //Set chassis part number - ascii formatted field
        //@fixme RTC Story 118373
        l_errl = addVpdData(io_data, CVPD::OPFR, CVPD::VP, true);
        if (l_errl) { break; }
        //Set chassis serial number - ascii formatted field
        //@fixme RTC Story 118373
        l_errl = addVpdData(io_data, CVPD::OPFR, CVPD::VS, true);
        if (l_errl) { break; }

        //Indicate no custom fields
        io_data.push_back(IPMIFRUINV::TYPELENGTH_BYTE_NULL);
        io_data.push_back(IPMIFRUINV::END_OF_CUSTOM_FIELDS);

        //Complete record data formatting
        postFormatProcessing(io_data);
    } while (0);

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
        //@fixme RTC Story 118373
        l_errl = addVpdData(io_data, CVPD::OPFR, CVPD::VN, true);
        if (l_errl) { break; }
        //Set Product Name - ascii formatted data
        //@fixme RTC Story 118373
        l_errl = addVpdData(io_data, CVPD::OPFR, CVPD::DR, true);
        if (l_errl) { break; }
        //Set Product Part number - ascii formatted data
        //@fixme RTC Story 118373
        l_errl = addVpdData(io_data, CVPD::OPFR, CVPD::VS, true);
        if (l_errl) { break; }
        //Set Product Serial number - ascii formatted data
        //@fixme RTC Story 118373
        l_errl = addVpdData(io_data, CVPD::OPFR, CVPD::VP, true);

        //Indicate No Custom Fields
        io_data.push_back(IPMIFRUINV::TYPELENGTH_BYTE_NULL);
        io_data.push_back(IPMIFRUINV::END_OF_CUSTOM_FIELDS);

        ////Complete record data formatting
        postFormatProcessing(io_data);

    } while (0);

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
                                     bool i_ascii)
{
    size_t     l_vpdSize = 0;
    errlHndl_t l_errl = NULL;

    do {
        //First get size of data with NULL parameter
        errlHndl_t l_errl = deviceRead(iv_target,
                                      NULL,
                                      l_vpdSize,
                                      //@fixme RTC Story 118373
                                      DEVICE_CVPD_ADDRESS(i_record, i_keyword));

        if (l_errl)
        {
            TRACFCOMP(g_trac_ipmi,"backplaneIpmiFruInv::addVpdData - Error "
                      "while reading CVPD keyword size");
            break;
        }

        //Assert if vpd field is too large to fit in IPMI fru inventory format
        assert(l_vpdSize < IPMIFRUINV::TYPELENGTH_BYTE_ASCII);

        if (l_vpdSize > 0)
        {
            uint8_t l_vDataPtr[l_vpdSize];
            l_errl = deviceRead(iv_target, l_vDataPtr, l_vpdSize,
                                DEVICE_CVPD_ADDRESS(i_record, i_keyword));

            //Add on the data to the type/length byte indicating it is ascii
            // otherwise leave it as binary
            if (i_ascii)
            {
                io_data.push_back(l_vpdSize
                                       + IPMIFRUINV::TYPELENGTH_BYTE_ASCII);
            }
            else
            {
                //First addon the size of this data
                io_data.push_back(l_vpdSize);
            }

            //Then add on the data returnd from the VPD read
            io_data.insert(io_data.end(),
                                   &l_vDataPtr[0], &l_vDataPtr[l_vpdSize]);
        }
        else
        {
            TRACFCOMP(g_trac_ipmi,"backplaneIpmiFruInv::addVpdData - "
                      " No size returned for CVPD keyword");
        }
    } while(0);

    if (l_errl)
    {
        TRACFCOMP(g_trac_ipmi, "backplaneIpmiFruInv::addVpdData - Error "
                  "acquiring data from Vpd.");
    }

    return l_errl;
}

errlHndl_t IPMIFRUINV::setData()
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

        // Find list of all target types that may need a fru inventory
        // record created for them
        TARGETING::PredicateCTM predChip(TARGETING::CLASS_CHIP);
        TARGETING::PredicateCTM predDimm(TARGETING::CLASS_LOGICAL_CARD,
                                         TARGETING::TYPE_DIMM);
        TARGETING::PredicatePostfixExpr checkExpr;
        TARGETING::PredicateHwas l_present;
        l_present.present(true);
        checkExpr.push(&predChip).push(&predDimm).Or().push(&l_present).And();

        TARGETING::TargetHandleList pCheckPres;
        TARGETING::targetService().getAssociated( pCheckPres, pSys,
            TARGETING::TargetService::CHILD, TARGETING::TargetService::ALL,
            &checkExpr );

        for (TARGETING::TargetHandleList::const_iterator pTarget_it =
                pCheckPres.begin();
                pTarget_it != pCheckPres.end();
                ++pTarget_it
            )
        {

            TARGETING::TargetHandle_t pTarget = *pTarget_it;

            //Check if EEPROM_VPD_FRU_INFO attribute exists
            TARGETING::EepromVpdFruInfo eepromVpdFruInfo;
            bool getFruInfo =
                 pTarget->tryGetAttr<TARGETING::ATTR_EEPROM_VPD_FRU_INFO>
                                                             (eepromVpdFruInfo);
            if (getFruInfo)
            {
                TRACFCOMP(g_trac_ipmi, "IPMIFRUINV::setData - Sending IPMI FRU Inventory Data for target with HUID: [%08x]",
                         pTarget->getAttr<TARGETING::ATTR_HUID>());

                IpmiFruInv *l_fru = IpmiFruInv::Factory(pTarget);

                if (l_fru != NULL)
                {
                    //Target recognized, build & send IPMI FRU Invenotry record
                    l_errl = l_fru->buildFruInvRecord();
                    if (l_errl)
                    {
                        TRACFCOMP(g_trac_ipmi, "IPMIFRUINV::setData - Errors encountered, will skip setting the rest of the data");
                        break;
                    }
                    l_fru->sendFruData(eepromVpdFruInfo.fruId);
                    delete l_fru;
                }
            }
        }
    } while(0);

    return l_errl;
}
