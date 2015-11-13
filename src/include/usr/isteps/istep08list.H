/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep08list.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
#ifndef __ISTEPS_ISTEP08LIST_H
#define __ISTEPS_ISTEP08LIST_H

/**
 * @file    istep08list.H
 *
 *  IStep 08        Nest Chiplets
 *  IPL FLow Doc    v0.67 (11/02/15)
 *
 *    08.01    host_slave_sbe_config
 *           : Configure host slave sbe
 *    08.02    host_setup_sbe
 *           : Setup host sbe
 *    08.03    host_cbs_start
 *           : Start cbs
 *    08.04    proc_check_slave_sbe_seeprom_complete
 *           : Check Slave SBE Complete
 *    08.05    proc_cen_ref_clk_enable
 *           : Setup centaur ref clocks
 *    08.06    proc_attr_update
 *           : Proc ATTR Update
 *    08.07    proc_enable_osclite
 *           : Enable Osclite
 *    08.08    proc_chiplet_scominit
 *           : Scom inits to all chiplets (sans Quad)
 *    08.09    proc_xbus_scominit
 *           : Apply scom inits to Xbus
 *    08.10    proc_abus_scominit
 *           : Apply scom inits to Abus
 *    08.11    proc_obus_scominit
 *           : Apply scom inits to Obus
 *    08.12    proc_npu_scominit
 *           : Apply scom inits to Npu
 *    08.13    proc_pcie_scominit
 *           : Apply scom inits to PCIechiplets
 *    08.14    proc_scomoverride_chiplets
 *           : Apply sequenced scom inits
 *    08.15    proc_chiplet_enable_ridi
 *           : Enable RI/DI chip wide
 *    08.16    host_rng_bist
 *           : Trigger Built In Self Test for RNG
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

namespace ISTEP_08
{

/**
 *  @brief host_slave_sbe_config
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any error logs to istep
 */
void* call_host_slave_sbe_config(void *io_pArgs);

/**
 *  @brief call_host_setup_sbe
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any error logs to istep
 */
void* call_host_setup_sbe(void *io_pArgs);

/**
 *  @brief call_host_cbs_start
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any error logs to istep
 */
void* call_host_cbs_start(void *io_pArgs);


/**
 *  @brief proc_check_slave_sbe_seeprom_complete
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any error logs to istep
 */
void* call_proc_check_slave_sbe_seeprom_complete(void *io_pArgs);

/**
 *  @brief  proc_cen_ref_clk_enable
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any error logs to istep
 */
void* call_proc_cen_ref_clk_enable(void *io_pArgs);

/**
 *  @brief  call_proc_attr_update
 *
 *           Stub to enable platforms to override attributes
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void * call_proc_attr_update( void * io_pArgs );

/**
 *  @brief proc_enable_osclite
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any error logs to istep
 *
 */
void* call_proc_enable_osclite(void *io_pArgs);

/**
 *  @brief  proc_chiplet_scominit
 *
 *          Apply scom inits to chiplets
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_proc_chiplet_scominit( void    *io_pArgs );

/**
 *  @brief   proc_xbus_scominit
 *
 *           Apply scom inits to Xbus
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_proc_xbus_scominit( void    *io_pArgs );

/**
 *  @brief   proc_abus_scominit
 *
 *           Apply scom inits to Abus
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_proc_abus_scominit( void    *io_pArgs );

/**
 *  @brief   proc_obus_scominit
 *
 *           Apply scom inits to OBUS
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 */
void*    call_proc_obus_scominit( void     *io_pArgs );

/**
 *  @brief   proc_npu_scominit
 *
 *           Apply scom inits to NPU
 *
 *  param[in.out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 */
void*    call_proc_npu_scominit( void     *io_pArgs );

/**
 *  @brief   proc_pcie_scominit
 *
 *           Apply scom inits to PCIe chiplets
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
 *           Apply sequenced scom inits
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_proc_scomoverride_chiplets( void    *io_pArgs );

/**
 *  @brief   proc_chiplet_enable_ridi
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_proc_chiplet_enable_ridi( void    *io_pArgs );

/**
 *  @brief   host_rng_bist
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_host_rng_bist( void    *io_pArgs );

};   // end namespace



namespace   INITSERVICE
{
    const   TaskInfo    g_istep08[]  =   {
        {
                "",         // dummy, index 0
                NULL,
                { NONE, EXT_IMAGE, IPL_NOOP, false }
        },
        {
                ISTEPNAME(08,01,"host_slave_sbe_config"),
                ISTEP_08::call_host_slave_sbe_config,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,02,"host_setup_sbe"),
                ISTEP_08::call_host_setup_sbe,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,03,"host_cbs_start"),
                ISTEP_08::call_host_cbs_start,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,04,"proc_check_slave_sbe_seeprom_complete"),
                ISTEP_08::call_proc_check_slave_sbe_seeprom_complete,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP | MPIPL_OP, false }
        },
        {
                ISTEPNAME(08,05,"proc_cen_ref_clk_enable"),
                ISTEP_08::call_proc_cen_ref_clk_enable,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,06,"proc_attr_update"),
                ISTEP_08::call_proc_attr_update,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,07,"proc_enable_osclite"),
                ISTEP_08::call_proc_enable_osclite,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,08,"proc_chiplet_scominit"),
                ISTEP_08::call_proc_chiplet_scominit,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,09,"proc_xbus_scominit"),
                ISTEP_08::call_proc_xbus_scominit,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,10,"proc_abus_scominit"),
                ISTEP_08::call_proc_abus_scominit,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,11,"proc_obus_scominit"),
                ISTEP_08::call_proc_obus_scominit,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,12,"proc_npu_scominit"),
                ISTEP_08::call_proc_npu_scominit,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,13,"proc_pcie_scominit"),
                ISTEP_08::call_proc_pcie_scominit,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,14,"proc_scomoverride_chiplets"),
                ISTEP_08::call_proc_scomoverride_chiplets,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,15,"proc_chiplet_enable_ridi"),
                ISTEP_08::call_proc_chiplet_enable_ridi,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,16,"host_rng_bist"),
                ISTEP_08::call_host_rng_bist,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },

};

const DepModInfo g_istep08Dependancies = {
    {
        DEP_LIB(libistep08.so),
        NULL
    }
};

const ExtTaskInfo g_istep08TaskList = {
    &(g_istep08[0]),
    ( sizeof(g_istep08)/sizeof(TaskInfo) ),
    &g_istep08Dependancies
};

};  // end namespace

#endif
