# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/beam/compiler_c_config.tcl $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2011,2013
#
# p1
#
# Object Code Only (OCO) source materials
# Licensed Internal Code Source Materials
# IBM HostBoot Licensed Internal Code
#
# The source code for this program is not published or otherwise
# divested of its trade secrets, irrespective of what has been
# deposited with the U.S. Copyright Office.
#
# Origin: 30
#
# IBM_PROLOG_END_TAG
############################################################
# Invocation of beam_configure:
#
#   '/afs/rchland.ibm.com/projects/esw/beam/newbeamreleases/beam-3.6.1/bin/beam_configure' 'powerpc64-unknown-linux-gnu-gcc' '--c' '--force' '-o' './obj/beam/compiler_c_config.tcl' '--headers' './src/include,./obj/genfiles' '--compile_flag=-std=c99 -O3 -nostdlib -mcpu=power7 -nostdinc -g -mno-vsx -mno-altivec -Wall -Werror -mtraceback=no -pipe' '--verbose'
#
# Location of compiler:
#
#   /opt/mcp/shared/powerpc64-gcc-20130412/wrappers/mchroot_wrapper.sh
#
############################################################
#
# This is BEAM configuration file that describes a compiler
# and a target machine. This was generated with beam_configure
# version "4.0".
#
# This information will help BEAM emulate this compiler's
# features, macros, and header file locations, so that BEAM
# can compile the same source code that the original compiler
# could compile, and understand it with respect to the machine's
# sizes and widths of types.
#
# The file format is Tcl, so basic Tcl knowledge may be beneficial
# for anything more than the simplest of modifications.
# 
# A quick Tcl primer:
# - Lines starting with "#" or ";#" are comments
# - Things inside balanced curly braces are literal strings {one string literal}
# - Things in square brackets that aren't in curly braces are function calls,
#   and will be expanded inline automatically. This causes the most problems in
#   double-quoted strings: "this is a function call: [some_func]"
#
# This file contains these sections:
#
# 1) Source language dialect
# 2) Default include paths
# 3) Target machine configuration
# 4) Predefined macros
# 5) Miscellaneous options
#
# Each section has variables that help configure BEAM. They should
# each be commented well. For additional documentation, please
# refer to the local documentation in the install point.
#
# Note that the order of the sections is not important,
# and variables may be set in any order.
#
# All variables are prefixed with name that corresponds to
# which language this configuration is for.
#
# For C compilers, the prefix is "beam::compiler::c"
# For C++, it is "beam::compiler::cpp"
#
############################################################

### This is the version of beam_configure that generated this
### configuration file.
  
set beam::compiler::c::generated_by_beam_configure "4.0"


### This tells BEAM which pre-canned settings to load.
### BEAM comes with some function attributes and argument
### mappers for gcc, xlc, and vac. If unsure, set this to
### "default".

set beam::compiler::c::cc "gcc"

  
############################################################
# Section 1: Source language dialect
############################################################
  
### The language_dialect variable selects among the available
### dialects of C and C++.
###
### By default, C files are set up as:
###
###    set beam::compiler::c::language_dialect c
###    set beam::compiler::c::c99_mode         0
###    set beam::compiler::c::strict_mode      0
###    set beam::compiler::c::gnu_mode         0
###    set beam::compiler::c::msvc_mode        0
###
### and C++ files are set up as:
###
###    set beam::compiler::cpp::language_dialect c++
###    set beam::compiler::cpp::c99_mode         0
###    set beam::compiler::cpp::strict_mode      0
###    set beam::compiler::cpp::gnu_mode         0
###    set beam::compiler::cpp::msvc_mode        0
###
### Note that the dialect must match the namespace.
### Don't set up the C++ language in the C namespace or
### things will probably fail.
###
### This defaults to be the same as the language being
### compiled (based on the source file extension).
### Normally, it should not be set.

# set beam::compiler::c::language_dialect old_c ;# K&R
# set beam::compiler::c::language_dialect c     ;# ANSI
# set beam::compiler::c::language_dialect c++

### In addition to simply using C or C++, different
### modes are provided to enable or disable language
### extensions. Some modes are incompatible with eachother
### or with the language_dialect above, and will produce
### errors.

### C99 mode enables C99 extensions in C code. It is not
### compatible with C++ code. This overrides old_c, and
### instead forces regular C.

# set beam::compiler::c::c99_mode 0
# set beam::compiler::c::c99_mode 1

### Strict mode disables all non-ANSI/ISO features. It
### is compatible with C and C++ code, but not with old_c.
  
# set beam::compiler::c::strict_mode 0
# set beam::compiler::c::strict_mode 1

### GNU mode enables GNU C extensions in C code and
### GNU C++ extensions in C++ code. This overrides
### old_c, and instead forces regular C.
###
### The value should be a 5 digit number representing
### the version of GCC to emulate. It is of this format:
###
###    major_version_num * 10000 +
###    minor_version_num * 100   +
###    patch_version_num
###
### so, GCC version "3.4.3" should be "30403".
###
### The minimum allowable value is "30200".

# set beam::compiler::c::gnu_mode 30200

set beam::compiler::c::gnu_mode 40702


### MSVC mode enables Microsoft extensions in C code and
### C++ code.
###
### The value should be a 3 or 4 digit number representing
### the version of MSVC to emulate.
###
### The minimum allowable value is "700".

# set beam::compiler::c::msvc_mode 700



### Other miscellaneous language settings. The values shown
### here are the defaults if they remain unset.

# set beam::compiler::c::language_friend_injection_enabled           0
# set beam::compiler::c::language_use_nonstandard_for_init_scope     0
# set beam::compiler::c::language_string_literals_are_const          1
# set beam::compiler::c::language_allow_dollar_in_id_chars           1
# set beam::compiler::c::language_end_of_line_comments_allowed       1
# set beam::compiler::c::language_allow_spaces_in_include_directive  0
# set beam::compiler::c::language_restrict_keyword_enabled           0
# set beam::compiler::c::language_allow_nonstandard_anonymous_unions 1
# set beam::compiler::c::language_trigraphs_allowed                  1
# set beam::compiler::c::language_wchar_t_is_keyword                 1
# set beam::compiler::c::language_bool_is_keyword                    1

set beam::compiler::c::language_restrict_keyword_enabled                  "1"
set beam::compiler::c::language_trigraphs_allowed                         "0"

  
############################################################
# Section 2: Default include paths
############################################################

### The system_include_path variable is a list of directories
### that will be searched in for system headers. Parser warnings
### are suppressed in these directories. These will come
### after any directories specified with -I on the command line.
  
# lappend beam::compiler::c::system_include_path {/usr/include}
# lappend beam::compiler::c::system_include_path {/usr/vacpp/include}

### Maybe your include paths are part of the environment
  
# if { [::info exists ::env(MY_INCLUDE_PATH)] } {
#   set beam::compiler::c::system_include_path \
#     [split $::env(MY_INCLUDE_PATH) $::beam::pathsep]
# }
  
lappend beam::compiler::c::system_include_path {/usr/lib/gcc/powerpc64-unknown-linux-gnu/4.7.2/include-fixed}
lappend beam::compiler::c::system_include_path {/usr/powerpc64-unknown-linux-gnu/usr/include}
lappend beam::compiler::c::system_include_path {/usr/lib/gcc/powerpc64-unknown-linux-gnu/4.7.2/include}

  
############################################################
# Section 3: Target machine configuration
############################################################

### These variables control the target machine and
### a few individual language options.
###
### Note: These examples do not cover all of the available
### options. For a complete list, refer to the BEAM documentation.
###
### Examples appear below the auto-configured ones.
  
set beam::compiler::c::target_char_bit                                    "8"
set beam::compiler::c::target_dbl_max_exp                                 "1024"
set beam::compiler::c::target_dbl_min_exp                                 "-1021"
set beam::compiler::c::target_flt_max_exp                                 "128"
set beam::compiler::c::target_flt_min_exp                                 "-125"
set beam::compiler::c::target_ldbl_max_exp                                "1024"
set beam::compiler::c::target_ldbl_min_exp                                "-968"
set beam::compiler::c::target_little_endian                               "0"
set beam::compiler::c::target_plain_char_is_unsigned                      "1"
set beam::compiler::c::target_ptrdiff_t_int_kind                          "long int"
set beam::compiler::c::target_size_t_int_kind                             "long unsigned int"
set beam::compiler::c::target_sizeof_double                               "8"
set beam::compiler::c::target_sizeof_float                                "4"
set beam::compiler::c::target_sizeof_int                                  "4"
set beam::compiler::c::target_sizeof_long                                 "8"
set beam::compiler::c::target_sizeof_long_double                          "16"
set beam::compiler::c::target_sizeof_long_long                            "8"
set beam::compiler::c::target_sizeof_pointer                              "8"
set beam::compiler::c::target_sizeof_short                                "2"
set beam::compiler::c::target_string_literals_are_readonly                "1"
set beam::compiler::c::target_wchar_t_int_kind                            "int"
set beam::compiler::c::target_wint_t_int_kind                             "unsigned int"

  
### Examples ###

### The number of bits in a char

# set beam::compiler::c::target_char_bit 8
    
### Default signedness options

# set beam::compiler::c::target_plain_char_is_unsigned              0
# set beam::compiler::c::target_plain_char_is_unsigned              1
#
# set beam::compiler::c::target_string_literals_are_readonly        0
# set beam::compiler::c::target_string_literals_are_readonly        1
#
# set beam::compiler::c::target_plain_int_bit_field_is_unsigned     0
# set beam::compiler::c::target_plain_int_bit_field_is_unsigned     1
#
# set beam::compiler::c::target_enum_bit_fields_are_always_unsigned 0
# set beam::compiler::c::target_enum_bit_fields_are_always_unsigned 1

### Endianness of target machine

# set beam::compiler::c::target_little_endian 0    
# set beam::compiler::c::target_little_endian 1

### Sizes of basic types in multiples of char. Since
### a char is defined to have size 1, it is not a
### configuration option.

# set beam::compiler::c::target_sizeof_short 2
# set beam::compiler::c::target_sizeof_int 4
# set beam::compiler::c::target_sizeof_long 4
# set beam::compiler::c::target_sizeof_long_long 8    
# set beam::compiler::c::target_sizeof_float 4
# set beam::compiler::c::target_sizeof_double 8
# set beam::compiler::c::target_sizeof_long_double 12
# set beam::compiler::c::target_sizeof_pointer 4

### Alignments of basic types in multiples of char. Since
### a char is defined to have alignment 1, it is not a
### configuration option.

# set beam::compiler::c::target_alignof_short 2
# set beam::compiler::c::target_alignof_int 4
# set beam::compiler::c::target_alignof_long 4
# set beam::compiler::c::target_alignof_long_long 4
# set beam::compiler::c::target_alignof_float 4
# set beam::compiler::c::target_alignof_double 4
# set beam::compiler::c::target_alignof_long_double 4
# set beam::compiler::c::target_alignof_pointer 4
    
### Special types

# set beam::compiler::c::target_sizeof_size_t     4
# set beam::compiler::c::target_size_t_int_kind   {unsigned int}
#
# set beam::compiler::c::target_sizeof_wchar_t      4
# set beam::compiler::c::target_wchar_t_int_kind    {int}
# set beam::compiler::c::target_wchar_t_is_unsigned 0
#
# set beam::compiler::c::target_sizeof_wint_t       4
# set beam::compiler::c::target_wint_t_int_kind     {int}
# set beam::compiler::c::target_wint_t_is_unsigned  0
#
# set beam::compiler::c::target_sizeof_char16_t      2
# set beam::compiler::c::target_char16_t_int_kind    {unsigned short}
#
# set beam::compiler::c::target_sizeof_char32_t      4
# set beam::compiler::c::target_char32_t_int_kind    {unsigned int}

### Floating-point characteristics. The default
### values for these variables depend on the sizes
### set beam::compiler::c::for the types. The examples shown here
### are appropriate if float is size 4, double is
### size 8, and long double is size 12.
###
### Note that these values do not have to be exact
### because BEAM currently has limited floating-point
### support.

# set beam::compiler::c::target_flt_max_exp 128
# set beam::compiler::c::target_flt_min_exp -125
# set beam::compiler::c::target_dbl_max_exp 1024
# set beam::compiler::c::target_dbl_min_exp -1021
# set beam::compiler::c::target_ldbl_max_exp 16384
# set beam::compiler::c::target_ldbl_min_exp -16381

### Other miscellaneous options. The values
### shown here are the default values.

# set beam::compiler::c::target_bit_field_container_size -1
# set beam::compiler::c::target_zero_width_bit_field_alignment -1
# set beam::compiler::c::target_zero_width_bit_field_affects_struct_alignment 0
# set beam::compiler::c::target_unnamed_bit_field_affects_struct_alignment 0
  
############################################################
# Section 4: Predefined macros
############################################################

### The predefined_macro variable is an associated array that
### maps the name of a macro to the value. Be sure that the
### value contains quotes inside the curly braces if the
### expansion should also contain quotes.
###
### Curly braces are allowed in the expansion text as long
### as they are properly balanced.
###
### There is no limit to the number of predefined macros that
### you can define.

# set beam::compiler::c::predefined_macro(identifier1)      {some_literal_value}
# set beam::compiler::c::predefined_macro(identifier2)      {"some string value with quotes"}
# set beam::compiler::c::predefined_macro(identifier3(x,y)) { do { code; } while((x) && (y)) }

set beam::compiler::c::predefined_macro(_ARCH_PPC)          {1}
set beam::compiler::c::predefined_macro(_ARCH_PPC64)        {1}
set beam::compiler::c::predefined_macro(_ARCH_PPCGR)        {1}
set beam::compiler::c::predefined_macro(_BIG_ENDIAN)        {1}
set beam::compiler::c::predefined_macro(_Bool)              {_Bool}
set beam::compiler::c::predefined_macro(_CALL_AIX)          {1}
set beam::compiler::c::predefined_macro(_CALL_AIXDESC)      {1}
set beam::compiler::c::predefined_macro(_FORTIFY_SOURCE)    {((defined __OPTIMIZE__ && __OPTIMIZE__ > 0) ? 2 : 0)}
set beam::compiler::c::predefined_macro(_LP64)              {1}
set beam::compiler::c::predefined_macro(__ATOMIC_ACQUIRE)   {2}
set beam::compiler::c::predefined_macro(__ATOMIC_ACQ_REL)   {4}
set beam::compiler::c::predefined_macro(__ATOMIC_CONSUME)   {1}
set beam::compiler::c::predefined_macro(__ATOMIC_RELAXED)   {0}
set beam::compiler::c::predefined_macro(__ATOMIC_RELEASE)   {3}
set beam::compiler::c::predefined_macro(__ATOMIC_SEQ_CST)   {5}
set beam::compiler::c::predefined_macro(__BIGGEST_ALIGNMENT__) {16}
set beam::compiler::c::predefined_macro(__BIG_ENDIAN__)     {1}
set beam::compiler::c::predefined_macro(__BYTE_ORDER__)     {__ORDER_BIG_ENDIAN__}
set beam::compiler::c::predefined_macro(__CHAR16_TYPE__)    {short unsigned int}
set beam::compiler::c::predefined_macro(__CHAR32_TYPE__)    {unsigned int}
set beam::compiler::c::predefined_macro(__CHAR_BIT__)       {8}
set beam::compiler::c::predefined_macro(__CHAR_UNSIGNED__)  {1}
set beam::compiler::c::predefined_macro(__CMODEL_MEDIUM__)  {1}
set beam::compiler::c::predefined_macro(__DBL_DECIMAL_DIG__) {17}
set beam::compiler::c::predefined_macro(__DBL_DENORM_MIN__) {((double)4.94065645841246544176568792868221e-324L)}
set beam::compiler::c::predefined_macro(__DBL_DIG__)        {15}
set beam::compiler::c::predefined_macro(__DBL_EPSILON__)    {((double)2.22044604925031308084726333618164e-16L)}
set beam::compiler::c::predefined_macro(__DBL_HAS_DENORM__) {1}
set beam::compiler::c::predefined_macro(__DBL_HAS_INFINITY__) {1}
set beam::compiler::c::predefined_macro(__DBL_HAS_QUIET_NAN__) {1}
set beam::compiler::c::predefined_macro(__DBL_MANT_DIG__)   {53}
set beam::compiler::c::predefined_macro(__DBL_MAX_10_EXP__) {308}
set beam::compiler::c::predefined_macro(__DBL_MAX_EXP__)    {1024}
set beam::compiler::c::predefined_macro(__DBL_MAX__)        {((double)1.79769313486231570814527423731704e+308L)}
set beam::compiler::c::predefined_macro(__DBL_MIN_10_EXP__) {(-307)}
set beam::compiler::c::predefined_macro(__DBL_MIN_EXP__)    {(-1021)}
set beam::compiler::c::predefined_macro(__DBL_MIN__)        {((double)2.22507385850720138309023271733240e-308L)}
set beam::compiler::c::predefined_macro(__DEC128_EPSILON__) {1E-33DL}
set beam::compiler::c::predefined_macro(__DEC128_MANT_DIG__) {34}
set beam::compiler::c::predefined_macro(__DEC128_MAX_EXP__) {6145}
set beam::compiler::c::predefined_macro(__DEC128_MAX__)     {9.999999999999999999999999999999999E6144DL}
set beam::compiler::c::predefined_macro(__DEC128_MIN_EXP__) {(-6142)}
set beam::compiler::c::predefined_macro(__DEC128_MIN__)     {1E-6143DL}
set beam::compiler::c::predefined_macro(__DEC128_SUBNORMAL_MIN__) {0.000000000000000000000000000000001E-6143DL}
set beam::compiler::c::predefined_macro(__DEC32_EPSILON__)  {1E-6DF}
set beam::compiler::c::predefined_macro(__DEC32_MANT_DIG__) {7}
set beam::compiler::c::predefined_macro(__DEC32_MAX_EXP__)  {97}
set beam::compiler::c::predefined_macro(__DEC32_MAX__)      {9.999999E96DF}
set beam::compiler::c::predefined_macro(__DEC32_MIN_EXP__)  {(-94)}
set beam::compiler::c::predefined_macro(__DEC32_MIN__)      {1E-95DF}
set beam::compiler::c::predefined_macro(__DEC32_SUBNORMAL_MIN__) {0.000001E-95DF}
set beam::compiler::c::predefined_macro(__DEC64_EPSILON__)  {1E-15DD}
set beam::compiler::c::predefined_macro(__DEC64_MANT_DIG__) {16}
set beam::compiler::c::predefined_macro(__DEC64_MAX_EXP__)  {385}
set beam::compiler::c::predefined_macro(__DEC64_MAX__)      {9.999999999999999E384DD}
set beam::compiler::c::predefined_macro(__DEC64_MIN_EXP__)  {(-382)}
set beam::compiler::c::predefined_macro(__DEC64_MIN__)      {1E-383DD}
set beam::compiler::c::predefined_macro(__DEC64_SUBNORMAL_MIN__) {0.000000000000001E-383DD}
set beam::compiler::c::predefined_macro(__DECIMAL_DIG__)    {33}
set beam::compiler::c::predefined_macro(__DEC_EVAL_METHOD__) {2}
set beam::compiler::c::predefined_macro(__ELF__)            {1}
set beam::compiler::c::predefined_macro(__FINITE_MATH_ONLY__) {0}
set beam::compiler::c::predefined_macro(__FLOAT_WORD_ORDER__) {__ORDER_BIG_ENDIAN__}
set beam::compiler::c::predefined_macro(__FLT_DECIMAL_DIG__) {9}
set beam::compiler::c::predefined_macro(__FLT_DENORM_MIN__) {1.40129846432481707092372958328992e-45F}
set beam::compiler::c::predefined_macro(__FLT_DIG__)        {6}
set beam::compiler::c::predefined_macro(__FLT_EPSILON__)    {1.19209289550781250000000000000000e-7F}
set beam::compiler::c::predefined_macro(__FLT_EVAL_METHOD__) {0}
set beam::compiler::c::predefined_macro(__FLT_HAS_DENORM__) {1}
set beam::compiler::c::predefined_macro(__FLT_HAS_INFINITY__) {1}
set beam::compiler::c::predefined_macro(__FLT_HAS_QUIET_NAN__) {1}
set beam::compiler::c::predefined_macro(__FLT_MANT_DIG__)   {24}
set beam::compiler::c::predefined_macro(__FLT_MAX_10_EXP__) {38}
set beam::compiler::c::predefined_macro(__FLT_MAX_EXP__)    {128}
set beam::compiler::c::predefined_macro(__FLT_MAX__)        {3.40282346638528859811704183484517e+38F}
set beam::compiler::c::predefined_macro(__FLT_MIN_10_EXP__) {(-37)}
set beam::compiler::c::predefined_macro(__FLT_MIN_EXP__)    {(-125)}
set beam::compiler::c::predefined_macro(__FLT_MIN__)        {1.17549435082228750796873653722225e-38F}
set beam::compiler::c::predefined_macro(__FLT_RADIX__)      {2}
set beam::compiler::c::predefined_macro(__FP_FAST_FMA)      {1}
set beam::compiler::c::predefined_macro(__FP_FAST_FMAF)     {1}
set beam::compiler::c::predefined_macro(__GCC_ATOMIC_BOOL_LOCK_FREE) {2}
set beam::compiler::c::predefined_macro(__GCC_ATOMIC_CHAR16_T_LOCK_FREE) {2}
set beam::compiler::c::predefined_macro(__GCC_ATOMIC_CHAR32_T_LOCK_FREE) {2}
set beam::compiler::c::predefined_macro(__GCC_ATOMIC_CHAR_LOCK_FREE) {2}
set beam::compiler::c::predefined_macro(__GCC_ATOMIC_INT_LOCK_FREE) {2}
set beam::compiler::c::predefined_macro(__GCC_ATOMIC_LLONG_LOCK_FREE) {2}
set beam::compiler::c::predefined_macro(__GCC_ATOMIC_LONG_LOCK_FREE) {2}
set beam::compiler::c::predefined_macro(__GCC_ATOMIC_POINTER_LOCK_FREE) {2}
set beam::compiler::c::predefined_macro(__GCC_ATOMIC_SHORT_LOCK_FREE) {2}
set beam::compiler::c::predefined_macro(__GCC_ATOMIC_TEST_AND_SET_TRUEVAL) {1}
set beam::compiler::c::predefined_macro(__GCC_ATOMIC_WCHAR_T_LOCK_FREE) {2}
set beam::compiler::c::predefined_macro(__GCC_HAVE_SYNC_COMPARE_AND_SWAP_1) {1}
set beam::compiler::c::predefined_macro(__GCC_HAVE_SYNC_COMPARE_AND_SWAP_2) {1}
set beam::compiler::c::predefined_macro(__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4) {1}
set beam::compiler::c::predefined_macro(__GCC_HAVE_SYNC_COMPARE_AND_SWAP_8) {1}
set beam::compiler::c::predefined_macro(__GNUC_GNU_INLINE__) {1}
set beam::compiler::c::predefined_macro(__GNUC_MINOR__)     {7}
set beam::compiler::c::predefined_macro(__GNUC_PATCHLEVEL__) {2}
set beam::compiler::c::predefined_macro(__GNUC__)           {4}
set beam::compiler::c::predefined_macro(__GXX_ABI_VERSION)  {1002}
set beam::compiler::c::predefined_macro(__HAVE_BSWAP__)     {1}
set beam::compiler::c::predefined_macro(__INT16_C)          {(c) c}
set beam::compiler::c::predefined_macro(__INT16_MAX__)      {32767}
set beam::compiler::c::predefined_macro(__INT16_TYPE__)     {short int}
set beam::compiler::c::predefined_macro(__INT32_C)          {(c) c}
set beam::compiler::c::predefined_macro(__INT32_MAX__)      {2147483647}
set beam::compiler::c::predefined_macro(__INT32_TYPE__)     {int}
set beam::compiler::c::predefined_macro(__INT64_C)          {(c) c ## L}
set beam::compiler::c::predefined_macro(__INT64_MAX__)      {9223372036854775807L}
set beam::compiler::c::predefined_macro(__INT64_TYPE__)     {long int}
set beam::compiler::c::predefined_macro(__INT8_C)           {(c) c}
set beam::compiler::c::predefined_macro(__INT8_MAX__)       {127}
set beam::compiler::c::predefined_macro(__INT8_TYPE__)      {signed char}
set beam::compiler::c::predefined_macro(__INTMAX_C)         {(c) c ## L}
set beam::compiler::c::predefined_macro(__INTMAX_MAX__)     {9223372036854775807L}
set beam::compiler::c::predefined_macro(__INTMAX_TYPE__)    {long int}
set beam::compiler::c::predefined_macro(__INTPTR_MAX__)     {9223372036854775807L}
set beam::compiler::c::predefined_macro(__INTPTR_TYPE__)    {long int}
set beam::compiler::c::predefined_macro(__INT_FAST16_MAX__) {9223372036854775807L}
set beam::compiler::c::predefined_macro(__INT_FAST16_TYPE__) {long int}
set beam::compiler::c::predefined_macro(__INT_FAST32_MAX__) {9223372036854775807L}
set beam::compiler::c::predefined_macro(__INT_FAST32_TYPE__) {long int}
set beam::compiler::c::predefined_macro(__INT_FAST64_MAX__) {9223372036854775807L}
set beam::compiler::c::predefined_macro(__INT_FAST64_TYPE__) {long int}
set beam::compiler::c::predefined_macro(__INT_FAST8_MAX__)  {127}
set beam::compiler::c::predefined_macro(__INT_FAST8_TYPE__) {signed char}
set beam::compiler::c::predefined_macro(__INT_LEAST16_MAX__) {32767}
set beam::compiler::c::predefined_macro(__INT_LEAST16_TYPE__) {short int}
set beam::compiler::c::predefined_macro(__INT_LEAST32_MAX__) {2147483647}
set beam::compiler::c::predefined_macro(__INT_LEAST32_TYPE__) {int}
set beam::compiler::c::predefined_macro(__INT_LEAST64_MAX__) {9223372036854775807L}
set beam::compiler::c::predefined_macro(__INT_LEAST64_TYPE__) {long int}
set beam::compiler::c::predefined_macro(__INT_LEAST8_MAX__) {127}
set beam::compiler::c::predefined_macro(__INT_LEAST8_TYPE__) {signed char}
set beam::compiler::c::predefined_macro(__INT_MAX__)        {2147483647}
set beam::compiler::c::predefined_macro(__LDBL_DENORM_MIN__) {4.94065645841246544176568792868221e-324L}
set beam::compiler::c::predefined_macro(__LDBL_DIG__)       {31}
set beam::compiler::c::predefined_macro(__LDBL_EPSILON__)   {4.94065645841246544176568792868221e-324L}
set beam::compiler::c::predefined_macro(__LDBL_HAS_DENORM__) {1}
set beam::compiler::c::predefined_macro(__LDBL_HAS_INFINITY__) {1}
set beam::compiler::c::predefined_macro(__LDBL_HAS_QUIET_NAN__) {1}
set beam::compiler::c::predefined_macro(__LDBL_MANT_DIG__)  {106}
set beam::compiler::c::predefined_macro(__LDBL_MAX_10_EXP__) {308}
set beam::compiler::c::predefined_macro(__LDBL_MAX_EXP__)   {1024}
set beam::compiler::c::predefined_macro(__LDBL_MAX__)       {1.79769313486231580793728971405301e+308L}
set beam::compiler::c::predefined_macro(__LDBL_MIN_10_EXP__) {(-291)}
set beam::compiler::c::predefined_macro(__LDBL_MIN_EXP__)   {(-968)}
set beam::compiler::c::predefined_macro(__LDBL_MIN__)       {2.00416836000897277799610805135016e-292L}
set beam::compiler::c::predefined_macro(__LONGDOUBLE128)    {1}
set beam::compiler::c::predefined_macro(__LONG_DOUBLE_128__) {1}
set beam::compiler::c::predefined_macro(__LONG_LONG_MAX__)  {9223372036854775807LL}
set beam::compiler::c::predefined_macro(__LONG_MAX__)       {9223372036854775807L}
set beam::compiler::c::predefined_macro(__LP64__)           {1}
set beam::compiler::c::predefined_macro(__NO_INLINE__)      {1}
set beam::compiler::c::predefined_macro(__ORDER_BIG_ENDIAN__) {4321}
set beam::compiler::c::predefined_macro(__ORDER_LITTLE_ENDIAN__) {1234}
set beam::compiler::c::predefined_macro(__ORDER_PDP_ENDIAN__) {3412}
set beam::compiler::c::predefined_macro(__PPC64__)          {1}
set beam::compiler::c::predefined_macro(__PPC__)            {1}
set beam::compiler::c::predefined_macro(__PRAGMA_REDEFINE_EXTNAME) {1}
set beam::compiler::c::predefined_macro(__PTRDIFF_MAX__)    {9223372036854775807L}
set beam::compiler::c::predefined_macro(__PTRDIFF_TYPE__)   {long int}
set beam::compiler::c::predefined_macro(__RECIPF__)         {1}
set beam::compiler::c::predefined_macro(__REGISTER_PREFIX__) {}
set beam::compiler::c::predefined_macro(__RSQRTE__)         {1}
set beam::compiler::c::predefined_macro(__SCHAR_MAX__)      {127}
set beam::compiler::c::predefined_macro(__SHRT_MAX__)       {32767}
set beam::compiler::c::predefined_macro(__SIG_ATOMIC_MAX__) {2147483647}
set beam::compiler::c::predefined_macro(__SIG_ATOMIC_MIN__) {(-__SIG_ATOMIC_MAX__ - 1)}
set beam::compiler::c::predefined_macro(__SIG_ATOMIC_TYPE__) {int}
set beam::compiler::c::predefined_macro(__SIZEOF_DOUBLE__)  {8}
set beam::compiler::c::predefined_macro(__SIZEOF_FLOAT__)   {4}
set beam::compiler::c::predefined_macro(__SIZEOF_INT128__)  {16}
set beam::compiler::c::predefined_macro(__SIZEOF_INT__)     {4}
set beam::compiler::c::predefined_macro(__SIZEOF_LONG_DOUBLE__) {16}
set beam::compiler::c::predefined_macro(__SIZEOF_LONG_LONG__) {8}
set beam::compiler::c::predefined_macro(__SIZEOF_LONG__)    {8}
set beam::compiler::c::predefined_macro(__SIZEOF_POINTER__) {8}
set beam::compiler::c::predefined_macro(__SIZEOF_PTRDIFF_T__) {8}
set beam::compiler::c::predefined_macro(__SIZEOF_SHORT__)   {2}
set beam::compiler::c::predefined_macro(__SIZEOF_SIZE_T__)  {8}
set beam::compiler::c::predefined_macro(__SIZEOF_WCHAR_T__) {4}
set beam::compiler::c::predefined_macro(__SIZEOF_WINT_T__)  {4}
set beam::compiler::c::predefined_macro(__SIZE_MAX__)       {18446744073709551615UL}
set beam::compiler::c::predefined_macro(__SIZE_TYPE__)      {long unsigned int}
set beam::compiler::c::predefined_macro(__UINT16_C)         {(c) c}
set beam::compiler::c::predefined_macro(__UINT16_MAX__)     {65535}
set beam::compiler::c::predefined_macro(__UINT16_TYPE__)    {short unsigned int}
set beam::compiler::c::predefined_macro(__UINT32_C)         {(c) c ## U}
set beam::compiler::c::predefined_macro(__UINT32_MAX__)     {4294967295U}
set beam::compiler::c::predefined_macro(__UINT32_TYPE__)    {unsigned int}
set beam::compiler::c::predefined_macro(__UINT64_C)         {(c) c ## UL}
set beam::compiler::c::predefined_macro(__UINT64_MAX__)     {18446744073709551615UL}
set beam::compiler::c::predefined_macro(__UINT64_TYPE__)    {long unsigned int}
set beam::compiler::c::predefined_macro(__UINT8_C)          {(c) c}
set beam::compiler::c::predefined_macro(__UINT8_MAX__)      {255}
set beam::compiler::c::predefined_macro(__UINT8_TYPE__)     {unsigned char}
set beam::compiler::c::predefined_macro(__UINTMAX_C)        {(c) c ## UL}
set beam::compiler::c::predefined_macro(__UINTMAX_MAX__)    {18446744073709551615UL}
set beam::compiler::c::predefined_macro(__UINTMAX_TYPE__)   {long unsigned int}
set beam::compiler::c::predefined_macro(__UINTPTR_MAX__)    {18446744073709551615UL}
set beam::compiler::c::predefined_macro(__UINTPTR_TYPE__)   {long unsigned int}
set beam::compiler::c::predefined_macro(__UINT_FAST16_MAX__) {18446744073709551615UL}
set beam::compiler::c::predefined_macro(__UINT_FAST16_TYPE__) {long unsigned int}
set beam::compiler::c::predefined_macro(__UINT_FAST32_MAX__) {18446744073709551615UL}
set beam::compiler::c::predefined_macro(__UINT_FAST32_TYPE__) {long unsigned int}
set beam::compiler::c::predefined_macro(__UINT_FAST64_MAX__) {18446744073709551615UL}
set beam::compiler::c::predefined_macro(__UINT_FAST64_TYPE__) {long unsigned int}
set beam::compiler::c::predefined_macro(__UINT_FAST8_MAX__) {255}
set beam::compiler::c::predefined_macro(__UINT_FAST8_TYPE__) {unsigned char}
set beam::compiler::c::predefined_macro(__UINT_LEAST16_MAX__) {65535}
set beam::compiler::c::predefined_macro(__UINT_LEAST16_TYPE__) {short unsigned int}
set beam::compiler::c::predefined_macro(__UINT_LEAST32_MAX__) {4294967295U}
set beam::compiler::c::predefined_macro(__UINT_LEAST32_TYPE__) {unsigned int}
set beam::compiler::c::predefined_macro(__UINT_LEAST64_MAX__) {18446744073709551615UL}
set beam::compiler::c::predefined_macro(__UINT_LEAST64_TYPE__) {long unsigned int}
set beam::compiler::c::predefined_macro(__UINT_LEAST8_MAX__) {255}
set beam::compiler::c::predefined_macro(__UINT_LEAST8_TYPE__) {unsigned char}
set beam::compiler::c::predefined_macro(__USER_LABEL_PREFIX__) {}
set beam::compiler::c::predefined_macro(__VERSION__)        {"4.7.2"}
set beam::compiler::c::predefined_macro(__WCHAR_MAX__)      {2147483647}
set beam::compiler::c::predefined_macro(__WCHAR_MIN__)      {(-__WCHAR_MAX__ - 1)}
set beam::compiler::c::predefined_macro(__WCHAR_TYPE__)     {int}
set beam::compiler::c::predefined_macro(__WINT_MAX__)       {4294967295U}
set beam::compiler::c::predefined_macro(__WINT_MIN__)       {0U}
set beam::compiler::c::predefined_macro(__WINT_TYPE__)      {unsigned int}
set beam::compiler::c::predefined_macro(__bool)             {__attribute__((altivec(bool__))) unsigned}
set beam::compiler::c::predefined_macro(__builtin_vsx_vperm) {__builtin_vec_perm}
set beam::compiler::c::predefined_macro(__builtin_vsx_xvmaddadp) {__builtin_vsx_xvmadddp}
set beam::compiler::c::predefined_macro(__builtin_vsx_xvmaddasp) {__builtin_vsx_xvmaddsp}
set beam::compiler::c::predefined_macro(__builtin_vsx_xvmaddmdp) {__builtin_vsx_xvmadddp}
set beam::compiler::c::predefined_macro(__builtin_vsx_xvmaddmsp) {__builtin_vsx_xvmaddsp}
set beam::compiler::c::predefined_macro(__builtin_vsx_xvmsubadp) {__builtin_vsx_xvmsubdp}
set beam::compiler::c::predefined_macro(__builtin_vsx_xvmsubasp) {__builtin_vsx_xvmsubsp}
set beam::compiler::c::predefined_macro(__builtin_vsx_xvmsubmdp) {__builtin_vsx_xvmsubdp}
set beam::compiler::c::predefined_macro(__builtin_vsx_xvmsubmsp) {__builtin_vsx_xvmsubsp}
set beam::compiler::c::predefined_macro(__builtin_vsx_xvnmaddadp) {__builtin_vsx_xvnmadddp}
set beam::compiler::c::predefined_macro(__builtin_vsx_xvnmaddasp) {__builtin_vsx_xvnmaddsp}
set beam::compiler::c::predefined_macro(__builtin_vsx_xvnmaddmdp) {__builtin_vsx_xvnmadddp}
set beam::compiler::c::predefined_macro(__builtin_vsx_xvnmaddmsp) {__builtin_vsx_xvnmaddsp}
set beam::compiler::c::predefined_macro(__builtin_vsx_xvnmsubadp) {__builtin_vsx_xvnmsubdp}
set beam::compiler::c::predefined_macro(__builtin_vsx_xvnmsubasp) {__builtin_vsx_xvnmsubsp}
set beam::compiler::c::predefined_macro(__builtin_vsx_xvnmsubmdp) {__builtin_vsx_xvnmsubdp}
set beam::compiler::c::predefined_macro(__builtin_vsx_xvnmsubmsp) {__builtin_vsx_xvnmsubsp}
set beam::compiler::c::predefined_macro(__builtin_vsx_xxland) {__builtin_vec_and}
set beam::compiler::c::predefined_macro(__builtin_vsx_xxlandc) {__builtin_vec_andc}
set beam::compiler::c::predefined_macro(__builtin_vsx_xxlnor) {__builtin_vec_nor}
set beam::compiler::c::predefined_macro(__builtin_vsx_xxlor) {__builtin_vec_or}
set beam::compiler::c::predefined_macro(__builtin_vsx_xxlxor) {__builtin_vec_xor}
set beam::compiler::c::predefined_macro(__builtin_vsx_xxsel) {__builtin_vec_sel}
set beam::compiler::c::predefined_macro(__gnu_linux__)      {1}
set beam::compiler::c::predefined_macro(__linux)            {1}
set beam::compiler::c::predefined_macro(__linux__)          {1}
set beam::compiler::c::predefined_macro(__pixel)            {__attribute__((altivec(pixel__))) unsigned short}
set beam::compiler::c::predefined_macro(__powerpc64__)      {1}
set beam::compiler::c::predefined_macro(__powerpc__)        {1}
set beam::compiler::c::predefined_macro(__unix)             {1}
set beam::compiler::c::predefined_macro(__unix__)           {1}
set beam::compiler::c::predefined_macro(__vector)           {__attribute__((altivec(vector__)))}
set beam::compiler::c::predefined_macro(bool)               {bool}
set beam::compiler::c::predefined_macro(linux)              {1}
set beam::compiler::c::predefined_macro(pixel)              {pixel}
set beam::compiler::c::predefined_macro(unix)               {1}
set beam::compiler::c::predefined_macro(vector)             {vector}
set beam::compiler::c::predefined_macro(__builtin_expect(_x,_y)) {(_x)}


### You can also suppress the standard EDG predefined macros
### like __STDC__ if you set this pattern. By default,
### the pattern is "*", which allows all EDG predefined
### macros to get defined. Setting this to something
### like "* - __STDC__" would suppress the __STDC__
### macro from being defined by default. This does
### not affect any predefined macros set up in this
### file; it only affects the basic EDG predefined macros.
  
# set beam::compiler::c::standard_predefined_macros "*"

set beam::compiler::c::standard_predefined_macros "* -  __STDC_VERSION__"

  
############################################################
# Section 5: Miscellaneous options
############################################################

### The extern variable is an associated array that maps
### unknown extern "string" values to known ones. For example,
### to force BEAM to treat
###
###   extern "builtin" void func();
###
### as
###
###   extern "C" void func();
###
### you should set this option:
###
###   set beam::compiler::c::extern(builtin) "C"
###
### There is no limit to the number of strings that you can
### map to the built-in strings of "C" or "C++".
  


### Some compilers define macro-like symbols that are being replaced
### with the name of the function they appear in. Below are the symbols
### EDG recognizes. Set to 1, if the symbol is replaced with a character
### string (as opposed to a variable). If in doubt define it as "1"
### which is more flexible.
###
### set beam::compiler::c::function_name_is_string_literal(__PRETTY_FUNCTION__) 1
### set beam::compiler::c::function_name_is_string_literal(__FUNCTION__) 1
### set beam::compiler::c::function_name_is_string_literal(__FUNCDNAME__) 1
### set beam::compiler::c::function_name_is_string_literal(__func__)     1



