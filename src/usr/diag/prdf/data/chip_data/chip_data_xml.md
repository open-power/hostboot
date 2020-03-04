# Chip Data XML

The machine readable Chip Data XML files are used to generate the Chip Data
Binary files that are consumed directly by the Hardware Error Isolator (simply
referred to as 'the isolator'). Details of the isolator and the
[Chip Data Binary][] format and requirements can be found in the
[openbmc/openpower-libhei][] project.

[Chip Data Binary]: https://github.com/openbmc/openpower-libhei/blob/master/src/chip_data/CHIP_DATA.md
[openbmc/openpower-libhei]: https://github.com/openbmc/openpower-libhei

## 1) Chip Files - Root Element: `<chip>`

Each chip represented by the XML must have a separate file. These files describe
the supported model/EC levels and where to start isolation for each attention
type supported by the chip.

The filename must start with the prefix `chip_` and have the `.xml` extension.

### 1.1) Attribute `name` (required)

The name of the chip. Must be alphanumeric or underscores, no spaces or other
symbols allowed.

### 1.2) Attribute `model_ec` (required)

See the notice in the appendix regarding the `model_ec` attributes.

### 1.3) Element `<attn_tree>` (required 1 or more)

These indicate where to start isolation for a specific attention type.

#### 1.3.1) Attribute `attn_type` (required)

The attention type for this tree. See appendix for supported values.

#### 1.3.2) Attribute `root_node` (required)

The name of the node that will be the root of this isolation tree. This value
can be found in the `name` attribute of the `<attn_node>` root element.

#### 1.3.3) Attribute `node_inst` (required)

The logical instance of the root node. See the various `node_inst`
sub-attributes of the `<attn_node>` root element.

## 2) Isolation Node Files - Root Element: `<attn_node>`

The data described by the XML in these files represents attention isolation
trees. Each tree node will contain:

 * A list of registers related to this node (FIRs, masks, config regs, etc.).

 * A list of registers to store in logs for additional debug, if necessary.

 * A set of rules describing registers and bit operations required to determine
   if there are active attentions for supported attention types.

 * A bit definition indicating if an active attention has been found or if it
   originated from another node.

**Important Note:**
A node typically represents a Fault Isolation Register (FIR).  However, other
hardware registers, like `c_err_rpt` registers, or a combination of registers
could be used as well.

For readability and maintainability, the data for each node will be stored in
separate XML files.

The filename must start with the prefix `node_` and have the `.xml` extension.

### 2.1) Attribute `name` (required)

The name of the node. Must be alphanumeric or underscores, no spaces or other
symbols allowed. This name will be displayed in log files.

Note that this typically matches the name of the register(s) targeted for
isolation, but it is not required.

### 2.2) Attribute `model_ec` (required)

See the notice in the appendix regarding the `model_ec` attributes.

### 2.3) Attribute `reg_type` (required)

All registers used by this node must be of the same type. This dispels any
ambiguity that may occur with the bitwise operations defined by the `<rule>`
elements. It also defines the maximum number of `<bit>` elements that can be
defined for this node and the order of the bit `pos` attribute (left to right
vs. right to left). Supported types:

 * POWER Systems SCOM register
   * Attribute value:   SCOM
   * Address length:    4 bytes
   * Register length:   8 bytes
   * Bit order:         ascending (0-63, left to right)

 * POWER Systems Indirect SCOM register
   * Attribute value:   IDSCOM
   * Address length:    8 bytes
   * Register length:   8 bytes
   * Bit order:         ascending (0-63, left to right)

### 2.4) Element `<register>` (required 1 or more)

These provide a list of all registers required for isolation of this node. At
a minimum, a `<register>` element must exist for each register referenced by
the `<rule>` elements.

#### 2.4.1) Attribute `name` (required)

The name of the register. Must be alphanumeric or underscores, no spaces or
other symbols allowed.

#### 2.4.2) Attribute `access` (optional)

The hardware operation accessibility. Supported values:

| Value  | Description                                                    |
|--------|----------------------------------------------------------------|
| RO     | read-only access                                               |
| WO     | write-only access                                              |
| RW     | read and write access (default when 'access' is not specified) |

#### 2.4.3) Element `<instance>` (required)

It is possible that a register could have multiple instances within a
chip. For example, the same register could exist for each core on a processor
chip. Generally, the isolation rules and bit definition for registers like these
are the same for each instance. The only difference would be the register
addresses associated with each instance. So, instead of repeating the same
information in multiple files, there will be an `<instance>` element for each
unique instance of the register.

##### 2.4.3.1) Attribute `reg_inst` (required)

A unique integer value for the logical instance of this register. Note that the
default value of 0 should be used for any single instance registers.

##### 2.4.3.2) Attribute `addr` (required)

The register address for this instance. The length of this hexadecimal integer
is dependent on the `reg_type` attribute defined in the root `<attn_node>`
element.

### 2.5) Element `<capture_group>` (optional)

These provide a list of all registers that should be captured and stored in log
files for additional debug, if necessary.

This may seem redundant because in most cases the `<register>` elements will
align exactly with this list. However, consider a special case:

 * There is a set of FIR bits that represent a unit within a chip.
 * That same set exists for each instance of that chip unit.
 * To save space in the hardware, a particular FIR may contain a set for more
   than one chip unit.
 * For example, sixteen bits per set and four sets per FIR could represent
   eight units in just two FIRs).

Therefore, if we set up the bit definition and rules for a node to represent
the hardware units instead of the FIRs, the register instances will not match
the node instances.

#### 2.5.1) Attribute `node_inst` (required)

The logical instance of the node targeted by this capture group. A list and/or
range value (see appendix) may be used to indicate this capture group applies to
more than one node.

#### 2.5.2) Element `<capture_register>` (required 1 or more)

A reference to a register that should be captured.

##### 2.5.2.1) Attribute `reg_name` (required)

See the `name` attribute of `<register>`.

##### 2.5.2.2) Attribute `reg_inst` (required)

See the `reg_inst` attribute for each `<instance>` of `<register>`.

**Important Note:**
This value is interpreted as an array, where the index is the instance value of
the `node_inst` attribute of the `<capture_group>` element. Therefore, this
requires the number of instances represented by this attribute to equal the
number of instances represented by the the `node_inst` attribute of the
`<capture_group>` element.

### 2.6) Element `<rule>` (required 1 or more)

A rule helps specify if an attention is being raised from a register and what
type of attention is being raised. A rule is constructed by a series of
expressions (see `<expr>` below). The result of the expressions will indicate
all active attentions for a rule.

#### 2.6.1) Attribute `attn_type` (required)

The attention type for this rule. See appendix for supported values.

#### 2.6.2) Attribute `node_inst` (required)

The logical instance of the node targeted by this rule. A list and/or range
value (see appendix) may be used to indicate this rule applies to more than one
node.

#### 2.6.3) Element `<expr>` (required 1 or more)

Expressions are used to characterize bitwise operations carried out against
registers and/or integer constants. For example, `~some_register & 0xffff` will
take the contents of `some_register` apply a bitwise NOT operation and then AND
that value with the integer `0xffff`. This example will generate XML as follows:

    <expr type="and">
        <expr type="not">
            <expr type="register" value="some_register" />
        </expr>
        <expr type="integer" value="0xffff" />
    </expr>

For simplicity, the register and integer sizes will be defined by the `reg_type`
attribute of the root `<attn_node>` element. This ensures all values are the
same, eliminating the ambiguity caused by variable register/integer sizes.

It is also important to note that any values shifted beyond the defined register
length will be lost. For example, given the register length of 2 bytes, the
expression `(0xffff << 8) >> 8` will resolve to `0x00ff`.

##### 2.6.3.1) Attributes `type` (required) and `value1`/`value2` (conditional)

Each `<expr>` will have an expression type. Supported types are:

| `type` | Description        | Sub-elements | `value1`      | `value2`     |
|--------|--------------------|:------------:|---------------|--------------|
| reg    | register reference |              | reg name      | reg instance |
| int    | integer constant   |              | integer value |              |
| and    | bitwise AND        | 2 or more    |               |              |
| or     | bitwise OR         | 2 or more    |               |              |
| not    | bitwise NOT        | 1            |               |              |
| lshift | left shift         | 1            | shift value   |              |
| rshift | right shift        | 1            | shift value   |              |

Table notes:
 * Some types require the sub-elements or `value1`/`value2` attributes, but they
   are only required if explicitly stated in the table above.
 * Sub-elements are expressions and will be resolved before handling the
   containing expression.

Expression type notes:
 * A register reference is a special expression that indicates the contents of
   the target register should be used for this expression. Generally, this means
   reading the register value from hardware. The `value1` attribute is required
   for this expression type and will indicate the name of the target register.
   The `value2` attribute is optional and indicates the target register
   instance. If omitted, the register instance will match the node instance(s)
   represented by this rule.
 * An integer constant is simply a right-justified, unsigned integer. The
   `value1` attribute for this expression type will contain the integer value.
   The length of the number is defined by the `reg_type` attribute of the root
   `<attn_node>` element.

### 2.7) Element `<bit>` (required 1 or more)

These provide metadata for each bit in this node. There should be a `<bit>`
element for each bit that could generate an attention.

#### 2.7.1) Attribute `pos` (required)

A numeric value representing the bit position within the node. The value cannot
exceed the bit length defined by the `reg_type` attribute of the root
`<attn_node>` element. A list and/or range value (see appendix) may be used to
indicate this bit definition applies to more than one bit.

#### 2.7.2) Attribute `child_node` (optional)

If this attribute exists, it means the event that raised the attention in this
bit originated from another node. The value of this attribute is the name of
the child node, which can be found in the `name` attribute of the `<attn_node>`
root element.

#### 2.7.3) Attribute `node_inst` (optional)

The target instance of the child node. This attribute should only exist when
`child_node` is specified. Also, if `child_node` is specified and this attribute
is omitted, the default value of 0 is used.

**Important Note:**
This value is actually interpreted as an array where the index is the instance
value of the current node. Therefore, this requires the number of instances
represented by this attribute to equal the number of instances represented by
the current node.

A list and/or range value (see appendix) may be used to represent the attribute
value. For example, say we have a node with four possible instances and a bit
defined as either of the following:

    <bit pos="0" child_node="SOME_FIR" node_inst="4,5,6,7" ...
    <bit pos="0" child_node="SOME_FIR" node_inst="4:7" ...
    <bit pos="0" child_node="SOME_FIR" node_inst="4:5,6:7" ...

All of which are equivalent once the lists/ranges are expanded. Then, if the
input instance during isolation of this node is 1, the instance used for
`SOME_FIR` will be 5.

#### 2.7.4) Data for `<bit>` (required)

A human readable description of this bit. This description will be printed out
in logs for human consumption. It is highly recommended to keep this description
short and concise (~50 characters) because longer descriptions will likely be
truncated depending on the application.

### 2.8) Special Element `<local_fir>` (optional)

Some chips have a lot of local FIR registers, especially POWER processor chips,
and nearly all of these FIRs follow the same pattern where:
 * The MASK, ACTION, WOF, etc. register are on the same address offset from the
   FIR address.
 * Attention rules are defined by the associated MASK and ACTION registers.

Therefore, this special `<local_fir>` element is simply provided as shorthand
for these common patterns. Under the covers it will generate the required
`<register>`, `<capture_group>`, and `<rule>` elements for the FIR.

#### 2.8.1) Attribute `name` (required)

The FIR name. Defined exactly as the `name` attribute of `<register>`.

#### 2.8.2) Attribute `config` (required)

Not all FIRs will have a WOF or ACT2 (which is new to P10). If either, or both,
of these registers exist, use the following values:

| Value | Description                         |
|-------|-------------------------------------|
|       | neither WOF nor ACT2 registers      |
| W     | include WOF register                |
| 2     | include ACT2 register               |
| W2    | include both WOF and ACT2 registers |

#### 2.8.3) Element `<instance>` (required 1 or more)

The FIR instance. Defined exactly as the `<instance>` attribute of `<register>`
where the `addr` attribute is the FIR address.

Under the covers, the following registers will be generated (see the `config`
attribute for details on the WOF and ACT2 registers):

| name            | addr   | access |
|-----------------|--------|--------|
| `name`          | addr+0 | RW     |
| `name_MASK`     | addr+3 | RW     |
| `name_ACT0`     | addr+6 | RW     |
| `name_ACT1`     | addr+7 | RW     |
| `name_WOF`      | addr+8 | RW     |
| `name_ACT2`     | addr+9 | RW     |

#### 2.8.4) Element `<action>` (required 1 or more)

The action registers associated with the FIR are used to configure supported
attention types.

##### 2.8.4.1) Attribute `attn_type` (required)

The attention type. Defined exactly as the `attn_type` attribute of `<rule>`.

##### 2.8.4.2) Attribute `config` (required)

Under the covers, the following rules will be generated based on the value of
this attribute:

| Value | Rule                                |
|-------|-------------------------------------|
| 00    | FIR & ~MASK & ~ACT0 & ~ACT1         |
| 01    | FIR & ~MASK & ~ACT0 &  ACT1         |
| 10    | FIR & ~MASK &  ACT0 & ~ACT1         |
| 11    | FIR & ~MASK &  ACT0 &  ACT1         |
| 000   | FIR & ~MASK & ~ACT0 & ~ACT1 & ~ACT2 |
| 001   | FIR & ~MASK & ~ACT0 & ~ACT1 &  ACT2 |
| 010   | FIR & ~MASK & ~ACT0 &  ACT1 & ~ACT2 |
| 011   | FIR & ~MASK & ~ACT0 &  ACT1 &  ACT2 |
| 100   | FIR & ~MASK &  ACT0 & ~ACT1 & ~ACT2 |
| 101   | FIR & ~MASK &  ACT0 & ~ACT1 &  ACT2 |
| 110   | FIR & ~MASK &  ACT0 &  ACT1 & ~ACT2 |
| 111   | FIR & ~MASK &  ACT0 &  ACT1 &  ACT2 |

## 3) Appendix

### 3.1) Number Format

All numbers in this XML are unsigned integers. A hexadecimal value must start
with '0x'. Otherwise, the value is assumed to be decimal.

### 3.2) Number Lists and Ranges

 * Lists are expressed by a comma separated list (e.g. "0,2,4,6,8").
 * Ranges represent consecutive ascending or descending numbers (including both
   endpoints) and are expressed using a colon (e.g. "8:15" or "15:8").
 * Lists and ranges can be combined. For example, a value of "0,2:4,6" expands
   to 0, 2, 3, 4, and 6.

### 3.3) Notice Regarding `model_ec` Attributes

This attribute allows us to reuse the same `<chip>` or `<attn_node>` definition
for multiple chip models and/or EC levels. These attributes are intentionally
limited to the root `<chip>` and `<attn_node>` elements for simplicity,
maintainability, and readability. Separate files will be required for each
definition if any part of the `<chip>` or `<attn_node>` definition differs
between chip models and/or EC levels.

The attribute is a comma separated list. The currently supported list values
are:

| Value         | Description          |
|---------------|----------------------|
| `EXPLORER_10` | Explorer chip EC 1.0 |
| `P10_10`      | P10 chip EC 1.0      |

### 3.4) Supported Attention Types

| Value | Description                                                          |
|-------|----------------------------------------------------------------------|
| CS    | System checkstop hardware attention.                                 |
| UCS   | Unit checkstop hardware attention.                                   |
| RE    | Recoverable hardware attention.                                      |
| SPA   | SW or HW event requiring action by the service processor firmware.   |
| HA    | SW or HW event requiring action by the host firmware.                |

