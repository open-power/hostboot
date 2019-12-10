# What is trace-lite

Trace-lite is a feature in hostboot that allows enabling traces on
OpenPower systems without taking space in PNOR.  Another advantage is a
faster power on time over running with conventional traces enabled.
Trace lite sends trace data to the console output as ASCII hex values.
Traces can be recreated using a command line tool called "weave"
and the hbotStringFile.

# How to enable trace-lite traces to console

Need to do an attribute override if you don't want to recompile code.

*ATTR_OP_TRACE_LITE* needs to be set to non-zero
### Copy this to a temporary file (ie. op_trace_lite_override.txt)
```
CLEAR

target = k0:s0
ATTR_OP_TRACE_LITE 0x01
```

### From OpenPower build, run the attributeOverride tool
Example:
./output/build/hostboot-bXYZ/obj/genfiles/attributeOverride op_trace_lite_override.txt

Creates attrOverride.bin

### Copy attrOverride.bin to BMC as /usr/local/share/pnor/ATTR_TMP

During next power on trace-lite traces should be seen on the console
or you could use traceLite.sh to parse the traces.


# What is traceLite.sh
This is a wrapper script which will ssh to the SOL console and then parse
the trace-lite traces with the weave tool on-the-fly.

This script requires the user to have enabled the trace-lite traces first (see above for steps)

Since this script opens an interactive ssh to the SOL console, you need to
exit this script by entering two characters "~."

Under-the-covers, this script is calling Expect script, login_bmc, which logs
into the SOL console.  Then traceLite.sh tees that output into weave tool
which then parses the trace data into human-readable form.


## How to use traceLite.sh

At a minimum, you need to provide the BMC system name with the -s option.

A recommended option is to provide your base hostboot OpenPower directory
with the -b option.  This will then allow the script to find the tools it needs
to run to parse the trace-lite traces in this directory path.

Also recommend passing in -o option so the SOL output is saved to this file
so it can be parsed later manually by the weave tool.
`cat raw_SOL_output | weave hbotStringFile`

The port number for the HB trace console defaults to 2200, this can be changed
with the -p option.

If running simics, the BMC system and console port number are forwarded through
the system that simics is running on. In this case, the system name returned by
running '!hostname' at the simics prompt can be used as the BMC system name, and
the port num connected to 2200 returned by running 'list-port-forwarding-setup'
at the simics prompt can be used as the BMC port number.

Example:
**traceLite.sh -s wsbmc021 -b /tmp/op_sb/output/build/hostboot-b28407123f5e5e834d658f994432ea77f8ba01d9 -o raw_SOL_output**

Example (SIMICS):
**traceLite.sh -s gfwr713 -p 1337 -b /tmp/op_sb/output/build/hostboot-b28407123f5e5e834d658f994432ea77f8ba01d9

A script help text is provided to see other options
**traceLite.sh -h**

**In another terminal, power on the system.**
Your terminal with traceLite.sh running should start outputting parsed traces.

## Trace format:

###Raw SOL output
HB Timestamp | TID Component | trace_lite HashValue argument_data

- HB Timestamp = Hostboot timestamp (a relative timestamp)
- TID = Thread ID
- Component = component name
- HashValue = hbotStringFile hash value for this trace
- argument_data = numbers or string values (used to fill in trace string like printk())

```
66.25437|738 EEPROM|trace_lite E9EDD456 000000000003001E
66.25457|738 EEPROM|trace_lite 53CA5913 0000000000050001 0000000000000000 0000000000000003 0000000000000001 00000000000000A6 000000000003001E
66.25479|738 EEPROM|trace_lite 94861AA9
66.25555|738 I2C|trace_lite DD51B059
```

### Parsed trace (output from weave tool)

HB Timestamp | TID Component_Name | ASCII trace text
```
66.25437|738 EEPROM|Targ 0003001E
66.25457|738 EEPROM|--Adding i2cm=00050001, type=0, eng=3, port=1, addr=A6 for 0003001E
66.25479|738 EEPROM|<<getEEPROMs()
66.25555|738 I2C|<<getDeviceInfo
66.25565|738 HDAT|<<[hdatGetI2cDeviceInfo]
```

