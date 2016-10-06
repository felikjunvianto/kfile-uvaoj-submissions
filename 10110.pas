var x,y:longword;

begin
	repeat
		readln(x);
		if x<>0 then
		begin
			y:=trunc(sqrt(x));
			if y*y=x then writeln('yes') else writeln('no');
		end;
	until x=0;
end.