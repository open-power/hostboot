/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep08list.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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
 *  IPL FLow Doc    v0.90.05 (Apr 27, 2020)
 *
 *    08.01    host_setup_sbe
 *           : Setup host sbe
 *    08.02    host_secondary_sbe_config
 *           : Configure host secondary sbe
 *    08.03    host_cbs_start
 *           : Start cbs
 *    08.04    proc_check_secondary_sbe_seeprom_complete
 *           : Check Secondary SBE Complete
 *    08.05    host_attnlisten_proc
 *           : Start attention poll for all
 *    08.06    proc_fbc_eff_config
 *           : Determine powerbus config
 *    08.07    proc_eff_config_links
 *           : Powerbus link config
 *    08.08    proc_attr_update
 *           : Proc ATTR Update
 *    08.09    proc_chiplet_fabric_scominit
 *           : Scom inits to all chiplet fabric (sans Quad)
 *    08.10    host_set_voltages
 *           : Set correct chip voltages
 *    08.11    proc_io_scominit
 *           : Apply scom inits to iohs
 *    08.12    proc_load_ioppe
 *           : Load IO PPE images to their SRAMS
 *    08.13    proc_init_ioppe
 *           : Start and init IO PPE
 *    08.14    proc_iohs_enable_ridi
 *           : Enable RI/DI for iohs
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

namespace ISTEP_08
{

/**
 *  @brief host_secondary_sbe_config
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any error logs to istep
 */
void* call_host_secondary_sbe_config(void *io_pArgs);

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
void* call_proc_check_secondary_sbe_seeprom_complete(void *io_pArgs);

/**
 *  @brief call_host_attnlisten_proc
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any error logs to istep
 */
void* call_host_attnlisten_proc(void *io_pArgs);

/**
 * @brief   proc_fbc_eff_config
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any error logs to istep
 */
void* call_proc_fbc_eff_config (void * io_pArgs);

/**
 * @brief   proc_eff_config_links
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any error logs to istep
 */
void* call_proc_eff_config_links (void * io_pArgs);

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
 *  @brief  proc_chiplet_fabric_scominit
 *
 *          Apply scom inits to chiplet fabric
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_proc_chiplet_fabric_scominit( void    *io_pArgs );

/**
 *  @brief   proc_io_scominit
 *
 *           Apply scom inits to iohs
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_proc_io_scominit( void    *io_pArgs );

/**
 *  @brief   proc_load_ioppe
 *
 *           Load IOPPE
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_proc_load_ioppe( void    *io_pArgs );

/**
 *  @brief   proc_init_ioppe
 *
 *           Init IOPPE
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_proc_init_ioppe( void    *io_pArgs );

/**
 *  @brief   proc_iohs_enable_ridi
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_proc_iohs_enable_ridi( void    *io_pArgs );

/**
 *  @brief host_set_voltages
 *
 *  param[in,out]   -  pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_host_set_voltages( void   *io_pArgs );


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
                ISTEPNAME(08,01,"host_setup_sbe"),
                ISTEP_08::call_host_setup_sbe,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,02,"host_secondary_sbe_config"),
                ISTEP_08::call_host_secondary_sbe_config,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,03,"host_cbs_start"),
                ISTEP_08::call_host_cbs_start,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,04,"proc_check_secondary_sbe_seeprom_complete"),
                ISTEP_08::call_proc_check_secondary_sbe_seeprom_complete,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,05,"host_attnlisten_proc"),
                ISTEP_08::call_host_attnlisten_proc,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,06,"proc_fbc_eff_config"),
                ISTEP_08::call_proc_fbc_eff_config,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,07,"proc_eff_config_links"),
                ISTEP_08::call_proc_eff_config_links,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,08,"proc_attr_update"),
                ISTEP_08::call_proc_attr_update,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,09,"proc_chiplet_fabric_scominit"),
                ISTEP_08::call_proc_chiplet_fabric_scominit,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,10,"host_set_voltages"),
                ISTEP_08::call_host_set_voltages,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,11,"proc_io_scominit"),
                ISTEP_08::call_proc_io_scominit,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,12,"proc_load_ioppe"),
                ISTEP_08::call_proc_load_ioppe,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,13,"proc_init_ioppe"),
                ISTEP_08::call_proc_init_ioppe,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
        {
                ISTEPNAME(08,14,"proc_iohs_enable_ridi"),
                ISTEP_08::call_proc_iohs_enable_ridi,
                { START_FN, EXT_IMAGE, NORMAL_IPL_OP, false }
        },
};

const DepModInfo g_istep08Dependancies = {
    {
        DEP_LIB(libistep08.so),
        DEP_LIB(libisteps_nest.so),
        DEP_LIB(libsbe.so),
        DEP_LIB(libpm.so),
        DEP_LIB(libimageprocs.so),
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
