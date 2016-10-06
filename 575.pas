var x,hasil:longint;
	baca:string;
	
begin
	repeat
		readln(baca);
		if baca<>'0' then
		begin
			hasil:=0;
			for x:=length(baca) downto 1 do
				hasil:=hasil+((ord(baca[x])-48)*((1 shl (1+length(baca)-x))-1));
			writeln(hasil);
		end;
	until baca='0';
end.