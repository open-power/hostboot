#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/Attr.pm $
#
# OpenPOWER HostBoot Project
#
# COPYRIGHT International Business Machines Corp. 2012,2014
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
# This perl module can be used in a standalone Hostboot environment
# (Simics or VBU) or with a L3 dump file to dump a specified target's
# attribute(s).
#
# Authors:  CamVan Nguyen
#           Mark Wenning
#

use strict;
package Hostboot::Attr;
use Hostboot::_DebugFrameworkVMM;
use Exporter;
our @EXPORT_OK = ('main');

use POSIX;
use File::Basename;
use Data::Dumper;
$Data::Dumper::Sortkeys  = 1;


#------------------------------------------------------------------------------
# Constants
#------------------------------------------------------------------------------

use constant PAGESIZE           => 4096;     # 4KB

##  each target object takes up space for:
##      uint32_t iv_attrs + void *iv_pAttrNames + void *iv_pAttrValues
##      + void* iv_ppAssociations[4]
use constant TARGETSIZE             =>  52;
##  Attribute id's are uint32_t enums
use constant    ATTRID_SIZE         =>  4;
##  pointers to attribute values should be 8 bytes
use constant    ATTRVALUESPTR_SIZE  =>  8 ;

##  size of the TargetsHdr struct at the beginning of PNOR
use constant    TARGETS_HDR_SIZE    =>  0x100;

#------------------------------------------------------------------------------
# Globals
#------------------------------------------------------------------------------

my %pages = ();
my  %sections   =   (
                     'PNOR_RO'           => {   'vaddr'     =>  0x100000000,
                                                'physaddr'  =>  0x0,
                                            },
                     'PNOR_RW'           => {   'vaddr'     =>  0x108000000,
                                                'physaddr'  =>  0x0,
                                            },
                     'HEAP_ZERO_INIT'    => {   'vaddr'     =>  0x110000000,
                                                'physaddr'  =>  0x0,
                                            },
                     'HB_HEAP_ZERO_INIT' => {   'vaddr'     =>  0x118000000,
                                                'physaddr'  =>  0x0,
                                            },
                     );
my  @targets        =   ();
my  $attrListRef    =   {};


#------------------------------------------------------------------------------
#   Forward Declarations
#------------------------------------------------------------------------------

#------------------------------------------------------------------------------
# Main
#------------------------------------------------------------------------------
sub main
{
    my ($packName,$args) = @_;

    #--------------------------------------------------------------------------
    # Process input arguments
    #--------------------------------------------------------------------------
    my $debug = 0;
    if (defined $args->{"debug"})
    {
        $debug = $args->{"debug"};

        my  $debugFileName  =   ::getImgPath() . "Attr.debug";
        open(DEBUG_FILE, "> $debugFileName")
            or die "Cannot open file $debugFileName";

        ::userDisplay   "write debug info to $debugFileName\n";
    }

    my $opt_huid = "";
    if (defined $args->{"huid"})
    {
        $opt_huid = $args->{"huid"};
        chomp $opt_huid;

        ::userDisplay "huid=$opt_huid option specified. \n";
    }

    my $opt_attrname = "";
    if (defined $args->{"attrname"})
    {
        $opt_attrname = $args->{"attrname"};
        chomp $opt_attrname;

        ::userDisplay "attrname=$opt_attrname option specified. \n";
    }

    ##  Normally this will not need to be specified, this is the default.
    my  $attrListFile   =   "targAttrInfo.csv";

    ## read --attrfile in case the user wants to override
    if (defined $args->{"attrfile"})
    {
        $attrListFile = $args->{"attrfile"};
    }

    #--------------------------------------------------------------------------
    #   Read in the file that associates the attr name, attr id, and size .
    #--------------------------------------------------------------------------
    $attrListFile = ::getImgPath() . $attrListFile;

    unless (-e $attrListFile)
    {
        ::userDisplay "Cannot find attribute list file \"$attrListFile\".\n";
        die;
    }

    ::userDisplay "Using attribute list file \"$attrListFile\"\n\n";

    #--------------------------------------------------------------------------
    # Process the attribute list file. Save data to a hash.
    #
    #   Format of file is:
    #       <FAPI-ATTR-ID-STR>,<LAYER-ATTR-ID-STR>,<ATTR-ID-VAL>,<ATTR-TYPE>
    #   We are not interested in the FAPI-ATTR-ID-STR, parse the rest of
    #   the csv fields.
    #--------------------------------------------------------------------------
    open(FILE, "< $attrListFile") or die "Cannot open file $attrListFile";

    my  @lines  =   <FILE>;
    my  $attrIdHex  =   0;

    # Get the attribute data and index by ID
    foreach  my $line (@lines)
        {
            chomp($line);
            my ( $fapi_attr_id_str,
                 $layer_attr_id_str,
                 $attr_id_val,
                 $attr_type ) =   split( ',', $line );

            ##  convert to scalar for a clean index
            $attrIdHex  =   hex( $attr_id_val );

            $attrListRef->{$attrIdHex}->{'str'}   =   $layer_attr_id_str ;
            $attrListRef->{$attrIdHex}->{'type'}  =   $attr_type ;
    }
    close(FILE) or die "Cannot close $attrListFile";

    ##  $$ debug
    ## ::userDisplay   Dumper( $attrListRef );

    #--------------------------------------------------------------------------
    # Initialize Global Vars
    #--------------------------------------------------------------------------
    my  $cacheData  =   0;

    ##  -----------------------------------------------------------------------
    ##  Initialize Target and Attribute Section info
    ##  -----------------------------------------------------------------------
    my  $secref =   \%sections;
    $secref->{'PNOR_RO'}->{'physaddr'} =
        getPhysicalAddr( $secref->{'PNOR_RO'}->{'vaddr'} );
    $secref->{'PNOR_RW'}->{'physaddr'} =
        getPhysicalAddr( $secref->{'PNOR_RW'}->{'vaddr'} );
    $secref->{'HEAP_ZERO_INIT'}->{'physaddr'} =
        getPhysicalAddr( $secref->{'HEAP_ZERO_INIT'}->{'vaddr'} );
    $secref->{'HB_HEAP_ZERO_INIT'}->{'physaddr'} =
        getPhysicalAddr( $secref->{'HB_HEAP_ZERO_INIT'}->{'vaddr'} );


    if  ( $debug )
    {
        ##  Dump Targeting Header
        ::userDisplay   "dump Targeting Header: \n" ;
        my  $data   =   readData( $secref->{'PNOR_RO'}->{'vaddr'} ,
                                  256,
                                  $cacheData,
                                  $debug );
        userDisplayHex( $data );
    }

    ##  The first thing in the first section (i.e. after the TargetHeader)
    ##  should be a vaddr pointer to the number of targets, followed by an
    ##  array of all the targets.
    ##
    ##  Read the pointer to numTargets and the targetArray.
    ##  skip over the 256 byte header to get to the first section
    my  $numTargetsPtr =    0;
    my  $numTargets    =    0;
    $numTargetsPtr  =
        readDataHex( ($secref->{'PNOR_RO'}->{'vaddr'}+TARGETS_HDR_SIZE),
                     8, $cacheData, $debug );
    $numTargets     =
        readDataHex( $numTargetsPtr,
                     4, $cacheData, $debug );

    ##  bump the pointer by a uint32_t.  We should now be pointing to the
    ##      first target.
    my  $targetsPtr  =   $numTargetsPtr + 4;
    if ( $debug )
    {
        ##  Sanity check
        ::userDisplay
            "ptr to numTargets: ",
            (sprintf("0x%016x", $numTargetsPtr)), "\n",
            "ptr to targets: ",
            (sprintf("0x%016x", $targetsPtr)), "\n",
            "numTargets: ",
            (sprintf("0x%08x", $numTargets)), "\n"  ;
    }

    ::userDisplay "Reading target and attribute data,",
                  " this may take a while...\n";


    ##  Fill in the @targets array with the target info
    for ( my $i=0; $i<$numTargets;  $i++ )
    {
        my  $targInfoRef    =   {};
        my  $offset         =   $i*TARGETSIZE;
        my  $attrSize       =   0;

        ##  Read in the number of attributes associated with this target
        $targInfoRef->{'iv_attr'} = readDataHex( ($targetsPtr + $offset),
                                                 4, $cacheData, $debug );
        $offset += 4 ;      ## bump to iv_AttrNames ptr and store
        $targInfoRef->{'iv_pAttrNames'} = readDataHex( ($targetsPtr+$offset),
                                                       8, $cacheData, $debug );
        $offset += 8 ;      ## bump to iv_AttrValues ptr and store
        $targInfoRef->{'iv_pAttrValues'} = readDataHex( ($targetsPtr+$offset),
                                                        8, $cacheData, $debug );


        ##
        ##  Follow the iv_pAttrNames pointer to read in the attribute id's
        ##      associated with this target
        ##
        my @attrIds =   getAttrIds( $targInfoRef,
                                    $cacheData,
                                    $debug );
        ##  $$ debug
        ## ::userDisplay   join(", ", @attrIds), "\n";

        ##  follow the iv_AttrValues pointer to read in the value pointers
        ##      associated with each target.
        ##  This should be in 1 to 1 correspondence with the @attrIds array
        ##      above.
        my @attrValuePtrs  =   getAttrValuePtrs(  $targInfoRef,
                                                  $cacheData,
                                                  $debug );
        ##  $$ debug
        ## ::userDisplay   join(", ", @attrValuePtrs), "\n";

        ##
        ##  Fill in the attribute values for each attribute id / name,
        ##  indexed by the name.
        ##

        for ( my $j=0; $j<$targInfoRef->{'iv_attr'};  $j++ )
        {
            my  $thisAttrId     =   $attrIds[$j];
            my  $thisAttrName   =   $attrListRef->{$thisAttrId}->{'str'} ;
            if ( $thisAttrName  eq "" )
            {
                ##  if we can't find the attribute in the attrList file,
                ##  it is probably not an integer or integer array.
                ##  Make up a name.  When we print all the attributes at the
                ##  end, these will be skipped unless --debug is turned on.
                ##  @TODO RTC 68517 Handle non-simple non-integer types
                ##  as part of the above RTC to make all attr dump tools
                ##  compatible with cronus.
                $thisAttrName   = "ATTR_TBD_" . (sprintf("0x%x", $thisAttrId));
            }

            ##  save the order that they came in.
            $targInfoRef->{$thisAttrName}->{'index'}  =   $j;

            ##  store the attribute id
            $targInfoRef->{$thisAttrName}->{'attrid'}    =  $thisAttrId;

            ##  read the type and derive the size from the attrList hash.
            my   $attrType   =   $attrListRef->{$thisAttrId}->{'type'};
            $targInfoRef->{$thisAttrName}->{'attrtype'}  =   $attrType;

            ##  parseType will return a size for simple types, for arrays
            ##  etc it will fill in @parseDesc .
            my  @parseDesc  =   ();
            my   $readSize  =   parseType( $attrType, \@parseDesc, $debug );
            $targInfoRef->{$thisAttrName}->{'attrsize'}  =   $readSize;
            $targInfoRef->{$thisAttrName}->{'attrDesc'}  =   \@parseDesc;

            if ( $debug )
            {
                print  DEBUG_FILE   "process $thisAttrName $attrType ",
                                    ", parseDesc= ", scalar(@parseDesc),
                                    ", vaddr=",
                                    (sprintf("0x%X",$attrValuePtrs[$j])),
                                    ", readSize=$readSize",
                                    "\n" ;
            }

            ##  Save the vaddr for debug.
            $targInfoRef->{$thisAttrName}->{'attrvaddr'} = $attrValuePtrs[$j];

            ##  fetch the attribute value.  Read and store this as a raw
            ##  binary hex string (mixed in with "not present" messages)
            ##  and process it later.
            my  $rawData   =   0;
            $rawData = readData( $attrValuePtrs[$j],
                                 $readSize,
                                 $cacheData, $debug );

            $targInfoRef->{$thisAttrName}->{'attrvalue'} = $rawData;

        }   ##  endfor $j (attributes)

        $targets[$i]    =   $targInfoRef;

    }   ##  endfor $i (targets)

    if ( $debug )
    {
        print DEBUG_FILE "\n",  Dumper( @targets );
    }


    ##  --------------------------------------------------------------
    ##  print out results
    ##  --------------------------------------------------------------
    my  $foundTarget =   0;

    ::userDisplay   "#  number of targets   =   $numTargets\n" ;

    foreach my $targetRef ( @targets )
    {
        my  $targHuid = binToHex( $targetRef->{'ATTR_HUID'}->{'attrvalue'} );

        if ( $opt_huid eq "" )
        {
            displayTargetAttributes( $targetRef, $opt_attrname, $debug );
        }
        else
        {
            my  $inHuid     =   hex( $opt_huid );
            if ( $debug )
            {
                ::userDisplay
                    "inHuid=", (sprintf("0x%X"),$inHuid),
                    ", targHuid=", (sprintf("0x%X"),$targHuid),
                    "\n";
            }
            if ( $inHuid == $targHuid )
            {
                $foundTarget    =   1;
                displayTargetAttributes( $targetRef, $opt_attrname, $debug );
            }
        }

        last if ( $foundTarget );

    }   ##  end foreach $targetRef


    if ( $debug )
    {
        close DEBUG_FILE;
    }

}   ##  end main

##
##  passed a targetref, print all or one of its' attributes in
##  more-or-less cronus format
##
sub displayTargetAttributes
{
    my  ( $targetRef, $attrname, $debug ) =   @_;
    my  $foundAttr    =   0;

    ##  print HUID and number of attributes (in a comment) first
    ##      as a sanity check.
    my  $huid   =   binToHex( $targetRef->{'ATTR_HUID'}->{'attrvalue'} );

    ::userDisplay   "\n# huid = ", (sprintf("0x%X",$huid)), "\n";
    ::userDisplay   "# number of attributes = ",$targetRef->{'iv_attr'}, "\n";
    ::userDisplay   "target = ", cronusTargetStr( $huid ), "\n" ;

    foreach my $attr   ( sort keys %$targetRef )
    {

        if ( $attrname  ne "" )
        {
            if ( $debug )
            {
                ::userDisplay   "attr=$attr, attrname=$attrname \n";
            }

            ##  if the attrname option is defined, skip any other attribute
            next if  ( $attr ne $attrname );
        }

        if ( $attr eq $attrname )
        {
            $foundAttr    =   1;
        }

        ##  skip the "iv_" keys.
        next if ( !($attr =~ m/ATTR_/)  );

        ##  skip the unknown ones, unless debug is on.
        if ( !$debug )
        {
            next if ( $attr =~ m/ATTR_TBD/  );
        }

        ##  make local copies
        my  $attrType       =   $targetRef->{$attr}->{'attrtype'} ;
        my  @attrDesc       =   @{$targetRef->{$attr}->{'attrDesc'}};
        my  $rawAttrValue   =   $targetRef->{$attr}->{'attrvalue'} ;

        ##  sanity check
        if (($rawAttrValue eq Hostboot::_DebugFrameworkVMM::NotFound) ||
            ($rawAttrValue eq Hostboot::_DebugFrameworkVMM::NotPresent))
        {
            ::userDisplay $attr ;
            ::userDisplay " $attrType ";
            ::userDisplay $rawAttrValue . ": vaddr=" .
                          (sprintf("0x%X",$targetRef->{$attr}->{'attrvaddr'})) ;

            return;
        }


        if ( scalar( @attrDesc ) ==  0 )
        {
            ##  print attr and type
            ::userDisplay   $attr, " ",
                            $attrType,  " " ;

            ##  Print out value(s)
            my  $attrValue  =   binToHex($rawAttrValue);
            ::userDisplay  (sprintf( "0x%X ", $attrValue )) ;
            ::userDisplay  "\n" ;

        }
        else
        {
            ##  array.

            userDisplayArray( $targetRef, $attr );
        }

        last if ( $foundAttr );

    }   ## end foreach $attr
}


sub userDisplayArray
{
    my ( $targetRef, $attr   )   =   @_;

    my  $attrType       =   $targetRef->{$attr}->{'attrtype'};
    my  $rawAttrValue   =   $targetRef->{$attr}->{'attrvalue'};
    my  @attrDesc       =   @{$targetRef->{$attr}->{'attrDesc'}};

    ##  assume max dimension of 3 deep, and always a good 1st dimension
    my  $i  =   0;
    my  $j_index    =   -1;
    my  $k_index    =   -1;
    my  $size       =   $attrDesc[$i];  $i++;
    my  $i_index    =   $attrDesc[$i];  $i++;
    my  $enum       =   $attrDesc[$i];  $i++;
    if ( $attrDesc[$i] )
    {
        $i++;
        $j_index    =   $attrDesc[$i];  $i++;
        $i++;
        if ( $attrDesc[$i]  )
        {
            $i++;
            $k_index    =   $attrDesc[$i];
            $i++;
            if ( $attrDesc[$i]  )
            {
                die "array dimensions > 3 are not supported.";
            }
        }
    }


    if ( $k_index > 0 )
    {
        userDisplay3dArray( $attr,
                            $attrType,
                            $size,
                            $i_index,
                            $j_index,
                            $k_index,
                            $rawAttrValue );
    }
    elsif   ($j_index > 0 )
    {
        userDisplay2dArray( $attr,
                            $attrType,
                            $size,
                            $i_index,
                            $j_index,
                            $rawAttrValue );
    }
    else
    {
        ##  single array
        my  $upsz   =   $size*2;
        my  @values =   unpack("(H$upsz)*", $rawAttrValue );
        ## $$ debug
        ## ::userDisplay   scalar(@values), ": ", join( ", ", @values), "\n" ;
        my  $valindex   =   0;
        for ( my $i=0; $i<$i_index; $i++ )
        {
            ##$$debug ::userDisplay   (sprintf("%02x ", $valindex) );
            ::userDisplay   $attr ;
            ::userDisplay   "[$i]" ;
            ::userDisplay   " $attrType ";
            ::userDisplay   $values[$valindex] ;    $valindex++;
            ::userDisplay   "\n";
        }   ##  endfor i
    }   ##  end else
}


sub userDisplay2dArray
{
    my  ($attr,
         $attrType,
         $size,
         $i_index,
         $j_index,
         $rawAttrValue )   =   @_;

    my  $upsz   =   $size*2;
    my  @values =   unpack("(H$upsz)*", $rawAttrValue );
    ## $$ debug
    ## ::userDisplay   scalar(@values), ": ", join( ", ", @values), "\n" ;
    my  $valindex   =   0;
    for ( my $i=0; $i<$i_index; $i++ )
    {
        for ( my $j=0;  $j<$j_index; $j++   )
        {
            ##$$debug ::userDisplay   (sprintf("%02x", $valindex) );
            ::userDisplay   $attr ;
            ::userDisplay   "[$i][$j]" ;
            ::userDisplay   " $attrType ";
            ::userDisplay   $values[$valindex] ;    $valindex++;
            ::userDisplay   "\n";
        }   ##  endfor j
    }   ##  endfor i

}


sub userDisplay3dArray
{
    my  ($attr,
         $attrType,
         $size,
         $i_index,
         $j_index,
         $k_index,
         $rawAttrValue) =   @_;

    my  $upsz   =   $size*2;
    my  @values =   unpack("(H$upsz)*", $rawAttrValue );
    ## $$ debug
    ## ::userDisplay   scalar(@values), ": ", join( ", ", @values), "\n" ;
    my  $valindex   =   0;
    for ( my $i=0; $i<$i_index; $i++ )
    {
        for ( my $j=0;  $j<$j_index; $j++   )
        {
            for ( my $k=0; $k<$k_index; $k++ )
            {
                ##$$debug ::userDisplay   (sprintf("%02x ", $valindex) );
                ::userDisplay   $attr ;
                ::userDisplay   "[$i][$j][$k]" ;
                ::userDisplay   " $attrType ";
                ::userDisplay   $values[$valindex] ;    $valindex++;
                ::userDisplay   "\n";
            }   ##  endfor k
        }   ##  endfor j
    }   ##  endfor i
}



sub cronusTargetStr()
{
    my  ( $huid )           =   @_;
    my  $cronusTargetStr    =   "TBD";

    ##  TBD

    return  $cronusTargetStr;
}


##
##  translate cronus-type type strings to:
##      Integer size in bytes
##      Number of integers to read
##      Enumerated type flag
##  Fills in list(s) of these 3 values that describes each field,
##  for example:
##      u64[5][6][1]
##  ( size=8,num=5,enum=0 ),    ## dimension 1
##  ( size=8,num=6,enum=0 ),    ## dimension 2
##  ( size=8,num=1,enum=0 ),    ## dimension 3
##  ( size=0,num=0,enum=0 ),    ## endit
##
##  if the attr type is a single simpleType, returns the size in bytes.
##  If the attr type is more complicated, return the total size in bytes
##      and fill in the passed-in parse Description struct.
##
sub parseType
{
    my  ( $type, $parseDescRef, $debug )   =   @_;

    my  $size       =   8;      ##  default
    my  $num        =   1;      ##  default
    my  $enum       =   0;      ##  default
    my  $totalSize  =   1;

    $_  =   $type;
    if ( m/u8/  )   {   $size   =   1;  }
    if ( m/u16/ )   {   $size   =   2;  }
    if ( m/u32/ )   {   $size   =   4;  }
    if ( m/u64/ )   {   $size   =   8;  }

    ##  @TODO RTC 68517 Add code to display non-simple non-integer types

    $totalSize  =   $size;

    ##  remove size spec
    s/[u][0-9]*[e]*//;

    ##  find any arrays
    my  @arrayDims  =   split /\[([^\]]*)\]/g ;

    if ( scalar( @arrayDims ) > 0 )
    {
        ##  Array.  Build the description struct and calculate the right size
        my  $i  =   0;
        foreach ( @arrayDims  )
        {
            ## skip empty array entries
            next if ( ! m/[0-9]+/ ) ;

            @{$parseDescRef}[$i] =  $size;  $i++;       ##  size in bytes
            @{$parseDescRef}[$i] =  $_;     $i++;       ##  number of vars
            @{$parseDescRef}[$i] =  $enum;  $i++;       ##  enum flag

            $totalSize *=   $_ ;
        }

        ##  add a terminating record
        @{$parseDescRef}[$i] =  0;  $i++;
        @{$parseDescRef}[$i] =  0;  $i++;
        @{$parseDescRef}[$i] =  0;  $i++;

    }

    return  $totalSize;
}



##
##  Fetch Attr Ids, passed a pointer to a Target's attrid list.
##      return an array of the attr id's
sub getAttrIds()
{
    my  ( $targInfoRef, $cacheData, $debug )  =   @_;
    my  $pAttrIds   =   $targInfoRef->{'iv_pAttrNames'};
    my  $numAttrs   =   $targInfoRef->{'iv_attr'};
    my  @attrIds    =   ();

    my $rawattrids = readData( $pAttrIds,
                               (ATTRID_SIZE*$numAttrs),
                                $cacheData, $debug );

    ##  split and convert from binary
    my @unpackattrids    =   unpack( "(H8)*", $rawattrids );

    my  $i  =   0;
    foreach ( @unpackattrids )
    {
        @attrIds[$i]    =   hex($_);
        $i++;
    }

    return  @attrIds;
}

##
##  fetch the array of pointers to attr values
##      return an array of the attr values.
sub getAttrValuePtrs()
{
    my  ( $targInfoRef, $pAttrValues, $numAttrs, $cacheData, $debug ) =   @_;
    my  $pAttrValues    =   $targInfoRef->{'iv_pAttrValues'};
    my  $numAttrs       =   $targInfoRef->{'iv_attr'};
    my  @attrvalueptrs  =   ();
    my  @attrValues     =   ();

    my $rawattrvalueptrs = readData( $pAttrValues,
                                     (ATTRVALUESPTR_SIZE*$numAttrs),
                                     $cacheData, $debug );

    ##  split and convert from binary
    my  @unpackattrvalueptrs  =   unpack( "(H16)*", $rawattrvalueptrs);

    my  $i  =   0;
    foreach ( @unpackattrvalueptrs )
    {
        @attrvalueptrs[$i]    =   hex($_);
        $i++;
    }

    return  @attrvalueptrs;
}

#
# Utility to read a block of data.  Caches 4K blocks to save time.
#   returns "binary" data
#
sub readData
{
    my ($vaddr, $size, $cache_data, $debug) = @_;

    my $result = "";

    if ($debug == 2)
    {
        ::userDisplay sprintf("Reading $size bytes from vaddr 0x%X\n", $vaddr);
    }

    while($size)
    {
        my $amount = $size;

        if ((($vaddr % PAGESIZE) + $size) > PAGESIZE)
        {
            $amount = PAGESIZE - ($vaddr % PAGESIZE);
            if ($debug == 2)
            {
                ::userDisplay sprintf("Data crossing page boundary for addr " .
                    "0x%X size $size\n", $vaddr);
            }
        }

        if ($cache_data)
        {
            # Read the entire page and cache it
            my $vpageaddr = $vaddr - ($vaddr % PAGESIZE);
            if (!defined $pages{$vpageaddr})
            {
                my $paddr = getPhysicalAddr($vpageaddr );
                if ((Hostboot::_DebugFrameworkVMM::NotFound eq $paddr) ||
                    (Hostboot::_DebugFrameworkVMM::NotPresent eq $paddr))
                {
                    return $paddr;
                }
                else
                {
                    if ($debug==2)
                    {
                        ::userDisplay sprintf("Caching data for address ".
                            "0x%X = 0x%x\n", $vpageaddr, $paddr);
                    }

                    $pages{$vpageaddr} = ::readData($paddr, PAGESIZE);
                }
            }
            elsif ($debug==2)
            {
                ::userDisplay sprintf("Using cached data for address 0x%X\n",
                    $vpageaddr);
            }

            $result = $result.
                substr($pages{$vpageaddr}, $vaddr % PAGESIZE,
                    $amount);
        }
        else
        {
            my $paddr = getPhysicalAddr($vaddr);
            if ((Hostboot::_DebugFrameworkVMM::NotFound eq $paddr) ||
                (Hostboot::_DebugFrameworkVMM::NotPresent eq $paddr))
            {
                return $paddr;
            }
            else
            {
                $result = $result.::readData($paddr, $amount);
            }
        }

        $vaddr = $vaddr + $amount;
        $size = $size - $amount;
    }

    return $result;
}



##
##  Read $bytes amount of data from $vaddr, using readData above.
##      return a valid hex scalar number.
##  Print an error message and return 0 if VirtToPhys says "not present"
##
sub readDataHex()
{
    my  ( $vaddr, $bytes, $cacheData, $debug )  =   @_;

    my  $data   =   readData( $vaddr,
                              $bytes,
                              $cacheData,
                              $debug );

    if ((Hostboot::_DebugFrameworkVMM::NotFound eq $data) ||
        (Hostboot::_DebugFrameworkVMM::NotPresent eq $data))
    {

        ::userDisplay   "readDataHex ERROR: ",
                        (sprintf("0x%X",$vaddr)), ":  $data\n";

        return  0;
    }

    my  $result =   binToHex( $data );

    return  $result;
}


##
##  read raw binary string and convert it to a hex scalar
##
sub binToHex()
{
    my  ( $rawData )    =   @_;

    my  $result =   hex(unpack("H*",$rawData));

    return  $result;
}

# Utility to display a block of data
sub userDisplayHex
{
    my $data = shift;
    my $count = 0;

    # Make it easier to read by displaying as two bytes chunks
    my @twobytes = unpack("(H4)*", $data);
    ::userDisplay   "\n    ";
    foreach (@twobytes)
    {
        ::userDisplay "$_ ";
        $count++;
        if (!($count % 8))
        {
            ::userDisplay "\n    ";
        }
    }
    ::userDisplay "\n";
}

sub helpInfo
{
    my %info = (
        name => "Attr",
        intro => ["Dump the specified target attribute(s)."],
        options => {
                    "huid=<HUID>" => ["HUID of the target as a hex number.",
                        "If not specified, will output attribute(s) of all ".
                        "targets."],
                    "attrname=<attribute name>" => ["Attribute to dump.",
                        "If not specified, will output all attributes for the ".
                        "specified target."],
                        "attrfile" => ["specify an alternate attribute " .
                        "information file.  Normally this will not be needed."],
                        "debug" => ["More debug output."],
                   },
    );
}


##  modules must return a 1 at the end
1;
__END__

