/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/nest_chiplets/nest_chiplets.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#ifndef  __NEST_CHIPLETS_NEST_CHIPLETS_H
#define  __NEST_CHIPLETS_NEST_CHIPLETS_H

/**
 *  @file nest_chiplets.H
 *
 *  Nest Chiplets
 *
 *  All of the following routines are "named isteps" - they are invoked as
 *  tasks by the @ref IStepDispatcher.
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-04-03:1952
 *  *****************************************************************
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

 /*  @tag isteplist
 *  @docversion     v1.01 (03/26/12)
 *  @istepname      nest_chiplets
 *  @istepnum       07
 *  @istepdesc      Nest Chiplets
 *
 *  @{
 *      @substepnum     1
 *      @substepname    proc_a_x_pci_dmi_pll_setup
 *      @substepdesc    : Setup PLL for A, X, PCIe, DMI
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     2
 *      @substepname    proc_startclock_chiplets
 *      @substepdesc    : Start clocks on A, X, PCIe chiplets
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     3
 *      @substepname    proc_chiplet_scominit
 *      @substepdesc    : Apply scom inits to chiplets
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     4
 *      @substepname    proc_pcie_scominit
 *      @substepdesc    : Apply scom inits to PCIe chiplets
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     5
 *      @substepname    proc_scomoverride_chiplets
 *      @substepdesc    : Apply sequenced scom inits
 *          @target_sched   serial
 *  @}
 *
 */ 

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

namespace   NEST_CHIPLETS
{



/**
 *  @brief   proc_a_x_pci_dmi_pll_setup
 *
 *  07.1 : : Setup PLL for A, X, PCIe, DMI
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *                    
 *  return  any error logs to istep
 *
 */
void*    call_proc_a_x_pci_dmi_pll_setup( void    *io_pArgs );



/**
 *  @brief   proc_startclock_chiplets
 *
 *  07.2 : : Start clocks on A, X, PCIe chiplets
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *                    
 *  return  any error logs to istep
 *
 */
void*    call_proc_startclock_chiplets( void    *io_pArgs );



/**
 *  @brief   proc_chiplet_scominit
 *
 *  07.3 : : Apply scom inits to chiplets
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *                    
 *  return  any error logs to istep
 *
 */
void*    call_proc_chiplet_scominit( void    *io_pArgs );



/**
 *  @brief   proc_pcie_scominit
 *
 *  07.4 : : Apply scom inits to PCIe chiplets
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_proc_pcie_scominit( void    *io_pArgs );



/**
 *  @brief   proc_scomoverride_chiplets
 *
 *  07.5 : : Apply sequenced scom inits
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *                    
 *  return  any error logs to istep
 *
 */
void*    call_proc_scomoverride_chiplets( void    *io_pArgs );


};   // end namespace

#endif

