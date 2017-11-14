/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_callout.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2018                        */
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
/// @file    p9_pm_callout.C
/// @brief   generates a vector of dead cores in response to PM malfunction alert
/// @details In case of PM Malfunction Alert, HBRT invokes PRD by setting a
///           bit in OCC LFIR.As a part of FIR bit response, PRD calls this HWP.
///           Procedure walks the bits of OCC Flag2 register and generates a bit
///           vector of cores considered dead by PHYP. It also points towards
///           a location of FFDC which needs to be committed to an error log.
///           Procedure updates QCSR and CCSR and also cleans up OCC Flag2
///           and some interrupt registers.
///
//----------------------------------------------------------------------------
// *HWP HWP Owner       : Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Prem S Jha <premjha2@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 2
// *HWP Consumed by     : HB
//----------------------------------------------------------------------------
#include <p9_pm_callout.H>
#include <p9_misc_scom_addresses.H>
#include <p9_quad_scom_addresses.H>
#include <p9n2_misc_scom_addresses.H>
#include <p9_hcd_memmap_base.H>
#include <p9_pm_hcd_flags.h>
#include <p9_pm_recovery_ffdc_defines.H>

/**
 * @brief   local constants used within HWP
 */
enum
{
    SUCCESS                     =   0,
    PCB_INTERRUPT_TYPE2_POS     =   20,
    PCB_INTERRUPT_TYPE2_POS_LEN =   12,
    PCB_INTERRUPT_TYPE3_POS     =   20,
    PCB_INTERRUPT_TYPE3_POS_LEN =   12,
    NET_CTRL0_FENCE_EN_POS      =   18,
    CFG_PM_MUX_DISABLE          =   7,
    TP_FENCE_PCB                =   25,
    OCC_FLAG2_SCOM1_ADDR        =   0x0006C18B,
    STATE_CONFIG_SECTN          =   0x00,
    SGPE_SECTN                  =   0x01,
    PGPE_SECTN                  =   0x02,
    CME_SECTN                   =   0x03,
    QPPM_SECTN                  =   0x04,
    CPPM_SECTN                  =   0x05,
    SGPE_GLOBAL_VAR_SECTN       =   0x06,
    PGPE_GLOBAL_VAR_SECTN       =   0x07,
    CME_GLOBAL_VAR_SECTN        =   0x08,
    MAX_FFDC_SUMMARY_SECTN_CNT  =   0x09,
};

/**
 * @brief   various states returned by cores
 */
enum CoreStopState
{
    CORE_IN_STOP_ENTRY          =   0,
    CORE_IN_STOP_EXIT           =   0,
    CORE_L2_STOPPED             =   0,
    QUAD_IN_STOP                =   0,
    CORE_IN_TRANSIT             =   0,
    CORE_NOT_IN_STOP_ENTRY      =   1,
    CORE_NOT_IN_STOP_EXIT       =   2,
    CORE_L2_NOT_STOPPED         =   3,
    QUAD_NOT_IN_STOP            =   4,
    CORE_NOT_IN_TRANSIT         =   5,
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
        fapi2::ReturnCode updateCoreAndQuadConfigState( );

        //@brief    configure the dead core for dump
        //@param[in]    i_coreTgt   fapi2 target for dead core.
        //@return       fapi2 return code.
        fapi2::ReturnCode configDeadCoresForDump( fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_coreTgt );

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
    fapi2::buffer<uint64_t> l_scomData;
    uint8_t l_corePos = 0;
    auto l_coreList = iv_procChipTgt.getChildren<fapi2::TARGET_TYPE_CORE> (fapi2::TARGET_STATE_FUNCTIONAL);
    l_scomData.insert< 0, 32 > ( iv_deadCoreVect );

    //Clearing pending OPIT2Cc Interrupts for all dead cores by writing to Write Clear bits

    FAPI_TRY( putScom( iv_procChipTgt, PU_OCB_OCI_OPIT2PRA_SCOM1, l_scomData ),
              "Failed To Write PCB Int Type 2 Pending Register" );

    //Clearing pending OPIT3Cc Interrupts for all dead cores by writing to Write Clear bits
    FAPI_TRY( putScom( iv_procChipTgt, PU_OCB_OCI_OPIT3PRA_SCOM1, l_scomData ),
              "Failed To Write PCB Int Type 3 Pending Register" );

    for( auto l_core : l_coreList )
    {
        FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS, l_core, l_corePos );

        if( !iv_deadCoreVect.getBit( l_corePos ) )
        {
            //If a core is not enlisted in dead core vector, skip it.
            continue;
        }

        //Clearing Type2 PCB Interrupt for dead core

        FAPI_TRY( putScom( iv_procChipTgt, ( PU_OCB_OCI_OPIT2C0_SCOM1 + l_corePos ), l_scomData ),
                  "Failed To Write PCB Int Type 2 Core %d Register", l_corePos );

        //Clearing Type3 PCB Interrupt for dead core

        FAPI_TRY( putScom( iv_procChipTgt, ( PU_OCB_OCI_OPIT3C0_SCOM1 + l_corePos ), l_scomData ),
                  "Failed To Write PCB Int Type 3 Core %d Register", l_corePos );

        configDeadCoresForDump( l_core );
    }

fapi_try_exit:
    return fapi2::current_err;
}

//--------------------------------------------------------------------------------------------------------

fapi2::ReturnCode CoreAction::configDeadCoresForDump( fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_coreTgt )
{
    fapi2::buffer<uint64_t> l_scomData;
    l_scomData.setBit( NET_CTRL0_FENCE_EN_POS );
    l_scomData.setBit( TP_FENCE_PCB );

    FAPI_TRY( putScom( i_coreTgt, C_NET_CTRL0_WOR, l_scomData ),
              "Failed To Write C_NET_CTRL0_WOR Register" );

    l_scomData.flush<0>();
    l_scomData.setBit( CFG_PM_MUX_DISABLE );
    FAPI_TRY( putScom( i_coreTgt, C_SLAVE_CONFIG_REG, l_scomData ),
              "Failed To Write Slave Config Register" );

fapi_try_exit:
    return fapi2::current_err;
}

//--------------------------------------------------------------------------------------------------------

fapi2::ReturnCode CoreAction::updateCoreAndQuadConfigState()
{
    fapi2::buffer <uint64_t> l_clearMask;
    fapi2::buffer <uint64_t> l_ccsrData;
    fapi2::buffer <uint64_t> l_qcsrData;
    uint8_t bitPos = 0;
    l_clearMask.insert<0, 32, 0>( iv_deadCoreVect );

    l_clearMask = ~(l_clearMask);

    FAPI_TRY( getScom( iv_procChipTgt, PU_OCB_OCI_CCSR_SCOM, l_ccsrData ),
              "Failed To Read CCSR Register" );

    l_ccsrData &= l_clearMask;

    FAPI_DBG( "Clear Mask 0x%016llx  CCSR 0x%016lx",
              l_clearMask, l_ccsrData );

    FAPI_TRY( putScom( iv_procChipTgt, PU_OCB_OCI_CCSR_SCOM, l_ccsrData ),
              "Failed To Write CCSR Register" );

    FAPI_TRY( getScom( iv_procChipTgt, PU_OCB_OCI_QCSR_SCOM, l_qcsrData ),
              "Failed To Read QCSR Register" );

    for( bitPos = 0; bitPos < MAX_CORES_PER_CHIP; bitPos++ )
    {
        if ( !l_ccsrData.getBit( bitPos, 2 ) )
        {
            l_qcsrData.clearBit(( bitPos >> 1 ));
        }
        else
        {
            l_qcsrData.setBit( ( bitPos >> 1 ) );
        }

        bitPos++; // account for both cores in an ex
    }

    FAPI_TRY( putScom( iv_procChipTgt, PU_OCB_OCI_QCSR_SCOM, l_qcsrData ),
              "Failed to Write QCSR Register" );

    FAPI_DBG("CCSR      :   0x%016lx    QCSR    :   0x%016lx",
             l_ccsrData, l_qcsrData );

fapi_try_exit:
    return fapi2::current_err;
}

//--------------------------------------------------------------------------------------------------------

fapi2::ReturnCode CoreAction :: init( )
{
    fapi2::buffer <uint64_t> l_scomData;
    FAPI_TRY( getScom( iv_procChipTgt, P9N2_PU_OCB_OCI_OCCFLG2_SCOM, l_scomData ),
              "Failed To Read OCC Flag2 Register" );
    l_scomData.extract<0, 32>( iv_deadCoreVect );

    FAPI_DBG( "Phyp Dead Core Vector 0x%08lx", iv_deadCoreVect );

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
    l_scomData.setBit( p9hcd::PM_CALLOUT_ACTIVE );      // clear PM Malfunction error

    FAPI_TRY( putScom( iv_procChipTgt, P9N2_PU_OCB_OCI_OCCFLG2_SCOM1, l_scomData ),
              "Failed To Write OCC Flag2 Register" );
fapi_try_exit:
    return fapi2::current_err;
}
//--------------------------------------------------------------------------------------------------------

extern "C"
{
    fapi2::ReturnCode p9_pm_callout(
        void* i_pHomerBase,
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procTgt,
        fapi2::buffer <uint32_t>& o_deadCores,
        std::vector < StopErrLogSectn >& o_ffdcList,
        RasAction&   o_rasAction  )
    {
        using namespace p9_stop_recov_ffdc;
        FAPI_IMP(">> p9_pm_callout" );

        HomerFfdcRegion* l_pHomerFfdc =
            ( HomerFfdcRegion*)( (uint8_t*)i_pHomerBase + FFDC_REGION_HOMER_BASE_OFFSET );
        uint8_t* l_pSummary     =   NULL;
        uint16_t l_sectnSize    =   0;
        o_rasAction             =   NO_CALLOUT;

        CoreAction l_coreActn( i_procTgt );

        FAPI_ASSERT( ( i_pHomerBase != NULL ),
                     fapi2::BAD_HOMER_PTR( )
                     .set_HOMER_PTR( i_pHomerBase ),
                     "Pointer To Homer Base is Bad" );

        //Ensure we got a empty vector. It is HWP which must fill it in.
        o_ffdcList.clear();
        l_coreActn.init();

        FAPI_TRY( l_coreActn.updateCoreAndQuadConfigState(),
                  "Failed To Update Core And Quad Configuration" );

        FAPI_TRY( l_coreActn.clearDeadCorePcbInt(),
                  "Failed To Clear PCB Interrupts" );

        l_coreActn.getDeadCoreVector( o_deadCores ); //retrieve Phyp generated dead core vector

        for( uint8_t l_ffdcSecId = 0; l_ffdcSecId < MAX_FFDC_SUMMARY_SECTN_CNT;
             l_ffdcSecId++ )
        {
            switch( l_ffdcSecId )
            {
                case STATE_CONFIG_SECTN:
                    l_pSummary   =  (uint8_t*) &l_pHomerFfdc->iv_ffdcSummaryRegion.iv_sysState;
                    l_sectnSize  =  sizeof(SysState);
                    break;

                case SGPE_SECTN:
                    l_pSummary   =  &l_pHomerFfdc->iv_ffdcSummaryRegion.iv_sgpeSummary[0];
                    l_sectnSize  =  FFDC_SUMMARY_SIZE_SGPE;
                    break;

                case PGPE_SECTN:
                    l_pSummary   =  &l_pHomerFfdc->iv_ffdcSummaryRegion.iv_pgpeSummary[0];
                    l_sectnSize  =  FFDC_SUMMARY_SIZE_PGPE;
                    break;

                case CME_SECTN:
                    l_pSummary   =  &l_pHomerFfdc->iv_ffdcSummaryRegion.iv_cmeSummary[0][0];
                    l_sectnSize  =  (FFDC_SUMMARY_SIZE_CME * MAX_CMES_PER_CHIP);
                    break;

                case QPPM_SECTN:
                    //QPPM FFDC section is small in size. So, let us lump it all as one user data
                    //section of error log.
                    l_pSummary   =  &l_pHomerFfdc->iv_ffdcSummaryRegion.iv_qpmmRegSummary[0][0];
                    l_sectnSize  =  (FFDC_SUMMARY_SIZE_QPPM_REG * MAX_QUADS_PER_CHIP);
                    break;

                case CPPM_SECTN:
                    //CPPM FFDC section is small in size. So, let us lump it all as one user data
                    //section of error log.
                    l_pSummary   =  &l_pHomerFfdc->iv_ffdcSummaryRegion.iv_cpmmRegSummary[0][0];
                    l_sectnSize  =  (FFDC_SUMMARY_SIZE_CPPM_REG * MAX_CORES_PER_CHIP);
                    break;

                case SGPE_GLOBAL_VAR_SECTN:
                    l_pSummary   =   l_pHomerFfdc->iv_ffdcSummaryRegion.iv_sgpeScoreBoard.iv_dataPtr;
                    l_sectnSize  =   l_pHomerFfdc->iv_ffdcSummaryRegion.iv_sgpeScoreBoard.iv_dataSize;
                    break;

                case PGPE_GLOBAL_VAR_SECTN:
                    l_pSummary   =   l_pHomerFfdc->iv_ffdcSummaryRegion.iv_pgpeScoreBoard.iv_dataPtr;
                    l_sectnSize  =   l_pHomerFfdc->iv_ffdcSummaryRegion.iv_pgpeScoreBoard.iv_dataSize;
                    break;

                case CME_GLOBAL_VAR_SECTN:

                    for( uint32_t l_corePos = 0; l_corePos < MAX_CORES_PER_CHIP; l_corePos++ )
                    {
                        if( o_deadCores.getBit( l_corePos ) )
                        {
                            l_pSummary  = l_pHomerFfdc->iv_ffdcSummaryRegion.iv_cmeScoreBoard[l_corePos].iv_dataPtr;
                            l_sectnSize = l_pHomerFfdc->iv_ffdcSummaryRegion.iv_cmeScoreBoard[l_corePos].iv_dataSize;
                            StopErrLogSectn l_coreGlobalVarSectn( l_pSummary, l_sectnSize );
                            o_ffdcList.push_back( l_coreGlobalVarSectn );
                        }
                    }

                    break;

                default:
                    //Skip the addition of this section to error log
                    FAPI_ERR("Section Number %d Not Defined in STOP Recovery Summary", l_ffdcSecId );
                    continue;
            }

            StopErrLogSectn l_ffdcSubSectn( l_pSummary, l_sectnSize );
            o_ffdcList.push_back( l_ffdcSubSectn );
        }

        if( o_ffdcList.size() > 0 )
        {
            //check ffdc list size just to be sure, callout
            o_rasAction     =   PROC_CHIP_CALLOUT;
        }

        FAPI_DBG( "FFDC Summary Sectn Count 0x%08x", o_ffdcList.size() );

    fapi_try_exit:

        l_coreActn.clearPmMalFuncRegs();

        FAPI_IMP("<< p9_pm_callout" );

        return fapi2::current_err;
    }

//--------------------------------------------------------------------------------------------------------

}//extern "C"
