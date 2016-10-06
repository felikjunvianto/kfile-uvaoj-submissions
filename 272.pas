var masuk:string;
	x:longint;
	awal:boolean;
	
begin
	awal:=TRUE;
	while not(eof) do
	begin
		readln(masuk);
		for x:=1 to length(masuk) do if masuk[x]<>'"' then write(masuk[x]) else
			if awal then
			begin
				write('``');
				awal:=FALSE;
			end else
			
			begin
				write('''','''');//write(chr(39),chr(39));
				awal:=TRUE;
			end;
		writeln;
	end;
end.