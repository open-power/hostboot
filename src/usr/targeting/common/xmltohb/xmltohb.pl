#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/common/xmltohb/xmltohb.pl $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2012,2015
# [+] International Business Machines Corp.
#
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
# implied. See the License for the specific language governing
# permissions and limitations under the License.
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
use Env;

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
my $CfgSMAttrFile = "";
my $cfgAddVersionPage = 0;

GetOptions("hb-xml-file:s" => \$cfgHbXmlFile,
           "src-output-dir:s" =>  \$cfgSrcOutputDir,
           "img-output-dir:s" =>  \$cfgImgOutputDir,
           "fapi-attributes-xml-file:s" => \$cfgFapiAttributesXmlFile,
           "img-output-file:s" =>  \$cfgImgOutputFile,
           "vmm-consts-file:s" =>  \$cfgVmmConstsFile,
           "short-enums!" =>  \$cfgShortEnums,
           "big-endian!" =>  \$cfgBigEndian,
           "smattr-output-file:s" => \$CfgSMAttrFile,
           "include-fsp-attributes!" =>  \$cfgIncludeFspAttributes,
           "version-page!" => \$cfgAddVersionPage,
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
    print STDOUT "version-page = $cfgAddVersionPage\n",
}

################################################################################
# Initialize some globals
################################################################################

use constant INVALID_HUID=>0xffffffff;
use constant PEER_HUID_NOT_PRESENT=>0xfffffffe;

# When computing associations between targets, always store the association list
# pointers in this exact order within each target object.  It also must be the
# case that the ASSOCIATION_TYPE enum in the target service header must declare
# the corresponding enum values in this order as well
use constant PARENT_BY_CONTAINMENT => "ParentByContainment";
use constant CHILD_BY_CONTAINMENT => "ChildByContainment";
use constant PARENT_BY_AFFINITY => "ParentByAffinity";
use constant CHILD_BY_AFFINITY => "ChildByAffinity";
my @associationTypes = ( PARENT_BY_CONTAINMENT,
    CHILD_BY_CONTAINMENT, PARENT_BY_AFFINITY, CHILD_BY_AFFINITY );

# Constants for attribute names (minus ATTR_ prefix)
use constant ATTR_PHYS_PATH => "PHYS_PATH";
use constant ATTR_AFFINITY_PATH => "AFFINITY_PATH";
use constant ATTR_UNKNOWN => "UnknownAttributeName";

# Data manipulation constants
use constant BITS_PER_BYTE => 8;
use constant LOW_BYTE_MASK => 0xFF;
use constant BYTE_RIGHT_BIT_INDEX => BITS_PER_BYTE - 1;
use constant BYTES_PER_ABSTRACT_POINTER => 8;

# This is the maximum total sum of (compute nodes + control nodes) possible for
# any known system using this attribute compiler.  It is used to reserve
# space in each system target's CHILD + CHILD_BY_AFFINITY association lists
# so that FSP can link a system target to multiple nodes
use constant MAX_COMPUTE_AND_CONTROL_NODE_SUM => 5;

my $xml = new XML::Simple (KeyAttr=>[]);
use Digest::MD5 qw(md5_hex);

# Until full machine parseable workbook parsing splits out all the input files,
# use the intermediate representation containing the full host boot model.
# Aborts application if file name not found.
my $attributes = $xml->XMLin($cfgHbXmlFile,
    forcearray => ['enumerationType','attribute','hwpfToHbAttrMap',
                   'compileAttribute']);
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
if($cfgIncludeFspAttributes)
{
    handleTgtPtrAttributesFsp(\$attributes, \%Target_t);
}
else
{
    handleTgtPtrAttributesHb(\$attributes, \%Target_t);
}

# Open the output files and write them
if( !($cfgSrcOutputDir =~ "none") )
{

    open(ATTR_TARG_MAP_FILE,">$cfgSrcOutputDir"."targAttrOverrideData.H")
      or fatal("Target Attribute data file: \"$cfgSrcOutputDir"
        . "getTargAttrData.C\" could not be opened.");
    my $targAttrFile = *ATTR_TARG_MAP_FILE;
    writeTargAttrMap($attributes, $targAttrFile);
    close $targAttrFile;


    open(TRAIT_FILE,">$cfgSrcOutputDir"."attributetraits.H")
      or fatal ("Trait file: \"$cfgSrcOutputDir"
        . "attributetraits.H\" could not be opened.");
    my $traitFile = *TRAIT_FILE;
    writeTraitFileHeader($attributes,$traitFile);
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
    writeTestEntityPath($attributes);
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

    open(ATTR_ATTRERRL_C_FILE,">$cfgSrcOutputDir"."errludattribute.C")
      or fatal ("Attribute errlog C file: \"$cfgSrcOutputDir"
        . "errludattribute.C\" could not be opened.");
    my $attrErrlCFile = *ATTR_ATTRERRL_C_FILE;
    writeAttrErrlCFile($attributes,$attrErrlCFile);
    close $attrErrlCFile;

    mkdir("$cfgSrcOutputDir/errl");
    open(ATTR_ATTRERRL_H_FILE,">$cfgSrcOutputDir"."errl/errludattribute.H")
      or fatal ("Attribute errlog H file: \"$cfgSrcOutputDir"
        . "errl/errludattribute.H\" could not be opened.");
    my $attrErrlHFile = *ATTR_ATTRERRL_H_FILE;
    writeAttrErrlHFile($attributes,$attrErrlHFile);
    close $attrErrlHFile;

    open(ATTR_TARGETERRL_C_FILE,">$cfgSrcOutputDir"."errludtarget.C")
      or fatal ("Target errlog C file: \"$cfgSrcOutputDir"
        . "errludtarget.C\" could not be opened.");
    my $targetErrlCFile = *ATTR_TARGETERRL_C_FILE;
    writeTargetErrlCFile($attributes,$targetErrlCFile);
    close $targetErrlCFile;

    open(ATTR_TARGETERRL_H_FILE,">$cfgSrcOutputDir"."errl/errludtarget.H")
      or fatal ("Target errlog H file: \"$cfgSrcOutputDir"
        . "errl/errludtarget.H\" could not be opened.");
    my $targetErrlHFile = *ATTR_TARGETERRL_H_FILE;
    writeTargetErrlHFile($attributes,$targetErrlHFile);
    close $targetErrlHFile;

    open(ATTR_INFO_CSV_FILE,">$cfgSrcOutputDir"."targAttrInfo.csv")
      or fatal ("Attribute info csv file: \"$cfgSrcOutputDir"
        . "targAttrInfo.csv\" could not be opened.");
    my $attrInfoCsvFile = *ATTR_INFO_CSV_FILE;
    writeAttrInfoCsvFile($attributes,$attrInfoCsvFile);
    close $attrInfoCsvFile;

    open(MAP_ATTR_METADATA_H_FILE,">$cfgSrcOutputDir"."mapattrmetadata.H")
      or fatal ("Attribute metadata map file Header: \"$cfgSrcOutputDir"
        . "mapattrmetadata.H\" could not be opened.");
    my $attrMetadataMapHFile = *MAP_ATTR_METADATA_H_FILE;
    writeAttrMetadataMapHFile($attrMetadataMapHFile);
    close $attrMetadataMapHFile;

    open(MAP_ATTR_METADATA_C_FILE,">$cfgSrcOutputDir"."mapattrmetadata.C")
      or fatal ("Attribute metadata map C file: \"$cfgSrcOutputDir"
        . "mapattrmetadata.C\" could not be opened.");
    my $attrMetadataMapCFile = *MAP_ATTR_METADATA_C_FILE;
    writeAttrMetadataMapCFileHeader($attrMetadataMapCFile);
    writeAttrMetadataMapCFile($attributes,$attrMetadataMapCFile);
    writeAttrMetadataMapCFileFooter($attrMetadataMapCFile);
    close $attrMetadataMapCFile;

    open(MAP_ATTR_SIZE_H_FILE,">$cfgSrcOutputDir"."mapsystemattrsize.H")
      or fatal ("Attribute size map file Header: \"$cfgSrcOutputDir"
        . "mapsystemattrsize.H\" could not be opened.");
    my $attrSizeMapHFile = *MAP_ATTR_SIZE_H_FILE;
    writeAttrSizeMapHFile($attrSizeMapHFile);
    close $attrSizeMapHFile;

    open(MAP_ATTR_SIZE_C_FILE,">$cfgSrcOutputDir"."mapsystemattrsize.C")
      or fatal ("Attribute size map file: \"$cfgSrcOutputDir"
        . "mapsystemattrsize.C\" could not be opened.");
    my $attrSizeMapCFile = *MAP_ATTR_SIZE_C_FILE;
    writeAttrSizeMapCFileHeader($attrSizeMapCFile);
    writeAttrSizeMapCFile($attributes,$attrSizeMapCFile);
    writeAttrSizeMapCFileFooter($attrSizeMapCFile);
    close $attrSizeMapCFile;
}

use constant ATTRID => 0;
use constant HUID   => 1;
use constant DATA   => 2;
use constant SECTION => 3;
use constant TARGET => 4;
use constant ATTRNAME => 5;
my @attrDataforSM = ();

#Flag which indicates if the script needs to add the 4096 bytes of version
#checksum as first page in the binary file generated.
my $addRO_Section_VerPage = 0;
if( !($cfgImgOutputDir =~ "none") )
{
    #Version page will be added only if the script is called in with the flag
    #--version-flag
    if ($cfgAddVersionPage)
    {
        $addRO_Section_VerPage = 1;
    }
    #Pass the $addRO_Section_VerPage into the sub rotuine
    my $Data = generateTargetingImage($cfgVmmConstsFile,$attributes,\%Target_t,
                                      $addRO_Section_VerPage);

    open(PNOR_TARGETING_FILE,">$cfgImgOutputDir".$cfgImgOutputFile)
      or fatal ("Targeting image file: \"$cfgImgOutputDir"
        . "$cfgImgOutputFile\" could not be opened.");
    binmode(PNOR_TARGETING_FILE);
    print PNOR_TARGETING_FILE "$Data";
    close(PNOR_TARGETING_FILE);
    if ($CfgSMAttrFile ne "")
    {
        generateXMLforSM();
    }

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
        print "name=$name, mustBeHash=$mustBeHash, element=$element, criteria=$criteria \n";
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
    $elements{"hbOnly"}      = { required => 0, isscalar => 0};
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
    $elements{"id"}               = { required => 1, isscalar => 1};
    $elements{"parent"}           = { required => 0, isscalar => 1};
    $elements{"attribute"}        = { required => 0, isscalar => 0};
    $elements{"fspOnly"}          = { required => 0, isscalar => 0};
    $elements{"compileAttribute"} = { required => 0, isscalar => 0};

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
    $elements{"id"}               = { required => 1, isscalar => 1};
    $elements{"type"}             = { required => 1, isscalar => 1};
    $elements{"attribute"}        = { required => 0, isscalar => 0};
    $elements{"compileAttribute"} = { required => 0, isscalar => 0};

    foreach my $targetInstance (@{$attributes->{targetInstance}})
    {
        validateSubElements("targetInstance",1,$targetInstance,\%elements);
    }
}

################################################################################
# Convert Target_t PHYS_PATH into Peer target's HUID - FSP Specific
################################################################################

sub handleTgtPtrAttributesFsp
{
    my($attributes) = @_;

    # replace PEER_TARGET attribute<PHYS_PATH> value with PEER's HUID
    foreach my $targetInstance (@{${$attributes}->{targetInstance}})
    {
        foreach my $attr (@{$targetInstance->{attribute}})
        {
            if (exists $attr->{default})
            {
                if(   ($attr->{default} ne "NULL")
                   && ($attr->{id} eq "PEER_TARGET") )
                {
                    my $peerHUID = INVALID_HUID;
                    $peerHUID = getPeerHuid($targetInstance);
                    if($peerHUID == INVALID_HUID)
                    {
                        fatal("HUID for Peer Target not found for "
                            . "Peer Target [$attr->{default}]\n");
                    }
                    elsif($peerHUID == PEER_HUID_NOT_PRESENT)
                    {
                        # Might require this for debug, so keeping it.
                        #print STDOUT "****PEER HUID Attribut not present for "
                        #    . "Peer Target [$attr->{default}]... Skip\n";
                        $attr->{default} = "NULL";
                    }
                    else
                    {
                        $attr->{default} =
                            sprintf("0x%X",(hex($peerHUID) << 32));
                    }
                }
            }
        }
    }
}

################################################################################
# Convert PHYS_PATH into index for Target_t attribute's value
################################################################################

sub handleTgtPtrAttributesHb{
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
                    print STDOUT ("$attr->{id} attribute has an unknown value "
                        . "$attr->{default}\n"
                        . "It must be NULL or a valid PHYS_PATH\n");
                    $attr->{default} = "NULL";
                }
            }
        }
    }
}

sub getPeerHuid
{
    my($targetInstance) = @_;

    my $peerHUID = PEER_HUID_NOT_PRESENT;
    if(exists $targetInstance->{compileAttribute})
    {
        foreach my $compileAttribute (@{$targetInstance->{compileAttribute}})
        {
            if($compileAttribute->{id} eq "PEER_HUID")
            {
                $peerHUID = $compileAttribute->{default};
                last;
            }
        }
    }

    return $peerHUID;
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

                            if ( (exists $fapiAttr->{persistent}))
                            {
                                if ($attribute->{persistency} ne "non-volatile")
                                {
                                    fatal("FAPI non-platInit attr " .
                                          "'$hwpfToHbAttrMap->{id}' is " .
                                          "'$attribute->{persistency}', " .
                                          "it must be non-volatile");
                                }
                            }
                            else
                            {
                                # Check that platInit attributes
                                # have a non-volatile persistency
                                if($attribute->{persistency} ne
                                   "volatile-zeroed")
                                {
                                     fatal("FAPI non-platInit attr " .
                                      "'$hwpfToHbAttrMap->{id}' is " .
                                      "'$attribute->{persistency}', " .
                                      "it must be volatile-zeroed");
                                }
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

        // Initialized to zero on Fsp Reset / Obliterate on Fsp Reset or R/R
        SECTION_TYPE_FSP_P0_ZERO_INIT = 0x4,

        // Initialized from Flash / Obliterate on Fsp Reset or R/R
        SECTION_TYPE_FSP_P0_FLASH_INIT = 0x5,

        // This section remains across fsp power cycle, fixed, never updates
        SECTION_TYPE_FSP_P3_RO = 0x6,

        // This section persist changes across Fsp Power cycle
        SECTION_TYPE_FSP_P3_RW = 0x7,

        // Initialized to zero on hard reset, else existing P1 memory
        // copied on R/R
        SECTION_TYPE_FSP_P1_ZERO_INIT = 0x8,

        // Intialized to default from P3 on hard reset, else existing P1
        // memory copied on R/R
        SECTION_TYPE_FSP_P1_FLASH_INIT = 0x9,

        // HOSTBOOT section

        // Targeting heap section intialized to zero
        SECTION_TYPE_HB_HEAP_ZERO_INIT = 0x0A,

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
# Writes test for toString entity path function
################################################################################

sub writeTestEntityPath {
    my($attributes) = @_;

    open EP_TEST_FILE, ">", "$cfgSrcOutputDir"."test_ep.H" or die $!;

    print EP_TEST_FILE "#include <attributeenums.H>\n";
    print EP_TEST_FILE "using namespace TARGETING;\n";
    print EP_TEST_FILE "EntityPath l_path;\n";
    print EP_TEST_FILE "const char * name = NULL;\n";
    print(EP_TEST_FILE "const char * test_string = \"Unknown path" .
                       " type\";\n");
    print EP_TEST_FILE "size_t size = strlen( test_string );\n";

    foreach my $attribute (@{$attributes->{attribute}})
    {
        if(exists $attribute->{simpleType})
        {
            my $simpleType = $attribute->{simpleType};
            if(exists $simpleType->{enumeration})
            {
                my $enumeration = $simpleType->{enumeration};

                my $enumerationType = getEnumerationType($attributes,
                    $enumeration->{id});

                foreach my $enumerator (@{$enumerationType->{enumerator}})
                {
                    if( $attribute->{id} eq "TYPE" )
                    {
                        print(EP_TEST_FILE "name = " .
                            "l_path.pathElementTypeAsString( " .
                            "TYPE_$enumerator->{name} );\n");
                        print EP_TEST_FILE "size = strlen( name );\n";

                        if( $enumerator->{name} eq "LAST_IN_RANGE" )
                        {
                            print(EP_TEST_FILE "if( memcmp( name, " .
                                "test_string, size ))\n{\n");

                            print(EP_TEST_FILE "TS_FAIL(\"type " .
                                "attribute TYPE_$enumerator->{name}" .
                                " - did not return expected error " .
                                "message. - update entitypath.C\");\n}\n");

                        }
                        elsif( $enumerator->{name} eq "TEST_FAIL" )
                        {
                            #TEST_FAIL is not defined in the function
                            #pathElementTypeAsString - validate error string
                            print(EP_TEST_FILE "if( memcmp( name, " .
                                "test_string, size ))\n{\n");

                            print(EP_TEST_FILE "TS_FAIL(\"type " .
                                "attribute TYPE_$enumerator->{name}" .
                                " - did not return expected error " .
                                "message. - update entitypath.C\");\n}\n");
                        }
                        else
                        {
                            print(EP_TEST_FILE "if( !memcmp( name, " .
                                "test_string, size ))\n{\n");

                            print(EP_TEST_FILE "TS_FAIL(\"undefined TYPE " .
                                "attribute TYPE_$enumerator->{name}" .
                                " - update entitypath.C\");\n}\n");
                        }
                    }
                }
            }
        }
    }
close EP_TEST_FILE;
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
        $hexVal = $enumerator->{value};
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

###############################################################################
# Writes code to populate Attribute Data Map
###############################################################################
sub writeTargAttrMap {
    my($attributes,$outFile) = @_;


    my $attributeIdEnum = getAttributeIdEnumeration($attributes);

    print $outFile "const AttributeData g_TargAttrs[] = {\n";

    # loop through every attribute
    foreach my $attribute
        (sort { $a->{id} cmp $b->{id} } @{$attributes->{attribute}})
    {


        # Only (initially) support attributes with simple integer types
        if ((exists $attribute->{simpleType}) &&
            ((exists $attribute->{simpleType}->{uint8_t}) ||
             (exists $attribute->{simpleType}->{uint16_t}) ||
             (exists $attribute->{simpleType}->{uint32_t}) ||
             (exists $attribute->{simpleType}->{uint64_t})))
        {


            foreach my $enum (@{$attributeIdEnum->{enumerator}})
            {
                if($enum->{name} eq $attribute->{id})
                {
                        # struct AttributeData
                    print $outFile "\t{\n";
                        # iv_name
                    print $outFile "\t\t\"ATTR_$attribute->{id}\",\n";
                        # iv_attrId
                    print $outFile "\t\t$enum->{value},\n";
                        # iv_attrElemSizeBytes
                    my @sizes = ( "uint8_t", "uint16_t",
                                  "uint32_t", "uint64_t" );

                    foreach my $size (@sizes)
                    {
                        if (exists $attribute->{simpleType}->{$size})
                        {
                            print $outFile "\t\tsizeof($size),\n";
                            last;
                        }
                    }

                        # iv_dims
                    my @dims = ();
                    if (exists $attribute->{simpleType}->{array})
                    {
                        # Remove leading whitespace
                        my $dimText = $attribute->{simpleType}->{array};
                        $dimText =~ s/^\s+//;

                        # Split on commas or whitespace
                        @dims = split(/\s*,\s*|\s+/, $dimText);
                    }
                    until ($#dims == 3)
                    {
                        push @dims, 1;
                    }
                    print $outFile "\t\t{ ".join(", ",@dims)." } \n";

                        # end AttributeData
                    print $outFile "\t},\n";

                }


            }

        }


    }

    print $outFile "};\n";
}

################################################################################
# Writes the trait file header
################################################################################

sub writeTraitFileHeader {
    my($attributes,$outFile) = @_;

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
VERBATIM

foreach my $attribute (@{$attributes->{attribute}})
{
    #check if fspmutex is present?
    if(   (exists $attribute->{simpleType})
            && (exists $attribute->{simpleType}->{fspmutex}) )
    {
        print $outFile "#include <utilmutex.H>\n";
        last; # don't need to look at any others.
    }
}

print $outFile <<VERBATIM;
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

    my %attrValHash;

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

        # Mark the attribute as being a fsp mutex or non-fsp mutex
        if(   (exists $attribute->{simpleType})
            && (exists $attribute->{simpleType}->{fspmutex}) )
        {
            $traits .= " fspMutex,";
        }
        else
        {
            $traits .= " notFspMutex,";
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

        # if it already exists skip it
        if( !exists($attrValHash{$attribute->{id}}))
        {
            # keep track of the ones we add to our file
            $attrValHash{$attribute->{id}} = 1;

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
                my $size = $attribute->{simpleType}->{string}->{sizeInclNull}-1;
                $typedefs .= "const size_t ATTR_"
                .  "$attribute->{id}" . "_max_chars = "
                .  "$size"
                . ";\n";
            }
            $typedefs .= "\n";
        }
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
    print $outFile "#include <errl/errludattribute.H>\n";
    print $outFile "#include <errl/errlreasoncodes.H>\n";
    print $outFile "#include <targeting/common/targetservice.H>\n";
    print $outFile "#include <targeting/common/trace.H>\n";
    print $outFile "\n";
    print $outFile "namespace ERRORLOG\n";
    print $outFile "{\n";
    print $outFile "using namespace TARGETING;\n";
    print $outFile "extern TARG_TD_t g_trac_errl;\n";

    # build function that takes adds 1 attribute to the output
    print $outFile "\n";
    print $outFile "void ErrlUserDetailsAttribute::addData(\n";
    print $outFile "    uint32_t i_attr)\n";
    print $outFile "{\n";
    print $outFile "    char *tmpBuffer = NULL;\n";
    print $outFile "    uint32_t attrSize = 0;\n";
    print $outFile "\n";
    print $outFile "    switch (i_attr) {\n";

    # loop through every attribute to make the swith/case
    foreach my $attribute (@{$attributes->{attribute}})
    {
        # things we'll skip:
        if(!(exists $attribute->{readable}) ||  # write-only attributes
           !(exists $attribute->{writeable}) || # read-only attributes
           (exists $attribute->{simpleType} && (
           (exists $attribute->{simpleType}->{hbmutex}) ||
           (exists $attribute->{simpleType}->{fspmutex}))) # mutex attributes
          ) {
            print $outFile "        case (ATTR_",$attribute->{id},"): { break; }\n";
            next;
        }
        # any complicated types just get dumped as raw hex binary
        elsif(exists $attribute->{complexType}) {
            print $outFile "        case (ATTR_",$attribute->{id},"): {\n";
            print $outFile "            TRACDCOMP( g_trac_errl, \"ErrlUserDetailsAttribute: ",$attribute->{id}," skipped -- complexType\");\n";
            print $outFile "            attrSize = 0;\n";
            print $outFile "            break;\n";
            print $outFile "        }\n";
        }
        # Enums
        elsif(exists $attribute->{simpleType} && (exists $attribute->{simpleType}->{enumeration}) ) {
            print $outFile "        case (ATTR_",$attribute->{id},"): { // simpleType:enum\n";
            print $outFile "            //TRACDCOMP( g_trac_errl, \"ErrlUserDetailsAttribute: ",$attribute->{id}," entry\");\n";
            print $outFile "            AttributeTraits<ATTR_",$attribute->{id},">::Type tmp;\n";
            print $outFile "            if( iv_pTarget->tryGetAttr<ATTR_",$attribute->{id},">(tmp) ) {\n";
            print $outFile "                tmpBuffer = new char[sizeof(tmp)];\n";
            print $outFile "                memcpy(tmpBuffer, &tmp, sizeof(tmp));\n";
            print $outFile "                attrSize = sizeof(tmp);\n";
            print $outFile "            }\n";
            print $outFile "            break;\n";
            print $outFile "        }\n";
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
            print $outFile "        case (ATTR_",$attribute->{id},"): { //simpleType:uint, :int...\n";
            print $outFile "            //TRACDCOMP( g_trac_errl, \"ErrlUserDetailsAttribute: ",$attribute->{id}," entry\");\n";
            print $outFile "            AttributeTraits<ATTR_",$attribute->{id},">::Type tmp;\n";
            print $outFile "            if( iv_pTarget->tryGetAttr<ATTR_",$attribute->{id},">(tmp) ) {\n";
            print $outFile "                tmpBuffer = new char[sizeof(tmp)];\n";
            print $outFile "                memcpy(tmpBuffer, &tmp, sizeof(tmp));\n";
            print $outFile "                attrSize = sizeof(tmp);\n";
            print $outFile "            }\n";
            print $outFile "            break;\n";
            print $outFile "        }\n";
        }
        # dump the enums for EntityPaths
        elsif(exists $attribute->{nativeType} && ($attribute->{nativeType}->{name} eq "EntityPath")) {
            print $outFile "        case (ATTR_",$attribute->{id},"): { //nativeType:EntityPath\n";
            print $outFile "            //TRACDCOMP( g_trac_errl, \"ErrlUserDetailsAttribute: ",$attribute->{id}," entry\");\n";
            print $outFile "            AttributeTraits<ATTR_",$attribute->{id},">::Type tmp;\n";
            print $outFile "            if( iv_pTarget->tryGetAttr<ATTR_",$attribute->{id},">(tmp) ) {\n";
            print $outFile "                // data is PATH_TYPE, Number of elements, [ Element, Instance# ]\n";
            print $outFile "                EntityPath::PATH_TYPE lPtype = tmp.type();\n";
            print $outFile "                uint8_t lSize = tmp.size();\n";
            print $outFile "                tmpBuffer = new char[sizeof(lPtype) + lSize + lSize * sizeof(EntityPath::PathElement)];\n";
            print $outFile "                memcpy(tmpBuffer + attrSize,&lPtype,sizeof(lPtype));\n";
            print $outFile "                attrSize += sizeof(lPtype);\n";
            print $outFile "                memcpy(tmpBuffer + attrSize,&lSize,sizeof(lSize));\n";
            print $outFile "                attrSize += sizeof(lSize);\n";
            print $outFile "                for (uint32_t i=0;i<lSize;i++) {\n";
            print $outFile "                    EntityPath::PathElement lType = tmp[i];\n";
            print $outFile "                    memcpy(tmpBuffer + attrSize,&tmp[i],sizeof(tmp[i]));\n";
            print $outFile "                    attrSize += sizeof(tmp[i]);\n";
            print $outFile "                }\n";
            print $outFile "            }\n";
            print $outFile "            break;\n";
            print $outFile "        }\n";
            print $outFile "}\n";
        }
        # any other nativeTypes are just decimals...  (I never saw one)
        elsif(exists $attribute->{nativeType}) {
            print $outFile "        case (ATTR_",$attribute->{id},"): { nativeType\n";
            print $outFile "            //TRACDCOMP( g_trac_errl, \"ErrlUserDetailsAttribute: ",$attribute->{id}," entry\");\n";
            print $outFile "            AttributeTraits<ATTR_",$attribute->{id},">::Type tmp;\n";
            print $outFile "            if( iv_pTarget->tryGetAttr<ATTR_",$attribute->{id},">(tmp) ) {\n";
            print $outFile "                tmpBuffer = new char[sizeof(tmp)];\n";
            print $outFile "                memcpy(tmpBuffer, &tmp, sizeof(tmp));\n";
            print $outFile "                attrSize = sizeof(tmp);\n";
            print $outFile "            }\n";
            print $outFile "            break;\n";
            print $outFile "        }\n";
        }
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
    print $outFile "    delete [] tmpBuffer;\n";
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
    print $outFile "    iv_CompId = ERRL_COMP_ID;\n";
    print $outFile "    iv_Version = 1;\n";
    print $outFile "    iv_SubSection = ERRL_UDT_ATTRIBUTE;\n";
    print $outFile "    // override the default of false\n";
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
    print $outFile "    iv_CompId = ERRL_COMP_ID;\n";
    print $outFile "    iv_Version = 1;\n";
    print $outFile "    iv_SubSection = ERRL_UDT_ATTRIBUTE;\n";
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
           (exists $attribute->{simpleType} && (
           (exists $attribute->{simpleType}->{hbmutex}) ||
           (exists $attribute->{simpleType}->{fspmutex}))) # mutex attributes
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
    print $outFile "#ifndef PARSER\n";
    print $outFile "\n";
    print $outFile "#include <errl/errluserdetails.H>\n";
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
    print $outFile "#include \"errluserdetails.H\"\n";
    print $outFile "\n";
    print $outFile "namespace ERRORLOG\n";
    print $outFile "{\n";
    print $outFile "class ErrlUserDetailsParserAttribute : public ErrlUserDetailsParser {\n";
    print $outFile "public:\n";
    print $outFile "\n";
    print $outFile "    ErrlUserDetailsParserAttribute() {}\n";
    print $outFile "\n";
    print $outFile "    virtual ~ErrlUserDetailsParserAttribute() {}\n";
    print $outFile "  /**\n";
    print $outFile "   *  \@brief Parses Attribute user detail data from an error log\n";
    print $outFile "   *  \@param  i_version Version of the data\n";
    print $outFile "   *  \@param  i_parse   ErrlUsrParser object for outputting information\n";
    print $outFile "   *  \@param  i_pBuffer Pointer to buffer containing detail data\n";
    print $outFile "   *  \@param  i_buflen  Length of the buffer\n";
    print $outFile "   */\n";
    print $outFile "  virtual void parse(errlver_t i_version,\n";
    print $outFile "                        ErrlUsrParser & i_parser,\n";
    print $outFile "                        void * i_pBuffer,\n";
    print $outFile "                        const uint32_t i_buflen) const\n";
    print $outFile "  {\n";
    print $outFile "    const char *pLabel = NULL;\n";
    print $outFile "    uint8_t *l_ptr = static_cast<uint8_t *>(i_pBuffer);\n";
    print $outFile "    std::vector<char> l_traceEntry(64);\n";
    print $outFile "    i_parser.PrintString(\"Target Attributes\", NULL);\n";
    print $outFile "\n";

    print $outFile "    for (; (l_ptr + sizeof(uint32_t)) <= ((uint8_t*)i_pBuffer + i_buflen); )\n";
    print $outFile "    {\n";
    print $outFile "        // first 4 bytes is the attr enum\n";
    print $outFile "        uint32_t attrEnum = ntohl(*(uint32_t *)l_ptr);\n";
    print $outFile "        l_ptr += sizeof(attrEnum);\n";
    print $outFile "\n";
    print $outFile "        switch (attrEnum) {\n";

    my $attributeIdEnum = getAttributeIdEnumeration($attributes);

    # loop through every attribute to make the swith/case
    foreach my $attribute (@{$attributes->{attribute}})
    {
        my $attrVal;
        foreach my $enum (@{$attributeIdEnum->{enumerator}})
        {
            if ($enum->{name} eq $attribute->{id})
            {
                $attrVal = $enum->{value};
                last; # don't need to look at any others.
            }
        }
        print $outFile "          case ",$attrVal,": {\n";

        # things we'll skip:
        if(!(exists $attribute->{readable}) ||  # write-only attributes
           !(exists $attribute->{writeable}) || # read-only attributes
           (exists $attribute->{simpleType} && (
           (exists $attribute->{simpleType}->{hbmutex}) ||
           (exists $attribute->{simpleType}->{fspmutex}))) # mutex attributes
          ) {
            print $outFile "              //not readable\n";
        }
        # Enums have strings defined already, use them
        elsif(exists $attribute->{simpleType} && (exists $attribute->{simpleType}->{enumeration}) ) {
            print $outFile "              //simpleType:enum\n";
            print $outFile "              pLabel = \"",$attribute->{id},"\";\n";
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
                    print $outFile "                      sprintf(&(l_traceEntry[0]), \"",$enumName,"\");\n";
                    print $outFile "                      l_ptr += sizeof(uint32_t);\n";
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
        # makes no sense to dump fsp mutex attributes, so skipping
        elsif(   (exists $attribute->{simpleType})
              && (exists $attribute->{simpleType}->{fspmutex}) )
        {
            print $outFile "            //Mutex attributes - skipping\n";
        }
        # any complicated types just get dumped as raw hex binary
        elsif(exists $attribute->{complexType}) {
            #print $outFile "         //complexType\n";
            #print $outFile "         uint32_t<ATTR_",$attribute->{id},">::Type tmp;\n";
            #print $outFile "         if( i_pTarget->tryGetAttr<ATTR_",$attribute->{id},">(tmp) ) {\n";
            #print $outFile "           sprintf(i_buffer, \" \", &tmp, sizeof(tmp));\n";
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
            print $outFile "              pLabel = \"",$attribute->{id},"\";\n";
            my @bounds;
            if(exists $attribute->{simpleType}->{array})
            {
                    @bounds = split(/,/,$attribute->{simpleType}->{array});
            }
            else
            {
                $bounds[0] = 1;
            }
            my $total_count = 1;
            foreach my $bound (@bounds)
            {
                $total_count *= $bound;
            }
            my $size = scalar(@bounds);
            if (($size == 1) && ( $bounds[0] > 1))
            {
                print $outFile "              uint32_t offset = sprintf(&(l_traceEntry[0]), \"[$bounds[0]]:\");\n";
            }
            elsif ($size == 2)
            {
                print $outFile "              uint32_t offset = sprintf(&(l_traceEntry[0]), \"[$bounds[0]][$bounds[1]]:\");\n";
            }
            elsif ($size == 3)
            {
                print $outFile "              uint32_t offset = sprintf(&(l_traceEntry[0]), \"[$bounds[0]][$bounds[1]][$bounds[2]]:\");\n";
            }
            else
            {
                print $outFile "              uint32_t offset = 0;\n";
            }
            if (exists $attribute->{simpleType}->{uint8_t})
            {
                print $outFile "              l_traceEntry.resize(10+offset + $total_count * 5);\n";
                print $outFile "              for (uint32_t i = 0;i<$total_count;i++) {\n";
                print $outFile "                  sprintf(&(l_traceEntry[offset+i*5]), \"0x%.2X \", *((uint8_t *)l_ptr)+i);\n";
                print $outFile "              }\n";
                print $outFile "              l_ptr += $total_count * sizeof(uint8_t);\n";
            }
            elsif (exists $attribute->{simpleType}->{uint16_t}) {
                print $outFile "              l_traceEntry.resize(10+offset + $total_count * 7);\n";
                print $outFile "              for (uint32_t i = 0;i<$total_count;i++) {\n";
                print $outFile "                  sprintf(&(l_traceEntry[offset+i*7]), \"0x%.4X \", ntohs(*((uint16_t *)l_ptr)+i));\n";
                print $outFile "              }\n";
                print $outFile "              l_ptr += $total_count * sizeof(uint16_t);\n";
            }
            elsif (exists $attribute->{simpleType}->{uint32_t}) {
                print $outFile "              l_traceEntry.resize(10+offset + $total_count * 11);\n";
                print $outFile "              for (uint32_t i = 0;i<$total_count;i++) {\n";
                print $outFile "                  sprintf(&(l_traceEntry[offset+i*11]), \"0x%.8X \", ntohl(*((uint32_t *)l_ptr)+i));\n";
                print $outFile "              }\n";
                print $outFile "              l_ptr += $total_count * sizeof(uint32_t);\n";
            }
            elsif (exists $attribute->{simpleType}->{uint64_t}) {
                print $outFile "              l_traceEntry.resize(10+offset + $total_count * 19);\n";
                print $outFile "              for (uint32_t i = 0;i<$total_count;i++) {\n";
                print $outFile "                  sprintf(&(l_traceEntry[offset+i*19]), \"0x%.16llX \", ntohll(*((uint64_t *)l_ptr)+i));\n";
                print $outFile "              }\n";
                print $outFile "              l_ptr += $total_count * sizeof(uint64_t);\n";
            }
            elsif (exists $attribute->{simpleType}->{int8_t}) {
                print $outFile "              l_traceEntry.resize(10+offset + $total_count * 5);\n";
                print $outFile "              for (uint32_t i = 0;i<$total_count;i++) {\n";
                print $outFile "                  sprintf(&(l_traceEntry[offset+i*5]), \"0x%.2X \", *((uint8_t *)l_ptr)+i);\n";
                print $outFile "              }\n";
                print $outFile "              l_ptr += $total_count * sizeof(uint8_t);\n";
            }
            elsif (exists $attribute->{simpleType}->{int16_t}) {
                print $outFile "              l_traceEntry.resize(10+offset + $total_count * 7);\n";
                print $outFile "              for (uint32_t i = 0;i<$total_count;i++) {\n";
                print $outFile "                  sprintf(&(l_traceEntry[offset+i*7]), \"0x%.4X \", ntohs(*((int16_t *)l_ptr)+i));\n";
                print $outFile "              }\n";
                print $outFile "              l_ptr += $total_count * sizeof(int16_t);\n";
            }
            elsif (exists $attribute->{simpleType}->{int32_t}) {
                print $outFile "              l_traceEntry.resize(10+offset + $total_count * 11);\n";
                print $outFile "              for (uint32_t i = 0;i<$total_count;i++) {\n";
                print $outFile "                  sprintf(&(l_traceEntry[offset+i*11]), \"0x%.8X \", ntohl(*((int32_t *)l_ptr)+i));\n";
                print $outFile "              }\n";
                print $outFile "              l_ptr += $total_count * sizeof(int32_t);\n";
            }
            elsif (exists $attribute->{simpleType}->{int64_t}) {
                print $outFile "              l_traceEntry.resize(10+offset + $total_count * 19);\n";
                print $outFile "              for (uint32_t i = 0;i<$total_count;i++) {\n";
                print $outFile "                  sprintf(&(l_traceEntry[offset+i*19]), \"0x%.16llX \", ntohll(*((int64_t *)l_ptr)+i));\n";
                print $outFile "              }\n";
                print $outFile "              l_ptr += $total_count * sizeof(int64_t);\n";
            }
        }
        # EntityPaths
        elsif(exists $attribute->{nativeType} && ($attribute->{nativeType}->{name} eq "EntityPath")) {
            print $outFile "              //nativeType:EntityPath\n";
            print $outFile "              pLabel = \"",$attribute->{id},"\";\n";
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
            print $outFile "              l_traceEntry.resize(strlen(pathString) + 128);\n";
            print $outFile "              uint32_t dataSize = sprintf(&(l_traceEntry[0]), \"%s\",pathString);\n";
            print $outFile "              const uint8_t lSize = *(l_ptr + 1); // number of elements\n";
            print $outFile "              uint8_t *lElementInstance = (l_ptr + 2);\n";
            print $outFile "              for (uint32_t i=0;i<lSize;i += 2) {\n";
            print $outFile "                  switch (lElementInstance[i]) {\n";
            foreach my $enumerationType (@{$attributes->{enumerationType}})
            {
                if( $enumerationType->{id} eq "TYPE" ) {
                    foreach my $enumerator (@{$enumerationType->{enumerator}})
                    {
                        my $enumHex = sprintf "0x%02X",
                            enumNameToValue($enumerationType,$enumerator->{name});
                        my $enumName = $enumerator->{name};
                        if ($enumName eq "SYS") {
                            $enumName = "Sys";
                        } elsif ($enumName eq "PROC") {
                            $enumName = "Proc";
                        } elsif ($enumName eq "NODE") {
                            $enumName = "Node";
                        } elsif ($enumName eq "CORE") {
                            $enumName = "Core";
                        } elsif ($enumName eq "MEMBUF") {
                            $enumName = "Membuf";
                        }
                        print $outFile "                      case $enumHex: { pathString = \"/$enumName\"; break; }\n";
                    }
                }
            } # enumerationType
            print $outFile "                      default:   { pathString = \"/UNKNOWN\"; break; }\n";
            print $outFile "                  } // switch\n";
            print $outFile "                  // copy next part in, overwritting previous terminator\n";
            print $outFile "                  dataSize += sprintf(&(l_traceEntry[0]) + dataSize, \"%s%d\",pathString,lElementInstance[i+1]);\n";
            print $outFile "                  l_ptr += 2 * sizeof(uint8_t);\n";
            print $outFile "              } // for\n";
        }
        # any other nativeTypes are just decimals...  (I never saw one)
        elsif(exists $attribute->{nativeType}) {
            print $outFile "              //nativeType\n";
            print $outFile "              pLabel = \"",$attribute->{id},"\";\n";
            print $outFile "              sprintf(&(l_traceEntry[0]), \"%d\", *((int32_t *)l_ptr));\n";
            print $outFile "              l_ptr += sizeof(uint32_t);\n";
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
    print $outFile "        if (pLabel != NULL) {\n";
    print $outFile "            i_parser.PrintString(pLabel, &(l_traceEntry[0]));\n";
    print $outFile "        }\n";
    print $outFile "    } // for\n";
    print $outFile "  } // parse\n\n";
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

######
#Create a .csv file to parse attribute overrides/syncs
#####
sub writeAttrInfoCsvFile {
    my($attributes,$outFile) = @_;

    # Print the file header
    print $outFile "# targAttrInfo.cvs\n";
    print $outFile "# This file is generated by perl script xmltohb.pl\n";
    print $outFile "# It lists information about TARG attributes and is used to\n";
    print $outFile "# process FAPI Attribute text files (overrides/syncs)\n";
    print $outFile "# Format:\n";
    print $outFile "# <FAPI-ATTR-ID-STR>,<LAYER-ATTR-ID-STR>,<ATTR-ID-VAL>,<ATTR-TYPE>\n";

    my $attributeIdEnum = getAttributeIdEnumeration($attributes);

    # loop through every attribute
    foreach my $attribute (@{$attributes->{attribute}})
    {
        # Only (initially) support attributes with simple integer types
        if ((exists $attribute->{simpleType}) &&
            ((exists $attribute->{simpleType}->{uint8_t}) ||
             (exists $attribute->{simpleType}->{uint16_t}) ||
             (exists $attribute->{simpleType}->{uint32_t}) ||
             (exists $attribute->{simpleType}->{uint64_t})))
        {
            my $fapiId = "NO-FAPI-ID";

            if (exists $attribute->{hwpfToHbAttrMap}[0])
            {
                $fapiId = $attribute->{hwpfToHbAttrMap}[0]->{id};
            }

            foreach my $enum (@{$attributeIdEnum->{enumerator}})
            {
                if ($enum->{name} eq $attribute->{id})
                {
                    print $outFile "$fapiId,";
                    print $outFile "ATTR_$attribute->{id}";
                    print $outFile ",$enum->{value},";

                    if (exists $attribute->{simpleType}->{uint8_t})
                    {
                        print $outFile "u8";
                    }
                    elsif (exists $attribute->{simpleType}->{uint16_t})
                    {
                        print $outFile "u16";
                    }
                    elsif (exists $attribute->{simpleType}->{uint32_t})
                    {
                        print $outFile "u32";
                    }
                    elsif (exists $attribute->{simpleType}->{uint64_t})
                    {
                        print $outFile "u64";
                    }

                    if (exists $attribute->{simpleType}->{array})
                    {
                        # Remove leading whitespace
                        my $dimText = $attribute->{simpleType}->{array};
                        $dimText =~ s/^\s+//;

                        # Split on commas or whitespace
                        my @vals = split(/\s*,\s*|\s+/, $dimText);

                        foreach my $val (@vals)
                        {
                            print $outFile "[$val]";
                        }
                    }
                    print $outFile "\n";
                }
            }
        }
    }
} # sub writeAttrInfoCsvFile

################################################################################
# Writes the unordered/Ordered map of all target attribute  metadata
# C file header
################################################################################

sub writeAttrMetadataMapCFileHeader {
    my($outFile) = @_;

print $outFile <<VERBATIM;

/**
 *  \@file mapattrmetadata.C
 *
 *  \@brief Interface to get the unordered/ordered map of all target attributes
 *  with respective attribute size and read/write properties. This file is
 *  autogenerated and should not be altered.
 */

// TARG
#include <mapattrmetadata.H>

//******************************************************************************
// Macros
//******************************************************************************

#undef TARG_NAMESPACE
#undef TARG_CLASS
#undef TARG_FUNC

//******************************************************************************
// Implementation
//******************************************************************************

namespace TARGETING
{

#define TARG_NAMESPACE "TARGETING::"
#define TARG_CLASS "MapAttrMetadata::"

// Persistency defines
static const char * P0_PERSISTENCY = "p0";
static const char * P1_PERSISTENCY = "p1";
static const char * P3_PERSISTENCY = "p3";

//******************************************************************************
// TARGETING::mapAttrMetadata
//******************************************************************************

TARGETING::MapAttrMetadata& mapAttrMetadata()
{
    #define TARG_FN "mapAttrMetadata()"

    return TARG_GET_SINGLETON(TARGETING::theMapAttrMetadata);

    #undef TARG_FN
}

//******************************************************************************
// TARGETING::MapAttrMetadata::~MapAttrMetadata
//******************************************************************************

MapAttrMetadata::~MapAttrMetadata()
{
    #define TARG_FN "~MapAttrMetadata()"
    #undef TARG_FN
}

//******************************************************************************
// TARGETING::MapAttrMetadata::getMapMetadataForAllAttributes
//******************************************************************************

const AttrMetadataMapper&
MapAttrMetadata::getMapMetadataForAllAttributes() const
{
    #define TARG_FN "getMapMetadataForAllAttributes()"
    TARG_ENTER();

    TARG_EXIT();
    return iv_mapAttrMetadata;

    #undef TARG_FN
}

//******************************************************************************
// TARGETING::MapAttrMetadata::MapAttrMetadata
//******************************************************************************

MapAttrMetadata::MapAttrMetadata()
{
    #define TARG_FN "MapAttrMetadata()"
VERBATIM

}

################################################################################
# Create a .C file to put All Target Attributes along with there respective
# Size and read/write properties in a unordered/ordered map variable
################################################################################

sub writeAttrMetadataMapCFile{
    my($attributes,$outFile) = @_;
    my %finalAttrhash = ();

    # look for all attributes in the XML
    foreach my $attribute (@{$attributes->{attribute}})
    {
        $finalAttrhash{$attribute->{id}} = $attribute;
    }

    print $outFile "\n";
    print $outFile "    static const Pair_t l_pair[] = {\n";

    foreach my $key ( keys %finalAttrhash)
    {
        if(!(exists $finalAttrhash{$key}->{hbOnly}))
        {
            # Fetch the Size of the attribute
            my $keySize = "ATTR_"."$key"."_type";
            if(exists $finalAttrhash{$key}->{simpleType})
            {
                # Nothing to do
            }
            elsif(!(exists $finalAttrhash{$key}->{complexType}) &&
                  !(exists $finalAttrhash{$key}->{nativeType}))
            {
                print STDOUT "\t// ### Attribute $key is Not Supported\n";
                next;
            }
            print $outFile "        std::make_pair( ATTR_".$key.",";
            print $outFile " AttrMetadataStr(sizeof($keySize),";

            # Fetch Read/Writeable Property
            if(exists $finalAttrhash{$key}->{writeable})
            {
                print $outFile " true,";
            }
            else
            {
                print $outFile " false,";
            }

            if(!(exists $finalAttrhash{$key}->{persistency}))
            {
                fatal("Attribute[$key] should have persistency by default");
            }
            if($finalAttrhash{$key}->{persistency} eq "non-volatile")
            {
                print $outFile " P3_PERSISTENCY) ),\n";
            }
            elsif(($finalAttrhash{$key}->{persistency} eq
                    "semi-non-volatile-zeroed") ||
                  ($finalAttrhash{$key}->{persistency} eq "semi-non-volatile"))
            {
                print $outFile " P1_PERSISTENCY) ),\n";
            }
            elsif(($finalAttrhash{$key}->{persistency} eq "volatile") ||
                  ($finalAttrhash{$key}->{persistency} eq "volatile-zeroed"))
            {
                print $outFile " P0_PERSISTENCY) ),\n";
            }
            else
            {
                fatal("Not a defined" .
                    "Persistency[$finalAttrhash{$key}->{persistency}] for" .
                    "attribute [$key]");
            }
        }
    }
    print $outFile "    };\n";
    print $outFile "    iv_mapAttrMetadata\.insert( l_pair,\n";
    print $outFile "        l_pair + (sizeof(l_pair)/sizeof(l_pair[0])) );\n\n";
}

################################################################################
# Writes the map all attr size C file Footer
################################################################################

sub writeAttrMetadataMapCFileFooter {
    my($outFile) = @_;

    print $outFile <<VERBATIM;
    #undef TARG_FN
}

}// namespace TARGETING

VERBATIM
}

################################################################################
# Create a .H file to put All Target Attributes along with their respective
# Size and read/write properties in a unordered/ordered map variable
################################################################################

sub writeAttrMetadataMapHFile{
    my($outFile) = @_;
    print $outFile <<VERBATIM;

#ifndef MAPATTRMETADATA_H
#define MAPATTRMETADATA_H

/**
 *  \@file mapattrmetadata.H
 *
 *  \@brief Interface to get the unordered/ordered map of all target attributes
 *  respective attribute size and read/write properties. This file is
 *  autogenerated and should not be altered.
 */

// STD
#ifndef __HOSTBOOT_MODULE
#include <tr1/unordered_map>
#else
#include <map>
#endif

// TARG
#include <targeting/common/trace.H>
#include <targeting/common/target.H>

//******************************************************************************
// Macros
//******************************************************************************

#undef TARG_NAMESPACE
#undef TARG_CLASS
#undef TARG_FUNC

//******************************************************************************
// Interface
//******************************************************************************

#ifndef __HOSTBOOT_MODULE
/*
 * \@brief Specialized Hash function Template to be inserted with unordered_map
 */
namespace std
{

namespace tr1
{
    template <>
    struct hash<TARGETING::ATTRIBUTE_ID> : public unary_function<
                                            TARGETING::ATTRIBUTE_ID, size_t>
    {
        size_t operator()(const TARGETING::ATTRIBUTE_ID& attrId) const
        {
            return attrId;
        }
    };
}

}
#endif

namespace TARGETING
{

/*
 * \@brief - Data Struct to contain attribute related info
 *
 * Field Description
 * \@field1 - Size: Size of the attribute
 * \@field2 - readWriteable: true if read and writeable else false only readable
 * \@field3 - Persistency level of the attribute
 */
struct attrMetadataStr
{
    uint32_t size;
    bool readWriteable;
    const char* persistency;

    attrMetadataStr() :
        size(0), readWriteable(false), persistency(NULL) {}

    attrMetadataStr(uint32_t i_size, bool i_rw, const char* i_persistency) :
        size(i_size), readWriteable(i_rw), persistency(i_persistency) {}
};

/*
 * \@brief Typedef for struct attrMetadataStr
 */
typedef struct attrMetadataStr AttrMetadataStr;

/*
 * \@brief Typedef for pair<ATTRIBUTE_ID, AttrMetadataStr>
 */
typedef std::pair<ATTRIBUTE_ID, AttrMetadataStr> Pair_t;

#ifndef __HOSTBOOT_MODULE
/*
 * \@brief Typedef std::tr1::unordered_map <attr, struct attrMetadataStr,
 *      hash_method>
 */
typedef std::tr1::unordered_map<ATTRIBUTE_ID, AttrMetadataStr, \
    std::tr1::hash<TARGETING::ATTRIBUTE_ID> > AttrMetadataMapper;
#else
/*
 * \@brief Typedef std::map <attr, struct attrMetadataStr>
 */
typedef std::map<ATTRIBUTE_ID, AttrMetadataStr> AttrMetadataMapper;
#endif

class MapAttrMetadata
{
    public:
        /**
         *  \@brief Destroy the MapAttrMetadata class
         */
        ~MapAttrMetadata();

        /**
         *  \@brief Create the MapAttrMetadata class
         */
        MapAttrMetadata();

        /*
         *  \@brief returns the unordered/ordered map of all attributes as
         *  key and struct attrMetadataStr as value, which contains the size
         *  of the attribute along with read/writeable properties
         *
         *  \@return, returns the unordered/ordered map which has the all
         *  attributes as key and struct attrMetadataStr as value pair,
         *  variable <ATTRIBUTE_ID::struct attrMetadataStr>
         */
         const AttrMetadataMapper& getMapMetadataForAllAttributes() const;

     private:

        /* Unordered/Ordered map variable for All Attribute Ids vs Size &
         * Read/Write properties */
        AttrMetadataMapper iv_mapAttrMetadata;

        /* Disable Copy constructor and assignment operator */
        MapAttrMetadata(
            const MapAttrMetadata& i_right);

        MapAttrMetadata& operator = (
            const MapAttrMetadata& i_right);
};

/**
 *  \@brief Provide singleton access to the MapAttrMetadata
 */
TARG_DECLARE_SINGLETON(TARGETING::MapAttrMetadata, theMapAttrMetadata);

#undef TARG_CLASS
#undef TARG_NAMESPACE


}// namespace TARGETING

#endif // MAPATTRMETADATA_H

VERBATIM

}

######
#Create a .C file to put target into the errlog
#####
sub writeTargetErrlCFile {
    my($attributes,$outFile) = @_;

    #First setup the includes and function definition
    print $outFile "#include <stdint.h>\n";
    print $outFile "#include <stdio.h>\n";
    print $outFile "#include <string.h>\n";
    print $outFile "#include <errl/errludtarget.H>\n";
    print $outFile "#include <errl/errlreasoncodes.H>\n";
    print $outFile "#include <targeting/common/target.H>\n";
    print $outFile "#include <targeting/common/targetservice.H>\n";
    print $outFile "#include <targeting/common/trace.H>\n";
    print $outFile "\n";
    print $outFile "namespace ERRORLOG\n";
    print $outFile "{\n";
    print $outFile "using namespace TARGETING;\n";
    print $outFile "extern TARG_TD_t g_trac_errl;\n";

    print $outFile "//------------------------------------------------------------------------------\n";
    print $outFile "ErrlUserDetailsTarget::ErrlUserDetailsTarget(\n";
    print $outFile "    const Target * i_pTarget,\n";
    print $outFile "    const char* i_label)\n";
    print $outFile "{\n";
    print $outFile "    // Set up ErrlUserDetails instance variables\n";
    print $outFile "    iv_CompId = ERRL_COMP_ID;\n";
    print $outFile "    iv_Version = 1;\n";
    print $outFile "    iv_SubSection = ERRL_UDT_TARGET;\n";
    print $outFile "    // override the default of false\n";
    print $outFile "    iv_merge = true;\n";
    print $outFile "\n";
    print $outFile "    uint8_t* label_buf = NULL;\n";
    print $outFile "\n";
    print $outFile "    if (i_pTarget == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL) {\n";
    print $outFile "        label_buf = reallocUsrBuf(sizeof(uint32_t)\n";
    print $outFile "                                +sizeof(TargetLabel_t));\n";
    print $outFile "        uint32_t *pBuffer = reinterpret_cast<uint32_t*>\n";
    print $outFile "          (label_buf+sizeof(TargetLabel_t));\n";
    print $outFile "        // copy 0xFFFFFFFF to indicate MASTER just as gethuid() does\n";
    print $outFile "        *pBuffer = 0xFFFFFFFF;\n";
    print $outFile "    } else {\n";
    print $outFile "        uint32_t bufSize = 0;\n";
    print $outFile "        uint8_t *pTargetString = i_pTarget->targetFFDC(bufSize);\n";
    print $outFile "        label_buf = reallocUsrBuf(bufSize+sizeof(TargetLabel_t));\n";
    print $outFile "        uint8_t* pBuffer = (label_buf+sizeof(TargetLabel_t));\n";
    print $outFile "        memcpy(pBuffer, pTargetString, bufSize);\n";
    print $outFile "        free (pTargetString);\n";
    print $outFile "    }\n";
    print $outFile "\n";
    print $outFile "    // Prepend a label\n";
    print $outFile "    TargetLabel_t label;\n";
    print $outFile "    if( i_label )\n";
    print $outFile "    {\n";
    print $outFile "        strcpy( label.x, i_label );\n";
    print $outFile "    }\n";
    print $outFile "    else // no label, put a generic one in there\n";
    print $outFile "    {\n";
    print $outFile "        strcpy( label.x, \"Target\" );\n";
    print $outFile "    }\n";
    print $outFile "    memcpy( label_buf, &label, sizeof(label) );\n";
    print $outFile "}\n";
    print $outFile "\n";

    print $outFile "\n";

    print $outFile "//------------------------------------------------------------------------------\n";
    print $outFile "ErrlUserDetailsTarget::~ErrlUserDetailsTarget()\n";
    print $outFile "{ }\n";
    print $outFile "} // namespace\n";
} # sub writeTargetErrlCFile


######
#Create a .H file to parse attributes out of the errlog
#####
sub writeTargetErrlHFile {
    my($attributes,$outFile) = @_;

    #First setup the includes and function definition
    print $outFile "\n";
    print $outFile "#ifndef ERRL_UDTARGET_H\n";
    print $outFile "#define ERRL_UDTARGET_H\n";
    print $outFile "\n";
    print $outFile "namespace ERRORLOG\n";
    print $outFile "{\n";
    print $outFile "typedef struct TargetLabel_t\n";
    print $outFile "{\n";
    print $outFile "    static const uint32_t LABEL_TAG = 0xEEEEEEEE;\n";
    print $outFile "    uint32_t tag;\n";
    print $outFile "    char x[24]; //space to left of divider\n";
    print $outFile "    TargetLabel_t() : tag(0xEEEEEEEE)\n";
    print $outFile "    {\n";
    print $outFile "        memset(x,'\\0',sizeof(x));\n";
    print $outFile "    };\n";
    print $outFile "} TargetLabel_t;\n";
    print $outFile "}\n";
    print $outFile "#ifndef PARSER\n";
    print $outFile "\n";
    print $outFile "#include <errl/errluserdetails.H>\n";
    print $outFile "\n";
    print $outFile "namespace TARGETING // Forward reference\n";
    print $outFile "{ class Target; }\n";
    print $outFile "\n";
    print $outFile "namespace ERRORLOG\n";
    print $outFile "{\n";
    print $outFile "class ErrlUserDetailsTarget : public ErrlUserDetails {\n";
    print $outFile "public:\n";
    print $outFile "\n";
    print $outFile "    ErrlUserDetailsTarget(const TARGETING::Target * i_pTarget,\n";
    print $outFile "                          const char* i_label = NULL);\n";
    print $outFile "    virtual ~ErrlUserDetailsTarget();\n";
    print $outFile "\n";
    print $outFile "private:\n";
    print $outFile "\n";
    print $outFile "    // Disabled\n";
    print $outFile "    ErrlUserDetailsTarget(const ErrlUserDetailsTarget &);\n";
    print $outFile "    ErrlUserDetailsTarget & operator=(const ErrlUserDetailsTarget &);\n";
    print $outFile "};\n";
    print $outFile "}\n";
    print $outFile "#else // if PARSER defined\n";
    print $outFile "\n";
    print $outFile "#include \"errluserdetails.H\"\n";
    print $outFile "#include <string.h>\n";
    print $outFile "\n";
    print $outFile "namespace ERRORLOG\n";
    print $outFile "{\n";

    # local function used by Target and Callout to print the entity path

    print $outFile "  static uint8_t *errlud_parse_entity_path(uint8_t *i_ptr, char *o_ptr)\n";
    print $outFile "  {\n";
    print $outFile "      uint8_t *l_ptr = i_ptr;\n";

    print $outFile "      // from targeting/common/entitypath.[CH]\n";
    print $outFile "      // entityPath is PATH_TYPE:4, NumberOfElements:4, \n";
    print $outFile "      //          [Element, Instance#]\n";
    print $outFile "      // PATH_TYPE\n";
    print $outFile "      const char *pathString;\n";
    print $outFile "      const uint8_t pathTypeLength = *l_ptr;\n";
    print $outFile "      l_ptr++;\n";
    print $outFile "      const uint8_t pathType = (pathTypeLength & 0xF0) >> 4;\n";
    print $outFile "      switch (pathType) {\n";
    print $outFile "          case 0x01: pathString = \"Logical:\"; break;\n";
    print $outFile "          case 0x02: pathString = \"Physical:\"; break;\n";
    print $outFile "          case 0x03: pathString = \"Device:\"; break;\n";
    print $outFile "          case 0x04: pathString = \"Power:\"; break;\n";
    print $outFile "          default:   pathString = \"Unknown:\"; break;\n";
    print $outFile "      }\n";
    print $outFile "      uint32_t dataSize = sprintf(o_ptr, \"%s\",pathString);\n";
    print $outFile "      const uint8_t pathSize = (pathTypeLength & 0x0F) * 2;\n";
    print $outFile "      uint8_t *lElementInstance = l_ptr;\n";
    print $outFile "      l_ptr += pathSize * sizeof(uint8_t);\n";
    print $outFile "      for (uint32_t j=0;j<pathSize;j += 2) {\n";
    print $outFile "          switch (lElementInstance[j]) {\n";
    foreach my $enumerationType (@{$attributes->{enumerationType}})
    {
      if( $enumerationType->{id} eq "TYPE" ) {
        foreach my $enumerator (@{$enumerationType->{enumerator}})
        {
            my $enumHex = sprintf "0x%02X",
                enumNameToValue($enumerationType,$enumerator->{name});
            #my $enumName = $enumerationType->{id} . "_" . $enumerator->{name};
            my $enumName = $enumerator->{name};
            if ($enumName eq "SYS") {
                $enumName = "Sys";
            } elsif ($enumName eq "PROC") {
                $enumName = "Proc";
            } elsif ($enumName eq "NODE") {
                $enumName = "Node";
            } elsif ($enumName eq "CORE") {
                $enumName = "Core";
            } elsif ($enumName eq "MEMBUF") {
                $enumName = "Membuf";
            }
            print $outFile "              case $enumHex: { pathString = \"/$enumName\"; break; }\n";
        }
      }
    } # enumerationType
    print $outFile "              default:   { pathString = \"/UKNOWN\"; break; }\n";

    print $outFile "          } // switch\n";
    print $outFile "          // copy next part in, overwritting previous terminator\n";
    print $outFile "          dataSize += sprintf(o_ptr + dataSize,\n";
    print $outFile "                              \"%s%d\", pathString,\n";
    print $outFile "                              lElementInstance[j+1]);\n";
    print $outFile "      } // for\n";
    print $outFile "      return l_ptr;\n";
    print $outFile "} // errlud_parse_entity_path \n";

    print $outFile "class ErrlUserDetailsParserTarget : public ErrlUserDetailsParser {\n";
    print $outFile "public:\n";
    print $outFile "\n";
    print $outFile "    ErrlUserDetailsParserTarget() {}\n";
    print $outFile "\n";
    print $outFile "    virtual ~ErrlUserDetailsParserTarget() {}\n";
    print $outFile "/**\n";
    print $outFile " *  \@brief Parses Target user detail data from an error log\n";
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
    print $outFile "    const char *attrData;\n";
    print $outFile "    char l_label[24];\n";
    print $outFile "    sprintf(l_label,\"Target\");\n";
    print $outFile "    uint32_t *l_ptr32 = reinterpret_cast<uint32_t *>(i_pBuffer);\n";
    print $outFile "    // while there is still at least 1 word of data left\n";
    print $outFile "    for (; (l_ptr32 + 1) <= (uint32_t *)((uint8_t*)i_pBuffer + i_buflen); )\n";
    print $outFile "    {\n";
    print $outFile "      if (*l_ptr32 == 0xFFFFFFFF) { // special - master\n";
    print $outFile "        i_parser.PrintString(\"Target\", \"MASTER_PROCESSOR_CHIP_TARGET_SENTINEL\");\n";
    print $outFile "        l_ptr32++; // past the marker\n";
    print $outFile "      } else if (*l_ptr32 == TargetLabel_t::LABEL_TAG) {\n";
    print $outFile "        TargetLabel_t* tmp_label = reinterpret_cast<TargetLabel_t*>(l_ptr32);\n";
    print $outFile "        memcpy( l_label, tmp_label->x, sizeof(l_label)-1 );\n";
    print $outFile "        l_ptr32 += (sizeof(TargetLabel_t)/sizeof(uint32_t));\n";
    print $outFile "      } else { \n";

    print $outFile "        // first 4 are always the same\n";
    print $outFile "        if ((l_ptr32 + 4) <= (uint32_t *)((uint8_t*)i_pBuffer + i_buflen)) {\n";
    print $outFile "            i_parser.PrintNumber( l_label, \"HUID = 0x%08X\", ntohl(*l_ptr32) );\n";
    print $outFile "            l_ptr32++;\n";

    # find CLASS
    print $outFile "            switch (ntohl(*l_ptr32)) { // CLASS\n";
    foreach my $enumerationType (@{$attributes->{enumerationType}})
    {
      if( $enumerationType->{id} eq "CLASS" ) {
        foreach my $enumerator (@{$enumerationType->{enumerator}})
        {
            my $enumHex = sprintf "0x%02X",
                enumNameToValue($enumerationType,$enumerator->{name});
            my $enumName = $enumerationType->{id} . "_" . $enumerator->{name};
            print $outFile "                case $enumHex: { attrData = \"$enumName\"; break; }\n";
        }
      }
    } # enumerationType
    print $outFile "                default:   { attrData = \"UNKNOWN_CLASS\"; break; }\n";
    print $outFile "            } // switch\n";
    print $outFile "            i_parser.PrintString(\"  ATTR_CLASS\", attrData);\n";
    print $outFile "            l_ptr32++;\n";

    # find TYPE
    print $outFile "            switch (ntohl(*l_ptr32)) { // TYPE\n";
    foreach my $enumerationType (@{$attributes->{enumerationType}})
    {
      if( $enumerationType->{id} eq "TYPE" ) {
        foreach my $enumerator (@{$enumerationType->{enumerator}})
        {
            my $enumHex = sprintf "0x%02X",
                enumNameToValue($enumerationType,$enumerator->{name});
            my $enumName = $enumerationType->{id} . "_" . $enumerator->{name};
            print $outFile "                case $enumHex: { attrData = \"$enumName\"; break; }\n";
        }
      }
    } # enumerationType
    print $outFile "                default:   { attrData = \"UNKNOWN_TYPE\"; break; }\n";
    print $outFile "            } // switch\n";
    print $outFile "            i_parser.PrintString(\"  ATTR_TYPE\", attrData);\n";
    print $outFile "            l_ptr32++;\n";

    # find MODEL
    print $outFile "            switch (ntohl(*l_ptr32)) { // MODEL\n";
    foreach my $enumerationType (@{$attributes->{enumerationType}})
    {
      if( $enumerationType->{id} eq "MODEL" ) {
        foreach my $enumerator (@{$enumerationType->{enumerator}})
        {
            my $enumHex = sprintf "0x%02X",
                enumNameToValue($enumerationType,$enumerator->{name});
            my $enumName = $enumerationType->{id} . "_" . $enumerator->{name};
            print $outFile "                case $enumHex: { attrData = \"$enumName\"; break; }\n";
        }
      }
    } # enumerationType
    print $outFile "                default:   { attrData = \"UNKNOWN_MODEL\"; break; }\n";
    print $outFile "            } // switch\n";
    print $outFile "            i_parser.PrintString(\"  ATTR_MODEL\", attrData);\n";
    print $outFile "            l_ptr32++;\n";
    print $outFile "            // 2 Entity Paths next\n";
    print $outFile "            for (uint32_t k = 0;k < 2; k++)\n";
    print $outFile "            {\n";

    my $attrPhysPath;
    my $attrAffinityPath;

    # need the attribute id's for ATTR_PHYS_PATH and ATTR_AFFINITY_PATH:
    my $attributeIdEnumeration = getAttributeIdEnumeration($attributes);
    foreach my $enumerator (@{$attributeIdEnumeration->{enumerator}})
    {
        if ($enumerator->{name} eq "PHYS_PATH")
        {
            $attrPhysPath = $enumerator->{value};
        }
        elsif ($enumerator->{name} eq "AFFINITY_PATH")
        {
            $attrAffinityPath = $enumerator->{value};
        }
    }

    print $outFile "                uint32_t l_pathType = ntohl(*l_ptr32);\n";
    print $outFile "                if ((l_pathType == $attrPhysPath) || // ATTR_PHYS_PATH\n";
    print $outFile "                    (l_pathType == $attrAffinityPath))   // ATTR_AFFINITY_PATH\n";
    print $outFile "                {\n";
    print $outFile "                    l_ptr32++;\n";
    print $outFile "                    uint8_t *l_ptr = reinterpret_cast<uint8_t *>(l_ptr32);\n";
    print $outFile "                    char outString[128];\n";
    print $outFile "                    l_ptr = errlud_parse_entity_path(l_ptr,outString);\n";
    print $outFile "                    if (l_pathType == $attrPhysPath)\n";
    print $outFile "                    {\n";
    print $outFile "                      i_parser.PrintString(\"  ATTR_PHYS_PATH\", outString);\n";
    print $outFile "                    }\n";
    print $outFile "                    if (l_pathType == $attrAffinityPath)\n";
    print $outFile "                    {\n";
    print $outFile "                      i_parser.PrintString(\"  ATTR_AFFINITY_PATH\", outString);\n";
    print $outFile "                    } // else don't print anything\n";
    print $outFile "                    l_ptr32 = reinterpret_cast<uint32_t *>(l_ptr);\n";
    print $outFile "                } else {\n";
    print $outFile "                    l_ptr32++;\n";
    print $outFile "                }\n";
    print $outFile "            } // for\n";
    print $outFile "        } // if\n";
    print $outFile "      }\n";
    print $outFile "    } // for\n";
    print $outFile "  } // parse()\n\n";
    print $outFile "private:\n";
    print $outFile "\n";
    print $outFile "// Disabled\n";
    print $outFile "ErrlUserDetailsParserTarget(const ErrlUserDetailsParserTarget &);\n";
    print $outFile "ErrlUserDetailsParserTarget & operator=(const ErrlUserDetailsParserTarget &);\n";
    print $outFile "};\n";
    print $outFile "} // namespace\n";
    print $outFile "#endif\n";
    print $outFile "#endif\n";
} # sub writeTargetErrlHFile

################################################################################
# Writes the map system attr size C file header
################################################################################

sub writeAttrSizeMapCFileHeader {
    my($outFile) = @_;

print $outFile <<VERBATIM;

/**
 *  \@file mapsystemattrsize.C
 *
 *  \@brief Interface to get the map of system target attributes with respective
 *  attribute size
 */

// STD
#include <map>

// TARG
#include <mapsystemattrsize.H>


//******************************************************************************
// Macros
//******************************************************************************

#undef TARG_NAMESPACE
#undef TARG_CLASS
#undef TARG_FUNC

//******************************************************************************
// Implementation
//******************************************************************************

namespace TARGETING
{


#define TARG_NAMESPACE "TARGETING::"
#define TARG_CLASS "MapSystemAttrSize::"

//******************************************************************************
// TARGETING::mapSystemAttrSize
//******************************************************************************

TARGETING::MapSystemAttrSize& mapSystemAttrSize()
{
    #define TARG_FN "mapSystemAttrSize()"

    return TARG_GET_SINGLETON(TARGETING::theMapSystemAttrSize);

    #undef TARG_FN
}

//******************************************************************************
// TARGETING::MapSystemAttrSize::~MapSystemAttrSize
//******************************************************************************

MapSystemAttrSize::~MapSystemAttrSize()
{
    #define TARG_FN "~MapSystemAttrSize()"
    #undef TARG_FN
}

//******************************************************************************
// TARGETING::MapSystemAttrSize::getMapForWriteableSystemAttributes
//******************************************************************************

const AttrSizeMapper&
MapSystemAttrSize::getMapForWriteableSystemAttributes() const
{
    #define TARG_FN "getMapForWriteableSystemAttributes()"
    TARG_ENTER();

    TARG_EXIT();
    return iv_mapSysAttrSize;

    #undef TARG_FN
}

//******************************************************************************
// TARGETING::MapSystemAttrSize::MapSystemAttrSize
//******************************************************************************

MapSystemAttrSize::MapSystemAttrSize()
{
    #define TARG_FN "MapSystemAttrSize()"
VERBATIM

}

######
# Create a .C file to put System Target Attributes along with there respective
# Size in a map file
######
sub writeAttrSizeMapCFile{
    my($attributes,$outFile) = @_;
    my %finalAttrhash = ();

    # look for type sys-sys-power8 and store all attributes associated
    foreach my $targetType (@{$attributes->{targetType}})
    {
        if($targetType->{id} =~ m/^sys-sys-/)
        {
            my %attrhash = ();
            getTargetAttributes($targetType->{id}, $attributes,\%attrhash);
            foreach my $key ( keys %attrhash )
            {
                foreach my $attr (@{$attributes->{attribute}})
                {
                    if($attr->{id} eq $key)
                    {
                        if((exists $attr->{writeable}) &&
                            (!(exists $attr->{hbOnly})))
                        {
                            # we have the attr here.. calculate the size
                            my $keyVal = "ATTR_"."$key"."_type";
                            if( (exists $attr->{simpleType}) ||
                                (exists $attr->{complexType}) ||
                                (exists $attr->{nativeType}) )
                            {
                                $finalAttrhash{$key} = $keyVal;
                            }
                            else
                            {
                                print STDOUT "\t// Attribute $key is writable "
                                    . "& Not Supported \n";
                            }
                        }
                    }
                }
            }
        }
    }
    print $outFile "\n";
    foreach my $key ( keys %finalAttrhash)
    {
        print $outFile "    iv_mapSysAttrSize[ATTR_"
            . "$key] = sizeof($finalAttrhash{$key});\n";
    }
    print $outFile "\n";
}

################################################################################
# Writes the map system attr size C file Footer
################################################################################

sub writeAttrSizeMapCFileFooter {
    my($outFile) = @_;

    print $outFile <<VERBATIM;
    #undef TARG_FN
}

}// namespace TARGETING

VERBATIM
}

######
# Create a .H file to put System Target Attributes along with their respective
# Size in a map file
######
sub writeAttrSizeMapHFile{
    my($outFile) = @_;
    print $outFile <<VERBATIM;

#ifndef MAPSYSTEMATTRSIZE_H
#define MAPSYSTEMATTRSIZE_H

/**
 *  \@file mapsystemattrsize.H
 *
 *  \@brief Interface to get the map of system target attributes with respective
 *  attribute size
 */

// STD
#include <map>

// TARG
#include <targeting/common/trace.H>
#include <targeting/common/target.H>

//******************************************************************************
// Macros
//******************************************************************************

#undef TARG_NAMESPACE
#undef TARG_CLASS
#undef TARG_FUNC

//******************************************************************************
// Interface
//******************************************************************************

namespace TARGETING
{

class MapSystemAttrSize;

/**
 *  \@brief Return the MapSystemAttrSize singleton instance
 *
 *  \@return Reference to the MapSystemAttrSize singleton
 */
TARGETING::MapSystemAttrSize& mapSystemAttrSize();


#define TARG_NAMESPACE "MAPSYSTEMATTRSIZE::"

#define TARG_CLASS "MapSystemAttrSize::"

/*
 * \@brief Typedef map <attr, attSize>
 */
typedef std::map<ATTRIBUTE_ID, uint32_t> AttrSizeMapper;

class MapSystemAttrSize
{

    public:
        /**
         *  \@brief Destroy the MapSystemAttrSize class
         */
        ~MapSystemAttrSize();

        /**
         *  \@brief Create the MapSystemAttrSize class
         */
        MapSystemAttrSize();

        /*
         *  \@brief returns the map of Writeable System attributes as Key and
         *  size of the attributes as value.
         *
         *  \@return, returns the map which has the Writeable Sytem attributes
         *  as key and size as value pair, variable <SYSTEM_ATTRIBUTE_ID::Size>
         */
         const AttrSizeMapper& getMapForWriteableSystemAttributes() const;

     private:

        /* Map variable for System Attribute Ids Vs the Size */
        AttrSizeMapper iv_mapSysAttrSize;

        /* Disable Copy constructor and assignment operator */
        MapSystemAttrSize(
            const MapSystemAttrSize& i_right);

        MapSystemAttrSize& operator = (
            const MapSystemAttrSize& i_right);
};

/**
 *  \@brief Provide singleton access to the MapSystemAttrSize
 */
TARG_DECLARE_SINGLETON(TARGETING::MapSystemAttrSize, theMapSystemAttrSize);

#undef TARG_CLASS
#undef TARG_NAMESPACE


}// namespace TARGETING

#endif // MAPSYSTEMATTRSIZE_H

VERBATIM

}

sub UTILITY_FUNCTIONS { }

################################################################################
# Get the hash hex string for an attribute name (ID).
################################################################################
sub getAttributeIdHashStr
{
    my ($attrId) = @_;
    return substr(md5_hex($attrId),0,7);
}

################################################################################
# Get generated enumeration describing attribute IDs
################################################################################

sub getAttributeIdEnumeration {
  my($attributes) = @_;

    my $attributeValue = 1;
    my $enumeration = { } ;
    my %attrValHash;

    # add the N/A value
    $enumeration->{description} = "Internal enum for attribute IDs\n";
    $enumeration->{default} = "NA";
    $enumeration->{enumerator}->[0]->{name} = "NA";
    $enumeration->{enumerator}->[0]->{value} = 0;

    foreach my $attribute (@{$attributes->{attribute}})
    {
        my $attributeHexVal28bit = getAttributeIdHashStr($attribute->{id});

        # check if this Id has already been processed
        if(exists($attrValHash{$attributeHexVal28bit}))
        {
            # fatal error if multiple IDs hash to same value
            if ( $attribute->{id} ne $attrValHash{$attributeHexVal28bit} )
            {
               fatal(
                 "Error:Duplicate AttributeId hashvalue for $attribute->{id} "
                     . "and $attrValHash{$attributeHexVal28bit}");
            }
            # fatal error if attribute has been defined more than once.
            # Could be defined twice in same file or defined in two files
            # that have been merged, such as attributes_types.xml and
            # attribute_types_hb.xml or attributes_types_fsp.
            else
            {
               fatal("Error: AttributeId $attribute->{id} "
                     . "defined multiple times");
            }
        }
        else
        {
            # add the name here so we can check for duplicate names
            $attrValHash{$attributeHexVal28bit}= $attribute->{id};

            $enumeration->{enumerator}->[$attributeValue]->{name}
            = $attribute->{id};
            $enumeration->{enumerator}->[$attributeValue]->{value}
            = sprintf "0x%s",$attributeHexVal28bit;
            $attribute->{value} = $attributeValue;
            $attributeValue++;
        }
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

sub pack64bitsDecimal {
    my($quad) = @_;

    my $package = unpack("H*", pack8byte($quad));
    if(!$cfgBigEndian)
    {
        my $val1 = sprintf("%08x", ((hex($package) >> 32)  & 0xFFFFFFFF));
        my $val2 = sprintf("%08x", (hex($package) & 0xFFFFFFFF));
        $package = $val1.$val2;
    }
    return hex($package);
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
# Strips off leading and trailing whitespace from a string and returns it
################################################################################

sub stripLeadingAndTrailingWhitespace {
    my($string) = @_;

    $string =~ s/^\s+|\s+$//g;

    return $string;
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
    my $targetCount = 0;
    my $moveSysTarget = 0;

    # To simplify the iterator code, always move a system target that appears as
    # the first target to the next position
    foreach my $targetInstance (@{$attributes->{targetInstance}})
    {
        if(($targetInstance->{type} =~ m/^sys-sys-/) && ($targetCount == 0))
        {
            $targetCount = $targetCount + 1;
            $moveSysTarget = 1;
        }
        push (@uniqueTargetTypes, $targetInstance->{type})
            unless $seen{$targetInstance->{type}}++;
    }
    if($moveSysTarget == 1)
    {
        @uniqueTargetTypes[0,1] = @uniqueTargetTypes[1,0];
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
# Enforce special fsp mutex restrictions
################################################################################

sub enforceFspMutex {
    my($attribute,$value) = @_;

    if($value != 0)
    {
        fatal("FSP mutex attribute default must always be 0, "
              . "was $value instead.");
    }

    if($attribute->{persistency} ne "volatile-zeroed")
    {
        fatal("FSP mutex attribute persistency must be volatile-zeroed, "
              . "was $attribute->{persistency} instead");
    }
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
    $typesHoH{"fspmutex"}     = { supportsArray => 1, canBeHex => 1, complexTypeSupport => 0, typeName => "util::Mutex*"              , bytes => 8, bits => 64, default => \&defaultZero  , alignment => 8, specialPolicies =>\&enforceFspMutex, packfmt =>\&pack8byte};

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
                    if( exists $attribute->{nativeType}->{default} )
                    {
                        $default = $attribute->{nativeType}->{default};
                    }
                    else
                    {
                        $default =  "MustBeOverriddenByTargetInstance";
                    }
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
        $fspTargetInstance = $g_fspTargetTypesCache{$targetInstance->{type}};
    }
    else
    {
        %g_fspTargetTypesCache =
            map { $_->{id} => exists $_->{fspOnly} ? 1:0 }
                @{$attributes->{targetType}};
        $fspTargetInstance = $g_fspTargetTypesCache{$targetInstance->{type}};
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
        fatal("Unsupported entity path type of [$value], [$typeStr], [$path].");
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

        if (ref($value) eq "HASH")
        {
            # value is a hash ref, XML::Simple represents an empty element with
            # an empty hash. Map to zero.
            # TODO RTC 103737. Remove this check. Empty elements should cause
            # a compile failure. This RTC will resolve a Brazos MFG Targeting
            # image problem where chip IDs from the MRW are empty elements.
            $value = 0;
        }
        elsif ($value eq 'true')
        {
            $value = 1;
        }
        elsif ($value eq 'false')
        {
            $value = 0;
        }

        if( ($simpleTypeProperties->{$typeName}{complexTypeSupport}) &&
            ($value =~ m/[^0-9]/) )
        {
            # This is a type that supports complex types - i.e. an integer and
            # the value is a string. Look for an enumeration named after the
            # attribute id, if one is not found then one of the function calls
            # below will exit with error
            my $enumeration = getEnumerationType($$attributesRef,
                $$attributeRef->{id});

            $value = enumNameToValue($enumeration, $value);
        }

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

    $value = stripLeadingAndTrailingWhitespace($value);

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
                            # Get the value from the value array and strip any
                            # remaining leading/trailing whitespace that
                            # surrounded the value after the original split
                            $val = stripLeadingAndTrailingWhitespace($values[$i]);
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
# Given a number, return a decimal/hexidecimal pair (for debug)
################################################################################

sub toDecAndHex
{
    my ($val) = @_;
    return "$val/" .  sprintf("0x%016X",$val);
}

################################################################################
# Trace association code entry (for debug)
################################################################################

sub ASSOC_ENTER
{
    if($ENV{"ASSOC_FUNC"} eq "1")
    {
        my ($trace) = @_;
        my ($package, $filename, $line, $undef, $hasargs, $wantarray, $evaltext,
            $is_require, $hints, $bitmask, $hinthash) = caller (0);
        my (undef,undef,undef,$subroutine) = caller (1);
        print STDERR "ENTER>> Function $subroutine, Line: $line\n";
        print STDERR "    " . $trace . "\n";
    }
}

################################################################################
# Trace association code exit (for debug)
################################################################################

sub ASSOC_EXIT
{
    if($ENV{"ASSOC_FUNC"} eq "1")
    {
        my ($trace) = @_;
        my ($package, $filename, $line, $undef, $hasargs, $wantarray, $evaltext,
            $is_require, $hints, $bitmask, $hinthash) = caller (0);
        my (undef,undef,undef,$subroutine) = caller (1);
        print STDERR "EXIT>> Function $subroutine, Line: $line\n";
        print STDERR "    " . $trace . "\n";
    }
}

################################################################################
# Trace association code debug statements
################################################################################

sub ASSOC_DBG
{
    if($ENV{"ASSOC_DBG"} eq "1")
    {
        my ($trace) = @_;
        my ($package, $filename, $line, $subroutine, $hasargs, $wantarray,
            $evaltext, $is_require, $hints, $bitmask, $hinthash) = caller (0);
        print STDERR "DEBUG($line): " . $trace . "\n";
    }
}

################################################################################
# Trace association code important statements
################################################################################

sub ASSOC_IMP
{
    if($ENV{"ASSOC_IMP"} eq "1")
    {
        my ($trace) = @_;
        my ($package, $filename, $line, $subroutine, $hasargs, $wantarray,
            $evaltext, $is_require, $hints, $bitmask, $hinthash) = caller (0);
        print STDERR "IMP($line): " . $trace . "\n";
    }
}

################################################################################
# Update dummy pointers with real pointers in binary blob of target structs
################################################################################

sub updateTargetAssociationPointers
{
    my ( $targetAddrHashRef, $targetsBinDataRef ) = @_;

    ASSOC_ENTER();

    foreach my $id ( keys %$targetAddrHashRef )
    {
        ASSOC_DBG("Fixing up target with ID = $id");
        foreach my $associationType (@associationTypes)
        {
            # Seek to pointer location within target object and replace the
            # dummy value with the real value
            my $seek = $targetAddrHashRef->{$id}{
                "offsetToPtrTo" . $associationType . "Associations"};
            my $pointer = $targetAddrHashRef->{$id}{ $associationType . "Ptr" };
            ASSOC_DBG("Seeking to offset: $seek");
            # Keeping the actual pointer as it is, making a copy of it and
            # using it for inversion if little endian
            my $myPointer = pack64bitsDecimal($pointer);
            ASSOC_IMP("Writing pointer value of: " . toDecAndHex($pointer) );
            ASSOC_IMP("Writing myPointer value of: " . toDecAndHex($myPointer));

            for(my $pointerByte=0; $pointerByte<8; ++$pointerByte)
            {
                my $val = sprintf("%02x",(($myPointer >>
                        ((BYTE_RIGHT_BIT_INDEX-$pointerByte)*BITS_PER_BYTE)) &
                         LOW_BYTE_MASK));
                ASSOC_IMP("Writing byte value : $val");
                vec($$targetsBinDataRef, $seek+$pointerByte,BITS_PER_BYTE) =
                                                                  hex($val);
            }
        }
    }

    ASSOC_EXIT();
}

################################################################################
# Serialize association data into a binary blob
################################################################################

sub serializeAssociations
{
    my ($offsetWithinBinary, $targetsAoHRef, $targetAddrHashRef,
        $associationsBinDataRef ) = @_;
    ASSOC_ENTER();

    foreach my $targetInstance (@$targetsAoHRef)
    {
        my $id = $targetInstance->{id};
        ASSOC_DBG("Serializing target = $id");
        foreach my $associationType (@associationTypes)
        {
            $targetAddrHashRef->{$id}{ $associationType . "Ptr" }
                = $offsetWithinBinary;
            ASSOC_DBG("Offset within binary = $offsetWithinBinary");
            my $pointers = "Association = $associationType, pointers = ";
            foreach my $pointer ( @ { $targetAddrHashRef->{$id}
                                          { $associationType . "Associations"}})
            {
                $$associationsBinDataRef .= pack8byte($pointer);
                $offsetWithinBinary += BYTES_PER_ABSTRACT_POINTER;
                $pointers .= toDecAndHex($pointer);
                $pointers .= ", ";
            }
            chomp($pointers);
            chomp($pointers);
            ASSOC_DBG($pointers);
        }
    }
    my $associationsBinDataSize = length $$associationsBinDataRef;
    ASSOC_IMP("Size of association section = $associationsBinDataSize");
    ASSOC_EXIT();
}

################################################################################
# Write the PNOR targeting image
################################################################################

sub generateTargetingImage {
    my($vmmConstsFile, $attributes, $Target_t,$addRO_Section_VerPage) = @_;

    # 128 MB virtual memory offset between sections
    my $vmmSectionOffset = 128 * 1024 * 1024; # 128MB

    # Virtual memory addresses corresponding to the start of the targeting image
    # PNOR/heap sections
    my $pnorRoBaseAddress    = getPnorBaseAddress($vmmConstsFile);
    my $pnorRwBaseAddress    = $pnorRoBaseAddress    + $vmmSectionOffset;
    my $heapPnorInitBaseAddr = $pnorRwBaseAddress    + $vmmSectionOffset;
    my $heapZeroInitBaseAddr = $heapPnorInitBaseAddr + $vmmSectionOffset;
    my $hbHeapZeroInitBaseAddr = $heapZeroInitBaseAddr + $vmmSectionOffset;

    # Split "fsp" into additional sections
    my $fspP0DefaultedFromZeroBaseAddr   = $hbHeapZeroInitBaseAddr + $vmmSectionOffset;
    my $fspP0DefaultedFromP3BaseAddr  = $fspP0DefaultedFromZeroBaseAddr + $vmmSectionOffset;
    my $fspP3RoBaseAddr         = $fspP0DefaultedFromP3BaseAddr + $vmmSectionOffset;
    my $fspP3RwBaseAddr         = $fspP3RoBaseAddr + $vmmSectionOffset;
    my $fspP1DefaultedFromZeroBaseAddr   = $fspP3RwBaseAddr + $vmmSectionOffset;
    my $fspP1DefaultedFromP3BaseAddr  = $fspP1DefaultedFromZeroBaseAddr + $vmmSectionOffset;

    # Reserve 256 bytes for the header, then keep track of PNOR RO offset
    my $headerSize = 256;
    my $offset = $headerSize;


    #If the file to be created is the HB targeting binary , then it will contain
    #first page (4096 bytes) as the read-only data checksum. Need to adjust the
    #read-only section offset.
    my $versionSectionSize = 4096;

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
        #    Sort the list by attribute ID (hash value) so that we can do a
        #    binary search at runtime.
        my $perTargetTypeAttrBinData;
        for my $attributeId
            (sort
                { getAttributeIdHashStr($a) cmp getAttributeIdHashStr($b) }
                (keys %attrhash)
            )
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
    my $targetCount = 0;
    my $moveSysTarget = 0;
    my $targetSystemInstance = 0;
    my $targetNodeInstance = 0;
    my $targetSysCnt = 0;
    my $targetNodeCnt = 0;

    # To support the iterator code, we dont want sys target to be the
    # first in order. So we have specifically moved system target to second,
    # and the first place has been reserved by a node target for all binaries.
    foreach my $targetInstance (@{$attributes->{targetInstance}})
    {
        if(($targetInstance->{type} =~ m/^sys-sys-/) && ($targetSysCnt == 0))
        {
            $targetSysCnt = 1;
            $targetSystemInstance = $targetInstance;
            next;
        }
        elsif(($targetInstance->{type} eq "enc-node-power8") && ($targetNodeCnt == 0))
        {
            $targetNodeCnt = 1;
            $targetNodeInstance = $targetInstance;
            next;
        }
        push(@targetsAoH, $targetInstance);
    }
    unshift(@targetsAoH, $targetSystemInstance);
    unshift(@targetsAoH, $targetNodeInstance);

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

    # Split into more granular sections
    my $fspP0DefaultedFromZeroOffset = 0;
    my $fspP0DefaultedFromZeroBinData;
    my $fspP0DefaultedFromP3Offset = 0;
    my $fspP0DefaultedFromP3BinData;
    my $fspP1DefaultedFromZeroOffset = 0;
    my $fspP1DefaultedFromZeroBinData;
    my $fspP1DefaultedFromP3Offset = 0;
    my $fspP1DefaultedFromP3BinData;
    my $fspP3RoOffset = 0;
    my $fspP3RoBinData;
    my $fspP3RwOffset = 0;
    my $fspP3RwBinData;

    # Hostboot specific section
    my $hbHeapZeroInitOffset = 0;
    my $hbHeapZeroInitBinData;

    my $attributePointerBinData;
    my $targetsBinData;

    # Ensure consistent ordering of target instances
    my $attrAddr = $pnorRoBaseAddress + $startOfAttributePointers;

    # Configure globals for computing associations
    my %targetAddrHash = ();
    my $offsetWithinTargets = 0;
    my @NullPtrArray = ( 0 ) ;

    foreach my $targetInstance (@targetsAoH)
    {
        my $data;

         # print "TargetInstance: $targetInstance->{id}\n";
         # print "    Attributes:  ",
         # $attributeListTypeHoH{$targetInstance->{type}}{elements}, "\n" ;
         # print "        offset:  ",
         # $attributeListTypeHoH{$targetInstance->{type}}{offset}, "\n" ;

        # Keep track of where this target is from start of targets
        $targetAddrHash{$targetInstance->{id}}{OffsetToTargetWithinTargetList}
            = $offsetWithinTargets;

        # Create target record
        $data .= pack4byte(
            $attributeListTypeHoH{$targetInstance->{type}}{elements});
        $data .= pack8byte(
              $attributeListTypeHoH{$targetInstance->{type}}{offset}
            + $pnorRoBaseAddress);
        $data .= pack8byte($attrAddr);

        # Make note of the offsets within the blob of targets where each pointer
        # for each association list is.  Also reserve each pointer with an
        # invalid value for now.
        use constant INVALID_POINTER => 0;
        my $ptrToParentByContainmentAssociations = INVALID_POINTER;
        my $ptrToChildByContainmentAssociations = INVALID_POINTER;
        my $ptrToParentByAffinityAssociations = INVALID_POINTER;
        my $ptrToChildByAffinityAssociations = INVALID_POINTER;

        my $id = $targetInstance->{id};
        $targetAddrHash{$id}{offsetToPtrToParentByContainmentAssociations} =
            $offsetWithinTargets + length $data;
        $data .= pack8byte($ptrToParentByContainmentAssociations);

        $targetAddrHash{$id}{offsetToPtrToChildByContainmentAssociations} =
            $offsetWithinTargets + length $data;
        $data .= pack8byte($ptrToChildByContainmentAssociations);

        $targetAddrHash{$id}{offsetToPtrToParentByAffinityAssociations} =
            $offsetWithinTargets + length $data;
        $data .= pack8byte($ptrToParentByAffinityAssociations);

        $targetAddrHash{$id}{offsetToPtrToChildByAffinityAssociations} =
            $offsetWithinTargets + length $data;
        $data .= pack8byte($ptrToChildByAffinityAssociations);

        $targetAddrHash{$id}{ParentByContainmentAssociations} = [@NullPtrArray];
        $targetAddrHash{$id}{ChildByContainmentAssociations} = [@NullPtrArray];
        $targetAddrHash{$id}{ParentByAffinityAssociations} = [@NullPtrArray];
        $targetAddrHash{$id}{ChildByAffinityAssociations} = [@NullPtrArray];

        if($id =~/^sys\d+$/)
        {
            ASSOC_DBG("Found system target of $id, reserving space");
            for(my $reserved = 0;
                $reserved < MAX_COMPUTE_AND_CONTROL_NODE_SUM - 1; ++$reserved)
            {
                unshift
                    @ { $targetAddrHash{$id}{ChildByContainmentAssociations} },
                    0;
                unshift
                    @ { $targetAddrHash{$id}{ChildByAffinityAssociations} },
                    0;
            }
        }

        ASSOC_DBG("Target ID = $id");
        ASSOC_DBG("Offset within targets to ptr to parent containment list = "
        . "$targetAddrHash{$id}{offsetToPtrToParentByContainmentAssociations}");
        ASSOC_DBG("Offset within targets to ptr to child containment list = "
        . "$targetAddrHash{$id}{offsetToPtrToChildByContainmentAssociations}");
        ASSOC_DBG("Offset within targets to ptr to parent affinit list = "
        . "$targetAddrHash{$id}{offsetToPtrToParentByAffinityAssociations}");
        ASSOC_DBG("Offset within targets to ptr to child affinity list = "
        . "$targetAddrHash{$id}{offsetToPtrToChildByAffinityAssociations}");

        $attrAddr += $attributeListTypeHoH{$targetInstance->{type}}{elements}
            * (length pack8byte(0));

        # Increment the offset
        $offset += (length $data);
        $offsetWithinTargets += (length $data);

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

        my $huidValue = $attrhash{HUID}->{default};

        # Flag if target is FSP specific; in that case store all of its
        # attributes in the FSP section, regardless of whether they are
        # themselves FSP specific.  Only need to do this 1x per target instance
        my $fspTarget = isFspTargetInstance($attributes,$targetInstance);

        my %attributeDefCache =
            map { $_->{id} => $_} @{$attributes->{attribute}};

        # Must have the same order as the attribute list from above.
        for my $attributeId
            (sort
                { getAttributeIdHashStr($a) cmp getAttributeIdHashStr($b) }
                (keys %attrhash)
            )
        {
            # Save each target's physical + affinity path for association
            # processing later on
            if(   ($attributeId eq ATTR_PHYS_PATH)
               || ($attributeId eq ATTR_AFFINITY_PATH) )
            {
                $targetAddrHash{$targetInstance->{id}}{$attributeId} =
                    $attrhash{$attributeId}->{default};
            }

            my $attrValue =
            enumNameToValue($attributeIdEnumeration,$attributeId);
            $attrValue = sprintf ("%0x", $attrValue);
            my $attributeDef = $attributeDefCache{$attributeId};
            if (not defined $attributeDef)
            {
                fatal("Attribute $attributeId is not found.");
            }

            my $ifFspOnlyTargetWithCommonAttr = "false";
            # Need to separate out the Fsp only target's common attributes
            if( ($fspTarget) && (!exists $attributeDef->{fspOnly}) &&
                (!exists $attributeDef->{hbOnly}))
            {
                if( $attributeDef->{persistency} eq "volatile-zeroed"  )
                {
                    $ifFspOnlyTargetWithCommonAttr = "true";
                }
                elsif( $attributeDef->{persistency} eq "volatile" )
                {
                    $ifFspOnlyTargetWithCommonAttr = "true";
                }
            }

            my $section;
            # Split "fsp" into more sections later
            if( (exists $attributeDef->{fspOnly})
               || ($fspTarget))
            {
                if( $attributeDef->{persistency} eq "volatile-zeroed"  )
                {
                    $section = "fspP0DefaultedFromZero";
                }
                elsif( $attributeDef->{persistency} eq "volatile" )
                {
                    $section = "fspP0DefaultedFromP3";
                }
                elsif( !exists $attributeDef->{writeable}
                       && $attributeDef->{persistency} eq "non-volatile" )
                {
                    $section = "fspP3Ro";
                }
                elsif( exists $attributeDef->{writeable}
                       && $attributeDef->{persistency} eq "non-volatile" )
                {
                    $section = "fspP3Rw";
                }
                elsif( $attributeDef->{persistency} eq "semi-non-volatile-zeroed" )
                {
                    $section = "fspP1DefaultedFromZero";
                }
                elsif( $attributeDef->{persistency} eq "semi-non-volatile" )
                {
                    $section = "fspP1DefaultedFromP3";
                }
                else
                {
                    fatal("Persistency '$attributeDef->{persistency}' is not "
                          . "supported for fspOnly attribute '$attributeId'.");
                }
            }
            elsif( exists $attributeDef->{hbOnly} )
            {
                if( $attributeDef->{persistency} eq "volatile-zeroed" )
                {
                    $section = "hb-heap-zero-initialized";
                }
                else
                {
                    fatal("Persistency '$attributeDef->{persistency}' is not "
                          . "supported for hbOnly attribute '$attributeId'.");
                }
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
                fatal("Persistency '$attributeDef->{persistency}' is not "
                      . "supported for attribute '$attributeId'.");
            }

            if($section eq "pnor-ro")
            {
                if ((exists ${$Target_t}{$attributeId}) &&
                    ($attrhash{$attributeId}->{default} != 0))
                {
                    my $index = $attrhash{$attributeId}->{default} - 1;

                    # Each target is 4 bytes # attributes, 8 bytes pointer
                    # to attribute list, 8 bytes pointer to attribute pointer
                    # list, 4 x 8 byte pointers to association lists, for total
                    # of 20 + 32 = 52 bytes per target
                    $index *= (20 + 32); # length(N + quad + quad + 4x quad)
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
                my $hex = unpack ("H*",$rwdata);

                push @attrDataforSM, [$attrValue, $huidValue,
                    $hex, $section, $targetInstance->{id}, $attributeId];

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

                my $hex = unpack ("H*",$heapZeroInitData);
                push @attrDataforSM, [$attrValue, $huidValue,
                    $hex, $section, $targetInstance->{id}, $attributeId];

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

                my $hex = unpack ("H*",$heapPnorInitData);
                push @attrDataforSM, [$attrValue, $huidValue,
                    $hex, $section, $targetInstance->{id}, $attributeId];
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
            # Split FSP section into more granular sections
            elsif($section eq "fspP0DefaultedFromZero")
            {
                my ($fspP0ZeroData,$alignment) = packAttribute(
                        $attributes,
                        $attributeDef,$attrhash{$attributeId}->{default});

                if($ifFspOnlyTargetWithCommonAttr eq "true")
                {
                    my $hex = unpack ("H*",$fspP0ZeroData);
                    push @attrDataforSM, [$attrValue, $huidValue,
                         $hex, $section, $targetInstance->{id}, $attributeId];
                    $ifFspOnlyTargetWithCommonAttr = "false";
                }

                # Align the data as necessary
                my $pads = ($alignment - ($fspP0DefaultedFromZeroOffset
                            % $alignment)) % $alignment;
                $fspP0DefaultedFromZeroBinData .= pack ("@".$pads);
                $fspP0DefaultedFromZeroOffset += $pads;

                $attributePointerBinData .= pack8byte(
                    $fspP0DefaultedFromZeroOffset + $fspP0DefaultedFromZeroBaseAddr);

                $fspP0DefaultedFromZeroOffset += (length $fspP0ZeroData);

                $fspP0DefaultedFromZeroBinData .= $fspP0ZeroData;
            }
            elsif($section eq "fspP0DefaultedFromP3")
            {
                my ($fspP0FlashData,$alignment) = packAttribute(
                        $attributes,
                        $attributeDef,$attrhash{$attributeId}->{default});

                if($ifFspOnlyTargetWithCommonAttr eq "true")
                {
                    my $hex = unpack ("H*",$fspP0FlashData);
                    push @attrDataforSM, [$attrValue, $huidValue,
                         $hex, $section, $targetInstance->{id}, $attributeId];
                    $ifFspOnlyTargetWithCommonAttr = "false";
                }

                # Align the data as necessary
                my $pads = ($alignment - ($fspP0DefaultedFromP3Offset
                            % $alignment)) % $alignment;
                $fspP0DefaultedFromP3BinData .= pack ("@".$pads);
                $fspP0DefaultedFromP3Offset += $pads;

                $attributePointerBinData .= pack8byte(
                    $fspP0DefaultedFromP3Offset + $fspP0DefaultedFromP3BaseAddr);

                $fspP0DefaultedFromP3Offset += (length $fspP0FlashData);

                $fspP0DefaultedFromP3BinData .= $fspP0FlashData;
            }
            elsif($section eq "fspP3Ro")
            {
                my ($fspP3RoData,$alignment) = packAttribute(
                        $attributes,
                        $attributeDef,$attrhash{$attributeId}->{default});

                # Align the data as necessary
                my $pads = ($alignment - ($fspP3RoOffset
                            % $alignment)) % $alignment;
                $fspP3RoBinData .= pack ("@".$pads);
                $fspP3RoOffset += $pads;

                $attributePointerBinData .= pack8byte(
                    $fspP3RoOffset + $fspP3RoBaseAddr);

                $fspP3RoOffset += (length $fspP3RoData);

                $fspP3RoBinData .= $fspP3RoData;
            }
            elsif($section eq "fspP3Rw")
            {
                my ($fspP3RwData,$alignment) = packAttribute(
                        $attributes,
                        $attributeDef,$attrhash{$attributeId}->{default});

                my $hex = unpack ("H*",$fspP3RwData);

                push @attrDataforSM, [$attrValue, $huidValue,
                    $hex, $section, $targetInstance->{id}, $attributeId];

                # Align the data as necessary
                my $pads = ($alignment - ($fspP3RwOffset
                            % $alignment)) % $alignment;
                $fspP3RwBinData .= pack ("@".$pads);
                $fspP3RwOffset += $pads;

                $attributePointerBinData .= pack8byte(
                    $fspP3RwOffset + $fspP3RwBaseAddr);

                $fspP3RwOffset += (length $fspP3RwData);

                $fspP3RwBinData .= $fspP3RwData;
            }
            elsif($section eq "fspP1DefaultedFromZero")
            {
                my ($fspP1ZeroData,$alignment) = packAttribute(
                        $attributes,
                        $attributeDef,$attrhash{$attributeId}->{default});

                my $hex = unpack ("H*",$fspP1ZeroData);

                push @attrDataforSM, [$attrValue, $huidValue,
                    $hex, $section, $targetInstance->{id}, $attributeId];

                # Align the data as necessary
                my $pads = ($alignment - ($fspP1DefaultedFromZeroOffset
                            % $alignment)) % $alignment;
                $fspP1DefaultedFromZeroBinData .= pack ("@".$pads);
                $fspP1DefaultedFromZeroOffset += $pads;

                $attributePointerBinData .= pack8byte(
                    $fspP1DefaultedFromZeroOffset + $fspP1DefaultedFromZeroBaseAddr);

                $fspP1DefaultedFromZeroOffset += (length $fspP1ZeroData);

                $fspP1DefaultedFromZeroBinData .= $fspP1ZeroData;
            }
            elsif($section eq "fspP1DefaultedFromP3")
            {
                my ($fspP1FlashData,$alignment) = packAttribute(
                        $attributes,
                        $attributeDef,$attrhash{$attributeId}->{default});

                my $hex = unpack ("H*",$fspP1FlashData);

                push @attrDataforSM, [$attrValue, $huidValue,
                    $hex, $section, $targetInstance->{id}, $attributeId];

                # Align the data as necessary
                my $pads = ($alignment - ($fspP1DefaultedFromP3Offset
                            % $alignment)) % $alignment;
                $fspP1DefaultedFromP3BinData .= pack ("@".$pads);
                $fspP1DefaultedFromP3Offset += $pads;

                $attributePointerBinData .= pack8byte(
                    $fspP1DefaultedFromP3Offset + $fspP1DefaultedFromP3BaseAddr);

                $fspP1DefaultedFromP3Offset += (length $fspP1FlashData);

                $fspP1DefaultedFromP3BinData .= $fspP1FlashData;
            }
            # Hostboot specific section
            elsif($section eq "hb-heap-zero-initialized")
            {
                my ($hbHeapZeroInitData,$alignment) = packAttribute(
                        $attributes,
                        $attributeDef,$attrhash{$attributeId}->{default});

                # Align the data as necessary
                my $pads = ($alignment - ($hbHeapZeroInitOffset
                            % $alignment)) % $alignment;
                $hbHeapZeroInitBinData .= pack ("@".$pads);
                $hbHeapZeroInitOffset += $pads;

                $attributePointerBinData .= pack8byte(
                    $hbHeapZeroInitOffset + $hbHeapZeroInitBaseAddr);

                $hbHeapZeroInitOffset += (length $hbHeapZeroInitData);

                $hbHeapZeroInitBinData .= $hbHeapZeroInitData;
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

    # Build the parent/child relationships for all targets
    my %targetPhysicalPath = ();
    my %targetAffinityPath = ();
    foreach my $id (keys %targetAddrHash)
    {
        my $phys_attr = ATTR_PHYS_PATH;
        my $affn_attr = ATTR_AFFINITY_PATH;
        $targetPhysicalPath{ $targetAddrHash{$id}{$phys_attr} } =
            $id;
        $targetAffinityPath{ $targetAddrHash{$id}{$affn_attr} } =
            $id;
    }
    foreach my $id (keys %targetAddrHash)
    {
        my $phys_attr = ATTR_PHYS_PATH;
        my $affn_attr = ATTR_AFFINITY_PATH;

        my $phys_path = $targetAddrHash{$id}{$phys_attr};
        my $parent_phys_path = substr $phys_path, 0, (rindex $phys_path, "/");

        my $affn_path = $targetAddrHash{$id}{$affn_attr};
        my $parent_affn_path = substr $affn_path, 0, (rindex $affn_path, "/");

        if (defined $targetPhysicalPath{$parent_phys_path})
        {
            my $parent = $targetPhysicalPath{$parent_phys_path};
            unshift
                @ { $targetAddrHash{$id}
                    {ParentByContainmentAssociations} },
                $firstTgtPtr + $targetAddrHash{$parent}
            {OffsetToTargetWithinTargetList};

            unshift
                @ { $targetAddrHash{$parent}
                    {ChildByContainmentAssociations} },
                $firstTgtPtr + $targetAddrHash{$id}
            {OffsetToTargetWithinTargetList};

        }
        if (defined $targetAffinityPath{$parent_affn_path})
        {
            my $parent = $targetAffinityPath{$parent_affn_path};
            unshift
                @ { $targetAddrHash{$id}
                    {ParentByAffinityAssociations} },
                $firstTgtPtr + $targetAddrHash{$parent}
            {OffsetToTargetWithinTargetList};

            unshift
                @ { $targetAddrHash{$parent}
                    {ChildByAffinityAssociations} },
                $firstTgtPtr + $targetAddrHash{$id}
            {OffsetToTargetWithinTargetList};
        }
    }

    # Serialize the association lists into a blob
    my $associationsBinData;
    my $offsetToAssociationsFromTargets =
        (length $targetsBinData) + (length $roAttrBinData);
    serializeAssociations( $firstTgtPtr + $offsetToAssociationsFromTargets,
        \@targetsAoH, \%targetAddrHash, \$associationsBinData);
    my $associationsBinDataSize = length $associationsBinData;
    ASSOC_IMP("Size of association section, redundant calculation "
              . "= $associationsBinDataSize");

    # Fix up the target bin blob to point to the right association lists
    updateTargetAssociationPointers(\%targetAddrHash, \$targetsBinData);

    # Size of PNOR RO increases by size of associations
    $offset += $associationsBinDataSize;

    # Build header data

    my $headerBinData;
    my $blockSize = 4*1024;

    my %sectionHoH = ();

    my $roOffset = 0;
    if ($addRO_Section_VerPage == 1)
    {
        #First section to start after 4096 bytes
        #as RO version data occupies first page in the binary file
        $roOffset = $versionSectionSize;
    }

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

    # zeroInitSection occupies no space in the binary, so set the
    # Hostboot section address to that of the zeroInitSection
    $sectionHoH{ hbHeapZeroInit }{ offset } =
        $sectionHoH{heapZeroInit}{ offset };
    $sectionHoH{ hbHeapZeroInit }{ type } = 10;
    $sectionHoH{ hbHeapZeroInit }{ size } =
        sizeBlockAligned($hbHeapZeroInitOffset,$blockSize,1);

    # Split "fsp" into additional sections
    if($cfgIncludeFspAttributes)
    {
        # zeroInitSection occupies no space in the binary, so set the FSP
        # section address to that of the zeroInitSection
        $sectionHoH{ fspP0DefaultedFromZero }{ offset } =
             $sectionHoH{heapZeroInit}{offset};
        $sectionHoH{ fspP0DefaultedFromZero }{ type } = 4;
        $sectionHoH{ fspP0DefaultedFromZero }{ size } =
            sizeBlockAligned($fspP0DefaultedFromZeroOffset,$blockSize,1);

        $sectionHoH{ fspP0DefaultedFromP3 }{ offset } =
             $sectionHoH{fspP0DefaultedFromZero}{offset} +
             $sectionHoH{fspP0DefaultedFromZero}{size};
        $sectionHoH{ fspP0DefaultedFromP3 }{ type } = 5;
        $sectionHoH{ fspP0DefaultedFromP3 }{ size } =
            sizeBlockAligned($fspP0DefaultedFromP3Offset,$blockSize,1);

        $sectionHoH{ fspP3Ro }{ offset } =
             $sectionHoH{fspP0DefaultedFromP3}{offset} +
             $sectionHoH{fspP0DefaultedFromP3}{size};
        $sectionHoH{ fspP3Ro }{ type } = 6;
        $sectionHoH{ fspP3Ro }{ size } =
            sizeBlockAligned($fspP3RoOffset,$blockSize,1);

        $sectionHoH{ fspP3Rw }{ offset } =
             $sectionHoH{fspP3Ro}{offset} + $sectionHoH{fspP3Ro}{size};
        $sectionHoH{ fspP3Rw }{ type } = 7;
        $sectionHoH{ fspP3Rw }{ size } =
            sizeBlockAligned($fspP3RwOffset,$blockSize,1);

        $sectionHoH{ fspP1DefaultedFromZero }{ offset } =
             $sectionHoH{fspP3Rw}{offset} + $sectionHoH{fspP3Rw}{size};
        $sectionHoH{ fspP1DefaultedFromZero }{ type } = 8;
        $sectionHoH{ fspP1DefaultedFromZero }{ size } =
            sizeBlockAligned($fspP1DefaultedFromZeroOffset,$blockSize,1);

        $sectionHoH{ fspP1DefaultedFromP3 }{ offset } =
             $sectionHoH{fspP1DefaultedFromZero}{offset} +
             $sectionHoH{fspP1DefaultedFromZero}{size};
        $sectionHoH{ fspP1DefaultedFromP3 }{ type } = 9;
        $sectionHoH{ fspP1DefaultedFromP3 }{ size } =
            sizeBlockAligned($fspP1DefaultedFromP3Offset,$blockSize,1);
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

    # Split "fsp" into additional sections
    my @sections = ("pnorRo","pnorRw","heapPnorInit","heapZeroInit", "hbHeapZeroInit");
    if($cfgIncludeFspAttributes)
    {
        push(@sections,"fspP0DefaultedFromZero");
        push(@sections,"fspP0DefaultedFromP3");
        push(@sections,"fspP3Ro");
        push(@sections,"fspP3Rw");
        push(@sections,"fspP1DefaultedFromZero");
        push(@sections,"fspP1DefaultedFromP3");
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

    #HB Targeting binary file will contain <Version Page>+<Targeting Header>+
    #<Section  data>...
    if ($addRO_Section_VerPage == 1)
    {
        #Generate the MD5 checksum value for the read-only data and update the
        #content of the version section
        my $versionHeader = "VERSION";
        $versionHeader .= md5_hex($roAttrBinData);

        $outFile .= $versionHeader;
        my $versionHeaderPadSize =
            (sizeBlockAligned ((length $versionHeader),$versionSectionSize,1)
             - (length $versionHeader));
        $outFile .= pack ("@".$versionHeaderPadSize);
    }

    #Append the 256 bytes header data
    $outFile .= $headerBinData;
    my $padSize = sizeBlockAligned((length $headerBinData),$headerSize,1)
        - (length $headerBinData);
    $outFile .= pack ("@".$padSize);

    # Remaining data belongs to targeting
    $outFile .= $numTargetsPointerBinData;
    $outFile .= $attributeListBinData;
    $outFile .= $attributePointerBinData;
    $outFile .= $numTargetsBinData;

    my $offsetOfTargets = length $outFile;
    my $sizeOfTargets = length $targetsBinData;
    my $offsetToAssociationsFromTargets =
        (length $targetsBinData) + (length $roAttrBinData);
    ASSOC_DBG("Offset of targets within targeting binary = $offsetOfTargets");
    ASSOC_DBG("Size of targets within targeting binary = $sizeOfTargets");
    ASSOC_DBG("Offset to associations from start of targets "
              . "= $offsetToAssociationsFromTargets");

    $outFile .= $targetsBinData;
    $outFile .= $roAttrBinData;

    $outFile .= $associationsBinData;

    $outFile .= pack ("@".($sectionHoH{pnorRo}{size} - $offset));

    # Serialize PNOR RW section to multiple of 4k page size (pad if necessary)
    $outFile .= $rwAttrBinData;
    $outFile .= pack("@".($sectionHoH{pnorRw}{size} - $rwOffset));

    # Serialize PNOR initiated heap section to multiple of 4k page size (pad if
    # necessary)
    $outFile .= $heapPnorInitBinData;
    $outFile .= pack("@".($sectionHoH{heapPnorInit}{size}
        - $heapPnorInitOffset));

    # Serialize FSP section to multiple of 4k page size (pad if
    # necessary)
    if($cfgIncludeFspAttributes)
    {
        $outFile .= $fspP0DefaultedFromZeroBinData;
        $outFile .= pack("@".($sectionHoH{fspP0DefaultedFromZero}{size}
            - $fspP0DefaultedFromZeroOffset));

        $outFile .= $fspP0DefaultedFromP3BinData;
        $outFile .= pack("@".($sectionHoH{fspP0DefaultedFromP3}{size}
            - $fspP0DefaultedFromP3Offset));

        $outFile .= $fspP3RoBinData;
        $outFile .= pack("@".($sectionHoH{fspP3Ro}{size}
            - $fspP3RoOffset));

        $outFile .= $fspP3RwBinData;
        $outFile .= pack("@".($sectionHoH{fspP3Rw}{size}
            - $fspP3RwOffset));

        $outFile .= $fspP1DefaultedFromZeroBinData;
        $outFile .= pack("@".($sectionHoH{fspP1DefaultedFromZero}{size}
            - $fspP1DefaultedFromZeroOffset));

        $outFile .= $fspP1DefaultedFromP3BinData;
        $outFile .= pack("@".($sectionHoH{fspP1DefaultedFromP3}{size}
            - $fspP1DefaultedFromP3Offset));
    }

    return $outFile;
}

sub generateXMLforSM {

    open(SM_TARGET_FILE,">".$CfgSMAttrFile)
        or fatal ("Targeting SM file: $CfgSMAttrFile "
            . "could not be opened.");
    my $Count = @attrDataforSM;

print SM_TARGET_FILE "
<attributes>";
    for (my $i = 0; $i < $Count; $i++)
    {
        print SM_TARGET_FILE "
<attribute>
    <id>0x$attrDataforSM[$i][ATTRID]</id>
    <HUID>$attrDataforSM[$i][HUID]</HUID>
    <value>0x$attrDataforSM[$i][DATA]</value>
    <section>$attrDataforSM[$i][SECTION]</section>
    <target>$attrDataforSM[$i][TARGET]</target>
    <name>$attrDataforSM[$i][ATTRNAME]</name>";
print SM_TARGET_FILE "\n</attribute>\n";

    }
print SM_TARGET_FILE"
</attributes>";

    close(SM_TARGET_FILE);
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

=item B<--smattr-output-file>=FILE

Indicates the file to dump hex representation of attributes that are synced
between system model and targeting.  Only used by FSP.

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

=item B<--version-page>
Adds 4096 bytes of version page as first page in the generated binaries.

=item B<--no-version-page>
Does not add 4096 bytes of version page as first page in the generated
binaries . This is the default behavior.

=item B<--verbose>

Prints out some internal workings

=back

=head1 DESCRIPTION

B<xmltohb.pl> will process a set of input .xml files and emit source files and
a PNOR targeting image binary to facilitate compiling and configuring host boot
respectively.

=cut


