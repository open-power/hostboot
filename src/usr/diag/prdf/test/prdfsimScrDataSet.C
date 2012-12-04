/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimScrDataSet.C $                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
