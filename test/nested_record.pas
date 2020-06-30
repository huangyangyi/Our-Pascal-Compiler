program test_nested_record;
type
    r1 = record
        a, b: integer;
    end;
    r2 = record
        a, b: integer;
        c, d: r1;
        e: record
            a, b: integer;
        end;
    end;
var a: r2;
begin
	{read(a.a, a.b);}
    read(a.a, a.c.b);
    {writeln(a.a, a.c.b, a.e.a);}
end.