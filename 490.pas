var bawah,samping,x,y,max:longint;
	kata:array[1..100,1..100] of char;
	
begin
	bawah:=0;
	max:=0;
	fillchar(kata,sizeof(kata),ord(127));
	while not(eof) do
	begin
		inc(bawah);
		samping:=0;
		while not(eoln) do 
		begin
			inc(samping);
			read(kata[bawah,samping]);
		end;
		if samping>max then max:=samping;
		readln;
	end;
	
	for x:=1 to max do
	begin
		for y:=bawah downto 1 do if(ord(kata[y,x]) = 127) then write(' ') else write(kata[y,x]);
		writeln;
	end;
end.