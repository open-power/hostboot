/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/rule/prdfRuleChip.C $      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2013              */
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

#ifndef __HOSTBOOT_MODULE
  #include <utilreg.H> // for UtilReg
  #include <prdfMfgThresholdMgr.H>
  #include <prdfSdcFileControl.H> //for SyncAnalysis
#endif

#include <prdfGlobal.H> // for SystemPtr.
#include <prdfErrlUtil.H>

#include <prdfRuleChip.H>
#include <prdrLoadChip.H>
#include <prdrLoadChipCache.H>
#include <prdfOperatorRegister.H>
#include <prdfGroup.H>
#include <prdfPluginMap.H>
#include <prdrCommon.H> // for enums.

#include <prdfScanFacility.H> // for ScanFacility
#include <iipResolutionFactory.h> // for ResolutionFactory
#include <iipCaptureData.h> // for CaptureData
#include <iipServiceDataCollector.h> // for ServiceDataCollector
#include <prdfErrorSignature.H> // for ErrorSignature
#include <iipResolution.h> // for Resolutions
#include <iipEregResolution.h> // for EregResolution
#include <xspprdDumpResolution.h> // for DumpResolution
#include <xspprdTryResolution.h> // for TryResolution
#include <prdfPluginCallResolution.H> // for PluginCallResolution
#include <prdfAnalyzeConnected.H> // for prdfAnalyzeConnected
#include <iipSystem.h> // for System
#include <xspprdFlagResolution.h>
#include <prdfPfa5Data.h> // for errl user data flags.

#include <prdfPlatServices.H> // for getConnected

#include <errlentry.H> // for errl.
#include <utilfile.H>  // for UtilFile
#include <UtilHash.H> // for Util::hashString

#include <prdfResetOperators.H>
#include <algorithm>
#include <prdf_ras_services.H>

namespace PRDF
{

template <bool Type>
struct ResetAndMaskTransformer
    : public std::unary_function<Prdr::Register::ResetOrMaskStruct,
                                 ResetAndMaskErrorRegister::ResetRegisterStruct>
{
    ResetAndMaskTransformer( ScanFacility & i_scanFactory,
                             size_t i_scomlen ,
                             TARGETING::TYPE i_type ):
                            cv_scanFactory( i_scanFactory ),
                            cv_scomlen( i_scomlen ),
                            iv_chipType( i_type )
        {};

    virtual ~ResetAndMaskTransformer() {};  // zs01

    virtual ResetAndMaskErrorRegister::ResetRegisterStruct
        operator()(const Prdr::Register::ResetOrMaskStruct & i)
    {
        ResetAndMaskErrorRegister::ResetRegisterStruct o;
        o.read = & cv_scanFactory.GetScanCommRegister( i.addr_r ,
                                                      cv_scomlen,iv_chipType );
        o.write = & cv_scanFactory.GetScanCommRegister( i.addr_w ,
                                                       cv_scomlen ,iv_chipType );


        switch (i.op)
        {
            case Prdr::OR:
                o.op = getStaticResetOperator<OrOperator<Type> >();
                break;

            case Prdr::AND:
                o.op = getStaticResetOperator<AndOperator<Type> >();
                break;

            case Prdr::XOR:
                o.op = getStaticResetOperator<XorOperator<Type> >();
                break;

            case Prdr::NOT:
                o.op = getStaticResetOperator<NotOperator<Type> >();
                break;

            default:
                o.op = NULL; // TODO: ERROR!  Assert...
                break;
        }

        return o;
    };

    private:
        ScanFacility & cv_scanFactory;
        size_t cv_scomlen;
        TARGETING::TYPE iv_chipType;
};


void RuleChip::loadRuleFile(ScanFacility & i_scanFactory,
                                ResolutionFactory & i_reslFactory)
{
    RegMap_t l_regMap;
    Reset_t l_resetMap;
    ResetAndMaskPair l_currentResets;
    uint32_t l_regMax = 0;
    uint32_t l_vregMax = 0;
    GroupMap_t l_groupMap;
    uint32_t l_groupMax = 0;
    ActionMap_t l_actionMap;
    uint32_t l_actionMax = 0;
    uint32_t l_id = 1;

    SharedThreshold_t l_sharedThresholds;

    Prdr::Chip * l_chip;

    /* Initialize local data struct to pass to sub-functions */
    RuleFileData l_localData = { l_regMap, l_groupMap, l_actionMap,
                                 i_scanFactory, i_reslFactory,
                                 this->GetChipHandle(), l_chip,
                                 l_resetMap, l_currentResets,
                                 l_sharedThresholds
                               };

    // Parse chip file.
    cv_errl = Prdr::LoadChipCache::loadChip(cv_fileName, &l_chip);
    if (NULL == l_chip)
    {
        // TODO: Do we need to percAbend?  We were unable to succesfully
        // load our chip objects.
        return;
    }

    // Get default dump type.
    cv_dumpType = l_chip->cv_dumpType;

    //getting target type before creating hardware register
    TARGETING::TYPE l_type = PlatServices::getTargetType( GetChipHandle() ) ;
    // Set signature offset for capture data output.
    iv_sigOff = l_chip->cv_signatureOffset;

    // create hardware regs.
    for (int i = 0; i < l_chip->cv_regCount; i++)
    {
        uint16_t hashId = l_chip->cv_registers[i].cv_name;

        l_regMap[l_id] = cv_hwRegs[hashId]
                       = &i_scanFactory.GetScanCommRegister(
                                        l_chip->cv_registers[i].cv_scomAddr,
                                        l_chip->cv_registers[i].cv_scomLen,
                                        l_type );
        l_regMap[l_id]->SetId(hashId);

        // Copy reset registers.
        std::transform
                (l_chip->cv_registers[i].cv_resets.begin(),
                 l_chip->cv_registers[i].cv_resets.end(),
                 std::back_inserter(l_resetMap[l_id].first),
                 ResetAndMaskTransformer<RESETOPERATOR_RESET>(
                        i_scanFactory,
                        l_chip->cv_registers[i].cv_scomLen,
                        l_type )
                );

        // Copy mask registers.
        std::transform
                (l_chip->cv_registers[i].cv_masks.begin(),
                 l_chip->cv_registers[i].cv_masks.end(),
                 std::back_inserter(l_resetMap[l_id].second),
                 ResetAndMaskTransformer<RESETOPERATOR_MASK>(
                        i_scanFactory,
                        l_chip->cv_registers[i].cv_scomLen,
                        l_type )
                );

        //This flag signifies that a mapping IS or ISN'T created between a
        //uint32_t mapping and a vector of SCAN_COMM_REGISTER_CLASS pointers.
        //If there is no mapping outside of the for loop then it is because
        //there is a capture type or requirement without a group statement in
        //the rule file.
        bool l_group_is_created = false;
        // Copy into capture groups.
        std::vector<Prdr::Register::CaptureInfoStruct>::const_iterator
            l_capturesEnd = l_chip->cv_registers[i].cv_captures.end();
        //For each capture in this register save a Group Type or Requirement.
        for(std::vector<Prdr::Register::CaptureInfoStruct>::const_iterator
                j = l_chip->cv_registers[i].cv_captures.begin();
            j != l_capturesEnd;
            ++j)
        {
            if ('G' == (*j).op)
            {
                cv_hwCaptureGroups[(*j).data[0]].push_back(l_regMap[l_id]);
                l_group_is_created = true;   //@jl06 Added this to indicate group was created.
            }
            // @jl04 a  Start.
            // This else if was added for a new capture "type" for registers
            // primary/secondary.
            // Cannot put the "type" in with the G group otherwise it will show
            // up as a i_group of 2 which is not called.
            else if('T' == (*j).op)
            {
                //@jl06. d Deleted temporary declaration of CaptureType in
                //         favor of an anonymous declaration.  Calls ctor twice.
                cv_hwCaptureType[l_regMap[l_id]] =
                 CaptureType((RegType)(*j).data[0]); //@jl06 c.
            }
            // @jl04 a Stop.
            else if ('f' == (*j).op)
            {
                CaptureRequirement req;
                req.cv_func = this->getExtensibleFunction(j->func);

                cv_hwCaptureReq[l_regMap[l_id]] = req;
            }
            else // 'C'
            {
                CaptureRequirement req;
                req.cv_TargetType = (*j).data[0];
                req.cv_TargetIndex = (*j).data[1];
                req.cv_func = NULL;

                cv_hwCaptureReq[l_regMap[l_id]] = req;
            }
        }
        if (!l_group_is_created)  // @jl06 c Add to default group if none there.
        {
            // Add to default if no group specified.
            cv_hwCaptureGroups[1].push_back(l_regMap[l_id]);
        }

        l_regMax = l_id++;

    }

    for (int i = 0; i < l_chip->cv_ruleCount; i++)
    {
        if (l_regMap[l_id]) // check if it already exists.
        {
            l_vregMax = l_id++;
            continue;
        }

        l_currentResets = ResetAndMaskPair();

        SCAN_COMM_REGISTER_CLASS * l_tmp =
            this->createVirtualRegister(&l_chip->cv_rules[i], l_localData);

        l_regMap[l_id] = l_tmp;
        l_resetMap[l_id] = l_currentResets;
        l_vregMax = l_id++;
    };

    // initialize all the pointers for the groups, but don't construct their
    // data yet.
    Resolution & l_defaultResolution =
                    i_reslFactory.GetCalloutResolution( this->GetChipHandle(),
                                                        MRU_MED );
    for (int i = 0; i < l_chip->cv_groupCount; i++)
    {
        Group * l_tmp = new Group(l_defaultResolution);
        l_groupMap[l_id] = l_tmp;
        l_groupMax = l_id++;
    };

    for (int i = 0; i < l_chip->cv_actionCount; i++)
    {
        if (l_actionMap[i])
        {
            l_actionMax = l_id++;
            continue;
        }

        // createActionClass will add to the actionMap.
        this->createActionClass(i, l_localData);
        //l_actionMap[l_id] = l_tmp;
        l_actionMax = l_id++;
    }

    for (int i = 0; i < l_chip->cv_groupCount; i++)
    {
        this->createGroup((Group *) l_groupMap[i+l_vregMax+1],
                          i,
                          l_localData);
    }
    for (int i = 0; i < Prdr::NUM_GROUP_ATTN; i++)
        cv_groupAttn[i] = l_groupMap[l_chip->cv_groupAttn[i]];

    // Call initialize plugin.
    ExtensibleChipFunction * l_init = getExtensibleFunction("Initialize", true);
    if (NULL != l_init)
    {
        (*l_init)
            (this,
             PluginDef::bindParm<void*>(NULL)
            );
    }

    return;
};

RuleChip::~RuleChip()
{
    if (NULL != cv_dataBundle)
    {
        delete cv_dataBundle;
    }
};


int32_t RuleChip::Analyze(STEP_CODE_DATA_STRUCT & i_serviceData,
                              ATTENTION_TYPE i_attnType)
{
    //this pointer is retained in stack just for the scope of this function
    PRDF_DEFINE_CHIP_SCOPE( this );

    ServiceDataCollector & i_sdc = *(i_serviceData.service_data);
    ErrorSignature & l_errSig = *(i_sdc.GetErrorSignature());
    CaptureData & capture = i_serviceData.service_data->GetCaptureData();  // @jl04 a Add this for Drop call.

    // Set current ATTN type to input value.
    // If we don't do this, then the AttnRegisters don't work.
    i_sdc.SetCauseAttentionType(i_attnType); // @pw02 @pw04

    int32_t l_rc = SUCCESS;

    // Set Signature Chip Id.
    l_errSig.setChipId( GetId() );

    // Set default dump flags.  //@ecdf
    //FIXME: take out hwTableContent for now for Hostboot
    #ifdef __HOSTBOOT_MODULE
    i_sdc.SetDump(/*(hwTableContent)cv_dumpType,*/ GetChipHandle());
    #else
    i_sdc.SetDump((hwTableContent)cv_dumpType, GetChipHandle());
    #endif

    // Get capture data for this chip.  Allow override.
    ExtensibleChipFunction * l_ignoreCapture =
            getExtensibleFunction("PreventDefaultCapture", true);
    bool l_shouldPreventDefaultCapture = false;

    (*l_ignoreCapture)
        (this, PluginDef::bindParm<STEP_CODE_DATA_STRUCT&, bool&>
                 (i_serviceData, l_shouldPreventDefaultCapture));

    if (!l_shouldPreventDefaultCapture)
    {
        // Drop secondary capture from earlier chips.
        capture.Drop(SECONDARY);

        // Read capture data.
        this->CaptureErrorData(i_sdc.GetCaptureData());
    }

    // Analyze group.
    ErrorRegisterType * l_errReg = NULL;
    switch (i_attnType)
    {
        case CHECK_STOP:
            l_errReg = cv_groupAttn[0];
            break;

        case RECOVERABLE:
            l_errReg = cv_groupAttn[1];
            break;

        case SPECIAL:
            l_errReg = cv_groupAttn[2];
            break;

        case UNIT_CS:                    // @jl02 JL Added this code to support the new Unit Check Stop.
            l_errReg = cv_groupAttn[3];  // @jl02 JL I don't know if this is the correct cv_groupAttn to add here or if it's needed.
            break;

    }
    if (NULL != l_errReg)
    {  //mp02 a Start
        //Call any pre analysis functions
        ExtensibleChipFunction * l_preAnalysis =
                getExtensibleFunction("PreAnalysis", true);
        bool analyzed = false;
        (*l_preAnalysis)(this,
                 PluginDef::bindParm<STEP_CODE_DATA_STRUCT&,bool&>
                 (i_serviceData,analyzed));
        if ( !analyzed)
            l_rc = l_errReg->Analyze(i_serviceData);
    }    //mp02 a Stop
       // mp02d l_rc = l_errReg->Analyze(i_serviceData);
    else                                      //@jl07
       l_rc = PRD_SCAN_COMM_REGISTER_ZERO;    //@jl07

    // Don't do reset or mask on CS. @pw03
    if (CHECK_STOP != i_serviceData.service_data->GetAttentionType()) //@pw04
    {
        #ifndef __HOSTBOOT_MODULE
        SyncAnalysis (i_sdc);  //mp01 Add call to Sync SDC
        #endif
        // Call mask plugin.
        if (i_serviceData.service_data->IsAtThreshold())
        {
            ExtensibleChipFunction * l_mask =
                    getExtensibleFunction("MaskError", true);
            (*l_mask)(this,
                 PluginDef::bindParm<STEP_CODE_DATA_STRUCT&>(i_serviceData)
                ); //@pw01
        }

        // Call reset plugin.
        ExtensibleChipFunction * l_reset =
                getExtensibleFunction("ResetError", true);
        (*l_reset)(this,
             PluginDef::bindParm<STEP_CODE_DATA_STRUCT&>(i_serviceData)
            ); //@pw01
    }

    // Call postanalysis plugin.
    // @jl02 JL Adding PostAnalysis plugin call.
    ExtensibleChipFunction * l_postanalysis =
            getExtensibleFunction("PostAnalysis", true);
    // @jl02 the true above means that a plugin may not exist for this call.
    // @jl02 JL Adding call for post analysis.
    (*l_postanalysis)(this,
              PluginDef::bindParm<STEP_CODE_DATA_STRUCT&>(i_serviceData));

    return l_rc;
};

int32_t RuleChip::CaptureErrorData(CaptureData & i_cap, int i_group)
{
    using namespace TARGETING;
    //this pointer is retained in stack just for the scope of this function
    PRDF_DEFINE_CHIP_SCOPE( this );

    std::vector<SCAN_COMM_REGISTER_CLASS *>::const_iterator l_hwCaptureEnd =
        cv_hwCaptureGroups[i_group].end();
    for (std::vector<SCAN_COMM_REGISTER_CLASS *>::const_iterator i =
            cv_hwCaptureGroups[i_group].begin();
         i != l_hwCaptureEnd;
         ++i)
    {
        // Check that requirements are satisfied.
        if (CaptureRequirement() != cv_hwCaptureReq[*i])
        {
            CaptureRequirement req = cv_hwCaptureReq[*i];
            if (NULL != req.cv_func)
            {
                bool l_cap = true;
                (*req.cv_func)(this, PluginDef::bindParm<bool &>(l_cap));
                if (!l_cap)
                    continue;
            }
            else
            {
                bool l_indexValid =false;
                TargetHandleList  l_ptargetHandleList  =
                    PlatServices::getConnected(this->GetChipHandle(),
                                              (TARGETING::TYPE) req.cv_TargetType);
                TargetHandleList ::iterator itrTarget =l_ptargetHandleList.begin();
                for( ; itrTarget != l_ptargetHandleList.end();itrTarget++ )
                {
                    if (req.cv_TargetIndex == PlatServices::getTargetPosition(*itrTarget))
                    {
                        l_indexValid = true;
                        break;
                    }
                }
                if(false == l_indexValid)
                {
                    continue;
                }
            }
        }

        i_cap.Add(this->GetChipHandle(),
                  (*i)->GetId() ^ this->getSignatureOffset(),
                  *(*i),
                  CaptureData::BACK,                 //@jl04 c change this because of proto.
                  cv_hwCaptureType[*i].cv_regType);  //@jl04 c Changed this function call to add a param.
    }

    // Call "PostCapture" plugin
    ExtensibleChipFunction * l_postCapture =
            getExtensibleFunction("PostCapture", true);

    (*l_postCapture)
        (this,
         PluginDef::bindParm<CaptureData &, int>(i_cap, i_group)
        );

    return SUCCESS;
}

SCAN_COMM_REGISTER_CLASS *
RuleChip::createVirtualRegister(
        Prdr::Expr * i_vReg,
        RuleFileData & i_data
    )
{
    SCAN_COMM_REGISTER_CLASS * l_arg[4] = { NULL };
    uint32_t l_tmp32 = 0;
    SCAN_COMM_REGISTER_CLASS * l_rc = NULL;

    switch(i_vReg->cv_op)
    {
        case Prdr::NOT:
            l_arg[0] = createVirtualRegister(i_vReg->cv_value[0].p, i_data);
            l_rc = &i_data.cv_scanFactory.GetNotRegister(*l_arg[0]);
            break;

        case Prdr::LSHIFT:
        case Prdr::RSHIFT:
            l_arg[0] = createVirtualRegister(i_vReg->cv_value[0].p, i_data);
            l_tmp32 = i_vReg->cv_value[1].p->cv_value[0].i;
            l_rc = (Prdr::LSHIFT == i_vReg->cv_op
                    ?
                        &i_data.cv_scanFactory.GetLeftShiftRegister(*l_arg[0],
                                                                    l_tmp32)
                    :
                        &i_data.cv_scanFactory.GetRightShiftRegister(*l_arg[0],
                                                                     l_tmp32)
                   );
            break;

        case Prdr::OR:
        case Prdr::AND:
            l_arg[0] = createVirtualRegister(i_vReg->cv_value[0].p, i_data);
            l_arg[1] = createVirtualRegister(i_vReg->cv_value[1].p, i_data);
            l_rc = (Prdr::OR == i_vReg->cv_op
                    ?
                        &i_data.cv_scanFactory.GetOrRegister(*l_arg[0],
                                                             *l_arg[1])
                    :
                        &i_data.cv_scanFactory.GetAndRegister(*l_arg[0],
                                                              *l_arg[1])
                    );
            break;


        case Prdr::REF_REG:
            std::copy(i_data.cv_resets[i_vReg->cv_value[0].i].first.begin(),
                      i_data.cv_resets[i_vReg->cv_value[0].i].first.end(),
                      std::back_inserter(i_data.cv_currentResets.first));
            std::copy(i_data.cv_resets[i_vReg->cv_value[0].i].second.begin(),
                      i_data.cv_resets[i_vReg->cv_value[0].i].second.end(),
                      std::back_inserter(i_data.cv_currentResets.second));
            l_rc = i_data.cv_regMap[i_vReg->cv_value[0].i];
            break;

        case Prdr::REF_RULE:
            if (NULL == i_data.cv_regMap[i_vReg->cv_value[0].i])
                i_data.cv_regMap[i_vReg->cv_value[0].i] =
                            createVirtualRegister(
                                    &i_data.cv_loadChip->
                                            cv_rules[i_vReg->cv_value[0].i],
                                    i_data);
            l_rc = i_data.cv_regMap[i_vReg->cv_value[0].i];
            break;

        case Prdr::ATTNLINK:
            if (NULL != i_vReg->cv_value[0].p)
                l_arg[0] = createVirtualRegister(i_vReg->cv_value[0].p, i_data);

            if (NULL != i_vReg->cv_value[1].p)
                l_arg[1] = createVirtualRegister(i_vReg->cv_value[1].p, i_data);

            if (NULL != i_vReg->cv_value[2].p)
                l_arg[2] = createVirtualRegister(i_vReg->cv_value[2].p, i_data);

            if (NULL != i_vReg->cv_value[3].p)
                l_arg[3] = createVirtualRegister(i_vReg->cv_value[3].p, i_data);

            l_rc = &i_data.cv_scanFactory.GetAttnTypeRegister(*l_arg[0],  /*passing null object*/
                                                              *l_arg[1],  /*passing null object*/
                                                              *l_arg[2],  /*passing null object*/
                                                              *l_arg[3]); /*passing null object*/
            break;

        case Prdr::BIT_STR:
            {
                uint32_t l_size = i_vReg->cv_bitStrVect.size();
                BIT_STRING_BUFFER_CLASS l_bs(l_size * 64);

                for (uint32_t i = 0; i < l_size; i++)
                {
                    l_bs.SetFieldJustify(32*(2*i)    , 32,
                           (i_vReg->cv_bitStrVect[i] >> 32) & 0xFFFFFFFF);
                    l_bs.SetFieldJustify(32*((2*i)+1), 32,
                           (i_vReg->cv_bitStrVect[i] & 0xFFFFFFFF));
                }

                l_rc = &i_data.cv_scanFactory.GetConstantRegister(l_bs);
            }
            break;

    }

    return l_rc;
};

Resolution * RuleChip::createActionClass( uint32_t i_action,
                                          RuleChip::RuleFileData & i_data )
{
    if (NULL != i_data.cv_actionMap[i_action])
        return i_data.cv_actionMap[i_action];

    Resolution * l_tmpRes = NULL, * l_retRes = NULL;
    for (int i = 0; i < i_data.cv_loadChip->cv_actionSize[i_action]; i++)
    {
        l_tmpRes = this->createResolution(
                                &(i_data.cv_loadChip->cv_actions[i_action][i]),
                                i_data);
        if (0 == i)
        {
            l_retRes = l_tmpRes;
        }
        else
        {
            l_retRes = &i_data.cv_reslFactory.
                            LinkResolutions(*l_retRes, *l_tmpRes);
        }
    }

    if (NULL == l_retRes) // @pw05
    {
        class NullResolution : public Resolution
        {
            public:
                int32_t Resolve(STEP_CODE_DATA_STRUCT & data)
                            { return SUCCESS; };
        };

        static NullResolution l_nullRes;
        l_retRes = &l_nullRes;
    }

    i_data.cv_actionMap[i_action] = l_retRes;
    return l_retRes;
};

Resolution * RuleChip::createResolution( Prdr::Expr * i_action,
                                         RuleChip::RuleFileData & i_data )
{
    Resolution * l_rc = NULL;

    switch (i_action->cv_op)
    {
        case Prdr::REF_ACT:
            l_rc = this->createActionClass(i_action->cv_value[0].i -
                                            (i_data.cv_loadChip->cv_regCount +
                                             i_data.cv_loadChip->cv_ruleCount +
                                             i_data.cv_loadChip->cv_groupCount +
                                             1),
                                           i_data);
            break;

        case Prdr::REF_GRP:
            l_rc = &i_data.cv_reslFactory.GetEregResolution(
                            *i_data.cv_groupMap[i_action->cv_value[0].i]);
            break;

        case Prdr::ACT_TRY: // TRY
            l_rc = &i_data.cv_reslFactory.GetTryResolution(
                    *(this->createResolution(i_action->cv_value[0].p,
                                             i_data)),
                    *(this->createResolution(i_action->cv_value[1].p,
                                             i_data))
                    );
            break;

        case Prdr::ACT_FUNC: // FUNCCALL
            l_rc = &i_data.cv_reslFactory.GetPluginCallResolution(
                        this->getExtensibleFunction(i_action->cv_actFunc)
                    );
            break;

        case Prdr::ACT_FLAG: // FLAG
            l_rc = &i_data.cv_reslFactory.GetFlagResolution(
                        (ServiceDataCollector::Flag) i_action->cv_value[0].i);
            break;

        case Prdr::ACT_THRES: // Threshold
            // The values which different parameter will have
            // cv_value[0,1] error frequency and time in sec for field threshold
            //cv_value[4] true if mnfg threshols needs to be picked up from mnfg file, false otherwise
            // cv_value [2,3]: error frequency and time in sec for mnfg threshold if cv_value[4] is false
            // otheiwse cv_value[3] tells which threshold needs to pick up from mnfg file
            // cv_value[5] maski id if shared threshold
            if (0 == i_action->cv_value[5].i)
            {
                if ( !PlatServices::mfgMode() )
                {
                    l_rc = &i_data.cv_reslFactory.GetThresholdSigResolution(
                                                     ThresholdResolution::ThresholdPolicy(
                                                            (uint16_t)i_action->cv_value[0].i, i_action->cv_value[1].i));
                }
                else if(i_action->cv_value[4].i)
                {
                    // FIXME : need to uncomment MfgThresholdMgr after we figure it out
                    #ifndef __HOSTBOOT_MODULE
                    l_rc = &i_data.cv_reslFactory.GetThresholdSigResolution(
                                    *(MfgThresholdMgr::getInstance()->
                                            getThresholdP(i_action->cv_value[3].i)));
                    #endif
                }
                else
                {
                    l_rc = &i_data.cv_reslFactory.GetThresholdSigResolution(
                                                     ThresholdResolution::ThresholdPolicy(
                                                            (uint16_t)i_action->cv_value[2].i, i_action->cv_value[3].i));
                }
            }
            else
                if (NULL == i_data.cv_sharedThresholds[i_action->cv_value[5].i])
                {
                    if ( !PlatServices::mfgMode() )
                    {
                        l_rc = &i_data.cv_reslFactory.
                                   GetThresholdResolution(i_action->cv_value[5].i,
                                      ThresholdResolution::ThresholdPolicy((uint16_t)i_action->cv_value[0].i, i_action->cv_value[1].i));
                    }
                    else if(i_action->cv_value[4].i)
                    {
                        // FIXME : need to uncomment MfgThresholdMgr after we figure it out
                        #ifndef __HOSTBOOT_MODULE
                        l_rc = &i_data.cv_reslFactory.
                                GetThresholdResolution(i_action->cv_value[5].i,
                                    *(MfgThresholdMgr::getInstance()->
                                        getThresholdP(i_action->cv_value[3].i)));
                        #endif
                    }
                    else
                    {
                        l_rc = &i_data.cv_reslFactory.
                                GetThresholdResolution(i_action->cv_value[5].i,
                                  ThresholdResolution::ThresholdPolicy((uint16_t)i_action->cv_value[2].i, i_action->cv_value[3].i));
                    }
                    i_data.cv_sharedThresholds[i_action->cv_value[5].i] = l_rc;
                }
                else
                {
                    l_rc = i_data.cv_sharedThresholds[i_action->cv_value[5].i];
                }
            break;


        case Prdr::ACT_DUMP: // DUMP : TODO: Allow dump connected.
            #ifdef __HOSTBOOT_MODULE
            //FIXME: comment out hwtablecontent for hostboot
            l_rc = &i_data.cv_reslFactory.GetDumpResolution(
                                /*(hwTableContent)    i_action->cv_value[0].i,*/
                                );
            #else
            l_rc = &i_data.cv_reslFactory.GetDumpResolution(
                                (hwTableContent)    i_action->cv_value[0].i );
            #endif
            break;

        case Prdr::ACT_GARD: // GARD
            l_rc = &i_data.cv_reslFactory.GetGardResolution(
                    (GardResolution::ErrorType) i_action->cv_value[0].i);
            break;

        case Prdr::ACT_ANALY: // ANALYZE
            l_rc = &i_data.cv_reslFactory.GetAnalyzeConnectedResolution(
                                    (TARGETING::TYPE) i_action->cv_value[0].i,
                                    i_action->cv_value[1].i );
            break;

        case Prdr::ACT_CALL: // CALLOUT
        {
            switch ((char)i_action->cv_value[0].i)
            {
                case 'c': // connected chip.
                    l_rc = &i_data.cv_reslFactory.GetConnectedCalloutResolution(
                                ( TARGETING::TYPE )     i_action->cv_value[2].i,
                                                        i_action->cv_value[3].i,
                                ( CalloutPriorityEnum ) i_action->cv_value[1].i,
                                ( NULL == i_action->cv_value[4].p ? NULL :
                                        ( this->createResolution(
                                          i_action->cv_value[4].p, i_data ) ) )

                            );
                    break;

                case 'p': // Procedure.
                    l_rc = &i_data.cv_reslFactory.GetCalloutResolution(
                                (SymbolicFru)         i_action->cv_value[2].i,
                                (CalloutPriorityEnum) i_action->cv_value[1].i);
                    break;

                case 's': // SELF
                default:
                    /*Passing NULL as target in this function creates a dummy
                     * place holder object of PRDcallout for  TARGET TYPE
                     * callout.Since resolution object is no longer tied to a
                     * specific target,any RulChip which needs target type
                     * callout with a given priority can use this resolution.
                     * .Since the same function shall be used for creating
                     * TYPE_MEMMRU and TYPE_SYMFRU callout ,it is not possible
                     * to remove this input parameter.So,by passing NULL as
                     * target other two callout remain  unaffected and we are
                     * still able to create place holder resolution object for
                     * target type callout.
                     */
                    l_rc = &i_data.cv_reslFactory.GetCalloutResolution(
                                NULL ,
                                (CalloutPriorityEnum) i_action->cv_value[1].i );
                    break;

            };
        }
            break;

        case Prdr::ACT_CAPT:  // Capture resolution.
            l_rc = &i_data.cv_reslFactory.GetCaptureResolution(
                                i_action->cv_value[0].i);
            break;
    };

    return l_rc;
};

void RuleChip::createGroup(Group * i_group,
                               uint32_t i_groupId,
                               RuleChip::RuleFileData & i_data)
{
    // Internal class to collapse the bit string.
    class CreateBitString
    {
        public:
            static void execute(std::vector<uint8_t> & i_bits,
                    Prdr::Expr * i_expr)
            {
                if (NULL == i_expr)
                    return;
                if (i_expr->cv_op == Prdr::INT_SHORT)
                {
                    i_bits.push_back(i_expr->cv_value[0].i);
                }
                else // must be an | or & operator.
                {
                    // Expand bit string from left side.
                    CreateBitString::execute(i_bits, i_expr->cv_value[0].p);
                    // Expand bit string from right side.
                    CreateBitString::execute(i_bits, i_expr->cv_value[1].p);
                }
            };
    };

    for (int i = 0; i < i_data.cv_loadChip->cv_groupSize[i_groupId]; i++)
    {
        std::vector<uint8_t> l_bits; // Vector to hold bit string.

        // TODO : handle & transformations.

        // Get expression for group's line.
        Prdr::Expr * l_expr = &i_data.cv_loadChip->cv_groups[i_groupId][i];

        // Execute internal (recursive) class to generate bit string.
        CreateBitString::execute(l_bits, l_expr->cv_value[1].p);

        // Add expression to group.
        i_group->Add(i_data.cv_regMap[l_expr->cv_value[0].i],
                     &(*l_bits.begin()),
                     l_bits.size(),
                     *(this->createResolution(l_expr->cv_value[2].p, i_data)),
                     i_data.cv_resets[l_expr->cv_value[0].i],
                     (i_data.cv_regMap[l_expr->cv_value[0].i]->GetId()
                            + i_data.cv_loadChip->cv_signatureOffset) & 0xffff,
                     Prdr::AND == l_expr->cv_value[1].p->cv_op
                    );

    } // end for.

    // Do flags. ---

    // Do Priority filter flag.
    if (i_data.cv_loadChip->cv_groupFlags[i_groupId] &
            Prdr::PRDR_GROUP_FILTER_PRIORITY)
    {
        std::vector<uint8_t> l_bits;
        CreateBitString::execute(l_bits,
                i_data.cv_loadChip->cv_groupPriorityBits[i_groupId]);

        FilterClass * l_filter = new PrioritySingleBitFilter(l_bits);
        i_group->AddFilter(l_filter);
    }

    // Do single bit filter flag.
    if (i_data.cv_loadChip->cv_groupFlags[i_groupId] &
            Prdr::PRDR_GROUP_FILTER_SINGLE_BIT)
    {
        FilterClass * l_filter = new SingleBitFilter();
        i_group->AddFilter(l_filter);
    }
}

ExtensibleChipFunction *
    RuleChip::getExtensibleFunction(const char * i_func, bool i_expectNull)
{
    //this pointer is retained in stack just for the scope of this function
    PRDF_DEFINE_CHIP_SCOPE( this );

    ExtensibleFunctionType * plugin =
        getPluginGlobalMap().getPlugins(cv_fileName)[i_func];
    if (NULL == plugin)
    {
        static Plugin<ExtensibleChip> l_nullPlugin(NULL);
        plugin = &l_nullPlugin;

        if (!i_expectNull)
        {
            errlHndl_t l_errl = NULL;

            PRDF_CREATE_ERRL(l_errl,
                             ERRL_SEV_UNRECOVERABLE,
                             ERRL_ETYPE_NOT_APPLICABLE,
                             SRCI_ERR_INFO,
                             SRCI_NO_ATTR,
                             PRDF_RULECHIP,
                             LIC_REFCODE,
                             PRDF_CODE_FAIL,
                             __LINE__,
                             0, 0, 0);

            PRDF_ADD_FFDC(l_errl,
                          cv_fileName,
                          strlen(cv_fileName),
                          ErrlVer1,
                          ErrlString);

            PRDF_ADD_FFDC(l_errl,
                          i_func,
                          strlen(i_func),
                          ErrlVer1,
                          ErrlString);

            PRDF_COMMIT_ERRL(l_errl, ERRL_ACTION_REPORT);
        }

    }
    return (ExtensibleChipFunction *) plugin;

}

SCAN_COMM_REGISTER_CLASS * RuleChip::getRegister(const char * i_reg,
                                                     bool i_expectNull)
{
    //this pointer is retained in stack just for the scope of this function
    PRDF_DEFINE_CHIP_SCOPE( this );
    uint16_t hashId = Util::hashString( i_reg );

    SCAN_COMM_REGISTER_CLASS * l_register = cv_hwRegs[hashId];

    if (NULL == l_register)
    {
        static NullRegister l_nullRegister(1024);
        l_register = &l_nullRegister;

        if (!i_expectNull)
        {
            errlHndl_t l_errl = NULL;
            PRDF_CREATE_ERRL(l_errl,
                             ERRL_SEV_UNRECOVERABLE,
                             ERRL_ETYPE_NOT_APPLICABLE,
                             SRCI_ERR_INFO,
                             SRCI_NO_ATTR,
                             PRDF_RULECHIP,
                             LIC_REFCODE,
                             PRDF_CODE_FAIL,
                             __LINE__,
                             1, 0, 0);

            PRDF_ADD_FFDC(l_errl,
                          cv_fileName,
                          strlen(cv_fileName),
                          ErrlVer1,
                          ErrlString);


            PRDF_ADD_FFDC(l_errl,
                          i_reg,
                          strlen(i_reg),
                          ErrlVer1,
                          ErrlString);

            PRDF_COMMIT_ERRL(l_errl, ERRL_ACTION_REPORT);
        }

    }
    else
    {   /* l_register obtained from cv_hwRegs is a ScomRegister which does not
           have rule chip info built in.Analyze leg of code uses this register.
           Inorder to use this register for scom, target info is obtained from
           service data collector.This register does not suit us for read and
           write operation in plugin function.It is because in plugin function
           register read should not be concerend with finding the associated
           rule chip or target.Inorder to address this situation,we create a
           wrapper register.This register has rule chip info in addition to all
           the data of scomRegister.This object is created through factory and
           and destroyed at the end of analysis.
        */
        SCAN_COMM_REGISTER_CLASS * l_pReg = l_register;
        ScanFacility      & l_scanFac = ScanFacility::Access();
        l_register = & l_scanFac.GetPluginRegister(*l_pReg,*this);

    }
    return l_register;
}

} // end namespace PRDF

