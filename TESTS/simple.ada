procedure main is
	a,c,z : integer;
	procedure nest is
	begin null; end;
	procedure sibling is 
	a, b : integer;
	begin 
		c := a;
		nest;
		b := a;
	end;
begin
   a := 10;
   sibling;
end;
