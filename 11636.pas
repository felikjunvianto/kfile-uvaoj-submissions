var x,y,z:longint;

begin
	y:=0;
	repeat
		readln(x);
		if x>=0 then
		begin
			inc(y);
			z:=0;
			if x>=2 then
			begin
				repeat
					inc(z);
				until (1 shl z)>=x;
			end;
			writeln('Case ',y,': ',z);
		end;
	until x<0;
end.