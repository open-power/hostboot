# *** traceHB.py
#
# Script to extract and display formatted trace in simics

# *** Usage
#
# On simics console:
# 1. Load file
# simics> run-python-file <gitrepo>/src/build/trace/traceHB.py
# 2. Display global trace buffer
# simics> @traceHB("<gitrepo>/img/hbicore.syms", <path>/trexStringFile")
# 3. Display kernel printk buffer
# simics> @printkHB("<gitrepo>/img/hbicore.syms")
#
# Example:
# run-python-file /gsa/ausgsa/home/c/a/camvanng/HOSTBOOT/src/build/trace/traceHB.py
# @traceHB("/gsa/ausgsa/home/c/a/camvanng/HOSTBOOT/img/hbicore.syms","/gsa/ausgsa/home/c/a/camvanng/HOSTBOOT/obj/modules/example/example.o.hash")
# @printkHB("/gsa/ausgsa/home/c/a/camvanng/HOSTBOOT/img/hbicore.syms")

# *** Change History
#
# 05/10/2011    camvanng    Created

import os,sys
import conf
import configuration
import cli

# Function to dump the global trace buffer
def traceHB(symsFile, trexStringFile):

    print

    #Find location of g_trac_global variable from the image's .syms file
    #i.e. grep g_trac_global <gitrepo>/img/hbicore.syms
    for line in open(symsFile):
        if "g_trac_global" in line:         #if found
            #print line
            x = line.split(",")
            addr = int(x[1],16)             #address of g_trac_global
            #print "addr = 0x%x"%(addr)
            size = int(x[3],16)             #size of g_trac_global
            #print "size = 0x%x"%(size)

            #get address of global trace buffer
            string = "phys_mem.x 0x%x 0x%x"%(addr,size)
            #print string
            result,message = quiet_run_command(string)
            #print message
            lst = message.split()
            #print lst
            addr_str = ""
            for i in range(1,5):
                addr_str += lst[i]
            #print addr_str
            addr_global_trace_buffer = int(addr_str,16)     #address of global trace buffer

            #save global trace buffer to <sandbox>/simics/trace.out
            string = "memory_image_ln0.save trace.out 0x%x 0x1000"%(addr_global_trace_buffer)
            #print string
            result = run_command(string)
            #print result

            #display formatted trace
            string = 'fsp-trace -s %s trace.out'%(trexStringFile)
            #print string
            os.system(string)

            print
            break
    return


# Function to dump the kernel printk buffer
def printkHB(symsFile):

    print

    #Find location of the kernel_printk_buffer variable from the image's .syms file
    #i.e. grep kernel_printk_buffer <gitrepo>/img/hbicore.syms
    for line in open(symsFile):
        if "kernel_printk_buffer" in line:  #if found
            #print line
            x = line.split(",")
            addr = int(x[1],16)             #address of kernel_printk_buffer
            #print "addr = 0x%x"%(addr)
            size = int(x[3],16)             #size of kernel_printk_buffer
            #print "size = 0x%x"%(size)

            #save kernel printk buffer to <sandbox>/simics/printk.out
            string = "memory_image_ln0.save printk.out 0x%x 0x%x"%(addr,size)
            #print string
            result = run_command(string)
            #print result

            #display buffer
            #for line in open("printk.out"):
            #    print line
            #file = open("printk.out")
            #print file.read()
            os.system('cat printk.out')

            break
    return

