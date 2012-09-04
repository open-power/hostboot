#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG 
# This is an automatically generated prolog. 
#  
# $Source: src/usr/targeting/common/xmltohb/xmltohb.pl $ 
#  
# IBM CONFIDENTIAL 
#  
# COPYRIGHT International Business Machines Corp. 2011,2012 
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
# Purpose:
# Author: Nick Bofferding
# Last Updated: 09/09/2011
#
# Version: 1.0
#
# Change Log **********************************************************
#
# End Change Log ******************************************************

use strict;

################################################################################
# Use of the following packages
################################################################################

use Getopt::Long;
use Pod::Usage;
use XML::Simple;
use Text::Wrap;
use Data::Dumper;
use POSIX;

################################################################################
# Set PREFERRED_PARSER to XML::Parser. Otherwise it uses XML::SAX which contains
# bugs that result in XML parse errors that can be fixed by adjusting white-
# space (i.e. parse errors that do not make sense).
################################################################################
$XML::Simple::PREFERRED_PARSER = 'XML::Parser';

################################################################################
# Process command line parameters, issue help text if needed
################################################################################

sub main{ }
my $cfgSrcOutputDir = ".";
my $cfgImgOutputDir = ".";
my $cfgHbXmlFile = "./hb.xml";
my $cfgVmmConstsFile = "../../../include/usr/vmmconst.h";
my $cfgFapiAttributesXmlFile = "";
my $cfgImgOutputFile = "./targeting.bin";
my $cfgHelp = 0;
my $cfgMan = 0;
my $cfgVerbose = 0;
my $cfgShortEnums = 0;
my $cfgBigEndian = 1;
my $cfgIncludeFspAttributes = 0;

GetOptions("hb-xml-file:s" => \$cfgHbXmlFile,
           "src-output-dir:s" =>  \$cfgSrcOutputDir,
           "img-output-dir:s" =>  \$cfgImgOutputDir,
           "fapi-attributes-xml-file:s" => \$cfgFapiAttributesXmlFile,
           "img-output-file:s" =>  \$cfgImgOutputFile,
           "vmm-consts-file:s" =>  \$cfgVmmConstsFile,
           "short-enums!" =>  \$cfgShortEnums,
           "big-endian!" =>  \$cfgBigEndian,
           "include-fsp-attributes!" =>  \$cfgIncludeFspAttributes,
           "help" => \$cfgHelp,
           "man" => \$cfgMan,
           "verbose" => \$cfgVerbose ) || pod2usage(-verbose => 0);

pod2usage(-verbose => 1) if $cfgHelp;
pod2usage(-verbose => 2) if $cfgMan;

# Remove extraneous '/' from end of path names; use temporary version of $/ for
# the chomp
{
    local $/ = '/';
    chomp($cfgSrcOutputDir);
    $cfgSrcOutputDir .= "/";

    chomp($cfgImgOutputDir);
    $cfgImgOutputDir .= "/";
}

if($cfgVerbose)
{
    print STDOUT "Host boot intemediate XML model = $cfgHbXmlFile\n";
    print STDOUT "Fapi attributes XML file = $cfgFapiAttributesXmlFile\n";
    print STDOUT "Source output dir = $cfgSrcOutputDir\n";
    print STDOUT "Image output dir = $cfgImgOutputDir\n";
    print STDOUT "VMM constants file = $cfgVmmConstsFile\n";
    print STDOUT "Short enums = $cfgShortEnums\n";
    print STDOUT "Big endian = $cfgBigEndian\n";
    print STDOUT "include-fsp-attributes = $cfgIncludeFspAttributes\n",
}

################################################################################
# Initialize some globals
################################################################################

my $xml = new XML::Simple (KeyAttr=>[]);

# Until full machine parseable workbook parsing splits out all the input files,
# use the intermediate representation containing the full host boot model.
# Aborts application if file name not found.
my $attributes = $xml->XMLin($cfgHbXmlFile,
    forcearray => ['enumerationType','attribute','hwpfToHbAttrMap']);
my $fapiAttributes = {};
if ($cfgFapiAttributesXmlFile ne "")
{
    $fapiAttributes = $xml->XMLin($cfgFapiAttributesXmlFile,
        forcearray => ['attribute']);
}
# save attributes defined as Target_t type
my %Target_t = ();

# Perform some sanity validation of the model (so we don't have to later)
validateAttributes($attributes);
validateTargetInstances($attributes);
validateTargetTypes($attributes);
validateTargetTypesExtension($attributes);
handleTgtPtrAttributes(\$attributes, \%Target_t);

# Open the output files and write them
if( !($cfgSrcOutputDir =~ "none") )
{
    open(TRAIT_FILE,">$cfgSrcOutputDir"."attributetraits.H")
      or fatal ("Trait file: \"$cfgSrcOutputDir"
        . "attributetraits.H\" could not be opened.");
    my $traitFile = *TRAIT_FILE;
    writeTraitFileHeader($traitFile);
    writeTraitFileTraits($attributes,$traitFile);
    writeTraitFileFooter($traitFile);
    close $traitFile;

    open(ATTR_FILE,">$cfgSrcOutputDir"."attributeenums.H")
      or fatal ("Attribute enum file: \"$cfgSrcOutputDir"
        . "attributeenums.H\" could not be opened.");
    my $enumFile = *ATTR_FILE;
    writeEnumFileHeader($enumFile);
    writeEnumFileAttrIdEnum($attributes,$enumFile);
    writeEnumFileAttrEnums($attributes,$enumFile);
    writeEnumFileFooter($enumFile);
    close $enumFile;

    open(STRING_HEADER_FILE,">$cfgSrcOutputDir"."attributestrings.H")
      or fatal ("Attribute string header file: \"$cfgSrcOutputDir"
        . "attributestrings.H\" could not be opened.");
    my $stringHeaderFile = *STRING_HEADER_FILE;
    writeStringHeaderFileHeader($stringHeaderFile);
    writeStringHeaderFileStrings($attributes,$stringHeaderFile);
    writeStringHeaderFileFooter($stringHeaderFile);
    close $stringHeaderFile;

    open(STRING_IMPLEMENTATION_FILE,">$cfgSrcOutputDir"."attributestrings.C")
      or fatal ("Attribute string source file: \"$cfgSrcOutputDir"
        . "attributestrings.C\" could not be opened.");
    my $stringImplementationFile = *STRING_IMPLEMENTATION_FILE;
    writeStringImplementationFileHeader($stringImplementationFile);
    writeStringImplementationFileStrings($attributes,$stringImplementationFile);
    writeStringImplementationFileFooter($stringImplementationFile);
    close $stringImplementationFile;

    open(STRUCTS_HEADER_FILE,">$cfgSrcOutputDir"."attributestructs.H")
      or fatal ("Attribute struct file: \"$cfgSrcOutputDir"
        . "attributestructs.H\" could not be opened.");
    my $structFile = *STRUCTS_HEADER_FILE;
    writeStructFileHeader($structFile);
    writeStructFileStructs($attributes,$structFile);
    writeStructFileFooter($structFile);
    close $structFile;

    open(PNOR_HEADER_DEF_FILE,">$cfgSrcOutputDir"."pnortargeting.H")
      or fatal ("Targeting header definition header file: \"$cfgSrcOutputDir"
        . "pnortargeting.H\" could not be opened.");
    my $pnorHeaderDefFile = *PNOR_HEADER_DEF_FILE;
    writeHeaderFormatHeaderFile($pnorHeaderDefFile);
    close $pnorHeaderDefFile;

    open(FAPI_PLAT_ATTR_MACROS_FILE,">$cfgSrcOutputDir"."fapiplatattrmacros.H")
      or fatal ("FAPI platform attribute macro header file: \"$cfgSrcOutputDir"
        . "fapiplatattrmacros.H\" could not be opened.");
    my $fapiPlatAttrMacrosHeaderFile = *FAPI_PLAT_ATTR_MACROS_FILE;
    writeFapiPlatAttrMacrosHeaderFileHeader ($fapiPlatAttrMacrosHeaderFile);
    writeFapiPlatAttrMacrosHeaderFileContent($attributes,$fapiAttributes,
        $fapiPlatAttrMacrosHeaderFile);
    writeFapiPlatAttrMacrosHeaderFileFooter ($fapiPlatAttrMacrosHeaderFile);
    close $fapiPlatAttrMacrosHeaderFile;

    #fixme-Remove when RTC:38197 is done
    open(ATTR_DUMP_FILE,">$cfgSrcOutputDir"."attributedump.C")
      or fatal ("Attribute dump file: \"$cfgSrcOutputDir"
		. "attributedump.C\" could not be opened.");
    my $dumpFile = *ATTR_DUMP_FILE;
    writeDumpFile($attributes,$dumpFile);
    close $dumpFile;

    open(ATTR_ATTRERRL_C_FILE,">$cfgSrcOutputDir"."errludattribute.C")
      or fatal ("Attribute errlog C file: \"$cfgSrcOutputDir"
		. "errludattribute.C\" could not be opened.");
    my $attrErrlCFile = *ATTR_ATTRERRL_C_FILE;
    writeAttrErrlCFile($attributes,$attrErrlCFile);
    close $attrErrlCFile;

    open(ATTR_ATTRERRL_H_FILE,">$cfgSrcOutputDir"."errludattribute.H")
      or fatal ("Attribute errlog H file: \"$cfgSrcOutputDir"
		. "errludattribute.H\" could not be opened.");
    my $attrErrlHFile = *ATTR_ATTRERRL_H_FILE;
    writeAttrErrlHFile($attributes,$attrErrlHFile);
    close $attrErrlHFile;

}

if( !($cfgImgOutputDir =~ "none") )
{
    my $Data = generateTargetingImage($cfgVmmConstsFile,$attributes,\%Target_t);

    open(PNOR_TARGETING_FILE,">$cfgImgOutputDir".$cfgImgOutputFile)
      or fatal ("Targeting image file: \"$cfgImgOutputDir"
        . "$cfgImgOutputFile\" could not be opened.");
    binmode(PNOR_TARGETING_FILE);
    print PNOR_TARGETING_FILE "$Data";
    close(PNOR_TARGETING_FILE);
}

exit(0);

################################################################################
# Report a fatal error and quit
################################################################################

sub DEBUG_FUNCTIONS { }
sub fatal {
    my($msg) = @_;

    print STDERR "[FATAL!] $msg\n";

    for(my $caller = 1; ; $caller++)
    {
        my ($package, $filename, $callerLine,
            $subr, $has_args, $wantarray )= caller($caller);
        my $line = (caller($caller-1))[2];
        if(!$line) { last; }

        print STDERR "     $caller: $subr" . "(". $line . ")\n";
    }

    exit(1);
}

sub VALIDATION_FUNCTIONS { }

################################################################################
# Validates sub-elements of an element against criteria
################################################################################

sub validateSubElements {
    my($name,$mustBeHash,$element,$criteria) = @_;

    if($mustBeHash && (ref($element) ne "HASH"))
    {
        fatal("$name must be in the form of a hash.");
    }

    # print keys %{$element} . "\n";

    for my $subElementName (sort(keys %{$element}))
    {
        if(!exists $criteria->{$subElementName})
        {
            fatal("$name element cannot have child element of type "
                . "\"$subElementName\".");
        }
    }

    for my $subElementName (sort(keys %{$criteria}))
    {
        if(   ($criteria->{$subElementName}{required} == 1)
           && (!exists $element->{$subElementName}))
        {
            fatal("$name element missing required child element "
                . "\"$subElementName\".");
        }

        if(exists $element->{$subElementName}
            && ($criteria->{$subElementName}{isscalar} == 1)
            && (ref ($element->{$subElementName}) eq "HASH"))
        {
            fatal("$name element child element \"$subElementName\" should be "
                . "scalar, but is a hash.");
        }
    }
}


################################################################################
# Validates attribute element for correctness
################################################################################

sub validateAttributes {
    my($attributes) = @_;

    my %elements = ( );
    $elements{"id"}          = { required => 1, isscalar => 1};
    $elements{"description"} = { required => 1, isscalar => 1};
    $elements{"persistency"} = { required => 1, isscalar => 1};
    $elements{"fspOnly"}     = { required => 0, isscalar => 0};
    $elements{"readable"}    = { required => 0, isscalar => 0};
    $elements{"simpleType"}  = { required => 0, isscalar => 0};
    $elements{"complexType"} = { required => 0, isscalar => 0};
    $elements{"nativeType"}  = { required => 0, isscalar => 0};
    $elements{"writeable"}   = { required => 0, isscalar => 0};
    $elements{"hasStringConversion"}
                             = { required => 0, isscalar => 0};
    $elements{"hwpfToHbAttrMap"}
                             = { required => 0, isscalar => 0};

    foreach my $attribute (@{$attributes->{attribute}})
    {
        validateSubElements("attribute",1,$attribute,\%elements);
    }
}

################################################################################
# Validates field element for correctness
################################################################################

sub validateFieldElement {
    my($field) = @_;

    my %elements = ( );
    $elements{"type"}        = { required => 1, isscalar => 1};
    $elements{"name"}        = { required => 1, isscalar => 1};
    $elements{"description"} = { required => 1, isscalar => 1};
    $elements{"default"}     = { required => 1, isscalar => 1};
    $elements{"bits"}        = { required => 0, isscalar => 1};

    validateSubElements("field",1,$field,\%elements);
}

################################################################################
# Validates target type extension elements for correctness
################################################################################

sub validateTargetTypesExtension {
    my($attributes) = @_;

    my %elements = ( );
    $elements{"id"}          = { required => 1, isscalar => 1};
    $elements{"attribute"}   = { required => 1, isscalar => 1};

    foreach my $targetTypeExtension (@{$attributes->{targetTypeExtension}})
    {
        validateSubElements("targetTypeExtension",1,
                            $targetTypeExtension,\%elements);
    }
}

################################################################################
# Validates target type elements for correctness
################################################################################

sub validateTargetTypes {
    my($attributes) = @_;

    my %elements = ( );
    $elements{"id"}          = { required => 1, isscalar => 1};
    $elements{"parent"}      = { required => 0, isscalar => 1};
    $elements{"attribute"}   = { required => 0, isscalar => 0};
    $elements{"fspOnly"}     = { required => 0, isscalar => 0};

    foreach my $targetType (@{$attributes->{targetType}})
    {
        validateSubElements("targetType",1,$targetType,\%elements);
    }
}

################################################################################
# Validates target instance elements for correctness
################################################################################

sub validateTargetInstances{
    my($attributes) = @_;

    my %elements = ( );
    $elements{"id"}          = { required => 1, isscalar => 1};
    $elements{"type"}        = { required => 1, isscalar => 1};
    $elements{"attribute"}   = { required => 0, isscalar => 0};

    foreach my $targetInstance (@{$attributes->{targetInstance}})
    {
        validateSubElements("targetInstance",1,$targetInstance,\%elements);
    }
}

################################################################################
# Convert PHYS_PATH into index for Target_t attribute's value
################################################################################

sub handleTgtPtrAttributes{
    my($attributes, $Target_t) = @_;

    my $aId = 0;
    ${$Target_t}{'NULL'} = $aId;
    foreach my $attribute (@{${$attributes}->{attribute}})
    {
        $aId++;
        if(exists $attribute->{simpleType} &&
           exists $attribute->{simpleType}->{'Target_t'})
        {
            ${$Target_t}{"$attribute->{id}"} = $aId;
        }
    }

    my %TargetList = ();
    my $index = 1;
    # Mapping instance's PHYS_PATH to index (1-base)
    foreach my $targetInstance (@{${$attributes}->{targetInstance}})
    {
        foreach my $attr (@{$targetInstance->{attribute}})
        {
            if ($attr->{id} eq "PHYS_PATH")
            {
                $TargetList{$attr->{default}} = $index++;
                last;
            }
        }
    }
    # replace Target_t attribute's value with instance's index
    foreach my $targetInstance (@{${$attributes}->{targetInstance}})
    {
        foreach my $attr (@{$targetInstance->{attribute}})
        {
            # An instance has a Target_t attribute
            if(exists ${$Target_t}{$attr->{id}})
            {
                if (exists $TargetList{$attr->{default}})
                {
                    $attr->{default} = $TargetList{$attr->{default}};
                }
                else
                {
                    fatal("$attr->{id} attribute has an unknown value "
                          . "$attr->{default}\n"
                          . "It must be NULL or a valid PHYS_PATH\n");
                }
            }
        }
    }
}

sub SOURCE_FILE_GENERATION_FUNCTIONS { }

################################################################################
# Writes the plat attribute macros header file header
################################################################################

sub writeFapiPlatAttrMacrosHeaderFileHeader {
    my($outFile) = @_;

    print $outFile <<VERBATIM;

#ifndef FAPI_FAPIPLATATTRMACROS_H
#define FAPI_FAPIPLATATTRMACROS_H

/**
 *  \@file fapiplatattrmacros.H
 *
 *  \@brief FAPI -> HB attribute mappings.  This file is autogenerated and
 *      should not be altered.
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <stdint.h>

//******************************************************************************
// Macros
//******************************************************************************

namespace fapi
{

namespace platAttrSvc
{
VERBATIM
}

################################################################################
# Writes the plat attribute macros
################################################################################

sub writeFapiPlatAttrMacrosHeaderFileContent {
    my($attributes,$fapiAttributes,$outFile) = @_;

    my $macroSection = "";
    my $attrSection = "";

    foreach my $attribute (@{$attributes->{attribute}})
    {
        foreach my $hwpfToHbAttrMap (@{$attribute->{hwpfToHbAttrMap}})
        {
            if(   !exists $hwpfToHbAttrMap->{id}
               || !exists $hwpfToHbAttrMap->{macro})
            {
                fatal("id,macro fields required\n");
            }

            my $fapiReadable  = 0;
            my $fapiWriteable = 0;
            my $instantiated = 0;

            if ($cfgFapiAttributesXmlFile eq "")
            {
                #No FAPI attributes xml file specified
                if(exists $attribute->{readable})
                {
                    $macroSection .= '    #define ' .  $hwpfToHbAttrMap->{id} .
                        "_GETMACRO(ID,PTARGET,VAL) \\\n" .
                        "        FAPI_PLAT_ATTR_SVC_GETMACRO_" .
                        $hwpfToHbAttrMap->{macro} . "(ID,PTARGET,VAL)\n";
                    $instantiated = 1;
                }

                if(exists $attribute->{writeable})
                {
                    $macroSection .= '    #ifndef ' .  $hwpfToHbAttrMap->{id} .
                        "_SETMACRO\n";
                    $macroSection .= '    #define ' .  $hwpfToHbAttrMap->{id} .
                        "_SETMACRO(ID,PTARGET,VAL) \\\n" .
                        "        FAPI_PLAT_ATTR_SVC_SETMACRO_" .
                        $hwpfToHbAttrMap->{macro} . "(ID,PTARGET,VAL)\n";
                    $macroSection .= "    #endif\n";
                    $instantiated = 1;
                }
            }
            else
            {
                #FAPI attribute xml file specified - validate against FAPI attrs
                foreach my $fapiAttr (@{$fapiAttributes->{attribute}})
                {
                    if(   (exists $fapiAttr->{id})
                       && ($fapiAttr->{id} eq $hwpfToHbAttrMap->{id}) )
                    {
                        # Check that non-platInit attributes are in the
                        # volatile-zeroed section and have a direct mapping
                        if (! exists $fapiAttr->{platInit})
                        {
                            if ($hwpfToHbAttrMap->{macro} ne "DIRECT")
                            {
                                fatal("FAPI non-platInit attr " .
                                      "'$hwpfToHbAttrMap->{id}' is " .
                                      "'$hwpfToHbAttrMap->{macro}', " .
                                      "it must be DIRECT");
                            }

                            if ($attribute->{persistency} ne "volatile-zeroed")
                            {
                                fatal("FAPI non-platInit attr " .
                                      "'$hwpfToHbAttrMap->{id}' is " .
                                      "'$attribute->{persistency}', " .
                                      "it must be volatile-zeroed");
                            }

                        }

                        # All FAPI attributes are readable
                        $fapiReadable = 1;

                        if(exists $fapiAttr->{writeable})
                        {
                            $fapiWriteable = 1;
                        }

                        last;
                    }
                }

                if($fapiReadable)
                {
                    if(exists $attribute->{readable})
                    {
                        $macroSection .= '    #define ' .  $hwpfToHbAttrMap->{id} .
                            "_GETMACRO(ID,PTARGET,VAL) \\\n" .
                            "        FAPI_PLAT_ATTR_SVC_GETMACRO_" .
                            $hwpfToHbAttrMap->{macro} . "(ID,PTARGET,VAL)\n";
                        $instantiated = 1;
                    }
                    else
                    {
                        fatal("FAPI attribute $hwpfToHbAttrMap->{id} requires " .
                            "platform supply readable attribute.");
                    }
                }

                if($fapiWriteable)
                {
                    if(exists $attribute->{writeable})
                    {
                        $macroSection .= '    #define ' .  $hwpfToHbAttrMap->{id} .
                            "_SETMACRO(ID,PTARGET,VAL) \\\n" .
                            "        FAPI_PLAT_ATTR_SVC_SETMACRO_" .
                            $hwpfToHbAttrMap->{macro} . "(ID,PTARGET,VAL)\n";
                        $instantiated = 1;
                    }
                    else
                    {
                        fatal("FAPI attribute $hwpfToHbAttrMap->{id} requires "
                            . "platform supply writeable attribute.");
                    }
                }
            }

            if($instantiated)
            {
                $attrSection .= '    #define FAPI_PLAT_ATTR_SVC_MACRO_' .
                    $hwpfToHbAttrMap->{macro} . "_FAPI_" .
                    $hwpfToHbAttrMap->{id} . " \\\n" .
                    "        TARGETING::ATTR_" .
                    $attribute->{id} . "\n";
            }
        }
    }

    print $outFile $attrSection;
    print $outFile "\n";
    print $outFile $macroSection;
    print $outFile "\n";
}

################################################################################
# Writes the plat attribute macros header file footer
################################################################################

sub writeFapiPlatAttrMacrosHeaderFileFooter {
    my($outFile) = @_;

print $outFile <<VERBATIM;
} // End namespace platAttrSvc

} // End namespace fapi

#endif // FAPI_FAPIPLATATTRMACROS_H

VERBATIM

}

################################################################################
# Writes the pnor targeting header format file
################################################################################

sub writeHeaderFormatHeaderFile {
    my($outFile) = @_;

    print $outFile <<VERBATIM;

#ifndef TARG_PNORHEADER_H
#define TARG_PNORHEADER_H

/**
 *  \@file pnorheader.H
 *
 *  \@brief Definition for structure of targeting's PNOR image header.  This
 *      file is autogenerated and should not be altered.
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <builtins.h>
#include <stdint.h>
#include <targeting/adapters/types.H>
#include <targeting/common/pointer.H>

// Targeting component

//******************************************************************************
// Complex Types
//******************************************************************************

namespace TARGETING
{
    const uint32_t PNOR_TARG_EYE_CATCHER = 0x54415247;

    enum SECTION_TYPE
    {
        // Targeting read-only section backed to PNOR.  Always the 0th section.
        SECTION_TYPE_PNOR_RO        = 0x00,

        // Targeting read-write section backed to PNOR
        SECTION_TYPE_PNOR_RW        = 0x01,

        // Targeting heap section initialized out of PNOR
        SECTION_TYPE_HEAP_PNOR_INIT = 0x02,

        // Targeting heap section intialized to zero
        SECTION_TYPE_HEAP_ZERO_INIT = 0x03,

        // FSP section
        // TODO RTC: 35451 
        SECTION_TYPE_FSP = 0x04,
    };

    struct TargetingSection
    {
        // Type of targeting section
        const SECTION_TYPE sectionType : 8;

        // Offset of the section within the PNOR targeting image from byte zero
        // of the targeting header
        const uint32_t     sectionOffset;

        // Size of the section within the PNOR targeting image
        const uint32_t     sectionSize;

    } PACKED;

    struct TargetingHeader
    {
        // Eyecatcher to quickly verify correct population of targeting PNOR
        // data
        const uint32_t         eyeCatcher;

        // Major version of the PNOR targeting image
        const uint16_t         majorVersion;

        // Minor version of the PNOR targeting image
        const uint16_t         minorVersion;

        // Total size of the targeting header (from beginning of header).  The
        // PNOR RO targeting data is located immediately following the header
        const uint32_t         headerSize;

        // Virtual memory offset from the virtual memory address of the previous
        // section where the attribute resource provider must load the next
        // section.  If there is no previous section, it will represent the
        // offset from the virtual memory base address (typically 0)
        const uint32_t         vmmSectionOffset;

        // Virtual memory base address where the attribute resource provider
        // must load the 0th (PNOR RO) section
        AbstractPointer<void>    vmmBaseAddress;

        // Size of each TargetingSection record
        const uint32_t         sizeOfSection;

        // Number of TargetingSection records
        const uint32_t         numSections;

        // Offset to the first TargetingSection record, from the end of this
        // field
        const uint32_t         offsetToSections;

        // Pad, in bytes, given by "offsetToSections"

        // const TargetingSection sections[numSections];

    } PACKED;

} // End namespace TARGETING

#endif // TARG_PNORHEADER_H

VERBATIM

}

################################################################################
# Writes the string implementation file header
################################################################################

sub writeStringImplementationFileHeader {
    my($outFile) = @_;

    print $outFile <<VERBATIM;

/**
 *  \@file attributestrings.C
 *
 *  \@brief Attribute string implementation.  This file is autogenerated and
 *      should not be altered.
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <stdint.h>
#include <stdlib.h>

// Targeting component
#include <targeting/common/attributes.H>

namespace TARGETING {

VERBATIM

}

################################################################################
# Writes string implementation
################################################################################

sub writeStringImplementationFileStrings {
    my($attributes,$outFile) = @_;

    foreach my $attribute (@{$attributes->{attribute}})
    {
        if(exists $attribute->{simpleType})
        {
            my $simpleType = $attribute->{simpleType};
            if(exists $simpleType->{enumeration})
            {
                my $enumeration = $simpleType->{enumeration};

                print $outFile "//*********************************************"
                    . "*********************************\n";
                print $outFile "// attrToString<ATTR_", $attribute->{id}, ">\n";
                print $outFile "//*********************************************"
                    . "*********************************\n\n";
                print $outFile "template<>\n";
                print $outFile "const char* attrToString<ATTR_",
                    $attribute->{id},"> (\n";
                print $outFile "    AttributeTraits<ATTR_",$attribute->{id},
                    ">::Type const& i_attrValue)\n";
                print $outFile "{\n";
                print $outFile "    switch(i_attrValue)\n";
                print $outFile "    {\n";
                my $enumerationType = getEnumerationType($attributes,
                    $enumeration->{id});

                foreach my $enumerator (@{$enumerationType->{enumerator}})
                {
                    print $outFile "        case ", $attribute->{id}, "_",
                        $enumerator->{name},":\n";
                    print $outFile "            return \"",
                        $enumerator->{name},"\";\n";
                }

                print $outFile "        default:\n";
                print $outFile "            return \"Cannot decode ",
                    $attribute->{id}, "\";\n";
                print $outFile "    }\n";
                print $outFile "}\n\n";
           }
        }
    }
}

################################################################################
# Locate generic attribute definition, given an enumeration ID
################################################################################

sub getEnumerationType {

    my($attributes,$id) = @_;
    my $matchingEnumeration;

    foreach my $enumerationType (@{$attributes->{enumerationType}})
    {
        if($id eq $enumerationType->{id})
        {
            $matchingEnumeration = $enumerationType;
            last;
        }
    }

    if(!exists $matchingEnumeration->{id})
    {
        fatal("Could not find enumeration with ID of " . $id . "\n");
    }

    return $matchingEnumeration;
}

################################################################################
# Writes the string implementation file footer
################################################################################

sub writeStringImplementationFileFooter {
    my($outFile) = @_;

print $outFile <<VERBATIM;
} // End namespace TARGETING

VERBATIM
}

################################################################################
# Writes the struct file header
################################################################################

sub writeStructFileHeader {
    my($outFile) = @_;

print $outFile <<VERBATIM;

#ifndef TARG_ATTRIBUTESTRUCTS_H
#define TARG_ATTRIBUTESTRUCTS_H

/**
 *  \@file attributestructs.H
 *
 *  \@brief Complex structures for host boot attributes.  This file is
 *      autogenerated and should not be altered.
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <stdint.h>
#include <stdlib.h>

// Targeting component
#include <builtins.h>
#include <targeting/common/attributes.H>
#include <targeting/common/entitypath.H>

//******************************************************************************
// Complex Types
//******************************************************************************

namespace TARGETING
{

VERBATIM

}

################################################################################
# Writes struct header file structs
################################################################################

sub writeStructFileStructs {
    my($attributes,$outFile) = @_;

    foreach my $attribute (@{$attributes->{attribute}})
    {
        if(exists $attribute->{complexType})
        {
            my $complexType = $attribute->{complexType};
            if(!exists $complexType->{description})
            {
                fatal("ERROR: Complex type requires a 'description'.");
            }

            print $outFile "/**\n";
            print $outFile wrapBrief($complexType->{description});
            print $outFile " */\n";

            print $outFile "struct ",
                calculateStructName($attribute->{id}), "\n";
            print $outFile "{\n";

            my $complex = $attribute->{complexType};
            foreach my $field (@{$complex->{field}})
            {
                validateFieldElement($field);

                my $bits = "";
                if($field->{bits})
                {
                    $bits = " : " . $field->{bits};
                }

                print $outFile wrapComment($field->{description});
                print $outFile "    ", $field->{type}, " ", $field->{name},
                    $bits, "; \n\n";
            }

            print $outFile "} PACKED;\n\n";
        }
    }
}

################################################################################
# Writes the struct file footer
################################################################################

sub writeStructFileFooter {
    my($outFile) = @_;

print $outFile <<VERBATIM;
} // End namespace TARGETING

#endif // TARG_ATTRIBUTESTRUCTS_H

VERBATIM

}

################################################################################
# Writes the string header file header
################################################################################

sub writeStringHeaderFileHeader {
    my($outFile) = @_;

print $outFile <<VERBATIM;

#ifndef TARG_ATTRIBUTESTRINGS_H
#define TARG_ATTRIBUTESTRINGS_H

/**
 *  \@file attributestrings.H
 *
 *  \@brief Attribute string conversion routines.  This file is autogenerated
 *      and should not be altered.
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <stdint.h>
#include <stdlib.h>

namespace TARGETING
{

/**
 *  \@brief Class used to clarify compiler error when caller attempts to
 *      stringify an unsupported attribute
 */
class InvalidAttributeForStringification;

/**
 *  \@brief Return attribute as a string
 *
 *  \@param[in] i_attrValue Value of the attribute
 *
 *  \@return String which decodes the attribute value
 */
template<const ATTRIBUTE_ID A>
const char* attrToString(
    typename AttributeTraits<A>::Type const& i_attrValue)
{
    // Default behavior is to fail the compile if caller attempt to print an
    // unsupported string
    return InvalidAttributeForStringification();
}

VERBATIM

}

################################################################################
# Writes string interfaces
################################################################################

sub writeStringHeaderFileStrings {
    my($attributes,$outFile) = @_;

    foreach my $attribute (@{$attributes->{attribute}})
    {
        if(exists $attribute->{simpleType})
        {
            my $simpleType = $attribute->{simpleType};
            if(exists $simpleType->{enumeration})
            {
                my $enumeration = $simpleType->{enumeration};
                print $outFile "/**\n";
                print $outFile " *  \@brief See "
                    . "attrToString<const ATTRIBUTE_ID A>\n";
                print $outFile " */\n";
                print $outFile "template<>\n";
                print $outFile "const char* attrToString<ATTR_",
                    $attribute->{id},">(\n";
                print $outFile "    AttributeTraits<ATTR_",$attribute->{id},
                    ">::Type const& i_attrValue);\n";
                print $outFile "\n";
            }
        }
    }
}

################################################################################
# Writes the string header file footer
################################################################################

sub writeStringHeaderFileFooter {
    my($outFile) = @_;

print $outFile <<VERBATIM;

} // End namespace TARGETING

#endif // TARG_ATTRIBUTESTRINGS_H

VERBATIM
}

################################################################################
# Writes the enum file header
################################################################################

sub writeEnumFileHeader {
    my($outFile) = @_;

print $outFile <<VERBATIM;

#ifndef TARG_ATTRIBUTEENUMS_H
#define TARG_ATTRIBUTEENUMS_H

/**
 *  \@file attributeenums.H
 *
 *  \@brief Defined enums for platform attributes
 *
 *  This header file contains enumerations for supported platform attributes
 *  (as opposed to HWPF attributes).  This file is automatically
 *  generated and should not be altered.
 */

//******************************************************************************
// Includes
//******************************************************************************

#include <stdint.h>
#include <stdlib.h>

//******************************************************************************
// Enumerations
//******************************************************************************

namespace TARGETING
{

VERBATIM

}

################################################################################
# Writes the enum file attribute enumeration
################################################################################

sub writeEnumFileAttrIdEnum {
    my($attributes,$outFile) = @_;

    print $outFile <<VERBATIM;
/**
 *  \@brief Platform attribute IDs
 *
 *  Enumeration defining every possible platform attribute that can be
 *  associated with a target. This file is autogenerated and should not be
 *  altered.
 */
enum ATTRIBUTE_ID
{
VERBATIM

    my $attrId;
    my $hexVal;

    # Format below intentionally > 80 chars for clarity

    format ATTRENUMFORMAT =
    ATTR_@<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< = @<<<<<<<<<<
    $attrId,                                                         $hexVal .","
.
    select($outFile);
    $~ = 'ATTRENUMFORMAT';

    my $attributeIdEnumeration = getAttributeIdEnumeration($attributes);
    foreach my $enumerator (@{$attributeIdEnumeration->{enumerator}})
    {
        $hexVal = sprintf "0x%08X", $enumerator->{value};
        $attrId = $enumerator->{name};
        write;
    }

    print $outFile "};\n\n";
}

################################################################################
# Writes other enumerations to enumeration file
################################################################################

sub writeEnumFileAttrEnums {
    my($attributes,$outFile) = @_;

    my $enumName = "";
    my $enumHex = "";

    # Format below intentionally > 80 chars for clarity

    format ENUMFORMAT =
    @<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< = @<<<<<<<<<<
    $enumName,                                                       $enumHex .","
.
    select($outFile);
    $~ = 'ENUMFORMAT';

    foreach my $enumerationType (@{$attributes->{enumerationType}})
    {
        print $outFile "/**\n";
        print $outFile wrapBrief( $enumerationType->{description} );
        print $outFile " */\n";
        print $outFile "enum ", $enumerationType->{id}, "\n";
        print $outFile "{\n";

        foreach my $enumerator (@{$enumerationType->{enumerator}})
        {
            $enumHex = sprintf "0x%08X",
                enumNameToValue($enumerationType,$enumerator->{name});
            $enumName = $enumerationType->{id} . "_" . $enumerator->{name};
            write;
        }

        print $outFile "};\n\n";
    }
}

################################################################################
# Writes the enum file footer
################################################################################

sub writeEnumFileFooter {
    my($outFile) = @_;

print $outFile <<VERBATIM;
} // End namespace TARGETING

#endif // TARG_ATTRIBUTEENUMS_H

VERBATIM
}

################################################################################
# Writes the trait file header
################################################################################

sub writeTraitFileHeader {
    my($outFile) = @_;

print $outFile <<VERBATIM;

#ifndef TARG_ATTRIBUTETRAITS_H
#define TARG_ATTRIBUTETRAITS_H

/**
 *  \@file attributetraits.H
 *
 *  \@brief Templates which map attributes to their type/properties
 *
 *  This header file contains templates which map attributes to their
 *  type/properties.  This file is autogenerated and should not be altered.
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <stdint.h>
#include <stdlib.h>
#include <targeting/common/entitypath.H>

namespace TARGETING
{

//******************************************************************************
// Attribute Property Mappings
//******************************************************************************

/**
 *  \@brief Template associating a specific attribute with a type and other
 *      properties, such as whether it is readable/writable
 *
 *      This is automatically generated
 *
 *      enum {
 *          disabled = Special value for the basic, unused wildcard attribute
 *          readable = Attribute is readable
 *          writable = Attribute is writable
 *          hasStringConversion = Attribute has debug string conversion
 *      }
 *
 *      typedef <type> TYPE // <type> is the Attribute's valid type
 */
template<const ATTRIBUTE_ID A>
class AttributeTraits
{
    private:
        enum { disabled };
        typedef void* Type;
};

VERBATIM

}

################################################################################
# Writes computed traits to trait file
################################################################################

sub writeTraitFileTraits {
    my($attributes,$outFile) = @_;

    my $typedefs = "";

    foreach my $attribute (@{$attributes->{attribute}})
    {
        # Build boolean traits

        my $traits = "";
        foreach my $trait ("writeable","readable","hasStringConversion")
        {
            if(exists $attribute->{$trait})
            {
                $traits .= " $trait,";
            }
        }

        # Mark the attribute as being a host boot mutex or non-host boot mutex
        if(   (exists $attribute->{simpleType})
           && (exists $attribute->{simpleType}->{hbmutex}) )
        {
            $traits .= " hbMutex,";
        }
        else
        {
            $traits .= " notHbMutex,";
        }

        chop($traits);

        # Build value type

        my $type = "";
        my $dimensions = "";
        if(exists $attribute->{simpleType})
        {
            my $simpleType = $attribute->{simpleType};
            my $simpleTypeProperties = simpleTypeProperties();
            for my $typeName (sort(keys %{$simpleType}))
            {
                if(exists $simpleTypeProperties->{$typeName})
                {
                    if(    $simpleTypeProperties->{$typeName}{typeName}
                       eq "XMLTOHB_USE_PARENT_ATTR_ID")
                    {
                        $type = $attribute->{id};
                    }
                    else
                    {
                        $type = $simpleTypeProperties->{$typeName}{typeName};
                    }

                    if(   (exists $simpleType->{array})
                       && ($simpleTypeProperties->{$typeName}{supportsArray}) )
                    {
                         my @bounds = split(/,/,$simpleType->{array});
                         foreach my $bound (@bounds)
                         {
                             $dimensions .= "[$bound]";
                         }
                    }
                    elsif(exists $simpleType->{string})
                    {
                        # Create the string dimension
                        if(exists $simpleType->{string}->{sizeInclNull})
                        {
                            $dimensions .=
                                "[$simpleType->{string}->{sizeInclNull}]";
                        }
                    }
                    last;
                }
            }

            if($type eq "")
            {
                fatal("Unsupported simpleType child element for "
                 . "attribute $attribute->{id}.  Keys are ("
                 . join(',',sort(keys %{$simpleType})) . ")");
            }
        }
        elsif(exists $attribute->{nativeType})
        {
            $type = $attribute->{nativeType}->{name};
        }
        elsif(exists $attribute->{complexType})
        {
            $type = calculateStructName($attribute->{id});
        }
        else
        {
            fatal("Could not determine attribute data type for attribute "
                . "$attribute->{id}.");
        }

        # Add traits definition to output

        print $outFile "template<>\n";
        print $outFile "class AttributeTraits<ATTR_",$attribute->{id},">\n";
        print $outFile "{\n";
        print $outFile "    public:\n";
        print $outFile "        enum {",$traits," };\n";
        print $outFile "        typedef ", $type, " Type$dimensions;\n";
        print $outFile "};\n\n";

        $typedefs .= "// Type aliases and/or sizes for ATTR_"
                   . "$attribute->{id} attribute\n";

        $typedefs .= "typedef " . $type .
            " $attribute->{id}" . "_ATTR" . $dimensions . ";\n";

        # Append a more friendly type alias for attribute
        $typedefs .= "typedef " . $type .
            " ATTR_" . "$attribute->{id}" . "_type" . $dimensions . ";\n";

        # If a string, append max # of characters for the string
        if(   (exists $attribute->{simpleType})
           && (exists $attribute->{simpleType}->{string}))
        {
            my $size = $attribute->{simpleType}->{string}->{sizeInclNull} - 1;
            $typedefs .= "const size_t ATTR_"
                      .  "$attribute->{id}" . "_max_chars = "
                      .  "$size"
                      . ";\n";
        }
        $typedefs .= "\n";
    };

    print $outFile "/**\n";
    print $outFile wrapBrief("Mapping of alias type name to underlying type");
    print $outFile " */\n";
    print $outFile $typedefs ."\n";
}

################################################################################
# Writes the trait file footer
################################################################################

sub writeTraitFileFooter {
    my($outFile) = @_;

    print $outFile <<VERBATIM;
} // End namespace TARGETING

#endif // TARG_ATTRIBUTETRAITS_H

VERBATIM
}

######
#Create a .C file to put attributes into the errlog
#####
sub writeAttrErrlCFile {
    my($attributes,$outFile) = @_;

    #First setup the includes and function definition
    print $outFile "#include <stdint.h>\n";
    print $outFile "#include <stdio.h>\n";
    print $outFile "#include <string.h>\n";
    print $outFile "#include <errludattribute.H>\n";
    print $outFile "#include <targeting/common/targetservice.H>\n";
    print $outFile "#include <targeting/common/trace.H>\n";
    print $outFile "\n";
    print $outFile "namespace ERRORLOG\n";
    print $outFile "{\n";
    print $outFile "using namespace TARGETING;\n";
    print $outFile "extern TARG_TD_t g_trac_errl;\n";

    # loop through every attribute to create the local dump function
    foreach my $attribute (@{$attributes->{attribute}})
    {
        # things we'll skip:
        if(!(exists $attribute->{readable}) ||  # write-only attributes
           !(exists $attribute->{writeable}) || # read-only attributes
           (exists $attribute->{simpleType} && (exists $attribute->{simpleType}->{hbmutex})) # mutex attributes
          ) {
            next;
        }
        # any complicated types just get dumped as raw hex binary
        elsif(exists $attribute->{complexType}) {
            #print $outFile "uint32_t dump_ATTR_",$attribute->{id},"(const Target * i_pTarget, char *i_buffer)\n";
            #print $outFile "{   //complexType\n";
            #print $outFile "    uint32_t retSize = 0;\n";
            #print $outFile "    AttributeTraits<ATTR_",$attribute->{id},">::Type tmp;\n";
            #print $outFile "    if( i_pTarget->tryGetAttr<ATTR_",$attribute->{id},">(tmp) ) {\n";
            #print $outFile "        retSize = 1 + sprintf(i_buffer, \" \", &tmp, sizeof(tmp));\n";
            #print $outFile "    }\n";
            #print $outFile "    return(retSize);\n";
            #print $outFile "}\n";
            print $outFile "uint32_t dump_ATTR_",$attribute->{id},"(const Target * i_pTarget, char *i_buffer)\n";
            print $outFile "{   //complexType\n";
            print $outFile "    TRACDCOMP( g_trac_errl, \"ErrlUserDetailsAttribute: ",$attribute->{id}," skipped -- complexType\");\n";
            print $outFile "    return(0);\n";
            print $outFile "}\n";
        }
        # Enums
        elsif(exists $attribute->{simpleType} && (exists $attribute->{simpleType}->{enumeration}) ) {
            print $outFile "uint32_t dump_ATTR_",$attribute->{id},"(const Target * i_pTarget, char *i_buffer)\n";
            print $outFile "{   //simpleType:enum\n";
            print $outFile "    //TRACDCOMP( g_trac_errl, \"ErrlUserDetailsAttribute: ",$attribute->{id}," entry\");\n";
            print $outFile "    uint32_t retSize = 0;\n";
            print $outFile "    AttributeTraits<ATTR_",$attribute->{id},">::Type tmp;\n";
            print $outFile "    if( i_pTarget->tryGetAttr<ATTR_",$attribute->{id},">(tmp) ) {\n";
            print $outFile "        memcpy(i_buffer, &tmp, sizeof(tmp));\n";
            print $outFile "        retSize = sizeof(tmp);\n";
            print $outFile "    }\n";
            print $outFile "    return(retSize);\n";
            print $outFile "}\n";
        }
        # signed and unsigned ints
        elsif(exists $attribute->{simpleType} &&
              ( (exists $attribute->{simpleType}->{uint8_t}) ||
                (exists $attribute->{simpleType}->{uint16_t}) ||
                (exists $attribute->{simpleType}->{uint32_t}) ||
                (exists $attribute->{simpleType}->{uint64_t}) ||
                (exists $attribute->{simpleType}->{int8_t}) ||
                (exists $attribute->{simpleType}->{int16_t}) ||
                (exists $attribute->{simpleType}->{int32_t}) ||
                (exists $attribute->{simpleType}->{int64_t})
              )
             )
        {
            print $outFile "uint32_t dump_ATTR_",$attribute->{id},"(const Target * i_pTarget, char *i_buffer)\n";
            print $outFile "{   //simpleType:uint :int\n";
            print $outFile "    //TRACDCOMP( g_trac_errl, \"ErrlUserDetailsAttribute: ",$attribute->{id}," entry\");\n";
            print $outFile "    uint32_t retSize = 0;\n";
            print $outFile "    AttributeTraits<ATTR_",$attribute->{id},">::Type tmp;\n";
            print $outFile "    if( i_pTarget->tryGetAttr<ATTR_",$attribute->{id},">(tmp) ) {\n";
            print $outFile "        memcpy(i_buffer, &tmp, sizeof(tmp));\n";
            print $outFile "        retSize = sizeof(tmp);\n";
            print $outFile "    }\n";
            print $outFile "    return(retSize);\n";
            print $outFile "}\n";
        }
        # dump the enums for EntityPaths
        elsif(exists $attribute->{nativeType} && ($attribute->{nativeType}->{name} eq "EntityPath")) {
            print $outFile "uint32_t dump_ATTR_",$attribute->{id},"(const Target * i_pTarget, char *i_buffer)\n";
            print $outFile "{   //nativeType:EntityPath\n";
            print $outFile "    //TRACDCOMP( g_trac_errl, \"ErrlUserDetailsAttribute: ",$attribute->{id}," entry\");\n";
            print $outFile "    uint32_t retSize = 0;\n";
            print $outFile "    AttributeTraits<ATTR_",$attribute->{id},">::Type tmp;\n";
            print $outFile "    if( i_pTarget->tryGetAttr<ATTR_",$attribute->{id},">(tmp) ) {\n";
            print $outFile "        // data is PATH_TYPE, Number of elements, [ Element, Instance# ]\n";
            print $outFile "        EntityPath::PATH_TYPE lPtype = tmp.type();\n";
            print $outFile "        memcpy(i_buffer + retSize,&lPtype,sizeof(lPtype));\n";
            print $outFile "        retSize += sizeof(lPtype);\n";
            print $outFile "        uint8_t lSize = tmp.size();\n";
            print $outFile "        memcpy(i_buffer + retSize,&lSize,sizeof(lSize));\n";
            print $outFile "        retSize += sizeof(lSize);\n";
            print $outFile "        for (uint32_t i=0;i<lSize;i++) {\n";
            print $outFile "            EntityPath::PathElement lType = tmp[i];\n";
            print $outFile "            memcpy(i_buffer + retSize,&tmp[i],sizeof(tmp[i]));\n";
            print $outFile "            retSize += sizeof(tmp[i]);\n";
            print $outFile "        }\n";
            print $outFile "    }\n";
            print $outFile "    return(retSize);\n";
            print $outFile "}\n";
        }
        # any other nativeTypes are just decimals...  (I never saw one)
        elsif(exists $attribute->{nativeType}) {
            print $outFile "uint32_t dump_ATTR_",$attribute->{id},"(const Target * i_pTarget, char *i_buffer)\n";
            print $outFile "{   //nativeType\n";
            print $outFile "    //TRACDCOMP( g_trac_errl, \"ErrlUserDetailsAttribute: ",$attribute->{id}," entry\");\n";
            print $outFile "    uint32_t retSize = 0;\n";
            print $outFile "    AttributeTraits<ATTR_",$attribute->{id},">::Type tmp;\n";
            print $outFile "    if( i_pTarget->tryGetAttr<ATTR_",$attribute->{id},">(tmp) ) {\n";
            print $outFile "        memcpy(i_buffer, &tmp, sizeof(tmp));\n";
            print $outFile "        retSize = sizeof(tmp);\n";
            print $outFile "    }\n";
            print $outFile "    return(retSize);\n";
            print $outFile "}\n";
        }
        # just in case, add a dummy function
        else
        {
            print $outFile "uint32_t dump_ATTR_",$attribute->{id},"(const Target * i_pTarget, char *i_buffer)\n";
            print $outFile "{   //unknown attributes\n";
            print $outFile "    TRACDCOMP( g_trac_errl, \"ErrlUserDetailsAttribute: ",$attribute->{id}," UNKNOWN\");\n";
            print $outFile "    return(0);\n";
            print $outFile "}\n";
        }
    }

    # build function that takes adds 1 attribute to the output
    print $outFile "\n";
    print $outFile "void ErrlUserDetailsAttribute::addData(\n";
    print $outFile "    uint32_t i_attr)\n";
    print $outFile "{\n";
    print $outFile "    char tmpBuffer[128];\n";
    print $outFile "    uint32_t attrSize = 0;\n";
    print $outFile "\n";
    print $outFile "    switch (i_attr) {\n";

    # loop through every attribute to make the swith/case
    foreach my $attribute (@{$attributes->{attribute}})
    {
        # things we'll skip:
        if(!(exists $attribute->{readable}) ||  # write-only attributes
           !(exists $attribute->{writeable}) || # read-only attributes
           (exists $attribute->{simpleType} && (exists $attribute->{simpleType}->{hbmutex})) # mutex attributes
          ) {
            print $outFile "        case (ATTR_",$attribute->{id},"): { break; }\n";
            next;
        }
        print $outFile "        case (ATTR_",$attribute->{id},"): {\n";
        print $outFile "            attrSize = dump_ATTR_",$attribute->{id},"(iv_pTarget,tmpBuffer); break;\n";
        print $outFile "        }\n";
    }

    print $outFile "        default: { //Shouldn't be anything here!!\n";
    print $outFile "            TRACDCOMP( g_trac_errl, \"ErrlUserDetailsAttribute: UNKNOWN i_attr %x\", i_attr);\n";
    print $outFile "            break;\n";
    print $outFile "        }\n";
    print $outFile "    } //switch\n";
    print $outFile "\n";
    print $outFile "    // if we generated one, copy the string into the buffer\n";
    print $outFile "    if (attrSize) { // we have something to output\n";
    print $outFile "        // resize buffer and copy string into it\n";
    print $outFile "        uint8_t * pBuf;\n";
    print $outFile "        pBuf = reinterpret_cast<uint8_t *>(reallocUsrBuf(iv_dataSize + attrSize + sizeof(i_attr) ));\n";
    print $outFile "        memcpy(pBuf + iv_dataSize, &i_attr, sizeof(i_attr)); // first dump the attr enum\n";
    print $outFile "        iv_dataSize += sizeof(i_attr);\n";
    print $outFile "        memcpy(pBuf + iv_dataSize, tmpBuffer, attrSize); // copy into iv_pBuffer\n";
    print $outFile "        iv_dataSize += attrSize;\n";
    print $outFile "    }\n";
    print $outFile "}\n";
    print $outFile "\n";

    # build constructor that dumps 1 attribute
    print $outFile "\n";
    print $outFile "//------------------------------------------------------------------------------\n";
    print $outFile "ErrlUserDetailsAttribute::ErrlUserDetailsAttribute(\n";
    print $outFile "    const Target * i_pTarget, uint32_t i_attr)\n";
    print $outFile "    : iv_pTarget(i_pTarget), iv_dataSize(0)\n";
    print $outFile "{\n";
    print $outFile "    // Set up ErrlUserDetails instance variables\n";
    print $outFile "    iv_CompId = HBERRL_COMP_ID;\n";
    print $outFile "    iv_Version = 1;\n";
    print $outFile "    iv_SubSection = HBERRL_UDT_ATTRIBUTE;\n";
    print $outFile "    iv_merge = true;\n";
    print $outFile "\n";
    print $outFile "    // first, write out the HUID\n";
    print $outFile "    addData(ATTR_HUID);\n";
    print $outFile "    if (i_attr != ATTR_HUID) {\n";
    print $outFile "        addData(i_attr);\n";
    print $outFile "    }\n";
    print $outFile "}\n";
    print $outFile "\n";

    # build constructor that dumps all attributes
    print $outFile "//------------------------------------------------------------------------------\n";
    print $outFile "ErrlUserDetailsAttribute::ErrlUserDetailsAttribute(\n";
    print $outFile "    const Target * i_pTarget)\n";
    print $outFile "    : iv_pTarget(i_pTarget), iv_dataSize(0)\n";
    print $outFile "{\n";
    print $outFile "    // Set up ErrlUserDetails instance variables\n";
    print $outFile "    iv_CompId = HBERRL_COMP_ID;\n";
    print $outFile "    iv_Version = 1;\n";
    print $outFile "    iv_SubSection = HBERRL_UDT_ATTRIBUTE;\n";
    print $outFile "    // override the default of false\n";
    print $outFile "    iv_merge = true;\n";
    print $outFile "\n";
    print $outFile "    dumpAll();\n";
    print $outFile "}\n";
    print $outFile "\n";

    # build internal function that dumps all attributes
    print $outFile "//------------------------------------------------------------------------------\n";
    print $outFile "void ErrlUserDetailsAttribute::dumpAll()\n";
    print $outFile "{\n";
    print $outFile "    // write out the HUID first and always\n";
    print $outFile "    addData(ATTR_HUID);\n";

    # loop through every attribute to make the swith/case
    foreach my $attribute (@{$attributes->{attribute}})
    {
        # skip the HUID that we already added
        if( $attribute->{id} =~ /HUID/ ) {
            next;
        }
        # things we'll skip:
        if(!(exists $attribute->{readable}) ||  # write-only attributes
           !(exists $attribute->{writeable}) || # read-only attributes
           (exists $attribute->{simpleType} && (exists $attribute->{simpleType}->{hbmutex})) # mutex attributes
          ) {
            next;
        }
        print $outFile "    addData(ATTR_",$attribute->{id},");\n";
    }
    print $outFile "}\n";

    print $outFile "\n";

    print $outFile "//------------------------------------------------------------------------------\n";
    print $outFile "ErrlUserDetailsAttribute::~ErrlUserDetailsAttribute()\n";
    print $outFile "{ }\n";
    print $outFile "} // namespace\n";
} # sub writeAttrErrlCFile


######
#Create a .H file to parse attributes out of the errlog
#####
sub writeAttrErrlHFile {
    my($attributes,$outFile) = @_;

    #First setup the includes and function definition
    print $outFile "\n";
    print $outFile "#ifndef ERRL_UDATTRIBUTE_H\n";
    print $outFile "#define ERRL_UDATTRIBUTE_H\n";
    print $outFile "\n";
    print $outFile "#include <errl/errluserdetails.H>\n";
    print $outFile "\n";
    print $outFile "#ifndef PARSER\n";
    print $outFile "\n";
    print $outFile "namespace TARGETING // Forward reference\n";
    print $outFile "{ class Target; }\n";
    print $outFile "\n";
    print $outFile "namespace ERRORLOG\n";
    print $outFile "{\n";
    print $outFile "class ErrlUserDetailsAttribute : public ErrlUserDetails {\n";
    print $outFile "public:\n";
    print $outFile "\n";
    print $outFile "    ErrlUserDetailsAttribute(const TARGETING::Target * i_pTarget, uint32_t i_attr);\n";
    print $outFile "    ErrlUserDetailsAttribute(const TARGETING::Target * i_pTarget);\n";
    print $outFile "    void addData(uint32_t i_attr);\n";
    print $outFile "    virtual ~ErrlUserDetailsAttribute();\n";
    print $outFile "\n";
    print $outFile "private:\n";
    print $outFile "\n";
    print $outFile "    // Disabled\n";
    print $outFile "    ErrlUserDetailsAttribute(const ErrlUserDetailsAttribute &);\n";
    print $outFile "    ErrlUserDetailsAttribute & operator=(const ErrlUserDetailsAttribute &);\n";
    print $outFile "\n";
    print $outFile "    // internal function\n";
    print $outFile "    void dumpAll();\n";
    print $outFile "\n";
    print $outFile "    const TARGETING::Target * iv_pTarget;\n";
    print $outFile "    uint32_t iv_dataSize;\n";
    print $outFile "};\n";
    print $outFile "}\n";
    print $outFile "#else // if PARSER defined\n";
    print $outFile "\n";
    print $outFile "namespace ERRORLOG\n";
    print $outFile "{\n";
    print $outFile "class ErrlUserDetailsParserAttribute : public ErrlUserDetailsParser {\n";
    print $outFile "public:\n";
    print $outFile "\n";
    print $outFile "    ErrlUserDetailsParserAttribute() {}\n";
    print $outFile "\n";
    print $outFile "    virtual ~ErrlUserDetailsParserAttribute() {}\n";
    print $outFile "/**\n";
    print $outFile " *  \@brief Parses Attribute user detail data from an error log\n";
    print $outFile " *  \@param  i_version Version of the data\n";
    print $outFile " *  \@param  i_parse   ErrlUsrParser object for outputting information\n";
    print $outFile " *  \@param  i_pBuffer Pointer to buffer containing detail data\n";
    print $outFile " *  \@param  i_buflen  Length of the buffer\n";
    print $outFile " */\n";
    print $outFile "  virtual void parse(errlver_t i_version,\n";
    print $outFile "                        ErrlUsrParser & i_parser,\n";
    print $outFile "                        void * i_pBuffer,\n";
    print $outFile "                        const uint32_t i_buflen) const\n";
    print $outFile "  {\n";
    print $outFile "    const char *pLabel;\n";
    print $outFile "    uint8_t *l_ptr = static_cast<uint8_t *>(i_pBuffer);\n";
    print $outFile "    std::vector<char> l_traceEntry(128);\n";
    print $outFile "\n";
    print $outFile "        // first 4 bytes is the attr enum\n";
    print $outFile "        uint32_t attrEnum = *(uint32_t *)l_ptr;\n";
    print $outFile "        uint32_t dataSize = 0;\n";
    print $outFile "        l_ptr += sizeof(attrEnum);\n";
    print $outFile "\n";
    print $outFile "        switch (attrEnum) {\n";

    # loop through every attribute to make the swith/case
    foreach my $attribute (@{$attributes->{attribute}})
    {
        my $attrVal = sprintf "0x%08X", $attribute->{value};
        print $outFile "          case ",$attrVal,": {\n";

        # things we'll skip:
        if(!(exists $attribute->{readable}) ||  # write-only attributes
           !(exists $attribute->{writeable}) || # read-only attributes
           (exists $attribute->{simpleType} && (exists $attribute->{simpleType}->{hbmutex})) # mutex attributes
          ) {
            print $outFile "              //not readable\n";
        }
        # Enums have strings defined already, use them
        elsif(exists $attribute->{simpleType} && (exists $attribute->{simpleType}->{enumeration}) ) {
            print $outFile "              //simpleType:enum\n";
            print $outFile "              pLabel = \"ATTR_",$attribute->{id},"\";\n";
            foreach my $enumerationType (@{$attributes->{enumerationType}})
            {
                if ($enumerationType->{id} eq $attribute->{id})
                {
                print $outFile "              switch (*l_ptr) {\n";
                foreach my $enumerator (@{$enumerationType->{enumerator}})
                {
                    my $enumName = $attribute->{id} . "_" . $enumerator->{name};
                    my $enumHex = sprintf "0x%08X", enumNameToValue($enumerationType,$enumerator->{name});
                    print $outFile "                  case ",$enumHex,": {\n";
                    print $outFile "                      // get the length and add one for the null terminator ";
                    print $outFile "                      dataSize = 1  + sprintf(&(l_traceEntry[0]), \"",$enumName,"\");\n";
                    print $outFile "                      break;\n";
                    print $outFile "                  }\n";
                }
                print $outFile "                  default: break;\n";
                print $outFile "              }\n";
                }
            }
        }
        # makes no sense to dump mutex attributes, so skipping
        elsif(exists $attribute->{simpleType} && (exists $attribute->{simpleType}->{hbmutex}) ) {
            print $outFile "            //Mutex attributes - skipping\n";
        }
        # any complicated types just get dumped as raw hex binary
        elsif(exists $attribute->{complexType}) {
            #print $outFile "         //complexType\n";
            #print $outFile "         uint32_t<ATTR_",$attribute->{id},">::Type tmp;\n";
            #print $outFile "         if( i_pTarget->tryGetAttr<ATTR_",$attribute->{id},">(tmp) ) {\n";
            #print $outFile "           dataSize = sprintf(i_buffer, \" \", &tmp, sizeof(tmp));\n";
            #print $outFile "         }\n";
            print $outFile "              //complexType - skipping\n";
        }
        # unsigned ints dump as hex, signed as decimals
        elsif(exists $attribute->{simpleType} &&
              ( (exists $attribute->{simpleType}->{uint8_t}) ||
                (exists $attribute->{simpleType}->{uint16_t}) ||
                (exists $attribute->{simpleType}->{uint32_t}) ||
                (exists $attribute->{simpleType}->{uint64_t}) ||
                (exists $attribute->{simpleType}->{int8_t}) ||
                (exists $attribute->{simpleType}->{int16_t}) ||
                (exists $attribute->{simpleType}->{int32_t}) ||
                (exists $attribute->{simpleType}->{int64_t})
              )
             )
        {
            print $outFile "              //simpleType:uint\n";
            print $outFile "              pLabel = \"ATTR_",$attribute->{id},"\";\n";
            if (exists $attribute->{simpleType}->{uint8_t}) 
            {
                print $outFile "              dataSize = 1 + sprintf(&(l_traceEntry[0]), \"0x%.2X\", *((uint8_t *)l_ptr));\n";
            }
            elsif (exists $attribute->{simpleType}->{uint16_t}) {
                print $outFile "              dataSize = 1 + sprintf(&(l_traceEntry[0]), \"0x%.4X\", *((uint16_t *)l_ptr));\n";
            }
            elsif (exists $attribute->{simpleType}->{uint32_t}) {
                print $outFile "              dataSize = 1 + sprintf(&(l_traceEntry[0]), \"0x%.8X\", *((uint32_t *)l_ptr));\n";
            }
            elsif (exists $attribute->{simpleType}->{uint64_t}) {
                print $outFile "              dataSize = 1 + sprintf(&(l_traceEntry[0]), \"0x%.16llX\", *((uint64_t *)l_ptr));\n";
            }
            elsif (exists $attribute->{simpleType}->{int8_t}) {
                print $outFile "              dataSize = 1 + sprintf(&(l_traceEntry[0]), \"%d\", *((int8_t *)l_ptr));\n";
            }
            elsif (exists $attribute->{simpleType}->{int16_t}) {
                print $outFile "              dataSize = 1 + sprintf(&(l_traceEntry[0]), \"%d\", *((int16_t *)l_ptr));\n";
            }
            elsif (exists $attribute->{simpleType}->{int32_t}) {
                print $outFile "              dataSize = 1 + sprintf(&(l_traceEntry[0]), \"%d\", *((int32_t *)l_ptr));\n";
            }
            elsif (exists $attribute->{simpleType}->{int64_t}) {
                print $outFile "              dataSize = 1 + sprintf(&(l_traceEntry[0]), \"%d\", *((int64_t *)l_ptr));\n";
            }
            if(exists $attribute->{array})
            {
                ### need to do loop for types that are ARRAYS!
            }
        }
        # EntityPaths
        elsif(exists $attribute->{nativeType} && ($attribute->{nativeType}->{name} eq "EntityPath")) {
            print $outFile "              //nativeType:EntityPath\n";
            print $outFile "              pLabel = \"ATTR_",$attribute->{id},"\";\n";
            # data is PATH_TYPE, Number of elements, [ Element, Instance# ]
            # output is PathType:/ElementInstance/ElementInstance/ElementInstance
            print $outFile "              const char *pathString;\n";
            print $outFile "              // from targeting/common/entitypath.[CH]\n";
            print $outFile "              const uint8_t lPtype = *l_ptr; // PATH_TYPE\n";
            print $outFile "              switch (lPtype) {\n";
            print $outFile "                  case 0x01: pathString = \"Logical:\"; break;\n";
            print $outFile "                  case 0x02: pathString = \"Physical:\"; break;\n";
            print $outFile "                  case 0x03: pathString = \"Device:\"; break;\n";
            print $outFile "                  case 0x04: pathString = \"Power:\"; break;\n";
            print $outFile "                  default:   pathString = \"Unknown:\"; break;\n";
            print $outFile "              }\n";
            print $outFile "              dataSize = sprintf(&(l_traceEntry[0]), \"%s\",pathString);\n";
            print $outFile "              const uint8_t lSize = *(l_ptr + 1); // number of elements\n";
            print $outFile "              uint8_t *lElementInstance = (l_ptr + 2);\n";
            print $outFile "              for (uint32_t i=0;i<lSize;i += 2) {\n";
            print $outFile "                  switch (lElementInstance[i]) {\n";
            print $outFile "                      case 0x01: pathString = \"/Sys\"; break;\n";
            print $outFile "                      case 0x02: pathString = \"/Node\"; break;\n";
            print $outFile "                      case 0x03: pathString = \"/DIMM\"; break;\n";
            print $outFile "                      case 0x04: pathString = \"/SCM\"; break;\n";
            print $outFile "                      case 0x05: pathString = \"/DCM\"; break;\n";
            print $outFile "                      case 0x06: pathString = \"/Membuf\"; break;\n";
            print $outFile "                      case 0x07: pathString = \"/Proc\"; break;\n";
            print $outFile "                      case 0x08: pathString = \"/MemVRM\"; break;\n";
            print $outFile "                      case 0x09: pathString = \"/ProcVRM\"; break;\n";
            print $outFile "                      case 0x0A: pathString = \"/EX\"; break;\n";
            print $outFile "                      case 0x0B: pathString = \"/Core\"; break;\n";
            print $outFile "                      case 0x0C: pathString = \"/L2\"; break;\n";
            print $outFile "                      case 0x0D: pathString = \"/L3\"; break;\n";
            print $outFile "                      case 0x0E: pathString = \"/L4\"; break;\n";
            print $outFile "                      case 0x0F: pathString = \"/MCS\"; break;\n";
            print $outFile "                      case 0x10: pathString = \"/MBS\"; break;\n";
            print $outFile "                      case 0x11: pathString = \"/MBA\"; break;\n";
            print $outFile "                      case 0x12: pathString = \"/MemPort\"; break;\n";
            print $outFile "                      case 0x13: pathString = \"/Pervasive\"; break;\n";
            print $outFile "                      case 0x14: pathString = \"/Powerbus\"; break;\n";
            print $outFile "                      case 0x15: pathString = \"/XBUS\"; break;\n";
            print $outFile "                      case 0x16: pathString = \"/ABUS\"; break;\n";
            print $outFile "                      case 0x17: pathString = \"/PCI\"; break;\n";
            print $outFile "                      case 0x18: pathString = \"/TP\"; break;\n";
            print $outFile "                      case 0x19: pathString = \"/DMI\"; break;\n";
            print $outFile "                      case 0x1A: pathString = \"/DPSS\"; break;\n";
            print $outFile "                      case 0x1B: pathString = \"/APSS\"; break;\n";
            print $outFile "                      case 0x1C: pathString = \"/OCC\"; break;\n";
            print $outFile "                      //case TYPE_FSI_LINK: pathString = \"/FSI-link\"; break;\n";
            print $outFile "                      //case TYPE_CFAM: pathString = \"/CFAM\"; break;\n";
            print $outFile "                      //case TYPE_ENGINE: pathString = \"/Engine\"; break;\n";
            print $outFile "                      default: pathString = \"/Unknown\"; break;\n";
            print $outFile "                  } // switch\n";
            print $outFile "                  // copy next part in, overwritting previous terminator\n";
            print $outFile "                  dataSize += sprintf(&(l_traceEntry[0]) + dataSize, \"%s%d\",pathString,lElementInstance[i+1]);\n";
            print $outFile "              } // for\n";
            print $outFile "              dataSize++; // account for last NULL terminator\n";
        }
        # any other nativeTypes are just decimals...  (I never saw one)
        elsif(exists $attribute->{nativeType}) {
            print $outFile "              //nativeType\n";
            print $outFile "              pLabel = \"ATTR_",$attribute->{id},"\";\n";
            print $outFile "              dataSize = 1 + sprintf(&(l_traceEntry[0]), \"%d\", *((int32_t *)l_ptr));\n";
        }
        # just in case, nothing..
        else
        {
            #print $outFile "              //unknown attributes\n";
        }


        print $outFile "              break;\n";
        print $outFile "          }\n";
    }
    print $outFile "          default: {\n";
    print $outFile "              pLabel = \"unknown Attribute\";\n";
    print $outFile "              break;\n";
    print $outFile "          }\n";
    print $outFile "        } // switch\n";
    print $outFile "\n";
    print $outFile "        // pointing to something - print it.\n";
    print $outFile "        if (dataSize != 0) {\n";
    print $outFile "            if (l_traceEntry.size() < dataSize + 2) {\n";
    print $outFile "                l_traceEntry.resize(dataSize + 2);\n";
    print $outFile "            }\n";
    print $outFile "            i_parser.PrintString(pLabel, &(l_traceEntry[0]));\n";
    print $outFile "        }\n";
    print $outFile "        l_ptr += dataSize;\n";
    print $outFile "    } // for\n\n";
    print $outFile "private:\n";
    print $outFile "\n";
    print $outFile "// Disabled\n";
    print $outFile "ErrlUserDetailsParserAttribute(const ErrlUserDetailsParserAttribute &);\n";
    print $outFile "ErrlUserDetailsParserAttribute & operator=(const ErrlUserDetailsParserAttribute &);\n";
    print $outFile "};\n";
    print $outFile "} // namespace\n";
    print $outFile "#endif\n";
    print $outFile "#endif\n";
} # sub writeAttrErrlHFile



#fixme-Remove when RTC:38197 is done
######
#Create a .C file to dump all possible attributes
#####
sub writeDumpFile {
    my($attributes,$outFile) = @_;

    #First setup the includes and function definition
    print $outFile "#include <targeting/common/targetservice.H>\n";
    print $outFile "#include <targeting/common/trace.H>\n";
    print $outFile "#include <stdio.h>\n";
    print $outFile "\n";
    print $outFile "namespace TARGETING\n";
    print $outFile "{\n";
    print $outFile "    void dumpAllAttributes( TARG_TD_t i_trac, uint32_t i_huid )\n";
    print $outFile "    {\n";
    print $outFile "        using namespace TARGETING;\n";
    print $outFile "\n";
    print $outFile "        bool foundit = false;\n";
    print $outFile "        TargetService& l_targetService = targetService();\n";
    print $outFile "\n";
    print $outFile "        // Loop through every Target\n";
    print $outFile "        for( TargetIterator l_targ = l_targetService.begin();\n";
    print $outFile "             l_targ != l_targetService.end();\n";
    print $outFile "             ++l_targ )\n";
    print $outFile "        {\n";

    # add a HUID check first so we can act on a single target
    print $outFile "            { //HUID Check\n";
    print $outFile "                AttributeTraits<ATTR_HUID>::Type huid;\n";
    print $outFile "                if( (*l_targ)->tryGetAttr<ATTR_HUID>(huid) ) {\n";
    print $outFile "                    if( (i_huid != huid) && (i_huid != 0) )\n";
    print $outFile "                    {\n";
    print $outFile "                        //skip this target\n";
    print $outFile "                        continue;\n";
    print $outFile "                    }\n";
    print $outFile "                    else\n";
    print $outFile "                    {\n";
    print $outFile "                        foundit = true;\n";
    print $outFile "                    }\n";
    print $outFile "                }\n";
    print $outFile "            }\n";

    # add the physical path first so we know where we are
    print $outFile "            { //Physical Path\n";
    print $outFile "                AttributeTraits<ATTR_PHYS_PATH>::Type tmp;\n";
    print $outFile "                if( (*l_targ)->tryGetAttr<ATTR_PHYS_PATH>(tmp) ) {\n";
    print $outFile "                    char* tmpstring = tmp.toString();\n";
    print $outFile "                    TRACFCOMP( i_trac, \"DUMP: --ATTR_PHYS_PATH=%s--\", tmpstring );\n";
    print $outFile "                    free(tmpstring);\n";
    print $outFile "                }\n";
    print $outFile "            }\n";

    # loop through every attribute
    foreach my $attribute (@{$attributes->{attribute}})
    {
	# skip write-only attributes
	if(!(exists $attribute->{readable})) {
	    next;
	}

	# skip the PHYS_PATH that we already added
	if( $attribute->{id} =~ /PHYS_PATH/ ) {
	    next;
	}

	# Enums have strings defined already, use them
	if(exists $attribute->{simpleType} && (exists $attribute->{simpleType}->{enumeration}) ) {
	    print $outFile "            { //simpleType:enum\n";
	    print $outFile "                AttributeTraits<ATTR_",$attribute->{id},">::Type tmp;\n";
	    print $outFile "                if( (*l_targ)->tryGetAttr<ATTR_",$attribute->{id},">(tmp) ) {\n";
	    print $outFile "                    const char* tmpstr = (*l_targ)->getAttrAsString<ATTR_",$attribute->{id},">();\n";
	    print $outFile "                    TRACFCOMP( i_trac, \"DUMP: ",$attribute->{id},"=%s\", tmpstr );\n";
	    print $outFile "                }\n";
	    print $outFile "            }\n";
	}
	# signed ints dump as decimals
	elsif(exists $attribute->{simpleType}
	      && ( (exists $attribute->{simpleType}->{int8_t}) ||
		  (exists $attribute->{simpleType}->{int16_t}) ||
		  (exists $attribute->{simpleType}->{int32_t}) ||
		  (exists $attribute->{simpleType}->{int64_t})
		  )
		)
	{
	    print $outFile "            { //simpleType:int\n";
	    print $outFile "                AttributeTraits<ATTR_",$attribute->{id},">::Type tmp;\n";
	    print $outFile "                if( (*l_targ)->tryGetAttr<ATTR_",$attribute->{id},">(tmp) ) {\n";
	    print $outFile "                    TRACFCOMP( i_trac, \"DUMP: ",$attribute->{id},"=%d\", tmp );\n";
	    print $outFile "                }\n";
	    print $outFile "            }\n";
	}
	# unsigned ints dump as hex
	elsif(exists $attribute->{simpleType}
	      && ( (exists $attribute->{simpleType}->{uint8_t}) ||
		  (exists $attribute->{simpleType}->{uint16_t}) ||
		  (exists $attribute->{simpleType}->{uint32_t}) ||
		  (exists $attribute->{simpleType}->{uint64_t})
		  )
		)
	{
	    print $outFile "            { //simpleType:uint\n";
	    print $outFile "                AttributeTraits<ATTR_",$attribute->{id},">::Type tmp;\n";
	    print $outFile "                if( (*l_targ)->tryGetAttr<ATTR_",$attribute->{id},">(tmp) ) {\n";
	    print $outFile "                    TRACFCOMP( i_trac, \"DUMP: ",$attribute->{id},"=0x%X\", tmp );\n";
	    print $outFile "                }\n";
	    print $outFile "            }\n";
	}
	# makes no sense to dump mutex attributes, so skipping
	elsif(exists $attribute->{simpleType} && (exists $attribute->{simpleType}->{hbmutex}) ) {
	    print $outFile "            //Skipping Mutex ",$attribute->{id},"\n";
	}
	# use the built-in stringifier for EntityPaths
	elsif(exists $attribute->{nativeType} && ($attribute->{nativeType}->{name} eq "EntityPath")) {
	    print $outFile "            { //nativeType:EntityPath\n";
	    print $outFile "                AttributeTraits<ATTR_",$attribute->{id},">::Type tmp;\n";
	    print $outFile "                if( (*l_targ)->tryGetAttr<ATTR_",$attribute->{id},">(tmp) ) {\n";
	    print $outFile "                    char* tmpstring = tmp.toString();\n";
	    print $outFile "                    TRACFCOMP( i_trac, \"DUMP: ",$attribute->{id},"=%s\", tmpstring );\n";
	    print $outFile "                    free(tmpstring);\n";
	    print $outFile "                }\n";
	    print $outFile "            }\n";
	}
	# any other nativeTypes are just decimals...  (I never saw one)
	elsif(exists $attribute->{nativeType}) {
	    print $outFile "            { //nativeType\n";
	    print $outFile "                AttributeTraits<ATTR_",$attribute->{id},">::Type tmp;\n";
	    print $outFile "                if( (*l_targ)->tryGetAttr<ATTR_",$attribute->{id},">(tmp) ) {\n";
	    print $outFile "                    TRACFCOMP( i_trac, \"DUMP: ",$attribute->{id},"=%d\", tmp );\n";
	    print $outFile "                }\n";
	    print $outFile "            }\n";
	}
	# any complicated types just get dumped as raw hex binary
	elsif(exists $attribute->{complexType}) {
	    print $outFile "            { //complexType\n";
	    print $outFile "                AttributeTraits<ATTR_",$attribute->{id},">::Type tmp;\n";
	    print $outFile "                if( (*l_targ)->tryGetAttr<ATTR_",$attribute->{id},">(tmp) ) {\n";
	    print $outFile "                    TRACFBIN( i_trac, \"DUMP: ",$attribute->{id},"=\", &tmp, sizeof(tmp) );\n";
	    print $outFile "                }\n";
	    print $outFile "            }\n";
	}
	# just in case, add a comment about missing types
	else
	{
	    print $outFile "            //Skipping ",$attribute->{id},"\n";
	}
    }

    print $outFile "        }\n";
    print $outFile "\n";
    print $outFile "        if( !foundit )\n";
    print $outFile "        {\n";
    print $outFile "            TRACFCOMP( i_trac, \"DUMP: No Target found matching HUID=%.8X\", i_huid );\n";
    print $outFile "        }\n";
    print $outFile "    }\n";
    print $outFile "\n";

    # add another prototype that is easier to call from debug framework
    print $outFile "    void dumpAllAttributes2( trace_desc_t** i_trac, uint32_t i_huid )\n";
    print $outFile "    {\n";
    print $outFile "        dumpAllAttributes( *i_trac, i_huid );\n";
    print $outFile "    }\n";
    print $outFile "\n";

    print $outFile "}\n";
    print $outFile "\n";
}

sub UTILITY_FUNCTIONS { }

################################################################################
# Get generated enumeration describing attribute IDs
################################################################################

sub getAttributeIdEnumeration {
  my($attributes) = @_;

    my $attributeValue = 0;
    my $enumeration = { } ;

    # add the N/A value
    $enumeration->{description} = "Internal enum for attribute IDs\n";
    $enumeration->{default} = "NA";
    $enumeration->{enumerator}->[0]->{name} = "NA";
    $enumeration->{enumerator}->[0]->{value} = 0;

    foreach my $attribute (@{$attributes->{attribute}})
    {
        $attributeValue++;
        $enumeration->{enumerator}->[$attributeValue]->{name}
            = $attribute->{id};
        $enumeration->{enumerator}->[$attributeValue]->{value}
            = sprintf "%u",$attributeValue;
        $attribute->{value} = $attributeValue;
    }

    return $enumeration;
}

################################################################################
# If value is hex, convert to regular number
###############################################################################

sub unhexify {
    my($val) = @_;
    if($val =~ m/^0[xX][01234567890A-Fa-f]+$/)
    {
        $val = hex($val);
    }
    return $val;
}

################################################################################
# Pack 8 byte value into a buffer using configured endianness
################################################################################

sub pack8byte {
    my($quad) = @_;

    my $value = unhexify($quad);

    my $binaryData;
    if($cfgBigEndian)
    {
        $binaryData = pack("NN" , (($value >> 32) & 0xFFFFFFFF),
                                    ($value & 0xFFFFFFFF));
    }
    else # Little endian
    {
        # Invert the words, then reverse them individually
        $binaryData = pack("VV" , ($value & 0xFFFFFFFF),
                                     (($value >> 32) & 0xFFFFFFFF));
    }

    return $binaryData;
}

################################################################################
# Pack 4 byte value into a buffer using configured endianness
################################################################################

sub pack4byte {
    my($value) = @_;

    my $binaryData;
    if($cfgBigEndian)
    {
        $binaryData = pack("N",$value);
    }
    else # Little endian
    {
        $binaryData = pack("V",$value);
    }

    return $binaryData;
}

################################################################################
# Pack 2 byte value into a buffer using configured endianness
################################################################################

sub pack2byte {
    my($value) = @_;

    my $binaryData;
    if($cfgBigEndian)
    {
        $binaryData = pack("n",$value);
    }
    else # Little endian
    {
        $binaryData = pack("v",$value);
    }

    return $binaryData;
}

################################################################################
# Pack 1 byte value into a buffer using configured endianness
################################################################################

sub pack1byte {
    my($value) = @_;

    my $binaryData = pack("C",$value);

    return $binaryData;
}

################################################################################
# Pack string into buffer
################################################################################

sub packString{
    my($value,$attribute) = @_;

    # Proper attribute tags already verified, no need to do checking again
    my $sizeInclNull = $attribute->{simpleType}->{string}->{sizeInclNull};

    # print "String content (before fixup) is [$value]\n";

    # For sanity, remove all white space from front and end of string
    $value =~ s/^\s+//g;
    $value =~ s/\s+$//g;

    my $length = length($value);

    # print "String content (after fixup) is [$value]\n";
    # print "String length is $length\n";
    # print "String container size is $sizeInclNull\n";

    if(($length + 1) > $sizeInclNull)
    {
        fatal("ERROR: Supplied string exceeds allows length");
    }

    return pack("Z$sizeInclNull",$value);
}

################################################################################
# Get space required to store an enum, based on the max value
################################################################################

sub enumSpace {
    my($maxEnumVal) = @_;
    if($maxEnumVal == 0)
    {
        # Enum needs at least one byte
        $maxEnumVal++;
    }

    # NOTE: Pass --noshort-enums command line option to force the code generator
    # to generate 4-byte enums instead of optimized enums.  Note there are a few
    # enumerations (primarily in PNOR header, etc.) that do not change size.
    # That is intentional in order to make this the single point of control over
    # binary compatibility.  Note that both FSP and Hostboot should always have
    # this policy in sync.  Also note that when Hostboot and FSP use optimized
    # enums, they must also be compiled with -fshort-enums compile option

    my $space = ($cfgShortEnums == 1) ?
        ceil(log($maxEnumVal+1) / (8 * log(2))) : 4;

    return $space;
}

################################################################################
# Get mininum # of bytes, in block size chunks, able to contain the input data
################################################################################

sub sizeBlockAligned {
    my ($size,$blockSize,$oneBlockMinimum) = @_;

    if( (!defined $size)
       || (!defined $blockSize)
       || (!defined $oneBlockMinimum) )
    {
        fatal("Caller must specify 'size', 'blockSize', 'oneBlockMinimum' "
            . "args.");
    }

    if(!$blockSize)
    {
        fatal("'blockSize' arg must be > 0.");
    }

    if(($size % $blockSize) || (($size==0) && $oneBlockMinimum) )
    {
        $size += ($blockSize - ($size % $blockSize));
    }

    return $size;
}

################################################################################
# Optimize white space for C++/doxygen documentation
################################################################################

sub optWhiteSpace {
    my($text) = @_;

    # Remove leading, trailing white space, then collapse excess internal
    # whitespace
    $text =~ s/^\s+|\s+$//g;
    $text =~ s/\s+/ /g;

    return $text;
}

################################################################################
# Wrap text into a C++/doxygen brief description
################################################################################

sub wrapBrief {
    my($text) = @_;

    my $brief_start      = " *  \@brief ";
    my $brief_continue   = " *      ";

    return wrap($brief_start,$brief_continue, optWhiteSpace($text))."\n";
}

################################################################################
# Wrap text into a C++ style comment
################################################################################

sub wrapComment {
    my($text) = @_;

    my $comment_start    = "    // ";
    my $comment_continue = "    // ";

    return wrap($comment_start,$comment_continue,optWhiteSpace($text))."\n";
}

################################################################################
# Calculate struct type name for a header file, based on its ID
################################################################################

sub calculateStructName {
    my($id) = @_;

    my $type = "";

    # Struct name is original ID with underscores removed and first letter of
    # each word capitalized
    my @words = split(/_/,$id);
    foreach my $word (@words)
    {
        $type .= ucfirst( lc($word) );
    }

    return $type;
}

################################################################################
# Return array containing only distinct target types that are actally in use
################################################################################

sub getInstantiatedTargetTypes {
    my($attributes) = @_;

    my %seen = ();
    my @uniqueTargetTypes = ();

    foreach my $targetInstance (@{$attributes->{targetInstance}})
    {
        push (@uniqueTargetTypes, $targetInstance->{type})
            unless $seen{$targetInstance->{type}}++;
    }

    return @uniqueTargetTypes;
}

################################################################################
# Return default value of zero for an attribute which is a POD numerical type
################################################################################

sub defaultZero {
    my($attributes,$typeInstance) = @_;

    # print STDOUT "Attribute's default value is 0\n";

    return 0;
}

################################################################################
# Return string default (empty string)
################################################################################

sub defaultString {
    my($attributes,$typeInstance) = @_;

    return "";
}

################################################################################
# Return default value for an attribute whose type is 'enumeration'
################################################################################

sub defaultEnum {
    my($attributes,$enumerationInstance) = @_;

    my $enumerationType = getEnumerationType(
        $attributes,$enumerationInstance->{id});

    # print STDOUT "Attribute enumeration's " .
    #    "(\"$enumerationType->{id}\") default is: " .
    #        $enumerationType->{default} . "\n";

    return $enumerationType->{default};
}

################################################################################
# Do nothing
################################################################################

sub null {

}

################################################################################
# Enforce special host boot mutex restrictions
################################################################################

sub enforceHbMutex {
    my($attribute,$value) = @_;

    if($value != 0)
    {
        fatal("HB mutex attribute default must always be 0, "
              . "was $value instead.");
    }

    if($attribute->{persistency} ne "volatile-zeroed")
    {
        fatal("HB mutex attribute persistency must be volatile-zeroed, "
              . "was $attribute->{persistency} instead");
    }
}

################################################################################
# Enforce string restrictions
################################################################################

sub enforceString {
    my($attribute,$value) = @_;

    if(!exists $attribute->{simpleType})
    {
        fatal("ERROR: Tried to enforce string policies on a non-simple type");
    }

    if(!exists $attribute->{simpleType}->{string})
    {
        fatal("ERROR: Did not find expected string element");
    }

    if(!exists $attribute->{simpleType}->{string}->{sizeInclNull})
    {
        fatal("ERROR: Did not find expected string sizeInclNull element");
    }

    my $size = $attribute->{simpleType}->{string}->{sizeInclNull};
    if($size <= 1)
    {
        fatal("ERROR: String size must be > 1 (string of size one is "
            . "only big enough to hold the empty string, which is not "
            . "useful)");
    }
}

################################################################################
# Get hash ref to supported simple types and their properties
################################################################################
my $g_simpleTypeProperties_cache = 0;

sub simpleTypeProperties {

    return $g_simpleTypeProperties_cache if ($g_simpleTypeProperties_cache);

    my %typesHoH = ();

    # Intentionally didn't wrap these to 80 columns to keep them lined up and
    # more readable/editable
    $typesHoH{"string"}      = { supportsArray => 0, canBeHex => 0, complexTypeSupport => 0, typeName => "char"                       , bytes => 1, bits => 8 , default => \&defaultString, alignment => 1, specialPolicies =>\&enforceString,  packfmt =>\&packString};
    $typesHoH{"int8_t"}      = { supportsArray => 1, canBeHex => 1, complexTypeSupport => 1, typeName => "int8_t"                     , bytes => 1, bits => 8 , default => \&defaultZero  , alignment => 1, specialPolicies =>\&null,           packfmt => "C" };
    $typesHoH{"int16_t"}     = { supportsArray => 1, canBeHex => 1, complexTypeSupport => 1, typeName => "int16_t"                    , bytes => 2, bits => 16, default => \&defaultZero  , alignment => 1, specialPolicies =>\&null,           packfmt =>\&pack2byte};
    $typesHoH{"int32_t"}     = { supportsArray => 1, canBeHex => 1, complexTypeSupport => 1, typeName => "int32_t"                    , bytes => 4, bits => 32, default => \&defaultZero  , alignment => 1, specialPolicies =>\&null,           packfmt =>\&pack4byte};
    $typesHoH{"int64_t"}     = { supportsArray => 1, canBeHex => 1, complexTypeSupport => 1, typeName => "int64_t"                    , bytes => 8, bits => 64, default => \&defaultZero  , alignment => 1, specialPolicies =>\&null,           packfmt =>\&pack8byte};
    $typesHoH{"uint8_t"}     = { supportsArray => 1, canBeHex => 1, complexTypeSupport => 1, typeName => "uint8_t"                    , bytes => 1, bits => 8 , default => \&defaultZero  , alignment => 1, specialPolicies =>\&null,           packfmt => "C" };
    $typesHoH{"uint16_t"}    = { supportsArray => 1, canBeHex => 1, complexTypeSupport => 1, typeName => "uint16_t"                   , bytes => 2, bits => 16, default => \&defaultZero  , alignment => 1, specialPolicies =>\&null,           packfmt =>\&pack2byte};
    $typesHoH{"uint32_t"}    = { supportsArray => 1, canBeHex => 1, complexTypeSupport => 1, typeName => "uint32_t"                   , bytes => 4, bits => 32, default => \&defaultZero  , alignment => 1, specialPolicies =>\&null,           packfmt =>\&pack4byte};
    $typesHoH{"uint64_t"}    = { supportsArray => 1, canBeHex => 1, complexTypeSupport => 1, typeName => "uint64_t"                   , bytes => 8, bits => 64, default => \&defaultZero  , alignment => 1, specialPolicies =>\&null,           packfmt =>\&pack8byte};
    $typesHoH{"enumeration"} = { supportsArray => 1, canBeHex => 1, complexTypeSupport => 0, typeName => "XMLTOHB_USE_PARENT_ATTR_ID" , bytes => 0, bits => 0 , default => \&defaultEnum  , alignment => 1, specialPolicies =>\&null,           packfmt => "packEnumeration"};
    $typesHoH{"hbmutex"}     = { supportsArray => 1, canBeHex => 1, complexTypeSupport => 0, typeName => "mutex_t*"                   , bytes => 8, bits => 64, default => \&defaultZero  , alignment => 8, specialPolicies =>\&enforceHbMutex, packfmt =>\&pack8byte};
    $typesHoH{"Target_t"}    = { supportsArray => 0, canBeHex => 1, complexTypeSupport => 0, typeName => "TARGETING::Target*"         , bytes => 8, bits => 64, default => \&defaultZero  , alignment => 8, specialPolicies =>\&null,           packfmt =>\&pack8byte};

    $g_simpleTypeProperties_cache = \%typesHoH;

    return $g_simpleTypeProperties_cache;
}

################################################################################
# Get attribute default
################################################################################

sub getAttributeDefault {
    my($attributeId,$attributes) = @_;

    my $default = "";
    my $simpleTypeProperties = simpleTypeProperties();

    foreach my $attribute (@{$attributes->{attribute}})
    {
        if ($attribute->{id} eq $attributeId)
        {
            if(exists $attribute->{simpleType})
            {
                for my $type (sort(keys %{$simpleTypeProperties}))
                {
                    # Note: must check for 'type' before 'default', otherwise
                    # might add value to the hash
                    if(exists $attribute->{simpleType}->{$type} )
                    {
                        # If attribute exists, or is not a HASH val (which can
                        # occur if the default element is omitted), then just
                        # grab the supplied value, otherwise use the default for
                        # the type
                        if(   (exists $attribute->{simpleType}->{$type}->
                                   {default})
                           && (ref ($attribute->{simpleType}->{$type}->
                                   {default})
                               ne "HASH") )
                        {
                            $default =
                                $attribute->{simpleType}->{$type}->{default};
                        }
                        else
                        {
                           $default = $simpleTypeProperties->{$type}{default}->(
                                $attributes,$attribute->{simpleType}->{$type} );
                        }
                        last;
                    }
                }
            }
            elsif(exists $attribute->{complexType})
            {
                my $cplxDefault = { } ;
                my $i = 0;
                foreach my $field (@{$attribute->{complexType}->{field}})
                {
                    $cplxDefault->{field}->[$i]->{id} = $field->{name};
                    $cplxDefault->{field}->[$i]->{value} = $field->{default};
                    $i++;
                }
                return $cplxDefault;
            }
            elsif(exists $attribute->{nativeType})
            {
                if(   exists $attribute->{nativeType}->{name}
                   && ($attribute->{nativeType}->{name} eq "EntityPath"))
                {
                    $default =  "MustBeOverriddenByTargetInstance";
                }
                else
                {
                    fatal("Cannot provide default for unsupported nativeType.");
                }
            }
            else
            {
                fatal("Unrecognized value type.");
            }

            last;
        }
    }

    return $default;
}

################################################################################
# Get target attributes
################################################################################

sub getTargetAttributes {
    my($type,$attributes,$attrhasha) = @_;

    foreach my $targetType (@{$attributes->{targetType}})
    {
        if($targetType->{id} eq $type)
        {
            if(exists $targetType->{parent})
            {
                getTargetAttributes($targetType->{parent},
                    $attributes,$attrhasha);
            }

            foreach my $attr (@{$targetType->{attribute}})
            {
                $attrhasha->{ $attr->{id} } = $attr;

                if(!exists $attrhasha->{ $attr->{id}}->{default})
                {
                   my $default = getAttributeDefault($attr->{id},$attributes);
                   $attrhasha->{ $attr->{id}}->{default} = $default;
                }
            }

            last;
        }
    }
}

################################################################################
# Compute maximum enumerator value for a given enumeration
################################################################################

sub maxEnumValue {
    my($enumeration) = @_;

    my $max = 0;
    my $candidateMax = 0;
    foreach my $enumerator (@{$enumeration->{enumerator}})
    {
        my $candidateMax = enumNameToValue($enumeration,$enumerator->{name});
        if($candidateMax > $max)
        {
            $max = $candidateMax;
        }
    }

    return $max;
}

################################################################################
# Serialize an enumeration to data buffer
################################################################################

sub packEnumeration {
    my($enumeration,$value) = @_;

    my $binaryData;

    # Determine space required for max enum
    my $bytes = enumSpace( maxEnumValue($enumeration) );

    $value = unhexify($value);

    # Encode the value
    for (my $count=$bytes-1; $count >= 0; $count--)
    {
        if($cfgBigEndian)
        {
            $binaryData .= pack1byte(0xFF & ($value >> (8*$count)));
        }
        else # Little endian
        {
            $binaryData .= pack1byte(
                    0xFF & ($value >> (8*($bytes - 1 - $count))));
        }
    }

    if( (length $binaryData) < 1)
    {
        fatal("Failed to write binary data for enumeration.");
    }

    #print "           Enum description: ", $enumeration->{description}, "\n";
    #print "Enum storage space required: ", $bytes, "\n";
    #print "              Value encoded: ", $value, "\n";
    #print "     Final length of encode: ", (length $binaryData), "\n";

    return $binaryData;
}

################################################################################
# Convert enumerator name into equivalent enumerator value for given enumeration
################################################################################

sub enumNameToValue {
    my ($enumeration,$enumeratorName) = @_;

    my $nextEnumeratorValue = 0;
    my $found = 0;
    my $enumeratorValue;

    if (defined $enumeration->{__optimized})
    {
        if (defined $enumeration->{__optimized}->{$enumeratorName})
        {
            $found = 1;
            $enumeratorValue = $enumeration->{__optimized}->{$enumeratorName};
        }
    }
    else
    {
        foreach my $enumerator (@{$enumeration->{enumerator}})
        {
            my $currentEnumeratorValue;
            if(exists $enumerator->{value} )
            {
                $currentEnumeratorValue = unhexify($enumerator->{value});
                $nextEnumeratorValue = $currentEnumeratorValue + 1;
            }
            else
            {
                $currentEnumeratorValue = $nextEnumeratorValue;
                $nextEnumeratorValue += 1;
            }

            $enumeration->{__optimized}->{$enumerator->{name}}
                = $currentEnumeratorValue;

            if($enumerator->{name} eq $enumeratorName)
            {
                $found = 1;
                $enumeratorValue = $currentEnumeratorValue;
            }
        }
    }

    if(!$found)
    {
        my $enumerationName = $enumeration->{id};

        fatal("Could not convert enumerator name \"$enumeratorName\"into "
            . "enumerator value in \"$enumerationName\".");
    }

    return $enumeratorValue;
}

################################################################################
# Query if target instance is an FSP target
################################################################################

my %g_fspTargetTypesCache = ();

sub isFspTargetInstance {
    my($attributes,$targetInstance) = @_;
    my $fspTargetInstance = 0;

    if(%g_fspTargetTypesCache)
    {
        $fspTargetInstance = %g_fspTargetTypesCache->{$targetInstance->{type}};
    }
    else
    {
        %g_fspTargetTypesCache =
            map { $_->{id} => exists $_->{fspOnly} ? 1:0 } 
                @{$attributes->{targetType}};
    }
    
    return $fspTargetInstance;
}

################################################################################
# Object which accumulates/flushes bit field data
################################################################################

{

package Accumulator;

################################################################################
# Constructor; create a new Accumulator object
################################################################################

sub new {
    my ($class) = @_;
    my $self = { _currentType => "", _accumulator => "", _bits => 0 };

    bless $self, $class;
    return $self;
}

################################################################################
# Accumulate a new bit field
################################################################################

sub accumulate {
    my($self,$type,$bits,$value) = @_;

    my $binaryData;
    my $simpleTypeProperties = main::simpleTypeProperties();

    if($bits > $simpleTypeProperties->{$type}{bits})
    {
        main::fatal("Too many bits ($bits) for type ($type).");
    }

    if($self->{_currentType} eq "")
    {
        $self->{_currentType} = $type;
        $self->{_bits} = $bits;
    }
    elsif($self->{_currentType} eq $type)
    {
        if($self->{_bits} + $bits >
            $simpleTypeProperties->{$self->{_currentType}}{bits})
        {
            $binaryData = $self->releaseAndClear();
            $self->{_currentType} = $type;
            $self->{_bits} = $bits;
        }
        else
        {
            $self->{_bits} += $bits;
        }
    }
    else
    {
         $binaryData = $self->releaseAndClear();
         $self->{_currentType} = $type;
         $self->{_bits} = $bits;
    }

    for(my $count = 0; $count < $bits; $count++)
    {
        if($cfgBigEndian)
        {
            if( 1 & ($value >> $bits - $count - 1))
            {
                $self->{_accumulator} .= "1";
            }
            else
            {
                $self->{_accumulator} .= "0";
            }
        }
        else
        {
            if( 1 & ($value >> $count))
            {
                $self->{_accumulator} .= "1";
            }
            else
            {
                $self->{_accumulator} .= "0";
            }
        }
    }

    return $binaryData;
}

################################################################################
# Release the accumulator (if non-empty) to the caller and clear
################################################################################

sub releaseAndClear {
    my($self) = @_;

    my $binaryData;

    if($self->{_currentType} ne "")
    {
        my $simpleTypeProperties = main::simpleTypeProperties();

        if($cfgBigEndian)
        {
            $binaryData = pack
            ("B$simpleTypeProperties->{$self->{_currentType}}{bits}",
                $self->{_accumulator});
        }
        else # Little endian, inverse order
        {
            $binaryData = pack
            ("b$simpleTypeProperties->{$self->{_currentType}}{bits}",
                $self->{_accumulator});
        }

        $self->{_accumulator} = "";
        $self->{_currentType} = "";
        $self->{_bits} = 0;
    }

    return $binaryData;
}

1;

}

################################################################################
# Pack a complex type into a binary data stream
################################################################################

sub packComplexType {
    my ($attributes,$complexType,$attributeDefault) = @_;

    my $binaryData;
    my $simpleTypeProperties = simpleTypeProperties();

    my $accumulator = new Accumulator();

    # Build using each field
    foreach my $field (@{$complexType->{field}})
    {
        # print STDERR "Field   = ", $field->{name}, "\n";
        # print STDERR "Default = ", $field->{default}, "\n";
        # print STDERR "Bits    = ", $field->{bits}, "\n";
        # print STDERR "Type    = ", $field->{type}, "\n";

        my $found = 0;
        foreach my $default (@{$attributeDefault->{field}})
        {
            if($default->{id} eq $field->{name})
            {
                $found = 1;
                if(exists $field->{bits})
                {
                    $binaryData .= $accumulator->accumulate(
                        $field->{type},unhexify($field->{bits}),
                           unhexify($default->{value}));
                }
                # If non-bitfield
                else
                {
                    $binaryData .= $accumulator->releaseAndClear();

                    # If native "EntityPath" type, process accordingly
                    if($field->{type} eq "EntityPath")
                    {
                         $binaryData .= packEntityPath($attributes,
                            $default->{value});
                    }
                    # If not a defined simple type, process as an enumeration
                    elsif(!exists $simpleTypeProperties->{$field->{type}})
                    {
                        my $enumerationType = getEnumerationType(
                            $attributes,$field->{type});
                        my $enumeratorValue = enumNameToValue($enumerationType,
                            $default->{value});
                        $binaryData .= packEnumeration($enumerationType,
                            $enumeratorValue);
                    }
                    # Pack easy types using 'pack', otherwise invoke appropriate
                    # (possibly workaround) callback function
                    elsif(exists $simpleTypeProperties->{$field->{type}}
                       && $simpleTypeProperties->{$field->{type}}
                            {complexTypeSupport})
                    {
                        my $defaultValue = $default->{value};
                        if($simpleTypeProperties->{$field->{type}}{canBeHex})
                        {
                            $defaultValue = unhexify($defaultValue);
                        }

                        if(ref ($simpleTypeProperties->{$field->{type}}
                            {packfmt}) eq "CODE")
                        {
                            $binaryData .=
                                $simpleTypeProperties->{$field->{type}}
                                    {packfmt}->($defaultValue);
                        }
                        else
                        {
                            $binaryData .= pack(
                                $simpleTypeProperties->{$field->{type}}
                                    {packfmt},$defaultValue);
                        }
                    }
                    else
                    {
                        fatal("Field type $field->{type} not supported in "
                            . "complex type.");
                    }
                }

                last;
            }
        }

        if(!$found)
        {
            fatal("Could not find value for field $field->{name} of type $field->{type}");
        }
    }

    $binaryData .= $accumulator->releaseAndClear();

    return $binaryData;
}

################################################################################
# Pack an entity path into a binary data stream
################################################################################

sub packEntityPath {
    my($attributes,$value) = @_;

    my $binaryData;

    my $maxPathElements = 10;
    my ($typeStr,$path) = split(/:/,$value);
    my (@paths) = split(/\//,$path);

    my $type = 0;

    # Trim whitespace from the type
    $typeStr =~ s/^\s+|\s+$//g;
    if($typeStr eq "physical")
    {
        $type = 2;
    }
    elsif($typeStr eq "affinity")
    {
        $type = 1;
    }
    else
    {
        fatal("Unsupported enity path type of [$value], [$typeStr], [$path].");
    }

    if( (scalar @paths) > $maxPathElements)
    {
        fatal("Path elements cannot be greater than $maxPathElements.");
    }

    if($cfgBigEndian)
    {
        $binaryData .= pack1byte((0xF0 & ($type << 4)) +
            (0x0F & (scalar @paths)));
    }
    else # Little endian
    {
        $binaryData .= pack1byte((0x0F & ($type)) +
            (0xF0 & ((scalar @paths) << 4)));
    }

    foreach my $pathElement (@paths)
    {
        my ($pathType,$pathInstance) = split(/-/,$pathElement);
        $pathType = uc($pathType);

        foreach my $attr (@{$attributes->{attribute}})
        {
            if($attr->{id} eq "TYPE")
            {
                $pathType =
                enumNameToValue(
                  getEnumerationType($attributes,
                   $attr->{simpleType}->{enumeration}->{id}),$pathType);
                $binaryData .= pack1byte($pathType);
                $binaryData .= pack1byte($pathInstance);
                last;
            }
        }
    }

    if($maxPathElements > (scalar @paths))
    {
        $binaryData .= pack("C".(($maxPathElements - scalar @paths)*2));
    }

    return $binaryData;
}

################################################################################
# Pack a single, simple attribute into a binary data stream
################################################################################

sub packSingleSimpleTypeAttribute {
    my($binaryDataRef,$attributesRef,$attributeRef,$typeName,$value) = @_;

    my $simpleType = $$attributeRef->{simpleType};
    my $simpleTypeProperties = simpleTypeProperties();

    if($typeName eq "enumeration")
    {
        my $enumeration = getEnumerationType($$attributesRef,$simpleType->
            {enumeration}->{id});

        # Here $value is the enumerator name
        my $enumeratorValue = enumNameToValue($enumeration,$value);
        $$binaryDataRef .= packEnumeration($enumeration,$enumeratorValue);
    }
    else
    {
        if($simpleTypeProperties->{$typeName}{canBeHex})
        {
            $value = unhexify($value);
        }

        # Apply special policy enforcement, if any
        $simpleTypeProperties->{$typeName}{specialPolicies}->($$attributeRef,
            $value);

        if(ref ($simpleTypeProperties->{$typeName}{packfmt}) eq "CODE")
        {
            $$binaryDataRef .= $simpleTypeProperties->{$typeName}{packfmt}->
                               ($value,$$attributeRef);
        }
        else
        {
            $$binaryDataRef .= pack($simpleTypeProperties->{$typeName}{packfmt},
                                    $value);
        }
    }
}

################################################################################
# Pack generic attribute into a binary data stream
################################################################################

sub packAttribute {
    my($attributes,$attribute,$value) = @_;

    my $binaryData;

    my $alignment = 1;
    if(exists $attribute->{simpleType})
    {
        my $simpleType = $attribute->{simpleType};
        my $simpleTypeProperties = simpleTypeProperties();

        for my $typeName (sort(keys %{$simpleType}))
        {
            if(exists $simpleTypeProperties->{$typeName})
            {
                $alignment = $simpleTypeProperties->{$typeName}{alignment};

                if (($simpleTypeProperties->{$typeName}{supportsArray}) &&
                    (exists $simpleType->{array}))
                {
                    # This is an array attribute, handle the value parameter as
                    # an array, if there are not enough values for the whole
                    # array then use the last value to fill in the remainder

                    # Figure out the array size (possibly multidimensional)
                    my $arraySize = 1;
                    my @bounds = split(/,/,$simpleType->{array});
                    foreach my $bound (@bounds)
                    {
                        $arraySize *= $bound;
                    }

                    # Split the values into an array
                    my @values = split(/,/,$value);
                    my $valueArraySize = scalar(@values);

                    # Iterate over the entire array creating values
                    my $val = "";
                    for (my $i = 0; $i < $arraySize; $i++)
                    {
                        if ($i < $valueArraySize)
                        {
                            # Get the value from the value array
                            $val = $values[$i];
                        }
                        # else use the last value

                        packSingleSimpleTypeAttribute(\$binaryData,
                            \$attributes, \$attribute, $typeName, $val);
                    }
                }
                else
                {
                    # Not an array attribute
                    packSingleSimpleTypeAttribute(\$binaryData,
                        \$attributes, \$attribute,$typeName, $value);
                }

                last;
            }
        }

        if( (length $binaryData) < 1)
        {
            fatal("Error requested simple type not supported.  Keys are ("
                . join(',',sort(keys %{$simpleType})) . ")");
        }
    }
    elsif(exists $attribute->{complexType})
    {
        if(ref ($value) eq "HASH" )
        {
            $binaryData = packComplexType($attributes,$attribute->{complexType},
                $value);
        }
        else
        {
            fatal("Warning cannot serialize non-hash complex type.");
        }
    }
    elsif(exists $attribute->{nativeType})
    {
        if($attribute->{nativeType}->{name} eq "EntityPath")
        {
            $binaryData = packEntityPath($attributes,$value);
        }
        else
        {
            fatal("Error nativeType not supported on attribute ID = "
                . "$attribute->{id}.");
        }
    }
    else
    {
        fatal("Unsupported attribute type on attribute ID = $attribute->{id}.");
    }

    if( (length $binaryData) < 1)
    {
        fatal("Serialization failed for attribute ID = $attribute->{id}.");
    }

    return ($binaryData,$alignment);
}

################################################################################
# Get the PNOR base address from host boot code
################################################################################

sub getPnorBaseAddress {
    my($vmmConstsFile) = @_;
    my $pnorBaseAddress = 0;

    open(VMM_CONSTS_FILE,"<$vmmConstsFile")
      or fatal ("VMM Constants file: \"$vmmConstsFile\" could not be opened.");

    foreach my $line (<VMM_CONSTS_FILE>)
    {
        chomp($line);
        if( $line =~ /VMM_VADDR_ATTR_RP/)
        {
            $line =~ s/[^0-9\*]//g;
            $pnorBaseAddress = eval $line;
            last;
        }
    }

    if($pnorBaseAddress == 0)
    {
        fatal("PNOR base address was zero!");
    }

    return $pnorBaseAddress;
}

################################################################################
# Write the PNOR targeting image
################################################################################

sub generateTargetingImage {
    my($vmmConstsFile, $attributes, $Target_t) = @_;

    # 128 MB virtual memory offset between sections
    #@TODO Need the final value after full host boot support is implemented.
    my $vmmSectionOffset = 128 * 1024 * 1024; # 128MB

    # Virtual memory addresses corresponding to the start of the targeting image
    # PNOR/heap sections
    my $pnorRoBaseAddress    = getPnorBaseAddress($vmmConstsFile);
    my $pnorRwBaseAddress    = $pnorRoBaseAddress    + $vmmSectionOffset;
    my $heapPnorInitBaseAddr = $pnorRwBaseAddress    + $vmmSectionOffset;
    my $heapZeroInitBaseAddr = $heapPnorInitBaseAddr + $vmmSectionOffset;

    # TODO RTC: 35451
    # Split "fsp" into additional sections
    my $fspBaseAddr          = $heapZeroInitBaseAddr + $vmmSectionOffset;

    # Reserve 256 bytes for the header, then keep track of PNOR RO offset
    my $headerSize = 256;
    my $offset = $headerSize;

    # Reserve space for the pointer to the # of targets, update later;
    my $numTargetsPointer = 0;
    my $numTargetsPointerBinData = pack8byte($numTargetsPointer);
    $offset += (length $numTargetsPointerBinData);

    ############################################################################
    # Build the attribute list for each unique CTM
    ############################################################################

    # Get an array of only the unique types of targets actually used by the
    # aggregation of target instances.
    my @targetTypes = getInstantiatedTargetTypes($attributes);

    my $attributeIdEnumeration = getAttributeIdEnumeration($attributes);

    my %attributeListTypeHoH = ();
    my $attributeListBinData;

    # For each unique type of target modeled, create the attribute list
    foreach my $targetType (@targetTypes)
    {
        # Create the attribute list associated with each target type
        #@TODO Eventually we'll need criteria to order the attributes
        # for code update
        my %attrhash = ();
        getTargetAttributes($targetType, $attributes,\%attrhash);

        # Serialize per target type attribute list
        my $perTargetTypeAttrBinData;
        for my $attributeId (sort(keys %attrhash))
        {
            $perTargetTypeAttrBinData .= packEnumeration(
                $attributeIdEnumeration,
                enumNameToValue($attributeIdEnumeration,$attributeId));
        }

        # Save offset of the attribute list, tied to the type
        $attributeListTypeHoH{$targetType}{offset} = $offset;
        $attributeListTypeHoH{$targetType}{elements} = scalar keys %attrhash;
        $attributeListTypeHoH{$targetType}{size} =
            (length $perTargetTypeAttrBinData);

        #print "Target type: $targetType\n";
        #print "   elements: $attributeListTypeHoH{$targetType}{elements}\n";
        #print "     offset: $attributeListTypeHoH{$targetType}{offset}\n";
        #print "       size: $attributeListTypeHoH{$targetType}{size}\n";

        # Append attribute data for this part to the attribute list subsection
        $attributeListBinData .= $perTargetTypeAttrBinData;

        # Increment the offset
        $offset += (length $perTargetTypeAttrBinData);
    }

    # For each target instance ...

    #@TODO Eventually we'll need criteria to order the attributes
    # for code update.  At minimum, ensure that we always process at this level
    # in the given order
    my @targetsAoH = ();
    foreach my $targetInstance (@{$attributes->{targetInstance}})
    {
        push(@targetsAoH, $targetInstance);
    }
    my $numTargets = @targetsAoH;

    my $numAttributes = 0;
    foreach my $targetInstance (@targetsAoH)
    {
        my %attrhash = ();
        getTargetAttributes($targetInstance->{type}, $attributes,\%attrhash);
        $numAttributes += keys %attrhash;
    }

    # Reserve # pointers * sizeof(pointer)
    my $startOfAttributePointers = $offset;
    # print "Total attributes = $numAttributes\n";
    $offset += ($numAttributes * (length pack8byte(0) ));

    # Now we can determine the pointer to the number of targets
    # Don't increment the offset; already accounted for
    $numTargetsPointer = $pnorRoBaseAddress + $offset;
    $numTargetsPointerBinData = pack8byte($numTargetsPointer);
    my $numTargetsBinData = pack4byte($numTargets);
    $offset += (length $numTargetsBinData);

    my $firstTgtPtr = $pnorRoBaseAddress + $offset;
    my $roAttrBinData;
    my $heapZeroInitOffset = 0;
    my $heapZeroInitBinData;
    my $heapPnorInitOffset = 0;
    my $heapPnorInitBinData;
    my $rwAttrBinData;
    my $rwOffset = 0;

    # TODO RTC: 35451   
    # Split into more granular sections
    my $fspOffset = 0;
    my $fspBinData;

    my $attributePointerBinData;
    my $targetsBinData;

    # Ensure consistent ordering of target instances
    my $attrAddr = $pnorRoBaseAddress + $startOfAttributePointers;

    foreach my $targetInstance (@targetsAoH)
    {
        my $data;

         # print "TargetInstance: $targetInstance->{id}\n";
         # print "    Attributes:  ",
         # $attributeListTypeHoH{$targetInstance->{type}}{elements}, "\n" ;
         # print "        offset:  ",
         # $attributeListTypeHoH{$targetInstance->{type}}{offset}, "\n" ;

        # Create target record
        $data .= pack4byte(
            $attributeListTypeHoH{$targetInstance->{type}}{elements});
        $data .= pack8byte(
              $attributeListTypeHoH{$targetInstance->{type}}{offset}
            + $pnorRoBaseAddress);
        $data .= pack8byte($attrAddr);
        $attrAddr += $attributeListTypeHoH{$targetInstance->{type}}{elements}
            * (length pack8byte(0));

        # Increment the offset
        $offset += (length $data);

        # Add it to the target sub-section
        $targetsBinData .= $data;
    }

    my $pnorRoOffset = $offset;
    my $attributesWritten = 0;

    foreach my $targetInstance (@targetsAoH)
    {
        my $data;
        my %attrhash = ();
        my @AoH = ();

        # Ensure consistent ordering of attributes for each target type
        # Get the attribute list associated with each target type
        #@TODO Attributes must eventually be ordered correctly for code update
        getTargetAttributes($targetInstance->{type}, $attributes,\%attrhash);

        # Update hash with any per-instance overrides, but only if that
        # attribute has already been defined
        foreach my $attr (@{$targetInstance->{attribute}})
        {
            if(exists $attrhash{$attr->{id}})
            {
                $attrhash{ $attr->{id} } = $attr;
            }
            else
            {
                fatal("Target instance \"$targetInstance->{id}\" cannot "
                    . "override attribute \"$attr->{id}\" unless "
                    . "the attribute has already been defined in the target "
                    . "type inheritance chain.");
            }
        }

        # Flag if target is FSP specific; in that case store all of its 
        # attributes in the FSP section, regardless of whether they are 
        # themselves FSP specific.  Only need to do this 1x per target instance
        my $fspTarget = isFspTargetInstance($attributes,$targetInstance);
 
        my %attributeDefCache =
            map { $_->{id} => $_} @{$attributes->{attribute}};

        for my $attributeId (sort(keys %attrhash))
        {
            my $attributeDef = $attributeDefCache{$attributeId};
            if (not defined $attributeDef)
            {
                fatal("Attribute $attributeId is not found.");
            }

            my $section;
            # TODO RTC: 35451
            # Split "fsp" into more sections later
            if(   (exists $attributeDef->{fspOnly})
               || ($fspTarget))
            {
                $section = "fsp";
            }
            elsif( exists $attributeDef->{writeable}
                    && $attributeDef->{persistency} eq "non-volatile" )
            {
                $section = "pnor-rw";
            }
            elsif ( !exists $attributeDef->{writeable}
                    && $attributeDef->{persistency} eq "non-volatile")
            {
                $section = "pnor-ro";
            }
            elsif ($attributeDef->{persistency} eq "volatile" )
            {
                $section = "heap-pnor-initialized";
            }
            elsif($attributeDef->{persistency} eq "volatile-zeroed")
            {
                $section = "heap-zero-initialized";
            }
            else
            {
                fatal("Persistency not supported.");
            }

            if($section eq "pnor-ro")
            {
                if ((exists ${$Target_t}{$attributeId}) &&
                    ($attrhash{$attributeId}->{default} != 0))
                {
                    my $index = $attrhash{$attributeId}->{default} - 1;
                    $index *= 20; # length(N + quad + quad)
                    $attrhash{$attributeId}->{default} = $index + $firstTgtPtr;
                }

                my ($rodata,$alignment) = packAttribute($attributes,
                        $attributeDef,
                        $attrhash{$attributeId}->{default});

                # Align the data as necessary
                my $pads = ($alignment - ($offset % $alignment))
                    % $alignment;
                $roAttrBinData .= pack ("@".$pads);
                $offset += $pads;

                        $attributePointerBinData .= pack8byte(
                            $offset + $pnorRoBaseAddress);

                $offset += (length $rodata);

                $roAttrBinData .= $rodata;
            }
            elsif($section eq "pnor-rw")
            {
                my ($rwdata,$alignment) = packAttribute($attributes,
                        $attributeDef,
                        $attrhash{$attributeId}->{default});

                #print "Wrote to pnor-rw value ",$attributeDef->{id}, ",
                #", $attrhash{$attributeId}->{default}," \n";

                # Align the data as necessary
                my $pads = ($alignment - ($rwOffset % $alignment))
                    % $alignment;
                $rwAttrBinData .= pack ("@".$pads);
                $rwOffset += $pads;

                $attributePointerBinData .= pack8byte(
                    $rwOffset + $pnorRwBaseAddress);

                $rwOffset += (length $rwdata);

                $rwAttrBinData .= $rwdata;

            }
            elsif($section eq "heap-zero-initialized")
            {
                my ($heapZeroInitData,$alignment) = packAttribute(
                        $attributes,
                        $attributeDef,$attrhash{$attributeId}->{default});

                # Align the data as necessary
                my $pads = ($alignment - ($heapZeroInitOffset
                            % $alignment)) % $alignment;
                $heapZeroInitBinData .= pack ("@".$pads);
                $heapZeroInitOffset += $pads;

                $attributePointerBinData .= pack8byte(
                    $heapZeroInitOffset + $heapZeroInitBaseAddr);

                $heapZeroInitOffset += (length $heapZeroInitData);

                $heapZeroInitBinData .= $heapZeroInitData;

            }
            elsif($section eq "heap-pnor-initialized")
            {
                my ($heapPnorInitData,$alignment) = packAttribute(
                        $attributes,
                        $attributeDef,$attrhash{$attributeId}->{default});

                # Align the data as necessary
                my $pads = ($alignment - ($heapPnorInitOffset
                            % $alignment)) % $alignment;
                $heapPnorInitBinData .= pack ("@".$pads);
                $heapPnorInitOffset += $pads;

                $attributePointerBinData .= pack8byte(
                    $heapPnorInitOffset + $heapPnorInitBaseAddr);

                $heapPnorInitOffset += (length $heapPnorInitData);

                $heapPnorInitBinData .= $heapPnorInitData;
            }
            # TODO RTC: 35451
            # Split FSP section into more granular sections
            elsif($section eq "fsp")
            {
                my ($fspData,$alignment) = packAttribute(
                        $attributes,
                        $attributeDef,$attrhash{$attributeId}->{default});

                # Align the data as necessary
                my $pads = ($alignment - ($fspOffset
                            % $alignment)) % $alignment;
                $fspBinData .= pack ("@".$pads);
                $fspOffset += $pads;

                $attributePointerBinData .= pack8byte(
                    $fspOffset + $fspBaseAddr);

                $fspOffset += (length $fspData);

                $fspBinData .= $fspData;
            }  
            else
            {
                fatal("Could not find a suitable section.");
            }

            $attributesWritten++;

        } # End attribute loop

    } # End target instance loop

    if($numAttributes != $attributesWritten)
    {
        fatal("Number of attributes expected, $numAttributes, does not match "
              . "what was written to PNOR, $attributesWritten.");
    }

    # Build header data

    my $headerBinData;
    my $blockSize = 4*1024;

    my %sectionHoH = ();
    $sectionHoH{ pnorRo }{ offset } = 0;
    $sectionHoH{ pnorRo }{ type   } = 0;
    $sectionHoH{ pnorRo }{ size   } = sizeBlockAligned($offset,$blockSize,1);

    $sectionHoH{ pnorRw }{ offset } =
        $sectionHoH{pnorRo}{offset} + $sectionHoH{pnorRo}{size};
    $sectionHoH{ pnorRw }{ type   } = 1;
    $sectionHoH{ pnorRw }{ size   } = sizeBlockAligned($rwOffset,$blockSize,1);

    $sectionHoH{ heapPnorInit }{ offset } =
        $sectionHoH{pnorRw}{offset} + $sectionHoH{pnorRw}{size};
    $sectionHoH{ heapPnorInit }{ type   } = 2;
    $sectionHoH{ heapPnorInit }{ size   } =
        sizeBlockAligned($heapPnorInitOffset,$blockSize,1);

    $sectionHoH{ heapZeroInit }{ offset } =
        $sectionHoH{heapPnorInit}{offset} + $sectionHoH{heapPnorInit}{size};
    $sectionHoH{ heapZeroInit }{ type   } = 3;
    $sectionHoH{ heapZeroInit }{ size   } =
        sizeBlockAligned($heapZeroInitOffset,$blockSize,1);
  
    # TODO RTC: 35451
    # Split "fsp" into additional sections
    if($cfgIncludeFspAttributes)
    {
        # zeroInitSection occupies no space in the binary, so set the FSP
        # section address to that of the zeroInitSection
        $sectionHoH{ fsp }{ offset } =
             $sectionHoH{heapZeroInit}{offset};
        $sectionHoH{ fsp }{ type } = 4;
        $sectionHoH{ fsp }{ size } =
            sizeBlockAligned($fspOffset,$blockSize,1);
    }

    my $numSections = keys %sectionHoH;

    # Version 1.0 to start with
    my $headerMajorMinorVersion = 0x00010000;
    my $eyeCatcher = 0x54415247; # TARG
    my $sizeOfSection = 9;
    my $offsetToSections = 0;

    $headerBinData .= pack4byte($eyeCatcher);
    $headerBinData .= pack4byte($headerMajorMinorVersion);
    $headerBinData .= pack4byte($headerSize);
    $headerBinData .= pack4byte($vmmSectionOffset);
    $headerBinData .= pack8byte($pnorRoBaseAddress);
    $headerBinData .= pack4byte($sizeOfSection);
    $headerBinData .= pack4byte($numSections);
    $headerBinData .= pack4byte($offsetToSections);

    # TODO RTC: 35451
    # Split "fsp" into additional sections
    my @sections = ("pnorRo","pnorRw","heapPnorInit","heapZeroInit");
    if($cfgIncludeFspAttributes)
    {
        push(@sections,"fsp");
    }

    foreach my $section (@sections)
    {
        $headerBinData .= pack1byte($sectionHoH{$section}{type});
        $headerBinData .= pack4byte($sectionHoH{$section}{offset});
        $headerBinData .= pack4byte($sectionHoH{$section}{size});
    }

    # Serialize PNOR RO section to multiple of 4k page size (pad if necessary)

    # First 256 bytes is  RO header (pad if necessary)
    if((length $headerBinData) > $headerSize)
    {
        fatal("Header data of length " . (length $headerBinData) . " is larger "
            . "than allocated amount of $headerSize.");
    }

    my $outFile;
    $outFile .= $headerBinData;
    my $padSize = sizeBlockAligned((length $headerBinData),$headerSize,1)
        - (length $headerBinData);
    $outFile .= pack ("@".$padSize);

    # Remaining data belongs to targeting
    $outFile .= $numTargetsPointerBinData;
    $outFile .= $attributeListBinData;
    $outFile .= $attributePointerBinData;
    $outFile .= $numTargetsBinData;
    $outFile .= $targetsBinData;
    $outFile .= $roAttrBinData;
    $outFile .= pack ("@".($sectionHoH{pnorRo}{size} - $offset));

    # Serialize PNOR RW section to multiple of 4k page size (pad if necessary)
    $outFile .= $rwAttrBinData;
    $outFile .= pack("@".($sectionHoH{pnorRw}{size} - $rwOffset));

    # Serialize PNOR initiated heap section to multiple of 4k page size (pad if
    # necessary)
    $outFile .= $heapPnorInitBinData;
    $outFile .= pack("@".($sectionHoH{heapPnorInit}{size}
        - $heapPnorInitOffset));

    # TODO RTC: 35451
    # Serialize FSP section to multiple of 4k page size (pad if
    # necessary)
    if($cfgIncludeFspAttributes)
    {
        $outFile .= $fspBinData;
        $outFile .= pack("@".($sectionHoH{fsp}{size}
            - $fspOffset));
    }

    return $outFile;
}

__END__

=head1 NAME

xmltohb.pl

=head1 SYNOPSIS

xmltohb.pl [options] [file ...]

=head1 OPTIONS

=over 8

=item B<--help>

Print a brief help message and exits.

=item B<--man>

Prints the manual page and exits.

=item B<--hb-xml-file>

File containing the intermediate representation of the host boot XML just prior
to compilation down to images and source files (Default is ./hb.xml)

=item B<--fapi-attributes-xml-file>

File containing the FAPI HWP attributes, for purposes of configuring the
attribute mappings between FAPI and targeting code

=item B<--src-output-dir>=DIRECTORY

Sets the output directory for generated source files (default is the current
directory)

=item B<--img-output-dir>=DIRECTORY

Sets the output directory for generated binary files
(default is the current directory)

=item B<--img-output-file>=FILE

Sets the file to receive the PNOR targeting image output (default
./targeting.bin).  Only used when generating the PNOR targeting image

=item B<--vmm-consts-file>=FILE

Indicates the file containing the base virtual address of the attributes
(default is src/include/usr/vmmconst.h).  Only used when generating the PNOR
targeting image

=item B<--big-endian>

Writes data structures to file in big endian format (default)

=item B<--nobig-endian>

Writes data structures to targeting image in little endian format (override to
default).  Supports x86 environments.

=item B<--short-enums>

Writes optimially sized enumerations to binary image (default). Any code which
uses the binary image or enumerations from generated header files must also
be compiled with short enumeration support.  This saves at minimum 0 and at most
3 bytes for each enumeration value.

=item B<--noshort-enums>

Writes maximum sized enumerations to binary image (default). Any code which
uses the binary image or enumerations from generated header files must not
be compiled with short enumeration support.  Every enumeration will consume 4
bytes by default

=item B<--include-fsp-attributes>

Emits FSP specific attributes and targets into the generated binaries and
generated code.  

=item B<--noinclude-fsp-attributes>

Omits FSP specific attributes and targets from the generated binaries and
generated code.  This is the default behavior.

=item B<--verbose>

Prints out some internal workings

=back

=head1 DESCRIPTION

B<xmltohb.pl> will process a set of input .xml files and emit source files and
a PNOR targeting image binary to facilitate compiling and configuring host boot
respectively.

=cut


