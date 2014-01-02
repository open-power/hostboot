/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/rule/prdfRuleChip.H $      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2014              */
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

/**
 * @file    prdfRuleChip.H
 * @brief   Models a physical target say a Proc or Ex
 *
 *          Each instance of RuleChip is associated with a particular target.As
 *          an example, all the procs in the system are modeled by PRD with a
 *          unique instance of RuleChip object.Design of class is based on
 *          following two facts about all the RuleChips modelling target of same
 *          type
 *              - contain an identical set of registers and resolutions
 *              - share a common mechansim to analyze attention
 *          Based on above two facts, all RuleChips modelling target of same
 *          type, share a common instance of RuleMetaData. RuleMetaData models
 *          all the regisers and resolutions associated with a RuleChip of
 *          particular type.
 *          Sharing of RuleMetaData instance reduces the memory usage
 *          and is key to address the scaling issue.
 */
#ifndef __PRDFRULECHIP_H
#define __PRDFRULECHIP_H

#include <iipchip.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginDef.H>
#include <string.h>
#include <vector>
#include <map>
#include <iipResetErrorRegister.h>
#include "prdrCommon.H"
#include <iipCaptureData.h>
#include <prdfRuleMetaData.H>

namespace PRDF
{

class RuleChip : public ExtensibleChip
{

    public:

       /*Note:
       At the beginning of all the public function of this class,'this' pointer
       should be pushed to stack maintained in service data collector.Also, at
       the end of same function,it should be popped.It is accomplished by just
       instantiating ChipScopeLock at the beginning of the function.This is
       encapsulated by PRDF_LOCK_CHIP_SCOPE */

        // TODO : add parameter for parent domains, connected chip classes.
        /**
         * @brief       constructor
         * @param[in]   i_fileName        name of Rule file
         * @param[in]   i_pTargetHandle   Target associated with RuleChip
         * @param[in]   i_scanFactory     instance of register factory
         * @param[in]   i_reslFactory     instance of resolution factory
         * @param[o]    o_errl            error log handle
         */
        RuleChip( const char * i_fileName ,
                TARGETING::TargetHandle_t   i_pTargetHandle,
                ScanFacility & i_scanFactory,
                ResolutionFactory & i_reslFactory,
                errlHndl_t & o_errl );
        /**
         * @brief         Destructor
         */

        ~RuleChip();
        /**
         * @brief       Analyzes attention in a RuleChip
         * @param[io]   io_serviceData    Reference to STEP_CODE_DATA_STRUCT
         * @param[in]   i_attn            attention reported by RuleChip
         * @return      returns SUCCESS or FAIL
         */

        int32_t Analyze( STEP_CODE_DATA_STRUCT & io_serviceData,
                     ATTENTION_TYPE i_attn );

        /**
         * @brief       Masks error
         * @return      returns SUCCESS or FAIL
         */
        int32_t MaskError(uint32_t i) { return SUCCESS; };
        /**
         * @brief       Returns plugin function pointer
         * @param[in]   i_func         name of  plugin function
         * @param[in]   i_expectNull   availability status of plugin function
         * @return      returns pointer to plugin function
         */

        ExtensibleChipFunction *getExtensibleFunction(
                    const char * i_func, bool i_expectNull = false );
        /**
         * @brief       Returns register instance
         * @param[in]   i_func         name of  plugin function
         * @param[in]   i_expectNull   availability status of plugin function
         * @return      returns pointer to plugin function
         */
        SCAN_COMM_REGISTER_CLASS * getRegister(
                const char * i_func, bool i_expectNull = false );

        /**
         * @brief       Returns data bundle instance
         * @return      returns DataBundle&
         */
        DataBundle *& getDataBundle() { return cv_dataBundle; };

        /**
         * @brief       Returns signature offset associated with registes of a
         *              RuleChip.
         * @return      Error signature offset
         */
         uint32_t getSignatureOffset();

        /**
         * @brief       Captures  register  data
         * @param[io]   io_cap     reference to instance of CaptureData
         * @param[in]   i_group    group id for register capture group
         * @return      returns capture status ( SUCCESS|FAIL)
         */
        virtual int32_t CaptureErrorData(
                    CaptureData& io_cap , int i_group = 1 ) ;
        /**
         * @brief       Initializes the RuleChip instance
         */
        void init( );

    private:    //data
        RuleMetaData * iv_pRuleData ;
        DataBundle * cv_dataBundle;
};

} // end namespace PRDF

#endif
