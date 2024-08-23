
# Attribute XML Tags

This document lists the supported tags for the attribute xml files.

```xml
<attribute>
<id>ATTR_MRW_EXAMPLE</id>
    <targetType>TARGET_TYPE_TYPE1,TARGET_TYPE_TYPE2</targetType>
    <description>
       This is a useful description for an attribute that should come from
       the MRW. It is nice to describe different
       values and also the format of anything non-obvious.
    </description>
    <valueType>uint8</valueType>
    <enum>VAL0 = 0, VAL2 = 2, VAL3 = 0xFF</enum>
    <default>0</default>
    <platInit/>
</attribute>

<attribute>
<id>ATTR_HWP_EXAMPLE</id>
    <targetType>TARGET_TYPE_TYPE1,TARGET_TYPE_TYPE2</targetType>
    <description>
       This is a useful description for an attribute that is set by a
       HWP directly.
    </description>
    <valueType>uint32</valueType>
    <default>0</default>
    <writeable/>
</attribute>

<attribute>
<id>ATTR_PLAT_DEFAULT</id>
    <targetType>TARGET_TYPE_TYPE1,TARGET_TYPE_TYPE2</targetType>
    <description>
       This is a useful description for an attribute that is supplied by
       the platform but the value is controlled within the xml.
    </description>
    <valueType>uint16</valueType>
    <default>0x1234</default>
    <platInit/>
</attribute>

<attribute>
<id>ATTR_LAB_OVERRIDE</id>
    <targetType>TARGET_TYPE_TYPE1,TARGET_TYPE_TYPE2</targetType>
    <description>
       This is a useful description for an attribute that is supplied by
       the platform but it is only non-zero if we're doing a lab override.
    </description>
    <valueType>uint16</valueType>
    <default>0x1234</default>
    <platInit/>
    <overrideOnly/>
</attribute>

```

## Required Tags
All attributes must contain exactly one instance of each of these tags.

### attribute
Defines the scope of a single attribute.

`<attribute> ... </attribute>`

### description
Provides a useful description of both the purpose and the layout of the attribute.  Useful information might include bounds on the value, bit/byte layout, array indices, etc.

`<description>A useful description</description>`

### id
Defines the name of the attribute.
This must be universally unique.
It must start with "ATTR_".

`<id>ATTR_THENAME</id>`

### targetType
Specifies which targets include this attribute.
Can be a single or multiple values separated by commas.
Must match a valid type from hwpf/fapi2/include/target_types.H.

`<targetType>TARGET_TYPE_PROC</targetType>`
`<targetType>TARGET_TYPE_MEMBUF_CHIP, TARGET_TYPE_CORE</targetType>`

### valueType
Specifies the data type for this attribute, the options are:
- uint8
- uint16
- uint32
- uint64
- int8
- int16
- int32
- int64

`<valueType>uint8</valueType>`


## Optional Tags
These tags are optional for an attribute definition.
Note that an attribute must include at least one of: platInit, writeable.

### array
Specifies that this attribute is an array of 'valueType' numbers.  The array can be multi-dimensional.
Note : You should provide information on the meaning of the indices inside of the description.

`<array>8</array>`
`<array>2 2</array>`
`<array>2 4 6</array>`

### default
Specifies a default value for this attribute.  The default serves different purposes depending on what other tags are used.
* Without mrwHide / platInit=mrw : Provides an initial value that is shown to the MRW owner.
  * *IMPORTANT* - Once any value is saved into the MRW, the value from the ekb xml is no longer used.
* With mrwHide / platInit=usedefault : Determines the final value of this attribute, no MRW inclusion
* With overrideOnly : Determines the final value of this attribute, no MRW inclusion
* A lack of a default is equivalent to zero

`<default>42</default>`

### enum
Specifies a set of enumerations/constants that should be used to read/write the attribute.  You are not required to use the enum for access but it is strongly encouraged.  The enumeration name will appear in MRW menus.

The constant will have a value of : fapi2::ENUM_ATTR_<name of attribute>_<enum string>.

`<enum>FIRSTVALUE = 0, ANOTHERONE = 1, SKIPPEDSOME = 10</enum>`

Note that the list should not end with a trailing comma.

### initToZero
Indicates that this attribute has a default value of zero.
Note : This has a positive memory usage effect in firmware compared to using an explicit default value of zero.

`<initToZero/>`

### mrwHide
Indicates that this attribute should not be shown as a configurable parameter in the MRW.  Instead the attribute value is entirely controlled by the default value specified in the xml.
Note : must have a default tag.

`<mrwHide/>`

*Note : Will be deprecated once platforms support the various platInit tags*

### overrideOnly
Indicates that this attribute is only ever modified from its default value using lab override tools.  Using this tag will result in memory savings for the platform and also hide it from the MRW tooling.

`<overrideOnly/>`

*Note : Will be deprecated once platforms support the various platInit tags*

### platInit
Indicates that the platform is responsible for providing the value of this attribute.  This could be algorithmically, sourced from VPD, defined as part of the MRW, or blank space allocated for lab overrides.  The value of the tag gives a hint to platform code on how to treat the attribute.

Types
* customer :: Value is input by customer
* fw  :: Value is calculated by platform code
* mrw :: Value is provided by the MRW
* override :: Indicates that this attribute is only ever modified from its default value using lab override tools.  Using this tag will result in memory savings for the platform and also hide it from the MRW tooling.
* usedefault :: Value is provided as a default inside the attribute xml definition.  This value will be used by all systems.  The only time it would vary is with an explicit override in the lab.
* vpd :: Value comes directly from VPD (live lookup)

`<platInit>Type</platInit>`

`<platInit/>` is equivalent to `<platInit>mrw</platInit>` (*Note : Will be deprecated once platforms support the various platInit tags*)

### sbeAttrSync

Indicates that this attribute should be included in the attribute exchange between the CEC firmware and the SPPE.

- toSBE = value is pushed into the SPPE
- fromSBE = value is pulled from the SPPE
- chipTypes = specifies which kinds of SBE/SPPE should be involved
- targetTypes = filters which target types are involved, must be a subset of the targets defined for the attribute itself

```
<sbeAttrSync toSBE="1" fromSBE="0" chipTypes="ody">
  <targetTypes>TARGET_TYPE_MEM_PORT</targetTypes>
</sbeAttrSync>
```

### writeable
Indicates that the attribute can be written to a new value by a Hardware Procedure (HWP).  By default, attributes are read-only.
Note : It is unusual, though not unheard of, for an attribute to be both platInit and writeable.  If this is the case, the written value will persist across boots and code updates.

`<writeable/>`

### denyForSecurityUpdate
Indicates that the attribute cannot be updated from outside by attribute update chip-op.

`<denyForSecurityUpdate/>`


## Ignored/Deprecated Tags
The following tags may exist in legacy xml files but they are not consumed by any code.

- `odmChangeable`
- `odmVisible`
- `persistent`
- `persistRuntime`

## Persistency / Attribute Lifetime

### CEC Firmware (Hostboot, FSP, BMC).

- Non-writeable attributes will refresh to new values on every new IPL.  They will also be updated to new defaults as part of a concurrent code update.
- Non-platInit attributes will refresh to their defaults on every IPL.  The exception is a memory-preserving IPL where they will retain their value from the previous boot and runtime changes
- The only attributes that persist across IPLs are platInit + writeable.  Note that there is typically no easy way to reset these values once they are set so care should be taken, especially for any value involved in the initial boot of the system.

### Processor SBE

- All attributes refresh to their defaults on CBS start.  There is explicit logic to update some attributes based on customization but any additions / changes require software changes.
- Modified values will never migrate out to the rest of the firmware directly.
- There is no MRW support so all defaults will come from the ekb xmls.  The value in p10_sbe_attributes.xml takes precedence over the default in the attribute definition.
- Attributes must be added to p10_sbe_attributes.xml to be included in the SBE firmware image.

### Odyssey SPPE

- All attributes refresh to their defaults on CBS start.
- Modified values will be pulled from the SPPE into the CEC firmware during the IPL.
- There is no MRW support so all defaults will come from the ekb xmls.  The value in sbe_ody_attributes.xml takes precedence over the default in the attribute definition.
- Attributes must be added to sbe_ody_attributes.xml to be included in the SBE firmware image.
