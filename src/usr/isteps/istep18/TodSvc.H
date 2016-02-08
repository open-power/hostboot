/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep18/TodSvc.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
#ifndef TODSVC_H
#define TODSVC_H

/**
 *  @file TodSvc.H
 *
 *  @brief Defines the TodSvc class that provides the Time Of Day service
 *      The TodSvc class is a thread-safe singleton.
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

#include <util/singleton.H>

namespace TOD
{

/**
 * @class TodSvc
 *
 * @brief Time Of Day service entry point
 */
class TodSvc
{
public:

    /**
     * @brief Get singleton instance of this class.
     *
     *  @return the (one and only) instance of TodSvc
     */
    static TodSvc& getTheInstance();

    /**
     * @brief This interface should be called during IPL to setup the
     *     time of day logic on the P8 processors sitting on the system.
     *
     * @par Detailed Description:
     *     All processors of a symmetric multiprocessor model must appear to
     *     have the same time. This is in order to ensure that time stamps
     *     accurately reflect the sequence of events occuring on these procs.
     *
     *     To achieve this, each proc has a hardware time of day (TOD) logic.
     *     A TOD oscillator(a fixed frequency clock) can send out signals to
     *     keep the TOD clocks on the various procs in sync.
     *
     *     Since the procs are connected by fabric buses, a signal sent out by
     *     the oscillator will reach the procs at different times. Besides,
     *     there are multiple bus paths to propagate TOD signals. To solve these
     *     issues, we (FSP HWSV) need to create a TOD topology. A TOD topology
     *     has a single Master Drawer Master TOD processor chip (MDMT), which
     *     receives input directly from the oscillator. The MDMT will propagate
     *     signals to other procs, MDSTs (Master Drawer Slave TOD Chips),
     *     in the fabric node/physical drawer in which it's contained, via X
     *     buses. This group of procs will be part of a TOD drawer. Inter TOD
     *     drawer communications will be via A buses. Via A bus, the MDMT will
     *     propagate TOD signals to designated masters in other drawers, SDMTs
     *     (Slave Drawer Master TOD Chips). In the their respective TOD
     *     drawers, SDMTs, like the MDMT, will use X buses to propagate signals
     *     to other SDSTs (Slave Drawer Slave TOD Chips).
     *
     *     We will create a primary topology and a secondary topology, for
     *     redundancy. Once we create the topologies, the same will be passed
     *     on to a hardware procedure. The procedure will set bits in the TOD
     *     registers of the procs, to indicate the topology. THe procedure will
     *     also compute "delays", to be introduced to signals sent out by the
     *     oscillator. MDMT will have the longest delay and the furthest proc
     *     from the oscillator will have 0 delay. This helps ensuring that TOD
     *     signals are received at the same wall clock time.
     *
     *     At runtime, PHYP will be able to read the TOD registers and
     *     determine the TOD topolgies. It will use the primary topology as the
     *     active topology for timekeeping. On detecting errors in the active
     *     topology, it can switch to the secondary and ask us to reconfigure a
     *     backup.
     *
     * @return Error log handle indicating the status of the request.
     * @retval NULL if successful
     * @retval !NULL if failed to setup TOD
     *
     *     Error log handle points to a valid error log object whose primary
     *     SRC reason code (pError->getSRC()->reasonCode()) indicates the type
     *     of error.
     *
     * @note It is up to the caller to change the severity of the
     *     returned error based on what it decides to do with it. By default
     *     any returned error created by this function will be a non-reported
     *     tracing event error log.
     *
     * @note TOD setup is not allowed at FSP runtime
     * @note Presence of a secondary topology is not critical to
     *    to TOD functionality, so an error in creating the same
     *    will be noted but not returned.
     */
    errlHndl_t todSetup();

    /**
     * @brief This interface should be called during IPL to set the TOD
     *     into running state
     *
     * @return Error log handle indicating the status of the request.
     * @retval NULL if successful
     * @retval !NULL if failed to setup TOD
     *
     *     Error log handle points to a valid error log object whose primary
     *     SRC reason code (pError->getSRC()->reasonCode()) indicates the type
     *     of error.
     *
     * @note It is up to the caller to change the severity of the
     *     returned error based on what it decides to do with it. By default
     *     any returned error created by this function will be a non-reported
     *     tracing event error log.
     */
    errlHndl_t todInit();

    /**
     * @brief Reads the Time Of Day (TOD) value from the TOD register on
     *     the processor chip and returns the same.
     *
     * @par Detailed Description:
     *     This interface will read the TOD value from the TOD value register.
     *     We could read this from any of the processor that's part of the
     *     TOD topology, since the TOD value should be in sync across procs,
     *     so we'll read this from the MDMT's register.
     *
     * @param[out] o_todValue
     *     64-bit contents of the TOD value register will be copied here
     *     in a big-endian format. Will be 0 on error.
     *
     * @return Error log handle indicating the status of the request.
     * @retval NULL if successful
     * @retval !NULL if failed to read TOD value
     *
     *     Error log handle points to a valid error log object whose primary
     *     SRC reason code (pError->getSRC()->reasonCode()) indicates the type
     *     of error.
     *
     * @note It is up to the caller to change the severity of the
     *     returned error based on what it decides to do with it. By default
     *     any returned error created by this function will be a non-reported
     *     tracing event error log.
     */
    errlHndl_t readTod(uint64_t& o_todValue) const;

protected:
    /**
     * @brief Constructor.
     *
     * @note This is protected so that only SingletonHolder can call.
     */
    TodSvc();

    /**
     * @brief Destructor.
     *
     * @note This is protected so that only SingletonHolder can call.
     */
    ~TodSvc();

private:
    //Disabled copy constructor and assignment operator
    TodSvc(const TodSvc& rhs);
    TodSvc& operator=(const TodSvc& rhs);

    //Indicates if we've already setup TOD
    bool iv_todSetup;
};

} //namespace TOD

#endif //TODSVC_H
