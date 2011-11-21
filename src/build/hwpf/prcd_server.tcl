#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/hwpf/prcd_server.tcl $
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
# the next line restarts using tclsh\
exec tclsh "$0" "$@"


# Name: prcd_server.tcl - Compile a hardware procedure provided by a client.
#
# Based on if_server.tcl by Doug Gilbert


set version "1.0"

############################################################################
# Accept is called when a new client request comes in
# An event is forked that calls AquireData whenever the socket becomes 
# readable the main thread continues to run looking for more client requests
############################################################################

proc Accept { sock addr port} {

    global socklist
    global log
    puts "[clock format [clock seconds]]: Accept $sock from $addr port $port"
    puts $log "$port: [clock format [clock seconds]]: Accept $sock from $addr port $port"
    set socklist(addr,$sock) [list $addr $port]
    fconfigure $sock -buffering line
    fileevent $sock readable [list AquireData $sock]

}


############################################################################
# AquireData  is called whenever there is data avaiable from a client.
# with line buffering on sock, this means when a line is 
# Processes commands and collect data from client
############################################################################

proc AquireData { sock } {

    global socklist
    global sandbox
    global forever
    global sb_dir
    global sbname
    global hwpfile
    global git_sh
    global backing
    global log
    global running
    global driver


    if { [eof $sock] || [catch {gets $sock line}] } {
        puts "Client closed unexpectedly"
        puts $log "$sock: Client closed unexpectedly"
        CloseOut $sock
    } else {
        if { [string compare $line "quit"] == 0 } {
            close $socklist(main)
	        puts $sock "hw procedure compiler server is terminating"
            puts $log "$sock: hw procedure compiler server is terminating"
            CloseOut $sock
            set forever 0
        } elseif {[regexp {:DRIVER +(.+)} $line a b] } {

            ################################################################
            # Make a unique sandbox backed to the driver specified
            # Do a workon to the sandbox.
            ################################################################

            set driver $b
            set release ""  
            puts $log "$sock: Input driver $driver"
            flush $log

            ################################################################
            # create git repository
            ################################################################

            set sbname($sock) "sb[string range [clock seconds] 4 end]"

            puts $sock "$sbname($sock)"
            puts $log "$sock: $sbname($sock)"

            # Make sure sandbox dir exists
            if {[file exists $sb_dir]} {
                file mkdir "$sb_dir/$sbname($sock)"

                set git_sh($sock) [open "|bash" r+]
                fconfigure $git_sh($sock) -buffering none
                fileevent $git_sh($sock) readable [list IfResult $git_sh($sock) $sock $sbname($sock)]

                ExtractSandbox $sock $git_sh($sock)

            } else {
                puts $sock "Could not extract code\n"
                puts $log "$sock: Could not extract code\n)"
                CloseOut $sock
            }
        } elseif {[regexp {:HWP_FILE +(.+) +(.+)} $line a b c] } {

            ################################################################
            # Open the hw procedure file in the hw procedure directory
            ################################################################

            puts $log "$sock: Input File $b $c"
            flush $log	

            if { ![info exists sbname($sock)] } {
                puts $sock "No sandbox found"
                puts $log "$sock: No sandbox found"
                CloseOut $sock
                return

            }
            ################################################################
            # Create the path to the file in the git sandbox
            # If it's a .C file it goes to src/usr/hwpf/hwp/ otherwise
            # it's a .H and needs to go to src/include/usr/hwpf/hwp/ otherwise
            # it's an initfile and needs to go to src/usr/hwpf/hwp/initfiles/
            # Note that I can't get /* to work correctly in the regexp so I had to
            # hard code in the fapi which should be ok, but annoying.
            ################################################################

            if {[regexp {.*/*(fapi.+\.C)} $b -> file] } { 
                set filen "$sb_dir/$sbname($sock)/src/usr/hwpf/hwp/$file"	
            } elseif {[regexp {.*/*(fapi.+\.H)} $b -> file] } {
                set filen "$sb_dir/$sbname($sock)/src/include/usr/hwpf/hwp/$file"
            } elseif {[regexp {(.*\.initfile)} $b -> file] } {
                set filen "$sb_dir/$sbname($sock)/src/usr/hwpf/hwp/initfiles/$file"
            } else {
                puts $sock "error: Invalid Input File - $b"
                puts $log "$sock: Invalid Input File - $b"
                CloseOut $sock
                return
            }

            # Open with create/overwrite option
            if {[catch {set hwpfile($sock) [open "$filen" w+] } res ] } {
                puts $sock "Server can't open $filen"
                puts $log "$sock: Server can't open $filen"
                CloseOut $sock
            } else {
                fconfigure $hwpfile($sock) -translation binary
                fconfigure $sock -translation binary
                fcopy $sock $hwpfile($sock) -size $c
                close $hwpfile($sock)
                fconfigure $sock -translation auto
                puts $sock ":DONE"
                puts $log "$sock: DONE"
                flush $sock
            }
        } elseif {[string compare $line ":HWP_COMPILE"] == 0} {
            set git_sh($sock) [open "|bash" r+]
            fconfigure $git_sh($sock) -buffering none
            fileevent $git_sh($sock) readable [list IfResult $git_sh($sock) $sock $sbname($sock)]
            puts $git_sh($sock) "cd $sb_dir/$sbname($sock)"
            SendSandbox $sock $git_sh($sock)
            puts $sock ":DONE"
            puts $log "$sock: DONE"
            flush $sock
            flush $log
        } elseif {[string compare $line ":HWP_RETRIEVE"] == 0} {
            SendObjFiles $sock "$sb_dir/$sbname($sock)/img"
            puts $sock ":DONE"
            puts $log "$sock: DONE"
            flush $sock
        } elseif {[string compare $line ":HWP_DONE"] == 0} {
            puts $sock ":DONE"
            puts $log "$sock: DONE"
            CloseOut $sock
            set line ""
        } elseif {[regexp {:INFO +(.+)} $line a b] } {
            puts $sock ":DONE"
            puts $log "$sock: $b"
            flush $sock
            flush $log
        } else {
            # Unrecognized command
            # if it's just blank line then skipt it - else report it
            if {[string length $line] > 0 } {
                puts "Unknown command:$line"
                puts $sock "Unknown command: $line"
                puts $log "$sock: Unknown command: $line"
            }
            puts $sock ":DONE"
            puts $log "$sock: DONE"
            flush $sock
        }

    }

}

##################################################################
# Clean up and close the socket
##################################################################
proc CloseOut { sock } {
    global socklist
    global sandbox
    global sbname
    global sb_dir
    global git_sh
    global backing
    global log

    if {![eof $sock]} { flush $sock }

    puts $log "$sock [clock format [clock seconds]]: Close $socklist(addr,$sock)- "
    flush $log
    close $sock
    puts "[clock format [clock seconds]]: Close $socklist(addr,$sock)- "
    unset socklist(addr,$sock)
    if {[info exists git_sh($sock)] } {
        # Comment out next line to avoid deleting the /tmp/hwp/ sandbox
        eval {exec} "rm -rf $sb_dir/$sbname($sock)"
        unset git_sh($sock)
        #unset sandbox($sbname($sock))
    }

    if {[info exists sbname($sock)]} { unset sbname($sock) }
    if {[info exists backint($sock)]} { unset backing($sock) }

}

##################################################################
# Sets up the sandbox with the required code from git
##################################################################
proc ExtractSandbox { sock git_sh} {
    global sandbox
    global running
    global sbname
    global sb_dir
    global driver
    global log

    ############################################################
    # Create GIT repository and extract input driver
    # Open a separate pipe which does the extraction and 
    # compiling
    ############################################################
    puts $git_sh "cd $sb_dir/$sbname($sock)"
    puts $git_sh {git init}
    puts $git_sh {git remote add gerrit ssh://gfw160.austin.ibm.com:29418/hostboot}
    puts $git_sh {unlog}
    puts $git_sh {git fetch gerrit --tags}

    if {[string compare $driver "master"] == 0} {
        puts $log "$sock: Using master branch"
        puts $git_sh "git checkout -b master gerrit/master"
    } else {
        puts $log "$sock: Using $driver branch"
        puts $git_sh "git checkout -b $sbname($sock) $driver"
    }
                
    ##################################################
    # tell the workon shell to terminate
    ##################################################
    puts $git_sh {echo :DONE}
    flush $git_sh

    ############################################################
    ## if the git_sh is not done by 180 sec, it probably crashed
    ## keep a list of running sandboxes
    ## hopefully processes timeout in the same order they were started
    ## Kick off an event that waits 10 sec then executes
    ############################################################

    lappend running $sbname($sock)
    set timoutid [after 10000 {
        set sandbox([lindex $running 0]) crashed
        lreplace $running 0 0
    } ]


    ############################################################
    ## This thread now waits until an event changes sandbox($sbname)
    ##   either the simulator exits or times out
    ############################################################

    vwait sandbox($sbname($sock))

    ############################################################
    # If the git_sh workon crashed then close the workon shell 
    # else cancel the timout event
    ############################################################
    if { [string compare $sandbox($sbname($sock)) "crashed"] == 0 } {
        if { [catch {close $git_sh} res]} {
            puts $sock "Failed: $res\n"
            puts $log "$sock: Failed: $res\n"
        }
        set sandbox($sbname($sock)) idle
    } else {
        after cancel $timoutid
    }
    flush $sock
    flush $log

    ## just a flag to indicate sandbox is being used
    set sandbox($sbname($sock)) running
    puts $sock ":DONE"
    puts $log "$sock: DONE"
    flush $sock
}


##################################################################
# Sets up the sandbox for the ifcompiler & sends commands
# sets up an event to collect the simulation results
# closes and deletes the sandbox
##################################################################
proc SendSandbox { sock git_sh} {
    global sandbox
    global running
    global sbname
    global missing_spies
    global log

    # set missing_spies($sock) {}

##################################################################
# Start Compile
##################################################################

    puts $git_sh "source env.bash; make -j4" 

##################################################################
# tell the workon shell to terminate
##################################################################

    puts $git_sh {echo :DONE}
    flush $git_sh

##################################################################
## if the git_sh is not done by 180 sec, it probably crashed
## keep a list of running sandboxes
## hopefully processes timeout in the same order they were started
## Kick off an event that waits 180 sec then executes
##################################################################

    lappend running $sbname($sock)
    set timoutid [after 180000 {
       set sandbox([lindex $running 0]) crashed
       lreplace $running 0 0

    } ]


##################################################################
## This thread now waits until an event changes sandbox($sbname)
##   either the simulator exits or timesout
##################################################################

    vwait sandbox($sbname($sock))

##################################################################
# If the git_sh workon crashed then close the workon shell else cancel the 
# timout event
##################################################################

    if { [string compare $sandbox($sbname($sock)) "crashed"] == 0 } {
	    if { [catch {close $git_sh} res]} {
	        puts $sock "Fail: $res\n"
            puts $log "$sock: Fail: $res\n"
	    }
        set sandbox($sbname($sock)) idle
    } else {
        after cancel $timoutid
    }

    flush $sock
    flush $log
}


##################################################################
# This is a list of regular expressions.  Any line sent to stdout during
# mk processing that matches one of these expressions will be sent to the 
# client.  Note: Everything from stderr gets returned
##################################################################

set explist [list  {ERROR:.*} {^IfScrub..E>.*} {^Parse Error.*} ]

##################################################################
## This event catches the output of the sandbox when the pipe become readable
## and sends it back to the client.
## The git_sh pipe is closed when the full result has been processed
##################################################################

proc IfResult { git_sh sock sbname_sock } {
    global sandbox
    global explist
    global log

    if { [eof $git_sh] || [catch {gets $git_sh line}] } {
        puts $sock "compile unexpectedly terminated. sandbox $sbname_sock"
        puts $log "$sock: compile unexpectedly terminated. sandbox $sbname_sock"

        if { [catch {close $git_sh} res] } {
            puts $sock "Error is $res\n"
            puts $log "$sock: Error is $res\n"
	    }
        set sandbox($sbname_sock) "idle"
    } else {

        # Uncomment to send back all compile output
        #puts $sock "$sock $line"
        #puts $log "$sock: $line"

        if { [string compare $line ":DONE"] == 0 } {
	        if { [catch {close $git_sh} res]} {
                #res has the stderr
                # Need to weed out the junk
                set rlines [split $res "\n"]
                foreach rline $rlines {
                    # weed out the errors from mk
                    if {[regexp {.*error.*} $rline ->] } {
                        puts $sock "$rline - ERROR"
                        puts $log "$sock: $rline"
                    }
                }
	        }

            puts $sock "Exit Sandbox"
            puts $log "$sock: Exit Sandbox"
            set sandbox($sbname_sock) "idle"

	    } else {
            foreach exp $explist {
               if {[regexp $exp $line a]} {
                   puts $sock $line
                   puts $log "$sock: $line"
               }
            }
        }
    }
}


##################################################################
# send the *.if and *.dat files from the compile back to the client
##################################################################
proc SendObjFiles { sock obj_dir } {

    global log

    set hbi_files {}

    # Send the .bin files
    if {[catch {set hbi_files [glob -dir $obj_dir *.bin]} res]} {
        puts $sock "ERROR: No *.bin files found in $obj_dir"
        puts $log "$sock: ERROR: No *.bin files found in $obj_dir"
    } else {
        SendFiles $sock $hbi_files
    }

    # Now send the .syms files
    if {[catch {set hbi_files [glob -dir $obj_dir *.syms]} res]} {
        puts $sock "ERROR: No *.syms files found in $obj_dir"
        puts $log "$sock: ERROR: No *.syms files found in $obj_dir"
    } else {
        SendFiles $sock $hbi_files
    }

    # Now send the hbotStringFile
    if {[catch {set hbi_files [glob -dir $obj_dir hbotStringFile]} res]} {
        puts $sock "ERROR: No hbotStringFile files found in $obj_dir"
        puts $log "$sock: ERROR: No hbotStringFile files found in $obj_dir"
    } else {
        SendFiles $sock $hbi_files
    }

    flush $sock
    flush $log

}


##################################################################
# Send a file to the client
##################################################################
proc SendFiles { sock files } {
    global log

    foreach f $files {
        set size [file size $f]
        puts $sock ":OBJ_FILE [file tail $f] $size"
        puts $log "$sock: :OBJ_FILE [file tail $f] $size"
        fconfigure $sock -translation binary
        set fp [open $f r]
        fconfigure $fp -translation binary
        fcopy $fp $sock -size $size
        close $fp
        fconfigure $sock -translation auto
    }
    flush $log
}



##################################################################
# main
##################################################################
set forever 1
set logfile {/tmp/prcd_server.log}
set log {}


# Where are we running?
foreach {host site c d} [split [exec hostname] .]  break
if {[string compare $host {gfw160}] == 0} {
    set sb_dir {/tmp/hwp/}
    eval {exec} "mkdir -p $sb_dir"
} else {
    puts "Invalid Location to run server!"
    exit -1
}

# array to keep track of ode sandboxes and thier state
array set sandbox {

    sb00000000 idle

}

array set backing {}

puts "Logfile: $logfile"


if { [file exists $logfile] } {
    set log [open "$logfile" a]
} else {
    set log [open "$logfile" w 0666]
}


puts "Logfile: $logfile $log"
exec chmod 666 $logfile

puts "[clock format [clock seconds]]: HWP compiler Server is starting"
puts $log "[clock format [clock seconds]]: HWP compiler Server is starting"
flush $log

set socklist(main) [socket -server Accept 7779]

# By catching errors from vwait- we can ignore them
catch {vwait forever}
