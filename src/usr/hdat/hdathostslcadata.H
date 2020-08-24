/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdathostslcadata.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
#ifndef HDATHOSTDATA_H_
#define HDATHOSTDATA_H_

namespace HDAT
{

const uint16_t HDAT_SLCA_STRUCT_VERSION    = 0x21;
const char HDAT_SLCA_STRUCT_NAME[7] = "SLCA  ";

struct pldm_entity_info
{
    uint16_t entityType;
    uint16_t entityInstanceNumber;
    uint16_t containerId;
}__attribute__ ((packed));

struct HDAT_slcaEntry_t
{
    uint16_t fru_index;                 //slca_index_of_this_fru
    uint16_t fru_rid;                   //vpd_resourece_id_of_this_fru
    char fru_id[2];                     //ASCII resource description
    uint16_t parent_index;              //slca_index_of_this_frus_parent
    uint8_t slca_reserved:6,
    non_functional_redundant_copy:1,    //1 = not functional, 0 = functional
    flag_embedded_pluggable:1;          //1 = embedded.  0=pluggable
    uint8_t number_of_children;         //number_of_children
    uint16_t first_child_index;         //slca_index_of_this_frus_first_child
    uint16_t first_child_rid;           //resource_ID of this frus first child
    uint8_t max_location_code_len;
    uint8_t actual_location_code_len;   //length_of_location_code
    char location_code[80];             //location_code (NULL terminated)
    uint16_t first_redundant_index;     //slca index of the redundant copy
    uint8_t number_redundant_copies;    //total number of redundant copy
    uint8_t reserved;
    uint16_t number_of_children_2B;     //number of children - 2 byte version
    uint8_t installed;                  //Is FRU installed
    uint8_t collected;                  //Is FRU VPD collected
    pldm_entity_info pldm_entity_id;             //pldm entity id of this fru
    pldm_entity_info first_child_pldm_entity_id; //pldm entity id of this frus 1st child

    HDAT_slcaEntry_t():fru_index(0xFFFF),
                       fru_rid(0xFFFF),
                       parent_index(0xFFFF),
                       slca_reserved(0x3F),
                       non_functional_redundant_copy(1),
                       flag_embedded_pluggable(1),
                       number_of_children(0xFF),
                       first_child_index(0xFFFF),
                       first_child_rid(0xFFFF),
                       max_location_code_len(0x00),
                       actual_location_code_len(0x00),
                       first_redundant_index(0xFFFF),
                       number_redundant_copies(0x00),
                       reserved(0x00),
                       number_of_children_2B(0x0000),
                       installed(0xFF),
                       collected(0xFF)
                       {
                            memset(&fru_id,0x0,sizeof(fru_id));
                            memset(&location_code,0x0,sizeof(location_code));
                       };
};

struct fru_id_rid_t
{
 uint16_t fru_rid;
 uint8_t fru_id[3];
};

struct hdatSLCAArrayHdr_t
{
 uint32_t hdatOffsetToSLCAArray;
 uint32_t hdatActualNrEntries;
 uint32_t hdatSizeOfEntryAllotted;
 uint32_t hdatActualSizeOfEntry;
};

struct hdatSLCAStruct_t
{
   hdatHDIF_t             hdatHdr;
   hdatHDIFDataHdr_t      hdatSLCAIntData[1];
   uint8_t                hdatPadding[8];
   hdatSLCAArrayHdr_t     hdatSLCAArrayHdr;
};

/**
 * @brief This routine builds the SLCA structure as per HDAT specifications
 *
 * @pre None
 *
 * @post None
 *
 * @param i_msAddr - Mainstore address where SLCA structure is loaded
 *        o_hdatslcaCount - output parameter - Number of SLCA structures
 *        o_hdatslcaSize - output paramster - Size of SLCA created
 *
 * @return errlHndl_t - Error Handle
 *
 * @retval HDAT_OTHER_COMP_ERROR
 */
errlHndl_t hdatBuildSLCA(const HDAT::hdatMsAddr_t &i_msAddr,
                               uint32_t &o_hdatslcaCount,
                               uint32_t &o_hdatslcaSize);

/**
 * @brief This routine copies the SLCA from a source address to a destination
 *        address
 *
 * @pre None
 *
 * @post None
 *
 * @param i_msAddrSource - input parameter - Source address of SLCA
 *        i_msAddrDest   - input parameter - Destination address of SLCA
 *        i_slcaSize     - input parameter - Size of SLCA to be copied
 *
 * @return None
 *
 * @retval HDAT_OTHER_COMP_ERROR
 */
void hdatMoveSLCA(const HDAT::hdatMsAddr_t &i_msAddrSource,
                   const HDAT::hdatMsAddr_t &i_msAddrDest,
                   uint32_t i_slcaSize);

}
#endif
