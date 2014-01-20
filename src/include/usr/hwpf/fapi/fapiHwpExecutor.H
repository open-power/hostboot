/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/fapi/fapiHwpExecutor.H $                 */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
// $Id: fapiHwpExecutor.H,v 1.5 2013/10/15 13:13:31 dcrowell Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/hwpf/working/fapi/fapiHwpExecutor.H,v $

/**
 *  @file fapiHwpExecutor.H
 *
 *  @brief Defines the FAPI HWP Executor Macro.
 *
 *  The FAPI HWP Executor macro is called when a PLAT invoker function or a HWP
 *  wants to execute a HWP.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     09/22/2011  Removed mandatory target
 *                                                  parameter from FAPI_EXEC_HWP
 */
#ifndef FAPIHWPEXECUTOR_H_
#define FAPIHWPEXECUTOR_H_

#include <fapiPlatHwpExecutor.H>

/**
 * @brief HWP Executor macro
 *
 * This macro calls a PLAT macro which will do any platform specific work to
 * execute the HWP (e.g. dlopening a shared library)
 */
#define FAPI_EXEC_HWP(RC, FUNC, _args_...) \
    FAPI_PLAT_EXEC_HWP(RC, FUNC, ##_args_)

#endif // FAPIHWPEXECUTOR_H_
