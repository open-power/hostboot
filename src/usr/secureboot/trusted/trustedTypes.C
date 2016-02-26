/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/trustedTypes.C $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
 * @file trustedTypes.C
 *
 * @brief Trusted boot type inline functions
 */

/////////////////////////////////////////////////////////////////
// NOTE: This file is exportable as TSS-Lite for skiboot/PHYP  //
/////////////////////////////////////////////////////////////////

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <string.h>
#include "trustedboot.H"
#include "trustedTypes.H"

#ifdef __cplusplus
namespace TRUSTEDBOOT
{
#endif

    uint8_t* unmarshalChunk(uint8_t* i_tpmBuf,
                            size_t * io_tpmBufSize,
                            void* o_chunkPtr,
                            size_t i_chunkSize);

    uint8_t* marshalChunk(uint8_t* o_tpmBuf,
                          size_t i_tpmBufSize,
                          size_t * io_cmdSize,
                          void* i_chunkPtr,
                          size_t i_chunkSize);

    uint32_t getDigestSize(TPM_Alg_Id i_algId)
    {
        uint32_t ret = 0;
        switch (i_algId)
        {
          case TPM_ALG_SHA1:
            ret = TPM_ALG_SHA1_SIZE;
            break;
          case TPM_ALG_SHA256:
            ret = TPM_ALG_SHA256_SIZE;
            break;
          default:
            ret = 0;
            break;
        };
        return ret;
    }

    uint8_t* unmarshalChunk(uint8_t* i_tpmBuf,
                            size_t * io_tpmBufSize,
                            void* o_chunkPtr,
                            size_t i_chunkSize)
    {
        if (NULL != i_tpmBuf)
        {
            if (i_chunkSize > *io_tpmBufSize)
            {
                return NULL;
            }
            memcpy(o_chunkPtr, i_tpmBuf, i_chunkSize);
            i_tpmBuf += i_chunkSize;
            *io_tpmBufSize -= i_chunkSize;
        }
        return i_tpmBuf;
    }

    uint8_t* marshalChunk(uint8_t* o_tpmBuf,
                          size_t i_tpmBufSize,
                          size_t * io_cmdSize,
                          void* i_chunkPtr,
                          size_t i_chunkSize)
    {
        if (NULL != o_tpmBuf)
        {
            if ((*io_cmdSize + i_chunkSize) > i_tpmBufSize)
            {
                return NULL;
            }
            memcpy(o_tpmBuf, i_chunkPtr, i_chunkSize);
            o_tpmBuf += i_chunkSize;
            *io_cmdSize += i_chunkSize;
        }
        return o_tpmBuf;
    }

    uint8_t* TPML_TAGGED_TPM_PROPERTY_unmarshal(TPML_TAGGED_TPM_PROPERTY* val,
                                                uint8_t* i_tpmBuf,
                                                size_t* io_tpmBufSize)
    {

        i_tpmBuf = unmarshalChunk(i_tpmBuf, io_tpmBufSize,
                                  &(val->count), sizeof(val->count));

        // Now we know the count as well
        i_tpmBuf = unmarshalChunk(i_tpmBuf, io_tpmBufSize,
                                  &(val->tpmProperty[0]),
                                  sizeof(TPMS_TAGGED_PROPERTY) * val->count);

        return i_tpmBuf;
    }

    uint8_t* TPMS_CAPABILITY_DATA_unmarshal(TPMS_CAPABILITY_DATA* val,
                                            uint8_t* i_tpmBuf,
                                            size_t * io_tpmBufSize)
    {
        i_tpmBuf = unmarshalChunk(i_tpmBuf, io_tpmBufSize,
                                  &(val->capability),
                                  sizeof(val->capability));

        switch (val->capability)
        {
          case TPM_CAP_TPM_PROPERTIES:
              {
                  return TPML_TAGGED_TPM_PROPERTY_unmarshal(
                                      &(val->data.tpmProperties), i_tpmBuf,
                                      io_tpmBufSize);
              }
              break;
          default:
              {
                  TRACFCOMP( g_trac_trustedboot,
                       "TPMS_CAPABILITY_DATA::unmarshal Unknown capability");
                  return NULL;
              }
              break;
        }
        return NULL;
    }

    size_t TCG_PCR_EVENT_marshalSize(TCG_PCR_EVENT* val)
    {
        return (sizeof(TCG_PCR_EVENT) + val->eventSize - MAX_TPM_LOG_MSG);
    }

    size_t TPMT_HA_marshalSize(TPMT_HA* val)
    {
        return (sizeof(TPMT_HA) - sizeof(TPMU_HA) +
                getDigestSize((TPM_Alg_Id)(val->algorithmId)));
    }

    size_t TPML_DIGEST_VALUES_marshalSize(TPML_DIGEST_VALUES* val)
    {
        size_t ret = sizeof(val->count);
        for (size_t idx = 0; (idx < val->count && idx < HASH_COUNT); idx++)
        {
            ret += TPMT_HA_marshalSize(&(val->digests[idx]));
        }
        return ret;
    }

    size_t TPM_EVENT_FIELD_marshalSize(TPM_EVENT_FIELD* val)
    {
        return (sizeof(val->eventSize) + val->eventSize);
    }

    uint8_t* TPM2_BaseIn_marshal(TPM2_BaseIn* val, uint8_t* o_tpmBuf,
                                 size_t i_tpmBufSize, size_t* io_cmdSize)
    {
        return marshalChunk(o_tpmBuf, i_tpmBufSize, io_cmdSize,
                            val, sizeof(TPM2_BaseIn));
    }

    uint8_t* TPM2_BaseOut_unmarshal(TPM2_BaseOut* val, uint8_t* i_tpmBuf,
                                    size_t* io_tpmBufSize, size_t i_outBufSize)
    {
        if (sizeof(TPM2_BaseOut) > i_outBufSize)
        {
            return NULL;
        }
        return unmarshalChunk(i_tpmBuf, io_tpmBufSize,
                              val, sizeof(TPM2_BaseOut));
    }

    uint8_t* TPM2_2ByteIn_marshal(TPM2_2ByteIn* val,
                                  uint8_t* o_tpmBuf,
                                  size_t i_tpmBufSize,
                                  size_t* io_cmdSize)
    {
        // Base has already been marshaled
        return marshalChunk(o_tpmBuf, i_tpmBufSize, io_cmdSize,
                            &(val->param), sizeof(val->param));
    }


    uint8_t* TPM2_GetCapabilityIn_marshal(TPM2_GetCapabilityIn* val,
                                          uint8_t* o_tpmBuf,
                                          size_t i_tpmBufSize,
                                          size_t* io_cmdSize)
    {
        // Base has already been marshaled
        o_tpmBuf = marshalChunk(o_tpmBuf, i_tpmBufSize, io_cmdSize,
                                &(val->capability),
                                sizeof(val->capability));
        o_tpmBuf = marshalChunk(o_tpmBuf, i_tpmBufSize, io_cmdSize,
                                &(val->property),
                                sizeof(val->property));
        o_tpmBuf = marshalChunk(o_tpmBuf, i_tpmBufSize, io_cmdSize,
                                &(val->propertyCount),
                                sizeof(val->propertyCount));
        return o_tpmBuf;
    }

    uint8_t* TPM2_GetCapabilityOut_unmarshal(TPM2_GetCapabilityOut* val,
                                             uint8_t* i_tpmBuf,
                                             size_t* io_tpmBufSize,
                                             size_t i_outBufSize)
    {
        // Base has already been unmarshaled
        if (sizeof(TPM2_GetCapabilityOut) > i_outBufSize)
        {
            return NULL;
        }
        i_tpmBuf = unmarshalChunk(i_tpmBuf, io_tpmBufSize,
                                  &(val->moreData), sizeof(val->moreData));

        // Capability data block
        return TPMS_CAPABILITY_DATA_unmarshal(&(val->capData), i_tpmBuf,
                                              io_tpmBufSize);

    }


#ifdef __cplusplus
} // end TRUSTEDBOOT
#endif
