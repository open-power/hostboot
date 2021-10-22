# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/simics/eecache-gen.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2020,2021
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
###############################
## Generate EECACHE partition
##
## Hostboot needs a way to grab image objects to create eecache for them
## to read contents directly out of a file rather than going to the
## device(which is very slow).  The way eecache is setup is to have a header
## and all the VPD images they care about (they may not need all the images,
## but they will pick and choose using the commands simics provides
## .. get-seeprom and get-dimm-seeprom) and put them in a predefined structure
## with information on its offset (mainly VPD, like MVPD for proc 1 on DCM0 or
## MVPD for proc 1 in DCM1 on rainier)
##
###############################
import os
import cli
import struct
import sys
import re

###########################################################################
# version 1 header record
###########################################################################
def write_eecache_record_v1(f, huid, port, engine, addr, mux, size, offset, valid):
    f.write(struct.pack('>i', huid));
    f.write(struct.pack('>B', port));
    f.write(struct.pack('>B', engine));
    f.write(struct.pack('>B', addr));
    f.write(struct.pack('>B', mux));
    f.write(struct.pack('>i', size));
    f.write(struct.pack('>I', offset));
    f.write(struct.pack('>B', valid));
    return

###########################################################################
# version 2 header records
###########################################################################
def write_spi_eecache_record(f, huid, engine, offset_KB, size, offset, valid):
    f.write(struct.pack('>B', 0x02)); # 0x02 = SPI access
    f.write(struct.pack('>i', huid));
    f.write(struct.pack('>B', engine));
    f.write(struct.pack('>H', offset_KB));
    f.write(struct.pack('>B', 0x00));
    f.write(struct.pack('>i', size));
    f.write(struct.pack('>I', offset));
    f.write(struct.pack('>B', valid));
    return

def write_i2c_eecache_record(f, huid, port, engine, devAddr, mux, size, offset, valid):
    f.write(struct.pack('>B', 0x01)); # 0x01 = I2C access
    f.write(struct.pack('>i', huid));
    f.write(struct.pack('>B', port));
    f.write(struct.pack('>B', engine));
    f.write(struct.pack('>B', devAddr));
    f.write(struct.pack('>B', mux));
    f.write(struct.pack('>i', size));
    f.write(struct.pack('>I', offset));
    f.write(struct.pack('>B', valid));
    return

# Write an empty eecache header record to opened filehandle f
# This has been verified to work with EECACHE files that use version 2 header records
def write_empty_eecache_record(f):
    '''
    In the HB code, internal_offset of an eepromRecordHeader struct is set to
    UNSET_INTERNAL_OFFSET_VALUE = 0xFFFFFFFF to mark that an entry does not have corresponding
    cache data yet.
    See src/include/usr/eeprom/eeprom_const.H for eepromRecordHeader struct and internal_offset
    location in struct.
    To create an empty entry, we'll set all of the bytes of the struct to zero, except for the
    internal_offset value.
    '''
    writeEmptyBytes(f, 13)
    f.write(struct.pack('>I', 0xFFFFFFFF))
    writeEmptyBytes(f, 1)

# Write n padding bytes to opened filehandle f
def writeEmptyBytes(f, n):
    # Write to opened filehandle
    for i in range(n):
        # Single byte write
        # f.write(struct.pack('>B', 0x00))
        f.write(struct.pack('x'))

# Append n empty kilobytes to file with name file_name
def writeEmptyKilobytes(file_name, n):
    n *= 1024 # KB to bytes
    with open(file_name, 'ab') as f:
        writeEmptyBytes(f, n)

###########################################################################
##
## hb_eecache_setup - fills in the eecache file with header and vpd content
#
# See eeprom_const.H for header information
# Version 1 only supports i2c
# Version 2 supports i2c and spi access (adds another byte to header size)
#
###########################################################################
def hb_eecache_setup(file_name, version, verbose):

    # create the header records
    with open(file_name, 'wb') as f:
        if version == 1:
            # version, written in 1 byte. only supports version 1
            f.write(struct.pack('>B', 1));
            # end of cache, written in 4 bytes
            f.write(struct.pack('>i', 0x24357));

            # eepromRecordHeader for MVPD (proc 0)
            write_eecache_record_v1(f, 0x50000, 0, 1, 0xA0, 0xFF, 64, 0x357, 0x80);
            # for DIMM port 0
            write_eecache_record_v1(f, 0x50000, 9, 3, 0xA0, 0xFF, 4, 0x10357, 0x80);
            # for DIMM port 1
            write_eecache_record_v1(f, 0x50000, 8, 3, 0xA0, 0xFF, 4, 0x11357, 0x80);

            # eepromRecordHeader for MVPD (proc 1)
            write_eecache_record_v1(f, 0x50001, 0, 1, 0xA0, 0xFF, 64, 0x12357, 0x80);
            # for DIMM port 0
            write_eecache_record_v1(f, 0x50001, 9, 3, 0xA0, 0xFF, 4,  0x22357, 0x80);
            # for DIMM port 1
            write_eecache_record_v1(f, 0x50001, 8, 3, 0xA0, 0xFF, 4,  0x23357, 0x80);

            # Note: The max eeprom counts come from src/include/usr/eeprom/eeprom_const.H
            # For version 1, it is currently a max count of 50
            # Given 6 records already filled out above, 44 more record headers
            # should be filled out as empty
            for _ in range(44):
                write_eecache_record_v1(f, 0, 0, 0, 0, 0, 0, 0xFFFFFFFF, 0);

        elif version == 2:
            # version, written in 1 byte. Supports version 2, i.e. I2C and SPI entries
            f.write(struct.pack('>B', 2));
            # end of cache, written in 4 bytes
            # it's offset (0x1270D bytes) + size (180 KB) of the last entry
            f.write(struct.pack('>i', 0x3F70D));
            # eepromRecordHeader for MVPD
            # valid arg.: 0xC0 means valid and master record
            write_spi_eecache_record(f, 0x50000, 0x02, 0x00C0, 64, 0x70D, 0xC0);
            # for DIMM port 0
            write_i2c_eecache_record(f, 0x50000, 0, 3, 0xA0, 0xFF, 4, 0x1070D, 0xC0);
            # for DIMM port 1
            write_i2c_eecache_record(f, 0x50000, 1, 3, 0xA0, 0xFF, 4, 0x1170D, 0xC0);
            # for WOF
            # valid arg.: 0x80 means is valid but not master record
            write_spi_eecache_record(f, 0x50000, 0x03, 0x0100, 180, 0x1270D, 0x80);

            # Note: The max eeprom count comes from src/include/usr/eeprom/eeprom_const.H
            # For version 2, it is currently a max count of 100
            # Given 4 records already filled out above, 96 more record headers
            # should be filled out as empty
            for _ in range(96):
                write_empty_eecache_record(f)
        else:
            # Non-supported version argument
            sys.exit("Error: Non-supported Version Value passed into hb_eecache_setup(...)")

    ##################################### Populate Proc 0 Records ####################################
    # now add 64K mvpd record for processor 0 (0x50000)
    ret = cli.run_command("get-seeprom 0 0 2") # reading MVPD

    if ret != None:
        # simics object for the image
        image = simics.SIM_get_object(ret)
        # string of bytes from simics interface
        read_buf = image.iface.image.get(0x30000, 0x10000) # interface takes start and length

        # Probably this file will be deleted once we write to BMC
        with open(file_name, 'ab') as f:
            f.write(read_buf)
    else:
        # 64 kb to write coming from header entry
        # write_spi_eecache_record(f, 0x50000, 0x03, 0x00C0, 64, ...)
        writeEmptyKilobytes(file_name, 64)

    # now add 4K DDIMM VPD port 0
    ret = cli.run_command("get-dimm-seeprom 0 0 3 0") # reading DDIMM VPD port 0
    if ret != None:
        # simics object for the image
        image = simics.SIM_get_object(ret)
        # string of bytes from simics interface
        read_buf = image.iface.image.get(0, image.size) # interface takes start and length

        # Probably this file will be deleted once we write to BMC
        with open(file_name, 'ab') as f:
            f.write(read_buf)
    else:
        # 4 kb to write coming from header entry
        # write_i2c_eecache_record(f, 0x50000, 0, 3, 0xA0, 0xFF, 4, ...)
        writeEmptyKilobytes(file_name, 4)

    # now add 4K DDIMM VPD port 1
    ret = cli.run_command("get-dimm-seeprom 0 0 3 1") # reading DDIMM VPD port 1
    if ret != None:
        # simics object for the image
        image = simics.SIM_get_object(ret)
        #string of bytes from simics interface
        read_buf = image.iface.image.get(0, image.size) # interface takes start and length

        # Probably this file will be deleted once we write to BMC
        with open(file_name, 'ab') as f:
            f.write(read_buf)
    else:
        # 4 kb to write coming from header entry
        # write_i2c_eecache_record(f, 0x50000, 1, 3, 0xA0, 0xFF, 4, ...)
        writeEmptyKilobytes(file_name, 4)

    # add 160K WOF record for processor 0
    ret = cli.run_command("get-seeprom 0 0 3") # get ref to seeprom that has WOF for proc 0
    if ret != None:
        image = simics.SIM_get_object(ret)
        # WOF+ECC data is at offset 0x40000 bytes in SEEPROM, and has a size of 0x2D000 bytes
        read_buf = image.iface.image.get(0x40000, 0x2D000)
        with open(file_name, 'ab') as f:
            f.write(read_buf)
    else:
        # 160 kb to write coming from header entry
        # write_spi_eecache_record(f, 0x50000, 0x03, 0x0100, 160, ...);
        writeEmptyKilobytes(file_name, 160)

    ##################################### Populate Proc 1 Records ####################################
    # now add 64K mvpd record for processor 1 (0x50001)
    ret = cli.run_command("get-seeprom 0 1 2") # reading MVPD

    if ret != None:
        # simics object for the image
        image = simics.SIM_get_object(ret)
        # string of bytes from simics interface
        read_buf = image.iface.image.get(0x30000, 0x10000) # interface takes start and length

        # Probably this file will be deleted once we write to BMC
        with open(file_name, 'ab') as f:
            f.write(read_buf)

    # now add 4K DDIMM VPD port 0
    ret = cli.run_command("get-dimm-seeprom 0 1 3 2") # reading DDIMM VPD port 0
    if ret != None:
        # simics object for the image
        image = simics.SIM_get_object(ret)
        # string of bytes from simics interface
        read_buf = image.iface.image.get(0, image.size) # interface takes start and length

        # Probably this file will be deleted once we write to BMC
        with open(file_name, 'ab') as f:
            f.write(read_buf)

    # now add 4K DDIMM VPD port 1
    ret = cli.run_command("get-dimm-seeprom 0 1 3 3") # reading DDIMM VPD port 1
    if ret != None:
        # simics object for the image
        image = simics.SIM_get_object(ret)
        #string of bytes from simics interface
        read_buf = image.iface.image.get(0, image.size) # interface takes start and length

        # Probably this file will be deleted once we write to BMC
        with open(file_name, 'ab') as f:
            f.write(read_buf)

    return None


###########################################################################
# Find what the local file name should be for generated EECACHE
# bmc_files is a parameter passed into runsim
###########################################################################
def find_eecache_file( bmc_files_str ):
    x = re.search('/host/(.+):/usr/local/share/hostfw/running/81e00679.lid', bmc_files_str)
    if x != None:
      #print(x.group(1))
      return x.group(1)
    return None

##########################################################################
# Resolve the relative simics path to absolute path
# This is to support copying EECACHE to the BMC
# @param bmc_files_str - simics bmc_files string
# @param absolute_simics_eecache - result of lookup-file on eecache part
# @return Altered version of bmc_files_string where relative eecache is
#         replaced with absolute_simics_eecache
##########################################################################
def resolve_eecache_path( bmc_files_str, absolute_simics_eecache ):
    #print "resolve_eecache_path("+bmc_files_str+ ", "+absolute_simics_eecache+")"
    x = re.sub(r'([^,]+):/usr/local/share/hostfw/running/81e00679.lid', absolute_simics_eecache+":/usr/local/share/hostfw/running/81e00679.lid", bmc_files_str)
    if x != None:
      return x
    return None

###########################################################################
# Generate eecache (MAIN FUNCTION)
# @param eecache_file = local file to create for EECACHE
# @param version = 1 or 2
#                - 1: i2c only
#                - 2: i2c + spi
###########################################################################
def eecache_gen(eecache_file, version):
    if eecache_file != None:
        # create eecache
        #print "Create eecache: hb_eecache_setup(", eecache_file, ", ", version, ",0)"
        hb_eecache_setup(eecache_file, version, 0)
    return None


###########################################################################
# Get PG records for EQ chiplets from MVPD file
# @param vpd_path - Path to file containing the meas/mvpd/ks SEEPROM data
# @return list    - 8 EQ PG records
###########################################################################
def get_eq_pg_records(vpd_path):
    with open(vpd_path, 'rb') as vpd_file:
        os.unlink(vpd_path)

        vpd_bytes = vpd_file.read()
        pg_key = 'CP00VD\x0201PG'
        pg_idx = vpd_bytes.find(pg_key.encode())

        if pg_idx == -1:
            raise Exception('Cannot find PG keyword in file ' + vpd_path)

        # Skip to the PG section contents
        pg_idx += 13

        # The 8 EQ records start at byte 96 and are 3 bytes wide (see
        # PG VPD spreadsheet)
        pg_idx += 96

        return [ struct.unpack(">I", b'\x00' + vpd_bytes[pg_idx+offset:pg_idx+offset+3])[0]
                 for offset in range(0, 8*3, 3) ]

################################################################
# Adds 0xFF to end of io_filename until it at least i_min_size
# bytes long. If the file is already larger than i_min_size then
# no extra bytes are added.
################################################################
def setMinFileSize(io_filename, i_min_size):
    pad_size = i_min_size - os.stat( io_filename ).st_size;
    if pad_size > 0:
        with open( io_filename, 'ab') as p:
            p.write(bytes([255]) * pad_size)