# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/VirtToPhys.pm $
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


    if( (defined $args->{"SPTE"}) || (defined $args->{"spte"}) )
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

    if (($phyAddr eq Hostboot::_DebugFrameworkVMM::NotFound) ||
        ($phyAddr eq Hostboot::_DebugFrameworkVMM::NotPresent))
    {
        ::userDisplay ("The Physical Address = $phyAddr\n");
    }
    else
    {
        ::userDisplay (sprintf "The Physical Address =  0x%X\n" , $phyAddr);
    }

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
                    "SPTE" => ["Display the SPTE for the VA passed in"],
                   },

    );
}
