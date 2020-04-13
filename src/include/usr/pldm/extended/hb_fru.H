/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/extended/hb_fru.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
 *  @file hb_fru.H
 *  @brief Header for utility functions that manipulate PLDM
 *         fru record table info
 */

#ifndef HB_FRU_H
#define HB_FRU_H

#include <errl/errlentry.H>

namespace PLDM
{
/**
* @brief Utility function to print out the various records contained in
*        the fru table we got from the getFruRecordTable request.
*        See https://www.dmtf.org/standards/pmci for references
*
* @param[in] i_pldm_fru_table_buf Ptr to a buffer which contains data defined
*                                 in Table 7 of DSP0257 v1.0.0
* @param[in] i_record_count       Number of records in the fru record table
*
* @note Output is written to g_trac_pldm trace buffer
*
* @return void
*/
void printFruRecordTable(const uint8_t* i_pldm_fru_table_buf,
                         uint16_t i_record_count);

/**
* @brief Given a complete fru record table's set of records, filter the
*        set of records for a given record set id / record type.
*        See https://www.dmtf.org/standards/pmci for references
*        Defined in src/usr/pldm/extended/
*
* @param[in] i_pldm_fru_table_buf  Pointer to a buffer which contains data
*                                  defined in Table 7 of DSP0257 v1.0.0
* @param[in] i_record_count        Number of records in the fru record table
* @param[in] i_record_set_id       The record set id we would like the records
*                                  returned to have
* @param[in] i_record_type         The record type we would like the records
*                                  returned to have
* @param[out] o_pldm_fru_table_buf Buffer containing the filtered out pldm fru
*                                  records we want. If nullptr , then this func
*                                  assumes caller is trying to figure out the
*                                  size of buffer to allocate, so this will not
*                                  be filled out. Note: this will not contain
*                                  the Pad or FRUDataStructureIntegrityChecksum
*                                  defined in DSP0257
* @param[out] o_record_buf_len     Length of the buffer returned, if
*                                  o_recordBuffer is nullptr then caller is
*                                  trying to determine how large of a buffer to
*                                  allocate so that len will be returned with-
*                                  out this param
* @param[out] o_records_in_output_table Number of records contained in
*                                       o_recordBuffer
*
* @note If no records matching i_record_set_id and i_record_type are found then
*       o_record_buf_len and o_records_in_output_table will return 0. In the
*       event a null o_pldm_fru_table_buf is passed in, no memcpy will
*       be performed.
*
* @void
*/
void getRecordSetByIdAndType(const uint8_t* i_pldm_fru_table_buf,
                             uint16_t i_record_count,
                             uint16_t i_record_set_id,
                             uint8_t  i_record_type,
                             uint8_t* o_pldm_fru_table_buf,
                             uint32_t & o_record_buf_len,
                             uint16_t & o_records_in_output_table);

/**
* @brief Convert a serialized fru record set to IPZ style VPD
*        See https://www.dmtf.org/standards/pmci for references
*
* @param[in]  i_pldm_fru_table_buf     Pointer to a buffer which is a series
*                                      of PLDM fru records of type
*                                      FRU_RECORD_TYPE_OEM
*                                      (See Table 2 & 3 of DSP0257 v1.0.0)
* @param[in]  i_pldm_fru_record_count  Number of records in i_pldm_fru_table_buf
* @param[out] o_ipz_vpd_buf            Vector which will be populated with
*                                      IPZ formated VPD translated from the
*                                      data in i_pldm_fru_table_buf
*
* @note o_ipz_vpd_buf is cleared at start of this function
*
* @return returns error log if error occurs, otherwise returns nullptr
*/
errlHndl_t pldmFruRecordSetToIPZ(const uint8_t* const i_pldm_fru_table_buf,
                                 const uint16_t i_pldm_fru_record_count,
                                 std::vector<uint8_t>& o_ipz_vpd_buf);
}

#endif