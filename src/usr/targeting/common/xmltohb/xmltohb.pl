#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/common/xmltohb/xmltohb.pl $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2012,2022
# [+] International Business Machines Corp.
# [+] YADRO
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
#   Process the attribute xml files, generate code, create binaries, etc
#
# Change Log **********************************************************
#
# End Change Log ******************************************************

use strict;

################################################################################
# Use of the following packages
################################################################################

use Carp;
use Getopt::Long;
use Pod::Usage;
use XML::Simple;
use Text::Wrap;
use Data::Dumper;
use POSIX;
use Env;
use XML::LibXML;
use Scalar::Util qw(looks_like_number);


# Provides object deep copy capability to support virtual
# attribute removal
use Storable 'dclone';

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
my $nonSyncAttribFile = "";

my $cfgBiosXmlFile = undef;
my $cfgBiosSchemaFile = undef;
my $cfgBiosOutputFile = undef;

my $MAX_4_BYTE_VALUE = 0xFFFFFFFF;

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
           "bios-xml-file:s" => \$cfgBiosXmlFile,
           "bios-schema-file:s" => \$cfgBiosSchemaFile,
           "bios-output-file:s" => \$cfgBiosOutputFile,
           "non-sync-attrib-file:s" => \$nonSyncAttribFile,
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
    print STDOUT "bios-schema-file = $cfgBiosSchemaFile\n";
    print STDOUT "bios-xml-file = $cfgBiosXmlFile\n";
    print STDOUT "bios-output-file = $cfgBiosOutputFile\n";
    print STDOUT "Non Sync Attributes file = $nonSyncAttribFile\n";
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
use constant PERVASIVE_CHILD => "PervasiveChild";
use constant PARENT_PERVASIVE => "ParentPervasive";
use constant OMIC_PARENT => "OmicParent";
use constant OMI_CHILD => "OmiChild";
use constant PAUC_CHILD => "PaucChild";
use constant PAUC_PARENT => "PaucParent";
my @associationTypes = ( PARENT_BY_CONTAINMENT,
    CHILD_BY_CONTAINMENT, PARENT_BY_AFFINITY, CHILD_BY_AFFINITY,
    PERVASIVE_CHILD, PARENT_PERVASIVE, OMIC_PARENT, OMI_CHILD, PAUC_CHILD,
    PAUC_PARENT );

# Constants for attribute names (minus ATTR_ prefix)
use constant ATTR_OMIC_PARENT => "OMIC_PARENT";
use constant ATTR_PAUC_PARENT => "PAUC_PARENT";
use constant ATTR_PARENT_PERVASIVE => "PARENT_PERVASIVE";
use constant ATTR_PHYS_PATH => "PHYS_PATH";
use constant ATTR_AFFINITY_PATH => "AFFINITY_PATH";
use constant ATTR_UNKNOWN => "UnknownAttributeName";
use constant ATTR_POSITION => "POSITION";
use constant ATTR_CHIP_UNIT => "CHIP_UNIT";
use constant ATTR_CLASS => "CLASS";
use constant ATTR_TYPE => "TYPE";
use constant ATTR_MODEL => "MODEL";

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

# These constants describe the persistencies of different targeting attributes.
# NOTE: keep this list in sync with the data that gets written out in writeHeaderFormatHeaderFile!
use constant
{
    SECTION_TYPE_PNOR_RO => 0,
    SECTION_TYPE_PNOR_RW => 1,
    SECTION_TYPE_HEAP_PNOR_INIT => 2,
    SECTION_TYPE_HEAP_ZERO_INIT => 3,
    SECTION_TYPE_FSP_P0_ZERO_INIT => 4,
    SECTION_TYPE_FSP_P0_FLASH_INIT => 5,
    SECTION_TYPE_FSP_P3_RO => 6,
    SECTION_TYPE_FSP_P3_RW => 7,
    SECTION_TYPE_FSP_P1_ZERO_INIT => 8,
    SECTION_TYPE_FSP_P1_FLASH_INIT => 9,
    SECTION_TYPE_HB_HEAP_ZERO_INIT => 0xa,
    SECTION_TYPE_HB_METADATA => 0xb,
    SECTION_TYPE_BAD_VALUE => 255
};

my $xml = new XML::Simple (KeyAttr=>[]);
use Digest::MD5 qw(md5_hex);

# Until full machine parseable workbook parsing splits out all the input files,
# use the intermediate representation containing the full host boot model.
# Aborts application if file name not found.
# NOTE: the attribute list initially contains both real and virtual attributes
my $allAttributes = $xml->XMLin($cfgHbXmlFile,
    forcearray => ['enumerationType','enumerator','attribute','hwpfToHbAttrMap',
                   'compileAttribute','range']);


my $fapiAttributes = {};
if ($cfgFapiAttributesXmlFile ne "")
{
    $fapiAttributes = $xml->XMLin($cfgFapiAttributesXmlFile,
        forcearray => ['attribute']);
}

my @nonSyncAttributes = {};
my @fspAccesCheck = {};
if ($nonSyncAttribFile ne "")
{
    my $nsa = $xml->XMLin($nonSyncAttribFile, ForceArray=>['attribute']);
    foreach my $attr (@{$nsa->{attribute}})
    {
        my $attrName = $attr->{id};
        if (!defined($attr->{fspaccess_nosync}))
        {
            push(@fspAccesCheck, $attrName);
        }
        push(@nonSyncAttributes, $attrName);
    }
}

# save attributes defined as Target_t type
my %Target_t = ();

# Perform some sanity validation of the model (so we don't have to later)
# Subject virtual attributes to same sanity checks
validateAttributes($allAttributes);
validateTargetInstances($allAttributes);
validateTargetTypes($allAttributes);
validateTargetTypesExtension($allAttributes);

# Clone the attributes and strip out any references to virtual
# attributes, then continue forward using the result as the typical
# working attribute set.  The original set containing virtual attributes
# will be used for very specific tasks, like computing associations
my $attributes = dclone $allAttributes;
my %virtualAttrIds = ();
for my $attr (reverse 0..((scalar @{$attributes->{attribute}})-1) )
{
    if(exists $attributes->{attribute}[$attr]->{virtual})
    {
        # Found a virtual attribute; note it and remove
        $virtualAttrIds{$attributes->{attribute}[$attr]->{id}} = 1;
        splice @{$attributes->{attribute}}, $attr, 1;
    }
}

foreach my $targetType (@{$attributes->{targetType}})
{
    if(exists $targetType->{attribute})
    {
        for my $attr (reverse 0..((scalar
            @{$targetType->{attribute}})-1))
        {
            my $currentAttr = $targetType->{attribute}[$attr];
            if(   exists $currentAttr->{id}
               && exists $virtualAttrIds{$currentAttr->{id}} )
            {
                # A targetType refers to the virtual attribute
                # so remove it
                splice @{$targetType->{attribute}}, $attr, 1;
            }
        }
    }
}

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
    # secureboot validation of RW persistent attributes
    generateRWPersistValidations($cfgSrcOutputDir, $attributes);

    open(ATTR_TARG_MAP_FILE,">$cfgSrcOutputDir"."targAttrOverrideData.H")
      or croak("Target Attribute data file: \"$cfgSrcOutputDir"
        . "targAttrOverrideData.H\" could not be opened.");
    my $targAttrFile = *ATTR_TARG_MAP_FILE;
    writeTargAttrMap($attributes, $targAttrFile);
    close $targAttrFile;

    open(ATTR_ID_MAP_FILE,">$cfgSrcOutputDir"."targAttrIdToName.H")
      or croak("Target Attribute ID to Name map file: \"$cfgSrcOutputDir"
        . "targAttrIdToName.H\" could not be opened.");
    my $targAttrIdNameFile = *ATTR_ID_MAP_FILE;
    writeAttrIdNameFileHeader($targAttrIdNameFile);
    writeAttrIdNameMap($attributes, $targAttrIdNameFile, 1); # RW-only attr map
    writeAttrIdNameMap($attributes, $targAttrIdNameFile, 0); # All attr map
    close $targAttrIdNameFile;

    open(MUTEX_ATTR_FILE, ">$cfgSrcOutputDir"."mutexattributes.H")
      or croak ("Mutex Attribute file: \"$cfgSrcOutputDir"
        . "mutexattributes.H\" could not be opened.");
    my $mutexFile = *MUTEX_ATTR_FILE;
    writeMutexFileHeader($mutexFile);
    writeMutexFileAttrs($attributes,$mutexFile);
    writeMutexFileFooter($mutexFile);
    close $mutexFile;


    open(TRAIT_FILE,">$cfgSrcOutputDir"."attributetraits.H")
      or croak ("Trait file: \"$cfgSrcOutputDir"
        . "attributetraits.H\" could not be opened.");
    my $traitFile = *TRAIT_FILE;
    writeTraitFileHeader($attributes,$traitFile);
    writeTraitFileTraits($attributes,$traitFile);
    writeTraitFileFooter($traitFile);
    close $traitFile;

    open(ATTR_FILE,">$cfgSrcOutputDir"."attributeenums.H")
      or croak ("Attribute enum file: \"$cfgSrcOutputDir"
        . "attributeenums.H\" could not be opened.");
    my $enumFile = *ATTR_FILE;
    writeEnumFileHeader($enumFile);
    writeEnumFileAttrIdEnum($attributes,$enumFile);
    writeEnumFileAttrEnums($attributes,$enumFile);
    writeEnumFileFooter($enumFile);
    close $enumFile;

    open(STRING_HEADER_FILE,">$cfgSrcOutputDir"."attributestrings.H")
      or croak ("Attribute string header file: \"$cfgSrcOutputDir"
        . "attributestrings.H\" could not be opened.");
    my $stringHeaderFile = *STRING_HEADER_FILE;
    writeStringHeaderFileHeader($stringHeaderFile);
    writeStringHeaderFileStrings($attributes,$stringHeaderFile);
    writeStringHeaderFileFooter($stringHeaderFile);
    close $stringHeaderFile;

    open(STRING_IMPLEMENTATION_FILE,">$cfgSrcOutputDir"."attributestrings.C")
      or croak ("Attribute string source file: \"$cfgSrcOutputDir"
        . "attributestrings.C\" could not be opened.");
    my $stringImplementationFile = *STRING_IMPLEMENTATION_FILE;
    writeStringImplementationFileHeader($stringImplementationFile);
    writeStringImplementationFileStrings($attributes,$stringImplementationFile);
    writeStringImplementationFileFooter($stringImplementationFile);
    writeTestEntityPath($attributes);
    close $stringImplementationFile;

    open(STRUCTS_HEADER_FILE,">$cfgSrcOutputDir"."attributestructs.H")
      or croak ("Attribute struct file: \"$cfgSrcOutputDir"
        . "attributestructs.H\" could not be opened.");
    my $structFile = *STRUCTS_HEADER_FILE;
    writeStructFileHeader($structFile);
    writeStructFileStructs($attributes,$structFile);
    writeStructFileFooter($structFile);
    close $structFile;

    open(PNOR_HEADER_DEF_FILE,">$cfgSrcOutputDir"."pnortargeting.H")
      or croak ("Targeting header definition header file: \"$cfgSrcOutputDir"
        . "pnortargeting.H\" could not be opened.");
    my $pnorHeaderDefFile = *PNOR_HEADER_DEF_FILE;
    writeHeaderFormatHeaderFile($pnorHeaderDefFile);
    close $pnorHeaderDefFile;

    open(FAPI2_PLAT_ATTR_MACROS_FILE,">$cfgSrcOutputDir"."fapi2platattrmacros.H")
      or croak ("FAPI2 platform attribute macro header file: \"$cfgSrcOutputDir"
        . "fapi2platattrmacros.H\" could not be opened.");
    my $fapi2PlatAttrMacrosHeaderFile = *FAPI2_PLAT_ATTR_MACROS_FILE;
    writeFapi2PlatAttrMacrosHeaderFileHeader ($fapi2PlatAttrMacrosHeaderFile);
    writeFapi2PlatAttrMacrosHeaderFileContent($attributes,$fapiAttributes,
        $fapi2PlatAttrMacrosHeaderFile);
    writeFapi2PlatAttrMacrosHeaderFileFooter ($fapi2PlatAttrMacrosHeaderFile);
    close $fapi2PlatAttrMacrosHeaderFile;

    open(ATTR_ATTRERRL_C_FILE,">$cfgSrcOutputDir"."errludattribute_gen.C")
      or croak ("Attribute errlog C file: \"$cfgSrcOutputDir"
        . "errludattribute_gen.C\" could not be opened.");
    my $attrErrlCFile = *ATTR_ATTRERRL_C_FILE;
    writeAttrErrlCFile($attributes,$attrErrlCFile);
    close $attrErrlCFile;

    mkdir("$cfgSrcOutputDir/errl");
    open(ATTR_ATTRERRL_H_FILE,">$cfgSrcOutputDir"."errl/errludattributeP_gen.H")
      or croak ("Attribute errlog H file: \"$cfgSrcOutputDir"
        . "errl/errludattributeP_gen.H\" could not be opened.");
    my $attrErrlHFile = *ATTR_ATTRERRL_H_FILE;

    open(ATTR_ATTRERRL_PY_FILE,">$cfgSrcOutputDir"."errl/errludattributeP_gen.py")
    or croak ("Attribute errlog PY file: \"$cfgSrcOutputDir"
        . "errl/errludattributeP_gen.py\" could not be opened.");
    my $attrErrlPYFile = *ATTR_ATTRERRL_PY_FILE;

    writeAttrErrlHFile($attributes,$attrErrlHFile,$attrErrlPYFile);
    close $attrErrlHFile;

    open(ATTR_TARGETERRL_C_FILE,">$cfgSrcOutputDir"."errludtarget.C")
      or croak ("Target errlog C file: \"$cfgSrcOutputDir"
        . "errludtarget.C\" could not be opened.");
    my $targetErrlCFile = *ATTR_TARGETERRL_C_FILE;
    writeTargetErrlCFile($attributes,$targetErrlCFile);
    close $targetErrlCFile;

    open(ATTR_TARGETERRL_H_FILE,">$cfgSrcOutputDir"."errl/errludtarget.H")
      or croak ("Target errlog H file: \"$cfgSrcOutputDir"
        . "errl/errludtarget.H\" could not be opened.");
    my $targetErrlHFile = *ATTR_TARGETERRL_H_FILE;
    open(ATTR_ENTITYPATH_PY_FILE,">$cfgSrcOutputDir"."errl/entityPath.py")
      or croak ("Target errlog Python file: \"$cfgSrcOutputDir"
        . "errl/entityPath.py\" could not be opened.");
    my $entityPathPYFile = *ATTR_ENTITYPATH_PY_FILE;
    open(ATTR_TARGETERRL_PY_FILE,">$cfgSrcOutputDir"."errl/errludtarget.py")
      or croak ("Target errlog Python file: \"$cfgSrcOutputDir"
        . "errl/errludtarget.py\" could not be opened.");
    my $targetErrlPYFile = *ATTR_TARGETERRL_PY_FILE;
    writeTargetErrlHFile($attributes,$targetErrlHFile,$entityPathPYFile,$targetErrlPYFile);
    close $targetErrlHFile;

    open(ATTR_INFO_CSV_FILE,">$cfgSrcOutputDir"."targAttrInfo.csv")
      or croak ("Attribute info csv file: \"$cfgSrcOutputDir"
        . "targAttrInfo.csv\" could not be opened.");
    my $attrInfoCsvFile = *ATTR_INFO_CSV_FILE;
    writeAttrInfoCsvFile($attributes,$attrInfoCsvFile);
    close $attrInfoCsvFile;

    open(MAP_ATTR_METADATA_H_FILE,">$cfgSrcOutputDir"."mapattrmetadata.H")
      or croak ("Attribute metadata map file Header: \"$cfgSrcOutputDir"
        . "mapattrmetadata.H\" could not be opened.");
    my $attrMetadataMapHFile = *MAP_ATTR_METADATA_H_FILE;
    writeAttrMetadataMapHFile($attrMetadataMapHFile);
    close $attrMetadataMapHFile;

    open(MAP_ATTR_METADATA_C_FILE,">$cfgSrcOutputDir"."mapattrmetadata.C")
      or croak ("Attribute metadata map C file: \"$cfgSrcOutputDir"
        . "mapattrmetadata.C\" could not be opened.");
    my $attrMetadataMapCFile = *MAP_ATTR_METADATA_C_FILE;
    writeAttrMetadataMapCFileHeader($attrMetadataMapCFile);
    writeAttrMetadataMapCFile($attributes,$attrMetadataMapCFile);
    writeAttrMetadataMapCFileFooter($attrMetadataMapCFile);
    close $attrMetadataMapCFile;

    open(MAP_ATTR_SIZE_H_FILE,">$cfgSrcOutputDir"."mapsystemattrsize.H")
      or croak ("Attribute size map file Header: \"$cfgSrcOutputDir"
        . "mapsystemattrsize.H\" could not be opened.");
    my $attrSizeMapHFile = *MAP_ATTR_SIZE_H_FILE;
    writeAttrSizeMapHFile($attrSizeMapHFile);
    close $attrSizeMapHFile;

    open(MAP_ATTR_SIZE_C_FILE,">$cfgSrcOutputDir"."mapsystemattrsize.C")
      or croak ("Attribute size map file: \"$cfgSrcOutputDir"
        . "mapsystemattrsize.C\" could not be opened.");
    my $attrSizeMapCFile = *MAP_ATTR_SIZE_C_FILE;
    writeAttrSizeMapCFileHeader($attrSizeMapCFile);
    writeAttrSizeMapCFile($attributes,$attrSizeMapCFile);
    writeAttrSizeMapCFileFooter($attrSizeMapCFile);
    close $attrSizeMapCFile;

    open(ATTR_SIZES_H_FILE, ">$cfgSrcOutputDir"."attrsizesdata.H")
      or croak ("Attribute size file: \"$cfgSrcOutputDir"
        . "attrsizesdata.H\" could not be opened.");
    my $attrSizesDataFile = *ATTR_SIZES_H_FILE;
    writeAttrSizesFileHeader($attrSizesDataFile);
    writeAttrSizesFileBody($attributes, $attrSizesDataFile);
    writeAttrSizesFileFooter($attrSizesDataFile);
    close $attrSizesDataFile;
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
    #--version-page
    if ($cfgAddVersionPage)
    {
        $addRO_Section_VerPage = 1;
    }

    # Different portions of the targeting data split up.
    my $combinedData;
    my $protectedData;
    my $unprotectedData;

    #Pass the $addRO_Section_VerPage into the sub rotuine
    generateTargetingImage($cfgVmmConstsFile,$attributes,\%Target_t,
                           $addRO_Section_VerPage,$allAttributes,
                           \$combinedData,
                           \$protectedData,
                           \$unprotectedData);

    # Generate combined targeting file
    open(PNOR_TARGETING_FILE,">$cfgImgOutputDir".$cfgImgOutputFile)
      or croak ("Targeting image file: \"$cfgImgOutputDir"
        . "$cfgImgOutputFile\" could not be opened.");
    binmode(PNOR_TARGETING_FILE);
    print PNOR_TARGETING_FILE "$combinedData";
    close(PNOR_TARGETING_FILE);

    # Generate protected payload file
    open(PNOR_TARGETING_FILE,">$cfgImgOutputDir"."$cfgImgOutputFile.protected")
      or fatal ("Targeting image file: \"$cfgImgOutputDir"
        . "$cfgImgOutputFile.protected\" could not be opened.");
    binmode(PNOR_TARGETING_FILE);
    print PNOR_TARGETING_FILE "$protectedData";
    close(PNOR_TARGETING_FILE);

    # Generate unprotected payload file
    open(PNOR_TARGETING_FILE,
         ">$cfgImgOutputDir"."$cfgImgOutputFile.unprotected")
      or fatal ("Targeting image file: \"$cfgImgOutputDir"
        . "$cfgImgOutputFile.unprotected\" could not be opened.");
    binmode(PNOR_TARGETING_FILE);
    print PNOR_TARGETING_FILE "$unprotectedData";
    close(PNOR_TARGETING_FILE);

    if ($CfgSMAttrFile ne "")
    {
        generateXMLforSM();
    }

}

exit(0);

# sub generateRWPersistValidations
# Generates code to validate the values of persistent read/write attributes
# @param[in] rwAttrOutputDir - The directory to place the output files
# @param[in] attributes - The list of attributes to generate code from
# @return none
sub generateRWPersistValidations {

#intentionally not indenting the top level of this function for readability
my ($rwAttrOutputDir, $attributes) = @_;

# Begin secure boot verification codegen for R/W persistent attributes
# Set up csv output file R/W persistent attributes
open(my $rwAttrFile, ">$rwAttrOutputDir"."PersistRwAttrList.csv")
      or croak("R/W data file 'PersistRwAttrList.csv' could not be opened.");

print $rwAttrFile <<VERBATIM;
# PersistRwAttrList.csv
# This file is generated by perl script xmltohb.pl
# It lists all non-volatile read/write attributes that persist in PNOR
# and can be manipulated at will.
VERBATIM

my @rwPersistAttrs; # store the persistent attributes in an array
my %attrEnumTypes; # store enum types in a hash table

foreach my $attrs (@{$attributes->{attribute}})
{
    if (exists $attrs->{readable} &&
        exists $attrs->{writeable} &&
        exists $attrs->{persistency} &&
        $attrs->{persistency} eq "non-volatile")
    {
        print $rwAttrFile "$attrs->{id}\n";
        push @rwPersistAttrs, $attrs;

        # do a little bit of validation for the range tag
        if (exists $attrs->{range})
        {
            if (!exists $attrs->{simpleType})
            {
                die "Attribute $attrs->{id} must be simpleType to use range tag.";
            }
            elsif (exists $attrs->{simpleType}->{enumeration})
            {
                die "Enumeration and range tags cannot coexist. See $attrs->{id}";
            }
        }
    }
}

foreach my $atype (@{$attributes->{enumerationType}})
{
    $attrEnumTypes{$atype->{id}}=$atype;
}

close $rwAttrFile;

# Set up header/cpp output file for secure boot verification codegen
open(my $rwAttrHFile, ">$rwAttrOutputDir"."persistrwattrcheck.H")
      or croak("R/W H gen file 'persistrwattrcheck.H' could not be opened.");

open(my $rwAttrCFile, ">$rwAttrOutputDir"."persistrwattrcheck.C")
      or croak("R/W C gen file 'persistrwattrcheck.C' could not be opened.");

print $rwAttrHFile <<VERBATIM;
/**
 *  \@file persistrwattrcheck.H
 *
 *  \@brief Verify enum attribute values are correct.
 */

#ifndef PERSISTRWATTRCHECK_H
#define PERSISTRWATTRCHECK_H

VERBATIM

print $rwAttrCFile <<VERBATIM;
/**
 *  \@file persistrwattrcheck.C
 *
 *  \@brief Verify enum attribute values are correct.
 */

#include <targeting/common/target.H>

namespace TARGETING
{

#ifndef __HOSTBOOT_RUNTIME

VERBATIM

foreach my $attr (@rwPersistAttrs)
{
    if (exists $attr->{simpleType} &&
        exists $attr->{simpleType}->{enumeration})
    {
        my $typeId = $attr->{simpleType}->{enumeration}->{id};
        if (!exists $attrEnumTypes{$typeId})
        {
            die "Attribute $attr->{id} is nonexistent enumerated type $typeId";
        }
        my $atype = $attrEnumTypes{$typeId};

        # forward declare in header file
        print $rwAttrHFile "template<>\n"
        . "bool Target::tryGetAttr<ATTR_$attr->{id}>("
        . "typename AttributeTraits<ATTR_$attr->{id}>::Type& o_attrValue)"
        . " const;\n\n";

        # implement in C file
        print $rwAttrCFile "template<>\n"
        . "bool Target::tryGetAttr<ATTR_$attr->{id}>("
        . "typename AttributeTraits<ATTR_$attr->{id}>::Type& o_attrValue)"
        . " const\n"
        . "{\n"
        . "    bool l_read = _tryGetAttrUnsafe(ATTR_$attr->{id},"
        .          "sizeof(o_attrValue),&o_attrValue);\n"
        . "    if (l_read)\n"
        . "    {\n";
        my $arrayPrefix = "";
        my $arraySuffix = "";
        my $isArrayType = exists $attr->{simpleType}->{array};
        if ($isArrayType)
        {
            my $arrayTag = "$attr->{simpleType}->{array}";
            my $arraySize = getArrayTagTotalSize($arrayTag);
            my $numDimensions = getArrayNumDimensions($arrayTag);
            $arraySuffix = "[i]";

            for (my $i=0; $i < $numDimensions - 1; $i++)
            {
                $arrayPrefix =  "$arrayPrefix*";
            }

            print $rwAttrCFile ""
            . "        for(int i=0; i<$arraySize; i++)\n"
            . "        {\n"
            . "            switch( (${arrayPrefix}o_attrValue)[i] )\n"
            . "            {\n";
        }
        else
        {
            print $rwAttrCFile ""
            . "        switch( o_attrValue )\n"
            . "        {\n";
        }
        foreach my $enumerations (@{$atype->{enumerator}})
        {
            print $rwAttrCFile ""
            . "            case $atype->{id}_$enumerations->{name}:\n";
        }
        print $rwAttrCFile "            case $atype->{id}_INVALID:\n";
        print $rwAttrCFile "                break;\n"
        . "            default:\n"
        . "                handleEnumCheckFailure(this, ATTR_$attr->{id}, "
        .                      "(${arrayPrefix}o_attrValue)$arraySuffix);\n";
        if ($isArrayType)
        {
            printf $rwAttrCFile ""
            . "            }\n";
        }
        printf $rwAttrCFile ""
        . "        }\n"
        . "    }\n"
        . "    return l_read;\n"
        . "}\n\n";
    }
}
print $rwAttrCFile "#endif // !__HOSTBOOT_RUNTIME\n";

print $rwAttrCFile <<VERBATIM;

bool Target::_tryGetAttr(ATTRIBUTE_ID i_attr, uint32_t i_size,
                                                       void* io_attrData) const
{
    #ifndef __HOSTBOOT_RUNTIME
    switch(i_attr)
    {
VERBATIM
foreach my $attr (@rwPersistAttrs)
{
    if (exists $attr->{simpleType} &&
        exists $attr->{simpleType}->{enumeration})
    {
        print $rwAttrCFile <<VERBATIM;
        case (ATTR_$attr->{id}):
            return tryGetAttr<ATTR_$attr->{id}>(
                * reinterpret_cast<
                    typename AttributeTraits<ATTR_$attr->{id}>::Type*
                >(io_attrData)
            );
VERBATIM
    }
}
# throw in any range checked attributes
foreach my $attr (@rwPersistAttrs)
{
    if (exists $attr->{range})
    {
        print $rwAttrCFile <<VERBATIM;
        case (ATTR_$attr->{id}):
            return tryGetAttr<ATTR_$attr->{id}>(
                * reinterpret_cast<
                    typename AttributeTraits<ATTR_$attr->{id}>::Type*
                >(io_attrData)
            );
VERBATIM
    }
}
print $rwAttrCFile <<VERBATIM;
        default:
            return _tryGetAttrUnsafe(i_attr, i_size, io_attrData);
    }
    #else
        return _tryGetAttrUnsafe(i_attr, i_size, io_attrData);
    #endif
}

#if !defined(__HOSTBOOT_RUNTIME) && defined(__HOSTBOOT_MODULE)
VERBATIM
foreach my $attr (@rwPersistAttrs)
{
    if (exists $attr->{range})
    {
        print $rwAttrHFile "template<>\n"
        . "bool Target::tryGetAttr<ATTR_$attr->{id}>("
        . "typename AttributeTraits<ATTR_$attr->{id}>::Type& o_attrValue)"
        . " const;\n\n";
        print $rwAttrCFile "template<>\n"
        . "bool Target::tryGetAttr<ATTR_$attr->{id}>("
        . "typename AttributeTraits<ATTR_$attr->{id}>::Type& o_attrValue)"
        . " const\n"
        . "{\n"
        . "    bool l_read = _tryGetAttrUnsafe(ATTR_$attr->{id},"
        .          "sizeof(o_attrValue),&o_attrValue);\n"
        . "    if (l_read)\n"
        . "    {\n";
        my $valueString = "";
        my $extraIndent = "";
        # persence of simpleType tag confirmed previously
        my $isArrayType = exists $attr->{simpleType}->{array};
        if ($isArrayType)
        {
            my $arrayTag = "$attr->{simpleType}->{array}";
            my $arraySize = getArrayTagTotalSize($arrayTag);
            my $numDimensions = getArrayNumDimensions($arrayTag);
            my $arrayPrefix = "";
            $extraIndent = "    ";
            for (my $i=0; $i < $numDimensions - 1; $i++)
            {
                $arrayPrefix =  "$arrayPrefix*";
            }
            print $rwAttrCFile ""
            . "        for(int i=0; i<$arraySize; i++)\n"
            . "        {\n";
            $valueString = "(${arrayPrefix}o_attrValue)[i]";
        }
        else
        {
            $valueString = "o_attrValue";
        }
        if (exists $attr->{range})
        {
            my @ranges = validateRangeMinsAndMaxes($attr->{range}, $attr->{id});
            print $rwAttrCFile "$extraIndent"
            . "        do {\n$extraIndent";
            for my $range (@ranges)
            {
                if (exists $range->{min} || exists $range->{max})
                {
                    print $rwAttrCFile "            if (";
                }
                if (exists $range->{min})
                {
                    print $rwAttrCFile "$valueString >= $range->{min}";
                }
                if (exists $range->{min} && exists $range->{max})
                {
                    print $rwAttrCFile " && ";
                }
                if (exists $range->{max})
                {
                    print $rwAttrCFile "$valueString <= $range->{max}";
                }
                if (exists $range->{min} || exists $range->{max})
                {
                    print $rwAttrCFile ")\n$extraIndent"
                        . "            {\n$extraIndent"
                        . "                break;\n$extraIndent"
                        . "            }\n";
                }
            }
            print $rwAttrCFile "$extraIndent"
                . "            handleRangeCheckFailure(this,ATTR_$attr->{id},"
                . "$valueString);\n$extraIndent"
                . "       } while(0);\n";
        }
        if ($isArrayType)
        {
            print $rwAttrCFile "        }\n";
        }
        print $rwAttrCFile ""
        . "   }\n"
        . "   return l_read;\n"
        . "}\n";
    }
}
print $rwAttrCFile <<VERBATIM;
void validateAllRwNvAttr(const Target* i_pTarget)
{
VERBATIM
foreach my $attr (@rwPersistAttrs)
{
    if (exists $attr->{simpleType} &&
        exists $attr->{simpleType}->{enumeration})
    {
        my $lowerCaseValue = lc "o_$attr->{id}_value";
        print $rwAttrCFile ""
        . "    AttributeTraits<ATTR_$attr->{id}>::Type $lowerCaseValue;\n"
        . "    i_pTarget->tryGetAttr<ATTR_$attr->{id}>($lowerCaseValue);\n\n";
    }
}
foreach my $attr (@rwPersistAttrs)
{
    if (exists $attr->{range})
    {
        my $lowerCaseValue = lc "o_$attr->{id}_value";
        print $rwAttrCFile ""
        . "    AttributeTraits<ATTR_$attr->{id}>::Type $lowerCaseValue;\n"
        . "    i_pTarget->tryGetAttr<ATTR_$attr->{id}>($lowerCaseValue);\n\n";
    }
}
print $rwAttrCFile <<VERBATIM;
}
#endif // !__HOSTBOOT_RUNTIME &&__HOSTBOOT_MODULE
} // namespace TARGETING

VERBATIM
print $rwAttrHFile "#endif\n";
close $rwAttrHFile;
close $rwAttrCFile;
}

# sub getArrayTagTotalSize
# Calculates the total array size from an array tag that contains individual
# sizes of each array dimension
# @param[in] thearray - an array of sizes for each dimension
# @return total size
sub getArrayTagTotalSize {
    my ($thearray) = @_;
    my $arraySize = 1;
    my @bounds = split(/,/,$thearray);

    foreach my $bound (@bounds)
    {
        $arraySize *= $bound;
    }
    return $arraySize;
}

# sub getArrayNumDimensions
# Calculates the number of array dimensions from an array tag that contains
# individual sizes of each array dimension
# @param[in] thearray - an array of sizes for each dimension
# @return number of dimensions
sub getArrayNumDimensions {
    my ($thearray) = @_;
    my @bounds = split(/,/,$thearray);
    my $dims = scalar @bounds;

    return $dims;
}

# sub validateRangeMinsAndMaxes
# Looks at the supplied range tag to determine if it was authored correctly.
# @param[in] range - The range tag and all of its sub elements
# @param[in] attr_id - The attribute id string used for better error messages.
sub validateRangeMinsAndMaxes {
    my ($range, $attr_id) = @_;

    # first check: make sure there is only one unbounded max and only one
    # unbounded min
    my $unboundedMins = 0;
    my $unboundedMaxes = 0;
    foreach my $i (@{$range})
    {
        if (!exists $i->{min} && exists $i->{max})
        {
            $unboundedMaxes++;
        }
        if (!exists $i->{max} && exists $i->{min})
        {
            $unboundedMins++;
        }
        if (!exists $i->{max} && !exists $i->{min})
        {
            die "empty range tag!";
        }
    }
    if ($unboundedMins > 1)
    {
        die "$attr_id has > 1 unbounded min in range tag: $unboundedMins";
    }
    if ($unboundedMaxes > 1)
    {
        die "$attr_id has > 1 unbounded max in range tag: $unboundedMaxes";
    }

    # sort by mins
    # if an item has no min tag assume lowest number possible
    # if an item has no max tag assume highest number possible
    # this puts the unbounded max at beginning and unbounded min at the end
    my @rangeArray = sort { (!exists $a->{min}? "-inf":
                             !exists $a->{max}? "inf": $a->{min} ) <=>
                            (!exists $b->{min}? "-inf":
                             !exists $b->{max}? "inf": $b->{min} )
                          } @$range;

    my $i=0;
    # if the first range is an unbounded max then it stands alone
    my $prevMax = "-inf"; # default prevMax is negative infinity
    if (!exists $rangeArray[$i]->{min})
    {
        if (!exists $rangeArray[$i]->{max})
        {
            die "$attr_id has range tag with no min or max!";
        }
        $prevMax = $rangeArray[$i]->{max};
        $i++;
    }

    # go through the list and check for undesired overlap of ranges
    while (exists $rangeArray[$i]->{min} && exists $rangeArray[$i]->{max})
    {
        if ($rangeArray[$i]->{max} < $rangeArray[$i]->{min})
        {
            print Dumper($rangeArray[$i]);
            die "Min/max pair in <range> tag inverted!";
        }
        if ($prevMax > $rangeArray[$i]->{min})
        {
            print "Previous max: $prevMax\n";
            print Dumper($rangeArray[$i]);
            die "Range overlap! Previous <max> tag $prevMax "
            . "exceeds <min> tag value! $rangeArray[$i]->{min}";
        }
        $prevMax = $rangeArray[$i]->{max};
        $i++;
    }

    # check for stray min tag at the end
    if (exists $rangeArray[$i]->{min})
    {
        # make sure trailing min is greater than previous max
        if ($prevMax > $rangeArray[$i]->{min})
        {
            print "Previous max: $prevMax\n";
            print Dumper($rangeArray[$i]);
            die "Range overlap! Previous <max> tag $prevMax "
            . "exceeds <min> tag value! $rangeArray[$i]->{min}";
        }
    }

    return @rangeArray;
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
        croak("$name must be in the form of a hash.");
    }

    # print keys %{$element} . "\n";

    for my $subElementName (sort(keys %{$element}))
    {
        if(!exists $criteria->{$subElementName})
        {
            croak("$name element cannot have child element of type "
                  . "\"$subElementName\".");
        }
    }

    for my $subElementName (sort(keys %{$criteria}))
    {
        if(   ($criteria->{$subElementName}{required} == 1)
           && (!exists $element->{$subElementName}))
        {
            croak("$name element missing required child element "
                  . "\"$subElementName\".");
        }

        if(exists $element->{$subElementName}
           && ($criteria->{$subElementName}{isscalar} == 1)
             && (ref ($element->{$subElementName}) eq "HASH"))
        {
            croak("$name element child element \"$subElementName\" should be "
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
    $elements{"id"}                     = { required => 1, isscalar => 1};
    $elements{"description"}            = { required => 1, isscalar => 1};
    $elements{"persistency"}            = { required => 1, isscalar => 1};
    $elements{"fspOnly"}                = { required => 0, isscalar => 0};
    $elements{"hbOnly"}                 = { required => 0, isscalar => 0};
    $elements{"readable"}               = { required => 0, isscalar => 0};
    $elements{"simpleType"}             = { required => 0, isscalar => 0};
    $elements{"complexType"}            = { required => 0, isscalar => 0};
    $elements{"nativeType"}             = { required => 0, isscalar => 0};
    $elements{"writeable"}              = { required => 0, isscalar => 0};
    $elements{"hasStringConversion"}    = { required => 0, isscalar => 0};
    $elements{"hwpfToHbAttrMap"}        = { required => 0, isscalar => 0};
    $elements{"display-name"}           = { required => 0, isscalar => 1};
    $elements{"virtual"}                = { required => 0, isscalar => 0};
    $elements{"tempAttribute"}          = { required => 0, isscalar => 0};
    $elements{"serverwizReadonly"}      = { required => 0, isscalar => 0};
    $elements{"serverwizShow"}          = { required => 0, isscalar => 1};
    $elements{"global"}                 = { required => 0, isscalar => 0};
    $elements{"range"}                  = { required => 0, isscalar => 0};
    $elements{"ignoreEkb"}              = { required => 0, isscalar => 0};
    $elements{"mrwRequired"}            = { required => 0, isscalar => 0};

    # do NOT export attribute & its associated enum to serverwiz
    $elements{"no_export"}              = { required => 0, isscalar => 0};

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
    $elements{"parent_type"}      = { required => 0, isscalar => 0};


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
                        croak("HUID for Peer Target not found for "
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
                # Only inspect the default value if it is not already NULL
                elsif ($attr->{default} ne "NULL")
                {
                    # Get the node number from the input file and PHYS_PATH for comparison
                    my $fileNodeNumber = $cfgHbXmlFile;
                    # Extract the node number from the file name
                    $fileNodeNumber =~ s/^.*node.([0-9]).*/$1/;

                    my $attributeNodeNumber = $attr->{default};
                    # Extract the node number from the PHYS_PATH
                    $attributeNodeNumber =~ s/^.*node.([0-9]).*/$1/;

                    # Make sure the data are valid numbers before doing the comparison
                    if ( looks_like_number($fileNodeNumber)         &&
                         looks_like_number($attributeNodeNumber)    &&
                        ($fileNodeNumber != $attributeNodeNumber) )
                    {
                        # If working with a file that is dealing with only NODE
                        # X data, then it will not find a PHYS_PATH that is in
                        # NODE Y, therefore no need to inform caller of a
                        # non-issue.  Just set the default value to NULL.
                        $attr->{default} = "NULL";
                    }
                    else
                    {
                        print STDOUT ("$attr->{id} attribute has an unknown value "
                            . "$attr->{default}\n"
                            . "It must be NULL or a valid PHYS_PATH\n");
                        $attr->{default} = "NULL";
                    } # if ($fileNodeNumber != $attributeNodeNumber)
                } # if (exists $TargetList{$attr->{default}})
            } # if(exists ${$Target_t}{$attr->{id}})
        } # foreach my $attr (@{$targetInstance->{attribute}})
    } # foreach my $targetInstance (@{${$attributes}->{targetInstance}})
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


# FAPI2 ATTRIBUTE SUPPORT
################################################################################
# Writes the FAPI2 plat attribute macros header file header
################################################################################
sub writeFapi2PlatAttrMacrosHeaderFileHeader {
    my($outFile) = @_;

    print $outFile <<VERBATIM;

#ifndef FAPI2_FAPIPLATATTRMACROS_H
#define FAPI2_FAPIPLATATTRMACROS_H

/**
 *  \@file fapi2platattrmacros.H
 *
 *  \@brief FAPI2 -> HB attribute mappings.  This file is autogenerated and
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


namespace fapiToTargeting
{
namespace fapi2
{

enum {

VERBATIM
}

################################################################################
# Writes the FAPI2 plat attribute macros
################################################################################

sub writeFapi2PlatAttrMacrosHeaderFileContent {
    my($attributes,$fapiAttributes,$outFile) = @_;

    my $macroSection = "";
    my $attrSection = "";
    my $typeSection = "";

    foreach my $attribute (@{$attributes->{attribute}})
    {
        foreach my $hwpfToHbAttrMap (@{$attribute->{hwpfToHbAttrMap}})
        {
            if(   !exists $hwpfToHbAttrMap->{id}
               || !exists $hwpfToHbAttrMap->{macro})
            {
                croak("id,macro fields required\n");
            }

            my $fapiReadable  = 0;
            my $fapiWriteable = 0;
            my $instantiated = 0;

            if ($cfgFapiAttributesXmlFile eq "")
            {
                if ($attribute->{id} ~~ @fspAccesCheck)
                {
                    next;
                }
                #No FAPI attributes xml file specified
                if(exists $attribute->{readable})
                {
                    $macroSection .= '    #define ' .  $hwpfToHbAttrMap->{id} .
                        "_GETMACRO(ID,PTARGET,VAL) \\\n" .
                        "        FAPI2_PLAT_ATTR_SVC_GETMACRO_" .
                        $hwpfToHbAttrMap->{macro} . "(ID,PTARGET,VAL)\n";
                    $instantiated = 1;
                }

                if(exists $attribute->{writeable})
                {
                    $macroSection .= '    #ifndef ' .  $hwpfToHbAttrMap->{id} .
                        "_SETMACRO\n";
                    $macroSection .= '    #define ' .  $hwpfToHbAttrMap->{id} .
                        "_SETMACRO(ID,PTARGET,VAL) \\\n" .
                        "        FAPI2_PLAT_ATTR_SVC_SETMACRO_" .
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
                            my $persistency = $attribute->{persistency};
                            if ($hwpfToHbAttrMap->{macro} ne "DIRECT")
                            {
                                croak("FAPI non-platInit attr " .
                                      "'$hwpfToHbAttrMap->{id}' is " .
                                      "'$hwpfToHbAttrMap->{macro}', " .
                                      "it must be DIRECT");
                            }

                            if ( (exists $fapiAttr->{persistent}))
                            {
                                if ($attribute->{persistency} ne "non-volatile")
                                {
                                    croak("FAPI non-platInit attr " .
                                          "'$hwpfToHbAttrMap->{id}' is " .
                                          "'$attribute->{persistency}', " .
                                          "it must be non-volatile");
                                }
                            }
                            else
                            {
                                # Check that platInit attributes
                                # do not have a volatile persistency
                                if( ($persistency ne "volatile-zeroed")
                                    && ($persistency ne "volatile") )
                                {
                                     croak("FAPI non-platInit attr " .
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

                        if(exists $attribute->{simpleType}->{enumeration})
                        {
                            die "Do not use enumerations for FAPI types! ".
                              $attribute->{id}."\n";
                        }
                        else
                        {
                            $typeSection .= "    static_assert(sizeof(TARGETING::ATTR_". $attribute->{id}."_type) ==
                                            sizeof(fapi2::". $fapiAttr->{id}."_Type), \"Size of attribute ATTR_". $attribute->{id}."_type is not equal to the size of ".
                                            $fapiAttr->{id}."_Type , types dont match \" );\n";
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
                            "        FAPI2_PLAT_ATTR_SVC_GETMACRO_" .
                            $hwpfToHbAttrMap->{macro} . "(ID,PTARGET,VAL)\n";
                        $instantiated = 1;
                    }
                    else
                    {
                        croak("FAPI attribute $hwpfToHbAttrMap->{id} requires " .
                            "platform supply readable attribute.");
                    }
                }

                if($fapiWriteable)
                {
                    if(exists $attribute->{writeable})
                    {
                        $macroSection .= '    #define ' .  $hwpfToHbAttrMap->{id} .
                            "_SETMACRO(ID,PTARGET,VAL) \\\n" .
                            "        FAPI2_PLAT_ATTR_SVC_SETMACRO_" .
                            $hwpfToHbAttrMap->{macro} . "(ID,PTARGET,VAL)\n";
                        $instantiated = 1;
                    }
                    else
                    {
                        croak("FAPI attribute $hwpfToHbAttrMap->{id} requires "
                            . "platform supply writeable attribute.");
                    }
                }

            }

            if($instantiated)
            {
                $attrSection .=
                    $hwpfToHbAttrMap->{id} .           " = " .
                    "        TARGETING::ATTR_" .
                    $attribute->{id} . ",\n";
            }
        }
    }

    print $outFile $attrSection;
    print $outFile "};\n\n";
    print $outFile "} // End namespace platAttrSvc\n\n";
    print $outFile "} // End namespace fapi2\n\n";

    print $outFile $typeSection;
    print $outFile "\n\n";
    print $outFile $macroSection;
    print $outFile "\n";
}

################################################################################
# Writes the plat attribute macros header file footer
################################################################################

sub writeFapi2PlatAttrMacrosHeaderFileFooter {
    my($outFile) = @_;

print $outFile <<VERBATIM;

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

    enum SECTION_TYPE : uint8_t
    {
        // Targeting read-only section backed to PNOR.  Always the 0th section.
        SECTION_TYPE_PNOR_RO        = @{[SECTION_TYPE_PNOR_RO]},

        // Targeting read-write section backed to PNOR
        SECTION_TYPE_PNOR_RW        = @{[SECTION_TYPE_PNOR_RW]},

        // Targeting heap section initialized out of PNOR
        SECTION_TYPE_HEAP_PNOR_INIT = @{[SECTION_TYPE_HEAP_PNOR_INIT]},

        // Targeting heap section intialized to zero
        SECTION_TYPE_HEAP_ZERO_INIT = @{[SECTION_TYPE_HEAP_ZERO_INIT]},

        // FSP section

        // Initialized to zero on Fsp Reset / Obliterate on Fsp Reset or R/R
        SECTION_TYPE_FSP_P0_ZERO_INIT = @{[SECTION_TYPE_FSP_P0_ZERO_INIT]},

        // Initialized from Flash / Obliterate on Fsp Reset or R/R
        SECTION_TYPE_FSP_P0_FLASH_INIT = @{[SECTION_TYPE_FSP_P0_FLASH_INIT]},

        // This section remains across fsp power cycle, fixed, never updates
        SECTION_TYPE_FSP_P3_RO = @{[SECTION_TYPE_FSP_P3_RO]},

        // This section persist changes across Fsp Power cycle
        SECTION_TYPE_FSP_P3_RW = @{[SECTION_TYPE_FSP_P3_RW]},

        // Initialized to zero on hard reset, else existing P1 memory
        // copied on R/R
        SECTION_TYPE_FSP_P1_ZERO_INIT = @{[SECTION_TYPE_FSP_P1_ZERO_INIT]},

        // Intialized to default from P3 on hard reset, else existing P1
        // memory copied on R/R
        SECTION_TYPE_FSP_P1_FLASH_INIT = @{[SECTION_TYPE_FSP_P1_FLASH_INIT]},

        // HOSTBOOT section

        // Targeting heap section intialized to zero
        SECTION_TYPE_HB_HEAP_ZERO_INIT = @{[SECTION_TYPE_HB_HEAP_ZERO_INIT]},

        // Attribute metadata section
        SECTION_TYPE_HB_METADATA = @{[SECTION_TYPE_HB_METADATA]},

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
        my $does_not_have_invalid = 1;
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
                    print $outFile "        case ", $attribute->{simpleType}->{enumeration}->{id}, "_",
                        $enumerator->{name},":\n";
                    print $outFile "            return \"",
                        $enumerator->{name},"\";\n";
                    $does_not_have_invalid &&= not($enumerator->{name} =~m/INVALID/);
                }
                # add case for INVALIDs
                if($does_not_have_invalid and not($enumerationType->{id}=~m/^TYPE$/))
                {
                    print $outFile "        case ", $attribute->{simpleType}->{enumeration}->{id}, "_INVALID:\n";
                    print $outFile "            return \"INVALID\";\n";
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
        croak("Could not find enumeration with ID of " . $id . "\n");
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
# Writes the struct file -er
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
                croak("ERROR: Complex type requires a 'description'.");
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
    // Default behavior is to fail the compile if caller attempts to print an
    // unsupported string
    #ifdef __HOSTBOOT_MODULE
        static_assert(A != A, \"Must use an explicitly supported template \"
                              \"specialization\");
    #else
        char mustUseTemplateSpecialization[A != A ? 1 : -1];
    #endif

    const char* retVal = NULL;
    return retVal;
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

        # enforce the implicit length requirement since the format command
        #  does not throw an error if we overrun
        my $enumsize = length($attrId);
        if( $enumsize > 55 )
        {
            print "    $attrId = $hexVal,\n";
        }
        else
        {
            write;
        }
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
    my $enumHexValue = 0;
    # number of '<' in the 'format ENUMFORMAT' below
    my $MAX_ENUM_LENGTH = 58;
    # Format below intentionally > 80 chars for clarity

    format ENUMFORMAT =
    @<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< = @<<<<<<<<<<<<<<<<<<<<<
    $enumName,                                                       $enumHex .","
.
    select($outFile);
    $~ = 'ENUMFORMAT';

    foreach my $enumerationType (@{$attributes->{enumerationType}})
    {
        my $does_not_have_invalid = 1;

        print $outFile "/**\n";
        print $outFile wrapBrief( $enumerationType->{description} );
        print $outFile " */\n";
        print $outFile "enum ", $enumerationType->{id}, "\n";

        print $outFile "{\n";

        foreach my $enumerator (@{$enumerationType->{enumerator}})
        {
            $enumHexValue =
                          enumNameToValue($enumerationType,$enumerator->{name});


            #If the enum is bigger than 0xFFFFFFFF, then we need to append 'LL'
            #or 'ULL' to it to prevent compiler errors.
            if($enumHexValue > $MAX_4_BYTE_VALUE)
            {
                # find type
                my $simpleType = getAttributeType($enumerationType->{id},
                                                  $attributes);

                if (exists $simpleType->{'uint64_t'})
                {
                    $enumHex = sprintf "0x%08XULL", $enumHexValue;
                }
                else
                {
                    $enumHex = sprintf "0x%08XLL", $enumHexValue;
                }
            }
            else
            {
                $enumHex = sprintf "0x%08X", $enumHexValue;
            }
            $enumName = $enumerationType->{id} . "_" . $enumerator->{name};

            # enforce the implicit length requirement since the format command
            #  does not throw an error if we overrun
            my $enumsize = length($enumName);
            if($enumsize > $MAX_ENUM_LENGTH)
            {
               print "    $enumName = $enumHex,\n";
            }
            else
            {
               write;
            }

            # set flag if there is already an enum with an INVALID enumerator
            $does_not_have_invalid &&= not($enumerator->{name} =~m/INVALID/);
        }

        # Add default invalid enum value
        # - Place default invalid enum value at the end of list of enum values above
        # - Calculate the number of bytes needed to store the largest enumerator per enum
        #     and attempt to assign an INVALID with that size
        # - Skip enums that already have enumerators with an INVALID
        # - Skip enums that already have all F's assigned to an enumerator of the largest word size

        my $stringMaxEValue = sprintf "%X", maxEnumValue($enumerationType);

        my $attributeType = getAttributeType($enumerationType->{id}, $attributes);

        # assume 8 nibbles (4 bytes) long for enums that are not of type
        # (u)int8_t ... (u)int64_t
        my $numF = 8;
        # check the type hash list for int or uint type
        foreach my $key (keys %{$attributeType})
        {
            if($key =~ m/int/)
            {
                # extract the number of bits from the type
                # and convert to number of nibbles for the following sprintf
                ($numF) = $key =~ m/([0-9]+)/;
                $numF /= 4;
                last;
            }
        }

        my $invalidEnumHex = sprintf "%${numF}X", 0xFF;
        $invalidEnumHex  =~ tr/ /F/;
        if($invalidEnumHex ne $stringMaxEValue and $does_not_have_invalid)
        {
            if (exists $attributeType->{'uint64_t'})
            {
               $enumHex = sprintf "0x%${numF}sULL", $invalidEnumHex;
            }
            elsif (exists $attributeType->{'int64_t'})
            {
               $enumHex = sprintf "0x%${numF}sLL", $invalidEnumHex;
            }
            elsif($enumerationType->{id}=~m/^TYPE$/)
            {
               # special case for the TYPE enum because in pldm_fru.C
               # its size is restricted to 7 bits
               $enumHex = sprintf "0x%08X", 0x0000007F;
            }
            else
            {
               # fill the remaining digits with 0's if needed
               $enumHex = sprintf "0x%08s", $invalidEnumHex;
            }

            $enumName = $enumerationType->{id} . "_INVALID";
            my $enumsize = length($enumName);
            if($enumsize > $MAX_ENUM_LENGTH)
            {
               print "    $enumName = $enumHex,\n";
            }
            else
            {
               write;
            }
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

sub writeAttrSizesFileHeader
{
    my ($outFile) = @_;

print $outFile <<VERBATIM;

#ifndef TARG_ATTR_SIZES
#define TARG_ATTR_SIZES

#include <stdint.h>
#include <map>
#include <vector>

/**
 * \@file attrsizesdata.H
 *
 * \@brief The file contains the data structure that holds the sizes and types
 *         of different attributes. Attributes represented as arrays also have
 *         dimensions associated with the array.
 */

namespace TARGETING
{

enum ATTR_DATA_TYPE
{
    UINT8_T_TYPE,
    INT8_T_TYPE,
    UINT16_T_TYPE,
    INT16_T_TYPE,
    UINT32_T_TYPE,
    INT32_T_TYPE,
    UINT64_T_TYPE,
    INT64_T_TYPE
};

enum ATTR_DATA_SIZE
{
    UINT8_T_SIZE = sizeof(uint8_t),
    INT8_T_SIZE = sizeof(int8_t),
    UINT16_T_SIZE = sizeof(uint16_t),
    INT16_T_SIZE = sizeof(int16_t),
    UINT32_T_SIZE = sizeof(uint32_t),
    INT32_T_SIZE = sizeof(int32_t),
    UINT64_T_SIZE = sizeof(uint64_t),
    INT64_T_SIZE = sizeof(int64_t)
};

typedef struct
{
    ATTR_DATA_TYPE dataType;
    ATTR_DATA_SIZE dataSize;
    bool isArray;
    std::vector<uint16_t>dimensions;
} attrSizeData_t;

constexpr bool ARRAY = true;
constexpr bool NOT_ARRAY = false;

// Map format:
// attr hash: {attr data type, attr data size, array or not, array dimensions}
static std::map<uint32_t, attrSizeData_t>g_attrSizesMap =
{
VERBATIM

}

sub getAttrDataTypeSize
{
    my ($attribute) = @_;
    my $dataTypeStr = "";
    my $dataSizeStr = "";

    if(exists $attribute->{simpleType}->{uint8_t})
    {
        $dataSizeStr = "UINT8_T_SIZE";
        $dataTypeStr = "UINT8_T_TYPE";
    }
    elsif(exists $attribute->{simpleType}->{int8_t})
    {
        $dataSizeStr = "INT8_T_SIZE";
        $dataTypeStr = "INT8_T_TYPE";
    }
    elsif(exists $attribute->{simpleType}->{uint16_t})
    {
        $dataSizeStr = "UINT16_T_SIZE";
        $dataTypeStr = "UINT16_T_TYPE";
    }
    elsif(exists $attribute->{simpleType}->{int16_t})
    {
        $dataSizeStr = "INT16_T_SIZE";
        $dataTypeStr = "INT16_T_TYPE";
    }
    elsif(exists $attribute->{simpleType}->{uint32_t})
    {
        $dataSizeStr = "UINT32_T_SIZE";
        $dataTypeStr = "UINT32_T_TYPE";
    }
    elsif(exists $attribute->{simpleType}->{int32_t})
    {
        $dataSizeStr = "INT32_T_SIZE";
        $dataTypeStr = "INT32_T_TYPE";
    }
    elsif(exists $attribute->{simpleType}->{uint64_t})
    {
        $dataSizeStr = "UINT64_T_SIZE";
        $dataTypeStr = "UINT64_T_TYPE";
    }
    elsif(exists $attribute->{simpleType}->{int64_t})
    {
        $dataSizeStr = "INT64_T_SIZE";
        $dataTypeStr = "INT64_T_TYPE";
    }
    return ($dataTypeStr, $dataSizeStr);
}

sub isSimpleNumericAttribute
{
    my ($attribute) = @_;

    return ( (exists $attribute->{simpleType}) and
             ( exists $attribute->{simpleType}->{uint8_t} or
               exists $attribute->{simpleType}->{int8_t} or
               exists $attribute->{simpleType}->{uint16_t} or
               exists $attribute->{simpleType}->{int16_t} or
               exists $attribute->{simpleType}->{uint32_t} or
               exists $attribute->{simpleType}->{int32_t} or
               exists $attribute->{simpleType}->{uint64_t} or
               exists $attribute->{simpleType}->{int64_t}));
}

sub writeAttrSizesFileBody
{
    my ($attributes, $outFile) = @_;

    foreach my $attribute (@{$attributes->{attribute}})
    {
        # Only process simple-type attribute types
        if(isSimpleNumericAttribute($attribute))
        {
            my $dimensionsString = "";
            my $attrHash = getAttributeIdHashStr($attribute->{id});
            my $isArray = exists $attribute->{simpleType}->{array};
            # If it's an array, populate the array dimensions
            if($isArray)
            {
                my @arrayDimensions = split(/,/,$attribute->{simpleType}->{array});
                foreach my $dimension (@arrayDimensions)
                {
                    $dimensionsString = $dimensionsString . "$dimension, ";
                }
                # Remove the last trailing space and comma after the last dimension
                chop($dimensionsString);
                chop($dimensionsString);
            }

            # Write map entry. The format is { hash, {dataType, isArray, {dimensions}}
            # Note that even though ARRAY and NOT_ARRAY are strings here, they translate
            # to bools in the code (see the const definition at the start of file).
            my $isArrayStr = $isArray ? "ARRAY" : "NOT_ARRAY";
            my ($dataTypeStr, $dataSizeStr) = getAttrDataTypeSize($attribute);
            print $outFile "    {0x$attrHash, {$dataTypeStr, $dataSizeStr, $isArrayStr, {$dimensionsString}}},\n";
        }
    }
}

sub writeAttrSizesFileFooter
{
    my ($outFile) = @_;

print $outFile <<VERBATIM;
}; // end of map

} // namespace TARGETING
#endif // #ifndef TARG_ATTR_SIZES

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
        if (isSimpleNumericAttribute($attribute))
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
                                  "uint32_t", "uint64_t",
                                  "int8_t", "int16_t",
                                  "int32_t", "int64_t");

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

###############################################################################
# Writes code to populate the header of the Attribute Name Map File
###############################################################################
sub writeAttrIdNameFileHeader
{
    my ($outFile) = @_;

    # file description
    print $outFile "// Attribute ID -> Attribute Name Map File\n";

    # includes
    print $outFile "#include <map>\n\n";
}


###############################################################################
# Writes code to populate Attribute ID to Attribute Name Map File
###############################################################################
sub writeAttrIdNameMap
{
    my($attributes,$outFile,$rwOnly) = @_;

    my $attributeIdEnum = getAttributeIdEnumeration($attributes);
    my $mapName = "g_attrIdToNameMap";

    if($rwOnly)
    {
        print $outFile "// g_rwAttrIdToNameMap only includes writeable attributes\n\n";
        $mapName = "g_rwAttrIdToNameMap";
    }
    else
    {
        print $outFile "// g_attrIdToNameMap includes all attributes\n\n";
    }

    # attribute id -> attribute info map
    print $outFile
        "const static std::map<uint32_t,const char*>$mapName = {\n";

    # loop through every attribute
    foreach my $attribute
        (sort { $a->{id} cmp $b->{id} } @{$attributes->{attribute}})
    {

        # Only want to add writeable attr
        if ($rwOnly and
            !(exists $attribute->{writeable}))
        {
            next;
        }

        # Simple or complex types
        if ((exists $attribute->{simpleType}) ||
            (exists $attribute->{complexType}))
        {
            # This loops through all attributes to add id and name
            # not just enumerated attributes
            foreach my $enum (@{$attributeIdEnum->{enumerator}})
            {
                if($enum->{name} eq $attribute->{id})
                {
                    # start attribute map data
                    print $outFile "\t{\n";
                    # attribute id
                    print $outFile "\t\t$enum->{value},\n";
                    # attribute name
                    print $outFile "\t\t\"ATTR_$attribute->{id}\"\n";
                    # end attribute map data
                    print $outFile "\t},\n";
                }
            }
        }
    }

    # end of map
    print $outFile "};\n\n";
}

sub writeMutexFileHeader {
    my($outFile) = @_;

print $outFile <<VERBATIM;

#ifndef TARG_MUTEXATTRIBUTES_H
#define TARG_MUTEXATTRIBUTES_H

/**
 *  \@file mutexattributes.H
 *
 *  \@brief Array of attributes Ids whose type is hbmutex
 *
 *  This header file contains a single array that lists out all of the hbmutex
 *  attributes. This is used on the MPIPL path to know which attributes we need
 *  to reset.  This file is autogenerated and should not be altered.
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <stdint.h>
VERBATIM
}

sub writeMutexFileAttrs {
    my($attributes,$outFile) = @_;

print $outFile <<VERBATIM;

//******************************************************************************
// Array
//******************************************************************************

namespace TARGETING
{

/**
 *  \@brief HB Mutex Attribute IDs
 *
 *  Array defining all attribute ids found that are of type hbMutex.
 *  This file is autogenerated and should not be altered.
 */
const struct {uint32_t id; bool isRecursive;} hbMutexAttrIds[] = {
VERBATIM

    my @mutexAttrIds;

    foreach my $attribute (@{$attributes->{attribute}})
    {
        #check if hbmutex tag is present
        #check that attr is readable/writeable
        if(   (exists $attribute->{simpleType})
                && (exists $attribute->{simpleType}->{hbmutex}
                ||  exists $attribute->{simpleType}->{hbrecursivemutex})
                && (exists $attribute->{readable})
                && (exists $attribute->{writeable}))
        {
            my $recursiveType = "false";
            if (exists $attribute->{simpleType}->{hbrecursivemutex})
            {
                $recursiveType = "true";
            }

            push @mutexAttrIds, ([ $attribute->{id}, $recursiveType ]);
        }
    }

    # variables that can be used for writing the enums to the file
    my $attrId;
    my $hexVal;
    my $recursiveVal;

    # Format below intentionally > 80 chars for clarity
    format ATTRMUTEXFORMAT =
                                  @>>>>>>>>>>>>>>>>>>>>
    "{ ". $hexVal .", ". $recursiveVal ." },"
.
    select($outFile);
    $~ = 'ATTRMUTEXFORMAT';

    my $attrIdEnum = getAttributeIdEnumeration($attributes);

    foreach my $enumerator (@{$attrIdEnum->{enumerator}})
    {
        $hexVal = $enumerator->{value};
        $attrId = $enumerator->{name};
        foreach my $mutexAttrId (@mutexAttrIds)
        {
            $recursiveVal = $mutexAttrId->[1];

            if( $mutexAttrId->[0] eq $attrId )
            {
                write;
                last;
            }
        }
    }

    print $outFile "};\n\n";
}

sub writeMutexFileFooter {
    my($outFile) = @_;
    print $outFile <<VERBATIM;
} // End namespace TARGETING

#endif // TARG_MUTEXATTRIBUTES_H

VERBATIM
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

// std::array support is dependent on the compiler supporting c++11
#if __cplusplus >= 201103L
#include <array>
#endif

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
    my $sizefunc = "";

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
            && (exists $attribute->{simpleType}->{hbmutex}
                || exists $attribute->{simpleType}->{hbrecursivemutex}) )
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

        if (!($attribute->{id} ~~ @fspAccesCheck))
        {
            $traits .= " fspAccessible,";
        }

        # Build value type

        my $type = "";
        my $dimensions = "";
        my $stdArrAddOn = ""; # Only used if attr holds array type
        my $isEnumerationType = 0;
        if(exists $attribute->{simpleType})
        {
            my $simpleType = $attribute->{simpleType};
            my $simpleTypeProperties = simpleTypeProperties();
            for my $typeName (sort(keys %{$simpleType}))
            {
                if(exists $simpleTypeProperties->{$typeName})
                {
                    if(    $simpleTypeProperties->{$typeName}{typeName}
                        eq "XMLTOHB_USE_PARENT_ATTR_ENUMERATION_ID")
                    {
                        $type = $attribute->{simpleType}->{enumeration}->{id};
                        $isEnumerationType = 1;
                    }
                    else
                    {
                        $type = $simpleTypeProperties->{$typeName}{typeName};
                    }
                    # Set char array
                    if(exists $simpleType->{string})
                    {
                        # Note: A 1-dimensional char array (noted as a "<string>..." type in an XML)
                        # won't trigger the std::array setup below, therefore it must be setup as a
                        # std::array here.
                        # A multidimensional array that holds type char (also using "<string>...")
                        # will not process the char array-dimensions below, so that set up is
                        # started here.
                        if(exists $simpleType->{string}->{sizeInclNull})
                        {
                            # Use the char dimension
                            my $charDimension = $simpleType->{string}->{sizeInclNull};
                            $dimensions = "[$charDimension]";
                            $stdArrAddOn = "std::array<$type, $charDimension>";
                        }
                    }

                    # Setup for a 1,2,3...N-dimensional std::array.
                    if(   (exists $simpleType->{array})
                        && ($simpleTypeProperties->{$typeName}{supportsArray}) )
                    {

                        my @revBounds = reverse split(/,/,$simpleType->{array});

                        for my $idx (0 .. $#revBounds)
                        {
                            $dimensions = "[@revBounds[$idx]]$dimensions";
                            # If $stdArrAddOn is already filled, then we need to append even more
                            # dimensions to the outside of it.
                            if ($stdArrAddOn ne "")
                            {
                                $stdArrAddOn = "std::array<$stdArrAddOn, "
                                    ."@revBounds[$idx]>";
                            }
                            else
                            {
                                $stdArrAddOn = "std::array<$type, "
                                    ."@revBounds[$idx]>";
                            }
                        }

                    }

                    last;
                }
            }

            if($type eq "")
            {
                croak("Unsupported simpleType child element for "
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
            croak("Could not determine attribute data type for attribute "
                . "$attribute->{id}.");
        }

        chop($traits);

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

            # In addition, add a default invalid value to traits definition for
            # uint8_t ... uint64_t, int8_t ... int64_t
            print $outFile "#if __cplusplus >= 201103L \n";
            my $qualifiers = "static constexpr";

            if ($isEnumerationType)
            {
                if ($attribute->{id}=~m/^TYPE$/)
                {
                    # special case for TYPE attr because in pldm_fru.C
                    # its size is restricted to 7 bits
                    print $outFile "        $qualifiers uint32_t $attribute->{id}_INVALID = 0x7F;\n";
                }
                else
                {
                    # otherwise, use default 32 bit sizing for enums
                    print $outFile "        $qualifiers uint32_t $attribute->{id}_INVALID = 0xFFFFFFFF;\n";
                }
            }
            else
            {
                my ($unsigned, $sizeInBytes) = ($type =~ /(u*)int(\d+)/);
                # skip non-integer types
                if ($type=~m/int/)
                {
                    $sizeInBytes /= 8; # convert number of bits to number of bytes
                    my $suffix = "";
                    if ($sizeInBytes >= 8)
                    {
                        # if attr type is 8 bytes large,
                        # append a suffix
                        $suffix = uc($unsigned)."LL";
                    }
                    print $outFile "        $qualifiers $type $attribute->{id}_INVALID = 0x", ("FF" x $sizeInBytes), "$suffix;\n";
                }
            }

            # Append typedef for std::array if attr holds array value
            if ($stdArrAddOn ne "")
            {
                print $outFile "        typedef $stdArrAddOn TypeStdArr;\n";
            }
            print $outFile "#endif\n";
            print $outFile "};\n\n";

            $typedefs .= "// Type aliases and/or sizes for ATTR_"
                . "$attribute->{id} attribute\n";

            $typedefs .= "typedef " . $type .
                " $attribute->{id}" . "_ATTR" . $dimensions . ";\n";

            # Append a more friendly type alias for attribute
            $typedefs .= "typedef " . $type .
                " ATTR_" . "$attribute->{id}" . "_type" . $dimensions . ";\n";

            if ($stdArrAddOn ne "")
            {
                $typedefs .= "#if __cplusplus >= 201103L \n";
                $typedefs .= "typedef $stdArrAddOn "
                    ."ATTR_$attribute->{id}_typeStdArr;\n";
                $typedefs .= "#endif\n";
            }

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

            # Create case definitions for attrSizeLookup function

            $sizefunc .= "    // Get size for ATTR_$attribute->{id}" .
                " attribute\n";
            $sizefunc .= "    case ATTR_$attribute->{id}:\n";
            $sizefunc .= "        l_attrSize = sizeof(ATTR_" .
                "$attribute->{id}_type);\n";
            $sizefunc .= "        break;\n";
            $sizefunc .= "\n";
        }
    };

    print $outFile "/**\n";
    print $outFile wrapBrief("Mapping of alias type name to underlying type");
    print $outFile " */\n";
    print $outFile $typedefs ."\n";

    # Create attrSizeLookup function

    print $outFile <<VERBATIM;
/**
 *  \@brief Function to return size of specified attribute
 *
 *  \@param[in] i_attrId Attribute ID for attribute to look up size
 *  \@return uint32_t Size of the attribute
 *
 *  \@retval Size of the attribute if succeeded
 *  \@retval 0 if failed
 *
 */
inline uint32_t attrSizeLookup(ATTRIBUTE_ID i_attrId)
{
    uint32_t l_attrSize = 0;

    switch(i_attrId) {
VERBATIM
    print $outFile $sizefunc;
    print $outFile <<VERBATIM;
    default:
        break;
    }

    return l_attrSize;
}

VERBATIM
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


    # List of attributes we want to explicitly support
    my @allowed_attributes = (
         "SERIAL_NUMBER",
         "PART_NUMBER",
         "PEC_PCIE_HX_KEYWORD_DATA",
         "ECID",
         "HUID",
         "BOOT_PAU_DPLL_BYPASS",
         "MASTER_MBOX_SCRATCH"
    );

    # loop through every attribute to make the switch/case
    foreach my $attribute (@{$attributes->{attribute}})
    {
        my $skippedattr = 0;
        if( grep { $_ eq $attribute->{id} } @allowed_attributes )
        {
            print "Allowing $attribute->{id}\n";
        }
        else
        {
            print $outFile "#if 0 //Modify writeAttrErrlCFile in xmltohb.pl to add this attribute\n";
            $skippedattr = 1;
        }

        # things we'll skip:
        if(!(exists $attribute->{readable}) ||  # write-only attributes
           (exists $attribute->{simpleType} && (
           (exists $attribute->{simpleType}->{hbmutex}) ||
           (exists $attribute->{simpleType}->{hbrecrusivemutex}) ||
           (exists $attribute->{simpleType}->{fspmutex}))) # mutex attributes
          ) {
            print $outFile "        case (ATTR_",$attribute->{id},"): { break; }\n";
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

        elsif(isSimpleNumericAttribute($attribute))
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
            print $outFile "                    memcpy(tmpBuffer + attrSize,&lType,sizeof(lType));\n";
            print $outFile "                    attrSize += sizeof(lType);\n";
            print $outFile "                }\n";
            print $outFile "            }\n";
            print $outFile "            break;\n";
            print $outFile "        }\n";
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

        if( $skippedattr )
        {
            print $outFile "#endif\n";
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
           (exists $attribute->{simpleType}->{hbrecursivemutex}) ||
           (exists $attribute->{simpleType}->{fspmutex}))) # mutex attributes
          ) {
            next;
        }
        print $outFile "    addData(ATTR_",$attribute->{id},");\n";
    }
    print $outFile "}\n";

    print $outFile "\n";

    print $outFile "} // namespace\n\n";
} # sub writeAttrErrlCFile


######
#Create a .H and an equivalent .py file to parse attributes out of the errlog
#####
sub writeAttrErrlHFile {
    my($attributes,$outFile,$outFilePY) = @_;

    # Included by errludattributeP.H
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
    print $outFile "        uint32_t attrEnum = ntohl(UINT32_FROM_PTR(l_ptr));\n";
    print $outFile "        l_ptr += sizeof(attrEnum);\n";
    print $outFile "        char* tmplabel = NULL;\n";
    print $outFile "\n";
    print $outFile "        switch (attrEnum) {\n";

    print $outFilePY "\n#This file is generated by src/usr/targeting/common/xmltohb/xmltohb.pl\n";
    print $outFilePY "import json\n";
    print $outFilePY "from udparsers.helpers.errludP_Helpers import intConcat, hexConcat\n\n";
    print $outFilePY "\"\"\" User Details Parser Attribute called by b0100.py\n\n";
    print $outFilePY "\@param[in] ver: int value of subsection version\n";
    print $outFilePY "\@param[in] data: memoryview object of data to be parsed\n";
    print $outFilePY "\@returns: JSON string of parsed data\n";
    print $outFilePY "\"\"\"\n";
    print $outFilePY "def ErrlUserDetailsParserAttribute(ver, data):\n";
    print $outFilePY "    d = dict()\n";
    print $outFilePY "    subd = dict()\n";
    print $outFilePY "    i = 0\n\n";
    print $outFilePY "    while (i+4) <= len(data):\n";
    print $outFilePY "        #First 4 bytes is the attr enum\n";
    print $outFilePY "        attrEnum,i=intConcat(data, i, i+4)\n";
    print $outFilePY "        traceEntry = []\n";
    print $outFilePY "        label = \'\'\n\n";


    my $attributeIdEnum = getAttributeIdEnumeration($attributes);

    my $isFirst = 1;

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

        if ($isFirst) {
            print $outFilePY "        if attrEnum == $attrVal:\n";
            $isFirst = 0;
        }
        else {
            print $outFilePY "        elif attrEnum == $attrVal:\n";
        }

        # things we'll skip:
        if(!(exists $attribute->{readable}) ||  # write-only attributes
           (exists $attribute->{simpleType} && (
           (exists $attribute->{simpleType}->{hbmutex}) ||
           (exists $attribute->{simpleType}->{hbrecursivemutex}) ||
           (exists $attribute->{simpleType}->{fspmutex}))) # mutex attributes
          ) {
            print $outFile "              //not readable\n";

            print $outFilePY "            pass #not readable\n";
        }
        # Enums have strings defined already, use them
        elsif(exists $attribute->{simpleType} && (exists $attribute->{simpleType}->{enumeration}) ) {
            print $outFile "              //simpleType:enum\n";
            print $outFile "              pLabel = \"",$attribute->{id},"\";\n";

            print $outFilePY "            #simpleType:enum\n";
            print $outFilePY "            label = \"",$attribute->{id},"\"\n";

            foreach my $enumerationType (@{$attributes->{enumerationType}})
            {
                if ($enumerationType->{id} eq $attribute->{id})
                {

                print $outFile "              switch (*((uint32_t*)l_ptr)) {\n";

                print $outFilePY "            attr, i=intConcat(data, i, i+4)\n";
                my $isFirst = 1;

                foreach my $enumerator (@{$enumerationType->{enumerator}})
                {
                    my $enumName = $attribute->{id} . "_" . $enumerator->{name};
                    my $enumHex = sprintf "0x%08X", enumNameToValue($enumerationType,$enumerator->{name});
                    print $outFile "                  case ",$enumHex,": {\n";
                    print $outFile "                      sprintf(&(l_traceEntry[0]), \"",$enumName,"\");\n";
                    print $outFile "                      l_ptr += sizeof(uint32_t);\n";
                    print $outFile "                      break;\n";
                    print $outFile "                  }\n";

                    if ($isFirst) {
                        print $outFilePY "            if attr == $enumHex:\n";
                        $isFirst = 0;
                    }
                    else {
                        print $outFilePY "            elif attr == $enumHex:\n";
                    }

                    print $outFilePY "                 traceEntry.append(\"$enumName\")\n";

                }
                print $outFile "                  default: break;\n";
                print $outFile "              }\n";
                }
            }
        }
        # makes no sense to dump mutex attributes, so skipping
        elsif(exists $attribute->{simpleType} && (exists $attribute->{simpleType}->{hbmutex}) || (exists $attribute->{simpleType}->{hbrecursivemutex}) ) {
            print $outFile "            //Mutex attributes - skipping\n";

            print $outFilePY "            pass #Mutex attributes - skipping\n";
        }
        # makes no sense to dump fsp mutex attributes, so skipping
        elsif(   (exists $attribute->{simpleType})
              && (exists $attribute->{simpleType}->{fspmutex}) )
        {
            print $outFile "            //Mutex attributes - skipping\n";

            print $outFilePY "            pass #Mutex attributes - skipping\n";
        }
        # any complicated types just get dumped as raw hex binary
        elsif(exists $attribute->{complexType}) {
            #print $outFile "         //complexType\n";
            #print $outFile "         uint32_t<ATTR_",$attribute->{id},">::Type tmp;\n";
            #print $outFile "         if( i_pTarget->tryGetAttr<ATTR_",$attribute->{id},">(tmp) ) {\n";
            #print $outFile "           sprintf(i_buffer, \" \", &tmp, sizeof(tmp));\n";
            #print $outFile "         }\n";
            print $outFile "              //complexType - skipping\n";

            print $outFilePY "            pass #complexType - skipping\n";
        }
        # unsigned ints dump as hex, signed as decimals
        elsif(isSimpleNumericAttribute($attribute))
        {
            print $outFile "              //simpleType:uint\n";
            print $outFile "              pLabel = \"",$attribute->{id},"\";\n";

            print $outFilePY "            #simpleType:uint\n";
            print $outFilePY "            label = \"",$attribute->{id},"\"\n";

            my @bounds;
            if(exists $attribute->{simpleType}->{array})
            {
                # remove any whitespace from simpleType array
                $attribute->{simpleType}->{array} =~ s/\s+//g;
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

                print $outFilePY "            traceEntry.append(\"[$bounds[0]]:\")\n";
            }
            elsif ($size == 2)
            {
                print $outFile "              uint32_t offset = sprintf(&(l_traceEntry[0]), \"[$bounds[0]][$bounds[1]]:\");\n";

                print $outFilePY "            traceEntry.append(\"[$bounds[0]][$bounds[1]]:\")\n";
            }
            elsif ($size == 3)
            {
                print $outFile "              uint32_t offset = sprintf(&(l_traceEntry[0]), \"[$bounds[0]][$bounds[1]][$bounds[2]]:\");\n";

                print $outFilePY "            traceEntry.append(\"[$bounds[0]][$bounds[1]][$bounds[2]]:\")\n";
            }
            else
            {
                print $outFile "              uint32_t offset = 0;\n";
            }
            if (exists $attribute->{simpleType}->{uint8_t})
            {
                print $outFile "              l_traceEntry.resize(10+offset + $total_count * 5);\n";
                print $outFile "              for (uint32_t i = 0;i<$total_count;i++) {\n";
                print $outFile "                  sprintf(&(l_traceEntry[offset+i*5]), \"0x%.2X \", *(((uint8_t *)l_ptr)+i));\n";
                print $outFile "              }\n";
                print $outFile "              l_ptr += $total_count * sizeof(uint8_t);\n";

                print $outFilePY "            for x in range($total_count):\n";
                print $outFilePY "                traceEntry.append(hexConcat(data, i, i+1)[0])\n";
                print $outFilePY "                i += 1\n";
            }
            elsif (exists $attribute->{simpleType}->{uint16_t}) {
                print $outFile "              l_traceEntry.resize(10+offset + $total_count * 7);\n";
                print $outFile "              for (uint32_t i = 0;i<$total_count;i++) {\n";
                print $outFile "                  sprintf(&(l_traceEntry[offset+i*7]), \"0x%.4X \", ntohs(UINT16_FROM_PTR(reinterpret_cast<const uint16_t*>(l_ptr) + i)));\n";
                print $outFile "              }\n";
                print $outFile "              l_ptr += $total_count * sizeof(uint16_t);\n";

                print $outFilePY "            for x in range($total_count):\n";
                print $outFilePY "                traceEntry.append(hexConcat(data, i, i+2)[0])\n";
                print $outFilePY "                i += 2\n";
            }
            elsif (exists $attribute->{simpleType}->{uint32_t}) {
                print $outFile "              l_traceEntry.resize(10+offset + $total_count * 11);\n";
                print $outFile "              for (uint32_t i = 0;i<$total_count;i++) {\n";
                print $outFile "                  sprintf(&(l_traceEntry[offset+i*11]), \"0x%.8X \", ntohl(UINT32_FROM_PTR(reinterpret_cast<const uint32_t*>(l_ptr)+i)));\n";
                print $outFile "              }\n";
                print $outFile "              l_ptr += $total_count * sizeof(uint32_t);\n";

                print $outFilePY "            for x in range($total_count):\n";
                print $outFilePY "                traceEntry.append(hexConcat(data, i, i+4)[0])\n";
                print $outFilePY "                i += 4\n";
            }
            elsif (exists $attribute->{simpleType}->{uint64_t}) {
                print $outFile "              l_traceEntry.resize(10+offset + $total_count * 19);\n";
                print $outFile "              for (uint32_t i = 0;i<$total_count;i++) {\n";
                print $outFile "                  sprintf(&(l_traceEntry[offset+i*19]), \"0x%.16llX \", ntohll(UINT64_FROM_PTR(reinterpret_cast<const uint64_t*>(l_ptr)+i)));\n";
                print $outFile "              }\n";
                print $outFile "              l_ptr += $total_count * sizeof(uint64_t);\n";

                print $outFilePY "            for x in range($total_count):\n";
                print $outFilePY "                traceEntry.append(hexConcat(data, i, i+8)[0])\n";
                print $outFilePY "                i += 8\n";
            }
            elsif (exists $attribute->{simpleType}->{int8_t}) {
                print $outFile "              l_traceEntry.resize(10+offset + $total_count * 5);\n";
                print $outFile "              for (uint32_t i = 0;i<$total_count;i++) {\n";
                print $outFile "                  sprintf(&(l_traceEntry[offset+i*5]), \"0x%.2X \", *(((int8_t *)l_ptr)+i));\n";
                print $outFile "              }\n";
                print $outFile "              l_ptr += $total_count * sizeof(uint8_t);\n";

                print $outFilePY "            for x in range($total_count):\n";
                print $outFilePY "                traceEntry.append(hexConcat(data, i, i+1)[0])\n";
                print $outFilePY "                i += 1\n";
            }
            elsif (exists $attribute->{simpleType}->{int16_t}) {
                print $outFile "              l_traceEntry.resize(10+offset + $total_count * 7);\n";
                print $outFile "              for (uint32_t i = 0;i<$total_count;i++) {\n";
                print $outFile "                  sprintf(&(l_traceEntry[offset+i*7]), \"0x%.4X \", ntohs(INT16_FROM_PTR(reinterpret_cast<const int16_t*>(l_ptr)+i)));\n";
                print $outFile "              }\n";
                print $outFile "              l_ptr += $total_count * sizeof(int16_t);\n";

                print $outFilePY "            for x in range($total_count):\n";
                print $outFilePY "                traceEntry.append(hexConcat(data, i+x, i+2)[0])\n";
                print $outFilePY "                i += 2\n";
            }
            elsif (exists $attribute->{simpleType}->{int32_t}) {
                print $outFile "              l_traceEntry.resize(10+offset + $total_count * 11);\n";
                print $outFile "              for (uint32_t i = 0;i<$total_count;i++) {\n";
                print $outFile "                  sprintf(&(l_traceEntry[offset+i*11]), \"0x%.8X \", ntohl(INT32_FROM_PTR(reinterpret_cast<const int32_t*>(l_ptr)+i)));\n";
                print $outFile "              }\n";
                print $outFile "              l_ptr += $total_count * sizeof(int32_t);\n";

                print $outFilePY "            for x in range($total_count):\n";
                print $outFilePY "                traceEntry.append(hexConcat(data, i, i+4)[0])\n";
                print $outFilePY "                i += 4\n";
            }
            elsif (exists $attribute->{simpleType}->{int64_t}) {
                print $outFile "              l_traceEntry.resize(10+offset + $total_count * 19);\n";
                print $outFile "              for (uint32_t i = 0;i<$total_count;i++) {\n";
                print $outFile "                  sprintf(&(l_traceEntry[offset+i*19]), \"0x%.16llX \", ntohll(INT64_FROM_PTR(reinterpret_cast<const int64_t*>(l_ptr)+i)));\n";
                print $outFile "              }\n";
                print $outFile "              l_ptr += $total_count * sizeof(int64_t);\n";

                print $outFilePY "            for x in range($total_count):\n";
                print $outFilePY "                traceEntry.append(hexConcat(data, i, i+8)[0])\n";
                print $outFilePY "                i += 8\n";
            }
        }
        # EntityPaths
        elsif(exists $attribute->{nativeType} && ($attribute->{nativeType}->{name} eq "EntityPath")) {
            print $outFile "              //nativeType:EntityPath\n";
            print $outFile "              pLabel = \"",$attribute->{id},"\";\n";

            print $outFilePY "            #nativeType:EntityPath\n";
            print $outFilePY "            label = \"$attribute->{id}\"\n";

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

            print $outFilePY "            pathType = { 0x01: \"Logical:\",\n";
            print $outFilePY "                         0x02: \"Physical:\",\n";
            print $outFilePY "                         0x03: \"Device:\",\n";
            print $outFilePY "                         0x04: \"Power:\" }\n\n";
            print $outFilePY "            elementInstance = {\n";

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

                        print $outFilePY "                              $enumHex: \"/$enumName\",\n";
                    }
                }
            } # enumerationType
            print $outFile "                      default:   { pathString = \"/UNKNOWN\"; break; }\n";
            print $outFile "                  } // switch\n";
            print $outFile "                  // copy next part in, overwritting previous terminator\n";
            print $outFile "                  dataSize += sprintf(&(l_traceEntry[0]) + dataSize, \"%s%d\",pathString,lElementInstance[i+1]);\n";
            print $outFile "                  l_ptr += 2 * sizeof(uint8_t);\n";
            print $outFile "              } // for\n";

            print $outFilePY "                              }\n";
            print $outFilePY "            pType = data[i]\n";
            print $outFilePY "            i += 1\n";
            print $outFilePY "            start+=1\n";
            print $outFilePY "            pathString = pathType.get(pType, \"Unknown:\")\n";
            print $outFilePY "            pathSize = data[i]\n";
            print $outFilePY "            i += 1\n";
            print $outFilePY "            for x in range(0, pathSize, 2):\n";
            print $outFilePY "                pathString += elementInstance.get(data[start], \"/UNKNOWN\")\n";
            print $outFilePY "                pathString += str(data[start+1])\n";
            print $outFilePY "                start+=2\n\n";
            print $outFilePY "            return pathString, start+1\n";
        }
        # any other nativeTypes are just decimals...  (I never saw one)
        elsif(exists $attribute->{nativeType}) {
            print $outFile "              //nativeType\n";
            print $outFile "              pLabel = \"",$attribute->{id},"\";\n";
            print $outFile "              sprintf(&(l_traceEntry[0]), \"%d\", *((int32_t *)l_ptr));\n";
            print $outFile "              l_ptr += sizeof(uint32_t);\n";

            print $outFilePY "            #nativeType\n";
            print $outFilePY "            label = \"$attribute->{id}\"\n";
            print $outFilePY "            traceEntry.append(intConcat(data, i, i+4))\n";
            print $outFilePY "            i += 1\n";
        }
        # just in case, nothing..
        else
        {
            #print $outFile "              //unknown attributes\n";
            print $outFilePY "            pass\n";
        }


        print $outFile "              break;\n";
        print $outFile "          }\n";

    }
    print $outFile "          default: {\n";
    print $outFile "              tmplabel = new char[30];\n";
    print $outFile "              sprintf( tmplabel, \"Unknown [0x%x]\", attrEnum );\n";
    print $outFile "              pLabel = tmplabel;\n";
    print $outFile "              break;\n";
    print $outFile "          }\n";
    print $outFile "        } // switch\n";
    print $outFile "\n";
    print $outFile "        // pointing to something - print it.\n";
    print $outFile "        if (pLabel != NULL) {\n";
    print $outFile "            i_parser.PrintString(pLabel, &(l_traceEntry[0]));\n";
    print $outFile "        }\n";
    print $outFile "        if( tmplabel != NULL ) { delete[] tmplabel; }\n";
    print $outFile "    } // for\n";
    print $outFile "  } // parse\n\n";
    print $outFile "private:\n";
    print $outFile "\n";
    print $outFile "// Disabled\n";
    print $outFile "ErrlUserDetailsParserAttribute(const ErrlUserDetailsParserAttribute &);\n";
    print $outFile "ErrlUserDetailsParserAttribute & operator=(const ErrlUserDetailsParserAttribute &);\n";
    print $outFile "};\n";
    print $outFile "} // namespace\n\n";

    print $outFilePY "        else:\n";
    print $outFilePY "            label=\"Unknown\"\n";
    print $outFilePY "            traceEntry.append(hex(attrEnum))\n";
    print $outFilePY "\n        if label:\n";
    print $outFilePY "            subd[label]=traceEntry\n\n";
    print $outFilePY "    d[\'Target Attributes\']=subd\n";
    print $outFilePY "    jsonStr = json.dumps(d)\n";
    print $outFilePY "    return jsonStr\n";
} # sub writeAttrErrlHFile

######
#Create a .csv file to parse attribute overrides/syncs
#####
sub writeAttrInfoCsvFile {
    my($attributes,$outFile) = @_;

    # Print the file header
    print $outFile "# targAttrInfo.csv\n";
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
        if (isSimpleNumericAttribute($attribute))
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
                    elsif (exists $attribute->{simpleType}->{int8_t})
                    {
                        print $outFile "s8";
                    }
                    elsif (exists $attribute->{simpleType}->{int16_t})
                    {
                        print $outFile "s16";
                    }
                    elsif (exists $attribute->{simpleType}->{int32_t})
                    {
                        print $outFile "s32";
                    }
                    elsif (exists $attribute->{simpleType}->{int64_t})
                    {
                        print $outFile "s64";
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
static __attribute__((unused)) const char * P0_PERSISTENCY = "p0";
static __attribute__((unused)) const char * P1_PERSISTENCY = "p1";
static __attribute__((unused)) const char * P3_PERSISTENCY = "p3";

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

    my $mapAttrMetadataPairs = "\n    static const Pair_t l_pair[] = {\n";
    my $hbOnlyMapAttrMetadataPairs = '';

    foreach my $key ( keys %finalAttrhash)
    {
        # Fetch the Size of the attribute
        my $keySize = "ATTR_"."$key"."_type";

        if (!(exists $finalAttrhash{$key}->{hbOnly})
            && ((exists $finalAttrhash{$key}->{simpleType})
                || (exists $finalAttrhash{$key}->{complexType})
                || (exists $finalAttrhash{$key}->{nativeType})))
        {
            # We're good to go
        }
        else
        {
            $hbOnlyMapAttrMetadataPairs .=
                "        std::make_pair( ATTR_$key, AttrMetadataStr(sizeof($keySize), false, NULL, false )),\n";
            next;
        }

        $mapAttrMetadataPairs .= "        std::make_pair( ATTR_".$key.",";
        $mapAttrMetadataPairs .= " AttrMetadataStr(sizeof($keySize),";

        # Fetch Read/Writeable Property
        if(exists $finalAttrhash{$key}->{writeable})
        {
            $mapAttrMetadataPairs .= " true,";
        }
        else
        {
            $mapAttrMetadataPairs .= " false,";
        }

        if(!(exists $finalAttrhash{$key}->{persistency}))
        {
            croak("Attribute[$key] should have persistency by default");
        }
        if($finalAttrhash{$key}->{persistency} eq "non-volatile")
        {
            $mapAttrMetadataPairs .= " P3_PERSISTENCY,";
        }
        elsif(($finalAttrhash{$key}->{persistency} eq
               "semi-non-volatile-zeroed") ||
              ($finalAttrhash{$key}->{persistency} eq "semi-non-volatile"))
        {
            $mapAttrMetadataPairs .= " P1_PERSISTENCY,";
        }
        elsif(($finalAttrhash{$key}->{persistency} eq "volatile") ||
              ($finalAttrhash{$key}->{persistency} eq "volatile-zeroed"))
        {
            $mapAttrMetadataPairs .= " P0_PERSISTENCY,";
        }
        else
        {
            croak("Not a defined" .
                  "Persistency[$finalAttrhash{$key}->{persistency}] for" .
                  "attribute [$key]");
        }

        if ($finalAttrhash{$key}->{id} ~~ @nonSyncAttributes)
        {
            $mapAttrMetadataPairs .= " true) ),\n";
        }
        else
        {
            $mapAttrMetadataPairs .= " false) ),\n";
        }
    }

    print $outFile $mapAttrMetadataPairs;

    # The HB-only attributes are only compiled in for hostboot to save space.
    print $outFile "#ifdef __HOSTBOOT_MODULE\n";
    print $outFile "// ******** WARNING ********\n";
    print $outFile "// The synchronized, read-write, and persistency fields\n";
    print $outFile "// for the following entries are potentially INCORRECT\n";
    print $outFile "// because Hostboot has not yet needed to consume them.\n";
    print $outFile "// Edit xmltohb.pl to calculate these values if necessary.\n";

    print $outFile $hbOnlyMapAttrMetadataPairs;
    print $outFile "#endif\n";

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
    bool noSync;

    attrMetadataStr() :
        size(0), readWriteable(false), persistency(NULL), noSync(false) {}

    attrMetadataStr(uint32_t i_size, bool i_rw, const char* i_persistency, \
        bool i_sync) :
        size(i_size), readWriteable(i_rw), persistency(i_persistency),\
        noSync(i_sync) {}
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
         *
         * ******** WARNING ********
         * The attribute information in the map about persistency, synchronization,
         * and read-write for HB-only attributes may be INCORRECT because Hostboot
         * hasn't needed that info yet. If you need it to be correct, edit
         * xmltohb.pl to calculate it correctly.

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
    my($attributes,$outFile,$pathOutFilePY,$targetOutFilePY) = @_;

    #First setup the includes and function definition
    print $outFile "\n";
    print $outFile "#ifndef ERRL_UDTARGET_H\n";
    print $outFile "#define ERRL_UDTARGET_H\n";
    print $outFile "\n";
    print $outFile "#include <string.h>\n";
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
    print $outFile "#if !defined(PARSER) && !defined(LOGPARSER)\n";
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
    print $outFile "#else // if LOGPARSER defined\n";
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
    print $outFile "      // entityPath is PATH_TYPE:4, NumberOfElements:4,\n";
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

    # Python version of local function used by Target and Callout to print the entity path
    print $pathOutFilePY "\n#This file is generated by src/usr/targeting/common/xmltohb/xmltohb.pl\n\n";
    print $pathOutFilePY "\"\"\" Creates the entity path for the given data\n";
    print $pathOutFilePY "Function is used by ErrlUserDetailsParserCallout and\n";
    print $pathOutFilePY "ErrlUserDetailsParserTarget in b0100.py\n\n";
    print $pathOutFilePY "\@param[in] data: memoryview object to get the data from\n";
    print $pathOutFilePY "\@param[in] start: starting index of data to use for entity path\n";
    print $pathOutFilePY "\@returns: a string of the entity path, and the offset value for the data following\n";
    print $pathOutFilePY "          the entity path data\n";
    print $pathOutFilePY "\"\"\"\n";
    print $pathOutFilePY "def errlud_parse_entity_path(data, start):\n";
    print $pathOutFilePY "    pathType = { 0x01: \"Logical:\",\n";
    print $pathOutFilePY "                 0x02: \"Physical:\",\n";
    print $pathOutFilePY "                 0x03: \"Device:\",\n";
    print $pathOutFilePY "                 0x04: \"Power:\" }\n\n";
    print $pathOutFilePY "    elementInstance = {\n";

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
            print $pathOutFilePY "                        $enumHex: \"/$enumName\",\n";
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

    print $pathOutFilePY "                      }\n\n";
    print $pathOutFilePY "    # Entity Path Layout\n";
    print $pathOutFilePY "    # 1 byte  : PATH_TYPE:4, NumberOfElements:4\n";
    print $pathOutFilePY "    # N number of [Element, Instance#] pairs\n";
    print $pathOutFilePY "    # 1 byte  : Element\n";
    print $pathOutFilePY "    # 1 byte  : Instance #\n";
    print $pathOutFilePY "    #\n";
    print $pathOutFilePY "    # Output is PathType:/ElementInstance#/ElementInstance#/ElementInstance#\n";
    print $pathOutFilePY "    pathTypeLength = data[start]\n";
    print $pathOutFilePY "    start+=1\n\n";
    print $pathOutFilePY "    pathString = pathType.get((pathTypeLength & 0xF0) >> 4, \"Unknown:\")\n";
    print $pathOutFilePY "    pathSize = (pathTypeLength & 0x0F) * 2\n\n";
    print $pathOutFilePY "    for x in range(0, pathSize, 2):\n";
    print $pathOutFilePY "        pathString += elementInstance.get(data[start], \"/UNKNOWN\")\n";
    print $pathOutFilePY "        start += 1\n";
    print $pathOutFilePY "        pathString += str(data[start])\n";
    print $pathOutFilePY "        start += 1\n\n";
    print $pathOutFilePY "    return pathString, start\n";


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
    print $outFile "            i_parser.PrintNumber( l_label, \"HUID = 0x%08X\", ntohl(UINT32_FROM_PTR(l_ptr32)) );\n";
    print $outFile "            l_ptr32++;\n";

    print $targetOutFilePY "\n# This file is generated by src/usr/targeting/common/xmltohb/xmltohb.pl\n\n";
    print $targetOutFilePY "import json\n";
    print $targetOutFilePY "from udparsers.helpers.errludP_Helpers import hexConcat, intConcat, findNull, strConcat\n";
    print $targetOutFilePY "from udparsers.helpers.entityPath import errlud_parse_entity_path\n\n";
    print $targetOutFilePY "\"\"\" User Details Parser Target called by b0100.py\n\n";
    print $targetOutFilePY "\@param[in] ver: int value of subsection version\n";
    print $targetOutFilePY "\@param[in] data: memoryview object of data to be parsed\n";
    print $targetOutFilePY "\@returns: JSON string of parsed data\n";
    print $targetOutFilePY "\"\"\"\n";
    print $targetOutFilePY "def ErrlUserDetailsParserTarget(ver, data):\n";
    print $targetOutFilePY "    LABEL_TAG = 0xEEEEEEEE\n";
    print $targetOutFilePY "    MASTER_LABEL_TAG = 0xFFFFFFFF\n";

    print $targetOutFilePY "    i = 0\n\n";
    print $targetOutFilePY "    attrClass = {\n";

    # find CLASS
    print $outFile "            switch (ntohl(UINT32_FROM_PTR(l_ptr32))) { // CLASS\n";
    foreach my $enumerationType (@{$attributes->{enumerationType}})
    {
      if( $enumerationType->{id} eq "CLASS" ) {
        foreach my $enumerator (@{$enumerationType->{enumerator}})
        {
            my $enumHex = sprintf "0x%02X",
                enumNameToValue($enumerationType,$enumerator->{name});
            my $enumName = $enumerationType->{id} . "_" . $enumerator->{name};
            print $outFile "                case $enumHex: { attrData = \"$enumName\"; break; }\n";

            print $targetOutFilePY "                  $enumHex: \"$enumName\",\n";
        }
      }
    } # enumerationType
    print $outFile "                default:   { attrData = \"UNKNOWN_CLASS\"; break; }\n";
    print $outFile "            } // switch\n";
    print $outFile "            i_parser.PrintString(\"  ATTR_CLASS\", attrData);\n";
    print $outFile "            l_ptr32++;\n";

    print $targetOutFilePY "                }\n\n";
    print $targetOutFilePY "    attrType = {\n";

    # find TYPE
    print $outFile "            switch (ntohl(UINT32_FROM_PTR(l_ptr32))) { // TYPE\n";
    foreach my $enumerationType (@{$attributes->{enumerationType}})
    {
      if( $enumerationType->{id} eq "TYPE" ) {
        foreach my $enumerator (@{$enumerationType->{enumerator}})
        {
            my $enumHex = sprintf "0x%02X",
                enumNameToValue($enumerationType,$enumerator->{name});
            my $enumName = $enumerationType->{id} . "_" . $enumerator->{name};
            print $outFile "                case $enumHex: { attrData = \"$enumName\"; break; }\n";

            print $targetOutFilePY "                 $enumHex: \"$enumName\",\n";
        }
      }
    } # enumerationType
    print $outFile "                default:   { attrData = \"UNKNOWN_TYPE\"; break; }\n";
    print $outFile "            } // switch\n";
    print $outFile "            i_parser.PrintString(\"  ATTR_TYPE\", attrData);\n";
    print $outFile "            l_ptr32++;\n";

    print $targetOutFilePY "                }\n\n";
    print $targetOutFilePY "    attrModel = {\n";

    # find MODEL
    print $outFile "            switch (ntohl(UINT32_FROM_PTR(l_ptr32))) { // MODEL\n";
    foreach my $enumerationType (@{$attributes->{enumerationType}})
    {
      if( $enumerationType->{id} eq "MODEL" ) {
        foreach my $enumerator (@{$enumerationType->{enumerator}})
        {
            my $enumHex = sprintf "0x%02X",
                enumNameToValue($enumerationType,$enumerator->{name});
            my $enumName = $enumerationType->{id} . "_" . $enumerator->{name};
            print $outFile "                case $enumHex: { attrData = \"$enumName\"; break; }\n";
            print $targetOutFilePY "                  $enumHex: \"$enumName\",\n";
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

    print $targetOutFilePY "                }\n\n";
    print $targetOutFilePY "    label = \"Target\"\n";
    print $targetOutFilePY "    dictArray = []\n";
    print $targetOutFilePY "    while (i+4) <= len(data):\n";
    print $targetOutFilePY "        subd = dict()\n";
    print $targetOutFilePY "        word, i=intConcat(data, i, i+4)\n";
    print $targetOutFilePY "        if word == MASTER_LABEL_TAG:\n";
    print $targetOutFilePY "            subd[\"Target\"]=\"MASTER_PROCESSOR_CHIP_TARGET_SENTINEL\"\n";
    print $targetOutFilePY "        elif word == LABEL_TAG:\n";
    print $targetOutFilePY "            # Data Layout\n";
    print $targetOutFilePY "            #  4 bytes  : Label Tag (word)\n";
    print $targetOutFilePY "            # 24 bytes  : Label\n\n";
    print $targetOutFilePY "            label=strConcat(data, i, findNull(data, i, i+24))[0]\n";
    print $targetOutFilePY "            i += 24 #skip over any trailing null chars\n";
    print $targetOutFilePY "        else:\n";
    print $targetOutFilePY "            if i+(4*4) <= len(data):\n";
    print $targetOutFilePY "                # Data Layout\n";
    print $targetOutFilePY "                # 4 bytes  : HUID (word)\n";
    print $targetOutFilePY "                # 4 bytes  : Class\n";
    print $targetOutFilePY "                # 4 bytes  : Type\n";
    print $targetOutFilePY "                # 4 bytes  : Model\n";
    print $targetOutFilePY "                # N bytes  : Entity Path 1\n";
    print $targetOutFilePY "                # N bytes  : Entity Path 2\n\n";
    print $targetOutFilePY "                subd[label]=\"HUID = \" + f\'0x{word:08X}\'\n";
    print $targetOutFilePY "                subd[\"  ATTR_CLASS\"]=attrClass.get(intConcat(data, i, i+4)[0], \"UNKNOWN_CLASS\")\n";
    print $targetOutFilePY "                i += 4\n";
    print $targetOutFilePY "                subd[\"  ATTR_TYPE\"]=attrType.get(intConcat(data, i, i+4)[0], \"UNKNOWN_TYPE\")\n";
    print $targetOutFilePY "                i += 4\n";
    print $targetOutFilePY "                subd[\"  ATTR_MODEL\"]=attrModel.get(intConcat(data, i, i+4)[0], \"UNKNOWN_MODEL\")\n";
    print $targetOutFilePY "                i += 4\n";
    print $targetOutFilePY "                for x in range(2):\n";
    print $targetOutFilePY "                    pathType,i=intConcat(data, i, i+4)\n";
    print $targetOutFilePY "                    if (pathType == $attrPhysPath or #ATTR_PHYS_PATH\n";
    print $targetOutFilePY "                        pathType == $attrAffinityPath): #ATTR_AFFINITY_PATH\n";
    print $targetOutFilePY "                        outString, i=errlud_parse_entity_path(data, i)\n";
    print $targetOutFilePY "                        if pathType == $attrPhysPath:\n";
    print $targetOutFilePY "                            subd[\"  ATTR_PHYS_PATH\"]=outString\n";
    print $targetOutFilePY "                        if pathType == $attrAffinityPath:\n";
    print $targetOutFilePY "                            subd[\"  ATTR_AFFINITY_PATH\"]=outString\n";
    print $targetOutFilePY "            dictArray.append(subd)\n";
    print $targetOutFilePY "    jsonStr = json.dumps(dictArray)\n";
    print $targetOutFilePY "    return jsonStr\n";

    print $outFile "                uint32_t l_pathType = ntohl(UINT32_FROM_PTR(l_ptr32));\n";
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
# Create a .C file to put System Target Attributes along with their respective
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
    my $env_chip = $ENV{'CHIP'};

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
               croak(
                 "Error:Duplicate AttributeId hashvalue for $attribute->{id} "
                     . "and $attrValHash{$attributeHexVal28bit}");
            }
            # fatal error if attribute has been defined more than once.
            # Could be defined twice in same file or defined in two files
            # that have been merged, such as attributes_types.xml and
            # attribute_types_hb.xml or attributes_types_fsp.
            else
            {
                croak("Error: AttributeId $attribute->{id} "
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
# Pack mutex
################################################################################

sub packMutex {
    my $length = 24;
    my $binaryData .= pack ("C".$length);

    return $binaryData;
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
        croak("ERROR: Supplied string exceeds allows length");
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
        croak("Caller must specify 'size', 'blockSize', 'oneBlockMinimum' "
            . "args.");
    }

    if(!$blockSize)
    {
        croak("'blockSize' arg must be > 0.");
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
        croak("FSP mutex attribute default must always be 0, "
              . "was $value instead.");
    }

    if($attribute->{persistency} ne "volatile-zeroed")
    {
        croak("FSP mutex attribute persistency must be volatile-zeroed, "
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
        croak("HB mutex attribute default must always be 0, "
              . "was $value instead.");
    }

    if($attribute->{persistency} ne "volatile-zeroed")
    {
        croak("HB mutex attribute persistency must be volatile-zeroed, "
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
        croak("ERROR: Tried to enforce string policies on a non-simple type");
    }

    if(!exists $attribute->{simpleType}->{string})
    {
        croak("ERROR: Did not find expected string element");
    }

    if(!exists $attribute->{simpleType}->{string}->{sizeInclNull})
    {
        croak("ERROR: Did not find expected string sizeInclNull element");
    }

    my $size = $attribute->{simpleType}->{string}->{sizeInclNull};
    if($size <= 1)
    {
        croak("ERROR: String size must be > 1 (string of size one is "
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
    $typesHoH{"string"}      = { supportsArray => 1, canBeHex => 0, complexTypeSupport => 0, typeName => "char"                       , bytes => 1, bits => 8 , default => \&defaultString, alignment => 1, specialPolicies =>\&enforceString,  packfmt =>\&packString};
    $typesHoH{"int8_t"}      = { supportsArray => 1, canBeHex => 1, complexTypeSupport => 1, typeName => "int8_t"                     , bytes => 1, bits => 8 , default => \&defaultZero  , alignment => 1, specialPolicies =>\&null,           packfmt => "C" };
    $typesHoH{"int16_t"}     = { supportsArray => 1, canBeHex => 1, complexTypeSupport => 1, typeName => "int16_t"                    , bytes => 2, bits => 16, default => \&defaultZero  , alignment => 1, specialPolicies =>\&null,           packfmt =>\&pack2byte};
    $typesHoH{"int32_t"}     = { supportsArray => 1, canBeHex => 1, complexTypeSupport => 1, typeName => "int32_t"                    , bytes => 4, bits => 32, default => \&defaultZero  , alignment => 1, specialPolicies =>\&null,           packfmt =>\&pack4byte};
    $typesHoH{"int64_t"}     = { supportsArray => 1, canBeHex => 1, complexTypeSupport => 1, typeName => "int64_t"                    , bytes => 8, bits => 64, default => \&defaultZero  , alignment => 1, specialPolicies =>\&null,           packfmt =>\&pack8byte};
    $typesHoH{"uint8_t"}     = { supportsArray => 1, canBeHex => 1, complexTypeSupport => 1, typeName => "uint8_t"                    , bytes => 1, bits => 8 , default => \&defaultZero  , alignment => 1, specialPolicies =>\&null,           packfmt => "C" };
    $typesHoH{"uint16_t"}    = { supportsArray => 1, canBeHex => 1, complexTypeSupport => 1, typeName => "uint16_t"                   , bytes => 2, bits => 16, default => \&defaultZero  , alignment => 1, specialPolicies =>\&null,           packfmt =>\&pack2byte};
    $typesHoH{"uint32_t"}    = { supportsArray => 1, canBeHex => 1, complexTypeSupport => 1, typeName => "uint32_t"                   , bytes => 4, bits => 32, default => \&defaultZero  , alignment => 1, specialPolicies =>\&null,           packfmt =>\&pack4byte};
    $typesHoH{"uint64_t"}    = { supportsArray => 1, canBeHex => 1, complexTypeSupport => 1, typeName => "uint64_t"                   , bytes => 8, bits => 64, default => \&defaultZero  , alignment => 1, specialPolicies =>\&null,           packfmt =>\&pack8byte};
    $typesHoH{"enumeration"} = { supportsArray => 1, canBeHex => 1, complexTypeSupport => 0, typeName => "XMLTOHB_USE_PARENT_ATTR_ENUMERATION_ID" , bytes => 0, bits => 0 , default => \&defaultEnum  , alignment => 1, specialPolicies =>\&null,           packfmt => "packEnumeration"};
    $typesHoH{"hbmutex"}     = { supportsArray => 1, canBeHex => 1, complexTypeSupport => 0, typeName => "mutex_t*"                   , bytes => 24, bits => 192, default => \&defaultZero  , alignment => 8, specialPolicies =>\&enforceHbMutex, packfmt =>\&packMutex};
    $typesHoH{"hbrecursivemutex"}     = { supportsArray => 1, canBeHex => 1, complexTypeSupport => 0, typeName => "mutex_t*"                   , bytes => 24, bits => 192, default => \&defaultZero  , alignment => 8, specialPolicies =>\&enforceHbMutex, packfmt =>\&packMutex};
    $typesHoH{"Target_t"}    = { supportsArray => 0, canBeHex => 1, complexTypeSupport => 0, typeName => "TARGETING::Target*"         , bytes => 8, bits => 64, default => \&defaultZero  , alignment => 8, specialPolicies =>\&null,           packfmt =>\&pack8byte};
    $typesHoH{"fspmutex"}     = { supportsArray => 1, canBeHex => 1, complexTypeSupport => 0, typeName => "util::Mutex*"              , bytes => 8, bits => 64, default => \&defaultZero  , alignment => 8, specialPolicies =>\&enforceFspMutex, packfmt =>\&pack8byte};

    $g_simpleTypeProperties_cache = \%typesHoH;

    return $g_simpleTypeProperties_cache;
}

################################################################################
# Get attribute type
################################################################################
sub getAttributeType {
    my($attributeId,$attributes) = @_;
    my $attrType;

    foreach my $attribute (@{$attributes->{attribute}})
    {
        if ($attribute->{id} eq $attributeId)
        {
            if(exists $attribute->{simpleType})
            {
                $attrType = $attribute->{simpleType};
            }
            elsif (exists $attribute->{complexType})
            {
                $attrType = $attribute->{complexType};
            }
            elsif (exists $attribute->{nativeType})
            {
                $attrType = $attribute->{nativeType};
            }
            else
            {
                $attrType = "unknown type";
            }
            last;
        }
    }
    return $attrType;
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
                    croak("Cannot provide default for unsupported nativeType.");
                }
            }
            else
            {
                croak("Unrecognized value type.");
            }

            last;
        }
    }

    return $default;
}

################################################################################
# Merge the fields of two complex attributes
################################################################################

# This function will merge the fields of two complex attributes.
#
# The field's value from $newAttrFields will be merged into $currentAttrFields.
# $currentAttrFields must have, at a minimum, all the fields that are in
# $newAttrFields.  If not then this function will halt execution with an error
# message.  Fields that are in $currentAttrFields that have no associated value
# within $newAttrFields will be left as is.
#
# param [in] - $newAttrFields - These are the new fields with new values that
#                        are to be merged.
#
# param [in] - $currentAttrFields - These are the current fields which, at a
#                        minimum, include ALL the fields from $newAttrFields.
#                        There may be more.
#
# return - The two fields successfully merged
#
sub mergeComplexAttributeFields {
    my($newAttrFields, $currentAttrFields) = @_;

    # Make a deep copy of the current fields, don't want to modify
    # $currentAttrFields - leave as is.  This copy will contain the merger of
    # the two fields.
    my $mergedFields = dclone $currentAttrFields;

    # If the merged field's (an alias for the current attribute fields)
    # hash is empty, then just assign it the new attribute field's value -
    # no merge necessary
    if ($mergedFields->{default} == 0)
    {
        $mergedFields->{default} = $newAttrFields->{default};
    }
    # Only proceed if both attribute pairs have values to merge
    elsif ($newAttrFields->{default} != 0)
    {
        # Iterate over the fields of $newField and look for their corresponding
        # id in $currentAttrFields.  All the fields in $newField should exist in
        # $currentAttrFields, if not, then there is a problem

        # There's an issue that $newAttrFields->{default}->{field} may not be an array.
        # To address that issue, we can check type of it:
        my @newFieldArr = ();
        if (ref $newAttrFields->{default}->{field} ne "ARRAY")
        {
            # If it's not an array, then append it to newFieldArr as if it is the only array entry
            @newFieldArr = ($newAttrFields->{default}->{field});
        }
        else
        {
            # If it is an array, then @newFieldArr will be a reference to it
            @newFieldArr = @{$newAttrFields->{default}->{field}};
        }

        foreach my $newField (@newFieldArr)
        {
            my $foundField = 0;

            # Do not try to merge in a field with no value
            if (ref($newField->{value}) eq "HASH")
            {
                #print STDOUT "Skip $newField->{id}\n";
                next;
            }

            # Iterate over $mergedFields (really $currentAttrFields) looking
            # for the $newField of @newFieldArr
            foreach my $currentField (@{$mergedFields->{default}->{field}})
            {
                # Found the field in question
                if ($currentField->{id} eq $newField->{id})
                {
                   # Merge in the new value from $newField
                   $currentField->{value} = $newField->{value};
                   $foundField = 1;
                   last;
                }
            } # end foreach my $currentField ...

            # A field was not found ... halt execution
            if ($foundField == 0)
            {
               croak("Field $newField is not supported.")
            }
        } # end foreach my $newField ...
    }
    # else new attribute fields is empty - nothing to merge

    return $mergedFields;
}

################################################################################
# Get target attributes
################################################################################

# This function will recursively work from the most derived target to the base
# target.  This function does not work on target instances, only the target
# types themselves.  $type is the current target being worked on.
#
# The default values for the attributes associated with the current target
# are gathered and consolidated in the attribute hash ($attrhasha). If there is
# no default value assocaited with that attribute then the attribute in the hash
# does not get updated - don't want to wipe out the current data with no data.
#
# BUT if the current target is the base target type (or the most derived target
# type) and there is no default value for the attribute, the attribute is still
# added to the attribute hash with defaults taken from the attribute definition
# itself as found in the attrubutes_types.xml.
#
# If the attribute is a simple type and it has a default value associated with
# it, then the attribute hash is simply updated with the new default value.
#
# If the attribute is a complex type and it has default values, the fields of
# the attribute will be merged with the same attribute in the hash, with the new
# attribute's fields taking precedence and any undefined fields keeping thier
# current value.  Again do not want to wipe out the current fields with no data.
#
# param [in] - $type - The target type (ie 'base', 'unit', 'unit-phb-power9',
#                      etc) currently being processed
# param [in] - $attributes - This has all data associated with attributes,
#                      target types, target instances and other data aggregates.
# param [in/out] - $attrhasha - An aggregate list of the attributes as each
#                      attribute is gathered from the target type and maintained
#                      in this list.
#

sub getTargetAttributes {
    my($type,$attributes,$attrhasha) = @_;

    foreach my $targetType (@{$attributes->{targetType}})
    {
        if ($targetType->{id} eq $type)
        {
            if (exists $targetType->{parent})
            {
                getTargetAttributes($targetType->{parent},
                                    $attributes,$attrhasha);
            }

            # Iterate thru all of this target's attribute and
            # copy them over to aggregate attributes if necessary
            foreach my $attr (@{$targetType->{attribute}})
            {
                # Flag to indicate that a complex type has been found
                my $isComplex = 0;

                # Determine if attribute ($attr) is a complex type.
                # Complex types are handled differently than simple types.
                # This is SO inefficient, I know no other way to determine this
                foreach my $attribute (@{$attributes->{attribute}})
                {
                    if ( ($attribute->{id} eq $attr->{id})  &&
                         (exists $attribute->{complexType}) )
                    {
                        $isComplex = 1;
                        last;
                    }
                }

                # If the aggregate of attributes ($attrhasha) does NOT currently
                # contain the attribute ($attr) then set the base's attribute
                # to the aggregate list ($attrhasha), regardless if attribute
                # ($attr) is complex or not.  This will give a base line to
                # work with.
                if (!exists $attrhasha->{ $attr->{id}})
                {
                    my $default = getAttributeDefault($attr->{id},$attributes);
                    $attrhasha->{ $attr->{id}}->{default} = $default;

                    # Add the 'id' value to the attribute
                    $attrhasha->{ $attr->{id}}->{id} = $attr->{id};
                }

                # If the attribute ($attr) has no default, then there is
                # nothing to do.  Move onto the next attribute.
                if (!exists $attr->{default})
                {
                   next;
                }

                # The simple type attribute ($attr) has a default value,
                # replace current attribute in aggregate list ($attrhasha)
                # with this one ($attr)
                if ($isComplex == 0)
                {
                   $attrhasha->{ $attr->{id} } = $attr;
                }
                else
                # This is a complex attribute.  Need to merge fields of
                # current attribute, within the aggregate list ($attrhasha),
                # with this new attribute's fields ($attr).
                {
                    my $mergedFields = mergeComplexAttributeFields($attr,
                                            $attrhasha->{ $attr->{id}});
                    $attrhasha->{ $attr->{id}}->{default} =
                                            $mergedFields->{default};
                } # end if ($isComplex == 0) ... else ...
            } # end foreach my $attr (@{$targetType->{attribute}})
           last;
        } # end if($targetType->{id} eq $type)
    } # end foreach my $targetType (@{$attributes->{targetType}})
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
        croak("Failed to write binary data for enumeration.");
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

        print STDOUT $enumeration;
        croak("Could not convert enumerator name \"$enumeratorName\" into "
            . "enumerator value in \"$enumerationName\".");
    }

    if($enumeratorValue < 0)
    {
        # In C++ enumerations are unsigned, we do not support negative values.
        croak("Negative enumeration value found $enumeration->{id},"
               ." $enumeratorValue");
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
        croak("Too many bits ($bits) for type ($type).");
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
    my ($attributes,$complexType,$attributeDefault,$attrhash) = @_;

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
                                                       $default->{value},
                                                       $attrhash);
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
                        croak("Field type $field->{type} not supported in "
                            . "complex type.");
                    }
                }

                last;
            }
        }

        if(!$found)
        {
            croak("Could not find value for field $field->{name} of type $field->{type}");
        }
    }

    $binaryData .= $accumulator->releaseAndClear();

    return $binaryData;
}

################################################################################
# Pack an entity path into a binary data stream
################################################################################

sub packEntityPath {
    my($attributes,$value,$attrhash) = @_;

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
        croak("Unsupported entity path type of [$value], [$typeStr], [$path].");
    }

    # If the EntityPath begins with a period, it's a relative path
    if (substr($path, 0, 1) eq '.')
    {
        # We only support the relative path "." (i.e. "this target") for now
        if ($path ne '.')
        {
            croak("This form of relative EntityPath not supported: $path");
        }

        my $pathAttributeID = ($typeStr eq "physical"
                               ? "PHYS_PATH"
                               : "AFFINITY_PATH");

        if (!exists $attrhash->{$pathAttributeID}
            || !exists $attrhash->{$pathAttributeID}->{default})
        {
            croak("Target has no $pathAttributeID attribute (when packing relative entity path)");
        }

        my $targetPath = $attrhash->{$pathAttributeID}->{default};
        return packEntityPath($attributes, $targetPath);
    }

    if( (scalar @paths) > $maxPathElements)
    {
        croak("Path elements cannot be greater than $maxPathElements.");
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

#         print STDOUT "id=$simpleType->{enumeration}->{id}\n";
#         print STDOUT "value=$value\n";
        #my %dummy1 = %{$enumeration};
        #foreach (sort keys %dummy1) {
        #    print STDOUT "---$_ : $dummy1{$_}\n";
        #}
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

        my $valueIsNegative = 'false';
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
        elsif ($value =~ m/[^0-9]/)
        {
            # This section is looking for integer values that are incorrectly
            # being interpreted as strings because of their negative sign (-).
            # We ensure that the first thing in the String is a negative sign
            # and that the rest of the String only contains numbers.
            my $negSign = substr($value,0,1);
            my $posVal = substr($value,1);
            if(($negSign eq '-') && ($posVal =~ m/[0-9]/))
            {
                $valueIsNegative = 'true';
            }
        }

        if( ($simpleTypeProperties->{$typeName}{complexTypeSupport}) &&
            ($value =~ m/[^0-9]/) && ($valueIsNegative eq 'false'))
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
    my($attributes,$attribute,$value,$attrhash) = @_;

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
                    my @values;
                    if ($typeName eq "string")
                    {
                        # using "" around strings for array of strings
                        (@values) = $value =~ m/"(.*?)"/g;
                    }
                    else
                    {
                        @values = split(/,/,$value);
                    }
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
            croak("Error requested simple type not supported.  Keys are ("
                . join(',',sort(keys %{$simpleType})) . ")");
        }
    }
    elsif(exists $attribute->{complexType})
    {
        if(ref ($value) eq "HASH" )
        {
            $binaryData = packComplexType($attributes,
                                          $attribute->{complexType},
                                          $value,
                                          $attrhash);
        }
        else
        {
            croak("Warning cannot serialize non-hash complex type.");
        }
    }
    elsif(exists $attribute->{nativeType})
    {
        if($attribute->{nativeType}->{name} eq "EntityPath")
        {
            $binaryData = packEntityPath($attributes,$value,$attrhash);
        }
        else
        {
            croak("Error nativeType not supported on attribute ID = "
                . "$attribute->{id}.");
        }
    }
    else
    {
        croak("Unsupported attribute type on attribute ID = $attribute->{id}.");
    }

    if( (length $binaryData) < 1)
    {
        croak("Serialization failed for attribute ID = $attribute->{id}.");
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
      or croak ("VMM Constants file: \"$vmmConstsFile\" could not be opened.");

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

    close(VMM_CONSTS_FILE);

    if($pnorBaseAddress == 0)
    {
        croak("PNOR base address was zero!");
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
# Write the Attribute Default Values Report
################################################################################
sub generateAttrValuesReport {
    my($attrhash) = @_;

    open(ATTR_DEFAULT_FILE_IMAGE,">$cfgImgOutputDir"."attrDefaultsReport.txt")
      or croak ("Attribute default file: >$cfgImgOutputDir"
        . "attrDefaultsReport.txt could not be opened.");
    my $attrDFile = *ATTR_DEFAULT_FILE_IMAGE;

    my $delim = "----------------------------------------------------------------------------------\n";

    # For each target instance, get the attribute list
    foreach my $targetInstance (sort (keys %$attrhash))
    {
        # A header for each target instance will be printed followed by a list of its
        # attributes in alphabetical order with their default values.
        # The following shows an example with both a simple and a complex type attribute.
        #
        # ----------------------------------------------------------------------------------
        # Target Instance: sys0node0tpm0
        # ----------------------------------------------------------------------------------
        # Attribute ID:                                          Default Value:
        # ----------------------------------------------------------------------------------
        # AFFINITY_PATH                                          affinity:sys-0/node-0/proc-0/tpm-0
        # FSI_OPTION_FLAGS                                       -
        #     Fields:
        #         flipPort                                       0
        #         reserved                                       0

        print $attrDFile $delim, "Target Instance: ", $targetInstance, "\n", $delim;
        printf $attrDFile "Attribute ID: %-41sDefault Value:\n%s", " ", $delim;

        foreach my $targetInstanceAttribute (sort (keys %{$attrhash->{$targetInstance}}))
        {
            my $dValue = $attrhash->{$targetInstance}->{$targetInstanceAttribute}->{default};
            if (ref ($dValue) eq "HASH") #If default is HASH, attr is complex type.
            {
                printf $attrDFile "%-55s-\n", $attrhash->{$targetInstance}->{$targetInstanceAttribute}->{id};
                print $attrDFile "\tFields:\n";
                foreach my $field (@{$dValue->{field}})
                {
                    printf $attrDFile "\t\t%-47s", $field->{id};
                    print $attrDFile $field->{value}, "\n";
                }
            }
            else
            {
                $dValue =~ s/^\s+|\s+$//g;
                printf $attrDFile "%-55s", $attrhash->{$targetInstance}->{$targetInstanceAttribute}->{id};
                print $attrDFile $dValue, "\n";
            }
        }
    }
    close $attrDFile;
}

################################################################################
# Write the PNOR targeting image
################################################################################

sub generateTargetingImage {
    my($vmmConstsFile, $attributes,$Target_t,$addRO_Section_VerPage,
        $allAttributes,$combinedDataRef, $protectedDataRef,
        $unprotectedDataRef) = @_;

    # 128 MB virtual memory offset between sections
    my $vmmSectionOffset = 128 * 1024 * 1024; # 128MB

    my $rwMetadataSize = 0; # The size of the metadata section (calculated later)

    # Virtual memory addresses corresponding to the start of the targeting image
    # PNOR/heap sections
    my $pnorRoBaseAddress    = getPnorBaseAddress($vmmConstsFile);
    my $heapPnorInitBaseAddr = $pnorRoBaseAddress    + $vmmSectionOffset;
    my $heapZeroInitBaseAddr = $heapPnorInitBaseAddr + $vmmSectionOffset;
    my $hbHeapZeroInitBaseAddr = $heapZeroInitBaseAddr + $vmmSectionOffset;
    my $pnorRwBaseAddress    = $hbHeapZeroInitBaseAddr + $vmmSectionOffset;

    # Split "fsp" into additional sections
    my $fspP0DefaultedFromZeroBaseAddr   = $pnorRwBaseAddress + $vmmSectionOffset;
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
        elsif((($targetInstance->{type} eq "enc-node-power8")   ||
               ($targetInstance->{type} eq "enc-node-power9")   ||
               ($targetInstance->{type} eq "enc-node-power10")) && ($targetNodeCnt == 0))
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

    # The metadate for RW attributes
    my $rwAttributeMetadataBinData = "";

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
        my $ptrToPervasiveChildAssociations = INVALID_POINTER;
        my $ptrToParentPervasiveAssociations = INVALID_POINTER;
        my $ptrToOmiChildAssociations = INVALID_POINTER;
        my $ptrToOmicParentAssociations = INVALID_POINTER;
        my $ptrToPaucChildAssociations = INVALID_POINTER;
        my $ptrToPaucParentAssociations = INVALID_POINTER;

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

        $targetAddrHash{$id}{offsetToPtrToPervasiveChildAssociations} =
            $offsetWithinTargets + length $data;
        $data .= pack8byte($ptrToPervasiveChildAssociations);

        $targetAddrHash{$id}{offsetToPtrToParentPervasiveAssociations} =
            $offsetWithinTargets + length $data;
        $data .= pack8byte($ptrToParentPervasiveAssociations);

        $targetAddrHash{$id}{offsetToPtrToOmiChildAssociations} =
            $offsetWithinTargets + length $data;
        $data .= pack8byte($ptrToOmiChildAssociations);

        $targetAddrHash{$id}{offsetToPtrToOmicParentAssociations} =
            $offsetWithinTargets + length $data;
        $data .= pack8byte($ptrToOmicParentAssociations);

        $targetAddrHash{$id}{offsetToPtrToPaucChildAssociations} =
            $offsetWithinTargets + length $data;
        $data .= pack8byte($ptrToPaucChildAssociations);

        $targetAddrHash{$id}{offsetToPtrToPaucParentAssociations} =
            $offsetWithinTargets + length $data;
        $data .= pack8byte($ptrToPaucParentAssociations);

        $targetAddrHash{$id}{ParentByContainmentAssociations} = [@NullPtrArray];
        $targetAddrHash{$id}{ChildByContainmentAssociations} = [@NullPtrArray];
        $targetAddrHash{$id}{ParentByAffinityAssociations} = [@NullPtrArray];
        $targetAddrHash{$id}{ChildByAffinityAssociations} = [@NullPtrArray];
        $targetAddrHash{$id}{PervasiveChildAssociations} = [@NullPtrArray];
        $targetAddrHash{$id}{ParentPervasiveAssociations} = [@NullPtrArray];
        $targetAddrHash{$id}{OmiChildAssociations} = [@NullPtrArray];
        $targetAddrHash{$id}{OmicParentAssociations} = [@NullPtrArray];
        $targetAddrHash{$id}{PaucChildAssociations} = [@NullPtrArray];
        $targetAddrHash{$id}{PaucParentAssociations} = [@NullPtrArray];

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
        ASSOC_DBG("Offset within targets to ptr to pervasive child list = "
        . "$targetAddrHash{$id}{offsetToPtrToPervasiveChildAssociations}");
        ASSOC_DBG("Offset within targets to ptr to parent pervasive list = "
        . "$targetAddrHash{$id}{offsetToPtrToParentPervasiveAssociations}");
        ASSOC_DBG("Offset within targets to ptr to omi child list = "
        . "$targetAddrHash{$id}{offsetToPtrToOmiChildAssociations}");
        ASSOC_DBG("Offset within targets to ptr to omic parent list = "
        . "$targetAddrHash{$id}{offsetToPtrToOmicParentAssociations}");
        ASSOC_DBG("Offset within targets to ptr to Pauc child list = "
        . "$targetAddrHash{$id}{offsetToPtrToPaucChildAssociations}");
        ASSOC_DBG("Offset within targets to ptr to Pauc parent list = "
        . "$targetAddrHash{$id}{offsetToPtrToPaucParentAssociations}");

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

    my %biosData = ();
    # Cache the attribute definitions for all attributes, including virtual
    my %attributeDefCache =
        map { $_->{id} => $_} @{$allAttributes->{attribute}};

    # Cache separate attribute definitions for all non-virtual attributes
    my %attributeDefCacheNoVirtual =
        map { $_->{id} => $_} @{$attributes->{attribute}};

    # For the main loop, use all attributes including virtual
    my $attributeIdEnumerationAll = getAttributeIdEnumeration($allAttributes);

    # The map to collect all of the attribute metadata info
    my %attrMetadataMap = ();

    my %allattrhash; #Hash used to generate attribute report
    foreach my $targetInstance (@targetsAoH)
    {
        #print STDOUT "Target=$targetInstance->{id}\n";
        my $data;
        my %attrhash = ();
        my @AoH = ();

        # Ensure consistent ordering of attributes for each target type
        # Get the attribute list associated with each target type
        #@TODO Attributes must eventually be ordered correctly for code update
        # Use all attributes including virtual for association processing
        getTargetAttributes($targetInstance->{type}, $allAttributes,\%attrhash);

        #Check for Targets with ZERO attributes before writing to PNOR.
        my $tempNumAttributes = keys %attrhash;
        if($tempNumAttributes == 0)
        {
            #skip the present target
            next;
        }

        #print Dumper($allAttributes);

        # Update hash with any per-instance overrides, but only if that
        # attribute has already been defined
        foreach my $targetInstanceAttribute (@{$targetInstance->{attribute}})
        {
            # If the attribute($targetInstanceAttribute->{id}) is defined for
            # the hash ($attrhash) AND the attribute($targetInstanceAttribute)
            # has default data then update the hash.  There is no point in
            # updating the hash if the attribute has nothing to update with and
            # could possibly wipe out a valid default value currently in
            # the hash.
            if ( (exists $attrhash{$targetInstanceAttribute->{id}}) &&
                 (exists $targetInstanceAttribute->{default}) )
            {
                # Determine if the attribute is a complex attribute by probing
                # the default.  If the default is a HASH then this indicates
                # a complex type.
                if (ref ($targetInstanceAttribute->{default}) eq "HASH")
                {
                    # Grab a copy of the attribute data from the hash
                    my $attrData = $attrhash{ $targetInstanceAttribute->{id} };

                    # Merge the two data types into one consolidated data with
                    # the attribute's field defaults replacing the hash's
                    # attribute field data. Leaving any undefined attribute's
                    # field as is (keeping the hash's field data in this case).
                    my $defaultFields = mergeComplexAttributeFields(
                                           $targetInstanceAttribute, $attrData);

                    # Update the hash with the merged data
                    $attrhash{$targetInstanceAttribute->{id}} = $defaultFields;
                }
                else
                # This is a simple type, just set the data
                {
                    $attrhash{ $targetInstanceAttribute->{id} } =
                                                        $targetInstanceAttribute;
                }
            }
            # If the attribute is not defined in the hash, then
            # throw out an error
            elsif ( !exists $attrhash{ $targetInstanceAttribute->{id} } )
            {
                croak("Target instance \"$targetInstance->{id}\" of type \" "
                    . "$targetInstance->{type} \" cannot override attribute "
                    . "\"$targetInstanceAttribute->{id}\" unless the attribute "
                    . "has already been defined in the target type "
                    . "inheritance chain.");
            }
            # If the default tag is missing from an attribute then verify that
            # it is not required to be assigned a default value by the system
            # owner.
            else
            {
                foreach my $attribute_type (@{$allAttributes->{attribute}})
                {
                    if ($attribute_type->{id} eq $targetInstanceAttribute->{id})
                    {
                        if (exists $attribute_type->{mrwRequired})
                        {
                            croak("Error in Target instance "
                               . "\"$targetInstance->{id}\": "
                               . "Attribute \"$attribute_type->{id}\" with tag "
                               . "\"<mrwRequired/>\" is required to have an "
                               . "instance level override from either the MRW "
                               . "or MRW processing tools.");
                        }
                        last;
                    }# end if ($attribute_type->{id} ...
                } # end foreach my $attribute_type ...
            } # end else
        } # end foreach my $targetInstanceAttribute ...

        my $huidValue = $attrhash{HUID}->{default};

        # Flag if target is FSP specific; in that case store all of its
        # attributes in the FSP section, regardless of whether they are
        # themselves FSP specific.  Only need to do this 1x per target instance
        my $fspTarget = isFspTargetInstance($attributes,$targetInstance);

        # Must have the same order as the attribute list from above.
        for my $attributeId
            (sort
                { getAttributeIdHashStr($a) cmp getAttributeIdHashStr($b) }
                (keys %attrhash)
            )
        {
            #print STDOUT "Id=$attributeId\n";

            # Save each target's physical + affinity  + parent pervasive/OMIC/
            # PAUC path for association processing later on
            if(   ($attributeId eq ATTR_PHYS_PATH)
               || ($attributeId eq ATTR_AFFINITY_PATH)
               || ($attributeId eq ATTR_PARENT_PERVASIVE)
               || ($attributeId eq ATTR_OMIC_PARENT)
               || ($attributeId eq ATTR_PAUC_PARENT))
            {
                $targetAddrHash{$targetInstance->{id}}{$attributeId} =
                    $attrhash{$attributeId}->{default};
            }

            # Cache these attributes away in the BIOS data structure as
            # identifying information that will be used to enforce the target
            # restrictions
            if(    ($attributeId eq ATTR_PHYS_PATH)
                || ($attributeId eq ATTR_POSITION )
                || ($attributeId eq ATTR_CHIP_UNIT)
                || ($attributeId eq ATTR_CLASS    )
                || ($attributeId eq ATTR_TYPE     )
                || ($attributeId eq ATTR_MODEL    ) )
            {
                $biosData{$targetInstance->{id}}{_identity_}{$attributeId} =
                     $attrhash{$attributeId}->{default};
            }

            my $attrValue =
            enumNameToValue($attributeIdEnumerationAll,$attributeId);
            $attrValue = sprintf ("%0x", $attrValue);
            my $attributeDef = $attributeDefCache{$attributeId};
            if (not defined $attributeDef)
            {
                croak("Attribute $attributeId is not found.");
            }

            # Do not lay down virtual attributes into the binary
            if(exists $attributeDef->{virtual})
            {
                next
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
                    croak("Persistency '$attributeDef->{persistency}' is not "
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
                    croak("Persistency '$attributeDef->{persistency}' is not "
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
                croak("Persistency '$attributeDef->{persistency}' is not "
                      . "supported for attribute '$attributeId'.");
            }

            my $attributeSize = 0; # The actual size of the attribute as it is packed into the image

            # The persistency of the attribute. This value is being driven by the XML tags for each
            # attribute. The persistency value assigned to each attribute matches the SECTION_TYPE
            # enum in obj/genfiles/pnortargeting.H (also generated by this script).
            my $attributePersistency = SECTION_TYPE_BAD_VALUE;

            if($section eq "pnor-ro")
            {
                if ((exists ${$Target_t}{$attributeId}) &&
                    ($attrhash{$attributeId}->{default} != 0))
                {
                    my $index = $attrhash{$attributeId}->{default} - 1;

                    # Each target is 4 bytes # attributes, 8 bytes pointer
                    # to attribute list, 8 bytes pointer to attribute pointer
                    # list, num associations x 8 byte pointers to association lists

                    # length(double + quad + quad + # associations x quad)
                    $index *= (20 + 8 * (scalar @associationTypes));
                    $attrhash{$attributeId}->{default} = $index + $firstTgtPtr;
                }

                my ($rodata,$alignment) = packAttribute($attributes,
                                                        $attributeDef,
                                                        $attrhash{$attributeId}->{default},
                                                        \%attrhash);

                # Align the data as necessary
                my $pads = ($alignment - ($offset % $alignment))
                    % $alignment;
                $roAttrBinData .= pack ("@".$pads);
                $offset += $pads;

                $attributePointerBinData .= pack8byte(
                    $offset + $pnorRoBaseAddress);

                $offset += (length $rodata);

                $roAttrBinData .= $rodata;

                $attributeSize = length($rodata);
                $attributePersistency = SECTION_TYPE_PNOR_RO;
            }
            elsif($section eq "pnor-rw")
            {
                my ($rwdata,$alignment) = packAttribute($attributes,
                                                        $attributeDef,
                                                        $attrhash{$attributeId}->{default},
                                                        \%attrhash);

                #print "Wrote to pnor-rw value ",$attributeDef->{id}, ",", $attrhash{$attributeId}->{default}," \n";

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
                $attributeSize = length($rwdata);
                $attributePersistency = SECTION_TYPE_PNOR_RW;

            }
            elsif($section eq "heap-zero-initialized")
            {
                my ($heapZeroInitData,$alignment) = packAttribute($attributes,
                                                                  $attributeDef,
                                                                  $attrhash{$attributeId}->{default},
                                                                  \%attrhash);

                $biosData{$targetInstance->{id}}{$attributeId}{size} =
                    (length $heapZeroInitData);
                $biosData{$targetInstance->{id}}{$attributeId}{default} =
                    $attrhash{$attributeId}->{default};

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
                $attributeSize = length($heapZeroInitData);
                $attributePersistency = SECTION_TYPE_HEAP_ZERO_INIT;

            }
            elsif($section eq "heap-pnor-initialized")
            {
                my ($heapPnorInitData,$alignment) = packAttribute($attributes,
                                                                  $attributeDef,
                                                                  $attrhash{$attributeId}->{default},
                                                                  \%attrhash);

                $biosData{$targetInstance->{id}}{$attributeId}{size} =
                    (length $heapPnorInitData);
                $biosData{$targetInstance->{id}}{$attributeId}{default} =
                    $attrhash{$attributeId}->{default};

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
                $attributeSize = length($heapPnorInitData);
                $attributePersistency = SECTION_TYPE_HEAP_PNOR_INIT;

            }
            # Split FSP section into more granular sections
            elsif($section eq "fspP0DefaultedFromZero")
            {
                my ($fspP0ZeroData,$alignment) = packAttribute($attributes,
                                                               $attributeDef,
                                                               $attrhash{$attributeId}->{default},
                                                               \%attrhash);

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
                $attributeSize = length($fspP0ZeroData);
                $attributePersistency = SECTION_TYPE_FSP_P0_ZERO_INIT;
            }
            elsif($section eq "fspP0DefaultedFromP3")
            {
                my ($fspP0FlashData,$alignment) = packAttribute($attributes,
                                                                $attributeDef,
                                                                $attrhash{$attributeId}->{default},
                                                                \%attrhash);

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
                $attributeSize = length($fspP0FlashData);
                $attributePersistency = SECTION_TYPE_FSP_P0_FLASH_INIT;
            }
            elsif($section eq "fspP3Ro")
            {
                my ($fspP3RoData,$alignment) = packAttribute($attributes,
                                                             $attributeDef,
                                                             $attrhash{$attributeId}->{default},
                                                             \%attrhash);

                # Align the data as necessary
                my $pads = ($alignment - ($fspP3RoOffset
                            % $alignment)) % $alignment;
                $fspP3RoBinData .= pack ("@".$pads);
                $fspP3RoOffset += $pads;

                $attributePointerBinData .= pack8byte(
                    $fspP3RoOffset + $fspP3RoBaseAddr);

                $fspP3RoOffset += (length $fspP3RoData);

                $fspP3RoBinData .= $fspP3RoData;
                $attributeSize = length($fspP3RoData);
                $attributePersistency = SECTION_TYPE_FSP_P3_RO;
            }
            elsif($section eq "fspP3Rw")
            {
                my ($fspP3RwData,$alignment) = packAttribute($attributes,
                                                             $attributeDef,
                                                             $attrhash{$attributeId}->{default},
                                                             \%attrhash);

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
                $attributeSize = length($fspP3RwData);
                $attributePersistency = SECTION_TYPE_FSP_P3_RW;
            }
            elsif($section eq "fspP1DefaultedFromZero")
            {
                my ($fspP1ZeroData,$alignment) = packAttribute($attributes,
                                                               $attributeDef,
                                                               $attrhash{$attributeId}->{default},
                                                               \%attrhash);

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
                $attributeSize = length($fspP1ZeroData);
                $attributePersistency = SECTION_TYPE_FSP_P1_ZERO_INIT;
            }
            elsif($section eq "fspP1DefaultedFromP3")
            {
                my ($fspP1FlashData,$alignment) = packAttribute($attributes,
                                                                $attributeDef,
                                                                $attrhash{$attributeId}->{default},
                                                                \%attrhash);

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
                $attributeSize = length($fspP1FlashData);
                $attributePersistency = SECTION_TYPE_FSP_P1_FLASH_INIT;
            }
            # Hostboot specific section
            elsif($section eq "hb-heap-zero-initialized")
            {
                my ($hbHeapZeroInitData,$alignment) = packAttribute($attributes,
                                                                    $attributeDef,
                                                                    $attrhash{$attributeId}->{default},
                                                                    \%attrhash);

                $biosData{$targetInstance->{id}}{$attributeId}{size} =
                    (length $hbHeapZeroInitData);
                $biosData{$targetInstance->{id}}{$attributeId}{default} =
                    $attrhash{$attributeId}->{default};

                # Align the data as necessary
                my $pads = ($alignment - ($hbHeapZeroInitOffset
                            % $alignment)) % $alignment;
                $hbHeapZeroInitBinData .= pack ("@".$pads);
                $hbHeapZeroInitOffset += $pads;

                $attributePointerBinData .= pack8byte(
                    $hbHeapZeroInitOffset + $hbHeapZeroInitBaseAddr);

                $hbHeapZeroInitOffset += (length $hbHeapZeroInitData);

                $hbHeapZeroInitBinData .= $hbHeapZeroInitData;
                $attributeSize = length($hbHeapZeroInitData);
                $attributePersistency = SECTION_TYPE_HB_HEAP_ZERO_INIT;
            }

            else
            {
                croak("Could not find a suitable section.");
            }

            # If this is an attribute we haven't seen before, add it to the
            # metadata map and metadata section.
            my $attrIdHash = hex(getAttributeIdHashStr($attributeId));
            if( (not exists $attrMetadataMap{$attrIdHash} )  &&
                ($attributePersistency eq SECTION_TYPE_PNOR_RW) )
            {
                $attrMetadataMap{$attrIdHash}{exists} = 1;
                # Write the metadata for the current attribute into the metadata section
                $rwAttributeMetadataBinData .= pack4byte($attrIdHash);
                $rwAttributeMetadataBinData .= pack4byte($attributeSize);
                $rwAttributeMetadataBinData .= pack1byte($attributePersistency);
            }

            $attributesWritten++;

        } # End attribute loop

        #Add attribute list for current Target Instance
        $allattrhash{$targetInstance->{id}} = \%attrhash;

    } # End target instance loop

    generateAttrValuesReport(\%allattrhash);

    # The number of attributes in the metadata section is packed in 4 bytes
    # (uint32_t). Include that size in the total size of the metadata section.
    use constant NUM_ATTR_SIZE => 4;

    $rwMetadataSize = length($rwAttributeMetadataBinData) + NUM_ATTR_SIZE;

    if($numAttributes != $attributesWritten)
    {
        croak("Number of attributes expected, $numAttributes, does not match "
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
        my $parent_pervasive = ATTR_PARENT_PERVASIVE;
        my $omic_parent = ATTR_OMIC_PARENT;
        my $pauc_parent = ATTR_PAUC_PARENT;

        my $phys_path = $targetAddrHash{$id}{$phys_attr};
        my $parent_phys_path = substr $phys_path, 0, (rindex $phys_path, "/");

        my $affn_path = $targetAddrHash{$id}{$affn_attr};
        my $parent_affn_path = substr $affn_path, 0, (rindex $affn_path, "/");

        # If this target has an associated OMIC target, create a
        # bidirectional relationship between this target and the specified
        # OMIC target.  This target will point to the OMIC target via
        # a "OMIC_PARENT" association, and the pervasive target will
        # point to this target via a "OMI_CHILD" association.
        if(defined $targetAddrHash{$id}{$omic_parent})
        {
            my $parent_omic_path =
                $targetAddrHash{$id}{$omic_parent};

            if(defined $targetPhysicalPath{$parent_omic_path})
            {
                my $parent = $targetPhysicalPath{$parent_omic_path};
                unshift
                    @ { $targetAddrHash{$id}
                        {OmicParentAssociations} },
                    $firstTgtPtr + $targetAddrHash{$parent}
                {OffsetToTargetWithinTargetList};

                unshift
                    @ { $targetAddrHash{$parent}
                        {OmiChildAssociations} },
                    $firstTgtPtr + $targetAddrHash{$id}
                {OffsetToTargetWithinTargetList};
            }
        }

        # If this target has an associated PAUC target, create a
        # bidirectional relationship between this target and the specified
        # PAUC target.  This target will point to the PAUC target via
        # a "PAUC_PARENT" association, and the PAUC target will
        # point to this target (OMIC) via a "PAUC_CHILD" association.
        if(defined $targetAddrHash{$id}{$pauc_parent})
        {
            my $parent_pauc_path =
                $targetAddrHash{$id}{$pauc_parent};

            if(defined $targetPhysicalPath{$parent_pauc_path})
            {
                my $parent = $targetPhysicalPath{$parent_pauc_path};
                unshift
                    @ { $targetAddrHash{$id}
                        {PaucParentAssociations} },
                    $firstTgtPtr + $targetAddrHash{$parent}
                {OffsetToTargetWithinTargetList};

                unshift
                    @ { $targetAddrHash{$parent}
                        {PaucChildAssociations} },
                    $firstTgtPtr + $targetAddrHash{$id}
                {OffsetToTargetWithinTargetList};
            }
        }

        # If this target has an associated pervasive target, create a
        # bidirectional relationship between this target and the specified
        # pervasive target.  This target will point to the pervasive target via
        # a "PARENT_PERVASIVE" association, and the pervasive target will
        # point to this target via a "PERVASIVE_CHILD" association.
        if (defined $targetAddrHash{$id}{$parent_pervasive})
        {
            my $parent_pervasive_path =
                $targetAddrHash{$id}{$parent_pervasive};

            if(defined $targetPhysicalPath{$parent_pervasive_path})
            {
                my $parent = $targetPhysicalPath{$parent_pervasive_path};
                unshift
                    @ { $targetAddrHash{$id}
                        {ParentPervasiveAssociations} },
                    $firstTgtPtr + $targetAddrHash{$parent}
                {OffsetToTargetWithinTargetList};

                unshift
                    @ { $targetAddrHash{$parent}
                        {PervasiveChildAssociations} },
                    $firstTgtPtr + $targetAddrHash{$id}
                {OffsetToTargetWithinTargetList};
            }
        }

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
    $sectionHoH{ pnorRo }{ type   } = SECTION_TYPE_PNOR_RO;
    $sectionHoH{ pnorRo }{ size   } = sizeBlockAligned($offset,$blockSize,1);

    $sectionHoH{ heapPnorInit }{ offset } = $sectionHoH{pnorRo}{offset}
                                            + $sectionHoH{pnorRo}{size};
    $sectionHoH{ heapPnorInit }{ type   } = SECTION_TYPE_HEAP_PNOR_INIT;
    $sectionHoH{ heapPnorInit }{ size   } =
        sizeBlockAligned($heapPnorInitOffset,$blockSize,1);

    $sectionHoH{ heapZeroInit }{ offset } = $sectionHoH{heapPnorInit}{offset}
                                            + $sectionHoH{heapPnorInit}{size};
    $sectionHoH{ heapZeroInit }{ type   } = SECTION_TYPE_HEAP_ZERO_INIT;
    $sectionHoH{ heapZeroInit }{ size   } =
        sizeBlockAligned($heapZeroInitOffset,$blockSize,1);

    # zeroInitSection occupies no space in the binary, so set the
    # Hostboot section address to that of the zeroInitSection
    $sectionHoH{ hbHeapZeroInit }{ offset } = $sectionHoH{heapZeroInit}{offset};
    $sectionHoH{ hbHeapZeroInit }{ type } = SECTION_TYPE_HB_HEAP_ZERO_INIT;
    $sectionHoH{ hbHeapZeroInit }{ size } =
        sizeBlockAligned($hbHeapZeroInitOffset,$blockSize,1);

    $sectionHoH{ pnorRw }{ offset } = $sectionHoH{hbHeapZeroInit}{offset};
    $sectionHoH{ pnorRw }{ type   } = SECTION_TYPE_PNOR_RW;
    $sectionHoH{ pnorRw }{ size   } = sizeBlockAligned($rwOffset,$blockSize,1);

    my $metadataSectionOffset = $sectionHoH{pnorRw}{offset} + $sectionHoH{pnorRw}{size};

    # Split "fsp" into additional sections
    if($cfgIncludeFspAttributes)
    {
        # zeroInitSection occupies no space in the binary, so set the FSP
        # section address to that of the zeroInitSection
        $sectionHoH{ fspP0DefaultedFromZero }{ offset } =
             $sectionHoH{pnorRw}{offset} + $sectionHoH{pnorRw}{size};
        $sectionHoH{ fspP0DefaultedFromZero }{ type } = SECTION_TYPE_FSP_P0_ZERO_INIT;
        $sectionHoH{ fspP0DefaultedFromZero }{ size } =
            sizeBlockAligned($fspP0DefaultedFromZeroOffset,$blockSize,1);

        $sectionHoH{ fspP0DefaultedFromP3 }{ offset } =
             $sectionHoH{fspP0DefaultedFromZero}{offset} +
             $sectionHoH{fspP0DefaultedFromZero}{size};
        $sectionHoH{ fspP0DefaultedFromP3 }{ type } = SECTION_TYPE_FSP_P0_FLASH_INIT;
        $sectionHoH{ fspP0DefaultedFromP3 }{ size } =
            sizeBlockAligned($fspP0DefaultedFromP3Offset,$blockSize,1);

        $sectionHoH{ fspP3Ro }{ offset } =
             $sectionHoH{fspP0DefaultedFromP3}{offset} +
             $sectionHoH{fspP0DefaultedFromP3}{size};
        $sectionHoH{ fspP3Ro }{ type } = SECTION_TYPE_FSP_P3_RO;
        $sectionHoH{ fspP3Ro }{ size } =
            sizeBlockAligned($fspP3RoOffset,$blockSize,1);

        $sectionHoH{ fspP3Rw }{ offset } =
             $sectionHoH{fspP3Ro}{offset} + $sectionHoH{fspP3Ro}{size};
        $sectionHoH{ fspP3Rw }{ type } = SECTION_TYPE_FSP_P3_RW;
        $sectionHoH{ fspP3Rw }{ size } =
            sizeBlockAligned($fspP3RwOffset,$blockSize,1);

        $sectionHoH{ fspP1DefaultedFromZero }{ offset } =
             $sectionHoH{fspP3Rw}{offset} + $sectionHoH{fspP3Rw}{size};
        $sectionHoH{ fspP1DefaultedFromZero }{ type } = SECTION_TYPE_FSP_P1_ZERO_INIT;
        $sectionHoH{ fspP1DefaultedFromZero }{ size } =
            sizeBlockAligned($fspP1DefaultedFromZeroOffset,$blockSize,1);

        $sectionHoH{ fspP1DefaultedFromP3 }{ offset } =
             $sectionHoH{fspP1DefaultedFromZero}{offset} +
             $sectionHoH{fspP1DefaultedFromZero}{size};
        $sectionHoH{ fspP1DefaultedFromP3 }{ type } = SECTION_TYPE_FSP_P1_FLASH_INIT;
        $sectionHoH{ fspP1DefaultedFromP3 }{ size } =
            sizeBlockAligned($fspP1DefaultedFromP3Offset,$blockSize,1);

        $metadataSectionOffset = $sectionHoH{fspP1DefaultedFromP3}{offset} + $sectionHoH{fspP1DefaultedFromP3}{size};
    }

    $sectionHoH{ pnorRwMetadata }{ offset } = $metadataSectionOffset;
    $sectionHoH{ pnorRwMetadata }{ type } = SECTION_TYPE_HB_METADATA;
    $sectionHoH{ pnorRwMetadata }{ size } =
        sizeBlockAligned($rwMetadataSize,$blockSize,1);

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
    my @sections = ("pnorRo","heapPnorInit","heapZeroInit", "hbHeapZeroInit", "pnorRw");
    if($cfgIncludeFspAttributes)
    {
        push(@sections,"fspP0DefaultedFromZero");
        push(@sections,"fspP0DefaultedFromP3");
        push(@sections,"fspP3Ro");
        push(@sections,"fspP3Rw");
        push(@sections,"fspP1DefaultedFromZero");
        push(@sections,"fspP1DefaultedFromP3");
    }

    # pnorRwMetadata section will always be included. Push it here so that it's included
    # in the header last, just like it would be in the HBD image
    push(@sections,"pnorRwMetadata");

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
        croak("Header data of length " . (length $headerBinData) . " is larger "
            . "than allocated amount of $headerSize.");
    }

    # Handle splitting up data into different files for secure signing purposes
    my $outFile;

    #HB Targeting binary file will contain <Version Page>+<Targeting Header>+
    #<Section  data>...
    if ($addRO_Section_VerPage == 1)
    {
        #Generate the MD5 checksum value for the read-only data and update the
        #content of the version section
        my $md5hex = Digest::MD5->new;
        $md5hex->add($numTargetsPointerBinData);
        $md5hex->add($attributeListBinData);
        $md5hex->add($attributePointerBinData);
        $md5hex->add($numTargetsBinData);
        $md5hex->add($targetsBinData);
        $md5hex->add($roAttrBinData);
        $md5hex->add($associationsBinData);
        $md5hex->add($heapPnorInitBinData);
        $md5hex->add($rwAttributeMetadataBinData);

        my $versionHeader = "VERSION\0";
        $versionHeader .= $md5hex->hexdigest;

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

    # Serialize PNOR initiated heap section to multiple of 4k page size (pad if
    # necessary)
    $outFile .= $heapPnorInitBinData;
    $outFile .= pack("@".($sectionHoH{heapPnorInit}{size}
        - $heapPnorInitOffset));

    # Handle read-only data
    ${$protectedDataRef} = $outFile;
    ${$combinedDataRef} = $outFile;
    $outFile = "";

    # Serialize PNOR RW section to multiple of 4k page size (pad if necessary)
    $outFile .= $rwAttrBinData;
    $outFile .= pack("@".($sectionHoH{pnorRw}{size} - $rwOffset));

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

    $outFile .= pack4byte(scalar keys %attrMetadataMap);
    $outFile .= $rwAttributeMetadataBinData;
    $outFile .= pack("@".($sectionHoH{pnorRwMetadata}{size} - $rwMetadataSize));

    # Handle read-write data
    ${$unprotectedDataRef} = $outFile;
    ${$combinedDataRef} .= $outFile;

    if(defined $cfgBiosXmlFile)
    {
        unless (-e $cfgBiosXmlFile)
        {
            croak("BIOS XML file $cfgBiosXmlFile does not exist.\n");
        }

        unless (defined $cfgBiosSchemaFile)
        {
            croak("BIOS XML file $cfgBiosXmlFile specified, but a BIOS schema "
                . "file was not.\n");
        }

        unless (-e $cfgBiosSchemaFile)
        {
            croak("BIOS schema file $cfgBiosSchemaFile does not exist.\n");
        }

        unless (defined $cfgBiosOutputFile)
        {
            croak("BIOS output file not specified.\n");
        }

        my $bios = new
            Bios($cfgBiosXmlFile,$cfgBiosSchemaFile,$cfgBiosOutputFile);
        $bios->load();
        $bios->processBios(
            \%attributeDefCacheNoVirtual,\$attributes,
            \%biosData,%targetPhysicalPath);
        $bios->export();
    }

    return $outFile;
}

sub generateXMLforSM {

    open(SM_TARGET_FILE,">".$CfgSMAttrFile)
        or croak ("Targeting SM file: $CfgSMAttrFile "
            . "could not be opened.");
    my $Count = @attrDataforSM;

print SM_TARGET_FILE "
<attributes>";
    for (my $i = 0; $i < $Count; $i++)
    {
        if ($attrDataforSM[$i][ATTRNAME] ~~ @nonSyncAttributes)
        {
            next;
        }

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

################################################################################
# BIOS Package
#    Consumes platform-specific BIOS XML file, validates it, and outputs
#    extended data on the attributes, which will be transformed (via xslt
#    stylesheets) and used by 3rd parties (like Petitboot).  The BIOS
#    package validates the input file against a stylesheet to ensure
#    proper formatting.
################################################################################

{

package Bios;

################################################################################
# Constructor; create a new Bios object
################################################################################

sub new
{
    my ($class,$biosInputXmlFile,$biosSchemaXsdFile,$biosOutputXmlFile) = @_;
    my $self = {
        _biosInputXmlFile => $biosInputXmlFile,
        _libXmlParser => XML::LibXML->new(),
        _biosXmlDoc => undef,
        _biosSchemaXsdFile => $biosSchemaXsdFile,
        _biosOutputXmlFile => $biosOutputXmlFile,
    };

    bless $self, $class;

    return $self;
}

################################################################################
# Load and parse the BIOS XML data, then validate it
################################################################################

sub load
{
    my ($self) = @_;
    my $biosSchemaXsd = undef;

    eval
    {
        $self->{_biosXmlDoc} =
            $self->{_libXmlParser}->parse_file($self->{_biosInputXmlFile});
    };

    croak ("Failed to parse BIOS file [$self->{_biosInputXmlFile}].\n"
        . " Reason: $@") if $@;

    eval
    {
        $biosSchemaXsd =
            XML::LibXML::Schema->new(location => $self->{_biosSchemaXsdFile} );
    };

    croak ("Failed to load valid schema [$self->{_biosSchemaXsdFile}].\n"
        . "Reason: $@") if $@;

    eval
    {
        $biosSchemaXsd->validate($self->{_biosXmlDoc})
    };

    croak ("Failed to validate [$self->{_biosInputXmlFile}] "
        . "using schema [$self->{_biosSchemaXsdFile}].\n"
        . "Reason: $@") if $@;
}

################################################################################
# Export the working version of the BIOS document to a file our STDOUT
################################################################################

sub export
{
    my ($self,$forceStdout) = @_;

    if(defined $forceStdout
        && ($forceStdout == 1))
    {
        print STDOUT "In-memory BIOS XML dump:\n";
        print STDOUT $self->{_biosXmlDoc}->toString();
    }
    else
    {
        open(OUTPUT_XML,">$self->{_biosOutputXmlFile}") or
            croak("Could not open output BIOS XML file "
                . "[$self->{_biosOutputXmlFile}] for writing.\n"
                . "Reason: $!");

        print OUTPUT_XML $self->{_biosXmlDoc}->toString() or
            croak ("Failed write output BIOS XML file "
                . "[$self->{_biosOutputXmlFile}].\n"
                . "Reason: $!");

        close OUTPUT_XML or
            croak ("Failed to close output BIOS XML file "
                . "[$self->{_biosOutputXmlFile}].\n"
                . "Reason: $!");
    }
}

################################################################################
# Create child element in BIOS XML tree and return it
################################################################################

sub createChildElement()
{
    my ($self,$parent,$name,$value) = @_;

    my $child = XML::LibXML::Element->new($name);

    # Value is optional parameter; if not specified, only the child container
    # element is created
    if(defined $value)
    {
        $child->appendTextNode($value);
    }
    $parent->addChild($child);

    return $child;
}

################################################################################
# Validate any constraint not enforced by the schema and amend the XML tree
################################################################################

sub processBios
{
    my($self,$attrMapRef,$attributesRef,$instanceRef,%targetPhysicalPath) = @_;

    use bigint;

    my %attrTargAttrSetByBios = ();

    # Process all attribute elements regardless of tree location
    foreach my $attribute ($self->{_biosXmlDoc}->findnodes('//attribute'))
    {
        my($id) = $attribute->findnodes('./id');
        my $attributeId =  $id->to_literal;

        # Attribute must be defined in targeting
        if(!exists $attrMapRef->{$attributeId})
        {
            croak("BIOS definition specified attribute $attributeId, but "
                . "that attribute is not defined in targeting.\n");
        }

        # Attribute must have volatile persistency
        if($attrMapRef->{$attributeId}{persistency} ne "volatile"
             && $attrMapRef->{$attributeId}{persistency} ne "volatile-zeroed")
        {
            croak("BIOS definition specified attribute $attributeId, but "
                . "that attribute is neither volatile nor volatile-zeroed "
                . "in targeting.  Actual persistency is "
                . "$attrMapRef->{$attributeId}{persistency}.\n");
        }

        # Attribute must be read only
        my $readable = exists $attrMapRef->{$attributeId}{readable} ? 1 : 0;
        my $writeable = exists $attrMapRef->{$attributeId}{writeable} ? 1 : 0;
        if(!$readable || $writeable)
        {
            croak("BIOS definition specified attribute $attributeId, but "
                . "that attribute is not read-only in targeting.  "
                . "Readable? " . $readable
                . " writeable? " . $writeable . "\n");
        }

        # Attribute must not be an FSP-only attribute
        my $fspOnly = exists $attrMapRef->{$attributeId}{fspOnly} ? 1 : 0;
        if($fspOnly)
        {
            croak("BIOS definition specified attribute $attributeId, but "
                . "that attribute is FSP only in targeting.\n");
        }

        # Attribute must be an allowed type -and- supported by the BIOS code
        # Current support is for signed/unsigned ints (1,2,4,8 bytes in size)
        # and enumerations
        my $simpleType = exists $attrMapRef->{$attributeId}{simpleType} ? 1 : 0;
        my $complexType =
            exists $attrMapRef->{$attributeId}{complexType} ? 1 : 0;
        my $nativeType = exists $attrMapRef->{$attributeId}{nativeType} ? 1 : 0;
        if(!$simpleType)
        {
            croak("BIOS definition specified attribute $attributeId, but "
                . "that attribute is not a simple type in targeting.  "
                . "Complex type? $complexType, native type? $nativeType.\n");
        }

        # Defines which attributes can be put in the BIOS and provides
        # associated BIOS type hint for 3rd party consumer
        my %typeHash = ();

        $typeHash{"int8_t"} =
             { generalType => 'signed',
               min         => -128,
               max         => 127,
               ror         => 1,
             };
        $typeHash{"int16_t"} =
             { generalType => 'signed',
               min         => -32768,
               max         => 32767,
               ror         => 1,
             };
        $typeHash{"int32_t"} =
             { generalType => 'signed',
               min         => -2147483648,
               max         => 2147483647,
               ror         => 1,
             };
        $typeHash{"int64_t"} =
             { generalType => 'signed',
               min         => -9223372036854775808,
               max         => 9223372036854775807,
               ror         => 1,
             };
        $typeHash{"uint8_t"} =
             { generalType => 'unsigned',
               min         => 0,
               max         => 255,
               ror         => 1,
              };
        $typeHash{"uint16_t"} =
             { generalType => 'unsigned',
               min         => 0,
               max         => 65535,
               ror         => 1,
             };
        $typeHash{"uint32_t"} =
             { generalType => 'unsigned',
               min         => 0,
               max         => 4294967295,
               ror         => 1,
             };
        $typeHash{"uint64_t"} =
             { generalType => 'unsigned',
               min         => 0,
               max         => 18446744073709551615,
               ror         => 1,
             };
        $typeHash{"enumeration"} =
             { generalType => 'unsigned',
               min         => 'na',
               max         => 'na',
               ror         => 1,
             };

        my $validType = 0;
        my $attrType = "unknown";
        # Convert actual type into a generalized type hint for the BIOS consumer
        # and append to the XML tree
        foreach my $type (keys %typeHash)
        {
            if(exists $attrMapRef->{$attributeId}{simpleType}{$type})
            {
                $self->createChildElement($attribute,"encoding",
                    $typeHash{$type}{generalType});
                $attrType = $type;
                $validType = 1;
                last;
            }
        }
        if(!$validType)
        {
            croak("BIOS definition specified attribute $attributeId, but "
                . "that attribute's type is not supported in BIOS context. "
                . "Dump of type:\n"
                . ::Dumper($attrMapRef->{$attributeId}{simpleType}) . "\n");
        }

        # Simple type must not be array
        if(exists $attrMapRef->{$attributeId}{simpleType}{array})
        {
            croak("BIOS definition specified attribute $attributeId, but "
                . "that attribute is an array which is not supported in "
                . "BIOS context.\n");
        }

        # If attribute definition doesn't have a short name, it must be
        # overridden by the BIOS config.  Add final value to the XML tree
        my($displayNameNodes) = $attribute->findnodes('./display-name');
        if(!$displayNameNodes)
        {
            if(exists $attrMapRef->{$attributeId}{'display-name'})
            {
                $self->createChildElement(
                    $attribute,"display-name",
                    $attrMapRef->{$attributeId}{'display-name'});
            }
            else
            {
                croak("BIOS definition specified attribute $attributeId, "
                    . "but attribute definition does not give a display name, "
                    . "so BIOS config must (but failed to do so).\n");
            }
        }

        # If attribute definition doesn't have a description, it must be
        # overridden by the BIOS config.  Add final value to the XML tree
        my($descriptionNodes) = $attribute->findnodes('./description');
        if(!$descriptionNodes)
        {
            if(exists $attrMapRef->{$attributeId}{description})
            {
               $self->createChildElement(
                    $attribute,"description",
                    $attrMapRef->{$attributeId}{description});
            }
            else
            {
                croak("BIOS definition specified attribute $attributeId, "
                    . "but attribute definition does not give a description, "
                    . "so BIOS config must (but failed to do so).\n");
            }
        }

        my $default = undef;
        my $size = undef;
        my @targetRestrictions = $attribute->findnodes('./targetRestriction');

        # Assume all targets have this BIOS attribute to begin with, then prove
        # otherwise during processing
        my %filteredTargets = %$instanceRef;
        foreach my $target (keys %filteredTargets)
        {
            $filteredTargets{$target}{_allowed_} = 1;
        }

        # Hold the target override data
        my %restriction = ();
        $restriction{node} = 0x0F; # FAPI override value = any position
        $restriction{position} = 0xFFFF; # FAPI override value = any position
        $restriction{unit} = 0xFF; # FAPI override value = any unit
        $restriction{symbolicType} = "*"; # Easy to understand target type
        $restriction{numericType} = 0x0; # FAPI type indicator; 0 = any

        # Scan target restriction(s).  If no restriction, the BIOS attribute
        # must have same default for all instances.  If target restriction, all
        # attributes that are grouped by the restriction must have the same
        # default value.
        if(scalar @targetRestrictions > 0)
        {
            my $restrictNode = "*";
            my $restrictPos  = "*"; # NA except for things with positions
                                    # including units
            my $restrictUnit = "*"; # NA except for units
            my $restrictType = "*";

            # By default, a BIOS setting applies to every target the attribute
            # is assigned to in targeting.  However, a target restriction can
            # restrict an attribute to one or more subsets of those.  The set of
            # targets tied to same BIOS attribute+restriction cannot intersect
            # with any other similar grouping.  Further, all attributes of
            # same type tied to same BIOS attribute via the restriction must
            # have same default value.  Only one target restriction allowed by
            # the schema
            foreach my $targetRestriction (@targetRestrictions)
            {
                # Schema validation doesn't easily force targetRestrictions to
                # have at least one child, so bail if that's the case
                my @childElements = $targetRestriction->findnodes('./*');
                if(scalar @childElements == 0)
                {
                    croak("BIOS definition specified attribute "
                        . "$attributeId, but requested targetRestriction with "
                        . "no parameters.\n");
                }

                my @nodeElements = $targetRestriction->findnodes('./node');
                my @positionElements
                    = $targetRestriction->findnodes('./position');
                my @unitElements = $targetRestriction->findnodes('./unit');
                my @typeElements = $targetRestriction->findnodes('./type');

                if(scalar @nodeElements)
                {
                    $restriction{node} = $nodeElements[0]->to_literal;
                }

                if(scalar @positionElements)
                {
                    $restriction{position} = $positionElements[0]->to_literal;
                }

                if(scalar @unitElements)
                {
                    $restriction{unit} = $unitElements[0]->to_literal;
                }

                # If any type restriction, verify it is a valid type designator
                # any hold onto the numeric ID which will end up in the XML tree
                if(scalar @typeElements)
                {
                    my $symbolicType = $typeElements[0]->to_literal;
                    my $typeEnumDef =
                        ::getEnumerationType($$attributesRef,"TYPE");
                    my $numericType =
                        ::enumNameToValue($typeEnumDef,$symbolicType);

                    $restriction{numericType} = $numericType;
                    $restriction{symbolicType} = $symbolicType;
                }

                # Compute the affected targets
                foreach my $target (keys %filteredTargets)
                {
                    if(scalar @typeElements > 0)
                    {
                        $restrictType = $typeElements[0]->to_literal;

                        # Screen out targets that don't match the given type
                        if($filteredTargets{$target}{_allowed_} == 1)
                        {
                            my $type =
                                $filteredTargets{$target}{_identity_}{TYPE};
                            if($restrictType ne $type
                                && $filteredTargets{$target}{_allowed_} == 1)
                            {
                                $filteredTargets{$target}{_allowed_} = 0;
                                next;
                            }
                        }
                    }

                    if(scalar @nodeElements > 0)
                    {
                        $restrictNode = $nodeElements[0]->to_literal;

                        # Screen out targets that don't match the given node.
                        # A target matches the node restriction if its physical
                        # path contains the same node ID.
                        my $isInSameNodeExpr =
                            quotemeta "physical:sys-0/node-$restrictNode" ;
                        my $path =
                            $filteredTargets{$target}{_identity_}{PHYS_PATH};

                        if($path !~ m/^$isInSameNodeExpr/)
                        {
                            $filteredTargets{$target}{_allowed_} = 0;
                            next;
                        }
                    }

                    if(scalar @unitElements > 0)
                    {
                        $restrictUnit = $unitElements[0]->to_literal;

                        my $checkPosition = 0;

                        # Screen out targets that do not have unit attributes,
                        # or which have non-matching unit attributes
                        if(   (!exists
                               $filteredTargets{$target}{_identity_}{CHIP_UNIT})
                           || ($filteredTargets{$target}{_identity_}{CHIP_UNIT}
                               != $restrictUnit)   )
                        {
                            $filteredTargets{$target}{_allowed_} = 0;
                            next;
                        }
                        else
                        {
                            $checkPosition = 1;
                        }

                        # If unit matches, need to make sure it also sits on
                        # chip at requested position, if specified
                        if($checkPosition && ((scalar @positionElements) > 0))
                        {
                            my $candidatePath =
                               $filteredTargets{$target}{_identity_}{PHYS_PATH};

                            my $parent_phys_path = substr(
                                $candidatePath, 0,(rindex $candidatePath, "/"));
                            my $foundPosition = 0;

                            # Walk from unit to whatever parent has the position
                            # attribute; Remove this target from consideration
                            # if the position does not match the restriction
                            while(
                                defined $targetPhysicalPath{$parent_phys_path})
                            {
                                if(defined $filteredTargets{
                                       $targetPhysicalPath{$parent_phys_path}
                                   }{_identity_}{POSITION})
                                {
                                    if ($filteredTargets{
                                          $targetPhysicalPath{$parent_phys_path}
                                        }{_identity_}{POSITION}
                                        == $positionElements[0]->to_literal)
                                    {
                                        $foundPosition = 1;
                                    }

                                    last;
                                }

                                $candidatePath = $parent_phys_path;
                                $parent_phys_path = substr(
                                    $candidatePath, 0,
                                    (rindex $candidatePath, "/"));
                            }

                            if(!$foundPosition)
                            {
                                $filteredTargets{$target}{_allowed_} = 0;
                                next;
                            }
                        }
                    }

                    # If no unit restriction but position restriction, screen
                    # out targets that don't have position attribute or whose
                    # position attribute does not match the restriction
                    if(   (scalar @positionElements > 0)
                       && (scalar @unitElements == 0)   )
                    {
                        $restrictPos = $positionElements[0]->to_literal;

                        if(   (!exists
                                $filteredTargets{$target}{_identity_}{POSITION})
                           || (  $filteredTargets{$target}{_identity_}{POSITION}
                               != $restrictPos))
                        {
                            $filteredTargets{$target}{_allowed_} = 0;
                        }
                    }
                 }
            }
        }

        foreach my $target (keys %filteredTargets)
        {
            # Don't bother with any target that is not in play
            if($filteredTargets{$target}{_allowed_} != 1)
            {
                next;
            }

            # Candidate is any target having the attribute and a default
            # value determined
            if(   exists $instanceRef->{$target}{$attributeId}
               && exists $instanceRef->{$target}{$attributeId}{default}
               && exists $instanceRef->{$target}{$attributeId}{size})
            {
                # Multiple BIOS directives cannot touch same
                # target/attribute
                if(defined $attrTargAttrSetByBios{$target}{$attributeId})
                {
                    croak("$target, $attributeId set by multiple BIOS "
                        . "definitions.\n");
                }
                else
                {
                    $attrTargAttrSetByBios{$target}{$attributeId} = 1;
                }

                # If no default set yet
                if(! (defined $default) )
                {
                    $default = $instanceRef->{$target}{$attributeId}{default};
                    $size = $instanceRef->{$target}{$attributeId}{size};
                }
                # Cannot have different defaults in same group
                elsif(   $instanceRef->{$target}{$attributeId}{default}
                      != $default )
                {
                    croak("BIOS definition specified attribute "
                        . "$attributeId, but default values are not same "
                        . "across all qualifying targets.  "
                        . "$target/ $attributeId = "
                        . "$instanceRef->{$target}{$attributeId}{default}.\n");
                }
            }
        }

        # If no targets had the attribute
        if(!defined $default || !defined $size)
        {
            croak("BIOS definition specified attribute $attributeId, but "
                . "after considering target restrictions/etc., no "
                . "valid targets were found.\n");
        }

        # Add the restriction info to the XML tree.  This info is useful for 3rd
        # parties to create Hostboot attribute overrides.
        my $targetElement = $self->createChildElement($attribute,"target");
        $self->createChildElement(
            $targetElement,"type",sprintf("0x%08X",$restriction{numericType}));
        $self->createChildElement(
            $targetElement,"node",sprintf("0x%02X",$restriction{node}));
        $self->createChildElement(
            $targetElement,"position",sprintf("0x%04X",$restriction{position}));
        $self->createChildElement(
            $targetElement,"unit",sprintf("0x%02X",$restriction{unit}));

        my @enumerationOverrideElement
            = $attribute->findnodes('./enumerationOverride');
        if($attrType eq "enumeration")
        {
            # Get a copy of the enumeration description.  Schema requires
            # enumerator to have only a name (symbolic handle) + value.
            # Customization allows overriding description + short name
            # Customization allows specifying subset of values to actually use
            # Output includes short name, long name, value
            my $enumType =
                $attrMapRef->{$attributeId}{simpleType}{enumeration}{id};
            my $enumerationType =
                ::getEnumerationType($$attributesRef,$enumType);

            my %foundAllowed = ();
            my $enableRestrictions = 0;
            if(scalar @enumerationOverrideElement)
            {
                # Each enumerator name must tie back to a valid enumeration
                foreach my $overrideNameElement (
                    $attribute->findnodes(
                        './enumerationOverride/allowedEnumerators/name'))
                {
                    my $overrideName = $overrideNameElement->to_literal;
                    my $nameFound = 0;
                    foreach my $enumerator (@{$enumerationType->{enumerator}})
                    {
                        if($enumerator->{name} eq $overrideName)
                        {
                            # Each allowed value must be different from all the
                            # rest previously found for this attribute
                            if(exists $foundAllowed{$overrideName})
                            {
                                croak("BIOS definition specified "
                                    . "attribute $attributeId, and supplied "
                                    . "override to allowed enumeration values, "
                                    . "but duplicated a value of "
                                    . "$overrideName.\n");
                            }
                            else
                            {
                                $foundAllowed{$overrideName} = 1;
                                $enumerator->{allowed} = 1;
                            }

                            $enableRestrictions = 1;
                            $nameFound = 1;

                            last;
                        }
                    }

                    if(!$nameFound)
                    {
                        croak("BIOS definition specified attribute "
                            . "$attributeId, and supplied override to allowed "
                            . "enumeration values, but requested enumerator "
                            . "$overrideName is not valid.\n");
                    }
                }

                # Apply any overrides to the enumerator text
                my %textOverrideAllowed = ();
                foreach my $enumeratorOverrideElement (
                    $attribute->findnodes(
                        './enumerationOverride/enumeratorOverride'))
                {
                    # Each override must have exactly one name element
                    my @name = $enumeratorOverrideElement->findnodes('./name');

                    # Each override must have 0 or 1 display-name and
                    # descriptions elements
                    my @displayName =
                        $enumeratorOverrideElement->findnodes('./display-name');
                    my @description =
                        $enumeratorOverrideElement->findnodes('./description');

                    # Make sure enumerator name is valid
                    my $overrideName = $name[0]->to_literal;
                    my $nameFound = 0;
                    foreach my $enumerator (@{$enumerationType->{enumerator}})
                    {
                        if($enumerator->{name} eq $overrideName)
                        {
                            # Must not duplicate already overridden enumerator
                            if(exists $textOverrideAllowed{$overrideName})
                            {
                                croak("BIOS definition specified "
                                     . "attribute $attributeId, and supplied "
                                     . "override to allowed enumerator, "
                                     . "but already overrode this "
                                     . "enuemrator.\n");
                            }
                            # Can only override things that are not restricted
                            elsif(   !exists $foundAllowed{$overrideName}
                                  && $enableRestrictions)
                            {
                                croak("BIOS definition specified "
                                     . "attribute $attributeId, and supplied "
                                     . "override to allowed enumerator, but "
                                     . "this enumerator $overrideName is "
                                     . "restricted.\n");
                            }
                            else
                            {
                                $textOverrideAllowed{$overrideName} = 1;
                            }

                            if(scalar @displayName)
                            {
                                $enumerator->{'display-name'} =
                                    $displayName[0]->to_literal;
                            }

                            if(scalar @description)
                            {
                                $enumerator->{description} =
                                    $description[0]->to_literal;
                            }

                            $nameFound = 1;
                            last;
                        }
                    }

                    if(!$nameFound)
                    {
                        croak("BIOS definition specified attribute "
                            . "$attributeId, and supplied override to allowed "
                            . "enumeration, but requested invalid enumerator "
                            . "name to override of $overrideName.\n");
                    }
                }
            }

            my $enumerationElement =
                $self->createChildElement($attribute,"enumeration");

            foreach my $enumerator (@{$enumerationType->{enumerator}})
            {
                if($enableRestrictions && !exists $enumerator->{allowed})
                {
                    # If enumerator is not allowed and is same as attribute
                    # default then can't continue
                    if($default eq  $enumerator->{name})
                    {
                        croak("BIOS definition specified attribute "
                            . "$attributeId as not allowing "
                            . "$enumerator->{name}, but that is the attribute "
                            . "default.\n");
                    }

                    next;
                }

                my $enumeratorElement =
                    $self->createChildElement($enumerationElement,"enumerator");

                if(!exists $enumerator->{'display-name'})
                {
                    croak("BIOS definition specified attribute "
                        . "$attributeId, and supplied override to enumerator "
                        . "$enumerator->{name}, but there is no "
                        . "display-name.\n");
                }

                $self->createChildElement(
                   $enumeratorElement,"display-name",
                   $enumerator->{'display-name'});

                if(!exists $enumerator->{description})
                {
                    croak("BIOS definition specified attribute "
                        . "$attributeId, and supplied override to enumerator "
                        . "$enumerator->{name}, but there is no "
                        . "description.\n");
                }

                $self->createChildElement(
                   $enumeratorElement,"description",$enumerator->{description});
                $self->createChildElement(
                   $enumeratorElement,"value",
                   sprintf("0x%08X",$enumerator->{value}));
            }

            # Translate attribute default to actual value
            $default = ::enumNameToValue($enumerationType,$default);
        }
        # No enums allowed to be specified
        elsif(scalar @enumerationOverrideElement)
        {
                croak("BIOS definition specified attribute $attributeId, "
                    . "and supplied enumerated values, but this is not an "
                    . "enumeration attribute, it is of type $attrType.\n");
        }

        # Can only specify numeric override for signed/unsigned values of
        # 1,2,4,8 byte values
        my @numericOverrideElements= $attribute->findnodes('./numericOverride');

        # Hash of min(key), max(value) pairs
        my %allowedRange = ();
        if(scalar @numericOverrideElements)
        {
            # If range override not allowed for this attribute, bail
            if($typeHash{$attrType}{ror} != 1)
            {
                croak("BIOS definition specified attribute $attributeId, "
                    . "and supplied numeric override, but this attribute "
                    . "type does not support such override.  Type is "
                    . "$attrType.\n");
            }

            # A numericOverride has exactly one start + end element
            my @startElements =
                @numericOverrideElements[0]->findnodes('./start');
            my @endElements = @numericOverrideElements[0]->findnodes('./end');
            my $min = $typeHash{$attrType}{min};
            my $max = $typeHash{$attrType}{max};

            # Validate range min
            if(scalar @startElements)
            {
                my $rawMin = @startElements[0]->to_literal;

                if($rawMin < $min || $rawMin > $max)
                {
                    croak("BIOS definition specified attribute "
                        . "$attributeId, and supplied valid start or end "
                        . "range, but min out of range. requested "
                        . "min = $rawMin, allowed min = "
                        . "$typeHash{$attrType}{min}, allowed max = "
                        . "$typeHash{$attrType}{max}.\n");
                }
                $min = $rawMin;
            }

            # Validate range max
            if(scalar @endElements)
            {
                my $rawMax = @endElements[0]->to_literal;

                if($rawMax > $max || $rawMax < $min)
                {
                    croak("BIOS definition specified attribute "
                        . "$attributeId, and supplied valid start or end "
                        . "range, but max out of range. requested "
                        . "max = $rawMax, current min = $min, "
                        . "allowed min = "
                        . "$typeHash{$attrType}{min}, allowed max = "
                        . "$typeHash{$attrType}{max}.\n");
                }
                $max = $rawMax;
            }

            # Min must be <= Max
            if($min > $max)
            {
                croak("BIOS definition specified attribute "
                    . "$attributeId, and supplied valid start or end "
                    . "range, but min > max. min = $min, "
                    . "max = $max.\n");
            }

            # To prevent range overlaps, cannot duplicate the same start of
            # a range
            if(defined $allowedRange{$min})
            {
                croak("Already range starting at $min.\n");
            }

            $allowedRange{$min} = $max;
            my $defaultInRange = 0;

            my $min = undef;
            my $max = undef;

            # Ensure default value falls within a defined range.  The ranges are
            # sorted in numerically ascending order according to the start of
            # each range, so if the start of
            # range N falls within range N-1, we know there is an illegal range
            # overlap and fail.
            foreach my $rangeKey (sort {$a <=> $b} keys %allowedRange)
            {
                if(   ($default >= $rangeKey)
                   && ($default <= $allowedRange{$rangeKey}) )
                {
                    $defaultInRange = 1;
                }

                if(!defined $min)
                {
                    $min = $rangeKey;
                    $max = $allowedRange{$rangeKey};
                    next;
                }

                if($rangeKey <= $max)
                {
                    croak("Range starting with $rangeKey overlaps "
                        . "range ending at $max.\n");
                }

                $min = $rangeKey;
                $max = $allowedRange{$rangeKey};
            }

            if(!$defaultInRange)
            {
                croak("Default value $default not in any valid range.\n");
            }
        }

        # Convert attribute ID to numerical value and append to XML tree
        my $attributeIdEnumeration
            = ::getAttributeIdEnumeration($$attributesRef);
        my $attrValue = ::enumNameToValue($attributeIdEnumeration,$attributeId);
        $attrValue = sprintf ("0x%0X", $attrValue);

        # Add the remaining metadata to the XML tree
        $self->createChildElement($attribute,"default",$default);
        $self->createChildElement($attribute,"numeric-id",$attrValue);
        $self->createChildElement($attribute,"size",$size);
    }
}

1;

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

=item B<--bios-xml-file>

Path + file name of XML file describing the platform's BIOS configuration.
Optional.

=item B<--bios-schema-file>

Path + file name of XSD schema file used to validate the BIOS XML file. Required
if a BIOS XML file is given.

=item B<--bios-output-file>

Path + filename of output XML file describing the amended BIOS configuration.
This output is commonly later modified by 3rd parties via xslt transformation to
tailor the output for a given application.  Required if a BIOS XML file is
given.

=item B<--verbose>

Prints out some internal workings

=back

=head1 DESCRIPTION

B<xmltohb.pl> will process a set of input .xml files and emit source files and
a PNOR targeting image binary to facilitate compiling and configuring host boot
respectively.

=cut
