/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/build/buildpnor/bpm-utils/imageCrc.c $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Copyright (c) 2019 SMART Modular Technologies, Inc.                    */
/* All Rights Reserved.                                                   */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*    http://www.apache.org/licenses/LICENSE-2.0                          */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. */
/* See the License for the specific language governing permissions and    */
/* limitations under the License.                                         */
/*                                                                        */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define DEBUG

//
// The BPM / SCAP firmware images always will be in one of
// the two address ranges:
//
// Range:(0xA000 - 0xFFFF). Start = 0xA000;  Length = 0x6000  (24K)
// Range:(0x8000 - 0xFFFF). Start = 0x8000;  Length = 0x8000  (32K)
//
#define FW_MAINIMAGE_START_ADDRESS_8000  (0x8000)
#define FW_MAINIMAGE_START_ADDRESS_A000  (0xA000)
#define FW_MAINIMAGE_LAST_ADDRESS        (0xFFFF)

//
// Maximum possible length of the firmware image
//
#define FW_MAINIMAGE_MAX_LENGTH   (0x8000)
#define CRC_SIGNATURE_LO (0xAA)
#define CRC_SIGNATURE_HI (0x55)

#define ADDRESS_CRC_SIGNATURE (0xFF7A)  // @FF7A = 0xAA, @FF7B = 0x55
#define ADDRESS_IMAGE_START   (0xFF7C)  // @FF7C = Start_Lo,  @FF7D = Start_Hi
#define ADDRESS_IMAGE_CRC     (0xFF7E)  // @FF7E = CRC_Lo, @FF7F = CRC_Hi
#define ADDRESS_RESET_VECTOR  (0xFFFE)  // @FFFE, FFFF
#define LENGTH_IMAGE_CRC      (0x2)

typedef unsigned char  uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long  uint32_t;

typedef struct _CRC_CONTEXT {
    uint16_t mainImageStartAddress;
    uint16_t mainImageTotalLength;
} CRC_CONTEXT;

typedef struct _OFFSET_LIST {
    uint32_t count;
    uint32_t offset[4];
} OFFSET_LIST;

char* readNextHex(const char* pLine, uint32_t *value);

uint16_t resetCrc(void);

uint16_t updateCrc(uint8_t byte);

uint16_t calculateCrc(uint8_t* pData, int length);

bool
parseLine(const char* pLine,
          uint32_t  *mMemoryAddress,
          CRC_CONTEXT *context,
          uint8_t   *mainImageData);

uint16_t mCrc = 0;

void
dumpImageData(uint8_t *data, uint32_t dataLength, OFFSET_LIST *offsetToSkipList)
{
    bool dontPrint = false;

    uint32_t i, c;
    uint32_t offsetToSkipCount = 0;

    if (offsetToSkipList != NULL) {
        offsetToSkipCount = offsetToSkipList->count;
    }

    printf("MainImageData:\n");

    for (i = 1; i < dataLength - 1; ++i) {

        //
        // Don't print some of the offsets, when requested
        //
        dontPrint = false;
        for (c = 0; c < offsetToSkipCount; c++) {
            if ((i - 1) == offsetToSkipList->offset[c]) {
                dontPrint = true;
                break;
            }
        }

        if (dontPrint) {
            printf("   ");
        } else {
            printf(" %02x", data[i - 1]);
        }

        if ((i % 16) == 0) {
            printf("\n");
        }
    }

    printf("\n");
}

uint16_t
resetCrc(void)
{
    mCrc = 0xFFFF;
    return mCrc;
}

uint16_t
updateCrc(uint8_t byte)
{
    bool x;
    int i;

    for (i = 0; i < 8; ++i) {
        x = ((mCrc & 0x8000 ? 1 : 0) ^ (byte & 0x80 ? 1 : 0)) ? true : false;
        mCrc <<= 1;
        if (x)
            mCrc ^= 0x1021;
        byte <<= 1;
    }
    return mCrc;
}

uint16_t
calculateCrc(uint8_t* pData, int length)
{
    //resetCrc();
    for (; length; --length, ++pData) {
        updateCrc(*pData);
    }
    return mCrc;
}

char*
readNextHex(const char* pLine, uint32_t *pValue)
{
    uint32_t value = 0;

    // Skip leading white space
    while (*pLine != '\0' && *pLine <= ' ') {
        ++pLine;
    }

    if (*pLine == '\0')
        return NULL;

    while (true) {
        if (*pLine >= '0' && *pLine <= '9') {
            value <<= 4;
            value += *pLine - '0';
        } else if (*pLine >= 'a' && *pLine <= 'f') {
            value <<= 4;
            value += 0xa + *pLine - 'a';
        } else if (*pLine >= 'A' && *pLine <= 'F') {
            value <<= 4;
            value += 0xA + *pLine - 'A';
        } else {
            break;
        }
        ++pLine;
    }

    *pValue = value;
    return (char*)pLine;
}

bool
parseLine(const char* pLine,
          uint32_t  *mMemoryAddress,
          CRC_CONTEXT *context,
          uint8_t   *mainImageData)
{
    uint8_t data[0x100];
    int dataLength = 0;
    uint32_t value;

    uint32_t offsetToCopy = 0;
#ifdef DEBUG
    int i;
#endif

    if (*pLine == '@') {
        // This is a memory address
        if (readNextHex(pLine + 1, &value) != NULL) {
            *mMemoryAddress = (uint16_t) value;
#ifdef DEBUG
            printf("@Memory Address: 0x%x\n", *mMemoryAddress);
#endif // DEBUG

            //
            // Initialize the Context when the firmware image
            // start address is detected.
            //
            if ((*mMemoryAddress == FW_MAINIMAGE_START_ADDRESS_8000) ||
                (*mMemoryAddress == FW_MAINIMAGE_START_ADDRESS_A000)) {

                context->mainImageStartAddress = value;
                context->mainImageTotalLength = (FW_MAINIMAGE_LAST_ADDRESS - value) + 1;

                printf("Context: Image Start Address = 0x%x; Image Length = %d (0x%x) \n",
                    context->mainImageStartAddress, context->mainImageTotalLength, context->mainImageTotalLength);
            }
        }

   } else if (*pLine == 'q' || *pLine == 'Q') {
#ifdef DEBUG
        printf("Done\n");
        printf("Memory Address: 0x%x\n", *mMemoryAddress);
#endif // DEBUG
        return true;
    } else {
        do {
            pLine = readNextHex(pLine, &value);

            if (pLine != NULL) {
                data[dataLength++] = value;
            }

        } while (pLine != NULL);

        if (dataLength & 1) {
            // Keep even byte alignment by padding
            data[dataLength++] = 0xFF;
        }

#ifdef DEBUG
        printf("Write data (%04x) dataLength (0x%x):",
            *mMemoryAddress, dataLength);
        for (i = 0; i < dataLength; ++i) {
            printf(" %02x", data[i]);
        }
        printf("\n");
#endif // DEBUG

        //
        // added by rananth to calculate the CRC of the main image data.
        //
        if ((*mMemoryAddress >= context->mainImageStartAddress) &&
            (*mMemoryAddress <
             (context->mainImageStartAddress + context->mainImageTotalLength)))
        {

            if (   (context->mainImageStartAddress != 0)
                && (context->mainImageTotalLength != 0) &&
                (mainImageData != NULL)) {

                //
                // Copy the main image data bytes (Range: @8000, 0x8000) to the
                // passed in data buffer.
                //
                offsetToCopy = *mMemoryAddress - context->mainImageStartAddress;
                memcpy(mainImageData + offsetToCopy, data, dataLength);

#ifdef DEBUG
                printf("Copy  data (%04x) dataLength (0x%x):",
                    offsetToCopy, dataLength);
                printf("\n");
#endif // DEBUG

            }
        }

        *mMemoryAddress += dataLength;
    }

    return true;
}


int
ProcessFile(char *pFilename, bool verbose)
{
    char buffer[0x100];
    int length;
    int line;

    uint8_t *mainImageData = 0;

    uint32_t mMemoryAddress = 0;
    uint32_t crc = 0;
    uint32_t offsetToSkip;
    uint32_t offsetToInsert;
    uint32_t firstPortion = 0;
    uint32_t secondPortion = 0;

    CRC_CONTEXT  context;
    OFFSET_LIST  offsetList;

    // Count the number of lines in the file and use that for progress
    FILE* pFile = fopen(pFilename, "r");
    if (!pFile) {
        printf("Unable to open file %s\n", pFilename);
        return false;
    }
    for (line = 0; !feof(pFile); ++line) {
        if (fgets(buffer, sizeof(buffer), pFile) == NULL) {
            break;
        }
    }


    // Rewind to the beginning of the file
    fseek(pFile, 0, SEEK_SET);

    //
    // allocate memory for the main image data
    //
    mainImageData = (uint8_t *) malloc(FW_MAINIMAGE_MAX_LENGTH);
    memset(mainImageData, 0xFF, FW_MAINIMAGE_MAX_LENGTH);

    memset(&context, 0, sizeof(CRC_CONTEXT));

    // Process the lines
    for (line = 0; !feof(pFile); ++line) {
        if (fgets(buffer, sizeof(buffer), pFile) == NULL) {
            break;
        }

        length = strlen(buffer);

        // Strip off any terminating carriage return/line feed
        for (; length > 0 && buffer[length - 1] < ' '; --length);
        buffer[length] = '\0';

        if ( !parseLine((const char*) buffer,
                &mMemoryAddress,
                &context,
                mainImageData) ) {
            printf("False returned by parseLine \n");
            break;
        }
    }

    if (verbose) {

        printf("==============================================\n");
        printf("Dump & CRC before selective skip (@FF7E, 2) (@FFFE, 2) \n");
        printf("==============================================\n");

        dumpImageData(mainImageData, context.mainImageTotalLength, NULL);

        crc = calculateCrc(mainImageData, context.mainImageTotalLength);

        printf("Total Length = %d (0x%x). Final CRC = 0x%x \n",
            context.mainImageTotalLength, context.mainImageTotalLength, crc);

    }

    //
    // Insert the Signature (if not already present)
    //
    offsetToInsert = ADDRESS_CRC_SIGNATURE - context.mainImageStartAddress;
    if (mainImageData[offsetToInsert] != CRC_SIGNATURE_LO) {
        mainImageData[offsetToInsert] = CRC_SIGNATURE_LO;
    }

    if (mainImageData[offsetToInsert + 1] = CRC_SIGNATURE_HI) {
        mainImageData[offsetToInsert + 1] = CRC_SIGNATURE_HI;
    }

    offsetToInsert = ADDRESS_IMAGE_START - context.mainImageStartAddress;
    mainImageData[offsetToInsert] = (context.mainImageStartAddress & 0xFF);   // Lo Byte
    mainImageData[offsetToInsert + 1] = (context.mainImageStartAddress & 0xFF00) >> 8; // Hi Byte

    //
    // Skip the following locations for CRC calculation.
    //
    // 1. @FF7E, 2
    // 2. @FFFE, 2
    //
    offsetToSkip = ADDRESS_IMAGE_CRC - context.mainImageStartAddress;
    mainImageData[offsetToSkip] = 0xFF;
    mainImageData[offsetToSkip + 1] = 0xFF;

    offsetToSkip = ADDRESS_RESET_VECTOR - context.mainImageStartAddress;
    mainImageData[offsetToSkip] = 0xFF;
    mainImageData[offsetToSkip + 1] = 0xFF;

    printf("\n");
    printf("====================================================================================\n");
    printf("Dump & CRC after Insert (@FF7A, 2) (@FF7C, 2) & Selective skip (@FF7E, 2) (@FFFE, 2) \n");
    printf("====================================================================================\n");

    memset(&offsetList, 0, sizeof(OFFSET_LIST));
    offsetList.count = 4;
    offsetList.offset[0] = ADDRESS_IMAGE_CRC - context.mainImageStartAddress;
    offsetList.offset[1] = ADDRESS_IMAGE_CRC - context.mainImageStartAddress + 1;
    offsetList.offset[2] = ADDRESS_RESET_VECTOR - context.mainImageStartAddress;
    offsetList.offset[3] = ADDRESS_RESET_VECTOR - context.mainImageStartAddress + 1;

    if (verbose) {
        dumpImageData(mainImageData, context.mainImageTotalLength, &offsetList);
    }

    // Reset
    resetCrc();

    firstPortion =  ADDRESS_IMAGE_CRC - context.mainImageStartAddress;
    secondPortion = ADDRESS_RESET_VECTOR - (ADDRESS_IMAGE_CRC + LENGTH_IMAGE_CRC);

    printf("firstPortion: Start = 0x%x   Length = %d (0x%x)\n", 0, firstPortion, firstPortion);
    printf("secondPortion: Start = 0x%x   Length = %d (0x%x)\n", firstPortion + 2, secondPortion, secondPortion);

    crc = calculateCrc(mainImageData,  firstPortion);
    crc = calculateCrc(mainImageData + firstPortion + 2,  secondPortion);

    printf("Total Length = %d (0x%x). Final CRC = 0x%x \n",
        (firstPortion + secondPortion), (firstPortion + secondPortion), crc);

    //
    // Generate the  CRC signature lines to be inserted to the firmware image file
    //
    printf("---\n");
    printf("@%x\n", ADDRESS_CRC_SIGNATURE);
    printf("%02x %02x %02x %02x %02x %02x \n",
    mainImageData[ADDRESS_CRC_SIGNATURE - context.mainImageStartAddress],
    mainImageData[ADDRESS_CRC_SIGNATURE - context.mainImageStartAddress + 1],
    mainImageData[ADDRESS_IMAGE_START - context.mainImageStartAddress],
    mainImageData[ADDRESS_IMAGE_START - context.mainImageStartAddress + 1],
    (crc & 0xFF),
    ((crc & 0xFF00) >> 8));
    printf("---\n");


    free(mainImageData);
    fclose(pFile);
}


int main(int argc, char *argv[])
{
    bool verbose = false;

    if (argc < 2) {
        printf("Usage: %s <filename> [-v]\n", argv[0]);
        return -1;
    }

    if (argc > 2) {
        if (!strcmp(argv[2], "-v")) {
            verbose = true;
        }
    }

    printf("Processing %s. Verbose=%d \n", argv[1], verbose);

    resetCrc();
    ProcessFile(argv[1], verbose);
    return 0;
}
