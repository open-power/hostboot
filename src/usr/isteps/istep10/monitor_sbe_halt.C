/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep10/monitor_sbe_halt.C $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
 * @file monitor_sbe_halt.C
 *
 *  Source code to monitor SBEs that have been put in halt state.
 *  This is for security reasons since the FSP/BMC could hreset the SBE
 *  while in the halt state.
 *
 */
#include "monitor_sbe_halt.H"

#include  <initservice/taskargs.H>

// System
#include  <sys/sync.h>
#include  <sys/time.h>

// Kernel checkstop
#include <kernel/machchk.H>

//  targeting support
#include   <targeting/common/commontargeting.H>
#include   <targeting/common/utilFilter.H>
#include   <targeting/common/target.H>

// Error log
#include  <errl/errlentry.H>
#include  <errl/errlmanager.H>
#include  <isteps/istep_reasoncodes.H>

// Trace
#include  <hbotcompid.H> // SECURE_COMP_ID
#include  <trace/interface.H>

// Scoms
#include  <p10_scom_perv_a.H>
#include  <p10_scom_proc.H>

#include <list> // std::list

using namespace TARGETING;
using namespace ERRORLOG;
using namespace scomt::perv;

namespace MONITOR_SBE_HALT
{
const char SBE_HALT_CHK_NAME[] = "SBE_HALT_CHECK";

// Initialize the trace buffer for this component
trace_desc_t* g_trac_sbehalt_chk  = nullptr;
TRAC_INIT(&g_trac_sbehalt_chk, SBE_HALT_CHK_NAME, 2*KILOBYTE);

// List and its mutex of halted SBEs to monitor
mutex_t g_sbeHalt_mutex = MUTEX_INITIALIZER;
std::list<TargetHandle_t> g_halted_sbe_list;
// flag to prevent multiple monitoring threads
bool g_halt_monitor_running = false;

// List and its mutex of bad SBEs that need to be stopped via Secure Debug bit
mutex_t g_unsecured_sbe_mutex = MUTEX_INITIALIZER;
std::list<TargetHandle_t> g_unsecured_sbes;

// function prototypes (see functions below for more details)
void * monitorSbeHalt(void * i_p); // main monitoring thread
void addUnsecuredSbe(TargetHandle_t i_sbeProc);

////////////////////////////////////////////////////////////////////////////////
// External Functions
////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Remove SBE processor from halt monitor list
 * @param[in] processor target to remove
 */
void removeSbeProc(TargetHandle_t i_sbe_proc)
{
    mutex_lock(&g_sbeHalt_mutex);
    TRACFCOMP( g_trac_sbehalt_chk,
               "removeSbeProc: removing 0x%.8X proc SBE from halt monitor",
               get_huid(i_sbe_proc) );
    g_halted_sbe_list.remove(i_sbe_proc);
    mutex_unlock(&g_sbeHalt_mutex);
}

/**
 * @brief Add SBE processor to halt monitor list
 *        If this is the first one added, it will also start the monitoring thread
 * @param[in] processor target to add
 */
void addSbeProc(TargetHandle_t i_sbe_proc)
{
    mutex_lock(&g_sbeHalt_mutex);
    TRACFCOMP( g_trac_sbehalt_chk,
               "addSbeProc: adding 0x%.8X proc SBE to halt monitor",
               get_huid(i_sbe_proc) );
    g_halted_sbe_list.push_back(i_sbe_proc);

    // Start up the monitor thread if one isn't already running
    if ((!g_halt_monitor_running) && (g_halted_sbe_list.size() == 1))
    {
        g_halt_monitor_running = true;
        task_create(&monitorSbeHalt, nullptr);
    }
    mutex_unlock(&g_sbeHalt_mutex);
}

/**
 * @brief Stop monitoring any SBE processors for resumed activity
 *        Removing all targets from monitor list should result in thread exit
 */
void stopSbeHaltMonitor()
{
    mutex_lock(&g_sbeHalt_mutex);
    // just remove all the monitored elements
    g_halted_sbe_list.clear();
    mutex_unlock(&g_sbeHalt_mutex);
}
////////////////////////////////////////////////////////////////////////////////


/**
 * @brief Check to see if Self-Boot Engine[SBE] Attention is set
 *        indicating that SBE is halted
 *
 * @param[in] i_sbeProc processor target for SBE
 * @param[out] o_regData TP.TPVSB.FSI.W.FSI2PIB.STATUS register data
 *
 * @return true if SBE attention bit set, else false
 */
bool checkSbeAttn(TargetHandle_t i_sbeProc, uint32_t & o_regData)
{
    bool l_sbeAttn = false;
    errlHndl_t l_errl = nullptr;
    uint32_t l_status_data = 0;
    size_t l_32bitSize = sizeof(l_status_data);

    // Read TP.TPVSB.FSI.W.FSI2PIB.STATUS register (0x00001007ull)
    l_errl = deviceOp(DeviceFW::READ,
                      i_sbeProc,
                      &l_status_data,
                      l_32bitSize,
                      DEVICE_FSI_ADDRESS(scomt::proc::TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));

    // only check SBE bit on successful read
    if (!l_errl)
    {
        // check SELFBOOT_ENGINE_ATTENTION bit (30)
        uint32_t checkBit = 0x80000000 >> scomt::proc::TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION;
        if (l_status_data & checkBit)
        {
            l_sbeAttn = true;
        }
        else
        {
            TRACFCOMP( g_trac_sbehalt_chk,
               "checkSbeAttn: 0x%.8X proc SBE is NOT at SBE attn (0x%08X PSI2PIB_STATUS)",
               get_huid(i_sbeProc), l_status_data );
            l_sbeAttn = false;
        }
    }
    else
    {
        TRACFCOMP( g_trac_sbehalt_chk,
               "checkSbeAttn: unable to read TP.TPVSB.FSI.W.FSI2PIB.STATUS register for 0x%.8X proc",
               get_huid(i_sbeProc) );
        l_errl->collectTrace(SBE_HALT_CHK_NAME);
        l_errl->collectTrace(ISTEP_COMP_NAME, 256);
        l_errl->collectTrace(SBE_COMP_NAME, 256);
        errlCommit(l_errl, ISTEP_COMP_ID);
        l_sbeAttn = false; // only return true if we read it
    }
    o_regData = l_status_data;
    return l_sbeAttn;
}

/**
 * @brief Main monitoring thread that checks that SBEs have not come out of halt state
 *        Relies on g_halted_sbe_list to have current list of SBE processors to check
 *
 *        If an SBE has been detected as no longer halted:
 *        1) Create and commit an error log
 *           Callout and deconfigure the affected proc
 *        2) Kill the bad SBE
 *            Set SDB (Secure Debug Bit) in fsi 0x2820
 *            Need to keep looping until we shutdown
 *
 * @param[in] i_p - unused parameter
 * @return nullptr
 */
void * monitorSbeHalt(void * i_p)
{
    TRACFCOMP(g_trac_sbehalt_chk, ENTER_MRK "monitorSbeHalt()" );

    task_detach();

    TRACFCOMP(g_trac_sbehalt_chk, "Begin monitoring SBEs for halt recovery");

    TargetHandle_t l_bad_sbe = nullptr;
    uint32_t l_regData = 0;

    // use a local variable for list size as STL size() operation is not thread-safe
    uint32_t listSize = 1;
    do
    {
        mutex_lock(&g_sbeHalt_mutex);
        for (auto const& l_proc_sbe : g_halted_sbe_list)
        {
            // check if SBE is still halted
            bool stillHalted = checkSbeAttn(l_proc_sbe, l_regData);
            if (!stillHalted)
            {
                l_bad_sbe = l_proc_sbe;
                break;
            }
        }
        if (l_bad_sbe != nullptr)
        {
            // create error for this restarted SBE
            /*@
            * @errortype    ERRL_SEV_UNRECOVERABLE
            * @moduleid     ISTEP::MOD_MONITOR_SBE_HALT
            * @reasoncode   ISTEP::RC_UNHALTED_SBE
            * @userdata1    SBE processor
            * @userdata2    FSI2PIB.STATUS register
            * @devdesc      FSP must have woken up halted secondary SBE
            * @custdesc     Security failure detected during system boot
            */
            errlHndl_t l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                        ISTEP::MOD_MONITOR_SBE_HALT,
                                                        ISTEP::RC_UNHALTED_SBE,
                                                        get_huid(l_bad_sbe),
                                                        l_regData,
                                                        ErrlEntry::NO_SW_CALLOUT);
            // deconfigure the compromised processor
            l_errl->addHwCallout( l_bad_sbe,
                                  HWAS::SRCI_PRIORITY_HIGH,
                                  HWAS::DECONFIG,
                                  HWAS::GARD_NULL );

            l_errl->collectTrace(SBE_HALT_CHK_NAME);
            l_errl->collectTrace(ISTEP_COMP_NAME, 256);
            l_errl->collectTrace(SBE_COMP_NAME, 256);
            errlCommit(l_errl, ISTEP_COMP_ID);

            TRACFCOMP(g_trac_sbehalt_chk, "Removing bad sbe 0x%.8X from halt monitor list", get_huid(l_bad_sbe));
            g_halted_sbe_list.remove(l_bad_sbe);

            // start setting Secure Debug bit to make sure SBE is killed
            addUnsecuredSbe(l_bad_sbe);
            l_bad_sbe = nullptr;
        }
        // update list size here so if a remove cleared the list, this thread will exit
        // thus preventing multiple monitors
        listSize = g_halted_sbe_list.size();
        if (listSize == 0)
        {
            // this thread will stop now since list is empty
            // only change this to false inside the g_sbeHalt_mutex lock
            g_halt_monitor_running = false;
        }
        mutex_unlock(&g_sbeHalt_mutex);
    } while (listSize > 0);

    TRACFCOMP(g_trac_sbehalt_chk, EXIT_MRK "monitorSbeHalt()" );

    return nullptr;
}



// ==============================================================================
// Unhalted SBE handling functions
// =============================================================================
/**
 * @brief Sets secure debug mode bit killing the SBE
 * @param[in] i_sbe_proc Processor target of the SBE
 * @return error if deviceOp failure, else nullptr
 */
errlHndl_t setSecureDebugBit(TargetHandle_t i_sbe_proc)
{
    errlHndl_t l_errl = nullptr;

    // Read FSXCOMP_FSXLOG_SB_CS_FSI_BYTE 0x2820 for target proc
    uint32_t l_read_reg = 0;
    size_t l_opSize = sizeof(uint32_t);

    // constants for the Selfboot Control/Status Register bits
    const uint32_t SB_CS_SECURE_DEBUG_MODE_BIT =
                  (0x80000000 >> FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE);
    const uint32_t SB_CS_START_RESTART_VECTOR_BITS =
                  ((0x80000000 >> FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0) |
                   (0x80000000 >> FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1));

    do {
    l_errl = DeviceFW::deviceOp(
                    DeviceFW::READ,
                    i_sbe_proc,
                    &l_read_reg,
                    l_opSize,
                    DEVICE_FSI_ADDRESS(FSXCOMP_FSXLOG_SB_CS_FSI_BYTE) );

    if( l_errl )
    {
        TRACFCOMP(g_trac_sbehalt_chk,  ERR_MRK"setSecureDebugBit: FSI device read "
                "FSXCOMP_FSXLOG_SB_CS_FSI_BYTE (0x%.4X), proc target = 0x%.8X, "
                "RC=0x%X, PLID=0x%lX",
                FSXCOMP_FSXLOG_SB_CS_FSI_BYTE,
                get_huid(i_sbe_proc),
                ERRL_GETRC_SAFE(l_errl),
                ERRL_GETPLID_SAFE(l_errl));
        break;
    }

    // Check if Secure Debug Mode bit needs to be set
    if ((SB_CS_SECURE_DEBUG_MODE_BIT & l_read_reg) == 0)
    {
        // SDB not set, now set it
        // When we set the SDB bit, we probably want to R-M-W except
        // make sure start/restart vector bits aren't set to avoid restarting code execution
        uint32_t l_new_setting = l_read_reg;
        l_new_setting &= ~SB_CS_START_RESTART_VECTOR_BITS;
        l_new_setting |= SB_CS_SECURE_DEBUG_MODE_BIT;

        TRACFCOMP(g_trac_sbehalt_chk,
            INFO_MRK"setSecureDebugBit: setting SECURE_DEBUG_MODE for proc 0x%.8X from 0x%08X to 0x%08X",
            get_huid(i_sbe_proc), l_read_reg, l_new_setting);

        l_opSize = sizeof(uint32_t);
        l_errl = DeviceFW::deviceOp(
                    DeviceFW::WRITE,
                    i_sbe_proc,
                    &l_new_setting,
                    l_opSize,
                    DEVICE_FSI_ADDRESS(FSXCOMP_FSXLOG_SB_CS_FSI_BYTE) );

        if( l_errl )
        {
            TRACFCOMP(g_trac_sbehalt_chk,  ERR_MRK"setSecureDebugBit: FSI device write "
                    "FSXCOMP_FSXLOG_SB_CS_FSI_BYTE (0x%.4X), proc target = 0x%.8X, "
                    "RC=0x%X, PLID=0x%lX",
                    FSXCOMP_FSXLOG_SB_CS_FSI_BYTE,
                    get_huid(i_sbe_proc),
                    ERRL_GETRC_SAFE(l_errl),
                    ERRL_GETPLID_SAFE(l_errl));
            break;
        }
    }

    } while (0);
    return l_errl;
}

/**
 * @brief Issue machine checkstop on primary processor
 *        This is a last resort to prevent unhalted sbe from messing with memory
 *        Note: this will either do the XSTOP call or assert so hostboot will be dead
 *        after this is executed
 */
void checkstopForUnhaltedSbe()
{
    errlHndl_t l_errl = nullptr;

    //  Identify the boot processor
    Target * l_bootProc =   nullptr;
    Target * l_bootNode =   nullptr;
    bool l_onlyFunctional = true; // Make sure bootproc is functional

    l_errl = targetService().queryMasterProcChipTargetHandle(
                                                      l_bootProc,
                                                      l_bootNode,
                                                      l_onlyFunctional);
     // do not leave this function
     assert(l_errl != nullptr, "checkstopForUnhaltedSbe() unable to find boot processor");

    static const uint64_t MCHK_XSTOP_FIR_SCOM_OR_ADDR = 0x03040102;
    uint64_t machineXstopHbFir = Kernel::MachineCheck::MCHK_XSTOP_FIR_VALUE;
    auto opSize = sizeof(machineXstopHbFir);

    l_errl = DeviceFW::deviceOp(
                    DeviceFW::WRITE,
                    l_bootProc,
                    &machineXstopHbFir,
                    opSize,
                    DEVICE_SCOM_ADDRESS(MCHK_XSTOP_FIR_SCOM_OR_ADDR) );
    // No sense in checking l_errl since we want to terminate if we ever get past this XSTOP
    // at this point thread should be stopped, if not, that is really bad
    assert(false, "checkstopForUnhaltedSbe() MCHK_XSTOP failed");
}

/**
 * @brief Thread loops on setting Secure Debug Bit for bad SBEs in
 *        the g_unsecured_sbes list
 *
 *        NOTE: this thread will be killed when a reconfig loop happens
 *
 * @param[in] i_p - unused
 * @return nullptr
 */
void * handleRestartedSbes(void * i_p)
{
    errlHndl_t l_err = nullptr;
    task_detach();

    TRACFCOMP(g_trac_sbehalt_chk, ENTER_MRK"handleRestartedSbes thread started");

    // use a local variable for list size as STL size() operation is not thread-safe
    uint32_t listSize = 1;
    do
    {
        mutex_lock(&g_unsecured_sbe_mutex);
        for (auto l_proc : g_unsecured_sbes)
        {
            l_err = setSecureDebugBit(l_proc);
            if (l_err)
            {
                // unable to stop unhalted SBE
                l_err->collectTrace(SBE_HALT_CHK_NAME);
                errlCommit(l_err, ISTEP_COMP_ID);

                // Cause a checkstop to prevent further damage from unhalted SBE
                checkstopForUnhaltedSbe();
            }
        }
        // update local listSize here so if a remove cleared the list, this thread will exit
        // thus preventing multiple handler threads
        listSize = g_unsecured_sbes.size();
        mutex_unlock(&g_unsecured_sbe_mutex);
    } while (listSize > 0);
    TRACFCOMP(g_trac_sbehalt_chk, EXIT_MRK"handleRestartedSbes thread");
    return nullptr;
}

/**
 * @brief Add a woken up SBE to the unsecured sbe list
 *        Will launch thread to continuously set Secure Debug bit.
 * @param[in] Processor target of the SBE
 */
void addUnsecuredSbe(TargetHandle_t i_sbeProc)
{
    mutex_lock(&g_unsecured_sbe_mutex);
    g_unsecured_sbes.push_back(i_sbeProc);
    if (g_unsecured_sbes.size() == 1)
    {
        // launch thread
        task_create(&handleRestartedSbes, nullptr);
    }
    mutex_unlock(&g_unsecured_sbe_mutex);
}

} // namespace MONITOR_SBE_HALT

