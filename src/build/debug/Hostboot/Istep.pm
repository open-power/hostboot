#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/Istep.pm $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2011,2014
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
# Purpose:  This perl script implements isteps on AWAN.
#
# Procedure:
#	Call hb_Istep twice:
#	1) hb_Istep [--]istepmode
#	    called after loading but before starting HostBoot
#	    this will check to see if the user has set istep mode, if so
#	    it will write the Istep_mode signature to L3 memory to put
#       HostBoot mode into single-step mode (spless).
#       Then it will boot HostBoot until it is ready to receive commands.
#	2) hb_Istep [--]command
#       Submit a istep/substep command for hostboot to run.
#	    Periodically call ::executeInstrCycles() to step through HostBoot.
#	    Checks for status from previous Isteps, and reports status.
#
# Author: Mark Wenning
#
#   DEVELOPER NOTES:
#   Do NOT put prints or printf's in this script!!!
#       simics-debug-framework.pl and simics-debug-framework.py communicate
#       (recvIPCmsg and sendIPCmsg) overstdin and stdout -
#       if you print to STDOUT you will inadvertently send an empty/corrupted
#       "IPC" message to python/simics which will usually cause ugly crashes.
#

#------------------------------------------------------------------------------
# Specify perl modules to use
#------------------------------------------------------------------------------
use strict;
use POSIX;      #   isdigit

## 64-bit input
use bigint;
no  warnings    'portable';


##  declare Istep package
package Hostboot::Istep;
use Exporter;
our @EXPORT_OK = ('main');

#------------------------------------------------------------------------------
#   Constants
#------------------------------------------------------------------------------
##  @todo   extract these from splesscommon.H
use constant    SPLESS_MODE_SIGNATURE     =>  0x4057b0074057b007;
use constant    RUN_ALL_MODE_SIGNATURE    =>  0xBADC0FFEE0DDF00D;

use constant    SPLESS_SINGLE_ISTEP_CMD     =>  0x00;
use constant    SPLESS_RESUME_ISTEP_CMD     =>  0x01;
use constant    SPLESS_CLEAR_TRACE_CMD      =>  0x02;

use constant    MAX_ISTEPS                  =>  25;
use constant    MAX_SUBSTEPS                =>  25;

##  Mailbox Scratchpad regs
use constant    MBOX_SCRATCH0               =>  0x00050038;     ## contTrace
use constant    MBOX_SCRATCH1               =>  0x00050039;     ## sts LO
use constant    MBOX_SCRATCH2               =>  0x0005003a;     ## sts HI
use constant    MBOX_SCRATCH3               =>  0x0005003b;     ## cmd reg

##  extra parm for ::executeInstrCycles
use constant    NOSHOW                      =>  1;

#------------------------------------------------------------------------------
# Globals
#------------------------------------------------------------------------------
my  $opt_debug          =   0;
my  $opt_splessmode     =   0;
my  $opt_fspmode        =   0;
my  $opt_command        =   0;
my  $opt_list           =   0;
my  $opt_resume         =   0;
my  $opt_clear_trace    =   0;

##  deprecated - keep around for now
my  $opt_istepmode      =   0;

my  $command            =   "";

my  @inList;

##  initialize the sequence number - 6 bit field, { 0 - 63 }
my  $g_SeqNum   =   int(rand(64));

my  $THREAD         =   "0";


##  --------------------------------------------------------------------------
##  get any environment variables
##  --------------------------------------------------------------------------

##  @todo   make this an enviroment var?
##  NOTE:  this is the # cycles used for simics, it is multiplied by 100
##  in vpo-debug-framework.pl
my  $hbDefaultCycles    =   5000000;

my  $hbCount =   $ENV{'HB_COUNT'};
if ( !defined( $hbCount ) || ( $hbCount eq "" ) )
{
    ##  set default
    $hbCount    =   0xffffffff;     ##  effectively infinite ...
}

## init global variables
my  $ShutDownFlag   =   "";
my  $ShutDownSts    =   "";

my  $CommandReg     =   "";
my  $StatusReg      =   "";


########################################################################
##  MAIN ROUTINE, called from debug framework
########################################################################
sub main
{
    ##  $packName is the name of the selected tool
    ##  $args is a hashref to all the command-line arguments
    my ($packName,$args) = @_;


    ##  debug - save
    while ( my ($k,$v) = each %$args )
    {
        ::userDisplay "args: $k => $v\n";
    }

    ::userDisplay   "Welcome to hb-Istep 3.34 .\n";
    ::userDisplay   "Note that in simics, multiple options must be in quotes,";
    ::userDisplay   "separated by spaces\n\n";

    ##  initialize inList to "undefined"
    $inList[MAX_ISTEPS][MAX_SUBSTEPS]   =   ();
    for( my $i = 0; $i <    MAX_ISTEPS; $i++)
    {
        for(my $j = 0; $j < MAX_SUBSTEPS; $j++)
       {
            undef( $inList[$i][$j] );
        }
    }

    ##  ---------------------------------------------------------------------------
    ##  Fetch the symbols we need from syms file
    ##  ---------------------------------------------------------------------------

    $CommandReg     =   getSymbol(  "SPLESS::g_SPLess_Command_Reg" );
    $StatusReg      =   getSymbol(  "SPLESS::g_SPLess_Status_Reg" );

    $ShutDownFlag   =   getSymbol(  "CpuManager::cv_shutdown_requested" );
    $ShutDownSts    =   getSymbol(  "CpuManager::cv_shutdown_status" );

    ##  fetch the istep list
    get_istep_list();

    ##  debug, dump all the environment vars that we are interested in
    ## dumpEnvVar( "HB_TOOLS" );
    ## dumpEnvVar( "HB_IMGDIR" );
    ## dumpEnvVar( "HB_VBUTOOLS" );
    ## dumpEnvVar( "HB_COUNT" );

    ##--------------------------------------------------------------------------
    ##  Start processing options
    ##  process the "flag" standard options, then use a loop to go through
    ##  the rest
    ##--------------------------------------------------------------------------
        ##  Get all the command line options in an array
    my  @options    =   ( keys %$args );
    ## ::userDisplay   join( ' ', @options );

    if  ( !(@options) )
    {
        ::userDisplay "type \"help hb-istep\" for help\n";
        exit;
    }

    ##
    ##  find all the standard options, set their flag, and remove them from
    ##  the options list.
    ##  vpo and simics use different command-line styles:
    ##  simics wants you to say " hb-istep "debug s4" ",
    ##  (note that multiple options must be in quotes, separated by spaces)
    ##  and vpo wants you to say "hb-istep --debug --command s4" .
    ##  This should accept both styles.
    ##
    for ( my $i=0; $i <= $#options; $i++ )
    {
        $_  =   $options[$i];

        ## ::userDisplay ".$_.";

        if ( m/^\-{0,2}debug$/ )
        {
            $opt_debug      =   1;
            $options[$i]    =   "";
        }
        if ( m/^\-{0,2}list$/ )
        {
            $opt_list       =   1;
            $options[$i]    =   "";
        }
        if ( m/^\-{0,2}istepmode$/ )
        {
            $opt_istepmode  =   1;
            $options[$i]    =   "";
        }
        if ( m/^\-{0,2}splessmode$/ )
        {
            $opt_splessmode  =   1;
            $options[$i]    =   "";
        }
        if ( m/^\-{0,2}fspmode$/ )
        {
            $opt_fspmode  =   1;
            $options[$i]    =   "";
        }
        if ( m/^\-{0,2}command$/ )
        {
            ## doesn't do much, just eats the option
            $opt_command    =   1;
            $options[$i]    =   "";
        }
        if ( m/^\-{0,2}resume$/ )
        {
            $opt_resume     =   1;
            $options[$i]    =   "";
        }
        if  ( m/^\-{0,2}clear-trace$/ )
        {
            $opt_clear_trace    =   1;
            $options[$i]    =   "";
        }
    }   ##  endfor

    ##  if there's anything left after this, assume it is a single command
    $command  = join( "", @options );
    chomp $command;

    ##  print out debug info
    if  ( $opt_debug )
    {
        ::userDisplay   "\n-----    DEBUG:  ------------------------------- \n";
        ::userDisplay   "debug          =   $opt_debug\n";
        ::userDisplay   "list           =   $opt_list\n";
        ::userDisplay   "splessmode     =   $opt_splessmode\n";
        ::userDisplay   "fspmode        =   $opt_fspmode\n";

        ::userDisplay   "resume         =   $opt_resume\n";
        ::userDisplay   "clear-trace    =   $opt_clear_trace\n";
        ::userDisplay   "command flag   =   $opt_command\n";
        ::userDisplay   "command        =   \"$command\"\n";

        ::userDisplay   "g_SeqNum       =   ", sprintf("0x%x",$g_SeqNum),     "\n";
        ::userDisplay   "CommandReg     =   ", sprintf("0x%x",$CommandReg),   "\n";
        ::userDisplay   "StatusReg      =   ", sprintf("0x%x",$StatusReg),    "\n";
        ::userDisplay   "ShutDownFlag   =   ", sprintf("0x%x",$ShutDownFlag), "\n";
        ::userDisplay   "ShutDownSts    =   ", sprintf("0x%x",$ShutDownSts),  "\n";

        ::userDisplay   "hbCount        =   ", sprintf("0x%x",$hbCount),      "\n";

        ::userDisplay   "\n";
    }

    if ( $opt_debug )   {   ::userDisplay   "=== check ShutDown Status...\n";  }
    if ( isShutDown() )
    {
        ::userDisplay   "Shutdown detected: cannot run HostBoot.\n";
        exit;
    }

    ##  ----------------------------------------------------------------
    ##  finally, run some commands.
    ##  ----------------------------------------------------------------

    if ( $opt_list  )
    {
        ::userDisplay   "List isteps\n";
        print_istep_list();
        exit;
    }

    if ( $opt_istepmode )
    {
        ::userDisplay "istepmode no longer used - use splessmode\n";
        exit;
    }

    if ( $opt_splessmode )
    {
        ::userDisplay   "ENable splessmode\n";
        setMode( "spless" );
        ::userDisplay   "Done.\n";
        exit;
    }

    if ( $opt_fspmode )
    {
        ::userDisplay "istepmode no longer used - use splessmode\n";
        exit;
    }

    ##  don't do any other commands unless ready bit is on.
    if ( ! isReadyBitOn() )
    {
        ::userDisplay   "Ready bit is off, must run splessmode first.\n";
        exit;
    }

    if ( $opt_clear_trace )
    {
        ::userDisplay   "Clear Trace\n";
        clear_trace();
        exit;
    }

    if ( $opt_resume )
    {
        ::userDisplay   "Resume\n";
        resume_istep();
        exit;
    }

    if ( $opt_command || ( $command ne "" ) )
    {
        ::userDisplay   "Process command \"$command\"\n";
        process_command( $command );
        exit;
    }

    ::userDisplay   "Done.\n";
    exit    0;
}   ##  end main

########################################################################
##  SUBROUTINES
########################################################################
##


sub helpInfo
{
    my %info = (
        name => "Istep",
        intro => ["Executes isteps."],
        options => {    "list"          =>  [" list out all supported isteps "],
                        "splessmode"    =>  ["enable istep mode"],
                        "resume"        =>  ["resume an istep that is at a break point"],
                        "clear-trace"   =>  ["clear trace buffers before starting"],
                        "sN"            =>  ["run istep N"],
                        "sN..M"         =>  ["run isteps N through M"],
                        "<foo>"         =>  ["run named istep \"foo\""],
                        "<foo>..<bar>"  =>  ["run named isteps \"foo\" through \"bar\""],
                   }
    );
}


##  Increment the sequence number, rolling over at 64
##  ---------------------------------------------------------------------------
sub bumpSeqNum()
{

    $g_SeqNum++;

    $g_SeqNum   %=  64;

    $g_SeqNum += ($g_SeqNum == 0) ? 1 : 0;

    return  $g_SeqNum;
}

##  ---------------------------------------------------------------------------
##  Dump environment variable specified.
##  ---------------------------------------------------------------------------
sub dumpEnvVar( $ )
{
    my  $envvar =   shift;

    if ( defined( $ENV{$envvar} )  )
    {
        ::userDisplay "$envvar =   $ENV{$envvar}\n";
    }
}

##
##  Get symbol address from hbotSymsFile
##
sub getSymbol( )
{
    my  $symbol  =   shift;
    my ($symAddr, $symSize) = ::findSymbolAddress( $symbol ) ;

    if ( not defined( $symAddr ) )
    {
        ::userDisplay "Cannot find $symbol.\n"; die;
    }

    return  $symAddr;
}

##
##  read in file with csv istep list and store in inList
##
sub get_istep_list()
{
    my $istep, my $substep, my $name ;

    my  @isteplist  =   ::getIstepList();

    ##  DEBUG:  Comment in to test invalid minor and invalid major isteps
    ## $inList[7][8]   =   "invalid_minor";
    ## $inList[0][17]  =   "invalid_major";

    foreach( @isteplist )
    {
        chomp;

        ( $istep, $substep, $name) =   split( ",", $_ );
        chomp $name;

        ## ::userDisplay "$_, $istep, $substep, $name\n" ;

        if ( defined($name) && ( $name ne "" ) )
        {
            $inList[$istep][$substep]    =   $name;
        }
    }

}


##
##  print the istep list to the screen.
##
sub print_istep_list( )
{
    my  $hdrflag    =   1;

    ## ::userDisplay   " IStep Name\n";
    ##::userDisplay   "---------------------------------------------------\n";

    for( my $i = 4; $i < MAX_ISTEPS; $i++)
    {
        for( my $j = 0; $j < MAX_SUBSTEPS; $j++)
        {
            ## print all substeps
            if ( defined( $inList[$i][$j] ) )
            {
                if ( $hdrflag )
                {
                    ::userDisplay   " ----- IStep $i -----  \n";
                    $hdrflag = 0;
                }
                ## will truncate after 40 chars, hopefully this will not be an issue
                my $ss  =   sprintf( "%-40s", $inList[$i][$j] );
                ::userDisplay   "$i.$j: $ss\n" ;
            }
        }   ## end for $j

        $hdrflag=1;
    }   ##  end for $i
}


##
##  Find istep name in inList array.
##
##  @param[in]  -   name
##
##  @return     -   istep #, substep #, found flag = true for success
##                                                   false for not found
##
sub find_in_inList( $ )
{
    my  ( $substepname )    =   @_;

    for(my $i = 0; $i < MAX_ISTEPS; $i++)
    {
        for(my $j = 0; $j < MAX_SUBSTEPS; $j++)
        {
            if ( defined($inList[$i][$j]) && ($inList[$i][$j] eq $substepname ) )
            {
                return  ($i, $j, 1 );
            }
        }
    }

    return ( MAX_ISTEPS, MAX_SUBSTEPS, 0 )
}

##
##  When HostBoot goes into singlestep mode, it turns on the ready bit in the
##  status reg.
##
##  @return nonzero if ready bit is on, else 0
##
sub isReadyBitOn()
{
    my  $result     =   0;
    my  $readybit   =   0;

    $result = getStatus( );
    $readybit    =   ( ( $result & 0x4000000000000000 ) >> 62 );

    if ( $opt_debug )   {   ::userDisplay   "=== readybit: $readybit\n";    }

    if ( $readybit )
    {
        return  1;
    }

    return  0;
}




##
##  Check if HostBoot has already run and shutdown.
##
##  @return nonzero if it has, 0 otherwise
##
sub isShutDown()
{

    my $flag    =   ::read64( $ShutDownFlag );
    my $status  =   ::read64( $ShutDownSts  );

    if ( $opt_debug )
    {
        ::userDisplay "=== isShutDown : Shutdown Flag   =   $flag\n";
        ::userDisplay "=== isShutDown : Shutdown Status = ",
                      sprintf( "0x%x", $status), "\n";
    }

    if ( $flag )
    {
        ::userDisplay "HostBoot has shut down with status ",
                      sprintf( "0x%x", $status), ".\n";
        return 1;
    }

    return 0;
}

##  --------------------------------------------------------------------
##  Write command reg
##
##  @param[in]  -   HEX STRING containing the 64-bit command word
##
##  @return none
##
##  --------------------------------------------------------------------
sub sendCommand( $ )
{
    my  $data    =   shift;

    if ( $opt_debug )
        {   ::userDisplay "===  sendCommand( $data )\n";    }

    ## convert to binary before sending to writescom
    my  $bindata    =   ( hex $data );

    ## now write the data
    ::writeScom( MBOX_SCRATCH3, 8, $bindata );

    if ( $opt_debug )
    {
        ## sanity check
        ::executeInstrCycles( 10, NOSHOW );
        my $readback    =   ::readScom( MBOX_SCRATCH3, 8 );
        ::userDisplay   "=== sendCommand readback: $readback\n";
    }

}


##  --------------------------------------------------------------------
##  read status reg
##
##  Note - mbox scratchpad regs are only 32 bits, so HostBoot will return
##  status in mbox 2 (hi32 bits) and mbox 1 (lo32 bits).
##  mbox 0 is reserved for continuous trace.
##
##
##
##  @return     binary  64-bit value
##  --------------------------------------------------------------------
sub getStatus()
{
    my  $status     =   0;
    my  $statusHi   =   "";
    my  $statusLo   =   "";

    $statusHi   =   ::readScom( MBOX_SCRATCH2, 8 );
    if ( $opt_debug )   {   ::userDisplay   "===  statusHi: $statusHi \n";  }

    $statusLo   =   ::readScom( MBOX_SCRATCH1, 8 );
    if ( $opt_debug )   {   ::userDisplay   "===  statusLo: $statusLo \n";  }

    $status =   (   (  ( $statusHi) & 0xffffffff00000000 )
                  | (( ( $statusLo) & 0x7fffffff00000000 ) >> 32)
                );

    if ( $opt_debug )
    {
        ::userDisplay   "===  getStatus() returned ", (sprintf( "0x%lx", $status ) ), "\n";
    }

    return  $status;
}


##
##  keep trying to get status until seqnum syncs up
##
sub getSyncStatus( )
{
    # set # of retries
    my  $count          =   $hbCount ;
    my  $result         =   0;
    my  $seqnum         =   0;
    my  $running        =   0;

    ##  get response.  sendCmd() should have bumped g_SeqNum, so we will sit
    ##  here for a reasonable amount of time waiting for the correct sequence
    ##  number to come back.
    while(1)
    {

        ##  advance HostBoot code by a certain # of cycles, then check the
        ##  sequence number to see if it has changed.  rinse and repeat.
        ::executeInstrCycles( $hbDefaultCycles, NOSHOW );


        ##  check to see if we need to dump trace - no-op in simics
        ##::checkContTrace();

        $result     = getStatus();
        $seqnum     =   ( ( $result & 0x3f00000000000000 ) >> 56 );
        $running    =   ( ( $result & 0x8000000000000000 ) >> 63 );

        ## @todo great place to add some debug, check running bit BEFORE
        ##  starting the clock (should be off), then run (relatively) small
        ##  number of clocks till the bit turns on.
        ##  If it doesn't go on, command was never received.  If so,
        ##  come here to wait for it to go back off again.
        ## if (    ( $running == 0 )
        ##     && ( $seqnum == $g_SeqNum )
        if ( $seqnum == $g_SeqNum )
        {
            return $result;
        }

        if ( $count <= 0)
        {
            ::userDisplay   "TIMEOUT waiting for seqnum=$g_SeqNum\n";
            return -1;
        }

        $count--;

    }   ##  endwhile

}


##
##  Run an istep
##
sub runIStep( $$ )
{
    my  ( $istep, $substep)  = @_;
    my  $byte0, my $command;
    my  $cmd;
    my  $result;


    ##  bump the seqnum
    bumpSeqNum() ;

    ::userDisplay   "run  $istep.$substep $inList[$istep][$substep]:\n" ;

    $byte0   =   0x80 + $g_SeqNum;      ## gobit + seqnum
    $command =   SPLESS_SINGLE_ISTEP_CMD;
    $cmd = sprintf( "0x%2.2x%2.2x%2.2x%2.2x00000000", $byte0, $command, $istep, $substep );

    sendCommand( $cmd );


    $result  =   getSyncStatus();

    ## if result is -1 we have a timeout
    if ( $result == -1 )
    {
        ::userDisplay   "-----------------------------------------------------------------\n";
    }
    else
    {
        my $taskStatus  =   ( ( $result & 0x00ff000000000000 ) >> 48 );
        my $stsIStep    =   ( ( $result & 0x0000ff0000000000 ) >> 40 );
        my $stsSubstep  =   ( ( $result & 0x000000ff00000000 ) >> 32 );
        my $istepStatus =   ( ( $result & 0x00000000ffffffff )  );

        ::userDisplay "---------------------------------\n";
        if ( $taskStatus != 0 )
        {
            ::userDisplay   "Istep $stsIStep.$stsSubstep FAILED to launch, task status is $taskStatus\n" ;
            exit;
        }
        else
        {
            ::userDisplay   "Istep $stsIStep.$stsSubstep $inList[$istep][$substep] returned Status: ",
                            sprintf("%x",$istepStatus),
                            "\n" ;
            if ( $istepStatus == 0xa )
            {
                ::userDisplay   ":     not implemented yet.\n";
            }
            elsif ( $istepStatus != 0 )
            {
                exit;
            }
        }
        ::userDisplay   "------------------------------------------------------- SeqNum: $g_SeqNum\n";
    }
}

##
##  run command = "sN"
##
sub sCommand( $ )
{
    my  ( $scommand )   =   @_;

    my  $i   =   $scommand;
    my  $j   =   0;

    #   execute all the substeps in the IStep
    for( $j=0; $j<MAX_SUBSTEPS; $j++ )
    {


        if ( defined( $inList[$i][$j] ) )
        {
            runIStep( $i, $j );
        }
    }
}


##
##  parse --command [command] option and execute it.
##
sub process_command( $ )
{
    my  ( $command ) =   @_;
    my  @execlist;
    my  $istepM, my $substepM, my $foundit, my $istepN, my $substepN;
    my  $M, my $N, my $scommand;
    my  @ss_list;

    ## check to see if we have an 's' command (string starts with 's' and a number)
    chomp( $command);
    if ( $command =~ m/^s+[0-9].*/ )
    {
        ## run "s" command
        if ($opt_debug) {   ::userDisplay   "=== s command \"$command\" \n";   }
        substr( $command, 0, 1, "" );

        if ( POSIX::isdigit($command) )
        {
            # command = "sN"
            if ($opt_debug) {   ::userDisplay   "=== single IStep: ", $command, "\n";  }
            sCommand( $command );
        }
        else
        {
            #   list of substeps = "sM..N"
            ( $M, $N )  =   split( /\.\./, $command );

            if ($opt_debug) {   ::userDisplay   "=== multiple ISteps: ", $M, "-", $N, "\n";    }
            for ( my $x=$M; $x<$N+1; $x++ )
            {
                sCommand( $x );
            }
        }
    }
    else
    {
        ## <substep name>, or <substep name>..<substep name>
        @ss_list    =   split( /\.\./, $command );

        if ($opt_debug) {   ::userDisplay   "=== named commands : ", @ss_list, "\n";    }

        ( $istepM, $substepM, $foundit) = find_in_inList( $ss_list[0] );
        $istepN      =   $istepM;
        $substepN    =   $substepM;
        if ( ! $foundit )
        {
            ::userDisplay   "Invalid substep ", $ss_list[0], "\n" ;
            return -1;
        }


        if ( $#ss_list > 0 )
        {
            ( $istepN, $substepN, $foundit) = find_in_inList( $ss_list[1] );
            if ( ! $foundit )
            {
                ::userDisplay   "Invalid substep $ss_list[1] \n" ;
                return -1;
            }
        }

        for(my $x=$istepM; $x<=$istepN; $x++)
        {
            if ($istepM == $istepN)
            {
                # First and Last Steps are the same.
                # Run all requested substeps between the same step
                for(my $y=$substepM; $y<=$substepN; $y++)
                {
                    if (defined($inList[$x][$y]))
                    {
                        runIStep($x, $y);
                    }
                }
            }
            elsif ($x == $istepM)
            {
                # First requested Step, run from requested substep
                for(my $y=$substepM; $y<MAX_SUBSTEPS; $y++)
                {
                    if (defined($inList[$x][$y]))
                    {
                        runIStep($x, $y);
                    } 
                }
            }
            elsif ($x == $istepN)
            {
                # Last requested Step, run up to requested substep
                for(my $y=0; $y<=$substepN; $y++)
                {
                    if (defined($inList[$x][$y]))
                    {
                        runIStep($x, $y);
                    }
                }
            }
            else
            {
                # Middle istep, run all substeps
                for(my $y=0; $y<MAX_SUBSTEPS; $y++)
                {
                    if (defined($inList[$x][$y]))
                    {
                        runIStep($x, $y);
                    }
                }
            }
        }

    }
}


##
##  write to mem to set istep or normal mode, check return status
##
##  Note that this only happens once at the beginning, when "splessmode"
##  is run.
##
sub setMode( $ )
{
    my  ( $cmd )    =   @_;
    my  $count      =   0;
    my  $expected   =   0;
    my  $readybit   =   0;
    my  $result     =   0;

    if ( $cmd eq "spless" )
    {
        ::userDisplay  "This command doesn't force HB into SPLESS mode anymore\n";
        ::userDisplay  "It only establish SPLESS communication (clocks model in sim)\n";
        ::userDisplay  "Use attributes to enter SPLESS mode\n";
        ::userDisplay  "\tSP_FUNCTIONS:mailboxEnabled = 0b0\n";
        ::userDisplay  "\tISTEP_MODE = 0x1\n";
        $expected    =   1;
    }
    else
    {
        ::userDisplay   "invalid setMode command: $cmd\n" ;
        return  -1;
    }

    ##  Loop, advancing clock, and wait for readybit
    $count  =   $hbCount ;
    while(1)
    {

        if ( $opt_debug )   {   ::userDisplay   "=== executeInstrCycles( $hbDefaultCycles )\n"; }
        ##  advance HostBoot code by a certain # of cycles, then check the
        ##  sequence number to see if it has changed.  rinse and repeat.
        ::executeInstrCycles( $hbDefaultCycles, NOSHOW );

        if ( $opt_debug )   {   ::userDisplay   "=== checkContTrace\n";   }
        ## check to see if it's time to dump trace - no-op in simics
        ::checkContTrace();

        if ( $opt_debug )   {   ::userDisplay   "=== isShutDown\n";       }
        ## check for system crash
        if ( isShutDown( ) )
        {
            ::userDisplay  "Shutdown detected: cannot run HostBoot.\n";
            return -1;
        }

        if ( $opt_debug )   {   ::userDisplay   "=== isReadyBitOn\n";     }
        if ( isReadyBitOn() )
        {
            return  0;
        }

        if ( $count <= 0 )
        {
            ::userDisplay "TIMEOUT waiting for readybit, status=$result\n" ;
            return -1;
        }

        $count--;

        if ( $opt_debug )   {   ::userDisplay   "=== count = $count\n";     }
    }
}


sub resume_istep()
{
    my $byte0;
    my $command;
    my $cmd;
    my $result;

    bumpSeqNum();

    ::userDisplay   "resume istep\n";

    $byte0 = 0x80 + $g_SeqNum;      ## gobit + seqnum
    $command = SPLESS_RESUME_ISTEP_CMD;
    $cmd = sprintf( "0x%2.2x%2.2x000000000000", $byte0, $command );
    sendCommand( $cmd );

    $result = getSyncStatus();

    ## if result is -1 we have a timeout
    if ( $result == -1 )
    {
        ::userDisplay   "-----------------------------------------------------------------\n";
    }
    else
    {
        my $taskStatus  =   ( ( $result & 0x00ff000000000000 ) >> 48 );

        ::userDisplay   "-----------------------------------------------------------------\n";
        if ( $taskStatus != 0 )
        {
            # This probably means istep was not at a breakpoint.
            ::userDisplay   "resume istep FAILED, task status is $taskStatus\n", $taskStatus ;
        }
        else
        {
            ::userDisplay   "resume istep returned success\n" ;
        }
        ::userDisplay   "-----------------------------------------------------------------\n";
    }
}

sub clear_trace( )
{
    my  $byte0, my $command;
    my  $cmd;
    my  $result;


    ##  bump the seqnum
    bumpSeqNum();

    $byte0   =   0x80 + $g_SeqNum;      ## gobit + seqnum
    $command =   SPLESS_CLEAR_TRACE_CMD;
    $cmd = sprintf( "0x%2.2x%2.2x%2.2x%2.2x00000000", $byte0, $command, 0, 0 );
    sendCommand( $cmd );

    $result  =   getSyncStatus();

    ## if result is -1 we have a timeout
    if ( $result == -1 )
    {
        ::userDisplay   "-----------------------------------------------------------------\n";
    }
    else
    {
        my $taskStatus  =   ( ( $result & 0x00ff000000000000 ) >> 48 );
        my $stsIStep    =   ( ( $result & 0x0000ff0000000000 ) >> 40 );
        my $stsSubstep  =   ( ( $result & 0x000000ff00000000 ) >> 32 );
        my $istepStatus =   ( ( $result & 0x00000000ffffffff )  );

        ::userDisplay   "-----------------------------------------------------------------\n";
        if ( $taskStatus != 0 )
        {
            ::userDisplay   "Clear Trace FAILED, task status is taskStatus\n" ;
        }
        else
        {
            ::userDisplay   "Clear Trace returned Status: $istepStatus\n" ;
        }
        ::userDisplay   "-----------------------------------------------------------------\n";
    }
}

  # A Perl module must end with a true value or else it is considered not to
  # have loaded.  By convention this value is usually 1 though it can be
  # any true value.  A module can end with false to indicate failure but
  # this is rarely used and it would instead die() (exit with an error).
  1;

__END__

