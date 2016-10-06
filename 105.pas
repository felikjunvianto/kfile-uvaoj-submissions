var kiri,kanan,tinggi,x,terkanan:longint;
	bangunan:array[1..10000] of longint;
	
begin
	fillchar(bangunan,sizeof(bangunan),0);
	terkanan:=0;
	while not(eof) do
	begin
		readln(kiri,tinggi,kanan);
		if terkanan<kanan then terkanan:=kanan;
		for x:=kiri to kanan-1 do if bangunan[x]<tinggi then bangunan[x]:=tinggi;
	end;
	
	write('1 ',bangunan[1]);
	for x:=2 to terkanan do if bangunan[x]<>bangunan[x-1] then
		write(' ',x,' ',bangunan[x]);
	writeln;
end.