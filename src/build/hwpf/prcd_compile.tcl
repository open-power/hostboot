#!/bin/sh
#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/hwpf/prcd_compile.tcl $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2011
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
# The next line is executed by /bin/sh, but not tcl \
exec tclsh "$0" "$@" 

# Name: prcd_compile.tcl - Compile a hardware procedure remotely
#
# Based on if_make.tcl by Doug Gilbert


#---------------------------------------------------------
# TBD - No Support Yet 
#---------------------------------------------------------
proc getPassword { prompt } {
     exec stty -echo echonl <@stdin

     # Print the prompt
     puts -nonewline stdout $prompt
     flush stdout

     # Read that password!  :^)
     gets stdin password

     # Reset the terminal
     exec stty echo -echonl <@stdin

     return $password
}

#---------------------------------------------------------
# TBD - No Support Yet 
#---------------------------------------------------------
proc mysend { chan val } {
    #puts "Sending>>>$val<<<<"
    puts $chan $val
}

#---------------------------------------------------------
# TBD - No Support Yet 
#---------------------------------------------------------
proc telnetResult { telnet } {
    global telnet_out
    #puts "Reading $telnet"

    if { [eof $telnet] || [catch { set dat [read $telnet]}] }  {
        #puts "GOT>>>AT END<<<"
        set telnet_out {AT END}
        if { [catch {close $telnet} res] }  {
            puts "Error: $res"
        }
    } else {
        #puts "GOT>>>$dat<<<<"
        append telnet_out $dat
    }
}


# Wait for p to showup in telnet_out
# return 1 if timout else returns 0
proc wait_for { p } {
    global telnet_out
    while { 1 } {
        vwait telnet_out
        if { [string last $p $telnet_out] > -1 } { return 0 }
        if { [string compare {timeout} $telnet_out] == 0 } { return 1 }
    }  
}


#---------------------------------------------------------
# TBD - No Support Yet 
#---------------------------------------------------------
proc get_fsp_info { fspip fsppassword} {
    global telnet_out
    set telnet_out {}

    # Open telnet session
    if {[catch {set telnet [open "|telnet $fspip" r+]} res]} {
        puts "Could not telnet to $fspip"
        return {}
    }
    fconfigure $telnet -buffering none -blocking 0

    # all output from telnet session captured by telnetResult procedure
    # put into telnet_out variable
    fileevent $telnet readable [list telnetResult $telnet]

    # Set a timeout of 20 seconds
    set timeoutid [after 20000 {
        set telnet_out {timeout}
        close $telnet
    } ]

    if {[wait_for {login:}]} { return {} }

    mysend $telnet {root}
    if { [wait_for {Password:}]} { return {} }

    mysend $telnet "$fsppassword"
    while { 1 } {
        vwait telnet_out
        if { [string last {$} $telnet_out] > 0 } { break }
        if { [string last {Login incorrect} $telnet_out] > 0 } {
            puts {Login incorrect}
            close $telnet
            return {}
        }
        if { [string compare $telnet_out {timeout}] == 0 } { return {} }
    }
    set telnet_out {}
  
    mysend $telnet {registry -r fstp/DriverName}
    if { [wait_for {$}]} { return {} }

    regexp {registry -r fstp/DriverName.+fips[0-9]+/(.+)\n.+} $telnet_out a driver
    set telnet_out {}

    mysend $telnet {cat /proc/mounts | grep /nfs}
    if { [wait_for {$}]} { return {} }

    regexp {.+\n(.+?):(.+?) +/nfs nfs .+} $telnet_out a companion_ip nfs_dir

    mysend $telnet {exit}
    if { [wait_for {AT END}]} { return {} }

    # Cancel the timout
    after cancel $timeoutid

    return "$driver:$companion_ip:$nfs_dir"
}

#---------------------------------------------------------
# TBD - No Support Yet 
#---------------------------------------------------------
proc start_patch_server_on_fsp { fspip fsppassword } {
    global telnet_out
    global telnet
    global fsp_server_port
    set telnet_out {}
    # Open telnet session
    if {[catch {set telnet [open "|telnet $fspip" r+]} res]} {
        puts "Could not telnet to $fspip"
        return 0
    }
    fconfigure $telnet -buffering none -blocking 0

    # all output from telnet session captured by telnetResult procedure
    # put into telnet_out variable
    fileevent $telnet readable [list telnetResult $telnet]

    # Set a timeout of 20 seconds
    set timeoutid [after 20000 {
        set telnet_out {timeout}
        close $telnet
    } ]

    if { [wait_for {login:}]} { return 0 }

    mysend $telnet {root}
    if { [wait_for {Password:}]} { return 0 }

    mysend $telnet "$fsppassword"
    while { 1 } {
        vwait telnet_out
        if { [string last {$} $telnet_out] > 0 } { break }
        if { [string last {Login incorrect} $telnet_out] > 0 } {
            puts {Login incorrect}
            close $telnet
            return 0
        }
        if { [string compare $telnet_out {timeout}] == 0 } { return 0 }
    }
    set telnet_out {}

    mysend $telnet {mkdir -p /nfs/data/engd}
    if { [wait_for {$}]} { return 0 }

    set telnet_out {}
    mysend $telnet {mkdir -p /nfs/data/rtbl}
    if { [wait_for {$}]} { return 0 }

    set telnet_out {}
    mysend $telnet {killall cini_patcher}
    if { [wait_for {$}]} { return 0 }

    set telnet_out {}
    mysend $telnet "cini_patcher &"
    if { [wait_for {Server ready}]} { return 0 }

    puts $telnet_out
    set telnet_out {}
    mysend $telnet {}
    if { [wait_for {$}]} { return 0 }
    set telnet_out {}

    mysend $telnet {exit}
    if { [wait_for {AT END}]} { return 0 }

    # Cancel the timout
    after cancel $timeoutid
    return 1
}

# ------------------------
# MAIN
# ------------------------
set userid $::env(USER)
set home $::env(HOME)
set domain [exec hostname -d]
set version "1.0"

set files [list]
set cmds  [list]
set servers [list gfw160.austin.ibm.com]

#-----------------------------------------------------------------------------------------
# Parse ARGs
#-----------------------------------------------------------------------------------------

set state flag
foreach arg $argv {
    switch -- $state {
        flag {
            switch -glob -- $arg {
		-quit { set cmds [list quit] }
		-d    { set state driverflag }
# NOT SUPPORTED -s    { set state fspflag }
# NOT SUPPORTED -p    { set state portflag }
                -v    { set verbose 1 }
                -o    { set state outputflag }
		-*h* { puts {prcd_compile.tcl [--help] [-d <drivername>] [-o <ouput dir> ] fapiTestHwp.C fapiTestHwp.H sample.initfile}
                       puts {}
                       puts {Note that currently this tool only supports the 3 files listed above as input }
                       puts {}
		       puts {example: > prcd_compile.tcl -d b0621a_2001_Sprint2 -o ./output/ fapiTestHwp.C fapiTestHwp.C sample.initfile}
                       puts {}
		       puts {On success, 5 files (hbicore.bin and hbicore_test.bin, hbicore.syms }
                       puts { hbicore_test.syms and hbotStringFile) will be placed in the output dir. }
                       puts {}
                       puts {The -d and -o parameters are optional.  Default for -d is the master level of code }
                       puts { and default for -o is the current working directory }
                       puts {}
                       puts "Version: $version"
                       puts {}
                       exit
                     }
                 *fapiTestHwp\.* { lappend files $arg }
                 *\.initfile     { lappend files $arg }
		default { puts "Unsupported File or Argument: $arg "
                          exit
                        }
	    }
	}
        driverflag {
            #lappend cmds ":DRIVER $arg"
            set driver $arg
            set state flag
	}
        fspflag {
            foreach {fspip fsp_port} [split $arg :] break
            set state flag
        }
        portflag {
            # Set the port the fsp patch server is listening on.
            # This is not the telnet port used in simics.
            # defaults to 7779
            set fsp_server_port $arg
            set state flag
        }
        outputflag {
            set output_dir $arg
            set state flag
        } 
    }
}

if {![info exists fsp_server_port]} { set fsp_server_port 7779 }

#-----------------------------------------------------------------------------------------
# Get fspip if not specified
#-----------------------------------------------------------------------------------------
# TBD - NOT SUPPORTED
if { ![info exists fspip] && ![info exists driver] } {
#    puts -nonewline {Enter telnet address of fsp: }
#    flush stdout
#    fconfigure stdin -blocking 1
#    foreach {fspip fsp_port} [split [gets stdin] { :}] break
#    fconfigure stdin -blockin 0
#     puts { No driver name input! }
#     exit
}

if { [info exists fspip] } {
    set fsppassword [getPassword "root password for fsp $fspip:"]
    set res [get_fsp_info "$fspip $fsp_port" $fsppassword]
    if { $res != "" } { foreach {driver companion_ip nfs_dir} [split $res {:}] break }

    if { [info exists driver]} {
        puts "FSP Driver: $driver"
    } else {
        puts {FSP login failed!}
        exit -1
    }

    if { $companion_ip != {} } {
        puts "Companion: $companion_ip"
    } else { unset companion_ip }


    if { $nfs_dir != {} } {
        puts "nfs_dir: $nfs_dir"
    }
}


if { ![info exists driver] } {
    # default to the master for the driver
    set driver "master"
}

if { ![info exists output_dir] } {
    # default to PWD for output
    set output_dir "./"
}

# Make the output directory
eval {exec} "mkdir -p $output_dir"

lappend cmds ":INFO userid $userid version $version"
lappend cmds ":DRIVER $driver"


##########################################################
# Generate command to send each input file
##########################################################
foreach filen $files {

     set file_size [file size $filen]
     set filesource($filen) $filen
     lappend cmds ":HWP_FILE $filen $file_size"
}

##########################################################
# Generate compile, retrieve, and complete directives
##########################################################
lappend cmds ":HWP_COMPILE"
lappend cmds ":HWP_RETRIEVE"
lappend cmds ":HWP_DONE"


set xfer_file_list {}

if {[llength $cmds] > 0 } {
    set result ""
    ##########################################################
    # Find a server to run on
    ##########################################################
    foreach server $servers {
        set result ""
        puts "Trying $server ..."
        if {[catch {set sockid [socket $server 7779] } res ] } {
            set result "    $res"
            puts $result
            continue
        } else { break }
    }
    ##########################################################
    # Now send all of the commands we generated sequentially
    # to the server, waiting for a :DONE between each one.
    ##########################################################
    # Note that currently we only support fapiTestHwp.C and .H as input
    if {$result == ""} {
        puts "Connected to $server - Starting Compile"
        foreach cmd $cmds {
            if {[info exists verbose]}  {puts "Send to hw procedure compiler:  $cmd"}
            if {[string compare $cmd {quit}] == 0 } {
                puts $sockid {quit}
                break
            } elseif {[regexp {^:HWP_FILE +(.+) +(.+)} $cmd a hwpfilename filesize]} {
                puts $sockid $cmd
                set hwpfile [open $filesource($hwpfilename) r]
                fconfigure $sockid -translation binary
                fconfigure $hwpfile -translation binary
                fcopy $hwpfile $sockid -size $filesize
                close $hwpfile
                fconfigure $sockid -translation auto
            } else {
                puts $sockid $cmd
            }
            flush $sockid
            set line ""
            while {[string compare $line {:DONE}] != 0} {
                if {[eof $sockid]} { break }
                gets $sockid line
                if {[info exists verbose]}  {puts "Received from hw procedure compiler:  $line"}
                if {[regexp {^:OBJ_FILE +(.+) +(.+)\n*} $line a b c] } {
                    fconfigure $sockid -translation binary
                    lappend xfer_file_list $b
                    set fp [open "$output_dir/$b" w]
                    fconfigure $fp -translation binary
                    fcopy $sockid $fp -size $c
                    close $fp
                    fconfigure $sockid -translation auto
                } elseif {[regexp {.*error:.*} $line ->] } {
                    puts stderr "Error in compile - $line"
                    set error 1
                }
            }
            if {[eof $sockid]} { break }
        }
        close $sockid
        if {[info exists error]}  {
               puts "Compile Failed!  See above errors"
               exit -1
           } else {
               puts "Compile Complete"
           }
    } else {
        #  The server must be down
        puts stderr "All The servers seems to be down"
        exit -1
    }
}


# telnet back to fsp and start patch server
# TBD - Not implemented in this sprint
if {[info exists companion_ip]} {
    if {$companion_ip != {}} {
        set res [start_patch_server_on_fsp "$fspip $fsp_port" $fsppassword]
        if { $res } {
            #puts "fspip $fspip"
            if {[catch { set sockid [socket $fspip $fsp_server_port] } res ] } {
                puts $res
                exit -1
            }
            # call fspipResult when sockid becomes readable
            fileevent $sockid readable [list fspipResult $sockid]
            #fconfigure $sockid -buffering line

            # send files
            foreach f $xfer_file_list {
                #puts "file: $f"
                if {[string match {*.if} $f] || [string match {*.dat} $f] } {
                    set dest_dir {/nfs/data/engd}
                } else {
                    set dest_dir {/nfs/data/rtbl}
                }
                set filesize [file size $f]
                puts $sockid ":PUT $dest_dir/[file tail $f] $filesize"
                puts ":FSPPUT $fspip:$dest_dir/[file tail $f] $filesize"
                set hwpfile [open $f r]
                fconfigure $sockid -translation binary
                fconfigure $hwpfile -translation binary
                #puts "fcopy $hwpfile $sockid -size $filesize"
                fcopy $hwpfile $sockid -size $filesize
                close $hwpfile
                fconfigure $sockid -translation auto
            }
            close $sockid
        }
    }
}

# should only see data comming back if there were errors.
proc fspipResult { sockid } {
    gets $sockid line
    puts $line
}
