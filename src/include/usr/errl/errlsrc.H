/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/errl/errlsrc.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
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
#ifndef ERRLSRC_H
#define ERRLSRC_H

/**
 *  @file errlsrc.H
 *
 *  @brief Manage the data that make up the 'PS' section in an
 *  error log PEL.  PS stands for Primary System Reference Code, or SRC.
 *  Part of that data management is the flattening of data into PEL.
 *
*/

#include <errl/errlsctn.H>
#include <errl/errlsctnhdr.H>

#include <vector>


namespace ERRORLOG
{

class ErrlSrc : public ErrlSctn
{

    // ErrlEntry may access private elements of this class.  Data items that
    // you would expect to be part of ErrlEntry are actually instance data
    // in this class.
    friend class ErrlEntry;
    friend class ErrlManager;


private:


    enum constants
    {
        SLEN            = 72,  // section length w/o sizeof(ErrlSctnHdr)
        SST             = 1,   // section type
        VER             = 1,   // section version
        SRCVER          = 2,   // SRC version (not section version)
        WORDCOUNT       = 9,   // SRC word count
        DECONFIG_BIT    = 0x02000000, // deconfig bit (6) in word 5
        GARD_BIT        = 0x01000000, // gard bit (7) in word 5
        ACK_BIT         = 0x00200000, // ack bit (10) in word 5
    };


    /**
     * @brief Constructor.  Pass in items destined for the primary SRC
     * section in the error log.
     *
     * @param[in]  i_srcType      SRC type
     * @param[in]  i_modId        Module ID
     * @param[in]  i_reasonCode   Reason code
     * @param[in]  i_user1        User data 1
     * @param[in]  i_user2        User data 2
     *
     */
    ErrlSrc( srcType_t i_srcType,
             uint8_t   i_modId,
             uint16_t  i_reasonCode,
             uint64_t  i_user1,
             uint64_t  i_user2 );


    /** @brief Destructor.  */
    ~ErrlSrc();



    /**
      * @brief   Disable copy constructor and assignment operator.
      */
    ErrlSrc(const ErrlSrc& i_right);
    ErrlSrc& operator=(const ErrlSrc& i_right);



    /**
     *  @brief Data export facility to flatten data to PEL.
     *  Exports the object into the 'PS' primary SRC PEL section.
     *
     *  @param[out] o_pBuffer  Pointer to buffer where flattened data will go.
     *  @param[in]  i_cbBuffer  Count of bytes in target buffer
     *
     */
    uint64_t flatten( void * o_pBuffer, const uint64_t i_cbBuffer );

    /**
     *  @brief Data export size.  Presently, Hostboot returns
     *  creates an 80-byte PS section: 72 bytes in the SRC
     *  and 8 bytes for the PEL section header. This is the
     *  amount of flat storage (in bytes) required to
     *  store the object.
     *
     *  @return  Size in bytes.
     *
     */
    uint64_t flatSize() const;

    /**
     * @brief Import data
     * @param[in] i_buf, pointer to the flattened data
     * @return number of bytes consumed
     */
    uint64_t unflatten( const void * i_buf );

    /**
     *  @brief return the failing subsystem id value
     *
     *  @return  Failing subsystem ID
     *
     */
    epubSubSystem_t getSubSys() const { return iv_ssid; };

    /**
     *  @brief set the failing subsystem id value in the SRC object
     *
     *
     */
    void setSubSys( epubSubSystem_t i_ssid ){ iv_ssid = i_ssid; };

    /**
     * Convert ascii hex digit to binary
     * @param[in] c, the ascii hex digit
     * @return the binary value 0-15
     * @note return value is only valid if input is valid hex digit
     * '0'-'9', 'A'-'F', 'a'='f'
     */
    uint64_t aschex2bin(char c) const;


#ifdef CONFIG_BUILD_FULL_PEL

    /**
     *  @brief This is the amount of flat storage (in bytes) required to store the FRU Identity Substructure.
     *         There are several optional fields in the struct that need to be accounted for.
     *
     *  @param  i_fruSubstruct  The FRU identity substructure which needs to have its size determined.
     *
     *  @return  Size in bytes.
     *
     */
    size_t fruIdSubstructSize(const fruCallOutEntry_t& i_fruSubstruct) const;

    /**
     *  @brief Added to the flatSize(), this is the
     *  amount of flat storage (in bytes) required to
     *  store the FRU callouts.
     *
     *  @return  Size in bytes.
     *
     */
    uint64_t fruCalloutFlatSize() const;

    /**
     *  @brief Check if new FRU callout matches an existing
     *         callout in the vector.  Keep the callout with
     *         the highest priority.  MRU entries may be added
     *         to the callout if it is a duplicate FRU.
     *
     *  @param[in]  io_co The new callout.
     *
     *  @return True if the callout should be added to the vector.
     *
     */
    bool checkForDuplicateCallout(fruCallOutEntry_t& io_co);

    /**
     *  @brief Add the new FRU callout to the callout vector.
     *         Entry may be modified if it is a duplicate FRU,
     *         MRU entries may be added
     *
     *  @param[in]  io_co The new callout.
     *
     */
    void addFruCallout(fruCallOutEntry_t& io_co);

    /**
     *  @brief Truncate the vector of FRU callouts to the
     *         maximum number of FRU callouts allowed in the SRC.
     *         This should be called after all callouts are added and sorted.
     *
     */
    void maxFruCallouts(void);

    /**
     *  @brief Translate the HWAS priority to a FRU priority.
     *
     *  @param[in]  i_hwasPri The HWAS priority.
     *
     */
    char hwasPriToFruPri( uint32_t i_hwasPri );

    /**
     *  @brief Flatten the FRU callouts into PEL.
     *
     *  @param[in]  i_psrc Pointer to the flattened src.
     *
     */
    void flattenFruCallouts(pelSRCSection_t* i_psrc);

#endif

    // Instance data
    srcType_t       iv_srcType : 8; // SRC type, the ?? in SRC ??xxxxxx
    uint8_t         iv_modId;       // module ID
    uint16_t        iv_reasonCode;  // reason code
    epubSubSystem_t iv_ssid : 8 ;   // subsystem type, the ?? in SRC xx??xxxx
    uint64_t        iv_user1;       // user data 1
    uint64_t        iv_user2;       // user data 2
    bool            iv_deconfig;    // true if there is a deconfigure callout
    bool            iv_gard;        // true if there is a gard callout

#ifdef CONFIG_BUILD_FULL_PEL
    std::vector<fruCallOutEntry_t> iv_coVec; // vector of FRU callouts
#endif
};

#ifdef CONFIG_BUILD_FULL_PEL

inline size_t ErrlSrc::fruIdSubstructSize(const fruCallOutEntry_t& i_fruSubstruct) const
{
    // FRU ID substructure length is variable depending on callout type.
    // Part Number, Serial Number, and CCIN are optional fields.
    size_t fruSubstructLength = sizeof(pelFRUIDSubstruct_t);
    // Check if a procedure id or part number was given. bits 4-7 have that info.
    if (i_fruSubstruct.fruCompType & FAILING_COMP_TYPE_FRU_PRC)
    {
        // CCIN and Serial Number are not present.
        fruSubstructLength = fruSubstructLength - PEL_CCIN_SIZE - PEL_SERIAL_NUM_SIZE;
    }
    // If neither the Part Number nor the Procedure ID were supplied then this FRU callout
    // doesn't have any of the optional fields.
    else if (!(i_fruSubstruct.fruCompType & FAILING_COMP_TYPE_FRU_PN))
    {
        // Part Number, CCIN and Serial Number are not present.
        fruSubstructLength = fruSubstructLength - PEL_PART_NUM_SIZE - PEL_CCIN_SIZE - PEL_SERIAL_NUM_SIZE;
    }
    return fruSubstructLength;
}

inline uint64_t ErrlSrc::fruCalloutFlatSize() const
{
    uint64_t l_size = 0;

    l_size += sizeof(pelSubSectionHeader_t);

    // Loop through all entries in the callout vector
    for (const auto& entry : iv_coVec)
    {
        l_size += sizeof(pelFRUCalloutHeader_t);
        l_size += entry.locCodeLen;
        l_size += fruIdSubstructSize(entry);
    }

    return l_size;

}
#endif


//**************************************************************************
// Hostboot PS SRC section generates minimal section with no additional
// words of data.
inline uint64_t ErrlSrc::flatSize() const
{
    // 72 bytes in SRC structure + 8 byte section header.
    CPPASSERT( 80 == sizeof( pelSRCSection_t ));
    uint64_t l_size = sizeof( pelSRCSection_t );

#ifdef CONFIG_BUILD_FULL_PEL
    if (!iv_coVec.empty())
    {
        l_size += fruCalloutFlatSize();
    }
#endif

    return l_size;
}


} // namespace

#endif //ERRLSRC_H

