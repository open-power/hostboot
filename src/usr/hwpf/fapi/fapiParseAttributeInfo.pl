#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/fapi/fapiParseAttributeInfo.pl $
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
# Purpose:  This perl script will parse HWP Attribute XML files
# and add attribute information to a file called fapiAttributeIds.H
#
# Author: CamVan Nguyen
# Last Updated: 06/23/2011
#
# Version: 1.0
#
# Change Log **********************************************************
#
#  Flag  Track#    Userid    Date      Description
#  ----  --------  --------  --------  -----------
#                  camvanng  06/03/11  Created
#                  mjjones   06/06/11  Minor updates for integration
#                  mjjones   06/10/11  Added "use strict;"
#                  mjjones   06/23/11  Parse more info
#                  mjjones   07/05/11  Take output dir as parameter
#                  mjjones   09/06/11  Remove string/defaultVal support 
#                  mjjones   10/07/11  Create fapiAttributeService.C
#                  mjjones   10/17/11  Support enums with values
#                  mjjones   10/18/11  Support multiple attr files and
#                                      multi-line descriptions
#                  camvanng  10/20/11  Changed i_pTarget to "const" ptr
#                  camvanng  11/09/11  Prepend "ENUM_" to attribute
#                                      enums
#                  mjjones   11/15/11  Move gen of fapiAttributeService.C
#                                      to a different file
#                  mjjones   12/16/11  Generate fapiAttributePlatCheck.H
#                                      Generate fapiAttributesSupported.html
#                  mjjones   02/08/12  Handle attribute files with 1 entry
#                  mjjones   03/22/12  Generate hash values for enums
#                  mjjones   04/10/12  Process Chip EC Feature attributes
#                  mjjones   05/15/12  Detect duplicate attr ids and append
#                                      ULL after 64bit enumerator
#                  mjjones   05/21/12  Detect duplicate ids/hashes across files
#                  mjjones   05/21/12  Ignore newlines and whitespace when
#                                      parsing enumerations
#                  mjjones   06/12/12  Add new include file to fapiChipEcFeature.C
#                  mjjones   08/08/12  Output target types and if PlatInit
#                  mjjones   09/28/12  Minor change to add FFDC on error
#                  mjjones   11/05/12  Generate fapiAttributeIds.txt
#                                      Generate fapiAttributeEnums.txt
#                  mjjones   03/21/13  Add fapi namespace to Chip EC Feature macro
#                  mjjones   02/27/13  Generate fapiAttrInfo.csv
#                                      Generate fapiAttrEnumInfo.csv
#                  mjjones   04/11/13  Allow platform to override Chip EC Feature
#
# End Change Log ******************************************************

use strict;

#------------------------------------------------------------------------------
# Print Command Line Help
#------------------------------------------------------------------------------
my $numArgs = $#ARGV + 1;
if ($numArgs < 2)
{
    print ("Usage: fapiParseAttributeInfo.pl <output dir> <attr-xml-file1> [<attr-xml-file2> ...]\n");
    print ("  This perl script will parse attribute XML files and create the following files:\n");
    print ("  - fapiAttributeIds.H.          Contains IDs, type, value enums and other information\n");
    print ("  - fapiChipEcFeature.C.         Contains a function to query chip EC features\n");
    print ("  - fapiAttributePlatCheck.H.    Contains compile time checks that all attributes are\n");
    print ("                                 handled by the platform\n");
    print ("  - fapiAttributesSupported.html Contains the HWPF attributes supported\n");
    print ("  - fapiAttrInfo.csv             Used to process Attribute Override Text files\n");
    print ("  - fapiAttrEnumInfo.csv         Used to process Attribute Override Text files\n");
    exit(1);
}

#------------------------------------------------------------------------------
# Specify perl modules to use
#------------------------------------------------------------------------------
use Digest::MD5 qw(md5_hex);
use XML::Simple;
my $xml = new XML::Simple (KeyAttr=>[]);

# Uncomment to enable debug output
#use Data::Dumper;

#------------------------------------------------------------------------------
# Set PREFERRED_PARSER to XML::Parser. Otherwise it uses XML::SAX which contains
# bugs that result in XML parse errors that can be fixed by adjusting white-
# space (i.e. parse errors that do not make sense).
#------------------------------------------------------------------------------
$XML::Simple::PREFERRED_PARSER = 'XML::Parser';

#------------------------------------------------------------------------------
# Open output files for writing
#------------------------------------------------------------------------------
my $aiFile = $ARGV[0];
$aiFile .= "/";
$aiFile .= "fapiAttributeIds.H";
open(AIFILE, ">", $aiFile);

my $ecFile = $ARGV[0];
$ecFile .= "/";
$ecFile .= "fapiChipEcFeature.C";
open(ECFILE, ">", $ecFile);

my $acFile = $ARGV[0];
$acFile .= "/";
$acFile .= "fapiAttributePlatCheck.H";
open(ACFILE, ">", $acFile);

my $asFile = $ARGV[0];
$asFile .= "/";
$asFile .= "fapiAttributesSupported.html";
open(ASFILE, ">", $asFile);

my $itFile = $ARGV[0];
$itFile .= "/";
$itFile .= "fapiAttrInfo.csv";
open(ITFILE, ">", $itFile);

my $etFile = $ARGV[0];
$etFile .= "/";
$etFile .= "fapiAttrEnumInfo.csv";
open(ETFILE, ">", $etFile);

#------------------------------------------------------------------------------
# Print Start of file information to fapiAttributeIds.H
#------------------------------------------------------------------------------
print AIFILE "// fapiAttributeIds.H\n";
print AIFILE "// This file is generated by perl script fapiParseAttributeInfo.pl\n\n";
print AIFILE "#ifndef FAPIATTRIBUTEIDS_H_\n";
print AIFILE "#define FAPIATTRIBUTEIDS_H_\n\n";
print AIFILE "#include <fapiTarget.H>\n\n";
print AIFILE "namespace fapi\n";
print AIFILE "{\n\n";
print AIFILE "\/**\n";
print AIFILE " * \@brief Enumeration of attribute IDs\n";
print AIFILE " *\/\n";
print AIFILE "enum AttributeId\n{\n";

#------------------------------------------------------------------------------
# Print Start of file information to fapiChipEcFeature.C
#------------------------------------------------------------------------------
print ECFILE "// fapiChipEcFeature.C\n";
print ECFILE "// This file is generated by perl script fapiParseAttributeInfo.pl\n";
print ECFILE "// It implements the fapiQueryChipEcFeature function\n\n";
print ECFILE "#include <fapiChipEcFeature.H>\n";
print ECFILE "#include <fapiAttributeService.H>\n";
print ECFILE "#include <fapiPlatTrace.H>\n\n";
print ECFILE "namespace fapi\n";
print ECFILE "{\n\n";
print ECFILE "fapi::ReturnCode fapiQueryChipEcFeature(fapi::AttributeId i_id,\n";
print ECFILE "                                        const fapi::Target * i_pTarget,\n";
print ECFILE "                                        uint8_t & o_hasFeature)\n";
print ECFILE "{\n";
print ECFILE "    o_hasFeature = false;\n";
print ECFILE "    fapi::ReturnCode l_rc;\n";
print ECFILE "    uint8_t l_chipName = 0;\n";
print ECFILE "    uint8_t l_chipEc = 0;\n\n";
print ECFILE "    l_rc = FAPI_ATTR_GET_PRIVILEGED(ATTR_NAME, i_pTarget, l_chipName);\n\n";
print ECFILE "    if (l_rc)\n";
print ECFILE "    {\n";
print ECFILE "        FAPI_ERR(\"fapiQueryChipEcFeature: error getting chip name\");\n";
print ECFILE "    }\n";
print ECFILE "    else\n";
print ECFILE "    {\n";
print ECFILE "        l_rc = FAPI_ATTR_GET_PRIVILEGED(ATTR_EC, i_pTarget, l_chipEc);\n\n";
print ECFILE "        if (l_rc)\n";
print ECFILE "        {\n";
print ECFILE "            FAPI_ERR(\"fapiQueryChipEcFeature: error getting chip ec\");\n";
print ECFILE "        }\n";
print ECFILE "        else\n";
print ECFILE "        {\n";
print ECFILE "            switch (i_id)\n";
print ECFILE "            {\n";

#------------------------------------------------------------------------------
# Print Start of file information to fapiAttributePlatCheck.H
#------------------------------------------------------------------------------
print ACFILE "// fapiAttributePlatCheck.H\n";
print ACFILE "// This file is generated by perl script fapiParseAttributeInfo.pl\n";
print ACFILE "// A platform can include it to ensure that it handles all HWPF\n";
print ACFILE "// attributes\n\n";
print ACFILE "#ifndef FAPIATTRIBUTEPLATCHECK_H_\n";
print ACFILE "#define FAPIATTRIBUTEPLATCHECK_H_\n\n";

#------------------------------------------------------------------------------
# Print Start of file information to fapiAttributesSupported.html
#------------------------------------------------------------------------------
print ASFILE "<html>\n";
print ASFILE "<body>\n\n";
print ASFILE "<!-- fapiAttributesSupported.html -->\n";
print ASFILE "<!-- This file is generated by perl script fapiParseAttributeInfo.pl -->\n";
print ASFILE "<!-- It lists all HWPF attributes supported -->\n\n";
print ASFILE "<h4>HWPF Attributes supported by this build.</h4>\n";
print ASFILE "<table border=\"4\">\n";
print ASFILE "<tr><th>Attribute ID</th><th>Attribute Description</th></tr>";

#------------------------------------------------------------------------------
# Print Start of file information to fapiAttrInfo.csv
#------------------------------------------------------------------------------
print ITFILE "# fapiAttrInfo.csv\n";
print ITFILE "# This file is generated by perl script fapiParseAttributeInfo.pl\n";
print ITFILE "# It lists information about FAPI attributes and is used to\n";
print ITFILE "# process FAPI Attribute text files (overrides/syncs)\n";
print ITFILE "# Format:\n";
print ITFILE "# <FAPI-ATTR-ID-STR>,<LAYER-ATTR-ID-STR>,<ATTR-ID-VAL>,<ATTR-TYPE>\n";
print ITFILE "# Note that for the AttributeTanks at the FAPI layer, the\n";
print ITFILE "# FAPI-ATTR-ID-STR and LAYER-ATTR-ID-STR will be identical\n";

#------------------------------------------------------------------------------
# Print Start of file information to fapiAttrEnumInfo.csv
#------------------------------------------------------------------------------
print ETFILE "# fapiAttrEnumInfo.csv\n";
print ETFILE "# This file is generated by perl script fapiParseAttributeInfo.pl\n";
print ETFILE "# It lists information about FAPI attribute enumeratorss and is\n";
print ETFILE "# used to process FAPI Attribute text files (overrides/syncs)\n";
print ETFILE "# Format:\n";
print ETFILE "# <ENUM-STR>,<ENUM-VAL>\n";

my %attrIdHash;  # Records which Attribute IDs have been used
my %attrValHash; # Records which Attribute values have been used

#------------------------------------------------------------------------------
# For each XML file
#------------------------------------------------------------------------------
foreach my $argnum (1 .. $#ARGV)
{
    my $infile = $ARGV[$argnum];

    # read XML file. The ForceArray option ensures that there is an array of
    # elements even if there is only one such element in the file
    my $attributes = $xml->XMLin($infile, ForceArray => ['attribute']);

    # Uncomment to get debug output of all attributes
    #print "\nFile: ", $infile, "\n", Dumper($attributes), "\n";

    #--------------------------------------------------------------------------
    # For each Attribute
    #--------------------------------------------------------------------------
    foreach my $attr (@{$attributes->{attribute}})
    {
        #----------------------------------------------------------------------
        # Print the Attribute ID and calculated value to fapiAttributeIds.H and
        # fapiAttributeIds.txt. The value for an attribute is a hash value
        # generated from the attribute name, this ties a specific value to a
        # specific attribute name. This is done for Cronus so that if a HWP is
        # not recompiled against a new eCMD/Cronus version where the attributes
        # have changed then there will not be a mismatch in enumerator values.
        # This is a 28bit hash value because the Initfile compiler has a
        # requirement that the top nibble of the 32 bit attribute ID be zero to
        # store flags
        #----------------------------------------------------------------------
        if (! exists $attr->{id})
        {
            print ("fapiParseAttributeInfo.pl ERROR. Att 'id' missing\n");
            exit(1);
        }

        if (exists($attrIdHash{$attr->{id}}))
        {
            # Two different attributes with the same id!
            print ("fapiParseAttributeInfo.pl ERROR. Duplicate attr id ",
                $attr->{id}, "\n");
            exit(1);
        }

        # Calculate a 28 bit hash value.
        my $attrHash128Bit = md5_hex($attr->{id});
        my $attrHash28Bit = substr($attrHash128Bit, 0, 7);

        # Print the attribute ID/value to fapiAttributeIds.H
        print AIFILE "    $attr->{id} = 0x$attrHash28Bit,\n";

        if (exists($attrValHash{$attrHash28Bit}))
        {
            # Two different attributes generate the same hash-value!
            print ("fapiParseAttributeInfo.pl ERROR. Duplicate attr id hash value for ",
                   $attr->{id}, "\n");
            exit(1);
        }

        $attrIdHash{$attr->{id}} = $attrHash28Bit;
        $attrValHash{$attrHash28Bit} = 1;
    };
}

#------------------------------------------------------------------------------
# Print AttributeId enumeration end to fapiAttributeIds.H
#------------------------------------------------------------------------------
print AIFILE "};\n\n";

#------------------------------------------------------------------------------
# Print Attribute Information comment to fapiAttributeIds.H
#------------------------------------------------------------------------------
print AIFILE "\/**\n";
print AIFILE " * \@brief Attribute Information\n";
print AIFILE " *\/\n";

#------------------------------------------------------------------------------
# For each XML file
#------------------------------------------------------------------------------
foreach my $argnum (1 .. $#ARGV)
{
    my $infile = $ARGV[$argnum];

    # read XML file. The ForceArray option ensures that there is an array of
    # elements even if there is only one such element in the file
    my $attributes = $xml->XMLin($infile, ForceArray => ['attribute', 'chip']);

    #--------------------------------------------------------------------------
    # For each Attribute
    #--------------------------------------------------------------------------
    foreach my $attr (@{$attributes->{attribute}})
    {
        #----------------------------------------------------------------------
        # Print a comment with the attribute ID fapiAttributeIds.H
        #----------------------------------------------------------------------
        print AIFILE "/* $attr->{id} */\n";

        #----------------------------------------------------------------------
        # Print the AttributeId and description to fapiAttributesSupported.html
        #----------------------------------------------------------------------
        if (! exists $attr->{description})
        {
            print ("fapiParseAttributeInfo.pl ERROR. Att 'description' missing\n");
            exit(1);
        }

        print ASFILE "<tr>\n";
        print ASFILE "  <td>$attr->{id}</td>\n";
        print ASFILE "  <td>$attr->{description}</td>\n";
        print ASFILE "</tr>\n";

        #----------------------------------------------------------------------
        # Figure out the attribute array dimensions (if array)
        #----------------------------------------------------------------------
        my $arrayDimensions = "";
        my $numArrayDimensions = 0;
        if ($attr->{array})
        {
            # Remove leading whitespace
            my $dimText = $attr->{array};
            $dimText =~ s/^\s+//;

            # Split on commas or whitespace
            my @vals = split(/\s*,\s*|\s+/, $dimText);

            foreach my $val (@vals)
            {
                $arrayDimensions .= "[${val}]";
                $numArrayDimensions++;
            }
        }

        #----------------------------------------------------------------------
        # Print the typedef for each attribute's val type to fapiAttributeIds.H
        # Print the attribute information to fapiAttrInfo.csv
        #----------------------------------------------------------------------
        if (exists $attr->{chipEcFeature})
        {
            # The value type of chip EC feature attributes is uint8_t
            print AIFILE "typedef uint8_t $attr->{id}_Type;\n";
            print ITFILE "$attr->{id},$attr->{id},0x$attrIdHash{$attr->{id}},u8\n"
        }
        else
        {
            if (! exists $attr->{valueType})
            {
                print ("fapiParseAttributeInfo.pl ERROR. Att 'valueType' missing\n");
                exit(1);
            }

            if ($attr->{valueType} eq 'uint8')
            {
                print AIFILE "typedef uint8_t $attr->{id}_Type$arrayDimensions;\n";
                print ITFILE "$attr->{id},$attr->{id},0x$attrIdHash{$attr->{id}},u8" .
                             "$arrayDimensions\n";
            }
            elsif ($attr->{valueType} eq 'uint32')
            {
                print AIFILE "typedef uint32_t $attr->{id}_Type$arrayDimensions;\n";
                print ITFILE "$attr->{id},$attr->{id},0x$attrIdHash{$attr->{id}},u32" .
                             "$arrayDimensions\n";
            }
            elsif ($attr->{valueType} eq 'uint64')
            {
                print AIFILE "typedef uint64_t $attr->{id}_Type$arrayDimensions;\n";
                print ITFILE "$attr->{id},$attr->{id},0x$attrIdHash{$attr->{id}},u64" .
                             "$arrayDimensions\n";
            }
            else
            {
                print ("fapiParseAttributeInfo.pl ERROR. valueType not recognized: ");
                print $attr->{valueType}, "\n";
                exit(1);
            }
        }

        #----------------------------------------------------------------------
        # Print if the attribute is privileged
        #----------------------------------------------------------------------
        if (exists $attr->{privileged})
        {
            print AIFILE "const bool $attr->{id}_Privileged = true;\n";
        }
        else
        {
            print AIFILE "const bool $attr->{id}_Privileged = false;\n";
        }

        #----------------------------------------------------------------------
        # Print the target type(s) that the attribute is associated with
        #----------------------------------------------------------------------
        if (! exists $attr->{targetType})
        {
            print ("fapiParseAttributeInfo.pl ERROR. Att 'targetType' missing\n");
            exit(1);
        }

        print AIFILE "const TargetTypes_t $attr->{id}_TargetTypes = ";

        # Split on commas
        my @targTypes = split(',', $attr->{targetType});

        my $targTypeCount = 0;
        foreach my $targType (@targTypes)
        {
            # Remove newlines and leading/trailing whitespace
            $targType =~ s/\n//;
            $targType =~ s/^\s+//;
            $targType =~ s/\s+$//;

            if ($targTypeCount != 0)
            {
                print AIFILE " | ";
            }
            print AIFILE "$targType";
            $targTypeCount++;
        }
        print AIFILE ";\n";

        #----------------------------------------------------------------------
        # Print if the attribute is a platInit attribute
        #----------------------------------------------------------------------
        if (exists $attr->{platInit})
        {
            print AIFILE "const bool $attr->{id}_PlatInit = true;\n";
        }
        else
        {
            print AIFILE "const bool $attr->{id}_PlatInit = false;\n";
        }

        #----------------------------------------------------------------------
        # Print the value enumeration (if specified) to fapiAttributeIds.H and
        # fapiAttributeEnums.txt
        #----------------------------------------------------------------------
        if (exists $attr->{enum})
        {
            print AIFILE "enum $attr->{id}_Enum\n{\n";

            # Values must be separated by commas to allow for values to be
            # specified: <enum>VAL_A = 3, VAL_B = 5, VAL_C = 0x23</enum>
            my @vals = split(',', $attr->{enum});

            foreach my $val (@vals)
            {
                # Remove newlines and leading/trailing whitespace
                $val =~ s/\n//;
                $val =~ s/^\s+//;
                $val =~ s/\s+$//;

                # Print the attribute enum to fapiAttributeIds.H
                print AIFILE "    ENUM_$attr->{id}_${val}";

                # Print the attribute enum to fapiAttrEnumInfo.csv
                my $attrEnumTxt = "$attr->{id}_${val}\n";
                $attrEnumTxt =~ s/ = /,/;
                print ETFILE $attrEnumTxt;

                if ($attr->{valueType} eq 'uint64')
                {
                    print AIFILE "ULL";
                }

                print AIFILE ",\n";
            }

            print AIFILE "};\n";
        }

        #----------------------------------------------------------------------
        # Print _GETMACRO and _SETMACRO where appropriate to fapiAttributeIds.H
        #----------------------------------------------------------------------
        if (exists $attr->{chipEcFeature})
        {
            #------------------------------------------------------------------
            # The attribute is a Chip EC Feature, define _GETMACRO to call a
            # fapi function and define _SETMACRO to something that will cause a
            # compile failure if a set is attempted
            #------------------------------------------------------------------
            print AIFILE "#define $attr->{id}_GETMACRO(ID, PTARGET, VAL) \\\n";
            print AIFILE "    PLAT_GET_CHIP_EC_FEATURE_OVERRIDE(ID, PTARGET, VAL) ? fapi::FAPI_RC_SUCCESS : \\\n";
            print AIFILE "    fapi::fapiQueryChipEcFeature(fapi::ID, PTARGET, VAL)\n";
            print AIFILE "#define $attr->{id}_SETMACRO(ID, PTARGET, VAL) ";
            print AIFILE "CHIP_EC_FEATURE_ATTRIBUTE_NOT_WRITABLE\n";
        }
        elsif (! exists $attr->{writeable})
        {
            #------------------------------------------------------------------
            # The attribute is read-only, define the _SETMACRO to something
            # that will cause a compile failure if a set is attempted
            #------------------------------------------------------------------
            if (! exists $attr->{writeable})
            {
                print AIFILE "#define $attr->{id}_SETMACRO ATTRIBUTE_NOT_WRITABLE\n";
            }
        }

        #----------------------------------------------------------------------
        # If the attribute is a Chip EC Feature, print the chip EC feature
        # query to fapiChipEcFeature.C
        #----------------------------------------------------------------------
        if (exists $attr->{chipEcFeature})
        {
            my $chipCount = 0;
            print ECFILE "            case $attr->{id}:\n";
            print ECFILE "                if (\n";

            foreach my $chip (@{$attr->{chipEcFeature}->{chip}})
            {
                $chipCount++;

                if (! exists $chip->{name})
                {
                    print ("fapiParseAttributeInfo.pl ERROR. Att 'name' missing\n");
                    exit(1);
                }

                if (! exists $chip->{ec})
                {
                    print ("fapiParseAttributeInfo.pl ERROR. Att 'ec' missing\n");
                    exit(1);
                }

                if (! exists $chip->{ec}->{value})
                {
                    print ("fapiParseAttributeInfo.pl ERROR. Att 'value' missing\n");
                    exit(1);
                }

                if (! exists $chip->{ec}->{test})
                {
                    print ("fapiParseAttributeInfo.pl ERROR. Att 'test' missing\n");
                    exit(1);
                }

                my $test;
                if ($chip->{ec}->{test} eq 'EQUAL')
                {
                    $test = '==';
                }
                elsif ($chip->{ec}->{test} eq 'GREATER_THAN')
                {
                    $test = '>';
                }
                elsif ($chip->{ec}->{test} eq 'GREATER_THAN_OR_EQUAL')
                {
                    $test = '>=';
                }
                elsif ($chip->{ec}->{test} eq 'LESS_THAN')
                {
                    $test = '<';
                }
                elsif ($chip->{ec}->{test} eq 'LESS_THAN_OR_EQUAL')
                {
                    $test = '<=';
                }
                else
                {
                    print ("fapiParseAttributeInfo.pl ERROR. test '$chip->{ec}->{test}' unrecognized\n");
                    exit(1);
                }

                if ($chipCount > 1)
                {
                    print ECFILE "                ||\n";
                }
                print ECFILE "                    ((l_chipName == $chip->{name}) &&\n";
                print ECFILE "                     (l_chipEc $test $chip->{ec}->{value}))\n";
            }

            print ECFILE "                   )\n";
            print ECFILE "                {\n";
            print ECFILE "                    o_hasFeature = true;\n";
            print ECFILE "                }\n";
            print ECFILE "                break;\n";
        }

        #----------------------------------------------------------------------
        # Print the platform attribute checks to fapiAttributePlatCheck.H
        #----------------------------------------------------------------------
        if (exists $attr->{writeable})
        {
            print ACFILE "#ifndef $attr->{id}_SETMACRO\n";
            print ACFILE "#error Platform does not support set of HWPF attr $attr->{id}\n";
            print ACFILE "#endif\n";
        }

        print ACFILE "#ifndef $attr->{id}_GETMACRO\n";
        print ACFILE "#error Platform does not support get of HWPF attr $attr->{id}\n";
        print ACFILE "#endif\n\n";

        #----------------------------------------------------------------------
        # Print newline between each attribute's info to fapiAttributeIds.H
        #----------------------------------------------------------------------
        print AIFILE "\n";
    };
}

#------------------------------------------------------------------------------
# Print End of file information to fapiAttributeIds.H
#------------------------------------------------------------------------------
print AIFILE "}\n\n";
print AIFILE "#endif\n";

#------------------------------------------------------------------------------
# Print End of file information to fapiChipEcFeature.C
#------------------------------------------------------------------------------
print ECFILE "            default:\n";
print ECFILE "                FAPI_ERR(\"fapiQueryChipEcFeature: Unknown feature 0x%x\",\n";
print ECFILE "                    i_id);\n";
print ECFILE "                l_rc.setFapiError(FAPI_RC_INVALID_CHIP_EC_FEATURE_GET);\n";
print ECFILE "                l_rc.addEIFfdc(0, &i_id, sizeof(i_id));\n";
print ECFILE "                break;\n";
print ECFILE "            }\n\n";
print ECFILE "            if (o_hasFeature)\n";
print ECFILE "            {\n";
print ECFILE "                FAPI_INF(\"fapiQueryChipEcFeature: Chip (0x%x:0x%x) has ";
print ECFILE "feature (0x%x)\", l_chipName, l_chipEc, i_id);\n";
print ECFILE "            }\n";
print ECFILE "            else\n";
print ECFILE "            {\n";
print ECFILE "                FAPI_INF(\"fapiQueryChipEcFeature: Chip (0x%x:0x%x) does not ";
print ECFILE "have feature (0x%x)\", l_chipName, l_chipEc, i_id);\n";
print ECFILE "            }\n";
print ECFILE "        }\n";
print ECFILE "    }\n";
print ECFILE "    return l_rc;\n";
print ECFILE "}\n\n";
print ECFILE "}\n";


#------------------------------------------------------------------------------
# Print End of file information to fapiAttributePlatCheck.H
#------------------------------------------------------------------------------
print ACFILE "#endif\n";

#------------------------------------------------------------------------------
# Print End of file information to fapiAttributesSupported.html
#------------------------------------------------------------------------------
print ASFILE "</table>\n\n";
print ASFILE "</body>\n";
print ASFILE "</html>\n";

#------------------------------------------------------------------------------
# Close output files
#------------------------------------------------------------------------------
close(AIFILE);
close(ECFILE);
close(ACFILE);
close(ASFILE);
close(ITFILE);
close(ETFILE);

