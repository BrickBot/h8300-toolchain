{$define DoTestNum 1}
program readb1;

{ FLAG -O0 }

{$define Borland}

{$i read1.inc}

{$W-,borland-pascal,macros}

{$i read2.inc}

begin
  dialect:='BP';
  base:=False;
  test
end.
