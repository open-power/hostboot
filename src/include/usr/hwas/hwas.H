//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/hwas/hwas.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
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
#ifndef  __HWAS_HWAS_H
#define __HWAS_HWAS_H
/**
 *  @file hwas.H
 *
 *  HardWare Availability Service prototypes.
 *  In trying to keep with C++ tradition, doxygen documentation for functions
 *  are here in the .H file.
 *
 *  All of the following routines are "named isteps" - they are invoked as
 *  tasks by the @ref IStepDispatcher.
 *
 */


/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>


namespace   HWAS
{
    /*
     * @brief   init_target_states
     *
     *  Currently the state of every target is held in one bitmapped attribute
     *  called HWAS_STATE.  HWAS_STATES is a read-only attribute - defaults are
     *  stored in flash, so they are already initialized.
     *  See src/user/errl/targeting/xmltohb/hb.xml for the settings.
     *  This is left as a placeholder when/if we add more attributes.
     *
     *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
     *                              or NULL.
     *  return  none
     *
     */
    void    init_target_states( void *io_pArgs );

    /**
     * @brief   init_fsi
     *
     *  Call into the fsi component to "walk the bus" and collect information
     *  on the hardware configuration.
     *
     *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
     *                              or NULL.
     *  return  none
     */
    void    init_fsi( void *io_pArgs );

    /**
     * @brief   apply_fsi_info
     *
     * Call into the FSI Component, read the hardware information, and apply
     * it to the target states.
     *
     *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
     *                              or NULL.
     *  return  none
     */
    void    apply_fsi_info( void *io_pArgs );

    /**
     * @brief   apply_dd_presence
     *
     *  Iterate over all targets and apply presence detect information to the
     *  target states.
     *  TBD
     *
     *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
     *                              or NULL.
     *  return  none
     */
    void    apply_dd_presence( void *io_pArgs );

    /**
     * @brief   apply_pr_keyword_data
     *
     * TBD
     *
     *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
     *                              or NULL.
     *  return  none
     *
     */
    void    apply_pr_keyword_data( void *io_pArgs );

    /**
     * @brief   apply_partial bad
     *
     * Collect Partial Bad information and apply it to the target states.
     * TBD
     *
     *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
     *                              or NULL.
     *  return  none
     */
    void    apply_partial_bad( void *io_pArgs );

    /**
     * @brief   apply_gard
     *
     * Collect GARD information and apply it to the target states.
     * TBD
     *
     *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
     *                              or NULL.
     *  return  none
     */
    void    apply_gard( void *io_pArgs );


};   // end namespace

#endif
