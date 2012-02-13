//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/sbe_centaur_init/sbe_centaur_init.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#ifndef  __SBE_CENTAUR_INIT_SBE_CENTAUR_INIT_H
#define __SBE_CENTAUR_INIT_SBE_CENTAUR_INIT_H
/**
 *  @file sbe_centaur_init.H
 *
 *  All of the following routines are "named isteps" - they are invoked as
 *  tasks by the @ref IStepDispatcher.
 *
 */

/*@
 *  @tag isteplist
 *  @docversion     v0.99 (02/10/12)
 *  @istepname      sbe_centaur_init
 *  @istepnum       10
 *  @istepdesc      Step 10 Hostboot SBE Centaur Init
 *
 *  @{
 *      @substepnum     1
 *      @substepname    cen_sbe_tp_chiplet_init1
 *      @substepdesc    : Cen TP Chiplet Init 1
 *      @param  target  (CLASS_CHIP, TYPE_MEMBUF)
 *          @target_sched   serial
 *  @}
 *
 *  @{
 *      @substepnum     2
 *      @substepname    cen_sbe_tp_arrayinit
 *      @substepdesc    : Cen TP Chiplet array init
 *          @target_sched   serial
 *  @}
 *
 *  @{
 *      @substepnum     3
 *      @substepname    cen_sbe_tp_chiplet_init2
 *      @substepdesc    : Cen TP Chiplet Repair
 *          @target_sched   serial
 *  @}
 *
 *  @{
 *      @substepnum     4
 *      @substepname    cen_sbe_tp_chiplet_init3
 *      @substepdesc    : Cen TP Chiplet Start c0locks
 *          @target_sched   serial
 *  @}
 *
 *  @{
 *      @substepnum     5
 *      @substepname    cen_sbe_chiplet_init
 *      @substepdesc    : Cen Chiplet Init
 *          @target_sched   serial
 *  @}
 *
 *  @{
 *      @substepnum     6
 *      @substepname    cen_sbe_arrayinit
 *      @substepdesc    : Chiplet array init
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     7
 *      @substepname    cen_sbe_pll_initf
 *      @substepdesc    : Cen PLL Init
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     8
 *      @substepname    cen_sbe_dts_init
 *      @substepdesc    : Cen DTS Init
 *          @target_sched   serial
 *  @}
 *
 *  @{
 *      @substepnum     9
 *      @substepname    cen_sbe_initf
 *      @substepdesc    :Cen Scan overrides
 *          @target_sched   serial
 *  @}
 *
 *  @{
 *      @substepnum     10
 *      @substepname    cen_sbe_do_manual_inits
 *      @substepdesc    : Manual Cen Scans
 *          @target_sched   serial
 *  @}
 *
 *  @{
 *      @substepnum     11
 *      @substepname    cen_sbe_startclocks
 *      @substepdesc    : Start Cen Nest
 *          @target_sched   serial
 *  @}
 *
 *  @{
 *      @substepnum     12
 *      @substepname    cen_sbe_scominits
 *      @substepdesc    : Perform any Cen scom inits
 *          @target_sched   serial
 *  @}
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>


namespace   SBE_CENTAUR_INIT
{

    /**
     *  @brief   cen_sbe_tp_chiplet_init1
     *
     *  10.1 : : Cen TP Chiplet Init 1
     *
     *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
     *                              or NULL.
     *  return  none
     *
     */
    void    call_cen_sbe_tp_chiplet_init1( void * io_pArgs );


    /**
     *  @brief   cen_sbe_tp_arrayinit
     *
     *  10.2 : Cen TP Chiplet array init
     *
     *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
     *                              or NULL.
     *  return  none
     *
     */
    void    call_cen_sbe_tp_arrayinit( void * io_pArgs );


    /**
     *  @brief   cen_sbe_tp_chiplet_init2
     *
     *  10.3 : Cen TP Chiplet Repair
     *
     *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
     *                              or NULL.
     *  return  none
     *
     */
    void    call_cen_sbe_tp_chiplet_init2( void * io_pArgs );


    /**
     *  @brief   cen_sbe_tp_chiplet_init3
     *
     *  10.4 : Cen TP Chiplet Start c0locks
     *
     *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
     *                              or NULL.
     *  return  none
     *
     */
    void    call_cen_sbe_tp_chiplet_init3( void * io_pArgs );


    /**
     *  @brief   cen_sbe_chiplet_init
     *
     *  10.5 : Cen Chiplet Init
     *
     *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
     *                              or NULL.
     *  return  none
     *
     */
    void    call_cen_sbe_chiplet_init( void * io_pArgs );


    /**
     *  @brief   cen_sbe_arrayinit
     *
     *  10.6 : Chiplet array init
     *
     *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
     *                              or NULL.
     *  return  none
     *
     */
    void    call_cen_sbe_arrayinit( void * io_pArgs );


    /**
     *  @brief   cen_sbe_pll_initf
     *
     *  10.7 : Cen PLL Init
     *
     *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
     *                              or NULL.
     *  return  none
     *
     */
    void    call_cen_sbe_pll_initf( void * io_pArgs );


    /**
     *  @brief   cen_sbe_dts_init
     *
     *  10.8 : Cen DTS Init
     *
     *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
     *                              or NULL.
     *  return  none
     *
     */
    void    call_cen_sbe_dts_init( void * io_pArgs );


    /**
     *  @brief   cen_sbe_initf
     *
     *  10.9 : Cen Scan overrides
     *
     *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
     *                              or NULL.
     *  return  none
     *
     */
    void    call_cen_sbe_initf( void * io_pArgs );


    /**
     *  @brief   cen_sbe_do_manual_inits
     *
     *  10.10 : Manual Cen Scans
     *
     *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
     *                              or NULL.
     *  return  none
     *
     */
    void    call_cen_sbe_do_manual_inits( void * io_pArgs );


    /**
     *  @brief   cen_sbe_startclocks
     *
     *  10.11 : Start Cen Nest
     *
     *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
     *                              or NULL.
     *  return  none
     *
     */
    void    call_cen_sbe_startclocks( void * io_pArgs );


    /**
     *  @brief   cen_sbe_scominits
     *
     *  10.12 : Perform any Cen scom inits
     *
     *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
     *                              or NULL.
     *  return  none
     *
     */
    void    call_cen_sbe_scominits( void * io_pArgs );

};   // end namespace

#endif
