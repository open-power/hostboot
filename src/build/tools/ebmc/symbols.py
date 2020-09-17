# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/ebmc/symbols.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2020
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

from enum import Enum

"""This file contains classes to read HB symbols file and provide a lookup
mechanism from "src/usr/errl/plugins/symbols.H"
These classes are used by the parser ErrlUserDetailsParserBackTrace in b0100.py
"""

"""Enum used to verify if hbSymbols are built correclty.
"""
class validation(Enum):
    TYPE = 0x8
    NAME = 0x4
    LENGTH = 0x2
    ADDRESS = 0x1

"""This class contains the data from a line of the HB syms file.
"""
class hbSymbol:
    # Data from a line in hbicore.syms
    address = 0
    length = 0
    name = ""
    validationBits = 0x0
    # Char in column 1 of hbicore.syms
    type = ""

    """Checks to see if all four variables have been set.
       If so, symbol is considered valid
    @returns: true if symbol is valid, else false
    """
    def isValid(self):
        valid = validation.TYPE.value|validation.ADDRESS.value|validation.LENGTH.value|validation.NAME.value
        return valid == self.validationBits

    """Sets address value for symbol and updates validationBits
    """
    def setAddress(self, pszAddress):
        self.address = int(pszAddress, 16)
        self.validationBits |= validation.ADDRESS.value

    """Sets length value for symbol and updates validationBits
    """
    def setLength(self, pszLength):
        self.length = int(pszLength, 16)
        self.validationBits |= validation.LENGTH.value

    """Sets type value for symbol and updates validationBits
    """
    def setType(self, type):
        self.type = int(type, 16)
        self.validationBits |= validation.TYPE.value

    """Sets name for symbol and updates validationBits
    """
    def setName(self, pszName):
        # remove trailing whitespace
        self.name = pszName.rstrip()
        if self.name != "":
            self.validationBits |= validation.NAME.value


"""Container for hbSymbols with methods to initialize and access.
"""
class hbSymbolTable:
    fPopulated = False
    pFileName = ""
    vecSymbols = []

    """Read the symbol file, return zero for success
    @param filename: file to read from
    @returns: an int, 0 for success
    """
    def readSymbols(self, filename):
        self.vecSymbols.clear()
        self.fPopulated = False
        self.pFileName = ""

        try:
            # if file is opened correctly, set file name
            with open(filename) as f:
                self.pFileName = filename
        except IOError:
            return 2

        # populate symbol vector with data from file
        self.populateSymbolVector()
        return 0

    """Read the file to populate the symbol vector
    @returns: an int, 0 for success
    """
    def populateSymbolVector(self):
        #return int
        if self.pFileName == "":
            return 2

        try:
            # if file is opened correctly, populate symbol table
            with open(self.pFileName) as f:
                # read each line of file
                for x in f.readlines():
                    # only use function symbols
                    if x[0] == 'F':
                        pSymbol = hbSymbol()
                        pch = x.split(",", 4)
                        k = 0
                        for y in pch:
                            if k == 0:
                                pSymbol.setType(y)
                            elif k == 1:
                                pSymbol.setAddress(y)
                            elif k == 3:
                                pSymbol.setLength(y)
                            elif k == 4:
                                pSymbol.setName(y)
                            k += 1
                        # add symbol to vector if all variables were set
                        if pSymbol.isValid():
                            self.vecSymbols.append(pSymbol)
        except IOError:
            return 2

        # Ensure vector is sorted
        self.vecSymbols.sort(key=lambda x: x.address, reverse=False)
        self.fPopulated = True
        return 0

    """Given the address, find the nearest symbol name
    @param address: Address to find the nearest match for
    @returns: a string of the symbol name
    """
    def nearestSymbol(self, address):
        rc = self.locateSymbol(int(address, 16))
        # match not found
        if rc < 0:
            return None
        return self.vecSymbols[rc].name

    """Given the address, use binary search to find the index of nearest or exact match
    @param addr: Address to find match for
    @returns: index of nearest or exact match, -1 if nothing found
    """
    def locateSymbol(self, addr):
        low = 0
        high = len(self.vecSymbols) - 1
        mid = 0

        while low <= high:
            mid = (high + low) // 2
            # Address is greater than mid point
            if self.vecSymbols[mid].address < addr:
                # check if it is nearest match
                if (self.vecSymbols[mid].address + self.vecSymbols[mid].length) > addr:
                    return mid
                # not a match, ignore right half
                else:
                    low = mid + 1
            # Address is less than mid point, ignore left half
            elif self.vecSymbols[mid].address > addr:
                high = mid - 1
            # Found exact match
            else:
                return mid
        # No matches were found
        return -1

