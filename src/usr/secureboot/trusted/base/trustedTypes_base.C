/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/base/trustedTypes_base.C $         */
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
 * @file trustedTypes_base.C
 *
 * @brief Trusted boot type inline functions for hostboot base
 */

/////////////////////////////////////////////////////////////////
// NOTE: This file is exportable as TSS-Lite for skiboot/PHYP  //
/////////////////////////////////////////////////////////////////

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <string.h>
#ifdef __HOSTBOOT_MODULE
#include "../trustedTypes.H"
#include "../trustedboot.H"
#else
#include "trustedTypes.H"
#include "trustedboot.H"
#endif


#ifdef __cplusplus
namespace TRUSTEDBOOT
{
#endif

    uint32_t getDigestSize(TPM_Alg_Id i_algId)
    {
        uint32_t ret = 0;
        switch (i_algId)
        {
          case TPM_ALG_SHA256:
            ret = TPM_ALG_SHA256_SIZE;
            break;
          default:
            ret = 0;
            break;
        };
        return ret;
    }

    uint8_t* TPMT_HA_logMarshal(const TPMT_HA* val, uint8_t* i_logBuf)
    {
        uint16_t* field16 = (uint16_t*)i_logBuf;
        *field16 = htole16(val->algorithmId);
        i_logBuf += sizeof(uint16_t);
        memcpy(i_logBuf, val->digest.bytes,
               getDigestSize((TPM_Alg_Id)val->algorithmId));
        i_logBuf += getDigestSize((TPM_Alg_Id)val->algorithmId);
        return i_logBuf;
    }

    const uint8_t* TPMT_HA_logUnmarshal(TPMT_HA* val,
                                        const uint8_t* i_tpmBuf, bool* o_err)
    {
        size_t size = 0;
        uint16_t* field16 = NULL;

        do {
            *o_err = false;

            // algorithmId
            size = sizeof(val->algorithmId);
            field16 = (uint16_t*)i_tpmBuf;
            val->algorithmId = le16toh(*field16);
            // Ensure a valid count
            if (val->algorithmId >= TPM_ALG_INVALID_ID)
            {
                *o_err = true;
                i_tpmBuf = NULL;
                TRACFCOMP(g_trac_trustedboot,"ERROR> TPMT_HA:logUnmarshal()"
                          " invalid algorithmId %d",
                          val->algorithmId);
                break;
            }
            i_tpmBuf += size;

            // digest
            size = getDigestSize((TPM_Alg_Id)val->algorithmId);
            // Ensure a valid count
            if (size >= TPM_ALG_INVALID_SIZE)
            {
                *o_err = true;
                i_tpmBuf = NULL;
                TRACFCOMP(g_trac_trustedboot,"ERROR> TPMT_HA:logUnmarshal() "
                          "invalid algorithm size of %d for algorithm id %d",
                          (int)size, val->algorithmId);
                break;
            }

            memcpy(&(val->digest.bytes), i_tpmBuf, size);
            i_tpmBuf += size;
        } while(0);

        return i_tpmBuf;
    }

    size_t TPMT_HA_marshalSize(const TPMT_HA* val)
    {
        return (sizeof(val->algorithmId) +
                getDigestSize((TPM_Alg_Id)(val->algorithmId)));
    }

#ifdef __cplusplus
    bool TPMT_HA::operator==(const TPMT_HA& i_rhs) const
    {
        size_t digestSize = getDigestSize((TPM_Alg_Id)algorithmId);
        return (algorithmId == i_rhs.algorithmId) &&
               (memcmp(digest.bytes, i_rhs.digest.bytes, digestSize) == 0);
    }
#endif

    size_t TPML_DIGEST_VALUES_marshalSize(const TPML_DIGEST_VALUES* val)
    {
        size_t ret = sizeof(val->count);
        for (size_t idx = 0; (idx < val->count && idx < HASH_COUNT); idx++)
        {
            ret += TPMT_HA_marshalSize(&(val->digests[idx]));
        }
        return ret;
    }

    uint8_t* TPML_DIGEST_VALUES_logMarshal(const TPML_DIGEST_VALUES* val,
                                           uint8_t* i_logBuf)
    {
        uint32_t* field32 = (uint32_t*)i_logBuf;
        if (HASH_COUNT < val->count)
        {
            i_logBuf = NULL;
        }
        else
        {
            *field32 = htole32(val->count);
            i_logBuf += sizeof(uint32_t);
            for (size_t idx = 0; idx < val->count; idx++)
            {
                i_logBuf = TPMT_HA_logMarshal(&(val->digests[idx]), i_logBuf);
                if (NULL == i_logBuf) break;
            }
        }
        return i_logBuf;
    }

    const uint8_t* TPML_DIGEST_VALUES_logUnmarshal(TPML_DIGEST_VALUES* val,
                                                   const uint8_t* i_tpmBuf,
                                                   bool* o_err)
    {
        size_t size = 0;
        uint32_t* field32 = NULL;
        do {
            *o_err = false;

            // count
            size = sizeof(val->count);
            field32 = (uint32_t*)(i_tpmBuf);
            val->count = le32toh(*field32);
            // Ensure a valid count
            if (val->count > HASH_COUNT)
            {
                *o_err = true;
                i_tpmBuf = NULL;
                TRACFCOMP(g_trac_trustedboot,"ERROR> "
                          "TPML_DIGEST_VALUES:logUnmarshal() "
                          "invalid digest count %d",
                          val->count);
                break;
            }
            i_tpmBuf += size;

            // Iterate all digests
            for (size_t idx = 0; idx < val->count; idx++)
            {
                i_tpmBuf = TPMT_HA_logUnmarshal(&(val->digests[idx]),
                                                i_tpmBuf, o_err);
                    if (NULL == i_tpmBuf)
                    {
                        break;
                    }
            }
        } while(0);

        return i_tpmBuf;
    }

#ifdef __cplusplus
    bool TPML_DIGEST_VALUES::operator==(const TPML_DIGEST_VALUES& i_rhs) const
    {
        bool result = (count == i_rhs.count);
        // Iterate all digests
        for (size_t idx = 0; idx < count; idx++)
        {
            result = (result && (digests[idx] == i_rhs.digests[idx]));
        }

        return result;
    }
#endif

    const uint8_t* TCG_PCR_EVENT_logUnmarshal(TCG_PCR_EVENT* val,
                                              const uint8_t* i_tpmBuf,
                                              size_t i_bufSize,
                                              bool* o_err)
    {
        size_t size = 0;
        uint32_t* field32;

        *o_err = false;
        do {
            // Ensure enough space for unmarshalled data
            if (sizeof(TCG_PCR_EVENT) > i_bufSize)
            {
                *o_err = true;
                i_tpmBuf = NULL;
                break;
            }

            // pcrIndex
            size = sizeof(val->pcrIndex);
            field32 = (uint32_t*)(i_tpmBuf);
            val->pcrIndex = le32toh(*field32);
            // Ensure a valid pcr index
            if (val->pcrIndex >= IMPLEMENTATION_PCR)
            {
                *o_err = true;
                i_tpmBuf = NULL;
                TRACFCOMP(g_trac_trustedboot,
                  "ERROR> TCG_PCR_EVENT:logUnmarshal() invalid pcrIndex %d",
                          val->pcrIndex);
                break;
            }
            i_tpmBuf += size;

            // eventType
            size = sizeof(val->eventType);
            field32 = (uint32_t*)(i_tpmBuf);
            val->eventType = le32toh(*field32);
            // Ensure a valid event type
            if (val->eventType == 0 || val->eventType >= EV_INVALID)
            {
                *o_err = true;
                i_tpmBuf = NULL;
                TRACFCOMP(g_trac_trustedboot,
                    "ERROR> TCG_PCR_EVENT:logUnmarshal() invalid eventType %d",
                          val->eventType);
                break;
            }
            i_tpmBuf += size;

            // digest
            size = sizeof(val->digest);
            memcpy(val->digest, i_tpmBuf, size);
            i_tpmBuf += size;

            // eventSize
            size = sizeof(val->eventSize);
            field32 = (uint32_t*)(i_tpmBuf);
            val->eventSize = le32toh(*field32);
            // Ensure a valid eventSize
            if (val->eventSize >= MAX_TPM_LOG_MSG)
            {
                *o_err = true;
                i_tpmBuf = NULL;
                TRACFCOMP(g_trac_trustedboot,
                    "ERROR> TCG_PCR_EVENT:logUnmarshal() invalid eventSize %d",
                          val->eventSize);
                break;
            }
            i_tpmBuf += size;

            memcpy(val->event, i_tpmBuf, val->eventSize);
            i_tpmBuf += val->eventSize;

        } while(0);

        return i_tpmBuf;
    }

    uint8_t* TCG_PCR_EVENT_logMarshal(const TCG_PCR_EVENT* val,
                                      uint8_t* i_logBuf)
    {
        uint32_t* field32 = (uint32_t*)(i_logBuf);
        *field32 = htole32(val->pcrIndex);
        i_logBuf += sizeof(uint32_t);

        field32 = (uint32_t*)(i_logBuf);
        *field32 = htole32(val->eventType);
        i_logBuf += sizeof(uint32_t);

        memcpy(i_logBuf, val->digest, sizeof(val->digest));
        i_logBuf += sizeof(val->digest);

        field32 = (uint32_t*)(i_logBuf);
        *field32 = htole32(val->eventSize);
        i_logBuf += sizeof(uint32_t);

        if (val->eventSize > 0)
        {
            memcpy(i_logBuf, val->event, val->eventSize);
            i_logBuf += val->eventSize;
        }
        return i_logBuf;
    }

    size_t TCG_PCR_EVENT_marshalSize(const TCG_PCR_EVENT* val)
    {
        return (sizeof(TCG_PCR_EVENT) + val->eventSize - MAX_TPM_LOG_MSG);
    }

    uint8_t* TPM_EVENT_FIELD_logMarshal(const TPM_EVENT_FIELD* val,
                                        uint8_t* i_logBuf)
    {
        uint32_t* field32 = (uint32_t*)i_logBuf;
        if (MAX_TPM_LOG_MSG < val->eventSize)
        {
            i_logBuf = NULL;
        }
        else
        {
            *field32 = htole32(val->eventSize);
            i_logBuf += sizeof(uint32_t);

            memcpy(i_logBuf, val->event, val->eventSize);
            i_logBuf += val->eventSize;
        }
        return i_logBuf;
    }

    const uint8_t* TPM_EVENT_FIELD_logUnmarshal(TPM_EVENT_FIELD* val,
                                                const uint8_t* i_tpmBuf,
                                                bool* o_err)
    {
        size_t size = 0;
        uint32_t* field32 = NULL;
        do {
            *o_err = false;

            // Event size
            size = sizeof(val->eventSize);
            field32 = (uint32_t*)(i_tpmBuf);
            val->eventSize = le32toh(*field32);
            i_tpmBuf += size;

            // Event
            size = val->eventSize;
            if (size > MAX_TPM_LOG_MSG)
            {
                *o_err = true;
                i_tpmBuf = NULL;
                break;
            }
            memcpy(&val->event, i_tpmBuf, size);
            i_tpmBuf += size;
        } while(0);

        return i_tpmBuf;
    }
    size_t TPM_EVENT_FIELD_marshalSize(const TPM_EVENT_FIELD* val)
    {
        return (sizeof(val->eventSize) + val->eventSize);
    }


#ifdef __cplusplus
    bool TPM_EVENT_FIELD::operator==(const TPM_EVENT_FIELD& i_rhs) const
    {
        return (eventSize == i_rhs.eventSize) &&
               (memcmp(event, i_rhs.event, eventSize) == 0);
    }
#endif


    size_t TCG_PCR_EVENT2_marshalSize(const TCG_PCR_EVENT2* val)
    {
        return (sizeof(val->pcrIndex) + sizeof(val->eventType) +
                TPML_DIGEST_VALUES_marshalSize(&(val->digests)) +
                TPM_EVENT_FIELD_marshalSize(&(val->event)));
    }

    uint8_t* TCG_PCR_EVENT2_logMarshal(const TCG_PCR_EVENT2* val,
                                       uint8_t* i_logBuf)
    {
        uint32_t* field32 = (uint32_t*)i_logBuf;
        *field32 = htole32(val->pcrIndex);
        i_logBuf += sizeof(uint32_t);
        field32 = (uint32_t*)i_logBuf;
        *field32 = htole32(val->eventType);
        i_logBuf += sizeof(uint32_t);

        i_logBuf = TPML_DIGEST_VALUES_logMarshal(&(val->digests),i_logBuf);
        if (NULL != i_logBuf)
        {
            i_logBuf = TPM_EVENT_FIELD_logMarshal(&(val->event),i_logBuf);
        }
        return i_logBuf;
    }

    const uint8_t* TCG_PCR_EVENT2_logUnmarshal(TCG_PCR_EVENT2* val,
                                               const uint8_t* i_tpmBuf,
                                               size_t i_bufSize,
                                               bool* o_err)
    {
        size_t size = 0;
        uint32_t* field32 = NULL;

        do {
            *o_err = false;

            // Ensure enough space for unmarshalled data
            if (sizeof(TCG_PCR_EVENT2) > i_bufSize)
            {
                *o_err = true;
                i_tpmBuf = NULL;
                break;
            }

            // pcrIndex
            size = sizeof(val->pcrIndex);
            field32 = (uint32_t*)(i_tpmBuf);
            val->pcrIndex = le32toh(*field32);
            // Ensure a valid pcr index
            if (val->pcrIndex > IMPLEMENTATION_PCR)
            {
                *o_err = true;
                i_tpmBuf = NULL;
                TRACFCOMP(g_trac_trustedboot,"ERROR> TCG_PCR_EVENT2:"
                          "logUnmarshal() invalid pcrIndex %d",
                          val->pcrIndex);
                break;
            }
            i_tpmBuf += size;

            // eventType
            size = sizeof(val->eventType);
            field32 = (uint32_t*)(i_tpmBuf);
            val->eventType = le32toh(*field32);
            // Ensure a valid event type
            if (val->eventType == 0 ||
                val->eventType >= EV_INVALID)
            {
                *o_err = true;
                i_tpmBuf = NULL;
                TRACFCOMP(g_trac_trustedboot,"ERROR> TCG_PCR_EVENT2:"
                          "logUnmarshal() invalid eventType %d",
                          val->eventType);
                break;
            }
            i_tpmBuf += size;

            // TPML_DIGEST_VALUES
            i_tpmBuf = TPML_DIGEST_VALUES_logUnmarshal(&(val->digests),
                                                       i_tpmBuf, o_err);
            if (i_tpmBuf == NULL)
            {
                break;
            }

            // TPM EVENT FIELD
            i_tpmBuf = TPM_EVENT_FIELD_logUnmarshal(&(val->event),
                                                    i_tpmBuf, o_err);
            if (i_tpmBuf == NULL)
            {
                break;
            }
        } while(0);

        return i_tpmBuf;
    }

#ifdef __cplusplus
    bool TCG_PCR_EVENT2::operator==(const TCG_PCR_EVENT2& i_rhs) const
    {
        return (pcrIndex == i_rhs.pcrIndex) &&
               (eventType == i_rhs.eventType) &&
               (digests == i_rhs.digests) &&
               (event == i_rhs.event);
    }
} // end TRUSTEDBOOT
#endif
