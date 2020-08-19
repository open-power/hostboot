/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/rule/prdfRuleMetaData.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
 * @file    prdfRuleMetaData.H
 * @brief   Models the register, groups and action and analyzes the attention.
 *
 *          Each Rule file maps to one instance of RuleMetaData. This class uses
 *          the services of rule file parser classes. Once Rule file is parsed,
 *          it models all the physical registers and resolutions. It also models
 *          the logical operation needed to analyze the registers. It furthur
 *          goes to the extent of modelling the entire mechansim of attention
 *          analysis using an entity called Group.All RuleChips modelling target
 *          of type share same instance of RuleMetaData class. It is created
 *          while building PRD object model. Similar to RuleChips, instance of
 *          this class too are contained in System class.
 *
 */


#ifndef __PRDFRULECHIPDATA_H
#define __PRDFRULECHIPDATA_H


#include <iipchip.h>
#include <prdfErrlSmartPtr.H>
#include <string.h>
#include <vector>
#include <map>
#include "prdrCommon.H"
#include <iipCaptureData.h>
#include <prdfExtensibleChip.H>
#include <iipResetErrorRegister.h>

namespace Prdr
{

class Chip;
class Expr;

} // end namespace PRDR

namespace PRDF
{

class ScanFacility;
class ResolutionFactory;
class Resolution;
class Group;
class SCAN_COMM_REGISTER_CLASS;

typedef std::pair<ResetAndMaskErrorRegister::ResetRegisterVector,
                       ResetAndMaskErrorRegister::ResetRegisterVector>
        ResetAndMaskPair;

// x86 compile wants this here - not forward declaired dgilbert
class CaptureRequirement
{
    public:

        CaptureRequirement() :cv_TargetType(TARGETING::TYPE_NA),
            cv_TargetIndex(0), cv_func(nullptr)
        { };

        uint32_t cv_TargetType;
        uint32_t cv_TargetIndex;
        ExtensibleChipFunction * cv_func;
        /**
         * @brief     defines != operator for register capture requirement
         */

        inline bool operator != ( const CaptureRequirement & r )
        {
            return ( ( cv_TargetType != r.cv_TargetType )   ||
                     ( cv_TargetIndex != r.cv_TargetIndex ) ||
                     ( cv_func != r.cv_func ) );
        };
};


//--------------------------------------

class CaptureType
{
    public:
        RegType cv_regType;
        /**
         * @brief     constructor
         */
        CaptureType( RegType reg = PRIMARY ):cv_regType( reg )
        { };
};

//--------------------------------------

class RuleMetaData
{
    public:
        typedef std::map<uint32_t, SCAN_COMM_REGISTER_CLASS *> RegMap_t;
        typedef std::map<uint32_t, ErrorRegisterType *>        GroupMap_t;
        typedef std::map<uint32_t, Resolution *>               ActionMap_t;
        typedef std::map<uint32_t, ResetAndMaskPair>           Reset_t;
        typedef std::map<uint32_t, Resolution *>              SharedThreshold_t;

        struct RuleFileData
        {
            RegMap_t & cv_regMap;
            GroupMap_t & cv_groupMap;
            ActionMap_t & cv_actionMap;

            ScanFacility & cv_scanFactory;
            ResolutionFactory & cv_reslFactory;

            Prdr::Chip *& cv_loadChip;

            Reset_t & cv_resets;
            ResetAndMaskPair & cv_currentResets;

            SharedThreshold_t & cv_sharedThresholds;

        };

        /**
         * @brief       constructor
         * @param[in]   i_fileName      name of Rule file
         * @param[in]   i_scanFactory   reference to factory class which
         *                              creates register instances
         * @param[in]   i_targetType    target type associated with Rulechip
         * @param[o]    o_errl          reference to error log handle
         */
        RuleMetaData( const char * i_fileName,
                    ScanFacility & i_scanFactory,
                    ResolutionFactory & i_reslFactory,
                    TARGETING::TYPE i_targetType,
                    errlHndl_t & o_errl );


        /**
         * @brief     destructor
         */

        virtual ~RuleMetaData();

        /**
         * @brief       Analyzes the attention by reading and analyzing group of
         *              registers.
         * @pre         Must set the secondary attention type in the SDC before
         *              calling this function.
         * @param[io]   io_serviceData   reference to STEP_CODE_DATA_STRUCT
         * @return      SUCCESS|FAIL
         */

        int32_t Analyze( STEP_CODE_DATA_STRUCT & io_serviceData );

        /**
         * @brief       Captures group of register associated with RuleChip
         * @param[io]   io_capture   reference to CaptureData instance.
         * @param[in]   i_group      capture group number
         * @return      SUCCESS
         */

        int32_t CaptureErrorData( CaptureData & io_capture , int i_group = 1 );
        /**
         * @brief       Masks error
         * @param[in]   i
         * @return      SUCCESS
         */
        int32_t MaskError( uint32_t i ) { return SUCCESS; };
        /**
         * @brief       Returns signature offset associated with registes of a
         *              RuleChip.
         * @return      Error signature offset
         */
         uint32_t getSignatureOffset() const { return iv_sigOff; };
        /**
         * @brief       returns pointer to plugin function
         * @param[in]   i_func          name of the plugin function
         * @param[in]   i_expectNull    plugin function availability status
         * @return      pointer to ExtensibleChipFunction
         */

         ExtensibleChipFunction * getExtensibleFunction( const char * i_func,
                                                    bool i_expectNull = false );
        /**
         * @brief       Returns pointer to physical register.
         * @param[in]   i_reg           name of the register
         * @param[in]   i_expectNull    register non availability expectation
         * @param[in]   i_chip          pointer to RuleChip associated
         * @return      pointer to SCAN_COMM_REGISTER_CLASS
         */
         SCAN_COMM_REGISTER_CLASS * getRegister( const char * i_reg,
                                                 bool i_expectNull,
                                                 ExtensibleChip* i_chip );
        /**
         * @brief       Returns Null register instance
         * @param[in]   i_reg           name of the register
         * @param[in]   i_expectNull    register non availability expectation
         * @return      pointer to SCAN_COMM_REGISTER_CLASS
         */

         SCAN_COMM_REGISTER_CLASS * getNullRegister( const char * i_reg,
                                                    bool i_expectNull );

         ErrorRegisterType * cv_groupAttn[Prdr::MAX_NUM_ATTN_TYPES];

    private:  // Data

        const char * cv_fileName; //name of rule file associated with the class
        uint32_t cv_dumpType; // dump type
        uint32_t iv_sigOff;   // signature offset for  registers
        std::map<uint16_t, SCAN_COMM_REGISTER_CLASS *> cv_hwRegs;

        typedef std::vector<SCAN_COMM_REGISTER_CLASS *> scomRegisterList_t ;

        typedef std::map< uint32_t,scomRegisterList_t > HwCaptureGroup_t;
        HwCaptureGroup_t cv_hwCaptureGroups; //capture group associated
        typedef std::map<SCAN_COMM_REGISTER_CLASS *,
                                            CaptureRequirement> HwCaptureReq_t;
        HwCaptureReq_t cv_hwCaptureReq;

        //Adding another std::map for passing some data to capture stuff.
        typedef std::map<SCAN_COMM_REGISTER_CLASS *,
                                                CaptureType> HwCaptureType_t;
        HwCaptureType_t cv_hwCaptureType; // capture type
        std::vector <ErrorRegisterType *> iv_groupList;

        // A std::map to capture secondary register and its corresponding
        // Primary register.
        typedef std::map<SCAN_COMM_REGISTER_CLASS *, SCAN_COMM_REGISTER_CLASS *>
                                                            HwCaptureNonzero_t;
        HwCaptureNonzero_t cv_hwCaptureNonzero;

        // This is temporary container used during loadRuleFile() to solve an
        // indexing issue with cv_loadChip->cv_rules, which is an array indexed
        // 0 to the size of the array. The problem is that when the data is
        // needed in createVirtualRegister(), the index stored in the input
        // Expr is the index for RuleFileData::cv_regMap. So we will need to
        // map the cv_regMap indexes to the cv_rules indexes.
        std::map<uint32_t, uint32_t> iv_ruleIndexes;

    private: //operations

        /**
         * @brief       Returns Null register instance
         * @param[in]   i_scanFacility        reference to register factory
         * @param[in]   i_resolutionFactory   refence  to resolution factory
         * @param[in]   i_type                target type associated with
         *                                    RuleChip
         * @return      error log handle
         */

        errlHndl_t loadRuleFile( ScanFacility & i_scanFacility,
                         ResolutionFactory & i_resolutionFactory ,
                         TARGETING::TYPE i_type );
        /**
         * @brief       Models register operation described in rule file.
         * @param[in]   i_expr    expression for logical operation
         * @param[in]   i_data    Reference to RuleFileData instance.
         * @return      pointer to SCAN_COMM_REGISTER_CLASS
         */

        SCAN_COMM_REGISTER_CLASS * createVirtualRegister( Prdr::Expr * i_expr,
                                                        RuleFileData & i_data );
        /**
         * @brief       Models actions described in rule file.
         * @param[in]   i_action  number corresponding to action in rule file.
         * @param[in]   i_data    Reference to RuleFileData instance.
         * @return      pointer to Resolution
         */
        Resolution * createActionClass( uint32_t i_action ,
                                        RuleFileData& i_data );

        /**
         * @brief       Models action described in rule file.
         * @param[in]   i_expr    expression for logical operation.
         * @param[in]   i_data    Reference to RuleFileData instance.
         * @return      pointer to Resolution
         */

        Resolution * createResolution( Prdr::Expr * i_expr,
                                         RuleFileData & i_data );

        /**
         * @brief       Models group described in rule file.
         * @param[in]   i_group   register capture group id
         * @param[in]   i_data    Reference to RuleFileData instance.
         */

        void createGroup( Group * i_group , uint32_t , RuleFileData & i_data );

};



}//namespace PRDF ends

#endif
