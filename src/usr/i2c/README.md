## P9 I2C attachments (External devieces and driving I2C master engines)

Each processor has a CFAM I2C master that connects to the FSP in additon to
a Quad I2C master chiptlet that houses 4 PIB I2CM devices. These I2C master
devices connect to the SBE , the VPD , the TPM/PCIE, and the DIMMs.

### I2C Masters in the P9 Proc Chiplet

CFAM I2CM_A = FSP

PIB I2CM_B  = SBE seeproms     = Engine0

PIB I2CM_C  = VPD/SBE seeproms = Engine1

PIB I2CM_D  = TPM/PCIE HotPlug = Engine2

PIB I2CM_E  = DIMMs            = Engine3


### I2C Master Connections


**CFAM I2CM_A** - connects to seeprom0(MVPD), seeprom1(SBE), seeprom2(MVPD),
seeprom3(SBE), CXPs (hostboot ignores), GPUs, DIMMs, and the DPSS/Spare

**PIB I2CM_B** - connects to seeprom1(SBE) and seeprom3(SBE)

**PIB I2CM_C** - connects to seeprom0(MVPD), seeprom1(SBE), seeprom2(MVPD),
seeprom3(SBE),CXPs (hostboot ignores), GPUs, and the DPSS/Spare

**PIB I2CM_D** - connects to TPM and PCIe HotPlugs

**PIB I2CM_E** - connects to DIMMs


**NOTE:** many of these devices have multiple masters, becausue of this masters
must handshake before communicating to make sure collisions do not occur.

