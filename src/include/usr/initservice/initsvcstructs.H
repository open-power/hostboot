/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/initservice/initsvcstructs.H $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
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
#ifndef __COMMON_INITSVCSTRUCTS_H
#define __COMMON_INITSVCSTRUCTS_H
/**
 *  @file initsvcstructs.H
 *
 *  common structs for initservice, extinitsvc, istepdispatcher
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>
#include <sys/vfs.h>            // VFS_MODULE_NAME_MAX
#include <time.h>

#include <initservice/initsvcreasoncodes.H>
#include <initservice/initsvcstructs.H>

// This constant has a corresponding entry in src/build/tools/listdeps.pl.
#define MAX_DEPENDENT_MODULES   12
// MAX_SUBSTEPS is also used elsewhere, i.e. build/vpo/hb-istep, build/debug/Hostboot/Istep.pm
#define MAX_SUBSTEPS 25
// UD is for the Error Log User Details tracking
// MAX_UD_ENTRIES also used in parser plugins/initsvcudistep.H
// Value based on max number of valid major/minor steps expected
// Currently 83 major/minor steps, so padded up for some flexibility
#define MAX_UD_ENTRIES 100
#define UD_VALID 1
#define UD_DEFAULT_NS 1

namespace   INITSERVICE
{

/******************************************************************************/
// Globals/Constants
/******************************************************************************/


/******************************************************************************/
// Typedef/Enumerations
/******************************************************************************/

/**
 * @note    istepname tag - this is a way to call out the istep, substep, and
 *          istep name for spless operation.    scanistepnames.pl will run
 *          through this, find the istepnames, and publish it as a CVS file
 *          for use by the SPLess user console (python) code.
 *          Usage:
 *          @ISTEPNAME( 4, 0, "init_target_states" )
 *
 *          This will be picked up by scanistepnames.pl and put in as the line
 *              4,0,init_target_states
 *
 *          HostBoot will see it as the string "init_target_states" in the
 *          istepNlist.H file
 */
#define ISTEPNAME( ISTEP, SUBSTEP, NAME )      NAME


/**
 * @enum    TaskType
 *  - NONE          ==  placeholder, no task
 *  - INIT_TASK     ==  load and initialize task, but task has no _start()
 *                      (extended image only)
 *  - START_TASK    ==  BASE_IMAGE: call _start() function entry point
 *                      EXT_IMAGE: call _init(), then _start()
 *  - START_FN      ==  task with function pointer entry point
 *  - UNINIT_TASK   ==  call _fini() to call static destructor(s) on the task.
 *                      (extended image only)
 *  - END_TASK_LIST ==  last entry in the task list.
 */

enum    TaskType
{
    UNDEFINED_TT    =   0,
    NONE,
    INIT_TASK,
    START_TASK,
    START_FN,
    UNINIT_TASK,
    END_TASK_LIST,
};


/**
 * @enum    ModuleType
 *  -   BASE_IMAGE == module in the base image
 *  -   EXT_IMAGE == module in the extended image
 */
enum    ModuleType
{
    UNDEFINED_MT    =   0,
    BASE_IMAGE,
    EXT_IMAGE,
};

/**
 * @enum    IplOpType
 * bitmap indicating whether the task is an op in certain IPL modes.
 */
enum IplOpType
{
    IPL_NOOP      = 0x00,
    NORMAL_IPL_OP = 0x01,
    MPIPL_OP      = 0x02,
};
/**
 * @enum    FirmwareProgressType
 *  -   PHASE_NA                -> No FW progress update.  (All other isteps)
 *  -   BASE_INITIALIZATION     -> 6.3
 *  -   MEMORY_INIT             -> 10.1
 *  -   SEC_PROCESSOR_INIT      -> 15.1
 *  -   STARTING_OS             -> 18.13
 *
 *  See Dean's BMC Function Requirements (R3.2-3.16)
 *  NOTE: The spec says we should update the progress code at the beginning
 *        of each of the step ranges.  Here we are updating at specific
 *        substeps since the previous substeps are functionally HB no-ops.
 *        If these become functional, we will need to change this.
 */
enum firmwareProgressPhase
{
    PHASE_NA            = 0x0,  // Not applicable
    MEMORY_INIT         = 0x01, //< isteps 10->14
    SEC_PROCESSOR_INIT  = 0x03, //< isteps 15->16
    STARTING_OS         = 0x13, //< isteps 17->21
    BASE_INITIALIZATION = 0x14, //< isteps  6-> 9
};
/**
 * @struct  TaskFlags
 *
 *  - run _start() function on start
 *  - module type, BASE_MODULE or EXT_MODULE
 *  - module_id for errorlog if task fails
 *
 */
struct  TaskFlags
{
    TaskType               task_type;    // -- Task execution flags
    ModuleType             module_type;  // -- BASE_IMAGE or EXT_IMAGE
    uint8_t                ipl_op;       // -- Bitmap of IplOpType enum
                                         //    indicating whether task
                                         //    is an op in certain IPL modes.
    bool                   check_attn;   // -- Flag indicating whether to check
                                         //    for attentions and invoke PRD
                                         //    for analysis after executing
                                         //    the istep substep
                                         //    true = check for attentions
    firmwareProgressPhase  fwprogtype;   // -- Flag indicating current IPMI
                                         //    Boot Progress code
};


/**
 * @struct  TaskInfo
 *
 * Holds information on each task in the system.
 *      - taskname
 *      - execution flags, see TaskFlags above
 *
 */
struct  TaskInfo
{
    const char * const  taskname;
    void*               (*taskfn)(void *ptr);
    const   TaskFlags   taskflags;
};


/**
 * @struct  DepModInfo
 *
 * Holds information on other modules that need to be loaded so that this
 * istep will run.
 */
struct  DepModInfo
{
    const char * const modulename[MAX_DEPENDENT_MODULES];
};


/**
 * @struct  ExtTaskInfo
 *
 * struct to store the TaskInfo for the ISteps, plus the number of items in
 * the istep (calculated at compiletime).
 */
struct  ExtTaskInfo
{
    const TaskInfo      *const pti;
    const uint64_t      numitems;
    const DepModInfo    *const depModules;
};

// UdSubStepInfo is shared with the parsers
struct UdSubStepInfo
{
    uint16_t  step;
    uint16_t  substep;
    uint64_t  msecs;
    // See initsvcudistep.C for future usage of stepname
    // Similar change needed in initsvcudistep.H
    // Limitation today is size of the UD object produced needs to fit in PNOR,
    // l_maxErrlogSize if 4K then the ErrlUD should be no greater than the 4K
    // per addToLog, see commitErrAllowExtraLogs from errlmanager_common.C
    // char      stepname[64];
} __attribute__ ((packed));

struct iplSubStepInfo
{
    uint64_t            nsecs;
    char                stepname[64];
    timespec_t          started;
    timespec_t          stopped;
    uint16_t            valid;
    uint16_t            in_progress;
    uint16_t            exit;
    const char *        taskname;
} __attribute__ ((packed));

struct iplInfo
{
    uint64_t            ipl_istep_nsecs;
    timespec_t          ipl_istep_started;
    timespec_t          ipl_istep_stopped;
    iplSubStepInfo      substeps[MAX_SUBSTEPS];
    uint16_t            numitems;
    uint16_t            istep;
    uint16_t            substep;
} __attribute__ ((packed));

} // namespace

#endif
