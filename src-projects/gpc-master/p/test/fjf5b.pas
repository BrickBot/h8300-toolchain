unit fjf5b;

interface
type
  r=record
    a:integer
  end;

procedure f(const p:r);

implementation
procedure f(const p:r);
begin
  writeln ( 'OK' );
end;
end.
