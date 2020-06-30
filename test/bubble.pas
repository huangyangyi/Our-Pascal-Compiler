program test_bubble;
var 
	r:array[1..100] of integer;
	i, j, n, temp: integer;
	flag: boolean;
begin
	readln(n);
	for i:=1 to n do
		read(r[i]);
	for i:=1 to n-1 do
	  begin
	    flag:=true;
	    for j:=n-1 downto i do
	      if r[j+1]<r[j] then
	        begin
	          temp:=r[j+1];
	          r[j+1]:=r[j];
	          r[j]:=temp;
	          flag:=false;
	        end;
	      if flag then break;
	  end;
	for i:=1 to n do
		if i < n then write(r[i], ' ') else writeln(r[i]);
end.