#!/usr/bin/perl -w
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/trace/tracehash_hb.pl $
#
# OpenPOWER HostBoot Project
#
# COPYRIGHT International Business Machines Corp. 2011,2014
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
# File tracehash.pl created by B J Zander.
# 05/08/2011 - Update by andrewg to work in host boot environment

use strict;

sub determine_args();
sub launch_cpp_and_parse($$);
sub cpp_dir($);
sub read_string_file();
sub collect_files($);
sub assimilate_file($);
sub hash_strings();
sub write_string_file();
sub help();

select (STDERR);
$| = 1;		# Make all prints to STDERR flush the buffer immediately
select (STDOUT);
$| = 1;		# Make all prints to STDOUT flush the buffer immediately

# Constants
my $HEAD_SEP = "|||";
my $HEAD_EYE_CATCHER = "#FSP_TRACE_v";
my $HEAD_BUILD_FLAG = "BUILD:";
my $HEAD_VER_FLAG = 2;
my $BB_STRING_FILE = "/opt/fsp/etc/BB_StringFile";

# Global Variables
my $debug = 0;
my $seperator = "&&&&";
my $file_name = "trexStringFile";
my $in_sand;
my ($backing) = $ENV{'bb'};
my $hash_prog = "trexhash";    #default to in path
my $build = ""; 
my ($sandbox) = $ENV{'SANDBOX'} || "";
my ($context) = $ENV{'CONTEXT'} || "";
my ($sandboxbase) = $ENV{'SANDBOXBASE'} || "";
my ($bb);
my ($sourcebase) = "$sandboxbase/src";
my ($version) = $HEAD_VER_FLAG; # default to oldest version
my ($collect) = 0;
my ($INCLUDE, $Arg, $file, $dir, $string_file);
my $args = "";

my $fail_on_collision = 0; # 1 = exit with error if hash collision occurs
my $hash_filename_too = 0; # 1 = hash is calculated over format string + filename

print "sourcebase = $sourcebase\n" if $debug;
print "sandbox = $sandbox\n" if $debug;
print "backing = $backing\n" if $debug;
print "context = $context\n" if $debug;

if ($context =~ /x86/)
{
    $bb = "i586-pc-linux-gnu";
}
else
{
    $bb = "powerpc-linux";
}

if(($sourcebase =~ /\w+/) && ($sandbox =~ /\w+/))
{
    $INCLUDE = "-I $sandboxbase/export/$context/fips/include  -I $backing/export/$context/fips/include -I /opt/fsp/$bb/include/fsp -I/opt/fsp/$bb/include/ -include /opt/fsp/$bb/include/fsp/tracinterface.H";
}
else
{
    print "Not in Sandbox so guessing Include Paths...\n" if $debug;
    $INCLUDE = "-I/opt/fsp/i586-pc-linux-gnu/include/fsp -I/opt/fsp/i586-pc-linux-gnu/include/ -include /opt/fsp/i586-pc-linux-gnu/include/fsp/tracinterface.H";
}

# I/P Series work in ODE sandbox env.
if ($sandboxbase =~ /\w+/)
{
    $in_sand = 1;
    print "backing = $backing\n" if $debug;
}
else
{
    $in_sand = 0;
}



#  Parse the input parameters.

while (@ARGV) {
    $Arg = shift;

    if ($Arg eq "-h" || $Arg eq "-H") {
        help();
        exit(127);
    }
    if ($Arg eq "-f") {
        $file = shift;
        next;
    }
    if ($Arg eq "-d") {
        $dir = shift;
        next;
    }
    if ($Arg eq "-s") {
        $string_file = shift;
        next;
    }
    if ($Arg eq "-c") {
        $collect = 1;
        next;
    }
    if ($Arg eq "-v") {
	$debug = 1;
	print "debug on\n" if $debug;
	next;
    }
    if ($Arg eq "-C") { # fail if a hash collision is detected
        $fail_on_collision = 1;
        next;
    }
    if ($Arg eq "-F") { # hash is calculated over format string + file name
        $hash_filename_too = 1;
        next;
    }
    if ($Arg eq "-S") {
        $BB_STRING_FILE = "";
        next;
    }

    #just pass it onto compiler
    $args = $args . " " . $Arg;
}

print "args = $args\n" if $debug;

if (!$file && !$dir && !$in_sand) {
    help();
    exit(127);
}

#################################
#          M A I N              #
#################################

my $clock = `date`;

$build = $HEAD_EYE_CATCHER . "$HEAD_VER_FLAG" . $HEAD_SEP . $clock . $HEAD_SEP  . $HEAD_BUILD_FLAG;

$build =~ s/\n//g;

# Global array to hold the parsed TRAC macro calls.
my @strings = ();

# Assoc. arrays to hold hash|string values.
my %string_file_array = ();
my %hash_strings_array = ();

# Check all provided arguments and look for defaults if not provided by user
determine_args();

# Scan the appropriate files or directories for TRAC macro calls.

if (defined $dir)
{

    $build = $build . $dir; # default to put at top of string file
    if($collect)
    {
	collect_files($dir);
    }
    else
    {
	cpp_dir($dir);
	# Hash the string that have been scanned.
	%hash_strings_array = hash_strings();
    }
}
else
{
    $build = $build . $file; # default to put at top of string file

    if($collect)
    {
	assimilate_file($file);
    }
    else
    {
	# make sure include path includes directory that file is in
	if($file =~ /^(.+)\/[^\/]+\.C$/)
	{

	    launch_cpp_and_parse($file,$1);
	}
	else
	{
	    # No path in front of file so it has to be local dir
	    launch_cpp_and_parse($file,"./");
	}
	# Hash the string that have been scanned.
	%hash_strings_array = hash_strings();
    }
}

# Read the existing string file into memory.
%string_file_array = read_string_file();

# Write out the new string file. check for collisions of new/old string here
write_string_file();

print "Hashing Started at $clock\n";
$clock = `date`;
print "Hashing Finished at $clock\n";

exit 0;


#################################
#     S U B R O U T I N E S     #
#################################

#=============================================================================
#  Enhance usability by figuring out which build env. we are in
#=============================================================================
sub determine_args() {

 
    # Find trexhash program
    # but only if needed (i.e. not in collect mode)
    if (!$collect) {
        my $tmp = `which $hash_prog`;
        chomp $tmp;

        if ($tmp eq '') {
	    print STDOUT "\nWarning: Program trexhash does not exist in path.\n" if $debug;
	    $hash_prog = "./trexhash";

	    $tmp = `which $hash_prog`;
	    chomp $tmp;
	    if ($tmp eq '') {
	        print STDOUT "\nError: Unable to find trexhash \n";
	        exit(127);
	    }
        }
    }

    # Verify input values.
    if ((!defined $file) && (!defined $dir)) {
	if(!($in_sand))
	{
	    print STDOUT "\nError: No input directory or file provided as input to scan\n";
	    exit(127);
	}

	# Assume they want sandbox scanned
	if($collect)
	{
	    # collect all string files generated by tracepp and merge
	    $dir = "$sandboxbase/obj/";
	}
	else
	{
	    # generate our own string file by pre-compiling all source code
	    $dir = "$sandboxbase/src/";
	}
	print STDOUT "\n-f <file> or -d <dir> not found...scanning $dir by default\n\n";
    }

    if (!defined $string_file)
    {
	if ($in_sand)
	{

	    # Copy the current string file from backing build into our sandbox
	    system ("cp $backing/obj/$file_name $sandboxbase/obj/$file_name")
	      if !(-e "$sandboxbase/obj/$file_name");

	    $string_file = "$sandboxbase/obj/$file_name";
	}
	else
	{
	    $string_file = "./$file_name";
	}
	print STDOUT "-sf <string_file> not specified, using $string_file instead...\n\n" if $debug;

    }

    # Try Creating the string file
    `touch $string_file`;

    if (! -f $string_file) {
	print STDOUT "\nError: File $string_file does not exist.  Current directory may not be writable.\n\n";
	help();
	exit(127);
    }

    # Make sure trexStringFile is readable/writeable
    system("chmod ugo+rw $string_file");

}

#=============================================================================
#  Launch cpp script and grab input from it looking for trace calls.
#=============================================================================
sub launch_cpp_and_parse($$) {

    my ($l_loc, $l_dir) = @_;

    print "Processing file $l_loc\n" if $debug;
    my $cmd = "/usr/bin/cpp $INCLUDE -I $l_dir $args $l_loc|";
    print "$cmd\n" if $debug;
    open(FH,"$cmd")
      or die ("Cannot open $_:$!,stopped");

    # Read through all lines in the file..
    my $line = <FH>;
    while (defined $line)
    {
	chop $line;         # remove EOL
	$line =~ s/^\s*//;  # remove unneccesary beginning white space.
	$line =~ s/\s*$//;  # remove unneccesary ending white space.
	# Look for lines that are trace macro calls.
	#if (/(trace_adal_hash)(\()( *)(".+")(,)(\d)/)
	#if ($line =~ /(.*?)(trace_adal_hash)(\()( *)(".+")(,)(\d)\)+(.*\d.*)/)
	while($line =~ m/^(.*?)trace_adal_hash\s*\(\s*(("[^"]*"\s*)+),\s*(\d+)\s*\)(.*)$/)
	{
	    my ($prefix, $strings, $salt, $suffix) = ($1, $2, $4, $5);
	    print STDOUT "$strings $salt\n" if $debug;
	    $strings =~ s/"\s*$//; # remove trailing " and space
	    $strings =~ s/^"//;    # remove leading "
	    $strings =~ s/"\s*"//g;
	    # Check to see if it's contained on a single line, or if we
	    # have to combine lines to get a complete trace call.

	    # Save the macro call so it can be hashed later..
	    push (@strings, [$l_loc, $strings, $salt]);
	    $line = $suffix; # check rest of line for a second trace call
	}
	my $nextline = <FH>;
	last if !defined $nextline;
	# if a trace call is spread over multiple lines we have to add the next
	# line from the source. the only problem is the definition/declaration
	# of trace_adal_hash: we have to ignore that. we catch that by requiring
	# a " after the function name. hopefully nobody writes a comment with
	# a " after the function declaration ...
	if ($line =~ /trace_adal_hash.*"/) {
		$line .= $nextline;
	} else {
		$line = $nextline;
	}
    }
    close(FH);
}

#=============================================================================
#  run cpp on all files in this directory and return the output
#=============================================================================
sub cpp_dir($) {

    my ($l_dir) = @_;
    my @dir_entry;
    my $l_entry;

    # Open the directory and read all entry names.
    opendir ( DH , "$l_dir")
      or die ("Cannot open $l_dir: $!, stopped");

    print STDOUT "Processing directory $l_dir\n" if $debug;
    @dir_entry = readdir(DH);
    closedir(DH);

    while (@dir_entry) {
        $l_entry = shift(@dir_entry);

        if ($l_dir =~ m"/$") {
            $l_entry = "$l_dir$l_entry";
        }
        else {
            $l_entry = "$l_dir/$l_entry";
        }

        # Is the entry a directory?
        if (-d $l_entry) {

	    if($l_entry =~ m"/?([^/]+)$")
	    {
		# check dir we are going into
		print "dir = $1\n" if $debug;
		# should we recurse into this directory.
		if ($1 =~ m/^(\.\.?|sim[ou]|bldv)$/)
		{
		    next; # skip '.', '..' and some fips dirs
		}
		cpp_dir($l_entry);
	    }
	    else
	    {
		# unable to determine name of dir (no / in filename)
		# should we recurse into this directory.
		if ($l_entry =~ m/^(\.\.?|sim[ou]|bldv)$/)
		{
		    next; # skip '.', '..' and some fips dirs
		}
		cpp_dir($l_entry);
	    }
        }
        # Is the entry a file?
        elsif ((-f $l_entry) && ($l_entry =~ m/\.C$/)) {
	    # it's a file so
	    launch_cpp_and_parse($l_entry,$l_dir);
        }
        else {
            # Not a file or directory so ignore it...
        }
    }
}

#=============================================================================
#  Read in strings from the existing trace string file....
#=============================================================================
sub read_string_file() {

    my %o_strings;
    my ($line) = "";
    my ($l_hash) = "";
    my ($l_str) = "";
    my ($cur_build) = "";
    my ($l_file) = "";


    # Make sure we can open each file.
    open ( FH , "<$string_file")
      or die ("Cannot open $_: $!, stopped");

    $line = <FH>;

    print "first line in trexStringFile= $line\n" if $debug;

    if((defined $line) && ($line =~ /^$HEAD_EYE_CATCHER(\d)/))
    {
	$version = $1;

	print "version = $version\n" if $debug;

	#Always put latest version in file
	$line =~ s/^$HEAD_EYE_CATCHER\d/${HEAD_EYE_CATCHER}${HEAD_VER_FLAG}/;

	# Take previous version in file and use it.
	$build = $line;
	chomp($build);
	$line = <FH>;

	while (defined $line) {
	    chomp $line;         # remove EOL
	    if($version eq "1")
	    {
		($l_hash, $l_file ,$l_str) = split(/\|\|/, $line);
	    }
	    elsif($version eq "2")
	    {
		($l_hash, $l_str ,$l_file) = split(/\|\|/, $line);
	    }
	    else
	    {
		print "Unknown version of stringfile $version\n";
		exit(127);
	    }
	    $o_strings{$l_hash} = $l_str . "||" . $l_file;
	    $line = <FH>;
	}

    }
    else
    {	  # If there is a file then we are dealing with the first
	  # version of trexStringFile so don't look for file name.
	if ($debug) {
		print "version 0 stringfile detected: $string_file\n";
	}

	# there is a file and it doesn't have a header
	$version = 0;

	while (defined $line) {
	    chomp $line;         # remove EOL
	    ($l_hash,$l_str) = split(/\|\|/, $line);
	    $o_strings{$l_hash} =$l_str . "||" . "NO FILE";
	    $line = <FH>;
	}
    }

    close(FH);

    #Time to look for a building block string file
    if($BB_STRING_FILE ne "" and $string_file ne $BB_STRING_FILE and -f $BB_STRING_FILE)
    {

	# Make sure we can open the file.
	open ( FH , "<$BB_STRING_FILE")
	  or die ("Cannot open $_: $!, stopped");

	$line = <FH>;

	print "first line in BB_StringFile = $line\n" if $debug;
	if((defined $line) && ($line =~ /^$HEAD_EYE_CATCHER(\d)/))
	{
	    $version = $1;

	    $line = <FH>;
	    while (defined $line)
	    {
		chop $line;         # remove EOL
		if($version eq "1")
		{
		    ($l_hash, $l_file ,$l_str) = split(/\|\|/, $line);
		}
		elsif($version eq "2")
		{
		    ($l_hash, $l_str ,$l_file) = split(/\|\|/, $line);
		}
		#($l_hash, $l_file ,$l_str) = split(/\|\|/, $line);
		$o_strings{$l_hash} = $l_str . "||" . $l_file ;
		$line = <FH>;
	    }
	}
	else
	{
	    print "*** ERROR: BB_StringFile '$BB_STRING_FILE' should always have version!!!\n"
	}

    }
    else
    {
	print "$BB_STRING_FILE is not available\n" if $debug;
    }
    #All files are latest version now.
    $version = $HEAD_VER_FLAG;
    return %o_strings;
}

#=============================================================================
#  Read in strings from the existing trace string file....
#=============================================================================
sub collect_files($) {

    my ($l_dir) = @_;
    my (@dir_entry);
    my ($l_entry) = "";

    # Open the directory and read all entry names.
    opendir ( DH , "$l_dir")
      or die ("Cannot open $l_dir: $!, stopped");

    print STDOUT "Processing directory $l_dir\n" if $debug;
    @dir_entry = readdir(DH);
    closedir(DH);

    while (@dir_entry) {
        $l_entry = shift(@dir_entry);

        if ($l_dir =~ m"/$") {
            $l_entry = "$l_dir$l_entry";
        }
        else {
            $l_entry = "$l_dir/$l_entry";
        }

        # Is the entry a directory?
        if (-d $l_entry) {

            # should we recurse into this directory.
	    if ($l_entry =~ m/\/(\.\.?|sim[ou]|bldv)$/)
	    {
		next; # skip '.', '..' and some fips dirs
	    }
	    collect_files($l_entry);
        }
        # Is the entry a file?
        elsif ((-f $l_entry) && ($l_entry =~ m"\.hash$")) {
	    # it's a file so
	    assimilate_file($l_entry);
        }
        else {
            # Not a file or directory so ignore it...
        }
    }

}

#=============================================================================
#  Read in data from file and add to master one
#=============================================================================
sub assimilate_file($) {

    my ($l_loc) = @_;

    my (%o_strings);
    my ($line) = "";
    my ($l_hash) = "";
    my ($l_str) = "";
    my ($l_file) = "";

    # Make sure we can open each file.
    open ( FH , "<$l_loc")
      or die ("Cannot open $_: $!, stopped");

    $line = <FH>;

    print "Assimilate: first line in $l_loc = $line" if $debug;

    if((defined $line) && ($line =~ /^$HEAD_EYE_CATCHER(\d)/))
    {
	$version = $1;
	if ($version eq "1") {
	    if ($hash_filename_too) {
	    	print "*** ERROR: hash_filename_too (-F) isn't possible with trace version 1\n";
		print "           please rebuild all .hash files and global trexStringFile\n";
		print "           version 1 file is '$l_loc'\n";
		exit(127);
	    }
	} elsif ($version ne "2") {
	    print "Unknown version of stringfile $version\n";
	    exit(127);
	}

	$line = <FH>;

	while (defined $line) {
	    chop $line;         # remove EOL

	    # 64 bit support
	    $line =~ s/\%(\d*)(\.?)(\d*)(?:h?|l{0,2}|L?)d\b/\%$1$2$3lld/g;
	    $line =~ s/\%(\d*)(\.?)(\d*)(?:h?|l{0,2}|L?)i\b/\%$1$2$3lld/g;
	    $line =~ s/\%(\d*)(\.?)(\d*)(?:h?|l{0,2}|L?)u\b/\%$1$2$3llu/g;
	    $line =~ s/\%(\d*)(\.?)(\d*)(?:h?|l{0,2}|L?)x\b/\%$1$2$3llx/g;
	    $line =~ s/\%(\d*)(\.?)(\d*)(?:h?|l{0,2}|L?)X\b/\%$1$2$3llX/g;
	    $line =~ s/\%p/0x\%llX/g;   # Replace pointer format with hex value
	    #print "line: $line\n";

	    if($version eq "1")
	    {
		($l_hash, $l_file ,$l_str) = split(/\|\|/, $line);
	    }
	    elsif($version eq "2")
	    {
		($l_hash, $l_str ,$l_file) = split(/\|\|/, $line);
	    }
	    my $newstring = $l_str . "||" . $l_file;
	    if (exists $hash_strings_array{$l_hash}) {
		my $hashstr1 = $hash_strings_array{$l_hash};
		my $hashstr2 = $newstring;
		if (!$hash_filename_too) {
		    # hash was made over format string only, remove file name
    		    $hashstr1 =~ s/\|\|.*$//;
    		    $hashstr2 = $l_str;
		}
		if ($debug) {
		    print "a_f: compare $hashstr1\n",
		          "     vs.     $hashstr2\n";
		}
		if ($hashstr1 ne $hashstr2)
		{
		    print "*** ERROR: HASH Collision! (a_f)\n",
			  "    Two different strings have the same hash value ($l_hash)\n",
			  "    String 1: $hash_strings_array{$l_hash}\n",
			  "    String 2: $newstring\n";
		    if ($fail_on_collision) {
		    	exit(1);
		    }
		}
	    }
	    $hash_strings_array{$l_hash} = $newstring;
	    $line = <FH>;
	}

    }
    else
    {	# If there is a file then we are dealing with the first
	# version of trexStringFile so don't look for file name.
	# these files shouldn't be there anymore. we don't check for collisions here
	if ($debug) {
	    print "version 0 stringfile detected: $string_file\n";
	}

	if(defined $line)
	{
	    # there is a file and it doesn't have a header
	    $version = 0;
	}

	while (defined $line) {
	    chop $line;         # remove EOL
	    ($l_hash,$l_str) = split(/\|\|/, $line);
	    $hash_strings_array{$l_hash} = $l_str . "||" . "NO FILE";
	    $line = <FH>;
	}
    }
    $version = $HEAD_VER_FLAG;
    close(FH);
}

#=============================================================================

#=============================================================================
sub hash_strings() {

    my ($hash_val, $l_key, $l_hash, %l_hash_strings);
    my ($line_feed) = chr(10);
    my ($l_file_name) = "NO FILENAME";
    print "\nHashing printf strings.\n\n";

    foreach my $str (@strings) {
    	my $printf_string;
	$l_file_name = $str->[0];
	$printf_string = $str->[1];
	$l_key = $str->[2];
	print "printf_string = $printf_string\n" if $debug;
	$printf_string =~ s/"\s?"//g; #multi line traces will have extra " in them
	$printf_string =~ s/`/\\`/g; # excape '
	$printf_string =~ s/\\n/$line_feed/g; # escape \n
	if ($hash_filename_too) {
	    $printf_string .= "||" . $l_file_name;
	}

	# call the hasher.
	print "$hash_prog \"$printf_string\" $l_key\n" if $debug;
	$hash_val = `$hash_prog \"$printf_string\" $l_key`;
	if ($?) {
		my ($hp_ret, $hp_sig) = ($? >> 8, $? & 127);
		if ($hp_sig) {
			print "*** ERROR: $hash_prog died with signal $hp_sig\n";
		} elsif ($hp_ret) {
			print "*** ERROR: $hash_prog returned the error $hp_ret\n";
			if ($hash_val) {
				print "   error from $hash_prog:\n$hash_val";
			}
		}
		exit(1);
	}
	print "printf_string = $printf_string l_key = $l_key hash val = $hash_val\n" if $debug;

    	# undo escaping
	$printf_string =~ s/$line_feed/\\n/g;
        $printf_string =~ s/\\`/`/g;

	if (exists $l_hash_strings{$hash_val})
	{
	    # hash val was found before. check if it's the same string
	    # else we have a hash collision
	    my $l_tmp = $l_hash_strings{$hash_val};
	    if (!$hash_filename_too) {
	    	$l_tmp =~ s/\|\|.*$//;
	    }
	    if ($l_tmp ne $printf_string)
	    {
		print "*** ERROR: HASH Collision! (h_s)\n",
		      "    Two different strings have the same hash value ($hash_val)\n",
		      "    String 1: $l_hash_strings{$hash_val}\n",
		      "    String 2: $printf_string (file $l_file_name)\n";
		if ($fail_on_collision) {
		    exit(1);
		}
	    }
	}
	# this will overwrite an old string with a new one if a collision occurred
	# but we might want to bail out in this case anyway
	$printf_string = $printf_string . "||" . $l_file_name;
	$l_hash_strings{$hash_val} = $printf_string;
    }	
    return %l_hash_strings;
}
#=============================================================================

#=============================================================================
sub write_string_file() {

    my (@keys) = ();
    my ($l_key) = "";

    # Combine the contents of the existing string file with the trace calls
    # that we have just hashed.
    print STDOUT "\nCombining Hash strings...\n\n";

    @keys = keys(%hash_strings_array);

    foreach $l_key (@keys) {
	my $l_tmp = $hash_strings_array{$l_key}; # freshly collected strings
	if (exists $string_file_array{$l_key})
	{ # hash exists in list from trexStringFile
	    my $l_tmp2 = $string_file_array{$l_key};
    	    if (!$hash_filename_too) {
		$l_tmp =~ s/\|\|.*$//;
		$l_tmp2 =~ s/\|\|.*$//;
	    }

            # Check for hash collisions.
            if ($l_tmp ne $l_tmp2)
            {
		print "*** ERROR: HASH Collision! (w_s_f)\n",
		      "    Two different strings have the same hash value ($l_key)\n",
		      "    String 1: $hash_strings_array{$l_key}\n",
		      "    String 2: $string_file_array{$l_key}\n";
		if ($fail_on_collision) {
		    exit(1);
		}
		# don't fail, write new one
            }
	}
	if($version > 0)
	{
	    # add/replace the new string to the string_file_array.
	    $string_file_array{$l_key} = $hash_strings_array{$l_key}
	}
	else
	{
	    # old version so only write out format string (not file name to)
	    $string_file_array{$l_key} = $l_tmp;
	}
    }

    # Write out the updated string file.
    print STDOUT "\nWriting updated hash||string file ($string_file)...\n\n";

    @keys = sort(keys(%string_file_array));

    open ( FH , ">$string_file")
      or die ("Cannot open $_: $!, stopped");

    if($version > 0)
    {
	print FH "$build\n"; # only print version if newer then version 0
    }
    foreach $l_key (@keys) {
        print FH "$l_key||$string_file_array{$l_key}\n";
    }
    close FH;
}
#=============================================================================

#=============================================================================
#  Display command invokation help for this program...
#=============================================================================
sub help() {
    print << "EOF";
tracehash.pl - create a trace string file from sources or collect tracepp files
Usage: tracehash.pl [options]
    General options:
      -h   - Print this help text.
      -v   - Be verbose, tell what's going on (debug output)
    Operation modes
      -c   - Collect StringFiles created by tracepp and merge.
      default - Scan source files for trace calls.

Collect mode: tracehash.pl -c [-vFCS] [-d <dir>] [-s <string_file>]
              tracehash.pl -c [-vFCS] [-f <file>] [-s <string_file>]
    Collect string files created by tracepp (.hash) from directory tree at
    <dir> or read them from string file <file> and write to file
    <string_file>, adding entries already in this file.
      -f   - String file to read and write/add to <string_file>.
      -d   - Start of directory tree to scan for .hash files. Default = .
      -s   - File with trace strings (and hashes) to read from and write to
             default = ./trexStringFile
      -F   - hash is calculated over trace string and source file name,
             otherwise without source file name
      -C   - report an error if a hash collisions occurs
      -S   - don't read global FLD-2.2 string file ($BB_STRING_FILE)
    If tracehash.pl is called in a FipS build sandbox without -d and -f
    defaults for the sandbox will be used.

Scan mode: tracehash.pl [-vFCS] [-d <dir>] [-s <string_file>] [ccpopts]
           tracehash.pl [-vFCS] [-f <file>] [-s <string_file>] [cppopts]
    Scan all files in directory tree <dir> or scan file <file> and write
    strings to file <string_file>. Strings already in this file will be merged.
      -f   - Source file to scan for trace entries.
      -d   - Source directory to scan for trace entries.
      -s   - File with trace strings (and hashes) to read from and write to.
             default = ./trexStringFile
      -F   - hash for string was build from format string + source file name
      -C   - report an error if hash collisions occur
      -S   - don't read global FLD-2.2 string file ($BB_STRING_FILE)
      All other arguments will be passed verbatim to cpp
EOF
}
#=============================================================================

