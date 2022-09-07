/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plugins/prdfPfa5Data.h $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2022                        */
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

#if !defined(prdfPfa5Data_h)
#define prdfPfa5Data_h
/**
 @file prdfPfa5Data.h
 @brief Version 5 format of the Pfa Data
*/

#include <iipconst.h>
#include <utilstream.H>
#include <string.h>

namespace PRDF
{
#if defined(PRDF_HOSTBOOT_ERRL_PLUGIN)
namespace HOSTBOOT
{
#elif defined(PRDF_FSP_ERRL_PLUGIN)
namespace FSP
{
#endif

const uint32_t PFA5_Format = 0x50464135;

const uint32_t MruListLIMIT  = 8;
const uint32_t SigListLIMIT  = 8;

// Size of PRD Capture Data
#ifdef __HOSTBOOT_MODULE
// Total error log size for Hostboot error logs is 4K.
const uint32_t CaptureDataSize = 2048;
#else
const uint32_t CaptureDataSize = 4096*2;
#endif
enum ErrlVersion
{
    ErrlVer1    = 1,
    ErrlVer2    = 2,
};

enum ErrlSubsect
{
    ErrlSectPFA5_1   = 51,
    ErrlCapData_1    = 1,
    ErrlMruData      = 62, // For the 80 byte centaur DQ pin map
    ErrlString       = 10,

    // The reason for the subsystem numbering above is lost. Starting new user
    // data sections for FFDC at 70.
    ErrlL2LineDeleteFfdc = 70,
    ErrlL3LineDeleteFfdc = 71,
    ErrlScratchSig       = 72,
};

struct MsDumpStruct
{
    int32_t content;
    HUID    id;

    friend UtilStream& operator<<( UtilStream& i_left, MsDumpStruct& i_right )
    {
        i_left << i_right.content << i_right.id;
        return i_left;
    };

    friend UtilStream& operator>>( UtilStream& i_left, MsDumpStruct& i_right )
    {
        i_left >> i_right.content >>i_right.id;
        return i_left;
    };
};

struct PfaMruListStruct
{
    uint32_t callout;  // 32-bit representation of HUID, MemoryMru, symbolic FRU
    uint8_t  type;     // See enum PRDcallout::MruType
    uint8_t  priority; // See enum srciPriority (in srci/fsp/srci.H)
    uint8_t  gardState;

    friend UtilStream& operator<<( UtilStream& i_left,
                                   PfaMruListStruct& i_right )
    {
        i_left << i_right.callout << i_right.type << i_right.priority
               << i_right.gardState;

        return i_left;
    };

    friend UtilStream& operator>>( UtilStream& i_left,
                                   PfaMruListStruct& i_right )
    {
        i_left >> i_right.callout >> i_right.type >> i_right.priority
               >> i_right.gardState;

        return i_left;
    };
};

struct PfaSigListStruct
{
    HUID     chipId;
    uint32_t signature;

    friend UtilStream& operator<<( UtilStream& i_left,
                                   PfaSigListStruct& i_right )
    {
        i_left << i_right.chipId << i_right.signature;
        return i_left;
    };

    friend UtilStream& operator>>( UtilStream& i_left,
                                   PfaSigListStruct& i_right )
    {
        i_left >> i_right.chipId >> i_right.signature;
        return i_left;
    };
};

struct PfaData
{
    // Dump info
    // NOTE: The msDumpLabel and its information must be first in this
    //       structure. ATTN handling is dependent on this ordering.
    uint32_t     msDumpLabel[2];
    MsDumpStruct msDumpInfo;

    // Error log actions and severity
    uint32_t errlActions          :16, // See enum errlActions (in errltypes.H)
             errlSeverity         : 8, // See enum errlSeverity (in errltypes.H)
             serviceActionCounter : 8; // Number of service actions requested
                                       // by PRD.

    // PRD Service Data Collector Flags (1:true, 0:false)
    uint32_t DUMP                 :1,
             UERE                 :1,
             SUE                  :1,
             AT_THRESHOLD         :1,
             DEGRADED             :1,
             SERVICE_CALL         :1,
             TRACKIT              :1,
             TERMINATE            :1,
             LOGIT                :1,
             MEM_CHNL_FAIL        :1,
             PROC_CORE_CS         :1,
             USING_SAVED_SDC      :1,
             LAST_CORE_TERMINATE  :1,
             DEFER_DECONFIG       :1,
             SECONDARY_ERROR      :1,
             Reserved             :17;

    // Thresholding
    uint32_t errorCount :16, // Number of occurrences of this attention
             threshold  :16; // Threshold for this attention

    // Attention types and GARD state.
    uint32_t priAttnType      : 8, // primary attention type
             secAttnType      : 8, // secondary attention type
             globalGardPolicy : 8, // See enum HWAS::GARD_ErrorType
             unUsed           : 8;

    uint32_t mruListCount;                  // Total number of MRUs.
    PfaMruListStruct mruList[MruListLIMIT]; // Full list of MRUs.

    uint32_t sigListCount;                  // Total number of multi-signatures.
    PfaSigListStruct sigList[SigListLIMIT]; // Full list of multi-signatures.

    /**
     * @brief Default constructor
     */
    PfaData()
    {
        memset( &mruList[0],  0x00, sizeof(PfaMruListStruct)  * MruListLIMIT  );
        memset( &sigList[0],  0x00, sizeof(PfaSigListStruct)  * SigListLIMIT  );
    }

    friend UtilStream& operator<<(UtilStream& i_left, PfaData& i_right)
    {
        i_left << i_right.msDumpLabel[0] << i_right.msDumpLabel[1]
               << i_right.msDumpInfo;

        i_left << ( (i_right.errlActions          << 16) |
                    (i_right.errlSeverity         <<  8) |
                    (i_right.serviceActionCounter      ) );

        i_left << ( (i_right.DUMP                 << 31) |
                    (i_right.UERE                 << 30) |
                    (i_right.SUE                  << 29) |
                    (i_right.AT_THRESHOLD         << 28) |
                    (i_right.DEGRADED             << 27) |
                    (i_right.SERVICE_CALL         << 26) |
                    (i_right.TRACKIT              << 25) |
                    (i_right.TERMINATE            << 24) |
                    (i_right.LOGIT                << 23) |
                    // FYI, one deprecated entry was removed. To make the
                    // parser compatible with older or newer error logs, this
                    // bit must remain a hole (i.e. it can be reused, but
                    // subsequent data must remain in the bit positions that
                    // they are currently in).
                    (i_right.MEM_CHNL_FAIL        << 21) |
                    (i_right.PROC_CORE_CS         << 20) |
                    (i_right.USING_SAVED_SDC      << 19) |
                    (i_right.LAST_CORE_TERMINATE  << 18) |
                    (i_right.DEFER_DECONFIG       << 17) |
                    (i_right.SECONDARY_ERROR      << 16) |
                    (i_right.Reserved                  ) );

        i_left << ( (i_right.errorCount << 16) |
                    (i_right.threshold       ) );

        i_left << ( (i_right.priAttnType      << 24) |
                    (i_right.secAttnType      << 16) |
                    (i_right.globalGardPolicy <<  8) |
                    (i_right.unUsed              ) );

        i_left << i_right.mruListCount;
        for ( uint32_t i = 0; i < i_right.mruListCount; i++ )
            i_left << i_right.mruList[i];

        i_left << i_right.sigListCount;
        for ( uint32_t i = 0; i < i_right.sigListCount; i++ )
            i_left << i_right.sigList[i];

        return i_left;
    };

    friend UtilStream& operator>>(UtilStream& i_left, PfaData& i_right)
    {
        uint32_t l_tmp[5];
        i_left >> i_right.msDumpLabel[0] >> i_right.msDumpLabel[1]
               >> i_right.msDumpInfo
               >> l_tmp[1]
               >> l_tmp[2]
               >> l_tmp[3]
               >> l_tmp[4];

        i_right.errlActions          = (l_tmp[1] >> 16) & 0xFFFF;
        i_right.errlSeverity         = (l_tmp[1] >>  8) & 0xFF;
        i_right.serviceActionCounter = (l_tmp[1]      ) & 0xFF;

        i_right.DUMP                = (l_tmp[2] >> 31) & 0x01;
        i_right.UERE                = (l_tmp[2] >> 30) & 0x01;
        i_right.SUE                 = (l_tmp[2] >> 29) & 0x01;
        i_right.AT_THRESHOLD        = (l_tmp[2] >> 28) & 0x01;
        i_right.DEGRADED            = (l_tmp[2] >> 27) & 0x01;
        i_right.SERVICE_CALL        = (l_tmp[2] >> 26) & 0x01;
        i_right.TRACKIT             = (l_tmp[2] >> 25) & 0x01;
        i_right.TERMINATE           = (l_tmp[2] >> 24) & 0x01;
        i_right.LOGIT               = (l_tmp[2] >> 23) & 0x01;
        // FYI, one deprecated entry was removed. To make the parser
        // compatible with older or newer error logs, this bit must remain a
        // hole (i.e. it can be reused, but subsequent data must remain in the
        // bit positions that they are currently in).
        i_right.MEM_CHNL_FAIL       = (l_tmp[2] >> 21) & 0x01;
        i_right.PROC_CORE_CS        = (l_tmp[2] >> 20) & 0x01;
        i_right.USING_SAVED_SDC     = (l_tmp[2] >> 19) & 0x01;
        i_right.LAST_CORE_TERMINATE = (l_tmp[2] >> 18) & 0x01;
        i_right.DEFER_DECONFIG      = (l_tmp[2] >> 17) & 0x01;
        i_right.SECONDARY_ERROR     = (l_tmp[2] >> 16) & 0x01;

        i_right.errorCount = (l_tmp[3] >> 16) & 0xFFFF;
        i_right.threshold  = (l_tmp[3]      ) & 0xFFFF;

        i_right.priAttnType      = (l_tmp[4] >> 24) & 0xFF;
        i_right.secAttnType      = (l_tmp[4] >> 16) & 0xFF;
        i_right.globalGardPolicy = (l_tmp[4] >>  8) & 0xFF;

        i_left >> i_right.mruListCount;
        for ( uint32_t i = 0; i < i_right.mruListCount; i++ )
            i_left >> i_right.mruList[i];

        i_left >> i_right.sigListCount;
        for ( uint32_t i = 0; i < i_right.sigListCount; i++ )
            i_left >> i_right.sigList[i];

        return i_left;
    };

};

struct CaptureDataClass
{
  uint32_t PfaCaptureDataSize;
  uint8_t CaptureData[CaptureDataSize]; // MAKMAK Can this be variable size?
};

#if defined(PRDF_HOSTBOOT_ERRL_PLUGIN) || defined(PRDF_FSP_ERRL_PLUGIN)
} // end namespace FSP/HOSTBOOT
#endif
} // end namespace PRDF

#endif // prdfPfa5Data_h
