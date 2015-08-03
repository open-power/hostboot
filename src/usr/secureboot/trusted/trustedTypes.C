/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/trustedTypes.C $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <string.h>
#include <sys/time.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <errl/errludstring.H>
#include "trustedTypes.H"

extern trace_desc_t* g_trac_trustedboot;

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

namespace TRUSTEDBOOT
{

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
                            size_t & io_tpmBufSize,
                            void* o_chunkPtr,
                            size_t i_chunkSize)
    {
        if (NULL != i_tpmBuf)
        {
            if (i_chunkSize > io_tpmBufSize)
            {
                return NULL;
            }
            memcpy(o_chunkPtr, i_tpmBuf, i_chunkSize);
            i_tpmBuf += i_chunkSize;
            io_tpmBufSize -= i_chunkSize;
        }
        return i_tpmBuf;
    }

    uint8_t* marshalChunk(uint8_t* o_tpmBuf,
                          size_t i_tpmBufSize,
                          size_t & io_cmdSize,
                          void* i_chunkPtr,
                          size_t i_chunkSize)
    {
        if (NULL != o_tpmBuf)
        {
            if ((io_cmdSize + i_chunkSize) > i_tpmBufSize)
            {
                return NULL;
            }
            memcpy(o_tpmBuf, i_chunkPtr, i_chunkSize);
            o_tpmBuf += i_chunkSize;
            io_cmdSize += i_chunkSize;
        }
        return o_tpmBuf;
    }

    uint8_t* TPML_TAGGED_TPM_PROPERTY::unmarshal(uint8_t* i_tpmBuf,
                                                 size_t & io_tpmBufSize,
                                                 size_t i_outBufSize)
    {

        i_tpmBuf = unmarshalChunk(i_tpmBuf, io_tpmBufSize,
                                  &count, sizeof(count));

        // Now we know the count as well
        i_tpmBuf = unmarshalChunk(i_tpmBuf, io_tpmBufSize,
                                  &(tpmProperty[0]),
                                  sizeof(TPMS_TAGGED_PROPERTY) * count);

        return i_tpmBuf;
    }

    uint8_t* TPMS_CAPABILITY_DATA::unmarshal(uint8_t* i_tpmBuf,
                                             size_t & io_tpmBufSize,
                                             size_t i_outBufSize)
    {
        i_tpmBuf = unmarshalChunk(i_tpmBuf, io_tpmBufSize,
                                  &capability, sizeof(capability));

        switch (capability)
        {
          case TRUSTEDBOOT::TPM_CAP_TPM_PROPERTIES:
              {
                  return data.tpmProperties.unmarshal(i_tpmBuf, io_tpmBufSize,
                                                      i_outBufSize);
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

    size_t TPML_DIGEST_VALUES::marshalSize() const
    {
        size_t ret = sizeof(count);
        for (size_t idx = 0; (idx < count && idx < HASH_COUNT); idx++)
        {
            ret += digests[idx].marshalSize();
        }
        return ret;
    }

    uint8_t* TPM2_BaseIn::marshal(uint8_t* o_tpmBuf, size_t i_tpmBufSize,
                                  size_t & io_cmdSize)
    {
        return marshalChunk(o_tpmBuf, i_tpmBufSize, io_cmdSize,
                            this, sizeof(TPM2_BaseIn));
    }

    uint8_t* TPM2_BaseOut::unmarshal(uint8_t* i_tpmBuf, size_t & io_tpmBufSize,
                                     size_t i_outBufSize)
    {
        if (sizeof(TPM2_BaseOut) > i_outBufSize)
        {
            return NULL;
        }
        return unmarshalChunk(i_tpmBuf, io_tpmBufSize,
                              this, sizeof(TPM2_BaseOut));
    }

    uint8_t* TPM2_2ByteIn::marshal(uint8_t* o_tpmBuf,
                                   size_t i_tpmBufSize,
                                   size_t & io_cmdSize)
    {
        // Base has already been marshaled
        return marshalChunk(o_tpmBuf, i_tpmBufSize, io_cmdSize,
                            &param, sizeof(param));
    }


    uint8_t* TPM2_GetCapabilityIn::marshal(uint8_t* o_tpmBuf,
                                           size_t i_tpmBufSize,
                                           size_t& io_cmdSize)
    {
        // Base has already been marshaled
        o_tpmBuf = marshalChunk(o_tpmBuf, i_tpmBufSize, io_cmdSize,
                                &capability, sizeof(capability));
        o_tpmBuf = marshalChunk(o_tpmBuf, i_tpmBufSize, io_cmdSize,
                                &property, sizeof(property));
        o_tpmBuf = marshalChunk(o_tpmBuf, i_tpmBufSize, io_cmdSize,
                                &propertyCount, sizeof(propertyCount));
        return o_tpmBuf;
    }

    uint8_t* TPM2_GetCapabilityOut::unmarshal(uint8_t* i_tpmBuf,
                                              size_t & io_tpmBufSize,
                                              size_t i_outBufSize)
    {
        // Base has already been unmarshaled
        if (sizeof(TPM2_GetCapabilityOut) > i_outBufSize)
        {
            return NULL;
        }
        i_tpmBuf = unmarshalChunk(i_tpmBuf, io_tpmBufSize,
                                  &moreData, sizeof(moreData));

        // Capability data block
        return capData.unmarshal(i_tpmBuf, io_tpmBufSize, i_outBufSize);

    }


} // end TRUSTEDBOOT
