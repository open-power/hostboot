
# Using the FFDC/XML Error Parsing Tools

For FAPI2, the parseErrorInfo PERL script has changed. The main goal was to
enable FFDC generation classes/methods. This enables a named-parameter
model as well as tucking the FFDC generation into a container which can
easily be used by the FAPI_ASSERT macro.

## Using the Tools

parseErrorInfo.pl [--empty-ffdc-classes] [--use-variable-buffers] --output-dir=<output dir> <filename1> <filename2> ...
- This perl script will parse HWP Error XML files and creates the following files:
- hwp_return_codes.H. HwpReturnCode enumeration (HWP generated errors)
- hwp_error_info.H.   Error information (used by FAPI_SET_HWP_ERROR when a HWP generates an error)
- collect_reg_ffdc.C. Function to collect register FFDC
- set_sbe_error.H.    Macro to create an SBE error

The --empty-ffdc-classes option is for platforms which don't collect FFDC. It will generate stub classes which
will allow the source to have the same code, but compile to no-ops on certain platforms.

The --use-variable-bufers option is for platforms which support variable buffers.

The XML input is the same format as for P8

## Using the Generated Classes

Each error found in the XML files generates a class in hwp_ffdc_classes.H.
The name of the class is the same as the return code itself and the set methods
are the same as the elements the xml described as needing colletion.

Take for example RC_MBVPD_INVALID_MT_DATA. Here is the XML:

    <hwpError>
        <rc>RC_MBVPD_INVALID_MT_DATA</rc>
        <description>
            To get the proper MT data, we need a valid
            dimm rank combination.
        </description>
        <ffdc>RANK_NUM</ffdc>
        <callout>
          <procedure>CODE</procedure>
          <priority>HIGH</priority>
        </callout>
     </hwpError>

It generates an FFDC class which looks like this (simplified):
Note that the prefix "RC_" is stripped by the parser.

    class MBVPD_INVALID_MT_DATA
    {
      public:
        MBVPD_INVALID_MT_DATA( ... )
        { FAPI_ERR("To get the proper MT data, we need a valid dimm rank combination."); }

        MBVPD_INVALID_MT_DATA& set_RANK_NUM(const T& i_value)
        { <setup ffdc> }

        void execute(void)
        { ... }
    };

To use this, for example, you may do:

    FAPI_ASSERT( foo != bar,
                 fapi2::MBVPD_INVALID_MT_DATA().set_RANK_NUM(l_rank),
                 "foo didn't equal bar" );

Notice the description of the error is automatically logged.

## Buffer Support

In FAPI, a ReturnCode had a mechanism for "containing" an error from an
ecmdDataBuffer. The API, setEcmdError(), no longer exists. fapi2::buffers
return ReturnCodes, and as such the FFDC information is added in a manner
consistent with the rest of the FFDC gathering.

There is a new error xml file specifically for buffers called
buffer_error.xml. It will generate an FFDC class which will take a buffer
as an argument and generate the correct FFDC.

    <hwpError>
        <rc>RC_FAPI2_BUFFER</rc>
        <description>
            fapi2 error from a buffer operation
        </description>
        <buffer>BUFFER</buffer>
        <callout>
            <procedure>CODE</procedure>
            <priority>HIGH</priority>
        </callout>
    </hwpError>

And its FFDC class:

    class FAPI2_BUFFER
    {
      public:
        FAPI2_BUFFER( ... )
        { FAPI_ERR("fapi2 error from a buffer operation"); }

        FAPI2_BUFFER& set_BUFFER(const fapi2::variable_buffer& i_value)
        { ... }

        template< typename T >
        FAPI2_BUFFER& set_BUFFER(const fapi2::buffer<T>& i_value)
        { ... }
    };

And it can be used:

    fapi2::buffer<uint64_t> foo;
    fapi2::variable_buffer  bar;

    FAPI_ASSERT( rc != FAPI2_RC_SUCCESS,
                 fapi2::FAPI2_BUFFER().set_FAPI2_BUFFER(foo),
                 "problem with buffer" );

    FAPI_ASSERT( rc != FAPI2_RC_SUCCESS,
                 fapi2::FAPI2_BUFFER().set_FAPI2_BUFFER(bar),
                 "problem with buffer" );

Note the indifference to integral or variable buffers.

### Collecting Buffers as Part of FFDC

To collect a buffer as part of an FFDC collection (as opposed to being
the FFDC you want to collect) you can add it to the XML:

    <buffer>RAS_STATUS</buffer>

This will generate fapi2::buffer and fapi2::variable_buffer set methods
for this element:

    fapi2::buffer<uint64_t> data;
    set_RAS_STATUS(data) ...

Also, you can force the conversion of the buffer to an integral
type without changing the XML

    <ffdc>RAS_STATUS</ffdc>

    fapi2::buffer<uint64_t> data;
    set_RAS_STATUS(unt64_t(data)) ...

## Error Log Generation

FAPI had a function called fapiLogError() which would generate platform
errors. The pattern was to call fapiLogError() at the end of the block
which generated the FFDC. With the addition of the FFDC classes, this
is no longer needed - the class knows to create these logs for you.

However, the severity information is needed by this logging mechanism.
It was an argument to fapiLogError(), and so it's been added to the
constructor of the FFDC class:

rc_repair_ring_invalid_ringbuf_ptr(fapi2::errlSeverity_t i_sev, ...)

It defaults to "unrecoverable" and so only need be set for errors
which have a different severity. That is, doing nothing will get you
and error log with unrecoverable severity - which was the default
for FAPI.

## Known Limitations

- Collecting register FFDC is not presently implemented.
- Calling out to hwp to collect FFDC is not presently implemented.
- The FirstFailureData class does not have a platform pointer
