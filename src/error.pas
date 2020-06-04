program error;
var
	a,b: real;
	c: wrongtype;
	d: integer;
begin
	read(a, b);
	d := a + b;
	writeln(d);
end.