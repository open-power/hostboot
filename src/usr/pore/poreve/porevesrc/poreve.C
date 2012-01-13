//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/pore/poreve/porevesrc/poreve.C $
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
// $Id: poreve.C,v 1.15 2011/12/14 22:11:51 bcbrock Exp $

/// \file poreve.C
/// \brief The PORE Virtual Environment

#include "poreve.H"

using namespace vsbe;


////////////////////////////////////////////////////////////////////////////
// PoreVeBase
////////////////////////////////////////////////////////////////////////////


PoreVeBase::PoreVeBase(const PoreIbufId i_id, 
                       const fapi::Target i_masterTarget) :
    iv_pore(i_id),
    iv_pnorMemory(PNOR_ADDRESS_BYTES),
    iv_id(i_id),
    iv_masterTarget(i_masterTarget),
    iv_slaveTarget(i_masterTarget)
{
    uint32_t porePibBase;

    // Configure the PORE.  Only the PIB bus is connected, the OCI bus remains
    // unconnected (0).  The PIB self-SCOM interface configuration is a
    // function of which PORE egine is being configured. Technically we should
    // barf if \a i_id is not PORE_SBE or PORE_SLW, but HBI doesn't want any
    // throw()s.

    if (i_id == PORE_SLW) {
        porePibBase = PORE_SLW_PIB_BASE;
    } else {
        porePibBase = PORE_SBE_PIB_BASE;
    }

    iv_pore.configure(&iv_slaveTarget, &iv_pib, 0,
                      &iv_dataBuffer,
                      porePibBase, PORE_PIB_SIZE, 
                      ACCESS_MODE_READ | ACCESS_MODE_WRITE);

    iv_pib.attachPrimarySlave(&iv_pore);

    // Configure the PNOR controller and attach its memory

    iv_pnorController.configure(&iv_masterTarget,
                                &iv_dataBuffer,
                                PNOR_PIB_BASE,
                                PNOR_PIB_SIZE,
                                ACCESS_MODE_READ | ACCESS_MODE_WRITE);

    iv_pib.attachPrimarySlave(&iv_pnorController);

    iv_pnorController.attachMemory(&iv_pnorMemory,
                                   PNOR_I2C_PORT,
                                   PNOR_I2C_DEVICE_ADDRESS);


    // Configure the PIB catch-all model

    iv_pibDefault.configure(&iv_slaveTarget,
                            &iv_dataBuffer,
                            PIB_DEFAULT_PIB_BASE,
                            PIB_DEFAULT_PIB_SIZE,
                            ACCESS_MODE_READ | ACCESS_MODE_WRITE);

    iv_pib.attachSecondarySlave(&iv_pibDefault);
}


PoreVeBase::~PoreVeBase()
{
}


//  This is a temporary hack: Until the final specification of the reset state
//  of the PORE-SBE engine is available, we initialize the PORE-SBE engine
//  here.  This is simpler than trying to keep the PMX model up to date as we
//  mess with chaging requirements, and it's also better for PMX to assume
//  that the PORE-SBE is halted at PMX-IPL, since PMX/Simics is really a model
//  for OCC firmware.  This initializaton of PORE-SBE is done here rather than
//  in the PoreModel because we have the memory address assumptions here.
//
//  If this is a PORE-SBE, then the machine comes up running from OTPROM.

/// \bug Temporary hack

void
PoreVeBase::reset(fapi::Target i_slaveTarget)
{
    iv_slaveTarget = i_slaveTarget;
    iv_pore.restart();
    HookManager::clearError();

    if (iv_id == PORE_SBE) {

        // The PMX model comes up halted in OCI space.  We set the PC to
        // OTPROM space and run() 0 instructions. This will clear the stop bit
        // to start execution.

        PoreAddress pc;
        uint64_t ran;

        pc.setFromPibAddress(OTPROM_PIB_BASE);
        iv_pore.setPc(pc);
        iv_pore.run(0, ran);
    }
}


int
PoreVeBase::run(uint64_t i_instructions, uint64_t& o_ran)
{
    return iv_pore.run(i_instructions, o_ran);
}


ModelError
PoreVeBase::getscom(const uint32_t i_address, uint64_t& o_data, int& o_rc)
{
    PibTransaction t;

    t.iv_address = i_address;
    t.iv_mode = ACCESS_MODE_READ;
    
    iv_pib.operation(t);

    o_data = t.iv_data;
    o_rc = t.iv_pcbReturnCode;
    return t.iv_modelError;
}


ModelError
PoreVeBase::putscom(const uint32_t i_address, const uint64_t i_data, int& o_rc)
{
    PibTransaction t;

    t.iv_address = i_address;
    t.iv_data = i_data;
    t.iv_mode = ACCESS_MODE_WRITE;
    
    iv_pib.operation(t);

    o_rc = t.iv_pcbReturnCode;
    return t.iv_modelError;
}


////////////////////////////////////////////////////////////////////////////
// PoreVe
////////////////////////////////////////////////////////////////////////////

PoreVe::PoreVe(const PoreIbufId i_id, 
               const fapi::Target i_masterTarget) :
    PoreVeBase(i_id, i_masterTarget),
    iv_seepromMemory(SEEPROM_ADDRESS_BYTES)
{
    uint32_t porePibBase;

    // Reconfigure the Pore - this doesn't hurt anything in the previous
    // configuration in the base class as this is a set of simple pointer and
    // data assignments. But it's another reason to jettison the requirement
    // for the base class.  The PORE was attached to the PIB in the base
    // class.

    if (i_id == PORE_SLW) {
        porePibBase = PORE_SLW_PIB_BASE;
    } else {
        porePibBase = PORE_SBE_PIB_BASE;
    }

    iv_pore.configure(&iv_slaveTarget, &iv_pib, &iv_oci,
                      &iv_dataBuffer,
                      porePibBase, PORE_PIB_SIZE, 
                      ACCESS_MODE_READ | ACCESS_MODE_WRITE);

    // Configure the OTPROM

    iv_otprom.configure(&iv_slaveTarget,
                        &iv_dataBuffer,
                        OTPROM_PIB_BASE,
                        OTPROM_PIB_SIZE,
                        ACCESS_MODE_READ | ACCESS_MODE_EXECUTE,
                        &iv_otpromMemory);

    iv_pib.attachPrimarySlave(&iv_otprom);


    // Configure the PIBMEM

    iv_pibmem.configure(&iv_slaveTarget,
                        &iv_dataBuffer,
                        PIBMEM_PIB_BASE,
                        PIBMEM_PIB_SIZE,
                        ACCESS_MODE_READ |
                        ACCESS_MODE_WRITE |
                        ACCESS_MODE_EXECUTE,
                        &iv_pibmemMemory);

    iv_pib.attachPrimarySlave(&iv_pibmem);


    // Configure the SEEPROM controller

    iv_seepromController.configure(&iv_slaveTarget,
                                   &iv_dataBuffer,
                                   SEEPROM_PIB_BASE,
                                   SEEPROM_PIB_SIZE,
                                   ACCESS_MODE_READ | ACCESS_MODE_WRITE);

    iv_pib.attachPrimarySlave(&iv_seepromController);

    iv_seepromController.attachMemory(&iv_seepromMemory,
                                      SEEPROM_I2C_PORT,
                                      SEEPROM_I2C_DEVICE_ADDRESS);

    // Configure Mainstore

    iv_main.configure(&iv_slaveTarget,
                      &iv_dataBuffer,
                      MAINSTORE_OCI_BASE,
                      MAINSTORE_OCI_SIZE,
                      ACCESS_MODE_READ | ACCESS_MODE_WRITE,
                      &iv_mainMemory);
    
    iv_oci.attachPrimarySlave(&iv_main);


    // Configure SRAM

    iv_sram.configure(&iv_slaveTarget,
                      &iv_dataBuffer,
                      SRAM_OCI_BASE,
                      SRAM_OCI_SIZE,
                      ACCESS_MODE_READ | ACCESS_MODE_WRITE,
                      &iv_sramMemory);

    iv_oci.attachPrimarySlave(&iv_sram);


#ifdef PM_HACKS
    // This device provides write-only access to a single control register in
    // the PMC.

    iv_pmc.configure(&iv_slaveTarget,
                     &iv_dataBuffer,
                     PMC_OCI_BASE,
                     PMC_OCI_SIZE,
                     ACCESS_MODE_WRITE);

    iv_oci.attachPrimarySlave(&iv_pmc);
#endif  // PM_HACKS


#ifdef VBU_HACKS
    // Configure the temporary Pib2Cfam component

    iv_pib2Cfam.configure(&iv_slaveTarget,
                          &iv_dataBuffer,
                          PIB2CFAM_PIB_BASE,
                          PIB2CFAM_PIB_SIZE,
                          ACCESS_MODE_READ | ACCESS_MODE_WRITE);

    iv_pib.attachPrimarySlave(&iv_pib2Cfam);

    // Configure the temporary sbeVital component

    iv_sbeVital.configure(&iv_slaveTarget,
                          &iv_dataBuffer,
                          SBEVITAL_PIB_BASE,
                          SBEVITAL_PIB_SIZE,
                          ACCESS_MODE_READ | ACCESS_MODE_WRITE);

    iv_pib.attachPrimarySlave(&iv_sbeVital);

#ifndef SIMPLE_VBU_HACKS_ONLY

    // The VBU_HACKS above are simple - they don't require complex eCMD support so
    // we can test them easily with the poreve/test/fapistub test case.  

    // The VBU hacks below are complicated to emulate, so we don't even try in
    // the test/fapistub test case.

    // Configure the Broadside scan component if using BROADSIDE scan
    //JDS TODO - add a check for broadside scan mode
    ecmdConfigValid_t validOutput;
    std::string       tmpStr;
    uint32_t          tmpNum;
    uint32_t          rc;
    ecmdChipTarget    e_target;

    //JDS TODO - change this to get attribute
    fapiTargetToEcmdTarget( iv_slaveTarget, e_target);
    rc = ecmdGetConfiguration(e_target, "SIM_BROADSIDE_MODE", 
                              validOutput, tmpStr, tmpNum );
    if( rc ||
        validOutput == ECMD_CONFIG_VALID_FIELD_NONE ||
        validOutput == ECMD_CONFIG_VALID_FIELD_NUMERIC )
    {
        FAPI_ERR( "Unable to determine SIM_BROADSIDE_MODE\n" );
    }
    else
    {
        size_t pos = tmpStr.find( "scan" );
        if( pos != (uint32_t)-1 )
        {
//             iv_bsscan_ex00.configure(&iv_slaveTarget,
//                                      &iv_dataBuffer,
//                                      BSSCAN_PIB_BASE | EX00_PIB_BASE,
//                                      BSSCAN_PIB_SIZE,
//                                      ACCESS_MODE_READ | ACCESS_MODE_WRITE);
            
//             iv_pib.attachPrimarySlave(&iv_bsscan_ex00);

            iv_bsscan_ex01.configure(&iv_slaveTarget,
                                     &iv_dataBuffer,
                                     BSSCAN_PIB_BASE | EX01_PIB_BASE,
                                     BSSCAN_PIB_SIZE,
                                     ACCESS_MODE_READ | ACCESS_MODE_WRITE);
            
            iv_pib.attachPrimarySlave(&iv_bsscan_ex01);
            
            iv_bsscan_ex02.configure(&iv_slaveTarget,
                                     &iv_dataBuffer,
                                     BSSCAN_PIB_BASE | EX02_PIB_BASE,
                                     BSSCAN_PIB_SIZE,
                                     ACCESS_MODE_READ | ACCESS_MODE_WRITE);
            
            iv_pib.attachPrimarySlave(&iv_bsscan_ex02);
            
            iv_bsscan_ex03.configure(&iv_slaveTarget,
                                     &iv_dataBuffer,
                                     BSSCAN_PIB_BASE | EX03_PIB_BASE,
                                     BSSCAN_PIB_SIZE,
                                     ACCESS_MODE_READ | ACCESS_MODE_WRITE);
            
            iv_pib.attachPrimarySlave(&iv_bsscan_ex03);
            
            iv_bsscan_ex04.configure(&iv_slaveTarget,
                                     &iv_dataBuffer,
                                     BSSCAN_PIB_BASE | EX04_PIB_BASE,
                                     BSSCAN_PIB_SIZE,
                                     ACCESS_MODE_READ | ACCESS_MODE_WRITE);
            
            iv_pib.attachPrimarySlave(&iv_bsscan_ex04);
            
            iv_bsscan_ex05.configure(&iv_slaveTarget,
                                     &iv_dataBuffer,
                                     BSSCAN_PIB_BASE | EX05_PIB_BASE,
                                     BSSCAN_PIB_SIZE,
                                     ACCESS_MODE_READ | ACCESS_MODE_WRITE);
            
            iv_pib.attachPrimarySlave(&iv_bsscan_ex05);
            
            iv_bsscan_ex06.configure(&iv_slaveTarget,
                                     &iv_dataBuffer,
                                     BSSCAN_PIB_BASE | EX06_PIB_BASE,
                                     BSSCAN_PIB_SIZE,
                                     ACCESS_MODE_READ | ACCESS_MODE_WRITE);
            
            iv_pib.attachPrimarySlave(&iv_bsscan_ex06);

//             iv_bsscan_ex07.configure(&iv_slaveTarget,
//                                      &iv_dataBuffer,
//                                      BSSCAN_PIB_BASE | EX07_PIB_BASE,
//                                      BSSCAN_PIB_SIZE,
//                                      ACCESS_MODE_READ | ACCESS_MODE_WRITE);
            
//             iv_pib.attachPrimarySlave(&iv_bsscan_ex07);
            
//             iv_bsscan_ex08.configure(&iv_slaveTarget,
//                                      &iv_dataBuffer,
//                                      BSSCAN_PIB_BASE | EX08_PIB_BASE,
//                                      BSSCAN_PIB_SIZE,
//                                      ACCESS_MODE_READ | ACCESS_MODE_WRITE);
            
//             iv_pib.attachPrimarySlave(&iv_bsscan_ex08);
            
            iv_bsscan_ex09.configure(&iv_slaveTarget,
                                     &iv_dataBuffer,
                                     BSSCAN_PIB_BASE | EX09_PIB_BASE,
                                     BSSCAN_PIB_SIZE,
                                     ACCESS_MODE_READ | ACCESS_MODE_WRITE);
            
            iv_pib.attachPrimarySlave(&iv_bsscan_ex09);
            
            iv_bsscan_ex10.configure(&iv_slaveTarget,
                                     &iv_dataBuffer,
                                     BSSCAN_PIB_BASE | EX10_PIB_BASE,
                                     BSSCAN_PIB_SIZE,
                                     ACCESS_MODE_READ | ACCESS_MODE_WRITE);
            
            iv_pib.attachPrimarySlave(&iv_bsscan_ex10);
            
            iv_bsscan_ex11.configure(&iv_slaveTarget,
                                     &iv_dataBuffer,
                                     BSSCAN_PIB_BASE | EX11_PIB_BASE,
                                     BSSCAN_PIB_SIZE,
                                     ACCESS_MODE_READ | ACCESS_MODE_WRITE);
            
            iv_pib.attachPrimarySlave(&iv_bsscan_ex11);
            
            iv_bsscan_ex12.configure(&iv_slaveTarget,
                                     &iv_dataBuffer,
                                     BSSCAN_PIB_BASE | EX12_PIB_BASE,
                                     BSSCAN_PIB_SIZE,
                                     ACCESS_MODE_READ | ACCESS_MODE_WRITE);
            
            iv_pib.attachPrimarySlave(&iv_bsscan_ex12);
            
            iv_bsscan_ex13.configure(&iv_slaveTarget,
                                     &iv_dataBuffer,
                                     BSSCAN_PIB_BASE | EX13_PIB_BASE,
                                     BSSCAN_PIB_SIZE,
                                     ACCESS_MODE_READ | ACCESS_MODE_WRITE);
            
            iv_pib.attachPrimarySlave(&iv_bsscan_ex13);
            
            iv_bsscan_ex14.configure(&iv_slaveTarget,
                                     &iv_dataBuffer,
                                     BSSCAN_PIB_BASE | EX14_PIB_BASE,
                                     BSSCAN_PIB_SIZE,
                                     ACCESS_MODE_READ | ACCESS_MODE_WRITE);
            
            iv_pib.attachPrimarySlave(&iv_bsscan_ex14);

//             iv_bsscan_ex15.configure(&iv_slaveTarget,
//                                      &iv_dataBuffer,
//                                      BSSCAN_PIB_BASE | EX15_PIB_BASE,
//                                      BSSCAN_PIB_SIZE,
//                                      ACCESS_MODE_READ | ACCESS_MODE_WRITE);
            
//             iv_pib.attachPrimarySlave(&iv_bsscan_ex15);
        } //end SIM_BROADSIDE_MODE has scan
    } //end was able to read SIM_BROADSIDE_MODE

#endif  // SIMPLE_VBU_HACKS_ONLY
#endif  // VBU_HACKS
}


PoreVe::~PoreVe()
{
}



    

    


    
    
    

