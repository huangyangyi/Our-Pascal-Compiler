program error;
type t = record
	x: real;
	y: integer;
end;
var
	a,b: real;
	c: wrongtype;
	d: integer;
	e: t;
begin
	read(a, b);
	d := a + b;
	writeln(d);
	d := e.x;
	d := e.z;
end.