# To Build

Need `meson` and `ninja`. Alternatively, source an OpenBMC ARM/x86 SDK.

```
meson build && ninja -C build
```

## To run unit tests

The simplest way of running the tests is as described by the meson man page:

```
meson builddir && meson test -C builddir
```

Alternatively, tests can be run in the OpenBMC CI docker container, or with an
OpenBMC x86 sdk(see below for x86 steps).

```
meson -Doe-sdk=enabled build
ninja -C build test
```

## To enable pldm verbosity

pldm daemon accepts a command line argument `--verbose` or `--v` or `-v` to
enable the daemon to run in verbose mode. It can be done via adding this option
to the environment file that pldm service consumes.

```
echo 'PLDMD_ARGS="--verbose"' > /etc/default/pldmd
systemctl restart pldmd
```

## To disable pldm verbosity

```
rm /etc/default/pldmd
systemctl restart pldmd
```

# Code Organization

At a high-level, code in this repository belongs to one of the following three
components.

## libpldmresponder

This library provides handlers for incoming PLDM request messages. It provides
for a registration as well as a plug-in mechanism. The library is implemented in
modern C++, and handles OpenBMC's platform specifics.

The handlers are of the form

```
Response handler(Request payload, size_t payloadLen)
```

Source files are named according to the PLDM Type, for eg base.[hpp/cpp],
fru.[hpp/cpp], etc.

## OEM/vendor-specific functions

This will support OEM or vendor-specific functions and semantic information.
Following directory structure has to be used:

```
    pldm repo
     |---- oem
            |----<oem_name>
                      |----libpldmresponder
                            |---<oem based handler files>

```

<oem_name> - This folder must be created with the name of the OEM/vendor in
lower case. Folders named libpldm and libpldmresponder must be created under the
folder <oem_name>

Files having the oem functionality for the libpldmresponder library should be
placed under the folder oem/<oem_name>/libpldmresponder. They must be adhering
to the rules mentioned under the libpldmresponder section above.

Once the above is done a meson option has to be created in
`pldm/meson_options.txt` with its mapped compiler flag to enable conditional
compilation.

For consistency would recommend using "oem-<oem_name>".

The `pldm/meson.build` and the corresponding source file(s) will need to
incorporate the logic of adding its mapped compiler flag to allow conditional
compilation of the code.

## libpldm

pldm daemon links against the libpldm library during compilation, For more
information on libpldm please refer to
[libpldm](https://github.com/openbmc/libpldm)

## pldmtool

For more information on pldmtool please refer to plmdtool/README.md.

# Flows

This section documents important code flow paths.

## BMC as PLDM responder

a) PLDM daemon receives PLDM request message from underlying transport (MCTP).

b) PLDM daemon routes message to message handler, based on the PLDM command.

c) Message handler decodes request payload into various field(s) of the request
message. It can make use of a decode_foo_req() API, and doesn't have to perform
deserialization of the request payload by itself.

d) Message handler works with the request field(s) and generates response
field(s).

e) Message handler prepares a response message. It can make use of an
encode_foo_resp() API, and doesn't have to perform the serialization of the
response field(s) by itself.

f) The PLDM daemon sends the response message prepared at step e) to the remote
PLDM device.

## BMC as PLDM requester

a) A BMC PLDM requester app prepares a PLDM request message. There would be
several requester apps (based on functionality/PLDM remote device). Each of them
needn't bother with the serialization of request field(s), and can instead make
use of an encode_foo_req() API.

b) BMC requester app requests PLDM daemon to send the request message to remote
PLDM device.

c) Once the PLDM daemon receives a corresponding response message, it notifies
the requester app.

d) The requester app has to work with the response field(s). It can make use of
a decode_foo_resp() API to deserialize the response message.

# PDR Implementation

While PLDM Platform Descriptor Records (PDRs) are mostly static information,
they can vary across platforms and systems. For this reason, platform specific
PDR information is encoded in platform specific JSON files. JSON files must be
named based on the PDR type number. For example a state effecter PDR JSON file
will be named 11.json. The JSON files may also include information to enable
additional processing (apart from PDR creation) for specific PDR types, for eg
mapping an effecter id to a D-Bus object.

The PLDM responder implementation finds and parses PDR JSON files to create the
PDR repository. Platform specific PDR modifications would likely just result in
JSON updates. New PDR type support would require JSON updates as well as PDR
generation code. The PDR generator is a map of PDR Type -> C++ lambda to create
PDR entries for that type based on the JSON, and to update the central PDR repo.
