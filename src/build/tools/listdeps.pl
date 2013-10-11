#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/listdeps.pl $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2013
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
# 1. Create a hash with all library names and function names as the key-pair
#    value.
# 2. Get a list of all undefined functions from the istep modules.
# 3. Figure out which libraries are required for each istep using the two lists
#    above.
#
#   NOTE:  The script only checks the first level of dependency for each module.

use strict;
use File::Find ();
use File::Path;
use Cwd;

use constant MAX_DEPENDENT_MODULES => 6;

# validate the number of input args
if( $#ARGV == -1 || $#ARGV > 4 )
{
    usage();
}

# return -1 if we fail validation, otherwise default to success
my $rc = 0;

# directory where modules (.so's) are located, passed in from cmdline
my $image_directory = shift;

if( $image_directory eq "-h" || $image_directory eq "--help")
{
    usage();
}

# the name of a specific module to check
my $module_to_check = "";

my $count = $#ARGV+2;

# should we validate against the existing
# g_istepDep structure?
my $validate_deps =  0;

# print out the depedancies for each module
my $print_deps = 0;

# list all, event resident modules
my $list_all = 0;

while ( $count )
{
    $count--;

    my $arg = shift;

    next if( $arg eq "" );

    if( $arg eq "-h" || $arg eq "--help")
    {
        usage();
    }

    if( $arg eq "-v" )
    {
        $validate_deps = 1;
    }
    elsif( $arg eq "-p" )
    {
        $print_deps = 1;
    }
    elsif( $arg eq "-All" )
    {
        $list_all = 1;
    }
    else
    {
        $module_to_check = $arg;
    }
}

# dont allow a validation for list all option
if( $list_all && $validate_deps )
{
    printf("\nSorry not able to validate non-istep modules please ");
    printf("remove either the or the -All option and try again.\n\n");
    exit;
}

# go to the image directory passed in
chdir "$image_directory";

my $module_name;
my $depends;
my %FunctionMap;

#slurp in all the modules names from the img directory
my @module_names = < *[!_][!r][!t].so >;

my $PREFIX = $ENV{'CROSS_PREFIX'};

# for each module, grab the defined functions and create a hash
# with the key being the function name and the value returned as the
# shared library where it is defined.
foreach $module_name  (@module_names )
{
    my @output = `${PREFIX}nm -AD  --defined-only $module_name`;

    chomp @output;

    foreach my $line (@output)
    {
        my @values = split(':', $line);

        my $library = $values[0];

        @values = split( ' ' , $line );

        my $function = $values[2];

        %FunctionMap->{ $function } =  $library;
    }
}

# if there was a library name passed in use that
# otherwise if they asked to list all dependencies
# then use the list we already created above,
# default is to the list required libs of istep modules
my @istep_modules = ();

if( $module_to_check )
{
    @istep_modules = ( $module_to_check );
}
elsif ( $list_all )
{
    @istep_modules = @module_names;
}
else
{
    @istep_modules = (
        "libslave_sbe.so",
        "libnest_chiplets.so" ,
        "libedi_ei_initialization.so" ,
        "libactivate_powerbus.so" ,
        "libmc_config.so" ,
        "libdram_training.so" ,
        "libdram_initialization.so" ,
        "libsbe_centaur_init.so" ,
        "libdmi_training.so" ,
        "libbuild_winkle_images.so" ,
        "libcore_activate.so" ,
        "libestablish_system_smp.so" ,
        "libstart_payload.so" ,
        "libocc.so" ,
    );
}

# list of libs which are not unloaded
my %resident_modules = (
    "libtargeting.so"      => '1',
    "libhwas.so"           => '1' ,
    "libdevicefw.so"       => '1',
    "liberrl.so"           => '1',
    "libtrace.so"          => '1',
    "libvfs.so"            => '1',
    "libfapi.so"           => '1',
    "libecmddatabuffer.so" => '1',
    "libpnor.so"           => '1',
    "libmbox.so"           => '1',
    "libinitservice.so"    => '1',
    "libistepdisp.so"      => '1',
    "libextinitsvc.so"     => '1',
    "libplat.so"           => '1',
    "libhwp.so"            => '1',
    "libbus_training.so"   => '1',
    "libintr.so"           => '1',
    "libprdf.so"           => '1',
    "libmdia.so"           => '1',
    "libattn.so"           => '1',
    "libi2c.so"            => '1',
    "libutil.so"           => '1',

);

# has with library to istep list file were the DepMod array is kept
my %istepFiles = (
    "libslave_sbe.so"               => "istep06list.H" ,
    "libnest_chiplets.so"           => "istep07list.H" ,
    "libedi_ei_initialization.so"   => "istep08list.H" ,
    "libactivate_powerbus.so"       => "istep09list.H" ,
    "libsbe_centaur_init.so"        => "istep10list.H" ,
    "libdmi_training.so"            => "istep11list.H" ,
    "libmc_config.so"               => "istep12list.H" ,
    "libdram_training.so"           => "istep13list.H" ,
    "libdram_initialization.so"     => "istep14list.H" ,
    "libocc.so"                     => "istep15list.H" ,
    "libbuild_winkle_images.so"     => "istep15list.H" ,
    "libcore_activate.so"           => "istep16list.H" ,
    "libestablish_system_smp.so"    => "istep18list.H" ,
    "libstart_payload.so"           => "istep21list.H" ,
);

# array to hold list of dependent libraries
my @Dependencies;

# hash to help with unique module names
my %seen = ();

foreach my $module_name  (@istep_modules )
{
    if( $list_all )
    {
       %seen = ();
    }
    else
    {
        %seen = %resident_modules;
    }

    @Dependencies = ();

    # the library will have a dependency on itself
    push(@Dependencies, $module_name);

    # get an array with all the undefined functions from this module
    my @output = `${PREFIX}nm --undefined-only $module_name`;

    chomp @output;

    foreach my $line (@output)
    {
        my @values = split( ' ' , $line );

        my $elem = $values[1];

        my $lib = %FunctionMap->{ $elem};

        # if we have this module in our "seen it" array, just skip it
        # otherwise we will add it as a new dependency
        next if $seen{ $lib }++;
        push @Dependencies, $lib;

    }

    # should we validate?
    if( $validate_deps )
    {
        validate( $module_name, %istepFiles->{$module_name} );
    }

    # does user want us to print the dependencies to the screen?
   if( $print_deps )
   {
       # print out the list of dependencies for this
       # particular library
       print ( "$module_name requires => \n");

       foreach my $required_lib ( @Dependencies )
       {
           $_ = $required_lib;
           next if ( m/test/ );
           next if ( !m/lib/ );
           if( $list_all )
           {
               # just print it for looking..
               print "\t\t$required_lib\n";
           }
           else
           {
               #format so I can cut and paste
               print "\t\tDEP_LIB($required_lib),\n";
           }
       }
       print "\n";
   }
}

exit($rc);

#/====================== S U B R O U T I N E S ===============================/

# validate the current dependencies for the passed in module name
# NOTE: the @Dependencies array is a global constructed above.
sub validate
{
    my @list = ();

    my ($module, $istepFile ) = @_;

    my $path = "../src/include/usr/isteps/";

    my $file = $path . $istepFile;

    open FILE, "< $file" or die $!;

    # read the file one line at a time until we find the
    # spot we are looking for
    while(<FILE>)
    {
        my $line = $_;
        next if ( !m/DEP_LIB/ );
        chomp($line);
        $line =~ s/^\s*(.*?)\s*$/$1/;
        $line =~s/DEP_LIB\(//;
        $line =~s/\),.*//;
        #print "$line\n";
        push( @list,$line);
        # we are at the start of the dependencies list
        # lets go into a new read till we find the  closing
        # bracket of the array;
        while(<FILE>)
        {
             my $line = $_;
             chomp($line);
             last if( m/\}/ );

             if (!($line =~ m/DEP_LIB/)) { next; }

             $line =~ s/^\s*(.*?)\s*$/$1/;
             $line =~s/DEP_LIB\(//;
             $line =~s/\),//;
             #     print "$line\n";
             push( @list, $line );
        }
        if( @list >= MAX_DEPENDENT_MODULES )
        {
            print "\n-- WARNING -- too many dependencies listed (MAX=".
                  (MAX_DEPENDENT_MODULES-1).") in";
            print " src/include/usr/isteps/$istepFile\n\n";
        }
    }

    # ok we have a list of dependencys from the actual istepXXlist.H file
    # convert array to a hash with the array elements as the hash keys,
    # the value is not important, so I set them all to 1
    my %ListedDeps = map {$_ => 1} @list;

    foreach my $match ( @Dependencies )
    {
        # check if the there exists a match
        if ( !(defined $ListedDeps{$match}) && ($match) &&
             !(defined $resident_modules{ $match } ) )
        {
          print "$module is MISSING DEPENDENCY $match\n";
          print "\nplease add \"DEP_LIB($match),\"";
          print "  to src/include/usr/isteps/$istepFile\n\n";
          $rc = -1;
        }
    }

    close FILE;
}

# the help text
sub usage
{
    print "Usage:\n";
    print "\t$0 <path> [ module to check ]\n\n";

    print "Example: to list all istep modules and dependencies.\n";
    print "\n\t$0 ~/my-hostboot-repo/img -p \n\n";

    print "Example: to validate all istep modules and top level dependencies.\n";
    print "\n\t$0 ~/my-hostboot-repo/img -v \n\n";


    print "Example: to list the dependencies for a specific module.\n";
    print "\n\t$0 ~/my-hostboot-repo/img libslave_sbe.so \n\n";

    print "-v will validate existing istep dependencies\n";
    print "-p will print dependency requirements\n";
    print "-All will print all dependency requirements (not just istep modules)\n";
    print "requires the -p option.\n\n";

    exit 0;
}


