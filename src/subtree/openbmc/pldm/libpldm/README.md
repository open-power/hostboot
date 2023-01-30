# libpldm

This is a library which deals with the encoding and decoding of PLDM messages.
It should be possible to use this library by projects other than OpenBMC, and
hence certain constraints apply to it:

- keeping it light weight
- implementation in C
- minimal dynamic memory allocations
- endian-safe
- no OpenBMC specific dependencies

Source files are named according to the PLDM Type, for eg base.[h/c], fru.[h/c],
etc.

Given a PLDM command "foo", the library will provide the following API: For the
Requester function:

```c
encode_foo_req() - encode a foo request
decode_foo_resp() - decode a response to foo
```

For the Responder function:

```c
decode_foo_req() - decode a foo request
encode_foo_resp() - encode a response to foo
```

The library also provides API to pack and unpack PLDM headers.

## To Build

Need `meson` and `ninja`. Alternatively, source an OpenBMC ARM/x86 SDK.

```sh
meson setup builddir && ninja -C builddir
```

## To run unit tests

The simplest way of running the tests is as described by the meson man page:

```sh
meson setup builddir && meson test -C builddir
```

## OEM/vendor-specific functions

This will support OEM or vendor-specific functions and semantic information.
Following directory structure has to be used:

```text
 libpldm
    |---- include/libpldm
    |        |---- oem/<oem_name>/libpldm
    |                    |----<oem based .h files>
    |---- src
    |        |---- oem/<oem_name>
    |                    |----<oem based .c files>
    |---- tests
    |        |---- oem/<oem_name>
    |                    |----<oem based test files>

```

<oem_name> - This folder must be created with the name of the OEM/vendor in
lower case.

Header files & source files having the oem functionality for the libpldm library
should be placed under the respective folder hierarchy as mentioned in the above
figure. They must be adhering to the rules mentioned under the libpldm section
above.

Once the above is done a meson option has to be created in
`libpldm/meson_options.txt` with its mapped compiler flag to enable conditional
compilation.

For consistency would recommend using "oem-<oem_name>".

The `libpldm/meson.build` and the corresponding source file(s) will need to
incorporate the logic of adding its mapped compiler flag to allow conditional
compilation of the code.

## Requester APIs

The pldm requester API's are present in `src/requester` folder and they are
intended to provide API's to interact with the desired underlying transport
layer to send/receive pldm messages.

**NOTE** : In the current state, the requester API's in the repository only
works with [specific transport mechanism](https://github.com/openbmc/libmctp) &
these are going to change in future & probably aren't appropriate to be writing
code against.
