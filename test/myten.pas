PROGRAM ten;
VAR
	a,s,max,min,avg:real;
	i:integer;
BEGIN
	write('please input:');
	read(a);
	s:=a;
	max:=a;
	min:=a;
	FOR i:=2 TO 5 DO
		BEGIN
			writeln(i);
			writeln(a);
			read(a);
			s:=s+a;
			IF a>max THEN
			max:=a
			ELSE
			IF a<min THEN min:=a;
		END;
	writeln(s+i);
END.