#!/usr/bin/env python2
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/dce/preplib.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2020,2022
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

# Usage: preplib.py ELF
#
# This script is an internal part of the Dynamic Code Execution (DCE)
# framework. It links an input ELF file with a Hostboot image and
# produces a binary file which is an ELF prepended with dynamic
# relocations and other metadata. This file is then transferred to a
# running Hostboot instance, which performs the dynamic relocations
# and executes the entrypoint of the ELF.

import os
import re
import sys
import struct
import subprocess

infilename = sys.argv[1]

ROOTPATH = os.environ['PROJECT_ROOT']

debug = 'HB_DCE_PREPLIB_DEBUG' in os.environ

infile = open(infilename, 'rb')
tmpfile = open(infilename + '.tmp', 'w+b')
hbicorefile = open(ROOTPATH + '/img/hbicore.bin', 'rb')
hbicore_extendedfile = open(ROOTPATH + '/img/hbicore_extended.bin', 'rb')
hbsyms = open(ROOTPATH + '/img/hbicore.syms.mangled', 'r').read()

# Copy the input file to the output file, and we'll fix up the output file in-place
tmpfile.write(infile.read())
infile.seek(0)

# Define utility functions

def debugout(s):
    if debug:
        print(s)

def add_cross_prefix(s):
    return os.environ['CROSS_PREFIX'] + s

def toolchain_command(process, *args):
    return subprocess.check_output([add_cross_prefix(process)] + list(args))

libsyms = toolchain_command('readelf', '-s', '-W', infilename)

def grep(needle, haystack):
    return [ line for line in haystack.splitlines() if re.search(needle, line) ]

def column(cols, idx, sep=None):
    return cols.split(sep)[idx]

def get_entrypoint_descriptor_addr():
    # Invoke readelf -h with the ELF as input, and parse the output
    # for the entrypoint descriptor address.
    return int(column(grep('Entry', toolchain_command('readelf', '-h', infilename))[0], -1), 16)

def get_symbol_and_offset_from_expression(symname):
    match = re.search('(.+)\+(.+)', symname)

    if match:
        return match.groups()[0], int(match.groups()[1], 0)

    return symname, 0

# The format of the HB symbol file is
#   Type,DataOffset,FunctionOffset,SymbolLength,SymbolName
def find_hb_fn_symbol_addr(symname, nohalt=False):
    symname, offset = get_symbol_and_offset_from_expression(symname)
    return int(column(grep(',' + symname + '$', hbsyms)[0], 2, ','), 16) + offset

def find_hb_data_symbol_addr(symname, nohalt=False):
    symname, offset = get_symbol_and_offset_from_expression(symname)
    return int(column(grep(',' + symname + '$', hbsyms)[0], 1, ','), 16) + offset

# See readelf documentation for the description of the output of
# readelf -s -W, but for example it looks like this:
#
# Symbol table '.dynsym' contains 29 entries:
#    Num:    Value          Size Type    Bind   Vis      Ndx Name
#      0: 0000000000000000     0 NOTYPE  LOCAL  DEFAULT  UND
#      1: 0000000000000b00     0 SECTION LOCAL  DEFAULT    6
#      2: 0000000000001ab8     0 SECTION LOCAL  DEFAULT   11
#      3: 0000000000000000     0 NOTYPE  GLOBAL DEFAULT  UND strcpy
def find_lib_symbol_addr(symname):
    symname, offset = get_symbol_and_offset_from_expression(symname)

    if 'Singleton' in symname:
        raise Exception('Singletons are always linked to HB[I]')

    entry = grep(' ' + symname + '$', libsyms)[0]
    defined = column(entry, 6)

    if defined != 'UND':
        return int(column(entry, 1), 16) + offset

    raise Exception('Cannot find symbol ' + symname + ' in ' + infilename)

def find_lib_symbol_type(symname):
    return column(grep(' ' + symname + '$', libsyms)[0], 4)

def file_bytes(file, offset, count):
    file.seek(offset)
    return file.read(count)

def lib_bytes(offset, count):
    return file_bytes(infile, offset, count)

def write_output(offset, data):
    tmpfile.seek(offset)
    tmpfile.write(data)

def read_descriptor(file, desc_addr):
    return file_bytes(file, desc_addr, 24)

def get_entry_descriptor():
    desc_addr = get_entrypoint_descriptor_addr()

    debugout('Reading entrypoint descriptor from %x' % (desc_addr,))

    return read_descriptor(infile, desc_addr)

# These constants must match Hostboot's dynamic relocation code
# Search for @DEP_ON_BL_TO_HB_SIZE
RELOC_TYPE_DESCRIPTOR = 1
RELOC_TYPE_ADDR64 = 2

dynamic_relocs = []
def add_dynamic_relocation(relocaddr, offset, reloc_type):
    dynamic_relocs.append((reloc_type, relocaddr, offset))

def hb_image_bytes(offset, numbytes):
    HBI_EXTENDED_OFFSET = 0x40000000

    source_file = hbicorefile

    if offset >= HBI_EXTENDED_OFFSET:
        source_file = hbicore_extendedfile
        offset = offset - HBI_EXTENDED_OFFSET

    return file_bytes(source_file, offset, numbytes)

def perform_descriptor_reloc(relocaddr, desc_addr):
    desc = hb_image_bytes(desc_addr, 24)
    write_output(relocaddr, desc)

def perform_addr64_reloc(relocaddr, word_addr):
    value = struct.pack('>Q', word_addr)
    write_output(relocaddr, value)

def perform_r_ppc64_jmp_slot_reloc(relocaddr, symbol):
    try:
        desc_addr = find_lib_symbol_addr(symbol)
    except Exception as e:
        try:
            desc_addr = find_hb_fn_symbol_addr(symbol)
        except Exception as e:
            print(e)
            print('[E] Undefined symbol: ' + symbol)
            sys.exit(1)

        debugout('[I] Performing relocation for direct function call ' + symbol + ' at ' + hex(relocaddr) + ' to the descriptor at ' + hex(desc_addr))

        perform_descriptor_reloc(relocaddr, desc_addr)
        return

    debugout('[I] Adding dynamic relocation for direct function call '  + symbol + ' at ' + hex(relocaddr) + ' to the descriptor at offset ' + hex(desc_addr))

    add_dynamic_relocation(relocaddr, desc_addr, RELOC_TYPE_DESCRIPTOR)

def perform_r_ppc64_addr64_reloc(relocaddr, symbol):
    try:
        sym_addr = find_lib_symbol_addr(symbol)
    except Exception as e2:
        try:
            sym_addr = find_hb_fn_symbol_addr(symbol)
        except Exception as e:
            print(e)
            print('[E] Undefined symbol: ' + symbol)
            sys.exit(1)

        if sym_addr == 0:
            sym_addr = find_hb_data_symbol_addr(symbol)

        debugout('[I] Performing relocation for 64-bit address reference ' + symbol + ' at ' + hex(relocaddr) + ' to the address ' + hex(sym_addr))

        perform_addr64_reloc(relocaddr, sym_addr)
        return

    debugout('[I] Adding dynamic relocation for 64-bit address reference ' + symbol + ' at ' + hex(relocaddr) + ' to the offset ' + hex(sym_addr))

    add_dynamic_relocation(relocaddr, sym_addr, RELOC_TYPE_ADDR64)

def perform_r_ppc64_relative_reloc(relocaddr, addr):
    match = re.search('0x([0-9a-fA-F]+)$', addr)

    if not match:
        print('[E] PPC64_RELATIVE relocation address format unrecognized: ' + addr)

    rel_addr = int(match.groups()[0], 16)

    debugout('[I] Adding dynamic relocation for 64-bit relative address at ' + hex(relocaddr) + ' to the offset ' + hex(rel_addr))

    add_dynamic_relocation(relocaddr, rel_addr, RELOC_TYPE_ADDR64)

def perform_relocs():
    for line in toolchain_command('objdump', '-R', infilename).splitlines():
        match = re.match('^([0-9a-fA-F]+)\s+([^\s]+)\s+(.+)$', line)

        if match:
            relocaddr, type, symbol = match.groups()

            relocaddr = int(relocaddr, 16)

            if type == 'R_PPC64_JMP_SLOT':
                perform_r_ppc64_jmp_slot_reloc(relocaddr, symbol)
            elif type == 'R_PPC64_ADDR64':
                perform_r_ppc64_addr64_reloc(relocaddr, symbol)
            elif type == 'R_PPC64_RELATIVE':
                perform_r_ppc64_relative_reloc(relocaddr, symbol)
            else:
                print('[E] Cannot performing relocation: ' + line)
                sys.exit(1)
        elif line:
            debugout('[I] Unrecognized line in objdump output: ' + line)

def finalize_output():
    # Write the entry file descriptor
    outfile = open(infilename + '.lid', 'wb')
    outfile.write(get_entry_descriptor())

    # Find and write the HBI image version to the LID
    hbi_imageid = file_bytes(hbicorefile, find_hb_data_symbol_addr('hbi_ImageId'), 128)
    print('[I] hbi_ImageId = ' + struct.unpack('128s', hbi_imageid)[0])
    outfile.write(hbi_imageid)

    # Write dynamic relocations
    outfile.write(struct.pack('>Q', len(dynamic_relocs)))
    for reloctype, relocaddr, offset in dynamic_relocs:
        outfile.write(struct.pack('>QQQ', reloctype, relocaddr, offset))

    # Copy tmpfile to output file
    tmpfile.seek(0)
    outfile.write(tmpfile.read())

perform_relocs()
finalize_output()
