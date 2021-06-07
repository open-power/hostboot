## Overview of pldmtool

pldmtool is a client tool that acts as a PLDM requester which runs on the BMC.
pldmtool sends the request message and displays the response message also
provides flexibility to parse the response message and display it in readable
format.

pldmtool supports the subcommands for PLDM types such as base, platform, bios,
fru, and oem-ibm.

- Source files are implemented in C++.
- Consumes pldm/libpldm encode and decode functions.
- Communicates with pldmd daemon running on BMC.
- Enables writing functional test cases for PLDM stack.

please refer the DMTF PLDM specifications with respect to the pldm types.
https://www.dmtf.org/


## Code organization

Source files in pldmtool repository are named with respect to the PLDM type.

Example:
```
pldm_base_cmd.[hpp/cpp], pldm_fru_cmd.[hpp/cpp]
```

pldmtool commands for corresponding PLDM type is constructed with the help of
encode request and decode response APIs which are implemented in pldm/libpldm.

Example:

Given a PLDM command "foo" of PLDM type "base" the pldmtool should consume
following API from the libpldm.

```
- encode_foo_req()  - Send the required input parameters in the request message.
- decode_foo_resp() - Decode the response message.
```

If PLDM commands are not yet supported in the pldmtool repository user can
directly send the request message with the help of **pldmtool raw -d <data>** option.


## Usage

User can see the pldmtool supported PLDM types in the usage output available
with the **-h** help option as shown below:

```
pldmtool -h
PLDM requester tool for OpenBMC
Usage: pldmtool [OPTIONS] SUBCOMMAND

Options:
  -h,--help                   Print this help message and exit

Subcommands:
  raw                         send a raw request and print response
  base                        base type command
  bios                        bios type command
  platform                    platform type command
  fru                         FRU type command
  oem-ibm                     oem type command

```
pldmtool command prompt expects a PLDM type to display the list of supported
commands that are already implemented for that particular PLDM type.

```
Command format: pldmtool <pldmType> -h
```
Example:

```
$ pldmtool base -h

base type command
Usage: pldmtool base [OPTIONS] SUBCOMMAND

Options:
  -h,--help                   Print this help message and exit

Subcommands:
  GetPLDMTypes                get pldm supported types
  GetPLDMVersion              get version of a certain type
  GetTID                      get Terminus ID (TID)
  GetPLDMCommands             get supported commands of pldm type

```
More help on the command usage can be found by specifying the PLDM type and the
command name with **-h** argument as shown below.

```
Command format: pldmtool <pldmType> <commandName> -h
```

Example:
```
$ pldmtool base GetPLDMTypes -h

get pldm supported types
Usage: pldmtool base GetPLDMTypes [OPTIONS]

Options:
  -h,--help                   Print this help message and exit
  -m,--mctp_eid UINT          MCTP endpoint ID
  -v,--verbose
```


## pldmtool raw command usage

pldmtool raw command option accepts request message in the hexadecimal
bytes and send the response message in hexadecimal bytes.

```
$ pldmtool raw -h
send a raw request and print response
Usage: pldmtool raw [OPTIONS]

Options:
  -h,--help                   Print this help message and exit
  -m,--mctp_eid UINT          MCTP endpoint ID
  -v,--verbose
  -d,--data UINT              REQUIRED raw data
```

**pldmtool request message format:**

```
pldmtool raw --data 0x80 <pldmType> <cmdType> <payloadReq>

payloadReq - stream of bytes constructed based on the request message format
             defined for the command type as per the spec.
```

**pldmtool response message format:**

```
<instanceId> <hdrVersion> <pldmType> <cmdType> <completionCode> <payloadResp>

payloadResp - stream of bytes displayed based on the response message format
              defined for the command type as per the spec.
```
Example:

```
$ pldmtool raw -d 0x80 0x00 0x04 0x00 0x00

Request Message:
08 01 80 00 04 00 00
Response Message:
08 01 00 00 04 00 1d 00 00 00 00 00 00 80

```
## pldmtool output format

In the current pldmtool implementation response message from pldmtool is parsed
and displayed in the JSON format.

Example:
```
$ pldmtool base GetPLDMTypes
[
    {
        "PLDM Type": "base",
        "PLDM Type Code": 0
    },
    {
        "PLDM Type": "platform",
        "PLDM Type Code": 2
    },
    {
        "PLDM Type": "bios",
        "PLDM Type Code": 3
    },
    {
        "PLDM Type": "fru",
        "PLDM Type Code": 4
    },
    {
        "PLDM Type": "oem-ibm",
        "PLDM Type Code": 63
    }
]
```
## pldmtool with mctp_eid option

Use **-m** or **--mctp_eid** option to send pldm request message to remote mctp
end point and by default pldmtool consider mctp_eid value as **'08'**.

```
Command format:

pldmtool <pldmType> <cmdType> -m <mctpId>
pldmtool raw -d 0x80 <pldmType> <cmdType> <payloadReq> -m <mctpId>
```

Example:
```
$ pldmtool base GetPLDMTypes -m 8

$ pldmtool raw -d 0x80 0x00 0x04 0x00 0x00 -m 0x08

```

## pldmtool verbosity

By default verbose flag is disabled on the pldmtool.

Enable verbosity with **-v** flag as shown below.

Example:

```
pldmtool base GetPLDMTypes -v
```
