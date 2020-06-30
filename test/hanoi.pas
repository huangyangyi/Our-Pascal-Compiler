program hanoi;
var N:integer;
procedure move(a:integer;b:integer;c:integer;N:integer);
begin
  if (N = 1) then
  begin
    write(a);
    write('->');
    writeln(b);
  end
  else
  begin
	  move(a,c,b,N-1);
	  write(a);
	  write('->');
	  writeln(b);
	  move(c,b,a,N-1);
  end;
end;

begin
  read(N);
  move(1,3,2,N);
end.