# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/simics/ipmi_bt_responder.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2014,2021
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
#####################################################################33
#
# Provide behavior for the BMC IPMI interface.
#  This code simulates the BMC firmware. The registers used for the
# bulk transfer commands work with this program to create response data
# as though the BMC firmware were operating.
#


#######################################################################
# To Add responses:
#  1) find the net function to respond to and its sub function in
#     handle_ipmi_msg
#      a) if not present then create handle_ipmi_XXX
#  2) Add if/else leg for command
#  3) Send response(s) with
#         resp_buf
#         msg.bld_response(resp_buf)
#         bmc_rsp_q.append(msg)
#

#######################################################################
# To send SMS:
#  1) on Simics commandline:
#    @ipmi_bt_responder_send_sms
#       ("fpga0.ipmi_bmc_device", 0x18, 0xdf, (0xde, 0xad, 0xbe, 0xef))
#     where first param is BMC device name, next is netfun, then command,
#        then data
#

# The model calling into this python is the end-device-ipmi-bmc.dml
# The model call to this python under these circumstances
#   1) any BIT within BT_CTRL is written    calls to ipmi_bt_responder_ctl
#   2) registers BT_CTRL, BT_INTMASK or RW Buffer are written, calls
#      to ipmi_bt_responder_reg
#
#   The end-device-ipmi-bmc.dml model maintains the buffer offset for
#   reading and writing.  The end-device-ipmi-bmc.dml model monitors
#   the H_BUSY bit. Then this changes from set to cleared it is known
#   the Host completed reading and buffer data. At that time the offset
#   into the buffer is set to zero, allowing the next write operation
#   to propley load the buffer data.
#
#   The end-device-ipmi-bmc.dml model monitors the interrupt bit
#   BMC_HWRST to reset the BMC registers
#
#
#####################################################################33



import cli
import simics
import pyobj

from configuration import *
from collections import deque

bt_debug = 1
bmc_rsp_q = deque([])
bmc_sms_q = deque([])
num_reads_for_processing = 5
cur_access_count = 0
processing_msg = 0
last_seq = 0
g_sel_time = []

##################################################################
#  Entry point for all IPMI message handling
#########
def handle_ipmi_msg(bmc):
    #####################
    # NetFun/LUN definitions
    NETFUN_CHASSIS  = (0x00 << 2)
    NETFUN_BRIDGE   = (0x02 << 2)
    NETFUN_SENSOR   = (0x04 << 2)
    NETFUN_APP      = (0x06 << 2)
    NETFUN_FIRMWARE = (0x08 << 2)
    NETFUN_STORAGE  = (0x0a << 2)
    NETFUN_TRANPORT = (0x0c << 2)

    global last_seq

    bt_debug_print(3,"  handle_ipmi_msg")
    msg = ipmiMessage(bmc.h2b_buffer)

    last_seq = msg.getSeq()


    msg.dump("Got MSG")

    ### Now decide how to respond
    ### break this up into a function for each Netfun/LUN
    if(msg.getNetfLun() == NETFUN_APP):
        handle_ipmi_APP(msg)
    elif(msg.getNetfLun() == NETFUN_STORAGE):
        handle_ipmi_STORAGE(msg)
    else:
        bt_debug_print(0,"ERROR> IPMI_RSP unrecognized message")
        bt_debug_print(0,"Cowardly doing nothing")
        msg.dump("UNRECOGNIZED IPMI MESSAGE")

    pass



##################################################################
#  Entry point for APP Net function/LUN
#########
def handle_ipmi_APP(msg):
    global bmc_rsp_q

    #####################
    # Command IDs for NETFUN_APP
    APP_GET_DEVID           = 0x01
    APP_GET_BT_CAP          = 0x36
    APP_GET_DROP_MAGIC      = 0x3e

    bt_debug_print(3,"    handle_ipmi_APP")

    ### Now decide how to respond
    ### Handle each command type inline
    if(msg.getCmd() == APP_GET_DEVID):
        bt_debug_print(2,"      bld response for DEVID")

        ### Send back "fake" dev id
        ### RC=0, FW level 1.0, IPMI 2.0, everything else 0s
        resp_buf = [0x0, 0x0, 0x0, 0x81, 0x0, 0x02, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0]
        msg.bld_response(resp_buf)
        msg.dump("DEVID RESP")
        bmc_rsp_q.append(msg)

    elif(msg.getCmd() == APP_GET_BT_CAP):
        bt_debug_print(2,"      bld response for BT Capabilities")

        ### Send back "fake" dev id
        ### RC=0, # req, Input size, resp size, resp time(sec), retry
        resp_buf = [0x0, 0x2, 0x40, 0x40, 0x1, 0x01]
        msg.bld_response(resp_buf)
        msg.dump("BTCAP RESP")
        bmc_rsp_q.append(msg)

    elif(msg.getCmd() == APP_GET_DROP_MAGIC):
        bt_debug_print(1,"MAGIC MSG -- drop this message")

        ### Don't send back anything
    else:
        bt_debug_print(0,"ERROR> IPMI_APP invalid CMD")
        bt_debug_print(0,"ERROR> Cowardly doing nothing")
        msg.dump("UNRECOGNIZED APP CMD")

    pass


##################################################################
#  Entry point for STORAGE Net function/LUN
#########
def handle_ipmi_STORAGE(msg):
    global bmc_rsp_q
    global g_sel_time

    #####################
    # Command IDs for NETFUN_APP
    APP_SET_SEL_TIME        = 0x49

    bt_debug_print(3,"    handle_ipmi_STORAGE")

    ### Now decide how to respond
    ### Handle each command type inline
    if(msg.getCmd() == APP_SET_SEL_TIME):
        bt_debug_print(2,"      bld response for set SEL Time")

        ### Send back good status and save away "time"
        g_sel_time = msg.getData()
        resp_buf = [0x0]
        msg.bld_response(resp_buf)
        msg.dump("SET_SEL RESP")
        bmc_rsp_q.append(msg)

    else:
        bt_debug_print(0,"ERROR> IPMI_STORAGE invalid CMD")
        bt_debug_print(0,"ERROR> Cowardly doing nothing")
        msg.dump("UNRECOGNIZED STORAGE CMD")

    pass



##############################################################################
##############################################################################
##############################################################################
##############################################################################
##############################################################################
##############################################################################
#                  END IPMI MESSAGE HANDLING FUNCTIONS               #########
##############################################################################
##############################################################################
##############################################################################
##############################################################################
##############################################################################
##############################################################################


def bt_debug_print(level, str, parms=None):
    global bt_debug

    if (bt_debug >= level):
        if parms:
            print(str % parms)
        else:
            print(str)

class ipmiMessage:
    #Instance constructor
    def __init__(self, buffer=[]):
      if(len(buffer)):
        #The IPMI protocol says:
        #   byte 0 = len, byte 1 = NetFun/LUN, byte 2 = Seq, byte 4 = cmd
        #   byte 5:N = Data.  Min size is 3
        if(buffer[0] < 3):
            bt_debug_print(0, "ERROR, malformed IPMI msg .Len %d", self.len)
            pass

        self.len = buffer[0] - 3
        self.netf_lun = buffer[1]
        self.seq = buffer[2]
        self.cmd = buffer[3]
        self.data = buffer[4:(buffer[0]+1)]
      else:
          self.len = 0
          self.netf_lun = 0
          self.seq = 0
          self.cmd = 0
          self.data = []

    def getIPMIBuf(self, sendbuf):
        sendbuf[0] = self.len
        sendbuf[1] = self.netf_lun
        sendbuf[2] = self.seq
        sendbuf[3] = self.cmd
        for x in range(4, 4+len(self.data)):
            sendbuf[x] = self.data[x-4]
        for x in range(4+len(self.data), len(sendbuf)):
            sendbuf[x] = 0xFF


    def getData(self):
         return self.data

    def setDataBuf(self, data):
        self.data = data
        self.len = 3+ len(data)

    def getDataSize(self):
         return self.len

    def getNetfLun(self):
         return self.netf_lun

    def setNetfLun(self, netf_lun):
         self.netf_lun = netf_lun

    def createNetfResp(self):
         self.netf_lun = self.netf_lun + 0x04

    def getCmd(self):
         return self.cmd

    def setCmd(self, cmd):
         self.cmd = cmd

    def getSeq(self):
         return self.seq

    def setSeq(self, i_seq):
         self.seq = i_seq

    def bld_response(self, resp_buf):
        #use existing message and tweak for the response
        self.createNetfResp()
        self.setDataBuf(resp_buf)

    def dump(self, header="Debug Dump", lvl=1):
       global bt_debug
       if (bt_debug >= lvl):
         print("======================================")
         print("= %s " % header)
         print("=================")
         print("Net: %X cmd: %X seq: %X" % (self.netf_lun, self.cmd, self.seq))
         print("Data: ")
         print(" ".join(hex(n) for n in self.data))
         print("======================================")
         print(" ")






##################################################################
#  send_messages
#########
def send_messages(bmc):
    CTL_B2H_ATN         = 0x08
    CTL_EVT_ATN         = 0x10
    CTL_H_BUSY          = 0x40
    BUSY_MASK = CTL_B2H_ATN | CTL_EVT_ATN | CTL_H_BUSY

    global processing_msg
    global bmc_sms_q
    global bmc_rsp_q
    global debug
    interrupt_bit = 0x0
    msg = None

    bt_debug_print(4,">>send_messages")
    # Clear B_BUSY as we have a message to respond to
    ctl_reg = bmc.BT_CTRL_base
    ctl_reg = ctl_reg & 0x7F  #clear B-BUSY
    bmc.BT_CTRL_base = ctl_reg


    #send message if we can (H_BUSY, B2H, EVT all have to be to clear)
    if(not (bmc.BT_CTRL_base & BUSY_MASK)):
         bt_debug_print(4,"  H_BUSY clear, OK to send")

         #Always perfer SMS
         if(len(bmc_sms_q) >0):
             msg = bmc_sms_q.popleft()
             interrupt_bit = CTL_EVT_ATN   # SMS
         elif(len(bmc_rsp_q) >0):
             msg = bmc_rsp_q.popleft()
             interrupt_bit = CTL_B2H_ATN   # Response

         #Have something to send
         if msg:
             msg.dump("BMC2Host message", 4)
             sendbuf = bmc.b2h_buffer
             msg.getIPMIBuf(sendbuf)
             bmc.b2h_buffer = sendbuf
             bt_debug_print(4,"about to set CTRL")
             bmc.BT_CTRL_base = bmc.BT_CTRL_base | interrupt_bit

    # If both SMS and rsp are empty we are not processing a message
    if((len(bmc_rsp_q) == 0) and (len(bmc_sms_q) == 0)):
        processing_msg = 0

    bt_debug_print(4,"<<send_messages")
    pass


################################################################################
##########################################
# Register update handler
# For the register passed in, access and update any BT registers and buffers
# to simulate the BT commands
#  Called on a per register basis
################################################################################
def bt_handle_reg(bmc, reg_name, RW):
    CTL_H2B_ATN         = 0x04

    global processing_msg
    global cur_access_count
    global num_reads_for_processing

    cur_access_count = cur_access_count +1
    bt_debug_print(9,"cnt[%d] proc[%d]", (cur_access_count, processing_msg))

    #Always attempt to send response/sms messages
    #function determines correct state
    #delay X number of reads/writes by the host
    #to simulate time
    if((processing_msg == 1) and (cur_access_count > 1) and ((bmc.BT_CTRL_base & CTL_H2B_ATN))):
          ctl_reg = bmc.BT_CTRL_base
          ctl_reg = ctl_reg & 0xFB  #clear H2B
          bmc.BT_CTRL_base = ctl_reg

    bt_debug_print(9,"prior to send messages check")
    if((processing_msg == 1) and (cur_access_count > num_reads_for_processing)):
        send_messages(bmc)


    if RW == "READ":
        # NOP
        ##bt_debug_print(2,"Process register %s for READ,  NOP",(reg_name))
        return
    write_buff = bmc.BT_RW_BUFF_base  # in case we need to modify
    if (reg_name == "BT_RW_BUFF"):
        bt_debug_print(4,"Process register %s",(reg_name))
    elif (reg_name == "BT_CTRL"):
        bt_debug_print(4,"Process register %s",(reg_name))
    elif (reg_name == "BT_INTMASK"):
        bt_debug_print(4,"Process register %s",(reg_name))
        reg0 = bmc.BT_CTRL_base
        bt_debug_print(4,"at present  --- %X",(reg0))
        # if REG0 equals 55, buffer set to AA
        # Imaginary behavior as an example
        if reg0 == 0x37:
            write_buff = 0xaa
    else:
        bt_debug_print(0,"Unhandled register named %s", (reg_name))
    bmc.BT_RW_BUFF_base = write_buff
    pass



##########################################
# Register update handler based on control bits
# For the attention name passed in, access and update any BT
# registers and buffers to simulate the BT commands
#  Called on a per register BIT
################################################################################
def bt_handle_ctl(bmc, bit_name, RW):
    #####################
    # CTL BIT Definitions
    #######
    CTL_CLR_WR_PTR      = 0x01
    CTL_CLR_RD_PTR      = 0x02
    CTL_H2B_ATN         = 0x04
    CTL_OEM0            = 0x20
    CTL_B_BUSY          = 0x80

    global processing_msg
    global cur_access_count
    global num_reads_for_processing


    bt_debug_print(4,"Process BIT %s  RW %s",(bit_name, RW))
    if RW == "READ":
        # NOP
        bt_debug_print(4,"Process BIT %s for READ,  NOP",(bit_name))
        return

    if(bit_name == "CLR_WR_PTR"):
           #handled by simics model proper
           bt_debug_print(9,"CRL_WR_PTR asserted")
    elif(bit_name == "CLR_RD_PTR"):
           #handled by simics model proper
           bt_debug_print(4,"CLR_RD_PTR asserted")
    elif (bit_name == "H2B_ATN"):
        bt_debug_print(1,"H2B --> Process process message")
        # Since this happens in "Simics" time it is instantaneous
        # however base model sets B_BUSY for us, so need to clear
        # when ready
        handle_ipmi_msg(bmc)

        #the model proper sets B_BUSY immediately

        cur_access_count = 0
        processing_msg = 1

    elif(bit_name == "B2H_ATN"):
           bt_debug_print(4,"Process BIT %s for WRITE",(bit_name))
    elif(bit_name == "SMS_ATN"):
           bt_debug_print(4,"Process BIT %s for WRITE",(bit_name))
    elif(bit_name == "OEM0"):
           bt_debug_print(4,"Process BIT %s for WRITE",(bit_name))
    elif(bit_name == "H_BUSY"):
           bt_debug_print(4,"Process BIT %s for WRITE",(bit_name))
    elif(bit_name == "B_BUSY"):
           bt_debug_print(4,"Process BIT %s for WRITE",(bit_name))
    elif(bit_name == "B2H_ATN"):
           bt_debug_print(4,"Process BIT %s for WRITE",(bit_name))
    else:
        bt_debug_print(2,"Unhandled BIT named %s", (bit_name))

    pass

##########################################
# Main entry point.
# Parms are the conf_t pointer to the BMC models
# and the name of the register and whether being R/W
#
#  NOTE: Assumed called from the model registers after_write
#       after_read method
#
#######
def ipmi_bt_responder_reg(bmc_name, reg_name, RW):

    bmc_obj = SIM_get_object(bmc_name)
    bt_handle_reg(bmc_obj, reg_name, RW)


    pass



def ipmi_bt_responder_ctl(bmc_name, bit_name, RW):

    bmc_obj = SIM_get_object(bmc_name)
    bt_handle_ctl(bmc_obj, bit_name, RW)
    pass

def ipmi_bt_responder_send_sms(bmc_name, i_netfunc, i_cmd, i_buf):

    global last_seq
    global bmc_sms_q
    global processing_msg
    bmc_obj = SIM_get_object(bmc_name)

    msg = ipmiMessage()
    msg.setNetfLun(i_netfunc)
    last_seq = (last_seq + 1) % 256
    msg.setSeq(last_seq)
    msg.setCmd(i_cmd)
    msg.setDataBuf(i_buf)

    msg.dump("Sending SMS Event/Command")
    bmc_sms_q.append(msg)
    processing_msg = 1
    pass
