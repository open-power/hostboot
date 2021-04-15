/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/rule/prdfRuleMetaData.C $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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

#include <prdfMfgThresholdMgr.H>

#ifndef __HOSTBOOT_MODULE
  #include <prdfSdcFileControl.H> //for SyncAnalysis
#endif
#include <prdfRuleMetaData.H>
#include <iipEregResolution.h> // for EregResolution
#include <iipServiceDataCollector.h> // for ServiceDataCollector
#include <prdfGroup.H>
#include <prdfRasServices.H>
#include <prdrLoadChip.H>
#include <prdrLoadChipCache.H>
#include <prdfScanFacility.H> // for ScanFacility
#include <iipResolutionFactory.h> // for ResolutionFactory
#include <prdfErrorSignature.H> // for ErrorSignature
#include <UtilHash.H> // for Util::hashString
#include <prdfPfa5Data.h>
#include <prdrCommon.H>

namespace PRDF
{

template <bool Type>
struct ResetAndMaskTransformer
    : public std::unary_function<Prdr::Register::ResetOrMaskStruct,
                                 ResetAndMaskErrorRegister::ResetRegisterStruct>
{
    ResetAndMaskTransformer( ScanFacility & i_scanFactory,size_t i_scomlen ,
                                TARGETING::TYPE i_type )
        :cv_scanFactory( i_scanFactory ),
        cv_scomlen( i_scomlen ),
        iv_chipType( i_type )
    { };

    virtual ~ResetAndMaskTransformer() {};

    virtual ResetAndMaskErrorRegister::ResetRegisterStruct
        operator()( const Prdr::Register::ResetOrMaskStruct & i )
    {
        /*
          These reset and mask registers, which are associated with a FIR, are
          created along with the FIR. They are needed to clear/mask FIR bits at
          the end of analysis. Let us call it scenario X.

          There are situations where we need a separate instance of an AND
          register. These are used in plugins to do some special analysis which
          is not possible through framework code. Let us call it scenario Y.

          Since, factory actually doesn't use operations (e.g. READ or WRITE)
          supported to determine whether a register instance is new or already
          available it shall return us the AND register instance created in
          scenario X.

          AND registers are write only. If we don't specify WRITE here, even in
          scenario Y, we shall get object created during scenario X, which may
          not be write-only.
        */
        ResetAndMaskErrorRegister::ResetRegisterStruct o;
        SCAN_COMM_REGISTER_CLASS::AccessLevel l_readRegAccess =
                                            SCAN_COMM_REGISTER_CLASS::ACCESS_WO;


        switch ( i.op )
        {
            case Prdr::OR:
                o.op = getStaticResetOperator<OrOperator<Type> >();
                break;

            case Prdr::AND:
                o.op = getStaticResetOperator<AndOperator<Type> >();
                break;

            case Prdr::XOR:
                o.op = getStaticResetOperator<XorOperator<Type> >();
                l_readRegAccess = SCAN_COMM_REGISTER_CLASS::ACCESS_RW;
                break;

            case Prdr::NOT:
                o.op = getStaticResetOperator<NotOperator<Type> >();
                break;

            default:
                o.op = nullptr;
                break;
        }

        o.read = & cv_scanFactory.GetScanCommRegister( i.addr_r, cv_scomlen,
                                        iv_chipType,
                                        l_readRegAccess );

        o.write = & cv_scanFactory.GetScanCommRegister( i.addr_w, cv_scomlen,
                                        iv_chipType,
                                        SCAN_COMM_REGISTER_CLASS::ACCESS_WO );

        return o;
    };

    private:
        ScanFacility & cv_scanFactory;
        size_t cv_scomlen;
        TARGETING::TYPE iv_chipType;
};


//------------------------------------------------------------------------------

 RuleMetaData::RuleMetaData( const char * i_fileName,
                             ScanFacility & i_scanFactory,
                             ResolutionFactory & i_reslFactory,
                             TARGETING::TYPE i_type,
                             errlHndl_t & o_errl )
    : cv_fileName( i_fileName ),cv_dumpType( 0 ),iv_sigOff(0)
{
    o_errl = this->loadRuleFile( i_scanFactory, i_reslFactory,i_type ) ;
}


//------------------------------------------------------------------------------
RuleMetaData::~RuleMetaData()
{
    uint32_t l_size = iv_groupList.size();
    for( uint32_t i = 0; i < l_size; i++ )
    {
        delete iv_groupList[i];
    }
    iv_groupList.clear();
    cv_hwCaptureGroups.clear();
    cv_hwCaptureReq.clear();
    cv_hwCaptureType.clear();
}
//------------------------------------------------------------------------------


errlHndl_t RuleMetaData::loadRuleFile( ScanFacility & i_scanFactory ,
                                    ResolutionFactory &i_reslFactory ,
                                    TARGETING::TYPE i_type  )
{
    RegMap_t l_regMap;
    Reset_t l_resetMap;
    ResetAndMaskPair l_currentResets;
    uint32_t l_vregMax = 0;
    ActionMap_t l_actionMap;
    GroupMap_t l_groupMap;
    uint32_t l_id = 1;
    errlHndl_t l_errl = nullptr ;
    SharedThreshold_t l_sharedThresholds;

    Prdr::Chip * l_chip;

    /* Initialize local data struct to pass to sub-functions */
    RuleFileData l_localData = { l_regMap, l_groupMap, l_actionMap,
                                 i_scanFactory, i_reslFactory,
                                 l_chip,
                                 l_resetMap, l_currentResets,
                                 l_sharedThresholds
                               };
    // Parse chip file.
    l_errl = Prdr::LoadChipCache::loadChip(cv_fileName, &l_chip);
    if( nullptr == l_errl )
    {

        // Get default dump type.
        cv_dumpType = l_chip->cv_dumpType;

        // Set signature offset for capture data output.
        iv_sigOff = l_chip->cv_signatureOffset;

        // create hardware regs.
        for (int i = 0; i < l_chip->cv_regCount; i++)
        {
            uint16_t hashId = l_chip->cv_registers[i].cv_name;
            SCAN_COMM_REGISTER_CLASS::AccessLevel l_regAccess;

            uint32_t l_accessLvls =
                        Prdr::PRDR_REGISTER_READ |
                        Prdr::PRDR_REGISTER_WRITE |
                        Prdr::PRDR_REGISTER_ACCESS_NIL;

            uint32_t l_accessType =
                        l_chip->cv_registers[i].cv_flags & l_accessLvls;

            switch( l_accessType )
            {
                case Prdr::PRDR_REGISTER_ACCESS_NIL:
                    l_regAccess = SCAN_COMM_REGISTER_CLASS::ACCESS_NONE;
                    break;
                case Prdr::PRDR_REGISTER_WRITE:
                    l_regAccess = SCAN_COMM_REGISTER_CLASS::ACCESS_WO;
                    break;
                case Prdr::PRDR_REGISTER_READ:
                    l_regAccess = SCAN_COMM_REGISTER_CLASS::ACCESS_RO;
                    break;
                default:
                    l_regAccess = SCAN_COMM_REGISTER_CLASS::ACCESS_RW;
            }
            //If more operations are incorporated in register, it can be
            //specified in same way as above.
            l_regMap[l_id] = cv_hwRegs[hashId]
                                = &i_scanFactory.GetScanCommRegister(
                                        l_chip->cv_registers[i].cv_scomAddr,
                                        l_chip->cv_registers[i].cv_scomLen,
                                        i_type, l_regAccess );
            l_regMap[l_id]->SetId(hashId);

            // Copy reset registers.
            std::transform( l_chip->cv_registers[i].cv_resets.begin(),
                            l_chip->cv_registers[i].cv_resets.end(),
                            std::back_inserter(l_resetMap[l_id].first),
                            ResetAndMaskTransformer<RESETOPERATOR_RESET>(
                                            i_scanFactory,
                                            l_chip->cv_registers[i].cv_scomLen,
                                            i_type )
                );

            // Copy mask registers.
            std::transform( l_chip->cv_registers[i].cv_masks.begin(),
                            l_chip->cv_registers[i].cv_masks.end(),
                            std::back_inserter(l_resetMap[l_id].second),
                            ResetAndMaskTransformer<RESETOPERATOR_MASK>(
                                            i_scanFactory,
                                            l_chip->cv_registers[i].cv_scomLen,
                                            i_type ) );
            l_id++;

        }

        // create capture struct for registers.
        for (int i = 0; i < l_chip->cv_regCount; i++)
        {
            uint16_t hashId = l_chip->cv_registers[i].cv_name;

            //This flag signifies that a mapping IS or ISN'T created between a
            //uint32_t mapping and a vector of SCAN_COMM_REGISTER_CLASS pointers
            //. If there is no mapping outside of the for loop then it is
            //because there is a capture type or requirement without a group
            //in the rule file.
            bool l_group_is_created = false;
            // Copy into capture groups.
            std::vector<Prdr::Register::CaptureInfoStruct>::const_iterator
            l_capturesEnd = l_chip->cv_registers[i].cv_captures.end();
            //For each capture in this register save a Group Type or
            //Requirement.
            for(std::vector<Prdr::Register::CaptureInfoStruct>::const_iterator
                    j = l_chip->cv_registers[i].cv_captures.begin();
                    j != l_capturesEnd;
                ++j)
            {
                if ('G' == (*j).op)
                {
                    cv_hwCaptureGroups[(*j).data[0]].push_back(
                                                        cv_hwRegs[hashId]);
                    //Added statement below this to indicate group was created.
                    l_group_is_created = true;
                }
                // This else if was added for a new capture "type" for registers
                // primary/secondary.
                // Cannot put the "type" in with the G group otherwise it will
                // show up as a i_group of 2 which is not called.
                else if('T' == (*j).op)
                {
                    cv_hwCaptureType[cv_hwRegs[hashId]] =
                                            CaptureType((RegType)(*j).data[0]);
                }
                else if ('f' == (*j).op)
                {
                    CaptureRequirement req;
                    req.cv_func = this->getExtensibleFunction(j->func);

                    cv_hwCaptureReq[cv_hwRegs[hashId]] = req;
                }
                else if ('P' == (*j).op)
                {
                    cv_hwCaptureNonzero[ cv_hwRegs[hashId] ] =
                                                cv_hwRegs[(*j).data[0]];
                }
                else // 'C'
                {
                    CaptureRequirement req;
                    req.cv_TargetType = (*j).data[0];
                    req.cv_TargetIndex = (*j).data[1];
                    req.cv_func = nullptr;

                    cv_hwCaptureReq[cv_hwRegs[hashId]] = req;
                }
            }
            if (!l_group_is_created)  // Add to default group if none there.
            {
                // Add to default if no group specified.
                cv_hwCaptureGroups[1].push_back(cv_hwRegs[hashId]);
            }
        }

        // Populate iv_ruleIndexes for each of the entries in l_chip->cv_rules.
        // Do not modify l_id otherwise it will mess up the indexes.
        uint32_t tmp_id = l_id;
        for ( uint32_t i = 0; i < l_chip->cv_ruleCount; i++ )
        {
            iv_ruleIndexes[tmp_id] = i;
            tmp_id++;
        }

        // Now, create virtual registers for each rule.
        for ( uint32_t i = 0; i < l_chip->cv_ruleCount; i++ )
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

        // iv_ruleIndexes is no longer needed. Empty it to save memory space.
        iv_ruleIndexes.clear();

        // initialize all the pointers for the groups, but don't construct their
        // data yet.
        Resolution & l_defaultResolution =
                        i_reslFactory.getCalloutGardResol( nullptr,
                                                            MRU_LOW, NO_GARD );
        for (int i = 0; i < l_chip->cv_groupCount; i++)
        {
            iv_groupList.push_back( new Group( l_defaultResolution ) );
            l_groupMap[l_id] = iv_groupList.back();
            l_id++;
        };

        for (int i = 0; i < l_chip->cv_actionCount; i++)
        {
            if (l_actionMap[i])
            {
                l_id++;
                continue;
            }

            // createActionClass will add to the actionMap.
            this->createActionClass(i, l_localData);
            //l_actionMap[l_id] = l_tmp;
            l_id++;
        }

        for (int i = 0; i < l_chip->cv_groupCount; i++)
        {
            this->createGroup( (Group *) l_groupMap[i+l_vregMax+1],
                                i,l_localData );
        }
        for ( int i = 0; i < Prdr::MAX_NUM_ATTN_TYPES; i++ )
            cv_groupAttn[i] = l_groupMap[l_chip->cv_groupAttn[i]];

    }
    else
    {
        PRDF_ERR(" LoadChipCache::loadChip( ) failed ");
    }

    return l_errl;

}

//------------------------------------------------------------------------------

int32_t RuleMetaData::Analyze( STEP_CODE_DATA_STRUCT & io_sc )
{
    int32_t l_rc = SUCCESS;
    ExtensibleChip * l_chipAnalyzed = ServiceDataCollector::getChipAnalyzed( );
    ServiceDataCollector & i_sdc = *(io_sc.service_data);
    // Set default dump flags.
    i_sdc.SetDump( (hwTableContent)cv_dumpType,
                    l_chipAnalyzed->getTrgt() );
    // Add statement below for Drop call.
    CaptureData & capture = io_sc.service_data->GetCaptureData();
    // Get capture data for this chip.  Allow override.
    ExtensibleChipFunction * l_ignoreCapture =
            getExtensibleFunction("PreventDefaultCapture", true);
    bool l_shouldPreventDefaultCapture = false;

    (*l_ignoreCapture)
        ( l_chipAnalyzed, PluginDef::bindParm<STEP_CODE_DATA_STRUCT&, bool&>
                 (io_sc, l_shouldPreventDefaultCapture));

    if (!l_shouldPreventDefaultCapture)
    {
        // Drop secondary capture from earlier chips.
        capture.Drop(SECONDARY);

        // Read capture data.
        this->CaptureErrorData( i_sdc.GetCaptureData() );
    }

    // Call the PreAnalysis plugin, if it exist. This should be done
    // before getting the error register just in case the secondary attention
    // type changes in the pre-analysis.
    ExtensibleChipFunction * l_preAnalysis =
                                    getExtensibleFunction("PreAnalysis", true);
    bool analyzed = false;
    (*l_preAnalysis)( l_chipAnalyzed,
            PluginDef::bindParm<STEP_CODE_DATA_STRUCT&,bool&>(io_sc,analyzed) );

    if ( !analyzed )
    {
        // Analyze the group.
        ErrorRegisterType * l_errReg = nullptr;
        switch ( io_sc.service_data->getSecondaryAttnType() )
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

            case UNIT_CS:
                l_errReg = cv_groupAttn[3];
                break;

            case HOST_ATTN:
                l_errReg = cv_groupAttn[4];
                break;
        }

        l_rc = ( nullptr != l_errReg ) ? l_errReg->Analyze(io_sc)
                                       : PRD_SCAN_COMM_REGISTER_ZERO;
    }

    // Don't do reset or mask on CS. @pw03
    if (CHECK_STOP != io_sc.service_data->getPrimaryAttnType()) //@pw04
    {
        #ifndef __HOSTBOOT_MODULE
        SyncAnalysis (i_sdc);  //mp01 Add call to Sync SDC
        #endif

        // We're not allowed to clear black-listed FIRs from the FSP
        #if defined(__HOSTBOOT_MODULE) || defined(ESW_SIM_COMPILE)

        // Call mask plugin.
        if (io_sc.service_data->IsAtThreshold())
        {
            ExtensibleChipFunction * l_mask =
                    getExtensibleFunction("MaskError", true);
            (*l_mask)( l_chipAnalyzed ,
                 PluginDef::bindParm<STEP_CODE_DATA_STRUCT&>(io_sc)
                ); //@pw01
        }

        // Call reset plugin.
        ExtensibleChipFunction * l_reset =
                getExtensibleFunction("ResetError", true);
        (*l_reset)( l_chipAnalyzed,
             PluginDef::bindParm<STEP_CODE_DATA_STRUCT&>(io_sc)
            ); //@pw01
        #endif
    }

    // Additional error isolation for HWPs, if needed.
    PlatServices::hwpErrorIsolation( l_chipAnalyzed, io_sc );

    // Call postanalysis plugin.
    // @jl02 JL Adding PostAnalysis plugin call.
    ExtensibleChipFunction * l_postanalysis =
            getExtensibleFunction("PostAnalysis", true);
    // @jl02 the true above means that a plugin may not exist for this call.
    // @jl02 JL Adding call for post analysis.
    (*l_postanalysis)( l_chipAnalyzed,
              PluginDef::bindParm<STEP_CODE_DATA_STRUCT&>(io_sc));


    return l_rc;
};


//------------------------------------------------------------------------------

int32_t RuleMetaData::CaptureErrorData( CaptureData & io_cap,
                                        int i_group )
{
    using namespace TARGETING;
    ExtensibleChip * l_pChipAnalyzed = ServiceDataCollector::getChipAnalyzed( );
    TargetHandle_t l_pTargetAnalyzed = l_pChipAnalyzed->getTrgt( );

    std::vector<SCAN_COMM_REGISTER_CLASS *>::const_iterator l_hwCaptureEnd =
                                            cv_hwCaptureGroups[i_group].end();

    for ( std::vector<SCAN_COMM_REGISTER_CLASS *>::const_iterator i =
            cv_hwCaptureGroups[i_group].begin();
         i != l_hwCaptureEnd;
         ++i )
    {
        // Check that requirements are satisfied.
        if ( CaptureRequirement() != cv_hwCaptureReq[*i])
        {
            CaptureRequirement req = cv_hwCaptureReq[*i];
            if (nullptr != req.cv_func)
            {
                bool l_cap = true;
                (*req.cv_func)
                    ( l_pChipAnalyzed , PluginDef::bindParm<bool &>(l_cap));

                if (!l_cap)
                    continue;
            }
            else
            {
                bool l_indexValid =false;
                TargetHandleList  l_ptargetHandleList  =
                    PlatServices::getConnectedChildren(
                                        l_pTargetAnalyzed,
                                        (TARGETING::TYPE) req.cv_TargetType );

                TargetHandleList::iterator itrTarget =
                                                l_ptargetHandleList.begin();

                for( ; itrTarget != l_ptargetHandleList.end();itrTarget++ )
                {
                    if ( req.cv_TargetIndex ==
                                PlatServices::getTargetPosition( *itrTarget) )
                    {
                        l_indexValid = true;
                        break;
                    }
                }
                if( false == l_indexValid )
                {
                    continue;
                }
            }
        }

        HwCaptureNonzero_t::const_iterator  l_primRegIter =
                                                cv_hwCaptureNonzero.find(*i);
        if(l_primRegIter != cv_hwCaptureNonzero.end())
        {
            SCAN_COMM_REGISTER_CLASS * l_primReg =
                                        (l_primRegIter)->second;

            if( l_primReg )
            {
                const BitString *l_bitStringPtr =
                                        l_primReg->GetBitString();
                if(l_bitStringPtr->isZero())
                {
                    //skip capture data if corresponding primary FIR is
                    //zero.
                    continue;
                }
            }
        }

        io_cap.Add( l_pTargetAnalyzed,
                    (*i)->GetId() ^ this->getSignatureOffset(),
                    *(*i),
                    CaptureData::BACK,
                    cv_hwCaptureType[*i].cv_regType );
    }

    // Call "PostCapture" plugin
    ExtensibleChipFunction * l_postCapture =
            getExtensibleFunction("PostCapture", true);

    (*l_postCapture)
        ( l_pChipAnalyzed,
         PluginDef::bindParm<CaptureData &, int>(io_cap, i_group)
        );

    return SUCCESS;
}


//------------------------------------------------------------------------------

SCAN_COMM_REGISTER_CLASS * RuleMetaData::createVirtualRegister(
                                                    Prdr::Expr * i_vReg,
                                                    RuleFileData & i_data )
{
    SCAN_COMM_REGISTER_CLASS * l_arg[5] = { nullptr };
    uint32_t l_tmp32 = 0;
    SCAN_COMM_REGISTER_CLASS * l_rc = nullptr;

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

            std::copy( i_data.cv_resets[i_vReg->cv_value[0].i].first.begin(),
                        i_data.cv_resets[i_vReg->cv_value[0].i].first.end(),
                        std::back_inserter(i_data.cv_currentResets.first) );

            std::copy( i_data.cv_resets[i_vReg->cv_value[0].i].second.begin(),
                        i_data.cv_resets[i_vReg->cv_value[0].i].second.end(),
                        std::back_inserter(i_data.cv_currentResets.second) );

            l_rc = i_data.cv_regMap[i_vReg->cv_value[0].i];

            break;

        case Prdr::REF_RULE:
        {
            uint32_t idx = i_vReg->cv_value[0].i;

            if ( nullptr == i_data.cv_regMap[idx] )
            {
                // This is a special case where a rule is referencing another
                // rule (i.e. the 'summary' construct). In this case, we will
                // want to preserve the current resets for this rule so that we
                // do not override them with the sub-rule.

                // Save the current resets for this rule.
                ResetAndMaskPair curResets = i_data.cv_currentResets;

                // Clear the current resets for the sub-rule (clean slate).
                i_data.cv_currentResets = ResetAndMaskPair();

                // Store the new virtual register in cv_regMap. Afterwards,
                // i_data.cv_currentResets will contain the current resets for
                // the sub-rule.
                i_data.cv_regMap[idx] =
                    createVirtualRegister(
                            &i_data.cv_loadChip->cv_rules[iv_ruleIndexes[idx]],
                            i_data );

                // Store the resets for the sub-rule in cv_resets.
                i_data.cv_resets[idx] = i_data.cv_currentResets;

                // Restore the saved current resets for this rule.
                i_data.cv_currentResets = curResets;
            }

            l_rc = i_data.cv_regMap[idx];

            break;
        }

        case Prdr::ATTNLINK:

            if ( nullptr != i_vReg->cv_value[0].p )
            {
                l_arg[0] = createVirtualRegister(i_vReg->cv_value[0].p, i_data);
            }

            if ( nullptr != i_vReg->cv_value[1].p )
            {
                l_arg[1] = createVirtualRegister(i_vReg->cv_value[1].p, i_data);

            }
            if ( nullptr != i_vReg->cv_value[2].p )
            {
                l_arg[2] = createVirtualRegister(i_vReg->cv_value[2].p, i_data);
            }

            if ( nullptr != i_vReg->cv_value[3].p )
            {
                l_arg[3] = createVirtualRegister(i_vReg->cv_value[3].p, i_data);
            }

            if ( nullptr != i_vReg->cv_value[4].p )
            {
                l_arg[4] = createVirtualRegister(i_vReg->cv_value[4].p, i_data);
            }

            // passing nullptr objects in *l_arg[x]
            l_rc = &i_data.cv_scanFactory.GetAttnTypeRegister(l_arg[0],
                                                              l_arg[1],
                                                              l_arg[2],
                                                              l_arg[3],
                                                              l_arg[4]);
            break;

        case Prdr::BIT_STR:
            {
                uint32_t l_size = i_vReg->cv_bitStrVect.size();
                BitStringBuffer l_bs(l_size * 64);

                for (uint32_t i = 0; i < l_size; i++)
                {
                    l_bs.setFieldJustify(32*(2*i)    , 32,
                           (i_vReg->cv_bitStrVect[i] >> 32) & 0xFFFFFFFF);
                    l_bs.setFieldJustify(32*((2*i)+1), 32,
                           (i_vReg->cv_bitStrVect[i] & 0xFFFFFFFF));
                }

                l_rc = &i_data.cv_scanFactory.GetConstantRegister(l_bs);
            }
            break;

        case Prdr::SUMMARY:

            l_arg[0] = createVirtualRegister(i_vReg->cv_value[1].p, i_data);

            l_tmp32 = i_vReg->cv_value[0].p->cv_value[0].i;

            l_rc =  &i_data.cv_scanFactory.GetSummaryRegister(*l_arg[0],
                l_tmp32);

            break;

    }

    return l_rc;
};

//------------------------------------------------------------------------------

Resolution * RuleMetaData::createActionClass( uint32_t i_action,
                                          RuleMetaData::RuleFileData & i_data )
{
    if ( nullptr != i_data.cv_actionMap[i_action] )
        return i_data.cv_actionMap[i_action];

    Resolution * l_tmpRes = nullptr, * l_retRes = nullptr;

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

    if (nullptr == l_retRes) // @pw05
    {
        class NullResolution : public Resolution
        {
            public:
                int32_t Resolve( STEP_CODE_DATA_STRUCT & io_data,
                                 bool i_default )
                            { return SUCCESS; };
        };

        static NullResolution l_nullRes;
        l_retRes = &l_nullRes;
    }

    i_data.cv_actionMap[i_action] = l_retRes;
    return l_retRes;
};

//------------------------------------------------------------------------------

Resolution * RuleMetaData::createResolution( Prdr::Expr * i_action,
                                         RuleMetaData::RuleFileData & i_data )
{
    Resolution * l_rc = nullptr;

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
            // cv_value[0,1]    error frequency and time in sec for field
            //                  threshold
            // cv_value[4]      true if mnfg threshols needs to be picked up
            //                  from  mnfg file, false otherwise
            // cv_value [2,3]:  error frequency and time in sec for mnfg
            //                  threshold if cv_value[4] is false otheriwse
            //                  cv_value[3] tells which threshold needs to pick
            //                  up from mnfg file
            // cv_value[5]      maskid id if shared threshold
            if (0 == i_action->cv_value[5].i)
            {
                if ( !PlatServices::mfgMode() )
                {
                    l_rc = &i_data.cv_reslFactory.GetThresholdSigResolution(
                                ThresholdResolution::ThresholdPolicy(
                                            (uint16_t)i_action->cv_value[0].i,
                                            i_action->cv_value[1].i ) );
                }
                else if(i_action->cv_value[4].i)
                {
                    l_rc = &i_data.cv_reslFactory.GetThresholdSigResolution(
                                *(MfgThresholdMgr::getInstance()->
                                     getThresholdP(i_action->cv_value[3].i) ) );
                }
                else
                {
                    l_rc = &i_data.cv_reslFactory.GetThresholdSigResolution(
                                ThresholdResolution::ThresholdPolicy(
                                            (uint16_t)i_action->cv_value[2].i,
                                             i_action->cv_value[3].i ) );
                }
            }
            else
            {
                if (nullptr == i_data.cv_sharedThresholds[i_action->cv_value[5].i])
                {
                    if ( !PlatServices::mfgMode() )
                    {
                        l_rc = &i_data.cv_reslFactory.GetThresholdResolution(
                                        i_action->cv_value[5].i,
                                        ThresholdResolution::ThresholdPolicy(
                                            (uint16_t)i_action->cv_value[0].i,
                                            i_action->cv_value[1].i ) );
                    }
                    else if(i_action->cv_value[4].i)
                    {
                        l_rc = &i_data.cv_reslFactory.
                                GetThresholdResolution(i_action->cv_value[5].i,
                                    *(MfgThresholdMgr::getInstance()->
                                        getThresholdP(i_action->cv_value[3].i)));
                    }
                    else
                    {
                        l_rc = &i_data.cv_reslFactory.
                                GetThresholdResolution( i_action->cv_value[5].i,
                                    ThresholdResolution::ThresholdPolicy(
                                            (uint16_t)i_action->cv_value[2].i,
                                             i_action->cv_value[3].i ) );
                    }
                    i_data.cv_sharedThresholds[i_action->cv_value[5].i] = l_rc;
                }
                else
                {
                    l_rc = i_data.cv_sharedThresholds[i_action->cv_value[5].i];
                }
             }
            break;


        case Prdr::ACT_DUMP:
            l_rc = &i_data.cv_reslFactory.GetDumpResolution(
                                (hwTableContent)    i_action->cv_value[0].i );
            break;

        case Prdr::ACT_ANALY: // ANALYZE
            l_rc = &i_data.cv_reslFactory.GetAnalyzeConnectedResolution(
                            (TARGETING::TYPE)        i_action->cv_value[0].i,
                                                     i_action->cv_value[1].i);
            break;

        case Prdr::ACT_CALL: // CALLOUT

            switch (i_action->cv_value[0].i)
            {
                case Prdr::CALLOUT_GARD_CHIP: // connected callout with gard
                    l_rc = &i_data.cv_reslFactory.getConnCalloutGardResol(
                                (TARGETING::TYPE) i_action->cv_value[2].i,
                                                  i_action->cv_value[3].i,
                                (PRDpriority)     i_action->cv_value[1].i,
                                ( nullptr == i_action->cv_value[4].p ? nullptr :
                                    ( this->createResolution(
                                        i_action->cv_value[4].p, i_data ) ) ),
                                TARGETING::TYPE_NA,
                                (GARD_POLICY)     i_action->cv_value[6].i );
                    break;

                // connected callout and gard with connection type
                case Prdr::CALLOUT_GARD_PEER:
                    l_rc = &i_data.cv_reslFactory.getConnCalloutGardResol(
                                (TARGETING::TYPE) i_action->cv_value[2].i,
                                                  i_action->cv_value[3].i,
                                (PRDpriority)     i_action->cv_value[1].i,
                                ( nullptr == i_action->cv_value[4].p ? nullptr :
                                    ( this->createResolution(
                                        i_action->cv_value[4].p, i_data ) ) ),
                                (TARGETING::TYPE) i_action->cv_value[5].i,
                                (GARD_POLICY)     i_action->cv_value[6].i );

                    break;

                case Prdr::CALLOUT_PROC: // Procedure callout
                    l_rc = &i_data.cv_reslFactory.getCalloutGardResol(
                                (SymbolicFru) i_action->cv_value[2].i,
                                (PRDpriority) i_action->cv_value[1].i,
                                (GARD_POLICY) i_action->cv_value[6].i );
                    break;

                case Prdr::CALLOUT_GARD_SELF: // self callout with gard option
                default:
                    l_rc = &i_data.cv_reslFactory.getCalloutGardResol(
                                nullptr,
                                (PRDpriority) i_action->cv_value[1].i,
                                (GARD_POLICY) i_action->cv_value[6].i );
                    break;

            };

            break;

        case Prdr::ACT_CAPT:  // Capture resolution.
            l_rc = &i_data.cv_reslFactory.GetCaptureResolution(
                                i_action->cv_value[0].i);
            break;
    };

    return l_rc;
};

//------------------------------------------------------------------------------

void RuleMetaData::createGroup(Group * i_group,
                               uint32_t i_groupId,
                               RuleMetaData::RuleFileData & i_data)
{
    // Internal class to collapse the bit string.
    class CreateBitString
    {
        public:
            static void execute(std::vector<uint8_t> & i_bits,
                    Prdr::Expr * i_expr)
            {
                if (nullptr == i_expr)
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

    std::vector<uint8_t> l_bits;
    CreateBitString::execute(l_bits,
            i_data.cv_loadChip->cv_groupCsRootCauseBits[i_groupId]);

    // Do CS_ROOT_CAUSE filter flags
    if ( i_data.cv_loadChip->cv_groupFlags[i_groupId] &
         Prdr::PRDR_GROUP_FILTER_CS_ROOT_CAUSE )
    {
        FilterClass * l_filter = new CsRootCauseFilter( l_bits );
        i_group->AddFilter( l_filter, true );
    }

    if ( i_data.cv_loadChip->cv_groupFlags[i_groupId] &
         Prdr::PRDR_GROUP_FILTER_CS_ROOT_CAUSE_NULL )
    {
        FilterClass * l_filter = new CsRootCauseFilter();
        i_group->AddFilter( l_filter, true );
    }

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

//------------------------------------------------------------------------------

ExtensibleChipFunction *RuleMetaData::getExtensibleFunction(
                                                    const char * i_func,
                                                    bool i_expectNull )
{
    #define PRDF_FUNC "[RuleMetaData::getExtensibleFunction] "
    ExtensibleFunctionType * plugin =
        getPluginGlobalMap().getPlugins(cv_fileName)[i_func];

    if (nullptr == plugin)
    {
        if (!i_expectNull)
        {
            errlHndl_t l_errl = nullptr;

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
                          ErrlString );

            PRDF_COMMIT_ERRL( l_errl, ERRL_ACTION_REPORT );

            // We can only reach here in two cases
            // 1. PRD patch is not properly applied ( prf files are changed
            //    but PRDF library is not updated )
            // 2. Obvious miss by developer.
            // In both these cases, we should catch these issues at very early
            // stage during system Initialize and this scenario should fail
            // basic validation.
            // So aborting system at this point.
            PRDF_ERR( PRDF_FUNC "nullptr Function for plugin:%s chip %s",
                      i_func, cv_fileName );

            PRDF_ASSERT( nullptr != plugin );
        }

        static Plugin<ExtensibleChip> l_nullPlugin(nullptr);
        plugin = &l_nullPlugin;

    }
    return ( ExtensibleChipFunction * ) plugin;
    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

SCAN_COMM_REGISTER_CLASS * RuleMetaData::getRegister( const char * i_reg,
                                                        bool i_expectNull,
                                                        ExtensibleChip* i_chip )
{
    uint16_t hashId = Util::hashString( i_reg );
    SCAN_COMM_REGISTER_CLASS * l_pRegister = cv_hwRegs[hashId];
    if ( nullptr == l_pRegister )
    {
       l_pRegister = getNullRegister( i_reg,i_expectNull );
    }
    else
    {
        /* l_register obtained from cv_hwRegs is a ScomRegister which does not
           have rule chip info built in.Analyze leg of code uses this register.
           Inorder to use this register for scom, target info is obtained from
           service data collector.This register does not suit us for read and
           write operation in plugin function.It is because in plugin function
           register read should not be concerned with finding the associated
           rule chip or target.Inorder to address this situation,we create a
           wrapper register.This register has rule chip info in addition to all
           the data of scomRegister.This object is created through factory and
           and destroyed at the end of analysis.
        */

        SCAN_COMM_REGISTER_CLASS * l_pReg = l_pRegister;
        ScanFacility      & l_scanFac = ScanFacility::Access();
        l_pRegister = & l_scanFac.GetPluginRegister( *l_pReg,*i_chip );

    }

    return l_pRegister;
}

//------------------------------------------------------------------------------

SCAN_COMM_REGISTER_CLASS * RuleMetaData::getNullRegister( const char * i_reg,
                                                            bool i_expectNull )
{
        static NullRegister l_nullRegister(1024);
        SCAN_COMM_REGISTER_CLASS * l_register = &l_nullRegister;

        if (!i_expectNull)
        {
            errlHndl_t l_errl = nullptr;
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
        return l_register;

}

//------------------------------------------------------------------------------


}//namespace PRDF ends
