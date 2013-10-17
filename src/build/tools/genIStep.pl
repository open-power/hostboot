#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/genIStep.pl $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2012,2013
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
# Author:   Mark Wenning    wenning@us.ibm.com
#
# Usage:
#   genIStep.pl --tag-file <path>   ( required: file containing tag block )
#               [ --help ]          ( prints usage message )
#               [ --dry-run ]       ( prints all steps without doing anything )
#               [ --import-hwp ]    ( import new HWP source from Gerrit )
#
# Purpose:
#   Read in a tag file and generate a new istep (or update the existing istep)
#   based on the tags.
#
#   To set up to run a new HWP, follow these directions
#        ( or have your perlscript do it from the tag block )
#
#   Make up a new directory  src/usr/hwpf/hwp/<@istepname>
#   cd to that directory.
#
#   Make up a blank file src/usr/hwpf/hwp/<@istepname>/<@istepname.H>
#           (use src/usr/hwpf/hwp/template.H as a template)
#   - add the tag block file example detailed below.
#   - note that each substep is enclosed by "@{  @}"  delimiters
#
#
#       /*  @tag isteplist
#        *  @docversion
#        *  @istepname
#        *  @istepnum
#        *  @istepdesc
#        *
#        *  @{
#        *      @substepnum     1
#        *      @substepname
#        *      @substepdesc
#        *          @target_sched   serial
#        *  @}
#        *
#        *      ...
#        *
#        *  @{
#        *      @substepnum     N
#        *      @substepname
#        *      @substepdesc
#        *          @target_sched   serial
#        *
#        *  @}
#        */
#
#   Checklist for building a new Istep:  ( [x] means done by this script )
##
#   1. [x]  Update the src/usr/hwpf/hwp/<@istepname>/<@istepname.H>
#           with the prototypes, etc. from the istep/substep.
#
#   2. [x]  Create a new file src/usr/hwpf/hwp/<@istepname>/<@istepname.C>
#           (use src/usr/hwpf/hwp/template.C as a template)
#
#   3. [x]  Make a new istep<@istepnum>list.H file in /usr/include/isteps/
#           Add the new istep<@istepnum>list.H file to
#           src/include/usr/istepmasterlist.H in the correct place in the
#           master istep list.
#
#   3.1 [ ] TODO:  if istepnum's are not contiguous, pad out the isteplist
#                   with { NULL, 0, NULL }
#   3.2 [ ] TODO:  make sure there are no tabs in output
#
#   3.3 [x] TODO:  use correct istep #'s in ISTEPNUM() macro $$$$$$$
#
#   3.4.[ ] TODO:   check mode - check files (numbering,etc) against tag blocks
#
#   3.5 [ ] TODO:   fix mode - rewrite just one type of file: .H, .C,
#                   makefile, etc.
#                   useful for updating H and list files without messing up
#                   code that has been added to C files.
#
#   4. [x]  Make up new makefile src/usr/hwpf/hwp/<@istepname>/makefile to
#           compile the HWP and wrapper
#
#   5. [ ] Update all the other makefiles:
#       src/usr/hwpf/hwp/makefile   ( add SUBDIR )
#       src/makefile            ( add to EXTENDED_MODULES )
#
#
#   Make a new istep<@istepnum>list.H file in /usr/include/isteps/
#   Add the new istep<@istepnum>list.H file to src/include/usr/istepmasterlist.H
#       in the correct place in the master istep list.
#
#   Create a tag block, usually in src/usr/hwpf/hwp/<@istepname>/<@istepname.H>
#       At present this is optional, but the (coming) genIstep.pl script will
#       not be able to maintain your istep without it.
#
#   The tag block keywords, with explanations, are as follows:
#   *   @tag isteplist
#       - should be at the beginning of the block to tell the (mythical) perl
#           script that this will generate an IStep wrapper for an HWP
#   *   @docversion     (version # of Dean's IPL document)
#       - adds a comment to istep<@istepname>list.H
#   *   @istepname      ( istep name from Dean's IPL document )
#       - creates a namespace ISTEP_NAME, i.e. uppercased <@istepame>
#           in <@istepname>.C and <@istepname>.H
#       - creates a new component id in src/include/usr/hbotcompid.H
#       - creates a new module id in src/include/usr/initsvcreasoncodes.H
#       - creates a modulename string "<@istepname>.so" for istep<@istepnum>list.H
#       - ?
#   *   @istepnum       (istep number from Dean's IPL document)
#       - creates a new istep<@istepnum>list.H file in /usr/include/isteps/
#       - adds the new istep<@istepnum>list.H file to src/include/usr/istepmasterlist.H
#           in the correct place in the master istep list.
#       - sets the istep number in the ISTEPNAME() macro in istep<@istepnum>list.H
#   *   @istepdesc      ( description of istep from Dean's document )
#       - creates comments in istep<@istepnum>list.H file
#   -- one or more substep blocks:
#   *   @substepname     (substepname from Dean's document)
#       - creates a prototype for <@substepname>
#   *   @substepnum     ( number of substep from Dean's document )
#       - sets the istep number in the ISTEPNAME() macro in istep<@istepnum>list.H
#           @target_sched  ( serial or parallel )
#           - will attempt to run each target either serially or in parallel
#       --  0 or more target types to be used as parameters to HWP
#           TBD needs work
#           @target_type    (type or class of targets that this HWP should run under)
#           - adds code to find the targets used in TARGETING
#
#
#   Make up a new directory  src/usr/hwpf/hwp/<@istepname>/<@substepname>
#   Copy code for new HWP to src/usr/hwpf/hwp/<@istepname>/<@substepname>,
#   using git:
#   - Go to the Gerrit page where the HWP is, and select the line to generate
#       a patch
#   - run this line and pipe it to a file.
#   - then run:
#        git apply --directory=src/usr/hwpf/hwp/@istepname/@substepname <file>
#
#       Example:  istep 12.2, mss_eff_config:
#       ## cutNpaste the patch comand from Gerrit and pipe to a file:
#       git fetch ssh://wenning@gfw160.austin.ibm.com:29418/hwp_review_centaur refs/changes/63/663/3 && git format-patch -1 --stdout FETCH_HEAD > mss_eff_config.patch
#       ##  then run the git command to put the code in the right directory:
#       git apply --directory=src/usr/hwpf/hwp/mc_config/mss_eff_config   mss_eff_config.patch
#
#   Add makefile support for the new HWP:
#   -   src/usr/hwpf/makefile       ( add any xml files to HWP_ERROR_XML_FILES )
#   - Scan src/usr/hwpf/hwp/@substepname/makefile for the line:
#       ##  NOTE: add a new EXTRAINCDIR when you add a new HWP
#   - Add new line just after it:
#       EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/@istepname/@substepname
#   - Scan further for the line:
#       ##  NOTE: add a new directory onto the vpaths when you add a new HWP
#   - Add new line just after it:
#       VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/@istepname/@substepname
#   - Scan further for the line:
#       OBJS = ??
#   - Append $substepname.o on to the end of it.  May have to wrap at 80 chars

#
#   Part of the HWP source should (may??) be a <@substep>.xml file .
#   - Update hwpf/makefile to process the xml file  in the
#       Source XML files section:
#       #------------------------------------------------------------------------------
#       # Source XML files
#       #------------------------------------------------------------------------------
#       HWP_ERROR_XML_FILES = ...
#


#------------------------------------------------------------------------------
# Specify perl modules to use
#------------------------------------------------------------------------------
use strict;
use warnings;
use POSIX;
use Getopt::Long;
## use Getopt::Long qw(GetOptionsFromString) ;
use File::Basename;
use lib dirname (__FILE__);


#------------------------------------------------------------------------------
# Constants
#------------------------------------------------------------------------------
use constant    ERR_INVALID_START_TAG   =>  1;
use constant    ERR_DUPLICATE_TAG       =>  2;
use constant    ERR_NO_TAG_FILE         =>  3;
use constant    ERR_NO_ISTEP_DIR        =>  4;
use constant    ERR_NO_TAG_BLOCK        =>  5;
use constant    ERR_NO_ISTEP_LIST_DIR   =>  6;


#------------------------------------------------------------------------------
# Forward Declaration
#------------------------------------------------------------------------------
sub printUsage;
sub extractTagBlock;
sub processBlock;
sub storeTagInHash;
sub createIstepHFile;
sub createIstepCFile;
sub createIstepListFile;
sub createMakefile;

#------------------------------------------------------------------------------
# Globals
#------------------------------------------------------------------------------
my  %Hash       =   ();
my  $Tag_Block   =   "";

#####################################################################
#####   begin   templateHFileHdr    #################################
my  $templateHFileHdr   =
"
#ifndef  __\@\@istepname_\@\@istepname_H
#define  __\@\@istepname_\@\@istepname_H

/**
 *  \@file \@istepname.H
 *
 *  \@istepdesc
 *
 *  All of the following routines are \"named isteps\" - they are invoked as
 *  tasks by the \@ref IStepDispatcher.
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON \@timestamp
 *  *****************************************************************
 *
 *  HWP_IGNORE_VERSION_CHECK
 */

 \@tag_block

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

namespace   \@\@istepname
{
";
#####   end     templateHFileHdr    #################################
#####################################################################

#####################################################################
#####   begin   templateHFileSubStep    #############################
my  $templateHFileSubStep   =
"
/**
 *  \@brief   \@substepname
 *
 *  \@istepnum.\@substepnum : \@substepdesc
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  none
 *
 */
void    call_\@substepname( void    *io_pArgs );
";
#####   end     templateHFileSubStep    #############################
#####################################################################


#####################################################################
#####   begin   templateHFileTrailer   ##############################
my  $templateHFileTrailer    =
"
};   // end namespace

#endif
";
#####   end templateHFileTrailer    #################################
#####################################################################


#####################################################################
#####   begin   templateCFileHdr    #################################
my  $templateCFileHdr   =
"
/**
 *  \@file \@istepname.C
 *
 *  Support file for IStep: \@istepname
 *   \@istepdesc
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON \@timestamp
 *  *****************************************************************
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <initservice/isteps_trace.H>

//  targeting support
#include <targeting/common/commontargeting.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>

#include    <hwpisteperror.H>

#include    \"\@istepname.H\"

//  Uncomment these files as they become available:
";
#####   end templateCFileHdr    #####################################
#####################################################################


#####################################################################
#####   begin templateCFileNSHdr    #####################################
my  $templateCFileNSHdr  =
"
namespace   \@\@istepname
{

using   namespace   TARGETING;
using   namespace   ISTEP_ERROR;
using   namespace   fapi;
";
#####   end templateCFileNSHdr    #####################################
#####################################################################


#####################################################################
#####   begin   templateCFileSubStep    #############################
my $templateCFileSubStep =
"
//
//  Wrapper function to call \@istepnum.\@substepnum :
//      \@substepname
//
void*    call_\@substepname( void    *io_pArgs )
{

    IStepError  l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               \"call_\@substepname entry\" );

#if 0
    errlHndl_t  l_errl  =   NULL;
    // \@\@\@\@\@    CUSTOM BLOCK:   \@\@\@\@\@
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)

    //  write HUID of target
    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              \"target HUID: %.8X\",
              TARGETING::get_huid(l_\@targetN_target));

    // cast OUR type of target to a FAPI type of target
    const fapi::Target l_fapi_\@targetN_target(
                    TARGET_TYPE_MEMBUF_CHIP,
                    reinterpret_cast<void *>
                        (const_cast<TARGETING::Target*>(l_\@targetN_target)) );

    //  call the HWP with each fapi::Target
    FAPI_INVOKE_HWP( l_errl, \@substepname, _args_...);
    if ( l_errl )
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  \"ERROR : \@substepname, errorlog PLID=0x%x\",
                  lerrl->plid()  );

        l_StepError.addErrorDetails( l_errl);

        errlCommit( l_errl, HWPF_COMP_ID );
    }
    else
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   \"SUCCESS : \@substepname \" );
    }
    // \@\@\@\@\@    END CUSTOM BLOCK:   \@\@\@\@\@
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               \"call_\@substepname exit\" );

    // end task, returning any errorlogs to IStepDisp
    return  l_StepError.getErrorHandle();
}
";
#####   end templateCFileSubStep    #################################
#####################################################################


#####################################################################
#####   begin   templateCfileTrailer    #############################
my  $templateCFileTrailer    =
"
};   // end namespace
";
#####   end     templateCFileTrailer    #############################
#####################################################################



#####################################################################
#####   begin   templateListFileHdr1   #############################
my  $templateListFileHdr1 =
"
#ifndef __ISTEPS_ISTEP\@istepnumLIST_H
#define __ISTEPS_ISTEP\@istepnumLIST_H

/**
 * \@file    istep\@istepnumlist.H
 *
 *  IStep \@istepnum    \@istepdesc
 *  IPL FLow Doc        \@docversion
 *
";
 #####   end     templateListFileHdr1    #############################
#####################################################################


#####################################################################
#####   begin   templateListFileHdr2   #############################
my $templateListFileHdr2    =
" *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON \@timestamp
 *  *****************************************************************
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */

#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

//  include prototypes file
#include    \"../../../usr/hwpf/hwp/\@istepname/\@istepname.H\"

namespace   INITSERVICE
{
    const   TaskInfo    g_istep\@istepnum[]  =   {

        {

                \"\",         // dummy, index 0
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                }
        },
";
#####   end     templateListFileHdr2    #############################
#####################################################################


#####################################################################
#####   begin   templateListFileSS  #################################
my  $templateListFileSS1  =
"        {
                ISTEPNAME(\@istepnum,\@substepnum,\"\@substepname\"),
                \@\@istepname::call_\@substepname,
                {
                        START_FN,
                        EXT_IMAGE,
                }
        },
";
#####   end     templateListFileSS    #############################
#####################################################################


#####################################################################
#####   begin   templateListFileSS  #################################
my  $templateListFileSS2  =
"        {
                \"\@substepname\",
                NULL,
                {
                        NONE,
                        EXT_IMAGE,
                }
        },
";
#####   end     templateListFileSS    #############################
#####################################################################


#####################################################################
#####   begin   templateListFileTrailer  ############################
my  $templateListFileTrailer =
"
        //  END OF LIST!
};

// make a struct from the above with the number of items included
const   ExtTaskInfo g_istep\@istepnumTaskList    =   {
        &(g_istep\@istepnum[0]),
        ( sizeof(g_istep\@istepnum)/sizeof(TaskInfo) ),
        NULL    //  later, depModules struct
};

};  // end namespace

#endif
";
#####   end     templateListFileTrailer    #############################
#####################################################################

#####################################################################
#####   begin   templateMakeFile  ###################################
my  $templateMakeFile   =
"
ROOTPATH = ../../../../..

MODULE = \@istepname

##      support for Targeting and fapi
EXTRAINCDIR += \${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += \${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += \${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += \${ROOTPATH}/src/include/usr/hwpf/hwp

## pointer to common HWP files
EXTRAINCDIR += \${ROOTPATH}/src/usr/hwpf/hwp/include

##  NOTE: add the base istep dir here.
EXTRAINCDIR += \${ROOTPATH}/src/usr/hwpf/hwp/\@istepname

##  Include sub dirs
##  NOTE: add a new EXTRAINCDIR when you add a new HWP
##  EXAMPLE:
##  EXTRAINCDIR += \${ROOTPATH}/src/usr/hwpf/hwp/\@istepname/<HWP_dir>


##  NOTE: add new object files when you add a new HWP
OBJS =  \@istepname.o


##  NOTE: add a new directory onto the vpaths when you add a new HWP
##  EXAMPLE:
#   VPATH += \${ROOTPATH}/src/usr/hwpf/hwp/\@istepname/<HWP_dir>


include \${ROOTPATH}/config.mk
";
#####   end     templateMakeFile    #############################
#####################################################################



#==============================================================================
# MAIN
#==============================================================================
my  $pgmDir  =   `dirname $0`;
chomp( $pgmDir );

my $hbDir = $ENV{'HB_IMGDIR'};
if ( ! defined( $hbDir) || ( $hbDir eq "" ) )
{
    $hbDir = $pgmDir;               ##  Set to tool directory
}


## print   $#ARGV;
if ( $#ARGV < 0 )
{
    printUsage();
    exit    0 ;
}
#------------------------------------------------------------------------------
# Parse optional input arguments
#------------------------------------------------------------------------------
my  $opt_help       =   0;
my  $opt_tag_file   =   "";
my  $opt_dry_run    =   0;
my  $opt_debug      =   0;
my  $istepDir       =   "";
my  $istepListDir   =   "src/include/usr/isteps";
my  $opt_gen_C       =   0;


GetOptions( 'help|?'            => \$opt_help,
            'tag-file=s'        => \$opt_tag_file,
            'istep-dir=s'       => \$istepDir,
            'istep-list-dir=s'  => \$istepListDir,
            'gen-C'             => \$opt_gen_C,
            'dry-run'           => \$opt_dry_run,
            'debug'             => \$opt_debug,
            );

if  ( $opt_debug )
{
    print   STDERR  "help       =   $opt_help\n";
    print   STDERR  "debug      =   $opt_debug\n";
    print   STDERR  "tag-file   =   $opt_tag_file\n";
    print   STDERR  "dry-run    =   $opt_dry_run\n";
    print   STDERR  "gen-C      =   $opt_gen_C\n";
    print   STDERR  "istepDir   =   $istepDir\n";

}


##  check for required options
if ( $opt_tag_file  eq  "" )
{
    print   STDOUT  "No tag file specified\n";
    printUsage();
    exit    ERR_NO_TAG_FILE;
}

if ( $istepDir  eq  "" )
{
    print   STDOUT  "No istep-dir specified.\n";
    exit    ERR_NO_ISTEP_DIR;
}

if ( $istepListDir  eq  "" )
{
    print   STDOUT  "No istep-list-dir specified.\n";
    exit    ERR_NO_ISTEP_LIST_DIR;
}

if ( ! -e $opt_tag_file )
{
    print STDOUT    "Tag file $opt_tag_file doesn't exist\n";
    exit ERR_NO_TAG_FILE;
}

if (    ( ! -e $istepDir )
     || ( ! -d $istepDir )
    )
{
    print STDOUT    "dir $istepDir doesn't exist.\n";
    exit    ERR_NO_ISTEP_DIR;
}

if (    ( ! -e $istepListDir )
     || ( ! -d $istepListDir )
    )
{
    print STDOUT    "dir $istepListDir doesn't exist.\n";
    exit    ERR_NO_ISTEP_LIST_DIR;
}

##  extract tag block
if ( extractTagBlock( $opt_tag_file )  != 0 )
{
    print   STDOUT  "No Tag block in $opt_tag_file.\n";
    exit    ERR_NO_TAG_BLOCK;
}

##  save the original to re-insert in the H file
my  $Extracted_Tag_Block =   $Tag_Block;


##  strip comment junk  from Tag Block
$Tag_Block =~ s/^(\*|\s)*//gmo;

##  split cleaned up lines from Tag_block into an array
my  @tag_lines  =   split /^/, $Tag_Block;

## print STDERR    ">>>@tag_lines<<<\n";

##  OK, start storing tag values
while ( $_ = shift( @tag_lines ) )
{
    if ( ! defined $_ )
    {
        if ( $opt_debug )   {   print STDERR    "Done.\n";  }
        last;
    }

    ##  strip junk at the beginning
    s/^(\*|\s)*//;

    chomp;
    if ( $opt_debug )   {   print   "-$_\n";    }

    if  ( m/\@\{/ )
    {
        ##  process the tag block
        processBlock( \@tag_lines );
    }

    if  ( m/\@docversion/ )
    {
        s/^\@docversion\s+//;
        storeTagInHash( "docversion", $_ );
    }

    if  ( m/\@istepname/ )
    {
        s/^\@istepname\s+//;
        storeTagInHash( "istepname", $_ );
    }

    if  ( m/\@istepnum/  )
    {
        s/^\@istepnum\s+//;
        storeTagInHash( "istepnum", $_ );
    }

    if  ( m/\@istepdesc/ )
    {
        s/^\@istepdesc\s+//;
        storeTagInHash( "istepdesc", $_ );
    }
}

##  -----   Begin writing the files.    ---------------------------------

#   Make up (or modify) src/usr/hwpf/hwp/<@istepname>/<@istepname.H>
#       (use src/usr/hwpf/hwp/template.H as a template)
createIstepHFile( );

##  The rest of the files can pretty safely be changed; the C file
##  possibly (probably) contains modifications.
##  Thus this flag - default is to NOT generate a new C file.
#
#   Make up a new file src/usr/hwpf/hwp/<@istepname>/<@istepname.C>
#      (use src/usr/hwpf/hwp/template.C as a template)
if  ( $opt_gen_C )
{
    createIstepCFile( );
}

#   Make a new istep<@istepnum>list.H file in /usr/include/isteps/
#   Add the new istep<@istepnum>list.H file to
#       src/include/usr/istepmasterlist.H in the correct place in the
#       master istep list.
createIstepListFile( );

#   Make up new makefile src/usr/hwpf/hwp/<@istepname>/makefile to compile
#           the HWP and wrapper
createMakefile();


print   STDOUT  "Done.\n";

#==============================================================================
# SUBROUTINES
#==============================================================================

##
##  Print the usage (help) message
##
sub printUsage()
{
    print   STDOUT  "genIStep.pl\n";
    print   STDOUT  "   --tag-file <path>           ( required: file containing tag block )\n";
    print   STDOUT  "   --istep-dir <path>          ( required: directory where istep code will be generated )\n";

    print   STDOUT  "   [ --istep-list-dir <path> ] ( directory where istepNlist.H will be generated\n";
    print   STDOUT  "                               ( this is usually src/include/usr/isteps )\n";
    print   STDOUT  "   [ --gen-C                   ( generate the stub C file.  Default is to NOT do this.\n";
    print   STDOUT  "   [ --help ]                  ( prints usage message )\n";
    ## print   STDOUT  "    [ --dry-run ]       ( prints all steps without doing anything )\n";
}


##
##  extract tag block from the passed-in file and put in the global $Tag_Block
##
sub extractTagBlock( $ )
{
    my  ( $in_tag_file )    =   @_;
    my  $data   =   "";

    open( TAGFH, "< $in_tag_file") or die " $? : can't open $in_tag_file : $!";
    read( TAGFH, $data, -s TAGFH ) or die "Error reading $in_tag_file: $!";
    close TAGFH;

    # =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    # Capture everything from opening '/* @tag isteplist' to end of tags '*/'
    #
    # Example:
    #   /*  @tag    isteplist
    #    *  ...
    #    */
    # =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    ##  Extract Tag block
    while ($data =~ /(\/\*\s*\@tag\s+isteplist)((.|\n)+?)(\*\/)/mgo )
    {
        ## $Tag_Block = "$2";
        $Tag_Block = "$1$2$4";
    }

    if ( $Tag_Block eq  "" )
    {
        return  1;
    }

    if ( $opt_debug )
    {
        print STDERR "debug: Extracted Tag Block: \n$Tag_Block\n";
    }

    return  0;
}

##
##  Store a tag in the hash table, given a key and value
##      @param  $key    -   key
##      @param  $value  -   value
##
sub storeTagInHash( $$ )
{
    my ( $key, $value ) =   @_;
    my  $rc =   0;

    if  ( exists  $Hash{ $key } )
    {
        print   STDOUT  "ERROR: duplicate tag \"$key\" \n";
        $rc =   ERR_DUPLICATE_TAG;
    }
    else
    {
        $Hash{ $key } =   $value;
    }

    if ( $opt_debug )   {   print STDERR "storetag: $key = $Hash{ $key }\n";  }

    return  $rc;
}


##
##  process a tag block from the caller
##  Note that this is passed a reference to the
##  original array so that we can shift the array
##  as we use up lines.
sub processBlock( $ )
{
    my  (@tag_block)    =   @{$_[0]};               # this is actually a copy
    my  %localhash      =   ();

    while ( $_  =   shift( @{$_[0]} ) )             ##@tag_block)  )
    {
        chomp;
        if ( $opt_debug )   {   print   "process:   $_\n";  }
        if ( m/\@}/ )
        {
            if ( $opt_debug )   {   print   "$_ : done.\n"; }
            last;
        }

        if  (   m/\@substepnum/  )
        {
            s/^\@substepnum\s+//;
            #storeTagInHash( \%localhash, "substepnum", $_ );
            $localhash{'substepnum'}    =   $_;
        }

        if  (   m/\@substepname/ )
        {
            s/^\@substepname\s+//;
            #storeTagInHash( \%localhash, "substepname", $_ );
            $localhash{'substepname'}    =   $_;
        }

        if  (   m/\@substepdesc/ )
        {
            s/^\@substepdesc\s+//;
            #storeTagInHash( \%localhash, "substepdesc", $_ );
            $localhash{'substepdesc'}    =   $_;
        }


        if  (   m/\@target_sched/    )
        {
            s/^\@target_sched\s+//;
            #storeTagInHash( \%localhash, "target_sched", $_ );
            $localhash{'target_sched'}  =   $_;
        }
    }

    ##  Store results in %Hash using keys like "<key>:<substepnum>"
    ##      Keep it easy and flat.
    if (    ( exists $localhash{'substepname'} )
         && ( exists $localhash{'substepnum' } )
        )
    {
        my  $num    =   sprintf( "%2.2d", int($localhash{'substepnum'}) );
        $Hash{ "substepname:$num"}= $localhash{'substepname'};
        $Hash{ "substepnum:$num"}= $localhash{'substepnum'};

        if (exists $localhash{'substepdesc'} )
        {
            $Hash{ "substepdesc:$num"}= $localhash{'substepdesc'};
        }

        if (exists $localhash{'target_sched'} )
        {
            $Hash{ "target_sched:$num"}= $localhash{'target_sched'};
        }
    }
    else
    {
        print   STDOUT  "Incomplete tag block for $localhash{'substepname'}\n";

    }
}

##
##  Back up old file before we start modifying it, if it exists.
##
sub backupOldFile( $ )
{
    my  $backupFileName  =   shift;

    if ( $opt_debug )
    {
        print   STDERR  "backing up $backupFileName, if necessary...\n";
    }

    if ( -e $backupFileName )
    {
        my  $ts  =   `date +%Y-%m-%d.%H%M`;
        chomp   $ts;
        my  $old_file   =   "$backupFileName.org_$ts";
        print   STDOUT  "   $backupFileName exists, renaming to $old_file\n";
        rename( $backupFileName, "$old_file" );
    }
}

##
##  Apply all the tags that belong to the istep to a multiline string
##      @docversion
##      @istepname
##      @istepnum
##      @istepdesc
##
##  param[in,out]   -   ref to a multiline string
##
##  Assumes that the istep tag values stored in the correct place in %Hash
##
sub applyIstepTags
{
    my  $str_ref    =   shift;
    my  $istepname  =  $Hash{'istepname'};
    my  $istepnum   =   $Hash{'istepnum'};
    my  $docversion =   $Hash{'docversion'};
    my  $istepdesc  =   $Hash{'istepdesc'};
    my  $upCaseistepname =   toupper( $istepname );
    my  $timestamp  =   `date +%Y-%m-%d:%H%M`;
    chomp   $timestamp;

    ${$str_ref}    =~  s/\@timestamp/$timestamp/gmo;
    #   replace "@@istepname"
    ${$str_ref}    =~  s/\@\@istepname/$upCaseistepname/gmo;
    #   replace "@istepname"
    ${$str_ref}    =~  s/\@istepname/$istepname/gmo;
    #   replace "istepnum"
    ${$str_ref}    =~  s/\@istepnum/$istepnum/gmo;
    #   replace "@istepdesc"
    ${$str_ref}    =~  s/\@istepdesc/$istepdesc/gmo;
    #   replace "@docversion"
    ${$str_ref}    =~  s/\@docversion/$docversion/gmo;

}

##
##  Make up a new file src/usr/hwpf/hwp/<@istepname>/<@istepname.H>
##   (use src/usr/hwpf/hwp/template.H as a template)Create the IstepHFile( )
##  This creates a new file, it will not carry anything over from an old file
##  Instead, it will rename the old file to <file>.org_YYYY.MM.DD:HHDD
##
sub createIstepHFile( )
{
    my  $istepname  =  $Hash{'istepname'};
    my  $istepHfile =   "$istepDir/$istepname.H";

    print STDOUT  "Create file $istepHfile...\n";

    ## @todo sanity check - $istepDir should be src/usr/hwpf/hwp/<@istepname>/

    backupOldFile( $istepHfile );

    open( HFH, "> $istepHfile") or die " $? : can't open $istepHfile : $!";

    ##  apply all the istep tags to the header
    applyIstepTags( \$templateHFileHdr );

    ##  add the original tag block as comments.
    ##  my  $cleaned_up_tag_block   =   $Tag_Block;
    ##  chomp   $cleaned_up_tag_block;
    ## $cleaned_up_tag_block   =~  s/^/ * /gmo;
    ## $templateHFileHdr   =~  s/\@tag_block/$cleaned_up_tag_block/gmo;
    $templateHFileHdr   =~  s/\@tag_block/$Extracted_Tag_Block/gmo;

    print   HFH "$templateHFileHdr\n";

    ##  generate substeps
    my  @substepnames   =   sort grep /substepname/,    ( keys %Hash );
    my  @substepnums    =   sort grep /substepnum/,     ( keys %Hash );
    my  @substepdescs   =   sort grep /substepdesc/,    ( keys %Hash );
        if ( $opt_debug )
    {

        print   "$istepname.H file: @substepnames\n";
        print   STDERR  "substeps last index = $#substepnames.\n";
    }

    ##  write each substep section
    for ( my $i=0; $i<=$#substepnames; $i++ )
    {
        ##  make a local copy to modify
        my  $templateHSS =   $templateHFileSubStep;
        applyIstepTags( \$templateHSS );

        #   replace "@substepname"
        $templateHSS    =~  s/\@substepname/$Hash{$substepnames[$i]}/gmo;
        #   replace "substepnum"
        $templateHSS    =~  s/\@substepnum/$Hash{$substepnums[$i]}/gmo;
        #   replace "@substepdesc"
        $templateHSS    =~  s/\@substepdesc/$Hash{$substepdescs[$i]}/gmo;

        print   HFH "\n$templateHSS\n";
    }

    print   HFH "$templateHFileTrailer\n";


    close   HFH;
}


##
##  Make up a new file src/usr/hwpf/hwp/<@istepname>/<@istepname.C>
##      (use src/usr/hwpf/hwp/template.C as a template)
##  This creates a new file, it will not carry anything over from an old file
##  Instead, it will rename the old file to <file>.org_YYYY.MM.DD:HHDD
##
sub createIstepCFile( )
{
    my  $istepname  =  $Hash{'istepname'};
    my  $istepCfile =   "$istepDir/$istepname.C";

    print STDOUT  "Create file $istepCfile...\n";

    ## sanity check - $istepDir should be src/usr/hwpf/hwp/<@istepname>/

    backupOldFile( $istepCfile );

    open( CFH, "> $istepCfile") or die " $? : can't open $istepCfile : $!";

    applyIstepTags( \$templateCFileHdr );
    print   CFH "$templateCFileHdr";

    ##  generate substeps
    my  @substepnames   =   sort grep /substepname/,    ( keys %Hash );
    my  @substepnums    =   sort grep /substepnum/,     ( keys %Hash );
    my  @substepdescs   =   sort grep /substepdesc/,    ( keys %Hash );
    if ( $opt_debug )
    {

        print   "$istepname.C file: @substepnames\n";
        print   STDERR  "substeps last index = $#substepnames\n";
    }

    ##  Write the lines to include the hwp h file
    for ( my $i=0; $i<=$#substepnames; $i++ )
    {
        ##  Write the line to include the hwp h file
        print   CFH "// #include    \"$Hash{$substepnames[$i]}/$Hash{$substepnames[$i]}.H\"\n";
    }

    applyIstepTags( \$templateCFileNSHdr );
    print   CFH "$templateCFileNSHdr\n";

    ##  write each substep section
    for ( my $i=0; $i<=$#substepnames; $i++ )
    {
        ##  make a local copy to modify
        my  $templateCSS =   $templateCFileSubStep;
        applyIstepTags( \$templateCSS );

        #   replace "@substepname"
        $templateCSS    =~  s/\@substepname/$Hash{$substepnames[$i]}/gmo;
        #   replace "substepnum"
        $templateCSS    =~  s/\@substepnum/$Hash{$substepnums[$i]}/gmo;
        #   replace "@substepdesc"
        $templateCSS    =~  s/\@substepdesc/$Hash{$substepdescs[$i]}/gmo;

        print   CFH "\n$templateCSS\n";
    }

    print   CFH "$templateCFileTrailer";

    close( CFH );
}

##
##  Make a new istep<@istepnum>list.H file in /usr/include/isteps/
##      Add the new istep<@istepnum>list.H file to
##      src/include/usr/istepmasterlist.H in the correct place in the
##      master istep list.
##
sub createIstepListFile( )
{

    my  $istepname  =   $Hash{'istepname'};
    my  $istepnum   =   $Hash{'istepnum'};
    my  $istepLfile =   $istepListDir . "/istep" . $istepnum . "list.H";

    print STDOUT  "Create file $istepLfile...\n";

    ## sanity check - $istepListDir should be src/include/usr/isteps

    backupOldFile( $istepLfile );

    open( LFH, "> $istepLfile") or die " $? : can't open $istepLfile : $!";

    applyIstepTags( \$templateListFileHdr1 );
    print   LFH "$templateListFileHdr1";

    ##  generate substeps
    my  @substepnames   =   sort grep /substepname/,    ( keys %Hash );
    my  @substepnums    =   sort grep /substepnum/,     ( keys %Hash );
    my  @substepdescs   =   sort grep /substepdesc/,    ( keys %Hash );
    if ( $opt_debug )
    {

        print   "$istepname.C file: @substepnames\n";
        print   STDERR  "substeps last index = $#substepnames\n";
    }

    ##   write the documentation lines in the istepNlist file
    for ( my $i=0; $i<=$#substepnames; $i++ )
    {
        print   LFH " *    $istepnum.$Hash{$substepnums[$i]}    $Hash{$substepnames[$i]}\n";
        print   LFH " *          $Hash{$substepdescs[$i]}\n";
    }

    applyIstepTags( \$templateListFileHdr2 );
    print   LFH "$templateListFileHdr2";


    ##  write each substep section
    for ( my $i=0; $i<=$#substepnames; $i++ )
    {
        ##  make a local copy to modify
        ##  @todo   check for @internal tag and use templateListFileSS2
        my  $templateLSS =   $templateListFileSS1;
        applyIstepTags( \$templateLSS );

        #   replace "@substepname"
        $templateLSS    =~  s/\@substepname/$Hash{$substepnames[$i]}/gmo;
        #   replace "substepnum" with 2 digits & leading 0's
        my  $pad_substep    =   sprintf( "%02d", $Hash{$substepnums[$i]} );
        ## $templateLSS    =~  s/\@substepnum/$Hash{$substepnums[$i]}/gmo;
        $templateLSS    =~  s/\@substepnum/$pad_substep/gmo;
        #   replace "@substepdesc"
        $templateLSS    =~  s/\@substepdesc/$Hash{$substepdescs[$i]}/gmo;

        print   LFH "\n$templateLSS\n";
    }

    applyIstepTags( \$templateListFileTrailer );
    print   LFH "$templateListFileTrailer";


    close   LFH;
}

##
##  Make up new makefile src/usr/hwpf/hwp/<@istepname>/makefile to
##      compile the HWP and wrapper
##
sub createMakefile( )
{
    my  $istepname  =  $Hash{'istepname'};
    my  $istepMakefile =   "$istepDir/makefile";

    print STDOUT  "Create file $istepMakefile...\n";

    ## @todo sanity check - $istepDir should be src/usr/hwpf/hwp/<@istepname>/

    backupOldFile( $istepMakefile );

    open( MFH, "> $istepMakefile") or die " $? : can't open $istepMakefile : $!";

    ##  apply all the istep tags to the header
    applyIstepTags( \$templateMakeFile );

    print   MFH "$templateMakeFile\n";

    close   MFH;
}



__END__
