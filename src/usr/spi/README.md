# Serial Peripheral Interface (SPI) Driver

SPI provides full-duplex synchronous serial communication between single master
and slave devices. For P10, there are 5 SPI engines.

Engines 0 and 1 are for the boot primary and backup seeproms.
Engines 2 and 3 are for the MVPD/Measurement primary and backups.
Engine 4 is for the TPM.

There are two ways to access Engines 0-3, CFAM and PIB. These paths are
controlled via a mux that is set by a root control register.

Engines 4 and 5 are only accessible through PIB and do not have a mux.

Each engine will have a lock to prevent issues during read and write and to
avoid potential switching of the muxes that are connected to Engines 0-3.

# SPI Device Driver Assumptions

## No ECC support

Despite hardware support for ECC address space correction for reads, this
feature will not be used for consistency between read and write. Therefore, if
a device supports ECC then its corresponding device driver must implement
support for that feature.

## Size and alignment adjustment

SPI transactions require a minimum of 8 bytes and must be aligned by 8 bytes
during writes. The hardware procedures that this driver calls will verify these
conditions and process requests larger than 8 bytes by breaking them up into a
series of 8 bytes. The SPI driver will handle this requirement transparently so
that the caller doesn't have to handle it.
