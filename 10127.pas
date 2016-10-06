var n,z:longint;
	satu:longint;
	
begin
	while not(eof) do
	begin
		readln(n);
		z:=0;
		satu:=0;
		
		repeat
			inc(z);
			satu:=satu*10+1;
			satu:=satu mod n;
		until satu = 0;
		writeln(z);
	end;
end.