/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/plugins/sbeIoFfdcType.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
#ifndef __SBEIO_FFDC_TYPE_H
#define __SBEIO_FFDC_TYPE_H

//Bit mapped identifiers
#define SBEIO_FFDC_ATTR_DUMP      0x0001
#define SBEIO_FFDC_TRACE_DUMP     0x0002
#define SBEIO_FFDC_ALL_DUMP       0xFFFF

/* Structure indicating the contents of FFDC package
 * value 'true' - field present;value 'false' - field not present
 * bit_0 - attribute dump
 * bit_1 - trace buffer dump
 * bit 2-31 - reserved
 */
typedef struct
{
    uint32_t attrField:1;
    uint32_t traceField:1;
    uint32_t reserved:30;
    /* @breif - set dump fields
     *
     * @param[in] - uint32_t value to be updated
     */
    void set(uint32_t val)
    {
        if(val & SBEIO_FFDC_ATTR_DUMP)
        {
            attrField = true;
        }
        if(val & SBEIO_FFDC_TRACE_DUMP)
        {
            traceField = true;
        }
    }
    /* @brief - get dump fields as uint32_t
     *
     * @return - uint32_t value
     */
    uint32_t get()
    {
        uint32_t l_val = 0;
        if(attrField)
        {
            l_val |= SBEIO_FFDC_ATTR_DUMP;
        }
        if(traceField)
        {
            l_val |= SBEIO_FFDC_TRACE_DUMP;
        }
        return l_val;
    }
} sbeIoFfdcDumpFields_t;

//Sturcture indicating the type of ffdc user data blob
//and its length in bytes
typedef struct
{
    uint32_t fieldId:16;
    uint32_t fieldLen:16;
} sbeIoFfdcUserDataIdentifier_t;

//Structure of ffdc user data blob
typedef struct
{
    sbeIoFfdcUserDataIdentifier_t userDataId;
    const void *userDataPtr;
} sbeIoFfdcUserData_t;

//keep it packed to 4byte boundary to avoid packing bytes
typedef struct
{
    uint32_t primaryStatus:16;//Chip Op Primary status
    uint32_t secondaryStatus:16;//Chip Op Secondary status
    uint32_t fwCommitID;// FW commit ID
    sbeIoFfdcDumpFields_t dumpFields;//bitmapped dumpFields
} sbeIoFfdcDataHeader_t;

#endif //__SBEIO_FFDC_TYPE_H
