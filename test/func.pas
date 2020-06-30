program myfunc;
var a, b : integer;
procedure f(a : integer; var b: integer);
    procedure g;
    begin
        a := 2;
    end;
begin
    writeln(a, ' ', b);
    g;
    b := 5;
    writeln(a, ' ', b);
end;
begin
    a := 3; 
    b := 4;
    writeln(a, ' ', b);
    f(a, b);
    writeln(a, ' ', b);
end.