#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/fapi/fapiParseErrorInfo.pl $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2011,2014
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
# $Id: fapiParseErrorInfo.pl,v 1.28 2014/03/26 21:31:21 mjjones Exp $
# Purpose:  This perl script will parse HWP Error XML files and create required
#           FAPI code.
#
# Author: CamVan Nguyen and Mike Jones
#
# Change Log **********************************************************
#
#  Flag  Track#    Userid    Date      Description
#  ----  --------  --------  --------  -----------
#                  camvanng  06/03/11  Created
#                  mjjones   06/06/11  Minor updates for integration
#                  mjjones   06/10/11  Added "use strict;"
#                  mjjones   07/05/11  Take output dir as parameter
#                  mjjones   08/08/11  Large update to create more code
#                  mjjones   08/24/11  Parse GARD info
#                  mjjones   09/22/11  New Error Info Design
#                  camvanng  10/20/11  Fix bug
#                  mjjones   12/16/11  Improved usage statement
#                  mjjones   02/10/12  Allow err file with one element
#                  mjjones   03/22/12  Generate hash values for enums
#                  mjjones   05/15/12  Detect duplicate error rcs
#                  mjjones   05/21/12  Detect duplicate ids/hashes across files
#                  mjjones   06/27/12  Add assembler output for SBE usage
#                  mjjones   09/19/12  Generate FFDC ID enumeration
#                                      Generate fapiCollectRegFfdc.C file
#                  mjjones   10/23/12  Minor fix for Cronus compile failure
#                  mjjones   11/09/12  Generate fapiSetSbeError.H
#                  mjjones   01/09/13  Fix CFAM register capture
#                  mjjones   03/14/13  Allow 64bit literals for SCOM reg capture
#                  mjjones   03/22/13  Support Procedure Callouts
#                  mjjones   04/25/13  Allow multiple register ffdc ids in a
#                                      collectRegisterFfdc element
#                  mjjones   05/20/13  Support Bus Callouts
#                  mjjones   06/24/13  Support Children CDGs
#                  mjjones   08/20/13  Use constants for Reg FFDC collection
#                  mjjones   08/26/13  Support HW Callouts
#                  dedahle   09/30/13  Support chiplet register FFDC collection
#                  rjknight  09/24/13  Allow callout/deconfigure/gard of
#                                      DIMM(s) related to MBA
#                  dedahle   10/15/13  Support register FFDC collection based on
#                                      present children
#                  whs       03/11/14  Add FW traces to error logs
#                  mjjones   03/20/14  Fix register FFDC collection bug when
#                                      collecting chiplet registers
#                  mjjones   03/26/14  Generate HWP error on unknown SBE error
#
# End Change Log *****************************************************
#
# Usage:
# fapiParseErrorInfo.pl <output dir> <filename1> <filename2> ...

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
#use Data::Dumper;

#------------------------------------------------------------------------------
# Print Command Line Help
#------------------------------------------------------------------------------
my $numArgs = $#ARGV + 1;
if ($numArgs < 2)
{
    print ("Usage: fapiParseErrorInfo.pl <output dir> <filename1> <filename2> ...\n");
    print ("  This perl script will parse HWP Error XML files and create\n");
    print ("  the following files:\n");
    print ("  - fapiHwpReturnCodes.H. HwpReturnCode enumeration (HWP generated errors)\n");
    print ("  - fapiHwpErrorInfo.H.   Error information (used by FAPI_SET_HWP_ERROR\n");
    print ("                          when a HWP generates an error)\n");
    print ("  - fapiCollectRegFfdc.C. Function to collect register FFDC\n");
    print ("  - fapiSetSbeError.H.    Macro to create an SBE error\n");
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
# Open output files for writing
#------------------------------------------------------------------------------
my $rcFile = $ARGV[0];
$rcFile .= "/";
$rcFile .= "fapiHwpReturnCodes.H";
open(RCFILE, ">", $rcFile);

my $eiFile = $ARGV[0];
$eiFile .= "/";
$eiFile .= "fapiHwpErrorInfo.H";
open(EIFILE, ">", $eiFile);

my $crFile = $ARGV[0];
$crFile .= "/";
$crFile .= "fapiCollectRegFfdc.C";
open(CRFILE, ">", $crFile);

my $sbFile = $ARGV[0];
$sbFile .= "/";
$sbFile .= "fapiSetSbeError.H";
open(SBFILE, ">", $sbFile);

#------------------------------------------------------------------------------
# Print start of file information to fapiHwpErrorInfo.H
#------------------------------------------------------------------------------
print EIFILE "// fapiHwpErrorInfo.H\n";
print EIFILE "// This file is generated by perl script fapiParseErrorInfo.pl\n\n";
print EIFILE "#ifndef FAPIHWPERRORINFO_H_\n";
print EIFILE "#define FAPIHWPERRORINFO_H_\n\n";
print EIFILE "/**\n";
print EIFILE " * \@brief Error Information macros and HwpFfdcId enumeration\n";
print EIFILE " *\/\n";

#------------------------------------------------------------------------------
# Print start of file information to fapiCollectRegFfdc.C
#------------------------------------------------------------------------------
print CRFILE "// fapiCollectRegFfdc.C\n";
print CRFILE "// This file is generated by perl script fapiParseErrorInfo.pl\n\n";
print CRFILE "#include <stdint.h>\n";
print CRFILE "#include <vector>\n";
print CRFILE "#include <ecmdDataBufferBase.H>\n";
print CRFILE "#include <fapiCollectRegFfdc.H>\n";
print CRFILE "#include <fapiTarget.H>\n";
print CRFILE "#include <fapiReturnCode.H>\n";
print CRFILE "#include <fapiHwAccess.H>\n";
print CRFILE "#include <fapiPlatTrace.H>\n";
print CRFILE "#include <fapiPlatRegAddresses.H>\n\n";
print CRFILE "#include <fapiAttributeService.H>\n";
print CRFILE "#include <fapiSystemConfig.H>\n\n";

print CRFILE "namespace fapi\n";
print CRFILE "{\n";
print CRFILE "void fapiCollectRegFfdc(const fapi::Target & i_target,\n";
print CRFILE "                        const fapi::HwpFfdcId i_ffdcId,\n";
print CRFILE "                        fapi::ReturnCode & o_rc,\n";
print CRFILE "                        fapi::TargetType i_child,\n";
print CRFILE "                        fapi::TargetType i_presChild,\n";
print CRFILE "                        uint32_t i_childOffsetMult)\n";
print CRFILE "{\n";
print CRFILE "    FAPI_INF(\"fapiCollectRegFfdc. FFDC ID: 0x%x\", i_ffdcId);\n";
print CRFILE "    fapi::ReturnCode l_rc;\n";
print CRFILE "    ecmdDataBufferBase l_buf;\n";
print CRFILE "    uint32_t l_cfamData = 0;\n";
print CRFILE "    uint64_t l_scomData = 0;\n";
print CRFILE "    std::vector<uint32_t> l_cfamAddresses;\n";
print CRFILE "    std::vector<uint64_t> l_scomAddresses;\n";
print CRFILE "    uint32_t l_ffdcSize = 0;\n\n";
print CRFILE "    switch (i_ffdcId)\n";
print CRFILE "    {\n";

#------------------------------------------------------------------------------
# Print start of file information to fapiSetSbeError.H
#------------------------------------------------------------------------------
print SBFILE "// fapiSetSbeError.H\n";
print SBFILE "// This file is generated by perl script fapiParseErrorInfo.pl\n\n";
print SBFILE "// When SBE code creates an error, it produces an error value\n";
print SBFILE "// that matches a value in the HwpReturnCode enum in\n";
print SBFILE "// fapiHwpReturnCodes.H. The SBE uses the __ASSEMBLER__\n";
print SBFILE "// primitives in fapiHwpReturnCodes.H to do this. The function\n";
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
print SBFILE "#ifndef FAPISETSBEERROR_H_\n";
print SBFILE "#define FAPISETSBEERROR_H_\n\n";
print SBFILE "#define FAPI_SET_SBE_ERROR(RC, ERRVAL)\\\n";
print SBFILE "switch (ERRVAL)\\\n";
print SBFILE "{\\\n";

#------------------------------------------------------------------------------
# For each XML file
#------------------------------------------------------------------------------
foreach my $argnum (1 .. $#ARGV)
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
         'id','collectTrace']);

    # Uncomment to get debug output of all errors
    #print "\nFile: ", $infile, "\n", Dumper($errors), "\n";

    #--------------------------------------------------------------------------
    # For each Error
    #--------------------------------------------------------------------------
    foreach my $err (@{$errors->{hwpError}})
    {
        #----------------------------------------------------------------------
        # Check that expected fields are present
        #----------------------------------------------------------------------
        if (! exists $err->{rc})
        {
            print ("fapiParseErrorInfo.pl ERROR. rc missing\n");
            exit(1);
        }

        if (! exists $err->{description})
        {
            print ("fapiParseErrorInfo.pl ERROR in $err->{rc}. description missing\n");
            exit(1);
        }

        #----------------------------------------------------------------------
        # Set the error enum value in a global hash
        #---------------------------------------------------------------------
        setErrorEnumValue($err->{rc});

        #----------------------------------------------------------------------
        # If this is an SBE error, add it to fapiSetSbeError.H
        #----------------------------------------------------------------------
        if (exists $err->{sbeError})
        {
            print SBFILE "    case fapi::$err->{rc}:\\\n";
            print SBFILE "        FAPI_SET_HWP_ERROR(RC, $err->{rc});\\\n";
            print SBFILE "        break;\\\n";
        }

        #----------------------------------------------------------------------
        # Print the CALL_FUNCS_TO_COLLECT_FFDC macro to fapiHwpErrorInfo.H
        #----------------------------------------------------------------------
        print EIFILE "#define $err->{rc}_CALL_FUNCS_TO_COLLECT_FFDC(RC) ";
        $count = 0;

        foreach my $collectFfdc (@{$err->{collectFfdc}})
        {
            if ($count == 0)
            {
                print EIFILE "{ fapi::ReturnCode l_tempRc; ";
            }
            $count++;

            print EIFILE "FAPI_EXEC_HWP(l_tempRc, $collectFfdc, RC); ";
        }

        if ($count > 0)
        {
            print EIFILE "}";
        }

        print EIFILE "\n";

        #----------------------------------------------------------------------
        # Print the CALL_FUNCS_TO_COLLECT_REG_FFDC macro to fapiHwpErrorInfo.H
        #----------------------------------------------------------------------
        print EIFILE "#define $err->{rc}_CALL_FUNCS_TO_COLLECT_REG_FFDC(RC) ";

        foreach my $collectRegisterFfdc (@{$err->{collectRegisterFfdc}})
        {
            #------------------------------------------------------------------
            # Check that expected fields are present
            #------------------------------------------------------------------
            if (! exists $collectRegisterFfdc->{id}[0])
            {
                print ("fapiParseErrorInfo.pl ERROR in $err->{rc}. id(s) missing from collectRegisterFfdc\n");
                exit(1);
            }
            foreach my $id (@{$collectRegisterFfdc->{id}})
            {
                #---------------------------------------------------------------------------------
                # Check FFDC register collection type: target, child, or based on present children
                #---------------------------------------------------------------------------------
                if (exists $collectRegisterFfdc->{target})
                {
                    print EIFILE "fapiCollectRegFfdc($collectRegisterFfdc->{target}, ";
                    print EIFILE "fapi::$id, RC); ";
                }
                elsif (exists $collectRegisterFfdc->{childTargets})
                {
                    if (! exists $collectRegisterFfdc->{childTargets}->{parent})
                    {
                        print ("fapiParseErrorInfo.pl ERROR: parent missing from collectRegisterFfdc\n");
                        exit(1);
                    }
                    if (! exists $collectRegisterFfdc->{childTargets}->{childType})
                    {
                        print ("fapiParseErrorInfo.pl ERROR: childType missing from collectRegisterFfdc\n");
                        exit(1);
                    }
                    print EIFILE "fapiCollectRegFfdc($collectRegisterFfdc->{childTargets}->{parent}, ";
                    print EIFILE "fapi::$id, RC, fapi::$collectRegisterFfdc->{childTargets}->{childType}); ";
                }
                elsif (exists $collectRegisterFfdc->{basedOnPresentChildren})
                {
                    if (! exists $collectRegisterFfdc->{basedOnPresentChildren}->{target})
                    {
                        print ("fapiParseErrorInfo.pl ERROR: target missing from collectRegisterFfdc\n");
                        exit(1);
                    }
                    if (! exists $collectRegisterFfdc->{basedOnPresentChildren}->{childType})
                    {
                        print ("fapiParseErrorInfo.pl ERROR: childType missing from collectRegisterFfdc\n");
                        exit(1);
                    }
                    if (! exists $collectRegisterFfdc->{basedOnPresentChildren}->{childPosOffsetMultiplier})
                    {
                        print ("fapiParseErrorInfo.pl ERROR: childPosOffsetMultiplier missing from collectRegisterFfdc\n");
                        exit(1);
                    }
                    print EIFILE "fapiCollectRegFfdc($collectRegisterFfdc->{basedOnPresentChildren}->{target}, ";
                    print EIFILE "fapi::$id, RC, fapi::TARGET_TYPE_NONE, fapi::$collectRegisterFfdc->{basedOnPresentChildren}->{childType}, ";
                    print EIFILE "$collectRegisterFfdc->{basedOnPresentChildren}->{childPosOffsetMultiplier});";
                }
                else
                {
                    print ("fapiParseErrorInfo.pl ERROR: Invalid collectRegisterFfdc configuration\n");
                    exit(1);
                }
            }
        }

        print EIFILE "\n";

        #----------------------------------------------------------------------
        # Print the ADD_ERROR_INFO macro to fapiHwpErrorInfo.H
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
            $eiEntryStr .= "  l_entries[$eiEntryCount].iv_type = fapi::ReturnCode::EI_TYPE_COLLECT_TRACE; \\\n";
            $eiEntryStr .= "  l_entries[$eiEntryCount].collect_trace.iv_eieTraceId =  fapi::CollectTraces::$collectTrace; \\\n";
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

            # Add an EI entry to eiEntryStr
            $eiEntryStr .= "  l_entries[$eiEntryCount].iv_type = fapi::ReturnCode::EI_TYPE_FFDC; \\\n";
            $eiEntryStr .= "  l_entries[$eiEntryCount].ffdc.iv_ffdcObjIndex = $objNum; \\\n";
            $eiEntryStr .= "  l_entries[$eiEntryCount].ffdc.iv_ffdcId = fapi::$ffdcName; \\\n";
            $eiEntryStr .= "  l_entries[$eiEntryCount].ffdc.iv_ffdcSize = fapi::ReturnCodeFfdc::getErrorInfoFfdcSize($ffdc); \\\n";
            $eiEntryCount++;
        }

        # Procedure/Target/Bus/Child callouts
        foreach my $callout (@{$err->{callout}})
        {
            if (! exists $callout->{priority})
            {
                print ("fapiParseErrorInfo.pl ERROR in $err->{rc}. Callout priority missing\n");
                exit(1);
            }

            my $elementsFound = 0;
            if (exists $callout->{hw})
            {
                # HW Callout
                if (! exists $callout->{hw}->{hwid})
                {
                    print ("fapiParseErrorInfo.pl ERROR in $err->{rc}. HW Callout hwid missing\n");
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
                        print ("fapiParseErrorInfo.pl ERROR in $err->{rc}. Callout missing refTarget\n");
                        exit(1);
                    }
                }

                # Add an EI entry to eiEntryStr
                $eiEntryStr .= "  l_entries[$eiEntryCount].iv_type = fapi::ReturnCode::EI_TYPE_HW_CALLOUT; \\\n";
                $eiEntryStr .= "  l_entries[$eiEntryCount].hw_callout.iv_hw = fapi::HwCallouts::$callout->{hw}->{hwid}; \\\n";
                $eiEntryStr .= "  l_entries[$eiEntryCount].hw_callout.iv_calloutPriority = fapi::CalloutPriorities::$callout->{priority}; \\\n";
                if (exists $callout->{hw}->{refTarget})
                {
                    # Add the Targets to the objectlist if they don't already exist
                    my $objNum = addEntryToArray(\@eiObjects, $callout->{hw}->{refTarget});
                    $eiEntryStr .= "  l_entries[$eiEntryCount].hw_callout.iv_refObjIndex = $objNum; \\\n";
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
                $eiEntryStr .= "  l_entries[$eiEntryCount].iv_type = fapi::ReturnCode::EI_TYPE_PROCEDURE_CALLOUT; \\\n";
                $eiEntryStr .= "  l_entries[$eiEntryCount].proc_callout.iv_procedure = fapi::ProcedureCallouts::$callout->{procedure}; \\\n";
                $eiEntryStr .= "  l_entries[$eiEntryCount].proc_callout.iv_calloutPriority = fapi::CalloutPriorities::$callout->{priority}; \\\n";
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
                    print ("fapiParseErrorInfo.pl ERROR in $err->{rc}. did not find two targets in bus callout\n");
                    exit(1);
                }

                # Check the type of the Targets
                print EIFILE "fapi::fapiCheckType<const fapi::Target *>(&$targets[0]); \\\n";
                print EIFILE "fapi::fapiCheckType<const fapi::Target *>(&$targets[1]); \\\n";

                # Add the Targets to the objectlist if they don't already exist
                my $objNum1 = addEntryToArray(\@eiObjects, $targets[0]);
                my $objNum2 = addEntryToArray(\@eiObjects, $targets[1]);

                # Add an EI entry to eiEntryStr
                $eiEntryStr .= "  l_entries[$eiEntryCount].iv_type = fapi::ReturnCode::EI_TYPE_BUS_CALLOUT; \\\n";
                $eiEntryStr .= "  l_entries[$eiEntryCount].bus_callout.iv_endpoint1ObjIndex = $objNum1; \\\n";
                $eiEntryStr .= "  l_entries[$eiEntryCount].bus_callout.iv_endpoint2ObjIndex = $objNum2; \\\n";
                $eiEntryStr .= "  l_entries[$eiEntryCount].bus_callout.iv_calloutPriority = fapi::CalloutPriorities::$callout->{priority}; \\\n";
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
                    print ("fapiParseErrorInfo.pl ERROR in $err->{rc}. Child Callout parent missing\n");
                    exit(1);
                }

                if (! exists $callout->{childTargets}->{childType})
                {
                    print ("fapiParseErrorInfo.pl ERROR in $err->{rc}. Child Callout childType missing\n");
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
                print ("fapiParseErrorInfo.pl ERROR in $err->{rc}. Callout incomplete\n");
                exit(1);
            }
            elsif ($elementsFound > 1)
            {
                print ("fapiParseErrorInfo.pl ERROR in $err->{rc}. Callout has multiple elements\n");
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
                    print ("fapiParseErrorInfo.pl ERROR in $err->{rc}. Child Deconfigure parent missing\n");
                    exit(1);
                }
                if (! exists $deconfigure->{childTargets}->{childType})
                {
                    print ("fapiParseErrorInfo.pl ERROR in $err->{rc}. Child Deconfigure childType missing\n");
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
                print ("fapiParseErrorInfo.pl ERROR in $err->{rc}. Deconfigure incomplete\n");
                exit(1);
            }
            elsif ($elementsFound > 1)
            {
                print ("fapiParseErrorInfo.pl ERROR in $err->{rc}. Deconfigure has multiple elements\n");
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
                    print ("fapiParseErrorInfo.pl ERROR in $err->{rc}. Child GARD parent missing\n");
                    exit(1);
                }
                if (! exists $gard->{childTargets}->{childType})
                {
                    print ("fapiParseErrorInfo.pl ERROR in $err->{rc}. Child GARD childType missing\n");
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
                print ("fapiParseErrorInfo.pl ERROR in $err->{rc}. GARD incomplete\n");
                exit(1);
            }
            elsif ($elementsFound > 1)
            {
                print ("fapiParseErrorInfo.pl ERROR in $err->{rc}. GARD has multiple elements\n");
                exit(1);
            }
        } # gard

        # Process the callout, deconfigures and GARDs for each Target
        foreach my $cdg (keys %cdgTargetHash)
        {
            # Check the type
            print EIFILE "fapi::fapiCheckType<const fapi::Target *>(&$cdg); \\\n";

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

            # Add an EI entry to eiEntryStr
            $eiEntryStr .= "  l_entries[$eiEntryCount].iv_type = fapi::ReturnCode::EI_TYPE_CDG; \\\n";
            $eiEntryStr .= "  l_entries[$eiEntryCount].target_cdg.iv_targetObjIndex = $objNum; \\\n";
            $eiEntryStr .= "  l_entries[$eiEntryCount].target_cdg.iv_callout = $callout; \\\n";
            $eiEntryStr .= "  l_entries[$eiEntryCount].target_cdg.iv_deconfigure = $deconf; \\\n";
            $eiEntryStr .= "  l_entries[$eiEntryCount].target_cdg.iv_gard = $gard; \\\n";
            $eiEntryStr .= "  l_entries[$eiEntryCount].target_cdg.iv_calloutPriority = fapi::CalloutPriorities::$priority; \\\n";
            $eiEntryCount++;
        }

        # Process the callout, deconfigures and GARDs for Child Targets
        foreach my $parent (keys %cdgChildHash)
        {
            # Check the type
            print EIFILE "fapi::fapiCheckType<const fapi::Target *>(&$parent); \\\n";

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
                }
                if (exists $cdgChildHash{$parent}->{$childType}->{childNumber})
                {
                    $childNumber =
                        $cdgChildHash{$parent}->{$childType}->{childNumber} ;
                }
                if (exists $cdgChildHash{$parent}->{$childType}->{gard})
                {
                    $gard = 1;
                }


                # Add the Target to the objectlist if it doesn't already exist
                my $objNum = addEntryToArray(\@eiObjects, $parent);

                # Add an EI entry to eiEntryStr
                $eiEntryStr .=
                    "  l_entries[$eiEntryCount].iv_type = fapi::ReturnCode::EI_TYPE_CHILDREN_CDG; \\\n";
                $eiEntryStr .=
                    "  l_entries[$eiEntryCount].children_cdg.iv_parentObjIndex = $objNum; \\\n";
                $eiEntryStr .=
                    "  l_entries[$eiEntryCount].children_cdg.iv_callout = $callout; \\\n";
                $eiEntryStr .=
                    "  l_entries[$eiEntryCount].children_cdg.iv_deconfigure = $deconf; \\\n";
                $eiEntryStr .=
                    "  l_entries[$eiEntryCount].children_cdg.iv_childType = fapi::$childType; \\\n";
                $eiEntryStr .=
                    "  l_entries[$eiEntryCount].children_cdg.iv_childPort = $childPort; \\\n";
                $eiEntryStr .=
                    "  l_entries[$eiEntryCount].children_cdg.iv_childNumber = $childNumber; \\\n";
                $eiEntryStr .=
                    "  l_entries[$eiEntryCount].children_cdg.iv_gard = $gard; \\\n";
                $eiEntryStr .=
                    "  l_entries[$eiEntryCount].children_cdg.iv_calloutPriority = fapi::CalloutPriorities::$priority; \\\n";
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
            $eiObjectStr .= "&$eiObject";
            $objCount++;
        }
        $eiObjectStr .= "};";

        # Print info to file
        if ($eiEntryCount > 0)
        {
            print EIFILE "\\\n{ \\\n  $eiObjectStr \\\n";
            print EIFILE "  fapi::ReturnCode::ErrorInfoEntry l_entries[$eiEntryCount]; \\\n";
            print EIFILE "$eiEntryStr";
            print EIFILE "  RC.addErrorInfo(l_objects, l_entries, $eiEntryCount); \\\n}";
        }
        print EIFILE "\n\n";
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
            print ("fapiParseErrorInfo.pl ERROR. id missing from registerFfdc\n");
            exit(1);
        }

        if (scalar @{$registerFfdc->{id}} > 1)
        {
            print ("fapiParseErrorInfo.pl ERROR. multiple ids in registerFfdc\n");
            exit(1);
        }

        #----------------------------------------------------------------------
        # Set the FFDC ID value in a global hash
        #----------------------------------------------------------------------
        setFfdcIdValue($registerFfdc->{id}[0]);

        #----------------------------------------------------------------------
        # Generate code to capture the registers in fapiCollectRegFfdc.C
        #----------------------------------------------------------------------
        print CRFILE "        case $registerFfdc->{id}[0]:\n";

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

        print CRFILE "            break;\n";
    }

}

#------------------------------------------------------------------------------
# Print end of file information to fapiCollectRegFfdc.C
#------------------------------------------------------------------------------
print CRFILE "        default:\n";
print CRFILE "            FAPI_ERR(\"fapiCollectRegFfdc.C: Invalid FFDC ID 0x%x\", ";
print CRFILE                     "i_ffdcId);\n";
print CRFILE "            return;\n";
print CRFILE "    }\n\n";
print CRFILE "    uint8_t * l_pBuf = NULL;\n";
print CRFILE "    uint8_t * l_pData = NULL;\n";
print CRFILE "    std::vector<fapi::Target> l_targets;\n";
print CRFILE "    uint32_t l_chipletPos32 = 0;\n";
#---------------------------------------------------------------------------------------------------------
# Populate chiplet vectors (if required by register collection method) and adjust buffer sizes accordingly
#---------------------------------------------------------------------------------------------------------
print CRFILE "    if (fapi::TARGET_TYPE_NONE != i_child)\n";
print CRFILE "    {\n";
print CRFILE "        l_rc = fapiGetChildChiplets(i_target, i_child, l_targets, TARGET_STATE_FUNCTIONAL);\n";
print CRFILE "        if (l_rc)\n";
print CRFILE "        {\n";
print CRFILE "            FAPI_ERR(\"fapiCollectRegFfdc.C: Error: fapiGetChildChiplets: failed to get chiplets.\");\n";
print CRFILE "            return;\n";
print CRFILE "        }\n";
print CRFILE "        if (l_targets.empty())\n";
print CRFILE "        {\n";
print CRFILE "            FAPI_INF(\"fapiCollectRegFfdc.C: Error: No functional chiplets found. \");\n";
print CRFILE "            return;\n";
print CRFILE "        }\n";
print CRFILE "        l_ffdcSize += sizeof(l_chipletPos32);\n";
print CRFILE "        l_ffdcSize *= l_targets.size();\n";
print CRFILE "        l_pBuf = new uint8_t[l_ffdcSize];\n";
print CRFILE "        l_pData = l_pBuf;\n";
print CRFILE "    }\n";
print CRFILE "    else if (fapi::TARGET_TYPE_NONE != i_presChild)\n";
print CRFILE "    {\n";
print CRFILE "        l_rc = fapiGetChildChiplets(i_target, i_presChild, l_targets, TARGET_STATE_PRESENT);\n";
print CRFILE "        if (l_rc)\n";
print CRFILE "        {\n";
print CRFILE "            FAPI_ERR(\"fapiCollectRegFfdc.C: Error: fapiGetChildChiplets: failed to get chiplets.\");\n";
print CRFILE "            return;\n";
print CRFILE "        }\n";
print CRFILE "        if (l_targets.empty())\n";
print CRFILE "        {\n";
print CRFILE "            FAPI_INF(\"fapiCollectRegFfdc.C: Error: No functional chiplets found. \");\n";
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
print CRFILE "        if ((fapi::TARGET_TYPE_NONE != i_child) ||\n";
print CRFILE "            (fapi::TARGET_TYPE_NONE != i_presChild) ||\n";
print CRFILE "            (true == l_targIsChiplet))\n";
print CRFILE "        {\n";
print CRFILE "            uint8_t l_chipletPos = 0;\n";
print CRFILE "            l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &(*targetIter), l_chipletPos);\n";
print CRFILE "            if (l_rc)\n";
print CRFILE "            {\n";
print CRFILE "                FAPI_ERR(\"fapiCollectRegFfdc.C: Error getting chiplet position\");\n";
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
print CRFILE "                FAPI_ERR(\"fapiCollectRegFfdc.C: Error getting chip position\");\n";
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
print CRFILE "            if (fapi::TARGET_TYPE_NONE != i_presChild)\n";
print CRFILE "            {\n";
print CRFILE "                l_rc = fapiGetCfamRegister(i_target, (*cfamIter + (l_chipletPos32 * i_childOffsetMult)), l_buf);\n";
print CRFILE "            }\n";
print CRFILE "            else\n";
print CRFILE "            {\n";
print CRFILE "                l_rc = fapiGetCfamRegister(*targetIter, *cfamIter, l_buf);\n";
print CRFILE "            }\n";
print CRFILE "            if (l_rc)\n";
print CRFILE "            {\n";
print CRFILE "                FAPI_ERR(\"fapiCollectRegFfdc.C: CFAM error for 0x%x\",";
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
print CRFILE "            if (fapi::TARGET_TYPE_NONE != i_presChild)\n";
print CRFILE "            {\n";
print CRFILE "                l_rc = fapiGetScom(i_target, (*scomIter + (l_chipletPos32 * i_childOffsetMult)), l_buf);\n";
print CRFILE "            }\n";
print CRFILE "            else\n";
print CRFILE "            {\n";
print CRFILE "                l_rc = fapiGetScom(*targetIter, *scomIter, l_buf);\n";
print CRFILE "            }\n";
print CRFILE "            if (l_rc)\n";
print CRFILE "            {\n";
print CRFILE "                FAPI_ERR(\"fapiCollectRegFfdc.C: SCOM error for 0x%llx\",";
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
print CRFILE "}\n";
print CRFILE "}\n";

#------------------------------------------------------------------------------
# Print the fapiHwpReturnCodes.H file
#------------------------------------------------------------------------------
print RCFILE "// fapiHwpReturnCodes.H\n";
print RCFILE "// This file is generated by perl script fapiParseErrorInfo.pl\n\n";
print RCFILE "#ifndef FAPIHWPRETURNCODES_H_\n";
print RCFILE "#define FAPIHWPRETURNCODES_H_\n\n";
print RCFILE "#ifndef __ASSEMBLER__\n";
print RCFILE "namespace fapi\n";
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
# Print the HwpFfdcId enumeration to fapiHwpErrorInfo.H
#------------------------------------------------------------------------------
print EIFILE "namespace fapi\n";
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
# Print end of file information to fapiHwpErrorInfo.H
#------------------------------------------------------------------------------
print EIFILE "\n\n#endif\n";

#------------------------------------------------------------------------------
# Print end of file information to fapiSetSbeError.H
#------------------------------------------------------------------------------
print SBFILE "    default:\\\n";
print SBFILE "        FAPI_SET_HWP_ERROR(RC, RC_SBE_UNKNOWN_ERROR);\\\n";
print SBFILE "        break;\\\n";
print SBFILE "}\n\n";
print SBFILE "#endif\n";

#------------------------------------------------------------------------------
# Close output files
#------------------------------------------------------------------------------
close(RCFILE);
close(EIFILE);
close(CRFILE);
close(SBFILE);
