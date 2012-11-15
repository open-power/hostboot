/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/service/prdfPfa5Data.h $   */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2003,2012              */
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

#include <prdf_types.h>
#include <utilstream.H>

const uint32_t PFA5_Format = 0x50464135;
const uint32_t prdfMruListLIMIT = 8;
const uint32_t prdfHcdbListLIMIT = 8;
const uint32_t prdfSignatureListLIMIT = 8;

// Size of PRD Capture Data
#ifdef __HOSTBOOT_MODULE
// Total error log size for Hostboot error logs is 4K.
const uint32_t CaptureDataSize = 2048;
#else
const uint32_t CaptureDataSize = 4096*2;
#endif

enum prdfErrlVersion
{
    prdfErrlVer1    = 1,
    prdfErrlVer2    = 2,
};

enum prdfErrlSubsect
{
    prdfErrlSectPFA5_1   = 51,
    prdfErrlSectPFA5_2   = 52,
    prdfErrlCapData_1    = 1,
    prdfErrlCapData_2    = 2,
    prdfErrlAVPData_1    = 41,
    prdfErrlAVPData_2    = 42,
    prdfErrlString       = 10,
};

struct prdfMsDumpStruct
{
  int32_t DumpContent;
  PRDF::HUID DumpId;

  friend UtilStream& operator<<(UtilStream& i_left, prdfMsDumpStruct& i_right)
  {
      i_left << i_right.DumpContent << i_right.DumpId;

      return i_left;
  };

  friend UtilStream& operator>>(UtilStream& i_left, prdfMsDumpStruct& i_right)
  {
      i_left >> i_right.DumpContent >>i_right.DumpId;

      return i_left;
  };
};

struct prdfPfaCalloutListStruct
{
  uint32_t Callout;
  uint8_t  MRUtype;         // See enum PRDcallout::MruType
  uint8_t  MRUpriority;     // in srci/fsp/srci.H
                            // SRCI_PRIORITY_LOW   = 1
                            // SRCI_PRIORITY_MEDC  = 2
                            // SRCI_PRIORITY_MEDB  = 3
                            // SRCI_PRIORITY_MEDA  = 4
                            // SRCI_PRIORITY_MED   = 5
                            // SRCI_PRIORITY_HIGH  = 6
  uint8_t Reserved_3;
  uint8_t Reserved_4;

  friend UtilStream& operator<<(UtilStream& i_left,
                                prdfPfaCalloutListStruct& i_right)
  {
        i_left << i_right.Callout << i_right.MRUtype << i_right.MRUpriority
             << i_right.Reserved_3 << i_right.Reserved_4;

      return i_left;
  };

  friend UtilStream& operator>>(UtilStream& i_left,
                                prdfPfaCalloutListStruct& i_right)
  {
    i_left >> i_right.Callout >> i_right.MRUtype >> i_right.MRUpriority
             >> i_right.Reserved_3 >> i_right.Reserved_4;
      return i_left;
  };

};

//NOTE: The addition of the hcdb data requires additonal PFA data and
//      error log parsing. This is triggered / indicated by a new
//      PFA data bit,HCDB_SUPPORT. Support is for fips720 and beyond.
struct prdfPfaHcdbListStruct
{
    PRDF::HUID     hcdbId ;
    uint32_t compSubType;
    uint32_t compType;
    uint32_t hcdbReserved1;
    uint32_t hcdbReserved2;

    friend UtilStream& operator<<(UtilStream& i_left,
                                  prdfPfaHcdbListStruct& i_right)
    {
      i_left << i_right.hcdbId << i_right.compSubType << i_right.compType
          << i_right.hcdbReserved1 << i_right.hcdbReserved2;
        return i_left;
    };

    friend UtilStream& operator>>(UtilStream& i_left,
                                  prdfPfaHcdbListStruct& i_right)
    {
        i_left >> i_right.hcdbId >> i_right.compSubType >> i_right.compType
          >> i_right.hcdbReserved1 >> i_right.hcdbReserved2;
        return i_left;
    };
};

struct prdfPfaSignatureListStruct
{
    PRDF::HUID  chipId ;
    uint32_t signature;

    friend UtilStream& operator<<(UtilStream& i_left,
                                  prdfPfaSignatureListStruct& i_right)
    {
        i_left << i_right.chipId << i_right.signature;
        return i_left;
    };

    friend UtilStream& operator>>(UtilStream& i_left,
                                  prdfPfaSignatureListStruct& i_right)
    {
        i_left >> i_right.chipId >> i_right.signature;
        return i_left;
    };
};

/*********************************************************************
 * NOTE: the MsDumpLabel and its information must be first in this
 *       structure. Attn handling is dependent on this ordering.
 **********************************************************************/
struct prdfPfaData
{
  //0x0000
  uint32_t MsDumpLabel[2];
  prdfMsDumpStruct MsDumpInfo;

  uint32_t PFA_errlActions :16,// Error Log Actions Parm
  //                              ERRL_ACTION_NONE              = 0x0000
  //                              ERRL_ACTION_SA                = 0x8000
  //                              ERRL_ACTION_HIDDEN            = 0x4000
  //                              ERRL_ACTION_REPORT            = 0x2000
  //                              ERRL_ACTION_REPORT_HMC_ONLY   = 0x1000
  //                              ERRL_ACTION_CALL_HOME         = 0x0800
  //                              ERRL_ACTION_FNM_REQ           = 0x0400
  //                              ERRL_ACTION_HYP_GARD          = 0x0200
  //                              ERRL_ACTION_OS_RECONFIG       = 0x0100
           PFA_errlSeverity :8,// Error Log Severity Parm
  //                              See errlSeverity in errltypes.H
  //                              ERRL_SEV_INFORMATIONAL                = 0,
  //                              ERRL_SEV_RECOVERED                    = 0x10
  //                              ERRL_SEV_PREDICTIVE                   = 0x20
  //                              ERRL_SEV_PREDICTIVE_DEGRADED          = 0x21
  //                              ERRL_SEV_PREDICTIVE_CORRECTABLE       = 0x22
  //                              ERRL_SEV_PREDICTIVE_CORRECTABLE2      = 0x23
  //                              ERRL_SEV_PREDICTIVE_REDUNDANCY_LOST   = 0x24
  //                              ERRL_SEV_UNRECOVERABLE1               = 0x41
  //                              ERRL_SEV_UNRECOVERABLE2               = 0x44
  //                              ERRL_SEV_UNRECOVERABLE3               = 0x45
  //                              ERRL_SEV_UNRECOVERABLE4               = 0x48
  //                              ERRL_SEV_DIAGNOSTIC_ERROR1            = 0x60
  //                              ERRL_SEV_DIAGNOSTIC_ERROR2            = 0x61
  //                              ERRL_SEV_UNRECOVERABLE                = 0x70
  //                              ERRL_SEV_UNRECOVERABLE_REIPL          = 0x71
  //                              ERRL_SEV_RESERVED                     = 0xFF


           Reserved_2     :8;

  // PRD Service Data Collector Flags
  uint32_t MP_DUMP_REQ    :1,
           MP_RESET_REQ   :1,
           MP_FATAL       :1,
           REBOOT_MSG     :1,
           DUMP           :1,
           UERE           :1,
           SUE            :1,
           CRUMB          :1,
           AT_THRESHOLD   :1,
           DEGRADED       :1,
           SERVICE_CALL   :1,
           TRACKIT        :1,
           TERMINATE      :1,
           LOGIT          :1,
           MEMORY_STEERED :1,
           FLOODING       :1,
           THERMAL_EVENT  :1,
           UNIT_CHECKSTOP :1,
           USING_SAVED_SDC :1,
           LAST_CORE_TERMINATE :1,
           FORCE_LATENT_CS :1,
           DEFER_DECONFIG_MASTER :1,
           DEFER_DECONFIG  :1,
           CM_MODE         :1,
           TERMINATE_ON_CS :1,
           HCDB_SUPPORT    :1,
           SIGNATURE_SUPPORT :1,
           Reserved        :5;
  //                            1  TRUE
  //                            0  FALSE
  //
  //0x00xx
  //uint32_t ComponentDataLabel[2];// Label to show start of Component data.
  uint32_t ErrorCount      :16,
  //                            PRD Hits on this Error since IPL.
           Threshold       :16;
  //                            PRD Threshold for this error (MAKMAK how represent interval?)

  uint32_t PRDServiceActionCounter :8,
  //                                  PRD Service Action Counter
           ErrorType               :8,
  //                                  Error type gard was called with (see xspprdGardResolution.h)
           homGardState            :8,
  //                                  homGardEnum in src/hwsv/server/hwsvTypes.H
  //                                        HOM_NO_GARD = 0
  //                                        HOM_DECONFIG_GARD =1
  //                                        HOM_BYPASS_GARD = 2
           Reserved_5              :8;  //MP01 c - SystemType not needed

  uint32_t PRD_AttnTypes        :8,
  //                                  0x00 NULL
  //                                  0x01 CheckStop Attn
  //                                  0x02 Recoverable Attn
  //                                  0x03 Special Attn
           PRD_SecondAttnTypes  :8,
  //                                  0x00 NULL
  //                                  0x01 CheckStop Attn
  //                                  0x02 Recoverable Attn
  //                                  0x03 Special Attn

           reasonCode           :16;  //MP06 a

  uint32_t PfaCalloutCount;      // The number of MRUs below.
  prdfPfaCalloutListStruct PfaCalloutList[prdfMruListLIMIT]; //full list of MRUs and flags.
  uint32_t hcdbListCount;  //mp15 a
  prdfPfaHcdbListStruct PfaHcdbList[prdfHcdbListLIMIT];  //mp15 a
  uint32_t signatureCount;
  prdfPfaSignatureListStruct PfaSignatureList[prdfSignatureListLIMIT];
  //pw01
  friend UtilStream& operator<<(UtilStream& i_left, prdfPfaData& i_right)
  {
      i_left << i_right.MsDumpLabel[0] << i_right.MsDumpLabel[1]
             << i_right.MsDumpInfo
            <<
                    ( (i_right.PFA_errlActions << 16) |
                      (i_right.PFA_errlSeverity << 8) |
                      (i_right.Reserved_2)
                    )
            <<
                    ( (i_right.MP_DUMP_REQ << 31) |
                      (i_right.MP_RESET_REQ << 30) |
                      (i_right.MP_FATAL << 29) |
                      (i_right.REBOOT_MSG << 28) |
                      (i_right.DUMP << 27) |
                      (i_right.UERE << 26) |
                      (i_right.SUE << 25) |
                      (i_right.CRUMB << 24) |
                      (i_right.AT_THRESHOLD << 23) |
                      (i_right.DEGRADED << 22) |
                      (i_right.SERVICE_CALL << 21) |
                      (i_right.TRACKIT << 20) |
                      (i_right.TERMINATE << 19) |
                      (i_right.LOGIT << 18) |
                      (i_right.MEMORY_STEERED << 17) |
                      (i_right.FLOODING << 16) |
                      (i_right.THERMAL_EVENT << 15) |
                      (i_right.UNIT_CHECKSTOP << 14) |                //MP09c
                      (i_right.USING_SAVED_SDC << 13) |         //MP08
                      (i_right.LAST_CORE_TERMINATE << 12) |     //MP10
                      (i_right.FORCE_LATENT_CS << 11) |         //MP11
                      (i_right.DEFER_DECONFIG_MASTER << 10) |   //MP12
                      (i_right.DEFER_DECONFIG << 9) |           //MP12
                      (i_right.CM_MODE << 8) |                  //MP12
                      (i_right.TERMINATE_ON_CS << 7) |          //mp78
                      (i_right.HCDB_SUPPORT << 6) |             //mp15
                      (i_right.SIGNATURE_SUPPORT << 5) |
                      (i_right.Reserved)
                    )
            //<< i_right.ComponentDataLabel[0] << i_right.ComponentDataLabel[1]
            <<
                    ( (i_right.ErrorCount << 16) |
                      (i_right.Threshold)
                    )
            <<
                    ( (i_right.PRDServiceActionCounter << 24) |
                      (i_right.ErrorType << 16) |
                      (i_right.homGardState << 8) |
                      (i_right.Reserved_5)
                    )
            <<
                    ( (i_right.PRD_AttnTypes << 24) |
                      (i_right.PRD_SecondAttnTypes << 16) |
                      (i_right.reasonCode)
                    )
            << i_right.PfaCalloutCount;
      for (uint32_t i = 0; i < i_right.PfaCalloutCount; i++)
                i_left << i_right.PfaCalloutList[i];

      if ( 0 != i_right.HCDB_SUPPORT )                             //mp16 a
        {
            i_left << i_right.hcdbListCount;                       //mp15 a
            for (uint32_t i = 0; i < i_right.hcdbListCount; i++)   //mp15 a
                i_left << i_right.PfaHcdbList[i];                  //mp15 a
        }

      if ( 0 != i_right.SIGNATURE_SUPPORT )                         //mp16 a
        {
            i_left << i_right.signatureCount;
            for (uint32_t i = 0; i < i_right.signatureCount; i++)
                i_left << i_right.PfaSignatureList[i];
        }

      return i_left;
  };

  friend UtilStream& operator>>(UtilStream& i_left, prdfPfaData& i_right)
  {
      uint32_t l_tmp[6];
      i_left >> i_right.MsDumpLabel[0] >> i_right.MsDumpLabel[1]
             >> i_right.MsDumpInfo
             >> l_tmp[1]
             >> l_tmp[2]
             >> l_tmp[3]
             >> l_tmp[4]
             >> l_tmp[5];

      i_right.PFA_errlActions = (l_tmp[1] >> 16) & 0xFFFF;
      i_right.PFA_errlSeverity = (l_tmp[1] >> 8) & 0xFF;
      i_right.MP_DUMP_REQ         = (l_tmp[2] >> 31) & 0x01;
      i_right.MP_RESET_REQ         = (l_tmp[2] >> 30) & 0x01;
      i_right.MP_FATAL                 = (l_tmp[2] >> 29) & 0x01;
      i_right.REBOOT_MSG         = (l_tmp[2] >> 28) & 0x01;
      i_right.DUMP                 = (l_tmp[2] >> 27) & 0x01;
      i_right.UERE                 = (l_tmp[2] >> 26) & 0x01;
      i_right.SUE                 = (l_tmp[2] >> 25) & 0x01;
      i_right.CRUMB                 = (l_tmp[2] >> 24) & 0x01;
      i_right.AT_THRESHOLD        = (l_tmp[2] >> 23) & 0x01;
      i_right.DEGRADED                 = (l_tmp[2] >> 22) & 0x01;
      i_right.SERVICE_CALL         = (l_tmp[2] >> 21) & 0x01;
      i_right.TRACKIT                 = (l_tmp[2] >> 20) & 0x01;
      i_right.TERMINATE         = (l_tmp[2] >> 19) & 0x01;
      i_right.LOGIT                 = (l_tmp[2] >> 18) & 0x01;
      i_right.MEMORY_STEERED         = (l_tmp[2] >> 17) & 0x01;
      i_right.FLOODING                 = (l_tmp[2] >> 16) & 0x01;
      i_right.THERMAL_EVENT        = (l_tmp[2] >> 15) & 0x01; //pw02
      i_right.UNIT_CHECKSTOP        = (l_tmp[2] >> 14) & 0x01; //pw02   //MP09c
      i_right.USING_SAVED_SDC        = (l_tmp[2] >> 13) & 0x01; //MP08
      i_right.LAST_CORE_TERMINATE = (l_tmp[2] >> 12) & 0x01; //MP10
      i_right.FORCE_LATENT_CS   = (l_tmp[2] >> 11) & 0x01; //MP11
      i_right.DEFER_DECONFIG_MASTER  = (l_tmp[2] >> 10) & 0x01; //MP12
      i_right.DEFER_DECONFIG    = (l_tmp[2] >>  9) & 0x01;      //MP12
      i_right.CM_MODE           = (l_tmp[2] >>  8) & 0x01;      //MP12
      i_right.TERMINATE_ON_CS   = (l_tmp[2] >>  7) & 0x01;      //mp78
      i_right.HCDB_SUPPORT      = (l_tmp[2] >>  6) & 0x01;      //mp15
      i_right.SIGNATURE_SUPPORT = (l_tmp[2] >>  5) & 0x01;
      i_right.ErrorCount = (l_tmp[3] >> 16) & 0xFFFF;
      i_right.Threshold = (l_tmp[3]) & 0xFFFF;
      i_right.PRDServiceActionCounter = (l_tmp[4] >> 24) & 0xFF;
      i_right.ErrorType = (l_tmp[4] >> 16) & 0xFF;
      i_right.homGardState = (l_tmp[4] >> 8) & 0xFF;
      i_right.PRD_AttnTypes = (l_tmp[5] >> 24) & 0xFF;
      i_right.PRD_SecondAttnTypes = (l_tmp[5] >> 16) & 0xFF;
      i_right.reasonCode = (l_tmp[5]) & 0xFFFF;  //MP06 a

      i_left >>        i_right.PfaCalloutCount;                     //mp16 m
      for (uint32_t i = 0; i < i_right.PfaCalloutCount; i++)
          i_left >> i_right.PfaCalloutList[i];

      if ( 0 != i_right.HCDB_SUPPORT  )                          //mp16 a
      {
          i_left >> i_right.hcdbListCount;                        //mp15 a
          for (uint32_t i = 0; i < i_right.hcdbListCount; i++)    //mp15 a
              i_left >> i_right.PfaHcdbList[i];                   //mp15 a
      }

      if ( 0 != i_right.SIGNATURE_SUPPORT )                      //mp16 a
      {
          i_left >> i_right.signatureCount;
          for (uint32_t i = 0; i < i_right.signatureCount; i++)
              i_left >> i_right.PfaSignatureList[i];
      }

      return i_left;
  };
  //--pw01
};

struct prdfCaptureData
{
  uint32_t CaptureData_Label; // Label to show start of Capture data.
  uint32_t PfaCaptureDataSize;
  uint8_t CaptureData[CaptureDataSize]; // MAKMAK Can this be variable size?
  uint32_t EndLabel[2];// Label to show End of Capture Data
};

#endif        //end prdfPfa5Data.h
