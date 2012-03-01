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
// $Id: poreve.C,v 1.16 2012/02/27 22:54:15 jeshua Exp $

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


    // Configure the Pib2Cfam component to remap MBOX scom addresses to cfam addresses
    uint8_t fsi_gpreg_scom_access;
    fapi::ReturnCode frc;

    //JDS TODO - uncomment this when the model actually works
//     frc = FAPI_ATTR_GET( ATTR_FSI_GP_REG_SCOM_ACCESS, &iv_slaveTarget, fsi_gpreg_scom_access );
    fsi_gpreg_scom_access = 0;

    if(!frc.ok()) {
      FAPI_ERR( "Unable to get ATTR_FSI_GP_REG_SCOM_ACCESS for target\n" );
      //JDS TODO - create an actual fapi error
      //      FAPI_SET_HWP_ERROR( frc, "Unable to get ATTR_FSI_GP_REG_SCOM_ACCESS for target\n" );
    }
    if( !fsi_gpreg_scom_access ) {
      iv_pib2Cfam.configure(&iv_slaveTarget,
                            &iv_dataBuffer,
                            PIB2CFAM_PIB_BASE,
                            PIB2CFAM_PIB_SIZE,
                            ACCESS_MODE_READ | ACCESS_MODE_WRITE);

      iv_pib.attachPrimarySlave(&iv_pib2Cfam);
    }

    // Configure the sbeVital register emulation
    uint8_t use_hw_sbe_vital_register;

    // JDS TODO - this needs to be done with an attribute (ATTR_USE_HW_SBE_VITAL_REGISTER requested)
//     frc = FAPI_ATTR_GET( ATTR_USE_HW_SBE_VITAL_REGISTER, &iv_slaveTarget, use_hw_sbe_vital_register );
//     if(!frc.ok()) {
//       FAPI_ERR( "Unable to get ATTR_USE_HW_SBE_VITAL_REGISTER for target\n" );
//       //JDS TODO - create an actual fapi error
//       //      FAPI_SET_HWP_ERROR( frc, "Unable to get ATTR_USE_HW_SBE_VITAL_REGISTER for target\n" );
//     }
    use_hw_sbe_vital_register = 0; //JDS TODO - TMP until the attribute is supported and the hardware allows access to the register

    if( !use_hw_sbe_vital_register ) {
      iv_sbeVital.configure(&iv_slaveTarget,
                            &iv_dataBuffer,
                            SBEVITAL_PIB_BASE,
                            SBEVITAL_PIB_SIZE,
                            ACCESS_MODE_READ | ACCESS_MODE_WRITE);

      iv_pib.attachPrimarySlave(&iv_sbeVital);
    }

}


PoreVe::~PoreVe()
{
}



    

    


    
    
    

