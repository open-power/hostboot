/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/framework/rule/prdfRuleChip.H $             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2012              */
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

#ifndef __PRDFRULECHIP_H
#define __PRDFRULECHIP_H

#include <iipchip.h>
#include <prdfErrlSmartPtr.H>

#include <iipsdbug.h> // for ATTENTION_TYPE
#include <prdfExtensibleChip.H>
#include <prdfPluginDef.H>

#include <string.h>
#include <vector>
#include <map>
#include <iipResetErrorRegister.h>
#include "prdrCommon.H" //@jl02 Added this to get the constant value from the enum.
#include <iipCaptureData.h> // @jl04 Added this for the RegType used for register = "PRIMARY" or "SECONDARY"
//---------------------------------------
// Forward decls.
class SCAN_COMM_REGISTER_CLASS;
class ScanFacility;
class ResolutionFactory;
class STEP_CODE_DATA_STRUCT;
class CaptureData;
class ErrorRegisterType;
class Resolution;
namespace Prdr
{
    class PrdrChip;
    class PrdrExpr;
};
class PrdfGroup;
typedef std::pair<ResetAndMaskErrorRegister::ResetRegisterVector,
                       ResetAndMaskErrorRegister::ResetRegisterVector>
        PrdfResetAndMaskPair;

// x86 compile wants this here - not forward declaired dgilbert
class PrdfCaptureRequirement
{
    public:
        PrdfCaptureRequirement() :
            cv_TargetType(TARGETING::TYPE_NA), cv_TargetIndex(0), cv_func(NULL) { };

        uint32_t cv_TargetType;
        uint32_t cv_TargetIndex;
        PrdfExtensibleChipFunction * cv_func;

        inline bool operator!=(const PrdfCaptureRequirement & r)
        {
            return ( (cv_TargetType != r.cv_TargetType)   ||
                     (cv_TargetIndex != r.cv_TargetIndex) ||
                     (cv_func != r.cv_func) );
        };
};

//--------------------------------------
// @jl04 a Start.
// Adding capture requirement type for transporting data.
class PrdfCaptureType
{
    public:
        RegType cv_regType;
        // if (reg == 1) reg = PRIMARY;
        // if (reg == 2) reg = SECONDARY;
        PrdfCaptureType(RegType reg = PRIMARY):cv_regType(reg){};
};
// @jl04 a Stop.
//--------------------------------------


class PrdfRuleChip : public PrdfExtensibleChip
{
    public:

        typedef std::map<uint32_t, SCAN_COMM_REGISTER_CLASS *> RegMap_t;
        typedef std::map<uint32_t, ErrorRegisterType *>        GroupMap_t;
        typedef std::map<uint32_t, Resolution *>               ActionMap_t;
        typedef std::map<uint32_t, PrdfResetAndMaskPair>       Reset_t;
        typedef std::map<uint32_t, Resolution *>               SharedThreshold_t;

        struct RuleFileData
        {
            RegMap_t & cv_regMap;
            GroupMap_t & cv_groupMap;
            ActionMap_t & cv_actionMap;

            ScanFacility & cv_scanFactory;
            ResolutionFactory & cv_reslFactory;

            TARGETING::TargetHandle_t cv_chipHandle;
            Prdr::PrdrChip *& cv_loadChip;        // pw01

            Reset_t & cv_resets;
            PrdfResetAndMaskPair & cv_currentResets;

            SharedThreshold_t & cv_sharedThresholds;

        };

    public:
        // TODO : add parameter for parent domains, connected chip classes.
        PrdfRuleChip(const char * i_fileName,
                     TARGETING::TargetHandle_t   i_pTargetHandle,
                     ScanFacility & i_scanFactory,
                     ResolutionFactory & i_reslFactory
                    )
                : PrdfExtensibleChip(i_pTargetHandle),
                  cv_fileName(i_fileName),
                  cv_dumpType(0),  //@ecdf
                  cv_dataBundle(NULL)
            {
                this->loadRuleFile(i_scanFactory, i_reslFactory);
            };

        ~PrdfRuleChip();

        int32_t Analyze(STEP_CODE_DATA_STRUCT &, ATTENTION_TYPE);
        int32_t CaptureErrorData(CaptureData &, int i_group = 1);
        int32_t MaskError(uint32_t i) { return SUCCESS; };

        PrdfExtensibleChipFunction *
                getExtensibleFunction(const char *, bool = false);
        SCAN_COMM_REGISTER_CLASS * getRegister(const char *, bool = false);
        PrdfDataBundle *& getDataBundle() { return cv_dataBundle; };

        uint32_t getSignatureOffset() const { return iv_sigOff; };

    private:
        const char * cv_fileName;
        PrdfErrlSmartPtr cv_errl;

        uint32_t cv_dumpType;  //@ecdf

        uint32_t iv_sigOff;

        std::map<uint16_t, SCAN_COMM_REGISTER_CLASS *> cv_hwRegs;

        typedef std::map<uint32_t, std::vector<SCAN_COMM_REGISTER_CLASS *> > HwCaptureGroup_t;
        HwCaptureGroup_t cv_hwCaptureGroups;

        typedef std::map<SCAN_COMM_REGISTER_CLASS *, PrdfCaptureRequirement> HwCaptureReq_t;
        HwCaptureReq_t cv_hwCaptureReq;

        //Adding another std::map for passing some data to capture stuff.
        typedef std::map<SCAN_COMM_REGISTER_CLASS *, PrdfCaptureType> HwCaptureType_t;
        HwCaptureType_t cv_hwCaptureType;

        PrdfDataBundle * cv_dataBundle;
        ErrorRegisterType * cv_groupAttn[NUM_GROUP_ATTN]; // @jl02 JL Changed from 3 to 4 with this const type.

        void loadRuleFile(ScanFacility &,
                          ResolutionFactory &);

        SCAN_COMM_REGISTER_CLASS *
            createVirtualRegister(Prdr::PrdrExpr *,
                                  RuleFileData &);

        Resolution *
            createActionClass(uint32_t,
                              RuleFileData &);

        Resolution *
            createResolution(Prdr::PrdrExpr *,
                             RuleFileData &);

        void createGroup(PrdfGroup *,
                         uint32_t,
                         RuleFileData &);
};

#endif
