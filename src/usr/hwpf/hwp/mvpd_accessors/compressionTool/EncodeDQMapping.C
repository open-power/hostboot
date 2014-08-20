/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/hwpf/working/hwp/mvpd_accessors/compressionTool/EncodeDQMapping.C,v $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
//$Id: EncodeDQMapping.C,v 1.5 2014/11/12 19:53:08 pragupta Exp $

/*
 *  @file  EncodeDQMapping.C
 *  @brief computes the encoding for ISDIMM to DQ or DQS mapping
 *
 *
 *  @param first input is a csv file that has the contents of DQ or DQS array
 *         It can have upto 4 ports. If there are less than 4 ports passed in,
 *         the algorithm will assume one-to-one mapping for the rest of the
 *         ports, meaning zeros for encoded data.
 *
 *
 *  @param second input is a file that will hold the encoded data
 *         (one byte of hex data separated with a space)
 *
 *
 */
#include <DQCompressionLib.H>
#include "DQCompressionReasonCodes.H"
#include "DQCompressionConsts.H"
#include <stdio.h>

using namespace DQCompression;

void parseInput (FILE* i_ptrFile, std::vector <std::vector<uint8_t> >& i_dqData,
                 std::vector<std::vector<uint8_t> >& i_dqsData)
{
    const uint32_t l_MAX_STR_LENGTH = 300;
    char l_inputStr [l_MAX_STR_LENGTH];
    char* l_splitStr;

    int l_dqRowNum  = 0;
    int l_dqsRowNum = 0;
    uint8_t l_arrayType = 0;

    //Read the file
    while (fgets(l_inputStr,l_MAX_STR_LENGTH,i_ptrFile))
    {
        //convert l_inputStr to a vector of uint8_t
        l_splitStr = strtok (l_inputStr, ",");
        //# means it is a comment: the comment can say whether it is DQ or DQS
        if (*l_splitStr == '#')
        {
            //Look for DQ or DQS in the comment
            char* l_dqPos = strstr(l_splitStr, "DQ");
            if (l_dqPos != NULL)
            {
                l_arrayType = (*(l_dqPos+2) == 'S') ? DQS : DQ;
            }
        }
        //Skip empty lines
        else if (*l_splitStr != '\n')
        {
            std::vector <uint8_t> l_col;
            //Add DQ arrays to the i_dqData vector
            if(l_arrayType == DQ)
            {
                i_dqData.push_back (l_col);
                while (l_splitStr != NULL)
                {
                    i_dqData.at(l_dqRowNum).push_back(atoi(l_splitStr));
                    l_splitStr = strtok (NULL, ",");
                }
                l_dqRowNum += 1;
            }

            else if(l_arrayType == DQS)
            {
                //Add DQS arrays to the i_dqsData vector
                i_dqsData.push_back (l_col);
                while (l_splitStr != NULL)
                {
                    i_dqsData.at(l_dqsRowNum).push_back(atoi(l_splitStr));
                    l_splitStr = strtok (NULL, ",");
                }
                l_dqsRowNum += 1;
            }
            else
            {
                fprintf(stderr,"Couldn't determixe DQ or DQS from comment\n");
                exit(1);
            }
        } // end outer else if
    } //end while
}
int writeEncodedData (FILE* i_ptrFile,
        std::vector <std::vector<uint8_t> >& i_data, uint8_t i_arrayType)
{
    size_t l_numPorts = i_data.size();
    uint32_t l_dataSize;
    int  l_rc = 0;
    for (uint32_t i = 0; i < l_numPorts; i++)
    {
        DQ_TRAC ("Input Data: \n");
        for (uint32_t j = 0; j < i_data.at(i).size(); j++)
        {
           DQ_TRAC("%d ", i_data.at(i).at(j));
        }
        DQ_TRAC ("\n");


        ecmdDataBufferBase l_encodedData;
        l_rc = encodeDQ (i_data.at(i), i_arrayType,
                        l_encodedData);
        if(l_rc)
        {
            //Check l_rc and print meaningful msgs
            fprintf(stderr, "Error Encoding Data %s \n", ReasonCodes[l_rc]);
            exit(1);
        }

        l_dataSize = l_encodedData.getByteLength();
        char l_buffer [4];
        //Write the data to a text file
        for (uint32_t j = 0; j < l_dataSize; j++)
        {
            if (j == 0)
            {
                sprintf(l_buffer,"%02X", l_encodedData.getByte(j));
            }
            else
            {
                sprintf(l_buffer," %02X", l_encodedData.getByte(j));
            }
            l_rc = fputs(l_buffer, i_ptrFile);
            if (l_rc == EOF)
            {
                DQ_TRAC("Unable to write data to the output file.\n");
                break;
            }
        }
        if (l_rc == EOF)
        {
            break;
        }
        l_rc = fputs("\n", i_ptrFile);
        if (l_rc == EOF)
        {
            DQ_TRAC("Unable to write newline char to the output file\n");
            break;
        }
    }

    //If less than 4 ports are passed in as an input, we assume
    //that the rest of the ports have one to one mapping, which
    //leads to all zeros for the encoded data.
    if (l_numPorts < 4)
    {
        for (uint32_t i = 0; i < (4 - l_numPorts); i++)
        {
            for (uint32_t j = 0; j < l_dataSize; j++)
            {
                if(j == 0)
                {
                    l_rc = fputs("00", i_ptrFile);
                    if (l_rc == EOF)
                    {
                        DQ_TRAC("Unable to write data '00' to the output file");
                        break;
                    }
                }
                else
                {
                    l_rc = fputs(" 00", i_ptrFile);
                    if (l_rc == EOF)
                    {
                        DQ_TRAC("Unable to write data '00' to the output file");
                        break;
                    }
                }
            } //end inner for loop
            if (l_rc == EOF)
            {
                break;
            }
            l_rc = fputs("\n", i_ptrFile);
            if (l_rc == EOF)
            {
                DQ_TRAC("Unable to write newline char to the output file");
                break;
            }
        } //end for loop
    } // end if statement
}



int main (int argc, char* argv [])
{
    int l_rc = 0;
    do {
        if (argc > 3)
        {
            fprintf(stderr, "There should only be two parameters\n");
            exit(1);
        }
        //Open the input file
        FILE* l_prInFile = fopen (argv[1], "r");
        if (l_prInFile == NULL)
        {
            fprintf(stderr, "Can't open the input file for reading\n");
            exit(1);
        }

        //parse the inputs
        std::vector <std::vector<uint8_t> > l_dqData;
        std::vector <std::vector<uint8_t> > l_dqsData;
        parseInput(l_prInFile, l_dqData, l_dqsData);
        fclose(l_prInFile);

        //Open the output file
        FILE* l_prOutFile = fopen (argv[2], "w");
        if (l_prOutFile == NULL)
        {
            fprintf(stderr, "Can't open the output file for writing\n");
            exit(1);
        }

        //process DQ arrays
        if (!(l_dqData.empty()))
        {
            l_rc = fputs("DQ\n", l_prOutFile);
            if (l_rc == EOF)
            {
                DQ_TRAC("Unable to write DQ to the file\n");
                break;
            }
            if(l_dqData.at(0).size() != DQarray_size)
            {
                fprintf(stderr, "DQ arrays must have 80 elements\n");
             exit(1);
            }
            l_rc =  writeEncodedData (l_prOutFile, l_dqData, DQ);
            if (l_rc == EOF)
            {
                DQ_TRAC ("writeEncodedData for DQ failed l_rc: %d\n", l_rc);
                break;
            }
        }

        //process DQS arrays
         if (!(l_dqsData.empty()))
        {
            l_rc = fputs("DQS\n", l_prOutFile);
            if (l_rc == EOF)
            {
                DQ_TRAC("Unable to write DQS to the file\n");
                break;
            }
            if(l_dqsData.at(0).size() != DQSarray_size)
            {
                fprintf(stderr, "DQS arrays must have 20 elements\n");
                exit(1);
            }
            l_rc = writeEncodedData (l_prOutFile, l_dqsData, DQS);
            if (l_rc == EOF)
            {
                DQ_TRAC("writeEncodedData for DQS failed\n");
                break;
            }
        }

        fclose(l_prOutFile);
    } while (0);

    return ((l_rc == EOF) ? EOF : 0);
}
