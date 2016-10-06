var x,panjang,awal,akhir,spasi:longint;
	kata:array[1..10000] of char;
	
begin
	while not(eof) do
	begin
		panjang:=0;
		while not(eoln) do
		begin
			inc(panjang);
			read(kata[panjang]);
		end;
		readln;
		
		awal:=0;
		spasi:=0;
		repeat
			inc(awal);
			if(kata[awal]=' ') then inc(spasi) else
			begin
				akhir:=awal+1;
				while((kata[akhir]<>' ')and(akhir<=panjang)) do inc(akhir);
				dec(akhir);
				for x:=1 to spasi do write(' ');
				for x:=akhir downto awal do write(kata[x]);
				awal:=akhir;
				spasi:=0;
			end;
		until awal=panjang;
		for x:=1 to spasi do write(' ');
		writeln;
	end;
end.