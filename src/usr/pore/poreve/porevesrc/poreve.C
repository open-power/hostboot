/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/porevesrc/poreve.C $                      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
// $Id: poreve.C,v 1.27 2012/12/06 18:03:52 bcbrock Exp $

/// \file poreve.C
/// \brief The PORE Virtual Environment

#include "poreve.H"

using namespace vsbe;
using namespace fapi;


////////////////////////////////////////////////////////////////////////////
// PoreVeBase
////////////////////////////////////////////////////////////////////////////


PoreVeBase::PoreVeBase(const PoreIbufId i_id, 
                       const fapi::Target i_masterTarget) :
    iv_pore(i_id),
    iv_id(i_id),
    iv_masterTarget(i_masterTarget),
    iv_slaveTarget(i_masterTarget)
{
    uint32_t porePibBase;
    uint8_t pnorI2cAddressBytes;

    do {

        if (iv_constructorRc) break;

        // Configure the PORE.  Only the PIB bus is connected, the OCI bus
        // remains unconnected (0).  The PIB self-SCOM interface configuration
        // is a function of which PORE egine is being configured. Technically
        // we should barf if \a i_id is not PORE_SBE or PORE_SLW, but HBI
        // doesn't want any throw()s.

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

        // Configure the PNOR controller and configure and attach its memory.
        // The PNOR controller PORE I2C configuration will also be saved away
        // for use with Centaur targets; See the documentation for
        // iv_pnorI2cParam and the code for the reset() method.

        iv_constructorRc = FAPI_ATTR_GET(ATTR_PNOR_I2C_ADDRESS_BYTES, 
                                          &iv_masterTarget,
                                          pnorI2cAddressBytes);
        if (iv_constructorRc) {
            FAPI_ERR("Unable to get ATTR_PNOR_I2C_ADDRESS_BYTES");
            break;
        }

        FAPI_DBG("ATTR_PNOR_I2C_ADDRESS_BYTES attribute = %u",
                 pnorI2cAddressBytes);

        iv_pnorController.configure(&iv_masterTarget,
                                    &iv_dataBuffer,
                                    PNOR_PIB_BASE,
                                    PNOR_PIB_SIZE,
                                    ACCESS_MODE_READ | ACCESS_MODE_WRITE);

        iv_pib.attachPrimarySlave(&iv_pnorController);

        iv_pnorMemory.configure(pnorI2cAddressBytes);

        iv_pnorController.attachMemory(&iv_pnorMemory,
                                       PNOR_I2C_PORT,
                                       PNOR_I2C_DEVICE_ADDRESS);

        memset(iv_lpcRegisterSpace, 0, LPC_REGISTER_SPACE_SIZE);

        iv_pnorMemory.map(LPC_REGISTER_SPACE_BASE,
                          LPC_REGISTER_SPACE_SIZE,
                          ACCESS_MODE_READ | ACCESS_MODE_WRITE,
                          &iv_lpcRegisterSpace,
                          0);

        iv_pnorI2cParam.val = 0;
        iv_pnorI2cParam.i2c_engine_identifier = (PNOR_PIB_BASE >> 16) & 0xf;
        iv_pnorI2cParam.i2c_engine_address_range = 4;

        // Configure the PIB catch-all model

        iv_pibDefault.configure(&iv_slaveTarget,
                                &iv_dataBuffer,
                                PIB_DEFAULT_PIB_BASE,
                                PIB_DEFAULT_PIB_SIZE,
                                ACCESS_MODE_READ | ACCESS_MODE_WRITE);

        iv_pib.attachSecondarySlave(&iv_pibDefault);

    } while (0);
}


PoreVeBase::~PoreVeBase()
{
}


fapi::ReturnCode
PoreVeBase::reset(fapi::Target i_slaveTarget)
{
    fapi::ReturnCode rc;

    HookManager::clearError();
    iv_slaveTarget = i_slaveTarget;
    iv_pore.restart();

    // If the slave target is Centaur, set up I2C_E0_PARAM to allow the
    // Centaur PNOR image to execute.  This is only done for Centaur since
    // Centaur SBE code is always run virtually.

    /// \bug This does not work yet, but it doesn't hurt (much) to go ahead
    /// and initialize the register.

    uint8_t name;
    rc = FAPI_ATTR_GET_PRIVILEGED(ATTR_NAME, &i_slaveTarget, name);
    if (!rc) {

        FAPI_DBG("ATTR_NAME attribute = %u\n", name);

        if (name == ENUM_ATTR_NAME_CENTAUR) {
            iv_pore.registerWrite(PORE_I2C_E0_PARAM, iv_pnorI2cParam.val);
        }
    }

    return rc;
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


ModelError
PoreVeBase::getmemInteger(const PoreAddress i_address,
                          uint64_t& o_data,
                          const size_t i_size)
{
    return iv_pore.getmemInteger(i_address, o_data, i_size);
}


ModelError
PoreVeBase::putmemInteger(const PoreAddress i_address,
                          uint64_t i_data,
                          const size_t i_size)
{
    return iv_pore.putmemInteger(i_address, i_data, i_size);
}


fapi::ReturnCode
PoreVeBase::constructorRc()
{
    return iv_constructorRc;
}


fapi::ReturnCode
PoreVeBase::poreRc()
{
    return iv_pore.getFapiReturnCode();
}


////////////////////////////////////////////////////////////////////////////
// PoreVe
////////////////////////////////////////////////////////////////////////////

PoreVe::PoreVe(const PoreIbufId i_id, 
               const fapi::Target i_masterTarget,
               const bool i_useSecondarySeepromConfig) :
    PoreVeBase(i_id, i_masterTarget),
    iv_pibmem(PIBMEM_PIB_SIZE)
{
    uint32_t porePibBase;
    uint8_t seepromI2cAddressBytes;
    uint8_t seepromI2cDeviceAddress[2];
    uint8_t seepromI2cPort[2];
    int seepromConfig;

    do {

        // Reconfigure the Pore - this doesn't hurt anything in the previous
        // configuration in the base class as this is a set of simple pointer
        // and data assignments. But it's another reason to jettison the
        // requirement for the base class.  The PORE was attached to the PIB
        // in the base class.

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


        // Configure the PIBMEM.  Unlike the other memories that represent
        // pre-programmed ROM memories, the PIBMEM is an uninitialized RAM, and
        // arguably we could allocate a blank image for it here.  However for
        // consistency (and ease of checkpointing) we require the user to
        // explicitly provide and map a PIBMEM image, which should be of size
        // (PIBMEM_PIB_REGISTERS * 8) bytes.

        iv_pibmem.configure(&iv_slaveTarget,
                            &iv_dataBuffer,
                            PIBMEM_PIB_BASE,
                            PIBMEM_PIB_SIZE,
                            ACCESS_MODE_READ |
                            ACCESS_MODE_WRITE |
                            ACCESS_MODE_EXECUTE,
                            &iv_pibmemMemory);

        iv_pib.attachPrimarySlave(&iv_pibmem);


        // Configure the SEEPROM controller and its memory

        seepromConfig = (i_useSecondarySeepromConfig ? 1 : 0);

        iv_constructorRc = FAPI_ATTR_GET(ATTR_SBE_SEEPROM_I2C_ADDRESS_BYTES, 
                                         &iv_masterTarget,
                                         seepromI2cAddressBytes);
        if (iv_constructorRc) {
            FAPI_ERR("Unable to get ATTR_SBE_SEEPROM_I2C_ADDRESS_BYTES");
            break;
        }
        FAPI_DBG("ATTR_SBE_SEEPROM_I2C_ADDRESS_BYTES attribute = %u",
                 seepromI2cAddressBytes);


        iv_constructorRc = FAPI_ATTR_GET(ATTR_SBE_SEEPROM_I2C_DEVICE_ADDRESS,
                                         &iv_masterTarget,
                                         seepromI2cDeviceAddress);
        if (iv_constructorRc) {
            FAPI_ERR("Unable to get ATTR_SBE_SEEPROM_I2C_DEVICE_ADDRESS");
            break;
        }
        FAPI_DBG("ATTR_SBE_SEEPROM_I2C_DEVICE_ADDRESS attribute = "
                 "{0x%02x, 0x%02x}",
                 seepromI2cDeviceAddress[0],
                 seepromI2cDeviceAddress[1]);


        iv_constructorRc = FAPI_ATTR_GET(ATTR_SBE_SEEPROM_I2C_PORT,
                                         &iv_masterTarget,
                                         seepromI2cPort);
        if (iv_constructorRc) {
            FAPI_ERR("Unable to get ATTR_SBE_SEEPROM_I2C_PORT");
            break;
        }
        FAPI_DBG("ATTR_SBE_SEEPROM_I2C_PORT attribute = "
                 "{%u, %u}", 
                 seepromI2cPort[0],
                 seepromI2cPort[1]);

        iv_seepromController.configure(&iv_slaveTarget,
                                       &iv_dataBuffer,
                                       SEEPROM_PIB_BASE,
                                       SEEPROM_PIB_SIZE,
                                       ACCESS_MODE_READ | ACCESS_MODE_WRITE);

        iv_pib.attachPrimarySlave(&iv_seepromController);

        iv_seepromMemory.configure(seepromI2cAddressBytes);

        iv_seepromController.
            attachMemory(&iv_seepromMemory,
                         seepromI2cPort[seepromConfig],
                         seepromI2cDeviceAddress[seepromConfig]);

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
        // This device provides write-only access to a single control register
        // in the PMC.

        iv_pmc.configure(&iv_slaveTarget,
                         &iv_dataBuffer,
                         PMC_OCI_BASE,
                         PMC_OCI_SIZE,
                         ACCESS_MODE_WRITE);

        iv_oci.attachPrimarySlave(&iv_pmc);
#endif  // PM_HACKS

        // Note: Optional components are always present in the model and
        // always configured, but may not be attached to the busses.  This
        // simpifies certain types of testing.

        // Configure the Pib2Cfam component to remap MBOX scom addresses to
        // cfam addresses.
        uint8_t fsi_gpreg_scom_access;

        iv_constructorRc = FAPI_ATTR_GET( ATTR_FSI_GP_REG_SCOM_ACCESS, 
                                          &iv_masterTarget, 
                                          fsi_gpreg_scom_access);
        if (iv_constructorRc) {
            FAPI_ERR( "Unable to get ATTR_FSI_GP_REG_SCOM_ACCESS for target\n" );
            break;
        }

        iv_pib2Cfam.configure(&iv_slaveTarget,
                              &iv_dataBuffer,
                              PIB2CFAM_PIB_BASE,
                              PIB2CFAM_PIB_SIZE,
                              ACCESS_MODE_READ | ACCESS_MODE_WRITE);

        if( !fsi_gpreg_scom_access ) {
            iv_pib.attachPrimarySlave(&iv_pib2Cfam);
        }

        // Configure the sbeVital register emulation
        uint8_t use_hw_sbe_vital_register;

        iv_constructorRc = FAPI_ATTR_GET( ATTR_CHIP_HAS_SBE,
                                          &iv_masterTarget, 
                                          use_hw_sbe_vital_register );
        if (iv_constructorRc) {
            FAPI_ERR( "Unable to get ATTR_CHIP_HAS_SBE for target\n" );
            break;
        }

        iv_sbeVital.configure(&iv_slaveTarget,
                              &iv_dataBuffer,
                              SBEVITAL_PIB_BASE,
                              SBEVITAL_PIB_SIZE,
                              ACCESS_MODE_READ | ACCESS_MODE_WRITE);

        if( !use_hw_sbe_vital_register ) {
            iv_pib.attachPrimarySlave(&iv_sbeVital);
        }

    } while (0);
}


PoreVe::~PoreVe()
{
}


ModelError
PoreVe::detachSlave(Slave* i_slave)
{
    ModelError me;

    me = iv_pib.detachSlave(i_slave);
    if (me) {
        me = iv_oci.detachSlave(i_slave);
    }
    return me;
}
