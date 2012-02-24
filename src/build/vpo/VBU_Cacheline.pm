#!/usr/bin/perl
#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/vpo/VBU_Cacheline.pm $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2011 - 2012
#
#  p1
#
#  Object Code Only (OCO) source materials
#  Licensed Internal Code Source Materials
#  IBM HostBoot Licensed Internal Code
#
#  The source code for this program is not published or other-
#  wise divested of its trade secrets, irrespective of what has
#  been deposited with the U.S. Copyright Office.
#
#  Origin: 30
#
#  IBM_PROLOG_END
#
# Name:     hb-modify-cacheline.pm
#
# Purpose:  routines for reading and writing a 64-bit value into L3 in an 
#           AWAN session.  Accepts an address into L3, and 64-bit data hex word
#           (write).
#           VBU can only read/write to memory in 128-byte cachelines, so if 
#           we want to write a memory location we must read in the entire 
#           cacheline, modify the correct byte(s) and then write it back.
#           Called from shell script do_p8vbu_script_hbi*
#           Written in perl because that is what is being used for the debug
#           framework
#
# Author: Mark Wenning
#

package VBU_Cacheline;
require Exporter;

our @ISA        =   qw( Exporter );
our @EXPORT     =   qw( CLread CLwrite RunClocks P8_Ins_Start P8_Ins_Stop P8_Ins_Query SetFlags);

  
#------------------------------------------------------------------------------
# Specify perl modules to use
#------------------------------------------------------------------------------
use strict;
use warnings;
use POSIX;
use Fcntl;

## 64-bit input
use bigint;
no  warnings    'portable';

#------------------------------------------------------------------------------
#   Forward declarations
#------------------------------------------------------------------------------
sub CLread;
sub CLwrite;
sub RunClocks;
sub P8_Ins_Start;
sub P8_Ins_Stop;
sub P8_Ins_Query;
sub P8_Flush_L2;
sub SetFlags;


############################################
##  constants
############################################
my  $curDir      =   getcwd();
my  $CLfile     =   "$curDir/istepmodereg.dma";
my  $CORE       =   "-c3";

## my  $SIM_CLOCKS =   "4000000"; 
## my  $SIM_CLOCKS =   "2000000"; 
my  $SIM_CLOCKS =   "3000000"; 

#############################################
##  Internal Globals
#############################################
my  $CLdebug    =   0;
my  $CLtest     =   0;  

##  flushed Flag, if 0, it means the L2 cache has not been flushed. 
##  It must be flushed once before doing L3 reads
my  $L2_Flushed =   0;


my  $vbuToolsDir    =   "/gsa/ausgsa/projects/h/hostboot/vbutools/latest";


my  $DUMPCMD    =   "$vbuToolsDir/p8_dump_l3";
my  $LOADCMD    =   "$vbuToolsDir/p8_load_l3";
my  $FLUSHCMD   =   "$vbuToolsDir/p8_l2_flush_wrap.x86 $CORE -quiet";
my  $FLUSHQUERY =   "$vbuToolsDir/p8_check_l3";
my  $RUNCLKSCMD =   "simclock";

##  @todo $$$$$
##  NOTE:   need to be able to specify thread (-t ) and core (-c ), they 
##  should not be hardwired 
##my  $QUERYCMD   =   "$vbuToolsDir/p8_thread_control.x86 -query  $CORE -t0";  
##my  $STOPCMD    =   "$vbuToolsDir/p8_thread_control.x86 -stop   $CORE -tall";
##my  $STARTCMD   =   "$vbuToolsDir/p8_thread_control.x86 -start  $CORE -tall";

##  Jim McGuire's older versions.
my  $QUERYCMD   =   "/gsa/pokgsa/home/m/c/mcguirej/public/auto/rel/P8bin/p8_ins_query";  
my  $STOPCMD    =   "/gsa/pokgsa/home/m/c/mcguirej/public/auto/rel/P8bin/p8_ins_stop";
my  $STARTCMD   =   "/gsa/pokgsa/home/m/c/mcguirej/public/auto/rel/P8bin/p8_ins_start";

my  $RESETCMD   =   "$vbuToolsDir/p8_thread_control.x86 -sreset_auto $CORE";


##  old dirs and tools, SAVE
## my  $DUMPCMD    =   "/afs/awd/projects/eclipz/lab/p8/gsiexe/p8_dump_l3";
## my  $LOADCMD    =   "/afs/awd/projects/eclipz/lab/p8/gsiexe/p8_load_l3";
## ## my  $FLUSHCMD   =   "/afs/awd/projects/eclipz/lab/p8/gsiexe/p8_l2_flush.x86 $CORE";
## my  $FLUSHCMD   =   "/afs/awd/projects/eclipz/lab/p8/compiled_procs/procs/p8_l2_flush_wrap.x86 $CORE -quiet";
## my  $FLUSHQUERY =   "/afs/awd.austin.ibm.com/projects/eclipz/lab/p8/gsiexe/p8_check_l3";
## my  $RUNCLKSCMD =   "simclock";

## my  $QUERYCMD   =   "/gsa/pokgsa/home/m/c/mcguirej/public/auto/rel/P8bin/p8_ins_query";  
## my  $STOPCMD    =   "/gsa/pokgsa/home/m/c/mcguirej/public/auto/rel/P8bin/p8_ins_stop";
## my  $STARTCMD   =   "/gsa/pokgsa/home/m/c/mcguirej/public/auto/rel/P8bin/p8_ins_start";
## ##  ##  later...
## ##  ##  my  $QUERYCMD   =   "/afs/awd/projects/eclipz/lab/p8/u/karm/ekb/eclipz/chips/p8/working/procedures/utils/p8_thread_control.x86 -query";  
## ##  ##  my  $STOPCMD    =   "/afs/awd/projects/eclipz/lab/p8/u/karm/ekb/eclipz/chips/p8/working/procedures/utils/p8_thread_control.x86 -stop";
## ##  ##  my  $STARTCMD   =   "/afs/awd/projects/eclipz/lab/p8/u/karm/ekb/eclipz/chips/p8/working/procedures/utils/p8_thread_control.x86 -start";


## 
#==============================================================================
# SUBROUTINES
#==============================================================================


##
##  Read the cacheline at addr from L3 and dump it to a binary file. 
##  Assumes that the input address is a binary addr on a 128 byte boundary 
##
sub readcacheline( $ )
{
    my ( $addr ) =   @_; 
    my $cmd;
    ##  my  $hexaddr    =   sprintf( "0x%x", $addr );
    my  $hexaddr    =   sprintf( "%x", $addr );    
    
    if ( $CLdebug )   { print  STDERR __LINE__,  "--  Read cacheline at $hexaddr...\n"; }
    
    ##  Stop simulation so we can read L3 properly
    P8_Ins_Stop();
    
    ##  flush   L2 if necessary
    P8_Flush_L2();
  
    $cmd    =   "$DUMPCMD $hexaddr 1 -f $CLfile -b $CORE";
    if ( $CLdebug )   {   print STDERR __LINE__,  "-- run $cmd ...\n";   } 
    ( system( $cmd ) == 0 ) 
        or die "$cmd failed $? : $! \n";
        
    ##  Start simulation back up.        
    ##  P8_Ins_Start();        
        
}


##
##  derived from Perl Cookbook, 8.13
##  pack/unpack format is unsigned big endian 32-bit hi, lo
##  however, the input data from getopts still assumes that perl is compiled 
##  for 64-bit #s
##
sub modifycacheline( $$ )
{
    my  ( $offset, $data )  =   @_;
    
    my $typedef     =   'N N';                        #  2 32-bit network order
    my $sizeof      =   length( pack($typedef,() ) );
    my $filesize    =   -s $CLfile;
    my $buffer;
    
    open( FH, "+< $CLfile") or die "can't open $CLfile : $!";
    binmode FH;                 ## not really necessary, but....         
    seek( FH, $offset, SEEK_SET) or die "seek $CLfile failed: $!";
    read( FH, $buffer, $sizeof) == $sizeof or die "read failed: $!";

    ( my $hi, my $lo ) = unpack($typedef, $buffer);

    $hi = ($data >> 32) ;
    $lo = ($data & 0x00000000ffffffff);

    $buffer = pack($typedef, $hi, $lo );

    # back up one record
    seek( FH, -$sizeof, SEEK_CUR) or die "seek $CLfile failed: $!";

    print FH $buffer;
    
    close( FH ) or die "close $CLfile failed: $!"; 
}   

##
##  Write modified file back to L3 cacheline.
##  This assumes that addr has already been converted to binary addr on a 
##  128 byte boundary
##
sub writecacheline( $ )
{
    my  ( $addr )  =   @_;
    my  $cmd;
    ##  my  $hexaddr    =   sprintf( "0x%x", $addr );
    my  $hexaddr    =   sprintf( "%x", $addr );    

    ##  Stop simulation so we can write L3
    P8_Ins_Stop();
    
    $cmd    =   "$LOADCMD -o $hexaddr -f $CLfile -b $CORE";
    if ( $CLdebug )   {   print STDERR __LINE__,  "-- run $cmd ...\n";   } 
    ( system( $cmd ) == 0 ) 
        or die "$cmd failed, $? : $! \n";
    
    ##  Start sim back up
    ## P8_Ins_Start();
    
} 


##
##  Query the state of the simulator, "RUNNING" or "STOPPED".
##
sub P8_Ins_Query()
{
    my  $cmd    =   "$QUERYCMD";
    my  $retstr =   "";
    
    if ( $CLdebug ) {   print STDERR __LINE__,  "--   run $cmd ...\n";   } 
    
    ## execute it with backticks so we can get the output.
    $retstr = `$cmd`; 
    if ( $? != 0 )  { die "$cmd failed $? : $! \n"; }
    
    if  (    ($retstr =~ m/Quiesced/)
         || ($retstr =~ m/STOPPED/)
        )  
    {
        return "STOPPED";
    }
    elsif   (   ($retstr =~ m/Running/) 
              ||($retstr =~ m/RUNNING/)
            )
    {
        return "RUNNING";
    }
    else
    {
        die "invalid string \"$retstr\" from P8_Ins_Query\n";
    }       
}


##
##  Stop the simulation.  Necessary to read and write L3 .
##
sub P8_Ins_Start()
{
    my  $cmd    =   "$STARTCMD";
    
    if ( P8_Ins_Query() eq "STOPPED" )
    {
        if ( !$CLdebug ) 
        {   $cmd    .=  " -quiet";  }
        else
        {   print STDERR __LINE__,  "--   run $cmd ...\n";   } 

        ( system( $cmd ) == 0 ) 
            or die "$cmd failed $? : $! \n";

        
        ##  reset the flushFlag, need to flush again before a read.
        $L2_Flushed   =   0;
    }
    else
    {
        if ($CLdebug)   { print STDERR __LINE__,    "--   P8_Ins_Start: already RUNNING\n";  }
    }       
              
}


##
##  Stop the simulation.
##
sub P8_Ins_Stop()
{
    my  $cmd    =   "$STOPCMD";
    
    if ( P8_Ins_Query() eq "RUNNING" )
    {    
        if ( ! $CLdebug )
        {   $cmd    .=  " -quiet";  }
        else
        {   print STDERR __LINE__,  "--   run $cmd ...\n";  }
        
       ( system( $cmd ) == 0 ) 
            or die "$cmd failed $? : $! \n";
      
    }
    else
    {
        if ($CLdebug)   {   print STDERR __LINE__,    "-- P8_Ins_Stop: already STOPPED\n"; }
    }       
               
}

##
##  Check if cache is flushed.  
##  $TODO
##   p8_check_L3 will scan the L3 directory for unfilled cachelines and 
##   return a string:
##      $ p8_check_l3 100 4 -c3 -f $labhome/foo -x -o    
##      p8_check_l3 - address (0x100) not found in L3 directory.
##
##      $ p8_check_l3 100 4 -c3 -f $labhome/foo -x -o
##      p8_check_l3 - all addresses found in L3 directory.
##
sub P8_Check_Flushed
{
    my  ( $addr, $lines )   =   @_;
    my  $tmpfile =   "./tmpflush";
    my  $cmd    =   "$FLUSHQUERY";
    my  $rc     =   0;
    
        ## execute it with backticks so we can get the output.
    my $retstr = `$cmd $CORE -f $tmpfile -x -o`; 
    if ( $? != 0 )  { die "$cmd failed $? : $! \n"; }
    
    chomp( $retstr );
    
    if ( $retstr    =~  /^.*.all addresses.*/ )
    {
        $rc =   1;
    }
    
    return  $rc;
}

##
##  Flush L2 Cache
##  This only needs to be done once after the clock is stopped, 
##      thus the toggle flag
##
sub P8_Flush_L2()
{
    my  $cmd    =   "$FLUSHCMD";
    
    if ( !$L2_Flushed ) 
    {
        if ( $CLdebug )   {   print STDERR __LINE__,  "-- run $cmd ...\n";   } 
        ( system( $cmd ) == 0 ) 
            or die "$cmd failed $? : $! \n";
            
        ##  mark the CPU as flushed.    
        $L2_Flushed =   1;      
    }    

    if ($CLdebug)   {   print STDERR __LINE__,    "-- P8_FLush_L2 : $L2_Flushed\n"; }
}


##
##  tell the simulator to run for so many clock cycles.
##  If simulator is stopped, then start it up first.
##
sub RunClocks()
{
    my  $cmd    =   0;
    
    if ( $CLdebug ) {   printf STDERR __LINE__, "-- RunClocks()\n"; }
    
    ##  Check, and start instructions if necessary
    if  ( P8_Ins_Query( ) ne "RUNNING" )
    {
        
        P8_Ins_Start();
    }

    $cmd    =   "$RUNCLKSCMD $SIM_CLOCKS   -quiet";
    if ( $CLdebug )   {   print STDERR __LINE__,  "-- run $cmd ...\n";   } 
    ( system( $cmd ) == 0 ) 
        or die "$cmd failed, $? : $! \n";  
          
}        


##
##  Read a 64-bit value from L3 at hex addr.  
##  Input is expected to be a hex ascii string
##
sub CLread( $ )
{
    my ( $addr ) =   @_;
    my $cmd;
    my  $CLbase     =   ( hex($addr) & 0xffffff80);
    my  $CLoffset   =   ( hex($addr) & (~0xffffff80) );
    my  $result     =   0;     ## 64-bit hex
               
    if ( $CLdebug ) {   printf STDERR __LINE__, "-- CLread( %s ) : CLbase=0x%x, CLoffset=0x%x\n", $addr, $CLbase, $CLoffset }
    
    readcacheline( $CLbase );

    ##  extract quadword from cacheline file
    my $typedef     =   'N N';                        #  QuadWord
    my $sizeof      =   length( pack($typedef,() ) );
    my $filesize    =   -s $CLfile;
    my $buffer;
    open( FH, "+< $CLfile") or die "can't open $CLfile : $!";
    binmode FH;                 ## not really necessary, but....         
    seek( FH, $CLoffset, SEEK_SET) or die "seek $CLfile failed: $!";
    read( FH, $buffer, $sizeof) == $sizeof or die "read failed: $!";
    close( FH ) or die "close $CLfile failed: $!"; 
    
    ## unpack and reassemble as big-endian
    ( my $hi, my $lo )  =   unpack($typedef, $buffer); 
    $result =   ( ( ( $hi << 32 ) & 0xffffffff00000000 ) | $lo );
    
    if ( $CLdebug ) 
    { 
        printf STDERR __LINE__, "-- CLread( %s ) = 0x%lx  ", $addr, $result; 
        dumpcacheline(" " );
    }

    return ( $result );  
}
 
##
##  Write command byte to cacheline
##      Inputs are expected to be hex ascii strings
##
sub CLwrite( $$ )
{
    my  ( $addr, $data )    =   @_;
    my  $CLbase     =   ( hex($addr) & 0xffffff80 );
    my  $CLoffset   =   ( hex($addr) & (~0xffffff80) );
    my  $CLdata     =   hex($data);
    my  $result     =   0;
    
    if ( $CLdebug ) {   printf STDERR __LINE__, "-- CLwrite( %s, %s ) : CLbase=0x%x, CLoffset=0x%x, CLdata=0x%lx\n", 
                                $addr, $data, $CLbase, $CLoffset, $CLdata;   }

    ##  clear the cacheline file
    system( "rm -f $CLfile" );

    ## issue the command to dump the cacheline to a file
    readcacheline( $CLbase );

    ## dumpcacheline( "after read", $CLfile );
   
   ##   modify the cacheline file
    modifycacheline( $CLoffset, $data );

    ## dumpcacheline( "after modify", $CLfile );

    ##  write the cacheline back to L3
    writecacheline( $CLbase );  

    if ( $CLdebug )
    {
        ##  check, clear the cacheline file and read again
        system( "rm -f $CLfile" );
        readcacheline( $CLbase );
        dumpcacheline( "Readback", $CLfile );   
    } 
    
}


sub dumpcacheline()
{
    my  ( $comment )   =   @_;
    
    if ( $CLdebug )   
    { 
        print STDERR __LINE__, "--    $comment, dump cache file :\n"; 
        system( "xxd $CLfile" ); 
    }   
    
}

sub SetFlags( $$ )
{
    my  ( $debug, $test )   =   @_;
    
    $CLdebug    =   $debug;
    $CLtest     =   $test;
  
    if ( $CLdebug )   
    { 
        print STDERR __LINE__, "-- CLdebug=$CLdebug, CLtest=$CLtest\n"; 
    }       
}


##  required at the end of perl modules
1;

__END__
