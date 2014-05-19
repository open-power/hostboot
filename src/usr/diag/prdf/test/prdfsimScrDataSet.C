/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimScrDataSet.C $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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

#include "prdfsimScrDataSet.H"
#include <prdfTrace.H>

namespace PRDF
{

SimScrDataSet::SimScrDataSet(void)
: xIteration(0) {}

DataList SimScrDataSet::GetData(void)
{
  DataList dl = xPile[xIteration];
  xAccessCount[xIteration] = xAccessCount[xIteration]++;
  ++xIteration;
  if(xIteration == xPile.size()) xIteration = 0; // loop back when at end
  PRDF_DTRAC( "SimScrDataSet::GetData() xIteration: %d, xPile.size(): %d, xAccessCount.size(): %d",
             xIteration, xPile.size(), xAccessCount.size() );
  return dl;
}

void SimScrDataSet::AddData(const DataList & dl)
{
  xPile.push_back(dl);
  xAccessCount.push_back(0);
  PRDF_DTRAC( "SimScrDataSet::AddData() xIteration: %d, xPile.size(): %d, xAccessCount.size(): %d",
             xIteration, xPile.size(), xAccessCount.size() );
}

bool SimScrDataSet::HasNoHits()
{
  bool rc = false;
  for(DataList::const_iterator hc = xAccessCount.begin();
      hc != xAccessCount.end(); ++hc)
  {
    if(*hc == 0)
    {
      rc = true;
      hc = xAccessCount.end()-1;  // terminate loop
    }
  }
  return rc;
}

} // End namespace PRDF
