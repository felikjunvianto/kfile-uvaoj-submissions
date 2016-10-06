var x:longint;
	kalimat:ansistring;
	
begin
	while not(eof) do
	begin
		readln(kalimat);
		for x:=1 to length(kalimat) do kalimat[x]:=chr(ord(kalimat[x])-7);
		writeln(kalimat);
	end;
end.