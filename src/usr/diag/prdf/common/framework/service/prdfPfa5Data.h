/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/service/prdfPfa5Data.h $   */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2003,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

#if !defined(prdfPfa5Data_h)
#define prdfPfa5Data_h
/**
 @file prdfPfa4Data.h
 @brief Version 5 format of the Pfa Data
*/

#include <iipconst.h>
#include <utilstream.H>

namespace PRDF
{

const uint32_t PFA5_Format = 0x50464135;

const uint32_t MruListLIMIT  = 8;
const uint32_t HcdbListLIMIT = 8;
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
    ErrlSectPFA5_2   = 52,
    ErrlCapData_1    = 1,
    ErrlCapData_2    = 2,
    ErrlAVPData_1    = 41,
    ErrlAVPData_2    = 42,
    ErrlMruData_1    = 61, // This will only be used in non-attenion code when
                           // we want to add MRU.
    ErrlString       = 10,
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

    friend UtilStream& operator<<( UtilStream& i_left,
                                   PfaMruListStruct& i_right )
    {
        i_left << i_right.callout << i_right.type << i_right.priority;
        return i_left;
    };

    friend UtilStream& operator>>( UtilStream& i_left,
                                   PfaMruListStruct& i_right )
    {
        i_left >> i_right.callout >> i_right.type >> i_right.priority;
        return i_left;
    };
};

struct PfaHcdbListStruct
{
    HUID     hcdbId;
    uint32_t compSubType;
    uint32_t compType;

    friend UtilStream& operator<<( UtilStream& i_left,
                                   PfaHcdbListStruct& i_right )
    {
        i_left << i_right.hcdbId << i_right.compSubType << i_right.compType;
        return i_left;
    };

    friend UtilStream& operator>>( UtilStream& i_left,
                                   PfaHcdbListStruct& i_right )
    {
        i_left >> i_right.hcdbId >> i_right.compSubType >> i_right.compType;
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
             FLOODING             :1,
             THERMAL_EVENT        :1,
             UNIT_CHECKSTOP       :1,
             USING_SAVED_SDC      :1,
             LAST_CORE_TERMINATE  :1,
             DEFER_DECONFIG       :1,
             CM_MODE              :1,
             Reserved             :16;

    // Thresholding
    uint32_t errorCount :16, // Number of occurrences of this attention
             threshold  :16; // Theshold for this attention

    // Attention types and GARD state.
    uint32_t priAttnType    : 8, // primary attention type
             secAttnType    : 8, // secondary attention type
             prdGardErrType : 8, // See enum GardResolution::ErrorType
             hwasGardState  : 8; // See enum hwsvGardEnum (in hwsvTypes.H)

    uint32_t mruListCount;                  // Total number of MRUs.
    PfaMruListStruct mruList[MruListLIMIT]; // Full list of MRUs.

    uint32_t hcdbListCount;                    // Total number of MRUs.
    PfaHcdbListStruct hcdbList[HcdbListLIMIT]; // Full list of HCDB changes.

    uint32_t sigListCount;                  // Total number of multi-signatures.
    PfaSigListStruct sigList[SigListLIMIT]; // Full list of multi-signatures.

    /**
     * @brief Default constructor
     */
    PfaData()
    {
        memset( &mruList[0],  0x00, sizeof(PfaMruListStruct)  * MruListLIMIT  );
        memset( &hcdbList[0], 0x00, sizeof(PfaHcdbListStruct) * HcdbListLIMIT );
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
                    (i_right.FLOODING             << 22) |
                    (i_right.THERMAL_EVENT        << 21) |
                    (i_right.UNIT_CHECKSTOP       << 20) |
                    (i_right.USING_SAVED_SDC      << 19) |
                    (i_right.LAST_CORE_TERMINATE  << 18) |
                    (i_right.DEFER_DECONFIG       << 17) |
                    (i_right.CM_MODE              << 16) |
                    (i_right.Reserved                  ) );

        i_left << ( (i_right.errorCount << 16) |
                    (i_right.threshold       ) );

        i_left << ( (i_right.priAttnType    << 24) |
                    (i_right.secAttnType    << 16) |
                    (i_right.prdGardErrType <<  8) |
                    (i_right.hwasGardState       ) );

        i_left << i_right.mruListCount;
        for ( uint32_t i = 0; i < i_right.mruListCount; i++ )
            i_left << i_right.mruList[i];

        i_left << i_right.hcdbListCount;
        for ( uint32_t i = 0; i < i_right.hcdbListCount; i++ )
            i_left << i_right.hcdbList[i];

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
        i_right.FLOODING            = (l_tmp[2] >> 22) & 0x01;
        i_right.THERMAL_EVENT       = (l_tmp[2] >> 21) & 0x01;
        i_right.UNIT_CHECKSTOP      = (l_tmp[2] >> 20) & 0x01;
        i_right.USING_SAVED_SDC     = (l_tmp[2] >> 19) & 0x01;
        i_right.LAST_CORE_TERMINATE = (l_tmp[2] >> 18) & 0x01;
        i_right.DEFER_DECONFIG      = (l_tmp[2] >> 17) & 0x01;
        i_right.CM_MODE             = (l_tmp[2] >> 16) & 0x01;

        i_right.errorCount = (l_tmp[3] >> 16) & 0xFFFF;
        i_right.threshold  = (l_tmp[3]      ) & 0xFFFF;

        i_right.priAttnType    = (l_tmp[4] >> 24) & 0xFF;
        i_right.secAttnType    = (l_tmp[4] >> 16) & 0xFF;
        i_right.prdGardErrType = (l_tmp[4] >>  8) & 0xFF;
        i_right.hwasGardState  = (l_tmp[4]      ) & 0xFF;

        i_left >> i_right.mruListCount;
        for ( uint32_t i = 0; i < i_right.mruListCount; i++ )
            i_left >> i_right.mruList[i];

        i_left >> i_right.hcdbListCount;
        for ( uint32_t i = 0; i < i_right.hcdbListCount; i++ )
            i_left >> i_right.hcdbList[i];

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

} // end namespace PRDF

#endif // prdfPfa5Data_h
