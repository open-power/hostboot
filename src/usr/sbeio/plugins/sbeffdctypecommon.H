/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/plugins/sbeffdctypecommon.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2024                        */
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

#pragma once

#include <endian.h>

/*******************************************************************************
 * Note:
 *  This file is used in the compilation of Odyssey SBE FFDC parser on FSP
 *  based systems. Hence, this file is shared with HWSV and Hostboot team for
 *  supporting Odyssey SBE FFDC parsing. So, please avoid adding any other
 *  include files that are not supported natively on FSP.
 *
 *  @NOTE: This file is a copy from the SBE repo
 *         $SANDBOXBASE/src/runtime/common/plat/ffdc/sbeffdctypecommon.H
 *         This file must be kept in sync. Any modification to this file
 *         must be reflected in all shared locations as noted above.
 *
 *******************************************************************************/

/**
 * FFDC DUMP Bit mapped identifiers called as Dump identifiers field
 */
#define SBE_FFDC_HW_DATA        (uint16_t)0x0001
#define SBE_FFDC_REG_DATA       (uint16_t)0x0002
#define SBE_FFDC_TRACE_DATA     (uint16_t)0x0004
#define SBE_FFDC_ATTR_DATA      (uint16_t)0x0008

// SBE_FFDC_ALL_HW_DATA: Get FFDC_HW + FFDC_REG
#define SBE_FFDC_ALL_HW_DATA    (uint16_t)(SBE_FFDC_HW_DATA     | SBE_FFDC_REG_DATA )
// SBE_FFDC_ALL_PLAT_DATA Get FFDC_ATTR + FFDC_TRACE
#define SBE_FFDC_ALL_PLAT_DATA  (uint16_t)(SBE_FFDC_TRACE_DATA  | SBE_FFDC_ATTR_DATA)
// FFDC All dump identifiers
#define SBE_FFDC_ALL_DATA       (uint16_t)(SBE_FFDC_ALL_HW_DATA | SBE_FFDC_ALL_PLAT_DATA)
// Invalid dump
#define SBE_FFDC_INVALID        ((uint16_t) !(SBE_FFDC_ALL_DATA))
/**
 *  Header size in words as per FFDC package
 */
#define HW_HEADER_SIZE_IN_WORDS     0x0001 // HW FFDC Fields
#define PLAT_HEADER_SIZE_IN_WORDS   0x0004 // PLAT Header values
#define BLOB_HEADER_SIZE_IN_WORDS   0x0001 // Blob Header size

/**
 * @brief Truncated trace size for FFDC
 */
#define SBE_FFDC_TRUNCATED_TRACE_LENGTH  512 // Package SBE Trace Data length


/*******************************************************************************
 * POZ FFDC Chip-op response structure, actually the response frame will contain
 *  multiple hwp/plat FFDC packages
 *
 * Figure : FFDC Response Frame format structure
 * Figure: 1
 * +-------------+-------------------+---------------+---------------+
 * | Byte 0      |       Byte 1      |     Byte 2    |    Bytes 3    |
 * +-------------+-------------------+---------------+---------------+
 * |    Magic Bytes 0xFBAD           |         Len in words          | \-
 * +-------------+-------------------+---------------+---------------+   |
 * |           Seq ID                |   Cmd class   |     Cmd       |   |
 * +-----------------------------------------------------------------+   |-> Respose Header
 * |           SLID                  |   Severity    |   Chip ID     |   |      @ref pozFfdcRespHeader_t
 * +-----------------------------------------------------------------+   |
 * |                          FAPI RC ( HWP )                        |   |
 * +-----------------------------------------------------------------+   |
 * |                        HWP FFDC Dump Fields                     | \-   --> @ref dumpFields_t
 * +-----------------------------------------------------------------+
 * |           Filed ID 0            |     Field ID 0 Length         | \-   --> @ref packageBlobField_t
 * +-----------------------------------------------------------------+   |
 * |                    Field Data 0 (size 1, data 2)                |   |
 * +-------------+-------------------+---------------+---------------+   |-> HWP local FFDC structure
 * |                              .......                            |   |      @ref fapi2::sbeFfdc_t
 * +-------------+-------------------+---------------+---------------+   |
 * |                    Field Data N (size 1, data 2)                | \-
 * +-------------+-------------------+---------------+---------------+
 * |           Filed ID 1            |     Field ID 1 Length         | \-
 * +-----------------------------------------------------------------+   |
 * |                    Field Data 0 (size 1, data 2)                |   |
 * +-------------+-------------------+---------------+---------------+   |-> HWP REG Data structure
 * |                              .......                            |   |
 * +-------------+-------------------+---------------+---------------+   |
 * |                    Field Data N (size 1, data 2)                | \-
 * +-------------+-------------------+---------------+---------------+
 * SBE internal (plat) FFDC:
 * +-------------+-------------------+---------------+---------------+
 * |    Magic Bytes 0xFBAD           |         Len in words          | \-
 * +-------------+-------------------+---------------+---------------+   |
 * |           Seq ID                |   Cmd class   |     Cmd       |   |
 * +-----------------------------------------------------------------+   |-> Respose Header
 * |           SLID                  |   Severity    |   Chip ID     |   |      @ref pozFfdcRespHeader_t
 * +-----------------------------------------------------------------+   |
 * |               FAPI RC ( FAPI2_RC_PLAT_ERR_SEE_DATA  )           | \-
 * +-------------+-------------------+---------------+---------------+
 * |        Primary Status           |        Secondary Status       | \-
 * +-----------------------------------------------------------------+   |
 * |                           FW Commit ID                          |   |-> Plat FFDC header
 * +-------------+-------------------+---------------+---------------+   |      @ref sbePlatHeader_t
 * |   Reserved  |     DD Major      |    DD Minor   |   Thread ID   |   |
 * +-----------------------------------------------------------------+   |
 * |                 SBE FFDC DUMP FIELDS (Bit Mapped)               | \-   --> @ref dumpFields_t
 * +-------------+-------------------+---------------+---------------+
 * |           Filed ID 0            |     Field ID 0 Length         | \-   --> @ref packageBlobField_t
 * +-----------------------------------------------------------------+   |
 * |                           Field Data 0                          |   |
 * +-------------+-------------------+---------------+---------------+   |-> Plat FFDC package 1
 * |                              .......                            |   |
 * +-------------+-------------------+---------------+---------------+   |
 * |                           Field Data N                          | \-
 * +-------------+-------------------+---------------+---------------+
 * |           Filed ID 1            |     Field ID 1 Length         | \-   --> @ref packageBlobField_t
 * +-----------------------------------------------------------------+   |
 * |                           Field Data 0                          |   |
 * +-------------+-------------------+---------------+---------------+   |-> Plat FFDC package 2
 * |                              .......                            |   |
 * +-------------+-------------------+---------------+---------------+   |
 * |                            Field Data N                         | \-
 * +-----------------------------------------------------------------+
 *
 * *****************************************************************************
*/

/**
 * Structure indicating the contents of FFDC package
 * value 'true' - field present;value 'false' - field not present
 * bit_0 - Local Hw dump
 * bit_1 - Hw Reg dump
 * bit_2 - Trace buffer dump
 * bit_3 - Attribute dump
 * bit 4-31 - reserved
 */
typedef struct __attribute__((packed, aligned(4)))
{
#if __BYTE_ORDER == __BIG_ENDIAN
    uint32_t hwField:1;
    uint32_t regField:1;
    uint32_t traceField:1;
    uint32_t attrField:1;
    uint32_t reserved:28;
#else
    uint32_t reserved:28;
    uint32_t attrField:1;
    uint32_t traceField:1;
    uint32_t regField:1;
    uint32_t hwField:1;
#endif
    /**
     *  @breif - set dump fields
     *
     * @param[in] - uint32_t value to be updated
     */
    void set(uint32_t val)
    {
        if(val & SBE_FFDC_HW_DATA)
        {
            hwField = true;
        }
        if(val & SBE_FFDC_REG_DATA)
        {
            regField = true;
        }
        if(val & SBE_FFDC_TRACE_DATA)
        {
            traceField = true;
        }
        if(val & SBE_FFDC_ATTR_DATA)
        {
            attrField = true;
        }
    }
    /**
     *  @brief - get dump fields as uint32_t
     *
     * @return - uint32_t value
     */
    uint32_t get()
    {
        uint32_t l_val = 0;
        if(hwField)
        {
            l_val |= SBE_FFDC_HW_DATA;
        }
        if(regField)
        {
            l_val |= SBE_FFDC_REG_DATA;
        }
        if(traceField)
        {
            l_val |= SBE_FFDC_TRACE_DATA;
        }
        if(attrField)
        {
            l_val |= SBE_FFDC_ATTR_DATA;
        }
        return l_val;
    }
} dumpFields_t;

/**
 * @brief Sturcture indicating the type of ffdc Package [ HW or  User data ] blob
 * and its length in bytes
 */
typedef struct __attribute__((packed, aligned(4)))
{
    uint32_t fieldId:16;
    uint32_t fieldLen:16;

    /**
     * @brief set method to set the value of the fieldId and fieldLen member variable
     *
     * @param[in] i_fieldId The new field ID to the set
     * @param[in] i_fieldLen The new field len to the set
    */
    void inline setFields (const uint16_t i_fieldId, const uint16_t i_fieldLen)
    {
        fieldId = i_fieldId;
        fieldLen = i_fieldLen;
    }

    uint32_t get()
    {
        uint32_t field = (fieldId << 16) + fieldLen;
        return field;
    }


} packageBlobField_t;

/**
 * @brief Structure of ffdc Package blob
 */
typedef struct __attribute__((packed, aligned(8)))
{
    packageBlobField_t  field;
    const void *blobPtr;
} ffdcPackageBlob_t;

/**
 * @brief FFDC HW Data Package Header
 */
typedef struct __attribute__((packed, aligned(8)))
{
    dumpFields_t dumpFields;//bitmapped dumpFields [ HW / REG ]
} hwDataHeader_t;

/**
 * @brief FFDC User Data Package Header
 */
typedef struct __attribute__((packed, aligned(8)))
{
    uint32_t primaryStatus:16;//Chip Op Primary status
    uint32_t secondaryStatus:16;//Chip Op Secondary status
    uint32_t fwCommitID;// FW commit ID
    uint32_t ddLevel;// DD level of the SBE
    dumpFields_t dumpFields; //bitmapped dumpFields [ TRACE / ATTR ]
} sbeDataHeader_t;

/**
 * @brief SBE plat Header
 *
 * Plat Header frame format
 * +-------------+-------------------+---------------+---------------+
 * | Byte 0      |       Byte 1      |     Byte 2    |    Bytes 3    |
 * +-------------+-------------------+---------------+---------------+
 * |        Primary Status           |        Secondary Status       | \-
 * +-----------------------------------------------------------------+   |
 * |                           FW Commit ID                          |   |-> Plat FFDC header
 * +-------------+-------------------+---------------+---------------+   |
 * |   Reserved  |     DD Major      |    DD Minor   |   Thread ID   | \-
 * +-----------------------------------------------------------------+
*/
typedef struct __attribute__((packed, aligned(4)))
{
    uint32_t                priRc       :16;
    uint32_t                secRc       :16;
    uint32_t                fwCommitId;
    uint32_t                reserved    : 8;
    uint32_t                ddMajor     : 8;
    uint32_t                ddMinor     : 8;
    uint32_t                threadId    : 8;

    /**
     * @brief set method of setting priRc and secRc member variable
     *
     * @param[in] i_priRc primary rc to set
     * @param[in] i_secRc secondary rc to set
    */
    void inline setRc (const uint16_t i_priRc, const uint16_t i_secRc)
    {
        priRc = i_priRc;
        secRc = i_secRc;
    }

    /**
     * @brief set method for setting fwCommitId member variable
     *
     * @param[in] i_commitId firmware commit id to set
    */
    void inline setfwCommitId (const uint32_t i_commitId)
    {
        fwCommitId = i_commitId;
    }

    /**
     * @brief set method for setting DD level member variable
     *
     * @param[in] i_ddMajor DD level major
     * @param[in] i_ddMinor DD level minor
    */
    void inline setDdlevel (const uint8_t i_ddMajor, const uint8_t i_ddMinor)
    {
        ddMajor = i_ddMajor;
        ddMinor = i_ddMinor;
    }

    /**
     * @brief set method for setting thread id member variable
     *
     * @param[in] i_theadId thread ID
    */
    void inline setThreadId (const uint8_t i_threadId)
    {
        threadId = i_threadId;
    }

}sbePlatHeader_t;


