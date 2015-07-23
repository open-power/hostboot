#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: hwpf/fapi2/tools/parseErrorInfo.pl $
#
# IBM CONFIDENTIAL
#
# EKB Project
#
# COPYRIGHT 2015
# [+] International Business Machines Corp.
#
#
# The source code for this program is not published or otherwise
# divested of its trade secrets, irrespective of what has been
# deposited with the U.S. Copyright Office.
#
# IBM_PROLOG_END_TAG
#
# @file   parseErrorInfo.pl
# @brief  This perl script will parse HWP Error XML files and generate required
#         FAPI code to create and error log and add FFDC to the error.
#
# *HWP HWP Owner: N/A
# *HWP FW Owner: Thi Tran <thi@us.ibm.com>
# *HWP Team: N/A
# *HWP Level: 1
# *HWP Consumed by: HB
#
# Usage:
# parseErrorInfo.pl <output dir> <filename1> <filename2> ...

use strict;

#------------------------------------------------------------------------------
# Set PREFERRED_PARSER to XML::Parser. Otherwise it uses XML::SAX which contains
# bugs that result in XML parse errors that can be fixed by adjusting white-
# space (i.e. parse errors that do not make sense).
#------------------------------------------------------------------------------
$XML::Simple::PREFERRED_PARSER = 'XML::Parser';

#------------------------------------------------------------------------------
# Specify perl modules to use
#------------------------------------------------------------------------------
use Digest::MD5 qw(md5_hex);
use XML::Simple;
my $xml = new XML::Simple (KeyAttr=>[]);

# Uncomment to enable debug output
use Data::Dumper;
use Getopt::Long;

my $target_ffdc_type = "fapi2::Target<T>";
my $buffer_ffdc_type = "fapi2::buffer";
my $variable_buffer_ffdc_type = "fapi2::variable_buffer";
my $ffdc_type = "fapi2::ffdc_t";

# We want to keep the signatures for the ffdc gathering hwp so that
# we can create members of the proper types for the ffdc classes.
my %signatures = ("proc_extract_pore_halt_ffdc" => ["por_base_state",
                                                    "por_halt_type_t",
                                                    "por_ffdc_offset_t"],
                  "hwpTestFfdc1" => [$target_ffdc_type],
                  "proc_extract_pore_base_ffdc" => ["por_base_state", "por_sbe_base_state"],
                  "proc_tp_collect_dbg_data" => [$target_ffdc_type],
    );

# There are some names used in the XML files which exist in either
# c++ keywords (case, for example) or macros (DOMAIN). The one's which
# cause problems and need to be changed are here.
#
# DOMAIN is defined to 1 in math.h
my %mangle_names = ("DOMAIN" => "FAPI2_DOMAIN");

# A list of deprecated elements. These will report messages to the
# user, and not define anything. They have not been found to be used,
# but that doesn't mean they're not ...
my %deprecated = ("RC_PROCPM_PMCINIT_TIMEOUT" => "CHIP_IN_ERROR is defined as a callout procedure");

#------------------------------------------------------------------------------
# Print Command Line Help
#------------------------------------------------------------------------------
my $arg_empty_ffdc = undef;
my $arg_output_dir = undef;
my $arg_use_variable_buffers = undef;

# Get the options from the command line - the rest of @ARGV will
# be filenames
GetOptions("empty-ffdc-classes" => \$arg_empty_ffdc,
           "output-dir=s" => \$arg_output_dir,
           "use-variable-buffers" => \$arg_use_variable_buffers);

my $numArgs = $#ARGV + 1;
if (($numArgs < 1) || ($arg_output_dir eq undef))
{
    print ("Usage: parseErrorInfo.pl [--empty-ffdc-classes] [--use-variable-buffers] --output-dir=<output dir> <filename1> <filename2> ...\n");
    print ("  This perl script will parse HWP Error XML files and creates\n");
    print ("  the following files:\n");
    print ("  - hwp_return_codes.H. HwpReturnCode enumeration (HWP generated errors)\n");
    print ("  - hwp_error_info.H.   Error information (used by FAPI_SET_HWP_ERROR\n");
    print ("                        when a HWP generates an error)\n");
    print ("  - collect_reg_ffdc.H. Function to collect register FFDC\n");
    print ("  - set_sbe_error.H.    Macro to create an SBE error\n");
    print ("  The --empty-ffdc-classes option is for platforms which don't collect ffdc.\n");
    exit(1);
}

#------------------------------------------------------------------------------
# Hashes containing error names/enum-values
#------------------------------------------------------------------------------
my %errNameToValueHash;
my %errValuePresentHash;

#------------------------------------------------------------------------------
# Hashes containing ffdc names/enum-values
#------------------------------------------------------------------------------
my %ffdcNameToValueHash;
my %ffdcValuePresentHash;

#------------------------------------------------------------------------------
# Subroutine that checks if an entry exists in an array. If it doesn't exist
# then it is added. The index of the entry within the array is returned
#------------------------------------------------------------------------------
sub addEntryToArray
{
    my ($arrayref, $entry ) = @_;

    my $match = 0;
    my $index = 0;

    foreach my $element (@$arrayref)
    {
        if ($element eq $entry)
        {
            $match = 1;
            last;
        }
        else
        {
            $index++;
        }
    }

    if (!($match))
    {
        push(@$arrayref, $entry);
    }

    return $index;
}

#------------------------------------------------------------------------------
# Subroutine that figures out an error enum value from an error name and stores
# it in global hashes
#------------------------------------------------------------------------------
sub setErrorEnumValue
{
    my $name = $_[0];

    #--------------------------------------------------------------------------
    # Check that the error name is not a duplicate
    #--------------------------------------------------------------------------
    if (exists($errNameToValueHash{$name}))
    {
        # Two different errors with the same name!
        print ("fapiParseErrorInfo.pl ERROR. Duplicate error name ", $name, "\n");
        exit(1);
    }

    #--------------------------------------------------------------------------
    # Figure out the error enum-value. This is a hash value generated from
    # the error name. A hash is used for Cronus so that if a HWP is not
    # recompiled against a new eCMD/Cronus version where the errors have
    # changed then there will not be a mismatch in error values.
    # This is a 24bit hash value because FAPI has a requirement that the
    # top byte of the 32 bit error value be zero to store flags indicating
    # the creator of the error
    #--------------------------------------------------------------------------
    my $errHash128Bit = md5_hex($name);
    my $errHash24Bit = substr($errHash128Bit, 0, 6);

    #--------------------------------------------------------------------------
    # Check that the error enum-value is not a duplicate
    #--------------------------------------------------------------------------
    if (exists($errValuePresentHash{$errHash24Bit}))
    {
        # Two different errors generate the same hash-value!
        print ("fapiParseAttributeInfo.pl ERROR. Duplicate error hash value\n");
        exit(1);
    }

    #--------------------------------------------------------------------------
    # Update the hashes with the error name and ID
    #--------------------------------------------------------------------------
    $errValuePresentHash{$errHash24Bit} = 1;
    $errNameToValueHash{$name} = $errHash24Bit;
}

#------------------------------------------------------------------------------
# Subroutine that figures out an FFDC ID value from an FFDC name and stores it
# in global hashes for use when creating the enumeration of FFDC IDs
#------------------------------------------------------------------------------
sub setFfdcIdValue
{
    my $name = $_[0];

    #--------------------------------------------------------------------------
    # Check that the FFDC name is not a duplicate
    #--------------------------------------------------------------------------
    if (exists($ffdcNameToValueHash{$name}))
    {
        # Two different FFDCs with the same name!
        print ("fapiParseErrorInfo.pl ERROR. Duplicate FFDC name ", $name, "\n");
        exit(1);
    }

    #--------------------------------------------------------------------------
    # Figure out the FFDC enum-value. This is a hash value generated from
    # the FFDC name.
    #--------------------------------------------------------------------------
    my $ffdcHash128Bit = md5_hex($name);
    my $ffdcHash32Bit = substr($ffdcHash128Bit, 0, 8);

    #--------------------------------------------------------------------------
    # Check that the error enum-value is not a duplicate
    #--------------------------------------------------------------------------
    if (exists($ffdcValuePresentHash{$ffdcHash32Bit}))
    {
        # Two different FFDCs generate the same hash-value!
        print ("fapiParseAttributeInfo.pl ERROR. Duplicate FFDC hash value\n");
        exit(1);
    }

    #--------------------------------------------------------------------------
    # Update the hashes with the error name and ID
    #--------------------------------------------------------------------------
    $ffdcValuePresentHash{$ffdcHash32Bit} = 1;
    $ffdcNameToValueHash{$name} = $ffdcHash32Bit;
}

#------------------------------------------------------------------------------
# Subroutine to create ffdc methods
#------------------------------------------------------------------------------
sub addFfdcMethod
{
    my $methods = shift;
    my $ffdc_uc = shift;
    my $class_name = shift;
    my $type = shift;

    # Remove the leading *_
    $class_name = (split (/_/, $class_name, 2))[1];

    # If we didn't get a type passed in, this element will get an ffdc_t pair.
    $type = $ffdc_type if ($type eq undef);

    # Mangle the uppercase name if needed
    $ffdc_uc = $mangle_names{$ffdc_uc} if ($mangle_names{$ffdc_uc} ne undef);

    my $key = $ffdc_uc.$type;
    my $key_target = $ffdc_uc.$target_ffdc_type;
    my $key_ffdc = $ffdc_uc.$ffdc_type;

    # Check to see if this element already has been recorded with this
    # type or a target type. Note the effect we're shooting for here is
    # to define the member if it's not been defined before *or* it's
    # changing from an ffdc_t to a target due to other information in the xml
    return if ($methods->{$key}{type} eq $type);
    return if ($methods->{$key_target}{type} eq $target_ffdc_type);

    # Just leave if this is a variable_buffer ans we're not supporting that.
    return if (($type eq $variable_buffer_ffdc_type) && ($arg_use_variable_buffers eq undef));

    # Set the proper type, and clear out any previous members/methods if
    # we're going from an ffdc_t to a target.
    $methods->{$key}{type} = $type;
    delete $methods->{$key_ffdc} if ($type eq $target_ffdc_type);

    my $method = "";
    my $method_body = "";

    # If we're generating empty classes, not using an argument name will avoid the unused parameter warnings
    my $param = ($arg_empty_ffdc eq undef) ? "i_value" : "";

    if ($type eq $ffdc_type)
    {
        $method =      "\n    template< typename T >\n";
        $method  .=      "    inline $class_name& set_$ffdc_uc(const T& $param)\n";
        $method_body  =  "    {$ffdc_uc.ptr() = &i_value; $ffdc_uc.size() = fapi2::getErrorInfoFfdcSize(i_value); return *this;}\n\n";

        $methods->{$key}{member} = "$ffdc_type $ffdc_uc;\n    ";
    }

    elsif ($type eq $buffer_ffdc_type)
    {
        # Two methods - one for integral buffers and one for variable_buffers
        $method =      "\n    template< typename T >\n";
        $method  .=      "    inline $class_name& set_$ffdc_uc(const fapi2::buffer<T>& $param)\n";
        $method_body  =  "    {$ffdc_uc.ptr() = &i_value(); $ffdc_uc.size() = i_value.template getLength<uint8_t>(); return *this;}\n\n";

        $methods->{$key}{member} = "$ffdc_type $ffdc_uc;\n    ";
    }

    elsif ($type eq $variable_buffer_ffdc_type)
    {
        $method       =  "\n    inline $class_name& set_$ffdc_uc(const fapi2::variable_buffer& $param)\n";
        $method_body  =    "    {$ffdc_uc.ptr() = &i_value(); $ffdc_uc.size() = i_value.template getLength<uint8_t>(); return *this;}\n\n";

        # No need to add the member here, it was added with fapi2::buffer. And we can't have variable
        # buffer support with out integral buffer support (can we?)
    }

    elsif ($type eq $target_ffdc_type)
    {
        $method =      "\n    template< TargetType T >\n";
        $method .=       "    inline $class_name& set_$ffdc_uc(const $type& $param)\n";
        $method_body .=  "    {$ffdc_uc.ptr() = &i_value; $ffdc_uc.size() = fapi2::getErrorInfoFfdcSize(i_value); return *this;}\n\n";

        $methods->{$key}{member} = "$ffdc_type $ffdc_uc;\n    ";
    }

    else
    {
        print ("ffdc type $type is unknown");
        exit(1);
    }

    $method .= ($arg_empty_ffdc eq undef) ? $method_body : "    {return *this;}\n\n";
    $methods->{$key}{method} = $method;
}

#------------------------------------------------------------------------------
# Open output files for writing
#------------------------------------------------------------------------------
my $rcFile = $arg_output_dir;
$rcFile .= "/";
$rcFile .= "hwp_return_codes.H";
open(RCFILE, ">", $rcFile);

my $eiFile = $arg_output_dir;
$eiFile .= "/";
$eiFile .= "hwp_error_info.H";
open(EIFILE, ">", $eiFile);

my $ecFile = $arg_output_dir;
$ecFile .= "/";
$ecFile .= "hwp_ffdc_classes.H";
open(ECFILE, ">", $ecFile);

my $crFile = $arg_output_dir;
$crFile .= "/";
$crFile .= "collect_reg_ffdc.H";
open(CRFILE, ">", $crFile);

my $sbFile = $arg_output_dir;
$sbFile .= "/";
$sbFile .= "set_sbe_error.H";
open(SBFILE, ">", $sbFile);

#------------------------------------------------------------------------------
# Print start of file information to hwp_error_info.H
#------------------------------------------------------------------------------
print EIFILE "// hwp_error_info.H\n";
print EIFILE "// This file is generated by the perl script parseErrorInfo.pl\n\n";
print EIFILE "#ifndef FAPI2_HWPERRORINFO_H_\n";
print EIFILE "#define FAPI2_HWPERRORINFO_H_\n\n";
print EIFILE "#include <target.H>\n";
print EIFILE "#include <plat_trace.H>\n";
print EIFILE "#include <hwp_return_codes.H>\n";
print EIFILE "#include <set_sbe_error.H>\n";
print EIFILE "/**\n";
print EIFILE " * \@brief Error Information macros and HwpFfdcId enumeration\n";
print EIFILE " *\/\n";

#------------------------------------------------------------------------------
# Print start of file information to hwp_ffdc_classes.H
#------------------------------------------------------------------------------
print ECFILE "// hwp_ffdc_classes.H\n";
print ECFILE "// This file is generated by the perl script parseErrorInfo.pl\n\n";
print ECFILE "#ifndef FAPI2_HWP_FFDC_CLASSES_H_\n";
print ECFILE "#define FAPI2_HWP_FFDC_CLASSES_H_\n\n";
print ECFILE "#include <ffdc.H>\n";
print ECFILE "#include <buffer.H>\n";
print ECFILE "#include <variable_buffer.H>\n" if ($arg_use_variable_buffers ne undef);
print ECFILE "#include <error_info.H>\n";
print ECFILE "#include <utils.H>\n";
print ECFILE "#include <hwp_error_info.H>\n";
print ECFILE "#include <collect_reg_ffdc.H>\n";
#print ECFILE "#include <proc_extract_sbe_rc.H>\n\n";
print ECFILE "/**\n";
print ECFILE " * \@brief FFDC gathering classes\n";
print ECFILE " *\/\n";
print ECFILE "namespace fapi2\n{\n";

#------------------------------------------------------------------------------
# Print start of file information to collectRegFfdc.H
#------------------------------------------------------------------------------
print CRFILE "// collect_reg_ffdc.H\n";
print CRFILE "// This file is generated by the perl script parseErrorInfo.pl\n\n";
print CRFILE "#ifndef FAPI2_COLLECT_REG_FFDC_H_\n";
print CRFILE "#define FAPI2_COLLECT_REG_FFDC_H_\n";
print CRFILE "#include <stdint.h>\n";
print CRFILE "#include <vector>\n";
print CRFILE "#include <ffdc.H>\n";
print CRFILE "#include <hwp_error_info.H>\n";
print CRFILE "#include <error_info_defs.H>\n";
print CRFILE "#include <buffer.H>\n";
print CRFILE "#include <target.H>\n";
print CRFILE "#include <return_code.H>\n";
print CRFILE "#include <hw_access.H>\n";
print CRFILE "#include <plat_trace.H>\n";
print CRFILE "namespace fapi2\n";
print CRFILE "{\n";
print CRFILE "template< TargetType C, TargetType P >\n";
print CRFILE "void collectRegFfdc(const fapi2::ffdc_t& i_target,\n";
print CRFILE "                        const fapi2::HwpFfdcId i_ffdcId,\n";
print CRFILE "                        fapi2::ReturnCode & o_rc,\n";
print CRFILE "                        uint32_t i_childOffsetMult = 0)\n";
print CRFILE "{\n";
print CRFILE "    FAPI_INF(\"collectRegFfdc. FFDC ID: 0x%x\", i_ffdcId);\n";
print CRFILE "    fapi2::ReturnCode l_rc;\n";
print CRFILE "    fapi2::buffer<uint64_t> l_buf;\n";
print CRFILE "    uint32_t l_cfamData = 0;\n";
print CRFILE "    uint64_t l_scomData = 0;\n";
print CRFILE "    std::vector<uint32_t> l_cfamAddresses;\n";
print CRFILE "    std::vector<uint64_t> l_scomAddresses;\n";
print CRFILE "    uint32_t l_ffdcSize = 0;\n\n";
print CRFILE "    switch (i_ffdcId)\n";
print CRFILE "    {\n";
print CRFILE "        // void statments for the unused variables\n";
print CRFILE "        static_cast<void>(l_cfamData);\n";
print CRFILE "        static_cast<void>(l_scomData);\n";
print CRFILE "        static_cast<void>(l_ffdcSize);\n";
print CRFILE "        static_cast<const void>(i_target);\n";
print CRFILE "        static_cast<void>(o_rc);\n";
print CRFILE "        static_cast<void>(i_childOffsetMult);\n";
#------------------------------------------------------------------------------
# Print start of file information to setSbeError.H
#------------------------------------------------------------------------------
print SBFILE "// setSbeError.H\n";
print SBFILE "// This file is generated by the perl script parseErrorInfo.pl\n\n";
print SBFILE "// When SBE code creates an error, it produces an error value\n";
print SBFILE "// that matches a value in the HwpReturnCode enum in\n";
print SBFILE "// fapiHwpReturnCodes.H. The SBE uses the __ASSEMBLER__\n";
print SBFILE "// primitives in hwpReturnCodes.H to do this. The function\n";
print SBFILE "// that extracts the error value from the SBE needs to call\n";
print SBFILE "// FAPI_SET_HWP_ERROR to create the error and get all the\n";
print SBFILE "// actions in the error XML file performed, but that macro can\n";
print SBFILE "// only be called with the enumerator, not the value. This\n";
print SBFILE "// FAPI_SET_SBE_ERROR macro can be called instead, it calls\n";
print SBFILE "// FAPI_SET_HWP_ERROR with the correct error enumerator.\n";
print SBFILE "// Errors containing <sbeError/> in their XML are supported\n";
print SBFILE "// in this macro.\n\n";
print SBFILE "// Note that it is expected that this macro will be called\n";
print SBFILE "// in one place (the function that extracts the error from\n";
print SBFILE "// the SBE), if this changes and it is called in multiple\n";
print SBFILE "// places then the macro could be turned into a function to\n";
print SBFILE "// avoid the code size increase of expanding the macro in\n";
print SBFILE "// multiple places. The function approach is slightly more\n";
print SBFILE "// complicated, there is an extra C file and the function\n";
print SBFILE "// must take a parameter for the generic chip ID in the error\n";
print SBFILE "// XML.\n\n";
print SBFILE "#ifndef FAPI2_SETSBEERROR_H_\n";
print SBFILE "#define FAPI2_SETSBEERROR_H_\n\n";
print SBFILE "#define FAPI_SET_SBE_ERROR(RC, ERRVAL)\\\n";
print SBFILE "{\\\n";
print SBFILE "switch (ERRVAL)\\\n";
print SBFILE "{\\\n";

#------------------------------------------------------------------------------
# For each XML file
#------------------------------------------------------------------------------
foreach my $argnum (0 .. $#ARGV)
{
    my $infile = $ARGV[$argnum];
    my $count = 0;

    #--------------------------------------------------------------------------
    # Read XML file. The ForceArray option ensures that there is an array of
    # elements even if there is only one element
    #--------------------------------------------------------------------------
    my $errors = $xml->XMLin($infile, ForceArray =>
        ['hwpError', 'collectFfdc', 'ffdc', 'callout', 'deconfigure', 'gard',
         'registerFfdc', 'collectRegisterFfdc', 'cfamRegister', 'scomRegister',
         'id','collectTrace', 'buffer']);

    # Uncomment to get debug output of all errors
    #print "\nFile: ", $infile, "\n", Dumper($errors), "\n";

    #--------------------------------------------------------------------------
    # For each Error
    #--------------------------------------------------------------------------
    foreach my $err (@{$errors->{hwpError}})
    {
        # Hash of methods for the ffdc-gathering class
        my %methods;

        #----------------------------------------------------------------------
        # Check that expected fields are present
        #----------------------------------------------------------------------
        if (! exists $err->{rc})
        {
            print ("parseErrorInfo.pl ERROR. rc missing\n");
            exit(1);
        }

        if (! exists $err->{description})
        {
            print ("parseErrorInfo.pl ERROR in $err->{rc}. description missing\n");
            exit(1);
        }

        #----------------------------------------------------------------------
        # Check that this rc hasn't been deprecated
        #----------------------------------------------------------------------
        if ($deprecated{$err->{rc}} ne undef)
        {
            print "WARNING: $err->{rc} has been deprecated because $deprecated{$err->{rc}}\n";
            next;
        }

        #----------------------------------------------------------------------
        # Set the error enum value in a global hash
        #---------------------------------------------------------------------
        setErrorEnumValue($err->{rc});

        #----------------------------------------------------------------------
        # If this is an SBE error, add it to set_sbe_error.H
        #----------------------------------------------------------------------
        if (exists $err->{sbeError})
        {
            print SBFILE "    case fapi2::$err->{rc}:\\\n";
            print SBFILE "        FAPI_SET_HWP_ERROR(RC, $err->{rc});\\\n";
            print SBFILE "        break;\\\n";
        }

        #----------------------------------------------------------------------
        # Print the CALL_FUNCS_TO_COLLECT_FFDC macro to hwp_error_info.H
        #----------------------------------------------------------------------
        print EIFILE "#define $err->{rc}_CALL_FUNCS_TO_COLLECT_FFDC(RC) ";

        # For now, this code is removed. It appears to work just fine but
        # will require more of the fapi2 infrastructure to be in place.
        # Because the ffdc collection classes create members with real types,
        # the declarations of the types need to be visible - and they're not
        # right now. When we get further along, we can enable this code.
=begin NO_FFDC_COLLECT_HWP
        $count = 0;
        foreach my $collectFfdc (@{$err->{collectFfdc}})
        {
            if ($count == 0)
            {
                print EIFILE "{ fapi2::ReturnCode l_tempRc; ";
            }
            $count++;

            print EIFILE "FAPI_EXEC_HWP(l_tempRc, $collectFfdc, RC); ";

            # collectFfdc is a string we're going to stuff into FAPI_EXEC_HWP
            # but we need to create the arguments in the ffdc class. The first
            # element inthe collectFfdc string is the function to call.
            my @elements = split /,/, $collectFfdc;
            my @signature = @{$signatures{@elements[0]}};
            for (my $i = 1; $i <= $#elements; $i++)
            {
                @elements[$i] =~ s/^\s+|\s+$//g;
                addFfdcMethod(\%methods, @elements[$i], $err->{rc}, @signature[$i-1]);
            }
        }

        if ($count > 0)
        {
            print EIFILE "}";
        }
=cut NO_FFDC_COLLECT_HWP
        print EIFILE "\n";

        #----------------------------------------------------------------------
        # Print the CALL_FUNCS_TO_COLLECT_REG_FFDC macro to hwp_error_info.H
        #----------------------------------------------------------------------
        print EIFILE "#define $err->{rc}_CALL_FUNCS_TO_COLLECT_REG_FFDC(RC) ";

        foreach my $collectRegisterFfdc (@{$err->{collectRegisterFfdc}})
        {
            #------------------------------------------------------------------
            # Check that expected fields are present
            #------------------------------------------------------------------
            if (! exists $collectRegisterFfdc->{id}[0])
            {
                print ("parseErrorInfo.pl ERROR in $err->{rc}. id(s) missing from collectRegisterFfdc\n");
                exit(1);
            }
            foreach my $id (@{$collectRegisterFfdc->{id}})
            {
                #---------------------------------------------------------------------------------
                # Check FFDC register collection type: target, child, or based on present children
                #---------------------------------------------------------------------------------
                if (exists $collectRegisterFfdc->{target})
                {
                    print EIFILE "fapi2::collectRegFfdc<fapi2::TARGET_TYPE_NONE, fapi2::TARGET_TYPE_NONE>($collectRegisterFfdc->{target}, ";
                    print EIFILE "fapi2::$id, RC); ";
                    addFfdcMethod(\%methods, $collectRegisterFfdc->{target},
                                  $err->{rc}, $target_ffdc_type);
                }
                elsif (exists $collectRegisterFfdc->{childTargets})
                {
                    if (! exists $collectRegisterFfdc->{childTargets}->{parent})
                    {
                        print ("parseErrorInfo.pl ERROR: parent missing from collectRegisterFfdc\n");
                        exit(1);
                    }
                    if (! exists $collectRegisterFfdc->{childTargets}->{childType})
                    {
                        print ("parseErrorInfo.pl ERROR: childType missing from collectRegisterFfdc\n");
                        exit(1);
                    }
                    print EIFILE "fapi2::collectRegFfdc<fapi2::$collectRegisterFfdc->{childTargets}->{childType}, fapi2::TARGET_TYPE_NONE>";
                    print EIFILE "($collectRegisterFfdc->{childTargets}->{parent}, fapi2::$id, RC); ";
                    addFfdcMethod(\%methods, $collectRegisterFfdc->{childTargets}->{parent},
                                  $err->{rc}, $target_ffdc_type);
                }
                elsif (exists $collectRegisterFfdc->{basedOnPresentChildren})
                {
                    if (! exists $collectRegisterFfdc->{basedOnPresentChildren}->{target})
                    {
                        print ("parseErrorInfo.pl ERROR: target missing from collectRegisterFfdc\n");
                        exit(1);
                    }
                    if (! exists $collectRegisterFfdc->{basedOnPresentChildren}->{childType})
                    {
                        print ("parseErrorInfo.pl ERROR: childType missing from collectRegisterFfdc\n");
                        exit(1);
                    }
                    if (! exists $collectRegisterFfdc->{basedOnPresentChildren}->{childPosOffsetMultiplier})
                    {
                        print ("parseErrorInfo.pl ERROR: childPosOffsetMultiplier missing from collectRegisterFfdc\n");
                        exit(1);
                    }
                    print EIFILE "fapi2::collectRegFfdc<fapi2::$collectRegisterFfdc->{basedOnPresentChildren}->{childType}, fapi2::TARGET_TYPE_NONE>";
                    print EIFILE "($collectRegisterFfdc->{basedOnPresentChildren}->{target}, fapi2::$id, RC, ";
                    print EIFILE "$collectRegisterFfdc->{basedOnPresentChildren}->{childPosOffsetMultiplier}); ";
                    addFfdcMethod(\%methods, $collectRegisterFfdc->{basedOnPresentChildren}->{target},
                                  $err->{rc}, $target_ffdc_type);
                }
                else
                {
                    print ("parseErrorInfo.pl ERROR: Invalid collectRegisterFfdc configuration\n");
                    exit(1);
                }
            }
        }

        print EIFILE "\n";

        #----------------------------------------------------------------------
        # Print the ADD_ERROR_INFO macro to hwp_error_info.H
        #----------------------------------------------------------------------
        print EIFILE "#define $err->{rc}_ADD_ERROR_INFO(RC) ";

        # Array of EI Objects
        my @eiObjects;

        my $eiObjectStr = "const void * l_objects[] = {";
        my $eiEntryStr = "";
        my $eiEntryCount = 0;
        my %cdgTargetHash; # Records the callout/deconfigure/gards for Targets
        my %cdgChildHash;  # Records the callout/deconfigure/gards for Children

        # collect firmware trace
        foreach my $collectTrace (@{$err->{collectTrace}})
        {
            # Add an EI entry to eiEntryStr
            $eiEntryStr .= "  l_entries[$eiEntryCount].iv_type = fapi2::EI_TYPE_COLLECT_TRACE; \\\n";
            $eiEntryStr .= "  l_entries[$eiEntryCount].collect_trace.iv_eieTraceId =  fapi2::CollectTraces::$collectTrace; \\\n";
            $eiEntryCount++;
        }

        # Local FFDC
        foreach my $ffdc (@{$err->{ffdc}})
        {
            # Set the FFDC ID value in a global hash. The name is <rc>_<ffdc>
            my $ffdcName = $err->{rc} . "_";
            $ffdcName = $ffdcName . $ffdc;
            setFfdcIdValue($ffdcName);

            # Add the FFDC data to the EI Object array if it doesn't already exist
            my $objNum = addEntryToArray(\@eiObjects, $ffdc);

            # Add a method to the ffdc-gathering class
            addFfdcMethod(\%methods, $ffdc, $err->{rc});

            $ffdc = $mangle_names{$ffdc} if ($mangle_names{$ffdc} ne undef);

            # Add an EI entry to eiEntryStr
            $eiEntryStr .= "  l_entries[$eiEntryCount].iv_type = fapi2::EI_TYPE_FFDC; \\\n";
            $eiEntryStr .= "  l_entries[$eiEntryCount].ffdc.iv_ffdcObjIndex = $objNum; \\\n";
            $eiEntryStr .= "  l_entries[$eiEntryCount].ffdc.iv_ffdcId = fapi2::$ffdcName; \\\n";
            $eiEntryStr .= "  l_entries[$eiEntryCount].ffdc.iv_ffdcSize = $ffdc.size(); \\\n";
            $eiEntryCount++;
        }

        # Buffers, looks a lot like local ffdc
        foreach my $buffer (@{$err->{buffer}})
        {
            # Set the FFDC ID value in a global hash. The name is <rc>_<ffdc>
            my $bufferName = $err->{rc} . "_";
            $bufferName = $bufferName . $buffer;
            setFfdcIdValue($bufferName);

            # Add the FFDC data to the EI Object array if it doesn't already exist
            my $objNum = addEntryToArray(\@eiObjects, $buffer);

            # Add a method to the ffdc-gathering class - one for each buffer type
            addFfdcMethod(\%methods, $buffer, $err->{rc}, $buffer_ffdc_type);
            addFfdcMethod(\%methods, $buffer, $err->{rc}, $variable_buffer_ffdc_type);

            # Add an EI entry to eiEntryStr
            $eiEntryStr .= "  l_entries[$eiEntryCount].iv_type = fapi2::EI_TYPE_FFDC; \\\n";
            $eiEntryStr .= "  l_entries[$eiEntryCount].ffdc.iv_ffdcObjIndex = $objNum; \\\n";
            $eiEntryStr .= "  l_entries[$eiEntryCount].ffdc.iv_ffdcId = fapi2::$bufferName; \\\n";
            $eiEntryStr .= "  l_entries[$eiEntryCount].ffdc.iv_ffdcSize = fapi2::getErrorInfoFfdcSize($buffer); \\\n";
            $eiEntryCount++;
        }

        # Procedure/Target/Bus/Child callouts
        foreach my $callout (@{$err->{callout}})
        {
            if (! exists $callout->{priority})
            {
                print ("parseErrorInfo.pl ERROR in $err->{rc}. Callout priority missing\n");
                exit(1);
            }

            my $elementsFound = 0;
            if (exists $callout->{hw})
            {
                # HW Callout
                if (! exists $callout->{hw}->{hwid})
                {
                    print ("parseErrorInfo.pl ERROR in $err->{rc}. HW Callout hwid missing\n");
                    exit(1);
                }

                # Check that those HW callouts that need reference targets have them
                if (($callout->{hw}->{hwid} eq "TOD_CLOCK") ||
                    ($callout->{hw}->{hwid} eq "MEM_REF_CLOCK") ||
                    ($callout->{hw}->{hwid} eq "PROC_REF_CLOCK") ||
                    ($callout->{hw}->{hwid} eq "PCI_REF_CLOCK"))
                {
                    if (! exists $callout->{hw}->{refTarget})
                    {
                        print ("parseErrorInfo.pl ERROR in $err->{rc}. Callout missing refTarget\n");
                        exit(1);
                    }
                }

                # Add an EI entry to eiEntryStr
                $eiEntryStr .= "  l_entries[$eiEntryCount].iv_type = fapi2::EI_TYPE_HW_CALLOUT; \\\n";
                $eiEntryStr .= "  l_entries[$eiEntryCount].hw_callout.iv_hw = fapi2::HwCallouts::$callout->{hw}->{hwid}; \\\n";
                $eiEntryStr .= "  l_entries[$eiEntryCount].hw_callout.iv_calloutPriority = fapi2::CalloutPriorities::$callout->{priority}; \\\n";
                if (exists $callout->{hw}->{refTarget})
                {
                    # Add the Targets to the objectlist if they don't already exist
                    my $objNum = addEntryToArray(\@eiObjects, $callout->{hw}->{refTarget});
                    $eiEntryStr .= "  l_entries[$eiEntryCount].hw_callout.iv_refObjIndex = $objNum; \\\n";

                    # Add a method to the ffdc-gathering class
                    addFfdcMethod(\%methods, $callout->{hw}->{refTarget}, $err->{rc});
                }
                else
                {
                    $eiEntryStr .= "  l_entries[$eiEntryCount].hw_callout.iv_refObjIndex = 0xff; \\\n";
                }
                $eiEntryCount++;
                $elementsFound++;
            }
            if (exists $callout->{procedure})
            {
                # Procedure Callout
                # Add an EI entry to eiEntryStr
                $eiEntryStr .= "  l_entries[$eiEntryCount].iv_type = fapi2::EI_TYPE_PROCEDURE_CALLOUT; \\\n";
                $eiEntryStr .= "  l_entries[$eiEntryCount].proc_callout.iv_procedure = fapi2::ProcedureCallouts::$callout->{procedure}; \\\n";
                $eiEntryStr .= "  l_entries[$eiEntryCount].proc_callout.iv_calloutPriority = fapi2::CalloutPriorities::$callout->{priority}; \\\n";
                $eiEntryCount++;
                $elementsFound++;
            }
            if (exists $callout->{bus})
            {
                # A Bus Callout consists of two targets separated by
                # commas/spaces
                my @targets = split(/\s*,\s*|\s+/, $callout->{bus});

                if (scalar @targets != 2)
                {
                    print ("parseErrorInfo.pl ERROR in $err->{rc}. did not find two targets in bus callout\n");
                    exit(1);
                }

                # Add the Targets to the objectlist if they don't already exist
                my $objNum1 = addEntryToArray(\@eiObjects, $targets[0]);

                my $objNum2 = addEntryToArray(\@eiObjects, $targets[1]);

                # Add a method to the ffdc-gathering class
                addFfdcMethod(\%methods, $targets[0], $err->{rc}, $target_ffdc_type);
                addFfdcMethod(\%methods, $targets[1], $err->{rc}, $target_ffdc_type);

                # Add an EI entry to eiEntryStr
                $eiEntryStr .= "  l_entries[$eiEntryCount].iv_type = fapi2::EI_TYPE_BUS_CALLOUT; \\\n";
                $eiEntryStr .= "  l_entries[$eiEntryCount].bus_callout.iv_endpoint1ObjIndex = $objNum1; \\\n";
                $eiEntryStr .= "  l_entries[$eiEntryCount].bus_callout.iv_endpoint2ObjIndex = $objNum2; \\\n";
                $eiEntryStr .= "  l_entries[$eiEntryCount].bus_callout.iv_calloutPriority = fapi2::CalloutPriorities::$callout->{priority}; \\\n";
                $eiEntryCount++;
                $elementsFound++;
            }
            if (exists $callout->{target})
            {
                # Add the Target to cdgTargetHash to be processed with any
                # deconfigure and GARD requests
                $cdgTargetHash{$callout->{target}}{callout} = 1;
                $cdgTargetHash{$callout->{target}}{priority} =
                    $callout->{priority};

                $elementsFound++;
            }
            if (exists $callout->{childTargets})
            {
                # Check that the parent and childType subelements exist
                if (! exists $callout->{childTargets}->{parent})
                {
                    print ("parseErrorInfo.pl ERROR in $err->{rc}. Child Callout parent missing\n");
                    exit(1);
                }

                if (! exists $callout->{childTargets}->{childType})
                {
                    print ("parseErrorInfo.pl ERROR in $err->{rc}. Child Callout childType missing\n");
                    exit(1);
                }

                # Add the child info to cdgChildHash to be processed with
                # any deconfigure and GARD requests
                my $parent = $callout->{childTargets}->{parent};
                my $childType = $callout->{childTargets}->{childType};
                $cdgChildHash{$parent}{$childType}{callout} = 1;
                $cdgChildHash{$parent}{$childType}{priority} =
                    $callout->{priority};

                $elementsFound++;

                if (exists $callout->{childTargets}->{childPort})
                {
                    my $childPort = $callout->{childTargets}->{childPort};

                    $cdgChildHash{$parent}{$childType}{childPort} = $childPort;
                }

                if (exists $callout->{childTargets}->{childNumber})
                {
                    my $childNum = $callout->{childTargets}->{childNumber};
                    $cdgChildHash{$parent}{$childType}{childNumber} = $childNum;
                }

            }
            if ($elementsFound == 0)
            {
                print ("parseErrorInfo.pl ERROR in $err->{rc}. Callout incomplete\n");
                exit(1);
            }
            elsif ($elementsFound > 1)
            {
                print ("parseErrorInfo.pl ERROR in $err->{rc}. Callout has multiple elements\n");
                exit(1);
            }
        } # callout

        # Target/Child deconfigures
        foreach my $deconfigure (@{$err->{deconfigure}})
        {
            my $elementsFound = 0;
            if (exists $deconfigure->{target})
            {
                # Add the Target to cdgTargetHash to be processed with any
                # callout and GARD requests
                $cdgTargetHash{$deconfigure->{target}}{deconf} = 1;
                $elementsFound++;
            }
            if (exists $deconfigure->{childTargets})
            {
                # Check that the parent and childType subelements exist
                if (! exists $deconfigure->{childTargets}->{parent})
                {
                    print ("parseErrorInfo.pl ERROR in $err->{rc}. Child Deconfigure parent missing\n");
                    exit(1);
                }
                if (! exists $deconfigure->{childTargets}->{childType})
                {
                    print ("parseErrorInfo.pl ERROR in $err->{rc}. Child Deconfigure childType missing\n");
                    exit(1);
                }

                # Add the child info to cdgChildHash to be processed with
                # any callout and GARD requests
                my $parent = $deconfigure->{childTargets}->{parent};
                my $childType = $deconfigure->{childTargets}->{childType};
                $cdgChildHash{$parent}{$childType}{deconf} = 1;

                $elementsFound++;

                if ( exists $deconfigure->{childTargets}->{childPort})
                {
                    my $childPort = $deconfigure->{childTargets}->{childPort};

                    $cdgChildHash{$parent}{$childType}{childPort} = $childPort;
                }

                if ( exists $deconfigure->{childTargets}->{childNumber})
                {
                    my $childNum = $deconfigure->{childTargets}->{childNumber};
                    $cdgChildHash{$parent}{$childType}{childNumber} = $childNum;

                }
            }
            if ($elementsFound == 0)
            {
                print ("parseErrorInfo.pl ERROR in $err->{rc}. Deconfigure incomplete\n");
                exit(1);
            }
            elsif ($elementsFound > 1)
            {
                print ("parseErrorInfo.pl ERROR in $err->{rc}. Deconfigure has multiple elements\n");
                exit(1);
            }
        } # deconfigure

        # Target/Child Gards
        foreach my $gard (@{$err->{gard}})
        {
            my $elementsFound = 0;
            if (exists $gard->{target})
            {
                # Add the Target to cdgTargetHash to be processed with any
                # callout and deconfigure requests
                $cdgTargetHash{$gard->{target}}{gard} = 1;
                $elementsFound++;
            }
            if (exists $gard->{childTargets})
            {
                # Check that the parent and childType subelements exist
                if (! exists $gard->{childTargets}->{parent})
                {
                    print ("parseErrorInfo.pl ERROR in $err->{rc}. Child GARD parent missing\n");
                    exit(1);
                }
                if (! exists $gard->{childTargets}->{childType})
                {
                    print ("parseErrorInfo.pl ERROR in $err->{rc}. Child GARD childType missing\n");
                    exit(1);
                }

                # Add the child info to cdgChildHash to be processed with
                # any callout and deconfigure requests
                my $parent = $gard->{childTargets}->{parent};
                my $childType = $gard->{childTargets}->{childType};
                $cdgChildHash{$parent}{$childType}{gard} = 1;

                $elementsFound++;

                if ( exists $gard->{childTargets}->{childPort})
                {
                    my $childPort = $gard->{childTargets}->{childPort};

                    $cdgChildHash{$parent}{$childType}{childPort} = $childPort;

                }

                if ( exists $gard->{childTargets}->{childNumber})
                {
                    my $childNum = $gard->{childTargets}->{childNumber};
                    $cdgChildHash{$parent}{$childType}{childNumber} = $childNum;
                }
            }
            if ($elementsFound == 0)
            {
                print ("parseErrorInfo.pl ERROR in $err->{rc}. GARD incomplete\n");
                exit(1);
            }
            elsif ($elementsFound > 1)
            {
                print ("parseErrorInfo.pl ERROR in $err->{rc}. GARD has multiple elements\n");
                exit(1);
            }
        } # gard

        # Process the callout, deconfigures and GARDs for each Target
        foreach my $cdg (keys %cdgTargetHash)
        {
            my $callout = 0;
            my $priority = 'LOW';
            my $deconf = 0;
            my $gard = 0;

            if (exists $cdgTargetHash{$cdg}->{callout})
            {
                $callout = 1;
            }
            if (exists $cdgTargetHash{$cdg}->{priority})
            {
                $priority = $cdgTargetHash{$cdg}->{priority};
            }
            if (exists $cdgTargetHash{$cdg}->{deconf})
            {
                $deconf = 1;
            }
            if (exists $cdgTargetHash{$cdg}->{gard})
            {
                $gard = 1;
            }

            # Add the Target to the objectlist if it doesn't already exist
            my $objNum = addEntryToArray(\@eiObjects, $cdg);

            # Add a method to the ffdc-gathering class
            addFfdcMethod(\%methods, $cdg, $err->{rc}, $target_ffdc_type);

            # Add an EI entry to eiEntryStr
            $eiEntryStr .= "  l_entries[$eiEntryCount].iv_type = fapi2::EI_TYPE_CDG; \\\n";
            $eiEntryStr .= "  l_entries[$eiEntryCount].target_cdg.iv_targetObjIndex = $objNum; \\\n";
            $eiEntryStr .= "  l_entries[$eiEntryCount].target_cdg.iv_callout = $callout; \\\n";
            $eiEntryStr .= "  l_entries[$eiEntryCount].target_cdg.iv_deconfigure = $deconf; \\\n";
            $eiEntryStr .= "  l_entries[$eiEntryCount].target_cdg.iv_gard = $gard; \\\n";
            $eiEntryStr .= "  l_entries[$eiEntryCount].target_cdg.iv_calloutPriority = fapi2::CalloutPriorities::$priority; \\\n";
            $eiEntryCount++;
        }

        # Process the callout, deconfigures and GARDs for Child Targets
        foreach my $parent (keys %cdgChildHash)
        {
            foreach my $childType (keys %{$cdgChildHash{$parent}})
            {
                my $callout = 0;
                my $priority = 'LOW';
                my $deconf = 0;
                my $gard = 0;
                my $childPort = 0xFF;
                my $childNumber = 0xFF;

                if (exists $cdgChildHash{$parent}{$childType}->{callout})
                {
                    $callout = 1;
                }
                if (exists $cdgChildHash{$parent}->{$childType}->{priority})
                {
                    $priority =
                        $cdgChildHash{$parent}->{$childType}->{priority};
                }
                if (exists $cdgChildHash{$parent}->{$childType}->{deconf})
                {
                    $deconf = 1;
                }
                if (exists $cdgChildHash{$parent}->{$childType}->{childPort})
                {
                    $childPort =
                        $cdgChildHash{$parent}->{$childType}->{childPort} ;
                     addFfdcMethod(\%methods, $childPort, $err->{rc});
                }
                if (exists $cdgChildHash{$parent}->{$childType}->{childNumber})
                {
                    $childNumber =
                        $cdgChildHash{$parent}->{$childType}->{childNumber} ;
                    addFfdcMethod(\%methods, $childNumber, $err->{rc});
                }
                if (exists $cdgChildHash{$parent}->{$childType}->{gard})
                {
                    $gard = 1;
                }


                # Add the Target to the objectlist if it doesn't already exist
                my $objNum = addEntryToArray(\@eiObjects, $parent);
                addFfdcMethod(\%methods, $parent, $err->{rc}, $target_ffdc_type);

                # Add an EI entry to eiEntryStr
                $eiEntryStr .=
                    "  l_entries[$eiEntryCount].iv_type = fapi2::EI_TYPE_CHILDREN_CDG; \\\n";
                $eiEntryStr .=
                    "  l_entries[$eiEntryCount].children_cdg.iv_parentObjIndex = $objNum; \\\n";
                $eiEntryStr .=
                    "  l_entries[$eiEntryCount].children_cdg.iv_callout = $callout; \\\n";
                $eiEntryStr .=
                    "  l_entries[$eiEntryCount].children_cdg.iv_deconfigure = $deconf; \\\n";
                $eiEntryStr .=
                    "  l_entries[$eiEntryCount].children_cdg.iv_childType = fapi2::$childType; \\\n";
                $eiEntryStr .=
                    "  l_entries[$eiEntryCount].children_cdg.iv_childPort = $childPort; \\\n";
                $eiEntryStr .=
                    "  l_entries[$eiEntryCount].children_cdg.iv_childNumber = $childNumber; \\\n";
                $eiEntryStr .=
                    "  l_entries[$eiEntryCount].children_cdg.iv_gard = $gard; \\\n";
                $eiEntryStr .=
                    "  l_entries[$eiEntryCount].children_cdg.iv_calloutPriority = fapi2::CalloutPriorities::$priority; \\\n";
                $eiEntryCount++;
            }
        }

        # Add all objects to $eiObjectStr
        my $objCount = 0;

        foreach my $eiObject (@eiObjects)
        {
            if ($objCount > 0)
            {
                $eiObjectStr .= ", ";
            }

            if ($mangle_names{$eiObject} eq undef)
            {
                $eiObjectStr .= "$eiObject"
            }
            else
            {
                $eiObjectStr .= $mangle_names{$eiObject};
            }

            $objCount++;
        }
        $eiObjectStr .= "};";

        # Print info to file
        if ($eiEntryCount > 0)
        {
            print EIFILE "\\\n{ \\\n  $eiObjectStr \\\n";
            print EIFILE "  fapi2::ErrorInfoEntry l_entries[$eiEntryCount]; \\\n";
            print EIFILE "$eiEntryStr";
            print EIFILE "  RC.addErrorInfo(l_objects, l_entries, $eiEntryCount); \\\n}";
        }

        print EIFILE "\n";

        #----------------------------------------------------------------------
        # Print the return code class to hwp_error_info.H
        #----------------------------------------------------------------------
        # Remove the repeated whitespace and newlines other characters from the description
        $err->{description} =~ s/^\s+|\s+$|"//g;
        $err->{description} =~ tr{\n}{ };
        $err->{description} =~ s/\h+/ /g;

        #----------------------------------------------------------------------
        # Print the return code class to hwp_error_info.H
        #----------------------------------------------------------------------
        my $class_name = $err->{rc};
        # Remove everything upto and including the first _. This makes the ffdc class
        # names different from the error code value enum names.
        $class_name = (split (/_/, $class_name, 2))[1];

        # Class declaration
        print ECFILE "\nclass $class_name\n{\n  public:\n";

        # Constructor. This traces the description. If this is too much, we can
        # remove it.
        if ($arg_empty_ffdc eq undef)
        {
            print ECFILE "    $class_name(fapi2::errlSeverity_t i_sev = fapi2::FAPI2_ERRL_SEV_UNRECOVERABLE, fapi2::ReturnCode& i_rc = fapi2::current_err):\n";
            print ECFILE "        iv_rc(i_rc),\n";
            print ECFILE "        iv_sev(i_sev)\n";
            print ECFILE "    { FAPI_ERR(\"$err->{description}\"); }\n";
        }
        else
        {
            # Void expression keeps the compiler from complaining about the unused arguments.
            # We want to set the i_rc to the RC if we're empty. This otherwise gets done in _setHwpError()
            print ECFILE "    $class_name(fapi2::errlSeverity_t i_sev = fapi2::FAPI2_ERRL_SEV_UNRECOVERABLE, fapi2::ReturnCode& i_rc = fapi2::current_err)\n";
            print ECFILE "    {\n";
            print ECFILE "        static_cast<void>(i_sev);\n";
            print ECFILE "        i_rc = $err->{rc};\n";
            print ECFILE "    }\n\n";
        }

        # Methods
        foreach my $key (keys %methods)
        {
            print ECFILE $methods{$key}{method};
        }

        # Stick the execute method at the end of the other methods. We allow
        # passing in of the severity so that macros which call execute() can over-ride
        # the default severity.
        print ECFILE "    void execute(fapi2::errlSeverity_t i_sev = fapi2::FAPI2_ERRL_SEV_UNDEFINED)\n";
        if ($arg_empty_ffdc eq undef)
        {
            print ECFILE "    {\n";
            print ECFILE "        FAPI_SET_HWP_ERROR(iv_rc, $err->{rc});\n";
            print ECFILE "        fapi2::logError(iv_rc, (i_sev == fapi2::FAPI2_ERRL_SEV_UNDEFINED) ? iv_sev : i_sev);\n";
            print ECFILE "    }\n\n";
        }
        else
        {
            print ECFILE "    {\n";
            print ECFILE "        static_cast<void>(i_sev);\n";
            print ECFILE "    }\n\n";
        }

        # Instance variables
        if ($arg_empty_ffdc eq undef)
        {
            print ECFILE "  private:\n    ";
            foreach my $key (keys %methods)
            {
                print ECFILE $methods{$key}{member};
            }

            print ECFILE "fapi2::ReturnCode& iv_rc;\n";
            print ECFILE "    fapi2::errlSeverity_t iv_sev;\n";
        }

        print ECFILE "};\n\n\n\n";
    }

    #--------------------------------------------------------------------------
    # For each registerFfdc.
    #--------------------------------------------------------------------------
    foreach my $registerFfdc (@{$errors->{registerFfdc}})
    {
        #----------------------------------------------------------------------
        # Check that expected fields are present
        #----------------------------------------------------------------------
        if (! exists $registerFfdc->{id}[0])
        {
            print ("parseErrorInfo.pl ERROR. id missing from registerFfdc\n");
            exit(1);
        }

        if (scalar @{$registerFfdc->{id}} > 1)
        {
            print ("parseErrorInfo.pl ERROR. multiple ids in registerFfdc\n");
            exit(1);
        }

        #----------------------------------------------------------------------
        # Set the FFDC ID value in a global hash
        #----------------------------------------------------------------------
        setFfdcIdValue($registerFfdc->{id}[0]);

        #----------------------------------------------------------------------
        # Generate code to capture the registers in collect_reg_ffdc.C
        #----------------------------------------------------------------------
        print CRFILE "        case $registerFfdc->{id}[0]:\n";

# TODO: RTC 132226 
=begin NEED_P9_REGISTERS
        # Look for CFAM Register addresses
        foreach my $cfamRegister (@{$registerFfdc->{cfamRegister}})
        {
            print CRFILE "            l_cfamAddresses.push_back($cfamRegister);\n";
            print CRFILE "            l_ffdcSize += sizeof(l_cfamData);\n";
        }

        # Look for SCOM Register addresses
        foreach my $scomRegister (@{$registerFfdc->{scomRegister}})
        {
            print CRFILE "            l_scomAddresses.push_back($scomRegister);\n";
            print CRFILE "            l_ffdcSize += sizeof(l_scomData);\n";
        }
=cut NEED_P9_REGISTERS

        print CRFILE "            break;\n";
    }

}

#------------------------------------------------------------------------------
# Print end of file information to collect_reg_ffdc.C
#------------------------------------------------------------------------------
print CRFILE "        default:\n";
print CRFILE "            FAPI_ERR(\"collect_reg_ffdc.C: Invalid FFDC ID 0x%x\", ";
print CRFILE                     "i_ffdcId);\n";
print CRFILE "            return;\n";
print CRFILE "    }\n\n";

# TODO: RTC 132226 
=begin NEED_P9_REGISTERS
print CRFILE "    uint8_t * l_pBuf = NULL;\n";
print CRFILE "    uint8_t * l_pData = NULL;\n";
print CRFILE "    std::vector<fapi::Target> l_targets;\n";
print CRFILE "    uint32_t l_chipletPos32 = 0;\n";

#---------------------------------------------------------------------------------------------------------
# Populate chiplet vectors (if required by register collection method) and adjust buffer sizes accordingly
#---------------------------------------------------------------------------------------------------------
print CRFILE "    if (C != TARGET_TYPE_NONE)\n";
print CRFILE "    {\n";
print CRFILE "        l_rc = fapiGetChildChiplets(i_target, i_child, l_targets, TARGET_STATE_FUNCTIONAL);\n";
print CRFILE "        if (l_rc)\n";
print CRFILE "        {\n";
print CRFILE "            FAPI_ERR(\"collect_reg_ffdc.C: Error: fapiGetChildChiplets: failed to get chiplets.\");\n";
print CRFILE "            return;\n";
print CRFILE "        }\n";
print CRFILE "        if (l_targets.empty())\n";
print CRFILE "        {\n";
print CRFILE "            FAPI_INF(\"collect_reg_ffdc.C: Error: No functional chiplets found. \");\n";
print CRFILE "            return;\n";
print CRFILE "        }\n";
print CRFILE "        l_ffdcSize += sizeof(l_chipletPos32);\n";
print CRFILE "        l_ffdcSize *= l_targets.size();\n";
print CRFILE "        l_pBuf = new uint8_t[l_ffdcSize];\n";
print CRFILE "        l_pData = l_pBuf;\n";
print CRFILE "    }\n";
print CRFILE "    else if (P != TARGET_TYPE_NONE)\n";
print CRFILE "    {\n";
print CRFILE "        l_rc = fapiGetChildChiplets(i_target, i_presChild, l_targets, TARGET_STATE_PRESENT);\n";
print CRFILE "        if (l_rc)\n";
print CRFILE "        {\n";
print CRFILE "            FAPI_ERR(\"collect_reg_ffdc.C: Error: fapiGetChildChiplets: failed to get chiplets.\");\n";
print CRFILE "            return;\n";
print CRFILE "        }\n";
print CRFILE "        if (l_targets.empty())\n";
print CRFILE "        {\n";
print CRFILE "            FAPI_INF(\"collect_reg_ffdc.C: Error: No functional chiplets found. \");\n";
print CRFILE "            return;\n";
print CRFILE "        }\n";
print CRFILE "        l_ffdcSize += sizeof(l_chipletPos32);\n";
print CRFILE "        l_ffdcSize *= l_targets.size();\n";
print CRFILE "        l_pBuf = new uint8_t[l_ffdcSize];\n";
print CRFILE "        l_pData = l_pBuf;\n";
print CRFILE "    }\n";
print CRFILE "    else\n";
print CRFILE "    {\n";
print CRFILE "        l_ffdcSize += sizeof(l_chipletPos32);\n";
print CRFILE "        l_pBuf = new uint8_t[l_ffdcSize];\n";
print CRFILE "        l_pData = l_pBuf;\n";
print CRFILE "        l_targets.push_back(i_target);\n";
print CRFILE "    }\n\n";

#---------------------------------------------------------------------------------------------------------
# Obtain target position and insert as the first word in the buffer
#---------------------------------------------------------------------------------------------------------
print CRFILE "    bool l_targIsChiplet = i_target.isChiplet();\n\n";
print CRFILE "    for (std::vector<fapi::Target>::const_iterator targetIter = l_targets.begin();\n";
print CRFILE "        targetIter != l_targets.end(); ++targetIter)\n";
print CRFILE "    {\n";
print CRFILE "        if ((fapi2::TARGET_TYPE_NONE != i_child) ||\n";
print CRFILE "            (fapi2::TARGET_TYPE_NONE != i_presChild) ||\n";
print CRFILE "            (true == l_targIsChiplet))\n";
print CRFILE "        {\n";
print CRFILE "            uint8_t l_chipletPos = 0;\n";
print CRFILE "            l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &(*targetIter), l_chipletPos);\n";
print CRFILE "            if (l_rc)\n";
print CRFILE "            {\n";
print CRFILE "                FAPI_ERR(\"collect_reg_ffdc.C: Error getting chiplet position\");\n";
print CRFILE "                l_chipletPos = 0xFF;\n";
print CRFILE "            }\n";
                          #-------------------------------------------------------------------------
                          # We print the target's position in the error log whether the target is a
                          # chip or chiplet, so we need to store the chiplet position in a uint32_t
                          # to have consitency in the buffer as ATTR_POS below returns a uint32_t
                          #-------------------------------------------------------------------------
print CRFILE "            l_chipletPos32 = l_chipletPos;\n";
print CRFILE "        }\n";
print CRFILE "        else\n";
print CRFILE "        {\n";
print CRFILE "            l_rc = FAPI_ATTR_GET(ATTR_POS, &(*targetIter), l_chipletPos32);\n";
print CRFILE "            if (l_rc)\n";
print CRFILE "            {\n";
print CRFILE "                FAPI_ERR(\"collect_reg_ffdc.C: Error getting chip position\");\n";
print CRFILE "                l_chipletPos32 = 0xFFFFFFFF;\n";
print CRFILE "            }\n";
print CRFILE "        }\n";
print CRFILE "        *(reinterpret_cast<uint32_t *>(l_pData)) = l_chipletPos32;\n";
print CRFILE "        l_pData += sizeof(l_chipletPos32);\n";
#---------------------------------------------------------------------------------------------------------
# Instert cfam data (if any) related to this chip / chiplet into the buffer
# If collecting FFDC based on present children, adjust the register address by the appropriate offset
#---------------------------------------------------------------------------------------------------------
print CRFILE "        for (std::vector<uint32_t>::const_iterator cfamIter = l_cfamAddresses.begin();\n";
print CRFILE "             cfamIter != l_cfamAddresses.end(); ++cfamIter)\n";
print CRFILE "        {\n";
print CRFILE "            if (fapi2::TARGET_TYPE_NONE != i_presChild)\n";
print CRFILE "            {\n";
print CRFILE "                l_rc = fapiGetCfamRegister(i_target, (*cfamIter + (l_chipletPos32 * i_childOffsetMult)), l_buf);\n";
print CRFILE "            }\n";
print CRFILE "            else\n";
print CRFILE "            {\n";
print CRFILE "                l_rc = fapiGetCfamRegister(*targetIter, *cfamIter, l_buf);\n";
print CRFILE "            }\n";
print CRFILE "            if (l_rc)\n";
print CRFILE "            {\n";
print CRFILE "                FAPI_ERR(\"collect_reg_ffdc.C: CFAM error for 0x%x\",";
print CRFILE                          "*cfamIter);\n";
print CRFILE "                l_cfamData = 0xbaddbadd;\n";
print CRFILE "            }\n";
print CRFILE "            else\n";
print CRFILE "            {\n";
print CRFILE "                l_cfamData = l_buf.getWord(0);\n";
print CRFILE "            }\n";
print CRFILE "            *(reinterpret_cast<uint32_t *>(l_pData)) = l_cfamData;\n";
print CRFILE "            l_pData += sizeof(l_cfamData);\n";
print CRFILE "        }\n\n";
#---------------------------------------------------------------------------------------------------------
# Instert any scom data (if any) related to this chip / chiplet into the buffer
# If collecting FFDC based on present children, adjust the register address by the appropriate offset
#---------------------------------------------------------------------------------------------------------
print CRFILE "        for (std::vector<uint64_t>::const_iterator scomIter = l_scomAddresses.begin();\n";
print CRFILE "            scomIter != l_scomAddresses.end(); ++scomIter)\n";
print CRFILE "        {\n";
print CRFILE "            if (fapi2::TARGET_TYPE_NONE != i_presChild)\n";
print CRFILE "            {\n";
print CRFILE "                l_rc = fapiGetScom(i_target, (*scomIter + (l_chipletPos32 * i_childOffsetMult)), l_buf);\n";
print CRFILE "            }\n";
print CRFILE "            else\n";
print CRFILE "            {\n";
print CRFILE "                l_rc = fapiGetScom(*targetIter, *scomIter, l_buf);\n";
print CRFILE "            }\n";
print CRFILE "            if (l_rc)\n";
print CRFILE "            {\n";
print CRFILE "                FAPI_ERR(\"collect_reg_ffdc.C: SCOM error for 0x%llx\",";
print CRFILE                         "*scomIter);\n";
print CRFILE "                l_scomData = 0xbaddbaddbaddbaddULL;\n";
print CRFILE "            }\n";
print CRFILE "            else\n";
print CRFILE "            {\n";
print CRFILE "                 l_scomData = l_buf.getDoubleWord(0);\n";
print CRFILE "            }\n";
print CRFILE "            *(reinterpret_cast<uint64_t *>(l_pData)) = l_scomData;\n";
print CRFILE "            l_pData += sizeof(l_scomData);\n";
print CRFILE "        }\n";
print CRFILE "    }\n\n";
print CRFILE "    o_rc.addEIFfdc(i_ffdcId, l_pBuf, l_ffdcSize);\n";
print CRFILE "    delete [] l_pBuf;\n";

=cut NEED_P9_REGISTERS

print CRFILE "}\n";
print CRFILE "}\n";
print CRFILE "#endif\n";

#------------------------------------------------------------------------------
# Print the fapiHwpReturnCodes.H file
#------------------------------------------------------------------------------
print RCFILE "// fapiHwpReturnCodes.H\n";
print RCFILE "// This file is generated by perl script parseErrorInfo.pl\n\n";
print RCFILE "#ifndef FAPI2_HWPRETURNCODES_H_\n";
print RCFILE "#define FAPI2_HWPRETURNCODES_H_\n\n";
print RCFILE "#ifndef __ASSEMBLER__\n";
print RCFILE "namespace fapi2\n";
print RCFILE "{\n\n";
print RCFILE "/**\n";
print RCFILE " * \@brief Enumeration of HWP return codes\n";
print RCFILE " *\/\n";
print RCFILE "enum HwpReturnCode\n";
print RCFILE "{\n";
foreach my $key (keys %errNameToValueHash)
{
    print RCFILE "    $key = 0x$errNameToValueHash{$key},\n";
}
print RCFILE "};\n\n";
print RCFILE "}\n\n";
print RCFILE "#else\n";
foreach my $key (keys %errNameToValueHash)
{
    print RCFILE "    .set $key, 0x$errNameToValueHash{$key}\n";
}
print RCFILE "#endif\n";
print RCFILE "#endif\n";

#------------------------------------------------------------------------------
# Print the HwpFfdcId enumeration to hwp_error_info.H
#------------------------------------------------------------------------------
print EIFILE "namespace fapi2\n";
print EIFILE "{\n\n";
print EIFILE "/**\n";
print EIFILE " * \@brief Enumeration of FFDC identifiers\n";
print EIFILE " *\/\n";
print EIFILE "enum HwpFfdcId\n";
print EIFILE "{\n";
foreach my $key (keys %ffdcNameToValueHash)
{
    print EIFILE "    $key = 0x$ffdcNameToValueHash{$key},\n";
}
print EIFILE "};\n\n";
print EIFILE "}\n\n";

#------------------------------------------------------------------------------
# Print end of file information to hwp_error_info.H
#------------------------------------------------------------------------------
print EIFILE "\n\n#endif\n";

#------------------------------------------------------------------------------
# Print end of file information to hwp_ffdc_classes.H
#------------------------------------------------------------------------------
print ECFILE "\n};\n"; # close the namespace
print ECFILE "\n\n#endif\n";

#------------------------------------------------------------------------------
# Print end of file information to set_sbe_error.H
#------------------------------------------------------------------------------
print SBFILE "    default:\\\n";
print SBFILE "        FAPI_SET_HWP_ERROR(RC, RC_SBE_UNKNOWN_ERROR);\\\n";
print SBFILE "        break;\\\n";
print SBFILE "}\\\n";
print SBFILE "}\n\n";
print SBFILE "#endif\n";

#------------------------------------------------------------------------------
# Close output files
#------------------------------------------------------------------------------
close(RCFILE);
close(EIFILE);
close(ECFILE);
close(CRFILE);
close(SBFILE);
