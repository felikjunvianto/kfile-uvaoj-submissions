var t,a,b,x:longint;

begin
	readln(t);
	for x:=1 to t do
	begin
		readln(a,b);
		if a>b then writeln('>') else
		if a<b then writeln('<') else
		writeln('=');
	end;
end.