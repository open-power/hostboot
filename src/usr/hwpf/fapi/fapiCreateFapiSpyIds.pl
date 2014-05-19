#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/fapi/fapiCreateFapiSpyIds.pl $
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
use strict; 
use warnings;


#------------------------------------------------------------------------------
# Print Command Line Help
#------------------------------------------------------------------------------
my $numArgs = $#ARGV+1;
print $numArgs;

if ($numArgs < 2)
{
    print ("Usage: fapiCreateFapiSpyIds.pl <input file> <output directory>\n");
    print ("  This script will parse the spy id files and create a set of nested\n");
    print ("  structures in the file fapiSpyIds.H which the FSP will use.\n");
    exit(1);
}

#------------------------------------------------------------------------------
# Globals
#------------------------------------------------------------------------------
my $spyIdFile = $ARGV[0];
my $outDir    = $ARGV[1];
my $outFile  = "fapiSpyIds.H";
my $UTFile   = "fapiSpyIdsUT.C";
$outFile = $outDir . $outFile; 
my %structureNames;
my $somenumber;
my %currentmembers;

#------------------------------------------------------------------------------
# Prototypes 
#------------------------------------------------------------------------------
sub buildStructures( \@ );
sub createTest();
sub addTest($$);
sub closeTest();

#------------------------------------------------------------------------------
# Open input and output files for our use.
#------------------------------------------------------------------------------
open(IDFILE, "<", $spyIdFile) or die "ERROR $? : cant open $spyIdFile : $!";
open(OUTFILE, ">", $outFile) or die "ERROR $? : can't open $outFile : $!";
open(UTFILE, ">", $UTFile) or die "ERROR $? : can't open $outFile : $!";

# direct the printf output to the file
select OUTFILE;
#select STDOUT;

createTest();
# read in the entire file to an array
my (@lines) = <IDFILE>;

#------------------------------------------------------------------------------
# Process every line in the file one at a time
#------------------------------------------------------------------------------
foreach my $line (@lines)
{
    $line =~s/^\s+|\s+$//g;
    my @tokens = split(/,/, $line );

    $tokens[1]=~s/\}//;
    $tokens[1]=~s/\"//g;

    # replace a # with __P__
    $tokens[1]=~s/\#/__P__/g;

    # fix a case like this ABC.2CD ==> ABC._2CD
    $tokens[1]=~s/(\.)([0-9])/$1_$2/;

    #get rid of the parens
    $tokens[0]=~s/\{//;

    my $structure=$tokens[1];
    my $number=$tokens[0];

    #create a hash for later use
    $structureNames{ $structure } = $number;

}

#sort the hash based on the structure name
my @keys = sort { ( $a cmp $b);  } ( keys %structureNames );

my @array = @keys;

#init the key to some value..
my $current = @keys;
my @name;
my @spaces;

push(@spaces," ");
push(@spaces," ");

# start the file off with a namespace
printf "#ifndef __FAPI_SPY_IDS_H__\n";
printf "#define __FAPI_SPY_IDS_H__ \n\n";
printf "namespace FAPI_SPY_NAMES \n { \n\n";

# look at every entry in the array of names..
foreach my $value (@array)
{
    # segment the name and then search for all
    # entries which have the first value the same
    # and then process those values
    my @members = split(/\./, $value );
    my $member = $members[0];
    @name = ();

    my $size = @members;

    #once we go in here we wont need to look at this value again
    if( $member ne $current  )
    {
        push(@name,$member);

        if( $size > 1 )
        {

            # add some readability;
            printf "@spaces";
            my $extern = "extern struct " . $member . "_component \n";
            printf "$extern";
            printf "@spaces";
            printf"{\n";
            # grab every value out of the array which matches our query
            my @selected = @keys;
            @selected = grep( m/^$member\b/, @selected);
            # modify the stucture names to remove the first member
            my @filtered = map { (my $new = $_) =~ s/$member\.//; $new} @selected;
            $current = $member;
            # passing the shortend structure names
            buildStructures( @filtered );
            printf "@spaces";
            printf"} $member;\n";
        }
        else
        {
                # make the structure back into a name and use it go get
                # the value from the hash we made eariler -- its a global
                my $name = join(".", @name );
                my $number = 0;
                $number = $structureNames{ $name };
                my $struct = "struct " . $member . "_comp";
                addTest( $name, $number );
                printf "@spaces";
                printf "$struct\n";
                printf "@spaces";
                printf "{\n";
                printf "@spaces";
                printf"     static const unsigned int value = $number;\n";
                printf "@spaces";
                printf "} $member;\n";
        }
    }

}
# close out the namespace in the file
printf "};\n";
printf "#endif\n";
close OUTFILE;
close IDFILE;
closeTest();
#done

#------------------------------------------------------------------------------
# Subroutines
#------------------------------------------------------------------------------
sub buildStructures( \@ )
{
    my( $structures ) = @_;

    my @structures = @$structures;

    my $current = 0;
    my $member = 0;

    push( @spaces, " " );
    push( @spaces, " " );

    foreach my $value (@structures )
    {
        my @members = split(/\./, $value );
        my $member = $members[0];
        push( @name, $member );

        my $size = @members;
        #once we go in here we wont need to look at this value again
        if( $member ne $current )
        {
            if( $size > 1 )
            {
                $somenumber += 1;
                my $struct = "struct " . $member . "_comp" . $somenumber . "\n";
                printf "@spaces";
                printf $struct;
                printf "@spaces";
                printf "{\n";
                # grab every value out of the array which matches our query
                my @selected = grep( m/^$member\b/, @structures);
                my @filtered = map { (my $new = $_) =~ s/$member\.//; $new} @selected;
                $current = $member;
                buildStructures( @filtered );
                #take off the last struture member name
                #from the array
                printf "@spaces";
                printf ("} $member;\n");
            }
            else
            {
                # make the structure back into a name and use it go get
                # the value from the hash we made eariler -- its a global
                my $name = join(".", @name );
                my $number = 0;
                $number = $structureNames{ $name };
                my $struct = "struct " . $member . "_comp";
                addTest( $name, $number );
                printf "@spaces";
                printf "$struct\n";
                printf "@spaces";
                printf "{\n";
                printf "@spaces";
                printf"     static const unsigned int value = $number;\n";
                printf "@spaces";
                printf "} $member;\n";
            }
        }
        pop(@name);
    }
   pop( @spaces );
   pop( @spaces );

}


sub createTest()
{
    printf( UTFILE "#include <fapiSpyIds.H>\n");
    printf( UTFILE "#include \"s1_reduced.h\"\n\n");
    printf( UTFILE "#include <iostream>\n\n");
    printf( UTFILE "#define fspSpyId(DATA) FAPI_SPY_NAMES::DATA.value\n");
    printf( UTFILE "int main( void )\n { \n");
    printf( UTFILE "unsigned int  totalTests = 0; \n");
    printf( UTFILE "unsigned int failedTests = 0; \n");
}
sub closeTest()
{

    printf( UTFILE "if( failedTests )\n { \n");
    printf( UTFILE "std::cout << failedTests  << \" of \" << totalTests << \" tests failed \" << std::endl;" );
    printf( UTFILE "}\n");
    printf( UTFILE "else { std::cout << \"+++++ SUCCESS +++++\" << std::endl; \
                           std::cout << totalTests << \" TESTS PASSED\" << std::endl; }" );
    printf( UTFILE "\n\n}\n");
    close(UTFILE);
}

sub addTest( $$ )
{
    my( $name, $number ) = @_;

    # create a name which the FSP understands
     my $fspName = $name;
     $fspName =~ s/__P__/_/g;
     $fspName =~ s/\._/\./g;
     $fspName =~ s/\./_/g;

    $fspName = "SPY_" . $fspName;

    $fspName =~ s/ //g;
#    $fspName =~ s/__/_/g;

    printf( UTFILE "totalTests++;  if ( fspSpyId( $name ) !=  $fspName)\n");
    printf( UTFILE "{ std::cout << \"spy values dont match\" << std::endl; failedTests++;  }\n");

}
