# P10 I2C attachments (External devices and driving I2C master engines)

Each processor has a CFAM I2C master that connects to the FSP/BMC in additon to
4 PIB I2C master devices. These I2C master devices connect to the DIMMs and 
various PCIE devices.

## I2C Masters in the P10 Processor

**CFAM I2CM_A**
- FSP/BMC

**PIB I2CM_B  = Engine0**
- Used by OCC (if required)

**PIB I2CM_C  = Engine1**
- Used by Hostboot/PHYP

**PIB I2CM_D  = Engine2**
- Used by PHYP
- Connects to PCIe HotPlugs, misc devices

**PIB I2CM_E  = Engine3**
- Used by Hostboot
- Connects to DDIMMs

### Note on register address mapping
The FSI and PIB engines use overlapping, but not identical register maps.  We hide the offset difference inside the i2cRegisterOp() function so most code doesn't need to care.  For example, the Status Register is offset 7 (I2C_REG_STATUS) in FSI-space but it is offset B in PIB-space.



## Multiple Masters
Many of these devices have multiple potential masters.  To avoid contention, it is assumed
that firmware subsystems will only use the engines assigned to them.

### Shared ports
Most i2c ports are dotted together (multiple wires are linked into one) inside the chip so that a 
single physical bus is shared external to the module.  There is no explicit enforcement, but 
high-level architecture has defined which engine should be used at any given time.  The general 
rules are:
- At standby, the BMC/FSP own all i2c devices.
- During IPL, Hostboot owns all devices off of Engine E.
- At runtime, PHYP owns all devices off of Engine C,D.

**Dotted lines**
- A0..A3 == E0..E3
- A4..A5 == B0..B1 == C0..C1
- A6..A17 == B2..B13 == C2..C13 == E4..E15


## I2C Reset
On initial boot we can't be sure that the i2c busses are in a useable state.  Before using them we will perform an extended reset sequence to get everything working.
- clear interrupt masks
- reset port busy
- send a stop
- reset the engine registers
- reset any sticky errors in the engine (and the fifo)
- reset port busy (again)
- send stop to all downstream devices
