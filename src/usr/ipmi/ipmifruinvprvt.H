/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmi/ipmifruinvprvt.H $                               */
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
        MAX_ASCII_FIELD_SIZE          = 0x3F, //size in bytes
        MAX_RECORD_SIZE               = 0xFF, //size in bytes
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
     * @param[in] isUpdate, Indicator if the code is updating
     *             existing data, or setting base data.
     */
    static IpmiFruInv *Factory(TARGETING::TargetHandleList i_targets,
                               bool i_isUpdate);

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

    /**
      * @brief Adds ECID attribute data
      * @param[in] target, The target to get the Sensor Number from
      * @param[in] ecid_info, The ECID attribute data
      * @param[in/out] data, The container to put ECID attribute data in
      */
    void addEcidData(const TARGETING::TargetHandle_t& i_target,
                     const TARGETING::ATTR_ECID_type& i_ecidInfo,
                     std::vector<uint8_t> &io_data);

    /**
      * @brief Adds Ecid attribute data from extra targets as custom data
      * @param[in] TargetHandleList, Handle to list of extra
      *             targets associated with this FRU Record
      * @param[in/out] data, The container to put ECID attribute data in
      */
    void customEcidData(TARGETING::TargetHandleList i_extraTargets,
                     std::vector<uint8_t> &io_data);

    /**
     * @brief Retrieve vpd record keyword and add to IPMI Fru Inventory record
     * @param[in/out] data, The container with record data
     * @param[in] access, Indicates vpd module to access (MVPD,PVPD,CPVD)
     * @param[in] record,  Indicates major offset in the VPD to get more data
     * @param[in] keyword, Indicates minor offset in the VPD to get more data
     * @param[in] ascii, Indicates if VPD field is in ascii format or not
     */
    errlHndl_t addCommonVpdData(
                          const TARGETING::TargetHandle_t& i_target,
                          std::vector<uint8_t> &io_data,
                          DeviceFW::AccessType i_accessType,
                          uint8_t i_record,
                          uint8_t i_keyword,
                          bool i_ascii,
                          bool i_typeLengthByte);

    /**
     * @brief Add attribute data to IPMI Fru Inventory record
     * @param[in/out] data, The container with record data
     * @param[in] attrData, Pointer to attribute data
     * @param[in] length,   Length of data to add
     */
    void addCommonAttrData( std::vector<uint8_t> &io_data,
                            uint8_t * i_pAttrData,
                            size_t    i_length);

    // The ATTR_SERIAL_NUMBER and ATTR_PART_NUMBER are 18 bytes but the
    // vpd data size is only 16. Only want to add the vpd data, not the pad.
    enum vpdSize
    {
        VPD_SN_PN_VPD_SIZE = 16,
    };

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
    isdimmIpmiFruInv( TARGETING::TargetHandle_t i_target);

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
     * @param[in] ascii, Indicates if VPD field is in ascii format or not
     */
    errlHndl_t addVpdData(std::vector<uint8_t> &io_data,
                          uint8_t i_keyword,
                          bool i_ascii=false);

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
     * @param[in] isUpdate, Indicator if the code is updating
     *             existing data, or setting base data.
     */
    procIpmiFruInv( TARGETING::TargetHandle_t i_target,
                    bool i_isUpdate );

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

  protected:

    //Indicator if a data update is happening.
    //True - means we are solely updating certain data
    //False - means we are doing the initial 'base' data set
    bool iv_isUpdate;

  private:

    /**
     * @brief Adds the specified VPD data to the data to build up a given
     *        IPMI Fru Inventory record
     * @param[in/out] data, The container with record data
     * @param[in] record,  Indicates major offset in the VPD to get more data
     * @param[in] keyword, Indicates minor offset in the VPD to get more data
     * @param[in] ascii, Indicates if VPD field is in ascii format or not
     * @param[in] typeLengthBtye, Indicates whether type length to be added.
     */
    errlHndl_t addVpdData(std::vector<uint8_t> &io_data,
                          uint8_t i_record,
                          uint8_t i_keyword,
                          bool i_ascii=false,
                          bool i_typeLengthByte=true);

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
     * @param[in] TargetHandleList, Handle to list of extra
     *             targets associated with this FRU Record
     * @param[in] isUpdate, Indicator if the code is updating
     *             existing data, or setting base data.
     */
    backplaneIpmiFruInv( TARGETING::TargetHandle_t i_target,
                         TARGETING::TargetHandleList i_extraTargets,
                         bool i_isUpdate );

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

  protected:
    //Indicator if a data update is happening.
    //True - means we are solely updating certain data
    //False - means we are doing the initial 'base' data set
    bool iv_isUpdate;

    //The list of Extra Targets if multiple targets are
    //associated with one FRU_ID
    TARGETING::TargetHandleList iv_extraTargets;

  private:

    /**
     * @brief Adds the specified VPD data to the data to build up a given
     *        IPMI Fru Inventory record
     * @param[in/out] data, The container with record data
     * @param[in] record,  Indicates major offset in the VPD to get more data
     * @param[in] keyword, Indicates minor offset in the VPD to get more data
     * @param[in] ascii, Indicates if VPD field is in ascii format or not
     * @param[in] typeLengthBtye, Indicates whether type length to be added.
     */
    errlHndl_t addVpdData(std::vector<uint8_t> &io_data,
                          uint8_t i_record,
                          uint8_t i_keyword,
                          bool i_ascii=false,
                          bool i_typeLengthByte=true);
};

//Child class for building up System Firwmare Fru Inventory Record Data
class systemFwIpmiFruInv : public IpmiFruInv
{

  public:
    /**
    * @brief Constructor
    *
    * @param[in] TargetHandle_t, Handle to target for which
    *             to get relevant IPMI FRU Data from
    */
    systemFwIpmiFruInv( TARGETING::TargetHandle_t i_target);

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

};

//Child class for building up membuf Fru Inventory Record Data. For example,
//for a memory riser card Fru.
class membufIpmiFruInv : public IpmiFruInv
{

  public:

     /**
     * @brief Constructor
     *
     * @param[in] TargetHandle_t, Handle to target for which
     *             to get relevant IPMI FRU Data from
     * @param[in] TargetHandleList, Handle to list of extra
     *             targets associated with this FRU Record
     * @param[in] isUpdate, Indicator if the code is updating
     *             existing data, or setting base data.
     */
    membufIpmiFruInv( TARGETING::TargetHandle_t i_target,
                         TARGETING::TargetHandleList i_extraTargets,
                         bool i_isUpdate );

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

  protected:
    //Indicator if a data update is happening.
    //True - means we are solely updating certain data
    //False - means we are doing the initial 'base' data set
    bool iv_isUpdate;

    //The list of Extra Targets if multiple targets are
    //associated with one FRU_ID
    TARGETING::TargetHandleList iv_extraTargets;

  private:

    /**
     * @brief Adds the specified VPD data to the data to build up a given
     *        IPMI Fru Inventory record
     * @param[in/out] data, The container with record data
     * @param[in] record,  Indicates major offset in the VPD to get more data
     * @param[in] keyword, Indicates minor offset in the VPD to get more data
     * @param[in] ascii, Indicates if VPD field is in ascii format or not
     * @param[in] typeLengthBtye, Indicates whether type length to be added.
     */
    errlHndl_t addVpdData(std::vector<uint8_t> &io_data,
                          uint8_t i_record,
                          uint8_t i_keyword,
                          bool i_ascii=false,
                          bool i_typeLengthByte=true);

};

#endif
