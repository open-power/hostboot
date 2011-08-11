/*
 *  @file readcomps.rex
 *
 *  Input file name is expected to be hbotcompid.H
 *  Output to stdout a snippet of C code that can
 *  be included by errlparser.C
 */

parse arg szInput .

if length( szInput ) = 0 then do
  say 'Give filename on command line.'
  signal halt
end

szRC = stream( szInput, 'C', 'OPEN READ' )
if left( szRC, 5 ) <> 'READY' then do
  say 'File' szInput 'not found.'
  signal halt
end

do while lines( szInput )
  szCompName = ''
  szCompID = ''

  szLine = linein( szInput )
  p1 = pos( "compId_t", szLine );
  p2 = pos( "_COMP_ID", szLine );
  p3 = pos( "MY_COMP_", szLine );
  if p1 > 0 & p2 > p1 & p3=0 then do

    /* interesting COMP_ID line */
    do i = 1 to words( szLine )
      w = translate( word( szLine, i ))
      if pos( "_COMP_ID", w ) > 0  then szCompName = w
      if pos( "0X", w ) > 0 then szCompID = w
    end

    /* clean them up */
    szCompName = left( szCompName, pos( "_", szCompName )-1 )
    szCompID = strip( szCompID, 'B', ';' )

    /* This output will be included by errlparser.C  */
    say "    {" '"'szCompName'",'  szCompID  "},"

  end
end


szRC = stream( szInput, 'C', 'CLOSE' )
if left( szRC, 5 ) <> 'READY' then signal halt

return 0


halt:
say 'Error: readcomps.rex problem'
exit 2
