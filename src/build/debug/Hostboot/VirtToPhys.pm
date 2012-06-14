 #  IBM_PROLOG_BEGIN_TAG
 #  This is an automatically generated prolog.
 #
 #  $Source: src/build/debug/Hostboot/VirtToPhys.pm $
 #
 #  IBM CONFIDENTIAL
 #
 #  COPYRIGHT International Business Machines Corp. 2012
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
 #  IBM_PROLOG_END_TAG
 #

use strict;
use Hostboot::_DebugFrameworkVMM;
package Hostboot::VirtToPhys;
use Exporter;
use integer;
our @EXPORT_OK = ('main');



sub main
{
    #::userDisplay "VirtToPhys module.\n";

    my ($packName,$args) = @_;

    my $phyAddr = Hostboot::_DebugFrameworkVMM::NotFound;   
    my $debug = 0;
    my $displaySPTE = 0;

    if (defined $args->{"debug"})
    {
        $debug = 1;
    }


    if (defined $args->{"showSPTE"})
    {
        $displaySPTE = 1;
    }

    # Parse 'vaddr' argument.    
    if (not defined $args->{"vaddr"})
    {
      ::userDisplay "ERROR.. Did not pass in Virtual Address.\n";
       die;
    }

    my $vaddr = hex($args->{"vaddr"});

    if ($debug)
    {
    ::userDisplay (sprintf "\n   Virtual Address = %X\n" , $vaddr);
    }
  
   $phyAddr = Hostboot::_DebugFrameworkVMM::getPhysicalAddr($vaddr, $debug, $displaySPTE); 
   
   return $phyAddr;
}


sub helpInfo
{
    my %info = (
        name => "VirtToPhys",
        intro => ["Take a virtual address and return its physical address"],
        options => {
                    "vaddr=<number>" =>  ["Virtual Address "],
                    "debug" => ["More debug output."],
                    "displaySPTE" => ["Display the SPTE for the VA passed in"],
                   },

    );
}
