/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep06/call_host_voltage_config.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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
#include <stdint.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>
#include <fapi2.H>
#include <fapi2/plat_hwp_invoker.H>
#include <arch/pirformat.H>
#include <sys/task.h>
#include <sys/mmio.h>
#include <arch/pvrformat.H>


//Targeting
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/util.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/target.H>

#include    <p9_pm_get_poundv_bucket_attr.H>
#include    <p9_pm_get_poundv_bucket.H>
#include    <p9_setup_evid.H>
#include    <p9_frequency_buckets.H>

#include    <util/utilmbox_scratch.H>
#include    <vpd/mvpdenums.H>

using namespace TARGETING;


namespace ISTEP_06
{

/**
 * @brief This function will query MVPD and get the #V data for the
 *        master core
 *
 * @return errlHndl_t -- returns error if it can't get to MVPDe.
*/
errlHndl_t get_first_valid_pdV_pbFreq(uint32_t& o_firstPBFreq)
{
    //#V Keyword in LPRx Record of MVPD contains the info we need
    //the x in LPRx is the EQ number.
    errlHndl_t  l_errl  =   NULL;
    uint64_t theRecord = 0x0;
    uint64_t theKeyword = MVPD::pdV;
    uint8_t * theData = NULL;
    size_t theSize = 0;
    TARGETING::Target* l_procTarget = NULL;
    uint64_t cpuid = task_getcpuid();
    uint64_t l_masterCoreId = PIR_t::coreFromPir(cpuid);
    o_firstPBFreq = 0;

    do {
        // Target: Find the Master processor
        TARGETING::targetService().masterProcChipTargetHandle(l_procTarget);
        assert(l_procTarget != NULL);

        //Convert core number to LPRx Record ID.
        //TODO: use a common utility function for conversion. RTC: 60552
        switch (l_masterCoreId)
        {
        case 0x00:
        case 0x01:
        case 0x02:
        case 0x03:
        default:    // if not anything else try LRP0
            theRecord = MVPD::LRP0;
            break;
        case 0x04:
        case 0x05:
        case 0x06:
        case 0x07:
            theRecord = MVPD::LRP1;
            break;
        case 0x08:
        case 0x09:
        case 0x0A:
        case 0x0B:
            theRecord = MVPD::LRP2;
            break;
        case 0x0C:
        case 0x0D:
        case 0x0E:
        case 0x0F:
            theRecord = MVPD::LRP3;
            break;
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
            theRecord = MVPD::LRP4;
            break;
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
            theRecord = MVPD::LRP5;
            break;
        }

        //First call is just to get the Record size.
        l_errl = deviceRead(l_procTarget,
                          NULL,
                          theSize,
                          DEVICE_MVPD_ADDRESS( theRecord,
                                               theKeyword ) );

        if (l_errl) { break; }

        //2nd call is to get the actual data.
        theData = static_cast<uint8_t*>(malloc( theSize ));
        l_errl = deviceRead(l_procTarget,
                          theData,
                          theSize,
                          DEVICE_MVPD_ADDRESS( theRecord,
                                               theKeyword ) );
        if( l_errl ) { break; }


        //Version 3:
        //#V record is laid out as follows:
        //Name:     0x2 byte
        //Length:   0x2 byte
        //Version:  0x1 byte **buffer starts here
        //PNP:      0x3 byte
        //bucket a: 0x3D byte
        //bucket b: 0x3D byte
        //bucket c: 0x3D byte
        //bucket d: 0x3D byte
        //bucket e: 0x3D byte
        //bucket f: 0x3D byte
        if( *theData == POUNDV_VERSION_3 )
        {
            //cast the voltage data into an array of buckets
            fapi2::voltageBucketData_t* l_buckets = reinterpret_cast
                                              <fapi2::voltageBucketData_t*>
                                              (theData + POUNDV_BUCKET_OFFSET);

            for(int i = 0; i < NUM_BUCKETS; i++)
            {
                //To be valid the bucketId must be set (!=0) and pbFreq !=0
                if((l_buckets[i].bucketId != 0) && (l_buckets[i].pbFreq != 0))
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              "First valid #V bucket[%x], pbus_freq %d",
                              l_buckets[i].bucketId, l_buckets[i].pbFreq);
                    o_firstPBFreq = l_buckets[i].pbFreq;
                    break;
                }
            }
        }
        else
        {
            //emit trace for debug, but not finding pbus freq is not fatal
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "Invalid #V version, default powerbus freq to boot freq");
        }
    } while(0);

    free(theData);
    return l_errl;
}


errlHndl_t determineNestFreq( uint32_t& o_nestFreq )
{
    errlHndl_t l_err = nullptr;
    o_nestFreq = 0x0;

    TARGETING::Target * l_sys = nullptr;
    (void) TARGETING::targetService().getTopLevelTarget( l_sys );
    assert( l_sys, "determineNestFreq() system target is NULL");

    do
    {
        // Set the Nest frequency to whatever we boot with
        // Note that all freq are supported in the nest pll buckets
        // so we can safely customize to any -- however #V may only
        // contain a subset.  Instead of defaulting to the freq
        // we booted with, target the freq we intend to run at:
        //
        // ATTR_REQUIRED_SYNCH_MODE == --> memory freq forces the nest freq,
        //                  thus default to whatever we booted with
        // ATTR_ASYNC_NEST_FREQ_MHZ != 0xFFFF --> System owner wants
        //                  specified ASYNC freq to be the default
        // ATTR_ASYNC_NEST_FREQ_MHZ == 0xFFFF --> System owner wants
        //                  Nest freq to be determined by 1st valid #V
        //                  bucket
        //

        //Default to the boot freq
        o_nestFreq = Util::getBootNestFreq();
        PVR_t l_pvr( mmio_pvr_read() & 0xFFFFFFFF );

        if(l_sys->getAttr<ATTR_REQUIRED_SYNCH_MODE>() == 0x1) //ALWAYS
        {
            //Leave nest freq as is, istep 7 will handle
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "call_host_voltage_config.C::"
                      "REQUIRED_SYNCH_MODE = 0x1, nest at boot %d Mhz",
                      o_nestFreq);
        }
        else if (l_sys->getAttr<ATTR_ASYNC_NEST_FREQ_MHZ>() != 0xFFFF)
        {
            o_nestFreq = l_sys->getAttr<ATTR_ASYNC_NEST_FREQ_MHZ>();
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "call_host_voltage_config.C::"
                      "ASYNC Freq specified by MRW, using %d Mhz",
                      o_nestFreq);
        }
        //Nimbus DD1.0 parts don't handle this well, if DD1 and
        //ATTR_ASYNC_NEST_FREQ_MHZ == 0xFFFF, force to 2.0Ghz
        else if ((l_sys->getAttr<ATTR_ASYNC_NEST_FREQ_MHZ>() == 0xFFFF)
                 && l_pvr.isNimbusDD1() )
        {
            o_nestFreq = 2000;
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "call_host_voltage_config.C::"
                      "ASYNC Freq to be determined by #V, but Nimbus DD1.0"
                      " -- force to 2000 Mhz");
        }
        else
        {
            uint32_t l_pdV_nestFreq = 0x0;
            l_err = get_first_valid_pdV_pbFreq( l_pdV_nestFreq );
            if( l_err )
            {
                //Fatal error on VPD access
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "call_host_voltage_config.C::"
                          "Failed to get nest freq from VPD");
                break;
            }
            else if (l_pdV_nestFreq != 0)
            {
                //got a valid freq
                o_nestFreq = l_pdV_nestFreq;
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "call_host_voltage_config.C::"
                          "First valid #V controls freq, found %d Mhz",
                          o_nestFreq);
            }
        }

        l_sys->setAttr<TARGETING::ATTR_FREQ_PB_MHZ>(o_nestFreq);

    }while( 0 );

    return l_err;
}


void* call_host_voltage_config( void *io_pArgs )
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_voltage_config entry" );

    ISTEP_ERROR::IStepError l_stepError;

    errlHndl_t l_err = nullptr;
    Target * l_sys = nullptr;
    TargetHandleList l_procList;
    TargetHandleList l_eqList;
    fapi2::voltageBucketData_t l_voltageData;
    fapi2::ReturnCode l_rc;

    uint32_t l_nominalFreq = 0;     //ATTR_NOMINAL_FREQ_MHZ
    uint32_t l_floorFreq = 0;       //ATTR_FREQ_FLOOR_MHZ
    uint32_t l_ceilingFreq = 0;     //ATTR_FREQ_CORE_CEILING_MHZ
    uint32_t l_ultraTurboFreq = 0;  //ATTR_ULTRA_TURBO_FREQ_MHZ
    uint32_t l_turboFreq = 0;       //ATTR_FREQ_CORE_MAX
    uint32_t l_nestFreq = 0;        //ATTR_FREQ_PB_MHZ
    uint32_t l_powerModeNom = 0;    //ATTR_SOCKET_POWER_NOMINAL
    uint32_t l_powerModeTurbo = 0;  //ATTR_SOCKET_POWER_TURBO

    bool l_firstPass = true;

    PredicateCTM l_eqFilter(CLASS_UNIT, TYPE_EQ);
    PredicateHwas l_predPres;
    l_predPres.present(true);
    PredicatePostfixExpr l_presentEqs;
    l_presentEqs.push(&l_eqFilter).push(&l_predPres).And();


    do
    {
        // Get the system target
        targetService().getTopLevelTarget(l_sys);

        // Set the Nest frequency based on ATTR
        l_err = determineNestFreq(l_nestFreq);
        if( l_err )
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "call_host_voltage_config.C::"
                      "Failed setting the nest frequency");
            break;
        }

        // Get the child proc chips
        getChildAffinityTargets( l_procList,
                                 l_sys,
                                 CLASS_CHIP,
                                 TYPE_PROC );

        // for each proc target
        for( const auto & l_proc : l_procList )
        {
            //Nimbus DD1 only supports XBUS with freq 1800MHz
            //DD2 supports 2000MHz freq
            //ATTR_CHIP_EC_FEATURE_HW393297 is used to pick the lower
            //freq for dd1 chips
            fapi2::ATTR_CHIP_EC_FEATURE_HW393297_Type l_dd1_xbus_pll;
            FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW393297, l_proc,
                        l_dd1_xbus_pll);
            if (l_dd1_xbus_pll)
            {
                l_sys->setAttr<ATTR_FREQ_X_MHZ>( 1800 );
            }
            else
            {
                l_sys->setAttr<ATTR_FREQ_X_MHZ>( 2000 );
            }
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "call_host_voltage_config.C::"
                    "ATTR_FREQ_X_MHZ = %d",
                    l_sys->getAttr<ATTR_FREQ_X_MHZ>());

            //Nimbus DD21 only supports OBUS PLL of 1563(versus product of 1611)
            //Force it because of a chip bug instead of letting MRW control
            PVR_t l_pvr( mmio_pvr_read() & 0xFFFFFFFF );
            if( l_pvr.isNimbusDD21() )
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "call_host_voltage_config.C::"
                          "Nimbus DD2.1 -- Forcing ATTR_FREQ_X_MHZ = %d",
                          l_sys->getAttr<ATTR_FREQ_X_MHZ>());

                TARGETING::ATTR_FREQ_O_MHZ_type l_freq_array =
                {OBUS_PLL_FREQ_LIST_P9N_21[0],OBUS_PLL_FREQ_LIST_P9N_21[0],
                OBUS_PLL_FREQ_LIST_P9N_21[0], OBUS_PLL_FREQ_LIST_P9N_21[0]};
                assert(l_proc->
                       trySetAttr<TARGETING::ATTR_FREQ_O_MHZ>(l_freq_array),
                       "call_host_voltage_config.C failed to set ATTR_FREQ_O_MHZ");
            }


            // get the child EQ targets
            targetService().getAssociated(
                    l_eqList,
                    l_proc,
                    TargetService::CHILD_BY_AFFINITY,
                    TargetService::ALL,
                    &l_presentEqs );


            if( l_eqList.empty() )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "No children of proc 0x%x found to have type EQ",
                        get_huid(l_proc));



                /*@
                 * @errortype
                 * @moduleid    ISTEP::MOD_VOLTAGE_CONFIG
                 * @reasoncode  ISTEP::RC_NO_PRESENT_EQS
                 * @userdata1   Parent PROC huid
                 * @devdesc     No present EQs found on processor
                 * @custdesc    A problem occurred during the IPL of the system.
                 */
                l_err = new ERRORLOG::ErrlEntry
                        (ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                         ISTEP::MOD_VOLTAGE_CONFIG,
                         ISTEP::RC_NO_PRESENT_EQS,
                         get_huid(l_proc),
                         0,
                         true /*HB SW error*/ );
                l_err->addHwCallout(l_proc,
                                    HWAS::SRCI_PRIORITY_HIGH,
                                    HWAS::NO_DECONFIG,
                                    HWAS::GARD_NULL );

                // We will allow this for the lab as long as this isn't the
                //  master processor
                TARGETING::Target* l_masterProc = NULL;
                targetService().masterProcChipTargetHandle( l_masterProc );
                if( l_masterProc == l_proc )
                {
                    break;
                }

                // Commit Error
                errlCommit( l_err, ISTEP_COMP_ID );

                continue;
            }
            //  for each child EQ target
            for( const auto & l_eq : l_eqList )
            {
                // cast to fapi2 target
                fapi2::Target<fapi2::TARGET_TYPE_EQ> l_fapiEq( l_eq );

                // get the #V data for this EQ
                FAPI_INVOKE_HWP( l_err,
                                 p9_pm_get_poundv_bucket,
                                 l_fapiEq,
                                 l_voltageData);

                if( l_err )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                            "Error in call_host_voltage_config::p9_pm_get_poundv_bucket");

                    // Create IStep error log and cross reference occurred error
                    l_stepError.addErrorDetails( l_err );

                    // Commit Error
                    errlCommit( l_err, ISTEP_COMP_ID );

                    continue;
                }

                // Save the freq data for future comparison
                if( l_firstPass )
                {
                    l_nominalFreq = l_voltageData.nomFreq;
                    l_floorFreq = l_voltageData.PSFreq;
                    l_ceilingFreq = l_voltageData.turboFreq;
                    l_ultraTurboFreq = l_voltageData.uTurboFreq;
                    l_turboFreq = l_voltageData.turboFreq;
                    l_powerModeNom = l_voltageData.SortPowerNorm;
                    l_powerModeTurbo = l_voltageData.SortPowerTurbo;
                    l_firstPass = false;
                }
                else
                {
                    // save it to variable and compare against other nomFreq
                    // All of the buckets should report the same Nominal frequency
                    if( l_nominalFreq != l_voltageData.nomFreq )
                    {
                        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                                "NOMINAL FREQ MISMATCH! expected: %d actual: %d",
                                l_nominalFreq, l_voltageData.nomFreq );

                        /*@
                        * @errortype
                        * @moduleid    ISTEP::MOD_VOLTAGE_CONFIG
                        * @reasoncode  ISTEP::RC_NOMINAL_FREQ_MISMATCH
                        * @userdata1   Previous EQ nominal frequency
                        * @userdata2   Current EQ nominal frequency
                        * @devdesc     Nominal Frequency mismatch
                        * @custdesc    A problem occurred during the IPL of the system.
                        */
                        l_err = new ERRORLOG::ErrlEntry
                            (ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                             ISTEP::MOD_VOLTAGE_CONFIG,
                             ISTEP::RC_NOMINAL_FREQ_MISMATCH,
                             l_nominalFreq,
                             l_voltageData.nomFreq,
                             false );

                        l_err->addHwCallout(l_proc,
                                            HWAS::SRCI_PRIORITY_HIGH,
                                            HWAS::DECONFIG,
                                            HWAS::GARD_NULL );

                        // Create IStep error log and
                        // cross reference occurred error
                        l_stepError.addErrorDetails( l_err );

                        // Commit Error
                        errlCommit( l_err, ISTEP_COMP_ID );

                        continue;
                    }

                    // All of the buckets should report the same Sort Power
                    if( (l_powerModeNom != l_voltageData.SortPowerNorm) ||
                        (l_powerModeTurbo != l_voltageData.SortPowerTurbo) )
                    {
                        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                                "Power Mode MISMATCH! "
                                "expected Nominal %d actual Nominal %d "
                                "expected Turbo %d actual Turbo %d",
                                l_powerModeNom, l_voltageData.SortPowerNorm,
                                l_powerModeTurbo, l_voltageData.SortPowerTurbo);

                        /*@
                        * @errortype
                        * @moduleid    ISTEP::MOD_VOLTAGE_CONFIG
                        * @reasoncode  ISTEP::RC_POWER_MODE_MISMATCH
                        * @userdata1[00:31]  Previous EQ nominal power mode
                        * @userdata1[32:63]  Current EQ nominal power mode
                        * @userdata2[00:31]  Previous EQ turbo power mode
                        * @userdata2[32:63]  Current EQ turbo power mode
                        * @devdesc     Power Mode mismatch
                        * @custdesc    A problem occurred during the IPL of the system.
                        */
                        l_err = new ERRORLOG::ErrlEntry
                            (ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                             ISTEP::MOD_VOLTAGE_CONFIG,
                             ISTEP::RC_POWER_MODE_MISMATCH,
                             TWO_UINT32_TO_UINT64(
                                l_powerModeNom,
                                l_voltageData.SortPowerNorm),
                             TWO_UINT32_TO_UINT64(
                                l_powerModeTurbo,
                                l_voltageData.SortPowerTurbo),
                             false );

                        l_err->addHwCallout(l_proc,
                                            HWAS::SRCI_PRIORITY_HIGH,
                                            HWAS::DECONFIG,
                                            HWAS::GARD_NULL );

                        // Create IStep error log and
                        // cross reference occurred error
                        l_stepError.addErrorDetails( l_err );

                        // Commit Error
                        errlCommit( l_err, ISTEP_COMP_ID );

                        continue;
                    }

                    // Floor frequency is the maximum of the Power Save Freqs
                    l_floorFreq =
                    (l_voltageData.PSFreq > l_floorFreq) ? l_voltageData.PSFreq : l_floorFreq;

                    // Ceiling frequency is the minimum of the Turbo Freqs
                    l_ceilingFreq = (l_voltageData.turboFreq < l_ceilingFreq) ?
                     l_voltageData.turboFreq : l_ceilingFreq;

                    // Ultra Turbo frequency is the minimum of the Ultra Turbo Freqs
                    l_ultraTurboFreq = (l_voltageData.uTurboFreq < l_ultraTurboFreq) ?
                     l_voltageData.uTurboFreq : l_ultraTurboFreq;

                    // Turbo frequency is the minimum of the Turbo Freqs
                    l_turboFreq = l_ceilingFreq;
                }

                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "Proc %.8X Freq from #V: "
                          "Powersave = %d Turbo = %d, UltraTurbo = %d",
                          TARGETING::get_huid(l_proc),
                          l_voltageData.PSFreq,
                          l_voltageData.turboFreq,
                          l_voltageData.uTurboFreq );

            } // EQ for-loop

            // Don't set the boot voltage ATTR -- instead the
            // setup_evid will calculate from each chips #V and factor
            // in loadline/distloss/etc
        } // PROC for-loop

        // If we hit an error from p9_setup_evid, quit
        if( l_err )
        {
            break;
        }

        // set the frequency system targets
        l_sys->setAttr<ATTR_NOMINAL_FREQ_MHZ>( l_nominalFreq );

        // raise the min freq if there is a system policy for it
        int32_t l_dpoPercent = l_sys->getAttr<ATTR_DPO_MIN_FREQ_PERCENT>();
        uint32_t l_dpoFreq = l_nominalFreq;
        if( (l_dpoPercent != 0) && (l_dpoPercent > -100) )
        {
            uint32_t l_multiplierPercent =
                static_cast<uint32_t>(100 + l_dpoPercent);
            l_dpoFreq = (l_nominalFreq*l_multiplierPercent)/100;
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "Computed floor=%d, DPO=%d (percent=%d)",
                      l_floorFreq, l_dpoFreq, l_dpoPercent );
            l_floorFreq = std::max( l_floorFreq, l_dpoFreq );
        }

        l_sys->setAttr<ATTR_MIN_FREQ_MHZ>( l_floorFreq );

        l_sys->setAttr<ATTR_FREQ_CORE_CEILING_MHZ>( l_ceilingFreq );

        l_sys->setAttr<ATTR_FREQ_CORE_MAX>( l_turboFreq );

        l_sys->setAttr<ATTR_ULTRA_TURBO_FREQ_MHZ>(l_ultraTurboFreq);

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "Setting System Frequency Attributes: "
                "Nominal = %d, Floor = %d, Ceiling = %d, "
                "Turbo = %d, UltraTurbo = %d",
                l_nominalFreq, l_floorFreq, l_ceilingFreq,
                l_turboFreq, l_ultraTurboFreq );

        // Setup the remaining attributes that are based on PB/Nest
        TARGETING::setFrequencyAttributes(l_sys,
                                          l_nestFreq);

        l_sys->setAttr<ATTR_SOCKET_POWER_NOMINAL>(l_powerModeNom);
        l_sys->setAttr<ATTR_SOCKET_POWER_TURBO>(l_powerModeTurbo);


        // for each proc target
        for( const auto & l_proc : l_procList )
        {
            // call p9_setup_evid for each processor
            fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>l_fapiProc(l_proc);
            FAPI_INVOKE_HWP(l_err, p9_setup_evid, l_fapiProc, COMPUTE_VOLTAGE_SETTINGS);

            if( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "Error in call_host_voltage_config::p9_setup_evid");

                // Create IStep error log and cross reference occurred error
                l_stepError.addErrorDetails( l_err );

                // Commit Error
                errlCommit( l_err, ISTEP_COMP_ID );
                continue;
            }

        } // PROC for-loop

        // If we hit an error from p9_setup_evid, quit
        if( l_err )
        {
            break;
        }


    } while( 0 );

    if( l_err )
    {
        // Create IStep error log and cross reference occurred error
        l_stepError.addErrorDetails( l_err );

        // Commit Error
        errlCommit( l_err, ISTEP_COMP_ID );

    }
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_voltage_config exit" );

    return l_stepError.getErrorHandle();
}

};
