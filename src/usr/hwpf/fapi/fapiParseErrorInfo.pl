#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/fapi/fapiParseErrorInfo.pl $
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
#
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
#
# End Change Log ******************************************************

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
# Subroutine that figures out an FFDC enum value from an FFDC name and stores
# it in global hashes
#------------------------------------------------------------------------------
sub setFfdcEnumValue
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
print CRFILE "#include <fapiPlatTrace.H>\n\n";
print CRFILE "namespace fapi\n";
print CRFILE "{\n";
print CRFILE "void fapiCollectRegFfdc(const fapi::Target & i_target,\n";
print CRFILE "                        const fapi::HwpFfdcId i_ffdcId,\n";
print CRFILE "                        fapi::ReturnCode & o_rc)\n";
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
         'registerFfdc', 'collectRegisterFfdc', 'cfamRegister', 'scomRegister']);

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
            print ("fapiParseErrorInfo.pl ERROR. description missing\n");
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
            if (! exists $collectRegisterFfdc->{id})
            {
                print ("fapiParseErrorInfo.pl ERROR. id missing from collectRegisterFfdc\n");
                exit(1);
            }

            if (! exists $collectRegisterFfdc->{target})
            {
                print ("fapiParseErrorInfo.pl ERROR. target missing from collectRegisterFfdc\n");
                exit(1);
            }

            print EIFILE "fapiCollectRegFfdc($collectRegisterFfdc->{target}, ";
            print EIFILE "fapi::$collectRegisterFfdc->{id}, RC); ";
        }

        print EIFILE "\n";

        #----------------------------------------------------------------------
        # Print the ADD_ERROR_INFO macro to fapiHwpErrorInfo.H
        #----------------------------------------------------------------------
        print EIFILE "#define $err->{rc}_ADD_ERROR_INFO(RC) ";

        # Array of EI Objects
        my @eiObjects;

        my $eiObjectStr = "const void * l_objects[] = {";
        my $eiEntryStr = "fapi::ReturnCode::ErrorInfoEntry l_entries[] = {";
        my $eiEntryCount = 0;

        # Local FFDC
        foreach my $ffdc (@{$err->{ffdc}})
        {
            # Set the FFDC enum value in a global hash. The name is <rc>_<ffdc>
            my $ffdcName = $err->{rc} . "_";
            $ffdcName = $ffdcName . $ffdc;
            setFfdcEnumValue($ffdcName);

            # Add the FFDC data to the EI Object array if it doesn't already exist
            my $objNum = addEntryToArray(\@eiObjects, $ffdc);

            # Add an EI entry to eiEntryStr.
            if ($eiEntryCount > 0)
            {
                $eiEntryStr .= ", ";
            }
            $eiEntryStr .= "{fapi::ReturnCode::EI_TYPE_FFDC, $objNum, fapi::ReturnCodeFfdc::getErrorInfoFfdcSize($ffdc), fapi::$ffdcName}";
            $eiEntryCount++;
        }

        # Target callouts
        foreach my $callout (@{$err->{callout}})
        {
            if (! exists $callout->{target})
            {
                print ("fapiParseErrorInfo.pl ERROR. Callout target missing\n");
                exit(1);
            }

            if (! exists $callout->{priority})
            {
                print ("fapiParseErrorInfo.pl ERROR. Callout priority missing\n");
                exit(1);
            }

            # Check the type
            print EIFILE "fapi::fapiCheckType<const fapi::Target *>(&$callout->{target}); ";

            # Add the Target to the objectlist if it doesn't already exist
            my $objNum = addEntryToArray(\@eiObjects, $callout->{target});

            # Add an EI entry to eiEntryStr
            if ($eiEntryCount > 0)
            {
                $eiEntryStr .= ", ";
            }
            $eiEntryStr .= "{fapi::ReturnCode::EI_TYPE_CALLOUT, $objNum, fapi::PRI_$callout->{priority}, 0}";
            $eiEntryCount++;
        }

        # Target deconfigures
        foreach my $deconfigure (@{$err->{deconfigure}})
        {
            if (! exists $deconfigure->{target})
            {
                print ("fapiParseErrorInfo.pl ERROR. Deconfigure target missing\n");
                exit(1);
            }

            # Check the type
            print EIFILE "fapi::fapiCheckType<const fapi::Target *>(&$deconfigure->{target}); ";

            # Add the Target to the objectlist if it doesn't already exist
            my $objNum = addEntryToArray(\@eiObjects, $deconfigure->{target});

            # Add an EI entry to eiEntryStr
            if ($eiEntryCount > 0)
            {
                $eiEntryStr .= ", ";
            }
            $eiEntryStr .= "{fapi::ReturnCode::EI_TYPE_DECONF, $objNum, 0, 0}";
            $eiEntryCount++;
        }

        # Target Gards
        foreach my $gard (@{$err->{gard}})
        {
            if (! exists $gard->{target})
            {
                print ("fapiParseErrorInfo.pl ERROR. Gard target missing\n");
                exit(1);
            }

            # Check the type
            print EIFILE "fapi::fapiCheckType<const fapi::Target *>(&$gard->{target}); ";

            # Add the Target to the objectlist if it doesn't already exist
            my $objNum = addEntryToArray(\@eiObjects, $gard->{target});

            # Add an EI entry to eiEntryStr
            if ($eiEntryCount > 0)
            {
                $eiEntryStr .= ", ";
            }
            $eiEntryStr .= "{fapi::ReturnCode::EI_TYPE_GARD, $objNum, 0, 0}";
            $eiEntryCount++;
        }

        # Complete $eiEntryStr
        $eiEntryStr .= "};";

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
            print EIFILE "{$eiObjectStr $eiEntryStr ";
            print EIFILE "RC.addErrorInfo(l_objects, l_entries, $eiEntryCount);}";
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
        if (! exists $registerFfdc->{id})
        {
            print ("fapiParseErrorInfo.pl ERROR. id missing from registerFfdc\n");
            exit(1);
        }

        #----------------------------------------------------------------------
        # Set the FFDC enum value in a global hash
        #----------------------------------------------------------------------
        setFfdcEnumValue($registerFfdc->{id});

        #----------------------------------------------------------------------
        # Generate code to capture the registers in fapiCollectRegFfdc.C
        #----------------------------------------------------------------------
        print CRFILE "        case $registerFfdc->{id}:\n";

        # Look for CFAM Register addresses
        foreach my $cfamRegister (@{$registerFfdc->{cfamRegister}})
        {
            # Extract the address
            if ($cfamRegister =~ m/(0x[\dA-Fa-f]+)/)
            {
                print CRFILE "            l_cfamAddresses.push_back($1);\n";
                print CRFILE "            l_ffdcSize += sizeof(l_cfamData);\n";
            }
            else
            {
                print ("fapiParseErrorInfo.pl ERROR. CFAM address bad: $cfamRegister\n");
                exit(1);
            }
        }

        # Look for SCOM Register addresses
        foreach my $scomRegister (@{$registerFfdc->{scomRegister}})
        {
            # Extract the address
            if ($scomRegister =~ m/(0x[\dA-Fa-f]+)/)
            {
                print CRFILE "            l_scomAddresses.push_back($1ULL);\n";
                print CRFILE "            l_ffdcSize += sizeof(l_scomData);\n";
            }
            else
            {
                print ("fapiParseErrorInfo.pl ERROR. SCOM address bad: $scomRegister\n");
                exit(1);
            }
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
print CRFILE "    uint8_t * l_pBuf = new uint8_t[l_ffdcSize];\n";
print CRFILE "    uint8_t * l_pData = l_pBuf;\n\n";
print CRFILE "    for (std::vector<uint32_t>::const_iterator cfamIter = l_cfamAddresses.begin();\n";
print CRFILE "         cfamIter != l_cfamAddresses.end(); ++cfamIter)\n";
print CRFILE "    {\n";
print CRFILE "        l_rc = fapiGetCfamRegister(i_target, *cfamIter, l_buf);\n";
print CRFILE "        if (l_rc)\n";
print CRFILE "        {\n";
print CRFILE "            FAPI_ERR(\"fapiCollectRegFfdc.C: CFAM error for 0x%x\",";
print CRFILE                     "*cfamIter);\n";
print CRFILE "            l_cfamData = 0xbaddbadd;\n";
print CRFILE "        }\n";
print CRFILE "        else\n";
print CRFILE "        {\n";
print CRFILE "            l_cfamData = l_buf.getWord(0);\n";
print CRFILE "        }\n";
print CRFILE "        *(reinterpret_cast<uint32_t *>(l_pData)) = l_cfamData;\n";
print CRFILE "        l_pData += sizeof(l_cfamData);\n";
print CRFILE "    }\n\n";
print CRFILE "    for (std::vector<uint64_t>::const_iterator scomIter = l_scomAddresses.begin();\n";
print CRFILE "         scomIter != l_scomAddresses.end(); ++scomIter)\n";
print CRFILE "    {\n";
print CRFILE "        l_rc = fapiGetScom(i_target, *scomIter, l_buf);\n";
print CRFILE "        if (l_rc)\n";
print CRFILE "        {\n";
print CRFILE "            FAPI_ERR(\"fapiCollectRegFfdc.C: SCOM error for 0x%llx\",";
print CRFILE                     "*scomIter);\n";
print CRFILE "            l_scomData = 0xbaddbaddbaddbaddULL;\n";
print CRFILE "        }\n";
print CRFILE "        else\n";
print CRFILE "        {\n";
print CRFILE "            l_scomData = l_buf.getDoubleWord(0);\n";
print CRFILE "        }\n";
print CRFILE "        *(reinterpret_cast<uint64_t *>(l_pData)) = l_scomData;\n";
print CRFILE "        l_pData += sizeof(l_scomData);\n";
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
print SBFILE "        RC.setFapiError(fapi::FAPI_RC_UNRECOGNIZED_SBE_ERROR);\\\n";
print SBFILE "        RC.addEIFfdc(0, &ERRVAL, sizeof(ERRVAL));\\\n";
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
