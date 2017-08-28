/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_check_idle_stop_done.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file   p9_check_idle_stop_done.C
/// @brief  Implements HWP that collects relevant PM complex info in case of activate core failure.
///
// *HWP HWP Owner:      Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner:       Prem S Jha <premjha2@in.ibm.com>
// *HWP Team:           PM
// *HWP Level:          2
// *HWP Consumed by:    Hostboot: Phyp

//--------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------
#include <p9_check_idle_stop_done.H>
#include <p9_misc_scom_addresses.H>
#include <p9_quad_scom_addresses.H>
#include <ocb_register_addresses.h>
#include <p9_ppe_defs.H>
#include <p9_ppe_utils.H>
#include <p9_eq_clear_atomic_lock.H>

namespace p9_check_idle_stop
{

/**
 * @brief   describes all the states pertaining to PM Complex engines.
 */
enum PmState
{
    STOP_GATED      =   0x0001,
    CME_HW_HALT     =   0x0002,
    SGPE_RUNNING    =   0x0004,
    SGPE_HW_HALT    =   0x0008,
    CME_OFFLINE     =   0x0010,
    BAD_CORE_ATTN   =   0x0020,
    SCOM_FAILURE    =   0x0040,
    CME_HCODE_HALT  =   0x0080,
    SGPE_HCODE_HALT =   0x0100,
    SGPE_OFFLINE    =   0x0200,
    PM_ACTIVE       =   0x0400,
};

/**
 * @brief   Misc constants local to HWP implementation.
 */
enum
{
    STOP_GATED_BIT              =   0,
    PM_ACTIVE_BIT               =   34, // for C0
    BOTH_CORES                  =   2,
    HALT_BIT                    =   0,
    SPECIAL_ATTN_BIT            =   32,
    TRAP_OPCODE                 =   0x7f,
    TRAP_EVENT_BIT              =   7, //in XSR
    MAX_CORE_PER_QUAD           =   4,
    MAX_CORE_PER_EX             =   2,
    INIT_BUF_PATT               =   0xDEADDEADDEADDEADll,
    FORCE_CORE_TIMEOUT_MS   =   1,
    FORCE_CORE_POLLTIME_US  =   300,
    FORCE_CORE_POLLTIME_MCYCLES = 2,
    TIMEOUT_COUNT               =
        (FORCE_CORE_TIMEOUT_MS * 1000) / FORCE_CORE_POLLTIME_US,
    HALT_CONDITION_BIT          =   4,

};

/**
 * @brief   Models CME associated with a given Ex.
 * @note    Collect hardware state of a given CME by
 * reading some SPRs and status register.
 */
class CmeState
{
    public:

        /**
         * @brief   constructor
         */
        CmeState( ) :
            iv_cmePos( 0 ),
            iv_cmeHcodeState( 0 ),
            iv_irRegValue( 0 )

        { }

        /**
         * @brief   destructor
         */
        ~CmeState() { }

        /**
         * @brief returns true if CME is halted false otherwise.
         */
        bool isCmeHalted( );

        /**
         * @brief returns true if CME hcode is in halt state due to Hcode trap.
         */
        bool isCmeHcodeHalted( );

        /**
         * @brief checks CME's accessibility.
         * @param[in]   i_exTgt     ex target.
         * @return  true if CME is accessible, false otherwise.
         */
        bool checkCmeStatus( fapi2::Target< fapi2::TARGET_TYPE_EX >& i_exTgt );

        /**
         * @brief   returns availability status as boolean.
         * @note    It just returns the last recorded status. No actual
         * checking is done.
         */
        bool isCmeOnLine();

        /**
         * @brief returns true if CME is active in PM function, false otherwise.
         */
        bool isPmActive();

        /**
         * @brief returns true if core is powered off or clocked off, false otherwise.
         */
        bool isStopGated();

        /**
         * @brief returns true if one of the core is reporting special attention, false otherwise.
         */
        bool isCoreReportingSpecialAttn();

        /**
         * @brief   Investigates the state of CME
         * @param[in]   i_coreTgt     fapi2 target for core
         * @return  FAPI2_RC_SUCCESS for success, error code otherwise.
         */
        fapi2::ReturnCode init( fapi2::Target< fapi2::TARGET_TYPE_CORE >& i_coreTgt );

        /**
         * @brief dumps CME State in Cronus environment.
         */
        void dumpCmeState();

        /**
         * @brief returns position of CME.
         */
        uint8_t getCmePosition()
        {
            return iv_cmePos;
        }

        /**
         * @brief returns XSR value of CME associated with failing core.
         */
        uint32_t getXsrRegValue( )
        {
            return iv_xsrRegValue;
        }

    private:
        uint8_t     iv_cmePos;          // CME Position
        uint16_t    iv_cmeHcodeState;   // State of CME
        uint8_t     iv_reserve;         // Reserve Fields
        uint32_t    iv_irRegValue;      // IR value
        uint32_t    iv_xsrRegValue;     // XSR value
};

/**
 * @brief   Returns the fully qualified address for a CME register
 * @param[in]   i_cmeid     position of a CME
 * @param[in]   i_baseaddr  base address for a CME register
 * @return  return the fully qualified address of a CME register
 */
uint64_t calCmeAddr(uint8_t i_cmeid, uint64_t i_baseaddr)
{
    return ( i_baseaddr |
             ((i_cmeid / 2 ) << 24) |
             ((i_cmeid % 2 ) << 10) );
}

//----------------------------------------------------------------------------------------------

bool CmeState::isCmeHalted( )
{
    bool cmeHaltState = false;
    cmeHaltState = ( iv_cmeHcodeState & CME_HW_HALT ) ? true : false;

    return cmeHaltState;
}

//----------------------------------------------------------------------------------------------

bool CmeState::isCmeHcodeHalted()
{
    bool cmeHcodeHalted = false;
    cmeHcodeHalted = ( iv_cmeHcodeState & CME_HCODE_HALT ) ? true : false;

    return cmeHcodeHalted;
}

//----------------------------------------------------------------------------------------------

bool CmeState::isCmeOnLine()
{
    bool l_cmeAvailable = false;
    l_cmeAvailable = ( iv_cmeHcodeState & (CME_OFFLINE | SCOM_FAILURE) ) ? false : true;

    return l_cmeAvailable;
}

//----------------------------------------------------------------------------------------------

bool CmeState::checkCmeStatus( fapi2::Target< fapi2::TARGET_TYPE_EX >& i_exTgt )
{
    bool cmeOnLine = false;
    fapi2::buffer<uint64_t> l_cmeSisrRegValue;
    cmeOnLine = ( getScom( i_exTgt, EX_CME_LCL_SISR_SCOM, l_cmeSisrRegValue ) == fapi2::FAPI2_RC_SUCCESS );

    return cmeOnLine;
}

//----------------------------------------------------------------------------------------------

bool CmeState::isCoreReportingSpecialAttn()
{
    bool specialAttn = false;

    specialAttn = ( iv_cmeHcodeState & BAD_CORE_ATTN ) ? true : false;
    return specialAttn;
}

//----------------------------------------------------------------------------------------------

bool CmeState::isPmActive()
{
    bool l_pmActive = false;
    l_pmActive = ( iv_cmeHcodeState & PM_ACTIVE ) ? true : false;

    return l_pmActive;
}

//----------------------------------------------------------------------------------------------

bool CmeState::isStopGated()
{
    bool l_stopGated = false;
    l_stopGated = ( iv_cmeHcodeState & STOP_GATED ) ? true : false;

    return l_stopGated;
}

//----------------------------------------------------------------------------------------------

fapi2::ReturnCode CmeState:: init( fapi2::Target< fapi2::TARGET_TYPE_CORE >& i_coreTgt )
{
    FAPI_DBG(">> CmeState:: init" );
    fapi2::buffer<uint64_t> l_cmeSisrRegValue;
    fapi2::buffer<uint64_t> l_cmeXsrRegValue;
    fapi2::buffer<uint64_t> l_cmeRegValue;
    uint32_t l_tempXirData = 0;
    uint8_t l_corePos = 0;
    uint8_t l_coreSplAttn = SPECIAL_ATTN_BIT;
    uint8_t l_pmActive = PM_ACTIVE_BIT;
    fapi2::ReturnCode l_retCode = fapi2::FAPI2_RC_SUCCESS;
    uint32_t cmeBaseAddress = 0;

    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_parentProc =
        i_coreTgt.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    fapi2::Target<fapi2::TARGET_TYPE_EX> l_exTgt =
        i_coreTgt.getParent<fapi2::TARGET_TYPE_EX>();

    FAPI_TRY( FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS, i_coreTgt, l_corePos ),
              "FAPI_ATTR_GET Failed To Read CME Position" );

    iv_cmePos = l_corePos >> 1;

    l_coreSplAttn =  ( l_corePos & 0x01 ) ? ( l_coreSplAttn + 1 ) : l_coreSplAttn;
    l_pmActive    =  ( l_corePos & 0x01 ) ? ( l_pmActive + 1 ) : l_pmActive;

    do
    {
        cmeBaseAddress = calCmeAddr( iv_cmePos, EX_PPE_XIRAMDBG );

        l_retCode = getScom( l_parentProc, cmeBaseAddress, l_cmeXsrRegValue );

        if( l_retCode  != fapi2::FAPI2_RC_SUCCESS )
        {
            //atomic lock is already dropped still CME is not accessible
            //We can't proceed further with this CME.

            FAPI_IMP("CME Found Offline");
            iv_cmeHcodeState |= CME_OFFLINE;
            break;
        }

        FAPI_DBG("CME XSR Val       :   0x%016lx", l_cmeXsrRegValue );

        l_retCode = getScom( l_exTgt, EX_CME_LCL_SISR_SCOM, l_cmeSisrRegValue );

        if( l_retCode  != fapi2::FAPI2_RC_SUCCESS )
        {
            iv_cmeHcodeState |= SCOM_FAILURE;
            break;
        }

        if( l_cmeSisrRegValue.getBit( l_pmActive ) )
        {
            iv_cmeHcodeState |= PM_ACTIVE;
        }

        FAPI_DBG("SISR Val          :   0x%016lx", l_cmeSisrRegValue );

        //CME is in halt state

        if( l_cmeXsrRegValue.getBit< HALT_BIT >() )
        {
            if( l_cmeSisrRegValue.getBit( l_coreSplAttn ) )
            {
                iv_cmeHcodeState |= BAD_CORE_ATTN;
                break;
            }

            l_retCode = getScom( l_exTgt, EX_PPE_XIRAMEDR, l_cmeRegValue );

            if( l_retCode != fapi2::FAPI2_RC_SUCCESS )
            {
                iv_cmeHcodeState |= SCOM_FAILURE;
                break;
            }

            l_cmeRegValue.extract<0, 8>( l_tempXirData );
            l_cmeRegValue.extract<0, 32>( iv_irRegValue );

            FAPI_DBG("CME IR-EDR    :   0x%016lx", l_cmeRegValue );

            if( ( TRAP_OPCODE == l_tempXirData ) ||
                l_cmeXsrRegValue.getBit< TRAP_EVENT_BIT >() )
            {
                iv_cmeHcodeState |= CME_HCODE_HALT;
                break;
            }

            iv_cmeHcodeState |= CME_HW_HALT;
        }
        else
        {
            l_retCode = getScom( i_coreTgt, C_0_PPM_SSHSRC, l_cmeRegValue );

            if( l_retCode != fapi2::FAPI2_RC_SUCCESS )
            {
                iv_cmeHcodeState |= SCOM_FAILURE;
                break;
            }

            FAPI_DBG("Core SSHSRC  :   0x%016lx", l_cmeRegValue );

            if( l_cmeRegValue.getBit< STOP_GATED_BIT >() )
            {
                iv_cmeHcodeState |= STOP_GATED;
                break;
            }
        }
    }
    while(0);

    fapi2::current_err = l_retCode;

fapi_try_exit:

    FAPI_DBG("<< CmeState:: init" );

    return fapi2::current_err;

}

//----------------------------------------------------------------------------------------------

void CmeState::dumpCmeState()
{
#ifndef __HOSTBOOT_MODULE

    FAPI_DBG("============================= CME State =============================================");
    FAPI_DBG("CME Pos                          :   0x%02d", iv_cmePos );
    FAPI_DBG("CME Is Accessible                :   %s", isCmeOnLine( ) ? "Yes" : "No" );
    FAPI_DBG("CME In Halt State Due to HW      :   %s", isCmeHalted( ) ? "Yes" : "No" );
    FAPI_DBG("CME In Halt State Due to Hcode   :   %s", isCmeHcodeHalted( ) ? "Yes" : "No" );
    FAPI_DBG("PM State Active                  :   %s", isPmActive( ) ? "Yes" : "No" );
    FAPI_DBG("STOP Gated                       :   %s", isStopGated( ) ? "Yes" : "No" );
    FAPI_DBG("Core Reporting Spl Attention     :   %s", isCoreReportingSpecialAttn( ) ? "Yes" : "No" );
    FAPI_DBG("============================= CME State Ends =========================================");

#endif
}

//----------------------------------------------------------------------------------------------

/**
 * @brief   Models SGPE State
 * @note    Collect hardware state of SGPE by reading some SPRs and status register.
 */
class SgpeState
{
    public:

        /**
         * @brief   constructor
         */
        SgpeState( ) :
            iv_sgpeHcodeState ( 0 ),
            iv_irRegValue( 0 )
        { }

        /**
         * @brief   destructor
         */
        ~SgpeState() { }

        /**
         * @brief returns true if SGPE is halted false otherwise.
         */
        bool isSgpeHalted( );

        /**
         * @brief returns true if SGPE is halted due to Hcode, false otherwise.
         */
        bool isSgpeHcodeHalted();

        /**
         * @brief returns true if SGPE is running, false otherwise.
         */
        bool isSgpeRunning( );

        /**
         * @brief   init SGPE state
         * @param[in]   i_exTgt fapi2 target for an Ex
         * @return  fapi2 RC
         */
        fapi2::ReturnCode init( fapi2::Target< fapi2::TARGET_TYPE_EX >& i_exTgt );

        /**
         * @brief dumps state of SGPE
         */
        void dumpSgpeState();

        /**
         * @brief returns EDR register value.
         */
        uint32_t getEdrValue()
        {
            return iv_edrValue;
        }


    private:

        uint16_t    iv_sgpeHcodeState;   // State of SGPE
        uint8_t     iv_reserve[2];       // Reserve Fields
        uint32_t    iv_irRegValue;       // IR value
        uint32_t    iv_edrValue;         // EDR value
};

//----------------------------------------------------------------------------------------------

bool SgpeState::isSgpeHalted( )
{
    bool sgpeHaltState = false;
    sgpeHaltState = ( iv_sgpeHcodeState & SGPE_HW_HALT ) ? true : false;

    return sgpeHaltState;
}

//----------------------------------------------------------------------------------------------

bool SgpeState::isSgpeHcodeHalted()
{
    bool sgpeHcodeHalted = false;
    sgpeHcodeHalted = ( iv_sgpeHcodeState & SGPE_HCODE_HALT ) ? true : false;

    return sgpeHcodeHalted;
}

//----------------------------------------------------------------------------------------------

bool  SgpeState::isSgpeRunning()
{
    bool sgpeRunning = false;
    sgpeRunning = ( iv_sgpeHcodeState & SGPE_RUNNING ) ? true : false;

    return sgpeRunning;
}
//----------------------------------------------------------------------------------------------

fapi2::ReturnCode SgpeState::init( fapi2::Target< fapi2::TARGET_TYPE_EX >& i_exTgt )
{
    FAPI_IMP( ">> SgpeState::init" );
    fapi2::ReturnCode l_retCode = fapi2::FAPI2_RC_SUCCESS;
    fapi2::buffer<uint64_t> l_sgpeXsrRegVal;
    fapi2::buffer<uint64_t> l_sgpeRegValue;
    uint32_t l_tempXirData = 0;

    do
    {
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_parentProc =
            i_exTgt.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

        //Giving enough time for SGPE to Halt just in case error under investgation is causing
        //it to halt.

        l_retCode = fapi2::delay(FORCE_CORE_POLLTIME_US  * 1000, FORCE_CORE_POLLTIME_MCYCLES * 1000 * 1000);

        if( l_retCode )
        {
            //Still let us make an attempt to check SGPE State
            FAPI_INF("fapi2::delay failed" );
        }

        l_retCode = getScom( l_parentProc, PU_GPE3_GPEXIXSR_SCOM, l_sgpeXsrRegVal );

        if( l_retCode != fapi2::FAPI2_RC_SUCCESS )
        {
            iv_sgpeHcodeState |= SGPE_OFFLINE;
            break;
        }

        FAPI_DBG("SGPE XSR          :   0x%016lx", l_sgpeXsrRegVal );

        l_sgpeXsrRegVal.extract<0, 32>( iv_edrValue );  //extract EDR value

        if( l_sgpeXsrRegVal.getBit< HALT_BIT >() )
        {
            l_retCode = getScom( l_parentProc, PU_GPE3_PPE_XIRAMEDR, l_sgpeRegValue );

            if( l_retCode != fapi2::FAPI2_RC_SUCCESS )
            {
                iv_sgpeHcodeState |= SCOM_FAILURE;
                break;
            }

            FAPI_DBG("SGPE IR-EDR   :   0x%016lx", l_sgpeRegValue );

            l_sgpeRegValue.extract<0, 8>( l_tempXirData );
            l_sgpeRegValue.extract<0, 32>( iv_irRegValue );

            if( ( TRAP_OPCODE == l_tempXirData ) ||
                l_sgpeXsrRegVal.getBit< TRAP_EVENT_BIT >() )
            {
                iv_sgpeHcodeState |= SGPE_HCODE_HALT;
            }

            iv_sgpeHcodeState |= SGPE_HW_HALT;
        }
        else
        {
            iv_sgpeHcodeState |= SGPE_RUNNING;
        }
    }
    while(0);

    fapi2::current_err = l_retCode;

    FAPI_IMP( "<< SgpeState::init" );

    return l_retCode;
}

//----------------------------------------------------------------------------------------------

void SgpeState::dumpSgpeState( )
{
#ifndef __HOSTBOOT_MODULE

    FAPI_DBG("============================= SGPE State ==============================================");
    FAPI_DBG("SGPE in Halt State Due to HW Error    :   %s", isSgpeHalted( ) ? "Yes" : "No" );
    FAPI_DBG("SGPE in Halt State Due to Hcode       :   %s", isSgpeHcodeHalted() ? "Yes" : "No" );
    FAPI_DBG("SGPE Running                          :   %s", isSgpeRunning() ? "Yes" : "No" );
    FAPI_DBG("============================= SGPE State Ends =========================================");

#endif
}
//----------------------------------------------------------------------------------------------

class StopFfdcRules
{
    public:

        /**
         * @brief   constructor
         */
        StopFfdcRules( const fapi2::Target< fapi2::TARGET_TYPE_CORE >& i_coreTgt ) :
            iv_coreTgt( i_coreTgt )
        { }

        /**
         * @brief   destructor
         */
        ~StopFfdcRules() { }

        /**
         * @brief   Investigates PM complex and returns appropriate reason code
         * @return  fapi2 RC
         */
        fapi2::ReturnCode analyze(  );

        /**
         * @brief   Collects CME and SGPE State.
         * @return  fapi2 RC
         */
        fapi2::ReturnCode init( );

        /**
         * @brief   returns a fapi2 RC suggesting that SGPE halt due to Hcode.
         * @return  fapi2 RC
         */
        fapi2::ReturnCode assertSgpeHcodeHalted();

        /**
         * @brief   returns a fapi2 RC suggesting that SGPE halt due to hardware error.
         * @return  fapi2 RC
         */
        fapi2::ReturnCode assertSgpeHardwareHalted();

        /**
         * @brief   returns a fapi2 RC suggesting that core is reporting special attention.
         * @return  fapi2 RC
         */
        fapi2::ReturnCode assertCoreAttention();

        /**
         * @brief   returns a fapi2 RC suggesting that CME is in halt state due to hcode.
         * @return  fapi2 RC
         */
        fapi2::ReturnCode assertCmeHcodeHalt();

        /**
         * @brief   returns a fapi2 RC suggesting that core is in halt state due to hw error.
         * @return  fapi2 RC
         */
        fapi2::ReturnCode assertCmeHalted();

        /**
         * @brief   returns a fapi2 RC suggesting that core is not stopped or in error state.
         * @return  fapi2 RC
         */
        fapi2::ReturnCode assertCoreRunning();

        /**
         * @brief   returns a fapi2 RC suggesting that PM complex is in an unrecognized error state.
         * @return  fapi2 RC
         */
        fapi2::ReturnCode assertPmUnknown();

        /**
         * @brief   returns a fapi2 RC suggesting that CME is not accessible.
         * @return  fapi2 RC
         */
        fapi2::ReturnCode assertCmeNotAccessible();

        /**
         * @brief   returns a fapi2 RC suggesting that SGPE is not accessible.
         * @return  fapi2 RC
         */
        fapi2::ReturnCode assertSgpeNotAccessible();

        /**
         * @brief   forces SGPE to halt state
         * @return  fapi2 RC
         */
        fapi2::ReturnCode forceSgpeHalt();

    private:

        SgpeState       iv_SgpeState;   // Summarizes state of SGPE
        CmeState        iv_CmeState;    // Summarizes state of CME
        fapi2::Target   < fapi2::TARGET_TYPE_CORE > iv_coreTgt; // fapi2 core target
        fapi2::Target   < fapi2::TARGET_TYPE_EX > iv_exTgt; // fapi2 ex target
        fapi2::Target   < fapi2::TARGET_TYPE_EQ > iv_eqTgt; // fapi2 eq target
        fapi2::Target   < fapi2::TARGET_TYPE_PROC_CHIP > iv_procTgt;    // fapi2 proc target
};

//----------------------------------------------------------------------------------------------

fapi2::ReturnCode StopFfdcRules::init()
{
    FAPI_DBG(">> StopFfdcRules::init");
    fapi2::ReturnCode l_retCode = fapi2::FAPI2_RC_SUCCESS;

    iv_exTgt    =   iv_coreTgt.getParent<fapi2::TARGET_TYPE_EX>();
    iv_eqTgt    =   iv_exTgt.getParent<fapi2::TARGET_TYPE_EQ>();
    iv_procTgt  =   iv_exTgt.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    FAPI_TRY( iv_SgpeState.init( iv_exTgt ),
              "SGPE Init Failed" );

    if( !iv_CmeState.checkCmeStatus( iv_exTgt ) && iv_SgpeState.isSgpeRunning() )
    {
        //SGPE is running but CME is not accessible. It might be because of
        //atomic lock taken by SGPE. So, halt SGPE and drop atomic lock to make
        //CME accessible

        FAPI_TRY( forceSgpeHalt(),
                  "Failed To Force Halt SGPE" );

        FAPI_TRY( p9_clear_atomic_lock( iv_eqTgt ),
                  "Failed To Clear Atomic Lock" );
    }

    FAPI_TRY( iv_CmeState.init( iv_coreTgt ),
              "Failure In Getting CME State" );

    iv_SgpeState.dumpSgpeState();
    iv_CmeState.dumpCmeState();

fapi_try_exit:
    FAPI_DBG("<< StopFfdcRules::init");
    return fapi2::current_err;
}

//----------------------------------------------------------------------------------------------

fapi2::ReturnCode StopFfdcRules::forceSgpeHalt( )
{
    FAPI_DBG(">> StopFfdcRules::forceSgpeHalt" );
    fapi2::buffer<uint64_t> l_xsrValue;

    //force halt XCR[1:3] = 0b111
    l_xsrValue.setBit < 1 > ( );
    l_xsrValue.setBit < 2 > ( );
    l_xsrValue.setBit < 3 > ( );
    uint32_t  l_timeout = TIMEOUT_COUNT;

    FAPI_TRY( putScom( iv_procTgt, PU_GPE3_GPEXIXSR_SCOM, l_xsrValue ) );

    do
    {
        FAPI_TRY( fapi2::delay(FORCE_CORE_POLLTIME_US  * 1000, FORCE_CORE_POLLTIME_MCYCLES * 1000 * 1000) );

        FAPI_TRY( getScom(iv_procTgt, PU_GPE3_GPEXIXSR_SCOM, l_xsrValue ),
                  "Failed To Read SGPE XSR" );

    }
    while( l_xsrValue.getBit< HALT_BIT >() && ( --l_timeout != 0) );

fapi_try_exit:
    FAPI_DBG("<< StopFfdcRules::forceSgpeHalt" );
    return fapi2::current_err;
}

//----------------------------------------------------------------------------------------------

fapi2::ReturnCode StopFfdcRules::analyze( )
{
    FAPI_DBG(">> StopFfdcRules::analyze");

    fapi2::ReturnCode l_retCode = fapi2::FAPI2_RC_SUCCESS;
    //*************************************************************************
    //-----------------------|-------------------------------------------------
    // Error Condition       |   Return Code
    //-----------------------|-------------------------------------------------
    // Trap in SGPE Hcode    | SGPE_HCODE_HALTED
    //-----------------------|-------------------------------------------------
    // Trap in SGPE HW       | SGPE_HW_HALTED
    //-----------------------|-------------------------------------------------
    // Trap in CME Hcode     | CME_HCODE_HALTED
    //-----------------------|-------------------------------------------------
    // Error In Hw           | CME_ERROR
    //-----------------------|-------------------------------------------------
    // Spl ATTN from Core    | CORE_ATTENTION
    //-----------------------|-------------------------------------------------
    // Cores Active          | CORE_RUNNING
    //-----------------------|-------------------------------------------------
    // Unidentified Error    | UNKNOWN_PM_STATE
    //-----------------------|-------------------------------------------------
    // CME SCOM Error        | CME_NOT_ACCESSIBLE
    //-------------------------------------------------------------------------
    // SGPE SCOM Error       | SGPE_NOT_ACCESSIBLE
    //-------------------------------------------------------------------------
    //*************************************************************************

    if( !iv_SgpeState.isSgpeRunning() )
    {
        if( iv_SgpeState.isSgpeHcodeHalted() )
        {
            l_retCode = assertSgpeHcodeHalted();
        }
        else if( iv_SgpeState.isSgpeHalted() )
        {
            l_retCode = assertSgpeHardwareHalted();
        }
        else
        {
            l_retCode = assertSgpeNotAccessible();
        }
    }

    else if( !iv_CmeState.isCmeOnLine() )
    {
        l_retCode = assertCmeNotAccessible();
    }
    else if( iv_CmeState.isCoreReportingSpecialAttn() )
    {
        l_retCode = assertCoreAttention();
    }
    else if( iv_CmeState.isCmeHcodeHalted() )
    {
        l_retCode = assertCmeHcodeHalt();
    }
    else if ( iv_CmeState.isCmeHalted() )
    {
        l_retCode = assertCmeHalted();
    }
    else if( !iv_CmeState.isPmActive()  && !iv_CmeState.isStopGated() )
    {
        l_retCode = assertCoreRunning();
    }
    else
    {
        l_retCode = assertPmUnknown();
    }

    FAPI_DBG("<< StopFfdcRules::analyze");
    return l_retCode;
}

//----------------------------------------------------------------------------------------------

fapi2::ReturnCode StopFfdcRules::assertSgpeHardwareHalted()
{
    FAPI_DBG( ">> StopFfdcRules::assertSgpeHardwareHalted" );

    //______________________________________________________________________________________________
    // SGPE_HW_HALTED | SGPE State |  CME State   |   CME FFDC Reg  |   SGPE FFDC Reg | Misc
    //                |            |              |                 |                 |
    //                |------------|--------------|-----------------|----------------------------
    //                |  Yes       |   No         |    No           |   Yes           | OCC LFIR
    //                |            |              |                 |                 | SSHSRC Core
    //______________________________________________________________________________________________
    //

    std::vector<uint64_t> l_sgpeBaseAddress;
    fapi2::buffer<uint64_t> l_occLfirBuf;
    fapi2::buffer<uint64_t> l_sshCore[MAX_CORE_PER_QUAD];

    //Since we need to assert RC anyway, we will ignore getScom
    //error and procced all the way till end.

    fapi2::ReturnCode l_retCode = fapi2::FAPI2_RC_SUCCESS;

    l_retCode = getScom( iv_procTgt, OCB_OCCLFIR, l_occLfirBuf );

    if( l_retCode )
    {
        FAPI_ERR("SCOM Error in FFDC Path - Ignoring" );
    }

    uint8_t l_coreId = 0;
    auto l_coreList = iv_eqTgt.getChildren<fapi2::TARGET_TYPE_CORE>( fapi2::TARGET_STATE_PRESENT );

    for( auto core : l_coreList )
    {
        l_sshCore[l_coreId].insert < 0, 64 > ( INIT_BUF_PATT );

        if( core.isFunctional() )
        {
            l_retCode = getScom( core, C_0_PPM_SSHSRC, l_sshCore[l_coreId] );

            if( l_retCode )
            {
                FAPI_ERR("SCOM Error in FFDC Path - Ignoring" );
            }
        }

        l_coreId++;
    }

    l_sgpeBaseAddress.push_back( SGPE_BASE_ADDRESS );

    FAPI_ASSERT( false,
                 fapi2::SGPE_HW_HALTED()
                 .set_EQ_TARGET( iv_eqTgt )
                 .set_CHIP( iv_procTgt )
                 .set_PPE_STATE_MODE( HALT )
                 .set_PPE_BASE_ADDRESS_LIST( l_sgpeBaseAddress )
                 .set_OCC_LFIR( l_occLfirBuf )
                 .set_EDR( iv_SgpeState.getEdrValue() )
                 .set_SSH_CORE_0( l_sshCore[0] )
                 .set_SSH_CORE_1( l_sshCore[1] )
                 .set_SSH_CORE_2( l_sshCore[2] )
                 .set_SSH_CORE_3( l_sshCore[3] ),
                 "SGPE Is Halted Due To HW Error" );

fapi_try_exit:
    FAPI_DBG( "<< StopFfdcRules::assertSgpeHardwareHalted" );
    return fapi2::current_err;
}

//----------------------------------------------------------------------------------------------

fapi2::ReturnCode StopFfdcRules::assertSgpeHcodeHalted( )
{
    FAPI_DBG( ">> StopFfdcRules::assertSgpeHcodeHalted" );
    //______________________________________________________________________________________________
    // SGPE_HCODE_HALTED | SGPE State |  CME State   |   CME FFDC Reg  |   SGPE FFDC Reg | Misc
    //                   |            |              |                 |                 |
    //                   |------------|--------------|-----------------|----------------------------
    //                   |  Yes       |   No         |    No           |   Yes           | OCC LFIR
    //                   |            |              |                 |                 |
    //______________________________________________________________________________________________
    //
    fapi2::buffer<uint64_t> l_occLfirBuf;
    std::vector<uint64_t> l_sgpeBaseAddress;
    fapi2::ReturnCode l_retCode = fapi2::FAPI2_RC_SUCCESS;

    //Since we need to assert RC anyway, we will ignore getScom
    //error and procced all the way till end.
    l_retCode = getScom( iv_procTgt, OCB_OCCLFIR, l_occLfirBuf );

    if( l_retCode )
    {
        FAPI_ERR("SCOM Error in FFDC Path - Ignoring" );
    }

    l_sgpeBaseAddress.push_back( SGPE_BASE_ADDRESS );


    FAPI_ASSERT( false,
                 fapi2::SGPE_HCODE_HALTED()
                 .set_EQ_TARGET( iv_eqTgt )
                 .set_CHIP( iv_procTgt )
                 .set_PPE_STATE_MODE( HALT )
                 .set_PPE_BASE_ADDRESS_LIST( l_sgpeBaseAddress )
                 .set_OCC_LFIR( l_occLfirBuf ),
                 "SGPE Hcode Is Halted" );

fapi_try_exit:
    FAPI_DBG( "<< StopFfdcRules::assertSgpeHcodeHalted" );
    return fapi2::current_err;
}

//----------------------------------------------------------------------------------------------

fapi2::ReturnCode StopFfdcRules::assertCoreAttention()
{
    FAPI_DBG( ">> StopFfdcRules::assertCoreAttention" );

    fapi2::buffer<uint64_t> l_sisrRegVal;
    fapi2::ReturnCode l_retCode = fapi2::FAPI2_RC_SUCCESS;

    //Since we need to assert RC anyway, we will ignore getScom
    //error and procced all the way till end.
    l_retCode = getScom( iv_exTgt, EX_CME_LCL_SISR_SCOM, l_sisrRegVal );

    if( l_retCode )
    {
        FAPI_ERR("SCOM Error in FFDC Path - Ignoring" );
    }

    FAPI_ASSERT( false,
                 fapi2::CORE_ATTENTION()
                 .set_CORE( iv_coreTgt )
                 .set_XSR_VALUE( iv_CmeState.getXsrRegValue() )
                 .set_SISR_VALUE( l_sisrRegVal ),
                 "Core Reporting Special Attention" );

fapi_try_exit:
    FAPI_DBG( "<< StopFfdcRules::assertCoreAttention" );
    return fapi2::current_err;

}

//----------------------------------------------------------------------------------------------

fapi2::ReturnCode StopFfdcRules::assertCmeHcodeHalt()
{
    FAPI_DBG( ">> StopFfdcRules::assertCmeHcodeHalt" );
    //______________________________________________________________________________________________
    // CME_HCODE_HALTED | SGPE State |  CME State   |   CME FFDC Reg  |   SGPE FFDC Reg | Misc
    //                  |            |              |                 |                 |
    //                  |------------|--------------|-----------------|----------------------------
    //                  |  No        |   Yes        |    Yes          |   No            | CME LFIR
    //                  |            |              |                 |                 | Core SSHSRC
    //______________________________________________________________________________________________
    //

    fapi2::buffer<uint64_t> l_sshCore[MAX_CORE_PER_EX];
    fapi2::buffer<uint64_t> l_occLfirBuf;
    fapi2::ReturnCode l_retCode = fapi2::FAPI2_RC_SUCCESS;
    uint8_t l_coreId = 0;
    std::vector<uint64_t> l_cmeBaseAddress;
    l_cmeBaseAddress.push_back( getCmeBaseAddress( iv_CmeState.getCmePosition() ) );

    auto l_coreList = iv_exTgt.getChildren<fapi2::TARGET_TYPE_CORE>( fapi2::TARGET_STATE_PRESENT );
    //Since we need to assert RC anyway, we will ignore getScom
    //error and procced all the way till end.
    l_retCode = getScom( iv_procTgt, OCB_OCCLFIR, l_occLfirBuf );

    if( l_retCode )
    {
        FAPI_ERR("SCOM Error in FFDC Path - Ignoring" );
    }

    for( auto core : l_coreList )
    {
        l_sshCore[l_coreId].insert< 0, 64 >( INIT_BUF_PATT );

        if( core.isFunctional() )
        {
            l_retCode = getScom( core, C_0_PPM_SSHSRC, l_sshCore[l_coreId] );

            if( l_retCode )
            {
                FAPI_ERR("SCOM Error in FFDC Path - Ignoring" );
            }
        }

        l_coreId++;
    }

    FAPI_ASSERT( false,
                 fapi2::CME_HCODE_HALTED()
                 .set_EQ_TARGET( iv_eqTgt )
                 .set_CHIP( iv_procTgt )
                 .set_PPE_STATE_MODE( HALT )
                 .set_PPE_BASE_ADDRESS_LIST( l_cmeBaseAddress )
                 .set_OCC_LFIR( l_occLfirBuf )
                 .set_SSH_CORE_0( l_sshCore[0] )
                 .set_SSH_CORE_1( l_sshCore[1] )
                 .set_EX( iv_exTgt ),
                 "CME Hcode Invoking Halt" );

fapi_try_exit:
    FAPI_DBG( "<< StopFfdcRules::assertCmeHcodeHalt" );
    return fapi2::current_err;

}

//----------------------------------------------------------------------------------------------

fapi2::ReturnCode StopFfdcRules::assertCmeHalted()
{
    FAPI_DBG( ">> StopFfdcRules::assertCmeHalted" );
    //______________________________________________________________________________________________
    // CME_ERROR_HALT   | SGPE State |  CME State   |   CME FFDC Reg  |   SGPE FFDC Reg | Misc
    //                  |            |              |                 |                 |
    //                  |------------|--------------|-----------------|----------------------------
    //                  |  No        |   Yes        |    Yes          |   No            | CME LFIR,
    //                  |            |              |                 |                 | Core SSHSRC,
    //                  |            |              |                 |                 | GPMMR, CPMMR
    //______________________________________________________________________________________________
    //
    fapi2::buffer<uint64_t> l_sshCore[MAX_CORE_PER_EX];
    fapi2::buffer<uint64_t> l_cpmmr[MAX_CORE_PER_EX];
    fapi2::buffer<uint64_t> l_gpmmr[MAX_CORE_PER_EX];
    fapi2::buffer<uint64_t> l_netCtrl[MAX_CORE_PER_EX];
    fapi2::buffer<uint64_t> l_occLfirBuf;
    fapi2::ReturnCode l_retCode = fapi2::FAPI2_RC_SUCCESS;
    uint8_t l_coreId = 0;
    std::vector<uint64_t> l_cmeBaseAddress;
    l_cmeBaseAddress.push_back( getCmeBaseAddress( iv_CmeState.getCmePosition() ) );

    //Since we need to assert RC anyway, we will ignore getScom
    //error and procced all the way till end.
    l_retCode = getScom( iv_procTgt, OCB_OCCLFIR, l_occLfirBuf );

    if( l_retCode )
    {
        FAPI_ERR("SCOM Error in FFDC Path - Ignoring" );
    }

    auto l_coreList = iv_exTgt.getChildren<fapi2::TARGET_TYPE_CORE>( fapi2::TARGET_STATE_PRESENT );

    for( auto core : l_coreList )
    {
        l_sshCore[l_coreId].insert < 0, 64 >( INIT_BUF_PATT );
        l_cpmmr[l_coreId].insert   < 0, 64 >( INIT_BUF_PATT );
        l_gpmmr[l_coreId].insert   < 0, 64 >( INIT_BUF_PATT );
        l_netCtrl[l_coreId].insert < 0, 64 >( INIT_BUF_PATT );

        if( core.isFunctional() )
        {
            getScom( core, C_0_PPM_SSHSRC,   l_sshCore[l_coreId] );
            getScom( core, C_CPPM_CPMMR,     l_cpmmr[l_coreId] );
            getScom( core, C_PPM_GPMMR_SCOM, l_gpmmr[l_coreId] );
            getScom( core, C_NET_CTRL0,      l_netCtrl[l_coreId] );

        }

        l_coreId++;
    }

    FAPI_ASSERT( false,
                 fapi2::CME_ERROR_HALT()
                 .set_EQ_TARGET( iv_eqTgt )
                 .set_CHIP( iv_procTgt )
                 .set_EX( iv_exTgt )
                 .set_PPE_STATE_MODE( HALT )
                 .set_PPE_BASE_ADDRESS_LIST( l_cmeBaseAddress )
                 .set_OCC_LFIR( l_occLfirBuf )
                 .set_NET_CTRL0( l_netCtrl[0] )
                 .set_NET_CTRL1( l_netCtrl[1] )
                 .set_CPMMR_0( l_cpmmr[0] )
                 .set_CPMMR_1( l_cpmmr[1] )
                 .set_GPMMR_0( l_gpmmr[0] )
                 .set_GPMMR_1( l_gpmmr[1] )
                 .set_SSH_CORE_0( l_sshCore[0] )
                 .set_SSH_CORE_1( l_sshCore[1] ),
                 "CME Halted Due To HW Error" );

fapi_try_exit:
    FAPI_DBG( "<< StopFfdcRules::assertCmeHalted" );
    return fapi2::current_err;

}

//----------------------------------------------------------------------------------------------

fapi2::ReturnCode StopFfdcRules::assertCmeNotAccessible()
{
    FAPI_DBG( ">> StopFfdcRules::assertCmeNotAccessible" );
    FAPI_ASSERT( false,
                 fapi2::CME_NOT_ACCESSIBLE()
                 .set_CHIP( iv_procTgt ),
                 "CME Is Not Accessible" );

fapi_try_exit:
    FAPI_DBG( "<< StopFfdcRules::assertCmeNotAccessible" );
    return fapi2::current_err;
}

//----------------------------------------------------------------------------------------------

fapi2::ReturnCode StopFfdcRules::assertSgpeNotAccessible()
{
    FAPI_DBG( ">> StopFfdcRules::assertSgpeNotAccessible" );
    FAPI_ASSERT( false,
                 fapi2::SGPE_NOT_ACCESSIBLE()
                 .set_CHIP( iv_procTgt ),
                 "SGPE Is Not Accessible" );

fapi_try_exit:
    FAPI_DBG( "<< StopFfdcRules::assertSgpeNotAccessible" );
    return fapi2::current_err;
}

//----------------------------------------------------------------------------------------------

fapi2::ReturnCode StopFfdcRules::assertCoreRunning()
{
    FAPI_DBG( ">> StopFfdcRules::assertCoreRunning" );

    FAPI_ASSERT( false,
                 fapi2::CORE_POWERED_AND_RUNNING(),
                 "Core(s) Is Not In Any STOP State And Running" );

fapi_try_exit:
    FAPI_DBG( "<< StopFfdcRules::assertCoreRunning" );
    return fapi2::current_err;
}

//----------------------------------------------------------------------------------------------

fapi2::ReturnCode StopFfdcRules::assertPmUnknown()
{
    FAPI_DBG( ">> StopFfdcRules::assertPmUnknown" );
    //______________________________________________________________________________________________
    // UNKNOWN_PM_STATE | SGPE State |  CME State   |   CME FFDC Reg  |   SGPE FFDC Reg | Misc
    //                  |            |              |                 |                 |
    //                  |------------|--------------|-----------------|----------------------------
    //                  |  No        |   Yes        |    Yes          |   No            | CME LFIR,
    //                  |            |              |                 |                 | Core SSHSRC,
    //                  |            |              |                 |                 | GPMMR, CPMMR,
    //                  |            |              |                 |                 | NetCtrl0
    //______________________________________________________________________________________________
    //
    fapi2::buffer<uint64_t> l_sshCore[MAX_CORE_PER_EX];
    fapi2::buffer<uint64_t> l_cpmmr[MAX_CORE_PER_EX];
    fapi2::buffer<uint64_t> l_gpmmr[MAX_CORE_PER_EX];
    fapi2::buffer<uint64_t> l_netCtrl[MAX_CORE_PER_EX];
    fapi2::buffer<uint64_t> l_occLfirBuf;
    fapi2::ReturnCode l_retCode = fapi2::FAPI2_RC_SUCCESS;

    uint8_t l_coreId = 0;
    std::vector<uint64_t> l_cmeBaseAddress;
    l_cmeBaseAddress.push_back( getCmeBaseAddress( iv_CmeState.getCmePosition() ) );

    auto l_coreList = iv_exTgt.getChildren<fapi2::TARGET_TYPE_CORE>( fapi2::TARGET_STATE_PRESENT );
    //Since we need to assert RC anyway, we will ignore getScom
    //error and procced all the way till end.
    //
    l_retCode = getScom( iv_procTgt, OCB_OCCLFIR, l_occLfirBuf );

    if( l_retCode )
    {
        FAPI_ERR("SCOM Error in FFDC Path - Ignoring" );
    }

    for( auto core : l_coreList )
    {
        l_sshCore[l_coreId].insert( INIT_BUF_PATT, 0, 64 );
        l_cpmmr[l_coreId].insert( INIT_BUF_PATT, 0, 64 );
        l_gpmmr[l_coreId].insert( INIT_BUF_PATT, 0, 64 );
        l_netCtrl[l_coreId].insert( INIT_BUF_PATT, 0, 64 );

        if( core.isFunctional() )
        {
            getScom( core, C_0_PPM_SSHSRC,   l_sshCore[l_coreId] );
            getScom( core, C_CPPM_CPMMR,     l_cpmmr[l_coreId] );
            getScom( core, C_PPM_GPMMR_SCOM, l_gpmmr[l_coreId] );
            getScom( core, C_NET_CTRL0,      l_netCtrl[l_coreId] );
        }

        l_coreId++;
    }

    FAPI_ASSERT( false,
                 fapi2::CME_ERROR_HALT()
                 .set_EQ_TARGET( iv_eqTgt )
                 .set_CHIP( iv_procTgt )
                 .set_EX( iv_exTgt )
                 .set_PPE_STATE_MODE( HALT )
                 .set_PPE_BASE_ADDRESS_LIST( l_cmeBaseAddress )
                 .set_OCC_LFIR( l_occLfirBuf )
                 .set_NET_CTRL0( l_netCtrl[0] )
                 .set_NET_CTRL1( l_netCtrl[1] )
                 .set_CPMMR_0( l_cpmmr[0] )
                 .set_CPMMR_1( l_cpmmr[1] )
                 .set_GPMMR_0( l_gpmmr[0] )
                 .set_GPMMR_1( l_gpmmr[1] )
                 .set_SSH_CORE_0( l_sshCore[0] )
                 .set_SSH_CORE_1( l_sshCore[1] ),
                 "An Unknown Problem In PM Complex" );

fapi_try_exit:
    FAPI_DBG( "<< StopFfdcRules::assertPmUnknown" );
    return fapi2::current_err;
}

//----------------------------------------------------------------------------------------------

fapi2::ReturnCode p9_check_idle_stop_done( const fapi2::Target< fapi2::TARGET_TYPE_CORE >& i_coreTgt )
{
    FAPI_IMP( ">> p9_check_idle_stop_done ");

    fapi2::ReturnCode l_retCode = fapi2::FAPI2_RC_SUCCESS;

    StopFfdcRules l_idleStopState( i_coreTgt );

    //Ignoring return code here, so that based on available information,
    //best possible assessment of situation can be attempted.

    l_retCode = l_idleStopState.init();

    FAPI_TRY( l_idleStopState.analyze(),
              "Analysis Of PM Complex Done" );
fapi_try_exit:

    FAPI_IMP( "<< p9_check_idle_stop_done ");
    return fapi2::current_err;
}

} //namespace p9_check_idle_stop ends
