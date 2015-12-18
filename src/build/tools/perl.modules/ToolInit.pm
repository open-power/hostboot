# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/perl.modules/ToolInit.pm $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015
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

package ToolInit;

use strict;
use Getopt::Long qw(:config pass_through);
use Switch;
# Allow platform scripts to use init_globals
use Exporter 'import';
our @EXPORT = qw(init_globals $debug $help $module_script MASTER FETCH_HEAD);

# Globals
our $debug = 0;
our $help = 0;
our $module_script = "";
my %globals = ( branch => "master");

# Projects that use ToolInit
use constant {
    MASTER => "master",
    FETCH_HEAD => "FETCH_HEAD",
    EKB => "EKB",
};

# Global options for all infrastructure scripts/modules
GetOptions("debug!" => \$debug,
           "help" => \$help,
           "module-script:s" => \$module_script,
           "branch:s" => \$globals{branch});

# sub init_globals
#
# Export global variables to all scripts/modules that need them
#
# @return hash - variables needed for infrastructure scripts
#
sub init_globals
{
    $globals{project_name} = $ENV{'PROJECT_NAME'};
    $globals{remote_server} = $ENV{'GERRIT_SRV'};

    if ($globals{project_name} eq "")
    {
        print "Environment not setup properly...\n\tRun 'source env.bash' or ";
        print "'./$module_script workon' based on your current environment\n";
        print "\tFor more info run './$module_script --help'\n";
        die ();
    }
    project_settings();

    return %globals;
}

# sub project_settings
#
# Set project specific settings for tools on any platform.
# Project names are found via env variable set (e.g.in env.bash)
# If project is not supported this fails, as supported must be added.
#
sub project_settings
{
    switch ($globals{project_name})
    {
        case (EKB)
        {
            $globals{gerrit_project} = "hw/ekb";
        }
        else
        {
            die "Project => $module_script not supported";
        }
    }
}