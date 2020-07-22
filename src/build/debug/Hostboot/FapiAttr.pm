#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/FapiAttr.pm $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016,2020
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
# This perl module is used in conjunction with the Istep.pm
# infrastructre to dump all FAPI attributes.  It requires
# a live and running Hostboot instance in Simics, VBU, HW
#

use strict;
package Hostboot::FapiAttr;
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

##  each ATTR sync record is formated as follows:
#        uint32_t iv_attrId;     // Attribute ID
#        uint32_t iv_targetType; // Target Type attribute is for
#        uint16_t iv_pos;        // For chips/dimms the position
#                                // For chiplets the parent chip position
#        uint8_t  iv_unitPos;    // For chiplets the position
#        uint8_t  iv_flags : 4;  // AttributeFlags enum value(s)
#        uint8_t  iv_node  : 4;  // Target Node number
#        uint32_t iv_valSize;    // Size of the attribute value in bytes

use constant    ATTRID_SIZE         =>  4;
use constant    TARGETTYPE_SIZE     =>  4;
use constant    POS_SIZE            =>  2;
use constant    UNIT_POS_SIZE       =>  1;
use constant    FLAG_NODE_SIZE      =>  1;
use constant    DATA_SIZE           =>  4;


#------------------------------------------------------------------------------
# Globals
#------------------------------------------------------------------------------

my  $attrListRef    =   {};
my $OUTFILE;
my $no_userDisplay = 0x0;



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

        my  $debugFileName  =   ::getImgPath() . "FapiAttr.debug";
        open(DEBUG_FILE, "> $debugFileName")
          or die "Cannot open file $debugFileName";

        ::userDisplay   "write debug info to $debugFileName\n";
    }

    ##  Normally this will not need to be specified, this is the default.
    my  $attrListFile   =   "attrInfo.csv";

    ## read --attrfile in case the user wants to override
    if (defined $args->{"attrfile"})
    {
        $attrListFile = $args->{"attrfile"};
    }
    else
    {
        $attrListFile = ::getImgPath() . $attrListFile;
    }

    unless (-e $attrListFile)
    {
        ::userDisplay "Cannot find attribute list file \"$attrListFile\".\n";
        die;
    }

    ::userDisplay "Using attribute list file \"$attrListFile\"\n";

    my $BINFILE;

    ## Must have bin dump file
    if (defined $args->{"attrbin"})
    {
        my $attrBinFile = $args->{"attrbin"};
        ::userDisplay "Using bin data file \"$attrBinFile\"\n";
        open($BINFILE, "<:raw", $attrBinFile) or die "Cannot open $attrBinFile";
    }
    else
    {
        ::userDisplay "No bin data to process \n";
        die;
    }

    ## If user specified an output file, route output there, otherwise console
    if (defined $args->{"attr_output"})
    {
        my $attrOutFile = $args->{"attr_output"};
        ::userDisplay "Outputting data to \"$attrOutFile\"\n";
        open($OUTFILE, ">", $attrOutFile) or die "Cannot open $attrOutFile";
        $no_userDisplay = 0x1;
    }

    #--------------------------------------------------------------------------
    # Process the attribute list file. Save data to a hash.
    #
    #   Format of file is:
    #       <FAPI-ATTR-ID-STR>,<LAYER-ATTR-ID-STR>,<ATTR-ID-VAL>,<ATTR-TYPE>
    #   We are not interested in the LAYER-ATTR-ID-STR, parse the rest of
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

        $attrListRef->{$attrIdHex}->{'str'}   =   $fapi_attr_id_str ;
        $attrListRef->{$attrIdHex}->{'type'}  =   $attr_type ;
    }
    close(FILE) or die "Cannot close $attrListFile";

    ##  $$ debug
    ## ::userDisplay   Dumper( $attrListRef );


    ## Walk the binFile of attributes
    my $hexHeader;
    my $hexData;
    my $prevTType = "";
    my $prevPos = "";
    my $prevUnitPos = "";

    seek ($BINFILE, 0, SEEK_SET);

    while(( my $bytes = read( $BINFILE, $hexHeader, 16)) == 16)
    {

        my($attrId, $targetType, $pos, $unitPos, $flag_node, $data_size) =
          unpack( 'H8H8H4H2H2H8', $hexHeader);
        read( $BINFILE, $hexData, (hex $data_size));

        ## If this is a new target, emit the target type str
        if(($targetType ne $prevTType) || ($pos ne $prevPos) ||
           ($unitPos ne $prevUnitPos))
        {
            #my $cro_str = cronusTargetStr( $targetType, $pos, $unitPos, $flag_node);
            #::userDisplay "Target type [$targetType] : $cro_str";
            $prevTType = $targetType;
            $prevPos = $pos;
            $prevUnitPos = $unitPos;
            outputData( "\n", (cronusTargetStr( $targetType, $pos,
                                           $unitPos, $flag_node)));
        }

        #Attempt to display
        #find ATTR and type from lookup
        my  $attrName   =   $attrListRef->{(hex $attrId)}->{'str'} ;
        my  $attrType   =   $attrListRef->{(hex $attrId)}->{'type'};


        ##  parseType will return a size for simple types, for arrays
        ##  etc it will fill in @parseDesc .
        my  @parseDesc  =   ();
        my   $readSize  =   parseType( $attrType, \@parseDesc);

        if ( scalar( @parseDesc ) ==  0 )
        {
            ##  print attr and type
            my  $upsz   =   $data_size*2;
            my  $value =   unpack("H$upsz", $hexData );
            outputData($attrName, " ", $attrType,  " ", $value, "\n");
        }
        else
        {
            ##  array.
            userDisplayArray( $attrName, $attrType, $hexData, @parseDesc);
        }
    }


    if ( $debug )
    {
        close DEBUG_FILE;
    }

}   ##  end main


sub outputData
{
    if(1 ==  $no_userDisplay)
    {
        foreach my $value (@_)
        {
            print $OUTFILE $value;
        }
     }
    else
    {
        ::userDisplay @_;
    }
}

sub userDisplayArray
{
    my ( $attrName, $attrType, $rawAttrValue, @attrDesc   )   =   @_;

    ##  assume max dimension of 3 deep, and always a good 1st dimension
    ##  attr Desc is a flat array where every three elements (a tuple)
    ##  indicate the parameters for the next set of array []
    ##  laid out like i_type, i_index, i_enum, j_type, j_index, j_enum,
    ##  k_type, k_index, k_enum where:
    ##     type is (u8, u16, etc)
    ##     index is the array index size (aka the 5 in [5])
    ##     enum is not used here (for enumerated ATTR types)
    my  $i  =   0;
    my  $j_index    =   -1;
    my  $k_index    =   -1;
    my  $size       =   $attrDesc[$i];  $i++;
    my  $i_index    =   $attrDesc[$i];  $i++;
    my  $enum       =   $attrDesc[$i];  $i++;
    if ( $attrDesc[$i] )
    {
        $i++; ## Move past j_type
        $j_index    =   $attrDesc[$i];  $i++; ## Capture j_index, move past
        $i++; ## Move past j_enum
        if ( $attrDesc[$i]  )
        {
            $i++; ## Move past k_type
            $k_index    =   $attrDesc[$i]; ## Capture k_index, move
            $i++; ## Move past k_index
            if ( $attrDesc[$i]  )
            {
                die "array dimensions > 3 are not supported.";
            }
        }
    }


    if ( $k_index > 0 )
    {
        userDisplay3dArray( $attrName,
                            $attrType,
                            $size,
                            $i_index,
                            $j_index,
                            $k_index,
                            $rawAttrValue );
    }
    elsif   ($j_index > 0 )
    {
        userDisplay2dArray( $attrName,
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
            outputData   $attrName ;
            outputData   "[$i]" ;
            outputData   " $attrType ";
            outputData   $values[$valindex] ;    $valindex++;
            outputData   "\n";
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
            outputData   $attr ;
            outputData   "[$i][$j]" ;
            outputData   " $attrType ";
            outputData   $values[$valindex] ;    $valindex++;
            outputData   "\n";
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
                outputData   $attr ;
                outputData   "[$i][$j][$k]" ;
                outputData   " $attrType ";
                outputData   $values[$valindex] ;    $valindex++;
                outputData   "\n";
            }   ##  endfor k
        }   ##  endfor j
    }   ##  endfor i
}



sub cronusTargetStr()
{
    my  ( $targetType_hexstr, $pos, $unitPos, $flag_node, ) =   @_;

    ## This array matches what is in fapi2/include/target_types.H
    my %types = (
                 "00000000" => "sys",
                 "00000001" => "dimm",
                 "00000002" => "pu",
                 "00000003" => "memb",
                 "00000004" => "pu.ex",
                 "00000005" => "memb.mba",
                 "00000006" => "pu.mcs",
                 "00000007" => "pu.xbus",
                 "00000008" => "pu.abus",
                 "00000009" => "memb.l4",
                 "0000000a" => "pu.c",
                 "0000000b" => "pu.eq",
                 "0000000c" => "pu.mca",
                 "0000000d" => "pu.mcbist",
                 "0000000e" => "pu.mi",
                 "0000000f" => "pu.capp",
                 "00000010" => "pu.dmi",
                 "00000011" => "pu.obus",
                 "00000012" => "pu.nv",
                 "00000013" => "pu.sbe",
                 "00000014" => "pu.ppe",
                 "00000015" => "pu.perv",
                 "00000016" => "pu.pec",
                 "00000017" => "pu.phb",
                 "00000018" => "pu.mc",
                 "00000019" => "pu.omi",
                 "0000001a" => "pu.omic",
                 "0000001b" => "pu.mcc",
                 "0000001c" => "ocmb",
                 "0000001d" => "ocmb.mp",
                 "0000001e" => "pu.nmmu",
                 "0000001f" => "reserved_z",
                 "00000020" => "pu.pau",
                 "00000021" => "pu.iohs",
                 "00000022" => "pu.fc",
                 "00000023" => "pmic",
                 "00000024" => "pu.pauc",
                 "00000025" => "geni2c",
                 );

    my $cro_type = $types{$targetType_hexstr};
    my  $cronusTargetStr;

    # System, dimm, pu and memb have different string
    if($cro_type eq "sys")
    {
        $cronusTargetStr = "target = k0\n";
    }
    elsif(-1 == index($cro_type, "."))
    {
        $cronusTargetStr = (sprintf("target = %s:k0:n0:s0:p%02d\n",
                                    $cro_type, (hex $pos)));
    }
    else
    {
        $cronusTargetStr = (sprintf("target = %s:k0:n0:s0:p%02d:c%02d\n",
                                    $cro_type, (hex $pos), (hex $unitPos)));
    }

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
    my  ( $type, $parseDescRef )   =   @_;

    my  $size       =   8;      ##  default
    my  $num        =   1;      ##  default
    my  $enum       =   0;      ##  default
    my  $totalSize  =   1;

    $_  =   $type;
    if ( m/u8/  )   {   $size   =   1;  }
    if ( m/u16/ )   {   $size   =   2;  }
    if ( m/u32/ )   {   $size   =   4;  }
    if ( m/u64/ )   {   $size   =   8;  }
    if ( m/s8/  )   {   $size   =   1;  }
    if ( m/s16/ )   {   $size   =   2;  }
    if ( m/s32/ )   {   $size   =   4;  }
    if ( m/s64/ )   {   $size   =   8;  }

    ##  @TODO RTC 68517 Add code to display non-simple non-integer types

    $totalSize  =   $size;

    ##  remove size spec
    s/[us][0-9]*[e]*//;

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
    outputData   "\n    ";
    foreach (@twobytes)
    {
        outputData "$_ ";
        $count++;
        if (!($count % 8))
        {
            outputData "\n    ";
        }
    }
    outputData "\n";
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

