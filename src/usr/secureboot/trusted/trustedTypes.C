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

    const uint8_t* unmarshalChunk(const uint8_t* i_tpmBuf,
                            size_t * io_tpmBufSize,
                            void* o_chunkPtr,
                            size_t i_chunkSize);

    uint8_t* marshalChunk(uint8_t* o_tpmBuf,
                          size_t i_tpmBufSize,
                          size_t * io_cmdSize,
                          const void* i_chunkPtr,
                          size_t i_chunkSize);

    const uint8_t* unmarshalChunk(const uint8_t* i_tpmBuf,
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
                          const void* i_chunkPtr,
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

    const uint8_t* TPML_TAGGED_TPM_PROPERTY_unmarshal(
                           TPML_TAGGED_TPM_PROPERTY* val,
                           const uint8_t* i_tpmBuf,
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

    const uint8_t* TPMS_CAPABILITY_DATA_unmarshal(TPMS_CAPABILITY_DATA* val,
                                                  const uint8_t* i_tpmBuf,
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

    uint8_t* TPMT_HA_marshal(const TPMT_HA* val,
                             uint8_t* o_tpmBuf,
                             size_t i_tpmBufSize,
                             size_t * io_cmdSize)
    {
        o_tpmBuf = marshalChunk(o_tpmBuf, i_tpmBufSize, io_cmdSize,
                                &(val->algorithmId), sizeof(val->algorithmId));
        if (getDigestSize((TPM_Alg_Id)val->algorithmId) == 0)
        {
            return NULL;
        }
        o_tpmBuf = marshalChunk(o_tpmBuf, i_tpmBufSize, io_cmdSize,
                                &(val->digest.bytes),
                                getDigestSize((TPM_Alg_Id)val->algorithmId));
        return o_tpmBuf;
    }

    uint8_t* TPML_DIGEST_VALUES_marshal(const TPML_DIGEST_VALUES* val,
                                        uint8_t* o_tpmBuf,
                                        size_t i_tpmBufSize,
                                        size_t * io_cmdSize)
    {
        o_tpmBuf = marshalChunk(o_tpmBuf, i_tpmBufSize, io_cmdSize,
                                &(val->count), sizeof(val->count));
        if (NULL != o_tpmBuf && HASH_COUNT < val->count)
        {
            o_tpmBuf = NULL;
        }
        else
        {
            for (size_t idx = 0; idx < val->count; idx++)
            {
                o_tpmBuf = TPMT_HA_marshal(&(val->digests[idx]),
                                           o_tpmBuf,
                                           i_tpmBufSize,
                                           io_cmdSize);
                if (NULL == o_tpmBuf)
                {
                    break;
                }
            }
        }
        return o_tpmBuf;
    }

    uint8_t* TPM2_BaseIn_marshal(const TPM2_BaseIn* val, uint8_t* o_tpmBuf,
                                 size_t i_tpmBufSize, size_t* io_cmdSize)
    {
        return marshalChunk(o_tpmBuf, i_tpmBufSize, io_cmdSize,
                            val, sizeof(TPM2_BaseIn));
    }

    const uint8_t* TPM2_BaseOut_unmarshal(TPM2_BaseOut* val,
                                          const uint8_t* i_tpmBuf,
                                          size_t* io_tpmBufSize,
                                          size_t i_outBufSize)
    {
        if (sizeof(TPM2_BaseOut) > i_outBufSize)
        {
            return NULL;
        }
        return unmarshalChunk(i_tpmBuf, io_tpmBufSize,
                              val, sizeof(TPM2_BaseOut));
    }

    uint8_t* TPM2_2ByteIn_marshal(const TPM2_2ByteIn* val,
                                  uint8_t* o_tpmBuf,
                                  size_t i_tpmBufSize,
                                  size_t* io_cmdSize)
    {
        // Base has already been marshaled
        return marshalChunk(o_tpmBuf, i_tpmBufSize, io_cmdSize,
                            &(val->param), sizeof(val->param));
    }

    uint8_t* TPM2_4ByteIn_marshal(const TPM2_4ByteIn* val,
                                  uint8_t* o_tpmBuf,
                                  size_t i_tpmBufSize,
                                  size_t* io_cmdSize)
    {
        // Base has already been marshaled
        return marshalChunk(o_tpmBuf, i_tpmBufSize, io_cmdSize,
                            &(val->param), sizeof(val->param));
    }

    uint8_t* TPM2_GetCapabilityIn_marshal(const TPM2_GetCapabilityIn* val,
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

    const uint8_t* TPM2_GetCapabilityOut_unmarshal(TPM2_GetCapabilityOut* val,
                                                   const uint8_t* i_tpmBuf,
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

    uint8_t* TPM2_ExtendIn_marshalHandle(const TPM2_ExtendIn* val,
                                         uint8_t* o_tpmBuf,
                                         size_t i_tpmBufSize,
                                         size_t* io_cmdSize)
    {
        // Base has already been marshaled
        // only marshal the pcr handle in this stage
        return marshalChunk(o_tpmBuf, i_tpmBufSize, io_cmdSize,
                            &(val->pcrHandle), sizeof(val->pcrHandle));
    }

    uint8_t* TPM2_ExtendIn_marshalParms(const TPM2_ExtendIn* val,
                                        uint8_t* o_tpmBuf,
                                        size_t i_tpmBufSize,
                                        size_t* io_cmdSize)
    {
        // Base and handle has already been marshaled
        return (TPML_DIGEST_VALUES_marshal(&(val->digests), o_tpmBuf,
                                           i_tpmBufSize, io_cmdSize));
    }

    uint8_t* TPMS_PCR_SELECTION_marshal(const TPMS_PCR_SELECTION* val,
                                        uint8_t* o_tpmBuf,
                                        size_t i_tpmBufSize,
                                        size_t* io_cmdSize)
    {
        o_tpmBuf = marshalChunk(o_tpmBuf, i_tpmBufSize, io_cmdSize,
                                &(val->algorithmId), sizeof(val->algorithmId));
        o_tpmBuf = marshalChunk(o_tpmBuf, i_tpmBufSize, io_cmdSize,
                               &(val->sizeOfSelect), sizeof(val->sizeOfSelect));

        if (NULL != o_tpmBuf &&
            PCR_SELECT_MAX < val->sizeOfSelect)
        {
            return NULL;
        }

        o_tpmBuf = marshalChunk(o_tpmBuf, i_tpmBufSize, io_cmdSize,
                                val->pcrSelect, val->sizeOfSelect);
        return o_tpmBuf;
    }

    const uint8_t* TPMS_PCR_SELECTION_unmarshal(TPMS_PCR_SELECTION* val,
                                                const uint8_t* i_tpmBuf,
                                                size_t* io_tpmBufSize)
    {
        i_tpmBuf = unmarshalChunk(i_tpmBuf, io_tpmBufSize,
                                  &(val->algorithmId),
                                  sizeof(val->algorithmId));
        i_tpmBuf = unmarshalChunk(i_tpmBuf, io_tpmBufSize,
                                  &(val->sizeOfSelect),
                                  sizeof(val->sizeOfSelect));
        if (NULL != i_tpmBuf &&
            PCR_SELECT_MAX < val->sizeOfSelect)
        {
            return NULL;
        }
        i_tpmBuf = unmarshalChunk(i_tpmBuf, io_tpmBufSize,
                                  val->pcrSelect, val->sizeOfSelect);

        return i_tpmBuf;
    }

    const uint8_t* TPM2B_DIGEST_unmarshal(TPM2B_DIGEST* val,
                                    const uint8_t* i_tpmBuf,
                                    size_t* io_tpmBufSize)
    {
        i_tpmBuf = unmarshalChunk(i_tpmBuf, io_tpmBufSize,
                                  &val->size, sizeof(val->size));
        if (NULL != i_tpmBuf &&
            sizeof(TPMU_HA) < val->size)
        {
            TRACUCOMP( g_trac_trustedboot,
                       "TPM2B_DIGEST::unmarshal invalid size");
            return NULL;
        }
        i_tpmBuf = unmarshalChunk(i_tpmBuf, io_tpmBufSize,
                                  val->buffer, val->size);
        return i_tpmBuf;

    }

    const uint8_t* TPML_DIGEST_unmarshal(TPML_DIGEST* val,
                                   const uint8_t* i_tpmBuf,
                                   size_t* io_tpmBufSize)
    {
        i_tpmBuf = unmarshalChunk(i_tpmBuf, io_tpmBufSize,
                                  &(val->count), sizeof(val->count));
        if (NULL != i_tpmBuf && HASH_COUNT < val->count)
        {
            TRACUCOMP( g_trac_trustedboot,
                       "TPML_DIGEST::unmarshal invalid count %d", val->count);
            i_tpmBuf = NULL;
        }
        else if (NULL != i_tpmBuf)
        {
            for (size_t idx = 0; idx < val->count; idx++)
            {
                i_tpmBuf = TPM2B_DIGEST_unmarshal(&(val->digests[idx]),
                                                  i_tpmBuf,
                                                  io_tpmBufSize);
                if (NULL == i_tpmBuf)
                {
                    break;
                }
            }
        }
        return i_tpmBuf;

    }

    uint8_t* TPML_PCR_SELECTION_marshal(const TPML_PCR_SELECTION* val,
                                        uint8_t* o_tpmBuf,
                                        size_t i_tpmBufSize,
                                        size_t* io_cmdSize)
    {
        o_tpmBuf = marshalChunk(o_tpmBuf, i_tpmBufSize, io_cmdSize,
                                &(val->count), sizeof(val->count));
        if (NULL != o_tpmBuf && HASH_COUNT < val->count)
        {
            TRACUCOMP( g_trac_trustedboot,
                       "TPML_PCR_SELECTION::marshal invalid count");
            o_tpmBuf = NULL;
        }
        else if (NULL != o_tpmBuf)
        {
            for (size_t idx = 0; idx < val->count; idx++)
            {
                o_tpmBuf = TPMS_PCR_SELECTION_marshal(
                                          &(val->pcrSelections[idx]),
                                          o_tpmBuf,
                                          i_tpmBufSize,
                                          io_cmdSize);
                if (NULL == o_tpmBuf)
                {
                    break;
                }
            }
        }
        return o_tpmBuf;
    }

    const uint8_t* TPML_PCR_SELECTION_unmarshal(TPML_PCR_SELECTION* val,
                                          const uint8_t* i_tpmBuf,
                                          size_t* io_tpmBufSize)
    {
        i_tpmBuf = unmarshalChunk(i_tpmBuf, io_tpmBufSize,
                                  &(val->count), sizeof(val->count));
        if (NULL != i_tpmBuf && HASH_COUNT < val->count)
        {
            TRACUCOMP( g_trac_trustedboot,
                       "TPML_PCR_SELECTION::unmarshal invalid count");
            i_tpmBuf = NULL;
        }
        else if (NULL != i_tpmBuf)
        {
            for (size_t idx = 0; idx < val->count; idx++)
            {
                i_tpmBuf = TPMS_PCR_SELECTION_unmarshal(
                                 &(val->pcrSelections[idx]),
                                 i_tpmBuf,
                                 io_tpmBufSize);
                if (NULL == i_tpmBuf)
                {
                    break;
                }
            }
        }
        return i_tpmBuf;

    }

    uint8_t* TPM2_PcrReadIn_marshal(const TPM2_PcrReadIn* val,
                                    uint8_t* o_tpmBuf,
                                    size_t i_tpmBufSize,
                                    size_t* io_cmdSize)
    {
        // Base and handle has already been marshaled
        return (TPML_PCR_SELECTION_marshal(&(val->pcrSelectionIn), o_tpmBuf,
                                           i_tpmBufSize, io_cmdSize));
    }

    const uint8_t* TPM2_PcrReadOut_unmarshal(TPM2_PcrReadOut* val,
                                       const uint8_t* i_tpmBuf,
                                       size_t* io_tpmBufSize,
                                       size_t i_outBufSize)
    {
        // Base and handle has already been marshaled
        if (sizeof(TPM2_PcrReadOut) > i_outBufSize) return NULL;
        i_tpmBuf = unmarshalChunk(i_tpmBuf, io_tpmBufSize,
                                  &(val->pcrUpdateCounter),
                                  sizeof(val->pcrUpdateCounter));

        i_tpmBuf = TPML_PCR_SELECTION_unmarshal(&(val->pcrSelectionOut),
                                                i_tpmBuf, io_tpmBufSize);
        i_tpmBuf = TPML_DIGEST_unmarshal(&(val->pcrValues), i_tpmBuf,
                                         io_tpmBufSize);
        return i_tpmBuf;

    }

    uint8_t* TPMS_AUTH_COMMAND_marshal(const TPMS_AUTH_COMMAND* val,
                                       uint8_t* o_tpmBuf,
                                       size_t i_tpmBufSize,
                                       size_t* io_cmdSize)
    {
        return marshalChunk(o_tpmBuf, i_tpmBufSize, io_cmdSize,
                            val, sizeof(TPMS_AUTH_COMMAND));
    }

#ifdef __cplusplus
} // end TRUSTEDBOOT
#endif
