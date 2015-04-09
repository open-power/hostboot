
# FAPI 2 and FAPI Lite definitions for targets, buffers, error handling.

## Were are some examples?

Examples can be found in the "Related Pages" tab. These examples are constantly
being expanded, please check back often.

## How is the code structured?

There is a new namespace; fapi2. This was created to prevent
the FAPI 1 code, in the fapi namespace, from colliding with the new code.

- Most documentation can be found under the class definition.
- Documentation for FAPI_TRY/FAPI_ASSERT is in the file error_scope.H,
  and doesn't have a "tab" in the HTML like the classes and the namespaces do.
- The documentation for TargeType is in the fapi namespace section.

## What do I need to implement for my platform?

### fapi2::buffer and fapi2::variable_buffer
There should be nothing for platforms to implement in the buffer code.
Smaller platforms which use fapi2::variable_buffer will need to
ensure they have an implementation of std::vector. Hostboot has one
which I'm sure you can steal if needed.

### fapi2::Target and fapi2::TargetType
Target is defined as a template of <TargetType, Value> where
Value is defined per platform. Smaller platforms will want an integer
type here, say uint64_t. Larger platforms may want to change this to
a pointer to an underlying platform specific targeting object. This change
can be made in plat_target.H

The target traversing functions will need to be implemented per-platform.

### Hardware Access (fapi2::getScom() ...)

All of the hardware access functions are assumed to need implementation
per platform.

plat_hw_access.H is used for platform definitions. Macros or other
platform definitions related to hw access can go in here.

fapi2_hw_access.H is the common hw access definitions and templates. It
includes plat_hw_access.H and so definitions in plat_hw_access.H can
be used in fapi2 common code.

hw_access.H is for platform specializations of the templates in
fapi2_hw_access.H.

Please use template specialization for target types which need special
treatment. The API documented here are generic, but they can be made
very specific for a target type or composite type.

For example (perhaps a poor example ...)

    template< TargetType K >
    ReturnCode getScom(const Target<K>& i_target, const uint64_t i_address,
                       buffer<uint64_t>& o_data)
can become

    template<>
    ReturnCode getScom(const Target<TARGET_TYPE_DIMM>& i_target, const uint64_t i_address,
                       buffer<uint64_t>& o_data)
for DIMMs

or

    template<>
    ReturnCode getScom(const Target<TARGET_TYPE_XBUS | TARGET_TYPE_ABUS>& i_target, const uint64_t i_address,
                       buffer<uint64_t>& o_data)

for XBUS and ABUS

### fapi2::ReturnCode and error_scope.H

For smaller platforms, a fapi::ReturnCode is nothing but a uint64_t. For
larger platforms fapi2::ReturnCode inherits from an FFDC object.

This difference is contained in
return_code.H, and noted with the preprocessor macro FAPI2_NO_FFDC.
Define FAPI2_NO_FFDC to get the simple representation of fapi2::ReturnCode,
and undefine it to get the FFDC class included.

error_scope.H refers to platform specific macros which can be defined
in plat_error_scope.H.

### Attributes

As in FAPI 1, platforms will need to implement the mechanism behind the
ATTR_GET/SET macros.

## How to report an issue?

Something in here is wrong - I'm sure of it. But you found it before someone
else. Please don't fire off an email into the ether; it will get lost.
Report an issue. Issues can be tracked and you can see what other issues are
taking priority over yours, etc. It's just better for everyone.

__To report an issue use Clear Quest__
  - Tier: ip Firmware
  - Reported Release: FW910
  - Subsystem: Hostboot
  - Component: FAPI

## Not sure how to do something?

So you've read the API documentation and it's horrible. You can't figure
out how to get anything done. Could be an issue, could be you just need the
crazy engineer who specified this horrible mess to see what struggles they
created in their overzealous attempt to make things "simple."

__Put it on the wiki__

You could send someone an email, and that might work out great. But if you
use the wiki you can be abrasive with your comments! Others might be able
to help or offer an opinion or become a member of the virtual posse you're
gathering to track down the crazy engineer. Good fun? You need a hobby.

None the less, the crazy engineer should update the FAPI 2 documentation when
the best practice is worked out, or create an issue to track the change
(and add it to a test case.)

Examples can be found in the "Related Pages" tab.

Questions have been asked as topics on the PFD/HW for P9 community wiki.

## Something missing? Before you report an issue ...

Many of the API from FAPI 1 have been changed into templated functions. For
example,

    ecmdDataBuffer::getDoubleWordLength() -> fapi::buffer::getLength<uint64_t>()
    ecmdDataBuffer::getWordLength() -> fapi::buffer::getLength<uint32_t>()
    ecmdDataBuffer::getHalfWordLength() -> fapi::buffer::getLength<uint16_t>()

Some API have been deprecated in favor of other API, some API have been
deprecated and are waiting for a use-case, and they'll be implemented.
A list of deprecated ecmdDataBuffer functions can be found in the
fapi::buffer_base class documentation.

Some API have been removed/deprecated and are expected to return in a different
form once the requirements are understood. Examples of this are the compressed
fapi::buffers. While platforms may need these functions, they have been removed
from the class itself as they are not vital to the class operation. These
functions, as needed, will be replaced with utility functions which perform the
operations needed for the platform. An example is fapi::Target::toString.
It has been replaced with fapi::toString(Target, ...) which can be overloaded
to take any type, and makes a nice utility for the fapi namespace.

Some API have plum been forgotten. You should open an issue so we can track
the implementation.

## Where's the documentation for Attributes?

The attribute macros are not expected to change for FAPI 2:

    l_rc = FAPI_ATTR_GET(<ID>, l_pTarget, l_val);
    l_rc = FAPI_ATTR_SET(<ID>, l_pTarget, l_val);
    l_rc = FAPI_ATTR_GET_PRIVILEGED(<ID>, l_pTarget, l_val);
    l_rc = FAPI_ATTR_SET_PRIVILEGED(<ID>, l_pTarget, l_val);

There is one outstanding question:
    1. whether we should/can change from a pointer to a target to a reference
    to a target to save a dereference on the smaller platforms (maybe it gets
    optimized out anyway?)

    Seems like the answer will be "no," but this depends on the PPE attribute
    look up scheme I think. Work in Progress.

## Where's the FFDC documentation?

Currently scheduled for End of February, 2015.

## Other Known Issues

- Thread local storage is broken on gcc 4.8, and the thread_local variables in
error_scope.H will need to become pthread TLS for the time being.
