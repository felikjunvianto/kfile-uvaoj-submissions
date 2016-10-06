var n,x,y,max,sisa:longint;
	satu,dua:array[1..1000000] of byte;
	
begin
	readln(n);
	for x:=1 to n do
	begin
		fillchar(satu,sizeof(satu),0);
		fillchar(dua,sizeof(dua),0);
		readln;
		readln(max);
		for y:=max downto 1 do readln(satu[y],dua[y]);
		
		sisa:=0;
		for y:=1 to max do
		begin
			satu[y]:=satu[y]+dua[y]+sisa;
			if satu[y]>9 then
			begin
				sisa:=satu[y] div 10;
				satu[y]:=satu[y] mod 10;
			end else sisa:=0;
		end;
		
		for y:=max downto 1 do write(satu[y]);
		writeln;
		if x<n then writeln;
	end;
end.