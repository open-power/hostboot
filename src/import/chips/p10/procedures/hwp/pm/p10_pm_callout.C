/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_callout.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2020                        */
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
///
/// @file    p10_pm_callout.C
/// @brief   generates a vector of dead cores in response to PM malfunction alert
/// @details In case of PM Malfunction Alert, HBRT invokes PRD by setting a
///           bit in OCC LFIR. As a part of FIR bit response, PRD calls this HWP.
///           Procedure walks the bits of OCC Flag7 register and generates a bit
///           vector of cores considered dead by PHYP. It also points towards
///           a location of FFDC which needs to be committed to an error log.
///           Procedure updates QCSR and CCSR and also cleans up OCC Flag7
///           and some interrupt registers.
///
//----------------------------------------------------------------------------
// *HWP HWP Owner       : Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Prem S Jha <premjha2@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 2
// *HWP Consumed by     : PRD
//----------------------------------------------------------------------------
#include <p10_pm_callout.H>
#include <p10_hcd_memmap_base.H>
#include <p10_pm_hcd_flags.h>
#include <p10_scom_proc_7.H>
#include <p10_scom_proc_5.H>
#include <p10_scom_eq_6.H>
#include <p10_scom_eq_a.H>
#include <p10_scom_proc.H>
#include <p10_scom_c.H>
#include <p10_scom_eq.H>

/**
 * @brief   local constants used within HWP
 */
enum
{
    SUCCESS                 =   0,
    PM_CALLOUT_ACTIVE       =   31,
    OCC_FLAG7_WO_CLR        =   0x6c0c2,
    OCC_FLAG7_RW            =   0x6c0c1,
    CORE_PSCOM_ENABLE_POS   =   0x05,
    CORE_FENCE_ENABLE_POS   =   0x05,
    L3_PSCOM_ENABLE_POS     =   0x09,
    L3_FENCE_ENABLE_POS     =   0x09,
    MMA_PSCOM_ENABLE_POS    =   0x0f,
    MMA_FENCE_ENABLE_POS    =   0x0f,
};

/**
 * @brief   various states returned by cores
 */
enum CoreStopState
{
    BAD_CORE_POS                =   6,
    INTERNAL_ERROR              =   7,
};

/**
 * @brief models all the clean up action needed on dead cores.
 */
class CoreAction
{
    public:

        // @brief constructor
        // @param[in]  i_procTgt       proc chip target

        CoreAction( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procTgt )
            : iv_procChipTgt ( i_procTgt )
        { }

        // @brief destructor
        ~CoreAction( ) { };

        //@brief    initializes the core status.
        fapi2::ReturnCode init();

        //@brief    clears PCB Type2 and 3 interrupts for dead cores.
        //@return   fapi2 return code
        fapi2::ReturnCode clearDeadCorePcbInt( );

        //@brief    updates CCSR and QCSR registers.
        //@return   fapi2 return code.
        fapi2::ReturnCode updateCoreConfigState( );

        //@brief    configure the dead core for dump
        //@param[in]    i_coreTgt   fapi2 target for dead core.
        //@return       fapi2 return code.
        fapi2::ReturnCode configDeadCoresForDump( );

        //@brief populates input buffer with a bit vector of dead cores.
        void getDeadCoreVector( fapi2::buffer <uint32_t>& o_deadCoreVectBuf );

        //@brief        clean up Phyp generated dead cores list and PM malfunction error.
        //@return       fapi2 return code.
        fapi2::ReturnCode clearPmMalFuncRegs();

    private:    //data
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> iv_procChipTgt; // Proc Chip
        fapi2::buffer <uint32_t> iv_deadCoreVect;   // vector of dead cores
};

//--------------------------------------------------------------------------------------------------------

fapi2::ReturnCode CoreAction::clearDeadCorePcbInt( )
{

fapi_try_exit:
    return fapi2::current_err;
}

//--------------------------------------------------------------------------------------------------------

fapi2::ReturnCode CoreAction::configDeadCoresForDump( )
{

    auto l_eqList   =   iv_procChipTgt.getChildren< fapi2::TARGET_TYPE_EQ >( fapi2::TARGET_STATE_FUNCTIONAL );

    fapi2::buffer< uint64_t > l_chipletCtrl1;
    fapi2::buffer< uint64_t > l_chipletCtrl3;
    fapi2::buffer< uint64_t > l_data;
    uint32_t l_regionPos = 0;
    uint8_t  l_corePos   = 0;

    for( auto l_eq : l_eqList )
    {
        auto l_coreList  =  l_eq.getChildren< fapi2::TARGET_TYPE_CORE > ( fapi2::TARGET_STATE_FUNCTIONAL );
        uint64_t l_pfetStatus   =   0;
        l_chipletCtrl1.flush< 0 >();
        l_chipletCtrl3.flush< 0 >();

        for( auto l_core : l_coreList )
        {
            FAPI_TRY( FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS, l_core, l_corePos ) );
            l_data.flush< 0 > ();

            if( iv_deadCoreVect.getBit( l_corePos ) )
            {
                l_regionPos     =   l_corePos % 4;
                l_pfetStatus    =   0;

                //Read the power status of EL
                FAPI_TRY(scomt::c::GET_CPMS_CL2_PFETSTAT(l_core, l_data));
                scomt::c::GET_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE(l_data, l_pfetStatus);

                if( l_pfetStatus )
                {
                    //core-L2 power is On
                    FAPI_DBG( "Core %d Power On", l_corePos );
                    //clear fence
                    l_chipletCtrl1.setBit( CORE_FENCE_ENABLE_POS + l_regionPos );

                    //enable SCOM
                    l_chipletCtrl3.setBit( CORE_PSCOM_ENABLE_POS + l_regionPos );
                }

                //Read the power status of L3
                l_pfetStatus    =   0;
                l_data.flush< 0 > ();
                FAPI_TRY(scomt::c::GET_CPMS_L3_PFETSTAT(l_core, l_data));
                scomt::c::GET_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE(l_data, l_pfetStatus);

                if( l_pfetStatus )
                {
                    //L3 power is On
                    FAPI_DBG( "Core %d L3 Power On", l_corePos );
                    //clear fence
                    l_chipletCtrl1.setBit( L3_FENCE_ENABLE_POS + l_regionPos );

                    //enable SCOM
                    l_chipletCtrl3.setBit( L3_PSCOM_ENABLE_POS + l_regionPos );
                }

                l_data.flush< 0 > ();
                l_pfetStatus    =   0;
                FAPI_TRY(scomt::c::GET_CPMS_MMA_PFETSTAT(l_core, l_data));
                scomt::c::GET_CPMS_MMA_PFETSTAT_S_ENABLED_SENSE(l_data, l_pfetStatus);

                if( l_pfetStatus )
                {
                    //mma power is on
                    FAPI_DBG( "Core %d MMA Power On", l_corePos );
                    //clear fence
                    l_chipletCtrl1.setBit( MMA_FENCE_ENABLE_POS + l_regionPos );

                    //enable SCOM
                    l_chipletCtrl3.setBit( MMA_PSCOM_ENABLE_POS + l_regionPos );
                }
            }

        }// for( l_core

        FAPI_TRY( fapi2::putScom( l_eq, scomt::eq::CPLT_CTRL1_WO_CLEAR, l_chipletCtrl1 ));
        FAPI_TRY( fapi2::putScom( l_eq, scomt::eq::CPLT_CTRL3_WO_OR, l_chipletCtrl3 ));
        FAPI_INF( "Chiplet Ctrl1 0x%016lx Chiplet Ctrl3 0x%016lx\n", l_chipletCtrl1, l_chipletCtrl3 );

    } //for ( l_eq

fapi_try_exit:
    return fapi2::current_err;
}

//--------------------------------------------------------------------------------------------------------

fapi2::ReturnCode CoreAction::updateCoreConfigState()
{
    fapi2::buffer <uint64_t> l_ccsrData;
    l_ccsrData.insert<0, 32, 0>( iv_deadCoreVect );
    FAPI_DBG( "CCSR Bit Vector 0x%016lx", l_ccsrData );

    FAPI_TRY( putScom( iv_procChipTgt, scomt::proc::TP_TPCHIP_OCC_OCI_OCB_CCSR_WO_CLEAR, l_ccsrData ),
              "Failed To Write CCSR Register" );

fapi_try_exit:
    return fapi2::current_err;
}

//--------------------------------------------------------------------------------------------------------

fapi2::ReturnCode CoreAction :: init( )
{
    fapi2::buffer <uint64_t> l_scomData;
    FAPI_TRY( getScom( iv_procChipTgt, OCC_FLAG7_RW, l_scomData ),
              "Failed To Read OCC Flag2 Register" );
    l_scomData.extract<0, 32>( iv_deadCoreVect );

fapi_try_exit:
    return fapi2::current_err;
}

//--------------------------------------------------------------------------------------------------------

void CoreAction :: getDeadCoreVector( fapi2::buffer <uint32_t>& o_deadCoreVectBuf )
{
    o_deadCoreVectBuf.flush<0>();
    iv_deadCoreVect.extract<0, 32>( o_deadCoreVectBuf );
}

//--------------------------------------------------------------------------------------------------------

fapi2::ReturnCode CoreAction :: clearPmMalFuncRegs( )
{
    fapi2::buffer <uint64_t> l_scomData;

    l_scomData.flush < 0 >();
    l_scomData.setBit( 0, MAX_CORES_PER_CHIP );   // clear dead core vector

    FAPI_TRY( putScom( iv_procChipTgt, OCC_FLAG7_WO_CLR, l_scomData ),
              "Failed To Write OCC Flag7 Register" );

    l_scomData.flush < 0 >();
    l_scomData.setBit( PM_CALLOUT_ACTIVE );      // clear PM Malfunction active bit
    FAPI_TRY( putScom( iv_procChipTgt, scomt::proc::TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_CLEAR, l_scomData ),
              "Failed To Write OCC Flag2 Register" );

fapi_try_exit:
    return fapi2::current_err;
}
//--------------------------------------------------------------------------------------------------------

extern "C"
{
    fapi2::ReturnCode p10_pm_callout(
        void* i_pHomerBase,
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procTgt,
        fapi2::buffer <uint32_t>& o_deadCores,
        std::vector < StopErrLogSectn >& o_ffdcList,
        RasAction&   o_rasAction  )
    {
        FAPI_IMP(">> p10_pm_callout" );

        o_rasAction = NO_CALLOUT;

        CoreAction l_coreActn( i_procTgt );

        FAPI_ASSERT( ( i_pHomerBase != NULL ),
                     fapi2::BAD_HOMER_PTR( )
                     .set_HOMER_PTR( i_pHomerBase ),
                     "Pointer To Homer Base is Bad" );

        //Ensure we got an empty vector. It is HWP which must fill it in.
        l_coreActn.init();

        FAPI_TRY( l_coreActn.updateCoreConfigState(),
                  "Failed To Update Core Configuration" );

        FAPI_TRY( l_coreActn.configDeadCoresForDump(),
                  "Failed To Config Cores For Dump" );

        l_coreActn.getDeadCoreVector( o_deadCores ); //retrieve Phyp generated dead core vector
        FAPI_INF("Dead cores from PHYP: 0x%08x", o_deadCores);

    fapi_try_exit:

        l_coreActn.clearPmMalFuncRegs();

        FAPI_IMP("<< p10_pm_callout" );

        return fapi2::current_err;
    }

//--------------------------------------------------------------------------------------------------------

}//extern "C"
