/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/fapiporeve/fapiPoreVe.C $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
// -*- mode: C++; c-file-style: "linux";  -*-
// $Id: fapiPoreVe.C,v 1.35 2014/03/31 15:21:37 thi Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/poreve/working/fapiporeve/fapiPoreVe.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE : fapiPoreVe.C
// *! DESCRIPTION : Creates and runs a PoreVe
// *! OWNER NAME  : Jeshua Smith    Email: jeshua@us.ibm.com
// *! BACKUP NAME : John Bordovsky  Email: johnb@us.ibm.com
// #! ADDITIONAL COMMENTS :
//
// The purpose of this procedure is to initialize and run a PoreVe
//
// Assume: Any memory images and start state desired are passed in
// 
// Procedure Summary:
//   Create new PoreVe (pass in master target)
//   Reset the PoreVe (pass in slave target)
//   Install start state, if passed in
//   Install hooks
//   Install each memory image passed in
//   Deconfigure missing memories
//   Set entry point
//   Set break point
//   Run the requested number of instructions
//   Extract end state
//   Destroy PoreVe
//		  

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include "poreve.H"
#include <fapi.H>
#include "fapiPoreVeArg.H"

//For hooks
#ifndef __HOSTBOOT_MODULE
#include <dlfcn.h>
#endif
#include "hookmanager.H"

#ifdef FAPIECMD
extern "C" {
#endif 

using namespace vsbe;

const uint32_t MBOX_SBEVITAL_0x0005001C = 0x0005001C;

//******************************************************************************
// fapiPoreVe function
//******************************************************************************
fapi::ReturnCode fapiPoreVe(
    const fapi::Target i_target,
    std::list<uint64_t> & io_sharedObjectArgs)
{
    fapi::ReturnCode rc = fapi::FAPI_RC_SUCCESS;
    PoreVe *poreve = NULL;
    FapiPoreVeOtherArg *pOtherArg = NULL;
    bool haveOTPROM  = false;
    bool havePNOR    = false;
    bool haveSEEPROM = false;
    bool haveMAINMEM = false;
    bool haveSRAM    = false;
    bool havePIBMEM  = false;
    const fapi::Target & TARGET = i_target;

    //----------------------------------------------------------------------
    // Find the PORE type
    //----------------------------------------------------------------------
    std::list<uint64_t>::iterator itr;
    for( itr = io_sharedObjectArgs.begin();
         (itr != io_sharedObjectArgs.end()) && (poreve == NULL);
         itr++ )
    {
        FapiPoreVeArg *arg = reinterpret_cast<FapiPoreVeArg *>(*itr);

        //----------------------------------------------------------------------
        // Use PORE type and pdbgArg to create poreve
        //----------------------------------------------------------------------
        if( arg->iv_type == ARG_OTHER )
        {
            FapiPoreVeOtherArg *thisArg = (FapiPoreVeOtherArg *)arg;
            pOtherArg = thisArg;
            fapi::Target masterTarget = i_target; //JDS TODO - get this from an attribute
            poreve = PoreVe::create( thisArg->iv_poreType,
                             masterTarget,
                             thisArg->iv_pdbgArgs );
        }
    }
    if( poreve == NULL )
    {
        FAPI_ERR( "Failed to create poreve\n" );
        FAPI_SET_HWP_ERROR(rc, RC_FAPIPOREVE_FAILED_TO_CREATE_POREVE);
    } else {
        rc = poreve->constructorRc();
    }

    //----------------------------------------------------------------------
    // Reset the PoreVe and set slave target
    //----------------------------------------------------------------------
    if( rc.ok() ) {
        poreve->reset( i_target );
    }

    //----------------------------------------------------------------------
    // Parse the arguments
    //----------------------------------------------------------------------
    FapiPoreVeStateArg *stateArg = NULL;
    bool p_state_allocated = false;
    for( itr = io_sharedObjectArgs.begin();
         (itr != io_sharedObjectArgs.end()) && rc.ok(); itr++ )
    {
        FapiPoreVeArg *arg = reinterpret_cast<FapiPoreVeArg *>(*itr);

        //----------------------------------------------------------------------
        // Install the start state (if passed in)
        //----------------------------------------------------------------------
        if( arg->iv_type == ARG_STATE )
        {
            stateArg = (FapiPoreVeStateArg *)arg;
            if( stateArg->iv_installState )
            {
                PoreState * p_state = (PoreState *)stateArg->iv_data;

#ifndef __HOSTBOOT_MODULE
                if( p_state == NULL )
                {
                    p_state = new PoreState();
                    stateArg->iv_data=p_state;
                    p_state_allocated = true;
                    char* state_rc;
                    int linenum = 0;

                    stateArg->iv_fd = fopen( stateArg->iv_filename, "r" );
                    if( stateArg->iv_fd == NULL )
                    {
                        FAPI_ERR( "Failed to open state file %s\n",
                                  stateArg->iv_filename );
                        // char & FILENAME = stateArg->iv_filename;
                        FAPI_SET_HWP_ERROR(rc,
                           RC_FAPIPOREVE_FAILED_TO_OPEN_STATE_FILE_FOR_READING);
                    }
                    else
                    {
                        do
                        {
                            char line[200];
                            state_rc = fgets( line, sizeof(line),
                                                       stateArg->iv_fd );
                            linenum++;
                            if( state_rc != NULL )
                            {
                                //Get register name
                                char* reg = strtok( line, " =" );

                                PoreRegisterOffset reg_offset;
                                if( strcmp( reg, "PORE_STATUS" ) == 0 ) {
                                    reg_offset = PORE_STATUS;
                                } else if( strcmp( reg, "PORE_CONTROL" ) == 0 ) {
                                    reg_offset = PORE_CONTROL;
                                } else if( strcmp( reg, "PORE_RESET" ) == 0 ) {
                                    reg_offset = PORE_RESET;
                                } else if( strcmp( reg, "PORE_ERROR_MASK" ) == 0 ) {
                                    reg_offset = PORE_ERROR_MASK;
                                } else if( strcmp( reg, "PORE_PRV_BASE_ADDR0" ) == 0 ) {
                                    reg_offset = PORE_PRV_BASE_ADDR0;
                                } else if( strcmp( reg, "PORE_PRV_BASE_ADDR1" ) == 0 ) {
                                    reg_offset = PORE_PRV_BASE_ADDR1;
                                } else if( strcmp( reg, "PORE_OCI_MEMORY_BASE_ADDR0" ) == 0 ) {
                                    reg_offset = PORE_OCI_MEMORY_BASE_ADDR0;
                                } else if( strcmp( reg, "PORE_OCI_MEMORY_BASE_ADDR1" ) == 0 ) {
                                    reg_offset = PORE_OCI_MEMORY_BASE_ADDR1;
                                } else if( strcmp( reg, "PORE_TABLE_BASE_ADDR" ) == 0 ) {
                                    reg_offset = PORE_TABLE_BASE_ADDR;
                                } else if( strcmp( reg, "PORE_EXE_TRIGGER" ) == 0 ) {
                                    reg_offset = PORE_EXE_TRIGGER;
                                } else if( strcmp( reg, "PORE_SCRATCH0" ) == 0 ) {
                                    reg_offset = PORE_SCRATCH0;
                                } else if( strcmp( reg, "PORE_SCRATCH1" ) == 0 ) {
                                    reg_offset = PORE_SCRATCH1;
                                } else if( strcmp( reg, "PORE_SCRATCH2" ) == 0 ) {
                                    reg_offset = PORE_SCRATCH2;
                                } else if( strcmp( reg, "PORE_IBUF_01" ) == 0 ) {
                                    reg_offset = PORE_IBUF_01;
                                } else if( strcmp( reg, "PORE_IBUF_2" ) == 0 ) {
                                    reg_offset = PORE_IBUF_2;
                                } else if( strcmp( reg, "PORE_DBG0" ) == 0 ) {
                                    reg_offset = PORE_DBG0;
                                } else if( strcmp( reg, "PORE_DBG1" ) == 0 ) {
                                    reg_offset = PORE_DBG1;
                                } else if( strcmp( reg, "PORE_PC_STACK0" ) == 0 ) {
                                    reg_offset = PORE_PC_STACK0;
                                } else if( strcmp( reg, "PORE_PC_STACK1" ) == 0 ) {
                                    reg_offset = PORE_PC_STACK1;
                                } else if( strcmp( reg, "PORE_PC_STACK2" ) == 0 ) {
                                    reg_offset = PORE_PC_STACK2;
                                } else if( strcmp( reg, "PORE_ID_FLAGS" ) == 0 ) {
                                    reg_offset = PORE_ID_FLAGS;
                                } else if( strcmp( reg, "PORE_DATA0" ) == 0 ) {
                                    reg_offset = PORE_DATA0;
                                } else if( strcmp( reg, "PORE_MEM_RELOC" ) == 0 ) {
                                    reg_offset = PORE_MEM_RELOC;
                                } else if( strcmp( reg, "PORE_I2C_E0_PARAM" ) == 0 ) {
                                    reg_offset = PORE_I2C_E0_PARAM;
                                } else if( strcmp( reg, "PORE_I2C_E1_PARAM" ) == 0 ) {
                                    reg_offset = PORE_I2C_E1_PARAM;
                                } else if( strcmp( reg, "PORE_I2C_E2_PARAM" ) == 0 ) {
                                    reg_offset = PORE_I2C_E2_PARAM;
                                } else if( strcmp( reg, "PORE_HIDDEN_STATE_0" ) == 0) {
                                    reg_offset = PORE_HIDDEN_STATE_0;
                                } else if( strcmp( reg, "PORE_HIDDEN_STATE_1" ) == 0) {
                                    reg_offset = PORE_HIDDEN_STATE_1;
                                } else if( strcmp( reg, "PORE_HIDDEN_STATE_2" ) == 0) {
                                    reg_offset = PORE_HIDDEN_STATE_2;
                                } else if( strcmp( reg, "PORE_HIDDEN_STATE_3" ) == 0) {
                                    reg_offset = PORE_HIDDEN_STATE_3;
                                } else if( strcmp( reg, "PORE_HIDDEN_STATE_4" ) == 0) {
                                    reg_offset = PORE_HIDDEN_STATE_4;
                                } else {
                                    FAPI_ERR("Unknown reg name %s on line %i\n",
                                             reg, linenum );
                                    reg = NULL;
                                } //strcmp reg vs regname

                                if( reg != NULL )
                                {
                                    //get the register value
                                    char* value = strtok( NULL, " =" );
                                    if( value != NULL )
                                    {
                                        uint64_t value_64;
                                        value_64 = strtoull(value, NULL, 16);
                                        ModelError me;
                                        me = p_state->put(reg_offset,value_64);
                                        FAPI_INF( "Set %s(0x%X) to 0x%016llX\n",
                                                   reg, reg_offset, value_64 );
                                        if( me != ME_SUCCESS )
                                        {
                                            FAPI_ERR( "Model error parsing "
                                                      "state. Errno(%i)\n",
                                                      (int)me);
                                        }
                                    }
                                    else
                                    {
                                        FAPI_ERR( "Error parsing value of %s "
                                                 "on line %i\n", reg, linenum );
                                    }
                                } //if reg != NULL
                            } //if state_rc != NULL
                        } while ( state_rc != NULL ); //able to read a line
                        fclose( stateArg->iv_fd );
                    } //able to open statefile
                }
                else
                {
                    FAPI_INF( "State pointer was passed in, "
                              "so not reading state from file\n" );
                }
#endif
                if (rc.ok())
                {
                    ModelError me = poreve->iv_pore.installState( *p_state );
                    if( me != ME_SUCCESS )
                    {
                        FAPI_ERR( "Model error installing state. Errno(%i)\n",
                                  (int)me);
                        ModelError & ERROR = me;
                        FAPI_SET_HWP_ERROR(rc,
                                       RC_FAPIPOREVE_FAILED_TO_INSTALL_STATE);
                    }
                }
            } //if install state
        } //end state arg processing

        //----------------------------------------------------------------------
        // Install hooks
        //----------------------------------------------------------------------
        else if( arg->iv_type == ARG_HOOKS )
        {
#ifndef __HOSTBOOT_MODULE
            FapiPoreVeHooksArg *thisArg = (FapiPoreVeHooksArg *)arg;

            //Load hooks (note: this must be done after poreve is created)
            void *handle = 
                    HookManager::dlopen( thisArg->iv_filename, RTLD_NOW);
            if (handle == 0)
            {
                FAPI_ERR( "dlopen() failed; See dlerror() string below\n%s\n",
                        dlerror());
                FAPI_ERR( "Failed to load hooks file\n" );
                // char & ERROR_STRING = dlerror();
                // char & FILENAME = thisArg->iv_filename;
                FAPI_SET_HWP_ERROR(rc, RC_FAPIPOREVE_FAILED_TO_LOAD_HOOKS);
            }
            else
            {
                FAPI_INF( "Loaded hooks file %s\n", thisArg->iv_filename );
                poreve->iv_pore.enableAddressHooks(true);
            }
#endif
        }

        //----------------------------------------------------------------------
        // Install each memory image passed in
        // (OTPROM, PNOR, SEEPROM, MAINMEM, SRAM)
        //----------------------------------------------------------------------
        else
        {
            FapiPoreVeMemArg *thisArg = (FapiPoreVeMemArg *)arg;

            //OTPROM
            if( thisArg->iv_type == ARG_OTPROM )
            {
                poreve->iv_otpromMemory.map( thisArg->iv_base,
                                             thisArg->iv_size,
                                             (ACCESS_MODE_READ),
                                             thisArg->iv_data,
                                             thisArg->iv_crcEnable );
                haveOTPROM = true;
            }

            //PNOR
            else if( thisArg->iv_type == ARG_PNOR )
            {
                poreve->iv_pnorMemory.map( thisArg->iv_base,
                                           thisArg->iv_size,
                                           (ACCESS_MODE_READ|ACCESS_MODE_WRITE),
                                           thisArg->iv_data,
                                           thisArg->iv_crcEnable );
                havePNOR = true;
            }

            //SEEPROM
            else if( thisArg->iv_type == ARG_SEEPROM )
            {
                poreve->iv_seepromMemory.map( thisArg->iv_base,
                                              thisArg->iv_size,
                                              (ACCESS_MODE_READ),
                                              thisArg->iv_data,
                                              thisArg->iv_crcEnable );
                haveSEEPROM = true;
            }

            //MAINMEM
            else if( thisArg->iv_type == ARG_MAINMEM )
            {
                poreve->iv_mainMemory.map( thisArg->iv_base,
                                           thisArg->iv_size,
                                           (ACCESS_MODE_READ|ACCESS_MODE_WRITE),
                                           thisArg->iv_data,
                                           thisArg->iv_crcEnable );
                haveMAINMEM = true;
            }

            //SRAM
            else if( thisArg->iv_type == ARG_SRAM )
            {
                poreve->iv_sramMemory.map( thisArg->iv_base,
                                           thisArg->iv_size,
                                           (ACCESS_MODE_READ|ACCESS_MODE_WRITE),
                                           thisArg->iv_data,
                                           thisArg->iv_crcEnable );
                haveSRAM = true;
            }

            //PIBMEM
            else if( thisArg->iv_type == ARG_PIBMEM )
            {
                poreve->iv_pibmemMemory.map( thisArg->iv_base,
                                             thisArg->iv_size,
                                             (ACCESS_MODE_READ|ACCESS_MODE_WRITE),
                                             thisArg->iv_data,
                                             thisArg->iv_crcEnable );
                havePIBMEM = true;
            }

            //Unknown type
            else if( thisArg->iv_type != ARG_OTHER )
            {
                FAPI_ERR( "Got an arg of an unknown type (type=%d)\n", thisArg->iv_type);
                FapiPoreVeArg_t const& TYPE = thisArg->iv_type;
                FAPI_SET_HWP_ERROR(rc, RC_FAPIPOREVE_UNKNOWN_ARG_TYPE);
            }
        } //end memory args
    } //end parse options

    //----------------------------------------------------------------------
    // Disconnect virtual controllers for memories we don't have
    // (allows access to real hardware for those memory types)
    //----------------------------------------------------------------------
    if( rc.ok() )
    {
        if( !haveOTPROM )
        {
            ModelError me = poreve->detachSlave(&poreve->iv_otprom);
            if( me != ME_SUCCESS )
            {
                FAPI_ERR("Model error detaching OTPROM. Errno(%i)\n",(int)me);
                ModelError & ERROR = me;
                FapiPoreVeArg_t TYPE = ARG_OTPROM;
                FAPI_SET_HWP_ERROR(rc, RC_FAPIPOREVE_ERROR_DETACHING_SLAVE);
            }
        }
        if( !havePNOR )
        {
            ModelError me = poreve->detachSlave(&poreve->iv_pnorController);
            if( me != ME_SUCCESS )
            {
                FAPI_ERR("Model error detaching PNOR. Errno(%i)\n",(int)me);
                ModelError & ERROR = me;
                FapiPoreVeArg_t TYPE = ARG_PNOR;
                FAPI_SET_HWP_ERROR(rc, RC_FAPIPOREVE_ERROR_DETACHING_SLAVE);
            }
        }
        if( !haveSEEPROM )
        {
            ModelError me = poreve->detachSlave(&poreve->iv_seepromController);
            if( me != ME_SUCCESS )
            {
                FAPI_ERR("Model error detaching SEEPROM. Errno(%i)\n",(int)me);
                ModelError & ERROR = me;
                FapiPoreVeArg_t TYPE = ARG_SEEPROM;
                FAPI_SET_HWP_ERROR(rc, RC_FAPIPOREVE_ERROR_DETACHING_SLAVE);
            }
        }
        if( !haveMAINMEM )
        {
            ModelError me = poreve->detachSlave(&poreve->iv_main);
            if( me != ME_SUCCESS )
            {
                FAPI_ERR("Model error detaching MAINMEM. Errno(%i)\n",(int)me);
                ModelError & ERROR = me;
                FapiPoreVeArg_t TYPE = ARG_MAINMEM;
                FAPI_SET_HWP_ERROR(rc, RC_FAPIPOREVE_ERROR_DETACHING_SLAVE);
            }
        }
        if( !haveSRAM )
        {
            ModelError me = poreve->detachSlave(&poreve->iv_sram);
            if( me != ME_SUCCESS )
            {
                FAPI_ERR("Model error detaching SRAM. Errno(%i)\n",(int)me);
                ModelError & ERROR = me;
                FapiPoreVeArg_t TYPE = ARG_SRAM;
                FAPI_SET_HWP_ERROR(rc, RC_FAPIPOREVE_ERROR_DETACHING_SLAVE);
            }
        }
        if( !havePIBMEM )
        {
            ModelError me = poreve->detachSlave(&poreve->iv_pibmem);
            if( me != ME_SUCCESS )
            {
                FAPI_ERR("Model error detaching PIBMEM. Errno(%i)\n",(int)me);
                ModelError & ERROR = me;
                FapiPoreVeArg_t TYPE = ARG_PIBMEM;
                FAPI_SET_HWP_ERROR(rc, RC_FAPIPOREVE_ERROR_DETACHING_SLAVE);
            }
        }
    }

    //----------------------------------------------------------------------
    // Set entry point
    //----------------------------------------------------------------------
    if( (pOtherArg->iv_entryPoint != NULL) && rc.ok() )
    {
        FAPI_INF( "Looking up entry point %s\n", pOtherArg->iv_entryPoint );
                
        GlobalSymbolInfo epInfo;
        bool symbolFound = false;
        HookError he = HookManager::findGlobalSymbol(
            pOtherArg->iv_entryPoint,
            symbolFound,
            epInfo);
        if( !symbolFound || (he != HOOK_OK) )
        {
            FAPI_ERR( "Failed to find entry point \"%s\" in hooks file. "
                      "HookError = %d\n", pOtherArg->iv_entryPoint, (int)he);
//            char & POINT = pOtherArg->iv_entryPoint;
            HookError &  ERROR = he;
            FAPI_SET_HWP_ERROR(rc, RC_FAPIPOREVE_ENTRY_POINT_NOT_FOUND);
            HookManager::report();
        }
        else
        {
            //Make sure entry point is a valid type
            if( epInfo.iv_type != 'T' )
            {
                FAPI_ERR("Entry point is of ivalid type %c\n", epInfo.iv_type);
                char & TYPE = epInfo.iv_type;
                FAPI_SET_HWP_ERROR(rc, RC_FAPIPOREVE_INVALID_ENTRY_POINT_TYPE);
            }
            else
            {
                //Set PC to the entry point
                ModelError me =
                    poreve->iv_pore.setPc( epInfo.iv_address );
                if( me != ME_SUCCESS )
                {
                    FAPI_ERR( "Model error setting PC. Errno(%i)\n", (int)me);
                    PoreAddress & ADDRESS = epInfo.iv_address;
                    ModelError & ERROR = me;
                    FAPI_SET_HWP_ERROR(rc, RC_FAPIPOREVE_ERROR_SETTING_PC);
                }
            }
        }
    }

    //----------------------------------------------------------------------
    // Set breakpoint
    //----------------------------------------------------------------------
    if( (pOtherArg->iv_breakpoint != NULL) && rc.ok() )
    {
        FAPI_INF( "Looking up breakpoint %s\n", pOtherArg->iv_breakpoint );
                
        GlobalSymbolInfo bpInfo;
        bool symbolFound = false;
        HookError he = HookManager::findGlobalSymbol(
            pOtherArg->iv_breakpoint,
            symbolFound,
            bpInfo);
        if( !symbolFound || (he != HOOK_OK) )
        {
            FAPI_ERR( "Failed to find breakpoint \"%s\" in hooks file."
                      "HookError = %d\n", pOtherArg->iv_breakpoint, (int)he);
            // char & POINT = pOtherArg->iv_breakpoint;
            HookError &  ERROR = he;
            FAPI_SET_HWP_ERROR(rc, RC_FAPIPOREVE_BREAKPOINT_NOT_FOUND);
            HookManager::report();
        }
        else
        {
            //Make sure break point is a valid type
            if( bpInfo.iv_type != 'T' )
            {
                FAPI_ERR("Break point is of ivalid type %c\n", bpInfo.iv_type);
                char & TYPE = bpInfo.iv_type;
                FAPI_SET_HWP_ERROR(rc, RC_FAPIPOREVE_INVALID_BREAK_POINT_TYPE);
            }
            else
            {
                //Set the break point
                ModelError me =
                    poreve->iv_pore.setBreakpoint( bpInfo.iv_address );
                if( me != ME_SUCCESS )
                {
                    FAPI_ERR( "Model error setting breakpoint. Errno(%i)\n",
                              (int)me);
                    PoreAddress & ADDRESS = bpInfo.iv_address;
                    ModelError & ERROR = me;
                    FAPI_SET_HWP_ERROR(rc,
                                        RC_FAPIPOREVE_ERROR_SETTING_BREAKPOINT);
                }
            }
        }
    }

    //----------------------------------------------------------------------
    // Set MRR
    //----------------------------------------------------------------------
    if( (pOtherArg->iv_mrr != 0) && rc.ok() )
    {
        FAPI_INF( "Setting MRR to 0x%016llX", pOtherArg->iv_mrr );
                
        ModelError me = poreve->iv_pore.registerWrite( vsbe::PORE_MEM_RELOC,
                pOtherArg->iv_mrr & 0x00000003fffffc00ull, sizeof(uint64_t) );
        if( me != ME_SUCCESS )
        {
            FAPI_ERR( "Model error setting MRR. Errno(%i)\n", (int)me);
            uint64_t & MRR = pOtherArg->iv_mrr;
            ModelError & ERROR = me;
            FAPI_SET_HWP_ERROR(rc, RC_FAPIPOREVE_ERROR_SETTING_MRR);
        }
    }

    //----------------------------------------------------------------------
    // Run the requested number of instructions
    // JDS TODO - check poreve->poreRc() to get run-time FAPI return codes
    //----------------------------------------------------------------------
    if( rc.ok() ) {
        uint64_t o_actualNumInstructionsRun = 0;
        int runStatus = poreve->run( pOtherArg->iv_instructionCount,
                                     o_actualNumInstructionsRun );
        FAPI_INF( "PORE ran %llu instructions, and returned status 0x%X\n",
                  o_actualNumInstructionsRun, runStatus);

        if( runStatus != 0 )
        {
            //Parse out each status bit
            if( runStatus & PORE_STATUS_HALTED )
            {
                FAPI_INF( "PORE is stopped at a HALT instruction\n");
                runStatus &= ~PORE_STATUS_HALTED;

                //Check the SBE VITAL reg halt code for success
                uint64_t   data_64;
                int        pib_rc;
                ModelError me;
                me = poreve->getscom(MBOX_SBEVITAL_0x0005001C, data_64, pib_rc);
                if( me == ME_SUCCESS )
                {
                    if( pib_rc == 0 )
                    {
                        //Bits 12:15 are halt code; code 0xF = success
                        uint32_t haltcode = (data_64 >> 48) & 0x0000000F;
                        if( haltcode != 0xF )
                        {
                            FAPI_ERR( "Halt code is 0x%x (ERROR)\n", haltcode );
                            uint32_t & ERROR = haltcode;
                            FAPI_SET_HWP_ERROR(rc,
                                              RC_FAPIPOREVE_HALTED_WITH_ERROR);
                            poreve->iv_pore.dumpOnce();
                        }
                        else
                        {
                            FAPI_INF( "Halt code is 0x%x (SUCCESS)\n",haltcode);
                            rc = fapi::FAPI_RC_SUCCESS;
                        }
                    }
                    else
                    {
                        FAPI_ERR("PIB error getting halt code "
                                 "(error code %i)\n", pib_rc );
                        int & ERROR = pib_rc;
                        FAPI_SET_HWP_ERROR(rc,
                                     RC_FAPIPOREVE_PIB_ERROR_READING_SBEVITAL);
                    }
                }
                else
                {
                    FAPI_ERR( "Model error getting halt code (me=0x%x)\n", me );
                    ModelError & ERROR = me;
                    FAPI_SET_HWP_ERROR(rc,
                                  RC_FAPIPOREVE_MODEL_ERROR_GETTING_HALT_CODE);
                }
            }
            if( runStatus & PORE_STATUS_ERROR_HALT )
            {
                FAPI_ERR( "PORE is stopped due to an architected error\n");
                runStatus &= ~PORE_STATUS_ERROR_HALT;
                FAPI_SET_HWP_ERROR(rc, RC_FAPIPOREVE_ARCHITECTED_ERROR);
                poreve->iv_pore.dumpOnce();
            }
            if( runStatus & PORE_STATUS_HARDWARE_STOP )
            {
                FAPI_INF( "PORE is stopped\n");
                runStatus &= ~PORE_STATUS_HARDWARE_STOP;
            }
            if( runStatus & PORE_STATUS_BREAKPOINT )
            {
                FAPI_INF( "PORE is stopped at a breakpoint\n");
                runStatus &= ~PORE_STATUS_BREAKPOINT;
            }
            if( runStatus & PORE_STATUS_TRAP )
            {
                FAPI_INF( "PORE is stopped at a TRAP instruction\n");
                runStatus &= ~PORE_STATUS_TRAP;
            }
            if( runStatus & PORE_STATUS_MODEL_ERROR )
            {
                FAPI_ERR( "PORE is stopped due to a modeling error\n");
                runStatus &= ~PORE_STATUS_MODEL_ERROR;
                FAPI_SET_HWP_ERROR(rc, RC_FAPIPOREVE_MODELING_ERROR);
                poreve->iv_pore.dumpOnce();
            }
            if( runStatus & PORE_STATUS_DEBUG_STOP )
            {
                FAPI_INF( "PORE is stopped due to a user request "
                          "(probably a hook)\n");
                runStatus &= ~PORE_STATUS_DEBUG_STOP;
            }
            //If we still have bits set, we missed something
            if( runStatus )
            {
                FAPI_ERR( "PORE is stopped with an unknown status code:0x%X\n",
                          runStatus);
                int & STATUS = runStatus;
                FAPI_SET_HWP_ERROR(rc, RC_FAPIPOREVE_UNKNOWN_STATUS_ERROR);
            }
        } else { //runStatus == 0
            FAPI_IMP( "PORE ran the requested number of instructions "
                      "without hitting any stop conditions\n");
        }

        if( (pOtherArg->iv_instructionCount != RUN_UNLIMITED) &&
            (pOtherArg->iv_instructionCount != o_actualNumInstructionsRun) )
        {
            FAPI_IMP( "PORE only ran %llu of the %llu instructions you "
                      "requested\n", o_actualNumInstructionsRun,
                      pOtherArg->iv_instructionCount );
        }
    } //if( rc.ok() )

    //----------------------------------------------------------------------
    // Extract end state
    //----------------------------------------------------------------------
    if( (stateArg != NULL) && stateArg->iv_extractState && rc.ok() )
    {
        ModelError me;
        PoreState * p_state = (PoreState *)stateArg->iv_data;

        if( p_state == NULL )
        {
            p_state = new PoreState();
            p_state_allocated = true;
        }
        me = poreve->iv_pore.extractState( *p_state );

#ifndef __HOSTBOOT_MODULE
        stateArg->iv_fd = fopen( stateArg->iv_filename, "w" );
        if( stateArg->iv_fd == NULL ) {
            FAPI_ERR( "Unable to write state to \"%s\"\n",
                      stateArg->iv_filename );
            // char & FILENAME = stateArg->iv_filename;
            FAPI_SET_HWP_ERROR(rc,
                          RC_FAPIPOREVE_FAILED_TO_OPEN_STATE_FILE_FOR_WRITING);
        } else {
            uint64_t data_64;

#define printreg(offset, reg)                                       \
            me = p_state->get(offset, data_64); if (me != 0) break; \
            fprintf( stateArg->iv_fd, reg, data_64 );

            do
            {
                printreg(vsbe::PORE_STATUS,
                         "PORE_STATUS = 0x%016llX\n" );                
                printreg(vsbe::PORE_CONTROL,
                         "PORE_CONTROL = 0x%016llX\n" );               
                printreg(vsbe::PORE_RESET,
                         "PORE_RESET = 0x%016llX\n" );                 
                printreg(vsbe::PORE_ERROR_MASK,
                         "PORE_ERROR_MASK = 0x%016llX\n" );            
                printreg(vsbe::PORE_PRV_BASE_ADDR0,
                         "PORE_PRV_BASE_ADDR0 = 0x%016llX\n" );        
                printreg(vsbe::PORE_PRV_BASE_ADDR1,
                         "PORE_PRV_BASE_ADDR1 = 0x%016llX\n" );        
                printreg(vsbe::PORE_OCI_MEMORY_BASE_ADDR0,
                         "PORE_OCI_MEMORY_BASE_ADDR0 = 0x%016llX\n" ); 
                printreg(vsbe::PORE_OCI_MEMORY_BASE_ADDR1,
                         "PORE_OCI_MEMORY_BASE_ADDR1 = 0x%016llX\n" ); 
                printreg(vsbe::PORE_TABLE_BASE_ADDR,
                         "PORE_TABLE_BASE_ADDR = 0x%016llX\n" );       
                printreg(vsbe::PORE_EXE_TRIGGER,
                         "PORE_EXE_TRIGGER = 0x%016llX\n" );           
                printreg(vsbe::PORE_SCRATCH0,
                         "PORE_SCRATCH0 = 0x%016llX\n" );              
                printreg(vsbe::PORE_SCRATCH1,
                         "PORE_SCRATCH1 = 0x%016llX\n" );              
                printreg(vsbe::PORE_SCRATCH2,
                         "PORE_SCRATCH2 = 0x%016llX\n" );              
                printreg(vsbe::PORE_IBUF_01,
                         "PORE_IBUF_01 = 0x%016llX\n" );               
                printreg(vsbe::PORE_IBUF_2,
                         "PORE_IBUF_2 = 0x%016llX\n" );                
                printreg(vsbe::PORE_DBG0,
                         "PORE_DBG0 = 0x%016llX\n" );                  
                printreg(vsbe::PORE_DBG1,
                         "PORE_DBG1 = 0x%016llX\n" );                  
                printreg(vsbe::PORE_PC_STACK0,
                         "PORE_PC_STACK0 = 0x%016llX\n" );             
                printreg(vsbe::PORE_PC_STACK1,
                         "PORE_PC_STACK1 = 0x%016llX\n" );             
                printreg(vsbe::PORE_PC_STACK2,
                         "PORE_PC_STACK2 = 0x%016llX\n" );             
                printreg(vsbe::PORE_ID_FLAGS,
                         "PORE_ID_FLAGS = 0x%016llX\n" );              
                printreg(vsbe::PORE_DATA0,
                         "PORE_DATA0 = 0x%016llX\n" );                 
                printreg(vsbe::PORE_MEM_RELOC,
                         "PORE_MEM_RELOC = 0x%016llX\n" );             
                printreg(vsbe::PORE_I2C_E0_PARAM,
                         "PORE_I2C_E0_PARAM = 0x%016llX\n" );          
                printreg(vsbe::PORE_I2C_E1_PARAM,
                         "PORE_I2C_E1_PARAM = 0x%016llX\n" );          
                printreg(vsbe::PORE_I2C_E2_PARAM,
                         "PORE_I2C_E2_PARAM = 0x%016llX\n" );          
                printreg(vsbe::PORE_HIDDEN_STATE_0,
                         "PORE_HIDDEN_STATE_0 = 0x%016llX\n" );          
                printreg(vsbe::PORE_HIDDEN_STATE_1,
                         "PORE_HIDDEN_STATE_1 = 0x%016llX\n" );          
                printreg(vsbe::PORE_HIDDEN_STATE_2,
                         "PORE_HIDDEN_STATE_2 = 0x%016llX\n" );          
                printreg(vsbe::PORE_HIDDEN_STATE_3,
                         "PORE_HIDDEN_STATE_3 = 0x%016llX\n" );          
                printreg(vsbe::PORE_HIDDEN_STATE_4
                ,        "PORE_HIDDEN_STATE_4 = 0x%016llX\n" );          
            } while (0);
            stateArg->iv_data=p_state;
            fclose( stateArg->iv_fd );
        }
#endif

        if (p_state_allocated)
        {
            delete p_state;
            stateArg->iv_data=NULL;
        }

        if( me != ME_SUCCESS )
        {
            FAPI_ERR( "Model error extracting state. Errno(%i)\n", (int)me);
            FAPI_SET_HWP_ERROR(rc, RC_FAPIPOREVE_ERROR_EXTRACTING_STATE);
        }
    } //if extract state

    //----------------------------------------------------------------------
    // Destroy PoreVe and HookManager
    //----------------------------------------------------------------------
    delete poreve;

#ifndef __HOSTBOOT_MODULE
    HookManager::destroy();
#endif

    return rc;
} //end function

#ifdef FAPIECMD
} //end extern C
#endif 

/*
*************** Do not edit this area ***************
This section is automatically updated by CVS when you check in this file.
Be sure to create CVS comments when you commit so that they are included here.

$Log: fapiPoreVe.C,v $
Revision 1.35  2014/03/31 15:21:37  thi
Added FFDC and callouts

Revision 1.34  2013/12/02 20:49:04  mklight
delete PoreState data created by fapiPoreVe

Revision 1.33  2013/06/25 19:08:33  thi
Fix Hostboot compile error

Revision 1.32  2013/04/05 19:35:32  jeshua
Use dumpOnce() instead of trying to track it ourselves

Revision 1.31  2013/03/27 19:02:48  jeshua
Dump SBE state when SBE executed an unexpected halt instruction

Revision 1.30  2013/02/05 16:14:29  bcbrock
Added the HookManager::dlopen() and ::destroy() APIs to allow the HookManager
to be deleted and all hook DLLs to be unloaded.  This suports the case that
both P8 and Centaur runs of PoreVe need to be made in the same process.

Revision 1.29  2012/09/05 20:11:16  jeshua
More robust return code handling
Cosmetic updates for things like line length

Revision 1.28  2012/09/05 18:32:42  jeshua
Disconnect missing memories

Revision 1.27  2012/04/26 21:30:31  jeshua
file renamed from ../../../fapiporeve/working/fapiPoreVe.C to fapiPoreVe.C

Revision 1.26  2012/04/26 20:52:47  jeshua
file renamed from ../../chips/p8/working/procedures/fapiPoreVe.C to fapiPoreVe.C

Revision 1.25  2012/04/26 14:53:12  jeshua
Use fapi error code generation

Revision 1.24  2012/03/01 20:11:31  jeshua
Updated for PIBMEM support

Revision 1.23  2012/03/01 17:08:22  jeshua
Added a pore dump call on model errors and architected errors

Revision 1.22  2012/01/09 20:55:27  jeshua
Don't include file-related code for hostboot

Revision 1.21  2011/12/07 22:30:46  jeshua
Initial MRR support

Revision 1.20  2011/11/17 18:17:59  jeshua
Fixed state handling so it works with hostboot (hopefully)

Revision 1.19  2011/11/02 23:24:44  bcbrock
Changes required for portability to HBI environment

Revision 1.18  2011/10/14 21:36:58  bcbrock
Added an enumeration of hidden state variables for fapiPoreVe

Revision 1.17  2011/10/06 19:29:34  jeshua
Use poreve->getscom to check sbe vital

Revision 1.16  2011/09/29 22:37:59  jeshua
Fixed some copy-paste problems in the break point code
Added a halt code check when the POREVE stops on a halt

Revision 1.15  2011/09/08 16:03:28  jeshua
Return an rc on an error_halt status

Revision 1.14  2011/09/02 20:54:13  jeshua
Open file for reading when installing state, close it after, open for writing when dumping state, close it after

Revision 1.13  2011/09/02 19:57:06  jeshua
Added state install and extract support

Revision 1.12  2011/07/13 19:13:34  jeshua
Enabled writing of the PNOR at John B's request

Revision 1.11  2011/07/12 16:40:13  jeshua
Breakpoint support

Revision 1.10  2011/07/08 23:52:22  jeshua
Updated for FAPI changes

Revision 1.9  2011/07/07 20:33:32  jeshua
Entry point is no longer in the hooks file

Revision 1.8  2011/06/06 20:47:09  jeshua
Removed workaround for setting the PC

Revision 1.7  2011/06/03 19:49:55  jeshua
Use the create funcion instead of new

Revision 1.6  2011/06/03 14:51:13  jeshua
Preliminary support for pdbg

Revision 1.5  2011/05/24 19:34:07  jeshua
Updated register read

Revision 1.4  2011/05/23 16:24:49  jeshua
Updated for new findGlobalSymbol signature

Revision 1.3  2011/05/20 13:52:12  jeshua
Fixed hook handling
Added entryPoint handling

Revision 1.2  2011/05/16 13:14:34  jeshua
Updated comments
Added hooks code from Bishop
Renamed InstructionCountArg to OtherArg, and added PORE type into it
Use bitwise AND when checking runStatus

Revision 1.1  2011/05/11 19:57:29  jeshua
Initial version




*/
/* Local Variables: */
/* c-basic-offset: 4 */
/* End: */
