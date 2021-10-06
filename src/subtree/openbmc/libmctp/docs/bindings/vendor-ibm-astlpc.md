# Management Component Transport Protocol (MCTP) LPC Transport Binding Specification for ASPEED BMC Systems

## Scope

This design provides an efficient method to transfer MCTP packets between the
host and BMC over the LPC bus on ASPEED BMC platforms.

## References

The following referenced documents are indispensable for the application of
this document.

1. DMTF DSP0236, Management Component Transport Protocol (MCTP) Base
Specification 1.0,  
http://www.dmtf.org/standards/published_documents/DSP0236_1.0.pdf

2. Intel (R) Low Pin Count (LPC) Interface Specification 1.1,  
https://www.intel.com/content/dam/www/program/design/us/en/documents/low-pin-count-interface-specification.pdf

3. IPMI Consortium, Intelligent Platform Management Interface Specification,
v1.5 Revision 1.1 February 20, 2002,  
http://download.intel.com/design/servers/ipmi/IPMIv1_5rev1_1.pdf

## Definitions

**BTU: Baseline Transmission Unit**

Defined by the MCTP base specification as the smallest maximum packet size all
MCTP-compliant endpoints must accept.

**IBF: Input Buffer Full**

A hardware-defined flag bit in a KCS device's Status Register (STR). The IBF
flag indicates that a value has been written by the host to the corresponding
Input Data Register (IDR).

**IDR: Input Data Register**

One of the three register interfaces exposed by a KCS device. The IDR is a one
byte buffer which is written by the host and read by the BMC.

**KCS: Keyboard-Controller-Style**

A set of bit definitions and operation of the registers typically used in
keyboard microcontrollers and embedded controllers. The term "Keyboard
Controller Style" reflects that the register definition was originally used as
the legacy "8742" keyboard controller interface in PC architecture computer
systems.  This interface is available built-in to several commercially
available microcontrollers. Data is transferred across the KCS interface using
a per-byte handshake.

**LPC Bus: Low Pin Count Bus**

A bus specification that implements ISA bus in a reduced physical form while
extending ISA's capabilities.

**LPC FW: LPC Firmware Cycles**

LPC firmware cycles allow separate boot BIOS firmware memory cycles and
application memory cycles with respect to the LPC bus. The ASPEED BMCs allow
remapping of the LPC firmware cycles onto arbitrary regions of the BMC's
physical address space, including RAM.

**MTU: Maximum Transmission Unit**

The largest payload the link will accept for a packet. The Maximum Transmission
Unit represents a value that is at least as large as the BTU. Negotiation of
MTU values larger than the BTU may improve throughput for data-intensive
transfers.

**OBF: Output Buffer Full**

A hardware-defined flag bit in a KCS device's Status Register (STR). The OBF
flag indicates that a value has been written by the BMC to the corresponding
Output Data Register (ODR).

**ODR: Output Data Register**

One of the three register interfaces exposed by a KCS device. The ODR is a
one byte buffer which is written by the BMC and read by the host.

**STR: Status Register**

One of the three register interfaces exposed by a KCS device. STR is a
BMC-controlled, eight-bit register exposed to both the BMC and the host for
indication of IBF and OBF events on the input (IDR) and output (ODR) buffers.
Bits that are not defined by hardware can be software-controlled in a manner
defined by a platform-specific ABI.

## Conventions

Where unspecified, state, command and sequence descriptions apply to all
versions of the protocol unless marked otherwise.

## MCTP over LPC Transport

### Concepts

The basic components used for the transfer are:

* An interrupt mechanism using the IPMI KCS interface
* A window of the LPC FW address space, where reads and writes are forwarded to
  BMC memory, using the LPC2AHB hardware

In order to transfer a packet, either side of the channel (BMC or host) will:

1. Write the packet to the LPC FW window
   * The BMC will perform writes by writing to the memory backing the LPC
     window
   * The host will perform writes by writing to the LPC bus, at predefined
     addresses
2. Trigger an interrupt on the remote side, by writing to the KCS data buffer

On this indication, the remote side will:

1. Read from the KCS status register, which shows that the single-byte KCS data
   buffer is full
2. Read the provided command from the KCS data buffer, acknowledging the
   interrupt
3. Read the MCTP packet from the LPC FW window

### Scope

The document limits itself to describing the operation of the binding protocol.
The following issues of protocol ABI are considered out of scope:

1. The LPC IO address and Serial IRQ parameters of the KCS device
2. The concrete location of the control region in the LPC FW address space

### KCS Interface

The KCS hardware on the ASPEED BMCs is used as a method of indicating, to the
remote side, that a packet is ready to be transferred through the LPC FW
mapping.

The KCS hardware consists of two single-byte buffers: the Output Data Register
(ODR) and the Input Data Register (IDR). The ODR is written by the BMC and read
by the host. The IDR is the obverse.

The KCS unit also contains a status register (STR), allowing both host and BMC
to determine if there is data in the ODR or IDR. These are single-bit flags,
designated Input/Output Buffer Full (IBF/OBF), and are automatically set by
hardware when data has been written to the corresponding ODR/IDR buffer (and
cleared when data has been read).

While the IBF and OBF flags are managed in hardware, the remaining
software-defined bits in the status register are used to carry other required
protocol state. A problematic feature of the KCS status register is described
in the IPMI specification, which states that an interrupt may be triggered on
writes to the KCS status register but hardware implementations are not required
to do so. Comparatively, writes to the data registers must set the
corresponding buffer-full flag and invoke an interrupt.

To ensure interrupts are generated for status updates, we exploit the OBF
interrupt to signal a status update by writing a dummy command to ODR after
updating the status register, as outlined below.

### LPC FW Window

The window of BMC-memory-backed LPC FW address space has a predefined format,
consisting of:

* A control descriptor, describing static data about the rest of the window
* A receive area for BMC-to-host packets
* A transmit area, for host-to-BMC packets

The control descriptor contains a version, and offset and size data for the
transmit and receive areas. These offsets are relative to the start of the LPC
FW window.

Full definition of the control area is defined below, and it will be the base
for all future versions.

```c
struct mctp_lpcmap_hdr {
   uint32_t magic;

   uint16_t bmc_ver_min;
   uint16_t bmc_ver_cur;
   uint16_t host_ver_min;
   uint16_t host_ver_cur;
   uint16_t negotiated_ver;
   uint16_t pad0;

   uint32_t rx_offset;
   uint32_t rx_size;
   uint32_t tx_offset;
   uint32_t tx_size;
} __attribute__((packed));
```

The magic value marking the beginning of the control area is the ASCII encoding
of "MCTP":

```c
#define LPC_MAGIC 0x4d435450
```

All medium-specific metadata is in big-endian format. This includes:

1. Control area data
2. Medium-specific packet header fields
3. Medium-specific packet trailer fields

MCTP packet data is transferred exactly as is presented, and no data escaping is
performed.

In all versions of the protocol, the transmit and receive areas contain a
medium-specific header comprising a 32-bit payload length field, followed
immediately by the MCTP packet data to be transferred. The full MCTP packet,
including MCTP header, is considered to be the payload for the purpose of the
header's length field.

```c
struct mctp_lpcbuf_hdr {
   uint32_t length;
} __attribute__((packed));
```

A medium-specific packet trailer must immediately follow the payload. The length
of the trailer is not accounted for in the length field of the medium-specific
packet header: The length of the trailer is implied by the negotiated protocol
version.

For protocol versions 1 and 2, the medium-specific trailer length is zero.

For protocol version 3, the medium-specific trailer comprises a CRC-32 checksum
of the payload.

```c
struct mctp_lpcbuf_tlr {
   uint32_t crc32;
} __attribute__((packed));
```

Where the CRC-32 implementation is defined by the following characteristics (or
equivalent):

1. The polynomial `x^32 + x^26 + x^23 + x^22 + x^16 + x^12 + x^11 + x^10 + x^8 + x^7 + x^5 + x^4 + x^2 + x + 1`
2. Initialising the remainder state to `2^32 - 1`
3. Incrementally shifting and `XOR`ing data bytes through the reversed polynomial representation `0xEDB88320`
4. `XOR`ing the calculated remainder with `2^32 - 1`

For all defined versions, only a single MCTP packet is present in the Rx and Tx
areas. This may change for future versions of the protocol.

#### Negotiation of the Maximum Transmission Unit

Version 1 of the protocol offers no mechanism for negotiation of the maximum
transmission unit. The Rx and Tx buffers must be sized to accommodate packets
up to the Baseline Transmission Unit, and the implementation assumes that the
MTU is set to the BTU regardless of the values of `rx_size` and `tx_size`.

Version 2 of the protocol exploits the `rx_size` and `tx_size` fields in the
control region to negotiate the link MTU. Note that at the time that the MTU is
under negotiation the protocol version has not been finalised, so the process
is necessarily backwards-compatible.

The relevant property that each endpoint must control is the MTU of packets it
will receive, as this governs how the remote endpoint's packetisation impacts
memory pressure at the local endpoint. As such while the BMC MUST populate
`rx_size` for backwards compatibility with version 1, the host MAY write
`rx_size` without regard for its current value if the host supports version 2.
The BMC controls the value of `tx_size`, and MAY choose to adjust it in
response to the host's proposed `rx_size` value. As such, when `Channel Active`
is set by the BMC, the host MUST read both `rx_size` and `tx_size` in response
to ensure both the BMC and the host have a consistent understanding of the MTU
in each direction. It is convention for `rx_size` and `tx_size` to be set to
the same value by the BMC as part of finalising the channel, though it is not
invalid to have asymmetric MTUs.

For all protocol versions, the following properties must be upheld for the Rx
and Tx buffers to be considered valid:

* Intersect neither eachother nor the control region
* Not extend beyond the window allocated to MCTP in the LPC FW address space
* Must accommodate at least BTU-sized payloads

The BMC MAY choose to fail channel initialisation if these properties are
violated in the negotiation process.

### KCS Status and Control Sequences

The KCS status flags and command set govern the state of the protocol, defining
the ability to send and receive packets on the LPC bus.

#### KCS Status Register Layout

| Bit      | Managed By | Description |
|----------|------------|-------------|
|  7 (MSB) |  Software  | BMC Active  |
|  6       |  Software  | Channel active, version negotiated |
|  5       |  Software  | Unused      |
|  4       |  Software  | Unused      |
|  3       |  Hardware  | Command / Data |
|  2       |  Software  | Unused      |
|  1       |  Hardware  | Input Buffer Full |
|  0 (LSB) |  Hardware  | Output Buffer Full |

#### KCS Data Register Commands

| Command | Description |
|---------|-------------|
|  0x00   | Initialise  |
|  0x01   | Tx Begin    |
|  0x02   | Rx Complete |
|  0xff   | Dummy Value |

#### Host Command to BMC Sequence

The host sends commands to the BMC to signal channel initialisation, begin
transmission of a packet, or to complete reception of a packet.

| Step | Description                                             |
|------|---------------------------------------------------------|
|  1   | The host writes a command value to IDR                  |
|  2   | The hardware sets IBF, which triggers a BMC interrupt   |
|  3   | The BMC reads the status register for IBF               |
|  4   | If IBF is set, the BMC reads the host command from IDR  |
|  5   | The interrupt is acknowledged by the data register read |

#### BMC Command to Host Sequence

The BMC sends commands to the host to begin transmission of a packet or to
complete reception of a packet.

| Step | Description                                             |
|------|---------------------------------------------------------|
|  1   | The BMC writes a command value to ODR                   |
|  2   | The hardware sets OBF, which triggers a host interrupt  |
|  3   | The host reads the status register for OBF              |
|  4   | If OBF is set, the host reads the BMC command from ODR  |
|  5   | The interrupt is acknowledged by the data register read |

#### BMC Status Update Sequence

The BMC sends status updates to the host to signal loss of function, loss of
channel state, or the presence of a command in the KCS data register.

| Step | Description                                                    |
|------|----------------------------------------------------------------|
|  1   | The BMC writes the status value to the status register         |
|  2   | The BMC writes the dummy command to ODR                        |
|  3   | The hardware sets OBF, which triggers a host interrupt         |
|  4   | If OBF is set, the host reads the BMC command from ODR         |
|  5   | The interrupt is acknowledged by the data register read        |
|  6   | The host observes the command is the dummy command             |
|  7   | The host reads the status register to capture the state change |

#### LPC Window Ownership and Synchronisation

Because the LPC FW window is shared between the host and the BMC we need
strict rules on which entity is allowed to access it at specific times.

Firstly, we have rules for modification:

* The control data is only written during initialisation. The control area
  is never modified once the channel is active.
* Only the BMC may write to the Rx buffer described in the control area
* Only the host may write to the Tx buffer described in the control area

During packet transmission, the follow sequence occurs:

1. The Tx side writes the packet to its Tx buffer
2. The Tx side sends a `Tx Begin` message, indicating that the buffer ownership
   is transferred
3. The Rx side now owns the buffer, and reads the message from its Rx area
4. The Rx side sends a `Rx Complete` once done, indicating that the buffer
   ownership is transferred back to the Tx side.

### LPC Binding Operation

The binding operation is not symmetric as the BMC is the only side that can
drive the status register. Each side's initialisation sequence is outlined
below.

The sequences below contain steps where the BMC updates the channel status and
where commands are sent between the BMC and the host. The act of updating
status or sending a command invokes the behaviour outlined in [KCS
Control](#kcs-control).

The packet transmission sequences assume that `BMC Active` and `Channel Active`
are set.

#### BMC Initialisation Sequence

| Step | Description                              |
|------|------------------------------------------|
|  1   | The BMC initialises the control area: magic value, BMC versions and buffer parameters |
|  2   | The BMC sets the status to `BMC Active`  |

#### Host Initialisation Sequence

| Step | v1 | v2 | v3 | Description                                    |
|------|----|----|----|------------------------------------------------|
|  1   | ✓  | ✓  | ✓  | The host waits for the `BMC Active` state      |
|  2   | ✓  | ✓  | ✓  | The host populates the its version fields      |
|  3   |    | ✓  | ✓  | The host derives and writes to `rx_size` the packet size associated with its desired MTU |
|  4   | ✓  | ✓  | ✓  | The host sends the `Initialise` command        |
|  5   | ✓  | ✓  | ✓  | The BMC observes the `Initialise` command      |
|  6   | ✓  | ✓  | ✓  | The BMC calculates and writes `negotiated_ver` |
|  7   |    | ✓  | ✓  | The BMC calculates the MTUs and updates neither, one or both of `rx_size` and `tx_size` |
|  8   | ✓  | ✓  | ✓  | The BMC sets the status to `Channel Active`    |
|  9   | ✓  | ✓  | ✓  | The host observes that `Channel Active` is set |
|  10  | ✓  | ✓  | ✓  | The host reads the negotiated version          |
|  11  |    | ✓  | ✓  | The host reads both `rx_size` and `tx_size` to derive the negotiated MTUs |

#### Host Packet Transmission Sequence

| Step | v1 | v2 | v3 | Description                                                  |
|------|----|----|----|--------------------------------------------------------------|
|  1   |    |    | ✓  | The host calculates the CRC-32 over the packet data          |
|  2   | ✓  | ✓  | ✓  | The host waits on any previous `Rx Complete` message         |
|  3   | ✓  | ✓  | ✓  | The host writes the packet data and medium-specific metadata to its Tx area (BMC Rx area) |
|  4   | ✓  | ✓  | ✓  | The host sends the `Tx Begin` command, transferring ownership of its Tx buffer to the BMC |
|  5   | ✓  | ✓  | ✓  | The BMC observes the `Tx Begin` command                      |
|  6   | ✓  | ✓  | ✓  | The BMC reads the packet data and medium-specific metadata from the its Rx area (host Tx area) |
|  7   | ✓  | ✓  | ✓  | The BMC sends the `Rx Complete` command, transferring ownership of its Rx buffer to the host |
|  8   | ✓  | ✓  | ✓  | The host observes the `Rx Complete` command                  |
|  9   |    |    | ✓  | The BMC validates the provided CRC-32 over the packet data   |

#### BMC Packet Transmission Sequence

| Step | v1 | v2 | v3 | Description                                                   |
|------|----|----|----|---------------------------------------------------------------|
|  1   |    |    | ✓  | The BMC calculates the CRC-32 over the packet data            |
|  2   | ✓  | ✓  | ✓  | The BMC waits on any previous `Rx Complete` message           |
|  3   | ✓  | ✓  | ✓  | The BMC writes the packet data and medium-specific metadata to its Tx area (host Rx area) |
|  4   | ✓  | ✓  | ✓  | The BMC sends the `Tx Begin` command, transferring ownership of its Tx buffer to the host |
|  5   | ✓  | ✓  | ✓  | The host observes the `Tx Begin` command                      |
|  6   | ✓  | ✓  | ✓  | The host reads the packet data and medium-specific metadata from the host Rx area (BMC Tx area) |
|  7   | ✓  | ✓  | ✓  | The host sends the `Rx Complete` command, transferring ownership of its Rx buffer to the BMC |
|  8   | ✓  | ✓  | ✓  | The BMC observes the `Rx Complete` command                    |
|  9   |    |    | ✓  | The host validates the provided CRC-32 over the packet data   |

## Implementation Notes

On the BMC the initial prototype implementation makes use of the following
components:

* An LPC KCS device exposed by a [binding-specific kernel driver][mctp-driver]
* The reserved memory mapped by the LPC2AHB bridge via the [aspeed-lpc-ctrl
  driver][aspeed-lpc-ctrl]
* The astlpc binding found in [libmctp][libmctp]

[mctp-driver]: https://github.com/openbmc/linux/commit/9a3b539a175cf4fe1f8fc2997e8a91abec25c37f
[aspeed-lpc-ctrl]: https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/tree/drivers/soc/aspeed/aspeed-lpc-ctrl.c?h=v5.7
[libmctp]: https://github.com/openbmc/libmctp

From the host side, the LPC Firmware and KCS IO cycles are driven by
free-standing firmware. Some firmwares exploit [libmctp][libmctp] by
implementing the driver hooks for direct access to the LPC devices.

## Alternatives Considered

### The KCS MCTP Binding (DSP0254)

The KCS hardware (used as the full transfer channel) can be used to transfer
arbitrarily-sized MCTP messages. However, there are much larger overheads in
synchronisation between host and BMC for every byte transferred.

### The MCTP Serial Binding (DSP0253)

We could use the VUART hardware to transfer the MCTP packets according to the
existing MCTP Serial Binding. However, the VUART device is already used for
console data. Multiplexing both MCTP and console would be an alternative, but
the complexity introduced would make low-level debugging both more difficult
and less reliable.

### The BT interface

The BT interface allows for block-at-time transfers. However, the BT buffer
size is only 64 bytes on the AST2500 hardware, which does not allow us to
comply with the MCTP Base Specification (DSP0236) that requires a 64-byte
payload size as the minimum. The 64-byte BT buffer does not allow for MCTP and
transport headers.

Additionally, we would like to develop the MCTP channel alongside the existing
IPMI interfaces, to allow a gradual transition from IPMI to MCTP. As the BT
channel is already used on OpenPOWER systems for IPMI transfers, we would not
be able to support both in parallel.

### Using the AST2500 LPC Mailbox

This would require enabling the SuperIO interface, which allows the host to
access the entire BMC address space, and so introduces security
vulnerabilities.
