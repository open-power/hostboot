# Checklist for making changes to `libpldm`

## Philosophy and influences

- [Good Practices in Library Design, Implementation, and Maintenance - Ulrich
  Drepper][goodpractice]

[goodpractice]: https://www.akkadia.org/drepper/goodpractice.pdf

- [How Do I Make This Hard to Misuse? - Rusty Russell][rusty-api-scale-good]

[rusty-api-scale-good]: https://ozlabs.org/~rusty/index.cgi/tech/2008-03-30.html

- [What If I Don't Actually Like My Users? - Rusty Russell][rusty-api-scale-bad]

[rusty-api-scale-bad]: https://ozlabs.org/~rusty/index.cgi/tech/2008-04-01.html

- [Red flags that indicate questionable quality - Lennart
  Poettering][poettering-library-red-flags]

[poettering-library-red-flags]:
  https://mastodon.social/@pid_eins/112517953375791453

- [Not sure if this is a gcc bug or some weird corner of UB or what... - Andrew
  Zonenberg][azonenberg-packed-struct]

[azonenberg-packed-struct]: https://ioc.exchange/@azonenberg/112535511250395148

- [The Good, the Bad, and the Weird - Trail of Bits
  Blog][trail-of-bits-weird-machines]

[trail-of-bits-weird-machines]:
  https://blog.trailofbits.com/2018/10/26/the-good-the-bad-and-the-weird/

- [Logic for Programmers - Hillel Wayne][logic-for-programmers]

[logic-for-programmers]: https://leanpub.com/logic

- [Parse, don’t validate - Alexis King][alexis-king-parse-dont-validate]

[alexis-king-parse-dont-validate]:
  https://lexi-lambda.github.io/blog/2019/11/05/parse-don-t-validate/

## References

- [C17 draft standard][c17-draft-standard]

[c17-draft-standard]:
  https://web.archive.org/web/20181230041359if_/http://www.open-std.org/jtc1/sc22/wg14/www/abq/c17_updated_proposed_fdis.pdf

- [SEI CERT C Coding Standard][sei-cert-c-coding-standard]

[sei-cert-c-coding-standard]:
  https://wiki.sei.cmu.edu/confluence/display/c/SEI+CERT+C+Coding+Standard

- [Common Weakness Enumeration (CWE) - Software
  Development][common-weakness-enumeration-sw]

[common-weakness-enumeration-sw]:
  https://cwe.mitre.org/data/definitions/699.html

## Definitions

- **Error condition**: An invalid state reached at runtime, caused either by
  resource exhaustion, or incorrect use of the library's public APIs and data
  types.

- **Invariant**: A condition in the library's implementation that must never
  evaluate false.

- **Public API**: Any definitions and declarations under `include/libpldm`.

- **Wire format**: Any message structure defined in the DMTF PLDM protocol
  specifications.

## Elaborations

- Resource exhaustion is always an error condition and never an invariant
  violation.

- An invariant violation is always a programming failure of the library's
  implementation, and never the result of incorrect use of the library's public
  APIs (see error condition).

- Corollaries of the above two points:

  - Incorrect use of public API functions is always an error condition, and is
    dealt with by returning an error code.

  - Incorrect use of static functions in the library's implementation is an
    invariant violation which may be established using `assert()`.

- `assert()` is the recommended way to demonstrate invariants are upheld.

## Adding a new API

### Naming macros, functions and types

- [ ] All publicly exposed macros, types and functions relating to the PLDM
      specifications must be prefixed with either `pldm_` or `PLDM_` as
      appropriate

  - The only (temporary) exception are the `encode_*()` and `decode_*()`
    function symbols

- [ ] All publicly exposed macros, types and functions relating to the library
      implementation must be prefixed with `libpldm_` or `LIBPLDM_`

- [ ] All `pldm_`-prefixed symbols must also name the related specification. For
      example, for DSP0248 Platform Monitoring and Control, the symbol prefix
      should be `pldm_platform_`.

- [ ] All enum members must be prefixed with the type name

### All other concerns

- [ ] My new public message codec functions take a `struct` representing the
      message as a parameter

  - Function prototypes must _not_ decompose the message to individual
    parameters. This approach is not ergonomic and is difficult to make
    type-safe. This is especially true for message decoding functions which must
    use pointers for out-parameters, where it has often become ambiguous whether
    the underlying memory represents a single object or an array.

- [ ] Each new `struct` I've defined is used in at least one new function I've
      added to the public API.

- [ ] My new public `struct` definitions are _not_ marked
      `__attribute__((packed))`

- [ ] My new public `struct` definitions do _not_ define a flexible array
      member, unless:

  - [ ] It's contained in an `#ifndef __cplusplus` macro guard, as flexible
        arrays are not specified by C++, and

  - [ ] I've implemented an accessor function so the array base pointer can be
        accessed from C++, and

  - [ ] It is defined as per the C17 specification by omitting the length[^1]

    - Note: Any array defined with length 1 is _not_ a flexible array, and any
      access beyond the first element invokes undefined behaviour in both C and
      C++.

  - [ ] I've annotated the flexible array member with `LIBPLDM_CC_COUNTED_BY()`

[^1]:
    [C17 draft specification][c17-draft-standard], 6.7.2.1 Structure and union
    specifiers, paragraph 18.

- [ ] If my work interacts with the PLDM wire format, then I have done so using
      the `msgbuf` APIs found in `src/msgbuf.h` (and under `src/msgbuf/`) to
      minimise concerns around spatial memory safety and endian-correctness.

- [ ] All my error conditions are handled by returning an error code to the
      caller.

- [ ] All my invariants are tested using `assert()`.

- [ ] I have not used `assert()` to evaluate any error conditions without also
      handling the error condition by returning an error code the the caller.

  - Release builds of the library are configured with `assert()` disabled
    (`-Db_ndebug=if-release`, which provides `-DNDEBUG` in `CFLAGS`).

- [ ] My new APIs return negative `errno` values on error and not PLDM
      completion codes.

  - [ ] The specific error values my function returns and their meaning in the
        context of the function call are listed in the API documentation.

- [ ] If I've added support for a new PLDM message type, then I've implemented
      both the encoder and decoder for that message. Note this applies for both
      request _and_ response message types.

- [ ] My new function symbols are marked with `LIBPLDM_ABI_TESTING` in the
      implementation

- [ ] I've implemented test cases with reasonable branch coverage of each new
      function I've added

- [ ] I've guarded the test cases of functions marked `LIBPLDM_ABI_TESTING` so
      that they are not compiled when the corresponding function symbols aren't
      visible

- [ ] If I've added support for a new message type, then my commit message
      specifies all of:

  - [ ] The relevant DMTF specification by its DSP number and title
  - [ ] The relevant version of the specification
  - [ ] The section of the specification that defines the message type

- [ ] If my work impacts the public API of the library, then I've added an entry
      to `CHANGELOG.md` describing my work

## Stabilising an existing API

- [ ] The API of interest is currently marked `LIBPLDM_ABI_TESTING`

- [ ] My commit message links to a publicly visible patch that makes use of the
      API

- [ ] My commit updates the annotation from `LIBPLDM_ABI_TESTING` to
      `LIBPLDM_ABI_STABLE` only for the function symbols demonstrated by the
      patch linked in the commit message.

- [ ] I've removed guards from the function's tests so they are always compiled

- [ ] If I've updated the ABI dump, then I've used the OpenBMC CI container to
      do so.

## Updating an ABI dump

To update the ABI dump you'll need to build an appropriate OpenBMC CI container
image of your own. Some hints on how to do this locally can be found [in the
openbmc/docs repository][openbmc-docs-local-ci]. You can list your locally built
images with `docker images`.

[openbmc-docs-local-ci]:
  https://github.com/openbmc/docs/blob/master/testing/local-ci-build.md

Assuming:

```
export OPENBMC_CI_IMAGE=openbmc/ubuntu-unit-test:2024-W21-ce361f95ff4fa669
```

the ABI dump can be updated with:

```
docker run \
  --cap-add=sys_admin \
  --rm=true \
  --privileged=true \
  -u $USER \
  -w $(pwd) \
  -v $(pwd):$(pwd) \
  -e MAKEFLAGS= \
  -t $OPENBMC_CI_IMAGE \
  ./scripts/abi-dump-updater
```

## Removing an API

- [ ] If the function is marked `LIBPLDM_ABI_TESTING`, then I have removed it

- [ ] If the function is marked `LIBPLDM_ABI_STABLE`, then I have changed the
      annotation to `LIBPLDM_ABI_DEPRECATED` and left it in-place.

  - [ ] I have updated the ABI dump, or will mark the change as WIP until it has
        been.

- [ ] If the function is marked `LIBPLDM_ABI_DEPRECATED`, then I have removed it
      only after satisfying myself that each of the following is true:

  - [ ] There are no known users of the function left in the community
  - [ ] There has been at least one tagged release of `libpldm` subsequent to
        the API being marked deprecated

## Renaming an API

A change to an API is a pure rename only if there are no additional behavioural
changes. Renaming an API with no other behavioural changes is really two
actions:

1. Introducing the new API name
2. Deprecating the old API name

- [ ] Only the name of the function has changed. None of its behaviour has
      changed.

- [ ] Both the new and the old functions are declared in the public headers

- [ ] I've aliased the old function name to the new function name via the
      `libpldm_deprecated_aliases` list in `meson.build`

- [ ] I've added a [semantic patch][coccinelle] to migrate users from the old
      name to the new name

[coccinelle]: https://coccinelle.gitlabpages.inria.fr/website/

- [ ] I've updated the ABI dump to capture the rename, or will mark the change
      as WIP until it has been.

## Fixing Implementation Defects

- [ ] My change fixing the bug includes a [Fixes tag][linux-kernel-fixes-tag]
      identifying the change introducing the defect.

[linux-kernel-fixes-tag]:
  https://docs.kernel.org/process/submitting-patches.html#describe-your-changes

- [ ] My change fixing the bug includes test cases demonstrating that the bug is
      fixed.
