program fjf495e5;

procedure foo (var a: Integer);
begin
end;

begin
  writeln ('failed');
  halt;
  foo ('' > '')  { WRONG }
end.
