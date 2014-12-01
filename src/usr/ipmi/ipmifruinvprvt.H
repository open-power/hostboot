/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/ipmi/ipmifru.H $                              */
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

#ifndef __IPMI_IPMIFRUINVPRVT_H
#define __IPMI_IMPIFRUINVPRVT_H

namespace IPMIFRUINV
{
    enum recordFields
    {
        //Storage Definition Headers will use version 1.2
        SPEC_VERSION                  = 1,
        RECORD_UNIT_OF_MEASUREMENT    = 8, //size in bytes
        CHECKSUM_SIZE                 = 1, //size in bytes
        RECORD_NOT_PRESENT            = 0,
        ENGLISH_LANGUAGE_CODE         = 0,
        TYPELENGTH_BYTE_NULL          = 0,
        TYPELENGTH_BYTE_ASCII         = 0xC0,
        END_OF_CUSTOM_FIELDS          = 0xC1,
        COMMON_HEADER_FORMAT_SIZE     = 8, //size in bytes
        DEFAULT_CHASSIS_TYPE          = 0x05,
        DEFAULT_FRU_OFFSET            = 0,
    };
};


//Parent Class Contains all common functions to build up, format,
//  and send IPMI Fru Inventory Record Data
//The parent Class also defines pure virtual functions so the child
//  is responsible to build up the individual record sections
//  as the data for those is specific to each child.
class IpmiFruInv
{
  public:


    /**
     * @brief Constructor
     *
     * @param[in] TargetHandle_t, Handle to target for which
     *             to get relevant IPMI FRU Data from
     */
    IpmiFruInv(TARGETING::TargetHandle_t i_target);

    /**
     * @brief Default Destructor
     */
    virtual ~IpmiFruInv();

    /**
     * @brief Factory Pattern Creator function
     * @param[in] TargetHandle_t, Handle to target for which
     *             to get relevant IPMI FRU Data from
     */
    static IpmiFruInv *Factory(TARGETING::TargetHandle_t i_target);

    /**
     * @brief Package and send the IPMI FRU Data
     *
     * @param[in] uint8_t, IPMI Fru Device ID
     */
    void sendFruData(uint8_t i_deviceId);

    /**
     * @brief Gather and Format relevant IPMI Fru Inventory Data
     *
     * @param[in] void
     * @param[out] errlHndl_t, error encountered getting data
     */
    errlHndl_t buildFruInvRecord(void);

  protected:
    //The target to build an IPMI fru inventory record for
    TARGETING::TargetHandle_t iv_target;

    //The overall IPMI Fru Inventory record to send
    std::vector<uint8_t> iv_record_data;

    /**
     * @brief Format Beginning of Individual IPMI Fru Data Section
     *
     * @param[in/out] data, Data to be updated with formatting + header
     * @param[in] i_setLanguagCode, Indicator to set/not set Language Code
     */
    void preFormatProcessing(std::vector<uint8_t>& io_data,
                                                        bool i_setLanguageCode);

    /**
     * @brief Format End of Individual IPMI Fru Data Section
     *
     * @param[in/out] data, Data container to be updated with formatting
     */
    void postFormatProcessing(std::vector<uint8_t>& io_data);
    /**
     * @brief Complete + Set size of Data Section
     *
     * @param[in/out] data, Data container with size to be updated
     * @param[in] offset, Indicate where to update size of data section
     */
    void setAreaSize(std::vector<uint8_t>& io_data, uint8_t i_offset);

    /**
     * @brief Add inputted data to overall IPMI Fru Record
     *
     * @param[in] data, Data container to be added to overall record
     */
    void addDataToRecord(const std::vector<uint8_t>& i_data);

    /**
     * @brief Builds the Internal Use Area Data Section
     * @param[in/out] data, The container to put intenral use area data in
     */
    virtual errlHndl_t buildInternalUseArea(std::vector<uint8_t> &io_data)=0;

    /**
     * @brief Builds the Chassis Info Area Data Section
     * @param[in/out] data, The container to put chassis info area data in
     */
    virtual errlHndl_t buildChassisInfoArea(std::vector<uint8_t> &io_data)=0;

    /**
     * @brief Builds the Board Info Area Data Section
     * @param[in/out] data, The container to put board info area data in
     */
    virtual errlHndl_t buildBoardInfoArea(std::vector<uint8_t> &io_data)=0;

    /**
     * @brief Builds the Product Info Area Data Section
     * @param[in/out] data, The container to put product info area data in
     */
    virtual errlHndl_t buildProductInfoArea(std::vector<uint8_t> &io_data)=0;

    /**
     * @brief Builds the MultiRecord Info Area Data Section
     * @param[in/out] data, The container to put multirecord info area data in
     */
    virtual errlHndl_t buildMultiRecordInfoArea(
                                           std::vector<uint8_t> &io_data)=0;

   /**
     * @brief Builds a standard data section that is empty
     * @param[in] data, The container to put the data in
     */
    virtual errlHndl_t buildEmptyArea(std::vector<uint8_t> &i_data);

    /**
     * @brief Debug function to print data to console
     * @param[in] data, The data to be printed
     */
    void printRecordDebugData(const std::vector<uint8_t> &i_data);

  private:

    /**
     * @brief Compute and Add data checsum to data record
     *
     * @param[in/out] data, Data to be updated with checsum
     */
    void addDataChecksum(std::vector<uint8_t>& io_data);

    /**
     * @brief Pad data section to proper size
     *
     * @param[in/out] data, Data to be padded
     */
    void padData(std::vector<uint8_t>& io_data);

    /**
     * @brief Builds a section of the common header
     *
     * @param[in/out] data, Common Header section data container
     * @param[in] section_data, Data from one particular record section
     * @param[in/out] cur_offset, Current offset for data in overall record
     */
    void buildCommonHeaderSection(std::vector<uint8_t>& io_out_data,
                                      uint32_t i_section_data,
                                      uint32_t &io_cur_offset);

    /**
     * @brief Sets IPMI Fru Spec Revision Header Format Value
     *
     * @param[in/out] data, data to add format value to
     */
    void addHeaderFormat(std::vector<uint8_t>& io_data);

    /**
     * @brief Builds the common header data in iv_record
     *
     * @param[in] internal_use_data, IPMI internal use section data
     * @param[in] chassis_data, IPMI chassis section data
     * @param[in] board_data, IPMI board section data
     * @param[in] product_data, IPMI product section data
     * @param[in] multirecord_data, IPMI multirecord section data
     * @param[out] void
     */
    void buildCommonHeader( const std::vector<uint8_t> &i_internal_use_data,
                            const std::vector<uint8_t> &i_chassis_data,
                            const std::vector<uint8_t> &i_board_data,
                            const std::vector<uint8_t> &i_product_data,
                            const std::vector<uint8_t> &i_multirecord_data );

    /**
     * @brief Complete entire record by combining all data parts
     *
     * @param[in] internal_use_data, IPMI internal use section data
     * @param[in] chassis_data, IPMI chassis section data
     * @param[in] board_data, IPMI board section data
     * @param[in] product_data, IPMI product section data
     * @param[in] multirecord_data, IPMI multirecord section data
     */
    void completeRecord(const std::vector<uint8_t> &i_internal_use_data,
                              const  std::vector<uint8_t> &i_chassis_data,
                              const  std::vector<uint8_t> &i_board_data,
                              const  std::vector<uint8_t> &i_product_data,
                              const  std::vector<uint8_t> &i_multirecord_data);

};


//Child class for building up ISDimm Fru Inventory Record Data
class isdimmIpmiFruInv : public IpmiFruInv
{

  public:

     /**
     * @brief Constructor
     *
     * @param[in] TargetHandle_t, Handle to target for which
     *             to get relevant IPMI FRU Data from
     */
    isdimmIpmiFruInv( TARGETING::TargetHandle_t i_target );

    /**
     * @brief Builds the Internal Use Area Data Section
     * @param[in/out] data, The container to put internal use area data in
     */
    errlHndl_t buildInternalUseArea(std::vector<uint8_t> &io_data);

    /**
     * @brief Builds the Chassis Info Area Data Section
     * @param[in/out] data, The container to put chassis info area data in
     */
    errlHndl_t buildChassisInfoArea(std::vector<uint8_t> &io_data);

    /**
     * @brief Builds the Board Info Area Data Section
     * @param[in/out] data, The container to put board info area data in
     */
    errlHndl_t buildBoardInfoArea(std::vector<uint8_t> &io_data);

    /**
     * @brief Builds the Product Info Area Data Section
     * @param[in/out] data, The container to put product info area data in
     */
    errlHndl_t buildProductInfoArea(std::vector<uint8_t> &io_data);

    /**
     * @brief Builds the MultiRecord Info Area Data Section
     * @param[in/out] data, The container to put multirecord info area data in
     */
    errlHndl_t buildMultiRecordInfoArea(std::vector<uint8_t> &io_data);

  private:

    /**
     * @brief Adds the specified VPD data to the data to build up a given
     *        record
     * @param[in/out] data, The container with record data
     * @param[in] keyword, Indicates where in the VPD to get more data

     */
    errlHndl_t addVpdData(std::vector<uint8_t> &io_data, uint8_t i_keyword);

};

//Child class for building up Processor Fru Inventory Record Data
class procIpmiFruInv : public IpmiFruInv
{

  public:

     /**
     * @brief Constructor
     *
     * @param[in] TargetHandle_t, Handle to target for which
     *             to get relevant IPMI FRU Data from
     */
    procIpmiFruInv( TARGETING::TargetHandle_t i_target );

    /**
     * @brief Builds the Internal Use Area Data Section
     * @param[in/out] data, The container to put internal use area data in
     */
    errlHndl_t buildInternalUseArea(std::vector<uint8_t> &io_data);

    /**
     * @brief Builds the Chassis Info Area Data Section
     * @param[in/out] data, The container to put chassis info area data in
     */
    errlHndl_t buildChassisInfoArea(std::vector<uint8_t> &io_data);

    /**
     * @brief Builds the Board Info Area Data Section
     * @param[in/out] data, The container to put board info area data in
     */
    errlHndl_t buildBoardInfoArea(std::vector<uint8_t> &io_data);

    /**
     * @brief Builds the Product Info Area Data Section
     * @param[in/out] data, The container to put product info area data in
     */
    errlHndl_t buildProductInfoArea(std::vector<uint8_t> &io_data);

    /**
     * @brief Builds the MultiRecord Info Area Data Section
     * @param[in/out] data, The container to put multirecord info area data in
     */
    errlHndl_t buildMultiRecordInfoArea(std::vector<uint8_t> &io_data);

  private:

    /**
     * @brief Adds the specified VPD data to the data to build up a given
     *        IPMI Fru Inventory record
     * @param[in/out] data, The container with record data
     * @param[in] record,  Indicates major offset in the VPD to get more data
     * @param[in] keyword, Indicates minor offset in the VPD to get more data
     * @param[in] ascii, Indicates if VPD field is in ascii format or not
     */
    errlHndl_t addVpdData(std::vector<uint8_t> &io_data,
                          uint8_t i_record,
                          uint8_t i_keyword,
                          bool i_ascii=false);

};

//Child class for building up backplane Fru Inventory Record Data
class backplaneIpmiFruInv : public IpmiFruInv
{

  public:

     /**
     * @brief Constructor
     *
     * @param[in] TargetHandle_t, Handle to target for which
     *             to get relevant IPMI FRU Data from
     */
    backplaneIpmiFruInv( TARGETING::TargetHandle_t i_target );

    /**
     * @brief Builds the Internal Use Area Data Section
     * @param[in/out] data, The container to put internal use area data in
     */
    errlHndl_t buildInternalUseArea(std::vector<uint8_t> &io_data);

    /**
     * @brief Builds the Chassis Info Area Data Section
     * @param[in/out] data, The container to put chassis info area data in
     */
    errlHndl_t buildChassisInfoArea(std::vector<uint8_t> &io_data);

    /**
     * @brief Builds the Board Info Area Data Section
     * @param[in/out] data, The container to put board info area data in
     */
    errlHndl_t buildBoardInfoArea(std::vector<uint8_t> &io_data);

    /**
     * @brief Builds the Product Info Area Data Section
     * @param[in/out] data, The container to put product info area data in
     */
    errlHndl_t buildProductInfoArea(std::vector<uint8_t>& io_data);

    /**
     * @brief Builds the MultiRecord Info Area Data Section
     * @param[in/out] data, The container to put multirecord info area data in
     */
    errlHndl_t buildMultiRecordInfoArea(std::vector<uint8_t>& io_data);

  private:

    /**
     * @brief Adds the specified VPD data to the data to build up a given
     *        IPMI Fru Inventory record
     * @param[in/out] data, The container with record data
     * @param[in] record,  Indicates major offset in the VPD to get more data
     * @param[in] keyword, Indicates minor offset in the VPD to get more data
     * @param[in] ascii, Indicates if VPD field is in ascii format or not
     */
    errlHndl_t addVpdData(std::vector<uint8_t> &io_data,
                          uint8_t i_record,
                          uint8_t i_keyword,
                          bool i_ascii=false);

};

#endif
