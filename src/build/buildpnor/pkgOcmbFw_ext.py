#!/usr/bin/env python3
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/buildpnor/pkgOcmbFw_ext.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2023
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

# The structure of the OCMB headers is described in ocmbFwImage_const.H

import os
import re
import sys
import json
import struct
import hashlib
import subprocess

from itertools import chain
from argparse import ArgumentParser

# Version 1 of the OCMBFW PNOR partition format contains just the base
# header.
#
# Version 2 of the OCMBFW format contains the base header folloewd by
# the extended header.

CURRENT_OCMBFW_HEADER_MAJOR_VERSION = 2
CURRENT_OCMBFW_HEADER_MINOR_VERSION = 0

CURRENT_OCMBFW_EXTENDED_HEADER_VERSION = 1

# See the POZ SBE FIFO Interface specification for definitions of these constants.

IMAGE_TYPE_BOOTLOADER = 1
IMAGE_TYPE_RUNTIME = 2

OCMB_TYPE_ODYSSEY = 1
OCMB_TYPE_EXPLORER = 2

COMPRESSION_TYPE_NONE = 0

def main():
    parser = ArgumentParser(prog='pkgOcmbFw_ext',
                            description='Extended OCMB Firmware Packager')

    parser.add_argument('--layout', required=True,
                        help='The JSON layout file specifying OCMB firmware sections to create/add/remove')
    parser.add_argument('--output', required=True,
                        help='Output file for the new OCMB firmware binary')
    parser.add_argument('--fw-image',
                        help='The firmware image to modify, for --add and --remove')

    group = parser.add_mutually_exclusive_group()
    group.add_argument('--add', action='store_true',
                        help='Add new sections to (or modify existing sections in) an existing fw-image according to the given layout')
    group.add_argument('--remove', action='store_true',
                        help='Remove sections from the existing fw-image according to the given layout')

    args = parser.parse_args()

    outfile = open(args.output, 'wb')

    layouttext = ''.join([line
                          for line in open(args.layout, 'r')
                          if not re.search(r'^\s*(#|//)', line)])

    layout = json.loads(layouttext)

    layout_version = layout['version']

    if layout_version != CURRENT_OCMBFW_EXTENDED_HEADER_VERSION:
        error('This script can only package layout files of version {} (got {})'
              .format(CURRENT_OCMBFW_EXTENDED_HEADER_VERSION, layout_version))

    if not args.add and not args.remove:
        outfile.write(ocmbfw_base_header())
        create_ocmbfw_image(layout, outfile)
    else:
        error('Arguments --add and --remove are not supported yet')

# Write the OCMBFW base header.
def ocmbfw_base_header():
    return (b'OCMBHDR\0'                                       # Eye catcher
            + struct.pack('>IIIIII',
                          CURRENT_OCMBFW_HEADER_MAJOR_VERSION, # Base header major version
                          CURRENT_OCMBFW_HEADER_MINOR_VERSION, # Base header minor version
                          0x60,                                # Header size (fixed)
                          1,                                   # Number of triplets (fixed at 1)
                          1,                                   # first triplet type ("hash")
                          64)                                  # first triplet length (always 64 for sha512)
            + (b'\0' * 64))                                    # first triplet value (invalid hash of all NULs,
                                                               #          this isn't populated in the extended header)

# Create an OCMBFW image, writing the extended header and the body of
# the image to the given file.
def create_ocmbfw_image(layout, outfile):
    images = []
    buffer = bytearray()
    label_to_position = {}
    reloc_sizes_and_positions = []
    reloc_to_label = {}

    for image in layout['images']:
        images.append(pack_fw_image_info_struct(image['image_type'],
                                                image['image_path'],
                                                image['ocmb_type'],
                                                image['dd_level'],
                                                image['compression'],
                                                image.get('pakfile_hash_path'),
                                                image.get('measured_hash_path'),
                                                image.get('image_hash'),
                                                image.get('unhashed_header_size')))

    buffer.extend(pack_ext_header_metadata(images))

    header_byteruns, trailer_byteruns, run_relocs = zip(*images)

    for run in chain(*header_byteruns, *trailer_byteruns):
        if isinstance(run, tuple):
            t, v = run
            if t == 'label':
                label_to_position[v] = len(buffer)
            elif t == 'reloc64':
                reloc_sizes_and_positions.append((v, 8, len(buffer)))
            else:
                error('Bug, invalid data type ' + str(run))
        else:
            buffer.extend(run)

    for (_, reloc), (_, label) in chain(*run_relocs):
        reloc_to_label[reloc] = label

    for reloc, sizebytes, position in reloc_sizes_and_positions:
        label = reloc_to_label[reloc]
        destination = label_to_position[label]
        buffer[position:position+sizebytes] = struct.pack('>Q', destination)

    outfile.write(buffer)

def pack_ext_header_metadata(images):
    return struct.pack('>QQ', CURRENT_OCMBFW_EXTENDED_HEADER_VERSION, len(images))

def error(str):
    print(str)
    sys.exit(1)

def string_to_enum(name, valid, t):
    val = valid.get(t)

    if val is None:
        error('Invalid {} type "{}", wanted one of: {}'
              .format(name, t,
                      ', '.join(['"' + x + '"' for x in valid.keys()])))

    return val

def ocmb_type_to_enum(ocmb_type):
    return string_to_enum('OCMB',
                          { 'odyssey': OCMB_TYPE_ODYSSEY,
                            'explorer': OCMB_TYPE_EXPLORER },
                          ocmb_type)

def image_type_to_enum(image_type):
    return string_to_enum('image',
                          { 'bootloader': IMAGE_TYPE_BOOTLOADER,
                            'runtime': IMAGE_TYPE_RUNTIME },
                          image_type)

def compression_type_to_enum(comp_type):
    return string_to_enum('compression',
                          { 'none': COMPRESSION_TYPE_NONE },
                          comp_type)

next_tag = 0

def gen_reloc64():
    global next_tag
    next_tag += 1
    return ('reloc64', next_tag)

def gen_label():
    global next_tag
    next_tag += 1
    return ('label', next_tag)

# This function takes the parameters of an image and returns three things:
#
# 1) A list of strings and relocation objects. These will be part of the extended header.
# 2) A list of strings and labels. These will appear in the binary after the extended header.
# 3) A list of relocations to perform. These relocations are pairs of (RELOCATION, LABEL) where
#    RELOCATION is a relocation object that marks a 64-bit number to replace, and LABEL
#    is a label object that marks the offset to replace that 64-bit number with.
def pack_fw_image_info_struct(image_type, image_path, ocmb_type,
                              dd_level, compression, pakfile_hash_path,
                              measured_hash_path, image_hash_algo, unhashed_header_size):
    try:
        dd_major, dd_minor = map(int, dd_level.split('.'))
    except Exception as e:
        error('Invalid DD level format "{}", expected something like "1.0"'.format(dd_level))

    compression_type = compression_type_to_enum(compression)

    print(image_type, image_path, ocmb_type, dd_major, dd_minor, compression_type)

    if not image_hash_algo and unhashed_header_size:
        error('unhashed_header_size set without image_hash; add an image_hash')

    if pakfile_hash_path and image_hash_algo:
        error('Both pakfile_hash_path and image_hash_algo specified; pick one')

    if pakfile_hash_path:
        ec = subprocess.run(['paktool', 'extract', image_path, pakfile_hash_path])
        if ec.returncode != 0:
            print(format(ec.args))
            error('paktool exited with error :: '.format(ec.args))

        image_hash = open(pakfile_hash_path, 'rb').read()
    elif unhashed_header_size:
        hasher = hashlib.new('sha512')
        hasher.update(open(image_path, 'rb').read()[unhashed_header_size or 0:])
        image_hash = hasher.digest()

    if measured_hash_path:
        ec = subprocess.run(['paktool', 'extract', image_path, measured_hash_path])
        if ec.returncode != 0:
            print(format(ec.args))
            error('paktool could not extract measured hash :: '.format(ec.args))
        measured_hash = open(measured_hash_path, 'rb').read()
    else:
        measured_hash = bytes()

    payload_reloc = gen_reloc64()
    payload_label = gen_label()

    return ([
               struct.pack('>QQIIQ64s64s',
                           ocmb_type_to_enum(ocmb_type),
                           image_type_to_enum(image_type),
                           dd_major,
                           dd_minor,
                           compression_type,
                           image_hash,
                           measured_hash),
               payload_reloc,
               struct.pack('>Q', 0), # This 64-bit 0 will be replaced
                                     # by the relative position of the
                                     # payload below by the relocation
                                     # handler
               struct.pack('>Q', os.path.getsize(image_path)),
           ],
           [
               payload_label,
               open(image_path, 'rb').read()
           ],
           [
               (payload_reloc, payload_label)
           ])

if __name__ == '__main__':
    main()
