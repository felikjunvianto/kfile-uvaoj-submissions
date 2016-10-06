var tape:string;
	ordinal,x:longint;
	
begin
	readln(tape);
	repeat
		readln(tape);
		if tape[1]<>'_' then
		begin
			delete(tape,1,1);
			delete(tape,6,1);
			delete(tape,9,1);
			ordinal:=0;
			for x:=length(tape) downto 1 do
				ordinal:=ordinal+(trunc(ord(tape[x])/100))*(1 shl (length(tape)-x));
			write(chr(ordinal));
		end;
	until(tape[1]='_');
end.