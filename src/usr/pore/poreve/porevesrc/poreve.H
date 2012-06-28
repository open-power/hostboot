/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/pore/poreve/porevesrc/poreve.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#ifndef __VSBE_POREVE_H
#define __VSBE_POREVE_H

// $Id: poreve.H,v 1.25 2012/06/18 23:38:37 bcbrock Exp $

/// \file poreve.H
/// \brief The PORE Virtual Environment
///
/// The PORE Virtual Environment is a container class that contains a Pore
/// model along with the Bus and Memory models that comprise a Pore system.
/// These system models offer very little in the way of interfaces other than
/// a way to reset() the simulation and a run() method to clock the
/// simulation. Instead, most operations on the PORE (including setting up the
/// initial state) are performed directly on the Pore model data member \a
/// iv_pore itself.  Similarly, memories are configured by map() operations
/// directly on the memory objects.
///
/// The system components are created and interconnected in a simple two-step
/// process:
///
/// - When objects are created any truly static configuration parameters are
/// passed as arguments of the constructor.
///
/// - After all components are constructed, simple code sequences stitch
/// together the components using a configure() method provided by each class
/// of component.
///
/// This two-step sequence eliminates the problem of loops that would arise if
/// we tried to configure the network in the constructor, and is very similar
/// to the way that Simics models are configured.
///
/// The final PoreVe model is constructed in two steps. We first define a
/// PoreVeBase model.  This is a stripped down environment that only contains
/// a PORE engine and the exact components required for the HBI application of
/// PORE-SBE.  The Vsbe facade class is later provided as the interface to
/// PoreVeBase.
///
/// The second step of the derivation is to add all of the remaining
/// components to create the full PoreVe model for use in VBU and lab
/// applications.  The derivation is done this way to make the PoreVeBase as
/// small as possible in terms of both code and data size.  Ideally however
/// the differences (in code and data size) will turn out to be small enough
/// such that we can drop the separate models and simply always create the
/// full PoreVe model, using the Vsbe facade as the high-level interface for
/// HBI. Frankly, the system design would probably be more robust if we had
/// only one model - we may go ahead and merge the models anyway.

#include <stdint.h>
#include <stdarg.h>

#include "fapi.H"

#include "fasti2c.H"
#include "pibmem.H"
#include "poremodel.H"
#include "poreregister.H"
#include "pore.H"

#include "pib2cfam.H"
#include "sbevital.H"

#ifdef VBU_HACKS
#include "bsscan.H"
#endif  // VBU_HACKS

#ifndef POREVE_STATISTICS
#define POREVE_STATISTICS 0
#endif

namespace vsbe {

    class PoreVeBase;
    class PoreVe;

    /// \defgroup poreve_config Parameters of PoreVe Configurations
    ///
    /// These parameters are required for configuring the PoreVe system model.
    ///
    /// \bug Many of these parameters are fake for now and will be system
    /// dependent.
    ///
    /// @{

    //////////////////////////////////////////////////////////////////////
    // PORE
    //////////////////////////////////////////////////////////////////////

    /// The PIB base address of PORE-SBE control registers
    const uint32_t PORE_SBE_PIB_BASE = 0x000e0000;

    /// The PIB base address of PORE-SLW control registers
    const uint32_t PORE_SLW_PIB_BASE = 0x00068000;

    /// The size of the PORE control register space.
    const uint64_t PORE_PIB_SIZE = ((uint64_t)SIZEOF_VISIBLE_PORE_STATE) / 8;


    //////////////////////////////////////////////////////////////////////
    // OTPROM
    //////////////////////////////////////////////////////////////////////

    /// The PIB base address of the OTPROM memory controller
    const uint32_t OTPROM_PIB_BASE = 0x00018000;

    /// The number of PIB \e registers defined by the OTPROM memory controller
    ///
    /// PIB memories are 8-byte \e word addressed. The maximum amount of
    /// memory accessible through the controller is (OTPROM_PIB_SIZE * 8)
    /// bytes.
    const uint64_t OTPROM_PIB_SIZE = 0x200;


    //////////////////////////////////////////////////////////////////////
    // PIBMEM
    //////////////////////////////////////////////////////////////////////

    /// The PIB base address of the PIBMEM memory controller
    const uint32_t PIBMEM_PIB_BASE = 0x00080000;

    /// The number of PIB \e registers defined by the PIBMEM memory controller
    ///
    /// PIB memories are 8-byte \e word addressed. The maximum amount of
    /// memory accessible through the controller is (PIBMEM_PIB_REGISTERS * 8)
    /// bytes (3KB).
    const uint64_t PIBMEM_PIB_REGISTERS = 0x180;


    //////////////////////////////////////////////////////////////////////
    // PNOR
    //////////////////////////////////////////////////////////////////////

    /// The PIB base address of the PNOR (LPCM) memory controller
    const uint32_t PNOR_PIB_BASE = 0x000b0000;

    /// The number of registers defined by the PNOR memory controller
    const size_t PNOR_PIB_SIZE = LPCM_REGISTERS;

    /// The PNOR I2C Port Number
    ///
    /// When the ECCAX unit is configured for access to the LPC (PNOR)
    /// interface, the I2C port and I2C device address are ignored by the
    /// unit, however we go ahead and define these constants as 0 for the
    /// benefit of our generic I2C controller model.
    const unsigned PNOR_I2C_PORT = 0;

    /// The PNOR I2C Device Address
    const unsigned PNOR_I2C_DEVICE_ADDRESS = 0;


    //////////////////////////////////////////////////////////////////////
    // SEEPROM
    //////////////////////////////////////////////////////////////////////

    /// The PIB base address of the SEEPROM memory controller
    const uint32_t SEEPROM_PIB_BASE = 0x000c0000;

    /// The number of registers defined by the SEEPROM memory controller
    const uint64_t SEEPROM_PIB_SIZE = FASTI2C_REGISTERS;


    //////////////////////////////////////////////////////////////////////
    // PIB Default Catch-All Model
    //////////////////////////////////////////////////////////////////////

    /// The PIB base address of the default PIB slave
    const uint32_t PIB_DEFAULT_PIB_BASE = 0x0;

    /// The number of registers defined by the default PIB slave
    const uint64_t PIB_DEFAULT_PIB_SIZE = 0x100000000ull;


    //////////////////////////////////////////////////////////////////////
    // OCI-Attached Components
    //////////////////////////////////////////////////////////////////////

    /// The OCI base address of the OCI PBA->Mainstore bridge
    ///
    /// We go ahead and map the entire 1GB. During configuration the actual
    /// memory area in use will be defined by Memory::map() calls.
    const uint32_t MAINSTORE_OCI_BASE = 0x00000000;

    /// The OCI PBA->Mainstore bridge maps 1GB of the address space
    const uint64_t MAINSTORE_OCI_SIZE = 0x40000000;


    /// The OCI base address of the SRAM
    const uint32_t SRAM_OCI_BASE = 0xfff80000;

    /// The OCI SRAM is 512KB
    const uint64_t SRAM_OCI_SIZE = 0x00080000;

    /// The OCI address of the PMC_PORE_REQ_STAT_REG Register
    ///
    /// This is the only OCI control register that PORE-SLW should access, so
    /// its size is limited to 8 bytes.
    const uint32_t PMC_OCI_BASE = 0x40010480;

    /// PORE-SLW is only allowed to access a specific 8 bytes of the OCI
    /// control register space.
    const uint64_t PMC_OCI_SIZE = 8;

    /// @}
};


////////////////////////////////////////////////////////////////////////////
// PoreVeBase
////////////////////////////////////////////////////////////////////////////

/// The base class (HBI-only components) of PoreVe.
///
/// This model contains only those components required for HBI applications
/// of the PORE virtual environment.  Currently this is only 
///
/// - A Pore
/// - A PIB bus
/// - A PNOR memory model
/// - A PibSlave to catch any getscom()/putscom() destined for the PIB

class 
vsbe::PoreVeBase {

public:

    ////////////////////////////// Creators //////////////////////////////

    /// Construct the PoreVeBase
    ///
    /// \param[in] i_id The PORE IBUF_ID (engine type) of the Pore component.
    /// This will be PORE_SBE for host boot/SBE applications, and PORE_SLW for
    /// testing Sleep/Winkle applications. 
    ///
    /// \param[in] i_masterTarget  The fapi::Target associated with the master
    /// chip in an HBI master/slave configuration.  This target is also
    /// installed into \a iv_slaveTarget by the constructor.
    PoreVeBase(const PoreIbufId i_id, const fapi::Target i_masterTarget);

    virtual ~PoreVeBase();


    ////////////////////  Simulation Interface    /////////////////////////

    /// Reset the simulation and target a new slave
    ///
    /// \param[in] i_slaveTarget  The slave target of the new slave
    ///
    /// The reset() method is provided to cleanly reset the simulator for
    /// simulation with a new slave target. 
    ///
    /// If the embedded PORE engine is PORE-SBE, then this method simulates
    /// the auto-POR sequence for the engine, and the engine comes up with a
    /// 'running' status at the correct auto-POR branch table address.  For
    /// other engines the application is responsible for setting up the
    /// register state of the Pore and invoking the run() method to begin
    /// simulation. As a side effect, any error status is also cleared from
    /// the HookManager.
    ///
    /// If the slave target is Centaur, then this method also takes the step
    /// of initializing the I2C_E0_PARAM register to allow the Centaur "PNOR"
    /// image to access the virtual PNOR.
    ///
    /// \returns The return code from the call of FAPI_ATTR_GET_PRIVILEGED()
    /// used to determine the target type.
    virtual fapi::ReturnCode
    reset(fapi::Target i_slaveTarget);

    
    /// See PoreModel::run()
    ///
    /// This API is provided as a convenience.  Currently the only model in
    /// the system that is 'clocked' is the PoreModel.
    virtual int
    run(const uint64_t i_instructions, uint64_t& o_ran);


    /// Run a 'getscom' on the virtual PIB
    ///
    /// \param[in] i_address A 32-bit SCOM address
    ///
    /// \param[out] o_data The 64-bit SCOM data returned from the read
    ///
    /// \param[out] o_rc The 3-bit PIB/PCB error code returned from the PIB
    /// transaction, see the PcbReturnCode enum in transaction.H.
    ///
    /// This method allows a caller to run a read transaction on the virtual
    /// PIB bus, observing the same PIB configuration seen by the virtual PORE
    /// engine. Accesses of PIB/PCB addresses that are modeled in the virtual
    /// model return modeled results, and accesses of non-modeled addresses
    /// are converted into FAPI calls.
    ///
    /// \note Use the getmemInteger() method to read from OCI/I2C memory
    /// spaces.
    ///
    /// \returns A return value of 0 indicates success of the method call, but
    /// does not guarantee that the PIB transaction succeeded. It will also be
    /// necessary to also observe that PIB/PCB return code \a o_rc was
    /// returned as 0.  A non-0 return code from the method indicates a
    /// modeling error.
    virtual ModelError
    getscom(const uint32_t i_address, uint64_t& o_data, int& o_rc);


    /// Run a 'putscom' on the virtual PIB
    ///
    /// \param[in] i_address A 32-bit SCOM address
    ///
    /// \param[out] i_data The 64-bit SCOM write data
    ///
    /// \param[out] o_rc The 3-bit PIB/PCB error code returned from the PIB
    /// transaction, see the PcbReturnCode enum in transaction.H.
    ///
    /// This method allows a caller to run a write transaction on the virtual
    /// PIB bus, observing the same PIB configuration seen by the virtual PORE
    /// engine. Accesses of PIB/PCB addresses that are modeled in the virtual
    /// model update modeled registers, and accesses of non-modeled addresses
    /// are converted into FAPI calls.
    ///
    /// \note Use the putmemInteger() method to write to OCI/I2C memory
    /// spaces.
    ///
    /// \returns A return value of 0 indicates success of the method call, but
    /// does not guarantee that the PIB transaction succeeded. It will also be
    /// necessary to also observe that PIB/PCB return code \a o_rc was
    /// returned as 0.  A non-0 return code from the method indicates a
    /// modeling error.
    virtual ModelError
    putscom(const uint32_t i_address, const uint64_t i_data, int& o_rc);

    
    /// See PoreModel::getmemInteger()
    virtual ModelError
    getmemInteger(const PoreAddress i_address,
                  uint64_t& o_data,
                  const size_t i_size);


    /// See PoreModel::putmemInteger()
    virtual ModelError
    putmemInteger(const PoreAddress i_address,
                  uint64_t i_data,
                  const size_t i_size);


    /// Return the FAPI return code associated with constructing the PoreVe
    /// object. 
    ///
    /// Any application constucting a PoreVe object must check that the object
    /// was constructed without error by using this method.
    virtual fapi::ReturnCode 
    constructorRc();


    /// Return the last FAPI return code from any PORE operations in the
    /// virtual environment. 
    ///
    /// If the status returned by run() includes the bit
    /// PORE_STATUS_MODEL_ERROR, then calling poreRc() will return the FAPI
    /// return code associated with the error, if any.
    virtual fapi::ReturnCode
    poreRc();


    //////////////////// Public Implementation ////////////////////////////

    /// The Pore model
    Pore iv_pore;

    /// The PIB bus model
    Bus iv_pib;

    /// The PNOR controller model
    FastI2cController iv_pnorController;

    /// The PNOR memory model
    I2cMemory iv_pnorMemory;

    /// The secondary PIB slave.
    ///
    /// This slave routes all operations that do not hit in a PIB-attached
    /// memory model to hardware via FAPI getscom/putcom.
    PibSlave iv_pibDefault;


    //////////////////// Protected Implementation ///////////////////////////

protected:

    /// The PORE IBUF ID of the PORE engine
    PoreIbufId iv_id;

    /// The master fapi::Target
    ///
    /// HBI applications differentiate between the \e master chip that is
    /// brought up first, and the \e slave chips that the master then
    /// initializes.  The master target is considered a constant and is
    /// provided in the constructor.  The master target is always associated
    /// with the PNOR; the other memory components are associated with the
    /// slave target.  A pointer to this data member is provided to the PNOR
    /// model during configuration.
    fapi::Target iv_masterTarget;


    /// The slave fapi::Target
    ///
    /// HBI applications differentiate between the \e master chip that is
    /// brought up first, and the \e slave chips that the master then
    /// initializes.  The slave target is considered a variable and the
    /// reset() method is provided to safely reset the system and modify the
    /// slave target after construction.  Note that the slave target is
    /// initialized to be identical to the master target by the constructor.
    /// A pointer to this data member is provided to all slaves other that the
    /// PNOR model during configuration.
    fapi::Target iv_slaveTarget;

    
    /// The common ecmdDataBufferBase for all FAPI APIs
    ///
    /// To save memory space we only allocate one FAPI data buffer that is
    /// used by all FAPI APIs that require a ecmdDataBuffer.  A pointer to
    /// this data member is provided to all slaves during configuration.
    ecmdDataBufferBase iv_dataBuffer;

    /// The FAPI return code associated with object construction
    ///
    /// Constructing a PoreVe object entails making FAPI and other API calls
    /// that may fail, however the host boot environment does not support
    /// exceptions, only FAPI return codes. To the extent possible, the
    /// constructor is coded such that this member holds the first non-OK
    /// return code encountered during construction, if any. Any application
    /// constucting a PoreVe object must check that the object was constructed
    /// without error by using the constructorRc() method.
    fapi::ReturnCode iv_constructorRc;

    /// The I2C setup for the PNOR controller
    ///
    /// When the PoreVe-SBE is being used to bring up the Centaur, this data
    /// member holds the I2C parameters required to allow the SBE to access
    /// the virtual PNOR containing the Centaur IPL code.  For processor IPL
    /// the IPL code itself does all setup, but since Centaur is only brought
    /// up virtually we elected to do this one piece of setup behind the
    /// scenes in the reset() method.
    pore_i2c_en_param_reg iv_pnorI2cParam;


    ///////////////////////////// Safety //////////////////////////////////

private:
    PoreVeBase(const PoreVeBase& i_rhs);
    PoreVeBase& operator=(const PoreVeBase& i_rhs);
};
    

////////////////////////////////////////////////////////////////////////////
// PoreVe
////////////////////////////////////////////////////////////////////////////


/// The full PoreVe configuration
///
/// This derivation from PoreVeBase adds the remaining PIB models not required
/// by the HBI application, as well as all of the OCI models.  Note that
/// unlike the PIB there is no catch-all for OCI accesses; An access must hit
/// within one of the defined memory maps, otherwise the access is considered
/// an error.

class
vsbe::PoreVe : public vsbe::PoreVeBase {

public:

    ////////////////////////////// Creators //////////////////////////////

    /// Construct the PoreVe
    ///
    /// \param[in] i_id The PORE IBUF_ID (engine type) of the Pore component.
    /// This will be PORE_SBE for host boot/SBE applications, and PORE_SLW for
    /// testing Sleep/Winkle applications. 
    ///
    /// \param[in] i_masterTarget  The fapi::Target associated with the master
    /// chip in an HBI master/slave configuration.  This target is also
    /// installed into \a iv_slaveTarget by the constructor.
    ///
    /// \param[in] i_useSecondarySeepromConfig The model contains a single
    /// SEEPROM memory, however the hardware always includes a primary and
    /// secondary SEEPROM. This option to the constructor selects which
    /// SEEPROM addressing attributes (device Id, port) to use for the SEEPROM
    /// memory model. The default is to use the primary attributes.
    PoreVe(const PoreIbufId i_id, 
           const fapi::Target i_masterTarget,
           const bool i_useSecondarySeepromConfig = false);

    virtual ~PoreVe();

    /// Create a PoreVe (subclass) by static link-time selection
    ///
    /// \param[in] i_id The PORE IBUF_ID (engine type) of the Pore component.
    /// This will be PORE_SBE for host boot/SBE applications, and PORE_SLW for
    /// testing Sleep/Winkle applications. 
    ///
    /// \param[in] i_masterTarget  The fapi::Target associated with the master
    /// chip in an HBI master/slave configuration.  This target is also
    /// installed into \a iv_slaveTarget by the constructor.
    ///
    /// \param[in] i_arg A private argument for the created model.  In the
    /// case of a debugged model this is a character string naming a script to
    /// be run when the debugger starts. The PoreVe ignores this argument.
    ///
    /// The static create() method is provided to enable link-time selection
    /// of a subclass of PoreVe, in particular to allow a common FAPI PoreVe
    /// procedure to create either a 'normal' or 'debug' version of PoreVe.
    static PoreVe* create(const PoreIbufId i_id, 
                          const fapi::Target i_masterTarget,
                          const void* i_arg);

    //////////////////// Public Implementation ////////////////////////////

    /// The OTPROM controller model
    PibMemory iv_otprom;

    /// The OTPROM memory model
    Memory iv_otpromMemory;

    /// The PIBMEM controller model
    Pibmem iv_pibmem;

    /// The PIBMEM memory model
    Memory iv_pibmemMemory;

    /// The SEEPROM controller model
    FastI2cController iv_seepromController;

    /// The SEEPROM memory model
    I2cMemory iv_seepromMemory;

    /// The OCI bus model
    Bus iv_oci;

    /// The Mainstore memory controller model
    OciMemory iv_main;

    /// The Mainstore memory model
    Memory iv_mainMemory;

    /// The SRAM controller model
    OciMemory iv_sram;

    /// The SRAM memory model
    Memory iv_sramMemory;

#ifdef PM_HACKS
    OciSlaveWritable iv_pmc;
#endif  // PM_HACKS

    /// The Pib2Cfam PIB Slave
    Pib2Cfam iv_pib2Cfam;

    /// The sbeVital PIB Slave
    SbeVital iv_sbeVital;

#ifdef VBU_HACKS
    /// The Broadside Scan components for each EX
  //    Bsscan iv_bsscan_ex00;
    Bsscan iv_bsscan_ex01;
    Bsscan iv_bsscan_ex02;
    Bsscan iv_bsscan_ex03;
    Bsscan iv_bsscan_ex04;
    Bsscan iv_bsscan_ex05;
    Bsscan iv_bsscan_ex06;
  //    Bsscan iv_bsscan_ex07;
  //    Bsscan iv_bsscan_ex08;
    Bsscan iv_bsscan_ex09;
    Bsscan iv_bsscan_ex10;
    Bsscan iv_bsscan_ex11;
    Bsscan iv_bsscan_ex12;
    Bsscan iv_bsscan_ex13;
    Bsscan iv_bsscan_ex14;
  //    Bsscan iv_bsscan_ex15;
#endif
    ///////////////////////////// Safety //////////////////////////////////

private:
    PoreVe(const PoreVe& i_rhs);
    PoreVe& operator=(const PoreVe& i_rhs);
};

#endif  // __VSBE_POREVE_H
